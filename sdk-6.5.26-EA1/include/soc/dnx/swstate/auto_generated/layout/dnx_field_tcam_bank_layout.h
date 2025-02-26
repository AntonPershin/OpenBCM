
/*
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2022 Broadcom Inc. All rights reserved.
 */

#ifndef __DNX_FIELD_TCAM_BANK_LAYOUT_H__
#define __DNX_FIELD_TCAM_BANK_LAYOUT_H__

#include <include/soc/dnxc/swstate/types/dnxc_sw_state_layout.h>
#include <include/soc/dnxc/swstate/auto_generated/types/dnxc_module_ids_types.h>


int dnx_field_tcam_bank_init_layout_structure(int unit);

typedef enum
{
    DNX_SW_STATE_DNX_FIELD_TCAM_BANK_SW = DNXC_SW_STATE_LAYOUT_NODE_ID_GET(DNX_FIELD_TCAM_BANK_MODULE_ID, 0),
    DNX_SW_STATE_DNX_FIELD_TCAM_BANK_SW__TCAM_BANKS,
    DNX_SW_STATE_DNX_FIELD_TCAM_BANK_SW__TCAM_BANKS__OWNER_STAGE,
    DNX_SW_STATE_DNX_FIELD_TCAM_BANK_SW__TCAM_BANKS__ACTIVE_HANDLERS_ID,
    DNX_SW_STATE_DNX_FIELD_TCAM_BANK_SW__TCAM_BANKS__NOF_FREE_ENTRIES,
    DNX_SW_STATE_DNX_FIELD_TCAM_BANK_SW__TCAM_BANKS__BANK_MODE,
    DNX_SW_STATE_DNX_FIELD_TCAM_BANK_SW__TCAM_BANKS__KEY_SIZE,
    
    DNX_SW_STATE_DNX_FIELD_TCAM_BANK_SW_NOF_PARAMS,
} dnxc_sw_state_layout_dnx_field_tcam_bank_node_id_e;

#endif 
