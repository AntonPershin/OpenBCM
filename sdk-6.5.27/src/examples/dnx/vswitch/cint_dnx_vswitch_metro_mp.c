/*~~~~~~~~~~~~~~~~~~~~~~~~~~Multipoint Metro Service~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/*
 *File: cint_dnx_vswitch_metro_mp.c
 * Purpose: Example of Multipoint Metro Service
 *
 * In this service, you can attach more than two logical ports to the VSI.
 * Packets are forwarded/flooded, based on the lookup in MAC table.
 *
 * Open multipoint service and attach logical ports to the service.
 *
 *  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 *  |                                                                       |
 *  |                   o  \                         o                      |
 *  |                    \  \<4,8>        <10,20>/  /                       |
 *  |                  /\ \  \   -----------    /  /                        |
 *  |                   \  \ \/ /  \   /\   \  /  / /\                      |
 *  |             <40,80>\  \  |    \  /     |\/ /  /                       |
 *  |                     \  \ |     \/      |  /  /<30,60>                 |
 *  |                       p3\|     /\      | /  /                         |
 *  |                          |    /  \     |/p1                           |
 *  |                         /|   \/   \    |                              |
 *  |                        /  \  VSwitch  /                               |
 *  |                   /\  /p2  -----------                                |
 *  |              <5,2>/  /  /                                             |
 *  |                  /  /  /<3,6>                                         |
 *  |                 /  /  /                                               |
 *  |                   /  \/                                               |
 *  |                  o                                                    |
 *  |                                                                       |
 *  |            +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+             |
 *  |            | Figure 12: Attach Logical Ports to Service |             |
 *  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 *
 * Calling sequence:
 *  1.  For port 1, set outer TPID to 0x8100 and inner TPID to 0x9100.
 *  2.  Create the Multipoint VSI (refer to vswitch_create).
 *      a.  Create new VSI.
 *          1.   Calls bcm_vswitch_create()
 *          2.   Returns handle to opened VSI
 *      b.  Open multicast group to be used for flooding (refer to multicast__open_mc_group)
 *          1.   Calls bcm_multicast_create()
 *          2.   The multicast is defined at ingress for L2 usage
 *          3.   For this purpose call bcm_multicast_create with following flags: 
                BCM_MULTICAST_INGRESS_GROUP | and BCM_MULTICAST_WITH_ID
 *      c.  Attach the multicast group to the created VSI
 *          1.   Note that uc/mc/bc group have the same value as VSI or uc
 *          2.   Another option is to set uc_group = VSI, and mc = uc + 4k, and bc = mc + 4k
 *          3.   Calls bcm_vlan_control_vlan_set()
 *  3.  Add VLAN ports to the VSI.
 *      a.  vswitch_metro_add_port creates VLAN port gport and returns gport ID.
 *          1.  Fills gport attributes (match and egress VLANs, etc.).
 *          2.   Calls bcm_vlan_port_create().
 *      b.  Then the returned gport ID is added to the VSI (vswitch_add_port).
 *          1.   Calls bcm_vswitch_port_add() to add the gport to VSI.
 *          2.   Calls multicast__gport_encap_add() to update the multicast group with the new gport.
 * 4.  Delete VSI
 *      a.  Find gport in VSI by returned gport ID.
 *               bcm_vlan_port_find()
 *      b.  Remove gport from VSI per gport ID.
 *               bcm_vswitch_port_delete()
 *      c.  Destroy VSI
 *               bcm_vswitch_destroy()
 *
 * Traffic:
 *  Flooding (sending packet with unknown DA):
 *      1.   Send Ethernet packet with:
 *          a.   Any SA
 *          b.   Unknown DA
 *          c.   VLAN tag1: VLAN tag type 0x8100, VID =10
 *          d.   VLAN tag2: VLAN tag type 0x9100, VID =20 
 *
 *   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ 
 *   |                                                                       |
 *   |                      tag1                 tag2                        |
 *   |  +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+  |
 *   |  | DA | SA || TIPD1 | Prio | VID || TIPD2 | Prio | VID ||   Data   |  |
 *   |  |    |    || 0x8100|      | 10  || 0x9100|      | 20  ||          |  |
 *   |  +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+  |
 *   |                                                                       |
 *   |                   +~~~~~~~~~~~~~~~~~~~~~~~~~~~+                       |
 *   |                   | Figure 13: Flooded Packet |                       | 
 *   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 *
 *      2.   Packet is flooded (as DA is not known).
 *          a.   The packet is received: 
 *                 In P2: port 1 with VLAN tag1: VID = 3, VLAN tag2: VLAN ID = 6.
 *                 In P3: port 1 with VLAN tag1 VID = 4, VLAN tag2: VLAN ID = 8.
 *          Note the packet is not received on P1 
 *          (as packet was injected into this port, that is, hair-pin filtering).
 *      3.   SA of the packet is learned.
 *          a.   Call l2_print_mact(unit) to print MAC table content.
 *  Sending to known DA:
 *      1.   Send Ethernet packet (from P2).
 *          a.   Any SA. 
 *          b.   DA equal to SA from previous packet.
 *          c.   VLAN tag1: VLAN tag type 0x8100, VID =1.
 *          d.   VLAN tag2: VLAN tag type 0x9100, VID =2. 
 *      2.   Packet is forwarded (as DA is known) and received in P1: 
 *          port 1 with VLAN tag1: VID =10, VLAN tag2: VLAN ID = 20. 
 *      3.   The SA of the packet is learned.
 *          a.   Call l2_print_mact(unit) to print MAC table content.
 *
 */

