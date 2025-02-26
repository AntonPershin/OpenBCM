
/*
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2022 Broadcom Inc. All rights reserved.
 */

#ifndef __OAM_LAYOUT_H__
#define __OAM_LAYOUT_H__

#include <include/soc/dnxc/swstate/types/dnxc_sw_state_layout.h>
#include <include/soc/dnxc/swstate/auto_generated/types/dnxc_module_ids_types.h>


int oam_init_layout_structure(int unit);

typedef enum
{
    DNX_SW_STATE_OAM_SW_DB_INFO = DNXC_SW_STATE_LAYOUT_NODE_ID_GET(OAM_MODULE_ID, 0),
    DNX_SW_STATE_OAM_SW_DB_INFO__OAM_GROUP_SW_DB_INFO,
    DNX_SW_STATE_OAM_SW_DB_INFO__OAM_ENDPOINT_SW_DB_INFO,
    DNX_SW_STATE_OAM_SW_DB_INFO__REFLECTOR,
    DNX_SW_STATE_OAM_SW_DB_INFO__OAM_GROUP_SW_DB_INFO__OAM_GROUP_ARRAY_OF_LINKED_LISTS,
    DNX_SW_STATE_OAM_SW_DB_INFO__OAM_ENDPOINT_SW_DB_INFO__OAM_ENDPOINT_ARRAY_OF_RMEP_LINKED_LISTS,
    DNX_SW_STATE_OAM_SW_DB_INFO__OAM_ENDPOINT_SW_DB_INFO__OAM_ENDPOINT_ARRAY_OF_MEP_LINKED_LISTS,
    DNX_SW_STATE_OAM_SW_DB_INFO__REFLECTOR__ENCAP_ID,
    DNX_SW_STATE_OAM_SW_DB_INFO__REFLECTOR__IS_ALLOCATED,
    
    DNX_SW_STATE_OAM_SW_DB_INFO_NOF_PARAMS,
} dnxc_sw_state_layout_oam_node_id_e;

#endif 
