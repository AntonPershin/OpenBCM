
/* *INDENT-OFF* */
/*
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2022 Broadcom Inc. All rights reserved.
 */
#ifdef BSL_LOG_MODULE
#error "BSL_LOG_MODULE redefined"
#endif
#define BSL_LOG_MODULE BSL_LS_BCMDNX_MACSEC

#include <soc/dnx/dnx_data/auto_generated/dnx_data_internal_macsec.h>







static shr_error_e
j2p_a0_dnx_data_macsec_general_macsec_block_exists_set(
    int unit)
{
    dnxc_data_feature_t *feature;
    int module_index = dnx_data_module_macsec;
    int submodule_index = dnx_data_macsec_submodule_general;
    int feature_index = dnx_data_macsec_general_macsec_block_exists;
    SHR_FUNC_INIT_VARS(unit);

    feature = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].features[feature_index];
    
    feature->default_data = 1;

    
    feature->data = 1;

    
    feature->flags |= DNXC_DATA_F_SUPPORTED;

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_feature_value_set(unit, feature));

exit:
    SHR_FUNC_EXIT;
}


static shr_error_e
j2p_a0_dnx_data_macsec_general_is_hw_reset_init_done_supported_set(
    int unit)
{
    dnxc_data_feature_t *feature;
    int module_index = dnx_data_module_macsec;
    int submodule_index = dnx_data_macsec_submodule_general;
    int feature_index = dnx_data_macsec_general_is_hw_reset_init_done_supported;
    SHR_FUNC_INIT_VARS(unit);

    feature = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].features[feature_index];
    
    feature->default_data = 1;

    
    feature->data = 1;

    
    feature->flags |= DNXC_DATA_F_SUPPORTED;

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_feature_value_set(unit, feature));

exit:
    SHR_FUNC_EXIT;
}


static shr_error_e
j2p_a0_dnx_data_macsec_general_is_port_based_supported_set(
    int unit)
{
    dnxc_data_feature_t *feature;
    int module_index = dnx_data_module_macsec;
    int submodule_index = dnx_data_macsec_submodule_general;
    int feature_index = dnx_data_macsec_general_is_port_based_supported;
    SHR_FUNC_INIT_VARS(unit);

    feature = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].features[feature_index];
    
    feature->default_data = 1;

    
    feature->data = 1;

    
    feature->flags |= DNXC_DATA_F_SUPPORTED;

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_feature_value_set(unit, feature));

exit:
    SHR_FUNC_EXIT;
}


static shr_error_e
j2p_a0_dnx_data_macsec_general_an_full_range_supported_set(
    int unit)
{
    dnxc_data_feature_t *feature;
    int module_index = dnx_data_module_macsec;
    int submodule_index = dnx_data_macsec_submodule_general;
    int feature_index = dnx_data_macsec_general_an_full_range_supported;
    SHR_FUNC_INIT_VARS(unit);

    feature = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].features[feature_index];
    
    feature->default_data = 0;

    
    feature->data = 0;

    
    feature->flags |= DNXC_DATA_F_SUPPORTED;

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_feature_value_set(unit, feature));

exit:
    SHR_FUNC_EXIT;
}


static shr_error_e
j2p_a0_dnx_data_macsec_general_rfc_6054_supported_set(
    int unit)
{
    dnxc_data_feature_t *feature;
    int module_index = dnx_data_module_macsec;
    int submodule_index = dnx_data_macsec_submodule_general;
    int feature_index = dnx_data_macsec_general_rfc_6054_supported;
    SHR_FUNC_INIT_VARS(unit);

    feature = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].features[feature_index];
    
    feature->default_data = 0;

    
    feature->data = 0;

    
    feature->flags |= DNXC_DATA_F_SUPPORTED;

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_feature_value_set(unit, feature));

exit:
    SHR_FUNC_EXIT;
}



static shr_error_e
j2p_a0_dnx_data_macsec_general_macsec_nof_set(
    int unit)
{
    dnxc_data_define_t *define;
    int module_index = dnx_data_module_macsec;
    int submodule_index = dnx_data_macsec_submodule_general;
    int define_index = dnx_data_macsec_general_define_macsec_nof;
    SHR_FUNC_INIT_VARS(unit);

    define = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].defines[define_index];
    
    define->default_data = 10;

    
    define->data = 10;

    
    define->flags |= DNXC_DATA_F_SUPPORTED;

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_define_value_set(unit, define));


exit:
    SHR_FUNC_EXIT;
}


static shr_error_e
j2p_a0_dnx_data_macsec_general_macsec_in_core_nof_set(
    int unit)
{
    dnxc_data_define_t *define;
    int module_index = dnx_data_module_macsec;
    int submodule_index = dnx_data_macsec_submodule_general;
    int define_index = dnx_data_macsec_general_define_macsec_in_core_nof;
    SHR_FUNC_INIT_VARS(unit);

    define = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].defines[define_index];
    
    define->default_data = 5;

    
    define->data = 5;

    
    define->flags |= DNXC_DATA_F_SUPPORTED;

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_define_value_set(unit, define));


exit:
    SHR_FUNC_EXIT;
}


static shr_error_e
j2p_a0_dnx_data_macsec_general_ports_in_macsec_nof_set(
    int unit)
{
    dnxc_data_define_t *define;
    int module_index = dnx_data_module_macsec;
    int submodule_index = dnx_data_macsec_submodule_general;
    int define_index = dnx_data_macsec_general_define_ports_in_macsec_nof;
    SHR_FUNC_INIT_VARS(unit);

    define = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].defines[define_index];
    
    define->default_data = 16;

    
    define->data = 16;

    
    define->flags |= DNXC_DATA_F_SUPPORTED;

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_define_value_set(unit, define));


exit:
    SHR_FUNC_EXIT;
}


static shr_error_e
j2p_a0_dnx_data_macsec_general_etype_nof_set(
    int unit)
{
    dnxc_data_define_t *define;
    int module_index = dnx_data_module_macsec;
    int submodule_index = dnx_data_macsec_submodule_general;
    int define_index = dnx_data_macsec_general_define_etype_nof;
    SHR_FUNC_INIT_VARS(unit);

    define = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].defines[define_index];
    
    define->default_data = 4;

    
    define->data = 4;

    
    define->flags |= DNXC_DATA_F_SUPPORTED;

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_define_value_set(unit, define));


exit:
    SHR_FUNC_EXIT;
}


static shr_error_e
j2p_a0_dnx_data_macsec_general_etype_not_zero_verify_set(
    int unit)
{
    dnxc_data_define_t *define;
    int module_index = dnx_data_module_macsec;
    int submodule_index = dnx_data_macsec_submodule_general;
    int define_index = dnx_data_macsec_general_define_etype_not_zero_verify;
    SHR_FUNC_INIT_VARS(unit);

    define = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].defines[define_index];
    
    define->default_data = 0;

    
    define->data = 0;

    
    define->flags |= DNXC_DATA_F_SUPPORTED;

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_define_value_set(unit, define));


