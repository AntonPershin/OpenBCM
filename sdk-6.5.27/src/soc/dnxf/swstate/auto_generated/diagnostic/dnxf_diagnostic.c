
/*
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2022 Broadcom Inc. All rights reserved.
 */

#ifdef BSL_LOG_MODULE
#error "BSL_LOG_MODULE redefined"
#endif
#define BSL_LOG_MODULE BSL_LS_SWSTATEDNX_GENERAL

#include <soc/dnxf/swstate/auto_generated/diagnostic/dnxf_diagnostic.h>
#include <soc/dnxf/swstate/auto_generated/layout/dnxf_layout.h>
#if defined(DNX_SW_STATE_DIAGNOSTIC)


extern dnxf_state_t * dnxf_state_data[SOC_MAX_NUM_DEVICES];



int
dnxf_state_dump(int  unit,  dnx_sw_state_dump_filters_t  filters)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;
    SHR_IF_ERR_EXIT(dnxf_state_info_dump(unit, filters));
    SHR_IF_ERR_EXIT(dnxf_state_modid_dump(unit, filters));
    SHR_IF_ERR_EXIT(dnxf_state_mc_dump(unit, filters));
    SHR_IF_ERR_EXIT(dnxf_state_lb_dump(unit, filters));
    SHR_IF_ERR_EXIT(dnxf_state_port_dump(unit, filters));
    SHR_IF_ERR_EXIT(dnxf_state_cable_swap_dump(unit, filters));
    SHR_IF_ERR_EXIT(dnxf_state_intr_dump(unit, filters));
    SHR_IF_ERR_EXIT(dnxf_state_lane_map_db_dump(unit, filters));
    SHR_IF_ERR_EXIT(dnxf_state_synce_dump(unit, filters));
    SHR_IF_ERR_EXIT(dnxf_state_system_upgrade_dump(unit, filters));
    SHR_IF_ERR_EXIT(dnxf_state_hard_reset_dump(unit, filters));
    SHR_IF_ERR_EXIT(dnxf_state_mib_dump(unit, filters));
    DNXC_SW_STATE_FUNC_RETURN;
}



int
dnxf_state_info_dump(int  unit,  dnx_sw_state_dump_filters_t  filters)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;
    SHR_IF_ERR_EXIT(dnxf_state_info_active_core_bmp_dump(unit, -1, filters));
    SHR_IF_ERR_EXIT(dnxf_state_info_valid_fsrd_bmp_dump(unit, -1, filters));
    SHR_IF_ERR_EXIT(dnxf_state_info_valid_dch_dcml_core_bmp_dump(unit, -1, filters));
    DNXC_SW_STATE_FUNC_RETURN;
}



int
dnxf_state_info_active_core_bmp_dump(int  unit,  int  active_core_bmp_idx_0,  dnx_sw_state_dump_filters_t  filters)
{
    int i0 = active_core_bmp_idx_0, I0 = active_core_bmp_idx_0 + 1;
    char *s0 = "";
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    if (dnx_sw_state_compare(filters.typefilter, "SHR_BITDCL") != TRUE)
    {
         SHR_EXIT();
    }

    if (dnx_sw_state_compare(filters.namefilter, "dnxf info active_core_bmp") != TRUE)
    {
         SHR_EXIT();
    }

    if (filters.nocontent)
    {
         DNX_SW_STATE_PRINT(unit, "swstate dnxf info active_core_bmp\n");
    }
    else
    {
        dnx_sw_state_dump_attach_file(
            unit,
            "dnxf_state/info/active_core_bmp.txt",
            "dnxf_state[%d]->","((dnxf_state_t*)sw_state_roots_array[%d][DNXF_MODULE_ID])->","info.active_core_bmp[]: ");

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID]));

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->info.active_core_bmp);

        if (i0 == -1) {
            I0 = dnx_sw_state_get_nof_elements(unit,
                DNX_SW_STATE_DNXF_STATE__INFO__ACTIVE_CORE_BMP,
                ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->info.active_core_bmp);
            i0 = dnx_sw_state_dump_check_all_the_same(unit,
                ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->info.active_core_bmp
                , sizeof(*((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->info.active_core_bmp), I0, &s0) ? I0 - 1 : 0;
        }

        if(i0 >= dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNXF_STATE__INFO__ACTIVE_CORE_BMP, ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->info.active_core_bmp))
        {
            LOG_CLI((BSL_META("dnxf_state[]->((dnxf_state_t*)sw_state_roots_array[][DNXF_MODULE_ID])->info.active_core_bmp[]: ")));
            LOG_CLI((BSL_META("Invalid index: %d \n"),i0));
            SHR_EXIT();
        }

        if(dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNXF_STATE__INFO__ACTIVE_CORE_BMP, ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->info.active_core_bmp) == 0)
        {
            SHR_EXIT();
        }

        for(; i0 < I0; i0++) {
            dnx_sw_state_dump_update_current_idx(unit, i0);
            DNX_SW_STATE_PRINT_MONITOR(
                unit,
                "dnxf_state[%d]->","((dnxf_state_t*)sw_state_roots_array[%d][DNXF_MODULE_ID])->","info.active_core_bmp[%s%d]: ", s0, i0);

            DNX_SW_STATE_PRINT_FILE(
                unit,
                "[%s%d]: ", s0, i0);

            dnx_sw_state_print_shr_bitdcl(
                unit,
                &((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->info.active_core_bmp[i0]);

        }
        dnx_sw_state_dump_end_of_stride(unit);
        dnx_sw_state_dump_detach_file(
            unit);

    }

    DNXC_SW_STATE_FUNC_RETURN;
}



int
dnxf_state_info_valid_fsrd_bmp_dump(int  unit,  int  valid_fsrd_bmp_idx_0,  dnx_sw_state_dump_filters_t  filters)
{
    int i0 = valid_fsrd_bmp_idx_0, I0 = valid_fsrd_bmp_idx_0 + 1;
    char *s0 = "";
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    if (dnx_sw_state_compare(filters.typefilter, "SHR_BITDCL") != TRUE)
    {
         SHR_EXIT();
    }

    if (dnx_sw_state_compare(filters.namefilter, "dnxf info valid_fsrd_bmp") != TRUE)
    {
         SHR_EXIT();
    }

    if (filters.nocontent)
    {
         DNX_SW_STATE_PRINT(unit, "swstate dnxf info valid_fsrd_bmp\n");
    }
    else
    {
        dnx_sw_state_dump_attach_file(
            unit,
            "dnxf_state/info/valid_fsrd_bmp.txt",
            "dnxf_state[%d]->","((dnxf_state_t*)sw_state_roots_array[%d][DNXF_MODULE_ID])->","info.valid_fsrd_bmp[]: ");

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID]));

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->info.valid_fsrd_bmp);

        if (i0 == -1) {
            I0 = dnx_sw_state_get_nof_elements(unit,
                DNX_SW_STATE_DNXF_STATE__INFO__VALID_FSRD_BMP,
                ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->info.valid_fsrd_bmp);
            i0 = dnx_sw_state_dump_check_all_the_same(unit,
                ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->info.valid_fsrd_bmp
                , sizeof(*((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->info.valid_fsrd_bmp), I0, &s0) ? I0 - 1 : 0;
        }

        if(i0 >= dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNXF_STATE__INFO__VALID_FSRD_BMP, ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->info.valid_fsrd_bmp))
        {
            LOG_CLI((BSL_META("dnxf_state[]->((dnxf_state_t*)sw_state_roots_array[][DNXF_MODULE_ID])->info.valid_fsrd_bmp[]: ")));
            LOG_CLI((BSL_META("Invalid index: %d \n"),i0));
            SHR_EXIT();
        }

        if(dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNXF_STATE__INFO__VALID_FSRD_BMP, ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->info.valid_fsrd_bmp) == 0)
        {
            SHR_EXIT();
        }

        for(; i0 < I0; i0++) {
            dnx_sw_state_dump_update_current_idx(unit, i0);
            DNX_SW_STATE_PRINT_MONITOR(
                unit,
                "dnxf_state[%d]->","((dnxf_state_t*)sw_state_roots_array[%d][DNXF_MODULE_ID])->","info.valid_fsrd_bmp[%s%d]: ", s0, i0);

            DNX_SW_STATE_PRINT_FILE(
                unit,
                "[%s%d]: ", s0, i0);

            dnx_sw_state_print_shr_bitdcl(
                unit,
                &((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->info.valid_fsrd_bmp[i0]);

        }
        dnx_sw_state_dump_end_of_stride(unit);
        dnx_sw_state_dump_detach_file(
            unit);

    }

    DNXC_SW_STATE_FUNC_RETURN;
}



int
dnxf_state_info_valid_dch_dcml_core_bmp_dump(int  unit,  int  valid_dch_dcml_core_bmp_idx_0,  dnx_sw_state_dump_filters_t  filters)
{
    int i0 = valid_dch_dcml_core_bmp_idx_0, I0 = valid_dch_dcml_core_bmp_idx_0 + 1;
    char *s0 = "";
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    if (dnx_sw_state_compare(filters.typefilter, "SHR_BITDCL") != TRUE)
    {
         SHR_EXIT();
    }

    if (dnx_sw_state_compare(filters.namefilter, "dnxf info valid_dch_dcml_core_bmp") != TRUE)
    {
         SHR_EXIT();
    }

    if (filters.nocontent)
    {
         DNX_SW_STATE_PRINT(unit, "swstate dnxf info valid_dch_dcml_core_bmp\n");
    }
    else
    {
        dnx_sw_state_dump_attach_file(
            unit,
            "dnxf_state/info/valid_dch_dcml_core_bmp.txt",
            "dnxf_state[%d]->","((dnxf_state_t*)sw_state_roots_array[%d][DNXF_MODULE_ID])->","info.valid_dch_dcml_core_bmp[]: ");

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID]));

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->info.valid_dch_dcml_core_bmp);

        if (i0 == -1) {
            I0 = dnx_sw_state_get_nof_elements(unit,
                DNX_SW_STATE_DNXF_STATE__INFO__VALID_DCH_DCML_CORE_BMP,
                ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->info.valid_dch_dcml_core_bmp);
            i0 = dnx_sw_state_dump_check_all_the_same(unit,
                ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->info.valid_dch_dcml_core_bmp
                , sizeof(*((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->info.valid_dch_dcml_core_bmp), I0, &s0) ? I0 - 1 : 0;
        }

        if(i0 >= dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNXF_STATE__INFO__VALID_DCH_DCML_CORE_BMP, ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->info.valid_dch_dcml_core_bmp))
        {
            LOG_CLI((BSL_META("dnxf_state[]->((dnxf_state_t*)sw_state_roots_array[][DNXF_MODULE_ID])->info.valid_dch_dcml_core_bmp[]: ")));
            LOG_CLI((BSL_META("Invalid index: %d \n"),i0));
            SHR_EXIT();
        }

        if(dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNXF_STATE__INFO__VALID_DCH_DCML_CORE_BMP, ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->info.valid_dch_dcml_core_bmp) == 0)
        {
            SHR_EXIT();
        }

        for(; i0 < I0; i0++) {
            dnx_sw_state_dump_update_current_idx(unit, i0);
            DNX_SW_STATE_PRINT_MONITOR(
                unit,
                "dnxf_state[%d]->","((dnxf_state_t*)sw_state_roots_array[%d][DNXF_MODULE_ID])->","info.valid_dch_dcml_core_bmp[%s%d]: ", s0, i0);

            DNX_SW_STATE_PRINT_FILE(
                unit,
                "[%s%d]: ", s0, i0);

            dnx_sw_state_print_shr_bitdcl(
                unit,
                &((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->info.valid_dch_dcml_core_bmp[i0]);

        }
        dnx_sw_state_dump_end_of_stride(unit);
        dnx_sw_state_dump_detach_file(
            unit);

    }

    DNXC_SW_STATE_FUNC_RETURN;
}



int
dnxf_state_modid_dump(int  unit,  dnx_sw_state_dump_filters_t  filters)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;
    SHR_IF_ERR_EXIT(dnxf_state_modid_local_map_dump(unit, -1, filters));
    SHR_IF_ERR_EXIT(dnxf_state_modid_group_map_dump(unit, -1, filters));
    SHR_IF_ERR_EXIT(dnxf_state_modid_modid_to_group_map_dump(unit, -1, filters));
    DNXC_SW_STATE_FUNC_RETURN;
}



int
dnxf_state_modid_local_map_dump(int  unit,  int  local_map_idx_0,  dnx_sw_state_dump_filters_t  filters)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;
    SHR_IF_ERR_EXIT(dnxf_state_modid_local_map_valid_dump(unit, local_map_idx_0, filters));
    SHR_IF_ERR_EXIT(dnxf_state_modid_local_map_module_id_dump(unit, local_map_idx_0, filters));
    DNXC_SW_STATE_FUNC_RETURN;
}



int
dnxf_state_modid_local_map_valid_dump(int  unit,  int  local_map_idx_0,  dnx_sw_state_dump_filters_t  filters)
{
    int i0 = local_map_idx_0, I0 = local_map_idx_0 + 1;
    char *s0 = "";
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    if (dnx_sw_state_compare(filters.typefilter, "uint32") != TRUE)
    {
         SHR_EXIT();
    }

    if (dnx_sw_state_compare(filters.namefilter, "dnxf modid local_map valid") != TRUE)
    {
         SHR_EXIT();
    }

    if (filters.nocontent)
    {
         DNX_SW_STATE_PRINT(unit, "swstate dnxf modid local_map valid\n");
    }
    else
    {
        dnx_sw_state_dump_attach_file(
            unit,
            "dnxf_state/modid/local_map/valid.txt",
            "dnxf_state[%d]->","((dnxf_state_t*)sw_state_roots_array[%d][DNXF_MODULE_ID])->","modid.local_map[].valid: ");

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID]));

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->modid.local_map);

        if (i0 == -1) {
            I0 = dnx_sw_state_get_nof_elements(unit,
                DNX_SW_STATE_DNXF_STATE__MODID__LOCAL_MAP__VALID,
                ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->modid.local_map);
            i0 = dnx_sw_state_dump_check_all_the_same(unit,
                ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->modid.local_map
                , sizeof(*((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->modid.local_map), I0, &s0) ? I0 - 1 : 0;
        }

        if(i0 >= dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNXF_STATE__MODID__LOCAL_MAP__VALID, ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->modid.local_map))
        {
            LOG_CLI((BSL_META("dnxf_state[]->((dnxf_state_t*)sw_state_roots_array[][DNXF_MODULE_ID])->modid.local_map[].valid: ")));
            LOG_CLI((BSL_META("Invalid index: %d \n"),i0));
            SHR_EXIT();
        }

        if(dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNXF_STATE__MODID__LOCAL_MAP__VALID, ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->modid.local_map) == 0)
        {
            SHR_EXIT();
        }

        for(; i0 < I0; i0++) {
            dnx_sw_state_dump_update_current_idx(unit, i0);
            DNX_SW_STATE_PRINT_MONITOR(
                unit,
                "dnxf_state[%d]->","((dnxf_state_t*)sw_state_roots_array[%d][DNXF_MODULE_ID])->","modid.local_map[%s%d].valid: ", s0, i0);

            DNX_SW_STATE_PRINT_FILE(
                unit,
                "[%s%d]: ", s0, i0);

            dnx_sw_state_print_uint32(
                unit,
                &((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->modid.local_map[i0].valid);

        }
        dnx_sw_state_dump_end_of_stride(unit);
        dnx_sw_state_dump_detach_file(
            unit);

    }

    DNXC_SW_STATE_FUNC_RETURN;
}



