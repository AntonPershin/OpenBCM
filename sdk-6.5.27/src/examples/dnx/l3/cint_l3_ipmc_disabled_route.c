/*
 * $Id: cint_l3_ipmc_disabled_route.c
 * Exp $
 This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 
 Copyright 2007-2022 Broadcom Inc. All rights reserved.
 */
/*
 *
 * Test Scenario - start
  cint ../../../../src/examples/sand/cint_ip_route_basic.c
  cint ../../../../src/examples/sand/cint_ipmc_route_basic.c
  cint ../../../../src/examples/dnx/l3/cint_l3_ipmc_disabled_route.c
  cint
  cint_ipmc_disabled_switch_l3mcastl2(0,200,201,202,203);
  exit;
 *
 * ETH-RIF packet
  tx 1 psrc = 200 data = 0x01005e020202000007000100810000960800450000350000000080009743c0800101e0020202000102030405060708090a0b0c0d0e0f
 * Received packets on unit 0 should be:
 * Data:
 * 0x01005e020202000007000100810000960800450000350000000080009743c0800101e0020202000102030405060708090a0b0c0d0e0f
 * 0x01005e020202000007000100810000960800450000350000000080009743c0800101e0020202000102030405060708090a0b0c0d0e0f
 * Test Scenario - end
 */
int l2_mc_group;
/******* Run example ******/

/*
 * packets will be routed from in_port to out-port1 and out-port2 after L2 MC group is hit
 *
 * Route:
 * packet to send:
 *  - in port = in_port
 *  - Vlan ID = 150
 *  - DA = 01:00:5E:02:02:02
 *  - DIP = 0xE0020202
 * expected:
 *  - out port = out_port1, outport2
 *  - vlan = 150
 *  - DA = input DA
 *  - SA = input SA
 *  TTL decremented
 *
 */
