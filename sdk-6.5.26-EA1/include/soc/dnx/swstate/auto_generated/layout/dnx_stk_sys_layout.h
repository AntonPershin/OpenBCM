
/*
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2022 Broadcom Inc. All rights reserved.
 */

#ifndef __DNX_STK_SYS_LAYOUT_H__
#define __DNX_STK_SYS_LAYOUT_H__

#ifdef BCM_DNX_SUPPORT
#include <include/soc/dnxc/swstate/types/dnxc_sw_state_layout.h>
#include <include/soc/dnxc/swstate/auto_generated/types/dnxc_module_ids_types.h>


int dnx_stk_sys_init_layout_structure(int unit);

typedef enum
{
    DNX_SW_STATE_DNX_STK_SYS_DB = DNXC_SW_STATE_LAYOUT_NODE_ID_GET(DNX_STK_SYS_MODULE_ID, 0),
    DNX_SW_STATE_DNX_STK_SYS_DB__NOF_FAP_IDS,
    DNX_SW_STATE_DNX_STK_SYS_DB__MODULE_ENABLE_DONE,
    
    DNX_SW_STATE_DNX_STK_SYS_DB_NOF_PARAMS,
} dnxc_sw_state_layout_dnx_stk_sys_node_id_e;
#endif  

#endif 
