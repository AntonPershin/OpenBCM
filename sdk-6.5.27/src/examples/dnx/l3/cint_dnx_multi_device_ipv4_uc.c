/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Multi-Dev IPv4 UC~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/* 
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2022 Broadcom Inc. All rights reserved.
 *
 * File: cint_dnx_multi_device_ipv4_uc.c
 * Purpose: Demo IPv4 UC under multi device system
 *
 * Multi-Device system require the ingress/egress configuration separately and relatively.
 * This cint demo how to configurer the IPv4 service under multi-device system.
 *  1. Create ARP and out-RIF configuration on egress device
 *  2. Create In-RIF and Forward configuration on ingress device
 *  3. Send IPv4 packet to verify the result

 * Example:
 * Test Scenario
 *
 * Test Scenario - start
  cint ../../../../src/examples/dnx/utility/cint_dnx_utils_global.c
  cint ../../../../src/examples/dnx/field/cint_field_utils.c
  cint ../../../../src/examples/dnx/utility/cint_dnx_utils_global.c
  cint ../../../../src/examples/dnx/utility/cint_dnx_utils_l3.c
  cint ../../../../src/examples/dnx/utility/cint_dnx_utils_mpls.c
  cint ../../../../src/examples/sand/cint_ip_route_basic.c
  cint ../../../../src/examples/dnx/l3/cint_dnx_multi_device_ipv4_uc.c
  cint ../../../../src/examples/dpp/internal/systems/cint_utils_jr2-comp-jr1-mode.c
  cint
  initialize_required_system_tools(0);
 * cint_ipv4_route_info.mode=0/1/2;
  cint_ipv4_route_info.mode=0;
  muti_dev_ipv4_uc_example(0,0,1811939531,1811939530);
  exit;
 * Send packets on unit 1 should be:
  tx 1 psrc=203 data=0x0000000000110000000000008100706408004500004c00000000403dfb71000000007fffff04000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f202122232425262728292a2b2c2d2e2f303132333435363738393a3b00000000
 *
 * Received packets on unit 2 should be:
 *  Data: 0x00000022000000000011810000c808004500004c000000003f3dfc71000000007fffff04000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f202122232425262728292a2b2c2d2e2f303132333435363738393a3b000000000000
 * Test Scenario - end
 */


 struct cint_multi_dev_ipv4_route_info_s
{
    int in_rif;                             /* access RIF */
    int out_rif;                            /* out RIF */
    int vrf;                                /*  VRF */
    bcm_mac_t my_mac;                       /* mac for Incoming L3 intf */
    bcm_mac_t next_hop_mac;                 /* next hop mac for outgoing station */
    bcm_ip_t dip;                           /* dip */

    int arp_encap_id;                       /*Next hop intf ID*/
    int level1_fec_id;                      /*FEC ID for routing into IP*/

    /*
     * FEC usage
     * 0:1 level FEC with OutRIF+ARP+Dest (Format A)
     * 1:1 level FEC with Out-LIF+Dest (Format B)
     * 2:1 level FEC with EEI+Dest (Format C)
     */
    int mode;
    int in_local_port;
    int out_local_port;
    int mtu;

};


 cint_multi_dev_ipv4_route_info_s cint_ipv4_route_info=
{
    /*
    * In-RIF,
    */
    100,
    /*
    * Out-RIF,
    */
    200,

    /*
    * vrf,
    */
    1,
    /*
    * my_mac | next_hop_mac
    */
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x11},
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x22},

    /*
    * dip
    */
    0x7FFFFF04, /* 127.255.255.4 */

};

/**
 * Convert system port to local port
*/

int
multi_dev_system_port_to_local(int unit, int sysport, int *local_port){

    BCM_IF_ERROR_RETURN_MSG(bcm_port_local_get(unit, sysport, local_port), "fail core_port");

    return BCM_E_NONE;
}


