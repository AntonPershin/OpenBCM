
/* *INDENT-OFF* */
/*
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2022 Broadcom Inc. All rights reserved.
 */
#ifdef BSL_LOG_MODULE
#error "BSL_LOG_MODULE redefined"
#endif
#define BSL_LOG_MODULE BSL_LS_BCMDNX_DEVICE

#include <soc/dnx/dnx_data/auto_generated/dnx_data_internal_device.h>




extern shr_error_e jr2_a0_data_device_attach(
    int unit);


extern shr_error_e jr2_b0_data_device_attach(
    int unit);


extern shr_error_e jr2_b1_data_device_attach(
    int unit);


extern shr_error_e j2c_a0_data_device_attach(
    int unit);


extern shr_error_e j2c_a1_data_device_attach(
    int unit);


extern shr_error_e q2a_a0_data_device_attach(
    int unit);


extern shr_error_e q2a_b0_data_device_attach(
    int unit);


extern shr_error_e q2a_b1_data_device_attach(
    int unit);


extern shr_error_e j2p_a0_data_device_attach(
    int unit);


extern shr_error_e j2p_a1_data_device_attach(
    int unit);


extern shr_error_e j2p_a2_data_device_attach(
    int unit);


extern shr_error_e j2x_a0_data_device_attach(
    int unit);




