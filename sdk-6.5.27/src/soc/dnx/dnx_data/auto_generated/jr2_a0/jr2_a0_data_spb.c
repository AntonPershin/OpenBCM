
/* *INDENT-OFF* */
/*
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2022 Broadcom Inc. All rights reserved.
 */
#ifdef BSL_LOG_MODULE
#error "BSL_LOG_MODULE redefined"
#endif
#define BSL_LOG_MODULE BSL_LS_BCMDNX_SWITCH

#include <soc/dnx/dnx_data/auto_generated/dnx_data_internal_spb.h>







static shr_error_e
jr2_a0_dnx_data_spb_ocb_configure_banks_full_threshold_set(
    int unit)
{
    dnxc_data_feature_t *feature;
    int module_index = dnx_data_module_spb;
    int submodule_index = dnx_data_spb_submodule_ocb;
    int feature_index = dnx_data_spb_ocb_configure_banks_full_threshold;
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
jr2_a0_dnx_data_spb_ocb_nof_banks_per_ring_set(
    int unit)
{
    dnxc_data_define_t *define;
    int module_index = dnx_data_module_spb;
    int submodule_index = dnx_data_spb_submodule_ocb;
    int define_index = dnx_data_spb_ocb_define_nof_banks_per_ring;
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
jr2_a0_dnx_data_spb_ocb_buffer_ptr_nof_bits_set(
    int unit)
{
    dnxc_data_define_t *define;
    int module_index = dnx_data_module_spb;
    int submodule_index = dnx_data_spb_submodule_ocb;
    int define_index = dnx_data_spb_ocb_define_buffer_ptr_nof_bits;
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
jr2_a0_dnx_data_spb_ocb_sram_in_power_down_set(
    int unit)
{
    dnxc_data_define_t *define;
    int module_index = dnx_data_module_spb;
    int submodule_index = dnx_data_spb_submodule_ocb;
    int define_index = dnx_data_spb_ocb_define_sram_in_power_down;
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
jr2_a0_dnx_data_spb_ocb_bank_full_threshold_bits_set(
    int unit)
{
    dnxc_data_define_t *define;
    int module_index = dnx_data_module_spb;
    int submodule_index = dnx_data_spb_submodule_ocb;
    int define_index = dnx_data_spb_ocb_define_bank_full_threshold_bits;
    SHR_FUNC_INIT_VARS(unit);

    define = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].defines[define_index];
    
    define->default_data = 13;

    
    define->data = 13;

    
    define->flags |= DNXC_DATA_F_SUPPORTED;

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_define_value_set(unit, define));


exit:
    SHR_FUNC_EXIT;
}


static shr_error_e
jr2_a0_dnx_data_spb_ocb_bank_full_threshold_set(
    int unit)
{
    dnxc_data_define_t *define;
    int module_index = dnx_data_module_spb;
    int submodule_index = dnx_data_spb_submodule_ocb;
    int define_index = dnx_data_spb_ocb_define_bank_full_threshold;
    SHR_FUNC_INIT_VARS(unit);

    define = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].defines[define_index];
    
    define->default_data = 32;

    
    define->data = 32;

    
    define->flags |= DNXC_DATA_F_SUPPORTED;

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_define_value_set(unit, define));


exit:
    SHR_FUNC_EXIT;
}




shr_error_e
jr2_a0_data_spb_attach(
    int unit)
{
    dnxc_data_module_t *module = NULL;
    dnxc_data_submodule_t *submodule = NULL;
    dnxc_data_define_t *define = NULL;
    dnxc_data_feature_t *feature = NULL;
    dnxc_data_table_t *table = NULL;
    int module_index = dnx_data_module_spb;
    int submodule_index = -1, data_index = -1;
    SHR_FUNC_INIT_VARS(unit);

    COMPILER_REFERENCE(define);
    COMPILER_REFERENCE(feature);
    COMPILER_REFERENCE(table);
    COMPILER_REFERENCE(submodule);
    COMPILER_REFERENCE(data_index);
    COMPILER_REFERENCE(submodule_index);
    module = &_dnxc_data[unit].modules[module_index];
    
    submodule_index = dnx_data_spb_submodule_ocb;
    submodule = &module->submodules[submodule_index];

    
    data_index = dnx_data_spb_ocb_define_nof_banks_per_ring;
    define = &submodule->defines[data_index];
    define->set = jr2_a0_dnx_data_spb_ocb_nof_banks_per_ring_set;
    data_index = dnx_data_spb_ocb_define_buffer_ptr_nof_bits;
    define = &submodule->defines[data_index];
    define->set = jr2_a0_dnx_data_spb_ocb_buffer_ptr_nof_bits_set;
    data_index = dnx_data_spb_ocb_define_sram_in_power_down;
    define = &submodule->defines[data_index];
    define->set = jr2_a0_dnx_data_spb_ocb_sram_in_power_down_set;
    data_index = dnx_data_spb_ocb_define_bank_full_threshold_bits;
    define = &submodule->defines[data_index];
    define->set = jr2_a0_dnx_data_spb_ocb_bank_full_threshold_bits_set;
    data_index = dnx_data_spb_ocb_define_bank_full_threshold;
    define = &submodule->defines[data_index];
    define->set = jr2_a0_dnx_data_spb_ocb_bank_full_threshold_set;

    
    data_index = dnx_data_spb_ocb_configure_banks_full_threshold;
    feature = &submodule->features[data_index];
    feature->set = jr2_a0_dnx_data_spb_ocb_configure_banks_full_threshold_set;

    

    SHR_FUNC_EXIT;
}
#undef BSL_LOG_MODULE

