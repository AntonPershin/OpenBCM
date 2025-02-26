/*
 * 
 This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 
 Copyright 2007-2022 Broadcom Inc. All rights reserved. File: cint_mpls_ecmp_basic.c Purpose: Various examples for MPLS. 
 */

/*
 * File: cint_mpls_ecmp.c
 * Purpose: Example of MPLS-ECMP configuration
 * 
 * Incoming Packet with dip 160.161.161.163 and random sip
 * 
 *          Edge router
 *              +--------------------------------------------------------+
 *              |                                                        |
 *              |                                                        |
 *              |                                                        |
 *              |                    +-------+                           |
 *              |                    | MPLS  |                           |
 *              |          +---------+ LABEL +---------------->          |----> IPV4oMPLSoETH(tagged) packet (mpls label==0x101)
 *              |          |         | 0x101 |                           |
 *              |          |         +-------+                           |
 *              |          |                                             |
 *              |          |                                             |
 *              |  +-------+         +-------+                           |
 *  IP route    |  |       |         | MPLS  |                           |
 *  --------->  |  | ECMP  +---------+ LABEL +---------------->          |----> IPV4oMPLSoETH(tagged) packet (mpls label==0x102)
 *  IPV4oETH    |  |       |         | 0x102 |                           |
 *  PACKETS     |  +-------+         +-------+                           |
 *              | Load     |                                             |
 *              | balance  |                                             |
 *              | -------  |                                             |
 *              | Choose   |         +-------+                           |
 *              | a fec    |         | MPLS  |                           |
 *              | from the +---------+ LABEL +---------------->          |----> IPV4oMPLSoETH(tagged) packet (mpls label==0x103)
 *              | 3 fec list.        | 0x103 |                           |
 *              | From the fec we    +-------+                           |
 *              | get the mpls label (0x101/0x102/0x103), with which we  |
 *              | later get the outlif and out port                      |
 *              |                                                        |
 *              +--------------------------------------------------------+
 * 
 *  Incoming IPV4 over Ethernet (untagged) packets coming from in_port
 *  ecmp interface will point to an MPLS tunnel and the fec will be chosen according to the hash result.
 *  The chosen fec will result in an mpls label
 *
 * Packets:
 *  Incoming
 *  +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+++++++++++++
 *  | Ethernet                                           | IPV4                                         |
 *  +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+++++++++++++
 *  | DA                | SA                 | ETHERTYPE | DIP             | SIP                        |  
 *  | 00:11:00:00:01:12 | 00:11:00:00:01:12  | 0x8100    | 160.161.161.163 | random                     |
 *  +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+++++++++++++
 *
 *  Outgoing:
 *  +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
 *  | Ethernet                                           | MPLS                    | IPV4                         |
 *  +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
 *  | DA                | SA                |  ETHERTYPE | Label | TC | BOS | TTL  | DIP                | SIP     |
 *  | 00:00:00:00:cd:1d | 00:0C:00:02:0F:55 |  0x8847    | 0x101 |    |  1  |      | 160.161.161.163    |         |
 *  |                   |                   |            | 0x102 |    |  1  |      |                    |         |
 *  |                   |                   |            | 0x103 |    |  1  |      |                    |         |
 *  +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
 *
 * Configuration:
 *  
 * Test Scenario - start
 * cint;                                                                  
 * cint_reset();                                                          
 * exit; 
  cint ../../../../src/examples/sand/cint_ip_route_basic.c   
  cint ../../../../src/examples/sand/cint_sand_utils_global
  cint ../../../../src/examples/sand/cint_ecmp_basic.c
  cint ../../../../src/examples/sand/cint_mpls_ecmp_basic.c
  cint                                                                   
  int unit = 0; 
  int rc = 0; 
  int in_port = 200; 
  int out_port = 201;
  rc = mpls_ecmp_basic_main(unit,in_port,out_port);
  print rc; 
 * Test Scenario - end
 * 
 */
int MEMBERS_IN_ECMP_GROUP = 3;