static shr_error_e
dnx_data_device_general_init(
    int unit,
    dnxc_data_submodule_t *submodule_data)
{
    SHR_FUNC_INIT_VARS(unit);

    submodule_data->name = "general";
    submodule_data->doc = "";
    
    submodule_data->nof_features = _dnx_data_device_general_feature_nof;
    DNXC_DATA_ALLOC(submodule_data->features, dnxc_data_feature_t,  submodule_data->nof_features, "_dnxc_data device general features");

    submodule_data->features[dnx_data_device_general_production_ready].name = "production_ready";
    submodule_data->features[dnx_data_device_general_production_ready].doc = "";
    submodule_data->features[dnx_data_device_general_production_ready].flags |= DNXC_DATA_F_FEATURE;

    submodule_data->features[dnx_data_device_general_hard_reset_disable].name = "hard_reset_disable";
    submodule_data->features[dnx_data_device_general_hard_reset_disable].doc = "";
    submodule_data->features[dnx_data_device_general_hard_reset_disable].flags |= DNXC_DATA_F_FEATURE;

    submodule_data->features[dnx_data_device_general_stop_on_access_init_error].name = "stop_on_access_init_error";
    submodule_data->features[dnx_data_device_general_stop_on_access_init_error].doc = "";
    submodule_data->features[dnx_data_device_general_stop_on_access_init_error].flags |= DNXC_DATA_F_FEATURE;

    submodule_data->features[dnx_data_device_general_multi_core].name = "multi_core";
    submodule_data->features[dnx_data_device_general_multi_core].doc = "";
    submodule_data->features[dnx_data_device_general_multi_core].flags |= DNXC_DATA_F_FEATURE;

    submodule_data->features[dnx_data_device_general_rqp_ecc_err_exist].name = "rqp_ecc_err_exist";
    submodule_data->features[dnx_data_device_general_rqp_ecc_err_exist].doc = "";
    submodule_data->features[dnx_data_device_general_rqp_ecc_err_exist].flags |= DNXC_DATA_F_FEATURE;

    submodule_data->features[dnx_data_device_general_new_crc32_calc].name = "new_crc32_calc";
    submodule_data->features[dnx_data_device_general_new_crc32_calc].doc = "";
    submodule_data->features[dnx_data_device_general_new_crc32_calc].flags |= DNXC_DATA_F_FEATURE;

    submodule_data->features[dnx_data_device_general_protection_state_ignore].name = "protection_state_ignore";
    submodule_data->features[dnx_data_device_general_protection_state_ignore].doc = "";
    submodule_data->features[dnx_data_device_general_protection_state_ignore].flags |= DNXC_DATA_F_FEATURE;

    submodule_data->features[dnx_data_device_general_delay_exist].name = "delay_exist";
    submodule_data->features[dnx_data_device_general_delay_exist].doc = "";
    submodule_data->features[dnx_data_device_general_delay_exist].flags |= DNXC_DATA_F_FEATURE;

    submodule_data->features[dnx_data_device_general_serdes_support].name = "serdes_support";
    submodule_data->features[dnx_data_device_general_serdes_support].doc = "";
    submodule_data->features[dnx_data_device_general_serdes_support].flags |= DNXC_DATA_F_FEATURE;

    submodule_data->features[dnx_data_device_general_snooping_support].name = "snooping_support";
    submodule_data->features[dnx_data_device_general_snooping_support].doc = "";
    submodule_data->features[dnx_data_device_general_snooping_support].flags |= DNXC_DATA_F_FEATURE;

    submodule_data->features[dnx_data_device_general_mirroring_support].name = "mirroring_support";
    submodule_data->features[dnx_data_device_general_mirroring_support].doc = "";
    submodule_data->features[dnx_data_device_general_mirroring_support].flags |= DNXC_DATA_F_FEATURE;

    submodule_data->features[dnx_data_device_general_injection_support].name = "injection_support";
    submodule_data->features[dnx_data_device_general_injection_support].doc = "";
    submodule_data->features[dnx_data_device_general_injection_support].flags |= DNXC_DATA_F_FEATURE;

    submodule_data->features[dnx_data_device_general_fabric_support].name = "fabric_support";
    submodule_data->features[dnx_data_device_general_fabric_support].doc = "";
    submodule_data->features[dnx_data_device_general_fabric_support].flags |= DNXC_DATA_F_FEATURE;

    submodule_data->features[dnx_data_device_general_flexe_support].name = "flexe_support";
    submodule_data->features[dnx_data_device_general_flexe_support].doc = "";
    submodule_data->features[dnx_data_device_general_flexe_support].flags |= DNXC_DATA_F_FEATURE;

    submodule_data->features[dnx_data_device_general_cmic_support].name = "cmic_support";
    submodule_data->features[dnx_data_device_general_cmic_support].doc = "";
    submodule_data->features[dnx_data_device_general_cmic_support].flags |= DNXC_DATA_F_FEATURE;

    submodule_data->features[dnx_data_device_general_real_interrupts_support].name = "real_interrupts_support";
    submodule_data->features[dnx_data_device_general_real_interrupts_support].doc = "";
    submodule_data->features[dnx_data_device_general_real_interrupts_support].flags |= DNXC_DATA_F_FEATURE;

    submodule_data->features[dnx_data_device_general_i2c_hw_support].name = "i2c_hw_support";
    submodule_data->features[dnx_data_device_general_i2c_hw_support].doc = "";
    submodule_data->features[dnx_data_device_general_i2c_hw_support].flags |= DNXC_DATA_F_FEATURE;

    submodule_data->features[dnx_data_device_general_ring_protection_hw_support].name = "ring_protection_hw_support";
    submodule_data->features[dnx_data_device_general_ring_protection_hw_support].doc = "";
    submodule_data->features[dnx_data_device_general_ring_protection_hw_support].flags |= DNXC_DATA_F_FEATURE;

    submodule_data->features[dnx_data_device_general_hw_support].name = "hw_support";
    submodule_data->features[dnx_data_device_general_hw_support].doc = "";
    submodule_data->features[dnx_data_device_general_hw_support].flags |= DNXC_DATA_F_FEATURE;

    submodule_data->features[dnx_data_device_general_fai_unknown_address_supported].name = "fai_unknown_address_supported";
    submodule_data->features[dnx_data_device_general_fai_unknown_address_supported].doc = "";
    submodule_data->features[dnx_data_device_general_fai_unknown_address_supported].flags |= DNXC_DATA_F_FEATURE;

    submodule_data->features[dnx_data_device_general_itpp_cud_valid_check].name = "itpp_cud_valid_check";
    submodule_data->features[dnx_data_device_general_itpp_cud_valid_check].doc = "";
    submodule_data->features[dnx_data_device_general_itpp_cud_valid_check].flags |= DNXC_DATA_F_FEATURE;

    submodule_data->features[dnx_data_device_general_high_traffic_support].name = "high_traffic_support";
    submodule_data->features[dnx_data_device_general_high_traffic_support].doc = "";
    submodule_data->features[dnx_data_device_general_high_traffic_support].flags |= DNXC_DATA_F_FEATURE;

    submodule_data->features[dnx_data_device_general_ire_negative_delta_support].name = "ire_negative_delta_support";
    submodule_data->features[dnx_data_device_general_ire_negative_delta_support].doc = "";
    submodule_data->features[dnx_data_device_general_ire_negative_delta_support].flags |= DNXC_DATA_F_FEATURE;

    submodule_data->features[dnx_data_device_general_ipc_exists].name = "ipc_exists";
    submodule_data->features[dnx_data_device_general_ipc_exists].doc = "";
    submodule_data->features[dnx_data_device_general_ipc_exists].flags |= DNXC_DATA_F_FEATURE;

    submodule_data->features[dnx_data_device_general_disable_maximal_core_bandwidth_support].name = "disable_maximal_core_bandwidth_support";
    submodule_data->features[dnx_data_device_general_disable_maximal_core_bandwidth_support].doc = "";
    submodule_data->features[dnx_data_device_general_disable_maximal_core_bandwidth_support].flags |= DNXC_DATA_F_FEATURE;

    submodule_data->features[dnx_data_device_general_disable_gated_top_level_sampling].name = "disable_gated_top_level_sampling";
    submodule_data->features[dnx_data_device_general_disable_gated_top_level_sampling].doc = "";
    submodule_data->features[dnx_data_device_general_disable_gated_top_level_sampling].flags |= DNXC_DATA_F_FEATURE;

    submodule_data->features[dnx_data_device_general_cross_connect_support].name = "cross_connect_support";
    submodule_data->features[dnx_data_device_general_cross_connect_support].doc = "";
    submodule_data->features[dnx_data_device_general_cross_connect_support].flags |= DNXC_DATA_F_FEATURE;

    submodule_data->features[dnx_data_device_general_ignore_mdb_sample_diff].name = "ignore_mdb_sample_diff";
    submodule_data->features[dnx_data_device_general_ignore_mdb_sample_diff].doc = "";
    submodule_data->features[dnx_data_device_general_ignore_mdb_sample_diff].flags |= DNXC_DATA_F_FEATURE;

    
    submodule_data->nof_defines = _dnx_data_device_general_define_nof;
    DNXC_DATA_ALLOC(submodule_data->defines, dnxc_data_define_t, submodule_data->nof_defines, "_dnxc_data device general defines");

    submodule_data->defines[dnx_data_device_general_define_max_nof_system_ports].name = "max_nof_system_ports";
    submodule_data->defines[dnx_data_device_general_define_max_nof_system_ports].doc = "";
    
    submodule_data->defines[dnx_data_device_general_define_max_nof_system_ports].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_device_general_define_invalid_system_port].name = "invalid_system_port";
    submodule_data->defines[dnx_data_device_general_define_invalid_system_port].doc = "";
    
    submodule_data->defines[dnx_data_device_general_define_invalid_system_port].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_device_general_define_fmq_system_port].name = "fmq_system_port";
    submodule_data->defines[dnx_data_device_general_define_fmq_system_port].doc = "";
    
    submodule_data->defines[dnx_data_device_general_define_fmq_system_port].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_device_general_define_invalid_fap_id].name = "invalid_fap_id";
    submodule_data->defines[dnx_data_device_general_define_invalid_fap_id].doc = "";
    
    submodule_data->defines[dnx_data_device_general_define_invalid_fap_id].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_device_general_define_fap_ids_per_core_bits].name = "fap_ids_per_core_bits";
    submodule_data->defines[dnx_data_device_general_define_fap_ids_per_core_bits].doc = "";
    
    submodule_data->defines[dnx_data_device_general_define_fap_ids_per_core_bits].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_device_general_define_nof_cores].name = "nof_cores";
    submodule_data->defines[dnx_data_device_general_define_nof_cores].doc = "";
    
    submodule_data->defines[dnx_data_device_general_define_nof_cores].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_device_general_define_valid_cores_bitmap].name = "valid_cores_bitmap";
    submodule_data->defines[dnx_data_device_general_define_valid_cores_bitmap].doc = "";
    
    submodule_data->defines[dnx_data_device_general_define_valid_cores_bitmap].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_device_general_define_nof_cores_for_traffic].name = "nof_cores_for_traffic";
    submodule_data->defines[dnx_data_device_general_define_nof_cores_for_traffic].doc = "";
    
    submodule_data->defines[dnx_data_device_general_define_nof_cores_for_traffic].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_device_general_define_max_nof_layer_protocols].name = "max_nof_layer_protocols";
    submodule_data->defines[dnx_data_device_general_define_max_nof_layer_protocols].doc = "";
    
    submodule_data->defines[dnx_data_device_general_define_max_nof_layer_protocols].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_device_general_define_nof_ipcs].name = "nof_ipcs";
    submodule_data->defines[dnx_data_device_general_define_nof_ipcs].doc = "";
    
    submodule_data->defines[dnx_data_device_general_define_nof_ipcs].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_device_general_define_nof_core_groups].name = "nof_core_groups";
    submodule_data->defines[dnx_data_device_general_define_nof_core_groups].doc = "";
    
    submodule_data->defines[dnx_data_device_general_define_nof_core_groups].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_device_general_define_nof_cores_per_core_group].name = "nof_cores_per_core_group";
    submodule_data->defines[dnx_data_device_general_define_nof_cores_per_core_group].doc = "";
    
    submodule_data->defines[dnx_data_device_general_define_nof_cores_per_core_group].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_device_general_define_nof_avs_status_bits].name = "nof_avs_status_bits";
    submodule_data->defines[dnx_data_device_general_define_nof_avs_status_bits].doc = "";
    
    submodule_data->defines[dnx_data_device_general_define_nof_avs_status_bits].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_device_general_define_core_max_nof_bits].name = "core_max_nof_bits";
    submodule_data->defines[dnx_data_device_general_define_core_max_nof_bits].doc = "";
    
    submodule_data->defines[dnx_data_device_general_define_core_max_nof_bits].flags |= DNXC_DATA_F_NUMERIC;

    submodule_data->defines[dnx_data_device_general_define_max_nof_fap_ids_per_core].name = "max_nof_fap_ids_per_core";
    submodule_data->defines[dnx_data_device_general_define_max_nof_fap_ids_per_core].doc = "";
    
    submodule_data->defines[dnx_data_device_general_define_max_nof_fap_ids_per_core].flags |= DNXC_DATA_F_NUMERIC;

    submodule_data->defines[dnx_data_device_general_define_max_nof_fap_ids_per_device].name = "max_nof_fap_ids_per_device";
    submodule_data->defines[dnx_data_device_general_define_max_nof_fap_ids_per_device].doc = "";
    
    submodule_data->defines[dnx_data_device_general_define_max_nof_fap_ids_per_device].flags |= DNXC_DATA_F_NUMERIC;

    submodule_data->defines[dnx_data_device_general_define_core_clock_khz].name = "core_clock_khz";
    submodule_data->defines[dnx_data_device_general_define_core_clock_khz].doc = "";
    
    submodule_data->defines[dnx_data_device_general_define_core_clock_khz].flags |= DNXC_DATA_F_NUMERIC;

    submodule_data->defines[dnx_data_device_general_define_system_ref_core_clock_khz].name = "system_ref_core_clock_khz";
    submodule_data->defines[dnx_data_device_general_define_system_ref_core_clock_khz].doc = "";
    
    submodule_data->defines[dnx_data_device_general_define_system_ref_core_clock_khz].flags |= DNXC_DATA_F_NUMERIC;

    submodule_data->defines[dnx_data_device_general_define_ref_core_clock_mhz].name = "ref_core_clock_mhz";
    submodule_data->defines[dnx_data_device_general_define_ref_core_clock_mhz].doc = "";
    
    submodule_data->defines[dnx_data_device_general_define_ref_core_clock_mhz].flags |= DNXC_DATA_F_NUMERIC;

    submodule_data->defines[dnx_data_device_general_define_core_clock_ndiv_size].name = "core_clock_ndiv_size";
    submodule_data->defines[dnx_data_device_general_define_core_clock_ndiv_size].doc = "";
    
    submodule_data->defines[dnx_data_device_general_define_core_clock_ndiv_size].flags |= DNXC_DATA_F_NUMERIC;

    submodule_data->defines[dnx_data_device_general_define_core_clock_mdiv_size].name = "core_clock_mdiv_size";
    submodule_data->defines[dnx_data_device_general_define_core_clock_mdiv_size].doc = "";
    
    submodule_data->defines[dnx_data_device_general_define_core_clock_mdiv_size].flags |= DNXC_DATA_F_NUMERIC;

    submodule_data->defines[dnx_data_device_general_define_core_clock_ndiv_offset].name = "core_clock_ndiv_offset";
    submodule_data->defines[dnx_data_device_general_define_core_clock_ndiv_offset].doc = "";
    
    submodule_data->defines[dnx_data_device_general_define_core_clock_ndiv_offset].flags |= DNXC_DATA_F_NUMERIC;

    submodule_data->defines[dnx_data_device_general_define_core_clock_mdiv_offset].name = "core_clock_mdiv_offset";
    submodule_data->defines[dnx_data_device_general_define_core_clock_mdiv_offset].doc = "";
    
    submodule_data->defines[dnx_data_device_general_define_core_clock_mdiv_offset].flags |= DNXC_DATA_F_NUMERIC;

    submodule_data->defines[dnx_data_device_general_define_bus_size_in_bits].name = "bus_size_in_bits";
    submodule_data->defines[dnx_data_device_general_define_bus_size_in_bits].doc = "";
    
    submodule_data->defines[dnx_data_device_general_define_bus_size_in_bits].flags |= DNXC_DATA_F_NUMERIC;

    submodule_data->defines[dnx_data_device_general_define_maximal_core_bandwidth_mbps].name = "maximal_core_bandwidth_mbps";
    submodule_data->defines[dnx_data_device_general_define_maximal_core_bandwidth_mbps].doc = "";
    
    submodule_data->defines[dnx_data_device_general_define_maximal_core_bandwidth_mbps].flags |= DNXC_DATA_F_NUMERIC;

    submodule_data->defines[dnx_data_device_general_define_enforce_maximal_core_bandwidth].name = "enforce_maximal_core_bandwidth";
    submodule_data->defines[dnx_data_device_general_define_enforce_maximal_core_bandwidth].doc = "";
    
    submodule_data->defines[dnx_data_device_general_define_enforce_maximal_core_bandwidth].flags |= DNXC_DATA_F_NUMERIC;

    submodule_data->defines[dnx_data_device_general_define_max_mpps].name = "max_mpps";
    submodule_data->defines[dnx_data_device_general_define_max_mpps].doc = "";
    
    submodule_data->defines[dnx_data_device_general_define_max_mpps].flags |= DNXC_DATA_F_NUMERIC;

    submodule_data->defines[dnx_data_device_general_define_packet_per_clock].name = "packet_per_clock";
    submodule_data->defines[dnx_data_device_general_define_packet_per_clock].doc = "";
    
    submodule_data->defines[dnx_data_device_general_define_packet_per_clock].flags |= DNXC_DATA_F_NUMERIC;

    submodule_data->defines[dnx_data_device_general_define_nof_faps].name = "nof_faps";
    submodule_data->defines[dnx_data_device_general_define_nof_faps].doc = "";
    
    submodule_data->defines[dnx_data_device_general_define_nof_faps].flags |= DNXC_DATA_F_NUMERIC;

    submodule_data->defines[dnx_data_device_general_define_device_id].name = "device_id";
    submodule_data->defines[dnx_data_device_general_define_device_id].doc = "";
    
    submodule_data->defines[dnx_data_device_general_define_device_id].flags |= DNXC_DATA_F_NUMERIC;

    submodule_data->defines[dnx_data_device_general_define_nof_sku_bits].name = "nof_sku_bits";
    submodule_data->defines[dnx_data_device_general_define_nof_sku_bits].doc = "";
    
    submodule_data->defines[dnx_data_device_general_define_nof_sku_bits].flags |= DNXC_DATA_F_NUMERIC;

    submodule_data->defines[dnx_data_device_general_define_bist_enable].name = "bist_enable";
    submodule_data->defines[dnx_data_device_general_define_bist_enable].doc = "";
    
    submodule_data->defines[dnx_data_device_general_define_bist_enable].flags |= DNXC_DATA_F_NUMERIC;

    submodule_data->defines[dnx_data_device_general_define_nof_bits_for_nof_cores].name = "nof_bits_for_nof_cores";
    submodule_data->defines[dnx_data_device_general_define_nof_bits_for_nof_cores].doc = "";
    
    submodule_data->defines[dnx_data_device_general_define_nof_bits_for_nof_cores].flags |= DNXC_DATA_F_NUMERIC;

    
    submodule_data->nof_tables = _dnx_data_device_general_table_nof;
    DNXC_DATA_ALLOC(submodule_data->tables, dnxc_data_table_t, submodule_data->nof_tables, "_dnxc_data device general tables");

    
    submodule_data->tables[dnx_data_device_general_table_ecc_err_masking].name = "ecc_err_masking";
    submodule_data->tables[dnx_data_device_general_table_ecc_err_masking].doc = "";
    submodule_data->tables[dnx_data_device_general_table_ecc_err_masking].flags |= DNXC_DATA_F_TABLE;
    submodule_data->tables[dnx_data_device_general_table_ecc_err_masking].size_of_values = sizeof(dnx_data_device_general_ecc_err_masking_t);
    submodule_data->tables[dnx_data_device_general_table_ecc_err_masking].entry_get = dnx_data_device_general_ecc_err_masking_entry_str_get;

    
    submodule_data->tables[dnx_data_device_general_table_ecc_err_masking].nof_keys = 1;
    submodule_data->tables[dnx_data_device_general_table_ecc_err_masking].keys[0].name = "block_type";
    submodule_data->tables[dnx_data_device_general_table_ecc_err_masking].keys[0].doc = "";

    
    submodule_data->tables[dnx_data_device_general_table_ecc_err_masking].nof_values = 4;
    DNXC_DATA_ALLOC(submodule_data->tables[dnx_data_device_general_table_ecc_err_masking].values, dnxc_data_value_t, submodule_data->tables[dnx_data_device_general_table_ecc_err_masking].nof_values, "_dnx_data_device_general_table_ecc_err_masking table values");
    submodule_data->tables[dnx_data_device_general_table_ecc_err_masking].values[0].name = "ecc_1bit_err_mask_reg";
    submodule_data->tables[dnx_data_device_general_table_ecc_err_masking].values[0].type = "int";
    submodule_data->tables[dnx_data_device_general_table_ecc_err_masking].values[0].doc = "";
    submodule_data->tables[dnx_data_device_general_table_ecc_err_masking].values[0].offset = UTILEX_OFFSETOF(dnx_data_device_general_ecc_err_masking_t, ecc_1bit_err_mask_reg);
    submodule_data->tables[dnx_data_device_general_table_ecc_err_masking].values[1].name = "ecc_1bit_err_field";
    submodule_data->tables[dnx_data_device_general_table_ecc_err_masking].values[1].type = "int[DNX_MAX_NOF_ECC_ERR_MEMS]";
    submodule_data->tables[dnx_data_device_general_table_ecc_err_masking].values[1].doc = "";
    submodule_data->tables[dnx_data_device_general_table_ecc_err_masking].values[1].offset = UTILEX_OFFSETOF(dnx_data_device_general_ecc_err_masking_t, ecc_1bit_err_field);
    submodule_data->tables[dnx_data_device_general_table_ecc_err_masking].values[2].name = "ecc_2bit_err_mask_reg";
    submodule_data->tables[dnx_data_device_general_table_ecc_err_masking].values[2].type = "int";
    submodule_data->tables[dnx_data_device_general_table_ecc_err_masking].values[2].doc = "";
    submodule_data->tables[dnx_data_device_general_table_ecc_err_masking].values[2].offset = UTILEX_OFFSETOF(dnx_data_device_general_ecc_err_masking_t, ecc_2bit_err_mask_reg);
    submodule_data->tables[dnx_data_device_general_table_ecc_err_masking].values[3].name = "ecc_2bit_err_field";
    submodule_data->tables[dnx_data_device_general_table_ecc_err_masking].values[3].type = "int[DNX_MAX_NOF_ECC_ERR_MEMS]";
    submodule_data->tables[dnx_data_device_general_table_ecc_err_masking].values[3].doc = "";
    submodule_data->tables[dnx_data_device_general_table_ecc_err_masking].values[3].offset = UTILEX_OFFSETOF(dnx_data_device_general_ecc_err_masking_t, ecc_2bit_err_field);

    
    submodule_data->tables[dnx_data_device_general_table_ctest_full_file_indentifier].name = "ctest_full_file_indentifier";
    submodule_data->tables[dnx_data_device_general_table_ctest_full_file_indentifier].doc = "";
    submodule_data->tables[dnx_data_device_general_table_ctest_full_file_indentifier].flags |= DNXC_DATA_F_TABLE;
    submodule_data->tables[dnx_data_device_general_table_ctest_full_file_indentifier].size_of_values = sizeof(dnx_data_device_general_ctest_full_file_indentifier_t);
    submodule_data->tables[dnx_data_device_general_table_ctest_full_file_indentifier].entry_get = dnx_data_device_general_ctest_full_file_indentifier_entry_str_get;

    
    submodule_data->tables[dnx_data_device_general_table_ctest_full_file_indentifier].nof_keys = 0;

    
    submodule_data->tables[dnx_data_device_general_table_ctest_full_file_indentifier].nof_values = 2;
    DNXC_DATA_ALLOC(submodule_data->tables[dnx_data_device_general_table_ctest_full_file_indentifier].values, dnxc_data_value_t, submodule_data->tables[dnx_data_device_general_table_ctest_full_file_indentifier].nof_values, "_dnx_data_device_general_table_ctest_full_file_indentifier table values");
    submodule_data->tables[dnx_data_device_general_table_ctest_full_file_indentifier].values[0].name = "family_name";
    submodule_data->tables[dnx_data_device_general_table_ctest_full_file_indentifier].values[0].type = "char *";
    submodule_data->tables[dnx_data_device_general_table_ctest_full_file_indentifier].values[0].doc = "";
    submodule_data->tables[dnx_data_device_general_table_ctest_full_file_indentifier].values[0].offset = UTILEX_OFFSETOF(dnx_data_device_general_ctest_full_file_indentifier_t, family_name);
    submodule_data->tables[dnx_data_device_general_table_ctest_full_file_indentifier].values[1].name = "family_number";
    submodule_data->tables[dnx_data_device_general_table_ctest_full_file_indentifier].values[1].type = "char *";
    submodule_data->tables[dnx_data_device_general_table_ctest_full_file_indentifier].values[1].doc = "";
    submodule_data->tables[dnx_data_device_general_table_ctest_full_file_indentifier].values[1].offset = UTILEX_OFFSETOF(dnx_data_device_general_ctest_full_file_indentifier_t, family_number);


