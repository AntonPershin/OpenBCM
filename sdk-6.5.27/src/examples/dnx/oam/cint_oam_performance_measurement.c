/*
 * 
 This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 
 Copyright 2007-2022 Broadcom Inc. All rights reserved. File: cint_oam_performance_measurement.c Purpose: basic examples for OAM loss and delay measurement.
 */

/* Short group indication */
int is_short_maid = 1;
int is_jumbo_dm = 0;
bcm_oam_endpoint_t oam_perf_up_mep_id = 4096;
bcm_oam_endpoint_t oam_perf_down_mep_id = 4100;
bcm_oam_endpoint_t oam_perf_lmm_up_mep_id = 10280;
bcm_oam_endpoint_t oam_perf_dmm_up_mep_id = 4105;
bcm_oam_endpoint_t oam_perf_dmm_down_mep_id = 4108;
bcm_oam_endpoint_t oam_perf_lmm_down_mep_id = 10284;

bcm_mac_t src_mac_up = {0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff};
bcm_mac_t src_mac_down = {0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0x01};
int nof_mep = 0;
int jumbo_with_Id = 1;


/** LM/DM reports */
uint32 last_delta_FCB = -1;
uint32 last_delta_FCf = -1;
uint32 acc_delta_FCB = 0;
uint32 acc_delta_FCf = 0;
uint32 delay_report_count = 0;
uint64 last_delay;
uint64 last_delay_near;

uint32 last_Tx_FCf = 0;
uint32 last_Rx_FCf = 0;
uint32 last_Tx_FCb = 0;
uint32 last_Rx_FCb = 0;
uint64 last_Tx_Timef;
uint64 last_Rx_Timef;
uint64 last_Tx_Timeb;
uint64 last_Rx_Timeb;

int oam_lm_dm_reports_enabled = 0;
int is_pcp_based_count = 0;


/**
 * Jumbo DM tlv feature is used to support the DM length to 9600 bytes. User needs to know below things about this feature
 *     Only 1K endpoints can be supported, the MEP entry is allocated by steps 64 with ID. 
 *     Mep memory allocation is SelfContained, short maid and ICC maid support 512 entries respectively.
 *     256 MEPs can support DMM/DMR with TLV length up to 9600.
 *     TLV length was configurable, and must be 12*N (N>=0)
 *     Data pattern is 4Bytes repeatable pattern
 *     Data TLV of DMR is from local DMM configuration
 *
 *  This example demonstrate how to create 1024 mep and 256 Jumbo dm entry
 *
 * @param unit
 * @param port1 - 
 * @param port2 - 
 *
 * @return int
 */