/* set to configure single vlan tag */
int single_vlan_tag = 0;

struct vswitch_metro_mp_s {
    bcm_port_t sysports[4];
    int p_vlans[16];  /* vlans for ports ndx = (port - 1) * 4 + i; */
    bcm_vlan_t vsi;
    uint32 flush_group_id[4];
    bcm_failover_t ingress_failover_id[4];
    bcm_failover_t egress_failover_id[4];
    int multi_bidir; /* Configure the multi-dev bidir with same configuration */
};


vswitch_metro_mp_s vswitch_metro_mp_info;

/**
 * Convert system port to local port
*/
int
multi_dev_system_port_to_local(int unit, int sysport, int *local_port){

    BCM_IF_ERROR_RETURN_MSG(bcm_port_local_get(unit, sysport, local_port), "fail core_port");

    return BCM_E_NONE;
}

void
vswitch_metro_mp_ring_protection_info_init(   int port_num,
                                       uint32 flush_group_id,
                                       bcm_failover_t ingress_failover_id,
                                       bcm_failover_t egress_failover_id){
    vswitch_metro_mp_info.flush_group_id[port_num] = flush_group_id;
    vswitch_metro_mp_info.ingress_failover_id[port_num] = ingress_failover_id;
    vswitch_metro_mp_info.egress_failover_id[port_num] = egress_failover_id;
}

void 
vswitch_metro_mp_info_init(int sysport_1, int sysport_2, int sysport_3){

    vswitch_metro_mp_info.flush_group_id[0] = 0;
    vswitch_metro_mp_info.ingress_failover_id[0] = 0;
    vswitch_metro_mp_info.egress_failover_id[0] = 0;
    vswitch_metro_mp_info.flush_group_id[1] = 0;
    vswitch_metro_mp_info.ingress_failover_id[1] = 0;
    vswitch_metro_mp_info.egress_failover_id[1] = 0;
    vswitch_metro_mp_info.flush_group_id[2] = 0;
    vswitch_metro_mp_info.ingress_failover_id[2] = 0;
    vswitch_metro_mp_info.egress_failover_id[2] = 0;

    vswitch_metro_mp_info.sysports[0] = sysport_1;
    vswitch_metro_mp_info.sysports[1] = sysport_2;
    vswitch_metro_mp_info.sysports[2] = sysport_3;

    vswitch_metro_mp_info.p_vlans[0] = 10; /* sysport_1 incoming outer_vlan */
    vswitch_metro_mp_info.p_vlans[1] = 20; /* sysport_1 incoming inner_vlan */
    vswitch_metro_mp_info.p_vlans[2] = 30; /* sysport_1 outgoing outer_vlan */
    vswitch_metro_mp_info.p_vlans[3] = 60; /* sysport_1 outgoing inner_vlan */
    vswitch_metro_mp_info.p_vlans[4] = 5; /* sysport_2 incoming outer_vlan */
    vswitch_metro_mp_info.p_vlans[5] = 2; /* sysport_2 incoming inner_vlan */
    vswitch_metro_mp_info.p_vlans[6] = 3; /* sysport_2 outgoing outer_vlan */
    vswitch_metro_mp_info.p_vlans[7] = 6; /* sysport_2 outgoing inner_vlan */
    vswitch_metro_mp_info.p_vlans[8] = 4; /* sysport_3 incoming outer_vlan */
    vswitch_metro_mp_info.p_vlans[9] = 8; /* sysport_3 incoming inner_vlan */
    vswitch_metro_mp_info.p_vlans[10] = 40; /* sysport_3 outgoing outer_vlan */
    vswitch_metro_mp_info.p_vlans[11] = 80; /* sysport_3 outgoing inner_vlan */

    vswitch_metro_mp_info.vsi = 0;
}

