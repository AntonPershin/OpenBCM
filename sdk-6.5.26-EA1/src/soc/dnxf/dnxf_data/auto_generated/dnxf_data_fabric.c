
/* *INDENT-OFF* */
/*
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2022 Broadcom Inc. All rights reserved.
 */
#ifdef BSL_LOG_MODULE
#error "BSL_LOG_MODULE redefined"
#endif
#define BSL_LOG_MODULE BSL_LS_BCMDNX_FABRIC

#include <soc/dnxf/dnxf_data/auto_generated/dnxf_data_internal_fabric.h>



#ifdef BCM_DNXF1_SUPPORT

extern shr_error_e ramon_a0_data_fabric_attach(
    int unit);

#endif 



static shr_error_e
dnxf_data_fabric_general_init(
    int unit,
    dnxc_data_submodule_t *submodule_data)
{
    SHR_FUNC_INIT_VARS(unit);

    submodule_data->name = "general";
    submodule_data->doc = "General fabric attributes";
    
    submodule_data->nof_features = _dnxf_data_fabric_general_feature_nof;
    DNXC_DATA_ALLOC(submodule_data->features, dnxc_data_feature_t,  submodule_data->nof_features, "_dnxc_data fabric general features");

    submodule_data->features[dnxf_data_fabric_general_is_multi_stage_supported].name = "is_multi_stage_supported";
    submodule_data->features[dnxf_data_fabric_general_is_multi_stage_supported].doc = "Indicates if device can operate in any of the multistage modes";
    submodule_data->features[dnxf_data_fabric_general_is_multi_stage_supported].flags |= DNXC_DATA_F_FEATURE;

    submodule_data->features[dnxf_data_fabric_general_is_symb_errors_per_frame_supported].name = "is_symb_errors_per_frame_supported";
    submodule_data->features[dnxf_data_fabric_general_is_symb_errors_per_frame_supported].doc = "Is the fabric supporting count water mark of number of symbol errors per frame";
    submodule_data->features[dnxf_data_fabric_general_is_symb_errors_per_frame_supported].flags |= DNXC_DATA_F_FEATURE;

    submodule_data->features[dnxf_data_fabric_general_is_nrz_supported].name = "is_nrz_supported";
    submodule_data->features[dnxf_data_fabric_general_is_nrz_supported].doc = "Is NRZ modulation supported";
    submodule_data->features[dnxf_data_fabric_general_is_nrz_supported].flags |= DNXC_DATA_F_FEATURE;

    
    submodule_data->nof_defines = _dnxf_data_fabric_general_define_nof;
    DNXC_DATA_ALLOC(submodule_data->defines, dnxc_data_define_t, submodule_data->nof_defines, "_dnxc_data fabric general defines");

    submodule_data->defines[dnxf_data_fabric_general_define_max_nof_pipes].name = "max_nof_pipes";
    submodule_data->defines[dnxf_data_fabric_general_define_max_nof_pipes].doc = "The maximum number of pipes that the device supports.";
    
    submodule_data->defines[dnxf_data_fabric_general_define_max_nof_pipes].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnxf_data_fabric_general_define_device_mode].name = "device_mode";
    submodule_data->defines[dnxf_data_fabric_general_define_device_mode].doc = "Sets the device operational mode.";
    
    submodule_data->defines[dnxf_data_fabric_general_define_device_mode].flags |= DNXC_DATA_F_NUMERIC;

    submodule_data->defines[dnxf_data_fabric_general_define_local_routing_enable_uc].name = "local_routing_enable_uc";
    submodule_data->defines[dnxf_data_fabric_general_define_local_routing_enable_uc].doc = "Enables unicast local routing from FE1 to FE3.";
    
    submodule_data->defines[dnxf_data_fabric_general_define_local_routing_enable_uc].flags |= DNXC_DATA_F_NUMERIC;

    submodule_data->defines[dnxf_data_fabric_general_define_local_routing_enable_mc].name = "local_routing_enable_mc";
    submodule_data->defines[dnxf_data_fabric_general_define_local_routing_enable_mc].doc = "Enables multicast local routing from FE1 to FE3.";
    
    submodule_data->defines[dnxf_data_fabric_general_define_local_routing_enable_mc].flags |= DNXC_DATA_F_NUMERIC;

    
    submodule_data->nof_tables = _dnxf_data_fabric_general_table_nof;
    DNXC_DATA_ALLOC(submodule_data->tables, dnxc_data_table_t, submodule_data->nof_tables, "_dnxc_data fabric general tables");


exit:
    SHR_FUNC_EXIT;
}


int
dnxf_data_fabric_general_feature_get(
    int unit,
    dnxf_data_fabric_general_feature_e feature)
{
    return dnxc_data_mgmt_feature_data_get(unit, dnxf_data_module_fabric, dnxf_data_fabric_submodule_general, feature);
}


uint32
dnxf_data_fabric_general_max_nof_pipes_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnxf_data_module_fabric, dnxf_data_fabric_submodule_general, dnxf_data_fabric_general_define_max_nof_pipes);
}

uint32
dnxf_data_fabric_general_device_mode_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnxf_data_module_fabric, dnxf_data_fabric_submodule_general, dnxf_data_fabric_general_define_device_mode);
}

uint32
dnxf_data_fabric_general_local_routing_enable_uc_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnxf_data_module_fabric, dnxf_data_fabric_submodule_general, dnxf_data_fabric_general_define_local_routing_enable_uc);
}

uint32
dnxf_data_fabric_general_local_routing_enable_mc_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnxf_data_module_fabric, dnxf_data_fabric_submodule_general, dnxf_data_fabric_general_define_local_routing_enable_mc);
}










static shr_error_e
dnxf_data_fabric_pipes_init(
    int unit,
    dnxc_data_submodule_t *submodule_data)
{
    SHR_FUNC_INIT_VARS(unit);

    submodule_data->name = "pipes";
    submodule_data->doc = "General pipes attributes";
    
    submodule_data->nof_features = _dnxf_data_fabric_pipes_feature_nof;
    DNXC_DATA_ALLOC(submodule_data->features, dnxc_data_feature_t,  submodule_data->nof_features, "_dnxc_data fabric pipes features");

    submodule_data->features[dnxf_data_fabric_pipes_local_route_pipe_supported].name = "local_route_pipe_supported";
    submodule_data->features[dnxf_data_fabric_pipes_local_route_pipe_supported].doc = "Indicate the device supports Local-Route using a dedicated pipe for Unicast cells";
    submodule_data->features[dnxf_data_fabric_pipes_local_route_pipe_supported].flags |= DNXC_DATA_F_FEATURE;

    
    submodule_data->nof_defines = _dnxf_data_fabric_pipes_define_nof;
    DNXC_DATA_ALLOC(submodule_data->defines, dnxc_data_define_t, submodule_data->nof_defines, "_dnxc_data fabric pipes defines");

    submodule_data->defines[dnxf_data_fabric_pipes_define_max_nof_pipes].name = "max_nof_pipes";
    submodule_data->defines[dnxf_data_fabric_pipes_define_max_nof_pipes].doc = "Max number of pipes supported by the device";
    
    submodule_data->defines[dnxf_data_fabric_pipes_define_max_nof_pipes].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnxf_data_fabric_pipes_define_local_route_pipe_index].name = "local_route_pipe_index";
    submodule_data->defines[dnxf_data_fabric_pipes_define_local_route_pipe_index].doc = "The pipe index used for Local Route unicast cells";
    
    submodule_data->defines[dnxf_data_fabric_pipes_define_local_route_pipe_index].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnxf_data_fabric_pipes_define_nof_pipes].name = "nof_pipes";
    submodule_data->defines[dnxf_data_fabric_pipes_define_nof_pipes].doc = "Configure number of fabric pipes.";
    
    submodule_data->defines[dnxf_data_fabric_pipes_define_nof_pipes].flags |= DNXC_DATA_F_NUMERIC;

    submodule_data->defines[dnxf_data_fabric_pipes_define_system_contains_multiple_pipe_device].name = "system_contains_multiple_pipe_device";
    submodule_data->defines[dnxf_data_fabric_pipes_define_system_contains_multiple_pipe_device].doc = "Determines if there is a multiple pipe device in the system";
    
    submodule_data->defines[dnxf_data_fabric_pipes_define_system_contains_multiple_pipe_device].flags |= DNXC_DATA_F_NUMERIC;

    submodule_data->defines[dnxf_data_fabric_pipes_define_system_tdm_priority].name = "system_tdm_priority";
    submodule_data->defines[dnxf_data_fabric_pipes_define_system_tdm_priority].doc = "Mark a CGM fabric priority as TDM";
    
    submodule_data->defines[dnxf_data_fabric_pipes_define_system_tdm_priority].flags |= DNXC_DATA_F_NUMERIC;

    
    submodule_data->nof_tables = _dnxf_data_fabric_pipes_table_nof;
    DNXC_DATA_ALLOC(submodule_data->tables, dnxc_data_table_t, submodule_data->nof_tables, "_dnxc_data fabric pipes tables");

    
    submodule_data->tables[dnxf_data_fabric_pipes_table_map].name = "map";
    submodule_data->tables[dnxf_data_fabric_pipes_table_map].doc = "map traffic cast X priority to fabric pipe";
    submodule_data->tables[dnxf_data_fabric_pipes_table_map].flags |= DNXC_DATA_F_TABLE;
    submodule_data->tables[dnxf_data_fabric_pipes_table_map].size_of_values = sizeof(dnxf_data_fabric_pipes_map_t);
    submodule_data->tables[dnxf_data_fabric_pipes_table_map].entry_get = dnxf_data_fabric_pipes_map_entry_str_get;

    
    submodule_data->tables[dnxf_data_fabric_pipes_table_map].nof_keys = 0;

    
    submodule_data->tables[dnxf_data_fabric_pipes_table_map].nof_values = 6;
    DNXC_DATA_ALLOC(submodule_data->tables[dnxf_data_fabric_pipes_table_map].values, dnxc_data_value_t, submodule_data->tables[dnxf_data_fabric_pipes_table_map].nof_values, "_dnxf_data_fabric_pipes_table_map table values");
    submodule_data->tables[dnxf_data_fabric_pipes_table_map].values[0].name = "uc";
    submodule_data->tables[dnxf_data_fabric_pipes_table_map].values[0].type = "uint32[DNXF_DATA_MAX_FABRIC_CONGESTION_NOF_THRESHOLD_PRIORITIES]";
    submodule_data->tables[dnxf_data_fabric_pipes_table_map].values[0].doc = "each element represents uc priority pipe";
    submodule_data->tables[dnxf_data_fabric_pipes_table_map].values[0].offset = UTILEX_OFFSETOF(dnxf_data_fabric_pipes_map_t, uc);
    submodule_data->tables[dnxf_data_fabric_pipes_table_map].values[1].name = "mc";
    submodule_data->tables[dnxf_data_fabric_pipes_table_map].values[1].type = "uint32[DNXF_DATA_MAX_FABRIC_CONGESTION_NOF_THRESHOLD_PRIORITIES]";
    submodule_data->tables[dnxf_data_fabric_pipes_table_map].values[1].doc = "each element represents mc priority pipe";
    submodule_data->tables[dnxf_data_fabric_pipes_table_map].values[1].offset = UTILEX_OFFSETOF(dnxf_data_fabric_pipes_map_t, mc);
    submodule_data->tables[dnxf_data_fabric_pipes_table_map].values[2].name = "lr_uc_pipe";
    submodule_data->tables[dnxf_data_fabric_pipes_table_map].values[2].type = "int";
    submodule_data->tables[dnxf_data_fabric_pipes_table_map].values[2].doc = "The pipe index to use for Unicast Local-Route cells";
    submodule_data->tables[dnxf_data_fabric_pipes_table_map].values[2].offset = UTILEX_OFFSETOF(dnxf_data_fabric_pipes_map_t, lr_uc_pipe);
    submodule_data->tables[dnxf_data_fabric_pipes_table_map].values[3].name = "name";
    submodule_data->tables[dnxf_data_fabric_pipes_table_map].values[3].type = "char *";
    submodule_data->tables[dnxf_data_fabric_pipes_table_map].values[3].doc = "The configuration display name";
    submodule_data->tables[dnxf_data_fabric_pipes_table_map].values[3].offset = UTILEX_OFFSETOF(dnxf_data_fabric_pipes_map_t, name);
    submodule_data->tables[dnxf_data_fabric_pipes_table_map].values[4].name = "type";
    submodule_data->tables[dnxf_data_fabric_pipes_table_map].values[4].type = "soc_dnxc_fabric_pipe_map_type_t";
    submodule_data->tables[dnxf_data_fabric_pipes_table_map].values[4].doc = "The pipe mapping type";
    submodule_data->tables[dnxf_data_fabric_pipes_table_map].values[4].offset = UTILEX_OFFSETOF(dnxf_data_fabric_pipes_map_t, type);
    submodule_data->tables[dnxf_data_fabric_pipes_table_map].values[5].name = "min_hp_mc";
    submodule_data->tables[dnxf_data_fabric_pipes_table_map].values[5].type = "int";
    submodule_data->tables[dnxf_data_fabric_pipes_table_map].values[5].doc = "Minimum priority to be considered as high priority multicast";
    submodule_data->tables[dnxf_data_fabric_pipes_table_map].values[5].offset = UTILEX_OFFSETOF(dnxf_data_fabric_pipes_map_t, min_hp_mc);

    
    submodule_data->tables[dnxf_data_fabric_pipes_table_valid_map_config].name = "valid_map_config";
    submodule_data->tables[dnxf_data_fabric_pipes_table_valid_map_config].doc = "pipes map valid configurations";
    submodule_data->tables[dnxf_data_fabric_pipes_table_valid_map_config].flags |= DNXC_DATA_F_TABLE;
    submodule_data->tables[dnxf_data_fabric_pipes_table_valid_map_config].size_of_values = sizeof(dnxf_data_fabric_pipes_valid_map_config_t);
    submodule_data->tables[dnxf_data_fabric_pipes_table_valid_map_config].entry_get = dnxf_data_fabric_pipes_valid_map_config_entry_str_get;

    
    submodule_data->tables[dnxf_data_fabric_pipes_table_valid_map_config].nof_keys = 1;
    submodule_data->tables[dnxf_data_fabric_pipes_table_valid_map_config].keys[0].name = "mapping_option_idx";
    submodule_data->tables[dnxf_data_fabric_pipes_table_valid_map_config].keys[0].doc = "The configuration running number";

    
    submodule_data->tables[dnxf_data_fabric_pipes_table_valid_map_config].nof_values = 7;
    DNXC_DATA_ALLOC(submodule_data->tables[dnxf_data_fabric_pipes_table_valid_map_config].values, dnxc_data_value_t, submodule_data->tables[dnxf_data_fabric_pipes_table_valid_map_config].nof_values, "_dnxf_data_fabric_pipes_table_valid_map_config table values");
    submodule_data->tables[dnxf_data_fabric_pipes_table_valid_map_config].values[0].name = "nof_pipes";
    submodule_data->tables[dnxf_data_fabric_pipes_table_valid_map_config].values[0].type = "uint32";
    submodule_data->tables[dnxf_data_fabric_pipes_table_valid_map_config].values[0].doc = "Number of pipes";
    submodule_data->tables[dnxf_data_fabric_pipes_table_valid_map_config].values[0].offset = UTILEX_OFFSETOF(dnxf_data_fabric_pipes_valid_map_config_t, nof_pipes);
    submodule_data->tables[dnxf_data_fabric_pipes_table_valid_map_config].values[1].name = "uc";
    submodule_data->tables[dnxf_data_fabric_pipes_table_valid_map_config].values[1].type = "uint32[DNXF_DATA_MAX_FABRIC_CONGESTION_NOF_THRESHOLD_PRIORITIES]";
    submodule_data->tables[dnxf_data_fabric_pipes_table_valid_map_config].values[1].doc = "map unicast cell priority to pipe";
    submodule_data->tables[dnxf_data_fabric_pipes_table_valid_map_config].values[1].offset = UTILEX_OFFSETOF(dnxf_data_fabric_pipes_valid_map_config_t, uc);
    submodule_data->tables[dnxf_data_fabric_pipes_table_valid_map_config].values[2].name = "mc";
    submodule_data->tables[dnxf_data_fabric_pipes_table_valid_map_config].values[2].type = "uint32[DNXF_DATA_MAX_FABRIC_CONGESTION_NOF_THRESHOLD_PRIORITIES]";
    submodule_data->tables[dnxf_data_fabric_pipes_table_valid_map_config].values[2].doc = "map multicast cell priority to pipe";
    submodule_data->tables[dnxf_data_fabric_pipes_table_valid_map_config].values[2].offset = UTILEX_OFFSETOF(dnxf_data_fabric_pipes_valid_map_config_t, mc);
    submodule_data->tables[dnxf_data_fabric_pipes_table_valid_map_config].values[3].name = "lr_uc_pipe";
    submodule_data->tables[dnxf_data_fabric_pipes_table_valid_map_config].values[3].type = "int";
    submodule_data->tables[dnxf_data_fabric_pipes_table_valid_map_config].values[3].doc = "The pipe index to use for Unicast Local-Route cells";
    submodule_data->tables[dnxf_data_fabric_pipes_table_valid_map_config].values[3].offset = UTILEX_OFFSETOF(dnxf_data_fabric_pipes_valid_map_config_t, lr_uc_pipe);
    submodule_data->tables[dnxf_data_fabric_pipes_table_valid_map_config].values[4].name = "name";
    submodule_data->tables[dnxf_data_fabric_pipes_table_valid_map_config].values[4].type = "char *";
    submodule_data->tables[dnxf_data_fabric_pipes_table_valid_map_config].values[4].doc = "The configuration display name";
    submodule_data->tables[dnxf_data_fabric_pipes_table_valid_map_config].values[4].offset = UTILEX_OFFSETOF(dnxf_data_fabric_pipes_valid_map_config_t, name);
    submodule_data->tables[dnxf_data_fabric_pipes_table_valid_map_config].values[5].name = "type";
    submodule_data->tables[dnxf_data_fabric_pipes_table_valid_map_config].values[5].type = "soc_dnxc_fabric_pipe_map_type_t";
    submodule_data->tables[dnxf_data_fabric_pipes_table_valid_map_config].values[5].doc = "The pipe mapping type";
    submodule_data->tables[dnxf_data_fabric_pipes_table_valid_map_config].values[5].offset = UTILEX_OFFSETOF(dnxf_data_fabric_pipes_valid_map_config_t, type);
    submodule_data->tables[dnxf_data_fabric_pipes_table_valid_map_config].values[6].name = "min_hp_mc";
    submodule_data->tables[dnxf_data_fabric_pipes_table_valid_map_config].values[6].type = "int";
    submodule_data->tables[dnxf_data_fabric_pipes_table_valid_map_config].values[6].doc = "Minimum priority to be considered as high priority multicast";
    submodule_data->tables[dnxf_data_fabric_pipes_table_valid_map_config].values[6].offset = UTILEX_OFFSETOF(dnxf_data_fabric_pipes_valid_map_config_t, min_hp_mc);