int dnx_oam_jumbo_dm_run_range(
    int unit,
    bcm_port_t port1,
    bcm_port_t port2)
{
    bcm_gport_t gport1;
    bcm_gport_t gport2;
    bcm_oam_group_info_t group_info_short;
    bcm_oam_group_info_t group_info_long;
    bcm_mac_t my_cfm_mac = {0x00, 0x00, 0x00, 0xff, 0xff, 0xff};
    uint32 flags = 0;
    bcm_oam_profile_t ingress_profile = 1;
    bcm_oam_profile_t egress_profile  = 1;
    bcm_oam_profile_t acc_ingress_profile = 1;
    bcm_oam_profile_t acc_egress_profile = 1;
    int lm_counter_base_id_0;
    int lm_counter_base_id_1;
    int counter_if_0 = 0;
    int counter_if_1 = 1;
    int vid = 5;
    int index = 0;
    int mepid_steps = 0;
    uint8 long_ma_name[BCM_OAM_GROUP_NAME_LENGTH] = {1, 32, 13, 01, 02, 03, 04, 05, 06, 07, 08, 09, 0xa, 0xb, 0xc, 0xd};
    uint8 short_ma_name[BCM_OAM_GROUP_NAME_LENGTH] = {1, 3, 2, 0xab, 0xcd};

    /*
     * Create OAM group
     */
    bcm_oam_group_info_t_init(group_info_short);
    group_info_short.flags = BCM_OAM_GROUP_WITH_ID;
    group_info_short.id = 7;
    bcm_oam_group_info_t_init(group_info_long);
    group_info_long.flags = BCM_OAM_GROUP_WITH_ID;
    group_info_long.id = 9;
    /* Short MAID */
    sal_memcpy(group_info_short.name, short_ma_name, BCM_OAM_GROUP_NAME_LENGTH);
    BCM_IF_ERROR_RETURN_MSG(bcm_oam_group_create(unit, group_info_short), "");

    /* Long MAID */
    sal_memcpy(group_info_long.name, long_ma_name, BCM_OAM_GROUP_NAME_LENGTH);
    BCM_IF_ERROR_RETURN_MSG(bcm_oam_group_create(unit, group_info_long), "");
    
    /*
     * Setting My-CFM-MAC
     */
    BCM_IF_ERROR_RETURN_MSG(oam__my_cfm_mac_set(unit, port2, my_cfm_mac), "");
    dnx_oam_results_glb.station_id[0] = gl_station_id;

    /*
     * Allocate counter engines and get counters
     */
    BCM_IF_ERROR_RETURN_MSG(set_counter_resource(unit, port2, counter_if_0, 1, &lm_counter_base_id_0), "");

    BCM_IF_ERROR_RETURN_MSG(set_counter_resource(unit, port2, counter_if_1, 1, &lm_counter_base_id_1), "");

    /*
     * Get default profile encoded values.
     * Default profile is 1 and is configured
     * on init(application) stage.
     */
    BCM_IF_ERROR_RETURN_MSG(bcm_oam_profile_id_get_by_type(unit, ingress_profile, bcmOAMProfileIngressLIF, &flags, &ingress_profile), "");

    BCM_IF_ERROR_RETURN_MSG(bcm_oam_profile_id_get_by_type(unit, egress_profile, bcmOAMProfileEgressLIF, &flags, &egress_profile), "");

    BCM_IF_ERROR_RETURN_MSG(bcm_oam_profile_id_get_by_type(unit, acc_ingress_profile, bcmOAMProfileIngressAcceleratedEndpoint, &flags, &acc_ingress_profile), "");

    BCM_IF_ERROR_RETURN_MSG(bcm_oam_profile_id_get_by_type(unit, acc_egress_profile, bcmOAMProfileEgressAcceleratedEndpoint, &flags, &acc_egress_profile), "");
	
    /**1, test create 1k MEP entry*/
    for (index = 0; index < 1024; index ++ )
    {

        /*
         * Create cross-connected VLAN ports
         */
        BCM_IF_ERROR_RETURN_MSG(dnx_oam_cross_connected_vlan_ports_create(unit, port1, port2, vid+nof_mep, vid+nof_mep, &gport1, &gport2), "");
    
        BCM_IF_ERROR_RETURN_MSG(bcm_oam_lif_profile_set(unit, 0, gport2, ingress_profile, egress_profile), "");

        mepid_steps = 64 * index;
        nof_mep ++;
        jumbo_with_Id = 1;
        printf("+++ create %d mep +++ \n", nof_mep);
        /*
         * Create accelerated Down-MEP
         */
        BCM_IF_ERROR_RETURN_MSG(dnx_oam_accelerated_endpoint_create(unit, 0 + mepid_steps, gport2, /*group_info_short.id*/(index >127) ? group_info_short.id : group_info_long.id,
                                                 counter_if_1, lm_counter_base_id_1, acc_ingress_profile, port2, 0, BCM_OAM_OPCODE_CCM_IN_HW), "");
    }
    
    for (index = 0; index < 1024; index ++ )
    {
        BCM_IF_ERROR_RETURN_MSG(bcm_oam_endpoint_destroy(unit, 64 * index), "");
    }
    printf(" free 1024 entries done.\n");


    /** 2: test create 256 DM entry*/
    for (index = 0; index < 256; index ++ )
    {
        /*
         * Create cross-connected VLAN ports
         */
        BCM_IF_ERROR_RETURN_MSG(dnx_oam_cross_connected_vlan_ports_create(unit, port1, port2, vid+nof_mep, vid+nof_mep, &gport1, &gport2), "");
    
        BCM_IF_ERROR_RETURN_MSG(bcm_oam_lif_profile_set(unit, 0, gport2, ingress_profile, egress_profile), "");

        mepid_steps = 64 * index;
        nof_mep ++;
        jumbo_with_Id = 1;
        printf("+++ create %d mep +++ \n", index);
        /*
         * Create accelerated Down-MEP
         */
        BCM_IF_ERROR_RETURN_MSG(dnx_oam_accelerated_endpoint_create(unit, 0 + mepid_steps, gport2, /*group_info_short.id*/(index >=128) ? group_info_short.id : group_info_long.id,
                                                 counter_if_1, lm_counter_base_id_1, acc_ingress_profile, port2, 0, BCM_OAM_OPCODE_CCM_IN_HW), "");
        BCM_IF_ERROR_RETURN_MSG(dnx_oam_delay_add(unit, mepid_steps, 16388 + mepid_steps, BCM_OAM_ENDPOINT_CCM_PERIOD_100MS), "");
    }
    
    for (index = 0; index < 256; index ++ )
    {
        BCM_IF_ERROR_RETURN_MSG(bcm_oam_endpoint_destroy(unit, 64 * index), "");
    }
    printf("  Again : free 256 entries.\n");
    
    return BCM_E_NONE;
}

/**
 * Create an accelerated Up-MEP with ID 4096 and level 5
 * and an accelerated Down-MEP with ID 4100 and level 2.
 * Up-MEP will have a loss (with extended statistics)
 * and a delay entry.
 * Down-MEP 4100 will have a piggy-back loss entry.
 *
 * @param unit
 * @param port1
 * @param port2
 *
 * @return int
 */