/**
 * Main entrance for mpls check ver configuration
 * INPUT:
 *   ingress_unit- traffic incoming unit
 *   egress_unit- traffic ougtoing unit
 *   in_sys_port- traffic incoming port
 *   out_sys_port- traffic outgoing port
*/
 int
 multi_dev_ipv4_uc_init(
    int ingress_unit,
    int egress_unit,
    int in_sys_port,
    int out_sys_port)
{
    int local_port,is_local;
    int egress_trunk_id;
    int egress_trunk_group;
    int egress_trunk_pool;

    /*
     * 0: Convert the sysport to local port
     */

    if (!BCM_GPORT_IS_TRUNK(in_sys_port)) {
        multi_dev_system_port_to_local(ingress_unit,in_sys_port,&cint_ipv4_route_info.in_local_port);
        multi_dev_system_port_to_local(egress_unit,out_sys_port,&cint_ipv4_route_info.out_local_port);
    } else {
        cint_ipv4_route_info.in_local_port = in_sys_port;
        BCM_TRUNK_ID_GROUP_GET(egress_trunk_group,out_sys_port);
        if (is_device_or_above(egress_unit, JERICHO2)) {
            BCM_TRUNK_ID_POOL_GET(egress_trunk_pool,out_sys_port);
            BCM_TRUNK_ID_SET(egress_trunk_id, egress_trunk_pool, egress_trunk_group);
            BCM_GPORT_TRUNK_SET(cint_ipv4_route_info.out_local_port, egress_trunk_id);
        } else {
            BCM_GPORT_TRUNK_SET(cint_ipv4_route_info.out_local_port, egress_trunk_group);
        }
    }

    /*
     * 1.EncapID, use the minimal valid
     *   global Out-LIF for JR and JR2
     */
    BCM_L3_ITF_SET(cint_ipv4_route_info.arp_encap_id,BCM_L3_ITF_TYPE_LIF, 0x4000);

    /*
     *2.FEC ID
     */
    if (is_device_or_above(ingress_unit, JERICHO2)) {
        int fec_id;
        BCM_IF_ERROR_RETURN_MSG(get_first_fec_in_range_which_not_in_ecmp_range(ingress_unit, 0, &fec_id), "");
        BCM_L3_ITF_SET(cint_ipv4_route_info.level1_fec_id, BCM_L3_ITF_TYPE_FEC, fec_id);
    } else {
        BCM_L3_ITF_SET(cint_ipv4_route_info.level1_fec_id, BCM_L3_ITF_TYPE_FEC, 0x1000);
    }

    return BCM_E_NONE;
}


/**
 * port init
 * INPUT:
 *   in_port    - traffic incoming port
*/
 int
 multi_dev_ingress_port_configuration(
    int unit,
    int in_port,
    int in_rif)
{

    BCM_IF_ERROR_RETURN_MSG(in_port_intf_set(unit, in_port, in_rif), "");
    return BCM_E_NONE;

}

/**
 * port egress init
 * INPUT:
 *   out_port - traffic outgoing port
*/
 int
 multi_dev_egress_port_configuration(
    int unit,
    int out_port)
{
    char error_msg[200]={0,};

    /*
     * 1. Set Out-Port default properties, in case of ARP+AC no need
     */
    snprintf(error_msg, sizeof(error_msg), "intf_out out_port %d", out_port);
    BCM_IF_ERROR_RETURN_MSG(out_port_set(unit, out_port), error_msg);
    return BCM_E_NONE;

}


/**
 * L3 intf init
 * INPUT:
 *   in_port    - traffic incoming port
*/
 int
 multi_dev_ipv4_uc_l3_intf_configuration(
    int unit,
    int in_port)
{
    int rv;
    bcm_l3_intf_t l3_intf;
    dnx_utils_l3_eth_rif_s eth_rif_structure;

    bcm_l3_intf_t_init(&l3_intf);
    l3_intf.l3a_intf_id = cint_ipv4_route_info.in_rif;
    rv = bcm_l3_intf_get(unit,&l3_intf);
    if (rv != BCM_E_NONE) {
        dnx_utils_l3_eth_rif_s_common_init(unit, 0, &eth_rif_structure, cint_ipv4_route_info.in_rif, 0, 0, cint_ipv4_route_info.my_mac, cint_ipv4_route_info.vrf);
        BCM_IF_ERROR_RETURN_MSG(dnx_utils_l3_eth_rif_create(unit, &eth_rif_structure), "core_native_eth_rif");
    }

    bcm_l3_intf_t_init(&l3_intf);
    l3_intf.l3a_intf_id = cint_ipv4_route_info.out_rif;
    rv = bcm_l3_intf_get(unit,&l3_intf);
    if (rv != BCM_E_NONE) {
        dnx_utils_l3_eth_rif_s_common_init(unit, 0, &eth_rif_structure, cint_ipv4_route_info.out_rif, 0, 0, cint_ipv4_route_info.my_mac, cint_ipv4_route_info.vrf);
        BCM_IF_ERROR_RETURN_MSG(dnx_utils_l3_eth_rif_create(unit, &eth_rif_structure), "core_native_eth_rif");

    }

    return BCM_E_NONE;
}

/**
 * ARP adding
 * INPUT:
 *   in_port    - traffic incoming port
 *   out_port - traffic outgoing port
*/
 int
 multi_dev_ipv4_uc_arp_configuration(
    int unit,
    int out_port)
{

    dnx_utils_l3_arp_s arp_structure;

    /*
     * Configure native ARP entry
     */
    if (cint_ipv4_route_info.mtu)
    {
        /*
         * For JR2, set l3eg.mtu as none-zero, so the result type of eedb_arp has mtu_profile field
         */
        dnx_utils_l3_arp_s_common_init(unit, 0, &arp_structure, cint_ipv4_route_info.arp_encap_id, 0, 0 , cint_ipv4_route_info.next_hop_mac, cint_ipv4_route_info.out_rif);
        arp_structure.mtu = cint_ipv4_route_info.mtu;
    }
    else
    {
        dnx_utils_l3_arp_s_common_init(unit, 0, &arp_structure, cint_ipv4_route_info.arp_encap_id, 0, BCM_L3_FLAGS2_VLAN_TRANSLATION , cint_ipv4_route_info.next_hop_mac, cint_ipv4_route_info.out_rif);
    }
    BCM_IF_ERROR_RETURN_MSG(dnx_utils_l3_arp_create(unit, &arp_structure), "create AC egress object ARP only");

    return BCM_E_NONE;
}


