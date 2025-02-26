/*
 * 
 This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 
 Copyright 2007-2022 Broadcom Inc. All rights reserved. File: cint_vpls_mp_basic.c Purpose: basic example for VPLS. 
 */

/*
 * 
 * Configuration:
 * 
 * Test Scenario - start
 * cint;
 * cint_reset();
 * exit;
  cint ../../../../src/examples/dnx/utility/cint_dnx_utils_global.c
  cint ../../../../src/examples/dnx/cint_dnx_ip_route_basic.c
  cint ../../../../src/examples/dnx/utility/cint_dnx_utils_l3.c
  cint ../../../../src/examples/dnx/cint_dnx_vpls_roo_basic.c
  cint ../../../../src/examples/dnx/utility/cint_dnx_utils_vlan_translate.c
  cint
  int unit = 0; 
  int rv = 0; 
  int access_port = 200; 
  int core_port = 201;
  rv = vpls_roo_basic_main(unit,access_port,core_port);
  print rv; 
 * Test Scenario - end
 * 
 *  Scenarios configured in this cint:
 * 
 *  ~~~~~~~~~~~~~~~~~~~~~~~~~
 *   Routing into overlay
 *  ~~~~~~~~~~~~~~~~~~~~~~~~~
 *
 *  Traffic:
 * 
 * Send through port 200 IPv4oETH into core. Route into core with IPv4oETHoMPLSoMPLSoETH on port 202. 
 *  ##############################################################################################
 * 
 *   ----------->
 * 
 *   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 *   |    +-+-+-+-+-+-+-+-+-+-+-+-+-++-+-+-+-++-+-+-+-+-+-++-+-+-+-+-+-+-+-++-+-+-+-+-+-  
 *   |    |      DA         | SA              |  SIP         ||  DIP          ||  TTL |
 *   |    |00:0F:00:02:0A:44|00:00:00:00:DD:2F|127.255.255.01||127.255.255.02 || 128  |
 *   |    |                 |                 |              ||               ||      |
 *   |    |                 |                 |              ||               ||      |
 *   |    +-+-+-+-+-+-+-+-+-+-+-+-+-+--+-+-+-++-+-+-+-+-+-+--+-+-+-+-+-+-+-++-+-+-+-+-+-
 *   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * 
 *   <------------
 * 
 *   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 *   |    +-+-+-+-+-+-+-+-+-+-+-+-+-++-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+++-+-++-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-++-+--++-+-+-+-+-+-+-+-+-+-+-+-+-++-+-+-+-+-+-+-++-+-+-+-+-
 *   |    |      DA         | SA              ||TPID1 |VID||   MPLS    ||MPLS (PWE)||TPID1 |VID|      DA         | SA              ||  SIP       ||  DIP           ||  TTL ||
 *   |    |00:00:00:00:CD:1E|00:0F:00:02:0A:33||0x8100|20 ||Label:4444 ||Label:3333||0x8100|30 |00:00:00:00:CD:1D|00:0F:00:02:0A:22||127.255.255.01||127.255.255.02|| 127  ||
 *   |    |                 |                 ||      |   ||Exp:0      ||Exp:0     ||      |   |                 |                 ||            ||                ||      ||
 *   |    |                 |                 ||      |   ||TTL:127    ||TTL:127   ||      |   |                 |                 ||            ||                ||      ||
 *   |    +-+-+-+-+-+-+-+-+-+-+-+-+-+--+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+++-+-+--+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+--+--++-+-+-+-+-+-+-+-+-+-+-+-+-+--+-+-+-+-+-+-++-+-+-+-+-
 *   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * ############################################################################################################################################################################
 *
 *  ~~~~~~~~~~~~~~~~~~~~~~~~~
 *   Routing out of overlay
 *  ~~~~~~~~~~~~~~~~~~~~~~~~~
 *
 *  Traffic:
 * 
 *  Send through port 201 IPv4oETHoMPLSoETH out of core. Route into access with IPv4oETH on port 201:
 *
 *  #####################################################################################################################################
 *   ----------->
 * 
 *   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 *   |    +-+-+-+-+-+-+-+-+-+-+-+-+-++-+-+-+-+-+-+++-+-++-+-+-+-+-+-+-+-+-+-++-+--++-+-+-+-+-+-+-+-+-+-+-+-+-++-+-+-+-+-+-+-++-+-+-+-+-+-
 *   |    |      DA         | SA              |MPLS (PWE)|      DA         | SA              ||  SIP         ||  DIP          ||  TTL ||
 *   |    |00:0F:00:02:0A:33|00:00:00:00:CD:1E|Label:3333|00:0F:00:02:0A:22|00:00:00:00:FD:2F||127.255.255.01||127.255.255.03 || 128  ||
 *   |    |                 |                 |Exp:0     |                 |                 ||              ||               ||      ||
 *   |    |                 |                 |          |                 |                 ||              ||               ||      ||
 *   |    +-+-+-+-+-+-+-+-+-+-+-+-+-+--+-+-+-+-+-+++-+-+--+-+-+-+-+-+-+-+-+-+--+--++-+-+-+-+-+-+-+-+-+-+-+-+-+--+-+-+-+-+-+-++-+-+-+-+-+-
 *   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * 
 *   <------------
 * 
 *   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 *   |    +-+-+-+-+-+-+-+-+-+-+-+-+-++-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-++-+-+-+-+-+-+-++-+-+-+-+-+-  
 *   |    |      DA         | SA              ||TPID1 |VID||  SIP         ||  DIP         ||  TTL ||
 *   |    |00:00:00:00:CD:1F|00:0F:00:02:0A:44||0x8100|10 ||127.255.255.01||127.255.255.03|| 127  ||
 *   |    |                 |                 ||      |   ||              ||              ||      ||
 *   |    |                 |                 ||      |   ||              ||              ||      ||
 *   |    +-+-+-+-+-+-+-+-+-+-+-+-+-+--+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+--+-+-+-+-+-+-++-+-+-+-+-+-
 *   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

 * ##################################################################################################
 *
 */

