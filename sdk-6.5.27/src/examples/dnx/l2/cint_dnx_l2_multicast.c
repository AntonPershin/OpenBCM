/* **************************************************************************************************************************************************
 *                                                                                                                                                  * 
 *                                                                                                                                                  * 
 *                                                                                                                                                  * 
 *                                                                                                                                                  * 
 * The cint creates a Multicast flooding scheme with all Ports of a VSI.                                                                            *
 * The packet will be received on all member ports with same tag status a incoming tag.                                                             * 
 *                                                                                                                                                  * 
 *                          tpid action                                                                                                             *
 *             +-------+       none                                                                                                                 *
 *    Port_1   |       |      +-----+      +------+     +---------+      Port_2                                                                     *
 *    +------> | LIF 1 +----> |IVE 1+----> |      |     |         |      LIF_2                                                                      *
 *             |       |      +-----+      | VSI  |     |         +--------------------------------+                                                *
 *             +-------+                   |      |     |         |      Port_3                    |                                                *
 *                                         |      +---> | MCID    |      LIF_3                     |                                                *
 *                                         |      |     | LOOKUP  +-----------------------+        |                                                *
 *                                         +------+     |         |      Port_4           |        |                                                *
 *                                                      |         |      LIF_4            |        |                                                *
 *                                                      |         +----------------+      |        |                                                *
 *                                                      +---------+                |      |        |                                                *
 *                                                                                 |      |        |                                                *
 *                                                                                 |      |        |                                                *
 *                                                                                 |      |        |                                                *
 *                                                                                 |      |        |                                                *
 *                                                       +---------+               |      |        |                                                *
 *                           Port_4          +------+    |         |               |      |        |                                                *
 *                         <-----------------+ EVE  | <--+ Out LIF +<--------------+      |        |                                                *
 *                                           +------+    |         |                      |        |                                                *
 *                                          {None,None}  +---------+                      |        |                                                *
 *                                                                                        |        |                                                *
 *                                                                                        |        |                                                *                                               
 *                                                       +---------+                      |        |                                                *
 *                           Port_3          +------+    |         |                      |        |                                                *
 *                         <-----------------+ EVE  | <--+ Out LIF +<---------------------+        |                                                *
 *                                           +------+    |         |                               |                                                *
 *                                          {None,None}  +---------+                               |                                                *
 *                                                                                                 |                                                *
 *                                                                                                 |                                                *                     
 *                                                       +---------+                               |                                                *
 *                           Port_2          +------+    |         |                               |                                                *
 *                         <-----------------+ EVE  | <--+ Out LIF +<------------------------------+                                                *
 *                                           +------+    |         |                                                                                *
 *                                          {None,None}  +---------+                                                                                *
 *                                                                                                                                                  *
 *                                                                                                                                                  *
 *                                                                                                                                                  *
 *                                                                                                                                                  * 
 * InLif : Based on incoming pkt format we create inlif                                                                                             *
 *         We are using step argument as the refernece                                                                                              *
 *       -------------------------------------------------------------------------------------------------------------------                        *                                   
 *       | STEP  | flood type      | incoming pkt format | inlif criteria                            | Test plan Scenario  |                        *                                   
 *       -------------------------------------------------------------------------------------------------------------------                        *                                   
 *       |   0   | Broadcast       |    untag            | Default LIF                               |  2.1                |                        *                                   
 *       -------------------------------------------------------------------------------------------------------------------                        *                                   
 *       |   1   | Broadcast       |     ctag            | ISEM {VDxCVLAN}                           |  2.2                |                        *                                   
 *       -------------------------------------------------------------------------------------------------------------------                        *                                   
 *       |   2   | Broadcast       |     PS+C Tag        | ISEM {VD x SVLAN x CVLAN }                |  2.3                |                        *                                   
 *       -------------------------------------------------------------------------------------------------------------------                        *                                   
 *       |   0   | known_egress_multicast |    untag            | Default LIF                               |  7.1                |                        *
 *       -------------------------------------------------------------------------------------------------------------------                        *                                   
 *       |   1   | known_egress_multicast |     ctag            | ISEM {VDxCVLAN}                           |  7.2                |                        *
 *       -------------------------------------------------------------------------------------------------------------------                        *                                   
 *       |   2   | known_egress_multicast |     dtag            | ISEM {VDxSVLAN}                           |  7.3                |                        *
 *       -------------------------------------------------------------------------------------------------------------------                        *                                   
 *                                                                                                                                                  * 
 * OutLif : Outlifs are derived based on MCID lookup.                                                                                               *
 *          MCID Database is programmed with Lifs (for signals verification) created with criteria MATCH_PORT_VLAN.                                 * 
 *          IVE,EVE actions are programmed as NOOP to preserve incoming tag status.                                                                 *
 *                                                                                                                                                  *
 * INPUT & OUTPUT:                                                                                                                                  * 
 *                                                                                                                                                  *
 *       ----------------------------------------------------------------------------------------------------------------------------------------   *
 *       | STEP  | flood type              | DA                  |Inport    | FWD lookup                    | Outports                                  |   *
 *       ----------------------------------------------------------------------------------------------------------------------------------------   *  
 *       | 0,1,2 | Broadcast               | ff:ff:ff:ff:ff:ff   |Port_1    | VSI based MCID destination    | Port_2, Port_3, Port_4 (To all members of |   *
 *       |       |                         |                     |          |                               | VSI/VLAN domain) Resolved using  Ingress  |   *
 *       |       |                         |                     |          |                               | Multicasting                              |   *
 *       ----------------------------------------------------------------------------------------------------------------------------------------   *
 *       | 0,1,2 | known_egress_multicast  | DA[40]=1            |Port_1    | SVL lookup {VSI x MAC-DA }    |  Port_3, Port_4 (To all members of MCID   |   *
 *       |       |                         | DA[47:23]!=0x01005e |          | in MACT.                      |  group 73) Resolved using Egress          |   *
 *       |       |                         |                     |          | MACT lookup ->                |  multicasting                             |   *
 *       |       |                         |                     |          | ->MCID destination = 73       |                                           |   *
 *       ----------------------------------------------------------------------------------------------------------------------------------------   *
 *       | 0,1,2 | known_ingress_multicast | DA[40]=1            |Port_1    | SVL lookup {VSI x MAC-DA }    |  Port_3, Port_4 (To all members of MCID   |   *
 *       |       |                         | DA[47:23]!=0x01005e |          | in MACT.                      |  group 73) Resolved using Ingress         |   *
 *       |       |                         |                     |          | MACT lookup ->                |  multicasting                             |   *
 *       |       |                         |                     |          | ->MCID destination = 73       |                                           |   *
 *       ----------------------------------------------------------------------------------------------------------------------------------------   *
 *                                                                                                                                                  *
 *                                                                                                                                                  *
 *                                                                                                                                                  *
 *                                                                                                                                                  *
 * All default values could be re-written with initialization of the global structure 'g_l2_multicast_flood', before calliing the main  function    * 
 * In order to re-write only part of values, call 'l2_multicast_flood_struct_get(l2_multicast_flood_s)' function and re-write values,               *
 * prior calling the main function                                                                                                                  * 
*************************************************************************************************************************************************** */
/* **************************************************************************************************
  --------------          Global Variables Definition and Initialization  START     -----------------
 **************************************************************************************************** */
