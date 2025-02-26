/*
 * 
 This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 
 Copyright 2007-2022 Broadcom Inc. All rights reserved.
 * File: cint_dnx_tunnel_l2_encap_external_cpu.c
 * Purpose: Example of trapping snooping and forwarding IPv4 tunneled packets to a remote CPU.
 */
/*
 * This CINT contains an example of packet tunneling to external CPU.
 * The packet is encapsulated above the system headers with an outer LL header, according to ARP encapsulation specification.
 *
 * In order to receive remote CPU tunneling, the following configurations are required:
 * 1. soc property for the header type of the remote CPU port:
 * tm_port_header_type_out_<cpu_port>.BCM88690=ENCAP_EXTERNAL_CPU
 *
 * 2. FTMH Ethernet next protocol should be configured through bcm_switch_control_set with type=bcmSwitchFtmhEtherType
 *
 * Scenarios tested in this cint:
 * Test 1:
 * forwarding to external CPU port
 * dnx_tunnel_l2_external_cpu_info_t structure indicates the encapsulation header information
 * the l2_external_cpu_info.l2_remote_arp_intf field will hold the lif index.
 *
 * preserve_trap parameter is used to indicate that in case of trap/snoop, the redirected packet will
 * contain system headers stack that includes FHEI header with trap/snoop command information.
 *
 * Example of usage in JR2 (NOTE: the exact system headers details depend on system configuration):
 *
 * Test Scenario - start
  cint ../../../../src/examples/sand/utility/cint_dnx_utils_global.c
  cint ../../../../src/examples/sand/cint_dnx_ip_route_basic.c
  cint ../../../../src/examples/sand/utility/cint_dnx_utils_vlan_translate.c
  cint ../../../../src/examples/dnx/tunnel/cint_dnx_tunnel_l2_encap_external_cpu.c
  cint
  dnx_tunnel_l2_external_cpu_run_all(0,16,201,202,1);
  exit;
 *
 * Ip over ethernet packet, UC forwarding and snooping
  tx 1 psrc=16 data=0x000c000200000011000001120800450000350000000080005873a0000011a0a1a1a3000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f20
 *
 * Received packets on unit 0 should be:
 * Source port: 0, Destination port: 0
 * Data: 0x6789ab010a1b2c3d4e5f810070648999019c00086480000000e4af49bb0000000000000004040e00020000a00400200210000100000c000200000011000001120800450000350000000080005873a0000011a0a1a1a3000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f20
 *
 * SA=DA, trap to remote CPU
  tx 1 psrc=15 data=0x000c00020000000c000200000800450000350000000080005873a0000011a0a1a1a3000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f20
 *
 * Received packets on unit 0 should be:
 * Source port: 0, Destination port: 0
 * Data: 0x6789ab020a1b2c3d4e5f81007064899901a40007e501000023e474784900000000000000000000000200000007fa0003000000004500000c00020000000c000200000800450000350000000080005873a0000011a0a1a1a3000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f20
 *
 * MC group destination to 2 remote encaps
  tx 1 psrc=16 data=0x000c000200000011000001120800450000350000000080005874a0000011a0a1a1a2000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f20
 *
 * Received packets on unit 0 should be:
 * Source port: 0, Destination port: 0
 * Data: 0x6789ab030a1b2c3d4e5f810070648999019000086485000030e4e7c71a0000000000000004040e00020000a00400000200000c000200000011000001120800450000350000000080005874a0000011a0a1a1a2000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f20
 * Source port: 0, Destination port: 0
 * Data: 0x6789ab020a1b2c3d4e5f810070648999019000086485000020e4e7c71a0000000000000004040e00020000a00400000200000c000200000011000001120800450000350000000080005874a0000011a0a1a1a2000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f20
 * Test Scenario - end
 *
 * Test 2:
 * L2 uc/mc/trap forwarding to external CPU port
 *
 * Test Scenario - start
  config add tm_port_header_type_out_200.0=ENCAP_EXTERNAL_CPU
  config add tm_port_header_type_out_201.0=ENCAP_EXTERNAL_CPU
  0: tr 141 NoInit=1
  config add custom_feature_init_verify=1
  config delete custom_feature_multithread_en*
  config delete custom_feature_kbp_multithread_en*
  0: tr 141 NoDeinit=1
  cint ../../../../src/examples/dnx/l3/cint_dnx_ip_route_basic.c
  cint ../../../../src/examples/dnx/utility/cint_dnx_utils_vlan_translate.c
  cint ../../../../src/examples/dnx/tunnel/cint_dnx_tunnel_l2_encap_external_cpu.c
  cint
  dnx_l2_fwd_external_cpu_run_all(0,17,200,201);
  exit;
 *
 * Creating UC packet to do l2 uc fwd
  tx 1 psrc=17 data=0x80060000000000eb00000000001581008001ffff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f20
 *
 * Received packets on unit 0 should be:
 * Source port: 17, Destination port: 200
 * Data: 0x23456789ab030a1b2c3d4e5f81007064899902240008e408056732608324c747f505ee000000000000000007fa00020000000be50030020008e400056710e48324c700000047f505ee000000000200000047fa00028000010000000000000000eb000000
 * Source port: 17, Destination port: 200
 * Data: 0x23456789ab010a1b2c3d4e5f810070648999019a0008e400056710e48324c700000047f505ee000000000200000047fa00028000010000000000000000eb
 *
 * Creating UC packet to trap sa=da
  tx 1 psrc=1 data=0x80010000000000eb0000000000eb81008001ffff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f20
 *
 * Received packets on unit 0 should be:
 * Source port: 1, Destination port: 201
 * Data: 0x23456789ab020a1b2c3d4e5f810070648999019a0000e480056723e42619b900000064a7f37a000000000200000047fa00030000018045000000000000eb
 *
 * Creating mc packet to do l2 mc fwd
  tx 1 psrc=1 data=0x8001ff00000000eb0000000000eb81008001ffff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f20
 *
 * Received packets on unit 0 should be:
 * Source port: 1, Destination port: 200
 * Data: 0x23456789ab030a1b2c3d4e5f810070648999019a0000e404056730e4c918e9000000749f184c000000000200000047fa0002800001000000ff00000000eb
 * Source port: 1, Destination port: 200
 * Data: 0x23456789ab020a1b2c3d4e5f810070648999019a0000e404056720e4c918e9000000749f184c000000000200000047fa0002800001000000ff00000000eb
 *
 config delete tm_port_header_type_out_200.0
 config delete tm_port_header_type_out_201.0
 0: tr 141 NoInit=1
 config add custom_feature_init_verify=1
 config delete custom_feature_multithread_en*
 config delete custom_feature_kbp_multithread_en*
 0: tr 141 NoDeinit=1
 * Test Scenario - end
 *
 */