struct cint_vpls_roo_basic_info_s
{
    int access_port;            /* incoming port from acsess side */
    int core_port;              /* incoming port from core side */
    int core_native_eth_rif;    /* core native RIF */
    int core_overlay_eth_rif;   /* core overlay RIF */
    int access_eth_rif;         /* access RIF */
    bcm_gport_t core_overlay_mpls_port_id_ing;  /* global lif encoded as MPLS port for overlay (ingress side) */
    bcm_gport_t core_overlay_mpls_port_id_eg;   /* global lif encoded as MPLS port for overlay 1 (egress side) */
    bcm_gport_t outer_ac_vlan_port_id;  /* vlan port id of the ac_port, used for ingress */
    bcm_if_t core_overlay_pwe_encap_id; /* The global lif of the EEDB PWE entry. */
    int core_native_arp_id;     /* Id for core native ARP entry */
    int core_overlay_arp_id;    /* Id for core overlay ARP entry */
    int access_arp_id;          /* Id for access ARP entry */
    int core_native_fec_id;     /* core native fec id for native outrif and native arp */
    int core_overlay_fec_id;    /* core overlay fec id for overlay */
    int core_overlay_fec_id2;    /* core overlay fec id for overlay (third hierarchy) */
    int access_fec_id;          /* access fec id for access outrif and access arp */
    bcm_mac_t core_native_eth_rif_mac;  /* mac for core native RIF */
    bcm_mac_t core_overlay_eth_rif_mac; /* mac for core overlay RIF */
    bcm_mac_t access_eth_rif_mac;       /* mac for access RIF */
    bcm_mac_t core_native_next_hop_mac; /* mac for next core native hop */
    bcm_mac_t core_overlay_next_hop_mac;        /* mac for next core overlay hop */
    bcm_mac_t access_next_hop_mac;      /* mac for next access hop */
    uint32 dip1;                /* first dip */
    uint32 dip2;                /* second dip */
    int outer_tpid;             /* Outer tpid for application */
    int inner_tpid;             /* Inner tpid for application */
    bcm_if_t core_overlay_mpls_tunnel_id;       /* tunnel id for encapsulation entry */
    bcm_mpls_label_t core_overlay_mpls_tunnel_label_1;  /* pushed label */
    bcm_mpls_label_t core_overlay_mpls_tunnel_label_2;  /* pushed label */
    bcm_mpls_label_t core_overlay_pwe_label;    /* pwe label */
    bcm_gport_t egress_native_ac_vlan_port_id;  /* vlan port id of the inner ac_port, used for egress */
    uint32 egress_vlan_edit_profile, ingress_vlan_edit_profile;
    int tag_format;
    int ingress_qos_map_id; 
    int egr_qos_map_id;
    int egr_term_qos_map_id;
    uint8 ttl;
    int vmpi;
};

cint_vpls_roo_basic_info_s cint_vpls_roo_basic_info = {
    /*
     * ports : access_port | core_port 
     */
    200, 201,
    /*
     * core_native_eth_rif
     */
    30,
    /*
     * core_overlay_eth_rif  
     */
    20,
    /*
     * access_eth_rif  
     */
    10,
    /*
     * core_overlay_mpls_port_id_ing| core_overlay_mpls_port_id_eg |  outer_ac_vlan_port_id |  core_overlay_pwe_encap_id 
     */
    0, 0, 8888, 0,
    /*
     * core_native_arp_id | core_overlay_arp_id | access_arp_id
     */
    0, 0, 0,
    /*
     * core_native_fec_id | core_overlay_fec_id |  core_overlay_fec_id2 | access_fec_id
     */
    60000, 120000, 170000, 60010,
    /*
     * core_native_eth_rif_mac | core_overlay_eth_rif_mac | access_eth_rif_mac
     */
    {0x00, 0x0F, 0x00, 0x02, 0x0A, 0x22}, {0x00, 0x0F, 0x00, 0x02, 0x0A, 0x33}, {0x00, 0x0F, 0x00, 0x02, 0x0A, 0x44},
    /*
     * core_native_next_hop_mac |  core_overlay_next_hop_mac | access_next_hop_mac
     */
    {0x00, 0x00, 0x00, 0x00, 0xCD, 0x1D}, {0x00, 0x00, 0x00, 0x00, 0xCD, 0x1E}, {0x00, 0x00, 0x00, 0x00, 0xCD, 0x1F},
    /*
     *dip1 | dip2
     127.255.255.02 , 127.255.255.03
     */
    0x7fffff02, 0x7fffff03,
    /*
     * outer_tpid | inner_tpid 
     */
    0x8100, 0x88a8,
    /*
     * core_overlay_mpls_tunnel_id 
     */
    8196,
    /*
     * core_overlay_mpls_tunnel_label_1  | core_overlay_mpls_tunnel_label_2 |  core_overlay_pwe_label
     */
    4444, 5555, 3333,
    /*
     * egress_native_ac_vlan_port_id
     */
    0,
    /*
     * egress_vlan_edit_profile, ingress_vlan_edit_profile 
     */
    4, 5,
    /*
     * tag_format 
     */

    0,
    /*
     * ingress_qos_map_id |egr_qos_map_id| egr_term_qos_map_id
     */
    7, 0, 2,
    /*
     * ttl
     */
    63,
    /*
     * vmpi
     */
    0
};

