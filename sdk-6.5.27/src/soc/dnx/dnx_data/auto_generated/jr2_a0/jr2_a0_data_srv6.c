
/* *INDENT-OFF* */
/*
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2022 Broadcom Inc. All rights reserved.
 */
#ifdef BSL_LOG_MODULE
#error "BSL_LOG_MODULE redefined"
#endif
#define BSL_LOG_MODULE BSL_LS_BCMDNX_SRV6

#include <soc/dnx/dnx_data/auto_generated/dnx_data_internal_srv6.h>







static shr_error_e
jr2_a0_dnx_data_srv6_general_jr2_compatible_set(
    int unit)
{
    dnxc_data_feature_t *feature;
    int module_index = dnx_data_module_srv6;
    int submodule_index = dnx_data_srv6_submodule_general;
    int feature_index = dnx_data_srv6_general_jr2_compatible;
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
jr2_a0_dnx_data_srv6_general_srv6_gsid_prefix_64b_enable_set(
    int unit)
{
    dnxc_data_feature_t *feature;
    int module_index = dnx_data_module_srv6;
    int submodule_index = dnx_data_srv6_submodule_general;
    int feature_index = dnx_data_srv6_general_srv6_gsid_prefix_64b_enable;
    SHR_FUNC_INIT_VARS(unit);

    feature = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].features[feature_index];
    
    feature->default_data = 0;

    
    feature->data = 0;

    
    feature->flags |= DNXC_DATA_F_SUPPORTED;
    
    feature->property.name = spn_APPL_PARAM;
    feature->property.doc = 
        "\n"
    ;
    feature->property.method = dnxc_data_property_method_suffix_enable;
    feature->property.method_str = "suffix_enable";
    feature->property.suffix = "srv6_gsid_prefix_64b_enable";
    SHR_IF_ERR_EXIT(dnxc_data_mgmt_property_read(unit, &feature->property, -1, &feature->data));
    
    feature->flags |= (DNXC_DATA_F_PROPERTY);


    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_feature_value_set(unit, feature));

exit:
    SHR_FUNC_EXIT;
}


static shr_error_e
jr2_a0_dnx_data_srv6_general_srv6_usid_prefix_48b_enable_set(
    int unit)
{
    dnxc_data_feature_t *feature;
    int module_index = dnx_data_module_srv6;
    int submodule_index = dnx_data_srv6_submodule_general;
    int feature_index = dnx_data_srv6_general_srv6_usid_prefix_48b_enable;
    SHR_FUNC_INIT_VARS(unit);

    feature = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].features[feature_index];
    
    feature->default_data = 0;

    
    feature->data = 0;

    
    feature->flags |= DNXC_DATA_F_SUPPORTED;
    
    feature->property.name = spn_APPL_PARAM;
    feature->property.doc = 
        "\n"
    ;
    feature->property.method = dnxc_data_property_method_suffix_enable;
    feature->property.method_str = "suffix_enable";
    feature->property.suffix = "srv6_usid_prefix_48b_enable";
    SHR_IF_ERR_EXIT(dnxc_data_mgmt_property_read(unit, &feature->property, -1, &feature->data));
    
    feature->flags |= (DNXC_DATA_F_PROPERTY);


    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_feature_value_set(unit, feature));

exit:
    SHR_FUNC_EXIT;
}







static shr_error_e
jr2_a0_dnx_data_srv6_termination_srv6_psp_enable_set(
    int unit)
{
    dnxc_data_feature_t *feature;
    int module_index = dnx_data_module_srv6;
    int submodule_index = dnx_data_srv6_submodule_termination;
    int feature_index = dnx_data_srv6_termination_srv6_psp_enable;
    SHR_FUNC_INIT_VARS(unit);

    feature = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].features[feature_index];
    
    feature->default_data = 0;

    
    feature->data = 0;

    
    feature->flags |= DNXC_DATA_F_SUPPORTED;
    
    feature->property.name = spn_APPL_PARAM;
    feature->property.doc = 
        "\n"
    ;
    feature->property.method = dnxc_data_property_method_suffix_enable;
    feature->property.method_str = "suffix_enable";
    feature->property.suffix = "srv6_psp_enable";
    SHR_IF_ERR_EXIT(dnxc_data_mgmt_property_read(unit, &feature->property, -1, &feature->data));
    
    feature->flags |= (DNXC_DATA_F_PROPERTY);


    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_feature_value_set(unit, feature));

exit:
    SHR_FUNC_EXIT;
}



