/*
 * $Id: cint_ip_ecmp_rpf_examples.c
 * Exp $
 This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 
 Copyright 2007-2022 Broadcom Inc. All rights reserved.
 */
/*
 * Example of a mc router scenario to pass MC ECMP Explicit RPF.
 *
 * Test Scenario - start
  config add pmf_sexem3_stage=IPMF3
  tr 141
  cint ../../../../src/examples/dnx/utility/cint_dnx_utils_global.c
  cint ../../../../src/examples/dnx/utility/cint_dnx_utils_l3.c
  cint ../../../../src/examples/dnx/cint_dnx_ip_route_basic.c
  cint ../../../../src/examples/dnx/cint_ipmc_route_basic.c
  cint ../../../../src/examples/dnx/cint_ip_route_rpf_basic.c
  cint ../../../../src/examples/dnx/cint_dnx_ecmp_basic.c
  cint ../../../../src/examples/dnx/l3/cint_dnx_ip_ecmp_rpf_examples.c
  cint ../../../../src/examples/dnx/field/cint_field_ecmp_rpf.c
  cint ../../../../src/examples/dnx/internal/field/cint_field_ecmp_rpf_test.c
  cint ../../../../src/examples/dnx/field/cint_field_always_hit_context.c
  cint ../../../../src/examples/dnx/field/cint_field_presel_fwd_layer.c
  cint ../../../../src/examples/dnx/internal/field/cint_field_ecmp_rpf_pmf_only.c
 *
  cint
 *
  field_ecmp_rpf_trap_pmf(0);
  bcm_field_context_t context_idx;
  cint_field_always_hit_context_main(0,15,bcmFieldStageIngressPMF3,&context_idx);
  field_ecmp_rpf_pmf(0,context_id,1);
  cint_ip_ecmp_mc_explicit_rpf_config(0,200,201,202);
  exit;
 *
 * ETH-RIF packet to pass Explicit ECMP MC RPF check
  tx 1 psrc = 200 data = 0x01005e020202000007000100810000640800450000350000000080009743c0800101e0020202000102030405060708090a
 * Received packets on unit 0 should be:
 * Data:
 * 0x01005e02020200123456789b81000033080045000035000000007f009843c0800101e0020202000102030405060708090a
 * 0x01005e02020200123456789a81000032080045000035000000007f009843c0800101e0020202000102030405060708090a
 * Test Scenario - end
 *
 * Example of a uc router scenario to pass UC ECMP Loose and Strict RPF.
 *
 * Test Scenario - start
  config add pmf_sexem3_stage=IPMF3
  tr 141
  cint ../../../../src/examples/sand/utility/cint_sand_utils_global.c
  cint ../../../../src/examples/sand/utility/cint_sand_utils_l3.c
  cint ../../../../src/examples/sand/cint_ip_route_basic.c
  cint ../../../../src/examples/sand/cint_ip_route_rpf_basic.c
  cint ../../../../src/examples/sand/cint_ecmp_basic.c
  cint ../../../../src/examples/dnx/l3/cint_ip_ecmp_rpf_examples.c
  cint ../../../../src/examples/dnx/field/cint_field_ecmp_rpf.c
  cint ../../../../src/examples/dnx/internal/field/cint_field_ecmp_rpf_test.c
  cint ../../../../src/examples/dnx/field/cint_field_always_hit_context.c
  cint ../../../../src/examples/dnx/field/cint_field_presel_fwd_layer.c
  cint ../../../../src/examples/dnx/internal/field/cint_field_ecmp_rpf_pmf_only.c
 *
  cint
 *
  field_ecmp_rpf_trap_pmf(0);
  bcm_field_context_t context_idx;
  cint_field_always_hit_context_main(0,16,bcmFieldStageIngressPMF3,&context_idx);
  field_ecmp_rpf_pmf(0,context_idx,0);
  cint_ip_ecmp_uc_explicit_rpf_config(0,200,201,202,203,15,20,30);
  exit;
 *
 * ETH-RIF packet to pass Loose RPF check
  tx 1 psrc = 200 data = 0x000c000200000000070001008100000f080045000035000000008000fa45c08001017fffff02000102030405060708090a
 * Received packet on unit 0 should be:
 * Data = 0x00000000cd1d000c000200ab81000064080045000035000000007f00fb45c08001017fffff02000102030405060708090a
 *
 * ETH-RIF packet to pass Strict RPF check
  tx 1 psrc = 200 data = 0x000c0002000000000700010081000014080045000035000000008000fa44c08001017fffff03000102030405060708090a
 * Received packet on unit 0 should be:
 * Data = 0x00000000cd27000c000200ab81000064080045000035000000007f00fb44c08001017fffff03000102030405060708090a
 * Test Scenario - end
 */

