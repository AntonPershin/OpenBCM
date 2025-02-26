/** \file algo/swstate/auto_generated/layout/dnx_algo_flexe_general_layout.c
 *
 * sw state layout structure
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

#ifdef BSL_LOG_MODULE
#error "BSL_LOG_MODULE redefined"
#endif
#define BSL_LOG_MODULE BSL_LS_SWSTATEDNX_GENERAL

#ifdef BCM_DNX_SUPPORT
#include <bcm_int/dnx/algo/swstate/auto_generated/types/dnx_algo_flexe_general_types.h>
#include <bcm_int/dnx/algo/swstate/auto_generated/layout/dnx_algo_flexe_general_layout.h>

dnxc_sw_state_layout_t layout_array_dnx_algo_flexe_general[DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_DNX_ALGO_FLEXE_GENERAL_DB_NOF_PARAMS)];

shr_error_e
dnx_algo_flexe_general_init_layout_structure(int unit)
{

    int idx;

    DNXC_SW_STATE_INIT_FUNC_DEFS;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_DNX_ALGO_FLEXE_GENERAL_DB);
    layout_array_dnx_algo_flexe_general[idx].name = "dnx_algo_flexe_general_db";
    layout_array_dnx_algo_flexe_general[idx].type = "dnx_algo_flexe_general_db_t";
    layout_array_dnx_algo_flexe_general[idx].doc = "FlexE general Data Base";
    layout_array_dnx_algo_flexe_general[idx].total_size = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_algo_flexe_general[idx].size_of = sizeof(dnx_algo_flexe_general_db_t);
    layout_array_dnx_algo_flexe_general[idx].parent  = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_algo_flexe_general[idx].first_child_index = 1;
    layout_array_dnx_algo_flexe_general[idx].last_child_index = 8;
    layout_array_dnx_algo_flexe_general[idx].next_node_index = 1;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_DNX_ALGO_FLEXE_GENERAL_DB__FIFO_LINK_LIST);
    layout_array_dnx_algo_flexe_general[idx].name = "dnx_algo_flexe_general_db__fifo_link_list";
    layout_array_dnx_algo_flexe_general[idx].type = "int*";
    layout_array_dnx_algo_flexe_general[idx].doc = "Store FlexE fifos link list info";
    layout_array_dnx_algo_flexe_general[idx].total_size = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_algo_flexe_general[idx].size_of = sizeof(int*);
    layout_array_dnx_algo_flexe_general[idx].array_indexes[0].size = DNX_ALGO_FLEXE_NOF_LINK_LIST_FIFOS;
    layout_array_dnx_algo_flexe_general[idx].array_indexes[0].index_type = DNXC_SWSTATE_ARRAY_INDEX_STATIC;
    layout_array_dnx_algo_flexe_general[idx].array_indexes[1].size = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_algo_flexe_general[idx].array_indexes[1].index_type = DNXC_SWSTATE_ARRAY_INDEX_DYNAMIC;
    layout_array_dnx_algo_flexe_general[idx].parent  = 0;
    layout_array_dnx_algo_flexe_general[idx].first_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_algo_flexe_general[idx].last_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_algo_flexe_general[idx].next_node_index = 2;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_DNX_ALGO_FLEXE_GENERAL_DB__GROUP_INFO);
    layout_array_dnx_algo_flexe_general[idx].name = "dnx_algo_flexe_general_db__group_info";
    layout_array_dnx_algo_flexe_general[idx].type = "dnx_algo_flexe_general_group_info_t*";
    layout_array_dnx_algo_flexe_general[idx].doc = "FlexE group info for each FlexE group";
    layout_array_dnx_algo_flexe_general[idx].total_size = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_algo_flexe_general[idx].size_of = sizeof(dnx_algo_flexe_general_group_info_t*);
    layout_array_dnx_algo_flexe_general[idx].array_indexes[0].size = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_algo_flexe_general[idx].array_indexes[0].index_type = DNXC_SWSTATE_ARRAY_INDEX_DYNAMIC_DNX_DATA;
    layout_array_dnx_algo_flexe_general[idx].parent  = 0;
    layout_array_dnx_algo_flexe_general[idx].first_child_index = 9;
    layout_array_dnx_algo_flexe_general[idx].last_child_index = 14;
    layout_array_dnx_algo_flexe_general[idx].next_node_index = 3;
    layout_array_dnx_algo_flexe_general[idx].labels = DNXC_SW_STATE_LAYOUT_LABEL_FORCE_INTERFACE_GENERATION;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_DNX_ALGO_FLEXE_GENERAL_DB__DEMUX_SLOT_INFO);
    layout_array_dnx_algo_flexe_general[idx].name = "dnx_algo_flexe_general_db__demux_slot_info";
    layout_array_dnx_algo_flexe_general[idx].type = "dnx_algo_flexe_general_demux_slot_info_t*";
    layout_array_dnx_algo_flexe_general[idx].doc = "FlexE group demux slot info for each FlexE group";
    layout_array_dnx_algo_flexe_general[idx].total_size = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_algo_flexe_general[idx].size_of = sizeof(dnx_algo_flexe_general_demux_slot_info_t*);
    layout_array_dnx_algo_flexe_general[idx].array_indexes[0].size = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_algo_flexe_general[idx].array_indexes[0].index_type = DNXC_SWSTATE_ARRAY_INDEX_DYNAMIC_DNX_DATA;
    layout_array_dnx_algo_flexe_general[idx].parent  = 0;
    layout_array_dnx_algo_flexe_general[idx].first_child_index = 15;
    layout_array_dnx_algo_flexe_general[idx].last_child_index = 15;
    layout_array_dnx_algo_flexe_general[idx].next_node_index = 4;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_DNX_ALGO_FLEXE_GENERAL_DB__MUX_SLOT_INFO);
    layout_array_dnx_algo_flexe_general[idx].name = "dnx_algo_flexe_general_db__mux_slot_info";
    layout_array_dnx_algo_flexe_general[idx].type = "dnx_algo_flexe_general_mux_slot_info_t*";
    layout_array_dnx_algo_flexe_general[idx].doc = "FlexE group mux slot info for each FlexE group";
    layout_array_dnx_algo_flexe_general[idx].total_size = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_algo_flexe_general[idx].size_of = sizeof(dnx_algo_flexe_general_mux_slot_info_t*);
    layout_array_dnx_algo_flexe_general[idx].array_indexes[0].size = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_algo_flexe_general[idx].array_indexes[0].index_type = DNXC_SWSTATE_ARRAY_INDEX_DYNAMIC_DNX_DATA;
    layout_array_dnx_algo_flexe_general[idx].parent  = 0;
    layout_array_dnx_algo_flexe_general[idx].first_child_index = 16;
    layout_array_dnx_algo_flexe_general[idx].last_child_index = 16;
    layout_array_dnx_algo_flexe_general[idx].next_node_index = 5;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_DNX_ALGO_FLEXE_GENERAL_DB__TINY_MAC_ACCESS_MUTEX);
    layout_array_dnx_algo_flexe_general[idx].name = "dnx_algo_flexe_general_db__tiny_mac_access_mutex";
    layout_array_dnx_algo_flexe_general[idx].type = "sw_state_mutex_t";
    layout_array_dnx_algo_flexe_general[idx].doc = "mutex to prevent race condition on TMAC access from different threads";
    layout_array_dnx_algo_flexe_general[idx].total_size = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_algo_flexe_general[idx].size_of = sizeof(sw_state_mutex_t);
    layout_array_dnx_algo_flexe_general[idx].parent  = 0;
    layout_array_dnx_algo_flexe_general[idx].first_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_algo_flexe_general[idx].last_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_algo_flexe_general[idx].next_node_index = 6;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_DNX_ALGO_FLEXE_GENERAL_DB__RESOURCE_ALLOC);
    layout_array_dnx_algo_flexe_general[idx].name = "dnx_algo_flexe_general_db__resource_alloc";
    layout_array_dnx_algo_flexe_general[idx].type = "dnx_algo_flexe_general_resource_alloc_t";
    layout_array_dnx_algo_flexe_general[idx].doc = "FlexE general resource mngr, including FlexE client channel id";
    layout_array_dnx_algo_flexe_general[idx].total_size = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_algo_flexe_general[idx].size_of = sizeof(dnx_algo_flexe_general_resource_alloc_t);
    layout_array_dnx_algo_flexe_general[idx].parent  = 0;
    layout_array_dnx_algo_flexe_general[idx].first_child_index = 17;
    layout_array_dnx_algo_flexe_general[idx].last_child_index = 24;
    layout_array_dnx_algo_flexe_general[idx].next_node_index = 7;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_DNX_ALGO_FLEXE_GENERAL_DB__FLEXE_CORE_IS_ACTIVE);
    layout_array_dnx_algo_flexe_general[idx].name = "dnx_algo_flexe_general_db__flexe_core_is_active";
    layout_array_dnx_algo_flexe_general[idx].type = "uint8";
    layout_array_dnx_algo_flexe_general[idx].doc = "Indicate if FlexE core is active";
    layout_array_dnx_algo_flexe_general[idx].total_size = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_algo_flexe_general[idx].size_of = sizeof(uint8);
    layout_array_dnx_algo_flexe_general[idx].parent  = 0;
    layout_array_dnx_algo_flexe_general[idx].first_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_algo_flexe_general[idx].last_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_algo_flexe_general[idx].next_node_index = 8;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_DNX_ALGO_FLEXE_GENERAL_DB__MGMT_CHANNEL_INFO);
    layout_array_dnx_algo_flexe_general[idx].name = "dnx_algo_flexe_general_db__mgmt_channel_info";
    layout_array_dnx_algo_flexe_general[idx].type = "dnx_algo_flexe_general_mgmt_channel_info_t*";
    layout_array_dnx_algo_flexe_general[idx].doc = "Store the FlexE mgmt channel info";
    layout_array_dnx_algo_flexe_general[idx].total_size = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_algo_flexe_general[idx].size_of = sizeof(dnx_algo_flexe_general_mgmt_channel_info_t*);
    layout_array_dnx_algo_flexe_general[idx].array_indexes[0].size = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_algo_flexe_general[idx].array_indexes[0].index_type = DNXC_SWSTATE_ARRAY_INDEX_DYNAMIC;
    layout_array_dnx_algo_flexe_general[idx].parent  = 0;
    layout_array_dnx_algo_flexe_general[idx].first_child_index = 25;
    layout_array_dnx_algo_flexe_general[idx].last_child_index = 26;
    layout_array_dnx_algo_flexe_general[idx].next_node_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_algo_flexe_general[idx].labels = DNXC_SW_STATE_LAYOUT_LABEL_FORCE_INTERFACE_GENERATION;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_DNX_ALGO_FLEXE_GENERAL_DB__GROUP_INFO__VALID);
    layout_array_dnx_algo_flexe_general[idx].name = "dnx_algo_flexe_general_db__group_info__valid";
    layout_array_dnx_algo_flexe_general[idx].type = "int";
    layout_array_dnx_algo_flexe_general[idx].doc = "Boolean, If group is valid.";
    layout_array_dnx_algo_flexe_general[idx].total_size = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_algo_flexe_general[idx].size_of = sizeof(int);
    layout_array_dnx_algo_flexe_general[idx].parent  = 2;
    layout_array_dnx_algo_flexe_general[idx].first_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_algo_flexe_general[idx].last_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_algo_flexe_general[idx].next_node_index = 10;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_DNX_ALGO_FLEXE_GENERAL_DB__GROUP_INFO__GROUP_ID);
    layout_array_dnx_algo_flexe_general[idx].name = "dnx_algo_flexe_general_db__group_info__group_id";
    layout_array_dnx_algo_flexe_general[idx].type = "int";
    layout_array_dnx_algo_flexe_general[idx].doc = "FlexE group ID required by FlexE spec.";
    layout_array_dnx_algo_flexe_general[idx].total_size = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_algo_flexe_general[idx].size_of = sizeof(int);
    layout_array_dnx_algo_flexe_general[idx].parent  = 2;
    layout_array_dnx_algo_flexe_general[idx].first_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_algo_flexe_general[idx].last_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_algo_flexe_general[idx].next_node_index = 11;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_DNX_ALGO_FLEXE_GENERAL_DB__GROUP_INFO__PHY_PORTS);
    layout_array_dnx_algo_flexe_general[idx].name = "dnx_algo_flexe_general_db__group_info__phy_ports";
    layout_array_dnx_algo_flexe_general[idx].type = "bcm_pbmp_t";
    layout_array_dnx_algo_flexe_general[idx].doc = "The FlexE phy ports in the FlexE group.";
    layout_array_dnx_algo_flexe_general[idx].total_size = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_algo_flexe_general[idx].size_of = sizeof(bcm_pbmp_t);
    layout_array_dnx_algo_flexe_general[idx].parent  = 2;
    layout_array_dnx_algo_flexe_general[idx].first_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_algo_flexe_general[idx].last_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_algo_flexe_general[idx].next_node_index = 12;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_DNX_ALGO_FLEXE_GENERAL_DB__GROUP_INFO__IS_BYPASS);
    layout_array_dnx_algo_flexe_general[idx].name = "dnx_algo_flexe_general_db__group_info__is_bypass";
    layout_array_dnx_algo_flexe_general[idx].type = "int";
    layout_array_dnx_algo_flexe_general[idx].doc = "Boolean, If group is used for FlexE core bypass mode.";
    layout_array_dnx_algo_flexe_general[idx].total_size = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_algo_flexe_general[idx].size_of = sizeof(int);
    layout_array_dnx_algo_flexe_general[idx].parent  = 2;
    layout_array_dnx_algo_flexe_general[idx].first_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_algo_flexe_general[idx].last_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_algo_flexe_general[idx].next_node_index = 13;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_DNX_ALGO_FLEXE_GENERAL_DB__GROUP_INFO__CAL_SLOTS_UNALIGNED);
    layout_array_dnx_algo_flexe_general[idx].name = "dnx_algo_flexe_general_db__group_info__cal_slots_unaligned";
    layout_array_dnx_algo_flexe_general[idx].type = "uint8";
    layout_array_dnx_algo_flexe_general[idx].doc = "Boolean, Indicate FlexE cal slots is unaligned in FlexE core.";
    layout_array_dnx_algo_flexe_general[idx].total_size = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_algo_flexe_general[idx].size_of = sizeof(uint8);
    layout_array_dnx_algo_flexe_general[idx].parent  = 2;
    layout_array_dnx_algo_flexe_general[idx].first_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_algo_flexe_general[idx].last_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_algo_flexe_general[idx].next_node_index = 14;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_DNX_ALGO_FLEXE_GENERAL_DB__GROUP_INFO__SLOT_MODE);
    layout_array_dnx_algo_flexe_general[idx].name = "dnx_algo_flexe_general_db__group_info__slot_mode";
    layout_array_dnx_algo_flexe_general[idx].type = "bcm_port_flexe_phy_slot_mode_t";
    layout_array_dnx_algo_flexe_general[idx].doc = "FlexE group slot mode.";
    layout_array_dnx_algo_flexe_general[idx].total_size = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_algo_flexe_general[idx].size_of = sizeof(bcm_port_flexe_phy_slot_mode_t);
    layout_array_dnx_algo_flexe_general[idx].parent  = 2;
    layout_array_dnx_algo_flexe_general[idx].first_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_algo_flexe_general[idx].last_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_algo_flexe_general[idx].next_node_index = DNXC_SW_STATE_LAYOUT_INVALID;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_DNX_ALGO_FLEXE_GENERAL_DB__DEMUX_SLOT_INFO__CAL_SLOTS);
    layout_array_dnx_algo_flexe_general[idx].name = "dnx_algo_flexe_general_db__demux_slot_info__cal_slots";
    layout_array_dnx_algo_flexe_general[idx].type = "uint16*";
    layout_array_dnx_algo_flexe_general[idx].doc = "Demux Calendar slots for each group";
    layout_array_dnx_algo_flexe_general[idx].total_size = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_algo_flexe_general[idx].size_of = sizeof(uint16*);
    layout_array_dnx_algo_flexe_general[idx].array_indexes[0].size = bcmPortFlexeGroupCalCount;
    layout_array_dnx_algo_flexe_general[idx].array_indexes[0].index_type = DNXC_SWSTATE_ARRAY_INDEX_STATIC;
    layout_array_dnx_algo_flexe_general[idx].array_indexes[1].size = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_algo_flexe_general[idx].array_indexes[1].index_type = DNXC_SWSTATE_ARRAY_INDEX_DYNAMIC_DNX_DATA;
    layout_array_dnx_algo_flexe_general[idx].parent  = 3;
    layout_array_dnx_algo_flexe_general[idx].first_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_algo_flexe_general[idx].last_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_algo_flexe_general[idx].next_node_index = DNXC_SW_STATE_LAYOUT_INVALID;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_DNX_ALGO_FLEXE_GENERAL_DB__MUX_SLOT_INFO__CAL_SLOTS);
    layout_array_dnx_algo_flexe_general[idx].name = "dnx_algo_flexe_general_db__mux_slot_info__cal_slots";
    layout_array_dnx_algo_flexe_general[idx].type = "uint16*";
    layout_array_dnx_algo_flexe_general[idx].doc = "Mux Calendar slots for each group";
    layout_array_dnx_algo_flexe_general[idx].total_size = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_algo_flexe_general[idx].size_of = sizeof(uint16*);
    layout_array_dnx_algo_flexe_general[idx].array_indexes[0].size = bcmPortFlexeGroupCalCount;
    layout_array_dnx_algo_flexe_general[idx].array_indexes[0].index_type = DNXC_SWSTATE_ARRAY_INDEX_STATIC;
    layout_array_dnx_algo_flexe_general[idx].array_indexes[1].size = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_algo_flexe_general[idx].array_indexes[1].index_type = DNXC_SWSTATE_ARRAY_INDEX_DYNAMIC_DNX_DATA;
    layout_array_dnx_algo_flexe_general[idx].parent  = 4;
    layout_array_dnx_algo_flexe_general[idx].first_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_algo_flexe_general[idx].last_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_algo_flexe_general[idx].next_node_index = DNXC_SW_STATE_LAYOUT_INVALID;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_DNX_ALGO_FLEXE_GENERAL_DB__RESOURCE_ALLOC__CLIENT_CHANNEL);
    layout_array_dnx_algo_flexe_general[idx].name = "dnx_algo_flexe_general_db__resource_alloc__client_channel";
    layout_array_dnx_algo_flexe_general[idx].type = "dnx_algo_res_t";
    layout_array_dnx_algo_flexe_general[idx].doc = "FlexE BusA client channel allocation manager";
    layout_array_dnx_algo_flexe_general[idx].total_size = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_algo_flexe_general[idx].size_of = sizeof(dnx_algo_res_t);
    layout_array_dnx_algo_flexe_general[idx].parent  = 6;
    layout_array_dnx_algo_flexe_general[idx].first_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_algo_flexe_general[idx].last_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_algo_flexe_general[idx].next_node_index = 18;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_DNX_ALGO_FLEXE_GENERAL_DB__RESOURCE_ALLOC__VIRTUAL_CLIENT_CHANNEL);
    layout_array_dnx_algo_flexe_general[idx].name = "dnx_algo_flexe_general_db__resource_alloc__virtual_client_channel";
    layout_array_dnx_algo_flexe_general[idx].type = "dnx_algo_res_t";
    layout_array_dnx_algo_flexe_general[idx].doc = "Virtual flexe client channel allocation manager";
    layout_array_dnx_algo_flexe_general[idx].total_size = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_algo_flexe_general[idx].size_of = sizeof(dnx_algo_res_t);
    layout_array_dnx_algo_flexe_general[idx].parent  = 6;
    layout_array_dnx_algo_flexe_general[idx].first_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_algo_flexe_general[idx].last_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_algo_flexe_general[idx].next_node_index = 19;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_DNX_ALGO_FLEXE_GENERAL_DB__RESOURCE_ALLOC__MAC1);
    layout_array_dnx_algo_flexe_general[idx].name = "dnx_algo_flexe_general_db__resource_alloc__mac1";
    layout_array_dnx_algo_flexe_general[idx].type = "dnx_algo_res_t";
    layout_array_dnx_algo_flexe_general[idx].doc = "Framer MAC1 channel allocation manager";
    layout_array_dnx_algo_flexe_general[idx].total_size = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_algo_flexe_general[idx].size_of = sizeof(dnx_algo_res_t);
    layout_array_dnx_algo_flexe_general[idx].parent  = 6;
    layout_array_dnx_algo_flexe_general[idx].first_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_algo_flexe_general[idx].last_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_algo_flexe_general[idx].next_node_index = 20;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_DNX_ALGO_FLEXE_GENERAL_DB__RESOURCE_ALLOC__MAC2);
    layout_array_dnx_algo_flexe_general[idx].name = "dnx_algo_flexe_general_db__resource_alloc__mac2";
    layout_array_dnx_algo_flexe_general[idx].type = "dnx_algo_res_t";
    layout_array_dnx_algo_flexe_general[idx].doc = "Framer MAC2 channel allocation manager";
    layout_array_dnx_algo_flexe_general[idx].total_size = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_algo_flexe_general[idx].size_of = sizeof(dnx_algo_res_t);
    layout_array_dnx_algo_flexe_general[idx].parent  = 6;
    layout_array_dnx_algo_flexe_general[idx].first_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_algo_flexe_general[idx].last_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_algo_flexe_general[idx].next_node_index = 21;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_DNX_ALGO_FLEXE_GENERAL_DB__RESOURCE_ALLOC__MAC_CHANNEL);
    layout_array_dnx_algo_flexe_general[idx].name = "dnx_algo_flexe_general_db__resource_alloc__mac_channel";
    layout_array_dnx_algo_flexe_general[idx].type = "dnx_algo_res_t";
    layout_array_dnx_algo_flexe_general[idx].doc = "FlexE MAC channel allocation manager";
    layout_array_dnx_algo_flexe_general[idx].total_size = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_algo_flexe_general[idx].size_of = sizeof(dnx_algo_res_t);
    layout_array_dnx_algo_flexe_general[idx].parent  = 6;
    layout_array_dnx_algo_flexe_general[idx].first_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_algo_flexe_general[idx].last_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_algo_flexe_general[idx].next_node_index = 22;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_DNX_ALGO_FLEXE_GENERAL_DB__RESOURCE_ALLOC__SAR_CHANNEL);
    layout_array_dnx_algo_flexe_general[idx].name = "dnx_algo_flexe_general_db__resource_alloc__sar_channel";
    layout_array_dnx_algo_flexe_general[idx].type = "dnx_algo_res_t";
    layout_array_dnx_algo_flexe_general[idx].doc = "FlexE SAR channel allocation manager";
    layout_array_dnx_algo_flexe_general[idx].total_size = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_algo_flexe_general[idx].size_of = sizeof(dnx_algo_res_t);
    layout_array_dnx_algo_flexe_general[idx].parent  = 6;
    layout_array_dnx_algo_flexe_general[idx].first_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_algo_flexe_general[idx].last_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_algo_flexe_general[idx].next_node_index = 23;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_DNX_ALGO_FLEXE_GENERAL_DB__RESOURCE_ALLOC__FLEXE_CORE_PORT);
    layout_array_dnx_algo_flexe_general[idx].name = "dnx_algo_flexe_general_db__resource_alloc__flexe_core_port";
    layout_array_dnx_algo_flexe_general[idx].type = "dnx_algo_res_t";
    layout_array_dnx_algo_flexe_general[idx].doc = "FlexE core port allocation";
    layout_array_dnx_algo_flexe_general[idx].total_size = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_algo_flexe_general[idx].size_of = sizeof(dnx_algo_res_t);
    layout_array_dnx_algo_flexe_general[idx].parent  = 6;
    layout_array_dnx_algo_flexe_general[idx].first_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_algo_flexe_general[idx].last_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_algo_flexe_general[idx].next_node_index = 24;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_DNX_ALGO_FLEXE_GENERAL_DB__RESOURCE_ALLOC__RMC_ID);
    layout_array_dnx_algo_flexe_general[idx].name = "dnx_algo_flexe_general_db__resource_alloc__rmc_id";
    layout_array_dnx_algo_flexe_general[idx].type = "dnx_algo_res_t";
    layout_array_dnx_algo_flexe_general[idx].doc = "Allocate FlexE RMC ID";
    layout_array_dnx_algo_flexe_general[idx].total_size = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_algo_flexe_general[idx].size_of = sizeof(dnx_algo_res_t);
    layout_array_dnx_algo_flexe_general[idx].parent  = 6;
    layout_array_dnx_algo_flexe_general[idx].first_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_algo_flexe_general[idx].last_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_algo_flexe_general[idx].next_node_index = DNXC_SW_STATE_LAYOUT_INVALID;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_DNX_ALGO_FLEXE_GENERAL_DB__MGMT_CHANNEL_INFO__VALID);
    layout_array_dnx_algo_flexe_general[idx].name = "dnx_algo_flexe_general_db__mgmt_channel_info__valid";
    layout_array_dnx_algo_flexe_general[idx].type = "int";
    layout_array_dnx_algo_flexe_general[idx].doc = "Boolean, If the channel is valid.";
    layout_array_dnx_algo_flexe_general[idx].total_size = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_algo_flexe_general[idx].size_of = sizeof(int);
    layout_array_dnx_algo_flexe_general[idx].parent  = 8;
    layout_array_dnx_algo_flexe_general[idx].first_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_algo_flexe_general[idx].last_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_algo_flexe_general[idx].next_node_index = 26;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_DNX_ALGO_FLEXE_GENERAL_DB__MGMT_CHANNEL_INFO__IS_BUSA);
    layout_array_dnx_algo_flexe_general[idx].name = "dnx_algo_flexe_general_db__mgmt_channel_info__is_busa";
    layout_array_dnx_algo_flexe_general[idx].type = "int";
    layout_array_dnx_algo_flexe_general[idx].doc = "Boolean, If the interface mux to BusA or BusB.";
    layout_array_dnx_algo_flexe_general[idx].total_size = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_algo_flexe_general[idx].size_of = sizeof(int);
    layout_array_dnx_algo_flexe_general[idx].parent  = 8;
    layout_array_dnx_algo_flexe_general[idx].first_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_algo_flexe_general[idx].last_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_algo_flexe_general[idx].next_node_index = DNXC_SW_STATE_LAYOUT_INVALID;


    dnxc_sw_state_layout_init_structure(unit, DNX_SW_STATE_DNX_ALGO_FLEXE_GENERAL_DB, layout_array_dnx_algo_flexe_general, sw_state_layout_array[unit][DNX_ALGO_FLEXE_GENERAL_MODULE_ID], DNX_SW_STATE_DNX_ALGO_FLEXE_GENERAL_DB_NOF_PARAMS);

    DNXC_SW_STATE_FUNC_RETURN;
}

#endif /* BCM_DNX_SUPPORT*/ 
#undef BSL_LOG_MODULE
