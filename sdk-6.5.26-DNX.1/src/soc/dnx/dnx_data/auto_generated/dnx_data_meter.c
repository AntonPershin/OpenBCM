
/* *INDENT-OFF* */
/*
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2022 Broadcom Inc. All rights reserved.
 */
#ifdef BSL_LOG_MODULE
#error "BSL_LOG_MODULE redefined"
#endif
#define BSL_LOG_MODULE BSL_LS_BCMDNX_POLICER

#include <soc/dnx/dnx_data/auto_generated/dnx_data_internal_meter.h>




extern shr_error_e jr2_a0_data_meter_attach(
    int unit);


extern shr_error_e jr2_b0_data_meter_attach(
    int unit);


extern shr_error_e j2c_a0_data_meter_attach(
    int unit);


extern shr_error_e q2a_a0_data_meter_attach(
    int unit);


extern shr_error_e j2p_a0_data_meter_attach(
    int unit);


extern shr_error_e j2x_a0_data_meter_attach(
    int unit);




static shr_error_e
dnx_data_meter_general_init(
    int unit,
    dnxc_data_submodule_t *submodule_data)
{
    SHR_FUNC_INIT_VARS(unit);

    submodule_data->name = "general";
    submodule_data->doc = "";
    
    submodule_data->nof_features = _dnx_data_meter_general_feature_nof;
    DNXC_DATA_ALLOC(submodule_data->features, dnxc_data_feature_t,  submodule_data->nof_features, "_dnxc_data meter general features");

    submodule_data->features[dnx_data_meter_general_is_used].name = "is_used";
    submodule_data->features[dnx_data_meter_general_is_used].doc = "";
    submodule_data->features[dnx_data_meter_general_is_used].flags |= DNXC_DATA_F_FEATURE;

    submodule_data->features[dnx_data_meter_general_power_down_supported].name = "power_down_supported";
    submodule_data->features[dnx_data_meter_general_power_down_supported].doc = "";
    submodule_data->features[dnx_data_meter_general_power_down_supported].flags |= DNXC_DATA_F_FEATURE;

    
    submodule_data->nof_defines = _dnx_data_meter_general_define_nof;
    DNXC_DATA_ALLOC(submodule_data->defines, dnxc_data_define_t, submodule_data->nof_defines, "_dnxc_data meter general defines");

    
    submodule_data->nof_tables = _dnx_data_meter_general_table_nof;
    DNXC_DATA_ALLOC(submodule_data->tables, dnxc_data_table_t, submodule_data->nof_tables, "_dnxc_data meter general tables");


exit:
    SHR_FUNC_EXIT;
}


int
dnx_data_meter_general_feature_get(
    int unit,
    dnx_data_meter_general_feature_e feature)
{
    return dnxc_data_mgmt_feature_data_get(unit, dnx_data_module_meter, dnx_data_meter_submodule_general, feature);
}











static shr_error_e
dnx_data_meter_profile_init(
    int unit,
    dnxc_data_submodule_t *submodule_data)
{
    SHR_FUNC_INIT_VARS(unit);

    submodule_data->name = "profile";
    submodule_data->doc = "";
    
    submodule_data->nof_features = _dnx_data_meter_profile_feature_nof;
    DNXC_DATA_ALLOC(submodule_data->features, dnxc_data_feature_t,  submodule_data->nof_features, "_dnxc_data meter profile features");

    
    submodule_data->nof_defines = _dnx_data_meter_profile_define_nof;
    DNXC_DATA_ALLOC(submodule_data->defines, dnxc_data_define_t, submodule_data->nof_defines, "_dnxc_data meter profile defines");

    submodule_data->defines[dnx_data_meter_profile_define_large_bucket_mode_exp_add].name = "large_bucket_mode_exp_add";
    submodule_data->defines[dnx_data_meter_profile_define_large_bucket_mode_exp_add].doc = "";
    
    submodule_data->defines[dnx_data_meter_profile_define_large_bucket_mode_exp_add].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_meter_profile_define_max_regular_bucket_mode_burst].name = "max_regular_bucket_mode_burst";
    submodule_data->defines[dnx_data_meter_profile_define_max_regular_bucket_mode_burst].doc = "";
    
    submodule_data->defines[dnx_data_meter_profile_define_max_regular_bucket_mode_burst].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_meter_profile_define_rev_exp_min].name = "rev_exp_min";
    submodule_data->defines[dnx_data_meter_profile_define_rev_exp_min].doc = "";
    
    submodule_data->defines[dnx_data_meter_profile_define_rev_exp_min].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_meter_profile_define_rev_exp_max].name = "rev_exp_max";
    submodule_data->defines[dnx_data_meter_profile_define_rev_exp_max].doc = "";
    
    submodule_data->defines[dnx_data_meter_profile_define_rev_exp_max].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_meter_profile_define_burst_size_min].name = "burst_size_min";
    submodule_data->defines[dnx_data_meter_profile_define_burst_size_min].doc = "";
    
    submodule_data->defines[dnx_data_meter_profile_define_burst_size_min].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_meter_profile_define_nof_valid_global_meters].name = "nof_valid_global_meters";
    submodule_data->defines[dnx_data_meter_profile_define_nof_valid_global_meters].doc = "";
    
    submodule_data->defines[dnx_data_meter_profile_define_nof_valid_global_meters].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_meter_profile_define_nof_dp_command_max].name = "nof_dp_command_max";
    submodule_data->defines[dnx_data_meter_profile_define_nof_dp_command_max].doc = "";
    
    submodule_data->defines[dnx_data_meter_profile_define_nof_dp_command_max].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_meter_profile_define_global_engine_hw_stat_database_id].name = "global_engine_hw_stat_database_id";
    submodule_data->defines[dnx_data_meter_profile_define_global_engine_hw_stat_database_id].doc = "";
    
    submodule_data->defines[dnx_data_meter_profile_define_global_engine_hw_stat_database_id].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_meter_profile_define_ir_mant_nof_bits].name = "ir_mant_nof_bits";
    submodule_data->defines[dnx_data_meter_profile_define_ir_mant_nof_bits].doc = "";
    
    submodule_data->defines[dnx_data_meter_profile_define_ir_mant_nof_bits].flags |= DNXC_DATA_F_DEFINE;

    
    submodule_data->nof_tables = _dnx_data_meter_profile_table_nof;
    DNXC_DATA_ALLOC(submodule_data->tables, dnxc_data_table_t, submodule_data->nof_tables, "_dnxc_data meter profile tables");