exit:
    SHR_FUNC_EXIT;
}


static shr_error_e
j2p_a0_dnx_data_macsec_general_tx_threshold_set(
    int unit)
{
    dnxc_data_define_t *define;
    int module_index = dnx_data_module_macsec;
    int submodule_index = dnx_data_macsec_submodule_general;
    int define_index = dnx_data_macsec_general_define_tx_threshold;
    SHR_FUNC_INIT_VARS(unit);

    define = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].defines[define_index];
    
    define->default_data = 3;

    
    define->data = 3;

    
    define->flags |= DNXC_DATA_F_SUPPORTED;

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_define_value_set(unit, define));


exit:
    SHR_FUNC_EXIT;
}


static shr_error_e
j2p_a0_dnx_data_macsec_general_macsec_tdm_cal_max_depth_set(
    int unit)
{
    dnxc_data_define_t *define;
    int module_index = dnx_data_module_macsec;
    int submodule_index = dnx_data_macsec_submodule_general;
    int define_index = dnx_data_macsec_general_define_macsec_tdm_cal_max_depth;
    SHR_FUNC_INIT_VARS(unit);

    define = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].defines[define_index];
    
    define->default_data = 129;

    
    define->data = 129;

    
    define->flags |= DNXC_DATA_F_SUPPORTED;

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_define_value_set(unit, define));


exit:
    SHR_FUNC_EXIT;
}


static shr_error_e
j2p_a0_dnx_data_macsec_general_macsec_tdm_cal_hw_depth_set(
    int unit)
{
    dnxc_data_define_t *define;
    int module_index = dnx_data_module_macsec;
    int submodule_index = dnx_data_macsec_submodule_general;
    int define_index = dnx_data_macsec_general_define_macsec_tdm_cal_hw_depth;
    SHR_FUNC_INIT_VARS(unit);

    define = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].defines[define_index];
    
    define->default_data = 129;

    
    define->data = 129;

    
    define->flags |= DNXC_DATA_F_SUPPORTED;

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_define_value_set(unit, define));


exit:
    SHR_FUNC_EXIT;
}


static shr_error_e
j2p_a0_dnx_data_macsec_general_association_number_full_range_nof_set(
    int unit)
{
    dnxc_data_define_t *define;
    int module_index = dnx_data_module_macsec;
    int submodule_index = dnx_data_macsec_submodule_general;
    int define_index = dnx_data_macsec_general_define_association_number_full_range_nof;
    SHR_FUNC_INIT_VARS(unit);

    define = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].defines[define_index];
    
    define->default_data = 4;

    
    define->data = 4;

    
    define->flags |= DNXC_DATA_F_SUPPORTED;

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_define_value_set(unit, define));


exit:
    SHR_FUNC_EXIT;
}


static shr_error_e
j2p_a0_dnx_data_macsec_general_sectag_offset_min_value_set(
    int unit)
{
    dnxc_data_define_t *define;
    int module_index = dnx_data_module_macsec;
    int submodule_index = dnx_data_macsec_submodule_general;
    int define_index = dnx_data_macsec_general_define_sectag_offset_min_value;
    SHR_FUNC_INIT_VARS(unit);

    define = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].defines[define_index];
    
    define->default_data = 12;

    
    define->data = 12;

    
    define->flags |= DNXC_DATA_F_SUPPORTED;

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_define_value_set(unit, define));


exit:
    SHR_FUNC_EXIT;
}


static shr_error_e
j2p_a0_dnx_data_macsec_general_supported_entries_nof_set(
    int unit)
{
    dnxc_data_define_t *define;
    int module_index = dnx_data_module_macsec;
    int submodule_index = dnx_data_macsec_submodule_general;
    int define_index = dnx_data_macsec_general_define_supported_entries_nof;
    SHR_FUNC_INIT_VARS(unit);

    define = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].defines[define_index];
    
    define->default_data = -1;

    
    define->data = -1;

    
    define->flags |= DNXC_DATA_F_SUPPORTED;

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_define_value_set(unit, define));


exit:
    SHR_FUNC_EXIT;
}


static shr_error_e
j2p_a0_dnx_data_macsec_general_is_macsec_enabled_set(
    int unit)
{
    dnxc_data_define_t *define;
    int module_index = dnx_data_module_macsec;
    int submodule_index = dnx_data_macsec_submodule_general;
    int define_index = dnx_data_macsec_general_define_is_macsec_enabled;
    SHR_FUNC_INIT_VARS(unit);

    define = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].defines[define_index];
    
    define->default_data = 1;

    
    define->data = 1;

    
    define->flags |= DNXC_DATA_F_SUPPORTED;
    
    define->property.name = "macsec_enabled";
    define->property.doc = 
        "\n"
        "Enable / Disable MACSec support:\n"
        "macsec_supported= 0 / 1\n"
        "When disabling macsec, the MACSEC functionality in device is not supported.\n"
        "\n"
    ;
    define->property.method = dnxc_data_property_method_custom;
    define->property.method_str = "custom";

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_define_value_set(unit, define));

    SHR_IF_ERR_EXIT(dnx_data_property_macsec_general_is_macsec_enabled_read(unit, (uint32 *) &define->data));
    
    define->flags |= (DNXC_DATA_F_PROPERTY);

exit:
    SHR_FUNC_EXIT;
}


static shr_error_e
j2p_a0_dnx_data_macsec_general_is_power_optimization_enabled_set(
    int unit)
{
    dnxc_data_define_t *define;
    int module_index = dnx_data_module_macsec;
    int submodule_index = dnx_data_macsec_submodule_general;
    int define_index = dnx_data_macsec_general_define_is_power_optimization_enabled;
    SHR_FUNC_INIT_VARS(unit);

    define = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].defines[define_index];
    
    define->default_data = 1;

    
    define->data = 1;

    
    define->flags |= DNXC_DATA_F_SUPPORTED;
    
    define->property.name = spn_CUSTOM_FEATURE;
    define->property.doc = 
        "\n"
        "Mainly used for debugging.\n"
        "Support power optimization.\n"
        "Can be 0 and 1\n"
        "Default: 0\n"
        "\n"
    ;
    define->property.method = dnxc_data_property_method_suffix_enable;
    define->property.method_str = "suffix_enable";
    define->property.suffix = "macsec_power_optimization_enable";

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_define_value_set(unit, define));

    SHR_IF_ERR_EXIT(dnxc_data_mgmt_property_read(unit, &define->property, -1, &define->data));
    
    define->flags |= (DNXC_DATA_F_PROPERTY);

exit:
    SHR_FUNC_EXIT;
}