int verbose1 = 1;

int
vpls_roo_basic_init(
    int unit,
    int access_port,
    int core_port)
{

    cint_vpls_roo_basic_info.access_port = access_port;
    cint_vpls_roo_basic_info.core_port = core_port;

    BCM_IF_ERROR_RETURN_MSG(get_first_fec_in_range_which_not_in_ecmp_range(unit, 0, 0, &cint_vpls_roo_basic_info.core_native_fec_id), "");
    cint_vpls_roo_basic_info.core_native_fec_id += 60;
    cint_vpls_roo_basic_info.access_fec_id = cint_vpls_roo_basic_info.core_native_fec_id +5;
    BCM_IF_ERROR_RETURN_MSG(get_first_fec_in_range_which_not_in_ecmp_range(unit, 1, 0, &cint_vpls_roo_basic_info.core_overlay_fec_id), "");
    BCM_IF_ERROR_RETURN_MSG(get_first_fec_in_range_which_not_in_ecmp_range(unit, 2, 0, &cint_vpls_roo_basic_info.core_overlay_fec_id2), "");

    return BCM_E_NONE;

}

int
vpls_roo_basic_configure_port_properties(
    int unit,
    int access_port,
    int core_port)
{
    char error_msg[200]={0,};
    /*
     * set class for both ports 
     */
    snprintf(error_msg, sizeof(error_msg), "port=%d", access_port);
    BCM_IF_ERROR_RETURN_MSG(bcm_port_class_set(unit, access_port, bcmPortClassId, access_port), error_msg);

    snprintf(error_msg, sizeof(error_msg), "port=%d", core_port);
    BCM_IF_ERROR_RETURN_MSG(bcm_port_class_set(unit, core_port, bcmPortClassId, core_port), error_msg);

    /*
     * Set In-Port vmpi
     */
    if (!*dnxc_data_get (unit, "dev_init", "general", "application_v2", NULL))
    {
        BCM_IF_ERROR_RETURN_MSG(bcm_port_class_set(unit,core_port,bcmPortClassMplsForwardIngress,cint_vpls_roo_basic_info.vmpi), "");
    }

    /*
     * Set In-Port to In ETh-RIF 
     */
    BCM_IF_ERROR_RETURN_MSG(in_port_intf_set(unit, cint_vpls_roo_basic_info.access_port, cint_vpls_roo_basic_info.access_eth_rif), "intf_in");

    /*
     * Set In-Port to In ETh-RIF 
     */
    BCM_IF_ERROR_RETURN_MSG(in_port_intf_set(unit, cint_vpls_roo_basic_info.core_port, cint_vpls_roo_basic_info.core_overlay_eth_rif), "intf_in");

    /*
     * Set Out-Port default properties 
     */
    BCM_IF_ERROR_RETURN_MSG(out_port_set(unit, cint_vpls_roo_basic_info.access_port), "intf_out");

    /*
     * Set Out-Port default properties 
     */
    BCM_IF_ERROR_RETURN_MSG(out_port_set(unit, cint_vpls_roo_basic_info.core_port), "intf_out");

    return BCM_E_NONE;
}

int
vpls_roo_basic_create_eth_rifs(
    int unit)
{

    char error_msg[200]={0,};

    /*
     * create vlan based on the vsi (vpn) 
     */
    snprintf(error_msg, sizeof(error_msg), "Failed to create VLAN %d", cint_vpls_roo_basic_info.core_native_eth_rif);
    BCM_IF_ERROR_RETURN_MSG(bcm_vlan_create(unit, cint_vpls_roo_basic_info.core_native_eth_rif), error_msg);

    /*
     * create vlan based on the vsi (vpn) 
     */
    snprintf(error_msg, sizeof(error_msg), "Failed to create VLAN %d", cint_vpls_roo_basic_info.core_overlay_eth_rif);
    BCM_IF_ERROR_RETURN_MSG(bcm_vlan_create(unit, cint_vpls_roo_basic_info.core_overlay_eth_rif), error_msg);

    /*
     * create vlan based on the vsi (vpn) 
     */
    snprintf(error_msg, sizeof(error_msg), "Failed to create VLAN %d", cint_vpls_roo_basic_info.access_eth_rif);
    BCM_IF_ERROR_RETURN_MSG(bcm_vlan_create(unit, cint_vpls_roo_basic_info.access_eth_rif), error_msg);

    return BCM_E_NONE;
}