exit:
    SHR_FUNC_EXIT;
}


int
dnx_data_meter_profile_feature_get(
    int unit,
    dnx_data_meter_profile_feature_e feature)
{
    return dnxc_data_mgmt_feature_data_get(unit, dnx_data_module_meter, dnx_data_meter_submodule_profile, feature);
}


uint32
dnx_data_meter_profile_large_bucket_mode_exp_add_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_meter, dnx_data_meter_submodule_profile, dnx_data_meter_profile_define_large_bucket_mode_exp_add);
}

uint32
dnx_data_meter_profile_max_regular_bucket_mode_burst_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_meter, dnx_data_meter_submodule_profile, dnx_data_meter_profile_define_max_regular_bucket_mode_burst);
}

uint32
dnx_data_meter_profile_rev_exp_min_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_meter, dnx_data_meter_submodule_profile, dnx_data_meter_profile_define_rev_exp_min);
}

uint32
dnx_data_meter_profile_rev_exp_max_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_meter, dnx_data_meter_submodule_profile, dnx_data_meter_profile_define_rev_exp_max);
}

uint32
dnx_data_meter_profile_burst_size_min_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_meter, dnx_data_meter_submodule_profile, dnx_data_meter_profile_define_burst_size_min);
}

uint32
dnx_data_meter_profile_nof_valid_global_meters_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_meter, dnx_data_meter_submodule_profile, dnx_data_meter_profile_define_nof_valid_global_meters);
}

uint32
dnx_data_meter_profile_nof_dp_command_max_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_meter, dnx_data_meter_submodule_profile, dnx_data_meter_profile_define_nof_dp_command_max);
}

uint32
dnx_data_meter_profile_global_engine_hw_stat_database_id_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_meter, dnx_data_meter_submodule_profile, dnx_data_meter_profile_define_global_engine_hw_stat_database_id);
}

uint32
dnx_data_meter_profile_ir_mant_nof_bits_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_meter, dnx_data_meter_submodule_profile, dnx_data_meter_profile_define_ir_mant_nof_bits);
}










static shr_error_e
dnx_data_meter_diag_init(
    int unit,
    dnxc_data_submodule_t *submodule_data)
{
    SHR_FUNC_INIT_VARS(unit);

    submodule_data->name = "diag";
    submodule_data->doc = "";
    
    submodule_data->nof_features = _dnx_data_meter_diag_feature_nof;
    DNXC_DATA_ALLOC(submodule_data->features, dnxc_data_feature_t,  submodule_data->nof_features, "_dnxc_data meter diag features");

    submodule_data->features[dnx_data_meter_diag_rate_measurements_support].name = "rate_measurements_support";
    submodule_data->features[dnx_data_meter_diag_rate_measurements_support].doc = "";
    submodule_data->features[dnx_data_meter_diag_rate_measurements_support].flags |= DNXC_DATA_F_FEATURE;

    
    submodule_data->nof_defines = _dnx_data_meter_diag_define_nof;
    DNXC_DATA_ALLOC(submodule_data->defines, dnxc_data_define_t, submodule_data->nof_defines, "_dnxc_data meter diag defines");

    
    submodule_data->nof_tables = _dnx_data_meter_diag_table_nof;
    DNXC_DATA_ALLOC(submodule_data->tables, dnxc_data_table_t, submodule_data->nof_tables, "_dnxc_data meter diag tables");


exit:
    SHR_FUNC_EXIT;
}


