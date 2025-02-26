/*
 * 
 This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 
 Copyright 2007-2022 Broadcom Inc. All rights reserved.
 * File: cint_dnx_evpn_protection.c
 * Purpose: Example of protected EVPN configuration.
 */
/*
 * This cint demonstrate configuration of a PE in a EVPN network, the link to a peer PE is protected.
 * The ingress link is 1+1 protected with a secondary ingress link.
 * The Egress MC link is 1:1 protected with a secondary IML link, both added to the MC group.
 * UC 1:1 protection is done through FEC mechanism. See cint_ac_fec_facility_protection.c for example. It is not
 * covered by the current example.
 * +------------------------------------------------------------------------------------------------+
 * |                                                                                                |
 * |                  +---------+  IML: 0x200   +------+               +-----------+                |
 * |                  |---------|  LSP: 0x3000  |      |               |           |                |
 * |                  ||       |+---------------+  P1  +---------------+ Prim-Peer +----------+     |
 * |   +-----+        ||       ||               |      |               |           |          |     |
 * |   |     |        ||       ||               +------+               +-----------+       +--+--+  |
 * |   | CE2 +--------+|  PE   ||                                                          | CE3 |  |
 * |   |     |        ||       ||  IML: 0x400   +------+               +-----------+       +--+--+  |
 * |   +-----+        ||       ||  LSP: 0x5000  |      |               |           |          |     |
 * |                  ||       |+---------------+  P2  +---------------+ Sec-Peer  +----------+     |
 * |                  |---------|               |      |               |           |                |
 * |                  +----+----+               +------+               +-----+-----+                |
 * |                       |                                                 |                      |
 * |                       |                                                 |                      |
 * |                       |                                                 |                      |
 * |                       |                   ESI 0x1000                    |                      |
 * |                       |                                                 |                      |
 * |                       |                                                 |                      |
 * |                       |                   +--------+                    |                      |
 * |                       |                   |        |                    |                      |
 * |                       +-------------------+  CE1   +--------------------+                      |
 * |                                           |        |                                           |
 * |                                           +--------+                                           |
 * |                                                                                                |
 * +------------------------------------------------------------------------------------------------+
 *
 * Both PEs are dual-homed to CE1 and also connected to other CEs.
 *
 */

