
/*
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2022 Broadcom Inc. All rights reserved.
 */

#ifdef BSL_LOG_MODULE
#error "BSL_LOG_MODULE redefined"
#endif
#define BSL_LOG_MODULE BSL_LS_SWSTATEDNX_GENERAL

#include <soc/dnx/swstate/auto_generated/access/dnx_field_tcam_cache_access.h>
#include <soc/dnx/swstate/auto_generated/diagnostic/dnx_field_tcam_cache_diagnostic.h>
#include <soc/dnx/swstate/auto_generated/layout/dnx_field_tcam_cache_layout.h>





int
dnx_field_tcam_cache_shadow_is_init(int unit, uint8 *is_init)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW,
        SW_STATE_FUNC_IS_INIT,
        DNXC_SW_STATE_NO_FLAGS);

    *is_init = (NULL != ((dnx_field_tcam_cache_shadow_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_CACHE_MODULE_ID]));
    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_IS_INIT_LOGGING,
        BSL_LS_SWSTATEDNX_ISINIT,
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW,
        ((dnx_field_tcam_cache_shadow_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_CACHE_MODULE_ID]),
        "dnx_field_tcam_cache_shadow[%d]",
        unit);

    DNXC_SW_STATE_FUNC_RETURN;
}



int
dnx_field_tcam_cache_shadow_init(int unit)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW,
        SW_STATE_FUNC_INIT,
        DNXC_SW_STATE_NO_FLAGS);

    DNX_SW_STATE_MODULE_INIT(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW,
        DNXC_SW_STATE_IMPLEMENTATION_WB,
        dnx_field_tcam_cache_shadow_t,
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW_NOF_PARAMS,
        DNXC_SW_STATE_AUTO_GENERATED_ALLOCATION,
        "dnx_field_tcam_cache_shadow_init",
        DNX_SW_STATE_DIAG_ALLOC,
        dnx_field_tcam_cache_init_layout_structure);

    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_INIT_LOGGING,
        BSL_LS_SWSTATEDNX_INIT,
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW,
        ((dnx_field_tcam_cache_shadow_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_CACHE_MODULE_ID]),
        "dnx_field_tcam_cache_shadow[%d]",
        unit);

    DNX_SW_STATE_DIAG_INFO_POST(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW,
        dnx_field_tcam_cache_shadow_info,
        DNX_FIELD_TCAM_CACHE_SHADOW_INFO,
        DNX_SW_STATE_DIAG_ALLOC,
        ((dnx_field_tcam_cache_shadow_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_CACHE_MODULE_ID]),
        sw_state_layout_array[unit][DNX_FIELD_TCAM_CACHE_MODULE_ID]);

    DNXC_SW_STATE_FUNC_RETURN;
}



int
dnx_field_tcam_cache_shadow_tcam_bank_alloc(int unit, uint32 nof_instances_to_alloc_1)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW__TCAM_BANK,
        SW_STATE_FUNC_ALLOC,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW__TCAM_BANK,
        sw_state_roots_array[unit][DNX_FIELD_TCAM_CACHE_MODULE_ID]);

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW__TCAM_BANK,
        DNX_SW_STATE_DIAG_ALLOC);

    DNX_SW_STATE_DOUBLE_DYNAMIC_ARRAY_SIZE_CHECK(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW__TCAM_BANK,
        dnx_data_device.general.nof_cores_get(unit),
        nof_instances_to_alloc_1,
        sizeof(dnx_field_tcam_cache_shadow_bank_t*));

    DNX_SW_STATE_AUTOGEN_ALLOC(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW__TCAM_BANK,
        ((dnx_field_tcam_cache_shadow_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_CACHE_MODULE_ID])->tcam_bank,
        dnx_field_tcam_cache_shadow_bank_t*,
        dnx_data_device.general.nof_cores_get(unit),
        sw_state_layout_array[unit][DNX_FIELD_TCAM_CACHE_MODULE_ID],
        DNXC_SWSTATE_LAYOUT_MAX_ARRAY_DIMENSIONS+1,
        DNXC_SW_STATE_DNX_DATA_ALLOC | DNXC_SW_STATE_AUTO_GENERATED_ALLOCATION,
        "dnx_field_tcam_cache_shadow_tcam_bank_alloc");

    for(uint32 tcam_bank_idx_0 = 0;
         tcam_bank_idx_0 < dnx_data_device.general.nof_cores_get(unit);
         tcam_bank_idx_0++)

    DNX_SW_STATE_AUTOGEN_ALLOC(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW__TCAM_BANK,
        ((dnx_field_tcam_cache_shadow_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_CACHE_MODULE_ID])->tcam_bank[tcam_bank_idx_0],
        dnx_field_tcam_cache_shadow_bank_t,
        nof_instances_to_alloc_1,
        sw_state_layout_array[unit][DNX_FIELD_TCAM_CACHE_MODULE_ID],
        1,
        DNXC_SW_STATE_AUTO_GENERATED_ALLOCATION,
        "dnx_field_tcam_cache_shadow_tcam_bank_alloc");

    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_ALLOC_LOGGING,
        BSL_LS_SWSTATEDNX_ALLOC,
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW__TCAM_BANK,
        ((dnx_field_tcam_cache_shadow_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_CACHE_MODULE_ID])->tcam_bank,
        "dnx_field_tcam_cache_shadow[%d]->tcam_bank",
        unit,
        nof_instances_to_alloc_1 * sizeof(dnx_field_tcam_cache_shadow_bank_t) / sizeof(*((dnx_field_tcam_cache_shadow_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_CACHE_MODULE_ID])->tcam_bank)+(nof_instances_to_alloc_1 * sizeof(dnx_field_tcam_cache_shadow_bank_t)));

    DNX_SW_STATE_DIAG_INFO_POST(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW__TCAM_BANK,
        dnx_field_tcam_cache_shadow_info,
        DNX_FIELD_TCAM_CACHE_SHADOW_TCAM_BANK_INFO,
        DNX_SW_STATE_DIAG_ALLOC,
        NULL,
        sw_state_layout_array[unit][DNX_FIELD_TCAM_CACHE_MODULE_ID]);

    DNXC_SW_STATE_FUNC_RETURN;
}