int dnx_oam_lm_dm_run_with_defaults(
    int unit,
    bcm_port_t port1,
    bcm_port_t port2)
{
    bcm_gport_t gport1;
    bcm_gport_t gport2;
    bcm_oam_group_info_t group_info;
    bcm_mac_t my_cfm_mac = {0x00, 0x00, 0x00, 0xff, 0xff, 0xff};
    uint32 flags = 0;
    bcm_oam_profile_t ingress_profile = 1;
    bcm_oam_profile_t egress_profile  = 1;
    bcm_oam_profile_t acc_ingress_profile;
    bcm_oam_profile_t acc_egress_profile = 1;
    int lm_counter_base_id_0;
    int lm_counter_base_id_1;
    int counter_if_0 = 0;
    int counter_if_1 = 1;
    int vid = 5;
    int core_id=0; 
    bcm_oam_control_key_t keyA;
    uint32 rcy_port = 60;
    uint64 arg;
    int up_mep_tod_recycle_enable = *(dnxc_data_get(unit,  "oam", "feature", "up_mep_tod_recycle_enable", NULL));
    int device_type_v2;

    device_type_v2 = *(dnxc_data_get(unit,  "oam", "oamp", "oamp_v2", NULL));

    /*
     * Create cross-connected VLAN ports
     */
    BCM_IF_ERROR_RETURN_MSG(dnx_oam_cross_connected_vlan_ports_create(unit, port1, port2, vid, vid, &gport1, &gport2), "");

    /*
     * Setting My-CFM-MAC
     */
    BCM_IF_ERROR_RETURN_MSG(oam__my_cfm_mac_set(unit, port2, my_cfm_mac), "");

    dnx_oam_results_glb.station_id[0] = gl_station_id;

    if(device_type_v2)
    {
        /*
         * For OAMP V2, accelerated OAM and BFD endpoints are
         * stored in multiple entries of variable number.  Endpoint
         * ID ranges are reserved for the different sizes, so these
         * values are in the allowed ranges for their EP types.
         */
        oam_perf_up_mep_id = 128;
        oam_perf_down_mep_id = 130;
        counter_if_1 = 0;
    }
    else
    {
        /*
         * Allocate counter engines and get counters
         */
        BCM_IF_ERROR_RETURN_MSG(set_counter_resource(unit, port2, counter_if_0, 1, &lm_counter_base_id_0), "");

        BCM_IF_ERROR_RETURN_MSG(set_counter_resource(unit, port2, counter_if_1, 1, &lm_counter_base_id_1), "");
    }

    /*
     * Get default profile encoded values.
     * Default profile is 1 and is configured
     * on init(application) stage.
     */
    BCM_IF_ERROR_RETURN_MSG(bcm_oam_profile_id_get_by_type(unit, ingress_profile, bcmOAMProfileIngressLIF, &flags, &ingress_profile), "");

    BCM_IF_ERROR_RETURN_MSG(bcm_oam_profile_id_get_by_type(unit, egress_profile, bcmOAMProfileEgressLIF, &flags, &egress_profile), "");

    BCM_IF_ERROR_RETURN_MSG(oam_set_of_action_profiles_create(unit), "");

    acc_ingress_profile = oam_acc_lif_profiles.oam_acc_profile_eth_dual_ended;

    if(is_jumbo_dm)
    {
        acc_ingress_profile=1;
    }

    BCM_IF_ERROR_RETURN_MSG(bcm_oam_profile_id_get_by_type(unit, acc_ingress_profile, bcmOAMProfileIngressAcceleratedEndpoint, &flags, &acc_ingress_profile), "");

    BCM_IF_ERROR_RETURN_MSG(bcm_oam_profile_id_get_by_type(unit, acc_egress_profile, bcmOAMProfileEgressAcceleratedEndpoint, &flags, &acc_egress_profile), "");

    BCM_IF_ERROR_RETURN_MSG(bcm_oam_lif_profile_set(unit, 0, gport2, ingress_profile, egress_profile), "");

    /*
     * Create OAM group
     */
    bcm_oam_group_info_t_init(group_info);
    group_info.flags = BCM_OAM_GROUP_WITH_ID;
    group_info.id = 7;

    if(dnx_oam_endpoint_info_glb.use_48_maid)
    {
        /*
         * In OAMP v2, the 48B MAID is stored in the endpoint entry,
         * so group name index is irrelevant.
         */
        sal_memcpy(group_info.name, dnx_oam_endpoint_info_glb.str_48b_name, BCM_OAM_GROUP_NAME_LENGTH);
        group_info.flags = BCM_OAM_GROUP_WITH_ID | BCM_OAM_GROUP_FLEXIBLE_MAID_48_BYTE;
        if(device_type_v2)
        {
            oam_perf_up_mep_id = 18432;
            oam_perf_down_mep_id = 18437;
        }
        else
        {
            group_info.group_name_index = 0xA014; /* Should be multiple of 4 */
        }
    }
    else
    {
        /* In OAMP v2, "short" group names are obsolete.  Only ICC and 48B MAID are allowed. */
        sal_memcpy(group_info.name, dnx_oam_endpoint_info_glb.long_name, BCM_OAM_GROUP_NAME_LENGTH);
    }

    BCM_IF_ERROR_RETURN_MSG(bcm_oam_group_create(unit, group_info), "");

    /*
     * Create accelerated Up-MEP
     */
    BCM_IF_ERROR_RETURN_MSG(dnx_oam_accelerated_endpoint_create(unit, oam_perf_up_mep_id, gport2, group_info.id,
        counter_if_0, lm_counter_base_id_0, acc_egress_profile, 0, 1, BCM_OAM_OPCODE_CCM_IN_HW), "(Up MEP)");

    /*
     * Create accelerated Down-MEP
     */
    BCM_IF_ERROR_RETURN_MSG(dnx_oam_accelerated_endpoint_create(unit, oam_perf_down_mep_id, gport2, group_info.id,
                                             counter_if_1, lm_counter_base_id_1, acc_ingress_profile, port2, 0,
                                             BCM_OAM_OPCODE_CCM_IN_HW), "(Down MEP)");

    /* Create action of trapping incoming delay measurement packet for down-MEPs */
    BCM_IF_ERROR_RETURN_MSG(oam_set_opcode_destination_to_oamp(unit, 1/**ingress */, acc_ingress_profile, bcmOamOpcodeDMM, bcmOAMEndpointTypeEthernet),
        "could not create action for DMM.");

    /* Create action of trapping incoming loss measurement packet for down-MEPs */
    BCM_IF_ERROR_RETURN_MSG(oam_set_opcode_destination_to_oamp(unit, 1/**ingress */, acc_ingress_profile, bcmOamOpcodeLMM, bcmOAMEndpointTypeEthernet),
        "could not create action for LMM.");

    /* Create action of trapping incoming delay measurement response packet for down-MEPs */
    BCM_IF_ERROR_RETURN_MSG(oam_set_opcode_destination_to_oamp(unit, 1/**ingress */, acc_ingress_profile, bcmOamOpcodeDMR, bcmOAMEndpointTypeEthernet),
        "could not create action for DMR.");

    /* Create action of trapping incoming loss measurement response packet for down-MEPs */
    BCM_IF_ERROR_RETURN_MSG(oam_set_opcode_destination_to_oamp(unit, 1/**ingress */, acc_ingress_profile, bcmOamOpcodeLMR, bcmOAMEndpointTypeEthernet),
        "could not create action for LMR.");


    if(device_type_v2)
    {
        /*
         * Create loss measurement endpoint - in OAMP v2, loss measurement is done with a separate endpoint,
         * instead of being an attribute of a CCM endpoint.  Therefore, CCM, LM and DM endpoints are allowed
         * on the same LIF and level.
         */
        BCM_IF_ERROR_RETURN_MSG(dnx_oam_accelerated_endpoint_create(unit, oam_perf_lmm_up_mep_id, gport2, group_info.id,
            counter_if_0, lm_counter_base_id_0, acc_egress_profile, 0, 1, BCM_OAM_OPCODE_LMM_IN_HW), "(Up MEP LMM)");

        /*
         * Create delay measurement endpoint - in OAMP v2, delay measurement is done with a separate endpoint,
         * as well.
         */
        BCM_IF_ERROR_RETURN_MSG(dnx_oam_accelerated_endpoint_create(unit, oam_perf_dmm_down_mep_id, gport2, group_info.id,
            counter_if_0, lm_counter_base_id_0, acc_ingress_profile, port2, 0, BCM_OAM_OPCODE_DMM_IN_HW), "(Down MEP DMM)");

        /*
         * Create delay measurement endpoint - up-MEP
         */
        BCM_IF_ERROR_RETURN_MSG(dnx_oam_accelerated_endpoint_create(unit, oam_perf_dmm_up_mep_id, gport2, group_info.id,
            counter_if_0, lm_counter_base_id_0, acc_egress_profile, 0, 1, BCM_OAM_OPCODE_DMM_IN_HW), "(Up MEP DMM)");
    }
    else
    {
        if(is_jumbo_dm)
        {
            /*
             * Add delay on Up-MEP
             */
            BCM_IF_ERROR_RETURN_MSG(dnx_oam_delay_add(unit, oam_perf_up_mep_id, 65552, BCM_OAM_ENDPOINT_CCM_PERIOD_100MS), "");
            /*
             * Add delay on Down-MEP
             */
            BCM_IF_ERROR_RETURN_MSG(dnx_oam_delay_add(unit, oam_perf_down_mep_id, 65556, BCM_OAM_ENDPOINT_CCM_PERIOD_100MS), "");
        }
        else
        {
            /*
             * Add loss on Up-MEP
             */
            BCM_IF_ERROR_RETURN_MSG(dnx_oam_loss_add(unit, oam_perf_up_mep_id, 65552, BCM_OAM_ENDPOINT_CCM_PERIOD_10MS, 0, 1), "");

            if(up_mep_tod_recycle_enable)
            {
                for(core_id=0; core_id<=1; core_id++)
                {
                    keyA.type = bcmOamControlUpMepDmRecyclePort;
                    keyA.index = core_id;
                    COMPILER_64_SET(arg, 0, rcy_port+core_id);
                    BCM_IF_ERROR_RETURN_MSG(bcm_oam_control_indexed_set(0,keyA,arg), "");
                }
            }
            /*
             * Add delay on Up-MEP
             */
            BCM_IF_ERROR_RETURN_MSG(dnx_oam_delay_add(unit, oam_perf_up_mep_id, 0, BCM_OAM_ENDPOINT_CCM_PERIOD_10MS), "");

            /*
             * Add CCM piggy-back loss on Down-MEP
             */
            BCM_IF_ERROR_RETURN_MSG(dnx_oam_loss_add(unit, oam_perf_down_mep_id, 65556, BCM_OAM_ENDPOINT_CCM_PERIOD_10MS, 1, 1), "");
        }
    }

    return BCM_E_NONE;
}