/* tag formats */
int tag_format_untag = 0;
int tag_format_stag = 4;
int tag_format_ctag = 8;
int tag_format_dtag = 16;
int tag_format_s_prio_c_tag = 24;
int egr_vlan_edit_profile_stag=6;


int IN_PORT_INDEX = 0;
int NUM_OF_OUT_PORTS = 3;
int OUT_PORT_INDEX[NUM_OF_OUT_PORTS] = {1, 2, 3};
int NUM_OF_PORTS = 4;

struct global_tpids_s{
    uint16 s_tag;       /* ingress packet s_tag (outer tag)*/
    uint16 c_tag;       /* ingress packet c_tag (inner tag)*/
    uint16 outer_tpid;  /* egress packet outer tag*/
    uint16 inner_tpid;  /* egress packet inner tag*/
};

enum multicast_type {
    unknown_unicast = 0,
    unknown_multicast = 1,
    broadcast = 2,
    known_egress_multicast = 3,
    known_ingress_multicast = 4
};


/*  Main Struct  */
struct l2_multicast_flood_s{
    bcm_gport_t ports[NUM_OF_PORTS];
    bcm_vlan_t vsi;
    bcm_vlan_t match_vlan;
    bcm_vlan_t port_default_vlan;
    bcm_mac_t d_mac;    
    bcm_multicast_t mcid;
    int nof_replications;
    global_tpids_s tpid_value;
    bcm_vlan_t outer_vid;
    bcm_gport_t inLifList[NUM_OF_PORTS];
    bcm_gport_t outLifList[NUM_OF_PORTS];
    multicast_type type;
    int unknown_da_profile_destination;
    int vsi_da_not_found_destination;
};