exit:
    SHR_FUNC_EXIT;
}


int
dnx_data_device_general_feature_get(
    int unit,
    dnx_data_device_general_feature_e feature)
{
    return dnxc_data_mgmt_feature_data_get(unit, dnx_data_module_device, dnx_data_device_submodule_general, feature);
}


uint32
dnx_data_device_general_max_nof_system_ports_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_device, dnx_data_device_submodule_general, dnx_data_device_general_define_max_nof_system_ports);
}

uint32
dnx_data_device_general_invalid_system_port_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_device, dnx_data_device_submodule_general, dnx_data_device_general_define_invalid_system_port);
}

uint32
dnx_data_device_general_fmq_system_port_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_device, dnx_data_device_submodule_general, dnx_data_device_general_define_fmq_system_port);
}

uint32
dnx_data_device_general_invalid_fap_id_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_device, dnx_data_device_submodule_general, dnx_data_device_general_define_invalid_fap_id);
}

uint32
dnx_data_device_general_fap_ids_per_core_bits_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_device, dnx_data_device_submodule_general, dnx_data_device_general_define_fap_ids_per_core_bits);
}

uint32
dnx_data_device_general_nof_cores_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_device, dnx_data_device_submodule_general, dnx_data_device_general_define_nof_cores);
}

uint32
dnx_data_device_general_valid_cores_bitmap_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_device, dnx_data_device_submodule_general, dnx_data_device_general_define_valid_cores_bitmap);
}