/**
 * Create accelerated OAM endpoint
 *
 * @param unit
 * @param mep_id - OAM endpoint ID
 * @param gport - VLAN port ID
 * @param group_id - OAM group ID
 * @param lm_counter_if - LM counter interface
 * @param lm_counter_base_id - LM counter pointer
 * @param acc_profile - accelerated profile ID
 * @param tx_port - relevant for Down-MEP only
 * @param is_up - Up-MEP indication
 *
 * @return int
 */
int dnx_oam_accelerated_endpoint_create(
    int unit,
    bcm_oam_endpoint_t mep_id,
    bcm_gport_t gport,
    bcm_oam_group_t group_id,
    int lm_counter_if,
    int lm_counter_base_id,
    int acc_profile,
    bcm_port_t tx_port,
    uint8 is_up,
    uint32 opcode_flags)
{
    bcm_oam_endpoint_info_t acc_endpoint;
    bcm_oam_endpoint_info_t remote_endpoint;
    uint8 is_ccm, is_dm, is_slm;

    is_ccm = ((opcode_flags == BCM_OAM_OPCODE_CCM_IN_HW) || (opcode_flags == BCM_OAM_OPCODE_DUAL_ENDED_LM));
    is_dm = ((opcode_flags == BCM_OAM_OPCODE_DMM_IN_HW) ||
             (opcode_flags == BCM_OAM_OPCODE_1DM_IN_HW));
    is_slm = (opcode_flags == BCM_OAM_OPCODE_SLM_IN_HW);

    /*
     * Adding accelerated endpoint
     */
    bcm_oam_endpoint_info_t_init(&acc_endpoint);
    acc_endpoint.endpoint_memory_type = bcmOamEndpointMemoryTypeSelfContained;
    acc_endpoint.type = bcmOAMEndpointTypeEthernet;
    acc_endpoint.flags = (jumbo_with_Id && !oam_lm_dm_reports_enabled) ? BCM_OAM_ENDPOINT_WITH_ID : 0;
    if (is_up)
    {
        acc_endpoint.flags |= BCM_OAM_ENDPOINT_UP_FACING;
    }
    acc_endpoint.id = mep_id;
    acc_endpoint.gport = gport;
    acc_endpoint.group = group_id;
    acc_endpoint.ccm_period = BCM_OAM_ENDPOINT_CCM_PERIOD_10MS;
    acc_endpoint.opcode_flags = opcode_flags;
    acc_endpoint.acc_profile_id = acc_profile;
    acc_endpoint.vlan = 5;
    acc_endpoint.pkt_pri = 0 + (2<<1);  /* dei(1bit) + (pcp(3bit) << 1) */
    acc_endpoint.outer_tpid = 0x8100;
    acc_endpoint.lm_counter_base_id = lm_counter_base_id;
    acc_endpoint.lm_counter_if = lm_counter_if;
    if (is_pcp_based_count)
    {
        acc_endpoint.pkt_pri = 0;
        acc_endpoint.lm_flags = BCM_OAM_LM_PCP;
    }

    if (is_up)
    {
        acc_endpoint.level = 5;
        if(is_ccm)
        {
            acc_endpoint.name = 124;
        }
        sal_memcpy(acc_endpoint.src_mac_address, src_mac_up, 6);
    }
    else
    {
        acc_endpoint.level = 2;
        if(is_ccm)
        {
            acc_endpoint.name = 127;
        }
        BCM_GPORT_SYSTEM_PORT_ID_SET(acc_endpoint.tx_gport, tx_port);
        sal_memcpy(acc_endpoint.src_mac_address, src_mac_down, 6);
    }
    if(is_dm)
    {
        if(is_jumbo_dm)
        {
            acc_endpoint.tlvs[0].tlv_length= 950;

            
        }
        else
        {
            acc_endpoint.tlvs[0].tlv_length = 6;
        }
        acc_endpoint.tlvs[0].tlv_type = bcmOamTlvTypeData;
    }

    if (!is_ccm)
    {
        /*
         * In OAMP V2, we use LM and DM MEPs to generate LMM
         * and DMM.  Unlike CCM, these packets have a
         * configurable DMAC - use dst_mac_address
         * to set it.
         */
        sal_memset(acc_endpoint.dst_mac_address, 0, 6);
        acc_endpoint.dst_mac_address[1] = 0xAB;
        acc_endpoint.dst_mac_address[3] = 0xEF;
    }


    BCM_IF_ERROR_RETURN_MSG(bcm_oam_endpoint_create(unit, acc_endpoint), "");

    printf("Created Local MEP: ID %d\n", acc_endpoint.id);

    if(is_ccm)
    {
        if (is_up)
        {
            oam_perf_up_mep_id = acc_endpoint.id;
        }
        else
        {
            oam_perf_down_mep_id = acc_endpoint.id;
        }
    }
    else
    {
        if(is_dm)
        {
            if (is_up)
            {
                oam_perf_dmm_up_mep_id = acc_endpoint.id;
            }
            else
            {
                oam_perf_dmm_down_mep_id = acc_endpoint.id;
            }
        }
        else
        {
            if (is_up)
            {
                oam_perf_lmm_up_mep_id = acc_endpoint.id;
            }
            else
            {
                oam_perf_lmm_down_mep_id = acc_endpoint.id;
            }
        }
    }

    if(is_ccm)
    {
        /*
         * Adding Remote MEP
         * For OAMP v2, not all endpoints are CCM - but remote
         * endpoints are relevant only for CCM endpoints.
         */
        bcm_oam_endpoint_info_t_init(remote_endpoint);
        remote_endpoint.flags = BCM_OAM_ENDPOINT_REMOTE;
        remote_endpoint.local_id = acc_endpoint.id;
        remote_endpoint.name = 0xff;
        remote_endpoint.loc_clear_threshold = 1;

        BCM_IF_ERROR_RETURN_MSG(bcm_oam_endpoint_create(unit, remote_endpoint), "");

        printf("Created RMEP: ID %d\n", remote_endpoint.id);
    }

    return BCM_E_NONE;
}