struct dnx_tunnel_l2_external_cpu_info_t
{
    /*
     * Remote encapsulation information
     */
    bcm_port_t remote_port1;
    bcm_port_t remote_port2;
    bcm_if_t l2_remote_arp_intf[3];
    bcm_mac_t l2_remote_arp_src_mac;
    bcm_mac_t l2_remote_arp_dst_mac_fwd;
    bcm_mac_t l2_remote_arp_dst_mac_trap;
    bcm_mac_t l2_remote_arp_dst_mac_snoop;
    int l2_remote_tpid;
    int l2_remote_vlan;
    int l2_remote_ethertype;
    /*
     * Incoming packet specification
     */
    bcm_port_t src_port;
    bcm_if_t intf_in;
    bcm_mac_t intf_in_mac_address;
    int vrf;
    bcm_ip_t dip_fwd;
    bcm_ip_t dip_fwd_mask;
    bcm_ip_t dip_mc_group;
    int fec_id_enc;
    bcm_multicast_t mc_group;
    /*
     * General config
     */
    uint8 preserve_trap;
    int snoop_trap_id;
    int rcpu_trap_id;
};

dnx_tunnel_l2_external_cpu_info_t l2_external_cpu_info =
    /*
     * ports : out_port1 | out_port2 - filled by input
     */
{ 0, 0,
    /*
     * l2_remote_arp_intf[3] - allocated WITH_ID
     */
    {0x5671, 0x5672, 0x5673},
    /*
     * l2_remote_arp_src_mac
     */
    {0x0A, 0x1B, 0x2C, 0x3D, 0x4E, 0x5F},
    /*
     * l2_remote_arp_dst_mac_fwd | l2_remote_arp_dst_mac_trap | l2_remote_arp_dst_mac_snoop
     */
    {0x23, 0x45, 0x67, 0x89, 0xAB, 0x01}, {0x23, 0x45, 0x67, 0x89, 0xAB, 0x02}, {0x23, 0x45, 0x67, 0x89, 0xAB, 0x03},
    /*
     * l2_remote_tpid
     */
    0x8100,
    /*
     * l2_remote_vlan
     */
    100,
    /*
     * l2_remote_ethertype
     */
    0x8999,
    /*
     * src_port - filled by input
     */
    0,
    /*
     * intf_in
     */
    20,
    /*
     * intf_in_mac_address
     */
    {0x00, 0x0c, 0x00, 0x02, 0x00, 0x00},
    /*
     * vrf
     */
    1,
    /*
     * dip_fwd | dip_fwd_mask | dip_mc_group
     */
    0xA0A1A1A3 /* 160.161.161.163 */, 0xffffffff, 0xA0A1A1A2 /* 160.161.161.162 */ ,
    /*
     * fec_id_enc
     */
    0x2000C351,
    /*
     * mc_group
     */
    111,
    /*
     * preserve_trap
     */
    1
};

struct cint_ipv4_tunnel_info_s
{
    bcm_gport_t tunnel_id;                /* IPv4 tunnel ID */
    int tunnel_fec_id;                    /* FEC id */
    bcm_ip_t     tunnel_ipv4_sip;         /* Tunnel SIP */
    bcm_ip_t     tunnel_ipv4_dip;         /* Tunnel DIP */
    bcm_tunnel_type_t tunnel_type;        /* tunnel type */
    int tunnel_ttl;                       /* Ip tunnel header TTL */
    int tunnel_dscp;                      /* Ip tunnel header differentiated services code point */
};

cint_ipv4_tunnel_info_s cint_ipv4_tunnel_info =
{
        /*
         * tunnel_id
         */
        0,
        /*
         * tunnel_fec_id
         */
        0x2000C351,
        /*
         * tunnel_ipv4_sip
         */
        0xA0000013, /* 160.0.0.19 */
        /*
         * tunnel_ipv4_dip
         */
        0xA1000011, /* 161.0.0.17 */
        /*
         * tunnel type
         */
        bcmTunnelTypeIpAnyIn4,
        /*
         * tunnel_ttl
         */
        64,
        /*
         * tunnel_dscp
         */
        10
};

/*
 * Snoop any packet that is going through src_port to remote CPU
 */
