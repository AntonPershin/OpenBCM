
/* *INDENT-OFF* */
/*
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2022 Broadcom Inc. All rights reserved.
 */
#ifdef BSL_LOG_MODULE
#error "BSL_LOG_MODULE redefined"
#endif
#define BSL_LOG_MODULE BSL_LS_BCMDNX_FLDPROCDNX

#include <soc/dnx/dnx_data/auto_generated/dnx_data_internal_field.h>



#ifdef BCM_DNX2_SUPPORT

extern shr_error_e jr2_a0_data_field_attach(
    int unit);

#endif 
#ifdef BCM_DNX2_SUPPORT

extern shr_error_e jr2_b0_data_field_attach(
    int unit);

#endif 
#ifdef BCM_DNX2_SUPPORT

extern shr_error_e j2c_a0_data_field_attach(
    int unit);

#endif 
#ifdef BCM_DNX2_SUPPORT

extern shr_error_e q2a_a0_data_field_attach(
    int unit);

#endif 
#ifdef BCM_DNX2_SUPPORT

extern shr_error_e j2p_a0_data_field_attach(
    int unit);

#endif 
#ifdef BCM_DNX2_SUPPORT

extern shr_error_e j2x_a0_data_field_attach(
    int unit);

#endif 



static shr_error_e
dnx_data_field_base_ipmf1_init(
    int unit,
    dnxc_data_submodule_t *submodule_data)
{
    SHR_FUNC_INIT_VARS(unit);

    submodule_data->name = "base_ipmf1";
    submodule_data->doc = "Ingress PMF_1 data. For internal DNX DATA use only. Use stage submodule instead.";
    
    submodule_data->nof_features = _dnx_data_field_base_ipmf1_feature_nof;
    DNXC_DATA_ALLOC(submodule_data->features, dnxc_data_feature_t,  submodule_data->nof_features, "_dnxc_data field base_ipmf1 features");

    
    submodule_data->nof_defines = _dnx_data_field_base_ipmf1_define_nof;
    DNXC_DATA_ALLOC(submodule_data->defines, dnxc_data_define_t, submodule_data->nof_defines, "_dnxc_data field base_ipmf1 defines");

    submodule_data->defines[dnx_data_field_base_ipmf1_define_nof_ffc].name = "nof_ffc";
    submodule_data->defines[dnx_data_field_base_ipmf1_define_nof_ffc].doc = "Number of FFC's per context. For internal DNX_DATA use only.";
    
    submodule_data->defines[dnx_data_field_base_ipmf1_define_nof_ffc].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_base_ipmf1_define_nof_keys].name = "nof_keys";
    submodule_data->defines[dnx_data_field_base_ipmf1_define_nof_keys].doc = "Number of keys for the this PMF stage. For internal DNX_DATA use only.";
    
    submodule_data->defines[dnx_data_field_base_ipmf1_define_nof_keys].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_base_ipmf1_define_nof_keys_alloc].name = "nof_keys_alloc";
    submodule_data->defines[dnx_data_field_base_ipmf1_define_nof_keys_alloc].doc = "Number of keys available for allocation for use by this specific PMF stage. For internal DNX_DATA use only.";
    
    submodule_data->defines[dnx_data_field_base_ipmf1_define_nof_keys_alloc].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_base_ipmf1_define_nof_keys_alloc_for_tcam].name = "nof_keys_alloc_for_tcam";
    submodule_data->defines[dnx_data_field_base_ipmf1_define_nof_keys_alloc_for_tcam].doc = "Number of keys available for allocation for use by this specific PMF stage for TCAM access. For internal DNX_DATA use only.";
    
    submodule_data->defines[dnx_data_field_base_ipmf1_define_nof_keys_alloc_for_tcam].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_base_ipmf1_define_nof_keys_alloc_for_exem].name = "nof_keys_alloc_for_exem";
    submodule_data->defines[dnx_data_field_base_ipmf1_define_nof_keys_alloc_for_exem].doc = "Number of keys available for allocation for use by this specific PMF stage for EXEM access. For internal DNX_DATA use only.";
    
    submodule_data->defines[dnx_data_field_base_ipmf1_define_nof_keys_alloc_for_exem].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_base_ipmf1_define_nof_keys_alloc_for_dir_ext].name = "nof_keys_alloc_for_dir_ext";
    submodule_data->defines[dnx_data_field_base_ipmf1_define_nof_keys_alloc_for_dir_ext].doc = "Number of keys available for allocation for use by this specific PMF stage for DIRECT EXTRACTION. For internal DNX_DATA use only.";
    
    submodule_data->defines[dnx_data_field_base_ipmf1_define_nof_keys_alloc_for_dir_ext].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_base_ipmf1_define_nof_keys_alloc_for_mdb_dt].name = "nof_keys_alloc_for_mdb_dt";
    submodule_data->defines[dnx_data_field_base_ipmf1_define_nof_keys_alloc_for_mdb_dt].doc = "Number of keys available for allocation for use by this specific PMF stage for MDB_DT access. For internal DNX_DATA use only.";
    
    submodule_data->defines[dnx_data_field_base_ipmf1_define_nof_keys_alloc_for_mdb_dt].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_base_ipmf1_define_nof_masks_per_fes].name = "nof_masks_per_fes";
    submodule_data->defines[dnx_data_field_base_ipmf1_define_nof_masks_per_fes].doc = "Number of masks per FES. For internal DNX_DATA use only.";
    
    submodule_data->defines[dnx_data_field_base_ipmf1_define_nof_masks_per_fes].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_base_ipmf1_define_nof_fes_id_per_array].name = "nof_fes_id_per_array";
    submodule_data->defines[dnx_data_field_base_ipmf1_define_nof_fes_id_per_array].doc = "Number FESes in each FES array. For internal DNX_DATA use only.";
    
    submodule_data->defines[dnx_data_field_base_ipmf1_define_nof_fes_id_per_array].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_base_ipmf1_define_nof_fes_array].name = "nof_fes_array";
    submodule_data->defines[dnx_data_field_base_ipmf1_define_nof_fes_array].doc = "Number FES arrays. For internal DNX_DATA use only.";
    
    submodule_data->defines[dnx_data_field_base_ipmf1_define_nof_fes_array].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_base_ipmf1_define_nof_fes_instruction_per_context].name = "nof_fes_instruction_per_context";
    submodule_data->defines[dnx_data_field_base_ipmf1_define_nof_fes_instruction_per_context].doc = "Number of FES INSTRUCTIONs per context. For internal DNX_DATA use only.";
    
    submodule_data->defines[dnx_data_field_base_ipmf1_define_nof_fes_instruction_per_context].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_base_ipmf1_define_nof_fes_programs].name = "nof_fes_programs";
    submodule_data->defines[dnx_data_field_base_ipmf1_define_nof_fes_programs].doc = "Number of FES programs. For internal DNX_DATA use only.";
    
    submodule_data->defines[dnx_data_field_base_ipmf1_define_nof_fes_programs].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_base_ipmf1_define_nof_prog_per_fes].name = "nof_prog_per_fes";
    submodule_data->defines[dnx_data_field_base_ipmf1_define_nof_prog_per_fes].doc = "Number of MS bits instruction programs per FES. For internal DNX_DATA use only.";
    
    submodule_data->defines[dnx_data_field_base_ipmf1_define_nof_prog_per_fes].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_base_ipmf1_define_cs_container_5_selected_bits_size].name = "cs_container_5_selected_bits_size";
    submodule_data->defines[dnx_data_field_base_ipmf1_define_cs_container_5_selected_bits_size].doc = "Number of bits taken from general data for context selection.";
    
    submodule_data->defines[dnx_data_field_base_ipmf1_define_cs_container_5_selected_bits_size].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_base_ipmf1_define_nof_contexts].name = "nof_contexts";
    submodule_data->defines[dnx_data_field_base_ipmf1_define_nof_contexts].doc = "Number of Ingress PMF_A programs (contexts). For internal DNX_DATA use only.";
    
    submodule_data->defines[dnx_data_field_base_ipmf1_define_nof_contexts].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_base_ipmf1_define_nof_link_profiles].name = "nof_link_profiles";
    submodule_data->defines[dnx_data_field_base_ipmf1_define_nof_link_profiles].doc = "Number of profiles assigned to iPMF1 contexts in order to create links between iPMF1 and iPMF2 contexts. For internal DNX_DATA use only.";
    
    submodule_data->defines[dnx_data_field_base_ipmf1_define_nof_link_profiles].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_base_ipmf1_define_nof_cs_lines].name = "nof_cs_lines";
    submodule_data->defines[dnx_data_field_base_ipmf1_define_nof_cs_lines].doc = "Number of program selection lines. For internal DNX_DATA use only.";
    
    submodule_data->defines[dnx_data_field_base_ipmf1_define_nof_cs_lines].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_base_ipmf1_define_nof_actions].name = "nof_actions";
    submodule_data->defines[dnx_data_field_base_ipmf1_define_nof_actions].doc = "Number of actions. For internal DNX_DATA use only.";
    
    submodule_data->defines[dnx_data_field_base_ipmf1_define_nof_actions].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_base_ipmf1_define_nof_qualifiers].name = "nof_qualifiers";
    submodule_data->defines[dnx_data_field_base_ipmf1_define_nof_qualifiers].doc = "Number of qualifiers. For internal DNX_DATA use only.";
    
    submodule_data->defines[dnx_data_field_base_ipmf1_define_nof_qualifiers].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_base_ipmf1_define_nof_bits_in_fes_action].name = "nof_bits_in_fes_action";
    submodule_data->defines[dnx_data_field_base_ipmf1_define_nof_bits_in_fes_action].doc = "Number of bits on the output of a FES. For internal DNX_DATA use only.";
    
    submodule_data->defines[dnx_data_field_base_ipmf1_define_nof_bits_in_fes_action].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_base_ipmf1_define_nof_bits_in_fes_key_select].name = "nof_bits_in_fes_key_select";
    submodule_data->defines[dnx_data_field_base_ipmf1_define_nof_bits_in_fes_key_select].doc = "Number of bits on input to FES. For internal DNX_DATA use only.";
    
    submodule_data->defines[dnx_data_field_base_ipmf1_define_nof_bits_in_fes_key_select].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_base_ipmf1_define_fes_key_select_resolution_in_bits].name = "fes_key_select_resolution_in_bits";
    submodule_data->defines[dnx_data_field_base_ipmf1_define_fes_key_select_resolution_in_bits].doc = "Number of bits in the 'step' from one 'key select' to the following for EFES. For internal DNX_DATA use only.";
    
    submodule_data->defines[dnx_data_field_base_ipmf1_define_fes_key_select_resolution_in_bits].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_base_ipmf1_define_fem_condition_ms_bit_min_value].name = "fem_condition_ms_bit_min_value";
    submodule_data->defines[dnx_data_field_base_ipmf1_define_fem_condition_ms_bit_min_value].doc = "The minumum legal value to be set in bit select for a FEM. For internal DNX_DATA use only.";
    
    submodule_data->defines[dnx_data_field_base_ipmf1_define_fem_condition_ms_bit_min_value].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_base_ipmf1_define_nof_fem_programs].name = "nof_fem_programs";
    submodule_data->defines[dnx_data_field_base_ipmf1_define_nof_fem_programs].doc = "Total number FEM programs available. For internal DNX_DATA use only.";
    
    submodule_data->defines[dnx_data_field_base_ipmf1_define_nof_fem_programs].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_base_ipmf1_define_log_nof_bits_in_fem_key_select].name = "log_nof_bits_in_fem_key_select";
    submodule_data->defines[dnx_data_field_base_ipmf1_define_log_nof_bits_in_fem_key_select].doc = "Log2 of number of bits on one 'chunk' of input to FEM. For internal DNX_DATA use only.";
    
    submodule_data->defines[dnx_data_field_base_ipmf1_define_log_nof_bits_in_fem_key_select].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_base_ipmf1_define_nof_bits_in_fem_key_select].name = "nof_bits_in_fem_key_select";
    submodule_data->defines[dnx_data_field_base_ipmf1_define_nof_bits_in_fem_key_select].doc = "Number of bits on one 'chunk' of input to FEM. For internal DNX_DATA use only.";
    
    submodule_data->defines[dnx_data_field_base_ipmf1_define_nof_bits_in_fem_key_select].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_base_ipmf1_define_fem_key_select_resolution_in_bits].name = "fem_key_select_resolution_in_bits";
    submodule_data->defines[dnx_data_field_base_ipmf1_define_fem_key_select_resolution_in_bits].doc = "Number of bits in the 'step' from one 'key select' to the following for FEM. See dbal_enum_value_field_field_pmf_a_fem_key_select_e. For internal DNX_DATA use only.";
    
    submodule_data->defines[dnx_data_field_base_ipmf1_define_fem_key_select_resolution_in_bits].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_base_ipmf1_define_log_nof_bits_in_fem_map_data_field].name = "log_nof_bits_in_fem_map_data_field";
    submodule_data->defines[dnx_data_field_base_ipmf1_define_log_nof_bits_in_fem_map_data_field].doc = "Log2 of number of bits on MAP_DATA field in IPPC_FEM_MAP_INDEX_TABLE (See FIELD_PMF_A_FEM_MAP_INDEX dbal table). For internal DNX_DATA use only.";
    
    submodule_data->defines[dnx_data_field_base_ipmf1_define_log_nof_bits_in_fem_map_data_field].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_base_ipmf1_define_nof_bits_in_fem_map_data_field].name = "nof_bits_in_fem_map_data_field";
    submodule_data->defines[dnx_data_field_base_ipmf1_define_nof_bits_in_fem_map_data_field].doc = "Number of bits on MAP_DATA field in IPPC_FEM_MAP_INDEX_TABLE (See FIELD_PMF_A_FEM_MAP_INDEX dbal table). For internal DNX_DATA use only.";
    
    submodule_data->defines[dnx_data_field_base_ipmf1_define_nof_bits_in_fem_map_data_field].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_base_ipmf1_define_nof_bits_in_fem_action_fems_2_15].name = "nof_bits_in_fem_action_fems_2_15";
    submodule_data->defines[dnx_data_field_base_ipmf1_define_nof_bits_in_fem_action_fems_2_15].doc = "Number of bits on action value in IPPC_FEM_*_24B_MAP_TABLE. For internal DNX_DATA use only.";
    
    submodule_data->defines[dnx_data_field_base_ipmf1_define_nof_bits_in_fem_action_fems_2_15].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_base_ipmf1_define_nof_bits_in_fem_action_fems_0_1].name = "nof_bits_in_fem_action_fems_0_1";
    submodule_data->defines[dnx_data_field_base_ipmf1_define_nof_bits_in_fem_action_fems_0_1].doc = "Number of bits on action value in IPPC_FEM_*_4B_MAP_TABLE. For internal DNX_DATA use only.";
    
    submodule_data->defines[dnx_data_field_base_ipmf1_define_nof_bits_in_fem_action_fems_0_1].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_base_ipmf1_define_nof_bits_in_fem_action].name = "nof_bits_in_fem_action";
    submodule_data->defines[dnx_data_field_base_ipmf1_define_nof_bits_in_fem_action].doc = "Maximal number of bits on action value in IPPC_FEM_*_*_MAP_TABLE. For internal DNX_DATA use only.";
    
    submodule_data->defines[dnx_data_field_base_ipmf1_define_nof_bits_in_fem_action].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_base_ipmf1_define_nof_fem_condition].name = "nof_fem_condition";
    submodule_data->defines[dnx_data_field_base_ipmf1_define_nof_fem_condition].doc = "Total number of fem conditions. This is the number of conditions that may be assigned to each (fem_id,fem_program) combination. For internal DNX_DATA use only.";
    
    submodule_data->defines[dnx_data_field_base_ipmf1_define_nof_fem_condition].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_base_ipmf1_define_nof_fem_map_index].name = "nof_fem_map_index";
    submodule_data->defines[dnx_data_field_base_ipmf1_define_nof_fem_map_index].doc = "Total number fem map indices. This represents the number of actions that may be assigned to each condition. For internal DNX_DATA use only.";
    
    submodule_data->defines[dnx_data_field_base_ipmf1_define_nof_fem_map_index].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_base_ipmf1_define_nof_fem_id].name = "nof_fem_id";
    submodule_data->defines[dnx_data_field_base_ipmf1_define_nof_fem_id].doc = "Total number 'FEM id's available. For internal DNX_DATA use only.";
    
    submodule_data->defines[dnx_data_field_base_ipmf1_define_nof_fem_id].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_base_ipmf1_define_num_fems_with_short_action].name = "num_fems_with_short_action";
    submodule_data->defines[dnx_data_field_base_ipmf1_define_num_fems_with_short_action].doc = "Number of FEMs, starting from 'fem_id=0', which have only 4 bits on action value. The rest have 24 bits on action value. For internal DNX_DATA use only.";
    
    submodule_data->defines[dnx_data_field_base_ipmf1_define_num_fems_with_short_action].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_base_ipmf1_define_num_bits_in_fem_field_select].name = "num_bits_in_fem_field_select";
    submodule_data->defines[dnx_data_field_base_ipmf1_define_num_bits_in_fem_field_select].doc = "Number of bits on each of the HW field marked FIELD_SELECT_MAP_*. For internal DNX_DATA use only.";
    
    submodule_data->defines[dnx_data_field_base_ipmf1_define_num_bits_in_fem_field_select].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_base_ipmf1_define_nof_fem_id_per_array].name = "nof_fem_id_per_array";
    submodule_data->defines[dnx_data_field_base_ipmf1_define_nof_fem_id_per_array].doc = "Number FEMes in each FEM array. For internal DNX_DATA use only.";
    
    submodule_data->defines[dnx_data_field_base_ipmf1_define_nof_fem_id_per_array].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_base_ipmf1_define_nof_fem_array].name = "nof_fem_array";
    submodule_data->defines[dnx_data_field_base_ipmf1_define_nof_fem_array].doc = "Number FEM arrays. For internal DNX_DATA use only.";
    
    submodule_data->defines[dnx_data_field_base_ipmf1_define_nof_fem_array].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_base_ipmf1_define_nof_compare_pairs_in_compare_mode].name = "nof_compare_pairs_in_compare_mode";
    submodule_data->defines[dnx_data_field_base_ipmf1_define_nof_compare_pairs_in_compare_mode].doc = "Number compare pairs in compare mode. For internal DNX_DATA use only.";
    
    submodule_data->defines[dnx_data_field_base_ipmf1_define_nof_compare_pairs_in_compare_mode].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_base_ipmf1_define_compare_key_size].name = "compare_key_size";
    submodule_data->defines[dnx_data_field_base_ipmf1_define_compare_key_size].doc = "Size of the compare key in the system. For internal DNX_DATA use only.";
    
    submodule_data->defines[dnx_data_field_base_ipmf1_define_compare_key_size].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_base_ipmf1_define_nof_l4_ops_ranges_legacy].name = "nof_l4_ops_ranges_legacy";
    submodule_data->defines[dnx_data_field_base_ipmf1_define_nof_l4_ops_ranges_legacy].doc = "Number of ranges for L4 Ops legacy. For internal DNX_DATA use only.";
    
    submodule_data->defines[dnx_data_field_base_ipmf1_define_nof_l4_ops_ranges_legacy].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_base_ipmf1_define_nof_ext_l4_ops_ranges].name = "nof_ext_l4_ops_ranges";
    submodule_data->defines[dnx_data_field_base_ipmf1_define_nof_ext_l4_ops_ranges].doc = "Number of ranges for External L4 Ops. For internal DNX_DATA use only.";
    
    submodule_data->defines[dnx_data_field_base_ipmf1_define_nof_ext_l4_ops_ranges].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_base_ipmf1_define_nof_pkt_hdr_ranges].name = "nof_pkt_hdr_ranges";
    submodule_data->defines[dnx_data_field_base_ipmf1_define_nof_pkt_hdr_ranges].doc = "Number of ranges for PKT HDR. For internal DNX_DATA use only.";
    
    submodule_data->defines[dnx_data_field_base_ipmf1_define_nof_pkt_hdr_ranges].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_base_ipmf1_define_nof_out_lif_ranges].name = "nof_out_lif_ranges";
    submodule_data->defines[dnx_data_field_base_ipmf1_define_nof_out_lif_ranges].doc = "Number of ranges for Out Lif. For internal DNX_DATA use only.";
    
    submodule_data->defines[dnx_data_field_base_ipmf1_define_nof_out_lif_ranges].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_base_ipmf1_define_cmp_selection].name = "cmp_selection";
    submodule_data->defines[dnx_data_field_base_ipmf1_define_cmp_selection].doc = "Compare selection for both keys of 2nd compare, See the CMP_SELECTION field in IPPC_PMF_GENERAL register for additional information. For internal DNX_DATA use only.";
    
    submodule_data->defines[dnx_data_field_base_ipmf1_define_cmp_selection].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_base_ipmf1_define_dir_ext_single_key_size].name = "dir_ext_single_key_size";
    submodule_data->defines[dnx_data_field_base_ipmf1_define_dir_ext_single_key_size].doc = "Single key size used for Direct Extraction. For internal DNX_DATA use only";
    
    submodule_data->defines[dnx_data_field_base_ipmf1_define_dir_ext_single_key_size].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_base_ipmf1_define_dir_ext_first_key].name = "dir_ext_first_key";
    submodule_data->defines[dnx_data_field_base_ipmf1_define_dir_ext_first_key].doc = "First key used for direct extraction. For internal DNX_DATA use only.";
    
    submodule_data->defines[dnx_data_field_base_ipmf1_define_dir_ext_first_key].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_base_ipmf1_define_exem_max_result_size].name = "exem_max_result_size";
    submodule_data->defines[dnx_data_field_base_ipmf1_define_exem_max_result_size].doc = "EXEM result (payload) size in bits, including VMV";
    
    submodule_data->defines[dnx_data_field_base_ipmf1_define_exem_max_result_size].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_base_ipmf1_define_fes_instruction_size].name = "fes_instruction_size";
    submodule_data->defines[dnx_data_field_base_ipmf1_define_fes_instruction_size].doc = "Number of bits in one fes instruction.";
    
    submodule_data->defines[dnx_data_field_base_ipmf1_define_fes_instruction_size].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_base_ipmf1_define_fes_pgm_id_offset].name = "fes_pgm_id_offset";
    submodule_data->defines[dnx_data_field_base_ipmf1_define_fes_pgm_id_offset].doc = "FES Program ID offset pointing to IPPC_PMF_FES_PROGRAMm->FES_2ND_INSTRUCTION_LSB_ADDRESSf.";
    
    submodule_data->defines[dnx_data_field_base_ipmf1_define_fes_pgm_id_offset].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_base_ipmf1_define_fes_key_select_for_zero_bit].name = "fes_key_select_for_zero_bit";
    submodule_data->defines[dnx_data_field_base_ipmf1_define_fes_key_select_for_zero_bit].doc = "The key select used for obtaining an always zero bit for input to FES (for example, using a zero padded bit). For internal DNX_DATA use only.";
    
    submodule_data->defines[dnx_data_field_base_ipmf1_define_fes_key_select_for_zero_bit].flags |= DNXC_DATA_F_NUMERIC;

    submodule_data->defines[dnx_data_field_base_ipmf1_define_fes_shift_for_zero_bit].name = "fes_shift_for_zero_bit";
    submodule_data->defines[dnx_data_field_base_ipmf1_define_fes_shift_for_zero_bit].doc = "The shift used for obtaining an always zero bit for input to FES (for example, using a zero padded bit). For internal DNX_DATA use only.";
    
    submodule_data->defines[dnx_data_field_base_ipmf1_define_fes_shift_for_zero_bit].flags |= DNXC_DATA_F_NUMERIC;

    submodule_data->defines[dnx_data_field_base_ipmf1_define_exem_pdb].name = "exem_pdb";
    submodule_data->defines[dnx_data_field_base_ipmf1_define_exem_pdb].doc = "EXEM physical database type in the form of dbal_physical_tables_e. For internal DNX_DATA use only.";
    
    submodule_data->defines[dnx_data_field_base_ipmf1_define_exem_pdb].flags |= DNXC_DATA_F_NUMERIC;

    
    submodule_data->nof_tables = _dnx_data_field_base_ipmf1_table_nof;
    DNXC_DATA_ALLOC(submodule_data->tables, dnxc_data_table_t, submodule_data->nof_tables, "_dnxc_data field base_ipmf1 tables");


exit:
    SHR_FUNC_EXIT;
}


int
dnx_data_field_base_ipmf1_feature_get(
    int unit,
    dnx_data_field_base_ipmf1_feature_e feature)
{
    return dnxc_data_mgmt_feature_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_ipmf1, feature);
}


uint32
dnx_data_field_base_ipmf1_nof_ffc_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_ipmf1, dnx_data_field_base_ipmf1_define_nof_ffc);
}

uint32
dnx_data_field_base_ipmf1_nof_keys_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_ipmf1, dnx_data_field_base_ipmf1_define_nof_keys);
}

uint32
dnx_data_field_base_ipmf1_nof_keys_alloc_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_ipmf1, dnx_data_field_base_ipmf1_define_nof_keys_alloc);
}

uint32
dnx_data_field_base_ipmf1_nof_keys_alloc_for_tcam_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_ipmf1, dnx_data_field_base_ipmf1_define_nof_keys_alloc_for_tcam);
}

uint32
dnx_data_field_base_ipmf1_nof_keys_alloc_for_exem_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_ipmf1, dnx_data_field_base_ipmf1_define_nof_keys_alloc_for_exem);
}

uint32
dnx_data_field_base_ipmf1_nof_keys_alloc_for_dir_ext_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_ipmf1, dnx_data_field_base_ipmf1_define_nof_keys_alloc_for_dir_ext);
}

uint32
dnx_data_field_base_ipmf1_nof_keys_alloc_for_mdb_dt_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_ipmf1, dnx_data_field_base_ipmf1_define_nof_keys_alloc_for_mdb_dt);
}

uint32
dnx_data_field_base_ipmf1_nof_masks_per_fes_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_ipmf1, dnx_data_field_base_ipmf1_define_nof_masks_per_fes);
}

uint32
dnx_data_field_base_ipmf1_nof_fes_id_per_array_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_ipmf1, dnx_data_field_base_ipmf1_define_nof_fes_id_per_array);
}

uint32
dnx_data_field_base_ipmf1_nof_fes_array_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_ipmf1, dnx_data_field_base_ipmf1_define_nof_fes_array);
}

uint32
dnx_data_field_base_ipmf1_nof_fes_instruction_per_context_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_ipmf1, dnx_data_field_base_ipmf1_define_nof_fes_instruction_per_context);
}

uint32
dnx_data_field_base_ipmf1_nof_fes_programs_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_ipmf1, dnx_data_field_base_ipmf1_define_nof_fes_programs);
}

uint32
dnx_data_field_base_ipmf1_nof_prog_per_fes_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_ipmf1, dnx_data_field_base_ipmf1_define_nof_prog_per_fes);
}

uint32
dnx_data_field_base_ipmf1_cs_container_5_selected_bits_size_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_ipmf1, dnx_data_field_base_ipmf1_define_cs_container_5_selected_bits_size);
}

uint32
dnx_data_field_base_ipmf1_nof_contexts_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_ipmf1, dnx_data_field_base_ipmf1_define_nof_contexts);
}

uint32
dnx_data_field_base_ipmf1_nof_link_profiles_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_ipmf1, dnx_data_field_base_ipmf1_define_nof_link_profiles);
}

uint32
dnx_data_field_base_ipmf1_nof_cs_lines_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_ipmf1, dnx_data_field_base_ipmf1_define_nof_cs_lines);
}

uint32
dnx_data_field_base_ipmf1_nof_actions_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_ipmf1, dnx_data_field_base_ipmf1_define_nof_actions);
}

uint32
dnx_data_field_base_ipmf1_nof_qualifiers_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_ipmf1, dnx_data_field_base_ipmf1_define_nof_qualifiers);
}

uint32
dnx_data_field_base_ipmf1_nof_bits_in_fes_action_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_ipmf1, dnx_data_field_base_ipmf1_define_nof_bits_in_fes_action);
}

uint32
dnx_data_field_base_ipmf1_nof_bits_in_fes_key_select_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_ipmf1, dnx_data_field_base_ipmf1_define_nof_bits_in_fes_key_select);
}

uint32
dnx_data_field_base_ipmf1_fes_key_select_resolution_in_bits_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_ipmf1, dnx_data_field_base_ipmf1_define_fes_key_select_resolution_in_bits);
}

uint32
dnx_data_field_base_ipmf1_fem_condition_ms_bit_min_value_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_ipmf1, dnx_data_field_base_ipmf1_define_fem_condition_ms_bit_min_value);
}

uint32
dnx_data_field_base_ipmf1_nof_fem_programs_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_ipmf1, dnx_data_field_base_ipmf1_define_nof_fem_programs);
}

uint32
dnx_data_field_base_ipmf1_log_nof_bits_in_fem_key_select_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_ipmf1, dnx_data_field_base_ipmf1_define_log_nof_bits_in_fem_key_select);
}

uint32
dnx_data_field_base_ipmf1_nof_bits_in_fem_key_select_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_ipmf1, dnx_data_field_base_ipmf1_define_nof_bits_in_fem_key_select);
}

uint32
dnx_data_field_base_ipmf1_fem_key_select_resolution_in_bits_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_ipmf1, dnx_data_field_base_ipmf1_define_fem_key_select_resolution_in_bits);
}

uint32
dnx_data_field_base_ipmf1_log_nof_bits_in_fem_map_data_field_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_ipmf1, dnx_data_field_base_ipmf1_define_log_nof_bits_in_fem_map_data_field);
}

uint32
dnx_data_field_base_ipmf1_nof_bits_in_fem_map_data_field_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_ipmf1, dnx_data_field_base_ipmf1_define_nof_bits_in_fem_map_data_field);
}

uint32
dnx_data_field_base_ipmf1_nof_bits_in_fem_action_fems_2_15_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_ipmf1, dnx_data_field_base_ipmf1_define_nof_bits_in_fem_action_fems_2_15);
}

uint32
dnx_data_field_base_ipmf1_nof_bits_in_fem_action_fems_0_1_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_ipmf1, dnx_data_field_base_ipmf1_define_nof_bits_in_fem_action_fems_0_1);
}

uint32
dnx_data_field_base_ipmf1_nof_bits_in_fem_action_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_ipmf1, dnx_data_field_base_ipmf1_define_nof_bits_in_fem_action);
}

uint32
dnx_data_field_base_ipmf1_nof_fem_condition_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_ipmf1, dnx_data_field_base_ipmf1_define_nof_fem_condition);
}

uint32
dnx_data_field_base_ipmf1_nof_fem_map_index_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_ipmf1, dnx_data_field_base_ipmf1_define_nof_fem_map_index);
}

uint32
dnx_data_field_base_ipmf1_nof_fem_id_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_ipmf1, dnx_data_field_base_ipmf1_define_nof_fem_id);
}

uint32
dnx_data_field_base_ipmf1_num_fems_with_short_action_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_ipmf1, dnx_data_field_base_ipmf1_define_num_fems_with_short_action);
}

uint32
dnx_data_field_base_ipmf1_num_bits_in_fem_field_select_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_ipmf1, dnx_data_field_base_ipmf1_define_num_bits_in_fem_field_select);
}

uint32
dnx_data_field_base_ipmf1_nof_fem_id_per_array_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_ipmf1, dnx_data_field_base_ipmf1_define_nof_fem_id_per_array);
}

uint32
dnx_data_field_base_ipmf1_nof_fem_array_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_ipmf1, dnx_data_field_base_ipmf1_define_nof_fem_array);
}

uint32
dnx_data_field_base_ipmf1_nof_compare_pairs_in_compare_mode_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_ipmf1, dnx_data_field_base_ipmf1_define_nof_compare_pairs_in_compare_mode);
}

uint32
dnx_data_field_base_ipmf1_compare_key_size_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_ipmf1, dnx_data_field_base_ipmf1_define_compare_key_size);
}

uint32
dnx_data_field_base_ipmf1_nof_l4_ops_ranges_legacy_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_ipmf1, dnx_data_field_base_ipmf1_define_nof_l4_ops_ranges_legacy);
}

uint32
dnx_data_field_base_ipmf1_nof_ext_l4_ops_ranges_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_ipmf1, dnx_data_field_base_ipmf1_define_nof_ext_l4_ops_ranges);
}

uint32
dnx_data_field_base_ipmf1_nof_pkt_hdr_ranges_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_ipmf1, dnx_data_field_base_ipmf1_define_nof_pkt_hdr_ranges);
}

uint32
dnx_data_field_base_ipmf1_nof_out_lif_ranges_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_ipmf1, dnx_data_field_base_ipmf1_define_nof_out_lif_ranges);
}

uint32
dnx_data_field_base_ipmf1_cmp_selection_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_ipmf1, dnx_data_field_base_ipmf1_define_cmp_selection);
}

uint32
dnx_data_field_base_ipmf1_dir_ext_single_key_size_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_ipmf1, dnx_data_field_base_ipmf1_define_dir_ext_single_key_size);
}

uint32
dnx_data_field_base_ipmf1_dir_ext_first_key_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_ipmf1, dnx_data_field_base_ipmf1_define_dir_ext_first_key);
}

uint32
dnx_data_field_base_ipmf1_exem_max_result_size_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_ipmf1, dnx_data_field_base_ipmf1_define_exem_max_result_size);
}

uint32
dnx_data_field_base_ipmf1_fes_instruction_size_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_ipmf1, dnx_data_field_base_ipmf1_define_fes_instruction_size);
}

uint32
dnx_data_field_base_ipmf1_fes_pgm_id_offset_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_ipmf1, dnx_data_field_base_ipmf1_define_fes_pgm_id_offset);
}

uint32
dnx_data_field_base_ipmf1_fes_key_select_for_zero_bit_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_ipmf1, dnx_data_field_base_ipmf1_define_fes_key_select_for_zero_bit);
}

uint32
dnx_data_field_base_ipmf1_fes_shift_for_zero_bit_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_ipmf1, dnx_data_field_base_ipmf1_define_fes_shift_for_zero_bit);
}

uint32
dnx_data_field_base_ipmf1_exem_pdb_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_ipmf1, dnx_data_field_base_ipmf1_define_exem_pdb);
}










static shr_error_e
dnx_data_field_base_ipmf2_init(
    int unit,
    dnxc_data_submodule_t *submodule_data)
{
    SHR_FUNC_INIT_VARS(unit);

    submodule_data->name = "base_ipmf2";
    submodule_data->doc = "Ingress PMF_2 data. For internal DNX DATA use only. Use stage submodule instead.";
    
    submodule_data->nof_features = _dnx_data_field_base_ipmf2_feature_nof;
    DNXC_DATA_ALLOC(submodule_data->features, dnxc_data_feature_t,  submodule_data->nof_features, "_dnxc_data field base_ipmf2 features");

    
    submodule_data->nof_defines = _dnx_data_field_base_ipmf2_define_nof;
    DNXC_DATA_ALLOC(submodule_data->defines, dnxc_data_define_t, submodule_data->nof_defines, "_dnxc_data field base_ipmf2 defines");

    submodule_data->defines[dnx_data_field_base_ipmf2_define_nof_ffc].name = "nof_ffc";
    submodule_data->defines[dnx_data_field_base_ipmf2_define_nof_ffc].doc = "Number of FFC's per context. For internal DNX_DATA use only.";
    
    submodule_data->defines[dnx_data_field_base_ipmf2_define_nof_ffc].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_base_ipmf2_define_nof_keys].name = "nof_keys";
    submodule_data->defines[dnx_data_field_base_ipmf2_define_nof_keys].doc = "Number of keys for the this PMF stage. For internal DNX_DATA use only.";
    
    submodule_data->defines[dnx_data_field_base_ipmf2_define_nof_keys].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_base_ipmf2_define_nof_keys_alloc].name = "nof_keys_alloc";
    submodule_data->defines[dnx_data_field_base_ipmf2_define_nof_keys_alloc].doc = "Number of keys available for allocation for use by this specific PMF stage. For internal DNX_DATA use only.";
    
    submodule_data->defines[dnx_data_field_base_ipmf2_define_nof_keys_alloc].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_base_ipmf2_define_nof_keys_alloc_for_tcam].name = "nof_keys_alloc_for_tcam";
    submodule_data->defines[dnx_data_field_base_ipmf2_define_nof_keys_alloc_for_tcam].doc = "Number of keys available for allocation for use by this specific PMF stage for TCAM access. For internal DNX_DATA use only.";
    
    submodule_data->defines[dnx_data_field_base_ipmf2_define_nof_keys_alloc_for_tcam].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_base_ipmf2_define_nof_keys_alloc_for_exem].name = "nof_keys_alloc_for_exem";
    submodule_data->defines[dnx_data_field_base_ipmf2_define_nof_keys_alloc_for_exem].doc = "Number of keys available for allocation for use by this specific PMF stage for EXEM access. For internal DNX_DATA use only.";
    
    submodule_data->defines[dnx_data_field_base_ipmf2_define_nof_keys_alloc_for_exem].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_base_ipmf2_define_nof_keys_alloc_for_dir_ext].name = "nof_keys_alloc_for_dir_ext";
    submodule_data->defines[dnx_data_field_base_ipmf2_define_nof_keys_alloc_for_dir_ext].doc = "Number of keys available for allocation for use by this specific PMF stage for DIRECT EXTRACTION. For internal DNX_DATA use only.";
    
    submodule_data->defines[dnx_data_field_base_ipmf2_define_nof_keys_alloc_for_dir_ext].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_base_ipmf2_define_nof_keys_alloc_for_mdb_dt].name = "nof_keys_alloc_for_mdb_dt";
    submodule_data->defines[dnx_data_field_base_ipmf2_define_nof_keys_alloc_for_mdb_dt].doc = "Number of keys available for allocation for use by this specific PMF stage for MDB_DT access. For internal DNX_DATA use only.";
    
    submodule_data->defines[dnx_data_field_base_ipmf2_define_nof_keys_alloc_for_mdb_dt].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_base_ipmf2_define_nof_masks_per_fes].name = "nof_masks_per_fes";
    submodule_data->defines[dnx_data_field_base_ipmf2_define_nof_masks_per_fes].doc = "Number of masks per FES. For internal DNX_DATA use only.";
    
    submodule_data->defines[dnx_data_field_base_ipmf2_define_nof_masks_per_fes].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_base_ipmf2_define_nof_fes_id_per_array].name = "nof_fes_id_per_array";
    submodule_data->defines[dnx_data_field_base_ipmf2_define_nof_fes_id_per_array].doc = "Number FESes in each FES array. For internal DNX_DATA use only.";
    
    submodule_data->defines[dnx_data_field_base_ipmf2_define_nof_fes_id_per_array].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_base_ipmf2_define_nof_fes_array].name = "nof_fes_array";
    submodule_data->defines[dnx_data_field_base_ipmf2_define_nof_fes_array].doc = "Number FES arrays. For internal DNX_DATA use only.";
    
    submodule_data->defines[dnx_data_field_base_ipmf2_define_nof_fes_array].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_base_ipmf2_define_nof_fes_instruction_per_context].name = "nof_fes_instruction_per_context";
    submodule_data->defines[dnx_data_field_base_ipmf2_define_nof_fes_instruction_per_context].doc = "Number of FES INSTRUCTIONs per context. For internal DNX_DATA use only.";
    
    submodule_data->defines[dnx_data_field_base_ipmf2_define_nof_fes_instruction_per_context].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_base_ipmf2_define_nof_cs_lines].name = "nof_cs_lines";
    submodule_data->defines[dnx_data_field_base_ipmf2_define_nof_cs_lines].doc = "Number of program selection lines. For internal DNX_DATA use only.";
    
    submodule_data->defines[dnx_data_field_base_ipmf2_define_nof_cs_lines].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_base_ipmf2_define_nof_contexts].name = "nof_contexts";
    submodule_data->defines[dnx_data_field_base_ipmf2_define_nof_contexts].doc = "Number of contexts. For internal DNX_DATA use only.";
    
    submodule_data->defines[dnx_data_field_base_ipmf2_define_nof_contexts].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_base_ipmf2_define_nof_qualifiers].name = "nof_qualifiers";
    submodule_data->defines[dnx_data_field_base_ipmf2_define_nof_qualifiers].doc = "Number of qualifiers. For internal DNX_DATA use only.";
    
    submodule_data->defines[dnx_data_field_base_ipmf2_define_nof_qualifiers].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_base_ipmf2_define_dir_ext_single_key_size].name = "dir_ext_single_key_size";
    submodule_data->defines[dnx_data_field_base_ipmf2_define_dir_ext_single_key_size].doc = "Single key size used for Direct Extraction. For internal DNX_DATA use only.";
    
    submodule_data->defines[dnx_data_field_base_ipmf2_define_dir_ext_single_key_size].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_base_ipmf2_define_dir_ext_first_key].name = "dir_ext_first_key";
    submodule_data->defines[dnx_data_field_base_ipmf2_define_dir_ext_first_key].doc = "First key used for direct extraction. For internal DNX_DATA use only.";
    
    submodule_data->defines[dnx_data_field_base_ipmf2_define_dir_ext_first_key].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_base_ipmf2_define_exem_max_result_size].name = "exem_max_result_size";
    submodule_data->defines[dnx_data_field_base_ipmf2_define_exem_max_result_size].doc = "EXEM result (payload) size in bits, including VMV";
    
    submodule_data->defines[dnx_data_field_base_ipmf2_define_exem_max_result_size].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_base_ipmf2_define_fes_key_select_for_zero_bit].name = "fes_key_select_for_zero_bit";
    submodule_data->defines[dnx_data_field_base_ipmf2_define_fes_key_select_for_zero_bit].doc = "The key select used for obtaining an always zero bit for input to FES (for example, using a zero padded bit). For internal DNX_DATA use only.";
    
    submodule_data->defines[dnx_data_field_base_ipmf2_define_fes_key_select_for_zero_bit].flags |= DNXC_DATA_F_NUMERIC;

    submodule_data->defines[dnx_data_field_base_ipmf2_define_fes_shift_for_zero_bit].name = "fes_shift_for_zero_bit";
    submodule_data->defines[dnx_data_field_base_ipmf2_define_fes_shift_for_zero_bit].doc = "The shift used for obtaining an always zero bit for input to FES (for example, using a zero padded bit). For internal DNX_DATA use only.";
    
    submodule_data->defines[dnx_data_field_base_ipmf2_define_fes_shift_for_zero_bit].flags |= DNXC_DATA_F_NUMERIC;

    submodule_data->defines[dnx_data_field_base_ipmf2_define_exem_pdb].name = "exem_pdb";
    submodule_data->defines[dnx_data_field_base_ipmf2_define_exem_pdb].doc = "EXEM physical database type in the form of dbal_physical_tables_e. For internal DNX_DATA use only.";
    
    submodule_data->defines[dnx_data_field_base_ipmf2_define_exem_pdb].flags |= DNXC_DATA_F_NUMERIC;

    
    submodule_data->nof_tables = _dnx_data_field_base_ipmf2_table_nof;
    DNXC_DATA_ALLOC(submodule_data->tables, dnxc_data_table_t, submodule_data->nof_tables, "_dnxc_data field base_ipmf2 tables");


exit:
    SHR_FUNC_EXIT;
}


int
dnx_data_field_base_ipmf2_feature_get(
    int unit,
    dnx_data_field_base_ipmf2_feature_e feature)
{
    return dnxc_data_mgmt_feature_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_ipmf2, feature);
}


uint32
dnx_data_field_base_ipmf2_nof_ffc_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_ipmf2, dnx_data_field_base_ipmf2_define_nof_ffc);
}

uint32
dnx_data_field_base_ipmf2_nof_keys_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_ipmf2, dnx_data_field_base_ipmf2_define_nof_keys);
}

uint32
dnx_data_field_base_ipmf2_nof_keys_alloc_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_ipmf2, dnx_data_field_base_ipmf2_define_nof_keys_alloc);
}

uint32
dnx_data_field_base_ipmf2_nof_keys_alloc_for_tcam_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_ipmf2, dnx_data_field_base_ipmf2_define_nof_keys_alloc_for_tcam);
}

uint32
dnx_data_field_base_ipmf2_nof_keys_alloc_for_exem_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_ipmf2, dnx_data_field_base_ipmf2_define_nof_keys_alloc_for_exem);
}

uint32
dnx_data_field_base_ipmf2_nof_keys_alloc_for_dir_ext_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_ipmf2, dnx_data_field_base_ipmf2_define_nof_keys_alloc_for_dir_ext);
}

uint32
dnx_data_field_base_ipmf2_nof_keys_alloc_for_mdb_dt_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_ipmf2, dnx_data_field_base_ipmf2_define_nof_keys_alloc_for_mdb_dt);
}

uint32
dnx_data_field_base_ipmf2_nof_masks_per_fes_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_ipmf2, dnx_data_field_base_ipmf2_define_nof_masks_per_fes);
}

uint32
dnx_data_field_base_ipmf2_nof_fes_id_per_array_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_ipmf2, dnx_data_field_base_ipmf2_define_nof_fes_id_per_array);
}

uint32
dnx_data_field_base_ipmf2_nof_fes_array_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_ipmf2, dnx_data_field_base_ipmf2_define_nof_fes_array);
}

uint32
dnx_data_field_base_ipmf2_nof_fes_instruction_per_context_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_ipmf2, dnx_data_field_base_ipmf2_define_nof_fes_instruction_per_context);
}

uint32
dnx_data_field_base_ipmf2_nof_cs_lines_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_ipmf2, dnx_data_field_base_ipmf2_define_nof_cs_lines);
}

uint32
dnx_data_field_base_ipmf2_nof_contexts_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_ipmf2, dnx_data_field_base_ipmf2_define_nof_contexts);
}

uint32
dnx_data_field_base_ipmf2_nof_qualifiers_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_ipmf2, dnx_data_field_base_ipmf2_define_nof_qualifiers);
}

uint32
dnx_data_field_base_ipmf2_dir_ext_single_key_size_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_ipmf2, dnx_data_field_base_ipmf2_define_dir_ext_single_key_size);
}

uint32
dnx_data_field_base_ipmf2_dir_ext_first_key_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_ipmf2, dnx_data_field_base_ipmf2_define_dir_ext_first_key);
}

uint32
dnx_data_field_base_ipmf2_exem_max_result_size_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_ipmf2, dnx_data_field_base_ipmf2_define_exem_max_result_size);
}

uint32
dnx_data_field_base_ipmf2_fes_key_select_for_zero_bit_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_ipmf2, dnx_data_field_base_ipmf2_define_fes_key_select_for_zero_bit);
}

uint32
dnx_data_field_base_ipmf2_fes_shift_for_zero_bit_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_ipmf2, dnx_data_field_base_ipmf2_define_fes_shift_for_zero_bit);
}

uint32
dnx_data_field_base_ipmf2_exem_pdb_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_ipmf2, dnx_data_field_base_ipmf2_define_exem_pdb);
}










static shr_error_e
dnx_data_field_base_ipmf3_init(
    int unit,
    dnxc_data_submodule_t *submodule_data)
{
    SHR_FUNC_INIT_VARS(unit);

    submodule_data->name = "base_ipmf3";
    submodule_data->doc = "Ingress PMF_3 (PMF_B) data. For internal DNX DATA use only. Use stage submodule instead.";
    
    submodule_data->nof_features = _dnx_data_field_base_ipmf3_feature_nof;
    DNXC_DATA_ALLOC(submodule_data->features, dnxc_data_feature_t,  submodule_data->nof_features, "_dnxc_data field base_ipmf3 features");

    
    submodule_data->nof_defines = _dnx_data_field_base_ipmf3_define_nof;
    DNXC_DATA_ALLOC(submodule_data->defines, dnxc_data_define_t, submodule_data->nof_defines, "_dnxc_data field base_ipmf3 defines");

    submodule_data->defines[dnx_data_field_base_ipmf3_define_nof_ffc].name = "nof_ffc";
    submodule_data->defines[dnx_data_field_base_ipmf3_define_nof_ffc].doc = "Number of FFC's. For internal DNX_DATA use only.";
    
    submodule_data->defines[dnx_data_field_base_ipmf3_define_nof_ffc].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_base_ipmf3_define_nof_keys].name = "nof_keys";
    submodule_data->defines[dnx_data_field_base_ipmf3_define_nof_keys].doc = "Number of keys for the this PMF stage. For internal DNX_DATA use only.";
    
    submodule_data->defines[dnx_data_field_base_ipmf3_define_nof_keys].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_base_ipmf3_define_nof_keys_alloc].name = "nof_keys_alloc";
    submodule_data->defines[dnx_data_field_base_ipmf3_define_nof_keys_alloc].doc = "Number of keys available for allocation for use by this specific PMF stage. For internal DNX_DATA use only.";
    
    submodule_data->defines[dnx_data_field_base_ipmf3_define_nof_keys_alloc].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_base_ipmf3_define_nof_keys_alloc_for_tcam].name = "nof_keys_alloc_for_tcam";
    submodule_data->defines[dnx_data_field_base_ipmf3_define_nof_keys_alloc_for_tcam].doc = "Number of keys available for allocation for use by this specific PMF stage for TCAM access. For internal DNX_DATA use only.";
    
    submodule_data->defines[dnx_data_field_base_ipmf3_define_nof_keys_alloc_for_tcam].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_base_ipmf3_define_nof_keys_alloc_for_exem].name = "nof_keys_alloc_for_exem";
    submodule_data->defines[dnx_data_field_base_ipmf3_define_nof_keys_alloc_for_exem].doc = "Number of keys available for allocation for use by this specific PMF stage for EXEM access. For internal DNX_DATA use only.";
    
    submodule_data->defines[dnx_data_field_base_ipmf3_define_nof_keys_alloc_for_exem].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_base_ipmf3_define_nof_keys_alloc_for_dir_ext].name = "nof_keys_alloc_for_dir_ext";
    submodule_data->defines[dnx_data_field_base_ipmf3_define_nof_keys_alloc_for_dir_ext].doc = "Number of keys available for allocation for use by this specific PMF stage for DIRECT EXTRACTION. For internal DNX_DATA use only.";
    
    submodule_data->defines[dnx_data_field_base_ipmf3_define_nof_keys_alloc_for_dir_ext].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_base_ipmf3_define_nof_keys_alloc_for_mdb_dt].name = "nof_keys_alloc_for_mdb_dt";
    submodule_data->defines[dnx_data_field_base_ipmf3_define_nof_keys_alloc_for_mdb_dt].doc = "Number of keys available for allocation for use by this specific PMF stage for MDB_DT access. For internal DNX_DATA use only.";
    
    submodule_data->defines[dnx_data_field_base_ipmf3_define_nof_keys_alloc_for_mdb_dt].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_base_ipmf3_define_nof_masks_per_fes].name = "nof_masks_per_fes";
    submodule_data->defines[dnx_data_field_base_ipmf3_define_nof_masks_per_fes].doc = "Number of masks per FES. For internal DNX_DATA use only.";
    
    submodule_data->defines[dnx_data_field_base_ipmf3_define_nof_masks_per_fes].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_base_ipmf3_define_nof_fes_id_per_array].name = "nof_fes_id_per_array";
    submodule_data->defines[dnx_data_field_base_ipmf3_define_nof_fes_id_per_array].doc = "Number FESes in each FES array. For internal DNX_DATA use only.";
    
    submodule_data->defines[dnx_data_field_base_ipmf3_define_nof_fes_id_per_array].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_base_ipmf3_define_nof_fes_array].name = "nof_fes_array";
    submodule_data->defines[dnx_data_field_base_ipmf3_define_nof_fes_array].doc = "Number FES arrays. For internal DNX_DATA use only.";
    
    submodule_data->defines[dnx_data_field_base_ipmf3_define_nof_fes_array].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_base_ipmf3_define_nof_fes_instruction_per_context].name = "nof_fes_instruction_per_context";
    submodule_data->defines[dnx_data_field_base_ipmf3_define_nof_fes_instruction_per_context].doc = "Number of FES INSTRUCTIONs per context. For internal DNX_DATA use only.";
    
    submodule_data->defines[dnx_data_field_base_ipmf3_define_nof_fes_instruction_per_context].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_base_ipmf3_define_nof_fes_programs].name = "nof_fes_programs";
    submodule_data->defines[dnx_data_field_base_ipmf3_define_nof_fes_programs].doc = "Number of FES programs. For internal DNX_DATA use only.";
    
    submodule_data->defines[dnx_data_field_base_ipmf3_define_nof_fes_programs].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_base_ipmf3_define_nof_prog_per_fes].name = "nof_prog_per_fes";
    submodule_data->defines[dnx_data_field_base_ipmf3_define_nof_prog_per_fes].doc = "Number of MS bits instruction programs per FES. For internal DNX_DATA use only.";
    
    submodule_data->defines[dnx_data_field_base_ipmf3_define_nof_prog_per_fes].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_base_ipmf3_define_cs_scratch_pad_size].name = "cs_scratch_pad_size";
    submodule_data->defines[dnx_data_field_base_ipmf3_define_cs_scratch_pad_size].doc = "Number of bits taken from general data for context selection.";
    
    submodule_data->defines[dnx_data_field_base_ipmf3_define_cs_scratch_pad_size].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_base_ipmf3_define_nof_contexts].name = "nof_contexts";
    submodule_data->defines[dnx_data_field_base_ipmf3_define_nof_contexts].doc = "Number of Ingress PMF_B programs. For internal DNX_DATA use only.";
    
    submodule_data->defines[dnx_data_field_base_ipmf3_define_nof_contexts].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_base_ipmf3_define_nof_cs_lines].name = "nof_cs_lines";
    submodule_data->defines[dnx_data_field_base_ipmf3_define_nof_cs_lines].doc = "Number of program selection lines. For internal DNX_DATA use only.";
    
    submodule_data->defines[dnx_data_field_base_ipmf3_define_nof_cs_lines].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_base_ipmf3_define_nof_actions].name = "nof_actions";
    submodule_data->defines[dnx_data_field_base_ipmf3_define_nof_actions].doc = "Number of actions. For internal DNX_DATA use only.";
    
    submodule_data->defines[dnx_data_field_base_ipmf3_define_nof_actions].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_base_ipmf3_define_nof_qualifiers].name = "nof_qualifiers";
    submodule_data->defines[dnx_data_field_base_ipmf3_define_nof_qualifiers].doc = "Number of qualifiers. For internal DNX_DATA use only.";
    
    submodule_data->defines[dnx_data_field_base_ipmf3_define_nof_qualifiers].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_base_ipmf3_define_nof_bits_in_fes_action].name = "nof_bits_in_fes_action";
    submodule_data->defines[dnx_data_field_base_ipmf3_define_nof_bits_in_fes_action].doc = "Number of bits on the output of a FES. For internal DNX_DATA use only.";
    
    submodule_data->defines[dnx_data_field_base_ipmf3_define_nof_bits_in_fes_action].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_base_ipmf3_define_nof_bits_in_fes_key_select].name = "nof_bits_in_fes_key_select";
    submodule_data->defines[dnx_data_field_base_ipmf3_define_nof_bits_in_fes_key_select].doc = "Number of bits on input to FES. For internal DNX_DATA use only.";
    
    submodule_data->defines[dnx_data_field_base_ipmf3_define_nof_bits_in_fes_key_select].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_base_ipmf3_define_fes_key_select_resolution_in_bits].name = "fes_key_select_resolution_in_bits";
    submodule_data->defines[dnx_data_field_base_ipmf3_define_fes_key_select_resolution_in_bits].doc = "Number of bits on input to FES. For internal DNX_DATA use only.";
    
    submodule_data->defines[dnx_data_field_base_ipmf3_define_fes_key_select_resolution_in_bits].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_base_ipmf3_define_nof_out_lif_ranges].name = "nof_out_lif_ranges";
    submodule_data->defines[dnx_data_field_base_ipmf3_define_nof_out_lif_ranges].doc = "Number of ranges for Out Lif. For internal DNX_DATA use only.";
    
    submodule_data->defines[dnx_data_field_base_ipmf3_define_nof_out_lif_ranges].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_base_ipmf3_define_fes_instruction_size].name = "fes_instruction_size";
    submodule_data->defines[dnx_data_field_base_ipmf3_define_fes_instruction_size].doc = "Number of bits in one fes instruction.";
    
    submodule_data->defines[dnx_data_field_base_ipmf3_define_fes_instruction_size].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_base_ipmf3_define_fes_pgm_id_offset].name = "fes_pgm_id_offset";
    submodule_data->defines[dnx_data_field_base_ipmf3_define_fes_pgm_id_offset].doc = "FES Program ID offset pointing to IPPD_PMF_FES_PROGRAMm->FES_2ND_INSTRUCTION_LSB_ADDRESSf.";
    
    submodule_data->defines[dnx_data_field_base_ipmf3_define_fes_pgm_id_offset].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_base_ipmf3_define_dir_ext_single_key_size].name = "dir_ext_single_key_size";
    submodule_data->defines[dnx_data_field_base_ipmf3_define_dir_ext_single_key_size].doc = "Single key size used for Direct Extraction. For internal DNX_DATA use only.";
    
    submodule_data->defines[dnx_data_field_base_ipmf3_define_dir_ext_single_key_size].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_base_ipmf3_define_dir_ext_first_key].name = "dir_ext_first_key";
    submodule_data->defines[dnx_data_field_base_ipmf3_define_dir_ext_first_key].doc = "First key used for direct extraction. For internal DNX_DATA use only.";
    
    submodule_data->defines[dnx_data_field_base_ipmf3_define_dir_ext_first_key].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_base_ipmf3_define_exem_max_result_size].name = "exem_max_result_size";
    submodule_data->defines[dnx_data_field_base_ipmf3_define_exem_max_result_size].doc = "EXEM result (payload) size in bits, including VMV";
    
    submodule_data->defines[dnx_data_field_base_ipmf3_define_exem_max_result_size].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_base_ipmf3_define_nof_fes_used_by_sdk].name = "nof_fes_used_by_sdk";
    submodule_data->defines[dnx_data_field_base_ipmf3_define_nof_fes_used_by_sdk].doc = "nof fe used by sdk in ipmf3 can be changed per system header soc property";
    
    submodule_data->defines[dnx_data_field_base_ipmf3_define_nof_fes_used_by_sdk].flags |= DNXC_DATA_F_NUMERIC;

    submodule_data->defines[dnx_data_field_base_ipmf3_define_fes_key_select_for_zero_bit].name = "fes_key_select_for_zero_bit";
    submodule_data->defines[dnx_data_field_base_ipmf3_define_fes_key_select_for_zero_bit].doc = "The key select used for obtaining an always zero bit for input to FES (for example, using a zero padded bit). For internal DNX_DATA use only.";
    
    submodule_data->defines[dnx_data_field_base_ipmf3_define_fes_key_select_for_zero_bit].flags |= DNXC_DATA_F_NUMERIC;

    submodule_data->defines[dnx_data_field_base_ipmf3_define_fes_shift_for_zero_bit].name = "fes_shift_for_zero_bit";
    submodule_data->defines[dnx_data_field_base_ipmf3_define_fes_shift_for_zero_bit].doc = "The shift used for obtaining an always zero bit for input to FES (for example, using a zero padded bit). For internal DNX_DATA use only.";
    
    submodule_data->defines[dnx_data_field_base_ipmf3_define_fes_shift_for_zero_bit].flags |= DNXC_DATA_F_NUMERIC;

    submodule_data->defines[dnx_data_field_base_ipmf3_define_exem_pdb].name = "exem_pdb";
    submodule_data->defines[dnx_data_field_base_ipmf3_define_exem_pdb].doc = "EXEM physical database type in the form of dbal_physical_tables_e. For internal DNX_DATA use only.";
    
    submodule_data->defines[dnx_data_field_base_ipmf3_define_exem_pdb].flags |= DNXC_DATA_F_NUMERIC;

    
    submodule_data->nof_tables = _dnx_data_field_base_ipmf3_table_nof;
    DNXC_DATA_ALLOC(submodule_data->tables, dnxc_data_table_t, submodule_data->nof_tables, "_dnxc_data field base_ipmf3 tables");


exit:
    SHR_FUNC_EXIT;
}


int
dnx_data_field_base_ipmf3_feature_get(
    int unit,
    dnx_data_field_base_ipmf3_feature_e feature)
{
    return dnxc_data_mgmt_feature_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_ipmf3, feature);
}


uint32
dnx_data_field_base_ipmf3_nof_ffc_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_ipmf3, dnx_data_field_base_ipmf3_define_nof_ffc);
}

uint32
dnx_data_field_base_ipmf3_nof_keys_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_ipmf3, dnx_data_field_base_ipmf3_define_nof_keys);
}

uint32
dnx_data_field_base_ipmf3_nof_keys_alloc_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_ipmf3, dnx_data_field_base_ipmf3_define_nof_keys_alloc);
}

uint32
dnx_data_field_base_ipmf3_nof_keys_alloc_for_tcam_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_ipmf3, dnx_data_field_base_ipmf3_define_nof_keys_alloc_for_tcam);
}

uint32
dnx_data_field_base_ipmf3_nof_keys_alloc_for_exem_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_ipmf3, dnx_data_field_base_ipmf3_define_nof_keys_alloc_for_exem);
}

uint32
dnx_data_field_base_ipmf3_nof_keys_alloc_for_dir_ext_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_ipmf3, dnx_data_field_base_ipmf3_define_nof_keys_alloc_for_dir_ext);
}

uint32
dnx_data_field_base_ipmf3_nof_keys_alloc_for_mdb_dt_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_ipmf3, dnx_data_field_base_ipmf3_define_nof_keys_alloc_for_mdb_dt);
}

uint32
dnx_data_field_base_ipmf3_nof_masks_per_fes_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_ipmf3, dnx_data_field_base_ipmf3_define_nof_masks_per_fes);
}

uint32
dnx_data_field_base_ipmf3_nof_fes_id_per_array_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_ipmf3, dnx_data_field_base_ipmf3_define_nof_fes_id_per_array);
}

uint32
dnx_data_field_base_ipmf3_nof_fes_array_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_ipmf3, dnx_data_field_base_ipmf3_define_nof_fes_array);
}

uint32
dnx_data_field_base_ipmf3_nof_fes_instruction_per_context_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_ipmf3, dnx_data_field_base_ipmf3_define_nof_fes_instruction_per_context);
}

uint32
dnx_data_field_base_ipmf3_nof_fes_programs_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_ipmf3, dnx_data_field_base_ipmf3_define_nof_fes_programs);
}

uint32
dnx_data_field_base_ipmf3_nof_prog_per_fes_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_ipmf3, dnx_data_field_base_ipmf3_define_nof_prog_per_fes);
}

uint32
dnx_data_field_base_ipmf3_cs_scratch_pad_size_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_ipmf3, dnx_data_field_base_ipmf3_define_cs_scratch_pad_size);
}

uint32
dnx_data_field_base_ipmf3_nof_contexts_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_ipmf3, dnx_data_field_base_ipmf3_define_nof_contexts);
}

uint32
dnx_data_field_base_ipmf3_nof_cs_lines_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_ipmf3, dnx_data_field_base_ipmf3_define_nof_cs_lines);
}

uint32
dnx_data_field_base_ipmf3_nof_actions_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_ipmf3, dnx_data_field_base_ipmf3_define_nof_actions);
}

uint32
dnx_data_field_base_ipmf3_nof_qualifiers_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_ipmf3, dnx_data_field_base_ipmf3_define_nof_qualifiers);
}

uint32
dnx_data_field_base_ipmf3_nof_bits_in_fes_action_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_ipmf3, dnx_data_field_base_ipmf3_define_nof_bits_in_fes_action);
}

uint32
dnx_data_field_base_ipmf3_nof_bits_in_fes_key_select_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_ipmf3, dnx_data_field_base_ipmf3_define_nof_bits_in_fes_key_select);
}

uint32
dnx_data_field_base_ipmf3_fes_key_select_resolution_in_bits_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_ipmf3, dnx_data_field_base_ipmf3_define_fes_key_select_resolution_in_bits);
}

uint32
dnx_data_field_base_ipmf3_nof_out_lif_ranges_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_ipmf3, dnx_data_field_base_ipmf3_define_nof_out_lif_ranges);
}

uint32
dnx_data_field_base_ipmf3_fes_instruction_size_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_ipmf3, dnx_data_field_base_ipmf3_define_fes_instruction_size);
}

uint32
dnx_data_field_base_ipmf3_fes_pgm_id_offset_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_ipmf3, dnx_data_field_base_ipmf3_define_fes_pgm_id_offset);
}

uint32
dnx_data_field_base_ipmf3_dir_ext_single_key_size_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_ipmf3, dnx_data_field_base_ipmf3_define_dir_ext_single_key_size);
}

uint32
dnx_data_field_base_ipmf3_dir_ext_first_key_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_ipmf3, dnx_data_field_base_ipmf3_define_dir_ext_first_key);
}

uint32
dnx_data_field_base_ipmf3_exem_max_result_size_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_ipmf3, dnx_data_field_base_ipmf3_define_exem_max_result_size);
}

uint32
dnx_data_field_base_ipmf3_nof_fes_used_by_sdk_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_ipmf3, dnx_data_field_base_ipmf3_define_nof_fes_used_by_sdk);
}

uint32
dnx_data_field_base_ipmf3_fes_key_select_for_zero_bit_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_ipmf3, dnx_data_field_base_ipmf3_define_fes_key_select_for_zero_bit);
}

uint32
dnx_data_field_base_ipmf3_fes_shift_for_zero_bit_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_ipmf3, dnx_data_field_base_ipmf3_define_fes_shift_for_zero_bit);
}

uint32
dnx_data_field_base_ipmf3_exem_pdb_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_ipmf3, dnx_data_field_base_ipmf3_define_exem_pdb);
}










static shr_error_e
dnx_data_field_base_epmf_init(
    int unit,
    dnxc_data_submodule_t *submodule_data)
{
    SHR_FUNC_INIT_VARS(unit);

    submodule_data->name = "base_epmf";
    submodule_data->doc = "Egress PMF data. For internal DNX DATA use only. Use stage submodule instead.";
    
    submodule_data->nof_features = _dnx_data_field_base_epmf_feature_nof;
    DNXC_DATA_ALLOC(submodule_data->features, dnxc_data_feature_t,  submodule_data->nof_features, "_dnxc_data field base_epmf features");

    
    submodule_data->nof_defines = _dnx_data_field_base_epmf_define_nof;
    DNXC_DATA_ALLOC(submodule_data->defines, dnxc_data_define_t, submodule_data->nof_defines, "_dnxc_data field base_epmf defines");

    submodule_data->defines[dnx_data_field_base_epmf_define_nof_ffc].name = "nof_ffc";
    submodule_data->defines[dnx_data_field_base_epmf_define_nof_ffc].doc = "Number of FFC's. For internal DNX_DATA use only.";
    
    submodule_data->defines[dnx_data_field_base_epmf_define_nof_ffc].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_base_epmf_define_nof_keys].name = "nof_keys";
    submodule_data->defines[dnx_data_field_base_epmf_define_nof_keys].doc = "Number of keys for the this PMF stage. For internal DNX_DATA use only.";
    
    submodule_data->defines[dnx_data_field_base_epmf_define_nof_keys].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_base_epmf_define_nof_keys_alloc].name = "nof_keys_alloc";
    submodule_data->defines[dnx_data_field_base_epmf_define_nof_keys_alloc].doc = "Number of keys available for allocation for use by this specific PMF stage. For internal DNX_DATA use only.";
    
    submodule_data->defines[dnx_data_field_base_epmf_define_nof_keys_alloc].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_base_epmf_define_nof_keys_alloc_for_tcam].name = "nof_keys_alloc_for_tcam";
    submodule_data->defines[dnx_data_field_base_epmf_define_nof_keys_alloc_for_tcam].doc = "Number of keys available for allocation for use by this specific PMF stage for TCAM access. For internal DNX_DATA use only.";
    
    submodule_data->defines[dnx_data_field_base_epmf_define_nof_keys_alloc_for_tcam].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_base_epmf_define_nof_keys_alloc_for_exem].name = "nof_keys_alloc_for_exem";
    submodule_data->defines[dnx_data_field_base_epmf_define_nof_keys_alloc_for_exem].doc = "Number of keys available for allocation for use by this specific PMF stage for EXEM access. For internal DNX_DATA use only.";
    
    submodule_data->defines[dnx_data_field_base_epmf_define_nof_keys_alloc_for_exem].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_base_epmf_define_nof_keys_alloc_for_dir_ext].name = "nof_keys_alloc_for_dir_ext";
    submodule_data->defines[dnx_data_field_base_epmf_define_nof_keys_alloc_for_dir_ext].doc = "Number of keys available for allocation for use by this specific PMF stage for DIRECT EXTRACTION. For internal DNX_DATA use only.";
    
    submodule_data->defines[dnx_data_field_base_epmf_define_nof_keys_alloc_for_dir_ext].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_base_epmf_define_nof_masks_per_fes].name = "nof_masks_per_fes";
    submodule_data->defines[dnx_data_field_base_epmf_define_nof_masks_per_fes].doc = "Number of masks per FES. For internal DNX_DATA use only.";
    
    submodule_data->defines[dnx_data_field_base_epmf_define_nof_masks_per_fes].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_base_epmf_define_nof_fes_id_per_array].name = "nof_fes_id_per_array";
    submodule_data->defines[dnx_data_field_base_epmf_define_nof_fes_id_per_array].doc = "Number FESes in each FES array. For internal DNX_DATA use only.";
    
    submodule_data->defines[dnx_data_field_base_epmf_define_nof_fes_id_per_array].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_base_epmf_define_nof_fes_array].name = "nof_fes_array";
    submodule_data->defines[dnx_data_field_base_epmf_define_nof_fes_array].doc = "Number FES arrays. For internal DNX_DATA use only.";
    
    submodule_data->defines[dnx_data_field_base_epmf_define_nof_fes_array].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_base_epmf_define_nof_fes_instruction_per_context].name = "nof_fes_instruction_per_context";
    submodule_data->defines[dnx_data_field_base_epmf_define_nof_fes_instruction_per_context].doc = "Number of FES INSTRUCTIONs per context. For internal DNX_DATA use only.";
    
    submodule_data->defines[dnx_data_field_base_epmf_define_nof_fes_instruction_per_context].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_base_epmf_define_nof_fes_programs].name = "nof_fes_programs";
    submodule_data->defines[dnx_data_field_base_epmf_define_nof_fes_programs].doc = "Number of FES programs. For internal DNX_DATA use only.";
    
    submodule_data->defines[dnx_data_field_base_epmf_define_nof_fes_programs].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_base_epmf_define_nof_prog_per_fes].name = "nof_prog_per_fes";
    submodule_data->defines[dnx_data_field_base_epmf_define_nof_prog_per_fes].doc = "Number of MS bits instruction programs per FES. For internal DNX_DATA use only.";
    
    submodule_data->defines[dnx_data_field_base_epmf_define_nof_prog_per_fes].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_base_epmf_define_nof_cs_lines].name = "nof_cs_lines";
    submodule_data->defines[dnx_data_field_base_epmf_define_nof_cs_lines].doc = "Number of program selection lines. For internal DNX_DATA use only.";
    
    submodule_data->defines[dnx_data_field_base_epmf_define_nof_cs_lines].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_base_epmf_define_nof_contexts].name = "nof_contexts";
    submodule_data->defines[dnx_data_field_base_epmf_define_nof_contexts].doc = "Number of Egress contexts. For internal DNX_DATA use only.";
    
    submodule_data->defines[dnx_data_field_base_epmf_define_nof_contexts].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_base_epmf_define_nof_actions].name = "nof_actions";
    submodule_data->defines[dnx_data_field_base_epmf_define_nof_actions].doc = "Number of actions. For internal DNX_DATA use only.";
    
    submodule_data->defines[dnx_data_field_base_epmf_define_nof_actions].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_base_epmf_define_nof_qualifiers].name = "nof_qualifiers";
    submodule_data->defines[dnx_data_field_base_epmf_define_nof_qualifiers].doc = "Number of qualifiers. For internal DNX_DATA use only.";
    
    submodule_data->defines[dnx_data_field_base_epmf_define_nof_qualifiers].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_base_epmf_define_nof_bits_in_fes_action].name = "nof_bits_in_fes_action";
    submodule_data->defines[dnx_data_field_base_epmf_define_nof_bits_in_fes_action].doc = "Number of bits on the output of a FES. For internal DNX_DATA use only.";
    
    submodule_data->defines[dnx_data_field_base_epmf_define_nof_bits_in_fes_action].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_base_epmf_define_nof_bits_in_fes_key_select].name = "nof_bits_in_fes_key_select";
    submodule_data->defines[dnx_data_field_base_epmf_define_nof_bits_in_fes_key_select].doc = "Number of bits on input to FES. For internal DNX_DATA use only.";
    
    submodule_data->defines[dnx_data_field_base_epmf_define_nof_bits_in_fes_key_select].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_base_epmf_define_fes_key_select_resolution_in_bits].name = "fes_key_select_resolution_in_bits";
    submodule_data->defines[dnx_data_field_base_epmf_define_fes_key_select_resolution_in_bits].doc = "Number of bits on input to FES. For internal DNX_DATA use only.";
    
    submodule_data->defines[dnx_data_field_base_epmf_define_fes_key_select_resolution_in_bits].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_base_epmf_define_nof_l4_ops_ranges_legacy].name = "nof_l4_ops_ranges_legacy";
    submodule_data->defines[dnx_data_field_base_epmf_define_nof_l4_ops_ranges_legacy].doc = "Number of ranges for L4 Ops legacy. For internal DNX_DATA use only.";
    
    submodule_data->defines[dnx_data_field_base_epmf_define_nof_l4_ops_ranges_legacy].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_base_epmf_define_fes_instruction_size].name = "fes_instruction_size";
    submodule_data->defines[dnx_data_field_base_epmf_define_fes_instruction_size].doc = "Number of bits in one fes instruction.";
    
    submodule_data->defines[dnx_data_field_base_epmf_define_fes_instruction_size].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_base_epmf_define_fes_pgm_id_offset].name = "fes_pgm_id_offset";
    submodule_data->defines[dnx_data_field_base_epmf_define_fes_pgm_id_offset].doc = "FES Program ID offset pointing to ERPP_PMF_FES_PROGRAMmm->FES_2ND_INSTRUCTION_LSB_ADDRESSf.";
    
    submodule_data->defines[dnx_data_field_base_epmf_define_fes_pgm_id_offset].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_base_epmf_define_dir_ext_single_key_size].name = "dir_ext_single_key_size";
    submodule_data->defines[dnx_data_field_base_epmf_define_dir_ext_single_key_size].doc = "Single key size used for Direct Extraction. For internal DNX_DATA use only.";
    
    submodule_data->defines[dnx_data_field_base_epmf_define_dir_ext_single_key_size].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_base_epmf_define_dir_ext_first_key].name = "dir_ext_first_key";
    submodule_data->defines[dnx_data_field_base_epmf_define_dir_ext_first_key].doc = "First key used for direct extraction. For internal DNX_DATA use only.";
    
    submodule_data->defines[dnx_data_field_base_epmf_define_dir_ext_first_key].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_base_epmf_define_exem_max_result_size].name = "exem_max_result_size";
    submodule_data->defines[dnx_data_field_base_epmf_define_exem_max_result_size].doc = "EXEM result (payload) size in bits, including VMV";
    
    submodule_data->defines[dnx_data_field_base_epmf_define_exem_max_result_size].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_base_epmf_define_fes_key_select_for_zero_bit].name = "fes_key_select_for_zero_bit";
    submodule_data->defines[dnx_data_field_base_epmf_define_fes_key_select_for_zero_bit].doc = "The key select used for obtaining an always zero bit for input to FES (for example, using a zero padded bit). For internal DNX_DATA use only.";
    
    submodule_data->defines[dnx_data_field_base_epmf_define_fes_key_select_for_zero_bit].flags |= DNXC_DATA_F_NUMERIC;

    submodule_data->defines[dnx_data_field_base_epmf_define_fes_shift_for_zero_bit].name = "fes_shift_for_zero_bit";
    submodule_data->defines[dnx_data_field_base_epmf_define_fes_shift_for_zero_bit].doc = "The shift used for obtaining an always zero bit for input to FES (for example, using a zero padded bit). For internal DNX_DATA use only.";
    
    submodule_data->defines[dnx_data_field_base_epmf_define_fes_shift_for_zero_bit].flags |= DNXC_DATA_F_NUMERIC;

    submodule_data->defines[dnx_data_field_base_epmf_define_exem_pdb].name = "exem_pdb";
    submodule_data->defines[dnx_data_field_base_epmf_define_exem_pdb].doc = "EXEM physical database type in the form of dbal_physical_tables_e. For internal DNX_DATA use only.";
    
    submodule_data->defines[dnx_data_field_base_epmf_define_exem_pdb].flags |= DNXC_DATA_F_NUMERIC;

    
    submodule_data->nof_tables = _dnx_data_field_base_epmf_table_nof;
    DNXC_DATA_ALLOC(submodule_data->tables, dnxc_data_table_t, submodule_data->nof_tables, "_dnxc_data field base_epmf tables");


exit:
    SHR_FUNC_EXIT;
}


int
dnx_data_field_base_epmf_feature_get(
    int unit,
    dnx_data_field_base_epmf_feature_e feature)
{
    return dnxc_data_mgmt_feature_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_epmf, feature);
}


uint32
dnx_data_field_base_epmf_nof_ffc_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_epmf, dnx_data_field_base_epmf_define_nof_ffc);
}

uint32
dnx_data_field_base_epmf_nof_keys_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_epmf, dnx_data_field_base_epmf_define_nof_keys);
}

uint32
dnx_data_field_base_epmf_nof_keys_alloc_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_epmf, dnx_data_field_base_epmf_define_nof_keys_alloc);
}

uint32
dnx_data_field_base_epmf_nof_keys_alloc_for_tcam_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_epmf, dnx_data_field_base_epmf_define_nof_keys_alloc_for_tcam);
}

uint32
dnx_data_field_base_epmf_nof_keys_alloc_for_exem_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_epmf, dnx_data_field_base_epmf_define_nof_keys_alloc_for_exem);
}

uint32
dnx_data_field_base_epmf_nof_keys_alloc_for_dir_ext_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_epmf, dnx_data_field_base_epmf_define_nof_keys_alloc_for_dir_ext);
}

uint32
dnx_data_field_base_epmf_nof_masks_per_fes_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_epmf, dnx_data_field_base_epmf_define_nof_masks_per_fes);
}

uint32
dnx_data_field_base_epmf_nof_fes_id_per_array_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_epmf, dnx_data_field_base_epmf_define_nof_fes_id_per_array);
}

uint32
dnx_data_field_base_epmf_nof_fes_array_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_epmf, dnx_data_field_base_epmf_define_nof_fes_array);
}

uint32
dnx_data_field_base_epmf_nof_fes_instruction_per_context_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_epmf, dnx_data_field_base_epmf_define_nof_fes_instruction_per_context);
}

uint32
dnx_data_field_base_epmf_nof_fes_programs_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_epmf, dnx_data_field_base_epmf_define_nof_fes_programs);
}

uint32
dnx_data_field_base_epmf_nof_prog_per_fes_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_epmf, dnx_data_field_base_epmf_define_nof_prog_per_fes);
}

uint32
dnx_data_field_base_epmf_nof_cs_lines_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_epmf, dnx_data_field_base_epmf_define_nof_cs_lines);
}

uint32
dnx_data_field_base_epmf_nof_contexts_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_epmf, dnx_data_field_base_epmf_define_nof_contexts);
}

uint32
dnx_data_field_base_epmf_nof_actions_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_epmf, dnx_data_field_base_epmf_define_nof_actions);
}

uint32
dnx_data_field_base_epmf_nof_qualifiers_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_epmf, dnx_data_field_base_epmf_define_nof_qualifiers);
}

uint32
dnx_data_field_base_epmf_nof_bits_in_fes_action_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_epmf, dnx_data_field_base_epmf_define_nof_bits_in_fes_action);
}

uint32
dnx_data_field_base_epmf_nof_bits_in_fes_key_select_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_epmf, dnx_data_field_base_epmf_define_nof_bits_in_fes_key_select);
}

uint32
dnx_data_field_base_epmf_fes_key_select_resolution_in_bits_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_epmf, dnx_data_field_base_epmf_define_fes_key_select_resolution_in_bits);
}

uint32
dnx_data_field_base_epmf_nof_l4_ops_ranges_legacy_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_epmf, dnx_data_field_base_epmf_define_nof_l4_ops_ranges_legacy);
}

uint32
dnx_data_field_base_epmf_fes_instruction_size_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_epmf, dnx_data_field_base_epmf_define_fes_instruction_size);
}

uint32
dnx_data_field_base_epmf_fes_pgm_id_offset_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_epmf, dnx_data_field_base_epmf_define_fes_pgm_id_offset);
}

uint32
dnx_data_field_base_epmf_dir_ext_single_key_size_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_epmf, dnx_data_field_base_epmf_define_dir_ext_single_key_size);
}

uint32
dnx_data_field_base_epmf_dir_ext_first_key_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_epmf, dnx_data_field_base_epmf_define_dir_ext_first_key);
}

uint32
dnx_data_field_base_epmf_exem_max_result_size_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_epmf, dnx_data_field_base_epmf_define_exem_max_result_size);
}

uint32
dnx_data_field_base_epmf_fes_key_select_for_zero_bit_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_epmf, dnx_data_field_base_epmf_define_fes_key_select_for_zero_bit);
}

uint32
dnx_data_field_base_epmf_fes_shift_for_zero_bit_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_epmf, dnx_data_field_base_epmf_define_fes_shift_for_zero_bit);
}

uint32
dnx_data_field_base_epmf_exem_pdb_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_epmf, dnx_data_field_base_epmf_define_exem_pdb);
}










static shr_error_e
dnx_data_field_base_ifwd2_init(
    int unit,
    dnxc_data_submodule_t *submodule_data)
{
    SHR_FUNC_INIT_VARS(unit);

    submodule_data->name = "base_ifwd2";
    submodule_data->doc = "IFWD2 data. For internal DNX DATA use only. Use stage submodule instead.";
    
    submodule_data->nof_features = _dnx_data_field_base_ifwd2_feature_nof;
    DNXC_DATA_ALLOC(submodule_data->features, dnxc_data_feature_t,  submodule_data->nof_features, "_dnxc_data field base_ifwd2 features");

    
    submodule_data->nof_defines = _dnx_data_field_base_ifwd2_define_nof;
    DNXC_DATA_ALLOC(submodule_data->defines, dnxc_data_define_t, submodule_data->nof_defines, "_dnxc_data field base_ifwd2 defines");

    submodule_data->defines[dnx_data_field_base_ifwd2_define_nof_ffc].name = "nof_ffc";
    submodule_data->defines[dnx_data_field_base_ifwd2_define_nof_ffc].doc = "Number of FFC's in this specific IFWD2 stage. For internal DNX_DATA use only.";
    
    submodule_data->defines[dnx_data_field_base_ifwd2_define_nof_ffc].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_base_ifwd2_define_nof_keys].name = "nof_keys";
    submodule_data->defines[dnx_data_field_base_ifwd2_define_nof_keys].doc = "Number of keys available for allocation for use by this specific IFWD2 stage. For internal DNX_DATA use only.";
    
    submodule_data->defines[dnx_data_field_base_ifwd2_define_nof_keys].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_base_ifwd2_define_nof_contexts].name = "nof_contexts";
    submodule_data->defines[dnx_data_field_base_ifwd2_define_nof_contexts].doc = "Number of KBP ACL contexts. For internal DNX_DATA use only.";
    
    submodule_data->defines[dnx_data_field_base_ifwd2_define_nof_contexts].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_base_ifwd2_define_nof_cs_lines].name = "nof_cs_lines";
    submodule_data->defines[dnx_data_field_base_ifwd2_define_nof_cs_lines].doc = "Number of program selection lines. For internal DNX_DATA use only.";
    
    submodule_data->defines[dnx_data_field_base_ifwd2_define_nof_cs_lines].flags |= DNXC_DATA_F_DEFINE;

    
    submodule_data->nof_tables = _dnx_data_field_base_ifwd2_table_nof;
    DNXC_DATA_ALLOC(submodule_data->tables, dnxc_data_table_t, submodule_data->nof_tables, "_dnxc_data field base_ifwd2 tables");


exit:
    SHR_FUNC_EXIT;
}


int
dnx_data_field_base_ifwd2_feature_get(
    int unit,
    dnx_data_field_base_ifwd2_feature_e feature)
{
    return dnxc_data_mgmt_feature_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_ifwd2, feature);
}


uint32
dnx_data_field_base_ifwd2_nof_ffc_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_ifwd2, dnx_data_field_base_ifwd2_define_nof_ffc);
}

uint32
dnx_data_field_base_ifwd2_nof_keys_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_ifwd2, dnx_data_field_base_ifwd2_define_nof_keys);
}

uint32
dnx_data_field_base_ifwd2_nof_contexts_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_ifwd2, dnx_data_field_base_ifwd2_define_nof_contexts);
}

uint32
dnx_data_field_base_ifwd2_nof_cs_lines_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_base_ifwd2, dnx_data_field_base_ifwd2_define_nof_cs_lines);
}










static shr_error_e
dnx_data_field_stage_init(
    int unit,
    dnxc_data_submodule_t *submodule_data)
{
    SHR_FUNC_INIT_VARS(unit);

    submodule_data->name = "stage";
    submodule_data->doc = "Data regarding the field stages";
    
    submodule_data->nof_features = _dnx_data_field_stage_feature_nof;
    DNXC_DATA_ALLOC(submodule_data->features, dnxc_data_feature_t,  submodule_data->nof_features, "_dnxc_data field stage features");

    
    submodule_data->nof_defines = _dnx_data_field_stage_define_nof;
    DNXC_DATA_ALLOC(submodule_data->defines, dnxc_data_define_t, submodule_data->nof_defines, "_dnxc_data field stage defines");

    
    submodule_data->nof_tables = _dnx_data_field_stage_table_nof;
    DNXC_DATA_ALLOC(submodule_data->tables, dnxc_data_table_t, submodule_data->nof_tables, "_dnxc_data field stage tables");

    
    submodule_data->tables[dnx_data_field_stage_table_stage_info].name = "stage_info";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].doc = "Per stage information";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].flags |= DNXC_DATA_F_TABLE;
    submodule_data->tables[dnx_data_field_stage_table_stage_info].size_of_values = sizeof(dnx_data_field_stage_stage_info_t);
    submodule_data->tables[dnx_data_field_stage_table_stage_info].entry_get = dnx_data_field_stage_stage_info_entry_str_get;

    
    submodule_data->tables[dnx_data_field_stage_table_stage_info].nof_keys = 1;
    submodule_data->tables[dnx_data_field_stage_table_stage_info].keys[0].name = "stage";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].keys[0].doc = "Field stage enum";

    
    submodule_data->tables[dnx_data_field_stage_table_stage_info].nof_values = 59;
    DNXC_DATA_ALLOC(submodule_data->tables[dnx_data_field_stage_table_stage_info].values, dnxc_data_value_t, submodule_data->tables[dnx_data_field_stage_table_stage_info].nof_values, "_dnx_data_field_stage_table_stage_info table values");
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[0].name = "valid";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[0].type = "int";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[0].doc = "Whether the field_stage is supported on the device";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[0].offset = UTILEX_OFFSETOF(dnx_data_field_stage_stage_info_t, valid);
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[1].name = "nof_ffc";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[1].type = "int";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[1].doc = "Number of FFC's per context";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[1].offset = UTILEX_OFFSETOF(dnx_data_field_stage_stage_info_t, nof_ffc);
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[2].name = "nof_keys";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[2].type = "int";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[2].doc = "Number of keys for the this PMF stage";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[2].offset = UTILEX_OFFSETOF(dnx_data_field_stage_stage_info_t, nof_keys);
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[3].name = "nof_keys_alloc";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[3].type = "int";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[3].doc = "Number of keys available for allocation for use by this specific PMF stage";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[3].offset = UTILEX_OFFSETOF(dnx_data_field_stage_stage_info_t, nof_keys_alloc);
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[4].name = "nof_keys_alloc_for_tcam";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[4].type = "int";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[4].doc = "Number of keys available for allocation for use by this specific PMF stage for TCAM access";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[4].offset = UTILEX_OFFSETOF(dnx_data_field_stage_stage_info_t, nof_keys_alloc_for_tcam);
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[5].name = "nof_keys_alloc_for_exem";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[5].type = "int";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[5].doc = "Number of keys available for allocation for use by this specific PMF stage for EXEM access";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[5].offset = UTILEX_OFFSETOF(dnx_data_field_stage_stage_info_t, nof_keys_alloc_for_exem);
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[6].name = "nof_keys_alloc_for_dir_ext";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[6].type = "int";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[6].doc = "Number of keys available for allocation for use by this specific PMF stage for DIRECT EXTRACTION";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[6].offset = UTILEX_OFFSETOF(dnx_data_field_stage_stage_info_t, nof_keys_alloc_for_dir_ext);
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[7].name = "nof_keys_alloc_for_mdb_dt";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[7].type = "int";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[7].doc = "Number of keys available for allocation for use by this specific PMF stage for Direct Table MDB access";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[7].offset = UTILEX_OFFSETOF(dnx_data_field_stage_stage_info_t, nof_keys_alloc_for_mdb_dt);
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[8].name = "nof_masks_per_fes";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[8].type = "int";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[8].doc = "Number of masks per FES";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[8].offset = UTILEX_OFFSETOF(dnx_data_field_stage_stage_info_t, nof_masks_per_fes);
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[9].name = "nof_fes_id_per_array";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[9].type = "int";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[9].doc = "Number FESes in each FES array";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[9].offset = UTILEX_OFFSETOF(dnx_data_field_stage_stage_info_t, nof_fes_id_per_array);
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[10].name = "nof_fes_array";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[10].type = "int";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[10].doc = "Number of FES arrays";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[10].offset = UTILEX_OFFSETOF(dnx_data_field_stage_stage_info_t, nof_fes_array);
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[11].name = "nof_fes_instruction_per_context";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[11].type = "int";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[11].doc = "Number of FES INSTRUCTIONs per context";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[11].offset = UTILEX_OFFSETOF(dnx_data_field_stage_stage_info_t, nof_fes_instruction_per_context);
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[12].name = "nof_fes_programs";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[12].type = "int";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[12].doc = "Number of FES programs";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[12].offset = UTILEX_OFFSETOF(dnx_data_field_stage_stage_info_t, nof_fes_programs);
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[13].name = "nof_prog_per_fes";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[13].type = "int";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[13].doc = "Number of MS bits instruction programs per FES";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[13].offset = UTILEX_OFFSETOF(dnx_data_field_stage_stage_info_t, nof_prog_per_fes);
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[14].name = "cs_scratch_pad_size";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[14].type = "int";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[14].doc = "Number of bits taken from general data for context selection.";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[14].offset = UTILEX_OFFSETOF(dnx_data_field_stage_stage_info_t, cs_scratch_pad_size);
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[15].name = "cs_container_5_selected_bits_size";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[15].type = "int";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[15].doc = "Number of bits taken from general data for context selection.";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[15].offset = UTILEX_OFFSETOF(dnx_data_field_stage_stage_info_t, cs_container_5_selected_bits_size);
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[16].name = "nof_contexts";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[16].type = "int";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[16].doc = "Number of Ingress PMF_A programs (contexts)";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[16].offset = UTILEX_OFFSETOF(dnx_data_field_stage_stage_info_t, nof_contexts);
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[17].name = "nof_link_profiles";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[17].type = "int";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[17].doc = "Number of profiles assigned to iPMF1 contexts in order to create links between iPMF1 and iPMF2 contexts";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[17].offset = UTILEX_OFFSETOF(dnx_data_field_stage_stage_info_t, nof_link_profiles);
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[18].name = "nof_cs_lines";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[18].type = "int";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[18].doc = "Number of program selection lines";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[18].offset = UTILEX_OFFSETOF(dnx_data_field_stage_stage_info_t, nof_cs_lines);
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[19].name = "nof_actions";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[19].type = "int";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[19].doc = "Number of actions";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[19].offset = UTILEX_OFFSETOF(dnx_data_field_stage_stage_info_t, nof_actions);
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[20].name = "nof_qualifiers";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[20].type = "int";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[20].doc = "Number of qualifiers";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[20].offset = UTILEX_OFFSETOF(dnx_data_field_stage_stage_info_t, nof_qualifiers);
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[21].name = "nof_bits_in_fes_action";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[21].type = "int";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[21].doc = "Number of bits on the output of a FES.";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[21].offset = UTILEX_OFFSETOF(dnx_data_field_stage_stage_info_t, nof_bits_in_fes_action);
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[22].name = "nof_bits_in_fes_key_select";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[22].type = "int";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[22].doc = "Number of bits on input to FES.";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[22].offset = UTILEX_OFFSETOF(dnx_data_field_stage_stage_info_t, nof_bits_in_fes_key_select);
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[23].name = "fes_key_select_resolution_in_bits";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[23].type = "int";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[23].doc = "Number of bits on input to FES.";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[23].offset = UTILEX_OFFSETOF(dnx_data_field_stage_stage_info_t, fes_key_select_resolution_in_bits);
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[24].name = "fem_condition_ms_bit_min_value";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[24].type = "int";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[24].doc = "The minumum legal value to be set in bit select for a FEM.";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[24].offset = UTILEX_OFFSETOF(dnx_data_field_stage_stage_info_t, fem_condition_ms_bit_min_value);
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[25].name = "nof_fem_programs";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[25].type = "int";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[25].doc = "Total number FEM programs available.";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[25].offset = UTILEX_OFFSETOF(dnx_data_field_stage_stage_info_t, nof_fem_programs);
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[26].name = "log_nof_bits_in_fem_key_select";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[26].type = "int";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[26].doc = "Log2 of number of bits on one 'chunk' of input to FEM.";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[26].offset = UTILEX_OFFSETOF(dnx_data_field_stage_stage_info_t, log_nof_bits_in_fem_key_select);
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[27].name = "nof_bits_in_fem_key_select";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[27].type = "int";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[27].doc = "Number of bits on one 'chunk' of input to FEM.";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[27].offset = UTILEX_OFFSETOF(dnx_data_field_stage_stage_info_t, nof_bits_in_fem_key_select);
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[28].name = "fem_key_select_resolution_in_bits";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[28].type = "int";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[28].doc = "Number of bits in the 'step' from one 'key select' to the following. See dbal_enum_value_field_field_pmf_a_fem_key_select_e.";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[28].offset = UTILEX_OFFSETOF(dnx_data_field_stage_stage_info_t, fem_key_select_resolution_in_bits);
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[29].name = "log_nof_bits_in_fem_map_data_field";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[29].type = "int";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[29].doc = "Log2 of number of bits on MAP_DATA field in IPPC_FEM_MAP_INDEX_TABLE (See FIELD_PMF_A_FEM_MAP_INDEX dbal table).";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[29].offset = UTILEX_OFFSETOF(dnx_data_field_stage_stage_info_t, log_nof_bits_in_fem_map_data_field);
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[30].name = "nof_bits_in_fem_map_data_field";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[30].type = "int";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[30].doc = "Number of bits on MAP_DATA field in IPPC_FEM_MAP_INDEX_TABLE (See FIELD_PMF_A_FEM_MAP_INDEX dbal table).";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[30].offset = UTILEX_OFFSETOF(dnx_data_field_stage_stage_info_t, nof_bits_in_fem_map_data_field);
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[31].name = "nof_bits_in_fem_action_fems_2_15";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[31].type = "int";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[31].doc = "Number of bits on action value in IPPC_FEM_*_24B_MAP_TABLE.";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[31].offset = UTILEX_OFFSETOF(dnx_data_field_stage_stage_info_t, nof_bits_in_fem_action_fems_2_15);
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[32].name = "nof_bits_in_fem_action_fems_0_1";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[32].type = "int";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[32].doc = "Number of bits on action value in IPPC_FEM_*_4B_MAP_TABLE.";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[32].offset = UTILEX_OFFSETOF(dnx_data_field_stage_stage_info_t, nof_bits_in_fem_action_fems_0_1);
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[33].name = "nof_bits_in_fem_action";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[33].type = "int";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[33].doc = "Maximal number of bits on action value in IPPC_FEM_*_*_MAP_TABLE.";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[33].offset = UTILEX_OFFSETOF(dnx_data_field_stage_stage_info_t, nof_bits_in_fem_action);
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[34].name = "nof_fem_condition";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[34].type = "int";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[34].doc = "Total number of fem conditions. This is the number of conditions that may be assigned to each (fem_id,fem_program) combination.";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[34].offset = UTILEX_OFFSETOF(dnx_data_field_stage_stage_info_t, nof_fem_condition);
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[35].name = "nof_fem_map_index";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[35].type = "int";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[35].doc = "Total number fem map indices. This represents the number of actions that may be assigned to each condition.";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[35].offset = UTILEX_OFFSETOF(dnx_data_field_stage_stage_info_t, nof_fem_map_index);
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[36].name = "nof_fem_id";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[36].type = "int";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[36].doc = "Total number 'FEM id's available.";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[36].offset = UTILEX_OFFSETOF(dnx_data_field_stage_stage_info_t, nof_fem_id);
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[37].name = "num_fems_with_short_action";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[37].type = "int";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[37].doc = "Number of FEMs, starting from 'fem_id=0', which have only 4 bits on action value. The rest have 24 bits on action value";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[37].offset = UTILEX_OFFSETOF(dnx_data_field_stage_stage_info_t, num_fems_with_short_action);
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[38].name = "num_bits_in_fem_field_select";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[38].type = "int";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[38].doc = "Number of bits on each of the HW field marked FIELD_SELECT_MAP_*";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[38].offset = UTILEX_OFFSETOF(dnx_data_field_stage_stage_info_t, num_bits_in_fem_field_select);
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[39].name = "nof_fem_id_per_array";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[39].type = "int";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[39].doc = "Number of FEMs in each FEM array";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[39].offset = UTILEX_OFFSETOF(dnx_data_field_stage_stage_info_t, nof_fem_id_per_array);
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[40].name = "nof_fem_array";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[40].type = "int";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[40].doc = "Number of FEM arrays";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[40].offset = UTILEX_OFFSETOF(dnx_data_field_stage_stage_info_t, nof_fem_array);
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[41].name = "pbus_header_length";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[41].type = "int";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[41].doc = "Number of bits reserved in Ingress PBUS for header";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[41].offset = UTILEX_OFFSETOF(dnx_data_field_stage_stage_info_t, pbus_header_length);
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[42].name = "nof_layer_records";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[42].type = "int";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[42].doc = "Number of layer records taken from the parser.";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[42].offset = UTILEX_OFFSETOF(dnx_data_field_stage_stage_info_t, nof_layer_records);
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[43].name = "layer_record_size";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[43].type = "int";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[43].doc = "Number of bits in each layer record.";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[43].offset = UTILEX_OFFSETOF(dnx_data_field_stage_stage_info_t, layer_record_size);
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[44].name = "nof_compare_pairs_in_compare_mode";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[44].type = "int";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[44].doc = "Number compare pairs in compare mode";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[44].offset = UTILEX_OFFSETOF(dnx_data_field_stage_stage_info_t, nof_compare_pairs_in_compare_mode);
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[45].name = "compare_key_size";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[45].type = "int";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[45].doc = "Size of the compare key in the system";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[45].offset = UTILEX_OFFSETOF(dnx_data_field_stage_stage_info_t, compare_key_size);
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[46].name = "nof_l4_ops_ranges_legacy";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[46].type = "int";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[46].doc = "Number of ranges for L4 Ops legacy";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[46].offset = UTILEX_OFFSETOF(dnx_data_field_stage_stage_info_t, nof_l4_ops_ranges_legacy);
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[47].name = "nof_ext_l4_ops_ranges";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[47].type = "int";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[47].doc = "Number of ranges for Extended L4 Ops";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[47].offset = UTILEX_OFFSETOF(dnx_data_field_stage_stage_info_t, nof_ext_l4_ops_ranges);
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[48].name = "nof_pkt_hdr_ranges";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[48].type = "int";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[48].doc = "Number of ranges for PKT HDR";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[48].offset = UTILEX_OFFSETOF(dnx_data_field_stage_stage_info_t, nof_pkt_hdr_ranges);
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[49].name = "nof_out_lif_ranges";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[49].type = "int";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[49].doc = "Number of ranges for Out Lif";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[49].offset = UTILEX_OFFSETOF(dnx_data_field_stage_stage_info_t, nof_out_lif_ranges);
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[50].name = "fes_key_select_for_zero_bit";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[50].type = "int";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[50].doc = "The key select used for obtaining an always zero bit for input to FES (for example, using a zero padded bit).";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[50].offset = UTILEX_OFFSETOF(dnx_data_field_stage_stage_info_t, fes_key_select_for_zero_bit);
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[51].name = "fes_shift_for_zero_bit";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[51].type = "int";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[51].doc = "The shift used for obtaining an always zero bit for input to FES (for example, using a zero padded bit).";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[51].offset = UTILEX_OFFSETOF(dnx_data_field_stage_stage_info_t, fes_shift_for_zero_bit);
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[52].name = "cmp_selection";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[52].type = "int";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[52].doc = "Compare selection for both keys of 2nd compare, See the CMP_SELECTION field in IPPC_PMF_GENERAL register for additional information";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[52].offset = UTILEX_OFFSETOF(dnx_data_field_stage_stage_info_t, cmp_selection);
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[53].name = "nof_bits_main_pbus";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[53].type = "int";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[53].doc = "Number of bits in the main PBUS of the stage (the one used by METADATA qualifiers). Only iPMF2 uses the iPMF1 PBUs as it's main PBUS.";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[53].offset = UTILEX_OFFSETOF(dnx_data_field_stage_stage_info_t, nof_bits_main_pbus);
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[54].name = "nof_bits_native_pbus";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[54].type = "int";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[54].doc = "Number of bits in the native PBUS of the stage, if it is different from the main PBUS. Only iPMF2 has a separate native PBUS.";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[54].offset = UTILEX_OFFSETOF(dnx_data_field_stage_stage_info_t, nof_bits_native_pbus);
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[55].name = "dir_ext_single_key_size";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[55].type = "int";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[55].doc = "Single key size used for Direct Extraction.";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[55].offset = UTILEX_OFFSETOF(dnx_data_field_stage_stage_info_t, dir_ext_single_key_size);
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[56].name = "dir_ext_first_key";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[56].type = "int";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[56].doc = "First key used for direct extraction.";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[56].offset = UTILEX_OFFSETOF(dnx_data_field_stage_stage_info_t, dir_ext_first_key);
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[57].name = "exem_max_result_size";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[57].type = "int";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[57].doc = "EXEM result (payload) size in bits, including VMV";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[57].offset = UTILEX_OFFSETOF(dnx_data_field_stage_stage_info_t, exem_max_result_size);
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[58].name = "exem_pdb";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[58].type = "int";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[58].doc = "EXEM physical database type in the form of dbal_physical_tables_e.";
    submodule_data->tables[dnx_data_field_stage_table_stage_info].values[58].offset = UTILEX_OFFSETOF(dnx_data_field_stage_stage_info_t, exem_pdb);


exit:
    SHR_FUNC_EXIT;
}


int
dnx_data_field_stage_feature_get(
    int unit,
    dnx_data_field_stage_feature_e feature)
{
    return dnxc_data_mgmt_feature_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_stage, feature);
}




const dnx_data_field_stage_stage_info_t *
dnx_data_field_stage_stage_info_get(
    int unit,
    int stage)
{
    char *data;
    dnxc_data_table_t *table;

    
    table = dnxc_data_mgmt_table_get(unit, dnx_data_module_field, dnx_data_field_submodule_stage, dnx_data_field_stage_table_stage_info);
    
    data = dnxc_data_mgmt_table_data_get(unit, table, stage, 0);
    return (const dnx_data_field_stage_stage_info_t *) data;

}


shr_error_e
dnx_data_field_stage_stage_info_entry_str_get(
    int unit,
    char *buffer,
    int key0,
    int key1,
    int value_index)
{
    dnxc_data_table_t *table;
    const dnx_data_field_stage_stage_info_t *data;
    SHR_FUNC_INIT_VARS(unit);

    
    table = dnxc_data_mgmt_table_get(unit, dnx_data_module_field, dnx_data_field_submodule_stage, dnx_data_field_stage_table_stage_info);
    data = (const dnx_data_field_stage_stage_info_t *) dnxc_data_mgmt_table_data_diag_get(unit, table, key0, 0);
    switch (value_index)
    {
        case 0:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->valid);
            break;
        case 1:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->nof_ffc);
            break;
        case 2:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->nof_keys);
            break;
        case 3:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->nof_keys_alloc);
            break;
        case 4:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->nof_keys_alloc_for_tcam);
            break;
        case 5:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->nof_keys_alloc_for_exem);
            break;
        case 6:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->nof_keys_alloc_for_dir_ext);
            break;
        case 7:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->nof_keys_alloc_for_mdb_dt);
            break;
        case 8:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->nof_masks_per_fes);
            break;
        case 9:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->nof_fes_id_per_array);
            break;
        case 10:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->nof_fes_array);
            break;
        case 11:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->nof_fes_instruction_per_context);
            break;
        case 12:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->nof_fes_programs);
            break;
        case 13:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->nof_prog_per_fes);
            break;
        case 14:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->cs_scratch_pad_size);
            break;
        case 15:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->cs_container_5_selected_bits_size);
            break;
        case 16:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->nof_contexts);
            break;
        case 17:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->nof_link_profiles);
            break;
        case 18:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->nof_cs_lines);
            break;
        case 19:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->nof_actions);
            break;
        case 20:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->nof_qualifiers);
            break;
        case 21:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->nof_bits_in_fes_action);
            break;
        case 22:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->nof_bits_in_fes_key_select);
            break;
        case 23:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->fes_key_select_resolution_in_bits);
            break;
        case 24:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->fem_condition_ms_bit_min_value);
            break;
        case 25:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->nof_fem_programs);
            break;
        case 26:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->log_nof_bits_in_fem_key_select);
            break;
        case 27:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->nof_bits_in_fem_key_select);
            break;
        case 28:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->fem_key_select_resolution_in_bits);
            break;
        case 29:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->log_nof_bits_in_fem_map_data_field);
            break;
        case 30:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->nof_bits_in_fem_map_data_field);
            break;
        case 31:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->nof_bits_in_fem_action_fems_2_15);
            break;
        case 32:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->nof_bits_in_fem_action_fems_0_1);
            break;
        case 33:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->nof_bits_in_fem_action);
            break;
        case 34:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->nof_fem_condition);
            break;
        case 35:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->nof_fem_map_index);
            break;
        case 36:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->nof_fem_id);
            break;
        case 37:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->num_fems_with_short_action);
            break;
        case 38:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->num_bits_in_fem_field_select);
            break;
        case 39:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->nof_fem_id_per_array);
            break;
        case 40:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->nof_fem_array);
            break;
        case 41:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->pbus_header_length);
            break;
        case 42:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->nof_layer_records);
            break;
        case 43:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->layer_record_size);
            break;
        case 44:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->nof_compare_pairs_in_compare_mode);
            break;
        case 45:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->compare_key_size);
            break;
        case 46:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->nof_l4_ops_ranges_legacy);
            break;
        case 47:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->nof_ext_l4_ops_ranges);
            break;
        case 48:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->nof_pkt_hdr_ranges);
            break;
        case 49:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->nof_out_lif_ranges);
            break;
        case 50:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->fes_key_select_for_zero_bit);
            break;
        case 51:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->fes_shift_for_zero_bit);
            break;
        case 52:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->cmp_selection);
            break;
        case 53:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->nof_bits_main_pbus);
            break;
        case 54:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->nof_bits_native_pbus);
            break;
        case 55:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->dir_ext_single_key_size);
            break;
        case 56:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->dir_ext_first_key);
            break;
        case 57:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->exem_max_result_size);
            break;
        case 58:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->exem_pdb);
            break;
    }

    SHR_FUNC_EXIT;
}


const dnxc_data_table_info_t *
dnx_data_field_stage_stage_info_info_get(
    int unit)
{

    
    return dnxc_data_mgmt_table_info_get(unit, dnx_data_module_field, dnx_data_field_submodule_stage, dnx_data_field_stage_table_stage_info);

}






static shr_error_e
dnx_data_field_external_tcam_init(
    int unit,
    dnxc_data_submodule_t *submodule_data)
{
    SHR_FUNC_INIT_VARS(unit);

    submodule_data->name = "external_tcam";
    submodule_data->doc = "External TCAM data";
    
    submodule_data->nof_features = _dnx_data_field_external_tcam_feature_nof;
    DNXC_DATA_ALLOC(submodule_data->features, dnxc_data_feature_t,  submodule_data->nof_features, "_dnxc_data field external_tcam features");

    submodule_data->features[dnx_data_field_external_tcam_has_acl_context_profile_mapping].name = "has_acl_context_profile_mapping";
    submodule_data->features[dnx_data_field_external_tcam_has_acl_context_profile_mapping].doc = "Indicates if we have a profile for acl_context";
    submodule_data->features[dnx_data_field_external_tcam_has_acl_context_profile_mapping].flags |= DNXC_DATA_F_FEATURE;

    
    submodule_data->nof_defines = _dnx_data_field_external_tcam_define_nof;
    DNXC_DATA_ALLOC(submodule_data->defines, dnxc_data_define_t, submodule_data->nof_defines, "_dnxc_data field external_tcam defines");

    submodule_data->defines[dnx_data_field_external_tcam_define_max_single_key_size].name = "max_single_key_size";
    submodule_data->defines[dnx_data_field_external_tcam_define_max_single_key_size].doc = "Maximum single key size";
    
    submodule_data->defines[dnx_data_field_external_tcam_define_max_single_key_size].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_external_tcam_define_nof_acl_keys_master_max].name = "nof_acl_keys_master_max";
    submodule_data->defines[dnx_data_field_external_tcam_define_nof_acl_keys_master_max].doc = "The maximum number of keys that can be used by ACL (not FWD) in external TCAM for a single context";
    
    submodule_data->defines[dnx_data_field_external_tcam_define_nof_acl_keys_master_max].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_external_tcam_define_nof_acl_keys_fg_max].name = "nof_acl_keys_fg_max";
    submodule_data->defines[dnx_data_field_external_tcam_define_nof_acl_keys_fg_max].doc = "The maximum number of keys that can be used by ACL (not FWD) in external TCAM for a single field group";
    
    submodule_data->defines[dnx_data_field_external_tcam_define_nof_acl_keys_fg_max].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_external_tcam_define_nof_keys_total].name = "nof_keys_total";
    submodule_data->defines[dnx_data_field_external_tcam_define_nof_keys_total].doc = "The maximum number of keys that can be used in external TCAM. The number of ones in key_bmp.";
    
    submodule_data->defines[dnx_data_field_external_tcam_define_nof_keys_total].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_external_tcam_define_min_acl_nof_ffc].name = "min_acl_nof_ffc";
    submodule_data->defines[dnx_data_field_external_tcam_define_min_acl_nof_ffc].doc = "Minimum number of FFC's that should be allocated for each context for ACL purposes.";
    
    submodule_data->defines[dnx_data_field_external_tcam_define_min_acl_nof_ffc].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_external_tcam_define_max_fwd_context_num_for_one_apptype].name = "max_fwd_context_num_for_one_apptype";
    submodule_data->defines[dnx_data_field_external_tcam_define_max_fwd_context_num_for_one_apptype].doc = "Maximum number of fwd contexts that could be mapped to an apptype ";
    
    submodule_data->defines[dnx_data_field_external_tcam_define_max_fwd_context_num_for_one_apptype].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_external_tcam_define_max_acl_context_num].name = "max_acl_context_num";
    submodule_data->defines[dnx_data_field_external_tcam_define_max_acl_context_num].doc = "Maximum number of ACL contexts in the KBP ";
    
    submodule_data->defines[dnx_data_field_external_tcam_define_max_acl_context_num].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_external_tcam_define_size_apptype_profile_id].name = "size_apptype_profile_id";
    submodule_data->defines[dnx_data_field_external_tcam_define_size_apptype_profile_id].doc = "Size in bits of the apptype profile ID (based on iFED2 ACL context)";
    
    submodule_data->defines[dnx_data_field_external_tcam_define_size_apptype_profile_id].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_external_tcam_define_key_bmp].name = "key_bmp";
    submodule_data->defines[dnx_data_field_external_tcam_define_key_bmp].doc = "bitmap of the key IDs used by the KBP.";
    
    submodule_data->defines[dnx_data_field_external_tcam_define_key_bmp].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_external_tcam_define_apptype_user_1st].name = "apptype_user_1st";
    submodule_data->defines[dnx_data_field_external_tcam_define_apptype_user_1st].doc = "First User defined Apptype id to avoid overlapping with static ones";
    
    submodule_data->defines[dnx_data_field_external_tcam_define_apptype_user_1st].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_external_tcam_define_apptype_user_nof].name = "apptype_user_nof";
    submodule_data->defines[dnx_data_field_external_tcam_define_apptype_user_nof].doc = "Number of user Defined apptypes that can be created";
    
    submodule_data->defines[dnx_data_field_external_tcam_define_apptype_user_nof].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_external_tcam_define_max_payload_size_per_opcode].name = "max_payload_size_per_opcode";
    submodule_data->defines[dnx_data_field_external_tcam_define_max_payload_size_per_opcode].doc = "The total payload size of the external lookup in FWD";
    
    submodule_data->defines[dnx_data_field_external_tcam_define_max_payload_size_per_opcode].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_external_tcam_define_max_payload_size_per_opcode_epmf].name = "max_payload_size_per_opcode_epmf";
    submodule_data->defines[dnx_data_field_external_tcam_define_max_payload_size_per_opcode_epmf].doc = "The total payload size of the external lookup in ePMF";
    
    submodule_data->defines[dnx_data_field_external_tcam_define_max_payload_size_per_opcode_epmf].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_external_tcam_define_max_epmf_nof_lookups].name = "max_epmf_nof_lookups";
    submodule_data->defines[dnx_data_field_external_tcam_define_max_epmf_nof_lookups].doc = "Maximum number of external TCAM lookups possible in ePMF";
    
    submodule_data->defines[dnx_data_field_external_tcam_define_max_epmf_nof_lookups].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_external_tcam_define_nof_total_lookups].name = "nof_total_lookups";
    submodule_data->defines[dnx_data_field_external_tcam_define_nof_total_lookups].doc = "Number of lookups in both FWD and ePMF.";
    
    submodule_data->defines[dnx_data_field_external_tcam_define_nof_total_lookups].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_external_tcam_define_payload_offset_granularity].name = "payload_offset_granularity";
    submodule_data->defines[dnx_data_field_external_tcam_define_payload_offset_granularity].doc = "Granularity of the payload offset.";
    
    submodule_data->defines[dnx_data_field_external_tcam_define_payload_offset_granularity].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_external_tcam_define_type].name = "type";
    submodule_data->defines[dnx_data_field_external_tcam_define_type].doc = "What type of external TCAM the device uses.";
    
    submodule_data->defines[dnx_data_field_external_tcam_define_type].flags |= DNXC_DATA_F_NUMERIC;

    
    submodule_data->nof_tables = _dnx_data_field_external_tcam_table_nof;
    DNXC_DATA_ALLOC(submodule_data->tables, dnxc_data_table_t, submodule_data->nof_tables, "_dnxc_data field external_tcam tables");

    
    submodule_data->tables[dnx_data_field_external_tcam_table_ffc_to_quad_and_group_map].name = "ffc_to_quad_and_group_map";
    submodule_data->tables[dnx_data_field_external_tcam_table_ffc_to_quad_and_group_map].doc = "Mapping of the ffc id to its quad anad group";
    submodule_data->tables[dnx_data_field_external_tcam_table_ffc_to_quad_and_group_map].flags |= DNXC_DATA_F_TABLE;
    submodule_data->tables[dnx_data_field_external_tcam_table_ffc_to_quad_and_group_map].size_of_values = sizeof(dnx_data_field_external_tcam_ffc_to_quad_and_group_map_t);
    submodule_data->tables[dnx_data_field_external_tcam_table_ffc_to_quad_and_group_map].entry_get = dnx_data_field_external_tcam_ffc_to_quad_and_group_map_entry_str_get;

    
    submodule_data->tables[dnx_data_field_external_tcam_table_ffc_to_quad_and_group_map].nof_keys = 1;
    submodule_data->tables[dnx_data_field_external_tcam_table_ffc_to_quad_and_group_map].keys[0].name = "ffc_id";
    submodule_data->tables[dnx_data_field_external_tcam_table_ffc_to_quad_and_group_map].keys[0].doc = "Id of the required ffc";

    
    submodule_data->tables[dnx_data_field_external_tcam_table_ffc_to_quad_and_group_map].nof_values = 2;
    DNXC_DATA_ALLOC(submodule_data->tables[dnx_data_field_external_tcam_table_ffc_to_quad_and_group_map].values, dnxc_data_value_t, submodule_data->tables[dnx_data_field_external_tcam_table_ffc_to_quad_and_group_map].nof_values, "_dnx_data_field_external_tcam_table_ffc_to_quad_and_group_map table values");
    submodule_data->tables[dnx_data_field_external_tcam_table_ffc_to_quad_and_group_map].values[0].name = "quad_id";
    submodule_data->tables[dnx_data_field_external_tcam_table_ffc_to_quad_and_group_map].values[0].type = "uint32";
    submodule_data->tables[dnx_data_field_external_tcam_table_ffc_to_quad_and_group_map].values[0].doc = "Id of the relevant quad for the given ffc id";
    submodule_data->tables[dnx_data_field_external_tcam_table_ffc_to_quad_and_group_map].values[0].offset = UTILEX_OFFSETOF(dnx_data_field_external_tcam_ffc_to_quad_and_group_map_t, quad_id);
    submodule_data->tables[dnx_data_field_external_tcam_table_ffc_to_quad_and_group_map].values[1].name = "group_id";
    submodule_data->tables[dnx_data_field_external_tcam_table_ffc_to_quad_and_group_map].values[1].type = "uint32";
    submodule_data->tables[dnx_data_field_external_tcam_table_ffc_to_quad_and_group_map].values[1].doc = "Id of the relevant group for the given ffc id";
    submodule_data->tables[dnx_data_field_external_tcam_table_ffc_to_quad_and_group_map].values[1].offset = UTILEX_OFFSETOF(dnx_data_field_external_tcam_ffc_to_quad_and_group_map_t, group_id);

    
    submodule_data->tables[dnx_data_field_external_tcam_table_epmf_payload_sizes].name = "epmf_payload_sizes";
    submodule_data->tables[dnx_data_field_external_tcam_table_epmf_payload_sizes].doc = "maximum payload size per result ID";
    submodule_data->tables[dnx_data_field_external_tcam_table_epmf_payload_sizes].flags |= DNXC_DATA_F_TABLE;
    submodule_data->tables[dnx_data_field_external_tcam_table_epmf_payload_sizes].size_of_values = sizeof(dnx_data_field_external_tcam_epmf_payload_sizes_t);
    submodule_data->tables[dnx_data_field_external_tcam_table_epmf_payload_sizes].entry_get = dnx_data_field_external_tcam_epmf_payload_sizes_entry_str_get;

    
    submodule_data->tables[dnx_data_field_external_tcam_table_epmf_payload_sizes].nof_keys = 1;
    submodule_data->tables[dnx_data_field_external_tcam_table_epmf_payload_sizes].keys[0].name = "result_id";
    submodule_data->tables[dnx_data_field_external_tcam_table_epmf_payload_sizes].keys[0].doc = "The payload ID";

    
    submodule_data->tables[dnx_data_field_external_tcam_table_epmf_payload_sizes].nof_values = 3;
    DNXC_DATA_ALLOC(submodule_data->tables[dnx_data_field_external_tcam_table_epmf_payload_sizes].values, dnxc_data_value_t, submodule_data->tables[dnx_data_field_external_tcam_table_epmf_payload_sizes].nof_values, "_dnx_data_field_external_tcam_table_epmf_payload_sizes table values");
    submodule_data->tables[dnx_data_field_external_tcam_table_epmf_payload_sizes].values[0].name = "payload_large_size";
    submodule_data->tables[dnx_data_field_external_tcam_table_epmf_payload_sizes].values[0].type = "int";
    submodule_data->tables[dnx_data_field_external_tcam_table_epmf_payload_sizes].values[0].doc = "Max size of larger option.";
    submodule_data->tables[dnx_data_field_external_tcam_table_epmf_payload_sizes].values[0].offset = UTILEX_OFFSETOF(dnx_data_field_external_tcam_epmf_payload_sizes_t, payload_large_size);
    submodule_data->tables[dnx_data_field_external_tcam_table_epmf_payload_sizes].values[1].name = "payload_small_size";
    submodule_data->tables[dnx_data_field_external_tcam_table_epmf_payload_sizes].values[1].type = "int";
    submodule_data->tables[dnx_data_field_external_tcam_table_epmf_payload_sizes].values[1].doc = "Max size of smaller option. -1 if not applicable.";
    submodule_data->tables[dnx_data_field_external_tcam_table_epmf_payload_sizes].values[1].offset = UTILEX_OFFSETOF(dnx_data_field_external_tcam_epmf_payload_sizes_t, payload_small_size);
    submodule_data->tables[dnx_data_field_external_tcam_table_epmf_payload_sizes].values[2].name = "payload_first_bit";
    submodule_data->tables[dnx_data_field_external_tcam_table_epmf_payload_sizes].values[2].type = "int";
    submodule_data->tables[dnx_data_field_external_tcam_table_epmf_payload_sizes].values[2].doc = "First bit on result buffer.";
    submodule_data->tables[dnx_data_field_external_tcam_table_epmf_payload_sizes].values[2].offset = UTILEX_OFFSETOF(dnx_data_field_external_tcam_epmf_payload_sizes_t, payload_first_bit);


exit:
    SHR_FUNC_EXIT;
}


int
dnx_data_field_external_tcam_feature_get(
    int unit,
    dnx_data_field_external_tcam_feature_e feature)
{
    return dnxc_data_mgmt_feature_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_external_tcam, feature);
}


uint32
dnx_data_field_external_tcam_max_single_key_size_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_external_tcam, dnx_data_field_external_tcam_define_max_single_key_size);
}

uint32
dnx_data_field_external_tcam_nof_acl_keys_master_max_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_external_tcam, dnx_data_field_external_tcam_define_nof_acl_keys_master_max);
}

uint32
dnx_data_field_external_tcam_nof_acl_keys_fg_max_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_external_tcam, dnx_data_field_external_tcam_define_nof_acl_keys_fg_max);
}

uint32
dnx_data_field_external_tcam_nof_keys_total_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_external_tcam, dnx_data_field_external_tcam_define_nof_keys_total);
}

uint32
dnx_data_field_external_tcam_min_acl_nof_ffc_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_external_tcam, dnx_data_field_external_tcam_define_min_acl_nof_ffc);
}

uint32
dnx_data_field_external_tcam_max_fwd_context_num_for_one_apptype_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_external_tcam, dnx_data_field_external_tcam_define_max_fwd_context_num_for_one_apptype);
}

uint32
dnx_data_field_external_tcam_max_acl_context_num_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_external_tcam, dnx_data_field_external_tcam_define_max_acl_context_num);
}

uint32
dnx_data_field_external_tcam_size_apptype_profile_id_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_external_tcam, dnx_data_field_external_tcam_define_size_apptype_profile_id);
}

uint32
dnx_data_field_external_tcam_key_bmp_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_external_tcam, dnx_data_field_external_tcam_define_key_bmp);
}

uint32
dnx_data_field_external_tcam_apptype_user_1st_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_external_tcam, dnx_data_field_external_tcam_define_apptype_user_1st);
}

uint32
dnx_data_field_external_tcam_apptype_user_nof_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_external_tcam, dnx_data_field_external_tcam_define_apptype_user_nof);
}

uint32
dnx_data_field_external_tcam_max_payload_size_per_opcode_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_external_tcam, dnx_data_field_external_tcam_define_max_payload_size_per_opcode);
}

uint32
dnx_data_field_external_tcam_max_payload_size_per_opcode_epmf_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_external_tcam, dnx_data_field_external_tcam_define_max_payload_size_per_opcode_epmf);
}

uint32
dnx_data_field_external_tcam_max_epmf_nof_lookups_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_external_tcam, dnx_data_field_external_tcam_define_max_epmf_nof_lookups);
}

uint32
dnx_data_field_external_tcam_nof_total_lookups_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_external_tcam, dnx_data_field_external_tcam_define_nof_total_lookups);
}

uint32
dnx_data_field_external_tcam_payload_offset_granularity_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_external_tcam, dnx_data_field_external_tcam_define_payload_offset_granularity);
}

uint32
dnx_data_field_external_tcam_type_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_external_tcam, dnx_data_field_external_tcam_define_type);
}



const dnx_data_field_external_tcam_ffc_to_quad_and_group_map_t *
dnx_data_field_external_tcam_ffc_to_quad_and_group_map_get(
    int unit,
    int ffc_id)
{
    char *data;
    dnxc_data_table_t *table;

    
    table = dnxc_data_mgmt_table_get(unit, dnx_data_module_field, dnx_data_field_submodule_external_tcam, dnx_data_field_external_tcam_table_ffc_to_quad_and_group_map);
    
    data = dnxc_data_mgmt_table_data_get(unit, table, ffc_id, 0);
    return (const dnx_data_field_external_tcam_ffc_to_quad_and_group_map_t *) data;

}

const dnx_data_field_external_tcam_epmf_payload_sizes_t *
dnx_data_field_external_tcam_epmf_payload_sizes_get(
    int unit,
    int result_id)
{
    char *data;
    dnxc_data_table_t *table;

    
    table = dnxc_data_mgmt_table_get(unit, dnx_data_module_field, dnx_data_field_submodule_external_tcam, dnx_data_field_external_tcam_table_epmf_payload_sizes);
    
    data = dnxc_data_mgmt_table_data_get(unit, table, result_id, 0);
    return (const dnx_data_field_external_tcam_epmf_payload_sizes_t *) data;

}


shr_error_e
dnx_data_field_external_tcam_ffc_to_quad_and_group_map_entry_str_get(
    int unit,
    char *buffer,
    int key0,
    int key1,
    int value_index)
{
    dnxc_data_table_t *table;
    const dnx_data_field_external_tcam_ffc_to_quad_and_group_map_t *data;
    SHR_FUNC_INIT_VARS(unit);

    
    table = dnxc_data_mgmt_table_get(unit, dnx_data_module_field, dnx_data_field_submodule_external_tcam, dnx_data_field_external_tcam_table_ffc_to_quad_and_group_map);
    data = (const dnx_data_field_external_tcam_ffc_to_quad_and_group_map_t *) dnxc_data_mgmt_table_data_diag_get(unit, table, key0, 0);
    switch (value_index)
    {
        case 0:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->quad_id);
            break;
        case 1:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->group_id);
            break;
    }

    SHR_FUNC_EXIT;
}

shr_error_e
dnx_data_field_external_tcam_epmf_payload_sizes_entry_str_get(
    int unit,
    char *buffer,
    int key0,
    int key1,
    int value_index)
{
    dnxc_data_table_t *table;
    const dnx_data_field_external_tcam_epmf_payload_sizes_t *data;
    SHR_FUNC_INIT_VARS(unit);

    
    table = dnxc_data_mgmt_table_get(unit, dnx_data_module_field, dnx_data_field_submodule_external_tcam, dnx_data_field_external_tcam_table_epmf_payload_sizes);
    data = (const dnx_data_field_external_tcam_epmf_payload_sizes_t *) dnxc_data_mgmt_table_data_diag_get(unit, table, key0, 0);
    switch (value_index)
    {
        case 0:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->payload_large_size);
            break;
        case 1:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->payload_small_size);
            break;
        case 2:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->payload_first_bit);
            break;
    }

    SHR_FUNC_EXIT;
}


const dnxc_data_table_info_t *
dnx_data_field_external_tcam_ffc_to_quad_and_group_map_info_get(
    int unit)
{

    
    return dnxc_data_mgmt_table_info_get(unit, dnx_data_module_field, dnx_data_field_submodule_external_tcam, dnx_data_field_external_tcam_table_ffc_to_quad_and_group_map);

}

const dnxc_data_table_info_t *
dnx_data_field_external_tcam_epmf_payload_sizes_info_get(
    int unit)
{

    
    return dnxc_data_mgmt_table_info_get(unit, dnx_data_module_field, dnx_data_field_submodule_external_tcam, dnx_data_field_external_tcam_table_epmf_payload_sizes);

}






static shr_error_e
dnx_data_field_tcam_init(
    int unit,
    dnxc_data_submodule_t *submodule_data)
{
    SHR_FUNC_INIT_VARS(unit);

    submodule_data->name = "tcam";
    submodule_data->doc = "TCAM data";
    
    submodule_data->nof_features = _dnx_data_field_tcam_feature_nof;
    DNXC_DATA_ALLOC(submodule_data->features, dnxc_data_feature_t,  submodule_data->nof_features, "_dnxc_data field tcam features");

    submodule_data->features[dnx_data_field_tcam_tcam_80b_traffic_safe_write].name = "tcam_80b_traffic_safe_write";
    submodule_data->features[dnx_data_field_tcam_tcam_80b_traffic_safe_write].doc = "Indicates whether moving/adding/deleting 80b entries is traffic safe or not";
    submodule_data->features[dnx_data_field_tcam_tcam_80b_traffic_safe_write].flags |= DNXC_DATA_F_FEATURE;

    submodule_data->features[dnx_data_field_tcam_mixed_ratio_supported].name = "mixed_ratio_supported";
    submodule_data->features[dnx_data_field_tcam_mixed_ratio_supported].doc = "Indicates whether key-mode is used in TCAM HW or not, key-mode enables mixed-ratio as it allows different key-sized TCAM handlers to share the same bank";
    submodule_data->features[dnx_data_field_tcam_mixed_ratio_supported].flags |= DNXC_DATA_F_FEATURE;

    
    submodule_data->nof_defines = _dnx_data_field_tcam_define_nof;
    DNXC_DATA_ALLOC(submodule_data->defines, dnxc_data_define_t, submodule_data->nof_defines, "_dnxc_data field tcam defines");

    submodule_data->defines[dnx_data_field_tcam_define_access_hw_mix_ratio_supported].name = "access_hw_mix_ratio_supported";
    submodule_data->defines[dnx_data_field_tcam_define_access_hw_mix_ratio_supported].doc = "Does HW support mix aspect ratio per bank, i.e. different FG size on same bank";
    
    submodule_data->defines[dnx_data_field_tcam_define_access_hw_mix_ratio_supported].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_tcam_define_direct_supported].name = "direct_supported";
    submodule_data->defines[dnx_data_field_tcam_define_direct_supported].doc = "HW supports TCAM Direct access ";
    
    submodule_data->defines[dnx_data_field_tcam_define_direct_supported].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_tcam_define_key_size_half].name = "key_size_half";
    submodule_data->defines[dnx_data_field_tcam_define_key_size_half].doc = "Half TCAM key size";
    
    submodule_data->defines[dnx_data_field_tcam_define_key_size_half].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_tcam_define_key_size_single].name = "key_size_single";
    submodule_data->defines[dnx_data_field_tcam_define_key_size_single].doc = "Single TCAM key size";
    
    submodule_data->defines[dnx_data_field_tcam_define_key_size_single].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_tcam_define_key_size_double].name = "key_size_double";
    submodule_data->defines[dnx_data_field_tcam_define_key_size_double].doc = "Double TCAM key size";
    
    submodule_data->defines[dnx_data_field_tcam_define_key_size_double].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_tcam_define_dt_max_key_size].name = "dt_max_key_size";
    submodule_data->defines[dnx_data_field_tcam_define_dt_max_key_size].doc = "Maximum key size for TCAM DT";
    
    submodule_data->defines[dnx_data_field_tcam_define_dt_max_key_size].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_tcam_define_dt_max_key_size_small_bank].name = "dt_max_key_size_small_bank";
    submodule_data->defines[dnx_data_field_tcam_define_dt_max_key_size_small_bank].doc = "Maximum key size for TCAM DT on small banks";
    
    submodule_data->defines[dnx_data_field_tcam_define_dt_max_key_size_small_bank].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_tcam_define_action_size_half].name = "action_size_half";
    submodule_data->defines[dnx_data_field_tcam_define_action_size_half].doc = "When the key size is half key (80b), this holds the action width payload";
    
    submodule_data->defines[dnx_data_field_tcam_define_action_size_half].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_tcam_define_action_size_single].name = "action_size_single";
    submodule_data->defines[dnx_data_field_tcam_define_action_size_single].doc = "When the key size is single key (160b), this holds the action width payload";
    
    submodule_data->defines[dnx_data_field_tcam_define_action_size_single].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_tcam_define_action_size_double].name = "action_size_double";
    submodule_data->defines[dnx_data_field_tcam_define_action_size_double].doc = "When the key size is double key (320b), this holds the action width payload";
    
    submodule_data->defines[dnx_data_field_tcam_define_action_size_double].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_tcam_define_key_mode_size].name = "key_mode_size";
    submodule_data->defines[dnx_data_field_tcam_define_key_mode_size].doc = "Number of bits representing the entry size for each half entry.";
    
    submodule_data->defines[dnx_data_field_tcam_define_key_mode_size].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_tcam_define_entry_size_single_key_hw].name = "entry_size_single_key_hw";
    submodule_data->defines[dnx_data_field_tcam_define_entry_size_single_key_hw].doc = "The full key size in HW, includingd entry size field, not including payload and valid bits.";
    
    submodule_data->defines[dnx_data_field_tcam_define_entry_size_single_key_hw].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_tcam_define_entry_size_single_key_shadow].name = "entry_size_single_key_shadow";
    submodule_data->defines[dnx_data_field_tcam_define_entry_size_single_key_shadow].doc = "Shadow entry size, including mode bits and valid bits";
    
    submodule_data->defines[dnx_data_field_tcam_define_entry_size_single_key_shadow].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_tcam_define_entry_size_single_valid_bits_hw].name = "entry_size_single_valid_bits_hw";
    submodule_data->defines[dnx_data_field_tcam_define_entry_size_single_valid_bits_hw].doc = "The size of the valid bits in HW.";
    
    submodule_data->defines[dnx_data_field_tcam_define_entry_size_single_valid_bits_hw].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_tcam_define_hw_bank_size].name = "hw_bank_size";
    submodule_data->defines[dnx_data_field_tcam_define_hw_bank_size].doc = "Size of a TCAM bank in HW";
    
    submodule_data->defines[dnx_data_field_tcam_define_hw_bank_size].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_tcam_define_nof_big_bank_lines].name = "nof_big_bank_lines";
    submodule_data->defines[dnx_data_field_tcam_define_nof_big_bank_lines].doc = "Number of TCAM big bank lines";
    
    submodule_data->defines[dnx_data_field_tcam_define_nof_big_bank_lines].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_tcam_define_nof_small_bank_lines].name = "nof_small_bank_lines";
    submodule_data->defines[dnx_data_field_tcam_define_nof_small_bank_lines].doc = "Number of TCAM small bank lines";
    
    submodule_data->defines[dnx_data_field_tcam_define_nof_small_bank_lines].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_tcam_define_nof_big_banks].name = "nof_big_banks";
    submodule_data->defines[dnx_data_field_tcam_define_nof_big_banks].doc = "Number of TCAM big banks";
    
    submodule_data->defines[dnx_data_field_tcam_define_nof_big_banks].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_tcam_define_nof_small_banks].name = "nof_small_banks";
    submodule_data->defines[dnx_data_field_tcam_define_nof_small_banks].doc = "Number of TCAM small banks";
    
    submodule_data->defines[dnx_data_field_tcam_define_nof_small_banks].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_tcam_define_nof_banks].name = "nof_banks";
    submodule_data->defines[dnx_data_field_tcam_define_nof_banks].doc = "Number of TCAM banks";
    
    submodule_data->defines[dnx_data_field_tcam_define_nof_banks].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_tcam_define_nof_payload_tables].name = "nof_payload_tables";
    submodule_data->defines[dnx_data_field_tcam_define_nof_payload_tables].doc = "Number of action tables";
    
    submodule_data->defines[dnx_data_field_tcam_define_nof_payload_tables].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_tcam_define_nof_access_profiles].name = "nof_access_profiles";
    submodule_data->defines[dnx_data_field_tcam_define_nof_access_profiles].doc = "Number of TCAM access profiles";
    
    submodule_data->defines[dnx_data_field_tcam_define_nof_access_profiles].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_tcam_define_action_width_selector_size].name = "action_width_selector_size";
    submodule_data->defines[dnx_data_field_tcam_define_action_width_selector_size].doc = "The action width selector size for each bank in each access profile, each bit represents the corresponding 32 bit in the action table";
    
    submodule_data->defines[dnx_data_field_tcam_define_action_width_selector_size].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_tcam_define_nof_entries_160_bits].name = "nof_entries_160_bits";
    submodule_data->defines[dnx_data_field_tcam_define_nof_entries_160_bits].doc = "Number of 160 bits TCAM entries; Value: (nof_big_banks*nof_big_bank_lines)+(nof_small_banks*nof_small_bank_lines)";
    
    submodule_data->defines[dnx_data_field_tcam_define_nof_entries_160_bits].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_tcam_define_nof_entries_80_bits].name = "nof_entries_80_bits";
    submodule_data->defines[dnx_data_field_tcam_define_nof_entries_80_bits].doc = "Number of 80 bits TCAM entries; Value: (2*nof_big_banks*nof_big_bank_lines)+(2*nof_small_banks*nof_small_bank_lines)";
    
    submodule_data->defines[dnx_data_field_tcam_define_nof_entries_80_bits].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_tcam_define_tcam_banks_size].name = "tcam_banks_size";
    submodule_data->defines[dnx_data_field_tcam_define_tcam_banks_size].doc = "The size of TCAM_TCAM_BANK which is equal to (nof_big_banks + nof_small_banks) * nof_big_bank_lines";
    
    submodule_data->defines[dnx_data_field_tcam_define_tcam_banks_size].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_tcam_define_tcam_banks_last_index].name = "tcam_banks_last_index";
    submodule_data->defines[dnx_data_field_tcam_define_tcam_banks_last_index].doc = "Last index available in TCAM banks";
    
    submodule_data->defines[dnx_data_field_tcam_define_tcam_banks_last_index].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_tcam_define_nof_tcam_handlers].name = "nof_tcam_handlers";
    submodule_data->defines[dnx_data_field_tcam_define_nof_tcam_handlers].doc = "Number of TCAM handlers in device";
    
    submodule_data->defines[dnx_data_field_tcam_define_nof_tcam_handlers].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_tcam_define_max_prefix_size].name = "max_prefix_size";
    submodule_data->defines[dnx_data_field_tcam_define_max_prefix_size].doc = "Maximum prefix size in TCAM";
    
    submodule_data->defines[dnx_data_field_tcam_define_max_prefix_size].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_tcam_define_max_prefix_value].name = "max_prefix_value";
    submodule_data->defines[dnx_data_field_tcam_define_max_prefix_value].doc = "Maximum prefix value in TCAM";
    
    submodule_data->defines[dnx_data_field_tcam_define_max_prefix_value].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_tcam_define_nof_keys_max].name = "nof_keys_max";
    submodule_data->defines[dnx_data_field_tcam_define_nof_keys_max].doc = "Number of 160'b key's in one search lookup";
    
    submodule_data->defines[dnx_data_field_tcam_define_nof_keys_max].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_tcam_define_access_profile_half_key_mode].name = "access_profile_half_key_mode";
    submodule_data->defines[dnx_data_field_tcam_define_access_profile_half_key_mode].doc = "Half key mode in access profile";
    
    submodule_data->defines[dnx_data_field_tcam_define_access_profile_half_key_mode].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_tcam_define_access_profile_single_key_mode].name = "access_profile_single_key_mode";
    submodule_data->defines[dnx_data_field_tcam_define_access_profile_single_key_mode].doc = "Single key mode in access profile";
    
    submodule_data->defines[dnx_data_field_tcam_define_access_profile_single_key_mode].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_tcam_define_access_profile_double_key_mode].name = "access_profile_double_key_mode";
    submodule_data->defines[dnx_data_field_tcam_define_access_profile_double_key_mode].doc = "Double key mode in access profile";
    
    submodule_data->defines[dnx_data_field_tcam_define_access_profile_double_key_mode].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_tcam_define_tcam_entries_per_hit_indication_entry].name = "tcam_entries_per_hit_indication_entry";
    submodule_data->defines[dnx_data_field_tcam_define_tcam_entries_per_hit_indication_entry].doc = "Number of entries in TCAM and CS TCAM HIT indication memories line (8b bmp).";
    
    submodule_data->defines[dnx_data_field_tcam_define_tcam_entries_per_hit_indication_entry].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_tcam_define_max_tcam_priority].name = "max_tcam_priority";
    submodule_data->defines[dnx_data_field_tcam_define_max_tcam_priority].doc = "The biggest valid value for the priority of a TCAM entry";
    
    submodule_data->defines[dnx_data_field_tcam_define_max_tcam_priority].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_tcam_define_nof_big_banks_srams].name = "nof_big_banks_srams";
    submodule_data->defines[dnx_data_field_tcam_define_nof_big_banks_srams].doc = "Number of SRAMs for big banks.";
    
    submodule_data->defines[dnx_data_field_tcam_define_nof_big_banks_srams].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_tcam_define_nof_small_banks_srams].name = "nof_small_banks_srams";
    submodule_data->defines[dnx_data_field_tcam_define_nof_small_banks_srams].doc = "Number of SRAMs for small banks.";
    
    submodule_data->defines[dnx_data_field_tcam_define_nof_small_banks_srams].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_tcam_define_nof_big_bank_lines_per_sram].name = "nof_big_bank_lines_per_sram";
    submodule_data->defines[dnx_data_field_tcam_define_nof_big_bank_lines_per_sram].doc = "Number of big bank lines per SRAM.";
    
    submodule_data->defines[dnx_data_field_tcam_define_nof_big_bank_lines_per_sram].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_tcam_define_nof_small_bank_lines_per_sram].name = "nof_small_bank_lines_per_sram";
    submodule_data->defines[dnx_data_field_tcam_define_nof_small_bank_lines_per_sram].doc = "Number of small bank lines per SRAM.";
    
    submodule_data->defines[dnx_data_field_tcam_define_nof_small_bank_lines_per_sram].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_tcam_define_app_db_id_size].name = "app_db_id_size";
    submodule_data->defines[dnx_data_field_tcam_define_app_db_id_size].doc = "Size in bits of the app_db_id.";
    
    submodule_data->defines[dnx_data_field_tcam_define_app_db_id_size].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_tcam_define_tcam_indirect_command_version].name = "tcam_indirect_command_version";
    submodule_data->defines[dnx_data_field_tcam_define_tcam_indirect_command_version].doc = "Version of the TCAM_INDIRECT_COMMAND register";
    
    submodule_data->defines[dnx_data_field_tcam_define_tcam_indirect_command_version].flags |= DNXC_DATA_F_DEFINE;

    
    submodule_data->nof_tables = _dnx_data_field_tcam_table_nof;
    DNXC_DATA_ALLOC(submodule_data->tables, dnxc_data_table_t, submodule_data->nof_tables, "_dnxc_data field tcam tables");


exit:
    SHR_FUNC_EXIT;
}


int
dnx_data_field_tcam_feature_get(
    int unit,
    dnx_data_field_tcam_feature_e feature)
{
    return dnxc_data_mgmt_feature_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_tcam, feature);
}


uint32
dnx_data_field_tcam_access_hw_mix_ratio_supported_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_tcam, dnx_data_field_tcam_define_access_hw_mix_ratio_supported);
}

uint32
dnx_data_field_tcam_direct_supported_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_tcam, dnx_data_field_tcam_define_direct_supported);
}

uint32
dnx_data_field_tcam_key_size_half_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_tcam, dnx_data_field_tcam_define_key_size_half);
}

uint32
dnx_data_field_tcam_key_size_single_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_tcam, dnx_data_field_tcam_define_key_size_single);
}

uint32
dnx_data_field_tcam_key_size_double_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_tcam, dnx_data_field_tcam_define_key_size_double);
}

uint32
dnx_data_field_tcam_dt_max_key_size_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_tcam, dnx_data_field_tcam_define_dt_max_key_size);
}

uint32
dnx_data_field_tcam_dt_max_key_size_small_bank_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_tcam, dnx_data_field_tcam_define_dt_max_key_size_small_bank);
}

uint32
dnx_data_field_tcam_action_size_half_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_tcam, dnx_data_field_tcam_define_action_size_half);
}

uint32
dnx_data_field_tcam_action_size_single_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_tcam, dnx_data_field_tcam_define_action_size_single);
}

uint32
dnx_data_field_tcam_action_size_double_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_tcam, dnx_data_field_tcam_define_action_size_double);
}

uint32
dnx_data_field_tcam_key_mode_size_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_tcam, dnx_data_field_tcam_define_key_mode_size);
}

uint32
dnx_data_field_tcam_entry_size_single_key_hw_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_tcam, dnx_data_field_tcam_define_entry_size_single_key_hw);
}

uint32
dnx_data_field_tcam_entry_size_single_key_shadow_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_tcam, dnx_data_field_tcam_define_entry_size_single_key_shadow);
}

uint32
dnx_data_field_tcam_entry_size_single_valid_bits_hw_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_tcam, dnx_data_field_tcam_define_entry_size_single_valid_bits_hw);
}

uint32
dnx_data_field_tcam_hw_bank_size_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_tcam, dnx_data_field_tcam_define_hw_bank_size);
}

uint32
dnx_data_field_tcam_nof_big_bank_lines_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_tcam, dnx_data_field_tcam_define_nof_big_bank_lines);
}

uint32
dnx_data_field_tcam_nof_small_bank_lines_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_tcam, dnx_data_field_tcam_define_nof_small_bank_lines);
}

uint32
dnx_data_field_tcam_nof_big_banks_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_tcam, dnx_data_field_tcam_define_nof_big_banks);
}

uint32
dnx_data_field_tcam_nof_small_banks_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_tcam, dnx_data_field_tcam_define_nof_small_banks);
}

uint32
dnx_data_field_tcam_nof_banks_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_tcam, dnx_data_field_tcam_define_nof_banks);
}

uint32
dnx_data_field_tcam_nof_payload_tables_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_tcam, dnx_data_field_tcam_define_nof_payload_tables);
}

uint32
dnx_data_field_tcam_nof_access_profiles_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_tcam, dnx_data_field_tcam_define_nof_access_profiles);
}

uint32
dnx_data_field_tcam_action_width_selector_size_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_tcam, dnx_data_field_tcam_define_action_width_selector_size);
}

uint32
dnx_data_field_tcam_nof_entries_160_bits_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_tcam, dnx_data_field_tcam_define_nof_entries_160_bits);
}

uint32
dnx_data_field_tcam_nof_entries_80_bits_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_tcam, dnx_data_field_tcam_define_nof_entries_80_bits);
}

uint32
dnx_data_field_tcam_tcam_banks_size_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_tcam, dnx_data_field_tcam_define_tcam_banks_size);
}

uint32
dnx_data_field_tcam_tcam_banks_last_index_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_tcam, dnx_data_field_tcam_define_tcam_banks_last_index);
}

uint32
dnx_data_field_tcam_nof_tcam_handlers_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_tcam, dnx_data_field_tcam_define_nof_tcam_handlers);
}

uint32
dnx_data_field_tcam_max_prefix_size_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_tcam, dnx_data_field_tcam_define_max_prefix_size);
}

uint32
dnx_data_field_tcam_max_prefix_value_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_tcam, dnx_data_field_tcam_define_max_prefix_value);
}

uint32
dnx_data_field_tcam_nof_keys_max_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_tcam, dnx_data_field_tcam_define_nof_keys_max);
}

uint32
dnx_data_field_tcam_access_profile_half_key_mode_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_tcam, dnx_data_field_tcam_define_access_profile_half_key_mode);
}

uint32
dnx_data_field_tcam_access_profile_single_key_mode_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_tcam, dnx_data_field_tcam_define_access_profile_single_key_mode);
}

uint32
dnx_data_field_tcam_access_profile_double_key_mode_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_tcam, dnx_data_field_tcam_define_access_profile_double_key_mode);
}

uint32
dnx_data_field_tcam_tcam_entries_per_hit_indication_entry_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_tcam, dnx_data_field_tcam_define_tcam_entries_per_hit_indication_entry);
}

uint32
dnx_data_field_tcam_max_tcam_priority_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_tcam, dnx_data_field_tcam_define_max_tcam_priority);
}

uint32
dnx_data_field_tcam_nof_big_banks_srams_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_tcam, dnx_data_field_tcam_define_nof_big_banks_srams);
}

uint32
dnx_data_field_tcam_nof_small_banks_srams_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_tcam, dnx_data_field_tcam_define_nof_small_banks_srams);
}

uint32
dnx_data_field_tcam_nof_big_bank_lines_per_sram_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_tcam, dnx_data_field_tcam_define_nof_big_bank_lines_per_sram);
}

uint32
dnx_data_field_tcam_nof_small_bank_lines_per_sram_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_tcam, dnx_data_field_tcam_define_nof_small_bank_lines_per_sram);
}

uint32
dnx_data_field_tcam_app_db_id_size_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_tcam, dnx_data_field_tcam_define_app_db_id_size);
}

uint32
dnx_data_field_tcam_tcam_indirect_command_version_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_tcam, dnx_data_field_tcam_define_tcam_indirect_command_version);
}










static shr_error_e
dnx_data_field_group_init(
    int unit,
    dnxc_data_submodule_t *submodule_data)
{
    SHR_FUNC_INIT_VARS(unit);

    submodule_data->name = "group";
    submodule_data->doc = "Field Group";
    
    submodule_data->nof_features = _dnx_data_field_group_feature_nof;
    DNXC_DATA_ALLOC(submodule_data->features, dnxc_data_feature_t,  submodule_data->nof_features, "_dnxc_data field group features");

    
    submodule_data->nof_defines = _dnx_data_field_group_define_nof;
    DNXC_DATA_ALLOC(submodule_data->defines, dnxc_data_define_t, submodule_data->nof_defines, "_dnxc_data field group defines");

    submodule_data->defines[dnx_data_field_group_define_nof_fgs].name = "nof_fgs";
    submodule_data->defines[dnx_data_field_group_define_nof_fgs].doc = "Number of Field Groups";
    
    submodule_data->defines[dnx_data_field_group_define_nof_fgs].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_group_define_nof_action_per_fg].name = "nof_action_per_fg";
    submodule_data->defines[dnx_data_field_group_define_nof_action_per_fg].doc = "Number of action per Field Group";
    
    submodule_data->defines[dnx_data_field_group_define_nof_action_per_fg].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_group_define_nof_quals_per_fg].name = "nof_quals_per_fg";
    submodule_data->defines[dnx_data_field_group_define_nof_quals_per_fg].doc = "Number of qualifiers per Field Group";
    
    submodule_data->defines[dnx_data_field_group_define_nof_quals_per_fg].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_group_define_nof_keys_per_fg_max].name = "nof_keys_per_fg_max";
    submodule_data->defines[dnx_data_field_group_define_nof_keys_per_fg_max].doc = "Maximum number of keys (KBRs) a field group can have.";
    
    submodule_data->defines[dnx_data_field_group_define_nof_keys_per_fg_max].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_group_define_id_fec].name = "id_fec";
    submodule_data->defines[dnx_data_field_group_define_id_fec].doc = "FEC is being used in more then one context, hence must be created with_id so that other applications can re-use the FG";
    
    submodule_data->defines[dnx_data_field_group_define_id_fec].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_group_define_payload_max_size].name = "payload_max_size";
    submodule_data->defines[dnx_data_field_group_define_payload_max_size].doc = "Maximum Payload size a field group can have.";
    
    submodule_data->defines[dnx_data_field_group_define_payload_max_size].flags |= DNXC_DATA_F_DEFINE;

    
    submodule_data->nof_tables = _dnx_data_field_group_table_nof;
    DNXC_DATA_ALLOC(submodule_data->tables, dnxc_data_table_t, submodule_data->nof_tables, "_dnxc_data field group tables");


exit:
    SHR_FUNC_EXIT;
}


int
dnx_data_field_group_feature_get(
    int unit,
    dnx_data_field_group_feature_e feature)
{
    return dnxc_data_mgmt_feature_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_group, feature);
}


uint32
dnx_data_field_group_nof_fgs_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_group, dnx_data_field_group_define_nof_fgs);
}

uint32
dnx_data_field_group_nof_action_per_fg_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_group, dnx_data_field_group_define_nof_action_per_fg);
}

uint32
dnx_data_field_group_nof_quals_per_fg_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_group, dnx_data_field_group_define_nof_quals_per_fg);
}

uint32
dnx_data_field_group_nof_keys_per_fg_max_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_group, dnx_data_field_group_define_nof_keys_per_fg_max);
}

uint32
dnx_data_field_group_id_fec_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_group, dnx_data_field_group_define_id_fec);
}

uint32
dnx_data_field_group_payload_max_size_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_group, dnx_data_field_group_define_payload_max_size);
}










static shr_error_e
dnx_data_field_efes_init(
    int unit,
    dnxc_data_submodule_t *submodule_data)
{
    SHR_FUNC_INIT_VARS(unit);

    submodule_data->name = "efes";
    submodule_data->doc = "EFES data";
    
    submodule_data->nof_features = _dnx_data_field_efes_feature_nof;
    DNXC_DATA_ALLOC(submodule_data->features, dnxc_data_feature_t,  submodule_data->nof_features, "_dnxc_data field efes features");

    
    submodule_data->nof_defines = _dnx_data_field_efes_define_nof;
    DNXC_DATA_ALLOC(submodule_data->defines, dnxc_data_define_t, submodule_data->nof_defines, "_dnxc_data field efes defines");

    submodule_data->defines[dnx_data_field_efes_define_max_nof_key_selects_per_field_io].name = "max_nof_key_selects_per_field_io";
    submodule_data->defines[dnx_data_field_efes_define_max_nof_key_selects_per_field_io].doc = "Number of key selects in table for each field IO";
    
    submodule_data->defines[dnx_data_field_efes_define_max_nof_key_selects_per_field_io].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_efes_define_max_nof_field_ios].name = "max_nof_field_ios";
    submodule_data->defines[dnx_data_field_efes_define_max_nof_field_ios].doc = "Number of field IOs";
    
    submodule_data->defines[dnx_data_field_efes_define_max_nof_field_ios].flags |= DNXC_DATA_F_DEFINE;

    
    submodule_data->nof_tables = _dnx_data_field_efes_table_nof;
    DNXC_DATA_ALLOC(submodule_data->tables, dnxc_data_table_t, submodule_data->nof_tables, "_dnxc_data field efes tables");

    
    submodule_data->tables[dnx_data_field_efes_table_key_select_properties].name = "key_select_properties";
    submodule_data->tables[dnx_data_field_efes_table_key_select_properties].doc = "The properties of the different key select options";
    submodule_data->tables[dnx_data_field_efes_table_key_select_properties].flags |= DNXC_DATA_F_TABLE;
    submodule_data->tables[dnx_data_field_efes_table_key_select_properties].size_of_values = sizeof(dnx_data_field_efes_key_select_properties_t);
    submodule_data->tables[dnx_data_field_efes_table_key_select_properties].entry_get = dnx_data_field_efes_key_select_properties_entry_str_get;

    
    submodule_data->tables[dnx_data_field_efes_table_key_select_properties].nof_keys = 2;
    submodule_data->tables[dnx_data_field_efes_table_key_select_properties].keys[0].name = "stage";
    submodule_data->tables[dnx_data_field_efes_table_key_select_properties].keys[0].doc = "Field stage enum";
    submodule_data->tables[dnx_data_field_efes_table_key_select_properties].keys[1].name = "field_io";
    submodule_data->tables[dnx_data_field_efes_table_key_select_properties].keys[1].doc = "Identifies the source of the information";

    
    submodule_data->tables[dnx_data_field_efes_table_key_select_properties].nof_values = 4;
    DNXC_DATA_ALLOC(submodule_data->tables[dnx_data_field_efes_table_key_select_properties].values, dnxc_data_value_t, submodule_data->tables[dnx_data_field_efes_table_key_select_properties].nof_values, "_dnx_data_field_efes_table_key_select_properties table values");
    submodule_data->tables[dnx_data_field_efes_table_key_select_properties].values[0].name = "key_select";
    submodule_data->tables[dnx_data_field_efes_table_key_select_properties].values[0].type = "uint8[DNX_DATA_MAX_FIELD_EFES_MAX_NOF_KEY_SELECTS_PER_FIELD_IO]";
    submodule_data->tables[dnx_data_field_efes_table_key_select_properties].values[0].doc = "Represents the DBAL key select enums of the different stages";
    submodule_data->tables[dnx_data_field_efes_table_key_select_properties].values[0].offset = UTILEX_OFFSETOF(dnx_data_field_efes_key_select_properties_t, key_select);
    submodule_data->tables[dnx_data_field_efes_table_key_select_properties].values[1].name = "num_bits";
    submodule_data->tables[dnx_data_field_efes_table_key_select_properties].values[1].type = "uint8[DNX_DATA_MAX_FIELD_EFES_MAX_NOF_KEY_SELECTS_PER_FIELD_IO]";
    submodule_data->tables[dnx_data_field_efes_table_key_select_properties].values[1].doc = "Number of bits on key select for field IO. If zero than entry is invalid.";
    submodule_data->tables[dnx_data_field_efes_table_key_select_properties].values[1].offset = UTILEX_OFFSETOF(dnx_data_field_efes_key_select_properties_t, num_bits);
    submodule_data->tables[dnx_data_field_efes_table_key_select_properties].values[2].name = "lsb";
    submodule_data->tables[dnx_data_field_efes_table_key_select_properties].values[2].type = "uint16[DNX_DATA_MAX_FIELD_EFES_MAX_NOF_KEY_SELECTS_PER_FIELD_IO]";
    submodule_data->tables[dnx_data_field_efes_table_key_select_properties].values[2].doc = "The offset on the field IO of the key select";
    submodule_data->tables[dnx_data_field_efes_table_key_select_properties].values[2].offset = UTILEX_OFFSETOF(dnx_data_field_efes_key_select_properties_t, lsb);
    submodule_data->tables[dnx_data_field_efes_table_key_select_properties].values[3].name = "num_bits_not_on_key";
    submodule_data->tables[dnx_data_field_efes_table_key_select_properties].values[3].type = "uint8[DNX_DATA_MAX_FIELD_EFES_MAX_NOF_KEY_SELECTS_PER_FIELD_IO]";
    submodule_data->tables[dnx_data_field_efes_table_key_select_properties].values[3].doc = "The number of LS bits on key select not on the field IO";
    submodule_data->tables[dnx_data_field_efes_table_key_select_properties].values[3].offset = UTILEX_OFFSETOF(dnx_data_field_efes_key_select_properties_t, num_bits_not_on_key);


exit:
    SHR_FUNC_EXIT;
}


int
dnx_data_field_efes_feature_get(
    int unit,
    dnx_data_field_efes_feature_e feature)
{
    return dnxc_data_mgmt_feature_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_efes, feature);
}


uint32
dnx_data_field_efes_max_nof_key_selects_per_field_io_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_efes, dnx_data_field_efes_define_max_nof_key_selects_per_field_io);
}

uint32
dnx_data_field_efes_max_nof_field_ios_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_efes, dnx_data_field_efes_define_max_nof_field_ios);
}



const dnx_data_field_efes_key_select_properties_t *
dnx_data_field_efes_key_select_properties_get(
    int unit,
    int stage,
    int field_io)
{
    char *data;
    dnxc_data_table_t *table;

    
    table = dnxc_data_mgmt_table_get(unit, dnx_data_module_field, dnx_data_field_submodule_efes, dnx_data_field_efes_table_key_select_properties);
    
    data = dnxc_data_mgmt_table_data_get(unit, table, stage, field_io);
    return (const dnx_data_field_efes_key_select_properties_t *) data;

}


shr_error_e
dnx_data_field_efes_key_select_properties_entry_str_get(
    int unit,
    char *buffer,
    int key0,
    int key1,
    int value_index)
{
    dnxc_data_table_t *table;
    const dnx_data_field_efes_key_select_properties_t *data;
    SHR_FUNC_INIT_VARS(unit);

    
    table = dnxc_data_mgmt_table_get(unit, dnx_data_module_field, dnx_data_field_submodule_efes, dnx_data_field_efes_table_key_select_properties);
    data = (const dnx_data_field_efes_key_select_properties_t *) dnxc_data_mgmt_table_data_diag_get(unit, table, key0, key1);
    switch (value_index)
    {
        case 0:
            DNXC_DATA_MGMT_ARR_STR(buffer, DNX_DATA_MAX_FIELD_EFES_MAX_NOF_KEY_SELECTS_PER_FIELD_IO, data->key_select);
            break;
        case 1:
            DNXC_DATA_MGMT_ARR_STR(buffer, DNX_DATA_MAX_FIELD_EFES_MAX_NOF_KEY_SELECTS_PER_FIELD_IO, data->num_bits);
            break;
        case 2:
            DNXC_DATA_MGMT_ARR_STR(buffer, DNX_DATA_MAX_FIELD_EFES_MAX_NOF_KEY_SELECTS_PER_FIELD_IO, data->lsb);
            break;
        case 3:
            DNXC_DATA_MGMT_ARR_STR(buffer, DNX_DATA_MAX_FIELD_EFES_MAX_NOF_KEY_SELECTS_PER_FIELD_IO, data->num_bits_not_on_key);
            break;
    }

    SHR_FUNC_EXIT;
}


const dnxc_data_table_info_t *
dnx_data_field_efes_key_select_properties_info_get(
    int unit)
{

    
    return dnxc_data_mgmt_table_info_get(unit, dnx_data_module_field, dnx_data_field_submodule_efes, dnx_data_field_efes_table_key_select_properties);

}






static shr_error_e
dnx_data_field_fem_init(
    int unit,
    dnxc_data_submodule_t *submodule_data)
{
    SHR_FUNC_INIT_VARS(unit);

    submodule_data->name = "fem";
    submodule_data->doc = "FEM data";
    
    submodule_data->nof_features = _dnx_data_field_fem_feature_nof;
    DNXC_DATA_ALLOC(submodule_data->features, dnxc_data_feature_t,  submodule_data->nof_features, "_dnxc_data field fem features");

    
    submodule_data->nof_defines = _dnx_data_field_fem_define_nof;
    DNXC_DATA_ALLOC(submodule_data->defines, dnxc_data_define_t, submodule_data->nof_defines, "_dnxc_data field fem defines");

    submodule_data->defines[dnx_data_field_fem_define_max_nof_key_selects_per_field_io].name = "max_nof_key_selects_per_field_io";
    submodule_data->defines[dnx_data_field_fem_define_max_nof_key_selects_per_field_io].doc = "Number of key selects in table for each field IO";
    
    submodule_data->defines[dnx_data_field_fem_define_max_nof_key_selects_per_field_io].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_fem_define_nof_condition_bits].name = "nof_condition_bits";
    submodule_data->defines[dnx_data_field_fem_define_nof_condition_bits].doc = "Number of condition bits in FEM";
    
    submodule_data->defines[dnx_data_field_fem_define_nof_condition_bits].flags |= DNXC_DATA_F_NUMERIC;

    
    submodule_data->nof_tables = _dnx_data_field_fem_table_nof;
    DNXC_DATA_ALLOC(submodule_data->tables, dnxc_data_table_t, submodule_data->nof_tables, "_dnxc_data field fem tables");

    
    submodule_data->tables[dnx_data_field_fem_table_key_select_properties].name = "key_select_properties";
    submodule_data->tables[dnx_data_field_fem_table_key_select_properties].doc = "The properties of the different key select options";
    submodule_data->tables[dnx_data_field_fem_table_key_select_properties].flags |= DNXC_DATA_F_TABLE;
    submodule_data->tables[dnx_data_field_fem_table_key_select_properties].size_of_values = sizeof(dnx_data_field_fem_key_select_properties_t);
    submodule_data->tables[dnx_data_field_fem_table_key_select_properties].entry_get = dnx_data_field_fem_key_select_properties_entry_str_get;

    
    submodule_data->tables[dnx_data_field_fem_table_key_select_properties].nof_keys = 1;
    submodule_data->tables[dnx_data_field_fem_table_key_select_properties].keys[0].name = "field_io";
    submodule_data->tables[dnx_data_field_fem_table_key_select_properties].keys[0].doc = "Identifies the source of the information";

    
    submodule_data->tables[dnx_data_field_fem_table_key_select_properties].nof_values = 4;
    DNXC_DATA_ALLOC(submodule_data->tables[dnx_data_field_fem_table_key_select_properties].values, dnxc_data_value_t, submodule_data->tables[dnx_data_field_fem_table_key_select_properties].nof_values, "_dnx_data_field_fem_table_key_select_properties table values");
    submodule_data->tables[dnx_data_field_fem_table_key_select_properties].values[0].name = "key_select";
    submodule_data->tables[dnx_data_field_fem_table_key_select_properties].values[0].type = "uint8[DNX_DATA_MAX_FIELD_FEM_MAX_NOF_KEY_SELECTS_PER_FIELD_IO]";
    submodule_data->tables[dnx_data_field_fem_table_key_select_properties].values[0].doc = "Represents the DBAL key select enums of the different stages";
    submodule_data->tables[dnx_data_field_fem_table_key_select_properties].values[0].offset = UTILEX_OFFSETOF(dnx_data_field_fem_key_select_properties_t, key_select);
    submodule_data->tables[dnx_data_field_fem_table_key_select_properties].values[1].name = "num_bits";
    submodule_data->tables[dnx_data_field_fem_table_key_select_properties].values[1].type = "uint8[DNX_DATA_MAX_FIELD_FEM_MAX_NOF_KEY_SELECTS_PER_FIELD_IO]";
    submodule_data->tables[dnx_data_field_fem_table_key_select_properties].values[1].doc = "Number of bits on key select for field IO. If zero than entry is invalid.";
    submodule_data->tables[dnx_data_field_fem_table_key_select_properties].values[1].offset = UTILEX_OFFSETOF(dnx_data_field_fem_key_select_properties_t, num_bits);
    submodule_data->tables[dnx_data_field_fem_table_key_select_properties].values[2].name = "lsb";
    submodule_data->tables[dnx_data_field_fem_table_key_select_properties].values[2].type = "uint16[DNX_DATA_MAX_FIELD_FEM_MAX_NOF_KEY_SELECTS_PER_FIELD_IO]";
    submodule_data->tables[dnx_data_field_fem_table_key_select_properties].values[2].doc = "The offset on the field IO of the key select";
    submodule_data->tables[dnx_data_field_fem_table_key_select_properties].values[2].offset = UTILEX_OFFSETOF(dnx_data_field_fem_key_select_properties_t, lsb);
    submodule_data->tables[dnx_data_field_fem_table_key_select_properties].values[3].name = "num_bits_not_on_key";
    submodule_data->tables[dnx_data_field_fem_table_key_select_properties].values[3].type = "uint8[DNX_DATA_MAX_FIELD_FEM_MAX_NOF_KEY_SELECTS_PER_FIELD_IO]";
    submodule_data->tables[dnx_data_field_fem_table_key_select_properties].values[3].doc = "The number of LS bits on key select not on the field IO";
    submodule_data->tables[dnx_data_field_fem_table_key_select_properties].values[3].offset = UTILEX_OFFSETOF(dnx_data_field_fem_key_select_properties_t, num_bits_not_on_key);


exit:
    SHR_FUNC_EXIT;
}


int
dnx_data_field_fem_feature_get(
    int unit,
    dnx_data_field_fem_feature_e feature)
{
    return dnxc_data_mgmt_feature_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_fem, feature);
}


uint32
dnx_data_field_fem_max_nof_key_selects_per_field_io_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_fem, dnx_data_field_fem_define_max_nof_key_selects_per_field_io);
}

uint32
dnx_data_field_fem_nof_condition_bits_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_fem, dnx_data_field_fem_define_nof_condition_bits);
}



const dnx_data_field_fem_key_select_properties_t *
dnx_data_field_fem_key_select_properties_get(
    int unit,
    int field_io)
{
    char *data;
    dnxc_data_table_t *table;

    
    table = dnxc_data_mgmt_table_get(unit, dnx_data_module_field, dnx_data_field_submodule_fem, dnx_data_field_fem_table_key_select_properties);
    
    data = dnxc_data_mgmt_table_data_get(unit, table, field_io, 0);
    return (const dnx_data_field_fem_key_select_properties_t *) data;

}


shr_error_e
dnx_data_field_fem_key_select_properties_entry_str_get(
    int unit,
    char *buffer,
    int key0,
    int key1,
    int value_index)
{
    dnxc_data_table_t *table;
    const dnx_data_field_fem_key_select_properties_t *data;
    SHR_FUNC_INIT_VARS(unit);

    
    table = dnxc_data_mgmt_table_get(unit, dnx_data_module_field, dnx_data_field_submodule_fem, dnx_data_field_fem_table_key_select_properties);
    data = (const dnx_data_field_fem_key_select_properties_t *) dnxc_data_mgmt_table_data_diag_get(unit, table, key0, 0);
    switch (value_index)
    {
        case 0:
            DNXC_DATA_MGMT_ARR_STR(buffer, DNX_DATA_MAX_FIELD_FEM_MAX_NOF_KEY_SELECTS_PER_FIELD_IO, data->key_select);
            break;
        case 1:
            DNXC_DATA_MGMT_ARR_STR(buffer, DNX_DATA_MAX_FIELD_FEM_MAX_NOF_KEY_SELECTS_PER_FIELD_IO, data->num_bits);
            break;
        case 2:
            DNXC_DATA_MGMT_ARR_STR(buffer, DNX_DATA_MAX_FIELD_FEM_MAX_NOF_KEY_SELECTS_PER_FIELD_IO, data->lsb);
            break;
        case 3:
            DNXC_DATA_MGMT_ARR_STR(buffer, DNX_DATA_MAX_FIELD_FEM_MAX_NOF_KEY_SELECTS_PER_FIELD_IO, data->num_bits_not_on_key);
            break;
    }

    SHR_FUNC_EXIT;
}


const dnxc_data_table_info_t *
dnx_data_field_fem_key_select_properties_info_get(
    int unit)
{

    
    return dnxc_data_mgmt_table_info_get(unit, dnx_data_module_field, dnx_data_field_submodule_fem, dnx_data_field_fem_table_key_select_properties);

}






static shr_error_e
dnx_data_field_context_init(
    int unit,
    dnxc_data_submodule_t *submodule_data)
{
    SHR_FUNC_INIT_VARS(unit);

    submodule_data->name = "context";
    submodule_data->doc = "Field Context";
    
    submodule_data->nof_features = _dnx_data_field_context_feature_nof;
    DNXC_DATA_ALLOC(submodule_data->features, dnxc_data_feature_t,  submodule_data->nof_features, "_dnxc_data field context features");

    
    submodule_data->nof_defines = _dnx_data_field_context_define_nof;
    DNXC_DATA_ALLOC(submodule_data->defines, dnxc_data_define_t, submodule_data->nof_defines, "_dnxc_data field context defines");

    submodule_data->defines[dnx_data_field_context_define_default_context].name = "default_context";
    submodule_data->defines[dnx_data_field_context_define_default_context].doc = "Default Context Id (used for Ethernet Packets)";
    
    submodule_data->defines[dnx_data_field_context_define_default_context].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_context_define_default_ftmh_mc_context].name = "default_ftmh_mc_context";
    submodule_data->defines[dnx_data_field_context_define_default_ftmh_mc_context].doc = "Default Context Id for multicast Packets";
    
    submodule_data->defines[dnx_data_field_context_define_default_ftmh_mc_context].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_context_define_default_itmh_context].name = "default_itmh_context";
    submodule_data->defines[dnx_data_field_context_define_default_itmh_context].doc = "Default Context Id for ITMH Packets";
    
    submodule_data->defines[dnx_data_field_context_define_default_itmh_context].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_context_define_default_itmh_pph_context].name = "default_itmh_pph_context";
    submodule_data->defines[dnx_data_field_context_define_default_itmh_pph_context].doc = "Default Context Id for ITMH_PPH Packets";
    
    submodule_data->defines[dnx_data_field_context_define_default_itmh_pph_context].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_context_define_default_itmh_pph_fhei_context].name = "default_itmh_pph_fhei_context";
    submodule_data->defines[dnx_data_field_context_define_default_itmh_pph_fhei_context].doc = "Default Context Id for ITMH_PPH_FHEI Packets";
    
    submodule_data->defines[dnx_data_field_context_define_default_itmh_pph_fhei_context].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_context_define_default_itmh_1588_tsh_context].name = "default_itmh_1588_tsh_context";
    submodule_data->defines[dnx_data_field_context_define_default_itmh_1588_tsh_context].doc = "Default Context Id for ITMH_1588v2_TSH Packets";
    
    submodule_data->defines[dnx_data_field_context_define_default_itmh_1588_tsh_context].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_context_define_default_j1_itmh_context].name = "default_j1_itmh_context";
    submodule_data->defines[dnx_data_field_context_define_default_j1_itmh_context].doc = "Default Context Id for J1 ITMH Packets";
    
    submodule_data->defines[dnx_data_field_context_define_default_j1_itmh_context].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_context_define_default_j1_itmh_pph_context].name = "default_j1_itmh_pph_context";
    submodule_data->defines[dnx_data_field_context_define_default_j1_itmh_pph_context].doc = "Default Context Id for J1 ITMH_PPH Packets";
    
    submodule_data->defines[dnx_data_field_context_define_default_j1_itmh_pph_context].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_context_define_default_oam_context].name = "default_oam_context";
    submodule_data->defines[dnx_data_field_context_define_default_oam_context].doc = "Default Context Id for OAM Packets";
    
    submodule_data->defines[dnx_data_field_context_define_default_oam_context].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_context_define_default_oam_reflector_context].name = "default_oam_reflector_context";
    submodule_data->defines[dnx_data_field_context_define_default_oam_reflector_context].doc = "Default Context Id for OAM downmep reflector Packets";
    
    submodule_data->defines[dnx_data_field_context_define_default_oam_reflector_context].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_context_define_default_oam_upmep_context].name = "default_oam_upmep_context";
    submodule_data->defines[dnx_data_field_context_define_default_oam_upmep_context].doc = "Default Context Id for OAM upmep Packets";
    
    submodule_data->defines[dnx_data_field_context_define_default_oam_upmep_context].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_context_define_default_j1_learning_2ndpass_context].name = "default_j1_learning_2ndpass_context";
    submodule_data->defines[dnx_data_field_context_define_default_j1_learning_2ndpass_context].doc = "Default Context Id for 2nd pass of J1 Learning flow";
    
    submodule_data->defines[dnx_data_field_context_define_default_j1_learning_2ndpass_context].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_context_define_default_rch_remove_context].name = "default_rch_remove_context";
    submodule_data->defines[dnx_data_field_context_define_default_rch_remove_context].doc = "Default Context Id for packets with RCH header.";
    
    submodule_data->defines[dnx_data_field_context_define_default_rch_remove_context].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_context_define_default_rch_extended_encap_context].name = "default_rch_extended_encap_context";
    submodule_data->defines[dnx_data_field_context_define_default_rch_extended_encap_context].doc = "Default Context Id for packets of RCH extended encapsulation application";
    
    submodule_data->defines[dnx_data_field_context_define_default_rch_extended_encap_context].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_context_define_default_nat_context].name = "default_nat_context";
    submodule_data->defines[dnx_data_field_context_define_default_nat_context].doc = "Default Context Id for NAT packets.";
    
    submodule_data->defines[dnx_data_field_context_define_default_nat_context].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_context_define_nof_hash_keys].name = "nof_hash_keys";
    submodule_data->defines[dnx_data_field_context_define_nof_hash_keys].doc = "Number of action keys per Hash Context.";
    
    submodule_data->defines[dnx_data_field_context_define_nof_hash_keys].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_context_define_default_itmh_pph_fhei_vlan_ipmf2_context].name = "default_itmh_pph_fhei_vlan_ipmf2_context";
    submodule_data->defines[dnx_data_field_context_define_default_itmh_pph_fhei_vlan_ipmf2_context].doc = "IPMF2 Context Id for FHEI_VLANoPPHoITMH Packets";
    
    submodule_data->defines[dnx_data_field_context_define_default_itmh_pph_fhei_vlan_ipmf2_context].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_context_define_default_itmh_pph_lif_ipmf2_context].name = "default_itmh_pph_lif_ipmf2_context";
    submodule_data->defines[dnx_data_field_context_define_default_itmh_pph_lif_ipmf2_context].doc = "IPMF2 ITMH Context Id for LIFoPPHoITMH Packets";
    
    submodule_data->defines[dnx_data_field_context_define_default_itmh_pph_lif_ipmf2_context].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_context_define_default_itmh_pph_fhei_lif_ipmf2_context].name = "default_itmh_pph_fhei_lif_ipmf2_context";
    submodule_data->defines[dnx_data_field_context_define_default_itmh_pph_fhei_lif_ipmf2_context].doc = "IPMF2 ITMH Context Id for LIFoFHEIoPPHoITMH Packets";
    
    submodule_data->defines[dnx_data_field_context_define_default_itmh_pph_fhei_lif_ipmf2_context].flags |= DNXC_DATA_F_DEFINE;

    
    submodule_data->nof_tables = _dnx_data_field_context_table_nof;
    DNXC_DATA_ALLOC(submodule_data->tables, dnxc_data_table_t, submodule_data->nof_tables, "_dnxc_data field context tables");


exit:
    SHR_FUNC_EXIT;
}


int
dnx_data_field_context_feature_get(
    int unit,
    dnx_data_field_context_feature_e feature)
{
    return dnxc_data_mgmt_feature_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_context, feature);
}


uint32
dnx_data_field_context_default_context_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_context, dnx_data_field_context_define_default_context);
}

uint32
dnx_data_field_context_default_ftmh_mc_context_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_context, dnx_data_field_context_define_default_ftmh_mc_context);
}

uint32
dnx_data_field_context_default_itmh_context_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_context, dnx_data_field_context_define_default_itmh_context);
}

uint32
dnx_data_field_context_default_itmh_pph_context_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_context, dnx_data_field_context_define_default_itmh_pph_context);
}

uint32
dnx_data_field_context_default_itmh_pph_fhei_context_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_context, dnx_data_field_context_define_default_itmh_pph_fhei_context);
}

uint32
dnx_data_field_context_default_itmh_1588_tsh_context_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_context, dnx_data_field_context_define_default_itmh_1588_tsh_context);
}

uint32
dnx_data_field_context_default_j1_itmh_context_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_context, dnx_data_field_context_define_default_j1_itmh_context);
}

uint32
dnx_data_field_context_default_j1_itmh_pph_context_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_context, dnx_data_field_context_define_default_j1_itmh_pph_context);
}

uint32
dnx_data_field_context_default_oam_context_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_context, dnx_data_field_context_define_default_oam_context);
}

uint32
dnx_data_field_context_default_oam_reflector_context_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_context, dnx_data_field_context_define_default_oam_reflector_context);
}

uint32
dnx_data_field_context_default_oam_upmep_context_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_context, dnx_data_field_context_define_default_oam_upmep_context);
}

uint32
dnx_data_field_context_default_j1_learning_2ndpass_context_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_context, dnx_data_field_context_define_default_j1_learning_2ndpass_context);
}

uint32
dnx_data_field_context_default_rch_remove_context_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_context, dnx_data_field_context_define_default_rch_remove_context);
}

uint32
dnx_data_field_context_default_rch_extended_encap_context_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_context, dnx_data_field_context_define_default_rch_extended_encap_context);
}

uint32
dnx_data_field_context_default_nat_context_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_context, dnx_data_field_context_define_default_nat_context);
}

uint32
dnx_data_field_context_nof_hash_keys_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_context, dnx_data_field_context_define_nof_hash_keys);
}

uint32
dnx_data_field_context_default_itmh_pph_fhei_vlan_ipmf2_context_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_context, dnx_data_field_context_define_default_itmh_pph_fhei_vlan_ipmf2_context);
}

uint32
dnx_data_field_context_default_itmh_pph_lif_ipmf2_context_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_context, dnx_data_field_context_define_default_itmh_pph_lif_ipmf2_context);
}

uint32
dnx_data_field_context_default_itmh_pph_fhei_lif_ipmf2_context_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_context, dnx_data_field_context_define_default_itmh_pph_fhei_lif_ipmf2_context);
}










static shr_error_e
dnx_data_field_preselector_init(
    int unit,
    dnxc_data_submodule_t *submodule_data)
{
    SHR_FUNC_INIT_VARS(unit);

    submodule_data->name = "preselector";
    submodule_data->doc = "Field Presel";
    
    submodule_data->nof_features = _dnx_data_field_preselector_feature_nof;
    DNXC_DATA_ALLOC(submodule_data->features, dnxc_data_feature_t,  submodule_data->nof_features, "_dnxc_data field preselector features");

    
    submodule_data->nof_defines = _dnx_data_field_preselector_define_nof;
    DNXC_DATA_ALLOC(submodule_data->defines, dnxc_data_define_t, submodule_data->nof_defines, "_dnxc_data field preselector defines");

    submodule_data->defines[dnx_data_field_preselector_define_default_ftmh_mc_presel_id_ipmf1].name = "default_ftmh_mc_presel_id_ipmf1";
    submodule_data->defines[dnx_data_field_preselector_define_default_ftmh_mc_presel_id_ipmf1].doc = "Default Presel Id in iPMF1 for multicast Packets";
    
    submodule_data->defines[dnx_data_field_preselector_define_default_ftmh_mc_presel_id_ipmf1].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_preselector_define_default_itmh_presel_id_ipmf1].name = "default_itmh_presel_id_ipmf1";
    submodule_data->defines[dnx_data_field_preselector_define_default_itmh_presel_id_ipmf1].doc = "Default Presel Id in iPMF1 for ITMH injected Packets";
    
    submodule_data->defines[dnx_data_field_preselector_define_default_itmh_presel_id_ipmf1].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_preselector_define_default_itmh_pph_presel_id_ipmf1].name = "default_itmh_pph_presel_id_ipmf1";
    submodule_data->defines[dnx_data_field_preselector_define_default_itmh_pph_presel_id_ipmf1].doc = "Default Presel Id in iPMF1 for PPHoITMH injected Packets";
    
    submodule_data->defines[dnx_data_field_preselector_define_default_itmh_pph_presel_id_ipmf1].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_preselector_define_default_itmh_pph_fhei_presel_id_ipmf1].name = "default_itmh_pph_fhei_presel_id_ipmf1";
    submodule_data->defines[dnx_data_field_preselector_define_default_itmh_pph_fhei_presel_id_ipmf1].doc = "Default Presel Id in iPMF1 for FHEI(5B)oPPHoITMH injected Packets";
    
    submodule_data->defines[dnx_data_field_preselector_define_default_itmh_pph_fhei_presel_id_ipmf1].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_preselector_define_default_itmh_1588_tsh_presel_id_ipmf1].name = "default_itmh_1588_tsh_presel_id_ipmf1";
    submodule_data->defines[dnx_data_field_preselector_define_default_itmh_1588_tsh_presel_id_ipmf1].doc = "Default Presel Id in iPMF1 for TSHoASE-1588v2oITMH injected Packets";
    
    submodule_data->defines[dnx_data_field_preselector_define_default_itmh_1588_tsh_presel_id_ipmf1].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_preselector_define_default_itmh_pph_oamp_presel_id_ipmf1].name = "default_itmh_pph_oamp_presel_id_ipmf1";
    submodule_data->defines[dnx_data_field_preselector_define_default_itmh_pph_oamp_presel_id_ipmf1].doc = "Default Presel Id in iPMF1 for ITMH_J2oPPH_J2 injected Packets from OAMP";
    
    submodule_data->defines[dnx_data_field_preselector_define_default_itmh_pph_oamp_presel_id_ipmf1].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_preselector_define_default_j1_itmh_presel_id_ipmf1].name = "default_j1_itmh_presel_id_ipmf1";
    submodule_data->defines[dnx_data_field_preselector_define_default_j1_itmh_presel_id_ipmf1].doc = "Default Presel Id in iPMF1 for ITMH_J1 injected Packets";
    
    submodule_data->defines[dnx_data_field_preselector_define_default_j1_itmh_presel_id_ipmf1].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_preselector_define_default_j1_itmh_pph_presel_id_ipmf1].name = "default_j1_itmh_pph_presel_id_ipmf1";
    submodule_data->defines[dnx_data_field_preselector_define_default_j1_itmh_pph_presel_id_ipmf1].doc = "Default Presel Id in iPMF1 for ITMH_J1oPPH_J1 injected Packets";
    
    submodule_data->defines[dnx_data_field_preselector_define_default_j1_itmh_pph_presel_id_ipmf1].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_preselector_define_default_j1_itmh_pph_oamp_presel_id_ipmf1].name = "default_j1_itmh_pph_oamp_presel_id_ipmf1";
    submodule_data->defines[dnx_data_field_preselector_define_default_j1_itmh_pph_oamp_presel_id_ipmf1].doc = "Default Presel Id in iPMF1 for ITMH_J1oPPH_J1 injected Packets from OAMP";
    
    submodule_data->defines[dnx_data_field_preselector_define_default_j1_itmh_pph_oamp_presel_id_ipmf1].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_preselector_define_default_j1_learn_presel_id_1st_pass_ipmf1].name = "default_j1_learn_presel_id_1st_pass_ipmf1";
    submodule_data->defines[dnx_data_field_preselector_define_default_j1_learn_presel_id_1st_pass_ipmf1].doc = "Default Presel in iPMF1 Learn 1st Pass";
    
    submodule_data->defines[dnx_data_field_preselector_define_default_j1_learn_presel_id_1st_pass_ipmf1].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_preselector_define_default_j1_learn_presel_id_2nd_pass_ipmf1].name = "default_j1_learn_presel_id_2nd_pass_ipmf1";
    submodule_data->defines[dnx_data_field_preselector_define_default_j1_learn_presel_id_2nd_pass_ipmf1].doc = "Default Presel in iPMF1 Learn 2nd Pass";
    
    submodule_data->defines[dnx_data_field_preselector_define_default_j1_learn_presel_id_2nd_pass_ipmf1].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_preselector_define_default_nat_presel_id_ipmf1].name = "default_nat_presel_id_ipmf1";
    submodule_data->defines[dnx_data_field_preselector_define_default_nat_presel_id_ipmf1].doc = "Default Presel in iPMF1 NAT";
    
    submodule_data->defines[dnx_data_field_preselector_define_default_nat_presel_id_ipmf1].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_preselector_define_default_itmh_pph_fhei_vlan_presel_id_ipmf2].name = "default_itmh_pph_fhei_vlan_presel_id_ipmf2";
    submodule_data->defines[dnx_data_field_preselector_define_default_itmh_pph_fhei_vlan_presel_id_ipmf2].doc = "Default Presel Id in iPMF2 for FHEI_VLANoPPHoITMH injected Packets";
    
    submodule_data->defines[dnx_data_field_preselector_define_default_itmh_pph_fhei_vlan_presel_id_ipmf2].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_preselector_define_default_itmh_pph_lif_presel_id_ipmf2].name = "default_itmh_pph_lif_presel_id_ipmf2";
    submodule_data->defines[dnx_data_field_preselector_define_default_itmh_pph_lif_presel_id_ipmf2].doc = "Default Presel Id in iPMF2 for LIFoPPHoITMH injected Packets";
    
    submodule_data->defines[dnx_data_field_preselector_define_default_itmh_pph_lif_presel_id_ipmf2].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_preselector_define_default_itmh_pph_fhei_lif_presel_id_ipmf2].name = "default_itmh_pph_fhei_lif_presel_id_ipmf2";
    submodule_data->defines[dnx_data_field_preselector_define_default_itmh_pph_fhei_lif_presel_id_ipmf2].doc = "Default Presel Id in iPMF2 for LIFoFHEIoPPHoITMH injected Packets";
    
    submodule_data->defines[dnx_data_field_preselector_define_default_itmh_pph_fhei_lif_presel_id_ipmf2].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_preselector_define_srv6_endpoint_psp_presel_id_ipmf1].name = "srv6_endpoint_psp_presel_id_ipmf1";
    submodule_data->defines[dnx_data_field_preselector_define_srv6_endpoint_psp_presel_id_ipmf1].doc = "Default Presel in iPMF1 Id for endpoint_psp";
    
    submodule_data->defines[dnx_data_field_preselector_define_srv6_endpoint_psp_presel_id_ipmf1].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_preselector_define_srv6_endpoint_psp_extended_cut_presel_id_ipmf1].name = "srv6_endpoint_psp_extended_cut_presel_id_ipmf1";
    submodule_data->defines[dnx_data_field_preselector_define_srv6_endpoint_psp_extended_cut_presel_id_ipmf1].doc = "Default Presel Id in iPMF1 Id for endpoint_psp_extended";
    
    submodule_data->defines[dnx_data_field_preselector_define_srv6_endpoint_psp_extended_cut_presel_id_ipmf1].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_preselector_define_srv6_endpoint_psp_extended_cut_presel_id_ipmf2].name = "srv6_endpoint_psp_extended_cut_presel_id_ipmf2";
    submodule_data->defines[dnx_data_field_preselector_define_srv6_endpoint_psp_extended_cut_presel_id_ipmf2].doc = "Default Presel Id in iPMF2 Id for none global PSP mode Endpoint Packet";
    
    submodule_data->defines[dnx_data_field_preselector_define_srv6_endpoint_psp_extended_cut_presel_id_ipmf2].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_preselector_define_srv6_endpoint_usp_extended_cut_presel_id_ipmf1].name = "srv6_endpoint_usp_extended_cut_presel_id_ipmf1";
    submodule_data->defines[dnx_data_field_preselector_define_srv6_endpoint_usp_extended_cut_presel_id_ipmf1].doc = "Default Presel Id in iPMF1 Id for egress_usp_extended";
    
    submodule_data->defines[dnx_data_field_preselector_define_srv6_endpoint_usp_extended_cut_presel_id_ipmf1].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_preselector_define_srv6_endpoint_usp_extended_cut_trap_presel_id_ipmf1].name = "srv6_endpoint_usp_extended_cut_trap_presel_id_ipmf1";
    submodule_data->defines[dnx_data_field_preselector_define_srv6_endpoint_usp_extended_cut_trap_presel_id_ipmf1].doc = "Default Presel Id in iPMF1 Id for trap egress_usp_extended";
    
    submodule_data->defines[dnx_data_field_preselector_define_srv6_endpoint_usp_extended_cut_trap_presel_id_ipmf1].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_preselector_define_srv6_endpoint_usp_extended_cut_icmp_presel_id_ipmf1].name = "srv6_endpoint_usp_extended_cut_icmp_presel_id_ipmf1";
    submodule_data->defines[dnx_data_field_preselector_define_srv6_endpoint_usp_extended_cut_icmp_presel_id_ipmf1].doc = "Default Presel Id in iPMF1 Id for icmp trap egress_usp_extended";
    
    submodule_data->defines[dnx_data_field_preselector_define_srv6_endpoint_usp_extended_cut_icmp_presel_id_ipmf1].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_preselector_define_srv6_egress_usd_eth_presel_id_ipmf1].name = "srv6_egress_usd_eth_presel_id_ipmf1";
    submodule_data->defines[dnx_data_field_preselector_define_srv6_egress_usd_eth_presel_id_ipmf1].doc = "Default Presel in iPMF1 Id for egress_usd eth";
    
    submodule_data->defines[dnx_data_field_preselector_define_srv6_egress_usd_eth_presel_id_ipmf1].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_preselector_define_srv6_egress_usd_ipv4_presel_id_ipmf1].name = "srv6_egress_usd_ipv4_presel_id_ipmf1";
    submodule_data->defines[dnx_data_field_preselector_define_srv6_egress_usd_ipv4_presel_id_ipmf1].doc = "Default Presel in iPMF1 Id for egress_usd ipv4";
    
    submodule_data->defines[dnx_data_field_preselector_define_srv6_egress_usd_ipv4_presel_id_ipmf1].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_preselector_define_srv6_egress_usd_ipv6_presel_id_ipmf1].name = "srv6_egress_usd_ipv6_presel_id_ipmf1";
    submodule_data->defines[dnx_data_field_preselector_define_srv6_egress_usd_ipv6_presel_id_ipmf1].doc = "Default Presel in iPMF1 Id for egress_usd ipv6";
    
    submodule_data->defines[dnx_data_field_preselector_define_srv6_egress_usd_ipv6_presel_id_ipmf1].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_preselector_define_srv6_egress_usd_mpls_presel_id_ipmf1].name = "srv6_egress_usd_mpls_presel_id_ipmf1";
    submodule_data->defines[dnx_data_field_preselector_define_srv6_egress_usd_mpls_presel_id_ipmf1].doc = "Default Presel in iPMF1 Id for egress_usd mpls";
    
    submodule_data->defines[dnx_data_field_preselector_define_srv6_egress_usd_mpls_presel_id_ipmf1].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_preselector_define_srv6_endpoint_usid_presel_id_ipmf1].name = "srv6_endpoint_usid_presel_id_ipmf1";
    submodule_data->defines[dnx_data_field_preselector_define_srv6_endpoint_usid_presel_id_ipmf1].doc = "Default Presel in iPMF1 Id for endpoint_usid";
    
    submodule_data->defines[dnx_data_field_preselector_define_srv6_endpoint_usid_presel_id_ipmf1].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_preselector_define_srv6_endpoint_gsid_presel_id_ipmf1].name = "srv6_endpoint_gsid_presel_id_ipmf1";
    submodule_data->defines[dnx_data_field_preselector_define_srv6_endpoint_gsid_presel_id_ipmf1].doc = "Default Presel in iPMF1 Id for endpoint_gsid";
    
    submodule_data->defines[dnx_data_field_preselector_define_srv6_endpoint_gsid_presel_id_ipmf1].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_preselector_define_srv6_egress_usp_presel_id_ipmf1].name = "srv6_egress_usp_presel_id_ipmf1";
    submodule_data->defines[dnx_data_field_preselector_define_srv6_egress_usp_presel_id_ipmf1].doc = "Default Presel Id in iPMF1 Id for egress usp";
    
    submodule_data->defines[dnx_data_field_preselector_define_srv6_egress_usp_presel_id_ipmf1].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_preselector_define_srv6_egress_usp_trap_presel_id_ipmf1].name = "srv6_egress_usp_trap_presel_id_ipmf1";
    submodule_data->defines[dnx_data_field_preselector_define_srv6_egress_usp_trap_presel_id_ipmf1].doc = "Default Presel Id in iPMF1 Id for egress usp when destination is PspUSP trap";
    
    submodule_data->defines[dnx_data_field_preselector_define_srv6_egress_usp_trap_presel_id_ipmf1].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_preselector_define_srv6_egress_usp_fwd_trap_presel_id_ipmf1].name = "srv6_egress_usp_fwd_trap_presel_id_ipmf1";
    submodule_data->defines[dnx_data_field_preselector_define_srv6_egress_usp_fwd_trap_presel_id_ipmf1].doc = "Default Presel Id in iPMF1 Id for egress usp when we have PsPUSP trap, used in 2nd pass fwd";
    
    submodule_data->defines[dnx_data_field_preselector_define_srv6_egress_usp_fwd_trap_presel_id_ipmf1].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_preselector_define_srv6_egress_usp_icmp_presel_id_ipmf1].name = "srv6_egress_usp_icmp_presel_id_ipmf1";
    submodule_data->defines[dnx_data_field_preselector_define_srv6_egress_usp_icmp_presel_id_ipmf1].doc = "Default Presel Id in iPMF1 Id for egress usp when destination is ICMP trap";
    
    submodule_data->defines[dnx_data_field_preselector_define_srv6_egress_usp_icmp_presel_id_ipmf1].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_preselector_define_mpls_bier_presel_id_ipmf1].name = "mpls_bier_presel_id_ipmf1";
    submodule_data->defines[dnx_data_field_preselector_define_mpls_bier_presel_id_ipmf1].doc = "Default Presel Id in iPMF1 Id for MPLS BIER";
    
    submodule_data->defines[dnx_data_field_preselector_define_mpls_bier_presel_id_ipmf1].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_preselector_define_default_itmh_pph_presel_id_ipmf3].name = "default_itmh_pph_presel_id_ipmf3";
    submodule_data->defines[dnx_data_field_preselector_define_default_itmh_pph_presel_id_ipmf3].doc = "Default Presel Id in iPMF1 for ITMHoPPH injected Packets";
    
    submodule_data->defines[dnx_data_field_preselector_define_default_itmh_pph_presel_id_ipmf3].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_preselector_define_default_itmh_pph_presel_id_2nd_ipmf3].name = "default_itmh_pph_presel_id_2nd_ipmf3";
    submodule_data->defines[dnx_data_field_preselector_define_default_itmh_pph_presel_id_2nd_ipmf3].doc = "Default 2nd Presel Id in iPMF1 for ITMHoPPH injected Packets";
    
    submodule_data->defines[dnx_data_field_preselector_define_default_itmh_pph_presel_id_2nd_ipmf3].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_preselector_define_default_itmh_pph_presel_id_vlan_ipmf3].name = "default_itmh_pph_presel_id_vlan_ipmf3";
    submodule_data->defines[dnx_data_field_preselector_define_default_itmh_pph_presel_id_vlan_ipmf3].doc = "Default Presel Id in iPMF1 for ITMHoPPHoFHEI-Vlan injected Packets";
    
    submodule_data->defines[dnx_data_field_preselector_define_default_itmh_pph_presel_id_vlan_ipmf3].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_preselector_define_default_j1_itmh_pph_presel_id_ipmf3].name = "default_j1_itmh_pph_presel_id_ipmf3";
    submodule_data->defines[dnx_data_field_preselector_define_default_j1_itmh_pph_presel_id_ipmf3].doc = "Default Presel Id in iPMF1 for ITMH_J1oPPH_J1 injected Packets";
    
    submodule_data->defines[dnx_data_field_preselector_define_default_j1_itmh_pph_presel_id_ipmf3].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_preselector_define_default_ftmh_mc_presel_id_ipmf3].name = "default_ftmh_mc_presel_id_ipmf3";
    submodule_data->defines[dnx_data_field_preselector_define_default_ftmh_mc_presel_id_ipmf3].doc = "Default Presel Id in iPMF3 for multicast Packets";
    
    submodule_data->defines[dnx_data_field_preselector_define_default_ftmh_mc_presel_id_ipmf3].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_preselector_define_default_oam_roo_ipv4_presel_id_ipmf3].name = "default_oam_roo_ipv4_presel_id_ipmf3";
    submodule_data->defines[dnx_data_field_preselector_define_default_oam_roo_ipv4_presel_id_ipmf3].doc = "Default Presel in iPMF3 Id for IPv4 with ROO Packets";
    
    submodule_data->defines[dnx_data_field_preselector_define_default_oam_roo_ipv4_presel_id_ipmf3].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_preselector_define_default_oam_roo_ipv6_presel_id_ipmf3].name = "default_oam_roo_ipv6_presel_id_ipmf3";
    submodule_data->defines[dnx_data_field_preselector_define_default_oam_roo_ipv6_presel_id_ipmf3].doc = "Default Presel in iPMF3 Id for IPv6 with ROO Packets";
    
    submodule_data->defines[dnx_data_field_preselector_define_default_oam_roo_ipv6_presel_id_ipmf3].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_preselector_define_default_oam_w_o_roo_no_rif_ipv4_presel_id_ipmf3].name = "default_oam_w_o_roo_no_rif_ipv4_presel_id_ipmf3";
    submodule_data->defines[dnx_data_field_preselector_define_default_oam_w_o_roo_no_rif_ipv4_presel_id_ipmf3].doc = "Default Presel in iPMF3 Id for IPv4 without ROO Packets no RIF";
    
    submodule_data->defines[dnx_data_field_preselector_define_default_oam_w_o_roo_no_rif_ipv4_presel_id_ipmf3].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_preselector_define_default_oam_w_o_roo_no_rif_ipv6_presel_id_ipmf3].name = "default_oam_w_o_roo_no_rif_ipv6_presel_id_ipmf3";
    submodule_data->defines[dnx_data_field_preselector_define_default_oam_w_o_roo_no_rif_ipv6_presel_id_ipmf3].doc = "Default Presel in iPMF3 Id for IPv6 without ROO Packets no RIF";
    
    submodule_data->defines[dnx_data_field_preselector_define_default_oam_w_o_roo_no_rif_ipv6_presel_id_ipmf3].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_preselector_define_default_oam_w_o_roo_with_rif_ipv4_presel_id_ipmf3].name = "default_oam_w_o_roo_with_rif_ipv4_presel_id_ipmf3";
    submodule_data->defines[dnx_data_field_preselector_define_default_oam_w_o_roo_with_rif_ipv4_presel_id_ipmf3].doc = "Default Presel in iPMF3 Id for IPv4 without ROO Packets with RIF";
    
    submodule_data->defines[dnx_data_field_preselector_define_default_oam_w_o_roo_with_rif_ipv4_presel_id_ipmf3].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_preselector_define_default_oam_w_o_roo_with_rif_ipv6_presel_id_ipmf3].name = "default_oam_w_o_roo_with_rif_ipv6_presel_id_ipmf3";
    submodule_data->defines[dnx_data_field_preselector_define_default_oam_w_o_roo_with_rif_ipv6_presel_id_ipmf3].doc = "Default Presel in iPMF3 Id for IPv6 without ROO Packets with RIF";
    
    submodule_data->defines[dnx_data_field_preselector_define_default_oam_w_o_roo_with_rif_ipv6_presel_id_ipmf3].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_preselector_define_default_j1_ipv4_mc_in_lif_presel_id_ipmf3].name = "default_j1_ipv4_mc_in_lif_presel_id_ipmf3";
    submodule_data->defines[dnx_data_field_preselector_define_default_j1_ipv4_mc_in_lif_presel_id_ipmf3].doc = "Default Presel in iPMF3 Id for IPv4 MC Packets";
    
    submodule_data->defines[dnx_data_field_preselector_define_default_j1_ipv4_mc_in_lif_presel_id_ipmf3].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_preselector_define_default_j1_ipv6_mc_in_lif_presel_id_ipmf3].name = "default_j1_ipv6_mc_in_lif_presel_id_ipmf3";
    submodule_data->defines[dnx_data_field_preselector_define_default_j1_ipv6_mc_in_lif_presel_id_ipmf3].doc = "Default Presel in iPMF3 Id for IPv6 MC Packets";
    
    submodule_data->defines[dnx_data_field_preselector_define_default_j1_ipv6_mc_in_lif_presel_id_ipmf3].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_preselector_define_default_rch_remove_presel_id_ipmf3].name = "default_rch_remove_presel_id_ipmf3";
    submodule_data->defines[dnx_data_field_preselector_define_default_rch_remove_presel_id_ipmf3].doc = "Default Presel in iPMF3 Id for packets with RCH header";
    
    submodule_data->defines[dnx_data_field_preselector_define_default_rch_remove_presel_id_ipmf3].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_preselector_define_default_rch_extended_encap_presel_id_ipmf3].name = "default_rch_extended_encap_presel_id_ipmf3";
    submodule_data->defines[dnx_data_field_preselector_define_default_rch_extended_encap_presel_id_ipmf3].doc = "Default Presel in iPMF3 Id for RCH extended encapsulation application";
    
    submodule_data->defines[dnx_data_field_preselector_define_default_rch_extended_encap_presel_id_ipmf3].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_preselector_define_default_j1_php_presel_id_ipmf3].name = "default_j1_php_presel_id_ipmf3";
    submodule_data->defines[dnx_data_field_preselector_define_default_j1_php_presel_id_ipmf3].doc = "Default Presel in iPMF3 Id for MPLS PHP Packets";
    
    submodule_data->defines[dnx_data_field_preselector_define_default_j1_php_presel_id_ipmf3].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_preselector_define_default_j1_swap_presel_id_ipmf3].name = "default_j1_swap_presel_id_ipmf3";
    submodule_data->defines[dnx_data_field_preselector_define_default_j1_swap_presel_id_ipmf3].doc = "Default Presel in iPMF3 Id for MPLS SWAP Packets";
    
    submodule_data->defines[dnx_data_field_preselector_define_default_j1_swap_presel_id_ipmf3].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_preselector_define_srv6_partial_fwd_layer_presel_id_ipmf3].name = "srv6_partial_fwd_layer_presel_id_ipmf3";
    submodule_data->defines[dnx_data_field_preselector_define_srv6_partial_fwd_layer_presel_id_ipmf3].doc = "Default Presel in iPMF3 Id for partial_fwd_layer";
    
    submodule_data->defines[dnx_data_field_preselector_define_srv6_partial_fwd_layer_presel_id_ipmf3].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_preselector_define_srv6_endpoint_usid_presel_id_ipmf3].name = "srv6_endpoint_usid_presel_id_ipmf3";
    submodule_data->defines[dnx_data_field_preselector_define_srv6_endpoint_usid_presel_id_ipmf3].doc = "Default Presel in iPMF3 Id for endpoint_usid";
    
    submodule_data->defines[dnx_data_field_preselector_define_srv6_endpoint_usid_presel_id_ipmf3].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_preselector_define_srv6_endpoint_gsid_presel_id_ipmf3].name = "srv6_endpoint_gsid_presel_id_ipmf3";
    submodule_data->defines[dnx_data_field_preselector_define_srv6_endpoint_gsid_presel_id_ipmf3].doc = "Default Presel in iPMF3 Id for endpoint_gsid";
    
    submodule_data->defines[dnx_data_field_preselector_define_srv6_endpoint_gsid_presel_id_ipmf3].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_preselector_define_srv6_endpoint_psp_presel_id_ipmf3].name = "srv6_endpoint_psp_presel_id_ipmf3";
    submodule_data->defines[dnx_data_field_preselector_define_srv6_endpoint_psp_presel_id_ipmf3].doc = "Default Presel in iPMF3 Id for endpoint_psp";
    
    submodule_data->defines[dnx_data_field_preselector_define_srv6_endpoint_psp_presel_id_ipmf3].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_preselector_define_srv6_psp_ext_to_endpoint_presel_id_ipmf3].name = "srv6_psp_ext_to_endpoint_presel_id_ipmf3";
    submodule_data->defines[dnx_data_field_preselector_define_srv6_psp_ext_to_endpoint_presel_id_ipmf3].doc = "Default Presel in iPMF3 Id from psp_ext to endpoint packet";
    
    submodule_data->defines[dnx_data_field_preselector_define_srv6_psp_ext_to_endpoint_presel_id_ipmf3].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_preselector_define_srv6_egress_usp_presel_id_ipmf3].name = "srv6_egress_usp_presel_id_ipmf3";
    submodule_data->defines[dnx_data_field_preselector_define_srv6_egress_usp_presel_id_ipmf3].doc = "Default Presel in iPMF3 Id for egress_usp";
    
    submodule_data->defines[dnx_data_field_preselector_define_srv6_egress_usp_presel_id_ipmf3].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_preselector_define_srv6_endpoint_psp_extended_cut_presel_id_ipmf3].name = "srv6_endpoint_psp_extended_cut_presel_id_ipmf3";
    submodule_data->defines[dnx_data_field_preselector_define_srv6_endpoint_psp_extended_cut_presel_id_ipmf3].doc = "Default Presel Id in iPMF3 Id for endpoint_psp_extended";
    
    submodule_data->defines[dnx_data_field_preselector_define_srv6_endpoint_psp_extended_cut_presel_id_ipmf3].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_preselector_define_srv6_endpoint_usp_extended_cut_presel_id_ipmf3].name = "srv6_endpoint_usp_extended_cut_presel_id_ipmf3";
    submodule_data->defines[dnx_data_field_preselector_define_srv6_endpoint_usp_extended_cut_presel_id_ipmf3].doc = "Default Presel Id in iPMF3 Id for endpoint_psp_extended";
    
    submodule_data->defines[dnx_data_field_preselector_define_srv6_endpoint_usp_extended_cut_presel_id_ipmf3].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_preselector_define_srv6_egress_usd_presel_id_ipmf3].name = "srv6_egress_usd_presel_id_ipmf3";
    submodule_data->defines[dnx_data_field_preselector_define_srv6_egress_usd_presel_id_ipmf3].doc = "Default Presel Id in iPMF3 Id for egress usd";
    
    submodule_data->defines[dnx_data_field_preselector_define_srv6_egress_usd_presel_id_ipmf3].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_preselector_define_mpls_bier_presel_id_ipmf3].name = "mpls_bier_presel_id_ipmf3";
    submodule_data->defines[dnx_data_field_preselector_define_mpls_bier_presel_id_ipmf3].doc = "Default Presel Id in iPMF3 Id for MPLS BIER";
    
    submodule_data->defines[dnx_data_field_preselector_define_mpls_bier_presel_id_ipmf3].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_preselector_define_ebtr_const_fwd_layer_eth_epmf].name = "ebtr_const_fwd_layer_eth_epmf";
    submodule_data->defines[dnx_data_field_preselector_define_ebtr_const_fwd_layer_eth_epmf].doc = "estimated btr value for fwd layer ethernet prsel in ePMF";
    
    submodule_data->defines[dnx_data_field_preselector_define_ebtr_const_fwd_layer_eth_epmf].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_preselector_define_srv6_ext_termination_btr_epmf].name = "srv6_ext_termination_btr_epmf";
    submodule_data->defines[dnx_data_field_preselector_define_srv6_ext_termination_btr_epmf].doc = "estimated btr value for srv6 extended termination in ePMF, using UDH input";
    
    submodule_data->defines[dnx_data_field_preselector_define_srv6_ext_termination_btr_epmf].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_preselector_define_default_j1_same_port_presel_id_epmf].name = "default_j1_same_port_presel_id_epmf";
    submodule_data->defines[dnx_data_field_preselector_define_default_j1_same_port_presel_id_epmf].doc = "Default Presel in ePMF Same port";
    
    submodule_data->defines[dnx_data_field_preselector_define_default_j1_same_port_presel_id_epmf].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_preselector_define_default_learn_limit_presel_id_epmf].name = "default_learn_limit_presel_id_epmf";
    submodule_data->defines[dnx_data_field_preselector_define_default_learn_limit_presel_id_epmf].doc = "Default Presel in ePMF Learn";
    
    submodule_data->defines[dnx_data_field_preselector_define_default_learn_limit_presel_id_epmf].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_preselector_define_srv6_endpoint_hbh_bta_presel_id_epmf].name = "srv6_endpoint_hbh_bta_presel_id_epmf";
    submodule_data->defines[dnx_data_field_preselector_define_srv6_endpoint_hbh_bta_presel_id_epmf].doc = "Default Presel in ePMF Id for endpoint_hbh_bta";
    
    submodule_data->defines[dnx_data_field_preselector_define_srv6_endpoint_hbh_bta_presel_id_epmf].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_preselector_define_srv6_transit_hbh_bta_presel_id_epmf].name = "srv6_transit_hbh_bta_presel_id_epmf";
    submodule_data->defines[dnx_data_field_preselector_define_srv6_transit_hbh_bta_presel_id_epmf].doc = "Default Presel in ePMF Id for Transit_hbh_bta";
    
    submodule_data->defines[dnx_data_field_preselector_define_srv6_transit_hbh_bta_presel_id_epmf].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_preselector_define_srv6_endpoint_psp_bta_presel_id_epmf].name = "srv6_endpoint_psp_bta_presel_id_epmf";
    submodule_data->defines[dnx_data_field_preselector_define_srv6_endpoint_psp_bta_presel_id_epmf].doc = "Default Presel in ePMF Id for endpoint_psp_bta";
    
    submodule_data->defines[dnx_data_field_preselector_define_srv6_endpoint_psp_bta_presel_id_epmf].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_preselector_define_default_mpls_8b_fhei_presel_id_epmf].name = "default_mpls_8b_fhei_presel_id_epmf";
    submodule_data->defines[dnx_data_field_preselector_define_default_mpls_8b_fhei_presel_id_epmf].doc = "Default Presel in ePMF Id for MPLS 8B FHEI";
    
    submodule_data->defines[dnx_data_field_preselector_define_default_mpls_8b_fhei_presel_id_epmf].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_preselector_define_num_cs_inlif_profile_entries].name = "num_cs_inlif_profile_entries";
    submodule_data->defines[dnx_data_field_preselector_define_num_cs_inlif_profile_entries].doc = "The number of CS entries which are used for inlif profile mapping";
    
    submodule_data->defines[dnx_data_field_preselector_define_num_cs_inlif_profile_entries].flags |= DNXC_DATA_F_DEFINE;

    
    submodule_data->nof_tables = _dnx_data_field_preselector_table_nof;
    DNXC_DATA_ALLOC(submodule_data->tables, dnxc_data_table_t, submodule_data->nof_tables, "_dnxc_data field preselector tables");


exit:
    SHR_FUNC_EXIT;
}


int
dnx_data_field_preselector_feature_get(
    int unit,
    dnx_data_field_preselector_feature_e feature)
{
    return dnxc_data_mgmt_feature_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_preselector, feature);
}


uint32
dnx_data_field_preselector_default_ftmh_mc_presel_id_ipmf1_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_preselector, dnx_data_field_preselector_define_default_ftmh_mc_presel_id_ipmf1);
}

uint32
dnx_data_field_preselector_default_itmh_presel_id_ipmf1_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_preselector, dnx_data_field_preselector_define_default_itmh_presel_id_ipmf1);
}

uint32
dnx_data_field_preselector_default_itmh_pph_presel_id_ipmf1_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_preselector, dnx_data_field_preselector_define_default_itmh_pph_presel_id_ipmf1);
}

uint32
dnx_data_field_preselector_default_itmh_pph_fhei_presel_id_ipmf1_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_preselector, dnx_data_field_preselector_define_default_itmh_pph_fhei_presel_id_ipmf1);
}

uint32
dnx_data_field_preselector_default_itmh_1588_tsh_presel_id_ipmf1_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_preselector, dnx_data_field_preselector_define_default_itmh_1588_tsh_presel_id_ipmf1);
}

uint32
dnx_data_field_preselector_default_itmh_pph_oamp_presel_id_ipmf1_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_preselector, dnx_data_field_preselector_define_default_itmh_pph_oamp_presel_id_ipmf1);
}

uint32
dnx_data_field_preselector_default_j1_itmh_presel_id_ipmf1_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_preselector, dnx_data_field_preselector_define_default_j1_itmh_presel_id_ipmf1);
}

uint32
dnx_data_field_preselector_default_j1_itmh_pph_presel_id_ipmf1_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_preselector, dnx_data_field_preselector_define_default_j1_itmh_pph_presel_id_ipmf1);
}

uint32
dnx_data_field_preselector_default_j1_itmh_pph_oamp_presel_id_ipmf1_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_preselector, dnx_data_field_preselector_define_default_j1_itmh_pph_oamp_presel_id_ipmf1);
}

uint32
dnx_data_field_preselector_default_j1_learn_presel_id_1st_pass_ipmf1_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_preselector, dnx_data_field_preselector_define_default_j1_learn_presel_id_1st_pass_ipmf1);
}

uint32
dnx_data_field_preselector_default_j1_learn_presel_id_2nd_pass_ipmf1_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_preselector, dnx_data_field_preselector_define_default_j1_learn_presel_id_2nd_pass_ipmf1);
}

uint32
dnx_data_field_preselector_default_nat_presel_id_ipmf1_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_preselector, dnx_data_field_preselector_define_default_nat_presel_id_ipmf1);
}

uint32
dnx_data_field_preselector_default_itmh_pph_fhei_vlan_presel_id_ipmf2_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_preselector, dnx_data_field_preselector_define_default_itmh_pph_fhei_vlan_presel_id_ipmf2);
}

uint32
dnx_data_field_preselector_default_itmh_pph_lif_presel_id_ipmf2_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_preselector, dnx_data_field_preselector_define_default_itmh_pph_lif_presel_id_ipmf2);
}

uint32
dnx_data_field_preselector_default_itmh_pph_fhei_lif_presel_id_ipmf2_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_preselector, dnx_data_field_preselector_define_default_itmh_pph_fhei_lif_presel_id_ipmf2);
}

uint32
dnx_data_field_preselector_srv6_endpoint_psp_presel_id_ipmf1_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_preselector, dnx_data_field_preselector_define_srv6_endpoint_psp_presel_id_ipmf1);
}

uint32
dnx_data_field_preselector_srv6_endpoint_psp_extended_cut_presel_id_ipmf1_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_preselector, dnx_data_field_preselector_define_srv6_endpoint_psp_extended_cut_presel_id_ipmf1);
}

uint32
dnx_data_field_preselector_srv6_endpoint_psp_extended_cut_presel_id_ipmf2_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_preselector, dnx_data_field_preselector_define_srv6_endpoint_psp_extended_cut_presel_id_ipmf2);
}

uint32
dnx_data_field_preselector_srv6_endpoint_usp_extended_cut_presel_id_ipmf1_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_preselector, dnx_data_field_preselector_define_srv6_endpoint_usp_extended_cut_presel_id_ipmf1);
}

uint32
dnx_data_field_preselector_srv6_endpoint_usp_extended_cut_trap_presel_id_ipmf1_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_preselector, dnx_data_field_preselector_define_srv6_endpoint_usp_extended_cut_trap_presel_id_ipmf1);
}

uint32
dnx_data_field_preselector_srv6_endpoint_usp_extended_cut_icmp_presel_id_ipmf1_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_preselector, dnx_data_field_preselector_define_srv6_endpoint_usp_extended_cut_icmp_presel_id_ipmf1);
}

uint32
dnx_data_field_preselector_srv6_egress_usd_eth_presel_id_ipmf1_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_preselector, dnx_data_field_preselector_define_srv6_egress_usd_eth_presel_id_ipmf1);
}

uint32
dnx_data_field_preselector_srv6_egress_usd_ipv4_presel_id_ipmf1_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_preselector, dnx_data_field_preselector_define_srv6_egress_usd_ipv4_presel_id_ipmf1);
}

uint32
dnx_data_field_preselector_srv6_egress_usd_ipv6_presel_id_ipmf1_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_preselector, dnx_data_field_preselector_define_srv6_egress_usd_ipv6_presel_id_ipmf1);
}

uint32
dnx_data_field_preselector_srv6_egress_usd_mpls_presel_id_ipmf1_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_preselector, dnx_data_field_preselector_define_srv6_egress_usd_mpls_presel_id_ipmf1);
}

uint32
dnx_data_field_preselector_srv6_endpoint_usid_presel_id_ipmf1_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_preselector, dnx_data_field_preselector_define_srv6_endpoint_usid_presel_id_ipmf1);
}

uint32
dnx_data_field_preselector_srv6_endpoint_gsid_presel_id_ipmf1_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_preselector, dnx_data_field_preselector_define_srv6_endpoint_gsid_presel_id_ipmf1);
}

uint32
dnx_data_field_preselector_srv6_egress_usp_presel_id_ipmf1_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_preselector, dnx_data_field_preselector_define_srv6_egress_usp_presel_id_ipmf1);
}

uint32
dnx_data_field_preselector_srv6_egress_usp_trap_presel_id_ipmf1_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_preselector, dnx_data_field_preselector_define_srv6_egress_usp_trap_presel_id_ipmf1);
}

uint32
dnx_data_field_preselector_srv6_egress_usp_fwd_trap_presel_id_ipmf1_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_preselector, dnx_data_field_preselector_define_srv6_egress_usp_fwd_trap_presel_id_ipmf1);
}

uint32
dnx_data_field_preselector_srv6_egress_usp_icmp_presel_id_ipmf1_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_preselector, dnx_data_field_preselector_define_srv6_egress_usp_icmp_presel_id_ipmf1);
}

uint32
dnx_data_field_preselector_mpls_bier_presel_id_ipmf1_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_preselector, dnx_data_field_preselector_define_mpls_bier_presel_id_ipmf1);
}

uint32
dnx_data_field_preselector_default_itmh_pph_presel_id_ipmf3_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_preselector, dnx_data_field_preselector_define_default_itmh_pph_presel_id_ipmf3);
}

uint32
dnx_data_field_preselector_default_itmh_pph_presel_id_2nd_ipmf3_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_preselector, dnx_data_field_preselector_define_default_itmh_pph_presel_id_2nd_ipmf3);
}

uint32
dnx_data_field_preselector_default_itmh_pph_presel_id_vlan_ipmf3_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_preselector, dnx_data_field_preselector_define_default_itmh_pph_presel_id_vlan_ipmf3);
}

uint32
dnx_data_field_preselector_default_j1_itmh_pph_presel_id_ipmf3_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_preselector, dnx_data_field_preselector_define_default_j1_itmh_pph_presel_id_ipmf3);
}

uint32
dnx_data_field_preselector_default_ftmh_mc_presel_id_ipmf3_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_preselector, dnx_data_field_preselector_define_default_ftmh_mc_presel_id_ipmf3);
}

uint32
dnx_data_field_preselector_default_oam_roo_ipv4_presel_id_ipmf3_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_preselector, dnx_data_field_preselector_define_default_oam_roo_ipv4_presel_id_ipmf3);
}

uint32
dnx_data_field_preselector_default_oam_roo_ipv6_presel_id_ipmf3_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_preselector, dnx_data_field_preselector_define_default_oam_roo_ipv6_presel_id_ipmf3);
}

uint32
dnx_data_field_preselector_default_oam_w_o_roo_no_rif_ipv4_presel_id_ipmf3_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_preselector, dnx_data_field_preselector_define_default_oam_w_o_roo_no_rif_ipv4_presel_id_ipmf3);
}

uint32
dnx_data_field_preselector_default_oam_w_o_roo_no_rif_ipv6_presel_id_ipmf3_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_preselector, dnx_data_field_preselector_define_default_oam_w_o_roo_no_rif_ipv6_presel_id_ipmf3);
}

uint32
dnx_data_field_preselector_default_oam_w_o_roo_with_rif_ipv4_presel_id_ipmf3_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_preselector, dnx_data_field_preselector_define_default_oam_w_o_roo_with_rif_ipv4_presel_id_ipmf3);
}

uint32
dnx_data_field_preselector_default_oam_w_o_roo_with_rif_ipv6_presel_id_ipmf3_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_preselector, dnx_data_field_preselector_define_default_oam_w_o_roo_with_rif_ipv6_presel_id_ipmf3);
}

uint32
dnx_data_field_preselector_default_j1_ipv4_mc_in_lif_presel_id_ipmf3_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_preselector, dnx_data_field_preselector_define_default_j1_ipv4_mc_in_lif_presel_id_ipmf3);
}

uint32
dnx_data_field_preselector_default_j1_ipv6_mc_in_lif_presel_id_ipmf3_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_preselector, dnx_data_field_preselector_define_default_j1_ipv6_mc_in_lif_presel_id_ipmf3);
}

uint32
dnx_data_field_preselector_default_rch_remove_presel_id_ipmf3_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_preselector, dnx_data_field_preselector_define_default_rch_remove_presel_id_ipmf3);
}

uint32
dnx_data_field_preselector_default_rch_extended_encap_presel_id_ipmf3_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_preselector, dnx_data_field_preselector_define_default_rch_extended_encap_presel_id_ipmf3);
}

uint32
dnx_data_field_preselector_default_j1_php_presel_id_ipmf3_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_preselector, dnx_data_field_preselector_define_default_j1_php_presel_id_ipmf3);
}

uint32
dnx_data_field_preselector_default_j1_swap_presel_id_ipmf3_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_preselector, dnx_data_field_preselector_define_default_j1_swap_presel_id_ipmf3);
}

uint32
dnx_data_field_preselector_srv6_partial_fwd_layer_presel_id_ipmf3_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_preselector, dnx_data_field_preselector_define_srv6_partial_fwd_layer_presel_id_ipmf3);
}

uint32
dnx_data_field_preselector_srv6_endpoint_usid_presel_id_ipmf3_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_preselector, dnx_data_field_preselector_define_srv6_endpoint_usid_presel_id_ipmf3);
}

uint32
dnx_data_field_preselector_srv6_endpoint_gsid_presel_id_ipmf3_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_preselector, dnx_data_field_preselector_define_srv6_endpoint_gsid_presel_id_ipmf3);
}

uint32
dnx_data_field_preselector_srv6_endpoint_psp_presel_id_ipmf3_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_preselector, dnx_data_field_preselector_define_srv6_endpoint_psp_presel_id_ipmf3);
}

uint32
dnx_data_field_preselector_srv6_psp_ext_to_endpoint_presel_id_ipmf3_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_preselector, dnx_data_field_preselector_define_srv6_psp_ext_to_endpoint_presel_id_ipmf3);
}

uint32
dnx_data_field_preselector_srv6_egress_usp_presel_id_ipmf3_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_preselector, dnx_data_field_preselector_define_srv6_egress_usp_presel_id_ipmf3);
}

uint32
dnx_data_field_preselector_srv6_endpoint_psp_extended_cut_presel_id_ipmf3_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_preselector, dnx_data_field_preselector_define_srv6_endpoint_psp_extended_cut_presel_id_ipmf3);
}

uint32
dnx_data_field_preselector_srv6_endpoint_usp_extended_cut_presel_id_ipmf3_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_preselector, dnx_data_field_preselector_define_srv6_endpoint_usp_extended_cut_presel_id_ipmf3);
}

uint32
dnx_data_field_preselector_srv6_egress_usd_presel_id_ipmf3_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_preselector, dnx_data_field_preselector_define_srv6_egress_usd_presel_id_ipmf3);
}

uint32
dnx_data_field_preselector_mpls_bier_presel_id_ipmf3_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_preselector, dnx_data_field_preselector_define_mpls_bier_presel_id_ipmf3);
}

uint32
dnx_data_field_preselector_ebtr_const_fwd_layer_eth_epmf_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_preselector, dnx_data_field_preselector_define_ebtr_const_fwd_layer_eth_epmf);
}

uint32
dnx_data_field_preselector_srv6_ext_termination_btr_epmf_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_preselector, dnx_data_field_preselector_define_srv6_ext_termination_btr_epmf);
}

uint32
dnx_data_field_preselector_default_j1_same_port_presel_id_epmf_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_preselector, dnx_data_field_preselector_define_default_j1_same_port_presel_id_epmf);
}

uint32
dnx_data_field_preselector_default_learn_limit_presel_id_epmf_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_preselector, dnx_data_field_preselector_define_default_learn_limit_presel_id_epmf);
}

uint32
dnx_data_field_preselector_srv6_endpoint_hbh_bta_presel_id_epmf_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_preselector, dnx_data_field_preselector_define_srv6_endpoint_hbh_bta_presel_id_epmf);
}

uint32
dnx_data_field_preselector_srv6_transit_hbh_bta_presel_id_epmf_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_preselector, dnx_data_field_preselector_define_srv6_transit_hbh_bta_presel_id_epmf);
}

uint32
dnx_data_field_preselector_srv6_endpoint_psp_bta_presel_id_epmf_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_preselector, dnx_data_field_preselector_define_srv6_endpoint_psp_bta_presel_id_epmf);
}

uint32
dnx_data_field_preselector_default_mpls_8b_fhei_presel_id_epmf_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_preselector, dnx_data_field_preselector_define_default_mpls_8b_fhei_presel_id_epmf);
}

uint32
dnx_data_field_preselector_num_cs_inlif_profile_entries_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_preselector, dnx_data_field_preselector_define_num_cs_inlif_profile_entries);
}










static shr_error_e
dnx_data_field_qual_init(
    int unit,
    dnxc_data_submodule_t *submodule_data)
{
    SHR_FUNC_INIT_VARS(unit);

    submodule_data->name = "qual";
    submodule_data->doc = "User Defined Data Qualifiers";
    
    submodule_data->nof_features = _dnx_data_field_qual_feature_nof;
    DNXC_DATA_ALLOC(submodule_data->features, dnxc_data_feature_t,  submodule_data->nof_features, "_dnxc_data field qual features");

    
    submodule_data->nof_defines = _dnx_data_field_qual_define_nof;
    DNXC_DATA_ALLOC(submodule_data->defines, dnxc_data_define_t, submodule_data->nof_defines, "_dnxc_data field qual defines");

    submodule_data->defines[dnx_data_field_qual_define_user_1st].name = "user_1st";
    submodule_data->defines[dnx_data_field_qual_define_user_1st].doc = "First User qualifier id to avoid overlapping with static ones";
    
    submodule_data->defines[dnx_data_field_qual_define_user_1st].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_qual_define_user_nof].name = "user_nof";
    submodule_data->defines[dnx_data_field_qual_define_user_nof].doc = "Number of User Define Data qualifiers that can be created";
    
    submodule_data->defines[dnx_data_field_qual_define_user_nof].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_qual_define_predefined_nof].name = "predefined_nof";
    submodule_data->defines[dnx_data_field_qual_define_predefined_nof].doc = "Number of predefined qualifier that need to create DBAL fields";
    
    submodule_data->defines[dnx_data_field_qual_define_predefined_nof].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_qual_define_layer_record_nof].name = "layer_record_nof";
    submodule_data->defines[dnx_data_field_qual_define_layer_record_nof].doc = "Number of layer record qualifier that need to create DBAL fields";
    
    submodule_data->defines[dnx_data_field_qual_define_layer_record_nof].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_qual_define_vw_1st].name = "vw_1st";
    submodule_data->defines[dnx_data_field_qual_define_vw_1st].doc = "First VW qualifier id to avoid overlapping with static or user defined qualifiers";
    
    submodule_data->defines[dnx_data_field_qual_define_vw_1st].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_qual_define_vw_nof].name = "vw_nof";
    submodule_data->defines[dnx_data_field_qual_define_vw_nof].doc = "Number of VW qualifiers that can be created";
    
    submodule_data->defines[dnx_data_field_qual_define_vw_nof].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_qual_define_max_bits_in_qual].name = "max_bits_in_qual";
    submodule_data->defines[dnx_data_field_qual_define_max_bits_in_qual].doc = "Maximum number of bits that any qualifier can have";
    
    submodule_data->defines[dnx_data_field_qual_define_max_bits_in_qual].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_qual_define_ingress_pbus_header_length].name = "ingress_pbus_header_length";
    submodule_data->defines[dnx_data_field_qual_define_ingress_pbus_header_length].doc = "Number of bits reserved in ingress PBUS for header.";
    
    submodule_data->defines[dnx_data_field_qual_define_ingress_pbus_header_length].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_qual_define_egress_pbus_header_length].name = "egress_pbus_header_length";
    submodule_data->defines[dnx_data_field_qual_define_egress_pbus_header_length].doc = "Number of bits reserved in egress PBUS for header.";
    
    submodule_data->defines[dnx_data_field_qual_define_egress_pbus_header_length].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_qual_define_ifwd2_pbus_size].name = "ifwd2_pbus_size";
    submodule_data->defines[dnx_data_field_qual_define_ifwd2_pbus_size].doc = "Number of bits in the PBUS of iFWD2";
    
    submodule_data->defines[dnx_data_field_qual_define_ifwd2_pbus_size].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_qual_define_ipmf1_pbus_size].name = "ipmf1_pbus_size";
    submodule_data->defines[dnx_data_field_qual_define_ipmf1_pbus_size].doc = "Number of bits in the PBUS of iPMF1";
    
    submodule_data->defines[dnx_data_field_qual_define_ipmf1_pbus_size].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_qual_define_ipmf2_pbus_size].name = "ipmf2_pbus_size";
    submodule_data->defines[dnx_data_field_qual_define_ipmf2_pbus_size].doc = "Number of bits in the PBUS of iPMF3";
    
    submodule_data->defines[dnx_data_field_qual_define_ipmf2_pbus_size].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_qual_define_ipmf3_pbus_size].name = "ipmf3_pbus_size";
    submodule_data->defines[dnx_data_field_qual_define_ipmf3_pbus_size].doc = "Number of bits in the PBUS of iPMF3";
    
    submodule_data->defines[dnx_data_field_qual_define_ipmf3_pbus_size].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_qual_define_epmf_pbus_size].name = "epmf_pbus_size";
    submodule_data->defines[dnx_data_field_qual_define_epmf_pbus_size].doc = "Number of bits in the PBUS of ePMF";
    
    submodule_data->defines[dnx_data_field_qual_define_epmf_pbus_size].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_qual_define_l4_ops_pbus_size].name = "l4_ops_pbus_size";
    submodule_data->defines[dnx_data_field_qual_define_l4_ops_pbus_size].doc = "Number of bits in the PBUS of L4 ops";
    
    submodule_data->defines[dnx_data_field_qual_define_l4_ops_pbus_size].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_qual_define_ingress_nof_layer_records].name = "ingress_nof_layer_records";
    submodule_data->defines[dnx_data_field_qual_define_ingress_nof_layer_records].doc = "Number of layer records taken from the parser in ingress stages.";
    
    submodule_data->defines[dnx_data_field_qual_define_ingress_nof_layer_records].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_qual_define_ingress_layer_record_size].name = "ingress_layer_record_size";
    submodule_data->defines[dnx_data_field_qual_define_ingress_layer_record_size].doc = "Number of bits in each layer record in ingress stages.";
    
    submodule_data->defines[dnx_data_field_qual_define_ingress_layer_record_size].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_qual_define_egress_nof_layer_records].name = "egress_nof_layer_records";
    submodule_data->defines[dnx_data_field_qual_define_egress_nof_layer_records].doc = "Number of layer records taken from the parser in egress stages.";
    
    submodule_data->defines[dnx_data_field_qual_define_egress_nof_layer_records].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_qual_define_egress_layer_record_size].name = "egress_layer_record_size";
    submodule_data->defines[dnx_data_field_qual_define_egress_layer_record_size].doc = "Number of bits in each layer record in egress stages.";
    
    submodule_data->defines[dnx_data_field_qual_define_egress_layer_record_size].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_qual_define_kbp_extra_offset_after_layer_record_offset].name = "kbp_extra_offset_after_layer_record_offset";
    submodule_data->defines[dnx_data_field_qual_define_kbp_extra_offset_after_layer_record_offset].doc = "Number of extra bits to add after layer record offset for KBP only.";
    
    submodule_data->defines[dnx_data_field_qual_define_kbp_extra_offset_after_layer_record_offset].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_qual_define_special_metadata_qual_max_parts].name = "special_metadata_qual_max_parts";
    submodule_data->defines[dnx_data_field_qual_define_special_metadata_qual_max_parts].doc = "Maximum number of parts a special metadata qualifier can be split into. Relevant not per device.";
    
    submodule_data->defines[dnx_data_field_qual_define_special_metadata_qual_max_parts].flags |= DNXC_DATA_F_DEFINE;

    
    submodule_data->nof_tables = _dnx_data_field_qual_table_nof;
    DNXC_DATA_ALLOC(submodule_data->tables, dnxc_data_table_t, submodule_data->nof_tables, "_dnxc_data field qual tables");


exit:
    SHR_FUNC_EXIT;
}


int
dnx_data_field_qual_feature_get(
    int unit,
    dnx_data_field_qual_feature_e feature)
{
    return dnxc_data_mgmt_feature_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_qual, feature);
}


uint32
dnx_data_field_qual_user_1st_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_qual, dnx_data_field_qual_define_user_1st);
}

uint32
dnx_data_field_qual_user_nof_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_qual, dnx_data_field_qual_define_user_nof);
}

uint32
dnx_data_field_qual_predefined_nof_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_qual, dnx_data_field_qual_define_predefined_nof);
}

uint32
dnx_data_field_qual_layer_record_nof_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_qual, dnx_data_field_qual_define_layer_record_nof);
}

uint32
dnx_data_field_qual_vw_1st_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_qual, dnx_data_field_qual_define_vw_1st);
}

uint32
dnx_data_field_qual_vw_nof_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_qual, dnx_data_field_qual_define_vw_nof);
}

uint32
dnx_data_field_qual_max_bits_in_qual_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_qual, dnx_data_field_qual_define_max_bits_in_qual);
}

uint32
dnx_data_field_qual_ingress_pbus_header_length_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_qual, dnx_data_field_qual_define_ingress_pbus_header_length);
}

uint32
dnx_data_field_qual_egress_pbus_header_length_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_qual, dnx_data_field_qual_define_egress_pbus_header_length);
}

uint32
dnx_data_field_qual_ifwd2_pbus_size_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_qual, dnx_data_field_qual_define_ifwd2_pbus_size);
}

uint32
dnx_data_field_qual_ipmf1_pbus_size_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_qual, dnx_data_field_qual_define_ipmf1_pbus_size);
}

uint32
dnx_data_field_qual_ipmf2_pbus_size_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_qual, dnx_data_field_qual_define_ipmf2_pbus_size);
}

uint32
dnx_data_field_qual_ipmf3_pbus_size_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_qual, dnx_data_field_qual_define_ipmf3_pbus_size);
}

uint32
dnx_data_field_qual_epmf_pbus_size_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_qual, dnx_data_field_qual_define_epmf_pbus_size);
}

uint32
dnx_data_field_qual_l4_ops_pbus_size_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_qual, dnx_data_field_qual_define_l4_ops_pbus_size);
}

uint32
dnx_data_field_qual_ingress_nof_layer_records_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_qual, dnx_data_field_qual_define_ingress_nof_layer_records);
}

uint32
dnx_data_field_qual_ingress_layer_record_size_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_qual, dnx_data_field_qual_define_ingress_layer_record_size);
}

uint32
dnx_data_field_qual_egress_nof_layer_records_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_qual, dnx_data_field_qual_define_egress_nof_layer_records);
}

uint32
dnx_data_field_qual_egress_layer_record_size_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_qual, dnx_data_field_qual_define_egress_layer_record_size);
}

uint32
dnx_data_field_qual_kbp_extra_offset_after_layer_record_offset_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_qual, dnx_data_field_qual_define_kbp_extra_offset_after_layer_record_offset);
}

uint32
dnx_data_field_qual_special_metadata_qual_max_parts_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_qual, dnx_data_field_qual_define_special_metadata_qual_max_parts);
}










static shr_error_e
dnx_data_field_action_init(
    int unit,
    dnxc_data_submodule_t *submodule_data)
{
    SHR_FUNC_INIT_VARS(unit);

    submodule_data->name = "action";
    submodule_data->doc = "User Define Data Actions";
    
    submodule_data->nof_features = _dnx_data_field_action_feature_nof;
    DNXC_DATA_ALLOC(submodule_data->features, dnxc_data_feature_t,  submodule_data->nof_features, "_dnxc_data field action features");

    
    submodule_data->nof_defines = _dnx_data_field_action_define_nof;
    DNXC_DATA_ALLOC(submodule_data->defines, dnxc_data_define_t, submodule_data->nof_defines, "_dnxc_data field action defines");

    submodule_data->defines[dnx_data_field_action_define_user_1st].name = "user_1st";
    submodule_data->defines[dnx_data_field_action_define_user_1st].doc = "First user action id to avaoid overlapping with static ones";
    
    submodule_data->defines[dnx_data_field_action_define_user_1st].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_action_define_user_nof].name = "user_nof";
    submodule_data->defines[dnx_data_field_action_define_user_nof].doc = "Number of User Define Data actions that can be created";
    
    submodule_data->defines[dnx_data_field_action_define_user_nof].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_action_define_predefined_nof].name = "predefined_nof";
    submodule_data->defines[dnx_data_field_action_define_predefined_nof].doc = "Number of predefined actions that need to create DBAL fields";
    
    submodule_data->defines[dnx_data_field_action_define_predefined_nof].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_action_define_vw_1st].name = "vw_1st";
    submodule_data->defines[dnx_data_field_action_define_vw_1st].doc = "First VW action id to avoid overlapping with static or user defined qualifiers";
    
    submodule_data->defines[dnx_data_field_action_define_vw_1st].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_action_define_vw_nof].name = "vw_nof";
    submodule_data->defines[dnx_data_field_action_define_vw_nof].doc = "Number of VW action that can be created";
    
    submodule_data->defines[dnx_data_field_action_define_vw_nof].flags |= DNXC_DATA_F_DEFINE;

    
    submodule_data->nof_tables = _dnx_data_field_action_table_nof;
    DNXC_DATA_ALLOC(submodule_data->tables, dnxc_data_table_t, submodule_data->nof_tables, "_dnxc_data field action tables");

    
    submodule_data->tables[dnx_data_field_action_table_params].name = "params";
    submodule_data->tables[dnx_data_field_action_table_params].doc = "Per stage Per action properties";
    submodule_data->tables[dnx_data_field_action_table_params].flags |= DNXC_DATA_F_TABLE;
    submodule_data->tables[dnx_data_field_action_table_params].size_of_values = sizeof(dnx_data_field_action_params_t);
    submodule_data->tables[dnx_data_field_action_table_params].entry_get = dnx_data_field_action_params_entry_str_get;

    
    submodule_data->tables[dnx_data_field_action_table_params].nof_keys = 2;
    submodule_data->tables[dnx_data_field_action_table_params].keys[0].name = "stage";
    submodule_data->tables[dnx_data_field_action_table_params].keys[0].doc = "stage enum";
    submodule_data->tables[dnx_data_field_action_table_params].keys[1].name = "action";
    submodule_data->tables[dnx_data_field_action_table_params].keys[1].doc = "dnx action";

    
    submodule_data->tables[dnx_data_field_action_table_params].nof_values = 2;
    DNXC_DATA_ALLOC(submodule_data->tables[dnx_data_field_action_table_params].values, dnxc_data_value_t, submodule_data->tables[dnx_data_field_action_table_params].nof_values, "_dnx_data_field_action_table_params table values");
    submodule_data->tables[dnx_data_field_action_table_params].values[0].name = "id";
    submodule_data->tables[dnx_data_field_action_table_params].values[0].type = "int";
    submodule_data->tables[dnx_data_field_action_table_params].values[0].doc = "DBAL Enum ID";
    submodule_data->tables[dnx_data_field_action_table_params].values[0].offset = UTILEX_OFFSETOF(dnx_data_field_action_params_t, id);
    submodule_data->tables[dnx_data_field_action_table_params].values[1].name = "size";
    submodule_data->tables[dnx_data_field_action_table_params].values[1].type = "int";
    submodule_data->tables[dnx_data_field_action_table_params].values[1].doc = "action size";
    submodule_data->tables[dnx_data_field_action_table_params].values[1].offset = UTILEX_OFFSETOF(dnx_data_field_action_params_t, size);


exit:
    SHR_FUNC_EXIT;
}


int
dnx_data_field_action_feature_get(
    int unit,
    dnx_data_field_action_feature_e feature)
{
    return dnxc_data_mgmt_feature_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_action, feature);
}


uint32
dnx_data_field_action_user_1st_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_action, dnx_data_field_action_define_user_1st);
}

uint32
dnx_data_field_action_user_nof_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_action, dnx_data_field_action_define_user_nof);
}

uint32
dnx_data_field_action_predefined_nof_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_action, dnx_data_field_action_define_predefined_nof);
}

uint32
dnx_data_field_action_vw_1st_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_action, dnx_data_field_action_define_vw_1st);
}

uint32
dnx_data_field_action_vw_nof_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_action, dnx_data_field_action_define_vw_nof);
}



const dnx_data_field_action_params_t *
dnx_data_field_action_params_get(
    int unit,
    int stage,
    int action)
{
    char *data;
    dnxc_data_table_t *table;

    
    table = dnxc_data_mgmt_table_get(unit, dnx_data_module_field, dnx_data_field_submodule_action, dnx_data_field_action_table_params);
    
    data = dnxc_data_mgmt_table_data_get(unit, table, stage, action);
    return (const dnx_data_field_action_params_t *) data;

}


shr_error_e
dnx_data_field_action_params_entry_str_get(
    int unit,
    char *buffer,
    int key0,
    int key1,
    int value_index)
{
    dnxc_data_table_t *table;
    const dnx_data_field_action_params_t *data;
    SHR_FUNC_INIT_VARS(unit);

    
    table = dnxc_data_mgmt_table_get(unit, dnx_data_module_field, dnx_data_field_submodule_action, dnx_data_field_action_table_params);
    data = (const dnx_data_field_action_params_t *) dnxc_data_mgmt_table_data_diag_get(unit, table, key0, key1);
    switch (value_index)
    {
        case 0:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->id);
            break;
        case 1:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->size);
            break;
    }

    SHR_FUNC_EXIT;
}


const dnxc_data_table_info_t *
dnx_data_field_action_params_info_get(
    int unit)
{

    
    return dnxc_data_mgmt_table_info_get(unit, dnx_data_module_field, dnx_data_field_submodule_action, dnx_data_field_action_table_params);

}






static shr_error_e
dnx_data_field_virtual_wire_init(
    int unit,
    dnxc_data_submodule_t *submodule_data)
{
    SHR_FUNC_INIT_VARS(unit);

    submodule_data->name = "virtual_wire";
    submodule_data->doc = "virtual_wires";
    
    submodule_data->nof_features = _dnx_data_field_virtual_wire_feature_nof;
    DNXC_DATA_ALLOC(submodule_data->features, dnxc_data_feature_t,  submodule_data->nof_features, "_dnxc_data field virtual_wire features");

    submodule_data->features[dnx_data_field_virtual_wire_in_lif_ac_wide_is_vw].name = "in_lif_ac_wide_is_vw";
    submodule_data->features[dnx_data_field_virtual_wire_in_lif_ac_wide_is_vw].doc = "Indicates if the In_LIF_AC_WIDE data is set on VW or container";
    submodule_data->features[dnx_data_field_virtual_wire_in_lif_ac_wide_is_vw].flags |= DNXC_DATA_F_FEATURE;

    
    submodule_data->nof_defines = _dnx_data_field_virtual_wire_define_nof;
    DNXC_DATA_ALLOC(submodule_data->defines, dnxc_data_define_t, submodule_data->nof_defines, "_dnxc_data field virtual_wire defines");

    submodule_data->defines[dnx_data_field_virtual_wire_define_signals_nof].name = "signals_nof";
    submodule_data->defines[dnx_data_field_virtual_wire_define_signals_nof].doc = "Number of elements in the table vw_quals.";
    
    submodule_data->defines[dnx_data_field_virtual_wire_define_signals_nof].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_virtual_wire_define_actions_per_signal_nof].name = "actions_per_signal_nof";
    submodule_data->defines[dnx_data_field_virtual_wire_define_actions_per_signal_nof].doc = "Maximum number of actions that write to a signal.";
    
    submodule_data->defines[dnx_data_field_virtual_wire_define_actions_per_signal_nof].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_virtual_wire_define_general_data_user_general_containers_size].name = "general_data_user_general_containers_size";
    submodule_data->defines[dnx_data_field_virtual_wire_define_general_data_user_general_containers_size].doc = "The size in bits of the user_general part of the general_data (before the comp_general_data part).";
    
    submodule_data->defines[dnx_data_field_virtual_wire_define_general_data_user_general_containers_size].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_virtual_wire_define_ipmf1_general_data_index].name = "ipmf1_general_data_index";
    submodule_data->defines[dnx_data_field_virtual_wire_define_ipmf1_general_data_index].doc = "The index in signal_qual_mapping table of the general data signal for iPMF1.";
    
    submodule_data->defines[dnx_data_field_virtual_wire_define_ipmf1_general_data_index].flags |= DNXC_DATA_F_DEFINE;

    
    submodule_data->nof_tables = _dnx_data_field_virtual_wire_table_nof;
    DNXC_DATA_ALLOC(submodule_data->tables, dnxc_data_table_t, submodule_data->nof_tables, "_dnxc_data field virtual_wire tables");

    
    submodule_data->tables[dnx_data_field_virtual_wire_table_signal_mapping].name = "signal_mapping";
    submodule_data->tables[dnx_data_field_virtual_wire_table_signal_mapping].doc = "Per stage per signal, how it maps to standard 1 qualifiers and actions";
    submodule_data->tables[dnx_data_field_virtual_wire_table_signal_mapping].flags |= DNXC_DATA_F_TABLE;
    submodule_data->tables[dnx_data_field_virtual_wire_table_signal_mapping].size_of_values = sizeof(dnx_data_field_virtual_wire_signal_mapping_t);
    submodule_data->tables[dnx_data_field_virtual_wire_table_signal_mapping].entry_get = dnx_data_field_virtual_wire_signal_mapping_entry_str_get;

    
    submodule_data->tables[dnx_data_field_virtual_wire_table_signal_mapping].nof_keys = 2;
    submodule_data->tables[dnx_data_field_virtual_wire_table_signal_mapping].keys[0].name = "stage";
    submodule_data->tables[dnx_data_field_virtual_wire_table_signal_mapping].keys[0].doc = "stage enum";
    submodule_data->tables[dnx_data_field_virtual_wire_table_signal_mapping].keys[1].name = "signal_id";
    submodule_data->tables[dnx_data_field_virtual_wire_table_signal_mapping].keys[1].doc = "A local index for the entry";

    
    submodule_data->tables[dnx_data_field_virtual_wire_table_signal_mapping].nof_values = 5;
    DNXC_DATA_ALLOC(submodule_data->tables[dnx_data_field_virtual_wire_table_signal_mapping].values, dnxc_data_value_t, submodule_data->tables[dnx_data_field_virtual_wire_table_signal_mapping].nof_values, "_dnx_data_field_virtual_wire_table_signal_mapping table values");
    submodule_data->tables[dnx_data_field_virtual_wire_table_signal_mapping].values[0].name = "signal_name";
    submodule_data->tables[dnx_data_field_virtual_wire_table_signal_mapping].values[0].type = "char *";
    submodule_data->tables[dnx_data_field_virtual_wire_table_signal_mapping].values[0].doc = "Name of the signal.";
    submodule_data->tables[dnx_data_field_virtual_wire_table_signal_mapping].values[0].offset = UTILEX_OFFSETOF(dnx_data_field_virtual_wire_signal_mapping_t, signal_name);
    submodule_data->tables[dnx_data_field_virtual_wire_table_signal_mapping].values[1].name = "mapped_qual";
    submodule_data->tables[dnx_data_field_virtual_wire_table_signal_mapping].values[1].type = "int";
    submodule_data->tables[dnx_data_field_virtual_wire_table_signal_mapping].values[1].doc = "Standard 1 qualifier that correlates to the signal";
    submodule_data->tables[dnx_data_field_virtual_wire_table_signal_mapping].values[1].offset = UTILEX_OFFSETOF(dnx_data_field_virtual_wire_signal_mapping_t, mapped_qual);
    submodule_data->tables[dnx_data_field_virtual_wire_table_signal_mapping].values[2].name = "offset_from_qual";
    submodule_data->tables[dnx_data_field_virtual_wire_table_signal_mapping].values[2].type = "int";
    submodule_data->tables[dnx_data_field_virtual_wire_table_signal_mapping].values[2].doc = "Offset on from the start of the standard 1 qualifier";
    submodule_data->tables[dnx_data_field_virtual_wire_table_signal_mapping].values[2].offset = UTILEX_OFFSETOF(dnx_data_field_virtual_wire_signal_mapping_t, offset_from_qual);
    submodule_data->tables[dnx_data_field_virtual_wire_table_signal_mapping].values[3].name = "mapped_action";
    submodule_data->tables[dnx_data_field_virtual_wire_table_signal_mapping].values[3].type = "int[DNX_DATA_MAX_FIELD_VIRTUAL_WIRE_ACTIONS_PER_SIGNAL_NOF]";
    submodule_data->tables[dnx_data_field_virtual_wire_table_signal_mapping].values[3].doc = "Standard 1 action that correlates to the signal";
    submodule_data->tables[dnx_data_field_virtual_wire_table_signal_mapping].values[3].offset = UTILEX_OFFSETOF(dnx_data_field_virtual_wire_signal_mapping_t, mapped_action);
    submodule_data->tables[dnx_data_field_virtual_wire_table_signal_mapping].values[4].name = "action_offset";
    submodule_data->tables[dnx_data_field_virtual_wire_table_signal_mapping].values[4].type = "int[DNX_DATA_MAX_FIELD_VIRTUAL_WIRE_ACTIONS_PER_SIGNAL_NOF]";
    submodule_data->tables[dnx_data_field_virtual_wire_table_signal_mapping].values[4].doc = "Offset on from the start of the signal for the action";
    submodule_data->tables[dnx_data_field_virtual_wire_table_signal_mapping].values[4].offset = UTILEX_OFFSETOF(dnx_data_field_virtual_wire_signal_mapping_t, action_offset);


exit:
    SHR_FUNC_EXIT;
}


int
dnx_data_field_virtual_wire_feature_get(
    int unit,
    dnx_data_field_virtual_wire_feature_e feature)
{
    return dnxc_data_mgmt_feature_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_virtual_wire, feature);
}


uint32
dnx_data_field_virtual_wire_signals_nof_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_virtual_wire, dnx_data_field_virtual_wire_define_signals_nof);
}

uint32
dnx_data_field_virtual_wire_actions_per_signal_nof_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_virtual_wire, dnx_data_field_virtual_wire_define_actions_per_signal_nof);
}

uint32
dnx_data_field_virtual_wire_general_data_user_general_containers_size_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_virtual_wire, dnx_data_field_virtual_wire_define_general_data_user_general_containers_size);
}

uint32
dnx_data_field_virtual_wire_ipmf1_general_data_index_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_virtual_wire, dnx_data_field_virtual_wire_define_ipmf1_general_data_index);
}



const dnx_data_field_virtual_wire_signal_mapping_t *
dnx_data_field_virtual_wire_signal_mapping_get(
    int unit,
    int stage,
    int signal_id)
{
    char *data;
    dnxc_data_table_t *table;

    
    table = dnxc_data_mgmt_table_get(unit, dnx_data_module_field, dnx_data_field_submodule_virtual_wire, dnx_data_field_virtual_wire_table_signal_mapping);
    
    data = dnxc_data_mgmt_table_data_get(unit, table, stage, signal_id);
    return (const dnx_data_field_virtual_wire_signal_mapping_t *) data;

}


shr_error_e
dnx_data_field_virtual_wire_signal_mapping_entry_str_get(
    int unit,
    char *buffer,
    int key0,
    int key1,
    int value_index)
{
    dnxc_data_table_t *table;
    const dnx_data_field_virtual_wire_signal_mapping_t *data;
    SHR_FUNC_INIT_VARS(unit);

    
    table = dnxc_data_mgmt_table_get(unit, dnx_data_module_field, dnx_data_field_submodule_virtual_wire, dnx_data_field_virtual_wire_table_signal_mapping);
    data = (const dnx_data_field_virtual_wire_signal_mapping_t *) dnxc_data_mgmt_table_data_diag_get(unit, table, key0, key1);
    switch (value_index)
    {
        case 0:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%s", data->signal_name == NULL ? "" : data->signal_name);
            break;
        case 1:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->mapped_qual);
            break;
        case 2:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->offset_from_qual);
            break;
        case 3:
            DNXC_DATA_MGMT_ARR_STR(buffer, DNX_DATA_MAX_FIELD_VIRTUAL_WIRE_ACTIONS_PER_SIGNAL_NOF, data->mapped_action);
            break;
        case 4:
            DNXC_DATA_MGMT_ARR_STR(buffer, DNX_DATA_MAX_FIELD_VIRTUAL_WIRE_ACTIONS_PER_SIGNAL_NOF, data->action_offset);
            break;
    }

    SHR_FUNC_EXIT;
}


const dnxc_data_table_info_t *
dnx_data_field_virtual_wire_signal_mapping_info_get(
    int unit)
{

    
    return dnxc_data_mgmt_table_info_get(unit, dnx_data_module_field, dnx_data_field_submodule_virtual_wire, dnx_data_field_virtual_wire_table_signal_mapping);

}






static shr_error_e
dnx_data_field_profile_bits_init(
    int unit,
    dnxc_data_submodule_t *submodule_data)
{
    SHR_FUNC_INIT_VARS(unit);

    submodule_data->name = "profile_bits";
    submodule_data->doc = "PMF Dedicated bits in profiles";
    
    submodule_data->nof_features = _dnx_data_field_profile_bits_feature_nof;
    DNXC_DATA_ALLOC(submodule_data->features, dnxc_data_feature_t,  submodule_data->nof_features, "_dnxc_data field profile_bits features");

    
    submodule_data->nof_defines = _dnx_data_field_profile_bits_define_nof;
    DNXC_DATA_ALLOC(submodule_data->defines, dnxc_data_define_t, submodule_data->nof_defines, "_dnxc_data field profile_bits defines");

    submodule_data->defines[dnx_data_field_profile_bits_define_ingress_pp_port_key_gen_var_size].name = "ingress_pp_port_key_gen_var_size";
    submodule_data->defines[dnx_data_field_profile_bits_define_ingress_pp_port_key_gen_var_size].doc = "Number of bits available on the key_ken_per per PP port";
    
    submodule_data->defines[dnx_data_field_profile_bits_define_ingress_pp_port_key_gen_var_size].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_profile_bits_define_max_port_profile_size].name = "max_port_profile_size";
    submodule_data->defines[dnx_data_field_profile_bits_define_max_port_profile_size].doc = "The maximum number in bits of all port profiles hw memories possible";
    
    submodule_data->defines[dnx_data_field_profile_bits_define_max_port_profile_size].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_profile_bits_define_nof_bits_in_port_profile].name = "nof_bits_in_port_profile";
    submodule_data->defines[dnx_data_field_profile_bits_define_nof_bits_in_port_profile].doc = "The number of bits used by the PMF for port profiles. Note that the actual number may be lower in some stages.";
    
    submodule_data->defines[dnx_data_field_profile_bits_define_nof_bits_in_port_profile].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_profile_bits_define_nof_bits_in_ingress_pp_port_general_data].name = "nof_bits_in_ingress_pp_port_general_data";
    submodule_data->defines[dnx_data_field_profile_bits_define_nof_bits_in_ingress_pp_port_general_data].doc = "The number of bits used by the PMF for per PP port general data.";
    
    submodule_data->defines[dnx_data_field_profile_bits_define_nof_bits_in_ingress_pp_port_general_data].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_profile_bits_define_nof_ing_in_lif].name = "nof_ing_in_lif";
    submodule_data->defines[dnx_data_field_profile_bits_define_nof_ing_in_lif].doc = "Number of reserved bits for Ingress FP in in_lif_profile";
    
    submodule_data->defines[dnx_data_field_profile_bits_define_nof_ing_in_lif].flags |= DNXC_DATA_F_NUMERIC;

    submodule_data->defines[dnx_data_field_profile_bits_define_nof_ing_eth_rif].name = "nof_ing_eth_rif";
    submodule_data->defines[dnx_data_field_profile_bits_define_nof_ing_eth_rif].doc = "Number of reserved bits for Ingress FP in in_rif_profile";
    
    submodule_data->defines[dnx_data_field_profile_bits_define_nof_ing_eth_rif].flags |= DNXC_DATA_F_NUMERIC;

    
    submodule_data->nof_tables = _dnx_data_field_profile_bits_table_nof;
    DNXC_DATA_ALLOC(submodule_data->tables, dnxc_data_table_t, submodule_data->nof_tables, "_dnxc_data field profile_bits tables");


exit:
    SHR_FUNC_EXIT;
}


int
dnx_data_field_profile_bits_feature_get(
    int unit,
    dnx_data_field_profile_bits_feature_e feature)
{
    return dnxc_data_mgmt_feature_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_profile_bits, feature);
}


uint32
dnx_data_field_profile_bits_ingress_pp_port_key_gen_var_size_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_profile_bits, dnx_data_field_profile_bits_define_ingress_pp_port_key_gen_var_size);
}

uint32
dnx_data_field_profile_bits_max_port_profile_size_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_profile_bits, dnx_data_field_profile_bits_define_max_port_profile_size);
}

uint32
dnx_data_field_profile_bits_nof_bits_in_port_profile_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_profile_bits, dnx_data_field_profile_bits_define_nof_bits_in_port_profile);
}

uint32
dnx_data_field_profile_bits_nof_bits_in_ingress_pp_port_general_data_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_profile_bits, dnx_data_field_profile_bits_define_nof_bits_in_ingress_pp_port_general_data);
}

uint32
dnx_data_field_profile_bits_nof_ing_in_lif_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_profile_bits, dnx_data_field_profile_bits_define_nof_ing_in_lif);
}

uint32
dnx_data_field_profile_bits_nof_ing_eth_rif_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_profile_bits, dnx_data_field_profile_bits_define_nof_ing_eth_rif);
}










static shr_error_e
dnx_data_field_dir_ext_init(
    int unit,
    dnxc_data_submodule_t *submodule_data)
{
    SHR_FUNC_INIT_VARS(unit);

    submodule_data->name = "dir_ext";
    submodule_data->doc = "Direct Extraction Data";
    
    submodule_data->nof_features = _dnx_data_field_dir_ext_feature_nof;
    DNXC_DATA_ALLOC(submodule_data->features, dnxc_data_feature_t,  submodule_data->nof_features, "_dnxc_data field dir_ext features");

    
    submodule_data->nof_defines = _dnx_data_field_dir_ext_define_nof;
    DNXC_DATA_ALLOC(submodule_data->defines, dnxc_data_define_t, submodule_data->nof_defines, "_dnxc_data field dir_ext defines");

    submodule_data->defines[dnx_data_field_dir_ext_define_half_key_size].name = "half_key_size";
    submodule_data->defines[dnx_data_field_dir_ext_define_half_key_size].doc = "Half key size of direct extraction";
    
    submodule_data->defines[dnx_data_field_dir_ext_define_half_key_size].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_dir_ext_define_single_key_size].name = "single_key_size";
    submodule_data->defines[dnx_data_field_dir_ext_define_single_key_size].doc = "Single key size of direct extraction";
    
    submodule_data->defines[dnx_data_field_dir_ext_define_single_key_size].flags |= DNXC_DATA_F_DEFINE;

    
    submodule_data->nof_tables = _dnx_data_field_dir_ext_table_nof;
    DNXC_DATA_ALLOC(submodule_data->tables, dnxc_data_table_t, submodule_data->nof_tables, "_dnxc_data field dir_ext tables");


exit:
    SHR_FUNC_EXIT;
}


int
dnx_data_field_dir_ext_feature_get(
    int unit,
    dnx_data_field_dir_ext_feature_e feature)
{
    return dnxc_data_mgmt_feature_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_dir_ext, feature);
}


uint32
dnx_data_field_dir_ext_half_key_size_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_dir_ext, dnx_data_field_dir_ext_define_half_key_size);
}

uint32
dnx_data_field_dir_ext_single_key_size_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_dir_ext, dnx_data_field_dir_ext_define_single_key_size);
}










static shr_error_e
dnx_data_field_state_table_init(
    int unit,
    dnxc_data_submodule_t *submodule_data)
{
    SHR_FUNC_INIT_VARS(unit);

    submodule_data->name = "state_table";
    submodule_data->doc = "State Table data";
    
    submodule_data->nof_features = _dnx_data_field_state_table_feature_nof;
    DNXC_DATA_ALLOC(submodule_data->features, dnxc_data_feature_t,  submodule_data->nof_features, "_dnxc_data field state_table features");

    
    submodule_data->nof_defines = _dnx_data_field_state_table_define_nof;
    DNXC_DATA_ALLOC(submodule_data->defines, dnxc_data_define_t, submodule_data->nof_defines, "_dnxc_data field state_table defines");

    submodule_data->defines[dnx_data_field_state_table_define_supported].name = "supported";
    submodule_data->defines[dnx_data_field_state_table_define_supported].doc = "indicate if state FG is supported";
    
    submodule_data->defines[dnx_data_field_state_table_define_supported].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_state_table_define_address_size_entry_max].name = "address_size_entry_max";
    submodule_data->defines[dnx_data_field_state_table_define_address_size_entry_max].doc = "Size of the address field in State Table in bits, for the case where the maximum size entry was chosen. Number of entries in HW.";
    
    submodule_data->defines[dnx_data_field_state_table_define_address_size_entry_max].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_state_table_define_data_size_entry_max].name = "data_size_entry_max";
    submodule_data->defines[dnx_data_field_state_table_define_data_size_entry_max].doc = "Size of the DATA/ARGUMENT field in State Table in bits, for the case where the maximum size entry was chosen. Number of bits on the paylaod of the entry in HW.";
    
    submodule_data->defines[dnx_data_field_state_table_define_data_size_entry_max].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_state_table_define_address_max_entry_max].name = "address_max_entry_max";
    submodule_data->defines[dnx_data_field_state_table_define_address_max_entry_max].doc = "Max address for the state table, for the case where the maximum size entry was chosen. Number of entries in HW.";
    
    submodule_data->defines[dnx_data_field_state_table_define_address_max_entry_max].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_state_table_define_wr_bit_size_rw].name = "wr_bit_size_rw";
    submodule_data->defines[dnx_data_field_state_table_define_wr_bit_size_rw].doc = "Size of wr bit field in state table interface in bits. Relevant for separate read write operations.";
    
    submodule_data->defines[dnx_data_field_state_table_define_wr_bit_size_rw].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_state_table_define_opcode_size_rmw].name = "opcode_size_rmw";
    submodule_data->defines[dnx_data_field_state_table_define_opcode_size_rmw].doc = "Size of opcode field in state table interface in bits. Relevant for atomic read modify write operations.";
    
    submodule_data->defines[dnx_data_field_state_table_define_opcode_size_rmw].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_state_table_define_ipmf2_key_select_supported].name = "ipmf2_key_select_supported";
    submodule_data->defines[dnx_data_field_state_table_define_ipmf2_key_select_supported].doc = "indicate if iPMF2 key select for state table is supported";
    
    submodule_data->defines[dnx_data_field_state_table_define_ipmf2_key_select_supported].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_state_table_define_data_size].name = "data_size";
    submodule_data->defines[dnx_data_field_state_table_define_data_size].doc = "Size of the data field in State Table in bits. Determined by SOC property.";
    
    submodule_data->defines[dnx_data_field_state_table_define_data_size].flags |= DNXC_DATA_F_NUMERIC;

    submodule_data->defines[dnx_data_field_state_table_define_state_table_stage_key].name = "state_table_stage_key";
    submodule_data->defines[dnx_data_field_state_table_define_state_table_stage_key].doc = "Indication of the source of the key for the state table lookup. Determined by SOC property.";
    
    submodule_data->defines[dnx_data_field_state_table_define_state_table_stage_key].flags |= DNXC_DATA_F_NUMERIC;

    submodule_data->defines[dnx_data_field_state_table_define_address_size].name = "address_size";
    submodule_data->defines[dnx_data_field_state_table_define_address_size].doc = "Size of the address field in State Table in bits";
    
    submodule_data->defines[dnx_data_field_state_table_define_address_size].flags |= DNXC_DATA_F_NUMERIC;

    submodule_data->defines[dnx_data_field_state_table_define_address_max].name = "address_max";
    submodule_data->defines[dnx_data_field_state_table_define_address_max].doc = "Max address for the state table";
    
    submodule_data->defines[dnx_data_field_state_table_define_address_max].flags |= DNXC_DATA_F_NUMERIC;

    submodule_data->defines[dnx_data_field_state_table_define_wr_bit_size].name = "wr_bit_size";
    submodule_data->defines[dnx_data_field_state_table_define_wr_bit_size].doc = "Size of wr bit field in state table interface in bits.";
    
    submodule_data->defines[dnx_data_field_state_table_define_wr_bit_size].flags |= DNXC_DATA_F_NUMERIC;

    submodule_data->defines[dnx_data_field_state_table_define_key_size].name = "key_size";
    submodule_data->defines[dnx_data_field_state_table_define_key_size].doc = "Size of the state table key in the system. Changes between RW or RMW according to device.";
    
    submodule_data->defines[dnx_data_field_state_table_define_key_size].flags |= DNXC_DATA_F_NUMERIC;

    
    submodule_data->nof_tables = _dnx_data_field_state_table_table_nof;
    DNXC_DATA_ALLOC(submodule_data->tables, dnxc_data_table_t, submodule_data->nof_tables, "_dnxc_data field state_table tables");


exit:
    SHR_FUNC_EXIT;
}


int
dnx_data_field_state_table_feature_get(
    int unit,
    dnx_data_field_state_table_feature_e feature)
{
    return dnxc_data_mgmt_feature_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_state_table, feature);
}


uint32
dnx_data_field_state_table_supported_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_state_table, dnx_data_field_state_table_define_supported);
}

uint32
dnx_data_field_state_table_address_size_entry_max_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_state_table, dnx_data_field_state_table_define_address_size_entry_max);
}

uint32
dnx_data_field_state_table_data_size_entry_max_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_state_table, dnx_data_field_state_table_define_data_size_entry_max);
}

uint32
dnx_data_field_state_table_address_max_entry_max_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_state_table, dnx_data_field_state_table_define_address_max_entry_max);
}

uint32
dnx_data_field_state_table_wr_bit_size_rw_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_state_table, dnx_data_field_state_table_define_wr_bit_size_rw);
}

uint32
dnx_data_field_state_table_opcode_size_rmw_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_state_table, dnx_data_field_state_table_define_opcode_size_rmw);
}

uint32
dnx_data_field_state_table_ipmf2_key_select_supported_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_state_table, dnx_data_field_state_table_define_ipmf2_key_select_supported);
}

uint32
dnx_data_field_state_table_data_size_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_state_table, dnx_data_field_state_table_define_data_size);
}

uint32
dnx_data_field_state_table_state_table_stage_key_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_state_table, dnx_data_field_state_table_define_state_table_stage_key);
}

uint32
dnx_data_field_state_table_address_size_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_state_table, dnx_data_field_state_table_define_address_size);
}

uint32
dnx_data_field_state_table_address_max_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_state_table, dnx_data_field_state_table_define_address_max);
}

uint32
dnx_data_field_state_table_wr_bit_size_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_state_table, dnx_data_field_state_table_define_wr_bit_size);
}

uint32
dnx_data_field_state_table_key_size_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_state_table, dnx_data_field_state_table_define_key_size);
}










static shr_error_e
dnx_data_field_sce_init(
    int unit,
    dnxc_data_submodule_t *submodule_data)
{
    SHR_FUNC_INIT_VARS(unit);

    submodule_data->name = "sce";
    submodule_data->doc = "State Collection Engine definitions";
    
    submodule_data->nof_features = _dnx_data_field_sce_feature_nof;
    DNXC_DATA_ALLOC(submodule_data->features, dnxc_data_feature_t,  submodule_data->nof_features, "_dnxc_data field sce features");

    
    submodule_data->nof_defines = _dnx_data_field_sce_define_nof;
    DNXC_DATA_ALLOC(submodule_data->defines, dnxc_data_define_t, submodule_data->nof_defines, "_dnxc_data field sce defines");

    
    submodule_data->nof_tables = _dnx_data_field_sce_table_nof;
    DNXC_DATA_ALLOC(submodule_data->tables, dnxc_data_table_t, submodule_data->nof_tables, "_dnxc_data field sce tables");


exit:
    SHR_FUNC_EXIT;
}


int
dnx_data_field_sce_feature_get(
    int unit,
    dnx_data_field_sce_feature_e feature)
{
    return dnxc_data_mgmt_feature_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_sce, feature);
}











static shr_error_e
dnx_data_field_mdb_dt_init(
    int unit,
    dnxc_data_submodule_t *submodule_data)
{
    SHR_FUNC_INIT_VARS(unit);

    submodule_data->name = "mdb_dt";
    submodule_data->doc = "MDB Large direct Data";
    
    submodule_data->nof_features = _dnx_data_field_mdb_dt_feature_nof;
    DNXC_DATA_ALLOC(submodule_data->features, dnxc_data_feature_t,  submodule_data->nof_features, "_dnxc_data field mdb_dt features");

    
    submodule_data->nof_defines = _dnx_data_field_mdb_dt_define_nof;
    DNXC_DATA_ALLOC(submodule_data->defines, dnxc_data_define_t, submodule_data->nof_defines, "_dnxc_data field mdb_dt defines");

    submodule_data->defines[dnx_data_field_mdb_dt_define_supported].name = "supported";
    submodule_data->defines[dnx_data_field_mdb_dt_define_supported].doc = "Maps supported";
    
    submodule_data->defines[dnx_data_field_mdb_dt_define_supported].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_mdb_dt_define_key_size].name = "key_size";
    submodule_data->defines[dnx_data_field_mdb_dt_define_key_size].doc = "Size of the MDB_DT key in the system";
    
    submodule_data->defines[dnx_data_field_mdb_dt_define_key_size].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_mdb_dt_define_action_size_large].name = "action_size_large";
    submodule_data->defines[dnx_data_field_mdb_dt_define_action_size_large].doc = "Size of the large MAP action in the system";
    
    submodule_data->defines[dnx_data_field_mdb_dt_define_action_size_large].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_mdb_dt_define_ipmf1_key_select_supported].name = "ipmf1_key_select_supported";
    submodule_data->defines[dnx_data_field_mdb_dt_define_ipmf1_key_select_supported].doc = "True in case MDB_DT key select is supporetd for iPMF1 stage";
    
    submodule_data->defines[dnx_data_field_mdb_dt_define_ipmf1_key_select_supported].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_mdb_dt_define_ipmf1_key_select].name = "ipmf1_key_select";
    submodule_data->defines[dnx_data_field_mdb_dt_define_ipmf1_key_select].doc = "The PMF key used for MDB_DT lookup by iPMF1. The value is the offset from the first key in the stage.";
    
    submodule_data->defines[dnx_data_field_mdb_dt_define_ipmf1_key_select].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_mdb_dt_define_ipmf2_key_select_supported].name = "ipmf2_key_select_supported";
    submodule_data->defines[dnx_data_field_mdb_dt_define_ipmf2_key_select_supported].doc = "True in case MDB_DT key select is supporetd for iPMF2 stage";
    
    submodule_data->defines[dnx_data_field_mdb_dt_define_ipmf2_key_select_supported].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_mdb_dt_define_ipmf2_key_select].name = "ipmf2_key_select";
    submodule_data->defines[dnx_data_field_mdb_dt_define_ipmf2_key_select].doc = "The PMF key used for MDB_DT lookup by iPMF2. The value is the offset from the first key in the stage.";
    
    submodule_data->defines[dnx_data_field_mdb_dt_define_ipmf2_key_select].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_mdb_dt_define_ipmf3_key_select_supported].name = "ipmf3_key_select_supported";
    submodule_data->defines[dnx_data_field_mdb_dt_define_ipmf3_key_select_supported].doc = "True in case MDB_DT key select is supporetd for iPMF3 stage";
    
    submodule_data->defines[dnx_data_field_mdb_dt_define_ipmf3_key_select_supported].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_mdb_dt_define_ipmf3_key_select].name = "ipmf3_key_select";
    submodule_data->defines[dnx_data_field_mdb_dt_define_ipmf3_key_select].doc = "The PMF key used for MDB_DT lookup by iPMF3. The value is the offset from the first key in the stage.";
    
    submodule_data->defines[dnx_data_field_mdb_dt_define_ipmf3_key_select].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_mdb_dt_define_pmf_map_stage].name = "pmf_map_stage";
    submodule_data->defines[dnx_data_field_mdb_dt_define_pmf_map_stage].doc = "Determines using SOC property if we use MDB_DT in iPMF1/iPMF2 or iPMF3.";
    
    submodule_data->defines[dnx_data_field_mdb_dt_define_pmf_map_stage].flags |= DNXC_DATA_F_NUMERIC;

    
    submodule_data->nof_tables = _dnx_data_field_mdb_dt_table_nof;
    DNXC_DATA_ALLOC(submodule_data->tables, dnxc_data_table_t, submodule_data->nof_tables, "_dnxc_data field mdb_dt tables");


exit:
    SHR_FUNC_EXIT;
}


int
dnx_data_field_mdb_dt_feature_get(
    int unit,
    dnx_data_field_mdb_dt_feature_e feature)
{
    return dnxc_data_mgmt_feature_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_mdb_dt, feature);
}


uint32
dnx_data_field_mdb_dt_supported_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_mdb_dt, dnx_data_field_mdb_dt_define_supported);
}

uint32
dnx_data_field_mdb_dt_key_size_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_mdb_dt, dnx_data_field_mdb_dt_define_key_size);
}

uint32
dnx_data_field_mdb_dt_action_size_large_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_mdb_dt, dnx_data_field_mdb_dt_define_action_size_large);
}

uint32
dnx_data_field_mdb_dt_ipmf1_key_select_supported_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_mdb_dt, dnx_data_field_mdb_dt_define_ipmf1_key_select_supported);
}

uint32
dnx_data_field_mdb_dt_ipmf1_key_select_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_mdb_dt, dnx_data_field_mdb_dt_define_ipmf1_key_select);
}

uint32
dnx_data_field_mdb_dt_ipmf2_key_select_supported_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_mdb_dt, dnx_data_field_mdb_dt_define_ipmf2_key_select_supported);
}

uint32
dnx_data_field_mdb_dt_ipmf2_key_select_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_mdb_dt, dnx_data_field_mdb_dt_define_ipmf2_key_select);
}

uint32
dnx_data_field_mdb_dt_ipmf3_key_select_supported_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_mdb_dt, dnx_data_field_mdb_dt_define_ipmf3_key_select_supported);
}

uint32
dnx_data_field_mdb_dt_ipmf3_key_select_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_mdb_dt, dnx_data_field_mdb_dt_define_ipmf3_key_select);
}

uint32
dnx_data_field_mdb_dt_pmf_map_stage_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_mdb_dt, dnx_data_field_mdb_dt_define_pmf_map_stage);
}










static shr_error_e
dnx_data_field_hash_init(
    int unit,
    dnxc_data_submodule_t *submodule_data)
{
    SHR_FUNC_INIT_VARS(unit);

    submodule_data->name = "hash";
    submodule_data->doc = "Hash (CRC) values";
    
    submodule_data->nof_features = _dnx_data_field_hash_feature_nof;
    DNXC_DATA_ALLOC(submodule_data->features, dnxc_data_feature_t,  submodule_data->nof_features, "_dnxc_data field hash features");

    
    submodule_data->nof_defines = _dnx_data_field_hash_define_nof;
    DNXC_DATA_ALLOC(submodule_data->defines, dnxc_data_define_t, submodule_data->nof_defines, "_dnxc_data field hash defines");

    submodule_data->defines[dnx_data_field_hash_define_max_key_size].name = "max_key_size";
    submodule_data->defines[dnx_data_field_hash_define_max_key_size].doc = "maximal key size Field Group type ";
    
    submodule_data->defines[dnx_data_field_hash_define_max_key_size].flags |= DNXC_DATA_F_DEFINE;

    
    submodule_data->nof_tables = _dnx_data_field_hash_table_nof;
    DNXC_DATA_ALLOC(submodule_data->tables, dnxc_data_table_t, submodule_data->nof_tables, "_dnxc_data field hash tables");


exit:
    SHR_FUNC_EXIT;
}


int
dnx_data_field_hash_feature_get(
    int unit,
    dnx_data_field_hash_feature_e feature)
{
    return dnxc_data_mgmt_feature_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_hash, feature);
}


uint32
dnx_data_field_hash_max_key_size_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_hash, dnx_data_field_hash_define_max_key_size);
}










static shr_error_e
dnx_data_field_udh_init(
    int unit,
    dnxc_data_submodule_t *submodule_data)
{
    SHR_FUNC_INIT_VARS(unit);

    submodule_data->name = "udh";
    submodule_data->doc = "User Defined Headers defines";
    
    submodule_data->nof_features = _dnx_data_field_udh_feature_nof;
    DNXC_DATA_ALLOC(submodule_data->features, dnxc_data_feature_t,  submodule_data->nof_features, "_dnxc_data field udh features");

    
    submodule_data->nof_defines = _dnx_data_field_udh_define_nof;
    DNXC_DATA_ALLOC(submodule_data->defines, dnxc_data_define_t, submodule_data->nof_defines, "_dnxc_data field udh defines");

    submodule_data->defines[dnx_data_field_udh_define_ext_supported].name = "ext_supported";
    submodule_data->defines[dnx_data_field_udh_define_ext_supported].doc = "If UDH0 and UDH1 extensions are supported";
    
    submodule_data->defines[dnx_data_field_udh_define_ext_supported].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_udh_define_type_count].name = "type_count";
    submodule_data->defines[dnx_data_field_udh_define_type_count].doc = "UDH Type count";
    
    submodule_data->defines[dnx_data_field_udh_define_type_count].flags |= DNXC_DATA_F_DEFINE;

#ifdef BCM_DNX2_SUPPORT

    if (soc_is(unit, DNX2_DEVICE))
    {
        submodule_data->defines[dnx_data_field_udh_define_type_0_length].name = "type_0_length";
        submodule_data->defines[dnx_data_field_udh_define_type_0_length].doc = "UDH Type 0 length in bytes";
        
        submodule_data->defines[dnx_data_field_udh_define_type_0_length].flags |= DNXC_DATA_F_DEFINE;
    }

#endif 
#ifdef BCM_DNX2_SUPPORT

    if (soc_is(unit, DNX2_DEVICE))
    {
        submodule_data->defines[dnx_data_field_udh_define_type_1_length].name = "type_1_length";
        submodule_data->defines[dnx_data_field_udh_define_type_1_length].doc = "UDH Type 1 length in bytes";
        
        submodule_data->defines[dnx_data_field_udh_define_type_1_length].flags |= DNXC_DATA_F_DEFINE;
    }

#endif 
#ifdef BCM_DNX2_SUPPORT

    if (soc_is(unit, DNX2_DEVICE))
    {
        submodule_data->defines[dnx_data_field_udh_define_type_2_length].name = "type_2_length";
        submodule_data->defines[dnx_data_field_udh_define_type_2_length].doc = "UDH Type 2 length in bytes";
        
        submodule_data->defines[dnx_data_field_udh_define_type_2_length].flags |= DNXC_DATA_F_DEFINE;
    }

#endif 
#ifdef BCM_DNX2_SUPPORT

    if (soc_is(unit, DNX2_DEVICE))
    {
        submodule_data->defines[dnx_data_field_udh_define_type_3_length].name = "type_3_length";
        submodule_data->defines[dnx_data_field_udh_define_type_3_length].doc = "UDH Type 3 length in bytes";
        
        submodule_data->defines[dnx_data_field_udh_define_type_3_length].flags |= DNXC_DATA_F_DEFINE;
    }

#endif 
    submodule_data->defines[dnx_data_field_udh_define_field_class_id_size_0].name = "field_class_id_size_0";
    submodule_data->defines[dnx_data_field_udh_define_field_class_id_size_0].doc = "J1 Mode UDH related size";
    
    submodule_data->defines[dnx_data_field_udh_define_field_class_id_size_0].flags |= DNXC_DATA_F_NUMERIC;

    submodule_data->defines[dnx_data_field_udh_define_field_class_id_size_1].name = "field_class_id_size_1";
    submodule_data->defines[dnx_data_field_udh_define_field_class_id_size_1].doc = "J1 Mode UDH retlated size";
    
    submodule_data->defines[dnx_data_field_udh_define_field_class_id_size_1].flags |= DNXC_DATA_F_NUMERIC;

    submodule_data->defines[dnx_data_field_udh_define_field_class_id_size_2].name = "field_class_id_size_2";
    submodule_data->defines[dnx_data_field_udh_define_field_class_id_size_2].doc = "J1 Mode UDH retlated size";
    
    submodule_data->defines[dnx_data_field_udh_define_field_class_id_size_2].flags |= DNXC_DATA_F_NUMERIC;

    submodule_data->defines[dnx_data_field_udh_define_field_class_id_size_3].name = "field_class_id_size_3";
    submodule_data->defines[dnx_data_field_udh_define_field_class_id_size_3].doc = "J1 Mode UDH retlated size";
    
    submodule_data->defines[dnx_data_field_udh_define_field_class_id_size_3].flags |= DNXC_DATA_F_NUMERIC;

    submodule_data->defines[dnx_data_field_udh_define_field_class_id_total_size].name = "field_class_id_total_size";
    submodule_data->defines[dnx_data_field_udh_define_field_class_id_total_size].doc = "J1 Mode UDH retlated size";
    
    submodule_data->defines[dnx_data_field_udh_define_field_class_id_total_size].flags |= DNXC_DATA_F_NUMERIC;

    
    submodule_data->nof_tables = _dnx_data_field_udh_table_nof;
    DNXC_DATA_ALLOC(submodule_data->tables, dnxc_data_table_t, submodule_data->nof_tables, "_dnxc_data field udh tables");


exit:
    SHR_FUNC_EXIT;
}


int
dnx_data_field_udh_feature_get(
    int unit,
    dnx_data_field_udh_feature_e feature)
{
    return dnxc_data_mgmt_feature_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_udh, feature);
}


uint32
dnx_data_field_udh_ext_supported_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_udh, dnx_data_field_udh_define_ext_supported);
}

uint32
dnx_data_field_udh_type_count_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_udh, dnx_data_field_udh_define_type_count);
}

#ifdef BCM_DNX2_SUPPORT

uint32
dnx_data_field_udh_type_0_length_get(
    int unit)
{
    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "type_0_length", "DNX2");
    }
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_udh, dnx_data_field_udh_define_type_0_length);
}


#endif 
#ifdef BCM_DNX2_SUPPORT

uint32
dnx_data_field_udh_type_1_length_get(
    int unit)
{
    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "type_1_length", "DNX2");
    }
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_udh, dnx_data_field_udh_define_type_1_length);
}


#endif 
#ifdef BCM_DNX2_SUPPORT

uint32
dnx_data_field_udh_type_2_length_get(
    int unit)
{
    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "type_2_length", "DNX2");
    }
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_udh, dnx_data_field_udh_define_type_2_length);
}


#endif 
#ifdef BCM_DNX2_SUPPORT

uint32
dnx_data_field_udh_type_3_length_get(
    int unit)
{
    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "type_3_length", "DNX2");
    }
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_udh, dnx_data_field_udh_define_type_3_length);
}


#endif 
uint32
dnx_data_field_udh_field_class_id_size_0_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_udh, dnx_data_field_udh_define_field_class_id_size_0);
}

uint32
dnx_data_field_udh_field_class_id_size_1_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_udh, dnx_data_field_udh_define_field_class_id_size_1);
}

uint32
dnx_data_field_udh_field_class_id_size_2_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_udh, dnx_data_field_udh_define_field_class_id_size_2);
}

uint32
dnx_data_field_udh_field_class_id_size_3_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_udh, dnx_data_field_udh_define_field_class_id_size_3);
}

uint32
dnx_data_field_udh_field_class_id_total_size_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_udh, dnx_data_field_udh_define_field_class_id_total_size);
}










static shr_error_e
dnx_data_field_system_headers_init(
    int unit,
    dnxc_data_submodule_t *submodule_data)
{
    SHR_FUNC_INIT_VARS(unit);

    submodule_data->name = "system_headers";
    submodule_data->doc = "System headers definitions";
    
    submodule_data->nof_features = _dnx_data_field_system_headers_feature_nof;
    DNXC_DATA_ALLOC(submodule_data->features, dnxc_data_feature_t,  submodule_data->nof_features, "_dnxc_data field system_headers features");

    
    submodule_data->nof_defines = _dnx_data_field_system_headers_define_nof;
    DNXC_DATA_ALLOC(submodule_data->defines, dnxc_data_define_t, submodule_data->nof_defines, "_dnxc_data field system_headers defines");

    submodule_data->defines[dnx_data_field_system_headers_define_nof_profiles].name = "nof_profiles";
    submodule_data->defines[dnx_data_field_system_headers_define_nof_profiles].doc = "Number of system headers in device";
    
    submodule_data->defines[dnx_data_field_system_headers_define_nof_profiles].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_system_headers_define_pph_learn_ext_disable].name = "pph_learn_ext_disable";
    submodule_data->defines[dnx_data_field_system_headers_define_pph_learn_ext_disable].doc = "Never add learn_ext in system headers unlesee FP required. Used by default header_profile only.";
    
    submodule_data->defines[dnx_data_field_system_headers_define_pph_learn_ext_disable].flags |= DNXC_DATA_F_NUMERIC;

    
    submodule_data->nof_tables = _dnx_data_field_system_headers_table_nof;
    DNXC_DATA_ALLOC(submodule_data->tables, dnxc_data_table_t, submodule_data->nof_tables, "_dnxc_data field system_headers tables");

    
    submodule_data->tables[dnx_data_field_system_headers_table_system_header_profiles].name = "system_header_profiles";
    submodule_data->tables[dnx_data_field_system_headers_table_system_header_profiles].doc = "Contains all system headers profiles defined in this device";
    submodule_data->tables[dnx_data_field_system_headers_table_system_header_profiles].flags |= DNXC_DATA_F_TABLE;
    submodule_data->tables[dnx_data_field_system_headers_table_system_header_profiles].size_of_values = sizeof(dnx_data_field_system_headers_system_header_profiles_t);
    submodule_data->tables[dnx_data_field_system_headers_table_system_header_profiles].entry_get = dnx_data_field_system_headers_system_header_profiles_entry_str_get;

    
    submodule_data->tables[dnx_data_field_system_headers_table_system_header_profiles].nof_keys = 1;
    submodule_data->tables[dnx_data_field_system_headers_table_system_header_profiles].keys[0].name = "system_header_profile";
    submodule_data->tables[dnx_data_field_system_headers_table_system_header_profiles].keys[0].doc = "System header profile number";

    
    submodule_data->tables[dnx_data_field_system_headers_table_system_header_profiles].nof_values = 6;
    DNXC_DATA_ALLOC(submodule_data->tables[dnx_data_field_system_headers_table_system_header_profiles].values, dnxc_data_value_t, submodule_data->tables[dnx_data_field_system_headers_table_system_header_profiles].nof_values, "_dnx_data_field_system_headers_table_system_header_profiles table values");
    submodule_data->tables[dnx_data_field_system_headers_table_system_header_profiles].values[0].name = "name";
    submodule_data->tables[dnx_data_field_system_headers_table_system_header_profiles].values[0].type = "char *";
    submodule_data->tables[dnx_data_field_system_headers_table_system_header_profiles].values[0].doc = "profile name";
    submodule_data->tables[dnx_data_field_system_headers_table_system_header_profiles].values[0].offset = UTILEX_OFFSETOF(dnx_data_field_system_headers_system_header_profiles_t, name);
    submodule_data->tables[dnx_data_field_system_headers_table_system_header_profiles].values[1].name = "build_ftmh";
    submodule_data->tables[dnx_data_field_system_headers_table_system_header_profiles].values[1].type = "uint8";
    submodule_data->tables[dnx_data_field_system_headers_table_system_header_profiles].values[1].doc = "Defines whether to build FTMH header or not";
    submodule_data->tables[dnx_data_field_system_headers_table_system_header_profiles].values[1].offset = UTILEX_OFFSETOF(dnx_data_field_system_headers_system_header_profiles_t, build_ftmh);
    submodule_data->tables[dnx_data_field_system_headers_table_system_header_profiles].values[2].name = "build_tsh";
    submodule_data->tables[dnx_data_field_system_headers_table_system_header_profiles].values[2].type = "uint8";
    submodule_data->tables[dnx_data_field_system_headers_table_system_header_profiles].values[2].doc = "Defines whether to build TSH header or not";
    submodule_data->tables[dnx_data_field_system_headers_table_system_header_profiles].values[2].offset = UTILEX_OFFSETOF(dnx_data_field_system_headers_system_header_profiles_t, build_tsh);
    submodule_data->tables[dnx_data_field_system_headers_table_system_header_profiles].values[3].name = "build_pph";
    submodule_data->tables[dnx_data_field_system_headers_table_system_header_profiles].values[3].type = "uint8";
    submodule_data->tables[dnx_data_field_system_headers_table_system_header_profiles].values[3].doc = "Defines whether to build PPH header or not";
    submodule_data->tables[dnx_data_field_system_headers_table_system_header_profiles].values[3].offset = UTILEX_OFFSETOF(dnx_data_field_system_headers_system_header_profiles_t, build_pph);
    submodule_data->tables[dnx_data_field_system_headers_table_system_header_profiles].values[4].name = "build_udh";
    submodule_data->tables[dnx_data_field_system_headers_table_system_header_profiles].values[4].type = "uint8";
    submodule_data->tables[dnx_data_field_system_headers_table_system_header_profiles].values[4].doc = "Defines whether to build UDH header or not";
    submodule_data->tables[dnx_data_field_system_headers_table_system_header_profiles].values[4].offset = UTILEX_OFFSETOF(dnx_data_field_system_headers_system_header_profiles_t, build_udh);
    submodule_data->tables[dnx_data_field_system_headers_table_system_header_profiles].values[5].name = "never_add_pph_learn_ext";
    submodule_data->tables[dnx_data_field_system_headers_table_system_header_profiles].values[5].type = "uint8";
    submodule_data->tables[dnx_data_field_system_headers_table_system_header_profiles].values[5].doc = "Defines whether to never add PPH Learn Ext.";
    submodule_data->tables[dnx_data_field_system_headers_table_system_header_profiles].values[5].offset = UTILEX_OFFSETOF(dnx_data_field_system_headers_system_header_profiles_t, never_add_pph_learn_ext);


exit:
    SHR_FUNC_EXIT;
}


int
dnx_data_field_system_headers_feature_get(
    int unit,
    dnx_data_field_system_headers_feature_e feature)
{
    return dnxc_data_mgmt_feature_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_system_headers, feature);
}


uint32
dnx_data_field_system_headers_nof_profiles_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_system_headers, dnx_data_field_system_headers_define_nof_profiles);
}

uint32
dnx_data_field_system_headers_pph_learn_ext_disable_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_system_headers, dnx_data_field_system_headers_define_pph_learn_ext_disable);
}



const dnx_data_field_system_headers_system_header_profiles_t *
dnx_data_field_system_headers_system_header_profiles_get(
    int unit,
    int system_header_profile)
{
    char *data;
    dnxc_data_table_t *table;

    
    table = dnxc_data_mgmt_table_get(unit, dnx_data_module_field, dnx_data_field_submodule_system_headers, dnx_data_field_system_headers_table_system_header_profiles);
    
    data = dnxc_data_mgmt_table_data_get(unit, table, system_header_profile, 0);
    return (const dnx_data_field_system_headers_system_header_profiles_t *) data;

}


shr_error_e
dnx_data_field_system_headers_system_header_profiles_entry_str_get(
    int unit,
    char *buffer,
    int key0,
    int key1,
    int value_index)
{
    dnxc_data_table_t *table;
    const dnx_data_field_system_headers_system_header_profiles_t *data;
    SHR_FUNC_INIT_VARS(unit);

    
    table = dnxc_data_mgmt_table_get(unit, dnx_data_module_field, dnx_data_field_submodule_system_headers, dnx_data_field_system_headers_table_system_header_profiles);
    data = (const dnx_data_field_system_headers_system_header_profiles_t *) dnxc_data_mgmt_table_data_diag_get(unit, table, key0, 0);
    switch (value_index)
    {
        case 0:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%s", data->name == NULL ? "" : data->name);
            break;
        case 1:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->build_ftmh);
            break;
        case 2:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->build_tsh);
            break;
        case 3:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->build_pph);
            break;
        case 4:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->build_udh);
            break;
        case 5:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->never_add_pph_learn_ext);
            break;
    }

    SHR_FUNC_EXIT;
}


const dnxc_data_table_info_t *
dnx_data_field_system_headers_system_header_profiles_info_get(
    int unit)
{

    
    return dnxc_data_mgmt_table_info_get(unit, dnx_data_module_field, dnx_data_field_submodule_system_headers, dnx_data_field_system_headers_table_system_header_profiles);

}






static shr_error_e
dnx_data_field_exem_init(
    int unit,
    dnxc_data_submodule_t *submodule_data)
{
    SHR_FUNC_INIT_VARS(unit);

    submodule_data->name = "exem";
    submodule_data->doc = "exem values";
    
    submodule_data->nof_features = _dnx_data_field_exem_feature_nof;
    DNXC_DATA_ALLOC(submodule_data->features, dnxc_data_feature_t,  submodule_data->nof_features, "_dnxc_data field exem features");

    submodule_data->features[dnx_data_field_exem_stage_selection_includes_ipmf1].name = "stage_selection_includes_ipmf1";
    submodule_data->features[dnx_data_field_exem_stage_selection_includes_ipmf1].doc = "Determines what are the stage options to choose from for SEXEM/NEXEM.";
    submodule_data->features[dnx_data_field_exem_stage_selection_includes_ipmf1].flags |= DNXC_DATA_F_FEATURE;

    submodule_data->features[dnx_data_field_exem_exem_vmv_padded_for_2msb].name = "exem_vmv_padded_for_2msb";
    submodule_data->features[dnx_data_field_exem_exem_vmv_padded_for_2msb].doc = "If TRUE we increase the size of the VMV by 2.";
    submodule_data->features[dnx_data_field_exem_exem_vmv_padded_for_2msb].flags |= DNXC_DATA_F_FEATURE;

    
    submodule_data->nof_defines = _dnx_data_field_exem_define_nof;
    DNXC_DATA_ALLOC(submodule_data->defines, dnxc_data_define_t, submodule_data->nof_defines, "_dnxc_data field exem defines");

    submodule_data->defines[dnx_data_field_exem_define_small_app_db_id_size].name = "small_app_db_id_size";
    submodule_data->defines[dnx_data_field_exem_define_small_app_db_id_size].doc = "Number of bits used application db";
    
    submodule_data->defines[dnx_data_field_exem_define_small_app_db_id_size].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_exem_define_large_app_db_id_size].name = "large_app_db_id_size";
    submodule_data->defines[dnx_data_field_exem_define_large_app_db_id_size].doc = "Number of bits used application db";
    
    submodule_data->defines[dnx_data_field_exem_define_large_app_db_id_size].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_exem_define_small_max_key_size].name = "small_max_key_size";
    submodule_data->defines[dnx_data_field_exem_define_small_max_key_size].doc = "Small EXEM key size in bits";
    
    submodule_data->defines[dnx_data_field_exem_define_small_max_key_size].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_exem_define_large_max_key_size].name = "large_max_key_size";
    submodule_data->defines[dnx_data_field_exem_define_large_max_key_size].doc = "Large EXEM key size in bits";
    
    submodule_data->defines[dnx_data_field_exem_define_large_max_key_size].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_exem_define_max_result_size_all_stages].name = "max_result_size_all_stages";
    submodule_data->defines[dnx_data_field_exem_define_max_result_size_all_stages].doc = "Maximum EXEM result (payload) size in bits, including VMV, amongst all stages";
    
    submodule_data->defines[dnx_data_field_exem_define_max_result_size_all_stages].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_exem_define_small_max_container_size].name = "small_max_container_size";
    submodule_data->defines[dnx_data_field_exem_define_small_max_container_size].doc = "Large EXEM maximal container size in bits";
    
    submodule_data->defines[dnx_data_field_exem_define_small_max_container_size].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_exem_define_large_max_container_size].name = "large_max_container_size";
    submodule_data->defines[dnx_data_field_exem_define_large_max_container_size].doc = "Large EXEM result (payload) size in bits";
    
    submodule_data->defines[dnx_data_field_exem_define_large_max_container_size].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_exem_define_small_min_app_db_id_range].name = "small_min_app_db_id_range";
    submodule_data->defines[dnx_data_field_exem_define_small_min_app_db_id_range].doc = "Small EXEM first APP_DB_ID allocated to PMF module";
    
    submodule_data->defines[dnx_data_field_exem_define_small_min_app_db_id_range].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_exem_define_large_min_app_db_id_range].name = "large_min_app_db_id_range";
    submodule_data->defines[dnx_data_field_exem_define_large_min_app_db_id_range].doc = "Large EXEM first APP_DB_ID allocated to PMF module";
    
    submodule_data->defines[dnx_data_field_exem_define_large_min_app_db_id_range].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_exem_define_small_max_app_db_id_range].name = "small_max_app_db_id_range";
    submodule_data->defines[dnx_data_field_exem_define_small_max_app_db_id_range].doc = "Small EXEM last APP_DB_ID allocated to PMF module";
    
    submodule_data->defines[dnx_data_field_exem_define_small_max_app_db_id_range].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_exem_define_large_max_app_db_id_range].name = "large_max_app_db_id_range";
    submodule_data->defines[dnx_data_field_exem_define_large_max_app_db_id_range].doc = "Large EXEM last APP_DB_ID allocated to PMF module";
    
    submodule_data->defines[dnx_data_field_exem_define_large_max_app_db_id_range].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_exem_define_small_ipmf2_key].name = "small_ipmf2_key";
    submodule_data->defines[dnx_data_field_exem_define_small_ipmf2_key].doc = "The PMF key used for EXEM lookup by iPMF2. The value is the offset from the first key in the stage.";
    
    submodule_data->defines[dnx_data_field_exem_define_small_ipmf2_key].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_exem_define_small_ipmf2_key_part].name = "small_ipmf2_key_part";
    submodule_data->defines[dnx_data_field_exem_define_small_ipmf2_key_part].doc = "The PMF key part used for EXEM lookup by iPMF2. 0 means the LSB half, 1 the MSB half.";
    
    submodule_data->defines[dnx_data_field_exem_define_small_ipmf2_key_part].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_exem_define_small_ipmf2_key_hw_value].name = "small_ipmf2_key_hw_value";
    submodule_data->defines[dnx_data_field_exem_define_small_ipmf2_key_hw_value].doc = "The HW value to provide for selecting small_ipmf2_key and small_ipmf2_key_part.";
    
    submodule_data->defines[dnx_data_field_exem_define_small_ipmf2_key_hw_value].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_exem_define_small_ipmf2_key_hw_bits].name = "small_ipmf2_key_hw_bits";
    submodule_data->defines[dnx_data_field_exem_define_small_ipmf2_key_hw_bits].doc = "The number of bits used by the HW for selecting small_ipmf2_key and small_ipmf2_key_part.";
    
    submodule_data->defines[dnx_data_field_exem_define_small_ipmf2_key_hw_bits].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_exem_define_ipmf1_key_configurable].name = "ipmf1_key_configurable";
    submodule_data->defines[dnx_data_field_exem_define_ipmf1_key_configurable].doc = "Whether or not the EXEM key for iPMF1 can be configured on a chip wide basis.";
    
    submodule_data->defines[dnx_data_field_exem_define_ipmf1_key_configurable].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_exem_define_ipmf2_key_configurable].name = "ipmf2_key_configurable";
    submodule_data->defines[dnx_data_field_exem_define_ipmf2_key_configurable].doc = "Whether or not the EXEM key for iPMF2 can be configured on a chip wide basis.";
    
    submodule_data->defines[dnx_data_field_exem_define_ipmf2_key_configurable].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_exem_define_ipmf1_key].name = "ipmf1_key";
    submodule_data->defines[dnx_data_field_exem_define_ipmf1_key].doc = "The PMF key used for EXEM lookup by iPMF1. The value is the offset from the first key in the stage.";
    
    submodule_data->defines[dnx_data_field_exem_define_ipmf1_key].flags |= DNXC_DATA_F_DEFINE;

#ifdef BCM_DNX2_SUPPORT

    if (soc_is(unit, DNX2_DEVICE))
    {
        submodule_data->defines[dnx_data_field_exem_define_pmf_sexem3_stage].name = "pmf_sexem3_stage";
        submodule_data->defines[dnx_data_field_exem_define_pmf_sexem3_stage].doc = "Determines using SOC property if we use SEXEM3 in iPMF2 or iPMF3.";
        
        submodule_data->defines[dnx_data_field_exem_define_pmf_sexem3_stage].flags |= DNXC_DATA_F_NUMERIC;
    }

#endif 
    
    submodule_data->nof_tables = _dnx_data_field_exem_table_nof;
    DNXC_DATA_ALLOC(submodule_data->tables, dnxc_data_table_t, submodule_data->nof_tables, "_dnxc_data field exem tables");


exit:
    SHR_FUNC_EXIT;
}


int
dnx_data_field_exem_feature_get(
    int unit,
    dnx_data_field_exem_feature_e feature)
{
    return dnxc_data_mgmt_feature_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_exem, feature);
}


uint32
dnx_data_field_exem_small_app_db_id_size_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_exem, dnx_data_field_exem_define_small_app_db_id_size);
}

uint32
dnx_data_field_exem_large_app_db_id_size_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_exem, dnx_data_field_exem_define_large_app_db_id_size);
}

uint32
dnx_data_field_exem_small_max_key_size_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_exem, dnx_data_field_exem_define_small_max_key_size);
}

uint32
dnx_data_field_exem_large_max_key_size_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_exem, dnx_data_field_exem_define_large_max_key_size);
}

uint32
dnx_data_field_exem_max_result_size_all_stages_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_exem, dnx_data_field_exem_define_max_result_size_all_stages);
}

uint32
dnx_data_field_exem_small_max_container_size_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_exem, dnx_data_field_exem_define_small_max_container_size);
}

uint32
dnx_data_field_exem_large_max_container_size_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_exem, dnx_data_field_exem_define_large_max_container_size);
}

uint32
dnx_data_field_exem_small_min_app_db_id_range_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_exem, dnx_data_field_exem_define_small_min_app_db_id_range);
}

uint32
dnx_data_field_exem_large_min_app_db_id_range_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_exem, dnx_data_field_exem_define_large_min_app_db_id_range);
}

uint32
dnx_data_field_exem_small_max_app_db_id_range_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_exem, dnx_data_field_exem_define_small_max_app_db_id_range);
}

uint32
dnx_data_field_exem_large_max_app_db_id_range_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_exem, dnx_data_field_exem_define_large_max_app_db_id_range);
}

uint32
dnx_data_field_exem_small_ipmf2_key_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_exem, dnx_data_field_exem_define_small_ipmf2_key);
}

uint32
dnx_data_field_exem_small_ipmf2_key_part_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_exem, dnx_data_field_exem_define_small_ipmf2_key_part);
}

uint32
dnx_data_field_exem_small_ipmf2_key_hw_value_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_exem, dnx_data_field_exem_define_small_ipmf2_key_hw_value);
}

uint32
dnx_data_field_exem_small_ipmf2_key_hw_bits_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_exem, dnx_data_field_exem_define_small_ipmf2_key_hw_bits);
}

uint32
dnx_data_field_exem_ipmf1_key_configurable_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_exem, dnx_data_field_exem_define_ipmf1_key_configurable);
}

uint32
dnx_data_field_exem_ipmf2_key_configurable_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_exem, dnx_data_field_exem_define_ipmf2_key_configurable);
}

uint32
dnx_data_field_exem_ipmf1_key_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_exem, dnx_data_field_exem_define_ipmf1_key);
}

#ifdef BCM_DNX2_SUPPORT

uint32
dnx_data_field_exem_pmf_sexem3_stage_get(
    int unit)
{
    
    if (!soc_is(unit, DNX2_DEVICE))
    {
        dnxc_data_mgmt_inaccessible_data_get(unit, "pmf_sexem3_stage", "DNX2");
    }
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_exem, dnx_data_field_exem_define_pmf_sexem3_stage);
}


#endif 









static shr_error_e
dnx_data_field_exem_learn_flush_machine_init(
    int unit,
    dnxc_data_submodule_t *submodule_data)
{
    SHR_FUNC_INIT_VARS(unit);

    submodule_data->name = "exem_learn_flush_machine";
    submodule_data->doc = "Inforamtion about the flush machine used for EXEM learning feature.";
    
    submodule_data->nof_features = _dnx_data_field_exem_learn_flush_machine_feature_nof;
    DNXC_DATA_ALLOC(submodule_data->features, dnxc_data_feature_t,  submodule_data->nof_features, "_dnxc_data field exem_learn_flush_machine features");

    
    submodule_data->nof_defines = _dnx_data_field_exem_learn_flush_machine_define_nof;
    DNXC_DATA_ALLOC(submodule_data->defines, dnxc_data_define_t, submodule_data->nof_defines, "_dnxc_data field exem_learn_flush_machine defines");

    submodule_data->defines[dnx_data_field_exem_learn_flush_machine_define_flush_machine_nof_entries].name = "flush_machine_nof_entries";
    submodule_data->defines[dnx_data_field_exem_learn_flush_machine_define_flush_machine_nof_entries].doc = "Number of entries in the flush machine.";
    
    submodule_data->defines[dnx_data_field_exem_learn_flush_machine_define_flush_machine_nof_entries].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_exem_learn_flush_machine_define_entry_extra_bits_for_hash].name = "entry_extra_bits_for_hash";
    submodule_data->defines[dnx_data_field_exem_learn_flush_machine_define_entry_extra_bits_for_hash].doc = "Number of bits added to the exem entry size to account for the hash bits.";
    
    submodule_data->defines[dnx_data_field_exem_learn_flush_machine_define_entry_extra_bits_for_hash].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_exem_learn_flush_machine_define_sexem_entry_max_size].name = "sexem_entry_max_size";
    submodule_data->defines[dnx_data_field_exem_learn_flush_machine_define_sexem_entry_max_size].doc = "Number of bits in HW that represent the SEXEM entry in the TCAM of the flush machine.";
    
    submodule_data->defines[dnx_data_field_exem_learn_flush_machine_define_sexem_entry_max_size].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_exem_learn_flush_machine_define_lexem_entry_max_size].name = "lexem_entry_max_size";
    submodule_data->defines[dnx_data_field_exem_learn_flush_machine_define_lexem_entry_max_size].doc = "Number of bits in HW that represent the LEXEM entry in the TCAM of the flush machine.";
    
    submodule_data->defines[dnx_data_field_exem_learn_flush_machine_define_lexem_entry_max_size].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_exem_learn_flush_machine_define_command_bit_transplant].name = "command_bit_transplant";
    submodule_data->defines[dnx_data_field_exem_learn_flush_machine_define_command_bit_transplant].doc = "The bit on the command field of the flush entry paylaod to set to change the payload of the EXEM entry.";
    
    submodule_data->defines[dnx_data_field_exem_learn_flush_machine_define_command_bit_transplant].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_exem_learn_flush_machine_define_command_bit_delete].name = "command_bit_delete";
    submodule_data->defines[dnx_data_field_exem_learn_flush_machine_define_command_bit_delete].doc = "The bit on the command field of the flush entry paylaod to set to delete the EXEM entry.";
    
    submodule_data->defines[dnx_data_field_exem_learn_flush_machine_define_command_bit_delete].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_exem_learn_flush_machine_define_command_bit_clear_hit_bit].name = "command_bit_clear_hit_bit";
    submodule_data->defines[dnx_data_field_exem_learn_flush_machine_define_command_bit_clear_hit_bit].doc = "The bit on the command field of the flush entry paylaod to set to clear the hit bit of the EXEM entry.";
    
    submodule_data->defines[dnx_data_field_exem_learn_flush_machine_define_command_bit_clear_hit_bit].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_exem_learn_flush_machine_define_nof_bits_source].name = "nof_bits_source";
    submodule_data->defines[dnx_data_field_exem_learn_flush_machine_define_nof_bits_source].doc = "Number of bits in HW that represent the source field in the flush machine key.";
    
    submodule_data->defines[dnx_data_field_exem_learn_flush_machine_define_nof_bits_source].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_exem_learn_flush_machine_define_source_bit_for_scan].name = "source_bit_for_scan";
    submodule_data->defines[dnx_data_field_exem_learn_flush_machine_define_source_bit_for_scan].doc = "The bit on source field to indicate that the flush was activated by scan.";
    
    submodule_data->defines[dnx_data_field_exem_learn_flush_machine_define_source_bit_for_scan].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_exem_learn_flush_machine_define_source_bit_for_pipe].name = "source_bit_for_pipe";
    submodule_data->defines[dnx_data_field_exem_learn_flush_machine_define_source_bit_for_pipe].doc = "The bit on source field to indicate that the flush was activated by pipe.";
    
    submodule_data->defines[dnx_data_field_exem_learn_flush_machine_define_source_bit_for_pipe].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_exem_learn_flush_machine_define_source_bit_for_mrq].name = "source_bit_for_mrq";
    submodule_data->defines[dnx_data_field_exem_learn_flush_machine_define_source_bit_for_mrq].doc = "The bit on source field to indicate that the flush was activated by MRQ.";
    
    submodule_data->defines[dnx_data_field_exem_learn_flush_machine_define_source_bit_for_mrq].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_exem_learn_flush_machine_define_nof_bits_accessed].name = "nof_bits_accessed";
    submodule_data->defines[dnx_data_field_exem_learn_flush_machine_define_nof_bits_accessed].doc = "Number of bits in HW that represent the accessed field in the flush machine key (hit bit).";
    
    submodule_data->defines[dnx_data_field_exem_learn_flush_machine_define_nof_bits_accessed].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_exem_learn_flush_machine_define_nof_flush_profiles].name = "nof_flush_profiles";
    submodule_data->defines[dnx_data_field_exem_learn_flush_machine_define_nof_flush_profiles].doc = "Number of flush profiles";
    
    submodule_data->defines[dnx_data_field_exem_learn_flush_machine_define_nof_flush_profiles].flags |= DNXC_DATA_F_DEFINE;

    
    submodule_data->nof_tables = _dnx_data_field_exem_learn_flush_machine_table_nof;
    DNXC_DATA_ALLOC(submodule_data->tables, dnxc_data_table_t, submodule_data->nof_tables, "_dnxc_data field exem_learn_flush_machine tables");

    
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_sexem_flush_tcam_tcam_memories].name = "sexem_flush_tcam_tcam_memories";
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_sexem_flush_tcam_tcam_memories].doc = "Holds the memories of the flush TCAM for SEXEM3";
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_sexem_flush_tcam_tcam_memories].flags |= DNXC_DATA_F_TABLE;
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_sexem_flush_tcam_tcam_memories].size_of_values = sizeof(dnx_data_field_exem_learn_flush_machine_sexem_flush_tcam_tcam_memories_t);
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_sexem_flush_tcam_tcam_memories].entry_get = dnx_data_field_exem_learn_flush_machine_sexem_flush_tcam_tcam_memories_entry_str_get;

    
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_sexem_flush_tcam_tcam_memories].nof_keys = 0;

    
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_sexem_flush_tcam_tcam_memories].nof_values = 10;
    DNXC_DATA_ALLOC(submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_sexem_flush_tcam_tcam_memories].values, dnxc_data_value_t, submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_sexem_flush_tcam_tcam_memories].nof_values, "_dnx_data_field_exem_learn_flush_machine_table_sexem_flush_tcam_tcam_memories table values");
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_sexem_flush_tcam_tcam_memories].values[0].name = "table_name";
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_sexem_flush_tcam_tcam_memories].values[0].type = "soc_mem_t";
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_sexem_flush_tcam_tcam_memories].values[0].doc = "memory name";
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_sexem_flush_tcam_tcam_memories].values[0].offset = UTILEX_OFFSETOF(dnx_data_field_exem_learn_flush_machine_sexem_flush_tcam_tcam_memories_t, table_name);
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_sexem_flush_tcam_tcam_memories].values[1].name = "valid";
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_sexem_flush_tcam_tcam_memories].values[1].type = "soc_field_t";
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_sexem_flush_tcam_tcam_memories].values[1].doc = "1 means rule is valid and should be used. 0 rule should not be checked.";
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_sexem_flush_tcam_tcam_memories].values[1].offset = UTILEX_OFFSETOF(dnx_data_field_exem_learn_flush_machine_sexem_flush_tcam_tcam_memories_t, valid);
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_sexem_flush_tcam_tcam_memories].values[2].name = "entry_data";
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_sexem_flush_tcam_tcam_memories].values[2].type = "soc_field_t";
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_sexem_flush_tcam_tcam_memories].values[2].doc = "The key value for entry to be compared.";
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_sexem_flush_tcam_tcam_memories].values[2].offset = UTILEX_OFFSETOF(dnx_data_field_exem_learn_flush_machine_sexem_flush_tcam_tcam_memories_t, entry_data);
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_sexem_flush_tcam_tcam_memories].values[3].name = "entry_mask";
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_sexem_flush_tcam_tcam_memories].values[3].type = "soc_field_t";
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_sexem_flush_tcam_tcam_memories].values[3].doc = "The mask value for entry to be compared.";
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_sexem_flush_tcam_tcam_memories].values[3].offset = UTILEX_OFFSETOF(dnx_data_field_exem_learn_flush_machine_sexem_flush_tcam_tcam_memories_t, entry_mask);
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_sexem_flush_tcam_tcam_memories].values[4].name = "src_data";
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_sexem_flush_tcam_tcam_memories].values[4].type = "soc_field_t";
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_sexem_flush_tcam_tcam_memories].values[4].doc = "The key value for SRC bits {MRQ,PIPE,SCAN}.";
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_sexem_flush_tcam_tcam_memories].values[4].offset = UTILEX_OFFSETOF(dnx_data_field_exem_learn_flush_machine_sexem_flush_tcam_tcam_memories_t, src_data);
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_sexem_flush_tcam_tcam_memories].values[5].name = "src_mask";
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_sexem_flush_tcam_tcam_memories].values[5].type = "soc_field_t";
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_sexem_flush_tcam_tcam_memories].values[5].doc = "The mask value for SRC bits {MRQ,PIPE,SCAN}.";
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_sexem_flush_tcam_tcam_memories].values[5].offset = UTILEX_OFFSETOF(dnx_data_field_exem_learn_flush_machine_sexem_flush_tcam_tcam_memories_t, src_mask);
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_sexem_flush_tcam_tcam_memories].values[6].name = "appdb_id_data";
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_sexem_flush_tcam_tcam_memories].values[6].type = "soc_field_t";
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_sexem_flush_tcam_tcam_memories].values[6].doc = "The key value for the app_db_id of the entry.";
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_sexem_flush_tcam_tcam_memories].values[6].offset = UTILEX_OFFSETOF(dnx_data_field_exem_learn_flush_machine_sexem_flush_tcam_tcam_memories_t, appdb_id_data);
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_sexem_flush_tcam_tcam_memories].values[7].name = "appdb_id_mask";
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_sexem_flush_tcam_tcam_memories].values[7].type = "soc_field_t";
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_sexem_flush_tcam_tcam_memories].values[7].doc = "The mask value for the app_db_id of the entry.";
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_sexem_flush_tcam_tcam_memories].values[7].offset = UTILEX_OFFSETOF(dnx_data_field_exem_learn_flush_machine_sexem_flush_tcam_tcam_memories_t, appdb_id_mask);
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_sexem_flush_tcam_tcam_memories].values[8].name = "accessed_data";
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_sexem_flush_tcam_tcam_memories].values[8].type = "soc_field_t";
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_sexem_flush_tcam_tcam_memories].values[8].doc = "The key value for accessed.";
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_sexem_flush_tcam_tcam_memories].values[8].offset = UTILEX_OFFSETOF(dnx_data_field_exem_learn_flush_machine_sexem_flush_tcam_tcam_memories_t, accessed_data);
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_sexem_flush_tcam_tcam_memories].values[9].name = "accessed_mask";
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_sexem_flush_tcam_tcam_memories].values[9].type = "soc_field_t";
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_sexem_flush_tcam_tcam_memories].values[9].doc = "The mask value for accessed.";
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_sexem_flush_tcam_tcam_memories].values[9].offset = UTILEX_OFFSETOF(dnx_data_field_exem_learn_flush_machine_sexem_flush_tcam_tcam_memories_t, accessed_mask);

    
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_lexem_flush_tcam_tcam_memories].name = "lexem_flush_tcam_tcam_memories";
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_lexem_flush_tcam_tcam_memories].doc = "Holds the memories of the flush TCAM for LEXEM";
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_lexem_flush_tcam_tcam_memories].flags |= DNXC_DATA_F_TABLE;
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_lexem_flush_tcam_tcam_memories].size_of_values = sizeof(dnx_data_field_exem_learn_flush_machine_lexem_flush_tcam_tcam_memories_t);
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_lexem_flush_tcam_tcam_memories].entry_get = dnx_data_field_exem_learn_flush_machine_lexem_flush_tcam_tcam_memories_entry_str_get;

    
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_lexem_flush_tcam_tcam_memories].nof_keys = 0;

    
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_lexem_flush_tcam_tcam_memories].nof_values = 10;
    DNXC_DATA_ALLOC(submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_lexem_flush_tcam_tcam_memories].values, dnxc_data_value_t, submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_lexem_flush_tcam_tcam_memories].nof_values, "_dnx_data_field_exem_learn_flush_machine_table_lexem_flush_tcam_tcam_memories table values");
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_lexem_flush_tcam_tcam_memories].values[0].name = "table_name";
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_lexem_flush_tcam_tcam_memories].values[0].type = "soc_mem_t";
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_lexem_flush_tcam_tcam_memories].values[0].doc = "memory name";
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_lexem_flush_tcam_tcam_memories].values[0].offset = UTILEX_OFFSETOF(dnx_data_field_exem_learn_flush_machine_lexem_flush_tcam_tcam_memories_t, table_name);
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_lexem_flush_tcam_tcam_memories].values[1].name = "valid";
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_lexem_flush_tcam_tcam_memories].values[1].type = "soc_field_t";
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_lexem_flush_tcam_tcam_memories].values[1].doc = "1 means rule is valid and should be used. 0 rule should not be checked.";
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_lexem_flush_tcam_tcam_memories].values[1].offset = UTILEX_OFFSETOF(dnx_data_field_exem_learn_flush_machine_lexem_flush_tcam_tcam_memories_t, valid);
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_lexem_flush_tcam_tcam_memories].values[2].name = "entry_data";
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_lexem_flush_tcam_tcam_memories].values[2].type = "soc_field_t";
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_lexem_flush_tcam_tcam_memories].values[2].doc = "The key value for entry to be compared.";
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_lexem_flush_tcam_tcam_memories].values[2].offset = UTILEX_OFFSETOF(dnx_data_field_exem_learn_flush_machine_lexem_flush_tcam_tcam_memories_t, entry_data);
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_lexem_flush_tcam_tcam_memories].values[3].name = "entry_mask";
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_lexem_flush_tcam_tcam_memories].values[3].type = "soc_field_t";
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_lexem_flush_tcam_tcam_memories].values[3].doc = "The mask value for entry to be compared.";
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_lexem_flush_tcam_tcam_memories].values[3].offset = UTILEX_OFFSETOF(dnx_data_field_exem_learn_flush_machine_lexem_flush_tcam_tcam_memories_t, entry_mask);
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_lexem_flush_tcam_tcam_memories].values[4].name = "src_data";
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_lexem_flush_tcam_tcam_memories].values[4].type = "soc_field_t";
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_lexem_flush_tcam_tcam_memories].values[4].doc = "The key value for SRC bits {MRQ,PIPE,SCAN}.";
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_lexem_flush_tcam_tcam_memories].values[4].offset = UTILEX_OFFSETOF(dnx_data_field_exem_learn_flush_machine_lexem_flush_tcam_tcam_memories_t, src_data);
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_lexem_flush_tcam_tcam_memories].values[5].name = "src_mask";
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_lexem_flush_tcam_tcam_memories].values[5].type = "soc_field_t";
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_lexem_flush_tcam_tcam_memories].values[5].doc = "The mask value for SRC bits {MRQ,PIPE,SCAN}.";
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_lexem_flush_tcam_tcam_memories].values[5].offset = UTILEX_OFFSETOF(dnx_data_field_exem_learn_flush_machine_lexem_flush_tcam_tcam_memories_t, src_mask);
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_lexem_flush_tcam_tcam_memories].values[6].name = "appdb_id_data";
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_lexem_flush_tcam_tcam_memories].values[6].type = "soc_field_t";
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_lexem_flush_tcam_tcam_memories].values[6].doc = "The key value for the app_db_id of the entry.";
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_lexem_flush_tcam_tcam_memories].values[6].offset = UTILEX_OFFSETOF(dnx_data_field_exem_learn_flush_machine_lexem_flush_tcam_tcam_memories_t, appdb_id_data);
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_lexem_flush_tcam_tcam_memories].values[7].name = "appdb_id_mask";
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_lexem_flush_tcam_tcam_memories].values[7].type = "soc_field_t";
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_lexem_flush_tcam_tcam_memories].values[7].doc = "The mask value for the app_db_id of the entry.";
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_lexem_flush_tcam_tcam_memories].values[7].offset = UTILEX_OFFSETOF(dnx_data_field_exem_learn_flush_machine_lexem_flush_tcam_tcam_memories_t, appdb_id_mask);
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_lexem_flush_tcam_tcam_memories].values[8].name = "accessed_data";
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_lexem_flush_tcam_tcam_memories].values[8].type = "soc_field_t";
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_lexem_flush_tcam_tcam_memories].values[8].doc = "The key value for accessed.";
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_lexem_flush_tcam_tcam_memories].values[8].offset = UTILEX_OFFSETOF(dnx_data_field_exem_learn_flush_machine_lexem_flush_tcam_tcam_memories_t, accessed_data);
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_lexem_flush_tcam_tcam_memories].values[9].name = "accessed_mask";
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_lexem_flush_tcam_tcam_memories].values[9].type = "soc_field_t";
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_lexem_flush_tcam_tcam_memories].values[9].doc = "The mask value for accessed.";
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_lexem_flush_tcam_tcam_memories].values[9].offset = UTILEX_OFFSETOF(dnx_data_field_exem_learn_flush_machine_lexem_flush_tcam_tcam_memories_t, accessed_mask);

    
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_sexem_flush_tcam_data_rules].name = "sexem_flush_tcam_data_rules";
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_sexem_flush_tcam_data_rules].doc = "Holds the memories of the flush DATA for SEXEM3";
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_sexem_flush_tcam_data_rules].flags |= DNXC_DATA_F_TABLE;
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_sexem_flush_tcam_data_rules].size_of_values = sizeof(dnx_data_field_exem_learn_flush_machine_sexem_flush_tcam_data_rules_t);
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_sexem_flush_tcam_data_rules].entry_get = dnx_data_field_exem_learn_flush_machine_sexem_flush_tcam_data_rules_entry_str_get;

    
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_sexem_flush_tcam_data_rules].nof_keys = 0;

    
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_sexem_flush_tcam_data_rules].nof_values = 4;
    DNXC_DATA_ALLOC(submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_sexem_flush_tcam_data_rules].values, dnxc_data_value_t, submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_sexem_flush_tcam_data_rules].nof_values, "_dnx_data_field_exem_learn_flush_machine_table_sexem_flush_tcam_data_rules table values");
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_sexem_flush_tcam_data_rules].values[0].name = "table_name";
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_sexem_flush_tcam_data_rules].values[0].type = "soc_mem_t";
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_sexem_flush_tcam_data_rules].values[0].doc = "memory name";
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_sexem_flush_tcam_data_rules].values[0].offset = UTILEX_OFFSETOF(dnx_data_field_exem_learn_flush_machine_sexem_flush_tcam_data_rules_t, table_name);
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_sexem_flush_tcam_data_rules].values[1].name = "command";
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_sexem_flush_tcam_data_rules].values[1].type = "soc_field_t";
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_sexem_flush_tcam_data_rules].values[1].doc = "command type.";
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_sexem_flush_tcam_data_rules].values[1].offset = UTILEX_OFFSETOF(dnx_data_field_exem_learn_flush_machine_sexem_flush_tcam_data_rules_t, command);
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_sexem_flush_tcam_data_rules].values[2].name = "payload";
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_sexem_flush_tcam_data_rules].values[2].type = "soc_field_t";
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_sexem_flush_tcam_data_rules].values[2].doc = "Payload for transplant action.";
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_sexem_flush_tcam_data_rules].values[2].offset = UTILEX_OFFSETOF(dnx_data_field_exem_learn_flush_machine_sexem_flush_tcam_data_rules_t, payload);
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_sexem_flush_tcam_data_rules].values[3].name = "payload_mask";
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_sexem_flush_tcam_data_rules].values[3].type = "soc_field_t";
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_sexem_flush_tcam_data_rules].values[3].doc = "Mask for the payload in transplant action.";
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_sexem_flush_tcam_data_rules].values[3].offset = UTILEX_OFFSETOF(dnx_data_field_exem_learn_flush_machine_sexem_flush_tcam_data_rules_t, payload_mask);

    
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_lexem_flush_tcam_data_rules].name = "lexem_flush_tcam_data_rules";
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_lexem_flush_tcam_data_rules].doc = "Holds the memories of the flush DATA for LEXEM";
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_lexem_flush_tcam_data_rules].flags |= DNXC_DATA_F_TABLE;
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_lexem_flush_tcam_data_rules].size_of_values = sizeof(dnx_data_field_exem_learn_flush_machine_lexem_flush_tcam_data_rules_t);
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_lexem_flush_tcam_data_rules].entry_get = dnx_data_field_exem_learn_flush_machine_lexem_flush_tcam_data_rules_entry_str_get;

    
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_lexem_flush_tcam_data_rules].nof_keys = 0;

    
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_lexem_flush_tcam_data_rules].nof_values = 4;
    DNXC_DATA_ALLOC(submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_lexem_flush_tcam_data_rules].values, dnxc_data_value_t, submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_lexem_flush_tcam_data_rules].nof_values, "_dnx_data_field_exem_learn_flush_machine_table_lexem_flush_tcam_data_rules table values");
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_lexem_flush_tcam_data_rules].values[0].name = "table_name";
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_lexem_flush_tcam_data_rules].values[0].type = "soc_mem_t";
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_lexem_flush_tcam_data_rules].values[0].doc = "memory name";
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_lexem_flush_tcam_data_rules].values[0].offset = UTILEX_OFFSETOF(dnx_data_field_exem_learn_flush_machine_lexem_flush_tcam_data_rules_t, table_name);
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_lexem_flush_tcam_data_rules].values[1].name = "command";
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_lexem_flush_tcam_data_rules].values[1].type = "soc_field_t";
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_lexem_flush_tcam_data_rules].values[1].doc = "command type.";
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_lexem_flush_tcam_data_rules].values[1].offset = UTILEX_OFFSETOF(dnx_data_field_exem_learn_flush_machine_lexem_flush_tcam_data_rules_t, command);
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_lexem_flush_tcam_data_rules].values[2].name = "payload";
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_lexem_flush_tcam_data_rules].values[2].type = "soc_field_t";
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_lexem_flush_tcam_data_rules].values[2].doc = "Payload for transplant action.";
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_lexem_flush_tcam_data_rules].values[2].offset = UTILEX_OFFSETOF(dnx_data_field_exem_learn_flush_machine_lexem_flush_tcam_data_rules_t, payload);
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_lexem_flush_tcam_data_rules].values[3].name = "payload_mask";
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_lexem_flush_tcam_data_rules].values[3].type = "soc_field_t";
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_lexem_flush_tcam_data_rules].values[3].doc = "Mask for the payload in transplant action.";
    submodule_data->tables[dnx_data_field_exem_learn_flush_machine_table_lexem_flush_tcam_data_rules].values[3].offset = UTILEX_OFFSETOF(dnx_data_field_exem_learn_flush_machine_lexem_flush_tcam_data_rules_t, payload_mask);


exit:
    SHR_FUNC_EXIT;
}


int
dnx_data_field_exem_learn_flush_machine_feature_get(
    int unit,
    dnx_data_field_exem_learn_flush_machine_feature_e feature)
{
    return dnxc_data_mgmt_feature_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_exem_learn_flush_machine, feature);
}


uint32
dnx_data_field_exem_learn_flush_machine_flush_machine_nof_entries_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_exem_learn_flush_machine, dnx_data_field_exem_learn_flush_machine_define_flush_machine_nof_entries);
}

uint32
dnx_data_field_exem_learn_flush_machine_entry_extra_bits_for_hash_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_exem_learn_flush_machine, dnx_data_field_exem_learn_flush_machine_define_entry_extra_bits_for_hash);
}

uint32
dnx_data_field_exem_learn_flush_machine_sexem_entry_max_size_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_exem_learn_flush_machine, dnx_data_field_exem_learn_flush_machine_define_sexem_entry_max_size);
}

uint32
dnx_data_field_exem_learn_flush_machine_lexem_entry_max_size_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_exem_learn_flush_machine, dnx_data_field_exem_learn_flush_machine_define_lexem_entry_max_size);
}

uint32
dnx_data_field_exem_learn_flush_machine_command_bit_transplant_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_exem_learn_flush_machine, dnx_data_field_exem_learn_flush_machine_define_command_bit_transplant);
}

uint32
dnx_data_field_exem_learn_flush_machine_command_bit_delete_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_exem_learn_flush_machine, dnx_data_field_exem_learn_flush_machine_define_command_bit_delete);
}

uint32
dnx_data_field_exem_learn_flush_machine_command_bit_clear_hit_bit_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_exem_learn_flush_machine, dnx_data_field_exem_learn_flush_machine_define_command_bit_clear_hit_bit);
}

uint32
dnx_data_field_exem_learn_flush_machine_nof_bits_source_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_exem_learn_flush_machine, dnx_data_field_exem_learn_flush_machine_define_nof_bits_source);
}

uint32
dnx_data_field_exem_learn_flush_machine_source_bit_for_scan_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_exem_learn_flush_machine, dnx_data_field_exem_learn_flush_machine_define_source_bit_for_scan);
}

uint32
dnx_data_field_exem_learn_flush_machine_source_bit_for_pipe_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_exem_learn_flush_machine, dnx_data_field_exem_learn_flush_machine_define_source_bit_for_pipe);
}

uint32
dnx_data_field_exem_learn_flush_machine_source_bit_for_mrq_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_exem_learn_flush_machine, dnx_data_field_exem_learn_flush_machine_define_source_bit_for_mrq);
}

uint32
dnx_data_field_exem_learn_flush_machine_nof_bits_accessed_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_exem_learn_flush_machine, dnx_data_field_exem_learn_flush_machine_define_nof_bits_accessed);
}

uint32
dnx_data_field_exem_learn_flush_machine_nof_flush_profiles_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_exem_learn_flush_machine, dnx_data_field_exem_learn_flush_machine_define_nof_flush_profiles);
}



const dnx_data_field_exem_learn_flush_machine_sexem_flush_tcam_tcam_memories_t *
dnx_data_field_exem_learn_flush_machine_sexem_flush_tcam_tcam_memories_get(
    int unit)
{
    char *data;
    dnxc_data_table_t *table;

    
    table = dnxc_data_mgmt_table_get(unit, dnx_data_module_field, dnx_data_field_submodule_exem_learn_flush_machine, dnx_data_field_exem_learn_flush_machine_table_sexem_flush_tcam_tcam_memories);
    
    data = dnxc_data_mgmt_table_data_get(unit, table, 0, 0);
    return (const dnx_data_field_exem_learn_flush_machine_sexem_flush_tcam_tcam_memories_t *) data;

}

const dnx_data_field_exem_learn_flush_machine_lexem_flush_tcam_tcam_memories_t *
dnx_data_field_exem_learn_flush_machine_lexem_flush_tcam_tcam_memories_get(
    int unit)
{
    char *data;
    dnxc_data_table_t *table;

    
    table = dnxc_data_mgmt_table_get(unit, dnx_data_module_field, dnx_data_field_submodule_exem_learn_flush_machine, dnx_data_field_exem_learn_flush_machine_table_lexem_flush_tcam_tcam_memories);
    
    data = dnxc_data_mgmt_table_data_get(unit, table, 0, 0);
    return (const dnx_data_field_exem_learn_flush_machine_lexem_flush_tcam_tcam_memories_t *) data;

}

const dnx_data_field_exem_learn_flush_machine_sexem_flush_tcam_data_rules_t *
dnx_data_field_exem_learn_flush_machine_sexem_flush_tcam_data_rules_get(
    int unit)
{
    char *data;
    dnxc_data_table_t *table;

    
    table = dnxc_data_mgmt_table_get(unit, dnx_data_module_field, dnx_data_field_submodule_exem_learn_flush_machine, dnx_data_field_exem_learn_flush_machine_table_sexem_flush_tcam_data_rules);
    
    data = dnxc_data_mgmt_table_data_get(unit, table, 0, 0);
    return (const dnx_data_field_exem_learn_flush_machine_sexem_flush_tcam_data_rules_t *) data;

}

const dnx_data_field_exem_learn_flush_machine_lexem_flush_tcam_data_rules_t *
dnx_data_field_exem_learn_flush_machine_lexem_flush_tcam_data_rules_get(
    int unit)
{
    char *data;
    dnxc_data_table_t *table;

    
    table = dnxc_data_mgmt_table_get(unit, dnx_data_module_field, dnx_data_field_submodule_exem_learn_flush_machine, dnx_data_field_exem_learn_flush_machine_table_lexem_flush_tcam_data_rules);
    
    data = dnxc_data_mgmt_table_data_get(unit, table, 0, 0);
    return (const dnx_data_field_exem_learn_flush_machine_lexem_flush_tcam_data_rules_t *) data;

}


shr_error_e
dnx_data_field_exem_learn_flush_machine_sexem_flush_tcam_tcam_memories_entry_str_get(
    int unit,
    char *buffer,
    int key0,
    int key1,
    int value_index)
{
    dnxc_data_table_t *table;
    const dnx_data_field_exem_learn_flush_machine_sexem_flush_tcam_tcam_memories_t *data;
    SHR_FUNC_INIT_VARS(unit);

    
    table = dnxc_data_mgmt_table_get(unit, dnx_data_module_field, dnx_data_field_submodule_exem_learn_flush_machine, dnx_data_field_exem_learn_flush_machine_table_sexem_flush_tcam_tcam_memories);
    data = (const dnx_data_field_exem_learn_flush_machine_sexem_flush_tcam_tcam_memories_t *) dnxc_data_mgmt_table_data_diag_get(unit, table, 0, 0);
    switch (value_index)
    {
        case 0:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->table_name);
            break;
        case 1:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->valid);
            break;
        case 2:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->entry_data);
            break;
        case 3:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->entry_mask);
            break;
        case 4:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->src_data);
            break;
        case 5:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->src_mask);
            break;
        case 6:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->appdb_id_data);
            break;
        case 7:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->appdb_id_mask);
            break;
        case 8:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->accessed_data);
            break;
        case 9:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->accessed_mask);
            break;
    }

    SHR_FUNC_EXIT;
}

shr_error_e
dnx_data_field_exem_learn_flush_machine_lexem_flush_tcam_tcam_memories_entry_str_get(
    int unit,
    char *buffer,
    int key0,
    int key1,
    int value_index)
{
    dnxc_data_table_t *table;
    const dnx_data_field_exem_learn_flush_machine_lexem_flush_tcam_tcam_memories_t *data;
    SHR_FUNC_INIT_VARS(unit);

    
    table = dnxc_data_mgmt_table_get(unit, dnx_data_module_field, dnx_data_field_submodule_exem_learn_flush_machine, dnx_data_field_exem_learn_flush_machine_table_lexem_flush_tcam_tcam_memories);
    data = (const dnx_data_field_exem_learn_flush_machine_lexem_flush_tcam_tcam_memories_t *) dnxc_data_mgmt_table_data_diag_get(unit, table, 0, 0);
    switch (value_index)
    {
        case 0:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->table_name);
            break;
        case 1:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->valid);
            break;
        case 2:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->entry_data);
            break;
        case 3:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->entry_mask);
            break;
        case 4:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->src_data);
            break;
        case 5:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->src_mask);
            break;
        case 6:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->appdb_id_data);
            break;
        case 7:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->appdb_id_mask);
            break;
        case 8:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->accessed_data);
            break;
        case 9:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->accessed_mask);
            break;
    }

    SHR_FUNC_EXIT;
}

shr_error_e
dnx_data_field_exem_learn_flush_machine_sexem_flush_tcam_data_rules_entry_str_get(
    int unit,
    char *buffer,
    int key0,
    int key1,
    int value_index)
{
    dnxc_data_table_t *table;
    const dnx_data_field_exem_learn_flush_machine_sexem_flush_tcam_data_rules_t *data;
    SHR_FUNC_INIT_VARS(unit);

    
    table = dnxc_data_mgmt_table_get(unit, dnx_data_module_field, dnx_data_field_submodule_exem_learn_flush_machine, dnx_data_field_exem_learn_flush_machine_table_sexem_flush_tcam_data_rules);
    data = (const dnx_data_field_exem_learn_flush_machine_sexem_flush_tcam_data_rules_t *) dnxc_data_mgmt_table_data_diag_get(unit, table, 0, 0);
    switch (value_index)
    {
        case 0:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->table_name);
            break;
        case 1:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->command);
            break;
        case 2:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->payload);
            break;
        case 3:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->payload_mask);
            break;
    }

    SHR_FUNC_EXIT;
}

shr_error_e
dnx_data_field_exem_learn_flush_machine_lexem_flush_tcam_data_rules_entry_str_get(
    int unit,
    char *buffer,
    int key0,
    int key1,
    int value_index)
{
    dnxc_data_table_t *table;
    const dnx_data_field_exem_learn_flush_machine_lexem_flush_tcam_data_rules_t *data;
    SHR_FUNC_INIT_VARS(unit);

    
    table = dnxc_data_mgmt_table_get(unit, dnx_data_module_field, dnx_data_field_submodule_exem_learn_flush_machine, dnx_data_field_exem_learn_flush_machine_table_lexem_flush_tcam_data_rules);
    data = (const dnx_data_field_exem_learn_flush_machine_lexem_flush_tcam_data_rules_t *) dnxc_data_mgmt_table_data_diag_get(unit, table, 0, 0);
    switch (value_index)
    {
        case 0:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->table_name);
            break;
        case 1:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->command);
            break;
        case 2:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->payload);
            break;
        case 3:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->payload_mask);
            break;
    }

    SHR_FUNC_EXIT;
}


const dnxc_data_table_info_t *
dnx_data_field_exem_learn_flush_machine_sexem_flush_tcam_tcam_memories_info_get(
    int unit)
{

    
    return dnxc_data_mgmt_table_info_get(unit, dnx_data_module_field, dnx_data_field_submodule_exem_learn_flush_machine, dnx_data_field_exem_learn_flush_machine_table_sexem_flush_tcam_tcam_memories);

}

const dnxc_data_table_info_t *
dnx_data_field_exem_learn_flush_machine_lexem_flush_tcam_tcam_memories_info_get(
    int unit)
{

    
    return dnxc_data_mgmt_table_info_get(unit, dnx_data_module_field, dnx_data_field_submodule_exem_learn_flush_machine, dnx_data_field_exem_learn_flush_machine_table_lexem_flush_tcam_tcam_memories);

}

const dnxc_data_table_info_t *
dnx_data_field_exem_learn_flush_machine_sexem_flush_tcam_data_rules_info_get(
    int unit)
{

    
    return dnxc_data_mgmt_table_info_get(unit, dnx_data_module_field, dnx_data_field_submodule_exem_learn_flush_machine, dnx_data_field_exem_learn_flush_machine_table_sexem_flush_tcam_data_rules);

}

const dnxc_data_table_info_t *
dnx_data_field_exem_learn_flush_machine_lexem_flush_tcam_data_rules_info_get(
    int unit)
{

    
    return dnxc_data_mgmt_table_info_get(unit, dnx_data_module_field, dnx_data_field_submodule_exem_learn_flush_machine, dnx_data_field_exem_learn_flush_machine_table_lexem_flush_tcam_data_rules);

}






static shr_error_e
dnx_data_field_ace_init(
    int unit,
    dnxc_data_submodule_t *submodule_data)
{
    SHR_FUNC_INIT_VARS(unit);

    submodule_data->name = "ace";
    submodule_data->doc = "ACE values, for ACE expansion done by the PPMC DB and ACE ACR, for both MC replication ID pointers and ACE pointers";
    
    submodule_data->nof_features = _dnx_data_field_ace_feature_nof;
    DNXC_DATA_ALLOC(submodule_data->features, dnxc_data_feature_t,  submodule_data->nof_features, "_dnxc_data field ace features");

    
    submodule_data->nof_defines = _dnx_data_field_ace_define_nof;
    DNXC_DATA_ALLOC(submodule_data->defines, dnxc_data_define_t, submodule_data->nof_defines, "_dnxc_data field ace defines");

    submodule_data->defines[dnx_data_field_ace_define_supported].name = "supported";
    submodule_data->defines[dnx_data_field_ace_define_supported].doc = "Specify if ace exist on a device";
    
    submodule_data->defines[dnx_data_field_ace_define_supported].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_ace_define_ace_id_size].name = "ace_id_size";
    submodule_data->defines[dnx_data_field_ace_define_ace_id_size].doc = "Number of bits used for the ACE ID (result type), which serves as an ID for the ACE format and context ID for the ACE EFES.";
    
    submodule_data->defines[dnx_data_field_ace_define_ace_id_size].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_ace_define_key_size].name = "key_size";
    submodule_data->defines[dnx_data_field_ace_define_key_size].doc = "Number of bits in the key of the PPMC table, including the prefix that indicates the type to the entry";
    
    submodule_data->defines[dnx_data_field_ace_define_key_size].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_ace_define_app_db_id_size].name = "app_db_id_size";
    submodule_data->defines[dnx_data_field_ace_define_app_db_id_size].doc = "Number of bits Used for the APP DB ID.";
    
    submodule_data->defines[dnx_data_field_ace_define_app_db_id_size].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_ace_define_payload_size].name = "payload_size";
    submodule_data->defines[dnx_data_field_ace_define_payload_size].doc = "Number of bits used to encode the container size, including the result type";
    
    submodule_data->defines[dnx_data_field_ace_define_payload_size].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_ace_define_min_key_range_pmf].name = "min_key_range_pmf";
    submodule_data->defines[dnx_data_field_ace_define_min_key_range_pmf].doc = "The first entry in the range of ACE keys allocated to ACE pointers (but not to MC replication ID).";
    
    submodule_data->defines[dnx_data_field_ace_define_min_key_range_pmf].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_ace_define_max_key_range_pmf].name = "max_key_range_pmf";
    submodule_data->defines[dnx_data_field_ace_define_max_key_range_pmf].doc = "The last entry in the range of ACE keys allocated to ACE pointers (but not to MC replication ID).";
    
    submodule_data->defines[dnx_data_field_ace_define_max_key_range_pmf].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_ace_define_min_ace_id_dynamic_range].name = "min_ace_id_dynamic_range";
    submodule_data->defines[dnx_data_field_ace_define_min_ace_id_dynamic_range].doc = "Minimal number of ACE ID that can be allocated dynamically.";
    
    submodule_data->defines[dnx_data_field_ace_define_min_ace_id_dynamic_range].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_ace_define_nof_ace_id].name = "nof_ace_id";
    submodule_data->defines[dnx_data_field_ace_define_nof_ace_id].doc = "Number of ACE IDs.";
    
    submodule_data->defines[dnx_data_field_ace_define_nof_ace_id].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_ace_define_nof_action_per_ace_format].name = "nof_action_per_ace_format";
    submodule_data->defines[dnx_data_field_ace_define_nof_action_per_ace_format].doc = "Number of action per ACE Format";
    
    submodule_data->defines[dnx_data_field_ace_define_nof_action_per_ace_format].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_ace_define_row_size].name = "row_size";
    submodule_data->defines[dnx_data_field_ace_define_row_size].doc = "Number of bits per raw, entry size is number row size times VMV encoding meaning, e.g. half row encoding VMV would mean 60 bits entry size.";
    
    submodule_data->defines[dnx_data_field_ace_define_row_size].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_ace_define_min_entry_size].name = "min_entry_size";
    submodule_data->defines[dnx_data_field_ace_define_min_entry_size].doc = "Minimum number of bits in entry.";
    
    submodule_data->defines[dnx_data_field_ace_define_min_entry_size].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_ace_define_ace_id_pmf_alloc_first].name = "ace_id_pmf_alloc_first";
    submodule_data->defines[dnx_data_field_ace_define_ace_id_pmf_alloc_first].doc = "The first ACE ID allocated to ACE, that is to ePMF extension.";
    
    submodule_data->defines[dnx_data_field_ace_define_ace_id_pmf_alloc_first].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_ace_define_ace_id_pmf_alloc_last].name = "ace_id_pmf_alloc_last";
    submodule_data->defines[dnx_data_field_ace_define_ace_id_pmf_alloc_last].doc = "The last ACE ID allocated to ACE, that is to ePMF extension.";
    
    submodule_data->defines[dnx_data_field_ace_define_ace_id_pmf_alloc_last].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_ace_define_nof_masks_per_fes].name = "nof_masks_per_fes";
    submodule_data->defines[dnx_data_field_ace_define_nof_masks_per_fes].doc = "Number of masks per FES";
    
    submodule_data->defines[dnx_data_field_ace_define_nof_masks_per_fes].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_ace_define_nof_fes_id_per_array].name = "nof_fes_id_per_array";
    submodule_data->defines[dnx_data_field_ace_define_nof_fes_id_per_array].doc = "Number FESes in each FES array";
    
    submodule_data->defines[dnx_data_field_ace_define_nof_fes_id_per_array].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_ace_define_nof_fes_array].name = "nof_fes_array";
    submodule_data->defines[dnx_data_field_ace_define_nof_fes_array].doc = "Number FES arrays";
    
    submodule_data->defines[dnx_data_field_ace_define_nof_fes_array].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_ace_define_nof_fes_instruction_per_context].name = "nof_fes_instruction_per_context";
    submodule_data->defines[dnx_data_field_ace_define_nof_fes_instruction_per_context].doc = "Number of FES INSTRUCTIONs per ACE ID, also the number of FESes.";
    
    submodule_data->defines[dnx_data_field_ace_define_nof_fes_instruction_per_context].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_ace_define_nof_fes_programs].name = "nof_fes_programs";
    submodule_data->defines[dnx_data_field_ace_define_nof_fes_programs].doc = "Number of FES programs. For ACE the FES program is the same as ACE ID. Used here for compatibility with PMF FESes.";
    
    submodule_data->defines[dnx_data_field_ace_define_nof_fes_programs].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_ace_define_nof_prog_per_fes].name = "nof_prog_per_fes";
    submodule_data->defines[dnx_data_field_ace_define_nof_prog_per_fes].doc = "Number of MS bits instruction programs per FES";
    
    submodule_data->defines[dnx_data_field_ace_define_nof_prog_per_fes].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_ace_define_nof_bits_in_fes_action].name = "nof_bits_in_fes_action";
    submodule_data->defines[dnx_data_field_ace_define_nof_bits_in_fes_action].doc = "Number of bits on the output of a FES.";
    
    submodule_data->defines[dnx_data_field_ace_define_nof_bits_in_fes_action].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_ace_define_fes_shift_for_zero_bit].name = "fes_shift_for_zero_bit";
    submodule_data->defines[dnx_data_field_ace_define_fes_shift_for_zero_bit].doc = "The shift used for obtaining an always zero bit for input to FES. Uses the zero padding at the end of the payload, expected to work only if EFES field type=1.";
    
    submodule_data->defines[dnx_data_field_ace_define_fes_shift_for_zero_bit].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_ace_define_fes_instruction_size].name = "fes_instruction_size";
    submodule_data->defines[dnx_data_field_ace_define_fes_instruction_size].doc = "Number of bits in one fes instruction.";
    
    submodule_data->defines[dnx_data_field_ace_define_fes_instruction_size].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_ace_define_fes_shift_offset].name = "fes_shift_offset";
    submodule_data->defines[dnx_data_field_ace_define_fes_shift_offset].doc = "FES shift offset in ETPPA_PRP_FES_PROGRAM_TABLEm->DATA_PER_FESf";
    
    submodule_data->defines[dnx_data_field_ace_define_fes_shift_offset].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_ace_define_fes_invalid_bits_offset].name = "fes_invalid_bits_offset";
    submodule_data->defines[dnx_data_field_ace_define_fes_invalid_bits_offset].doc = "FES invalid bits offset in ETPPA_PRP_FES_PROGRAM_TABLEm->DATA_PER_FESf";
    
    submodule_data->defines[dnx_data_field_ace_define_fes_invalid_bits_offset].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_ace_define_fes_type_offset].name = "fes_type_offset";
    submodule_data->defines[dnx_data_field_ace_define_fes_type_offset].doc = "FES type offset in ETPPA_PRP_FES_PROGRAM_TABLEm->DATA_PER_FESf";
    
    submodule_data->defines[dnx_data_field_ace_define_fes_type_offset].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_ace_define_fes_ace_action_offset].name = "fes_ace_action_offset";
    submodule_data->defines[dnx_data_field_ace_define_fes_ace_action_offset].doc = "FES ace action offset in ETPPA_PRP_FES_PROGRAM_TABLEm->DATA_PER_FESf";
    
    submodule_data->defines[dnx_data_field_ace_define_fes_ace_action_offset].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_ace_define_fes_chosen_mask_offset].name = "fes_chosen_mask_offset";
    submodule_data->defines[dnx_data_field_ace_define_fes_chosen_mask_offset].doc = "FES chosen mask offset in ETPPA_PRP_FES_PROGRAM_TABLEm->DATA_PER_FESf";
    
    submodule_data->defines[dnx_data_field_ace_define_fes_chosen_mask_offset].flags |= DNXC_DATA_F_DEFINE;

    
    submodule_data->nof_tables = _dnx_data_field_ace_table_nof;
    DNXC_DATA_ALLOC(submodule_data->tables, dnxc_data_table_t, submodule_data->nof_tables, "_dnxc_data field ace tables");


exit:
    SHR_FUNC_EXIT;
}


int
dnx_data_field_ace_feature_get(
    int unit,
    dnx_data_field_ace_feature_e feature)
{
    return dnxc_data_mgmt_feature_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_ace, feature);
}


uint32
dnx_data_field_ace_supported_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_ace, dnx_data_field_ace_define_supported);
}

uint32
dnx_data_field_ace_ace_id_size_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_ace, dnx_data_field_ace_define_ace_id_size);
}

uint32
dnx_data_field_ace_key_size_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_ace, dnx_data_field_ace_define_key_size);
}

uint32
dnx_data_field_ace_app_db_id_size_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_ace, dnx_data_field_ace_define_app_db_id_size);
}

uint32
dnx_data_field_ace_payload_size_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_ace, dnx_data_field_ace_define_payload_size);
}

uint32
dnx_data_field_ace_min_key_range_pmf_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_ace, dnx_data_field_ace_define_min_key_range_pmf);
}

uint32
dnx_data_field_ace_max_key_range_pmf_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_ace, dnx_data_field_ace_define_max_key_range_pmf);
}

uint32
dnx_data_field_ace_min_ace_id_dynamic_range_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_ace, dnx_data_field_ace_define_min_ace_id_dynamic_range);
}

uint32
dnx_data_field_ace_nof_ace_id_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_ace, dnx_data_field_ace_define_nof_ace_id);
}

uint32
dnx_data_field_ace_nof_action_per_ace_format_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_ace, dnx_data_field_ace_define_nof_action_per_ace_format);
}

uint32
dnx_data_field_ace_row_size_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_ace, dnx_data_field_ace_define_row_size);
}

uint32
dnx_data_field_ace_min_entry_size_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_ace, dnx_data_field_ace_define_min_entry_size);
}

uint32
dnx_data_field_ace_ace_id_pmf_alloc_first_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_ace, dnx_data_field_ace_define_ace_id_pmf_alloc_first);
}

uint32
dnx_data_field_ace_ace_id_pmf_alloc_last_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_ace, dnx_data_field_ace_define_ace_id_pmf_alloc_last);
}

uint32
dnx_data_field_ace_nof_masks_per_fes_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_ace, dnx_data_field_ace_define_nof_masks_per_fes);
}

uint32
dnx_data_field_ace_nof_fes_id_per_array_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_ace, dnx_data_field_ace_define_nof_fes_id_per_array);
}

uint32
dnx_data_field_ace_nof_fes_array_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_ace, dnx_data_field_ace_define_nof_fes_array);
}

uint32
dnx_data_field_ace_nof_fes_instruction_per_context_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_ace, dnx_data_field_ace_define_nof_fes_instruction_per_context);
}

uint32
dnx_data_field_ace_nof_fes_programs_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_ace, dnx_data_field_ace_define_nof_fes_programs);
}

uint32
dnx_data_field_ace_nof_prog_per_fes_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_ace, dnx_data_field_ace_define_nof_prog_per_fes);
}

uint32
dnx_data_field_ace_nof_bits_in_fes_action_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_ace, dnx_data_field_ace_define_nof_bits_in_fes_action);
}

uint32
dnx_data_field_ace_fes_shift_for_zero_bit_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_ace, dnx_data_field_ace_define_fes_shift_for_zero_bit);
}

uint32
dnx_data_field_ace_fes_instruction_size_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_ace, dnx_data_field_ace_define_fes_instruction_size);
}

uint32
dnx_data_field_ace_fes_shift_offset_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_ace, dnx_data_field_ace_define_fes_shift_offset);
}

uint32
dnx_data_field_ace_fes_invalid_bits_offset_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_ace, dnx_data_field_ace_define_fes_invalid_bits_offset);
}

uint32
dnx_data_field_ace_fes_type_offset_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_ace, dnx_data_field_ace_define_fes_type_offset);
}

uint32
dnx_data_field_ace_fes_ace_action_offset_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_ace, dnx_data_field_ace_define_fes_ace_action_offset);
}

uint32
dnx_data_field_ace_fes_chosen_mask_offset_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_ace, dnx_data_field_ace_define_fes_chosen_mask_offset);
}










static shr_error_e
dnx_data_field_entry_init(
    int unit,
    dnxc_data_submodule_t *submodule_data)
{
    SHR_FUNC_INIT_VARS(unit);

    submodule_data->name = "entry";
    submodule_data->doc = "Entry data";
    
    submodule_data->nof_features = _dnx_data_field_entry_feature_nof;
    DNXC_DATA_ALLOC(submodule_data->features, dnxc_data_feature_t,  submodule_data->nof_features, "_dnxc_data field entry features");

    
    submodule_data->nof_defines = _dnx_data_field_entry_define_nof;
    DNXC_DATA_ALLOC(submodule_data->defines, dnxc_data_define_t, submodule_data->nof_defines, "_dnxc_data field entry defines");

    submodule_data->defines[dnx_data_field_entry_define_dir_ext_nof_fields].name = "dir_ext_nof_fields";
    submodule_data->defines[dnx_data_field_entry_define_dir_ext_nof_fields].doc = "The maximum number of fields in a direct extraction request. \n                                                   (e.g. if we want the action to be composed of 3 bits of constant value, 5 bits from the key, \n                                                   5 bits of constant value and then 4 bits from the key we need at least 4 fields.)\n                                                   Used by dnx_field_dir_ext_action_t for the array size of the fields. \n                                                   Arbitrary value, can be increased.";
    
    submodule_data->defines[dnx_data_field_entry_define_dir_ext_nof_fields].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_entry_define_nof_action_params_per_entry].name = "nof_action_params_per_entry";
    submodule_data->defines[dnx_data_field_entry_define_nof_action_params_per_entry].doc = "Number of action parameters can be given for each action \n                                                             e.g. action values that are filled for TCAM action result";
    
    submodule_data->defines[dnx_data_field_entry_define_nof_action_params_per_entry].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_entry_define_nof_qual_params_per_entry].name = "nof_qual_params_per_entry";
    submodule_data->defines[dnx_data_field_entry_define_nof_qual_params_per_entry].doc = "Number of qualifiers parameters can be given for each qualifier type \n                                                             e.g. qualifier/key values that are filled for TCAM key";
    
    submodule_data->defines[dnx_data_field_entry_define_nof_qual_params_per_entry].flags |= DNXC_DATA_F_DEFINE;

    
    submodule_data->nof_tables = _dnx_data_field_entry_table_nof;
    DNXC_DATA_ALLOC(submodule_data->tables, dnxc_data_table_t, submodule_data->nof_tables, "_dnxc_data field entry tables");


exit:
    SHR_FUNC_EXIT;
}


int
dnx_data_field_entry_feature_get(
    int unit,
    dnx_data_field_entry_feature_e feature)
{
    return dnxc_data_mgmt_feature_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_entry, feature);
}


uint32
dnx_data_field_entry_dir_ext_nof_fields_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_entry, dnx_data_field_entry_define_dir_ext_nof_fields);
}

uint32
dnx_data_field_entry_nof_action_params_per_entry_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_entry, dnx_data_field_entry_define_nof_action_params_per_entry);
}

uint32
dnx_data_field_entry_nof_qual_params_per_entry_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_entry, dnx_data_field_entry_define_nof_qual_params_per_entry);
}










static shr_error_e
dnx_data_field_L4_Ops_init(
    int unit,
    dnxc_data_submodule_t *submodule_data)
{
    SHR_FUNC_INIT_VARS(unit);

    submodule_data->name = "L4_Ops";
    submodule_data->doc = "L4 Ops data";
    
    submodule_data->nof_features = _dnx_data_field_L4_Ops_feature_nof;
    DNXC_DATA_ALLOC(submodule_data->features, dnxc_data_feature_t,  submodule_data->nof_features, "_dnxc_data field L4_Ops features");

    
    submodule_data->nof_defines = _dnx_data_field_L4_Ops_define_nof;
    DNXC_DATA_ALLOC(submodule_data->defines, dnxc_data_define_t, submodule_data->nof_defines, "_dnxc_data field L4_Ops defines");

    submodule_data->defines[dnx_data_field_L4_Ops_define_udp_position].name = "udp_position";
    submodule_data->defines[dnx_data_field_L4_Ops_define_udp_position].doc = "The position of the UDP protocol in the register";
    
    submodule_data->defines[dnx_data_field_L4_Ops_define_udp_position].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_L4_Ops_define_tcp_position].name = "tcp_position";
    submodule_data->defines[dnx_data_field_L4_Ops_define_tcp_position].doc = "The position of the UDP protocol in the register";
    
    submodule_data->defines[dnx_data_field_L4_Ops_define_tcp_position].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_L4_Ops_define_nof_range_entries].name = "nof_range_entries";
    submodule_data->defines[dnx_data_field_L4_Ops_define_nof_range_entries].doc = "number of range entries in L4 Ops";
    
    submodule_data->defines[dnx_data_field_L4_Ops_define_nof_range_entries].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_L4_Ops_define_nof_ext_encoders].name = "nof_ext_encoders";
    submodule_data->defines[dnx_data_field_L4_Ops_define_nof_ext_encoders].doc = "Number of range result encoders in extended L4 OPs";
    
    submodule_data->defines[dnx_data_field_L4_Ops_define_nof_ext_encoders].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_L4_Ops_define_nof_ext_types].name = "nof_ext_types";
    submodule_data->defines[dnx_data_field_L4_Ops_define_nof_ext_types].doc = "Number of range types in extended L4 OPs";
    
    submodule_data->defines[dnx_data_field_L4_Ops_define_nof_ext_types].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_L4_Ops_define_nof_configurable_ranges].name = "nof_configurable_ranges";
    submodule_data->defines[dnx_data_field_L4_Ops_define_nof_configurable_ranges].doc = "Number of configurable ranges";
    
    submodule_data->defines[dnx_data_field_L4_Ops_define_nof_configurable_ranges].flags |= DNXC_DATA_F_DEFINE;

    
    submodule_data->nof_tables = _dnx_data_field_L4_Ops_table_nof;
    DNXC_DATA_ALLOC(submodule_data->tables, dnxc_data_table_t, submodule_data->nof_tables, "_dnxc_data field L4_Ops tables");


exit:
    SHR_FUNC_EXIT;
}


int
dnx_data_field_L4_Ops_feature_get(
    int unit,
    dnx_data_field_L4_Ops_feature_e feature)
{
    return dnxc_data_mgmt_feature_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_L4_Ops, feature);
}


uint32
dnx_data_field_L4_Ops_udp_position_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_L4_Ops, dnx_data_field_L4_Ops_define_udp_position);
}

uint32
dnx_data_field_L4_Ops_tcp_position_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_L4_Ops, dnx_data_field_L4_Ops_define_tcp_position);
}

uint32
dnx_data_field_L4_Ops_nof_range_entries_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_L4_Ops, dnx_data_field_L4_Ops_define_nof_range_entries);
}

uint32
dnx_data_field_L4_Ops_nof_ext_encoders_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_L4_Ops, dnx_data_field_L4_Ops_define_nof_ext_encoders);
}

uint32
dnx_data_field_L4_Ops_nof_ext_types_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_L4_Ops, dnx_data_field_L4_Ops_define_nof_ext_types);
}

uint32
dnx_data_field_L4_Ops_nof_configurable_ranges_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_L4_Ops, dnx_data_field_L4_Ops_define_nof_configurable_ranges);
}










static shr_error_e
dnx_data_field_encoded_qual_actions_offset_init(
    int unit,
    dnxc_data_submodule_t *submodule_data)
{
    SHR_FUNC_INIT_VARS(unit);

    submodule_data->name = "encoded_qual_actions_offset";
    submodule_data->doc = "Encoded qualfiers and actions offsets";
    
    submodule_data->nof_features = _dnx_data_field_encoded_qual_actions_offset_feature_nof;
    DNXC_DATA_ALLOC(submodule_data->features, dnxc_data_feature_t,  submodule_data->nof_features, "_dnxc_data field encoded_qual_actions_offset features");

    
    submodule_data->nof_defines = _dnx_data_field_encoded_qual_actions_offset_define_nof;
    DNXC_DATA_ALLOC(submodule_data->defines, dnxc_data_define_t, submodule_data->nof_defines, "_dnxc_data field encoded_qual_actions_offset defines");

    submodule_data->defines[dnx_data_field_encoded_qual_actions_offset_define_trap_strength_offset].name = "trap_strength_offset";
    submodule_data->defines[dnx_data_field_encoded_qual_actions_offset_define_trap_strength_offset].doc = "The offset of the Trap Strength in the action";
    
    submodule_data->defines[dnx_data_field_encoded_qual_actions_offset_define_trap_strength_offset].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_encoded_qual_actions_offset_define_trap_qualifier_offset].name = "trap_qualifier_offset";
    submodule_data->defines[dnx_data_field_encoded_qual_actions_offset_define_trap_qualifier_offset].doc = "The offset of the Trap Qualifier in the action";
    
    submodule_data->defines[dnx_data_field_encoded_qual_actions_offset_define_trap_qualifier_offset].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_encoded_qual_actions_offset_define_sniff_qualifier_offset].name = "sniff_qualifier_offset";
    submodule_data->defines[dnx_data_field_encoded_qual_actions_offset_define_sniff_qualifier_offset].doc = "The offset of the Snoop qualifier in the action";
    
    submodule_data->defines[dnx_data_field_encoded_qual_actions_offset_define_sniff_qualifier_offset].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_encoded_qual_actions_offset_define_mirror_qualifier_offset].name = "mirror_qualifier_offset";
    submodule_data->defines[dnx_data_field_encoded_qual_actions_offset_define_mirror_qualifier_offset].doc = "The offset of the Mirror Qualifier in the action";
    
    submodule_data->defines[dnx_data_field_encoded_qual_actions_offset_define_mirror_qualifier_offset].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_encoded_qual_actions_offset_define_forward_trap_qualifier_offset].name = "forward_trap_qualifier_offset";
    submodule_data->defines[dnx_data_field_encoded_qual_actions_offset_define_forward_trap_qualifier_offset].doc = "The offset of the Trap Qualifier Qualifier in the action bcmFieldActionForward";
    
    submodule_data->defines[dnx_data_field_encoded_qual_actions_offset_define_forward_trap_qualifier_offset].flags |= DNXC_DATA_F_DEFINE;

    
    submodule_data->nof_tables = _dnx_data_field_encoded_qual_actions_offset_table_nof;
    DNXC_DATA_ALLOC(submodule_data->tables, dnxc_data_table_t, submodule_data->nof_tables, "_dnxc_data field encoded_qual_actions_offset tables");


exit:
    SHR_FUNC_EXIT;
}


int
dnx_data_field_encoded_qual_actions_offset_feature_get(
    int unit,
    dnx_data_field_encoded_qual_actions_offset_feature_e feature)
{
    return dnxc_data_mgmt_feature_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_encoded_qual_actions_offset, feature);
}


uint32
dnx_data_field_encoded_qual_actions_offset_trap_strength_offset_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_encoded_qual_actions_offset, dnx_data_field_encoded_qual_actions_offset_define_trap_strength_offset);
}

uint32
dnx_data_field_encoded_qual_actions_offset_trap_qualifier_offset_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_encoded_qual_actions_offset, dnx_data_field_encoded_qual_actions_offset_define_trap_qualifier_offset);
}

uint32
dnx_data_field_encoded_qual_actions_offset_sniff_qualifier_offset_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_encoded_qual_actions_offset, dnx_data_field_encoded_qual_actions_offset_define_sniff_qualifier_offset);
}

uint32
dnx_data_field_encoded_qual_actions_offset_mirror_qualifier_offset_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_encoded_qual_actions_offset, dnx_data_field_encoded_qual_actions_offset_define_mirror_qualifier_offset);
}

uint32
dnx_data_field_encoded_qual_actions_offset_forward_trap_qualifier_offset_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_encoded_qual_actions_offset, dnx_data_field_encoded_qual_actions_offset_define_forward_trap_qualifier_offset);
}










static shr_error_e
dnx_data_field_compare_init(
    int unit,
    dnxc_data_submodule_t *submodule_data)
{
    SHR_FUNC_INIT_VARS(unit);

    submodule_data->name = "compare";
    submodule_data->doc = "Compare feature";
    
    submodule_data->nof_features = _dnx_data_field_compare_feature_nof;
    DNXC_DATA_ALLOC(submodule_data->features, dnxc_data_feature_t,  submodule_data->nof_features, "_dnxc_data field compare features");

    
    submodule_data->nof_defines = _dnx_data_field_compare_define_nof;
    DNXC_DATA_ALLOC(submodule_data->defines, dnxc_data_define_t, submodule_data->nof_defines, "_dnxc_data field compare defines");

    submodule_data->defines[dnx_data_field_compare_define_equal_offset].name = "equal_offset";
    submodule_data->defines[dnx_data_field_compare_define_equal_offset].doc = "The position in the qual showing that the result of compare is equal";
    
    submodule_data->defines[dnx_data_field_compare_define_equal_offset].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_compare_define_not_equal_offset].name = "not_equal_offset";
    submodule_data->defines[dnx_data_field_compare_define_not_equal_offset].doc = "The position in the qual showing that the result of compare is not equal";
    
    submodule_data->defines[dnx_data_field_compare_define_not_equal_offset].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_compare_define_smaller_offset].name = "smaller_offset";
    submodule_data->defines[dnx_data_field_compare_define_smaller_offset].doc = "The position in the qual showing that the first compare value is smaller then the second";
    
    submodule_data->defines[dnx_data_field_compare_define_smaller_offset].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_compare_define_not_smaller_offset].name = "not_smaller_offset";
    submodule_data->defines[dnx_data_field_compare_define_not_smaller_offset].doc = "The position in the qual showing that the first compare value is not smaller then the second";
    
    submodule_data->defines[dnx_data_field_compare_define_not_smaller_offset].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_compare_define_bigger_offset].name = "bigger_offset";
    submodule_data->defines[dnx_data_field_compare_define_bigger_offset].doc = "The position in the qual showing that the first compare value is bigger then the second";
    
    submodule_data->defines[dnx_data_field_compare_define_bigger_offset].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_compare_define_not_bigger_offset].name = "not_bigger_offset";
    submodule_data->defines[dnx_data_field_compare_define_not_bigger_offset].doc = "The position in the qual showing that the first compare value is not bigger then the second";
    
    submodule_data->defines[dnx_data_field_compare_define_not_bigger_offset].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_compare_define_nof_keys].name = "nof_keys";
    submodule_data->defines[dnx_data_field_compare_define_nof_keys].doc = "Nof keys in compare pair";
    
    submodule_data->defines[dnx_data_field_compare_define_nof_keys].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_compare_define_nof_compare_pairs].name = "nof_compare_pairs";
    submodule_data->defines[dnx_data_field_compare_define_nof_compare_pairs].doc = "Maximal number of pairs used for compare.";
    
    submodule_data->defines[dnx_data_field_compare_define_nof_compare_pairs].flags |= DNXC_DATA_F_DEFINE;

    
    submodule_data->nof_tables = _dnx_data_field_compare_table_nof;
    DNXC_DATA_ALLOC(submodule_data->tables, dnxc_data_table_t, submodule_data->nof_tables, "_dnxc_data field compare tables");


exit:
    SHR_FUNC_EXIT;
}


int
dnx_data_field_compare_feature_get(
    int unit,
    dnx_data_field_compare_feature_e feature)
{
    return dnxc_data_mgmt_feature_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_compare, feature);
}


uint32
dnx_data_field_compare_equal_offset_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_compare, dnx_data_field_compare_define_equal_offset);
}

uint32
dnx_data_field_compare_not_equal_offset_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_compare, dnx_data_field_compare_define_not_equal_offset);
}

uint32
dnx_data_field_compare_smaller_offset_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_compare, dnx_data_field_compare_define_smaller_offset);
}

uint32
dnx_data_field_compare_not_smaller_offset_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_compare, dnx_data_field_compare_define_not_smaller_offset);
}

uint32
dnx_data_field_compare_bigger_offset_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_compare, dnx_data_field_compare_define_bigger_offset);
}

uint32
dnx_data_field_compare_not_bigger_offset_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_compare, dnx_data_field_compare_define_not_bigger_offset);
}

uint32
dnx_data_field_compare_nof_keys_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_compare, dnx_data_field_compare_define_nof_keys);
}

uint32
dnx_data_field_compare_nof_compare_pairs_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_compare, dnx_data_field_compare_define_nof_compare_pairs);
}










static shr_error_e
dnx_data_field_diag_init(
    int unit,
    dnxc_data_submodule_t *submodule_data)
{
    SHR_FUNC_INIT_VARS(unit);

    submodule_data->name = "diag";
    submodule_data->doc = "Field diagnostics related defines and features.";
    
    submodule_data->nof_features = _dnx_data_field_diag_feature_nof;
    DNXC_DATA_ALLOC(submodule_data->features, dnxc_data_feature_t,  submodule_data->nof_features, "_dnxc_data field diag features");

    submodule_data->features[dnx_data_field_diag_tcam_cs_hit_bit_support].name = "tcam_cs_hit_bit_support";
    submodule_data->features[dnx_data_field_diag_tcam_cs_hit_bit_support].doc = "Indicates if the TCAM Context Selection hit bit indication is supported.";
    submodule_data->features[dnx_data_field_diag_tcam_cs_hit_bit_support].flags |= DNXC_DATA_F_FEATURE;

    
    submodule_data->nof_defines = _dnx_data_field_diag_define_nof;
    DNXC_DATA_ALLOC(submodule_data->defines, dnxc_data_define_t, submodule_data->nof_defines, "_dnxc_data field diag defines");

    submodule_data->defines[dnx_data_field_diag_define_bytes_to_remove_mask].name = "bytes_to_remove_mask";
    submodule_data->defines[dnx_data_field_diag_define_bytes_to_remove_mask].doc = "Mask of bits, which are related to the value of bytes to remove, from the signal.";
    
    submodule_data->defines[dnx_data_field_diag_define_bytes_to_remove_mask].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_diag_define_layers_to_remove_size_in_bit].name = "layers_to_remove_size_in_bit";
    submodule_data->defines[dnx_data_field_diag_define_layers_to_remove_size_in_bit].doc = "Size of the layers to remove value in bits, to be used for shifting the signal value.";
    
    submodule_data->defines[dnx_data_field_diag_define_layers_to_remove_size_in_bit].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_diag_define_layers_to_remove_mask].name = "layers_to_remove_mask";
    submodule_data->defines[dnx_data_field_diag_define_layers_to_remove_mask].doc = "Mask of bits, which are related to the value of layers to remove, from the signal.";
    
    submodule_data->defines[dnx_data_field_diag_define_layers_to_remove_mask].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_diag_define_nof_signals_per_action].name = "nof_signals_per_action";
    submodule_data->defines[dnx_data_field_diag_define_nof_signals_per_action].doc = "Maximum number of signals per action.";
    
    submodule_data->defines[dnx_data_field_diag_define_nof_signals_per_action].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_diag_define_nof_signals_per_qualifier].name = "nof_signals_per_qualifier";
    submodule_data->defines[dnx_data_field_diag_define_nof_signals_per_qualifier].doc = "Maximum number of signals per qualifier.";
    
    submodule_data->defines[dnx_data_field_diag_define_nof_signals_per_qualifier].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_diag_define_key_signal_size_in_bytes].name = "key_signal_size_in_bytes";
    submodule_data->defines[dnx_data_field_diag_define_key_signal_size_in_bytes].doc = "Number of bytes to store KEY signal value.";
    
    submodule_data->defines[dnx_data_field_diag_define_key_signal_size_in_bytes].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_diag_define_result_signal_size_in_words].name = "result_signal_size_in_words";
    submodule_data->defines[dnx_data_field_diag_define_result_signal_size_in_words].doc = "Maximum number of words to store RESULT signal value.";
    
    submodule_data->defines[dnx_data_field_diag_define_result_signal_size_in_words].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_diag_define_dt_result_signal_size_in_words].name = "dt_result_signal_size_in_words";
    submodule_data->defines[dnx_data_field_diag_define_dt_result_signal_size_in_words].doc = "Maximum number of words to store DT RESULT signal value.";
    
    submodule_data->defines[dnx_data_field_diag_define_dt_result_signal_size_in_words].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_diag_define_hit_signal_size_in_words].name = "hit_signal_size_in_words";
    submodule_data->defines[dnx_data_field_diag_define_hit_signal_size_in_words].doc = "Maximum number of words to store HIT signal value.";
    
    submodule_data->defines[dnx_data_field_diag_define_hit_signal_size_in_words].flags |= DNXC_DATA_F_DEFINE;

    
    submodule_data->nof_tables = _dnx_data_field_diag_table_nof;
    DNXC_DATA_ALLOC(submodule_data->tables, dnxc_data_table_t, submodule_data->nof_tables, "_dnxc_data field diag tables");


exit:
    SHR_FUNC_EXIT;
}


int
dnx_data_field_diag_feature_get(
    int unit,
    dnx_data_field_diag_feature_e feature)
{
    return dnxc_data_mgmt_feature_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_diag, feature);
}


uint32
dnx_data_field_diag_bytes_to_remove_mask_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_diag, dnx_data_field_diag_define_bytes_to_remove_mask);
}

uint32
dnx_data_field_diag_layers_to_remove_size_in_bit_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_diag, dnx_data_field_diag_define_layers_to_remove_size_in_bit);
}

uint32
dnx_data_field_diag_layers_to_remove_mask_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_diag, dnx_data_field_diag_define_layers_to_remove_mask);
}

uint32
dnx_data_field_diag_nof_signals_per_action_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_diag, dnx_data_field_diag_define_nof_signals_per_action);
}

uint32
dnx_data_field_diag_nof_signals_per_qualifier_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_diag, dnx_data_field_diag_define_nof_signals_per_qualifier);
}

uint32
dnx_data_field_diag_key_signal_size_in_bytes_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_diag, dnx_data_field_diag_define_key_signal_size_in_bytes);
}

uint32
dnx_data_field_diag_result_signal_size_in_words_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_diag, dnx_data_field_diag_define_result_signal_size_in_words);
}

uint32
dnx_data_field_diag_dt_result_signal_size_in_words_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_diag, dnx_data_field_diag_define_dt_result_signal_size_in_words);
}

uint32
dnx_data_field_diag_hit_signal_size_in_words_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_diag, dnx_data_field_diag_define_hit_signal_size_in_words);
}










static shr_error_e
dnx_data_field_general_data_qualifiers_init(
    int unit,
    dnxc_data_submodule_t *submodule_data)
{
    SHR_FUNC_INIT_VARS(unit);

    submodule_data->name = "general_data_qualifiers";
    submodule_data->doc = "Size and locations on general data of qualifiers.";
    
    submodule_data->nof_features = _dnx_data_field_general_data_qualifiers_feature_nof;
    DNXC_DATA_ALLOC(submodule_data->features, dnxc_data_feature_t,  submodule_data->nof_features, "_dnxc_data field general_data_qualifiers features");

    
    submodule_data->nof_defines = _dnx_data_field_general_data_qualifiers_define_nof;
    DNXC_DATA_ALLOC(submodule_data->defines, dnxc_data_define_t, submodule_data->nof_defines, "_dnxc_data field general_data_qualifiers defines");

    submodule_data->defines[dnx_data_field_general_data_qualifiers_define_vw_supported].name = "vw_supported";
    submodule_data->defines[dnx_data_field_general_data_qualifiers_define_vw_supported].doc = "Indicate if VW feature supported";
    
    submodule_data->defines[dnx_data_field_general_data_qualifiers_define_vw_supported].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_general_data_qualifiers_define_ac_in_lif_wide_data_nof_bits].name = "ac_in_lif_wide_data_nof_bits";
    submodule_data->defines[dnx_data_field_general_data_qualifiers_define_ac_in_lif_wide_data_nof_bits].doc = "Number of bits on general_data for DBAL_FIELD_AC_IN_LIF_WIDE_DATA";
    
    submodule_data->defines[dnx_data_field_general_data_qualifiers_define_ac_in_lif_wide_data_nof_bits].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_general_data_qualifiers_define_pwe_in_lif_wide_data_nof_bits].name = "pwe_in_lif_wide_data_nof_bits";
    submodule_data->defines[dnx_data_field_general_data_qualifiers_define_pwe_in_lif_wide_data_nof_bits].doc = "Number of bits on general_data for DBAL_FIELD_PWE_IN_LIF_WIDE_DATA";
    
    submodule_data->defines[dnx_data_field_general_data_qualifiers_define_pwe_in_lif_wide_data_nof_bits].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_general_data_qualifiers_define_ip_tunnel_in_lif_wide_data_nof_bits].name = "ip_tunnel_in_lif_wide_data_nof_bits";
    submodule_data->defines[dnx_data_field_general_data_qualifiers_define_ip_tunnel_in_lif_wide_data_nof_bits].doc = "Number of bits on general_data for DBAL_FIELD_IP_TUNNEL_IN_LIF_WIDE_DATA";
    
    submodule_data->defines[dnx_data_field_general_data_qualifiers_define_ip_tunnel_in_lif_wide_data_nof_bits].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_general_data_qualifiers_define_native_ac_in_lif_wide_data_nof_bits].name = "native_ac_in_lif_wide_data_nof_bits";
    submodule_data->defines[dnx_data_field_general_data_qualifiers_define_native_ac_in_lif_wide_data_nof_bits].doc = "Number of bits on general_data for DBAL_FIELD_NATIVE_AC_IN_LIF_WIDE_DATA";
    
    submodule_data->defines[dnx_data_field_general_data_qualifiers_define_native_ac_in_lif_wide_data_nof_bits].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_general_data_qualifiers_define_ac_in_lif_wide_data_extended_nof_bits].name = "ac_in_lif_wide_data_extended_nof_bits";
    submodule_data->defines[dnx_data_field_general_data_qualifiers_define_ac_in_lif_wide_data_extended_nof_bits].doc = "Number of bits on general_data for DBAL_FIELD_AC_IN_LIF_WIDE_DATA_EXTENDED";
    
    submodule_data->defines[dnx_data_field_general_data_qualifiers_define_ac_in_lif_wide_data_extended_nof_bits].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_general_data_qualifiers_define_mact_entry_grouping_nof_bits].name = "mact_entry_grouping_nof_bits";
    submodule_data->defines[dnx_data_field_general_data_qualifiers_define_mact_entry_grouping_nof_bits].doc = "Number of bits on general_data for DBAL_FIELD_MACT_ENTRY_GROUPING";
    
    submodule_data->defines[dnx_data_field_general_data_qualifiers_define_mact_entry_grouping_nof_bits].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_general_data_qualifiers_define_vw_vip_valid_nof_bits].name = "vw_vip_valid_nof_bits";
    submodule_data->defines[dnx_data_field_general_data_qualifiers_define_vw_vip_valid_nof_bits].doc = "Number of bits on general_data for DBAL_FIELD_VW_VIP_VALID";
    
    submodule_data->defines[dnx_data_field_general_data_qualifiers_define_vw_vip_valid_nof_bits].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_general_data_qualifiers_define_vw_vip_id_nof_bits].name = "vw_vip_id_nof_bits";
    submodule_data->defines[dnx_data_field_general_data_qualifiers_define_vw_vip_id_nof_bits].doc = "Number of bits on general_data for DBAL_FIELD_VW_VIP_ID";
    
    submodule_data->defines[dnx_data_field_general_data_qualifiers_define_vw_vip_id_nof_bits].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_general_data_qualifiers_define_vw_member_reference_nof_bits].name = "vw_member_reference_nof_bits";
    submodule_data->defines[dnx_data_field_general_data_qualifiers_define_vw_member_reference_nof_bits].doc = "Number of bits on general_data for DBAL_FIELD_VW_MEMBER_REFERENCE";
    
    submodule_data->defines[dnx_data_field_general_data_qualifiers_define_vw_member_reference_nof_bits].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_general_data_qualifiers_define_vw_pcc_hit_nof_bits].name = "vw_pcc_hit_nof_bits";
    submodule_data->defines[dnx_data_field_general_data_qualifiers_define_vw_pcc_hit_nof_bits].doc = "Number of bits on general_data for DBAL_FIELD_VW_PCC_HIT";
    
    submodule_data->defines[dnx_data_field_general_data_qualifiers_define_vw_pcc_hit_nof_bits].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_general_data_qualifiers_define_l3srcbind_hit_nof_bits].name = "l3srcbind_hit_nof_bits";
    submodule_data->defines[dnx_data_field_general_data_qualifiers_define_l3srcbind_hit_nof_bits].doc = "Number of bits on general_data for DBAL_FIELD_L3SRCBIND_HIT";
    
    submodule_data->defines[dnx_data_field_general_data_qualifiers_define_l3srcbind_hit_nof_bits].flags |= DNXC_DATA_F_DEFINE;

    
    submodule_data->nof_tables = _dnx_data_field_general_data_qualifiers_table_nof;
    DNXC_DATA_ALLOC(submodule_data->tables, dnxc_data_table_t, submodule_data->nof_tables, "_dnxc_data field general_data_qualifiers tables");


exit:
    SHR_FUNC_EXIT;
}


int
dnx_data_field_general_data_qualifiers_feature_get(
    int unit,
    dnx_data_field_general_data_qualifiers_feature_e feature)
{
    return dnxc_data_mgmt_feature_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_general_data_qualifiers, feature);
}


uint32
dnx_data_field_general_data_qualifiers_vw_supported_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_general_data_qualifiers, dnx_data_field_general_data_qualifiers_define_vw_supported);
}

uint32
dnx_data_field_general_data_qualifiers_ac_in_lif_wide_data_nof_bits_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_general_data_qualifiers, dnx_data_field_general_data_qualifiers_define_ac_in_lif_wide_data_nof_bits);
}

uint32
dnx_data_field_general_data_qualifiers_pwe_in_lif_wide_data_nof_bits_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_general_data_qualifiers, dnx_data_field_general_data_qualifiers_define_pwe_in_lif_wide_data_nof_bits);
}

uint32
dnx_data_field_general_data_qualifiers_ip_tunnel_in_lif_wide_data_nof_bits_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_general_data_qualifiers, dnx_data_field_general_data_qualifiers_define_ip_tunnel_in_lif_wide_data_nof_bits);
}

uint32
dnx_data_field_general_data_qualifiers_native_ac_in_lif_wide_data_nof_bits_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_general_data_qualifiers, dnx_data_field_general_data_qualifiers_define_native_ac_in_lif_wide_data_nof_bits);
}

uint32
dnx_data_field_general_data_qualifiers_ac_in_lif_wide_data_extended_nof_bits_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_general_data_qualifiers, dnx_data_field_general_data_qualifiers_define_ac_in_lif_wide_data_extended_nof_bits);
}

uint32
dnx_data_field_general_data_qualifiers_mact_entry_grouping_nof_bits_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_general_data_qualifiers, dnx_data_field_general_data_qualifiers_define_mact_entry_grouping_nof_bits);
}

uint32
dnx_data_field_general_data_qualifiers_vw_vip_valid_nof_bits_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_general_data_qualifiers, dnx_data_field_general_data_qualifiers_define_vw_vip_valid_nof_bits);
}

uint32
dnx_data_field_general_data_qualifiers_vw_vip_id_nof_bits_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_general_data_qualifiers, dnx_data_field_general_data_qualifiers_define_vw_vip_id_nof_bits);
}

uint32
dnx_data_field_general_data_qualifiers_vw_member_reference_nof_bits_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_general_data_qualifiers, dnx_data_field_general_data_qualifiers_define_vw_member_reference_nof_bits);
}

uint32
dnx_data_field_general_data_qualifiers_vw_pcc_hit_nof_bits_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_general_data_qualifiers, dnx_data_field_general_data_qualifiers_define_vw_pcc_hit_nof_bits);
}

uint32
dnx_data_field_general_data_qualifiers_l3srcbind_hit_nof_bits_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_general_data_qualifiers, dnx_data_field_general_data_qualifiers_define_l3srcbind_hit_nof_bits);
}










static shr_error_e
dnx_data_field_common_max_val_init(
    int unit,
    dnxc_data_submodule_t *submodule_data)
{
    SHR_FUNC_INIT_VARS(unit);

    submodule_data->name = "common_max_val";
    submodule_data->doc = "Common max values over all PMF stages (IPMF1/IPMF2/IPMF3/EPMF) or over all IO types (TCAM, EXAM, ...)";
    
    submodule_data->nof_features = _dnx_data_field_common_max_val_feature_nof;
    DNXC_DATA_ALLOC(submodule_data->features, dnxc_data_feature_t,  submodule_data->nof_features, "_dnxc_data field common_max_val features");

    
    submodule_data->nof_defines = _dnx_data_field_common_max_val_define_nof;
    DNXC_DATA_ALLOC(submodule_data->defines, dnxc_data_define_t, submodule_data->nof_defines, "_dnxc_data field common_max_val defines");

    submodule_data->defines[dnx_data_field_common_max_val_define_nof_ffc].name = "nof_ffc";
    submodule_data->defines[dnx_data_field_common_max_val_define_nof_ffc].doc = "Maximal number of FFC's in all stages";
    
    submodule_data->defines[dnx_data_field_common_max_val_define_nof_ffc].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_common_max_val_define_nof_masks_per_fes].name = "nof_masks_per_fes";
    submodule_data->defines[dnx_data_field_common_max_val_define_nof_masks_per_fes].doc = "Number of masks per FES";
    
    submodule_data->defines[dnx_data_field_common_max_val_define_nof_masks_per_fes].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_common_max_val_define_nof_fes_id_per_array].name = "nof_fes_id_per_array";
    submodule_data->defines[dnx_data_field_common_max_val_define_nof_fes_id_per_array].doc = "Number FESes in each FES array";
    
    submodule_data->defines[dnx_data_field_common_max_val_define_nof_fes_id_per_array].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_common_max_val_define_nof_fes_array].name = "nof_fes_array";
    submodule_data->defines[dnx_data_field_common_max_val_define_nof_fes_array].doc = "Number FES arrays";
    
    submodule_data->defines[dnx_data_field_common_max_val_define_nof_fes_array].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_common_max_val_define_nof_fes_instruction_per_context].name = "nof_fes_instruction_per_context";
    submodule_data->defines[dnx_data_field_common_max_val_define_nof_fes_instruction_per_context].doc = "Number of FES INSTRUCTIONs per context";
    
    submodule_data->defines[dnx_data_field_common_max_val_define_nof_fes_instruction_per_context].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_common_max_val_define_nof_fes_programs].name = "nof_fes_programs";
    submodule_data->defines[dnx_data_field_common_max_val_define_nof_fes_programs].doc = "Number of FES programs";
    
    submodule_data->defines[dnx_data_field_common_max_val_define_nof_fes_programs].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_common_max_val_define_nof_prog_per_fes].name = "nof_prog_per_fes";
    submodule_data->defines[dnx_data_field_common_max_val_define_nof_prog_per_fes].doc = "Number of MS bits instruction programs per FES";
    
    submodule_data->defines[dnx_data_field_common_max_val_define_nof_prog_per_fes].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_common_max_val_define_nof_cs_lines].name = "nof_cs_lines";
    submodule_data->defines[dnx_data_field_common_max_val_define_nof_cs_lines].doc = "Number of program selection lines";
    
    submodule_data->defines[dnx_data_field_common_max_val_define_nof_cs_lines].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_common_max_val_define_nof_contexts].name = "nof_contexts";
    submodule_data->defines[dnx_data_field_common_max_val_define_nof_contexts].doc = "Number of contexts per PMF";
    
    submodule_data->defines[dnx_data_field_common_max_val_define_nof_contexts].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_common_max_val_define_nof_actions].name = "nof_actions";
    submodule_data->defines[dnx_data_field_common_max_val_define_nof_actions].doc = "Number of actions";
    
    submodule_data->defines[dnx_data_field_common_max_val_define_nof_actions].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_common_max_val_define_nof_qualifiers].name = "nof_qualifiers";
    submodule_data->defines[dnx_data_field_common_max_val_define_nof_qualifiers].doc = "Number of qualifiers";
    
    submodule_data->defines[dnx_data_field_common_max_val_define_nof_qualifiers].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_common_max_val_define_nof_bits_in_fes_action].name = "nof_bits_in_fes_action";
    submodule_data->defines[dnx_data_field_common_max_val_define_nof_bits_in_fes_action].doc = "Number of bits on the outpus of a FES.";
    
    submodule_data->defines[dnx_data_field_common_max_val_define_nof_bits_in_fes_action].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_common_max_val_define_nof_bits_in_fes_key_select].name = "nof_bits_in_fes_key_select";
    submodule_data->defines[dnx_data_field_common_max_val_define_nof_bits_in_fes_key_select].doc = "Number of bits on input to FES.";
    
    submodule_data->defines[dnx_data_field_common_max_val_define_nof_bits_in_fes_key_select].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_common_max_val_define_nof_bits_in_ffc].name = "nof_bits_in_ffc";
    submodule_data->defines[dnx_data_field_common_max_val_define_nof_bits_in_ffc].doc = "Number of bits in ffc.";
    
    submodule_data->defines[dnx_data_field_common_max_val_define_nof_bits_in_ffc].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_common_max_val_define_nof_ffc_in_uint32].name = "nof_ffc_in_uint32";
    submodule_data->defines[dnx_data_field_common_max_val_define_nof_ffc_in_uint32].doc = "Number of uint32 needed to hold bitmap for maximum number of FFC's.";
    
    submodule_data->defines[dnx_data_field_common_max_val_define_nof_ffc_in_uint32].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_common_max_val_define_nof_action_per_group].name = "nof_action_per_group";
    submodule_data->defines[dnx_data_field_common_max_val_define_nof_action_per_group].doc = "Maxmimal number of actions between both Field Group and ACE format. Used for arrays in functions that serve both.";
    
    submodule_data->defines[dnx_data_field_common_max_val_define_nof_action_per_group].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_common_max_val_define_nof_layer_records].name = "nof_layer_records";
    submodule_data->defines[dnx_data_field_common_max_val_define_nof_layer_records].doc = "Maximal number of layer records.";
    
    submodule_data->defines[dnx_data_field_common_max_val_define_nof_layer_records].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_common_max_val_define_layer_record_size].name = "layer_record_size";
    submodule_data->defines[dnx_data_field_common_max_val_define_layer_record_size].doc = "Maximal size of layer records.";
    
    submodule_data->defines[dnx_data_field_common_max_val_define_layer_record_size].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_common_max_val_define_nof_l4_ops_ranges_legacy].name = "nof_l4_ops_ranges_legacy";
    submodule_data->defines[dnx_data_field_common_max_val_define_nof_l4_ops_ranges_legacy].doc = "Maximal number of ranges for L4 Ops legacy.";
    
    submodule_data->defines[dnx_data_field_common_max_val_define_nof_l4_ops_ranges_legacy].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_common_max_val_define_nof_pkt_hdr_ranges].name = "nof_pkt_hdr_ranges";
    submodule_data->defines[dnx_data_field_common_max_val_define_nof_pkt_hdr_ranges].doc = "Maximal number of ranges for packet header.";
    
    submodule_data->defines[dnx_data_field_common_max_val_define_nof_pkt_hdr_ranges].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_common_max_val_define_nof_out_lif_ranges].name = "nof_out_lif_ranges";
    submodule_data->defines[dnx_data_field_common_max_val_define_nof_out_lif_ranges].doc = "Maximal number of ranges for Out Lif.";
    
    submodule_data->defines[dnx_data_field_common_max_val_define_nof_out_lif_ranges].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_common_max_val_define_kbr_size].name = "kbr_size";
    submodule_data->defines[dnx_data_field_common_max_val_define_kbr_size].doc = "Maximal KBR size.";
    
    submodule_data->defines[dnx_data_field_common_max_val_define_kbr_size].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_common_max_val_define_nof_compare_pairs_in_compare_mode].name = "nof_compare_pairs_in_compare_mode";
    submodule_data->defines[dnx_data_field_common_max_val_define_nof_compare_pairs_in_compare_mode].doc = "Number compare pairs in compare mode.";
    
    submodule_data->defines[dnx_data_field_common_max_val_define_nof_compare_pairs_in_compare_mode].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_common_max_val_define_nof_bits_in_fem_action].name = "nof_bits_in_fem_action";
    submodule_data->defines[dnx_data_field_common_max_val_define_nof_bits_in_fem_action].doc = "Maximal number of bits on action value in IPPC_FEM_*_*_MAP_TABLE.";
    
    submodule_data->defines[dnx_data_field_common_max_val_define_nof_bits_in_fem_action].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_common_max_val_define_nof_fem_condition].name = "nof_fem_condition";
    submodule_data->defines[dnx_data_field_common_max_val_define_nof_fem_condition].doc = "Total number of fem conditions. This is the number of conditions that may be assigned to each (fem_id,fem_program) combination.";
    
    submodule_data->defines[dnx_data_field_common_max_val_define_nof_fem_condition].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_common_max_val_define_nof_fem_map_index].name = "nof_fem_map_index";
    submodule_data->defines[dnx_data_field_common_max_val_define_nof_fem_map_index].doc = "Total number fem map indices. This represents the number of actions that may be assigned to each condition.";
    
    submodule_data->defines[dnx_data_field_common_max_val_define_nof_fem_map_index].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_common_max_val_define_nof_fem_programs].name = "nof_fem_programs";
    submodule_data->defines[dnx_data_field_common_max_val_define_nof_fem_programs].doc = "Total number FEM programs available.";
    
    submodule_data->defines[dnx_data_field_common_max_val_define_nof_fem_programs].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_common_max_val_define_nof_fem_id].name = "nof_fem_id";
    submodule_data->defines[dnx_data_field_common_max_val_define_nof_fem_id].doc = "Total number 'FEM id's available.";
    
    submodule_data->defines[dnx_data_field_common_max_val_define_nof_fem_id].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_common_max_val_define_nof_array_ids].name = "nof_array_ids";
    submodule_data->defines[dnx_data_field_common_max_val_define_nof_array_ids].doc = "Total number of 'array_is's which are used to identify a range of FESes or FEMs. See BCM_FIELD_ACTION_POSITION.";
    
    submodule_data->defines[dnx_data_field_common_max_val_define_nof_array_ids].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_common_max_val_define_dbal_pairs].name = "dbal_pairs";
    submodule_data->defines[dnx_data_field_common_max_val_define_dbal_pairs].doc = "Maximum number of pairs which are used to identify the DBAL key/result field in dnx_field_dbal_entry_set function. ";
    
    submodule_data->defines[dnx_data_field_common_max_val_define_dbal_pairs].flags |= DNXC_DATA_F_DEFINE;

    
    submodule_data->nof_tables = _dnx_data_field_common_max_val_table_nof;
    DNXC_DATA_ALLOC(submodule_data->tables, dnxc_data_table_t, submodule_data->nof_tables, "_dnxc_data field common_max_val tables");

    
    submodule_data->tables[dnx_data_field_common_max_val_table_array_id_type].name = "array_id_type";
    submodule_data->tables[dnx_data_field_common_max_val_table_array_id_type].doc = "Contains indications on whether a specific 'array_id' is for FESes or for FEMs";
    submodule_data->tables[dnx_data_field_common_max_val_table_array_id_type].flags |= DNXC_DATA_F_TABLE;
    submodule_data->tables[dnx_data_field_common_max_val_table_array_id_type].size_of_values = sizeof(dnx_data_field_common_max_val_array_id_type_t);
    submodule_data->tables[dnx_data_field_common_max_val_table_array_id_type].entry_get = dnx_data_field_common_max_val_array_id_type_entry_str_get;

    
    submodule_data->tables[dnx_data_field_common_max_val_table_array_id_type].nof_keys = 1;
    submodule_data->tables[dnx_data_field_common_max_val_table_array_id_type].keys[0].name = "array_id";
    submodule_data->tables[dnx_data_field_common_max_val_table_array_id_type].keys[0].doc = "Index identifier of 'array_id'";

    
    submodule_data->tables[dnx_data_field_common_max_val_table_array_id_type].nof_values = 4;
    DNXC_DATA_ALLOC(submodule_data->tables[dnx_data_field_common_max_val_table_array_id_type].values, dnxc_data_value_t, submodule_data->tables[dnx_data_field_common_max_val_table_array_id_type].nof_values, "_dnx_data_field_common_max_val_table_array_id_type table values");
    submodule_data->tables[dnx_data_field_common_max_val_table_array_id_type].values[0].name = "is_fes";
    submodule_data->tables[dnx_data_field_common_max_val_table_array_id_type].values[0].type = "int";
    submodule_data->tables[dnx_data_field_common_max_val_table_array_id_type].values[0].doc = "Non-zero if 'array_id' is for FESes. Zero otherwise";
    submodule_data->tables[dnx_data_field_common_max_val_table_array_id_type].values[0].offset = UTILEX_OFFSETOF(dnx_data_field_common_max_val_array_id_type_t, is_fes);
    submodule_data->tables[dnx_data_field_common_max_val_table_array_id_type].values[1].name = "is_fem";
    submodule_data->tables[dnx_data_field_common_max_val_table_array_id_type].values[1].type = "int";
    submodule_data->tables[dnx_data_field_common_max_val_table_array_id_type].values[1].doc = "Non-zero if 'array_id' is for FEMs. Zero otherwise";
    submodule_data->tables[dnx_data_field_common_max_val_table_array_id_type].values[1].offset = UTILEX_OFFSETOF(dnx_data_field_common_max_val_array_id_type_t, is_fem);
    submodule_data->tables[dnx_data_field_common_max_val_table_array_id_type].values[2].name = "fes_array_index";
    submodule_data->tables[dnx_data_field_common_max_val_table_array_id_type].values[2].type = "int";
    submodule_data->tables[dnx_data_field_common_max_val_table_array_id_type].values[2].doc = "Converts 'array_id' to number of FES arrays so far. 'array_id' 0 converts to 0, 2 converts to 1";
    submodule_data->tables[dnx_data_field_common_max_val_table_array_id_type].values[2].offset = UTILEX_OFFSETOF(dnx_data_field_common_max_val_array_id_type_t, fes_array_index);
    submodule_data->tables[dnx_data_field_common_max_val_table_array_id_type].values[3].name = "fem_array_index";
    submodule_data->tables[dnx_data_field_common_max_val_table_array_id_type].values[3].type = "int";
    submodule_data->tables[dnx_data_field_common_max_val_table_array_id_type].values[3].doc = "Converts 'array_id' to number of FEM arrays so far. 'array_id' 1 converts to 0, 3 converts to 1";
    submodule_data->tables[dnx_data_field_common_max_val_table_array_id_type].values[3].offset = UTILEX_OFFSETOF(dnx_data_field_common_max_val_array_id_type_t, fem_array_index);


exit:
    SHR_FUNC_EXIT;
}


int
dnx_data_field_common_max_val_feature_get(
    int unit,
    dnx_data_field_common_max_val_feature_e feature)
{
    return dnxc_data_mgmt_feature_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_common_max_val, feature);
}


uint32
dnx_data_field_common_max_val_nof_ffc_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_common_max_val, dnx_data_field_common_max_val_define_nof_ffc);
}

uint32
dnx_data_field_common_max_val_nof_masks_per_fes_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_common_max_val, dnx_data_field_common_max_val_define_nof_masks_per_fes);
}

uint32
dnx_data_field_common_max_val_nof_fes_id_per_array_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_common_max_val, dnx_data_field_common_max_val_define_nof_fes_id_per_array);
}

uint32
dnx_data_field_common_max_val_nof_fes_array_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_common_max_val, dnx_data_field_common_max_val_define_nof_fes_array);
}

uint32
dnx_data_field_common_max_val_nof_fes_instruction_per_context_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_common_max_val, dnx_data_field_common_max_val_define_nof_fes_instruction_per_context);
}

uint32
dnx_data_field_common_max_val_nof_fes_programs_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_common_max_val, dnx_data_field_common_max_val_define_nof_fes_programs);
}

uint32
dnx_data_field_common_max_val_nof_prog_per_fes_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_common_max_val, dnx_data_field_common_max_val_define_nof_prog_per_fes);
}

uint32
dnx_data_field_common_max_val_nof_cs_lines_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_common_max_val, dnx_data_field_common_max_val_define_nof_cs_lines);
}

uint32
dnx_data_field_common_max_val_nof_contexts_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_common_max_val, dnx_data_field_common_max_val_define_nof_contexts);
}

uint32
dnx_data_field_common_max_val_nof_actions_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_common_max_val, dnx_data_field_common_max_val_define_nof_actions);
}

uint32
dnx_data_field_common_max_val_nof_qualifiers_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_common_max_val, dnx_data_field_common_max_val_define_nof_qualifiers);
}

uint32
dnx_data_field_common_max_val_nof_bits_in_fes_action_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_common_max_val, dnx_data_field_common_max_val_define_nof_bits_in_fes_action);
}

uint32
dnx_data_field_common_max_val_nof_bits_in_fes_key_select_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_common_max_val, dnx_data_field_common_max_val_define_nof_bits_in_fes_key_select);
}

uint32
dnx_data_field_common_max_val_nof_bits_in_ffc_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_common_max_val, dnx_data_field_common_max_val_define_nof_bits_in_ffc);
}

uint32
dnx_data_field_common_max_val_nof_ffc_in_uint32_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_common_max_val, dnx_data_field_common_max_val_define_nof_ffc_in_uint32);
}

uint32
dnx_data_field_common_max_val_nof_action_per_group_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_common_max_val, dnx_data_field_common_max_val_define_nof_action_per_group);
}

uint32
dnx_data_field_common_max_val_nof_layer_records_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_common_max_val, dnx_data_field_common_max_val_define_nof_layer_records);
}

uint32
dnx_data_field_common_max_val_layer_record_size_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_common_max_val, dnx_data_field_common_max_val_define_layer_record_size);
}

uint32
dnx_data_field_common_max_val_nof_l4_ops_ranges_legacy_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_common_max_val, dnx_data_field_common_max_val_define_nof_l4_ops_ranges_legacy);
}

uint32
dnx_data_field_common_max_val_nof_pkt_hdr_ranges_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_common_max_val, dnx_data_field_common_max_val_define_nof_pkt_hdr_ranges);
}

uint32
dnx_data_field_common_max_val_nof_out_lif_ranges_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_common_max_val, dnx_data_field_common_max_val_define_nof_out_lif_ranges);
}

uint32
dnx_data_field_common_max_val_kbr_size_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_common_max_val, dnx_data_field_common_max_val_define_kbr_size);
}

uint32
dnx_data_field_common_max_val_nof_compare_pairs_in_compare_mode_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_common_max_val, dnx_data_field_common_max_val_define_nof_compare_pairs_in_compare_mode);
}

uint32
dnx_data_field_common_max_val_nof_bits_in_fem_action_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_common_max_val, dnx_data_field_common_max_val_define_nof_bits_in_fem_action);
}

uint32
dnx_data_field_common_max_val_nof_fem_condition_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_common_max_val, dnx_data_field_common_max_val_define_nof_fem_condition);
}

uint32
dnx_data_field_common_max_val_nof_fem_map_index_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_common_max_val, dnx_data_field_common_max_val_define_nof_fem_map_index);
}

uint32
dnx_data_field_common_max_val_nof_fem_programs_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_common_max_val, dnx_data_field_common_max_val_define_nof_fem_programs);
}

uint32
dnx_data_field_common_max_val_nof_fem_id_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_common_max_val, dnx_data_field_common_max_val_define_nof_fem_id);
}

uint32
dnx_data_field_common_max_val_nof_array_ids_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_common_max_val, dnx_data_field_common_max_val_define_nof_array_ids);
}

uint32
dnx_data_field_common_max_val_dbal_pairs_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_common_max_val, dnx_data_field_common_max_val_define_dbal_pairs);
}



const dnx_data_field_common_max_val_array_id_type_t *
dnx_data_field_common_max_val_array_id_type_get(
    int unit,
    int array_id)
{
    char *data;
    dnxc_data_table_t *table;

    
    table = dnxc_data_mgmt_table_get(unit, dnx_data_module_field, dnx_data_field_submodule_common_max_val, dnx_data_field_common_max_val_table_array_id_type);
    
    data = dnxc_data_mgmt_table_data_get(unit, table, array_id, 0);
    return (const dnx_data_field_common_max_val_array_id_type_t *) data;

}


shr_error_e
dnx_data_field_common_max_val_array_id_type_entry_str_get(
    int unit,
    char *buffer,
    int key0,
    int key1,
    int value_index)
{
    dnxc_data_table_t *table;
    const dnx_data_field_common_max_val_array_id_type_t *data;
    SHR_FUNC_INIT_VARS(unit);

    
    table = dnxc_data_mgmt_table_get(unit, dnx_data_module_field, dnx_data_field_submodule_common_max_val, dnx_data_field_common_max_val_table_array_id_type);
    data = (const dnx_data_field_common_max_val_array_id_type_t *) dnxc_data_mgmt_table_data_diag_get(unit, table, key0, 0);
    switch (value_index)
    {
        case 0:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->is_fes);
            break;
        case 1:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->is_fem);
            break;
        case 2:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->fes_array_index);
            break;
        case 3:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->fem_array_index);
            break;
    }

    SHR_FUNC_EXIT;
}


const dnxc_data_table_info_t *
dnx_data_field_common_max_val_array_id_type_info_get(
    int unit)
{

    
    return dnxc_data_mgmt_table_info_get(unit, dnx_data_module_field, dnx_data_field_submodule_common_max_val, dnx_data_field_common_max_val_table_array_id_type);

}






static shr_error_e
dnx_data_field_init_init(
    int unit,
    dnxc_data_submodule_t *submodule_data)
{
    SHR_FUNC_INIT_VARS(unit);

    submodule_data->name = "init";
    submodule_data->doc = "Field defines and features related to init.";
    
    submodule_data->nof_features = _dnx_data_field_init_feature_nof;
    DNXC_DATA_ALLOC(submodule_data->features, dnxc_data_feature_t,  submodule_data->nof_features, "_dnxc_data field init features");

    
    submodule_data->nof_defines = _dnx_data_field_init_define_nof;
    DNXC_DATA_ALLOC(submodule_data->defines, dnxc_data_define_t, submodule_data->nof_defines, "_dnxc_data field init defines");

    submodule_data->defines[dnx_data_field_init_define_fec_dest].name = "fec_dest";
    submodule_data->defines[dnx_data_field_init_define_fec_dest].doc = "APP for fec destination";
    
    submodule_data->defines[dnx_data_field_init_define_fec_dest].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_init_define_l4_trap].name = "l4_trap";
    submodule_data->defines[dnx_data_field_init_define_l4_trap].doc = "APP for L4 Trap";
    
    submodule_data->defines[dnx_data_field_init_define_l4_trap].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_init_define_oam_layer_index].name = "oam_layer_index";
    submodule_data->defines[dnx_data_field_init_define_oam_layer_index].doc = "APP for OAM Layer Index";
    
    submodule_data->defines[dnx_data_field_init_define_oam_layer_index].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_init_define_oam_stat].name = "oam_stat";
    submodule_data->defines[dnx_data_field_init_define_oam_stat].doc = "APP for OAM Statistics";
    
    submodule_data->defines[dnx_data_field_init_define_oam_stat].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_init_define_roo].name = "roo";
    submodule_data->defines[dnx_data_field_init_define_roo].doc = "APP for Roo";
    
    submodule_data->defines[dnx_data_field_init_define_roo].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_init_define_disable_erpp_counters].name = "disable_erpp_counters";
    submodule_data->defines[dnx_data_field_init_define_disable_erpp_counters].doc = "APP for Making the statistics counters not be activated.";
    
    submodule_data->defines[dnx_data_field_init_define_disable_erpp_counters].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_init_define_jr1_ipmc_inlif].name = "jr1_ipmc_inlif";
    submodule_data->defines[dnx_data_field_init_define_jr1_ipmc_inlif].doc = "APP for IPMC In LIF";
    
    submodule_data->defines[dnx_data_field_init_define_jr1_ipmc_inlif].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_init_define_j1_same_port].name = "j1_same_port";
    submodule_data->defines[dnx_data_field_init_define_j1_same_port].doc = "APP for J1 Same port";
    
    submodule_data->defines[dnx_data_field_init_define_j1_same_port].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_init_define_j1_learning].name = "j1_learning";
    submodule_data->defines[dnx_data_field_init_define_j1_learning].doc = "APP for J1 Learning";
    
    submodule_data->defines[dnx_data_field_init_define_j1_learning].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_init_define_learn_limit].name = "learn_limit";
    submodule_data->defines[dnx_data_field_init_define_learn_limit].doc = "APP for Learn Limit";
    
    submodule_data->defines[dnx_data_field_init_define_learn_limit].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_init_define_j1_php].name = "j1_php";
    submodule_data->defines[dnx_data_field_init_define_j1_php].doc = "APP for J1 MPLS PHP";
    
    submodule_data->defines[dnx_data_field_init_define_j1_php].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_init_define_ftmh_mc].name = "ftmh_mc";
    submodule_data->defines[dnx_data_field_init_define_ftmh_mc].doc = "APP for FTMH MC";
    
    submodule_data->defines[dnx_data_field_init_define_ftmh_mc].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_init_define_flow_id].name = "flow_id";
    submodule_data->defines[dnx_data_field_init_define_flow_id].doc = "APP for Flow ID";
    
    submodule_data->defines[dnx_data_field_init_define_flow_id].flags |= DNXC_DATA_F_DEFINE;

    
    submodule_data->nof_tables = _dnx_data_field_init_table_nof;
    DNXC_DATA_ALLOC(submodule_data->tables, dnxc_data_table_t, submodule_data->nof_tables, "_dnxc_data field init tables");


exit:
    SHR_FUNC_EXIT;
}


int
dnx_data_field_init_feature_get(
    int unit,
    dnx_data_field_init_feature_e feature)
{
    return dnxc_data_mgmt_feature_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_init, feature);
}


uint32
dnx_data_field_init_fec_dest_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_init, dnx_data_field_init_define_fec_dest);
}

uint32
dnx_data_field_init_l4_trap_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_init, dnx_data_field_init_define_l4_trap);
}

uint32
dnx_data_field_init_oam_layer_index_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_init, dnx_data_field_init_define_oam_layer_index);
}

uint32
dnx_data_field_init_oam_stat_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_init, dnx_data_field_init_define_oam_stat);
}

uint32
dnx_data_field_init_roo_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_init, dnx_data_field_init_define_roo);
}

uint32
dnx_data_field_init_disable_erpp_counters_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_init, dnx_data_field_init_define_disable_erpp_counters);
}

uint32
dnx_data_field_init_jr1_ipmc_inlif_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_init, dnx_data_field_init_define_jr1_ipmc_inlif);
}

uint32
dnx_data_field_init_j1_same_port_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_init, dnx_data_field_init_define_j1_same_port);
}

uint32
dnx_data_field_init_j1_learning_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_init, dnx_data_field_init_define_j1_learning);
}

uint32
dnx_data_field_init_learn_limit_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_init, dnx_data_field_init_define_learn_limit);
}

uint32
dnx_data_field_init_j1_php_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_init, dnx_data_field_init_define_j1_php);
}

uint32
dnx_data_field_init_ftmh_mc_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_init, dnx_data_field_init_define_ftmh_mc);
}

uint32
dnx_data_field_init_flow_id_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_init, dnx_data_field_init_define_flow_id);
}










static shr_error_e
dnx_data_field_features_init(
    int unit,
    dnxc_data_submodule_t *submodule_data)
{
    SHR_FUNC_INIT_VARS(unit);

    submodule_data->name = "features";
    submodule_data->doc = "All device specific features";
    
    submodule_data->nof_features = _dnx_data_field_features_feature_nof;
    DNXC_DATA_ALLOC(submodule_data->features, dnxc_data_feature_t,  submodule_data->nof_features, "_dnxc_data field features features");

    submodule_data->features[dnx_data_field_features_spn_supported].name = "spn_supported";
    submodule_data->features[dnx_data_field_features_spn_supported].doc = "Indicates whether SPN function is supported for hash context.";
    submodule_data->features[dnx_data_field_features_spn_supported].flags |= DNXC_DATA_F_FEATURE;

    
    submodule_data->nof_defines = _dnx_data_field_features_define_nof;
    DNXC_DATA_ALLOC(submodule_data->defines, dnxc_data_define_t, submodule_data->nof_defines, "_dnxc_data field features defines");

    submodule_data->defines[dnx_data_field_features_define_tcam_cs_inlif_profile_supported].name = "tcam_cs_inlif_profile_supported";
    submodule_data->defines[dnx_data_field_features_define_tcam_cs_inlif_profile_supported].doc = "LIF Profile is supported for PMF, bits should be allocated";
    
    submodule_data->defines[dnx_data_field_features_define_tcam_cs_inlif_profile_supported].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_features_define_tcam_cs_is_tcam_direct_access].name = "tcam_cs_is_tcam_direct_access";
    submodule_data->defines[dnx_data_field_features_define_tcam_cs_is_tcam_direct_access].doc = "Identify Dbal table type if its TCAM_DIRECT (HL DBAL)or non-drect (TCAM_CS DBAL)";
    
    submodule_data->defines[dnx_data_field_features_define_tcam_cs_is_tcam_direct_access].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_features_define_ecc_enable].name = "ecc_enable";
    submodule_data->defines[dnx_data_field_features_define_ecc_enable].doc = "ECC is calculated per whole entry otcam_cs_inlif_profile_supportedn each entry write, therefore, when writing half-entries\n                      need to get whole entry from the SW and update relevant half entry.";
    
    submodule_data->defines[dnx_data_field_features_define_ecc_enable].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_features_define_switch_to_acl_context].name = "switch_to_acl_context";
    submodule_data->defines[dnx_data_field_features_define_switch_to_acl_context].doc = "Allows to swap the acl_context and fwd_context signals after iPMF1/2 using IPPC_PMF_GENERAL.SWITCH_TO_ACL_CONTEXT.";
    
    submodule_data->defines[dnx_data_field_features_define_switch_to_acl_context].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_features_define_per_pp_port_pmf_profile_cs_offset].name = "per_pp_port_pmf_profile_cs_offset";
    submodule_data->defines[dnx_data_field_features_define_per_pp_port_pmf_profile_cs_offset].doc = "The placement of PMF_PROFILE field within ERPP_PER_PORT_TABLE. Used because DBAL mapping by device didn't work.";
    
    submodule_data->defines[dnx_data_field_features_define_per_pp_port_pmf_profile_cs_offset].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_features_define_tcam_result_flip_eco].name = "tcam_result_flip_eco";
    submodule_data->defines[dnx_data_field_features_define_tcam_result_flip_eco].doc = "The TCAM result flip ECO is about flippiing lsb and msb parts of the TCAM-result in order to support 80b result being parsed by ARR";
    
    submodule_data->defines[dnx_data_field_features_define_tcam_result_flip_eco].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_features_define_tcam_result_half_payload_on_msb].name = "tcam_result_half_payload_on_msb";
    submodule_data->defines[dnx_data_field_features_define_tcam_result_half_payload_on_msb].doc = "Indicates that for half payload lookup the result is on the MSB half, but not using the tcam_result_flip_eco.";
    
    submodule_data->defines[dnx_data_field_features_define_tcam_result_half_payload_on_msb].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_features_define_parsing_start_offset_msb_meaningless].name = "parsing_start_offset_msb_meaningless";
    submodule_data->defines[dnx_data_field_features_define_parsing_start_offset_msb_meaningless].doc = "In JR2, the parsing_start_offset signal is 8 bit in ingress but only 7 in egress, so we make the action smaller so as not to have a meaningles MSB.";
    
    submodule_data->defines[dnx_data_field_features_define_parsing_start_offset_msb_meaningless].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_features_define_kbp_opcode_in_ipmf1_cs].name = "kbp_opcode_in_ipmf1_cs";
    submodule_data->defines[dnx_data_field_features_define_kbp_opcode_in_ipmf1_cs].doc = "Indicates whether the context selection of iPMF1 takes the KBP opcode into account.";
    
    submodule_data->defines[dnx_data_field_features_define_kbp_opcode_in_ipmf1_cs].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_features_define_kbp_hitbits_correct_in_ipmf1_cs].name = "kbp_hitbits_correct_in_ipmf1_cs";
    submodule_data->defines[dnx_data_field_features_define_kbp_hitbits_correct_in_ipmf1_cs].doc = "Indicates whether the context selection of iPMF1 takes the KBP hitbits from the correct place of the elk payload. Assumed to be either 0 or 1.";
    
    submodule_data->defines[dnx_data_field_features_define_kbp_hitbits_correct_in_ipmf1_cs].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_features_define_exem_vmv_removable_from_payload].name = "exem_vmv_removable_from_payload";
    submodule_data->defines[dnx_data_field_features_define_exem_vmv_removable_from_payload].doc = "Indicates whether it is possible to configure a shift to remove the from the EXEM payload.";
    
    submodule_data->defines[dnx_data_field_features_define_exem_vmv_removable_from_payload].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_features_define_multiple_dynamic_mem_enablers].name = "multiple_dynamic_mem_enablers";
    submodule_data->defines[dnx_data_field_features_define_multiple_dynamic_mem_enablers].doc = "Indicates whether it is possible to configure dynamic memory enablers for ST, CS hit, TCAM entry protection etc.";
    
    submodule_data->defines[dnx_data_field_features_define_multiple_dynamic_mem_enablers].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_features_define_aacl_super_group_handler_enable].name = "aacl_super_group_handler_enable";
    submodule_data->defines[dnx_data_field_features_define_aacl_super_group_handler_enable].doc = "Indicates whether it is possible to configure Super Group Handler for AACL";
    
    submodule_data->defines[dnx_data_field_features_define_aacl_super_group_handler_enable].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_features_define_aacl_tcam_swap_enable].name = "aacl_tcam_swap_enable";
    submodule_data->defines[dnx_data_field_features_define_aacl_tcam_swap_enable].doc = "Indicates whether it is possible to configure TCAM swap for AACL";
    
    submodule_data->defines[dnx_data_field_features_define_aacl_tcam_swap_enable].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_features_define_extended_l4_ops].name = "extended_l4_ops";
    submodule_data->defines[dnx_data_field_features_define_extended_l4_ops].doc = "Whether extended L4 Ops is supported";
    
    submodule_data->defines[dnx_data_field_features_define_extended_l4_ops].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_features_define_state_table_ipmf1_key_select].name = "state_table_ipmf1_key_select";
    submodule_data->defines[dnx_data_field_features_define_state_table_ipmf1_key_select].doc = "Whether we can choose the key for state table in iPMF1.";
    
    submodule_data->defines[dnx_data_field_features_define_state_table_ipmf1_key_select].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_features_define_state_table_acr_bus].name = "state_table_acr_bus";
    submodule_data->defines[dnx_data_field_features_define_state_table_acr_bus].doc = "Whether the EFES/FEM can access the state table result.";
    
    submodule_data->defines[dnx_data_field_features_define_state_table_acr_bus].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_features_define_state_table_atomic_rmw].name = "state_table_atomic_rmw";
    submodule_data->defines[dnx_data_field_features_define_state_table_atomic_rmw].doc = "Whether state table uses atomic read modify write (rmw) instead of separate read and write (rw).";
    
    submodule_data->defines[dnx_data_field_features_define_state_table_atomic_rmw].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_features_define_hitbit_volatile].name = "hitbit_volatile";
    submodule_data->defines[dnx_data_field_features_define_hitbit_volatile].doc = "Indicates on, which devices the HIT_INCDICATION memories have volatile values and therefore we add SW state to save them.";
    
    submodule_data->defines[dnx_data_field_features_define_hitbit_volatile].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_features_define_fem_replace_msb_instead_lsb].name = "fem_replace_msb_instead_lsb";
    submodule_data->defines[dnx_data_field_features_define_fem_replace_msb_instead_lsb].doc = "Starting from Q2A, the 16 MSB of the overriding TCAM are taken, instead of the 16 LSB.";
    
    submodule_data->defines[dnx_data_field_features_define_fem_replace_msb_instead_lsb].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_features_define_dir_ext_epmf].name = "dir_ext_epmf";
    submodule_data->defines[dnx_data_field_features_define_dir_ext_epmf].doc = "Indicates whether Direct Extract is supported for EPMF stage.";
    
    submodule_data->defines[dnx_data_field_features_define_dir_ext_epmf].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_features_define_hashing_process_lsb_to_msb].name = "hashing_process_lsb_to_msb";
    submodule_data->defines[dnx_data_field_features_define_hashing_process_lsb_to_msb].doc = "Indicates whether the Hashing processes the bits from LSB to MSB.";
    
    submodule_data->defines[dnx_data_field_features_define_hashing_process_lsb_to_msb].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_features_define_exem_age_flush_scan].name = "exem_age_flush_scan";
    submodule_data->defines[dnx_data_field_features_define_exem_age_flush_scan].doc = "Indicates whether EXEM age scan period or flush scan period works.";
    
    submodule_data->defines[dnx_data_field_features_define_exem_age_flush_scan].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_features_define_epmf_has_lookup_enabler].name = "epmf_has_lookup_enabler";
    submodule_data->defines[dnx_data_field_features_define_epmf_has_lookup_enabler].doc = "Indicates whether ePMF has lookup enabler table";
    
    submodule_data->defines[dnx_data_field_features_define_epmf_has_lookup_enabler].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_features_define_epmf_outlif_profile_map].name = "epmf_outlif_profile_map";
    submodule_data->defines[dnx_data_field_features_define_epmf_outlif_profile_map].doc = "Indicates whether ePMF CS outlif profile has mapping to CS PMF";
    
    submodule_data->defines[dnx_data_field_features_define_epmf_outlif_profile_map].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_features_define_epmf_inlif_profile_map].name = "epmf_inlif_profile_map";
    submodule_data->defines[dnx_data_field_features_define_epmf_inlif_profile_map].doc = "Indicates whether ePMF CS outlif profile has mapping to PMF";
    
    submodule_data->defines[dnx_data_field_features_define_epmf_inlif_profile_map].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_features_define_tcam_full_key_half_payload_both_lsb_msb].name = "tcam_full_key_half_payload_both_lsb_msb";
    submodule_data->defines[dnx_data_field_features_define_tcam_full_key_half_payload_both_lsb_msb].doc = "Indicates whether a TCAM field group with single size key and half size payload writes its output to both the LSB half and the MSB half.";
    
    submodule_data->defines[dnx_data_field_features_define_tcam_full_key_half_payload_both_lsb_msb].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_features_define_epmf_exem_debug_signal_move_zero_padding_from_msb_to_lsb].name = "epmf_exem_debug_signal_move_zero_padding_from_msb_to_lsb";
    submodule_data->defines[dnx_data_field_features_define_epmf_exem_debug_signal_move_zero_padding_from_msb_to_lsb].doc = "Indicates whether zero padding of ePMF EXEM debug signal needs to be removed from MSB";
    
    submodule_data->defines[dnx_data_field_features_define_epmf_exem_debug_signal_move_zero_padding_from_msb_to_lsb].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_features_define_ecmp_tunnel_priority].name = "ecmp_tunnel_priority";
    submodule_data->defines[dnx_data_field_features_define_ecmp_tunnel_priority].doc = "Indicates whether ECMP TP is supported in PMF";
    
    submodule_data->defines[dnx_data_field_features_define_ecmp_tunnel_priority].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_features_define_result_signal_exists].name = "result_signal_exists";
    submodule_data->defines[dnx_data_field_features_define_result_signal_exists].doc = "Indicates whether lookups have result and hit signals exposed.";
    
    submodule_data->defines[dnx_data_field_features_define_result_signal_exists].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_features_define_apptype_based_on_fwd2].name = "apptype_based_on_fwd2";
    submodule_data->defines[dnx_data_field_features_define_apptype_based_on_fwd2].doc = "Indicates whether predefined apptypes use FWD2 or FWD1 contexts.";
    
    submodule_data->defines[dnx_data_field_features_define_apptype_based_on_fwd2].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_features_define_udh_base_cs_is_mapped].name = "udh_base_cs_is_mapped";
    submodule_data->defines[dnx_data_field_features_define_udh_base_cs_is_mapped].doc = "Indicates whether ePMF UDH Base has PMF CS mapping.";
    
    submodule_data->defines[dnx_data_field_features_define_udh_base_cs_is_mapped].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_features_define_state_collection_engine].name = "state_collection_engine";
    submodule_data->defines[dnx_data_field_features_define_state_collection_engine].doc = "Indicates whether SCE lookup is supported.";
    
    submodule_data->defines[dnx_data_field_features_define_state_collection_engine].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_features_define_empf_trap_action_is_strength_based].name = "empf_trap_action_is_strength_based";
    submodule_data->defines[dnx_data_field_features_define_empf_trap_action_is_strength_based].doc = "Indicates if the EPMF trap action is strength based";
    
    submodule_data->defines[dnx_data_field_features_define_empf_trap_action_is_strength_based].flags |= DNXC_DATA_F_DEFINE;

    
    submodule_data->nof_tables = _dnx_data_field_features_table_nof;
    DNXC_DATA_ALLOC(submodule_data->tables, dnxc_data_table_t, submodule_data->nof_tables, "_dnxc_data field features tables");


exit:
    SHR_FUNC_EXIT;
}


int
dnx_data_field_features_feature_get(
    int unit,
    dnx_data_field_features_feature_e feature)
{
    return dnxc_data_mgmt_feature_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_features, feature);
}


uint32
dnx_data_field_features_tcam_cs_inlif_profile_supported_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_features, dnx_data_field_features_define_tcam_cs_inlif_profile_supported);
}

uint32
dnx_data_field_features_tcam_cs_is_tcam_direct_access_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_features, dnx_data_field_features_define_tcam_cs_is_tcam_direct_access);
}

uint32
dnx_data_field_features_ecc_enable_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_features, dnx_data_field_features_define_ecc_enable);
}

uint32
dnx_data_field_features_switch_to_acl_context_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_features, dnx_data_field_features_define_switch_to_acl_context);
}

uint32
dnx_data_field_features_per_pp_port_pmf_profile_cs_offset_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_features, dnx_data_field_features_define_per_pp_port_pmf_profile_cs_offset);
}

uint32
dnx_data_field_features_tcam_result_flip_eco_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_features, dnx_data_field_features_define_tcam_result_flip_eco);
}

uint32
dnx_data_field_features_tcam_result_half_payload_on_msb_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_features, dnx_data_field_features_define_tcam_result_half_payload_on_msb);
}

uint32
dnx_data_field_features_parsing_start_offset_msb_meaningless_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_features, dnx_data_field_features_define_parsing_start_offset_msb_meaningless);
}

uint32
dnx_data_field_features_kbp_opcode_in_ipmf1_cs_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_features, dnx_data_field_features_define_kbp_opcode_in_ipmf1_cs);
}

uint32
dnx_data_field_features_kbp_hitbits_correct_in_ipmf1_cs_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_features, dnx_data_field_features_define_kbp_hitbits_correct_in_ipmf1_cs);
}

uint32
dnx_data_field_features_exem_vmv_removable_from_payload_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_features, dnx_data_field_features_define_exem_vmv_removable_from_payload);
}

uint32
dnx_data_field_features_multiple_dynamic_mem_enablers_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_features, dnx_data_field_features_define_multiple_dynamic_mem_enablers);
}

uint32
dnx_data_field_features_aacl_super_group_handler_enable_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_features, dnx_data_field_features_define_aacl_super_group_handler_enable);
}

uint32
dnx_data_field_features_aacl_tcam_swap_enable_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_features, dnx_data_field_features_define_aacl_tcam_swap_enable);
}

uint32
dnx_data_field_features_extended_l4_ops_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_features, dnx_data_field_features_define_extended_l4_ops);
}

uint32
dnx_data_field_features_state_table_ipmf1_key_select_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_features, dnx_data_field_features_define_state_table_ipmf1_key_select);
}

uint32
dnx_data_field_features_state_table_acr_bus_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_features, dnx_data_field_features_define_state_table_acr_bus);
}

uint32
dnx_data_field_features_state_table_atomic_rmw_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_features, dnx_data_field_features_define_state_table_atomic_rmw);
}

uint32
dnx_data_field_features_hitbit_volatile_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_features, dnx_data_field_features_define_hitbit_volatile);
}

uint32
dnx_data_field_features_fem_replace_msb_instead_lsb_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_features, dnx_data_field_features_define_fem_replace_msb_instead_lsb);
}

uint32
dnx_data_field_features_dir_ext_epmf_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_features, dnx_data_field_features_define_dir_ext_epmf);
}

uint32
dnx_data_field_features_hashing_process_lsb_to_msb_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_features, dnx_data_field_features_define_hashing_process_lsb_to_msb);
}

uint32
dnx_data_field_features_exem_age_flush_scan_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_features, dnx_data_field_features_define_exem_age_flush_scan);
}

uint32
dnx_data_field_features_epmf_has_lookup_enabler_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_features, dnx_data_field_features_define_epmf_has_lookup_enabler);
}

uint32
dnx_data_field_features_epmf_outlif_profile_map_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_features, dnx_data_field_features_define_epmf_outlif_profile_map);
}

uint32
dnx_data_field_features_epmf_inlif_profile_map_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_features, dnx_data_field_features_define_epmf_inlif_profile_map);
}

uint32
dnx_data_field_features_tcam_full_key_half_payload_both_lsb_msb_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_features, dnx_data_field_features_define_tcam_full_key_half_payload_both_lsb_msb);
}

uint32
dnx_data_field_features_epmf_exem_debug_signal_move_zero_padding_from_msb_to_lsb_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_features, dnx_data_field_features_define_epmf_exem_debug_signal_move_zero_padding_from_msb_to_lsb);
}

uint32
dnx_data_field_features_ecmp_tunnel_priority_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_features, dnx_data_field_features_define_ecmp_tunnel_priority);
}

uint32
dnx_data_field_features_result_signal_exists_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_features, dnx_data_field_features_define_result_signal_exists);
}

uint32
dnx_data_field_features_apptype_based_on_fwd2_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_features, dnx_data_field_features_define_apptype_based_on_fwd2);
}

uint32
dnx_data_field_features_udh_base_cs_is_mapped_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_features, dnx_data_field_features_define_udh_base_cs_is_mapped);
}

uint32
dnx_data_field_features_state_collection_engine_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_features, dnx_data_field_features_define_state_collection_engine);
}

uint32
dnx_data_field_features_empf_trap_action_is_strength_based_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_features, dnx_data_field_features_define_empf_trap_action_is_strength_based);
}










static shr_error_e
dnx_data_field_signal_sizes_init(
    int unit,
    dnxc_data_submodule_t *submodule_data)
{
    SHR_FUNC_INIT_VARS(unit);

    submodule_data->name = "signal_sizes";
    submodule_data->doc = "signal sizes that change by device, as needed for qualifier and action sizes.";
    
    submodule_data->nof_features = _dnx_data_field_signal_sizes_feature_nof;
    DNXC_DATA_ALLOC(submodule_data->features, dnxc_data_feature_t,  submodule_data->nof_features, "_dnxc_data field signal_sizes features");

    
    submodule_data->nof_defines = _dnx_data_field_signal_sizes_define_nof;
    DNXC_DATA_ALLOC(submodule_data->defines, dnxc_data_define_t, submodule_data->nof_defines, "_dnxc_data field signal_sizes defines");

    submodule_data->defines[dnx_data_field_signal_sizes_define_dual_queue_size].name = "dual_queue_size";
    submodule_data->defines[dnx_data_field_signal_sizes_define_dual_queue_size].doc = "";
    
    submodule_data->defines[dnx_data_field_signal_sizes_define_dual_queue_size].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_signal_sizes_define_packet_header_size].name = "packet_header_size";
    submodule_data->defines[dnx_data_field_signal_sizes_define_packet_header_size].doc = "";
    
    submodule_data->defines[dnx_data_field_signal_sizes_define_packet_header_size].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_signal_sizes_define_ecn].name = "ecn";
    submodule_data->defines[dnx_data_field_signal_sizes_define_ecn].doc = "";
    
    submodule_data->defines[dnx_data_field_signal_sizes_define_ecn].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_signal_sizes_define_congestion_info].name = "congestion_info";
    submodule_data->defines[dnx_data_field_signal_sizes_define_congestion_info].doc = "CONGESTION_INFO signal. Takes ECN by default, and changed with it.";
    
    submodule_data->defines[dnx_data_field_signal_sizes_define_congestion_info].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_signal_sizes_define_parsing_start_offset_size].name = "parsing_start_offset_size";
    submodule_data->defines[dnx_data_field_signal_sizes_define_parsing_start_offset_size].doc = "";
    
    submodule_data->defines[dnx_data_field_signal_sizes_define_parsing_start_offset_size].flags |= DNXC_DATA_F_DEFINE;

    
    submodule_data->nof_tables = _dnx_data_field_signal_sizes_table_nof;
    DNXC_DATA_ALLOC(submodule_data->tables, dnxc_data_table_t, submodule_data->nof_tables, "_dnxc_data field signal_sizes tables");


exit:
    SHR_FUNC_EXIT;
}


int
dnx_data_field_signal_sizes_feature_get(
    int unit,
    dnx_data_field_signal_sizes_feature_e feature)
{
    return dnxc_data_mgmt_feature_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_signal_sizes, feature);
}


uint32
dnx_data_field_signal_sizes_dual_queue_size_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_signal_sizes, dnx_data_field_signal_sizes_define_dual_queue_size);
}

uint32
dnx_data_field_signal_sizes_packet_header_size_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_signal_sizes, dnx_data_field_signal_sizes_define_packet_header_size);
}

uint32
dnx_data_field_signal_sizes_ecn_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_signal_sizes, dnx_data_field_signal_sizes_define_ecn);
}

uint32
dnx_data_field_signal_sizes_congestion_info_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_signal_sizes, dnx_data_field_signal_sizes_define_congestion_info);
}

uint32
dnx_data_field_signal_sizes_parsing_start_offset_size_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_signal_sizes, dnx_data_field_signal_sizes_define_parsing_start_offset_size);
}










static shr_error_e
dnx_data_field_dnx_data_internal_init(
    int unit,
    dnxc_data_submodule_t *submodule_data)
{
    SHR_FUNC_INIT_VARS(unit);

    submodule_data->name = "dnx_data_internal";
    submodule_data->doc = "For internal DNX DATA usage only";
    
    submodule_data->nof_features = _dnx_data_field_dnx_data_internal_feature_nof;
    DNXC_DATA_ALLOC(submodule_data->features, dnxc_data_feature_t,  submodule_data->nof_features, "_dnxc_data field dnx_data_internal features");

    
    submodule_data->nof_defines = _dnx_data_field_dnx_data_internal_define_nof;
    DNXC_DATA_ALLOC(submodule_data->defines, dnxc_data_define_t, submodule_data->nof_defines, "_dnxc_data field dnx_data_internal defines");

    submodule_data->defines[dnx_data_field_dnx_data_internal_define_lr_eth_is_da_mac_valid].name = "lr_eth_is_da_mac_valid";
    submodule_data->defines[dnx_data_field_dnx_data_internal_define_lr_eth_is_da_mac_valid].doc = "Whether layer record ETH_IS_DA_MAC works on device (works on JR2_B0 but not on JR2_A0).";
    
    submodule_data->defines[dnx_data_field_dnx_data_internal_define_lr_eth_is_da_mac_valid].flags |= DNXC_DATA_F_DEFINE;

    
    submodule_data->nof_tables = _dnx_data_field_dnx_data_internal_table_nof;
    DNXC_DATA_ALLOC(submodule_data->tables, dnxc_data_table_t, submodule_data->nof_tables, "_dnxc_data field dnx_data_internal tables");


exit:
    SHR_FUNC_EXIT;
}


int
dnx_data_field_dnx_data_internal_feature_get(
    int unit,
    dnx_data_field_dnx_data_internal_feature_e feature)
{
    return dnxc_data_mgmt_feature_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_dnx_data_internal, feature);
}


uint32
dnx_data_field_dnx_data_internal_lr_eth_is_da_mac_valid_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_dnx_data_internal, dnx_data_field_dnx_data_internal_define_lr_eth_is_da_mac_valid);
}










static shr_error_e
dnx_data_field_tests_init(
    int unit,
    dnxc_data_submodule_t *submodule_data)
{
    SHR_FUNC_INIT_VARS(unit);

    submodule_data->name = "tests";
    submodule_data->doc = "Used for field tests, where special checks per device are needed.";
    
    submodule_data->nof_features = _dnx_data_field_tests_feature_nof;
    DNXC_DATA_ALLOC(submodule_data->features, dnxc_data_feature_t,  submodule_data->nof_features, "_dnxc_data field tests features");

    
    submodule_data->nof_defines = _dnx_data_field_tests_define_nof;
    DNXC_DATA_ALLOC(submodule_data->defines, dnxc_data_define_t, submodule_data->nof_defines, "_dnxc_data field tests defines");

    submodule_data->defines[dnx_data_field_tests_define_learn_info_actions_structure_change].name = "learn_info_actions_structure_change";
    submodule_data->defines[dnx_data_field_tests_define_learn_info_actions_structure_change].doc = "";
    
    submodule_data->defines[dnx_data_field_tests_define_learn_info_actions_structure_change].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_tests_define_ingress_time_stamp_increased].name = "ingress_time_stamp_increased";
    submodule_data->defines[dnx_data_field_tests_define_ingress_time_stamp_increased].doc = "";
    
    submodule_data->defines[dnx_data_field_tests_define_ingress_time_stamp_increased].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_tests_define_ace_debug_signals_exist].name = "ace_debug_signals_exist";
    submodule_data->defines[dnx_data_field_tests_define_ace_debug_signals_exist].doc = "";
    
    submodule_data->defines[dnx_data_field_tests_define_ace_debug_signals_exist].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_tests_define_epmf_debug_rely_on_tcam0].name = "epmf_debug_rely_on_tcam0";
    submodule_data->defines[dnx_data_field_tests_define_epmf_debug_rely_on_tcam0].doc = "";
    
    submodule_data->defines[dnx_data_field_tests_define_epmf_debug_rely_on_tcam0].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_tests_define_epmf_tm_port_cs].name = "epmf_tm_port_cs";
    submodule_data->defines[dnx_data_field_tests_define_epmf_tm_port_cs].doc = "";
    
    submodule_data->defines[dnx_data_field_tests_define_epmf_tm_port_cs].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_tests_define_small_exem_addr_bits].name = "small_exem_addr_bits";
    submodule_data->defines[dnx_data_field_tests_define_small_exem_addr_bits].doc = "";
    
    submodule_data->defines[dnx_data_field_tests_define_small_exem_addr_bits].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_field_tests_define_stub_cmodel_supports_semantic_flush].name = "stub_cmodel_supports_semantic_flush";
    submodule_data->defines[dnx_data_field_tests_define_stub_cmodel_supports_semantic_flush].doc = "Indication that stub cmodel can support reading and writing to flush entries.";
    
    submodule_data->defines[dnx_data_field_tests_define_stub_cmodel_supports_semantic_flush].flags |= DNXC_DATA_F_DEFINE;

    
    submodule_data->nof_tables = _dnx_data_field_tests_table_nof;
    DNXC_DATA_ALLOC(submodule_data->tables, dnxc_data_table_t, submodule_data->nof_tables, "_dnxc_data field tests tables");


exit:
    SHR_FUNC_EXIT;
}


int
dnx_data_field_tests_feature_get(
    int unit,
    dnx_data_field_tests_feature_e feature)
{
    return dnxc_data_mgmt_feature_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_tests, feature);
}


uint32
dnx_data_field_tests_learn_info_actions_structure_change_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_tests, dnx_data_field_tests_define_learn_info_actions_structure_change);
}

uint32
dnx_data_field_tests_ingress_time_stamp_increased_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_tests, dnx_data_field_tests_define_ingress_time_stamp_increased);
}

uint32
dnx_data_field_tests_ace_debug_signals_exist_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_tests, dnx_data_field_tests_define_ace_debug_signals_exist);
}

uint32
dnx_data_field_tests_epmf_debug_rely_on_tcam0_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_tests, dnx_data_field_tests_define_epmf_debug_rely_on_tcam0);
}

uint32
dnx_data_field_tests_epmf_tm_port_cs_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_tests, dnx_data_field_tests_define_epmf_tm_port_cs);
}

uint32
dnx_data_field_tests_small_exem_addr_bits_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_tests, dnx_data_field_tests_define_small_exem_addr_bits);
}

uint32
dnx_data_field_tests_stub_cmodel_supports_semantic_flush_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_field, dnx_data_field_submodule_tests, dnx_data_field_tests_define_stub_cmodel_supports_semantic_flush);
}







shr_error_e
dnx_data_field_init(
    int unit,
    dnxc_data_module_t *module_data)
{
    SHR_FUNC_INIT_VARS(unit);

    
    module_data->name = "field";
    module_data->nof_submodules = _dnx_data_field_submodule_nof;
    DNXC_DATA_ALLOC(module_data->submodules, dnxc_data_submodule_t, module_data->nof_submodules, "_dnxc_data field submodules");

    
    SHR_IF_ERR_EXIT(dnx_data_field_base_ipmf1_init(unit, &module_data->submodules[dnx_data_field_submodule_base_ipmf1]));
    SHR_IF_ERR_EXIT(dnx_data_field_base_ipmf2_init(unit, &module_data->submodules[dnx_data_field_submodule_base_ipmf2]));
    SHR_IF_ERR_EXIT(dnx_data_field_base_ipmf3_init(unit, &module_data->submodules[dnx_data_field_submodule_base_ipmf3]));
    SHR_IF_ERR_EXIT(dnx_data_field_base_epmf_init(unit, &module_data->submodules[dnx_data_field_submodule_base_epmf]));
    SHR_IF_ERR_EXIT(dnx_data_field_base_ifwd2_init(unit, &module_data->submodules[dnx_data_field_submodule_base_ifwd2]));
    SHR_IF_ERR_EXIT(dnx_data_field_stage_init(unit, &module_data->submodules[dnx_data_field_submodule_stage]));
    SHR_IF_ERR_EXIT(dnx_data_field_external_tcam_init(unit, &module_data->submodules[dnx_data_field_submodule_external_tcam]));
    SHR_IF_ERR_EXIT(dnx_data_field_tcam_init(unit, &module_data->submodules[dnx_data_field_submodule_tcam]));
    SHR_IF_ERR_EXIT(dnx_data_field_group_init(unit, &module_data->submodules[dnx_data_field_submodule_group]));
    SHR_IF_ERR_EXIT(dnx_data_field_efes_init(unit, &module_data->submodules[dnx_data_field_submodule_efes]));
    SHR_IF_ERR_EXIT(dnx_data_field_fem_init(unit, &module_data->submodules[dnx_data_field_submodule_fem]));
    SHR_IF_ERR_EXIT(dnx_data_field_context_init(unit, &module_data->submodules[dnx_data_field_submodule_context]));
    SHR_IF_ERR_EXIT(dnx_data_field_preselector_init(unit, &module_data->submodules[dnx_data_field_submodule_preselector]));
    SHR_IF_ERR_EXIT(dnx_data_field_qual_init(unit, &module_data->submodules[dnx_data_field_submodule_qual]));
    SHR_IF_ERR_EXIT(dnx_data_field_action_init(unit, &module_data->submodules[dnx_data_field_submodule_action]));
    SHR_IF_ERR_EXIT(dnx_data_field_virtual_wire_init(unit, &module_data->submodules[dnx_data_field_submodule_virtual_wire]));
    SHR_IF_ERR_EXIT(dnx_data_field_profile_bits_init(unit, &module_data->submodules[dnx_data_field_submodule_profile_bits]));
    SHR_IF_ERR_EXIT(dnx_data_field_dir_ext_init(unit, &module_data->submodules[dnx_data_field_submodule_dir_ext]));
    SHR_IF_ERR_EXIT(dnx_data_field_state_table_init(unit, &module_data->submodules[dnx_data_field_submodule_state_table]));
    SHR_IF_ERR_EXIT(dnx_data_field_sce_init(unit, &module_data->submodules[dnx_data_field_submodule_sce]));
    SHR_IF_ERR_EXIT(dnx_data_field_mdb_dt_init(unit, &module_data->submodules[dnx_data_field_submodule_mdb_dt]));
    SHR_IF_ERR_EXIT(dnx_data_field_hash_init(unit, &module_data->submodules[dnx_data_field_submodule_hash]));
    SHR_IF_ERR_EXIT(dnx_data_field_udh_init(unit, &module_data->submodules[dnx_data_field_submodule_udh]));
    SHR_IF_ERR_EXIT(dnx_data_field_system_headers_init(unit, &module_data->submodules[dnx_data_field_submodule_system_headers]));
    SHR_IF_ERR_EXIT(dnx_data_field_exem_init(unit, &module_data->submodules[dnx_data_field_submodule_exem]));
    SHR_IF_ERR_EXIT(dnx_data_field_exem_learn_flush_machine_init(unit, &module_data->submodules[dnx_data_field_submodule_exem_learn_flush_machine]));
    SHR_IF_ERR_EXIT(dnx_data_field_ace_init(unit, &module_data->submodules[dnx_data_field_submodule_ace]));
    SHR_IF_ERR_EXIT(dnx_data_field_entry_init(unit, &module_data->submodules[dnx_data_field_submodule_entry]));
    SHR_IF_ERR_EXIT(dnx_data_field_L4_Ops_init(unit, &module_data->submodules[dnx_data_field_submodule_L4_Ops]));
    SHR_IF_ERR_EXIT(dnx_data_field_encoded_qual_actions_offset_init(unit, &module_data->submodules[dnx_data_field_submodule_encoded_qual_actions_offset]));
    SHR_IF_ERR_EXIT(dnx_data_field_compare_init(unit, &module_data->submodules[dnx_data_field_submodule_compare]));
    SHR_IF_ERR_EXIT(dnx_data_field_diag_init(unit, &module_data->submodules[dnx_data_field_submodule_diag]));
    SHR_IF_ERR_EXIT(dnx_data_field_general_data_qualifiers_init(unit, &module_data->submodules[dnx_data_field_submodule_general_data_qualifiers]));
    SHR_IF_ERR_EXIT(dnx_data_field_common_max_val_init(unit, &module_data->submodules[dnx_data_field_submodule_common_max_val]));
    SHR_IF_ERR_EXIT(dnx_data_field_init_init(unit, &module_data->submodules[dnx_data_field_submodule_init]));
    SHR_IF_ERR_EXIT(dnx_data_field_features_init(unit, &module_data->submodules[dnx_data_field_submodule_features]));
    SHR_IF_ERR_EXIT(dnx_data_field_signal_sizes_init(unit, &module_data->submodules[dnx_data_field_submodule_signal_sizes]));
    SHR_IF_ERR_EXIT(dnx_data_field_dnx_data_internal_init(unit, &module_data->submodules[dnx_data_field_submodule_dnx_data_internal]));
    SHR_IF_ERR_EXIT(dnx_data_field_tests_init(unit, &module_data->submodules[dnx_data_field_submodule_tests]));
    
#ifdef BCM_DNX2_SUPPORT

    if (dnxc_data_mgmt_is_jr2_a0(unit))
    {
        SHR_IF_ERR_EXIT(jr2_a0_data_field_attach(unit));
    }
    else

#endif 
#ifdef BCM_DNX2_SUPPORT

    if (dnxc_data_mgmt_is_jr2_b0(unit))
    {
        SHR_IF_ERR_EXIT(jr2_a0_data_field_attach(unit));
        SHR_IF_ERR_EXIT(jr2_b0_data_field_attach(unit));
    }
    else

#endif 
#ifdef BCM_DNX2_SUPPORT

    if (dnxc_data_mgmt_is_jr2_b1(unit))
    {
        SHR_IF_ERR_EXIT(jr2_a0_data_field_attach(unit));
        SHR_IF_ERR_EXIT(jr2_b0_data_field_attach(unit));
    }
    else

#endif 
#ifdef BCM_DNX2_SUPPORT

    if (dnxc_data_mgmt_is_j2c_a0(unit))
    {
        SHR_IF_ERR_EXIT(jr2_a0_data_field_attach(unit));
        SHR_IF_ERR_EXIT(j2c_a0_data_field_attach(unit));
    }
    else

#endif 
#ifdef BCM_DNX2_SUPPORT

    if (dnxc_data_mgmt_is_j2c_a1(unit))
    {
        SHR_IF_ERR_EXIT(jr2_a0_data_field_attach(unit));
        SHR_IF_ERR_EXIT(j2c_a0_data_field_attach(unit));
    }
    else

#endif 
#ifdef BCM_DNX2_SUPPORT

    if (dnxc_data_mgmt_is_q2a_a0(unit))
    {
        SHR_IF_ERR_EXIT(jr2_a0_data_field_attach(unit));
        SHR_IF_ERR_EXIT(q2a_a0_data_field_attach(unit));
    }
    else

#endif 
#ifdef BCM_DNX2_SUPPORT

    if (dnxc_data_mgmt_is_q2a_b0(unit))
    {
        SHR_IF_ERR_EXIT(jr2_a0_data_field_attach(unit));
        SHR_IF_ERR_EXIT(q2a_a0_data_field_attach(unit));
    }
    else

#endif 
#ifdef BCM_DNX2_SUPPORT

    if (dnxc_data_mgmt_is_q2a_b1(unit))
    {
        SHR_IF_ERR_EXIT(jr2_a0_data_field_attach(unit));
        SHR_IF_ERR_EXIT(q2a_a0_data_field_attach(unit));
    }
    else

#endif 
#ifdef BCM_DNX2_SUPPORT

    if (dnxc_data_mgmt_is_j2p_a0(unit))
    {
        SHR_IF_ERR_EXIT(jr2_a0_data_field_attach(unit));
        SHR_IF_ERR_EXIT(j2p_a0_data_field_attach(unit));
    }
    else

#endif 
#ifdef BCM_DNX2_SUPPORT

    if (dnxc_data_mgmt_is_j2p_a1(unit))
    {
        SHR_IF_ERR_EXIT(jr2_a0_data_field_attach(unit));
        SHR_IF_ERR_EXIT(j2p_a0_data_field_attach(unit));
    }
    else

#endif 
#ifdef BCM_DNX2_SUPPORT

    if (dnxc_data_mgmt_is_j2p_a2(unit))
    {
        SHR_IF_ERR_EXIT(jr2_a0_data_field_attach(unit));
        SHR_IF_ERR_EXIT(j2p_a0_data_field_attach(unit));
    }
    else

#endif 
#ifdef BCM_DNX2_SUPPORT

    if (dnxc_data_mgmt_is_j2x_a0(unit))
    {
        SHR_IF_ERR_EXIT(jr2_a0_data_field_attach(unit));
        SHR_IF_ERR_EXIT(j2x_a0_data_field_attach(unit));
    }
    else

#endif 
    {
        SHR_EXIT();
    }

exit:
    SHR_FUNC_EXIT;
}
#undef BSL_LOG_MODULE