int
cint_ipmc_disabled_switch_l3mcastl2(
    int unit,
    int in_port,
    int in_port2,
    int out_port1,
    int out_port2)
{
    int intf_in = 150;
    int out_rifs[4] = {50, 51, 52, 53};

    bcm_ip_t mask = 0xFFFFFFFF;
    bcm_mac_t intf_in_mac_address = { 0x00, 0x0c, 0x00, 0x02, 0x00, 0x00 };     /* my-MAC */
    bcm_mac_t intf_out_mac_address = { 0x00, 0x12, 0x34, 0x56, 0x78, 0x9a };    /* my-MAC */
    bcm_mac_t arp_next_hop_mac = { 0x00, 0x00, 0x00, 0x00, 0xcd, 0x1d };        /* next_hop_mac */
    int idx;
    int flags;
    bcm_vlan_port_t vlan_port;
    int out_lifs[2];
    bcm_gport_t gport;
    
    bcm_vlan_port_t_init(&vlan_port);
    bcm_multicast_replication_t replications[cint_ipmc_info.nof_replications];

    cint_ipmc_info.out_ports[0] = out_port1;
    cint_ipmc_info.out_ports[1] = out_port2;
    l3_ingress_intf ingress_rif;
    l3_ingress_intf_init(&ingress_rif);
    cint_ipmc_info.intf_in = intf_in;
    l2_mc_group = 0x1111;
    /*
     * 1. Set In-Port to In ETh-RIF
     */
    BCM_IF_ERROR_RETURN_MSG(in_port_intf_set(unit, in_port, intf_in), "intf_in");
    BCM_IF_ERROR_RETURN_MSG(in_port_intf_set(unit, in_port2, intf_in+1), "intf_in");

    BCM_IF_ERROR_RETURN_MSG(bcm_switch_control_set(unit, bcmSwitchL3McastL2, 1), "");

    BCM_IF_ERROR_RETURN_MSG(intf_eth_rif_create(unit, intf_in, intf_in_mac_address), "intf_in");
    ingress_rif.intf_id = intf_in;
    ingress_rif.vrf = intf_in;
    ingress_rif.flags = BCM_L3_INGRESS_ROUTE_DISABLE_IP4_MCAST | BCM_L3_INGRESS_ROUTE_DISABLE_IP6_MCAST | BCM_L3_INGRESS_L3_MCAST_L2;
    BCM_IF_ERROR_RETURN_MSG(intf_ingress_rif_set(unit, &ingress_rif), "intf_out");
    for (idx = 0; idx < 4; idx++)
    {
        BCM_IF_ERROR_RETURN_MSG(intf_eth_rif_create(unit, out_rifs[idx], intf_out_mac_address), "intf_in");
        intf_out_mac_address[5] ++;
    }

    /*
     * Create multicast replications
     */
    BCM_GPORT_SYSTEM_PORT_ID_SET(gport, cint_ipmc_info.out_ports[0]);
    set_multicast_replication(&replications[0], gport, -1);
    BCM_GPORT_SYSTEM_PORT_ID_SET(gport, cint_ipmc_info.out_ports[1]);
    set_multicast_replication(&replications[1], gport, -1);

    /*
     * Create a multicast group
     */
    if (*dnxc_data_get(unit, "multicast", "params", "mcdb_formats_v2", NULL)) {
        flags = BCM_MULTICAST_INGRESS_GROUP | BCM_MULTICAST_ELEMENT_STATIC;
    } else {
        flags = BCM_MULTICAST_INGRESS_GROUP;
    }
    BCM_IF_ERROR_RETURN_MSG(bcm_multicast_create(unit, (flags | BCM_MULTICAST_WITH_ID), &l2_mc_group), "");
    BCM_IF_ERROR_RETURN_MSG(bcm_multicast_add(unit, l2_mc_group, flags, 2, replications), "");

    BCM_IF_ERROR_RETURN_MSG(add_ipv4_ipmc_bridge(unit, cint_ipmc_info.mc_dip, mask, 0, 0, intf_in, 0, l2_mc_group, 0, 0), "");
    
    l2_mc_group++;
    /*
     * Create multicast replications
     */
    BCM_GPORT_SYSTEM_PORT_ID_SET(gport, cint_ipmc_info.out_ports[0]);
    set_multicast_replication(&replications[0], gport, -1);
    BCM_GPORT_SYSTEM_PORT_ID_SET(gport, cint_ipmc_info.out_ports[1]);
    set_multicast_replication(&replications[1], gport, -1);

    /*
     * Create a multicast group
     */
    if (*dnxc_data_get(unit, "multicast", "params", "mcdb_formats_v2", NULL)) {
        flags = BCM_MULTICAST_INGRESS_GROUP | BCM_MULTICAST_ELEMENT_STATIC;
    } else {
        flags = BCM_MULTICAST_INGRESS_GROUP;
    }
    BCM_IF_ERROR_RETURN_MSG(bcm_multicast_create(unit, (flags | BCM_MULTICAST_WITH_ID), &l2_mc_group), "");
    BCM_IF_ERROR_RETURN_MSG(bcm_multicast_add(unit, l2_mc_group, flags, 2, replications), "");
    
    bcm_l2_addr_t l2_addr;
    bcm_mac_t mc_mac = {0x01, 0, 0x5E, 0x2, 0x2, 0x2};
    bcm_l2_addr_t_init(&l2_addr, mc_mac, intf_in + 1);
    l2_addr.flags = BCM_L2_STATIC | BCM_L2_MCAST;
    l2_addr.l2mc_group = l2_mc_group;
    BCM_IF_ERROR_RETURN_MSG(bcm_l2_addr_add(unit, &l2_addr), "");

    return BCM_E_NONE;
}

/**
 * Helper function that flips the switch bcmSwitchL3McastL2 to 0 and creates a new RIF with ID 151.
 */
int cint_ipmc_disabled_switch_additional(
    int unit)
{
    int intf_in = 151;
    bcm_mac_t intf_in_mac_address = { 0x00, 0x0c, 0x00, 0x02, 0x00, 0x00 };     /* my-MAC */
    l3_ingress_intf ingress_rif;
    l3_ingress_intf_init(&ingress_rif);
    
    BCM_IF_ERROR_RETURN_MSG(bcm_switch_control_set(unit, bcmSwitchL3McastL2, 0), "");
    
    BCM_IF_ERROR_RETURN_MSG(intf_eth_rif_create(unit, intf_in, intf_in_mac_address), "intf_in");
    ingress_rif.intf_id = intf_in;
    ingress_rif.vrf = intf_in;
    ingress_rif.flags = BCM_L3_INGRESS_ROUTE_DISABLE_IP4_MCAST | BCM_L3_INGRESS_ROUTE_DISABLE_IP6_MCAST;
    BCM_IF_ERROR_RETURN_MSG(intf_ingress_rif_set(unit, &ingress_rif), "intf_out");


    return BCM_E_NONE;
}


