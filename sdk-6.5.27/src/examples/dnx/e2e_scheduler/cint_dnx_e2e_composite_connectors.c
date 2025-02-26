/*~~~~~~~~~~~~~~~~~~~~~~~~~~Cosq: E2E Scheduling~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/*
 * 
 *
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2022 Broadcom Inc. All rights reserved.
 *
 * File: cint_dnx_e2e_composite_connectors.c
 * Purpose: Example of Composite Connector Validation
 *
 * Environment
 *    - Default Egress queue mapping in play.
 *    - Default Egress Port Scheduler hierarchy in play.
 *    - Default Ingress Scheduling Discipline (delay tolerance), queues sizes
 *    - Packet Size 1500 -  size should be aligned with credit source settings
 *
 * - Port Scheduler
 *   - CL Scheduler (SP mode)
 *     - 4 FQ Schedulers
 *       - 1 Queue Group / Connector Group (4 elements in bundle) - Composite
 *         1st Connector element (1st flow, CIR) connected to FQ-0
 *         1st Connector element (2nd flow, EIR) connected to FQ-2
 *         2nd Connector element (1st flow, CIR) connected to FQ-1
 *         2nd Connector element (2nd flow, EIR) connected to FQ-3
 *
 * - test run 1
 *   - Input
 *     - Queue - Cos 0
 *       Input 500 Mbps
 *     - Queue - Cos 1
 *       Input 500 Mbps
 *
 *   - Expected Output
 *     - Queue - Cos 0
 *       Expected Output 300 Mbps (CIR connector)
 *       Observed =>
 *     - Queue - Cos 1
 *       Expected Output 200 Mbps (CIR connector)
 *       Observed =>
 *
 * - test run 2
 *   - Input
 *     - Queue - Cos 0
 *       Input 500 Mbps
 *     - Queue - Cos 1
 *       Input 100 Mbps
 *
 *   - Expected Output
 *     - Queue - Cos 0
 *       Expected Output 300 Mbps (CIR connector)
 *       Observed =>
 *       Expected Output 100 Mbps (PIR connector)
 *       Observed =>
 *     - Queue - Cos 1
 *       Expected Output 100 Mbps (CIR connector)
 *       Observed =>
 *
 *  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 *  |                                                                                |
 *  |                                      |                                         |
 *  |                                     SPR (500 Mbps)                             |
 *  |                                      |                                         |
 *  |                                     \/                                         |
 *  |                                    +----+                                      |
 *  |                                   /      \                                     |
 *  |                                  /   HR   \                                    |
 *  |                                 /          \                                   |
 *  |                                +-----------+                                   |
 *  |                                      |                                         |
 *  |                                     SPR (500 Mbps)                             |
 *  |                                      |                                         |
 *  |                                     \/                                         |
 *  |                              +----------------+                                |
 *  |                             / CL (4 SP levels) \                               |
 *  |                            /                    \                              |
 *  |                           / SP0   SP1  SP2   SP3 \                             |
 *  |                          +------------------------+                            |
 *  |                            /      \   /        \                               |
 *  |                           /        \ /          \                              |
 *  |                         SPR         /           SPR                            |
 *  |                    (300 Mbps)      / \        (200 Mbps)                       |
 *  |                       /          SPR SPR           \                           |
 *  |                      /     (200 Mbps) (300 Mbps)    \                          |
 *  |                    /            /       \            \                         |
 *  |                   \/          \/        \/           \/                        |
 *  |                 +------+   +------+   +------+   +------+                      |
 *  |                /   FQ   \ /   FQ   \ /   FQ   \ /   FQ   \                     |
 *  |               +----------+----------+----------+----------+                    |
 *  |                      \          /          \            /                      |
 *  |                       \        /            \          /                       |
 *  |                      SPR     SPR            SPR     SPR                        |
 *  |                 (300 Mbps)(200 Mbps)   (300 Mbps)(200 Mbps)                    |
 *  |                         \   /                  \   /                           |
 *  |                         \/ \/                  \/ \/                           |
 *  |                        |     |                |     |                          |
 *  |                        |     |                |     |                          |
 *  |                        |     |                |     |                          |
 *  |                        |     |                |     |                          |
 *  |                        |     |                |     |                          |
 *  |                        +-----+                +-----+      +----------------+  |
 *  |                     Input:500 Mbps        Input:100 Mbps   |      KEY       |  |
 *  |                                                            +----------------+  |
 *  |                                                            |SPR- Rate Shaper|  |
 *  |                                                            |                |  |
 *  |                                                            +----------------+  |
 *  |               +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+                           |
 *  |               |   Figure 7: Composite Connectors   |                           |
 *  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 *
 */

/*
 * General Definitions
 */
int C5_NUM_COS = 4;
int C5_DEFAULT_E2E_SCHED_TYPE = bcmCosqSchedulerGportTypeHrEnhanced;

int C5_SCHED_CL_TYPE = bcmCosqSchedulerGportTypeClass4Sp;
int C5_SCHEDULER_MODE = BCM_COSQ_SP1;
int C5_SCHED_KBITS_SEC_MAX = 5000000; /* 5000 Mbps */
int C5_SCHED_KBITS_SEC_MAX_MARGIN = 100; /* 100 Kbps */
int C5_SCHED_MAX_BURST = 3000;
int C5_SCHED_MAX_BURST_MARGIN = 75;

int C5_E2E_INTERFACE_KBITS_SEC_MAX = 10000000; /* 10gbps */
int C5_E2E_INTERFACE_KBITS_SEC_MAX_MARGIN = 5000; /* 5000 kbps */

int C5_NBR_FQ_SCHEDULERS = 4;
int C5_SCHED_FQ_TYPE = bcmCosqSchedulerGportTypeFq;
int C5_SCHED_FQ0_MODE = BCM_COSQ_SP0;
int C5_SCHED_FQ1_MODE = BCM_COSQ_SP1;
int C5_SCHED_FQ2_MODE = BCM_COSQ_SP2;
int C5_SCHED_FQ3_MODE = BCM_COSQ_SP3;

