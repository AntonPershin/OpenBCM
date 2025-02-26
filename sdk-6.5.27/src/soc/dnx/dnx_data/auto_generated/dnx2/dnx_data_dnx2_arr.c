
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

#include <soc/dnx/dnx_data/auto_generated/dnx2/dnx_data_internal_dnx2_arr.h>




extern shr_error_e jr2_a0_standard_1_data_dnx2_arr_attach(
    int unit);


extern shr_error_e jr2_b0_standard_1_data_dnx2_arr_attach(
    int unit);


extern shr_error_e j2c_a0_standard_1_data_dnx2_arr_attach(
    int unit);


extern shr_error_e q2a_a0_standard_1_data_dnx2_arr_attach(
    int unit);


extern shr_error_e q2a_b0_standard_1_data_dnx2_arr_attach(
    int unit);


extern shr_error_e j2p_a0_standard_1_data_dnx2_arr_attach(
    int unit);


extern shr_error_e j2x_a0_standard_1_data_dnx2_arr_attach(
    int unit);




static shr_error_e
dnx_data_dnx2_arr_prefix_init(
    int unit,
    dnxc_data_submodule_t *submodule_data)
{
    SHR_FUNC_INIT_VARS(unit);

    submodule_data->name = "prefix";
    submodule_data->doc = "";
    
    submodule_data->nof_features = _dnx_data_dnx2_arr_prefix_feature_nof;
    DNXC_DATA_ALLOC(submodule_data->features, dnxc_data_feature_t,  submodule_data->nof_features, "_dnxc_data dnx2_arr prefix features");

    
    submodule_data->nof_defines = _dnx_data_dnx2_arr_prefix_define_nof;
    DNXC_DATA_ALLOC(submodule_data->defines, dnxc_data_define_t, submodule_data->nof_defines, "_dnxc_data dnx2_arr prefix defines");

    if (soc_is(unit, DNX2_DEVICE))
    {
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_ETPP_ETPS_FORMATS___prefix_0].name = "ETPP_ETPS_FORMATS___prefix_0";
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_ETPP_ETPS_FORMATS___prefix_0].doc = "";
        
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_ETPP_ETPS_FORMATS___prefix_0].flags |= DNXC_DATA_F_DEFINE;
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_ETPP_ETPS_FORMATS___prefix_1].name = "ETPP_ETPS_FORMATS___prefix_1";
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_ETPP_ETPS_FORMATS___prefix_1].doc = "";
        
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_ETPP_ETPS_FORMATS___prefix_1].flags |= DNXC_DATA_F_DEFINE;
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_ETPP_ETPS_FORMATS___prefix_2].name = "ETPP_ETPS_FORMATS___prefix_2";
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_ETPP_ETPS_FORMATS___prefix_2].doc = "";
        
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_ETPP_ETPS_FORMATS___prefix_2].flags |= DNXC_DATA_F_DEFINE;
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_ETPP_ETPS_FORMATS___prefix_3].name = "ETPP_ETPS_FORMATS___prefix_3";
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_ETPP_ETPS_FORMATS___prefix_3].doc = "";
        
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_ETPP_ETPS_FORMATS___prefix_3].flags |= DNXC_DATA_F_DEFINE;
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_ETPP_ETPS_FORMATS___prefix_4].name = "ETPP_ETPS_FORMATS___prefix_4";
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_ETPP_ETPS_FORMATS___prefix_4].doc = "";
        
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_ETPP_ETPS_FORMATS___prefix_4].flags |= DNXC_DATA_F_DEFINE;
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_ETPP_ETPS_FORMATS___prefix_5].name = "ETPP_ETPS_FORMATS___prefix_5";
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_ETPP_ETPS_FORMATS___prefix_5].doc = "";
        
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_ETPP_ETPS_FORMATS___prefix_5].flags |= DNXC_DATA_F_DEFINE;
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_ETPP_ETPS_FORMATS___prefix_6].name = "ETPP_ETPS_FORMATS___prefix_6";
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_ETPP_ETPS_FORMATS___prefix_6].doc = "";
        
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_ETPP_ETPS_FORMATS___prefix_6].flags |= DNXC_DATA_F_DEFINE;
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_ETPP_ETPS_FORMATS___prefix_7].name = "ETPP_ETPS_FORMATS___prefix_7";
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_ETPP_ETPS_FORMATS___prefix_7].doc = "";
        
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_ETPP_ETPS_FORMATS___prefix_7].flags |= DNXC_DATA_F_DEFINE;
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_ETPP_ETPS_FORMATS___prefix_8].name = "ETPP_ETPS_FORMATS___prefix_8";
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_ETPP_ETPS_FORMATS___prefix_8].doc = "";
        
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_ETPP_ETPS_FORMATS___prefix_8].flags |= DNXC_DATA_F_DEFINE;
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_ETPP_ETPS_FORMATS___prefix_9].name = "ETPP_ETPS_FORMATS___prefix_9";
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_ETPP_ETPS_FORMATS___prefix_9].doc = "";
        
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_ETPP_ETPS_FORMATS___prefix_9].flags |= DNXC_DATA_F_DEFINE;
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_ETPP_ETPS_FORMATS___prefix_10].name = "ETPP_ETPS_FORMATS___prefix_10";
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_ETPP_ETPS_FORMATS___prefix_10].doc = "";
        
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_ETPP_ETPS_FORMATS___prefix_10].flags |= DNXC_DATA_F_DEFINE;
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_ETPP_ETPS_FORMATS___prefix_11].name = "ETPP_ETPS_FORMATS___prefix_11";
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_ETPP_ETPS_FORMATS___prefix_11].doc = "";
        
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_ETPP_ETPS_FORMATS___prefix_11].flags |= DNXC_DATA_F_DEFINE;
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_ETPP_ETPS_FORMATS___prefix_12].name = "ETPP_ETPS_FORMATS___prefix_12";
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_ETPP_ETPS_FORMATS___prefix_12].doc = "";
        
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_ETPP_ETPS_FORMATS___prefix_12].flags |= DNXC_DATA_F_DEFINE;
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_ETPP_ETPS_FORMATS___prefix_13].name = "ETPP_ETPS_FORMATS___prefix_13";
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_ETPP_ETPS_FORMATS___prefix_13].doc = "";
        
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_ETPP_ETPS_FORMATS___prefix_13].flags |= DNXC_DATA_F_DEFINE;
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_ETPP_ETPS_FORMATS___prefix_14].name = "ETPP_ETPS_FORMATS___prefix_14";
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_ETPP_ETPS_FORMATS___prefix_14].doc = "";
        
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_ETPP_ETPS_FORMATS___prefix_14].flags |= DNXC_DATA_F_DEFINE;
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_ETPP_ETPS_FORMATS___prefix_15].name = "ETPP_ETPS_FORMATS___prefix_15";
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_ETPP_ETPS_FORMATS___prefix_15].doc = "";
        
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_ETPP_ETPS_FORMATS___prefix_15].flags |= DNXC_DATA_F_DEFINE;
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_FEC_ENTRY_FORMAT___prefix_0].name = "IRPP_FEC_ENTRY_FORMAT___prefix_0";
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_FEC_ENTRY_FORMAT___prefix_0].doc = "";
        
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_FEC_ENTRY_FORMAT___prefix_0].flags |= DNXC_DATA_F_DEFINE;
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_FEC_ENTRY_FORMAT___prefix_1].name = "IRPP_FEC_ENTRY_FORMAT___prefix_1";
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_FEC_ENTRY_FORMAT___prefix_1].doc = "";
        
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_FEC_ENTRY_FORMAT___prefix_1].flags |= DNXC_DATA_F_DEFINE;
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_FEC_ENTRY_FORMAT___prefix_2].name = "IRPP_FEC_ENTRY_FORMAT___prefix_2";
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_FEC_ENTRY_FORMAT___prefix_2].doc = "";
        
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_FEC_ENTRY_FORMAT___prefix_2].flags |= DNXC_DATA_F_DEFINE;
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_FEC_ENTRY_FORMAT___prefix_3].name = "IRPP_FEC_ENTRY_FORMAT___prefix_3";
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_FEC_ENTRY_FORMAT___prefix_3].doc = "";
        
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_FEC_ENTRY_FORMAT___prefix_3].flags |= DNXC_DATA_F_DEFINE;
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_FEC_ENTRY_FORMAT___prefix_4].name = "IRPP_FEC_ENTRY_FORMAT___prefix_4";
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_FEC_ENTRY_FORMAT___prefix_4].doc = "";
        
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_FEC_ENTRY_FORMAT___prefix_4].flags |= DNXC_DATA_F_DEFINE;
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_FEC_ENTRY_FORMAT___prefix_5].name = "IRPP_FEC_ENTRY_FORMAT___prefix_5";
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_FEC_ENTRY_FORMAT___prefix_5].doc = "";
        
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_FEC_ENTRY_FORMAT___prefix_5].flags |= DNXC_DATA_F_DEFINE;
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_FEC_ENTRY_FORMAT___prefix_6].name = "IRPP_FEC_ENTRY_FORMAT___prefix_6";
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_FEC_ENTRY_FORMAT___prefix_6].doc = "";
        
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_FEC_ENTRY_FORMAT___prefix_6].flags |= DNXC_DATA_F_DEFINE;
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_FEC_ENTRY_FORMAT___prefix_7].name = "IRPP_FEC_ENTRY_FORMAT___prefix_7";
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_FEC_ENTRY_FORMAT___prefix_7].doc = "";
        
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_FEC_ENTRY_FORMAT___prefix_7].flags |= DNXC_DATA_F_DEFINE;
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_FEC_ENTRY_FORMAT___prefix_8].name = "IRPP_FEC_ENTRY_FORMAT___prefix_8";
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_FEC_ENTRY_FORMAT___prefix_8].doc = "";
        
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_FEC_ENTRY_FORMAT___prefix_8].flags |= DNXC_DATA_F_DEFINE;
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_FEC_ENTRY_FORMAT___prefix_9].name = "IRPP_FEC_ENTRY_FORMAT___prefix_9";
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_FEC_ENTRY_FORMAT___prefix_9].doc = "";
        
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_FEC_ENTRY_FORMAT___prefix_9].flags |= DNXC_DATA_F_DEFINE;
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_FEC_ENTRY_FORMAT___prefix_10].name = "IRPP_FEC_ENTRY_FORMAT___prefix_10";
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_FEC_ENTRY_FORMAT___prefix_10].doc = "";
        
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_FEC_ENTRY_FORMAT___prefix_10].flags |= DNXC_DATA_F_DEFINE;
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_FEC_ENTRY_FORMAT___prefix_11].name = "IRPP_FEC_ENTRY_FORMAT___prefix_11";
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_FEC_ENTRY_FORMAT___prefix_11].doc = "";
        
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_FEC_ENTRY_FORMAT___prefix_11].flags |= DNXC_DATA_F_DEFINE;
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_FEC_ENTRY_FORMAT___prefix_12].name = "IRPP_FEC_ENTRY_FORMAT___prefix_12";
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_FEC_ENTRY_FORMAT___prefix_12].doc = "";
        
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_FEC_ENTRY_FORMAT___prefix_12].flags |= DNXC_DATA_F_DEFINE;
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_FEC_ENTRY_FORMAT___prefix_13].name = "IRPP_FEC_ENTRY_FORMAT___prefix_13";
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_FEC_ENTRY_FORMAT___prefix_13].doc = "";
        
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_FEC_ENTRY_FORMAT___prefix_13].flags |= DNXC_DATA_F_DEFINE;
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_FEC_ENTRY_FORMAT___prefix_14].name = "IRPP_FEC_ENTRY_FORMAT___prefix_14";
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_FEC_ENTRY_FORMAT___prefix_14].doc = "";
        
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_FEC_ENTRY_FORMAT___prefix_14].flags |= DNXC_DATA_F_DEFINE;
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_FEC_ENTRY_FORMAT___prefix_15].name = "IRPP_FEC_ENTRY_FORMAT___prefix_15";
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_FEC_ENTRY_FORMAT___prefix_15].doc = "";
        
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_FEC_ENTRY_FORMAT___prefix_15].flags |= DNXC_DATA_F_DEFINE;
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_FEC_SUPER_ENTRY_FORMAT___prefix_0].name = "IRPP_FEC_SUPER_ENTRY_FORMAT___prefix_0";
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_FEC_SUPER_ENTRY_FORMAT___prefix_0].doc = "";
        
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_FEC_SUPER_ENTRY_FORMAT___prefix_0].flags |= DNXC_DATA_F_DEFINE;
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_FEC_SUPER_ENTRY_FORMAT___prefix_1].name = "IRPP_FEC_SUPER_ENTRY_FORMAT___prefix_1";
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_FEC_SUPER_ENTRY_FORMAT___prefix_1].doc = "";
        
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_FEC_SUPER_ENTRY_FORMAT___prefix_1].flags |= DNXC_DATA_F_DEFINE;
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_FEC_SUPER_ENTRY_FORMAT___prefix_2].name = "IRPP_FEC_SUPER_ENTRY_FORMAT___prefix_2";
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_FEC_SUPER_ENTRY_FORMAT___prefix_2].doc = "";
        
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_FEC_SUPER_ENTRY_FORMAT___prefix_2].flags |= DNXC_DATA_F_DEFINE;
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_FEC_SUPER_ENTRY_FORMAT___prefix_3].name = "IRPP_FEC_SUPER_ENTRY_FORMAT___prefix_3";
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_FEC_SUPER_ENTRY_FORMAT___prefix_3].doc = "";
        
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_FEC_SUPER_ENTRY_FORMAT___prefix_3].flags |= DNXC_DATA_F_DEFINE;
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_FEC_SUPER_ENTRY_FORMAT___prefix_4].name = "IRPP_FEC_SUPER_ENTRY_FORMAT___prefix_4";
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_FEC_SUPER_ENTRY_FORMAT___prefix_4].doc = "";
        
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_FEC_SUPER_ENTRY_FORMAT___prefix_4].flags |= DNXC_DATA_F_DEFINE;
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_FEC_SUPER_ENTRY_FORMAT___prefix_5].name = "IRPP_FEC_SUPER_ENTRY_FORMAT___prefix_5";
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_FEC_SUPER_ENTRY_FORMAT___prefix_5].doc = "";
        
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_FEC_SUPER_ENTRY_FORMAT___prefix_5].flags |= DNXC_DATA_F_DEFINE;
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_FEC_SUPER_ENTRY_FORMAT___prefix_6].name = "IRPP_FEC_SUPER_ENTRY_FORMAT___prefix_6";
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_FEC_SUPER_ENTRY_FORMAT___prefix_6].doc = "";
        
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_FEC_SUPER_ENTRY_FORMAT___prefix_6].flags |= DNXC_DATA_F_DEFINE;
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_FEC_SUPER_ENTRY_FORMAT___prefix_7].name = "IRPP_FEC_SUPER_ENTRY_FORMAT___prefix_7";
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_FEC_SUPER_ENTRY_FORMAT___prefix_7].doc = "";
        
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_FEC_SUPER_ENTRY_FORMAT___prefix_7].flags |= DNXC_DATA_F_DEFINE;
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_FEC_SUPER_ENTRY_FORMAT___prefix_8].name = "IRPP_FEC_SUPER_ENTRY_FORMAT___prefix_8";
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_FEC_SUPER_ENTRY_FORMAT___prefix_8].doc = "";
        
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_FEC_SUPER_ENTRY_FORMAT___prefix_8].flags |= DNXC_DATA_F_DEFINE;
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_FEC_SUPER_ENTRY_FORMAT___prefix_9].name = "IRPP_FEC_SUPER_ENTRY_FORMAT___prefix_9";
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_FEC_SUPER_ENTRY_FORMAT___prefix_9].doc = "";
        
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_FEC_SUPER_ENTRY_FORMAT___prefix_9].flags |= DNXC_DATA_F_DEFINE;
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_FEC_SUPER_ENTRY_FORMAT___prefix_10].name = "IRPP_FEC_SUPER_ENTRY_FORMAT___prefix_10";
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_FEC_SUPER_ENTRY_FORMAT___prefix_10].doc = "";
        
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_FEC_SUPER_ENTRY_FORMAT___prefix_10].flags |= DNXC_DATA_F_DEFINE;
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_FEC_SUPER_ENTRY_FORMAT___prefix_11].name = "IRPP_FEC_SUPER_ENTRY_FORMAT___prefix_11";
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_FEC_SUPER_ENTRY_FORMAT___prefix_11].doc = "";
        
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_FEC_SUPER_ENTRY_FORMAT___prefix_11].flags |= DNXC_DATA_F_DEFINE;
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_FEC_SUPER_ENTRY_FORMAT___prefix_12].name = "IRPP_FEC_SUPER_ENTRY_FORMAT___prefix_12";
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_FEC_SUPER_ENTRY_FORMAT___prefix_12].doc = "";
        
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_FEC_SUPER_ENTRY_FORMAT___prefix_12].flags |= DNXC_DATA_F_DEFINE;
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_FEC_SUPER_ENTRY_FORMAT___prefix_13].name = "IRPP_FEC_SUPER_ENTRY_FORMAT___prefix_13";
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_FEC_SUPER_ENTRY_FORMAT___prefix_13].doc = "";
        
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_FEC_SUPER_ENTRY_FORMAT___prefix_13].flags |= DNXC_DATA_F_DEFINE;
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_FEC_SUPER_ENTRY_FORMAT___prefix_14].name = "IRPP_FEC_SUPER_ENTRY_FORMAT___prefix_14";
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_FEC_SUPER_ENTRY_FORMAT___prefix_14].doc = "";
        
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_FEC_SUPER_ENTRY_FORMAT___prefix_14].flags |= DNXC_DATA_F_DEFINE;
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_FEC_SUPER_ENTRY_FORMAT___prefix_15].name = "IRPP_FEC_SUPER_ENTRY_FORMAT___prefix_15";
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_FEC_SUPER_ENTRY_FORMAT___prefix_15].doc = "";
        
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_FEC_SUPER_ENTRY_FORMAT___prefix_15].flags |= DNXC_DATA_F_DEFINE;
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_FWD_STAGE_FORMATS___prefix_0].name = "IRPP_FWD_STAGE_FORMATS___prefix_0";
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_FWD_STAGE_FORMATS___prefix_0].doc = "";
        
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_FWD_STAGE_FORMATS___prefix_0].flags |= DNXC_DATA_F_DEFINE;
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_FWD_STAGE_FORMATS___prefix_1].name = "IRPP_FWD_STAGE_FORMATS___prefix_1";
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_FWD_STAGE_FORMATS___prefix_1].doc = "";
        
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_FWD_STAGE_FORMATS___prefix_1].flags |= DNXC_DATA_F_DEFINE;
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_FWD_STAGE_FORMATS___prefix_2].name = "IRPP_FWD_STAGE_FORMATS___prefix_2";
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_FWD_STAGE_FORMATS___prefix_2].doc = "";
        
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_FWD_STAGE_FORMATS___prefix_2].flags |= DNXC_DATA_F_DEFINE;
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_FWD_STAGE_FORMATS___prefix_3].name = "IRPP_FWD_STAGE_FORMATS___prefix_3";
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_FWD_STAGE_FORMATS___prefix_3].doc = "";
        
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_FWD_STAGE_FORMATS___prefix_3].flags |= DNXC_DATA_F_DEFINE;
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_FWD_STAGE_FORMATS___prefix_4].name = "IRPP_FWD_STAGE_FORMATS___prefix_4";
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_FWD_STAGE_FORMATS___prefix_4].doc = "";
        
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_FWD_STAGE_FORMATS___prefix_4].flags |= DNXC_DATA_F_DEFINE;
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_FWD_STAGE_FORMATS___prefix_5].name = "IRPP_FWD_STAGE_FORMATS___prefix_5";
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_FWD_STAGE_FORMATS___prefix_5].doc = "";
        
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_FWD_STAGE_FORMATS___prefix_5].flags |= DNXC_DATA_F_DEFINE;
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_FWD_STAGE_FORMATS___prefix_6].name = "IRPP_FWD_STAGE_FORMATS___prefix_6";
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_FWD_STAGE_FORMATS___prefix_6].doc = "";
        
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_FWD_STAGE_FORMATS___prefix_6].flags |= DNXC_DATA_F_DEFINE;
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_FWD_STAGE_FORMATS___prefix_7].name = "IRPP_FWD_STAGE_FORMATS___prefix_7";
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_FWD_STAGE_FORMATS___prefix_7].doc = "";
        
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_FWD_STAGE_FORMATS___prefix_7].flags |= DNXC_DATA_F_DEFINE;
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_IN_LIF_FORMATS___prefix_0].name = "IRPP_IN_LIF_FORMATS___prefix_0";
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_IN_LIF_FORMATS___prefix_0].doc = "";
        
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_IN_LIF_FORMATS___prefix_0].flags |= DNXC_DATA_F_DEFINE;
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_IN_LIF_FORMATS___prefix_1].name = "IRPP_IN_LIF_FORMATS___prefix_1";
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_IN_LIF_FORMATS___prefix_1].doc = "";
        
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_IN_LIF_FORMATS___prefix_1].flags |= DNXC_DATA_F_DEFINE;
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_IN_LIF_FORMATS___prefix_2].name = "IRPP_IN_LIF_FORMATS___prefix_2";
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_IN_LIF_FORMATS___prefix_2].doc = "";
        
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_IN_LIF_FORMATS___prefix_2].flags |= DNXC_DATA_F_DEFINE;
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_IN_LIF_FORMATS___prefix_3].name = "IRPP_IN_LIF_FORMATS___prefix_3";
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_IN_LIF_FORMATS___prefix_3].doc = "";
        
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_IN_LIF_FORMATS___prefix_3].flags |= DNXC_DATA_F_DEFINE;
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_IN_LIF_FORMATS___prefix_4].name = "IRPP_IN_LIF_FORMATS___prefix_4";
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_IN_LIF_FORMATS___prefix_4].doc = "";
        
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_IN_LIF_FORMATS___prefix_4].flags |= DNXC_DATA_F_DEFINE;
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_IN_LIF_FORMATS___prefix_5].name = "IRPP_IN_LIF_FORMATS___prefix_5";
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_IN_LIF_FORMATS___prefix_5].doc = "";
        
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_IN_LIF_FORMATS___prefix_5].flags |= DNXC_DATA_F_DEFINE;
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_IN_LIF_FORMATS___prefix_6].name = "IRPP_IN_LIF_FORMATS___prefix_6";
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_IN_LIF_FORMATS___prefix_6].doc = "";
        
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_IN_LIF_FORMATS___prefix_6].flags |= DNXC_DATA_F_DEFINE;
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_IN_LIF_FORMATS___prefix_7].name = "IRPP_IN_LIF_FORMATS___prefix_7";
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_IN_LIF_FORMATS___prefix_7].doc = "";
        
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_IN_LIF_FORMATS___prefix_7].flags |= DNXC_DATA_F_DEFINE;
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_IN_LIF_FORMATS___prefix_8].name = "IRPP_IN_LIF_FORMATS___prefix_8";
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_IN_LIF_FORMATS___prefix_8].doc = "";
        
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_IN_LIF_FORMATS___prefix_8].flags |= DNXC_DATA_F_DEFINE;
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_IN_LIF_FORMATS___prefix_9].name = "IRPP_IN_LIF_FORMATS___prefix_9";
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_IN_LIF_FORMATS___prefix_9].doc = "";
        
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_IN_LIF_FORMATS___prefix_9].flags |= DNXC_DATA_F_DEFINE;
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_IN_LIF_FORMATS___prefix_10].name = "IRPP_IN_LIF_FORMATS___prefix_10";
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_IN_LIF_FORMATS___prefix_10].doc = "";
        
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_IN_LIF_FORMATS___prefix_10].flags |= DNXC_DATA_F_DEFINE;
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_IN_LIF_FORMATS___prefix_11].name = "IRPP_IN_LIF_FORMATS___prefix_11";
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_IN_LIF_FORMATS___prefix_11].doc = "";
        
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_IN_LIF_FORMATS___prefix_11].flags |= DNXC_DATA_F_DEFINE;
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_IN_LIF_FORMATS___prefix_12].name = "IRPP_IN_LIF_FORMATS___prefix_12";
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_IN_LIF_FORMATS___prefix_12].doc = "";
        
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_IN_LIF_FORMATS___prefix_12].flags |= DNXC_DATA_F_DEFINE;
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_IN_LIF_FORMATS___prefix_13].name = "IRPP_IN_LIF_FORMATS___prefix_13";
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_IN_LIF_FORMATS___prefix_13].doc = "";
        
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_IN_LIF_FORMATS___prefix_13].flags |= DNXC_DATA_F_DEFINE;
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_IN_LIF_FORMATS___prefix_14].name = "IRPP_IN_LIF_FORMATS___prefix_14";
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_IN_LIF_FORMATS___prefix_14].doc = "";
        
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_IN_LIF_FORMATS___prefix_14].flags |= DNXC_DATA_F_DEFINE;
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_IN_LIF_FORMATS___prefix_15].name = "IRPP_IN_LIF_FORMATS___prefix_15";
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_IN_LIF_FORMATS___prefix_15].doc = "";
        
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_IN_LIF_FORMATS___prefix_15].flags |= DNXC_DATA_F_DEFINE;
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_VSI_FORMATS___prefix_0].name = "IRPP_VSI_FORMATS___prefix_0";
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_VSI_FORMATS___prefix_0].doc = "";
        
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_VSI_FORMATS___prefix_0].flags |= DNXC_DATA_F_DEFINE;
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_VSI_FORMATS___prefix_1].name = "IRPP_VSI_FORMATS___prefix_1";
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_VSI_FORMATS___prefix_1].doc = "";
        
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_VSI_FORMATS___prefix_1].flags |= DNXC_DATA_F_DEFINE;
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_VSI_FORMATS___prefix_2].name = "IRPP_VSI_FORMATS___prefix_2";
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_VSI_FORMATS___prefix_2].doc = "";
        
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_VSI_FORMATS___prefix_2].flags |= DNXC_DATA_F_DEFINE;
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_VSI_FORMATS___prefix_3].name = "IRPP_VSI_FORMATS___prefix_3";
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_VSI_FORMATS___prefix_3].doc = "";
        
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_VSI_FORMATS___prefix_3].flags |= DNXC_DATA_F_DEFINE;
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_VSI_FORMATS___prefix_4].name = "IRPP_VSI_FORMATS___prefix_4";
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_VSI_FORMATS___prefix_4].doc = "";
        
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_VSI_FORMATS___prefix_4].flags |= DNXC_DATA_F_DEFINE;
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_VSI_FORMATS___prefix_5].name = "IRPP_VSI_FORMATS___prefix_5";
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_VSI_FORMATS___prefix_5].doc = "";
        
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_VSI_FORMATS___prefix_5].flags |= DNXC_DATA_F_DEFINE;
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_VSI_FORMATS___prefix_6].name = "IRPP_VSI_FORMATS___prefix_6";
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_VSI_FORMATS___prefix_6].doc = "";
        
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_VSI_FORMATS___prefix_6].flags |= DNXC_DATA_F_DEFINE;
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_VSI_FORMATS___prefix_7].name = "IRPP_VSI_FORMATS___prefix_7";
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_VSI_FORMATS___prefix_7].doc = "";
        
        submodule_data->defines[dnx_data_dnx2_arr_prefix_define_IRPP_VSI_FORMATS___prefix_7].flags |= DNXC_DATA_F_DEFINE;
    }

    
    submodule_data->nof_tables = _dnx_data_dnx2_arr_prefix_table_nof;
    DNXC_DATA_ALLOC(submodule_data->tables, dnxc_data_table_t, submodule_data->nof_tables, "_dnxc_data dnx2_arr prefix tables");


exit:
    SHR_FUNC_EXIT;
}


int
dnx_data_dnx2_arr_prefix_feature_get(
    int unit,
    dnx_data_dnx2_arr_prefix_feature_e feature)
{
    return dnxc_data_mgmt_feature_data_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_prefix, feature);
}


uint32
dnx_data_dnx2_arr_prefix_ETPP_ETPS_FORMATS___prefix_0_get(
    int unit)
{
    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "ETPP_ETPS_FORMATS___prefix_0", "DNX2");
    }
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_prefix, dnx_data_dnx2_arr_prefix_define_ETPP_ETPS_FORMATS___prefix_0);
}

uint32
dnx_data_dnx2_arr_prefix_ETPP_ETPS_FORMATS___prefix_1_get(
    int unit)
{
    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "ETPP_ETPS_FORMATS___prefix_1", "DNX2");
    }
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_prefix, dnx_data_dnx2_arr_prefix_define_ETPP_ETPS_FORMATS___prefix_1);
}

uint32
dnx_data_dnx2_arr_prefix_ETPP_ETPS_FORMATS___prefix_2_get(
    int unit)
{
    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "ETPP_ETPS_FORMATS___prefix_2", "DNX2");
    }
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_prefix, dnx_data_dnx2_arr_prefix_define_ETPP_ETPS_FORMATS___prefix_2);
}

uint32
dnx_data_dnx2_arr_prefix_ETPP_ETPS_FORMATS___prefix_3_get(
    int unit)
{
    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "ETPP_ETPS_FORMATS___prefix_3", "DNX2");
    }
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_prefix, dnx_data_dnx2_arr_prefix_define_ETPP_ETPS_FORMATS___prefix_3);
}

uint32
dnx_data_dnx2_arr_prefix_ETPP_ETPS_FORMATS___prefix_4_get(
    int unit)
{
    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "ETPP_ETPS_FORMATS___prefix_4", "DNX2");
    }
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_prefix, dnx_data_dnx2_arr_prefix_define_ETPP_ETPS_FORMATS___prefix_4);
}

uint32
dnx_data_dnx2_arr_prefix_ETPP_ETPS_FORMATS___prefix_5_get(
    int unit)
{
    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "ETPP_ETPS_FORMATS___prefix_5", "DNX2");
    }
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_prefix, dnx_data_dnx2_arr_prefix_define_ETPP_ETPS_FORMATS___prefix_5);
}

uint32
dnx_data_dnx2_arr_prefix_ETPP_ETPS_FORMATS___prefix_6_get(
    int unit)
{
    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "ETPP_ETPS_FORMATS___prefix_6", "DNX2");
    }
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_prefix, dnx_data_dnx2_arr_prefix_define_ETPP_ETPS_FORMATS___prefix_6);
}

uint32
dnx_data_dnx2_arr_prefix_ETPP_ETPS_FORMATS___prefix_7_get(
    int unit)
{
    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "ETPP_ETPS_FORMATS___prefix_7", "DNX2");
    }
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_prefix, dnx_data_dnx2_arr_prefix_define_ETPP_ETPS_FORMATS___prefix_7);
}

uint32
dnx_data_dnx2_arr_prefix_ETPP_ETPS_FORMATS___prefix_8_get(
    int unit)
{
    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "ETPP_ETPS_FORMATS___prefix_8", "DNX2");
    }
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_prefix, dnx_data_dnx2_arr_prefix_define_ETPP_ETPS_FORMATS___prefix_8);
}

uint32
dnx_data_dnx2_arr_prefix_ETPP_ETPS_FORMATS___prefix_9_get(
    int unit)
{
    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "ETPP_ETPS_FORMATS___prefix_9", "DNX2");
    }
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_prefix, dnx_data_dnx2_arr_prefix_define_ETPP_ETPS_FORMATS___prefix_9);
}

uint32
dnx_data_dnx2_arr_prefix_ETPP_ETPS_FORMATS___prefix_10_get(
    int unit)
{
    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "ETPP_ETPS_FORMATS___prefix_10", "DNX2");
    }
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_prefix, dnx_data_dnx2_arr_prefix_define_ETPP_ETPS_FORMATS___prefix_10);
}

uint32
dnx_data_dnx2_arr_prefix_ETPP_ETPS_FORMATS___prefix_11_get(
    int unit)
{
    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "ETPP_ETPS_FORMATS___prefix_11", "DNX2");
    }
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_prefix, dnx_data_dnx2_arr_prefix_define_ETPP_ETPS_FORMATS___prefix_11);
}

uint32
dnx_data_dnx2_arr_prefix_ETPP_ETPS_FORMATS___prefix_12_get(
    int unit)
{
    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "ETPP_ETPS_FORMATS___prefix_12", "DNX2");
    }
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_prefix, dnx_data_dnx2_arr_prefix_define_ETPP_ETPS_FORMATS___prefix_12);
}

uint32
dnx_data_dnx2_arr_prefix_ETPP_ETPS_FORMATS___prefix_13_get(
    int unit)
{
    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "ETPP_ETPS_FORMATS___prefix_13", "DNX2");
    }
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_prefix, dnx_data_dnx2_arr_prefix_define_ETPP_ETPS_FORMATS___prefix_13);
}

uint32
dnx_data_dnx2_arr_prefix_ETPP_ETPS_FORMATS___prefix_14_get(
    int unit)
{
    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "ETPP_ETPS_FORMATS___prefix_14", "DNX2");
    }
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_prefix, dnx_data_dnx2_arr_prefix_define_ETPP_ETPS_FORMATS___prefix_14);
}

uint32
dnx_data_dnx2_arr_prefix_ETPP_ETPS_FORMATS___prefix_15_get(
    int unit)
{
    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "ETPP_ETPS_FORMATS___prefix_15", "DNX2");
    }
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_prefix, dnx_data_dnx2_arr_prefix_define_ETPP_ETPS_FORMATS___prefix_15);
}

uint32
dnx_data_dnx2_arr_prefix_IRPP_FEC_ENTRY_FORMAT___prefix_0_get(
    int unit)
{
    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "IRPP_FEC_ENTRY_FORMAT___prefix_0", "DNX2");
    }
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_prefix, dnx_data_dnx2_arr_prefix_define_IRPP_FEC_ENTRY_FORMAT___prefix_0);
}

uint32
dnx_data_dnx2_arr_prefix_IRPP_FEC_ENTRY_FORMAT___prefix_1_get(
    int unit)
{
    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "IRPP_FEC_ENTRY_FORMAT___prefix_1", "DNX2");
    }
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_prefix, dnx_data_dnx2_arr_prefix_define_IRPP_FEC_ENTRY_FORMAT___prefix_1);
}

uint32
dnx_data_dnx2_arr_prefix_IRPP_FEC_ENTRY_FORMAT___prefix_2_get(
    int unit)
{
    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "IRPP_FEC_ENTRY_FORMAT___prefix_2", "DNX2");
    }
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_prefix, dnx_data_dnx2_arr_prefix_define_IRPP_FEC_ENTRY_FORMAT___prefix_2);
}

uint32
dnx_data_dnx2_arr_prefix_IRPP_FEC_ENTRY_FORMAT___prefix_3_get(
    int unit)
{
    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "IRPP_FEC_ENTRY_FORMAT___prefix_3", "DNX2");
    }
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_prefix, dnx_data_dnx2_arr_prefix_define_IRPP_FEC_ENTRY_FORMAT___prefix_3);
}

uint32
dnx_data_dnx2_arr_prefix_IRPP_FEC_ENTRY_FORMAT___prefix_4_get(
    int unit)
{
    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "IRPP_FEC_ENTRY_FORMAT___prefix_4", "DNX2");
    }
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_prefix, dnx_data_dnx2_arr_prefix_define_IRPP_FEC_ENTRY_FORMAT___prefix_4);
}

uint32
dnx_data_dnx2_arr_prefix_IRPP_FEC_ENTRY_FORMAT___prefix_5_get(
    int unit)
{
    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "IRPP_FEC_ENTRY_FORMAT___prefix_5", "DNX2");
    }
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_prefix, dnx_data_dnx2_arr_prefix_define_IRPP_FEC_ENTRY_FORMAT___prefix_5);
}

uint32
dnx_data_dnx2_arr_prefix_IRPP_FEC_ENTRY_FORMAT___prefix_6_get(
    int unit)
{
    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "IRPP_FEC_ENTRY_FORMAT___prefix_6", "DNX2");
    }
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_prefix, dnx_data_dnx2_arr_prefix_define_IRPP_FEC_ENTRY_FORMAT___prefix_6);
}

uint32
dnx_data_dnx2_arr_prefix_IRPP_FEC_ENTRY_FORMAT___prefix_7_get(
    int unit)
{
    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "IRPP_FEC_ENTRY_FORMAT___prefix_7", "DNX2");
    }
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_prefix, dnx_data_dnx2_arr_prefix_define_IRPP_FEC_ENTRY_FORMAT___prefix_7);
}

uint32
dnx_data_dnx2_arr_prefix_IRPP_FEC_ENTRY_FORMAT___prefix_8_get(
    int unit)
{
    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "IRPP_FEC_ENTRY_FORMAT___prefix_8", "DNX2");
    }
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_prefix, dnx_data_dnx2_arr_prefix_define_IRPP_FEC_ENTRY_FORMAT___prefix_8);
}

uint32
dnx_data_dnx2_arr_prefix_IRPP_FEC_ENTRY_FORMAT___prefix_9_get(
    int unit)
{
    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "IRPP_FEC_ENTRY_FORMAT___prefix_9", "DNX2");
    }
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_prefix, dnx_data_dnx2_arr_prefix_define_IRPP_FEC_ENTRY_FORMAT___prefix_9);
}

uint32
dnx_data_dnx2_arr_prefix_IRPP_FEC_ENTRY_FORMAT___prefix_10_get(
    int unit)
{
    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "IRPP_FEC_ENTRY_FORMAT___prefix_10", "DNX2");
    }
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_prefix, dnx_data_dnx2_arr_prefix_define_IRPP_FEC_ENTRY_FORMAT___prefix_10);
}

uint32
dnx_data_dnx2_arr_prefix_IRPP_FEC_ENTRY_FORMAT___prefix_11_get(
    int unit)
{
    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "IRPP_FEC_ENTRY_FORMAT___prefix_11", "DNX2");
    }
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_prefix, dnx_data_dnx2_arr_prefix_define_IRPP_FEC_ENTRY_FORMAT___prefix_11);
}

uint32
dnx_data_dnx2_arr_prefix_IRPP_FEC_ENTRY_FORMAT___prefix_12_get(
    int unit)
{
    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "IRPP_FEC_ENTRY_FORMAT___prefix_12", "DNX2");
    }
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_prefix, dnx_data_dnx2_arr_prefix_define_IRPP_FEC_ENTRY_FORMAT___prefix_12);
}

uint32
dnx_data_dnx2_arr_prefix_IRPP_FEC_ENTRY_FORMAT___prefix_13_get(
    int unit)
{
    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "IRPP_FEC_ENTRY_FORMAT___prefix_13", "DNX2");
    }
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_prefix, dnx_data_dnx2_arr_prefix_define_IRPP_FEC_ENTRY_FORMAT___prefix_13);
}

uint32
dnx_data_dnx2_arr_prefix_IRPP_FEC_ENTRY_FORMAT___prefix_14_get(
    int unit)
{
    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "IRPP_FEC_ENTRY_FORMAT___prefix_14", "DNX2");
    }
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_prefix, dnx_data_dnx2_arr_prefix_define_IRPP_FEC_ENTRY_FORMAT___prefix_14);
}

uint32
dnx_data_dnx2_arr_prefix_IRPP_FEC_ENTRY_FORMAT___prefix_15_get(
    int unit)
{
    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "IRPP_FEC_ENTRY_FORMAT___prefix_15", "DNX2");
    }
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_prefix, dnx_data_dnx2_arr_prefix_define_IRPP_FEC_ENTRY_FORMAT___prefix_15);
}

uint32
dnx_data_dnx2_arr_prefix_IRPP_FEC_SUPER_ENTRY_FORMAT___prefix_0_get(
    int unit)
{
    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "IRPP_FEC_SUPER_ENTRY_FORMAT___prefix_0", "DNX2");
    }
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_prefix, dnx_data_dnx2_arr_prefix_define_IRPP_FEC_SUPER_ENTRY_FORMAT___prefix_0);
}

uint32
dnx_data_dnx2_arr_prefix_IRPP_FEC_SUPER_ENTRY_FORMAT___prefix_1_get(
    int unit)
{
    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "IRPP_FEC_SUPER_ENTRY_FORMAT___prefix_1", "DNX2");
    }
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_prefix, dnx_data_dnx2_arr_prefix_define_IRPP_FEC_SUPER_ENTRY_FORMAT___prefix_1);
}

uint32
dnx_data_dnx2_arr_prefix_IRPP_FEC_SUPER_ENTRY_FORMAT___prefix_2_get(
    int unit)
{
    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "IRPP_FEC_SUPER_ENTRY_FORMAT___prefix_2", "DNX2");
    }
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_prefix, dnx_data_dnx2_arr_prefix_define_IRPP_FEC_SUPER_ENTRY_FORMAT___prefix_2);
}

uint32
dnx_data_dnx2_arr_prefix_IRPP_FEC_SUPER_ENTRY_FORMAT___prefix_3_get(
    int unit)
{
    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "IRPP_FEC_SUPER_ENTRY_FORMAT___prefix_3", "DNX2");
    }
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_prefix, dnx_data_dnx2_arr_prefix_define_IRPP_FEC_SUPER_ENTRY_FORMAT___prefix_3);
}

uint32
dnx_data_dnx2_arr_prefix_IRPP_FEC_SUPER_ENTRY_FORMAT___prefix_4_get(
    int unit)
{
    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "IRPP_FEC_SUPER_ENTRY_FORMAT___prefix_4", "DNX2");
    }
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_prefix, dnx_data_dnx2_arr_prefix_define_IRPP_FEC_SUPER_ENTRY_FORMAT___prefix_4);
}

uint32
dnx_data_dnx2_arr_prefix_IRPP_FEC_SUPER_ENTRY_FORMAT___prefix_5_get(
    int unit)
{
    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "IRPP_FEC_SUPER_ENTRY_FORMAT___prefix_5", "DNX2");
    }
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_prefix, dnx_data_dnx2_arr_prefix_define_IRPP_FEC_SUPER_ENTRY_FORMAT___prefix_5);
}

uint32
dnx_data_dnx2_arr_prefix_IRPP_FEC_SUPER_ENTRY_FORMAT___prefix_6_get(
    int unit)
{
    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "IRPP_FEC_SUPER_ENTRY_FORMAT___prefix_6", "DNX2");
    }
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_prefix, dnx_data_dnx2_arr_prefix_define_IRPP_FEC_SUPER_ENTRY_FORMAT___prefix_6);
}

uint32
dnx_data_dnx2_arr_prefix_IRPP_FEC_SUPER_ENTRY_FORMAT___prefix_7_get(
    int unit)
{
    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "IRPP_FEC_SUPER_ENTRY_FORMAT___prefix_7", "DNX2");
    }
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_prefix, dnx_data_dnx2_arr_prefix_define_IRPP_FEC_SUPER_ENTRY_FORMAT___prefix_7);
}

uint32
dnx_data_dnx2_arr_prefix_IRPP_FEC_SUPER_ENTRY_FORMAT___prefix_8_get(
    int unit)
{
    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "IRPP_FEC_SUPER_ENTRY_FORMAT___prefix_8", "DNX2");
    }
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_prefix, dnx_data_dnx2_arr_prefix_define_IRPP_FEC_SUPER_ENTRY_FORMAT___prefix_8);
}

uint32
dnx_data_dnx2_arr_prefix_IRPP_FEC_SUPER_ENTRY_FORMAT___prefix_9_get(
    int unit)
{
    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "IRPP_FEC_SUPER_ENTRY_FORMAT___prefix_9", "DNX2");
    }
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_prefix, dnx_data_dnx2_arr_prefix_define_IRPP_FEC_SUPER_ENTRY_FORMAT___prefix_9);
}

uint32
dnx_data_dnx2_arr_prefix_IRPP_FEC_SUPER_ENTRY_FORMAT___prefix_10_get(
    int unit)
{
    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "IRPP_FEC_SUPER_ENTRY_FORMAT___prefix_10", "DNX2");
    }
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_prefix, dnx_data_dnx2_arr_prefix_define_IRPP_FEC_SUPER_ENTRY_FORMAT___prefix_10);
}

uint32
dnx_data_dnx2_arr_prefix_IRPP_FEC_SUPER_ENTRY_FORMAT___prefix_11_get(
    int unit)
{
    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "IRPP_FEC_SUPER_ENTRY_FORMAT___prefix_11", "DNX2");
    }
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_prefix, dnx_data_dnx2_arr_prefix_define_IRPP_FEC_SUPER_ENTRY_FORMAT___prefix_11);
}

uint32
dnx_data_dnx2_arr_prefix_IRPP_FEC_SUPER_ENTRY_FORMAT___prefix_12_get(
    int unit)
{
    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "IRPP_FEC_SUPER_ENTRY_FORMAT___prefix_12", "DNX2");
    }
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_prefix, dnx_data_dnx2_arr_prefix_define_IRPP_FEC_SUPER_ENTRY_FORMAT___prefix_12);
}

uint32
dnx_data_dnx2_arr_prefix_IRPP_FEC_SUPER_ENTRY_FORMAT___prefix_13_get(
    int unit)
{
    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "IRPP_FEC_SUPER_ENTRY_FORMAT___prefix_13", "DNX2");
    }
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_prefix, dnx_data_dnx2_arr_prefix_define_IRPP_FEC_SUPER_ENTRY_FORMAT___prefix_13);
}

uint32
dnx_data_dnx2_arr_prefix_IRPP_FEC_SUPER_ENTRY_FORMAT___prefix_14_get(
    int unit)
{
    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "IRPP_FEC_SUPER_ENTRY_FORMAT___prefix_14", "DNX2");
    }
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_prefix, dnx_data_dnx2_arr_prefix_define_IRPP_FEC_SUPER_ENTRY_FORMAT___prefix_14);
}

uint32
dnx_data_dnx2_arr_prefix_IRPP_FEC_SUPER_ENTRY_FORMAT___prefix_15_get(
    int unit)
{
    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "IRPP_FEC_SUPER_ENTRY_FORMAT___prefix_15", "DNX2");
    }
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_prefix, dnx_data_dnx2_arr_prefix_define_IRPP_FEC_SUPER_ENTRY_FORMAT___prefix_15);
}

uint32
dnx_data_dnx2_arr_prefix_IRPP_FWD_STAGE_FORMATS___prefix_0_get(
    int unit)
{
    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "IRPP_FWD_STAGE_FORMATS___prefix_0", "DNX2");
    }
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_prefix, dnx_data_dnx2_arr_prefix_define_IRPP_FWD_STAGE_FORMATS___prefix_0);
}

uint32
dnx_data_dnx2_arr_prefix_IRPP_FWD_STAGE_FORMATS___prefix_1_get(
    int unit)
{
    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "IRPP_FWD_STAGE_FORMATS___prefix_1", "DNX2");
    }
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_prefix, dnx_data_dnx2_arr_prefix_define_IRPP_FWD_STAGE_FORMATS___prefix_1);
}

uint32
dnx_data_dnx2_arr_prefix_IRPP_FWD_STAGE_FORMATS___prefix_2_get(
    int unit)
{
    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "IRPP_FWD_STAGE_FORMATS___prefix_2", "DNX2");
    }
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_prefix, dnx_data_dnx2_arr_prefix_define_IRPP_FWD_STAGE_FORMATS___prefix_2);
}

uint32
dnx_data_dnx2_arr_prefix_IRPP_FWD_STAGE_FORMATS___prefix_3_get(
    int unit)
{
    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "IRPP_FWD_STAGE_FORMATS___prefix_3", "DNX2");
    }
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_prefix, dnx_data_dnx2_arr_prefix_define_IRPP_FWD_STAGE_FORMATS___prefix_3);
}

uint32
dnx_data_dnx2_arr_prefix_IRPP_FWD_STAGE_FORMATS___prefix_4_get(
    int unit)
{
    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "IRPP_FWD_STAGE_FORMATS___prefix_4", "DNX2");
    }
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_prefix, dnx_data_dnx2_arr_prefix_define_IRPP_FWD_STAGE_FORMATS___prefix_4);
}

uint32
dnx_data_dnx2_arr_prefix_IRPP_FWD_STAGE_FORMATS___prefix_5_get(
    int unit)
{
    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "IRPP_FWD_STAGE_FORMATS___prefix_5", "DNX2");
    }
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_prefix, dnx_data_dnx2_arr_prefix_define_IRPP_FWD_STAGE_FORMATS___prefix_5);
}

uint32
dnx_data_dnx2_arr_prefix_IRPP_FWD_STAGE_FORMATS___prefix_6_get(
    int unit)
{
    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "IRPP_FWD_STAGE_FORMATS___prefix_6", "DNX2");
    }
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_prefix, dnx_data_dnx2_arr_prefix_define_IRPP_FWD_STAGE_FORMATS___prefix_6);
}

uint32
dnx_data_dnx2_arr_prefix_IRPP_FWD_STAGE_FORMATS___prefix_7_get(
    int unit)
{
    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "IRPP_FWD_STAGE_FORMATS___prefix_7", "DNX2");
    }
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_prefix, dnx_data_dnx2_arr_prefix_define_IRPP_FWD_STAGE_FORMATS___prefix_7);
}

uint32
dnx_data_dnx2_arr_prefix_IRPP_IN_LIF_FORMATS___prefix_0_get(
    int unit)
{
    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "IRPP_IN_LIF_FORMATS___prefix_0", "DNX2");
    }
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_prefix, dnx_data_dnx2_arr_prefix_define_IRPP_IN_LIF_FORMATS___prefix_0);
}

uint32
dnx_data_dnx2_arr_prefix_IRPP_IN_LIF_FORMATS___prefix_1_get(
    int unit)
{
    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "IRPP_IN_LIF_FORMATS___prefix_1", "DNX2");
    }
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_prefix, dnx_data_dnx2_arr_prefix_define_IRPP_IN_LIF_FORMATS___prefix_1);
}

uint32
dnx_data_dnx2_arr_prefix_IRPP_IN_LIF_FORMATS___prefix_2_get(
    int unit)
{
    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "IRPP_IN_LIF_FORMATS___prefix_2", "DNX2");
    }
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_prefix, dnx_data_dnx2_arr_prefix_define_IRPP_IN_LIF_FORMATS___prefix_2);
}

uint32
dnx_data_dnx2_arr_prefix_IRPP_IN_LIF_FORMATS___prefix_3_get(
    int unit)
{
    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "IRPP_IN_LIF_FORMATS___prefix_3", "DNX2");
    }
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_prefix, dnx_data_dnx2_arr_prefix_define_IRPP_IN_LIF_FORMATS___prefix_3);
}

uint32
dnx_data_dnx2_arr_prefix_IRPP_IN_LIF_FORMATS___prefix_4_get(
    int unit)
{
    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "IRPP_IN_LIF_FORMATS___prefix_4", "DNX2");
    }
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_prefix, dnx_data_dnx2_arr_prefix_define_IRPP_IN_LIF_FORMATS___prefix_4);
}

uint32
dnx_data_dnx2_arr_prefix_IRPP_IN_LIF_FORMATS___prefix_5_get(
    int unit)
{
    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "IRPP_IN_LIF_FORMATS___prefix_5", "DNX2");
    }
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_prefix, dnx_data_dnx2_arr_prefix_define_IRPP_IN_LIF_FORMATS___prefix_5);
}

uint32
dnx_data_dnx2_arr_prefix_IRPP_IN_LIF_FORMATS___prefix_6_get(
    int unit)
{
    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "IRPP_IN_LIF_FORMATS___prefix_6", "DNX2");
    }
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_prefix, dnx_data_dnx2_arr_prefix_define_IRPP_IN_LIF_FORMATS___prefix_6);
}

uint32
dnx_data_dnx2_arr_prefix_IRPP_IN_LIF_FORMATS___prefix_7_get(
    int unit)
{
    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "IRPP_IN_LIF_FORMATS___prefix_7", "DNX2");
    }
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_prefix, dnx_data_dnx2_arr_prefix_define_IRPP_IN_LIF_FORMATS___prefix_7);
}

uint32
dnx_data_dnx2_arr_prefix_IRPP_IN_LIF_FORMATS___prefix_8_get(
    int unit)
{
    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "IRPP_IN_LIF_FORMATS___prefix_8", "DNX2");
    }
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_prefix, dnx_data_dnx2_arr_prefix_define_IRPP_IN_LIF_FORMATS___prefix_8);
}

uint32
dnx_data_dnx2_arr_prefix_IRPP_IN_LIF_FORMATS___prefix_9_get(
    int unit)
{
    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "IRPP_IN_LIF_FORMATS___prefix_9", "DNX2");
    }
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_prefix, dnx_data_dnx2_arr_prefix_define_IRPP_IN_LIF_FORMATS___prefix_9);
}

uint32
dnx_data_dnx2_arr_prefix_IRPP_IN_LIF_FORMATS___prefix_10_get(
    int unit)
{
    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "IRPP_IN_LIF_FORMATS___prefix_10", "DNX2");
    }
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_prefix, dnx_data_dnx2_arr_prefix_define_IRPP_IN_LIF_FORMATS___prefix_10);
}

uint32
dnx_data_dnx2_arr_prefix_IRPP_IN_LIF_FORMATS___prefix_11_get(
    int unit)
{
    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "IRPP_IN_LIF_FORMATS___prefix_11", "DNX2");
    }
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_prefix, dnx_data_dnx2_arr_prefix_define_IRPP_IN_LIF_FORMATS___prefix_11);
}

uint32
dnx_data_dnx2_arr_prefix_IRPP_IN_LIF_FORMATS___prefix_12_get(
    int unit)
{
    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "IRPP_IN_LIF_FORMATS___prefix_12", "DNX2");
    }
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_prefix, dnx_data_dnx2_arr_prefix_define_IRPP_IN_LIF_FORMATS___prefix_12);
}

uint32
dnx_data_dnx2_arr_prefix_IRPP_IN_LIF_FORMATS___prefix_13_get(
    int unit)
{
    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "IRPP_IN_LIF_FORMATS___prefix_13", "DNX2");
    }
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_prefix, dnx_data_dnx2_arr_prefix_define_IRPP_IN_LIF_FORMATS___prefix_13);
}

uint32
dnx_data_dnx2_arr_prefix_IRPP_IN_LIF_FORMATS___prefix_14_get(
    int unit)
{
    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "IRPP_IN_LIF_FORMATS___prefix_14", "DNX2");
    }
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_prefix, dnx_data_dnx2_arr_prefix_define_IRPP_IN_LIF_FORMATS___prefix_14);
}

uint32
dnx_data_dnx2_arr_prefix_IRPP_IN_LIF_FORMATS___prefix_15_get(
    int unit)
{
    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "IRPP_IN_LIF_FORMATS___prefix_15", "DNX2");
    }
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_prefix, dnx_data_dnx2_arr_prefix_define_IRPP_IN_LIF_FORMATS___prefix_15);
}

uint32
dnx_data_dnx2_arr_prefix_IRPP_VSI_FORMATS___prefix_0_get(
    int unit)
{
    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "IRPP_VSI_FORMATS___prefix_0", "DNX2");
    }
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_prefix, dnx_data_dnx2_arr_prefix_define_IRPP_VSI_FORMATS___prefix_0);
}

uint32
dnx_data_dnx2_arr_prefix_IRPP_VSI_FORMATS___prefix_1_get(
    int unit)
{
    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "IRPP_VSI_FORMATS___prefix_1", "DNX2");
    }
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_prefix, dnx_data_dnx2_arr_prefix_define_IRPP_VSI_FORMATS___prefix_1);
}

uint32
dnx_data_dnx2_arr_prefix_IRPP_VSI_FORMATS___prefix_2_get(
    int unit)
{
    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "IRPP_VSI_FORMATS___prefix_2", "DNX2");
    }
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_prefix, dnx_data_dnx2_arr_prefix_define_IRPP_VSI_FORMATS___prefix_2);
}

uint32
dnx_data_dnx2_arr_prefix_IRPP_VSI_FORMATS___prefix_3_get(
    int unit)
{
    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "IRPP_VSI_FORMATS___prefix_3", "DNX2");
    }
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_prefix, dnx_data_dnx2_arr_prefix_define_IRPP_VSI_FORMATS___prefix_3);
}

uint32
dnx_data_dnx2_arr_prefix_IRPP_VSI_FORMATS___prefix_4_get(
    int unit)
{
    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "IRPP_VSI_FORMATS___prefix_4", "DNX2");
    }
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_prefix, dnx_data_dnx2_arr_prefix_define_IRPP_VSI_FORMATS___prefix_4);
}

uint32
dnx_data_dnx2_arr_prefix_IRPP_VSI_FORMATS___prefix_5_get(
    int unit)
{
    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "IRPP_VSI_FORMATS___prefix_5", "DNX2");
    }
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_prefix, dnx_data_dnx2_arr_prefix_define_IRPP_VSI_FORMATS___prefix_5);
}

uint32
dnx_data_dnx2_arr_prefix_IRPP_VSI_FORMATS___prefix_6_get(
    int unit)
{
    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "IRPP_VSI_FORMATS___prefix_6", "DNX2");
    }
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_prefix, dnx_data_dnx2_arr_prefix_define_IRPP_VSI_FORMATS___prefix_6);
}

uint32
dnx_data_dnx2_arr_prefix_IRPP_VSI_FORMATS___prefix_7_get(
    int unit)
{
    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "IRPP_VSI_FORMATS___prefix_7", "DNX2");
    }
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_prefix, dnx_data_dnx2_arr_prefix_define_IRPP_VSI_FORMATS___prefix_7);
}










static shr_error_e
dnx_data_dnx2_arr_max_nof_entries_init(
    int unit,
    dnxc_data_submodule_t *submodule_data)
{
    SHR_FUNC_INIT_VARS(unit);

    submodule_data->name = "max_nof_entries";
    submodule_data->doc = "";
    
    submodule_data->nof_features = _dnx_data_dnx2_arr_max_nof_entries_feature_nof;
    DNXC_DATA_ALLOC(submodule_data->features, dnxc_data_feature_t,  submodule_data->nof_features, "_dnxc_data dnx2_arr max_nof_entries features");

    
    submodule_data->nof_defines = _dnx_data_dnx2_arr_max_nof_entries_define_nof;
    DNXC_DATA_ALLOC(submodule_data->defines, dnxc_data_define_t, submodule_data->nof_defines, "_dnxc_data dnx2_arr max_nof_entries defines");

    if (soc_is(unit, DNX2_DEVICE))
    {
        submodule_data->defines[dnx_data_dnx2_arr_max_nof_entries_define_AGE_PROFILE_ARR].name = "AGE_PROFILE_ARR";
        submodule_data->defines[dnx_data_dnx2_arr_max_nof_entries_define_AGE_PROFILE_ARR].doc = "";
        
        submodule_data->defines[dnx_data_dnx2_arr_max_nof_entries_define_AGE_PROFILE_ARR].flags |= DNXC_DATA_F_DEFINE;
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        submodule_data->defines[dnx_data_dnx2_arr_max_nof_entries_define_ETPP_ENCAP_1_ARR_ToS].name = "ETPP_ENCAP_1_ARR_ToS";
        submodule_data->defines[dnx_data_dnx2_arr_max_nof_entries_define_ETPP_ENCAP_1_ARR_ToS].doc = "";
        
        submodule_data->defines[dnx_data_dnx2_arr_max_nof_entries_define_ETPP_ENCAP_1_ARR_ToS].flags |= DNXC_DATA_F_DEFINE;
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        submodule_data->defines[dnx_data_dnx2_arr_max_nof_entries_define_ETPP_ENCAP_2_ARR_ToS].name = "ETPP_ENCAP_2_ARR_ToS";
        submodule_data->defines[dnx_data_dnx2_arr_max_nof_entries_define_ETPP_ENCAP_2_ARR_ToS].doc = "";
        
        submodule_data->defines[dnx_data_dnx2_arr_max_nof_entries_define_ETPP_ENCAP_2_ARR_ToS].flags |= DNXC_DATA_F_DEFINE;
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        submodule_data->defines[dnx_data_dnx2_arr_max_nof_entries_define_ETPP_ENCAP_3_ARR_ToS].name = "ETPP_ENCAP_3_ARR_ToS";
        submodule_data->defines[dnx_data_dnx2_arr_max_nof_entries_define_ETPP_ENCAP_3_ARR_ToS].doc = "";
        
        submodule_data->defines[dnx_data_dnx2_arr_max_nof_entries_define_ETPP_ENCAP_3_ARR_ToS].flags |= DNXC_DATA_F_DEFINE;
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        submodule_data->defines[dnx_data_dnx2_arr_max_nof_entries_define_ETPP_ENCAP_4_ARR_ToS].name = "ETPP_ENCAP_4_ARR_ToS";
        submodule_data->defines[dnx_data_dnx2_arr_max_nof_entries_define_ETPP_ENCAP_4_ARR_ToS].doc = "";
        
        submodule_data->defines[dnx_data_dnx2_arr_max_nof_entries_define_ETPP_ENCAP_4_ARR_ToS].flags |= DNXC_DATA_F_DEFINE;
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        submodule_data->defines[dnx_data_dnx2_arr_max_nof_entries_define_ETPP_ENCAP_5_ARR_ToS].name = "ETPP_ENCAP_5_ARR_ToS";
        submodule_data->defines[dnx_data_dnx2_arr_max_nof_entries_define_ETPP_ENCAP_5_ARR_ToS].doc = "";
        
        submodule_data->defines[dnx_data_dnx2_arr_max_nof_entries_define_ETPP_ENCAP_5_ARR_ToS].flags |= DNXC_DATA_F_DEFINE;
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        submodule_data->defines[dnx_data_dnx2_arr_max_nof_entries_define_ETPP_ENCAP_ARR_ToS_plus_2].name = "ETPP_ENCAP_ARR_ToS_plus_2";
        submodule_data->defines[dnx_data_dnx2_arr_max_nof_entries_define_ETPP_ENCAP_ARR_ToS_plus_2].doc = "";
        
        submodule_data->defines[dnx_data_dnx2_arr_max_nof_entries_define_ETPP_ENCAP_ARR_ToS_plus_2].flags |= DNXC_DATA_F_DEFINE;
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        submodule_data->defines[dnx_data_dnx2_arr_max_nof_entries_define_ETPP_FWD_ARR_ToS].name = "ETPP_FWD_ARR_ToS";
        submodule_data->defines[dnx_data_dnx2_arr_max_nof_entries_define_ETPP_FWD_ARR_ToS].doc = "";
        
        submodule_data->defines[dnx_data_dnx2_arr_max_nof_entries_define_ETPP_FWD_ARR_ToS].flags |= DNXC_DATA_F_DEFINE;
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        submodule_data->defines[dnx_data_dnx2_arr_max_nof_entries_define_ETPP_FWD_ARR_ToS_plus_1].name = "ETPP_FWD_ARR_ToS_plus_1";
        submodule_data->defines[dnx_data_dnx2_arr_max_nof_entries_define_ETPP_FWD_ARR_ToS_plus_1].doc = "";
        
        submodule_data->defines[dnx_data_dnx2_arr_max_nof_entries_define_ETPP_FWD_ARR_ToS_plus_1].flags |= DNXC_DATA_F_DEFINE;
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        submodule_data->defines[dnx_data_dnx2_arr_max_nof_entries_define_ETPP_Preprocessing_ARR].name = "ETPP_Preprocessing_ARR";
        submodule_data->defines[dnx_data_dnx2_arr_max_nof_entries_define_ETPP_Preprocessing_ARR].doc = "";
        
        submodule_data->defines[dnx_data_dnx2_arr_max_nof_entries_define_ETPP_Preprocessing_ARR].flags |= DNXC_DATA_F_DEFINE;
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        submodule_data->defines[dnx_data_dnx2_arr_max_nof_entries_define_ETPP_Termination_1_ARR].name = "ETPP_Termination_1_ARR";
        submodule_data->defines[dnx_data_dnx2_arr_max_nof_entries_define_ETPP_Termination_1_ARR].doc = "";
        
        submodule_data->defines[dnx_data_dnx2_arr_max_nof_entries_define_ETPP_Termination_1_ARR].flags |= DNXC_DATA_F_DEFINE;
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        submodule_data->defines[dnx_data_dnx2_arr_max_nof_entries_define_ETPP_Termination_2_ARR].name = "ETPP_Termination_2_ARR";
        submodule_data->defines[dnx_data_dnx2_arr_max_nof_entries_define_ETPP_Termination_2_ARR].doc = "";
        
        submodule_data->defines[dnx_data_dnx2_arr_max_nof_entries_define_ETPP_Termination_2_ARR].flags |= DNXC_DATA_F_DEFINE;
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        submodule_data->defines[dnx_data_dnx2_arr_max_nof_entries_define_IPPB_EXISTING_ARR].name = "IPPB_EXISTING_ARR";
        submodule_data->defines[dnx_data_dnx2_arr_max_nof_entries_define_IPPB_EXISTING_ARR].doc = "";
        
        submodule_data->defines[dnx_data_dnx2_arr_max_nof_entries_define_IPPB_EXISTING_ARR].flags |= DNXC_DATA_F_DEFINE;
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        submodule_data->defines[dnx_data_dnx2_arr_max_nof_entries_define_IPPB_EXISTING_INCOMING_STRENGTH_ARR].name = "IPPB_EXISTING_INCOMING_STRENGTH_ARR";
        submodule_data->defines[dnx_data_dnx2_arr_max_nof_entries_define_IPPB_EXISTING_INCOMING_STRENGTH_ARR].doc = "";
        
        submodule_data->defines[dnx_data_dnx2_arr_max_nof_entries_define_IPPB_EXISTING_INCOMING_STRENGTH_ARR].flags |= DNXC_DATA_F_DEFINE;
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        submodule_data->defines[dnx_data_dnx2_arr_max_nof_entries_define_IPPB_INCOMING_ARR].name = "IPPB_INCOMING_ARR";
        submodule_data->defines[dnx_data_dnx2_arr_max_nof_entries_define_IPPB_INCOMING_ARR].doc = "";
        
        submodule_data->defines[dnx_data_dnx2_arr_max_nof_entries_define_IPPB_INCOMING_ARR].flags |= DNXC_DATA_F_DEFINE;
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        submodule_data->defines[dnx_data_dnx2_arr_max_nof_entries_define_IRPP_FEC_ARR].name = "IRPP_FEC_ARR";
        submodule_data->defines[dnx_data_dnx2_arr_max_nof_entries_define_IRPP_FEC_ARR].doc = "";
        
        submodule_data->defines[dnx_data_dnx2_arr_max_nof_entries_define_IRPP_FEC_ARR].flags |= DNXC_DATA_F_DEFINE;
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        submodule_data->defines[dnx_data_dnx2_arr_max_nof_entries_define_IRPP_FWD1_FWD_ARR].name = "IRPP_FWD1_FWD_ARR";
        submodule_data->defines[dnx_data_dnx2_arr_max_nof_entries_define_IRPP_FWD1_FWD_ARR].doc = "";
        
        submodule_data->defines[dnx_data_dnx2_arr_max_nof_entries_define_IRPP_FWD1_FWD_ARR].flags |= DNXC_DATA_F_DEFINE;
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        submodule_data->defines[dnx_data_dnx2_arr_max_nof_entries_define_IRPP_FWD1_RPF_ARR].name = "IRPP_FWD1_RPF_ARR";
        submodule_data->defines[dnx_data_dnx2_arr_max_nof_entries_define_IRPP_FWD1_RPF_ARR].doc = "";
        
        submodule_data->defines[dnx_data_dnx2_arr_max_nof_entries_define_IRPP_FWD1_RPF_ARR].flags |= DNXC_DATA_F_DEFINE;
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        submodule_data->defines[dnx_data_dnx2_arr_max_nof_entries_define_IRPP_SUPER_FEC_ARR].name = "IRPP_SUPER_FEC_ARR";
        submodule_data->defines[dnx_data_dnx2_arr_max_nof_entries_define_IRPP_SUPER_FEC_ARR].doc = "";
        
        submodule_data->defines[dnx_data_dnx2_arr_max_nof_entries_define_IRPP_SUPER_FEC_ARR].flags |= DNXC_DATA_F_DEFINE;
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        submodule_data->defines[dnx_data_dnx2_arr_max_nof_entries_define_IRPP_VSI_ARR].name = "IRPP_VSI_ARR";
        submodule_data->defines[dnx_data_dnx2_arr_max_nof_entries_define_IRPP_VSI_ARR].doc = "";
        
        submodule_data->defines[dnx_data_dnx2_arr_max_nof_entries_define_IRPP_VSI_ARR].flags |= DNXC_DATA_F_DEFINE;
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        submodule_data->defines[dnx_data_dnx2_arr_max_nof_entries_define_IRPP_VTT_ARR].name = "IRPP_VTT_ARR";
        submodule_data->defines[dnx_data_dnx2_arr_max_nof_entries_define_IRPP_VTT_ARR].doc = "";
        
        submodule_data->defines[dnx_data_dnx2_arr_max_nof_entries_define_IRPP_VTT_ARR].flags |= DNXC_DATA_F_DEFINE;
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        submodule_data->defines[dnx_data_dnx2_arr_max_nof_entries_define_ITPP_MACT_LEARN_JR1_TRANSLATE_ARR].name = "ITPP_MACT_LEARN_JR1_TRANSLATE_ARR";
        submodule_data->defines[dnx_data_dnx2_arr_max_nof_entries_define_ITPP_MACT_LEARN_JR1_TRANSLATE_ARR].doc = "";
        
        submodule_data->defines[dnx_data_dnx2_arr_max_nof_entries_define_ITPP_MACT_LEARN_JR1_TRANSLATE_ARR].flags |= DNXC_DATA_F_DEFINE;
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        submodule_data->defines[dnx_data_dnx2_arr_max_nof_entries_define_PPMC_ERPP_ARR].name = "PPMC_ERPP_ARR";
        submodule_data->defines[dnx_data_dnx2_arr_max_nof_entries_define_PPMC_ERPP_ARR].doc = "";
        
        submodule_data->defines[dnx_data_dnx2_arr_max_nof_entries_define_PPMC_ERPP_ARR].flags |= DNXC_DATA_F_DEFINE;
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        submodule_data->defines[dnx_data_dnx2_arr_max_nof_entries_define_USER_ALLOCATION].name = "USER_ALLOCATION";
        submodule_data->defines[dnx_data_dnx2_arr_max_nof_entries_define_USER_ALLOCATION].doc = "";
        
        submodule_data->defines[dnx_data_dnx2_arr_max_nof_entries_define_USER_ALLOCATION].flags |= DNXC_DATA_F_DEFINE;
    }

    
    submodule_data->nof_tables = _dnx_data_dnx2_arr_max_nof_entries_table_nof;
    DNXC_DATA_ALLOC(submodule_data->tables, dnxc_data_table_t, submodule_data->nof_tables, "_dnxc_data dnx2_arr max_nof_entries tables");


exit:
    SHR_FUNC_EXIT;
}


int
dnx_data_dnx2_arr_max_nof_entries_feature_get(
    int unit,
    dnx_data_dnx2_arr_max_nof_entries_feature_e feature)
{
    return dnxc_data_mgmt_feature_data_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_max_nof_entries, feature);
}


uint32
dnx_data_dnx2_arr_max_nof_entries_AGE_PROFILE_ARR_get(
    int unit)
{
    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "AGE_PROFILE_ARR", "DNX2");
    }
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_max_nof_entries, dnx_data_dnx2_arr_max_nof_entries_define_AGE_PROFILE_ARR);
}

uint32
dnx_data_dnx2_arr_max_nof_entries_ETPP_ENCAP_1_ARR_ToS_get(
    int unit)
{
    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "ETPP_ENCAP_1_ARR_ToS", "DNX2");
    }
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_max_nof_entries, dnx_data_dnx2_arr_max_nof_entries_define_ETPP_ENCAP_1_ARR_ToS);
}

uint32
dnx_data_dnx2_arr_max_nof_entries_ETPP_ENCAP_2_ARR_ToS_get(
    int unit)
{
    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "ETPP_ENCAP_2_ARR_ToS", "DNX2");
    }
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_max_nof_entries, dnx_data_dnx2_arr_max_nof_entries_define_ETPP_ENCAP_2_ARR_ToS);
}

uint32
dnx_data_dnx2_arr_max_nof_entries_ETPP_ENCAP_3_ARR_ToS_get(
    int unit)
{
    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "ETPP_ENCAP_3_ARR_ToS", "DNX2");
    }
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_max_nof_entries, dnx_data_dnx2_arr_max_nof_entries_define_ETPP_ENCAP_3_ARR_ToS);
}

uint32
dnx_data_dnx2_arr_max_nof_entries_ETPP_ENCAP_4_ARR_ToS_get(
    int unit)
{
    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "ETPP_ENCAP_4_ARR_ToS", "DNX2");
    }
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_max_nof_entries, dnx_data_dnx2_arr_max_nof_entries_define_ETPP_ENCAP_4_ARR_ToS);
}

uint32
dnx_data_dnx2_arr_max_nof_entries_ETPP_ENCAP_5_ARR_ToS_get(
    int unit)
{
    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "ETPP_ENCAP_5_ARR_ToS", "DNX2");
    }
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_max_nof_entries, dnx_data_dnx2_arr_max_nof_entries_define_ETPP_ENCAP_5_ARR_ToS);
}

uint32
dnx_data_dnx2_arr_max_nof_entries_ETPP_ENCAP_ARR_ToS_plus_2_get(
    int unit)
{
    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "ETPP_ENCAP_ARR_ToS_plus_2", "DNX2");
    }
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_max_nof_entries, dnx_data_dnx2_arr_max_nof_entries_define_ETPP_ENCAP_ARR_ToS_plus_2);
}

uint32
dnx_data_dnx2_arr_max_nof_entries_ETPP_FWD_ARR_ToS_get(
    int unit)
{
    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "ETPP_FWD_ARR_ToS", "DNX2");
    }
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_max_nof_entries, dnx_data_dnx2_arr_max_nof_entries_define_ETPP_FWD_ARR_ToS);
}

uint32
dnx_data_dnx2_arr_max_nof_entries_ETPP_FWD_ARR_ToS_plus_1_get(
    int unit)
{
    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "ETPP_FWD_ARR_ToS_plus_1", "DNX2");
    }
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_max_nof_entries, dnx_data_dnx2_arr_max_nof_entries_define_ETPP_FWD_ARR_ToS_plus_1);
}

uint32
dnx_data_dnx2_arr_max_nof_entries_ETPP_Preprocessing_ARR_get(
    int unit)
{
    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "ETPP_Preprocessing_ARR", "DNX2");
    }
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_max_nof_entries, dnx_data_dnx2_arr_max_nof_entries_define_ETPP_Preprocessing_ARR);
}

uint32
dnx_data_dnx2_arr_max_nof_entries_ETPP_Termination_1_ARR_get(
    int unit)
{
    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "ETPP_Termination_1_ARR", "DNX2");
    }
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_max_nof_entries, dnx_data_dnx2_arr_max_nof_entries_define_ETPP_Termination_1_ARR);
}

uint32
dnx_data_dnx2_arr_max_nof_entries_ETPP_Termination_2_ARR_get(
    int unit)
{
    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "ETPP_Termination_2_ARR", "DNX2");
    }
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_max_nof_entries, dnx_data_dnx2_arr_max_nof_entries_define_ETPP_Termination_2_ARR);
}

uint32
dnx_data_dnx2_arr_max_nof_entries_IPPB_EXISTING_ARR_get(
    int unit)
{
    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "IPPB_EXISTING_ARR", "DNX2");
    }
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_max_nof_entries, dnx_data_dnx2_arr_max_nof_entries_define_IPPB_EXISTING_ARR);
}

uint32
dnx_data_dnx2_arr_max_nof_entries_IPPB_EXISTING_INCOMING_STRENGTH_ARR_get(
    int unit)
{
    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "IPPB_EXISTING_INCOMING_STRENGTH_ARR", "DNX2");
    }
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_max_nof_entries, dnx_data_dnx2_arr_max_nof_entries_define_IPPB_EXISTING_INCOMING_STRENGTH_ARR);
}

uint32
dnx_data_dnx2_arr_max_nof_entries_IPPB_INCOMING_ARR_get(
    int unit)
{
    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "IPPB_INCOMING_ARR", "DNX2");
    }
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_max_nof_entries, dnx_data_dnx2_arr_max_nof_entries_define_IPPB_INCOMING_ARR);
}

uint32
dnx_data_dnx2_arr_max_nof_entries_IRPP_FEC_ARR_get(
    int unit)
{
    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "IRPP_FEC_ARR", "DNX2");
    }
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_max_nof_entries, dnx_data_dnx2_arr_max_nof_entries_define_IRPP_FEC_ARR);
}

uint32
dnx_data_dnx2_arr_max_nof_entries_IRPP_FWD1_FWD_ARR_get(
    int unit)
{
    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "IRPP_FWD1_FWD_ARR", "DNX2");
    }
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_max_nof_entries, dnx_data_dnx2_arr_max_nof_entries_define_IRPP_FWD1_FWD_ARR);
}

uint32
dnx_data_dnx2_arr_max_nof_entries_IRPP_FWD1_RPF_ARR_get(
    int unit)
{
    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "IRPP_FWD1_RPF_ARR", "DNX2");
    }
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_max_nof_entries, dnx_data_dnx2_arr_max_nof_entries_define_IRPP_FWD1_RPF_ARR);
}

uint32
dnx_data_dnx2_arr_max_nof_entries_IRPP_SUPER_FEC_ARR_get(
    int unit)
{
    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "IRPP_SUPER_FEC_ARR", "DNX2");
    }
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_max_nof_entries, dnx_data_dnx2_arr_max_nof_entries_define_IRPP_SUPER_FEC_ARR);
}

uint32
dnx_data_dnx2_arr_max_nof_entries_IRPP_VSI_ARR_get(
    int unit)
{
    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "IRPP_VSI_ARR", "DNX2");
    }
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_max_nof_entries, dnx_data_dnx2_arr_max_nof_entries_define_IRPP_VSI_ARR);
}

uint32
dnx_data_dnx2_arr_max_nof_entries_IRPP_VTT_ARR_get(
    int unit)
{
    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "IRPP_VTT_ARR", "DNX2");
    }
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_max_nof_entries, dnx_data_dnx2_arr_max_nof_entries_define_IRPP_VTT_ARR);
}

uint32
dnx_data_dnx2_arr_max_nof_entries_ITPP_MACT_LEARN_JR1_TRANSLATE_ARR_get(
    int unit)
{
    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "ITPP_MACT_LEARN_JR1_TRANSLATE_ARR", "DNX2");
    }
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_max_nof_entries, dnx_data_dnx2_arr_max_nof_entries_define_ITPP_MACT_LEARN_JR1_TRANSLATE_ARR);
}

uint32
dnx_data_dnx2_arr_max_nof_entries_PPMC_ERPP_ARR_get(
    int unit)
{
    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "PPMC_ERPP_ARR", "DNX2");
    }
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_max_nof_entries, dnx_data_dnx2_arr_max_nof_entries_define_PPMC_ERPP_ARR);
}

uint32
dnx_data_dnx2_arr_max_nof_entries_USER_ALLOCATION_get(
    int unit)
{
    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "USER_ALLOCATION", "DNX2");
    }
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_max_nof_entries, dnx_data_dnx2_arr_max_nof_entries_define_USER_ALLOCATION);
}










static shr_error_e
dnx_data_dnx2_arr_formats_init(
    int unit,
    dnxc_data_submodule_t *submodule_data)
{
    SHR_FUNC_INIT_VARS(unit);

    submodule_data->name = "formats";
    submodule_data->doc = "";
    
    submodule_data->nof_features = _dnx_data_dnx2_arr_formats_feature_nof;
    DNXC_DATA_ALLOC(submodule_data->features, dnxc_data_feature_t,  submodule_data->nof_features, "_dnxc_data dnx2_arr formats features");

    
    submodule_data->nof_defines = _dnx_data_dnx2_arr_formats_define_nof;
    DNXC_DATA_ALLOC(submodule_data->defines, dnxc_data_define_t, submodule_data->nof_defines, "_dnxc_data dnx2_arr formats defines");

    
    submodule_data->nof_tables = _dnx_data_dnx2_arr_formats_table_nof;
    DNXC_DATA_ALLOC(submodule_data->tables, dnxc_data_table_t, submodule_data->nof_tables, "_dnxc_data dnx2_arr formats tables");

    if (soc_is(unit, DNX2_DEVICE))
    {
        
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_files].name = "files";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_files].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_files].flags |= DNXC_DATA_F_TABLE;
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_files].size_of_values = sizeof(dnx_data_dnx2_arr_formats_files_t);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_files].entry_get = dnx_data_dnx2_arr_formats_files_entry_str_get;

        
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_files].nof_keys = 0;

        
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_files].nof_values = 1;
        DNXC_DATA_ALLOC(submodule_data->tables[dnx_data_dnx2_arr_formats_table_files].values, dnxc_data_value_t, submodule_data->tables[dnx_data_dnx2_arr_formats_table_files].nof_values, "_dnx_data_dnx2_arr_formats_table_files table values");
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_files].values[0].name = "arr_formats_file";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_files].values[0].type = "char *";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_files].values[0].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_files].values[0].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_files_t, arr_formats_file);
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_MACT_AGE_PROFILE_ARR_CFG].name = "MACT_AGE_PROFILE_ARR_CFG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_MACT_AGE_PROFILE_ARR_CFG].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_MACT_AGE_PROFILE_ARR_CFG].flags |= DNXC_DATA_F_TABLE;
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_MACT_AGE_PROFILE_ARR_CFG].size_of_values = sizeof(dnx_data_dnx2_arr_formats_MACT_AGE_PROFILE_ARR_CFG_t);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_MACT_AGE_PROFILE_ARR_CFG].entry_get = dnx_data_dnx2_arr_formats_MACT_AGE_PROFILE_ARR_CFG_entry_str_get;

        
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_MACT_AGE_PROFILE_ARR_CFG].nof_keys = 1;
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_MACT_AGE_PROFILE_ARR_CFG].keys[0].name = "index";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_MACT_AGE_PROFILE_ARR_CFG].keys[0].doc = "";

        
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_MACT_AGE_PROFILE_ARR_CFG].nof_values = 4;
        DNXC_DATA_ALLOC(submodule_data->tables[dnx_data_dnx2_arr_formats_table_MACT_AGE_PROFILE_ARR_CFG].values, dnxc_data_value_t, submodule_data->tables[dnx_data_dnx2_arr_formats_table_MACT_AGE_PROFILE_ARR_CFG].nof_values, "_dnx_data_dnx2_arr_formats_table_MACT_AGE_PROFILE_ARR_CFG table values");
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_MACT_AGE_PROFILE_ARR_CFG].values[0].name = "valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_MACT_AGE_PROFILE_ARR_CFG].values[0].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_MACT_AGE_PROFILE_ARR_CFG].values[0].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_MACT_AGE_PROFILE_ARR_CFG].values[0].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_MACT_AGE_PROFILE_ARR_CFG_t, valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_MACT_AGE_PROFILE_ARR_CFG].values[1].name = "doc";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_MACT_AGE_PROFILE_ARR_CFG].values[1].type = "char *";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_MACT_AGE_PROFILE_ARR_CFG].values[1].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_MACT_AGE_PROFILE_ARR_CFG].values[1].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_MACT_AGE_PROFILE_ARR_CFG_t, doc);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_MACT_AGE_PROFILE_ARR_CFG].values[2].name = "AGE_PROFILE";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_MACT_AGE_PROFILE_ARR_CFG].values[2].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_MACT_AGE_PROFILE_ARR_CFG].values[2].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_MACT_AGE_PROFILE_ARR_CFG].values[2].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_MACT_AGE_PROFILE_ARR_CFG_t, AGE_PROFILE);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_MACT_AGE_PROFILE_ARR_CFG].values[3].name = "AGE_PROFILE_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_MACT_AGE_PROFILE_ARR_CFG].values[3].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_MACT_AGE_PROFILE_ARR_CFG].values[3].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_MACT_AGE_PROFILE_ARR_CFG].values[3].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_MACT_AGE_PROFILE_ARR_CFG_t, AGE_PROFILE_valid);
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].name = "ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].flags |= DNXC_DATA_F_TABLE;
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].size_of_values = sizeof(dnx_data_dnx2_arr_formats_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE_t);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].entry_get = dnx_data_dnx2_arr_formats_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE_entry_str_get;

        
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].nof_keys = 1;
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].keys[0].name = "index";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].keys[0].doc = "";

        
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].nof_values = 36;
        DNXC_DATA_ALLOC(submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values, dnxc_data_value_t, submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].nof_values, "_dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE table values");
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[0].name = "valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[0].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[0].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[0].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE_t, valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[1].name = "doc";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[1].type = "char *";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[1].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[1].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE_t, doc);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[2].name = "DUAL_HOMING_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[2].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[2].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[2].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE_t, DUAL_HOMING_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[3].name = "DUAL_HOMING_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[3].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[3].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[3].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE_t, DUAL_HOMING_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[4].name = "EGRESS_LAST_LAYER_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[4].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[4].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[4].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE_t, EGRESS_LAST_LAYER_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[5].name = "EGRESS_LAST_LAYER_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[5].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[5].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[5].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE_t, EGRESS_LAST_LAYER_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[6].name = "VLAN_MEMBERSHIP_INTERFACE_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[6].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[6].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[6].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE_t, VLAN_MEMBERSHIP_INTERFACE_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[7].name = "VLAN_MEMBERSHIP_INTERFACE_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[7].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[7].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[7].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE_t, VLAN_MEMBERSHIP_INTERFACE_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[8].name = "ENCAP_DESTINATION_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[8].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[8].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[8].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE_t, ENCAP_DESTINATION_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[9].name = "ENCAP_DESTINATION_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[9].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[9].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[9].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE_t, ENCAP_DESTINATION_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[10].name = "QOS_MODEL_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[10].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[10].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[10].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE_t, QOS_MODEL_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[11].name = "QOS_MODEL_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[11].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[11].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[11].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE_t, QOS_MODEL_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[12].name = "FORWARD_DOMAIN_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[12].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[12].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[12].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE_t, FORWARD_DOMAIN_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[13].name = "FORWARD_DOMAIN_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[13].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[13].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[13].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE_t, FORWARD_DOMAIN_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[14].name = "FORWARD_DOMAIN_NETWORK_NAME_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[14].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[14].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[14].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE_t, FORWARD_DOMAIN_NETWORK_NAME_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[15].name = "FORWARD_DOMAIN_NETWORK_NAME_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[15].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[15].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[15].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE_t, FORWARD_DOMAIN_NETWORK_NAME_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[16].name = "LIF_ADDITIONAL_HEADERS_PROFILE_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[16].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[16].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[16].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE_t, LIF_ADDITIONAL_HEADERS_PROFILE_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[17].name = "LIF_ADDITIONAL_HEADERS_PROFILE_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[17].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[17].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[17].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE_t, LIF_ADDITIONAL_HEADERS_PROFILE_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[18].name = "MTU_PROFILE_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[18].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[18].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[18].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE_t, MTU_PROFILE_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[19].name = "MTU_PROFILE_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[19].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[19].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[19].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE_t, MTU_PROFILE_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[20].name = "NWK_QOS_IDX_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[20].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[20].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[20].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE_t, NWK_QOS_IDX_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[21].name = "NWK_QOS_IDX_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[21].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[21].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[21].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE_t, NWK_QOS_IDX_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[22].name = "REMARK_PROFILE_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[22].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[22].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[22].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE_t, REMARK_PROFILE_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[23].name = "REMARK_PROFILE_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[23].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[23].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[23].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE_t, REMARK_PROFILE_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[24].name = "SOURCE_IDX_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[24].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[24].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[24].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE_t, SOURCE_IDX_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[25].name = "SOURCE_IDX_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[25].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[25].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[25].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE_t, SOURCE_IDX_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[26].name = "LIF_STATISTICS_OBJECT_COMMAND_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[26].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[26].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[26].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE_t, LIF_STATISTICS_OBJECT_COMMAND_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[27].name = "LIF_STATISTICS_OBJECT_COMMAND_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[27].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[27].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[27].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE_t, LIF_STATISTICS_OBJECT_COMMAND_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[28].name = "LIF_STATISTICS_OBJECT_ID_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[28].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[28].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[28].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE_t, LIF_STATISTICS_OBJECT_ID_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[29].name = "LIF_STATISTICS_OBJECT_ID_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[29].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[29].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[29].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE_t, LIF_STATISTICS_OBJECT_ID_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[30].name = "TTL_MODEL_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[30].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[30].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[30].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE_t, TTL_MODEL_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[31].name = "TTL_MODEL_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[31].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[31].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[31].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE_t, TTL_MODEL_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[32].name = "TTL_IDX_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[32].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[32].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[32].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE_t, TTL_IDX_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[33].name = "TTL_IDX_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[33].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[33].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[33].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE_t, TTL_IDX_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[34].name = "VLAN_EDIT_PROFILE_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[34].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[34].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[34].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE_t, VLAN_EDIT_PROFILE_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[35].name = "VLAN_EDIT_PROFILE_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[35].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[35].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE].values[35].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE_t, VLAN_EDIT_PROFILE_CONFIG_valid);
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].name = "ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].flags |= DNXC_DATA_F_TABLE;
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].size_of_values = sizeof(dnx_data_dnx2_arr_formats_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE_t);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].entry_get = dnx_data_dnx2_arr_formats_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE_entry_str_get;

        
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].nof_keys = 1;
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].keys[0].name = "index";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].keys[0].doc = "";

        
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].nof_values = 36;
        DNXC_DATA_ALLOC(submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values, dnxc_data_value_t, submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].nof_values, "_dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE table values");
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[0].name = "valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[0].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[0].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[0].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE_t, valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[1].name = "doc";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[1].type = "char *";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[1].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[1].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE_t, doc);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[2].name = "DUAL_HOMING_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[2].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[2].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[2].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE_t, DUAL_HOMING_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[3].name = "DUAL_HOMING_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[3].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[3].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[3].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE_t, DUAL_HOMING_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[4].name = "EGRESS_LAST_LAYER_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[4].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[4].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[4].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE_t, EGRESS_LAST_LAYER_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[5].name = "EGRESS_LAST_LAYER_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[5].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[5].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[5].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE_t, EGRESS_LAST_LAYER_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[6].name = "VLAN_MEMBERSHIP_INTERFACE_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[6].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[6].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[6].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE_t, VLAN_MEMBERSHIP_INTERFACE_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[7].name = "VLAN_MEMBERSHIP_INTERFACE_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[7].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[7].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[7].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE_t, VLAN_MEMBERSHIP_INTERFACE_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[8].name = "ENCAP_DESTINATION_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[8].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[8].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[8].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE_t, ENCAP_DESTINATION_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[9].name = "ENCAP_DESTINATION_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[9].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[9].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[9].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE_t, ENCAP_DESTINATION_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[10].name = "QOS_MODEL_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[10].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[10].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[10].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE_t, QOS_MODEL_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[11].name = "QOS_MODEL_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[11].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[11].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[11].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE_t, QOS_MODEL_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[12].name = "FORWARD_DOMAIN_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[12].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[12].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[12].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE_t, FORWARD_DOMAIN_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[13].name = "FORWARD_DOMAIN_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[13].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[13].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[13].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE_t, FORWARD_DOMAIN_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[14].name = "FORWARD_DOMAIN_NETWORK_NAME_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[14].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[14].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[14].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE_t, FORWARD_DOMAIN_NETWORK_NAME_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[15].name = "FORWARD_DOMAIN_NETWORK_NAME_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[15].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[15].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[15].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE_t, FORWARD_DOMAIN_NETWORK_NAME_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[16].name = "LIF_ADDITIONAL_HEADERS_PROFILE_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[16].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[16].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[16].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE_t, LIF_ADDITIONAL_HEADERS_PROFILE_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[17].name = "LIF_ADDITIONAL_HEADERS_PROFILE_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[17].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[17].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[17].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE_t, LIF_ADDITIONAL_HEADERS_PROFILE_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[18].name = "MTU_PROFILE_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[18].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[18].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[18].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE_t, MTU_PROFILE_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[19].name = "MTU_PROFILE_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[19].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[19].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[19].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE_t, MTU_PROFILE_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[20].name = "NWK_QOS_IDX_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[20].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[20].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[20].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE_t, NWK_QOS_IDX_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[21].name = "NWK_QOS_IDX_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[21].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[21].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[21].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE_t, NWK_QOS_IDX_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[22].name = "REMARK_PROFILE_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[22].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[22].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[22].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE_t, REMARK_PROFILE_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[23].name = "REMARK_PROFILE_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[23].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[23].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[23].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE_t, REMARK_PROFILE_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[24].name = "SOURCE_IDX_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[24].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[24].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[24].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE_t, SOURCE_IDX_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[25].name = "SOURCE_IDX_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[25].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[25].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[25].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE_t, SOURCE_IDX_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[26].name = "LIF_STATISTICS_OBJECT_COMMAND_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[26].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[26].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[26].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE_t, LIF_STATISTICS_OBJECT_COMMAND_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[27].name = "LIF_STATISTICS_OBJECT_COMMAND_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[27].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[27].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[27].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE_t, LIF_STATISTICS_OBJECT_COMMAND_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[28].name = "LIF_STATISTICS_OBJECT_ID_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[28].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[28].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[28].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE_t, LIF_STATISTICS_OBJECT_ID_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[29].name = "LIF_STATISTICS_OBJECT_ID_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[29].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[29].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[29].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE_t, LIF_STATISTICS_OBJECT_ID_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[30].name = "TTL_MODEL_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[30].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[30].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[30].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE_t, TTL_MODEL_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[31].name = "TTL_MODEL_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[31].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[31].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[31].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE_t, TTL_MODEL_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[32].name = "TTL_IDX_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[32].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[32].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[32].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE_t, TTL_IDX_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[33].name = "TTL_IDX_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[33].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[33].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[33].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE_t, TTL_IDX_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[34].name = "VLAN_EDIT_PROFILE_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[34].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[34].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[34].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE_t, VLAN_EDIT_PROFILE_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[35].name = "VLAN_EDIT_PROFILE_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[35].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[35].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE].values[35].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE_t, VLAN_EDIT_PROFILE_CONFIG_valid);
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].name = "ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].flags |= DNXC_DATA_F_TABLE;
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].size_of_values = sizeof(dnx_data_dnx2_arr_formats_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE_t);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].entry_get = dnx_data_dnx2_arr_formats_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE_entry_str_get;

        
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].nof_keys = 1;
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].keys[0].name = "index";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].keys[0].doc = "";

        
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].nof_values = 36;
        DNXC_DATA_ALLOC(submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values, dnxc_data_value_t, submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].nof_values, "_dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE table values");
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[0].name = "valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[0].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[0].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[0].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE_t, valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[1].name = "doc";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[1].type = "char *";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[1].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[1].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE_t, doc);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[2].name = "DUAL_HOMING_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[2].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[2].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[2].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE_t, DUAL_HOMING_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[3].name = "DUAL_HOMING_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[3].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[3].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[3].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE_t, DUAL_HOMING_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[4].name = "EGRESS_LAST_LAYER_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[4].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[4].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[4].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE_t, EGRESS_LAST_LAYER_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[5].name = "EGRESS_LAST_LAYER_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[5].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[5].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[5].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE_t, EGRESS_LAST_LAYER_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[6].name = "VLAN_MEMBERSHIP_INTERFACE_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[6].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[6].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[6].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE_t, VLAN_MEMBERSHIP_INTERFACE_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[7].name = "VLAN_MEMBERSHIP_INTERFACE_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[7].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[7].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[7].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE_t, VLAN_MEMBERSHIP_INTERFACE_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[8].name = "ENCAP_DESTINATION_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[8].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[8].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[8].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE_t, ENCAP_DESTINATION_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[9].name = "ENCAP_DESTINATION_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[9].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[9].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[9].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE_t, ENCAP_DESTINATION_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[10].name = "QOS_MODEL_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[10].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[10].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[10].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE_t, QOS_MODEL_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[11].name = "QOS_MODEL_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[11].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[11].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[11].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE_t, QOS_MODEL_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[12].name = "FORWARD_DOMAIN_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[12].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[12].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[12].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE_t, FORWARD_DOMAIN_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[13].name = "FORWARD_DOMAIN_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[13].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[13].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[13].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE_t, FORWARD_DOMAIN_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[14].name = "FORWARD_DOMAIN_NETWORK_NAME_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[14].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[14].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[14].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE_t, FORWARD_DOMAIN_NETWORK_NAME_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[15].name = "FORWARD_DOMAIN_NETWORK_NAME_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[15].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[15].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[15].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE_t, FORWARD_DOMAIN_NETWORK_NAME_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[16].name = "LIF_ADDITIONAL_HEADERS_PROFILE_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[16].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[16].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[16].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE_t, LIF_ADDITIONAL_HEADERS_PROFILE_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[17].name = "LIF_ADDITIONAL_HEADERS_PROFILE_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[17].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[17].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[17].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE_t, LIF_ADDITIONAL_HEADERS_PROFILE_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[18].name = "MTU_PROFILE_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[18].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[18].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[18].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE_t, MTU_PROFILE_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[19].name = "MTU_PROFILE_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[19].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[19].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[19].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE_t, MTU_PROFILE_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[20].name = "NWK_QOS_IDX_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[20].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[20].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[20].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE_t, NWK_QOS_IDX_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[21].name = "NWK_QOS_IDX_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[21].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[21].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[21].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE_t, NWK_QOS_IDX_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[22].name = "REMARK_PROFILE_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[22].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[22].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[22].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE_t, REMARK_PROFILE_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[23].name = "REMARK_PROFILE_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[23].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[23].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[23].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE_t, REMARK_PROFILE_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[24].name = "SOURCE_IDX_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[24].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[24].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[24].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE_t, SOURCE_IDX_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[25].name = "SOURCE_IDX_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[25].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[25].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[25].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE_t, SOURCE_IDX_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[26].name = "LIF_STATISTICS_OBJECT_COMMAND_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[26].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[26].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[26].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE_t, LIF_STATISTICS_OBJECT_COMMAND_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[27].name = "LIF_STATISTICS_OBJECT_COMMAND_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[27].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[27].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[27].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE_t, LIF_STATISTICS_OBJECT_COMMAND_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[28].name = "LIF_STATISTICS_OBJECT_ID_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[28].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[28].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[28].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE_t, LIF_STATISTICS_OBJECT_ID_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[29].name = "LIF_STATISTICS_OBJECT_ID_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[29].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[29].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[29].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE_t, LIF_STATISTICS_OBJECT_ID_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[30].name = "TTL_MODEL_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[30].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[30].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[30].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE_t, TTL_MODEL_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[31].name = "TTL_MODEL_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[31].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[31].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[31].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE_t, TTL_MODEL_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[32].name = "TTL_IDX_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[32].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[32].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[32].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE_t, TTL_IDX_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[33].name = "TTL_IDX_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[33].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[33].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[33].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE_t, TTL_IDX_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[34].name = "VLAN_EDIT_PROFILE_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[34].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[34].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[34].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE_t, VLAN_EDIT_PROFILE_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[35].name = "VLAN_EDIT_PROFILE_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[35].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[35].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE].values[35].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE_t, VLAN_EDIT_PROFILE_CONFIG_valid);
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].name = "ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].flags |= DNXC_DATA_F_TABLE;
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].size_of_values = sizeof(dnx_data_dnx2_arr_formats_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE_t);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].entry_get = dnx_data_dnx2_arr_formats_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE_entry_str_get;

        
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].nof_keys = 1;
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].keys[0].name = "index";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].keys[0].doc = "";

        
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].nof_values = 36;
        DNXC_DATA_ALLOC(submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values, dnxc_data_value_t, submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].nof_values, "_dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE table values");
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[0].name = "valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[0].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[0].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[0].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE_t, valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[1].name = "doc";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[1].type = "char *";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[1].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[1].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE_t, doc);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[2].name = "DUAL_HOMING_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[2].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[2].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[2].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE_t, DUAL_HOMING_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[3].name = "DUAL_HOMING_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[3].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[3].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[3].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE_t, DUAL_HOMING_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[4].name = "EGRESS_LAST_LAYER_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[4].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[4].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[4].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE_t, EGRESS_LAST_LAYER_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[5].name = "EGRESS_LAST_LAYER_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[5].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[5].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[5].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE_t, EGRESS_LAST_LAYER_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[6].name = "VLAN_MEMBERSHIP_INTERFACE_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[6].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[6].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[6].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE_t, VLAN_MEMBERSHIP_INTERFACE_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[7].name = "VLAN_MEMBERSHIP_INTERFACE_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[7].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[7].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[7].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE_t, VLAN_MEMBERSHIP_INTERFACE_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[8].name = "ENCAP_DESTINATION_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[8].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[8].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[8].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE_t, ENCAP_DESTINATION_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[9].name = "ENCAP_DESTINATION_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[9].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[9].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[9].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE_t, ENCAP_DESTINATION_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[10].name = "QOS_MODEL_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[10].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[10].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[10].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE_t, QOS_MODEL_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[11].name = "QOS_MODEL_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[11].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[11].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[11].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE_t, QOS_MODEL_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[12].name = "FORWARD_DOMAIN_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[12].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[12].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[12].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE_t, FORWARD_DOMAIN_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[13].name = "FORWARD_DOMAIN_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[13].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[13].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[13].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE_t, FORWARD_DOMAIN_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[14].name = "FORWARD_DOMAIN_NETWORK_NAME_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[14].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[14].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[14].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE_t, FORWARD_DOMAIN_NETWORK_NAME_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[15].name = "FORWARD_DOMAIN_NETWORK_NAME_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[15].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[15].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[15].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE_t, FORWARD_DOMAIN_NETWORK_NAME_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[16].name = "LIF_ADDITIONAL_HEADERS_PROFILE_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[16].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[16].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[16].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE_t, LIF_ADDITIONAL_HEADERS_PROFILE_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[17].name = "LIF_ADDITIONAL_HEADERS_PROFILE_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[17].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[17].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[17].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE_t, LIF_ADDITIONAL_HEADERS_PROFILE_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[18].name = "MTU_PROFILE_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[18].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[18].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[18].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE_t, MTU_PROFILE_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[19].name = "MTU_PROFILE_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[19].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[19].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[19].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE_t, MTU_PROFILE_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[20].name = "NWK_QOS_IDX_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[20].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[20].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[20].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE_t, NWK_QOS_IDX_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[21].name = "NWK_QOS_IDX_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[21].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[21].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[21].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE_t, NWK_QOS_IDX_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[22].name = "REMARK_PROFILE_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[22].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[22].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[22].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE_t, REMARK_PROFILE_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[23].name = "REMARK_PROFILE_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[23].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[23].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[23].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE_t, REMARK_PROFILE_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[24].name = "SOURCE_IDX_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[24].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[24].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[24].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE_t, SOURCE_IDX_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[25].name = "SOURCE_IDX_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[25].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[25].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[25].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE_t, SOURCE_IDX_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[26].name = "LIF_STATISTICS_OBJECT_COMMAND_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[26].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[26].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[26].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE_t, LIF_STATISTICS_OBJECT_COMMAND_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[27].name = "LIF_STATISTICS_OBJECT_COMMAND_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[27].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[27].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[27].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE_t, LIF_STATISTICS_OBJECT_COMMAND_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[28].name = "LIF_STATISTICS_OBJECT_ID_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[28].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[28].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[28].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE_t, LIF_STATISTICS_OBJECT_ID_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[29].name = "LIF_STATISTICS_OBJECT_ID_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[29].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[29].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[29].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE_t, LIF_STATISTICS_OBJECT_ID_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[30].name = "TTL_MODEL_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[30].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[30].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[30].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE_t, TTL_MODEL_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[31].name = "TTL_MODEL_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[31].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[31].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[31].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE_t, TTL_MODEL_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[32].name = "TTL_IDX_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[32].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[32].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[32].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE_t, TTL_IDX_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[33].name = "TTL_IDX_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[33].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[33].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[33].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE_t, TTL_IDX_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[34].name = "VLAN_EDIT_PROFILE_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[34].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[34].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[34].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE_t, VLAN_EDIT_PROFILE_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[35].name = "VLAN_EDIT_PROFILE_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[35].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[35].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE].values[35].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE_t, VLAN_EDIT_PROFILE_CONFIG_valid);
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].name = "ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].flags |= DNXC_DATA_F_TABLE;
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].size_of_values = sizeof(dnx_data_dnx2_arr_formats_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE_t);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].entry_get = dnx_data_dnx2_arr_formats_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE_entry_str_get;

        
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].nof_keys = 1;
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].keys[0].name = "index";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].keys[0].doc = "";

        
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].nof_values = 36;
        DNXC_DATA_ALLOC(submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values, dnxc_data_value_t, submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].nof_values, "_dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE table values");
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[0].name = "valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[0].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[0].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[0].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE_t, valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[1].name = "doc";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[1].type = "char *";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[1].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[1].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE_t, doc);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[2].name = "DUAL_HOMING_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[2].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[2].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[2].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE_t, DUAL_HOMING_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[3].name = "DUAL_HOMING_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[3].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[3].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[3].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE_t, DUAL_HOMING_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[4].name = "EGRESS_LAST_LAYER_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[4].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[4].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[4].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE_t, EGRESS_LAST_LAYER_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[5].name = "EGRESS_LAST_LAYER_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[5].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[5].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[5].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE_t, EGRESS_LAST_LAYER_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[6].name = "VLAN_MEMBERSHIP_INTERFACE_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[6].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[6].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[6].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE_t, VLAN_MEMBERSHIP_INTERFACE_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[7].name = "VLAN_MEMBERSHIP_INTERFACE_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[7].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[7].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[7].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE_t, VLAN_MEMBERSHIP_INTERFACE_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[8].name = "ENCAP_DESTINATION_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[8].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[8].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[8].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE_t, ENCAP_DESTINATION_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[9].name = "ENCAP_DESTINATION_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[9].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[9].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[9].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE_t, ENCAP_DESTINATION_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[10].name = "QOS_MODEL_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[10].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[10].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[10].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE_t, QOS_MODEL_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[11].name = "QOS_MODEL_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[11].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[11].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[11].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE_t, QOS_MODEL_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[12].name = "FORWARD_DOMAIN_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[12].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[12].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[12].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE_t, FORWARD_DOMAIN_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[13].name = "FORWARD_DOMAIN_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[13].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[13].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[13].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE_t, FORWARD_DOMAIN_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[14].name = "FORWARD_DOMAIN_NETWORK_NAME_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[14].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[14].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[14].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE_t, FORWARD_DOMAIN_NETWORK_NAME_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[15].name = "FORWARD_DOMAIN_NETWORK_NAME_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[15].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[15].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[15].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE_t, FORWARD_DOMAIN_NETWORK_NAME_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[16].name = "LIF_ADDITIONAL_HEADERS_PROFILE_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[16].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[16].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[16].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE_t, LIF_ADDITIONAL_HEADERS_PROFILE_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[17].name = "LIF_ADDITIONAL_HEADERS_PROFILE_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[17].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[17].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[17].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE_t, LIF_ADDITIONAL_HEADERS_PROFILE_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[18].name = "MTU_PROFILE_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[18].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[18].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[18].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE_t, MTU_PROFILE_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[19].name = "MTU_PROFILE_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[19].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[19].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[19].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE_t, MTU_PROFILE_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[20].name = "NWK_QOS_IDX_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[20].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[20].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[20].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE_t, NWK_QOS_IDX_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[21].name = "NWK_QOS_IDX_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[21].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[21].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[21].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE_t, NWK_QOS_IDX_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[22].name = "REMARK_PROFILE_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[22].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[22].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[22].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE_t, REMARK_PROFILE_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[23].name = "REMARK_PROFILE_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[23].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[23].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[23].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE_t, REMARK_PROFILE_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[24].name = "SOURCE_IDX_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[24].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[24].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[24].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE_t, SOURCE_IDX_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[25].name = "SOURCE_IDX_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[25].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[25].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[25].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE_t, SOURCE_IDX_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[26].name = "LIF_STATISTICS_OBJECT_COMMAND_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[26].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[26].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[26].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE_t, LIF_STATISTICS_OBJECT_COMMAND_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[27].name = "LIF_STATISTICS_OBJECT_COMMAND_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[27].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[27].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[27].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE_t, LIF_STATISTICS_OBJECT_COMMAND_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[28].name = "LIF_STATISTICS_OBJECT_ID_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[28].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[28].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[28].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE_t, LIF_STATISTICS_OBJECT_ID_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[29].name = "LIF_STATISTICS_OBJECT_ID_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[29].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[29].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[29].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE_t, LIF_STATISTICS_OBJECT_ID_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[30].name = "TTL_MODEL_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[30].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[30].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[30].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE_t, TTL_MODEL_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[31].name = "TTL_MODEL_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[31].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[31].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[31].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE_t, TTL_MODEL_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[32].name = "TTL_IDX_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[32].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[32].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[32].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE_t, TTL_IDX_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[33].name = "TTL_IDX_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[33].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[33].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[33].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE_t, TTL_IDX_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[34].name = "VLAN_EDIT_PROFILE_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[34].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[34].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[34].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE_t, VLAN_EDIT_PROFILE_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[35].name = "VLAN_EDIT_PROFILE_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[35].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[35].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE].values[35].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE_t, VLAN_EDIT_PROFILE_CONFIG_valid);
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_FORMAT_CONFIGURATION_TABLE].name = "ETPPB_ENC_FORMAT_CONFIGURATION_TABLE";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_FORMAT_CONFIGURATION_TABLE].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_FORMAT_CONFIGURATION_TABLE].flags |= DNXC_DATA_F_TABLE;
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_FORMAT_CONFIGURATION_TABLE].size_of_values = sizeof(dnx_data_dnx2_arr_formats_ETPPB_ENC_FORMAT_CONFIGURATION_TABLE_t);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_FORMAT_CONFIGURATION_TABLE].entry_get = dnx_data_dnx2_arr_formats_ETPPB_ENC_FORMAT_CONFIGURATION_TABLE_entry_str_get;

        
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_FORMAT_CONFIGURATION_TABLE].nof_keys = 1;
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_FORMAT_CONFIGURATION_TABLE].keys[0].name = "index";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_FORMAT_CONFIGURATION_TABLE].keys[0].doc = "";

        
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_FORMAT_CONFIGURATION_TABLE].nof_values = 8;
        DNXC_DATA_ALLOC(submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_FORMAT_CONFIGURATION_TABLE].values, dnxc_data_value_t, submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_FORMAT_CONFIGURATION_TABLE].nof_values, "_dnx_data_dnx2_arr_formats_table_ETPPB_ENC_FORMAT_CONFIGURATION_TABLE table values");
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_FORMAT_CONFIGURATION_TABLE].values[0].name = "valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_FORMAT_CONFIGURATION_TABLE].values[0].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_FORMAT_CONFIGURATION_TABLE].values[0].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_FORMAT_CONFIGURATION_TABLE].values[0].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_FORMAT_CONFIGURATION_TABLE_t, valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_FORMAT_CONFIGURATION_TABLE].values[1].name = "doc";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_FORMAT_CONFIGURATION_TABLE].values[1].type = "char *";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_FORMAT_CONFIGURATION_TABLE].values[1].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_FORMAT_CONFIGURATION_TABLE].values[1].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_FORMAT_CONFIGURATION_TABLE_t, doc);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_FORMAT_CONFIGURATION_TABLE].values[2].name = "VLAN_MEMBERSHIP_INTERFACE_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_FORMAT_CONFIGURATION_TABLE].values[2].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_FORMAT_CONFIGURATION_TABLE].values[2].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_FORMAT_CONFIGURATION_TABLE].values[2].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_FORMAT_CONFIGURATION_TABLE_t, VLAN_MEMBERSHIP_INTERFACE_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_FORMAT_CONFIGURATION_TABLE].values[3].name = "VLAN_MEMBERSHIP_INTERFACE_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_FORMAT_CONFIGURATION_TABLE].values[3].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_FORMAT_CONFIGURATION_TABLE].values[3].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_FORMAT_CONFIGURATION_TABLE].values[3].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_FORMAT_CONFIGURATION_TABLE_t, VLAN_MEMBERSHIP_INTERFACE_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_FORMAT_CONFIGURATION_TABLE].values[4].name = "ENCAP_DESTINATION_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_FORMAT_CONFIGURATION_TABLE].values[4].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_FORMAT_CONFIGURATION_TABLE].values[4].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_FORMAT_CONFIGURATION_TABLE].values[4].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_FORMAT_CONFIGURATION_TABLE_t, ENCAP_DESTINATION_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_FORMAT_CONFIGURATION_TABLE].values[5].name = "ENCAP_DESTINATION_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_FORMAT_CONFIGURATION_TABLE].values[5].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_FORMAT_CONFIGURATION_TABLE].values[5].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_FORMAT_CONFIGURATION_TABLE].values[5].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_FORMAT_CONFIGURATION_TABLE_t, ENCAP_DESTINATION_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_FORMAT_CONFIGURATION_TABLE].values[6].name = "REMARK_PROFILE_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_FORMAT_CONFIGURATION_TABLE].values[6].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_FORMAT_CONFIGURATION_TABLE].values[6].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_FORMAT_CONFIGURATION_TABLE].values[6].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_FORMAT_CONFIGURATION_TABLE_t, REMARK_PROFILE_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_FORMAT_CONFIGURATION_TABLE].values[7].name = "REMARK_PROFILE_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_FORMAT_CONFIGURATION_TABLE].values[7].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_FORMAT_CONFIGURATION_TABLE].values[7].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_FORMAT_CONFIGURATION_TABLE].values[7].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_FORMAT_CONFIGURATION_TABLE_t, REMARK_PROFILE_CONFIG_valid);
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_FORMAT_CONFIGURATION_TABLE].name = "ETPPC_ENC_FORMAT_CONFIGURATION_TABLE";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_FORMAT_CONFIGURATION_TABLE].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_FORMAT_CONFIGURATION_TABLE].flags |= DNXC_DATA_F_TABLE;
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_FORMAT_CONFIGURATION_TABLE].size_of_values = sizeof(dnx_data_dnx2_arr_formats_ETPPC_ENC_FORMAT_CONFIGURATION_TABLE_t);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_FORMAT_CONFIGURATION_TABLE].entry_get = dnx_data_dnx2_arr_formats_ETPPC_ENC_FORMAT_CONFIGURATION_TABLE_entry_str_get;

        
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_FORMAT_CONFIGURATION_TABLE].nof_keys = 1;
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_FORMAT_CONFIGURATION_TABLE].keys[0].name = "index";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_FORMAT_CONFIGURATION_TABLE].keys[0].doc = "";

        
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_FORMAT_CONFIGURATION_TABLE].nof_values = 8;
        DNXC_DATA_ALLOC(submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_FORMAT_CONFIGURATION_TABLE].values, dnxc_data_value_t, submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_FORMAT_CONFIGURATION_TABLE].nof_values, "_dnx_data_dnx2_arr_formats_table_ETPPC_ENC_FORMAT_CONFIGURATION_TABLE table values");
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_FORMAT_CONFIGURATION_TABLE].values[0].name = "valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_FORMAT_CONFIGURATION_TABLE].values[0].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_FORMAT_CONFIGURATION_TABLE].values[0].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_FORMAT_CONFIGURATION_TABLE].values[0].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPC_ENC_FORMAT_CONFIGURATION_TABLE_t, valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_FORMAT_CONFIGURATION_TABLE].values[1].name = "doc";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_FORMAT_CONFIGURATION_TABLE].values[1].type = "char *";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_FORMAT_CONFIGURATION_TABLE].values[1].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_FORMAT_CONFIGURATION_TABLE].values[1].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPC_ENC_FORMAT_CONFIGURATION_TABLE_t, doc);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_FORMAT_CONFIGURATION_TABLE].values[2].name = "VLAN_MEMBERSHIP_INTERFACE_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_FORMAT_CONFIGURATION_TABLE].values[2].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_FORMAT_CONFIGURATION_TABLE].values[2].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_FORMAT_CONFIGURATION_TABLE].values[2].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPC_ENC_FORMAT_CONFIGURATION_TABLE_t, VLAN_MEMBERSHIP_INTERFACE_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_FORMAT_CONFIGURATION_TABLE].values[3].name = "VLAN_MEMBERSHIP_INTERFACE_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_FORMAT_CONFIGURATION_TABLE].values[3].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_FORMAT_CONFIGURATION_TABLE].values[3].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_FORMAT_CONFIGURATION_TABLE].values[3].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPC_ENC_FORMAT_CONFIGURATION_TABLE_t, VLAN_MEMBERSHIP_INTERFACE_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_FORMAT_CONFIGURATION_TABLE].values[4].name = "ENCAP_DESTINATION_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_FORMAT_CONFIGURATION_TABLE].values[4].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_FORMAT_CONFIGURATION_TABLE].values[4].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_FORMAT_CONFIGURATION_TABLE].values[4].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPC_ENC_FORMAT_CONFIGURATION_TABLE_t, ENCAP_DESTINATION_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_FORMAT_CONFIGURATION_TABLE].values[5].name = "ENCAP_DESTINATION_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_FORMAT_CONFIGURATION_TABLE].values[5].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_FORMAT_CONFIGURATION_TABLE].values[5].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_FORMAT_CONFIGURATION_TABLE].values[5].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPC_ENC_FORMAT_CONFIGURATION_TABLE_t, ENCAP_DESTINATION_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_FORMAT_CONFIGURATION_TABLE].values[6].name = "REMARK_PROFILE_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_FORMAT_CONFIGURATION_TABLE].values[6].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_FORMAT_CONFIGURATION_TABLE].values[6].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_FORMAT_CONFIGURATION_TABLE].values[6].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPC_ENC_FORMAT_CONFIGURATION_TABLE_t, REMARK_PROFILE_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_FORMAT_CONFIGURATION_TABLE].values[7].name = "REMARK_PROFILE_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_FORMAT_CONFIGURATION_TABLE].values[7].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_FORMAT_CONFIGURATION_TABLE].values[7].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_FORMAT_CONFIGURATION_TABLE].values[7].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPC_ENC_FORMAT_CONFIGURATION_TABLE_t, REMARK_PROFILE_CONFIG_valid);
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_1_FORMAT_CONFIGURATION_TABLE].name = "ETPPB_ENC_2_ARR_1_FORMAT_CONFIGURATION_TABLE";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_1_FORMAT_CONFIGURATION_TABLE].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_1_FORMAT_CONFIGURATION_TABLE].flags |= DNXC_DATA_F_TABLE;
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_1_FORMAT_CONFIGURATION_TABLE].size_of_values = sizeof(dnx_data_dnx2_arr_formats_ETPPB_ENC_2_ARR_1_FORMAT_CONFIGURATION_TABLE_t);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_1_FORMAT_CONFIGURATION_TABLE].entry_get = dnx_data_dnx2_arr_formats_ETPPB_ENC_2_ARR_1_FORMAT_CONFIGURATION_TABLE_entry_str_get;

        
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_1_FORMAT_CONFIGURATION_TABLE].nof_keys = 1;
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_1_FORMAT_CONFIGURATION_TABLE].keys[0].name = "index";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_1_FORMAT_CONFIGURATION_TABLE].keys[0].doc = "";

        
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_1_FORMAT_CONFIGURATION_TABLE].nof_values = 8;
        DNXC_DATA_ALLOC(submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_1_FORMAT_CONFIGURATION_TABLE].values, dnxc_data_value_t, submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_1_FORMAT_CONFIGURATION_TABLE].nof_values, "_dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_1_FORMAT_CONFIGURATION_TABLE table values");
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_1_FORMAT_CONFIGURATION_TABLE].values[0].name = "valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_1_FORMAT_CONFIGURATION_TABLE].values[0].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_1_FORMAT_CONFIGURATION_TABLE].values[0].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_1_FORMAT_CONFIGURATION_TABLE].values[0].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_2_ARR_1_FORMAT_CONFIGURATION_TABLE_t, valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_1_FORMAT_CONFIGURATION_TABLE].values[1].name = "doc";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_1_FORMAT_CONFIGURATION_TABLE].values[1].type = "char *";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_1_FORMAT_CONFIGURATION_TABLE].values[1].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_1_FORMAT_CONFIGURATION_TABLE].values[1].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_2_ARR_1_FORMAT_CONFIGURATION_TABLE_t, doc);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_1_FORMAT_CONFIGURATION_TABLE].values[2].name = "VLAN_MEMBERSHIP_INTERFACE_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_1_FORMAT_CONFIGURATION_TABLE].values[2].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_1_FORMAT_CONFIGURATION_TABLE].values[2].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_1_FORMAT_CONFIGURATION_TABLE].values[2].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_2_ARR_1_FORMAT_CONFIGURATION_TABLE_t, VLAN_MEMBERSHIP_INTERFACE_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_1_FORMAT_CONFIGURATION_TABLE].values[3].name = "VLAN_MEMBERSHIP_INTERFACE_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_1_FORMAT_CONFIGURATION_TABLE].values[3].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_1_FORMAT_CONFIGURATION_TABLE].values[3].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_1_FORMAT_CONFIGURATION_TABLE].values[3].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_2_ARR_1_FORMAT_CONFIGURATION_TABLE_t, VLAN_MEMBERSHIP_INTERFACE_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_1_FORMAT_CONFIGURATION_TABLE].values[4].name = "ENCAP_DESTINATION_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_1_FORMAT_CONFIGURATION_TABLE].values[4].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_1_FORMAT_CONFIGURATION_TABLE].values[4].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_1_FORMAT_CONFIGURATION_TABLE].values[4].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_2_ARR_1_FORMAT_CONFIGURATION_TABLE_t, ENCAP_DESTINATION_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_1_FORMAT_CONFIGURATION_TABLE].values[5].name = "ENCAP_DESTINATION_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_1_FORMAT_CONFIGURATION_TABLE].values[5].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_1_FORMAT_CONFIGURATION_TABLE].values[5].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_1_FORMAT_CONFIGURATION_TABLE].values[5].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_2_ARR_1_FORMAT_CONFIGURATION_TABLE_t, ENCAP_DESTINATION_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_1_FORMAT_CONFIGURATION_TABLE].values[6].name = "REMARK_PROFILE_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_1_FORMAT_CONFIGURATION_TABLE].values[6].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_1_FORMAT_CONFIGURATION_TABLE].values[6].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_1_FORMAT_CONFIGURATION_TABLE].values[6].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_2_ARR_1_FORMAT_CONFIGURATION_TABLE_t, REMARK_PROFILE_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_1_FORMAT_CONFIGURATION_TABLE].values[7].name = "REMARK_PROFILE_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_1_FORMAT_CONFIGURATION_TABLE].values[7].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_1_FORMAT_CONFIGURATION_TABLE].values[7].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_1_FORMAT_CONFIGURATION_TABLE].values[7].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_2_ARR_1_FORMAT_CONFIGURATION_TABLE_t, REMARK_PROFILE_CONFIG_valid);
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_1_FORMAT_CONFIGURATION_TABLE].name = "ETPPB_ENC_3_ARR_1_FORMAT_CONFIGURATION_TABLE";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_1_FORMAT_CONFIGURATION_TABLE].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_1_FORMAT_CONFIGURATION_TABLE].flags |= DNXC_DATA_F_TABLE;
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_1_FORMAT_CONFIGURATION_TABLE].size_of_values = sizeof(dnx_data_dnx2_arr_formats_ETPPB_ENC_3_ARR_1_FORMAT_CONFIGURATION_TABLE_t);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_1_FORMAT_CONFIGURATION_TABLE].entry_get = dnx_data_dnx2_arr_formats_ETPPB_ENC_3_ARR_1_FORMAT_CONFIGURATION_TABLE_entry_str_get;

        
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_1_FORMAT_CONFIGURATION_TABLE].nof_keys = 1;
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_1_FORMAT_CONFIGURATION_TABLE].keys[0].name = "index";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_1_FORMAT_CONFIGURATION_TABLE].keys[0].doc = "";

        
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_1_FORMAT_CONFIGURATION_TABLE].nof_values = 8;
        DNXC_DATA_ALLOC(submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_1_FORMAT_CONFIGURATION_TABLE].values, dnxc_data_value_t, submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_1_FORMAT_CONFIGURATION_TABLE].nof_values, "_dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_1_FORMAT_CONFIGURATION_TABLE table values");
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_1_FORMAT_CONFIGURATION_TABLE].values[0].name = "valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_1_FORMAT_CONFIGURATION_TABLE].values[0].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_1_FORMAT_CONFIGURATION_TABLE].values[0].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_1_FORMAT_CONFIGURATION_TABLE].values[0].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_3_ARR_1_FORMAT_CONFIGURATION_TABLE_t, valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_1_FORMAT_CONFIGURATION_TABLE].values[1].name = "doc";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_1_FORMAT_CONFIGURATION_TABLE].values[1].type = "char *";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_1_FORMAT_CONFIGURATION_TABLE].values[1].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_1_FORMAT_CONFIGURATION_TABLE].values[1].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_3_ARR_1_FORMAT_CONFIGURATION_TABLE_t, doc);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_1_FORMAT_CONFIGURATION_TABLE].values[2].name = "VLAN_MEMBERSHIP_INTERFACE_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_1_FORMAT_CONFIGURATION_TABLE].values[2].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_1_FORMAT_CONFIGURATION_TABLE].values[2].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_1_FORMAT_CONFIGURATION_TABLE].values[2].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_3_ARR_1_FORMAT_CONFIGURATION_TABLE_t, VLAN_MEMBERSHIP_INTERFACE_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_1_FORMAT_CONFIGURATION_TABLE].values[3].name = "VLAN_MEMBERSHIP_INTERFACE_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_1_FORMAT_CONFIGURATION_TABLE].values[3].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_1_FORMAT_CONFIGURATION_TABLE].values[3].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_1_FORMAT_CONFIGURATION_TABLE].values[3].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_3_ARR_1_FORMAT_CONFIGURATION_TABLE_t, VLAN_MEMBERSHIP_INTERFACE_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_1_FORMAT_CONFIGURATION_TABLE].values[4].name = "ENCAP_DESTINATION_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_1_FORMAT_CONFIGURATION_TABLE].values[4].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_1_FORMAT_CONFIGURATION_TABLE].values[4].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_1_FORMAT_CONFIGURATION_TABLE].values[4].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_3_ARR_1_FORMAT_CONFIGURATION_TABLE_t, ENCAP_DESTINATION_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_1_FORMAT_CONFIGURATION_TABLE].values[5].name = "ENCAP_DESTINATION_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_1_FORMAT_CONFIGURATION_TABLE].values[5].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_1_FORMAT_CONFIGURATION_TABLE].values[5].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_1_FORMAT_CONFIGURATION_TABLE].values[5].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_3_ARR_1_FORMAT_CONFIGURATION_TABLE_t, ENCAP_DESTINATION_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_1_FORMAT_CONFIGURATION_TABLE].values[6].name = "REMARK_PROFILE_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_1_FORMAT_CONFIGURATION_TABLE].values[6].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_1_FORMAT_CONFIGURATION_TABLE].values[6].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_1_FORMAT_CONFIGURATION_TABLE].values[6].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_3_ARR_1_FORMAT_CONFIGURATION_TABLE_t, REMARK_PROFILE_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_1_FORMAT_CONFIGURATION_TABLE].values[7].name = "REMARK_PROFILE_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_1_FORMAT_CONFIGURATION_TABLE].values[7].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_1_FORMAT_CONFIGURATION_TABLE].values[7].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_1_FORMAT_CONFIGURATION_TABLE].values[7].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_3_ARR_1_FORMAT_CONFIGURATION_TABLE_t, REMARK_PROFILE_CONFIG_valid);
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_1_FORMAT_CONFIGURATION_TABLE].name = "ETPPB_ENC_4_ARR_1_FORMAT_CONFIGURATION_TABLE";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_1_FORMAT_CONFIGURATION_TABLE].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_1_FORMAT_CONFIGURATION_TABLE].flags |= DNXC_DATA_F_TABLE;
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_1_FORMAT_CONFIGURATION_TABLE].size_of_values = sizeof(dnx_data_dnx2_arr_formats_ETPPB_ENC_4_ARR_1_FORMAT_CONFIGURATION_TABLE_t);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_1_FORMAT_CONFIGURATION_TABLE].entry_get = dnx_data_dnx2_arr_formats_ETPPB_ENC_4_ARR_1_FORMAT_CONFIGURATION_TABLE_entry_str_get;

        
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_1_FORMAT_CONFIGURATION_TABLE].nof_keys = 1;
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_1_FORMAT_CONFIGURATION_TABLE].keys[0].name = "index";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_1_FORMAT_CONFIGURATION_TABLE].keys[0].doc = "";

        
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_1_FORMAT_CONFIGURATION_TABLE].nof_values = 8;
        DNXC_DATA_ALLOC(submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_1_FORMAT_CONFIGURATION_TABLE].values, dnxc_data_value_t, submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_1_FORMAT_CONFIGURATION_TABLE].nof_values, "_dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_1_FORMAT_CONFIGURATION_TABLE table values");
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_1_FORMAT_CONFIGURATION_TABLE].values[0].name = "valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_1_FORMAT_CONFIGURATION_TABLE].values[0].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_1_FORMAT_CONFIGURATION_TABLE].values[0].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_1_FORMAT_CONFIGURATION_TABLE].values[0].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_4_ARR_1_FORMAT_CONFIGURATION_TABLE_t, valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_1_FORMAT_CONFIGURATION_TABLE].values[1].name = "doc";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_1_FORMAT_CONFIGURATION_TABLE].values[1].type = "char *";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_1_FORMAT_CONFIGURATION_TABLE].values[1].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_1_FORMAT_CONFIGURATION_TABLE].values[1].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_4_ARR_1_FORMAT_CONFIGURATION_TABLE_t, doc);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_1_FORMAT_CONFIGURATION_TABLE].values[2].name = "VLAN_MEMBERSHIP_INTERFACE_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_1_FORMAT_CONFIGURATION_TABLE].values[2].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_1_FORMAT_CONFIGURATION_TABLE].values[2].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_1_FORMAT_CONFIGURATION_TABLE].values[2].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_4_ARR_1_FORMAT_CONFIGURATION_TABLE_t, VLAN_MEMBERSHIP_INTERFACE_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_1_FORMAT_CONFIGURATION_TABLE].values[3].name = "VLAN_MEMBERSHIP_INTERFACE_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_1_FORMAT_CONFIGURATION_TABLE].values[3].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_1_FORMAT_CONFIGURATION_TABLE].values[3].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_1_FORMAT_CONFIGURATION_TABLE].values[3].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_4_ARR_1_FORMAT_CONFIGURATION_TABLE_t, VLAN_MEMBERSHIP_INTERFACE_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_1_FORMAT_CONFIGURATION_TABLE].values[4].name = "ENCAP_DESTINATION_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_1_FORMAT_CONFIGURATION_TABLE].values[4].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_1_FORMAT_CONFIGURATION_TABLE].values[4].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_1_FORMAT_CONFIGURATION_TABLE].values[4].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_4_ARR_1_FORMAT_CONFIGURATION_TABLE_t, ENCAP_DESTINATION_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_1_FORMAT_CONFIGURATION_TABLE].values[5].name = "ENCAP_DESTINATION_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_1_FORMAT_CONFIGURATION_TABLE].values[5].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_1_FORMAT_CONFIGURATION_TABLE].values[5].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_1_FORMAT_CONFIGURATION_TABLE].values[5].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_4_ARR_1_FORMAT_CONFIGURATION_TABLE_t, ENCAP_DESTINATION_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_1_FORMAT_CONFIGURATION_TABLE].values[6].name = "REMARK_PROFILE_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_1_FORMAT_CONFIGURATION_TABLE].values[6].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_1_FORMAT_CONFIGURATION_TABLE].values[6].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_1_FORMAT_CONFIGURATION_TABLE].values[6].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_4_ARR_1_FORMAT_CONFIGURATION_TABLE_t, REMARK_PROFILE_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_1_FORMAT_CONFIGURATION_TABLE].values[7].name = "REMARK_PROFILE_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_1_FORMAT_CONFIGURATION_TABLE].values[7].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_1_FORMAT_CONFIGURATION_TABLE].values[7].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_1_FORMAT_CONFIGURATION_TABLE].values[7].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_4_ARR_1_FORMAT_CONFIGURATION_TABLE_t, REMARK_PROFILE_CONFIG_valid);
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_1_FORMAT_CONFIGURATION_TABLE].name = "ETPPB_ENC_5_ARR_1_FORMAT_CONFIGURATION_TABLE";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_1_FORMAT_CONFIGURATION_TABLE].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_1_FORMAT_CONFIGURATION_TABLE].flags |= DNXC_DATA_F_TABLE;
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_1_FORMAT_CONFIGURATION_TABLE].size_of_values = sizeof(dnx_data_dnx2_arr_formats_ETPPB_ENC_5_ARR_1_FORMAT_CONFIGURATION_TABLE_t);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_1_FORMAT_CONFIGURATION_TABLE].entry_get = dnx_data_dnx2_arr_formats_ETPPB_ENC_5_ARR_1_FORMAT_CONFIGURATION_TABLE_entry_str_get;

        
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_1_FORMAT_CONFIGURATION_TABLE].nof_keys = 1;
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_1_FORMAT_CONFIGURATION_TABLE].keys[0].name = "index";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_1_FORMAT_CONFIGURATION_TABLE].keys[0].doc = "";

        
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_1_FORMAT_CONFIGURATION_TABLE].nof_values = 8;
        DNXC_DATA_ALLOC(submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_1_FORMAT_CONFIGURATION_TABLE].values, dnxc_data_value_t, submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_1_FORMAT_CONFIGURATION_TABLE].nof_values, "_dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_1_FORMAT_CONFIGURATION_TABLE table values");
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_1_FORMAT_CONFIGURATION_TABLE].values[0].name = "valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_1_FORMAT_CONFIGURATION_TABLE].values[0].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_1_FORMAT_CONFIGURATION_TABLE].values[0].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_1_FORMAT_CONFIGURATION_TABLE].values[0].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_5_ARR_1_FORMAT_CONFIGURATION_TABLE_t, valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_1_FORMAT_CONFIGURATION_TABLE].values[1].name = "doc";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_1_FORMAT_CONFIGURATION_TABLE].values[1].type = "char *";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_1_FORMAT_CONFIGURATION_TABLE].values[1].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_1_FORMAT_CONFIGURATION_TABLE].values[1].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_5_ARR_1_FORMAT_CONFIGURATION_TABLE_t, doc);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_1_FORMAT_CONFIGURATION_TABLE].values[2].name = "VLAN_MEMBERSHIP_INTERFACE_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_1_FORMAT_CONFIGURATION_TABLE].values[2].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_1_FORMAT_CONFIGURATION_TABLE].values[2].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_1_FORMAT_CONFIGURATION_TABLE].values[2].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_5_ARR_1_FORMAT_CONFIGURATION_TABLE_t, VLAN_MEMBERSHIP_INTERFACE_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_1_FORMAT_CONFIGURATION_TABLE].values[3].name = "VLAN_MEMBERSHIP_INTERFACE_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_1_FORMAT_CONFIGURATION_TABLE].values[3].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_1_FORMAT_CONFIGURATION_TABLE].values[3].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_1_FORMAT_CONFIGURATION_TABLE].values[3].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_5_ARR_1_FORMAT_CONFIGURATION_TABLE_t, VLAN_MEMBERSHIP_INTERFACE_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_1_FORMAT_CONFIGURATION_TABLE].values[4].name = "ENCAP_DESTINATION_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_1_FORMAT_CONFIGURATION_TABLE].values[4].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_1_FORMAT_CONFIGURATION_TABLE].values[4].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_1_FORMAT_CONFIGURATION_TABLE].values[4].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_5_ARR_1_FORMAT_CONFIGURATION_TABLE_t, ENCAP_DESTINATION_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_1_FORMAT_CONFIGURATION_TABLE].values[5].name = "ENCAP_DESTINATION_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_1_FORMAT_CONFIGURATION_TABLE].values[5].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_1_FORMAT_CONFIGURATION_TABLE].values[5].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_1_FORMAT_CONFIGURATION_TABLE].values[5].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_5_ARR_1_FORMAT_CONFIGURATION_TABLE_t, ENCAP_DESTINATION_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_1_FORMAT_CONFIGURATION_TABLE].values[6].name = "REMARK_PROFILE_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_1_FORMAT_CONFIGURATION_TABLE].values[6].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_1_FORMAT_CONFIGURATION_TABLE].values[6].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_1_FORMAT_CONFIGURATION_TABLE].values[6].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_5_ARR_1_FORMAT_CONFIGURATION_TABLE_t, REMARK_PROFILE_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_1_FORMAT_CONFIGURATION_TABLE].values[7].name = "REMARK_PROFILE_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_1_FORMAT_CONFIGURATION_TABLE].values[7].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_1_FORMAT_CONFIGURATION_TABLE].values[7].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_1_FORMAT_CONFIGURATION_TABLE].values[7].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPB_ENC_5_ARR_1_FORMAT_CONFIGURATION_TABLE_t, REMARK_PROFILE_CONFIG_valid);
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_1_FORMAT_CONFIGURATION_TABLE].name = "ETPPC_ENC_1_ARR_1_FORMAT_CONFIGURATION_TABLE";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_1_FORMAT_CONFIGURATION_TABLE].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_1_FORMAT_CONFIGURATION_TABLE].flags |= DNXC_DATA_F_TABLE;
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_1_FORMAT_CONFIGURATION_TABLE].size_of_values = sizeof(dnx_data_dnx2_arr_formats_ETPPC_ENC_1_ARR_1_FORMAT_CONFIGURATION_TABLE_t);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_1_FORMAT_CONFIGURATION_TABLE].entry_get = dnx_data_dnx2_arr_formats_ETPPC_ENC_1_ARR_1_FORMAT_CONFIGURATION_TABLE_entry_str_get;

        
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_1_FORMAT_CONFIGURATION_TABLE].nof_keys = 1;
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_1_FORMAT_CONFIGURATION_TABLE].keys[0].name = "index";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_1_FORMAT_CONFIGURATION_TABLE].keys[0].doc = "";

        
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_1_FORMAT_CONFIGURATION_TABLE].nof_values = 8;
        DNXC_DATA_ALLOC(submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_1_FORMAT_CONFIGURATION_TABLE].values, dnxc_data_value_t, submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_1_FORMAT_CONFIGURATION_TABLE].nof_values, "_dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_1_FORMAT_CONFIGURATION_TABLE table values");
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_1_FORMAT_CONFIGURATION_TABLE].values[0].name = "valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_1_FORMAT_CONFIGURATION_TABLE].values[0].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_1_FORMAT_CONFIGURATION_TABLE].values[0].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_1_FORMAT_CONFIGURATION_TABLE].values[0].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPC_ENC_1_ARR_1_FORMAT_CONFIGURATION_TABLE_t, valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_1_FORMAT_CONFIGURATION_TABLE].values[1].name = "doc";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_1_FORMAT_CONFIGURATION_TABLE].values[1].type = "char *";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_1_FORMAT_CONFIGURATION_TABLE].values[1].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_1_FORMAT_CONFIGURATION_TABLE].values[1].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPC_ENC_1_ARR_1_FORMAT_CONFIGURATION_TABLE_t, doc);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_1_FORMAT_CONFIGURATION_TABLE].values[2].name = "VLAN_MEMBERSHIP_INTERFACE_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_1_FORMAT_CONFIGURATION_TABLE].values[2].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_1_FORMAT_CONFIGURATION_TABLE].values[2].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_1_FORMAT_CONFIGURATION_TABLE].values[2].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPC_ENC_1_ARR_1_FORMAT_CONFIGURATION_TABLE_t, VLAN_MEMBERSHIP_INTERFACE_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_1_FORMAT_CONFIGURATION_TABLE].values[3].name = "VLAN_MEMBERSHIP_INTERFACE_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_1_FORMAT_CONFIGURATION_TABLE].values[3].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_1_FORMAT_CONFIGURATION_TABLE].values[3].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_1_FORMAT_CONFIGURATION_TABLE].values[3].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPC_ENC_1_ARR_1_FORMAT_CONFIGURATION_TABLE_t, VLAN_MEMBERSHIP_INTERFACE_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_1_FORMAT_CONFIGURATION_TABLE].values[4].name = "ENCAP_DESTINATION_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_1_FORMAT_CONFIGURATION_TABLE].values[4].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_1_FORMAT_CONFIGURATION_TABLE].values[4].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_1_FORMAT_CONFIGURATION_TABLE].values[4].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPC_ENC_1_ARR_1_FORMAT_CONFIGURATION_TABLE_t, ENCAP_DESTINATION_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_1_FORMAT_CONFIGURATION_TABLE].values[5].name = "ENCAP_DESTINATION_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_1_FORMAT_CONFIGURATION_TABLE].values[5].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_1_FORMAT_CONFIGURATION_TABLE].values[5].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_1_FORMAT_CONFIGURATION_TABLE].values[5].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPC_ENC_1_ARR_1_FORMAT_CONFIGURATION_TABLE_t, ENCAP_DESTINATION_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_1_FORMAT_CONFIGURATION_TABLE].values[6].name = "REMARK_PROFILE_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_1_FORMAT_CONFIGURATION_TABLE].values[6].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_1_FORMAT_CONFIGURATION_TABLE].values[6].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_1_FORMAT_CONFIGURATION_TABLE].values[6].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPC_ENC_1_ARR_1_FORMAT_CONFIGURATION_TABLE_t, REMARK_PROFILE_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_1_FORMAT_CONFIGURATION_TABLE].values[7].name = "REMARK_PROFILE_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_1_FORMAT_CONFIGURATION_TABLE].values[7].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_1_FORMAT_CONFIGURATION_TABLE].values[7].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_1_FORMAT_CONFIGURATION_TABLE].values[7].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPC_ENC_1_ARR_1_FORMAT_CONFIGURATION_TABLE_t, REMARK_PROFILE_CONFIG_valid);
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0].name = "ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0].flags |= DNXC_DATA_F_TABLE;
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0].size_of_values = sizeof(dnx_data_dnx2_arr_formats_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0_t);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0].entry_get = dnx_data_dnx2_arr_formats_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0_entry_str_get;

        
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0].nof_keys = 1;
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0].keys[0].name = "index";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0].keys[0].doc = "";

        
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0].nof_values = 28;
        DNXC_DATA_ALLOC(submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0].values, dnxc_data_value_t, submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0].nof_values, "_dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0 table values");
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0].values[0].name = "valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0].values[0].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0].values[0].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0].values[0].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0_t, valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0].values[1].name = "doc";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0].values[1].type = "char *";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0].values[1].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0].values[1].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0_t, doc);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0].values[2].name = "ETHERNET_EGRESS_LAST_LAYER_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0].values[2].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0].values[2].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0].values[2].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0_t, ETHERNET_EGRESS_LAST_LAYER_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0].values[3].name = "ETHERNET_EGRESS_LAST_LAYER_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0].values[3].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0].values[3].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0].values[3].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0_t, ETHERNET_EGRESS_LAST_LAYER_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0].values[4].name = "ETHERNET_EGRESS_VLAN_MEMBERSHIP_INTERFACE_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0].values[4].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0].values[4].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0].values[4].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0_t, ETHERNET_EGRESS_VLAN_MEMBERSHIP_INTERFACE_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0].values[5].name = "ETHERNET_EGRESS_VLAN_MEMBERSHIP_INTERFACE_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0].values[5].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0].values[5].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0].values[5].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0_t, ETHERNET_EGRESS_VLAN_MEMBERSHIP_INTERFACE_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0].values[6].name = "ENCAP_DESTINATION_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0].values[6].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0].values[6].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0].values[6].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0_t, ENCAP_DESTINATION_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0].values[7].name = "ENCAP_DESTINATION_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0].values[7].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0].values[7].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0].values[7].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0_t, ENCAP_DESTINATION_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0].values[8].name = "FORWARDING_DOMAIN_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0].values[8].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0].values[8].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0].values[8].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0_t, FORWARDING_DOMAIN_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0].values[9].name = "FORWARDING_DOMAIN_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0].values[9].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0].values[9].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0].values[9].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0_t, FORWARDING_DOMAIN_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0].values[10].name = "QOS_MODEL_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0].values[10].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0].values[10].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0].values[10].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0_t, QOS_MODEL_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0].values[11].name = "QOS_MODEL_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0].values[11].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0].values[11].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0].values[11].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0_t, QOS_MODEL_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0].values[12].name = "MTU_PROFILE_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0].values[12].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0].values[12].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0].values[12].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0_t, MTU_PROFILE_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0].values[13].name = "MTU_PROFILE_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0].values[13].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0].values[13].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0].values[13].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0_t, MTU_PROFILE_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0].values[14].name = "NWK_QOS_INDEX_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0].values[14].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0].values[14].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0].values[14].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0_t, NWK_QOS_INDEX_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0].values[15].name = "NWK_QOS_INDEX_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0].values[15].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0].values[15].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0].values[15].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0_t, NWK_QOS_INDEX_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0].values[16].name = "ETHERNET_OUTLIF_PROFILE_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0].values[16].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0].values[16].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0].values[16].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0_t, ETHERNET_OUTLIF_PROFILE_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0].values[17].name = "ETHERNET_OUTLIF_PROFILE_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0].values[17].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0].values[17].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0].values[17].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0_t, ETHERNET_OUTLIF_PROFILE_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0].values[18].name = "REMARK_PROFILE_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0].values[18].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0].values[18].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0].values[18].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0_t, REMARK_PROFILE_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0].values[19].name = "REMARK_PROFILE_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0].values[19].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0].values[19].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0].values[19].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0_t, REMARK_PROFILE_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0].values[20].name = "LIF_STATISTICS_OBJECT_COMMAND_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0].values[20].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0].values[20].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0].values[20].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0_t, LIF_STATISTICS_OBJECT_COMMAND_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0].values[21].name = "LIF_STATISTICS_OBJECT_COMMAND_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0].values[21].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0].values[21].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0].values[21].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0_t, LIF_STATISTICS_OBJECT_COMMAND_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0].values[22].name = "LIF_STATISTICS_OBJECT_ID_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0].values[22].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0].values[22].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0].values[22].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0_t, LIF_STATISTICS_OBJECT_ID_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0].values[23].name = "LIF_STATISTICS_OBJECT_ID_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0].values[23].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0].values[23].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0].values[23].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0_t, LIF_STATISTICS_OBJECT_ID_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0].values[24].name = "TTL_MODEL_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0].values[24].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0].values[24].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0].values[24].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0_t, TTL_MODEL_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0].values[25].name = "TTL_MODEL_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0].values[25].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0].values[25].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0].values[25].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0_t, TTL_MODEL_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0].values[26].name = "ETHERNET_EGRESS_VLAN_EDIT_PROFILE_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0].values[26].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0].values[26].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0].values[26].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0_t, ETHERNET_EGRESS_VLAN_EDIT_PROFILE_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0].values[27].name = "ETHERNET_EGRESS_VLAN_EDIT_PROFILE_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0].values[27].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0].values[27].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0].values[27].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0_t, ETHERNET_EGRESS_VLAN_EDIT_PROFILE_CONFIG_valid);
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_1].name = "ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_1";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_1].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_1].flags |= DNXC_DATA_F_TABLE;
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_1].size_of_values = sizeof(dnx_data_dnx2_arr_formats_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_1_t);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_1].entry_get = dnx_data_dnx2_arr_formats_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_1_entry_str_get;

        
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_1].nof_keys = 1;
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_1].keys[0].name = "index";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_1].keys[0].doc = "";

        
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_1].nof_values = 8;
        DNXC_DATA_ALLOC(submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_1].values, dnxc_data_value_t, submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_1].nof_values, "_dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_1 table values");
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_1].values[0].name = "valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_1].values[0].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_1].values[0].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_1].values[0].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_1_t, valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_1].values[1].name = "doc";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_1].values[1].type = "char *";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_1].values[1].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_1].values[1].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_1_t, doc);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_1].values[2].name = "ETHERNET_EGRESS_VLAN_MEMBERSHIP_INTERFACE_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_1].values[2].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_1].values[2].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_1].values[2].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_1_t, ETHERNET_EGRESS_VLAN_MEMBERSHIP_INTERFACE_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_1].values[3].name = "ETHERNET_EGRESS_VLAN_MEMBERSHIP_INTERFACE_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_1].values[3].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_1].values[3].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_1].values[3].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_1_t, ETHERNET_EGRESS_VLAN_MEMBERSHIP_INTERFACE_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_1].values[4].name = "ENCAP_DESTINATION_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_1].values[4].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_1].values[4].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_1].values[4].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_1_t, ENCAP_DESTINATION_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_1].values[5].name = "ENCAP_DESTINATION_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_1].values[5].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_1].values[5].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_1].values[5].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_1_t, ENCAP_DESTINATION_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_1].values[6].name = "REMARK_PROFILE_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_1].values[6].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_1].values[6].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_1].values[6].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_1_t, REMARK_PROFILE_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_1].values[7].name = "REMARK_PROFILE_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_1].values[7].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_1].values[7].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_1].values[7].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_1_t, REMARK_PROFILE_CONFIG_valid);
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION].name = "ETPPA_PRP_EES_ARR_CONFIGURATION";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION].flags |= DNXC_DATA_F_TABLE;
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION].size_of_values = sizeof(dnx_data_dnx2_arr_formats_ETPPA_PRP_EES_ARR_CONFIGURATION_t);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION].entry_get = dnx_data_dnx2_arr_formats_ETPPA_PRP_EES_ARR_CONFIGURATION_entry_str_get;

        
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION].nof_keys = 1;
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION].keys[0].name = "index";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION].keys[0].doc = "";

        
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION].nof_values = 14;
        DNXC_DATA_ALLOC(submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION].values, dnxc_data_value_t, submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION].nof_values, "_dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION table values");
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION].values[0].name = "valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION].values[0].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION].values[0].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION].values[0].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPA_PRP_EES_ARR_CONFIGURATION_t, valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION].values[1].name = "doc";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION].values[1].type = "char *";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION].values[1].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION].values[1].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPA_PRP_EES_ARR_CONFIGURATION_t, doc);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION].values[2].name = "LLVP_PROFILE_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION].values[2].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION].values[2].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION].values[2].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPA_PRP_EES_ARR_CONFIGURATION_t, LLVP_PROFILE_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION].values[3].name = "LLVP_PROFILE_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION].values[3].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION].values[3].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION].values[3].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPA_PRP_EES_ARR_CONFIGURATION_t, LLVP_PROFILE_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION].values[4].name = "EM_ACCESS_CMD_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION].values[4].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION].values[4].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION].values[4].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPA_PRP_EES_ARR_CONFIGURATION_t, EM_ACCESS_CMD_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION].values[5].name = "EM_ACCESS_CMD_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION].values[5].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION].values[5].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION].values[5].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPA_PRP_EES_ARR_CONFIGURATION_t, EM_ACCESS_CMD_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION].values[6].name = "NAME_SPACE_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION].values[6].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION].values[6].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION].values[6].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPA_PRP_EES_ARR_CONFIGURATION_t, NAME_SPACE_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION].values[7].name = "NAME_SPACE_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION].values[7].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION].values[7].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION].values[7].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPA_PRP_EES_ARR_CONFIGURATION_t, NAME_SPACE_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION].values[8].name = "FWD_DOMAIN_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION].values[8].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION].values[8].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION].values[8].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPA_PRP_EES_ARR_CONFIGURATION_t, FWD_DOMAIN_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION].values[9].name = "FWD_DOMAIN_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION].values[9].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION].values[9].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION].values[9].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPA_PRP_EES_ARR_CONFIGURATION_t, FWD_DOMAIN_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION].values[10].name = "OAM_LIF_SET_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION].values[10].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION].values[10].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION].values[10].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPA_PRP_EES_ARR_CONFIGURATION_t, OAM_LIF_SET_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION].values[11].name = "OAM_LIF_SET_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION].values[11].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION].values[11].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION].values[11].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPA_PRP_EES_ARR_CONFIGURATION_t, OAM_LIF_SET_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION].values[12].name = "OUTLIF_PROFILE_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION].values[12].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION].values[12].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION].values[12].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPA_PRP_EES_ARR_CONFIGURATION_t, OUTLIF_PROFILE_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION].values[13].name = "OUTLIF_PROFILE_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION].values[13].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION].values[13].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION].values[13].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPA_PRP_EES_ARR_CONFIGURATION_t, OUTLIF_PROFILE_CONFIG_valid);
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION___array].name = "ETPPA_PRP_EES_ARR_CONFIGURATION___array";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION___array].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION___array].flags |= DNXC_DATA_F_TABLE;
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION___array].size_of_values = sizeof(dnx_data_dnx2_arr_formats_ETPPA_PRP_EES_ARR_CONFIGURATION___array_t);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION___array].entry_get = dnx_data_dnx2_arr_formats_ETPPA_PRP_EES_ARR_CONFIGURATION___array_entry_str_get;

        
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION___array].nof_keys = 2;
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION___array].keys[0].name = "table_index";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION___array].keys[0].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION___array].keys[1].name = "index";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION___array].keys[1].doc = "";

        
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION___array].nof_values = 14;
        DNXC_DATA_ALLOC(submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION___array].values, dnxc_data_value_t, submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION___array].nof_values, "_dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION___array table values");
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION___array].values[0].name = "valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION___array].values[0].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION___array].values[0].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION___array].values[0].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPA_PRP_EES_ARR_CONFIGURATION___array_t, valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION___array].values[1].name = "doc";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION___array].values[1].type = "char *";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION___array].values[1].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION___array].values[1].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPA_PRP_EES_ARR_CONFIGURATION___array_t, doc);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION___array].values[2].name = "LLVP_PROFILE_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION___array].values[2].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION___array].values[2].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION___array].values[2].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPA_PRP_EES_ARR_CONFIGURATION___array_t, LLVP_PROFILE_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION___array].values[3].name = "LLVP_PROFILE_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION___array].values[3].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION___array].values[3].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION___array].values[3].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPA_PRP_EES_ARR_CONFIGURATION___array_t, LLVP_PROFILE_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION___array].values[4].name = "EM_ACCESS_CMD_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION___array].values[4].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION___array].values[4].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION___array].values[4].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPA_PRP_EES_ARR_CONFIGURATION___array_t, EM_ACCESS_CMD_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION___array].values[5].name = "EM_ACCESS_CMD_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION___array].values[5].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION___array].values[5].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION___array].values[5].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPA_PRP_EES_ARR_CONFIGURATION___array_t, EM_ACCESS_CMD_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION___array].values[6].name = "NAME_SPACE_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION___array].values[6].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION___array].values[6].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION___array].values[6].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPA_PRP_EES_ARR_CONFIGURATION___array_t, NAME_SPACE_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION___array].values[7].name = "NAME_SPACE_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION___array].values[7].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION___array].values[7].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION___array].values[7].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPA_PRP_EES_ARR_CONFIGURATION___array_t, NAME_SPACE_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION___array].values[8].name = "FWD_DOMAIN_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION___array].values[8].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION___array].values[8].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION___array].values[8].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPA_PRP_EES_ARR_CONFIGURATION___array_t, FWD_DOMAIN_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION___array].values[9].name = "FWD_DOMAIN_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION___array].values[9].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION___array].values[9].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION___array].values[9].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPA_PRP_EES_ARR_CONFIGURATION___array_t, FWD_DOMAIN_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION___array].values[10].name = "OAM_LIF_SET_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION___array].values[10].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION___array].values[10].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION___array].values[10].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPA_PRP_EES_ARR_CONFIGURATION___array_t, OAM_LIF_SET_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION___array].values[11].name = "OAM_LIF_SET_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION___array].values[11].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION___array].values[11].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION___array].values[11].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPA_PRP_EES_ARR_CONFIGURATION___array_t, OAM_LIF_SET_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION___array].values[12].name = "OUTLIF_PROFILE_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION___array].values[12].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION___array].values[12].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION___array].values[12].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPA_PRP_EES_ARR_CONFIGURATION___array_t, OUTLIF_PROFILE_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION___array].values[13].name = "OUTLIF_PROFILE_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION___array].values[13].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION___array].values[13].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION___array].values[13].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPA_PRP_EES_ARR_CONFIGURATION___array_t, OUTLIF_PROFILE_CONFIG_valid);
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION].name = "ETPPC_TERM_ETPS_ARR_1_CONFIGURATION";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION].flags |= DNXC_DATA_F_TABLE;
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION].size_of_values = sizeof(dnx_data_dnx2_arr_formats_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION_t);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION].entry_get = dnx_data_dnx2_arr_formats_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION_entry_str_get;

        
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION].nof_keys = 1;
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION].keys[0].name = "index";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION].keys[0].doc = "";

        
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION].nof_values = 12;
        DNXC_DATA_ALLOC(submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION].values, dnxc_data_value_t, submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION].nof_values, "_dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION table values");
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION].values[0].name = "valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION].values[0].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION].values[0].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION].values[0].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION_t, valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION].values[1].name = "doc";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION].values[1].type = "char *";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION].values[1].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION].values[1].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION_t, doc);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION].values[2].name = "ACTION_PROFILE_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION].values[2].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION].values[2].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION].values[2].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION_t, ACTION_PROFILE_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION].values[3].name = "ACTION_PROFILE_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION].values[3].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION].values[3].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION].values[3].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION_t, ACTION_PROFILE_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION].values[4].name = "PROTECTION_PATH_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION].values[4].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION].values[4].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION].values[4].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION_t, PROTECTION_PATH_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION].values[5].name = "PROTECTION_PATH_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION].values[5].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION].values[5].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION].values[5].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION_t, PROTECTION_PATH_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION].values[6].name = "PROTECTION_PTR_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION].values[6].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION].values[6].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION].values[6].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION_t, PROTECTION_PTR_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION].values[7].name = "PROTECTION_PTR_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION].values[7].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION].values[7].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION].values[7].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION_t, PROTECTION_PTR_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION].values[8].name = "STAT_OBJ_CMD_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION].values[8].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION].values[8].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION].values[8].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION_t, STAT_OBJ_CMD_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION].values[9].name = "STAT_OBJ_CMD_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION].values[9].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION].values[9].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION].values[9].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION_t, STAT_OBJ_CMD_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION].values[10].name = "STAT_OBJ_ID_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION].values[10].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION].values[10].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION].values[10].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION_t, STAT_OBJ_ID_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION].values[11].name = "STAT_OBJ_ID_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION].values[11].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION].values[11].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION].values[11].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION_t, STAT_OBJ_ID_CONFIG_valid);
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION___array].name = "ETPPC_TERM_ETPS_ARR_1_CONFIGURATION___array";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION___array].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION___array].flags |= DNXC_DATA_F_TABLE;
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION___array].size_of_values = sizeof(dnx_data_dnx2_arr_formats_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION___array_t);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION___array].entry_get = dnx_data_dnx2_arr_formats_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION___array_entry_str_get;

        
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION___array].nof_keys = 2;
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION___array].keys[0].name = "table_index";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION___array].keys[0].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION___array].keys[1].name = "index";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION___array].keys[1].doc = "";

        
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION___array].nof_values = 12;
        DNXC_DATA_ALLOC(submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION___array].values, dnxc_data_value_t, submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION___array].nof_values, "_dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION___array table values");
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION___array].values[0].name = "valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION___array].values[0].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION___array].values[0].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION___array].values[0].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION___array_t, valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION___array].values[1].name = "doc";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION___array].values[1].type = "char *";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION___array].values[1].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION___array].values[1].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION___array_t, doc);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION___array].values[2].name = "ACTION_PROFILE_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION___array].values[2].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION___array].values[2].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION___array].values[2].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION___array_t, ACTION_PROFILE_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION___array].values[3].name = "ACTION_PROFILE_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION___array].values[3].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION___array].values[3].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION___array].values[3].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION___array_t, ACTION_PROFILE_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION___array].values[4].name = "PROTECTION_PATH_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION___array].values[4].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION___array].values[4].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION___array].values[4].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION___array_t, PROTECTION_PATH_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION___array].values[5].name = "PROTECTION_PATH_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION___array].values[5].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION___array].values[5].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION___array].values[5].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION___array_t, PROTECTION_PATH_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION___array].values[6].name = "PROTECTION_PTR_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION___array].values[6].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION___array].values[6].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION___array].values[6].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION___array_t, PROTECTION_PTR_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION___array].values[7].name = "PROTECTION_PTR_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION___array].values[7].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION___array].values[7].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION___array].values[7].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION___array_t, PROTECTION_PTR_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION___array].values[8].name = "STAT_OBJ_CMD_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION___array].values[8].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION___array].values[8].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION___array].values[8].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION___array_t, STAT_OBJ_CMD_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION___array].values[9].name = "STAT_OBJ_CMD_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION___array].values[9].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION___array].values[9].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION___array].values[9].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION___array_t, STAT_OBJ_CMD_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION___array].values[10].name = "STAT_OBJ_ID_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION___array].values[10].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION___array].values[10].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION___array].values[10].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION___array_t, STAT_OBJ_ID_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION___array].values[11].name = "STAT_OBJ_ID_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION___array].values[11].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION___array].values[11].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION___array].values[11].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION___array_t, STAT_OBJ_ID_CONFIG_valid);
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_2_CONFIGURATION].name = "ETPPC_TERM_ETPS_ARR_2_CONFIGURATION";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_2_CONFIGURATION].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_2_CONFIGURATION].flags |= DNXC_DATA_F_TABLE;
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_2_CONFIGURATION].size_of_values = sizeof(dnx_data_dnx2_arr_formats_ETPPC_TERM_ETPS_ARR_2_CONFIGURATION_t);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_2_CONFIGURATION].entry_get = dnx_data_dnx2_arr_formats_ETPPC_TERM_ETPS_ARR_2_CONFIGURATION_entry_str_get;

        
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_2_CONFIGURATION].nof_keys = 1;
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_2_CONFIGURATION].keys[0].name = "index";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_2_CONFIGURATION].keys[0].doc = "";

        
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_2_CONFIGURATION].nof_values = 12;
        DNXC_DATA_ALLOC(submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_2_CONFIGURATION].values, dnxc_data_value_t, submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_2_CONFIGURATION].nof_values, "_dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_2_CONFIGURATION table values");
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_2_CONFIGURATION].values[0].name = "valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_2_CONFIGURATION].values[0].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_2_CONFIGURATION].values[0].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_2_CONFIGURATION].values[0].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPC_TERM_ETPS_ARR_2_CONFIGURATION_t, valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_2_CONFIGURATION].values[1].name = "doc";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_2_CONFIGURATION].values[1].type = "char *";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_2_CONFIGURATION].values[1].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_2_CONFIGURATION].values[1].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPC_TERM_ETPS_ARR_2_CONFIGURATION_t, doc);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_2_CONFIGURATION].values[2].name = "QOS_MODEL_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_2_CONFIGURATION].values[2].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_2_CONFIGURATION].values[2].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_2_CONFIGURATION].values[2].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPC_TERM_ETPS_ARR_2_CONFIGURATION_t, QOS_MODEL_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_2_CONFIGURATION].values[3].name = "QOS_MODEL_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_2_CONFIGURATION].values[3].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_2_CONFIGURATION].values[3].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_2_CONFIGURATION].values[3].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPC_TERM_ETPS_ARR_2_CONFIGURATION_t, QOS_MODEL_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_2_CONFIGURATION].values[4].name = "NWK_QOS_IDX_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_2_CONFIGURATION].values[4].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_2_CONFIGURATION].values[4].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_2_CONFIGURATION].values[4].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPC_TERM_ETPS_ARR_2_CONFIGURATION_t, NWK_QOS_IDX_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_2_CONFIGURATION].values[5].name = "NWK_QOS_IDX_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_2_CONFIGURATION].values[5].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_2_CONFIGURATION].values[5].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_2_CONFIGURATION].values[5].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPC_TERM_ETPS_ARR_2_CONFIGURATION_t, NWK_QOS_IDX_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_2_CONFIGURATION].values[6].name = "OUTLIF_PROFILE_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_2_CONFIGURATION].values[6].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_2_CONFIGURATION].values[6].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_2_CONFIGURATION].values[6].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPC_TERM_ETPS_ARR_2_CONFIGURATION_t, OUTLIF_PROFILE_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_2_CONFIGURATION].values[7].name = "OUTLIF_PROFILE_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_2_CONFIGURATION].values[7].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_2_CONFIGURATION].values[7].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_2_CONFIGURATION].values[7].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPC_TERM_ETPS_ARR_2_CONFIGURATION_t, OUTLIF_PROFILE_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_2_CONFIGURATION].values[8].name = "REMARK_PROFILE_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_2_CONFIGURATION].values[8].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_2_CONFIGURATION].values[8].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_2_CONFIGURATION].values[8].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPC_TERM_ETPS_ARR_2_CONFIGURATION_t, REMARK_PROFILE_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_2_CONFIGURATION].values[9].name = "REMARK_PROFILE_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_2_CONFIGURATION].values[9].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_2_CONFIGURATION].values[9].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_2_CONFIGURATION].values[9].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPC_TERM_ETPS_ARR_2_CONFIGURATION_t, REMARK_PROFILE_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_2_CONFIGURATION].values[10].name = "TTL_MODEL_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_2_CONFIGURATION].values[10].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_2_CONFIGURATION].values[10].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_2_CONFIGURATION].values[10].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPC_TERM_ETPS_ARR_2_CONFIGURATION_t, TTL_MODEL_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_2_CONFIGURATION].values[11].name = "TTL_MODEL_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_2_CONFIGURATION].values[11].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_2_CONFIGURATION].values[11].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_2_CONFIGURATION].values[11].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ETPPC_TERM_ETPS_ARR_2_CONFIGURATION_t, TTL_MODEL_CONFIG_valid);
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_EXPECTED_ARR_FORMAT_CONFIG].name = "IPPB_EXPECTED_ARR_FORMAT_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_EXPECTED_ARR_FORMAT_CONFIG].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_EXPECTED_ARR_FORMAT_CONFIG].flags |= DNXC_DATA_F_TABLE;
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_EXPECTED_ARR_FORMAT_CONFIG].size_of_values = sizeof(dnx_data_dnx2_arr_formats_IPPB_EXPECTED_ARR_FORMAT_CONFIG_t);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_EXPECTED_ARR_FORMAT_CONFIG].entry_get = dnx_data_dnx2_arr_formats_IPPB_EXPECTED_ARR_FORMAT_CONFIG_entry_str_get;

        
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_EXPECTED_ARR_FORMAT_CONFIG].nof_keys = 1;
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_EXPECTED_ARR_FORMAT_CONFIG].keys[0].name = "index";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_EXPECTED_ARR_FORMAT_CONFIG].keys[0].doc = "";

        
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_EXPECTED_ARR_FORMAT_CONFIG].nof_values = 12;
        DNXC_DATA_ALLOC(submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_EXPECTED_ARR_FORMAT_CONFIG].values, dnxc_data_value_t, submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_EXPECTED_ARR_FORMAT_CONFIG].nof_values, "_dnx_data_dnx2_arr_formats_table_IPPB_EXPECTED_ARR_FORMAT_CONFIG table values");
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_EXPECTED_ARR_FORMAT_CONFIG].values[0].name = "valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_EXPECTED_ARR_FORMAT_CONFIG].values[0].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_EXPECTED_ARR_FORMAT_CONFIG].values[0].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_EXPECTED_ARR_FORMAT_CONFIG].values[0].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPB_EXPECTED_ARR_FORMAT_CONFIG_t, valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_EXPECTED_ARR_FORMAT_CONFIG].values[1].name = "doc";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_EXPECTED_ARR_FORMAT_CONFIG].values[1].type = "char *";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_EXPECTED_ARR_FORMAT_CONFIG].values[1].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_EXPECTED_ARR_FORMAT_CONFIG].values[1].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPB_EXPECTED_ARR_FORMAT_CONFIG_t, doc);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_EXPECTED_ARR_FORMAT_CONFIG].values[2].name = "DESTINATION";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_EXPECTED_ARR_FORMAT_CONFIG].values[2].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_EXPECTED_ARR_FORMAT_CONFIG].values[2].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_EXPECTED_ARR_FORMAT_CONFIG].values[2].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPB_EXPECTED_ARR_FORMAT_CONFIG_t, DESTINATION);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_EXPECTED_ARR_FORMAT_CONFIG].values[3].name = "DESTINATION_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_EXPECTED_ARR_FORMAT_CONFIG].values[3].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_EXPECTED_ARR_FORMAT_CONFIG].values[3].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_EXPECTED_ARR_FORMAT_CONFIG].values[3].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPB_EXPECTED_ARR_FORMAT_CONFIG_t, DESTINATION_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_EXPECTED_ARR_FORMAT_CONFIG].values[4].name = "DATA_1";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_EXPECTED_ARR_FORMAT_CONFIG].values[4].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_EXPECTED_ARR_FORMAT_CONFIG].values[4].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_EXPECTED_ARR_FORMAT_CONFIG].values[4].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPB_EXPECTED_ARR_FORMAT_CONFIG_t, DATA_1);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_EXPECTED_ARR_FORMAT_CONFIG].values[5].name = "DATA_1_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_EXPECTED_ARR_FORMAT_CONFIG].values[5].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_EXPECTED_ARR_FORMAT_CONFIG].values[5].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_EXPECTED_ARR_FORMAT_CONFIG].values[5].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPB_EXPECTED_ARR_FORMAT_CONFIG_t, DATA_1_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_EXPECTED_ARR_FORMAT_CONFIG].values[6].name = "DATA_2";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_EXPECTED_ARR_FORMAT_CONFIG].values[6].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_EXPECTED_ARR_FORMAT_CONFIG].values[6].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_EXPECTED_ARR_FORMAT_CONFIG].values[6].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPB_EXPECTED_ARR_FORMAT_CONFIG_t, DATA_2);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_EXPECTED_ARR_FORMAT_CONFIG].values[7].name = "DATA_2_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_EXPECTED_ARR_FORMAT_CONFIG].values[7].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_EXPECTED_ARR_FORMAT_CONFIG].values[7].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_EXPECTED_ARR_FORMAT_CONFIG].values[7].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPB_EXPECTED_ARR_FORMAT_CONFIG_t, DATA_2_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_EXPECTED_ARR_FORMAT_CONFIG].values[8].name = "TYPE";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_EXPECTED_ARR_FORMAT_CONFIG].values[8].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_EXPECTED_ARR_FORMAT_CONFIG].values[8].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_EXPECTED_ARR_FORMAT_CONFIG].values[8].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPB_EXPECTED_ARR_FORMAT_CONFIG_t, TYPE);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_EXPECTED_ARR_FORMAT_CONFIG].values[9].name = "TYPE_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_EXPECTED_ARR_FORMAT_CONFIG].values[9].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_EXPECTED_ARR_FORMAT_CONFIG].values[9].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_EXPECTED_ARR_FORMAT_CONFIG].values[9].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPB_EXPECTED_ARR_FORMAT_CONFIG_t, TYPE_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_EXPECTED_ARR_FORMAT_CONFIG].values[10].name = "STRENGTH";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_EXPECTED_ARR_FORMAT_CONFIG].values[10].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_EXPECTED_ARR_FORMAT_CONFIG].values[10].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_EXPECTED_ARR_FORMAT_CONFIG].values[10].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPB_EXPECTED_ARR_FORMAT_CONFIG_t, STRENGTH);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_EXPECTED_ARR_FORMAT_CONFIG].values[11].name = "STRENGTH_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_EXPECTED_ARR_FORMAT_CONFIG].values[11].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_EXPECTED_ARR_FORMAT_CONFIG].values[11].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_EXPECTED_ARR_FORMAT_CONFIG].values[11].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPB_EXPECTED_ARR_FORMAT_CONFIG_t, STRENGTH_valid);
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_MACT_MRQ_ARR_CFG].name = "MACT_MRQ_ARR_CFG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_MACT_MRQ_ARR_CFG].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_MACT_MRQ_ARR_CFG].flags |= DNXC_DATA_F_TABLE;
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_MACT_MRQ_ARR_CFG].size_of_values = sizeof(dnx_data_dnx2_arr_formats_MACT_MRQ_ARR_CFG_t);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_MACT_MRQ_ARR_CFG].entry_get = dnx_data_dnx2_arr_formats_MACT_MRQ_ARR_CFG_entry_str_get;

        
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_MACT_MRQ_ARR_CFG].nof_keys = 1;
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_MACT_MRQ_ARR_CFG].keys[0].name = "index";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_MACT_MRQ_ARR_CFG].keys[0].doc = "";

        
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_MACT_MRQ_ARR_CFG].nof_values = 4;
        DNXC_DATA_ALLOC(submodule_data->tables[dnx_data_dnx2_arr_formats_table_MACT_MRQ_ARR_CFG].values, dnxc_data_value_t, submodule_data->tables[dnx_data_dnx2_arr_formats_table_MACT_MRQ_ARR_CFG].nof_values, "_dnx_data_dnx2_arr_formats_table_MACT_MRQ_ARR_CFG table values");
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_MACT_MRQ_ARR_CFG].values[0].name = "valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_MACT_MRQ_ARR_CFG].values[0].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_MACT_MRQ_ARR_CFG].values[0].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_MACT_MRQ_ARR_CFG].values[0].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_MACT_MRQ_ARR_CFG_t, valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_MACT_MRQ_ARR_CFG].values[1].name = "doc";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_MACT_MRQ_ARR_CFG].values[1].type = "char *";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_MACT_MRQ_ARR_CFG].values[1].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_MACT_MRQ_ARR_CFG].values[1].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_MACT_MRQ_ARR_CFG_t, doc);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_MACT_MRQ_ARR_CFG].values[2].name = "STRENGTH";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_MACT_MRQ_ARR_CFG].values[2].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_MACT_MRQ_ARR_CFG].values[2].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_MACT_MRQ_ARR_CFG].values[2].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_MACT_MRQ_ARR_CFG_t, STRENGTH);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_MACT_MRQ_ARR_CFG].values[3].name = "STRENGTH_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_MACT_MRQ_ARR_CFG].values[3].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_MACT_MRQ_ARR_CFG].values[3].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_MACT_MRQ_ARR_CFG].values[3].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_MACT_MRQ_ARR_CFG_t, STRENGTH_valid);
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_ACCEPTED_ARR_FORMAT_CONFIG].name = "IPPB_ACCEPTED_ARR_FORMAT_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_ACCEPTED_ARR_FORMAT_CONFIG].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_ACCEPTED_ARR_FORMAT_CONFIG].flags |= DNXC_DATA_F_TABLE;
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_ACCEPTED_ARR_FORMAT_CONFIG].size_of_values = sizeof(dnx_data_dnx2_arr_formats_IPPB_ACCEPTED_ARR_FORMAT_CONFIG_t);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_ACCEPTED_ARR_FORMAT_CONFIG].entry_get = dnx_data_dnx2_arr_formats_IPPB_ACCEPTED_ARR_FORMAT_CONFIG_entry_str_get;

        
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_ACCEPTED_ARR_FORMAT_CONFIG].nof_keys = 1;
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_ACCEPTED_ARR_FORMAT_CONFIG].keys[0].name = "index";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_ACCEPTED_ARR_FORMAT_CONFIG].keys[0].doc = "";

        
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_ACCEPTED_ARR_FORMAT_CONFIG].nof_values = 12;
        DNXC_DATA_ALLOC(submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_ACCEPTED_ARR_FORMAT_CONFIG].values, dnxc_data_value_t, submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_ACCEPTED_ARR_FORMAT_CONFIG].nof_values, "_dnx_data_dnx2_arr_formats_table_IPPB_ACCEPTED_ARR_FORMAT_CONFIG table values");
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_ACCEPTED_ARR_FORMAT_CONFIG].values[0].name = "valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_ACCEPTED_ARR_FORMAT_CONFIG].values[0].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_ACCEPTED_ARR_FORMAT_CONFIG].values[0].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_ACCEPTED_ARR_FORMAT_CONFIG].values[0].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPB_ACCEPTED_ARR_FORMAT_CONFIG_t, valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_ACCEPTED_ARR_FORMAT_CONFIG].values[1].name = "doc";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_ACCEPTED_ARR_FORMAT_CONFIG].values[1].type = "char *";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_ACCEPTED_ARR_FORMAT_CONFIG].values[1].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_ACCEPTED_ARR_FORMAT_CONFIG].values[1].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPB_ACCEPTED_ARR_FORMAT_CONFIG_t, doc);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_ACCEPTED_ARR_FORMAT_CONFIG].values[2].name = "DESTINATION";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_ACCEPTED_ARR_FORMAT_CONFIG].values[2].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_ACCEPTED_ARR_FORMAT_CONFIG].values[2].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_ACCEPTED_ARR_FORMAT_CONFIG].values[2].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPB_ACCEPTED_ARR_FORMAT_CONFIG_t, DESTINATION);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_ACCEPTED_ARR_FORMAT_CONFIG].values[3].name = "DESTINATION_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_ACCEPTED_ARR_FORMAT_CONFIG].values[3].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_ACCEPTED_ARR_FORMAT_CONFIG].values[3].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_ACCEPTED_ARR_FORMAT_CONFIG].values[3].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPB_ACCEPTED_ARR_FORMAT_CONFIG_t, DESTINATION_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_ACCEPTED_ARR_FORMAT_CONFIG].values[4].name = "DATA_1";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_ACCEPTED_ARR_FORMAT_CONFIG].values[4].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_ACCEPTED_ARR_FORMAT_CONFIG].values[4].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_ACCEPTED_ARR_FORMAT_CONFIG].values[4].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPB_ACCEPTED_ARR_FORMAT_CONFIG_t, DATA_1);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_ACCEPTED_ARR_FORMAT_CONFIG].values[5].name = "DATA_1_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_ACCEPTED_ARR_FORMAT_CONFIG].values[5].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_ACCEPTED_ARR_FORMAT_CONFIG].values[5].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_ACCEPTED_ARR_FORMAT_CONFIG].values[5].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPB_ACCEPTED_ARR_FORMAT_CONFIG_t, DATA_1_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_ACCEPTED_ARR_FORMAT_CONFIG].values[6].name = "DATA_2";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_ACCEPTED_ARR_FORMAT_CONFIG].values[6].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_ACCEPTED_ARR_FORMAT_CONFIG].values[6].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_ACCEPTED_ARR_FORMAT_CONFIG].values[6].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPB_ACCEPTED_ARR_FORMAT_CONFIG_t, DATA_2);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_ACCEPTED_ARR_FORMAT_CONFIG].values[7].name = "DATA_2_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_ACCEPTED_ARR_FORMAT_CONFIG].values[7].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_ACCEPTED_ARR_FORMAT_CONFIG].values[7].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_ACCEPTED_ARR_FORMAT_CONFIG].values[7].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPB_ACCEPTED_ARR_FORMAT_CONFIG_t, DATA_2_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_ACCEPTED_ARR_FORMAT_CONFIG].values[8].name = "TYPE";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_ACCEPTED_ARR_FORMAT_CONFIG].values[8].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_ACCEPTED_ARR_FORMAT_CONFIG].values[8].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_ACCEPTED_ARR_FORMAT_CONFIG].values[8].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPB_ACCEPTED_ARR_FORMAT_CONFIG_t, TYPE);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_ACCEPTED_ARR_FORMAT_CONFIG].values[9].name = "TYPE_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_ACCEPTED_ARR_FORMAT_CONFIG].values[9].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_ACCEPTED_ARR_FORMAT_CONFIG].values[9].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_ACCEPTED_ARR_FORMAT_CONFIG].values[9].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPB_ACCEPTED_ARR_FORMAT_CONFIG_t, TYPE_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_ACCEPTED_ARR_FORMAT_CONFIG].values[10].name = "STRENGTH";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_ACCEPTED_ARR_FORMAT_CONFIG].values[10].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_ACCEPTED_ARR_FORMAT_CONFIG].values[10].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_ACCEPTED_ARR_FORMAT_CONFIG].values[10].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPB_ACCEPTED_ARR_FORMAT_CONFIG_t, STRENGTH);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_ACCEPTED_ARR_FORMAT_CONFIG].values[11].name = "STRENGTH_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_ACCEPTED_ARR_FORMAT_CONFIG].values[11].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_ACCEPTED_ARR_FORMAT_CONFIG].values[11].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_ACCEPTED_ARR_FORMAT_CONFIG].values[11].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPB_ACCEPTED_ARR_FORMAT_CONFIG_t, STRENGTH_valid);
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_FEC_FORMAT_CONFIGURATION_TABLE___array].name = "IPPD_FEC_FORMAT_CONFIGURATION_TABLE___array";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_FEC_FORMAT_CONFIGURATION_TABLE___array].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_FEC_FORMAT_CONFIGURATION_TABLE___array].flags |= DNXC_DATA_F_TABLE;
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_FEC_FORMAT_CONFIGURATION_TABLE___array].size_of_values = sizeof(dnx_data_dnx2_arr_formats_IPPD_FEC_FORMAT_CONFIGURATION_TABLE___array_t);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_FEC_FORMAT_CONFIGURATION_TABLE___array].entry_get = dnx_data_dnx2_arr_formats_IPPD_FEC_FORMAT_CONFIGURATION_TABLE___array_entry_str_get;

        
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_FEC_FORMAT_CONFIGURATION_TABLE___array].nof_keys = 2;
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_FEC_FORMAT_CONFIGURATION_TABLE___array].keys[0].name = "table_index";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_FEC_FORMAT_CONFIGURATION_TABLE___array].keys[0].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_FEC_FORMAT_CONFIGURATION_TABLE___array].keys[1].name = "index";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_FEC_FORMAT_CONFIGURATION_TABLE___array].keys[1].doc = "";

        
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_FEC_FORMAT_CONFIGURATION_TABLE___array].nof_values = 14;
        DNXC_DATA_ALLOC(submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_FEC_FORMAT_CONFIGURATION_TABLE___array].values, dnxc_data_value_t, submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_FEC_FORMAT_CONFIGURATION_TABLE___array].nof_values, "_dnx_data_dnx2_arr_formats_table_IPPD_FEC_FORMAT_CONFIGURATION_TABLE___array table values");
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_FEC_FORMAT_CONFIGURATION_TABLE___array].values[0].name = "valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_FEC_FORMAT_CONFIGURATION_TABLE___array].values[0].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_FEC_FORMAT_CONFIGURATION_TABLE___array].values[0].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_FEC_FORMAT_CONFIGURATION_TABLE___array].values[0].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPD_FEC_FORMAT_CONFIGURATION_TABLE___array_t, valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_FEC_FORMAT_CONFIGURATION_TABLE___array].values[1].name = "doc";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_FEC_FORMAT_CONFIGURATION_TABLE___array].values[1].type = "char *";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_FEC_FORMAT_CONFIGURATION_TABLE___array].values[1].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_FEC_FORMAT_CONFIGURATION_TABLE___array].values[1].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPD_FEC_FORMAT_CONFIGURATION_TABLE___array_t, doc);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_FEC_FORMAT_CONFIGURATION_TABLE___array].values[2].name = "DESTINATION_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_FEC_FORMAT_CONFIGURATION_TABLE___array].values[2].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_FEC_FORMAT_CONFIGURATION_TABLE___array].values[2].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_FEC_FORMAT_CONFIGURATION_TABLE___array].values[2].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPD_FEC_FORMAT_CONFIGURATION_TABLE___array_t, DESTINATION_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_FEC_FORMAT_CONFIGURATION_TABLE___array].values[3].name = "DESTINATION_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_FEC_FORMAT_CONFIGURATION_TABLE___array].values[3].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_FEC_FORMAT_CONFIGURATION_TABLE___array].values[3].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_FEC_FORMAT_CONFIGURATION_TABLE___array].values[3].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPD_FEC_FORMAT_CONFIGURATION_TABLE___array_t, DESTINATION_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_FEC_FORMAT_CONFIGURATION_TABLE___array].values[4].name = "EEI_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_FEC_FORMAT_CONFIGURATION_TABLE___array].values[4].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_FEC_FORMAT_CONFIGURATION_TABLE___array].values[4].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_FEC_FORMAT_CONFIGURATION_TABLE___array].values[4].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPD_FEC_FORMAT_CONFIGURATION_TABLE___array_t, EEI_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_FEC_FORMAT_CONFIGURATION_TABLE___array].values[5].name = "EEI_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_FEC_FORMAT_CONFIGURATION_TABLE___array].values[5].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_FEC_FORMAT_CONFIGURATION_TABLE___array].values[5].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_FEC_FORMAT_CONFIGURATION_TABLE___array].values[5].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPD_FEC_FORMAT_CONFIGURATION_TABLE___array_t, EEI_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_FEC_FORMAT_CONFIGURATION_TABLE___array].values[6].name = "OUT_LIF_0_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_FEC_FORMAT_CONFIGURATION_TABLE___array].values[6].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_FEC_FORMAT_CONFIGURATION_TABLE___array].values[6].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_FEC_FORMAT_CONFIGURATION_TABLE___array].values[6].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPD_FEC_FORMAT_CONFIGURATION_TABLE___array_t, OUT_LIF_0_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_FEC_FORMAT_CONFIGURATION_TABLE___array].values[7].name = "OUT_LIF_0_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_FEC_FORMAT_CONFIGURATION_TABLE___array].values[7].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_FEC_FORMAT_CONFIGURATION_TABLE___array].values[7].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_FEC_FORMAT_CONFIGURATION_TABLE___array].values[7].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPD_FEC_FORMAT_CONFIGURATION_TABLE___array_t, OUT_LIF_0_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_FEC_FORMAT_CONFIGURATION_TABLE___array].values[8].name = "OUT_LIF_1_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_FEC_FORMAT_CONFIGURATION_TABLE___array].values[8].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_FEC_FORMAT_CONFIGURATION_TABLE___array].values[8].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_FEC_FORMAT_CONFIGURATION_TABLE___array].values[8].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPD_FEC_FORMAT_CONFIGURATION_TABLE___array_t, OUT_LIF_1_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_FEC_FORMAT_CONFIGURATION_TABLE___array].values[9].name = "OUT_LIF_1_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_FEC_FORMAT_CONFIGURATION_TABLE___array].values[9].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_FEC_FORMAT_CONFIGURATION_TABLE___array].values[9].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_FEC_FORMAT_CONFIGURATION_TABLE___array].values[9].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPD_FEC_FORMAT_CONFIGURATION_TABLE___array_t, OUT_LIF_1_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_FEC_FORMAT_CONFIGURATION_TABLE___array].values[10].name = "WEAK_TM_FLOW_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_FEC_FORMAT_CONFIGURATION_TABLE___array].values[10].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_FEC_FORMAT_CONFIGURATION_TABLE___array].values[10].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_FEC_FORMAT_CONFIGURATION_TABLE___array].values[10].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPD_FEC_FORMAT_CONFIGURATION_TABLE___array_t, WEAK_TM_FLOW_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_FEC_FORMAT_CONFIGURATION_TABLE___array].values[11].name = "WEAK_TM_FLOW_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_FEC_FORMAT_CONFIGURATION_TABLE___array].values[11].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_FEC_FORMAT_CONFIGURATION_TABLE___array].values[11].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_FEC_FORMAT_CONFIGURATION_TABLE___array].values[11].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPD_FEC_FORMAT_CONFIGURATION_TABLE___array_t, WEAK_TM_FLOW_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_FEC_FORMAT_CONFIGURATION_TABLE___array].values[12].name = "MC_RPF_MODE_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_FEC_FORMAT_CONFIGURATION_TABLE___array].values[12].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_FEC_FORMAT_CONFIGURATION_TABLE___array].values[12].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_FEC_FORMAT_CONFIGURATION_TABLE___array].values[12].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPD_FEC_FORMAT_CONFIGURATION_TABLE___array_t, MC_RPF_MODE_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_FEC_FORMAT_CONFIGURATION_TABLE___array].values[13].name = "MC_RPF_MODE_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_FEC_FORMAT_CONFIGURATION_TABLE___array].values[13].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_FEC_FORMAT_CONFIGURATION_TABLE___array].values[13].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_FEC_FORMAT_CONFIGURATION_TABLE___array].values[13].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPD_FEC_FORMAT_CONFIGURATION_TABLE___array_t, MC_RPF_MODE_CONFIG_valid);
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array].name = "IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array].flags |= DNXC_DATA_F_TABLE;
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array].size_of_values = sizeof(dnx_data_dnx2_arr_formats_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array_t);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array].entry_get = dnx_data_dnx2_arr_formats_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array_entry_str_get;

        
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array].nof_keys = 2;
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array].keys[0].name = "table_index";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array].keys[0].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array].keys[1].name = "index";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array].keys[1].doc = "";

        
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array].nof_values = 26;
        DNXC_DATA_ALLOC(submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array].values, dnxc_data_value_t, submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array].nof_values, "_dnx_data_dnx2_arr_formats_table_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array table values");
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array].values[0].name = "valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array].values[0].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array].values[0].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array].values[0].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array_t, valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array].values[1].name = "doc";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array].values[1].type = "char *";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array].values[1].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array].values[1].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array_t, doc);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array].values[2].name = "AGING_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array].values[2].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array].values[2].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array].values[2].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array_t, AGING_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array].values[3].name = "AGING_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array].values[3].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array].values[3].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array].values[3].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array_t, AGING_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array].values[4].name = "DESTINATION_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array].values[4].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array].values[4].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array].values[4].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array_t, DESTINATION_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array].values[5].name = "DESTINATION_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array].values[5].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array].values[5].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array].values[5].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array_t, DESTINATION_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array].values[6].name = "EEI_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array].values[6].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array].values[6].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array].values[6].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array_t, EEI_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array].values[7].name = "EEI_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array].values[7].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array].values[7].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array].values[7].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array_t, EEI_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array].values[8].name = "ENTRY_GROUPING_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array].values[8].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array].values[8].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array].values[8].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array_t, ENTRY_GROUPING_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array].values[9].name = "ENTRY_GROUPING_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array].values[9].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array].values[9].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array].values[9].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array_t, ENTRY_GROUPING_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array].values[10].name = "OUTLIF_0_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array].values[10].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array].values[10].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array].values[10].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array_t, OUTLIF_0_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array].values[11].name = "OUTLIF_0_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array].values[11].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array].values[11].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array].values[11].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array_t, OUTLIF_0_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array].values[12].name = "OUTLIF_1_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array].values[12].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array].values[12].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array].values[12].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array_t, OUTLIF_1_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array].values[13].name = "OUTLIF_1_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array].values[13].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array].values[13].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array].values[13].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array_t, OUTLIF_1_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array].values[14].name = "IRPP_FWD_RAW_DATA";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array].values[14].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array].values[14].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array].values[14].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array_t, IRPP_FWD_RAW_DATA);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array].values[15].name = "IRPP_FWD_RAW_DATA_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array].values[15].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array].values[15].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array].values[15].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array_t, IRPP_FWD_RAW_DATA_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array].values[16].name = "DEFAULT_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array].values[16].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array].values[16].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array].values[16].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array_t, DEFAULT_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array].values[17].name = "DEFAULT_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array].values[17].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array].values[17].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array].values[17].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array_t, DEFAULT_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array].values[18].name = "MAC_ENTRY_STRENGTH_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array].values[18].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array].values[18].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array].values[18].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array_t, MAC_ENTRY_STRENGTH_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array].values[19].name = "MAC_ENTRY_STRENGTH_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array].values[19].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array].values[19].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array].values[19].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array_t, MAC_ENTRY_STRENGTH_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array].values[20].name = "STAT_OBJ_CMD_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array].values[20].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array].values[20].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array].values[20].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array_t, STAT_OBJ_CMD_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array].values[21].name = "STAT_OBJ_CMD_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array].values[21].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array].values[21].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array].values[21].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array_t, STAT_OBJ_CMD_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array].values[22].name = "STAT_OBJ_ID_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array].values[22].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array].values[22].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array].values[22].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array_t, STAT_OBJ_ID_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array].values[23].name = "STAT_OBJ_ID_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array].values[23].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array].values[23].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array].values[23].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array_t, STAT_OBJ_ID_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array].values[24].name = "UNKNOWN_ADDR_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array].values[24].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array].values[24].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array].values[24].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array_t, UNKNOWN_ADDR_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array].values[25].name = "UNKNOWN_ADDR_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array].values[25].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array].values[25].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array].values[25].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array_t, UNKNOWN_ADDR_CONFIG_valid);
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_RPF_FORMAT_CONFIGURATION_TABLE___array].name = "IPPB_FLP_RPF_FORMAT_CONFIGURATION_TABLE___array";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_RPF_FORMAT_CONFIGURATION_TABLE___array].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_RPF_FORMAT_CONFIGURATION_TABLE___array].flags |= DNXC_DATA_F_TABLE;
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_RPF_FORMAT_CONFIGURATION_TABLE___array].size_of_values = sizeof(dnx_data_dnx2_arr_formats_IPPB_FLP_RPF_FORMAT_CONFIGURATION_TABLE___array_t);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_RPF_FORMAT_CONFIGURATION_TABLE___array].entry_get = dnx_data_dnx2_arr_formats_IPPB_FLP_RPF_FORMAT_CONFIGURATION_TABLE___array_entry_str_get;

        
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_RPF_FORMAT_CONFIGURATION_TABLE___array].nof_keys = 2;
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_RPF_FORMAT_CONFIGURATION_TABLE___array].keys[0].name = "table_index";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_RPF_FORMAT_CONFIGURATION_TABLE___array].keys[0].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_RPF_FORMAT_CONFIGURATION_TABLE___array].keys[1].name = "index";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_RPF_FORMAT_CONFIGURATION_TABLE___array].keys[1].doc = "";

        
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_RPF_FORMAT_CONFIGURATION_TABLE___array].nof_values = 16;
        DNXC_DATA_ALLOC(submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_RPF_FORMAT_CONFIGURATION_TABLE___array].values, dnxc_data_value_t, submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_RPF_FORMAT_CONFIGURATION_TABLE___array].nof_values, "_dnx_data_dnx2_arr_formats_table_IPPB_FLP_RPF_FORMAT_CONFIGURATION_TABLE___array table values");
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_RPF_FORMAT_CONFIGURATION_TABLE___array].values[0].name = "valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_RPF_FORMAT_CONFIGURATION_TABLE___array].values[0].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_RPF_FORMAT_CONFIGURATION_TABLE___array].values[0].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_RPF_FORMAT_CONFIGURATION_TABLE___array].values[0].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPB_FLP_RPF_FORMAT_CONFIGURATION_TABLE___array_t, valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_RPF_FORMAT_CONFIGURATION_TABLE___array].values[1].name = "doc";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_RPF_FORMAT_CONFIGURATION_TABLE___array].values[1].type = "char *";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_RPF_FORMAT_CONFIGURATION_TABLE___array].values[1].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_RPF_FORMAT_CONFIGURATION_TABLE___array].values[1].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPB_FLP_RPF_FORMAT_CONFIGURATION_TABLE___array_t, doc);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_RPF_FORMAT_CONFIGURATION_TABLE___array].values[2].name = "DESTINATION_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_RPF_FORMAT_CONFIGURATION_TABLE___array].values[2].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_RPF_FORMAT_CONFIGURATION_TABLE___array].values[2].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_RPF_FORMAT_CONFIGURATION_TABLE___array].values[2].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPB_FLP_RPF_FORMAT_CONFIGURATION_TABLE___array_t, DESTINATION_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_RPF_FORMAT_CONFIGURATION_TABLE___array].values[3].name = "DESTINATION_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_RPF_FORMAT_CONFIGURATION_TABLE___array].values[3].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_RPF_FORMAT_CONFIGURATION_TABLE___array].values[3].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_RPF_FORMAT_CONFIGURATION_TABLE___array].values[3].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPB_FLP_RPF_FORMAT_CONFIGURATION_TABLE___array_t, DESTINATION_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_RPF_FORMAT_CONFIGURATION_TABLE___array].values[4].name = "OUTLIF_0_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_RPF_FORMAT_CONFIGURATION_TABLE___array].values[4].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_RPF_FORMAT_CONFIGURATION_TABLE___array].values[4].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_RPF_FORMAT_CONFIGURATION_TABLE___array].values[4].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPB_FLP_RPF_FORMAT_CONFIGURATION_TABLE___array_t, OUTLIF_0_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_RPF_FORMAT_CONFIGURATION_TABLE___array].values[5].name = "OUTLIF_0_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_RPF_FORMAT_CONFIGURATION_TABLE___array].values[5].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_RPF_FORMAT_CONFIGURATION_TABLE___array].values[5].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_RPF_FORMAT_CONFIGURATION_TABLE___array].values[5].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPB_FLP_RPF_FORMAT_CONFIGURATION_TABLE___array_t, OUTLIF_0_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_RPF_FORMAT_CONFIGURATION_TABLE___array].values[6].name = "DEFAULT_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_RPF_FORMAT_CONFIGURATION_TABLE___array].values[6].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_RPF_FORMAT_CONFIGURATION_TABLE___array].values[6].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_RPF_FORMAT_CONFIGURATION_TABLE___array].values[6].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPB_FLP_RPF_FORMAT_CONFIGURATION_TABLE___array_t, DEFAULT_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_RPF_FORMAT_CONFIGURATION_TABLE___array].values[7].name = "DEFAULT_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_RPF_FORMAT_CONFIGURATION_TABLE___array].values[7].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_RPF_FORMAT_CONFIGURATION_TABLE___array].values[7].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_RPF_FORMAT_CONFIGURATION_TABLE___array].values[7].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPB_FLP_RPF_FORMAT_CONFIGURATION_TABLE___array_t, DEFAULT_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_RPF_FORMAT_CONFIGURATION_TABLE___array].values[8].name = "OPAQUE_FIELD_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_RPF_FORMAT_CONFIGURATION_TABLE___array].values[8].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_RPF_FORMAT_CONFIGURATION_TABLE___array].values[8].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_RPF_FORMAT_CONFIGURATION_TABLE___array].values[8].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPB_FLP_RPF_FORMAT_CONFIGURATION_TABLE___array_t, OPAQUE_FIELD_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_RPF_FORMAT_CONFIGURATION_TABLE___array].values[9].name = "OPAQUE_FIELD_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_RPF_FORMAT_CONFIGURATION_TABLE___array].values[9].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_RPF_FORMAT_CONFIGURATION_TABLE___array].values[9].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_RPF_FORMAT_CONFIGURATION_TABLE___array].values[9].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPB_FLP_RPF_FORMAT_CONFIGURATION_TABLE___array_t, OPAQUE_FIELD_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_RPF_FORMAT_CONFIGURATION_TABLE___array].values[10].name = "SA_DROP_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_RPF_FORMAT_CONFIGURATION_TABLE___array].values[10].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_RPF_FORMAT_CONFIGURATION_TABLE___array].values[10].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_RPF_FORMAT_CONFIGURATION_TABLE___array].values[10].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPB_FLP_RPF_FORMAT_CONFIGURATION_TABLE___array_t, SA_DROP_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_RPF_FORMAT_CONFIGURATION_TABLE___array].values[11].name = "SA_DROP_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_RPF_FORMAT_CONFIGURATION_TABLE___array].values[11].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_RPF_FORMAT_CONFIGURATION_TABLE___array].values[11].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_RPF_FORMAT_CONFIGURATION_TABLE___array].values[11].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPB_FLP_RPF_FORMAT_CONFIGURATION_TABLE___array_t, SA_DROP_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_RPF_FORMAT_CONFIGURATION_TABLE___array].values[12].name = "STAT_OBJ_CMD_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_RPF_FORMAT_CONFIGURATION_TABLE___array].values[12].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_RPF_FORMAT_CONFIGURATION_TABLE___array].values[12].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_RPF_FORMAT_CONFIGURATION_TABLE___array].values[12].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPB_FLP_RPF_FORMAT_CONFIGURATION_TABLE___array_t, STAT_OBJ_CMD_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_RPF_FORMAT_CONFIGURATION_TABLE___array].values[13].name = "STAT_OBJ_CMD_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_RPF_FORMAT_CONFIGURATION_TABLE___array].values[13].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_RPF_FORMAT_CONFIGURATION_TABLE___array].values[13].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_RPF_FORMAT_CONFIGURATION_TABLE___array].values[13].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPB_FLP_RPF_FORMAT_CONFIGURATION_TABLE___array_t, STAT_OBJ_CMD_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_RPF_FORMAT_CONFIGURATION_TABLE___array].values[14].name = "STAT_OBJ_ID_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_RPF_FORMAT_CONFIGURATION_TABLE___array].values[14].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_RPF_FORMAT_CONFIGURATION_TABLE___array].values[14].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_RPF_FORMAT_CONFIGURATION_TABLE___array].values[14].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPB_FLP_RPF_FORMAT_CONFIGURATION_TABLE___array_t, STAT_OBJ_ID_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_RPF_FORMAT_CONFIGURATION_TABLE___array].values[15].name = "STAT_OBJ_ID_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_RPF_FORMAT_CONFIGURATION_TABLE___array].values[15].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_RPF_FORMAT_CONFIGURATION_TABLE___array].values[15].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPB_FLP_RPF_FORMAT_CONFIGURATION_TABLE___array].values[15].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPB_FLP_RPF_FORMAT_CONFIGURATION_TABLE___array_t, STAT_OBJ_ID_CONFIG_valid);
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_SUPER_ARR_FORMAT_CONFIGURATION_TABLE___array].name = "IPPD_SUPER_ARR_FORMAT_CONFIGURATION_TABLE___array";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_SUPER_ARR_FORMAT_CONFIGURATION_TABLE___array].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_SUPER_ARR_FORMAT_CONFIGURATION_TABLE___array].flags |= DNXC_DATA_F_TABLE;
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_SUPER_ARR_FORMAT_CONFIGURATION_TABLE___array].size_of_values = sizeof(dnx_data_dnx2_arr_formats_IPPD_SUPER_ARR_FORMAT_CONFIGURATION_TABLE___array_t);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_SUPER_ARR_FORMAT_CONFIGURATION_TABLE___array].entry_get = dnx_data_dnx2_arr_formats_IPPD_SUPER_ARR_FORMAT_CONFIGURATION_TABLE___array_entry_str_get;

        
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_SUPER_ARR_FORMAT_CONFIGURATION_TABLE___array].nof_keys = 2;
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_SUPER_ARR_FORMAT_CONFIGURATION_TABLE___array].keys[0].name = "table_index";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_SUPER_ARR_FORMAT_CONFIGURATION_TABLE___array].keys[0].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_SUPER_ARR_FORMAT_CONFIGURATION_TABLE___array].keys[1].name = "index";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_SUPER_ARR_FORMAT_CONFIGURATION_TABLE___array].keys[1].doc = "";

        
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_SUPER_ARR_FORMAT_CONFIGURATION_TABLE___array].nof_values = 16;
        DNXC_DATA_ALLOC(submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_SUPER_ARR_FORMAT_CONFIGURATION_TABLE___array].values, dnxc_data_value_t, submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_SUPER_ARR_FORMAT_CONFIGURATION_TABLE___array].nof_values, "_dnx_data_dnx2_arr_formats_table_IPPD_SUPER_ARR_FORMAT_CONFIGURATION_TABLE___array table values");
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_SUPER_ARR_FORMAT_CONFIGURATION_TABLE___array].values[0].name = "valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_SUPER_ARR_FORMAT_CONFIGURATION_TABLE___array].values[0].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_SUPER_ARR_FORMAT_CONFIGURATION_TABLE___array].values[0].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_SUPER_ARR_FORMAT_CONFIGURATION_TABLE___array].values[0].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPD_SUPER_ARR_FORMAT_CONFIGURATION_TABLE___array_t, valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_SUPER_ARR_FORMAT_CONFIGURATION_TABLE___array].values[1].name = "doc";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_SUPER_ARR_FORMAT_CONFIGURATION_TABLE___array].values[1].type = "char *";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_SUPER_ARR_FORMAT_CONFIGURATION_TABLE___array].values[1].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_SUPER_ARR_FORMAT_CONFIGURATION_TABLE___array].values[1].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPD_SUPER_ARR_FORMAT_CONFIGURATION_TABLE___array_t, doc);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_SUPER_ARR_FORMAT_CONFIGURATION_TABLE___array].values[2].name = "LEFT_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_SUPER_ARR_FORMAT_CONFIGURATION_TABLE___array].values[2].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_SUPER_ARR_FORMAT_CONFIGURATION_TABLE___array].values[2].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_SUPER_ARR_FORMAT_CONFIGURATION_TABLE___array].values[2].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPD_SUPER_ARR_FORMAT_CONFIGURATION_TABLE___array_t, LEFT_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_SUPER_ARR_FORMAT_CONFIGURATION_TABLE___array].values[3].name = "LEFT_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_SUPER_ARR_FORMAT_CONFIGURATION_TABLE___array].values[3].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_SUPER_ARR_FORMAT_CONFIGURATION_TABLE___array].values[3].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_SUPER_ARR_FORMAT_CONFIGURATION_TABLE___array].values[3].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPD_SUPER_ARR_FORMAT_CONFIGURATION_TABLE___array_t, LEFT_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_SUPER_ARR_FORMAT_CONFIGURATION_TABLE___array].values[4].name = "LEFT_STAT_OBJECT_CMD_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_SUPER_ARR_FORMAT_CONFIGURATION_TABLE___array].values[4].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_SUPER_ARR_FORMAT_CONFIGURATION_TABLE___array].values[4].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_SUPER_ARR_FORMAT_CONFIGURATION_TABLE___array].values[4].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPD_SUPER_ARR_FORMAT_CONFIGURATION_TABLE___array_t, LEFT_STAT_OBJECT_CMD_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_SUPER_ARR_FORMAT_CONFIGURATION_TABLE___array].values[5].name = "LEFT_STAT_OBJECT_CMD_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_SUPER_ARR_FORMAT_CONFIGURATION_TABLE___array].values[5].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_SUPER_ARR_FORMAT_CONFIGURATION_TABLE___array].values[5].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_SUPER_ARR_FORMAT_CONFIGURATION_TABLE___array].values[5].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPD_SUPER_ARR_FORMAT_CONFIGURATION_TABLE___array_t, LEFT_STAT_OBJECT_CMD_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_SUPER_ARR_FORMAT_CONFIGURATION_TABLE___array].values[6].name = "LEFT_STAT_OBJECT_ID_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_SUPER_ARR_FORMAT_CONFIGURATION_TABLE___array].values[6].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_SUPER_ARR_FORMAT_CONFIGURATION_TABLE___array].values[6].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_SUPER_ARR_FORMAT_CONFIGURATION_TABLE___array].values[6].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPD_SUPER_ARR_FORMAT_CONFIGURATION_TABLE___array_t, LEFT_STAT_OBJECT_ID_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_SUPER_ARR_FORMAT_CONFIGURATION_TABLE___array].values[7].name = "LEFT_STAT_OBJECT_ID_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_SUPER_ARR_FORMAT_CONFIGURATION_TABLE___array].values[7].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_SUPER_ARR_FORMAT_CONFIGURATION_TABLE___array].values[7].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_SUPER_ARR_FORMAT_CONFIGURATION_TABLE___array].values[7].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPD_SUPER_ARR_FORMAT_CONFIGURATION_TABLE___array_t, LEFT_STAT_OBJECT_ID_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_SUPER_ARR_FORMAT_CONFIGURATION_TABLE___array].values[8].name = "PROTECTION_PTR_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_SUPER_ARR_FORMAT_CONFIGURATION_TABLE___array].values[8].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_SUPER_ARR_FORMAT_CONFIGURATION_TABLE___array].values[8].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_SUPER_ARR_FORMAT_CONFIGURATION_TABLE___array].values[8].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPD_SUPER_ARR_FORMAT_CONFIGURATION_TABLE___array_t, PROTECTION_PTR_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_SUPER_ARR_FORMAT_CONFIGURATION_TABLE___array].values[9].name = "PROTECTION_PTR_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_SUPER_ARR_FORMAT_CONFIGURATION_TABLE___array].values[9].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_SUPER_ARR_FORMAT_CONFIGURATION_TABLE___array].values[9].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_SUPER_ARR_FORMAT_CONFIGURATION_TABLE___array].values[9].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPD_SUPER_ARR_FORMAT_CONFIGURATION_TABLE___array_t, PROTECTION_PTR_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_SUPER_ARR_FORMAT_CONFIGURATION_TABLE___array].values[10].name = "RIGHT_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_SUPER_ARR_FORMAT_CONFIGURATION_TABLE___array].values[10].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_SUPER_ARR_FORMAT_CONFIGURATION_TABLE___array].values[10].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_SUPER_ARR_FORMAT_CONFIGURATION_TABLE___array].values[10].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPD_SUPER_ARR_FORMAT_CONFIGURATION_TABLE___array_t, RIGHT_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_SUPER_ARR_FORMAT_CONFIGURATION_TABLE___array].values[11].name = "RIGHT_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_SUPER_ARR_FORMAT_CONFIGURATION_TABLE___array].values[11].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_SUPER_ARR_FORMAT_CONFIGURATION_TABLE___array].values[11].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_SUPER_ARR_FORMAT_CONFIGURATION_TABLE___array].values[11].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPD_SUPER_ARR_FORMAT_CONFIGURATION_TABLE___array_t, RIGHT_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_SUPER_ARR_FORMAT_CONFIGURATION_TABLE___array].values[12].name = "RIGHT_STAT_OBJECT_CMD_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_SUPER_ARR_FORMAT_CONFIGURATION_TABLE___array].values[12].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_SUPER_ARR_FORMAT_CONFIGURATION_TABLE___array].values[12].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_SUPER_ARR_FORMAT_CONFIGURATION_TABLE___array].values[12].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPD_SUPER_ARR_FORMAT_CONFIGURATION_TABLE___array_t, RIGHT_STAT_OBJECT_CMD_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_SUPER_ARR_FORMAT_CONFIGURATION_TABLE___array].values[13].name = "RIGHT_STAT_OBJECT_CMD_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_SUPER_ARR_FORMAT_CONFIGURATION_TABLE___array].values[13].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_SUPER_ARR_FORMAT_CONFIGURATION_TABLE___array].values[13].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_SUPER_ARR_FORMAT_CONFIGURATION_TABLE___array].values[13].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPD_SUPER_ARR_FORMAT_CONFIGURATION_TABLE___array_t, RIGHT_STAT_OBJECT_CMD_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_SUPER_ARR_FORMAT_CONFIGURATION_TABLE___array].values[14].name = "RIGHT_STAT_OBJECT_ID_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_SUPER_ARR_FORMAT_CONFIGURATION_TABLE___array].values[14].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_SUPER_ARR_FORMAT_CONFIGURATION_TABLE___array].values[14].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_SUPER_ARR_FORMAT_CONFIGURATION_TABLE___array].values[14].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPD_SUPER_ARR_FORMAT_CONFIGURATION_TABLE___array_t, RIGHT_STAT_OBJECT_ID_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_SUPER_ARR_FORMAT_CONFIGURATION_TABLE___array].values[15].name = "RIGHT_STAT_OBJECT_ID_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_SUPER_ARR_FORMAT_CONFIGURATION_TABLE___array].values[15].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_SUPER_ARR_FORMAT_CONFIGURATION_TABLE___array].values[15].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_SUPER_ARR_FORMAT_CONFIGURATION_TABLE___array].values[15].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPD_SUPER_ARR_FORMAT_CONFIGURATION_TABLE___array_t, RIGHT_STAT_OBJECT_ID_CONFIG_valid);
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1].name = "IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1].flags |= DNXC_DATA_F_TABLE;
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1].size_of_values = sizeof(dnx_data_dnx2_arr_formats_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1_t);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1].entry_get = dnx_data_dnx2_arr_formats_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1_entry_str_get;

        
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1].nof_keys = 1;
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1].keys[0].name = "index";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1].keys[0].doc = "";

        
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1].nof_values = 26;
        DNXC_DATA_ALLOC(submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1].values, dnxc_data_value_t, submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1].nof_values, "_dnx_data_dnx2_arr_formats_table_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1 table values");
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1].values[0].name = "valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1].values[0].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1].values[0].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1].values[0].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1_t, valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1].values[1].name = "doc";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1].values[1].type = "char *";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1].values[1].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1].values[1].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1_t, doc);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1].values[2].name = "DA_NOT_FOUND_DESTINATION_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1].values[2].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1].values[2].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1].values[2].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1_t, DA_NOT_FOUND_DESTINATION_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1].values[3].name = "DA_NOT_FOUND_DESTINATION_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1].values[3].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1].values[3].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1].values[3].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1_t, DA_NOT_FOUND_DESTINATION_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1].values[4].name = "ECN_MAPPING_PROFILE_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1].values[4].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1].values[4].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1].values[4].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1_t, ECN_MAPPING_PROFILE_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1].values[5].name = "ECN_MAPPING_PROFILE_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1].values[5].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1].values[5].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1].values[5].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1_t, ECN_MAPPING_PROFILE_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1].values[6].name = "MY_MAC_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1].values[6].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1].values[6].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1].values[6].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1_t, MY_MAC_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1].values[7].name = "MY_MAC_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1].values[7].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1].values[7].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1].values[7].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1_t, MY_MAC_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1].values[8].name = "MY_MAC_PREFIX_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1].values[8].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1].values[8].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1].values[8].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1_t, MY_MAC_PREFIX_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1].values[9].name = "MY_MAC_PREFIX_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1].values[9].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1].values[9].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1].values[9].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1_t, MY_MAC_PREFIX_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1].values[10].name = "PROPAGATION_PROFILE_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1].values[10].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1].values[10].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1].values[10].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1_t, PROPAGATION_PROFILE_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1].values[11].name = "PROPAGATION_PROFILE_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1].values[11].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1].values[11].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1].values[11].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1_t, PROPAGATION_PROFILE_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1].values[12].name = "QOS_PROFILE_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1].values[12].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1].values[12].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1].values[12].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1_t, QOS_PROFILE_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1].values[13].name = "QOS_PROFILE_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1].values[13].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1].values[13].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1].values[13].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1_t, QOS_PROFILE_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1].values[14].name = "STAT_OBJ_CMD_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1].values[14].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1].values[14].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1].values[14].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1_t, STAT_OBJ_CMD_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1].values[15].name = "STAT_OBJ_CMD_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1].values[15].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1].values[15].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1].values[15].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1_t, STAT_OBJ_CMD_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1].values[16].name = "STAT_OBJ_ID_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1].values[16].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1].values[16].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1].values[16].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1_t, STAT_OBJ_ID_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1].values[17].name = "STAT_OBJ_ID_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1].values[17].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1].values[17].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1].values[17].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1_t, STAT_OBJ_ID_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1].values[18].name = "TOPOLOGY_ID_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1].values[18].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1].values[18].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1].values[18].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1_t, TOPOLOGY_ID_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1].values[19].name = "TOPOLOGY_ID_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1].values[19].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1].values[19].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1].values[19].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1_t, TOPOLOGY_ID_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1].values[20].name = "VRF_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1].values[20].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1].values[20].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1].values[20].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1_t, VRF_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1].values[21].name = "VRF_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1].values[21].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1].values[21].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1].values[21].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1_t, VRF_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1].values[22].name = "VRID_BITMAP_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1].values[22].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1].values[22].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1].values[22].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1_t, VRID_BITMAP_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1].values[23].name = "VRID_BITMAP_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1].values[23].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1].values[23].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1].values[23].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1_t, VRID_BITMAP_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1].values[24].name = "VSI_PROFILE_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1].values[24].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1].values[24].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1].values[24].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1_t, VSI_PROFILE_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1].values[25].name = "VSI_PROFILE_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1].values[25].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1].values[25].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1].values[25].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1_t, VSI_PROFILE_CONFIG_valid);
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VSI_FORMAT_CONFIGURATION_TABLE].name = "IPPF_VSI_FORMAT_CONFIGURATION_TABLE";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VSI_FORMAT_CONFIGURATION_TABLE].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VSI_FORMAT_CONFIGURATION_TABLE].flags |= DNXC_DATA_F_TABLE;
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VSI_FORMAT_CONFIGURATION_TABLE].size_of_values = sizeof(dnx_data_dnx2_arr_formats_IPPF_VSI_FORMAT_CONFIGURATION_TABLE_t);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VSI_FORMAT_CONFIGURATION_TABLE].entry_get = dnx_data_dnx2_arr_formats_IPPF_VSI_FORMAT_CONFIGURATION_TABLE_entry_str_get;

        
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VSI_FORMAT_CONFIGURATION_TABLE].nof_keys = 1;
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VSI_FORMAT_CONFIGURATION_TABLE].keys[0].name = "index";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VSI_FORMAT_CONFIGURATION_TABLE].keys[0].doc = "";

        
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VSI_FORMAT_CONFIGURATION_TABLE].nof_values = 26;
        DNXC_DATA_ALLOC(submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VSI_FORMAT_CONFIGURATION_TABLE].values, dnxc_data_value_t, submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VSI_FORMAT_CONFIGURATION_TABLE].nof_values, "_dnx_data_dnx2_arr_formats_table_IPPF_VSI_FORMAT_CONFIGURATION_TABLE table values");
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VSI_FORMAT_CONFIGURATION_TABLE].values[0].name = "valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VSI_FORMAT_CONFIGURATION_TABLE].values[0].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VSI_FORMAT_CONFIGURATION_TABLE].values[0].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VSI_FORMAT_CONFIGURATION_TABLE].values[0].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPF_VSI_FORMAT_CONFIGURATION_TABLE_t, valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VSI_FORMAT_CONFIGURATION_TABLE].values[1].name = "doc";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VSI_FORMAT_CONFIGURATION_TABLE].values[1].type = "char *";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VSI_FORMAT_CONFIGURATION_TABLE].values[1].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VSI_FORMAT_CONFIGURATION_TABLE].values[1].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPF_VSI_FORMAT_CONFIGURATION_TABLE_t, doc);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VSI_FORMAT_CONFIGURATION_TABLE].values[2].name = "DA_NOT_FOUND_DESTINATION_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VSI_FORMAT_CONFIGURATION_TABLE].values[2].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VSI_FORMAT_CONFIGURATION_TABLE].values[2].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VSI_FORMAT_CONFIGURATION_TABLE].values[2].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPF_VSI_FORMAT_CONFIGURATION_TABLE_t, DA_NOT_FOUND_DESTINATION_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VSI_FORMAT_CONFIGURATION_TABLE].values[3].name = "DA_NOT_FOUND_DESTINATION_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VSI_FORMAT_CONFIGURATION_TABLE].values[3].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VSI_FORMAT_CONFIGURATION_TABLE].values[3].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VSI_FORMAT_CONFIGURATION_TABLE].values[3].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPF_VSI_FORMAT_CONFIGURATION_TABLE_t, DA_NOT_FOUND_DESTINATION_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VSI_FORMAT_CONFIGURATION_TABLE].values[4].name = "ECN_MAPPING_PROFILE_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VSI_FORMAT_CONFIGURATION_TABLE].values[4].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VSI_FORMAT_CONFIGURATION_TABLE].values[4].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VSI_FORMAT_CONFIGURATION_TABLE].values[4].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPF_VSI_FORMAT_CONFIGURATION_TABLE_t, ECN_MAPPING_PROFILE_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VSI_FORMAT_CONFIGURATION_TABLE].values[5].name = "ECN_MAPPING_PROFILE_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VSI_FORMAT_CONFIGURATION_TABLE].values[5].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VSI_FORMAT_CONFIGURATION_TABLE].values[5].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VSI_FORMAT_CONFIGURATION_TABLE].values[5].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPF_VSI_FORMAT_CONFIGURATION_TABLE_t, ECN_MAPPING_PROFILE_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VSI_FORMAT_CONFIGURATION_TABLE].values[6].name = "MY_MAC_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VSI_FORMAT_CONFIGURATION_TABLE].values[6].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VSI_FORMAT_CONFIGURATION_TABLE].values[6].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VSI_FORMAT_CONFIGURATION_TABLE].values[6].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPF_VSI_FORMAT_CONFIGURATION_TABLE_t, MY_MAC_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VSI_FORMAT_CONFIGURATION_TABLE].values[7].name = "MY_MAC_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VSI_FORMAT_CONFIGURATION_TABLE].values[7].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VSI_FORMAT_CONFIGURATION_TABLE].values[7].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VSI_FORMAT_CONFIGURATION_TABLE].values[7].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPF_VSI_FORMAT_CONFIGURATION_TABLE_t, MY_MAC_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VSI_FORMAT_CONFIGURATION_TABLE].values[8].name = "MY_MAC_PREFIX_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VSI_FORMAT_CONFIGURATION_TABLE].values[8].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VSI_FORMAT_CONFIGURATION_TABLE].values[8].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VSI_FORMAT_CONFIGURATION_TABLE].values[8].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPF_VSI_FORMAT_CONFIGURATION_TABLE_t, MY_MAC_PREFIX_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VSI_FORMAT_CONFIGURATION_TABLE].values[9].name = "MY_MAC_PREFIX_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VSI_FORMAT_CONFIGURATION_TABLE].values[9].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VSI_FORMAT_CONFIGURATION_TABLE].values[9].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VSI_FORMAT_CONFIGURATION_TABLE].values[9].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPF_VSI_FORMAT_CONFIGURATION_TABLE_t, MY_MAC_PREFIX_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VSI_FORMAT_CONFIGURATION_TABLE].values[10].name = "PROPAGATION_PROFILE_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VSI_FORMAT_CONFIGURATION_TABLE].values[10].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VSI_FORMAT_CONFIGURATION_TABLE].values[10].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VSI_FORMAT_CONFIGURATION_TABLE].values[10].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPF_VSI_FORMAT_CONFIGURATION_TABLE_t, PROPAGATION_PROFILE_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VSI_FORMAT_CONFIGURATION_TABLE].values[11].name = "PROPAGATION_PROFILE_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VSI_FORMAT_CONFIGURATION_TABLE].values[11].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VSI_FORMAT_CONFIGURATION_TABLE].values[11].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VSI_FORMAT_CONFIGURATION_TABLE].values[11].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPF_VSI_FORMAT_CONFIGURATION_TABLE_t, PROPAGATION_PROFILE_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VSI_FORMAT_CONFIGURATION_TABLE].values[12].name = "QOS_PROFILE_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VSI_FORMAT_CONFIGURATION_TABLE].values[12].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VSI_FORMAT_CONFIGURATION_TABLE].values[12].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VSI_FORMAT_CONFIGURATION_TABLE].values[12].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPF_VSI_FORMAT_CONFIGURATION_TABLE_t, QOS_PROFILE_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VSI_FORMAT_CONFIGURATION_TABLE].values[13].name = "QOS_PROFILE_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VSI_FORMAT_CONFIGURATION_TABLE].values[13].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VSI_FORMAT_CONFIGURATION_TABLE].values[13].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VSI_FORMAT_CONFIGURATION_TABLE].values[13].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPF_VSI_FORMAT_CONFIGURATION_TABLE_t, QOS_PROFILE_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VSI_FORMAT_CONFIGURATION_TABLE].values[14].name = "STAT_OBJ_CMD_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VSI_FORMAT_CONFIGURATION_TABLE].values[14].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VSI_FORMAT_CONFIGURATION_TABLE].values[14].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VSI_FORMAT_CONFIGURATION_TABLE].values[14].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPF_VSI_FORMAT_CONFIGURATION_TABLE_t, STAT_OBJ_CMD_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VSI_FORMAT_CONFIGURATION_TABLE].values[15].name = "STAT_OBJ_CMD_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VSI_FORMAT_CONFIGURATION_TABLE].values[15].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VSI_FORMAT_CONFIGURATION_TABLE].values[15].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VSI_FORMAT_CONFIGURATION_TABLE].values[15].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPF_VSI_FORMAT_CONFIGURATION_TABLE_t, STAT_OBJ_CMD_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VSI_FORMAT_CONFIGURATION_TABLE].values[16].name = "STAT_OBJ_ID_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VSI_FORMAT_CONFIGURATION_TABLE].values[16].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VSI_FORMAT_CONFIGURATION_TABLE].values[16].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VSI_FORMAT_CONFIGURATION_TABLE].values[16].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPF_VSI_FORMAT_CONFIGURATION_TABLE_t, STAT_OBJ_ID_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VSI_FORMAT_CONFIGURATION_TABLE].values[17].name = "STAT_OBJ_ID_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VSI_FORMAT_CONFIGURATION_TABLE].values[17].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VSI_FORMAT_CONFIGURATION_TABLE].values[17].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VSI_FORMAT_CONFIGURATION_TABLE].values[17].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPF_VSI_FORMAT_CONFIGURATION_TABLE_t, STAT_OBJ_ID_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VSI_FORMAT_CONFIGURATION_TABLE].values[18].name = "TOPOLOGY_ID_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VSI_FORMAT_CONFIGURATION_TABLE].values[18].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VSI_FORMAT_CONFIGURATION_TABLE].values[18].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VSI_FORMAT_CONFIGURATION_TABLE].values[18].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPF_VSI_FORMAT_CONFIGURATION_TABLE_t, TOPOLOGY_ID_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VSI_FORMAT_CONFIGURATION_TABLE].values[19].name = "TOPOLOGY_ID_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VSI_FORMAT_CONFIGURATION_TABLE].values[19].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VSI_FORMAT_CONFIGURATION_TABLE].values[19].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VSI_FORMAT_CONFIGURATION_TABLE].values[19].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPF_VSI_FORMAT_CONFIGURATION_TABLE_t, TOPOLOGY_ID_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VSI_FORMAT_CONFIGURATION_TABLE].values[20].name = "VRF_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VSI_FORMAT_CONFIGURATION_TABLE].values[20].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VSI_FORMAT_CONFIGURATION_TABLE].values[20].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VSI_FORMAT_CONFIGURATION_TABLE].values[20].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPF_VSI_FORMAT_CONFIGURATION_TABLE_t, VRF_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VSI_FORMAT_CONFIGURATION_TABLE].values[21].name = "VRF_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VSI_FORMAT_CONFIGURATION_TABLE].values[21].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VSI_FORMAT_CONFIGURATION_TABLE].values[21].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VSI_FORMAT_CONFIGURATION_TABLE].values[21].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPF_VSI_FORMAT_CONFIGURATION_TABLE_t, VRF_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VSI_FORMAT_CONFIGURATION_TABLE].values[22].name = "VRID_BITMAP_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VSI_FORMAT_CONFIGURATION_TABLE].values[22].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VSI_FORMAT_CONFIGURATION_TABLE].values[22].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VSI_FORMAT_CONFIGURATION_TABLE].values[22].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPF_VSI_FORMAT_CONFIGURATION_TABLE_t, VRID_BITMAP_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VSI_FORMAT_CONFIGURATION_TABLE].values[23].name = "VRID_BITMAP_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VSI_FORMAT_CONFIGURATION_TABLE].values[23].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VSI_FORMAT_CONFIGURATION_TABLE].values[23].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VSI_FORMAT_CONFIGURATION_TABLE].values[23].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPF_VSI_FORMAT_CONFIGURATION_TABLE_t, VRID_BITMAP_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VSI_FORMAT_CONFIGURATION_TABLE].values[24].name = "VSI_PROFILE_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VSI_FORMAT_CONFIGURATION_TABLE].values[24].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VSI_FORMAT_CONFIGURATION_TABLE].values[24].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VSI_FORMAT_CONFIGURATION_TABLE].values[24].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPF_VSI_FORMAT_CONFIGURATION_TABLE_t, VSI_PROFILE_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VSI_FORMAT_CONFIGURATION_TABLE].values[25].name = "VSI_PROFILE_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VSI_FORMAT_CONFIGURATION_TABLE].values[25].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VSI_FORMAT_CONFIGURATION_TABLE].values[25].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VSI_FORMAT_CONFIGURATION_TABLE].values[25].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPF_VSI_FORMAT_CONFIGURATION_TABLE_t, VSI_PROFILE_CONFIG_valid);
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].name = "IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].flags |= DNXC_DATA_F_TABLE;
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].size_of_values = sizeof(dnx_data_dnx2_arr_formats_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array_t);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].entry_get = dnx_data_dnx2_arr_formats_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array_entry_str_get;

        
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].nof_keys = 2;
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].keys[0].name = "table_index";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].keys[0].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].keys[1].name = "index";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].keys[1].doc = "";

        
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].nof_values = 64;
        DNXC_DATA_ALLOC(submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values, dnxc_data_value_t, submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].nof_values, "_dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array table values");
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[0].name = "valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[0].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[0].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[0].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array_t, valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[1].name = "doc";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[1].type = "char *";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[1].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[1].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array_t, doc);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[2].name = "ACTION_PROFILE_IDX_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[2].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[2].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[2].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array_t, ACTION_PROFILE_IDX_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[3].name = "ACTION_PROFILE_IDX_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[3].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[3].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[3].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array_t, ACTION_PROFILE_IDX_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[4].name = "DESTINATION_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[4].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[4].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[4].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array_t, DESTINATION_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[5].name = "DESTINATION_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[5].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[5].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[5].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array_t, DESTINATION_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[6].name = "ECN_MAPPING_PROFILE_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[6].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[6].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[6].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array_t, ECN_MAPPING_PROFILE_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[7].name = "ECN_MAPPING_PROFILE_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[7].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[7].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[7].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array_t, ECN_MAPPING_PROFILE_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[8].name = "EEI_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[8].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[8].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[8].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array_t, EEI_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[9].name = "EEI_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[9].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[9].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[9].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array_t, EEI_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[10].name = "FORWARD_DOMAIN_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[10].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[10].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[10].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array_t, FORWARD_DOMAIN_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[11].name = "FORWARD_DOMAIN_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[11].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[11].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[11].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array_t, FORWARD_DOMAIN_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[12].name = "FORWARD_DOMAIN_ASSIGNMENT_MODE_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[12].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[12].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[12].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array_t, FORWARD_DOMAIN_ASSIGNMENT_MODE_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[13].name = "FORWARD_DOMAIN_ASSIGNMENT_MODE_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[13].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[13].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[13].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array_t, FORWARD_DOMAIN_ASSIGNMENT_MODE_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[14].name = "SYS_INLIF_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[14].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[14].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[14].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array_t, SYS_INLIF_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[15].name = "SYS_INLIF_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[15].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[15].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[15].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array_t, SYS_INLIF_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[16].name = "OUT_LIF_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[16].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[16].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[16].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array_t, OUT_LIF_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[17].name = "OUT_LIF_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[17].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[17].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[17].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array_t, OUT_LIF_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[18].name = "LIF_PROFILE_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[18].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[18].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[18].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array_t, LIF_PROFILE_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[19].name = "LIF_PROFILE_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[19].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[19].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[19].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array_t, LIF_PROFILE_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[20].name = "LEARN_EN_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[20].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[20].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[20].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array_t, LEARN_EN_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[21].name = "LEARN_EN_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[21].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[21].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[21].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array_t, LEARN_EN_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[22].name = "LEARN_INFO_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[22].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[22].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[22].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array_t, LEARN_INFO_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[23].name = "LEARN_INFO_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[23].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[23].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[23].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array_t, LEARN_INFO_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[24].name = "LEARN_PAYLOAD_CONTEXT_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[24].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[24].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[24].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array_t, LEARN_PAYLOAD_CONTEXT_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[25].name = "LEARN_PAYLOAD_CONTEXT_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[25].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[25].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[25].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array_t, LEARN_PAYLOAD_CONTEXT_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[26].name = "LIF_GENERIC_DATA_0_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[26].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[26].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[26].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array_t, LIF_GENERIC_DATA_0_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[27].name = "LIF_GENERIC_DATA_0_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[27].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[27].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[27].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array_t, LIF_GENERIC_DATA_0_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[28].name = "LIF_GENERIC_DATA_1_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[28].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[28].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[28].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array_t, LIF_GENERIC_DATA_1_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[29].name = "LIF_GENERIC_DATA_1_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[29].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[29].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[29].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array_t, LIF_GENERIC_DATA_1_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[30].name = "PROTECTION_PTR_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[30].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[30].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[30].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array_t, PROTECTION_PTR_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[31].name = "PROTECTION_PTR_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[31].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[31].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[31].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array_t, PROTECTION_PTR_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[32].name = "NEXT_LAYER_NETWORK_DOMAIN_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[32].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[32].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[32].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array_t, NEXT_LAYER_NETWORK_DOMAIN_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[33].name = "NEXT_LAYER_NETWORK_DOMAIN_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[33].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[33].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[33].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array_t, NEXT_LAYER_NETWORK_DOMAIN_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[34].name = "NEXT_PARSER_CONTEXT_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[34].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[34].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[34].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array_t, NEXT_PARSER_CONTEXT_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[35].name = "NEXT_PARSER_CONTEXT_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[35].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[35].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[35].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array_t, NEXT_PARSER_CONTEXT_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[36].name = "OAM_LIF_SET_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[36].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[36].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[36].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array_t, OAM_LIF_SET_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[37].name = "OAM_LIF_SET_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[37].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[37].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[37].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array_t, OAM_LIF_SET_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[38].name = "PROPAGATION_PROFILE_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[38].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[38].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[38].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array_t, PROPAGATION_PROFILE_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[39].name = "PROPAGATION_PROFILE_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[39].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[39].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[39].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array_t, PROPAGATION_PROFILE_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[40].name = "PROTECTION_PATH_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[40].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[40].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[40].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array_t, PROTECTION_PATH_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[41].name = "PROTECTION_PATH_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[41].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[41].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[41].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array_t, PROTECTION_PATH_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[42].name = "QOS_PROFILE_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[42].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[42].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[42].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array_t, QOS_PROFILE_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[43].name = "QOS_PROFILE_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[43].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[43].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[43].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array_t, QOS_PROFILE_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[44].name = "RESEREVED";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[44].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[44].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[44].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array_t, RESEREVED);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[45].name = "RESEREVED_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[45].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[45].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[45].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array_t, RESEREVED_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[46].name = "SERVICE_TYPE_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[46].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[46].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[46].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array_t, SERVICE_TYPE_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[47].name = "SERVICE_TYPE_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[47].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[47].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[47].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array_t, SERVICE_TYPE_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[48].name = "STAT_OBJ_CMD_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[48].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[48].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[48].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array_t, STAT_OBJ_CMD_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[49].name = "STAT_OBJ_CMD_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[49].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[49].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[49].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array_t, STAT_OBJ_CMD_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[50].name = "STAT_OBJ_ID_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[50].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[50].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[50].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array_t, STAT_OBJ_ID_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[51].name = "STAT_OBJ_ID_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[51].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[51].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[51].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array_t, STAT_OBJ_ID_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[52].name = "TERMINATION_TYPE_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[52].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[52].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[52].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array_t, TERMINATION_TYPE_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[53].name = "TERMINATION_TYPE_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[53].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[53].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[53].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array_t, TERMINATION_TYPE_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[54].name = "VLAN_EDIT_PCP_DEI_PROFILE_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[54].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[54].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[54].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array_t, VLAN_EDIT_PCP_DEI_PROFILE_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[55].name = "VLAN_EDIT_PCP_DEI_PROFILE_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[55].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[55].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[55].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array_t, VLAN_EDIT_PCP_DEI_PROFILE_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[56].name = "VLAN_EDIT_PROFILE_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[56].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[56].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[56].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array_t, VLAN_EDIT_PROFILE_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[57].name = "VLAN_EDIT_PROFILE_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[57].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[57].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[57].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array_t, VLAN_EDIT_PROFILE_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[58].name = "VLAN_EDIT_VID_1_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[58].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[58].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[58].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array_t, VLAN_EDIT_VID_1_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[59].name = "VLAN_EDIT_VID_1_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[59].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[59].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[59].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array_t, VLAN_EDIT_VID_1_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[60].name = "VLAN_EDIT_VID_2_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[60].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[60].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[60].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array_t, VLAN_EDIT_VID_2_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[61].name = "VLAN_EDIT_VID_2_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[61].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[61].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[61].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array_t, VLAN_EDIT_VID_2_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[62].name = "VLAN_MEMBER_IF_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[62].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[62].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[62].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array_t, VLAN_MEMBER_IF_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[63].name = "VLAN_MEMBER_IF_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[63].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[63].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array].values[63].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array_t, VLAN_MEMBER_IF_CONFIG_valid);
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].name = "IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].flags |= DNXC_DATA_F_TABLE;
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].size_of_values = sizeof(dnx_data_dnx2_arr_formats_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array_t);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].entry_get = dnx_data_dnx2_arr_formats_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array_entry_str_get;

        
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].nof_keys = 2;
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].keys[0].name = "table_index";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].keys[0].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].keys[1].name = "index";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].keys[1].doc = "";

        
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].nof_values = 64;
        DNXC_DATA_ALLOC(submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values, dnxc_data_value_t, submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].nof_values, "_dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array table values");
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[0].name = "valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[0].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[0].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[0].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array_t, valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[1].name = "doc";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[1].type = "char *";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[1].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[1].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array_t, doc);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[2].name = "ACTION_PROFILE_IDX_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[2].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[2].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[2].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array_t, ACTION_PROFILE_IDX_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[3].name = "ACTION_PROFILE_IDX_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[3].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[3].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[3].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array_t, ACTION_PROFILE_IDX_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[4].name = "DESTINATION_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[4].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[4].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[4].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array_t, DESTINATION_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[5].name = "DESTINATION_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[5].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[5].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[5].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array_t, DESTINATION_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[6].name = "ECN_MAPPING_PROFILE_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[6].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[6].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[6].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array_t, ECN_MAPPING_PROFILE_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[7].name = "ECN_MAPPING_PROFILE_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[7].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[7].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[7].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array_t, ECN_MAPPING_PROFILE_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[8].name = "EEI_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[8].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[8].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[8].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array_t, EEI_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[9].name = "EEI_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[9].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[9].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[9].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array_t, EEI_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[10].name = "FORWARD_DOMAIN_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[10].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[10].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[10].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array_t, FORWARD_DOMAIN_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[11].name = "FORWARD_DOMAIN_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[11].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[11].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[11].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array_t, FORWARD_DOMAIN_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[12].name = "FORWARD_DOMAIN_ASSIGNMENT_MODE_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[12].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[12].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[12].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array_t, FORWARD_DOMAIN_ASSIGNMENT_MODE_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[13].name = "FORWARD_DOMAIN_ASSIGNMENT_MODE_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[13].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[13].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[13].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array_t, FORWARD_DOMAIN_ASSIGNMENT_MODE_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[14].name = "SYS_INLIF_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[14].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[14].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[14].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array_t, SYS_INLIF_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[15].name = "SYS_INLIF_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[15].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[15].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[15].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array_t, SYS_INLIF_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[16].name = "OUT_LIF_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[16].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[16].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[16].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array_t, OUT_LIF_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[17].name = "OUT_LIF_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[17].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[17].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[17].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array_t, OUT_LIF_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[18].name = "LIF_PROFILE_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[18].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[18].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[18].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array_t, LIF_PROFILE_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[19].name = "LIF_PROFILE_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[19].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[19].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[19].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array_t, LIF_PROFILE_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[20].name = "LEARN_EN_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[20].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[20].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[20].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array_t, LEARN_EN_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[21].name = "LEARN_EN_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[21].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[21].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[21].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array_t, LEARN_EN_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[22].name = "LEARN_INFO_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[22].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[22].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[22].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array_t, LEARN_INFO_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[23].name = "LEARN_INFO_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[23].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[23].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[23].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array_t, LEARN_INFO_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[24].name = "LEARN_PAYLOAD_CONTEXT_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[24].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[24].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[24].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array_t, LEARN_PAYLOAD_CONTEXT_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[25].name = "LEARN_PAYLOAD_CONTEXT_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[25].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[25].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[25].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array_t, LEARN_PAYLOAD_CONTEXT_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[26].name = "LIF_GENERIC_DATA_0_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[26].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[26].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[26].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array_t, LIF_GENERIC_DATA_0_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[27].name = "LIF_GENERIC_DATA_0_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[27].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[27].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[27].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array_t, LIF_GENERIC_DATA_0_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[28].name = "LIF_GENERIC_DATA_1_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[28].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[28].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[28].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array_t, LIF_GENERIC_DATA_1_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[29].name = "LIF_GENERIC_DATA_1_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[29].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[29].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[29].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array_t, LIF_GENERIC_DATA_1_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[30].name = "PROTECTION_PTR_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[30].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[30].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[30].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array_t, PROTECTION_PTR_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[31].name = "PROTECTION_PTR_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[31].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[31].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[31].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array_t, PROTECTION_PTR_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[32].name = "NEXT_LAYER_NETWORK_DOMAIN_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[32].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[32].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[32].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array_t, NEXT_LAYER_NETWORK_DOMAIN_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[33].name = "NEXT_LAYER_NETWORK_DOMAIN_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[33].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[33].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[33].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array_t, NEXT_LAYER_NETWORK_DOMAIN_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[34].name = "NEXT_PARSER_CONTEXT_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[34].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[34].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[34].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array_t, NEXT_PARSER_CONTEXT_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[35].name = "NEXT_PARSER_CONTEXT_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[35].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[35].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[35].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array_t, NEXT_PARSER_CONTEXT_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[36].name = "OAM_LIF_SET_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[36].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[36].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[36].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array_t, OAM_LIF_SET_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[37].name = "OAM_LIF_SET_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[37].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[37].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[37].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array_t, OAM_LIF_SET_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[38].name = "PROPAGATION_PROFILE_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[38].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[38].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[38].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array_t, PROPAGATION_PROFILE_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[39].name = "PROPAGATION_PROFILE_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[39].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[39].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[39].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array_t, PROPAGATION_PROFILE_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[40].name = "PROTECTION_PATH_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[40].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[40].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[40].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array_t, PROTECTION_PATH_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[41].name = "PROTECTION_PATH_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[41].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[41].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[41].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array_t, PROTECTION_PATH_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[42].name = "QOS_PROFILE_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[42].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[42].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[42].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array_t, QOS_PROFILE_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[43].name = "QOS_PROFILE_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[43].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[43].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[43].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array_t, QOS_PROFILE_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[44].name = "RESEREVED";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[44].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[44].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[44].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array_t, RESEREVED);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[45].name = "RESEREVED_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[45].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[45].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[45].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array_t, RESEREVED_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[46].name = "SERVICE_TYPE_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[46].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[46].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[46].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array_t, SERVICE_TYPE_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[47].name = "SERVICE_TYPE_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[47].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[47].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[47].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array_t, SERVICE_TYPE_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[48].name = "STAT_OBJ_CMD_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[48].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[48].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[48].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array_t, STAT_OBJ_CMD_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[49].name = "STAT_OBJ_CMD_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[49].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[49].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[49].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array_t, STAT_OBJ_CMD_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[50].name = "STAT_OBJ_ID_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[50].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[50].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[50].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array_t, STAT_OBJ_ID_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[51].name = "STAT_OBJ_ID_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[51].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[51].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[51].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array_t, STAT_OBJ_ID_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[52].name = "TERMINATION_TYPE_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[52].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[52].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[52].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array_t, TERMINATION_TYPE_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[53].name = "TERMINATION_TYPE_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[53].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[53].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[53].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array_t, TERMINATION_TYPE_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[54].name = "VLAN_EDIT_PCP_DEI_PROFILE_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[54].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[54].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[54].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array_t, VLAN_EDIT_PCP_DEI_PROFILE_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[55].name = "VLAN_EDIT_PCP_DEI_PROFILE_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[55].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[55].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[55].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array_t, VLAN_EDIT_PCP_DEI_PROFILE_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[56].name = "VLAN_EDIT_PROFILE_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[56].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[56].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[56].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array_t, VLAN_EDIT_PROFILE_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[57].name = "VLAN_EDIT_PROFILE_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[57].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[57].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[57].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array_t, VLAN_EDIT_PROFILE_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[58].name = "VLAN_EDIT_VID_1_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[58].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[58].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[58].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array_t, VLAN_EDIT_VID_1_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[59].name = "VLAN_EDIT_VID_1_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[59].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[59].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[59].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array_t, VLAN_EDIT_VID_1_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[60].name = "VLAN_EDIT_VID_2_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[60].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[60].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[60].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array_t, VLAN_EDIT_VID_2_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[61].name = "VLAN_EDIT_VID_2_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[61].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[61].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[61].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array_t, VLAN_EDIT_VID_2_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[62].name = "VLAN_MEMBER_IF_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[62].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[62].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[62].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array_t, VLAN_MEMBER_IF_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[63].name = "VLAN_MEMBER_IF_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[63].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[63].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array].values[63].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array_t, VLAN_MEMBER_IF_CONFIG_valid);
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_LEARN_ARR_CONFIGURATION_TABLE].name = "IPPD_LEARN_ARR_CONFIGURATION_TABLE";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_LEARN_ARR_CONFIGURATION_TABLE].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_LEARN_ARR_CONFIGURATION_TABLE].flags |= DNXC_DATA_F_TABLE;
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_LEARN_ARR_CONFIGURATION_TABLE].size_of_values = sizeof(dnx_data_dnx2_arr_formats_IPPD_LEARN_ARR_CONFIGURATION_TABLE_t);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_LEARN_ARR_CONFIGURATION_TABLE].entry_get = dnx_data_dnx2_arr_formats_IPPD_LEARN_ARR_CONFIGURATION_TABLE_entry_str_get;

        
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_LEARN_ARR_CONFIGURATION_TABLE].nof_keys = 1;
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_LEARN_ARR_CONFIGURATION_TABLE].keys[0].name = "index";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_LEARN_ARR_CONFIGURATION_TABLE].keys[0].doc = "";

        
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_LEARN_ARR_CONFIGURATION_TABLE].nof_values = 8;
        DNXC_DATA_ALLOC(submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_LEARN_ARR_CONFIGURATION_TABLE].values, dnxc_data_value_t, submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_LEARN_ARR_CONFIGURATION_TABLE].nof_values, "_dnx_data_dnx2_arr_formats_table_IPPD_LEARN_ARR_CONFIGURATION_TABLE table values");
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_LEARN_ARR_CONFIGURATION_TABLE].values[0].name = "valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_LEARN_ARR_CONFIGURATION_TABLE].values[0].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_LEARN_ARR_CONFIGURATION_TABLE].values[0].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_LEARN_ARR_CONFIGURATION_TABLE].values[0].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPD_LEARN_ARR_CONFIGURATION_TABLE_t, valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_LEARN_ARR_CONFIGURATION_TABLE].values[1].name = "doc";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_LEARN_ARR_CONFIGURATION_TABLE].values[1].type = "char *";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_LEARN_ARR_CONFIGURATION_TABLE].values[1].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_LEARN_ARR_CONFIGURATION_TABLE].values[1].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPD_LEARN_ARR_CONFIGURATION_TABLE_t, doc);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_LEARN_ARR_CONFIGURATION_TABLE].values[2].name = "DESTINATION_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_LEARN_ARR_CONFIGURATION_TABLE].values[2].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_LEARN_ARR_CONFIGURATION_TABLE].values[2].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_LEARN_ARR_CONFIGURATION_TABLE].values[2].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPD_LEARN_ARR_CONFIGURATION_TABLE_t, DESTINATION_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_LEARN_ARR_CONFIGURATION_TABLE].values[3].name = "DESTINATION_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_LEARN_ARR_CONFIGURATION_TABLE].values[3].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_LEARN_ARR_CONFIGURATION_TABLE].values[3].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_LEARN_ARR_CONFIGURATION_TABLE].values[3].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPD_LEARN_ARR_CONFIGURATION_TABLE_t, DESTINATION_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_LEARN_ARR_CONFIGURATION_TABLE].values[4].name = "EEI_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_LEARN_ARR_CONFIGURATION_TABLE].values[4].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_LEARN_ARR_CONFIGURATION_TABLE].values[4].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_LEARN_ARR_CONFIGURATION_TABLE].values[4].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPD_LEARN_ARR_CONFIGURATION_TABLE_t, EEI_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_LEARN_ARR_CONFIGURATION_TABLE].values[5].name = "EEI_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_LEARN_ARR_CONFIGURATION_TABLE].values[5].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_LEARN_ARR_CONFIGURATION_TABLE].values[5].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_LEARN_ARR_CONFIGURATION_TABLE].values[5].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPD_LEARN_ARR_CONFIGURATION_TABLE_t, EEI_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_LEARN_ARR_CONFIGURATION_TABLE].values[6].name = "OUTLIF_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_LEARN_ARR_CONFIGURATION_TABLE].values[6].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_LEARN_ARR_CONFIGURATION_TABLE].values[6].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_LEARN_ARR_CONFIGURATION_TABLE].values[6].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPD_LEARN_ARR_CONFIGURATION_TABLE_t, OUTLIF_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_LEARN_ARR_CONFIGURATION_TABLE].values[7].name = "OUTLIF_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_LEARN_ARR_CONFIGURATION_TABLE].values[7].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_LEARN_ARR_CONFIGURATION_TABLE].values[7].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_IPPD_LEARN_ARR_CONFIGURATION_TABLE].values[7].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_IPPD_LEARN_ARR_CONFIGURATION_TABLE_t, OUTLIF_CONFIG_valid);
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_OLP_LEARN_ARR_CONFIGURATION_TABLE].name = "OLP_LEARN_ARR_CONFIGURATION_TABLE";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_OLP_LEARN_ARR_CONFIGURATION_TABLE].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_OLP_LEARN_ARR_CONFIGURATION_TABLE].flags |= DNXC_DATA_F_TABLE;
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_OLP_LEARN_ARR_CONFIGURATION_TABLE].size_of_values = sizeof(dnx_data_dnx2_arr_formats_OLP_LEARN_ARR_CONFIGURATION_TABLE_t);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_OLP_LEARN_ARR_CONFIGURATION_TABLE].entry_get = dnx_data_dnx2_arr_formats_OLP_LEARN_ARR_CONFIGURATION_TABLE_entry_str_get;

        
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_OLP_LEARN_ARR_CONFIGURATION_TABLE].nof_keys = 1;
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_OLP_LEARN_ARR_CONFIGURATION_TABLE].keys[0].name = "index";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_OLP_LEARN_ARR_CONFIGURATION_TABLE].keys[0].doc = "";

        
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_OLP_LEARN_ARR_CONFIGURATION_TABLE].nof_values = 8;
        DNXC_DATA_ALLOC(submodule_data->tables[dnx_data_dnx2_arr_formats_table_OLP_LEARN_ARR_CONFIGURATION_TABLE].values, dnxc_data_value_t, submodule_data->tables[dnx_data_dnx2_arr_formats_table_OLP_LEARN_ARR_CONFIGURATION_TABLE].nof_values, "_dnx_data_dnx2_arr_formats_table_OLP_LEARN_ARR_CONFIGURATION_TABLE table values");
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_OLP_LEARN_ARR_CONFIGURATION_TABLE].values[0].name = "valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_OLP_LEARN_ARR_CONFIGURATION_TABLE].values[0].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_OLP_LEARN_ARR_CONFIGURATION_TABLE].values[0].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_OLP_LEARN_ARR_CONFIGURATION_TABLE].values[0].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_OLP_LEARN_ARR_CONFIGURATION_TABLE_t, valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_OLP_LEARN_ARR_CONFIGURATION_TABLE].values[1].name = "doc";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_OLP_LEARN_ARR_CONFIGURATION_TABLE].values[1].type = "char *";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_OLP_LEARN_ARR_CONFIGURATION_TABLE].values[1].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_OLP_LEARN_ARR_CONFIGURATION_TABLE].values[1].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_OLP_LEARN_ARR_CONFIGURATION_TABLE_t, doc);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_OLP_LEARN_ARR_CONFIGURATION_TABLE].values[2].name = "DESTINATION_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_OLP_LEARN_ARR_CONFIGURATION_TABLE].values[2].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_OLP_LEARN_ARR_CONFIGURATION_TABLE].values[2].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_OLP_LEARN_ARR_CONFIGURATION_TABLE].values[2].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_OLP_LEARN_ARR_CONFIGURATION_TABLE_t, DESTINATION_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_OLP_LEARN_ARR_CONFIGURATION_TABLE].values[3].name = "DESTINATION_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_OLP_LEARN_ARR_CONFIGURATION_TABLE].values[3].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_OLP_LEARN_ARR_CONFIGURATION_TABLE].values[3].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_OLP_LEARN_ARR_CONFIGURATION_TABLE].values[3].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_OLP_LEARN_ARR_CONFIGURATION_TABLE_t, DESTINATION_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_OLP_LEARN_ARR_CONFIGURATION_TABLE].values[4].name = "EEI_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_OLP_LEARN_ARR_CONFIGURATION_TABLE].values[4].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_OLP_LEARN_ARR_CONFIGURATION_TABLE].values[4].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_OLP_LEARN_ARR_CONFIGURATION_TABLE].values[4].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_OLP_LEARN_ARR_CONFIGURATION_TABLE_t, EEI_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_OLP_LEARN_ARR_CONFIGURATION_TABLE].values[5].name = "EEI_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_OLP_LEARN_ARR_CONFIGURATION_TABLE].values[5].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_OLP_LEARN_ARR_CONFIGURATION_TABLE].values[5].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_OLP_LEARN_ARR_CONFIGURATION_TABLE].values[5].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_OLP_LEARN_ARR_CONFIGURATION_TABLE_t, EEI_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_OLP_LEARN_ARR_CONFIGURATION_TABLE].values[6].name = "OUTLIF_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_OLP_LEARN_ARR_CONFIGURATION_TABLE].values[6].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_OLP_LEARN_ARR_CONFIGURATION_TABLE].values[6].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_OLP_LEARN_ARR_CONFIGURATION_TABLE].values[6].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_OLP_LEARN_ARR_CONFIGURATION_TABLE_t, OUTLIF_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_OLP_LEARN_ARR_CONFIGURATION_TABLE].values[7].name = "OUTLIF_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_OLP_LEARN_ARR_CONFIGURATION_TABLE].values[7].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_OLP_LEARN_ARR_CONFIGURATION_TABLE].values[7].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_OLP_LEARN_ARR_CONFIGURATION_TABLE].values[7].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_OLP_LEARN_ARR_CONFIGURATION_TABLE_t, OUTLIF_CONFIG_valid);
    }

    if (soc_is(unit, DNX2_DEVICE))
    {
        
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ERPP_EGRESS_MCDB_FORMAT_CFG].name = "ERPP_EGRESS_MCDB_FORMAT_CFG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ERPP_EGRESS_MCDB_FORMAT_CFG].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ERPP_EGRESS_MCDB_FORMAT_CFG].flags |= DNXC_DATA_F_TABLE;
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ERPP_EGRESS_MCDB_FORMAT_CFG].size_of_values = sizeof(dnx_data_dnx2_arr_formats_ERPP_EGRESS_MCDB_FORMAT_CFG_t);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ERPP_EGRESS_MCDB_FORMAT_CFG].entry_get = dnx_data_dnx2_arr_formats_ERPP_EGRESS_MCDB_FORMAT_CFG_entry_str_get;

        
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ERPP_EGRESS_MCDB_FORMAT_CFG].nof_keys = 1;
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ERPP_EGRESS_MCDB_FORMAT_CFG].keys[0].name = "index";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ERPP_EGRESS_MCDB_FORMAT_CFG].keys[0].doc = "";

        
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ERPP_EGRESS_MCDB_FORMAT_CFG].nof_values = 8;
        DNXC_DATA_ALLOC(submodule_data->tables[dnx_data_dnx2_arr_formats_table_ERPP_EGRESS_MCDB_FORMAT_CFG].values, dnxc_data_value_t, submodule_data->tables[dnx_data_dnx2_arr_formats_table_ERPP_EGRESS_MCDB_FORMAT_CFG].nof_values, "_dnx_data_dnx2_arr_formats_table_ERPP_EGRESS_MCDB_FORMAT_CFG table values");
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ERPP_EGRESS_MCDB_FORMAT_CFG].values[0].name = "valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ERPP_EGRESS_MCDB_FORMAT_CFG].values[0].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ERPP_EGRESS_MCDB_FORMAT_CFG].values[0].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ERPP_EGRESS_MCDB_FORMAT_CFG].values[0].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ERPP_EGRESS_MCDB_FORMAT_CFG_t, valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ERPP_EGRESS_MCDB_FORMAT_CFG].values[1].name = "doc";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ERPP_EGRESS_MCDB_FORMAT_CFG].values[1].type = "char *";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ERPP_EGRESS_MCDB_FORMAT_CFG].values[1].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ERPP_EGRESS_MCDB_FORMAT_CFG].values[1].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ERPP_EGRESS_MCDB_FORMAT_CFG_t, doc);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ERPP_EGRESS_MCDB_FORMAT_CFG].values[2].name = "MCDB_OUTLIF_0_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ERPP_EGRESS_MCDB_FORMAT_CFG].values[2].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ERPP_EGRESS_MCDB_FORMAT_CFG].values[2].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ERPP_EGRESS_MCDB_FORMAT_CFG].values[2].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ERPP_EGRESS_MCDB_FORMAT_CFG_t, MCDB_OUTLIF_0_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ERPP_EGRESS_MCDB_FORMAT_CFG].values[3].name = "MCDB_OUTLIF_0_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ERPP_EGRESS_MCDB_FORMAT_CFG].values[3].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ERPP_EGRESS_MCDB_FORMAT_CFG].values[3].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ERPP_EGRESS_MCDB_FORMAT_CFG].values[3].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ERPP_EGRESS_MCDB_FORMAT_CFG_t, MCDB_OUTLIF_0_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ERPP_EGRESS_MCDB_FORMAT_CFG].values[4].name = "MCDB_OUTLIF_1_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ERPP_EGRESS_MCDB_FORMAT_CFG].values[4].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ERPP_EGRESS_MCDB_FORMAT_CFG].values[4].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ERPP_EGRESS_MCDB_FORMAT_CFG].values[4].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ERPP_EGRESS_MCDB_FORMAT_CFG_t, MCDB_OUTLIF_1_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ERPP_EGRESS_MCDB_FORMAT_CFG].values[5].name = "MCDB_OUTLIF_1_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ERPP_EGRESS_MCDB_FORMAT_CFG].values[5].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ERPP_EGRESS_MCDB_FORMAT_CFG].values[5].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ERPP_EGRESS_MCDB_FORMAT_CFG].values[5].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ERPP_EGRESS_MCDB_FORMAT_CFG_t, MCDB_OUTLIF_1_CONFIG_valid);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ERPP_EGRESS_MCDB_FORMAT_CFG].values[6].name = "MCDB_OUTLIF_2_CONFIG";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ERPP_EGRESS_MCDB_FORMAT_CFG].values[6].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ERPP_EGRESS_MCDB_FORMAT_CFG].values[6].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ERPP_EGRESS_MCDB_FORMAT_CFG].values[6].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ERPP_EGRESS_MCDB_FORMAT_CFG_t, MCDB_OUTLIF_2_CONFIG);
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ERPP_EGRESS_MCDB_FORMAT_CFG].values[7].name = "MCDB_OUTLIF_2_CONFIG_valid";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ERPP_EGRESS_MCDB_FORMAT_CFG].values[7].type = "uint32";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ERPP_EGRESS_MCDB_FORMAT_CFG].values[7].doc = "";
        submodule_data->tables[dnx_data_dnx2_arr_formats_table_ERPP_EGRESS_MCDB_FORMAT_CFG].values[7].offset = UTILEX_OFFSETOF(dnx_data_dnx2_arr_formats_ERPP_EGRESS_MCDB_FORMAT_CFG_t, MCDB_OUTLIF_2_CONFIG_valid);
    }


exit:
    SHR_FUNC_EXIT;
}


int
dnx_data_dnx2_arr_formats_feature_get(
    int unit,
    dnx_data_dnx2_arr_formats_feature_e feature)
{
    return dnxc_data_mgmt_feature_data_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_formats, feature);
}




const dnx_data_dnx2_arr_formats_files_t *
dnx_data_dnx2_arr_formats_files_get(
    int unit)
{
    char *data;
    dnxc_data_table_t *table;

    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "files", "DNX2");
    }
    
    table = dnxc_data_mgmt_table_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_formats, dnx_data_dnx2_arr_formats_table_files);
    
    data = dnxc_data_mgmt_table_data_get(unit, table, 0, 0);
    return (const dnx_data_dnx2_arr_formats_files_t *) data;

}

const dnx_data_dnx2_arr_formats_MACT_AGE_PROFILE_ARR_CFG_t *
dnx_data_dnx2_arr_formats_MACT_AGE_PROFILE_ARR_CFG_get(
    int unit,
    int index)
{
    char *data;
    dnxc_data_table_t *table;

    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "MACT_AGE_PROFILE_ARR_CFG", "DNX2");
    }
    
    table = dnxc_data_mgmt_table_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_formats, dnx_data_dnx2_arr_formats_table_MACT_AGE_PROFILE_ARR_CFG);
    
    data = dnxc_data_mgmt_table_data_get(unit, table, index, 0);
    return (const dnx_data_dnx2_arr_formats_MACT_AGE_PROFILE_ARR_CFG_t *) data;

}

const dnx_data_dnx2_arr_formats_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE_t *
dnx_data_dnx2_arr_formats_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE_get(
    int unit,
    int index)
{
    char *data;
    dnxc_data_table_t *table;

    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE", "DNX2");
    }
    
    table = dnxc_data_mgmt_table_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_formats, dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE);
    
    data = dnxc_data_mgmt_table_data_get(unit, table, index, 0);
    return (const dnx_data_dnx2_arr_formats_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE_t *) data;

}

const dnx_data_dnx2_arr_formats_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE_t *
dnx_data_dnx2_arr_formats_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE_get(
    int unit,
    int index)
{
    char *data;
    dnxc_data_table_t *table;

    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE", "DNX2");
    }
    
    table = dnxc_data_mgmt_table_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_formats, dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE);
    
    data = dnxc_data_mgmt_table_data_get(unit, table, index, 0);
    return (const dnx_data_dnx2_arr_formats_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE_t *) data;

}

const dnx_data_dnx2_arr_formats_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE_t *
dnx_data_dnx2_arr_formats_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE_get(
    int unit,
    int index)
{
    char *data;
    dnxc_data_table_t *table;

    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE", "DNX2");
    }
    
    table = dnxc_data_mgmt_table_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_formats, dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE);
    
    data = dnxc_data_mgmt_table_data_get(unit, table, index, 0);
    return (const dnx_data_dnx2_arr_formats_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE_t *) data;

}

const dnx_data_dnx2_arr_formats_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE_t *
dnx_data_dnx2_arr_formats_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE_get(
    int unit,
    int index)
{
    char *data;
    dnxc_data_table_t *table;

    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE", "DNX2");
    }
    
    table = dnxc_data_mgmt_table_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_formats, dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE);
    
    data = dnxc_data_mgmt_table_data_get(unit, table, index, 0);
    return (const dnx_data_dnx2_arr_formats_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE_t *) data;

}

const dnx_data_dnx2_arr_formats_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE_t *
dnx_data_dnx2_arr_formats_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE_get(
    int unit,
    int index)
{
    char *data;
    dnxc_data_table_t *table;

    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE", "DNX2");
    }
    
    table = dnxc_data_mgmt_table_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_formats, dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE);
    
    data = dnxc_data_mgmt_table_data_get(unit, table, index, 0);
    return (const dnx_data_dnx2_arr_formats_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE_t *) data;

}

const dnx_data_dnx2_arr_formats_ETPPB_ENC_FORMAT_CONFIGURATION_TABLE_t *
dnx_data_dnx2_arr_formats_ETPPB_ENC_FORMAT_CONFIGURATION_TABLE_get(
    int unit,
    int index)
{
    char *data;
    dnxc_data_table_t *table;

    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "ETPPB_ENC_FORMAT_CONFIGURATION_TABLE", "DNX2");
    }
    
    table = dnxc_data_mgmt_table_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_formats, dnx_data_dnx2_arr_formats_table_ETPPB_ENC_FORMAT_CONFIGURATION_TABLE);
    
    data = dnxc_data_mgmt_table_data_get(unit, table, index, 0);
    return (const dnx_data_dnx2_arr_formats_ETPPB_ENC_FORMAT_CONFIGURATION_TABLE_t *) data;

}

const dnx_data_dnx2_arr_formats_ETPPC_ENC_FORMAT_CONFIGURATION_TABLE_t *
dnx_data_dnx2_arr_formats_ETPPC_ENC_FORMAT_CONFIGURATION_TABLE_get(
    int unit,
    int index)
{
    char *data;
    dnxc_data_table_t *table;

    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "ETPPC_ENC_FORMAT_CONFIGURATION_TABLE", "DNX2");
    }
    
    table = dnxc_data_mgmt_table_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_formats, dnx_data_dnx2_arr_formats_table_ETPPC_ENC_FORMAT_CONFIGURATION_TABLE);
    
    data = dnxc_data_mgmt_table_data_get(unit, table, index, 0);
    return (const dnx_data_dnx2_arr_formats_ETPPC_ENC_FORMAT_CONFIGURATION_TABLE_t *) data;

}

const dnx_data_dnx2_arr_formats_ETPPB_ENC_2_ARR_1_FORMAT_CONFIGURATION_TABLE_t *
dnx_data_dnx2_arr_formats_ETPPB_ENC_2_ARR_1_FORMAT_CONFIGURATION_TABLE_get(
    int unit,
    int index)
{
    char *data;
    dnxc_data_table_t *table;

    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "ETPPB_ENC_2_ARR_1_FORMAT_CONFIGURATION_TABLE", "DNX2");
    }
    
    table = dnxc_data_mgmt_table_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_formats, dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_1_FORMAT_CONFIGURATION_TABLE);
    
    data = dnxc_data_mgmt_table_data_get(unit, table, index, 0);
    return (const dnx_data_dnx2_arr_formats_ETPPB_ENC_2_ARR_1_FORMAT_CONFIGURATION_TABLE_t *) data;

}

const dnx_data_dnx2_arr_formats_ETPPB_ENC_3_ARR_1_FORMAT_CONFIGURATION_TABLE_t *
dnx_data_dnx2_arr_formats_ETPPB_ENC_3_ARR_1_FORMAT_CONFIGURATION_TABLE_get(
    int unit,
    int index)
{
    char *data;
    dnxc_data_table_t *table;

    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "ETPPB_ENC_3_ARR_1_FORMAT_CONFIGURATION_TABLE", "DNX2");
    }
    
    table = dnxc_data_mgmt_table_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_formats, dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_1_FORMAT_CONFIGURATION_TABLE);
    
    data = dnxc_data_mgmt_table_data_get(unit, table, index, 0);
    return (const dnx_data_dnx2_arr_formats_ETPPB_ENC_3_ARR_1_FORMAT_CONFIGURATION_TABLE_t *) data;

}

const dnx_data_dnx2_arr_formats_ETPPB_ENC_4_ARR_1_FORMAT_CONFIGURATION_TABLE_t *
dnx_data_dnx2_arr_formats_ETPPB_ENC_4_ARR_1_FORMAT_CONFIGURATION_TABLE_get(
    int unit,
    int index)
{
    char *data;
    dnxc_data_table_t *table;

    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "ETPPB_ENC_4_ARR_1_FORMAT_CONFIGURATION_TABLE", "DNX2");
    }
    
    table = dnxc_data_mgmt_table_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_formats, dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_1_FORMAT_CONFIGURATION_TABLE);
    
    data = dnxc_data_mgmt_table_data_get(unit, table, index, 0);
    return (const dnx_data_dnx2_arr_formats_ETPPB_ENC_4_ARR_1_FORMAT_CONFIGURATION_TABLE_t *) data;

}

const dnx_data_dnx2_arr_formats_ETPPB_ENC_5_ARR_1_FORMAT_CONFIGURATION_TABLE_t *
dnx_data_dnx2_arr_formats_ETPPB_ENC_5_ARR_1_FORMAT_CONFIGURATION_TABLE_get(
    int unit,
    int index)
{
    char *data;
    dnxc_data_table_t *table;

    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "ETPPB_ENC_5_ARR_1_FORMAT_CONFIGURATION_TABLE", "DNX2");
    }
    
    table = dnxc_data_mgmt_table_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_formats, dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_1_FORMAT_CONFIGURATION_TABLE);
    
    data = dnxc_data_mgmt_table_data_get(unit, table, index, 0);
    return (const dnx_data_dnx2_arr_formats_ETPPB_ENC_5_ARR_1_FORMAT_CONFIGURATION_TABLE_t *) data;

}

const dnx_data_dnx2_arr_formats_ETPPC_ENC_1_ARR_1_FORMAT_CONFIGURATION_TABLE_t *
dnx_data_dnx2_arr_formats_ETPPC_ENC_1_ARR_1_FORMAT_CONFIGURATION_TABLE_get(
    int unit,
    int index)
{
    char *data;
    dnxc_data_table_t *table;

    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "ETPPC_ENC_1_ARR_1_FORMAT_CONFIGURATION_TABLE", "DNX2");
    }
    
    table = dnxc_data_mgmt_table_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_formats, dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_1_FORMAT_CONFIGURATION_TABLE);
    
    data = dnxc_data_mgmt_table_data_get(unit, table, index, 0);
    return (const dnx_data_dnx2_arr_formats_ETPPC_ENC_1_ARR_1_FORMAT_CONFIGURATION_TABLE_t *) data;

}

const dnx_data_dnx2_arr_formats_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0_t *
dnx_data_dnx2_arr_formats_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0_get(
    int unit,
    int index)
{
    char *data;
    dnxc_data_table_t *table;

    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0", "DNX2");
    }
    
    table = dnxc_data_mgmt_table_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_formats, dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0);
    
    data = dnxc_data_mgmt_table_data_get(unit, table, index, 0);
    return (const dnx_data_dnx2_arr_formats_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0_t *) data;

}

const dnx_data_dnx2_arr_formats_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_1_t *
dnx_data_dnx2_arr_formats_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_1_get(
    int unit,
    int index)
{
    char *data;
    dnxc_data_table_t *table;

    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_1", "DNX2");
    }
    
    table = dnxc_data_mgmt_table_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_formats, dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_1);
    
    data = dnxc_data_mgmt_table_data_get(unit, table, index, 0);
    return (const dnx_data_dnx2_arr_formats_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_1_t *) data;

}

const dnx_data_dnx2_arr_formats_ETPPA_PRP_EES_ARR_CONFIGURATION_t *
dnx_data_dnx2_arr_formats_ETPPA_PRP_EES_ARR_CONFIGURATION_get(
    int unit,
    int index)
{
    char *data;
    dnxc_data_table_t *table;

    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "ETPPA_PRP_EES_ARR_CONFIGURATION", "DNX2");
    }
    
    table = dnxc_data_mgmt_table_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_formats, dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION);
    
    data = dnxc_data_mgmt_table_data_get(unit, table, index, 0);
    return (const dnx_data_dnx2_arr_formats_ETPPA_PRP_EES_ARR_CONFIGURATION_t *) data;

}

const dnx_data_dnx2_arr_formats_ETPPA_PRP_EES_ARR_CONFIGURATION___array_t *
dnx_data_dnx2_arr_formats_ETPPA_PRP_EES_ARR_CONFIGURATION___array_get(
    int unit,
    int table_index,
    int index)
{
    char *data;
    dnxc_data_table_t *table;

    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "ETPPA_PRP_EES_ARR_CONFIGURATION___array", "DNX2");
    }
    
    table = dnxc_data_mgmt_table_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_formats, dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION___array);
    
    data = dnxc_data_mgmt_table_data_get(unit, table, table_index, index);
    return (const dnx_data_dnx2_arr_formats_ETPPA_PRP_EES_ARR_CONFIGURATION___array_t *) data;

}

const dnx_data_dnx2_arr_formats_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION_t *
dnx_data_dnx2_arr_formats_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION_get(
    int unit,
    int index)
{
    char *data;
    dnxc_data_table_t *table;

    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "ETPPC_TERM_ETPS_ARR_1_CONFIGURATION", "DNX2");
    }
    
    table = dnxc_data_mgmt_table_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_formats, dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION);
    
    data = dnxc_data_mgmt_table_data_get(unit, table, index, 0);
    return (const dnx_data_dnx2_arr_formats_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION_t *) data;

}

const dnx_data_dnx2_arr_formats_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION___array_t *
dnx_data_dnx2_arr_formats_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION___array_get(
    int unit,
    int table_index,
    int index)
{
    char *data;
    dnxc_data_table_t *table;

    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "ETPPC_TERM_ETPS_ARR_1_CONFIGURATION___array", "DNX2");
    }
    
    table = dnxc_data_mgmt_table_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_formats, dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION___array);
    
    data = dnxc_data_mgmt_table_data_get(unit, table, table_index, index);
    return (const dnx_data_dnx2_arr_formats_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION___array_t *) data;

}

const dnx_data_dnx2_arr_formats_ETPPC_TERM_ETPS_ARR_2_CONFIGURATION_t *
dnx_data_dnx2_arr_formats_ETPPC_TERM_ETPS_ARR_2_CONFIGURATION_get(
    int unit,
    int index)
{
    char *data;
    dnxc_data_table_t *table;

    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "ETPPC_TERM_ETPS_ARR_2_CONFIGURATION", "DNX2");
    }
    
    table = dnxc_data_mgmt_table_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_formats, dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_2_CONFIGURATION);
    
    data = dnxc_data_mgmt_table_data_get(unit, table, index, 0);
    return (const dnx_data_dnx2_arr_formats_ETPPC_TERM_ETPS_ARR_2_CONFIGURATION_t *) data;

}

const dnx_data_dnx2_arr_formats_IPPB_EXPECTED_ARR_FORMAT_CONFIG_t *
dnx_data_dnx2_arr_formats_IPPB_EXPECTED_ARR_FORMAT_CONFIG_get(
    int unit,
    int index)
{
    char *data;
    dnxc_data_table_t *table;

    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "IPPB_EXPECTED_ARR_FORMAT_CONFIG", "DNX2");
    }
    
    table = dnxc_data_mgmt_table_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_formats, dnx_data_dnx2_arr_formats_table_IPPB_EXPECTED_ARR_FORMAT_CONFIG);
    
    data = dnxc_data_mgmt_table_data_get(unit, table, index, 0);
    return (const dnx_data_dnx2_arr_formats_IPPB_EXPECTED_ARR_FORMAT_CONFIG_t *) data;

}

const dnx_data_dnx2_arr_formats_MACT_MRQ_ARR_CFG_t *
dnx_data_dnx2_arr_formats_MACT_MRQ_ARR_CFG_get(
    int unit,
    int index)
{
    char *data;
    dnxc_data_table_t *table;

    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "MACT_MRQ_ARR_CFG", "DNX2");
    }
    
    table = dnxc_data_mgmt_table_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_formats, dnx_data_dnx2_arr_formats_table_MACT_MRQ_ARR_CFG);
    
    data = dnxc_data_mgmt_table_data_get(unit, table, index, 0);
    return (const dnx_data_dnx2_arr_formats_MACT_MRQ_ARR_CFG_t *) data;

}

const dnx_data_dnx2_arr_formats_IPPB_ACCEPTED_ARR_FORMAT_CONFIG_t *
dnx_data_dnx2_arr_formats_IPPB_ACCEPTED_ARR_FORMAT_CONFIG_get(
    int unit,
    int index)
{
    char *data;
    dnxc_data_table_t *table;

    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "IPPB_ACCEPTED_ARR_FORMAT_CONFIG", "DNX2");
    }
    
    table = dnxc_data_mgmt_table_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_formats, dnx_data_dnx2_arr_formats_table_IPPB_ACCEPTED_ARR_FORMAT_CONFIG);
    
    data = dnxc_data_mgmt_table_data_get(unit, table, index, 0);
    return (const dnx_data_dnx2_arr_formats_IPPB_ACCEPTED_ARR_FORMAT_CONFIG_t *) data;

}

const dnx_data_dnx2_arr_formats_IPPD_FEC_FORMAT_CONFIGURATION_TABLE___array_t *
dnx_data_dnx2_arr_formats_IPPD_FEC_FORMAT_CONFIGURATION_TABLE___array_get(
    int unit,
    int table_index,
    int index)
{
    char *data;
    dnxc_data_table_t *table;

    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "IPPD_FEC_FORMAT_CONFIGURATION_TABLE___array", "DNX2");
    }
    
    table = dnxc_data_mgmt_table_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_formats, dnx_data_dnx2_arr_formats_table_IPPD_FEC_FORMAT_CONFIGURATION_TABLE___array);
    
    data = dnxc_data_mgmt_table_data_get(unit, table, table_index, index);
    return (const dnx_data_dnx2_arr_formats_IPPD_FEC_FORMAT_CONFIGURATION_TABLE___array_t *) data;

}

const dnx_data_dnx2_arr_formats_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array_t *
dnx_data_dnx2_arr_formats_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array_get(
    int unit,
    int table_index,
    int index)
{
    char *data;
    dnxc_data_table_t *table;

    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array", "DNX2");
    }
    
    table = dnxc_data_mgmt_table_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_formats, dnx_data_dnx2_arr_formats_table_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array);
    
    data = dnxc_data_mgmt_table_data_get(unit, table, table_index, index);
    return (const dnx_data_dnx2_arr_formats_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array_t *) data;

}

const dnx_data_dnx2_arr_formats_IPPB_FLP_RPF_FORMAT_CONFIGURATION_TABLE___array_t *
dnx_data_dnx2_arr_formats_IPPB_FLP_RPF_FORMAT_CONFIGURATION_TABLE___array_get(
    int unit,
    int table_index,
    int index)
{
    char *data;
    dnxc_data_table_t *table;

    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "IPPB_FLP_RPF_FORMAT_CONFIGURATION_TABLE___array", "DNX2");
    }
    
    table = dnxc_data_mgmt_table_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_formats, dnx_data_dnx2_arr_formats_table_IPPB_FLP_RPF_FORMAT_CONFIGURATION_TABLE___array);
    
    data = dnxc_data_mgmt_table_data_get(unit, table, table_index, index);
    return (const dnx_data_dnx2_arr_formats_IPPB_FLP_RPF_FORMAT_CONFIGURATION_TABLE___array_t *) data;

}

const dnx_data_dnx2_arr_formats_IPPD_SUPER_ARR_FORMAT_CONFIGURATION_TABLE___array_t *
dnx_data_dnx2_arr_formats_IPPD_SUPER_ARR_FORMAT_CONFIGURATION_TABLE___array_get(
    int unit,
    int table_index,
    int index)
{
    char *data;
    dnxc_data_table_t *table;

    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "IPPD_SUPER_ARR_FORMAT_CONFIGURATION_TABLE___array", "DNX2");
    }
    
    table = dnxc_data_mgmt_table_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_formats, dnx_data_dnx2_arr_formats_table_IPPD_SUPER_ARR_FORMAT_CONFIGURATION_TABLE___array);
    
    data = dnxc_data_mgmt_table_data_get(unit, table, table_index, index);
    return (const dnx_data_dnx2_arr_formats_IPPD_SUPER_ARR_FORMAT_CONFIGURATION_TABLE___array_t *) data;

}

const dnx_data_dnx2_arr_formats_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1_t *
dnx_data_dnx2_arr_formats_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1_get(
    int unit,
    int index)
{
    char *data;
    dnxc_data_table_t *table;

    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1", "DNX2");
    }
    
    table = dnxc_data_mgmt_table_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_formats, dnx_data_dnx2_arr_formats_table_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1);
    
    data = dnxc_data_mgmt_table_data_get(unit, table, index, 0);
    return (const dnx_data_dnx2_arr_formats_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1_t *) data;

}

const dnx_data_dnx2_arr_formats_IPPF_VSI_FORMAT_CONFIGURATION_TABLE_t *
dnx_data_dnx2_arr_formats_IPPF_VSI_FORMAT_CONFIGURATION_TABLE_get(
    int unit,
    int index)
{
    char *data;
    dnxc_data_table_t *table;

    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "IPPF_VSI_FORMAT_CONFIGURATION_TABLE", "DNX2");
    }
    
    table = dnxc_data_mgmt_table_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_formats, dnx_data_dnx2_arr_formats_table_IPPF_VSI_FORMAT_CONFIGURATION_TABLE);
    
    data = dnxc_data_mgmt_table_data_get(unit, table, index, 0);
    return (const dnx_data_dnx2_arr_formats_IPPF_VSI_FORMAT_CONFIGURATION_TABLE_t *) data;

}

const dnx_data_dnx2_arr_formats_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array_t *
dnx_data_dnx2_arr_formats_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array_get(
    int unit,
    int table_index,
    int index)
{
    char *data;
    dnxc_data_table_t *table;

    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array", "DNX2");
    }
    
    table = dnxc_data_mgmt_table_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_formats, dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array);
    
    data = dnxc_data_mgmt_table_data_get(unit, table, table_index, index);
    return (const dnx_data_dnx2_arr_formats_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array_t *) data;

}

const dnx_data_dnx2_arr_formats_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array_t *
dnx_data_dnx2_arr_formats_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array_get(
    int unit,
    int table_index,
    int index)
{
    char *data;
    dnxc_data_table_t *table;

    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array", "DNX2");
    }
    
    table = dnxc_data_mgmt_table_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_formats, dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array);
    
    data = dnxc_data_mgmt_table_data_get(unit, table, table_index, index);
    return (const dnx_data_dnx2_arr_formats_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array_t *) data;

}

const dnx_data_dnx2_arr_formats_IPPD_LEARN_ARR_CONFIGURATION_TABLE_t *
dnx_data_dnx2_arr_formats_IPPD_LEARN_ARR_CONFIGURATION_TABLE_get(
    int unit,
    int index)
{
    char *data;
    dnxc_data_table_t *table;

    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "IPPD_LEARN_ARR_CONFIGURATION_TABLE", "DNX2");
    }
    
    table = dnxc_data_mgmt_table_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_formats, dnx_data_dnx2_arr_formats_table_IPPD_LEARN_ARR_CONFIGURATION_TABLE);
    
    data = dnxc_data_mgmt_table_data_get(unit, table, index, 0);
    return (const dnx_data_dnx2_arr_formats_IPPD_LEARN_ARR_CONFIGURATION_TABLE_t *) data;

}

const dnx_data_dnx2_arr_formats_OLP_LEARN_ARR_CONFIGURATION_TABLE_t *
dnx_data_dnx2_arr_formats_OLP_LEARN_ARR_CONFIGURATION_TABLE_get(
    int unit,
    int index)
{
    char *data;
    dnxc_data_table_t *table;

    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "OLP_LEARN_ARR_CONFIGURATION_TABLE", "DNX2");
    }
    
    table = dnxc_data_mgmt_table_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_formats, dnx_data_dnx2_arr_formats_table_OLP_LEARN_ARR_CONFIGURATION_TABLE);
    
    data = dnxc_data_mgmt_table_data_get(unit, table, index, 0);
    return (const dnx_data_dnx2_arr_formats_OLP_LEARN_ARR_CONFIGURATION_TABLE_t *) data;

}

const dnx_data_dnx2_arr_formats_ERPP_EGRESS_MCDB_FORMAT_CFG_t *
dnx_data_dnx2_arr_formats_ERPP_EGRESS_MCDB_FORMAT_CFG_get(
    int unit,
    int index)
{
    char *data;
    dnxc_data_table_t *table;

    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "ERPP_EGRESS_MCDB_FORMAT_CFG", "DNX2");
    }
    
    table = dnxc_data_mgmt_table_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_formats, dnx_data_dnx2_arr_formats_table_ERPP_EGRESS_MCDB_FORMAT_CFG);
    
    data = dnxc_data_mgmt_table_data_get(unit, table, index, 0);
    return (const dnx_data_dnx2_arr_formats_ERPP_EGRESS_MCDB_FORMAT_CFG_t *) data;

}


shr_error_e
dnx_data_dnx2_arr_formats_files_entry_str_get(
    int unit,
    char *buffer,
    int key0,
    int key1,
    int value_index)
{
    dnxc_data_table_t *table;
    const dnx_data_dnx2_arr_formats_files_t *data;
    SHR_FUNC_INIT_VARS(unit);

    
    table = dnxc_data_mgmt_table_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_formats, dnx_data_dnx2_arr_formats_table_files);
    data = (const dnx_data_dnx2_arr_formats_files_t *) dnxc_data_mgmt_table_data_diag_get(unit, table, 0, 0);
    switch (value_index)
    {
        case 0:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%s", data->arr_formats_file == NULL ? "" : data->arr_formats_file);
            break;
    }

    SHR_FUNC_EXIT;
}

shr_error_e
dnx_data_dnx2_arr_formats_MACT_AGE_PROFILE_ARR_CFG_entry_str_get(
    int unit,
    char *buffer,
    int key0,
    int key1,
    int value_index)
{
    dnxc_data_table_t *table;
    const dnx_data_dnx2_arr_formats_MACT_AGE_PROFILE_ARR_CFG_t *data;
    SHR_FUNC_INIT_VARS(unit);

    
    table = dnxc_data_mgmt_table_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_formats, dnx_data_dnx2_arr_formats_table_MACT_AGE_PROFILE_ARR_CFG);
    data = (const dnx_data_dnx2_arr_formats_MACT_AGE_PROFILE_ARR_CFG_t *) dnxc_data_mgmt_table_data_diag_get(unit, table, key0, 0);
    switch (value_index)
    {
        case 0:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->valid);
            break;
        case 1:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%s", data->doc == NULL ? "" : data->doc);
            break;
        case 2:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->AGE_PROFILE);
            break;
        case 3:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->AGE_PROFILE_valid);
            break;
    }

    SHR_FUNC_EXIT;
}

shr_error_e
dnx_data_dnx2_arr_formats_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE_entry_str_get(
    int unit,
    char *buffer,
    int key0,
    int key1,
    int value_index)
{
    dnxc_data_table_t *table;
    const dnx_data_dnx2_arr_formats_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE_t *data;
    SHR_FUNC_INIT_VARS(unit);

    
    table = dnxc_data_mgmt_table_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_formats, dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE);
    data = (const dnx_data_dnx2_arr_formats_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE_t *) dnxc_data_mgmt_table_data_diag_get(unit, table, key0, 0);
    switch (value_index)
    {
        case 0:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->valid);
            break;
        case 1:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%s", data->doc == NULL ? "" : data->doc);
            break;
        case 2:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->DUAL_HOMING_CONFIG);
            break;
        case 3:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->DUAL_HOMING_CONFIG_valid);
            break;
        case 4:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->EGRESS_LAST_LAYER_CONFIG);
            break;
        case 5:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->EGRESS_LAST_LAYER_CONFIG_valid);
            break;
        case 6:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->VLAN_MEMBERSHIP_INTERFACE_CONFIG);
            break;
        case 7:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->VLAN_MEMBERSHIP_INTERFACE_CONFIG_valid);
            break;
        case 8:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->ENCAP_DESTINATION_CONFIG);
            break;
        case 9:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->ENCAP_DESTINATION_CONFIG_valid);
            break;
        case 10:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->QOS_MODEL_CONFIG);
            break;
        case 11:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->QOS_MODEL_CONFIG_valid);
            break;
        case 12:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->FORWARD_DOMAIN_CONFIG);
            break;
        case 13:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->FORWARD_DOMAIN_CONFIG_valid);
            break;
        case 14:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->FORWARD_DOMAIN_NETWORK_NAME_CONFIG);
            break;
        case 15:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->FORWARD_DOMAIN_NETWORK_NAME_CONFIG_valid);
            break;
        case 16:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->LIF_ADDITIONAL_HEADERS_PROFILE_CONFIG);
            break;
        case 17:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->LIF_ADDITIONAL_HEADERS_PROFILE_CONFIG_valid);
            break;
        case 18:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->MTU_PROFILE_CONFIG);
            break;
        case 19:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->MTU_PROFILE_CONFIG_valid);
            break;
        case 20:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->NWK_QOS_IDX_CONFIG);
            break;
        case 21:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->NWK_QOS_IDX_CONFIG_valid);
            break;
        case 22:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->REMARK_PROFILE_CONFIG);
            break;
        case 23:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->REMARK_PROFILE_CONFIG_valid);
            break;
        case 24:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->SOURCE_IDX_CONFIG);
            break;
        case 25:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->SOURCE_IDX_CONFIG_valid);
            break;
        case 26:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->LIF_STATISTICS_OBJECT_COMMAND_CONFIG);
            break;
        case 27:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->LIF_STATISTICS_OBJECT_COMMAND_CONFIG_valid);
            break;
        case 28:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->LIF_STATISTICS_OBJECT_ID_CONFIG);
            break;
        case 29:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->LIF_STATISTICS_OBJECT_ID_CONFIG_valid);
            break;
        case 30:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->TTL_MODEL_CONFIG);
            break;
        case 31:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->TTL_MODEL_CONFIG_valid);
            break;
        case 32:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->TTL_IDX_CONFIG);
            break;
        case 33:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->TTL_IDX_CONFIG_valid);
            break;
        case 34:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->VLAN_EDIT_PROFILE_CONFIG);
            break;
        case 35:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->VLAN_EDIT_PROFILE_CONFIG_valid);
            break;
    }

    SHR_FUNC_EXIT;
}

shr_error_e
dnx_data_dnx2_arr_formats_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE_entry_str_get(
    int unit,
    char *buffer,
    int key0,
    int key1,
    int value_index)
{
    dnxc_data_table_t *table;
    const dnx_data_dnx2_arr_formats_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE_t *data;
    SHR_FUNC_INIT_VARS(unit);

    
    table = dnxc_data_mgmt_table_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_formats, dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE);
    data = (const dnx_data_dnx2_arr_formats_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE_t *) dnxc_data_mgmt_table_data_diag_get(unit, table, key0, 0);
    switch (value_index)
    {
        case 0:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->valid);
            break;
        case 1:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%s", data->doc == NULL ? "" : data->doc);
            break;
        case 2:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->DUAL_HOMING_CONFIG);
            break;
        case 3:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->DUAL_HOMING_CONFIG_valid);
            break;
        case 4:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->EGRESS_LAST_LAYER_CONFIG);
            break;
        case 5:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->EGRESS_LAST_LAYER_CONFIG_valid);
            break;
        case 6:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->VLAN_MEMBERSHIP_INTERFACE_CONFIG);
            break;
        case 7:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->VLAN_MEMBERSHIP_INTERFACE_CONFIG_valid);
            break;
        case 8:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->ENCAP_DESTINATION_CONFIG);
            break;
        case 9:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->ENCAP_DESTINATION_CONFIG_valid);
            break;
        case 10:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->QOS_MODEL_CONFIG);
            break;
        case 11:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->QOS_MODEL_CONFIG_valid);
            break;
        case 12:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->FORWARD_DOMAIN_CONFIG);
            break;
        case 13:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->FORWARD_DOMAIN_CONFIG_valid);
            break;
        case 14:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->FORWARD_DOMAIN_NETWORK_NAME_CONFIG);
            break;
        case 15:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->FORWARD_DOMAIN_NETWORK_NAME_CONFIG_valid);
            break;
        case 16:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->LIF_ADDITIONAL_HEADERS_PROFILE_CONFIG);
            break;
        case 17:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->LIF_ADDITIONAL_HEADERS_PROFILE_CONFIG_valid);
            break;
        case 18:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->MTU_PROFILE_CONFIG);
            break;
        case 19:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->MTU_PROFILE_CONFIG_valid);
            break;
        case 20:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->NWK_QOS_IDX_CONFIG);
            break;
        case 21:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->NWK_QOS_IDX_CONFIG_valid);
            break;
        case 22:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->REMARK_PROFILE_CONFIG);
            break;
        case 23:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->REMARK_PROFILE_CONFIG_valid);
            break;
        case 24:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->SOURCE_IDX_CONFIG);
            break;
        case 25:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->SOURCE_IDX_CONFIG_valid);
            break;
        case 26:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->LIF_STATISTICS_OBJECT_COMMAND_CONFIG);
            break;
        case 27:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->LIF_STATISTICS_OBJECT_COMMAND_CONFIG_valid);
            break;
        case 28:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->LIF_STATISTICS_OBJECT_ID_CONFIG);
            break;
        case 29:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->LIF_STATISTICS_OBJECT_ID_CONFIG_valid);
            break;
        case 30:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->TTL_MODEL_CONFIG);
            break;
        case 31:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->TTL_MODEL_CONFIG_valid);
            break;
        case 32:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->TTL_IDX_CONFIG);
            break;
        case 33:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->TTL_IDX_CONFIG_valid);
            break;
        case 34:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->VLAN_EDIT_PROFILE_CONFIG);
            break;
        case 35:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->VLAN_EDIT_PROFILE_CONFIG_valid);
            break;
    }

    SHR_FUNC_EXIT;
}

shr_error_e
dnx_data_dnx2_arr_formats_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE_entry_str_get(
    int unit,
    char *buffer,
    int key0,
    int key1,
    int value_index)
{
    dnxc_data_table_t *table;
    const dnx_data_dnx2_arr_formats_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE_t *data;
    SHR_FUNC_INIT_VARS(unit);

    
    table = dnxc_data_mgmt_table_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_formats, dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE);
    data = (const dnx_data_dnx2_arr_formats_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE_t *) dnxc_data_mgmt_table_data_diag_get(unit, table, key0, 0);
    switch (value_index)
    {
        case 0:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->valid);
            break;
        case 1:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%s", data->doc == NULL ? "" : data->doc);
            break;
        case 2:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->DUAL_HOMING_CONFIG);
            break;
        case 3:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->DUAL_HOMING_CONFIG_valid);
            break;
        case 4:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->EGRESS_LAST_LAYER_CONFIG);
            break;
        case 5:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->EGRESS_LAST_LAYER_CONFIG_valid);
            break;
        case 6:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->VLAN_MEMBERSHIP_INTERFACE_CONFIG);
            break;
        case 7:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->VLAN_MEMBERSHIP_INTERFACE_CONFIG_valid);
            break;
        case 8:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->ENCAP_DESTINATION_CONFIG);
            break;
        case 9:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->ENCAP_DESTINATION_CONFIG_valid);
            break;
        case 10:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->QOS_MODEL_CONFIG);
            break;
        case 11:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->QOS_MODEL_CONFIG_valid);
            break;
        case 12:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->FORWARD_DOMAIN_CONFIG);
            break;
        case 13:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->FORWARD_DOMAIN_CONFIG_valid);
            break;
        case 14:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->FORWARD_DOMAIN_NETWORK_NAME_CONFIG);
            break;
        case 15:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->FORWARD_DOMAIN_NETWORK_NAME_CONFIG_valid);
            break;
        case 16:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->LIF_ADDITIONAL_HEADERS_PROFILE_CONFIG);
            break;
        case 17:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->LIF_ADDITIONAL_HEADERS_PROFILE_CONFIG_valid);
            break;
        case 18:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->MTU_PROFILE_CONFIG);
            break;
        case 19:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->MTU_PROFILE_CONFIG_valid);
            break;
        case 20:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->NWK_QOS_IDX_CONFIG);
            break;
        case 21:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->NWK_QOS_IDX_CONFIG_valid);
            break;
        case 22:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->REMARK_PROFILE_CONFIG);
            break;
        case 23:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->REMARK_PROFILE_CONFIG_valid);
            break;
        case 24:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->SOURCE_IDX_CONFIG);
            break;
        case 25:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->SOURCE_IDX_CONFIG_valid);
            break;
        case 26:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->LIF_STATISTICS_OBJECT_COMMAND_CONFIG);
            break;
        case 27:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->LIF_STATISTICS_OBJECT_COMMAND_CONFIG_valid);
            break;
        case 28:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->LIF_STATISTICS_OBJECT_ID_CONFIG);
            break;
        case 29:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->LIF_STATISTICS_OBJECT_ID_CONFIG_valid);
            break;
        case 30:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->TTL_MODEL_CONFIG);
            break;
        case 31:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->TTL_MODEL_CONFIG_valid);
            break;
        case 32:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->TTL_IDX_CONFIG);
            break;
        case 33:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->TTL_IDX_CONFIG_valid);
            break;
        case 34:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->VLAN_EDIT_PROFILE_CONFIG);
            break;
        case 35:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->VLAN_EDIT_PROFILE_CONFIG_valid);
            break;
    }

    SHR_FUNC_EXIT;
}

shr_error_e
dnx_data_dnx2_arr_formats_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE_entry_str_get(
    int unit,
    char *buffer,
    int key0,
    int key1,
    int value_index)
{
    dnxc_data_table_t *table;
    const dnx_data_dnx2_arr_formats_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE_t *data;
    SHR_FUNC_INIT_VARS(unit);

    
    table = dnxc_data_mgmt_table_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_formats, dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE);
    data = (const dnx_data_dnx2_arr_formats_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE_t *) dnxc_data_mgmt_table_data_diag_get(unit, table, key0, 0);
    switch (value_index)
    {
        case 0:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->valid);
            break;
        case 1:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%s", data->doc == NULL ? "" : data->doc);
            break;
        case 2:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->DUAL_HOMING_CONFIG);
            break;
        case 3:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->DUAL_HOMING_CONFIG_valid);
            break;
        case 4:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->EGRESS_LAST_LAYER_CONFIG);
            break;
        case 5:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->EGRESS_LAST_LAYER_CONFIG_valid);
            break;
        case 6:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->VLAN_MEMBERSHIP_INTERFACE_CONFIG);
            break;
        case 7:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->VLAN_MEMBERSHIP_INTERFACE_CONFIG_valid);
            break;
        case 8:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->ENCAP_DESTINATION_CONFIG);
            break;
        case 9:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->ENCAP_DESTINATION_CONFIG_valid);
            break;
        case 10:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->QOS_MODEL_CONFIG);
            break;
        case 11:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->QOS_MODEL_CONFIG_valid);
            break;
        case 12:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->FORWARD_DOMAIN_CONFIG);
            break;
        case 13:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->FORWARD_DOMAIN_CONFIG_valid);
            break;
        case 14:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->FORWARD_DOMAIN_NETWORK_NAME_CONFIG);
            break;
        case 15:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->FORWARD_DOMAIN_NETWORK_NAME_CONFIG_valid);
            break;
        case 16:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->LIF_ADDITIONAL_HEADERS_PROFILE_CONFIG);
            break;
        case 17:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->LIF_ADDITIONAL_HEADERS_PROFILE_CONFIG_valid);
            break;
        case 18:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->MTU_PROFILE_CONFIG);
            break;
        case 19:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->MTU_PROFILE_CONFIG_valid);
            break;
        case 20:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->NWK_QOS_IDX_CONFIG);
            break;
        case 21:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->NWK_QOS_IDX_CONFIG_valid);
            break;
        case 22:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->REMARK_PROFILE_CONFIG);
            break;
        case 23:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->REMARK_PROFILE_CONFIG_valid);
            break;
        case 24:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->SOURCE_IDX_CONFIG);
            break;
        case 25:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->SOURCE_IDX_CONFIG_valid);
            break;
        case 26:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->LIF_STATISTICS_OBJECT_COMMAND_CONFIG);
            break;
        case 27:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->LIF_STATISTICS_OBJECT_COMMAND_CONFIG_valid);
            break;
        case 28:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->LIF_STATISTICS_OBJECT_ID_CONFIG);
            break;
        case 29:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->LIF_STATISTICS_OBJECT_ID_CONFIG_valid);
            break;
        case 30:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->TTL_MODEL_CONFIG);
            break;
        case 31:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->TTL_MODEL_CONFIG_valid);
            break;
        case 32:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->TTL_IDX_CONFIG);
            break;
        case 33:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->TTL_IDX_CONFIG_valid);
            break;
        case 34:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->VLAN_EDIT_PROFILE_CONFIG);
            break;
        case 35:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->VLAN_EDIT_PROFILE_CONFIG_valid);
            break;
    }

    SHR_FUNC_EXIT;
}

shr_error_e
dnx_data_dnx2_arr_formats_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE_entry_str_get(
    int unit,
    char *buffer,
    int key0,
    int key1,
    int value_index)
{
    dnxc_data_table_t *table;
    const dnx_data_dnx2_arr_formats_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE_t *data;
    SHR_FUNC_INIT_VARS(unit);

    
    table = dnxc_data_mgmt_table_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_formats, dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE);
    data = (const dnx_data_dnx2_arr_formats_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE_t *) dnxc_data_mgmt_table_data_diag_get(unit, table, key0, 0);
    switch (value_index)
    {
        case 0:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->valid);
            break;
        case 1:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%s", data->doc == NULL ? "" : data->doc);
            break;
        case 2:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->DUAL_HOMING_CONFIG);
            break;
        case 3:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->DUAL_HOMING_CONFIG_valid);
            break;
        case 4:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->EGRESS_LAST_LAYER_CONFIG);
            break;
        case 5:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->EGRESS_LAST_LAYER_CONFIG_valid);
            break;
        case 6:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->VLAN_MEMBERSHIP_INTERFACE_CONFIG);
            break;
        case 7:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->VLAN_MEMBERSHIP_INTERFACE_CONFIG_valid);
            break;
        case 8:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->ENCAP_DESTINATION_CONFIG);
            break;
        case 9:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->ENCAP_DESTINATION_CONFIG_valid);
            break;
        case 10:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->QOS_MODEL_CONFIG);
            break;
        case 11:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->QOS_MODEL_CONFIG_valid);
            break;
        case 12:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->FORWARD_DOMAIN_CONFIG);
            break;
        case 13:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->FORWARD_DOMAIN_CONFIG_valid);
            break;
        case 14:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->FORWARD_DOMAIN_NETWORK_NAME_CONFIG);
            break;
        case 15:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->FORWARD_DOMAIN_NETWORK_NAME_CONFIG_valid);
            break;
        case 16:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->LIF_ADDITIONAL_HEADERS_PROFILE_CONFIG);
            break;
        case 17:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->LIF_ADDITIONAL_HEADERS_PROFILE_CONFIG_valid);
            break;
        case 18:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->MTU_PROFILE_CONFIG);
            break;
        case 19:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->MTU_PROFILE_CONFIG_valid);
            break;
        case 20:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->NWK_QOS_IDX_CONFIG);
            break;
        case 21:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->NWK_QOS_IDX_CONFIG_valid);
            break;
        case 22:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->REMARK_PROFILE_CONFIG);
            break;
        case 23:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->REMARK_PROFILE_CONFIG_valid);
            break;
        case 24:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->SOURCE_IDX_CONFIG);
            break;
        case 25:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->SOURCE_IDX_CONFIG_valid);
            break;
        case 26:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->LIF_STATISTICS_OBJECT_COMMAND_CONFIG);
            break;
        case 27:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->LIF_STATISTICS_OBJECT_COMMAND_CONFIG_valid);
            break;
        case 28:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->LIF_STATISTICS_OBJECT_ID_CONFIG);
            break;
        case 29:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->LIF_STATISTICS_OBJECT_ID_CONFIG_valid);
            break;
        case 30:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->TTL_MODEL_CONFIG);
            break;
        case 31:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->TTL_MODEL_CONFIG_valid);
            break;
        case 32:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->TTL_IDX_CONFIG);
            break;
        case 33:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->TTL_IDX_CONFIG_valid);
            break;
        case 34:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->VLAN_EDIT_PROFILE_CONFIG);
            break;
        case 35:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->VLAN_EDIT_PROFILE_CONFIG_valid);
            break;
    }

    SHR_FUNC_EXIT;
}

shr_error_e
dnx_data_dnx2_arr_formats_ETPPB_ENC_FORMAT_CONFIGURATION_TABLE_entry_str_get(
    int unit,
    char *buffer,
    int key0,
    int key1,
    int value_index)
{
    dnxc_data_table_t *table;
    const dnx_data_dnx2_arr_formats_ETPPB_ENC_FORMAT_CONFIGURATION_TABLE_t *data;
    SHR_FUNC_INIT_VARS(unit);

    
    table = dnxc_data_mgmt_table_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_formats, dnx_data_dnx2_arr_formats_table_ETPPB_ENC_FORMAT_CONFIGURATION_TABLE);
    data = (const dnx_data_dnx2_arr_formats_ETPPB_ENC_FORMAT_CONFIGURATION_TABLE_t *) dnxc_data_mgmt_table_data_diag_get(unit, table, key0, 0);
    switch (value_index)
    {
        case 0:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->valid);
            break;
        case 1:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%s", data->doc == NULL ? "" : data->doc);
            break;
        case 2:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->VLAN_MEMBERSHIP_INTERFACE_CONFIG);
            break;
        case 3:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->VLAN_MEMBERSHIP_INTERFACE_CONFIG_valid);
            break;
        case 4:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->ENCAP_DESTINATION_CONFIG);
            break;
        case 5:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->ENCAP_DESTINATION_CONFIG_valid);
            break;
        case 6:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->REMARK_PROFILE_CONFIG);
            break;
        case 7:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->REMARK_PROFILE_CONFIG_valid);
            break;
    }

    SHR_FUNC_EXIT;
}

shr_error_e
dnx_data_dnx2_arr_formats_ETPPC_ENC_FORMAT_CONFIGURATION_TABLE_entry_str_get(
    int unit,
    char *buffer,
    int key0,
    int key1,
    int value_index)
{
    dnxc_data_table_t *table;
    const dnx_data_dnx2_arr_formats_ETPPC_ENC_FORMAT_CONFIGURATION_TABLE_t *data;
    SHR_FUNC_INIT_VARS(unit);

    
    table = dnxc_data_mgmt_table_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_formats, dnx_data_dnx2_arr_formats_table_ETPPC_ENC_FORMAT_CONFIGURATION_TABLE);
    data = (const dnx_data_dnx2_arr_formats_ETPPC_ENC_FORMAT_CONFIGURATION_TABLE_t *) dnxc_data_mgmt_table_data_diag_get(unit, table, key0, 0);
    switch (value_index)
    {
        case 0:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->valid);
            break;
        case 1:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%s", data->doc == NULL ? "" : data->doc);
            break;
        case 2:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->VLAN_MEMBERSHIP_INTERFACE_CONFIG);
            break;
        case 3:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->VLAN_MEMBERSHIP_INTERFACE_CONFIG_valid);
            break;
        case 4:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->ENCAP_DESTINATION_CONFIG);
            break;
        case 5:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->ENCAP_DESTINATION_CONFIG_valid);
            break;
        case 6:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->REMARK_PROFILE_CONFIG);
            break;
        case 7:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->REMARK_PROFILE_CONFIG_valid);
            break;
    }

    SHR_FUNC_EXIT;
}

shr_error_e
dnx_data_dnx2_arr_formats_ETPPB_ENC_2_ARR_1_FORMAT_CONFIGURATION_TABLE_entry_str_get(
    int unit,
    char *buffer,
    int key0,
    int key1,
    int value_index)
{
    dnxc_data_table_t *table;
    const dnx_data_dnx2_arr_formats_ETPPB_ENC_2_ARR_1_FORMAT_CONFIGURATION_TABLE_t *data;
    SHR_FUNC_INIT_VARS(unit);

    
    table = dnxc_data_mgmt_table_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_formats, dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_1_FORMAT_CONFIGURATION_TABLE);
    data = (const dnx_data_dnx2_arr_formats_ETPPB_ENC_2_ARR_1_FORMAT_CONFIGURATION_TABLE_t *) dnxc_data_mgmt_table_data_diag_get(unit, table, key0, 0);
    switch (value_index)
    {
        case 0:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->valid);
            break;
        case 1:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%s", data->doc == NULL ? "" : data->doc);
            break;
        case 2:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->VLAN_MEMBERSHIP_INTERFACE_CONFIG);
            break;
        case 3:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->VLAN_MEMBERSHIP_INTERFACE_CONFIG_valid);
            break;
        case 4:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->ENCAP_DESTINATION_CONFIG);
            break;
        case 5:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->ENCAP_DESTINATION_CONFIG_valid);
            break;
        case 6:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->REMARK_PROFILE_CONFIG);
            break;
        case 7:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->REMARK_PROFILE_CONFIG_valid);
            break;
    }

    SHR_FUNC_EXIT;
}

shr_error_e
dnx_data_dnx2_arr_formats_ETPPB_ENC_3_ARR_1_FORMAT_CONFIGURATION_TABLE_entry_str_get(
    int unit,
    char *buffer,
    int key0,
    int key1,
    int value_index)
{
    dnxc_data_table_t *table;
    const dnx_data_dnx2_arr_formats_ETPPB_ENC_3_ARR_1_FORMAT_CONFIGURATION_TABLE_t *data;
    SHR_FUNC_INIT_VARS(unit);

    
    table = dnxc_data_mgmt_table_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_formats, dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_1_FORMAT_CONFIGURATION_TABLE);
    data = (const dnx_data_dnx2_arr_formats_ETPPB_ENC_3_ARR_1_FORMAT_CONFIGURATION_TABLE_t *) dnxc_data_mgmt_table_data_diag_get(unit, table, key0, 0);
    switch (value_index)
    {
        case 0:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->valid);
            break;
        case 1:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%s", data->doc == NULL ? "" : data->doc);
            break;
        case 2:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->VLAN_MEMBERSHIP_INTERFACE_CONFIG);
            break;
        case 3:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->VLAN_MEMBERSHIP_INTERFACE_CONFIG_valid);
            break;
        case 4:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->ENCAP_DESTINATION_CONFIG);
            break;
        case 5:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->ENCAP_DESTINATION_CONFIG_valid);
            break;
        case 6:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->REMARK_PROFILE_CONFIG);
            break;
        case 7:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->REMARK_PROFILE_CONFIG_valid);
            break;
    }

    SHR_FUNC_EXIT;
}

shr_error_e
dnx_data_dnx2_arr_formats_ETPPB_ENC_4_ARR_1_FORMAT_CONFIGURATION_TABLE_entry_str_get(
    int unit,
    char *buffer,
    int key0,
    int key1,
    int value_index)
{
    dnxc_data_table_t *table;
    const dnx_data_dnx2_arr_formats_ETPPB_ENC_4_ARR_1_FORMAT_CONFIGURATION_TABLE_t *data;
    SHR_FUNC_INIT_VARS(unit);

    
    table = dnxc_data_mgmt_table_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_formats, dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_1_FORMAT_CONFIGURATION_TABLE);
    data = (const dnx_data_dnx2_arr_formats_ETPPB_ENC_4_ARR_1_FORMAT_CONFIGURATION_TABLE_t *) dnxc_data_mgmt_table_data_diag_get(unit, table, key0, 0);
    switch (value_index)
    {
        case 0:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->valid);
            break;
        case 1:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%s", data->doc == NULL ? "" : data->doc);
            break;
        case 2:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->VLAN_MEMBERSHIP_INTERFACE_CONFIG);
            break;
        case 3:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->VLAN_MEMBERSHIP_INTERFACE_CONFIG_valid);
            break;
        case 4:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->ENCAP_DESTINATION_CONFIG);
            break;
        case 5:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->ENCAP_DESTINATION_CONFIG_valid);
            break;
        case 6:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->REMARK_PROFILE_CONFIG);
            break;
        case 7:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->REMARK_PROFILE_CONFIG_valid);
            break;
    }

    SHR_FUNC_EXIT;
}

shr_error_e
dnx_data_dnx2_arr_formats_ETPPB_ENC_5_ARR_1_FORMAT_CONFIGURATION_TABLE_entry_str_get(
    int unit,
    char *buffer,
    int key0,
    int key1,
    int value_index)
{
    dnxc_data_table_t *table;
    const dnx_data_dnx2_arr_formats_ETPPB_ENC_5_ARR_1_FORMAT_CONFIGURATION_TABLE_t *data;
    SHR_FUNC_INIT_VARS(unit);

    
    table = dnxc_data_mgmt_table_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_formats, dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_1_FORMAT_CONFIGURATION_TABLE);
    data = (const dnx_data_dnx2_arr_formats_ETPPB_ENC_5_ARR_1_FORMAT_CONFIGURATION_TABLE_t *) dnxc_data_mgmt_table_data_diag_get(unit, table, key0, 0);
    switch (value_index)
    {
        case 0:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->valid);
            break;
        case 1:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%s", data->doc == NULL ? "" : data->doc);
            break;
        case 2:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->VLAN_MEMBERSHIP_INTERFACE_CONFIG);
            break;
        case 3:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->VLAN_MEMBERSHIP_INTERFACE_CONFIG_valid);
            break;
        case 4:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->ENCAP_DESTINATION_CONFIG);
            break;
        case 5:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->ENCAP_DESTINATION_CONFIG_valid);
            break;
        case 6:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->REMARK_PROFILE_CONFIG);
            break;
        case 7:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->REMARK_PROFILE_CONFIG_valid);
            break;
    }

    SHR_FUNC_EXIT;
}

shr_error_e
dnx_data_dnx2_arr_formats_ETPPC_ENC_1_ARR_1_FORMAT_CONFIGURATION_TABLE_entry_str_get(
    int unit,
    char *buffer,
    int key0,
    int key1,
    int value_index)
{
    dnxc_data_table_t *table;
    const dnx_data_dnx2_arr_formats_ETPPC_ENC_1_ARR_1_FORMAT_CONFIGURATION_TABLE_t *data;
    SHR_FUNC_INIT_VARS(unit);

    
    table = dnxc_data_mgmt_table_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_formats, dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_1_FORMAT_CONFIGURATION_TABLE);
    data = (const dnx_data_dnx2_arr_formats_ETPPC_ENC_1_ARR_1_FORMAT_CONFIGURATION_TABLE_t *) dnxc_data_mgmt_table_data_diag_get(unit, table, key0, 0);
    switch (value_index)
    {
        case 0:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->valid);
            break;
        case 1:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%s", data->doc == NULL ? "" : data->doc);
            break;
        case 2:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->VLAN_MEMBERSHIP_INTERFACE_CONFIG);
            break;
        case 3:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->VLAN_MEMBERSHIP_INTERFACE_CONFIG_valid);
            break;
        case 4:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->ENCAP_DESTINATION_CONFIG);
            break;
        case 5:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->ENCAP_DESTINATION_CONFIG_valid);
            break;
        case 6:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->REMARK_PROFILE_CONFIG);
            break;
        case 7:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->REMARK_PROFILE_CONFIG_valid);
            break;
    }

    SHR_FUNC_EXIT;
}

shr_error_e
dnx_data_dnx2_arr_formats_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0_entry_str_get(
    int unit,
    char *buffer,
    int key0,
    int key1,
    int value_index)
{
    dnxc_data_table_t *table;
    const dnx_data_dnx2_arr_formats_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0_t *data;
    SHR_FUNC_INIT_VARS(unit);

    
    table = dnxc_data_mgmt_table_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_formats, dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0);
    data = (const dnx_data_dnx2_arr_formats_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0_t *) dnxc_data_mgmt_table_data_diag_get(unit, table, key0, 0);
    switch (value_index)
    {
        case 0:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->valid);
            break;
        case 1:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%s", data->doc == NULL ? "" : data->doc);
            break;
        case 2:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->ETHERNET_EGRESS_LAST_LAYER_CONFIG);
            break;
        case 3:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->ETHERNET_EGRESS_LAST_LAYER_CONFIG_valid);
            break;
        case 4:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->ETHERNET_EGRESS_VLAN_MEMBERSHIP_INTERFACE_CONFIG);
            break;
        case 5:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->ETHERNET_EGRESS_VLAN_MEMBERSHIP_INTERFACE_CONFIG_valid);
            break;
        case 6:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->ENCAP_DESTINATION_CONFIG);
            break;
        case 7:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->ENCAP_DESTINATION_CONFIG_valid);
            break;
        case 8:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->FORWARDING_DOMAIN_CONFIG);
            break;
        case 9:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->FORWARDING_DOMAIN_CONFIG_valid);
            break;
        case 10:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->QOS_MODEL_CONFIG);
            break;
        case 11:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->QOS_MODEL_CONFIG_valid);
            break;
        case 12:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->MTU_PROFILE_CONFIG);
            break;
        case 13:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->MTU_PROFILE_CONFIG_valid);
            break;
        case 14:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->NWK_QOS_INDEX_CONFIG);
            break;
        case 15:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->NWK_QOS_INDEX_CONFIG_valid);
            break;
        case 16:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->ETHERNET_OUTLIF_PROFILE_CONFIG);
            break;
        case 17:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->ETHERNET_OUTLIF_PROFILE_CONFIG_valid);
            break;
        case 18:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->REMARK_PROFILE_CONFIG);
            break;
        case 19:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->REMARK_PROFILE_CONFIG_valid);
            break;
        case 20:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->LIF_STATISTICS_OBJECT_COMMAND_CONFIG);
            break;
        case 21:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->LIF_STATISTICS_OBJECT_COMMAND_CONFIG_valid);
            break;
        case 22:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->LIF_STATISTICS_OBJECT_ID_CONFIG);
            break;
        case 23:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->LIF_STATISTICS_OBJECT_ID_CONFIG_valid);
            break;
        case 24:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->TTL_MODEL_CONFIG);
            break;
        case 25:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->TTL_MODEL_CONFIG_valid);
            break;
        case 26:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->ETHERNET_EGRESS_VLAN_EDIT_PROFILE_CONFIG);
            break;
        case 27:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->ETHERNET_EGRESS_VLAN_EDIT_PROFILE_CONFIG_valid);
            break;
    }

    SHR_FUNC_EXIT;
}

shr_error_e
dnx_data_dnx2_arr_formats_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_1_entry_str_get(
    int unit,
    char *buffer,
    int key0,
    int key1,
    int value_index)
{
    dnxc_data_table_t *table;
    const dnx_data_dnx2_arr_formats_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_1_t *data;
    SHR_FUNC_INIT_VARS(unit);

    
    table = dnxc_data_mgmt_table_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_formats, dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_1);
    data = (const dnx_data_dnx2_arr_formats_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_1_t *) dnxc_data_mgmt_table_data_diag_get(unit, table, key0, 0);
    switch (value_index)
    {
        case 0:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->valid);
            break;
        case 1:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%s", data->doc == NULL ? "" : data->doc);
            break;
        case 2:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->ETHERNET_EGRESS_VLAN_MEMBERSHIP_INTERFACE_CONFIG);
            break;
        case 3:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->ETHERNET_EGRESS_VLAN_MEMBERSHIP_INTERFACE_CONFIG_valid);
            break;
        case 4:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->ENCAP_DESTINATION_CONFIG);
            break;
        case 5:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->ENCAP_DESTINATION_CONFIG_valid);
            break;
        case 6:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->REMARK_PROFILE_CONFIG);
            break;
        case 7:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->REMARK_PROFILE_CONFIG_valid);
            break;
    }

    SHR_FUNC_EXIT;
}

shr_error_e
dnx_data_dnx2_arr_formats_ETPPA_PRP_EES_ARR_CONFIGURATION_entry_str_get(
    int unit,
    char *buffer,
    int key0,
    int key1,
    int value_index)
{
    dnxc_data_table_t *table;
    const dnx_data_dnx2_arr_formats_ETPPA_PRP_EES_ARR_CONFIGURATION_t *data;
    SHR_FUNC_INIT_VARS(unit);

    
    table = dnxc_data_mgmt_table_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_formats, dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION);
    data = (const dnx_data_dnx2_arr_formats_ETPPA_PRP_EES_ARR_CONFIGURATION_t *) dnxc_data_mgmt_table_data_diag_get(unit, table, key0, 0);
    switch (value_index)
    {
        case 0:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->valid);
            break;
        case 1:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%s", data->doc == NULL ? "" : data->doc);
            break;
        case 2:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->LLVP_PROFILE_CONFIG);
            break;
        case 3:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->LLVP_PROFILE_CONFIG_valid);
            break;
        case 4:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->EM_ACCESS_CMD_CONFIG);
            break;
        case 5:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->EM_ACCESS_CMD_CONFIG_valid);
            break;
        case 6:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->NAME_SPACE_CONFIG);
            break;
        case 7:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->NAME_SPACE_CONFIG_valid);
            break;
        case 8:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->FWD_DOMAIN_CONFIG);
            break;
        case 9:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->FWD_DOMAIN_CONFIG_valid);
            break;
        case 10:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->OAM_LIF_SET_CONFIG);
            break;
        case 11:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->OAM_LIF_SET_CONFIG_valid);
            break;
        case 12:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->OUTLIF_PROFILE_CONFIG);
            break;
        case 13:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->OUTLIF_PROFILE_CONFIG_valid);
            break;
    }

    SHR_FUNC_EXIT;
}

shr_error_e
dnx_data_dnx2_arr_formats_ETPPA_PRP_EES_ARR_CONFIGURATION___array_entry_str_get(
    int unit,
    char *buffer,
    int key0,
    int key1,
    int value_index)
{
    dnxc_data_table_t *table;
    const dnx_data_dnx2_arr_formats_ETPPA_PRP_EES_ARR_CONFIGURATION___array_t *data;
    SHR_FUNC_INIT_VARS(unit);

    
    table = dnxc_data_mgmt_table_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_formats, dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION___array);
    data = (const dnx_data_dnx2_arr_formats_ETPPA_PRP_EES_ARR_CONFIGURATION___array_t *) dnxc_data_mgmt_table_data_diag_get(unit, table, key0, key1);
    switch (value_index)
    {
        case 0:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->valid);
            break;
        case 1:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%s", data->doc == NULL ? "" : data->doc);
            break;
        case 2:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->LLVP_PROFILE_CONFIG);
            break;
        case 3:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->LLVP_PROFILE_CONFIG_valid);
            break;
        case 4:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->EM_ACCESS_CMD_CONFIG);
            break;
        case 5:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->EM_ACCESS_CMD_CONFIG_valid);
            break;
        case 6:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->NAME_SPACE_CONFIG);
            break;
        case 7:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->NAME_SPACE_CONFIG_valid);
            break;
        case 8:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->FWD_DOMAIN_CONFIG);
            break;
        case 9:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->FWD_DOMAIN_CONFIG_valid);
            break;
        case 10:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->OAM_LIF_SET_CONFIG);
            break;
        case 11:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->OAM_LIF_SET_CONFIG_valid);
            break;
        case 12:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->OUTLIF_PROFILE_CONFIG);
            break;
        case 13:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->OUTLIF_PROFILE_CONFIG_valid);
            break;
    }

    SHR_FUNC_EXIT;
}

shr_error_e
dnx_data_dnx2_arr_formats_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION_entry_str_get(
    int unit,
    char *buffer,
    int key0,
    int key1,
    int value_index)
{
    dnxc_data_table_t *table;
    const dnx_data_dnx2_arr_formats_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION_t *data;
    SHR_FUNC_INIT_VARS(unit);

    
    table = dnxc_data_mgmt_table_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_formats, dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION);
    data = (const dnx_data_dnx2_arr_formats_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION_t *) dnxc_data_mgmt_table_data_diag_get(unit, table, key0, 0);
    switch (value_index)
    {
        case 0:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->valid);
            break;
        case 1:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%s", data->doc == NULL ? "" : data->doc);
            break;
        case 2:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->ACTION_PROFILE_CONFIG);
            break;
        case 3:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->ACTION_PROFILE_CONFIG_valid);
            break;
        case 4:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->PROTECTION_PATH_CONFIG);
            break;
        case 5:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->PROTECTION_PATH_CONFIG_valid);
            break;
        case 6:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->PROTECTION_PTR_CONFIG);
            break;
        case 7:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->PROTECTION_PTR_CONFIG_valid);
            break;
        case 8:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->STAT_OBJ_CMD_CONFIG);
            break;
        case 9:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->STAT_OBJ_CMD_CONFIG_valid);
            break;
        case 10:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->STAT_OBJ_ID_CONFIG);
            break;
        case 11:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->STAT_OBJ_ID_CONFIG_valid);
            break;
    }

    SHR_FUNC_EXIT;
}

shr_error_e
dnx_data_dnx2_arr_formats_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION___array_entry_str_get(
    int unit,
    char *buffer,
    int key0,
    int key1,
    int value_index)
{
    dnxc_data_table_t *table;
    const dnx_data_dnx2_arr_formats_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION___array_t *data;
    SHR_FUNC_INIT_VARS(unit);

    
    table = dnxc_data_mgmt_table_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_formats, dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION___array);
    data = (const dnx_data_dnx2_arr_formats_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION___array_t *) dnxc_data_mgmt_table_data_diag_get(unit, table, key0, key1);
    switch (value_index)
    {
        case 0:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->valid);
            break;
        case 1:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%s", data->doc == NULL ? "" : data->doc);
            break;
        case 2:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->ACTION_PROFILE_CONFIG);
            break;
        case 3:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->ACTION_PROFILE_CONFIG_valid);
            break;
        case 4:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->PROTECTION_PATH_CONFIG);
            break;
        case 5:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->PROTECTION_PATH_CONFIG_valid);
            break;
        case 6:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->PROTECTION_PTR_CONFIG);
            break;
        case 7:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->PROTECTION_PTR_CONFIG_valid);
            break;
        case 8:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->STAT_OBJ_CMD_CONFIG);
            break;
        case 9:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->STAT_OBJ_CMD_CONFIG_valid);
            break;
        case 10:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->STAT_OBJ_ID_CONFIG);
            break;
        case 11:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->STAT_OBJ_ID_CONFIG_valid);
            break;
    }

    SHR_FUNC_EXIT;
}

shr_error_e
dnx_data_dnx2_arr_formats_ETPPC_TERM_ETPS_ARR_2_CONFIGURATION_entry_str_get(
    int unit,
    char *buffer,
    int key0,
    int key1,
    int value_index)
{
    dnxc_data_table_t *table;
    const dnx_data_dnx2_arr_formats_ETPPC_TERM_ETPS_ARR_2_CONFIGURATION_t *data;
    SHR_FUNC_INIT_VARS(unit);

    
    table = dnxc_data_mgmt_table_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_formats, dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_2_CONFIGURATION);
    data = (const dnx_data_dnx2_arr_formats_ETPPC_TERM_ETPS_ARR_2_CONFIGURATION_t *) dnxc_data_mgmt_table_data_diag_get(unit, table, key0, 0);
    switch (value_index)
    {
        case 0:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->valid);
            break;
        case 1:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%s", data->doc == NULL ? "" : data->doc);
            break;
        case 2:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->QOS_MODEL_CONFIG);
            break;
        case 3:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->QOS_MODEL_CONFIG_valid);
            break;
        case 4:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->NWK_QOS_IDX_CONFIG);
            break;
        case 5:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->NWK_QOS_IDX_CONFIG_valid);
            break;
        case 6:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->OUTLIF_PROFILE_CONFIG);
            break;
        case 7:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->OUTLIF_PROFILE_CONFIG_valid);
            break;
        case 8:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->REMARK_PROFILE_CONFIG);
            break;
        case 9:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->REMARK_PROFILE_CONFIG_valid);
            break;
        case 10:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->TTL_MODEL_CONFIG);
            break;
        case 11:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->TTL_MODEL_CONFIG_valid);
            break;
    }

    SHR_FUNC_EXIT;
}

shr_error_e
dnx_data_dnx2_arr_formats_IPPB_EXPECTED_ARR_FORMAT_CONFIG_entry_str_get(
    int unit,
    char *buffer,
    int key0,
    int key1,
    int value_index)
{
    dnxc_data_table_t *table;
    const dnx_data_dnx2_arr_formats_IPPB_EXPECTED_ARR_FORMAT_CONFIG_t *data;
    SHR_FUNC_INIT_VARS(unit);

    
    table = dnxc_data_mgmt_table_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_formats, dnx_data_dnx2_arr_formats_table_IPPB_EXPECTED_ARR_FORMAT_CONFIG);
    data = (const dnx_data_dnx2_arr_formats_IPPB_EXPECTED_ARR_FORMAT_CONFIG_t *) dnxc_data_mgmt_table_data_diag_get(unit, table, key0, 0);
    switch (value_index)
    {
        case 0:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->valid);
            break;
        case 1:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%s", data->doc == NULL ? "" : data->doc);
            break;
        case 2:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->DESTINATION);
            break;
        case 3:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->DESTINATION_valid);
            break;
        case 4:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->DATA_1);
            break;
        case 5:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->DATA_1_valid);
            break;
        case 6:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->DATA_2);
            break;
        case 7:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->DATA_2_valid);
            break;
        case 8:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->TYPE);
            break;
        case 9:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->TYPE_valid);
            break;
        case 10:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->STRENGTH);
            break;
        case 11:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->STRENGTH_valid);
            break;
    }

    SHR_FUNC_EXIT;
}

shr_error_e
dnx_data_dnx2_arr_formats_MACT_MRQ_ARR_CFG_entry_str_get(
    int unit,
    char *buffer,
    int key0,
    int key1,
    int value_index)
{
    dnxc_data_table_t *table;
    const dnx_data_dnx2_arr_formats_MACT_MRQ_ARR_CFG_t *data;
    SHR_FUNC_INIT_VARS(unit);

    
    table = dnxc_data_mgmt_table_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_formats, dnx_data_dnx2_arr_formats_table_MACT_MRQ_ARR_CFG);
    data = (const dnx_data_dnx2_arr_formats_MACT_MRQ_ARR_CFG_t *) dnxc_data_mgmt_table_data_diag_get(unit, table, key0, 0);
    switch (value_index)
    {
        case 0:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->valid);
            break;
        case 1:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%s", data->doc == NULL ? "" : data->doc);
            break;
        case 2:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->STRENGTH);
            break;
        case 3:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->STRENGTH_valid);
            break;
    }

    SHR_FUNC_EXIT;
}

shr_error_e
dnx_data_dnx2_arr_formats_IPPB_ACCEPTED_ARR_FORMAT_CONFIG_entry_str_get(
    int unit,
    char *buffer,
    int key0,
    int key1,
    int value_index)
{
    dnxc_data_table_t *table;
    const dnx_data_dnx2_arr_formats_IPPB_ACCEPTED_ARR_FORMAT_CONFIG_t *data;
    SHR_FUNC_INIT_VARS(unit);

    
    table = dnxc_data_mgmt_table_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_formats, dnx_data_dnx2_arr_formats_table_IPPB_ACCEPTED_ARR_FORMAT_CONFIG);
    data = (const dnx_data_dnx2_arr_formats_IPPB_ACCEPTED_ARR_FORMAT_CONFIG_t *) dnxc_data_mgmt_table_data_diag_get(unit, table, key0, 0);
    switch (value_index)
    {
        case 0:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->valid);
            break;
        case 1:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%s", data->doc == NULL ? "" : data->doc);
            break;
        case 2:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->DESTINATION);
            break;
        case 3:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->DESTINATION_valid);
            break;
        case 4:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->DATA_1);
            break;
        case 5:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->DATA_1_valid);
            break;
        case 6:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->DATA_2);
            break;
        case 7:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->DATA_2_valid);
            break;
        case 8:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->TYPE);
            break;
        case 9:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->TYPE_valid);
            break;
        case 10:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->STRENGTH);
            break;
        case 11:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->STRENGTH_valid);
            break;
    }

    SHR_FUNC_EXIT;
}

shr_error_e
dnx_data_dnx2_arr_formats_IPPD_FEC_FORMAT_CONFIGURATION_TABLE___array_entry_str_get(
    int unit,
    char *buffer,
    int key0,
    int key1,
    int value_index)
{
    dnxc_data_table_t *table;
    const dnx_data_dnx2_arr_formats_IPPD_FEC_FORMAT_CONFIGURATION_TABLE___array_t *data;
    SHR_FUNC_INIT_VARS(unit);

    
    table = dnxc_data_mgmt_table_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_formats, dnx_data_dnx2_arr_formats_table_IPPD_FEC_FORMAT_CONFIGURATION_TABLE___array);
    data = (const dnx_data_dnx2_arr_formats_IPPD_FEC_FORMAT_CONFIGURATION_TABLE___array_t *) dnxc_data_mgmt_table_data_diag_get(unit, table, key0, key1);
    switch (value_index)
    {
        case 0:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->valid);
            break;
        case 1:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%s", data->doc == NULL ? "" : data->doc);
            break;
        case 2:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->DESTINATION_CONFIG);
            break;
        case 3:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->DESTINATION_CONFIG_valid);
            break;
        case 4:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->EEI_CONFIG);
            break;
        case 5:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->EEI_CONFIG_valid);
            break;
        case 6:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->OUT_LIF_0_CONFIG);
            break;
        case 7:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->OUT_LIF_0_CONFIG_valid);
            break;
        case 8:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->OUT_LIF_1_CONFIG);
            break;
        case 9:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->OUT_LIF_1_CONFIG_valid);
            break;
        case 10:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->WEAK_TM_FLOW_CONFIG);
            break;
        case 11:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->WEAK_TM_FLOW_CONFIG_valid);
            break;
        case 12:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->MC_RPF_MODE_CONFIG);
            break;
        case 13:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->MC_RPF_MODE_CONFIG_valid);
            break;
    }

    SHR_FUNC_EXIT;
}

shr_error_e
dnx_data_dnx2_arr_formats_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array_entry_str_get(
    int unit,
    char *buffer,
    int key0,
    int key1,
    int value_index)
{
    dnxc_data_table_t *table;
    const dnx_data_dnx2_arr_formats_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array_t *data;
    SHR_FUNC_INIT_VARS(unit);

    
    table = dnxc_data_mgmt_table_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_formats, dnx_data_dnx2_arr_formats_table_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array);
    data = (const dnx_data_dnx2_arr_formats_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array_t *) dnxc_data_mgmt_table_data_diag_get(unit, table, key0, key1);
    switch (value_index)
    {
        case 0:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->valid);
            break;
        case 1:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%s", data->doc == NULL ? "" : data->doc);
            break;
        case 2:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->AGING_CONFIG);
            break;
        case 3:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->AGING_CONFIG_valid);
            break;
        case 4:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->DESTINATION_CONFIG);
            break;
        case 5:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->DESTINATION_CONFIG_valid);
            break;
        case 6:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->EEI_CONFIG);
            break;
        case 7:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->EEI_CONFIG_valid);
            break;
        case 8:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->ENTRY_GROUPING_CONFIG);
            break;
        case 9:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->ENTRY_GROUPING_CONFIG_valid);
            break;
        case 10:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->OUTLIF_0_CONFIG);
            break;
        case 11:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->OUTLIF_0_CONFIG_valid);
            break;
        case 12:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->OUTLIF_1_CONFIG);
            break;
        case 13:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->OUTLIF_1_CONFIG_valid);
            break;
        case 14:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->IRPP_FWD_RAW_DATA);
            break;
        case 15:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->IRPP_FWD_RAW_DATA_valid);
            break;
        case 16:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->DEFAULT_CONFIG);
            break;
        case 17:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->DEFAULT_CONFIG_valid);
            break;
        case 18:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->MAC_ENTRY_STRENGTH_CONFIG);
            break;
        case 19:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->MAC_ENTRY_STRENGTH_CONFIG_valid);
            break;
        case 20:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->STAT_OBJ_CMD_CONFIG);
            break;
        case 21:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->STAT_OBJ_CMD_CONFIG_valid);
            break;
        case 22:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->STAT_OBJ_ID_CONFIG);
            break;
        case 23:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->STAT_OBJ_ID_CONFIG_valid);
            break;
        case 24:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->UNKNOWN_ADDR_CONFIG);
            break;
        case 25:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->UNKNOWN_ADDR_CONFIG_valid);
            break;
    }

    SHR_FUNC_EXIT;
}

shr_error_e
dnx_data_dnx2_arr_formats_IPPB_FLP_RPF_FORMAT_CONFIGURATION_TABLE___array_entry_str_get(
    int unit,
    char *buffer,
    int key0,
    int key1,
    int value_index)
{
    dnxc_data_table_t *table;
    const dnx_data_dnx2_arr_formats_IPPB_FLP_RPF_FORMAT_CONFIGURATION_TABLE___array_t *data;
    SHR_FUNC_INIT_VARS(unit);

    
    table = dnxc_data_mgmt_table_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_formats, dnx_data_dnx2_arr_formats_table_IPPB_FLP_RPF_FORMAT_CONFIGURATION_TABLE___array);
    data = (const dnx_data_dnx2_arr_formats_IPPB_FLP_RPF_FORMAT_CONFIGURATION_TABLE___array_t *) dnxc_data_mgmt_table_data_diag_get(unit, table, key0, key1);
    switch (value_index)
    {
        case 0:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->valid);
            break;
        case 1:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%s", data->doc == NULL ? "" : data->doc);
            break;
        case 2:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->DESTINATION_CONFIG);
            break;
        case 3:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->DESTINATION_CONFIG_valid);
            break;
        case 4:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->OUTLIF_0_CONFIG);
            break;
        case 5:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->OUTLIF_0_CONFIG_valid);
            break;
        case 6:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->DEFAULT_CONFIG);
            break;
        case 7:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->DEFAULT_CONFIG_valid);
            break;
        case 8:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->OPAQUE_FIELD_CONFIG);
            break;
        case 9:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->OPAQUE_FIELD_CONFIG_valid);
            break;
        case 10:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->SA_DROP_CONFIG);
            break;
        case 11:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->SA_DROP_CONFIG_valid);
            break;
        case 12:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->STAT_OBJ_CMD_CONFIG);
            break;
        case 13:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->STAT_OBJ_CMD_CONFIG_valid);
            break;
        case 14:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->STAT_OBJ_ID_CONFIG);
            break;
        case 15:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->STAT_OBJ_ID_CONFIG_valid);
            break;
    }

    SHR_FUNC_EXIT;
}

shr_error_e
dnx_data_dnx2_arr_formats_IPPD_SUPER_ARR_FORMAT_CONFIGURATION_TABLE___array_entry_str_get(
    int unit,
    char *buffer,
    int key0,
    int key1,
    int value_index)
{
    dnxc_data_table_t *table;
    const dnx_data_dnx2_arr_formats_IPPD_SUPER_ARR_FORMAT_CONFIGURATION_TABLE___array_t *data;
    SHR_FUNC_INIT_VARS(unit);

    
    table = dnxc_data_mgmt_table_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_formats, dnx_data_dnx2_arr_formats_table_IPPD_SUPER_ARR_FORMAT_CONFIGURATION_TABLE___array);
    data = (const dnx_data_dnx2_arr_formats_IPPD_SUPER_ARR_FORMAT_CONFIGURATION_TABLE___array_t *) dnxc_data_mgmt_table_data_diag_get(unit, table, key0, key1);
    switch (value_index)
    {
        case 0:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->valid);
            break;
        case 1:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%s", data->doc == NULL ? "" : data->doc);
            break;
        case 2:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->LEFT_CONFIG);
            break;
        case 3:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->LEFT_CONFIG_valid);
            break;
        case 4:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->LEFT_STAT_OBJECT_CMD_CONFIG);
            break;
        case 5:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->LEFT_STAT_OBJECT_CMD_CONFIG_valid);
            break;
        case 6:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->LEFT_STAT_OBJECT_ID_CONFIG);
            break;
        case 7:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->LEFT_STAT_OBJECT_ID_CONFIG_valid);
            break;
        case 8:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->PROTECTION_PTR_CONFIG);
            break;
        case 9:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->PROTECTION_PTR_CONFIG_valid);
            break;
        case 10:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->RIGHT_CONFIG);
            break;
        case 11:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->RIGHT_CONFIG_valid);
            break;
        case 12:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->RIGHT_STAT_OBJECT_CMD_CONFIG);
            break;
        case 13:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->RIGHT_STAT_OBJECT_CMD_CONFIG_valid);
            break;
        case 14:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->RIGHT_STAT_OBJECT_ID_CONFIG);
            break;
        case 15:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->RIGHT_STAT_OBJECT_ID_CONFIG_valid);
            break;
    }

    SHR_FUNC_EXIT;
}

shr_error_e
dnx_data_dnx2_arr_formats_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1_entry_str_get(
    int unit,
    char *buffer,
    int key0,
    int key1,
    int value_index)
{
    dnxc_data_table_t *table;
    const dnx_data_dnx2_arr_formats_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1_t *data;
    SHR_FUNC_INIT_VARS(unit);

    
    table = dnxc_data_mgmt_table_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_formats, dnx_data_dnx2_arr_formats_table_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1);
    data = (const dnx_data_dnx2_arr_formats_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1_t *) dnxc_data_mgmt_table_data_diag_get(unit, table, key0, 0);
    switch (value_index)
    {
        case 0:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->valid);
            break;
        case 1:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%s", data->doc == NULL ? "" : data->doc);
            break;
        case 2:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->DA_NOT_FOUND_DESTINATION_CONFIG);
            break;
        case 3:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->DA_NOT_FOUND_DESTINATION_CONFIG_valid);
            break;
        case 4:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->ECN_MAPPING_PROFILE_CONFIG);
            break;
        case 5:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->ECN_MAPPING_PROFILE_CONFIG_valid);
            break;
        case 6:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->MY_MAC_CONFIG);
            break;
        case 7:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->MY_MAC_CONFIG_valid);
            break;
        case 8:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->MY_MAC_PREFIX_CONFIG);
            break;
        case 9:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->MY_MAC_PREFIX_CONFIG_valid);
            break;
        case 10:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->PROPAGATION_PROFILE_CONFIG);
            break;
        case 11:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->PROPAGATION_PROFILE_CONFIG_valid);
            break;
        case 12:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->QOS_PROFILE_CONFIG);
            break;
        case 13:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->QOS_PROFILE_CONFIG_valid);
            break;
        case 14:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->STAT_OBJ_CMD_CONFIG);
            break;
        case 15:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->STAT_OBJ_CMD_CONFIG_valid);
            break;
        case 16:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->STAT_OBJ_ID_CONFIG);
            break;
        case 17:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->STAT_OBJ_ID_CONFIG_valid);
            break;
        case 18:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->TOPOLOGY_ID_CONFIG);
            break;
        case 19:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->TOPOLOGY_ID_CONFIG_valid);
            break;
        case 20:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->VRF_CONFIG);
            break;
        case 21:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->VRF_CONFIG_valid);
            break;
        case 22:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->VRID_BITMAP_CONFIG);
            break;
        case 23:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->VRID_BITMAP_CONFIG_valid);
            break;
        case 24:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->VSI_PROFILE_CONFIG);
            break;
        case 25:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->VSI_PROFILE_CONFIG_valid);
            break;
    }

    SHR_FUNC_EXIT;
}

shr_error_e
dnx_data_dnx2_arr_formats_IPPF_VSI_FORMAT_CONFIGURATION_TABLE_entry_str_get(
    int unit,
    char *buffer,
    int key0,
    int key1,
    int value_index)
{
    dnxc_data_table_t *table;
    const dnx_data_dnx2_arr_formats_IPPF_VSI_FORMAT_CONFIGURATION_TABLE_t *data;
    SHR_FUNC_INIT_VARS(unit);

    
    table = dnxc_data_mgmt_table_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_formats, dnx_data_dnx2_arr_formats_table_IPPF_VSI_FORMAT_CONFIGURATION_TABLE);
    data = (const dnx_data_dnx2_arr_formats_IPPF_VSI_FORMAT_CONFIGURATION_TABLE_t *) dnxc_data_mgmt_table_data_diag_get(unit, table, key0, 0);
    switch (value_index)
    {
        case 0:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->valid);
            break;
        case 1:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%s", data->doc == NULL ? "" : data->doc);
            break;
        case 2:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->DA_NOT_FOUND_DESTINATION_CONFIG);
            break;
        case 3:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->DA_NOT_FOUND_DESTINATION_CONFIG_valid);
            break;
        case 4:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->ECN_MAPPING_PROFILE_CONFIG);
            break;
        case 5:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->ECN_MAPPING_PROFILE_CONFIG_valid);
            break;
        case 6:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->MY_MAC_CONFIG);
            break;
        case 7:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->MY_MAC_CONFIG_valid);
            break;
        case 8:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->MY_MAC_PREFIX_CONFIG);
            break;
        case 9:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->MY_MAC_PREFIX_CONFIG_valid);
            break;
        case 10:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->PROPAGATION_PROFILE_CONFIG);
            break;
        case 11:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->PROPAGATION_PROFILE_CONFIG_valid);
            break;
        case 12:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->QOS_PROFILE_CONFIG);
            break;
        case 13:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->QOS_PROFILE_CONFIG_valid);
            break;
        case 14:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->STAT_OBJ_CMD_CONFIG);
            break;
        case 15:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->STAT_OBJ_CMD_CONFIG_valid);
            break;
        case 16:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->STAT_OBJ_ID_CONFIG);
            break;
        case 17:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->STAT_OBJ_ID_CONFIG_valid);
            break;
        case 18:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->TOPOLOGY_ID_CONFIG);
            break;
        case 19:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->TOPOLOGY_ID_CONFIG_valid);
            break;
        case 20:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->VRF_CONFIG);
            break;
        case 21:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->VRF_CONFIG_valid);
            break;
        case 22:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->VRID_BITMAP_CONFIG);
            break;
        case 23:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->VRID_BITMAP_CONFIG_valid);
            break;
        case 24:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->VSI_PROFILE_CONFIG);
            break;
        case 25:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->VSI_PROFILE_CONFIG_valid);
            break;
    }

    SHR_FUNC_EXIT;
}

shr_error_e
dnx_data_dnx2_arr_formats_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array_entry_str_get(
    int unit,
    char *buffer,
    int key0,
    int key1,
    int value_index)
{
    dnxc_data_table_t *table;
    const dnx_data_dnx2_arr_formats_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array_t *data;
    SHR_FUNC_INIT_VARS(unit);

    
    table = dnxc_data_mgmt_table_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_formats, dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array);
    data = (const dnx_data_dnx2_arr_formats_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array_t *) dnxc_data_mgmt_table_data_diag_get(unit, table, key0, key1);
    switch (value_index)
    {
        case 0:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->valid);
            break;
        case 1:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%s", data->doc == NULL ? "" : data->doc);
            break;
        case 2:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->ACTION_PROFILE_IDX_CONFIG);
            break;
        case 3:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->ACTION_PROFILE_IDX_CONFIG_valid);
            break;
        case 4:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->DESTINATION_CONFIG);
            break;
        case 5:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->DESTINATION_CONFIG_valid);
            break;
        case 6:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->ECN_MAPPING_PROFILE_CONFIG);
            break;
        case 7:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->ECN_MAPPING_PROFILE_CONFIG_valid);
            break;
        case 8:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->EEI_CONFIG);
            break;
        case 9:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->EEI_CONFIG_valid);
            break;
        case 10:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->FORWARD_DOMAIN_CONFIG);
            break;
        case 11:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->FORWARD_DOMAIN_CONFIG_valid);
            break;
        case 12:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->FORWARD_DOMAIN_ASSIGNMENT_MODE_CONFIG);
            break;
        case 13:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->FORWARD_DOMAIN_ASSIGNMENT_MODE_CONFIG_valid);
            break;
        case 14:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->SYS_INLIF_CONFIG);
            break;
        case 15:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->SYS_INLIF_CONFIG_valid);
            break;
        case 16:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->OUT_LIF_CONFIG);
            break;
        case 17:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->OUT_LIF_CONFIG_valid);
            break;
        case 18:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->LIF_PROFILE_CONFIG);
            break;
        case 19:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->LIF_PROFILE_CONFIG_valid);
            break;
        case 20:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->LEARN_EN_CONFIG);
            break;
        case 21:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->LEARN_EN_CONFIG_valid);
            break;
        case 22:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->LEARN_INFO_CONFIG);
            break;
        case 23:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->LEARN_INFO_CONFIG_valid);
            break;
        case 24:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->LEARN_PAYLOAD_CONTEXT_CONFIG);
            break;
        case 25:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->LEARN_PAYLOAD_CONTEXT_CONFIG_valid);
            break;
        case 26:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->LIF_GENERIC_DATA_0_CONFIG);
            break;
        case 27:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->LIF_GENERIC_DATA_0_CONFIG_valid);
            break;
        case 28:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->LIF_GENERIC_DATA_1_CONFIG);
            break;
        case 29:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->LIF_GENERIC_DATA_1_CONFIG_valid);
            break;
        case 30:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->PROTECTION_PTR_CONFIG);
            break;
        case 31:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->PROTECTION_PTR_CONFIG_valid);
            break;
        case 32:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->NEXT_LAYER_NETWORK_DOMAIN_CONFIG);
            break;
        case 33:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->NEXT_LAYER_NETWORK_DOMAIN_CONFIG_valid);
            break;
        case 34:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->NEXT_PARSER_CONTEXT_CONFIG);
            break;
        case 35:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->NEXT_PARSER_CONTEXT_CONFIG_valid);
            break;
        case 36:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->OAM_LIF_SET_CONFIG);
            break;
        case 37:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->OAM_LIF_SET_CONFIG_valid);
            break;
        case 38:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->PROPAGATION_PROFILE_CONFIG);
            break;
        case 39:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->PROPAGATION_PROFILE_CONFIG_valid);
            break;
        case 40:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->PROTECTION_PATH_CONFIG);
            break;
        case 41:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->PROTECTION_PATH_CONFIG_valid);
            break;
        case 42:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->QOS_PROFILE_CONFIG);
            break;
        case 43:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->QOS_PROFILE_CONFIG_valid);
            break;
        case 44:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->RESEREVED);
            break;
        case 45:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->RESEREVED_valid);
            break;
        case 46:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->SERVICE_TYPE_CONFIG);
            break;
        case 47:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->SERVICE_TYPE_CONFIG_valid);
            break;
        case 48:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->STAT_OBJ_CMD_CONFIG);
            break;
        case 49:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->STAT_OBJ_CMD_CONFIG_valid);
            break;
        case 50:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->STAT_OBJ_ID_CONFIG);
            break;
        case 51:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->STAT_OBJ_ID_CONFIG_valid);
            break;
        case 52:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->TERMINATION_TYPE_CONFIG);
            break;
        case 53:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->TERMINATION_TYPE_CONFIG_valid);
            break;
        case 54:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->VLAN_EDIT_PCP_DEI_PROFILE_CONFIG);
            break;
        case 55:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->VLAN_EDIT_PCP_DEI_PROFILE_CONFIG_valid);
            break;
        case 56:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->VLAN_EDIT_PROFILE_CONFIG);
            break;
        case 57:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->VLAN_EDIT_PROFILE_CONFIG_valid);
            break;
        case 58:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->VLAN_EDIT_VID_1_CONFIG);
            break;
        case 59:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->VLAN_EDIT_VID_1_CONFIG_valid);
            break;
        case 60:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->VLAN_EDIT_VID_2_CONFIG);
            break;
        case 61:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->VLAN_EDIT_VID_2_CONFIG_valid);
            break;
        case 62:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->VLAN_MEMBER_IF_CONFIG);
            break;
        case 63:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->VLAN_MEMBER_IF_CONFIG_valid);
            break;
    }

    SHR_FUNC_EXIT;
}

shr_error_e
dnx_data_dnx2_arr_formats_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array_entry_str_get(
    int unit,
    char *buffer,
    int key0,
    int key1,
    int value_index)
{
    dnxc_data_table_t *table;
    const dnx_data_dnx2_arr_formats_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array_t *data;
    SHR_FUNC_INIT_VARS(unit);

    
    table = dnxc_data_mgmt_table_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_formats, dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array);
    data = (const dnx_data_dnx2_arr_formats_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array_t *) dnxc_data_mgmt_table_data_diag_get(unit, table, key0, key1);
    switch (value_index)
    {
        case 0:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->valid);
            break;
        case 1:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%s", data->doc == NULL ? "" : data->doc);
            break;
        case 2:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->ACTION_PROFILE_IDX_CONFIG);
            break;
        case 3:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->ACTION_PROFILE_IDX_CONFIG_valid);
            break;
        case 4:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->DESTINATION_CONFIG);
            break;
        case 5:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->DESTINATION_CONFIG_valid);
            break;
        case 6:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->ECN_MAPPING_PROFILE_CONFIG);
            break;
        case 7:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->ECN_MAPPING_PROFILE_CONFIG_valid);
            break;
        case 8:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->EEI_CONFIG);
            break;
        case 9:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->EEI_CONFIG_valid);
            break;
        case 10:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->FORWARD_DOMAIN_CONFIG);
            break;
        case 11:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->FORWARD_DOMAIN_CONFIG_valid);
            break;
        case 12:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->FORWARD_DOMAIN_ASSIGNMENT_MODE_CONFIG);
            break;
        case 13:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->FORWARD_DOMAIN_ASSIGNMENT_MODE_CONFIG_valid);
            break;
        case 14:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->SYS_INLIF_CONFIG);
            break;
        case 15:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->SYS_INLIF_CONFIG_valid);
            break;
        case 16:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->OUT_LIF_CONFIG);
            break;
        case 17:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->OUT_LIF_CONFIG_valid);
            break;
        case 18:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->LIF_PROFILE_CONFIG);
            break;
        case 19:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->LIF_PROFILE_CONFIG_valid);
            break;
        case 20:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->LEARN_EN_CONFIG);
            break;
        case 21:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->LEARN_EN_CONFIG_valid);
            break;
        case 22:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->LEARN_INFO_CONFIG);
            break;
        case 23:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->LEARN_INFO_CONFIG_valid);
            break;
        case 24:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->LEARN_PAYLOAD_CONTEXT_CONFIG);
            break;
        case 25:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->LEARN_PAYLOAD_CONTEXT_CONFIG_valid);
            break;
        case 26:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->LIF_GENERIC_DATA_0_CONFIG);
            break;
        case 27:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->LIF_GENERIC_DATA_0_CONFIG_valid);
            break;
        case 28:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->LIF_GENERIC_DATA_1_CONFIG);
            break;
        case 29:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->LIF_GENERIC_DATA_1_CONFIG_valid);
            break;
        case 30:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->PROTECTION_PTR_CONFIG);
            break;
        case 31:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->PROTECTION_PTR_CONFIG_valid);
            break;
        case 32:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->NEXT_LAYER_NETWORK_DOMAIN_CONFIG);
            break;
        case 33:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->NEXT_LAYER_NETWORK_DOMAIN_CONFIG_valid);
            break;
        case 34:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->NEXT_PARSER_CONTEXT_CONFIG);
            break;
        case 35:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->NEXT_PARSER_CONTEXT_CONFIG_valid);
            break;
        case 36:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->OAM_LIF_SET_CONFIG);
            break;
        case 37:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->OAM_LIF_SET_CONFIG_valid);
            break;
        case 38:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->PROPAGATION_PROFILE_CONFIG);
            break;
        case 39:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->PROPAGATION_PROFILE_CONFIG_valid);
            break;
        case 40:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->PROTECTION_PATH_CONFIG);
            break;
        case 41:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->PROTECTION_PATH_CONFIG_valid);
            break;
        case 42:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->QOS_PROFILE_CONFIG);
            break;
        case 43:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->QOS_PROFILE_CONFIG_valid);
            break;
        case 44:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->RESEREVED);
            break;
        case 45:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->RESEREVED_valid);
            break;
        case 46:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->SERVICE_TYPE_CONFIG);
            break;
        case 47:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->SERVICE_TYPE_CONFIG_valid);
            break;
        case 48:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->STAT_OBJ_CMD_CONFIG);
            break;
        case 49:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->STAT_OBJ_CMD_CONFIG_valid);
            break;
        case 50:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->STAT_OBJ_ID_CONFIG);
            break;
        case 51:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->STAT_OBJ_ID_CONFIG_valid);
            break;
        case 52:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->TERMINATION_TYPE_CONFIG);
            break;
        case 53:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->TERMINATION_TYPE_CONFIG_valid);
            break;
        case 54:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->VLAN_EDIT_PCP_DEI_PROFILE_CONFIG);
            break;
        case 55:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->VLAN_EDIT_PCP_DEI_PROFILE_CONFIG_valid);
            break;
        case 56:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->VLAN_EDIT_PROFILE_CONFIG);
            break;
        case 57:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->VLAN_EDIT_PROFILE_CONFIG_valid);
            break;
        case 58:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->VLAN_EDIT_VID_1_CONFIG);
            break;
        case 59:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->VLAN_EDIT_VID_1_CONFIG_valid);
            break;
        case 60:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->VLAN_EDIT_VID_2_CONFIG);
            break;
        case 61:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->VLAN_EDIT_VID_2_CONFIG_valid);
            break;
        case 62:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->VLAN_MEMBER_IF_CONFIG);
            break;
        case 63:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->VLAN_MEMBER_IF_CONFIG_valid);
            break;
    }

    SHR_FUNC_EXIT;
}

shr_error_e
dnx_data_dnx2_arr_formats_IPPD_LEARN_ARR_CONFIGURATION_TABLE_entry_str_get(
    int unit,
    char *buffer,
    int key0,
    int key1,
    int value_index)
{
    dnxc_data_table_t *table;
    const dnx_data_dnx2_arr_formats_IPPD_LEARN_ARR_CONFIGURATION_TABLE_t *data;
    SHR_FUNC_INIT_VARS(unit);

    
    table = dnxc_data_mgmt_table_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_formats, dnx_data_dnx2_arr_formats_table_IPPD_LEARN_ARR_CONFIGURATION_TABLE);
    data = (const dnx_data_dnx2_arr_formats_IPPD_LEARN_ARR_CONFIGURATION_TABLE_t *) dnxc_data_mgmt_table_data_diag_get(unit, table, key0, 0);
    switch (value_index)
    {
        case 0:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->valid);
            break;
        case 1:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%s", data->doc == NULL ? "" : data->doc);
            break;
        case 2:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->DESTINATION_CONFIG);
            break;
        case 3:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->DESTINATION_CONFIG_valid);
            break;
        case 4:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->EEI_CONFIG);
            break;
        case 5:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->EEI_CONFIG_valid);
            break;
        case 6:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->OUTLIF_CONFIG);
            break;
        case 7:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->OUTLIF_CONFIG_valid);
            break;
    }

    SHR_FUNC_EXIT;
}

shr_error_e
dnx_data_dnx2_arr_formats_OLP_LEARN_ARR_CONFIGURATION_TABLE_entry_str_get(
    int unit,
    char *buffer,
    int key0,
    int key1,
    int value_index)
{
    dnxc_data_table_t *table;
    const dnx_data_dnx2_arr_formats_OLP_LEARN_ARR_CONFIGURATION_TABLE_t *data;
    SHR_FUNC_INIT_VARS(unit);

    
    table = dnxc_data_mgmt_table_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_formats, dnx_data_dnx2_arr_formats_table_OLP_LEARN_ARR_CONFIGURATION_TABLE);
    data = (const dnx_data_dnx2_arr_formats_OLP_LEARN_ARR_CONFIGURATION_TABLE_t *) dnxc_data_mgmt_table_data_diag_get(unit, table, key0, 0);
    switch (value_index)
    {
        case 0:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->valid);
            break;
        case 1:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%s", data->doc == NULL ? "" : data->doc);
            break;
        case 2:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->DESTINATION_CONFIG);
            break;
        case 3:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->DESTINATION_CONFIG_valid);
            break;
        case 4:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->EEI_CONFIG);
            break;
        case 5:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->EEI_CONFIG_valid);
            break;
        case 6:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->OUTLIF_CONFIG);
            break;
        case 7:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->OUTLIF_CONFIG_valid);
            break;
    }

    SHR_FUNC_EXIT;
}

shr_error_e
dnx_data_dnx2_arr_formats_ERPP_EGRESS_MCDB_FORMAT_CFG_entry_str_get(
    int unit,
    char *buffer,
    int key0,
    int key1,
    int value_index)
{
    dnxc_data_table_t *table;
    const dnx_data_dnx2_arr_formats_ERPP_EGRESS_MCDB_FORMAT_CFG_t *data;
    SHR_FUNC_INIT_VARS(unit);

    
    table = dnxc_data_mgmt_table_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_formats, dnx_data_dnx2_arr_formats_table_ERPP_EGRESS_MCDB_FORMAT_CFG);
    data = (const dnx_data_dnx2_arr_formats_ERPP_EGRESS_MCDB_FORMAT_CFG_t *) dnxc_data_mgmt_table_data_diag_get(unit, table, key0, 0);
    switch (value_index)
    {
        case 0:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->valid);
            break;
        case 1:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%s", data->doc == NULL ? "" : data->doc);
            break;
        case 2:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->MCDB_OUTLIF_0_CONFIG);
            break;
        case 3:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->MCDB_OUTLIF_0_CONFIG_valid);
            break;
        case 4:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->MCDB_OUTLIF_1_CONFIG);
            break;
        case 5:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->MCDB_OUTLIF_1_CONFIG_valid);
            break;
        case 6:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->MCDB_OUTLIF_2_CONFIG);
            break;
        case 7:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->MCDB_OUTLIF_2_CONFIG_valid);
            break;
    }

    SHR_FUNC_EXIT;
}


const dnxc_data_table_info_t *
dnx_data_dnx2_arr_formats_files_info_get(
    int unit)
{

    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "files", "DNX2");
    }
    
    return dnxc_data_mgmt_table_info_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_formats, dnx_data_dnx2_arr_formats_table_files);

}

const dnxc_data_table_info_t *
dnx_data_dnx2_arr_formats_MACT_AGE_PROFILE_ARR_CFG_info_get(
    int unit)
{

    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "MACT_AGE_PROFILE_ARR_CFG", "DNX2");
    }
    
    return dnxc_data_mgmt_table_info_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_formats, dnx_data_dnx2_arr_formats_table_MACT_AGE_PROFILE_ARR_CFG);

}

const dnxc_data_table_info_t *
dnx_data_dnx2_arr_formats_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE_info_get(
    int unit)
{

    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE", "DNX2");
    }
    
    return dnxc_data_mgmt_table_info_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_formats, dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_0_FORMAT_CONFIGURATION_TABLE);

}

const dnxc_data_table_info_t *
dnx_data_dnx2_arr_formats_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE_info_get(
    int unit)
{

    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE", "DNX2");
    }
    
    return dnxc_data_mgmt_table_info_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_formats, dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_0_FORMAT_CONFIGURATION_TABLE);

}

const dnxc_data_table_info_t *
dnx_data_dnx2_arr_formats_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE_info_get(
    int unit)
{

    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE", "DNX2");
    }
    
    return dnxc_data_mgmt_table_info_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_formats, dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_0_FORMAT_CONFIGURATION_TABLE);

}

const dnxc_data_table_info_t *
dnx_data_dnx2_arr_formats_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE_info_get(
    int unit)
{

    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE", "DNX2");
    }
    
    return dnxc_data_mgmt_table_info_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_formats, dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_0_FORMAT_CONFIGURATION_TABLE);

}

const dnxc_data_table_info_t *
dnx_data_dnx2_arr_formats_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE_info_get(
    int unit)
{

    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE", "DNX2");
    }
    
    return dnxc_data_mgmt_table_info_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_formats, dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_0_FORMAT_CONFIGURATION_TABLE);

}

const dnxc_data_table_info_t *
dnx_data_dnx2_arr_formats_ETPPB_ENC_FORMAT_CONFIGURATION_TABLE_info_get(
    int unit)
{

    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "ETPPB_ENC_FORMAT_CONFIGURATION_TABLE", "DNX2");
    }
    
    return dnxc_data_mgmt_table_info_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_formats, dnx_data_dnx2_arr_formats_table_ETPPB_ENC_FORMAT_CONFIGURATION_TABLE);

}

const dnxc_data_table_info_t *
dnx_data_dnx2_arr_formats_ETPPC_ENC_FORMAT_CONFIGURATION_TABLE_info_get(
    int unit)
{

    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "ETPPC_ENC_FORMAT_CONFIGURATION_TABLE", "DNX2");
    }
    
    return dnxc_data_mgmt_table_info_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_formats, dnx_data_dnx2_arr_formats_table_ETPPC_ENC_FORMAT_CONFIGURATION_TABLE);

}

const dnxc_data_table_info_t *
dnx_data_dnx2_arr_formats_ETPPB_ENC_2_ARR_1_FORMAT_CONFIGURATION_TABLE_info_get(
    int unit)
{

    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "ETPPB_ENC_2_ARR_1_FORMAT_CONFIGURATION_TABLE", "DNX2");
    }
    
    return dnxc_data_mgmt_table_info_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_formats, dnx_data_dnx2_arr_formats_table_ETPPB_ENC_2_ARR_1_FORMAT_CONFIGURATION_TABLE);

}

const dnxc_data_table_info_t *
dnx_data_dnx2_arr_formats_ETPPB_ENC_3_ARR_1_FORMAT_CONFIGURATION_TABLE_info_get(
    int unit)
{

    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "ETPPB_ENC_3_ARR_1_FORMAT_CONFIGURATION_TABLE", "DNX2");
    }
    
    return dnxc_data_mgmt_table_info_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_formats, dnx_data_dnx2_arr_formats_table_ETPPB_ENC_3_ARR_1_FORMAT_CONFIGURATION_TABLE);

}

const dnxc_data_table_info_t *
dnx_data_dnx2_arr_formats_ETPPB_ENC_4_ARR_1_FORMAT_CONFIGURATION_TABLE_info_get(
    int unit)
{

    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "ETPPB_ENC_4_ARR_1_FORMAT_CONFIGURATION_TABLE", "DNX2");
    }
    
    return dnxc_data_mgmt_table_info_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_formats, dnx_data_dnx2_arr_formats_table_ETPPB_ENC_4_ARR_1_FORMAT_CONFIGURATION_TABLE);

}

const dnxc_data_table_info_t *
dnx_data_dnx2_arr_formats_ETPPB_ENC_5_ARR_1_FORMAT_CONFIGURATION_TABLE_info_get(
    int unit)
{

    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "ETPPB_ENC_5_ARR_1_FORMAT_CONFIGURATION_TABLE", "DNX2");
    }
    
    return dnxc_data_mgmt_table_info_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_formats, dnx_data_dnx2_arr_formats_table_ETPPB_ENC_5_ARR_1_FORMAT_CONFIGURATION_TABLE);

}

const dnxc_data_table_info_t *
dnx_data_dnx2_arr_formats_ETPPC_ENC_1_ARR_1_FORMAT_CONFIGURATION_TABLE_info_get(
    int unit)
{

    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "ETPPC_ENC_1_ARR_1_FORMAT_CONFIGURATION_TABLE", "DNX2");
    }
    
    return dnxc_data_mgmt_table_info_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_formats, dnx_data_dnx2_arr_formats_table_ETPPC_ENC_1_ARR_1_FORMAT_CONFIGURATION_TABLE);

}

const dnxc_data_table_info_t *
dnx_data_dnx2_arr_formats_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0_info_get(
    int unit)
{

    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0", "DNX2");
    }
    
    return dnxc_data_mgmt_table_info_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_formats, dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_0);

}

const dnxc_data_table_info_t *
dnx_data_dnx2_arr_formats_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_1_info_get(
    int unit)
{

    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_1", "DNX2");
    }
    
    return dnxc_data_mgmt_table_info_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_formats, dnx_data_dnx2_arr_formats_table_ETPPC_FORWARDING_FORMAT_CONFIGURATION_TABLE_1);

}

const dnxc_data_table_info_t *
dnx_data_dnx2_arr_formats_ETPPA_PRP_EES_ARR_CONFIGURATION_info_get(
    int unit)
{

    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "ETPPA_PRP_EES_ARR_CONFIGURATION", "DNX2");
    }
    
    return dnxc_data_mgmt_table_info_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_formats, dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION);

}

const dnxc_data_table_info_t *
dnx_data_dnx2_arr_formats_ETPPA_PRP_EES_ARR_CONFIGURATION___array_info_get(
    int unit)
{

    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "ETPPA_PRP_EES_ARR_CONFIGURATION___array", "DNX2");
    }
    
    return dnxc_data_mgmt_table_info_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_formats, dnx_data_dnx2_arr_formats_table_ETPPA_PRP_EES_ARR_CONFIGURATION___array);

}

const dnxc_data_table_info_t *
dnx_data_dnx2_arr_formats_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION_info_get(
    int unit)
{

    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "ETPPC_TERM_ETPS_ARR_1_CONFIGURATION", "DNX2");
    }
    
    return dnxc_data_mgmt_table_info_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_formats, dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION);

}

const dnxc_data_table_info_t *
dnx_data_dnx2_arr_formats_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION___array_info_get(
    int unit)
{

    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "ETPPC_TERM_ETPS_ARR_1_CONFIGURATION___array", "DNX2");
    }
    
    return dnxc_data_mgmt_table_info_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_formats, dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_1_CONFIGURATION___array);

}

const dnxc_data_table_info_t *
dnx_data_dnx2_arr_formats_ETPPC_TERM_ETPS_ARR_2_CONFIGURATION_info_get(
    int unit)
{

    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "ETPPC_TERM_ETPS_ARR_2_CONFIGURATION", "DNX2");
    }
    
    return dnxc_data_mgmt_table_info_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_formats, dnx_data_dnx2_arr_formats_table_ETPPC_TERM_ETPS_ARR_2_CONFIGURATION);

}

const dnxc_data_table_info_t *
dnx_data_dnx2_arr_formats_IPPB_EXPECTED_ARR_FORMAT_CONFIG_info_get(
    int unit)
{

    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "IPPB_EXPECTED_ARR_FORMAT_CONFIG", "DNX2");
    }
    
    return dnxc_data_mgmt_table_info_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_formats, dnx_data_dnx2_arr_formats_table_IPPB_EXPECTED_ARR_FORMAT_CONFIG);

}

const dnxc_data_table_info_t *
dnx_data_dnx2_arr_formats_MACT_MRQ_ARR_CFG_info_get(
    int unit)
{

    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "MACT_MRQ_ARR_CFG", "DNX2");
    }
    
    return dnxc_data_mgmt_table_info_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_formats, dnx_data_dnx2_arr_formats_table_MACT_MRQ_ARR_CFG);

}

const dnxc_data_table_info_t *
dnx_data_dnx2_arr_formats_IPPB_ACCEPTED_ARR_FORMAT_CONFIG_info_get(
    int unit)
{

    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "IPPB_ACCEPTED_ARR_FORMAT_CONFIG", "DNX2");
    }
    
    return dnxc_data_mgmt_table_info_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_formats, dnx_data_dnx2_arr_formats_table_IPPB_ACCEPTED_ARR_FORMAT_CONFIG);

}

const dnxc_data_table_info_t *
dnx_data_dnx2_arr_formats_IPPD_FEC_FORMAT_CONFIGURATION_TABLE___array_info_get(
    int unit)
{

    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "IPPD_FEC_FORMAT_CONFIGURATION_TABLE___array", "DNX2");
    }
    
    return dnxc_data_mgmt_table_info_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_formats, dnx_data_dnx2_arr_formats_table_IPPD_FEC_FORMAT_CONFIGURATION_TABLE___array);

}

const dnxc_data_table_info_t *
dnx_data_dnx2_arr_formats_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array_info_get(
    int unit)
{

    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array", "DNX2");
    }
    
    return dnxc_data_mgmt_table_info_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_formats, dnx_data_dnx2_arr_formats_table_IPPB_FLP_FWD_FORMAT_CONFIGURATION_TABLE___array);

}

const dnxc_data_table_info_t *
dnx_data_dnx2_arr_formats_IPPB_FLP_RPF_FORMAT_CONFIGURATION_TABLE___array_info_get(
    int unit)
{

    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "IPPB_FLP_RPF_FORMAT_CONFIGURATION_TABLE___array", "DNX2");
    }
    
    return dnxc_data_mgmt_table_info_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_formats, dnx_data_dnx2_arr_formats_table_IPPB_FLP_RPF_FORMAT_CONFIGURATION_TABLE___array);

}

const dnxc_data_table_info_t *
dnx_data_dnx2_arr_formats_IPPD_SUPER_ARR_FORMAT_CONFIGURATION_TABLE___array_info_get(
    int unit)
{

    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "IPPD_SUPER_ARR_FORMAT_CONFIGURATION_TABLE___array", "DNX2");
    }
    
    return dnxc_data_mgmt_table_info_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_formats, dnx_data_dnx2_arr_formats_table_IPPD_SUPER_ARR_FORMAT_CONFIGURATION_TABLE___array);

}

const dnxc_data_table_info_t *
dnx_data_dnx2_arr_formats_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1_info_get(
    int unit)
{

    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1", "DNX2");
    }
    
    return dnxc_data_mgmt_table_info_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_formats, dnx_data_dnx2_arr_formats_table_IPPA_VSI_FORMAT_CONFIGURATION_TABLE_1);

}

const dnxc_data_table_info_t *
dnx_data_dnx2_arr_formats_IPPF_VSI_FORMAT_CONFIGURATION_TABLE_info_get(
    int unit)
{

    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "IPPF_VSI_FORMAT_CONFIGURATION_TABLE", "DNX2");
    }
    
    return dnxc_data_mgmt_table_info_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_formats, dnx_data_dnx2_arr_formats_table_IPPF_VSI_FORMAT_CONFIGURATION_TABLE);

}

const dnxc_data_table_info_t *
dnx_data_dnx2_arr_formats_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array_info_get(
    int unit)
{

    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array", "DNX2");
    }
    
    return dnxc_data_mgmt_table_info_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_formats, dnx_data_dnx2_arr_formats_table_IPPA_VTT_FORMAT_CONFIGURATION_TABLE___array);

}

const dnxc_data_table_info_t *
dnx_data_dnx2_arr_formats_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array_info_get(
    int unit)
{

    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array", "DNX2");
    }
    
    return dnxc_data_mgmt_table_info_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_formats, dnx_data_dnx2_arr_formats_table_IPPF_VTT_FORMAT_CONFIGURATION_TABLE___array);

}

const dnxc_data_table_info_t *
dnx_data_dnx2_arr_formats_IPPD_LEARN_ARR_CONFIGURATION_TABLE_info_get(
    int unit)
{

    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "IPPD_LEARN_ARR_CONFIGURATION_TABLE", "DNX2");
    }
    
    return dnxc_data_mgmt_table_info_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_formats, dnx_data_dnx2_arr_formats_table_IPPD_LEARN_ARR_CONFIGURATION_TABLE);

}

const dnxc_data_table_info_t *
dnx_data_dnx2_arr_formats_OLP_LEARN_ARR_CONFIGURATION_TABLE_info_get(
    int unit)
{

    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "OLP_LEARN_ARR_CONFIGURATION_TABLE", "DNX2");
    }
    
    return dnxc_data_mgmt_table_info_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_formats, dnx_data_dnx2_arr_formats_table_OLP_LEARN_ARR_CONFIGURATION_TABLE);

}

const dnxc_data_table_info_t *
dnx_data_dnx2_arr_formats_ERPP_EGRESS_MCDB_FORMAT_CFG_info_get(
    int unit)
{

    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "ERPP_EGRESS_MCDB_FORMAT_CFG", "DNX2");
    }
    
    return dnxc_data_mgmt_table_info_get(unit, dnx_data_module_dnx2_arr, dnx_data_dnx2_arr_submodule_formats, dnx_data_dnx2_arr_formats_table_ERPP_EGRESS_MCDB_FORMAT_CFG);

}



shr_error_e
dnx_data_dnx2_arr_init(
    int unit,
    dnxc_data_module_t *module_data)
{
    SHR_FUNC_INIT_VARS(unit);

    
    module_data->name = "dnx2_arr";
    module_data->nof_submodules = _dnx_data_dnx2_arr_submodule_nof;
    DNXC_DATA_ALLOC(module_data->submodules, dnxc_data_submodule_t, module_data->nof_submodules, "_dnxc_data dnx2_arr submodules");

    
    SHR_IF_ERR_EXIT(dnx_data_dnx2_arr_prefix_init(unit, &module_data->submodules[dnx_data_dnx2_arr_submodule_prefix]));
    SHR_IF_ERR_EXIT(dnx_data_dnx2_arr_max_nof_entries_init(unit, &module_data->submodules[dnx_data_dnx2_arr_submodule_max_nof_entries]));
    SHR_IF_ERR_EXIT(dnx_data_dnx2_arr_formats_init(unit, &module_data->submodules[dnx_data_dnx2_arr_submodule_formats]));
    

    if (dnxc_data_mgmt_is_jr2_a0(unit) && dnxc_data_mgmt_image_verify(unit, "standard_1"))
    {
        SHR_IF_ERR_EXIT(jr2_a0_standard_1_data_dnx2_arr_attach(unit));
    }
    else


    if (dnxc_data_mgmt_is_jr2_b0(unit) && dnxc_data_mgmt_image_verify(unit, "standard_1"))
    {
        SHR_IF_ERR_EXIT(jr2_a0_standard_1_data_dnx2_arr_attach(unit));
        SHR_IF_ERR_EXIT(jr2_b0_standard_1_data_dnx2_arr_attach(unit));
    }
    else


    if (dnxc_data_mgmt_is_jr2_b1(unit) && dnxc_data_mgmt_image_verify(unit, "standard_1"))
    {
        SHR_IF_ERR_EXIT(jr2_a0_standard_1_data_dnx2_arr_attach(unit));
        SHR_IF_ERR_EXIT(jr2_b0_standard_1_data_dnx2_arr_attach(unit));
    }
    else


    if (dnxc_data_mgmt_is_j2c_a0(unit) && dnxc_data_mgmt_image_verify(unit, "standard_1"))
    {
        SHR_IF_ERR_EXIT(jr2_a0_standard_1_data_dnx2_arr_attach(unit));
        SHR_IF_ERR_EXIT(j2c_a0_standard_1_data_dnx2_arr_attach(unit));
    }
    else


    if (dnxc_data_mgmt_is_j2c_a1(unit) && dnxc_data_mgmt_image_verify(unit, "standard_1"))
    {
        SHR_IF_ERR_EXIT(jr2_a0_standard_1_data_dnx2_arr_attach(unit));
        SHR_IF_ERR_EXIT(j2c_a0_standard_1_data_dnx2_arr_attach(unit));
    }
    else


    if (dnxc_data_mgmt_is_q2a_a0(unit) && dnxc_data_mgmt_image_verify(unit, "standard_1"))
    {
        SHR_IF_ERR_EXIT(jr2_a0_standard_1_data_dnx2_arr_attach(unit));
        SHR_IF_ERR_EXIT(q2a_a0_standard_1_data_dnx2_arr_attach(unit));
    }
    else


    if (dnxc_data_mgmt_is_q2a_b0(unit) && dnxc_data_mgmt_image_verify(unit, "standard_1"))
    {
        SHR_IF_ERR_EXIT(jr2_a0_standard_1_data_dnx2_arr_attach(unit));
        SHR_IF_ERR_EXIT(q2a_a0_standard_1_data_dnx2_arr_attach(unit));
        SHR_IF_ERR_EXIT(q2a_b0_standard_1_data_dnx2_arr_attach(unit));
    }
    else


    if (dnxc_data_mgmt_is_q2a_b1(unit) && dnxc_data_mgmt_image_verify(unit, "standard_1"))
    {
        SHR_IF_ERR_EXIT(jr2_a0_standard_1_data_dnx2_arr_attach(unit));
        SHR_IF_ERR_EXIT(q2a_a0_standard_1_data_dnx2_arr_attach(unit));
        SHR_IF_ERR_EXIT(q2a_b0_standard_1_data_dnx2_arr_attach(unit));
    }
    else


    if (dnxc_data_mgmt_is_j2p_a0(unit) && dnxc_data_mgmt_image_verify(unit, "standard_1"))
    {
        SHR_IF_ERR_EXIT(jr2_a0_standard_1_data_dnx2_arr_attach(unit));
        SHR_IF_ERR_EXIT(j2p_a0_standard_1_data_dnx2_arr_attach(unit));
    }
    else


    if (dnxc_data_mgmt_is_j2p_a1(unit) && dnxc_data_mgmt_image_verify(unit, "standard_1"))
    {
        SHR_IF_ERR_EXIT(jr2_a0_standard_1_data_dnx2_arr_attach(unit));
        SHR_IF_ERR_EXIT(j2p_a0_standard_1_data_dnx2_arr_attach(unit));
    }
    else


    if (dnxc_data_mgmt_is_j2p_a2(unit) && dnxc_data_mgmt_image_verify(unit, "standard_1"))
    {
        SHR_IF_ERR_EXIT(jr2_a0_standard_1_data_dnx2_arr_attach(unit));
        SHR_IF_ERR_EXIT(j2p_a0_standard_1_data_dnx2_arr_attach(unit));
    }
    else


    if (dnxc_data_mgmt_is_j2x_a0(unit) && dnxc_data_mgmt_image_verify(unit, "standard_1"))
    {
        SHR_IF_ERR_EXIT(jr2_a0_standard_1_data_dnx2_arr_attach(unit));
        SHR_IF_ERR_EXIT(j2x_a0_standard_1_data_dnx2_arr_attach(unit));
    }
    else

    {
        SHR_EXIT();
    }

exit:
    SHR_FUNC_EXIT;
}
#undef BSL_LOG_MODULE

