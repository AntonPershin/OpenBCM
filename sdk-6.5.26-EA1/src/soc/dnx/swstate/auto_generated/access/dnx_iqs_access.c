
/*
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2022 Broadcom Inc. All rights reserved.
 */

#ifdef BSL_LOG_MODULE
#error "BSL_LOG_MODULE redefined"
#endif
#define BSL_LOG_MODULE BSL_LS_SWSTATEDNX_GENERAL

#include <soc/dnx/swstate/auto_generated/access/dnx_iqs_access.h>
#include <soc/dnx/swstate/auto_generated/diagnostic/dnx_iqs_diagnostic.h>
#include <soc/dnx/swstate/auto_generated/layout/dnx_iqs_layout.h>





int
dnx_iqs_db_is_init(int unit, uint8 *is_init)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_DNX_IQS_DB,
        SW_STATE_FUNC_IS_INIT,
        DNXC_SW_STATE_NO_FLAGS);

    *is_init = (NULL != ((dnx_iqs_db_t*)sw_state_roots_array[unit][DNX_IQS_MODULE_ID]));
    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_IS_INIT_LOGGING,
        BSL_LS_SWSTATEDNX_ISINIT,
        DNX_SW_STATE_DNX_IQS_DB,
        ((dnx_iqs_db_t*)sw_state_roots_array[unit][DNX_IQS_MODULE_ID]),
        "dnx_iqs_db[%d]",
        unit);

    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_iqs_db_init(int unit)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_DNX_IQS_DB,
        SW_STATE_FUNC_INIT,
        DNXC_SW_STATE_NO_FLAGS);

    DNX_SW_STATE_MODULE_INIT(
        unit,
        DNX_SW_STATE_DNX_IQS_DB,
        DNXC_SW_STATE_IMPLEMENTATION_WB,
        dnx_iqs_db_t,
        DNX_SW_STATE_DNX_IQS_DB_NOF_PARAMS,
        DNXC_SW_STATE_AUTO_GENERATED_ALLOCATION,
        "dnx_iqs_db_init",
        DNX_SW_STATE_DIAG_ALLOC,
        dnx_iqs_init_layout_structure);

    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_INIT_LOGGING,
        BSL_LS_SWSTATEDNX_INIT,
        DNX_SW_STATE_DNX_IQS_DB,
        ((dnx_iqs_db_t*)sw_state_roots_array[unit][DNX_IQS_MODULE_ID]),
        "dnx_iqs_db[%d]",
        unit);

    DNX_SW_STATE_DIAG_INFO_POST(
        unit,
        DNX_SW_STATE_DNX_IQS_DB,
        dnx_iqs_db_info,
        DNX_IQS_DB_INFO,
        DNX_SW_STATE_DIAG_ALLOC,
        ((dnx_iqs_db_t*)sw_state_roots_array[unit][DNX_IQS_MODULE_ID]));

    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_iqs_db_credit_request_profile_alloc(int unit)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_DNX_IQS_DB__CREDIT_REQUEST_PROFILE,
        SW_STATE_FUNC_ALLOC,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_DNX_IQS_DB__CREDIT_REQUEST_PROFILE,
        sw_state_roots_array[unit][DNX_IQS_MODULE_ID]);

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_DNX_IQS_DB__CREDIT_REQUEST_PROFILE,
        DNX_SW_STATE_DIAG_ALLOC);

    DNX_SW_STATE_ALLOC(
        unit,
        DNX_SW_STATE_DNX_IQS_DB__CREDIT_REQUEST_PROFILE,
        ((dnx_iqs_db_t*)sw_state_roots_array[unit][DNX_IQS_MODULE_ID])->credit_request_profile,
        dnx_iqs_credit_request_profile_db_t,
        dnx_data_iqs.credit.nof_profiles_get(unit),
        DNXC_SW_STATE_DNX_DATA_ALLOC | DNXC_SW_STATE_AUTO_GENERATED_ALLOCATION,
        "dnx_iqs_db_credit_request_profile_alloc");

    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_ALLOC_LOGGING,
        BSL_LS_SWSTATEDNX_ALLOC,
        DNX_SW_STATE_DNX_IQS_DB__CREDIT_REQUEST_PROFILE,
        ((dnx_iqs_db_t*)sw_state_roots_array[unit][DNX_IQS_MODULE_ID])->credit_request_profile,
        "dnx_iqs_db[%d]->credit_request_profile",
        unit,
        dnx_data_iqs.credit.nof_profiles_get(unit) * sizeof(dnx_iqs_credit_request_profile_db_t) / sizeof(*((dnx_iqs_db_t*)sw_state_roots_array[unit][DNX_IQS_MODULE_ID])->credit_request_profile));

    DNX_SW_STATE_DIAG_INFO_POST(
        unit,
        DNX_SW_STATE_DNX_IQS_DB__CREDIT_REQUEST_PROFILE,
        dnx_iqs_db_info,
        DNX_IQS_DB_CREDIT_REQUEST_PROFILE_INFO,
        DNX_SW_STATE_DIAG_ALLOC,
        NULL);

    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_iqs_db_credit_request_profile_valid_set(int unit, uint32 credit_request_profile_idx_0, int valid)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_DNX_IQS_DB__CREDIT_REQUEST_PROFILE__VALID,
        SW_STATE_FUNC_SET,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_DNX_IQS_DB__CREDIT_REQUEST_PROFILE__VALID,
        sw_state_roots_array[unit][DNX_IQS_MODULE_ID]);

    DNX_SW_STATE_OOB_DYNAMIC_ARRAY_CHECK(
        DNX_SW_STATE_DNX_IQS_DB__CREDIT_REQUEST_PROFILE__VALID,
        ((dnx_iqs_db_t*)sw_state_roots_array[unit][DNX_IQS_MODULE_ID])->credit_request_profile,
        credit_request_profile_idx_0);

    DNX_SW_STATE_PTR_NULL_CHECK(
        unit,
        DNX_SW_STATE_DNX_IQS_DB__CREDIT_REQUEST_PROFILE__VALID,
        ((dnx_iqs_db_t*)sw_state_roots_array[unit][DNX_IQS_MODULE_ID])->credit_request_profile);

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_DNX_IQS_DB__CREDIT_REQUEST_PROFILE__VALID,
        DNX_SW_STATE_DIAG_MODIFY);

    DNX_SW_STATE_SET(
        unit,
        DNX_SW_STATE_DNX_IQS_DB__CREDIT_REQUEST_PROFILE__VALID,
        ((dnx_iqs_db_t*)sw_state_roots_array[unit][DNX_IQS_MODULE_ID])->credit_request_profile[credit_request_profile_idx_0].valid,
        valid,
        int,
        0,
        "dnx_iqs_db_credit_request_profile_valid_set");

    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_SET_LOGGING,
        BSL_LS_SWSTATEDNX_SET,
        DNX_SW_STATE_DNX_IQS_DB__CREDIT_REQUEST_PROFILE__VALID,
        &valid,
        "dnx_iqs_db[%d]->credit_request_profile[%d].valid",
        unit, credit_request_profile_idx_0);

    DNX_SW_STATE_DIAG_INFO_POST(
        unit,
        DNX_SW_STATE_DNX_IQS_DB__CREDIT_REQUEST_PROFILE__VALID,
        dnx_iqs_db_info,
        DNX_IQS_DB_CREDIT_REQUEST_PROFILE_VALID_INFO,
        DNX_SW_STATE_DIAG_MODIFY,
        NULL);

    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_iqs_db_credit_request_profile_valid_get(int unit, uint32 credit_request_profile_idx_0, int *valid)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_DNX_IQS_DB__CREDIT_REQUEST_PROFILE__VALID,
        SW_STATE_FUNC_GET,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_DNX_IQS_DB__CREDIT_REQUEST_PROFILE__VALID,
        sw_state_roots_array[unit][DNX_IQS_MODULE_ID]);

    DNX_SW_STATE_OOB_DYNAMIC_ARRAY_CHECK(
        DNX_SW_STATE_DNX_IQS_DB__CREDIT_REQUEST_PROFILE__VALID,
        ((dnx_iqs_db_t*)sw_state_roots_array[unit][DNX_IQS_MODULE_ID])->credit_request_profile,
        credit_request_profile_idx_0);

    DNX_SW_STATE_PTR_NULL_CHECK(
        unit,
        DNX_SW_STATE_DNX_IQS_DB__CREDIT_REQUEST_PROFILE__VALID,
        valid);

    DNX_SW_STATE_PTR_NULL_CHECK(
        unit,
        DNX_SW_STATE_DNX_IQS_DB__CREDIT_REQUEST_PROFILE__VALID,
        ((dnx_iqs_db_t*)sw_state_roots_array[unit][DNX_IQS_MODULE_ID])->credit_request_profile);

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_DNX_IQS_DB__CREDIT_REQUEST_PROFILE__VALID,
        DNX_SW_STATE_DIAG_READ);

    *valid = ((dnx_iqs_db_t*)sw_state_roots_array[unit][DNX_IQS_MODULE_ID])->credit_request_profile[credit_request_profile_idx_0].valid;
    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_GET_LOGGING,
        BSL_LS_SWSTATEDNX_GET,
        DNX_SW_STATE_DNX_IQS_DB__CREDIT_REQUEST_PROFILE__VALID,
        &((dnx_iqs_db_t*)sw_state_roots_array[unit][DNX_IQS_MODULE_ID])->credit_request_profile[credit_request_profile_idx_0].valid,
        "dnx_iqs_db[%d]->credit_request_profile[%d].valid",
        unit, credit_request_profile_idx_0);

    DNX_SW_STATE_DIAG_INFO_POST(
        unit,
        DNX_SW_STATE_DNX_IQS_DB__CREDIT_REQUEST_PROFILE__VALID,
        dnx_iqs_db_info,
        DNX_IQS_DB_CREDIT_REQUEST_PROFILE_VALID_INFO,
        DNX_SW_STATE_DIAG_READ,
        NULL);

    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_iqs_db_credit_request_profile_thresholds_set(int unit, uint32 credit_request_profile_idx_0, bcm_cosq_delay_tolerance_t thresholds)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_DNX_IQS_DB__CREDIT_REQUEST_PROFILE__THRESHOLDS,
        SW_STATE_FUNC_SET,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_DNX_IQS_DB__CREDIT_REQUEST_PROFILE__THRESHOLDS,
        sw_state_roots_array[unit][DNX_IQS_MODULE_ID]);

    DNX_SW_STATE_OOB_DYNAMIC_ARRAY_CHECK(
        DNX_SW_STATE_DNX_IQS_DB__CREDIT_REQUEST_PROFILE__THRESHOLDS,
        ((dnx_iqs_db_t*)sw_state_roots_array[unit][DNX_IQS_MODULE_ID])->credit_request_profile,
        credit_request_profile_idx_0);

    DNX_SW_STATE_PTR_NULL_CHECK(
        unit,
        DNX_SW_STATE_DNX_IQS_DB__CREDIT_REQUEST_PROFILE__THRESHOLDS,
        ((dnx_iqs_db_t*)sw_state_roots_array[unit][DNX_IQS_MODULE_ID])->credit_request_profile);

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_DNX_IQS_DB__CREDIT_REQUEST_PROFILE__THRESHOLDS,
        DNX_SW_STATE_DIAG_MODIFY);

    DNX_SW_STATE_SET(
        unit,
        DNX_SW_STATE_DNX_IQS_DB__CREDIT_REQUEST_PROFILE__THRESHOLDS,
        ((dnx_iqs_db_t*)sw_state_roots_array[unit][DNX_IQS_MODULE_ID])->credit_request_profile[credit_request_profile_idx_0].thresholds,
        thresholds,
        bcm_cosq_delay_tolerance_t,
        0,
        "dnx_iqs_db_credit_request_profile_thresholds_set");

    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_SET_LOGGING,
        BSL_LS_SWSTATEDNX_SET,
        DNX_SW_STATE_DNX_IQS_DB__CREDIT_REQUEST_PROFILE__THRESHOLDS,
        &thresholds,
        "dnx_iqs_db[%d]->credit_request_profile[%d].thresholds",
        unit, credit_request_profile_idx_0);

    DNX_SW_STATE_DIAG_INFO_POST(
        unit,
        DNX_SW_STATE_DNX_IQS_DB__CREDIT_REQUEST_PROFILE__THRESHOLDS,
        dnx_iqs_db_info,
        DNX_IQS_DB_CREDIT_REQUEST_PROFILE_THRESHOLDS_INFO,
        DNX_SW_STATE_DIAG_MODIFY,
        NULL);

    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_iqs_db_credit_request_profile_thresholds_get(int unit, uint32 credit_request_profile_idx_0, bcm_cosq_delay_tolerance_t *thresholds)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_DNX_IQS_DB__CREDIT_REQUEST_PROFILE__THRESHOLDS,
        SW_STATE_FUNC_GET,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_DNX_IQS_DB__CREDIT_REQUEST_PROFILE__THRESHOLDS,
        sw_state_roots_array[unit][DNX_IQS_MODULE_ID]);

    DNX_SW_STATE_OOB_DYNAMIC_ARRAY_CHECK(
        DNX_SW_STATE_DNX_IQS_DB__CREDIT_REQUEST_PROFILE__THRESHOLDS,
        ((dnx_iqs_db_t*)sw_state_roots_array[unit][DNX_IQS_MODULE_ID])->credit_request_profile,
        credit_request_profile_idx_0);

    DNX_SW_STATE_PTR_NULL_CHECK(
        unit,
        DNX_SW_STATE_DNX_IQS_DB__CREDIT_REQUEST_PROFILE__THRESHOLDS,
        thresholds);

    DNX_SW_STATE_PTR_NULL_CHECK(
        unit,
        DNX_SW_STATE_DNX_IQS_DB__CREDIT_REQUEST_PROFILE__THRESHOLDS,
        ((dnx_iqs_db_t*)sw_state_roots_array[unit][DNX_IQS_MODULE_ID])->credit_request_profile);

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_DNX_IQS_DB__CREDIT_REQUEST_PROFILE__THRESHOLDS,
        DNX_SW_STATE_DIAG_READ);

    *thresholds = ((dnx_iqs_db_t*)sw_state_roots_array[unit][DNX_IQS_MODULE_ID])->credit_request_profile[credit_request_profile_idx_0].thresholds;
    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_GET_LOGGING,
        BSL_LS_SWSTATEDNX_GET,
        DNX_SW_STATE_DNX_IQS_DB__CREDIT_REQUEST_PROFILE__THRESHOLDS,
        &((dnx_iqs_db_t*)sw_state_roots_array[unit][DNX_IQS_MODULE_ID])->credit_request_profile[credit_request_profile_idx_0].thresholds,
        "dnx_iqs_db[%d]->credit_request_profile[%d].thresholds",
        unit, credit_request_profile_idx_0);

    DNX_SW_STATE_DIAG_INFO_POST(
        unit,
        DNX_SW_STATE_DNX_IQS_DB__CREDIT_REQUEST_PROFILE__THRESHOLDS,
        dnx_iqs_db_info,
        DNX_IQS_DB_CREDIT_REQUEST_PROFILE_THRESHOLDS_INFO,
        DNX_SW_STATE_DIAG_READ,
        NULL);

    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_iqs_db_credit_watchdog_queue_min_set(int unit, int queue_min)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_DNX_IQS_DB__CREDIT_WATCHDOG__QUEUE_MIN,
        SW_STATE_FUNC_SET,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_DNX_IQS_DB__CREDIT_WATCHDOG__QUEUE_MIN,
        sw_state_roots_array[unit][DNX_IQS_MODULE_ID]);

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_DNX_IQS_DB__CREDIT_WATCHDOG__QUEUE_MIN,
        DNX_SW_STATE_DIAG_MODIFY);

    DNX_SW_STATE_SET(
        unit,
        DNX_SW_STATE_DNX_IQS_DB__CREDIT_WATCHDOG__QUEUE_MIN,
        ((dnx_iqs_db_t*)sw_state_roots_array[unit][DNX_IQS_MODULE_ID])->credit_watchdog.queue_min,
        queue_min,
        int,
        0,
        "dnx_iqs_db_credit_watchdog_queue_min_set");

    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_SET_LOGGING,
        BSL_LS_SWSTATEDNX_SET,
        DNX_SW_STATE_DNX_IQS_DB__CREDIT_WATCHDOG__QUEUE_MIN,
        &queue_min,
        "dnx_iqs_db[%d]->credit_watchdog.queue_min",
        unit);

    DNX_SW_STATE_DIAG_INFO_POST(
        unit,
        DNX_SW_STATE_DNX_IQS_DB__CREDIT_WATCHDOG__QUEUE_MIN,
        dnx_iqs_db_info,
        DNX_IQS_DB_CREDIT_WATCHDOG_QUEUE_MIN_INFO,
        DNX_SW_STATE_DIAG_MODIFY,
        NULL);

    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_iqs_db_credit_watchdog_queue_min_get(int unit, int *queue_min)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_DNX_IQS_DB__CREDIT_WATCHDOG__QUEUE_MIN,
        SW_STATE_FUNC_GET,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_DNX_IQS_DB__CREDIT_WATCHDOG__QUEUE_MIN,
        sw_state_roots_array[unit][DNX_IQS_MODULE_ID]);

    DNX_SW_STATE_PTR_NULL_CHECK(
        unit,
        DNX_SW_STATE_DNX_IQS_DB__CREDIT_WATCHDOG__QUEUE_MIN,
        queue_min);

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_DNX_IQS_DB__CREDIT_WATCHDOG__QUEUE_MIN,
        DNX_SW_STATE_DIAG_READ);

    *queue_min = ((dnx_iqs_db_t*)sw_state_roots_array[unit][DNX_IQS_MODULE_ID])->credit_watchdog.queue_min;
    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_GET_LOGGING,
        BSL_LS_SWSTATEDNX_GET,
        DNX_SW_STATE_DNX_IQS_DB__CREDIT_WATCHDOG__QUEUE_MIN,
        &((dnx_iqs_db_t*)sw_state_roots_array[unit][DNX_IQS_MODULE_ID])->credit_watchdog.queue_min,
        "dnx_iqs_db[%d]->credit_watchdog.queue_min",
        unit);

    DNX_SW_STATE_DIAG_INFO_POST(
        unit,
        DNX_SW_STATE_DNX_IQS_DB__CREDIT_WATCHDOG__QUEUE_MIN,
        dnx_iqs_db_info,
        DNX_IQS_DB_CREDIT_WATCHDOG_QUEUE_MIN_INFO,
        DNX_SW_STATE_DIAG_READ,
        NULL);

    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_iqs_db_credit_watchdog_queue_max_set(int unit, int queue_max)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_DNX_IQS_DB__CREDIT_WATCHDOG__QUEUE_MAX,
        SW_STATE_FUNC_SET,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_DNX_IQS_DB__CREDIT_WATCHDOG__QUEUE_MAX,
        sw_state_roots_array[unit][DNX_IQS_MODULE_ID]);

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_DNX_IQS_DB__CREDIT_WATCHDOG__QUEUE_MAX,
        DNX_SW_STATE_DIAG_MODIFY);

    DNX_SW_STATE_SET(
        unit,
        DNX_SW_STATE_DNX_IQS_DB__CREDIT_WATCHDOG__QUEUE_MAX,
        ((dnx_iqs_db_t*)sw_state_roots_array[unit][DNX_IQS_MODULE_ID])->credit_watchdog.queue_max,
        queue_max,
        int,
        0,
        "dnx_iqs_db_credit_watchdog_queue_max_set");

    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_SET_LOGGING,
        BSL_LS_SWSTATEDNX_SET,
        DNX_SW_STATE_DNX_IQS_DB__CREDIT_WATCHDOG__QUEUE_MAX,
        &queue_max,
        "dnx_iqs_db[%d]->credit_watchdog.queue_max",
        unit);

    DNX_SW_STATE_DIAG_INFO_POST(
        unit,
        DNX_SW_STATE_DNX_IQS_DB__CREDIT_WATCHDOG__QUEUE_MAX,
        dnx_iqs_db_info,
        DNX_IQS_DB_CREDIT_WATCHDOG_QUEUE_MAX_INFO,
        DNX_SW_STATE_DIAG_MODIFY,
        NULL);

    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_iqs_db_credit_watchdog_queue_max_get(int unit, int *queue_max)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_DNX_IQS_DB__CREDIT_WATCHDOG__QUEUE_MAX,
        SW_STATE_FUNC_GET,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_DNX_IQS_DB__CREDIT_WATCHDOG__QUEUE_MAX,
        sw_state_roots_array[unit][DNX_IQS_MODULE_ID]);

    DNX_SW_STATE_PTR_NULL_CHECK(
        unit,
        DNX_SW_STATE_DNX_IQS_DB__CREDIT_WATCHDOG__QUEUE_MAX,
        queue_max);

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_DNX_IQS_DB__CREDIT_WATCHDOG__QUEUE_MAX,
        DNX_SW_STATE_DIAG_READ);

    *queue_max = ((dnx_iqs_db_t*)sw_state_roots_array[unit][DNX_IQS_MODULE_ID])->credit_watchdog.queue_max;
    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_GET_LOGGING,
        BSL_LS_SWSTATEDNX_GET,
        DNX_SW_STATE_DNX_IQS_DB__CREDIT_WATCHDOG__QUEUE_MAX,
        &((dnx_iqs_db_t*)sw_state_roots_array[unit][DNX_IQS_MODULE_ID])->credit_watchdog.queue_max,
        "dnx_iqs_db[%d]->credit_watchdog.queue_max",
        unit);

    DNX_SW_STATE_DIAG_INFO_POST(
        unit,
        DNX_SW_STATE_DNX_IQS_DB__CREDIT_WATCHDOG__QUEUE_MAX,
        dnx_iqs_db_info,
        DNX_IQS_DB_CREDIT_WATCHDOG_QUEUE_MAX_INFO,
        DNX_SW_STATE_DIAG_READ,
        NULL);

    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_iqs_db_credit_watchdog_enable_set(int unit, int enable)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_DNX_IQS_DB__CREDIT_WATCHDOG__ENABLE,
        SW_STATE_FUNC_SET,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_DNX_IQS_DB__CREDIT_WATCHDOG__ENABLE,
        sw_state_roots_array[unit][DNX_IQS_MODULE_ID]);

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_DNX_IQS_DB__CREDIT_WATCHDOG__ENABLE,
        DNX_SW_STATE_DIAG_MODIFY);

    DNX_SW_STATE_SET(
        unit,
        DNX_SW_STATE_DNX_IQS_DB__CREDIT_WATCHDOG__ENABLE,
        ((dnx_iqs_db_t*)sw_state_roots_array[unit][DNX_IQS_MODULE_ID])->credit_watchdog.enable,
        enable,
        int,
        0,
        "dnx_iqs_db_credit_watchdog_enable_set");

    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_SET_LOGGING,
        BSL_LS_SWSTATEDNX_SET,
        DNX_SW_STATE_DNX_IQS_DB__CREDIT_WATCHDOG__ENABLE,
        &enable,
        "dnx_iqs_db[%d]->credit_watchdog.enable",
        unit);

    DNX_SW_STATE_DIAG_INFO_POST(
        unit,
        DNX_SW_STATE_DNX_IQS_DB__CREDIT_WATCHDOG__ENABLE,
        dnx_iqs_db_info,
        DNX_IQS_DB_CREDIT_WATCHDOG_ENABLE_INFO,
        DNX_SW_STATE_DIAG_MODIFY,
        NULL);

    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_iqs_db_credit_watchdog_enable_get(int unit, int *enable)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_DNX_IQS_DB__CREDIT_WATCHDOG__ENABLE,
        SW_STATE_FUNC_GET,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_DNX_IQS_DB__CREDIT_WATCHDOG__ENABLE,
        sw_state_roots_array[unit][DNX_IQS_MODULE_ID]);

    DNX_SW_STATE_PTR_NULL_CHECK(
        unit,
        DNX_SW_STATE_DNX_IQS_DB__CREDIT_WATCHDOG__ENABLE,
        enable);

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_DNX_IQS_DB__CREDIT_WATCHDOG__ENABLE,
        DNX_SW_STATE_DIAG_READ);

    *enable = ((dnx_iqs_db_t*)sw_state_roots_array[unit][DNX_IQS_MODULE_ID])->credit_watchdog.enable;
    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_GET_LOGGING,
        BSL_LS_SWSTATEDNX_GET,
        DNX_SW_STATE_DNX_IQS_DB__CREDIT_WATCHDOG__ENABLE,
        &((dnx_iqs_db_t*)sw_state_roots_array[unit][DNX_IQS_MODULE_ID])->credit_watchdog.enable,
        "dnx_iqs_db[%d]->credit_watchdog.enable",
        unit);

    DNX_SW_STATE_DIAG_INFO_POST(
        unit,
        DNX_SW_STATE_DNX_IQS_DB__CREDIT_WATCHDOG__ENABLE,
        dnx_iqs_db_info,
        DNX_IQS_DB_CREDIT_WATCHDOG_ENABLE_INFO,
        DNX_SW_STATE_DIAG_READ,
        NULL);

    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_iqs_db_credit_watchdog_retransmit_th_set(int unit, int retransmit_th)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_DNX_IQS_DB__CREDIT_WATCHDOG__RETRANSMIT_TH,
        SW_STATE_FUNC_SET,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_DNX_IQS_DB__CREDIT_WATCHDOG__RETRANSMIT_TH,
        sw_state_roots_array[unit][DNX_IQS_MODULE_ID]);

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_DNX_IQS_DB__CREDIT_WATCHDOG__RETRANSMIT_TH,
        DNX_SW_STATE_DIAG_MODIFY);

    DNX_SW_STATE_SET(
        unit,
        DNX_SW_STATE_DNX_IQS_DB__CREDIT_WATCHDOG__RETRANSMIT_TH,
        ((dnx_iqs_db_t*)sw_state_roots_array[unit][DNX_IQS_MODULE_ID])->credit_watchdog.retransmit_th,
        retransmit_th,
        int,
        0,
        "dnx_iqs_db_credit_watchdog_retransmit_th_set");

    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_SET_LOGGING,
        BSL_LS_SWSTATEDNX_SET,
        DNX_SW_STATE_DNX_IQS_DB__CREDIT_WATCHDOG__RETRANSMIT_TH,
        &retransmit_th,
        "dnx_iqs_db[%d]->credit_watchdog.retransmit_th",
        unit);

    DNX_SW_STATE_DIAG_INFO_POST(
        unit,
        DNX_SW_STATE_DNX_IQS_DB__CREDIT_WATCHDOG__RETRANSMIT_TH,
        dnx_iqs_db_info,
        DNX_IQS_DB_CREDIT_WATCHDOG_RETRANSMIT_TH_INFO,
        DNX_SW_STATE_DIAG_MODIFY,
        NULL);

    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_iqs_db_credit_watchdog_retransmit_th_get(int unit, int *retransmit_th)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_DNX_IQS_DB__CREDIT_WATCHDOG__RETRANSMIT_TH,
        SW_STATE_FUNC_GET,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_DNX_IQS_DB__CREDIT_WATCHDOG__RETRANSMIT_TH,
        sw_state_roots_array[unit][DNX_IQS_MODULE_ID]);

    DNX_SW_STATE_PTR_NULL_CHECK(
        unit,
        DNX_SW_STATE_DNX_IQS_DB__CREDIT_WATCHDOG__RETRANSMIT_TH,
        retransmit_th);

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_DNX_IQS_DB__CREDIT_WATCHDOG__RETRANSMIT_TH,
        DNX_SW_STATE_DIAG_READ);

    *retransmit_th = ((dnx_iqs_db_t*)sw_state_roots_array[unit][DNX_IQS_MODULE_ID])->credit_watchdog.retransmit_th;
    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_GET_LOGGING,
        BSL_LS_SWSTATEDNX_GET,
        DNX_SW_STATE_DNX_IQS_DB__CREDIT_WATCHDOG__RETRANSMIT_TH,
        &((dnx_iqs_db_t*)sw_state_roots_array[unit][DNX_IQS_MODULE_ID])->credit_watchdog.retransmit_th,
        "dnx_iqs_db[%d]->credit_watchdog.retransmit_th",
        unit);

    DNX_SW_STATE_DIAG_INFO_POST(
        unit,
        DNX_SW_STATE_DNX_IQS_DB__CREDIT_WATCHDOG__RETRANSMIT_TH,
        dnx_iqs_db_info,
        DNX_IQS_DB_CREDIT_WATCHDOG_RETRANSMIT_TH_INFO,
        DNX_SW_STATE_DIAG_READ,
        NULL);

    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_iqs_db_credit_watchdog_delete_th_set(int unit, uint32 delete_th_idx_0, int delete_th)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_DNX_IQS_DB__CREDIT_WATCHDOG__DELETE_TH,
        SW_STATE_FUNC_SET,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_DNX_IQS_DB__CREDIT_WATCHDOG__DELETE_TH,
        sw_state_roots_array[unit][DNX_IQS_MODULE_ID]);

    DNX_SW_STATE_OOB_DYNAMIC_ARRAY_CHECK(
        DNX_SW_STATE_DNX_IQS_DB__CREDIT_WATCHDOG__DELETE_TH,
        ((dnx_iqs_db_t*)sw_state_roots_array[unit][DNX_IQS_MODULE_ID])->credit_watchdog.delete_th,
        delete_th_idx_0);

    DNX_SW_STATE_PTR_NULL_CHECK(
        unit,
        DNX_SW_STATE_DNX_IQS_DB__CREDIT_WATCHDOG__DELETE_TH,
        ((dnx_iqs_db_t*)sw_state_roots_array[unit][DNX_IQS_MODULE_ID])->credit_watchdog.delete_th);

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_DNX_IQS_DB__CREDIT_WATCHDOG__DELETE_TH,
        DNX_SW_STATE_DIAG_MODIFY);

    DNX_SW_STATE_SET(
        unit,
        DNX_SW_STATE_DNX_IQS_DB__CREDIT_WATCHDOG__DELETE_TH,
        ((dnx_iqs_db_t*)sw_state_roots_array[unit][DNX_IQS_MODULE_ID])->credit_watchdog.delete_th[delete_th_idx_0],
        delete_th,
        int,
        0,
        "dnx_iqs_db_credit_watchdog_delete_th_set");

    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_SET_LOGGING,
        BSL_LS_SWSTATEDNX_SET,
        DNX_SW_STATE_DNX_IQS_DB__CREDIT_WATCHDOG__DELETE_TH,
        &delete_th,
        "dnx_iqs_db[%d]->credit_watchdog.delete_th[%d]",
        unit, delete_th_idx_0);

    DNX_SW_STATE_DIAG_INFO_POST(
        unit,
        DNX_SW_STATE_DNX_IQS_DB__CREDIT_WATCHDOG__DELETE_TH,
        dnx_iqs_db_info,
        DNX_IQS_DB_CREDIT_WATCHDOG_DELETE_TH_INFO,
        DNX_SW_STATE_DIAG_MODIFY,
        NULL);

    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_iqs_db_credit_watchdog_delete_th_get(int unit, uint32 delete_th_idx_0, int *delete_th)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_DNX_IQS_DB__CREDIT_WATCHDOG__DELETE_TH,
        SW_STATE_FUNC_GET,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_DNX_IQS_DB__CREDIT_WATCHDOG__DELETE_TH,
        sw_state_roots_array[unit][DNX_IQS_MODULE_ID]);

    DNX_SW_STATE_OOB_DYNAMIC_ARRAY_CHECK(
        DNX_SW_STATE_DNX_IQS_DB__CREDIT_WATCHDOG__DELETE_TH,
        ((dnx_iqs_db_t*)sw_state_roots_array[unit][DNX_IQS_MODULE_ID])->credit_watchdog.delete_th,
        delete_th_idx_0);

    DNX_SW_STATE_PTR_NULL_CHECK(
        unit,
        DNX_SW_STATE_DNX_IQS_DB__CREDIT_WATCHDOG__DELETE_TH,
        delete_th);

    DNX_SW_STATE_PTR_NULL_CHECK(
        unit,
        DNX_SW_STATE_DNX_IQS_DB__CREDIT_WATCHDOG__DELETE_TH,
        ((dnx_iqs_db_t*)sw_state_roots_array[unit][DNX_IQS_MODULE_ID])->credit_watchdog.delete_th);

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_DNX_IQS_DB__CREDIT_WATCHDOG__DELETE_TH,
        DNX_SW_STATE_DIAG_READ);

    *delete_th = ((dnx_iqs_db_t*)sw_state_roots_array[unit][DNX_IQS_MODULE_ID])->credit_watchdog.delete_th[delete_th_idx_0];
    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_GET_LOGGING,
        BSL_LS_SWSTATEDNX_GET,
        DNX_SW_STATE_DNX_IQS_DB__CREDIT_WATCHDOG__DELETE_TH,
        &((dnx_iqs_db_t*)sw_state_roots_array[unit][DNX_IQS_MODULE_ID])->credit_watchdog.delete_th[delete_th_idx_0],
        "dnx_iqs_db[%d]->credit_watchdog.delete_th[%d]",
        unit, delete_th_idx_0);

    DNX_SW_STATE_DIAG_INFO_POST(
        unit,
        DNX_SW_STATE_DNX_IQS_DB__CREDIT_WATCHDOG__DELETE_TH,
        dnx_iqs_db_info,
        DNX_IQS_DB_CREDIT_WATCHDOG_DELETE_TH_INFO,
        DNX_SW_STATE_DIAG_READ,
        NULL);

    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_iqs_db_credit_watchdog_delete_th_alloc(int unit)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_DNX_IQS_DB__CREDIT_WATCHDOG__DELETE_TH,
        SW_STATE_FUNC_ALLOC,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_DNX_IQS_DB__CREDIT_WATCHDOG__DELETE_TH,
        sw_state_roots_array[unit][DNX_IQS_MODULE_ID]);

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_DNX_IQS_DB__CREDIT_WATCHDOG__DELETE_TH,
        DNX_SW_STATE_DIAG_ALLOC);

    DNX_SW_STATE_ALLOC(
        unit,
        DNX_SW_STATE_DNX_IQS_DB__CREDIT_WATCHDOG__DELETE_TH,
        ((dnx_iqs_db_t*)sw_state_roots_array[unit][DNX_IQS_MODULE_ID])->credit_watchdog.delete_th,
        int,
        dnx_data_iqs.credit.nof_profiles_get(unit),
        DNXC_SW_STATE_DNX_DATA_ALLOC | DNXC_SW_STATE_AUTO_GENERATED_ALLOCATION,
        "dnx_iqs_db_credit_watchdog_delete_th_alloc");

    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_ALLOC_LOGGING,
        BSL_LS_SWSTATEDNX_ALLOC,
        DNX_SW_STATE_DNX_IQS_DB__CREDIT_WATCHDOG__DELETE_TH,
        ((dnx_iqs_db_t*)sw_state_roots_array[unit][DNX_IQS_MODULE_ID])->credit_watchdog.delete_th,
        "dnx_iqs_db[%d]->credit_watchdog.delete_th",
        unit,
        dnx_data_iqs.credit.nof_profiles_get(unit) * sizeof(int) / sizeof(*((dnx_iqs_db_t*)sw_state_roots_array[unit][DNX_IQS_MODULE_ID])->credit_watchdog.delete_th));

    DNX_SW_STATE_DIAG_INFO_POST(
        unit,
        DNX_SW_STATE_DNX_IQS_DB__CREDIT_WATCHDOG__DELETE_TH,
        dnx_iqs_db_info,
        DNX_IQS_DB_CREDIT_WATCHDOG_DELETE_TH_INFO,
        DNX_SW_STATE_DIAG_ALLOC,
        NULL);

    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_iqs_db_delete_credit_request_profile_valid_set(int unit, uint32 valid)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_DNX_IQS_DB__DELETE_CREDIT_REQUEST_PROFILE__VALID,
        SW_STATE_FUNC_SET,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_DNX_IQS_DB__DELETE_CREDIT_REQUEST_PROFILE__VALID,
        sw_state_roots_array[unit][DNX_IQS_MODULE_ID]);

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_DNX_IQS_DB__DELETE_CREDIT_REQUEST_PROFILE__VALID,
        DNX_SW_STATE_DIAG_MODIFY);

    DNX_SW_STATE_SET(
        unit,
        DNX_SW_STATE_DNX_IQS_DB__DELETE_CREDIT_REQUEST_PROFILE__VALID,
        ((dnx_iqs_db_t*)sw_state_roots_array[unit][DNX_IQS_MODULE_ID])->delete_credit_request_profile.valid,
        valid,
        uint32,
        0,
        "dnx_iqs_db_delete_credit_request_profile_valid_set");

    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_SET_LOGGING,
        BSL_LS_SWSTATEDNX_SET,
        DNX_SW_STATE_DNX_IQS_DB__DELETE_CREDIT_REQUEST_PROFILE__VALID,
        &valid,
        "dnx_iqs_db[%d]->delete_credit_request_profile.valid",
        unit);

    DNX_SW_STATE_DIAG_INFO_POST(
        unit,
        DNX_SW_STATE_DNX_IQS_DB__DELETE_CREDIT_REQUEST_PROFILE__VALID,
        dnx_iqs_db_info,
        DNX_IQS_DB_DELETE_CREDIT_REQUEST_PROFILE_VALID_INFO,
        DNX_SW_STATE_DIAG_MODIFY,
        NULL);

    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_iqs_db_delete_credit_request_profile_valid_get(int unit, uint32 *valid)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_DNX_IQS_DB__DELETE_CREDIT_REQUEST_PROFILE__VALID,
        SW_STATE_FUNC_GET,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_DNX_IQS_DB__DELETE_CREDIT_REQUEST_PROFILE__VALID,
        sw_state_roots_array[unit][DNX_IQS_MODULE_ID]);

    DNX_SW_STATE_PTR_NULL_CHECK(
        unit,
        DNX_SW_STATE_DNX_IQS_DB__DELETE_CREDIT_REQUEST_PROFILE__VALID,
        valid);

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_DNX_IQS_DB__DELETE_CREDIT_REQUEST_PROFILE__VALID,
        DNX_SW_STATE_DIAG_READ);

    *valid = ((dnx_iqs_db_t*)sw_state_roots_array[unit][DNX_IQS_MODULE_ID])->delete_credit_request_profile.valid;
    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_GET_LOGGING,
        BSL_LS_SWSTATEDNX_GET,
        DNX_SW_STATE_DNX_IQS_DB__DELETE_CREDIT_REQUEST_PROFILE__VALID,
        &((dnx_iqs_db_t*)sw_state_roots_array[unit][DNX_IQS_MODULE_ID])->delete_credit_request_profile.valid,
        "dnx_iqs_db[%d]->delete_credit_request_profile.valid",
        unit);

    DNX_SW_STATE_DIAG_INFO_POST(
        unit,
        DNX_SW_STATE_DNX_IQS_DB__DELETE_CREDIT_REQUEST_PROFILE__VALID,
        dnx_iqs_db_info,
        DNX_IQS_DB_DELETE_CREDIT_REQUEST_PROFILE_VALID_INFO,
        DNX_SW_STATE_DIAG_READ,
        NULL);

    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_iqs_db_delete_credit_request_profile_id_set(int unit, int id)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_DNX_IQS_DB__DELETE_CREDIT_REQUEST_PROFILE__ID,
        SW_STATE_FUNC_SET,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_DNX_IQS_DB__DELETE_CREDIT_REQUEST_PROFILE__ID,
        sw_state_roots_array[unit][DNX_IQS_MODULE_ID]);

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_DNX_IQS_DB__DELETE_CREDIT_REQUEST_PROFILE__ID,
        DNX_SW_STATE_DIAG_MODIFY);

    DNX_SW_STATE_SET(
        unit,
        DNX_SW_STATE_DNX_IQS_DB__DELETE_CREDIT_REQUEST_PROFILE__ID,
        ((dnx_iqs_db_t*)sw_state_roots_array[unit][DNX_IQS_MODULE_ID])->delete_credit_request_profile.id,
        id,
        int,
        0,
        "dnx_iqs_db_delete_credit_request_profile_id_set");

    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_SET_LOGGING,
        BSL_LS_SWSTATEDNX_SET,
        DNX_SW_STATE_DNX_IQS_DB__DELETE_CREDIT_REQUEST_PROFILE__ID,
        &id,
        "dnx_iqs_db[%d]->delete_credit_request_profile.id",
        unit);

    DNX_SW_STATE_DIAG_INFO_POST(
        unit,
        DNX_SW_STATE_DNX_IQS_DB__DELETE_CREDIT_REQUEST_PROFILE__ID,
        dnx_iqs_db_info,
        DNX_IQS_DB_DELETE_CREDIT_REQUEST_PROFILE_ID_INFO,
        DNX_SW_STATE_DIAG_MODIFY,
        NULL);

    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_iqs_db_delete_credit_request_profile_id_get(int unit, int *id)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_DNX_IQS_DB__DELETE_CREDIT_REQUEST_PROFILE__ID,
        SW_STATE_FUNC_GET,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_DNX_IQS_DB__DELETE_CREDIT_REQUEST_PROFILE__ID,
        sw_state_roots_array[unit][DNX_IQS_MODULE_ID]);

    DNX_SW_STATE_PTR_NULL_CHECK(
        unit,
        DNX_SW_STATE_DNX_IQS_DB__DELETE_CREDIT_REQUEST_PROFILE__ID,
        id);

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_DNX_IQS_DB__DELETE_CREDIT_REQUEST_PROFILE__ID,
        DNX_SW_STATE_DIAG_READ);

    *id = ((dnx_iqs_db_t*)sw_state_roots_array[unit][DNX_IQS_MODULE_ID])->delete_credit_request_profile.id;
    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_GET_LOGGING,
        BSL_LS_SWSTATEDNX_GET,
        DNX_SW_STATE_DNX_IQS_DB__DELETE_CREDIT_REQUEST_PROFILE__ID,
        &((dnx_iqs_db_t*)sw_state_roots_array[unit][DNX_IQS_MODULE_ID])->delete_credit_request_profile.id,
        "dnx_iqs_db[%d]->delete_credit_request_profile.id",
        unit);

    DNX_SW_STATE_DIAG_INFO_POST(
        unit,
        DNX_SW_STATE_DNX_IQS_DB__DELETE_CREDIT_REQUEST_PROFILE__ID,
        dnx_iqs_db_info,
        DNX_IQS_DB_DELETE_CREDIT_REQUEST_PROFILE_ID_INFO,
        DNX_SW_STATE_DIAG_READ,
        NULL);

    DNXC_SW_STATE_FUNC_RETURN;
}