int
dnx_field_tcam_cache_shadow_tcam_bank_entry_key_alloc(int unit, uint32 tcam_bank_idx_0, uint32 tcam_bank_idx_1, uint32 nof_instances_to_alloc_0)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW__TCAM_BANK__ENTRY_KEY,
        SW_STATE_FUNC_ALLOC,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW__TCAM_BANK__ENTRY_KEY,
        sw_state_roots_array[unit][DNX_FIELD_TCAM_CACHE_MODULE_ID]);

    DNX_SW_STATE_OOB_DYNAMIC_ARRAY_CHECK(
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW__TCAM_BANK__ENTRY_KEY,
        ((dnx_field_tcam_cache_shadow_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_CACHE_MODULE_ID])->tcam_bank,
        tcam_bank_idx_0);

    DNX_SW_STATE_PTR_NULL_CHECK(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW__TCAM_BANK__ENTRY_KEY,
        ((dnx_field_tcam_cache_shadow_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_CACHE_MODULE_ID])->tcam_bank[tcam_bank_idx_0]);

    DNX_SW_STATE_OOB_DYNAMIC_ARRAY_CHECK(
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW__TCAM_BANK__ENTRY_KEY,
        ((dnx_field_tcam_cache_shadow_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_CACHE_MODULE_ID])->tcam_bank[tcam_bank_idx_0],
        tcam_bank_idx_1);

    DNX_SWSTATE_ALLOC_SIZE_VERIFY(
        unit,
        sizeof(uint8),
        BITS2BYTES(DNX_DATA_MAX_FIELD_TCAM_ENTRY_SIZE_SINGLE_KEY_SHADOW),
        DNXC_SW_STATE_AUTO_GENERATED_ALLOCATION);

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW__TCAM_BANK__ENTRY_KEY,
        DNX_SW_STATE_DIAG_ALLOC);

    DNX_SW_STATE_AUTOGEN_ALLOC(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW__TCAM_BANK__ENTRY_KEY,
        ((dnx_field_tcam_cache_shadow_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_CACHE_MODULE_ID])->tcam_bank[tcam_bank_idx_0][tcam_bank_idx_1].entry_key,
        dnx_field_tcam_cache_shadow_entry_t,
        nof_instances_to_alloc_0,
        sw_state_layout_array[unit][DNX_FIELD_TCAM_CACHE_MODULE_ID],
        0,
        DNXC_SW_STATE_AUTO_GENERATED_ALLOCATION,
        "dnx_field_tcam_cache_shadow_tcam_bank_entry_key_alloc");

    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_ALLOC_LOGGING,
        BSL_LS_SWSTATEDNX_ALLOC,
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW__TCAM_BANK__ENTRY_KEY,
        ((dnx_field_tcam_cache_shadow_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_CACHE_MODULE_ID])->tcam_bank[tcam_bank_idx_0][tcam_bank_idx_1].entry_key,
        "dnx_field_tcam_cache_shadow[%d]->tcam_bank[%d][%d].entry_key",
        unit, tcam_bank_idx_0, tcam_bank_idx_1,
        nof_instances_to_alloc_0 * sizeof(dnx_field_tcam_cache_shadow_entry_t) / sizeof(*((dnx_field_tcam_cache_shadow_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_CACHE_MODULE_ID])->tcam_bank[tcam_bank_idx_0][tcam_bank_idx_1].entry_key));

    DNX_SW_STATE_DIAG_INFO_POST(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW__TCAM_BANK__ENTRY_KEY,
        dnx_field_tcam_cache_shadow_info,
        DNX_FIELD_TCAM_CACHE_SHADOW_TCAM_BANK_ENTRY_KEY_INFO,
        DNX_SW_STATE_DIAG_ALLOC,
        NULL,
        sw_state_layout_array[unit][DNX_FIELD_TCAM_CACHE_MODULE_ID]);

    DNXC_SW_STATE_FUNC_RETURN;
}



int
dnx_field_tcam_cache_shadow_tcam_bank_entry_key_key_data_set(int unit, uint32 tcam_bank_idx_0, uint32 tcam_bank_idx_1, uint32 entry_key_idx_0, uint32 key_data_idx_0, uint8 key_data)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW__TCAM_BANK__ENTRY_KEY__KEY_DATA,
        SW_STATE_FUNC_SET,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW__TCAM_BANK__ENTRY_KEY__KEY_DATA,
        sw_state_roots_array[unit][DNX_FIELD_TCAM_CACHE_MODULE_ID]);

    DNX_SW_STATE_OOB_DYNAMIC_ARRAY_CHECK(
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW__TCAM_BANK__ENTRY_KEY__KEY_DATA,
        ((dnx_field_tcam_cache_shadow_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_CACHE_MODULE_ID])->tcam_bank,
        tcam_bank_idx_0);

    DNX_SW_STATE_PTR_NULL_CHECK(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW__TCAM_BANK__ENTRY_KEY__KEY_DATA,
        ((dnx_field_tcam_cache_shadow_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_CACHE_MODULE_ID])->tcam_bank[tcam_bank_idx_0][tcam_bank_idx_1].entry_key);

    DNX_SW_STATE_OOB_DYNAMIC_ARRAY_CHECK(
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW__TCAM_BANK__ENTRY_KEY__KEY_DATA,
        ((dnx_field_tcam_cache_shadow_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_CACHE_MODULE_ID])->tcam_bank[tcam_bank_idx_0],
        tcam_bank_idx_1);

    DNX_SW_STATE_PTR_NULL_CHECK(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW__TCAM_BANK__ENTRY_KEY__KEY_DATA,
        ((dnx_field_tcam_cache_shadow_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_CACHE_MODULE_ID])->tcam_bank[tcam_bank_idx_0]);

    DNX_SW_STATE_OOB_DYNAMIC_ARRAY_CHECK(
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW__TCAM_BANK__ENTRY_KEY__KEY_DATA,
        ((dnx_field_tcam_cache_shadow_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_CACHE_MODULE_ID])->tcam_bank[tcam_bank_idx_0][tcam_bank_idx_1].entry_key,
        entry_key_idx_0);

    DNX_SW_STATE_OOB_STATIC_ARRAY_CHECK(
        key_data_idx_0,
        BITS2BYTES(DNX_DATA_MAX_FIELD_TCAM_ENTRY_SIZE_SINGLE_KEY_SHADOW));

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW__TCAM_BANK__ENTRY_KEY__KEY_DATA,
        DNX_SW_STATE_DIAG_MODIFY);

    DNX_SW_STATE_SET(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW__TCAM_BANK__ENTRY_KEY__KEY_DATA,
        ((dnx_field_tcam_cache_shadow_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_CACHE_MODULE_ID])->tcam_bank[tcam_bank_idx_0][tcam_bank_idx_1].entry_key[entry_key_idx_0].key_data[key_data_idx_0],
        key_data,
        uint8,
        0,
        "dnx_field_tcam_cache_shadow_tcam_bank_entry_key_key_data_set");

    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_SET_LOGGING,
        BSL_LS_SWSTATEDNX_SET,
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW__TCAM_BANK__ENTRY_KEY__KEY_DATA,
        &key_data,
        "dnx_field_tcam_cache_shadow[%d]->tcam_bank[%d][%d].entry_key[%d].key_data[%d]",
        unit, tcam_bank_idx_0, tcam_bank_idx_1, entry_key_idx_0, key_data_idx_0);

    DNX_SW_STATE_DIAG_INFO_POST(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW__TCAM_BANK__ENTRY_KEY__KEY_DATA,
        dnx_field_tcam_cache_shadow_info,
        DNX_FIELD_TCAM_CACHE_SHADOW_TCAM_BANK_ENTRY_KEY_KEY_DATA_INFO,
        DNX_SW_STATE_DIAG_MODIFY,
        NULL,
        sw_state_layout_array[unit][DNX_FIELD_TCAM_CACHE_MODULE_ID]);

    DNXC_SW_STATE_FUNC_RETURN;
}