exit:
    SHR_FUNC_EXIT;
}


int
dnxf_data_fabric_pipes_feature_get(
    int unit,
    dnxf_data_fabric_pipes_feature_e feature)
{
    return dnxc_data_mgmt_feature_data_get(unit, dnxf_data_module_fabric, dnxf_data_fabric_submodule_pipes, feature);
}


uint32
dnxf_data_fabric_pipes_max_nof_pipes_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnxf_data_module_fabric, dnxf_data_fabric_submodule_pipes, dnxf_data_fabric_pipes_define_max_nof_pipes);
}

uint32
dnxf_data_fabric_pipes_local_route_pipe_index_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnxf_data_module_fabric, dnxf_data_fabric_submodule_pipes, dnxf_data_fabric_pipes_define_local_route_pipe_index);
}

uint32
dnxf_data_fabric_pipes_nof_pipes_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnxf_data_module_fabric, dnxf_data_fabric_submodule_pipes, dnxf_data_fabric_pipes_define_nof_pipes);
}

uint32
dnxf_data_fabric_pipes_system_contains_multiple_pipe_device_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnxf_data_module_fabric, dnxf_data_fabric_submodule_pipes, dnxf_data_fabric_pipes_define_system_contains_multiple_pipe_device);
}

uint32
dnxf_data_fabric_pipes_system_tdm_priority_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnxf_data_module_fabric, dnxf_data_fabric_submodule_pipes, dnxf_data_fabric_pipes_define_system_tdm_priority);
}



const dnxf_data_fabric_pipes_map_t *
dnxf_data_fabric_pipes_map_get(
    int unit)
{
    char *data;
    dnxc_data_table_t *table;

    
    table = dnxc_data_mgmt_table_get(unit, dnxf_data_module_fabric, dnxf_data_fabric_submodule_pipes, dnxf_data_fabric_pipes_table_map);
    
    data = dnxc_data_mgmt_table_data_get(unit, table, 0, 0);
    return (const dnxf_data_fabric_pipes_map_t *) data;

}

const dnxf_data_fabric_pipes_valid_map_config_t *
dnxf_data_fabric_pipes_valid_map_config_get(
    int unit,
    int mapping_option_idx)
{
    char *data;
    dnxc_data_table_t *table;

    
    table = dnxc_data_mgmt_table_get(unit, dnxf_data_module_fabric, dnxf_data_fabric_submodule_pipes, dnxf_data_fabric_pipes_table_valid_map_config);
    
    data = dnxc_data_mgmt_table_data_get(unit, table, mapping_option_idx, 0);
    return (const dnxf_data_fabric_pipes_valid_map_config_t *) data;

}


shr_error_e
dnxf_data_fabric_pipes_map_entry_str_get(
    int unit,
    char *buffer,
    int key0,
    int key1,
    int value_index)
{
    dnxc_data_table_t *table;
    const dnxf_data_fabric_pipes_map_t *data;
    SHR_FUNC_INIT_VARS(unit);

    
    table = dnxc_data_mgmt_table_get(unit, dnxf_data_module_fabric, dnxf_data_fabric_submodule_pipes, dnxf_data_fabric_pipes_table_map);
    data = (const dnxf_data_fabric_pipes_map_t *) dnxc_data_mgmt_table_data_diag_get(unit, table, 0, 0);
    switch (value_index)
    {
        case 0:
            DNXC_DATA_MGMT_ARR_STR(buffer, DNXF_DATA_MAX_FABRIC_CONGESTION_NOF_THRESHOLD_PRIORITIES, data->uc);
            break;
        case 1:
            DNXC_DATA_MGMT_ARR_STR(buffer, DNXF_DATA_MAX_FABRIC_CONGESTION_NOF_THRESHOLD_PRIORITIES, data->mc);
            break;
        case 2:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->lr_uc_pipe);
            break;
        case 3:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%s", data->name == NULL ? "" : data->name);
            break;
        case 4:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->type);
            break;
        case 5:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->min_hp_mc);
            break;
    }

    SHR_FUNC_EXIT;
}

shr_error_e
dnxf_data_fabric_pipes_valid_map_config_entry_str_get(
    int unit,
    char *buffer,
    int key0,
    int key1,
    int value_index)
{
    dnxc_data_table_t *table;
    const dnxf_data_fabric_pipes_valid_map_config_t *data;
    SHR_FUNC_INIT_VARS(unit);

    
    table = dnxc_data_mgmt_table_get(unit, dnxf_data_module_fabric, dnxf_data_fabric_submodule_pipes, dnxf_data_fabric_pipes_table_valid_map_config);
    data = (const dnxf_data_fabric_pipes_valid_map_config_t *) dnxc_data_mgmt_table_data_diag_get(unit, table, key0, 0);
    switch (value_index)
    {
        case 0:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->nof_pipes);
            break;
        case 1:
            DNXC_DATA_MGMT_ARR_STR(buffer, DNXF_DATA_MAX_FABRIC_CONGESTION_NOF_THRESHOLD_PRIORITIES, data->uc);
            break;
        case 2:
            DNXC_DATA_MGMT_ARR_STR(buffer, DNXF_DATA_MAX_FABRIC_CONGESTION_NOF_THRESHOLD_PRIORITIES, data->mc);
            break;
        case 3:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->lr_uc_pipe);
            break;
        case 4:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%s", data->name == NULL ? "" : data->name);
            break;
        case 5:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->type);
            break;
        case 6:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->min_hp_mc);
            break;
    }

    SHR_FUNC_EXIT;
}


const dnxc_data_table_info_t *
dnxf_data_fabric_pipes_map_info_get(
    int unit)
{

    
    return dnxc_data_mgmt_table_info_get(unit, dnxf_data_module_fabric, dnxf_data_fabric_submodule_pipes, dnxf_data_fabric_pipes_table_map);

}

const dnxc_data_table_info_t *
dnxf_data_fabric_pipes_valid_map_config_info_get(
    int unit)
{

    
    return dnxc_data_mgmt_table_info_get(unit, dnxf_data_module_fabric, dnxf_data_fabric_submodule_pipes, dnxf_data_fabric_pipes_table_valid_map_config);

}






static shr_error_e
dnxf_data_fabric_multicast_init(
    int unit,
    dnxc_data_submodule_t *submodule_data)
{
    SHR_FUNC_INIT_VARS(unit);

    submodule_data->name = "multicast";
    submodule_data->doc = "General multicast attributes";
    
    submodule_data->nof_features = _dnxf_data_fabric_multicast_feature_nof;
    DNXC_DATA_ALLOC(submodule_data->features, dnxc_data_feature_t,  submodule_data->nof_features, "_dnxc_data fabric multicast features");

    submodule_data->features[dnxf_data_fabric_multicast_egress_api_supported].name = "egress_api_supported";
    submodule_data->features[dnxf_data_fabric_multicast_egress_api_supported].doc = "Indicates if the multicast egress APIs are still supported.";
    submodule_data->features[dnxf_data_fabric_multicast_egress_api_supported].flags |= DNXC_DATA_F_FEATURE;

    
    submodule_data->nof_defines = _dnxf_data_fabric_multicast_define_nof;
    DNXC_DATA_ALLOC(submodule_data->defines, dnxc_data_define_t, submodule_data->nof_defines, "_dnxc_data fabric multicast defines");

    submodule_data->defines[dnxf_data_fabric_multicast_define_table_row_size_in_uint32].name = "table_row_size_in_uint32";
    submodule_data->defines[dnxf_data_fabric_multicast_define_table_row_size_in_uint32].doc = "Multicast table row size in UINT32s.";
    
    submodule_data->defines[dnxf_data_fabric_multicast_define_table_row_size_in_uint32].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnxf_data_fabric_multicast_define_id_range].name = "id_range";
    submodule_data->defines[dnxf_data_fabric_multicast_define_id_range].doc = "Specifies the MC IDs range.";
    submodule_data->defines[dnxf_data_fabric_multicast_define_id_range].labels[0] = "data_notrev";
    
    submodule_data->defines[dnxf_data_fabric_multicast_define_id_range].flags |= DNXC_DATA_F_NUMERIC;

    submodule_data->defines[dnxf_data_fabric_multicast_define_mode].name = "mode";
    submodule_data->defines[dnxf_data_fabric_multicast_define_mode].doc = "Specifies the MC mode.";
    submodule_data->defines[dnxf_data_fabric_multicast_define_mode].labels[0] = "data_notrev";
    
    submodule_data->defines[dnxf_data_fabric_multicast_define_mode].flags |= DNXC_DATA_F_NUMERIC;

    submodule_data->defines[dnxf_data_fabric_multicast_define_priority_map_enable].name = "priority_map_enable";
    submodule_data->defines[dnxf_data_fabric_multicast_define_priority_map_enable].doc = "Enable mapping internal multicast priority according to MC-ID ranges.";
    submodule_data->defines[dnxf_data_fabric_multicast_define_priority_map_enable].labels[0] = "data_notrev";
    
    submodule_data->defines[dnxf_data_fabric_multicast_define_priority_map_enable].flags |= DNXC_DATA_F_NUMERIC;

    
    submodule_data->nof_tables = _dnxf_data_fabric_multicast_table_nof;
    DNXC_DATA_ALLOC(submodule_data->tables, dnxc_data_table_t, submodule_data->nof_tables, "_dnxc_data fabric multicast tables");


exit:
    SHR_FUNC_EXIT;
}


int
dnxf_data_fabric_multicast_feature_get(
    int unit,
    dnxf_data_fabric_multicast_feature_e feature)
{
    return dnxc_data_mgmt_feature_data_get(unit, dnxf_data_module_fabric, dnxf_data_fabric_submodule_multicast, feature);
}


uint32
dnxf_data_fabric_multicast_table_row_size_in_uint32_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnxf_data_module_fabric, dnxf_data_fabric_submodule_multicast, dnxf_data_fabric_multicast_define_table_row_size_in_uint32);
}

uint32
dnxf_data_fabric_multicast_id_range_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnxf_data_module_fabric, dnxf_data_fabric_submodule_multicast, dnxf_data_fabric_multicast_define_id_range);
}

uint32
dnxf_data_fabric_multicast_mode_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnxf_data_module_fabric, dnxf_data_fabric_submodule_multicast, dnxf_data_fabric_multicast_define_mode);
}

uint32
dnxf_data_fabric_multicast_priority_map_enable_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnxf_data_module_fabric, dnxf_data_fabric_submodule_multicast, dnxf_data_fabric_multicast_define_priority_map_enable);
}