static shr_error_e
jr2_a0_dnx_data_srv6_termination_max_nof_terminated_sids_psp_extended_set(
    int unit)
{
    dnxc_data_define_t *define;
    int module_index = dnx_data_module_srv6;
    int submodule_index = dnx_data_srv6_submodule_termination;
    int define_index = dnx_data_srv6_termination_define_max_nof_terminated_sids_psp_extended;
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
jr2_a0_dnx_data_srv6_termination_max_nof_terminated_sids_psp_set(
    int unit)
{
    dnxc_data_define_t *define;
    int module_index = dnx_data_module_srv6;
    int submodule_index = dnx_data_srv6_submodule_termination;
    int define_index = dnx_data_srv6_termination_define_max_nof_terminated_sids_psp;
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
jr2_a0_dnx_data_srv6_termination_max_nof_terminated_sids_usp_set(
    int unit)
{
    dnxc_data_define_t *define;
    int module_index = dnx_data_module_srv6;
    int submodule_index = dnx_data_srv6_submodule_termination;
    int define_index = dnx_data_srv6_termination_define_max_nof_terminated_sids_usp;
    SHR_FUNC_INIT_VARS(unit);

    define = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].defines[define_index];
    
    define->default_data = 9;

    
    define->data = 9;

    
    define->flags |= DNXC_DATA_F_SUPPORTED;

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_define_value_set(unit, define));


exit:
    SHR_FUNC_EXIT;
}


