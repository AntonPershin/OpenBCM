
/* *INDENT-OFF* */
/*
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2022 Broadcom Inc. All rights reserved.
 */
#ifdef BSL_LOG_MODULE
#error "BSL_LOG_MODULE redefined"
#endif
#define BSL_LOG_MODULE BSL_LS_BCMDNX_PORT

#include <soc/dnx/dnx_data/auto_generated/dnx_data_internal_ingr_reassembly.h>




extern shr_error_e jr2_a0_data_ingr_reassembly_attach(
    int unit);


extern shr_error_e j2c_a0_data_ingr_reassembly_attach(
    int unit);


extern shr_error_e q2a_a0_data_ingr_reassembly_attach(
    int unit);


extern shr_error_e j2p_a0_data_ingr_reassembly_attach(
    int unit);


extern shr_error_e j2x_a0_data_ingr_reassembly_attach(
    int unit);




static shr_error_e
dnx_data_ingr_reassembly_general_init(
    int unit,
    dnxc_data_submodule_t *submodule_data)
{
    SHR_FUNC_INIT_VARS(unit);

    submodule_data->name = "general";
    submodule_data->doc = "";
    
    submodule_data->nof_features = _dnx_data_ingr_reassembly_general_feature_nof;
    DNXC_DATA_ALLOC(submodule_data->features, dnxc_data_feature_t,  submodule_data->nof_features, "_dnxc_data ingr_reassembly general features");

    submodule_data->features[dnx_data_ingr_reassembly_general_is_used].name = "is_used";
    submodule_data->features[dnx_data_ingr_reassembly_general_is_used].doc = "";
    submodule_data->features[dnx_data_ingr_reassembly_general_is_used].flags |= DNXC_DATA_F_FEATURE;

    submodule_data->features[dnx_data_ingr_reassembly_general_power_down_supported].name = "power_down_supported";
    submodule_data->features[dnx_data_ingr_reassembly_general_power_down_supported].doc = "";
    submodule_data->features[dnx_data_ingr_reassembly_general_power_down_supported].flags |= DNXC_DATA_F_FEATURE;

    
    submodule_data->nof_defines = _dnx_data_ingr_reassembly_general_define_nof;
    DNXC_DATA_ALLOC(submodule_data->defines, dnxc_data_define_t, submodule_data->nof_defines, "_dnxc_data ingr_reassembly general defines");

    
    submodule_data->nof_tables = _dnx_data_ingr_reassembly_general_table_nof;
    DNXC_DATA_ALLOC(submodule_data->tables, dnxc_data_table_t, submodule_data->nof_tables, "_dnxc_data ingr_reassembly general tables");


exit:
    SHR_FUNC_EXIT;
}


int
dnx_data_ingr_reassembly_general_feature_get(
    int unit,
    dnx_data_ingr_reassembly_general_feature_e feature)
{
    return dnxc_data_mgmt_feature_data_get(unit, dnx_data_module_ingr_reassembly, dnx_data_ingr_reassembly_submodule_general, feature);
}