int
dnx_field_tcam_cache_shadow_tcam_bank_entry_key_key_data_get(int unit, uint32 tcam_bank_idx_0, uint32 tcam_bank_idx_1, uint32 entry_key_idx_0, uint32 key_data_idx_0, uint8 *key_data)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW__TCAM_BANK__ENTRY_KEY__KEY_DATA,
        SW_STATE_FUNC_GET,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW__TCAM_BANK__ENTRY_KEY__KEY_DATA,
        sw_state_roots_array[unit][DNX_FIELD_TCAM_CACHE_MODULE_ID]);

    DNX_SW_STATE_OOB_DYNAMIC_ARRAY_CHECK(
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW__TCAM_BANK__ENTRY_KEY__KEY_DATA,
        ((dnx_field_tcam_cache_shadow_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_CACHE_MODULE_ID])->tcam_bank,
        tcam_bank_idx_0);

    DNX_SW_STATE_PTR_NULL_CHECK(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW__TCAM_BANK__ENTRY_KEY__KEY_DATA,
        key_data);

    DNX_SW_STATE_OOB_DYNAMIC_ARRAY_CHECK(
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW__TCAM_BANK__ENTRY_KEY__KEY_DATA,
        ((dnx_field_tcam_cache_shadow_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_CACHE_MODULE_ID])->tcam_bank[tcam_bank_idx_0],
        tcam_bank_idx_1);

    DNX_SW_STATE_PTR_NULL_CHECK(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW__TCAM_BANK__ENTRY_KEY__KEY_DATA,
        ((dnx_field_tcam_cache_shadow_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_CACHE_MODULE_ID])->tcam_bank[tcam_bank_idx_0][tcam_bank_idx_1].entry_key);

    DNX_SW_STATE_OOB_DYNAMIC_ARRAY_CHECK(
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW__TCAM_BANK__ENTRY_KEY__KEY_DATA,
        ((dnx_field_tcam_cache_shadow_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_CACHE_MODULE_ID])->tcam_bank[tcam_bank_idx_0][tcam_bank_idx_1].entry_key,
        entry_key_idx_0);

    DNX_SW_STATE_PTR_NULL_CHECK(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW__TCAM_BANK__ENTRY_KEY__KEY_DATA,
        ((dnx_field_tcam_cache_shadow_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_CACHE_MODULE_ID])->tcam_bank[tcam_bank_idx_0]);

    DNX_SW_STATE_OOB_STATIC_ARRAY_CHECK(
        key_data_idx_0,
        BITS2BYTES(DNX_DATA_MAX_FIELD_TCAM_ENTRY_SIZE_SINGLE_KEY_SHADOW));

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW__TCAM_BANK__ENTRY_KEY__KEY_DATA,
        DNX_SW_STATE_DIAG_READ);

    *key_data = ((dnx_field_tcam_cache_shadow_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_CACHE_MODULE_ID])->tcam_bank[tcam_bank_idx_0][tcam_bank_idx_1].entry_key[entry_key_idx_0].key_data[key_data_idx_0];
    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_GET_LOGGING,
        BSL_LS_SWSTATEDNX_GET,
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW__TCAM_BANK__ENTRY_KEY__KEY_DATA,
        &((dnx_field_tcam_cache_shadow_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_CACHE_MODULE_ID])->tcam_bank[tcam_bank_idx_0][tcam_bank_idx_1].entry_key[entry_key_idx_0].key_data[key_data_idx_0],
        "dnx_field_tcam_cache_shadow[%d]->tcam_bank[%d][%d].entry_key[%d].key_data[%d]",
        unit, tcam_bank_idx_0, tcam_bank_idx_1, entry_key_idx_0, key_data_idx_0);

    DNX_SW_STATE_DIAG_INFO_POST(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW__TCAM_BANK__ENTRY_KEY__KEY_DATA,
        dnx_field_tcam_cache_shadow_info,
        DNX_FIELD_TCAM_CACHE_SHADOW_TCAM_BANK_ENTRY_KEY_KEY_DATA_INFO,
        DNX_SW_STATE_DIAG_READ,
        NULL,
        sw_state_layout_array[unit][DNX_FIELD_TCAM_CACHE_MODULE_ID]);

    DNXC_SW_STATE_FUNC_RETURN;
}



int
dnx_field_tcam_cache_shadow_tcam_bank_entry_key_key_data_range_read(int unit, uint32 tcam_bank_idx_0, uint32 tcam_bank_idx_1, uint32 entry_key_idx_0, uint32 from_idx, uint32 nof_elements, uint8 *dest)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW__TCAM_BANK__ENTRY_KEY__KEY_DATA,
        SW_STATE_FUNC_RANGE_READ,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW__TCAM_BANK__ENTRY_KEY__KEY_DATA,
        sw_state_roots_array[unit][DNX_FIELD_TCAM_CACHE_MODULE_ID]);

    DNX_SW_STATE_PTR_NULL_CHECK(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW__TCAM_BANK__ENTRY_KEY__KEY_DATA,
        ((dnx_field_tcam_cache_shadow_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_CACHE_MODULE_ID])->tcam_bank[tcam_bank_idx_0][tcam_bank_idx_1].entry_key);

    DNX_SW_STATE_PTR_NULL_CHECK(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW__TCAM_BANK__ENTRY_KEY__KEY_DATA,
        ((dnx_field_tcam_cache_shadow_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_CACHE_MODULE_ID])->tcam_bank[tcam_bank_idx_0]);

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW__TCAM_BANK__ENTRY_KEY__KEY_DATA,
        DNX_SW_STATE_DIAG_READ);

    DNX_SW_STATE_RANGE_READ(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW__TCAM_BANK__ENTRY_KEY__KEY_DATA,
        dest,
        ((dnx_field_tcam_cache_shadow_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_CACHE_MODULE_ID])->tcam_bank[tcam_bank_idx_0][tcam_bank_idx_1].entry_key[entry_key_idx_0].key_data,
        uint8,
        from_idx,
        nof_elements,
        0,
        "dnx_field_tcam_cache_shadow_tcam_bank_entry_key_key_data_range_read");

    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_RANGE_READ_LOGGING,
        BSL_LS_SWSTATEDNX_RANGEREAD,
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW__TCAM_BANK__ENTRY_KEY__KEY_DATA,
        ((dnx_field_tcam_cache_shadow_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_CACHE_MODULE_ID])->tcam_bank[tcam_bank_idx_0][tcam_bank_idx_1].entry_key[entry_key_idx_0].key_data,
        "dnx_field_tcam_cache_shadow[%d]->tcam_bank[%d][%d].entry_key[%d].key_data",
        unit, tcam_bank_idx_0, tcam_bank_idx_1, entry_key_idx_0, nof_elements);

    DNX_SW_STATE_DIAG_INFO_POST(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW__TCAM_BANK__ENTRY_KEY__KEY_DATA,
        dnx_field_tcam_cache_shadow_info,
        DNX_FIELD_TCAM_CACHE_SHADOW_TCAM_BANK_ENTRY_KEY_KEY_DATA_INFO,
        DNX_SW_STATE_DIAG_READ,
        NULL,
        sw_state_layout_array[unit][DNX_FIELD_TCAM_CACHE_MODULE_ID]);

    DNXC_SW_STATE_FUNC_RETURN;
}