/*
 * create vlan-ports
 *   vlan-port: is Logical interface identified by (port-vlan-vlan).
 */
int
vswitch_metro_add_port(
    int unit,
    int port_num,
    bcm_gport_t *port_id,
    int flags)
{
    int base = port_num * 4;
    bcm_vlan_port_t vp1;
    bcm_info_t info;
    bcm_vlan_port_t_init(&vp1);

    /*
     * ring protection parameters
     */
    vp1.group = vswitch_metro_mp_info.flush_group_id[port_num];
    vp1.ingress_failover_id = vswitch_metro_mp_info.ingress_failover_id[port_num];
    vp1.failover_port_id = 0;
    vp1.egress_failover_id = vswitch_metro_mp_info.egress_failover_id[port_num];
    vp1.egress_failover_port_id = 0;

    /* the match criteria is port:1, out-vlan:10,  in-vlan:20 */
    vp1.criteria = single_vlan_tag ? BCM_VLAN_PORT_MATCH_PORT_VLAN : BCM_VLAN_PORT_MATCH_PORT_VLAN_STACKED;
    vp1.port = vswitch_metro_mp_info.sysports[port_num];
    vp1.match_vlan = vswitch_metro_mp_info.p_vlans[base + 0];
    vp1.match_inner_vlan = single_vlan_tag ? 0 : vswitch_metro_mp_info.p_vlans[base + 1];

    /*
     * packet forwarded to this port will be set with out-vlan:100,  in-vlan:200
     *   the following two inputs are not for bcm_vlan_port_create, but for vlan_translation_vlan_port_create_to_translation.
     */
    vp1.flags = flags;
    vp1.vlan_port_id = *port_id;
    /* this is relevant only when get the gport, not relevant for creation */
    /* will be pupulated when the gport is added to service, using vswitch_port_add */
    vp1.vsi = 0;
    BCM_IF_ERROR_RETURN_MSG(bcm_vlan_port_create(unit,&vp1), "");

    /* The following two inputs are used for eve */
    vp1.egress_vlan = vswitch_metro_mp_info.p_vlans[base + 2];
    vp1.egress_inner_vlan = single_vlan_tag ? 0 : vswitch_metro_mp_info.p_vlans[base + 3];

    /* save the created gport */
    *port_id = vp1.vlan_port_id;

    /* bcm_vlan_port_create does not create ingress / egress action mapping. This is here to compensate. */
    BCM_IF_ERROR_RETURN_MSG(vlan_translation_vlan_port_create_to_translation(unit, &vp1), "");
    if(verbose >= 1){
        printf("Add vlan-port-id:0x%08x in-port:0x%08x match_vlan:0x%08x match_inner_vlan:0x%08x in unit %d\n",vp1.vlan_port_id, vp1.port, vp1.match_vlan, vp1.match_inner_vlan, unit);
    }

  return BCM_E_NONE;
}

/*
 * add L2 entry points to the given gport
 */
int
vswitch_add_l2_addr_to_gport(
    int unit,
    int gport_id,
    bcm_mac_t mac,
    bcm_vlan_t vsi)
{
    bcm_l2_addr_t l2_addr;

    bcm_l2_addr_t_init(&l2_addr,mac,vsi);
    l2_addr.flags = BCM_L2_STATIC; /* static entry */
    l2_addr.port = gport_id;
    BCM_IF_ERROR_RETURN_MSG(bcm_l2_addr_add(unit,&l2_addr), "");

    return BCM_E_NONE;
}


/*
 * Add an L2 entry with a MACT flush group
 */