/*
 * Test Scenario
 *
 * Test Scenario - start
  cint ../../../../src/examples/sand/utility/cint_sand_utils_global.c
  cint ../../../../src/examples/sand/utility/cint_sand_utils_l3.c
  cint ../../../../src/examples/sand/utility/cint_sand_utils_vlan.c
  cint ../../../../src/examples/sand/utility/cint_sand_utils_multicast.c
  cint ../../../../src/examples/sand/utility/cint_sand_utils_vlan_translate.c
  cint ../../../../src/examples/sand/cint_ip_route_basic.c
  cint ../../../../src/examples/dnx/utility/cint_dnx_utility_mpls.c
  cint ../../../../src/examples/dnx/utility/cint_dnx_utils_evpn.c
  cint ../../../../src/examples/dnx/field/cint_field_evpn_esi.c
  cint ../../../../src/examples/dnx/evpn/cint_dnx_evpn_protection.c
  cint
  evpn_protection_main(0,200,201,202,203);
  exit;
 *
 * >>>     SET USING INGESS PRIMARY     <<<
  cint
  evpn_protection_ingress_path_set(0, 1);
  exit;
 *
 * IML from primary -> Local flooding (No ESI)
  tx 1 psrc=202 data=0x0000000001330000000002228100001e8847030000400020014000000000011700000000025581000020ffff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f20
 *
 * Received packets on unit 0 should be:
 * Data: 0x00000000011700000000025581000020ffff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f20
 * Data: 0x00000000011700000000025581000020ffff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f20
 *
 * IML from secondary -> Local flooding (No ESI)
  tx 1 psrc=203 data=0x000000000144000000000223810000288847060000400040014000000000011700000000025581000020ffff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f20
 *
 * DROP
 *
 * IML from secondary -> Local flooding (ESI filtered)
  tx 1 psrc=203 data=0x00000000014400000000022381000028884706000040004000400100014000000000011700000000025581000020ffff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f20
 *
 * DROP
 *
 * >>>     SET USING INGESS SECONDARY      <<<
  cint
  evpn_protection_ingress_path_set(0, 0);
  exit;
 *
 * IML from primary -> Local flooding (No ESI)
  tx 1 psrc=202 data=0x0000000001330000000002228100001e8847030000400020014000000000011700000000025581000020ffff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f20
 *
 * DROP
 *
 * IML from secondary -> Local flooding (No ESI)
  tx 1 psrc=203 data=0x000000000144000000000223810000288847060000400040014000000000011700000000025581000020ffff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f20
 *
 * Received packets on unit 0 should be:
 * Data: 0x00000000011700000000025581000020ffff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f20
 * Data: 0x00000000011700000000025581000020ffff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f20
 *
 * IML from secondary -> Local flooding (ESI filtered)
  tx 1 psrc=203 data=0x00000000014400000000022381000028884706000040004000400100014000000000011700000000025581000020ffff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f20
 *
 * Received packets on unit 0 should be:
 * Data: 0x00000000011700000000025581000020ffff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f20
 *
 * >>>     SET USING EGESS PRIMARY      <<<
  cint
  evpn_protection_egress_path_set(0, 1);
  exit;
 *
 * CE2 -> flooding to CE1 and peer
  tx 1 psrc=201 data=0x00000000025500000000025481000020ffff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f20
 *
 * Received packets on unit 0 should be:
 * Data: 0x00000000025500000000025481000020ffff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f200000000000000000000000
 * Data: 0x000000000222000000000133810000208847030000fe002001fe00000000025500000000025481000020ffff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f200000000000000000000000
 *
 * CE1 -> flooding to CE2 and peer
  tx 1 psrc=200 data=0x00000000025500000000025381000020ffff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f20
 *
 * Received packets on unit 0 should be:
 * Data: 0x00000000025500000000025381000020ffff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f200000000000000000000000
 * Data: 0x000000000222000000000133810000208847030000fe002001fe00000000025500000000025381000020ffff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f200000000000000000000000
 *
 * >>>     SET USING EGESS SECONDARY      <<<
  cint
  evpn_protection_egress_path_set(0, 0);
  exit;
 *
 * CE2 -> flooding to CE1 and peer
  tx 1 psrc=201 data=0x00000000025500000000025481000020ffff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f20
 *
 * Received packets on unit 0 should be:
 * Data: 0x00000000025500000000025481000020ffff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f200000000000000000000000
 * Data: 0x000000000223000000000144810000208847060000fe004001fe00000000025500000000025481000020ffff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f200000000000000000000000
 *
 * CE2 -> flooding to CE1 and peer
  tx 1 psrc=200 data=0x00000000025500000000025381000020ffff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f20
 *
 * Received packets on unit 0 should be:
 * Data: 0x00000000025500000000025381000020ffff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f200000000000000000000000
 * Data: 0x000000000223000000000144810000208847060000fe004000fe0100010100000000025500000000025381000020ffff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f200000000000000000000000
 * Test Scenario - end
 *
 */


/*
 * Structure to hold core mpls interfaces for carrying traffic to a peer
 */
struct evpn_core_intf_s
{
    int rif;
    bcm_mac_t next_hop_mac;
    bcm_mac_t rif_mac;
    bcm_mpls_label_t lsp_label;
};

/*
 * General structure to hold the objects generated to implement
 * the scenario described in cint_evpn.c.
 */
struct evpn_protection_info_s
{
    int vpn;

    evpn_util_peer_info_s peer_primary;
    evpn_util_peer_info_s peer_secondary;

    evpn_core_intf_s p1_ifs;
    evpn_core_intf_s p2_ifs;

    /** User defined in-lif profile for ESI FP filter. */
    int in_lif_acl_profile_esi;

    /** EVPN Network group ID for split horizon */
    int evpn_nwk_grp_id;
    /** When network group is taken from ESEM, need default native AC with the correct value */
    bcm_vlan_port_t evpn_default_native_ac;

    /** Access Network Group ID for split horizon */
    int access_nwk_grp_id;

    /** IML label range properties */
    bcm_mpls_label_t iml_label_range_low;
    bcm_mpls_label_t iml_label_range_high;

    /** CE links information */
    bcm_vlan_port_t ce1_vport;
    bcm_vlan_port_t ce2_vport;

    /** Generated failover IDs */
    bcm_failover_t ingress_failover_id;
    bcm_failover_t egress_failover_id;
};

evpn_protection_info_s evpn_protection_info;