/*
 * Create VSI ETH-RIF and set initial properties:
 * - my_mac - My-MAC address
 */
int
intf_eth_rif_create_with_qos(
    int unit,
    int eth_rif_id,
    int qos_map_id,
    bcm_mac_t my_mac)
{
    bcm_l3_intf_t l3if;

    /*
     * Initialize a bcm_l3_intf_t structure.
     */
    bcm_l3_intf_t_init(&l3if);
    l3if.l3a_flags = BCM_L3_WITH_ID;

    /*
     * My-MAC
     */
    l3if.l3a_mac_addr = my_mac;
    l3if.l3a_intf_id = l3if.l3a_vid = eth_rif_id;
    l3if.dscp_qos.qos_map_id = qos_map_id;

    BCM_IF_ERROR_RETURN_MSG(bcm_l3_intf_create(unit, l3if), "");

    return BCM_E_NONE;
}

int
vpls_roo_basic_create_l3_interfaces(
    int unit)
{
    bcm_l3_ingress_t ingress_l3_interface;
    bcm_l3_ingress_t_init(&ingress_l3_interface);
    bcm_l3_intf_t l3if;
    int egr_term_qos_map_id, ing_qos_map_id;

    BCM_IF_ERROR_RETURN_MSG(intf_eth_rif_create(unit, cint_vpls_roo_basic_info.core_native_eth_rif,
                             cint_vpls_roo_basic_info.core_native_eth_rif_mac), "pwe_intf");
    /*ROO should update native rif qos model to uniform (default short_pipe)*/
    l3if.l3a_intf_id = cint_vpls_roo_basic_info.core_native_eth_rif;
    BCM_IF_ERROR_RETURN_MSG(bcm_l3_intf_get(unit, &l3if), "pwe_intf");
    l3if.ingress_qos_model.ingress_phb = bcmQosIngressModelUniform;
    l3if.ingress_qos_model.ingress_remark = bcmQosIngressModelUniform;
    l3if.ingress_qos_model.ingress_ttl = bcmQosIngressModelUniform;
    l3if.l3a_flags |= BCM_L3_REPLACE | BCM_L3_WITH_ID;
    BCM_IF_ERROR_RETURN_MSG(bcm_l3_intf_create(unit, &l3if), "pwe_intf");

    BCM_IF_ERROR_RETURN_MSG(intf_eth_rif_create(unit, cint_vpls_roo_basic_info.core_overlay_eth_rif,
                             cint_vpls_roo_basic_info.core_overlay_eth_rif_mac), "pwe_intf");
    
    BCM_IF_ERROR_RETURN_MSG(bcm_qos_map_id_get_by_profile(unit, BCM_QOS_MAP_EGRESS | BCM_QOS_MAP_REMARK,
                                       cint_vpls_roo_basic_info.egr_term_qos_map_id, &egr_term_qos_map_id), "");
    BCM_IF_ERROR_RETURN_MSG(intf_eth_rif_create_with_qos(unit, cint_vpls_roo_basic_info.access_eth_rif, egr_term_qos_map_id, cint_vpls_roo_basic_info.access_eth_rif_mac), "");

    /*
     * create ingress interface which supports public lookup
     */
    BCM_IF_ERROR_RETURN_MSG(bcm_qos_map_id_get_by_profile(unit, BCM_QOS_MAP_INGRESS | BCM_QOS_MAP_PHB | BCM_QOS_MAP_REMARK ,
                                       cint_vpls_roo_basic_info.ingress_qos_map_id, &ing_qos_map_id), "");
    ingress_l3_interface.flags = BCM_L3_INGRESS_WITH_ID;
    ingress_l3_interface.qos_map_id = ing_qos_map_id;
    BCM_IF_ERROR_RETURN_MSG(bcm_l3_ingress_create(unit, ingress_l3_interface, cint_vpls_roo_basic_info.access_eth_rif), "");

    BCM_IF_ERROR_RETURN_MSG(bcm_l3_ingress_create(unit, ingress_l3_interface, cint_vpls_roo_basic_info.core_overlay_eth_rif), "");

    BCM_IF_ERROR_RETURN_MSG(bcm_l3_ingress_create(unit, ingress_l3_interface, cint_vpls_roo_basic_info.core_native_eth_rif), "");
    return BCM_E_NONE;
}

