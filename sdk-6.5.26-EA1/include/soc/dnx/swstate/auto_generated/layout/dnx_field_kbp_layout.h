
/*
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2022 Broadcom Inc. All rights reserved.
 */

#ifndef __DNX_FIELD_KBP_LAYOUT_H__
#define __DNX_FIELD_KBP_LAYOUT_H__

#ifdef BCM_DNX_SUPPORT
#if defined(INCLUDE_KBP)
#include <include/soc/dnxc/swstate/types/dnxc_sw_state_layout.h>
#include <include/soc/dnxc/swstate/auto_generated/types/dnxc_module_ids_types.h>


int dnx_field_kbp_init_layout_structure(int unit);

typedef enum
{
    DNX_SW_STATE_DNX_FIELD_KBP_SW = DNXC_SW_STATE_LAYOUT_NODE_ID_GET(DNX_FIELD_KBP_MODULE_ID, 0),
    DNX_SW_STATE_DNX_FIELD_KBP_SW__OPCODE_INFO,
    DNX_SW_STATE_DNX_FIELD_KBP_SW__OPCODE_INFO__MASTER_KEY_INFO,
    DNX_SW_STATE_DNX_FIELD_KBP_SW__OPCODE_INFO__IS_VALID,
    DNX_SW_STATE_DNX_FIELD_KBP_SW__OPCODE_INFO__MASTER_KEY_INFO__SEGMENT_INFO,
    DNX_SW_STATE_DNX_FIELD_KBP_SW__OPCODE_INFO__MASTER_KEY_INFO__NOF_FWD_SEGMENTS,
    DNX_SW_STATE_DNX_FIELD_KBP_SW__OPCODE_INFO__MASTER_KEY_INFO__SEGMENT_INFO__QUAL_IDX,
    DNX_SW_STATE_DNX_FIELD_KBP_SW__OPCODE_INFO__MASTER_KEY_INFO__SEGMENT_INFO__FG_ID,
    
    DNX_SW_STATE_DNX_FIELD_KBP_SW_NOF_PARAMS,
} dnxc_sw_state_layout_dnx_field_kbp_node_id_e;
#endif  
#endif  

#endif 