uint32
dnx_data_device_general_nof_cores_for_traffic_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_device, dnx_data_device_submodule_general, dnx_data_device_general_define_nof_cores_for_traffic);
}

uint32
dnx_data_device_general_max_nof_layer_protocols_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_device, dnx_data_device_submodule_general, dnx_data_device_general_define_max_nof_layer_protocols);
}

uint32
dnx_data_device_general_nof_ipcs_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_device, dnx_data_device_submodule_general, dnx_data_device_general_define_nof_ipcs);
}

uint32
dnx_data_device_general_nof_core_groups_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_device, dnx_data_device_submodule_general, dnx_data_device_general_define_nof_core_groups);
}

uint32
dnx_data_device_general_nof_cores_per_core_group_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_device, dnx_data_device_submodule_general, dnx_data_device_general_define_nof_cores_per_core_group);
}

uint32
dnx_data_device_general_nof_avs_status_bits_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_device, dnx_data_device_submodule_general, dnx_data_device_general_define_nof_avs_status_bits);
}

uint32
dnx_data_device_general_core_max_nof_bits_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_device, dnx_data_device_submodule_general, dnx_data_device_general_define_core_max_nof_bits);
}

uint32
dnx_data_device_general_max_nof_fap_ids_per_core_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_device, dnx_data_device_submodule_general, dnx_data_device_general_define_max_nof_fap_ids_per_core);
}

uint32
dnx_data_device_general_max_nof_fap_ids_per_device_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_device, dnx_data_device_submodule_general, dnx_data_device_general_define_max_nof_fap_ids_per_device);
}

uint32
dnx_data_device_general_core_clock_khz_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_device, dnx_data_device_submodule_general, dnx_data_device_general_define_core_clock_khz);
}

uint32
dnx_data_device_general_system_ref_core_clock_khz_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_device, dnx_data_device_submodule_general, dnx_data_device_general_define_system_ref_core_clock_khz);
}

uint32
dnx_data_device_general_ref_core_clock_mhz_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_device, dnx_data_device_submodule_general, dnx_data_device_general_define_ref_core_clock_mhz);
}

uint32
dnx_data_device_general_core_clock_ndiv_size_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_device, dnx_data_device_submodule_general, dnx_data_device_general_define_core_clock_ndiv_size);
}

uint32
dnx_data_device_general_core_clock_mdiv_size_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_device, dnx_data_device_submodule_general, dnx_data_device_general_define_core_clock_mdiv_size);
}

uint32
dnx_data_device_general_core_clock_ndiv_offset_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_device, dnx_data_device_submodule_general, dnx_data_device_general_define_core_clock_ndiv_offset);
}

uint32
dnx_data_device_general_core_clock_mdiv_offset_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_device, dnx_data_device_submodule_general, dnx_data_device_general_define_core_clock_mdiv_offset);
}

uint32
dnx_data_device_general_bus_size_in_bits_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_device, dnx_data_device_submodule_general, dnx_data_device_general_define_bus_size_in_bits);
}

uint32
dnx_data_device_general_maximal_core_bandwidth_mbps_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_device, dnx_data_device_submodule_general, dnx_data_device_general_define_maximal_core_bandwidth_mbps);
}

uint32
dnx_data_device_general_enforce_maximal_core_bandwidth_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_device, dnx_data_device_submodule_general, dnx_data_device_general_define_enforce_maximal_core_bandwidth);
}

uint32
dnx_data_device_general_max_mpps_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_device, dnx_data_device_submodule_general, dnx_data_device_general_define_max_mpps);
}

uint32
dnx_data_device_general_packet_per_clock_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_device, dnx_data_device_submodule_general, dnx_data_device_general_define_packet_per_clock);
}