int
vpls_roo_basic_create_arp_entries(
    int unit)
{

    /*
     * Configure native ARP entry 
     */
    BCM_IF_ERROR_RETURN_MSG(l3__egress_only_encap__create_inner(unit, 0, &(cint_vpls_roo_basic_info.core_native_arp_id),
                                             cint_vpls_roo_basic_info.core_native_next_hop_mac,
                                             cint_vpls_roo_basic_info.core_native_eth_rif,
                                             BCM_L3_NATIVE_ENCAP, BCM_L3_FLAGS2_VLAN_TRANSLATION),
                                             "create AC egress object ARP only");


    /*
     * Configure overlay ARP entry 
     */
    BCM_IF_ERROR_RETURN_MSG(l3__egress_only_encap__create(unit, 0, &(cint_vpls_roo_basic_info.core_overlay_arp_id),
                                       cint_vpls_roo_basic_info.core_overlay_next_hop_mac,
                                       cint_vpls_roo_basic_info.core_overlay_eth_rif),
                                       "create AC egress object ARP only");

    /*
     * Configure access ARP entry 
     */
    BCM_IF_ERROR_RETURN_MSG(l3__egress_only_encap__create(unit, 0, &(cint_vpls_roo_basic_info.access_arp_id),
                                       cint_vpls_roo_basic_info.access_next_hop_mac,
                                       cint_vpls_roo_basic_info.access_eth_rif),
                                       "create AC egress object ARP only");

    return BCM_E_NONE;

}

int
vpls_roo_basic_create_fec_entries(
    int unit)
{
    bcm_gport_t gport;
    int pointer_to_pwe;
    l3_egress_s l3_egress;

    /*
     * Create overlay FEC (third hierarchy)  for routing into overlay: 
     * 1) Tunnel id of the overlay MPLS . 
     * 2) Out port. 
     */
    gport = 0;
    dnx_utils_l3_egress_s_init(unit,0,&l3_egress);

    BCM_GPORT_LOCAL_SET(gport, cint_vpls_roo_basic_info.core_port);
    l3_egress.out_tunnel_or_rif = cint_vpls_roo_basic_info.core_overlay_mpls_tunnel_id;
    l3_egress.out_gport = gport;
    l3_egress.allocation_flags = BCM_L3_INGRESS_ONLY | BCM_L3_WITH_ID;
    l3_egress.l3_flags = BCM_L3_3RD_HIERARCHY;
    l3_egress.fec_id = cint_vpls_roo_basic_info.core_overlay_fec_id2;
    if(*dnxc_data_get(unit, "l3", "feature", "separate_fwd_rpf_dbs", NULL))
    {
        l3_egress.l3_flags2 |= BCM_L3_FLAGS2_FWD_ONLY;
    }
    BCM_IF_ERROR_RETURN_MSG(dnx_utils_l3_egress_create(unit, &l3_egress),
        "in creating overlay FEC, 3rd hierarchy, for routing into overlay");

    /*
     * Create overlay FEC (second hierarchy) for routing into overlay: 
     * 1) PWE gport converted to type l3_itf. 
     * 2) Point to third hierarchy FEC (that points to MPLS tunnel). 
     */
    gport = 0;
    dnx_utils_l3_egress_s_init(unit,0,&l3_egress);
    BCM_GPORT_FORWARD_PORT_SET(gport, cint_vpls_roo_basic_info.core_overlay_fec_id2);
    /* Convert to type L3_ITF, according to APT's expectation */
    pointer_to_pwe = BCM_GPORT_SUB_TYPE_LIF_VAL_GET(cint_vpls_roo_basic_info.core_overlay_mpls_port_id_eg);
    BCM_L3_ITF_SET(pointer_to_pwe,BCM_L3_ITF_TYPE_LIF,pointer_to_pwe);
    l3_egress.out_tunnel_or_rif = pointer_to_pwe;
    l3_egress.out_gport = gport;
    l3_egress.allocation_flags = BCM_L3_INGRESS_ONLY | BCM_L3_WITH_ID;
    l3_egress.l3_flags = BCM_L3_2ND_HIERARCHY;
    l3_egress.fec_id = cint_vpls_roo_basic_info.core_overlay_fec_id;
    if(*dnxc_data_get(unit, "l3", "feature", "separate_fwd_rpf_dbs", NULL))
    {
        l3_egress.l3_flags2 |= BCM_L3_FLAGS2_FWD_ONLY;
    }
    BCM_IF_ERROR_RETURN_MSG(dnx_utils_l3_egress_create(unit, &l3_egress),
        "in creating overlay FEC, second hierarchy, for routing into overlay");



    /*
     * Create native FEC (first hierarchy) for routing into overlay: 
     * 1) Native out rif. 
     * 2) Native arp id. 
     * 3) Point to overlay fec (second hierarchy). 
     */
    dnx_utils_l3_egress_s_init(unit,0,&l3_egress);
    BCM_GPORT_FORWARD_PORT_SET(gport, cint_vpls_roo_basic_info.core_overlay_fec_id);
    l3_egress.out_tunnel_or_rif = cint_vpls_roo_basic_info.core_native_eth_rif;
    l3_egress.arp_encap_id = cint_vpls_roo_basic_info.core_native_arp_id;
    l3_egress.out_gport = gport;
    l3_egress.allocation_flags = BCM_L3_INGRESS_ONLY| BCM_L3_WITH_ID;
    l3_egress.fec_id = cint_vpls_roo_basic_info.core_native_fec_id;
    if(*dnxc_data_get(unit, "l3", "feature", "separate_fwd_rpf_dbs", NULL))
    {
        l3_egress.l3_flags2 |= BCM_L3_FLAGS2_FWD_ONLY;
    }
    BCM_IF_ERROR_RETURN_MSG(dnx_utils_l3_egress_create(unit, &l3_egress),
        "in creating native FEC, first hierarchy,  for routing into overlay");


    /*
     * Create FEC for routing out of overlay: 
     * 1) Access out rif. 
     * 2) Access arp id. 
     * 3) Out port. 
     */
    dnx_utils_l3_egress_s_init(unit,0,&l3_egress);
    BCM_GPORT_LOCAL_SET(gport, cint_vpls_roo_basic_info.access_port);
    l3_egress.out_tunnel_or_rif = cint_vpls_roo_basic_info.access_eth_rif;
    l3_egress.arp_encap_id = cint_vpls_roo_basic_info.access_arp_id;
    l3_egress.out_gport = gport;
    l3_egress.allocation_flags = BCM_L3_INGRESS_ONLY | BCM_L3_WITH_ID;
    l3_egress.fec_id = cint_vpls_roo_basic_info.access_fec_id;
    if(*dnxc_data_get(unit, "l3", "feature", "separate_fwd_rpf_dbs", NULL))
    {
        l3_egress.l3_flags2 |= BCM_L3_FLAGS2_FWD_ONLY;
    }
    BCM_IF_ERROR_RETURN_MSG(dnx_utils_l3_egress_create(unit, &l3_egress), "in creating FEC routing out of overlay");

    return BCM_E_NONE;
}