int
dnx_data_meter_diag_feature_get(
    int unit,
    dnx_data_meter_diag_feature_e feature)
{
    return dnxc_data_mgmt_feature_data_get(unit, dnx_data_module_meter, dnx_data_meter_submodule_diag, feature);
}











static shr_error_e
dnx_data_meter_meter_db_init(
    int unit,
    dnxc_data_submodule_t *submodule_data)
{
    SHR_FUNC_INIT_VARS(unit);

    submodule_data->name = "meter_db";
    submodule_data->doc = "";
    
    submodule_data->nof_features = _dnx_data_meter_meter_db_feature_nof;
    DNXC_DATA_ALLOC(submodule_data->features, dnxc_data_feature_t,  submodule_data->nof_features, "_dnxc_data meter meter_db features");

    submodule_data->features[dnx_data_meter_meter_db_refresh_disable_required].name = "refresh_disable_required";
    submodule_data->features[dnx_data_meter_meter_db_refresh_disable_required].doc = "";
    submodule_data->features[dnx_data_meter_meter_db_refresh_disable_required].flags |= DNXC_DATA_F_FEATURE;

    submodule_data->features[dnx_data_meter_meter_db_refresh_range_minus_one].name = "refresh_range_minus_one";
    submodule_data->features[dnx_data_meter_meter_db_refresh_range_minus_one].doc = "";
    submodule_data->features[dnx_data_meter_meter_db_refresh_range_minus_one].flags |= DNXC_DATA_F_FEATURE;

    submodule_data->features[dnx_data_meter_meter_db_tcsm_support].name = "tcsm_support";
    submodule_data->features[dnx_data_meter_meter_db_tcsm_support].doc = "";
    submodule_data->features[dnx_data_meter_meter_db_tcsm_support].flags |= DNXC_DATA_F_FEATURE;

    
    submodule_data->nof_defines = _dnx_data_meter_meter_db_define_nof;
    DNXC_DATA_ALLOC(submodule_data->defines, dnxc_data_define_t, submodule_data->nof_defines, "_dnxc_data meter meter_db defines");

    submodule_data->defines[dnx_data_meter_meter_db_define_nof_ingress_db].name = "nof_ingress_db";
    submodule_data->defines[dnx_data_meter_meter_db_define_nof_ingress_db].doc = "";
    
    submodule_data->defines[dnx_data_meter_meter_db_define_nof_ingress_db].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_meter_meter_db_define_nof_egress_db].name = "nof_egress_db";
    submodule_data->defines[dnx_data_meter_meter_db_define_nof_egress_db].doc = "";
    
    submodule_data->defines[dnx_data_meter_meter_db_define_nof_egress_db].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_meter_meter_db_define_meter_ids_in_group].name = "meter_ids_in_group";
    submodule_data->defines[dnx_data_meter_meter_db_define_meter_ids_in_group].doc = "";
    
    submodule_data->defines[dnx_data_meter_meter_db_define_meter_ids_in_group].flags |= DNXC_DATA_F_DEFINE;

    
    submodule_data->nof_tables = _dnx_data_meter_meter_db_table_nof;
    DNXC_DATA_ALLOC(submodule_data->tables, dnxc_data_table_t, submodule_data->nof_tables, "_dnxc_data meter meter_db tables");


exit:
    SHR_FUNC_EXIT;
}


int
dnx_data_meter_meter_db_feature_get(
    int unit,
    dnx_data_meter_meter_db_feature_e feature)
{
    return dnxc_data_mgmt_feature_data_get(unit, dnx_data_module_meter, dnx_data_meter_submodule_meter_db, feature);
}


uint32
dnx_data_meter_meter_db_nof_ingress_db_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_meter, dnx_data_meter_submodule_meter_db, dnx_data_meter_meter_db_define_nof_ingress_db);
}

uint32
dnx_data_meter_meter_db_nof_egress_db_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_meter, dnx_data_meter_submodule_meter_db, dnx_data_meter_meter_db_define_nof_egress_db);
}

uint32
dnx_data_meter_meter_db_meter_ids_in_group_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_meter, dnx_data_meter_submodule_meter_db, dnx_data_meter_meter_db_define_meter_ids_in_group);
}