int
evpn_protection_params_init(
    int unit)
{
    evpn_util_peer_info_s * p_info;
    evpn_core_intf_s * p_ifs;
    bcm_vlan_port_t * p_vport;

    bcm_mac_t p1_rif_mac = {0x00, 0x00, 0x00, 0x00, 0x01, 0x33};
    bcm_mac_t p1_next_hop = {0x00, 0x00, 0x00, 0x00, 0x02, 0x22};
    bcm_mac_t p2_rif_mac = {0x00, 0x00, 0x00, 0x00, 0x01, 0x44};
    bcm_mac_t p2_next_hop = {0x00, 0x00, 0x00, 0x00, 0x02, 0x23};

    printf("Load global configuration\n");
    /*
     * By default, FP in-lif profile is 2 bits. The value for these bits is managed by the application, in
     * consideration of other ACL application that may use these bits.
     * Need to select a value between 0-3. 0 should be reserved for non-ESI profiles.
     * Selected 1 arbitrarily.
     */
    evpn_protection_info.in_lif_acl_profile_esi = 1;
    /*
     * Select network groups for EVPN and Access, to configure split horizon to filter
     * traffic going back (for example through traffic) to the same network (EVPN to
     * EVPN).
     */
    evpn_protection_info.access_nwk_grp_id = 0;
    evpn_protection_info.evpn_nwk_grp_id = 2;

    evpn_protection_info.vpn = 0x20;

    evpn_protection_info.iml_label_range_low = 0x200;
    evpn_protection_info.iml_label_range_high = 0x6ff;

    printf("Load CE1 link configuration\n");
    p_vport = &evpn_protection_info.ce1_vport;
    bcm_vlan_port_t_init(p_vport);
    p_vport->criteria = BCM_VLAN_PORT_MATCH_PORT_CVLAN;
    p_vport->match_vlan = evpn_protection_info.vpn;
    p_vport->egress_vlan = 0;

    printf("Load CE2 link configuration\n");
    p_vport = &evpn_protection_info.ce2_vport;
    bcm_vlan_port_t_init(p_vport);
    p_vport->criteria = BCM_VLAN_PORT_MATCH_PORT_CVLAN;
    p_vport->match_vlan = evpn_protection_info.vpn;
    p_vport->egress_vlan = 0;

    printf("Load Primary Peer configuration\n");
    p_info = &evpn_protection_info.peer_primary;
    p_info->vpn = evpn_protection_info.vpn;
    p_info->evpn_label = 0x111;
    p_info->iml_label = 0x200;
    p_info->iml_esi_acl_lif_profile = evpn_protection_info.in_lif_acl_profile_esi;
    p_info->iml_dual_homed_peer_profile = 0x20;
    p_info->nof_dual_homed_ces = 0;
    p_info->network_group_id = evpn_protection_info.evpn_nwk_grp_id;
    p_info->default_native_ac_for_split_horizon = &evpn_protection_info.evpn_default_native_ac;

    printf("Load Secondary Peer configuration\n");
    p_info = &evpn_protection_info.peer_secondary;
    p_info->vpn = evpn_protection_info.vpn;
    p_info->evpn_label = 0x112;
    p_info->iml_label = 0x400;
    p_info->iml_esi_acl_lif_profile = evpn_protection_info.in_lif_acl_profile_esi;
    p_info->iml_dual_homed_peer_profile = 0x30;
    p_info->nof_dual_homed_ces = 1;
    p_info->dual_homed_ce_info[0].esi_label = 0x1000;
    p_info->dual_homed_ce_info[0].src_port = &evpn_protection_info.ce1_vport.port;
    p_info->network_group_id = evpn_protection_info.evpn_nwk_grp_id;
    p_info->default_native_ac_for_split_horizon = &evpn_protection_info.evpn_default_native_ac;

    printf("Load P1 configuration\n");
    p_ifs = &evpn_protection_info.p1_ifs;
    p_ifs->rif = 30;
    p_ifs->rif_mac = p1_rif_mac;
    p_ifs->next_hop_mac = p1_next_hop;
    p_ifs->lsp_label = 0x3000;


    printf("Load P2 configuration\n");
    p_ifs = &evpn_protection_info.p2_ifs;
    p_ifs->rif = 40;
    p_ifs->rif_mac = p2_rif_mac;
    p_ifs->next_hop_mac = p2_next_hop;
    p_ifs->lsp_label = 0x6000;

    return BCM_E_NONE;
}