int
l2_external_cpu_snoop_by_src_port(
    int unit)
{
    bcm_mirror_destination_t mirror_dest;
    bcm_rx_trap_config_t trap_config_snoop;
    int is_snoop;
    int snoop_cmnd;
    int trap_code;
    int flags = 0;
    int trap_strength = 0;
    int snoop_strength = 3;
    bcm_field_group_info_t fg_info;
    bcm_field_group_attach_info_t attach_info;
    bcm_field_entry_info_t ent_info;
    void *dest_char;
    bcm_gport_t snoop_trap_gport_id;
    bcm_field_group_t cint_in_port_qaul_fg_id = 0;
    bcm_field_entry_t ent1_id;
    bcm_mirror_header_info_t mirror_header_info;
    bcm_gport_t gport_tunnel_temp;      /* mirror header info works with GPORTs */


    /*
     * Create a new snoop command to be associated with the new trap and OutLif
     */
    bcm_mirror_destination_t_init(&mirror_dest);
    mirror_dest.gport = l2_external_cpu_info.remote_port1;
    mirror_dest.flags = BCM_MIRROR_DEST_IS_SNOOP;
    /* Add trap FHEI preserve */
    mirror_dest.packet_control_updates.valid = BCM_MIRROR_PKT_HEADER_UPDATE_FABRIC_HEADER_EDITING;

    BCM_IF_ERROR_RETURN_MSG(bcm_mirror_destination_create(unit, &mirror_dest), "");
    /*
     * Set mirror header info (keep original headers if required)
     */
    flags = BCM_MIRROR_DEST_IS_SNOOP;
    if (l2_external_cpu_info.preserve_trap)
    {
        flags |= BCM_MIRROR_DEST_EGRESS_ADD_ORIG_SYSTEM_HEADER;
    }

    BCM_L3_ITF_LIF_TO_GPORT_TUNNEL(gport_tunnel_temp, l2_external_cpu_info.l2_remote_arp_intf[2]);
    bcm_mirror_header_info_t_init(&mirror_header_info);
    mirror_header_info.tm.out_vport = gport_tunnel_temp;
    mirror_header_info.tm.src_sysport = l2_external_cpu_info.src_port;
    BCM_IF_ERROR_RETURN_MSG(bcm_mirror_header_info_set(unit, flags, mirror_dest.mirror_dest_id, &mirror_header_info), "");

    /*
     * Check if snoop was created
     */
    is_snoop = BCM_GPORT_IS_MIRROR_SNOOP(mirror_dest.mirror_dest_id);
    if (!is_snoop)
    {
        printf("Error. Could not create snoop.\n");
        return -1;
    }

    /*
     * Get the snoop command
     */
    snoop_cmnd = BCM_GPORT_MIRROR_GET(mirror_dest.mirror_dest_id);

    /*
     * Create a new trap
     */
    flags = 0;
    BCM_IF_ERROR_RETURN_MSG(bcm_rx_trap_type_create(unit, flags, bcmRxTrapUserDefine, &trap_code), "");
    l2_external_cpu_info.snoop_trap_id = trap_code;
    /*
     * Setup the new trap
     */
    bcm_rx_trap_config_t_init(&trap_config_snoop);
    trap_config_snoop.trap_strength = 0;
    trap_config_snoop.snoop_cmnd = snoop_cmnd;

    BCM_IF_ERROR_RETURN_MSG(bcm_rx_trap_set(unit, trap_code, trap_config_snoop), "");

    /*
     * Encode trap, trap strength and snoop strength as a gport
     */
    BCM_GPORT_TRAP_SET(snoop_trap_gport_id, trap_code, trap_strength, snoop_strength);

    /*
     * Create and attach TCAM group in iPMF1
     */
    bcm_field_group_info_t_init(&fg_info);
    fg_info.fg_type = bcmFieldGroupTypeTcam;
    fg_info.stage = bcmFieldStageIngressPMF1;
    fg_info.nof_quals = 1;
    fg_info.qual_types[0] = bcmFieldQualifyInPort;
    fg_info.nof_actions = 1;
    fg_info.action_types[0] = bcmFieldActionSnoop;

    printf("Creating first group\n");
    dest_char = &(fg_info.name[0]);
    sal_strncpy_s(dest_char, "In_port_qual", sizeof(fg_info.name));
    BCM_IF_ERROR_RETURN_MSG(bcm_field_group_add(unit, 0, &fg_info, &cint_in_port_qaul_fg_id), "");

    /*
     * Attach the FG to context
     */
    bcm_field_group_attach_info_t_init(&attach_info);

    attach_info.key_info.nof_quals = 1;
    attach_info.key_info.qual_types[0] = bcmFieldQualifyInPort;
    attach_info.payload_info.nof_actions = 1;
    attach_info.payload_info.action_types[0] = bcmFieldActionSnoop;
    attach_info.key_info.qual_info[0].input_type = bcmFieldInputTypeMetaData;
    attach_info.key_info.qual_info[0].input_arg = 0;
    attach_info.key_info.qual_info[0].offset = 0;

    printf("Attaching field group\n");
    BCM_IF_ERROR_RETURN_MSG(bcm_field_group_context_attach(unit, 0, cint_in_port_qaul_fg_id, 0 , &attach_info), "");

    bcm_field_entry_info_t_init(&ent_info);
    ent_info.priority = 1;
    ent_info.nof_entry_quals = 1;
    ent_info.entry_qual[0].type = bcmFieldQualifyInPort;
    ent_info.entry_qual[0].value[0] = l2_external_cpu_info.src_port;
    ent_info.entry_qual[0].mask[0] = 0x1ff;

    ent_info.nof_entry_actions = 1;
    ent_info.entry_action[0].type = bcmFieldActionSnoop;
    ent_info.entry_action[0].value[0] = snoop_trap_gport_id;

    printf("Adding Entry\n");
    BCM_IF_ERROR_RETURN_MSG(bcm_field_entry_add(unit, 0, cint_in_port_qaul_fg_id, &ent_info, &ent1_id), "");

    return BCM_E_NONE;
}

/*
 * Init remark profile to be later used for outer LL entry
 */
int
arp_plus_ac_qos(
    int unit,
    int pcp,
    int dei,
    int *qos_egress)
{
    char error_msg[200]={0,};
    int opcode_egress;
    bcm_qos_map_t l2_eg_map;
    int flags;

    /*
     * Create Egress Remark profile which is used by VLAN-Port (or ARP VLAN translation)
     */
    flags = BCM_QOS_MAP_EGRESS | BCM_QOS_MAP_REMARK;
    BCM_IF_ERROR_RETURN_MSG(bcm_qos_map_create(unit, flags, qos_egress), "in L3 egress");

    /*
     * Create Egress opcode which is later used to set the required pcp mapping
     */
    flags = BCM_QOS_MAP_EGRESS | BCM_QOS_MAP_REMARK | BCM_QOS_MAP_OPCODE;
    BCM_IF_ERROR_RETURN_MSG(bcm_qos_map_create(unit, flags, &opcode_egress), "in egress l3 opcode");

    /*
     * Clear structure
     */
    bcm_qos_map_t_init(&l2_eg_map);

    /*
     * Map Egress Remark profile to L2 Opcode
     */
    l2_eg_map.opcode = opcode_egress;
    flags = BCM_QOS_MAP_L2 | BCM_QOS_MAP_REMARK | BCM_QOS_MAP_OPCODE;
    BCM_IF_ERROR_RETURN_MSG(bcm_qos_map_add(unit, flags, &l2_eg_map, *qos_egress), "in egress l2 opcode");
    /*
     * Set L2 opcode mappings
     */
    int idx;
    for (idx = 0; idx < 256; idx++)
    {
        flags = BCM_QOS_MAP_L2 | BCM_QOS_MAP_REMARK;

        bcm_qos_map_t_init(&l2_eg_map);
        /*
         * Input internal priority NWK-QOS
         */
        l2_eg_map.int_pri = idx;
        /*
         * Input color
         */
        l2_eg_map.color = 0;

        /*
         * Set egress PCP and DEI
         */
        l2_eg_map.pkt_pri = pcp;
        l2_eg_map.pkt_cfi = dei;

        snprintf(error_msg, sizeof(error_msg), "in L2 egress, profile(0x%08x)", opcode_egress);
        BCM_IF_ERROR_RETURN_MSG(bcm_qos_map_add(unit, flags, &l2_eg_map, opcode_egress), error_msg);
    }

    return BCM_E_NONE;
}

/*
 * create RCPU tunnel and vlan editing
 * Relevant for JR2 device only
 * In JR2 RCPU tunnel is done by Routing processing of Intf and ARP+AC object.
 */
