/*  Feature  : TCB - egress admission control
 *  
 *  Usage    : BCM.0> cint tcb_egr.c
 *  
 *  config   : tcb_config.bcm
 *  
 *  Log file : tcb_egr_log.txt
 *  
 *  Test Topology :
 * +-----------------+            +---------+
 * |                 |            |         |
 * |                 |            |         |
 * |             XE0 <------------+         |
 * |                 |            |         |
 * |                 |            |Traffic  |
 * |     SVK     XE1 <------------+Generator|
 * |                 |            |         |
 * |                 |            |         |
 * |                 |            |         |
 * |             XE2 +------------>         |
 * |                 |            |         |
 * |                 |            |         |
 * |                 |            |         |
 * +-----------------+            +---------+
 * 
 *  Summary:
 *  ========
 * This CINT script demonstrates how to configure chip TCB to detect ingress 
 * admission control drop. 
 * 
 *  Detailed steps done in the CINT script:
 *  =====================================================
 * 1) Step1 - Test Setup
 * ============================================
 * a) Connect xe0-xe2 with traffic generator.
 * b) Make sure xe0-xe2 link up with traffic generator.
 * 
 * 2) Step2 - Configuration
 * ============================================
 * ./bcm.user
 * config add mmu_lossless=0
 * rc
 * port xe0-xe2 rxpau=off txpau=off
 * l2 add pbm=xe2 mac=0x0042434DFFFF vlanid=1 rp=false
 * c tcb_egr.c
 * 
 * 3) Step3 - Verification
 * ==========================================
 * a) Send wirespeed traffic into xe0 and xe1.
 *  0042434DFFFF0042434D007A81000001
 *  0B040000000000000000000000000000
 *  00000000000000000000000000000000
 *  00000000000000000000000000000000
 * Expected Result:
 * ===================
 * TCB and event buffer data is printed.
 * 
 */


/* Structure for tcb configuration and its threshold profile */
cint_reset();

struct tcb_config_t
{
    bcm_gport_t gport;               /* monitor entity - Unicast queue/Physical port */
    bcm_cosq_dir_t direction;        /* cosq direction - Ingress/Egress */
    bcm_cosq_tcb_scope_t scope_type; /* monitor scope type - Unicast queue/Ingress port/Egress port*/
    uint32 trigger_reason;           /* trigger event - Ingress admin drop/Egress admin drop/WRED/CFAP */
    uint32 start_threshold;          /* tcb start threshold in bytes */
    uint32 stop_threshold;           /* tcb stop threshold in bytes */
};

/* Callback function for TCB events */
void
bcm_cosq_tcb_callback(int unit, bcm_cosq_buffer_id_t buffer_id, void *user_data)
{
    const int array_max = 1024;
    int *event_count = user_data;
    bcm_cosq_tcb_buffer_t buffer_array[array_max];
    bcm_cosq_tcb_event_t event_array[array_max];
    int array_count;
    int overflow_count;
    int i;
    bcm_error_t rv;
    (*event_count)++;

    rv = bcm_cosq_tcb_control_set(unit, -1, bcmCosqTcbControlFreeze, TRUE);
    if(BCM_FAILURE(rv)) {
        printf("\nError in bcm_cosq_tcb_control_set: %s.\n",bcm_errmsg(rv));
        return rv;
    }

    /* Print "interesting" information from the buffer and event arrays. */
    rv = bcm_cosq_tcb_buffer_multi_get(unit, buffer_id, array_max, buffer_array,
                                       &array_count);
    if(BCM_FAILURE(rv)) {
        printf("\nError in bcm_cosq_tcb_buffer_multi_get: %s.\n",
               bcm_errmsg(rv));
        return rv;
    }

    printf("\nTCB buffer info\n");
    printf("Ing gport 0x%x\n",buffer_array.ingress_gport);
    printf("Egr gport 0x%x\n",buffer_array.egress_gport);
    printf("queue 0x%x\n",buffer_array.queue);
    printf("queue size 0x%x\n",buffer_array.queue_size);
    printf("Packet data\n");
    for(i=0; i<BCM_COSQ_TCB_MAX_BUF_SIZE; i++)
    printf("%x",buffer_array.buf_data[i]);
    printf("\n\n");

    rv = bcm_cosq_tcb_event_multi_get(unit, buffer_id, array_max, event_array,
                                      &array_count, &overflow_count);
    if(BCM_FAILURE(rv)) {
        printf("\nError in bcm_cosq_tcb_event_multi_get: %s.\n",bcm_errmsg(rv));
        return rv;
    }

    printf("Event buffer info\n");
    printf("TCB event %d on buffer %d\n", *event_count, buffer_id);
    printf("Ing gport 0x%x\n",event_array.ingress_gport);
    printf("Egr gport 0x%x\n",event_array.egress_gport);
    printf("Drop reason %d\n",event_array.drop_reason);
    printf("queue 0x%x\n",event_array.queue);
    printf("queue size 0x%x\n",event_array.queue_size);

}

