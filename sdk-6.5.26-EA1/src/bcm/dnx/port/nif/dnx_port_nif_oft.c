/**
 *
 * \file dnx_port_nif_oft.c 
 * 
 *
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2022 Broadcom Inc. All rights reserved.
 *
 * NIF OFT procedures for DNX.
 *
 */

/*
 * Include files:
 * {
 */

#include "dnx_port_nif_oft_internal.h"
#include "dnx_port_nif_link_list_internal.h"
#include "dnx_port_nif_calendar_internal.h"

#include <soc/dnx/dbal/dbal.h>
#include <bcm_int/dnx/port/imb/imb_common.h>
#include <bcm_int/dnx/port/nif/dnx_port_nif_oft.h>
#include <bcm_int/dnx/algo/port/algo_port_mgmt.h>
#include <shared/utilex/utilex_integer_arithmetic.h>
#include <soc/dnx/dnx_data/auto_generated/dnx_data_nif.h>
#include <soc/dnx/swstate/auto_generated/access/dnx_port_nif_access.h>

/*
 * }
 */

#ifdef BSL_LOG_MODULE
#error "BSL_LOG_MODULE redefined"
#endif
#define BSL_LOG_MODULE BSL_LS_BCMDNX_PORT

shr_error_e
dnx_port_oft_init(
    int unit)
{
    SHR_FUNC_INIT_VARS(unit);

    
    SHR_IF_ERR_EXIT(dnx_port_oft_enable_dynamic_memories_set(unit, TRUE));

    /*
     * Initialize OFT link list
     */
    SHR_IF_ERR_EXIT(dnx_port_link_list_init(unit, DNX_PORT_NIF_OFT_LINK_LIST, dnx_data_nif.oft.nof_sections_get(unit)));

    /*
     * Initialize OFT calendars
     */
    SHR_IF_ERR_EXIT(dnx_port_calendar_init(unit, DNX_PORT_NIF_OFT_CALENDAR));

    /*
     * Taking hw scheduler out of reset
     */
    SHR_IF_ERR_EXIT(dnx_port_oft_scheduler_reset_set(unit, IMB_COMMON_OUT_OF_RESET));

    /*
     * Enable scheduler tdm counter
     */
    SHR_IF_ERR_EXIT(dnx_port_oft_scheduler_tdm_counter_enable_set(unit));

    /*
     * Stop frame preemtion
     */
    SHR_IF_ERR_EXIT(dnx_port_oft_frame_preemption_set(unit, TRUE));

exit:
    SHR_FUNC_EXIT;
}

shr_error_e
dnx_port_oft_power_down(
    int unit)
{
    SHR_FUNC_INIT_VARS(unit);
    SHR_IF_ERR_EXIT(dnx_port_oft_power_down_set(unit, TRUE));

exit:
    SHR_FUNC_EXIT;
}

shr_error_e
dnx_port_oft_port_add(
    int unit,
    bcm_port_t logical_port)
{
    SHR_FUNC_INIT_VARS(unit);

    /*
     * Nothing to do
     */
    SHR_FUNC_EXIT;
}

shr_error_e
dnx_port_oft_port_remove(
    int unit,
    bcm_port_t logical_port)
{
    SHR_FUNC_INIT_VARS(unit);

    /*
     * Rebuild OFT calendar
     */
    SHR_IF_ERR_EXIT(dnx_port_oft_calendar_set(unit));

exit:
    SHR_FUNC_EXIT;
}

shr_error_e
dnx_port_oft_link_list_set(
    int unit,
    bcm_port_t logical_port,
    int enable)
{
    int speed, nof_sections, core, oft_context;
    SHR_FUNC_INIT_VARS(unit);

    /*
     * Get Tx context
     */
    SHR_IF_ERR_EXIT(dnx_algo_port_nif_interface_id_get(unit, logical_port, 0, &core, &oft_context));

    if (enable)
    {
        /*
         * Get nof_sections from port's speed
         */
        SHR_IF_ERR_EXIT(dnx_algo_port_speed_get(unit, logical_port, DNX_ALGO_PORT_SPEED_F_TX, &speed));
        nof_sections = UTILEX_DIV_ROUND_UP(speed, dnx_data_nif.oft.port_speed_granularity_get(unit));

        /*
         * Allocate new link list
         */
        SHR_IF_ERR_EXIT(dnx_port_link_list_alloc(unit, DNX_PORT_NIF_OFT_LINK_LIST, nof_sections, oft_context));
    }
    else
    {
        /*
         * Free link list
         */
        SHR_IF_ERR_EXIT(dnx_port_link_list_free(unit, DNX_PORT_NIF_OFT_LINK_LIST, oft_context));
    }

exit:
    SHR_FUNC_EXIT;
}

shr_error_e
dnx_port_oft_calendar_set(
    int unit)
{
    SHR_FUNC_INIT_VARS(unit);

    /*
     * set Tx calendar 
     */
    SHR_IF_ERR_EXIT(dnx_port_calendar_set(unit, DNX_PORT_NIF_OFT_CALENDAR));

exit:
    SHR_FUNC_EXIT;
}

shr_error_e
dnx_port_nif_oft_tx_start_thr_set(
    int unit,
    bcm_port_t logical_port,
    int start_thr)
{

    SHR_FUNC_INIT_VARS(unit);

    SHR_IF_ERR_EXIT(dnx_port_nif_oft_tx_start_thr_hw_set(unit, logical_port, start_thr));

exit:
    SHR_FUNC_EXIT;
}

shr_error_e
dnx_port_oft_port_enable_set(
    int unit,
    bcm_port_t logical_port,
    int enable)
{
    int in_reset;
    SHR_FUNC_INIT_VARS(unit);

    in_reset = (enable) ? IMB_COMMON_OUT_OF_RESET : IMB_COMMON_IN_RESET;

    /*
     * Reset / taking out of OFT counters
     */
    SHR_IF_ERR_EXIT(dnx_port_oft_reset_counters_set(unit, logical_port, in_reset));

    /*
     * Reset / taking out of reset the port itself
     */
    SHR_IF_ERR_EXIT(dnx_port_oft_port_reset(unit, logical_port, in_reset));

    if (enable)
    {
        SHR_IF_ERR_EXIT(dnx_port_oft_destination_credits_bitmap_set(unit, logical_port));
    }

exit:
    SHR_FUNC_EXIT;
}
