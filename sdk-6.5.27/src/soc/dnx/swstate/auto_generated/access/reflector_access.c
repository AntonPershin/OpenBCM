
/*
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2022 Broadcom Inc. All rights reserved.
 */

#ifdef BSL_LOG_MODULE
#error "BSL_LOG_MODULE redefined"
#endif
#define BSL_LOG_MODULE BSL_LS_SWSTATEDNX_GENERAL

#include <soc/dnx/swstate/auto_generated/access/reflector_access.h>
#include <soc/dnx/swstate/auto_generated/diagnostic/reflector_diagnostic.h>
#include <soc/dnx/swstate/auto_generated/layout/reflector_layout.h>





int
reflector_sw_db_info_is_init(int unit, uint8 *is_init)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_REFLECTOR_SW_DB_INFO,
        SW_STATE_FUNC_IS_INIT,
        DNXC_SW_STATE_NO_FLAGS);

    *is_init = (NULL != ((reflector_sw_db_info_t*)sw_state_roots_array[unit][REFLECTOR_MODULE_ID]));
    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_IS_INIT_LOGGING,
        BSL_LS_SWSTATEDNX_ISINIT,
        DNX_SW_STATE_REFLECTOR_SW_DB_INFO,
        ((reflector_sw_db_info_t*)sw_state_roots_array[unit][REFLECTOR_MODULE_ID]),
        "reflector_sw_db_info[%d]",
        unit);

    DNXC_SW_STATE_FUNC_RETURN;
}



int
reflector_sw_db_info_init(int unit)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_REFLECTOR_SW_DB_INFO,
        SW_STATE_FUNC_INIT,
        DNXC_SW_STATE_NO_FLAGS);

    DNX_SW_STATE_MODULE_INIT(
        unit,
        DNX_SW_STATE_REFLECTOR_SW_DB_INFO,
        DNXC_SW_STATE_IMPLEMENTATION_WB,
        reflector_sw_db_info_t,
        DNX_SW_STATE_REFLECTOR_SW_DB_INFO_NOF_PARAMS,
        DNXC_SW_STATE_AUTO_GENERATED_ALLOCATION,
        "reflector_sw_db_info_init",
        DNX_SW_STATE_DIAG_ALLOC,
        reflector_init_layout_structure);

    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_INIT_LOGGING,
        BSL_LS_SWSTATEDNX_INIT,
        DNX_SW_STATE_REFLECTOR_SW_DB_INFO,
        ((reflector_sw_db_info_t*)sw_state_roots_array[unit][REFLECTOR_MODULE_ID]),
        "reflector_sw_db_info[%d]",
        unit);

    DNX_SW_STATE_DIAG_INFO_POST(
        unit,
        DNX_SW_STATE_REFLECTOR_SW_DB_INFO,
        reflector_sw_db_info_info,
        REFLECTOR_SW_DB_INFO_INFO,
        DNX_SW_STATE_DIAG_ALLOC,
        ((reflector_sw_db_info_t*)sw_state_roots_array[unit][REFLECTOR_MODULE_ID]),
        sw_state_layout_array[unit][REFLECTOR_MODULE_ID]);

    DNXC_SW_STATE_FUNC_RETURN;
}



int
reflector_sw_db_info_uc_encap_id_set(int unit, int encap_id)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_REFLECTOR_SW_DB_INFO__UC__ENCAP_ID,
        SW_STATE_FUNC_SET,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_REFLECTOR_SW_DB_INFO__UC__ENCAP_ID,
        sw_state_roots_array[unit][REFLECTOR_MODULE_ID]);

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_REFLECTOR_SW_DB_INFO__UC__ENCAP_ID,
        DNX_SW_STATE_DIAG_MODIFY);

    DNX_SW_STATE_SET(
        unit,
        DNX_SW_STATE_REFLECTOR_SW_DB_INFO__UC__ENCAP_ID,
        ((reflector_sw_db_info_t*)sw_state_roots_array[unit][REFLECTOR_MODULE_ID])->uc.encap_id,
        encap_id,
        int,
        0,
        "reflector_sw_db_info_uc_encap_id_set");

    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_SET_LOGGING,
        BSL_LS_SWSTATEDNX_SET,
        DNX_SW_STATE_REFLECTOR_SW_DB_INFO__UC__ENCAP_ID,
        &encap_id,
        "reflector_sw_db_info[%d]->uc.encap_id",
        unit);

    DNX_SW_STATE_DIAG_INFO_POST(
        unit,
        DNX_SW_STATE_REFLECTOR_SW_DB_INFO__UC__ENCAP_ID,
        reflector_sw_db_info_info,
        REFLECTOR_SW_DB_INFO_UC_ENCAP_ID_INFO,
        DNX_SW_STATE_DIAG_MODIFY,
        NULL,
        sw_state_layout_array[unit][REFLECTOR_MODULE_ID]);

    DNXC_SW_STATE_FUNC_RETURN;
}