int
create_rcpu_tunnel(
    int unit,
    int tunnel_index,
    int qos_egress)
{
    int eth_out_rif;
    int flags;
    int arp_outlif;
    bcm_gport_t arp_ac_gport;
    bcm_mac_t dst_mac;

    eth_out_rif = 100 + tunnel_index;

    /*
     * Create Eth rif for outer Ethernet SRC MAC
     */
    BCM_IF_ERROR_RETURN_MSG(intf_eth_rif_create(unit, eth_out_rif, l2_external_cpu_info.l2_remote_arp_src_mac), "intf_out");

    /*
     * Create ARP+AC entry for outer Ethernet and set its properties
     * ARP+AC indication is flag BCM_L3_FLAGS2_VLAN_TRANSLATION
     */
    switch (tunnel_index)
    {
        case 0:
            dst_mac = l2_external_cpu_info.l2_remote_arp_dst_mac_fwd;
            break;
        case 1:
            dst_mac = l2_external_cpu_info.l2_remote_arp_dst_mac_trap;
            break;
        case 2:
            dst_mac = l2_external_cpu_info.l2_remote_arp_dst_mac_snoop;
            break;
    }
    BCM_IF_ERROR_RETURN_MSG(l3__egress_only_encap__create_inner(unit, BCM_L3_WITH_ID, &l2_external_cpu_info.l2_remote_arp_intf[tunnel_index], dst_mac,
                                             eth_out_rif, 0, BCM_L3_FLAGS2_VLAN_TRANSLATION), "create egress object ARP only");

    /*
     * for arp+ac, bcm_vlan_port_translation_set is the API which sets the VLAN editing part in
     * the ARP+AC entry in EEDB.
     * The following part it used to configure vlan and QOS editing on the outer LL
     */
    arp_outlif = BCM_L3_ITF_VAL_GET(l2_external_cpu_info.l2_remote_arp_intf[tunnel_index]);
    BCM_GPORT_SUB_TYPE_L3_VLAN_TRANSLATION_SET(arp_ac_gport, arp_outlif);
    BCM_GPORT_VLAN_PORT_ID_SET(arp_ac_gport, arp_ac_gport);

    /*
     * Connect ARP VLAN translation to VLAN-Translation Command 3 which always add VLAN
     */
    int vlan_edit_profile = 3;
    bcm_vlan_port_translation_t port_trans;
    bcm_vlan_port_translation_t_init(&port_trans);
    port_trans.gport = arp_ac_gport;
    port_trans.vlan_edit_class_id = vlan_edit_profile;
    port_trans.new_outer_vlan = l2_external_cpu_info.l2_remote_vlan;
    port_trans.flags = BCM_VLAN_ACTION_SET_EGRESS;
    BCM_IF_ERROR_RETURN_MSG(bcm_vlan_port_translation_set(unit, &port_trans), "");

    /*
     * Create action ID
     */
    int action_id_1;
    BCM_IF_ERROR_RETURN_MSG(bcm_vlan_translate_action_id_create(unit, BCM_VLAN_ACTION_SET_EGRESS, &action_id_1), "");

    /*
     * Set translation action
     */
    bcm_vlan_action_set_t action;
    bcm_vlan_action_set_t_init(&action);
    action.outer_tpid = l2_external_cpu_info.l2_remote_tpid;
    action.dt_outer = bcmVlanActionArpVlanTranslateAdd;
    action.dt_outer_pkt_prio = bcmVlanActionAdd;
    BCM_IF_ERROR_RETURN_MSG(bcm_vlan_translate_action_id_set(unit, BCM_VLAN_ACTION_SET_EGRESS, action_id_1, &action), "");

    /*
     * Set translation action class (map edit_profile & tag_format to action_id)
     */
    bcm_vlan_translate_action_class_t action_class;
    bcm_vlan_translate_action_class_t_init(&action_class);
    action_class.vlan_edit_class_id = vlan_edit_profile;
    action_class.tag_format_class_id = 0;       /* Untagged */
    action_class.vlan_translation_action_id = action_id_1;
    action_class.flags = BCM_VLAN_ACTION_SET_EGRESS;
    BCM_IF_ERROR_RETURN_MSG(bcm_vlan_translate_action_class_set(unit, &action_class), "");

    /*
     * Connect ARP VLAN translation to Remark profile which is used to decide the PCP value on VLAN tag
     */
    BCM_IF_ERROR_RETURN_MSG(bcm_qos_port_map_set(unit, arp_ac_gport, -1, qos_egress), "");

    return BCM_E_NONE;
}

/*
 * Configure RCPU encapsulation
 */
int
l2_external_cpu_setup(
    int unit)
{
    int i;
    int pcp = 3;
    int dei = 1;
    int qos_egress;

    /*
     * FTMH Ethertype is device configuration
     */
    BCM_IF_ERROR_RETURN_MSG(bcm_switch_control_set(unit, bcmSwitchFtmhEtherType, l2_external_cpu_info.l2_remote_ethertype),
        "with type=bcmSwitchFTMHEthertype");

    /*
     * Create Eth rif for outer Ethernet SRC MAC
     */
    BCM_IF_ERROR_RETURN_MSG(arp_plus_ac_qos(unit, pcp, dei, &qos_egress), "intf_out");

    for (i = 0; i < 3; ++i)
    {
        BCM_IF_ERROR_RETURN_MSG(create_rcpu_tunnel(unit, i, qos_egress), "");

    }

    return BCM_E_NONE;

}

/*
 * Add ip forwarding into remote CPU
 */
int
l2_external_cpu_uc_forwarding(
    int unit)
{

    int fec_flags2 = 0, encoded_fec = 0;
    bcm_gport_t gport = 0;
    char *proc_name;

    proc_name = "l2_external_cpu_uc_forwarding";

    if (*(dnxc_data_get(unit, "l3", "fwd", "host_entry_support", NULL)))
    {
        /*
        * Create l3 forwarding entry for the mc_group
        */
        BCM_IF_ERROR_RETURN_MSG(add_host_ipv4(unit, l2_external_cpu_info.dip_fwd, l2_external_cpu_info.vrf, 0,
                        BCM_L3_ITF_VAL_GET(l2_external_cpu_info.l2_remote_arp_intf[0]),
                        l2_external_cpu_info.remote_port1), "");
        printf("Configured ipv4 forwarding to port: %d, encap: %d\n", l2_external_cpu_info.remote_port1, BCM_L3_ITF_VAL_GET(l2_external_cpu_info.l2_remote_arp_intf[0]));
    }
    else
    {

        /**  Create FEC and set its properties */
        BCM_GPORT_LOCAL_SET(gport, l2_external_cpu_info.remote_port1);

        if(*dnxc_data_get(unit, "l3", "feature", "separate_fwd_rpf_dbs", NULL))
        {
            fec_flags2 |= BCM_L3_FLAGS2_FWD_ONLY;
        }

        BCM_IF_ERROR_RETURN_MSG(l3__egress_only_fec__create_inner(unit, l2_external_cpu_info.fec_id_enc+2, 1, BCM_L3_ITF_VAL_GET(l2_external_cpu_info.l2_remote_arp_intf[0]), gport, 0,
                                            fec_flags2, 0, 0, &encoded_fec), "create egress object FEC only");

        printf("%s: encoded_fec is 0x%08X.\r\n", proc_name, encoded_fec);

        BCM_IF_ERROR_RETURN_MSG(add_route_ipv4(unit, l2_external_cpu_info.dip_fwd, l2_external_cpu_info.dip_fwd_mask, l2_external_cpu_info.vrf, encoded_fec), "");
    }
    return BCM_E_NONE;

}

/*
 * Trap bcmRxTrapLinkLayerSaEqualsDa packets to remote CPU
 */