static shr_error_e
dnx_data_ingr_reassembly_context_init(
    int unit,
    dnxc_data_submodule_t *submodule_data)
{
    SHR_FUNC_INIT_VARS(unit);

    submodule_data->name = "context";
    submodule_data->doc = "";
    
    submodule_data->nof_features = _dnx_data_ingr_reassembly_context_feature_nof;
    DNXC_DATA_ALLOC(submodule_data->features, dnxc_data_feature_t,  submodule_data->nof_features, "_dnxc_data ingr_reassembly context features");

    submodule_data->features[dnx_data_ingr_reassembly_context_rcy_interleaving_between_priorities].name = "rcy_interleaving_between_priorities";
    submodule_data->features[dnx_data_ingr_reassembly_context_rcy_interleaving_between_priorities].doc = "";
    submodule_data->features[dnx_data_ingr_reassembly_context_rcy_interleaving_between_priorities].flags |= DNXC_DATA_F_FEATURE;

    submodule_data->features[dnx_data_ingr_reassembly_context_direct_context_table].name = "direct_context_table";
    submodule_data->features[dnx_data_ingr_reassembly_context_direct_context_table].doc = "";
    submodule_data->features[dnx_data_ingr_reassembly_context_direct_context_table].flags |= DNXC_DATA_F_FEATURE;

    submodule_data->features[dnx_data_ingr_reassembly_context_port_termination_in_context_table].name = "port_termination_in_context_table";
    submodule_data->features[dnx_data_ingr_reassembly_context_port_termination_in_context_table].doc = "";
    submodule_data->features[dnx_data_ingr_reassembly_context_port_termination_in_context_table].flags |= DNXC_DATA_F_FEATURE;

    submodule_data->features[dnx_data_ingr_reassembly_context_pp_tm_context].name = "pp_tm_context";
    submodule_data->features[dnx_data_ingr_reassembly_context_pp_tm_context].doc = "";
    submodule_data->features[dnx_data_ingr_reassembly_context_pp_tm_context].flags |= DNXC_DATA_F_FEATURE;

    submodule_data->features[dnx_data_ingr_reassembly_context_reassembly_to_in_cgm_port_mapping].name = "reassembly_to_in_cgm_port_mapping";
    submodule_data->features[dnx_data_ingr_reassembly_context_reassembly_to_in_cgm_port_mapping].doc = "";
    submodule_data->features[dnx_data_ingr_reassembly_context_reassembly_to_in_cgm_port_mapping].flags |= DNXC_DATA_F_FEATURE;

    
    submodule_data->nof_defines = _dnx_data_ingr_reassembly_context_define_nof;
    DNXC_DATA_ALLOC(submodule_data->defines, dnxc_data_define_t, submodule_data->nof_defines, "_dnxc_data ingr_reassembly context defines");

    submodule_data->defines[dnx_data_ingr_reassembly_context_define_nof_contexts].name = "nof_contexts";
    submodule_data->defines[dnx_data_ingr_reassembly_context_define_nof_contexts].doc = "";
    
    submodule_data->defines[dnx_data_ingr_reassembly_context_define_nof_contexts].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_ingr_reassembly_context_define_invalid_context].name = "invalid_context";
    submodule_data->defines[dnx_data_ingr_reassembly_context_define_invalid_context].doc = "";
    
    submodule_data->defines[dnx_data_ingr_reassembly_context_define_invalid_context].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_ingr_reassembly_context_define_nof_cpu_channels_per_core].name = "nof_cpu_channels_per_core";
    submodule_data->defines[dnx_data_ingr_reassembly_context_define_nof_cpu_channels_per_core].doc = "";
    
    submodule_data->defines[dnx_data_ingr_reassembly_context_define_nof_cpu_channels_per_core].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_ingr_reassembly_context_define_reassembly_timeout].name = "reassembly_timeout";
    submodule_data->defines[dnx_data_ingr_reassembly_context_define_reassembly_timeout].doc = "";
    
    submodule_data->defines[dnx_data_ingr_reassembly_context_define_reassembly_timeout].flags |= DNXC_DATA_F_NUMERIC;

    submodule_data->defines[dnx_data_ingr_reassembly_context_define_rcy_unique_context].name = "rcy_unique_context";
    submodule_data->defines[dnx_data_ingr_reassembly_context_define_rcy_unique_context].doc = "";
    
    submodule_data->defines[dnx_data_ingr_reassembly_context_define_rcy_unique_context].flags |= DNXC_DATA_F_NUMERIC;

    
    submodule_data->nof_tables = _dnx_data_ingr_reassembly_context_table_nof;
    DNXC_DATA_ALLOC(submodule_data->tables, dnxc_data_table_t, submodule_data->nof_tables, "_dnxc_data ingr_reassembly context tables");

    
    submodule_data->tables[dnx_data_ingr_reassembly_context_table_context_map].name = "context_map";
    submodule_data->tables[dnx_data_ingr_reassembly_context_table_context_map].doc = "";
    submodule_data->tables[dnx_data_ingr_reassembly_context_table_context_map].flags |= DNXC_DATA_F_TABLE;
    submodule_data->tables[dnx_data_ingr_reassembly_context_table_context_map].size_of_values = sizeof(dnx_data_ingr_reassembly_context_context_map_t);
    submodule_data->tables[dnx_data_ingr_reassembly_context_table_context_map].entry_get = dnx_data_ingr_reassembly_context_context_map_entry_str_get;

    
    submodule_data->tables[dnx_data_ingr_reassembly_context_table_context_map].nof_keys = 2;
    submodule_data->tables[dnx_data_ingr_reassembly_context_table_context_map].keys[0].name = "port_type";
    submodule_data->tables[dnx_data_ingr_reassembly_context_table_context_map].keys[0].doc = "";
    submodule_data->tables[dnx_data_ingr_reassembly_context_table_context_map].keys[1].name = "is_mgmt";
    submodule_data->tables[dnx_data_ingr_reassembly_context_table_context_map].keys[1].doc = "";

    
    submodule_data->tables[dnx_data_ingr_reassembly_context_table_context_map].nof_values = 1;
    DNXC_DATA_ALLOC(submodule_data->tables[dnx_data_ingr_reassembly_context_table_context_map].values, dnxc_data_value_t, submodule_data->tables[dnx_data_ingr_reassembly_context_table_context_map].nof_values, "_dnx_data_ingr_reassembly_context_table_context_map table values");
    submodule_data->tables[dnx_data_ingr_reassembly_context_table_context_map].values[0].name = "start_index";
    submodule_data->tables[dnx_data_ingr_reassembly_context_table_context_map].values[0].type = "uint32";
    submodule_data->tables[dnx_data_ingr_reassembly_context_table_context_map].values[0].doc = "";
    submodule_data->tables[dnx_data_ingr_reassembly_context_table_context_map].values[0].offset = UTILEX_OFFSETOF(dnx_data_ingr_reassembly_context_context_map_t, start_index);