int
reflector_sw_db_info_uc_encap_id_get(int unit, int *encap_id)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_REFLECTOR_SW_DB_INFO__UC__ENCAP_ID,
        SW_STATE_FUNC_GET,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_REFLECTOR_SW_DB_INFO__UC__ENCAP_ID,
        sw_state_roots_array[unit][REFLECTOR_MODULE_ID]);

    DNX_SW_STATE_PTR_NULL_CHECK(
        unit,
        DNX_SW_STATE_REFLECTOR_SW_DB_INFO__UC__ENCAP_ID,
        encap_id);

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_REFLECTOR_SW_DB_INFO__UC__ENCAP_ID,
        DNX_SW_STATE_DIAG_READ);

    *encap_id = ((reflector_sw_db_info_t*)sw_state_roots_array[unit][REFLECTOR_MODULE_ID])->uc.encap_id;
    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_GET_LOGGING,
        BSL_LS_SWSTATEDNX_GET,
        DNX_SW_STATE_REFLECTOR_SW_DB_INFO__UC__ENCAP_ID,
        &((reflector_sw_db_info_t*)sw_state_roots_array[unit][REFLECTOR_MODULE_ID])->uc.encap_id,
        "reflector_sw_db_info[%d]->uc.encap_id",
        unit);

    DNX_SW_STATE_DIAG_INFO_POST(
        unit,
        DNX_SW_STATE_REFLECTOR_SW_DB_INFO__UC__ENCAP_ID,
        reflector_sw_db_info_info,
        REFLECTOR_SW_DB_INFO_UC_ENCAP_ID_INFO,
        DNX_SW_STATE_DIAG_READ,
        NULL,
        sw_state_layout_array[unit][REFLECTOR_MODULE_ID]);

    DNXC_SW_STATE_FUNC_RETURN;
}



int
reflector_sw_db_info_uc_is_allocated_set(int unit, int is_allocated)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_REFLECTOR_SW_DB_INFO__UC__IS_ALLOCATED,
        SW_STATE_FUNC_SET,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_REFLECTOR_SW_DB_INFO__UC__IS_ALLOCATED,
        sw_state_roots_array[unit][REFLECTOR_MODULE_ID]);

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_REFLECTOR_SW_DB_INFO__UC__IS_ALLOCATED,
        DNX_SW_STATE_DIAG_MODIFY);

    DNX_SW_STATE_SET(
        unit,
        DNX_SW_STATE_REFLECTOR_SW_DB_INFO__UC__IS_ALLOCATED,
        ((reflector_sw_db_info_t*)sw_state_roots_array[unit][REFLECTOR_MODULE_ID])->uc.is_allocated,
        is_allocated,
        int,
        0,
        "reflector_sw_db_info_uc_is_allocated_set");

    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_SET_LOGGING,
        BSL_LS_SWSTATEDNX_SET,
        DNX_SW_STATE_REFLECTOR_SW_DB_INFO__UC__IS_ALLOCATED,
        &is_allocated,
        "reflector_sw_db_info[%d]->uc.is_allocated",
        unit);

    DNX_SW_STATE_DIAG_INFO_POST(
        unit,
        DNX_SW_STATE_REFLECTOR_SW_DB_INFO__UC__IS_ALLOCATED,
        reflector_sw_db_info_info,
        REFLECTOR_SW_DB_INFO_UC_IS_ALLOCATED_INFO,
        DNX_SW_STATE_DIAG_MODIFY,
        NULL,
        sw_state_layout_array[unit][REFLECTOR_MODULE_ID]);

    DNXC_SW_STATE_FUNC_RETURN;
}