int
dnx_field_tcam_cache_shadow_tcam_bank_entry_key_key_data_range_write(int unit, uint32 tcam_bank_idx_0, uint32 tcam_bank_idx_1, uint32 entry_key_idx_0, uint32 from_idx, uint32 nof_elements, const uint8 *source)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW__TCAM_BANK__ENTRY_KEY__KEY_DATA,
        SW_STATE_FUNC_RANGE_WRITE,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW__TCAM_BANK__ENTRY_KEY__KEY_DATA,
        sw_state_roots_array[unit][DNX_FIELD_TCAM_CACHE_MODULE_ID]);

    DNX_SW_STATE_PTR_NULL_CHECK(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW__TCAM_BANK__ENTRY_KEY__KEY_DATA,
        ((dnx_field_tcam_cache_shadow_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_CACHE_MODULE_ID])->tcam_bank[tcam_bank_idx_0][tcam_bank_idx_1].entry_key);

    DNX_SW_STATE_PTR_NULL_CHECK(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW__TCAM_BANK__ENTRY_KEY__KEY_DATA,
        ((dnx_field_tcam_cache_shadow_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_CACHE_MODULE_ID])->tcam_bank[tcam_bank_idx_0]);

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW__TCAM_BANK__ENTRY_KEY__KEY_DATA,
        DNX_SW_STATE_DIAG_MODIFY);

    DNX_SW_STATE_RANGE_COPY(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW__TCAM_BANK__ENTRY_KEY__KEY_DATA,
        ((dnx_field_tcam_cache_shadow_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_CACHE_MODULE_ID])->tcam_bank[tcam_bank_idx_0][tcam_bank_idx_1].entry_key[entry_key_idx_0].key_data,
        source,
        uint8,
        from_idx,
        nof_elements,
        0,
        "dnx_field_tcam_cache_shadow_tcam_bank_entry_key_key_data_range_write");

    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_RANGE_WRITE_LOGGING,
        BSL_LS_SWSTATEDNX_RANGEWRITE,
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW__TCAM_BANK__ENTRY_KEY__KEY_DATA,
        ((dnx_field_tcam_cache_shadow_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_CACHE_MODULE_ID])->tcam_bank[tcam_bank_idx_0][tcam_bank_idx_1].entry_key[entry_key_idx_0].key_data,
        "dnx_field_tcam_cache_shadow[%d]->tcam_bank[%d][%d].entry_key[%d].key_data",
        unit, tcam_bank_idx_0, tcam_bank_idx_1, entry_key_idx_0, nof_elements);

    DNX_SW_STATE_DIAG_INFO_POST(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW__TCAM_BANK__ENTRY_KEY__KEY_DATA,
        dnx_field_tcam_cache_shadow_info,
        DNX_FIELD_TCAM_CACHE_SHADOW_TCAM_BANK_ENTRY_KEY_KEY_DATA_INFO,
        DNX_SW_STATE_DIAG_MODIFY,
        NULL,
        sw_state_layout_array[unit][DNX_FIELD_TCAM_CACHE_MODULE_ID]);

    DNXC_SW_STATE_FUNC_RETURN;
}



int
dnx_field_tcam_cache_shadow_tcam_bank_entry_key_key_data_range_fill(int unit, uint32 tcam_bank_idx_0, uint32 tcam_bank_idx_1, uint32 entry_key_idx_0, uint32 from_idx, uint32 nof_elements, uint8 value)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW__TCAM_BANK__ENTRY_KEY__KEY_DATA,
        SW_STATE_FUNC_RANGE_FILL,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW__TCAM_BANK__ENTRY_KEY__KEY_DATA,
        sw_state_roots_array[unit][DNX_FIELD_TCAM_CACHE_MODULE_ID]);

    DNX_SW_STATE_PTR_NULL_CHECK(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW__TCAM_BANK__ENTRY_KEY__KEY_DATA,
        ((dnx_field_tcam_cache_shadow_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_CACHE_MODULE_ID])->tcam_bank[tcam_bank_idx_0][tcam_bank_idx_1].entry_key);

    DNX_SW_STATE_PTR_NULL_CHECK(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW__TCAM_BANK__ENTRY_KEY__KEY_DATA,
        ((dnx_field_tcam_cache_shadow_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_CACHE_MODULE_ID])->tcam_bank[tcam_bank_idx_0]);

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW__TCAM_BANK__ENTRY_KEY__KEY_DATA,
        DNX_SW_STATE_DIAG_MODIFY);

    DNX_SW_STATE_RANGE_FILL(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW__TCAM_BANK__ENTRY_KEY__KEY_DATA,
        ((dnx_field_tcam_cache_shadow_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_CACHE_MODULE_ID])->tcam_bank[tcam_bank_idx_0][tcam_bank_idx_1].entry_key[entry_key_idx_0].key_data,
        uint8,
        from_idx,
        nof_elements,
        value,
        0,
        "dnx_field_tcam_cache_shadow_tcam_bank_entry_key_key_data_range_fill");

    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_RANGE_FILL_LOGGING,
        BSL_LS_SWSTATEDNX_RANGEFILL,
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW__TCAM_BANK__ENTRY_KEY__KEY_DATA,
        ((dnx_field_tcam_cache_shadow_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_CACHE_MODULE_ID])->tcam_bank[tcam_bank_idx_0][tcam_bank_idx_1].entry_key[entry_key_idx_0].key_data,
        "dnx_field_tcam_cache_shadow[%d]->tcam_bank[%d][%d].entry_key[%d].key_data",
        unit, tcam_bank_idx_0, tcam_bank_idx_1, entry_key_idx_0, nof_elements);

    DNX_SW_STATE_DIAG_INFO_POST(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW__TCAM_BANK__ENTRY_KEY__KEY_DATA,
        dnx_field_tcam_cache_shadow_info,
        DNX_FIELD_TCAM_CACHE_SHADOW_TCAM_BANK_ENTRY_KEY_KEY_DATA_INFO,
        DNX_SW_STATE_DIAG_MODIFY,
        NULL,
        sw_state_layout_array[unit][DNX_FIELD_TCAM_CACHE_MODULE_ID]);

    DNXC_SW_STATE_FUNC_RETURN;
}