static shr_error_e
dnxf_data_fabric_fifos_init(
    int unit,
    dnxc_data_submodule_t *submodule_data)
{
    SHR_FUNC_INIT_VARS(unit);

    submodule_data->name = "fifos";
    submodule_data->doc = "Fabric FIFOs attributes";
    
    submodule_data->nof_features = _dnxf_data_fabric_fifos_feature_nof;
    DNXC_DATA_ALLOC(submodule_data->features, dnxc_data_feature_t,  submodule_data->nof_features, "_dnxc_data fabric fifos features");

    submodule_data->features[dnxf_data_fabric_fifos_reduced_buffers].name = "reduced_buffers";
    submodule_data->features[dnxf_data_fabric_fifos_reduced_buffers].doc = "Indicates if device have reduced fifo buffers";
    submodule_data->features[dnxf_data_fabric_fifos_reduced_buffers].flags |= DNXC_DATA_F_FEATURE;

    
    submodule_data->nof_defines = _dnxf_data_fabric_fifos_define_nof;
    DNXC_DATA_ALLOC(submodule_data->defines, dnxc_data_define_t, submodule_data->nof_defines, "_dnxc_data fabric fifos defines");

    submodule_data->defines[dnxf_data_fabric_fifos_define_granularity].name = "granularity";
    submodule_data->defines[dnxf_data_fabric_fifos_define_granularity].doc = "FIFO granularity";
    
    submodule_data->defines[dnxf_data_fabric_fifos_define_granularity].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnxf_data_fabric_fifos_define_min_depth].name = "min_depth";
    submodule_data->defines[dnxf_data_fabric_fifos_define_min_depth].doc = "Minimal FIFO depth";
    
    submodule_data->defines[dnxf_data_fabric_fifos_define_min_depth].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnxf_data_fabric_fifos_define_max_unused_resources].name = "max_unused_resources";
    submodule_data->defines[dnxf_data_fabric_fifos_define_max_unused_resources].doc = "Maximal unused resources allowed per FIFO";
    
    submodule_data->defines[dnxf_data_fabric_fifos_define_max_unused_resources].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnxf_data_fabric_fifos_define_rx_resources].name = "rx_resources";
    submodule_data->defines[dnxf_data_fabric_fifos_define_rx_resources].doc = "Maximal Available Resources per RX FIFO";
    
    submodule_data->defines[dnxf_data_fabric_fifos_define_rx_resources].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnxf_data_fabric_fifos_define_mid_resources].name = "mid_resources";
    submodule_data->defines[dnxf_data_fabric_fifos_define_mid_resources].doc = "Maximal Available Resources per MIDDLE FIFO";
    
    submodule_data->defines[dnxf_data_fabric_fifos_define_mid_resources].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnxf_data_fabric_fifos_define_tx_resources].name = "tx_resources";
    submodule_data->defines[dnxf_data_fabric_fifos_define_tx_resources].doc = "Maximal Available Resources per TX FIFO";
    
    submodule_data->defines[dnxf_data_fabric_fifos_define_tx_resources].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnxf_data_fabric_fifos_define_reduced_rx_resources].name = "reduced_rx_resources";
    submodule_data->defines[dnxf_data_fabric_fifos_define_reduced_rx_resources].doc = "Reduced buffer RX FIFO";
    
    submodule_data->defines[dnxf_data_fabric_fifos_define_reduced_rx_resources].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnxf_data_fabric_fifos_define_dfl_resources].name = "dfl_resources";
    submodule_data->defines[dnxf_data_fabric_fifos_define_dfl_resources].doc = "DFL bank max resources";
    
    submodule_data->defines[dnxf_data_fabric_fifos_define_dfl_resources].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnxf_data_fabric_fifos_define_reduced_dfl_resources].name = "reduced_dfl_resources";
    submodule_data->defines[dnxf_data_fabric_fifos_define_reduced_dfl_resources].doc = "DFL bank max resources if SKU with reduced buffers";
    
    submodule_data->defines[dnxf_data_fabric_fifos_define_reduced_dfl_resources].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnxf_data_fabric_fifos_define_rx_full_offset].name = "rx_full_offset";
    submodule_data->defines[dnxf_data_fabric_fifos_define_rx_full_offset].doc = "RX FULL-to-DEPTH offset";
    
    submodule_data->defines[dnxf_data_fabric_fifos_define_rx_full_offset].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnxf_data_fabric_fifos_define_mid_full_offset].name = "mid_full_offset";
    submodule_data->defines[dnxf_data_fabric_fifos_define_mid_full_offset].doc = "MID FULL-to-DEPTH offset";
    
    submodule_data->defines[dnxf_data_fabric_fifos_define_mid_full_offset].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnxf_data_fabric_fifos_define_tx_full_offset].name = "tx_full_offset";
    submodule_data->defines[dnxf_data_fabric_fifos_define_tx_full_offset].doc = "TX FULL-to-DEPTH offset";
    
    submodule_data->defines[dnxf_data_fabric_fifos_define_tx_full_offset].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnxf_data_fabric_fifos_define_dfl_bank_wr_threshold_offset].name = "dfl_bank_wr_threshold_offset";
    submodule_data->defines[dnxf_data_fabric_fifos_define_dfl_bank_wr_threshold_offset].doc = "Offset to the full bank size for the write threshold";
    
    submodule_data->defines[dnxf_data_fabric_fifos_define_dfl_bank_wr_threshold_offset].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnxf_data_fabric_fifos_define_dfl_bank_admit_threshold_additional_offset].name = "dfl_bank_admit_threshold_additional_offset";
    submodule_data->defines[dnxf_data_fabric_fifos_define_dfl_bank_admit_threshold_additional_offset].doc = "Additional offset for the admit DFL bank threshold as it has to be lowe than write threshold";
    
    submodule_data->defines[dnxf_data_fabric_fifos_define_dfl_bank_admit_threshold_additional_offset].flags |= DNXC_DATA_F_DEFINE;

    
    submodule_data->nof_tables = _dnxf_data_fabric_fifos_table_nof;
    DNXC_DATA_ALLOC(submodule_data->tables, dnxc_data_table_t, submodule_data->nof_tables, "_dnxc_data fabric fifos tables");

    
    submodule_data->tables[dnxf_data_fabric_fifos_table_rx_depth_per_pipe].name = "rx_depth_per_pipe";
    submodule_data->tables[dnxf_data_fabric_fifos_table_rx_depth_per_pipe].doc = "RX FIFO depth per pipe";
    submodule_data->tables[dnxf_data_fabric_fifos_table_rx_depth_per_pipe].flags |= DNXC_DATA_F_TABLE;
    submodule_data->tables[dnxf_data_fabric_fifos_table_rx_depth_per_pipe].size_of_values = sizeof(dnxf_data_fabric_fifos_rx_depth_per_pipe_t);
    submodule_data->tables[dnxf_data_fabric_fifos_table_rx_depth_per_pipe].entry_get = dnxf_data_fabric_fifos_rx_depth_per_pipe_entry_str_get;

    
    submodule_data->tables[dnxf_data_fabric_fifos_table_rx_depth_per_pipe].nof_keys = 1;
    submodule_data->tables[dnxf_data_fabric_fifos_table_rx_depth_per_pipe].keys[0].name = "pipe_id";
    submodule_data->tables[dnxf_data_fabric_fifos_table_rx_depth_per_pipe].keys[0].doc = "Pipe ID.";

    
    submodule_data->tables[dnxf_data_fabric_fifos_table_rx_depth_per_pipe].nof_values = 2;
    DNXC_DATA_ALLOC(submodule_data->tables[dnxf_data_fabric_fifos_table_rx_depth_per_pipe].values, dnxc_data_value_t, submodule_data->tables[dnxf_data_fabric_fifos_table_rx_depth_per_pipe].nof_values, "_dnxf_data_fabric_fifos_table_rx_depth_per_pipe table values");
    submodule_data->tables[dnxf_data_fabric_fifos_table_rx_depth_per_pipe].values[0].name = "fe1";
    submodule_data->tables[dnxf_data_fabric_fifos_table_rx_depth_per_pipe].values[0].type = "uint32";
    submodule_data->tables[dnxf_data_fabric_fifos_table_rx_depth_per_pipe].values[0].doc = "FE1 FIFOs depth";
    submodule_data->tables[dnxf_data_fabric_fifos_table_rx_depth_per_pipe].values[0].offset = UTILEX_OFFSETOF(dnxf_data_fabric_fifos_rx_depth_per_pipe_t, fe1);
    submodule_data->tables[dnxf_data_fabric_fifos_table_rx_depth_per_pipe].values[1].name = "fe3";
    submodule_data->tables[dnxf_data_fabric_fifos_table_rx_depth_per_pipe].values[1].type = "uint32";
    submodule_data->tables[dnxf_data_fabric_fifos_table_rx_depth_per_pipe].values[1].doc = "FE3 FIFOs depth";
    submodule_data->tables[dnxf_data_fabric_fifos_table_rx_depth_per_pipe].values[1].offset = UTILEX_OFFSETOF(dnxf_data_fabric_fifos_rx_depth_per_pipe_t, fe3);

    
    submodule_data->tables[dnxf_data_fabric_fifos_table_mid_depth_per_pipe].name = "mid_depth_per_pipe";
    submodule_data->tables[dnxf_data_fabric_fifos_table_mid_depth_per_pipe].doc = "Middle FIFO depth per pipe";
    submodule_data->tables[dnxf_data_fabric_fifos_table_mid_depth_per_pipe].flags |= DNXC_DATA_F_TABLE;
    submodule_data->tables[dnxf_data_fabric_fifos_table_mid_depth_per_pipe].size_of_values = sizeof(dnxf_data_fabric_fifos_mid_depth_per_pipe_t);
    submodule_data->tables[dnxf_data_fabric_fifos_table_mid_depth_per_pipe].entry_get = dnxf_data_fabric_fifos_mid_depth_per_pipe_entry_str_get;

    
    submodule_data->tables[dnxf_data_fabric_fifos_table_mid_depth_per_pipe].nof_keys = 1;
    submodule_data->tables[dnxf_data_fabric_fifos_table_mid_depth_per_pipe].keys[0].name = "pipe_id";
    submodule_data->tables[dnxf_data_fabric_fifos_table_mid_depth_per_pipe].keys[0].doc = "Pipe ID.";

    
    submodule_data->tables[dnxf_data_fabric_fifos_table_mid_depth_per_pipe].nof_values = 4;
    DNXC_DATA_ALLOC(submodule_data->tables[dnxf_data_fabric_fifos_table_mid_depth_per_pipe].values, dnxc_data_value_t, submodule_data->tables[dnxf_data_fabric_fifos_table_mid_depth_per_pipe].nof_values, "_dnxf_data_fabric_fifos_table_mid_depth_per_pipe table values");
    submodule_data->tables[dnxf_data_fabric_fifos_table_mid_depth_per_pipe].values[0].name = "fe1_nlr";
    submodule_data->tables[dnxf_data_fabric_fifos_table_mid_depth_per_pipe].values[0].type = "uint32";
    submodule_data->tables[dnxf_data_fabric_fifos_table_mid_depth_per_pipe].values[0].doc = "FE1 FIFOs Non Local Route Depth";
    submodule_data->tables[dnxf_data_fabric_fifos_table_mid_depth_per_pipe].values[0].offset = UTILEX_OFFSETOF(dnxf_data_fabric_fifos_mid_depth_per_pipe_t, fe1_nlr);
    submodule_data->tables[dnxf_data_fabric_fifos_table_mid_depth_per_pipe].values[1].name = "fe3_nlr";
    submodule_data->tables[dnxf_data_fabric_fifos_table_mid_depth_per_pipe].values[1].type = "uint32";
    submodule_data->tables[dnxf_data_fabric_fifos_table_mid_depth_per_pipe].values[1].doc = "FE3 FIFOs Non Local Route Depth";
    submodule_data->tables[dnxf_data_fabric_fifos_table_mid_depth_per_pipe].values[1].offset = UTILEX_OFFSETOF(dnxf_data_fabric_fifos_mid_depth_per_pipe_t, fe3_nlr);
    submodule_data->tables[dnxf_data_fabric_fifos_table_mid_depth_per_pipe].values[2].name = "fe1_lr";
    submodule_data->tables[dnxf_data_fabric_fifos_table_mid_depth_per_pipe].values[2].type = "uint32";
    submodule_data->tables[dnxf_data_fabric_fifos_table_mid_depth_per_pipe].values[2].doc = "FE1 FIFOs Local Route Depth";
    submodule_data->tables[dnxf_data_fabric_fifos_table_mid_depth_per_pipe].values[2].offset = UTILEX_OFFSETOF(dnxf_data_fabric_fifos_mid_depth_per_pipe_t, fe1_lr);
    submodule_data->tables[dnxf_data_fabric_fifos_table_mid_depth_per_pipe].values[3].name = "fe3_lr";
    submodule_data->tables[dnxf_data_fabric_fifos_table_mid_depth_per_pipe].values[3].type = "uint32";
    submodule_data->tables[dnxf_data_fabric_fifos_table_mid_depth_per_pipe].values[3].doc = "FE3 FIFOs Local Route Depth";
    submodule_data->tables[dnxf_data_fabric_fifos_table_mid_depth_per_pipe].values[3].offset = UTILEX_OFFSETOF(dnxf_data_fabric_fifos_mid_depth_per_pipe_t, fe3_lr);

    
    submodule_data->tables[dnxf_data_fabric_fifos_table_tx_depth_per_pipe].name = "tx_depth_per_pipe";
    submodule_data->tables[dnxf_data_fabric_fifos_table_tx_depth_per_pipe].doc = "TX FIFO depth per pipe";
    submodule_data->tables[dnxf_data_fabric_fifos_table_tx_depth_per_pipe].flags |= DNXC_DATA_F_TABLE;
    submodule_data->tables[dnxf_data_fabric_fifos_table_tx_depth_per_pipe].size_of_values = sizeof(dnxf_data_fabric_fifos_tx_depth_per_pipe_t);
    submodule_data->tables[dnxf_data_fabric_fifos_table_tx_depth_per_pipe].entry_get = dnxf_data_fabric_fifos_tx_depth_per_pipe_entry_str_get;

    
    submodule_data->tables[dnxf_data_fabric_fifos_table_tx_depth_per_pipe].nof_keys = 1;
    submodule_data->tables[dnxf_data_fabric_fifos_table_tx_depth_per_pipe].keys[0].name = "pipe_id";
    submodule_data->tables[dnxf_data_fabric_fifos_table_tx_depth_per_pipe].keys[0].doc = "Pipe ID.";

    
    submodule_data->tables[dnxf_data_fabric_fifos_table_tx_depth_per_pipe].nof_values = 4;
    DNXC_DATA_ALLOC(submodule_data->tables[dnxf_data_fabric_fifos_table_tx_depth_per_pipe].values, dnxc_data_value_t, submodule_data->tables[dnxf_data_fabric_fifos_table_tx_depth_per_pipe].nof_values, "_dnxf_data_fabric_fifos_table_tx_depth_per_pipe table values");
    submodule_data->tables[dnxf_data_fabric_fifos_table_tx_depth_per_pipe].values[0].name = "fe1_nlr";
    submodule_data->tables[dnxf_data_fabric_fifos_table_tx_depth_per_pipe].values[0].type = "uint32";
    submodule_data->tables[dnxf_data_fabric_fifos_table_tx_depth_per_pipe].values[0].doc = "FE1 FIFOs Non Local Route Depth";
    submodule_data->tables[dnxf_data_fabric_fifos_table_tx_depth_per_pipe].values[0].offset = UTILEX_OFFSETOF(dnxf_data_fabric_fifos_tx_depth_per_pipe_t, fe1_nlr);
    submodule_data->tables[dnxf_data_fabric_fifos_table_tx_depth_per_pipe].values[1].name = "fe3_nlr";
    submodule_data->tables[dnxf_data_fabric_fifos_table_tx_depth_per_pipe].values[1].type = "uint32";
    submodule_data->tables[dnxf_data_fabric_fifos_table_tx_depth_per_pipe].values[1].doc = "FE3 FIFOs Non Local Route Depth";
    submodule_data->tables[dnxf_data_fabric_fifos_table_tx_depth_per_pipe].values[1].offset = UTILEX_OFFSETOF(dnxf_data_fabric_fifos_tx_depth_per_pipe_t, fe3_nlr);
    submodule_data->tables[dnxf_data_fabric_fifos_table_tx_depth_per_pipe].values[2].name = "fe1_lr";
    submodule_data->tables[dnxf_data_fabric_fifos_table_tx_depth_per_pipe].values[2].type = "uint32";
    submodule_data->tables[dnxf_data_fabric_fifos_table_tx_depth_per_pipe].values[2].doc = "FE1 FIFOs Local Route Depth";
    submodule_data->tables[dnxf_data_fabric_fifos_table_tx_depth_per_pipe].values[2].offset = UTILEX_OFFSETOF(dnxf_data_fabric_fifos_tx_depth_per_pipe_t, fe1_lr);
    submodule_data->tables[dnxf_data_fabric_fifos_table_tx_depth_per_pipe].values[3].name = "fe3_lr";
    submodule_data->tables[dnxf_data_fabric_fifos_table_tx_depth_per_pipe].values[3].type = "uint32";
    submodule_data->tables[dnxf_data_fabric_fifos_table_tx_depth_per_pipe].values[3].doc = "FE3 FIFOs Local Route Depth";
    submodule_data->tables[dnxf_data_fabric_fifos_table_tx_depth_per_pipe].values[3].offset = UTILEX_OFFSETOF(dnxf_data_fabric_fifos_tx_depth_per_pipe_t, fe3_lr);