int
reflector_sw_db_info_uc_is_allocated_get(int unit, int *is_allocated)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_REFLECTOR_SW_DB_INFO__UC__IS_ALLOCATED,
        SW_STATE_FUNC_GET,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_REFLECTOR_SW_DB_INFO__UC__IS_ALLOCATED,
        sw_state_roots_array[unit][REFLECTOR_MODULE_ID]);

    DNX_SW_STATE_PTR_NULL_CHECK(
        unit,
        DNX_SW_STATE_REFLECTOR_SW_DB_INFO__UC__IS_ALLOCATED,
        is_allocated);

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_REFLECTOR_SW_DB_INFO__UC__IS_ALLOCATED,
        DNX_SW_STATE_DIAG_READ);

    *is_allocated = ((reflector_sw_db_info_t*)sw_state_roots_array[unit][REFLECTOR_MODULE_ID])->uc.is_allocated;
    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_GET_LOGGING,
        BSL_LS_SWSTATEDNX_GET,
        DNX_SW_STATE_REFLECTOR_SW_DB_INFO__UC__IS_ALLOCATED,
        &((reflector_sw_db_info_t*)sw_state_roots_array[unit][REFLECTOR_MODULE_ID])->uc.is_allocated,
        "reflector_sw_db_info[%d]->uc.is_allocated",
        unit);

    DNX_SW_STATE_DIAG_INFO_POST(
        unit,
        DNX_SW_STATE_REFLECTOR_SW_DB_INFO__UC__IS_ALLOCATED,
        reflector_sw_db_info_info,
        REFLECTOR_SW_DB_INFO_UC_IS_ALLOCATED_INFO,
        DNX_SW_STATE_DIAG_READ,
        NULL,
        sw_state_layout_array[unit][REFLECTOR_MODULE_ID]);

    DNXC_SW_STATE_FUNC_RETURN;
}



int
reflector_sw_db_info_uc_l2_int_encap_id_set(int unit, int encap_id)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_REFLECTOR_SW_DB_INFO__UC_L2_INT__ENCAP_ID,
        SW_STATE_FUNC_SET,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_REFLECTOR_SW_DB_INFO__UC_L2_INT__ENCAP_ID,
        sw_state_roots_array[unit][REFLECTOR_MODULE_ID]);

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_REFLECTOR_SW_DB_INFO__UC_L2_INT__ENCAP_ID,
        DNX_SW_STATE_DIAG_MODIFY);

    DNX_SW_STATE_SET(
        unit,
        DNX_SW_STATE_REFLECTOR_SW_DB_INFO__UC_L2_INT__ENCAP_ID,
        ((reflector_sw_db_info_t*)sw_state_roots_array[unit][REFLECTOR_MODULE_ID])->uc_l2_int.encap_id,
        encap_id,
        int,
        0,
        "reflector_sw_db_info_uc_l2_int_encap_id_set");

    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_SET_LOGGING,
        BSL_LS_SWSTATEDNX_SET,
        DNX_SW_STATE_REFLECTOR_SW_DB_INFO__UC_L2_INT__ENCAP_ID,
        &encap_id,
        "reflector_sw_db_info[%d]->uc_l2_int.encap_id",
        unit);

    DNX_SW_STATE_DIAG_INFO_POST(
        unit,
        DNX_SW_STATE_REFLECTOR_SW_DB_INFO__UC_L2_INT__ENCAP_ID,
        reflector_sw_db_info_info,
        REFLECTOR_SW_DB_INFO_UC_L2_INT_ENCAP_ID_INFO,
        DNX_SW_STATE_DIAG_MODIFY,
        NULL,
        sw_state_layout_array[unit][REFLECTOR_MODULE_ID]);

    DNXC_SW_STATE_FUNC_RETURN;
}



int
reflector_sw_db_info_uc_l2_int_encap_id_get(int unit, int *encap_id)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_REFLECTOR_SW_DB_INFO__UC_L2_INT__ENCAP_ID,
        SW_STATE_FUNC_GET,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_REFLECTOR_SW_DB_INFO__UC_L2_INT__ENCAP_ID,
        sw_state_roots_array[unit][REFLECTOR_MODULE_ID]);

    DNX_SW_STATE_PTR_NULL_CHECK(
        unit,
        DNX_SW_STATE_REFLECTOR_SW_DB_INFO__UC_L2_INT__ENCAP_ID,
        encap_id);

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_REFLECTOR_SW_DB_INFO__UC_L2_INT__ENCAP_ID,
        DNX_SW_STATE_DIAG_READ);

    *encap_id = ((reflector_sw_db_info_t*)sw_state_roots_array[unit][REFLECTOR_MODULE_ID])->uc_l2_int.encap_id;
    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_GET_LOGGING,
        BSL_LS_SWSTATEDNX_GET,
        DNX_SW_STATE_REFLECTOR_SW_DB_INFO__UC_L2_INT__ENCAP_ID,
        &((reflector_sw_db_info_t*)sw_state_roots_array[unit][REFLECTOR_MODULE_ID])->uc_l2_int.encap_id,
        "reflector_sw_db_info[%d]->uc_l2_int.encap_id",
        unit);

    DNX_SW_STATE_DIAG_INFO_POST(
        unit,
        DNX_SW_STATE_REFLECTOR_SW_DB_INFO__UC_L2_INT__ENCAP_ID,
        reflector_sw_db_info_info,
        REFLECTOR_SW_DB_INFO_UC_L2_INT_ENCAP_ID_INFO,
        DNX_SW_STATE_DIAG_READ,
        NULL,
        sw_state_layout_array[unit][REFLECTOR_MODULE_ID]);

    DNXC_SW_STATE_FUNC_RETURN;
}



