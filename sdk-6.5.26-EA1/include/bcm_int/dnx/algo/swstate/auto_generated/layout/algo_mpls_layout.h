/** \file algo/swstate/auto_generated/layout/algo_mpls_layout.h
 *
 * sw state layout enum
 *
 * DO NOT EDIT THIS FILE!
 * This file is auto-generated.
 * Edits to this file will be lost when it is regenerated.
 *
 */
/*
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2022 Broadcom Inc. All rights reserved.
 */

#ifndef __ALGO_MPLS_LAYOUT_H__
#define __ALGO_MPLS_LAYOUT_H__

#include <include/soc/dnxc/swstate/types/dnxc_sw_state_layout.h>
#include <include/soc/dnxc/swstate/auto_generated/types/dnxc_module_ids_types.h>


int algo_mpls_init_layout_structure(int unit);

typedef enum
{
    DNX_SW_STATE_ALGO_MPLS_DB = DNXC_SW_STATE_LAYOUT_NODE_ID_GET(ALGO_MPLS_MODULE_ID, 0),
    DNX_SW_STATE_ALGO_MPLS_DB__TERMINATION_PROFILE,
    DNX_SW_STATE_ALGO_MPLS_DB__PUSH_PROFILE,
    DNX_SW_STATE_ALGO_MPLS_DB__LABEL_RANGE_PROFILE,
    /*
     * Use DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX macro to get the number of parameters
     */
    DNX_SW_STATE_ALGO_MPLS_DB_NOF_PARAMS,
} dnxc_sw_state_layout_algo_mpls_node_id_e;

#endif /* __ALGO_MPLS_LAYOUT_H__ */