/* Initialization of global struct*/
l2_multicast_flood_s g_l2_multicast_flood =
{
/*  ports  */
    {0, 0, 0, 0},
/*  vsi:   */
    10,
/*  match_vlan */
    33,
/*  default_vlan */
    10,
/*  d_mac  */
    {0x01, 0x00, 0x00, 0x00, 0x12, 0x34},
/*  mcid */
    73,
/* nof_replications */
    1,
/*  tpid_value:
     |s_tag  | c_tag | outer | inner |*/
    { 0x9100, 0x8100, 0x9100, 0x8100},
/*  outer_vid */
    10,
/*  inLifList */
    {0, 0, 0, 0},
/*  outLifList  */
    {0, 0, 0, 0},
/*  Multicast type */
    broadcast,
/*  unknown_da_profile_destination */
    6,
/*  vsi_da_not_found_destination */
    11,
};

/* **************************************************************************************************
  --------------          Global  Variables Definitions and Initialization  END       ---------------
 **************************************************************************************************** */
/* Initialization of main struct
 * Function allow to re-write default values 
 *
 * INPUT:
 *   params: new values for g_l2_multicast_flood
 */
int l2_multicast_flood_init(int unit, l2_multicast_flood_s *param){
    if (param != NULL) {
       sal_memcpy(&g_l2_multicast_flood, param, sizeof(g_l2_multicast_flood));
    }
    return BCM_E_NONE;
}

/* 
 * Return g_l2_multicast_flood information
 */
void l2_multicast_flood_struct_get(int unit, l2_multicast_flood_s *param){

    sal_memcpy( param, &g_l2_multicast_flood, sizeof(g_l2_multicast_flood));

    return BCM_E_NONE;
}

/* This function runs the main test function with given ports
 *  
 * INPUT: unit     - unit
 *        in_port  - ingress port 
 *        out_port - egress port
 */
int l2_multicast_flood_with_ports__main_config__start_run(int unit, multicast_type type, int in_port, int out_port1, int out_port2, int out_port3, int step){

    l2_multicast_flood_s param;

    l2_multicast_flood_struct_get(unit, &param);

    param.ports[IN_PORT_INDEX] = in_port;
    param.ports[OUT_PORT_INDEX[0]] = out_port1;
    param.ports[OUT_PORT_INDEX[1]] = out_port2;
    param.ports[OUT_PORT_INDEX[2]] = out_port3;
    param.type = type;

    /*Send packets to a subset of vlan domain members*/
    if (param.type == known_egress_multicast || param.type == known_ingress_multicast) {
        NUM_OF_OUT_PORTS = 2;
        param.ports[OUT_PORT_INDEX[0]] = out_port2;
        param.ports[OUT_PORT_INDEX[1]] = out_port3;
    }

    return l2_multicast_flood__main_config__start_run(unit, &param, step);
}

/*
 * Main function runs the Broadcast da example. 
 *  
 * Main steps of configuration: 
 *    1. Initialize test parameters
 *    2. Setting VLAN domain for ingress/egress ports.
 *    3. Setting relevant TPID's for ingress/egress ports.
 *    4. Configuring Multicast group for vlan flooding
 *    
 * INPUT: unit  - unit
 *        param - new values for l2_multicast_flood_s(in case it's NULL default values will be used).
 */
