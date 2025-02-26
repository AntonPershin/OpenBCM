/*
 * 
 This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 
 Copyright 2007-2022 Broadcom Inc. All rights reserved.
 */
/*
 * Test Scenario
 *
 * Test Scenario - start
  cint ../../../../src/examples/dnx/l3/cint_dnx_ip_route_basic.c
  cint ../../../../src/examples/dnx/l3/cint_dnx_ecmp_basic.c
  cint
  basic_ecmp_example(0,200,201,0,100);
  exit;
 *
 * * ETH-RIF packet *
  tx 1 psrc=200 data=0x000c00020000000007000100080045000035000000008000fa45c08001017fffff02000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f20
 *
 * * Received packets on unit 0 should be: *
 * * Source port: 0, Destination port: 0 *
 * * Data: 0x0000cd1d00123456789a81000000080045000035000000007f00fb45c08001017fffff02 *
 * Test Scenario - end
 *
 */

/*
 * NOF FECs in the ECMP group of the basic ECMP test.
 */
int NOF_OF_MEMBERS_ECMP_GROUP = 10;

/*
 * NOF FECs required for the ECMP TP testing.
 */
int NOF_OF_MEMBERS_ECMP_TP_GROUPS = 16;

struct cint_ecmp_basic_info_s
{
    int in_port;                                        /** incoming port */
    int out_port;                                       /** outgoing port */
    int intf_in;                                        /** Incoming packet ETH-RIF */
    int intf_out;                                       /** Outgoing packet ETH-RIF */
    bcm_mac_t intf_in_mac_address;                      /** mac for in RIF */
    bcm_mac_t intf_out_mac_address;                     /** mac for out RIF */
    bcm_mac_t arp_next_hop_mac;                         /** mac for out RIF */
    int encap_id1;                                      /** encap ID 1 */
    int encap_id2;                                      /** encap ID 2 */
    bcm_ip_t host;                                      /** host */
    bcm_ip_t mask;                                      /** mask */
    int vrf;                                            /** VRF */
    bcm_if_t fec_id1;                                   /** FEC id 1*/
    bcm_if_t fec_id2;                                   /** FEC id 2*/
    bcm_if_t fec_id3;                                   /** FEC id 3*/
    bcm_if_t ecmp_id1;                                  /** ECMP interface id 1 */
    bcm_if_t ecmp_id2;                                  /** ECMP interface id 2 */
    bcm_if_t ecmp_id3;                                  /** ECMP interface id 3 */
    int user_profile_id;                                /** ECMP user_profile id */
    int new_outer_vlan;                                 /** Outer VLAN ID */
    int new_inner_vlan;                                 /** Inner VLAN ID */
    int outer_tpid;                                     /** Outer TPID */
    int inner_tpid;                                     /** Inner TPID */
    bcm_l3_ecmp_tunnel_priority_mode_t tp_mode;         /** tunnel priority mode */
};

cint_ecmp_basic_info_s cint_ecmp_info = {
    /*
     * ports : in_port | out_port
     */
    200, 201,
    /*
     * intf_in | intf_out
     */
    15, 100,
    /*
     * intf_in_mac_address | intf_out_mac_address | arp_next_hop_mac
     */
    {0x00, 0x0c, 0x00, 0x02, 0x00, 0x00}, {0x00, 0x12, 0x34, 0x56, 0x78, 0x9a}, {0x00, 0x00, 0x00, 0x00, 0xcd, 0x1d},
    /*
     * encap_id1
     */
    0x2708,
    /*
     * encap_id2
     */
    0x1021,
    /*
     * host
     */
    0x7fffff02 /** 127.255.255.2 */ ,
    /*
     * mask
     */
    0xfffffff0 /** 255.255.255.240 */ ,
    /*
     * vrf
     */
    1,
    /*
     * fec_id1
     */
    0x4001,
    /*
     * fec_id2
     */
    0x10001,
    /*
     * fec_id3
     */
    0x18000,
    /*
     * ecmp_id1
     */
    50,
    /*
     * ecmp_id2
     */
    2150,
    /*
     * ecmp_id3
     */
    4097,
    /*
     * user_profile_id
     */
    0,
    /*
     * new_outer_vlan
     */
    55,
    /*
     * new_inner_vlan
     */
    56,
    /*
     * outer_tpid
     */
    0x9100,
    /*
     * inner_tpid
     */
    0x8100,
    /*
     * tp_mode
     */
    0
};
/*
 * Create an ECMP user profile
 * - flags - user profile flags
 * - user_profile_id - user_profile_id number
 * - offset_array - offset array for user profile
 * - offset_count_intf - offset array nof elements
 * - user_profile_ecmp - the created ECMP user profile
 */