exit:
    SHR_FUNC_EXIT;
}


int
dnxf_data_fabric_fifos_feature_get(
    int unit,
    dnxf_data_fabric_fifos_feature_e feature)
{
    return dnxc_data_mgmt_feature_data_get(unit, dnxf_data_module_fabric, dnxf_data_fabric_submodule_fifos, feature);
}


uint32
dnxf_data_fabric_fifos_granularity_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnxf_data_module_fabric, dnxf_data_fabric_submodule_fifos, dnxf_data_fabric_fifos_define_granularity);
}

uint32
dnxf_data_fabric_fifos_min_depth_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnxf_data_module_fabric, dnxf_data_fabric_submodule_fifos, dnxf_data_fabric_fifos_define_min_depth);
}

uint32
dnxf_data_fabric_fifos_max_unused_resources_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnxf_data_module_fabric, dnxf_data_fabric_submodule_fifos, dnxf_data_fabric_fifos_define_max_unused_resources);
}

uint32
dnxf_data_fabric_fifos_rx_resources_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnxf_data_module_fabric, dnxf_data_fabric_submodule_fifos, dnxf_data_fabric_fifos_define_rx_resources);
}

uint32
dnxf_data_fabric_fifos_mid_resources_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnxf_data_module_fabric, dnxf_data_fabric_submodule_fifos, dnxf_data_fabric_fifos_define_mid_resources);
}

uint32
dnxf_data_fabric_fifos_tx_resources_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnxf_data_module_fabric, dnxf_data_fabric_submodule_fifos, dnxf_data_fabric_fifos_define_tx_resources);
}

uint32
dnxf_data_fabric_fifos_reduced_rx_resources_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnxf_data_module_fabric, dnxf_data_fabric_submodule_fifos, dnxf_data_fabric_fifos_define_reduced_rx_resources);
}

uint32
dnxf_data_fabric_fifos_dfl_resources_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnxf_data_module_fabric, dnxf_data_fabric_submodule_fifos, dnxf_data_fabric_fifos_define_dfl_resources);
}

uint32
dnxf_data_fabric_fifos_reduced_dfl_resources_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnxf_data_module_fabric, dnxf_data_fabric_submodule_fifos, dnxf_data_fabric_fifos_define_reduced_dfl_resources);
}

uint32
dnxf_data_fabric_fifos_rx_full_offset_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnxf_data_module_fabric, dnxf_data_fabric_submodule_fifos, dnxf_data_fabric_fifos_define_rx_full_offset);
}

uint32
dnxf_data_fabric_fifos_mid_full_offset_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnxf_data_module_fabric, dnxf_data_fabric_submodule_fifos, dnxf_data_fabric_fifos_define_mid_full_offset);
}

uint32
dnxf_data_fabric_fifos_tx_full_offset_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnxf_data_module_fabric, dnxf_data_fabric_submodule_fifos, dnxf_data_fabric_fifos_define_tx_full_offset);
}

uint32
dnxf_data_fabric_fifos_dfl_bank_wr_threshold_offset_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnxf_data_module_fabric, dnxf_data_fabric_submodule_fifos, dnxf_data_fabric_fifos_define_dfl_bank_wr_threshold_offset);
}

uint32
dnxf_data_fabric_fifos_dfl_bank_admit_threshold_additional_offset_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnxf_data_module_fabric, dnxf_data_fabric_submodule_fifos, dnxf_data_fabric_fifos_define_dfl_bank_admit_threshold_additional_offset);
}



const dnxf_data_fabric_fifos_rx_depth_per_pipe_t *
dnxf_data_fabric_fifos_rx_depth_per_pipe_get(
    int unit,
    int pipe_id)
{
    char *data;
    dnxc_data_table_t *table;

    
    table = dnxc_data_mgmt_table_get(unit, dnxf_data_module_fabric, dnxf_data_fabric_submodule_fifos, dnxf_data_fabric_fifos_table_rx_depth_per_pipe);
    
    data = dnxc_data_mgmt_table_data_get(unit, table, pipe_id, 0);
    return (const dnxf_data_fabric_fifos_rx_depth_per_pipe_t *) data;

}

const dnxf_data_fabric_fifos_mid_depth_per_pipe_t *
dnxf_data_fabric_fifos_mid_depth_per_pipe_get(
    int unit,
    int pipe_id)
{
    char *data;
    dnxc_data_table_t *table;

    
    table = dnxc_data_mgmt_table_get(unit, dnxf_data_module_fabric, dnxf_data_fabric_submodule_fifos, dnxf_data_fabric_fifos_table_mid_depth_per_pipe);
    
    data = dnxc_data_mgmt_table_data_get(unit, table, pipe_id, 0);
    return (const dnxf_data_fabric_fifos_mid_depth_per_pipe_t *) data;

}

const dnxf_data_fabric_fifos_tx_depth_per_pipe_t *
dnxf_data_fabric_fifos_tx_depth_per_pipe_get(
    int unit,
    int pipe_id)
{
    char *data;
    dnxc_data_table_t *table;

    
    table = dnxc_data_mgmt_table_get(unit, dnxf_data_module_fabric, dnxf_data_fabric_submodule_fifos, dnxf_data_fabric_fifos_table_tx_depth_per_pipe);
    
    data = dnxc_data_mgmt_table_data_get(unit, table, pipe_id, 0);
    return (const dnxf_data_fabric_fifos_tx_depth_per_pipe_t *) data;

}


shr_error_e
dnxf_data_fabric_fifos_rx_depth_per_pipe_entry_str_get(
    int unit,
    char *buffer,
    int key0,
    int key1,
    int value_index)
{
    dnxc_data_table_t *table;
    const dnxf_data_fabric_fifos_rx_depth_per_pipe_t *data;
    SHR_FUNC_INIT_VARS(unit);

    
    table = dnxc_data_mgmt_table_get(unit, dnxf_data_module_fabric, dnxf_data_fabric_submodule_fifos, dnxf_data_fabric_fifos_table_rx_depth_per_pipe);
    data = (const dnxf_data_fabric_fifos_rx_depth_per_pipe_t *) dnxc_data_mgmt_table_data_diag_get(unit, table, key0, 0);
    switch (value_index)
    {
        case 0:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->fe1);
            break;
        case 1:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->fe3);
            break;
    }

    SHR_FUNC_EXIT;
}

shr_error_e
dnxf_data_fabric_fifos_mid_depth_per_pipe_entry_str_get(
    int unit,
    char *buffer,
    int key0,
    int key1,
    int value_index)
{
    dnxc_data_table_t *table;
    const dnxf_data_fabric_fifos_mid_depth_per_pipe_t *data;
    SHR_FUNC_INIT_VARS(unit);

    
    table = dnxc_data_mgmt_table_get(unit, dnxf_data_module_fabric, dnxf_data_fabric_submodule_fifos, dnxf_data_fabric_fifos_table_mid_depth_per_pipe);
    data = (const dnxf_data_fabric_fifos_mid_depth_per_pipe_t *) dnxc_data_mgmt_table_data_diag_get(unit, table, key0, 0);
    switch (value_index)
    {
        case 0:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->fe1_nlr);
            break;
        case 1:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->fe3_nlr);
            break;
        case 2:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->fe1_lr);
            break;
        case 3:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->fe3_lr);
            break;
    }

    SHR_FUNC_EXIT;
}

shr_error_e
dnxf_data_fabric_fifos_tx_depth_per_pipe_entry_str_get(
    int unit,
    char *buffer,
    int key0,
    int key1,
    int value_index)
{
    dnxc_data_table_t *table;
    const dnxf_data_fabric_fifos_tx_depth_per_pipe_t *data;
    SHR_FUNC_INIT_VARS(unit);

    
    table = dnxc_data_mgmt_table_get(unit, dnxf_data_module_fabric, dnxf_data_fabric_submodule_fifos, dnxf_data_fabric_fifos_table_tx_depth_per_pipe);
    data = (const dnxf_data_fabric_fifos_tx_depth_per_pipe_t *) dnxc_data_mgmt_table_data_diag_get(unit, table, key0, 0);
    switch (value_index)
    {
        case 0:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->fe1_nlr);
            break;
        case 1:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->fe3_nlr);
            break;
        case 2:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->fe1_lr);
            break;
        case 3:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->fe3_lr);
            break;
    }

    SHR_FUNC_EXIT;
}


const dnxc_data_table_info_t *
dnxf_data_fabric_fifos_rx_depth_per_pipe_info_get(
    int unit)
{

    
    return dnxc_data_mgmt_table_info_get(unit, dnxf_data_module_fabric, dnxf_data_fabric_submodule_fifos, dnxf_data_fabric_fifos_table_rx_depth_per_pipe);

}

const dnxc_data_table_info_t *
dnxf_data_fabric_fifos_mid_depth_per_pipe_info_get(
    int unit)
{

    
    return dnxc_data_mgmt_table_info_get(unit, dnxf_data_module_fabric, dnxf_data_fabric_submodule_fifos, dnxf_data_fabric_fifos_table_mid_depth_per_pipe);

}

const dnxc_data_table_info_t *
dnxf_data_fabric_fifos_tx_depth_per_pipe_info_get(
    int unit)
{

    
    return dnxc_data_mgmt_table_info_get(unit, dnxf_data_module_fabric, dnxf_data_fabric_submodule_fifos, dnxf_data_fabric_fifos_table_tx_depth_per_pipe);

}