static shr_error_e
j2p_a0_dnx_data_macsec_general_pm_to_macsec_set(
    int unit)
{
    int ethu_index_index;
    dnx_data_macsec_general_pm_to_macsec_t *data, *default_data;
    dnxc_data_table_t *table;
    int module_index = dnx_data_module_macsec;
    int submodule_index = dnx_data_macsec_submodule_general;
    int table_index = dnx_data_macsec_general_table_pm_to_macsec;
    SHR_FUNC_INIT_VARS(unit);

    table = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].tables[table_index];
    
    table->flags |= DNXC_DATA_F_SUPPORTED;

    
    table->keys[0].size = dnx_data_nif.eth.ethu_nof_get(unit);
    table->info_get.key_size[0] = dnx_data_nif.eth.ethu_nof_get(unit);

    
    table->values[0].default_val = "-1";
    
    if (table->keys[0].size == 0 || table->info_get.key_size[0] == 0)
    {
        SHR_EXIT();
    }

    
    DNXC_DATA_ALLOC(table->data, dnx_data_macsec_general_pm_to_macsec_t, (1 * (table->keys[0].size) + 1  ), "data of dnx_data_macsec_general_table_pm_to_macsec");

    
    default_data = (dnx_data_macsec_general_pm_to_macsec_t *) dnxc_data_mgmt_table_data_get(unit, table, -1, -1);
    default_data->macsec_id = -1;
    
    for (ethu_index_index = 0; ethu_index_index < table->keys[0].size; ethu_index_index++)
    {
        data = (dnx_data_macsec_general_pm_to_macsec_t *) dnxc_data_mgmt_table_data_get(unit, table, ethu_index_index, 0);
        sal_memcpy(data, default_data, table->size_of_values);
    }
    
    if (0 < table->keys[0].size)
    {
        data = (dnx_data_macsec_general_pm_to_macsec_t *) dnxc_data_mgmt_table_data_get(unit, table, 0, 0);
        data->macsec_id = 0;
    }
    if (1 < table->keys[0].size)
    {
        data = (dnx_data_macsec_general_pm_to_macsec_t *) dnxc_data_mgmt_table_data_get(unit, table, 1, 0);
        data->macsec_id = 1;
    }
    if (2 < table->keys[0].size)
    {
        data = (dnx_data_macsec_general_pm_to_macsec_t *) dnxc_data_mgmt_table_data_get(unit, table, 2, 0);
        data->macsec_id = 1;
    }
    if (3 < table->keys[0].size)
    {
        data = (dnx_data_macsec_general_pm_to_macsec_t *) dnxc_data_mgmt_table_data_get(unit, table, 3, 0);
        data->macsec_id = 2;
    }
    if (4 < table->keys[0].size)
    {
        data = (dnx_data_macsec_general_pm_to_macsec_t *) dnxc_data_mgmt_table_data_get(unit, table, 4, 0);
        data->macsec_id = 2;
    }
    if (5 < table->keys[0].size)
    {
        data = (dnx_data_macsec_general_pm_to_macsec_t *) dnxc_data_mgmt_table_data_get(unit, table, 5, 0);
        data->macsec_id = 3;
    }
    if (6 < table->keys[0].size)
    {
        data = (dnx_data_macsec_general_pm_to_macsec_t *) dnxc_data_mgmt_table_data_get(unit, table, 6, 0);
        data->macsec_id = 3;
    }
    if (7 < table->keys[0].size)
    {
        data = (dnx_data_macsec_general_pm_to_macsec_t *) dnxc_data_mgmt_table_data_get(unit, table, 7, 0);
        data->macsec_id = 4;
    }
    if (8 < table->keys[0].size)
    {
        data = (dnx_data_macsec_general_pm_to_macsec_t *) dnxc_data_mgmt_table_data_get(unit, table, 8, 0);
        data->macsec_id = 4;
    }
    if (9 < table->keys[0].size)
    {
        data = (dnx_data_macsec_general_pm_to_macsec_t *) dnxc_data_mgmt_table_data_get(unit, table, 9, 0);
        data->macsec_id = 5;
    }
    if (10 < table->keys[0].size)
    {
        data = (dnx_data_macsec_general_pm_to_macsec_t *) dnxc_data_mgmt_table_data_get(unit, table, 10, 0);
        data->macsec_id = 6;
    }
    if (11 < table->keys[0].size)
    {
        data = (dnx_data_macsec_general_pm_to_macsec_t *) dnxc_data_mgmt_table_data_get(unit, table, 11, 0);
        data->macsec_id = 6;
    }
    if (12 < table->keys[0].size)
    {
        data = (dnx_data_macsec_general_pm_to_macsec_t *) dnxc_data_mgmt_table_data_get(unit, table, 12, 0);
        data->macsec_id = 7;
    }
    if (13 < table->keys[0].size)
    {
        data = (dnx_data_macsec_general_pm_to_macsec_t *) dnxc_data_mgmt_table_data_get(unit, table, 13, 0);
        data->macsec_id = 7;
    }
    if (14 < table->keys[0].size)
    {
        data = (dnx_data_macsec_general_pm_to_macsec_t *) dnxc_data_mgmt_table_data_get(unit, table, 14, 0);
        data->macsec_id = 8;
    }
    if (15 < table->keys[0].size)
    {
        data = (dnx_data_macsec_general_pm_to_macsec_t *) dnxc_data_mgmt_table_data_get(unit, table, 15, 0);
        data->macsec_id = 8;
    }
    if (16 < table->keys[0].size)
    {
        data = (dnx_data_macsec_general_pm_to_macsec_t *) dnxc_data_mgmt_table_data_get(unit, table, 16, 0);
        data->macsec_id = 9;
    }
    if (17 < table->keys[0].size)
    {
        data = (dnx_data_macsec_general_pm_to_macsec_t *) dnxc_data_mgmt_table_data_get(unit, table, 17, 0);
        data->macsec_id = 9;
    }

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_table_value_set(unit, table));


exit:
    SHR_FUNC_EXIT;
}