int
reflector_sw_db_info_uc_l2_int_is_allocated_set(int unit, int is_allocated)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_REFLECTOR_SW_DB_INFO__UC_L2_INT__IS_ALLOCATED,
        SW_STATE_FUNC_SET,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_REFLECTOR_SW_DB_INFO__UC_L2_INT__IS_ALLOCATED,
        sw_state_roots_array[unit][REFLECTOR_MODULE_ID]);

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_REFLECTOR_SW_DB_INFO__UC_L2_INT__IS_ALLOCATED,
        DNX_SW_STATE_DIAG_MODIFY);

    DNX_SW_STATE_SET(
        unit,
        DNX_SW_STATE_REFLECTOR_SW_DB_INFO__UC_L2_INT__IS_ALLOCATED,
        ((reflector_sw_db_info_t*)sw_state_roots_array[unit][REFLECTOR_MODULE_ID])->uc_l2_int.is_allocated,
        is_allocated,
        int,
        0,
        "reflector_sw_db_info_uc_l2_int_is_allocated_set");

    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_SET_LOGGING,
        BSL_LS_SWSTATEDNX_SET,
        DNX_SW_STATE_REFLECTOR_SW_DB_INFO__UC_L2_INT__IS_ALLOCATED,
        &is_allocated,
        "reflector_sw_db_info[%d]->uc_l2_int.is_allocated",
        unit);

    DNX_SW_STATE_DIAG_INFO_POST(
        unit,
        DNX_SW_STATE_REFLECTOR_SW_DB_INFO__UC_L2_INT__IS_ALLOCATED,
        reflector_sw_db_info_info,
        REFLECTOR_SW_DB_INFO_UC_L2_INT_IS_ALLOCATED_INFO,
        DNX_SW_STATE_DIAG_MODIFY,
        NULL,
        sw_state_layout_array[unit][REFLECTOR_MODULE_ID]);

    DNXC_SW_STATE_FUNC_RETURN;
}



int
reflector_sw_db_info_uc_l2_int_is_allocated_get(int unit, int *is_allocated)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_REFLECTOR_SW_DB_INFO__UC_L2_INT__IS_ALLOCATED,
        SW_STATE_FUNC_GET,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_REFLECTOR_SW_DB_INFO__UC_L2_INT__IS_ALLOCATED,
        sw_state_roots_array[unit][REFLECTOR_MODULE_ID]);

    DNX_SW_STATE_PTR_NULL_CHECK(
        unit,
        DNX_SW_STATE_REFLECTOR_SW_DB_INFO__UC_L2_INT__IS_ALLOCATED,
        is_allocated);

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_REFLECTOR_SW_DB_INFO__UC_L2_INT__IS_ALLOCATED,
        DNX_SW_STATE_DIAG_READ);

    *is_allocated = ((reflector_sw_db_info_t*)sw_state_roots_array[unit][REFLECTOR_MODULE_ID])->uc_l2_int.is_allocated;
    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_GET_LOGGING,
        BSL_LS_SWSTATEDNX_GET,
        DNX_SW_STATE_REFLECTOR_SW_DB_INFO__UC_L2_INT__IS_ALLOCATED,
        &((reflector_sw_db_info_t*)sw_state_roots_array[unit][REFLECTOR_MODULE_ID])->uc_l2_int.is_allocated,
        "reflector_sw_db_info[%d]->uc_l2_int.is_allocated",
        unit);

    DNX_SW_STATE_DIAG_INFO_POST(
        unit,
        DNX_SW_STATE_REFLECTOR_SW_DB_INFO__UC_L2_INT__IS_ALLOCATED,
        reflector_sw_db_info_info,
        REFLECTOR_SW_DB_INFO_UC_L2_INT_IS_ALLOCATED_INFO,
        DNX_SW_STATE_DIAG_READ,
        NULL,
        sw_state_layout_array[unit][REFLECTOR_MODULE_ID]);

    DNXC_SW_STATE_FUNC_RETURN;
}