static shr_error_e
dnxf_data_fabric_congestion_init(
    int unit,
    dnxc_data_submodule_t *submodule_data)
{
    SHR_FUNC_INIT_VARS(unit);

    submodule_data->name = "congestion";
    submodule_data->doc = "General CGM attributes";
    
    submodule_data->nof_features = _dnxf_data_fabric_congestion_feature_nof;
    DNXC_DATA_ALLOC(submodule_data->features, dnxc_data_feature_t,  submodule_data->nof_features, "_dnxc_data fabric congestion features");

    submodule_data->features[dnxf_data_fabric_congestion_credit_based_llfc_supported].name = "credit_based_llfc_supported";
    submodule_data->features[dnxf_data_fabric_congestion_credit_based_llfc_supported].doc = "Indicates if device supports credit based link level flow control";
    submodule_data->features[dnxf_data_fabric_congestion_credit_based_llfc_supported].flags |= DNXC_DATA_F_FEATURE;

    
    submodule_data->nof_defines = _dnxf_data_fabric_congestion_define_nof;
    DNXC_DATA_ALLOC(submodule_data->defines, dnxc_data_define_t, submodule_data->nof_defines, "_dnxc_data fabric congestion defines");

    submodule_data->defines[dnxf_data_fabric_congestion_define_nof_profiles].name = "nof_profiles";
    submodule_data->defines[dnxf_data_fabric_congestion_define_nof_profiles].doc = "Number of CGM profiles.";
    
    submodule_data->defines[dnxf_data_fabric_congestion_define_nof_profiles].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnxf_data_fabric_congestion_define_nof_threshold_priorities].name = "nof_threshold_priorities";
    submodule_data->defines[dnxf_data_fabric_congestion_define_nof_threshold_priorities].doc = "Number of CGM threhold priorities.";
    
    submodule_data->defines[dnxf_data_fabric_congestion_define_nof_threshold_priorities].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnxf_data_fabric_congestion_define_nof_threshold_levels].name = "nof_threshold_levels";
    submodule_data->defines[dnxf_data_fabric_congestion_define_nof_threshold_levels].doc = "Number of CGM threhold levels.";
    
    submodule_data->defines[dnxf_data_fabric_congestion_define_nof_threshold_levels].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnxf_data_fabric_congestion_define_nof_threshold_index_dimensions].name = "nof_threshold_index_dimensions";
    submodule_data->defines[dnxf_data_fabric_congestion_define_nof_threshold_index_dimensions].doc = "Number of threshold index dimendions used to indicate the application of the threshold value.";
    
    submodule_data->defines[dnxf_data_fabric_congestion_define_nof_threshold_index_dimensions].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnxf_data_fabric_congestion_define_nof_dfl_banks].name = "nof_dfl_banks";
    submodule_data->defines[dnxf_data_fabric_congestion_define_nof_dfl_banks].doc = "Number of DFL banks.";
    submodule_data->defines[dnxf_data_fabric_congestion_define_nof_dfl_banks].labels[0] = "data_notrev";
    
    submodule_data->defines[dnxf_data_fabric_congestion_define_nof_dfl_banks].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnxf_data_fabric_congestion_define_nof_dfl_sub_banks].name = "nof_dfl_sub_banks";
    submodule_data->defines[dnxf_data_fabric_congestion_define_nof_dfl_sub_banks].doc = "Number of sub-banks for each DFL bank.";
    submodule_data->defines[dnxf_data_fabric_congestion_define_nof_dfl_sub_banks].labels[0] = "data_notrev";
    
    submodule_data->defines[dnxf_data_fabric_congestion_define_nof_dfl_sub_banks].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnxf_data_fabric_congestion_define_nof_dfl_bank_entries].name = "nof_dfl_bank_entries";
    submodule_data->defines[dnxf_data_fabric_congestion_define_nof_dfl_bank_entries].doc = "Number of overall entries in each DFL bank.";
    submodule_data->defines[dnxf_data_fabric_congestion_define_nof_dfl_bank_entries].labels[0] = "data_notrev";
    
    submodule_data->defines[dnxf_data_fabric_congestion_define_nof_dfl_bank_entries].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnxf_data_fabric_congestion_define_nof_rci_bits].name = "nof_rci_bits";
    submodule_data->defines[dnxf_data_fabric_congestion_define_nof_rci_bits].doc = "Number of RCI indication bits.";
    submodule_data->defines[dnxf_data_fabric_congestion_define_nof_rci_bits].labels[0] = "data_notrev";
    
    submodule_data->defines[dnxf_data_fabric_congestion_define_nof_rci_bits].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnxf_data_fabric_congestion_define_max_wfq_weight_value].name = "max_wfq_weight_value";
    submodule_data->defines[dnxf_data_fabric_congestion_define_max_wfq_weight_value].doc = "Maxmium WFQ value";
    
    submodule_data->defines[dnxf_data_fabric_congestion_define_max_wfq_weight_value].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnxf_data_fabric_congestion_define_llfc_type_default].name = "llfc_type_default";
    submodule_data->defines[dnxf_data_fabric_congestion_define_llfc_type_default].doc = "Default llfc type mode";
    
    submodule_data->defines[dnxf_data_fabric_congestion_define_llfc_type_default].flags |= DNXC_DATA_F_NUMERIC;

    
    submodule_data->nof_tables = _dnxf_data_fabric_congestion_table_nof;
    DNXC_DATA_ALLOC(submodule_data->tables, dnxc_data_table_t, submodule_data->nof_tables, "_dnxc_data fabric congestion tables");

    
    submodule_data->tables[dnxf_data_fabric_congestion_table_thresholds_info].name = "thresholds_info";
    submodule_data->tables[dnxf_data_fabric_congestion_table_thresholds_info].doc = "Congestion manager thresholds information.";
    submodule_data->tables[dnxf_data_fabric_congestion_table_thresholds_info].labels[0] = "data_notrev";
    submodule_data->tables[dnxf_data_fabric_congestion_table_thresholds_info].flags |= DNXC_DATA_F_TABLE;
    submodule_data->tables[dnxf_data_fabric_congestion_table_thresholds_info].size_of_values = sizeof(dnxf_data_fabric_congestion_thresholds_info_t);
    submodule_data->tables[dnxf_data_fabric_congestion_table_thresholds_info].entry_get = dnxf_data_fabric_congestion_thresholds_info_entry_str_get;

    
    submodule_data->tables[dnxf_data_fabric_congestion_table_thresholds_info].nof_keys = 1;
    submodule_data->tables[dnxf_data_fabric_congestion_table_thresholds_info].keys[0].name = "threshold_id";
    submodule_data->tables[dnxf_data_fabric_congestion_table_thresholds_info].keys[0].doc = "The name of the threshold follwing the convention _SHR_FABRIC[Stage][Name][Index]th.";

    
    submodule_data->tables[dnxf_data_fabric_congestion_table_thresholds_info].nof_values = 8;
    DNXC_DATA_ALLOC(submodule_data->tables[dnxf_data_fabric_congestion_table_thresholds_info].values, dnxc_data_value_t, submodule_data->tables[dnxf_data_fabric_congestion_table_thresholds_info].nof_values, "_dnxf_data_fabric_congestion_table_thresholds_info table values");
    submodule_data->tables[dnxf_data_fabric_congestion_table_thresholds_info].values[0].name = "threshold_str";
    submodule_data->tables[dnxf_data_fabric_congestion_table_thresholds_info].values[0].type = "char *";
    submodule_data->tables[dnxf_data_fabric_congestion_table_thresholds_info].values[0].doc = "String associated to the threshold used for diagnostic printouts.";
    submodule_data->tables[dnxf_data_fabric_congestion_table_thresholds_info].values[0].offset = UTILEX_OFFSETOF(dnxf_data_fabric_congestion_thresholds_info_t, threshold_str);
    submodule_data->tables[dnxf_data_fabric_congestion_table_thresholds_info].values[1].name = "threshold_group";
    submodule_data->tables[dnxf_data_fabric_congestion_table_thresholds_info].values[1].type = "soc_dnxf_threshold_group_options_t";
    submodule_data->tables[dnxf_data_fabric_congestion_table_thresholds_info].values[1].doc = "Shows the threshold group which is used for diagnostic filtering.";
    submodule_data->tables[dnxf_data_fabric_congestion_table_thresholds_info].values[1].offset = UTILEX_OFFSETOF(dnxf_data_fabric_congestion_thresholds_info_t, threshold_group);
    submodule_data->tables[dnxf_data_fabric_congestion_table_thresholds_info].values[2].name = "threshold_stage";
    submodule_data->tables[dnxf_data_fabric_congestion_table_thresholds_info].values[2].type = "soc_dnxf_threshold_stage_options_t";
    submodule_data->tables[dnxf_data_fabric_congestion_table_thresholds_info].values[2].doc = "Shows the threshold stage which is used for diagnostic filtering.";
    submodule_data->tables[dnxf_data_fabric_congestion_table_thresholds_info].values[2].offset = UTILEX_OFFSETOF(dnxf_data_fabric_congestion_thresholds_info_t, threshold_stage);
    submodule_data->tables[dnxf_data_fabric_congestion_table_thresholds_info].values[3].name = "index_type";
    submodule_data->tables[dnxf_data_fabric_congestion_table_thresholds_info].values[3].type = "_shr_dnxf_cgm_index_type_t";
    submodule_data->tables[dnxf_data_fabric_congestion_table_thresholds_info].values[3].doc = "Shows the threshold index type used to specify the threshold application.";
    submodule_data->tables[dnxf_data_fabric_congestion_table_thresholds_info].values[3].offset = UTILEX_OFFSETOF(dnxf_data_fabric_congestion_thresholds_info_t, index_type);
    submodule_data->tables[dnxf_data_fabric_congestion_table_thresholds_info].values[4].name = "supported_flags";
    submodule_data->tables[dnxf_data_fabric_congestion_table_thresholds_info].values[4].type = "uint32";
    submodule_data->tables[dnxf_data_fabric_congestion_table_thresholds_info].values[4].doc = "Indicates which of the API flags are supported for the given threshold.";
    submodule_data->tables[dnxf_data_fabric_congestion_table_thresholds_info].values[4].offset = UTILEX_OFFSETOF(dnxf_data_fabric_congestion_thresholds_info_t, supported_flags);
    submodule_data->tables[dnxf_data_fabric_congestion_table_thresholds_info].values[5].name = "is_tx";
    submodule_data->tables[dnxf_data_fabric_congestion_table_thresholds_info].values[5].type = "uint32";
    submodule_data->tables[dnxf_data_fabric_congestion_table_thresholds_info].values[5].doc = "Indicates if the threshold controls DCH or DCML blocks.";
    submodule_data->tables[dnxf_data_fabric_congestion_table_thresholds_info].values[5].offset = UTILEX_OFFSETOF(dnxf_data_fabric_congestion_thresholds_info_t, is_tx);
    submodule_data->tables[dnxf_data_fabric_congestion_table_thresholds_info].values[6].name = "th_validity_bmp";
    submodule_data->tables[dnxf_data_fabric_congestion_table_thresholds_info].values[6].type = "uint32";
    submodule_data->tables[dnxf_data_fabric_congestion_table_thresholds_info].values[6].doc = "Additional threshold checks.";
    submodule_data->tables[dnxf_data_fabric_congestion_table_thresholds_info].values[6].offset = UTILEX_OFFSETOF(dnxf_data_fabric_congestion_thresholds_info_t, th_validity_bmp);
    submodule_data->tables[dnxf_data_fabric_congestion_table_thresholds_info].values[7].name = "is_to_be_displayed";
    submodule_data->tables[dnxf_data_fabric_congestion_table_thresholds_info].values[7].type = "uint32";
    submodule_data->tables[dnxf_data_fabric_congestion_table_thresholds_info].values[7].doc = "Indicates if the threshold should be displaied in the diagnostic";
    submodule_data->tables[dnxf_data_fabric_congestion_table_thresholds_info].values[7].offset = UTILEX_OFFSETOF(dnxf_data_fabric_congestion_thresholds_info_t, is_to_be_displayed);


exit:
    SHR_FUNC_EXIT;
}


int
dnxf_data_fabric_congestion_feature_get(
    int unit,
    dnxf_data_fabric_congestion_feature_e feature)
{
    return dnxc_data_mgmt_feature_data_get(unit, dnxf_data_module_fabric, dnxf_data_fabric_submodule_congestion, feature);
}


uint32
dnxf_data_fabric_congestion_nof_profiles_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnxf_data_module_fabric, dnxf_data_fabric_submodule_congestion, dnxf_data_fabric_congestion_define_nof_profiles);
}

uint32
dnxf_data_fabric_congestion_nof_threshold_priorities_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnxf_data_module_fabric, dnxf_data_fabric_submodule_congestion, dnxf_data_fabric_congestion_define_nof_threshold_priorities);
}

uint32
dnxf_data_fabric_congestion_nof_threshold_levels_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnxf_data_module_fabric, dnxf_data_fabric_submodule_congestion, dnxf_data_fabric_congestion_define_nof_threshold_levels);
}

uint32
dnxf_data_fabric_congestion_nof_threshold_index_dimensions_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnxf_data_module_fabric, dnxf_data_fabric_submodule_congestion, dnxf_data_fabric_congestion_define_nof_threshold_index_dimensions);
}

uint32
dnxf_data_fabric_congestion_nof_dfl_banks_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnxf_data_module_fabric, dnxf_data_fabric_submodule_congestion, dnxf_data_fabric_congestion_define_nof_dfl_banks);
}

uint32
dnxf_data_fabric_congestion_nof_dfl_sub_banks_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnxf_data_module_fabric, dnxf_data_fabric_submodule_congestion, dnxf_data_fabric_congestion_define_nof_dfl_sub_banks);
}

uint32
dnxf_data_fabric_congestion_nof_dfl_bank_entries_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnxf_data_module_fabric, dnxf_data_fabric_submodule_congestion, dnxf_data_fabric_congestion_define_nof_dfl_bank_entries);
}

uint32
dnxf_data_fabric_congestion_nof_rci_bits_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnxf_data_module_fabric, dnxf_data_fabric_submodule_congestion, dnxf_data_fabric_congestion_define_nof_rci_bits);
}

uint32
dnxf_data_fabric_congestion_max_wfq_weight_value_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnxf_data_module_fabric, dnxf_data_fabric_submodule_congestion, dnxf_data_fabric_congestion_define_max_wfq_weight_value);
}

uint32
dnxf_data_fabric_congestion_llfc_type_default_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnxf_data_module_fabric, dnxf_data_fabric_submodule_congestion, dnxf_data_fabric_congestion_define_llfc_type_default);
}



const dnxf_data_fabric_congestion_thresholds_info_t *
dnxf_data_fabric_congestion_thresholds_info_get(
    int unit,
    int threshold_id)
{
    char *data;
    dnxc_data_table_t *table;

    
    table = dnxc_data_mgmt_table_get(unit, dnxf_data_module_fabric, dnxf_data_fabric_submodule_congestion, dnxf_data_fabric_congestion_table_thresholds_info);
    
    data = dnxc_data_mgmt_table_data_get(unit, table, threshold_id, 0);
    return (const dnxf_data_fabric_congestion_thresholds_info_t *) data;

}


shr_error_e
dnxf_data_fabric_congestion_thresholds_info_entry_str_get(
    int unit,
    char *buffer,
    int key0,
    int key1,
    int value_index)
{
    dnxc_data_table_t *table;
    const dnxf_data_fabric_congestion_thresholds_info_t *data;
    SHR_FUNC_INIT_VARS(unit);

    
    table = dnxc_data_mgmt_table_get(unit, dnxf_data_module_fabric, dnxf_data_fabric_submodule_congestion, dnxf_data_fabric_congestion_table_thresholds_info);
    data = (const dnxf_data_fabric_congestion_thresholds_info_t *) dnxc_data_mgmt_table_data_diag_get(unit, table, key0, 0);
    switch (value_index)
    {
        case 0:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%s", data->threshold_str == NULL ? "" : data->threshold_str);
            break;
        case 1:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->threshold_group);
            break;
        case 2:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->threshold_stage);
            break;
        case 3:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->index_type);
            break;
        case 4:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->supported_flags);
            break;
        case 5:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->is_tx);
            break;
        case 6:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->th_validity_bmp);
            break;
        case 7:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->is_to_be_displayed);
            break;
    }

    SHR_FUNC_EXIT;
}


const dnxc_data_table_info_t *
dnxf_data_fabric_congestion_thresholds_info_info_get(
    int unit)
{

    
    return dnxc_data_mgmt_table_info_get(unit, dnxf_data_module_fabric, dnxf_data_fabric_submodule_congestion, dnxf_data_fabric_congestion_table_thresholds_info);

}