static shr_error_e
j2p_a0_dnx_data_macsec_general_macsec_instances_set(
    int unit)
{
    int macsec_id_index;
    dnx_data_macsec_general_macsec_instances_t *data, *default_data;
    dnxc_data_table_t *table;
    int module_index = dnx_data_module_macsec;
    int submodule_index = dnx_data_macsec_submodule_general;
    int table_index = dnx_data_macsec_general_table_macsec_instances;
    SHR_FUNC_INIT_VARS(unit);

    table = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].tables[table_index];
    
    table->flags |= DNXC_DATA_F_SUPPORTED;

    
    table->keys[0].size = dnx_data_macsec.general.macsec_nof_get(unit);
    table->info_get.key_size[0] = dnx_data_macsec.general.macsec_nof_get(unit);

    
    table->values[0].default_val = "2";
    
    if (table->keys[0].size == 0 || table->info_get.key_size[0] == 0)
    {
        SHR_EXIT();
    }

    
    DNXC_DATA_ALLOC(table->data, dnx_data_macsec_general_macsec_instances_t, (1 * (table->keys[0].size) + 1  ), "data of dnx_data_macsec_general_table_macsec_instances");

    
    default_data = (dnx_data_macsec_general_macsec_instances_t *) dnxc_data_mgmt_table_data_get(unit, table, -1, -1);
    default_data->nof_pms = 2;
    
    for (macsec_id_index = 0; macsec_id_index < table->keys[0].size; macsec_id_index++)
    {
        data = (dnx_data_macsec_general_macsec_instances_t *) dnxc_data_mgmt_table_data_get(unit, table, macsec_id_index, 0);
        sal_memcpy(data, default_data, table->size_of_values);
    }
    
    if (0 < table->keys[0].size)
    {
        data = (dnx_data_macsec_general_macsec_instances_t *) dnxc_data_mgmt_table_data_get(unit, table, 0, 0);
        data->nof_pms = 1;
    }
    if (1 < table->keys[0].size)
    {
        data = (dnx_data_macsec_general_macsec_instances_t *) dnxc_data_mgmt_table_data_get(unit, table, 1, 0);
        data->nof_pms = 2;
    }
    if (2 < table->keys[0].size)
    {
        data = (dnx_data_macsec_general_macsec_instances_t *) dnxc_data_mgmt_table_data_get(unit, table, 2, 0);
        data->nof_pms = 2;
    }
    if (3 < table->keys[0].size)
    {
        data = (dnx_data_macsec_general_macsec_instances_t *) dnxc_data_mgmt_table_data_get(unit, table, 3, 0);
        data->nof_pms = 2;
    }
    if (4 < table->keys[0].size)
    {
        data = (dnx_data_macsec_general_macsec_instances_t *) dnxc_data_mgmt_table_data_get(unit, table, 4, 0);
        data->nof_pms = 2;
    }
    if (5 < table->keys[0].size)
    {
        data = (dnx_data_macsec_general_macsec_instances_t *) dnxc_data_mgmt_table_data_get(unit, table, 5, 0);
        data->nof_pms = 1;
    }
    if (6 < table->keys[0].size)
    {
        data = (dnx_data_macsec_general_macsec_instances_t *) dnxc_data_mgmt_table_data_get(unit, table, 6, 0);
        data->nof_pms = 2;
    }
    if (7 < table->keys[0].size)
    {
        data = (dnx_data_macsec_general_macsec_instances_t *) dnxc_data_mgmt_table_data_get(unit, table, 7, 0);
        data->nof_pms = 2;
    }
    if (8 < table->keys[0].size)
    {
        data = (dnx_data_macsec_general_macsec_instances_t *) dnxc_data_mgmt_table_data_get(unit, table, 8, 0);
        data->nof_pms = 2;
    }
    if (9 < table->keys[0].size)
    {
        data = (dnx_data_macsec_general_macsec_instances_t *) dnxc_data_mgmt_table_data_get(unit, table, 9, 0);
        data->nof_pms = 2;
    }

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_table_value_set(unit, table));


exit:
    SHR_FUNC_EXIT;
}


static shr_error_e
j2p_a0_dnx_data_macsec_general_macsec_block_mapping_set(
    int unit)
{
    int is_mss_index;
    int block_id_index;
    dnx_data_macsec_general_macsec_block_mapping_t *data, *default_data;
    dnxc_data_table_t *table;
    int module_index = dnx_data_module_macsec;
    int submodule_index = dnx_data_macsec_submodule_general;
    int table_index = dnx_data_macsec_general_table_macsec_block_mapping;
    SHR_FUNC_INIT_VARS(unit);

    table = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].tables[table_index];
    
    table->flags |= DNXC_DATA_F_SUPPORTED;

    
    table->keys[0].size = 2;
    table->info_get.key_size[0] = 2;
    table->keys[1].size = dnx_data_macsec.general.macsec_nof_get(unit);
    table->info_get.key_size[1] = dnx_data_macsec.general.macsec_nof_get(unit);

    
    table->values[0].default_val = "0";
    
    if (table->keys[0].size == 0 || table->info_get.key_size[0] == 0)
    {
        SHR_EXIT();
    }
    if (table->keys[1].size == 0 || table->info_get.key_size[1] == 0)
    {
        SHR_EXIT();
    }

    
    DNXC_DATA_ALLOC(table->data, dnx_data_macsec_general_macsec_block_mapping_t, (1 * (table->keys[0].size) * (table->keys[1].size) + 1  ), "data of dnx_data_macsec_general_table_macsec_block_mapping");

    
    default_data = (dnx_data_macsec_general_macsec_block_mapping_t *) dnxc_data_mgmt_table_data_get(unit, table, -1, -1);
    default_data->instance_id = 0;
    
    for (is_mss_index = 0; is_mss_index < table->keys[0].size; is_mss_index++)
    {
        for (block_id_index = 0; block_id_index < table->keys[1].size; block_id_index++)
        {
            data = (dnx_data_macsec_general_macsec_block_mapping_t *) dnxc_data_mgmt_table_data_get(unit, table, is_mss_index, block_id_index);
            sal_memcpy(data, default_data, table->size_of_values);
        }
    }
    
    if (1 < table->keys[0].size && 0 < table->keys[1].size)
    {
        data = (dnx_data_macsec_general_macsec_block_mapping_t *) dnxc_data_mgmt_table_data_get(unit, table, 1, 0);
        data->instance_id = 0;
    }
    if (0 < table->keys[0].size && 0 < table->keys[1].size)
    {
        data = (dnx_data_macsec_general_macsec_block_mapping_t *) dnxc_data_mgmt_table_data_get(unit, table, 0, 0);
        data->instance_id = 1;
    }
    if (0 < table->keys[0].size && 1 < table->keys[1].size)
    {
        data = (dnx_data_macsec_general_macsec_block_mapping_t *) dnxc_data_mgmt_table_data_get(unit, table, 0, 1);
        data->instance_id = 2;
    }
    if (0 < table->keys[0].size && 2 < table->keys[1].size)
    {
        data = (dnx_data_macsec_general_macsec_block_mapping_t *) dnxc_data_mgmt_table_data_get(unit, table, 0, 2);
        data->instance_id = 3;
    }
    if (0 < table->keys[0].size && 3 < table->keys[1].size)
    {
        data = (dnx_data_macsec_general_macsec_block_mapping_t *) dnxc_data_mgmt_table_data_get(unit, table, 0, 3);
        data->instance_id = 4;
    }
    if (1 < table->keys[0].size && 1 < table->keys[1].size)
    {
        data = (dnx_data_macsec_general_macsec_block_mapping_t *) dnxc_data_mgmt_table_data_get(unit, table, 1, 1);
        data->instance_id = 5;
    }
    if (0 < table->keys[0].size && 4 < table->keys[1].size)
    {
        data = (dnx_data_macsec_general_macsec_block_mapping_t *) dnxc_data_mgmt_table_data_get(unit, table, 0, 4);
        data->instance_id = 6;
    }
    if (0 < table->keys[0].size && 5 < table->keys[1].size)
    {
        data = (dnx_data_macsec_general_macsec_block_mapping_t *) dnxc_data_mgmt_table_data_get(unit, table, 0, 5);
        data->instance_id = 7;
    }
    if (0 < table->keys[0].size && 6 < table->keys[1].size)
    {
        data = (dnx_data_macsec_general_macsec_block_mapping_t *) dnxc_data_mgmt_table_data_get(unit, table, 0, 6);
        data->instance_id = 8;
    }
    if (0 < table->keys[0].size && 7 < table->keys[1].size)
    {
        data = (dnx_data_macsec_general_macsec_block_mapping_t *) dnxc_data_mgmt_table_data_get(unit, table, 0, 7);
        data->instance_id = 9;
    }

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_table_value_set(unit, table));