/*
 * packets will be routed from in_port1 and in_port2 to out-port1 and out-port2 after MC group is hit
 * Two RIFs are configured - one will use the BCM_L3_INGRESS_L3_MCAST_L2 flag, the other BCM_L3_INGRESS_IP6_L3_MCAST_L2 flag.
 * IPv4 MC bridge:
 * packet to send:
 *  - in port = in_port1
 *  - Vlan ID = eth_rif1
 *  - DA = 01:00:5E:02:02:02
 *  - DIP = 0xE0020202
 * expected:
 *  - out port = out_port1, outport2
 *  - vlan = 150
 *  - DA = input DA
 *  - SA = input SA
 *  TTL decremented
 *
 * IPv4 MC MAC bridge (L2 fwd):
 * packet to send:
 *  - in port = in_port2
 *  - Vlan ID = eth_rif2
 *  - DA = 01:00:5E:02:02:02
 *  - DIP = 0xE0020202
 * expected:
 *  - out port = out_port1, outport2
 *  - vlan = 150
 *  - DA = input DA
 *  - SA = input SA
 *
 * IPv6 MC MAC bridge (L2 fwd):
 * packet to send:
 *  - in port = in_port1
 *  - Vlan ID = eth_rif1
 *  - DA = 33:33:00:34:56:78
 *  - DIP = FFFF:0000:0000:0000:0000:0000:1234:5678
 * expected:
 *  - out port = out_port1, outport2
 *  - vlan = 150
 *  - DA = input DA
 *  - SA = input SA
 *
 * IPv6 MC bridge:
 * packet to send:
 *  - in port = in_port2
 *  - Vlan ID = eth_rif2
 *  - DA = 33:33:00:34:56:78
 *  - DIP = FFFF:0000:0000:0000:0000:0000:1234:5678
 * expected:
 *  - out port = out_port1, outport2
 *  - vlan = 150
 *  - DA = input DA
 *  - SA = input SA
 */
