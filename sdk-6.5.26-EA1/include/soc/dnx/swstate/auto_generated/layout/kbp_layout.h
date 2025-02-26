
/*
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2022 Broadcom Inc. All rights reserved.
 */

#ifndef __KBP_LAYOUT_H__
#define __KBP_LAYOUT_H__

#ifdef BCM_DNX_SUPPORT
#if defined(INCLUDE_KBP)
#include <include/soc/dnxc/swstate/types/dnxc_sw_state_layout.h>
#include <include/soc/dnxc/swstate/auto_generated/types/dnxc_module_ids_types.h>


int kbp_init_layout_structure(int unit);

typedef enum
{
    DNX_SW_STATE_KBP_SW_STATE = DNXC_SW_STATE_LAYOUT_NODE_ID_GET(KBP_MODULE_ID, 0),
    DNX_SW_STATE_KBP_SW_STATE__FWD_CACHING_ENABLED,
    DNX_SW_STATE_KBP_SW_STATE__IS_DEVICE_LOCKED,
    DNX_SW_STATE_KBP_SW_STATE__DB_HANDLES_INFO,
    DNX_SW_STATE_KBP_SW_STATE__INSTRUCTION_INFO,
    DNX_SW_STATE_KBP_SW_STATE__DB_HANDLES_INFO__CACHING_BMP,
    DNX_SW_STATE_KBP_SW_STATE__DB_HANDLES_INFO__CORE_ID,
    DNX_SW_STATE_KBP_SW_STATE__DB_HANDLES_INFO__CACHING_ENABLED,
    DNX_SW_STATE_KBP_SW_STATE__DB_HANDLES_INFO__DB_P,
    DNX_SW_STATE_KBP_SW_STATE__DB_HANDLES_INFO__AD_DB_ZERO_SIZE_P,
    DNX_SW_STATE_KBP_SW_STATE__DB_HANDLES_INFO__AD_ENTRY_ZERO_SIZE_P,
    DNX_SW_STATE_KBP_SW_STATE__DB_HANDLES_INFO__AD_DB_P,
    DNX_SW_STATE_KBP_SW_STATE__DB_HANDLES_INFO__OPT_RESULT_SIZE,
    DNX_SW_STATE_KBP_SW_STATE__DB_HANDLES_INFO__LARGE_OPT_RESULT_SIZE,
    DNX_SW_STATE_KBP_SW_STATE__DB_HANDLES_INFO__CLONED_DB_ID,
    DNX_SW_STATE_KBP_SW_STATE__DB_HANDLES_INFO__ASSOCIATED_DBAL_TABLE_ID,
    DNX_SW_STATE_KBP_SW_STATE__INSTRUCTION_INFO__INST_P,
    
    DNX_SW_STATE_KBP_SW_STATE_NOF_PARAMS,
} dnxc_sw_state_layout_kbp_node_id_e;
#endif  
#endif  

#endif 