int
l2_external_cpu_uc_trap_set(
    int unit)
{

    char error_msg[200]={0,};
    bcm_rx_trap_config_t config;
    int flags = 0;
    int trap_id = 0;

    sal_memset(&config, 0, sizeof(config));

    /*
     * for port dest change
     */
    config.flags = BCM_RX_TRAP_UPDATE_DEST | BCM_RX_TRAP_UPDATE_ENCAP_ID;
    if (l2_external_cpu_info.preserve_trap)
    {
        config.flags |= BCM_RX_TRAP_TRAP;
    }

    config.trap_strength = 7;
    config.dest_port = l2_external_cpu_info.remote_port2;

    bcm_gport_t gport_tunnel_temp;      /* rx trap works with GPORTs */
    BCM_L3_ITF_LIF_TO_GPORT_TUNNEL(gport_tunnel_temp, l2_external_cpu_info.l2_remote_arp_intf[1]);
    config.encap_id = gport_tunnel_temp;

    config.snoop_cmnd = 0;
    config.snoop_strength = 0;

    flags = 0;
    snprintf(error_msg, sizeof(error_msg), "trap id %d", trap_id);
    BCM_IF_ERROR_RETURN_MSG(bcm_rx_trap_type_create(unit, flags, bcmRxTrapLinkLayerSaEqualsDa, &trap_id), error_msg);
    l2_external_cpu_info.rcpu_trap_id = trap_id;

    BCM_IF_ERROR_RETURN_MSG(bcm_rx_trap_set(unit, trap_id, &config), "");

    printf("Configured trap to port: %d, encap: %d\n", l2_external_cpu_info.remote_port2, BCM_L3_ITF_VAL_GET(l2_external_cpu_info.l2_remote_arp_intf[1]));

    return BCM_E_NONE;

}

/*
 * Add ip forwarding into MC group of 2 RCPU members
 */
int
l2_external_cpu_mc(
    int unit)
{
    char error_msg[200]={0,};
    bcm_error_t rv;
    int fec_flags2 = 0;
    int flags;

    if (*dnxc_data_get(unit, "multicast", "params", "mcdb_formats_v2", NULL)) {
        flags = BCM_MULTICAST_INGRESS_GROUP | BCM_MULTICAST_ELEMENT_STATIC;
    } else {
        flags = BCM_MULTICAST_INGRESS_GROUP;
    }
    if (*dnxc_data_get(unit, "multicast", "params", "mcdb_formats_v2", NULL)) {
        rv = bcm_multicast_group_destroy(unit, flags, l2_external_cpu_info.mc_group);
        if (rv != BCM_E_NONE)
        {
            printf("Warning, in mc destroy, mc_group %d \n", l2_external_cpu_info.mc_group);
        }
    } else {
        rv = bcm_multicast_destroy(unit, l2_external_cpu_info.mc_group);
        if (rv != BCM_E_NONE)
        {
            printf("Warning, in mc destroy, mc_group %d \n", l2_external_cpu_info.mc_group);
        }
    }

    flags |= BCM_MULTICAST_WITH_ID;
    snprintf(error_msg, sizeof(error_msg), "in mc create, flags %d mc_group %d", flags, l2_external_cpu_info.mc_group);
    BCM_IF_ERROR_RETURN_MSG(bcm_multicast_create(unit, flags, &l2_external_cpu_info.mc_group), error_msg);

    printf("mc group created %d \n", l2_external_cpu_info.mc_group);

    bcm_gport_t gport;
    BCM_GPORT_LOCAL_SET(gport, l2_external_cpu_info.remote_port1);

    bcm_multicast_replication_t replications[2];
    replications[0].encap1 = BCM_L3_ITF_VAL_GET(l2_external_cpu_info.l2_remote_arp_intf[1]);
    replications[0].port = gport;
    replications[1].encap1 = BCM_L3_ITF_VAL_GET(l2_external_cpu_info.l2_remote_arp_intf[2]);
    replications[1].port = gport;
    BCM_IF_ERROR_RETURN_MSG(bcm_multicast_add(unit, l2_external_cpu_info.mc_group, flags, 2, &replications), "");

    /*
     * Configure fec entry for encapsulation flow
     */
    bcm_gport_t mc_gport;
    BCM_GPORT_MCAST_SET(mc_gport, l2_external_cpu_info.mc_group);

    if(*dnxc_data_get(unit, "l3", "feature", "separate_fwd_rpf_dbs", NULL))
    {
        fec_flags2 |= BCM_L3_FLAGS2_FWD_ONLY;
    }

    BCM_IF_ERROR_RETURN_MSG(l3__egress_only_fec__create(unit, l2_external_cpu_info.fec_id_enc, 0, 0, mc_gport, 0, fec_flags2),
        "create egress object FEC only");

    if (*(dnxc_data_get(unit, "l3", "fwd", "host_entry_support", NULL)))
    {
        /*
        * Create l3 forwarding entry for the mc_group
        */
        BCM_IF_ERROR_RETURN_MSG(add_host_ipv4(unit, l2_external_cpu_info.dip_mc_group, l2_external_cpu_info.vrf,
                        l2_external_cpu_info.fec_id_enc, 0, 0), "");

        printf("Configured ipv4 mc group to port: %d, encaps: %d and %d\n", l2_external_cpu_info.remote_port1,
                BCM_L3_ITF_VAL_GET(l2_external_cpu_info.l2_remote_arp_intf[1]),
                BCM_L3_ITF_VAL_GET(l2_external_cpu_info.l2_remote_arp_intf[2]));
    }
    else
    {
        BCM_IF_ERROR_RETURN_MSG(add_route_ipv4(unit,l2_external_cpu_info.dip_mc_group, l2_external_cpu_info.dip_fwd_mask, l2_external_cpu_info.vrf, l2_external_cpu_info.fec_id_enc), "");
    }
    return BCM_E_NONE;

}


/*
 * ip forwarding basic configuration
 */
int
ip_forwarding_ingress_configuration(
    int unit)
{

    /*
     * Configure port properties for this application
     */
    /*
     * Set In-Port to In ETh-RIF
     */
    BCM_IF_ERROR_RETURN_MSG(in_port_intf_set(unit, l2_external_cpu_info.src_port, l2_external_cpu_info.intf_in), "intf_in");

    /*
     * Configure L3 interfaces
     */
    l3_ingress_intf ingr_itf;
    l3_ingress_intf_init(&ingr_itf);
    /*
     * Create ETH-RIF and set its properties
     */
    BCM_IF_ERROR_RETURN_MSG(intf_eth_rif_create(unit, l2_external_cpu_info.intf_in, l2_external_cpu_info.intf_in_mac_address), "intf_in");

    /*
     * Set Incoming ETH-RIF properties
     */
    ingr_itf.intf_id = l2_external_cpu_info.intf_in;
    ingr_itf.vrf = l2_external_cpu_info.vrf;
    BCM_IF_ERROR_RETURN_MSG(intf_ingress_rif_set(unit, &ingr_itf), "intf_out");

    return BCM_E_NONE;
}

/*
 * Create ipv4 tunnel
 * Create FEC and add ipv4 host entry
 */