static shr_error_e
dnx_data_meter_mem_mgmt_init(
    int unit,
    dnxc_data_submodule_t *submodule_data)
{
    SHR_FUNC_INIT_VARS(unit);

    submodule_data->name = "mem_mgmt";
    submodule_data->doc = "";
    
    submodule_data->nof_features = _dnx_data_meter_mem_mgmt_feature_nof;
    DNXC_DATA_ALLOC(submodule_data->features, dnxc_data_feature_t,  submodule_data->nof_features, "_dnxc_data meter mem_mgmt features");

    
    submodule_data->nof_defines = _dnx_data_meter_mem_mgmt_define_nof;
    DNXC_DATA_ALLOC(submodule_data->defines, dnxc_data_define_t, submodule_data->nof_defines, "_dnxc_data meter mem_mgmt defines");

    submodule_data->defines[dnx_data_meter_mem_mgmt_define_adrress_range_resolution].name = "adrress_range_resolution";
    submodule_data->defines[dnx_data_meter_mem_mgmt_define_adrress_range_resolution].doc = "";
    
    submodule_data->defines[dnx_data_meter_mem_mgmt_define_adrress_range_resolution].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_meter_mem_mgmt_define_object_stat_pointer_base_resolution].name = "object_stat_pointer_base_resolution";
    submodule_data->defines[dnx_data_meter_mem_mgmt_define_object_stat_pointer_base_resolution].doc = "";
    
    submodule_data->defines[dnx_data_meter_mem_mgmt_define_object_stat_pointer_base_resolution].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_meter_mem_mgmt_define_base_big_engine_for_meter].name = "base_big_engine_for_meter";
    submodule_data->defines[dnx_data_meter_mem_mgmt_define_base_big_engine_for_meter].doc = "";
    
    submodule_data->defines[dnx_data_meter_mem_mgmt_define_base_big_engine_for_meter].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_meter_mem_mgmt_define_ingress_single_bucket_engine].name = "ingress_single_bucket_engine";
    submodule_data->defines[dnx_data_meter_mem_mgmt_define_ingress_single_bucket_engine].doc = "";
    
    submodule_data->defines[dnx_data_meter_mem_mgmt_define_ingress_single_bucket_engine].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_meter_mem_mgmt_define_egress_single_bucket_engine].name = "egress_single_bucket_engine";
    submodule_data->defines[dnx_data_meter_mem_mgmt_define_egress_single_bucket_engine].doc = "";
    
    submodule_data->defines[dnx_data_meter_mem_mgmt_define_egress_single_bucket_engine].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_meter_mem_mgmt_define_meter_pointer_size].name = "meter_pointer_size";
    submodule_data->defines[dnx_data_meter_mem_mgmt_define_meter_pointer_size].doc = "";
    
    submodule_data->defines[dnx_data_meter_mem_mgmt_define_meter_pointer_size].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_meter_mem_mgmt_define_meter_pointer_map_size].name = "meter_pointer_map_size";
    submodule_data->defines[dnx_data_meter_mem_mgmt_define_meter_pointer_map_size].doc = "";
    
    submodule_data->defines[dnx_data_meter_mem_mgmt_define_meter_pointer_map_size].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_meter_mem_mgmt_define_invalid_bank_id].name = "invalid_bank_id";
    submodule_data->defines[dnx_data_meter_mem_mgmt_define_invalid_bank_id].doc = "";
    
    submodule_data->defines[dnx_data_meter_mem_mgmt_define_invalid_bank_id].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_meter_mem_mgmt_define_ptr_map_table_resolution].name = "ptr_map_table_resolution";
    submodule_data->defines[dnx_data_meter_mem_mgmt_define_ptr_map_table_resolution].doc = "";
    
    submodule_data->defines[dnx_data_meter_mem_mgmt_define_ptr_map_table_resolution].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_meter_mem_mgmt_define_bank_id_size].name = "bank_id_size";
    submodule_data->defines[dnx_data_meter_mem_mgmt_define_bank_id_size].doc = "";
    
    submodule_data->defines[dnx_data_meter_mem_mgmt_define_bank_id_size].flags |= DNXC_DATA_F_NUMERIC;

    submodule_data->defines[dnx_data_meter_mem_mgmt_define_nof_bank_ids].name = "nof_bank_ids";
    submodule_data->defines[dnx_data_meter_mem_mgmt_define_nof_bank_ids].doc = "";
    
    submodule_data->defines[dnx_data_meter_mem_mgmt_define_nof_bank_ids].flags |= DNXC_DATA_F_NUMERIC;

    submodule_data->defines[dnx_data_meter_mem_mgmt_define_sections_offset].name = "sections_offset";
    submodule_data->defines[dnx_data_meter_mem_mgmt_define_sections_offset].doc = "";
    
    submodule_data->defines[dnx_data_meter_mem_mgmt_define_sections_offset].flags |= DNXC_DATA_F_NUMERIC;

    submodule_data->defines[dnx_data_meter_mem_mgmt_define_nof_banks_in_big_engine].name = "nof_banks_in_big_engine";
    submodule_data->defines[dnx_data_meter_mem_mgmt_define_nof_banks_in_big_engine].doc = "";
    
    submodule_data->defines[dnx_data_meter_mem_mgmt_define_nof_banks_in_big_engine].flags |= DNXC_DATA_F_NUMERIC;

    submodule_data->defines[dnx_data_meter_mem_mgmt_define_nof_single_buckets_per_entry].name = "nof_single_buckets_per_entry";
    submodule_data->defines[dnx_data_meter_mem_mgmt_define_nof_single_buckets_per_entry].doc = "";
    
    submodule_data->defines[dnx_data_meter_mem_mgmt_define_nof_single_buckets_per_entry].flags |= DNXC_DATA_F_NUMERIC;

    submodule_data->defines[dnx_data_meter_mem_mgmt_define_nof_dual_buckets_per_entry].name = "nof_dual_buckets_per_entry";
    submodule_data->defines[dnx_data_meter_mem_mgmt_define_nof_dual_buckets_per_entry].doc = "";
    
    submodule_data->defines[dnx_data_meter_mem_mgmt_define_nof_dual_buckets_per_entry].flags |= DNXC_DATA_F_NUMERIC;

    submodule_data->defines[dnx_data_meter_mem_mgmt_define_bucket_size_nof_bits].name = "bucket_size_nof_bits";
    submodule_data->defines[dnx_data_meter_mem_mgmt_define_bucket_size_nof_bits].doc = "";
    
    submodule_data->defines[dnx_data_meter_mem_mgmt_define_bucket_size_nof_bits].flags |= DNXC_DATA_F_NUMERIC;

    
    submodule_data->nof_tables = _dnx_data_meter_mem_mgmt_table_nof;
    DNXC_DATA_ALLOC(submodule_data->tables, dnxc_data_table_t, submodule_data->nof_tables, "_dnxc_data meter mem_mgmt tables");