static shr_error_e
dnxf_data_fabric_cell_init(
    int unit,
    dnxc_data_submodule_t *submodule_data)
{
    SHR_FUNC_INIT_VARS(unit);

    submodule_data->name = "cell";
    submodule_data->doc = "General cell attributes";
    
    submodule_data->nof_features = _dnxf_data_fabric_cell_feature_nof;
    DNXC_DATA_ALLOC(submodule_data->features, dnxc_data_feature_t,  submodule_data->nof_features, "_dnxc_data fabric cell features");

    submodule_data->features[dnxf_data_fabric_cell_format_always_with_pcp].name = "format_always_with_pcp";
    submodule_data->features[dnxf_data_fabric_cell_format_always_with_pcp].doc = "PCP couldn't be excluded from cell format";
    submodule_data->features[dnxf_data_fabric_cell_format_always_with_pcp].flags |= DNXC_DATA_F_FEATURE;

    
    submodule_data->nof_defines = _dnxf_data_fabric_cell_define_nof;
    DNXC_DATA_ALLOC(submodule_data->defines, dnxc_data_define_t, submodule_data->nof_defines, "_dnxc_data fabric cell defines");

    submodule_data->defines[dnxf_data_fabric_cell_define_max_vsc_format_size].name = "max_vsc_format_size";
    submodule_data->defines[dnxf_data_fabric_cell_define_max_vsc_format_size].doc = "Maximum VSC cell format supported for the device (e.g v256, v512)";
    
    submodule_data->defines[dnxf_data_fabric_cell_define_max_vsc_format_size].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnxf_data_fabric_cell_define_fifo_dma_fabric_cell_nof_entries_per_cell].name = "fifo_dma_fabric_cell_nof_entries_per_cell";
    submodule_data->defines[dnxf_data_fabric_cell_define_fifo_dma_fabric_cell_nof_entries_per_cell].doc = "Number of entries per one cell (chunk).";
    submodule_data->defines[dnxf_data_fabric_cell_define_fifo_dma_fabric_cell_nof_entries_per_cell].labels[0] = "data_notrev";
    
    submodule_data->defines[dnxf_data_fabric_cell_define_fifo_dma_fabric_cell_nof_entries_per_cell].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnxf_data_fabric_cell_define_rx_cpu_cell_max_payload_size].name = "rx_cpu_cell_max_payload_size";
    submodule_data->defines[dnxf_data_fabric_cell_define_rx_cpu_cell_max_payload_size].doc = "Payload size of data cpu cells (bits).";
    submodule_data->defines[dnxf_data_fabric_cell_define_rx_cpu_cell_max_payload_size].labels[0] = "data_notrev";
    
    submodule_data->defines[dnxf_data_fabric_cell_define_rx_cpu_cell_max_payload_size].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnxf_data_fabric_cell_define_rx_max_nof_cpu_buffers].name = "rx_max_nof_cpu_buffers";
    submodule_data->defines[dnxf_data_fabric_cell_define_rx_max_nof_cpu_buffers].doc = "Number of rx CPU buffers.";
    submodule_data->defines[dnxf_data_fabric_cell_define_rx_max_nof_cpu_buffers].labels[0] = "data_notrev";
    
    submodule_data->defines[dnxf_data_fabric_cell_define_rx_max_nof_cpu_buffers].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnxf_data_fabric_cell_define_source_routed_cells_header_offset].name = "source_routed_cells_header_offset";
    submodule_data->defines[dnxf_data_fabric_cell_define_source_routed_cells_header_offset].doc = "Offset in the header fields of sr cells.";
    submodule_data->defines[dnxf_data_fabric_cell_define_source_routed_cells_header_offset].labels[0] = "data_notrev";
    
    submodule_data->defines[dnxf_data_fabric_cell_define_source_routed_cells_header_offset].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnxf_data_fabric_cell_define_fifo_dma_nof_channels].name = "fifo_dma_nof_channels";
    submodule_data->defines[dnxf_data_fabric_cell_define_fifo_dma_nof_channels].doc = "Number of channels used for fifo DMA.";
    submodule_data->defines[dnxf_data_fabric_cell_define_fifo_dma_nof_channels].labels[0] = "data_notrev";
    
    submodule_data->defines[dnxf_data_fabric_cell_define_fifo_dma_nof_channels].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnxf_data_fabric_cell_define_fifo_dma_entry_size].name = "fifo_dma_entry_size";
    submodule_data->defines[dnxf_data_fabric_cell_define_fifo_dma_entry_size].doc = "DMA entry size in bytes";
    submodule_data->defines[dnxf_data_fabric_cell_define_fifo_dma_entry_size].labels[0] = "data_notrev";
    
    submodule_data->defines[dnxf_data_fabric_cell_define_fifo_dma_entry_size].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnxf_data_fabric_cell_define_fifo_dma_max_nof_entries].name = "fifo_dma_max_nof_entries";
    submodule_data->defines[dnxf_data_fabric_cell_define_fifo_dma_max_nof_entries].doc = "MAX number of entries in DMA buffer.";
    submodule_data->defines[dnxf_data_fabric_cell_define_fifo_dma_max_nof_entries].labels[0] = "data_notrev";
    
    submodule_data->defines[dnxf_data_fabric_cell_define_fifo_dma_max_nof_entries].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnxf_data_fabric_cell_define_fifo_dma_min_nof_entries].name = "fifo_dma_min_nof_entries";
    submodule_data->defines[dnxf_data_fabric_cell_define_fifo_dma_min_nof_entries].doc = "MIN number of entries in DMA buffer.";
    submodule_data->defines[dnxf_data_fabric_cell_define_fifo_dma_min_nof_entries].labels[0] = "data_notrev";
    
    submodule_data->defines[dnxf_data_fabric_cell_define_fifo_dma_min_nof_entries].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnxf_data_fabric_cell_define_fifo_dma_enable].name = "fifo_dma_enable";
    submodule_data->defines[dnxf_data_fabric_cell_define_fifo_dma_enable].doc = "Deterimins if to use or not to use FIFO DMA.";
    submodule_data->defines[dnxf_data_fabric_cell_define_fifo_dma_enable].labels[0] = "data_notrev";
    
    submodule_data->defines[dnxf_data_fabric_cell_define_fifo_dma_enable].flags |= DNXC_DATA_F_NUMERIC;

    submodule_data->defines[dnxf_data_fabric_cell_define_fifo_dma_buffer_size].name = "fifo_dma_buffer_size";
    submodule_data->defines[dnxf_data_fabric_cell_define_fifo_dma_buffer_size].doc = "Size of the host memory stored allocated by the CPU.";
    submodule_data->defines[dnxf_data_fabric_cell_define_fifo_dma_buffer_size].labels[0] = "data_notrev";
    
    submodule_data->defines[dnxf_data_fabric_cell_define_fifo_dma_buffer_size].flags |= DNXC_DATA_F_NUMERIC;

    submodule_data->defines[dnxf_data_fabric_cell_define_fifo_dma_threshold].name = "fifo_dma_threshold";
    submodule_data->defines[dnxf_data_fabric_cell_define_fifo_dma_threshold].doc = "The number of writes by the DMA until a threshold based interrupt is triggered";
    submodule_data->defines[dnxf_data_fabric_cell_define_fifo_dma_threshold].labels[0] = "data_notrev";
    
    submodule_data->defines[dnxf_data_fabric_cell_define_fifo_dma_threshold].flags |= DNXC_DATA_F_NUMERIC;

    submodule_data->defines[dnxf_data_fabric_cell_define_fifo_dma_timeout].name = "fifo_dma_timeout";
    submodule_data->defines[dnxf_data_fabric_cell_define_fifo_dma_timeout].doc = "The amount of time in microseconds that passes from the first write by the DMA until a timeout based interrupt is triggered.";
    submodule_data->defines[dnxf_data_fabric_cell_define_fifo_dma_timeout].labels[0] = "data_notrev";
    
    submodule_data->defines[dnxf_data_fabric_cell_define_fifo_dma_timeout].flags |= DNXC_DATA_F_NUMERIC;

    submodule_data->defines[dnxf_data_fabric_cell_define_rx_thread_pri].name = "rx_thread_pri";
    submodule_data->defines[dnxf_data_fabric_cell_define_rx_thread_pri].doc = "Rx thread priority.";
    submodule_data->defines[dnxf_data_fabric_cell_define_rx_thread_pri].labels[0] = "data_notrev";
    
    submodule_data->defines[dnxf_data_fabric_cell_define_rx_thread_pri].flags |= DNXC_DATA_F_NUMERIC;

    
    submodule_data->nof_tables = _dnxf_data_fabric_cell_table_nof;
    DNXC_DATA_ALLOC(submodule_data->tables, dnxc_data_table_t, submodule_data->nof_tables, "_dnxc_data fabric cell tables");

    
    submodule_data->tables[dnxf_data_fabric_cell_table_cell_match_filter_reg_mask].name = "cell_match_filter_reg_mask";
    submodule_data->tables[dnxf_data_fabric_cell_table_cell_match_filter_reg_mask].doc = "register mask for cell filter types";
    submodule_data->tables[dnxf_data_fabric_cell_table_cell_match_filter_reg_mask].flags |= DNXC_DATA_F_TABLE;
    submodule_data->tables[dnxf_data_fabric_cell_table_cell_match_filter_reg_mask].size_of_values = sizeof(dnxf_data_fabric_cell_cell_match_filter_reg_mask_t);
    submodule_data->tables[dnxf_data_fabric_cell_table_cell_match_filter_reg_mask].entry_get = dnxf_data_fabric_cell_cell_match_filter_reg_mask_entry_str_get;

    
    submodule_data->tables[dnxf_data_fabric_cell_table_cell_match_filter_reg_mask].nof_keys = 1;
    submodule_data->tables[dnxf_data_fabric_cell_table_cell_match_filter_reg_mask].keys[0].name = "filter_type";
    submodule_data->tables[dnxf_data_fabric_cell_table_cell_match_filter_reg_mask].keys[0].doc = "type of cell filter";

    
    submodule_data->tables[dnxf_data_fabric_cell_table_cell_match_filter_reg_mask].nof_values = 3;
    DNXC_DATA_ALLOC(submodule_data->tables[dnxf_data_fabric_cell_table_cell_match_filter_reg_mask].values, dnxc_data_value_t, submodule_data->tables[dnxf_data_fabric_cell_table_cell_match_filter_reg_mask].nof_values, "_dnxf_data_fabric_cell_table_cell_match_filter_reg_mask table values");
    submodule_data->tables[dnxf_data_fabric_cell_table_cell_match_filter_reg_mask].values[0].name = "start_bit";
    submodule_data->tables[dnxf_data_fabric_cell_table_cell_match_filter_reg_mask].values[0].type = "uint32";
    submodule_data->tables[dnxf_data_fabric_cell_table_cell_match_filter_reg_mask].values[0].doc = "starting bit in register";
    submodule_data->tables[dnxf_data_fabric_cell_table_cell_match_filter_reg_mask].values[0].offset = UTILEX_OFFSETOF(dnxf_data_fabric_cell_cell_match_filter_reg_mask_t, start_bit);
    submodule_data->tables[dnxf_data_fabric_cell_table_cell_match_filter_reg_mask].values[1].name = "bit_length";
    submodule_data->tables[dnxf_data_fabric_cell_table_cell_match_filter_reg_mask].values[1].type = "uint32";
    submodule_data->tables[dnxf_data_fabric_cell_table_cell_match_filter_reg_mask].values[1].doc = "bit length of in register";
    submodule_data->tables[dnxf_data_fabric_cell_table_cell_match_filter_reg_mask].values[1].offset = UTILEX_OFFSETOF(dnxf_data_fabric_cell_cell_match_filter_reg_mask_t, bit_length);
    submodule_data->tables[dnxf_data_fabric_cell_table_cell_match_filter_reg_mask].values[2].name = "mask";
    submodule_data->tables[dnxf_data_fabric_cell_table_cell_match_filter_reg_mask].values[2].type = "uint32";
    submodule_data->tables[dnxf_data_fabric_cell_table_cell_match_filter_reg_mask].values[2].doc = "mask in register, must be bitwise inverted in code";
    submodule_data->tables[dnxf_data_fabric_cell_table_cell_match_filter_reg_mask].values[2].offset = UTILEX_OFFSETOF(dnxf_data_fabric_cell_cell_match_filter_reg_mask_t, mask);


exit:
    SHR_FUNC_EXIT;
}


int
dnxf_data_fabric_cell_feature_get(
    int unit,
    dnxf_data_fabric_cell_feature_e feature)
{
    return dnxc_data_mgmt_feature_data_get(unit, dnxf_data_module_fabric, dnxf_data_fabric_submodule_cell, feature);
}


uint32
dnxf_data_fabric_cell_max_vsc_format_size_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnxf_data_module_fabric, dnxf_data_fabric_submodule_cell, dnxf_data_fabric_cell_define_max_vsc_format_size);
}

uint32
dnxf_data_fabric_cell_fifo_dma_fabric_cell_nof_entries_per_cell_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnxf_data_module_fabric, dnxf_data_fabric_submodule_cell, dnxf_data_fabric_cell_define_fifo_dma_fabric_cell_nof_entries_per_cell);
}

uint32
dnxf_data_fabric_cell_rx_cpu_cell_max_payload_size_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnxf_data_module_fabric, dnxf_data_fabric_submodule_cell, dnxf_data_fabric_cell_define_rx_cpu_cell_max_payload_size);
}

uint32
dnxf_data_fabric_cell_rx_max_nof_cpu_buffers_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnxf_data_module_fabric, dnxf_data_fabric_submodule_cell, dnxf_data_fabric_cell_define_rx_max_nof_cpu_buffers);
}

uint32
dnxf_data_fabric_cell_source_routed_cells_header_offset_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnxf_data_module_fabric, dnxf_data_fabric_submodule_cell, dnxf_data_fabric_cell_define_source_routed_cells_header_offset);
}

uint32
dnxf_data_fabric_cell_fifo_dma_nof_channels_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnxf_data_module_fabric, dnxf_data_fabric_submodule_cell, dnxf_data_fabric_cell_define_fifo_dma_nof_channels);
}

uint32
dnxf_data_fabric_cell_fifo_dma_entry_size_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnxf_data_module_fabric, dnxf_data_fabric_submodule_cell, dnxf_data_fabric_cell_define_fifo_dma_entry_size);
}

uint32
dnxf_data_fabric_cell_fifo_dma_max_nof_entries_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnxf_data_module_fabric, dnxf_data_fabric_submodule_cell, dnxf_data_fabric_cell_define_fifo_dma_max_nof_entries);
}

uint32
dnxf_data_fabric_cell_fifo_dma_min_nof_entries_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnxf_data_module_fabric, dnxf_data_fabric_submodule_cell, dnxf_data_fabric_cell_define_fifo_dma_min_nof_entries);
}

uint32
dnxf_data_fabric_cell_fifo_dma_enable_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnxf_data_module_fabric, dnxf_data_fabric_submodule_cell, dnxf_data_fabric_cell_define_fifo_dma_enable);
}

uint32
dnxf_data_fabric_cell_fifo_dma_buffer_size_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnxf_data_module_fabric, dnxf_data_fabric_submodule_cell, dnxf_data_fabric_cell_define_fifo_dma_buffer_size);
}

uint32
dnxf_data_fabric_cell_fifo_dma_threshold_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnxf_data_module_fabric, dnxf_data_fabric_submodule_cell, dnxf_data_fabric_cell_define_fifo_dma_threshold);
}

uint32
dnxf_data_fabric_cell_fifo_dma_timeout_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnxf_data_module_fabric, dnxf_data_fabric_submodule_cell, dnxf_data_fabric_cell_define_fifo_dma_timeout);
}

uint32
dnxf_data_fabric_cell_rx_thread_pri_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnxf_data_module_fabric, dnxf_data_fabric_submodule_cell, dnxf_data_fabric_cell_define_rx_thread_pri);
}



const dnxf_data_fabric_cell_cell_match_filter_reg_mask_t *
dnxf_data_fabric_cell_cell_match_filter_reg_mask_get(
    int unit,
    int filter_type)
{
    char *data;
    dnxc_data_table_t *table;

    
    table = dnxc_data_mgmt_table_get(unit, dnxf_data_module_fabric, dnxf_data_fabric_submodule_cell, dnxf_data_fabric_cell_table_cell_match_filter_reg_mask);
    
    data = dnxc_data_mgmt_table_data_get(unit, table, filter_type, 0);
    return (const dnxf_data_fabric_cell_cell_match_filter_reg_mask_t *) data;

}


shr_error_e
dnxf_data_fabric_cell_cell_match_filter_reg_mask_entry_str_get(
    int unit,
    char *buffer,
    int key0,
    int key1,
    int value_index)
{
    dnxc_data_table_t *table;
    const dnxf_data_fabric_cell_cell_match_filter_reg_mask_t *data;
    SHR_FUNC_INIT_VARS(unit);

    
    table = dnxc_data_mgmt_table_get(unit, dnxf_data_module_fabric, dnxf_data_fabric_submodule_cell, dnxf_data_fabric_cell_table_cell_match_filter_reg_mask);
    data = (const dnxf_data_fabric_cell_cell_match_filter_reg_mask_t *) dnxc_data_mgmt_table_data_diag_get(unit, table, key0, 0);
    switch (value_index)
    {
        case 0:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->start_bit);
            break;
        case 1:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->bit_length);
            break;
        case 2:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->mask);
            break;
    }

    SHR_FUNC_EXIT;
}


const dnxc_data_table_info_t *
dnxf_data_fabric_cell_cell_match_filter_reg_mask_info_get(
    int unit)
{

    
    return dnxc_data_mgmt_table_info_get(unit, dnxf_data_module_fabric, dnxf_data_fabric_submodule_cell, dnxf_data_fabric_cell_table_cell_match_filter_reg_mask);

}