int C5_CIR_KBITS_SEC_MAX = 3000000; /* 3000 Mbps */
int C5_CIR_KBITS_SEC_MAX_MARGIN = 100;
int C5_EIR_KBITS_SEC_MAX = 2000000; /* 2000 Mbps */
int C5_EIR_KBITS_SEC_MAX_MARGIN = 100;

int C5_CONN_FLAGS = (BCM_COSQ_GPORT_VOQ_CONNECTOR | BCM_COSQ_VOQ_CONNECTOR_GPORT_F_COMPOSITE);
int C5_CONN_MODE = BCM_COSQ_SP0;

int C5_QUEUE_FLAGS = (BCM_COSQ_GPORT_UCAST_QUEUE_GROUP | BCM_COSQ_GPORT_COMPOSITE);
/* handles */
int c5_my_modid = 0;
int credit_worth;

bcm_gport_t c5_gport_ucast_voq_connector_group0[32];
bcm_gport_t c5_gport_ucast_voq_connector_group0_sf2[32];
bcm_gport_t c5_gport_ucast_queue_group0[32];
bcm_gport_t c5_gport_ucast_scheduler[32];
bcm_gport_t c5_gport_ucast_scheduler_fq0[32];
bcm_gport_t c5_gport_ucast_scheduler_fq1[32];
bcm_gport_t c5_gport_ucast_scheduler_fq2[32];
bcm_gport_t c5_gport_ucast_scheduler_fq3[32];
bcm_gport_t c5_e2e_gport[32];
bcm_gport_t c5_e2e_parent_gport[32];
int c5_use_same_handles = 0;


void e2e_composite_connectors_display_handles(int idx)
{
    printf("  e2eGport(0x%x)\n", c5_e2e_gport[idx]);
    printf("    schedGport(0x%x)\n", c5_gport_ucast_scheduler[idx]);
    printf("    l3_fq0(0x%x) l3_fq1(0x%x) l3_fq2(0x%x) l3_fq3(0x%x)\n",
            c5_gport_ucast_scheduler_fq0[idx], c5_gport_ucast_scheduler_fq1[idx],
            c5_gport_ucast_scheduler_fq2[idx], c5_gport_ucast_scheduler_fq3[idx]);
    printf("    connGrp0Gport(0x%x) connGrp0Sf2Gport(0x%x)\n",
            c5_gport_ucast_voq_connector_group0[idx], c5_gport_ucast_voq_connector_group0_sf2[idx]);
    printf("    ucastGrp0Gport(0x%x)\n", c5_gport_ucast_queue_group0[idx]);
}