/******* Run example ******/

/*
 * packets will be routed from in_port to out-port1 and out-port2 if RPF check passes successfully.
 * This function defines several important entities for the packet forwarding:
 * 1. Mc group pointing to the out ports.
 * 2. Configure the FEC members of the ECMP groups (first 5 FECs are for the passing RPF check, latter 5 - for the failing RPF check)
 * 3. Create the ECMP groups.
 * 4. Link the ECMP group to the expected in interface ID.
 * 5. Create the FECs pointing to the MC group and the ECMP group with the needed BCM_L3_MC_RPF_EXPLCIT_RPF flag.
 * 6. Create the DIP L3 host entries resulting to the FECs with the correct LIF for the RPF check.
 *
 * Route:
 * packet to send:
 *  - in port = in_port
 *  - Vlan ID = 100
 *  - DA = 01:00:5E:02:02:02
 *  - DIP = 224.2.2.2
 * expected:
 *  - out port = out_port1/out_port2
 *  - vlan = 50/51
 *  - DA = 01:00:5E:02:02:02
 *  - SA = 00:12:34:56:78:9a / 00:12:34:56:78:9b
 *  TTL decremented
 *
 */
int
cint_ip_ecmp_mc_explicit_rpf_config(
    int unit,
    int in_port,
    int out_port1,
    int out_port2)
{
    int rv = BCM_E_NONE;
    int intf_in = 100;
    int intf_out = 50;
    int vrf = 5;
    int encap_id = 0x1234;
    char error_msg[200]={0,};
    int fec_id_fwd_pass;
    int fec_id_fwd_fail;
    int fec_id_sip;
    int fec_id_ecmp;
    int mc_group = 6000;
    int iter;
    int intf_array_pass[NOF_OF_MEMBERS_ECMP_GROUP/2];
    int intf_array_fail[NOF_OF_MEMBERS_ECMP_GROUP/2];
    bcm_gport_t mc_gport;
    bcm_gport_t gport;
    bcm_ip_t dip = 0xE0020202;
    bcm_ip_t sip = 0xC0800101;
    bcm_ip_t sip2 = 0xC0800102;
    uint32 dip_mask = 0xFFFFFFFF;
    uint32 sip_mask = 0x0;
    uint32 ecmp_group_pass = 300;
    uint32 ecmp_group_fail = 400;
    bcm_mac_t intf_in_mac_address = { 0x00, 0x0c, 0x00, 0x02, 0x00, 0x00 };     /* my-MAC */
    bcm_mac_t intf_out_mac_address = { 0x00, 0x12, 0x34, 0x56, 0x78, 0x9a };    /* my-MAC */
    bcm_mac_t arp_next_hop_mac = { 0x00, 0x00, 0x00, 0x00, 0xcd, 0x1d };        /* next_hop_mac */
    bcm_l3_egress_ecmp_t ecmp;
    l3_ingress_intf ingr_itf;
    l3_ingress_intf_init(&ingr_itf);
    dnx_utils_l3_fec_s fec_structure;
    dnx_utils_l3_fec_s_init(unit, 0x0, &fec_structure);

    cint_ipmc_info.out_ports[0] = out_port1;
    cint_ipmc_info.out_ports[1] = out_port2;

    BCM_IF_ERROR_RETURN_MSG(get_first_fec_in_range_which_not_in_ecmp_range(unit, 0, 0, &fec_id_fwd_pass), "");
    fec_id_fwd_fail = fec_id_fwd_pass + 2;
    fec_id_sip = fec_id_fwd_fail + 2;
    fec_id_ecmp = fec_id_sip + 2;

    if(*dnxc_data_get(unit, "l3", "feature", "separate_fwd_rpf_dbs", NULL))
    {
        BCM_IF_ERROR_RETURN_MSG(get_first_fec_in_range_which_not_in_ecmp_range(unit, 0, 1, &fec_id_sip), "");
    }
    /* 1. Configure traps for failed RPF lookup - SIP-based and Explicit. */
    rv = l3_dnx_ip_mc_rpf_config_traps(unit);
    if (rv == BCM_E_PARAM) {
        rv = BCM_E_NONE;
    }
    BCM_IF_ERROR_RETURN_MSG(rv, "");

    /* 2. Set In-Port to Eth-RIF */
    BCM_IF_ERROR_RETURN_MSG(in_port_intf_set(unit, in_port, intf_in), "intf_in");

    /* 3. Set Out-Port default properties */
    BCM_IF_ERROR_RETURN_MSG(out_port_set(unit, out_port1), "");
    BCM_IF_ERROR_RETURN_MSG(out_port_set(unit, out_port2), "");
    /*
     * 4. Create ETH-RIF and set its properties
     */
    snprintf(error_msg, sizeof(error_msg), "intf_in %d", intf_in);
    BCM_IF_ERROR_RETURN_MSG(intf_eth_rif_create(unit, intf_in, intf_in_mac_address), error_msg);
    /*
     * 5. Set Incoming ETH-RIF properties
     */
    ingr_itf.intf_id = intf_in;
    ingr_itf.vrf = vrf;
    BCM_IF_ERROR_RETURN_MSG(intf_ingress_rif_set(unit, &ingr_itf), "intf_out");
    /*
     * 6. Create a multicast group and its replications
     */
    cint_ipmc_info.intf_out = intf_out;
    BCM_IF_ERROR_RETURN_MSG(create_multicast_group_and_replications(unit, mc_group, cint_ipmc_info.out_ports), "");
    BCM_GPORT_MCAST_SET(mc_gport, mc_group);
    BCM_GPORT_LOCAL_SET(gport, out_port1);

    int fec_rpf_flags2 = 0;
    int fec_fwd_flags2 = 0;
    if(*dnxc_data_get(unit, "l3", "feature", "separate_fwd_rpf_dbs", NULL))
    {
       fec_rpf_flags2 |= BCM_L3_FLAGS2_RPF_ONLY;
       fec_fwd_flags2 |= BCM_L3_FLAGS2_FWD_ONLY;
    }
    /*
     * 7. Create FECs for the ECMP groups
     */
    for (iter = 0; iter < NOF_OF_MEMBERS_ECMP_GROUP; iter++)
    {
        /*
         * 7.1 Create ARP and set its properties
         */
        BCM_IF_ERROR_RETURN_MSG(create_arp_plus_ac_type(unit, 0, arp_next_hop_mac, &encap_id, 0),
            "create egress object ARP only - FEC member");

        /*
         * 7.2 Create FEC and set its properties
         */
        dnx_utils_l3_fec_s_init(unit, 0x0, &fec_structure);
        if (iter < NOF_OF_MEMBERS_ECMP_GROUP/2)
        {
            fec_structure.tunnel_gport = intf_in;
        }
        else
        {
            fec_structure.tunnel_gport = intf_out;
        }
        fec_structure.destination = gport;
        fec_structure.tunnel_gport2 = encap_id;
        fec_structure.fec_id = fec_id_ecmp;
        fec_structure.allocation_flags = BCM_L3_WITH_ID;
        fec_structure.flags2 = fec_fwd_flags2;
        BCM_IF_ERROR_RETURN_MSG(dnx_utils_l3_fec_create(unit, &fec_structure), "create egress object FEC only");

        /*
         * 7.3 Place the new FEC into the interfaces array of the ECMP
         * First 5 will be placed in the passing intf array, second 5 ones - in the failing.
         */
        if (iter < NOF_OF_MEMBERS_ECMP_GROUP/2)
        {
            intf_array_pass[iter] = fec_id_ecmp;
        }
        else
        {
            intf_array_fail[iter - NOF_OF_MEMBERS_ECMP_GROUP/2] = fec_id_ecmp;
        }
        fec_id_ecmp++;
        encap_id++;
        arp_next_hop_mac[5]++;
    }

    /*
     * 8. Create the two ECMP groups
     */
    BCM_IF_ERROR_RETURN_MSG(l3__ecmp_create(unit, ecmp_group_pass, NOF_OF_MEMBERS_ECMP_GROUP/2, intf_array_pass, BCM_L3_WITH_ID,
                         BCM_L3_ECMP_DYNAMIC_MODE_DISABLED, &ecmp,0), "create ECMP group");
    BCM_IF_ERROR_RETURN_MSG(l3__ecmp_create(unit, ecmp_group_fail, NOF_OF_MEMBERS_ECMP_GROUP/2, intf_array_fail, BCM_L3_WITH_ID,
                             BCM_L3_ECMP_DYNAMIC_MODE_DISABLED, &ecmp,0), "create ECMP group");

    /*
     * 9. Link the ECMP group IDs to the interface IDs that should be associated with it.
     */
    BCM_IF_ERROR_RETURN_MSG(field_ecmp_rpf_pmf_entry_add(unit, 0, ecmp_group_pass, intf_in), "");
    BCM_IF_ERROR_RETURN_MSG(field_ecmp_rpf_pmf_entry_add(unit, 0, ecmp_group_fail, intf_out), "");

    /*
     * 10. Create the RPF FEC and the FWD FECs.
     */
    BCM_IF_ERROR_RETURN_MSG(l3__egress_only_fec__create_inner(unit, fec_id_sip, intf_in, 0, gport, 0, fec_rpf_flags2, 0, 0, 0),
        "create egress object FEC only");

    dnx_utils_l3_fec_s_init(unit, 0x0, &fec_structure);
    fec_structure.destination = mc_gport;
    fec_structure.tunnel_gport = ecmp_group_pass;
    fec_structure.fec_id = fec_id_fwd_pass;
    fec_structure.flags = BCM_L3_MC_RPF_EXPLICIT_ECMP;
    fec_structure.flags2 = fec_fwd_flags2;
    fec_structure.allocation_flags = BCM_L3_WITH_ID;
    BCM_IF_ERROR_RETURN_MSG(dnx_utils_l3_fec_create(unit, &fec_structure), "create egress object FEC only");

    dnx_utils_l3_fec_s_init(unit, 0x0, &fec_structure);
    fec_structure.destination = mc_gport;
    fec_structure.tunnel_gport = ecmp_group_fail;
    fec_structure.fec_id = fec_id_fwd_fail;
    fec_structure.flags = BCM_L3_MC_RPF_EXPLICIT_ECMP;
    fec_structure.flags2 = fec_fwd_flags2;
    fec_structure.allocation_flags = BCM_L3_WITH_ID;
    BCM_IF_ERROR_RETURN_MSG(dnx_utils_l3_fec_create(unit, &fec_structure), "create egress object FEC only");

    /*
     * 11. Add IPv4 IPMC entries and host entries
     */
    BCM_IF_ERROR_RETURN_MSG(add_ipv4_ipmc(unit, dip, dip_mask, sip, sip_mask, intf_in, vrf, 0, fec_id_fwd_pass, 0),
        "to LEM table");

    if(*dnxc_data_get(unit, "l3", "fwd", "host_entry_support", NULL))
    {
        BCM_IF_ERROR_RETURN_MSG(add_host_ipv4(unit, sip, vrf, fec_id_sip, 0, 0), "");
    }
    else
    {
        BCM_IF_ERROR_RETURN_MSG(add_route_ipv4_rpf(unit, sip, 0xffffffff, vrf, fec_id_sip), "");
    }

    BCM_IF_ERROR_RETURN_MSG(add_ipv4_ipmc(unit, dip + 1, dip_mask, sip, sip_mask, intf_in, vrf, 0, fec_id_fwd_fail, 0),
        "to LEM table");

    return BCM_E_NONE;
}