uint32
dnx_data_device_general_nof_faps_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_device, dnx_data_device_submodule_general, dnx_data_device_general_define_nof_faps);
}

uint32
dnx_data_device_general_device_id_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_device, dnx_data_device_submodule_general, dnx_data_device_general_define_device_id);
}

uint32
dnx_data_device_general_nof_sku_bits_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_device, dnx_data_device_submodule_general, dnx_data_device_general_define_nof_sku_bits);
}

uint32
dnx_data_device_general_bist_enable_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_device, dnx_data_device_submodule_general, dnx_data_device_general_define_bist_enable);
}

uint32
dnx_data_device_general_nof_bits_for_nof_cores_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_device, dnx_data_device_submodule_general, dnx_data_device_general_define_nof_bits_for_nof_cores);
}



const dnx_data_device_general_ecc_err_masking_t *
dnx_data_device_general_ecc_err_masking_get(
    int unit,
    int block_type)
{
    char *data;
    dnxc_data_table_t *table;

    
    table = dnxc_data_mgmt_table_get(unit, dnx_data_module_device, dnx_data_device_submodule_general, dnx_data_device_general_table_ecc_err_masking);
    
    data = dnxc_data_mgmt_table_data_get(unit, table, block_type, 0);
    return (const dnx_data_device_general_ecc_err_masking_t *) data;

}

const dnx_data_device_general_ctest_full_file_indentifier_t *
dnx_data_device_general_ctest_full_file_indentifier_get(
    int unit)
{
    char *data;
    dnxc_data_table_t *table;

    
    table = dnxc_data_mgmt_table_get(unit, dnx_data_module_device, dnx_data_device_submodule_general, dnx_data_device_general_table_ctest_full_file_indentifier);
    
    data = dnxc_data_mgmt_table_data_get(unit, table, 0, 0);
    return (const dnx_data_device_general_ctest_full_file_indentifier_t *) data;

}


shr_error_e
dnx_data_device_general_ecc_err_masking_entry_str_get(
    int unit,
    char *buffer,
    int key0,
    int key1,
    int value_index)
{
    dnxc_data_table_t *table;
    const dnx_data_device_general_ecc_err_masking_t *data;
    SHR_FUNC_INIT_VARS(unit);

    
    table = dnxc_data_mgmt_table_get(unit, dnx_data_module_device, dnx_data_device_submodule_general, dnx_data_device_general_table_ecc_err_masking);
    data = (const dnx_data_device_general_ecc_err_masking_t *) dnxc_data_mgmt_table_data_diag_get(unit, table, key0, 0);
    switch (value_index)
    {
        case 0:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->ecc_1bit_err_mask_reg);
            break;
        case 1:
            DNXC_DATA_MGMT_ARR_STR(buffer, DNX_MAX_NOF_ECC_ERR_MEMS, data->ecc_1bit_err_field);
            break;
        case 2:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->ecc_2bit_err_mask_reg);
            break;
        case 3:
            DNXC_DATA_MGMT_ARR_STR(buffer, DNX_MAX_NOF_ECC_ERR_MEMS, data->ecc_2bit_err_field);
            break;
    }

    SHR_FUNC_EXIT;
}

shr_error_e
dnx_data_device_general_ctest_full_file_indentifier_entry_str_get(
    int unit,
    char *buffer,
    int key0,
    int key1,
    int value_index)
{
    dnxc_data_table_t *table;
    const dnx_data_device_general_ctest_full_file_indentifier_t *data;
    SHR_FUNC_INIT_VARS(unit);

    
    table = dnxc_data_mgmt_table_get(unit, dnx_data_module_device, dnx_data_device_submodule_general, dnx_data_device_general_table_ctest_full_file_indentifier);
    data = (const dnx_data_device_general_ctest_full_file_indentifier_t *) dnxc_data_mgmt_table_data_diag_get(unit, table, 0, 0);
    switch (value_index)
    {
        case 0:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%s", data->family_name == NULL ? "" : data->family_name);
            break;
        case 1:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%s", data->family_number == NULL ? "" : data->family_number);
            break;
    }

    SHR_FUNC_EXIT;
}


const dnxc_data_table_info_t *
dnx_data_device_general_ecc_err_masking_info_get(
    int unit)
{

    
    return dnxc_data_mgmt_table_info_get(unit, dnx_data_module_device, dnx_data_device_submodule_general, dnx_data_device_general_table_ecc_err_masking);

}

const dnxc_data_table_info_t *
dnx_data_device_general_ctest_full_file_indentifier_info_get(
    int unit)
{

    
    return dnxc_data_mgmt_table_info_get(unit, dnx_data_module_device, dnx_data_device_submodule_general, dnx_data_device_general_table_ctest_full_file_indentifier);

}






static shr_error_e
dnx_data_device_regression_init(
    int unit,
    dnxc_data_submodule_t *submodule_data)
{
    SHR_FUNC_INIT_VARS(unit);

    submodule_data->name = "regression";
    submodule_data->doc = "";
    
    submodule_data->nof_features = _dnx_data_device_regression_feature_nof;
    DNXC_DATA_ALLOC(submodule_data->features, dnxc_data_feature_t,  submodule_data->nof_features, "_dnxc_data device regression features");

    
    submodule_data->nof_defines = _dnx_data_device_regression_define_nof;
    DNXC_DATA_ALLOC(submodule_data->defines, dnxc_data_define_t, submodule_data->nof_defines, "_dnxc_data device regression defines");

    
    submodule_data->nof_tables = _dnx_data_device_regression_table_nof;
    DNXC_DATA_ALLOC(submodule_data->tables, dnxc_data_table_t, submodule_data->nof_tables, "_dnxc_data device regression tables");

    
    submodule_data->tables[dnx_data_device_regression_table_regression_parms].name = "regression_parms";
    submodule_data->tables[dnx_data_device_regression_table_regression_parms].doc = "";
    submodule_data->tables[dnx_data_device_regression_table_regression_parms].flags |= DNXC_DATA_F_TABLE;
    submodule_data->tables[dnx_data_device_regression_table_regression_parms].size_of_values = sizeof(dnx_data_device_regression_regression_parms_t);
    submodule_data->tables[dnx_data_device_regression_table_regression_parms].entry_get = dnx_data_device_regression_regression_parms_entry_str_get;

    
    submodule_data->tables[dnx_data_device_regression_table_regression_parms].nof_keys = 0;

    
    submodule_data->tables[dnx_data_device_regression_table_regression_parms].nof_values = 1;
    DNXC_DATA_ALLOC(submodule_data->tables[dnx_data_device_regression_table_regression_parms].values, dnxc_data_value_t, submodule_data->tables[dnx_data_device_regression_table_regression_parms].nof_values, "_dnx_data_device_regression_table_regression_parms table values");
    submodule_data->tables[dnx_data_device_regression_table_regression_parms].values[0].name = "system_mode_name";
    submodule_data->tables[dnx_data_device_regression_table_regression_parms].values[0].type = "char *";
    submodule_data->tables[dnx_data_device_regression_table_regression_parms].values[0].doc = "";
    submodule_data->tables[dnx_data_device_regression_table_regression_parms].values[0].offset = UTILEX_OFFSETOF(dnx_data_device_regression_regression_parms_t, system_mode_name);


exit:
    SHR_FUNC_EXIT;
}


int
dnx_data_device_regression_feature_get(
    int unit,
    dnx_data_device_regression_feature_e feature)
{
    return dnxc_data_mgmt_feature_data_get(unit, dnx_data_module_device, dnx_data_device_submodule_regression, feature);
}




const dnx_data_device_regression_regression_parms_t *
dnx_data_device_regression_regression_parms_get(
    int unit)
{
    char *data;
    dnxc_data_table_t *table;

    
    table = dnxc_data_mgmt_table_get(unit, dnx_data_module_device, dnx_data_device_submodule_regression, dnx_data_device_regression_table_regression_parms);
    
    data = dnxc_data_mgmt_table_data_get(unit, table, 0, 0);
    return (const dnx_data_device_regression_regression_parms_t *) data;

}