/* Added parameter: kbits_sec_max_port identify maximum bandwidth for the rate on the Scheduler and  E2E port. */
/* One example of running (see Negev UM for figure description is by running: main(500000) */
int e2e_composite_connectors_setup(int unit, int kbits_sec_max_port, int port_idx)
{
    int idx, port, system_port;
    bcm_gport_t dest_gport[32];
    bcm_gport_t sys_gport[32];
    int flags = 0, default_flags = 0, default_voq_flags = 0 , default_connector_flags = 0;
    int voq;
    bcm_cosq_gport_connection_t connection;
    int kbits_sec_max;
    int max_burst;
    int cosq = 0, fq_sched = 0;
    bcm_cosq_voq_connector_gport_t config;
    uint32 dummy_flags;
    bcm_port_interface_info_t interface_info;
    bcm_port_mapping_info_t mapping_info;
    bcm_cosq_ingress_queue_bundle_gport_config_t conf;
    bcm_port_resource_t resource;
    int delay_tolerance_level, rate_class;
    bcm_cosq_scheduler_gport_params_t params;


    printf("\nSetup\n");

    credit_worth = *(dnxc_data_get(unit, "iqs", "credit", "worth", NULL));
    int multiplier = credit_worth / 1024;
    C5_SCHED_MAX_BURST *= multiplier;
    C5_SCHED_MAX_BURST_MARGIN *= multiplier;


    C5_SCHED_KBITS_SEC_MAX = kbits_sec_max_port;


    if (c5_use_same_handles == 1) {
        default_flags = BCM_COSQ_SCHEDULER_GPORT_WITH_ID;
        default_voq_flags = BCM_COSQ_GPORT_WITH_ID;
        default_connector_flags = BCM_COSQ_VOQ_CONNECTOR_GPORT_F_WITH_ID;
        e2e_composite_connectors_display_handles(0);
    }

    idx = port_idx;

    port = idx + 1;
    system_port = idx + 1;
    BCM_GPORT_SYSTEM_PORT_ID_SET(sys_gport[idx], system_port);
    BCM_GPORT_LOCAL_SET(dest_gport[idx], port);


    BCM_IF_ERROR_RETURN_MSG(bcm_port_get(unit, port, &dummy_flags, &interface_info, &mapping_info), "");

    BCM_IF_ERROR_RETURN_MSG(bcm_stk_sysport_gport_set(unit, sys_gport[idx], dest_gport[idx]), "");


    /* create CL scheduler */

    params.type = bcmCosqSchedulerGportTypeClass4Sp;
    params.mode = bcmCosqSchedulerGportModeSimple;
    params.cl_wfq_mode = bcmCosqSchedulerGportClWfqModeNone;
    params.core = mapping_info.core;
    params.shared_order = bcmCosqSchedulerGportSharedOrderNone;

    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_scheduler_gport_add(unit, default_flags, params, &c5_gport_ucast_scheduler[idx]), "");

    /* COS 0, CL scheduler scheduling discipline configuration */
    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_sched_set(unit,
            c5_gport_ucast_scheduler[idx],
            0,
            C5_SCHEDULER_MODE,
            0), "");

    BCM_COSQ_GPORT_E2E_PORT_SET(c5_e2e_gport[idx], port);

    /* CL scheduler attach to E2E port scheduler */
    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_attach(unit, c5_e2e_gport[idx],
            c5_gport_ucast_scheduler[idx], 0), "");

    /* create scheduler FQ scheduler (instance 0) - will aggregrate all cos 0 queues */

    params.type = bcmCosqSchedulerGportTypeFq;
    params.mode = bcmCosqSchedulerGportModeSimple;
    params.cl_wfq_mode = bcmCosqSchedulerGportClWfqModeNone;
    params.core = mapping_info.core;
    params.shared_order = bcmCosqSchedulerGportSharedOrderNone;

    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_scheduler_gport_add(unit, default_flags, params, &c5_gport_ucast_scheduler_fq0[idx]), 0);


    /* COS 0, FQ scheduler (instance 0) scheduling discipline configuration, weight of 2 */
    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_sched_set(unit,
            c5_gport_ucast_scheduler_fq0[idx],
            0,
            C5_SCHED_FQ0_MODE,
            0), "");

    /* FQ scheduler (instance 0) attach to CL scheduler */
    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_attach(unit, c5_gport_ucast_scheduler[idx],
            c5_gport_ucast_scheduler_fq0[idx], 0), "");


    /* create scheduler FQ scheduler (instance 1) - will aggregrate all cos 1 queues */

    params.type = bcmCosqSchedulerGportTypeFq;
    params.mode = bcmCosqSchedulerGportModeSimple;
    params.cl_wfq_mode = bcmCosqSchedulerGportClWfqModeNone;
    params.core = mapping_info.core;
    params.shared_order = bcmCosqSchedulerGportSharedOrderNone;

    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_scheduler_gport_add(unit, default_flags, params, &c5_gport_ucast_scheduler_fq1[idx]), "");


    /* COS 0, FQ scheduler (instance 1) scheduling discipline configuration, weight of 4 */
    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_sched_set(unit,
            c5_gport_ucast_scheduler_fq1[idx],
            0,
            C5_SCHED_FQ1_MODE,
            0), "");

    /* FQ scheduler (instance 1) attach to CL scheduler */
    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_attach(unit, c5_gport_ucast_scheduler[idx],
            c5_gport_ucast_scheduler_fq1[idx], 0), "");

    /* create scheduler FQ scheduler (instance 2) - will aggregrate all cos 2 queues */

    params.type = bcmCosqSchedulerGportTypeFq;
    params.mode = bcmCosqSchedulerGportModeSimple;
    params.cl_wfq_mode = bcmCosqSchedulerGportClWfqModeNone;
    params.core = mapping_info.core;
    params.shared_order = bcmCosqSchedulerGportSharedOrderNone;

    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_scheduler_gport_add(unit, default_flags, params, &c5_gport_ucast_scheduler_fq2[idx]), "");

    /* COS 0, FQ scheduler (instance 2) scheduling discipline configuration, weight of 8 */
    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_sched_set(unit,
            c5_gport_ucast_scheduler_fq2[idx],
            0,
            C5_SCHED_FQ2_MODE,
            0), "");


    /* FQ scheduler (instance 2) attach to CL scheduler */
    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_attach(unit, c5_gport_ucast_scheduler[idx],
            c5_gport_ucast_scheduler_fq2[idx], 0), "");


    /* create scheduler FQ scheduler (instance 3) - will aggregrate all cos 3 queues */

    params.type = bcmCosqSchedulerGportTypeFq;
    params.mode = bcmCosqSchedulerGportModeSimple;
    params.cl_wfq_mode = bcmCosqSchedulerGportClWfqModeNone;
    params.core = mapping_info.core;
    params.shared_order = bcmCosqSchedulerGportSharedOrderNone;

    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_scheduler_gport_add(unit, default_flags, params, &c5_gport_ucast_scheduler_fq3[idx]), "");

    /* COS 0, FQ scheduler (instance 3) scheduling discipline configuration, weight of 16 */
    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_sched_set(unit,
            c5_gport_ucast_scheduler_fq3[idx],
            0,
            C5_SCHED_FQ3_MODE,
            0), "");


    /* FQ scheduler (instance 3) attach to CL scheduler */
    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_attach(unit, c5_gport_ucast_scheduler[idx],
            c5_gport_ucast_scheduler_fq3[idx], 0), "");

    /* create voq connector bundle, 4 elements in bundle */
    BCM_GPORT_LOCAL_SET(config.port, port);
    config.flags = C5_CONN_FLAGS | default_connector_flags;
    config.numq = C5_NUM_COS;
    config.remote_modid = c5_my_modid + mapping_info.core;
    config.nof_remote_cores = 1;
    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_voq_connector_gport_add(unit, &config, &c5_gport_ucast_voq_connector_group0[idx]), "");


    /* handle for the 2nd flow (composite elements) */
    BCM_COSQ_GPORT_COMPOSITE_SF2_CORE_SET(c5_gport_ucast_voq_connector_group0_sf2[idx], c5_gport_ucast_voq_connector_group0[idx], mapping_info.core);


    /* COS 0 (bundle 1st element, 1st Flow), scheduling discipline setup */
    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_sched_set(unit,
            c5_gport_ucast_voq_connector_group0[idx],
            0,
            C5_CONN_MODE,
            0), "");

    /* COS 0 (bundle 1st element, 1st flow), attach to FQ scheduler (instance 0) */
    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_attach(unit, c5_gport_ucast_scheduler_fq0[idx],
            c5_gport_ucast_voq_connector_group0[idx], 0), "");

    /* COS 0 (bundle 1st element, sub-Flow 2), scheduling discipline setup */
    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_sched_set(unit,
            c5_gport_ucast_voq_connector_group0_sf2[idx],
            0,
            C5_CONN_MODE,
            0), "");

    /* COS 0 (bundle 1st element, sub-flow 2), attach to FQ scheduler (instance 2) */
    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_attach(unit, c5_gport_ucast_scheduler_fq2[idx],
            c5_gport_ucast_voq_connector_group0_sf2[idx], 0), "");


    /* COS 1, (bundle 2nd element, 1st flow), scheduling discipline setup */
    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_sched_set(unit,
            c5_gport_ucast_voq_connector_group0[idx],
            1,
            C5_CONN_MODE,
            0), "");

    /* COS 1 (bundle 2nd element, 1st flow), attach to FQ scheduler (instance 1) */
    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_attach(unit, c5_gport_ucast_scheduler_fq1[idx],
            c5_gport_ucast_voq_connector_group0[idx], 1), "");

    /* COS 1 (bundle 2nd element, sub-Flow 2), scheduling discipline setup */
    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_sched_set(unit,
            c5_gport_ucast_voq_connector_group0_sf2[idx],
            1,
            C5_CONN_MODE,
            0), "");

    /* COS 1 (bundle 2nd element, sub-flow 2), attach to FQ scheduler (instance 3) */
    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_attach(unit, c5_gport_ucast_scheduler_fq3[idx],
            c5_gport_ucast_voq_connector_group0_sf2[idx], 1), "");

    /* create queue group bundle, 4 elements in bundle */
    flags = C5_QUEUE_FLAGS | default_voq_flags;
    BCM_IF_ERROR_RETURN_MSG(bcm_port_resource_get(unit, port, &resource), "");
    BCM_IF_ERROR_RETURN_MSG(appl_dnx_e2e_voq_profiles_get(unit, resource.speed, &delay_tolerance_level, &rate_class), "");
    conf.flags = flags;
    conf.port = sys_gport[idx];
    conf.numq = C5_NUM_COS;
    conf.local_core_id = BCM_CORE_ALL;
    for (cosq = 0; cosq < C5_NUM_COS; cosq++) {
        conf.queue_atrributes[cosq].delay_tolerance_level = delay_tolerance_level;
        conf.queue_atrributes[cosq].rate_class = rate_class;
    }
    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_ingress_queue_bundle_gport_add(unit, &conf, &c5_gport_ucast_queue_group0[idx]), "");

    printf("ucast gport(0x%08x)\n", c5_gport_ucast_queue_group0[idx]);

    BCM_GPORT_UNICAST_QUEUE_GROUP_CORE_QUEUE_SET(c5_gport_ucast_queue_group0[idx], mapping_info.core, BCM_GPORT_UNICAST_QUEUE_GROUP_QID_GET(c5_gport_ucast_queue_group0[idx]));
    /* connect VoQ to flow */
    connection.flags = BCM_COSQ_GPORT_CONNECTION_INGRESS;
    connection.remote_modid = c5_my_modid + mapping_info.core;
    connection.voq = c5_gport_ucast_queue_group0[idx];
    connection.voq_connector = c5_gport_ucast_voq_connector_group0[idx];

    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_connection_set(unit, &connection), "");

    /* connect flow to VoQ */
    connection.flags = BCM_COSQ_GPORT_CONNECTION_EGRESS;
    connection.remote_modid = c5_my_modid + mapping_info.core;
    connection.voq = c5_gport_ucast_queue_group0[idx];
    connection.voq_connector = c5_gport_ucast_voq_connector_group0[idx];

    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_connection_set(unit, &connection), "");


    /*
     * Set rate on the E2E Interface
     */
    kbits_sec_max = C5_E2E_INTERFACE_KBITS_SEC_MAX; /* 1Gbps */

    BCM_COSQ_GPORT_E2E_PORT_SET(c5_e2e_gport[idx], port);

    BCM_IF_ERROR_RETURN_MSG(bcm_fabric_port_get(unit,
            c5_e2e_gport[idx],
            0,
            &c5_e2e_parent_gport[idx]), "");

    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_bandwidth_set(unit,
            c5_e2e_parent_gport[idx],
            0,
            0,
            kbits_sec_max,
            0), "");

    /*
     * Set rate on the E2E port
     */
    BCM_COSQ_GPORT_E2E_PORT_SET(c5_e2e_gport[idx], port);

    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_bandwidth_set(unit,
            c5_e2e_gport[idx],
            0,
            0,
            kbits_sec_max_port,
            0), "");

    /* Set rate on the Scheduler */
    /* Scheduler */
    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_bandwidth_set(unit,
            c5_gport_ucast_scheduler[idx],
            0,
            0,
            kbits_sec_max_port,
            0), "");

    max_burst = C5_SCHED_MAX_BURST;

    /* Set max burst on the Scheduler */
    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_control_set(unit,
            c5_gport_ucast_scheduler[idx],
            0,
            bcmCosqControlBandwidthBurstMax,
            max_burst), "");



    /*
     * FQ scheduler (instance 0)
     */
    kbits_sec_max = C5_CIR_KBITS_SEC_MAX;
    max_burst = C5_SCHED_MAX_BURST;
    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_bandwidth_set(unit,
            c5_gport_ucast_scheduler_fq0[idx],
            0,
            0,
            kbits_sec_max,
            0), "");

    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_control_set(unit,
            c5_gport_ucast_scheduler_fq0[idx],
            0,
            bcmCosqControlBandwidthBurstMax,
            max_burst), "");

    /*
     * FQ scheduler (instance 1)
     */
    kbits_sec_max = C5_CIR_KBITS_SEC_MAX;
    max_burst = C5_SCHED_MAX_BURST;
    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_bandwidth_set(unit,
            c5_gport_ucast_scheduler_fq1[idx],
            0,
            0,
            kbits_sec_max,
            0), "");

    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_control_set(unit,
            c5_gport_ucast_scheduler_fq1[idx],
            0,
            bcmCosqControlBandwidthBurstMax,
            max_burst), "");

    /*
     * FQ scheduler (instance 2)
     */
    kbits_sec_max = C5_EIR_KBITS_SEC_MAX;
    max_burst = C5_SCHED_MAX_BURST;
    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_bandwidth_set(unit,
            c5_gport_ucast_scheduler_fq2[idx],
            0,
            0,
            kbits_sec_max,
            0), "");

    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_control_set(unit,
            c5_gport_ucast_scheduler_fq2[idx],
            0,
            bcmCosqControlBandwidthBurstMax,
            max_burst), "");

    /*
     * FQ scheduler (instance 3)
     */
    kbits_sec_max = C5_EIR_KBITS_SEC_MAX;
    max_burst = C5_SCHED_MAX_BURST;
    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_bandwidth_set(unit,
            c5_gport_ucast_scheduler_fq3[idx],
            0,
            0,
            kbits_sec_max,
            0), "");

    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_control_set(unit,
            c5_gport_ucast_scheduler_fq3[idx],
            0,
            bcmCosqControlBandwidthBurstMax,
            max_burst), "");


    /*
     * cos 0/1 = CIR
     */
    kbits_sec_max = C5_CIR_KBITS_SEC_MAX;
    max_burst = C5_SCHED_MAX_BURST;
    for (cosq = 0; cosq < 2; cosq++) {
        /* Set rate on the Connector flow */
        BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_bandwidth_set(unit,
                c5_gport_ucast_voq_connector_group0[idx],
                cosq,
                0,
                kbits_sec_max,
                0), "");

        /* Set maxburst on the Connector flow */
        BCM_IF_ERROR_RETURN_MSG(bcm_cosq_control_set(unit,
                c5_gport_ucast_voq_connector_group0[idx],
                cosq,
                bcmCosqControlBandwidthBurstMax,
                max_burst), "");
    }


    /*
     * cos 0/1 = EIR
     */
    kbits_sec_max = C5_EIR_KBITS_SEC_MAX;
    max_burst = C5_SCHED_MAX_BURST;
    for (cosq = 0; cosq < 2; cosq++) {
        /* Set rate on the Connector flow */
        BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_bandwidth_set(unit,
                c5_gport_ucast_voq_connector_group0_sf2[idx],
                cosq,
                0,
                kbits_sec_max,
                0), "");

        /* Set maxburst on the Connector flow */
        BCM_IF_ERROR_RETURN_MSG(bcm_cosq_control_set(unit,
                c5_gport_ucast_voq_connector_group0_sf2[idx],
                cosq,
                bcmCosqControlBandwidthBurstMax,
                max_burst), "");
    }

    if (c5_use_same_handles == 0) {
        e2e_composite_connectors_display_handles(idx);
    }

    BCM_GPORT_UNICAST_QUEUE_GROUP_CORE_QUEUE_SET(c5_gport_ucast_queue_group0[idx], BCM_CORE_ALL, BCM_GPORT_UNICAST_QUEUE_GROUP_QID_GET(c5_gport_ucast_queue_group0[idx]));

    printf("port(%d) sysport(%d) ucast gport(0x%08x)\n", port, system_port, c5_gport_ucast_queue_group0[idx]);
    printf("cint_dnx_e2e_composite_connectors.c completed with status (%s)\n", bcm_errmsg(rv));
    return BCM_E_NONE;
}