exit:
    SHR_FUNC_EXIT;
}


int
dnx_data_meter_mem_mgmt_feature_get(
    int unit,
    dnx_data_meter_mem_mgmt_feature_e feature)
{
    return dnxc_data_mgmt_feature_data_get(unit, dnx_data_module_meter, dnx_data_meter_submodule_mem_mgmt, feature);
}


uint32
dnx_data_meter_mem_mgmt_adrress_range_resolution_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_meter, dnx_data_meter_submodule_mem_mgmt, dnx_data_meter_mem_mgmt_define_adrress_range_resolution);
}

uint32
dnx_data_meter_mem_mgmt_object_stat_pointer_base_resolution_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_meter, dnx_data_meter_submodule_mem_mgmt, dnx_data_meter_mem_mgmt_define_object_stat_pointer_base_resolution);
}

uint32
dnx_data_meter_mem_mgmt_base_big_engine_for_meter_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_meter, dnx_data_meter_submodule_mem_mgmt, dnx_data_meter_mem_mgmt_define_base_big_engine_for_meter);
}

uint32
dnx_data_meter_mem_mgmt_ingress_single_bucket_engine_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_meter, dnx_data_meter_submodule_mem_mgmt, dnx_data_meter_mem_mgmt_define_ingress_single_bucket_engine);
}

uint32
dnx_data_meter_mem_mgmt_egress_single_bucket_engine_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_meter, dnx_data_meter_submodule_mem_mgmt, dnx_data_meter_mem_mgmt_define_egress_single_bucket_engine);
}

uint32
dnx_data_meter_mem_mgmt_meter_pointer_size_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_meter, dnx_data_meter_submodule_mem_mgmt, dnx_data_meter_mem_mgmt_define_meter_pointer_size);
}

uint32
dnx_data_meter_mem_mgmt_meter_pointer_map_size_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_meter, dnx_data_meter_submodule_mem_mgmt, dnx_data_meter_mem_mgmt_define_meter_pointer_map_size);
}

uint32
dnx_data_meter_mem_mgmt_invalid_bank_id_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_meter, dnx_data_meter_submodule_mem_mgmt, dnx_data_meter_mem_mgmt_define_invalid_bank_id);
}

uint32
dnx_data_meter_mem_mgmt_ptr_map_table_resolution_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_meter, dnx_data_meter_submodule_mem_mgmt, dnx_data_meter_mem_mgmt_define_ptr_map_table_resolution);
}

uint32
dnx_data_meter_mem_mgmt_bank_id_size_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_meter, dnx_data_meter_submodule_mem_mgmt, dnx_data_meter_mem_mgmt_define_bank_id_size);
}

uint32
dnx_data_meter_mem_mgmt_nof_bank_ids_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_meter, dnx_data_meter_submodule_mem_mgmt, dnx_data_meter_mem_mgmt_define_nof_bank_ids);
}