/**
 * Add loss measurement entries
 *
 * @param unit
 * @param mep_id - OAM endpoint ID
 * @param loss_id - LM entry ID
 * @param period - loss period
 * @param is_dual_ended_lm - CCM piggy-back indication
 *
 * @return int
 */
int dnx_oam_loss_add(
    int unit,
    bcm_oam_endpoint_t mep_id,
    int loss_id,
    int period,
    uint8 is_dual_ended_lm,
    uint8 use_extended_statistics)
{
    bcm_oam_loss_t loss;

    /*
     * Create LM entries
     */
    bcm_oam_loss_t_init(&loss);
    if (loss_id)
    {
        loss.flags = BCM_OAM_LOSS_WITH_ID;
    }

    if (use_extended_statistics)
    {
        loss.flags |= BCM_OAM_LOSS_STATISTICS_EXTENDED;
    }

    if (!is_dual_ended_lm)
    {
        loss.flags |= BCM_OAM_LOSS_SINGLE_ENDED;
        loss.peer_da_mac_address[1] = 0xab;
        loss.peer_da_mac_address[3] = 0xef;
    }

    loss.id = mep_id;
    loss.loss_id = loss_id;
    loss.period = period;
    BCM_IF_ERROR_RETURN_MSG(bcm_oam_loss_add(unit, &loss), "");

    return BCM_E_NONE;
}