int
cint_ipmc_l3_mcast_l2_example(
    int unit,
    int eth_rif1,
    int eth_rif2,
    int in_port1,
    int in_port2,
    int out_port1,
    int out_port2)
{
    char error_msg[200]={0,};
    int idx;
    int vrf = 1;
    int ipmc_group[4] = {0x1000, 0x1001, 0x1002, 0x1003};
    int intf_out = 150;
    int c_sip = 0x456;
    int nof_mc_groups = 2;
    uint32 sip_addr = 0xC0800101;
    uint32 sip_mask = 0xFFFF0000;
    uint32 dip_addr = 0xE0020202;
    uint32 dip_mask = 0xFFFFFFFF;
    bcm_ip6_t dip_v6_addr = {0xFF, 0xFF, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x12, 0x34, 0x56, 0x78};
    bcm_ip6_t dip_v6_mask = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
    bcm_ip6_t sip_v6_addr = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11};
    bcm_ip6_t sip_v6_mask = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0, 0};
    int out_ports[2] = {out_port1, out_port2};
    int in_ports[2] = {in_port1, in_port2};
    uint32 flags;
    bcm_multicast_replication_t replications[cint_ipmc_info.nof_replications];
    l3_ingress_intf ingr_itf;
    uint32 rif_flags[2] = {BCM_L3_INGRESS_ROUTE_DISABLE_IP4_MCAST | BCM_L3_INGRESS_ROUTE_DISABLE_IP6_MCAST | BCM_L3_INGRESS_L3_MCAST_L2,
            BCM_L3_INGRESS_ROUTE_DISABLE_IP4_MCAST | BCM_L3_INGRESS_ROUTE_DISABLE_IP6_MCAST | BCM_L3_INGRESS_IP6_L3_MCAST_L2};
    int vids[2] = {eth_rif1, eth_rif2};
    bcm_l2_addr_t l2_addr;
    bcm_mac_t ipv4_mc_mac = {0x01, 0, 0x5E, 0x2, 0x2, 0x2};
    bcm_mac_t ipv6_mc_mac = {0x33, 0x33, 0x00, 0x34, 0x56, 0x78};

    l3_ingress_intf_init(&ingr_itf);

    for (idx = 0; idx < nof_mc_groups; idx++)
    {
        snprintf(error_msg, sizeof(error_msg), "create VLAN %d", vids[idx]);
        BCM_IF_ERROR_RETURN_MSG(bcm_vlan_create(unit, vids[idx]), error_msg);

        /* 1. Set In-Port to Eth-RIF */
        BCM_IF_ERROR_RETURN_MSG(in_port_intf_set(unit, in_ports[idx], vids[idx]), "intf_in");

        /* 2. Set Out-Port default properties */
        BCM_IF_ERROR_RETURN_MSG(out_port_set(unit, out_ports[idx]), "");

        /* 3. Create IN-RIF and set its properties */
        BCM_IF_ERROR_RETURN_MSG(intf_eth_rif_create(unit, vids[idx], cint_ipmc_info.intf_in_mac_address), "intf_in");

        /* 4. Set ingress interface */
        ingr_itf.intf_id = vids[idx];
        ingr_itf.vrf = vrf;
        ingr_itf.flags = rif_flags[idx];
        BCM_IF_ERROR_RETURN_MSG(intf_ingress_rif_set(unit, &ingr_itf), "intf_out");
    }
    /*
     * 5 Create the multicast group replications.
     */
    for (idx = 0; idx < cint_ipmc_info.nof_replications; idx++)
    {
        /*
         * 5.2 Set the replication.
         */
        set_multicast_replication(&replications[idx], out_ports[idx], -1);

        /*
         * 5.3 Set some changes for the next replication.
         */
        cint_ipmc_info.intf_out_mac_address[5]++;
    }
    /*
     * 6. Create a multicast group
     */
    for (idx = 0; idx < 4; idx++)
    {
        if (*dnxc_data_get(unit, "multicast", "params", "mcdb_formats_v2", NULL)) {
            flags = BCM_MULTICAST_INGRESS_GROUP | BCM_MULTICAST_ELEMENT_STATIC;
        } else {
            flags = BCM_MULTICAST_INGRESS_GROUP;
        }
        snprintf(error_msg, sizeof(error_msg), "%d", idx);
        BCM_IF_ERROR_RETURN_MSG(bcm_multicast_create(unit, (flags | BCM_MULTICAST_WITH_ID), &ipmc_group[idx]), error_msg);
        BCM_IF_ERROR_RETURN_MSG(bcm_multicast_add(unit, ipmc_group[idx], flags, cint_ipmc_info.nof_replications, replications), "");
    }

    BCM_IF_ERROR_RETURN_MSG(add_ipv4_ipmc_bridge(unit, dip_addr, dip_mask, sip_addr, sip_mask, vids[0], 0, ipmc_group[0], 0, 0), "");
    bcm_l2_addr_t_init(&l2_addr, ipv6_mc_mac, vids[0]);
    l2_addr.flags = BCM_L2_STATIC | BCM_L2_MCAST;
    l2_addr.l2mc_group = ipmc_group[1];
    BCM_IF_ERROR_RETURN_MSG(bcm_l2_addr_add(unit, &l2_addr), "");
    bcm_l2_addr_t_init(&l2_addr, ipv4_mc_mac, vids[1]);
    l2_addr.flags = BCM_L2_STATIC | BCM_L2_MCAST;
    l2_addr.l2mc_group = ipmc_group[2];
    BCM_IF_ERROR_RETURN_MSG(bcm_l2_addr_add(unit, &l2_addr), "");
    BCM_IF_ERROR_RETURN_MSG(add_ipv6_ipmc_bridge(unit, dip_v6_addr, dip_v6_mask, sip_v6_addr, sip_v6_mask, 0, vids[1], c_sip, ipmc_group[3], 0, 0), "");

    return BCM_E_NONE;
}