static shr_error_e
jr2_a0_dnx_data_srv6_termination_max_nof_terminated_sids_usp_1pass_set(
    int unit)
{
    dnxc_data_define_t *define;
    int module_index = dnx_data_module_srv6;
    int submodule_index = dnx_data_srv6_submodule_termination;
    int define_index = dnx_data_srv6_termination_define_max_nof_terminated_sids_usp_1pass;
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
jr2_a0_dnx_data_srv6_termination_max_nof_terminated_sids_usd_1pass_set(
    int unit)
{
    dnxc_data_define_t *define;
    int module_index = dnx_data_module_srv6;
    int submodule_index = dnx_data_srv6_submodule_termination;
    int define_index = dnx_data_srv6_termination_define_max_nof_terminated_sids_usd_1pass;
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
jr2_a0_dnx_data_srv6_termination_max_nof_locators_set(
    int unit)
{
    dnxc_data_define_t *define;
    int module_index = dnx_data_module_srv6;
    int submodule_index = dnx_data_srv6_submodule_termination;
    int define_index = dnx_data_srv6_termination_define_max_nof_locators;
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
jr2_a0_dnx_data_srv6_encapsulation_is_t_insert_support_set(
    int unit)
{
    dnxc_data_feature_t *feature;
    int module_index = dnx_data_module_srv6;
    int submodule_index = dnx_data_srv6_submodule_encapsulation;
    int feature_index = dnx_data_srv6_encapsulation_is_t_insert_support;
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
jr2_a0_dnx_data_srv6_encapsulation_srv6_reduce_enable_set(
    int unit)
{
    dnxc_data_feature_t *feature;
    int module_index = dnx_data_module_srv6;
    int submodule_index = dnx_data_srv6_submodule_encapsulation;
    int feature_index = dnx_data_srv6_encapsulation_srv6_reduce_enable;
    SHR_FUNC_INIT_VARS(unit);

    feature = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].features[feature_index];
    
    feature->default_data = 0;

    
    feature->data = 0;

    
    feature->flags |= DNXC_DATA_F_SUPPORTED;
    
    feature->property.name = spn_APPL_PARAM;
    feature->property.doc = 
        "\n"
    ;
    feature->property.method = dnxc_data_property_method_suffix_enable;
    feature->property.method_str = "suffix_enable";
    feature->property.suffix = "srv6_reduce_enable";
    SHR_IF_ERR_EXIT(dnxc_data_mgmt_property_read(unit, &feature->property, -1, &feature->data));
    
    feature->flags |= (DNXC_DATA_F_PROPERTY);


    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_feature_value_set(unit, feature));

exit:
    SHR_FUNC_EXIT;
}



static shr_error_e
jr2_a0_dnx_data_srv6_encapsulation_max_nof_encap_sids_main_pass_set(
    int unit)
{
    dnxc_data_define_t *define;
    int module_index = dnx_data_module_srv6;
    int submodule_index = dnx_data_srv6_submodule_encapsulation;
    int define_index = dnx_data_srv6_encapsulation_define_max_nof_encap_sids_main_pass;
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
jr2_a0_dnx_data_srv6_encapsulation_nof_encap_sids_extended_pass_set(
    int unit)
{
    dnxc_data_define_t *define;
    int module_index = dnx_data_module_srv6;
    int submodule_index = dnx_data_srv6_submodule_encapsulation;
    int define_index = dnx_data_srv6_encapsulation_define_nof_encap_sids_extended_pass;
    SHR_FUNC_INIT_VARS(unit);

    define = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].defines[define_index];
    
    define->default_data = 5;

    
    define->data = 5;

    
    define->flags |= DNXC_DATA_F_SUPPORTED;

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_define_value_set(unit, define));


exit:
    SHR_FUNC_EXIT;
}









shr_error_e
jr2_a0_data_srv6_attach(
    int unit)
{
    dnxc_data_module_t *module = NULL;
    dnxc_data_submodule_t *submodule = NULL;
    dnxc_data_define_t *define = NULL;
    dnxc_data_feature_t *feature = NULL;
    dnxc_data_table_t *table = NULL;
    int module_index = dnx_data_module_srv6;
    int submodule_index = -1, data_index = -1;
    SHR_FUNC_INIT_VARS(unit);

    COMPILER_REFERENCE(define);
    COMPILER_REFERENCE(feature);
    COMPILER_REFERENCE(table);
    COMPILER_REFERENCE(submodule);
    COMPILER_REFERENCE(data_index);
    COMPILER_REFERENCE(submodule_index);
    module = &_dnxc_data[unit].modules[module_index];
    
    submodule_index = dnx_data_srv6_submodule_general;
    submodule = &module->submodules[submodule_index];

    

    
    data_index = dnx_data_srv6_general_jr2_compatible;
    feature = &submodule->features[data_index];
    feature->set = jr2_a0_dnx_data_srv6_general_jr2_compatible_set;
    data_index = dnx_data_srv6_general_srv6_gsid_prefix_64b_enable;
    feature = &submodule->features[data_index];
    feature->set = jr2_a0_dnx_data_srv6_general_srv6_gsid_prefix_64b_enable_set;
    data_index = dnx_data_srv6_general_srv6_usid_prefix_48b_enable;
    feature = &submodule->features[data_index];
    feature->set = jr2_a0_dnx_data_srv6_general_srv6_usid_prefix_48b_enable_set;

    
    
    submodule_index = dnx_data_srv6_submodule_termination;
    submodule = &module->submodules[submodule_index];

    
    data_index = dnx_data_srv6_termination_define_max_nof_terminated_sids_psp_extended;
    define = &submodule->defines[data_index];
    define->set = jr2_a0_dnx_data_srv6_termination_max_nof_terminated_sids_psp_extended_set;
    data_index = dnx_data_srv6_termination_define_max_nof_terminated_sids_psp;
    define = &submodule->defines[data_index];
    define->set = jr2_a0_dnx_data_srv6_termination_max_nof_terminated_sids_psp_set;
    data_index = dnx_data_srv6_termination_define_max_nof_terminated_sids_usp;
    define = &submodule->defines[data_index];
    define->set = jr2_a0_dnx_data_srv6_termination_max_nof_terminated_sids_usp_set;
    data_index = dnx_data_srv6_termination_define_max_nof_terminated_sids_usp_1pass;
    define = &submodule->defines[data_index];
    define->set = jr2_a0_dnx_data_srv6_termination_max_nof_terminated_sids_usp_1pass_set;
    data_index = dnx_data_srv6_termination_define_max_nof_terminated_sids_usd_1pass;
    define = &submodule->defines[data_index];
    define->set = jr2_a0_dnx_data_srv6_termination_max_nof_terminated_sids_usd_1pass_set;
    data_index = dnx_data_srv6_termination_define_max_nof_locators;
    define = &submodule->defines[data_index];
    define->set = jr2_a0_dnx_data_srv6_termination_max_nof_locators_set;

    
    data_index = dnx_data_srv6_termination_srv6_psp_enable;
    feature = &submodule->features[data_index];
    feature->set = jr2_a0_dnx_data_srv6_termination_srv6_psp_enable_set;

    
    
    submodule_index = dnx_data_srv6_submodule_encapsulation;
    submodule = &module->submodules[submodule_index];

    
    data_index = dnx_data_srv6_encapsulation_define_max_nof_encap_sids_main_pass;
    define = &submodule->defines[data_index];
    define->set = jr2_a0_dnx_data_srv6_encapsulation_max_nof_encap_sids_main_pass_set;
    data_index = dnx_data_srv6_encapsulation_define_nof_encap_sids_extended_pass;
    define = &submodule->defines[data_index];
    define->set = jr2_a0_dnx_data_srv6_encapsulation_nof_encap_sids_extended_pass_set;

    
    data_index = dnx_data_srv6_encapsulation_is_t_insert_support;
    feature = &submodule->features[data_index];
    feature->set = jr2_a0_dnx_data_srv6_encapsulation_is_t_insert_support_set;
    data_index = dnx_data_srv6_encapsulation_srv6_reduce_enable;
    feature = &submodule->features[data_index];
    feature->set = jr2_a0_dnx_data_srv6_encapsulation_srv6_reduce_enable_set;

    
    
    submodule_index = dnx_data_srv6_submodule_endpoint;
    submodule = &module->submodules[submodule_index];

    

    

    

    SHR_FUNC_EXIT;
}
#undef BSL_LOG_MODULE