int
l2_external_cpu_tunnel_create(
    int unit)
{
    int fec_id = 0;
    bcm_l3_intf_t l3_intf;
    bcm_tunnel_initiator_t tunnel_init;
    int fec_flags2 = 0;

    bcm_l3_intf_t_init(&l3_intf);

    bcm_tunnel_initiator_t_init(&tunnel_init);
    tunnel_init.dip = cint_ipv4_tunnel_info.tunnel_ipv4_dip;
    tunnel_init.sip = cint_ipv4_tunnel_info.tunnel_ipv4_sip;
    tunnel_init.flags = 0;
    tunnel_init.dscp = cint_ipv4_tunnel_info.tunnel_dscp;
    tunnel_init.egress_qos_model.egress_qos = bcmQosEgressModelPipeNextNameSpace;
    tunnel_init.type = cint_ipv4_tunnel_info.tunnel_type;
    tunnel_init.encap_access = bcmEncapAccessTunnel2;
    tunnel_init.l3_intf_id = l2_external_cpu_info.l2_remote_arp_intf[0];
    tunnel_init.outlif_counting_profile = BCM_STAT_LIF_COUNTING_PROFILE_NONE;
    BCM_IF_ERROR_RETURN_MSG(bcm_tunnel_initiator_create(unit, &l3_intf, tunnel_init), "");
    cint_ipv4_tunnel_info.tunnel_id = tunnel_init.tunnel_id;

    BCM_IF_ERROR_RETURN_MSG(get_first_fec_in_range_which_not_in_ecmp_range(unit, 0, 0, &cint_ipv4_tunnel_info.tunnel_fec_id), "");

    if(*dnxc_data_get(unit, "l3", "feature", "separate_fwd_rpf_dbs", NULL))
    {
        fec_flags2 |= BCM_L3_FLAGS2_FWD_ONLY;
    }
    /*
     * Create FEC
     */
    BCM_IF_ERROR_RETURN_MSG(l3__egress_only_fec__create(unit, cint_ipv4_tunnel_info.tunnel_fec_id, l3_intf.l3a_intf_id, 0, l2_external_cpu_info.remote_port1, 0, fec_flags2), "");

    BCM_L3_ITF_SET(&fec_id, BCM_L3_ITF_TYPE_FEC, cint_ipv4_tunnel_info.tunnel_fec_id);
    /*
     * Add Ipv4 host entry
     */
    BCM_IF_ERROR_RETURN_MSG(add_host_ipv4(unit, l2_external_cpu_info.dip_fwd,l2_external_cpu_info.vrf, fec_id, 0, 0), "");

    return BCM_E_NONE;
}

/*
 * main function to create all forward-trap-snoop scenarios combined.
 * preserve_trap parameter is used to indicate that in case of trap/snoop, the redirected packet will
 * contain system headers stack that includes FHEI header with trap/snoop command information.
 */
int
dnx_tunnel_l2_external_cpu_run_all(
    int unit,
    bcm_port_t src_port,
    bcm_port_t out_port1,
    bcm_port_t out_port2,
    uint8 preserve_trap,
    uint8 create_ipv4_tunnel)
{


    l2_external_cpu_info.src_port = src_port;
    l2_external_cpu_info.remote_port1 = out_port1;
    l2_external_cpu_info.remote_port2 = out_port2;
    l2_external_cpu_info.preserve_trap = preserve_trap;

    BCM_IF_ERROR_RETURN_MSG(get_first_fec_in_range_which_not_in_ecmp_range(unit, 0, 0, &l2_external_cpu_info.fec_id_enc), "");

    /*
     * Configure the incoming packet to do IP forwarding
     */
    BCM_IF_ERROR_RETURN_MSG(ip_forwarding_ingress_configuration(unit), "");

    /*
     * Configure remote cpu encapsulation
     */
    printf("l2_external_cpu_setup\n");
    BCM_IF_ERROR_RETURN_MSG(l2_external_cpu_setup(unit), "");

    if (create_ipv4_tunnel == 1)
    {
        printf("l2_external_cpu_tunnel_create\n");
        BCM_IF_ERROR_RETURN_MSG(l2_external_cpu_tunnel_create(unit), "");
    }

    if (!create_ipv4_tunnel)
    {
        /*
         * Set ip uc forwarding to l2_remote_arp_intf[0] & remote_port1
         */
        printf("l2_external_cpu_uc_forwarding\n");
        BCM_IF_ERROR_RETURN_MSG(l2_external_cpu_uc_forwarding(unit), "");
    }

    /*
     * Set snooping according to src port to l2_remote_arp_intf[2] & remote_port1
     */
    printf("l2_external_cpu_snoop_by_src_port \n");
    BCM_IF_ERROR_RETURN_MSG(l2_external_cpu_snoop_by_src_port(unit), "");

    /*
     * Set trapping according to SA=DA to l2_remote_arp_intf[1] & remote_port2
     */
    printf("l2_external_cpu_uc_trap_set\n");
    BCM_IF_ERROR_RETURN_MSG(l2_external_cpu_uc_trap_set(unit), "");
    if (!create_ipv4_tunnel)
    {
        /*
         * Set ip forwarding to MC group of l2_remote_arp_intf[1], l2_remote_arp_intf[2] & remote_port1
         */
        printf("l2_external_cpu_mc_forwarding\n");
        BCM_IF_ERROR_RETURN_MSG(l2_external_cpu_mc(unit), "");
    }
    return BCM_E_NONE;

}

int l2_external_cpu_uc_l2_forwarding(int unit) {
    bcm_l2_addr_t l2_addr;
    uint8 fwd_mac[6] = {0x00,0x00,0x00,0x00,0x00,0xeb};

    bcm_l2_addr_t_init(&l2_addr,fwd_mac,1);
    l2_addr.vid = 1;
    l2_addr.port = l2_external_cpu_info.remote_port1;
    l2_addr.flags = BCM_L2_STATIC;
    l2_addr.encap_id = BCM_L3_ITF_VAL_GET(l2_external_cpu_info.l2_remote_arp_intf[0]); /*outlif (not a gport)*/
    BCM_IF_ERROR_RETURN_MSG(bcm_l2_addr_add(unit, &l2_addr), "");

    return BCM_E_NONE;
}