shr_error_e
dnx_data_device_regression_regression_parms_entry_str_get(
    int unit,
    char *buffer,
    int key0,
    int key1,
    int value_index)
{
    dnxc_data_table_t *table;
    const dnx_data_device_regression_regression_parms_t *data;
    SHR_FUNC_INIT_VARS(unit);

    
    table = dnxc_data_mgmt_table_get(unit, dnx_data_module_device, dnx_data_device_submodule_regression, dnx_data_device_regression_table_regression_parms);
    data = (const dnx_data_device_regression_regression_parms_t *) dnxc_data_mgmt_table_data_diag_get(unit, table, 0, 0);
    switch (value_index)
    {
        case 0:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%s", data->system_mode_name == NULL ? "" : data->system_mode_name);
            break;
    }

    SHR_FUNC_EXIT;
}


const dnxc_data_table_info_t *
dnx_data_device_regression_regression_parms_info_get(
    int unit)
{

    
    return dnxc_data_mgmt_table_info_get(unit, dnx_data_module_device, dnx_data_device_submodule_regression, dnx_data_device_regression_table_regression_parms);

}






static shr_error_e
dnx_data_device_emulation_init(
    int unit,
    dnxc_data_submodule_t *submodule_data)
{
    SHR_FUNC_INIT_VARS(unit);

    submodule_data->name = "emulation";
    submodule_data->doc = "";
    
    submodule_data->nof_features = _dnx_data_device_emulation_feature_nof;
    DNXC_DATA_ALLOC(submodule_data->features, dnxc_data_feature_t,  submodule_data->nof_features, "_dnxc_data device emulation features");

    submodule_data->features[dnx_data_device_emulation_fmac_supported].name = "fmac_supported";
    submodule_data->features[dnx_data_device_emulation_fmac_supported].doc = "";
    submodule_data->features[dnx_data_device_emulation_fmac_supported].flags |= DNXC_DATA_F_FEATURE;

    submodule_data->features[dnx_data_device_emulation_ecc_enable].name = "ecc_enable";
    submodule_data->features[dnx_data_device_emulation_ecc_enable].doc = "";
    submodule_data->features[dnx_data_device_emulation_ecc_enable].flags |= DNXC_DATA_F_FEATURE;

    
    submodule_data->nof_defines = _dnx_data_device_emulation_define_nof;
    DNXC_DATA_ALLOC(submodule_data->defines, dnxc_data_define_t, submodule_data->nof_defines, "_dnxc_data device emulation defines");

    submodule_data->defines[dnx_data_device_emulation_define_emulation_system].name = "emulation_system";
    submodule_data->defines[dnx_data_device_emulation_define_emulation_system].doc = "";
    
    submodule_data->defines[dnx_data_device_emulation_define_emulation_system].flags |= DNXC_DATA_F_NUMERIC;

    submodule_data->defines[dnx_data_device_emulation_define_framer_init_mode].name = "framer_init_mode";
    submodule_data->defines[dnx_data_device_emulation_define_framer_init_mode].doc = "";
    
    submodule_data->defines[dnx_data_device_emulation_define_framer_init_mode].flags |= DNXC_DATA_F_NUMERIC;

    
    submodule_data->nof_tables = _dnx_data_device_emulation_table_nof;
    DNXC_DATA_ALLOC(submodule_data->tables, dnxc_data_table_t, submodule_data->nof_tables, "_dnxc_data device emulation tables");


exit:
    SHR_FUNC_EXIT;
}


int
dnx_data_device_emulation_feature_get(
    int unit,
    dnx_data_device_emulation_feature_e feature)
{
    return dnxc_data_mgmt_feature_data_get(unit, dnx_data_module_device, dnx_data_device_submodule_emulation, feature);
}


uint32
dnx_data_device_emulation_emulation_system_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_device, dnx_data_device_submodule_emulation, dnx_data_device_emulation_define_emulation_system);
}

uint32
dnx_data_device_emulation_framer_init_mode_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_device, dnx_data_device_submodule_emulation, dnx_data_device_emulation_define_framer_init_mode);
}