int
dnxf_state_modid_local_map_module_id_dump(int  unit,  int  local_map_idx_0,  dnx_sw_state_dump_filters_t  filters)
{
    int i0 = local_map_idx_0, I0 = local_map_idx_0 + 1;
    char *s0 = "";
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    if (dnx_sw_state_compare(filters.typefilter, "uint32") != TRUE)
    {
         SHR_EXIT();
    }

    if (dnx_sw_state_compare(filters.namefilter, "dnxf modid local_map module_id") != TRUE)
    {
         SHR_EXIT();
    }

    if (filters.nocontent)
    {
         DNX_SW_STATE_PRINT(unit, "swstate dnxf modid local_map module_id\n");
    }
    else
    {
        dnx_sw_state_dump_attach_file(
            unit,
            "dnxf_state/modid/local_map/module_id.txt",
            "dnxf_state[%d]->","((dnxf_state_t*)sw_state_roots_array[%d][DNXF_MODULE_ID])->","modid.local_map[].module_id: ");

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID]));

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->modid.local_map);

        if (i0 == -1) {
            I0 = dnx_sw_state_get_nof_elements(unit,
                DNX_SW_STATE_DNXF_STATE__MODID__LOCAL_MAP__MODULE_ID,
                ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->modid.local_map);
            i0 = dnx_sw_state_dump_check_all_the_same(unit,
                ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->modid.local_map
                , sizeof(*((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->modid.local_map), I0, &s0) ? I0 - 1 : 0;
        }

        if(i0 >= dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNXF_STATE__MODID__LOCAL_MAP__MODULE_ID, ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->modid.local_map))
        {
            LOG_CLI((BSL_META("dnxf_state[]->((dnxf_state_t*)sw_state_roots_array[][DNXF_MODULE_ID])->modid.local_map[].module_id: ")));
            LOG_CLI((BSL_META("Invalid index: %d \n"),i0));
            SHR_EXIT();
        }

        if(dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNXF_STATE__MODID__LOCAL_MAP__MODULE_ID, ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->modid.local_map) == 0)
        {
            SHR_EXIT();
        }

        for(; i0 < I0; i0++) {
            dnx_sw_state_dump_update_current_idx(unit, i0);
            DNX_SW_STATE_PRINT_MONITOR(
                unit,
                "dnxf_state[%d]->","((dnxf_state_t*)sw_state_roots_array[%d][DNXF_MODULE_ID])->","modid.local_map[%s%d].module_id: ", s0, i0);

            DNX_SW_STATE_PRINT_FILE(
                unit,
                "[%s%d]: ", s0, i0);

            dnx_sw_state_print_uint32(
                unit,
                &((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->modid.local_map[i0].module_id);

        }
        dnx_sw_state_dump_end_of_stride(unit);
        dnx_sw_state_dump_detach_file(
            unit);

    }

    DNXC_SW_STATE_FUNC_RETURN;
}



int
dnxf_state_modid_group_map_dump(int  unit,  int  group_map_idx_0,  dnx_sw_state_dump_filters_t  filters)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;
    SHR_IF_ERR_EXIT(dnxf_state_modid_group_map_raw_dump(unit, group_map_idx_0, -1, filters));
    DNXC_SW_STATE_FUNC_RETURN;
}



int
dnxf_state_modid_group_map_raw_dump(int  unit,  int  group_map_idx_0,  int  raw_idx_0,  dnx_sw_state_dump_filters_t  filters)
{
    int i0 = group_map_idx_0, I0 = group_map_idx_0 + 1;
    int i1 = raw_idx_0, I1 = raw_idx_0 + 1, org_i1 = raw_idx_0;
    char *s0 = "", *s1 = "";
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    if (dnx_sw_state_compare(filters.typefilter, "SHR_BITDCL") != TRUE)
    {
         SHR_EXIT();
    }

    if (dnx_sw_state_compare(filters.namefilter, "dnxf modid group_map raw") != TRUE)
    {
         SHR_EXIT();
    }

    if (filters.nocontent)
    {
         DNX_SW_STATE_PRINT(unit, "swstate dnxf modid group_map raw\n");
    }
    else
    {
        dnx_sw_state_dump_attach_file(
            unit,
            "dnxf_state/modid/group_map/raw.txt",
            "dnxf_state[%d]->","((dnxf_state_t*)sw_state_roots_array[%d][DNXF_MODULE_ID])->","modid.group_map[].raw[]: ");

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID]));

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->modid.group_map);

        if (i0 == -1) {
            I0 = dnx_sw_state_get_nof_elements(unit,
                DNX_SW_STATE_DNXF_STATE__MODID__GROUP_MAP__RAW,
                ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->modid.group_map);
            i0 = dnx_sw_state_dump_check_all_the_same(unit,
                ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->modid.group_map
                , sizeof(*((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->modid.group_map), I0, &s0) ? I0 - 1 : 0;
        }

        if(i0 >= dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNXF_STATE__MODID__GROUP_MAP__RAW, ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->modid.group_map))
        {
            LOG_CLI((BSL_META("dnxf_state[]->((dnxf_state_t*)sw_state_roots_array[][DNXF_MODULE_ID])->modid.group_map[].raw[]: ")));
            LOG_CLI((BSL_META("Invalid index: %d \n"),i0));
            SHR_EXIT();
        }

        if(dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNXF_STATE__MODID__GROUP_MAP__RAW, ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->modid.group_map) == 0)
        {
            SHR_EXIT();
        }

        for(; i0 < I0; i0++) {
            
            
                DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
                    unit,
                    ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->modid.group_map[i0].raw);

            if (i1 == -1) {
                I1 = dnx_sw_state_get_nof_elements(unit,
                    DNX_SW_STATE_DNXF_STATE__MODID__GROUP_MAP__RAW,
                    ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->modid.group_map[i0].raw);
                i1 = dnx_sw_state_dump_check_all_the_same(unit,
                    ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->modid.group_map[i0].raw
                    , sizeof(*((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->modid.group_map[i0].raw), I1, &s1) ? I1 - 1 : 0;
            }

            if(i1 >= dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNXF_STATE__MODID__GROUP_MAP__RAW, ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->modid.group_map[i0].raw))
            {
                LOG_CLI((BSL_META("dnxf_state[]->((dnxf_state_t*)sw_state_roots_array[][DNXF_MODULE_ID])->modid.group_map[].raw[]: ")));
                LOG_CLI((BSL_META("Invalid index: %d \n"),i1));
                SHR_EXIT();
            }

            if(dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNXF_STATE__MODID__GROUP_MAP__RAW, ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->modid.group_map[i0].raw) == 0)
            {
                SHR_EXIT();
            }

            for(; i1 < I1; i1++) {
                dnx_sw_state_dump_update_current_idx(unit, i1);
                DNX_SW_STATE_PRINT_MONITOR(
                    unit,
                    "dnxf_state[%d]->","((dnxf_state_t*)sw_state_roots_array[%d][DNXF_MODULE_ID])->","modid.group_map[%s%d].raw[%s%d]: ", s0, i0, s1, i1);

                DNX_SW_STATE_PRINT_FILE(
                    unit,
                    "[%s%d][%s%d]: ", s0, i0, s1, i1);

                dnx_sw_state_print_shr_bitdcl(
                    unit,
                    &((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->modid.group_map[i0].raw[i1]);

            }
            i1 = org_i1;
            dnx_sw_state_dump_end_of_stride(unit);
        }
        dnx_sw_state_dump_detach_file(
            unit);

    }

    DNXC_SW_STATE_FUNC_RETURN;
}



int
dnxf_state_modid_modid_to_group_map_dump(int  unit,  int  modid_to_group_map_idx_0,  dnx_sw_state_dump_filters_t  filters)
{
    int i0 = modid_to_group_map_idx_0, I0 = modid_to_group_map_idx_0 + 1;
    char *s0 = "";
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    if (dnx_sw_state_compare(filters.typefilter, "soc_module_t") != TRUE)
    {
         SHR_EXIT();
    }

    if (dnx_sw_state_compare(filters.namefilter, "dnxf modid modid_to_group_map") != TRUE)
    {
         SHR_EXIT();
    }

    if (filters.nocontent)
    {
         DNX_SW_STATE_PRINT(unit, "swstate dnxf modid modid_to_group_map\n");
    }
    else
    {
        dnx_sw_state_dump_attach_file(
            unit,
            "dnxf_state/modid/modid_to_group_map.txt",
            "dnxf_state[%d]->","((dnxf_state_t*)sw_state_roots_array[%d][DNXF_MODULE_ID])->","modid.modid_to_group_map[]: ");

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID]));

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->modid.modid_to_group_map);

        if (i0 == -1) {
            I0 = dnx_sw_state_get_nof_elements(unit,
                DNX_SW_STATE_DNXF_STATE__MODID__MODID_TO_GROUP_MAP,
                ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->modid.modid_to_group_map);
            i0 = dnx_sw_state_dump_check_all_the_same(unit,
                ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->modid.modid_to_group_map
                , sizeof(*((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->modid.modid_to_group_map), I0, &s0) ? I0 - 1 : 0;
        }

        if(i0 >= dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNXF_STATE__MODID__MODID_TO_GROUP_MAP, ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->modid.modid_to_group_map))
        {
            LOG_CLI((BSL_META("dnxf_state[]->((dnxf_state_t*)sw_state_roots_array[][DNXF_MODULE_ID])->modid.modid_to_group_map[]: ")));
            LOG_CLI((BSL_META("Invalid index: %d \n"),i0));
            SHR_EXIT();
        }

        if(dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNXF_STATE__MODID__MODID_TO_GROUP_MAP, ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->modid.modid_to_group_map) == 0)
        {
            SHR_EXIT();
        }

        for(; i0 < I0; i0++) {
            dnx_sw_state_dump_update_current_idx(unit, i0);
            DNX_SW_STATE_PRINT_MONITOR(
                unit,
                "dnxf_state[%d]->","((dnxf_state_t*)sw_state_roots_array[%d][DNXF_MODULE_ID])->","modid.modid_to_group_map[%s%d]: ", s0, i0);

            DNX_SW_STATE_PRINT_FILE(
                unit,
                "[%s%d]: ", s0, i0);

            dnx_sw_state_print_int(
                unit,
                &((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->modid.modid_to_group_map[i0]);

        }
        dnx_sw_state_dump_end_of_stride(unit);
        dnx_sw_state_dump_detach_file(
            unit);

    }

    DNXC_SW_STATE_FUNC_RETURN;
}



int
dnxf_state_mc_dump(int  unit,  dnx_sw_state_dump_filters_t  filters)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;
    SHR_IF_ERR_EXIT(dnxf_state_mc_mode_dump(unit, filters));
    SHR_IF_ERR_EXIT(dnxf_state_mc_id_map_dump(unit, -1, filters));
    SHR_IF_ERR_EXIT(dnxf_state_mc_nof_mc_groups_created_dump(unit, filters));
    DNXC_SW_STATE_FUNC_RETURN;
}



int
dnxf_state_mc_mode_dump(int  unit,  dnx_sw_state_dump_filters_t  filters)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    if (dnx_sw_state_compare(filters.typefilter, "uint32") != TRUE)
    {
         SHR_EXIT();
    }

    if (dnx_sw_state_compare(filters.namefilter, "dnxf mc mode") != TRUE)
    {
         SHR_EXIT();
    }

    if (filters.nocontent)
    {
         DNX_SW_STATE_PRINT(unit, "swstate dnxf mc mode\n");
    }
    else
    {
        dnx_sw_state_dump_attach_file(
            unit,
            "dnxf_state/mc/mode.txt",
            "dnxf_state[%d]->","((dnxf_state_t*)sw_state_roots_array[%d][DNXF_MODULE_ID])->","mc.mode: ");

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID]));

        DNX_SW_STATE_PRINT_MONITOR(
            unit,
            "dnxf_state[%d]->","((dnxf_state_t*)sw_state_roots_array[%d][DNXF_MODULE_ID])->","mc.mode: ");

        DNX_SW_STATE_PRINT_FILE(
            unit,
            " ");

        dnx_sw_state_print_uint32(
            unit,
            &((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->mc.mode);

        dnx_sw_state_dump_detach_file(
            unit);

    }

    DNXC_SW_STATE_FUNC_RETURN;
}



int
dnxf_state_mc_id_map_dump(int  unit,  int  id_map_idx_0,  dnx_sw_state_dump_filters_t  filters)
{
    int i0 = id_map_idx_0, I0 = id_map_idx_0 + 1;
    char *s0 = "";
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    if (dnx_sw_state_compare(filters.typefilter, "uint32") != TRUE)
    {
         SHR_EXIT();
    }

    if (dnx_sw_state_compare(filters.namefilter, "dnxf mc id_map") != TRUE)
    {
         SHR_EXIT();
    }

    if (filters.nocontent)
    {
         DNX_SW_STATE_PRINT(unit, "swstate dnxf mc id_map\n");
    }
    else
    {
        dnx_sw_state_dump_attach_file(
            unit,
            "dnxf_state/mc/id_map.txt",
            "dnxf_state[%d]->","((dnxf_state_t*)sw_state_roots_array[%d][DNXF_MODULE_ID])->","mc.id_map[]: ");

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID]));

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->mc.id_map);

        if (i0 == -1) {
            I0 = dnx_sw_state_get_nof_elements(unit,
                DNX_SW_STATE_DNXF_STATE__MC__ID_MAP,
                ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->mc.id_map);
            i0 = dnx_sw_state_dump_check_all_the_same(unit,
                ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->mc.id_map
                , sizeof(*((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->mc.id_map), I0, &s0) ? I0 - 1 : 0;
        }

        if(i0 >= dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNXF_STATE__MC__ID_MAP, ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->mc.id_map))
        {
            LOG_CLI((BSL_META("dnxf_state[]->((dnxf_state_t*)sw_state_roots_array[][DNXF_MODULE_ID])->mc.id_map[]: ")));
            LOG_CLI((BSL_META("Invalid index: %d \n"),i0));
            SHR_EXIT();
        }

        if(dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNXF_STATE__MC__ID_MAP, ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->mc.id_map) == 0)
        {
            SHR_EXIT();
        }

        for(; i0 < I0; i0++) {
            dnx_sw_state_dump_update_current_idx(unit, i0);
            DNX_SW_STATE_PRINT_MONITOR(
                unit,
                "dnxf_state[%d]->","((dnxf_state_t*)sw_state_roots_array[%d][DNXF_MODULE_ID])->","mc.id_map[%s%d]: ", s0, i0);

            DNX_SW_STATE_PRINT_FILE(
                unit,
                "[%s%d]: ", s0, i0);

            dnx_sw_state_print_uint32(
                unit,
                &((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->mc.id_map[i0]);

        }
        dnx_sw_state_dump_end_of_stride(unit);
        dnx_sw_state_dump_detach_file(
            unit);

    }

    DNXC_SW_STATE_FUNC_RETURN;
}