/**
 * Add delay measurement entries
 *
 * @param unit
 * @param mep_id - OAM endpoint ID
 * @param delay_id - DM entry ID
 * @param period - delay period
 *
 * @return int
 */
int dnx_oam_delay_add(
    int unit,
    bcm_oam_endpoint_t mep_id,
    int delay_id,
    int period)
{
    bcm_oam_delay_t delay;

    /*
     * Create DM entries
     */
    bcm_oam_delay_t_init(&delay);
    if (delay_id)
    {
        delay.flags = BCM_OAM_LOSS_WITH_ID;
    }
    delay.id = mep_id;
    delay.peer_da_mac_address[1] = 0xab;
    delay.peer_da_mac_address[3] = 0xef;
    delay.delay_id = delay_id;
    delay.period = period;
    delay.timestamp_format = bcmOAMTimestampFormatIEEE1588v1;
    if(is_jumbo_dm)
    {
        delay.tlvs[0].tlv_type = bcmOamTlvTypeData;
        delay.tlvs[0].tlv_length= 9600;
        delay.tlvs[0].four_byte_repeatable_pattern= 0xabcdeeff;
    }
    BCM_IF_ERROR_RETURN_MSG(bcm_oam_delay_add(unit, &delay), "");

    return BCM_E_NONE;
}

/* This is an example of using bcm_oam_performance_event_register api.
 * A simple callback is created for lm/dm report events.
 * Triggered upon LM/DM report rx.
 */
