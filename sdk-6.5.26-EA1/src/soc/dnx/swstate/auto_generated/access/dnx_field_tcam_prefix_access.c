
/*
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2022 Broadcom Inc. All rights reserved.
 */

#ifdef BSL_LOG_MODULE
#error "BSL_LOG_MODULE redefined"
#endif
#define BSL_LOG_MODULE BSL_LS_SWSTATEDNX_GENERAL

#include <soc/dnx/swstate/auto_generated/access/dnx_field_tcam_prefix_access.h>
#include <soc/dnx/swstate/auto_generated/diagnostic/dnx_field_tcam_prefix_diagnostic.h>
#include <soc/dnx/swstate/auto_generated/layout/dnx_field_tcam_prefix_layout.h>





int
dnx_field_tcam_prefix_sw_is_init(int unit, uint8 *is_init)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_PREFIX_SW,
        SW_STATE_FUNC_IS_INIT,
        DNXC_SW_STATE_NO_FLAGS);

    *is_init = (NULL != ((dnx_field_tcam_prefix_sw_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_PREFIX_MODULE_ID]));
    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_IS_INIT_LOGGING,
        BSL_LS_SWSTATEDNX_ISINIT,
        DNX_SW_STATE_DNX_FIELD_TCAM_PREFIX_SW,
        ((dnx_field_tcam_prefix_sw_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_PREFIX_MODULE_ID]),
        "dnx_field_tcam_prefix_sw[%d]",
        unit);

    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_field_tcam_prefix_sw_init(int unit)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_PREFIX_SW,
        SW_STATE_FUNC_INIT,
        DNXC_SW_STATE_NO_FLAGS);

    DNX_SW_STATE_MODULE_INIT(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_PREFIX_SW,
        DNXC_SW_STATE_IMPLEMENTATION_WB,
        dnx_field_tcam_prefix_sw_t,
        DNX_SW_STATE_DNX_FIELD_TCAM_PREFIX_SW_NOF_PARAMS,
        DNXC_SW_STATE_AUTO_GENERATED_ALLOCATION,
        "dnx_field_tcam_prefix_sw_init",
        DNX_SW_STATE_DIAG_ALLOC,
        dnx_field_tcam_prefix_init_layout_structure);

    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_INIT_LOGGING,
        BSL_LS_SWSTATEDNX_INIT,
        DNX_SW_STATE_DNX_FIELD_TCAM_PREFIX_SW,
        ((dnx_field_tcam_prefix_sw_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_PREFIX_MODULE_ID]),
        "dnx_field_tcam_prefix_sw[%d]",
        unit);

    DNX_SW_STATE_DIAG_INFO_POST(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_PREFIX_SW,
        dnx_field_tcam_prefix_sw_info,
        DNX_FIELD_TCAM_PREFIX_SW_INFO,
        DNX_SW_STATE_DIAG_ALLOC,
        ((dnx_field_tcam_prefix_sw_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_PREFIX_MODULE_ID]));

    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_field_tcam_prefix_sw_banks_prefix_alloc(int unit)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_PREFIX_SW__BANKS_PREFIX,
        SW_STATE_FUNC_ALLOC,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_PREFIX_SW__BANKS_PREFIX,
        sw_state_roots_array[unit][DNX_FIELD_TCAM_PREFIX_MODULE_ID]);

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_PREFIX_SW__BANKS_PREFIX,
        DNX_SW_STATE_DIAG_ALLOC);

    DNX_SW_STATE_ALLOC(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_PREFIX_SW__BANKS_PREFIX,
        ((dnx_field_tcam_prefix_sw_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_PREFIX_MODULE_ID])->banks_prefix,
        dnx_field_tcam_core_prefix_t,
        dnx_data_field.tcam.nof_banks_get(unit),
        DNXC_SW_STATE_DNX_DATA_ALLOC | DNXC_SW_STATE_AUTO_GENERATED_ALLOCATION,
        "dnx_field_tcam_prefix_sw_banks_prefix_alloc");

    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_ALLOC_LOGGING,
        BSL_LS_SWSTATEDNX_ALLOC,
        DNX_SW_STATE_DNX_FIELD_TCAM_PREFIX_SW__BANKS_PREFIX,
        ((dnx_field_tcam_prefix_sw_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_PREFIX_MODULE_ID])->banks_prefix,
        "dnx_field_tcam_prefix_sw[%d]->banks_prefix",
        unit,
        dnx_data_field.tcam.nof_banks_get(unit) * sizeof(dnx_field_tcam_core_prefix_t) / sizeof(*((dnx_field_tcam_prefix_sw_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_PREFIX_MODULE_ID])->banks_prefix));

    DNX_SW_STATE_DIAG_INFO_POST(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_PREFIX_SW__BANKS_PREFIX,
        dnx_field_tcam_prefix_sw_info,
        DNX_FIELD_TCAM_PREFIX_SW_BANKS_PREFIX_INFO,
        DNX_SW_STATE_DIAG_ALLOC,
        NULL);

    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_field_tcam_prefix_sw_banks_prefix_core_prefix_map_alloc(int unit, uint32 banks_prefix_idx_0)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_PREFIX_SW__BANKS_PREFIX__CORE_PREFIX_MAP,
        SW_STATE_FUNC_ALLOC,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_PREFIX_SW__BANKS_PREFIX__CORE_PREFIX_MAP,
        sw_state_roots_array[unit][DNX_FIELD_TCAM_PREFIX_MODULE_ID]);

    DNX_SW_STATE_OOB_DYNAMIC_ARRAY_CHECK(
        DNX_SW_STATE_DNX_FIELD_TCAM_PREFIX_SW__BANKS_PREFIX__CORE_PREFIX_MAP,
        ((dnx_field_tcam_prefix_sw_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_PREFIX_MODULE_ID])->banks_prefix,
        banks_prefix_idx_0);

    DNX_SW_STATE_PTR_NULL_CHECK(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_PREFIX_SW__BANKS_PREFIX__CORE_PREFIX_MAP,
        ((dnx_field_tcam_prefix_sw_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_PREFIX_MODULE_ID])->banks_prefix);

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_PREFIX_SW__BANKS_PREFIX__CORE_PREFIX_MAP,
        DNX_SW_STATE_DIAG_ALLOC);

    DNX_SW_STATE_ALLOC(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_PREFIX_SW__BANKS_PREFIX__CORE_PREFIX_MAP,
        ((dnx_field_tcam_prefix_sw_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_PREFIX_MODULE_ID])->banks_prefix[banks_prefix_idx_0].core_prefix_map,
        dnx_field_tcam_prefix_t,
        dnx_data_device.general.nof_cores_get(unit),
        DNXC_SW_STATE_DNX_DATA_ALLOC | DNXC_SW_STATE_AUTO_GENERATED_ALLOCATION,
        "dnx_field_tcam_prefix_sw_banks_prefix_core_prefix_map_alloc");

    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_ALLOC_LOGGING,
        BSL_LS_SWSTATEDNX_ALLOC,
        DNX_SW_STATE_DNX_FIELD_TCAM_PREFIX_SW__BANKS_PREFIX__CORE_PREFIX_MAP,
        ((dnx_field_tcam_prefix_sw_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_PREFIX_MODULE_ID])->banks_prefix[banks_prefix_idx_0].core_prefix_map,
        "dnx_field_tcam_prefix_sw[%d]->banks_prefix[%d].core_prefix_map",
        unit, banks_prefix_idx_0,
        dnx_data_device.general.nof_cores_get(unit) * sizeof(dnx_field_tcam_prefix_t) / sizeof(*((dnx_field_tcam_prefix_sw_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_PREFIX_MODULE_ID])->banks_prefix[banks_prefix_idx_0].core_prefix_map));

    DNX_SW_STATE_DIAG_INFO_POST(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_PREFIX_SW__BANKS_PREFIX__CORE_PREFIX_MAP,
        dnx_field_tcam_prefix_sw_info,
        DNX_FIELD_TCAM_PREFIX_SW_BANKS_PREFIX_CORE_PREFIX_MAP_INFO,
        DNX_SW_STATE_DIAG_ALLOC,
        NULL);

    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_field_tcam_prefix_sw_banks_prefix_core_prefix_map_prefix_handler_map_set(int unit, uint32 banks_prefix_idx_0, uint32 core_prefix_map_idx_0, uint32 prefix_handler_map_idx_0, uint32 prefix_handler_map)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_PREFIX_SW__BANKS_PREFIX__CORE_PREFIX_MAP__PREFIX_HANDLER_MAP,
        SW_STATE_FUNC_SET,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_PREFIX_SW__BANKS_PREFIX__CORE_PREFIX_MAP__PREFIX_HANDLER_MAP,
        sw_state_roots_array[unit][DNX_FIELD_TCAM_PREFIX_MODULE_ID]);

    DNX_SW_STATE_OOB_DYNAMIC_ARRAY_CHECK(
        DNX_SW_STATE_DNX_FIELD_TCAM_PREFIX_SW__BANKS_PREFIX__CORE_PREFIX_MAP__PREFIX_HANDLER_MAP,
        ((dnx_field_tcam_prefix_sw_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_PREFIX_MODULE_ID])->banks_prefix,
        banks_prefix_idx_0);

    DNX_SW_STATE_PTR_NULL_CHECK(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_PREFIX_SW__BANKS_PREFIX__CORE_PREFIX_MAP__PREFIX_HANDLER_MAP,
        ((dnx_field_tcam_prefix_sw_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_PREFIX_MODULE_ID])->banks_prefix[banks_prefix_idx_0].core_prefix_map[core_prefix_map_idx_0].prefix_handler_map);

    DNX_SW_STATE_OOB_DYNAMIC_ARRAY_CHECK(
        DNX_SW_STATE_DNX_FIELD_TCAM_PREFIX_SW__BANKS_PREFIX__CORE_PREFIX_MAP__PREFIX_HANDLER_MAP,
        ((dnx_field_tcam_prefix_sw_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_PREFIX_MODULE_ID])->banks_prefix[banks_prefix_idx_0].core_prefix_map,
        core_prefix_map_idx_0);

    DNX_SW_STATE_PTR_NULL_CHECK(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_PREFIX_SW__BANKS_PREFIX__CORE_PREFIX_MAP__PREFIX_HANDLER_MAP,
        ((dnx_field_tcam_prefix_sw_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_PREFIX_MODULE_ID])->banks_prefix[banks_prefix_idx_0].core_prefix_map);

    DNX_SW_STATE_OOB_DYNAMIC_ARRAY_CHECK(
        DNX_SW_STATE_DNX_FIELD_TCAM_PREFIX_SW__BANKS_PREFIX__CORE_PREFIX_MAP__PREFIX_HANDLER_MAP,
        ((dnx_field_tcam_prefix_sw_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_PREFIX_MODULE_ID])->banks_prefix[banks_prefix_idx_0].core_prefix_map[core_prefix_map_idx_0].prefix_handler_map,
        prefix_handler_map_idx_0);

    DNX_SW_STATE_PTR_NULL_CHECK(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_PREFIX_SW__BANKS_PREFIX__CORE_PREFIX_MAP__PREFIX_HANDLER_MAP,
        ((dnx_field_tcam_prefix_sw_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_PREFIX_MODULE_ID])->banks_prefix);

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_PREFIX_SW__BANKS_PREFIX__CORE_PREFIX_MAP__PREFIX_HANDLER_MAP,
        DNX_SW_STATE_DIAG_MODIFY);

    DNX_SW_STATE_SET(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_PREFIX_SW__BANKS_PREFIX__CORE_PREFIX_MAP__PREFIX_HANDLER_MAP,
        ((dnx_field_tcam_prefix_sw_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_PREFIX_MODULE_ID])->banks_prefix[banks_prefix_idx_0].core_prefix_map[core_prefix_map_idx_0].prefix_handler_map[prefix_handler_map_idx_0],
        prefix_handler_map,
        uint32,
        0,
        "dnx_field_tcam_prefix_sw_banks_prefix_core_prefix_map_prefix_handler_map_set");

    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_SET_LOGGING,
        BSL_LS_SWSTATEDNX_SET,
        DNX_SW_STATE_DNX_FIELD_TCAM_PREFIX_SW__BANKS_PREFIX__CORE_PREFIX_MAP__PREFIX_HANDLER_MAP,
        &prefix_handler_map,
        "dnx_field_tcam_prefix_sw[%d]->banks_prefix[%d].core_prefix_map[%d].prefix_handler_map[%d]",
        unit, banks_prefix_idx_0, core_prefix_map_idx_0, prefix_handler_map_idx_0);

    DNX_SW_STATE_DIAG_INFO_POST(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_PREFIX_SW__BANKS_PREFIX__CORE_PREFIX_MAP__PREFIX_HANDLER_MAP,
        dnx_field_tcam_prefix_sw_info,
        DNX_FIELD_TCAM_PREFIX_SW_BANKS_PREFIX_CORE_PREFIX_MAP_PREFIX_HANDLER_MAP_INFO,
        DNX_SW_STATE_DIAG_MODIFY,
        NULL);

    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_field_tcam_prefix_sw_banks_prefix_core_prefix_map_prefix_handler_map_get(int unit, uint32 banks_prefix_idx_0, uint32 core_prefix_map_idx_0, uint32 prefix_handler_map_idx_0, uint32 *prefix_handler_map)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_PREFIX_SW__BANKS_PREFIX__CORE_PREFIX_MAP__PREFIX_HANDLER_MAP,
        SW_STATE_FUNC_GET,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_PREFIX_SW__BANKS_PREFIX__CORE_PREFIX_MAP__PREFIX_HANDLER_MAP,
        sw_state_roots_array[unit][DNX_FIELD_TCAM_PREFIX_MODULE_ID]);

    DNX_SW_STATE_OOB_DYNAMIC_ARRAY_CHECK(
        DNX_SW_STATE_DNX_FIELD_TCAM_PREFIX_SW__BANKS_PREFIX__CORE_PREFIX_MAP__PREFIX_HANDLER_MAP,
        ((dnx_field_tcam_prefix_sw_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_PREFIX_MODULE_ID])->banks_prefix,
        banks_prefix_idx_0);

    DNX_SW_STATE_PTR_NULL_CHECK(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_PREFIX_SW__BANKS_PREFIX__CORE_PREFIX_MAP__PREFIX_HANDLER_MAP,
        prefix_handler_map);

    DNX_SW_STATE_OOB_DYNAMIC_ARRAY_CHECK(
        DNX_SW_STATE_DNX_FIELD_TCAM_PREFIX_SW__BANKS_PREFIX__CORE_PREFIX_MAP__PREFIX_HANDLER_MAP,
        ((dnx_field_tcam_prefix_sw_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_PREFIX_MODULE_ID])->banks_prefix[banks_prefix_idx_0].core_prefix_map,
        core_prefix_map_idx_0);

    DNX_SW_STATE_PTR_NULL_CHECK(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_PREFIX_SW__BANKS_PREFIX__CORE_PREFIX_MAP__PREFIX_HANDLER_MAP,
        ((dnx_field_tcam_prefix_sw_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_PREFIX_MODULE_ID])->banks_prefix[banks_prefix_idx_0].core_prefix_map[core_prefix_map_idx_0].prefix_handler_map);

    DNX_SW_STATE_OOB_DYNAMIC_ARRAY_CHECK(
        DNX_SW_STATE_DNX_FIELD_TCAM_PREFIX_SW__BANKS_PREFIX__CORE_PREFIX_MAP__PREFIX_HANDLER_MAP,
        ((dnx_field_tcam_prefix_sw_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_PREFIX_MODULE_ID])->banks_prefix[banks_prefix_idx_0].core_prefix_map[core_prefix_map_idx_0].prefix_handler_map,
        prefix_handler_map_idx_0);

    DNX_SW_STATE_PTR_NULL_CHECK(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_PREFIX_SW__BANKS_PREFIX__CORE_PREFIX_MAP__PREFIX_HANDLER_MAP,
        ((dnx_field_tcam_prefix_sw_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_PREFIX_MODULE_ID])->banks_prefix[banks_prefix_idx_0].core_prefix_map);

    DNX_SW_STATE_PTR_NULL_CHECK(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_PREFIX_SW__BANKS_PREFIX__CORE_PREFIX_MAP__PREFIX_HANDLER_MAP,
        ((dnx_field_tcam_prefix_sw_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_PREFIX_MODULE_ID])->banks_prefix);

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_PREFIX_SW__BANKS_PREFIX__CORE_PREFIX_MAP__PREFIX_HANDLER_MAP,
        DNX_SW_STATE_DIAG_READ);

    *prefix_handler_map = ((dnx_field_tcam_prefix_sw_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_PREFIX_MODULE_ID])->banks_prefix[banks_prefix_idx_0].core_prefix_map[core_prefix_map_idx_0].prefix_handler_map[prefix_handler_map_idx_0];
    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_GET_LOGGING,
        BSL_LS_SWSTATEDNX_GET,
        DNX_SW_STATE_DNX_FIELD_TCAM_PREFIX_SW__BANKS_PREFIX__CORE_PREFIX_MAP__PREFIX_HANDLER_MAP,
        &((dnx_field_tcam_prefix_sw_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_PREFIX_MODULE_ID])->banks_prefix[banks_prefix_idx_0].core_prefix_map[core_prefix_map_idx_0].prefix_handler_map[prefix_handler_map_idx_0],
        "dnx_field_tcam_prefix_sw[%d]->banks_prefix[%d].core_prefix_map[%d].prefix_handler_map[%d]",
        unit, banks_prefix_idx_0, core_prefix_map_idx_0, prefix_handler_map_idx_0);

    DNX_SW_STATE_DIAG_INFO_POST(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_PREFIX_SW__BANKS_PREFIX__CORE_PREFIX_MAP__PREFIX_HANDLER_MAP,
        dnx_field_tcam_prefix_sw_info,
        DNX_FIELD_TCAM_PREFIX_SW_BANKS_PREFIX_CORE_PREFIX_MAP_PREFIX_HANDLER_MAP_INFO,
        DNX_SW_STATE_DIAG_READ,
        NULL);

    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_field_tcam_prefix_sw_banks_prefix_core_prefix_map_prefix_handler_map_alloc(int unit, uint32 banks_prefix_idx_0, uint32 core_prefix_map_idx_0)
{
    DNX_SW_STATE_DEFAULT_VALUE_DEFS;
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_PREFIX_SW__BANKS_PREFIX__CORE_PREFIX_MAP__PREFIX_HANDLER_MAP,
        SW_STATE_FUNC_ALLOC,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_PREFIX_SW__BANKS_PREFIX__CORE_PREFIX_MAP__PREFIX_HANDLER_MAP,
        sw_state_roots_array[unit][DNX_FIELD_TCAM_PREFIX_MODULE_ID]);

    DNX_SW_STATE_OOB_DYNAMIC_ARRAY_CHECK(
        DNX_SW_STATE_DNX_FIELD_TCAM_PREFIX_SW__BANKS_PREFIX__CORE_PREFIX_MAP__PREFIX_HANDLER_MAP,
        ((dnx_field_tcam_prefix_sw_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_PREFIX_MODULE_ID])->banks_prefix,
        banks_prefix_idx_0);

    DNX_SW_STATE_PTR_NULL_CHECK(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_PREFIX_SW__BANKS_PREFIX__CORE_PREFIX_MAP__PREFIX_HANDLER_MAP,
        ((dnx_field_tcam_prefix_sw_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_PREFIX_MODULE_ID])->banks_prefix[banks_prefix_idx_0].core_prefix_map);

    DNX_SW_STATE_OOB_DYNAMIC_ARRAY_CHECK(
        DNX_SW_STATE_DNX_FIELD_TCAM_PREFIX_SW__BANKS_PREFIX__CORE_PREFIX_MAP__PREFIX_HANDLER_MAP,
        ((dnx_field_tcam_prefix_sw_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_PREFIX_MODULE_ID])->banks_prefix[banks_prefix_idx_0].core_prefix_map,
        core_prefix_map_idx_0);

    DNX_SW_STATE_PTR_NULL_CHECK(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_PREFIX_SW__BANKS_PREFIX__CORE_PREFIX_MAP__PREFIX_HANDLER_MAP,
        ((dnx_field_tcam_prefix_sw_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_PREFIX_MODULE_ID])->banks_prefix);

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_PREFIX_SW__BANKS_PREFIX__CORE_PREFIX_MAP__PREFIX_HANDLER_MAP,
        DNX_SW_STATE_DIAG_ALLOC);

    DNX_SW_STATE_ALLOC(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_PREFIX_SW__BANKS_PREFIX__CORE_PREFIX_MAP__PREFIX_HANDLER_MAP,
        ((dnx_field_tcam_prefix_sw_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_PREFIX_MODULE_ID])->banks_prefix[banks_prefix_idx_0].core_prefix_map[core_prefix_map_idx_0].prefix_handler_map,
        uint32,
        dnx_data_field.tcam.max_prefix_value_get(unit),
        DNXC_SW_STATE_DNX_DATA_ALLOC | DNXC_SW_STATE_AUTO_GENERATED_ALLOCATION,
        "dnx_field_tcam_prefix_sw_banks_prefix_core_prefix_map_prefix_handler_map_alloc");

    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_ALLOC_LOGGING,
        BSL_LS_SWSTATEDNX_ALLOC,
        DNX_SW_STATE_DNX_FIELD_TCAM_PREFIX_SW__BANKS_PREFIX__CORE_PREFIX_MAP__PREFIX_HANDLER_MAP,
        ((dnx_field_tcam_prefix_sw_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_PREFIX_MODULE_ID])->banks_prefix[banks_prefix_idx_0].core_prefix_map[core_prefix_map_idx_0].prefix_handler_map,
        "dnx_field_tcam_prefix_sw[%d]->banks_prefix[%d].core_prefix_map[%d].prefix_handler_map",
        unit, banks_prefix_idx_0, core_prefix_map_idx_0,
        dnx_data_field.tcam.max_prefix_value_get(unit) * sizeof(uint32) / sizeof(*((dnx_field_tcam_prefix_sw_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_PREFIX_MODULE_ID])->banks_prefix[banks_prefix_idx_0].core_prefix_map[core_prefix_map_idx_0].prefix_handler_map));

    DNX_SW_STATE_DIAG_INFO_POST(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_PREFIX_SW__BANKS_PREFIX__CORE_PREFIX_MAP__PREFIX_HANDLER_MAP,
        dnx_field_tcam_prefix_sw_info,
        DNX_FIELD_TCAM_PREFIX_SW_BANKS_PREFIX_CORE_PREFIX_MAP_PREFIX_HANDLER_MAP_INFO,
        DNX_SW_STATE_DIAG_ALLOC,
        NULL);

    DNX_SW_STATE_DEFAULT_VALUE_LOOP(def_val_idx[0], dnx_data_field.tcam.max_prefix_value_get(unit))

    DNX_SW_STATE_DEFAULT_VALUE_ASSIGN(
        ((dnx_field_tcam_prefix_sw_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_PREFIX_MODULE_ID])->banks_prefix[banks_prefix_idx_0].core_prefix_map[core_prefix_map_idx_0].prefix_handler_map[def_val_idx[0]],
        DNX_FIELD_TCAM_HANDLER_ID_INVALID);

    DNXC_SW_STATE_FUNC_RETURN;
}





dnx_field_tcam_prefix_sw_cbs dnx_field_tcam_prefix_sw = 	{
	
	dnx_field_tcam_prefix_sw_is_init,
	dnx_field_tcam_prefix_sw_init,
		{
		
		dnx_field_tcam_prefix_sw_banks_prefix_alloc,
			{
			
			dnx_field_tcam_prefix_sw_banks_prefix_core_prefix_map_alloc,
				{
				
				dnx_field_tcam_prefix_sw_banks_prefix_core_prefix_map_prefix_handler_map_set,
				dnx_field_tcam_prefix_sw_banks_prefix_core_prefix_map_prefix_handler_map_get,
				dnx_field_tcam_prefix_sw_banks_prefix_core_prefix_map_prefix_handler_map_alloc}
			}
		}
	}
;
#undef BSL_LOG_MODULE