exit:
    SHR_FUNC_EXIT;
}


int
dnx_data_ingr_reassembly_context_feature_get(
    int unit,
    dnx_data_ingr_reassembly_context_feature_e feature)
{
    return dnxc_data_mgmt_feature_data_get(unit, dnx_data_module_ingr_reassembly, dnx_data_ingr_reassembly_submodule_context, feature);
}


uint32
dnx_data_ingr_reassembly_context_nof_contexts_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_ingr_reassembly, dnx_data_ingr_reassembly_submodule_context, dnx_data_ingr_reassembly_context_define_nof_contexts);
}

uint32
dnx_data_ingr_reassembly_context_invalid_context_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_ingr_reassembly, dnx_data_ingr_reassembly_submodule_context, dnx_data_ingr_reassembly_context_define_invalid_context);
}

uint32
dnx_data_ingr_reassembly_context_nof_cpu_channels_per_core_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_ingr_reassembly, dnx_data_ingr_reassembly_submodule_context, dnx_data_ingr_reassembly_context_define_nof_cpu_channels_per_core);
}

uint32
dnx_data_ingr_reassembly_context_reassembly_timeout_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_ingr_reassembly, dnx_data_ingr_reassembly_submodule_context, dnx_data_ingr_reassembly_context_define_reassembly_timeout);
}

uint32
dnx_data_ingr_reassembly_context_rcy_unique_context_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_ingr_reassembly, dnx_data_ingr_reassembly_submodule_context, dnx_data_ingr_reassembly_context_define_rcy_unique_context);
}



const dnx_data_ingr_reassembly_context_context_map_t *
dnx_data_ingr_reassembly_context_context_map_get(
    int unit,
    int port_type,
    int is_mgmt)
{
    char *data;
    dnxc_data_table_t *table;

    
    table = dnxc_data_mgmt_table_get(unit, dnx_data_module_ingr_reassembly, dnx_data_ingr_reassembly_submodule_context, dnx_data_ingr_reassembly_context_table_context_map);
    
    data = dnxc_data_mgmt_table_data_get(unit, table, port_type, is_mgmt);
    return (const dnx_data_ingr_reassembly_context_context_map_t *) data;

}


shr_error_e
dnx_data_ingr_reassembly_context_context_map_entry_str_get(
    int unit,
    char *buffer,
    int key0,
    int key1,
    int value_index)
{
    dnxc_data_table_t *table;
    const dnx_data_ingr_reassembly_context_context_map_t *data;
    SHR_FUNC_INIT_VARS(unit);

    
    table = dnxc_data_mgmt_table_get(unit, dnx_data_module_ingr_reassembly, dnx_data_ingr_reassembly_submodule_context, dnx_data_ingr_reassembly_context_table_context_map);
    data = (const dnx_data_ingr_reassembly_context_context_map_t *) dnxc_data_mgmt_table_data_diag_get(unit, table, key0, key1);
    switch (value_index)
    {
        case 0:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->start_index);
            break;
    }

    SHR_FUNC_EXIT;
}


const dnxc_data_table_info_t *
dnx_data_ingr_reassembly_context_context_map_info_get(
    int unit)
{

    
    return dnxc_data_mgmt_table_info_get(unit, dnx_data_module_ingr_reassembly, dnx_data_ingr_reassembly_submodule_context, dnx_data_ingr_reassembly_context_table_context_map);

}






