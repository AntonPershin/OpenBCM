
/* *INDENT-OFF* */
/*
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2022 Broadcom Inc. All rights reserved.
 */
#ifdef BSL_LOG_MODULE
#error "BSL_LOG_MODULE redefined"
#endif
#define BSL_LOG_MODULE BSL_LS_BCMDNX_EGRESSDNX

#include <soc/dnx/dnx_data/auto_generated/dnx_data_internal_tdm.h>
#include <bcm_int/dnx/tdm/tdm.h>








static shr_error_e
jr2_a0_dnx_data_tdm_params_global_sid_offset_size_set(
    int unit)
{
    dnxc_data_define_t *define;
    int module_index = dnx_data_module_tdm;
    int submodule_index = dnx_data_tdm_submodule_params;
    int define_index = dnx_data_tdm_params_define_global_sid_offset_size;
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
jr2_a0_dnx_data_tdm_params_pkt_size_size_set(
    int unit)
{
    dnxc_data_define_t *define;
    int module_index = dnx_data_module_tdm;
    int submodule_index = dnx_data_tdm_submodule_params;
    int define_index = dnx_data_tdm_params_define_pkt_size_size;
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
jr2_a0_dnx_data_tdm_params_mode_set(
    int unit)
{
    dnxc_data_define_t *define;
    int module_index = dnx_data_module_tdm;
    int submodule_index = dnx_data_tdm_submodule_params;
    int define_index = dnx_data_tdm_params_define_mode;
    SHR_FUNC_INIT_VARS(unit);

    define = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].defines[define_index];
    
    define->default_data = TDM_MODE_NONE;

    
    define->data = TDM_MODE_NONE;

    
    define->flags |= DNXC_DATA_F_SUPPORTED;
    
    define->property.name = spn_TDM_MODE;
    define->property.doc = 
        "TDM system mode\n"
    ;
    define->property.method = dnxc_data_property_method_direct_map;
    define->property.method_str = "direct_map";
    define->property.nof_mapping = 1;
    DNXC_DATA_ALLOC(define->property.mapping, dnxc_data_property_map_t, define->property.nof_mapping, "dnxc_data property mapping");

    define->property.mapping[0].name = "TDM_NONE";
    define->property.mapping[0].val = TDM_MODE_NONE;
    define->property.mapping[0].is_default = 1 ;

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_define_value_set(unit, define));

    SHR_IF_ERR_EXIT(dnxc_data_mgmt_property_read(unit, &define->property, -1, &define->data));
    
    define->flags |= (DNXC_DATA_F_PROPERTY);

exit:
    SHR_FUNC_EXIT;
}




shr_error_e
jr2_a0_data_tdm_attach(
    int unit)
{
    dnxc_data_module_t *module = NULL;
    dnxc_data_submodule_t *submodule = NULL;
    dnxc_data_define_t *define = NULL;
    dnxc_data_feature_t *feature = NULL;
    dnxc_data_table_t *table = NULL;
    int module_index = dnx_data_module_tdm;
    int submodule_index = -1, data_index = -1;
    SHR_FUNC_INIT_VARS(unit);

    COMPILER_REFERENCE(define);
    COMPILER_REFERENCE(feature);
    COMPILER_REFERENCE(table);
    COMPILER_REFERENCE(submodule);
    COMPILER_REFERENCE(data_index);
    COMPILER_REFERENCE(submodule_index);
    module = &_dnxc_data[unit].modules[module_index];
    
    submodule_index = dnx_data_tdm_submodule_params;
    submodule = &module->submodules[submodule_index];

    
    data_index = dnx_data_tdm_params_define_global_sid_offset_size;
    define = &submodule->defines[data_index];
    define->set = jr2_a0_dnx_data_tdm_params_global_sid_offset_size_set;
    data_index = dnx_data_tdm_params_define_pkt_size_size;
    define = &submodule->defines[data_index];
    define->set = jr2_a0_dnx_data_tdm_params_pkt_size_size_set;
    data_index = dnx_data_tdm_params_define_mode;
    define = &submodule->defines[data_index];
    define->set = jr2_a0_dnx_data_tdm_params_mode_set;

    

    

    SHR_FUNC_EXIT;
}
#undef BSL_LOG_MODULE

