/** \file dnx/swstate/auto_generated/diagnostic/dnx_algo_field_commandline.h
 *
 * sw state functions declarations
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

#ifndef __DNX_ALGO_FIELD_COMMANDLINE_H__
#define __DNX_ALGO_FIELD_COMMANDLINE_H__

#include <appl/diag/sand/diag_sand_framework.h>
#include <appl/diag/sand/diag_sand_utils.h>
#include <soc/dnxc/swstate/dnxc_sw_state_h_includes.h>
#include <soc/dnxc/swstate/dnx_sw_state_dump.h>
#include <bcm_int/dnx/algo/swstate/auto_generated/types/dnx_algo_field_types.h>
#include <bcm_int/dnx/algo/field/algo_field.h>
#include <bcm_int/dnx/algo/res_mngr/res_mngr.h>
#include <bcm_int/dnx/algo/res_mngr/res_mngr_internal.h>
#include <soc/dnx/swstate/auto_generated/types/dnx_field_types.h>
#include <soc/dnx/swstate/auto_generated/types/dnx_field_key_types.h>
#include <soc/dnx/swstate/auto_generated/types/dnx_field_actions_types.h>
#if defined(DNX_SW_STATE_DIAGNOSTIC)
shr_error_e sh_dnx_swstate_dnx_algo_field_dump_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_algo_field_dump_options[];
extern sh_sand_man_t dnx_swstate_dnx_algo_field_dump_man;
shr_error_e sh_dnx_swstate_dnx_algo_field_size_get_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_algo_field_size_get_options[];
extern sh_sand_man_t dnx_swstate_dnx_algo_field_size_get_man;
extern sh_sand_cmd_t sh_dnx_swstate_dnx_algo_field_cmds[];
extern sh_sand_man_t dnx_swstate_dnx_algo_field_man;
extern const char cmd_dnx_swstate_dnx_algo_field_desc[];

extern sh_sand_cmd_t sh_dnx_swstate_dnx_algo_field_key_algo_cmds[];
extern sh_sand_man_t dnx_swstate_dnx_algo_field_key_algo_man;
extern const char cmd_dnx_swstate_dnx_algo_field_key_algo_desc[];
shr_error_e sh_dnx_swstate_dnx_algo_field_key_algo_dump_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_algo_field_key_algo_dump_options[];
extern sh_sand_man_t dnx_swstate_dnx_algo_field_key_algo_dump_man;


shr_error_e sh_dnx_swstate_dnx_algo_field_key_algo_size_get_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_algo_field_key_algo_size_get_options[];
extern sh_sand_man_t dnx_swstate_dnx_algo_field_key_algo_size_get_man;



extern sh_sand_cmd_t sh_dnx_swstate_dnx_algo_field_key_algo_dummy_cmds[];
extern sh_sand_man_t dnx_swstate_dnx_algo_field_key_algo_dummy_man;
extern const char cmd_dnx_swstate_dnx_algo_field_key_algo_dummy_desc[];
shr_error_e sh_dnx_swstate_dnx_algo_field_key_algo_dummy_dump_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_algo_field_key_algo_dummy_dump_options[];
extern sh_sand_man_t dnx_swstate_dnx_algo_field_key_algo_dummy_dump_man;


shr_error_e sh_dnx_swstate_dnx_algo_field_key_algo_dummy_size_get_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_algo_field_key_algo_dummy_size_get_options[];
extern sh_sand_man_t dnx_swstate_dnx_algo_field_key_algo_dummy_size_get_man;



extern sh_sand_cmd_t sh_dnx_swstate_dnx_algo_field_ipmf_1_ffc_cmds[];
extern sh_sand_man_t dnx_swstate_dnx_algo_field_ipmf_1_ffc_man;
extern const char cmd_dnx_swstate_dnx_algo_field_ipmf_1_ffc_desc[];
shr_error_e sh_dnx_swstate_dnx_algo_field_ipmf_1_ffc_dump_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_algo_field_ipmf_1_ffc_dump_options[];
extern sh_sand_man_t dnx_swstate_dnx_algo_field_ipmf_1_ffc_dump_man;


shr_error_e sh_dnx_swstate_dnx_algo_field_ipmf_1_ffc_size_get_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_algo_field_ipmf_1_ffc_size_get_options[];
extern sh_sand_man_t dnx_swstate_dnx_algo_field_ipmf_1_ffc_size_get_man;



extern sh_sand_cmd_t sh_dnx_swstate_dnx_algo_field_ipmf_2_ffc_cmds[];
extern sh_sand_man_t dnx_swstate_dnx_algo_field_ipmf_2_ffc_man;
extern const char cmd_dnx_swstate_dnx_algo_field_ipmf_2_ffc_desc[];
shr_error_e sh_dnx_swstate_dnx_algo_field_ipmf_2_ffc_dump_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_algo_field_ipmf_2_ffc_dump_options[];
extern sh_sand_man_t dnx_swstate_dnx_algo_field_ipmf_2_ffc_dump_man;


shr_error_e sh_dnx_swstate_dnx_algo_field_ipmf_2_ffc_size_get_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_algo_field_ipmf_2_ffc_size_get_options[];
extern sh_sand_man_t dnx_swstate_dnx_algo_field_ipmf_2_ffc_size_get_man;



extern sh_sand_cmd_t sh_dnx_swstate_dnx_algo_field_ipmf_3_ffc_cmds[];
extern sh_sand_man_t dnx_swstate_dnx_algo_field_ipmf_3_ffc_man;
extern const char cmd_dnx_swstate_dnx_algo_field_ipmf_3_ffc_desc[];
shr_error_e sh_dnx_swstate_dnx_algo_field_ipmf_3_ffc_dump_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_algo_field_ipmf_3_ffc_dump_options[];
extern sh_sand_man_t dnx_swstate_dnx_algo_field_ipmf_3_ffc_dump_man;


shr_error_e sh_dnx_swstate_dnx_algo_field_ipmf_3_ffc_size_get_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_algo_field_ipmf_3_ffc_size_get_options[];
extern sh_sand_man_t dnx_swstate_dnx_algo_field_ipmf_3_ffc_size_get_man;



extern sh_sand_cmd_t sh_dnx_swstate_dnx_algo_field_epmf_ffc_cmds[];
extern sh_sand_man_t dnx_swstate_dnx_algo_field_epmf_ffc_man;
extern const char cmd_dnx_swstate_dnx_algo_field_epmf_ffc_desc[];
shr_error_e sh_dnx_swstate_dnx_algo_field_epmf_ffc_dump_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_algo_field_epmf_ffc_dump_options[];
extern sh_sand_man_t dnx_swstate_dnx_algo_field_epmf_ffc_dump_man;


shr_error_e sh_dnx_swstate_dnx_algo_field_epmf_ffc_size_get_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_algo_field_epmf_ffc_size_get_options[];
extern sh_sand_man_t dnx_swstate_dnx_algo_field_epmf_ffc_size_get_man;



extern sh_sand_cmd_t sh_dnx_swstate_dnx_algo_field_ifwd2_ffc_cmds[];
extern sh_sand_man_t dnx_swstate_dnx_algo_field_ifwd2_ffc_man;
extern const char cmd_dnx_swstate_dnx_algo_field_ifwd2_ffc_desc[];
shr_error_e sh_dnx_swstate_dnx_algo_field_ifwd2_ffc_dump_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_algo_field_ifwd2_ffc_dump_options[];
extern sh_sand_man_t dnx_swstate_dnx_algo_field_ifwd2_ffc_dump_man;


shr_error_e sh_dnx_swstate_dnx_algo_field_ifwd2_ffc_size_get_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_algo_field_ifwd2_ffc_size_get_options[];
extern sh_sand_man_t dnx_swstate_dnx_algo_field_ifwd2_ffc_size_get_man;



extern sh_sand_cmd_t sh_dnx_swstate_dnx_algo_field_ipmf1_initial_key_occ_bmp_cmds[];
extern sh_sand_man_t dnx_swstate_dnx_algo_field_ipmf1_initial_key_occ_bmp_man;
extern const char cmd_dnx_swstate_dnx_algo_field_ipmf1_initial_key_occ_bmp_desc[];
shr_error_e sh_dnx_swstate_dnx_algo_field_ipmf1_initial_key_occ_bmp_dump_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_algo_field_ipmf1_initial_key_occ_bmp_dump_options[];
extern sh_sand_man_t dnx_swstate_dnx_algo_field_ipmf1_initial_key_occ_bmp_dump_man;


shr_error_e sh_dnx_swstate_dnx_algo_field_ipmf1_initial_key_occ_bmp_size_get_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_algo_field_ipmf1_initial_key_occ_bmp_size_get_options[];
extern sh_sand_man_t dnx_swstate_dnx_algo_field_ipmf1_initial_key_occ_bmp_size_get_man;



extern sh_sand_cmd_t sh_dnx_swstate_dnx_algo_field_ipmf1_key_occ_bmp_cmds[];
extern sh_sand_man_t dnx_swstate_dnx_algo_field_ipmf1_key_occ_bmp_man;
extern const char cmd_dnx_swstate_dnx_algo_field_ipmf1_key_occ_bmp_desc[];
shr_error_e sh_dnx_swstate_dnx_algo_field_ipmf1_key_occ_bmp_dump_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_algo_field_ipmf1_key_occ_bmp_dump_options[];
extern sh_sand_man_t dnx_swstate_dnx_algo_field_ipmf1_key_occ_bmp_dump_man;


shr_error_e sh_dnx_swstate_dnx_algo_field_ipmf1_key_occ_bmp_size_get_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_algo_field_ipmf1_key_occ_bmp_size_get_options[];
extern sh_sand_man_t dnx_swstate_dnx_algo_field_ipmf1_key_occ_bmp_size_get_man;



extern sh_sand_cmd_t sh_dnx_swstate_dnx_algo_field_ipmf2_key_occ_bmp_cmds[];
extern sh_sand_man_t dnx_swstate_dnx_algo_field_ipmf2_key_occ_bmp_man;
extern const char cmd_dnx_swstate_dnx_algo_field_ipmf2_key_occ_bmp_desc[];
shr_error_e sh_dnx_swstate_dnx_algo_field_ipmf2_key_occ_bmp_dump_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_algo_field_ipmf2_key_occ_bmp_dump_options[];
extern sh_sand_man_t dnx_swstate_dnx_algo_field_ipmf2_key_occ_bmp_dump_man;


shr_error_e sh_dnx_swstate_dnx_algo_field_ipmf2_key_occ_bmp_size_get_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_algo_field_ipmf2_key_occ_bmp_size_get_options[];
extern sh_sand_man_t dnx_swstate_dnx_algo_field_ipmf2_key_occ_bmp_size_get_man;



extern sh_sand_cmd_t sh_dnx_swstate_dnx_algo_field_ipmf3_key_occ_bmp_cmds[];
extern sh_sand_man_t dnx_swstate_dnx_algo_field_ipmf3_key_occ_bmp_man;
extern const char cmd_dnx_swstate_dnx_algo_field_ipmf3_key_occ_bmp_desc[];
shr_error_e sh_dnx_swstate_dnx_algo_field_ipmf3_key_occ_bmp_dump_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_algo_field_ipmf3_key_occ_bmp_dump_options[];
extern sh_sand_man_t dnx_swstate_dnx_algo_field_ipmf3_key_occ_bmp_dump_man;


shr_error_e sh_dnx_swstate_dnx_algo_field_ipmf3_key_occ_bmp_size_get_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_algo_field_ipmf3_key_occ_bmp_size_get_options[];
extern sh_sand_man_t dnx_swstate_dnx_algo_field_ipmf3_key_occ_bmp_size_get_man;



extern sh_sand_cmd_t sh_dnx_swstate_dnx_algo_field_epmf_key_occ_bmp_cmds[];
extern sh_sand_man_t dnx_swstate_dnx_algo_field_epmf_key_occ_bmp_man;
extern const char cmd_dnx_swstate_dnx_algo_field_epmf_key_occ_bmp_desc[];
shr_error_e sh_dnx_swstate_dnx_algo_field_epmf_key_occ_bmp_dump_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_algo_field_epmf_key_occ_bmp_dump_options[];
extern sh_sand_man_t dnx_swstate_dnx_algo_field_epmf_key_occ_bmp_dump_man;


shr_error_e sh_dnx_swstate_dnx_algo_field_epmf_key_occ_bmp_size_get_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_algo_field_epmf_key_occ_bmp_size_get_options[];
extern sh_sand_man_t dnx_swstate_dnx_algo_field_epmf_key_occ_bmp_size_get_man;



extern sh_sand_cmd_t sh_dnx_swstate_dnx_algo_field_key_lookup_occ_bmp_cmds[];
extern sh_sand_man_t dnx_swstate_dnx_algo_field_key_lookup_occ_bmp_man;
extern const char cmd_dnx_swstate_dnx_algo_field_key_lookup_occ_bmp_desc[];
shr_error_e sh_dnx_swstate_dnx_algo_field_key_lookup_occ_bmp_dump_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_algo_field_key_lookup_occ_bmp_dump_options[];
extern sh_sand_man_t dnx_swstate_dnx_algo_field_key_lookup_occ_bmp_dump_man;


shr_error_e sh_dnx_swstate_dnx_algo_field_key_lookup_occ_bmp_size_get_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_algo_field_key_lookup_occ_bmp_size_get_options[];
extern sh_sand_man_t dnx_swstate_dnx_algo_field_key_lookup_occ_bmp_size_get_man;



extern sh_sand_cmd_t sh_dnx_swstate_dnx_algo_field_ipmf_a_fes_id_cmds[];
extern sh_sand_man_t dnx_swstate_dnx_algo_field_ipmf_a_fes_id_man;
extern const char cmd_dnx_swstate_dnx_algo_field_ipmf_a_fes_id_desc[];
shr_error_e sh_dnx_swstate_dnx_algo_field_ipmf_a_fes_id_dump_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_algo_field_ipmf_a_fes_id_dump_options[];
extern sh_sand_man_t dnx_swstate_dnx_algo_field_ipmf_a_fes_id_dump_man;


shr_error_e sh_dnx_swstate_dnx_algo_field_ipmf_a_fes_id_size_get_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_algo_field_ipmf_a_fes_id_size_get_options[];
extern sh_sand_man_t dnx_swstate_dnx_algo_field_ipmf_a_fes_id_size_get_man;



extern sh_sand_cmd_t sh_dnx_swstate_dnx_algo_field_ipmf_b_fes_id_cmds[];
extern sh_sand_man_t dnx_swstate_dnx_algo_field_ipmf_b_fes_id_man;
extern const char cmd_dnx_swstate_dnx_algo_field_ipmf_b_fes_id_desc[];
shr_error_e sh_dnx_swstate_dnx_algo_field_ipmf_b_fes_id_dump_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_algo_field_ipmf_b_fes_id_dump_options[];
extern sh_sand_man_t dnx_swstate_dnx_algo_field_ipmf_b_fes_id_dump_man;


shr_error_e sh_dnx_swstate_dnx_algo_field_ipmf_b_fes_id_size_get_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_algo_field_ipmf_b_fes_id_size_get_options[];
extern sh_sand_man_t dnx_swstate_dnx_algo_field_ipmf_b_fes_id_size_get_man;



extern sh_sand_cmd_t sh_dnx_swstate_dnx_algo_field_epmf_fes_id_cmds[];
extern sh_sand_man_t dnx_swstate_dnx_algo_field_epmf_fes_id_man;
extern const char cmd_dnx_swstate_dnx_algo_field_epmf_fes_id_desc[];
shr_error_e sh_dnx_swstate_dnx_algo_field_epmf_fes_id_dump_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_algo_field_epmf_fes_id_dump_options[];
extern sh_sand_man_t dnx_swstate_dnx_algo_field_epmf_fes_id_dump_man;


shr_error_e sh_dnx_swstate_dnx_algo_field_epmf_fes_id_size_get_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_algo_field_epmf_fes_id_size_get_options[];
extern sh_sand_man_t dnx_swstate_dnx_algo_field_epmf_fes_id_size_get_man;



extern sh_sand_cmd_t sh_dnx_swstate_dnx_algo_field_ipmf_a_fem_pgm_id_cmds[];
extern sh_sand_man_t dnx_swstate_dnx_algo_field_ipmf_a_fem_pgm_id_man;
extern const char cmd_dnx_swstate_dnx_algo_field_ipmf_a_fem_pgm_id_desc[];
shr_error_e sh_dnx_swstate_dnx_algo_field_ipmf_a_fem_pgm_id_dump_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_algo_field_ipmf_a_fem_pgm_id_dump_options[];
extern sh_sand_man_t dnx_swstate_dnx_algo_field_ipmf_a_fem_pgm_id_dump_man;


shr_error_e sh_dnx_swstate_dnx_algo_field_ipmf_a_fem_pgm_id_size_get_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_algo_field_ipmf_a_fem_pgm_id_size_get_options[];
extern sh_sand_man_t dnx_swstate_dnx_algo_field_ipmf_a_fem_pgm_id_size_get_man;



extern sh_sand_cmd_t sh_dnx_swstate_dnx_algo_field_ipmf_a_fem_map_index_cmds[];
extern sh_sand_man_t dnx_swstate_dnx_algo_field_ipmf_a_fem_map_index_man;
extern const char cmd_dnx_swstate_dnx_algo_field_ipmf_a_fem_map_index_desc[];
shr_error_e sh_dnx_swstate_dnx_algo_field_ipmf_a_fem_map_index_dump_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_algo_field_ipmf_a_fem_map_index_dump_options[];
extern sh_sand_man_t dnx_swstate_dnx_algo_field_ipmf_a_fem_map_index_dump_man;


shr_error_e sh_dnx_swstate_dnx_algo_field_ipmf_a_fem_map_index_size_get_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_algo_field_ipmf_a_fem_map_index_size_get_options[];
extern sh_sand_man_t dnx_swstate_dnx_algo_field_ipmf_a_fem_map_index_size_get_man;



extern sh_sand_cmd_t sh_dnx_swstate_dnx_algo_field_ipmf1_context_id_cmds[];
extern sh_sand_man_t dnx_swstate_dnx_algo_field_ipmf1_context_id_man;
extern const char cmd_dnx_swstate_dnx_algo_field_ipmf1_context_id_desc[];
shr_error_e sh_dnx_swstate_dnx_algo_field_ipmf1_context_id_dump_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_algo_field_ipmf1_context_id_dump_options[];
extern sh_sand_man_t dnx_swstate_dnx_algo_field_ipmf1_context_id_dump_man;


shr_error_e sh_dnx_swstate_dnx_algo_field_ipmf1_context_id_size_get_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_algo_field_ipmf1_context_id_size_get_options[];
extern sh_sand_man_t dnx_swstate_dnx_algo_field_ipmf1_context_id_size_get_man;



extern sh_sand_cmd_t sh_dnx_swstate_dnx_algo_field_ipmf2_context_id_cmds[];
extern sh_sand_man_t dnx_swstate_dnx_algo_field_ipmf2_context_id_man;
extern const char cmd_dnx_swstate_dnx_algo_field_ipmf2_context_id_desc[];
shr_error_e sh_dnx_swstate_dnx_algo_field_ipmf2_context_id_dump_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_algo_field_ipmf2_context_id_dump_options[];
extern sh_sand_man_t dnx_swstate_dnx_algo_field_ipmf2_context_id_dump_man;


shr_error_e sh_dnx_swstate_dnx_algo_field_ipmf2_context_id_size_get_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_algo_field_ipmf2_context_id_size_get_options[];
extern sh_sand_man_t dnx_swstate_dnx_algo_field_ipmf2_context_id_size_get_man;



extern sh_sand_cmd_t sh_dnx_swstate_dnx_algo_field_ipmf3_context_id_cmds[];
extern sh_sand_man_t dnx_swstate_dnx_algo_field_ipmf3_context_id_man;
extern const char cmd_dnx_swstate_dnx_algo_field_ipmf3_context_id_desc[];
shr_error_e sh_dnx_swstate_dnx_algo_field_ipmf3_context_id_dump_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_algo_field_ipmf3_context_id_dump_options[];
extern sh_sand_man_t dnx_swstate_dnx_algo_field_ipmf3_context_id_dump_man;


shr_error_e sh_dnx_swstate_dnx_algo_field_ipmf3_context_id_size_get_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_algo_field_ipmf3_context_id_size_get_options[];
extern sh_sand_man_t dnx_swstate_dnx_algo_field_ipmf3_context_id_size_get_man;



extern sh_sand_cmd_t sh_dnx_swstate_dnx_algo_field_epmf_context_id_cmds[];
extern sh_sand_man_t dnx_swstate_dnx_algo_field_epmf_context_id_man;
extern const char cmd_dnx_swstate_dnx_algo_field_epmf_context_id_desc[];
shr_error_e sh_dnx_swstate_dnx_algo_field_epmf_context_id_dump_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_algo_field_epmf_context_id_dump_options[];
extern sh_sand_man_t dnx_swstate_dnx_algo_field_epmf_context_id_dump_man;


shr_error_e sh_dnx_swstate_dnx_algo_field_epmf_context_id_size_get_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_algo_field_epmf_context_id_size_get_options[];
extern sh_sand_man_t dnx_swstate_dnx_algo_field_epmf_context_id_size_get_man;



extern sh_sand_cmd_t sh_dnx_swstate_dnx_algo_field_user_qual_id_cmds[];
extern sh_sand_man_t dnx_swstate_dnx_algo_field_user_qual_id_man;
extern const char cmd_dnx_swstate_dnx_algo_field_user_qual_id_desc[];
shr_error_e sh_dnx_swstate_dnx_algo_field_user_qual_id_dump_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_algo_field_user_qual_id_dump_options[];
extern sh_sand_man_t dnx_swstate_dnx_algo_field_user_qual_id_dump_man;


shr_error_e sh_dnx_swstate_dnx_algo_field_user_qual_id_size_get_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_algo_field_user_qual_id_size_get_options[];
extern sh_sand_man_t dnx_swstate_dnx_algo_field_user_qual_id_size_get_man;



extern sh_sand_cmd_t sh_dnx_swstate_dnx_algo_field_user_action_id_cmds[];
extern sh_sand_man_t dnx_swstate_dnx_algo_field_user_action_id_man;
extern const char cmd_dnx_swstate_dnx_algo_field_user_action_id_desc[];
shr_error_e sh_dnx_swstate_dnx_algo_field_user_action_id_dump_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_algo_field_user_action_id_dump_options[];
extern sh_sand_man_t dnx_swstate_dnx_algo_field_user_action_id_dump_man;


shr_error_e sh_dnx_swstate_dnx_algo_field_user_action_id_size_get_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_algo_field_user_action_id_size_get_options[];
extern sh_sand_man_t dnx_swstate_dnx_algo_field_user_action_id_size_get_man;



extern sh_sand_cmd_t sh_dnx_swstate_dnx_algo_field_field_group_id_cmds[];
extern sh_sand_man_t dnx_swstate_dnx_algo_field_field_group_id_man;
extern const char cmd_dnx_swstate_dnx_algo_field_field_group_id_desc[];
shr_error_e sh_dnx_swstate_dnx_algo_field_field_group_id_dump_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_algo_field_field_group_id_dump_options[];
extern sh_sand_man_t dnx_swstate_dnx_algo_field_field_group_id_dump_man;


shr_error_e sh_dnx_swstate_dnx_algo_field_field_group_id_size_get_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_algo_field_field_group_id_size_get_options[];
extern sh_sand_man_t dnx_swstate_dnx_algo_field_field_group_id_size_get_man;



extern sh_sand_cmd_t sh_dnx_swstate_dnx_algo_field_sexem_app_db_id_cmds[];
extern sh_sand_man_t dnx_swstate_dnx_algo_field_sexem_app_db_id_man;
extern const char cmd_dnx_swstate_dnx_algo_field_sexem_app_db_id_desc[];
shr_error_e sh_dnx_swstate_dnx_algo_field_sexem_app_db_id_dump_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_algo_field_sexem_app_db_id_dump_options[];
extern sh_sand_man_t dnx_swstate_dnx_algo_field_sexem_app_db_id_dump_man;


shr_error_e sh_dnx_swstate_dnx_algo_field_sexem_app_db_id_size_get_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_algo_field_sexem_app_db_id_size_get_options[];
extern sh_sand_man_t dnx_swstate_dnx_algo_field_sexem_app_db_id_size_get_man;



extern sh_sand_cmd_t sh_dnx_swstate_dnx_algo_field_lexem_app_db_id_cmds[];
extern sh_sand_man_t dnx_swstate_dnx_algo_field_lexem_app_db_id_man;
extern const char cmd_dnx_swstate_dnx_algo_field_lexem_app_db_id_desc[];
shr_error_e sh_dnx_swstate_dnx_algo_field_lexem_app_db_id_dump_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_algo_field_lexem_app_db_id_dump_options[];
extern sh_sand_man_t dnx_swstate_dnx_algo_field_lexem_app_db_id_dump_man;


shr_error_e sh_dnx_swstate_dnx_algo_field_lexem_app_db_id_size_get_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_algo_field_lexem_app_db_id_size_get_options[];
extern sh_sand_man_t dnx_swstate_dnx_algo_field_lexem_app_db_id_size_get_man;



extern sh_sand_cmd_t sh_dnx_swstate_dnx_algo_field_nexem2_app_db_id_cmds[];
extern sh_sand_man_t dnx_swstate_dnx_algo_field_nexem2_app_db_id_man;
extern const char cmd_dnx_swstate_dnx_algo_field_nexem2_app_db_id_desc[];
shr_error_e sh_dnx_swstate_dnx_algo_field_nexem2_app_db_id_dump_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_algo_field_nexem2_app_db_id_dump_options[];
extern sh_sand_man_t dnx_swstate_dnx_algo_field_nexem2_app_db_id_dump_man;


shr_error_e sh_dnx_swstate_dnx_algo_field_nexem2_app_db_id_size_get_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_algo_field_nexem2_app_db_id_size_get_options[];
extern sh_sand_man_t dnx_swstate_dnx_algo_field_nexem2_app_db_id_size_get_man;



extern sh_sand_cmd_t sh_dnx_swstate_dnx_algo_field_wexem1_app_db_id_cmds[];
extern sh_sand_man_t dnx_swstate_dnx_algo_field_wexem1_app_db_id_man;
extern const char cmd_dnx_swstate_dnx_algo_field_wexem1_app_db_id_desc[];
shr_error_e sh_dnx_swstate_dnx_algo_field_wexem1_app_db_id_dump_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_algo_field_wexem1_app_db_id_dump_options[];
extern sh_sand_man_t dnx_swstate_dnx_algo_field_wexem1_app_db_id_dump_man;


shr_error_e sh_dnx_swstate_dnx_algo_field_wexem1_app_db_id_size_get_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_algo_field_wexem1_app_db_id_size_get_options[];
extern sh_sand_man_t dnx_swstate_dnx_algo_field_wexem1_app_db_id_size_get_man;



extern sh_sand_cmd_t sh_dnx_swstate_dnx_algo_field_wexem2_app_db_id_cmds[];
extern sh_sand_man_t dnx_swstate_dnx_algo_field_wexem2_app_db_id_man;
extern const char cmd_dnx_swstate_dnx_algo_field_wexem2_app_db_id_desc[];
shr_error_e sh_dnx_swstate_dnx_algo_field_wexem2_app_db_id_dump_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_algo_field_wexem2_app_db_id_dump_options[];
extern sh_sand_man_t dnx_swstate_dnx_algo_field_wexem2_app_db_id_dump_man;


shr_error_e sh_dnx_swstate_dnx_algo_field_wexem2_app_db_id_size_get_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_algo_field_wexem2_app_db_id_size_get_options[];
extern sh_sand_man_t dnx_swstate_dnx_algo_field_wexem2_app_db_id_size_get_man;



extern sh_sand_cmd_t sh_dnx_swstate_dnx_algo_field_ace_id_cmds[];
extern sh_sand_man_t dnx_swstate_dnx_algo_field_ace_id_man;
extern const char cmd_dnx_swstate_dnx_algo_field_ace_id_desc[];
shr_error_e sh_dnx_swstate_dnx_algo_field_ace_id_dump_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_algo_field_ace_id_dump_options[];
extern sh_sand_man_t dnx_swstate_dnx_algo_field_ace_id_dump_man;


shr_error_e sh_dnx_swstate_dnx_algo_field_ace_id_size_get_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_algo_field_ace_id_size_get_options[];
extern sh_sand_man_t dnx_swstate_dnx_algo_field_ace_id_size_get_man;



extern sh_sand_cmd_t sh_dnx_swstate_dnx_algo_field_ace_key_cmds[];
extern sh_sand_man_t dnx_swstate_dnx_algo_field_ace_key_man;
extern const char cmd_dnx_swstate_dnx_algo_field_ace_key_desc[];
shr_error_e sh_dnx_swstate_dnx_algo_field_ace_key_dump_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_algo_field_ace_key_dump_options[];
extern sh_sand_man_t dnx_swstate_dnx_algo_field_ace_key_dump_man;


shr_error_e sh_dnx_swstate_dnx_algo_field_ace_key_size_get_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_algo_field_ace_key_size_get_options[];
extern sh_sand_man_t dnx_swstate_dnx_algo_field_ace_key_size_get_man;



extern sh_sand_cmd_t sh_dnx_swstate_dnx_algo_field_entry_tcam_access_id_cmds[];
extern sh_sand_man_t dnx_swstate_dnx_algo_field_entry_tcam_access_id_man;
extern const char cmd_dnx_swstate_dnx_algo_field_entry_tcam_access_id_desc[];
shr_error_e sh_dnx_swstate_dnx_algo_field_entry_tcam_access_id_dump_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_algo_field_entry_tcam_access_id_dump_options[];
extern sh_sand_man_t dnx_swstate_dnx_algo_field_entry_tcam_access_id_dump_man;


shr_error_e sh_dnx_swstate_dnx_algo_field_entry_tcam_access_id_size_get_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_algo_field_entry_tcam_access_id_size_get_options[];
extern sh_sand_man_t dnx_swstate_dnx_algo_field_entry_tcam_access_id_size_get_man;



extern sh_sand_cmd_t sh_dnx_swstate_dnx_algo_field_link_profiles_cmds[];
extern sh_sand_man_t dnx_swstate_dnx_algo_field_link_profiles_man;
extern const char cmd_dnx_swstate_dnx_algo_field_link_profiles_desc[];
shr_error_e sh_dnx_swstate_dnx_algo_field_link_profiles_dump_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_algo_field_link_profiles_dump_options[];
extern sh_sand_man_t dnx_swstate_dnx_algo_field_link_profiles_dump_man;


shr_error_e sh_dnx_swstate_dnx_algo_field_link_profiles_size_get_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_algo_field_link_profiles_size_get_options[];
extern sh_sand_man_t dnx_swstate_dnx_algo_field_link_profiles_size_get_man;



extern sh_sand_cmd_t sh_dnx_swstate_dnx_algo_field_external_tcam_opcode_cs_profile_id_cmds[];
extern sh_sand_man_t dnx_swstate_dnx_algo_field_external_tcam_opcode_cs_profile_id_man;
extern const char cmd_dnx_swstate_dnx_algo_field_external_tcam_opcode_cs_profile_id_desc[];
shr_error_e sh_dnx_swstate_dnx_algo_field_external_tcam_opcode_cs_profile_id_dump_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_algo_field_external_tcam_opcode_cs_profile_id_dump_options[];
extern sh_sand_man_t dnx_swstate_dnx_algo_field_external_tcam_opcode_cs_profile_id_dump_man;


shr_error_e sh_dnx_swstate_dnx_algo_field_external_tcam_opcode_cs_profile_id_size_get_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_algo_field_external_tcam_opcode_cs_profile_id_size_get_options[];
extern sh_sand_man_t dnx_swstate_dnx_algo_field_external_tcam_opcode_cs_profile_id_size_get_man;



extern sh_sand_cmd_t sh_dnx_swstate_dnx_algo_field_ipmf1_contexts_link_cmds[];
extern sh_sand_man_t dnx_swstate_dnx_algo_field_ipmf1_contexts_link_man;
extern const char cmd_dnx_swstate_dnx_algo_field_ipmf1_contexts_link_desc[];
shr_error_e sh_dnx_swstate_dnx_algo_field_ipmf1_contexts_link_dump_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_algo_field_ipmf1_contexts_link_dump_options[];
extern sh_sand_man_t dnx_swstate_dnx_algo_field_ipmf1_contexts_link_dump_man;


shr_error_e sh_dnx_swstate_dnx_algo_field_ipmf1_contexts_link_size_get_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_algo_field_ipmf1_contexts_link_size_get_options[];
extern sh_sand_man_t dnx_swstate_dnx_algo_field_ipmf1_contexts_link_size_get_man;



extern sh_sand_cmd_t sh_dnx_swstate_dnx_algo_field_ipmf1_contexts_link_profile_num_cmds[];
extern sh_sand_man_t dnx_swstate_dnx_algo_field_ipmf1_contexts_link_profile_num_man;
extern const char cmd_dnx_swstate_dnx_algo_field_ipmf1_contexts_link_profile_num_desc[];
shr_error_e sh_dnx_swstate_dnx_algo_field_ipmf1_contexts_link_profile_num_dump_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_algo_field_ipmf1_contexts_link_profile_num_dump_options[];
extern sh_sand_man_t dnx_swstate_dnx_algo_field_ipmf1_contexts_link_profile_num_dump_man;


shr_error_e sh_dnx_swstate_dnx_algo_field_ipmf1_contexts_link_profile_num_size_get_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_algo_field_ipmf1_contexts_link_profile_num_size_get_options[];
extern sh_sand_man_t dnx_swstate_dnx_algo_field_ipmf1_contexts_link_profile_num_size_get_man;



extern sh_sand_cmd_t sh_dnx_swstate_dnx_algo_field_ipmf1_contexts_link_nof_linked_cmds[];
extern sh_sand_man_t dnx_swstate_dnx_algo_field_ipmf1_contexts_link_nof_linked_man;
extern const char cmd_dnx_swstate_dnx_algo_field_ipmf1_contexts_link_nof_linked_desc[];
shr_error_e sh_dnx_swstate_dnx_algo_field_ipmf1_contexts_link_nof_linked_dump_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_algo_field_ipmf1_contexts_link_nof_linked_dump_options[];
extern sh_sand_man_t dnx_swstate_dnx_algo_field_ipmf1_contexts_link_nof_linked_dump_man;


shr_error_e sh_dnx_swstate_dnx_algo_field_ipmf1_contexts_link_nof_linked_size_get_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_algo_field_ipmf1_contexts_link_nof_linked_size_get_options[];
extern sh_sand_man_t dnx_swstate_dnx_algo_field_ipmf1_contexts_link_nof_linked_size_get_man;



extern sh_sand_cmd_t sh_dnx_swstate_dnx_algo_field_user_apptype_id_cmds[];
extern sh_sand_man_t dnx_swstate_dnx_algo_field_user_apptype_id_man;
extern const char cmd_dnx_swstate_dnx_algo_field_user_apptype_id_desc[];
shr_error_e sh_dnx_swstate_dnx_algo_field_user_apptype_id_dump_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_algo_field_user_apptype_id_dump_options[];
extern sh_sand_man_t dnx_swstate_dnx_algo_field_user_apptype_id_dump_man;


shr_error_e sh_dnx_swstate_dnx_algo_field_user_apptype_id_size_get_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_algo_field_user_apptype_id_size_get_options[];
extern sh_sand_man_t dnx_swstate_dnx_algo_field_user_apptype_id_size_get_man;



extern sh_sand_cmd_t sh_dnx_swstate_dnx_algo_field_flush_profile_id_cmds[];
extern sh_sand_man_t dnx_swstate_dnx_algo_field_flush_profile_id_man;
extern const char cmd_dnx_swstate_dnx_algo_field_flush_profile_id_desc[];
shr_error_e sh_dnx_swstate_dnx_algo_field_flush_profile_id_dump_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_algo_field_flush_profile_id_dump_options[];
extern sh_sand_man_t dnx_swstate_dnx_algo_field_flush_profile_id_dump_man;


shr_error_e sh_dnx_swstate_dnx_algo_field_flush_profile_id_size_get_cmd(int unit, args_t *args, sh_sand_control_t *sand_control);
extern sh_sand_option_t dnx_swstate_dnx_algo_field_flush_profile_id_size_get_options[];
extern sh_sand_man_t dnx_swstate_dnx_algo_field_flush_profile_id_size_get_man;


#endif /* DNX_SW_STATE_DIAGNOSTIC */

#endif /* __DNX_ALGO_FIELD_COMMANDLINE_H__ */