/*
 * packets will be routed from in_port1/in_port2/in_port3 to out-port if they pass the RPF check.
 * This function defines several important entities for the packet forwarding:
 * 1. Ingress interfaces with UC RPF configuration.
 * 2. Configure the FEC members of the ECMP group.
 * 3. Create the ECMP groups with the selected UC RPF mode.
 * 4. Create the SIP L3 host entries resulting to the created ECMP groups that will be used for the RPF check.
 * 5. Create the DIP L3 host entries resulting to a FEC pointing to an out port.
 *
 * Route:
 * packet to send:
 *  - in port = in_port
 *  - Vlan ID = vsi_loose/vsi_strict
 *  - SA = 00:00:07:00:01:00
    - DA = 00:0c:00:02:00:00
 *  - DIP = 127.255.255.2/3/4
 * expected:
 *  - out port = out_port
 *  - vlan = 100
 *  - SA = 00:0C:00:02:00:AB
 *  - DA = 00:00:00:00:cd:1d
 *  TTL decremented
 *
 */
int
cint_ip_ecmp_uc_rpf_config(
    int unit,
    int in_port1,
    int in_port2,
    int in_port3,
    int out_port,
    int vsi_loose,
    int vsi_strict,
    int vsi_none)
{
    int rv = BCM_E_NONE;
    int mid = 0;
    int nof_rpf_modes = 3;
    int vrfs[3] =  {vsi_loose, vsi_strict, vsi_none};
    int intf_out = 100;
    bcm_mac_t intf_in_mac_address = {0x00, 0x0c, 0x00, 0x02, 0x00, 0x00};
    bcm_mac_t intf_out_mac_address = {0x00, 0x0C, 0x00, 0x02, 0x00, 0xab};
    bcm_mac_t arp_next_hop_mac = {0x00, 0x00, 0x00, 0x00, 0xcd, 0x1d};
    bcm_l3_egress_ecmp_t ecmp;
    int encap_id = *dnxc_data_get(unit, "l3", "rif", "nof_rifs", NULL) + 0x384;  /* ARP-Link-layer */
    int fec_id;
    int fec_id_ecmp;
    int iter;
    int ecmp_group = 100;
    int vsi_list[3] = {vsi_loose, vsi_strict, vsi_none};
    int fec_id_fwd[3];
    int dip[3] = {0x7fffff02, 0x7fffff03, 0x7fffff04};
    int sip = 0xc0800101;
    int intf_array[NOF_OF_MEMBERS_ECMP_GROUP];
    int rpf_mode[3] = {bcmL3EcmpUrpfLoose, bcmL3EcmpUrpfStrictEm, bcmL3EcmpUrpfInterfaceDefault};
    int fec_fwd_flags2 = 0, fec_rpf_flags2 = 0;

    l3_port_intf intfs[3];
    l3_port_intf_init(&intfs[0], in_port1, vrfs[0], vsi_list[0], bcmL3IngressUrpfLoose, intf_in_mac_address);
    l3_port_intf_init(&intfs[1], in_port2, vrfs[1], vsi_list[1], bcmL3IngressUrpfStrict, intf_in_mac_address);
    l3_port_intf_init(&intfs[2], in_port3, vrfs[2], vsi_list[2], bcmL3IngressUrpfDisable, intf_in_mac_address);

    fec_fwd_flags2 = (*dnxc_data_get(unit, "l3", "feature", "separate_fwd_rpf_dbs", NULL)) ? BCM_L3_FLAGS2_FWD_ONLY : 0;
    fec_rpf_flags2 = (*dnxc_data_get(unit, "l3", "feature", "separate_fwd_rpf_dbs", NULL)) ? BCM_L3_FLAGS2_RPF_ONLY : 0;

    if(*dnxc_data_get(unit, "l3", "feature", "separate_fwd_rpf_dbs", NULL))
    {
        BCM_IF_ERROR_RETURN_MSG(get_first_fec_in_range_which_not_in_ecmp_range(unit, 0, 1, &fec_id), "");
        fec_id_ecmp = fec_id + 2;
        BCM_IF_ERROR_RETURN_MSG(get_first_fec_in_range_which_not_in_ecmp_range(unit, 0, 0, &fec_id_fwd[0]), "");
    }
    else
    {
        BCM_IF_ERROR_RETURN_MSG(get_first_fec_in_range_which_not_in_ecmp_range(unit, 0, 0, &fec_id), "");
        fec_id_ecmp = fec_id + 2;
        fec_id_fwd[0] = fec_id_ecmp + 200;
    }
    fec_id_fwd[1] = fec_id_fwd[0] + 2;
    fec_id_fwd[2] = fec_id_fwd[1] + 2;

    /** 1. Configure traps for UC RPF - Loose and Strict */
    rv = l3_dnx_ip_rpf_config_traps(&unit, 1);
    if (rv == BCM_E_PARAM) {
        rv = BCM_E_NONE;
    }
    BCM_IF_ERROR_RETURN_MSG(rv, "");

    /** 2. Set Out-Port default properties */
    BCM_IF_ERROR_RETURN_MSG(out_port_set(unit, out_port), "");

    /** 3. Configure in-port, ingress interfaces and set RPF check */
    for (mid = 0; mid < nof_rpf_modes; mid++)
    {
        printf("Creating intf = %d with port = %d\n", intfs[mid].intf_id, intfs[mid].port);
        BCM_IF_ERROR_RETURN_MSG(cint_ip_rpf_port_intf_set(unit, intfs[mid].port, intfs[mid].intf_id, intfs[mid].vrf, intfs[mid].rpf_mode), "");
    }

    /** 4. Create OUT-LIF and set its properties: FEC, encap-id */
    BCM_IF_ERROR_RETURN_MSG(intf_eth_rif_create(unit, intf_out, intf_out_mac_address), "intf_out");
    /** 5. Create ARP and set its properties */
    BCM_IF_ERROR_RETURN_MSG(l3__egress_only_encap__create(unit, 0, &encap_id, arp_next_hop_mac, 0),
        "create egress object ARP only, encap_id");
    /** 6. Create FEC used for RPF*/
    BCM_IF_ERROR_RETURN_MSG(l3__egress_only_fec__create(unit, fec_id, intf_out, encap_id, out_port, 0, fec_rpf_flags2),
        "create egress object FEC only, intf_out");

    /*
     * 7. Create FECs for the ECMP group
     */
    int encap_index = encap_id + 1;
    for (iter = 0; iter < NOF_OF_MEMBERS_ECMP_GROUP; iter++)
    {
        encap_index++;
        arp_next_hop_mac[5] ++;
        /*
         * 7.1 Create ARP and set its properties
         */
        BCM_IF_ERROR_RETURN_MSG(l3__egress_only_encap__create(unit, 0, &encap_index, arp_next_hop_mac, 0),
            "create egress object ARP only");

        /*
         * 7.2 Create FEC and set its properties
         */
        BCM_IF_ERROR_RETURN_MSG(l3__egress_only_fec__create(unit, fec_id_ecmp, intf_out, encap_index, out_port, 0, fec_rpf_flags2),
            "create egress object FEC only, intf_out");

        /*
         * 7.3 Increment variables for next iteration.
         * Place the new FEC into the interfaces array of the ECMP
         * Increment the FEC number ad the encap number for the next FEC.
         * Set a different next hop MAC to identify different FEC selection.
         */
        intf_array[iter] = fec_id_ecmp;
        fec_id_ecmp++;
    }

    /** 8. Iterate over the three RPF modes and create the needed entries.*/
    for (mid = 0; mid < nof_rpf_modes; mid++)
    {
        /* 8.1. Create FECs used for forwarding*/
        BCM_IF_ERROR_RETURN_MSG(l3__egress_only_fec__create(unit, fec_id_fwd[mid], intf_out, encap_id, out_port, 0, fec_fwd_flags2),
            "create egress object FEC only, intf_out");

        /*
         * 8.2. Create an ECMP group
         */
        bcm_l3_egress_ecmp_t_init(ecmp);
        ecmp.flags = BCM_L3_WITH_ID;
        ecmp.ecmp_intf = ecmp_group;
        ecmp.dynamic_mode = BCM_L3_ECMP_DYNAMIC_MODE_DISABLED;
        ecmp.rpf_mode = rpf_mode[mid];
        BCM_IF_ERROR_RETURN_MSG(bcm_l3_egress_ecmp_create(unit, ecmp, NOF_OF_MEMBERS_ECMP_GROUP, intf_array), "");
        BCM_IF_ERROR_RETURN_MSG(field_ecmp_rpf_pmf_entry_add(unit, 0, ecmp_group, vsi_list[mid]), "");

        if (*dnxc_data_get(unit, "l3", "fwd", "host_entry_support", NULL))
        {
            /*
             * 8.3. Create the Destination host entry
             */
            BCM_IF_ERROR_RETURN_MSG(add_host_ipv4(unit, dip[mid], vrfs[mid], fec_id_fwd[mid], 0, 0), "dip, vrfs[mid]");
            /*
             * 8.4. Create the Source host entry - same SIP, but different VRF based on RPF type.
             */
            BCM_IF_ERROR_RETURN_MSG(add_host_ipv4(unit, sip, vrfs[mid], ecmp.ecmp_intf, 0, 0), "sip, vrfs[mid]");
        }
        else
        {
            /*
             * 8.3. Create the Destination route entry
             */
            BCM_IF_ERROR_RETURN_MSG(add_route_ipv4(unit, dip[mid], 0xffffffff, vrfs[mid], fec_id_fwd[mid]), "");
            /*
             * 8.4. Create the Source host entry - same SIP, but different VRF based on RPF type.
             */
            BCM_IF_ERROR_RETURN_MSG(add_route_ipv4_rpf(unit, sip, 0xffffffff, vrfs[mid], ecmp.ecmp_intf), "");
        }
        ecmp_group++;
    }

    if (*dnxc_data_get(unit, "l3", "fwd", "host_entry_support", NULL))
    {
        /** 9. Create the Source host entries*/
        sip++;
        BCM_IF_ERROR_RETURN_MSG(add_host_ipv4(unit, sip, vrfs[0], fec_id, 0, 0), "sip, vrfs[mid]");
        sip++;
        BCM_IF_ERROR_RETURN_MSG(add_host_ipv4(unit, sip, vrfs[2], ecmp.ecmp_intf - 1, 0, 0), "sip, vrfs[mid]");
    }
    else
    {
        /**9. Create the Source route entries*/
        sip++;
        BCM_IF_ERROR_RETURN_MSG(add_route_ipv4_rpf(unit, sip, 0xffffffff, vrfs[0], fec_id), "sip, vrfs[mid]");
        sip++;
        BCM_IF_ERROR_RETURN_MSG(add_route_ipv4_rpf(unit, sip, 0xffffffff, vrfs[2], ecmp.ecmp_intf - 1), "sip, vrfs[mid]");
    }
    return BCM_E_NONE;
}