int
dnxf_state_mc_nof_mc_groups_created_dump(int  unit,  dnx_sw_state_dump_filters_t  filters)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    if (dnx_sw_state_compare(filters.typefilter, "uint32") != TRUE)
    {
         SHR_EXIT();
    }

    if (dnx_sw_state_compare(filters.namefilter, "dnxf mc nof_mc_groups_created") != TRUE)
    {
         SHR_EXIT();
    }

    if (filters.nocontent)
    {
         DNX_SW_STATE_PRINT(unit, "swstate dnxf mc nof_mc_groups_created\n");
    }
    else
    {
        dnx_sw_state_dump_attach_file(
            unit,
            "dnxf_state/mc/nof_mc_groups_created.txt",
            "dnxf_state[%d]->","((dnxf_state_t*)sw_state_roots_array[%d][DNXF_MODULE_ID])->","mc.nof_mc_groups_created: ");

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID]));

        DNX_SW_STATE_PRINT_MONITOR(
            unit,
            "dnxf_state[%d]->","((dnxf_state_t*)sw_state_roots_array[%d][DNXF_MODULE_ID])->","mc.nof_mc_groups_created: ");

        DNX_SW_STATE_PRINT_FILE(
            unit,
            " ");

        dnx_sw_state_print_uint32(
            unit,
            &((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->mc.nof_mc_groups_created);

        dnx_sw_state_dump_detach_file(
            unit);

    }

    DNXC_SW_STATE_FUNC_RETURN;
}



int
dnxf_state_lb_dump(int  unit,  dnx_sw_state_dump_filters_t  filters)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;
    SHR_IF_ERR_EXIT(dnxf_state_lb_group_to_first_link_dump(unit, -1, -1, filters));
    DNXC_SW_STATE_FUNC_RETURN;
}



int
dnxf_state_lb_group_to_first_link_dump(int  unit,  int  group_to_first_link_idx_0,  int  group_to_first_link_idx_1,  dnx_sw_state_dump_filters_t  filters)
{
    int i0 = group_to_first_link_idx_0, I0 = group_to_first_link_idx_0 + 1;
    int i1 = group_to_first_link_idx_1, I1 = group_to_first_link_idx_1 + 1, org_i1 = group_to_first_link_idx_1;
    char *s0 = "", *s1 = "";
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    if (dnx_sw_state_compare(filters.typefilter, "soc_port_t") != TRUE)
    {
         SHR_EXIT();
    }

    if (dnx_sw_state_compare(filters.namefilter, "dnxf lb group_to_first_link") != TRUE)
    {
         SHR_EXIT();
    }

    if (filters.nocontent)
    {
         DNX_SW_STATE_PRINT(unit, "swstate dnxf lb group_to_first_link\n");
    }
    else
    {
        dnx_sw_state_dump_attach_file(
            unit,
            "dnxf_state/lb/group_to_first_link.txt",
            "dnxf_state[%d]->","((dnxf_state_t*)sw_state_roots_array[%d][DNXF_MODULE_ID])->","lb.group_to_first_link[][]: ");

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID]));

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->lb.group_to_first_link);

        if (i0 == -1) {
            I0 = dnx_sw_state_get_nof_elements(unit,
                DNX_SW_STATE_DNXF_STATE__LB__GROUP_TO_FIRST_LINK,
                ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->lb.group_to_first_link);
            i0 = dnx_sw_state_dump_check_all_the_same(unit,
                ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->lb.group_to_first_link
                , sizeof(*((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->lb.group_to_first_link), I0, &s0) ? I0 - 1 : 0;
        }

        if(i0 >= dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNXF_STATE__LB__GROUP_TO_FIRST_LINK, ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->lb.group_to_first_link))
        {
            LOG_CLI((BSL_META("dnxf_state[]->((dnxf_state_t*)sw_state_roots_array[][DNXF_MODULE_ID])->lb.group_to_first_link[][]: ")));
            LOG_CLI((BSL_META("Invalid index: %d \n"),i0));
            SHR_EXIT();
        }

        if(dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNXF_STATE__LB__GROUP_TO_FIRST_LINK, ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->lb.group_to_first_link) == 0)
        {
            SHR_EXIT();
        }

        for(; i0 < I0; i0++) {
            
            
                DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
                    unit,
                    ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->lb.group_to_first_link[i0]);

            if (i1 == -1) {
                I1 = dnx_sw_state_get_nof_elements(unit,
                    DNX_SW_STATE_DNXF_STATE__LB__GROUP_TO_FIRST_LINK,
                    ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->lb.group_to_first_link[i0]);
                i1 = dnx_sw_state_dump_check_all_the_same(unit,
                    ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->lb.group_to_first_link[i0]
                    , sizeof(*((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->lb.group_to_first_link[i0]), I1, &s1) ? I1 - 1 : 0;
            }

            if(i1 >= dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNXF_STATE__LB__GROUP_TO_FIRST_LINK, ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->lb.group_to_first_link[i0]))
            {
                LOG_CLI((BSL_META("dnxf_state[]->((dnxf_state_t*)sw_state_roots_array[][DNXF_MODULE_ID])->lb.group_to_first_link[][]: ")));
                LOG_CLI((BSL_META("Invalid index: %d \n"),i1));
                SHR_EXIT();
            }

            if(dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNXF_STATE__LB__GROUP_TO_FIRST_LINK, ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->lb.group_to_first_link[i0]) == 0)
            {
                SHR_EXIT();
            }

            for(; i1 < I1; i1++) {
                dnx_sw_state_dump_update_current_idx(unit, i1);
                DNX_SW_STATE_PRINT_MONITOR(
                    unit,
                    "dnxf_state[%d]->","((dnxf_state_t*)sw_state_roots_array[%d][DNXF_MODULE_ID])->","lb.group_to_first_link[%s%d][%s%d]: ", s0, i0, s1, i1);

                DNX_SW_STATE_PRINT_FILE(
                    unit,
                    "[%s%d][%s%d]: ", s0, i0, s1, i1);

                dnx_sw_state_print_int(
                    unit,
                    &((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->lb.group_to_first_link[i0][i1]);

            }
            i1 = org_i1;
            dnx_sw_state_dump_end_of_stride(unit);
        }
        dnx_sw_state_dump_detach_file(
            unit);

    }

    DNXC_SW_STATE_FUNC_RETURN;
}



int
dnxf_state_port_dump(int  unit,  dnx_sw_state_dump_filters_t  filters)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;
    SHR_IF_ERR_EXIT(dnxf_state_port_cl72_conf_dump(unit, -1, filters));
    SHR_IF_ERR_EXIT(dnxf_state_port_phy_lane_config_dump(unit, -1, filters));
    SHR_IF_ERR_EXIT(dnxf_state_port_speed_dump(unit, -1, filters));
    SHR_IF_ERR_EXIT(dnxf_state_port_fec_type_dump(unit, -1, filters));
    SHR_IF_ERR_EXIT(dnxf_state_port_is_connected_to_repeater_dump(unit, -1, filters));
    SHR_IF_ERR_EXIT(dnxf_state_port_isolation_status_stored_dump(unit, -1, filters));
    SHR_IF_ERR_EXIT(dnxf_state_port_orig_isolated_status_dump(unit, -1, filters));
    DNXC_SW_STATE_FUNC_RETURN;
}



int
dnxf_state_port_cl72_conf_dump(int  unit,  int  cl72_conf_idx_0,  dnx_sw_state_dump_filters_t  filters)
{
    int i0 = cl72_conf_idx_0, I0 = cl72_conf_idx_0 + 1;
    char *s0 = "";
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    if (dnx_sw_state_compare(filters.typefilter, "uint32") != TRUE)
    {
         SHR_EXIT();
    }

    if (dnx_sw_state_compare(filters.namefilter, "dnxf port cl72_conf") != TRUE)
    {
         SHR_EXIT();
    }

    if (filters.nocontent)
    {
         DNX_SW_STATE_PRINT(unit, "swstate dnxf port cl72_conf\n");
    }
    else
    {
        dnx_sw_state_dump_attach_file(
            unit,
            "dnxf_state/port/cl72_conf.txt",
            "dnxf_state[%d]->","((dnxf_state_t*)sw_state_roots_array[%d][DNXF_MODULE_ID])->","port.cl72_conf[]: ");

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID]));

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->port.cl72_conf);

        if (i0 == -1) {
            I0 = dnx_sw_state_get_nof_elements(unit,
                DNX_SW_STATE_DNXF_STATE__PORT__CL72_CONF,
                ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->port.cl72_conf);
            i0 = dnx_sw_state_dump_check_all_the_same(unit,
                ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->port.cl72_conf
                , sizeof(*((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->port.cl72_conf), I0, &s0) ? I0 - 1 : 0;
        }

        if(i0 >= dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNXF_STATE__PORT__CL72_CONF, ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->port.cl72_conf))
        {
            LOG_CLI((BSL_META("dnxf_state[]->((dnxf_state_t*)sw_state_roots_array[][DNXF_MODULE_ID])->port.cl72_conf[]: ")));
            LOG_CLI((BSL_META("Invalid index: %d \n"),i0));
            SHR_EXIT();
        }

        if(dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNXF_STATE__PORT__CL72_CONF, ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->port.cl72_conf) == 0)
        {
            SHR_EXIT();
        }

        for(; i0 < I0; i0++) {
            dnx_sw_state_dump_update_current_idx(unit, i0);
            DNX_SW_STATE_PRINT_MONITOR(
                unit,
                "dnxf_state[%d]->","((dnxf_state_t*)sw_state_roots_array[%d][DNXF_MODULE_ID])->","port.cl72_conf[%s%d]: ", s0, i0);

            DNX_SW_STATE_PRINT_FILE(
                unit,
                "[%s%d]: ", s0, i0);

            dnx_sw_state_print_uint32(
                unit,
                &((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->port.cl72_conf[i0]);

        }
        dnx_sw_state_dump_end_of_stride(unit);
        dnx_sw_state_dump_detach_file(
            unit);

    }

    DNXC_SW_STATE_FUNC_RETURN;
}



int
dnxf_state_port_phy_lane_config_dump(int  unit,  int  phy_lane_config_idx_0,  dnx_sw_state_dump_filters_t  filters)
{
    int i0 = phy_lane_config_idx_0, I0 = phy_lane_config_idx_0 + 1;
    char *s0 = "";
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    if (dnx_sw_state_compare(filters.typefilter, "int") != TRUE)
    {
         SHR_EXIT();
    }

    if (dnx_sw_state_compare(filters.namefilter, "dnxf port phy_lane_config") != TRUE)
    {
         SHR_EXIT();
    }

    if (filters.nocontent)
    {
         DNX_SW_STATE_PRINT(unit, "swstate dnxf port phy_lane_config\n");
    }
    else
    {
        dnx_sw_state_dump_attach_file(
            unit,
            "dnxf_state/port/phy_lane_config.txt",
            "dnxf_state[%d]->","((dnxf_state_t*)sw_state_roots_array[%d][DNXF_MODULE_ID])->","port.phy_lane_config[]: ");

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID]));

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->port.phy_lane_config);

        if (i0 == -1) {
            I0 = dnx_sw_state_get_nof_elements(unit,
                DNX_SW_STATE_DNXF_STATE__PORT__PHY_LANE_CONFIG,
                ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->port.phy_lane_config);
            i0 = dnx_sw_state_dump_check_all_the_same(unit,
                ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->port.phy_lane_config
                , sizeof(*((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->port.phy_lane_config), I0, &s0) ? I0 - 1 : 0;
        }

        if(i0 >= dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNXF_STATE__PORT__PHY_LANE_CONFIG, ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->port.phy_lane_config))
        {
            LOG_CLI((BSL_META("dnxf_state[]->((dnxf_state_t*)sw_state_roots_array[][DNXF_MODULE_ID])->port.phy_lane_config[]: ")));
            LOG_CLI((BSL_META("Invalid index: %d \n"),i0));
            SHR_EXIT();
        }

        if(dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNXF_STATE__PORT__PHY_LANE_CONFIG, ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->port.phy_lane_config) == 0)
        {
            SHR_EXIT();
        }

        for(; i0 < I0; i0++) {
            dnx_sw_state_dump_update_current_idx(unit, i0);
            DNX_SW_STATE_PRINT_MONITOR(
                unit,
                "dnxf_state[%d]->","((dnxf_state_t*)sw_state_roots_array[%d][DNXF_MODULE_ID])->","port.phy_lane_config[%s%d]: ", s0, i0);

            DNX_SW_STATE_PRINT_FILE(
                unit,
                "[%s%d]: ", s0, i0);

            dnx_sw_state_print_int(
                unit,
                &((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->port.phy_lane_config[i0]);

        }
        dnx_sw_state_dump_end_of_stride(unit);
        dnx_sw_state_dump_detach_file(
            unit);

    }

    DNXC_SW_STATE_FUNC_RETURN;
}