int
reflector_sw_db_info_uc_l2_int_onepass_encap_id_set(int unit, int encap_id)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_REFLECTOR_SW_DB_INFO__UC_L2_INT_ONEPASS__ENCAP_ID,
        SW_STATE_FUNC_SET,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_REFLECTOR_SW_DB_INFO__UC_L2_INT_ONEPASS__ENCAP_ID,
        sw_state_roots_array[unit][REFLECTOR_MODULE_ID]);

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_REFLECTOR_SW_DB_INFO__UC_L2_INT_ONEPASS__ENCAP_ID,
        DNX_SW_STATE_DIAG_MODIFY);

    DNX_SW_STATE_SET(
        unit,
        DNX_SW_STATE_REFLECTOR_SW_DB_INFO__UC_L2_INT_ONEPASS__ENCAP_ID,
        ((reflector_sw_db_info_t*)sw_state_roots_array[unit][REFLECTOR_MODULE_ID])->uc_l2_int_onepass.encap_id,
        encap_id,
        int,
        0,
        "reflector_sw_db_info_uc_l2_int_onepass_encap_id_set");

    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_SET_LOGGING,
        BSL_LS_SWSTATEDNX_SET,
        DNX_SW_STATE_REFLECTOR_SW_DB_INFO__UC_L2_INT_ONEPASS__ENCAP_ID,
        &encap_id,
        "reflector_sw_db_info[%d]->uc_l2_int_onepass.encap_id",
        unit);

    DNX_SW_STATE_DIAG_INFO_POST(
        unit,
        DNX_SW_STATE_REFLECTOR_SW_DB_INFO__UC_L2_INT_ONEPASS__ENCAP_ID,
        reflector_sw_db_info_info,
        REFLECTOR_SW_DB_INFO_UC_L2_INT_ONEPASS_ENCAP_ID_INFO,
        DNX_SW_STATE_DIAG_MODIFY,
        NULL,
        sw_state_layout_array[unit][REFLECTOR_MODULE_ID]);

    DNXC_SW_STATE_FUNC_RETURN;
}



int
reflector_sw_db_info_uc_l2_int_onepass_encap_id_get(int unit, int *encap_id)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_REFLECTOR_SW_DB_INFO__UC_L2_INT_ONEPASS__ENCAP_ID,
        SW_STATE_FUNC_GET,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_REFLECTOR_SW_DB_INFO__UC_L2_INT_ONEPASS__ENCAP_ID,
        sw_state_roots_array[unit][REFLECTOR_MODULE_ID]);

    DNX_SW_STATE_PTR_NULL_CHECK(
        unit,
        DNX_SW_STATE_REFLECTOR_SW_DB_INFO__UC_L2_INT_ONEPASS__ENCAP_ID,
        encap_id);

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_REFLECTOR_SW_DB_INFO__UC_L2_INT_ONEPASS__ENCAP_ID,
        DNX_SW_STATE_DIAG_READ);

    *encap_id = ((reflector_sw_db_info_t*)sw_state_roots_array[unit][REFLECTOR_MODULE_ID])->uc_l2_int_onepass.encap_id;
    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_GET_LOGGING,
        BSL_LS_SWSTATEDNX_GET,
        DNX_SW_STATE_REFLECTOR_SW_DB_INFO__UC_L2_INT_ONEPASS__ENCAP_ID,
        &((reflector_sw_db_info_t*)sw_state_roots_array[unit][REFLECTOR_MODULE_ID])->uc_l2_int_onepass.encap_id,
        "reflector_sw_db_info[%d]->uc_l2_int_onepass.encap_id",
        unit);

    DNX_SW_STATE_DIAG_INFO_POST(
        unit,
        DNX_SW_STATE_REFLECTOR_SW_DB_INFO__UC_L2_INT_ONEPASS__ENCAP_ID,
        reflector_sw_db_info_info,
        REFLECTOR_SW_DB_INFO_UC_L2_INT_ONEPASS_ENCAP_ID_INFO,
        DNX_SW_STATE_DIAG_READ,
        NULL,
        sw_state_layout_array[unit][REFLECTOR_MODULE_ID]);

    DNXC_SW_STATE_FUNC_RETURN;
}