/**
 * FEC entry adding
 * INPUT:
 *   in_port    - traffic incoming port
 *   out_sys_port - traffic outgoing port
*/
 int
 multi_dev_ipv4_uc_fec_entry_configuration(
    int unit,
    int in_port,
    int out_sys_port)
{
    dnx_utils_l3_fec_s fec_structure;


    dnx_utils_l3_fec_s_init(unit, 0x0, &fec_structure);
    fec_structure.destination = out_sys_port;

    switch (cint_ipv4_route_info.mode)
    {
        case 0:
            fec_structure.tunnel_gport = cint_ipv4_route_info.out_rif;
            fec_structure.tunnel_gport2 = cint_ipv4_route_info.arp_encap_id;
        break;

        case 1:
            fec_structure.tunnel_gport = cint_ipv4_route_info.arp_encap_id;
        break;

        case 2:
            fec_structure.tunnel_gport = cint_ipv4_route_info.arp_encap_id;
            fec_structure.flags= BCM_L3_ENCAP_SPACE_OPTIMIZED;
        break;
    }

    fec_structure.fec_id = cint_ipv4_route_info.level1_fec_id;
    fec_structure.allocation_flags = BCM_L3_WITH_ID;

    BCM_IF_ERROR_RETURN_MSG(dnx_utils_l3_fec_create(unit, &fec_structure), "create egress object FEC only");

    return BCM_E_NONE;
}

/**
 * forward entry adding(ILM, IPv4 Route)
 * INPUT:
 *   unit    - traffic incoming unit
*/
 int
 multi_dev_ipv4_uc_forward_entry_configuration(
    int unit)
{
    BCM_IF_ERROR_RETURN_MSG(add_host_ipv4(unit, cint_ipv4_route_info.dip, cint_ipv4_route_info.vrf, cint_ipv4_route_info.level1_fec_id, 0, 0), "");

    return BCM_E_NONE;
}


/**
 * ingress side configuration
 * INPUT:
 *   in_port    - traffic incoming port
 *   out_sys_port - traffic outgoing port
*/
 int
 multi_dev_ipv4_uc_ingress_configuration(
    int ingress_unit,
    int in_port,
    int out_sys_port)
{

    BCM_IF_ERROR_RETURN_MSG(multi_dev_ingress_port_configuration(ingress_unit,in_port, cint_ipv4_route_info.in_rif), "");

    BCM_IF_ERROR_RETURN_MSG(multi_dev_ipv4_uc_l3_intf_configuration(ingress_unit,in_port), "");

    BCM_IF_ERROR_RETURN_MSG(multi_dev_ipv4_uc_fec_entry_configuration(ingress_unit,in_port,out_sys_port), "");

    BCM_IF_ERROR_RETURN_MSG(multi_dev_ipv4_uc_forward_entry_configuration(ingress_unit), "");

    return BCM_E_NONE;
}

/**
 * egress side configuration
 * INPUT:
 *   out_port - traffic outgoing port
*/
 int
 multi_dev_ipv4_uc_egress_configuration(
    int egress_unit,
    int out_port)
{

    BCM_IF_ERROR_RETURN_MSG(multi_dev_egress_port_configuration(egress_unit,out_port), "");

    BCM_IF_ERROR_RETURN_MSG(multi_dev_ipv4_uc_l3_intf_configuration(egress_unit,out_port), "");

    BCM_IF_ERROR_RETURN_MSG(multi_dev_ipv4_uc_arp_configuration(egress_unit,out_port), "");

    return BCM_E_NONE;
}



/**
 * Main entrance for IPv4 UC on multi-device
 * INPUT:
 *   in_sys_port    - traffic incoming port
 *   out_sys_port - traffic outgoing port
*/
 int
 multi_dev_ipv4_uc_example(
    int ingress_unit,
    int egress_unit,
    int in_sys_port,
    int out_sys_port)
{

    BCM_IF_ERROR_RETURN_MSG(multi_dev_ipv4_uc_init(ingress_unit,egress_unit,in_sys_port,out_sys_port), "");


    BCM_IF_ERROR_RETURN_MSG(multi_dev_ipv4_uc_ingress_configuration(ingress_unit,cint_ipv4_route_info.in_local_port,out_sys_port), "");

    BCM_IF_ERROR_RETURN_MSG(multi_dev_ipv4_uc_egress_configuration(egress_unit,cint_ipv4_route_info.out_local_port), "");
    return BCM_E_NONE;
}


