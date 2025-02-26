/** \file algo/swstate/auto_generated/layout/instru_layout.c
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

#include <bcm_int/dnx/algo/swstate/auto_generated/types/instru_types.h>
#include <bcm_int/dnx/algo/swstate/auto_generated/layout/instru_layout.h>

dnxc_sw_state_layout_t layout_array_instru[DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_INSTRU_NOF_PARAMS)];

shr_error_e
instru_init_layout_structure(int unit)
{

    int idx;

    DNXC_SW_STATE_INIT_FUNC_DEFS;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_INSTRU);
    layout_array_instru[idx].name = "instru";
    layout_array_instru[idx].type = "instru_sw_state_t";
    layout_array_instru[idx].doc = "SW state for instru";
    layout_array_instru[idx].sum_of_allocation = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_instru[idx].size_of = sizeof(instru_sw_state_t);
    layout_array_instru[idx].parent  = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_instru[idx].first_child_index = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_INSTRU__FIRST);
    layout_array_instru[idx].last_child_index = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_INSTRU__LAST)-1;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_INSTRU__SFLOW_INFO);
    layout_array_instru[idx].name = "instru__sflow_info";
    layout_array_instru[idx].type = "sflow_info_t";
    layout_array_instru[idx].doc = "SW state for sFlow";
    layout_array_instru[idx].sum_of_allocation = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_instru[idx].size_of = sizeof(sflow_info_t);
    layout_array_instru[idx].parent  = 0;
    layout_array_instru[idx].first_child_index = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_INSTRU__SFLOW_INFO__FIRST);
    layout_array_instru[idx].last_child_index = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_INSTRU__SFLOW_INFO__LAST)-1;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_INSTRU__EVENTOR_INFO);
    layout_array_instru[idx].name = "instru__eventor_info";
    layout_array_instru[idx].type = "eventor_info_t";
    layout_array_instru[idx].doc = "SW state for Eventor";
    layout_array_instru[idx].sum_of_allocation = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_instru[idx].size_of = sizeof(eventor_info_t);
    layout_array_instru[idx].parent  = 0;
    layout_array_instru[idx].first_child_index = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_INSTRU__EVENTOR_INFO__FIRST);
    layout_array_instru[idx].last_child_index = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_INSTRU__EVENTOR_INFO__LAST)-1;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_INSTRU__TRIGGER_INFO);
    layout_array_instru[idx].name = "instru__trigger_info";
    layout_array_instru[idx].type = "synced_trigger_config_t";
    layout_array_instru[idx].doc = "SW state for synced triggersr";
    layout_array_instru[idx].sum_of_allocation = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_instru[idx].size_of = sizeof(synced_trigger_config_t);
    layout_array_instru[idx].array_indexes[0].num_elements = bcmInstruSyncedTriggerTypeCount;
    layout_array_instru[idx].array_indexes[0].index_type = DNXC_SWSTATE_ARRAY_INDEX_STATIC;
    layout_array_instru[idx].parent  = 0;
    layout_array_instru[idx].first_child_index = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_INSTRU__TRIGGER_INFO__FIRST);
    layout_array_instru[idx].last_child_index = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_INSTRU__TRIGGER_INFO__LAST)-1;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_INSTRU__SFLOW_INFO__SFLOW_DESTINATION_PROFILE);
    layout_array_instru[idx].name = "instru__sflow_info__sflow_destination_profile";
    layout_array_instru[idx].type = "dnx_algo_template_t";
    layout_array_instru[idx].doc = "Virtual template keeping track of sFlow destinations.";
    layout_array_instru[idx].sum_of_allocation = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_instru[idx].size_of = sizeof(dnx_algo_template_t);
    layout_array_instru[idx].parent  = 1;
    layout_array_instru[idx].first_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_instru[idx].last_child_index = DNXC_SW_STATE_LAYOUT_INVALID;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_INSTRU__SFLOW_INFO__RAW_OUTLIFS_BY_PROFILE);
    layout_array_instru[idx].name = "instru__sflow_info__raw_outlifs_by_profile";
    layout_array_instru[idx].type = "int**";
    layout_array_instru[idx].doc = "Map between udp tunnel profile to sFlow RAW stack.";
    layout_array_instru[idx].sum_of_allocation = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_instru[idx].size_of = sizeof(int**);
    layout_array_instru[idx].array_indexes[0].num_elements = dnx_data_instru.sflow.max_nof_sflow_encaps_get(unit);
    layout_array_instru[idx].array_indexes[0].index_type = DNXC_SWSTATE_ARRAY_INDEX_DYNAMIC_DNX_DATA;
    layout_array_instru[idx].array_indexes[1].num_elements = dnx_data_instru.sflow.nof_sflow_raw_entries_per_stack_get(unit);
    layout_array_instru[idx].array_indexes[1].index_type = DNXC_SWSTATE_ARRAY_INDEX_DYNAMIC_DNX_DATA;
    layout_array_instru[idx].parent  = 1;
    layout_array_instru[idx].first_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_instru[idx].last_child_index = DNXC_SW_STATE_LAYOUT_INVALID;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_INSTRU__SFLOW_INFO__SFLOW_ENCAP_TO_SFLOW_DESTINATION_PROFILE);
    layout_array_instru[idx].name = "instru__sflow_info__sflow_encap_to_sflow_destination_profile";
    layout_array_instru[idx].type = "sw_state_htbl_t";
    layout_array_instru[idx].doc = "Map between the sFlow profile and the udp tunnel profile.";
    layout_array_instru[idx].sum_of_allocation = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_instru[idx].size_of = sizeof(sw_state_htbl_t);
    layout_array_instru[idx].parent  = 1;
    layout_array_instru[idx].first_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_instru[idx].last_child_index = DNXC_SW_STATE_LAYOUT_INVALID;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_INSTRU__SFLOW_INFO__NOF_SFLOW_ENCAPS);
    layout_array_instru[idx].name = "instru__sflow_info__nof_sflow_encaps";
    layout_array_instru[idx].type = "int";
    layout_array_instru[idx].doc = "Number of allocated encap entries.                     This number can't exceed the maximum.";
    layout_array_instru[idx].sum_of_allocation = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_instru[idx].size_of = sizeof(int);
    layout_array_instru[idx].parent  = 1;
    layout_array_instru[idx].first_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_instru[idx].last_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_instru[idx].labels = DNXC_SW_STATE_LAYOUT_LABEL_COUNTER;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_INSTRU__SFLOW_INFO__AGENT_IP_ADDRESS);
    layout_array_instru[idx].name = "instru__sflow_info__agent_ip_address";
    layout_array_instru[idx].type = "uint32";
    layout_array_instru[idx].doc = "Global agent ip address for sFlow";
    layout_array_instru[idx].sum_of_allocation = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_instru[idx].size_of = sizeof(uint32);
    layout_array_instru[idx].parent  = 1;
    layout_array_instru[idx].first_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_instru[idx].last_child_index = DNXC_SW_STATE_LAYOUT_INVALID;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_INSTRU__EVENTOR_INFO__FLAGS);
    layout_array_instru[idx].name = "instru__eventor_info__flags";
    layout_array_instru[idx].type = "uint32";
    layout_array_instru[idx].doc = "flags.";
    layout_array_instru[idx].sum_of_allocation = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_instru[idx].size_of = sizeof(uint32);
    layout_array_instru[idx].parent  = 2;
    layout_array_instru[idx].first_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_instru[idx].last_child_index = DNXC_SW_STATE_LAYOUT_INVALID;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_INSTRU__EVENTOR_INFO__RX_SRAM_BANKS_BITMAP);
    layout_array_instru[idx].name = "instru__eventor_info__rx_sram_banks_bitmap";
    layout_array_instru[idx].type = "SHR_BITDCL*";
    layout_array_instru[idx].doc = "bitmap of sram banks used for rx.";
    layout_array_instru[idx].sum_of_allocation = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_instru[idx].size_of = sizeof(SHR_BITDCL*);
    layout_array_instru[idx].array_indexes[0].num_elements = dnx_data_instru.eventor.nof_sram_banks_get(unit);
    layout_array_instru[idx].array_indexes[0].index_type = DNXC_SWSTATE_ARRAY_INDEX_BITMAP;
    layout_array_instru[idx].parent  = 2;
    layout_array_instru[idx].first_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_instru[idx].last_child_index = DNXC_SW_STATE_LAYOUT_INVALID;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_INSTRU__EVENTOR_INFO__BUILDER_CONFIGURED_BITMAP);
    layout_array_instru[idx].name = "instru__eventor_info__builder_configured_bitmap";
    layout_array_instru[idx].type = "SHR_BITDCL*";
    layout_array_instru[idx].doc = "bitmap of configured builders.";
    layout_array_instru[idx].sum_of_allocation = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_instru[idx].size_of = sizeof(SHR_BITDCL*);
    layout_array_instru[idx].array_indexes[0].num_elements = dnx_data_instru.eventor.nof_builders_get(unit);
    layout_array_instru[idx].array_indexes[0].index_type = DNXC_SWSTATE_ARRAY_INDEX_BITMAP;
    layout_array_instru[idx].parent  = 2;
    layout_array_instru[idx].first_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_instru[idx].last_child_index = DNXC_SW_STATE_LAYOUT_INVALID;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_INSTRU__EVENTOR_INFO__RX_CONTEXTS_BITMAP);
    layout_array_instru[idx].name = "instru__eventor_info__rx_contexts_bitmap";
    layout_array_instru[idx].type = "SHR_BITDCL*";
    layout_array_instru[idx].doc = "bitmap of used rx contexts.";
    layout_array_instru[idx].sum_of_allocation = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_instru[idx].size_of = sizeof(SHR_BITDCL*);
    layout_array_instru[idx].array_indexes[0].num_elements = dnx_data_instru.eventor.nof_contexts_get(unit);
    layout_array_instru[idx].array_indexes[0].index_type = DNXC_SWSTATE_ARRAY_INDEX_BITMAP;
    layout_array_instru[idx].parent  = 2;
    layout_array_instru[idx].first_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_instru[idx].last_child_index = DNXC_SW_STATE_LAYOUT_INVALID;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_INSTRU__EVENTOR_INFO__RX_CONTEXTS_INFO);
    layout_array_instru[idx].name = "instru__eventor_info__rx_contexts_info";
    layout_array_instru[idx].type = "eventor_rx_context_info_t*";
    layout_array_instru[idx].doc = "eventor context info.";
    layout_array_instru[idx].sum_of_allocation = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_instru[idx].size_of = sizeof(eventor_rx_context_info_t*);
    layout_array_instru[idx].array_indexes[0].num_elements = dnx_data_instru.eventor.nof_contexts_get(unit);
    layout_array_instru[idx].array_indexes[0].index_type = DNXC_SWSTATE_ARRAY_INDEX_DYNAMIC_DNX_DATA;
    layout_array_instru[idx].parent  = 2;
    layout_array_instru[idx].first_child_index = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_INSTRU__EVENTOR_INFO__RX_CONTEXTS_INFO__FIRST);
    layout_array_instru[idx].last_child_index = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_INSTRU__EVENTOR_INFO__RX_CONTEXTS_INFO__LAST)-1;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_INSTRU__EVENTOR_INFO__TX_CONTEXTS_BITMAP);
    layout_array_instru[idx].name = "instru__eventor_info__tx_contexts_bitmap";
    layout_array_instru[idx].type = "SHR_BITDCL*";
    layout_array_instru[idx].doc = "bitmap of used tx contexts.";
    layout_array_instru[idx].sum_of_allocation = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_instru[idx].size_of = sizeof(SHR_BITDCL*);
    layout_array_instru[idx].array_indexes[0].num_elements = dnx_data_instru.eventor.nof_contexts_get(unit);
    layout_array_instru[idx].array_indexes[0].index_type = DNXC_SWSTATE_ARRAY_INDEX_BITMAP;
    layout_array_instru[idx].parent  = 2;
    layout_array_instru[idx].first_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_instru[idx].last_child_index = DNXC_SW_STATE_LAYOUT_INVALID;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_INSTRU__EVENTOR_INFO__TX_CONTEXTS_QUEUE_TYPE_BITMAP);
    layout_array_instru[idx].name = "instru__eventor_info__tx_contexts_queue_type_bitmap";
    layout_array_instru[idx].type = "SHR_BITDCL*";
    layout_array_instru[idx].doc = "bitmap of used tx contexts queue type.";
    layout_array_instru[idx].sum_of_allocation = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_instru[idx].size_of = sizeof(SHR_BITDCL*);
    layout_array_instru[idx].array_indexes[0].num_elements = dnx_data_instru.eventor.nof_contexts_get(unit);
    layout_array_instru[idx].array_indexes[0].index_type = DNXC_SWSTATE_ARRAY_INDEX_BITMAP;
    layout_array_instru[idx].parent  = 2;
    layout_array_instru[idx].first_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_instru[idx].last_child_index = DNXC_SW_STATE_LAYOUT_INVALID;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_INSTRU__EVENTOR_INFO__TX_SRAM_BANKS_BITMAP);
    layout_array_instru[idx].name = "instru__eventor_info__tx_sram_banks_bitmap";
    layout_array_instru[idx].type = "SHR_BITDCL*";
    layout_array_instru[idx].doc = "bitmap of sram banks used for tx.";
    layout_array_instru[idx].sum_of_allocation = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_instru[idx].size_of = sizeof(SHR_BITDCL*);
    layout_array_instru[idx].array_indexes[0].num_elements = dnx_data_instru.eventor.nof_sram_banks_get(unit);
    layout_array_instru[idx].array_indexes[0].index_type = DNXC_SWSTATE_ARRAY_INDEX_BITMAP;
    layout_array_instru[idx].parent  = 2;
    layout_array_instru[idx].first_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_instru[idx].last_child_index = DNXC_SW_STATE_LAYOUT_INVALID;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_INSTRU__EVENTOR_INFO__TX_CONTEXTS_INFO);
    layout_array_instru[idx].name = "instru__eventor_info__tx_contexts_info";
    layout_array_instru[idx].type = "eventor_tx_context_info_t*";
    layout_array_instru[idx].doc = "eventor context info.";
    layout_array_instru[idx].sum_of_allocation = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_instru[idx].size_of = sizeof(eventor_tx_context_info_t*);
    layout_array_instru[idx].array_indexes[0].num_elements = dnx_data_instru.eventor.nof_contexts_get(unit);
    layout_array_instru[idx].array_indexes[0].index_type = DNXC_SWSTATE_ARRAY_INDEX_DYNAMIC_DNX_DATA;
    layout_array_instru[idx].parent  = 2;
    layout_array_instru[idx].first_child_index = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_INSTRU__EVENTOR_INFO__TX_CONTEXTS_INFO__FIRST);
    layout_array_instru[idx].last_child_index = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_INSTRU__EVENTOR_INFO__TX_CONTEXTS_INFO__LAST)-1;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_INSTRU__EVENTOR_INFO__RX_CONTEXTS_INFO__CONTEXT_TYPE);
    layout_array_instru[idx].name = "instru__eventor_info__rx_contexts_info__context_type";
    layout_array_instru[idx].type = "uint32";
    layout_array_instru[idx].doc = "rx context type.";
    layout_array_instru[idx].sum_of_allocation = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_instru[idx].size_of = sizeof(uint32);
    layout_array_instru[idx].parent  = 13;
    layout_array_instru[idx].first_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_instru[idx].last_child_index = DNXC_SW_STATE_LAYOUT_INVALID;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_INSTRU__EVENTOR_INFO__RX_CONTEXTS_INFO__BUFFER0_OFFSET);
    layout_array_instru[idx].name = "instru__eventor_info__rx_contexts_info__buffer0_offset";
    layout_array_instru[idx].type = "uint32";
    layout_array_instru[idx].doc = "buffer 0 offset.";
    layout_array_instru[idx].sum_of_allocation = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_instru[idx].size_of = sizeof(uint32);
    layout_array_instru[idx].parent  = 13;
    layout_array_instru[idx].first_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_instru[idx].last_child_index = DNXC_SW_STATE_LAYOUT_INVALID;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_INSTRU__EVENTOR_INFO__RX_CONTEXTS_INFO__BUFFER1_OFFSET);
    layout_array_instru[idx].name = "instru__eventor_info__rx_contexts_info__buffer1_offset";
    layout_array_instru[idx].type = "uint32";
    layout_array_instru[idx].doc = "buffer 1 offset.";
    layout_array_instru[idx].sum_of_allocation = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_instru[idx].size_of = sizeof(uint32);
    layout_array_instru[idx].parent  = 13;
    layout_array_instru[idx].first_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_instru[idx].last_child_index = DNXC_SW_STATE_LAYOUT_INVALID;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_INSTRU__EVENTOR_INFO__RX_CONTEXTS_INFO__BUFFER_SIZE);
    layout_array_instru[idx].name = "instru__eventor_info__rx_contexts_info__buffer_size";
    layout_array_instru[idx].type = "uint32";
    layout_array_instru[idx].doc = "buffer size in bytes.";
    layout_array_instru[idx].sum_of_allocation = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_instru[idx].size_of = sizeof(uint32);
    layout_array_instru[idx].parent  = 13;
    layout_array_instru[idx].first_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_instru[idx].last_child_index = DNXC_SW_STATE_LAYOUT_INVALID;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_INSTRU__EVENTOR_INFO__RX_CONTEXTS_INFO__PROGRAM0_OFFSET);
    layout_array_instru[idx].name = "instru__eventor_info__rx_contexts_info__program0_offset";
    layout_array_instru[idx].type = "uint32";
    layout_array_instru[idx].doc = "program 0 offset.";
    layout_array_instru[idx].sum_of_allocation = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_instru[idx].size_of = sizeof(uint32);
    layout_array_instru[idx].parent  = 13;
    layout_array_instru[idx].first_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_instru[idx].last_child_index = DNXC_SW_STATE_LAYOUT_INVALID;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_INSTRU__EVENTOR_INFO__RX_CONTEXTS_INFO__PROGRAM1_OFFSET);
    layout_array_instru[idx].name = "instru__eventor_info__rx_contexts_info__program1_offset";
    layout_array_instru[idx].type = "uint32";
    layout_array_instru[idx].doc = "program 1 offset.";
    layout_array_instru[idx].sum_of_allocation = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_instru[idx].size_of = sizeof(uint32);
    layout_array_instru[idx].parent  = 13;
    layout_array_instru[idx].first_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_instru[idx].last_child_index = DNXC_SW_STATE_LAYOUT_INVALID;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_INSTRU__EVENTOR_INFO__TX_CONTEXTS_INFO__BUFFER0_OFFSET);
    layout_array_instru[idx].name = "instru__eventor_info__tx_contexts_info__buffer0_offset";
    layout_array_instru[idx].type = "uint32";
    layout_array_instru[idx].doc = "buffer 0 offset.";
    layout_array_instru[idx].sum_of_allocation = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_instru[idx].size_of = sizeof(uint32);
    layout_array_instru[idx].parent  = 17;
    layout_array_instru[idx].first_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_instru[idx].last_child_index = DNXC_SW_STATE_LAYOUT_INVALID;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_INSTRU__EVENTOR_INFO__TX_CONTEXTS_INFO__BUFFER1_OFFSET);
    layout_array_instru[idx].name = "instru__eventor_info__tx_contexts_info__buffer1_offset";
    layout_array_instru[idx].type = "uint32";
    layout_array_instru[idx].doc = "buffer 1 offset.";
    layout_array_instru[idx].sum_of_allocation = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_instru[idx].size_of = sizeof(uint32);
    layout_array_instru[idx].parent  = 17;
    layout_array_instru[idx].first_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_instru[idx].last_child_index = DNXC_SW_STATE_LAYOUT_INVALID;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_INSTRU__EVENTOR_INFO__TX_CONTEXTS_INFO__BUFFER_SIZE);
    layout_array_instru[idx].name = "instru__eventor_info__tx_contexts_info__buffer_size";
    layout_array_instru[idx].type = "uint32";
    layout_array_instru[idx].doc = "buffer size in bytes.";
    layout_array_instru[idx].sum_of_allocation = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_instru[idx].size_of = sizeof(uint32);
    layout_array_instru[idx].parent  = 17;
    layout_array_instru[idx].first_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_instru[idx].last_child_index = DNXC_SW_STATE_LAYOUT_INVALID;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_INSTRU__EVENTOR_INFO__TX_CONTEXTS_INFO__PROGRAM0_OFFSET);
    layout_array_instru[idx].name = "instru__eventor_info__tx_contexts_info__program0_offset";
    layout_array_instru[idx].type = "uint32";
    layout_array_instru[idx].doc = "program 0 offset.";
    layout_array_instru[idx].sum_of_allocation = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_instru[idx].size_of = sizeof(uint32);
    layout_array_instru[idx].parent  = 17;
    layout_array_instru[idx].first_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_instru[idx].last_child_index = DNXC_SW_STATE_LAYOUT_INVALID;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_INSTRU__EVENTOR_INFO__TX_CONTEXTS_INFO__PROGRAM1_OFFSET);
    layout_array_instru[idx].name = "instru__eventor_info__tx_contexts_info__program1_offset";
    layout_array_instru[idx].type = "uint32";
    layout_array_instru[idx].doc = "program 1 offset.";
    layout_array_instru[idx].sum_of_allocation = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_instru[idx].size_of = sizeof(uint32);
    layout_array_instru[idx].parent  = 17;
    layout_array_instru[idx].first_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_instru[idx].last_child_index = DNXC_SW_STATE_LAYOUT_INVALID;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_INSTRU__EVENTOR_INFO__TX_CONTEXTS_INFO__NOF_OPERATIONS);
    layout_array_instru[idx].name = "instru__eventor_info__tx_contexts_info__nof_operations";
    layout_array_instru[idx].type = "uint32";
    layout_array_instru[idx].doc = "number of context operations.";
    layout_array_instru[idx].sum_of_allocation = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_instru[idx].size_of = sizeof(uint32);
    layout_array_instru[idx].parent  = 17;
    layout_array_instru[idx].first_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_instru[idx].last_child_index = DNXC_SW_STATE_LAYOUT_INVALID;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_INSTRU__EVENTOR_INFO__TX_CONTEXTS_INFO__NOF_CONST_VALUES);
    layout_array_instru[idx].name = "instru__eventor_info__tx_contexts_info__nof_const_values";
    layout_array_instru[idx].type = "uint32";
    layout_array_instru[idx].doc = "number of context constant values";
    layout_array_instru[idx].sum_of_allocation = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_instru[idx].size_of = sizeof(uint32);
    layout_array_instru[idx].parent  = 17;
    layout_array_instru[idx].first_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_instru[idx].last_child_index = DNXC_SW_STATE_LAYOUT_INVALID;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_INSTRU__EVENTOR_INFO__TX_CONTEXTS_INFO__BUILDERS);
    layout_array_instru[idx].name = "instru__eventor_info__tx_contexts_info__builders";
    layout_array_instru[idx].type = "uint32";
    layout_array_instru[idx].doc = "context used builders bitmap";
    layout_array_instru[idx].sum_of_allocation = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_instru[idx].size_of = sizeof(uint32);
    layout_array_instru[idx].parent  = 17;
    layout_array_instru[idx].first_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_instru[idx].last_child_index = DNXC_SW_STATE_LAYOUT_INVALID;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_INSTRU__TRIGGER_INFO__FLAGS);
    layout_array_instru[idx].name = "instru__trigger_info__flags";
    layout_array_instru[idx].type = "uint32";
    layout_array_instru[idx].doc = "configuration flags";
    layout_array_instru[idx].sum_of_allocation = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_instru[idx].size_of = sizeof(uint32);
    layout_array_instru[idx].parent  = 3;
    layout_array_instru[idx].first_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_instru[idx].last_child_index = DNXC_SW_STATE_LAYOUT_INVALID;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_INSTRU__TRIGGER_INFO__START_TIME);
    layout_array_instru[idx].name = "instru__trigger_info__start_time";
    layout_array_instru[idx].type = "uint64";
    layout_array_instru[idx].doc = "ns value for start time";
    layout_array_instru[idx].sum_of_allocation = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_instru[idx].size_of = sizeof(uint64);
    layout_array_instru[idx].parent  = 3;
    layout_array_instru[idx].first_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_instru[idx].last_child_index = DNXC_SW_STATE_LAYOUT_INVALID;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_INSTRU__TRIGGER_INFO__TRIGGER_PERIOD);
    layout_array_instru[idx].name = "instru__trigger_info__trigger_period";
    layout_array_instru[idx].type = "uint64";
    layout_array_instru[idx].doc = "number of nanoseconds between triggers";
    layout_array_instru[idx].sum_of_allocation = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_instru[idx].size_of = sizeof(uint64);
    layout_array_instru[idx].parent  = 3;
    layout_array_instru[idx].first_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_instru[idx].last_child_index = DNXC_SW_STATE_LAYOUT_INVALID;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_INSTRU__TRIGGER_INFO__NOF_TRIGGERS);
    layout_array_instru[idx].name = "instru__trigger_info__nof_triggers";
    layout_array_instru[idx].type = "uint32";
    layout_array_instru[idx].doc = "Number of triggers to generate, 0 means infinite.";
    layout_array_instru[idx].sum_of_allocation = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_instru[idx].size_of = sizeof(uint32);
    layout_array_instru[idx].parent  = 3;
    layout_array_instru[idx].first_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_instru[idx].last_child_index = DNXC_SW_STATE_LAYOUT_INVALID;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_INSTRU__TRIGGER_INFO__ENABLE);
    layout_array_instru[idx].name = "instru__trigger_info__enable";
    layout_array_instru[idx].type = "uint32";
    layout_array_instru[idx].doc = "trigger status 1- enable, 0 - disable.";
    layout_array_instru[idx].sum_of_allocation = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_instru[idx].size_of = sizeof(uint32);
    layout_array_instru[idx].parent  = 3;
    layout_array_instru[idx].first_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_instru[idx].last_child_index = DNXC_SW_STATE_LAYOUT_INVALID;


    dnxc_sw_state_layout_init_structure(unit, DNX_SW_STATE_INSTRU, layout_array_instru, sw_state_layout_array[unit][INSTRU_MODULE_ID], DNX_SW_STATE_INSTRU_NOF_PARAMS);

    DNXC_SW_STATE_FUNC_RETURN;
}

#undef BSL_LOG_MODULE