int
vpls_roo_basic_create_mpls_tunnel(
    int unit,
    bcm_mpls_label_t outer_label,
    bcm_mpls_label_t inner_label,
    int num_labels,
    int arp_id,
    bcm_if_t * tunnel_id)
{

    bcm_mpls_egress_label_t label_array[2];

    bcm_mpls_egress_label_t_init(&label_array[0]);
    bcm_mpls_egress_label_t_init(&label_array[1]);

    /*
     * Label to be pushed as part of the MPLS tunnel.
     */
    label_array[0].label = outer_label;
    label_array[0].flags = BCM_MPLS_EGRESS_LABEL_WITH_ID | BCM_MPLS_EGRESS_LABEL_TTL_DECREMENT;
    BCM_L3_ITF_SET(label_array[0].tunnel_id, BCM_L3_ITF_TYPE_LIF, *tunnel_id);
    if (num_labels == 2)
    {
        label_array[1].label = inner_label;
        label_array[1].flags = BCM_MPLS_EGRESS_LABEL_WITH_ID | BCM_MPLS_EGRESS_LABEL_TTL_DECREMENT;
        BCM_L3_ITF_SET(label_array[1].tunnel_id, BCM_L3_ITF_TYPE_LIF, *tunnel_id);
    }
    /*
     * Set the next pointer of this entry to be the arp. This configuration is new compared to Jericho, where the arp
     * pointer used to be connected to the EEDB entry via bcm_l3_egress_create (with egress flag indication).
     */
    label_array[0].l3_intf_id = arp_id;

    BCM_IF_ERROR_RETURN_MSG(bcm_mpls_tunnel_initiator_create(unit, 0, num_labels, label_array), "");

    *tunnel_id = label_array[0].tunnel_id;

    return BCM_E_NONE;

}

int
vpls_roo_basic_create_termination_stack(
    int unit,
    bcm_mpls_label_t * labels,
    int nof_labels)
{
    bcm_mpls_tunnel_switch_t entry;
    int i;
    /*
     * Create a stack of MPLS labels to be terminated 
     */

    for (i = 0; i < nof_labels; i++)
    {
        bcm_mpls_tunnel_switch_t_init(&entry);

        entry.action = BCM_MPLS_SWITCH_ACTION_POP;
        entry.class_id = cint_vpls_roo_basic_info.vmpi;
        /*
         * incoming label
         * only the mpls tunnel label needs to be defined here.
         * pwe label will be handed as part of the ingress mpls_port_add api
         */
        entry.label = labels[i];

        BCM_IF_ERROR_RETURN_MSG(bcm_mpls_tunnel_switch_create(unit, &entry), "");
    }

    return BCM_E_NONE;

}

int
vpls_roo_basic_l3_forwarding(
    int unit)
{

    /*
     * Add Route entry for access to core traffic
     */

    BCM_IF_ERROR_RETURN_MSG(add_route_ipv4(unit, cint_vpls_roo_basic_info.dip1, 0xffffffff, 0,
                        cint_vpls_roo_basic_info.core_native_fec_id), "");

    /*
     * Add Route entry for core to access traffic
     */

    BCM_IF_ERROR_RETURN_MSG(add_route_ipv4(unit, cint_vpls_roo_basic_info.dip2, 0xffffffff, 0, cint_vpls_roo_basic_info.access_fec_id), "");

    return BCM_E_NONE;
}