int e2e_composite_connectors_teardown(int unit,int port_idx)
{
    int                           idx = port_idx;
    bcm_gport_t                   gport_scheduler_fq;
    bcm_gport_t                   gport_sched_fq_cir, gport_sched_fq_pir;
    bcm_gport_t                   gport_ucast_voq_conn_cir, gport_ucast_voq_conn_pir;
    int                           nbr_fq_sched;
    bcm_cosq_gport_connection_t   connection;
    int                           cosq = 0;
    char                          error_msg[200]={0,};


    printf("\nTeardown\n");

    e2e_composite_connectors_display_handles(idx);

    /* detach scheduler sub-tree from E2E hierarchy */
    snprintf(error_msg, sizeof(error_msg), "detach for SE(0x%x) failed", c5_gport_ucast_scheduler[idx]);
    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_detach(unit, c5_e2e_gport[idx], c5_gport_ucast_scheduler[idx], 0), error_msg);
    printf("  detached schedGport(0x%x)\n", c5_gport_ucast_scheduler[idx]);


    /* dis-associate queue from connectors */
    connection.flags = BCM_COSQ_GPORT_CONNECTION_INGRESS | BCM_COSQ_GPORT_CONNECTION_INVALID;
    connection.remote_modid = c5_my_modid + mapping_info.core;
    connection.voq = c5_gport_ucast_queue_group0[idx];
    connection.voq_connector = c5_gport_ucast_voq_connector_group0[idx];

    snprintf(error_msg, sizeof(error_msg), "resetting queue2connector association failed, queue(0x%x)", c5_gport_ucast_queue_group0[idx]);
    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_connection_set(unit, &connection), error_msg);
    printf("  disconnected (Ingress) ucastGport(0x%x) from connGport(0x%x)\n", c5_gport_ucast_queue_group0[idx], c5_gport_ucast_voq_connector_group0[idx]);


    /* dis-associate connectors from queues */
    connection.flags = BCM_COSQ_GPORT_CONNECTION_EGRESS | BCM_COSQ_GPORT_CONNECTION_INVALID;
    connection.remote_modid = c5_my_modid + mapping_info.core;
    connection.voq = c5_gport_ucast_queue_group0[idx];
    connection.voq_connector = c5_gport_ucast_voq_connector_group0[idx];

    snprintf(error_msg, sizeof(error_msg), "resetting connector2queue association failed, Connector(0x%x)", c5_gport_ucast_voq_connector_group0[idx]);
    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_connection_set(unit, &connection), error_msg);
    printf("  disconnected (Engress) connGport(0x%x) from ucastGport(0x%x)\n", c5_gport_ucast_voq_connector_group0[idx], c5_gport_ucast_queue_group0[idx]);


    /* delete queues */
    snprintf(error_msg, sizeof(error_msg), "delete for QueueGroup(0x%x) failed", c5_gport_ucast_queue_group0[idx]);
    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_delete(unit, c5_gport_ucast_queue_group0[idx]), error_msg);
    printf("  deleted ucastGport(0x%x)\n", c5_gport_ucast_queue_group0[idx]);


    /* detach connectors */
    for (cosq = 0; cosq < 2; cosq++) {
        switch (cosq) {
        case 0:
            gport_sched_fq_cir = c5_gport_ucast_scheduler_fq0[idx];
            gport_sched_fq_pir = c5_gport_ucast_scheduler_fq2[idx];
            gport_ucast_voq_conn_cir = c5_gport_ucast_voq_connector_group0[idx];
            gport_ucast_voq_conn_pir = c5_gport_ucast_voq_connector_group0_sf2[idx];
            break;
        default:
            gport_sched_fq_cir = c5_gport_ucast_scheduler_fq1[idx];
            gport_sched_fq_pir = c5_gport_ucast_scheduler_fq3[idx];
            gport_ucast_voq_conn_cir = c5_gport_ucast_voq_connector_group0[idx];
            gport_ucast_voq_conn_pir = c5_gport_ucast_voq_connector_group0_sf2[idx];
            break;
        }

        snprintf(error_msg, sizeof(error_msg), "detach for Connector:cosq(0x%x:%d) from Sched(0x%x) failed", gport_ucast_voq_conn_cir, cosq, gport_sched_fq_cir);
        BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_detach(unit, gport_sched_fq_cir, gport_ucast_voq_conn_cir, cosq), error_msg);
        printf("  detached connGport:cosq(0x%x:%d) from schedGport(0x%x)\n", gport_ucast_voq_conn_cir, cosq, gport_sched_fq_cir);

        snprintf(error_msg, sizeof(error_msg), "detach for Connector:cosq(0x%x:%d) from Sched(0x%x) failed", gport_ucast_voq_conn_pir, cosq, gport_sched_fq_pir);
        BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_detach(unit, gport_sched_fq_pir, gport_ucast_voq_conn_pir, cosq), error_msg);
        printf("  detached connGport:cosq(0x%x:%d) from schedGport(0x%x)\n", gport_ucast_voq_conn_pir, cosq, gport_sched_fq_pir);
    }


    /* delete connectors */
    snprintf(error_msg, sizeof(error_msg), "delete for ConnectorGroup(0x%x) failed", c5_gport_ucast_voq_connector_group0[idx]);
    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_delete(unit, c5_gport_ucast_voq_connector_group0[idx]), error_msg);
    printf("  delete connGport(0x%x)\n", c5_gport_ucast_voq_connector_group0[idx]);


    /* detach intermediate Scheduler elements (SE) */
    for (nbr_fq_sched = 0; nbr_fq_sched < C5_NBR_FQ_SCHEDULERS; nbr_fq_sched++) {
        switch (nbr_fq_sched) {
        case 0: gport_scheduler_fq = c5_gport_ucast_scheduler_fq0[idx]; break;
        case 1: gport_scheduler_fq = c5_gport_ucast_scheduler_fq1[idx]; break;
        case 2: gport_scheduler_fq = c5_gport_ucast_scheduler_fq2[idx]; break;
        default: gport_scheduler_fq = c5_gport_ucast_scheduler_fq3[idx]; break;
        }

        snprintf(error_msg, sizeof(error_msg), "detach for SE(0x%x) failed", gport_scheduler_fq);
        BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_detach(unit, c5_gport_ucast_scheduler[idx], gport_scheduler_fq, 0), error_msg);
        printf("  detached schedGport(0x%x)\n", gport_scheduler_fq);
    }


    /* delete intermediate Scheduler elements (SE) */
    for (nbr_fq_sched = 0; nbr_fq_sched < C5_NBR_FQ_SCHEDULERS; nbr_fq_sched++) {
        switch (nbr_fq_sched) {
        case 0: gport_scheduler_fq = c5_gport_ucast_scheduler_fq0[idx]; break;
        case 1: gport_scheduler_fq = c5_gport_ucast_scheduler_fq1[idx]; break;
        case 2: gport_scheduler_fq = c5_gport_ucast_scheduler_fq2[idx]; break;
        default: gport_scheduler_fq = c5_gport_ucast_scheduler_fq3[idx]; break;
        }

        snprintf(error_msg, sizeof(error_msg), "delete for SE(0x%x) failed", gport_scheduler_fq);
        BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_delete(unit, gport_scheduler_fq), error_msg);
        printf("  delete schedGport(0x%x)\n", gport_scheduler_fq);
    }


    /* delete scheduler  element at top of sub-tree */
    snprintf(error_msg, sizeof(error_msg), "delete for SE(0x%x) failed", c5_gport_ucast_scheduler[idx]);
    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_delete(unit, c5_gport_ucast_scheduler[idx]), error_msg);
    printf("  delete schedGport(0x%x)\n", c5_gport_ucast_scheduler[idx]);

    printf("cint_dnx_e2e_composite_connectors.c (teardown) completed with status (%s)\n", bcm_errmsg(rc));

    c5_use_same_handles = 1;

    return BCM_E_NONE;
}