int
vswitch_add_l2_addr_w_group_id(
    int unit,
    int gport_id,
    bcm_mac_t mac,
    int group_id,
    bcm_vlan_t vsi)
{
    bcm_l2_addr_t l2_addr;

    bcm_l2_addr_t_init(&l2_addr,mac,vsi);
    l2_addr.flags = BCM_L2_STATIC; /* static entry */
    l2_addr.port = gport_id;
    l2_addr.group = group_id;
    BCM_IF_ERROR_RETURN_MSG(bcm_l2_addr_add(unit,&l2_addr), "");

    return BCM_E_NONE;
}


/*
 * A functions that performs the initial configurations for cint_dnx_vswitch_metro_mp.c 
 * It includes VLAN-Port creation, attaching to a vswitch, VLLAN translation configurations, flood MC etc. 
 * The function is and alternative to the vswitch_metro_mp_multi_device function, but without the need to 
 * supply the system ports as they are retrieved from the CINTs data structure. 
 * The function is based on the function vswitch_metro_mp_multi_device_arad_run().
 */ 
int
vswitch_metro_mp_multi_device_fixed_ports(int *units_ids, int nof_units, int known_mac_lsb, int known_vlan){
    bcm_gport_t gport1,gport2, gport3;
    bcm_vlan_t  vsi1;
    bcm_mac_t kmac;
    int index;
    bcm_vlan_t kvlan;
    int i, unit, local_unit, remote_unit, flags;
    bcm_port_tpid_class_t port_tpid_class;
    int local_port;
    int sysport_is_local;

    kmac[5] = known_mac_lsb;
    kvlan = known_vlan;

    /* init values */  
    units_array_make_local_first(units_ids, nof_units, vswitch_metro_mp_info.sysports[0]);
    for (i = 0 ; i < nof_units ; i++){
        unit = units_ids[i];

        bcm_port_tpid_class_t_init(&port_tpid_class);
        multi_dev_system_port_to_local(unit, vswitch_metro_mp_info.sysports[0], &local_port);

        port_tpid_class.tpid1 = 0x8100;
        port_tpid_class.tpid2 = 0x9100;
        port_tpid_class.port = local_port;
        port_tpid_class.tag_format_class_id = 16;
        port_tpid_class.flags = BCM_PORT_TPID_CLASS_INGRESS_ONLY;
    
        BCM_IF_ERROR_RETURN_MSG(bcm_port_tpid_class_set(unit, &port_tpid_class), "( in_port )");
    }

    units_array_make_local_first(units_ids, nof_units, vswitch_metro_mp_info.sysports[1]);
    for (i = 0 ; i < nof_units ; i++){
        unit = units_ids[i];

        bcm_port_tpid_class_t_init(&port_tpid_class);
        multi_dev_system_port_to_local(unit, vswitch_metro_mp_info.sysports[1], &local_port);

        port_tpid_class.tpid1 = 0x8100;
        port_tpid_class.tpid2 = 0x9100;
        port_tpid_class.port = local_port;
        port_tpid_class.tag_format_class_id = 16;
        port_tpid_class.flags = BCM_PORT_TPID_CLASS_INGRESS_ONLY;
    
        BCM_IF_ERROR_RETURN_MSG(bcm_port_tpid_class_set(unit, &port_tpid_class), "( in_port )");
    }

    units_array_make_local_first(units_ids, nof_units, vswitch_metro_mp_info.sysports[2]);
    for (i = 0 ; i < nof_units ; i++){
        unit = units_ids[i];

        bcm_port_tpid_class_t_init(&port_tpid_class);
        multi_dev_system_port_to_local(unit, vswitch_metro_mp_info.sysports[2], &local_port);

        port_tpid_class.tpid1 = 0x8100;
        port_tpid_class.tpid2 = 0x9100;
        port_tpid_class.port = local_port;
        port_tpid_class.tag_format_class_id = 16;
        port_tpid_class.flags = BCM_PORT_TPID_CLASS_INGRESS_ONLY;
    
        BCM_IF_ERROR_RETURN_MSG(bcm_port_tpid_class_set(unit, &port_tpid_class), "( in_port )");
    }

    /* In advanced vlan translation mode, the default ingress/ egress actions and mapping
       are not configured. This is here to compensate. */    
    for (i = 0 ; i < nof_units ; i++) {
        unit = units_ids[i];
        BCM_IF_ERROR_RETURN_MSG(vlan_translation_default_mode_init(unit), "");
    }

    for (i = 0 ; i < nof_units ; i++){
        unit = units_ids[i];
        for (index = 0; index < 12; index++)
        {
            if (single_vlan_tag && (((index % 2) != 0))) {
                continue;
            }
            BCM_IF_ERROR_RETURN_MSG(vlan__init_vlan(unit,vswitch_metro_mp_info.p_vlans[index]), "");
        }
    }

    /* 1. create vswitch + create Multicast for flooding */
    for (i = 0 ; i < nof_units ; i++){
        unit = units_ids[i];
        BCM_IF_ERROR_RETURN_MSG(vswitch_create(unit, &vsi1, i /* On first iteration, with_id = i = 0*/), "");
    }

    /* 2. create first vlan-port */
    units_array_make_local_first(units_ids, nof_units, vswitch_metro_mp_info.sysports[0]);
    flags = (vswitch_metro_mp_info.egress_failover_id[0]) ? BCM_VLAN_PORT_EGRESS_PROTECTION : 0;
    gport1 = 0;
    for (i = 0 ; i < nof_units ; i++){
        unit = units_ids[i];
        BCM_IF_ERROR_RETURN_MSG(is_system_port_is_local(unit, vswitch_metro_mp_info.sysports[0], &sysport_is_local), "");
        if(sysport_is_local || vswitch_metro_mp_info.multi_bidir) {
            BCM_IF_ERROR_RETURN_MSG(vswitch_metro_add_port(unit, 0, &gport1, flags), "");
            if(verbose){
                printf("created vlan-port   0x%08x in unit %d\n",gport1, unit);
            }        
            flags |= BCM_VLAN_PORT_WITH_ID;
        }
    }
    /* 3. add vlan-port to the vswitch and multicast */
    local_unit = units_ids[0];
    remote_unit = (nof_units > 1) ? units_ids[1] : -1;
    BCM_IF_ERROR_RETURN_MSG(vswitch_add_port_multi_dev(local_unit, remote_unit, vsi1, vswitch_metro_mp_info.sysports[0], gport1), "");
    
    /* add another port to the vswitch */
    /* 4. create second vlan-port */
    units_array_make_local_first(units_ids, nof_units, vswitch_metro_mp_info.sysports[1]);
    flags = (vswitch_metro_mp_info.egress_failover_id[1]) ? BCM_VLAN_PORT_EGRESS_PROTECTION : 0;
    gport2 = 0;
    for (i = 0 ; i < nof_units ; i++){
        unit = units_ids[i];
        BCM_IF_ERROR_RETURN_MSG(is_system_port_is_local(unit, vswitch_metro_mp_info.sysports[1], &sysport_is_local), "");
        if(sysport_is_local || vswitch_metro_mp_info.multi_bidir) {
            BCM_IF_ERROR_RETURN_MSG(vswitch_metro_add_port(unit, 1, &gport2, flags), "");
            if(verbose){
                printf("created vlan-port   0x%08x\n\r",gport2);
            }    
            flags |= BCM_VLAN_PORT_WITH_ID;
        }
    }

    /* 5. add vlan-port to the vswitch and multicast */
    local_unit = units_ids[0];
    remote_unit = (nof_units > 1) ? units_ids[1] : -1;
    BCM_IF_ERROR_RETURN_MSG(vswitch_add_port_multi_dev(local_unit, remote_unit, vsi1, vswitch_metro_mp_info.sysports[1], gport2), "");

    /* add a third port to the vswitch */
    /* 6. create third vlan-port */
    units_array_make_local_first(units_ids, nof_units, vswitch_metro_mp_info.sysports[2]);
    flags = (vswitch_metro_mp_info.egress_failover_id[2]) ? BCM_VLAN_PORT_EGRESS_PROTECTION : 0;
    gport3 = 0;
    for (i = 0 ; i < nof_units ; i++){
        unit = units_ids[i];
        BCM_IF_ERROR_RETURN_MSG(is_system_port_is_local(unit, vswitch_metro_mp_info.sysports[2], &sysport_is_local), "");
        if(sysport_is_local || vswitch_metro_mp_info.multi_bidir) {
            BCM_IF_ERROR_RETURN_MSG(vswitch_metro_add_port(unit, 2, &gport3, flags), "");
            if(verbose){
                printf("created vlan=port   0x%08x in unit %d\n",gport3, unit);
            }     
            flags |= BCM_VLAN_PORT_WITH_ID;
        }
    }

    /* 7. add vlan-port to the vswitch and multicast */
    local_unit = units_ids[0];
    remote_unit = (nof_units > 1) ? units_ids[1] : -1;
    BCM_IF_ERROR_RETURN_MSG(vswitch_add_port_multi_dev(local_unit, remote_unit, vsi1, vswitch_metro_mp_info.sysports[2], gport3), "");

    /* 8. add vlan-port to the l2 addr */
    for (i = 0 ; i < nof_units ; i++){
        unit = units_ids[i];
        BCM_IF_ERROR_RETURN_MSG(is_system_port_is_local(unit, vswitch_metro_mp_info.sysports[2], &sysport_is_local), "");
        if(sysport_is_local || vswitch_metro_mp_info.multi_bidir) {
            BCM_IF_ERROR_RETURN_MSG(vswitch_add_l2_addr_w_group_id(unit, gport3, kmac, 0, kvlan), "");
        }
    }

    vswitch_metro_mp_info.vsi = vsi1;
    return BCM_E_NONE;
}