static shr_error_e
dnx_data_ingr_reassembly_ilkn_init(
    int unit,
    dnxc_data_submodule_t *submodule_data)
{
    SHR_FUNC_INIT_VARS(unit);

    submodule_data->name = "ilkn";
    submodule_data->doc = "";
    
    submodule_data->nof_features = _dnx_data_ingr_reassembly_ilkn_feature_nof;
    DNXC_DATA_ALLOC(submodule_data->features, dnxc_data_feature_t,  submodule_data->nof_features, "_dnxc_data ingr_reassembly ilkn features");

    submodule_data->features[dnx_data_ingr_reassembly_ilkn_is_supported].name = "is_supported";
    submodule_data->features[dnx_data_ingr_reassembly_ilkn_is_supported].doc = "";
    submodule_data->features[dnx_data_ingr_reassembly_ilkn_is_supported].flags |= DNXC_DATA_F_FEATURE;

    
    submodule_data->nof_defines = _dnx_data_ingr_reassembly_ilkn_define_nof;
    DNXC_DATA_ALLOC(submodule_data->defines, dnxc_data_define_t, submodule_data->nof_defines, "_dnxc_data ingr_reassembly ilkn defines");

    
    submodule_data->nof_tables = _dnx_data_ingr_reassembly_ilkn_table_nof;
    DNXC_DATA_ALLOC(submodule_data->tables, dnxc_data_table_t, submodule_data->nof_tables, "_dnxc_data ingr_reassembly ilkn tables");


exit:
    SHR_FUNC_EXIT;
}


int
dnx_data_ingr_reassembly_ilkn_feature_get(
    int unit,
    dnx_data_ingr_reassembly_ilkn_feature_e feature)
{
    return dnxc_data_mgmt_feature_data_get(unit, dnx_data_module_ingr_reassembly, dnx_data_ingr_reassembly_submodule_ilkn, feature);
}











static shr_error_e
dnx_data_ingr_reassembly_priority_init(
    int unit,
    dnxc_data_submodule_t *submodule_data)
{
    SHR_FUNC_INIT_VARS(unit);

    submodule_data->name = "priority";
    submodule_data->doc = "";
    
    submodule_data->nof_features = _dnx_data_ingr_reassembly_priority_feature_nof;
    DNXC_DATA_ALLOC(submodule_data->features, dnxc_data_feature_t,  submodule_data->nof_features, "_dnxc_data ingr_reassembly priority features");

    
    submodule_data->nof_defines = _dnx_data_ingr_reassembly_priority_define_nof;
    DNXC_DATA_ALLOC(submodule_data->defines, dnxc_data_define_t, submodule_data->nof_defines, "_dnxc_data ingr_reassembly priority defines");

    submodule_data->defines[dnx_data_ingr_reassembly_priority_define_nif_eth_priorities_nof].name = "nif_eth_priorities_nof";
    submodule_data->defines[dnx_data_ingr_reassembly_priority_define_nif_eth_priorities_nof].doc = "";
    
    submodule_data->defines[dnx_data_ingr_reassembly_priority_define_nif_eth_priorities_nof].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_ingr_reassembly_priority_define_mirror_priorities_nof].name = "mirror_priorities_nof";
    submodule_data->defines[dnx_data_ingr_reassembly_priority_define_mirror_priorities_nof].doc = "";
    
    submodule_data->defines[dnx_data_ingr_reassembly_priority_define_mirror_priorities_nof].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_ingr_reassembly_priority_define_rcy_priorities_nof].name = "rcy_priorities_nof";
    submodule_data->defines[dnx_data_ingr_reassembly_priority_define_rcy_priorities_nof].doc = "";
    
    submodule_data->defines[dnx_data_ingr_reassembly_priority_define_rcy_priorities_nof].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_ingr_reassembly_priority_define_priorities_nof].name = "priorities_nof";
    submodule_data->defines[dnx_data_ingr_reassembly_priority_define_priorities_nof].doc = "";
    
    submodule_data->defines[dnx_data_ingr_reassembly_priority_define_priorities_nof].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_ingr_reassembly_priority_define_cgm_priorities_nof].name = "cgm_priorities_nof";
    submodule_data->defines[dnx_data_ingr_reassembly_priority_define_cgm_priorities_nof].doc = "";
    
    submodule_data->defines[dnx_data_ingr_reassembly_priority_define_cgm_priorities_nof].flags |= DNXC_DATA_F_DEFINE;

    
    submodule_data->nof_tables = _dnx_data_ingr_reassembly_priority_table_nof;
    DNXC_DATA_ALLOC(submodule_data->tables, dnxc_data_table_t, submodule_data->nof_tables, "_dnxc_data ingr_reassembly priority tables");