exit:
    SHR_FUNC_EXIT;
}






static shr_error_e
j2p_a0_dnx_data_macsec_ingress_flow_nof_set(
    int unit)
{
    dnxc_data_define_t *define;
    int module_index = dnx_data_module_macsec;
    int submodule_index = dnx_data_macsec_submodule_ingress;
    int define_index = dnx_data_macsec_ingress_define_flow_nof;
    SHR_FUNC_INIT_VARS(unit);

    define = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].defines[define_index];
    
    define->default_data = 1536;

    
    define->data = 1536;

    
    define->flags |= DNXC_DATA_F_SUPPORTED;

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_define_value_set(unit, define));


exit:
    SHR_FUNC_EXIT;
}


static shr_error_e
j2p_a0_dnx_data_macsec_ingress_policy_nof_set(
    int unit)
{
    dnxc_data_define_t *define;
    int module_index = dnx_data_module_macsec;
    int submodule_index = dnx_data_macsec_submodule_ingress;
    int define_index = dnx_data_macsec_ingress_define_policy_nof;
    SHR_FUNC_INIT_VARS(unit);

    define = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].defines[define_index];
    
    define->default_data = 1024;

    
    define->data = 1024;

    
    define->flags |= DNXC_DATA_F_SUPPORTED;

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_define_value_set(unit, define));


exit:
    SHR_FUNC_EXIT;
}


static shr_error_e
j2p_a0_dnx_data_macsec_ingress_secure_assoc_nof_set(
    int unit)
{
    dnxc_data_define_t *define;
    int module_index = dnx_data_module_macsec;
    int submodule_index = dnx_data_macsec_submodule_ingress;
    int define_index = dnx_data_macsec_ingress_define_secure_assoc_nof;
    SHR_FUNC_INIT_VARS(unit);

    define = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].defines[define_index];
    
    define->default_data = 2048;

    
    define->data = 2048;

    
    define->flags |= DNXC_DATA_F_SUPPORTED;

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_define_value_set(unit, define));


exit:
    SHR_FUNC_EXIT;
}


static shr_error_e
j2p_a0_dnx_data_macsec_ingress_udf_nof_bits_set(
    int unit)
{
    dnxc_data_define_t *define;
    int module_index = dnx_data_module_macsec;
    int submodule_index = dnx_data_macsec_submodule_ingress;
    int define_index = dnx_data_macsec_ingress_define_udf_nof_bits;
    SHR_FUNC_INIT_VARS(unit);

    define = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].defines[define_index];
    
    define->default_data = 440;

    
    define->data = 440;

    
    define->flags |= DNXC_DATA_F_SUPPORTED;

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_define_value_set(unit, define));


exit:
    SHR_FUNC_EXIT;
}


static shr_error_e
j2p_a0_dnx_data_macsec_ingress_mgmt_rule_exact_nof_set(
    int unit)
{
    dnxc_data_define_t *define;
    int module_index = dnx_data_module_macsec;
    int submodule_index = dnx_data_macsec_submodule_ingress;
    int define_index = dnx_data_macsec_ingress_define_mgmt_rule_exact_nof;
    SHR_FUNC_INIT_VARS(unit);

    define = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].defines[define_index];
    
    define->default_data = 8;

    
    define->data = 8;

    
    define->flags |= DNXC_DATA_F_SUPPORTED;

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_define_value_set(unit, define));


exit:
    SHR_FUNC_EXIT;
}


static shr_error_e
j2p_a0_dnx_data_macsec_ingress_tpid_nof_set(
    int unit)
{
    dnxc_data_define_t *define;
    int module_index = dnx_data_module_macsec;
    int submodule_index = dnx_data_macsec_submodule_ingress;
    int define_index = dnx_data_macsec_ingress_define_tpid_nof;
    SHR_FUNC_INIT_VARS(unit);

    define = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].defines[define_index];
    
    define->default_data = 5;

    
    define->data = 5;

    
    define->flags |= DNXC_DATA_F_SUPPORTED;

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_define_value_set(unit, define));


exit:
    SHR_FUNC_EXIT;
}


static shr_error_e
j2p_a0_dnx_data_macsec_ingress_cpu_flex_map_nof_set(
    int unit)
{
    dnxc_data_define_t *define;
    int module_index = dnx_data_module_macsec;
    int submodule_index = dnx_data_macsec_submodule_ingress;
    int define_index = dnx_data_macsec_ingress_define_cpu_flex_map_nof;
    SHR_FUNC_INIT_VARS(unit);

    define = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].defines[define_index];
    
    define->default_data = 16;

    
    define->data = 16;

    
    define->flags |= DNXC_DATA_F_SUPPORTED;

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_define_value_set(unit, define));


exit:
    SHR_FUNC_EXIT;
}


static shr_error_e
j2p_a0_dnx_data_macsec_ingress_sc_tcam_nof_set(
    int unit)
{
    dnxc_data_define_t *define;
    int module_index = dnx_data_module_macsec;
    int submodule_index = dnx_data_macsec_submodule_ingress;
    int define_index = dnx_data_macsec_ingress_define_sc_tcam_nof;
    SHR_FUNC_INIT_VARS(unit);

    define = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].defines[define_index];
    
    define->default_data = 1280;

    
    define->data = 1280;

    
    define->flags |= DNXC_DATA_F_SUPPORTED;

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_define_value_set(unit, define));


exit:
    SHR_FUNC_EXIT;
}


static shr_error_e
j2p_a0_dnx_data_macsec_ingress_sa_per_sc_nof_set(
    int unit)
{
    dnxc_data_define_t *define;
    int module_index = dnx_data_module_macsec;
    int submodule_index = dnx_data_macsec_submodule_ingress;
    int define_index = dnx_data_macsec_ingress_define_sa_per_sc_nof;
    SHR_FUNC_INIT_VARS(unit);

    define = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].defines[define_index];
    
    define->default_data = 2;

    
    define->data = 2;

    
    define->flags |= DNXC_DATA_F_SUPPORTED;
    
    define->property.name = "xflow_macsec_secure_chan_to_num_secure_assoc";
    define->property.doc = 
        "Number of SA entries per SC entry for Decrypt\n"
    ;
    define->property.method = dnxc_data_property_method_custom;
    define->property.method_str = "custom";

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_define_value_set(unit, define));

    define->property.label = DNXC_DATA_LABEL_MACSEC;
    SHR_IF_ERR_EXIT(dnx_data_property_macsec_ingress_sa_per_sc_nof_read(unit, (uint32 *) &define->data));
    
    define->flags |= (DNXC_DATA_F_PROPERTY);