int
l3__ecmp_user_profile_create(int unit,
        int flags,
        uint32 dynamic_mode,
        int user_profile_id,
        int offset_count_intf,
        bcm_if_t * offset_array,
        bcm_l3_egress_ecmp_t * user_profile_ecmp)
{
    bcm_l3_egress_ecmp_t_init(user_profile_ecmp);

    user_profile_ecmp->user_profile= user_profile_id;
    user_profile_ecmp->flags = flags;
    user_profile_ecmp->dynamic_mode = dynamic_mode;

    BCM_IF_ERROR_RETURN_MSG(bcm_l3_egress_ecmp_user_profile_create(unit,user_profile_ecmp , offset_count_intf , offset_array), "");
    return BCM_E_NONE;
}
/*
 * Create an ECMP group
 * - ecmp_id - the ECMP ID
 * - intf_count - NOF members in the ECMP group
 * - intf_array - array of the group members
 * - flags - ECMP flags
 * - ecmp - the created ECMP group.
 */
int
l3__ecmp_create(
    int unit,
    int ecmp_id,
    int intf_count,
    bcm_if_t * intf_array,
    int flags,
    uint32 dynamic_mode,
    bcm_l3_egress_ecmp_t * ecmp,
    int user_profile_id)
{
    int nof_ecmp_basic_mode = *dnxc_data_get(unit, "l3", "ecmp", "nof_ecmp_basic_mode", NULL);
    bcm_l3_egress_ecmp_t_init(ecmp);

    /*
     * ECMP properties
     */
    ecmp->max_paths = intf_count;
    ecmp->flags = flags;
    ecmp->ecmp_intf = ecmp_id;
    ecmp->dynamic_mode = dynamic_mode;
    /** If the ECMP group is in the extended range, add the needed flag. */
    if (ecmp_id >= nof_ecmp_basic_mode)
    {
        ecmp->ecmp_group_flags = BCM_L3_ECMP_EXTENDED;
    }
    /*
     * create an ECMP, containing the FECs entries
     */
    if(user_profile_id)
    {
        ecmp->max_paths = 0;
        ecmp->user_profile = user_profile_id;
        ecmp->ecmp_group_flags = BCM_L3_ECMP_USER_PROFILE;
        BCM_IF_ERROR_RETURN_MSG(bcm_l3_egress_ecmp_create(unit, ecmp, 1, intf_array), "");
    }
    else
    {
        BCM_IF_ERROR_RETURN_MSG(bcm_l3_egress_ecmp_create(unit, ecmp, intf_count, intf_array), "");
    }

    return BCM_E_NONE;
}

/*
 * Packets will be routed through different FEC from the in_port to the out_port and each FEC will have a different next hop MAC address.
 *
 * packet to send:
 *  - in port = in_port
 *  - DA = {0x00, 0x0c, 0x00, 0x02, 0x00, 0x00}
 *  - DIP = 0x7fffff02
 * expected:
 *  - out port = out_port
 *  - vlan = 100.
 *  - DA = {0x20, 0x00, 0x00, 0x00, 0xcd, 0x1d}
 *  - SA = {0x00, 0x0c, 0x00, 0x02, 0x00, 0x01}
 *  TTL decremented
 *
 */
/*
 * example:
 int unit = 0;
 int in_port = 200;
 int out_port = 201;
 */
