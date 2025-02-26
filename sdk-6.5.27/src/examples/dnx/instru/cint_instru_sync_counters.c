/*
 * File: cint_instru_sync_counters.c
 * Purpose: Example of collecting synchronized counters
 *
 * Configure and then collect iCGM synchronize counters.
 *
 * The cint includes:
 * - Configure functions for configuring the synchronized counters.
 * - Collect funtion for colecting the results.
 *
 * Usage:
 * ------
 *
 * Test Scenario:
 *--------------
 * Test Scenario - start
  cint
  uint64 packets_enqueue_last;
  uint64 bytes_enqueue_last;
  int nof_records;
  cint_instru_sync_counters_configure(0,FALSE,1000000);
 * wait...
  cint_instru_sync_counters_collect(0,0,&packets_ingress,&bytes_enqueue,&nof_records);
  exit;
 *
 * Note, to clear configuration:
  cint
  cint_instru_sync_counters_clear(0);
  exit;
 * Test Scenario - end
 */

/* Variables for saving information.*/
uint32 cint_instru_synch_enqueue_packets_min = 0;
uint32 cint_instru_synch_enqueue_packets_max = 0;

int
cint_instru_sync_counters_configure(
   int unit,
   int is_continuous,
   int period_ms)
{
    bcm_instru_synced_counters_config_t config;

    bcm_instru_synced_counters_config_t_init(&config);
    /* 
     * Convert the period from milliseconds to nanoseconds.
     */
    COMPILER_64_SET(config.period, 0, period_ms);
    COMPILER_64_UMUL_32(config.period, 1000000);

    /*
     * Set the start time to begin immediately.
     */
    COMPILER_64_SET(config.start_time,-1,-1);

    config.is_eventor_collection = FALSE;
    config.is_continuous = is_continuous;
    config.enable = TRUE;
    BCM_IF_ERROR_RETURN_MSG(bcm_instru_synced_counters_config_set(unit,0,bcmInstruSyncedCountersTypeIcgm,&config), "");

    return BCM_E_NONE;
}

int
cint_instru_sync_counters_collect(
   int unit,
   bcm_core_t core_id)
{
    bcm_instru_synced_counters_records_key_t key;
    bcm_instru_synced_counters_data_t data;
    int found_packets_enqueue = FALSE;
    int packets_enqueue_index;
    int found_bytes_enqueue = FALSE;
    int bytes_enqueue_index;
    int found_min_free_ocb_buffers = FALSE;
    int min_free_ocb_buffers_index;
    int counters_index;
    int record_index;

    bcm_instru_synced_counters_records_key_t_init(&key);
    bcm_instru_synced_counters_data_t_init(&data);

    /* Initialize the min and max variable.*/
    cint_instru_synch_enqueue_packets_min = 0;
    cint_instru_synch_enqueue_packets_max = 0;

    /* Core_id must be a specific core, cannot be all cores.*/
    key.core_id = core_id;
    key.source_type=bcmInstruSyncedCountersTypeIcgm;
  
    BCM_IF_ERROR_RETURN_MSG(bcm_instru_synced_counters_records_get(unit,0,&key,&data), "");

    /* Print the counters*/
    for (record_index = 0; record_index < data.nof_records; record_index++)
    {
        printf("record %d time(0x%x,0x%x):",record_index,
               COMPILER_64_HI(data.record_arr[record_index].estimated_time_of_day),
               COMPILER_64_LO(data.record_arr[record_index].estimated_time_of_day));
        for (counters_index = 0; counters_index < data.nof_counters; counters_index++)
        {
            printf(" counter %d.%d value (0x%x,0x%x)", counters_index,
                   data.record_arr_counters_type[counters_index].counter_type,
                   data.record_arr_counters_type[counters_index].counter_index,
                   COMPILER_64_HI(data.record_arr[record_index].value_arr[counters_index]),
                   COMPILER_64_LO(data.record_arr[record_index].value_arr[counters_index]));
        }
        printf("\n");
    }

    /* Find packets_enqueue and bytes_enqueue*/
    if (data.nof_records > 0)
    {
        for (counters_index = 0; counters_index < data.nof_counters; counters_index++)
        {
            if (data.record_arr_counters_type[counters_index].counter_type == bcmInstruSyncedCountersIcgmTypeEnqueuePackets)
            {
                found_packets_enqueue = TRUE;
                packets_enqueue_index = counters_index;
            }
            if (data.record_arr_counters_type[counters_index].counter_type == bcmInstruSyncedCountersIcgmTypeEnqueueBytes)
            {
                found_bytes_enqueue = TRUE;
                bytes_enqueue_index = counters_index;
            }
            if (data.record_arr_counters_type[counters_index].counter_type == bcmInstruSyncedCountersIcgmTypeMinFreeOcbBuffers)
            {
                found_min_free_ocb_buffers = TRUE;
                min_free_ocb_buffers_index = counters_index;
            }
        }
        if (!(found_packets_enqueue && found_bytes_enqueue && found_min_free_ocb_buffers))
        {
            printf("bcm_instru_synced_counters_records_get did not return the required counters.\n");
            return BCM_E_FAIL;
        }
    }

    printf("%d records returned for core %d.\n", data.nof_records, core_id);

    /* Print the results.*/
    for (record_index = 0; record_index < data.nof_records; record_index++)
    {
        uint64 *packets_enqueue;
        uint64 *bytes_enqueue;
        uint64 *tod_1588;
        uint32 min_free_ocb_buffers;

        packets_enqueue = &(data.record_arr[record_index].value_arr[packets_enqueue_index]);
        bytes_enqueue = &(data.record_arr[record_index].value_arr[bytes_enqueue_index]);
        tod_1588 = &(data.record_arr[record_index].estimated_time_of_day);
        min_free_ocb_buffers = COMPILER_64_LO(data.record_arr[record_index].value_arr[bytes_enqueue_index]);
        
        printf("%d. Time (%us,%uns): Packets enqueue (%u,%u) Bytes enqueue (%u,%u) min_free_ocb_buffers %u.\n",
               record_index,
               COMPILER_64_HI(*tod_1588), COMPILER_64_LO(*tod_1588),
               COMPILER_64_HI(*packets_enqueue), COMPILER_64_LO(*packets_enqueue),
               COMPILER_64_HI(*bytes_enqueue), COMPILER_64_LO(*bytes_enqueue),
               min_free_ocb_buffers);

        /* Write the min and max*/
        if (record_index == 0)
        {
            cint_instru_synch_enqueue_packets_min = COMPILER_64_LO(*packets_enqueue);
            cint_instru_synch_enqueue_packets_max = COMPILER_64_LO(*packets_enqueue);
        }
        else
        {
            if (cint_instru_synch_enqueue_packets_min > COMPILER_64_LO(*packets_enqueue))
            {
                cint_instru_synch_enqueue_packets_min = COMPILER_64_LO(*packets_enqueue);
            }
            if (cint_instru_synch_enqueue_packets_max < COMPILER_64_LO(*packets_enqueue))
            {
                cint_instru_synch_enqueue_packets_max = COMPILER_64_LO(*packets_enqueue);
            }
        }
    }

    return BCM_E_NONE;
    
}

int
cint_instru_sync_counters_clear(
   int unit)
{
    bcm_instru_synced_counters_config_t config;

    bcm_instru_synced_counters_config_t_init(&config);

    config.enable = FALSE;
    BCM_IF_ERROR_RETURN_MSG(bcm_instru_synced_counters_config_set(unit,0,bcmInstruSyncedCountersTypeIcgm,&config), "");

    return BCM_E_NONE;
}