int
dnxf_state_port_speed_dump(int  unit,  int  speed_idx_0,  dnx_sw_state_dump_filters_t  filters)
{
    int i0 = speed_idx_0, I0 = speed_idx_0 + 1;
    char *s0 = "";
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    if (dnx_sw_state_compare(filters.typefilter, "int") != TRUE)
    {
         SHR_EXIT();
    }

    if (dnx_sw_state_compare(filters.namefilter, "dnxf port speed") != TRUE)
    {
         SHR_EXIT();
    }

    if (filters.nocontent)
    {
         DNX_SW_STATE_PRINT(unit, "swstate dnxf port speed\n");
    }
    else
    {
        dnx_sw_state_dump_attach_file(
            unit,
            "dnxf_state/port/speed.txt",
            "dnxf_state[%d]->","((dnxf_state_t*)sw_state_roots_array[%d][DNXF_MODULE_ID])->","port.speed[]: ");

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID]));

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->port.speed);

        if (i0 == -1) {
            I0 = dnx_sw_state_get_nof_elements(unit,
                DNX_SW_STATE_DNXF_STATE__PORT__SPEED,
                ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->port.speed);
            i0 = dnx_sw_state_dump_check_all_the_same(unit,
                ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->port.speed
                , sizeof(*((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->port.speed), I0, &s0) ? I0 - 1 : 0;
        }

        if(i0 >= dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNXF_STATE__PORT__SPEED, ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->port.speed))
        {
            LOG_CLI((BSL_META("dnxf_state[]->((dnxf_state_t*)sw_state_roots_array[][DNXF_MODULE_ID])->port.speed[]: ")));
            LOG_CLI((BSL_META("Invalid index: %d \n"),i0));
            SHR_EXIT();
        }

        if(dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNXF_STATE__PORT__SPEED, ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->port.speed) == 0)
        {
            SHR_EXIT();
        }

        for(; i0 < I0; i0++) {
            dnx_sw_state_dump_update_current_idx(unit, i0);
            DNX_SW_STATE_PRINT_MONITOR(
                unit,
                "dnxf_state[%d]->","((dnxf_state_t*)sw_state_roots_array[%d][DNXF_MODULE_ID])->","port.speed[%s%d]: ", s0, i0);

            DNX_SW_STATE_PRINT_FILE(
                unit,
                "[%s%d]: ", s0, i0);

            dnx_sw_state_print_int(
                unit,
                &((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->port.speed[i0]);

        }
        dnx_sw_state_dump_end_of_stride(unit);
        dnx_sw_state_dump_detach_file(
            unit);

    }

    DNXC_SW_STATE_FUNC_RETURN;
}



int
dnxf_state_port_fec_type_dump(int  unit,  int  fec_type_idx_0,  dnx_sw_state_dump_filters_t  filters)
{
    int i0 = fec_type_idx_0, I0 = fec_type_idx_0 + 1;
    char *s0 = "";
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    if (dnx_sw_state_compare(filters.typefilter, "int") != TRUE)
    {
         SHR_EXIT();
    }

    if (dnx_sw_state_compare(filters.namefilter, "dnxf port fec_type") != TRUE)
    {
         SHR_EXIT();
    }

    if (filters.nocontent)
    {
         DNX_SW_STATE_PRINT(unit, "swstate dnxf port fec_type\n");
    }
    else
    {
        dnx_sw_state_dump_attach_file(
            unit,
            "dnxf_state/port/fec_type.txt",
            "dnxf_state[%d]->","((dnxf_state_t*)sw_state_roots_array[%d][DNXF_MODULE_ID])->","port.fec_type[]: ");

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID]));

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->port.fec_type);

        if (i0 == -1) {
            I0 = dnx_sw_state_get_nof_elements(unit,
                DNX_SW_STATE_DNXF_STATE__PORT__FEC_TYPE,
                ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->port.fec_type);
            i0 = dnx_sw_state_dump_check_all_the_same(unit,
                ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->port.fec_type
                , sizeof(*((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->port.fec_type), I0, &s0) ? I0 - 1 : 0;
        }

        if(i0 >= dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNXF_STATE__PORT__FEC_TYPE, ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->port.fec_type))
        {
            LOG_CLI((BSL_META("dnxf_state[]->((dnxf_state_t*)sw_state_roots_array[][DNXF_MODULE_ID])->port.fec_type[]: ")));
            LOG_CLI((BSL_META("Invalid index: %d \n"),i0));
            SHR_EXIT();
        }

        if(dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNXF_STATE__PORT__FEC_TYPE, ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->port.fec_type) == 0)
        {
            SHR_EXIT();
        }

        for(; i0 < I0; i0++) {
            dnx_sw_state_dump_update_current_idx(unit, i0);
            DNX_SW_STATE_PRINT_MONITOR(
                unit,
                "dnxf_state[%d]->","((dnxf_state_t*)sw_state_roots_array[%d][DNXF_MODULE_ID])->","port.fec_type[%s%d]: ", s0, i0);

            DNX_SW_STATE_PRINT_FILE(
                unit,
                "[%s%d]: ", s0, i0);

            dnx_sw_state_print_int(
                unit,
                &((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->port.fec_type[i0]);

        }
        dnx_sw_state_dump_end_of_stride(unit);
        dnx_sw_state_dump_detach_file(
            unit);

    }

    DNXC_SW_STATE_FUNC_RETURN;
}



int
dnxf_state_port_is_connected_to_repeater_dump(int  unit,  int  is_connected_to_repeater_idx_0,  dnx_sw_state_dump_filters_t  filters)
{
    int i0 = is_connected_to_repeater_idx_0, I0 = is_connected_to_repeater_idx_0 + 1;
    char *s0 = "";
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    if (dnx_sw_state_compare(filters.typefilter, "SHR_BITDCL") != TRUE)
    {
         SHR_EXIT();
    }

    if (dnx_sw_state_compare(filters.namefilter, "dnxf port is_connected_to_repeater") != TRUE)
    {
         SHR_EXIT();
    }

    if (filters.nocontent)
    {
         DNX_SW_STATE_PRINT(unit, "swstate dnxf port is_connected_to_repeater\n");
    }
    else
    {
        dnx_sw_state_dump_attach_file(
            unit,
            "dnxf_state/port/is_connected_to_repeater.txt",
            "dnxf_state[%d]->","((dnxf_state_t*)sw_state_roots_array[%d][DNXF_MODULE_ID])->","port.is_connected_to_repeater[]: ");

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID]));

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->port.is_connected_to_repeater);

        if (i0 == -1) {
            I0 = dnx_sw_state_get_nof_elements(unit,
                DNX_SW_STATE_DNXF_STATE__PORT__IS_CONNECTED_TO_REPEATER,
                ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->port.is_connected_to_repeater);
            i0 = dnx_sw_state_dump_check_all_the_same(unit,
                ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->port.is_connected_to_repeater
                , sizeof(*((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->port.is_connected_to_repeater), I0, &s0) ? I0 - 1 : 0;
        }

        if(i0 >= dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNXF_STATE__PORT__IS_CONNECTED_TO_REPEATER, ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->port.is_connected_to_repeater))
        {
            LOG_CLI((BSL_META("dnxf_state[]->((dnxf_state_t*)sw_state_roots_array[][DNXF_MODULE_ID])->port.is_connected_to_repeater[]: ")));
            LOG_CLI((BSL_META("Invalid index: %d \n"),i0));
            SHR_EXIT();
        }

        if(dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNXF_STATE__PORT__IS_CONNECTED_TO_REPEATER, ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->port.is_connected_to_repeater) == 0)
        {
            SHR_EXIT();
        }

        for(; i0 < I0; i0++) {
            dnx_sw_state_dump_update_current_idx(unit, i0);
            DNX_SW_STATE_PRINT_MONITOR(
                unit,
                "dnxf_state[%d]->","((dnxf_state_t*)sw_state_roots_array[%d][DNXF_MODULE_ID])->","port.is_connected_to_repeater[%s%d]: ", s0, i0);

            DNX_SW_STATE_PRINT_FILE(
                unit,
                "[%s%d]: ", s0, i0);

            dnx_sw_state_print_shr_bitdcl(
                unit,
                &((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->port.is_connected_to_repeater[i0]);

        }
        dnx_sw_state_dump_end_of_stride(unit);
        dnx_sw_state_dump_detach_file(
            unit);

    }

    DNXC_SW_STATE_FUNC_RETURN;
}



int
dnxf_state_port_isolation_status_stored_dump(int  unit,  int  isolation_status_stored_idx_0,  dnx_sw_state_dump_filters_t  filters)
{
    int i0 = isolation_status_stored_idx_0, I0 = isolation_status_stored_idx_0 + 1;
    char *s0 = "";
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    if (dnx_sw_state_compare(filters.typefilter, "int") != TRUE)
    {
         SHR_EXIT();
    }

    if (dnx_sw_state_compare(filters.namefilter, "dnxf port isolation_status_stored") != TRUE)
    {
         SHR_EXIT();
    }

    if (filters.nocontent)
    {
         DNX_SW_STATE_PRINT(unit, "swstate dnxf port isolation_status_stored\n");
    }
    else
    {
        dnx_sw_state_dump_attach_file(
            unit,
            "dnxf_state/port/isolation_status_stored.txt",
            "dnxf_state[%d]->","((dnxf_state_t*)sw_state_roots_array[%d][DNXF_MODULE_ID])->","port.isolation_status_stored[]: ");

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID]));

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->port.isolation_status_stored);

        if (i0 == -1) {
            I0 = dnx_sw_state_get_nof_elements(unit,
                DNX_SW_STATE_DNXF_STATE__PORT__ISOLATION_STATUS_STORED,
                ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->port.isolation_status_stored);
            i0 = dnx_sw_state_dump_check_all_the_same(unit,
                ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->port.isolation_status_stored
                , sizeof(*((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->port.isolation_status_stored), I0, &s0) ? I0 - 1 : 0;
        }

        if(i0 >= dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNXF_STATE__PORT__ISOLATION_STATUS_STORED, ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->port.isolation_status_stored))
        {
            LOG_CLI((BSL_META("dnxf_state[]->((dnxf_state_t*)sw_state_roots_array[][DNXF_MODULE_ID])->port.isolation_status_stored[]: ")));
            LOG_CLI((BSL_META("Invalid index: %d \n"),i0));
            SHR_EXIT();
        }

        if(dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNXF_STATE__PORT__ISOLATION_STATUS_STORED, ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->port.isolation_status_stored) == 0)
        {
            SHR_EXIT();
        }

        for(; i0 < I0; i0++) {
            dnx_sw_state_dump_update_current_idx(unit, i0);
            DNX_SW_STATE_PRINT_MONITOR(
                unit,
                "dnxf_state[%d]->","((dnxf_state_t*)sw_state_roots_array[%d][DNXF_MODULE_ID])->","port.isolation_status_stored[%s%d]: ", s0, i0);

            DNX_SW_STATE_PRINT_FILE(
                unit,
                "[%s%d]: ", s0, i0);

            dnx_sw_state_print_int(
                unit,
                &((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->port.isolation_status_stored[i0]);

        }
        dnx_sw_state_dump_end_of_stride(unit);
        dnx_sw_state_dump_detach_file(
            unit);

    }

    DNXC_SW_STATE_FUNC_RETURN;
}



int
dnxf_state_port_orig_isolated_status_dump(int  unit,  int  orig_isolated_status_idx_0,  dnx_sw_state_dump_filters_t  filters)
{
    int i0 = orig_isolated_status_idx_0, I0 = orig_isolated_status_idx_0 + 1;
    char *s0 = "";
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    if (dnx_sw_state_compare(filters.typefilter, "int") != TRUE)
    {
         SHR_EXIT();
    }

    if (dnx_sw_state_compare(filters.namefilter, "dnxf port orig_isolated_status") != TRUE)
    {
         SHR_EXIT();
    }

    if (filters.nocontent)
    {
         DNX_SW_STATE_PRINT(unit, "swstate dnxf port orig_isolated_status\n");
    }
    else
    {
        dnx_sw_state_dump_attach_file(
            unit,
            "dnxf_state/port/orig_isolated_status.txt",
            "dnxf_state[%d]->","((dnxf_state_t*)sw_state_roots_array[%d][DNXF_MODULE_ID])->","port.orig_isolated_status[]: ");

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID]));

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->port.orig_isolated_status);

        if (i0 == -1) {
            I0 = dnx_sw_state_get_nof_elements(unit,
                DNX_SW_STATE_DNXF_STATE__PORT__ORIG_ISOLATED_STATUS,
                ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->port.orig_isolated_status);
            i0 = dnx_sw_state_dump_check_all_the_same(unit,
                ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->port.orig_isolated_status
                , sizeof(*((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->port.orig_isolated_status), I0, &s0) ? I0 - 1 : 0;
        }

        if(i0 >= dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNXF_STATE__PORT__ORIG_ISOLATED_STATUS, ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->port.orig_isolated_status))
        {
            LOG_CLI((BSL_META("dnxf_state[]->((dnxf_state_t*)sw_state_roots_array[][DNXF_MODULE_ID])->port.orig_isolated_status[]: ")));
            LOG_CLI((BSL_META("Invalid index: %d \n"),i0));
            SHR_EXIT();
        }

        if(dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNXF_STATE__PORT__ORIG_ISOLATED_STATUS, ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->port.orig_isolated_status) == 0)
        {
            SHR_EXIT();
        }

        for(; i0 < I0; i0++) {
            dnx_sw_state_dump_update_current_idx(unit, i0);
            DNX_SW_STATE_PRINT_MONITOR(
                unit,
                "dnxf_state[%d]->","((dnxf_state_t*)sw_state_roots_array[%d][DNXF_MODULE_ID])->","port.orig_isolated_status[%s%d]: ", s0, i0);

            DNX_SW_STATE_PRINT_FILE(
                unit,
                "[%s%d]: ", s0, i0);

            dnx_sw_state_print_int(
                unit,
                &((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->port.orig_isolated_status[i0]);

        }
        dnx_sw_state_dump_end_of_stride(unit);
        dnx_sw_state_dump_detach_file(
            unit);

    }

    DNXC_SW_STATE_FUNC_RETURN;
}



int
dnxf_state_cable_swap_dump(int  unit,  dnx_sw_state_dump_filters_t  filters)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;
    SHR_IF_ERR_EXIT(dnxf_state_cable_swap_is_enable_dump(unit, -1, filters));
    SHR_IF_ERR_EXIT(dnxf_state_cable_swap_is_master_dump(unit, -1, filters));
    DNXC_SW_STATE_FUNC_RETURN;
}