int
init_evpn_mpls_util_params(
    int unit)
{
    mpls_util_entity_s * entity;
    evpn_core_intf_s * p_ifs;

    printf("Configuring Entity 0 - MPLS tunnels from PE1 to Peer1\n");
    p_ifs = &evpn_protection_info.p1_ifs;
    entity = &mpls_util_entity[0];
    entity->arps[0].next_hop = p_ifs->next_hop_mac;
    entity->arps[0].flags2 |= BCM_L3_FLAGS2_VLAN_TRANSLATION;
    entity->rifs[0].mac_addr = p_ifs->rif_mac;
    entity->rifs[0].intf = p_ifs->rif;
    printf("- Configure MPLS LSP encapsulation 0\n");
    entity->mpls_encap_tunnel[0].num_labels = 1;
    entity->mpls_encap_tunnel[0].label[0] = p_ifs->lsp_label;
    entity->mpls_encap_tunnel[0].encap_access = bcmEncapAccessTunnel2;
    entity->mpls_encap_tunnel[0].l3_intf_id = &entity->arps[0].arp;
    printf("  - Reconnect entity 0 to it's own out port\n");
    entity->fecs[0].port = &entity->ports[0].port;
    printf("- Configure MPLS LSP termination\n");
    entity->mpls_switch_tunnel[0].action = BCM_MPLS_SWITCH_ACTION_POP;
    entity->mpls_switch_tunnel[0].label = p_ifs->lsp_label;
    entity->mpls_switch_tunnel[0].vrf = 1;

    printf("Configure Entity 1 - MPLS tunnel from PE1 to PE2 through P2\n");
    p_ifs = &evpn_protection_info.p2_ifs;
    entity = &mpls_util_entity[1];
    entity->arps[0].next_hop = p_ifs->next_hop_mac;
    entity->arps[0].flags2 |= BCM_L3_FLAGS2_VLAN_TRANSLATION;
    entity->rifs[0].mac_addr = p_ifs->rif_mac;
    entity->rifs[0].intf = p_ifs->rif;
    printf("- Configure MPLS LSP encapsulation 0\n");
    entity->mpls_encap_tunnel[0].num_labels = 1;
    entity->mpls_encap_tunnel[0].label[0] = p_ifs->lsp_label;
    entity->mpls_encap_tunnel[0].flags |= BCM_MPLS_EGRESS_LABEL_TTL_DECREMENT;
    entity->mpls_encap_tunnel[0].encap_access = bcmEncapAccessTunnel2;
    entity->mpls_encap_tunnel[0].l3_intf_id = &entity->arps[0].arp;
    printf("  - Reconnect entity 1 to it's own out port\n");
    entity->fecs[0].port = &entity->ports[0].port;
    printf("- Reset entity 1 fec 0");
    entity->fecs[0].tunnel_gport = &entity->mpls_encap_tunnel[0].tunnel_id;
    entity->fecs[0].tunnel_gport2 = &MPLS_UTIL_INVALID_GPORT;
    printf("- Configure MPLS LSP termination\n");
    entity->mpls_switch_tunnel[0].action = BCM_MPLS_SWITCH_ACTION_POP;
    entity->mpls_switch_tunnel[0].label = p_ifs->lsp_label;
    entity->mpls_switch_tunnel[0].vrf = 2;

    return BCM_E_NONE;
}

/*
 * Main function to configure the scenario described above
 * The function performs the following activities:
 * - Setup the VSI
 * - Create ETH segments - in this example - AC links
 * - Configure a L3 MPLS core connecting the device to neighboring MPLS routers
 * - Setup EVPN services for L2 MC over the MPLS core
 */
int
evpn_protection_main(
    int unit,
    int ce1_port,
    int ce2_port,
    int p1_port,
    int p2_port)
{
    char error_msg[200]={0,};

    printf("~~ EVPN Protection Example ~~\n");

    printf("Load application profiles and misc configs\n");
    BCM_IF_ERROR_RETURN_MSG(evpn_protection_params_init(unit), "");

    BCM_IF_ERROR_RETURN_MSG(in_port_intf_set(unit, p1_port, evpn_protection_info.p1_ifs.rif), "");

    BCM_IF_ERROR_RETURN_MSG(in_port_intf_set(unit, p2_port, evpn_protection_info.p2_ifs.rif), "");

    BCM_IF_ERROR_RETURN_MSG(in_port_intf_set(unit, ce1_port, evpn_protection_info.vpn), "");

    BCM_IF_ERROR_RETURN_MSG(in_port_intf_set(unit, ce2_port, evpn_protection_info.vpn), "");

    printf("Create VPN (%d)\n", evpn_protection_info.vpn);
    BCM_IF_ERROR_RETURN_MSG(evpn_protection_vswitch_create(unit), "");

    printf("Init ESI filter FP application\n");
    BCM_IF_ERROR_RETURN_MSG(evpn_util_esi_filter_init(unit, evpn_protection_info.in_lif_acl_profile_esi), "");

    printf("Init Split Horizon filter\n");
    BCM_IF_ERROR_RETURN_MSG(evpn_protection_split_horizon_filter_config(unit), "");

    printf("Create ETH segments\n");
    BCM_IF_ERROR_RETURN_MSG(evpn_protection_eth_segments_create(unit, ce1_port, ce2_port), "");

    printf("Setup MPLS L3 network\n");
    BCM_IF_ERROR_RETURN_MSG(evpn_mpls_core_setup(unit, p1_port, p2_port), "");

    printf("Setup EVPN Services\n");
    BCM_IF_ERROR_RETURN_MSG(evpn_service_config(unit), "");

    /* Configure ESI filter for IOP mode */
    if (!is_jr2_system_header_mode(unit)) {
        /* Init forbidden port */
        field_evpn_info_init(unit, 0, ce1_port, p2_port, 0, ce1_port, ce2_port);

        /* ESI label 0x1000 */
        cint_field_evpn_info.esi1_label[1] = 0x10;
        cint_field_evpn_info.esi1_label[2] = 0;
        /* Set IPMF to set forbidden port to learn_extension */
        snprintf(error_msg, sizeof(error_msg), "unit: %d, in esi_db", unit);
        BCM_IF_ERROR_RETURN_MSG(field_jr2_comp_evpn_esi_db(unit, jr2_ing_presel_id-1/*presel_id*/), error_msg);

        /* Configure EPMF to drop when dst_port matches learn_extension */
        snprintf(error_msg, sizeof(error_msg), "unit: %d, in evpn_egress_filter_db", unit);
        BCM_IF_ERROR_RETURN_MSG(field_jr2_comp_evpn_egress_filter_db(unit, jr2_egr_presel_id), error_msg);
    }

    return BCM_E_NONE;
}