static shr_error_e
dnxf_data_fabric_topology_init(
    int unit,
    dnxc_data_submodule_t *submodule_data)
{
    SHR_FUNC_INIT_VARS(unit);

    submodule_data->name = "topology";
    submodule_data->doc = "General topology attributes";
    
    submodule_data->nof_features = _dnxf_data_fabric_topology_feature_nof;
    DNXC_DATA_ALLOC(submodule_data->features, dnxc_data_feature_t,  submodule_data->nof_features, "_dnxc_data fabric topology features");

    
    submodule_data->nof_defines = _dnxf_data_fabric_topology_define_nof;
    DNXC_DATA_ALLOC(submodule_data->defines, dnxc_data_define_t, submodule_data->nof_defines, "_dnxc_data fabric topology defines");

    submodule_data->defines[dnxf_data_fabric_topology_define_max_link_score].name = "max_link_score";
    submodule_data->defines[dnxf_data_fabric_topology_define_max_link_score].doc = "Max link score.";
    submodule_data->defines[dnxf_data_fabric_topology_define_max_link_score].labels[0] = "data_notrev";
    
    submodule_data->defines[dnxf_data_fabric_topology_define_max_link_score].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnxf_data_fabric_topology_define_nof_system_modid].name = "nof_system_modid";
    submodule_data->defines[dnxf_data_fabric_topology_define_nof_system_modid].doc = "Number of system modids.";
    
    submodule_data->defines[dnxf_data_fabric_topology_define_nof_system_modid].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnxf_data_fabric_topology_define_nof_local_modid].name = "nof_local_modid";
    submodule_data->defines[dnxf_data_fabric_topology_define_nof_local_modid].doc = "Number of local modids.";
    
    submodule_data->defines[dnxf_data_fabric_topology_define_nof_local_modid].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnxf_data_fabric_topology_define_nof_local_modid_fe13].name = "nof_local_modid_fe13";
    submodule_data->defines[dnxf_data_fabric_topology_define_nof_local_modid_fe13].doc = "Number of local modids in FE13 mode.";
    
    submodule_data->defines[dnxf_data_fabric_topology_define_nof_local_modid_fe13].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnxf_data_fabric_topology_define_all_reachable_fap_group_size].name = "all_reachable_fap_group_size";
    submodule_data->defines[dnxf_data_fabric_topology_define_all_reachable_fap_group_size].doc = "Fap group granularity for all-reachable vector.";
    
    submodule_data->defines[dnxf_data_fabric_topology_define_all_reachable_fap_group_size].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnxf_data_fabric_topology_define_all_reachable_max_nof_ignore_faps].name = "all_reachable_max_nof_ignore_faps";
    submodule_data->defines[dnxf_data_fabric_topology_define_all_reachable_max_nof_ignore_faps].doc = "Max number of all faps to ignore in the all-reachable vector.";
    
    submodule_data->defines[dnxf_data_fabric_topology_define_all_reachable_max_nof_ignore_faps].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnxf_data_fabric_topology_define_load_balancing_mode].name = "load_balancing_mode";
    submodule_data->defines[dnxf_data_fabric_topology_define_load_balancing_mode].doc = "Sets the load balancing method.";
    submodule_data->defines[dnxf_data_fabric_topology_define_load_balancing_mode].labels[0] = "data_notrev";
    
    submodule_data->defines[dnxf_data_fabric_topology_define_load_balancing_mode].flags |= DNXC_DATA_F_NUMERIC;

    
    submodule_data->nof_tables = _dnxf_data_fabric_topology_table_nof;
    DNXC_DATA_ALLOC(submodule_data->tables, dnxc_data_table_t, submodule_data->nof_tables, "_dnxc_data fabric topology tables");


exit:
    SHR_FUNC_EXIT;
}


int
dnxf_data_fabric_topology_feature_get(
    int unit,
    dnxf_data_fabric_topology_feature_e feature)
{
    return dnxc_data_mgmt_feature_data_get(unit, dnxf_data_module_fabric, dnxf_data_fabric_submodule_topology, feature);
}


uint32
dnxf_data_fabric_topology_max_link_score_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnxf_data_module_fabric, dnxf_data_fabric_submodule_topology, dnxf_data_fabric_topology_define_max_link_score);
}

uint32
dnxf_data_fabric_topology_nof_system_modid_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnxf_data_module_fabric, dnxf_data_fabric_submodule_topology, dnxf_data_fabric_topology_define_nof_system_modid);
}

uint32
dnxf_data_fabric_topology_nof_local_modid_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnxf_data_module_fabric, dnxf_data_fabric_submodule_topology, dnxf_data_fabric_topology_define_nof_local_modid);
}

uint32
dnxf_data_fabric_topology_nof_local_modid_fe13_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnxf_data_module_fabric, dnxf_data_fabric_submodule_topology, dnxf_data_fabric_topology_define_nof_local_modid_fe13);
}

uint32
dnxf_data_fabric_topology_all_reachable_fap_group_size_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnxf_data_module_fabric, dnxf_data_fabric_submodule_topology, dnxf_data_fabric_topology_define_all_reachable_fap_group_size);
}

uint32
dnxf_data_fabric_topology_all_reachable_max_nof_ignore_faps_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnxf_data_module_fabric, dnxf_data_fabric_submodule_topology, dnxf_data_fabric_topology_define_all_reachable_max_nof_ignore_faps);
}

uint32
dnxf_data_fabric_topology_load_balancing_mode_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnxf_data_module_fabric, dnxf_data_fabric_submodule_topology, dnxf_data_fabric_topology_define_load_balancing_mode);
}










static shr_error_e
dnxf_data_fabric_gpd_init(
    int unit,
    dnxc_data_submodule_t *submodule_data)
{
    SHR_FUNC_INIT_VARS(unit);

    submodule_data->name = "gpd";
    submodule_data->doc = "General graceful power down attributes";
    
    submodule_data->nof_features = _dnxf_data_fabric_gpd_feature_nof;
    DNXC_DATA_ALLOC(submodule_data->features, dnxc_data_feature_t,  submodule_data->nof_features, "_dnxc_data fabric gpd features");

    
    submodule_data->nof_defines = _dnxf_data_fabric_gpd_define_nof;
    DNXC_DATA_ALLOC(submodule_data->defines, dnxc_data_define_t, submodule_data->nof_defines, "_dnxc_data fabric gpd defines");

    submodule_data->defines[dnxf_data_fabric_gpd_define_in_time].name = "in_time";
    submodule_data->defines[dnxf_data_fabric_gpd_define_in_time].doc = "Time interval between 2 GPD cells to enter GPD mode (usec).";
    
    submodule_data->defines[dnxf_data_fabric_gpd_define_in_time].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnxf_data_fabric_gpd_define_out_time].name = "out_time";
    submodule_data->defines[dnxf_data_fabric_gpd_define_out_time].doc = "Time to get out of GPD mode if no GPD cells arrived (msec).";
    
    submodule_data->defines[dnxf_data_fabric_gpd_define_out_time].flags |= DNXC_DATA_F_DEFINE;

    
    submodule_data->nof_tables = _dnxf_data_fabric_gpd_table_nof;
    DNXC_DATA_ALLOC(submodule_data->tables, dnxc_data_table_t, submodule_data->nof_tables, "_dnxc_data fabric gpd tables");


exit:
    SHR_FUNC_EXIT;
}


int
dnxf_data_fabric_gpd_feature_get(
    int unit,
    dnxf_data_fabric_gpd_feature_e feature)
{
    return dnxc_data_mgmt_feature_data_get(unit, dnxf_data_module_fabric, dnxf_data_fabric_submodule_gpd, feature);
}


uint32
dnxf_data_fabric_gpd_in_time_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnxf_data_module_fabric, dnxf_data_fabric_submodule_gpd, dnxf_data_fabric_gpd_define_in_time);
}

uint32
dnxf_data_fabric_gpd_out_time_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnxf_data_module_fabric, dnxf_data_fabric_submodule_gpd, dnxf_data_fabric_gpd_define_out_time);
}










static shr_error_e
dnxf_data_fabric_reachability_init(
    int unit,
    dnxc_data_submodule_t *submodule_data)
{
    SHR_FUNC_INIT_VARS(unit);

    submodule_data->name = "reachability";
    submodule_data->doc = "General reachability  attributes";
    
    submodule_data->nof_features = _dnxf_data_fabric_reachability_feature_nof;
    DNXC_DATA_ALLOC(submodule_data->features, dnxc_data_feature_t,  submodule_data->nof_features, "_dnxc_data fabric reachability features");

    
    submodule_data->nof_defines = _dnxf_data_fabric_reachability_define_nof;
    DNXC_DATA_ALLOC(submodule_data->defines, dnxc_data_define_t, submodule_data->nof_defines, "_dnxc_data fabric reachability defines");

    submodule_data->defines[dnxf_data_fabric_reachability_define_table_row_size_in_uint32].name = "table_row_size_in_uint32";
    submodule_data->defines[dnxf_data_fabric_reachability_define_table_row_size_in_uint32].doc = "RTP table Row Size in UINT32s.";
    
    submodule_data->defines[dnxf_data_fabric_reachability_define_table_row_size_in_uint32].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnxf_data_fabric_reachability_define_table_group_size].name = "table_group_size";
    submodule_data->defines[dnxf_data_fabric_reachability_define_table_group_size].doc = "RMHMT Group Size.";
    
    submodule_data->defines[dnxf_data_fabric_reachability_define_table_group_size].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnxf_data_fabric_reachability_define_rmgr_units].name = "rmgr_units";
    submodule_data->defines[dnxf_data_fabric_reachability_define_rmgr_units].doc = "RTP RMGR resolution.";
    
    submodule_data->defines[dnxf_data_fabric_reachability_define_rmgr_units].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnxf_data_fabric_reachability_define_gpd_rmgr_time_factor].name = "gpd_rmgr_time_factor";
    submodule_data->defines[dnxf_data_fabric_reachability_define_gpd_rmgr_time_factor].doc = "Factor waiting for the GPD to spread in the system.";
    
    submodule_data->defines[dnxf_data_fabric_reachability_define_gpd_rmgr_time_factor].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnxf_data_fabric_reachability_define_gen_rate_link_delta].name = "gen_rate_link_delta";
    submodule_data->defines[dnxf_data_fabric_reachability_define_gen_rate_link_delta].doc = "Reachability gen rate between links.";
    
    submodule_data->defines[dnxf_data_fabric_reachability_define_gen_rate_link_delta].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnxf_data_fabric_reachability_define_gen_rate_full_cycle].name = "gen_rate_full_cycle";
    submodule_data->defines[dnxf_data_fabric_reachability_define_gen_rate_full_cycle].doc = "RTP Reachability gen rate full cycle.";
    
    submodule_data->defines[dnxf_data_fabric_reachability_define_gen_rate_full_cycle].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnxf_data_fabric_reachability_define_gpd_gen_rate_full_cycle].name = "gpd_gen_rate_full_cycle";
    submodule_data->defines[dnxf_data_fabric_reachability_define_gpd_gen_rate_full_cycle].doc = "RTP GPD Reachability gen rate full cycle (nsec).";
    
    submodule_data->defines[dnxf_data_fabric_reachability_define_gpd_gen_rate_full_cycle].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnxf_data_fabric_reachability_define_watchdog_rate].name = "watchdog_rate";
    submodule_data->defines[dnxf_data_fabric_reachability_define_watchdog_rate].doc = "RTP Reachability watchdog rate.";
    
    submodule_data->defines[dnxf_data_fabric_reachability_define_watchdog_rate].flags |= DNXC_DATA_F_DEFINE;

    
    submodule_data->nof_tables = _dnxf_data_fabric_reachability_table_nof;
    DNXC_DATA_ALLOC(submodule_data->tables, dnxc_data_table_t, submodule_data->nof_tables, "_dnxc_data fabric reachability tables");


exit:
    SHR_FUNC_EXIT;
}


int
dnxf_data_fabric_reachability_feature_get(
    int unit,
    dnxf_data_fabric_reachability_feature_e feature)
{
    return dnxc_data_mgmt_feature_data_get(unit, dnxf_data_module_fabric, dnxf_data_fabric_submodule_reachability, feature);
}


uint32
dnxf_data_fabric_reachability_table_row_size_in_uint32_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnxf_data_module_fabric, dnxf_data_fabric_submodule_reachability, dnxf_data_fabric_reachability_define_table_row_size_in_uint32);
}

uint32
dnxf_data_fabric_reachability_table_group_size_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnxf_data_module_fabric, dnxf_data_fabric_submodule_reachability, dnxf_data_fabric_reachability_define_table_group_size);
}

uint32
dnxf_data_fabric_reachability_rmgr_units_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnxf_data_module_fabric, dnxf_data_fabric_submodule_reachability, dnxf_data_fabric_reachability_define_rmgr_units);
}

uint32
dnxf_data_fabric_reachability_gpd_rmgr_time_factor_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnxf_data_module_fabric, dnxf_data_fabric_submodule_reachability, dnxf_data_fabric_reachability_define_gpd_rmgr_time_factor);
}

uint32
dnxf_data_fabric_reachability_gen_rate_link_delta_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnxf_data_module_fabric, dnxf_data_fabric_submodule_reachability, dnxf_data_fabric_reachability_define_gen_rate_link_delta);
}

uint32
dnxf_data_fabric_reachability_gen_rate_full_cycle_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnxf_data_module_fabric, dnxf_data_fabric_submodule_reachability, dnxf_data_fabric_reachability_define_gen_rate_full_cycle);
}

uint32
dnxf_data_fabric_reachability_gpd_gen_rate_full_cycle_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnxf_data_module_fabric, dnxf_data_fabric_submodule_reachability, dnxf_data_fabric_reachability_define_gpd_gen_rate_full_cycle);
}

uint32
dnxf_data_fabric_reachability_watchdog_rate_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnxf_data_module_fabric, dnxf_data_fabric_submodule_reachability, dnxf_data_fabric_reachability_define_watchdog_rate);
}










static shr_error_e
dnxf_data_fabric_hw_snake_init(
    int unit,
    dnxc_data_submodule_t *submodule_data)
{
    SHR_FUNC_INIT_VARS(unit);

    submodule_data->name = "hw_snake";
    submodule_data->doc = "Internal HW snake test attributes";
    
    submodule_data->nof_features = _dnxf_data_fabric_hw_snake_feature_nof;
    DNXC_DATA_ALLOC(submodule_data->features, dnxc_data_feature_t,  submodule_data->nof_features, "_dnxc_data fabric hw_snake features");

    submodule_data->features[dnxf_data_fabric_hw_snake_is_sw_config_required].name = "is_sw_config_required";
    submodule_data->features[dnxf_data_fabric_hw_snake_is_sw_config_required].doc = "Shows if SW configuration is required";
    submodule_data->features[dnxf_data_fabric_hw_snake_is_sw_config_required].labels[0] = "data_notrev";
    submodule_data->features[dnxf_data_fabric_hw_snake_is_sw_config_required].flags |= DNXC_DATA_F_FEATURE;

    
    submodule_data->nof_defines = _dnxf_data_fabric_hw_snake_define_nof;
    DNXC_DATA_ALLOC(submodule_data->defines, dnxc_data_define_t, submodule_data->nof_defines, "_dnxc_data fabric hw_snake defines");

    
    submodule_data->nof_tables = _dnxf_data_fabric_hw_snake_table_nof;
    DNXC_DATA_ALLOC(submodule_data->tables, dnxc_data_table_t, submodule_data->nof_tables, "_dnxc_data fabric hw_snake tables");


exit:
    SHR_FUNC_EXIT;
}


int
dnxf_data_fabric_hw_snake_feature_get(
    int unit,
    dnxf_data_fabric_hw_snake_feature_e feature)
{
    return dnxc_data_mgmt_feature_data_get(unit, dnxf_data_module_fabric, dnxf_data_fabric_submodule_hw_snake, feature);
}











