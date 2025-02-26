
/*
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2022 Broadcom Inc. All rights reserved.
 */

#ifdef BSL_LOG_MODULE
#error "BSL_LOG_MODULE redefined"
#endif
#define BSL_LOG_MODULE BSL_LS_SWSTATEDNX_GENERAL

#include <soc/dnx/swstate/auto_generated/types/dnx_field_context_types.h>
#include <soc/dnx/swstate/auto_generated/layout/dnx_field_context_layout.h>

dnxc_sw_state_layout_t layout_array_dnx_field_context[DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_DNX_FIELD_CONTEXT_SW_NOF_PARAMS)];

shr_error_e
dnx_field_context_init_layout_structure(int unit)
{

    dnx_field_context_compare_mode_e dnx_field_context_sw__context_info__context_ipmf1_info__compare_info__pair_1__mode__default_val = DNX_FIELD_CONTEXT_COMPARE_MODE_NONE;
    dnx_field_qual_t dnx_field_context_sw__context_info__context_ipmf1_info__compare_info__pair_1__key_info__key_template__key_qual_map__qual_type__default_val = DNX_FIELD_QUAL_TYPE_INVALID;
    dbal_enum_value_field_field_key_e dnx_field_context_sw__context_info__context_ipmf1_info__compare_info__pair_1__key_info__key_id__id__default_val = DNX_FIELD_KEY_ID_INVALID;
    dnx_field_input_type_e dnx_field_context_sw__context_info__context_ipmf1_info__compare_info__pair_1__key_info__attach_info__input_type__default_val = DNX_FIELD_INPUT_TYPE_INVALID;
    int dnx_field_context_sw__context_info__context_ipmf1_info__compare_info__pair_1__key_info__attach_info__input_arg__default_val = 0xFFFF;
    int dnx_field_context_sw__context_info__context_ipmf1_info__compare_info__pair_1__key_info__attach_info__offset__default_val = 0xFFFF;
    dnx_field_qual_t dnx_field_context_sw__context_info__context_ipmf1_info__compare_info__pair_1__key_info__attach_info__base_qual__default_val = DNX_FIELD_QUAL_TYPE_INVALID;
    dnx_field_context_compare_mode_e dnx_field_context_sw__context_info__context_ipmf1_info__compare_info__pair_2__mode__default_val = DNX_FIELD_CONTEXT_COMPARE_MODE_NONE;
    dnx_field_qual_t dnx_field_context_sw__context_info__context_ipmf1_info__compare_info__pair_2__key_info__key_template__key_qual_map__qual_type__default_val = DNX_FIELD_QUAL_TYPE_INVALID;
    dbal_enum_value_field_field_key_e dnx_field_context_sw__context_info__context_ipmf1_info__compare_info__pair_2__key_info__key_id__id__default_val = DNX_FIELD_KEY_ID_INVALID;
    dnx_field_input_type_e dnx_field_context_sw__context_info__context_ipmf1_info__compare_info__pair_2__key_info__attach_info__input_type__default_val = DNX_FIELD_INPUT_TYPE_INVALID;
    int dnx_field_context_sw__context_info__context_ipmf1_info__compare_info__pair_2__key_info__attach_info__input_arg__default_val = 0xFFFF;
    int dnx_field_context_sw__context_info__context_ipmf1_info__compare_info__pair_2__key_info__attach_info__offset__default_val = 0xFFFF;
    dnx_field_qual_t dnx_field_context_sw__context_info__context_ipmf1_info__compare_info__pair_2__key_info__attach_info__base_qual__default_val = DNX_FIELD_QUAL_TYPE_INVALID;
    dnx_field_context_hash_mode_e dnx_field_context_sw__context_info__context_ipmf1_info__hashing_info__mode__default_val = DNX_FIELD_CONTEXT_HASH_MODE_DISABLED;
    dnx_field_qual_t dnx_field_context_sw__context_info__context_ipmf1_info__hashing_info__key_info__key_template__key_qual_map__qual_type__default_val = DNX_FIELD_QUAL_TYPE_INVALID;
    dbal_enum_value_field_field_key_e dnx_field_context_sw__context_info__context_ipmf1_info__hashing_info__key_info__key_id__id__default_val = DNX_FIELD_KEY_ID_INVALID;
    dnx_field_input_type_e dnx_field_context_sw__context_info__context_ipmf1_info__hashing_info__key_info__attach_info__input_type__default_val = DNX_FIELD_INPUT_TYPE_INVALID;
    int dnx_field_context_sw__context_info__context_ipmf1_info__hashing_info__key_info__attach_info__input_arg__default_val = 0xFFFF;
    int dnx_field_context_sw__context_info__context_ipmf1_info__hashing_info__key_info__attach_info__offset__default_val = 0xFFFF;
    dnx_field_qual_t dnx_field_context_sw__context_info__context_ipmf1_info__hashing_info__key_info__attach_info__base_qual__default_val = DNX_FIELD_QUAL_TYPE_INVALID;
    dnx_field_context_t dnx_field_context_sw__context_info__context_ipmf2_info__cascaded_from__default_val = DNX_FIELD_CONTEXT_ID_INVALID;
    dnx_field_context_state_table_mode_e dnx_field_context_sw__context_info__state_table_info__mode__default_val = DNX_FIELD_CONTEXT_STATE_TABLE_MODE_DISABLED;


    int idx;

    DNXC_SW_STATE_INIT_FUNC_DEFS;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_DNX_FIELD_CONTEXT_SW);
    layout_array_dnx_field_context[idx].name = "dnx_field_context_sw";
    layout_array_dnx_field_context[idx].type = "dnx_field_context_sw_t";
    layout_array_dnx_field_context[idx].doc = "Holds the needed information for each field context per stage in the system.";
    layout_array_dnx_field_context[idx].total_size = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].size_of = sizeof(dnx_field_context_sw_t);
    layout_array_dnx_field_context[idx].parent  = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].first_child_index = 1;
    layout_array_dnx_field_context[idx].last_child_index = 1;
    layout_array_dnx_field_context[idx].next_node_index = 1;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_DNX_FIELD_CONTEXT_SW__CONTEXT_INFO);
    layout_array_dnx_field_context[idx].name = "dnx_field_context_sw__context_info";
    layout_array_dnx_field_context[idx].type = "dnx_field_context_sw_info_t*";
    layout_array_dnx_field_context[idx].doc = "Specifies the context info of each context in the system";
    layout_array_dnx_field_context[idx].total_size = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].size_of = sizeof(dnx_field_context_sw_info_t*);
    layout_array_dnx_field_context[idx].array_indexes[0].size = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].array_indexes[0].index_type = DNXC_SWSTATE_ARRAY_INDEX_DYNAMIC_DNX_DATA;
    layout_array_dnx_field_context[idx].parent  = 0;
    layout_array_dnx_field_context[idx].first_child_index = 2;
    layout_array_dnx_field_context[idx].last_child_index = 5;
    layout_array_dnx_field_context[idx].next_node_index = DNXC_SW_STATE_LAYOUT_INVALID;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_DNX_FIELD_CONTEXT_SW__CONTEXT_INFO__CONTEXT_IPMF1_INFO);
    layout_array_dnx_field_context[idx].name = "dnx_field_context_sw__context_info__context_ipmf1_info";
    layout_array_dnx_field_context[idx].type = "dnx_field_context_ipmf1_sw_info_t";
    layout_array_dnx_field_context[idx].doc = "All needed information for each field context in iPMF1 stage";
    layout_array_dnx_field_context[idx].total_size = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].size_of = sizeof(dnx_field_context_ipmf1_sw_info_t);
    layout_array_dnx_field_context[idx].parent  = 1;
    layout_array_dnx_field_context[idx].first_child_index = 6;
    layout_array_dnx_field_context[idx].last_child_index = 7;
    layout_array_dnx_field_context[idx].next_node_index = 3;
    layout_array_dnx_field_context[idx].labels = DNXC_SW_STATE_LAYOUT_LABEL_FORCE_INTERFACE_GENERATION;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_DNX_FIELD_CONTEXT_SW__CONTEXT_INFO__CONTEXT_IPMF2_INFO);
    layout_array_dnx_field_context[idx].name = "dnx_field_context_sw__context_info__context_ipmf2_info";
    layout_array_dnx_field_context[idx].type = "dnx_field_context_ipmf2_sw_info_t";
    layout_array_dnx_field_context[idx].doc = "All needed information for each field context in iPMF2 stage";
    layout_array_dnx_field_context[idx].total_size = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].size_of = sizeof(dnx_field_context_ipmf2_sw_info_t);
    layout_array_dnx_field_context[idx].parent  = 1;
    layout_array_dnx_field_context[idx].first_child_index = 64;
    layout_array_dnx_field_context[idx].last_child_index = 64;
    layout_array_dnx_field_context[idx].next_node_index = 4;
    layout_array_dnx_field_context[idx].labels = DNXC_SW_STATE_LAYOUT_LABEL_FORCE_INTERFACE_GENERATION;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_DNX_FIELD_CONTEXT_SW__CONTEXT_INFO__STATE_TABLE_INFO);
    layout_array_dnx_field_context[idx].name = "dnx_field_context_sw__context_info__state_table_info";
    layout_array_dnx_field_context[idx].type = "dnx_field_context_state_table_sw_info_t";
    layout_array_dnx_field_context[idx].doc = "Specifies the state table information (such as state table key template, key ids) of the context";
    layout_array_dnx_field_context[idx].total_size = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].size_of = sizeof(dnx_field_context_state_table_sw_info_t);
    layout_array_dnx_field_context[idx].parent  = 1;
    layout_array_dnx_field_context[idx].first_child_index = 65;
    layout_array_dnx_field_context[idx].last_child_index = 66;
    layout_array_dnx_field_context[idx].next_node_index = 5;
    layout_array_dnx_field_context[idx].labels = DNXC_SW_STATE_LAYOUT_LABEL_FORCE_INTERFACE_GENERATION;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_DNX_FIELD_CONTEXT_SW__CONTEXT_INFO__NAME);
    layout_array_dnx_field_context[idx].name = "dnx_field_context_sw__context_info__name";
    layout_array_dnx_field_context[idx].type = "dnx_field_context_name_t";
    layout_array_dnx_field_context[idx].doc = "Context name per stage.";
    layout_array_dnx_field_context[idx].total_size = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].size_of = sizeof(dnx_field_context_name_t);
    layout_array_dnx_field_context[idx].array_indexes[0].size = DNX_FIELD_STAGE_NOF;
    layout_array_dnx_field_context[idx].array_indexes[0].index_type = DNXC_SWSTATE_ARRAY_INDEX_STATIC;
    layout_array_dnx_field_context[idx].parent  = 1;
    layout_array_dnx_field_context[idx].first_child_index = 67;
    layout_array_dnx_field_context[idx].last_child_index = 67;
    layout_array_dnx_field_context[idx].next_node_index = DNXC_SW_STATE_LAYOUT_INVALID;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_DNX_FIELD_CONTEXT_SW__CONTEXT_INFO__CONTEXT_IPMF1_INFO__COMPARE_INFO);
    layout_array_dnx_field_context[idx].name = "dnx_field_context_sw__context_info__context_ipmf1_info__compare_info";
    layout_array_dnx_field_context[idx].type = "dnx_field_context_compare_info_t";
    layout_array_dnx_field_context[idx].doc = "Holds all information needed for compare (mode/keys allocated/etc...)";
    layout_array_dnx_field_context[idx].total_size = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].size_of = sizeof(dnx_field_context_compare_info_t);
    layout_array_dnx_field_context[idx].parent  = 2;
    layout_array_dnx_field_context[idx].first_child_index = 8;
    layout_array_dnx_field_context[idx].last_child_index = 9;
    layout_array_dnx_field_context[idx].next_node_index = 7;
    layout_array_dnx_field_context[idx].labels = DNXC_SW_STATE_LAYOUT_LABEL_FORCE_INTERFACE_GENERATION;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_DNX_FIELD_CONTEXT_SW__CONTEXT_INFO__CONTEXT_IPMF1_INFO__HASHING_INFO);
    layout_array_dnx_field_context[idx].name = "dnx_field_context_sw__context_info__context_ipmf1_info__hashing_info";
    layout_array_dnx_field_context[idx].type = "dnx_field_context_hashing_info_t";
    layout_array_dnx_field_context[idx].doc = "Specifies the hashing information (such as hash key template, key ids) of the context";
    layout_array_dnx_field_context[idx].total_size = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].size_of = sizeof(dnx_field_context_hashing_info_t);
    layout_array_dnx_field_context[idx].parent  = 2;
    layout_array_dnx_field_context[idx].first_child_index = 46;
    layout_array_dnx_field_context[idx].last_child_index = 48;
    layout_array_dnx_field_context[idx].next_node_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].labels = DNXC_SW_STATE_LAYOUT_LABEL_FORCE_INTERFACE_GENERATION;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_DNX_FIELD_CONTEXT_SW__CONTEXT_INFO__CONTEXT_IPMF1_INFO__COMPARE_INFO__PAIR_1);
    layout_array_dnx_field_context[idx].name = "dnx_field_context_sw__context_info__context_ipmf1_info__compare_info__pair_1";
    layout_array_dnx_field_context[idx].type = "dnx_field_context_compare_mode_info_t";
    layout_array_dnx_field_context[idx].doc = "Compare pair 1 information (works on Keys F and G )";
    layout_array_dnx_field_context[idx].total_size = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].size_of = sizeof(dnx_field_context_compare_mode_info_t);
    layout_array_dnx_field_context[idx].parent  = 6;
    layout_array_dnx_field_context[idx].first_child_index = 10;
    layout_array_dnx_field_context[idx].last_child_index = 12;
    layout_array_dnx_field_context[idx].next_node_index = 9;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_DNX_FIELD_CONTEXT_SW__CONTEXT_INFO__CONTEXT_IPMF1_INFO__COMPARE_INFO__PAIR_2);
    layout_array_dnx_field_context[idx].name = "dnx_field_context_sw__context_info__context_ipmf1_info__compare_info__pair_2";
    layout_array_dnx_field_context[idx].type = "dnx_field_context_compare_mode_info_t";
    layout_array_dnx_field_context[idx].doc = "Compare pair 2 information (works on Keys H and I )";
    layout_array_dnx_field_context[idx].total_size = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].size_of = sizeof(dnx_field_context_compare_mode_info_t);
    layout_array_dnx_field_context[idx].parent  = 6;
    layout_array_dnx_field_context[idx].first_child_index = 28;
    layout_array_dnx_field_context[idx].last_child_index = 30;
    layout_array_dnx_field_context[idx].next_node_index = DNXC_SW_STATE_LAYOUT_INVALID;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_DNX_FIELD_CONTEXT_SW__CONTEXT_INFO__CONTEXT_IPMF1_INFO__COMPARE_INFO__PAIR_1__MODE);
    layout_array_dnx_field_context[idx].name = "dnx_field_context_sw__context_info__context_ipmf1_info__compare_info__pair_1__mode";
    layout_array_dnx_field_context[idx].type = "dnx_field_context_compare_mode_e";
    layout_array_dnx_field_context[idx].doc = "mode for each compare operation NONE/SINGLE/DOUBLE";
    layout_array_dnx_field_context[idx].default_value= &(dnx_field_context_sw__context_info__context_ipmf1_info__compare_info__pair_1__mode__default_val);
    layout_array_dnx_field_context[idx].total_size = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].size_of = sizeof(dnx_field_context_compare_mode_e);
    layout_array_dnx_field_context[idx].parent  = 8;
    layout_array_dnx_field_context[idx].first_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].last_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].next_node_index = 11;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_DNX_FIELD_CONTEXT_SW__CONTEXT_INFO__CONTEXT_IPMF1_INFO__COMPARE_INFO__PAIR_1__IS_SET);
    layout_array_dnx_field_context[idx].name = "dnx_field_context_sw__context_info__context_ipmf1_info__compare_info__pair_1__is_set";
    layout_array_dnx_field_context[idx].type = "uint8";
    layout_array_dnx_field_context[idx].doc = "Whether the qualifiers were set for the compare key";
    layout_array_dnx_field_context[idx].total_size = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].size_of = sizeof(uint8);
    layout_array_dnx_field_context[idx].parent  = 8;
    layout_array_dnx_field_context[idx].first_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].last_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].next_node_index = 12;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_DNX_FIELD_CONTEXT_SW__CONTEXT_INFO__CONTEXT_IPMF1_INFO__COMPARE_INFO__PAIR_1__KEY_INFO);
    layout_array_dnx_field_context[idx].name = "dnx_field_context_sw__context_info__context_ipmf1_info__compare_info__pair_1__key_info";
    layout_array_dnx_field_context[idx].type = "dnx_field_context_key_info_t";
    layout_array_dnx_field_context[idx].doc = "Compare key information";
    layout_array_dnx_field_context[idx].total_size = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].size_of = sizeof(dnx_field_context_key_info_t);
    layout_array_dnx_field_context[idx].array_indexes[0].size = DNX_DATA_MAX_FIELD_COMPARE_NOF_KEYS;
    layout_array_dnx_field_context[idx].array_indexes[0].index_type = DNXC_SWSTATE_ARRAY_INDEX_STATIC;
    layout_array_dnx_field_context[idx].parent  = 8;
    layout_array_dnx_field_context[idx].first_child_index = 13;
    layout_array_dnx_field_context[idx].last_child_index = 15;
    layout_array_dnx_field_context[idx].next_node_index = DNXC_SW_STATE_LAYOUT_INVALID;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_DNX_FIELD_CONTEXT_SW__CONTEXT_INFO__CONTEXT_IPMF1_INFO__COMPARE_INFO__PAIR_1__KEY_INFO__KEY_TEMPLATE);
    layout_array_dnx_field_context[idx].name = "dnx_field_context_sw__context_info__context_ipmf1_info__compare_info__pair_1__key_info__key_template";
    layout_array_dnx_field_context[idx].type = "dnx_field_key_template_t";
    layout_array_dnx_field_context[idx].doc = "Key template";
    layout_array_dnx_field_context[idx].total_size = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].size_of = sizeof(dnx_field_key_template_t);
    layout_array_dnx_field_context[idx].parent  = 12;
    layout_array_dnx_field_context[idx].first_child_index = 16;
    layout_array_dnx_field_context[idx].last_child_index = 17;
    layout_array_dnx_field_context[idx].next_node_index = 14;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_DNX_FIELD_CONTEXT_SW__CONTEXT_INFO__CONTEXT_IPMF1_INFO__COMPARE_INFO__PAIR_1__KEY_INFO__KEY_ID);
    layout_array_dnx_field_context[idx].name = "dnx_field_context_sw__context_info__context_ipmf1_info__compare_info__pair_1__key_info__key_id";
    layout_array_dnx_field_context[idx].type = "dnx_field_key_id_t";
    layout_array_dnx_field_context[idx].doc = "Key Ids";
    layout_array_dnx_field_context[idx].total_size = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].size_of = sizeof(dnx_field_key_id_t);
    layout_array_dnx_field_context[idx].parent  = 12;
    layout_array_dnx_field_context[idx].first_child_index = 21;
    layout_array_dnx_field_context[idx].last_child_index = 23;
    layout_array_dnx_field_context[idx].next_node_index = 15;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_DNX_FIELD_CONTEXT_SW__CONTEXT_INFO__CONTEXT_IPMF1_INFO__COMPARE_INFO__PAIR_1__KEY_INFO__ATTACH_INFO);
    layout_array_dnx_field_context[idx].name = "dnx_field_context_sw__context_info__context_ipmf1_info__compare_info__pair_1__key_info__attach_info";
    layout_array_dnx_field_context[idx].type = "dnx_field_qual_attach_info_t";
    layout_array_dnx_field_context[idx].doc = "Indicate how to read the relevant qualifier from PBUS The information is aligned to the qualifier types array above Number of elements set by key_template.key_qual_map[].qual_type array";
    layout_array_dnx_field_context[idx].total_size = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].size_of = sizeof(dnx_field_qual_attach_info_t);
    layout_array_dnx_field_context[idx].array_indexes[0].size = DNX_DATA_MAX_FIELD_GROUP_NOF_QUALS_PER_FG;
    layout_array_dnx_field_context[idx].array_indexes[0].index_type = DNXC_SWSTATE_ARRAY_INDEX_STATIC;
    layout_array_dnx_field_context[idx].parent  = 12;
    layout_array_dnx_field_context[idx].first_child_index = 24;
    layout_array_dnx_field_context[idx].last_child_index = 27;
    layout_array_dnx_field_context[idx].next_node_index = DNXC_SW_STATE_LAYOUT_INVALID;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_DNX_FIELD_CONTEXT_SW__CONTEXT_INFO__CONTEXT_IPMF1_INFO__COMPARE_INFO__PAIR_1__KEY_INFO__KEY_TEMPLATE__KEY_QUAL_MAP);
    layout_array_dnx_field_context[idx].name = "dnx_field_context_sw__context_info__context_ipmf1_info__compare_info__pair_1__key_info__key_template__key_qual_map";
    layout_array_dnx_field_context[idx].type = "dnx_field_qual_map_in_key_t";
    layout_array_dnx_field_context[idx].doc = "Mapping of each qualifier inside the key. End of 'valid' entries is marked \n                            by an entry with 'key_qual_map.qual_type = DNX_FIELD_QUAL_TYPE_INVALID'";
    layout_array_dnx_field_context[idx].total_size = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].size_of = sizeof(dnx_field_qual_map_in_key_t);
    layout_array_dnx_field_context[idx].array_indexes[0].size = DNX_DATA_MAX_FIELD_GROUP_NOF_QUALS_PER_FG;
    layout_array_dnx_field_context[idx].array_indexes[0].index_type = DNXC_SWSTATE_ARRAY_INDEX_STATIC;
    layout_array_dnx_field_context[idx].parent  = 13;
    layout_array_dnx_field_context[idx].first_child_index = 18;
    layout_array_dnx_field_context[idx].last_child_index = 20;
    layout_array_dnx_field_context[idx].next_node_index = 17;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_DNX_FIELD_CONTEXT_SW__CONTEXT_INFO__CONTEXT_IPMF1_INFO__COMPARE_INFO__PAIR_1__KEY_INFO__KEY_TEMPLATE__KEY_SIZE_IN_BITS);
    layout_array_dnx_field_context[idx].name = "dnx_field_context_sw__context_info__context_ipmf1_info__compare_info__pair_1__key_info__key_template__key_size_in_bits";
    layout_array_dnx_field_context[idx].type = "uint16";
    layout_array_dnx_field_context[idx].doc = "Hold the actual key size in Bit Resolution,\n                            i.e. sum, in bits, of all qualifiers configured for this key";
    layout_array_dnx_field_context[idx].total_size = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].size_of = sizeof(uint16);
    layout_array_dnx_field_context[idx].parent  = 13;
    layout_array_dnx_field_context[idx].first_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].last_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].next_node_index = DNXC_SW_STATE_LAYOUT_INVALID;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_DNX_FIELD_CONTEXT_SW__CONTEXT_INFO__CONTEXT_IPMF1_INFO__COMPARE_INFO__PAIR_1__KEY_INFO__KEY_TEMPLATE__KEY_QUAL_MAP__QUAL_TYPE);
    layout_array_dnx_field_context[idx].name = "dnx_field_context_sw__context_info__context_ipmf1_info__compare_info__pair_1__key_info__key_template__key_qual_map__qual_type";
    layout_array_dnx_field_context[idx].type = "dnx_field_qual_t";
    layout_array_dnx_field_context[idx].doc = "Qualifier type";
    layout_array_dnx_field_context[idx].default_value= &(dnx_field_context_sw__context_info__context_ipmf1_info__compare_info__pair_1__key_info__key_template__key_qual_map__qual_type__default_val);
    layout_array_dnx_field_context[idx].total_size = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].size_of = sizeof(dnx_field_qual_t);
    layout_array_dnx_field_context[idx].parent  = 16;
    layout_array_dnx_field_context[idx].first_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].last_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].next_node_index = 19;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_DNX_FIELD_CONTEXT_SW__CONTEXT_INFO__CONTEXT_IPMF1_INFO__COMPARE_INFO__PAIR_1__KEY_INFO__KEY_TEMPLATE__KEY_QUAL_MAP__LSB);
    layout_array_dnx_field_context[idx].name = "dnx_field_context_sw__context_info__context_ipmf1_info__compare_info__pair_1__key_info__key_template__key_qual_map__lsb";
    layout_array_dnx_field_context[idx].type = "uint16";
    layout_array_dnx_field_context[idx].doc = "LSB bit of the qualifier inside the key";
    layout_array_dnx_field_context[idx].total_size = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].size_of = sizeof(uint16);
    layout_array_dnx_field_context[idx].parent  = 16;
    layout_array_dnx_field_context[idx].first_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].last_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].next_node_index = 20;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_DNX_FIELD_CONTEXT_SW__CONTEXT_INFO__CONTEXT_IPMF1_INFO__COMPARE_INFO__PAIR_1__KEY_INFO__KEY_TEMPLATE__KEY_QUAL_MAP__SIZE);
    layout_array_dnx_field_context[idx].name = "dnx_field_context_sw__context_info__context_ipmf1_info__compare_info__pair_1__key_info__key_template__key_qual_map__size";
    layout_array_dnx_field_context[idx].type = "uint8";
    layout_array_dnx_field_context[idx].doc = "Size of the qualifier in the key";
    layout_array_dnx_field_context[idx].total_size = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].size_of = sizeof(uint8);
    layout_array_dnx_field_context[idx].parent  = 16;
    layout_array_dnx_field_context[idx].first_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].last_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].next_node_index = DNXC_SW_STATE_LAYOUT_INVALID;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_DNX_FIELD_CONTEXT_SW__CONTEXT_INFO__CONTEXT_IPMF1_INFO__COMPARE_INFO__PAIR_1__KEY_INFO__KEY_ID__ID);
    layout_array_dnx_field_context[idx].name = "dnx_field_context_sw__context_info__context_ipmf1_info__compare_info__pair_1__key_info__key_id__id";
    layout_array_dnx_field_context[idx].type = "dbal_enum_value_field_field_key_e";
    layout_array_dnx_field_context[idx].doc = "Hold the information regarding the key allocated for the Context ID";
    layout_array_dnx_field_context[idx].default_value= &(dnx_field_context_sw__context_info__context_ipmf1_info__compare_info__pair_1__key_info__key_id__id__default_val);
    layout_array_dnx_field_context[idx].total_size = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].size_of = sizeof(dbal_enum_value_field_field_key_e);
    layout_array_dnx_field_context[idx].array_indexes[0].size = DNX_DATA_MAX_FIELD_GROUP_NOF_KEYS_PER_FG_MAX;
    layout_array_dnx_field_context[idx].array_indexes[0].index_type = DNXC_SWSTATE_ARRAY_INDEX_STATIC;
    layout_array_dnx_field_context[idx].parent  = 14;
    layout_array_dnx_field_context[idx].first_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].last_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].next_node_index = 22;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_DNX_FIELD_CONTEXT_SW__CONTEXT_INFO__CONTEXT_IPMF1_INFO__COMPARE_INFO__PAIR_1__KEY_INFO__KEY_ID__OFFSET_ON_FIRST_KEY);
    layout_array_dnx_field_context[idx].name = "dnx_field_context_sw__context_info__context_ipmf1_info__compare_info__pair_1__key_info__key_id__offset_on_first_key";
    layout_array_dnx_field_context[idx].type = "uint8";
    layout_array_dnx_field_context[idx].doc = "Hold the lsb of the allocated bits within the first key.";
    layout_array_dnx_field_context[idx].total_size = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].size_of = sizeof(uint8);
    layout_array_dnx_field_context[idx].parent  = 14;
    layout_array_dnx_field_context[idx].first_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].last_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].next_node_index = 23;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_DNX_FIELD_CONTEXT_SW__CONTEXT_INFO__CONTEXT_IPMF1_INFO__COMPARE_INFO__PAIR_1__KEY_INFO__KEY_ID__NOF_BITS);
    layout_array_dnx_field_context[idx].name = "dnx_field_context_sw__context_info__context_ipmf1_info__compare_info__pair_1__key_info__key_id__nof_bits";
    layout_array_dnx_field_context[idx].type = "uint8";
    layout_array_dnx_field_context[idx].doc = "Hold the number of bits allocated within the key.";
    layout_array_dnx_field_context[idx].total_size = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].size_of = sizeof(uint8);
    layout_array_dnx_field_context[idx].array_indexes[0].size = DNX_DATA_MAX_FIELD_GROUP_NOF_KEYS_PER_FG_MAX;
    layout_array_dnx_field_context[idx].array_indexes[0].index_type = DNXC_SWSTATE_ARRAY_INDEX_STATIC;
    layout_array_dnx_field_context[idx].parent  = 14;
    layout_array_dnx_field_context[idx].first_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].last_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].next_node_index = DNXC_SW_STATE_LAYOUT_INVALID;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_DNX_FIELD_CONTEXT_SW__CONTEXT_INFO__CONTEXT_IPMF1_INFO__COMPARE_INFO__PAIR_1__KEY_INFO__ATTACH_INFO__INPUT_TYPE);
    layout_array_dnx_field_context[idx].name = "dnx_field_context_sw__context_info__context_ipmf1_info__compare_info__pair_1__key_info__attach_info__input_type";
    layout_array_dnx_field_context[idx].type = "dnx_field_input_type_e";
    layout_array_dnx_field_context[idx].doc = "The base of qualifier indicates from which part of the PBUS the info is taken                                                                          \n relevant for all type of qualifiers                                                                          \n DNX_FIELD_INPUT_TYPE_LAYER_FWD  - Takes data from a layer in the header, using the forwarding layer information.                                                                          \n DNX_FIELD_INPUT_TYPE_LAYER_ABSOLUTE - Takes data from a layer in the header, ignoring forwarding layer information.                                                                          \n DNX_FIELD_INPUT_TYPE_META_DATA - Takes data from the Metadata.                                                                          \n DNX_FIELD_INPUT_TYPE_META_DATA2 - Takes data from the native Metadata of iPMF2, relevant only for iPMF2.                                                                          \n DNX_FIELD_INPUT_TYPE_LAYER_RECORDS_FWD  -  Takes data about a layer in the header (layer record), using the forwarding layer information.                                                                          \n DNX_FIELD_INPUT_TYPE_LAYER_RECORDS_ABSOLUTE - Takes data about a layer in the header (layer record), ignoring the forwarding layer information.                                                                          \n DNX_FIELD_INPUT_TYPE_EXTERNAL - Takes data from the results of an external stage field group.                                                                          \n DNX_FIELD_INPUT_TYPE_CASCADED - Takes data from the result of a field group from an earlier PMF stage, using cascading.                                                                          \n DNX_FIELD_INPUT_TYPE_CONST - Writes a constant value.";
    layout_array_dnx_field_context[idx].default_value= &(dnx_field_context_sw__context_info__context_ipmf1_info__compare_info__pair_1__key_info__attach_info__input_type__default_val);
    layout_array_dnx_field_context[idx].total_size = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].size_of = sizeof(dnx_field_input_type_e);
    layout_array_dnx_field_context[idx].parent  = 15;
    layout_array_dnx_field_context[idx].first_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].last_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].next_node_index = 25;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_DNX_FIELD_CONTEXT_SW__CONTEXT_INFO__CONTEXT_IPMF1_INFO__COMPARE_INFO__PAIR_1__KEY_INFO__ATTACH_INFO__INPUT_ARG);
    layout_array_dnx_field_context[idx].name = "dnx_field_context_sw__context_info__context_ipmf1_info__compare_info__pair_1__key_info__attach_info__input_arg";
    layout_array_dnx_field_context[idx].type = "int";
    layout_array_dnx_field_context[idx].doc = " Input arg has different meaning per input type as follows:                                                          \n DNX_FIELD_INPUT_TYPE_LAYER_FWD  - how many layer to increment from the forwarding layer (i.e. FWD+input_arg). Can take negative or positive values.                                                          \n DNX_FIELD_INPUT_TYPE_LAYER_ABSOLUTE - how many layer to increment from the outermost layer (i.e. 0+input_arg). Can only take non-negative values.                                                          \n DNX_FIELD_INPUT_TYPE_META_DATA - Has no meaning                                                           \n DNX_FIELD_INPUT_TYPE_LAYER_RECORDS_FWD  -  how many layer to increment from the forwarding layer (i.e. FWD+input_arg). Can take negative or positive values.                                                          \n DNX_FIELD_INPUT_TYPE_LAYER_RECORDS_ABSOLUTE - how many layer to increment from the absolute layer (i.e. 0+input_arg). Can only take non-negative values.                                                          \n DNX_FIELD_INPUT_TYPE_EXTERNAL - Has no meaning                                                           \n DNX_FIELD_INPUT_TYPE_CASCADED - Field group Id of the 'Cascaded from' result                                                          \n DNX_FIELD_INPUT_TYPE_CONST - A constant, up to 32 bit.";
    layout_array_dnx_field_context[idx].default_value= &(dnx_field_context_sw__context_info__context_ipmf1_info__compare_info__pair_1__key_info__attach_info__input_arg__default_val);
    layout_array_dnx_field_context[idx].total_size = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].size_of = sizeof(int);
    layout_array_dnx_field_context[idx].parent  = 15;
    layout_array_dnx_field_context[idx].first_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].last_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].next_node_index = 26;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_DNX_FIELD_CONTEXT_SW__CONTEXT_INFO__CONTEXT_IPMF1_INFO__COMPARE_INFO__PAIR_1__KEY_INFO__ATTACH_INFO__OFFSET);
    layout_array_dnx_field_context[idx].name = "dnx_field_context_sw__context_info__context_ipmf1_info__compare_info__pair_1__key_info__attach_info__offset";
    layout_array_dnx_field_context[idx].type = "int";
    layout_array_dnx_field_context[idx].doc = "1) This filed is bit resolution                                                          \n 2) In case the qualifier was created by dnx_field_qual_create() this field is always relevant                                                          \n    it is the offset of the field inside the PBUS (MD/LR/Layer)                                                          \n 3) For predefined qualifiers based on input_type:                                                          \n DNX_FIELD_INPUT_TYPE_LAYER_FWD  - offset inside the layer  (chosen by input_type+input_arg)                                                          \n DNX_FIELD_INPUT_TYPE_LAYER_ABSOLUTE - offset inside the layer  (chosen by input_type+input_arg)                                                          \n DNX_FIELD_INPUT_TYPE_META_DATA - NA                                                          \n DNX_FIELD_INPUT_TYPE_LAYER_RECORDS_FWD  -  NA                                                          \n DNX_FIELD_INPUT_TYPE_LAYER_RECORDS_ABSOLUTE - NA                                                          \n DNX_FIELD_INPUT_TYPE_EXTERNAL - offset of the field group in the external stage result buffer, plus the offset of the action withing the field group.                                                          \n DNX_FIELD_INPUT_TYPE_CASCADED - offset in the field group of 'Cascaded from' result buffer                                                          \n DNX_FIELD_INPUT_TYPE_CONST - NA";
    layout_array_dnx_field_context[idx].default_value= &(dnx_field_context_sw__context_info__context_ipmf1_info__compare_info__pair_1__key_info__attach_info__offset__default_val);
    layout_array_dnx_field_context[idx].total_size = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].size_of = sizeof(int);
    layout_array_dnx_field_context[idx].parent  = 15;
    layout_array_dnx_field_context[idx].first_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].last_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].next_node_index = 27;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_DNX_FIELD_CONTEXT_SW__CONTEXT_INFO__CONTEXT_IPMF1_INFO__COMPARE_INFO__PAIR_1__KEY_INFO__ATTACH_INFO__BASE_QUAL);
    layout_array_dnx_field_context[idx].name = "dnx_field_context_sw__context_info__context_ipmf1_info__compare_info__pair_1__key_info__attach_info__base_qual";
    layout_array_dnx_field_context[idx].type = "dnx_field_qual_t";
    layout_array_dnx_field_context[idx].doc = "The qualifier to be based upon. used for user defined qualifers that relate to split predefined qualifers.";
    layout_array_dnx_field_context[idx].default_value= &(dnx_field_context_sw__context_info__context_ipmf1_info__compare_info__pair_1__key_info__attach_info__base_qual__default_val);
    layout_array_dnx_field_context[idx].total_size = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].size_of = sizeof(dnx_field_qual_t);
    layout_array_dnx_field_context[idx].parent  = 15;
    layout_array_dnx_field_context[idx].first_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].last_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].next_node_index = DNXC_SW_STATE_LAYOUT_INVALID;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_DNX_FIELD_CONTEXT_SW__CONTEXT_INFO__CONTEXT_IPMF1_INFO__COMPARE_INFO__PAIR_2__MODE);
    layout_array_dnx_field_context[idx].name = "dnx_field_context_sw__context_info__context_ipmf1_info__compare_info__pair_2__mode";
    layout_array_dnx_field_context[idx].type = "dnx_field_context_compare_mode_e";
    layout_array_dnx_field_context[idx].doc = "mode for each compare operation NONE/SINGLE/DOUBLE";
    layout_array_dnx_field_context[idx].default_value= &(dnx_field_context_sw__context_info__context_ipmf1_info__compare_info__pair_2__mode__default_val);
    layout_array_dnx_field_context[idx].total_size = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].size_of = sizeof(dnx_field_context_compare_mode_e);
    layout_array_dnx_field_context[idx].parent  = 9;
    layout_array_dnx_field_context[idx].first_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].last_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].next_node_index = 29;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_DNX_FIELD_CONTEXT_SW__CONTEXT_INFO__CONTEXT_IPMF1_INFO__COMPARE_INFO__PAIR_2__IS_SET);
    layout_array_dnx_field_context[idx].name = "dnx_field_context_sw__context_info__context_ipmf1_info__compare_info__pair_2__is_set";
    layout_array_dnx_field_context[idx].type = "uint8";
    layout_array_dnx_field_context[idx].doc = "Whether the qualifiers were set for the compare key";
    layout_array_dnx_field_context[idx].total_size = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].size_of = sizeof(uint8);
    layout_array_dnx_field_context[idx].parent  = 9;
    layout_array_dnx_field_context[idx].first_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].last_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].next_node_index = 30;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_DNX_FIELD_CONTEXT_SW__CONTEXT_INFO__CONTEXT_IPMF1_INFO__COMPARE_INFO__PAIR_2__KEY_INFO);
    layout_array_dnx_field_context[idx].name = "dnx_field_context_sw__context_info__context_ipmf1_info__compare_info__pair_2__key_info";
    layout_array_dnx_field_context[idx].type = "dnx_field_context_key_info_t";
    layout_array_dnx_field_context[idx].doc = "Compare key information";
    layout_array_dnx_field_context[idx].total_size = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].size_of = sizeof(dnx_field_context_key_info_t);
    layout_array_dnx_field_context[idx].array_indexes[0].size = DNX_DATA_MAX_FIELD_COMPARE_NOF_KEYS;
    layout_array_dnx_field_context[idx].array_indexes[0].index_type = DNXC_SWSTATE_ARRAY_INDEX_STATIC;
    layout_array_dnx_field_context[idx].parent  = 9;
    layout_array_dnx_field_context[idx].first_child_index = 31;
    layout_array_dnx_field_context[idx].last_child_index = 33;
    layout_array_dnx_field_context[idx].next_node_index = DNXC_SW_STATE_LAYOUT_INVALID;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_DNX_FIELD_CONTEXT_SW__CONTEXT_INFO__CONTEXT_IPMF1_INFO__COMPARE_INFO__PAIR_2__KEY_INFO__KEY_TEMPLATE);
    layout_array_dnx_field_context[idx].name = "dnx_field_context_sw__context_info__context_ipmf1_info__compare_info__pair_2__key_info__key_template";
    layout_array_dnx_field_context[idx].type = "dnx_field_key_template_t";
    layout_array_dnx_field_context[idx].doc = "Key template";
    layout_array_dnx_field_context[idx].total_size = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].size_of = sizeof(dnx_field_key_template_t);
    layout_array_dnx_field_context[idx].parent  = 30;
    layout_array_dnx_field_context[idx].first_child_index = 34;
    layout_array_dnx_field_context[idx].last_child_index = 35;
    layout_array_dnx_field_context[idx].next_node_index = 32;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_DNX_FIELD_CONTEXT_SW__CONTEXT_INFO__CONTEXT_IPMF1_INFO__COMPARE_INFO__PAIR_2__KEY_INFO__KEY_ID);
    layout_array_dnx_field_context[idx].name = "dnx_field_context_sw__context_info__context_ipmf1_info__compare_info__pair_2__key_info__key_id";
    layout_array_dnx_field_context[idx].type = "dnx_field_key_id_t";
    layout_array_dnx_field_context[idx].doc = "Key Ids";
    layout_array_dnx_field_context[idx].total_size = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].size_of = sizeof(dnx_field_key_id_t);
    layout_array_dnx_field_context[idx].parent  = 30;
    layout_array_dnx_field_context[idx].first_child_index = 39;
    layout_array_dnx_field_context[idx].last_child_index = 41;
    layout_array_dnx_field_context[idx].next_node_index = 33;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_DNX_FIELD_CONTEXT_SW__CONTEXT_INFO__CONTEXT_IPMF1_INFO__COMPARE_INFO__PAIR_2__KEY_INFO__ATTACH_INFO);
    layout_array_dnx_field_context[idx].name = "dnx_field_context_sw__context_info__context_ipmf1_info__compare_info__pair_2__key_info__attach_info";
    layout_array_dnx_field_context[idx].type = "dnx_field_qual_attach_info_t";
    layout_array_dnx_field_context[idx].doc = "Indicate how to read the relevant qualifier from PBUS The information is aligned to the qualifier types array above Number of elements set by key_template.key_qual_map[].qual_type array";
    layout_array_dnx_field_context[idx].total_size = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].size_of = sizeof(dnx_field_qual_attach_info_t);
    layout_array_dnx_field_context[idx].array_indexes[0].size = DNX_DATA_MAX_FIELD_GROUP_NOF_QUALS_PER_FG;
    layout_array_dnx_field_context[idx].array_indexes[0].index_type = DNXC_SWSTATE_ARRAY_INDEX_STATIC;
    layout_array_dnx_field_context[idx].parent  = 30;
    layout_array_dnx_field_context[idx].first_child_index = 42;
    layout_array_dnx_field_context[idx].last_child_index = 45;
    layout_array_dnx_field_context[idx].next_node_index = DNXC_SW_STATE_LAYOUT_INVALID;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_DNX_FIELD_CONTEXT_SW__CONTEXT_INFO__CONTEXT_IPMF1_INFO__COMPARE_INFO__PAIR_2__KEY_INFO__KEY_TEMPLATE__KEY_QUAL_MAP);
    layout_array_dnx_field_context[idx].name = "dnx_field_context_sw__context_info__context_ipmf1_info__compare_info__pair_2__key_info__key_template__key_qual_map";
    layout_array_dnx_field_context[idx].type = "dnx_field_qual_map_in_key_t";
    layout_array_dnx_field_context[idx].doc = "Mapping of each qualifier inside the key. End of 'valid' entries is marked \n                            by an entry with 'key_qual_map.qual_type = DNX_FIELD_QUAL_TYPE_INVALID'";
    layout_array_dnx_field_context[idx].total_size = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].size_of = sizeof(dnx_field_qual_map_in_key_t);
    layout_array_dnx_field_context[idx].array_indexes[0].size = DNX_DATA_MAX_FIELD_GROUP_NOF_QUALS_PER_FG;
    layout_array_dnx_field_context[idx].array_indexes[0].index_type = DNXC_SWSTATE_ARRAY_INDEX_STATIC;
    layout_array_dnx_field_context[idx].parent  = 31;
    layout_array_dnx_field_context[idx].first_child_index = 36;
    layout_array_dnx_field_context[idx].last_child_index = 38;
    layout_array_dnx_field_context[idx].next_node_index = 35;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_DNX_FIELD_CONTEXT_SW__CONTEXT_INFO__CONTEXT_IPMF1_INFO__COMPARE_INFO__PAIR_2__KEY_INFO__KEY_TEMPLATE__KEY_SIZE_IN_BITS);
    layout_array_dnx_field_context[idx].name = "dnx_field_context_sw__context_info__context_ipmf1_info__compare_info__pair_2__key_info__key_template__key_size_in_bits";
    layout_array_dnx_field_context[idx].type = "uint16";
    layout_array_dnx_field_context[idx].doc = "Hold the actual key size in Bit Resolution,\n                            i.e. sum, in bits, of all qualifiers configured for this key";
    layout_array_dnx_field_context[idx].total_size = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].size_of = sizeof(uint16);
    layout_array_dnx_field_context[idx].parent  = 31;
    layout_array_dnx_field_context[idx].first_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].last_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].next_node_index = DNXC_SW_STATE_LAYOUT_INVALID;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_DNX_FIELD_CONTEXT_SW__CONTEXT_INFO__CONTEXT_IPMF1_INFO__COMPARE_INFO__PAIR_2__KEY_INFO__KEY_TEMPLATE__KEY_QUAL_MAP__QUAL_TYPE);
    layout_array_dnx_field_context[idx].name = "dnx_field_context_sw__context_info__context_ipmf1_info__compare_info__pair_2__key_info__key_template__key_qual_map__qual_type";
    layout_array_dnx_field_context[idx].type = "dnx_field_qual_t";
    layout_array_dnx_field_context[idx].doc = "Qualifier type";
    layout_array_dnx_field_context[idx].default_value= &(dnx_field_context_sw__context_info__context_ipmf1_info__compare_info__pair_2__key_info__key_template__key_qual_map__qual_type__default_val);
    layout_array_dnx_field_context[idx].total_size = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].size_of = sizeof(dnx_field_qual_t);
    layout_array_dnx_field_context[idx].parent  = 34;
    layout_array_dnx_field_context[idx].first_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].last_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].next_node_index = 37;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_DNX_FIELD_CONTEXT_SW__CONTEXT_INFO__CONTEXT_IPMF1_INFO__COMPARE_INFO__PAIR_2__KEY_INFO__KEY_TEMPLATE__KEY_QUAL_MAP__LSB);
    layout_array_dnx_field_context[idx].name = "dnx_field_context_sw__context_info__context_ipmf1_info__compare_info__pair_2__key_info__key_template__key_qual_map__lsb";
    layout_array_dnx_field_context[idx].type = "uint16";
    layout_array_dnx_field_context[idx].doc = "LSB bit of the qualifier inside the key";
    layout_array_dnx_field_context[idx].total_size = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].size_of = sizeof(uint16);
    layout_array_dnx_field_context[idx].parent  = 34;
    layout_array_dnx_field_context[idx].first_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].last_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].next_node_index = 38;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_DNX_FIELD_CONTEXT_SW__CONTEXT_INFO__CONTEXT_IPMF1_INFO__COMPARE_INFO__PAIR_2__KEY_INFO__KEY_TEMPLATE__KEY_QUAL_MAP__SIZE);
    layout_array_dnx_field_context[idx].name = "dnx_field_context_sw__context_info__context_ipmf1_info__compare_info__pair_2__key_info__key_template__key_qual_map__size";
    layout_array_dnx_field_context[idx].type = "uint8";
    layout_array_dnx_field_context[idx].doc = "Size of the qualifier in the key";
    layout_array_dnx_field_context[idx].total_size = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].size_of = sizeof(uint8);
    layout_array_dnx_field_context[idx].parent  = 34;
    layout_array_dnx_field_context[idx].first_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].last_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].next_node_index = DNXC_SW_STATE_LAYOUT_INVALID;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_DNX_FIELD_CONTEXT_SW__CONTEXT_INFO__CONTEXT_IPMF1_INFO__COMPARE_INFO__PAIR_2__KEY_INFO__KEY_ID__ID);
    layout_array_dnx_field_context[idx].name = "dnx_field_context_sw__context_info__context_ipmf1_info__compare_info__pair_2__key_info__key_id__id";
    layout_array_dnx_field_context[idx].type = "dbal_enum_value_field_field_key_e";
    layout_array_dnx_field_context[idx].doc = "Hold the information regarding the key allocated for the Context ID";
    layout_array_dnx_field_context[idx].default_value= &(dnx_field_context_sw__context_info__context_ipmf1_info__compare_info__pair_2__key_info__key_id__id__default_val);
    layout_array_dnx_field_context[idx].total_size = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].size_of = sizeof(dbal_enum_value_field_field_key_e);
    layout_array_dnx_field_context[idx].array_indexes[0].size = DNX_DATA_MAX_FIELD_GROUP_NOF_KEYS_PER_FG_MAX;
    layout_array_dnx_field_context[idx].array_indexes[0].index_type = DNXC_SWSTATE_ARRAY_INDEX_STATIC;
    layout_array_dnx_field_context[idx].parent  = 32;
    layout_array_dnx_field_context[idx].first_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].last_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].next_node_index = 40;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_DNX_FIELD_CONTEXT_SW__CONTEXT_INFO__CONTEXT_IPMF1_INFO__COMPARE_INFO__PAIR_2__KEY_INFO__KEY_ID__OFFSET_ON_FIRST_KEY);
    layout_array_dnx_field_context[idx].name = "dnx_field_context_sw__context_info__context_ipmf1_info__compare_info__pair_2__key_info__key_id__offset_on_first_key";
    layout_array_dnx_field_context[idx].type = "uint8";
    layout_array_dnx_field_context[idx].doc = "Hold the lsb of the allocated bits within the first key.";
    layout_array_dnx_field_context[idx].total_size = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].size_of = sizeof(uint8);
    layout_array_dnx_field_context[idx].parent  = 32;
    layout_array_dnx_field_context[idx].first_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].last_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].next_node_index = 41;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_DNX_FIELD_CONTEXT_SW__CONTEXT_INFO__CONTEXT_IPMF1_INFO__COMPARE_INFO__PAIR_2__KEY_INFO__KEY_ID__NOF_BITS);
    layout_array_dnx_field_context[idx].name = "dnx_field_context_sw__context_info__context_ipmf1_info__compare_info__pair_2__key_info__key_id__nof_bits";
    layout_array_dnx_field_context[idx].type = "uint8";
    layout_array_dnx_field_context[idx].doc = "Hold the number of bits allocated within the key.";
    layout_array_dnx_field_context[idx].total_size = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].size_of = sizeof(uint8);
    layout_array_dnx_field_context[idx].array_indexes[0].size = DNX_DATA_MAX_FIELD_GROUP_NOF_KEYS_PER_FG_MAX;
    layout_array_dnx_field_context[idx].array_indexes[0].index_type = DNXC_SWSTATE_ARRAY_INDEX_STATIC;
    layout_array_dnx_field_context[idx].parent  = 32;
    layout_array_dnx_field_context[idx].first_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].last_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].next_node_index = DNXC_SW_STATE_LAYOUT_INVALID;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_DNX_FIELD_CONTEXT_SW__CONTEXT_INFO__CONTEXT_IPMF1_INFO__COMPARE_INFO__PAIR_2__KEY_INFO__ATTACH_INFO__INPUT_TYPE);
    layout_array_dnx_field_context[idx].name = "dnx_field_context_sw__context_info__context_ipmf1_info__compare_info__pair_2__key_info__attach_info__input_type";
    layout_array_dnx_field_context[idx].type = "dnx_field_input_type_e";
    layout_array_dnx_field_context[idx].doc = "The base of qualifier indicates from which part of the PBUS the info is taken                                                                          \n relevant for all type of qualifiers                                                                          \n DNX_FIELD_INPUT_TYPE_LAYER_FWD  - Takes data from a layer in the header, using the forwarding layer information.                                                                          \n DNX_FIELD_INPUT_TYPE_LAYER_ABSOLUTE - Takes data from a layer in the header, ignoring forwarding layer information.                                                                          \n DNX_FIELD_INPUT_TYPE_META_DATA - Takes data from the Metadata.                                                                          \n DNX_FIELD_INPUT_TYPE_META_DATA2 - Takes data from the native Metadata of iPMF2, relevant only for iPMF2.                                                                          \n DNX_FIELD_INPUT_TYPE_LAYER_RECORDS_FWD  -  Takes data about a layer in the header (layer record), using the forwarding layer information.                                                                          \n DNX_FIELD_INPUT_TYPE_LAYER_RECORDS_ABSOLUTE - Takes data about a layer in the header (layer record), ignoring the forwarding layer information.                                                                          \n DNX_FIELD_INPUT_TYPE_EXTERNAL - Takes data from the results of an external stage field group.                                                                          \n DNX_FIELD_INPUT_TYPE_CASCADED - Takes data from the result of a field group from an earlier PMF stage, using cascading.                                                                          \n DNX_FIELD_INPUT_TYPE_CONST - Writes a constant value.";
    layout_array_dnx_field_context[idx].default_value= &(dnx_field_context_sw__context_info__context_ipmf1_info__compare_info__pair_2__key_info__attach_info__input_type__default_val);
    layout_array_dnx_field_context[idx].total_size = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].size_of = sizeof(dnx_field_input_type_e);
    layout_array_dnx_field_context[idx].parent  = 33;
    layout_array_dnx_field_context[idx].first_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].last_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].next_node_index = 43;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_DNX_FIELD_CONTEXT_SW__CONTEXT_INFO__CONTEXT_IPMF1_INFO__COMPARE_INFO__PAIR_2__KEY_INFO__ATTACH_INFO__INPUT_ARG);
    layout_array_dnx_field_context[idx].name = "dnx_field_context_sw__context_info__context_ipmf1_info__compare_info__pair_2__key_info__attach_info__input_arg";
    layout_array_dnx_field_context[idx].type = "int";
    layout_array_dnx_field_context[idx].doc = " Input arg has different meaning per input type as follows:                                                          \n DNX_FIELD_INPUT_TYPE_LAYER_FWD  - how many layer to increment from the forwarding layer (i.e. FWD+input_arg). Can take negative or positive values.                                                          \n DNX_FIELD_INPUT_TYPE_LAYER_ABSOLUTE - how many layer to increment from the outermost layer (i.e. 0+input_arg). Can only take non-negative values.                                                          \n DNX_FIELD_INPUT_TYPE_META_DATA - Has no meaning                                                           \n DNX_FIELD_INPUT_TYPE_LAYER_RECORDS_FWD  -  how many layer to increment from the forwarding layer (i.e. FWD+input_arg). Can take negative or positive values.                                                          \n DNX_FIELD_INPUT_TYPE_LAYER_RECORDS_ABSOLUTE - how many layer to increment from the absolute layer (i.e. 0+input_arg). Can only take non-negative values.                                                          \n DNX_FIELD_INPUT_TYPE_EXTERNAL - Has no meaning                                                           \n DNX_FIELD_INPUT_TYPE_CASCADED - Field group Id of the 'Cascaded from' result                                                          \n DNX_FIELD_INPUT_TYPE_CONST - A constant, up to 32 bit.";
    layout_array_dnx_field_context[idx].default_value= &(dnx_field_context_sw__context_info__context_ipmf1_info__compare_info__pair_2__key_info__attach_info__input_arg__default_val);
    layout_array_dnx_field_context[idx].total_size = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].size_of = sizeof(int);
    layout_array_dnx_field_context[idx].parent  = 33;
    layout_array_dnx_field_context[idx].first_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].last_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].next_node_index = 44;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_DNX_FIELD_CONTEXT_SW__CONTEXT_INFO__CONTEXT_IPMF1_INFO__COMPARE_INFO__PAIR_2__KEY_INFO__ATTACH_INFO__OFFSET);
    layout_array_dnx_field_context[idx].name = "dnx_field_context_sw__context_info__context_ipmf1_info__compare_info__pair_2__key_info__attach_info__offset";
    layout_array_dnx_field_context[idx].type = "int";
    layout_array_dnx_field_context[idx].doc = "1) This filed is bit resolution                                                          \n 2) In case the qualifier was created by dnx_field_qual_create() this field is always relevant                                                          \n    it is the offset of the field inside the PBUS (MD/LR/Layer)                                                          \n 3) For predefined qualifiers based on input_type:                                                          \n DNX_FIELD_INPUT_TYPE_LAYER_FWD  - offset inside the layer  (chosen by input_type+input_arg)                                                          \n DNX_FIELD_INPUT_TYPE_LAYER_ABSOLUTE - offset inside the layer  (chosen by input_type+input_arg)                                                          \n DNX_FIELD_INPUT_TYPE_META_DATA - NA                                                          \n DNX_FIELD_INPUT_TYPE_LAYER_RECORDS_FWD  -  NA                                                          \n DNX_FIELD_INPUT_TYPE_LAYER_RECORDS_ABSOLUTE - NA                                                          \n DNX_FIELD_INPUT_TYPE_EXTERNAL - offset of the field group in the external stage result buffer, plus the offset of the action withing the field group.                                                          \n DNX_FIELD_INPUT_TYPE_CASCADED - offset in the field group of 'Cascaded from' result buffer                                                          \n DNX_FIELD_INPUT_TYPE_CONST - NA";
    layout_array_dnx_field_context[idx].default_value= &(dnx_field_context_sw__context_info__context_ipmf1_info__compare_info__pair_2__key_info__attach_info__offset__default_val);
    layout_array_dnx_field_context[idx].total_size = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].size_of = sizeof(int);
    layout_array_dnx_field_context[idx].parent  = 33;
    layout_array_dnx_field_context[idx].first_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].last_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].next_node_index = 45;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_DNX_FIELD_CONTEXT_SW__CONTEXT_INFO__CONTEXT_IPMF1_INFO__COMPARE_INFO__PAIR_2__KEY_INFO__ATTACH_INFO__BASE_QUAL);
    layout_array_dnx_field_context[idx].name = "dnx_field_context_sw__context_info__context_ipmf1_info__compare_info__pair_2__key_info__attach_info__base_qual";
    layout_array_dnx_field_context[idx].type = "dnx_field_qual_t";
    layout_array_dnx_field_context[idx].doc = "The qualifier to be based upon. used for user defined qualifers that relate to split predefined qualifers.";
    layout_array_dnx_field_context[idx].default_value= &(dnx_field_context_sw__context_info__context_ipmf1_info__compare_info__pair_2__key_info__attach_info__base_qual__default_val);
    layout_array_dnx_field_context[idx].total_size = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].size_of = sizeof(dnx_field_qual_t);
    layout_array_dnx_field_context[idx].parent  = 33;
    layout_array_dnx_field_context[idx].first_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].last_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].next_node_index = DNXC_SW_STATE_LAYOUT_INVALID;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_DNX_FIELD_CONTEXT_SW__CONTEXT_INFO__CONTEXT_IPMF1_INFO__HASHING_INFO__MODE);
    layout_array_dnx_field_context[idx].name = "dnx_field_context_sw__context_info__context_ipmf1_info__hashing_info__mode";
    layout_array_dnx_field_context[idx].type = "dnx_field_context_hash_mode_e";
    layout_array_dnx_field_context[idx].doc = "Hashing mode (disabled/enabled)";
    layout_array_dnx_field_context[idx].default_value= &(dnx_field_context_sw__context_info__context_ipmf1_info__hashing_info__mode__default_val);
    layout_array_dnx_field_context[idx].total_size = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].size_of = sizeof(dnx_field_context_hash_mode_e);
    layout_array_dnx_field_context[idx].parent  = 7;
    layout_array_dnx_field_context[idx].first_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].last_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].next_node_index = 47;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_DNX_FIELD_CONTEXT_SW__CONTEXT_INFO__CONTEXT_IPMF1_INFO__HASHING_INFO__IS_SET);
    layout_array_dnx_field_context[idx].name = "dnx_field_context_sw__context_info__context_ipmf1_info__hashing_info__is_set";
    layout_array_dnx_field_context[idx].type = "uint8";
    layout_array_dnx_field_context[idx].doc = "Whether the qualifiers were set for the hash key";
    layout_array_dnx_field_context[idx].total_size = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].size_of = sizeof(uint8);
    layout_array_dnx_field_context[idx].parent  = 7;
    layout_array_dnx_field_context[idx].first_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].last_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].next_node_index = 48;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_DNX_FIELD_CONTEXT_SW__CONTEXT_INFO__CONTEXT_IPMF1_INFO__HASHING_INFO__KEY_INFO);
    layout_array_dnx_field_context[idx].name = "dnx_field_context_sw__context_info__context_ipmf1_info__hashing_info__key_info";
    layout_array_dnx_field_context[idx].type = "dnx_field_context_key_info_t";
    layout_array_dnx_field_context[idx].doc = "Hash key info";
    layout_array_dnx_field_context[idx].total_size = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].size_of = sizeof(dnx_field_context_key_info_t);
    layout_array_dnx_field_context[idx].parent  = 7;
    layout_array_dnx_field_context[idx].first_child_index = 49;
    layout_array_dnx_field_context[idx].last_child_index = 51;
    layout_array_dnx_field_context[idx].next_node_index = DNXC_SW_STATE_LAYOUT_INVALID;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_DNX_FIELD_CONTEXT_SW__CONTEXT_INFO__CONTEXT_IPMF1_INFO__HASHING_INFO__KEY_INFO__KEY_TEMPLATE);
    layout_array_dnx_field_context[idx].name = "dnx_field_context_sw__context_info__context_ipmf1_info__hashing_info__key_info__key_template";
    layout_array_dnx_field_context[idx].type = "dnx_field_key_template_t";
    layout_array_dnx_field_context[idx].doc = "Key template";
    layout_array_dnx_field_context[idx].total_size = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].size_of = sizeof(dnx_field_key_template_t);
    layout_array_dnx_field_context[idx].parent  = 48;
    layout_array_dnx_field_context[idx].first_child_index = 52;
    layout_array_dnx_field_context[idx].last_child_index = 53;
    layout_array_dnx_field_context[idx].next_node_index = 50;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_DNX_FIELD_CONTEXT_SW__CONTEXT_INFO__CONTEXT_IPMF1_INFO__HASHING_INFO__KEY_INFO__KEY_ID);
    layout_array_dnx_field_context[idx].name = "dnx_field_context_sw__context_info__context_ipmf1_info__hashing_info__key_info__key_id";
    layout_array_dnx_field_context[idx].type = "dnx_field_key_id_t";
    layout_array_dnx_field_context[idx].doc = "Key Ids";
    layout_array_dnx_field_context[idx].total_size = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].size_of = sizeof(dnx_field_key_id_t);
    layout_array_dnx_field_context[idx].parent  = 48;
    layout_array_dnx_field_context[idx].first_child_index = 57;
    layout_array_dnx_field_context[idx].last_child_index = 59;
    layout_array_dnx_field_context[idx].next_node_index = 51;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_DNX_FIELD_CONTEXT_SW__CONTEXT_INFO__CONTEXT_IPMF1_INFO__HASHING_INFO__KEY_INFO__ATTACH_INFO);
    layout_array_dnx_field_context[idx].name = "dnx_field_context_sw__context_info__context_ipmf1_info__hashing_info__key_info__attach_info";
    layout_array_dnx_field_context[idx].type = "dnx_field_qual_attach_info_t";
    layout_array_dnx_field_context[idx].doc = "Indicate how to read the relevant qualifier from PBUS The information is aligned to the qualifier types array above Number of elements set by key_template.key_qual_map[].qual_type array";
    layout_array_dnx_field_context[idx].total_size = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].size_of = sizeof(dnx_field_qual_attach_info_t);
    layout_array_dnx_field_context[idx].array_indexes[0].size = DNX_DATA_MAX_FIELD_GROUP_NOF_QUALS_PER_FG;
    layout_array_dnx_field_context[idx].array_indexes[0].index_type = DNXC_SWSTATE_ARRAY_INDEX_STATIC;
    layout_array_dnx_field_context[idx].parent  = 48;
    layout_array_dnx_field_context[idx].first_child_index = 60;
    layout_array_dnx_field_context[idx].last_child_index = 63;
    layout_array_dnx_field_context[idx].next_node_index = DNXC_SW_STATE_LAYOUT_INVALID;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_DNX_FIELD_CONTEXT_SW__CONTEXT_INFO__CONTEXT_IPMF1_INFO__HASHING_INFO__KEY_INFO__KEY_TEMPLATE__KEY_QUAL_MAP);
    layout_array_dnx_field_context[idx].name = "dnx_field_context_sw__context_info__context_ipmf1_info__hashing_info__key_info__key_template__key_qual_map";
    layout_array_dnx_field_context[idx].type = "dnx_field_qual_map_in_key_t";
    layout_array_dnx_field_context[idx].doc = "Mapping of each qualifier inside the key. End of 'valid' entries is marked \n                            by an entry with 'key_qual_map.qual_type = DNX_FIELD_QUAL_TYPE_INVALID'";
    layout_array_dnx_field_context[idx].total_size = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].size_of = sizeof(dnx_field_qual_map_in_key_t);
    layout_array_dnx_field_context[idx].array_indexes[0].size = DNX_DATA_MAX_FIELD_GROUP_NOF_QUALS_PER_FG;
    layout_array_dnx_field_context[idx].array_indexes[0].index_type = DNXC_SWSTATE_ARRAY_INDEX_STATIC;
    layout_array_dnx_field_context[idx].parent  = 49;
    layout_array_dnx_field_context[idx].first_child_index = 54;
    layout_array_dnx_field_context[idx].last_child_index = 56;
    layout_array_dnx_field_context[idx].next_node_index = 53;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_DNX_FIELD_CONTEXT_SW__CONTEXT_INFO__CONTEXT_IPMF1_INFO__HASHING_INFO__KEY_INFO__KEY_TEMPLATE__KEY_SIZE_IN_BITS);
    layout_array_dnx_field_context[idx].name = "dnx_field_context_sw__context_info__context_ipmf1_info__hashing_info__key_info__key_template__key_size_in_bits";
    layout_array_dnx_field_context[idx].type = "uint16";
    layout_array_dnx_field_context[idx].doc = "Hold the actual key size in Bit Resolution,\n                            i.e. sum, in bits, of all qualifiers configured for this key";
    layout_array_dnx_field_context[idx].total_size = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].size_of = sizeof(uint16);
    layout_array_dnx_field_context[idx].parent  = 49;
    layout_array_dnx_field_context[idx].first_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].last_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].next_node_index = DNXC_SW_STATE_LAYOUT_INVALID;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_DNX_FIELD_CONTEXT_SW__CONTEXT_INFO__CONTEXT_IPMF1_INFO__HASHING_INFO__KEY_INFO__KEY_TEMPLATE__KEY_QUAL_MAP__QUAL_TYPE);
    layout_array_dnx_field_context[idx].name = "dnx_field_context_sw__context_info__context_ipmf1_info__hashing_info__key_info__key_template__key_qual_map__qual_type";
    layout_array_dnx_field_context[idx].type = "dnx_field_qual_t";
    layout_array_dnx_field_context[idx].doc = "Qualifier type";
    layout_array_dnx_field_context[idx].default_value= &(dnx_field_context_sw__context_info__context_ipmf1_info__hashing_info__key_info__key_template__key_qual_map__qual_type__default_val);
    layout_array_dnx_field_context[idx].total_size = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].size_of = sizeof(dnx_field_qual_t);
    layout_array_dnx_field_context[idx].parent  = 52;
    layout_array_dnx_field_context[idx].first_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].last_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].next_node_index = 55;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_DNX_FIELD_CONTEXT_SW__CONTEXT_INFO__CONTEXT_IPMF1_INFO__HASHING_INFO__KEY_INFO__KEY_TEMPLATE__KEY_QUAL_MAP__LSB);
    layout_array_dnx_field_context[idx].name = "dnx_field_context_sw__context_info__context_ipmf1_info__hashing_info__key_info__key_template__key_qual_map__lsb";
    layout_array_dnx_field_context[idx].type = "uint16";
    layout_array_dnx_field_context[idx].doc = "LSB bit of the qualifier inside the key";
    layout_array_dnx_field_context[idx].total_size = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].size_of = sizeof(uint16);
    layout_array_dnx_field_context[idx].parent  = 52;
    layout_array_dnx_field_context[idx].first_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].last_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].next_node_index = 56;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_DNX_FIELD_CONTEXT_SW__CONTEXT_INFO__CONTEXT_IPMF1_INFO__HASHING_INFO__KEY_INFO__KEY_TEMPLATE__KEY_QUAL_MAP__SIZE);
    layout_array_dnx_field_context[idx].name = "dnx_field_context_sw__context_info__context_ipmf1_info__hashing_info__key_info__key_template__key_qual_map__size";
    layout_array_dnx_field_context[idx].type = "uint8";
    layout_array_dnx_field_context[idx].doc = "Size of the qualifier in the key";
    layout_array_dnx_field_context[idx].total_size = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].size_of = sizeof(uint8);
    layout_array_dnx_field_context[idx].parent  = 52;
    layout_array_dnx_field_context[idx].first_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].last_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].next_node_index = DNXC_SW_STATE_LAYOUT_INVALID;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_DNX_FIELD_CONTEXT_SW__CONTEXT_INFO__CONTEXT_IPMF1_INFO__HASHING_INFO__KEY_INFO__KEY_ID__ID);
    layout_array_dnx_field_context[idx].name = "dnx_field_context_sw__context_info__context_ipmf1_info__hashing_info__key_info__key_id__id";
    layout_array_dnx_field_context[idx].type = "dbal_enum_value_field_field_key_e";
    layout_array_dnx_field_context[idx].doc = "Hold the information regarding the key allocated for the Context ID";
    layout_array_dnx_field_context[idx].default_value= &(dnx_field_context_sw__context_info__context_ipmf1_info__hashing_info__key_info__key_id__id__default_val);
    layout_array_dnx_field_context[idx].total_size = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].size_of = sizeof(dbal_enum_value_field_field_key_e);
    layout_array_dnx_field_context[idx].array_indexes[0].size = DNX_DATA_MAX_FIELD_GROUP_NOF_KEYS_PER_FG_MAX;
    layout_array_dnx_field_context[idx].array_indexes[0].index_type = DNXC_SWSTATE_ARRAY_INDEX_STATIC;
    layout_array_dnx_field_context[idx].parent  = 50;
    layout_array_dnx_field_context[idx].first_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].last_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].next_node_index = 58;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_DNX_FIELD_CONTEXT_SW__CONTEXT_INFO__CONTEXT_IPMF1_INFO__HASHING_INFO__KEY_INFO__KEY_ID__OFFSET_ON_FIRST_KEY);
    layout_array_dnx_field_context[idx].name = "dnx_field_context_sw__context_info__context_ipmf1_info__hashing_info__key_info__key_id__offset_on_first_key";
    layout_array_dnx_field_context[idx].type = "uint8";
    layout_array_dnx_field_context[idx].doc = "Hold the lsb of the allocated bits within the first key.";
    layout_array_dnx_field_context[idx].total_size = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].size_of = sizeof(uint8);
    layout_array_dnx_field_context[idx].parent  = 50;
    layout_array_dnx_field_context[idx].first_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].last_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].next_node_index = 59;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_DNX_FIELD_CONTEXT_SW__CONTEXT_INFO__CONTEXT_IPMF1_INFO__HASHING_INFO__KEY_INFO__KEY_ID__NOF_BITS);
    layout_array_dnx_field_context[idx].name = "dnx_field_context_sw__context_info__context_ipmf1_info__hashing_info__key_info__key_id__nof_bits";
    layout_array_dnx_field_context[idx].type = "uint8";
    layout_array_dnx_field_context[idx].doc = "Hold the number of bits allocated within the key.";
    layout_array_dnx_field_context[idx].total_size = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].size_of = sizeof(uint8);
    layout_array_dnx_field_context[idx].array_indexes[0].size = DNX_DATA_MAX_FIELD_GROUP_NOF_KEYS_PER_FG_MAX;
    layout_array_dnx_field_context[idx].array_indexes[0].index_type = DNXC_SWSTATE_ARRAY_INDEX_STATIC;
    layout_array_dnx_field_context[idx].parent  = 50;
    layout_array_dnx_field_context[idx].first_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].last_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].next_node_index = DNXC_SW_STATE_LAYOUT_INVALID;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_DNX_FIELD_CONTEXT_SW__CONTEXT_INFO__CONTEXT_IPMF1_INFO__HASHING_INFO__KEY_INFO__ATTACH_INFO__INPUT_TYPE);
    layout_array_dnx_field_context[idx].name = "dnx_field_context_sw__context_info__context_ipmf1_info__hashing_info__key_info__attach_info__input_type";
    layout_array_dnx_field_context[idx].type = "dnx_field_input_type_e";
    layout_array_dnx_field_context[idx].doc = "The base of qualifier indicates from which part of the PBUS the info is taken                                                                          \n relevant for all type of qualifiers                                                                          \n DNX_FIELD_INPUT_TYPE_LAYER_FWD  - Takes data from a layer in the header, using the forwarding layer information.                                                                          \n DNX_FIELD_INPUT_TYPE_LAYER_ABSOLUTE - Takes data from a layer in the header, ignoring forwarding layer information.                                                                          \n DNX_FIELD_INPUT_TYPE_META_DATA - Takes data from the Metadata.                                                                          \n DNX_FIELD_INPUT_TYPE_META_DATA2 - Takes data from the native Metadata of iPMF2, relevant only for iPMF2.                                                                          \n DNX_FIELD_INPUT_TYPE_LAYER_RECORDS_FWD  -  Takes data about a layer in the header (layer record), using the forwarding layer information.                                                                          \n DNX_FIELD_INPUT_TYPE_LAYER_RECORDS_ABSOLUTE - Takes data about a layer in the header (layer record), ignoring the forwarding layer information.                                                                          \n DNX_FIELD_INPUT_TYPE_EXTERNAL - Takes data from the results of an external stage field group.                                                                          \n DNX_FIELD_INPUT_TYPE_CASCADED - Takes data from the result of a field group from an earlier PMF stage, using cascading.                                                                          \n DNX_FIELD_INPUT_TYPE_CONST - Writes a constant value.";
    layout_array_dnx_field_context[idx].default_value= &(dnx_field_context_sw__context_info__context_ipmf1_info__hashing_info__key_info__attach_info__input_type__default_val);
    layout_array_dnx_field_context[idx].total_size = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].size_of = sizeof(dnx_field_input_type_e);
    layout_array_dnx_field_context[idx].parent  = 51;
    layout_array_dnx_field_context[idx].first_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].last_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].next_node_index = 61;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_DNX_FIELD_CONTEXT_SW__CONTEXT_INFO__CONTEXT_IPMF1_INFO__HASHING_INFO__KEY_INFO__ATTACH_INFO__INPUT_ARG);
    layout_array_dnx_field_context[idx].name = "dnx_field_context_sw__context_info__context_ipmf1_info__hashing_info__key_info__attach_info__input_arg";
    layout_array_dnx_field_context[idx].type = "int";
    layout_array_dnx_field_context[idx].doc = " Input arg has different meaning per input type as follows:                                                          \n DNX_FIELD_INPUT_TYPE_LAYER_FWD  - how many layer to increment from the forwarding layer (i.e. FWD+input_arg). Can take negative or positive values.                                                          \n DNX_FIELD_INPUT_TYPE_LAYER_ABSOLUTE - how many layer to increment from the outermost layer (i.e. 0+input_arg). Can only take non-negative values.                                                          \n DNX_FIELD_INPUT_TYPE_META_DATA - Has no meaning                                                           \n DNX_FIELD_INPUT_TYPE_LAYER_RECORDS_FWD  -  how many layer to increment from the forwarding layer (i.e. FWD+input_arg). Can take negative or positive values.                                                          \n DNX_FIELD_INPUT_TYPE_LAYER_RECORDS_ABSOLUTE - how many layer to increment from the absolute layer (i.e. 0+input_arg). Can only take non-negative values.                                                          \n DNX_FIELD_INPUT_TYPE_EXTERNAL - Has no meaning                                                           \n DNX_FIELD_INPUT_TYPE_CASCADED - Field group Id of the 'Cascaded from' result                                                          \n DNX_FIELD_INPUT_TYPE_CONST - A constant, up to 32 bit.";
    layout_array_dnx_field_context[idx].default_value= &(dnx_field_context_sw__context_info__context_ipmf1_info__hashing_info__key_info__attach_info__input_arg__default_val);
    layout_array_dnx_field_context[idx].total_size = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].size_of = sizeof(int);
    layout_array_dnx_field_context[idx].parent  = 51;
    layout_array_dnx_field_context[idx].first_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].last_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].next_node_index = 62;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_DNX_FIELD_CONTEXT_SW__CONTEXT_INFO__CONTEXT_IPMF1_INFO__HASHING_INFO__KEY_INFO__ATTACH_INFO__OFFSET);
    layout_array_dnx_field_context[idx].name = "dnx_field_context_sw__context_info__context_ipmf1_info__hashing_info__key_info__attach_info__offset";
    layout_array_dnx_field_context[idx].type = "int";
    layout_array_dnx_field_context[idx].doc = "1) This filed is bit resolution                                                          \n 2) In case the qualifier was created by dnx_field_qual_create() this field is always relevant                                                          \n    it is the offset of the field inside the PBUS (MD/LR/Layer)                                                          \n 3) For predefined qualifiers based on input_type:                                                          \n DNX_FIELD_INPUT_TYPE_LAYER_FWD  - offset inside the layer  (chosen by input_type+input_arg)                                                          \n DNX_FIELD_INPUT_TYPE_LAYER_ABSOLUTE - offset inside the layer  (chosen by input_type+input_arg)                                                          \n DNX_FIELD_INPUT_TYPE_META_DATA - NA                                                          \n DNX_FIELD_INPUT_TYPE_LAYER_RECORDS_FWD  -  NA                                                          \n DNX_FIELD_INPUT_TYPE_LAYER_RECORDS_ABSOLUTE - NA                                                          \n DNX_FIELD_INPUT_TYPE_EXTERNAL - offset of the field group in the external stage result buffer, plus the offset of the action withing the field group.                                                          \n DNX_FIELD_INPUT_TYPE_CASCADED - offset in the field group of 'Cascaded from' result buffer                                                          \n DNX_FIELD_INPUT_TYPE_CONST - NA";
    layout_array_dnx_field_context[idx].default_value= &(dnx_field_context_sw__context_info__context_ipmf1_info__hashing_info__key_info__attach_info__offset__default_val);
    layout_array_dnx_field_context[idx].total_size = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].size_of = sizeof(int);
    layout_array_dnx_field_context[idx].parent  = 51;
    layout_array_dnx_field_context[idx].first_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].last_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].next_node_index = 63;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_DNX_FIELD_CONTEXT_SW__CONTEXT_INFO__CONTEXT_IPMF1_INFO__HASHING_INFO__KEY_INFO__ATTACH_INFO__BASE_QUAL);
    layout_array_dnx_field_context[idx].name = "dnx_field_context_sw__context_info__context_ipmf1_info__hashing_info__key_info__attach_info__base_qual";
    layout_array_dnx_field_context[idx].type = "dnx_field_qual_t";
    layout_array_dnx_field_context[idx].doc = "The qualifier to be based upon. used for user defined qualifers that relate to split predefined qualifers.";
    layout_array_dnx_field_context[idx].default_value= &(dnx_field_context_sw__context_info__context_ipmf1_info__hashing_info__key_info__attach_info__base_qual__default_val);
    layout_array_dnx_field_context[idx].total_size = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].size_of = sizeof(dnx_field_qual_t);
    layout_array_dnx_field_context[idx].parent  = 51;
    layout_array_dnx_field_context[idx].first_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].last_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].next_node_index = DNXC_SW_STATE_LAYOUT_INVALID;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_DNX_FIELD_CONTEXT_SW__CONTEXT_INFO__CONTEXT_IPMF2_INFO__CASCADED_FROM);
    layout_array_dnx_field_context[idx].name = "dnx_field_context_sw__context_info__context_ipmf2_info__cascaded_from";
    layout_array_dnx_field_context[idx].type = "dnx_field_context_t";
    layout_array_dnx_field_context[idx].doc = "the context-Id which the current context is cascaded from ";
    layout_array_dnx_field_context[idx].default_value= &(dnx_field_context_sw__context_info__context_ipmf2_info__cascaded_from__default_val);
    layout_array_dnx_field_context[idx].total_size = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].size_of = sizeof(dnx_field_context_t);
    layout_array_dnx_field_context[idx].parent  = 3;
    layout_array_dnx_field_context[idx].first_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].last_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].next_node_index = DNXC_SW_STATE_LAYOUT_INVALID;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_DNX_FIELD_CONTEXT_SW__CONTEXT_INFO__STATE_TABLE_INFO__MODE);
    layout_array_dnx_field_context[idx].name = "dnx_field_context_sw__context_info__state_table_info__mode";
    layout_array_dnx_field_context[idx].type = "dnx_field_context_state_table_mode_e";
    layout_array_dnx_field_context[idx].doc = "State Table mode (disabled/enabled)";
    layout_array_dnx_field_context[idx].default_value= &(dnx_field_context_sw__context_info__state_table_info__mode__default_val);
    layout_array_dnx_field_context[idx].total_size = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].size_of = sizeof(dnx_field_context_state_table_mode_e);
    layout_array_dnx_field_context[idx].parent  = 4;
    layout_array_dnx_field_context[idx].first_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].last_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].next_node_index = 66;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_DNX_FIELD_CONTEXT_SW__CONTEXT_INFO__STATE_TABLE_INFO__IS_SET);
    layout_array_dnx_field_context[idx].name = "dnx_field_context_sw__context_info__state_table_info__is_set";
    layout_array_dnx_field_context[idx].type = "uint8";
    layout_array_dnx_field_context[idx].doc = "Whether a state table field group was set";
    layout_array_dnx_field_context[idx].total_size = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].size_of = sizeof(uint8);
    layout_array_dnx_field_context[idx].parent  = 4;
    layout_array_dnx_field_context[idx].first_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].last_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].next_node_index = DNXC_SW_STATE_LAYOUT_INVALID;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_DNX_FIELD_CONTEXT_SW__CONTEXT_INFO__NAME__VALUE);
    layout_array_dnx_field_context[idx].name = "dnx_field_context_sw__context_info__name__value";
    layout_array_dnx_field_context[idx].type = "sw_state_string_t";
    layout_array_dnx_field_context[idx].doc = "Context name.";
    layout_array_dnx_field_context[idx].total_size = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].size_of = sizeof(sw_state_string_t);
    layout_array_dnx_field_context[idx].parent  = 5;
    layout_array_dnx_field_context[idx].first_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].last_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_dnx_field_context[idx].next_node_index = DNXC_SW_STATE_LAYOUT_INVALID;


    dnxc_sw_state_layout_init_structure(unit, DNX_SW_STATE_DNX_FIELD_CONTEXT_SW, layout_array_dnx_field_context, sw_state_layout_array[unit][DNX_FIELD_CONTEXT_MODULE_ID], DNX_SW_STATE_DNX_FIELD_CONTEXT_SW_NOF_PARAMS);

    DNXC_SW_STATE_FUNC_RETURN;
}

#undef BSL_LOG_MODULE