dnx_iqs_db_cbs dnx_iqs_db = 	{
	
	dnx_iqs_db_is_init,
	dnx_iqs_db_init,
		{
		
		dnx_iqs_db_credit_request_profile_alloc,
			{
			
			dnx_iqs_db_credit_request_profile_valid_set,
			dnx_iqs_db_credit_request_profile_valid_get}
		,
			{
			
			dnx_iqs_db_credit_request_profile_thresholds_set,
			dnx_iqs_db_credit_request_profile_thresholds_get}
		}
	,
		{
		
			{
			
			dnx_iqs_db_credit_watchdog_queue_min_set,
			dnx_iqs_db_credit_watchdog_queue_min_get}
		,
			{
			
			dnx_iqs_db_credit_watchdog_queue_max_set,
			dnx_iqs_db_credit_watchdog_queue_max_get}
		,
			{
			
			dnx_iqs_db_credit_watchdog_enable_set,
			dnx_iqs_db_credit_watchdog_enable_get}
		,
			{
			
			dnx_iqs_db_credit_watchdog_retransmit_th_set,
			dnx_iqs_db_credit_watchdog_retransmit_th_get}
		,
			{
			
			dnx_iqs_db_credit_watchdog_delete_th_set,
			dnx_iqs_db_credit_watchdog_delete_th_get,
			dnx_iqs_db_credit_watchdog_delete_th_alloc}
		}
	,
		{
		
			{
			
			dnx_iqs_db_delete_credit_request_profile_valid_set,
			dnx_iqs_db_delete_credit_request_profile_valid_get}
		,
			{
			
			dnx_iqs_db_delete_credit_request_profile_id_set,
			dnx_iqs_db_delete_credit_request_profile_id_get}
		}
	}
;
#undef BSL_LOG_MODULE