int
vpls_roo_basic_mpls_port_add_encapsulation(
    int unit)
{
    char error_msg[200]={0,};
    bcm_mpls_port_t mpls_port;
    bcm_gport_t gport_id;
    int egr_qos_map_id;

    bcm_mpls_port_t_init(&mpls_port);
    mpls_port.flags2 |= BCM_MPLS_PORT2_EGRESS_ONLY;
    mpls_port.flags |= BCM_MPLS_PORT_EGRESS_TUNNEL;

    mpls_port.egress_label.label = cint_vpls_roo_basic_info.core_overlay_pwe_label;
    mpls_port.egress_label.ttl = cint_vpls_roo_basic_info.ttl;
    mpls_port.egress_label.flags = BCM_MPLS_EGRESS_LABEL_TTL_DECREMENT;
    mpls_port.egress_label.egress_qos_model.egress_qos = bcmQosEgressModelUniform;
    mpls_port.egress_label.egress_qos_model.egress_ttl = bcmQosEgressModelPipeMyNameSpace;

    BCM_IF_ERROR_RETURN_MSG(bcm_mpls_port_add(unit, 0, mpls_port), "");

    cint_vpls_roo_basic_info.core_overlay_mpls_port_id_eg = mpls_port.mpls_port_id;
    cint_vpls_roo_basic_info.core_overlay_pwe_encap_id = mpls_port.encap_id;

    BCM_IF_ERROR_RETURN_MSG(bcm_qos_map_id_get_by_profile(unit, BCM_QOS_MAP_EGRESS | BCM_QOS_MAP_REMARK,
                                       cint_vpls_roo_basic_info.egr_qos_map_id, &egr_qos_map_id), "");

    snprintf(error_msg, sizeof(error_msg), "setting up egress gport(0x%08x) to map", cint_vpls_roo_basic_info.core_overlay_mpls_port_id_eg);
    BCM_IF_ERROR_RETURN_MSG(bcm_qos_port_map_set(unit, cint_vpls_roo_basic_info.core_overlay_mpls_port_id_eg, -1, egr_qos_map_id), error_msg);

    return BCM_E_NONE;
}

int
vpls_roo_basic_mpls_port_add_termination(
    int unit,
    bcm_vpn_t vpn)
{
    bcm_mpls_port_t mpls_port;
    bcm_gport_t gport_id;

    bcm_mpls_port_t_init(&mpls_port);
    mpls_port.flags2 |= BCM_MPLS_PORT2_INGRESS_ONLY;
    mpls_port.flags2 |= (vpn ? 0 : BCM_MPLS_PORT2_CROSS_CONNECT);
    mpls_port.flags2 |= BCM_MPLS_PORT2_PLATFORM_NAMESPACE;
    mpls_port.flags |= BCM_MPLS_PORT_EGRESS_TUNNEL;
    mpls_port.class_id = cint_vpls_roo_basic_info.vmpi;
    /*
     * encap_id is the egress outlif - used for learning 
     */
    mpls_port.encap_id = cint_vpls_roo_basic_info.core_overlay_pwe_encap_id;
    mpls_port.criteria = BCM_MPLS_PORT_MATCH_LABEL;
    mpls_port.match_label = cint_vpls_roo_basic_info.core_overlay_pwe_label;
    /** connect PWE entry to created MPLS encapsulation entry for learning */
    BCM_L3_ITF_SET(mpls_port.egress_tunnel_if, BCM_L3_ITF_TYPE_FEC, cint_vpls_roo_basic_info.core_overlay_fec_id);

    BCM_IF_ERROR_RETURN_MSG(bcm_mpls_port_add(unit, vpn, mpls_port), "termination");

    cint_vpls_roo_basic_info.core_overlay_mpls_port_id_ing = mpls_port.mpls_port_id;

    return BCM_E_NONE;
}

int
vpls_roo_basic_vswitch_add_core_outer_ac(
    int unit,
    bcm_gport_t port)
{
    bcm_vlan_port_t vlan_port;
    int is_two_dev = 0;
    /*
     * add port, according to port_vlan_vlan 
     */
    bcm_vlan_port_t_init(&vlan_port);

    /*
     * set port attribures, key <port-vlan-vlan>
     */
    vlan_port.port = port;
    vlan_port.flags = BCM_VLAN_PORT_CREATE_EGRESS_ONLY | BCM_VLAN_PORT_VLAN_TRANSLATION;
    vlan_port.criteria = BCM_VLAN_PORT_MATCH_PORT_VLAN;
    /*
     * For some reason, VSI is in match_vlan 
     */
    vlan_port.match_vlan = cint_vpls_roo_basic_info.core_eth_rif;

    BCM_IF_ERROR_RETURN_MSG(bcm_vlan_port_create(unit, &vlan_port), "");
    cint_vpls_roo_basic_info.outer_ac_vlan_port_id = vlan_port.vlan_port_id;

    printf("outer_ac_vlan_port_id: 0x%08x\n", cint_vpls_roo_basic_info.outer_ac_vlan_port_id);

    return BCM_E_NONE;
}