int
e2e_scheduling_elements_verify_type(int unit, bcm_gport_t gport, int exp_type)
{
    bcm_cosq_scheduler_gport_params_t params_get;
    char error_msg[200]={0,};

    snprintf(error_msg, sizeof(error_msg), "failed on e2e Sched (0x%x)", gport);
    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_scheduler_gport_get(unit, 0, gport, &params_get), error_msg);
    if (params_get.type != exp_type) {
        printf("gport get mismatch on gport (0x%x) expected type(%d) retreived type (%d)\n", gport, exp_type, params_get.type);
    }

    return BCM_E_NONE;
}

int
e2e_composite_connectors_verify_flags(int unit, bcm_gport_t gport, int exp_flags)
{
    bcm_cosq_voq_connector_gport_t config_get;
    char error_msg[200]={0,};

    /* retreive type of scheduling element */
    snprintf(error_msg, sizeof(error_msg), "failed on Sched (0x%x)", gport);
    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_voq_connector_gport_get(unit, gport, &config_get), error_msg);
    if (config_get.flags != exp_flags) {
        printf("gport get mismatch on gport (0x%x) expected flags(0x%x) retreived flags (0x%x)\n", gport, exp_flags, config_get.flags);
    }

    return BCM_E_NONE;
}

int
e2e_composite_connectors_verify_mode(int unit, bcm_gport_t gport, int cosq, int exp_mode, int exp_weight)
{
    int mode, weight;
    char error_msg[200]={0,};


    snprintf(error_msg, sizeof(error_msg), "failed on gport (0x%x)", gport);
    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_sched_get(unit, gport, cosq, &mode, &weight), error_msg);
    if (mode != exp_mode) {
        printf("sched mode mismatch on gport (0x%x) expected(BCM_COSQ_SP%d) retreived (BCM_COSQ_SP%d)\n", gport, (exp_mode - BCM_COSQ_SP0), (mode - BCM_COSQ_SP0));
    }
    if (weight != exp_weight) {
        printf("sched weight mismatch on gport (0x%x) expected(%d) retreived (%d)\n", gport, 0, weight);
    }

    return BCM_E_NONE;
}

