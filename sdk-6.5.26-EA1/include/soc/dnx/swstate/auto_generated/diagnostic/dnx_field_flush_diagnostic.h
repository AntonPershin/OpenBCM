
/*
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2022 Broadcom Inc. All rights reserved.
 */

#ifndef __DNX_FIELD_FLUSH_DIAGNOSTIC_H__
#define __DNX_FIELD_FLUSH_DIAGNOSTIC_H__

#include <soc/dnxc/swstate/dnx_sw_state_dump.h>
#include <soc/dnxc/swstate/dnx_sw_state_size.h>
#include <soc/dnx/swstate/auto_generated/types/dnx_field_flush_types.h>
#include <soc/dnx/swstate/auto_generated/types/dnx_field_types.h>
#if defined(DNX_SW_STATE_DIAGNOSTIC)
typedef enum {
    DNX_FIELD_FLUSH_SW_INFO,
    DNX_FIELD_FLUSH_SW_FLUSH_PROFILE_INFO,
    DNX_FIELD_FLUSH_SW_FLUSH_PROFILE_IS_MAPPED_INFO,
    DNX_FIELD_FLUSH_SW_FLUSH_PROFILE_MAPPED_FG_INFO,
    DNX_FIELD_FLUSH_SW_INFO_NOF_ENTRIES
} sw_state_dnx_field_flush_sw_layout_e;


extern dnx_sw_state_diagnostic_info_t dnx_field_flush_sw_info[SOC_MAX_NUM_DEVICES][DNX_FIELD_FLUSH_SW_INFO_NOF_ENTRIES];

extern const char* dnx_field_flush_sw_layout_str[DNX_FIELD_FLUSH_SW_INFO_NOF_ENTRIES];
int dnx_field_flush_sw_dump(
    int unit, dnx_sw_state_dump_filters_t filters);

int dnx_field_flush_sw_flush_profile_dump(
    int unit, int flush_profile_idx_0, dnx_sw_state_dump_filters_t filters);

int dnx_field_flush_sw_flush_profile_is_mapped_dump(
    int unit, int flush_profile_idx_0, dnx_sw_state_dump_filters_t filters);

int dnx_field_flush_sw_flush_profile_mapped_fg_dump(
    int unit, int flush_profile_idx_0, dnx_sw_state_dump_filters_t filters);

#endif 

#endif 