uint32
dnx_data_meter_mem_mgmt_sections_offset_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_meter, dnx_data_meter_submodule_mem_mgmt, dnx_data_meter_mem_mgmt_define_sections_offset);
}

uint32
dnx_data_meter_mem_mgmt_nof_banks_in_big_engine_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_meter, dnx_data_meter_submodule_mem_mgmt, dnx_data_meter_mem_mgmt_define_nof_banks_in_big_engine);
}

uint32
dnx_data_meter_mem_mgmt_nof_single_buckets_per_entry_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_meter, dnx_data_meter_submodule_mem_mgmt, dnx_data_meter_mem_mgmt_define_nof_single_buckets_per_entry);
}

uint32
dnx_data_meter_mem_mgmt_nof_dual_buckets_per_entry_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_meter, dnx_data_meter_submodule_mem_mgmt, dnx_data_meter_mem_mgmt_define_nof_dual_buckets_per_entry);
}

uint32
dnx_data_meter_mem_mgmt_bucket_size_nof_bits_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_meter, dnx_data_meter_submodule_mem_mgmt, dnx_data_meter_mem_mgmt_define_bucket_size_nof_bits);
}










static shr_error_e
dnx_data_meter_compensation_init(
    int unit,
    dnxc_data_submodule_t *submodule_data)
{
    SHR_FUNC_INIT_VARS(unit);

    submodule_data->name = "compensation";
    submodule_data->doc = "";
    
    submodule_data->nof_features = _dnx_data_meter_compensation_feature_nof;
    DNXC_DATA_ALLOC(submodule_data->features, dnxc_data_feature_t,  submodule_data->nof_features, "_dnxc_data meter compensation features");

    
    submodule_data->nof_defines = _dnx_data_meter_compensation_define_nof;
    DNXC_DATA_ALLOC(submodule_data->defines, dnxc_data_define_t, submodule_data->nof_defines, "_dnxc_data meter compensation defines");

    
    submodule_data->nof_tables = _dnx_data_meter_compensation_table_nof;
    DNXC_DATA_ALLOC(submodule_data->tables, dnxc_data_table_t, submodule_data->nof_tables, "_dnxc_data meter compensation tables");

    
    submodule_data->tables[dnx_data_meter_compensation_table_ingress_port_delta_value].name = "ingress_port_delta_value";
    submodule_data->tables[dnx_data_meter_compensation_table_ingress_port_delta_value].doc = "";
    submodule_data->tables[dnx_data_meter_compensation_table_ingress_port_delta_value].flags |= DNXC_DATA_F_TABLE;
    submodule_data->tables[dnx_data_meter_compensation_table_ingress_port_delta_value].size_of_values = sizeof(dnx_data_meter_compensation_ingress_port_delta_value_t);
    submodule_data->tables[dnx_data_meter_compensation_table_ingress_port_delta_value].entry_get = dnx_data_meter_compensation_ingress_port_delta_value_entry_str_get;

    
    submodule_data->tables[dnx_data_meter_compensation_table_ingress_port_delta_value].nof_keys = 0;

    
    submodule_data->tables[dnx_data_meter_compensation_table_ingress_port_delta_value].nof_values = 2;
    DNXC_DATA_ALLOC(submodule_data->tables[dnx_data_meter_compensation_table_ingress_port_delta_value].values, dnxc_data_value_t, submodule_data->tables[dnx_data_meter_compensation_table_ingress_port_delta_value].nof_values, "_dnx_data_meter_compensation_table_ingress_port_delta_value table values");
    submodule_data->tables[dnx_data_meter_compensation_table_ingress_port_delta_value].values[0].name = "min";
    submodule_data->tables[dnx_data_meter_compensation_table_ingress_port_delta_value].values[0].type = "int";
    submodule_data->tables[dnx_data_meter_compensation_table_ingress_port_delta_value].values[0].doc = "";
    submodule_data->tables[dnx_data_meter_compensation_table_ingress_port_delta_value].values[0].offset = UTILEX_OFFSETOF(dnx_data_meter_compensation_ingress_port_delta_value_t, min);
    submodule_data->tables[dnx_data_meter_compensation_table_ingress_port_delta_value].values[1].name = "max";
    submodule_data->tables[dnx_data_meter_compensation_table_ingress_port_delta_value].values[1].type = "int";
    submodule_data->tables[dnx_data_meter_compensation_table_ingress_port_delta_value].values[1].doc = "";
    submodule_data->tables[dnx_data_meter_compensation_table_ingress_port_delta_value].values[1].offset = UTILEX_OFFSETOF(dnx_data_meter_compensation_ingress_port_delta_value_t, max);


exit:
    SHR_FUNC_EXIT;
}