/*
 * Basic example of vswitch in multiple device
 */
int
vswitch_metro_mp_multi_device(
    int unit1,
    int port1,
    int unit2,
    int port2,
    int port3)
{
    bcm_vlan_t vsi = 6000;
    bcm_mac_t known_mac = {0x00, 0x00, 0x00, 0x00, 0x00, 0x11};
    int index;
    int local_port;
    int flags;
    bcm_gport_t gport1, gport2, gport3;

    /* init values */
    vswitch_metro_mp_info_init(port1, port2, port3);
    vswitch_metro_mp_info.vsi = vsi;

    /* The default ingress/ egress actions and mapping are not configured. This is here to compensate. */
    BCM_IF_ERROR_RETURN_MSG(vlan_translation_default_mode_init(unit1), "on unit1");

    BCM_IF_ERROR_RETURN_MSG(vlan_translation_default_mode_init(unit2), "on unit2");

    /* Create VLANs on unit1 */
    for (index = 0; index < 4; index++)
    {
        /* If it's double tag, ignore inner VLAN */
        if (single_vlan_tag && (((index % 2) != 0))) {
            continue;
        }
        BCM_IF_ERROR_RETURN_MSG(bcm_vlan_create(unit1, vswitch_metro_mp_info.p_vlans[index]), "");

        BCM_IF_ERROR_RETURN_MSG(bcm_vlan_gport_add(unit1, vswitch_metro_mp_info.p_vlans[index], port1, 0), "port1");
    }

    /* Create VLANs on unit2 */
    for (index = 4; index < 12; index++)
    {
        /* If it's double tag, ignore inner VLAN */
        if (single_vlan_tag && (((index % 2) != 0))) {
            continue;
        }
        BCM_IF_ERROR_RETURN_MSG(bcm_vlan_create(unit2, vswitch_metro_mp_info.p_vlans[index]), "");

        if (index < 8) {
            BCM_IF_ERROR_RETURN_MSG(bcm_vlan_gport_add(unit2, vswitch_metro_mp_info.p_vlans[index], port2, 0), "port2");
        } else {
            BCM_IF_ERROR_RETURN_MSG(bcm_vlan_gport_add(unit2, vswitch_metro_mp_info.p_vlans[index], port3, 0), "port3");
        }
    }

    /*
     * Create vsi and multicast group
     */
    BCM_IF_ERROR_RETURN_MSG(vswitch_create(unit1, &vsi, 1), "");

    BCM_IF_ERROR_RETURN_MSG(vswitch_create(unit2, &vsi, 1), "");

    /*
     * Create VLAN ports
     */

    /* 1st AC on unit1 */
    flags = (vswitch_metro_mp_info.egress_failover_id[0]) ? BCM_VLAN_PORT_EGRESS_PROTECTION : 0;
    BCM_IF_ERROR_RETURN_MSG(vswitch_metro_add_port(unit1, 0, &gport1, flags), "");
    if(verbose){
        printf("created vlan-port   0x%08x in unit %d\n",gport1, unit1);
    }

    /* Add vlan-port to the vswitch and multicast */
    BCM_IF_ERROR_RETURN_MSG(vswitch_add_port_multi_dev(unit1, unit2, vsi, vswitch_metro_mp_info.sysports[0], gport1), "");

    /* 2nd AC on unit2 */
    flags = ( vswitch_metro_mp_info.egress_failover_id[1]) ? BCM_VLAN_PORT_EGRESS_PROTECTION : 0;
    BCM_IF_ERROR_RETURN_MSG(vswitch_metro_add_port(unit2, 1, &gport2, flags), "");
    if(verbose){
        printf("created vlan-port   0x%08x in unit %d\n",gport2, unit2);
    }

    /* Add vlan-port to the vswitch and multicast */
    BCM_IF_ERROR_RETURN_MSG(vswitch_add_port_multi_dev(unit2, unit1, vsi, vswitch_metro_mp_info.sysports[1], gport2), "");

    /* 3rd AC on unit2 */
    flags = ( vswitch_metro_mp_info.egress_failover_id[2]) ? BCM_VLAN_PORT_EGRESS_PROTECTION : 0;
    BCM_IF_ERROR_RETURN_MSG(vswitch_metro_add_port(unit2, 2, &gport3, flags), "");
    if(verbose){
        printf("created vlan-port   0x%08x in unit %d\n",gport3, unit2);
    }

    /* Add vlan-port to the vswitch and multicast */
    BCM_IF_ERROR_RETURN_MSG(vswitch_add_port_multi_dev(unit2, unit1, vsi, vswitch_metro_mp_info.sysports[2], gport3), "");

    return BCM_E_NONE;
}

