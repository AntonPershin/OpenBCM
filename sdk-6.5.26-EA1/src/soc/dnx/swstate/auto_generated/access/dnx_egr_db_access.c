
/*
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2022 Broadcom Inc. All rights reserved.
 */

#ifdef BSL_LOG_MODULE
#error "BSL_LOG_MODULE redefined"
#endif
#define BSL_LOG_MODULE BSL_LS_SWSTATEDNX_GENERAL

#include <soc/dnx/swstate/auto_generated/access/dnx_egr_db_access.h>
#include <soc/dnx/swstate/auto_generated/diagnostic/dnx_egr_db_diagnostic.h>
#include <soc/dnx/swstate/auto_generated/layout/dnx_egr_db_layout.h>





int
dnx_egr_db_is_init(int unit, uint8 *is_init)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_DNX_EGR_DB,
        SW_STATE_FUNC_IS_INIT,
        DNXC_SW_STATE_NO_FLAGS);

    *is_init = (NULL != ((dnx_egr_db_t*)sw_state_roots_array[unit][DNX_EGR_DB_MODULE_ID]));
    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_IS_INIT_LOGGING,
        BSL_LS_SWSTATEDNX_ISINIT,
        DNX_SW_STATE_DNX_EGR_DB,
        ((dnx_egr_db_t*)sw_state_roots_array[unit][DNX_EGR_DB_MODULE_ID]),
        "dnx_egr_db[%d]",
        unit);

    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_egr_db_init(int unit)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_DNX_EGR_DB,
        SW_STATE_FUNC_INIT,
        DNXC_SW_STATE_NO_FLAGS);

    DNX_SW_STATE_MODULE_INIT(
        unit,
        DNX_SW_STATE_DNX_EGR_DB,
        DNXC_SW_STATE_IMPLEMENTATION_WB,
        dnx_egr_db_t,
        DNX_SW_STATE_DNX_EGR_DB_NOF_PARAMS,
        DNXC_SW_STATE_AUTO_GENERATED_ALLOCATION,
        "dnx_egr_db_init",
        DNX_SW_STATE_DIAG_ALLOC,
        dnx_egr_db_init_layout_structure);

    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_INIT_LOGGING,
        BSL_LS_SWSTATEDNX_INIT,
        DNX_SW_STATE_DNX_EGR_DB,
        ((dnx_egr_db_t*)sw_state_roots_array[unit][DNX_EGR_DB_MODULE_ID]),
        "dnx_egr_db[%d]",
        unit);

    DNX_SW_STATE_DIAG_INFO_POST(
        unit,
        DNX_SW_STATE_DNX_EGR_DB,
        dnx_egr_db_info,
        DNX_EGR_DB_INFO,
        DNX_SW_STATE_DIAG_ALLOC,
        ((dnx_egr_db_t*)sw_state_roots_array[unit][DNX_EGR_DB_MODULE_ID]));

    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_egr_db_ps_allocation_bmap_set(int unit, uint32 allocation_bmap_idx_0, uint32 allocation_bmap_idx_1, uint32 allocation_bmap)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_DNX_EGR_DB__PS__ALLOCATION_BMAP,
        SW_STATE_FUNC_SET,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_DNX_EGR_DB__PS__ALLOCATION_BMAP,
        sw_state_roots_array[unit][DNX_EGR_DB_MODULE_ID]);

    DNX_SW_STATE_OOB_STATIC_ARRAY_CHECK(
        allocation_bmap_idx_0,
        DNX_DATA_MAX_DEVICE_GENERAL_NOF_CORES);

    DNX_SW_STATE_OOB_STATIC_ARRAY_CHECK(
        allocation_bmap_idx_1,
        DNX_DATA_MAX_EGR_QUEUING_PARAMS_NOF_PORT_SCHEDULERS);

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_DNX_EGR_DB__PS__ALLOCATION_BMAP,
        DNX_SW_STATE_DIAG_MODIFY);

    DNX_SW_STATE_SET(
        unit,
        DNX_SW_STATE_DNX_EGR_DB__PS__ALLOCATION_BMAP,
        ((dnx_egr_db_t*)sw_state_roots_array[unit][DNX_EGR_DB_MODULE_ID])->ps.allocation_bmap[allocation_bmap_idx_0][allocation_bmap_idx_1],
        allocation_bmap,
        uint32,
        0,
        "dnx_egr_db_ps_allocation_bmap_set");

    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_SET_LOGGING,
        BSL_LS_SWSTATEDNX_SET,
        DNX_SW_STATE_DNX_EGR_DB__PS__ALLOCATION_BMAP,
        &allocation_bmap,
        "dnx_egr_db[%d]->ps.allocation_bmap[%d][%d]",
        unit, allocation_bmap_idx_0, allocation_bmap_idx_1);

    DNX_SW_STATE_DIAG_INFO_POST(
        unit,
        DNX_SW_STATE_DNX_EGR_DB__PS__ALLOCATION_BMAP,
        dnx_egr_db_info,
        DNX_EGR_DB_PS_ALLOCATION_BMAP_INFO,
        DNX_SW_STATE_DIAG_MODIFY,
        NULL);

    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_egr_db_ps_allocation_bmap_get(int unit, uint32 allocation_bmap_idx_0, uint32 allocation_bmap_idx_1, uint32 *allocation_bmap)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_DNX_EGR_DB__PS__ALLOCATION_BMAP,
        SW_STATE_FUNC_GET,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_DNX_EGR_DB__PS__ALLOCATION_BMAP,
        sw_state_roots_array[unit][DNX_EGR_DB_MODULE_ID]);

    DNX_SW_STATE_OOB_STATIC_ARRAY_CHECK(
        allocation_bmap_idx_0,
        DNX_DATA_MAX_DEVICE_GENERAL_NOF_CORES);

    DNX_SW_STATE_PTR_NULL_CHECK(
        unit,
        DNX_SW_STATE_DNX_EGR_DB__PS__ALLOCATION_BMAP,
        allocation_bmap);

    DNX_SW_STATE_OOB_STATIC_ARRAY_CHECK(
        allocation_bmap_idx_1,
        DNX_DATA_MAX_EGR_QUEUING_PARAMS_NOF_PORT_SCHEDULERS);

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_DNX_EGR_DB__PS__ALLOCATION_BMAP,
        DNX_SW_STATE_DIAG_READ);

    *allocation_bmap = ((dnx_egr_db_t*)sw_state_roots_array[unit][DNX_EGR_DB_MODULE_ID])->ps.allocation_bmap[allocation_bmap_idx_0][allocation_bmap_idx_1];
    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_GET_LOGGING,
        BSL_LS_SWSTATEDNX_GET,
        DNX_SW_STATE_DNX_EGR_DB__PS__ALLOCATION_BMAP,
        &((dnx_egr_db_t*)sw_state_roots_array[unit][DNX_EGR_DB_MODULE_ID])->ps.allocation_bmap[allocation_bmap_idx_0][allocation_bmap_idx_1],
        "dnx_egr_db[%d]->ps.allocation_bmap[%d][%d]",
        unit, allocation_bmap_idx_0, allocation_bmap_idx_1);

    DNX_SW_STATE_DIAG_INFO_POST(
        unit,
        DNX_SW_STATE_DNX_EGR_DB__PS__ALLOCATION_BMAP,
        dnx_egr_db_info,
        DNX_EGR_DB_PS_ALLOCATION_BMAP_INFO,
        DNX_SW_STATE_DIAG_READ,
        NULL);

    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_egr_db_ps_prio_mode_set(int unit, uint32 prio_mode_idx_0, uint32 prio_mode_idx_1, uint32 prio_mode)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_DNX_EGR_DB__PS__PRIO_MODE,
        SW_STATE_FUNC_SET,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_DNX_EGR_DB__PS__PRIO_MODE,
        sw_state_roots_array[unit][DNX_EGR_DB_MODULE_ID]);

    DNX_SW_STATE_OOB_STATIC_ARRAY_CHECK(
        prio_mode_idx_0,
        DNX_DATA_MAX_DEVICE_GENERAL_NOF_CORES);

    DNX_SW_STATE_OOB_STATIC_ARRAY_CHECK(
        prio_mode_idx_1,
        DNX_DATA_MAX_EGR_QUEUING_PARAMS_NOF_PORT_SCHEDULERS);

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_DNX_EGR_DB__PS__PRIO_MODE,
        DNX_SW_STATE_DIAG_MODIFY);

    DNX_SW_STATE_SET(
        unit,
        DNX_SW_STATE_DNX_EGR_DB__PS__PRIO_MODE,
        ((dnx_egr_db_t*)sw_state_roots_array[unit][DNX_EGR_DB_MODULE_ID])->ps.prio_mode[prio_mode_idx_0][prio_mode_idx_1],
        prio_mode,
        uint32,
        0,
        "dnx_egr_db_ps_prio_mode_set");

    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_SET_LOGGING,
        BSL_LS_SWSTATEDNX_SET,
        DNX_SW_STATE_DNX_EGR_DB__PS__PRIO_MODE,
        &prio_mode,
        "dnx_egr_db[%d]->ps.prio_mode[%d][%d]",
        unit, prio_mode_idx_0, prio_mode_idx_1);

    DNX_SW_STATE_DIAG_INFO_POST(
        unit,
        DNX_SW_STATE_DNX_EGR_DB__PS__PRIO_MODE,
        dnx_egr_db_info,
        DNX_EGR_DB_PS_PRIO_MODE_INFO,
        DNX_SW_STATE_DIAG_MODIFY,
        NULL);

    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_egr_db_ps_prio_mode_get(int unit, uint32 prio_mode_idx_0, uint32 prio_mode_idx_1, uint32 *prio_mode)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_DNX_EGR_DB__PS__PRIO_MODE,
        SW_STATE_FUNC_GET,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_DNX_EGR_DB__PS__PRIO_MODE,
        sw_state_roots_array[unit][DNX_EGR_DB_MODULE_ID]);

    DNX_SW_STATE_OOB_STATIC_ARRAY_CHECK(
        prio_mode_idx_0,
        DNX_DATA_MAX_DEVICE_GENERAL_NOF_CORES);

    DNX_SW_STATE_PTR_NULL_CHECK(
        unit,
        DNX_SW_STATE_DNX_EGR_DB__PS__PRIO_MODE,
        prio_mode);

    DNX_SW_STATE_OOB_STATIC_ARRAY_CHECK(
        prio_mode_idx_1,
        DNX_DATA_MAX_EGR_QUEUING_PARAMS_NOF_PORT_SCHEDULERS);

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_DNX_EGR_DB__PS__PRIO_MODE,
        DNX_SW_STATE_DIAG_READ);

    *prio_mode = ((dnx_egr_db_t*)sw_state_roots_array[unit][DNX_EGR_DB_MODULE_ID])->ps.prio_mode[prio_mode_idx_0][prio_mode_idx_1];
    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_GET_LOGGING,
        BSL_LS_SWSTATEDNX_GET,
        DNX_SW_STATE_DNX_EGR_DB__PS__PRIO_MODE,
        &((dnx_egr_db_t*)sw_state_roots_array[unit][DNX_EGR_DB_MODULE_ID])->ps.prio_mode[prio_mode_idx_0][prio_mode_idx_1],
        "dnx_egr_db[%d]->ps.prio_mode[%d][%d]",
        unit, prio_mode_idx_0, prio_mode_idx_1);

    DNX_SW_STATE_DIAG_INFO_POST(
        unit,
        DNX_SW_STATE_DNX_EGR_DB__PS__PRIO_MODE,
        dnx_egr_db_info,
        DNX_EGR_DB_PS_PRIO_MODE_INFO,
        DNX_SW_STATE_DIAG_READ,
        NULL);

    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_egr_db_ps_if_idx_set(int unit, uint32 if_idx_idx_0, uint32 if_idx_idx_1, int if_idx)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_DNX_EGR_DB__PS__IF_IDX,
        SW_STATE_FUNC_SET,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_DNX_EGR_DB__PS__IF_IDX,
        sw_state_roots_array[unit][DNX_EGR_DB_MODULE_ID]);

    DNX_SW_STATE_OOB_STATIC_ARRAY_CHECK(
        if_idx_idx_0,
        DNX_DATA_MAX_DEVICE_GENERAL_NOF_CORES);

    DNX_SW_STATE_OOB_STATIC_ARRAY_CHECK(
        if_idx_idx_1,
        DNX_DATA_MAX_EGR_QUEUING_PARAMS_NOF_PORT_SCHEDULERS);

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_DNX_EGR_DB__PS__IF_IDX,
        DNX_SW_STATE_DIAG_MODIFY);

    DNX_SW_STATE_SET(
        unit,
        DNX_SW_STATE_DNX_EGR_DB__PS__IF_IDX,
        ((dnx_egr_db_t*)sw_state_roots_array[unit][DNX_EGR_DB_MODULE_ID])->ps.if_idx[if_idx_idx_0][if_idx_idx_1],
        if_idx,
        int,
        0,
        "dnx_egr_db_ps_if_idx_set");

    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_SET_LOGGING,
        BSL_LS_SWSTATEDNX_SET,
        DNX_SW_STATE_DNX_EGR_DB__PS__IF_IDX,
        &if_idx,
        "dnx_egr_db[%d]->ps.if_idx[%d][%d]",
        unit, if_idx_idx_0, if_idx_idx_1);

    DNX_SW_STATE_DIAG_INFO_POST(
        unit,
        DNX_SW_STATE_DNX_EGR_DB__PS__IF_IDX,
        dnx_egr_db_info,
        DNX_EGR_DB_PS_IF_IDX_INFO,
        DNX_SW_STATE_DIAG_MODIFY,
        NULL);

    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_egr_db_ps_if_idx_get(int unit, uint32 if_idx_idx_0, uint32 if_idx_idx_1, int *if_idx)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_DNX_EGR_DB__PS__IF_IDX,
        SW_STATE_FUNC_GET,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_DNX_EGR_DB__PS__IF_IDX,
        sw_state_roots_array[unit][DNX_EGR_DB_MODULE_ID]);

    DNX_SW_STATE_OOB_STATIC_ARRAY_CHECK(
        if_idx_idx_0,
        DNX_DATA_MAX_DEVICE_GENERAL_NOF_CORES);

    DNX_SW_STATE_PTR_NULL_CHECK(
        unit,
        DNX_SW_STATE_DNX_EGR_DB__PS__IF_IDX,
        if_idx);

    DNX_SW_STATE_OOB_STATIC_ARRAY_CHECK(
        if_idx_idx_1,
        DNX_DATA_MAX_EGR_QUEUING_PARAMS_NOF_PORT_SCHEDULERS);

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_DNX_EGR_DB__PS__IF_IDX,
        DNX_SW_STATE_DIAG_READ);

    *if_idx = ((dnx_egr_db_t*)sw_state_roots_array[unit][DNX_EGR_DB_MODULE_ID])->ps.if_idx[if_idx_idx_0][if_idx_idx_1];
    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_GET_LOGGING,
        BSL_LS_SWSTATEDNX_GET,
        DNX_SW_STATE_DNX_EGR_DB__PS__IF_IDX,
        &((dnx_egr_db_t*)sw_state_roots_array[unit][DNX_EGR_DB_MODULE_ID])->ps.if_idx[if_idx_idx_0][if_idx_idx_1],
        "dnx_egr_db[%d]->ps.if_idx[%d][%d]",
        unit, if_idx_idx_0, if_idx_idx_1);

    DNX_SW_STATE_DIAG_INFO_POST(
        unit,
        DNX_SW_STATE_DNX_EGR_DB__PS__IF_IDX,
        dnx_egr_db_info,
        DNX_EGR_DB_PS_IF_IDX_INFO,
        DNX_SW_STATE_DIAG_READ,
        NULL);

    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_egr_db_interface_occ_set(int unit, uint32 interface_occ_idx_0, uint32 interface_occ_idx_1, int interface_occ)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_DNX_EGR_DB__INTERFACE_OCC,
        SW_STATE_FUNC_SET,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_DNX_EGR_DB__INTERFACE_OCC,
        sw_state_roots_array[unit][DNX_EGR_DB_MODULE_ID]);

    DNX_SW_STATE_OOB_STATIC_ARRAY_CHECK(
        interface_occ_idx_0,
        DNX_DATA_MAX_DEVICE_GENERAL_NOF_CORES);

    DNX_SW_STATE_OOB_STATIC_ARRAY_CHECK(
        interface_occ_idx_1,
        DNX_DATA_MAX_EGR_QUEUING_PARAMS_NOF_EGR_INTERFACES);

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_DNX_EGR_DB__INTERFACE_OCC,
        DNX_SW_STATE_DIAG_MODIFY);

    DNX_SW_STATE_SET(
        unit,
        DNX_SW_STATE_DNX_EGR_DB__INTERFACE_OCC,
        ((dnx_egr_db_t*)sw_state_roots_array[unit][DNX_EGR_DB_MODULE_ID])->interface_occ[interface_occ_idx_0][interface_occ_idx_1],
        interface_occ,
        int,
        0,
        "dnx_egr_db_interface_occ_set");

    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_SET_LOGGING,
        BSL_LS_SWSTATEDNX_SET,
        DNX_SW_STATE_DNX_EGR_DB__INTERFACE_OCC,
        &interface_occ,
        "dnx_egr_db[%d]->interface_occ[%d][%d]",
        unit, interface_occ_idx_0, interface_occ_idx_1);

    DNX_SW_STATE_DIAG_INFO_POST(
        unit,
        DNX_SW_STATE_DNX_EGR_DB__INTERFACE_OCC,
        dnx_egr_db_info,
        DNX_EGR_DB_INTERFACE_OCC_INFO,
        DNX_SW_STATE_DIAG_MODIFY,
        NULL);

    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_egr_db_interface_occ_get(int unit, uint32 interface_occ_idx_0, uint32 interface_occ_idx_1, int *interface_occ)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_DNX_EGR_DB__INTERFACE_OCC,
        SW_STATE_FUNC_GET,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_DNX_EGR_DB__INTERFACE_OCC,
        sw_state_roots_array[unit][DNX_EGR_DB_MODULE_ID]);

    DNX_SW_STATE_OOB_STATIC_ARRAY_CHECK(
        interface_occ_idx_0,
        DNX_DATA_MAX_DEVICE_GENERAL_NOF_CORES);

    DNX_SW_STATE_PTR_NULL_CHECK(
        unit,
        DNX_SW_STATE_DNX_EGR_DB__INTERFACE_OCC,
        interface_occ);

    DNX_SW_STATE_OOB_STATIC_ARRAY_CHECK(
        interface_occ_idx_1,
        DNX_DATA_MAX_EGR_QUEUING_PARAMS_NOF_EGR_INTERFACES);

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_DNX_EGR_DB__INTERFACE_OCC,
        DNX_SW_STATE_DIAG_READ);

    *interface_occ = ((dnx_egr_db_t*)sw_state_roots_array[unit][DNX_EGR_DB_MODULE_ID])->interface_occ[interface_occ_idx_0][interface_occ_idx_1];
    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_GET_LOGGING,
        BSL_LS_SWSTATEDNX_GET,
        DNX_SW_STATE_DNX_EGR_DB__INTERFACE_OCC,
        &((dnx_egr_db_t*)sw_state_roots_array[unit][DNX_EGR_DB_MODULE_ID])->interface_occ[interface_occ_idx_0][interface_occ_idx_1],
        "dnx_egr_db[%d]->interface_occ[%d][%d]",
        unit, interface_occ_idx_0, interface_occ_idx_1);

    DNX_SW_STATE_DIAG_INFO_POST(
        unit,
        DNX_SW_STATE_DNX_EGR_DB__INTERFACE_OCC,
        dnx_egr_db_info,
        DNX_EGR_DB_INTERFACE_OCC_INFO,
        DNX_SW_STATE_DIAG_READ,
        NULL);

    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_egr_db_total_egr_if_credits_set(int unit, uint32 total_egr_if_credits_idx_0, int total_egr_if_credits)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_DNX_EGR_DB__TOTAL_EGR_IF_CREDITS,
        SW_STATE_FUNC_SET,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_DNX_EGR_DB__TOTAL_EGR_IF_CREDITS,
        sw_state_roots_array[unit][DNX_EGR_DB_MODULE_ID]);

    DNX_SW_STATE_OOB_STATIC_ARRAY_CHECK(
        total_egr_if_credits_idx_0,
        DNX_DATA_MAX_DEVICE_GENERAL_NOF_CORES);

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_DNX_EGR_DB__TOTAL_EGR_IF_CREDITS,
        DNX_SW_STATE_DIAG_MODIFY);

    DNX_SW_STATE_SET(
        unit,
        DNX_SW_STATE_DNX_EGR_DB__TOTAL_EGR_IF_CREDITS,
        ((dnx_egr_db_t*)sw_state_roots_array[unit][DNX_EGR_DB_MODULE_ID])->total_egr_if_credits[total_egr_if_credits_idx_0],
        total_egr_if_credits,
        int,
        0,
        "dnx_egr_db_total_egr_if_credits_set");

    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_SET_LOGGING,
        BSL_LS_SWSTATEDNX_SET,
        DNX_SW_STATE_DNX_EGR_DB__TOTAL_EGR_IF_CREDITS,
        &total_egr_if_credits,
        "dnx_egr_db[%d]->total_egr_if_credits[%d]",
        unit, total_egr_if_credits_idx_0);

    DNX_SW_STATE_DIAG_INFO_POST(
        unit,
        DNX_SW_STATE_DNX_EGR_DB__TOTAL_EGR_IF_CREDITS,
        dnx_egr_db_info,
        DNX_EGR_DB_TOTAL_EGR_IF_CREDITS_INFO,
        DNX_SW_STATE_DIAG_MODIFY,
        NULL);

    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_egr_db_total_egr_if_credits_get(int unit, uint32 total_egr_if_credits_idx_0, int *total_egr_if_credits)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_DNX_EGR_DB__TOTAL_EGR_IF_CREDITS,
        SW_STATE_FUNC_GET,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_DNX_EGR_DB__TOTAL_EGR_IF_CREDITS,
        sw_state_roots_array[unit][DNX_EGR_DB_MODULE_ID]);

    DNX_SW_STATE_OOB_STATIC_ARRAY_CHECK(
        total_egr_if_credits_idx_0,
        DNX_DATA_MAX_DEVICE_GENERAL_NOF_CORES);

    DNX_SW_STATE_PTR_NULL_CHECK(
        unit,
        DNX_SW_STATE_DNX_EGR_DB__TOTAL_EGR_IF_CREDITS,
        total_egr_if_credits);

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_DNX_EGR_DB__TOTAL_EGR_IF_CREDITS,
        DNX_SW_STATE_DIAG_READ);

    *total_egr_if_credits = ((dnx_egr_db_t*)sw_state_roots_array[unit][DNX_EGR_DB_MODULE_ID])->total_egr_if_credits[total_egr_if_credits_idx_0];
    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_GET_LOGGING,
        BSL_LS_SWSTATEDNX_GET,
        DNX_SW_STATE_DNX_EGR_DB__TOTAL_EGR_IF_CREDITS,
        &((dnx_egr_db_t*)sw_state_roots_array[unit][DNX_EGR_DB_MODULE_ID])->total_egr_if_credits[total_egr_if_credits_idx_0],
        "dnx_egr_db[%d]->total_egr_if_credits[%d]",
        unit, total_egr_if_credits_idx_0);

    DNX_SW_STATE_DIAG_INFO_POST(
        unit,
        DNX_SW_STATE_DNX_EGR_DB__TOTAL_EGR_IF_CREDITS,
        dnx_egr_db_info,
        DNX_EGR_DB_TOTAL_EGR_IF_CREDITS_INFO,
        DNX_SW_STATE_DIAG_READ,
        NULL);

    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_egr_db_egr_if_credits_configured_set(int unit, uint32 egr_if_credits_configured_idx_0, uint32 egr_if_credits_configured_idx_1, uint8 egr_if_credits_configured)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_DNX_EGR_DB__EGR_IF_CREDITS_CONFIGURED,
        SW_STATE_FUNC_SET,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_DNX_EGR_DB__EGR_IF_CREDITS_CONFIGURED,
        sw_state_roots_array[unit][DNX_EGR_DB_MODULE_ID]);

    DNX_SW_STATE_OOB_STATIC_ARRAY_CHECK(
        egr_if_credits_configured_idx_0,
        DNX_DATA_MAX_DEVICE_GENERAL_NOF_CORES);

    DNX_SW_STATE_OOB_STATIC_ARRAY_CHECK(
        egr_if_credits_configured_idx_1,
        DNX_DATA_MAX_EGR_QUEUING_PARAMS_NOF_EGR_INTERFACES);

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_DNX_EGR_DB__EGR_IF_CREDITS_CONFIGURED,
        DNX_SW_STATE_DIAG_MODIFY);

    DNX_SW_STATE_SET(
        unit,
        DNX_SW_STATE_DNX_EGR_DB__EGR_IF_CREDITS_CONFIGURED,
        ((dnx_egr_db_t*)sw_state_roots_array[unit][DNX_EGR_DB_MODULE_ID])->egr_if_credits_configured[egr_if_credits_configured_idx_0][egr_if_credits_configured_idx_1],
        egr_if_credits_configured,
        uint8,
        0,
        "dnx_egr_db_egr_if_credits_configured_set");

    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_SET_LOGGING,
        BSL_LS_SWSTATEDNX_SET,
        DNX_SW_STATE_DNX_EGR_DB__EGR_IF_CREDITS_CONFIGURED,
        &egr_if_credits_configured,
        "dnx_egr_db[%d]->egr_if_credits_configured[%d][%d]",
        unit, egr_if_credits_configured_idx_0, egr_if_credits_configured_idx_1);

    DNX_SW_STATE_DIAG_INFO_POST(
        unit,
        DNX_SW_STATE_DNX_EGR_DB__EGR_IF_CREDITS_CONFIGURED,
        dnx_egr_db_info,
        DNX_EGR_DB_EGR_IF_CREDITS_CONFIGURED_INFO,
        DNX_SW_STATE_DIAG_MODIFY,
        NULL);

    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_egr_db_egr_if_credits_configured_get(int unit, uint32 egr_if_credits_configured_idx_0, uint32 egr_if_credits_configured_idx_1, uint8 *egr_if_credits_configured)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_DNX_EGR_DB__EGR_IF_CREDITS_CONFIGURED,
        SW_STATE_FUNC_GET,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_DNX_EGR_DB__EGR_IF_CREDITS_CONFIGURED,
        sw_state_roots_array[unit][DNX_EGR_DB_MODULE_ID]);

    DNX_SW_STATE_OOB_STATIC_ARRAY_CHECK(
        egr_if_credits_configured_idx_0,
        DNX_DATA_MAX_DEVICE_GENERAL_NOF_CORES);

    DNX_SW_STATE_PTR_NULL_CHECK(
        unit,
        DNX_SW_STATE_DNX_EGR_DB__EGR_IF_CREDITS_CONFIGURED,
        egr_if_credits_configured);

    DNX_SW_STATE_OOB_STATIC_ARRAY_CHECK(
        egr_if_credits_configured_idx_1,
        DNX_DATA_MAX_EGR_QUEUING_PARAMS_NOF_EGR_INTERFACES);

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_DNX_EGR_DB__EGR_IF_CREDITS_CONFIGURED,
        DNX_SW_STATE_DIAG_READ);

    *egr_if_credits_configured = ((dnx_egr_db_t*)sw_state_roots_array[unit][DNX_EGR_DB_MODULE_ID])->egr_if_credits_configured[egr_if_credits_configured_idx_0][egr_if_credits_configured_idx_1];
    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_GET_LOGGING,
        BSL_LS_SWSTATEDNX_GET,
        DNX_SW_STATE_DNX_EGR_DB__EGR_IF_CREDITS_CONFIGURED,
        &((dnx_egr_db_t*)sw_state_roots_array[unit][DNX_EGR_DB_MODULE_ID])->egr_if_credits_configured[egr_if_credits_configured_idx_0][egr_if_credits_configured_idx_1],
        "dnx_egr_db[%d]->egr_if_credits_configured[%d][%d]",
        unit, egr_if_credits_configured_idx_0, egr_if_credits_configured_idx_1);

    DNX_SW_STATE_DIAG_INFO_POST(
        unit,
        DNX_SW_STATE_DNX_EGR_DB__EGR_IF_CREDITS_CONFIGURED,
        dnx_egr_db_info,
        DNX_EGR_DB_EGR_IF_CREDITS_CONFIGURED_INFO,
        DNX_SW_STATE_DIAG_READ,
        NULL);

    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_egr_db_total_esb_queues_allocated_set(int unit, uint32 total_esb_queues_allocated_idx_0, int total_esb_queues_allocated)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_DNX_EGR_DB__TOTAL_ESB_QUEUES_ALLOCATED,
        SW_STATE_FUNC_SET,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_DNX_EGR_DB__TOTAL_ESB_QUEUES_ALLOCATED,
        sw_state_roots_array[unit][DNX_EGR_DB_MODULE_ID]);

    DNX_SW_STATE_OOB_STATIC_ARRAY_CHECK(
        total_esb_queues_allocated_idx_0,
        DNX_DATA_MAX_DEVICE_GENERAL_NOF_CORES);

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_DNX_EGR_DB__TOTAL_ESB_QUEUES_ALLOCATED,
        DNX_SW_STATE_DIAG_MODIFY);

    DNX_SW_STATE_SET(
        unit,
        DNX_SW_STATE_DNX_EGR_DB__TOTAL_ESB_QUEUES_ALLOCATED,
        ((dnx_egr_db_t*)sw_state_roots_array[unit][DNX_EGR_DB_MODULE_ID])->total_esb_queues_allocated[total_esb_queues_allocated_idx_0],
        total_esb_queues_allocated,
        int,
        0,
        "dnx_egr_db_total_esb_queues_allocated_set");

    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_SET_LOGGING,
        BSL_LS_SWSTATEDNX_SET,
        DNX_SW_STATE_DNX_EGR_DB__TOTAL_ESB_QUEUES_ALLOCATED,
        &total_esb_queues_allocated,
        "dnx_egr_db[%d]->total_esb_queues_allocated[%d]",
        unit, total_esb_queues_allocated_idx_0);

    DNX_SW_STATE_DIAG_INFO_POST(
        unit,
        DNX_SW_STATE_DNX_EGR_DB__TOTAL_ESB_QUEUES_ALLOCATED,
        dnx_egr_db_info,
        DNX_EGR_DB_TOTAL_ESB_QUEUES_ALLOCATED_INFO,
        DNX_SW_STATE_DIAG_MODIFY,
        NULL);

    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_egr_db_total_esb_queues_allocated_get(int unit, uint32 total_esb_queues_allocated_idx_0, int *total_esb_queues_allocated)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_DNX_EGR_DB__TOTAL_ESB_QUEUES_ALLOCATED,
        SW_STATE_FUNC_GET,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_DNX_EGR_DB__TOTAL_ESB_QUEUES_ALLOCATED,
        sw_state_roots_array[unit][DNX_EGR_DB_MODULE_ID]);

    DNX_SW_STATE_OOB_STATIC_ARRAY_CHECK(
        total_esb_queues_allocated_idx_0,
        DNX_DATA_MAX_DEVICE_GENERAL_NOF_CORES);

    DNX_SW_STATE_PTR_NULL_CHECK(
        unit,
        DNX_SW_STATE_DNX_EGR_DB__TOTAL_ESB_QUEUES_ALLOCATED,
        total_esb_queues_allocated);

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_DNX_EGR_DB__TOTAL_ESB_QUEUES_ALLOCATED,
        DNX_SW_STATE_DIAG_READ);

    *total_esb_queues_allocated = ((dnx_egr_db_t*)sw_state_roots_array[unit][DNX_EGR_DB_MODULE_ID])->total_esb_queues_allocated[total_esb_queues_allocated_idx_0];
    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_GET_LOGGING,
        BSL_LS_SWSTATEDNX_GET,
        DNX_SW_STATE_DNX_EGR_DB__TOTAL_ESB_QUEUES_ALLOCATED,
        &((dnx_egr_db_t*)sw_state_roots_array[unit][DNX_EGR_DB_MODULE_ID])->total_esb_queues_allocated[total_esb_queues_allocated_idx_0],
        "dnx_egr_db[%d]->total_esb_queues_allocated[%d]",
        unit, total_esb_queues_allocated_idx_0);

    DNX_SW_STATE_DIAG_INFO_POST(
        unit,
        DNX_SW_STATE_DNX_EGR_DB__TOTAL_ESB_QUEUES_ALLOCATED,
        dnx_egr_db_info,
        DNX_EGR_DB_TOTAL_ESB_QUEUES_ALLOCATED_INFO,
        DNX_SW_STATE_DIAG_READ,
        NULL);

    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_egr_db_nof_negative_compensation_ports_set(int unit, uint32 nof_negative_compensation_ports_idx_0, int nof_negative_compensation_ports)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_DNX_EGR_DB__NOF_NEGATIVE_COMPENSATION_PORTS,
        SW_STATE_FUNC_SET,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_DNX_EGR_DB__NOF_NEGATIVE_COMPENSATION_PORTS,
        sw_state_roots_array[unit][DNX_EGR_DB_MODULE_ID]);

    DNX_SW_STATE_OOB_STATIC_ARRAY_CHECK(
        nof_negative_compensation_ports_idx_0,
        DNX_DATA_MAX_DEVICE_GENERAL_NOF_CORES);

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_DNX_EGR_DB__NOF_NEGATIVE_COMPENSATION_PORTS,
        DNX_SW_STATE_DIAG_MODIFY);

    DNX_SW_STATE_SET(
        unit,
        DNX_SW_STATE_DNX_EGR_DB__NOF_NEGATIVE_COMPENSATION_PORTS,
        ((dnx_egr_db_t*)sw_state_roots_array[unit][DNX_EGR_DB_MODULE_ID])->nof_negative_compensation_ports[nof_negative_compensation_ports_idx_0],
        nof_negative_compensation_ports,
        int,
        0,
        "dnx_egr_db_nof_negative_compensation_ports_set");

    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_SET_LOGGING,
        BSL_LS_SWSTATEDNX_SET,
        DNX_SW_STATE_DNX_EGR_DB__NOF_NEGATIVE_COMPENSATION_PORTS,
        &nof_negative_compensation_ports,
        "dnx_egr_db[%d]->nof_negative_compensation_ports[%d]",
        unit, nof_negative_compensation_ports_idx_0);

    DNX_SW_STATE_DIAG_INFO_POST(
        unit,
        DNX_SW_STATE_DNX_EGR_DB__NOF_NEGATIVE_COMPENSATION_PORTS,
        dnx_egr_db_info,
        DNX_EGR_DB_NOF_NEGATIVE_COMPENSATION_PORTS_INFO,
        DNX_SW_STATE_DIAG_MODIFY,
        NULL);

    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_egr_db_nof_negative_compensation_ports_get(int unit, uint32 nof_negative_compensation_ports_idx_0, int *nof_negative_compensation_ports)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_DNX_EGR_DB__NOF_NEGATIVE_COMPENSATION_PORTS,
        SW_STATE_FUNC_GET,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_DNX_EGR_DB__NOF_NEGATIVE_COMPENSATION_PORTS,
        sw_state_roots_array[unit][DNX_EGR_DB_MODULE_ID]);

    DNX_SW_STATE_OOB_STATIC_ARRAY_CHECK(
        nof_negative_compensation_ports_idx_0,
        DNX_DATA_MAX_DEVICE_GENERAL_NOF_CORES);

    DNX_SW_STATE_PTR_NULL_CHECK(
        unit,
        DNX_SW_STATE_DNX_EGR_DB__NOF_NEGATIVE_COMPENSATION_PORTS,
        nof_negative_compensation_ports);

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_DNX_EGR_DB__NOF_NEGATIVE_COMPENSATION_PORTS,
        DNX_SW_STATE_DIAG_READ);

    *nof_negative_compensation_ports = ((dnx_egr_db_t*)sw_state_roots_array[unit][DNX_EGR_DB_MODULE_ID])->nof_negative_compensation_ports[nof_negative_compensation_ports_idx_0];
    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_GET_LOGGING,
        BSL_LS_SWSTATEDNX_GET,
        DNX_SW_STATE_DNX_EGR_DB__NOF_NEGATIVE_COMPENSATION_PORTS,
        &((dnx_egr_db_t*)sw_state_roots_array[unit][DNX_EGR_DB_MODULE_ID])->nof_negative_compensation_ports[nof_negative_compensation_ports_idx_0],
        "dnx_egr_db[%d]->nof_negative_compensation_ports[%d]",
        unit, nof_negative_compensation_ports_idx_0);

    DNX_SW_STATE_DIAG_INFO_POST(
        unit,
        DNX_SW_STATE_DNX_EGR_DB__NOF_NEGATIVE_COMPENSATION_PORTS,
        dnx_egr_db_info,
        DNX_EGR_DB_NOF_NEGATIVE_COMPENSATION_PORTS_INFO,
        DNX_SW_STATE_DIAG_READ,
        NULL);

    DNXC_SW_STATE_FUNC_RETURN;
}