/*
 * Create VSwitch and flooding MC group for it.
 */
int
evpn_protection_vswitch_create(
    int unit)
{

    printf("- Create VSI\n");
    BCM_IF_ERROR_RETURN_MSG(bcm_vswitch_create_with_id(unit, evpn_protection_info.vpn), "");

    printf("- Create MC group\n");
    BCM_IF_ERROR_RETURN_MSG(multicast__open_mc_group(unit, &evpn_protection_info.vpn, egress_mc), "");

    return BCM_E_NONE;
}

/*
 * Configure split horizon for EVPN to EVPN filtering
 */
int
evpn_protection_split_horizon_filter_config(
    int unit)
{

    bcm_switch_network_group_config_t network_group_config;
    bcm_switch_network_group_config_t_init(&network_group_config);
    network_group_config.dest_network_group_id = evpn_protection_info.evpn_nwk_grp_id;
    network_group_config.config_flags = BCM_SWITCH_NETWORK_GROUP_EGRESS_PRUNE_ENABLE;
    BCM_IF_ERROR_RETURN_MSG(bcm_switch_network_group_config_set(unit, evpn_protection_info.evpn_nwk_grp_id, &network_group_config), "EVPN group ID");

    return BCM_E_NONE;
}

/*
 * Setup the port properties and creates the vlan port for a link with a CE.
 * Adds the vlan port to the VSI.
 */
int
evpn_protection_es_link_create(
    int unit,
    int vsi,
    bcm_vlan_port_t * vport,
    int add_to_flooding)
{
    char error_msg[200]={0,};
    int port = vport->port;
    /*
     * set class
     */
    snprintf(error_msg, sizeof(error_msg), "port=%d", port);
    BCM_IF_ERROR_RETURN_MSG(bcm_port_class_set(unit, port, bcmPortClassId, port), error_msg);

    /*
     * Set Out-Port default properties
     */
    snprintf(error_msg, sizeof(error_msg), "port=%d", port);
    BCM_IF_ERROR_RETURN_MSG(out_port_set(unit, port), error_msg);

    /*
     * Create vlan port
     */
    BCM_IF_ERROR_RETURN_MSG(bcm_vlan_port_create(unit, vport), "");

    /*
     * Set VSI
     */
    BCM_IF_ERROR_RETURN_MSG(bcm_vswitch_port_add(unit, vsi, vport->vlan_port_id), "");

    /*
     * Add to flooding domain
     */
    if (add_to_flooding)
    {
        bcm_gport_t gport;
        BCM_GPORT_MODPORT_SET(gport, unit, port);
        BCM_IF_ERROR_RETURN_MSG(multicast__add_multicast_entry(unit, vsi, &gport, &vport->encap_id, 1, egress_mc), "");
    }

    return BCM_E_NONE;
}

/*
 * Create CE1 Vlan port,
 * Create CE2 Vlan port,
 */
int
evpn_protection_eth_segments_create(
    int unit,
    int ce1_port,
    int ce2_port)
{
    int add_to_flooding;

    evpn_protection_info.ce1_vport.port = ce1_port;
    add_to_flooding = 1;
    BCM_IF_ERROR_RETURN_MSG(evpn_protection_es_link_create(unit, evpn_protection_info.vpn, &evpn_protection_info.ce1_vport,
                                        add_to_flooding), "");
    BCM_IF_ERROR_RETURN_MSG(evpn_util_esi_filter_entry_add(unit, evpn_protection_info.peer_secondary.dual_homed_ce_info[0].esi_label,
                                        &ce1_port, 1), "");

    evpn_protection_info.ce2_vport.port = ce2_port;
    add_to_flooding = 1;
    BCM_IF_ERROR_RETURN_MSG(evpn_protection_es_link_create(unit, evpn_protection_info.vpn, &evpn_protection_info.ce2_vport,
                                        add_to_flooding), "");

    return BCM_E_NONE;
}