int l2_external_cpu_mc_l2_forwarding(int unit) {
    bcm_error_t rv;
    uint8 fwd_mac[6] = {0xff,0x00,0x00,0x00,0x00,0xeb};
    bcm_l2_addr_t l2_addr;
    bcm_multicast_t mc_group = 111;
    int flags;
    bcm_gport_t gport;
    char error_msg[200]={0,};

    flags = BCM_MULTICAST_INGRESS_GROUP | BCM_MULTICAST_WITH_ID ;
    if (*dnxc_data_get(unit, "multicast", "params", "mcdb_formats_v2", NULL))
    {
        flags |= BCM_MULTICAST_ELEMENT_STATIC;
    }

    if (*dnxc_data_get(unit, "multicast", "params", "mcdb_formats_v2", NULL))
    {
        rv = bcm_multicast_group_destroy(unit, flags, mc_group);
    }
    else
    {
        rv = bcm_multicast_destroy(unit, mc_group);
    }
    if (rv != BCM_E_NONE)
    {
        printf("Warning, in mc destroy,  mc_group %d \n", mc_group);
    }

    snprintf(error_msg, sizeof(error_msg), "in mc create, flags %d mc_group %d", flags, mc_group);
    BCM_IF_ERROR_RETURN_MSG(bcm_multicast_create(unit, flags, &mc_group), error_msg);
    printf("mc group created %d, \n",mc_group);

    bcm_l2_addr_t_init(&l2_addr, fwd_mac, 1);
    l2_addr.vid = 1;
    l2_addr.flags = BCM_L2_STATIC | BCM_L2_MCAST;
    l2_addr.l2mc_group = mc_group;
    BCM_IF_ERROR_RETURN_MSG(bcm_l2_addr_add(unit, &l2_addr), "");

    BCM_GPORT_LOCAL_SET(gport, l2_external_cpu_info.remote_port1);
    bcm_multicast_replication_t replications[2];
    replications[0].encap1 = BCM_L3_ITF_VAL_GET(l2_external_cpu_info.l2_remote_arp_intf[1]);
    replications[0].port = gport;
    replications[1].encap1 = BCM_L3_ITF_VAL_GET(l2_external_cpu_info.l2_remote_arp_intf[2]);
    replications[1].port = gport;
    BCM_IF_ERROR_RETURN_MSG(bcm_multicast_add(unit, mc_group, flags, 2, &replications), "");

    return BCM_E_NONE;
}

int dnx_l2_fwd_external_cpu_run_all(
    int unit,
    bcm_port_t src_port,
    bcm_port_t out_port1,
    bcm_port_t out_port2)
{
    l2_external_cpu_info.src_port = src_port;
    l2_external_cpu_info.remote_port1 = out_port1;
    l2_external_cpu_info.remote_port2 = out_port2;
    l2_external_cpu_info.preserve_trap = 1;

    printf("l2_external_cpu_setup\n");
    BCM_IF_ERROR_RETURN_MSG(l2_external_cpu_setup(unit), "");

    printf("l2_external_cpu_uc_l2_forwarding\n");
    BCM_IF_ERROR_RETURN_MSG(l2_external_cpu_uc_l2_forwarding(unit), "");

    /*
     * Set snooping according to src port to l2_remote_arp_intf[2] & remote_port1
     */
    BCM_IF_ERROR_RETURN_MSG(l2_external_cpu_snoop_by_src_port(unit), "");

    printf("l2_external_cpu_uc_trap_set\n");
    BCM_IF_ERROR_RETURN_MSG(l2_external_cpu_uc_trap_set(unit), "");

    printf("l2_external_cpu_mc_l2_forwarding\n");
    BCM_IF_ERROR_RETURN_MSG(l2_external_cpu_mc_l2_forwarding(unit), "");

    return BCM_E_NONE;
}