int
dnx_field_tcam_cache_shadow_payload_table_alloc(int unit, uint32 nof_instances_to_alloc_1)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW__PAYLOAD_TABLE,
        SW_STATE_FUNC_ALLOC,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW__PAYLOAD_TABLE,
        sw_state_roots_array[unit][DNX_FIELD_TCAM_CACHE_MODULE_ID]);

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW__PAYLOAD_TABLE,
        DNX_SW_STATE_DIAG_ALLOC);

    DNX_SW_STATE_DOUBLE_DYNAMIC_ARRAY_SIZE_CHECK(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW__PAYLOAD_TABLE,
        dnx_data_device.general.nof_cores_get(unit),
        nof_instances_to_alloc_1,
        sizeof(dnx_field_tcam_cache_shadow_payload_table_t*));

    DNX_SW_STATE_AUTOGEN_ALLOC(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW__PAYLOAD_TABLE,
        ((dnx_field_tcam_cache_shadow_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_CACHE_MODULE_ID])->payload_table,
        dnx_field_tcam_cache_shadow_payload_table_t*,
        dnx_data_device.general.nof_cores_get(unit),
        sw_state_layout_array[unit][DNX_FIELD_TCAM_CACHE_MODULE_ID],
        DNXC_SWSTATE_LAYOUT_MAX_ARRAY_DIMENSIONS+1,
        DNXC_SW_STATE_DNX_DATA_ALLOC | DNXC_SW_STATE_AUTO_GENERATED_ALLOCATION,
        "dnx_field_tcam_cache_shadow_payload_table_alloc");

    for(uint32 payload_table_idx_0 = 0;
         payload_table_idx_0 < dnx_data_device.general.nof_cores_get(unit);
         payload_table_idx_0++)

    DNX_SW_STATE_AUTOGEN_ALLOC(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW__PAYLOAD_TABLE,
        ((dnx_field_tcam_cache_shadow_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_CACHE_MODULE_ID])->payload_table[payload_table_idx_0],
        dnx_field_tcam_cache_shadow_payload_table_t,
        nof_instances_to_alloc_1,
        sw_state_layout_array[unit][DNX_FIELD_TCAM_CACHE_MODULE_ID],
        1,
        DNXC_SW_STATE_AUTO_GENERATED_ALLOCATION,
        "dnx_field_tcam_cache_shadow_payload_table_alloc");

    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_ALLOC_LOGGING,
        BSL_LS_SWSTATEDNX_ALLOC,
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW__PAYLOAD_TABLE,
        ((dnx_field_tcam_cache_shadow_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_CACHE_MODULE_ID])->payload_table,
        "dnx_field_tcam_cache_shadow[%d]->payload_table",
        unit,
        nof_instances_to_alloc_1 * sizeof(dnx_field_tcam_cache_shadow_payload_table_t) / sizeof(*((dnx_field_tcam_cache_shadow_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_CACHE_MODULE_ID])->payload_table)+(nof_instances_to_alloc_1 * sizeof(dnx_field_tcam_cache_shadow_payload_table_t)));

    DNX_SW_STATE_DIAG_INFO_POST(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW__PAYLOAD_TABLE,
        dnx_field_tcam_cache_shadow_info,
        DNX_FIELD_TCAM_CACHE_SHADOW_PAYLOAD_TABLE_INFO,
        DNX_SW_STATE_DIAG_ALLOC,
        NULL,
        sw_state_layout_array[unit][DNX_FIELD_TCAM_CACHE_MODULE_ID]);

    DNXC_SW_STATE_FUNC_RETURN;
}



int
dnx_field_tcam_cache_shadow_payload_table_entry_payload_alloc(int unit, uint32 payload_table_idx_0, uint32 payload_table_idx_1, uint32 nof_instances_to_alloc_0)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW__PAYLOAD_TABLE__ENTRY_PAYLOAD,
        SW_STATE_FUNC_ALLOC,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW__PAYLOAD_TABLE__ENTRY_PAYLOAD,
        sw_state_roots_array[unit][DNX_FIELD_TCAM_CACHE_MODULE_ID]);

    DNX_SW_STATE_OOB_DYNAMIC_ARRAY_CHECK(
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW__PAYLOAD_TABLE__ENTRY_PAYLOAD,
        ((dnx_field_tcam_cache_shadow_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_CACHE_MODULE_ID])->payload_table,
        payload_table_idx_0);

    DNX_SW_STATE_PTR_NULL_CHECK(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW__PAYLOAD_TABLE__ENTRY_PAYLOAD,
        ((dnx_field_tcam_cache_shadow_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_CACHE_MODULE_ID])->payload_table[payload_table_idx_0]);

    DNX_SW_STATE_OOB_DYNAMIC_ARRAY_CHECK(
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW__PAYLOAD_TABLE__ENTRY_PAYLOAD,
        ((dnx_field_tcam_cache_shadow_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_CACHE_MODULE_ID])->payload_table[payload_table_idx_0],
        payload_table_idx_1);

    DNX_SWSTATE_ALLOC_SIZE_VERIFY(
        unit,
        sizeof(uint8),
        BITS2BYTES(DNX_DATA_MAX_FIELD_TCAM_ACTION_SIZE_HALF),
        DNXC_SW_STATE_AUTO_GENERATED_ALLOCATION);

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW__PAYLOAD_TABLE__ENTRY_PAYLOAD,
        DNX_SW_STATE_DIAG_ALLOC);

    DNX_SW_STATE_AUTOGEN_ALLOC(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW__PAYLOAD_TABLE__ENTRY_PAYLOAD,
        ((dnx_field_tcam_cache_shadow_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_CACHE_MODULE_ID])->payload_table[payload_table_idx_0][payload_table_idx_1].entry_payload,
        dnx_field_tcam_cache_shadow_payload_entry_t,
        nof_instances_to_alloc_0,
        sw_state_layout_array[unit][DNX_FIELD_TCAM_CACHE_MODULE_ID],
        0,
        DNXC_SW_STATE_AUTO_GENERATED_ALLOCATION,
        "dnx_field_tcam_cache_shadow_payload_table_entry_payload_alloc");

    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_ALLOC_LOGGING,
        BSL_LS_SWSTATEDNX_ALLOC,
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW__PAYLOAD_TABLE__ENTRY_PAYLOAD,
        ((dnx_field_tcam_cache_shadow_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_CACHE_MODULE_ID])->payload_table[payload_table_idx_0][payload_table_idx_1].entry_payload,
        "dnx_field_tcam_cache_shadow[%d]->payload_table[%d][%d].entry_payload",
        unit, payload_table_idx_0, payload_table_idx_1,
        nof_instances_to_alloc_0 * sizeof(dnx_field_tcam_cache_shadow_payload_entry_t) / sizeof(*((dnx_field_tcam_cache_shadow_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_CACHE_MODULE_ID])->payload_table[payload_table_idx_0][payload_table_idx_1].entry_payload));

    DNX_SW_STATE_DIAG_INFO_POST(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW__PAYLOAD_TABLE__ENTRY_PAYLOAD,
        dnx_field_tcam_cache_shadow_info,
        DNX_FIELD_TCAM_CACHE_SHADOW_PAYLOAD_TABLE_ENTRY_PAYLOAD_INFO,
        DNX_SW_STATE_DIAG_ALLOC,
        NULL,
        sw_state_layout_array[unit][DNX_FIELD_TCAM_CACHE_MODULE_ID]);

    DNXC_SW_STATE_FUNC_RETURN;
}