exit:
    SHR_FUNC_EXIT;
}


int
dnx_data_ingr_reassembly_priority_feature_get(
    int unit,
    dnx_data_ingr_reassembly_priority_feature_e feature)
{
    return dnxc_data_mgmt_feature_data_get(unit, dnx_data_module_ingr_reassembly, dnx_data_ingr_reassembly_submodule_priority, feature);
}


uint32
dnx_data_ingr_reassembly_priority_nif_eth_priorities_nof_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_ingr_reassembly, dnx_data_ingr_reassembly_submodule_priority, dnx_data_ingr_reassembly_priority_define_nif_eth_priorities_nof);
}

uint32
dnx_data_ingr_reassembly_priority_mirror_priorities_nof_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_ingr_reassembly, dnx_data_ingr_reassembly_submodule_priority, dnx_data_ingr_reassembly_priority_define_mirror_priorities_nof);
}

uint32
dnx_data_ingr_reassembly_priority_rcy_priorities_nof_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_ingr_reassembly, dnx_data_ingr_reassembly_submodule_priority, dnx_data_ingr_reassembly_priority_define_rcy_priorities_nof);
}

uint32
dnx_data_ingr_reassembly_priority_priorities_nof_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_ingr_reassembly, dnx_data_ingr_reassembly_submodule_priority, dnx_data_ingr_reassembly_priority_define_priorities_nof);
}

uint32
dnx_data_ingr_reassembly_priority_cgm_priorities_nof_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_ingr_reassembly, dnx_data_ingr_reassembly_submodule_priority, dnx_data_ingr_reassembly_priority_define_cgm_priorities_nof);
}










static shr_error_e
dnx_data_ingr_reassembly_dbal_init(
    int unit,
    dnxc_data_submodule_t *submodule_data)
{
    SHR_FUNC_INIT_VARS(unit);

    submodule_data->name = "dbal";
    submodule_data->doc = "";
    
    submodule_data->nof_features = _dnx_data_ingr_reassembly_dbal_feature_nof;
    DNXC_DATA_ALLOC(submodule_data->features, dnxc_data_feature_t,  submodule_data->nof_features, "_dnxc_data ingr_reassembly dbal features");

    
    submodule_data->nof_defines = _dnx_data_ingr_reassembly_dbal_define_nof;
    DNXC_DATA_ALLOC(submodule_data->defines, dnxc_data_define_t, submodule_data->nof_defines, "_dnxc_data ingr_reassembly dbal defines");

    submodule_data->defines[dnx_data_ingr_reassembly_dbal_define_reassembly_context_bits].name = "reassembly_context_bits";
    submodule_data->defines[dnx_data_ingr_reassembly_dbal_define_reassembly_context_bits].doc = "";
    
    submodule_data->defines[dnx_data_ingr_reassembly_dbal_define_reassembly_context_bits].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_ingr_reassembly_dbal_define_interface_bits].name = "interface_bits";
    submodule_data->defines[dnx_data_ingr_reassembly_dbal_define_interface_bits].doc = "";
    
    submodule_data->defines[dnx_data_ingr_reassembly_dbal_define_interface_bits].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_ingr_reassembly_dbal_define_interface_max].name = "interface_max";
    submodule_data->defines[dnx_data_ingr_reassembly_dbal_define_interface_max].doc = "";
    
    submodule_data->defines[dnx_data_ingr_reassembly_dbal_define_interface_max].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_ingr_reassembly_dbal_define_context_map_base_address_bits].name = "context_map_base_address_bits";
    submodule_data->defines[dnx_data_ingr_reassembly_dbal_define_context_map_base_address_bits].doc = "";
    
    submodule_data->defines[dnx_data_ingr_reassembly_dbal_define_context_map_base_address_bits].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_ingr_reassembly_dbal_define_context_map_base_address_max].name = "context_map_base_address_max";
    submodule_data->defines[dnx_data_ingr_reassembly_dbal_define_context_map_base_address_max].doc = "";
    
    submodule_data->defines[dnx_data_ingr_reassembly_dbal_define_context_map_base_address_max].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_ingr_reassembly_dbal_define_context_map_base_offest_ext_max].name = "context_map_base_offest_ext_max";
    submodule_data->defines[dnx_data_ingr_reassembly_dbal_define_context_map_base_offest_ext_max].doc = "";
    
    submodule_data->defines[dnx_data_ingr_reassembly_dbal_define_context_map_base_offest_ext_max].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_ingr_reassembly_dbal_define_interleaved_interface_bits].name = "interleaved_interface_bits";
    submodule_data->defines[dnx_data_ingr_reassembly_dbal_define_interleaved_interface_bits].doc = "";
    
    submodule_data->defines[dnx_data_ingr_reassembly_dbal_define_interleaved_interface_bits].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_ingr_reassembly_dbal_define_interleaved_interface_max].name = "interleaved_interface_max";
    submodule_data->defines[dnx_data_ingr_reassembly_dbal_define_interleaved_interface_max].doc = "";
    
    submodule_data->defines[dnx_data_ingr_reassembly_dbal_define_interleaved_interface_max].flags |= DNXC_DATA_F_DEFINE;

    
    submodule_data->nof_tables = _dnx_data_ingr_reassembly_dbal_table_nof;
    DNXC_DATA_ALLOC(submodule_data->tables, dnxc_data_table_t, submodule_data->nof_tables, "_dnxc_data ingr_reassembly dbal tables");