int
basic_ecmp_example(
    int unit,
    int in_port,
    int out_port,
    int is_consistent,
    int ecmp_id)
{
    int iter;
    bcm_if_t intf_array[NOF_OF_MEMBERS_ECMP_GROUP];
    bcm_gport_t gport;
    bcm_l3_egress_ecmp_t ecmp;
    l3_ingress_intf ingr_itf;
    l3_ingress_intf_init(&ingr_itf);

    char *proc_name;

    proc_name = "dnx_basic_ecmp_example";
    int encoded_fec;
    cint_ecmp_info.in_port = in_port;
    cint_ecmp_info.out_port = out_port;


    BCM_IF_ERROR_RETURN_MSG(get_first_fec_in_range_which_not_in_ecmp_range(unit, 0, 0, &(cint_ecmp_info.fec_id3)), "");
    /*
     * 1. Set In-Port to In ETh-RIF
     */
    BCM_IF_ERROR_RETURN_MSG(in_port_intf_set(unit, cint_ecmp_info.in_port, cint_ecmp_info.intf_in), "");

    /*
     * 2. Set Out-Port default properties
     */
    BCM_IF_ERROR_RETURN_MSG(out_port_set(unit, cint_ecmp_info.out_port), "");

    /*
     * 3. Create ETH-RIF and set its properties
     */
    BCM_IF_ERROR_RETURN_MSG(intf_eth_rif_create_vrf(unit, cint_ecmp_info.intf_in, cint_ecmp_info.vrf, cint_ecmp_info.intf_in_mac_address), "");

    /*
     * 4. Set Incoming ETH-RIF properties
     */
    ingr_itf.intf_id = cint_ecmp_info.intf_in;
    ingr_itf.vrf = cint_ecmp_info.vrf;
    BCM_IF_ERROR_RETURN_MSG(intf_ingress_rif_set(unit, &ingr_itf), "");

    /*
     * 5. Create ETH-RIF and set its properties
     */
    BCM_IF_ERROR_RETURN_MSG(intf_eth_rif_create_vrf(unit, cint_ecmp_info.intf_out, 0, cint_ecmp_info.intf_out_mac_address), "");

    BCM_GPORT_LOCAL_SET(gport, cint_ecmp_info.out_port);

    /*
     * 5. Create FECs for the ECMP group
     *
     */
    for (iter = 0; iter < NOF_OF_MEMBERS_ECMP_GROUP; iter++)
    {
        /*
         * 5.1 Create ARP and set its properties
         */
        BCM_IF_ERROR_RETURN_MSG(create_arp_plus_ac_type(unit, 0, cint_ecmp_info.arp_next_hop_mac, &cint_ecmp_info.encap_id1, 0), "");

        /*
         * 6. Create FEC and set its properties
         */

        printf("%s():. Create main FEC and set its properties.\r\n",proc_name);
        if (BCM_GPORT_IS_SET(out_port)) {
           gport = out_port;
        }
        else {
           BCM_GPORT_LOCAL_SET(gport, out_port);
        }

        int fec_flags2 = 0;
        if(*dnxc_data_get(unit, "l3", "feature", "separate_fwd_rpf_dbs", NULL))
        {
            fec_flags2 |= BCM_L3_FLAGS2_FWD_ONLY;
        }

        BCM_IF_ERROR_RETURN_MSG(l3__egress_only_fec__create_inner(unit, cint_ecmp_info.fec_id3, cint_ecmp_info.intf_out, cint_ecmp_info.encap_id1, gport, 0,
                                               fec_flags2, 0, 0, 0), "create egress object FEC only");

        /*
         * Place the new FEC into the interfaces array of the ECMP
         * Increment the FEC number ad the encap number for the next FEC.
         * Set a different next hop MAC to identify different FEC selection.
         */
        intf_array[iter] = cint_ecmp_info.fec_id3;
        cint_ecmp_info.fec_id3++;
        cint_ecmp_info.encap_id1++;
        cint_ecmp_info.arp_next_hop_mac[5]++;
    }
    /*
     * 7. Create user profile
    */
    if (cint_ecmp_info.user_profile_id)
    {
        bcm_if_t * intf_offset;
        bcm_if_t intf_array[NOF_OF_MEMBERS_ECMP_GROUP];
        bcm_l3_egress_ecmp_t user_profile_ecmp;
        /* Create offsets for user profile array*/
        int offset_iter;
        uint32 max_offset_valid;
        int nof_offsets_user_profiles = *(dnxc_data_1d_get(unit, "l3", "ecmp", "consistent_tables_info", "nof_entries", 0));
        intf_offset = sal_alloc((sizeof(intf_array[0]) * nof_offsets_user_profiles),"User profile array");
        max_offset_valid = *(dnxc_data_1d_get(unit, "l3", "ecmp", "consistent_tables_info", "entry_size_in_bits", 0));
        for(offset_iter = 0;offset_iter< nof_offsets_user_profiles;offset_iter++)
        {
          intf_offset[offset_iter] = offset_iter%(1U << max_offset_valid);
        }

        BCM_IF_ERROR_RETURN_MSG(l3__ecmp_user_profile_create(unit,BCM_L3_WITH_ID,BCM_L3_ECMP_DYNAMIC_MODE_RESILIENT,cint_ecmp_info.user_profile_id
                ,nof_offsets_user_profiles,intf_offset,&user_profile_ecmp), "create ecmp user profile");
    }
    /*
     * 7. Create an ECMP group
     */
    if ((cint_ecmp_info.user_profile_id==0) && (is_consistent == 0))
    {
        BCM_IF_ERROR_RETURN_MSG(l3__ecmp_create(unit, ecmp_id, NOF_OF_MEMBERS_ECMP_GROUP, intf_array, BCM_L3_WITH_ID,
                             BCM_L3_ECMP_DYNAMIC_MODE_DISABLED, &ecmp, 0), "create ECMP group");
    }
    else
    {
        BCM_IF_ERROR_RETURN_MSG(l3__ecmp_create(unit, ecmp_id, NOF_OF_MEMBERS_ECMP_GROUP, intf_array, BCM_L3_WITH_ID,
                             BCM_L3_ECMP_DYNAMIC_MODE_RESILIENT, &ecmp, cint_ecmp_info.user_profile_id), "create ECMP group");
    }

    /*
     * 8. Add Route entry
     */

    BCM_IF_ERROR_RETURN_MSG(add_route_ipv4(unit, cint_ecmp_info.host, cint_ecmp_info.mask, cint_ecmp_info.vrf, ecmp_id), "");

    return BCM_E_NONE;
}