static shr_error_e
dnx_data_device_otp_init(
    int unit,
    dnxc_data_submodule_t *submodule_data)
{
    SHR_FUNC_INIT_VARS(unit);

    submodule_data->name = "otp";
    submodule_data->doc = "";
    
    submodule_data->nof_features = _dnx_data_device_otp_feature_nof;
    DNXC_DATA_ALLOC(submodule_data->features, dnxc_data_feature_t,  submodule_data->nof_features, "_dnxc_data device otp features");

    
    submodule_data->nof_defines = _dnx_data_device_otp_define_nof;
    DNXC_DATA_ALLOC(submodule_data->defines, dnxc_data_define_t, submodule_data->nof_defines, "_dnxc_data device otp defines");

    submodule_data->defines[dnx_data_device_otp_define_nof_words_in_row].name = "nof_words_in_row";
    submodule_data->defines[dnx_data_device_otp_define_nof_words_in_row].doc = "";
    
    submodule_data->defines[dnx_data_device_otp_define_nof_words_in_row].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_device_otp_define_read_timeout].name = "read_timeout";
    submodule_data->defines[dnx_data_device_otp_define_read_timeout].doc = "";
    
    submodule_data->defines[dnx_data_device_otp_define_read_timeout].flags |= DNXC_DATA_F_DEFINE;

    
    submodule_data->nof_tables = _dnx_data_device_otp_table_nof;
    DNXC_DATA_ALLOC(submodule_data->tables, dnxc_data_table_t, submodule_data->nof_tables, "_dnxc_data device otp tables");

    
    submodule_data->tables[dnx_data_device_otp_table_otp_instance_attributes].name = "otp_instance_attributes";
    submodule_data->tables[dnx_data_device_otp_table_otp_instance_attributes].doc = "";
    submodule_data->tables[dnx_data_device_otp_table_otp_instance_attributes].flags |= DNXC_DATA_F_TABLE;
    submodule_data->tables[dnx_data_device_otp_table_otp_instance_attributes].size_of_values = sizeof(dnx_data_device_otp_otp_instance_attributes_t);
    submodule_data->tables[dnx_data_device_otp_table_otp_instance_attributes].entry_get = dnx_data_device_otp_otp_instance_attributes_entry_str_get;

    
    submodule_data->tables[dnx_data_device_otp_table_otp_instance_attributes].nof_keys = 1;
    submodule_data->tables[dnx_data_device_otp_table_otp_instance_attributes].keys[0].name = "otp_instance_index";
    submodule_data->tables[dnx_data_device_otp_table_otp_instance_attributes].keys[0].doc = "";

    
    submodule_data->tables[dnx_data_device_otp_table_otp_instance_attributes].nof_values = 3;
    DNXC_DATA_ALLOC(submodule_data->tables[dnx_data_device_otp_table_otp_instance_attributes].values, dnxc_data_value_t, submodule_data->tables[dnx_data_device_otp_table_otp_instance_attributes].nof_values, "_dnx_data_device_otp_table_otp_instance_attributes table values");
    submodule_data->tables[dnx_data_device_otp_table_otp_instance_attributes].values[0].name = "block_id";
    submodule_data->tables[dnx_data_device_otp_table_otp_instance_attributes].values[0].type = "int";
    submodule_data->tables[dnx_data_device_otp_table_otp_instance_attributes].values[0].doc = "";
    submodule_data->tables[dnx_data_device_otp_table_otp_instance_attributes].values[0].offset = UTILEX_OFFSETOF(dnx_data_device_otp_otp_instance_attributes_t, block_id);
    submodule_data->tables[dnx_data_device_otp_table_otp_instance_attributes].values[1].name = "is_supported";
    submodule_data->tables[dnx_data_device_otp_table_otp_instance_attributes].values[1].type = "int";
    submodule_data->tables[dnx_data_device_otp_table_otp_instance_attributes].values[1].doc = "";
    submodule_data->tables[dnx_data_device_otp_table_otp_instance_attributes].values[1].offset = UTILEX_OFFSETOF(dnx_data_device_otp_otp_instance_attributes_t, is_supported);
    submodule_data->tables[dnx_data_device_otp_table_otp_instance_attributes].values[2].name = "size";
    submodule_data->tables[dnx_data_device_otp_table_otp_instance_attributes].values[2].type = "int";
    submodule_data->tables[dnx_data_device_otp_table_otp_instance_attributes].values[2].doc = "";
    submodule_data->tables[dnx_data_device_otp_table_otp_instance_attributes].values[2].offset = UTILEX_OFFSETOF(dnx_data_device_otp_otp_instance_attributes_t, size);

    
    submodule_data->tables[dnx_data_device_otp_table_reg_addresses].name = "reg_addresses";
    submodule_data->tables[dnx_data_device_otp_table_reg_addresses].doc = "";
    submodule_data->tables[dnx_data_device_otp_table_reg_addresses].flags |= DNXC_DATA_F_TABLE;
    submodule_data->tables[dnx_data_device_otp_table_reg_addresses].size_of_values = sizeof(dnx_data_device_otp_reg_addresses_t);
    submodule_data->tables[dnx_data_device_otp_table_reg_addresses].entry_get = dnx_data_device_otp_reg_addresses_entry_str_get;

    
    submodule_data->tables[dnx_data_device_otp_table_reg_addresses].nof_keys = 0;

    
    submodule_data->tables[dnx_data_device_otp_table_reg_addresses].nof_values = 8;
    DNXC_DATA_ALLOC(submodule_data->tables[dnx_data_device_otp_table_reg_addresses].values, dnxc_data_value_t, submodule_data->tables[dnx_data_device_otp_table_reg_addresses].nof_values, "_dnx_data_device_otp_table_reg_addresses table values");
    submodule_data->tables[dnx_data_device_otp_table_reg_addresses].values[0].name = "mode";
    submodule_data->tables[dnx_data_device_otp_table_reg_addresses].values[0].type = "uint32";
    submodule_data->tables[dnx_data_device_otp_table_reg_addresses].values[0].doc = "";
    submodule_data->tables[dnx_data_device_otp_table_reg_addresses].values[0].offset = UTILEX_OFFSETOF(dnx_data_device_otp_reg_addresses_t, mode);
    submodule_data->tables[dnx_data_device_otp_table_reg_addresses].values[1].name = "cpu_addr";
    submodule_data->tables[dnx_data_device_otp_table_reg_addresses].values[1].type = "uint32";
    submodule_data->tables[dnx_data_device_otp_table_reg_addresses].values[1].doc = "";
    submodule_data->tables[dnx_data_device_otp_table_reg_addresses].values[1].offset = UTILEX_OFFSETOF(dnx_data_device_otp_reg_addresses_t, cpu_addr);
    submodule_data->tables[dnx_data_device_otp_table_reg_addresses].values[2].name = "cmd";
    submodule_data->tables[dnx_data_device_otp_table_reg_addresses].values[2].type = "uint32";
    submodule_data->tables[dnx_data_device_otp_table_reg_addresses].values[2].doc = "";
    submodule_data->tables[dnx_data_device_otp_table_reg_addresses].values[2].offset = UTILEX_OFFSETOF(dnx_data_device_otp_reg_addresses_t, cmd);
    submodule_data->tables[dnx_data_device_otp_table_reg_addresses].values[3].name = "cmd_start";
    submodule_data->tables[dnx_data_device_otp_table_reg_addresses].values[3].type = "uint32";
    submodule_data->tables[dnx_data_device_otp_table_reg_addresses].values[3].doc = "";
    submodule_data->tables[dnx_data_device_otp_table_reg_addresses].values[3].offset = UTILEX_OFFSETOF(dnx_data_device_otp_reg_addresses_t, cmd_start);
    submodule_data->tables[dnx_data_device_otp_table_reg_addresses].values[4].name = "cpu_status";
    submodule_data->tables[dnx_data_device_otp_table_reg_addresses].values[4].type = "uint32";
    submodule_data->tables[dnx_data_device_otp_table_reg_addresses].values[4].doc = "";
    submodule_data->tables[dnx_data_device_otp_table_reg_addresses].values[4].offset = UTILEX_OFFSETOF(dnx_data_device_otp_reg_addresses_t, cpu_status);
    submodule_data->tables[dnx_data_device_otp_table_reg_addresses].values[5].name = "cpu_data_0";
    submodule_data->tables[dnx_data_device_otp_table_reg_addresses].values[5].type = "uint32";
    submodule_data->tables[dnx_data_device_otp_table_reg_addresses].values[5].doc = "";
    submodule_data->tables[dnx_data_device_otp_table_reg_addresses].values[5].offset = UTILEX_OFFSETOF(dnx_data_device_otp_reg_addresses_t, cpu_data_0);
    submodule_data->tables[dnx_data_device_otp_table_reg_addresses].values[6].name = "cpu_data_1";
    submodule_data->tables[dnx_data_device_otp_table_reg_addresses].values[6].type = "uint32";
    submodule_data->tables[dnx_data_device_otp_table_reg_addresses].values[6].doc = "";
    submodule_data->tables[dnx_data_device_otp_table_reg_addresses].values[6].offset = UTILEX_OFFSETOF(dnx_data_device_otp_reg_addresses_t, cpu_data_1);
    submodule_data->tables[dnx_data_device_otp_table_reg_addresses].values[7].name = "cpu_data_2";
    submodule_data->tables[dnx_data_device_otp_table_reg_addresses].values[7].type = "uint32";
    submodule_data->tables[dnx_data_device_otp_table_reg_addresses].values[7].doc = "";
    submodule_data->tables[dnx_data_device_otp_table_reg_addresses].values[7].offset = UTILEX_OFFSETOF(dnx_data_device_otp_reg_addresses_t, cpu_data_2);


exit:
    SHR_FUNC_EXIT;
}


int
dnx_data_device_otp_feature_get(
    int unit,
    dnx_data_device_otp_feature_e feature)
{
    return dnxc_data_mgmt_feature_data_get(unit, dnx_data_module_device, dnx_data_device_submodule_otp, feature);
}


uint32
dnx_data_device_otp_nof_words_in_row_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_device, dnx_data_device_submodule_otp, dnx_data_device_otp_define_nof_words_in_row);
}

uint32
dnx_data_device_otp_read_timeout_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_device, dnx_data_device_submodule_otp, dnx_data_device_otp_define_read_timeout);
}



const dnx_data_device_otp_otp_instance_attributes_t *
dnx_data_device_otp_otp_instance_attributes_get(
    int unit,
    int otp_instance_index)
{
    char *data;
    dnxc_data_table_t *table;

    
    table = dnxc_data_mgmt_table_get(unit, dnx_data_module_device, dnx_data_device_submodule_otp, dnx_data_device_otp_table_otp_instance_attributes);
    
    data = dnxc_data_mgmt_table_data_get(unit, table, otp_instance_index, 0);
    return (const dnx_data_device_otp_otp_instance_attributes_t *) data;

}

const dnx_data_device_otp_reg_addresses_t *
dnx_data_device_otp_reg_addresses_get(
    int unit)
{
    char *data;
    dnxc_data_table_t *table;

    
    table = dnxc_data_mgmt_table_get(unit, dnx_data_module_device, dnx_data_device_submodule_otp, dnx_data_device_otp_table_reg_addresses);
    
    data = dnxc_data_mgmt_table_data_get(unit, table, 0, 0);
    return (const dnx_data_device_otp_reg_addresses_t *) data;

}


shr_error_e
dnx_data_device_otp_otp_instance_attributes_entry_str_get(
    int unit,
    char *buffer,
    int key0,
    int key1,
    int value_index)
{
    dnxc_data_table_t *table;
    const dnx_data_device_otp_otp_instance_attributes_t *data;
    SHR_FUNC_INIT_VARS(unit);

    
    table = dnxc_data_mgmt_table_get(unit, dnx_data_module_device, dnx_data_device_submodule_otp, dnx_data_device_otp_table_otp_instance_attributes);
    data = (const dnx_data_device_otp_otp_instance_attributes_t *) dnxc_data_mgmt_table_data_diag_get(unit, table, key0, 0);
    switch (value_index)
    {
        case 0:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->block_id);
            break;
        case 1:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->is_supported);
            break;
        case 2:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->size);
            break;
    }

    SHR_FUNC_EXIT;
}