int l2_multicast_flood__main_config__start_run(int unit,  l2_multicast_flood_s *param, int step){
    int i;
    int flags;
    char error_msg[200]={0,};

    BCM_IF_ERROR_RETURN_MSG(l2_multicast_flood_init(unit, param), "");

    /* set VLAN domain to each port */
    for (i=0; i< NUM_OF_PORTS; i++) {
        snprintf(error_msg, sizeof(error_msg), "(port = %d)", g_l2_multicast_flood.ports[i]);
        BCM_IF_ERROR_RETURN_MSG(bcm_port_class_set(unit, g_l2_multicast_flood.ports[i], bcmPortClassId, g_l2_multicast_flood.ports[i]), error_msg);
    }

    /* 
     * Configuring TPIDs
     */
    BCM_IF_ERROR_RETURN_MSG(tpid__tpids_clear_all(unit), "");

    snprintf(error_msg, sizeof(error_msg), "(tpid_value=0x%04x)", g_l2_multicast_flood.tpid_value.s_tag);
    BCM_IF_ERROR_RETURN_MSG(tpid__tpid_add(unit, g_l2_multicast_flood.tpid_value.s_tag), error_msg);

    snprintf(error_msg, sizeof(error_msg), "(tpid_value=0x%04x)", g_l2_multicast_flood.tpid_value.c_tag);
    BCM_IF_ERROR_RETURN_MSG(tpid__tpid_add(unit, g_l2_multicast_flood.tpid_value.c_tag), error_msg);

    /* Configure Port.Default_vlan*/
    snprintf(error_msg, sizeof(error_msg), "(port=%d)", g_l2_multicast_flood.ports[IN_PORT_INDEX]);
    BCM_IF_ERROR_RETURN_MSG(bcm_port_untagged_vlan_set(unit, g_l2_multicast_flood.ports[IN_PORT_INDEX], g_l2_multicast_flood.port_default_vlan), error_msg);

    /* Create VSI:*/
    snprintf(error_msg, sizeof(error_msg), "(vsi=%d)", g_l2_multicast_flood.vsi);
    BCM_IF_ERROR_RETURN_MSG(bcm_vlan_create(unit, g_l2_multicast_flood.vsi), error_msg);

    /* 
     * Set VLAN port membership
     */
    bcm_pbmp_t pbmp, untag_pbmp;

    BCM_PBMP_CLEAR(pbmp);
    BCM_PBMP_CLEAR(untag_pbmp);

    for (i=0; i<NUM_OF_PORTS; i++) {
        BCM_PBMP_PORT_ADD(pbmp, g_l2_multicast_flood.ports[i]);
        BCM_PBMP_PORT_ADD(untag_pbmp, g_l2_multicast_flood.ports[i]);
    }

    BCM_IF_ERROR_RETURN_MSG(bcm_vlan_port_add(unit, g_l2_multicast_flood.vsi, pbmp, untag_pbmp), "");
    BCM_IF_ERROR_RETURN_MSG(bcm_vlan_gport_add(unit, g_l2_multicast_flood.match_vlan, g_l2_multicast_flood.ports[IN_PORT_INDEX], 0), "");

    /*
     * Creates LIF for Tx port
     */
    bcm_vlan_port_t vlan_port;
    bcm_vlan_port_t_init(&vlan_port);
    /* Dummy lif creation to get non zero value of local lif*/
    vlan_port.criteria = BCM_VLAN_PORT_MATCH_PORT_VLAN;
    vlan_port.match_vlan = g_l2_multicast_flood.match_vlan*2;
    vlan_port.vsi = 0;
    vlan_port.port =  g_l2_multicast_flood.ports[IN_PORT_INDEX];
    snprintf(error_msg, sizeof(error_msg), "(port = %d)", vlan_port.port);
    BCM_IF_ERROR_RETURN_MSG(bcm_vlan_port_create(unit, &vlan_port), error_msg);

     bcm_vlan_port_t_init(&vlan_port);

    /*Actual Inlif Derivation: */
    /*InLIF creation*/
    vlan_port.flags = BCM_VLAN_PORT_WITH_ID;
    vlan_port.vsi = 0;
    vlan_port.port = g_l2_multicast_flood.ports[IN_PORT_INDEX];
    
    /*
     * Based on multicast_type value and step value we configure criteria for Lif derivation.
     */
    if (g_l2_multicast_flood.type == known_egress_multicast || g_l2_multicast_flood.type == known_ingress_multicast) {
        if (step == 0) {
            /* Tx tag: Untag*/    
            /* Default LIF */
            vlan_port.flags |= BCM_VLAN_PORT_CREATE_INGRESS_ONLY;
            vlan_port.criteria = BCM_VLAN_PORT_MATCH_PORT;
            vlan_port.vsi = g_l2_multicast_flood.vsi;
        } else if (step == 1) {
            /* Tx tag: C-Tag */
            vlan_port.criteria = BCM_VLAN_PORT_MATCH_PORT_CVLAN;
            vlan_port.match_vlan = g_l2_multicast_flood.match_vlan;
        } else if (step == 2) {
            /* Tx tag: D-Tag */
            vlan_port.criteria = BCM_VLAN_PORT_MATCH_PORT_VLAN;
            vlan_port.match_vlan = g_l2_multicast_flood.match_vlan;
        }
    } else if (g_l2_multicast_flood.type == broadcast) {
        if (step == 0) {
            /* Tx tag: UnTag*/    
            /* Default LIF */
            vlan_port.flags |= BCM_VLAN_PORT_CREATE_INGRESS_ONLY;
            vlan_port.criteria = BCM_VLAN_PORT_MATCH_PORT;
            vlan_port.vsi = g_l2_multicast_flood.vsi;
        } else if (step == 1) {
            /* Tx tag: C-Tag */
            vlan_port.criteria = BCM_VLAN_PORT_MATCH_PORT_CVLAN;
            vlan_port.match_vlan = g_l2_multicast_flood.match_vlan;
        } else if (step == 2) {
            /* Tx tag: PS+CTag*/    
            vlan_port.criteria = BCM_VLAN_PORT_MATCH_PORT_VLAN_STACKED;
            vlan_port.match_vlan = 0;
            vlan_port.match_inner_vlan = g_l2_multicast_flood.match_vlan;
        }
    }

    /*InLif Value is fixed for signals verification:*/    
    /*GPORT_TYPE <<26, GPORT_SUB_TYPE <<22; ingress_only/egress_only/symmetric<<20; lif vlaue*/
    if (vlan_port.flags & BCM_VLAN_PORT_CREATE_INGRESS_ONLY) {

        if (*dnxc_data_get(unit, "flow", "general", "is_flow_enabled_for_legacy_applications", NULL))
        {
           BCM_GPORT_SUB_TYPE_VIRTUAL_INGRESS_NON_NATIVE_SET(g_l2_multicast_flood.inLifList[IN_PORT_INDEX],5000);
        } else {
            BCM_GPORT_SUB_TYPE_LIF_SET(g_l2_multicast_flood.inLifList[IN_PORT_INDEX], BCM_GPORT_SUB_TYPE_LIF_EXC_INGRESS_ONLY, 5000);
        }
    }
    else if (vlan_port.flags & BCM_VLAN_PORT_CREATE_EGRESS_ONLY) {
       BCM_GPORT_SUB_TYPE_LIF_SET(g_l2_multicast_flood.inLifList[IN_PORT_INDEX], BCM_GPORT_SUB_TYPE_LIF_EXC_EGRESS_ONLY, 5000);
    }
    else
    {
        BCM_GPORT_SUB_TYPE_LIF_SET(g_l2_multicast_flood.inLifList[IN_PORT_INDEX], 0, 5000);
    }
    BCM_GPORT_VLAN_PORT_ID_SET(g_l2_multicast_flood.inLifList[IN_PORT_INDEX], g_l2_multicast_flood.inLifList[IN_PORT_INDEX]);
    vlan_port.vlan_port_id = g_l2_multicast_flood.inLifList[IN_PORT_INDEX];

    snprintf(error_msg, sizeof(error_msg), "(port = %d)", vlan_port.port);
    BCM_IF_ERROR_RETURN_MSG(bcm_vlan_port_create(unit, &vlan_port), error_msg);
    printf("port=%d, vsi=%d, vlan_port_id=0x%08x, encap_id=0x%04x\n", vlan_port.port, vlan_port.vsi, vlan_port.vlan_port_id, vlan_port.encap_id);
    
    /*Setting up vsi for Lifs - only for symmetric LIFs:*/
    if ( (vlan_port.flags & (BCM_VLAN_PORT_CREATE_INGRESS_ONLY | BCM_VLAN_PORT_CREATE_EGRESS_ONLY)) == 0 ) {
        snprintf(error_msg, sizeof(error_msg), "(port = %d)", g_l2_multicast_flood.ports[IN_PORT_INDEX]);
        BCM_IF_ERROR_RETURN_MSG(bcm_vswitch_port_add(unit, g_l2_multicast_flood.vsi, vlan_port.vlan_port_id), error_msg);
    }

    /*  Ingress LLVP configs: To identify C-tag packets */
    bcm_port_tpid_class_t port_tpid_class;
    bcm_port_tpid_class_t_init(&port_tpid_class);
    port_tpid_class.flags = BCM_PORT_TPID_CLASS_INGRESS_ONLY | BCM_PORT_TPID_CLASS_OUTER_C;
    port_tpid_class.tpid1 = g_l2_multicast_flood.tpid_value.c_tag;
    port_tpid_class.tpid2 = BCM_PORT_TPID_CLASS_TPID_INVALID;
    port_tpid_class.tag_format_class_id = tag_format_ctag;
    port_tpid_class.port =  g_l2_multicast_flood.ports[IN_PORT_INDEX];

    snprintf(error_msg, sizeof(error_msg), "( iPort%d )", g_l2_multicast_flood.ports[IN_PORT_INDEX]);
    BCM_IF_ERROR_RETURN_MSG(bcm_port_tpid_class_set(unit, &port_tpid_class), error_msg);

    /*  Ingress LLVP configs: To identify D-tag packets - not priority */
    bcm_port_tpid_class_t_init(&port_tpid_class);
    port_tpid_class.flags = BCM_PORT_TPID_CLASS_INGRESS_ONLY | BCM_PORT_TPID_CLASS_OUTER_NOT_PRIO;
    port_tpid_class.tpid1 = g_l2_multicast_flood.tpid_value.s_tag;
    port_tpid_class.tpid2 = g_l2_multicast_flood.tpid_value.c_tag;
    port_tpid_class.tag_format_class_id = tag_format_dtag;
    port_tpid_class.port =  g_l2_multicast_flood.ports[IN_PORT_INDEX];

    snprintf(error_msg, sizeof(error_msg), "( iPort%d )", g_l2_multicast_flood.ports[IN_PORT_INDEX]);
    BCM_IF_ERROR_RETURN_MSG(bcm_port_tpid_class_set(unit, &port_tpid_class), error_msg);

    /*  Ingress LLVP configs: To identify D-tag packets - s-tag is priority */
    bcm_port_tpid_class_t_init(&port_tpid_class);

    port_tpid_class.flags = BCM_PORT_TPID_CLASS_INGRESS_ONLY | BCM_PORT_TPID_CLASS_OUTER_IS_PRIO;
    port_tpid_class.tpid1 = g_l2_multicast_flood.tpid_value.s_tag;
    port_tpid_class.tpid2 = g_l2_multicast_flood.tpid_value.c_tag;
    port_tpid_class.tag_format_class_id = tag_format_s_prio_c_tag;
    port_tpid_class.port =  g_l2_multicast_flood.ports[IN_PORT_INDEX];

    snprintf(error_msg, sizeof(error_msg), "( iPort%d )", g_l2_multicast_flood.ports[IN_PORT_INDEX]);
    BCM_IF_ERROR_RETURN_MSG(bcm_port_tpid_class_set(unit, &port_tpid_class), error_msg);

    /*
     * Creates Out LIFs (at EEDB) for signals verification
     */
    bcm_vlan_port_t_init(&vlan_port);

    vlan_port.flags = BCM_VLAN_PORT_CREATE_EGRESS_ONLY;
    vlan_port.criteria = BCM_VLAN_PORT_MATCH_NONE;
    vlan_port.vsi = 0;

    for (i=0; i<NUM_OF_OUT_PORTS; i++) {
       /*
       * vlan_port.port = g_l2_multicast_flood.ports[OUT_PORT_INDEX[i]];
       * port is irrelevant for this case, set it to zero! 
       */
        vlan_port.port = 0;

        snprintf(error_msg, sizeof(error_msg), "(port = %d)", vlan_port.port);
        BCM_IF_ERROR_RETURN_MSG(bcm_vlan_port_create(unit, &vlan_port), error_msg);

        g_l2_multicast_flood.outLifList[OUT_PORT_INDEX[i]] = vlan_port.vlan_port_id;

        printf("port=%d, vlan_port_id=0x%08x, encap_id=0x%04x\n", vlan_port.port, vlan_port.vlan_port_id, vlan_port.encap_id);
    }

    /* Destination resolution Configuration*/
    bcm_port_control_t flood_type;
    bcm_vlan_control_vlan_t control;

    /*Configures Port based profile, Unknown_DA_profile, ING_VSI_INFO tables */
    if (g_l2_multicast_flood.type == broadcast) {

        /*Configures PINFO_FLP_MEM.action_profile_da_not_found_index=1 and Unknown_DA_profile.destination */
        bcm_gport_t flood_destination;
        bcm_port_flood_group_t flood_groups;
        bcm_port_flood_group_t_init(&flood_groups);
        BCM_GPORT_MCAST_SET(flood_destination, g_l2_multicast_flood.unknown_da_profile_destination);
        flood_groups.broadcast_group = flood_destination;
        if (*dnxc_data_get(unit, "l2", "feature", "bc_same_as_unknown_mc", NULL)) {
            flood_groups.unknown_multicast_group = flood_groups.broadcast_group;
        }
        snprintf(error_msg, sizeof(error_msg), "in Port= %d", g_l2_multicast_flood.ports[IN_PORT_INDEX]);
        BCM_IF_ERROR_RETURN_MSG(bcm_port_flood_group_set(unit, g_l2_multicast_flood.ports[IN_PORT_INDEX], 0, &flood_groups), error_msg);

        /*Configures vsi.da_not_found_destination*/
        control.broadcast_group = g_l2_multicast_flood.vsi_da_not_found_destination;
        control.unknown_multicast_group = g_l2_multicast_flood.vsi_da_not_found_destination;
        control.unknown_unicast_group = g_l2_multicast_flood.vsi_da_not_found_destination;
        control.forwarding_vlan = g_l2_multicast_flood.vsi;
        snprintf(error_msg, sizeof(error_msg), "in vsi= %d", g_l2_multicast_flood.vsi);
        BCM_IF_ERROR_RETURN_MSG(bcm_vlan_control_vlan_set(unit, g_l2_multicast_flood.vsi, control), error_msg);

        g_l2_multicast_flood.mcid = g_l2_multicast_flood.vsi_da_not_found_destination + g_l2_multicast_flood.unknown_da_profile_destination;
    }

    /* Multicast Configuration*/
    /*Create multicast group*/
    if (g_l2_multicast_flood.type == known_egress_multicast)
    {
        flags = BCM_MULTICAST_EGRESS_GROUP;
    } else {
        if (*dnxc_data_get(unit, "multicast", "params", "mcdb_formats_v2", NULL)) {
            flags = BCM_MULTICAST_INGRESS_GROUP | BCM_MULTICAST_ELEMENT_STATIC;
        } else {
            flags = BCM_MULTICAST_INGRESS_GROUP;
        }
    }
    BCM_IF_ERROR_RETURN_MSG(bcm_multicast_create(unit, (BCM_MULTICAST_WITH_ID | flags), &g_l2_multicast_flood.mcid), "");

    bcm_multicast_replication_t rep_array;
    bcm_multicast_replication_t_init(&rep_array);
    int system_port_id;
    bcm_gport_t sysport_gport;

    /*Adding Ports to MCID group*/
    for(i=0;i<NUM_OF_OUT_PORTS;i++) {
        /*
         * map logical port to sysport_gport assuming DNX default reference application (system ports defined)
         */
        appl_dnx_logical_port_to_sysport_get(unit, 0 /* base_modid */ , g_l2_multicast_flood.ports[OUT_PORT_INDEX[i]], &system_port_id);
        BCM_GPORT_SYSTEM_PORT_ID_SET(sysport_gport, system_port_id);

        rep_array.port =  sysport_gport;
        rep_array.encap1 = (g_l2_multicast_flood.outLifList[OUT_PORT_INDEX[i]] & 0x3fffff);

        snprintf(error_msg, sizeof(error_msg), "in Port= %d", g_l2_multicast_flood.ports[OUT_PORT_INDEX[i]]);
        BCM_IF_ERROR_RETURN_MSG(bcm_multicast_add(unit, g_l2_multicast_flood.mcid, flags, g_l2_multicast_flood.nof_replications, &rep_array), error_msg);
    }

    /* Configure MACT table to derive MCID as destination for KMC packets*/
    if (g_l2_multicast_flood.type == known_egress_multicast || g_l2_multicast_flood.type == known_ingress_multicast) {
        if(g_l2_multicast_flood.type == known_egress_multicast)
        {
            BCM_IF_ERROR_RETURN_MSG(multicast__open_fabric_mc_or_ingress_mc_for_egress_mc(unit, g_l2_multicast_flood.mcid, g_l2_multicast_flood.mcid), "");
        }

        bcm_l2_addr_t l2_addr;

        bcm_l2_addr_t_init(&l2_addr, g_l2_multicast_flood.d_mac, g_l2_multicast_flood.vsi);

        l2_addr.flags = BCM_L2_STATIC | BCM_L2_MCAST;
        l2_addr.l2mc_group = g_l2_multicast_flood.mcid;

        BCM_IF_ERROR_RETURN_MSG(bcm_l2_addr_add(unit, &l2_addr), "");
    }

    /* EGRESS TPID Profiles for different TAGs on Out Port */
    bcm_port_tpid_class_t_init(&port_tpid_class);

    port_tpid_class.tpid1 = BCM_PORT_TPID_CLASS_TPID_INVALID;
    port_tpid_class.tpid2 = BCM_PORT_TPID_CLASS_TPID_INVALID;
    port_tpid_class.flags = BCM_PORT_TPID_CLASS_EGRESS_ONLY;

    for(i=0;i<NUM_OF_OUT_PORTS;i++) {

        port_tpid_class.port =  g_l2_multicast_flood.ports[OUT_PORT_INDEX[i]];
        port_tpid_class.tag_format_class_id = tag_format_untag;

        snprintf(error_msg, sizeof(error_msg), "( %d )", g_l2_multicast_flood.ports[OUT_PORT_INDEX[i]]);
        BCM_IF_ERROR_RETURN_MSG(bcm_port_tpid_class_set(unit, &port_tpid_class), error_msg);
    }

    /*
     * Egress Vlan Edit
     * Tag After IVE = Untag
     * Out Pkt = Untag
     * Hence EVE ={None,None}
     */
    for(i=0;i<NUM_OF_OUT_PORTS;i++) {
        snprintf(error_msg, sizeof(error_msg), "( %d )", g_l2_multicast_flood.ports[OUT_PORT_INDEX[i]]);
        BCM_IF_ERROR_RETURN_MSG(vlan_translate_ive_eve_translation_set(
                                unit,
                                g_l2_multicast_flood.outLifList[OUT_PORT_INDEX[i]],   /* lif - need the gport, thus use inLifList instead of outLifList */
                                g_l2_multicast_flood.tpid_value.s_tag,     /* outer_tpid */
                                g_l2_multicast_flood.tpid_value.c_tag,     /* inner_tpid */
                                bcmVlanActionNone,                 /* outer_action */
                                bcmVlanActionNone,                 /* inner_action */
                                0,                                 /* new_outer_vid*/
                                0,                                 /* new_inner_vid*/
                                egr_vlan_edit_profile_stag,        /* vlan_edit_profile */
                                tag_format_untag,                  /* tag_format */
                                FALSE                              /* is_ive */
                                ), error_msg);
    }
    return BCM_E_NONE;
}