static shr_error_e
dnxf_data_fabric_system_upgrade_init(
    int unit,
    dnxc_data_submodule_t *submodule_data)
{
    SHR_FUNC_INIT_VARS(unit);

    submodule_data->name = "system_upgrade";
    submodule_data->doc = "fabric system upgrade";
    
    submodule_data->nof_features = _dnxf_data_fabric_system_upgrade_feature_nof;
    DNXC_DATA_ALLOC(submodule_data->features, dnxc_data_feature_t,  submodule_data->nof_features, "_dnxc_data fabric system_upgrade features");

    submodule_data->features[dnxf_data_fabric_system_upgrade_is_system_upgrade_supported].name = "is_system_upgrade_supported";
    submodule_data->features[dnxf_data_fabric_system_upgrade_is_system_upgrade_supported].doc = "Denotes whether device supports system upgrade procedure";
    submodule_data->features[dnxf_data_fabric_system_upgrade_is_system_upgrade_supported].flags |= DNXC_DATA_F_FEATURE;

    
    submodule_data->nof_defines = _dnxf_data_fabric_system_upgrade_define_nof;
    DNXC_DATA_ALLOC(submodule_data->defines, dnxc_data_define_t, submodule_data->nof_defines, "_dnxc_data fabric system_upgrade defines");

    submodule_data->defines[dnxf_data_fabric_system_upgrade_define_max_master_id].name = "max_master_id";
    submodule_data->defines[dnxf_data_fabric_system_upgrade_define_max_master_id].doc = "fabric system upgrade maximum master id";
    submodule_data->defines[dnxf_data_fabric_system_upgrade_define_max_master_id].labels[0] = "data_notrev";
    
    submodule_data->defines[dnxf_data_fabric_system_upgrade_define_max_master_id].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnxf_data_fabric_system_upgrade_define_param_0].name = "param_0";
    submodule_data->defines[dnxf_data_fabric_system_upgrade_define_param_0].doc = "fabric system upgrade param 0";
    submodule_data->defines[dnxf_data_fabric_system_upgrade_define_param_0].labels[0] = "data_notrev";
    
    submodule_data->defines[dnxf_data_fabric_system_upgrade_define_param_0].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnxf_data_fabric_system_upgrade_define_param_1].name = "param_1";
    submodule_data->defines[dnxf_data_fabric_system_upgrade_define_param_1].doc = "fabric system upgrade param 1";
    submodule_data->defines[dnxf_data_fabric_system_upgrade_define_param_1].labels[0] = "data_notrev";
    
    submodule_data->defines[dnxf_data_fabric_system_upgrade_define_param_1].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnxf_data_fabric_system_upgrade_define_param_2].name = "param_2";
    submodule_data->defines[dnxf_data_fabric_system_upgrade_define_param_2].doc = "fabric system upgrade param 2";
    submodule_data->defines[dnxf_data_fabric_system_upgrade_define_param_2].labels[0] = "data_notrev";
    
    submodule_data->defines[dnxf_data_fabric_system_upgrade_define_param_2].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnxf_data_fabric_system_upgrade_define_param_3].name = "param_3";
    submodule_data->defines[dnxf_data_fabric_system_upgrade_define_param_3].doc = "fabric system upgrade param 3";
    submodule_data->defines[dnxf_data_fabric_system_upgrade_define_param_3].labels[0] = "data_notrev";
    
    submodule_data->defines[dnxf_data_fabric_system_upgrade_define_param_3].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnxf_data_fabric_system_upgrade_define_param_4].name = "param_4";
    submodule_data->defines[dnxf_data_fabric_system_upgrade_define_param_4].doc = "fabric system upgrade param 4";
    submodule_data->defines[dnxf_data_fabric_system_upgrade_define_param_4].labels[0] = "data_notrev";
    
    submodule_data->defines[dnxf_data_fabric_system_upgrade_define_param_4].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnxf_data_fabric_system_upgrade_define_param_5].name = "param_5";
    submodule_data->defines[dnxf_data_fabric_system_upgrade_define_param_5].doc = "fabric system upgrade param 5";
    submodule_data->defines[dnxf_data_fabric_system_upgrade_define_param_5].labels[0] = "data_notrev";
    
    submodule_data->defines[dnxf_data_fabric_system_upgrade_define_param_5].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnxf_data_fabric_system_upgrade_define_param_7].name = "param_7";
    submodule_data->defines[dnxf_data_fabric_system_upgrade_define_param_7].doc = "fabric system upgrade param 7";
    submodule_data->defines[dnxf_data_fabric_system_upgrade_define_param_7].labels[0] = "data_notrev";
    
    submodule_data->defines[dnxf_data_fabric_system_upgrade_define_param_7].flags |= DNXC_DATA_F_DEFINE;

    
    submodule_data->nof_tables = _dnxf_data_fabric_system_upgrade_table_nof;
    DNXC_DATA_ALLOC(submodule_data->tables, dnxc_data_table_t, submodule_data->nof_tables, "_dnxc_data fabric system_upgrade tables");

    
    submodule_data->tables[dnxf_data_fabric_system_upgrade_table_target].name = "target";
    submodule_data->tables[dnxf_data_fabric_system_upgrade_table_target].doc = "fabric system upgrade target values";
    submodule_data->tables[dnxf_data_fabric_system_upgrade_table_target].labels[0] = "data_notrev";
    submodule_data->tables[dnxf_data_fabric_system_upgrade_table_target].flags |= DNXC_DATA_F_TABLE;
    submodule_data->tables[dnxf_data_fabric_system_upgrade_table_target].size_of_values = sizeof(dnxf_data_fabric_system_upgrade_target_t);
    submodule_data->tables[dnxf_data_fabric_system_upgrade_table_target].entry_get = dnxf_data_fabric_system_upgrade_target_entry_str_get;

    
    submodule_data->tables[dnxf_data_fabric_system_upgrade_table_target].nof_keys = 1;
    submodule_data->tables[dnxf_data_fabric_system_upgrade_table_target].keys[0].name = "target";
    submodule_data->tables[dnxf_data_fabric_system_upgrade_table_target].keys[0].doc = "target";

    
    submodule_data->tables[dnxf_data_fabric_system_upgrade_table_target].nof_values = 1;
    DNXC_DATA_ALLOC(submodule_data->tables[dnxf_data_fabric_system_upgrade_table_target].values, dnxc_data_value_t, submodule_data->tables[dnxf_data_fabric_system_upgrade_table_target].nof_values, "_dnxf_data_fabric_system_upgrade_table_target table values");
    submodule_data->tables[dnxf_data_fabric_system_upgrade_table_target].values[0].name = "value";
    submodule_data->tables[dnxf_data_fabric_system_upgrade_table_target].values[0].type = "uint32";
    submodule_data->tables[dnxf_data_fabric_system_upgrade_table_target].values[0].doc = "target value";
    submodule_data->tables[dnxf_data_fabric_system_upgrade_table_target].values[0].offset = UTILEX_OFFSETOF(dnxf_data_fabric_system_upgrade_target_t, value);


exit:
    SHR_FUNC_EXIT;
}


int
dnxf_data_fabric_system_upgrade_feature_get(
    int unit,
    dnxf_data_fabric_system_upgrade_feature_e feature)
{
    return dnxc_data_mgmt_feature_data_get(unit, dnxf_data_module_fabric, dnxf_data_fabric_submodule_system_upgrade, feature);
}


uint32
dnxf_data_fabric_system_upgrade_max_master_id_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnxf_data_module_fabric, dnxf_data_fabric_submodule_system_upgrade, dnxf_data_fabric_system_upgrade_define_max_master_id);
}

uint32
dnxf_data_fabric_system_upgrade_param_0_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnxf_data_module_fabric, dnxf_data_fabric_submodule_system_upgrade, dnxf_data_fabric_system_upgrade_define_param_0);
}

uint32
dnxf_data_fabric_system_upgrade_param_1_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnxf_data_module_fabric, dnxf_data_fabric_submodule_system_upgrade, dnxf_data_fabric_system_upgrade_define_param_1);
}

uint32
dnxf_data_fabric_system_upgrade_param_2_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnxf_data_module_fabric, dnxf_data_fabric_submodule_system_upgrade, dnxf_data_fabric_system_upgrade_define_param_2);
}

uint32
dnxf_data_fabric_system_upgrade_param_3_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnxf_data_module_fabric, dnxf_data_fabric_submodule_system_upgrade, dnxf_data_fabric_system_upgrade_define_param_3);
}

uint32
dnxf_data_fabric_system_upgrade_param_4_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnxf_data_module_fabric, dnxf_data_fabric_submodule_system_upgrade, dnxf_data_fabric_system_upgrade_define_param_4);
}

uint32
dnxf_data_fabric_system_upgrade_param_5_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnxf_data_module_fabric, dnxf_data_fabric_submodule_system_upgrade, dnxf_data_fabric_system_upgrade_define_param_5);
}

uint32
dnxf_data_fabric_system_upgrade_param_7_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnxf_data_module_fabric, dnxf_data_fabric_submodule_system_upgrade, dnxf_data_fabric_system_upgrade_define_param_7);
}



const dnxf_data_fabric_system_upgrade_target_t *
dnxf_data_fabric_system_upgrade_target_get(
    int unit,
    int target)
{
    char *data;
    dnxc_data_table_t *table;

    
    table = dnxc_data_mgmt_table_get(unit, dnxf_data_module_fabric, dnxf_data_fabric_submodule_system_upgrade, dnxf_data_fabric_system_upgrade_table_target);
    
    data = dnxc_data_mgmt_table_data_get(unit, table, target, 0);
    return (const dnxf_data_fabric_system_upgrade_target_t *) data;

}


shr_error_e
dnxf_data_fabric_system_upgrade_target_entry_str_get(
    int unit,
    char *buffer,
    int key0,
    int key1,
    int value_index)
{
    dnxc_data_table_t *table;
    const dnxf_data_fabric_system_upgrade_target_t *data;
    SHR_FUNC_INIT_VARS(unit);

    
    table = dnxc_data_mgmt_table_get(unit, dnxf_data_module_fabric, dnxf_data_fabric_submodule_system_upgrade, dnxf_data_fabric_system_upgrade_table_target);
    data = (const dnxf_data_fabric_system_upgrade_target_t *) dnxc_data_mgmt_table_data_diag_get(unit, table, key0, 0);
    switch (value_index)
    {
        case 0:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->value);
            break;
    }

    SHR_FUNC_EXIT;
}


const dnxc_data_table_info_t *
dnxf_data_fabric_system_upgrade_target_info_get(
    int unit)
{

    
    return dnxc_data_mgmt_table_info_get(unit, dnxf_data_module_fabric, dnxf_data_fabric_submodule_system_upgrade, dnxf_data_fabric_system_upgrade_table_target);

}






static shr_error_e
dnxf_data_fabric_regression_init(
    int unit,
    dnxc_data_submodule_t *submodule_data)
{
    SHR_FUNC_INIT_VARS(unit);

    submodule_data->name = "regression";
    submodule_data->doc = "defines used in regression tests";
    
    submodule_data->nof_features = _dnxf_data_fabric_regression_feature_nof;
    DNXC_DATA_ALLOC(submodule_data->features, dnxc_data_feature_t,  submodule_data->nof_features, "_dnxc_data fabric regression features");

    
    submodule_data->nof_defines = _dnxf_data_fabric_regression_define_nof;
    DNXC_DATA_ALLOC(submodule_data->defines, dnxc_data_define_t, submodule_data->nof_defines, "_dnxc_data fabric regression defines");

    submodule_data->defines[dnxf_data_fabric_regression_define_minimum_system_ref_clk].name = "minimum_system_ref_clk";
    submodule_data->defines[dnxf_data_fabric_regression_define_minimum_system_ref_clk].doc = "minimum system_ref_clk";
    
    submodule_data->defines[dnxf_data_fabric_regression_define_minimum_system_ref_clk].flags |= DNXC_DATA_F_DEFINE;

    
    submodule_data->nof_tables = _dnxf_data_fabric_regression_table_nof;
    DNXC_DATA_ALLOC(submodule_data->tables, dnxc_data_table_t, submodule_data->nof_tables, "_dnxc_data fabric regression tables");


exit:
    SHR_FUNC_EXIT;
}


int
dnxf_data_fabric_regression_feature_get(
    int unit,
    dnxf_data_fabric_regression_feature_e feature)
{
    return dnxc_data_mgmt_feature_data_get(unit, dnxf_data_module_fabric, dnxf_data_fabric_submodule_regression, feature);
}


uint32
dnxf_data_fabric_regression_minimum_system_ref_clk_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnxf_data_module_fabric, dnxf_data_fabric_submodule_regression, dnxf_data_fabric_regression_define_minimum_system_ref_clk);
}







shr_error_e
dnxf_data_fabric_init(
    int unit,
    dnxc_data_module_t *module_data)
{
    SHR_FUNC_INIT_VARS(unit);

    
    module_data->name = "fabric";
    module_data->nof_submodules = _dnxf_data_fabric_submodule_nof;
    DNXC_DATA_ALLOC(module_data->submodules, dnxc_data_submodule_t, module_data->nof_submodules, "_dnxc_data fabric submodules");

    
    SHR_IF_ERR_EXIT(dnxf_data_fabric_general_init(unit, &module_data->submodules[dnxf_data_fabric_submodule_general]));
    SHR_IF_ERR_EXIT(dnxf_data_fabric_pipes_init(unit, &module_data->submodules[dnxf_data_fabric_submodule_pipes]));
    SHR_IF_ERR_EXIT(dnxf_data_fabric_multicast_init(unit, &module_data->submodules[dnxf_data_fabric_submodule_multicast]));
    SHR_IF_ERR_EXIT(dnxf_data_fabric_fifos_init(unit, &module_data->submodules[dnxf_data_fabric_submodule_fifos]));
    SHR_IF_ERR_EXIT(dnxf_data_fabric_congestion_init(unit, &module_data->submodules[dnxf_data_fabric_submodule_congestion]));
    SHR_IF_ERR_EXIT(dnxf_data_fabric_cell_init(unit, &module_data->submodules[dnxf_data_fabric_submodule_cell]));
    SHR_IF_ERR_EXIT(dnxf_data_fabric_topology_init(unit, &module_data->submodules[dnxf_data_fabric_submodule_topology]));
    SHR_IF_ERR_EXIT(dnxf_data_fabric_gpd_init(unit, &module_data->submodules[dnxf_data_fabric_submodule_gpd]));
    SHR_IF_ERR_EXIT(dnxf_data_fabric_reachability_init(unit, &module_data->submodules[dnxf_data_fabric_submodule_reachability]));
    SHR_IF_ERR_EXIT(dnxf_data_fabric_hw_snake_init(unit, &module_data->submodules[dnxf_data_fabric_submodule_hw_snake]));
    SHR_IF_ERR_EXIT(dnxf_data_fabric_system_upgrade_init(unit, &module_data->submodules[dnxf_data_fabric_submodule_system_upgrade]));
    SHR_IF_ERR_EXIT(dnxf_data_fabric_regression_init(unit, &module_data->submodules[dnxf_data_fabric_submodule_regression]));
    
#ifdef BCM_DNXF1_SUPPORT

    if (dnxc_data_mgmt_is_ramon(unit))
    {
        SHR_IF_ERR_EXIT(ramon_a0_data_fabric_attach(unit));
    }
    else

#endif 
    {
        SHR_EXIT();
    }

exit:
    SHR_FUNC_EXIT;
}
#undef BSL_LOG_MODULE