/**
* \brief
*  Example to override the global_outlifs by the ePMF with any tunnel encapsulation pointers.
*  The ePMF CS is based on the out-port to the remote cpu.
*  The ePMF Qualifier is also based on the out-port to the remote cpu(Actual not needed in the example).
*
*  It's recommended the users to define thier own ePMF configurations based on their applications.
*
*/
int cint_field_external_cpu_tunnel_ptr_set_epmf(int unit, int * global_outlifs)
{
    bcm_field_ace_entry_info_t ace_entry_info;
    bcm_field_ace_format_info_t ace_format_info;
    bcm_field_ace_format_t ace_format_id;
    uint32 ace_entry_handle;

    bcm_field_group_attach_info_t attach_info;
    bcm_field_entry_info_t ent_info;
    bcm_field_context_info_t context_info;
    bcm_field_presel_entry_data_t p_data;
    bcm_field_group_info_t fg_info;
    bcm_field_presel_entry_id_t p_id;

    bcm_field_context_t context_id;
    bcm_field_presel_t presel_id = 60;
    bcm_field_group_t fg_id;
    bcm_field_entry_t epmf_entry_handle;

    int rcpu_port_profile = 3;
    void *dest_char;
    int idx;
    int is_epmf_ace_support = *(dnxc_data_get(unit, "field", "ace", "supported", NULL));

    /*
     * Create the ACE entry for updating the outLIFs in some devices
     */
    if (is_epmf_ace_support)
    {
        /** define ace action */
        bcm_field_ace_format_info_t_init(&ace_format_info);
        ace_format_info.nof_actions = 4;
        ace_format_info.action_types[0] = bcmFieldActionOutVport0Raw;
        ace_format_info.action_types[1] = bcmFieldActionOutVport1Raw;
        ace_format_info.action_types[2] = bcmFieldActionOutVport2Raw;
        ace_format_info.action_types[3] = bcmFieldActionOutVport3Raw;
        BCM_IF_ERROR_RETURN_MSG(bcm_field_ace_format_add(unit, 0, &ace_format_info, &ace_format_id), "");

        bcm_field_ace_entry_info_t_init(&ace_entry_info);
        ace_entry_info.nof_entry_actions = ace_format_info.nof_actions;
        ace_entry_info.entry_action[0].type = bcmFieldActionOutVport0Raw;
        ace_entry_info.entry_action[0].value[0] = global_outlifs[0];
        ace_entry_info.entry_action[1].type = bcmFieldActionOutVport1Raw;
        ace_entry_info.entry_action[1].value[0] = global_outlifs[1];
        ace_entry_info.entry_action[2].type = bcmFieldActionOutVport2Raw;
        ace_entry_info.entry_action[2].value[0] = global_outlifs[2];
        ace_entry_info.entry_action[3].type = bcmFieldActionOutVport3Raw;
        ace_entry_info.entry_action[3].value[0] = global_outlifs[3];
        BCM_IF_ERROR_RETURN_MSG(bcm_field_ace_entry_add(unit, 0, ace_format_id, &ace_entry_info, &ace_entry_handle), "");
    }

    /*
     * Context create
     */
    bcm_field_context_info_t_init(&context_info);
    dest_char = &(context_info.name[0]);
    sal_strncpy_s(dest_char, "External_CPU_Tunnel_Ptr_Set_ePMF_CTX", sizeof(context_info.name));
    BCM_IF_ERROR_RETURN_MSG(bcm_field_context_create(unit, 0, bcmFieldStageEgress, &context_info, &context_id), "");

    /** Set the preselectors. */
    bcm_field_presel_entry_id_info_init(&p_id);
    bcm_field_presel_entry_data_info_init(&p_data);

    p_id.presel_id = presel_id;
    p_id.stage = bcmFieldStageEgress;

    p_data.entry_valid = TRUE;
    p_data.context_id = context_id;
    p_data.nof_qualifiers = 1;
    p_data.qual_data[0].qual_type = bcmFieldQualifyPortClassPacketProcessing;
    p_data.qual_data[0].qual_arg = 0;
    p_data.qual_data[0].qual_value = rcpu_port_profile;
    p_data.qual_data[0].qual_mask = 7;
    BCM_IF_ERROR_RETURN_MSG(bcm_field_presel_set(unit, 0, &p_id, &p_data), "");

    printf("Presel (%d) was configured for stage(ePMF) context(%d)! \n", presel_id, context_id);

   
    /*
     * Add the FG.
     */
    bcm_field_group_info_t_init(&fg_info);

    fg_info.stage = bcmFieldStageEgress;
    fg_info.fg_type = bcmFieldGroupTypeTcam;
    fg_info.nof_quals = 1;
    fg_info.qual_types[0] = bcmFieldQualifyPortClassPacketProcessing;

    if (is_epmf_ace_support) {
        fg_info.nof_actions = 1;
        fg_info.action_types[0] = bcmFieldActionAceEntryId;
    } else {
        fg_info.nof_actions = 4;
        fg_info.action_types[0] = bcmFieldActionOutVport0Raw;
        fg_info.action_types[1] = bcmFieldActionOutVport1Raw;
        fg_info.action_types[2] = bcmFieldActionOutVport2Raw;
        fg_info.action_types[3] = bcmFieldActionOutVport3Raw;
    }
    dest_char = &(fg_info.name[0]);
    sal_strncpy_s(dest_char, "External_CPU_Tunnel_Ptr_Set_ePMF_GRP", sizeof(fg_info.name));
    BCM_IF_ERROR_RETURN_MSG(bcm_field_group_add(unit, 0, &fg_info, &fg_id), "");
    printf("Created TCAM field group (%d) in ePMF \n", fg_id);

    
    /*
     *Attach the FG to the context
     */
    bcm_field_group_attach_info_t_init(&attach_info);
    attach_info.key_info.nof_quals = fg_info.nof_quals;
    attach_info.payload_info.nof_actions = fg_info.nof_actions;
    attach_info.key_info.qual_types[0] = fg_info.qual_types[0];
    attach_info.key_info.qual_info[0].input_type = bcmFieldInputTypeMetaData;
    for(idx=0; idx < fg_info.nof_actions; idx++)
    {
        attach_info.payload_info.action_types[idx] = fg_info.action_types[idx];
    }

    BCM_IF_ERROR_RETURN_MSG(bcm_field_group_context_attach(unit, 0, fg_id, context_id, &attach_info), "");
    printf("Attached  FG (%d) to context (%d) Stage(ePMF)\n", fg_id, context_id);


    /*
     * Add an entry to update the outLIFs with the given values
     */
    bcm_field_entry_info_t_init(&ent_info);

    ent_info.nof_entry_quals = fg_info.nof_quals;
    
    ent_info.entry_qual[0].type = fg_info.qual_types[0];
    ent_info.entry_qual[0].value[0] = rcpu_port_profile;
    ent_info.entry_qual[0].mask[0] = 0x0;

    ent_info.nof_entry_actions = fg_info.nof_actions;
    if (is_epmf_ace_support) {
        ent_info.entry_action[0].type = fg_info.action_types[0];
        ent_info.entry_action[0].value[0] = ace_entry_handle;
    } else {
        for(idx=0 ; idx < fg_info.nof_actions; idx++)
        {
            ent_info.entry_action[idx].type = fg_info.action_types[idx];
            ent_info.entry_action[idx].value[0] = global_outlifs[idx];
        } 
    }

    BCM_IF_ERROR_RETURN_MSG(bcm_field_entry_add(unit, 0, fg_id, &ent_info, &epmf_entry_handle), "");
    printf("FG (%d) Stage(ePMF) , entry_add: handle(%d) \n", fg_id, epmf_entry_handle);

    return BCM_E_NONE;
}



/*
 * Example to trap to remote CPU with any tunnel encapsulation.
 * IPv4 tunnel is used in the example, so two pointers (IPv4_tunnel and ARP_AC)
 * are needed to update in the signal by ePMF.
 *
 * Please be noticed that it's recommended to override the outLIFs by TRAP configuration
 * when the required outLIFs for tunnel encapsulation are 2 or less.
 */
int
dnx_l2_external_cpu_ipv4_tunnel_main(
    int unit,
    bcm_port_t src_port,
    bcm_port_t out_port1,
    bcm_port_t out_port2)
{

    int global_outlifs[4] = {0};

    l2_external_cpu_info.src_port = src_port;
    l2_external_cpu_info.remote_port1 = out_port1;
    l2_external_cpu_info.remote_port2 = out_port2;  /** Port 2 is used remote CPU */
    l2_external_cpu_info.preserve_trap = TRUE; /** Keep the original system headers. */

    BCM_IF_ERROR_RETURN_MSG(get_first_fec_in_range_which_not_in_ecmp_range(unit, 0, 0, &l2_external_cpu_info.fec_id_enc), "");

    /*
     * Configure the incoming packet to do IP forwarding
     */
    BCM_IF_ERROR_RETURN_MSG(ip_forwarding_ingress_configuration(unit), "");

    /*
     * Configure remote cpu encapsulation
     */
    printf("l2_external_cpu_setup\n");
    BCM_IF_ERROR_RETURN_MSG(l2_external_cpu_setup(unit), "");

    printf("l2_external_cpu_tunnel_create\n");
    BCM_IF_ERROR_RETURN_MSG(l2_external_cpu_tunnel_create(unit), "");

    /*
     * Set trapping according to SA=DA to l2_remote_arp_intf[1] & remote_port2
     */
    printf("l2_external_cpu_uc_trap_set\n");
    BCM_IF_ERROR_RETURN_MSG(l2_external_cpu_uc_trap_set(unit), "");

    printf("cint_field_external_cpu_tunnel_ptr_set_epmf, ePMF to override the outLIFs\n");
    int rcpu_port_profile = 3;
    BCM_IF_ERROR_RETURN_MSG(bcm_port_class_set(unit, l2_external_cpu_info.remote_port2, bcmPortClassFieldEgressPacketProcessingPortCs, rcpu_port_profile),
        "bcmPortClassFieldEgressPacketProcessingPortCs");

    global_outlifs[0] = BCM_GPORT_TUNNEL_ID_GET(cint_ipv4_tunnel_info.tunnel_id);
    global_outlifs[1] = BCM_L3_ITF_VAL_GET(l2_external_cpu_info.l2_remote_arp_intf[0]);
    global_outlifs[2] = 0;
    global_outlifs[3] = 0;
    BCM_IF_ERROR_RETURN_MSG(cint_field_external_cpu_tunnel_ptr_set_epmf(unit, global_outlifs), "");

    return BCM_E_NONE;
}