int
reflector_sw_db_info_uc_l2_int_onepass_is_allocated_set(int unit, int is_allocated)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_REFLECTOR_SW_DB_INFO__UC_L2_INT_ONEPASS__IS_ALLOCATED,
        SW_STATE_FUNC_SET,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_REFLECTOR_SW_DB_INFO__UC_L2_INT_ONEPASS__IS_ALLOCATED,
        sw_state_roots_array[unit][REFLECTOR_MODULE_ID]);

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_REFLECTOR_SW_DB_INFO__UC_L2_INT_ONEPASS__IS_ALLOCATED,
        DNX_SW_STATE_DIAG_MODIFY);

    DNX_SW_STATE_SET(
        unit,
        DNX_SW_STATE_REFLECTOR_SW_DB_INFO__UC_L2_INT_ONEPASS__IS_ALLOCATED,
        ((reflector_sw_db_info_t*)sw_state_roots_array[unit][REFLECTOR_MODULE_ID])->uc_l2_int_onepass.is_allocated,
        is_allocated,
        int,
        0,
        "reflector_sw_db_info_uc_l2_int_onepass_is_allocated_set");

    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_SET_LOGGING,
        BSL_LS_SWSTATEDNX_SET,
        DNX_SW_STATE_REFLECTOR_SW_DB_INFO__UC_L2_INT_ONEPASS__IS_ALLOCATED,
        &is_allocated,
        "reflector_sw_db_info[%d]->uc_l2_int_onepass.is_allocated",
        unit);

    DNX_SW_STATE_DIAG_INFO_POST(
        unit,
        DNX_SW_STATE_REFLECTOR_SW_DB_INFO__UC_L2_INT_ONEPASS__IS_ALLOCATED,
        reflector_sw_db_info_info,
        REFLECTOR_SW_DB_INFO_UC_L2_INT_ONEPASS_IS_ALLOCATED_INFO,
        DNX_SW_STATE_DIAG_MODIFY,
        NULL,
        sw_state_layout_array[unit][REFLECTOR_MODULE_ID]);

    DNXC_SW_STATE_FUNC_RETURN;
}



int
reflector_sw_db_info_uc_l2_int_onepass_is_allocated_get(int unit, int *is_allocated)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_REFLECTOR_SW_DB_INFO__UC_L2_INT_ONEPASS__IS_ALLOCATED,
        SW_STATE_FUNC_GET,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_REFLECTOR_SW_DB_INFO__UC_L2_INT_ONEPASS__IS_ALLOCATED,
        sw_state_roots_array[unit][REFLECTOR_MODULE_ID]);

    DNX_SW_STATE_PTR_NULL_CHECK(
        unit,
        DNX_SW_STATE_REFLECTOR_SW_DB_INFO__UC_L2_INT_ONEPASS__IS_ALLOCATED,
        is_allocated);

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_REFLECTOR_SW_DB_INFO__UC_L2_INT_ONEPASS__IS_ALLOCATED,
        DNX_SW_STATE_DIAG_READ);

    *is_allocated = ((reflector_sw_db_info_t*)sw_state_roots_array[unit][REFLECTOR_MODULE_ID])->uc_l2_int_onepass.is_allocated;
    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_GET_LOGGING,
        BSL_LS_SWSTATEDNX_GET,
        DNX_SW_STATE_REFLECTOR_SW_DB_INFO__UC_L2_INT_ONEPASS__IS_ALLOCATED,
        &((reflector_sw_db_info_t*)sw_state_roots_array[unit][REFLECTOR_MODULE_ID])->uc_l2_int_onepass.is_allocated,
        "reflector_sw_db_info[%d]->uc_l2_int_onepass.is_allocated",
        unit);

    DNX_SW_STATE_DIAG_INFO_POST(
        unit,
        DNX_SW_STATE_REFLECTOR_SW_DB_INFO__UC_L2_INT_ONEPASS__IS_ALLOCATED,
        reflector_sw_db_info_info,
        REFLECTOR_SW_DB_INFO_UC_L2_INT_ONEPASS_IS_ALLOCATED_INFO,
        DNX_SW_STATE_DIAG_READ,
        NULL,
        sw_state_layout_array[unit][REFLECTOR_MODULE_ID]);

    DNXC_SW_STATE_FUNC_RETURN;
}