/*
 * Create EVPN L3 network to route packets from PE1 to P1, P2
 */
int
evpn_mpls_core_setup(
    int unit,
    int p1_port,
    int p2_port)
{

    printf("Initializing MPLS utility.\n");
    BCM_IF_ERROR_RETURN_MSG(init_default_mpls_params(unit, p1_port, p2_port), "");

    printf("Configure example specific parameters to MPLS utility.\n");
    BCM_IF_ERROR_RETURN_MSG(init_evpn_mpls_util_params(unit), "");

    printf("Run MPLS utility\n");
    BCM_IF_ERROR_RETURN_MSG(mpls_util_main(unit, 0/*ignored*/, 0/*ignored*/), "");

    printf("Add vlan translation to ARP+VLAN translation entries\n");
    BCM_IF_ERROR_RETURN_MSG(evpn_mpls_arp_plus_ac_configure(unit), "");

    return BCM_E_NONE;
}

/*
 * Set vlan translation in ARP+AC entries, used for MPLS tunnels
 * with ESI DB lookup trigger.
 */
int
evpn_mpls_arp_plus_ac_configure(
    int unit)
{

    int encap_id;
    int arp_outlif;
    bcm_gport_t arp_gport;

    encap_id = mpls_util_entity[0].arps[0].arp;
    arp_outlif = BCM_L3_ITF_VAL_GET(encap_id);
    BCM_GPORT_SUB_TYPE_L3_VLAN_TRANSLATION_SET(arp_gport, arp_outlif);
    BCM_GPORT_VLAN_PORT_ID_SET(arp_gport, arp_gport);
    BCM_IF_ERROR_RETURN_MSG(vlan_translate_ive_eve_translation_set(unit, arp_gport,
                                                0x8100,                           0,
                                                bcmVlanActionArpVlanTranslateAdd, bcmVlanActionNone,
                                                evpn_protection_info.vpn,              0,
                                                3, 0, 0), "");

    encap_id = mpls_util_entity[1].arps[0].arp;
    arp_outlif = BCM_L3_ITF_VAL_GET(encap_id);
    BCM_GPORT_SUB_TYPE_L3_VLAN_TRANSLATION_SET(arp_gport, arp_outlif);
    BCM_GPORT_VLAN_PORT_ID_SET(arp_gport, arp_gport);
    BCM_IF_ERROR_RETURN_MSG(vlan_translate_ive_eve_translation_set(unit, arp_gport,
                                                0x8100,                           0,
                                                bcmVlanActionArpVlanTranslateAdd, bcmVlanActionNone,
                                                evpn_protection_info.vpn,              0,
                                                4, 0, 0), "");

    return BCM_E_NONE;
}

/*
 * Configure EVPN services
 */