int
dnx_data_meter_compensation_feature_get(
    int unit,
    dnx_data_meter_compensation_feature_e feature)
{
    return dnxc_data_mgmt_feature_data_get(unit, dnx_data_module_meter, dnx_data_meter_submodule_compensation, feature);
}




const dnx_data_meter_compensation_ingress_port_delta_value_t *
dnx_data_meter_compensation_ingress_port_delta_value_get(
    int unit)
{
    char *data;
    dnxc_data_table_t *table;

    
    table = dnxc_data_mgmt_table_get(unit, dnx_data_module_meter, dnx_data_meter_submodule_compensation, dnx_data_meter_compensation_table_ingress_port_delta_value);
    
    data = dnxc_data_mgmt_table_data_get(unit, table, 0, 0);
    return (const dnx_data_meter_compensation_ingress_port_delta_value_t *) data;

}


shr_error_e
dnx_data_meter_compensation_ingress_port_delta_value_entry_str_get(
    int unit,
    char *buffer,
    int key0,
    int key1,
    int value_index)
{
    dnxc_data_table_t *table;
    const dnx_data_meter_compensation_ingress_port_delta_value_t *data;
    SHR_FUNC_INIT_VARS(unit);

    
    table = dnxc_data_mgmt_table_get(unit, dnx_data_module_meter, dnx_data_meter_submodule_compensation, dnx_data_meter_compensation_table_ingress_port_delta_value);
    data = (const dnx_data_meter_compensation_ingress_port_delta_value_t *) dnxc_data_mgmt_table_data_diag_get(unit, table, 0, 0);
    switch (value_index)
    {
        case 0:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->min);
            break;
        case 1:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->max);
            break;
    }

    SHR_FUNC_EXIT;
}


const dnxc_data_table_info_t *
dnx_data_meter_compensation_ingress_port_delta_value_info_get(
    int unit)
{

    
    return dnxc_data_mgmt_table_info_get(unit, dnx_data_module_meter, dnx_data_meter_submodule_compensation, dnx_data_meter_compensation_table_ingress_port_delta_value);

}






static shr_error_e
dnx_data_meter_expansion_init(
    int unit,
    dnxc_data_submodule_t *submodule_data)
{
    SHR_FUNC_INIT_VARS(unit);

    submodule_data->name = "expansion";
    submodule_data->doc = "";
    
    submodule_data->nof_features = _dnx_data_meter_expansion_feature_nof;
    DNXC_DATA_ALLOC(submodule_data->features, dnxc_data_feature_t,  submodule_data->nof_features, "_dnxc_data meter expansion features");

    submodule_data->features[dnx_data_meter_expansion_expansion_based_on_tc_support].name = "expansion_based_on_tc_support";
    submodule_data->features[dnx_data_meter_expansion_expansion_based_on_tc_support].doc = "";
    submodule_data->features[dnx_data_meter_expansion_expansion_based_on_tc_support].flags |= DNXC_DATA_F_FEATURE;

    submodule_data->features[dnx_data_meter_expansion_expansion_for_uuc_umc_support].name = "expansion_for_uuc_umc_support";
    submodule_data->features[dnx_data_meter_expansion_expansion_for_uuc_umc_support].doc = "";
    submodule_data->features[dnx_data_meter_expansion_expansion_for_uuc_umc_support].flags |= DNXC_DATA_F_FEATURE;

    
    submodule_data->nof_defines = _dnx_data_meter_expansion_define_nof;
    DNXC_DATA_ALLOC(submodule_data->defines, dnxc_data_define_t, submodule_data->nof_defines, "_dnxc_data meter expansion defines");

    submodule_data->defines[dnx_data_meter_expansion_define_max_size].name = "max_size";
    submodule_data->defines[dnx_data_meter_expansion_define_max_size].doc = "";
    
    submodule_data->defines[dnx_data_meter_expansion_define_max_size].flags |= DNXC_DATA_F_DEFINE;

    
    submodule_data->nof_tables = _dnx_data_meter_expansion_table_nof;
    DNXC_DATA_ALLOC(submodule_data->tables, dnxc_data_table_t, submodule_data->nof_tables, "_dnxc_data meter expansion tables");


exit:
    SHR_FUNC_EXIT;
}


int
dnx_data_meter_expansion_feature_get(
    int unit,
    dnx_data_meter_expansion_feature_e feature)
{
    return dnxc_data_mgmt_feature_data_get(unit, dnx_data_module_meter, dnx_data_meter_submodule_expansion, feature);
}


uint32
dnx_data_meter_expansion_max_size_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_meter, dnx_data_meter_submodule_expansion, dnx_data_meter_expansion_define_max_size);
}