struct cint_mpls_ecmp_basic_info_s
{
    int in_port;                                                    /* incoming port */
    int out_port;                                                   /* outgoing port */
    int intf_in;                                                    /* in RIF */
    int intf_out;                                                   /* out RIF */
    bcm_mac_t intf_in_mac_address;                                  /* mac for in RIF */
    bcm_mac_t intf_out_mac_address;                                 /* mac for out RIF */
    bcm_mac_t arp_next_hop_mac;                                     /* mac for out RIF */
    int arp_id;                                                     /* Id for ARP entry for push entry */
    bcm_ip_t dip;                                                   /* dip 1 */
    uint32 mask;                                                    /* mask for dip */
    int vrf;                                                        /* VRF */
    bcm_if_t fec_ids[MEMBERS_IN_ECMP_GROUP];                        /* FEC ids for the ecmp group */
    bcm_mpls_label_t ecmp_tunnel_labels[MEMBERS_IN_ECMP_GROUP];     /* Tunnels for each ecmp group member */
    bcm_if_t ecmp_intf;                                             /* ECMP interface id */
    int ingress_qos_profile;                                        /* Ingress qos profile */
};

cint_mpls_ecmp_basic_info_s cint_mpls_ecmp_basic_info =
{
    /*
     * ports : in_port | out_port 
     */
   200, 201,
    /*
     * intf_in | intf_out 
     */
    20, 42,
    /*
     * intf_in_mac_address | intf_out_mac_address | arp_next_hop_mac | 
     */
    {0x00, 0x0c, 0x00, 0x02, 0x00, 0x00}, {0x00, 0x0c, 0x00, 0x02, 0x0f, 0x55}, {0x00, 0x00, 0x00, 0x00, 0xcd, 0x1d},
    /*
     * arp_id 
     */
    0x1011, /* in init, some global lif might be allocated in some device(in which mdb.feature.eedb_bank_traffic_lock is set) */
    /*
     * dip
     */
    0xA0A1A1A3 /* 160.161.161.163 */ ,
    /*
     * mask
     */
    0xfffffff0,
   /*
     * vrf
     */
    1,
    /*
     * fec_id_1 | fec_id_2 | fec_id_3
     */
    {50001, 50002, 50003},
    /*
     * ecmp_tunnel_labels
     */
    {0x101, 0x102, 0x103},
    /*
     * ecmp_intf
     */
    0x104,
    /*
     * ingress_qos_profile | egress_qos_profile
     */
    3
};

int
mpls_ecmp_basic_configure_port_properties(
    int unit)
{
    /*
     * Set In-Port to In ETh-RIF 
     */
    BCM_IF_ERROR_RETURN_MSG(in_port_intf_set(unit, cint_mpls_ecmp_basic_info.in_port, cint_mpls_ecmp_basic_info.intf_in), "intf_in");

    /*
     * Set Out-Port default properties 
     */
    BCM_IF_ERROR_RETURN_MSG(out_port_set(unit, cint_mpls_ecmp_basic_info.out_port), "intf_out");

    return BCM_E_NONE;
}

int
mpls_ecmp_basic_create_l3_interfaces(
    int unit)
{
    l3_ingress_intf ingr_itf;
    l3_ingress_intf_init(&ingr_itf);
    /*
     * Create ETH-RIF and set its properties 
     */
    BCM_IF_ERROR_RETURN_MSG(intf_eth_rif_create(unit, cint_mpls_ecmp_basic_info.intf_in,
                             cint_mpls_ecmp_basic_info.intf_in_mac_address), "intf_in");
    BCM_IF_ERROR_RETURN_MSG(intf_eth_rif_create(unit, cint_mpls_ecmp_basic_info.intf_out,
                             cint_mpls_ecmp_basic_info.intf_out_mac_address), "intf_out");

    /*
     * Set Incoming ETH-RIF properties  (like vrf)
     */
    ingr_itf.intf_id = cint_mpls_ecmp_basic_info.intf_in;
    bcm_qos_map_id_get_by_profile(unit,BCM_QOS_MAP_INGRESS | BCM_QOS_MAP_PHB | BCM_QOS_MAP_REMARK,cint_mpls_ecmp_basic_info.ingress_qos_profile, &ingr_itf.qos_map);
    ingr_itf.vrf = cint_mpls_ecmp_basic_info.vrf;
    BCM_IF_ERROR_RETURN_MSG(intf_ingress_rif_set(unit, &ingr_itf), "intf_out");

    return BCM_E_NONE;
}

