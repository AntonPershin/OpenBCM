
/* *INDENT-OFF* */
/*
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2022 Broadcom Inc. All rights reserved.
 */
#ifdef BSL_LOG_MODULE
#error "BSL_LOG_MODULE redefined"
#endif
#define BSL_LOG_MODULE BSL_LS_BCMDNX_COMMON

#include <soc/dnx/dnx_data/auto_generated/dnx2/dnx_data_internal_dnx2_pemla_soc.h>








static shr_error_e
jr2_b0_dnx_data_dnx2_pemla_soc_soc_JR1_MODE_set(
    int unit)
{
    dnxc_data_define_t *define;
    int module_index = dnx_data_module_dnx2_pemla_soc;
    int submodule_index = dnx_data_dnx2_pemla_soc_submodule_soc;
    int define_index = dnx_data_dnx2_pemla_soc_soc_define_JR1_MODE;
    SHR_FUNC_INIT_VARS(unit);

    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_set(unit, "JR1_MODE", "DNX2");
    }

    define = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].defines[define_index];
    
    define->default_data = 0;

    
    define->data = 0;

    
    define->flags |= DNXC_DATA_F_SUPPORTED;

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_define_value_set(unit, define));


exit:
    SHR_FUNC_EXIT;
}


static shr_error_e
jr2_b0_dnx_data_dnx2_pemla_soc_soc_JR2_MODE_set(
    int unit)
{
    dnxc_data_define_t *define;
    int module_index = dnx_data_module_dnx2_pemla_soc;
    int submodule_index = dnx_data_dnx2_pemla_soc_submodule_soc;
    int define_index = dnx_data_dnx2_pemla_soc_soc_define_JR2_MODE;
    SHR_FUNC_INIT_VARS(unit);

    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_set(unit, "JR2_MODE", "DNX2");
    }

    define = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].defines[define_index];
    
    define->default_data = 1;

    
    define->data = 1;

    
    define->flags |= DNXC_DATA_F_SUPPORTED;

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_define_value_set(unit, define));


exit:
    SHR_FUNC_EXIT;
}


static shr_error_e
jr2_b0_dnx_data_dnx2_pemla_soc_soc_system_headers_mode_set(
    int unit)
{
    dnxc_data_define_t *define;
    int module_index = dnx_data_module_dnx2_pemla_soc;
    int submodule_index = dnx_data_dnx2_pemla_soc_submodule_soc;
    int define_index = dnx_data_dnx2_pemla_soc_soc_define_system_headers_mode;
    SHR_FUNC_INIT_VARS(unit);

    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_set(unit, "system_headers_mode", "DNX2");
    }

    define = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].defines[define_index];
    
    define->default_data = 1;

    
    define->data = 1;

    
    define->flags |= DNXC_DATA_F_SUPPORTED;
    
    define->property.name = spn_SYSTEM_HEADERS_MODE;
    define->property.doc = 
        "\n"
        "JR1_MODE: backward compatible with Jericho/Kalia\n"
        "JR2_MODE: not backward compatible\n"
    ;
    define->property.method = dnxc_data_property_method_enable;
    define->property.method_str = "enable";

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_define_value_set(unit, define));

    SHR_IF_ERR_EXIT(dnxc_data_mgmt_property_read(unit, &define->property, -1, &define->data));
    
    define->flags |= (DNXC_DATA_F_PROPERTY);

exit:
    SHR_FUNC_EXIT;
}




shr_error_e
jr2_b0_data_dnx2_pemla_soc_attach(
    int unit)
{
    dnxc_data_module_t *module = NULL;
    dnxc_data_submodule_t *submodule = NULL;
    dnxc_data_define_t *define = NULL;
    dnxc_data_feature_t *feature = NULL;
    dnxc_data_table_t *table = NULL;
    int module_index = dnx_data_module_dnx2_pemla_soc;
    int submodule_index = -1, data_index = -1;
    SHR_FUNC_INIT_VARS(unit);

    COMPILER_REFERENCE(define);
    COMPILER_REFERENCE(feature);
    COMPILER_REFERENCE(table);
    COMPILER_REFERENCE(submodule);
    COMPILER_REFERENCE(data_index);
    COMPILER_REFERENCE(submodule_index);
    module = &_dnxc_data[unit].modules[module_index];
    
    submodule_index = dnx_data_dnx2_pemla_soc_submodule_soc;
    submodule = &module->submodules[submodule_index];

    
    data_index = dnx_data_dnx2_pemla_soc_soc_define_JR1_MODE;
    define = &submodule->defines[data_index];
    define->set = jr2_b0_dnx_data_dnx2_pemla_soc_soc_JR1_MODE_set;
    data_index = dnx_data_dnx2_pemla_soc_soc_define_JR2_MODE;
    define = &submodule->defines[data_index];
    define->set = jr2_b0_dnx_data_dnx2_pemla_soc_soc_JR2_MODE_set;
    data_index = dnx_data_dnx2_pemla_soc_soc_define_system_headers_mode;
    define = &submodule->defines[data_index];
    define->set = jr2_b0_dnx_data_dnx2_pemla_soc_soc_system_headers_mode_set;

    

    

    SHR_FUNC_EXIT;
}
#undef BSL_LOG_MODULE