shr_error_e
dnx_data_meter_init(
    int unit,
    dnxc_data_module_t *module_data)
{
    SHR_FUNC_INIT_VARS(unit);

    
    module_data->name = "meter";
    module_data->nof_submodules = _dnx_data_meter_submodule_nof;
    DNXC_DATA_ALLOC(module_data->submodules, dnxc_data_submodule_t, module_data->nof_submodules, "_dnxc_data meter submodules");

    
    SHR_IF_ERR_EXIT(dnx_data_meter_general_init(unit, &module_data->submodules[dnx_data_meter_submodule_general]));
    SHR_IF_ERR_EXIT(dnx_data_meter_profile_init(unit, &module_data->submodules[dnx_data_meter_submodule_profile]));
    SHR_IF_ERR_EXIT(dnx_data_meter_diag_init(unit, &module_data->submodules[dnx_data_meter_submodule_diag]));
    SHR_IF_ERR_EXIT(dnx_data_meter_meter_db_init(unit, &module_data->submodules[dnx_data_meter_submodule_meter_db]));
    SHR_IF_ERR_EXIT(dnx_data_meter_mem_mgmt_init(unit, &module_data->submodules[dnx_data_meter_submodule_mem_mgmt]));
    SHR_IF_ERR_EXIT(dnx_data_meter_compensation_init(unit, &module_data->submodules[dnx_data_meter_submodule_compensation]));
    SHR_IF_ERR_EXIT(dnx_data_meter_expansion_init(unit, &module_data->submodules[dnx_data_meter_submodule_expansion]));
    

    if (dnxc_data_mgmt_is_jr2_a0(unit))
    {
        SHR_IF_ERR_EXIT(jr2_a0_data_meter_attach(unit));
    }
    else


    if (dnxc_data_mgmt_is_jr2_b0(unit))
    {
        SHR_IF_ERR_EXIT(jr2_a0_data_meter_attach(unit));
        SHR_IF_ERR_EXIT(jr2_b0_data_meter_attach(unit));
    }
    else


    if (dnxc_data_mgmt_is_jr2_b1(unit))
    {
        SHR_IF_ERR_EXIT(jr2_a0_data_meter_attach(unit));
        SHR_IF_ERR_EXIT(jr2_b0_data_meter_attach(unit));
    }
    else


    if (dnxc_data_mgmt_is_j2c_a0(unit))
    {
        SHR_IF_ERR_EXIT(jr2_a0_data_meter_attach(unit));
        SHR_IF_ERR_EXIT(j2c_a0_data_meter_attach(unit));
    }
    else


    if (dnxc_data_mgmt_is_j2c_a1(unit))
    {
        SHR_IF_ERR_EXIT(jr2_a0_data_meter_attach(unit));
        SHR_IF_ERR_EXIT(j2c_a0_data_meter_attach(unit));
    }
    else


    if (dnxc_data_mgmt_is_q2a_a0(unit))
    {
        SHR_IF_ERR_EXIT(jr2_a0_data_meter_attach(unit));
        SHR_IF_ERR_EXIT(q2a_a0_data_meter_attach(unit));
    }
    else


    if (dnxc_data_mgmt_is_q2a_b0(unit))
    {
        SHR_IF_ERR_EXIT(jr2_a0_data_meter_attach(unit));
        SHR_IF_ERR_EXIT(q2a_a0_data_meter_attach(unit));
    }
    else


    if (dnxc_data_mgmt_is_q2a_b1(unit))
    {
        SHR_IF_ERR_EXIT(jr2_a0_data_meter_attach(unit));
        SHR_IF_ERR_EXIT(q2a_a0_data_meter_attach(unit));
    }
    else


    if (dnxc_data_mgmt_is_j2p_a0(unit))
    {
        SHR_IF_ERR_EXIT(jr2_a0_data_meter_attach(unit));
        SHR_IF_ERR_EXIT(j2p_a0_data_meter_attach(unit));
    }
    else


    if (dnxc_data_mgmt_is_j2p_a1(unit))
    {
        SHR_IF_ERR_EXIT(jr2_a0_data_meter_attach(unit));
        SHR_IF_ERR_EXIT(j2p_a0_data_meter_attach(unit));
    }
    else


    if (dnxc_data_mgmt_is_j2p_a2(unit))
    {
        SHR_IF_ERR_EXIT(jr2_a0_data_meter_attach(unit));
        SHR_IF_ERR_EXIT(j2p_a0_data_meter_attach(unit));
    }
    else


    if (dnxc_data_mgmt_is_j2x_a0(unit))
    {
        SHR_IF_ERR_EXIT(jr2_a0_data_meter_attach(unit));
        SHR_IF_ERR_EXIT(j2x_a0_data_meter_attach(unit));
    }
    else

    {
        SHR_EXIT();
    }

exit:
    SHR_FUNC_EXIT;
}
#undef BSL_LOG_MODULE