int
dnx_field_tcam_cache_shadow_payload_table_entry_payload_payload_data_set(int unit, uint32 payload_table_idx_0, uint32 payload_table_idx_1, uint32 entry_payload_idx_0, uint32 payload_data_idx_0, uint8 payload_data)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW__PAYLOAD_TABLE__ENTRY_PAYLOAD__PAYLOAD_DATA,
        SW_STATE_FUNC_SET,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW__PAYLOAD_TABLE__ENTRY_PAYLOAD__PAYLOAD_DATA,
        sw_state_roots_array[unit][DNX_FIELD_TCAM_CACHE_MODULE_ID]);

    DNX_SW_STATE_OOB_DYNAMIC_ARRAY_CHECK(
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW__PAYLOAD_TABLE__ENTRY_PAYLOAD__PAYLOAD_DATA,
        ((dnx_field_tcam_cache_shadow_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_CACHE_MODULE_ID])->payload_table,
        payload_table_idx_0);

    DNX_SW_STATE_PTR_NULL_CHECK(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW__PAYLOAD_TABLE__ENTRY_PAYLOAD__PAYLOAD_DATA,
        ((dnx_field_tcam_cache_shadow_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_CACHE_MODULE_ID])->payload_table[payload_table_idx_0][payload_table_idx_1].entry_payload);

    DNX_SW_STATE_OOB_DYNAMIC_ARRAY_CHECK(
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW__PAYLOAD_TABLE__ENTRY_PAYLOAD__PAYLOAD_DATA,
        ((dnx_field_tcam_cache_shadow_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_CACHE_MODULE_ID])->payload_table[payload_table_idx_0],
        payload_table_idx_1);

    DNX_SW_STATE_PTR_NULL_CHECK(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW__PAYLOAD_TABLE__ENTRY_PAYLOAD__PAYLOAD_DATA,
        ((dnx_field_tcam_cache_shadow_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_CACHE_MODULE_ID])->payload_table[payload_table_idx_0]);

    DNX_SW_STATE_OOB_DYNAMIC_ARRAY_CHECK(
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW__PAYLOAD_TABLE__ENTRY_PAYLOAD__PAYLOAD_DATA,
        ((dnx_field_tcam_cache_shadow_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_CACHE_MODULE_ID])->payload_table[payload_table_idx_0][payload_table_idx_1].entry_payload,
        entry_payload_idx_0);

    DNX_SW_STATE_OOB_STATIC_ARRAY_CHECK(
        payload_data_idx_0,
        BITS2BYTES(DNX_DATA_MAX_FIELD_TCAM_ACTION_SIZE_HALF));

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW__PAYLOAD_TABLE__ENTRY_PAYLOAD__PAYLOAD_DATA,
        DNX_SW_STATE_DIAG_MODIFY);

    DNX_SW_STATE_SET(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW__PAYLOAD_TABLE__ENTRY_PAYLOAD__PAYLOAD_DATA,
        ((dnx_field_tcam_cache_shadow_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_CACHE_MODULE_ID])->payload_table[payload_table_idx_0][payload_table_idx_1].entry_payload[entry_payload_idx_0].payload_data[payload_data_idx_0],
        payload_data,
        uint8,
        0,
        "dnx_field_tcam_cache_shadow_payload_table_entry_payload_payload_data_set");

    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_SET_LOGGING,
        BSL_LS_SWSTATEDNX_SET,
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW__PAYLOAD_TABLE__ENTRY_PAYLOAD__PAYLOAD_DATA,
        &payload_data,
        "dnx_field_tcam_cache_shadow[%d]->payload_table[%d][%d].entry_payload[%d].payload_data[%d]",
        unit, payload_table_idx_0, payload_table_idx_1, entry_payload_idx_0, payload_data_idx_0);

    DNX_SW_STATE_DIAG_INFO_POST(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW__PAYLOAD_TABLE__ENTRY_PAYLOAD__PAYLOAD_DATA,
        dnx_field_tcam_cache_shadow_info,
        DNX_FIELD_TCAM_CACHE_SHADOW_PAYLOAD_TABLE_ENTRY_PAYLOAD_PAYLOAD_DATA_INFO,
        DNX_SW_STATE_DIAG_MODIFY,
        NULL,
        sw_state_layout_array[unit][DNX_FIELD_TCAM_CACHE_MODULE_ID]);

    DNXC_SW_STATE_FUNC_RETURN;
}