/* Helper routine for configuring tcb for Egress Admission Drop */
int
configure_egress_trigger(int unit, int buffer_id, int profile_index,
                         tcb_config_t *tcb)
{
    bcm_cosq_tcb_config_t config;
    bcm_cosq_tcb_threshold_profile_t threshold;
    bcm_cosq_object_id_t object_id;
    bcm_error_t rv;
    int flags = 0;
    bcm_cos_queue_t cosq = 0;

    rv = bcm_cosq_tcb_config_get(unit, buffer_id, &config);
    if(BCM_FAILURE(rv)) {
        printf("\nError in bcm_cosq_tcb_config_get: %s.\n",bcm_errmsg(rv));
        return rv;
    }

    config.scope_type = tcb->scope_type;
    config.gport = tcb->gport;
    config.trigger_reason = tcb->trigger_reason;

    /* Setting the config attributes of TCB instance */
    rv = bcm_cosq_tcb_config_set(unit, buffer_id, &config);
    if(BCM_FAILURE(rv)) {
        printf("\nError in bcm_cosq_tcb_config_set: %s.\n",bcm_errmsg(rv));
        return rv;
    }

    bcm_cosq_tcb_threshold_profile_t_init(&threshold);
    threshold.start_threshold_bytes = tcb->start_threshold;
    threshold.stop_threshold_bytes = tcb->stop_threshold;
    /* Create threshold profile for TCB instance */
    rv = bcm_cosq_tcb_threshold_profile_create(unit, flags, buffer_id,
                                               &threshold, profile_index);
    if(BCM_FAILURE(rv)) {
        printf("\nError in bcm_cosq_tcb_threshols_profile_create: %s.\n",
               bcm_errmsg(rv));
        return rv;
    }

    bcm_cosq_object_id_t_init(&object_id);
    object_id.port = tcb->gport;
    object_id.cosq = cosq;
    object_id.buffer = buffer_id;
    /* Associating the threshold profile with the port or UCQ */
    rv = bcm_cosq_tcb_gport_threshold_mapping_set(unit, &object_id,
                                                  profile_index);
    if(BCM_FAILURE(rv)) {
        printf("\nError in bcm_cosq_tcb_gport_threshold_mapping_set: %s.\n",
               bcm_errmsg(rv));
        return rv;
    }

    /* Enabling the specific TCB instance */
    rv = bcm_cosq_tcb_control_set(unit, buffer_id, bcmCosqTcbControlEnable,
                                  TRUE);
    if(BCM_FAILURE(rv)) {
        printf("\nError in bcm_cosq_tcb_control_set: %s.\n",bcm_errmsg(rv));
        return rv;
    }

    return BCM_E_NONE;
}

/* Steps to configure tcb for Egress Admisssion Drop and Egress Port as scope */
int
scope_egress(int unit, tcb_config_t *tcb_cfg)
{
    int event_count = 0;
    const int   max_buf_ids = 4;        /* There's always two TCB engines per port */
    const void *user_data = & event_count;
    bcm_cosq_buffer_id_t buf_id[max_buf_ids];
    int         array_count;
    int         idx;
    int         profile_index[max_buf_ids];
    bcm_error_t rv;

    /*
     * To get buffer ids associated with specified port
     * "cos" parameter is reserved and should be 0
     */
    rv = bcm_cosq_buffer_id_multi_get(unit, tcb_cfg->gport, 0,
                                      tcb_cfg->direction, max_buf_ids, buf_id,
                                      &array_count);
    if(BCM_FAILURE(rv)) {
        printf("\nError in bcm_cosq_tcb_buffer_multi_get: %s.\n",
               bcm_errmsg(rv));
        return rv;
    }

    /* To register callback to handle freeze events */
    rv = bcm_cosq_tcb_cb_register(unit, bcm_cosq_tcb_callback, user_data);
    if(BCM_FAILURE(rv)) {
        printf("\nError in bcm_cosq_tcb_cb_register: %s.\n",bcm_errmsg(rv));
        return rv;
    }

    /* Configuring TCB for the associated XPEs [buffer id] */
    for (idx = 0; idx < array_count; idx++) {
        rv = configure_egress_trigger(unit, buf_id[idx], profile_index[idx],
                                      tcb_cfg);
        if(BCM_FAILURE(rv)) {
            printf("\nError in configure_egress_trigger: %s.\n",bcm_errmsg(rv));
            return rv;
        }
    }

    return BCM_E_NONE;
}

int tcb_egress(bcm_gport_t gport)
{
    bcm_error_t rv;

    tcb_config_t tcb_config;
    tcb_config.gport = gport;               /* monitor entity - Unicast queue/Physical port */
    tcb_config.direction = bcmCosqEgress;        /* cosq direction - Ingress/Egress */
    tcb_config.scope_type = bcmCosqTcbScopeEgressPort; /* monitor scope type - Unicast queue/Ingress port/Egress port*/
    tcb_config.trigger_reason = BCM_COSQ_TCB_EGRESS_ADMIN_DROP;           /* trigger event - Ingress admin drop/Egress admin drop/WRED/CFAP */
    tcb_config.start_threshold = 2500;          /* tcb start threshold in bytes */
    tcb_config.stop_threshold = 1500;           /* tcb stop threshold in bytes */

   /* TCB configuration */
   rv = scope_egress(unit, &tcb_config);
   if (BCM_FAILURE(rv)) {
        printf("SCOPE EGRESS TEST FAILED: %s\n", bcm_errmsg(rv));
        return rv;
   }

   return BCM_E_NONE;
}

int unit = 0;
bcm_port_t port = 3;

bcm_error_t execute()
{
    int rrv;
    
    bcm_gport_t gport;
    BCM_GPORT_LOCAL_SET(gport, port);
    if( (rrv = tcb_egress(gport)) != BCM_E_NONE )
    {
        printf("Fail to configure TCB %d\n", rrv);
        return rrv;
    }
    
    return BCM_E_NONE;
}

const char *auto_execute = (ARGC == 1) ? ARGV[0] : "YES";
if (!sal_strcmp(auto_execute, "YES")) {
  print execute();
}