int
e2e_composite_connectors_verify_bandwidth(int unit, bcm_gport_t gport, int cosq, int exp_rate, int margin)
{
    uint32 kbits_sec_max, kbits_sec_min, flags;
    char error_msg[200]={0,};

    snprintf(error_msg, sizeof(error_msg), "failed on gport (0x%x)", gport);
    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_bandwidth_get(unit, gport, cosq, &kbits_sec_min, &kbits_sec_max, &flags), error_msg);
    if ( (kbits_sec_max < (exp_rate - margin)) ||
            (kbits_sec_max > (exp_rate + margin)) ) {
        printf("bandwidth_get mismatch on gport (0x%x) expected(%d) retreived (%d)\n", gport, exp_rate, kbits_sec_max);
    }

    return BCM_E_NONE;
}

int
e2e_composite_connectors_verify_burst_size(int unit, bcm_gport_t gport, int cosq, int exp_burst_size, int margin)
{
    int max_burst;
    char error_msg[200]={0,};


    snprintf(error_msg, sizeof(error_msg), "failed on gport (0x%x)", gport);
    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_control_get(unit, gport, cosq, bcmCosqControlBandwidthBurstMax, &max_burst), error_msg);
    if ( (max_burst < (exp_burst_size - margin)) || (max_burst > (exp_burst_size + margin)) ) {
        printf("control_get-BandwidthBurstMax mismatch on Sched (0x%x) expected(%d) retreived (%d)\n", gport, exp_burst_size, max_burst);
    }

    return BCM_E_NONE;
}