int
dnxf_state_cable_swap_is_enable_dump(int  unit,  int  is_enable_idx_0,  dnx_sw_state_dump_filters_t  filters)
{
    int i0 = is_enable_idx_0, I0 = is_enable_idx_0 + 1;
    char *s0 = "";
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    if (dnx_sw_state_compare(filters.typefilter, "int") != TRUE)
    {
         SHR_EXIT();
    }

    if (dnx_sw_state_compare(filters.namefilter, "dnxf cable_swap is_enable") != TRUE)
    {
         SHR_EXIT();
    }

    if (filters.nocontent)
    {
         DNX_SW_STATE_PRINT(unit, "swstate dnxf cable_swap is_enable\n");
    }
    else
    {
        dnx_sw_state_dump_attach_file(
            unit,
            "dnxf_state/cable_swap/is_enable.txt",
            "dnxf_state[%d]->","((dnxf_state_t*)sw_state_roots_array[%d][DNXF_MODULE_ID])->","cable_swap.is_enable[]: ");

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID]));

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->cable_swap.is_enable);

        if (i0 == -1) {
            I0 = dnx_sw_state_get_nof_elements(unit,
                DNX_SW_STATE_DNXF_STATE__CABLE_SWAP__IS_ENABLE,
                ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->cable_swap.is_enable);
            i0 = dnx_sw_state_dump_check_all_the_same(unit,
                ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->cable_swap.is_enable
                , sizeof(*((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->cable_swap.is_enable), I0, &s0) ? I0 - 1 : 0;
        }

        if(i0 >= dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNXF_STATE__CABLE_SWAP__IS_ENABLE, ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->cable_swap.is_enable))
        {
            LOG_CLI((BSL_META("dnxf_state[]->((dnxf_state_t*)sw_state_roots_array[][DNXF_MODULE_ID])->cable_swap.is_enable[]: ")));
            LOG_CLI((BSL_META("Invalid index: %d \n"),i0));
            SHR_EXIT();
        }

        if(dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNXF_STATE__CABLE_SWAP__IS_ENABLE, ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->cable_swap.is_enable) == 0)
        {
            SHR_EXIT();
        }

        for(; i0 < I0; i0++) {
            dnx_sw_state_dump_update_current_idx(unit, i0);
            DNX_SW_STATE_PRINT_MONITOR(
                unit,
                "dnxf_state[%d]->","((dnxf_state_t*)sw_state_roots_array[%d][DNXF_MODULE_ID])->","cable_swap.is_enable[%s%d]: ", s0, i0);

            DNX_SW_STATE_PRINT_FILE(
                unit,
                "[%s%d]: ", s0, i0);

            dnx_sw_state_print_int(
                unit,
                &((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->cable_swap.is_enable[i0]);

        }
        dnx_sw_state_dump_end_of_stride(unit);
        dnx_sw_state_dump_detach_file(
            unit);

    }

    DNXC_SW_STATE_FUNC_RETURN;
}



int
dnxf_state_cable_swap_is_master_dump(int  unit,  int  is_master_idx_0,  dnx_sw_state_dump_filters_t  filters)
{
    int i0 = is_master_idx_0, I0 = is_master_idx_0 + 1;
    char *s0 = "";
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    if (dnx_sw_state_compare(filters.typefilter, "int") != TRUE)
    {
         SHR_EXIT();
    }

    if (dnx_sw_state_compare(filters.namefilter, "dnxf cable_swap is_master") != TRUE)
    {
         SHR_EXIT();
    }

    if (filters.nocontent)
    {
         DNX_SW_STATE_PRINT(unit, "swstate dnxf cable_swap is_master\n");
    }
    else
    {
        dnx_sw_state_dump_attach_file(
            unit,
            "dnxf_state/cable_swap/is_master.txt",
            "dnxf_state[%d]->","((dnxf_state_t*)sw_state_roots_array[%d][DNXF_MODULE_ID])->","cable_swap.is_master[]: ");

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID]));

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->cable_swap.is_master);

        if (i0 == -1) {
            I0 = dnx_sw_state_get_nof_elements(unit,
                DNX_SW_STATE_DNXF_STATE__CABLE_SWAP__IS_MASTER,
                ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->cable_swap.is_master);
            i0 = dnx_sw_state_dump_check_all_the_same(unit,
                ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->cable_swap.is_master
                , sizeof(*((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->cable_swap.is_master), I0, &s0) ? I0 - 1 : 0;
        }

        if(i0 >= dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNXF_STATE__CABLE_SWAP__IS_MASTER, ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->cable_swap.is_master))
        {
            LOG_CLI((BSL_META("dnxf_state[]->((dnxf_state_t*)sw_state_roots_array[][DNXF_MODULE_ID])->cable_swap.is_master[]: ")));
            LOG_CLI((BSL_META("Invalid index: %d \n"),i0));
            SHR_EXIT();
        }

        if(dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNXF_STATE__CABLE_SWAP__IS_MASTER, ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->cable_swap.is_master) == 0)
        {
            SHR_EXIT();
        }

        for(; i0 < I0; i0++) {
            dnx_sw_state_dump_update_current_idx(unit, i0);
            DNX_SW_STATE_PRINT_MONITOR(
                unit,
                "dnxf_state[%d]->","((dnxf_state_t*)sw_state_roots_array[%d][DNXF_MODULE_ID])->","cable_swap.is_master[%s%d]: ", s0, i0);

            DNX_SW_STATE_PRINT_FILE(
                unit,
                "[%s%d]: ", s0, i0);

            dnx_sw_state_print_int(
                unit,
                &((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->cable_swap.is_master[i0]);

        }
        dnx_sw_state_dump_end_of_stride(unit);
        dnx_sw_state_dump_detach_file(
            unit);

    }

    DNXC_SW_STATE_FUNC_RETURN;
}



int
dnxf_state_intr_dump(int  unit,  dnx_sw_state_dump_filters_t  filters)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;
    SHR_IF_ERR_EXIT(dnxf_state_intr_flags_dump(unit, -1, filters));
    SHR_IF_ERR_EXIT(dnxf_state_intr_storm_timed_count_dump(unit, -1, filters));
    SHR_IF_ERR_EXIT(dnxf_state_intr_storm_timed_period_dump(unit, -1, filters));
    SHR_IF_ERR_EXIT(dnxf_state_intr_storm_nominal_dump(unit, filters));
    DNXC_SW_STATE_FUNC_RETURN;
}



int
dnxf_state_intr_flags_dump(int  unit,  int  flags_idx_0,  dnx_sw_state_dump_filters_t  filters)
{
    int i0 = flags_idx_0, I0 = flags_idx_0 + 1;
    char *s0 = "";
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    if (dnx_sw_state_compare(filters.typefilter, "uint32") != TRUE)
    {
         SHR_EXIT();
    }

    if (dnx_sw_state_compare(filters.namefilter, "dnxf intr flags") != TRUE)
    {
         SHR_EXIT();
    }

    if (filters.nocontent)
    {
         DNX_SW_STATE_PRINT(unit, "swstate dnxf intr flags\n");
    }
    else
    {
        dnx_sw_state_dump_attach_file(
            unit,
            "dnxf_state/intr/flags.txt",
            "dnxf_state[%d]->","((dnxf_state_t*)sw_state_roots_array[%d][DNXF_MODULE_ID])->","intr.flags[]: ");

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID]));

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->intr.flags);

        if (i0 == -1) {
            I0 = dnx_sw_state_get_nof_elements(unit,
                DNX_SW_STATE_DNXF_STATE__INTR__FLAGS,
                ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->intr.flags);
            i0 = dnx_sw_state_dump_check_all_the_same(unit,
                ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->intr.flags
                , sizeof(*((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->intr.flags), I0, &s0) ? I0 - 1 : 0;
        }

        if(i0 >= dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNXF_STATE__INTR__FLAGS, ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->intr.flags))
        {
            LOG_CLI((BSL_META("dnxf_state[]->((dnxf_state_t*)sw_state_roots_array[][DNXF_MODULE_ID])->intr.flags[]: ")));
            LOG_CLI((BSL_META("Invalid index: %d \n"),i0));
            SHR_EXIT();
        }

        if(dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNXF_STATE__INTR__FLAGS, ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->intr.flags) == 0)
        {
            SHR_EXIT();
        }

        for(; i0 < I0; i0++) {
            dnx_sw_state_dump_update_current_idx(unit, i0);
            DNX_SW_STATE_PRINT_MONITOR(
                unit,
                "dnxf_state[%d]->","((dnxf_state_t*)sw_state_roots_array[%d][DNXF_MODULE_ID])->","intr.flags[%s%d]: ", s0, i0);

            DNX_SW_STATE_PRINT_FILE(
                unit,
                "[%s%d]: ", s0, i0);

            dnx_sw_state_print_uint32(
                unit,
                &((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->intr.flags[i0]);

        }
        dnx_sw_state_dump_end_of_stride(unit);
        dnx_sw_state_dump_detach_file(
            unit);

    }

    DNXC_SW_STATE_FUNC_RETURN;
}



int
dnxf_state_intr_storm_timed_count_dump(int  unit,  int  storm_timed_count_idx_0,  dnx_sw_state_dump_filters_t  filters)
{
    int i0 = storm_timed_count_idx_0, I0 = storm_timed_count_idx_0 + 1;
    char *s0 = "";
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    if (dnx_sw_state_compare(filters.typefilter, "uint32") != TRUE)
    {
         SHR_EXIT();
    }

    if (dnx_sw_state_compare(filters.namefilter, "dnxf intr storm_timed_count") != TRUE)
    {
         SHR_EXIT();
    }

    if (filters.nocontent)
    {
         DNX_SW_STATE_PRINT(unit, "swstate dnxf intr storm_timed_count\n");
    }
    else
    {
        dnx_sw_state_dump_attach_file(
            unit,
            "dnxf_state/intr/storm_timed_count.txt",
            "dnxf_state[%d]->","((dnxf_state_t*)sw_state_roots_array[%d][DNXF_MODULE_ID])->","intr.storm_timed_count[]: ");

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID]));

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->intr.storm_timed_count);

        if (i0 == -1) {
            I0 = dnx_sw_state_get_nof_elements(unit,
                DNX_SW_STATE_DNXF_STATE__INTR__STORM_TIMED_COUNT,
                ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->intr.storm_timed_count);
            i0 = dnx_sw_state_dump_check_all_the_same(unit,
                ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->intr.storm_timed_count
                , sizeof(*((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->intr.storm_timed_count), I0, &s0) ? I0 - 1 : 0;
        }

        if(i0 >= dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNXF_STATE__INTR__STORM_TIMED_COUNT, ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->intr.storm_timed_count))
        {
            LOG_CLI((BSL_META("dnxf_state[]->((dnxf_state_t*)sw_state_roots_array[][DNXF_MODULE_ID])->intr.storm_timed_count[]: ")));
            LOG_CLI((BSL_META("Invalid index: %d \n"),i0));
            SHR_EXIT();
        }

        if(dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNXF_STATE__INTR__STORM_TIMED_COUNT, ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->intr.storm_timed_count) == 0)
        {
            SHR_EXIT();
        }

        for(; i0 < I0; i0++) {
            dnx_sw_state_dump_update_current_idx(unit, i0);
            DNX_SW_STATE_PRINT_MONITOR(
                unit,
                "dnxf_state[%d]->","((dnxf_state_t*)sw_state_roots_array[%d][DNXF_MODULE_ID])->","intr.storm_timed_count[%s%d]: ", s0, i0);

            DNX_SW_STATE_PRINT_FILE(
                unit,
                "[%s%d]: ", s0, i0);

            dnx_sw_state_print_uint32(
                unit,
                &((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->intr.storm_timed_count[i0]);

        }
        dnx_sw_state_dump_end_of_stride(unit);
        dnx_sw_state_dump_detach_file(
            unit);

    }

    DNXC_SW_STATE_FUNC_RETURN;
}



int
dnxf_state_intr_storm_timed_period_dump(int  unit,  int  storm_timed_period_idx_0,  dnx_sw_state_dump_filters_t  filters)
{
    int i0 = storm_timed_period_idx_0, I0 = storm_timed_period_idx_0 + 1;
    char *s0 = "";
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    if (dnx_sw_state_compare(filters.typefilter, "uint32") != TRUE)
    {
         SHR_EXIT();
    }

    if (dnx_sw_state_compare(filters.namefilter, "dnxf intr storm_timed_period") != TRUE)
    {
         SHR_EXIT();
    }

    if (filters.nocontent)
    {
         DNX_SW_STATE_PRINT(unit, "swstate dnxf intr storm_timed_period\n");
    }
    else
    {
        dnx_sw_state_dump_attach_file(
            unit,
            "dnxf_state/intr/storm_timed_period.txt",
            "dnxf_state[%d]->","((dnxf_state_t*)sw_state_roots_array[%d][DNXF_MODULE_ID])->","intr.storm_timed_period[]: ");

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID]));

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->intr.storm_timed_period);

        if (i0 == -1) {
            I0 = dnx_sw_state_get_nof_elements(unit,
                DNX_SW_STATE_DNXF_STATE__INTR__STORM_TIMED_PERIOD,
                ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->intr.storm_timed_period);
            i0 = dnx_sw_state_dump_check_all_the_same(unit,
                ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->intr.storm_timed_period
                , sizeof(*((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->intr.storm_timed_period), I0, &s0) ? I0 - 1 : 0;
        }

        if(i0 >= dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNXF_STATE__INTR__STORM_TIMED_PERIOD, ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->intr.storm_timed_period))
        {
            LOG_CLI((BSL_META("dnxf_state[]->((dnxf_state_t*)sw_state_roots_array[][DNXF_MODULE_ID])->intr.storm_timed_period[]: ")));
            LOG_CLI((BSL_META("Invalid index: %d \n"),i0));
            SHR_EXIT();
        }

        if(dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNXF_STATE__INTR__STORM_TIMED_PERIOD, ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->intr.storm_timed_period) == 0)
        {
            SHR_EXIT();
        }

        for(; i0 < I0; i0++) {
            dnx_sw_state_dump_update_current_idx(unit, i0);
            DNX_SW_STATE_PRINT_MONITOR(
                unit,
                "dnxf_state[%d]->","((dnxf_state_t*)sw_state_roots_array[%d][DNXF_MODULE_ID])->","intr.storm_timed_period[%s%d]: ", s0, i0);

            DNX_SW_STATE_PRINT_FILE(
                unit,
                "[%s%d]: ", s0, i0);

            dnx_sw_state_print_uint32(
                unit,
                &((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->intr.storm_timed_period[i0]);

        }
        dnx_sw_state_dump_end_of_stride(unit);
        dnx_sw_state_dump_detach_file(
            unit);

    }

    DNXC_SW_STATE_FUNC_RETURN;
}



int
dnxf_state_intr_storm_nominal_dump(int  unit,  dnx_sw_state_dump_filters_t  filters)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    if (dnx_sw_state_compare(filters.typefilter, "uint32") != TRUE)
    {
         SHR_EXIT();
    }

    if (dnx_sw_state_compare(filters.namefilter, "dnxf intr storm_nominal") != TRUE)
    {
         SHR_EXIT();
    }

    if (filters.nocontent)
    {
         DNX_SW_STATE_PRINT(unit, "swstate dnxf intr storm_nominal\n");
    }
    else
    {
        dnx_sw_state_dump_attach_file(
            unit,
            "dnxf_state/intr/storm_nominal.txt",
            "dnxf_state[%d]->","((dnxf_state_t*)sw_state_roots_array[%d][DNXF_MODULE_ID])->","intr.storm_nominal: ");

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID]));

        DNX_SW_STATE_PRINT_MONITOR(
            unit,
            "dnxf_state[%d]->","((dnxf_state_t*)sw_state_roots_array[%d][DNXF_MODULE_ID])->","intr.storm_nominal: ");

        DNX_SW_STATE_PRINT_FILE(
            unit,
            " ");

        dnx_sw_state_print_uint32(
            unit,
            &((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->intr.storm_nominal);

        dnx_sw_state_dump_detach_file(
            unit);

    }

    DNXC_SW_STATE_FUNC_RETURN;
}