int cb_stat(int unit,
            bcm_oam_event_type_t event_type,
            bcm_oam_group_t group,
            bcm_oam_endpoint_t endpoint,
            bcm_oam_performance_event_data_t *event_data,
            void *user_data) {

   print unit;
   print event_type;
   print group;
   print endpoint;
   print *event_data;

    /* Update globals */
    switch (event_type) {
    case bcmOAMEventEndpointDmStatistics:
        delay_report_count++;
        last_delay = event_data->last_delay;
        last_delay_near = event_data->last_delay_near;
        last_Tx_Timef = event_data->Tx_Timef;
        last_Rx_Timef = event_data->Rx_Timef;
        last_Tx_Timeb = event_data->Tx_Timeb;
        last_Rx_Timeb = event_data->Rx_Timeb;
        break;
    case bcmOAMEventEndpointLmStatistics:
        last_delta_FCB = event_data->delta_FCB;
        acc_delta_FCB+= last_delta_FCB;
        last_delta_FCf = event_data->delta_FCf;
        acc_delta_FCf+= last_delta_FCf;

        last_Tx_FCf = event_data->Tx_FCf;
        last_Rx_FCf = event_data->Rx_FCf;
        last_Tx_FCb = event_data->Tx_FCb;
        last_Rx_FCb = event_data->Rx_FCb;
        break;
    }

    return BCM_E_NONE;
}

/* Indicate if checking delay MSB will be done */
int is_check_delay_msb = 0;
/* Indicate the first 0 delay MSB is reported */
int is_first_zero_delay_msb = 0;
/* Indicate the second 0 delay MSB is reported right after the first 0*/
int is_second_zero_delay_msb = 0;
/* Indicate if sudden zero is found */
int is_sudden_zero_delay_msb = 0;

/*
 * This is callback function specific for checking if sunden zero happens to delay MSB.
 * sudden zero means the previous is not zero and the next is not zero
 *   zero, zero, non-zero, this sequence is not sudden zero;
 *   non-zero, zero, zero, this sequence is not sudden zero;
 *   non-zero, zero, non-zero, this sequence is sudden zero;
 */
int cb_stat_check_delay_msb(int unit,
            bcm_oam_event_type_t event_type,
            bcm_oam_group_t group,
            bcm_oam_endpoint_t endpoint,
            bcm_oam_performance_event_data_t *event_data,
            void *user_data) {
    uint32 delay_msb;
    delay_msb = COMPILER_64_HI(event_data->last_delay);

    if (0 == delay_msb)
    {
        /* Mark the first zero and second zero delay MSB */
        if (0 == is_first_zero_delay_msb)
        {
            is_first_zero_delay_msb = 1;
        }
        else if (0 == is_second_zero_delay_msb)
        {
            is_second_zero_delay_msb = 1;
        }
    }
    else
    {
        /* Mark if sudden zero occurs */
        if ((0 == is_second_zero_delay_msb) && (0 != is_first_zero_delay_msb))
        {
            is_sudden_zero_delay_msb = 1;
        }
        else
        {
            is_first_zero_delay_msb = 0;
            is_second_zero_delay_msb = 0;
        }
    }
    return BCM_E_NONE;
}

/**
 * Register OAM performance events registered using funtion register_events

 *
 * @param unit
 * @return int
 */
int register_performance_events(int unit)
{
    bcm_oam_performance_event_cb cb = NULL;
    bcm_oam_event_types_t loss_event, delay_event;

    if (is_check_delay_msb)
    {
        cb = cb_stat_check_delay_msb;
    }
    else
    {
        cb = cb_stat;
    }

    BCM_OAM_EVENT_TYPE_SET(loss_event, bcmOAMEventEndpointLmStatistics);
    BCM_IF_ERROR_RETURN_MSG(bcm_oam_performance_event_register(unit, loss_event, cb, (void*)1), "");

    BCM_OAM_EVENT_TYPE_SET(delay_event, bcmOAMEventEndpointDmStatistics);
    BCM_IF_ERROR_RETURN_MSG(bcm_oam_performance_event_register(unit, delay_event, cb, (void*)2), "");

    return BCM_E_NONE;
}

/**
 * Create and remove loss, delay entries for endpoints.
 *
 * Afterwards create 2 accelerated endpoints (up and down) for
 * testing traffic.
 *
 * @param unit
 * @param port1
 * @param port2
 * @param port3
 * @param seed seed used for randomizations
 *
 * @return int
 */