int
mpls_ecmp_basic_create_arp_entry(
    int unit)
{
    /*
     * Configure ARP entry 
     */
    BCM_IF_ERROR_RETURN_MSG(l3__egress_only_encap__create(unit, 0,&(cint_mpls_ecmp_basic_info.arp_id),
                                       cint_mpls_ecmp_basic_info.arp_next_hop_mac,
                                       cint_mpls_ecmp_basic_info.intf_out), "create egress object ARP only");

    return BCM_E_NONE;
}

/* Create MPLS tunnel */
int
mpls_ecmp_basic_tunnel_initiator_create(
   int unit, 
   int label, 
   int* tunnel_id) 
{
    int num_labels = 1;
    /* Intf parameter must be set to 0 when creating tunnel */
    bcm_if_t intf = 0;
    bcm_mpls_egress_label_t mpls_label;
    char *proc_name;

    proc_name = "mpls_ecmp_basic_tunnel_initiator_create";
    /* printf("%s(): Enter. Label = 0x%04X\n", proc_name, label); */
    bcm_mpls_egress_label_t_init(&mpls_label);
    mpls_label.label = label;
    mpls_label.l3_intf_id = cint_mpls_ecmp_basic_info.arp_id;
    mpls_label.flags |= BCM_MPLS_EGRESS_LABEL_TTL_DECREMENT;
    

    printf("%s(): Call bcm_mpls_tunnel_initiator_create() with intf = 0x%08X\n",proc_name, intf);
    BCM_IF_ERROR_RETURN_MSG(bcm_mpls_tunnel_initiator_create(unit, intf, num_labels, &mpls_label), "");

    *tunnel_id = mpls_label.tunnel_id;
    /* printf("%s(): MPLS tunnel created. Label = 0x%04X, Tunnel id = 0x%08X\n", proc_name, mpls_label.label, *tunnel_id); */
    return BCM_E_NONE;
}

int 
mpls_ecmp_basic_fec_create(
   int unit, 
   int tunnel_id, 
   bcm_if_t fec_id) 
{
    /* char *proc_name; */
    int flags2 = 0;

    /* proc_name = "mpls_ecmp_basic_fec_create"; */
    if (*dnxc_data_get(unit, "l3", "feature", "separate_fwd_rpf_dbs", NULL))
    {
        flags2 |= BCM_L3_FLAGS2_FWD_ONLY;
    }
    /* printf("%s(): Enter. FEC ID = 0x%08X, for tunnel id = 0x%08X\r\n", proc_name, fec_id, tunnel_id); */
    BCM_IF_ERROR_RETURN_MSG(l3__egress_only_fec__create(unit, fec_id, tunnel_id, 0, cint_mpls_ecmp_basic_info.out_port, 0,flags2), "");

    /* printf("%s(): Exit. FEC created. FEC ID = 0x%08X, for tunnel id = 0x%08X\n", proc_name, fec_id, tunnel_id); */
    return BCM_E_NONE;
}

int
mpls_ecmp_basic_create_l3_forwarding(
   int unit, 
   int intf)
{
    if (*dnxc_data_get(unit, "l3", "fwd", "host_entry_support", NULL))
    {
        BCM_IF_ERROR_RETURN_MSG(add_host_ipv4(unit, cint_mpls_ecmp_basic_info.dip, cint_mpls_ecmp_basic_info.vrf, intf, 0, 0), "");
    }
    else
    {
        BCM_IF_ERROR_RETURN_MSG(add_route_ipv4(unit, cint_mpls_ecmp_basic_info.dip, 0xFFFFFFFF, cint_mpls_ecmp_basic_info.vrf,
                intf), "");

    }

    return BCM_E_NONE;
}