int
dnx_field_tcam_cache_shadow_payload_table_entry_payload_payload_data_get(int unit, uint32 payload_table_idx_0, uint32 payload_table_idx_1, uint32 entry_payload_idx_0, uint32 payload_data_idx_0, uint8 *payload_data)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW__PAYLOAD_TABLE__ENTRY_PAYLOAD__PAYLOAD_DATA,
        SW_STATE_FUNC_GET,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW__PAYLOAD_TABLE__ENTRY_PAYLOAD__PAYLOAD_DATA,
        sw_state_roots_array[unit][DNX_FIELD_TCAM_CACHE_MODULE_ID]);

    DNX_SW_STATE_OOB_DYNAMIC_ARRAY_CHECK(
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW__PAYLOAD_TABLE__ENTRY_PAYLOAD__PAYLOAD_DATA,
        ((dnx_field_tcam_cache_shadow_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_CACHE_MODULE_ID])->payload_table,
        payload_table_idx_0);

    DNX_SW_STATE_PTR_NULL_CHECK(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW__PAYLOAD_TABLE__ENTRY_PAYLOAD__PAYLOAD_DATA,
        payload_data);

    DNX_SW_STATE_OOB_DYNAMIC_ARRAY_CHECK(
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW__PAYLOAD_TABLE__ENTRY_PAYLOAD__PAYLOAD_DATA,
        ((dnx_field_tcam_cache_shadow_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_CACHE_MODULE_ID])->payload_table[payload_table_idx_0],
        payload_table_idx_1);

    DNX_SW_STATE_PTR_NULL_CHECK(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW__PAYLOAD_TABLE__ENTRY_PAYLOAD__PAYLOAD_DATA,
        ((dnx_field_tcam_cache_shadow_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_CACHE_MODULE_ID])->payload_table[payload_table_idx_0][payload_table_idx_1].entry_payload);

    DNX_SW_STATE_OOB_DYNAMIC_ARRAY_CHECK(
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW__PAYLOAD_TABLE__ENTRY_PAYLOAD__PAYLOAD_DATA,
        ((dnx_field_tcam_cache_shadow_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_CACHE_MODULE_ID])->payload_table[payload_table_idx_0][payload_table_idx_1].entry_payload,
        entry_payload_idx_0);

    DNX_SW_STATE_PTR_NULL_CHECK(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW__PAYLOAD_TABLE__ENTRY_PAYLOAD__PAYLOAD_DATA,
        ((dnx_field_tcam_cache_shadow_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_CACHE_MODULE_ID])->payload_table[payload_table_idx_0]);

    DNX_SW_STATE_OOB_STATIC_ARRAY_CHECK(
        payload_data_idx_0,
        BITS2BYTES(DNX_DATA_MAX_FIELD_TCAM_ACTION_SIZE_HALF));

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW__PAYLOAD_TABLE__ENTRY_PAYLOAD__PAYLOAD_DATA,
        DNX_SW_STATE_DIAG_READ);

    *payload_data = ((dnx_field_tcam_cache_shadow_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_CACHE_MODULE_ID])->payload_table[payload_table_idx_0][payload_table_idx_1].entry_payload[entry_payload_idx_0].payload_data[payload_data_idx_0];
    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_GET_LOGGING,
        BSL_LS_SWSTATEDNX_GET,
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW__PAYLOAD_TABLE__ENTRY_PAYLOAD__PAYLOAD_DATA,
        &((dnx_field_tcam_cache_shadow_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_CACHE_MODULE_ID])->payload_table[payload_table_idx_0][payload_table_idx_1].entry_payload[entry_payload_idx_0].payload_data[payload_data_idx_0],
        "dnx_field_tcam_cache_shadow[%d]->payload_table[%d][%d].entry_payload[%d].payload_data[%d]",
        unit, payload_table_idx_0, payload_table_idx_1, entry_payload_idx_0, payload_data_idx_0);

    DNX_SW_STATE_DIAG_INFO_POST(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW__PAYLOAD_TABLE__ENTRY_PAYLOAD__PAYLOAD_DATA,
        dnx_field_tcam_cache_shadow_info,
        DNX_FIELD_TCAM_CACHE_SHADOW_PAYLOAD_TABLE_ENTRY_PAYLOAD_PAYLOAD_DATA_INFO,
        DNX_SW_STATE_DIAG_READ,
        NULL,
        sw_state_layout_array[unit][DNX_FIELD_TCAM_CACHE_MODULE_ID]);

    DNXC_SW_STATE_FUNC_RETURN;
}



int
dnx_field_tcam_cache_shadow_payload_table_entry_payload_payload_data_range_read(int unit, uint32 payload_table_idx_0, uint32 payload_table_idx_1, uint32 entry_payload_idx_0, uint32 from_idx, uint32 nof_elements, uint8 *dest)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW__PAYLOAD_TABLE__ENTRY_PAYLOAD__PAYLOAD_DATA,
        SW_STATE_FUNC_RANGE_READ,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW__PAYLOAD_TABLE__ENTRY_PAYLOAD__PAYLOAD_DATA,
        sw_state_roots_array[unit][DNX_FIELD_TCAM_CACHE_MODULE_ID]);

    DNX_SW_STATE_PTR_NULL_CHECK(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW__PAYLOAD_TABLE__ENTRY_PAYLOAD__PAYLOAD_DATA,
        ((dnx_field_tcam_cache_shadow_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_CACHE_MODULE_ID])->payload_table[payload_table_idx_0][payload_table_idx_1].entry_payload);

    DNX_SW_STATE_PTR_NULL_CHECK(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW__PAYLOAD_TABLE__ENTRY_PAYLOAD__PAYLOAD_DATA,
        ((dnx_field_tcam_cache_shadow_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_CACHE_MODULE_ID])->payload_table[payload_table_idx_0]);

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW__PAYLOAD_TABLE__ENTRY_PAYLOAD__PAYLOAD_DATA,
        DNX_SW_STATE_DIAG_READ);

    DNX_SW_STATE_RANGE_READ(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW__PAYLOAD_TABLE__ENTRY_PAYLOAD__PAYLOAD_DATA,
        dest,
        ((dnx_field_tcam_cache_shadow_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_CACHE_MODULE_ID])->payload_table[payload_table_idx_0][payload_table_idx_1].entry_payload[entry_payload_idx_0].payload_data,
        uint8,
        from_idx,
        nof_elements,
        0,
        "dnx_field_tcam_cache_shadow_payload_table_entry_payload_payload_data_range_read");

    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_RANGE_READ_LOGGING,
        BSL_LS_SWSTATEDNX_RANGEREAD,
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW__PAYLOAD_TABLE__ENTRY_PAYLOAD__PAYLOAD_DATA,
        ((dnx_field_tcam_cache_shadow_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_CACHE_MODULE_ID])->payload_table[payload_table_idx_0][payload_table_idx_1].entry_payload[entry_payload_idx_0].payload_data,
        "dnx_field_tcam_cache_shadow[%d]->payload_table[%d][%d].entry_payload[%d].payload_data",
        unit, payload_table_idx_0, payload_table_idx_1, entry_payload_idx_0, nof_elements);

    DNX_SW_STATE_DIAG_INFO_POST(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW__PAYLOAD_TABLE__ENTRY_PAYLOAD__PAYLOAD_DATA,
        dnx_field_tcam_cache_shadow_info,
        DNX_FIELD_TCAM_CACHE_SHADOW_PAYLOAD_TABLE_ENTRY_PAYLOAD_PAYLOAD_DATA_INFO,
        DNX_SW_STATE_DIAG_READ,
        NULL,
        sw_state_layout_array[unit][DNX_FIELD_TCAM_CACHE_MODULE_ID]);

    DNXC_SW_STATE_FUNC_RETURN;
}



