
/* *INDENT-OFF* */
/*
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2022 Broadcom Inc. All rights reserved.
 */
#ifdef BSL_LOG_MODULE
#error "BSL_LOG_MODULE redefined"
#endif
#define BSL_LOG_MODULE BSL_LS_BCMDNX_L2

#include <soc/dnx/dnx_data/auto_generated/dnx_data_internal_l2.h>







static shr_error_e
jr2_b0_dnx_data_l2_general_aging_support_set(
    int unit)
{
    dnxc_data_feature_t *feature;
    int module_index = dnx_data_module_l2;
    int submodule_index = dnx_data_l2_submodule_general;
    int feature_index = dnx_data_l2_general_aging_support;
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
jr2_b0_dnx_data_l2_general_ivl_feature_support_set(
    int unit)
{
    dnxc_data_feature_t *feature;
    int module_index = dnx_data_module_l2;
    int submodule_index = dnx_data_l2_submodule_general;
    int feature_index = dnx_data_l2_general_ivl_feature_support;
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
jr2_b0_dnx_data_l2_feature_age_out_and_refresh_profile_selection_set(
    int unit)
{
    dnxc_data_feature_t *feature;
    int module_index = dnx_data_module_l2;
    int submodule_index = dnx_data_l2_submodule_feature;
    int feature_index = dnx_data_l2_feature_age_out_and_refresh_profile_selection;
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
jr2_b0_dnx_data_l2_feature_age_machine_pause_after_flush_set(
    int unit)
{
    dnxc_data_feature_t *feature;
    int module_index = dnx_data_module_l2;
    int submodule_index = dnx_data_l2_submodule_feature;
    int feature_index = dnx_data_l2_feature_age_machine_pause_after_flush;
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
jr2_b0_dnx_data_l2_feature_age_state_not_updated_set(
    int unit)
{
    dnxc_data_feature_t *feature;
    int module_index = dnx_data_module_l2;
    int submodule_index = dnx_data_l2_submodule_feature;
    int feature_index = dnx_data_l2_feature_age_state_not_updated;
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
jr2_b0_dnx_data_l2_feature_eth_qual_is_mc_set(
    int unit)
{
    dnxc_data_feature_t *feature;
    int module_index = dnx_data_module_l2;
    int submodule_index = dnx_data_l2_submodule_feature;
    int feature_index = dnx_data_l2_feature_eth_qual_is_mc;
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
jr2_b0_dnx_data_l2_feature_bc_same_as_unknown_mc_set(
    int unit)
{
    dnxc_data_feature_t *feature;
    int module_index = dnx_data_module_l2;
    int submodule_index = dnx_data_l2_submodule_feature;
    int feature_index = dnx_data_l2_feature_bc_same_as_unknown_mc;
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
jr2_b0_dnx_data_l2_feature_wrong_limit_interrupt_handling_set(
    int unit)
{
    dnxc_data_feature_t *feature;
    int module_index = dnx_data_module_l2;
    int submodule_index = dnx_data_l2_submodule_feature;
    int feature_index = dnx_data_l2_feature_wrong_limit_interrupt_handling;
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
jr2_b0_dnx_data_l2_feature_transplant_instead_of_refresh_set(
    int unit)
{
    dnxc_data_feature_t *feature;
    int module_index = dnx_data_module_l2;
    int submodule_index = dnx_data_l2_submodule_feature;
    int feature_index = dnx_data_l2_feature_transplant_instead_of_refresh;
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
jr2_b0_dnx_data_l2_feature_static_mac_age_out_set(
    int unit)
{
    dnxc_data_feature_t *feature;
    int module_index = dnx_data_module_l2;
    int submodule_index = dnx_data_l2_submodule_feature;
    int feature_index = dnx_data_l2_feature_static_mac_age_out;
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
jr2_b0_dnx_data_l2_feature_vmv_for_limit_in_wrong_location_set(
    int unit)
{
    dnxc_data_feature_t *feature;
    int module_index = dnx_data_module_l2;
    int submodule_index = dnx_data_l2_submodule_feature;
    int feature_index = dnx_data_l2_feature_vmv_for_limit_in_wrong_location;
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
jr2_b0_dnx_data_l2_feature_learn_limit_set(
    int unit)
{
    dnxc_data_feature_t *feature;
    int module_index = dnx_data_module_l2;
    int submodule_index = dnx_data_l2_submodule_feature;
    int feature_index = dnx_data_l2_feature_learn_limit;
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
jr2_b0_dnx_data_l2_feature_learn_events_wrong_command_set(
    int unit)
{
    dnxc_data_feature_t *feature;
    int module_index = dnx_data_module_l2;
    int submodule_index = dnx_data_l2_submodule_feature;
    int feature_index = dnx_data_l2_feature_learn_events_wrong_command;
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
jr2_b0_dnx_data_l2_feature_ignore_limit_check_set(
    int unit)
{
    dnxc_data_feature_t *feature;
    int module_index = dnx_data_module_l2;
    int submodule_index = dnx_data_l2_submodule_feature;
    int feature_index = dnx_data_l2_feature_ignore_limit_check;
    SHR_FUNC_INIT_VARS(unit);

    feature = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].features[feature_index];
    
    feature->default_data = 0;

    
    feature->data = 0;

    
    feature->flags |= DNXC_DATA_F_SUPPORTED;

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_feature_value_set(unit, feature));

exit:
    SHR_FUNC_EXIT;
}





shr_error_e
jr2_b0_data_l2_attach(
    int unit)
{
    dnxc_data_module_t *module = NULL;
    dnxc_data_submodule_t *submodule = NULL;
    dnxc_data_define_t *define = NULL;
    dnxc_data_feature_t *feature = NULL;
    dnxc_data_table_t *table = NULL;
    int module_index = dnx_data_module_l2;
    int submodule_index = -1, data_index = -1;
    SHR_FUNC_INIT_VARS(unit);

    COMPILER_REFERENCE(define);
    COMPILER_REFERENCE(feature);
    COMPILER_REFERENCE(table);
    COMPILER_REFERENCE(submodule);
    COMPILER_REFERENCE(data_index);
    COMPILER_REFERENCE(submodule_index);
    module = &_dnxc_data[unit].modules[module_index];
    
    submodule_index = dnx_data_l2_submodule_general;
    submodule = &module->submodules[submodule_index];

    

    
    data_index = dnx_data_l2_general_aging_support;
    feature = &submodule->features[data_index];
    feature->set = jr2_b0_dnx_data_l2_general_aging_support_set;
    data_index = dnx_data_l2_general_ivl_feature_support;
    feature = &submodule->features[data_index];
    feature->set = jr2_b0_dnx_data_l2_general_ivl_feature_support_set;

    
    
    submodule_index = dnx_data_l2_submodule_feature;
    submodule = &module->submodules[submodule_index];

    

    
    data_index = dnx_data_l2_feature_age_out_and_refresh_profile_selection;
    feature = &submodule->features[data_index];
    feature->set = jr2_b0_dnx_data_l2_feature_age_out_and_refresh_profile_selection_set;
    data_index = dnx_data_l2_feature_age_machine_pause_after_flush;
    feature = &submodule->features[data_index];
    feature->set = jr2_b0_dnx_data_l2_feature_age_machine_pause_after_flush_set;
    data_index = dnx_data_l2_feature_age_state_not_updated;
    feature = &submodule->features[data_index];
    feature->set = jr2_b0_dnx_data_l2_feature_age_state_not_updated_set;
    data_index = dnx_data_l2_feature_eth_qual_is_mc;
    feature = &submodule->features[data_index];
    feature->set = jr2_b0_dnx_data_l2_feature_eth_qual_is_mc_set;
    data_index = dnx_data_l2_feature_bc_same_as_unknown_mc;
    feature = &submodule->features[data_index];
    feature->set = jr2_b0_dnx_data_l2_feature_bc_same_as_unknown_mc_set;
    data_index = dnx_data_l2_feature_wrong_limit_interrupt_handling;
    feature = &submodule->features[data_index];
    feature->set = jr2_b0_dnx_data_l2_feature_wrong_limit_interrupt_handling_set;
    data_index = dnx_data_l2_feature_transplant_instead_of_refresh;
    feature = &submodule->features[data_index];
    feature->set = jr2_b0_dnx_data_l2_feature_transplant_instead_of_refresh_set;
    data_index = dnx_data_l2_feature_static_mac_age_out;
    feature = &submodule->features[data_index];
    feature->set = jr2_b0_dnx_data_l2_feature_static_mac_age_out_set;
    data_index = dnx_data_l2_feature_vmv_for_limit_in_wrong_location;
    feature = &submodule->features[data_index];
    feature->set = jr2_b0_dnx_data_l2_feature_vmv_for_limit_in_wrong_location_set;
    data_index = dnx_data_l2_feature_learn_limit;
    feature = &submodule->features[data_index];
    feature->set = jr2_b0_dnx_data_l2_feature_learn_limit_set;
    data_index = dnx_data_l2_feature_learn_events_wrong_command;
    feature = &submodule->features[data_index];
    feature->set = jr2_b0_dnx_data_l2_feature_learn_events_wrong_command_set;
    data_index = dnx_data_l2_feature_ignore_limit_check;
    feature = &submodule->features[data_index];
    feature->set = jr2_b0_dnx_data_l2_feature_ignore_limit_check_set;

    

    SHR_FUNC_EXIT;
}
#undef BSL_LOG_MODULE