/*
 * Main function for basic mpls ecmp scnenario in Jericho 2: Forward according to IP into MPLS tunnel, 
 * label chosen by ecmp load balancing (3 options) 
 */
int 
mpls_ecmp_basic_main(
   int unit, 
   int in_port, 
   int out_port) 
{
    int i;
    int fec_direction = 0;
    /* char *proc_name;
    proc_name = "mpls_ecmp_basic_main";
    printf("%s(): Enter. in_port = %d, out_port = %d\n", proc_name, in_port, out_port); */

    cint_mpls_ecmp_basic_info.in_port = in_port;
    cint_mpls_ecmp_basic_info.out_port = out_port;

    /*
     * Configure port properties
     */
    BCM_IF_ERROR_RETURN_MSG(mpls_ecmp_basic_configure_port_properties(unit), "");

    /*
     * Configure L3 interfaces 
     */
    BCM_IF_ERROR_RETURN_MSG(mpls_ecmp_basic_create_l3_interfaces(unit), "");

    /*
     * Configure an ARP entry 
     */
    BCM_IF_ERROR_RETURN_MSG(mpls_ecmp_basic_create_arp_entry(unit), "");

    /* 
     * Creating MPLS tunnels for outgoing packets and assign them to fecs. 
     * Each fec will also hold the mpls label encapsulated into the packet. 
     * Fec will be chosen according to ECMP                                                                   .
     */
    int tunnel_ids[MEMBERS_IN_ECMP_GROUP];
    if (*dnxc_data_get(unit, "l3", "feature", "separate_fwd_rpf_dbs", NULL))
    {
        fec_direction = 0;
    }
    else
    {
        fec_direction = 1;
    }
    BCM_IF_ERROR_RETURN_MSG(get_first_fec_in_range_which_not_in_ecmp_range(unit, 0, fec_direction, &cint_mpls_ecmp_basic_info.fec_ids[0]), "");
    for (i = 1; i < MEMBERS_IN_ECMP_GROUP; i++)
    {
       cint_mpls_ecmp_basic_info.fec_ids[i] = cint_mpls_ecmp_basic_info.fec_ids[0] + i;
    }

    for (i = 0; i < MEMBERS_IN_ECMP_GROUP; i++)
    {
        BCM_IF_ERROR_RETURN_MSG(mpls_ecmp_basic_tunnel_initiator_create(unit, cint_mpls_ecmp_basic_info.ecmp_tunnel_labels[i], &tunnel_ids[i]), "");
        BCM_IF_ERROR_RETURN_MSG(mpls_ecmp_basic_fec_create(unit, tunnel_ids[i], cint_mpls_ecmp_basic_info.fec_ids[i]), "");
    }

    /* 
     * Create ecmp
     */
    bcm_l3_egress_ecmp_t ecmp;
    /*
     * Until ECMP allocation manager is ready, ecmp is created with WITH_ID flag
     */
    BCM_IF_ERROR_RETURN_MSG(l3__ecmp_create(unit, cint_mpls_ecmp_basic_info.ecmp_intf, MEMBERS_IN_ECMP_GROUP, cint_mpls_ecmp_basic_info.fec_ids, BCM_L3_WITH_ID, BCM_L3_ECMP_DYNAMIC_MODE_DISABLED,&ecmp,0), "");

    /* 
     * Add host entry, pointing at the ecmp interface, so that the forwarding is done on dip
     */

    BCM_IF_ERROR_RETURN_MSG(mpls_ecmp_basic_create_l3_forwarding(unit, ecmp.ecmp_intf), "");

    /* printf("%s(): Exit. in_port = %d, out_port = %d \n", proc_name, in_port, out_port); */
    return BCM_E_NONE;
}

