/** \file algo/swstate/auto_generated/diagnostic/phantom_queues_diagnostic.c
 *
 * sw state functions definitions
 *
 * DO NOT EDIT THIS FILE!
 * This file is auto-generated.
 * Edits to this file will be lost when it is regenerated.
 *
 */
/*
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2022 Broadcom Inc. All rights reserved.
 */

#ifdef BSL_LOG_MODULE
#error "BSL_LOG_MODULE redefined"
#endif
#define BSL_LOG_MODULE BSL_LS_SWSTATEDNX_GENERAL

#ifdef BCM_DNX_SUPPORT
#include <bcm_int/dnx/algo/swstate/auto_generated/diagnostic/phantom_queues_diagnostic.h>
#include <bcm_int/dnx/cosq/egress/phantom_queues.h>
#include <soc/dnx/dnx_data/auto_generated/dnx_data_max_device.h>
#include <bcm_int/dnx/algo/swstate/auto_generated/layout/phantom_queues_layout.h>
#if defined(DNX_SW_STATE_DIAGNOSTIC)
/*
 * Global Variables
 */

extern dnx_phantom_queues_db_t * dnx_phantom_queues_db_data[SOC_MAX_NUM_DEVICES];
/*
 * FUNCTIONs
 */

/*
 *
 * dump function for the variable dnx_phantom_queues_db
 * AUTO-GENERATED - DO NOT MODIFY
 *
 */
int
dnx_phantom_queues_db_dump(int  unit,  dnx_sw_state_dump_filters_t  filters)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;
    SHR_IF_ERR_EXIT(dnx_phantom_queues_db_phantom_queues_dump(unit, -1, filters));
    DNXC_SW_STATE_FUNC_RETURN;
}



/*
 *
 * dump function for the variable phantom_queues
 * AUTO-GENERATED - DO NOT MODIFY
 *
 */
int
dnx_phantom_queues_db_phantom_queues_dump(int  unit,  int  phantom_queues_idx_0,  dnx_sw_state_dump_filters_t  filters)
{
    int i0 = phantom_queues_idx_0, I0 = phantom_queues_idx_0 + 1;
    char *s0 = "";
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    if (dnx_sw_state_compare(filters.typefilter, "dnx_algo_template_t") != TRUE)
    {
         SHR_EXIT();
    }

    if (dnx_sw_state_compare(filters.namefilter, "phantom_queues phantom_queues") != TRUE)
    {
         SHR_EXIT();
    }

    if (filters.nocontent)
    {
         DNX_SW_STATE_PRINT(unit, "swstate phantom_queues phantom_queues\n");
    }
    else
    {
        dnx_sw_state_dump_attach_file(
            unit,
            "dnx_phantom_queues_db/phantom_queues.txt",
            "dnx_phantom_queues_db[%d]->","((dnx_phantom_queues_db_t*)sw_state_roots_array[%d][PHANTOM_QUEUES_MODULE_ID])->","phantom_queues[]: ");

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnx_phantom_queues_db_t*)sw_state_roots_array[unit][PHANTOM_QUEUES_MODULE_ID]));

        if (i0 == -1) {
            I0 = DNX_DATA_MAX_DEVICE_GENERAL_NOF_CORES;
            i0 = dnx_sw_state_dump_check_all_the_same(unit,
                ((dnx_phantom_queues_db_t*)sw_state_roots_array[unit][PHANTOM_QUEUES_MODULE_ID])->phantom_queues
                , sizeof(*((dnx_phantom_queues_db_t*)sw_state_roots_array[unit][PHANTOM_QUEUES_MODULE_ID])->phantom_queues), I0, &s0) ? I0 - 1 : 0;
        }

        if(i0 >= DNX_DATA_MAX_DEVICE_GENERAL_NOF_CORES)
        {
            LOG_CLI((BSL_META("dnx_phantom_queues_db[]->((dnx_phantom_queues_db_t*)sw_state_roots_array[][PHANTOM_QUEUES_MODULE_ID])->phantom_queues[]: ")));
            LOG_CLI((BSL_META("Invalid index: %d \n"),i0));
            SHR_EXIT();
        }

        if(DNX_DATA_MAX_DEVICE_GENERAL_NOF_CORES == 0)
        {
            SHR_EXIT();
        }

        for(; i0 < I0; i0++) {
            dnx_sw_state_dump_update_current_idx(unit, i0);
            DNX_SW_STATE_PRINT_MONITOR(
                unit,
                "dnx_phantom_queues_db[%d]->","((dnx_phantom_queues_db_t*)sw_state_roots_array[%d][PHANTOM_QUEUES_MODULE_ID])->","phantom_queues[%s%d]: ", s0, i0);

            DNX_SW_STATE_PRINT_FILE(
                unit,
                "[%s%d]: ", s0, i0);

            DNX_ALGO_TEMP_MNGR_PRINT(
                unit,
                PHANTOM_QUEUES_MODULE_ID,
                &((dnx_phantom_queues_db_t*)sw_state_roots_array[unit][PHANTOM_QUEUES_MODULE_ID])->phantom_queues[i0],
                dnx_cosq_ohantom_queues_profile_print_cb);

        }
        dnx_sw_state_dump_end_of_stride(unit);
        dnx_sw_state_dump_detach_file(
            unit);

    }

    DNXC_SW_STATE_FUNC_RETURN;
}



/*
 * Global Variables
 */

dnx_sw_state_diagnostic_info_t dnx_phantom_queues_db_info[SOC_MAX_NUM_DEVICES][DNX_PHANTOM_QUEUES_DB_INFO_NOF_ENTRIES];
const char* dnx_phantom_queues_db_layout_str[DNX_PHANTOM_QUEUES_DB_INFO_NOF_ENTRIES] = {
    "DNX_PHANTOM_QUEUES_DB~",
    "DNX_PHANTOM_QUEUES_DB~PHANTOM_QUEUES~",
};
#endif /* DNX_SW_STATE_DIAGNOSTIC */
#endif /* BCM_DNX_SUPPORT*/ 
#undef BSL_LOG_MODULE