exit:
    SHR_FUNC_EXIT;
}


int
dnx_data_ingr_reassembly_dbal_feature_get(
    int unit,
    dnx_data_ingr_reassembly_dbal_feature_e feature)
{
    return dnxc_data_mgmt_feature_data_get(unit, dnx_data_module_ingr_reassembly, dnx_data_ingr_reassembly_submodule_dbal, feature);
}


uint32
dnx_data_ingr_reassembly_dbal_reassembly_context_bits_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_ingr_reassembly, dnx_data_ingr_reassembly_submodule_dbal, dnx_data_ingr_reassembly_dbal_define_reassembly_context_bits);
}

uint32
dnx_data_ingr_reassembly_dbal_interface_bits_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_ingr_reassembly, dnx_data_ingr_reassembly_submodule_dbal, dnx_data_ingr_reassembly_dbal_define_interface_bits);
}

uint32
dnx_data_ingr_reassembly_dbal_interface_max_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_ingr_reassembly, dnx_data_ingr_reassembly_submodule_dbal, dnx_data_ingr_reassembly_dbal_define_interface_max);
}

uint32
dnx_data_ingr_reassembly_dbal_context_map_base_address_bits_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_ingr_reassembly, dnx_data_ingr_reassembly_submodule_dbal, dnx_data_ingr_reassembly_dbal_define_context_map_base_address_bits);
}

uint32
dnx_data_ingr_reassembly_dbal_context_map_base_address_max_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_ingr_reassembly, dnx_data_ingr_reassembly_submodule_dbal, dnx_data_ingr_reassembly_dbal_define_context_map_base_address_max);
}

uint32
dnx_data_ingr_reassembly_dbal_context_map_base_offest_ext_max_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_ingr_reassembly, dnx_data_ingr_reassembly_submodule_dbal, dnx_data_ingr_reassembly_dbal_define_context_map_base_offest_ext_max);
}

uint32
dnx_data_ingr_reassembly_dbal_interleaved_interface_bits_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_ingr_reassembly, dnx_data_ingr_reassembly_submodule_dbal, dnx_data_ingr_reassembly_dbal_define_interleaved_interface_bits);
}

uint32
dnx_data_ingr_reassembly_dbal_interleaved_interface_max_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_ingr_reassembly, dnx_data_ingr_reassembly_submodule_dbal, dnx_data_ingr_reassembly_dbal_define_interleaved_interface_max);
}