dnx_egr_db_cbs dnx_egr_db = 	{
	
	dnx_egr_db_is_init,
	dnx_egr_db_init,
		{
		
			{
			
			dnx_egr_db_ps_allocation_bmap_set,
			dnx_egr_db_ps_allocation_bmap_get}
		,
			{
			
			dnx_egr_db_ps_prio_mode_set,
			dnx_egr_db_ps_prio_mode_get}
		,
			{
			
			dnx_egr_db_ps_if_idx_set,
			dnx_egr_db_ps_if_idx_get}
		}
	,
		{
		
		dnx_egr_db_interface_occ_set,
		dnx_egr_db_interface_occ_get}
	,
		{
		
		dnx_egr_db_total_egr_if_credits_set,
		dnx_egr_db_total_egr_if_credits_get}
	,
		{
		
		dnx_egr_db_egr_if_credits_configured_set,
		dnx_egr_db_egr_if_credits_configured_get}
	,
		{
		
		dnx_egr_db_total_esb_queues_allocated_set,
		dnx_egr_db_total_esb_queues_allocated_get}
	,
		{
		
		dnx_egr_db_nof_negative_compensation_ports_set,
		dnx_egr_db_nof_negative_compensation_ports_get}
	}
;
#undef BSL_LOG_MODULE