exit:
    SHR_FUNC_EXIT;
}


static shr_error_e
j2p_a0_dnx_data_macsec_ingress_invalidate_sa_set(
    int unit)
{
    dnxc_data_define_t *define;
    int module_index = dnx_data_module_macsec;
    int submodule_index = dnx_data_macsec_submodule_ingress;
    int define_index = dnx_data_macsec_ingress_define_invalidate_sa;
    SHR_FUNC_INIT_VARS(unit);

    define = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].defines[define_index];
    
    define->default_data = 0;

    
    define->data = 0;

    
    define->flags |= DNXC_DATA_F_SUPPORTED;
    
    define->property.name = spn_XFLOW_MACSEC_DECRYPT_AUTO_SECURE_ASSOC_INVALIDATE;
    define->property.doc = 
        "Enable Auto SA invalidation\n"
    ;
    define->property.method = dnxc_data_property_method_enable;
    define->property.method_str = "enable";

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_define_value_set(unit, define));

    define->property.label = DNXC_DATA_LABEL_MACSEC;
    SHR_IF_ERR_EXIT(dnxc_data_mgmt_property_read(unit, &define->property, -1, &define->data));
    
    define->flags |= (DNXC_DATA_F_PROPERTY);

exit:
    SHR_FUNC_EXIT;
}


static shr_error_e
j2p_a0_dnx_data_macsec_ingress_secure_channel_nof_set(
    int unit)
{
    dnxc_data_define_t *define;
    int module_index = dnx_data_module_macsec;
    int submodule_index = dnx_data_macsec_submodule_ingress;
    int define_index = dnx_data_macsec_ingress_define_secure_channel_nof;
    SHR_FUNC_INIT_VARS(unit);

    define = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].defines[define_index];
    
    define->default_data = dnx_data_macsec.ingress.secure_assoc_nof_get(unit)/dnx_data_macsec.ingress.sa_per_sc_nof_get(unit);

    
    define->data = dnx_data_macsec.ingress.secure_assoc_nof_get(unit)/dnx_data_macsec.ingress.sa_per_sc_nof_get(unit);

    
    define->flags |= DNXC_DATA_F_SUPPORTED;

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_define_value_set(unit, define));


exit:
    SHR_FUNC_EXIT;
}



static shr_error_e
j2p_a0_dnx_data_macsec_ingress_udf_set(
    int unit)
{
    int type_index;
    dnx_data_macsec_ingress_udf_t *data, *default_data;
    dnxc_data_table_t *table;
    int module_index = dnx_data_module_macsec;
    int submodule_index = dnx_data_macsec_submodule_ingress;
    int table_index = dnx_data_macsec_ingress_table_udf;
    SHR_FUNC_INIT_VARS(unit);

    table = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].tables[table_index];
    
    table->flags |= DNXC_DATA_F_SUPPORTED;

    
    table->keys[0].size = 13;
    table->info_get.key_size[0] = 13;

    
    table->values[0].default_val = "0";
    
    if (table->keys[0].size == 0 || table->info_get.key_size[0] == 0)
    {
        SHR_EXIT();
    }

    
    DNXC_DATA_ALLOC(table->data, dnx_data_macsec_ingress_udf_t, (1 * (table->keys[0].size) + 1  ), "data of dnx_data_macsec_ingress_table_udf");

    
    default_data = (dnx_data_macsec_ingress_udf_t *) dnxc_data_mgmt_table_data_get(unit, table, -1, -1);
    default_data->payload_len = 0;
    
    for (type_index = 0; type_index < table->keys[0].size; type_index++)
    {
        data = (dnx_data_macsec_ingress_udf_t *) dnxc_data_mgmt_table_data_get(unit, table, type_index, 0);
        sal_memcpy(data, default_data, table->size_of_values);
    }
    
    if (0 < table->keys[0].size)
    {
        data = (dnx_data_macsec_ingress_udf_t *) dnxc_data_mgmt_table_data_get(unit, table, 0, 0);
        data->payload_len = 280;
    }
    if (1 < table->keys[0].size)
    {
        data = (dnx_data_macsec_ingress_udf_t *) dnxc_data_mgmt_table_data_get(unit, table, 1, 0);
        data->payload_len = 280;
    }
    if (2 < table->keys[0].size)
    {
        data = (dnx_data_macsec_ingress_udf_t *) dnxc_data_mgmt_table_data_get(unit, table, 2, 0);
        data->payload_len = 280;
    }
    if (3 < table->keys[0].size)
    {
        data = (dnx_data_macsec_ingress_udf_t *) dnxc_data_mgmt_table_data_get(unit, table, 3, 0);
        data->payload_len = 296;
    }
    if (4 < table->keys[0].size)
    {
        data = (dnx_data_macsec_ingress_udf_t *) dnxc_data_mgmt_table_data_get(unit, table, 4, 0);
        data->payload_len = 168;
    }
    if (5 < table->keys[0].size)
    {
        data = (dnx_data_macsec_ingress_udf_t *) dnxc_data_mgmt_table_data_get(unit, table, 5, 0);
        data->payload_len = 344;
    }
    if (6 < table->keys[0].size)
    {
        data = (dnx_data_macsec_ingress_udf_t *) dnxc_data_mgmt_table_data_get(unit, table, 6, 0);
        data->payload_len = 264;
    }
    if (7 < table->keys[0].size)
    {
        data = (dnx_data_macsec_ingress_udf_t *) dnxc_data_mgmt_table_data_get(unit, table, 7, 0);
        data->payload_len = 240;
    }
    if (8 < table->keys[0].size)
    {
        data = (dnx_data_macsec_ingress_udf_t *) dnxc_data_mgmt_table_data_get(unit, table, 8, 0);
        data->payload_len = 208;
    }
    if (9 < table->keys[0].size)
    {
        data = (dnx_data_macsec_ingress_udf_t *) dnxc_data_mgmt_table_data_get(unit, table, 9, 0);
        data->payload_len = 208;
    }
    if (10 < table->keys[0].size)
    {
        data = (dnx_data_macsec_ingress_udf_t *) dnxc_data_mgmt_table_data_get(unit, table, 10, 0);
        data->payload_len = 96;
    }
    if (11 < table->keys[0].size)
    {
        data = (dnx_data_macsec_ingress_udf_t *) dnxc_data_mgmt_table_data_get(unit, table, 11, 0);
        data->payload_len = 64;
    }
    if (12 < table->keys[0].size)
    {
        data = (dnx_data_macsec_ingress_udf_t *) dnxc_data_mgmt_table_data_get(unit, table, 12, 0);
        data->payload_len = 64;
    }

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_table_value_set(unit, table));