int
dnx_field_tcam_cache_shadow_payload_table_entry_payload_payload_data_range_write(int unit, uint32 payload_table_idx_0, uint32 payload_table_idx_1, uint32 entry_payload_idx_0, uint32 from_idx, uint32 nof_elements, const uint8 *source)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW__PAYLOAD_TABLE__ENTRY_PAYLOAD__PAYLOAD_DATA,
        SW_STATE_FUNC_RANGE_WRITE,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW__PAYLOAD_TABLE__ENTRY_PAYLOAD__PAYLOAD_DATA,
        sw_state_roots_array[unit][DNX_FIELD_TCAM_CACHE_MODULE_ID]);

    DNX_SW_STATE_PTR_NULL_CHECK(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW__PAYLOAD_TABLE__ENTRY_PAYLOAD__PAYLOAD_DATA,
        ((dnx_field_tcam_cache_shadow_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_CACHE_MODULE_ID])->payload_table[payload_table_idx_0][payload_table_idx_1].entry_payload);

    DNX_SW_STATE_PTR_NULL_CHECK(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW__PAYLOAD_TABLE__ENTRY_PAYLOAD__PAYLOAD_DATA,
        ((dnx_field_tcam_cache_shadow_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_CACHE_MODULE_ID])->payload_table[payload_table_idx_0]);

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW__PAYLOAD_TABLE__ENTRY_PAYLOAD__PAYLOAD_DATA,
        DNX_SW_STATE_DIAG_MODIFY);

    DNX_SW_STATE_RANGE_COPY(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW__PAYLOAD_TABLE__ENTRY_PAYLOAD__PAYLOAD_DATA,
        ((dnx_field_tcam_cache_shadow_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_CACHE_MODULE_ID])->payload_table[payload_table_idx_0][payload_table_idx_1].entry_payload[entry_payload_idx_0].payload_data,
        source,
        uint8,
        from_idx,
        nof_elements,
        0,
        "dnx_field_tcam_cache_shadow_payload_table_entry_payload_payload_data_range_write");

    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_RANGE_WRITE_LOGGING,
        BSL_LS_SWSTATEDNX_RANGEWRITE,
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW__PAYLOAD_TABLE__ENTRY_PAYLOAD__PAYLOAD_DATA,
        ((dnx_field_tcam_cache_shadow_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_CACHE_MODULE_ID])->payload_table[payload_table_idx_0][payload_table_idx_1].entry_payload[entry_payload_idx_0].payload_data,
        "dnx_field_tcam_cache_shadow[%d]->payload_table[%d][%d].entry_payload[%d].payload_data",
        unit, payload_table_idx_0, payload_table_idx_1, entry_payload_idx_0, nof_elements);

    DNX_SW_STATE_DIAG_INFO_POST(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW__PAYLOAD_TABLE__ENTRY_PAYLOAD__PAYLOAD_DATA,
        dnx_field_tcam_cache_shadow_info,
        DNX_FIELD_TCAM_CACHE_SHADOW_PAYLOAD_TABLE_ENTRY_PAYLOAD_PAYLOAD_DATA_INFO,
        DNX_SW_STATE_DIAG_MODIFY,
        NULL,
        sw_state_layout_array[unit][DNX_FIELD_TCAM_CACHE_MODULE_ID]);

    DNXC_SW_STATE_FUNC_RETURN;
}



int
dnx_field_tcam_cache_shadow_payload_table_entry_payload_payload_data_range_fill(int unit, uint32 payload_table_idx_0, uint32 payload_table_idx_1, uint32 entry_payload_idx_0, uint32 from_idx, uint32 nof_elements, uint8 value)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW__PAYLOAD_TABLE__ENTRY_PAYLOAD__PAYLOAD_DATA,
        SW_STATE_FUNC_RANGE_FILL,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW__PAYLOAD_TABLE__ENTRY_PAYLOAD__PAYLOAD_DATA,
        sw_state_roots_array[unit][DNX_FIELD_TCAM_CACHE_MODULE_ID]);

    DNX_SW_STATE_PTR_NULL_CHECK(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW__PAYLOAD_TABLE__ENTRY_PAYLOAD__PAYLOAD_DATA,
        ((dnx_field_tcam_cache_shadow_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_CACHE_MODULE_ID])->payload_table[payload_table_idx_0][payload_table_idx_1].entry_payload);

    DNX_SW_STATE_PTR_NULL_CHECK(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW__PAYLOAD_TABLE__ENTRY_PAYLOAD__PAYLOAD_DATA,
        ((dnx_field_tcam_cache_shadow_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_CACHE_MODULE_ID])->payload_table[payload_table_idx_0]);

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW__PAYLOAD_TABLE__ENTRY_PAYLOAD__PAYLOAD_DATA,
        DNX_SW_STATE_DIAG_MODIFY);

    DNX_SW_STATE_RANGE_FILL(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW__PAYLOAD_TABLE__ENTRY_PAYLOAD__PAYLOAD_DATA,
        ((dnx_field_tcam_cache_shadow_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_CACHE_MODULE_ID])->payload_table[payload_table_idx_0][payload_table_idx_1].entry_payload[entry_payload_idx_0].payload_data,
        uint8,
        from_idx,
        nof_elements,
        value,
        0,
        "dnx_field_tcam_cache_shadow_payload_table_entry_payload_payload_data_range_fill");

    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_RANGE_FILL_LOGGING,
        BSL_LS_SWSTATEDNX_RANGEFILL,
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW__PAYLOAD_TABLE__ENTRY_PAYLOAD__PAYLOAD_DATA,
        ((dnx_field_tcam_cache_shadow_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_CACHE_MODULE_ID])->payload_table[payload_table_idx_0][payload_table_idx_1].entry_payload[entry_payload_idx_0].payload_data,
        "dnx_field_tcam_cache_shadow[%d]->payload_table[%d][%d].entry_payload[%d].payload_data",
        unit, payload_table_idx_0, payload_table_idx_1, entry_payload_idx_0, nof_elements);

    DNX_SW_STATE_DIAG_INFO_POST(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_CACHE_SHADOW__PAYLOAD_TABLE__ENTRY_PAYLOAD__PAYLOAD_DATA,
        dnx_field_tcam_cache_shadow_info,
        DNX_FIELD_TCAM_CACHE_SHADOW_PAYLOAD_TABLE_ENTRY_PAYLOAD_PAYLOAD_DATA_INFO,
        DNX_SW_STATE_DIAG_MODIFY,
        NULL,
        sw_state_layout_array[unit][DNX_FIELD_TCAM_CACHE_MODULE_ID]);

    DNXC_SW_STATE_FUNC_RETURN;
}




dnx_field_tcam_cache_shadow_cbs dnx_field_tcam_cache_shadow = 	{
	
	dnx_field_tcam_cache_shadow_is_init,
	dnx_field_tcam_cache_shadow_init,
		{
		
		dnx_field_tcam_cache_shadow_tcam_bank_alloc,
			{
			
			dnx_field_tcam_cache_shadow_tcam_bank_entry_key_alloc,
				{
				
				dnx_field_tcam_cache_shadow_tcam_bank_entry_key_key_data_set,
				dnx_field_tcam_cache_shadow_tcam_bank_entry_key_key_data_get,
				dnx_field_tcam_cache_shadow_tcam_bank_entry_key_key_data_range_read,
				dnx_field_tcam_cache_shadow_tcam_bank_entry_key_key_data_range_write,
				dnx_field_tcam_cache_shadow_tcam_bank_entry_key_key_data_range_fill}
			}
		}
	,
		{
		
		dnx_field_tcam_cache_shadow_payload_table_alloc,
			{
			
			dnx_field_tcam_cache_shadow_payload_table_entry_payload_alloc,
				{
				
				dnx_field_tcam_cache_shadow_payload_table_entry_payload_payload_data_set,
				dnx_field_tcam_cache_shadow_payload_table_entry_payload_payload_data_get,
				dnx_field_tcam_cache_shadow_payload_table_entry_payload_payload_data_range_read,
				dnx_field_tcam_cache_shadow_payload_table_entry_payload_payload_data_range_write,
				dnx_field_tcam_cache_shadow_payload_table_entry_payload_payload_data_range_fill}
			}
		}
	}
;
#undef BSL_LOG_MODULE