shr_error_e
dnx_data_device_otp_reg_addresses_entry_str_get(
    int unit,
    char *buffer,
    int key0,
    int key1,
    int value_index)
{
    dnxc_data_table_t *table;
    const dnx_data_device_otp_reg_addresses_t *data;
    SHR_FUNC_INIT_VARS(unit);

    
    table = dnxc_data_mgmt_table_get(unit, dnx_data_module_device, dnx_data_device_submodule_otp, dnx_data_device_otp_table_reg_addresses);
    data = (const dnx_data_device_otp_reg_addresses_t *) dnxc_data_mgmt_table_data_diag_get(unit, table, 0, 0);
    switch (value_index)
    {
        case 0:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->mode);
            break;
        case 1:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->cpu_addr);
            break;
        case 2:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->cmd);
            break;
        case 3:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->cmd_start);
            break;
        case 4:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->cpu_status);
            break;
        case 5:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->cpu_data_0);
            break;
        case 6:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->cpu_data_1);
            break;
        case 7:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->cpu_data_2);
            break;
    }

    SHR_FUNC_EXIT;
}


const dnxc_data_table_info_t *
dnx_data_device_otp_otp_instance_attributes_info_get(
    int unit)
{

    
    return dnxc_data_mgmt_table_info_get(unit, dnx_data_module_device, dnx_data_device_submodule_otp, dnx_data_device_otp_table_otp_instance_attributes);

}

const dnxc_data_table_info_t *
dnx_data_device_otp_reg_addresses_info_get(
    int unit)
{

    
    return dnxc_data_mgmt_table_info_get(unit, dnx_data_module_device, dnx_data_device_submodule_otp, dnx_data_device_otp_table_reg_addresses);

}






static shr_error_e
dnx_data_device_docs_init(
    int unit,
    dnxc_data_submodule_t *submodule_data)
{
    SHR_FUNC_INIT_VARS(unit);

    submodule_data->name = "docs";
    submodule_data->doc = "";
    
    submodule_data->nof_features = _dnx_data_device_docs_feature_nof;
    DNXC_DATA_ALLOC(submodule_data->features, dnxc_data_feature_t,  submodule_data->nof_features, "_dnxc_data device docs features");

    submodule_data->features[dnx_data_device_docs_is_fap].name = "is_fap";
    submodule_data->features[dnx_data_device_docs_is_fap].doc = "";
    submodule_data->features[dnx_data_device_docs_is_fap].flags |= DNXC_DATA_F_FEATURE;

    
    submodule_data->nof_defines = _dnx_data_device_docs_define_nof;
    DNXC_DATA_ALLOC(submodule_data->defines, dnxc_data_define_t, submodule_data->nof_defines, "_dnxc_data device docs defines");

    
    submodule_data->nof_tables = _dnx_data_device_docs_table_nof;
    DNXC_DATA_ALLOC(submodule_data->tables, dnxc_data_table_t, submodule_data->nof_tables, "_dnxc_data device docs tables");


exit:
    SHR_FUNC_EXIT;
}


int
dnx_data_device_docs_feature_get(
    int unit,
    dnx_data_device_docs_feature_e feature)
{
    return dnxc_data_mgmt_feature_data_get(unit, dnx_data_module_device, dnx_data_device_submodule_docs, feature);
}








shr_error_e
dnx_data_device_init(
    int unit,
    dnxc_data_module_t *module_data)
{
    SHR_FUNC_INIT_VARS(unit);

    
    module_data->name = "device";
    module_data->nof_submodules = _dnx_data_device_submodule_nof;
    DNXC_DATA_ALLOC(module_data->submodules, dnxc_data_submodule_t, module_data->nof_submodules, "_dnxc_data device submodules");

    
    SHR_IF_ERR_EXIT(dnx_data_device_general_init(unit, &module_data->submodules[dnx_data_device_submodule_general]));
    SHR_IF_ERR_EXIT(dnx_data_device_regression_init(unit, &module_data->submodules[dnx_data_device_submodule_regression]));
    SHR_IF_ERR_EXIT(dnx_data_device_emulation_init(unit, &module_data->submodules[dnx_data_device_submodule_emulation]));
    SHR_IF_ERR_EXIT(dnx_data_device_otp_init(unit, &module_data->submodules[dnx_data_device_submodule_otp]));
    SHR_IF_ERR_EXIT(dnx_data_device_docs_init(unit, &module_data->submodules[dnx_data_device_submodule_docs]));
    

    if (dnxc_data_mgmt_is_jr2_a0(unit))
    {
        SHR_IF_ERR_EXIT(jr2_a0_data_device_attach(unit));
    }
    else


    if (dnxc_data_mgmt_is_jr2_b0(unit))
    {
        SHR_IF_ERR_EXIT(jr2_a0_data_device_attach(unit));
        SHR_IF_ERR_EXIT(jr2_b0_data_device_attach(unit));
    }
    else


    if (dnxc_data_mgmt_is_jr2_b1(unit))
    {
        SHR_IF_ERR_EXIT(jr2_a0_data_device_attach(unit));
        SHR_IF_ERR_EXIT(jr2_b0_data_device_attach(unit));
        SHR_IF_ERR_EXIT(jr2_b1_data_device_attach(unit));
    }
    else


    if (dnxc_data_mgmt_is_j2c_a0(unit))
    {
        SHR_IF_ERR_EXIT(jr2_a0_data_device_attach(unit));
        SHR_IF_ERR_EXIT(j2c_a0_data_device_attach(unit));
    }
    else


    if (dnxc_data_mgmt_is_j2c_a1(unit))
    {
        SHR_IF_ERR_EXIT(jr2_a0_data_device_attach(unit));
        SHR_IF_ERR_EXIT(j2c_a0_data_device_attach(unit));
        SHR_IF_ERR_EXIT(j2c_a1_data_device_attach(unit));
    }
    else


    if (dnxc_data_mgmt_is_q2a_a0(unit))
    {
        SHR_IF_ERR_EXIT(jr2_a0_data_device_attach(unit));
        SHR_IF_ERR_EXIT(q2a_a0_data_device_attach(unit));
    }
    else


    if (dnxc_data_mgmt_is_q2a_b0(unit))
    {
        SHR_IF_ERR_EXIT(jr2_a0_data_device_attach(unit));
        SHR_IF_ERR_EXIT(q2a_a0_data_device_attach(unit));
        SHR_IF_ERR_EXIT(q2a_b0_data_device_attach(unit));
    }
    else


    if (dnxc_data_mgmt_is_q2a_b1(unit))
    {
        SHR_IF_ERR_EXIT(jr2_a0_data_device_attach(unit));
        SHR_IF_ERR_EXIT(q2a_a0_data_device_attach(unit));
        SHR_IF_ERR_EXIT(q2a_b0_data_device_attach(unit));
        SHR_IF_ERR_EXIT(q2a_b1_data_device_attach(unit));
    }
    else


    if (dnxc_data_mgmt_is_j2p_a0(unit))
    {
        SHR_IF_ERR_EXIT(jr2_a0_data_device_attach(unit));
        SHR_IF_ERR_EXIT(j2p_a0_data_device_attach(unit));
    }
    else


    if (dnxc_data_mgmt_is_j2p_a1(unit))
    {
        SHR_IF_ERR_EXIT(jr2_a0_data_device_attach(unit));
        SHR_IF_ERR_EXIT(j2p_a0_data_device_attach(unit));
        SHR_IF_ERR_EXIT(j2p_a1_data_device_attach(unit));
    }
    else


    if (dnxc_data_mgmt_is_j2p_a2(unit))
    {
        SHR_IF_ERR_EXIT(jr2_a0_data_device_attach(unit));
        SHR_IF_ERR_EXIT(j2p_a0_data_device_attach(unit));
        SHR_IF_ERR_EXIT(j2p_a2_data_device_attach(unit));
    }
    else


    if (dnxc_data_mgmt_is_j2x_a0(unit))
    {
        SHR_IF_ERR_EXIT(jr2_a0_data_device_attach(unit));
        SHR_IF_ERR_EXIT(j2x_a0_data_device_attach(unit));
    }
    else

    {
        SHR_EXIT();
    }

exit:
    SHR_FUNC_EXIT;
}
#undef BSL_LOG_MODULE