int
reflector_sw_db_info_sbfd_reflector_cnt_set(int unit, uint32 sbfd_reflector_cnt)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_REFLECTOR_SW_DB_INFO__SBFD_REFLECTOR_CNT,
        SW_STATE_FUNC_SET,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_REFLECTOR_SW_DB_INFO__SBFD_REFLECTOR_CNT,
        sw_state_roots_array[unit][REFLECTOR_MODULE_ID]);

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_REFLECTOR_SW_DB_INFO__SBFD_REFLECTOR_CNT,
        DNX_SW_STATE_DIAG_MODIFY);

    DNX_SW_STATE_SET(
        unit,
        DNX_SW_STATE_REFLECTOR_SW_DB_INFO__SBFD_REFLECTOR_CNT,
        ((reflector_sw_db_info_t*)sw_state_roots_array[unit][REFLECTOR_MODULE_ID])->sbfd_reflector_cnt,
        sbfd_reflector_cnt,
        uint32,
        0,
        "reflector_sw_db_info_sbfd_reflector_cnt_set");

    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_SET_LOGGING,
        BSL_LS_SWSTATEDNX_SET,
        DNX_SW_STATE_REFLECTOR_SW_DB_INFO__SBFD_REFLECTOR_CNT,
        &sbfd_reflector_cnt,
        "reflector_sw_db_info[%d]->sbfd_reflector_cnt",
        unit);

    DNX_SW_STATE_DIAG_INFO_POST(
        unit,
        DNX_SW_STATE_REFLECTOR_SW_DB_INFO__SBFD_REFLECTOR_CNT,
        reflector_sw_db_info_info,
        REFLECTOR_SW_DB_INFO_SBFD_REFLECTOR_CNT_INFO,
        DNX_SW_STATE_DIAG_MODIFY,
        NULL,
        sw_state_layout_array[unit][REFLECTOR_MODULE_ID]);

    DNXC_SW_STATE_FUNC_RETURN;
}



int
reflector_sw_db_info_sbfd_reflector_cnt_get(int unit, uint32 *sbfd_reflector_cnt)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_REFLECTOR_SW_DB_INFO__SBFD_REFLECTOR_CNT,
        SW_STATE_FUNC_GET,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_REFLECTOR_SW_DB_INFO__SBFD_REFLECTOR_CNT,
        sw_state_roots_array[unit][REFLECTOR_MODULE_ID]);

    DNX_SW_STATE_PTR_NULL_CHECK(
        unit,
        DNX_SW_STATE_REFLECTOR_SW_DB_INFO__SBFD_REFLECTOR_CNT,
        sbfd_reflector_cnt);

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_REFLECTOR_SW_DB_INFO__SBFD_REFLECTOR_CNT,
        DNX_SW_STATE_DIAG_READ);

    *sbfd_reflector_cnt = ((reflector_sw_db_info_t*)sw_state_roots_array[unit][REFLECTOR_MODULE_ID])->sbfd_reflector_cnt;
    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_GET_LOGGING,
        BSL_LS_SWSTATEDNX_GET,
        DNX_SW_STATE_REFLECTOR_SW_DB_INFO__SBFD_REFLECTOR_CNT,
        &((reflector_sw_db_info_t*)sw_state_roots_array[unit][REFLECTOR_MODULE_ID])->sbfd_reflector_cnt,
        "reflector_sw_db_info[%d]->sbfd_reflector_cnt",
        unit);

    DNX_SW_STATE_DIAG_INFO_POST(
        unit,
        DNX_SW_STATE_REFLECTOR_SW_DB_INFO__SBFD_REFLECTOR_CNT,
        reflector_sw_db_info_info,
        REFLECTOR_SW_DB_INFO_SBFD_REFLECTOR_CNT_INFO,
        DNX_SW_STATE_DIAG_READ,
        NULL,
        sw_state_layout_array[unit][REFLECTOR_MODULE_ID]);

    DNXC_SW_STATE_FUNC_RETURN;
}



int
reflector_sw_db_info_sbfd_reflector_discriminator_set(int unit, uint32 sbfd_reflector_discriminator)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_REFLECTOR_SW_DB_INFO__SBFD_REFLECTOR_DISCRIMINATOR,
        SW_STATE_FUNC_SET,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_REFLECTOR_SW_DB_INFO__SBFD_REFLECTOR_DISCRIMINATOR,
        sw_state_roots_array[unit][REFLECTOR_MODULE_ID]);

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_REFLECTOR_SW_DB_INFO__SBFD_REFLECTOR_DISCRIMINATOR,
        DNX_SW_STATE_DIAG_MODIFY);

    DNX_SW_STATE_SET(
        unit,
        DNX_SW_STATE_REFLECTOR_SW_DB_INFO__SBFD_REFLECTOR_DISCRIMINATOR,
        ((reflector_sw_db_info_t*)sw_state_roots_array[unit][REFLECTOR_MODULE_ID])->sbfd_reflector_discriminator,
        sbfd_reflector_discriminator,
        uint32,
        0,
        "reflector_sw_db_info_sbfd_reflector_discriminator_set");

    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_SET_LOGGING,
        BSL_LS_SWSTATEDNX_SET,
        DNX_SW_STATE_REFLECTOR_SW_DB_INFO__SBFD_REFLECTOR_DISCRIMINATOR,
        &sbfd_reflector_discriminator,
        "reflector_sw_db_info[%d]->sbfd_reflector_discriminator",
        unit);

    DNX_SW_STATE_DIAG_INFO_POST(
        unit,
        DNX_SW_STATE_REFLECTOR_SW_DB_INFO__SBFD_REFLECTOR_DISCRIMINATOR,
        reflector_sw_db_info_info,
        REFLECTOR_SW_DB_INFO_SBFD_REFLECTOR_DISCRIMINATOR_INFO,
        DNX_SW_STATE_DIAG_MODIFY,
        NULL,
        sw_state_layout_array[unit][REFLECTOR_MODULE_ID]);

    DNXC_SW_STATE_FUNC_RETURN;
}