/*
 * basic ECMP tunnel priority setup.
 * The NOF priorities is set by the cint_ecmp_info.tp_mode
 */
int
basic_ecmp_tp_example(
    int unit,
    int in_port,
    int out_port,
    int ecmp_id)
{

    int iter;
    int dscp;
    int flags_qos = BCM_QOS_MAP_L3 | BCM_QOS_MAP_IPV4 | BCM_QOS_MAP_PHB;
    bcm_if_t intf_array[NOF_OF_MEMBERS_ECMP_TP_GROUPS];
    bcm_gport_t gport;
    bcm_l3_egress_ecmp_t ecmp;
    bcm_qos_map_t l3_ing_map;
    l3_ingress_intf ingr_itf;
    l3_ingress_intf_init(&ingr_itf);
    bcm_qos_map_t_init(&l3_ing_map);
    cint_ecmp_info.in_port = in_port;
    cint_ecmp_info.out_port = out_port;
    uint32 mask = 0xfffffff0;
    BCM_IF_ERROR_RETURN_MSG(get_first_fec_in_range_which_not_in_ecmp_range(unit, 0, 0, &(cint_ecmp_info.fec_id3)), "");
    /*
     * 1. Set In-Port to In ETh-RIF
     */
    BCM_IF_ERROR_RETURN_MSG(in_port_intf_set(unit, cint_ecmp_info.in_port, cint_ecmp_info.intf_in), "intf_in");
    /*
     * 2. Set Out-Port default properties
     */
    BCM_IF_ERROR_RETURN_MSG(out_port_set(unit, cint_ecmp_info.out_port), "out_port");

    /*
     * 3. Set the QOS map, and match each DSCP value to a traffic class value.
     * DSCP 0 will get TC 0, DSCP 1 will get TC 1...
     */
    BCM_IF_ERROR_RETURN_MSG(dnx_qos_ingress_phb_map(unit, 0, 0), "out_port");

    for(dscp = 0; dscp < 8; dscp++)
    {
        l3_ing_map.dscp             = dscp;
        l3_ing_map.int_pri          = dscp;
        BCM_IF_ERROR_RETURN_MSG(bcm_qos_map_add(unit, flags_qos, &l3_ing_map, ing_opcode_id), "");
    }

    /*
     * 4. Create ETH-RIF and set its properties
     */
    BCM_IF_ERROR_RETURN_MSG(intf_eth_rif_create(unit, cint_ecmp_info.intf_in,cint_ecmp_info.intf_in_mac_address), "intf_in");

    /*
     * 5. Set Incoming ETH-RIF properties
     */
    ingr_itf.intf_id = cint_ecmp_info.intf_in;
    ingr_itf.vrf = cint_ecmp_info.vrf;
    ingr_itf.qos_map = ing_phb_map_id;
    BCM_IF_ERROR_RETURN_MSG(intf_ingress_rif_set(unit, &ingr_itf), "ingr_itf");

    /*
     * 6. Create ETH-RIF and set its properties
     */
    BCM_IF_ERROR_RETURN_MSG(intf_eth_rif_create(unit, cint_ecmp_info.intf_out, cint_ecmp_info.intf_out_mac_address), "intf_out");

    BCM_GPORT_LOCAL_SET(gport, cint_ecmp_info.out_port);

    /*
     * 7. Create FECs for the ECMP group
     *
     */
    for (iter = 0; iter < NOF_OF_MEMBERS_ECMP_TP_GROUPS; iter++)
    {
        /*
         * 7.1 Create ARP and set its properties
         */
        BCM_IF_ERROR_RETURN_MSG(create_arp_plus_ac_type(unit, 0, cint_ecmp_info.arp_next_hop_mac, &cint_ecmp_info.encap_id1, 0),
            "create egress object ARP only");

        /*
         * 7.2 Create FEC and set its properties
         */

        if (BCM_GPORT_IS_SET(out_port)) {
            gport = out_port;
        }
        else {
            BCM_GPORT_LOCAL_SET(gport, out_port);
        }

        int fec_flags2 = 0;
        if(*dnxc_data_get(unit, "l3", "feature", "separate_fwd_rpf_dbs", NULL))
        {
            fec_flags2 |= BCM_L3_FLAGS2_FWD_ONLY;
        }

        BCM_IF_ERROR_RETURN_MSG(l3__egress_only_fec__create_inner(unit, cint_ecmp_info.fec_id3, cint_ecmp_info.intf_out, cint_ecmp_info.encap_id1, gport, 0,
                                              fec_flags2, 0, 0, 0), "create egress object FEC only");
        {
            /*
             * Currently in adapter consecutive even and odd LIF entries get the even entry payload.
             * This allocation is a to create odd LIF entries but don't use them so we can be sure what is the ARP payload
             * that will be received.
             */
            cint_ecmp_info.encap_id1++;
            BCM_IF_ERROR_RETURN_MSG(create_arp_plus_ac_type(unit, 0, cint_ecmp_info.arp_next_hop_mac, &cint_ecmp_info.encap_id1, 0),
                "create egress object ARP only");
        }
        /*
         * Place the new FEC into the interfaces array of the ECMP
         * Increment the FEC number ad the encap number for the next FEC.
         * Set a different next hop MAC to identify different FEC selection.
         */
        intf_array[iter] = cint_ecmp_info.fec_id3;
        cint_ecmp_info.fec_id3++;
        cint_ecmp_info.encap_id1++;
        cint_ecmp_info.arp_next_hop_mac[5]++;
    }

    /*
     * 8. Create tunnel priority map for the ECMP group
     */
    int traffic_class_max_size = 8;/** The traffic class size is 3 bits */
    int nof_tables = 1 << cint_ecmp_info.tp_mode;
    int tp_iter;
    int tp_range_per_size_index = traffic_class_max_size / nof_tables;
    bcm_l3_ecmp_tunnel_priority_map_info_t map_info;
    map_info.l3_flags = 0;
    BCM_IF_ERROR_RETURN_MSG(bcm_l3_ecmp_tunnel_priority_map_create(unit,&map_info), "");

    for(tp_iter = 0; tp_iter < traffic_class_max_size; tp_iter++)
    {
        map_info.tunnel_priority = tp_iter;
        map_info.index = tp_iter / tp_range_per_size_index;
        BCM_IF_ERROR_RETURN_MSG(bcm_l3_ecmp_tunnel_priority_map_set(unit,&map_info), "");
    }

    /*
     * 9. Create an TP ECMP group
     */
    bcm_l3_egress_ecmp_t_init(ecmp);
    ecmp.max_paths = NOF_OF_MEMBERS_ECMP_TP_GROUPS;
    ecmp.flags = BCM_L3_WITH_ID;
    ecmp.ecmp_intf = ecmp_id;
    ecmp.dynamic_mode = BCM_L3_ECMP_DYNAMIC_MODE_RESILIENT;
    ecmp.tunnel_priority.index = 0;
    ecmp.tunnel_priority.map_profile = map_info.map_profile;
    ecmp.tunnel_priority.mode = cint_ecmp_info.tp_mode;
    BCM_IF_ERROR_RETURN_MSG(bcm_l3_egress_ecmp_create(unit, &ecmp, 1, &intf_array[0]), "");

    bcm_if_t index_intf_array[NOF_OF_MEMBERS_ECMP_TP_GROUPS];
    int nof_interfaces_per_index = NOF_OF_MEMBERS_ECMP_TP_GROUPS / nof_tables;
    int index_iter;

    /*
     * 10. Update each one of the ECMP group TP tables with different FEC members
     */
    for(index_iter = 0;index_iter < nof_tables;index_iter++)
    {

        for (iter = 0; iter < nof_interfaces_per_index; iter++)
        {
            index_intf_array[iter] = intf_array[index_iter*nof_interfaces_per_index + iter];
        }

        ecmp.tunnel_priority.index = index_iter;
        BCM_IF_ERROR_RETURN_MSG(bcm_l3_egress_ecmp_tunnel_priority_set(unit,&ecmp,nof_interfaces_per_index,index_intf_array), "");
    }

    /*
     * 11. Add FWD entry
     */
    if(*dnxc_data_get(unit, "l3", "fwd", "host_entry_support", NULL))
    {
        BCM_IF_ERROR_RETURN_MSG(add_host_ipv4(unit, cint_ecmp_info.host, cint_ecmp_info.vrf, ecmp_id, 0, 0), "");
    }
    else
    {
        BCM_IF_ERROR_RETURN_MSG(add_route_ipv4(unit, cint_ecmp_info.host, mask, cint_ecmp_info.vrf, ecmp_id), "");
    }

    return BCM_E_NONE;

}