int
dnxf_state_lane_map_db_dump(int  unit,  dnx_sw_state_dump_filters_t  filters)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;
    SHR_IF_ERR_EXIT(dnxf_state_lane_map_db_serdes_map_dump(unit, filters));
    SHR_IF_ERR_EXIT(dnxf_state_lane_map_db_link_to_fmac_lane_map_dump(unit, -1, filters));
    DNXC_SW_STATE_FUNC_RETURN;
}



int
dnxf_state_lane_map_db_serdes_map_dump(int  unit,  dnx_sw_state_dump_filters_t  filters)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;
    SHR_IF_ERR_EXIT(dnxf_state_lane_map_db_serdes_map_map_size_dump(unit, filters));
    SHR_IF_ERR_EXIT(dnxf_state_lane_map_db_serdes_map_lane2serdes_dump(unit, -1, filters));
    SHR_IF_ERR_EXIT(dnxf_state_lane_map_db_serdes_map_serdes2lane_dump(unit, -1, filters));
    DNXC_SW_STATE_FUNC_RETURN;
}



int
dnxf_state_lane_map_db_serdes_map_map_size_dump(int  unit,  dnx_sw_state_dump_filters_t  filters)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    if (dnx_sw_state_compare(filters.typefilter, "int") != TRUE)
    {
         SHR_EXIT();
    }

    if (dnx_sw_state_compare(filters.namefilter, "dnxf lane_map_db serdes_map map_size") != TRUE)
    {
         SHR_EXIT();
    }

    if (filters.nocontent)
    {
         DNX_SW_STATE_PRINT(unit, "swstate dnxf lane_map_db serdes_map map_size\n");
    }
    else
    {
        dnx_sw_state_dump_attach_file(
            unit,
            "dnxf_state/lane_map_db/serdes_map/map_size.txt",
            "dnxf_state[%d]->","((dnxf_state_t*)sw_state_roots_array[%d][DNXF_MODULE_ID])->","lane_map_db.serdes_map.map_size: ");

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID]));

        DNX_SW_STATE_PRINT_MONITOR(
            unit,
            "dnxf_state[%d]->","((dnxf_state_t*)sw_state_roots_array[%d][DNXF_MODULE_ID])->","lane_map_db.serdes_map.map_size: ");

        DNX_SW_STATE_PRINT_FILE(
            unit,
            " ");

        dnx_sw_state_print_int(
            unit,
            &((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->lane_map_db.serdes_map.map_size);

        dnx_sw_state_dump_detach_file(
            unit);

    }

    DNXC_SW_STATE_FUNC_RETURN;
}



int
dnxf_state_lane_map_db_serdes_map_lane2serdes_dump(int  unit,  int  lane2serdes_idx_0,  dnx_sw_state_dump_filters_t  filters)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;
    SHR_IF_ERR_EXIT(dnxf_state_lane_map_db_serdes_map_lane2serdes_rx_id_dump(unit, lane2serdes_idx_0, filters));
    SHR_IF_ERR_EXIT(dnxf_state_lane_map_db_serdes_map_lane2serdes_tx_id_dump(unit, lane2serdes_idx_0, filters));
    DNXC_SW_STATE_FUNC_RETURN;
}



int
dnxf_state_lane_map_db_serdes_map_lane2serdes_rx_id_dump(int  unit,  int  lane2serdes_idx_0,  dnx_sw_state_dump_filters_t  filters)
{
    int i0 = lane2serdes_idx_0, I0 = lane2serdes_idx_0 + 1;
    char *s0 = "";
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    if (dnx_sw_state_compare(filters.typefilter, "int") != TRUE)
    {
         SHR_EXIT();
    }

    if (dnx_sw_state_compare(filters.namefilter, "dnxf lane_map_db serdes_map lane2serdes rx_id") != TRUE)
    {
         SHR_EXIT();
    }

    if (filters.nocontent)
    {
         DNX_SW_STATE_PRINT(unit, "swstate dnxf lane_map_db serdes_map lane2serdes rx_id\n");
    }
    else
    {
        dnx_sw_state_dump_attach_file(
            unit,
            "dnxf_state/lane_map_db/serdes_map/lane2serdes/rx_id.txt",
            "dnxf_state[%d]->","((dnxf_state_t*)sw_state_roots_array[%d][DNXF_MODULE_ID])->","lane_map_db.serdes_map.lane2serdes[].rx_id: ");

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID]));

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->lane_map_db.serdes_map.lane2serdes);

        if (i0 == -1) {
            I0 = dnx_sw_state_get_nof_elements(unit,
                DNX_SW_STATE_DNXF_STATE__LANE_MAP_DB__SERDES_MAP__LANE2SERDES__RX_ID,
                ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->lane_map_db.serdes_map.lane2serdes);
            i0 = dnx_sw_state_dump_check_all_the_same(unit,
                ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->lane_map_db.serdes_map.lane2serdes
                , sizeof(*((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->lane_map_db.serdes_map.lane2serdes), I0, &s0) ? I0 - 1 : 0;
        }

        if(i0 >= dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNXF_STATE__LANE_MAP_DB__SERDES_MAP__LANE2SERDES__RX_ID, ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->lane_map_db.serdes_map.lane2serdes))
        {
            LOG_CLI((BSL_META("dnxf_state[]->((dnxf_state_t*)sw_state_roots_array[][DNXF_MODULE_ID])->lane_map_db.serdes_map.lane2serdes[].rx_id: ")));
            LOG_CLI((BSL_META("Invalid index: %d \n"),i0));
            SHR_EXIT();
        }

        if(dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNXF_STATE__LANE_MAP_DB__SERDES_MAP__LANE2SERDES__RX_ID, ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->lane_map_db.serdes_map.lane2serdes) == 0)
        {
            SHR_EXIT();
        }

        for(; i0 < I0; i0++) {
            dnx_sw_state_dump_update_current_idx(unit, i0);
            DNX_SW_STATE_PRINT_MONITOR(
                unit,
                "dnxf_state[%d]->","((dnxf_state_t*)sw_state_roots_array[%d][DNXF_MODULE_ID])->","lane_map_db.serdes_map.lane2serdes[%s%d].rx_id: ", s0, i0);

            DNX_SW_STATE_PRINT_FILE(
                unit,
                "[%s%d]: ", s0, i0);

            dnx_sw_state_print_int(
                unit,
                &((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->lane_map_db.serdes_map.lane2serdes[i0].rx_id);

        }
        dnx_sw_state_dump_end_of_stride(unit);
        dnx_sw_state_dump_detach_file(
            unit);

    }

    DNXC_SW_STATE_FUNC_RETURN;
}



int
dnxf_state_lane_map_db_serdes_map_lane2serdes_tx_id_dump(int  unit,  int  lane2serdes_idx_0,  dnx_sw_state_dump_filters_t  filters)
{
    int i0 = lane2serdes_idx_0, I0 = lane2serdes_idx_0 + 1;
    char *s0 = "";
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    if (dnx_sw_state_compare(filters.typefilter, "int") != TRUE)
    {
         SHR_EXIT();
    }

    if (dnx_sw_state_compare(filters.namefilter, "dnxf lane_map_db serdes_map lane2serdes tx_id") != TRUE)
    {
         SHR_EXIT();
    }

    if (filters.nocontent)
    {
         DNX_SW_STATE_PRINT(unit, "swstate dnxf lane_map_db serdes_map lane2serdes tx_id\n");
    }
    else
    {
        dnx_sw_state_dump_attach_file(
            unit,
            "dnxf_state/lane_map_db/serdes_map/lane2serdes/tx_id.txt",
            "dnxf_state[%d]->","((dnxf_state_t*)sw_state_roots_array[%d][DNXF_MODULE_ID])->","lane_map_db.serdes_map.lane2serdes[].tx_id: ");

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID]));

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->lane_map_db.serdes_map.lane2serdes);

        if (i0 == -1) {
            I0 = dnx_sw_state_get_nof_elements(unit,
                DNX_SW_STATE_DNXF_STATE__LANE_MAP_DB__SERDES_MAP__LANE2SERDES__TX_ID,
                ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->lane_map_db.serdes_map.lane2serdes);
            i0 = dnx_sw_state_dump_check_all_the_same(unit,
                ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->lane_map_db.serdes_map.lane2serdes
                , sizeof(*((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->lane_map_db.serdes_map.lane2serdes), I0, &s0) ? I0 - 1 : 0;
        }

        if(i0 >= dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNXF_STATE__LANE_MAP_DB__SERDES_MAP__LANE2SERDES__TX_ID, ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->lane_map_db.serdes_map.lane2serdes))
        {
            LOG_CLI((BSL_META("dnxf_state[]->((dnxf_state_t*)sw_state_roots_array[][DNXF_MODULE_ID])->lane_map_db.serdes_map.lane2serdes[].tx_id: ")));
            LOG_CLI((BSL_META("Invalid index: %d \n"),i0));
            SHR_EXIT();
        }

        if(dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNXF_STATE__LANE_MAP_DB__SERDES_MAP__LANE2SERDES__TX_ID, ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->lane_map_db.serdes_map.lane2serdes) == 0)
        {
            SHR_EXIT();
        }

        for(; i0 < I0; i0++) {
            dnx_sw_state_dump_update_current_idx(unit, i0);
            DNX_SW_STATE_PRINT_MONITOR(
                unit,
                "dnxf_state[%d]->","((dnxf_state_t*)sw_state_roots_array[%d][DNXF_MODULE_ID])->","lane_map_db.serdes_map.lane2serdes[%s%d].tx_id: ", s0, i0);

            DNX_SW_STATE_PRINT_FILE(
                unit,
                "[%s%d]: ", s0, i0);

            dnx_sw_state_print_int(
                unit,
                &((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->lane_map_db.serdes_map.lane2serdes[i0].tx_id);

        }
        dnx_sw_state_dump_end_of_stride(unit);
        dnx_sw_state_dump_detach_file(
            unit);

    }

    DNXC_SW_STATE_FUNC_RETURN;
}



int
dnxf_state_lane_map_db_serdes_map_serdes2lane_dump(int  unit,  int  serdes2lane_idx_0,  dnx_sw_state_dump_filters_t  filters)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;
    SHR_IF_ERR_EXIT(dnxf_state_lane_map_db_serdes_map_serdes2lane_rx_id_dump(unit, serdes2lane_idx_0, filters));
    SHR_IF_ERR_EXIT(dnxf_state_lane_map_db_serdes_map_serdes2lane_tx_id_dump(unit, serdes2lane_idx_0, filters));
    DNXC_SW_STATE_FUNC_RETURN;
}



int
dnxf_state_lane_map_db_serdes_map_serdes2lane_rx_id_dump(int  unit,  int  serdes2lane_idx_0,  dnx_sw_state_dump_filters_t  filters)
{
    int i0 = serdes2lane_idx_0, I0 = serdes2lane_idx_0 + 1;
    char *s0 = "";
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    if (dnx_sw_state_compare(filters.typefilter, "int") != TRUE)
    {
         SHR_EXIT();
    }

    if (dnx_sw_state_compare(filters.namefilter, "dnxf lane_map_db serdes_map serdes2lane rx_id") != TRUE)
    {
         SHR_EXIT();
    }

    if (filters.nocontent)
    {
         DNX_SW_STATE_PRINT(unit, "swstate dnxf lane_map_db serdes_map serdes2lane rx_id\n");
    }
    else
    {
        dnx_sw_state_dump_attach_file(
            unit,
            "dnxf_state/lane_map_db/serdes_map/serdes2lane/rx_id.txt",
            "dnxf_state[%d]->","((dnxf_state_t*)sw_state_roots_array[%d][DNXF_MODULE_ID])->","lane_map_db.serdes_map.serdes2lane[].rx_id: ");

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID]));

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->lane_map_db.serdes_map.serdes2lane);

        if (i0 == -1) {
            I0 = dnx_sw_state_get_nof_elements(unit,
                DNX_SW_STATE_DNXF_STATE__LANE_MAP_DB__SERDES_MAP__SERDES2LANE__RX_ID,
                ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->lane_map_db.serdes_map.serdes2lane);
            i0 = dnx_sw_state_dump_check_all_the_same(unit,
                ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->lane_map_db.serdes_map.serdes2lane
                , sizeof(*((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->lane_map_db.serdes_map.serdes2lane), I0, &s0) ? I0 - 1 : 0;
        }

        if(i0 >= dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNXF_STATE__LANE_MAP_DB__SERDES_MAP__SERDES2LANE__RX_ID, ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->lane_map_db.serdes_map.serdes2lane))
        {
            LOG_CLI((BSL_META("dnxf_state[]->((dnxf_state_t*)sw_state_roots_array[][DNXF_MODULE_ID])->lane_map_db.serdes_map.serdes2lane[].rx_id: ")));
            LOG_CLI((BSL_META("Invalid index: %d \n"),i0));
            SHR_EXIT();
        }

        if(dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNXF_STATE__LANE_MAP_DB__SERDES_MAP__SERDES2LANE__RX_ID, ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->lane_map_db.serdes_map.serdes2lane) == 0)
        {
            SHR_EXIT();
        }

        for(; i0 < I0; i0++) {
            dnx_sw_state_dump_update_current_idx(unit, i0);
            DNX_SW_STATE_PRINT_MONITOR(
                unit,
                "dnxf_state[%d]->","((dnxf_state_t*)sw_state_roots_array[%d][DNXF_MODULE_ID])->","lane_map_db.serdes_map.serdes2lane[%s%d].rx_id: ", s0, i0);

            DNX_SW_STATE_PRINT_FILE(
                unit,
                "[%s%d]: ", s0, i0);

            dnx_sw_state_print_int(
                unit,
                &((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->lane_map_db.serdes_map.serdes2lane[i0].rx_id);

        }
        dnx_sw_state_dump_end_of_stride(unit);
        dnx_sw_state_dump_detach_file(
            unit);

    }

    DNXC_SW_STATE_FUNC_RETURN;
}