shr_error_e
dnx_data_ingr_reassembly_init(
    int unit,
    dnxc_data_module_t *module_data)
{
    SHR_FUNC_INIT_VARS(unit);

    
    module_data->name = "ingr_reassembly";
    module_data->nof_submodules = _dnx_data_ingr_reassembly_submodule_nof;
    DNXC_DATA_ALLOC(module_data->submodules, dnxc_data_submodule_t, module_data->nof_submodules, "_dnxc_data ingr_reassembly submodules");

    
    SHR_IF_ERR_EXIT(dnx_data_ingr_reassembly_general_init(unit, &module_data->submodules[dnx_data_ingr_reassembly_submodule_general]));
    SHR_IF_ERR_EXIT(dnx_data_ingr_reassembly_context_init(unit, &module_data->submodules[dnx_data_ingr_reassembly_submodule_context]));
    SHR_IF_ERR_EXIT(dnx_data_ingr_reassembly_ilkn_init(unit, &module_data->submodules[dnx_data_ingr_reassembly_submodule_ilkn]));
    SHR_IF_ERR_EXIT(dnx_data_ingr_reassembly_priority_init(unit, &module_data->submodules[dnx_data_ingr_reassembly_submodule_priority]));
    SHR_IF_ERR_EXIT(dnx_data_ingr_reassembly_dbal_init(unit, &module_data->submodules[dnx_data_ingr_reassembly_submodule_dbal]));
    

    if (dnxc_data_mgmt_is_jr2_a0(unit))
    {
        SHR_IF_ERR_EXIT(jr2_a0_data_ingr_reassembly_attach(unit));
    }
    else


    if (dnxc_data_mgmt_is_jr2_b0(unit))
    {
        SHR_IF_ERR_EXIT(jr2_a0_data_ingr_reassembly_attach(unit));
    }
    else


    if (dnxc_data_mgmt_is_jr2_b1(unit))
    {
        SHR_IF_ERR_EXIT(jr2_a0_data_ingr_reassembly_attach(unit));
    }
    else


    if (dnxc_data_mgmt_is_j2c_a0(unit))
    {
        SHR_IF_ERR_EXIT(jr2_a0_data_ingr_reassembly_attach(unit));
        SHR_IF_ERR_EXIT(j2c_a0_data_ingr_reassembly_attach(unit));
    }
    else


    if (dnxc_data_mgmt_is_j2c_a1(unit))
    {
        SHR_IF_ERR_EXIT(jr2_a0_data_ingr_reassembly_attach(unit));
        SHR_IF_ERR_EXIT(j2c_a0_data_ingr_reassembly_attach(unit));
    }
    else


    if (dnxc_data_mgmt_is_q2a_a0(unit))
    {
        SHR_IF_ERR_EXIT(jr2_a0_data_ingr_reassembly_attach(unit));
        SHR_IF_ERR_EXIT(q2a_a0_data_ingr_reassembly_attach(unit));
    }
    else


    if (dnxc_data_mgmt_is_q2a_b0(unit))
    {
        SHR_IF_ERR_EXIT(jr2_a0_data_ingr_reassembly_attach(unit));
        SHR_IF_ERR_EXIT(q2a_a0_data_ingr_reassembly_attach(unit));
    }
    else


    if (dnxc_data_mgmt_is_q2a_b1(unit))
    {
        SHR_IF_ERR_EXIT(jr2_a0_data_ingr_reassembly_attach(unit));
        SHR_IF_ERR_EXIT(q2a_a0_data_ingr_reassembly_attach(unit));
    }
    else


    if (dnxc_data_mgmt_is_j2p_a0(unit))
    {
        SHR_IF_ERR_EXIT(jr2_a0_data_ingr_reassembly_attach(unit));
        SHR_IF_ERR_EXIT(j2p_a0_data_ingr_reassembly_attach(unit));
    }
    else


    if (dnxc_data_mgmt_is_j2p_a1(unit))
    {
        SHR_IF_ERR_EXIT(jr2_a0_data_ingr_reassembly_attach(unit));
        SHR_IF_ERR_EXIT(j2p_a0_data_ingr_reassembly_attach(unit));
    }
    else


    if (dnxc_data_mgmt_is_j2p_a2(unit))
    {
        SHR_IF_ERR_EXIT(jr2_a0_data_ingr_reassembly_attach(unit));
        SHR_IF_ERR_EXIT(j2p_a0_data_ingr_reassembly_attach(unit));
    }
    else


    if (dnxc_data_mgmt_is_j2x_a0(unit))
    {
        SHR_IF_ERR_EXIT(jr2_a0_data_ingr_reassembly_attach(unit));
        SHR_IF_ERR_EXIT(j2x_a0_data_ingr_reassembly_attach(unit));
    }
    else

    {
        SHR_EXIT();
    }

exit:
    SHR_FUNC_EXIT;
}
#undef BSL_LOG_MODULE