/* Remove a member from an ECMP group.*/
int
ecmp_consistent_hashing_remove_member(
    int unit,
    int ecmp_id,
    int fec_member)
{
    bcm_l3_egress_ecmp_t ecmp;
    ecmp.flags = BCM_L3_WITH_ID;
    ecmp.ecmp_intf = ecmp_id;
    ecmp.dynamic_mode = BCM_L3_ECMP_DYNAMIC_MODE_RESILIENT;

    BCM_IF_ERROR_RETURN_MSG(bcm_l3_egress_ecmp_delete(unit, &ecmp, fec_member), "");
    return BCM_E_NONE;
}

/* Add another member to an ECMP group.*/
int
ecmp_consistent_hashing_add_member(
    int unit,
    int ecmp_id,
    int fec_member)
{
    bcm_l3_egress_ecmp_t ecmp;
    ecmp.flags = BCM_L3_WITH_ID;
    ecmp.ecmp_intf = ecmp_id;
    ecmp.dynamic_mode = BCM_L3_ECMP_DYNAMIC_MODE_RESILIENT;
    BCM_IF_ERROR_RETURN_MSG(bcm_l3_egress_ecmp_add(unit, &ecmp, fec_member), "");
    return BCM_E_NONE;
}


/*
 * hierarchy ECMPS in the group.
 */