int
dnxf_state_lane_map_db_serdes_map_serdes2lane_tx_id_dump(int  unit,  int  serdes2lane_idx_0,  dnx_sw_state_dump_filters_t  filters)
{
    int i0 = serdes2lane_idx_0, I0 = serdes2lane_idx_0 + 1;
    char *s0 = "";
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    if (dnx_sw_state_compare(filters.typefilter, "int") != TRUE)
    {
         SHR_EXIT();
    }

    if (dnx_sw_state_compare(filters.namefilter, "dnxf lane_map_db serdes_map serdes2lane tx_id") != TRUE)
    {
         SHR_EXIT();
    }

    if (filters.nocontent)
    {
         DNX_SW_STATE_PRINT(unit, "swstate dnxf lane_map_db serdes_map serdes2lane tx_id\n");
    }
    else
    {
        dnx_sw_state_dump_attach_file(
            unit,
            "dnxf_state/lane_map_db/serdes_map/serdes2lane/tx_id.txt",
            "dnxf_state[%d]->","((dnxf_state_t*)sw_state_roots_array[%d][DNXF_MODULE_ID])->","lane_map_db.serdes_map.serdes2lane[].tx_id: ");

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID]));

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->lane_map_db.serdes_map.serdes2lane);

        if (i0 == -1) {
            I0 = dnx_sw_state_get_nof_elements(unit,
                DNX_SW_STATE_DNXF_STATE__LANE_MAP_DB__SERDES_MAP__SERDES2LANE__TX_ID,
                ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->lane_map_db.serdes_map.serdes2lane);
            i0 = dnx_sw_state_dump_check_all_the_same(unit,
                ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->lane_map_db.serdes_map.serdes2lane
                , sizeof(*((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->lane_map_db.serdes_map.serdes2lane), I0, &s0) ? I0 - 1 : 0;
        }

        if(i0 >= dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNXF_STATE__LANE_MAP_DB__SERDES_MAP__SERDES2LANE__TX_ID, ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->lane_map_db.serdes_map.serdes2lane))
        {
            LOG_CLI((BSL_META("dnxf_state[]->((dnxf_state_t*)sw_state_roots_array[][DNXF_MODULE_ID])->lane_map_db.serdes_map.serdes2lane[].tx_id: ")));
            LOG_CLI((BSL_META("Invalid index: %d \n"),i0));
            SHR_EXIT();
        }

        if(dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNXF_STATE__LANE_MAP_DB__SERDES_MAP__SERDES2LANE__TX_ID, ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->lane_map_db.serdes_map.serdes2lane) == 0)
        {
            SHR_EXIT();
        }

        for(; i0 < I0; i0++) {
            dnx_sw_state_dump_update_current_idx(unit, i0);
            DNX_SW_STATE_PRINT_MONITOR(
                unit,
                "dnxf_state[%d]->","((dnxf_state_t*)sw_state_roots_array[%d][DNXF_MODULE_ID])->","lane_map_db.serdes_map.serdes2lane[%s%d].tx_id: ", s0, i0);

            DNX_SW_STATE_PRINT_FILE(
                unit,
                "[%s%d]: ", s0, i0);

            dnx_sw_state_print_int(
                unit,
                &((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->lane_map_db.serdes_map.serdes2lane[i0].tx_id);

        }
        dnx_sw_state_dump_end_of_stride(unit);
        dnx_sw_state_dump_detach_file(
            unit);

    }

    DNXC_SW_STATE_FUNC_RETURN;
}



int
dnxf_state_lane_map_db_link_to_fmac_lane_map_dump(int  unit,  int  link_to_fmac_lane_map_idx_0,  dnx_sw_state_dump_filters_t  filters)
{
    int i0 = link_to_fmac_lane_map_idx_0, I0 = link_to_fmac_lane_map_idx_0 + 1;
    char *s0 = "";
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    if (dnx_sw_state_compare(filters.typefilter, "int") != TRUE)
    {
         SHR_EXIT();
    }

    if (dnx_sw_state_compare(filters.namefilter, "dnxf lane_map_db link_to_fmac_lane_map") != TRUE)
    {
         SHR_EXIT();
    }

    if (filters.nocontent)
    {
         DNX_SW_STATE_PRINT(unit, "swstate dnxf lane_map_db link_to_fmac_lane_map\n");
    }
    else
    {
        dnx_sw_state_dump_attach_file(
            unit,
            "dnxf_state/lane_map_db/link_to_fmac_lane_map.txt",
            "dnxf_state[%d]->","((dnxf_state_t*)sw_state_roots_array[%d][DNXF_MODULE_ID])->","lane_map_db.link_to_fmac_lane_map[]: ");

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID]));

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->lane_map_db.link_to_fmac_lane_map);

        if (i0 == -1) {
            I0 = dnx_sw_state_get_nof_elements(unit,
                DNX_SW_STATE_DNXF_STATE__LANE_MAP_DB__LINK_TO_FMAC_LANE_MAP,
                ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->lane_map_db.link_to_fmac_lane_map);
            i0 = dnx_sw_state_dump_check_all_the_same(unit,
                ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->lane_map_db.link_to_fmac_lane_map
                , sizeof(*((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->lane_map_db.link_to_fmac_lane_map), I0, &s0) ? I0 - 1 : 0;
        }

        if(i0 >= dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNXF_STATE__LANE_MAP_DB__LINK_TO_FMAC_LANE_MAP, ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->lane_map_db.link_to_fmac_lane_map))
        {
            LOG_CLI((BSL_META("dnxf_state[]->((dnxf_state_t*)sw_state_roots_array[][DNXF_MODULE_ID])->lane_map_db.link_to_fmac_lane_map[]: ")));
            LOG_CLI((BSL_META("Invalid index: %d \n"),i0));
            SHR_EXIT();
        }

        if(dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNXF_STATE__LANE_MAP_DB__LINK_TO_FMAC_LANE_MAP, ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->lane_map_db.link_to_fmac_lane_map) == 0)
        {
            SHR_EXIT();
        }

        for(; i0 < I0; i0++) {
            dnx_sw_state_dump_update_current_idx(unit, i0);
            DNX_SW_STATE_PRINT_MONITOR(
                unit,
                "dnxf_state[%d]->","((dnxf_state_t*)sw_state_roots_array[%d][DNXF_MODULE_ID])->","lane_map_db.link_to_fmac_lane_map[%s%d]: ", s0, i0);

            DNX_SW_STATE_PRINT_FILE(
                unit,
                "[%s%d]: ", s0, i0);

            dnx_sw_state_print_int(
                unit,
                &((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->lane_map_db.link_to_fmac_lane_map[i0]);

        }
        dnx_sw_state_dump_end_of_stride(unit);
        dnx_sw_state_dump_detach_file(
            unit);

    }

    DNXC_SW_STATE_FUNC_RETURN;
}



int
dnxf_state_synce_dump(int  unit,  dnx_sw_state_dump_filters_t  filters)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;
    SHR_IF_ERR_EXIT(dnxf_state_synce_master_synce_enabled_dump(unit, filters));
    SHR_IF_ERR_EXIT(dnxf_state_synce_slave_synce_enabled_dump(unit, filters));
    SHR_IF_ERR_EXIT(dnxf_state_synce_master_set1_synce_enabled_dump(unit, filters));
    SHR_IF_ERR_EXIT(dnxf_state_synce_slave_set1_synce_enabled_dump(unit, filters));
    DNXC_SW_STATE_FUNC_RETURN;
}



int
dnxf_state_synce_master_synce_enabled_dump(int  unit,  dnx_sw_state_dump_filters_t  filters)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    if (dnx_sw_state_compare(filters.typefilter, "int") != TRUE)
    {
         SHR_EXIT();
    }

    if (dnx_sw_state_compare(filters.namefilter, "dnxf synce master_synce_enabled") != TRUE)
    {
         SHR_EXIT();
    }

    if (filters.nocontent)
    {
         DNX_SW_STATE_PRINT(unit, "swstate dnxf synce master_synce_enabled\n");
    }
    else
    {
        dnx_sw_state_dump_attach_file(
            unit,
            "dnxf_state/synce/master_synce_enabled.txt",
            "dnxf_state[%d]->","((dnxf_state_t*)sw_state_roots_array[%d][DNXF_MODULE_ID])->","synce.master_synce_enabled: ");

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID]));

        DNX_SW_STATE_PRINT_MONITOR(
            unit,
            "dnxf_state[%d]->","((dnxf_state_t*)sw_state_roots_array[%d][DNXF_MODULE_ID])->","synce.master_synce_enabled: ");

        DNX_SW_STATE_PRINT_FILE(
            unit,
            " ");

        dnx_sw_state_print_int(
            unit,
            &((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->synce.master_synce_enabled);

        dnx_sw_state_dump_detach_file(
            unit);

    }

    DNXC_SW_STATE_FUNC_RETURN;
}



int
dnxf_state_synce_slave_synce_enabled_dump(int  unit,  dnx_sw_state_dump_filters_t  filters)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    if (dnx_sw_state_compare(filters.typefilter, "int") != TRUE)
    {
         SHR_EXIT();
    }

    if (dnx_sw_state_compare(filters.namefilter, "dnxf synce slave_synce_enabled") != TRUE)
    {
         SHR_EXIT();
    }

    if (filters.nocontent)
    {
         DNX_SW_STATE_PRINT(unit, "swstate dnxf synce slave_synce_enabled\n");
    }
    else
    {
        dnx_sw_state_dump_attach_file(
            unit,
            "dnxf_state/synce/slave_synce_enabled.txt",
            "dnxf_state[%d]->","((dnxf_state_t*)sw_state_roots_array[%d][DNXF_MODULE_ID])->","synce.slave_synce_enabled: ");

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID]));

        DNX_SW_STATE_PRINT_MONITOR(
            unit,
            "dnxf_state[%d]->","((dnxf_state_t*)sw_state_roots_array[%d][DNXF_MODULE_ID])->","synce.slave_synce_enabled: ");

        DNX_SW_STATE_PRINT_FILE(
            unit,
            " ");

        dnx_sw_state_print_int(
            unit,
            &((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->synce.slave_synce_enabled);

        dnx_sw_state_dump_detach_file(
            unit);

    }

    DNXC_SW_STATE_FUNC_RETURN;
}



int
dnxf_state_synce_master_set1_synce_enabled_dump(int  unit,  dnx_sw_state_dump_filters_t  filters)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    if (dnx_sw_state_compare(filters.typefilter, "int") != TRUE)
    {
         SHR_EXIT();
    }

    if (dnx_sw_state_compare(filters.namefilter, "dnxf synce master_set1_synce_enabled") != TRUE)
    {
         SHR_EXIT();
    }

    if (filters.nocontent)
    {
         DNX_SW_STATE_PRINT(unit, "swstate dnxf synce master_set1_synce_enabled\n");
    }
    else
    {
        dnx_sw_state_dump_attach_file(
            unit,
            "dnxf_state/synce/master_set1_synce_enabled.txt",
            "dnxf_state[%d]->","((dnxf_state_t*)sw_state_roots_array[%d][DNXF_MODULE_ID])->","synce.master_set1_synce_enabled: ");

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID]));

        DNX_SW_STATE_PRINT_MONITOR(
            unit,
            "dnxf_state[%d]->","((dnxf_state_t*)sw_state_roots_array[%d][DNXF_MODULE_ID])->","synce.master_set1_synce_enabled: ");

        DNX_SW_STATE_PRINT_FILE(
            unit,
            " ");

        dnx_sw_state_print_int(
            unit,
            &((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->synce.master_set1_synce_enabled);

        dnx_sw_state_dump_detach_file(
            unit);

    }

    DNXC_SW_STATE_FUNC_RETURN;
}



int
dnxf_state_synce_slave_set1_synce_enabled_dump(int  unit,  dnx_sw_state_dump_filters_t  filters)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    if (dnx_sw_state_compare(filters.typefilter, "int") != TRUE)
    {
         SHR_EXIT();
    }

    if (dnx_sw_state_compare(filters.namefilter, "dnxf synce slave_set1_synce_enabled") != TRUE)
    {
         SHR_EXIT();
    }

    if (filters.nocontent)
    {
         DNX_SW_STATE_PRINT(unit, "swstate dnxf synce slave_set1_synce_enabled\n");
    }
    else
    {
        dnx_sw_state_dump_attach_file(
            unit,
            "dnxf_state/synce/slave_set1_synce_enabled.txt",
            "dnxf_state[%d]->","((dnxf_state_t*)sw_state_roots_array[%d][DNXF_MODULE_ID])->","synce.slave_set1_synce_enabled: ");

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID]));

        DNX_SW_STATE_PRINT_MONITOR(
            unit,
            "dnxf_state[%d]->","((dnxf_state_t*)sw_state_roots_array[%d][DNXF_MODULE_ID])->","synce.slave_set1_synce_enabled: ");

        DNX_SW_STATE_PRINT_FILE(
            unit,
            " ");

        dnx_sw_state_print_int(
            unit,
            &((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->synce.slave_set1_synce_enabled);

        dnx_sw_state_dump_detach_file(
            unit);

    }

    DNXC_SW_STATE_FUNC_RETURN;
}



int
dnxf_state_system_upgrade_dump(int  unit,  dnx_sw_state_dump_filters_t  filters)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;
    SHR_IF_ERR_EXIT(dnxf_state_system_upgrade_state_0_dump(unit, filters));
    SHR_IF_ERR_EXIT(dnxf_state_system_upgrade_state_1_dump(unit, filters));
    SHR_IF_ERR_EXIT(dnxf_state_system_upgrade_state_2_dump(unit, filters));
    DNXC_SW_STATE_FUNC_RETURN;
}



int
dnxf_state_system_upgrade_state_0_dump(int  unit,  dnx_sw_state_dump_filters_t  filters)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    if (dnx_sw_state_compare(filters.typefilter, "uint32") != TRUE)
    {
         SHR_EXIT();
    }

    if (dnx_sw_state_compare(filters.namefilter, "dnxf system_upgrade state_0") != TRUE)
    {
         SHR_EXIT();
    }

    if (filters.nocontent)
    {
         DNX_SW_STATE_PRINT(unit, "swstate dnxf system_upgrade state_0\n");
    }
    else
    {
        dnx_sw_state_dump_attach_file(
            unit,
            "dnxf_state/system_upgrade/state_0.txt",
            "dnxf_state[%d]->","((dnxf_state_t*)sw_state_roots_array[%d][DNXF_MODULE_ID])->","system_upgrade.state_0: ");

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID]));

        DNX_SW_STATE_PRINT_MONITOR(
            unit,
            "dnxf_state[%d]->","((dnxf_state_t*)sw_state_roots_array[%d][DNXF_MODULE_ID])->","system_upgrade.state_0: ");

        DNX_SW_STATE_PRINT_FILE(
            unit,
            " ");

        dnx_sw_state_print_uint32(
            unit,
            &((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->system_upgrade.state_0);

        dnx_sw_state_dump_detach_file(
            unit);

    }

    DNXC_SW_STATE_FUNC_RETURN;
}