exit:
    SHR_FUNC_EXIT;
}






static shr_error_e
j2p_a0_dnx_data_macsec_egress_secure_assoc_nof_set(
    int unit)
{
    dnxc_data_define_t *define;
    int module_index = dnx_data_module_macsec;
    int submodule_index = dnx_data_macsec_submodule_egress;
    int define_index = dnx_data_macsec_egress_define_secure_assoc_nof;
    SHR_FUNC_INIT_VARS(unit);

    define = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].defines[define_index];
    
    define->default_data = 1024;

    
    define->data = 1024;

    
    define->flags |= DNXC_DATA_F_SUPPORTED;

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_define_value_set(unit, define));


exit:
    SHR_FUNC_EXIT;
}


static shr_error_e
j2p_a0_dnx_data_macsec_egress_soft_expiry_threshold_profiles_nof_set(
    int unit)
{
    dnxc_data_define_t *define;
    int module_index = dnx_data_module_macsec;
    int submodule_index = dnx_data_macsec_submodule_egress;
    int define_index = dnx_data_macsec_egress_define_soft_expiry_threshold_profiles_nof;
    SHR_FUNC_INIT_VARS(unit);

    define = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].defines[define_index];
    
    define->default_data = 4;

    
    define->data = 4;

    
    define->flags |= DNXC_DATA_F_SUPPORTED;

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_define_value_set(unit, define));


exit:
    SHR_FUNC_EXIT;
}


static shr_error_e
j2p_a0_dnx_data_macsec_egress_an_bit_nof_set(
    int unit)
{
    dnxc_data_define_t *define;
    int module_index = dnx_data_module_macsec;
    int submodule_index = dnx_data_macsec_submodule_egress;
    int define_index = dnx_data_macsec_egress_define_an_bit_nof;
    SHR_FUNC_INIT_VARS(unit);

    define = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].defines[define_index];
    
    define->default_data = 1;

    
    define->data = 1;

    
    define->flags |= DNXC_DATA_F_SUPPORTED;

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_define_value_set(unit, define));


exit:
    SHR_FUNC_EXIT;
}


static shr_error_e
j2p_a0_dnx_data_macsec_egress_sa_per_sc_nof_set(
    int unit)
{
    dnxc_data_define_t *define;
    int module_index = dnx_data_module_macsec;
    int submodule_index = dnx_data_macsec_submodule_egress;
    int define_index = dnx_data_macsec_egress_define_sa_per_sc_nof;
    SHR_FUNC_INIT_VARS(unit);

    define = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].defines[define_index];
    
    define->default_data = 1;

    
    define->data = 1;

    
    define->flags |= DNXC_DATA_F_SUPPORTED;
    
    define->property.name = "xflow_macsec_secure_chan_to_num_secure_assoc";
    define->property.doc = 
        "Number of SA entries per SC entry for Encrypt\n"
    ;
    define->property.method = dnxc_data_property_method_custom;
    define->property.method_str = "custom";

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_define_value_set(unit, define));

    define->property.label = DNXC_DATA_LABEL_MACSEC;
    SHR_IF_ERR_EXIT(dnx_data_property_macsec_egress_sa_per_sc_nof_read(unit, (uint32 *) &define->data));
    
    define->flags |= (DNXC_DATA_F_PROPERTY);

exit:
    SHR_FUNC_EXIT;
}


static shr_error_e
j2p_a0_dnx_data_macsec_egress_secure_channel_nof_set(
    int unit)
{
    dnxc_data_define_t *define;
    int module_index = dnx_data_module_macsec;
    int submodule_index = dnx_data_macsec_submodule_egress;
    int define_index = dnx_data_macsec_egress_define_secure_channel_nof;
    SHR_FUNC_INIT_VARS(unit);

    define = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].defines[define_index];
    
    define->default_data = dnx_data_macsec.egress.secure_assoc_nof_get(unit)/dnx_data_macsec.egress.sa_per_sc_nof_get(unit);

    
    define->data = dnx_data_macsec.egress.secure_assoc_nof_get(unit)/dnx_data_macsec.egress.sa_per_sc_nof_get(unit);

    
    define->flags |= DNXC_DATA_F_SUPPORTED;

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_define_value_set(unit, define));


exit:
    SHR_FUNC_EXIT;
}