int
vpls_roo_basic_eve_swap(
    int unit,
    int port)
{
    int action_id_1;
    char error_msg[200]={0,};
    bcm_vlan_action_set_t action;
    bcm_port_tpid_class_t port_tpid_class;
    bcm_vlan_translate_action_class_t action_class;
    /*
     * set tag format for untagged packets 
     */
    bcm_port_tpid_class_t_init(&port_tpid_class);
    port_tpid_class.port = port;
    port_tpid_class.tpid1 = cint_vpls_roo_basic_info.outer_tpid;
    port_tpid_class.tpid2 = cint_vpls_roo_basic_info.inner_tpid;
    port_tpid_class.tag_format_class_id = cint_vpls_roo_basic_info.tag_format;
    port_tpid_class.flags = BCM_PORT_TPID_CLASS_EGRESS_ONLY;
    port_tpid_class.vlan_translation_action_id = 0;
    snprintf(error_msg, sizeof(error_msg), "port=%d", port);
    BCM_IF_ERROR_RETURN_MSG(bcm_port_tpid_class_set(unit, &port_tpid_class), error_msg);

    /*
     * Create action ID
     */
    BCM_IF_ERROR_RETURN_MSG(bcm_vlan_translate_action_id_create(unit, BCM_VLAN_ACTION_SET_EGRESS, &action_id_1), "");

    /*
     * Set translation action 
     */
    bcm_vlan_action_set_t_init(&action);
    action.outer_tpid = cint_vpls_roo_basic_info.outer_tpid;
    action.inner_tpid = cint_vpls_roo_basic_info.inner_tpid;
    action.dt_outer = bcmVlanActionDelete;
    action.dt_inner = bcmVlanActionDelete;
    BCM_IF_ERROR_RETURN_MSG(bcm_vlan_translate_action_id_set(unit, BCM_VLAN_ACTION_SET_EGRESS, action_id_1, &action), "");

    /*
     * Set translation action class (map edit_profile & tag_format to action_id) 
     */
    bcm_vlan_translate_action_class_t_init(&action_class);
    action_class.vlan_edit_class_id = cint_vpls_roo_basic_info.egress_vlan_edit_profile;
    action_class.tag_format_class_id = cint_vpls_roo_basic_info.tag_format;
    action_class.vlan_translation_action_id = action_id_1;
    action_class.flags = BCM_VLAN_ACTION_SET_INGRESS;
    BCM_IF_ERROR_RETURN_MSG(bcm_vlan_translate_action_class_set(unit, &action_class), "");

    return BCM_E_NONE;

}

/*
 * Main function for basic mpls vpls scenario.
 */
int
vpls_roo_basic_main(
    int unit,
    int access_port,
    int core_port)
{
    int nof_labels = 2;

    BCM_IF_ERROR_RETURN_MSG(vpls_roo_basic_init(unit,access_port, core_port), "");
    /*
     * Configure AC and PWE ports
     */
    BCM_IF_ERROR_RETURN_MSG(vpls_roo_basic_configure_port_properties(unit, cint_vpls_roo_basic_info.access_port,
                                                  cint_vpls_roo_basic_info.core_port), "");

    BCM_IF_ERROR_RETURN_MSG(vpls_roo_basic_create_eth_rifs(unit), "");

    /*
     * Configure L3 interfaces 
     */
    BCM_IF_ERROR_RETURN_MSG(vpls_roo_basic_create_l3_interfaces(unit), "");

    /*
     * Configure an ARP entries
     */
    BCM_IF_ERROR_RETURN_MSG(vpls_roo_basic_create_arp_entries(unit), "");

    /*
     * Configure a push entry.
     */
    BCM_IF_ERROR_RETURN_MSG(vpls_roo_basic_create_mpls_tunnel(unit,
                                           cint_vpls_roo_basic_info.core_overlay_mpls_tunnel_label_1,
                                           cint_vpls_roo_basic_info.core_overlay_mpls_tunnel_label_2,
                                           1, cint_vpls_roo_basic_info.core_overlay_arp_id,
                                           &cint_vpls_roo_basic_info.core_overlay_mpls_tunnel_id), "");

    /*
     * configure PWE tunnel - egress flow 
     */
    BCM_IF_ERROR_RETURN_MSG(vpls_roo_basic_mpls_port_add_encapsulation(unit), "");

    /*
     * Configure fec entry 
     */
    BCM_IF_ERROR_RETURN_MSG(vpls_roo_basic_create_fec_entries(unit), "");

    /*
     * Configure a termination label for the ingress flow  
     */
    bcm_mpls_label_t label_array[2];
    label_array[0] = cint_vpls_roo_basic_info.core_overlay_mpls_tunnel_label_1;
    label_array[1] = cint_vpls_roo_basic_info.core_overlay_mpls_tunnel_label_2;
    BCM_IF_ERROR_RETURN_MSG(vpls_roo_basic_create_termination_stack(unit, label_array, 2), "");

    /*
     * configure PWE tunnel - ingress flow 
     */
    BCM_IF_ERROR_RETURN_MSG(vpls_roo_basic_mpls_port_add_termination(unit, cint_vpls_roo_basic_info.core_native_eth_rif), "");

    /*
     * add l2 addresses to be defined as static - no learning needed
     */
    BCM_IF_ERROR_RETURN_MSG(vpls_roo_basic_l3_forwarding(unit), "");

    BCM_IF_ERROR_RETURN_MSG(vpls_roo_basic_eve_swap(unit, cint_vpls_roo_basic_info.core_port), "");

    return BCM_E_NONE;
}