int NOF_1ST_HIER_FECS = 5;
/*
 * NOF FECs in each 2nd hierarchy ECMP.
 */
int NOF_2ND_HIER_FECS = 5;
/*
 * NOF FECs in each 3rd hierarchy ECMP.
 */
int NOF_3RD_HIER_FECS = 5;
/*
 * Test Scenario
 * This test checks the hierarchical ECMP (two hierarchies), the first hierarchy level sets the out-RIF and the second one the ARP (DA).
 * When changing the header parameters we're expecting that both the out-RIF and the DA of the outgoing packets will be modified
 *
 * Test Scenario - start
  cint ../../../../src/examples/sand/utility/cint_sand_utils_global.c
  cint ../../../../src/examples/sand/cint_ip_route_basic.c
  cint ../../../../src/examples/sand/cint_ecmp_basic.c
  cint
  basic_ecmp_hierarchical_example(0,200,201);
 * Test Scenario - end
 *
 *                                                                                                            +----> FEC_000 (3rd hier)
 *                                                                                      +-> ECMP_00(3rd hier) |---->    .
 *                                                                                      |          .          +----> FEC_00P (3rd hier)
 *                                                               +----> FEC_00(2nd hier)+          .                    .
 *                                       +----> ECMP_0(2nd hier) |---->                            .          +----> FEC_0M0 (3rd hier)
 *                 +---->FEC_0 (1st hier)+             .         +----> FEC_0M(2nd hier)+-> ECMP_0M 3rd hier) |---->    .
 *                 |          .                        .                                           .          +----> FEC_0MP (3rd hier)
 *                 +---->     .                        .                                           .                    .
 * ECMP (1st hier) |          .                        .                                           .                    .
 *                 +---->     .                        .                                           .                    .
 *                 |          .                        .                                                      +----> FEC_N00 (3rd hier)
 *                 +---->FEC_N (1st hier)+             .         +----> FEC_N0(2nd hier)+-> ECMP_N0(3rd hier) |---->    .
 *                                       +----> ECMP_N(2nd hier) |---->                            .          +----> FEC_N0P (3rd hier)
 *                                                               +----> FEC_NM(2nd hier)+          .                    .
 *                                                                                      |          .          +----> FEC_NM0 (3rd hier)
 *                    (FECs from 0 to N)                                                +-> ECMP_NM(3rd hier) |---->    .
 *                                                           (FECs from 0 to M for each ECMP group)           +----> FEC_NMP (3rd hier)
 *                                                                                                      (FECs from 0 to P for each ECMP group)
 *
 */
/*
 * example:
 int unit = 0;
 int in_port = 200;
 int out_port = 201;
 */