int dnx_oam_lm_dm_run_test(
    int unit,
    bcm_port_t port1,
    bcm_port_t port2)
{
    bcm_gport_t gport1;
    bcm_gport_t gport2;
    bcm_oam_group_info_t group_info;
    bcm_mac_t my_cfm_mac = {0x00, 0x00, 0x00, 0xff, 0xff, 0xff};
    uint32 flags = 0;
    bcm_oam_profile_t ingress_profile = 1;
    bcm_oam_profile_t egress_profile  = 1;
    bcm_oam_profile_t acc_ingress_profile = 1;
    bcm_oam_profile_t acc_egress_profile = 1;
    int lm_counter_base_id_0;
    int lm_counter_base_id_1;
    int counter_if_0 = 0;
    int counter_if_1 = 1;
    int vid = 5;
    uint64 arg;
    bcm_oam_performance_event_cb cb = NULL;

    /*
     * Create cross-connected VLAN ports
     */
    BCM_IF_ERROR_RETURN_MSG(dnx_oam_cross_connected_vlan_ports_create(unit, port1, port2, vid, vid, &gport1, &gport2), "");

    /*
     * Setting My-CFM-MAC
     */
    BCM_IF_ERROR_RETURN_MSG(oam__my_cfm_mac_set(unit, port2, my_cfm_mac), "");

    dnx_oam_results_glb.station_id[0] = gl_station_id;


    if (is_pcp_based_count) {
        COMPILER_64_ZERO(arg);
        BCM_IF_ERROR_RETURN_MSG(bcm_oam_control_set(unit, bcmOamControlLmPcpCounterRangeMin, arg), "");
        BCM_IF_ERROR_RETURN_MSG(bcm_oam_control_set(unit, bcmOamControlLmPcpCounterRangeMax, arg), "");
    }

    /*
     * Allocate counter engines and get counters
     */
    BCM_IF_ERROR_RETURN_MSG(set_counter_resource(unit, port2, counter_if_0, 1, &lm_counter_base_id_0), "");

    /* Different counter bases and interfaces on the same LIF only allowed when hierachical LM is supported */
    if (*dnxc_data_get(unit, "oam", "general", "oam_hlm_support", NULL))
    {
        BCM_IF_ERROR_RETURN_MSG(set_counter_resource(unit, port2, counter_if_1, 1, &lm_counter_base_id_1), "");
    }
    else
    {
        lm_counter_base_id_1 = lm_counter_base_id_0;
        counter_if_1 = counter_if_0;
    }

    /*
     * Get default profile encoded values.
     * Default profile is 1 and is configured
     * on init(application) stage.
     */
    BCM_IF_ERROR_RETURN_MSG(bcm_oam_profile_id_get_by_type(unit, ingress_profile, bcmOAMProfileIngressLIF, &flags, &ingress_profile), "");

    BCM_IF_ERROR_RETURN_MSG(bcm_oam_profile_id_get_by_type(unit, egress_profile, bcmOAMProfileEgressLIF, &flags, &egress_profile), "");

    BCM_IF_ERROR_RETURN_MSG(oam_set_of_action_profiles_create(unit), "");

    BCM_IF_ERROR_RETURN_MSG(bcm_oam_profile_id_get_by_type(unit, acc_ingress_profile, bcmOAMProfileIngressAcceleratedEndpoint, &flags, &acc_ingress_profile), "");

    BCM_IF_ERROR_RETURN_MSG(bcm_oam_profile_id_get_by_type(unit, acc_egress_profile, bcmOAMProfileEgressAcceleratedEndpoint, &flags, &acc_egress_profile), "");

    BCM_IF_ERROR_RETURN_MSG(bcm_oam_lif_profile_set(unit, 0, gport2, ingress_profile, egress_profile), "");

    /*
     * Create OAM group
     */
    bcm_oam_group_info_t_init(group_info);
    group_info.flags = BCM_OAM_GROUP_WITH_ID;
    group_info.id = 7;

    if(dnx_oam_endpoint_info_glb.use_48_maid)
    {
        /*
         * In OAMP v2, the 48B MAID is stored in the endpoint entry,
         * so group name index is irrelevant.
         */
        sal_memcpy(group_info.name, dnx_oam_endpoint_info_glb.str_48b_name, BCM_OAM_GROUP_NAME_LENGTH);
        group_info.flags = BCM_OAM_GROUP_WITH_ID | BCM_OAM_GROUP_FLEXIBLE_MAID_48_BYTE;
        group_info.group_name_index = 0xA014; /* Should be multiple of 4 */
    }
    else
    {
        /* In OAMP v2, "short" group names are obsolete.  Only ICC and 48B MAID are allowed. */
        sal_memcpy(group_info.name, dnx_oam_endpoint_info_glb.long_name, BCM_OAM_GROUP_NAME_LENGTH);
    }

    BCM_IF_ERROR_RETURN_MSG(bcm_oam_group_create(unit, group_info), "");

    /*
     * Create accelerated Up-MEP
     */
    BCM_IF_ERROR_RETURN_MSG(dnx_oam_accelerated_endpoint_create(unit, oam_perf_up_mep_id, gport2, group_info.id,
        counter_if_0, lm_counter_base_id_0, acc_egress_profile, 0, 1, BCM_OAM_OPCODE_CCM_IN_HW), "(Up MEP)");

    /*
     * Create accelerated Down-MEP
     */
    BCM_IF_ERROR_RETURN_MSG(dnx_oam_accelerated_endpoint_create(unit, oam_perf_down_mep_id, gport2, group_info.id,
                                             counter_if_1, lm_counter_base_id_1, acc_ingress_profile, port2, 0,
                                             BCM_OAM_OPCODE_CCM_IN_HW), "(Down MEP)");

    if (oam_lm_dm_reports_enabled)
    {
        COMPILER_64_SET(arg, 0, bcmOamReportModeTypeNormal);
        BCM_IF_ERROR_RETURN_MSG(bcm_oam_control_set(unit, bcmOamControlReportMode, arg), "");

        BCM_IF_ERROR_RETURN_MSG(register_performance_events(unit), "");
    }

    return BCM_E_NONE;
}