int
evpn_service_config(
    int unit)
{

    bcm_mpls_esi_info_t esi_encap;
    bcm_mpls_range_action_t action;
    int nwk_grp_from_esem = *dnxc_data_get(unit, "esem", "feature", "etps_properties_assignment", NULL);

    if (nwk_grp_from_esem)
    {
        bcm_vlan_port_t * default_native_ac = &evpn_protection_info.evpn_default_native_ac;
        /*
         * Default egress native AC with network group for the IMLs (used for
         * setting up split horizon)
         */
        printf("Create egress default native AC with EVPN network group ID for split horizon\n");
        bcm_vlan_port_t_init(default_native_ac);
        default_native_ac->criteria = BCM_VLAN_PORT_MATCH_NONE;
        default_native_ac->flags = BCM_VLAN_PORT_DEFAULT | BCM_VLAN_PORT_NATIVE
                | BCM_VLAN_PORT_CREATE_EGRESS_ONLY | BCM_VLAN_PORT_VLAN_TRANSLATION;
        default_native_ac->egress_network_group_id = evpn_protection_info.evpn_nwk_grp_id;
        BCM_IF_ERROR_RETURN_MSG(bcm_vlan_port_create(unit, default_native_ac), "");
    }

    /** JR2: Create fabric MC for each core in case of egress Multicast. */
    if (egress_mc && (!sand_utils_is_jr2_system_header_mode(unit)) && (*dnxc_data_get(unit, "fabric", "general", "blocks_exist", NULL)))
    {
        int nof_cores = *dnxc_data_get(unit, "device", "general", "nof_cores", NULL);
        bcm_module_t mreps[2];
        mreps[0] = 0;
        mreps[1] = 1; /* Ignore it in single core devices*/
        BCM_IF_ERROR_RETURN_MSG(bcm_fabric_multicast_set(unit, evpn_protection_info.vpn, 0, nof_cores, mreps), "");
    }

    printf("Set IML range\n");
    action.flags = BCM_MPLS_RANGE_ACTION_EVPN_IML;
    BCM_IF_ERROR_RETURN_MSG(bcm_mpls_range_action_add(unit, evpn_protection_info.iml_label_range_low,
                                   evpn_protection_info.iml_label_range_high, &action), "");

    printf("Create failover for IML services\n");

    /** In case the mc protection is supported, we use it as egress protection.*/
    uint32 flags = 0;
    if (*dnxc_data_get(unit, "multicast", "params", "mcdb_formats_v2", NULL))
    {
        flags = BCM_FAILOVER_INGRESS_MC;
    }
    else
    {
        flags = BCM_FAILOVER_ENCAP;
    }
    BCM_IF_ERROR_RETURN_MSG(bcm_failover_create(unit, flags, &evpn_protection_info.egress_failover_id), "");

    BCM_IF_ERROR_RETURN_MSG(bcm_failover_create(unit, BCM_FAILOVER_INGRESS, &evpn_protection_info.ingress_failover_id), "");

    printf("Creating EVPN services for primary peer\n");
    evpn_protection_info.peer_primary.iml_ingress_protection.enabled = 1;
    evpn_protection_info.peer_primary.iml_ingress_protection.failover_id = evpn_protection_info.ingress_failover_id;
    evpn_protection_info.peer_primary.iml_ingress_protection.failover_path = 1; /** primary */
    evpn_protection_info.peer_primary.iml_egress_protection.enabled = *dnxc_data_get(unit, "multicast", "params", "mcdb_formats_v2", NULL) ? 0 : 1;
    evpn_protection_info.peer_primary.iml_egress_protection.failover_id = evpn_protection_info.egress_failover_id;
    evpn_protection_info.peer_primary.iml_egress_protection.failover_path = 1; /** primary */
    BCM_IF_ERROR_RETURN_MSG(evpn_util_peer_services_create(unit, &evpn_protection_info.peer_primary), "");

    printf("Creating EVPN services for secondary peer\n");
    evpn_protection_info.peer_secondary.iml_ingress_protection.enabled = 1;
    evpn_protection_info.peer_secondary.iml_ingress_protection.failover_id = evpn_protection_info.ingress_failover_id;
    evpn_protection_info.peer_secondary.iml_ingress_protection.failover_path = 0; /** secondary */
    evpn_protection_info.peer_secondary.iml_egress_protection.enabled = *dnxc_data_get(unit, "multicast", "params", "mcdb_formats_v2", NULL) ? 0 : 1;
    evpn_protection_info.peer_secondary.iml_egress_protection.failover_id = evpn_protection_info.egress_failover_id;
    evpn_protection_info.peer_secondary.iml_egress_protection.failover_path = 0; /** secondary */
    BCM_IF_ERROR_RETURN_MSG(evpn_util_peer_services_create(unit, &evpn_protection_info.peer_secondary), "");

    if (*dnxc_data_get(unit, "multicast", "params", "mcdb_formats_v2", NULL))
    {
        BCM_IF_ERROR_RETURN_MSG(evpn_iml_failover_mc_add(unit, evpn_protection_info.egress_failover_id,
                                      *(mpls_util_entity[0].fecs[0].port),
                                      *(mpls_util_entity[0].fecs[0].tunnel_gport), /** not really a gport */
                                      evpn_protection_info.peer_primary.iml_egress_label.tunnel_id,
                                      *(mpls_util_entity[1].fecs[0].port),
                                      *(mpls_util_entity[1].fecs[0].tunnel_gport), /** not really a gport */
                                      evpn_protection_info.peer_secondary.iml_egress_label.tunnel_id), "");
    }
    else
    {
        BCM_IF_ERROR_RETURN_MSG(evpn_iml_mc_add(unit, *(mpls_util_entity[0].fecs[0].port),
                             *(mpls_util_entity[0].fecs[0].tunnel_gport), /** not really a gport */
                             evpn_protection_info.peer_primary.iml_egress_label.tunnel_id), "");
        BCM_IF_ERROR_RETURN_MSG(evpn_iml_mc_add(unit, *(mpls_util_entity[1].fecs[0].port),
                             *(mpls_util_entity[1].fecs[0].tunnel_gport), /** not really a gport */
                             evpn_protection_info.peer_secondary.iml_egress_label.tunnel_id), "");
    }

    return BCM_E_NONE;
}

/*
 * Add IML encapsulation to the VSI's flooding group
 */