/*
 * Create L2 VPN (VSI and MC group)
 */
int vswitch_create(
    int unit,
    bcm_vlan_t *new_vsi,
    int with_id)
{
    bcm_vlan_t vsi;
    bcm_vlan_control_vlan_t vsi_control;

    /* 1. create vswitch */
    if (!with_id)
    {
        BCM_IF_ERROR_RETURN_MSG(bcm_vswitch_create(unit,new_vsi), "");

        if(verbose){
            printf("created vswitch   0x%08x\n\r", *new_vsi);
        }
    } else {
        BCM_IF_ERROR_RETURN_MSG(bcm_vswitch_create_with_id(unit, *new_vsi), "");
        
        if(verbose){
            printf("created vswitch with id  0x%08x\n\r", *new_vsi);
        }
    }

    vsi = *new_vsi;
    /* 2. create multicast:
     *     - to be used for vswitch flooding
     *     - has to be same id as vswitch
     */
    egress_mc = 0;
    int mc_group = vsi;
    BCM_IF_ERROR_RETURN_MSG(multicast__open_mc_group(unit, &mc_group, 0), "");

    if(verbose){
        printf("created multicast   0x%08x\n\r",vsi);
    }

    /*  set vlan control, to flood */
    bcm_vlan_control_vlan_t_init(&vsi_control);
    /* setting FID, filtering database, for accessing the MACT, for shared learning */
    /* for VSI (not vlans) has to be equal to VSI */
    vsi_control.forwarding_vlan = vsi;
    /* set multicast groups for flooding */
    /* 2 options:
    1. all values equal, and equal to VSI
    2. uc_group = VSI, and mc = uc + 4k, and bc = mc + 4k */
    vsi_control.unknown_unicast_group   = vsi;
    vsi_control.unknown_multicast_group = vsi;
    vsi_control.broadcast_group         = vsi;

    BCM_IF_ERROR_RETURN_MSG(bcm_vlan_control_vlan_set(unit,vsi,vsi_control), "");

    return BCM_E_NONE;
}