int
basic_ecmp_hierarchical_example(
    int unit,
    int in_port,
    int out_port)
{
    char error_msg[200]={0,};
    int iter_1st;
    int iter_2nd;
    int iter_3rd;
    int rif = 70;

    bcm_gport_t gport;
    bcm_gport_t gport_ecmp;
    bcm_gport_t lif_as_gport = 0;
    bcm_l3_egress_ecmp_t ecmp;
    bcm_l3_egress_ecmp_t ecmp1;

    l3_ingress_intf ingress_itf;
    bcm_if_t fec_array_hier1[NOF_1ST_HIER_FECS];
    bcm_if_t fec_array_hier2[NOF_2ND_HIER_FECS];
    bcm_if_t fec_array_hier3[NOF_3RD_HIER_FECS];

    cint_ecmp_info.in_port = in_port;
    cint_ecmp_info.out_port = out_port;

    BCM_IF_ERROR_RETURN_MSG(get_first_fec_in_range_which_not_in_ecmp_range(unit, 0, 0, &cint_ecmp_info.fec_id1), "");
    BCM_IF_ERROR_RETURN_MSG(get_first_fec_in_range_which_not_in_ecmp_range(unit, 1, 0, &cint_ecmp_info.fec_id2), "");
    BCM_IF_ERROR_RETURN_MSG(get_first_fec_in_range_which_not_in_ecmp_range(unit, 2, 0, &cint_ecmp_info.fec_id3), "");

    /*
     * 1. Set In-Port to In ETh-RIF
     */
    BCM_IF_ERROR_RETURN_MSG(in_port_intf_set(unit, cint_ecmp_info.in_port, cint_ecmp_info.intf_in), "intf_in");

    /*
     * 2. Set Out-Port default properties
     */
    BCM_IF_ERROR_RETURN_MSG(out_port_set(unit, cint_ecmp_info.out_port), "out_port");

    /*
     * 3. Create ETH-RIF and set its properties
     */
    BCM_IF_ERROR_RETURN_MSG(intf_eth_rif_create(unit, cint_ecmp_info.intf_in, cint_ecmp_info.intf_in_mac_address), "intf_in");

    /*
     * 4. Set Incoming ETH-RIF properties
     */
    l3_ingress_intf_init(&ingress_itf);
    ingress_itf.intf_id = cint_ecmp_info.intf_in;
    ingress_itf.vrf = cint_ecmp_info.vrf;
    BCM_IF_ERROR_RETURN_MSG(intf_ingress_rif_set(unit, &ingress_itf), "intf_out");

    BCM_GPORT_LOCAL_SET(gport, cint_ecmp_info.out_port);
    int flags2 = 0;
    if(*dnxc_data_get(unit, "l3", "feature", "separate_fwd_rpf_dbs", NULL))
    {
       flags2 |= BCM_L3_FLAGS2_FWD_ONLY;
    }
    /*
     * This is a nested loop, the outer loop creates a first level ECMP group that provides (using the first level FEC)
     * and out-RIF and an inner loop that provide in the second hierarchy level an ARP.
     */
    for (iter_1st = 0; iter_1st < NOF_1ST_HIER_FECS; iter_1st++)
    {
        BCM_IF_ERROR_RETURN_MSG(intf_eth_rif_create(unit, cint_ecmp_info.intf_out, cint_ecmp_info.intf_out_mac_address), "intf_out");

        /*
         * Loop over the creation of FECs in different hierarchies.
         */
        for (iter_2nd = 0; iter_2nd < NOF_2ND_HIER_FECS; iter_2nd++)
        {
            /*
             * 5. Create ARP and set its properties for each 3H FEC
             */
            snprintf(error_msg, sizeof(error_msg), "ARP only, encap_id = %04x", cint_ecmp_info.encap_id1);
            BCM_IF_ERROR_RETURN_MSG(create_arp_plus_ac_type(unit, 0, cint_ecmp_info.arp_next_hop_mac, &cint_ecmp_info.encap_id1,
                                               cint_ecmp_info.intf_out), error_msg);
            /*
             * 6. Create 3rd hierarchy FECs with encap_id_2 and gport pointing to the out_port
             */
            for (iter_3rd = 0; iter_3rd < NOF_3RD_HIER_FECS; iter_3rd++)
            {
                BCM_IF_ERROR_RETURN_MSG(l3__egress_only_fec__create_inner(unit, cint_ecmp_info.fec_id3, rif, cint_ecmp_info.encap_id2, gport, BCM_L3_3RD_HIERARCHY, flags2, 0, 0, 0),
                    "create egress object FEC only");

                fec_array_hier3[iter_3rd] = cint_ecmp_info.fec_id3;
                rif++;
                cint_ecmp_info.fec_id3++;
            }
            /*
             * 7. Create ECMP group in 3rd hieararchy with the list of 3H FECs.
             * Until ECMP allocation manager is ready, ecmp is created with WITH_ID flag
             */
            BCM_IF_ERROR_RETURN_MSG(l3__ecmp_create(unit, cint_ecmp_info.ecmp_id3, NOF_3RD_HIER_FECS, fec_array_hier3,
                BCM_L3_WITH_ID | BCM_L3_3RD_HIERARCHY, BCM_L3_ECMP_DYNAMIC_MODE_DISABLED, &ecmp1, 0), "3rd hierarchy");

            /*
             * 8. Create second hierarchy FECs pointing to the ECMP group in 3rd hierarchy
             */
            BCM_L3_ITF_FEC_TO_GPORT_FORWARD_GROUP(gport_ecmp, ecmp1.ecmp_intf);
            printf("FEC_2 = 0x%x\n", cint_ecmp_info.fec_id2);
            BCM_IF_ERROR_RETURN_MSG(l3__egress_only_fec__create_inner(unit, cint_ecmp_info.fec_id2, 0, cint_ecmp_info.encap_id1, gport_ecmp, BCM_L3_2ND_HIERARCHY, flags2, 0, 0, 0),
                "create egress object FEC only");

            fec_array_hier2[iter_2nd] = cint_ecmp_info.fec_id2;
            cint_ecmp_info.fec_id2++;
            cint_ecmp_info.encap_id1++;
            cint_ecmp_info.arp_next_hop_mac[5]++;
            cint_ecmp_info.ecmp_id3++;
        }

        /*
         * 9. Create the second hierarchy ECMP group with the list of FECs in hierarchy 2.
         */
        BCM_IF_ERROR_RETURN_MSG(l3__ecmp_create(unit, cint_ecmp_info.ecmp_id2, NOF_2ND_HIER_FECS, fec_array_hier2,
            BCM_L3_WITH_ID | BCM_L3_2ND_HIERARCHY, BCM_L3_ECMP_DYNAMIC_MODE_DISABLED, &ecmp,0), "create ECMP group 2nd hierarchy");

        BCM_L3_ITF_FEC_TO_GPORT_FORWARD_GROUP(gport_ecmp, ecmp.ecmp_intf);
        /*
         * 10. Create first level FECs that point to a second level ECMP group
         */
        printf("FEC_1 = 0x%x\n", cint_ecmp_info.fec_id1);
        BCM_IF_ERROR_RETURN_MSG(l3__egress_only_fec__create_inner(unit, cint_ecmp_info.fec_id1, 0, cint_ecmp_info.intf_out, gport_ecmp, 0, flags2, 0, 0, 0),
            "create egress object FEC only");

        fec_array_hier1[iter_1st] = cint_ecmp_info.fec_id1;
        cint_ecmp_info.fec_id1++;
        cint_ecmp_info.intf_out++;
        cint_ecmp_info.ecmp_id2++;
    }

    /*
     * 11. Create AC-Ptr for 3rd-hier FECs and set its properties
     */
    BCM_IF_ERROR_RETURN_MSG(out_vlan_port_intf_set(unit, cint_ecmp_info.out_port, cint_ecmp_info.encap_id2, &lif_as_gport), "out_port");

    /*
     * Add VLAN editing for encap stage (using UNTAG tag_struct - 0)
     */
    BCM_IF_ERROR_RETURN_MSG(vlan_translate_ive_eve_translation_set(unit, lif_as_gport, cint_ecmp_info.outer_tpid,
                                                cint_ecmp_info.inner_tpid, bcmVlanActionAdd, bcmVlanActionAdd,
                                                cint_ecmp_info.new_outer_vlan, cint_ecmp_info.new_inner_vlan, 1, 0, 0), "");

    /*
     * 12. Create first hierarchy ECMP group with the list of FECs in 1st hierarchy
     */
    BCM_IF_ERROR_RETURN_MSG(l3__ecmp_create(unit, cint_ecmp_info.ecmp_id1, NOF_1ST_HIER_FECS, fec_array_hier1, BCM_L3_WITH_ID,
                         BCM_L3_ECMP_DYNAMIC_MODE_DISABLED, &ecmp,0), "create ECMP group 1st hierarchy");

    /*
     * 13. Add host entry with the 1H ECMP group as result
     */
    BCM_IF_ERROR_RETURN_MSG(add_route_ipv4(unit, cint_ecmp_info.host, cint_ecmp_info.mask, cint_ecmp_info.vrf, ecmp.ecmp_intf), "");

    return BCM_E_NONE;
}