/*
 * Cleanup function runs the vlan translate tpid modify example 
 *  
 * Main steps of configuration: 
 *    1. Delete all TPIDs.
 *    2. Destroy VSI.
 *    3. Destroy LIFs.
 *    4. Destroy Multicast group.
 *    
 * INPUT: unit - unit
 */
int l2_multicast_flood__cleanup__start_run(int unit){
    char error_msg[200]={0,};
    int i;

    printf("l2_multicast_flood__cleanup__start_run\n");
    /*
     * Destroy OutLIFs
     */
    for (i=0; i<NUM_OF_OUT_PORTS; i++) {

        snprintf(error_msg, sizeof(error_msg), "(port = %d)", g_l2_multicast_flood.outLifList[OUT_PORT_INDEX[i]]);
        BCM_IF_ERROR_RETURN_MSG(bcm_vlan_port_destroy(unit, g_l2_multicast_flood.outLifList[OUT_PORT_INDEX[i]]), error_msg);

    }

    /*
     * Destroy InLIFs
     */
    snprintf(error_msg, sizeof(error_msg), "(port = %d)", g_l2_multicast_flood.inLifList[IN_PORT_INDEX]);
    BCM_IF_ERROR_RETURN_MSG(bcm_vlan_port_destroy(unit, g_l2_multicast_flood.inLifList[IN_PORT_INDEX]), error_msg);

    /* 
     * VSI
     */
    snprintf(error_msg, sizeof(error_msg), "(vsi=%d)", g_l2_multicast_flood.vsi);
    BCM_IF_ERROR_RETURN_MSG(bcm_vlan_destroy(unit, g_l2_multicast_flood.vsi), error_msg);

    /*
     * TPIDs
     */
    BCM_IF_ERROR_RETURN_MSG(tpid__tpids_clear_all(unit), error_msg);

    /*
     * Destroy Multicast Group
     */
    if (*dnxc_data_get(unit, "multicast", "params", "mcdb_formats_v2", NULL)) {
        BCM_IF_ERROR_RETURN_MSG(bcm_multicast_group_destroy(unit, (BCM_MULTICAST_INGRESS_GROUP | BCM_MULTICAST_ELEMENT_STATIC), g_l2_multicast_flood.mcid), "");
    } else {
        BCM_IF_ERROR_RETURN_MSG(bcm_multicast_destroy(unit, g_l2_multicast_flood.mcid), "");
    }
    return BCM_E_NONE;
}