/*
 * Add AC on both units to multicast group
 */
int system_multicast_vlan_port_add(
    int unit1,
    int unit2,
    bcm_port_t sys_port,
    bcm_gport_t gport,
    int mc_group_id)
{

    BCM_IF_ERROR_RETURN_MSG(multicast__gport_encap_add(unit1, mc_group_id, sys_port, gport, egress_mc), "for AC");

    if (unit2 != -1) {
        BCM_IF_ERROR_RETURN_MSG(multicast__gport_encap_add(unit2, mc_group_id, sys_port, gport, egress_mc), "for AC");
    }

    return BCM_E_NONE;
}

/*
 * Add AC to the vswitch and multicast for multiple device
 */
int vswitch_add_port_multi_dev(
    int unit1,
    int unit2,
    bcm_vlan_t vsi,
    bcm_port_t sys_port,
    bcm_gport_t gport)
{

    BCM_IF_ERROR_RETURN_MSG(bcm_vswitch_port_add(unit1, vsi, gport), "");

    if(verbose){
        printf("add port   0x%08x to vswitch   0x%08x \n\r",gport, vsi);
    }

    /* update Multicast to have the added port */
    BCM_IF_ERROR_RETURN_MSG(system_multicast_vlan_port_add(unit1, unit2, sys_port , gport, vsi), "");

    if(verbose){
        printf("add port   0x%08x to multicast 0x%08x in unit1 %d, unit2 %d\n",gport, vsi, unit1, unit2);
    }

    return BCM_E_NONE;
}