int
reflector_sw_db_info_sbfd_reflector_discriminator_get(int unit, uint32 *sbfd_reflector_discriminator)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_REFLECTOR_SW_DB_INFO__SBFD_REFLECTOR_DISCRIMINATOR,
        SW_STATE_FUNC_GET,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_REFLECTOR_SW_DB_INFO__SBFD_REFLECTOR_DISCRIMINATOR,
        sw_state_roots_array[unit][REFLECTOR_MODULE_ID]);

    DNX_SW_STATE_PTR_NULL_CHECK(
        unit,
        DNX_SW_STATE_REFLECTOR_SW_DB_INFO__SBFD_REFLECTOR_DISCRIMINATOR,
        sbfd_reflector_discriminator);

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_REFLECTOR_SW_DB_INFO__SBFD_REFLECTOR_DISCRIMINATOR,
        DNX_SW_STATE_DIAG_READ);

    *sbfd_reflector_discriminator = ((reflector_sw_db_info_t*)sw_state_roots_array[unit][REFLECTOR_MODULE_ID])->sbfd_reflector_discriminator;
    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_GET_LOGGING,
        BSL_LS_SWSTATEDNX_GET,
        DNX_SW_STATE_REFLECTOR_SW_DB_INFO__SBFD_REFLECTOR_DISCRIMINATOR,
        &((reflector_sw_db_info_t*)sw_state_roots_array[unit][REFLECTOR_MODULE_ID])->sbfd_reflector_discriminator,
        "reflector_sw_db_info[%d]->sbfd_reflector_discriminator",
        unit);

    DNX_SW_STATE_DIAG_INFO_POST(
        unit,
        DNX_SW_STATE_REFLECTOR_SW_DB_INFO__SBFD_REFLECTOR_DISCRIMINATOR,
        reflector_sw_db_info_info,
        REFLECTOR_SW_DB_INFO_SBFD_REFLECTOR_DISCRIMINATOR_INFO,
        DNX_SW_STATE_DIAG_READ,
        NULL,
        sw_state_layout_array[unit][REFLECTOR_MODULE_ID]);

    DNXC_SW_STATE_FUNC_RETURN;
}




reflector_sw_db_info_cbs reflector_sw_db_info = 	{
	
	reflector_sw_db_info_is_init,
	reflector_sw_db_info_init,
		{
		
			{
			
			reflector_sw_db_info_uc_encap_id_set,
			reflector_sw_db_info_uc_encap_id_get}
		,
			{
			
			reflector_sw_db_info_uc_is_allocated_set,
			reflector_sw_db_info_uc_is_allocated_get}
		}
	,
		{
		
			{
			
			reflector_sw_db_info_uc_l2_int_encap_id_set,
			reflector_sw_db_info_uc_l2_int_encap_id_get}
		,
			{
			
			reflector_sw_db_info_uc_l2_int_is_allocated_set,
			reflector_sw_db_info_uc_l2_int_is_allocated_get}
		}
	,
		{
		
			{
			
			reflector_sw_db_info_uc_l2_int_onepass_encap_id_set,
			reflector_sw_db_info_uc_l2_int_onepass_encap_id_get}
		,
			{
			
			reflector_sw_db_info_uc_l2_int_onepass_is_allocated_set,
			reflector_sw_db_info_uc_l2_int_onepass_is_allocated_get}
		}
	,
		{
		
		reflector_sw_db_info_sbfd_reflector_cnt_set,
		reflector_sw_db_info_sbfd_reflector_cnt_get}
	,
		{
		
		reflector_sw_db_info_sbfd_reflector_discriminator_set,
		reflector_sw_db_info_sbfd_reflector_discriminator_get}
	}
;
#undef BSL_LOG_MODULE