/* verify setup */
int e2e_composite_connectors_verify(int unit, int kbits_sec_max_port, int port_idx)
{
    int                           idx = port_idx;
    bcm_port_t                    port = port_idx + 1;
    bcm_gport_t                   physical_port;
    int                           num_cos_levels;
    uint32                        flags;
    bcm_gport_t                   gport_scheduler_fq;
    bcm_gport_t                   gport_ucast_voq_conn;
    int                           nbr_fq_sched, nbr_flows;
    bcm_cosq_gport_connection_t   connection;
    int                           cosq = 0;
    int                           exp_flags, exp_mode, exp_margin, exp_kbits_sec_max;
    uint32 dummy_flags ;
    bcm_port_interface_info_t interface_info;
    bcm_port_mapping_info_t mapping_info;
    bcm_cosq_scheduler_gport_params_t params_get;
    bcm_cosq_gport_info_t gport_info;
    char error_msg[200]={0,};

    printf("\nVerify Setup\n");

    rc = bcm_port_get(unit, port, &dummy_flags, &interface_info, &mapping_info);
    if (rc != BCM_E_NONE) {
        printf("bcm_port_get scheduler failed $rc\n");
        return rc;
    }

    exp_margin = C5_E2E_INTERFACE_KBITS_SEC_MAX_MARGIN;
    BCM_IF_ERROR_RETURN_MSG(e2e_composite_connectors_verify_bandwidth(unit, c5_e2e_parent_gport[idx], 0, C5_E2E_INTERFACE_KBITS_SEC_MAX, exp_margin), "");
    exp_margin = kbits_sec_max_port /100; /* 1% error */
    BCM_IF_ERROR_RETURN_MSG(e2e_composite_connectors_verify_bandwidth(unit, c5_e2e_gport[idx], 0, kbits_sec_max_port, exp_margin), "");
    /* retrive e2e port scheduling element */
    gport_info.in_gport = c5_e2e_gport[idx];
    gport_info.cosq = 0;

    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_handle_get(unit, bcmCosqGportTypeSched, &gport_info), "");
    c5_e2e_gport[idx] = gport_info.out_gport;
    snprintf(error_msg, sizeof(error_msg), "failed on e2e Sched (0x%x)", c5_e2e_gport[idx]);
    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_scheduler_gport_get(unit, 0, c5_e2e_gport[idx], &params_get), error_msg);
    if (params_get.type != C5_DEFAULT_E2E_SCHED_TYPE) {
        printf("gport get mismatch on E2E Sched (0x%x) expected type(%d) retreived type (%d)\n", c5_e2e_gport[idx], C5_DEFAULT_E2E_SCHED_TYPE, params_get.type);
    }

    /* retreive type of scheduling element */
    BCM_IF_ERROR_RETURN_MSG(e2e_scheduling_elements_verify_type(unit, c5_gport_ucast_scheduler[idx], C5_SCHED_CL_TYPE), "");

    /* retreive SE scheduling discipline */
    BCM_IF_ERROR_RETURN_MSG(e2e_composite_connectors_verify_mode(unit, c5_gport_ucast_scheduler[idx], 0, C5_SCHEDULER_MODE, 0), "");

    /* retreive rate of Scheduler */
    BCM_IF_ERROR_RETURN_MSG(e2e_composite_connectors_verify_bandwidth(unit, c5_gport_ucast_scheduler[idx], 0, C5_SCHED_KBITS_SEC_MAX, C5_SCHED_KBITS_SEC_MAX_MARGIN), "");

    /* retreive scheduler burst size */
    BCM_IF_ERROR_RETURN_MSG(e2e_composite_connectors_verify_burst_size(unit, c5_gport_ucast_scheduler[idx], 0, C5_SCHED_MAX_BURST, C5_SCHED_MAX_BURST_MARGIN), "");

    /* retreive intermediate Scheduler elements (SE) */
    for (nbr_fq_sched = 0; nbr_fq_sched < C5_NBR_FQ_SCHEDULERS; nbr_fq_sched++) {
        switch (nbr_fq_sched) {
        case 0: gport_scheduler_fq = c5_gport_ucast_scheduler_fq0[idx];
        exp_mode = C5_SCHED_FQ0_MODE;
        exp_kbits_sec_max = C5_CIR_KBITS_SEC_MAX;
        exp_margin = C5_CIR_KBITS_SEC_MAX_MARGIN; break;
        case 1: gport_scheduler_fq = c5_gport_ucast_scheduler_fq1[idx];
        exp_mode = C5_SCHED_FQ1_MODE;
        exp_kbits_sec_max = C5_CIR_KBITS_SEC_MAX;
        exp_margin = C5_CIR_KBITS_SEC_MAX_MARGIN; break;
        case 2: gport_scheduler_fq = c5_gport_ucast_scheduler_fq2[idx];
        exp_mode = C5_SCHED_FQ2_MODE;
        exp_kbits_sec_max = C5_EIR_KBITS_SEC_MAX;
        exp_margin = C5_EIR_KBITS_SEC_MAX_MARGIN; break;
        default: gport_scheduler_fq = c5_gport_ucast_scheduler_fq3[idx];
        exp_mode = C5_SCHED_FQ3_MODE;
        exp_kbits_sec_max = C5_EIR_KBITS_SEC_MAX;
        exp_margin = C5_EIR_KBITS_SEC_MAX_MARGIN; break;
        }

        /* retreive type of scheduling element */
        BCM_IF_ERROR_RETURN_MSG(e2e_scheduling_elements_verify_type(unit, gport_scheduler_fq, C5_SCHED_FQ_TYPE), "");

        /* retreive SE scheduling discipline */
        BCM_IF_ERROR_RETURN_MSG(e2e_composite_connectors_verify_mode(unit, gport_scheduler_fq, 0, exp_mode, 0), "");

        /* retreive rate of Scheduler */
        BCM_IF_ERROR_RETURN_MSG(e2e_composite_connectors_verify_bandwidth(unit, gport_scheduler_fq, 0, exp_kbits_sec_max, exp_margin), "");

        /* retreive scheduler burst size */
        BCM_IF_ERROR_RETURN_MSG(e2e_composite_connectors_verify_burst_size(unit, gport_scheduler_fq, 0, C5_SCHED_MAX_BURST, C5_SCHED_MAX_BURST_MARGIN), "");
    }

    /* retreive type of connector element */
    BCM_IF_ERROR_RETURN_MSG(e2e_composite_connectors_verify_flags(unit, c5_gport_ucast_voq_connector_group0[idx], C5_CONN_FLAGS), "");

    /* retreive connector attributes*/
    for (cosq = 0; cosq < 2; cosq++) {
        for (nbr_flows = 0; nbr_flows < 2; nbr_flows++) {
            switch (nbr_flows) {
            case 0:
                gport_ucast_voq_conn = c5_gport_ucast_voq_connector_group0[idx];
                exp_kbits_sec_max = C5_CIR_KBITS_SEC_MAX;
                exp_margin = C5_CIR_KBITS_SEC_MAX_MARGIN;
                break;
            default:
                gport_ucast_voq_conn = c5_gport_ucast_voq_connector_group0_sf2[idx];
                exp_kbits_sec_max = C5_EIR_KBITS_SEC_MAX;
                exp_margin = C5_EIR_KBITS_SEC_MAX_MARGIN;
                break;
            }

            /* retreive SE scheduling discipline */
            BCM_IF_ERROR_RETURN_MSG(e2e_composite_connectors_verify_mode(unit, gport_ucast_voq_conn, cosq, C5_CONN_MODE, 0), "");

            /* retreive rate of Scheduler */
            BCM_IF_ERROR_RETURN_MSG(e2e_composite_connectors_verify_bandwidth(unit, gport_ucast_voq_conn, cosq, exp_kbits_sec_max, exp_margin), "");

            /* retreive scheduler burst size */
            BCM_IF_ERROR_RETURN_MSG(e2e_composite_connectors_verify_burst_size(unit, gport_ucast_voq_conn, cosq, C5_SCHED_MAX_BURST, C5_SCHED_MAX_BURST_MARGIN), "");
        }
    }

    snprintf(error_msg, sizeof(error_msg), "failed on ucast queue group(0x%x)", gport_ucast_queue_group);
    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_get(unit, c5_gport_ucast_queue_group0[idx],
            &physical_port, &num_cos_levels, &flags), error_msg);

    if (flags != C5_QUEUE_FLAGS) {
        printf("gport get mismatch on ucast queue (0x%x) failed expected flags(0x%x) retrieved flags(0x%x)\n",
                gport_ucast_queue_group, C5_QUEUE_FLAGS, flags);
    }

    if (num_cos_levels != C5_NUM_COS) {
        printf("gport get mismatch on ucast queue (0x%x) expected numCos(%d) retreived numCos(%d)\n",
                gport_ucast_queue_group, C5_NUM_COS, num_cos_levels);
    }

    /* retreive egress connection set information */
    connection.flags = BCM_COSQ_GPORT_CONNECTION_EGRESS;
    connection.voq_connector = c5_gport_ucast_voq_connector_group0[idx];
    rc = bcm_cosq_gport_connection_get(unit, &connection);
    if (rc != BCM_E_NONE) {
        printf("bcm_cosq_gport_connection_get on Egress, Connector (0x%x) failed, error (%d)\n", c5_gport_ucast_voq_connector_group0[idx], rc);
        return(rc);
    }
    if (connection.voq != c5_gport_ucast_queue_group0[idx]) {
        printf("gport_connection_get on Egress, Connector (0x%x) VoQ association mismatch, Expected (0x%x), retreived (0x%x)\n", c5_gport_ucast_voq_connector_group0[idx], c5_gport_ucast_queue_group0[idx], connection.voq);
    }

    /* retreive ingress connection set information */
    connection.flags = BCM_COSQ_GPORT_CONNECTION_INGRESS;
    connection.voq = c5_gport_ucast_queue_group0[idx];
    connection.remote_modid = c5_my_modid + mapping_info.core;
    BCM_GPORT_UNICAST_QUEUE_GROUP_CORE_QUEUE_SET(c5_gport_ucast_queue_group0[idx], 1, BCM_GPORT_UNICAST_QUEUE_GROUP_QID_GET(c5_gport_ucast_queue_group0[idx]));
    snprintf(error_msg, sizeof(error_msg), "failed on Ingress, VoQ (0x%x)", c5_gport_ucast_queue_group0[idx]);
    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_connection_get(unit, &connection), error_msg);
    if (connection.voq_connector != c5_gport_ucast_voq_connector_group0[idx]) {
        printf("gport_connection_get on Ingress, VoQ (0x%x) connector association mismatch, Expected (0x%x), retreived (0x%x)\n", c5_gport_ucast_queue_group0[idx], c5_gport_ucast_voq_connector_group0[idx], connection.voq_connector);
    }

    printf("cint_dnx_e2e_composite_connectors.c (verify) completed with status (%s)\n", bcm_errmsg(rc));

    return BCM_E_NONE;
}