/*
 * Add AC to the vswitch and multicast
 */
int vswitch_add_port(
    int unit,
    bcm_vlan_t vsi,
    bcm_port_t sys_port,
    bcm_gport_t gport)
{

    /* add to vswitch */
    BCM_IF_ERROR_RETURN_MSG(bcm_vswitch_port_add(unit, vsi, gport), "");
    if(verbose){
        printf("add port   0x%08x to vswitch   0x%08x \n\r",gport, vsi);
    }

    /* update Multicast to have the added port  */
    BCM_IF_ERROR_RETURN_MSG(multicast__gport_encap_add(unit, vsi, sys_port , gport, 0), "");
    if(verbose){
        printf("add port   0x%08x to multicast 0x%08x in unit %d\n",gport, vsi, unit);
    }

    return BCM_E_NONE;
}

/* 
* Search vlan-port with index in array vswitch_metro_mp_info.
* vlan-port: is Logical interface identified by (port-vlan-vlan). 
* index 0 - valn_port 1, index 1 - vlan_port 2, index 2 - vlan_port 3
*/
int
vswitch_metro_find_port(int unit, int index, bcm_gport_t *port_id){
    bcm_vlan_port_t vp1;
    bcm_vlan_port_t_init(&vp1);
    
    /* the match criteria is port, out-vlan, in-vlan*/
    vp1.criteria = single_vlan_tag ? BCM_VLAN_PORT_MATCH_PORT_VLAN : BCM_VLAN_PORT_MATCH_PORT_VLAN_STACKED;
      
    vp1.port = vswitch_metro_mp_info.sysports[index];
    
    vp1.match_vlan = vswitch_metro_mp_info.p_vlans[index*4];
    vp1.match_inner_vlan = single_vlan_tag ? 0 : vswitch_metro_mp_info.p_vlans[index*4+1];

    BCM_IF_ERROR_RETURN_MSG(bcm_vlan_port_find(unit,&vp1), "");
    

    *port_id = vp1.vlan_port_id;

    return BCM_E_NONE;
}

/*
 * Remove vlan-port from vsi and delete it.
 * index 0 - vlan_port 1, index 1 - vlan_port 2, index 2 - vlan_port 3
 */
int
vswitch_metro_delete_port(int unit, int index, bcm_gport_t *port_id){
    bcm_mac_t kmac;
    uint16 vsi;
  
    kmac[5] = 0xce;	
    
    if (*port_id == -1){
        BCM_IF_ERROR_RETURN_MSG(vswitch_metro_find_port(unit, index, port_id), "");
    }
    
    BCM_IF_ERROR_RETURN_MSG(bcm_vswitch_port_get(unit, *port_id, &vsi), "");
    
    BCM_IF_ERROR_RETURN_MSG(bcm_vswitch_port_delete(unit, vsi, *port_id), "");
  
    if(verbose){
        printf("remove port   0x%08x from vsi   0x%08x \n",*port_id, vsi);
    }
  
    BCM_IF_ERROR_RETURN_MSG(bcm_vlan_port_destroy(unit,*port_id), "");
  
    if(verbose){
        printf("delete port   0x%08x in unit %d \n",*port_id, unit);
    }
    
    return BCM_E_NONE;
}

int vswitch_delete(int unit){

   /*1. delete multicast group*/
   BCM_IF_ERROR_RETURN_MSG(bcm_multicast_destroy(unit, vswitch_metro_mp_info.vsi), "");

   if(verbose){
       printf("delete multicast   0x%08x in unit %d\n",vswitch_metro_mp_info.vsi, unit);
   }

   /*2. destroy vswitch */
   BCM_IF_ERROR_RETURN_MSG(bcm_vswitch_destroy(unit, vswitch_metro_mp_info.vsi), "");

   if(verbose){
       printf("destroy vswitch   0x%08x in unit %d\n", vswitch_metro_mp_info.vsi, unit);
    }
     
   return BCM_E_NONE;
}