int
evpn_iml_mc_add(
    int unit,
    int port,
    int lsp_tunnel_if,
    int iml_tunnel_if)
{

    int mc_id = evpn_protection_info.vpn;
    int cuds[2];
    int mc_ext_id;

    printf("Adding IML egress labels to the VPN MC group\n");
    /** Peer1 IML */
    mc_ext_id = 0;
    cuds[0] = iml_tunnel_if;
    cuds[1] = lsp_tunnel_if;
    BCM_IF_ERROR_RETURN_MSG(bcm_multicast_encap_extension_create(unit, 0, &mc_ext_id, 2, cuds), "");
    printf(" - Created PPMC entry with ID = 0x%08x\n", mc_ext_id);

    BCM_IF_ERROR_RETURN_MSG(multicast__add_multicast_entry(unit, mc_id, &port, &mc_ext_id, 1, egress_mc), "");
    printf(" - <port=%d, rep_idx=0x%08x> added to MC group %d\n", port, mc_ext_id, mc_id);

    return BCM_E_NONE;
}

/*
 * Add IML encapsulation to the VSI's flooding group
 */
int
evpn_iml_failover_mc_add(
    int unit,
    int failover_id,
    int primary_port,
    int primary_lsp_tunnel_if,
    int primary_iml_tunnel_if,
    int secondary_port,
    int secondary_lsp_tunnel_if,
    int secondary_iml_tunnel_if)
{

    int mc_id = evpn_protection_info.vpn;
    int cuds[2];
    int primary_mc_ext_id, secondary_mc_ext_id;

    printf("Adding IML egress labels to the VPN MC group\n");

    if (!*dnxc_data_get(unit, "multicast", "params", "mcdb_formats_v2", NULL)) {
        printf("evpn_iml_mc_failover_add is not supported in current device!\n");
        return BCM_E_CONFIG;
    }

    primary_mc_ext_id = 0;
    cuds[0] = primary_lsp_tunnel_if;
    cuds[1] = primary_iml_tunnel_if;
    BCM_IF_ERROR_RETURN_MSG(bcm_multicast_encap_extension_create(unit, 0, &primary_mc_ext_id, 2, cuds), "");
    printf(" - Created Primary PPMC entry with ID = 0x%08x\n", primary_mc_ext_id);

    secondary_mc_ext_id = 0;
    cuds[0] = secondary_lsp_tunnel_if;
    cuds[1] = secondary_iml_tunnel_if;
    BCM_IF_ERROR_RETURN_MSG(bcm_multicast_encap_extension_create(unit, 0, &secondary_mc_ext_id, 2, cuds), "");
    printf(" - Created Secondary PPMC entry with ID = 0x%08x\n", secondary_mc_ext_id);

    uint32 flags = BCM_MULTICAST_INGRESS_GROUP | BCM_MULTICAST_ELEMENT_STATIC;
    bcm_multicast_replication_t rep_array;
    bcm_multicast_replication_t_init(&rep_array);
    rep_array.port = BCM_GPORT_IS_MODPORT(primary_port) ? BCM_GPORT_MODPORT_PORT_GET(primary_port) : primary_port;
    rep_array.port2 = BCM_GPORT_IS_MODPORT(secondary_port) ? BCM_GPORT_MODPORT_PORT_GET(secondary_port) : secondary_port;
    rep_array.encap1 = primary_mc_ext_id;
    rep_array.encap2 = secondary_mc_ext_id;
    rep_array.failover_id = failover_id;
    rep_array.flags = BCM_MULTICAST_REP_EITHER;
    BCM_IF_ERROR_RETURN_MSG(bcm_multicast_add(unit, mc_id, flags, 1, rep_array), "");
    printf(" - <port1=%d, rep_idx1=0x%08x, port2=%d, rep_idx2=0x%08x> added to protection MC group %d\n",
           primary_port, secondary_port, primary_mc_ext_id, secondary_mc_ext_id, mc_id);

    return BCM_E_NONE;
}



/* *************************
 * Protection path switchers
 * *************************/

/*
 * Set protection state for 1+1 protection
 */
int
evpn_protection_ingress_path_set(
    int unit,
    int use_primary)
{

    use_primary = (use_primary ? 1 : 0);
    BCM_IF_ERROR_RETURN_MSG(bcm_failover_set(unit, evpn_protection_info.ingress_failover_id, use_primary), "");

    return BCM_E_NONE;
}

/*
 * Set protection state for 1:1 protection
 */
int
evpn_protection_egress_path_set(
    int unit,
    int use_primary)
{

    use_primary = (use_primary ? 1 : 0);
    BCM_IF_ERROR_RETURN_MSG(bcm_failover_set(unit, evpn_protection_info.egress_failover_id, use_primary), "");

    return BCM_E_NONE;
}