shr_error_e
j2p_a0_data_macsec_attach(
    int unit)
{
    dnxc_data_module_t *module = NULL;
    dnxc_data_submodule_t *submodule = NULL;
    dnxc_data_define_t *define = NULL;
    dnxc_data_feature_t *feature = NULL;
    dnxc_data_table_t *table = NULL;
    int module_index = dnx_data_module_macsec;
    int submodule_index = -1, data_index = -1;
    SHR_FUNC_INIT_VARS(unit);

    COMPILER_REFERENCE(define);
    COMPILER_REFERENCE(feature);
    COMPILER_REFERENCE(table);
    COMPILER_REFERENCE(submodule);
    COMPILER_REFERENCE(data_index);
    COMPILER_REFERENCE(submodule_index);
    module = &_dnxc_data[unit].modules[module_index];
    
    submodule_index = dnx_data_macsec_submodule_general;
    submodule = &module->submodules[submodule_index];

    
    data_index = dnx_data_macsec_general_define_macsec_nof;
    define = &submodule->defines[data_index];
    define->set = j2p_a0_dnx_data_macsec_general_macsec_nof_set;
    data_index = dnx_data_macsec_general_define_macsec_in_core_nof;
    define = &submodule->defines[data_index];
    define->set = j2p_a0_dnx_data_macsec_general_macsec_in_core_nof_set;
    data_index = dnx_data_macsec_general_define_ports_in_macsec_nof;
    define = &submodule->defines[data_index];
    define->set = j2p_a0_dnx_data_macsec_general_ports_in_macsec_nof_set;
    data_index = dnx_data_macsec_general_define_etype_nof;
    define = &submodule->defines[data_index];
    define->set = j2p_a0_dnx_data_macsec_general_etype_nof_set;
    data_index = dnx_data_macsec_general_define_etype_not_zero_verify;
    define = &submodule->defines[data_index];
    define->set = j2p_a0_dnx_data_macsec_general_etype_not_zero_verify_set;
    data_index = dnx_data_macsec_general_define_tx_threshold;
    define = &submodule->defines[data_index];
    define->set = j2p_a0_dnx_data_macsec_general_tx_threshold_set;
    data_index = dnx_data_macsec_general_define_macsec_tdm_cal_max_depth;
    define = &submodule->defines[data_index];
    define->set = j2p_a0_dnx_data_macsec_general_macsec_tdm_cal_max_depth_set;
    data_index = dnx_data_macsec_general_define_macsec_tdm_cal_hw_depth;
    define = &submodule->defines[data_index];
    define->set = j2p_a0_dnx_data_macsec_general_macsec_tdm_cal_hw_depth_set;
    data_index = dnx_data_macsec_general_define_association_number_full_range_nof;
    define = &submodule->defines[data_index];
    define->set = j2p_a0_dnx_data_macsec_general_association_number_full_range_nof_set;
    data_index = dnx_data_macsec_general_define_sectag_offset_min_value;
    define = &submodule->defines[data_index];
    define->set = j2p_a0_dnx_data_macsec_general_sectag_offset_min_value_set;
    data_index = dnx_data_macsec_general_define_supported_entries_nof;
    define = &submodule->defines[data_index];
    define->set = j2p_a0_dnx_data_macsec_general_supported_entries_nof_set;
    data_index = dnx_data_macsec_general_define_is_macsec_enabled;
    define = &submodule->defines[data_index];
    define->set = j2p_a0_dnx_data_macsec_general_is_macsec_enabled_set;
    data_index = dnx_data_macsec_general_define_is_power_optimization_enabled;
    define = &submodule->defines[data_index];
    define->set = j2p_a0_dnx_data_macsec_general_is_power_optimization_enabled_set;

    
    data_index = dnx_data_macsec_general_macsec_block_exists;
    feature = &submodule->features[data_index];
    feature->set = j2p_a0_dnx_data_macsec_general_macsec_block_exists_set;
    data_index = dnx_data_macsec_general_is_hw_reset_init_done_supported;
    feature = &submodule->features[data_index];
    feature->set = j2p_a0_dnx_data_macsec_general_is_hw_reset_init_done_supported_set;
    data_index = dnx_data_macsec_general_is_port_based_supported;
    feature = &submodule->features[data_index];
    feature->set = j2p_a0_dnx_data_macsec_general_is_port_based_supported_set;
    data_index = dnx_data_macsec_general_an_full_range_supported;
    feature = &submodule->features[data_index];
    feature->set = j2p_a0_dnx_data_macsec_general_an_full_range_supported_set;
    data_index = dnx_data_macsec_general_rfc_6054_supported;
    feature = &submodule->features[data_index];
    feature->set = j2p_a0_dnx_data_macsec_general_rfc_6054_supported_set;

    
    data_index = dnx_data_macsec_general_table_pm_to_macsec;
    table = &submodule->tables[data_index];
    table->set = j2p_a0_dnx_data_macsec_general_pm_to_macsec_set;
    data_index = dnx_data_macsec_general_table_macsec_instances;
    table = &submodule->tables[data_index];
    table->set = j2p_a0_dnx_data_macsec_general_macsec_instances_set;
    data_index = dnx_data_macsec_general_table_macsec_block_mapping;
    table = &submodule->tables[data_index];
    table->set = j2p_a0_dnx_data_macsec_general_macsec_block_mapping_set;
    
    submodule_index = dnx_data_macsec_submodule_ingress;
    submodule = &module->submodules[submodule_index];

    
    data_index = dnx_data_macsec_ingress_define_flow_nof;
    define = &submodule->defines[data_index];
    define->set = j2p_a0_dnx_data_macsec_ingress_flow_nof_set;
    data_index = dnx_data_macsec_ingress_define_policy_nof;
    define = &submodule->defines[data_index];
    define->set = j2p_a0_dnx_data_macsec_ingress_policy_nof_set;
    data_index = dnx_data_macsec_ingress_define_secure_assoc_nof;
    define = &submodule->defines[data_index];
    define->set = j2p_a0_dnx_data_macsec_ingress_secure_assoc_nof_set;
    data_index = dnx_data_macsec_ingress_define_udf_nof_bits;
    define = &submodule->defines[data_index];
    define->set = j2p_a0_dnx_data_macsec_ingress_udf_nof_bits_set;
    data_index = dnx_data_macsec_ingress_define_mgmt_rule_exact_nof;
    define = &submodule->defines[data_index];
    define->set = j2p_a0_dnx_data_macsec_ingress_mgmt_rule_exact_nof_set;
    data_index = dnx_data_macsec_ingress_define_tpid_nof;
    define = &submodule->defines[data_index];
    define->set = j2p_a0_dnx_data_macsec_ingress_tpid_nof_set;
    data_index = dnx_data_macsec_ingress_define_cpu_flex_map_nof;
    define = &submodule->defines[data_index];
    define->set = j2p_a0_dnx_data_macsec_ingress_cpu_flex_map_nof_set;
    data_index = dnx_data_macsec_ingress_define_sc_tcam_nof;
    define = &submodule->defines[data_index];
    define->set = j2p_a0_dnx_data_macsec_ingress_sc_tcam_nof_set;
    data_index = dnx_data_macsec_ingress_define_sa_per_sc_nof;
    define = &submodule->defines[data_index];
    define->set = j2p_a0_dnx_data_macsec_ingress_sa_per_sc_nof_set;
    data_index = dnx_data_macsec_ingress_define_invalidate_sa;
    define = &submodule->defines[data_index];
    define->set = j2p_a0_dnx_data_macsec_ingress_invalidate_sa_set;
    data_index = dnx_data_macsec_ingress_define_secure_channel_nof;
    define = &submodule->defines[data_index];
    define->set = j2p_a0_dnx_data_macsec_ingress_secure_channel_nof_set;

    

    
    data_index = dnx_data_macsec_ingress_table_udf;
    table = &submodule->tables[data_index];
    table->set = j2p_a0_dnx_data_macsec_ingress_udf_set;
    
    submodule_index = dnx_data_macsec_submodule_egress;
    submodule = &module->submodules[submodule_index];

    
    data_index = dnx_data_macsec_egress_define_secure_assoc_nof;
    define = &submodule->defines[data_index];
    define->set = j2p_a0_dnx_data_macsec_egress_secure_assoc_nof_set;
    data_index = dnx_data_macsec_egress_define_soft_expiry_threshold_profiles_nof;
    define = &submodule->defines[data_index];
    define->set = j2p_a0_dnx_data_macsec_egress_soft_expiry_threshold_profiles_nof_set;
    data_index = dnx_data_macsec_egress_define_an_bit_nof;
    define = &submodule->defines[data_index];
    define->set = j2p_a0_dnx_data_macsec_egress_an_bit_nof_set;
    data_index = dnx_data_macsec_egress_define_sa_per_sc_nof;
    define = &submodule->defines[data_index];
    define->set = j2p_a0_dnx_data_macsec_egress_sa_per_sc_nof_set;
    data_index = dnx_data_macsec_egress_define_secure_channel_nof;
    define = &submodule->defines[data_index];
    define->set = j2p_a0_dnx_data_macsec_egress_secure_channel_nof_set;

    

    

    SHR_FUNC_EXIT;
}
#undef BSL_LOG_MODULE