int
dnxf_state_system_upgrade_state_1_dump(int  unit,  dnx_sw_state_dump_filters_t  filters)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    if (dnx_sw_state_compare(filters.typefilter, "uint32") != TRUE)
    {
         SHR_EXIT();
    }

    if (dnx_sw_state_compare(filters.namefilter, "dnxf system_upgrade state_1") != TRUE)
    {
         SHR_EXIT();
    }

    if (filters.nocontent)
    {
         DNX_SW_STATE_PRINT(unit, "swstate dnxf system_upgrade state_1\n");
    }
    else
    {
        dnx_sw_state_dump_attach_file(
            unit,
            "dnxf_state/system_upgrade/state_1.txt",
            "dnxf_state[%d]->","((dnxf_state_t*)sw_state_roots_array[%d][DNXF_MODULE_ID])->","system_upgrade.state_1: ");

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID]));

        DNX_SW_STATE_PRINT_MONITOR(
            unit,
            "dnxf_state[%d]->","((dnxf_state_t*)sw_state_roots_array[%d][DNXF_MODULE_ID])->","system_upgrade.state_1: ");

        DNX_SW_STATE_PRINT_FILE(
            unit,
            " ");

        dnx_sw_state_print_uint32(
            unit,
            &((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->system_upgrade.state_1);

        dnx_sw_state_dump_detach_file(
            unit);

    }

    DNXC_SW_STATE_FUNC_RETURN;
}



int
dnxf_state_system_upgrade_state_2_dump(int  unit,  dnx_sw_state_dump_filters_t  filters)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    if (dnx_sw_state_compare(filters.typefilter, "uint32") != TRUE)
    {
         SHR_EXIT();
    }

    if (dnx_sw_state_compare(filters.namefilter, "dnxf system_upgrade state_2") != TRUE)
    {
         SHR_EXIT();
    }

    if (filters.nocontent)
    {
         DNX_SW_STATE_PRINT(unit, "swstate dnxf system_upgrade state_2\n");
    }
    else
    {
        dnx_sw_state_dump_attach_file(
            unit,
            "dnxf_state/system_upgrade/state_2.txt",
            "dnxf_state[%d]->","((dnxf_state_t*)sw_state_roots_array[%d][DNXF_MODULE_ID])->","system_upgrade.state_2: ");

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID]));

        DNX_SW_STATE_PRINT_MONITOR(
            unit,
            "dnxf_state[%d]->","((dnxf_state_t*)sw_state_roots_array[%d][DNXF_MODULE_ID])->","system_upgrade.state_2: ");

        DNX_SW_STATE_PRINT_FILE(
            unit,
            " ");

        dnx_sw_state_print_uint32(
            unit,
            &((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->system_upgrade.state_2);

        dnx_sw_state_dump_detach_file(
            unit);

    }

    DNXC_SW_STATE_FUNC_RETURN;
}



int
dnxf_state_hard_reset_dump(int  unit,  dnx_sw_state_dump_filters_t  filters)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;
    SHR_IF_ERR_EXIT(dnxf_state_hard_reset_callback_dump(unit, filters));
    SHR_IF_ERR_EXIT(dnxf_state_hard_reset_userdata_dump(unit, filters));
    DNXC_SW_STATE_FUNC_RETURN;
}



int
dnxf_state_hard_reset_callback_dump(int  unit,  dnx_sw_state_dump_filters_t  filters)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    if (dnx_sw_state_compare(filters.typefilter, "bcm_switch_hard_reset_callback_t") != TRUE)
    {
         SHR_EXIT();
    }

    if (dnx_sw_state_compare(filters.namefilter, "dnxf hard_reset callback") != TRUE)
    {
         SHR_EXIT();
    }

    if (filters.nocontent)
    {
         DNX_SW_STATE_PRINT(unit, "swstate dnxf hard_reset callback\n");
    }
    else
    {
        dnx_sw_state_dump_attach_file(
            unit,
            "dnxf_state/hard_reset/callback.txt",
            "dnxf_state[%d]->","((dnxf_state_t*)sw_state_roots_array[%d][DNXF_MODULE_ID])->","hard_reset.callback: ");

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID]));

        DNX_SW_STATE_PRINT_OPAQUE_MONITOR(
            unit,
            ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->hard_reset.callback,
            "dnxf_state[%d]->","((dnxf_state_t*)sw_state_roots_array[%d][DNXF_MODULE_ID])->","hard_reset.callback: ");

        DNX_SW_STATE_PRINT_OPAQUE_FILE(
            unit,
            ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->hard_reset.callback,
                " ");

        dnx_sw_state_dump_detach_file(
            unit);

    }

    DNXC_SW_STATE_FUNC_RETURN;
}



int
dnxf_state_hard_reset_userdata_dump(int  unit,  dnx_sw_state_dump_filters_t  filters)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    if (dnx_sw_state_compare(filters.typefilter, "uint32*") != TRUE)
    {
         SHR_EXIT();
    }

    if (dnx_sw_state_compare(filters.namefilter, "dnxf hard_reset userdata") != TRUE)
    {
         SHR_EXIT();
    }

    if (filters.nocontent)
    {
         DNX_SW_STATE_PRINT(unit, "swstate dnxf hard_reset userdata\n");
    }
    else
    {
        dnx_sw_state_dump_attach_file(
            unit,
            "dnxf_state/hard_reset/userdata.txt",
            "dnxf_state[%d]->","((dnxf_state_t*)sw_state_roots_array[%d][DNXF_MODULE_ID])->","hard_reset.userdata: ");

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID]));

        DNX_SW_STATE_PRINT_OPAQUE_MONITOR(
            unit,
            ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->hard_reset.userdata,
            "dnxf_state[%d]->","((dnxf_state_t*)sw_state_roots_array[%d][DNXF_MODULE_ID])->","hard_reset.userdata: ");

        DNX_SW_STATE_PRINT_OPAQUE_FILE(
            unit,
            ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->hard_reset.userdata,
                " ");

        dnx_sw_state_dump_detach_file(
            unit);

    }

    DNXC_SW_STATE_FUNC_RETURN;
}



int
dnxf_state_mib_dump(int  unit,  dnx_sw_state_dump_filters_t  filters)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;
    SHR_IF_ERR_EXIT(dnxf_state_mib_counter_pbmp_dump(unit, filters));
    SHR_IF_ERR_EXIT(dnxf_state_mib_interval_dump(unit, filters));
    DNXC_SW_STATE_FUNC_RETURN;
}



int
dnxf_state_mib_counter_pbmp_dump(int  unit,  dnx_sw_state_dump_filters_t  filters)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    if (dnx_sw_state_compare(filters.typefilter, "bcm_pbmp_t") != TRUE)
    {
         SHR_EXIT();
    }

    if (dnx_sw_state_compare(filters.namefilter, "dnxf mib counter_pbmp") != TRUE)
    {
         SHR_EXIT();
    }

    if (filters.nocontent)
    {
         DNX_SW_STATE_PRINT(unit, "swstate dnxf mib counter_pbmp\n");
    }
    else
    {
        dnx_sw_state_dump_attach_file(
            unit,
            "dnxf_state/mib/counter_pbmp.txt",
            "dnxf_state[%d]->","((dnxf_state_t*)sw_state_roots_array[%d][DNXF_MODULE_ID])->","mib.counter_pbmp: ");

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID]));

        DNX_SW_STATE_PRINT_OPAQUE_MONITOR(
            unit,
            ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->mib.counter_pbmp,
            "dnxf_state[%d]->","((dnxf_state_t*)sw_state_roots_array[%d][DNXF_MODULE_ID])->","mib.counter_pbmp: ");

        DNX_SW_STATE_PRINT_OPAQUE_FILE(
            unit,
            ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->mib.counter_pbmp,
                " ");

        dnx_sw_state_dump_detach_file(
            unit);

    }

    DNXC_SW_STATE_FUNC_RETURN;
}



int
dnxf_state_mib_interval_dump(int  unit,  dnx_sw_state_dump_filters_t  filters)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    if (dnx_sw_state_compare(filters.typefilter, "int") != TRUE)
    {
         SHR_EXIT();
    }

    if (dnx_sw_state_compare(filters.namefilter, "dnxf mib interval") != TRUE)
    {
         SHR_EXIT();
    }

    if (filters.nocontent)
    {
         DNX_SW_STATE_PRINT(unit, "swstate dnxf mib interval\n");
    }
    else
    {
        dnx_sw_state_dump_attach_file(
            unit,
            "dnxf_state/mib/interval.txt",
            "dnxf_state[%d]->","((dnxf_state_t*)sw_state_roots_array[%d][DNXF_MODULE_ID])->","mib.interval: ");

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID]));

        DNX_SW_STATE_PRINT_MONITOR(
            unit,
            "dnxf_state[%d]->","((dnxf_state_t*)sw_state_roots_array[%d][DNXF_MODULE_ID])->","mib.interval: ");

        DNX_SW_STATE_PRINT_FILE(
            unit,
            " ");

        dnx_sw_state_print_int(
            unit,
            &((dnxf_state_t*)sw_state_roots_array[unit][DNXF_MODULE_ID])->mib.interval);

        dnx_sw_state_dump_detach_file(
            unit);

    }

    DNXC_SW_STATE_FUNC_RETURN;
}




dnx_sw_state_diagnostic_info_t dnxf_state_info[SOC_MAX_NUM_DEVICES][DNXF_STATE_INFO_NOF_ENTRIES];
const char* dnxf_state_layout_str[DNXF_STATE_INFO_NOF_ENTRIES] = {
    "DNXF_STATE~",
    "DNXF_STATE~INFO~",
    "DNXF_STATE~INFO~ACTIVE_CORE_BMP~",
    "DNXF_STATE~INFO~VALID_FSRD_BMP~",
    "DNXF_STATE~INFO~VALID_DCH_DCML_CORE_BMP~",
    "DNXF_STATE~MODID~",
    "DNXF_STATE~MODID~LOCAL_MAP~",
    "DNXF_STATE~MODID~LOCAL_MAP~VALID~",
    "DNXF_STATE~MODID~LOCAL_MAP~MODULE_ID~",
    "DNXF_STATE~MODID~GROUP_MAP~",
    "DNXF_STATE~MODID~GROUP_MAP~RAW~",
    "DNXF_STATE~MODID~MODID_TO_GROUP_MAP~",
    "DNXF_STATE~MC~",
    "DNXF_STATE~MC~MODE~",
    "DNXF_STATE~MC~ID_MAP~",
    "DNXF_STATE~MC~NOF_MC_GROUPS_CREATED~",
    "DNXF_STATE~LB~",
    "DNXF_STATE~LB~GROUP_TO_FIRST_LINK~",
    "DNXF_STATE~PORT~",
    "DNXF_STATE~PORT~CL72_CONF~",
    "DNXF_STATE~PORT~PHY_LANE_CONFIG~",
    "DNXF_STATE~PORT~SPEED~",
    "DNXF_STATE~PORT~FEC_TYPE~",
    "DNXF_STATE~PORT~IS_CONNECTED_TO_REPEATER~",
    "DNXF_STATE~PORT~ISOLATION_STATUS_STORED~",
    "DNXF_STATE~PORT~ORIG_ISOLATED_STATUS~",
    "DNXF_STATE~CABLE_SWAP~",
    "DNXF_STATE~CABLE_SWAP~IS_ENABLE~",
    "DNXF_STATE~CABLE_SWAP~IS_MASTER~",
    "DNXF_STATE~INTR~",
    "DNXF_STATE~INTR~FLAGS~",
    "DNXF_STATE~INTR~STORM_TIMED_COUNT~",
    "DNXF_STATE~INTR~STORM_TIMED_PERIOD~",
    "DNXF_STATE~INTR~STORM_NOMINAL~",
    "DNXF_STATE~LANE_MAP_DB~",
    "DNXF_STATE~LANE_MAP_DB~SERDES_MAP~",
    "DNXF_STATE~LANE_MAP_DB~SERDES_MAP~MAP_SIZE~",
    "DNXF_STATE~LANE_MAP_DB~SERDES_MAP~LANE2SERDES~",
    "DNXF_STATE~LANE_MAP_DB~SERDES_MAP~LANE2SERDES~RX_ID~",
    "DNXF_STATE~LANE_MAP_DB~SERDES_MAP~LANE2SERDES~TX_ID~",
    "DNXF_STATE~LANE_MAP_DB~SERDES_MAP~SERDES2LANE~",
    "DNXF_STATE~LANE_MAP_DB~SERDES_MAP~SERDES2LANE~RX_ID~",
    "DNXF_STATE~LANE_MAP_DB~SERDES_MAP~SERDES2LANE~TX_ID~",
    "DNXF_STATE~LANE_MAP_DB~LINK_TO_FMAC_LANE_MAP~",
    "DNXF_STATE~SYNCE~",
    "DNXF_STATE~SYNCE~MASTER_SYNCE_ENABLED~",
    "DNXF_STATE~SYNCE~SLAVE_SYNCE_ENABLED~",
    "DNXF_STATE~SYNCE~MASTER_SET1_SYNCE_ENABLED~",
    "DNXF_STATE~SYNCE~SLAVE_SET1_SYNCE_ENABLED~",
    "DNXF_STATE~SYSTEM_UPGRADE~",
    "DNXF_STATE~SYSTEM_UPGRADE~STATE_0~",
    "DNXF_STATE~SYSTEM_UPGRADE~STATE_1~",
    "DNXF_STATE~SYSTEM_UPGRADE~STATE_2~",
    "DNXF_STATE~HARD_RESET~",
    "DNXF_STATE~HARD_RESET~CALLBACK~",
    "DNXF_STATE~HARD_RESET~USERDATA~",
    "DNXF_STATE~MIB~",
    "DNXF_STATE~MIB~COUNTER_PBMP~",
    "DNXF_STATE~MIB~INTERVAL~",
    "DNXF_STATE~SIGNAL_QUALITY~INTERRUPT~CALLBACK~",
    "DNXF_STATE~SIGNAL_QUALITY~INTERRUPT~USERDATA~",
    "DNXF_STATE~SIGNAL_QUALITY~FMAC_CONFIG~DEGRADE_THR~",
    "DNXF_STATE~SIGNAL_QUALITY~FMAC_CONFIG~DEGRADE_CU_THR~",
    "DNXF_STATE~SIGNAL_QUALITY~FMAC_CONFIG~FAIL_THR~",
    "DNXF_STATE~SIGNAL_QUALITY~FMAC_CONFIG~FAIL_CU_THR~",
    "DNXF_STATE~SIGNAL_QUALITY~FMAC_CONFIG~INTERVAL~",
    "DNXF_STATE~IP_CONFIG~SELF_ROUTED_CONFIG~DEST_MODID~",
    "DNXF_STATE~IP_CONFIG~SELF_ROUTED_CONFIG~DEST_SYSPORT~",
    "DNXF_STATE~IP_CONFIG~SOURCE_ROUTED_CONFIG~PATH_LINK~",
    "DNXF_STATE~IP_CONFIG~SOURCE_ROUTED_CONFIG~DEST_DEVICE_TYPE~",
};
#endif 
#undef BSL_LOG_MODULE
