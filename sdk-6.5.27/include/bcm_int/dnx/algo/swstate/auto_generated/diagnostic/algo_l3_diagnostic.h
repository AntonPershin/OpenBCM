/** \file algo/swstate/auto_generated/diagnostic/algo_l3_diagnostic.h
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

#ifndef __DNX_ALGO_L3_DIAGNOSTIC_H__
#define __DNX_ALGO_L3_DIAGNOSTIC_H__

#include <soc/dnxc/swstate/dnx_sw_state_dump.h>
#include <soc/dnxc/swstate/dnx_sw_state_size.h>
#include <bcm_int/dnx/algo/swstate/auto_generated/types/algo_l3_types.h>
#include <bcm_int/dnx/algo/l3/source_address_table_allocation.h>
#include <bcm_int/dnx/algo/res_mngr/res_mngr.h>
#include <bcm_int/dnx/algo/res_mngr/res_mngr_internal.h>
#include <bcm_int/dnx/algo/template_mngr/template_mngr.h>
#include <bcm_int/dnx/algo/template_mngr/template_mngr_internal.h>
#include <bcm_int/dnx/l3/l3_ecmp.h>
#include <include/soc/dnx/dnx_data/auto_generated/dnx_data_l3.h>
#include <include/soc/dnx/dnx_data/auto_generated/dnx_data_max_l3.h>
#include <soc/dnxc/swstate/types/sw_state_bitmap.h>
#include <bcm_int/dnx/algo/swstate/auto_generated/types/algo_consistent_hashing_types.h>
#if defined(DNX_SW_STATE_DIAGNOSTIC)
typedef enum {
    ALGO_L3_DB_INFO,
    ALGO_L3_DB_SOURCE_ADDRESS_TABLE_ALLOCATION_INFO,
    ALGO_L3_DB_SOURCE_ADDRESS_TABLE_ALLOCATION_SOURCE_ADDRESS_TABLE_INFO,
    ALGO_L3_DB_FEC_ALLOC_INFO,
    ALGO_L3_DB_FEC_ALLOC_L3_FEC_RES_MNGR_INFO,
    ALGO_L3_DB_FEC_ALLOC_L3_FEC_RES_MNGR_FEC_RES_MANAGER_INFO,
    ALGO_L3_DB_EGR_POINTED_ALLOC_INFO,
    ALGO_L3_DB_EGR_POINTED_ALLOC_EGR_POINTED_RES_MANAGER_INFO,
    ALGO_L3_DB_ALGO_L3_TEMPLATES_INFO,
    ALGO_L3_DB_ALGO_L3_TEMPLATES_ECMP_CONSISTENT_MANAGER_INFO,
    ALGO_L3_DB_ALGO_L3_TEMPLATES_VRRP_VSI_TCAM_TABLE_INFO,
    ALGO_L3_DB_ALGO_L3_TEMPLATES_ECMP_PROFILE_HIER_TABLE_INFO,
    ALGO_L3_DB_ALGO_L3_TEMPLATES_VRRP_EXEM_TCAM_TABLE_INFO,
    ALGO_L3_DB_VRRP_EXEM_L2_STATION_ID_ALLOC_INFO,
    ALGO_L3_DB_VRRP_EXEM_L2_STATION_ID_ALLOC_RES_BITMAP_INFO,
    ALGO_L3_DB_VRRP_DB_INFO,
    ALGO_L3_DB_VRRP_DB_DATABASE_ENABLE_INFO,
    ALGO_L3_DB_RIF_ALLOC_INFO,
    ALGO_L3_DB_RIF_ALLOC_RIF_RES_MANAGER_INFO,
    ALGO_L3_DB_RIF_ALLOC_INTF_RIF_RES_MNGR_INFO,
    ALGO_L3_DB_TP_MODES_INFO,
    ALGO_L3_DB_TP_MODES_L3_ECMP_TUNNEL_PRIORITY_MODES_RES_MNGR_INFO,
    ALGO_L3_DB_VIP_ECMP_ALLOC_INFO,
    ALGO_L3_DB_VIP_ECMP_ALLOC_VIP_ECMP_RES_MANAGER_INFO,
    ALGO_L3_DB_FEC_DB_INFO_INFO,
    ALGO_L3_DB_FEC_DB_INFO_FEC_DB_INFO,
    ALGO_L3_DB_OUT_RIF_RESULT_TYPE_INFO_INFO,
    ALGO_L3_DB_MAC_COMPRESS_ID_ALLOC_INFO,
    ALGO_L3_DB_MAC_COMPRESS_ID_ALLOC_MAC_COMPRESS_ID_BITMAP_INFO,
    ALGO_L3_DB_IPV6_MSB32_COMPRESS_ID_ALLOC_INFO,
    ALGO_L3_DB_IPV6_MSB32_COMPRESS_ID_ALLOC_IPV6_MSB32_COMPRESS_ID_BITMAP_INFO,
    ALGO_L3_DB_MAC_COMPRESS_REF_INFO,
    ALGO_L3_DB_IPV6_MSB32_COMPRESS_REF_INFO,
    ALGO_L3_DB_INFO_NOF_ENTRIES
} sw_state_algo_l3_db_layout_e;


extern dnx_sw_state_diagnostic_info_t algo_l3_db_info[SOC_MAX_NUM_DEVICES][ALGO_L3_DB_INFO_NOF_ENTRIES];

extern const char* algo_l3_db_layout_str[ALGO_L3_DB_INFO_NOF_ENTRIES];
int algo_l3_db_dump(
    int unit, dnx_sw_state_dump_filters_t filters);

int algo_l3_db_source_address_table_allocation_dump(
    int unit, dnx_sw_state_dump_filters_t filters);

int algo_l3_db_source_address_table_allocation_source_address_table_dump(
    int unit, dnx_sw_state_dump_filters_t filters);

int algo_l3_db_fec_alloc_dump(
    int unit, dnx_sw_state_dump_filters_t filters);

int algo_l3_db_fec_alloc_l3_fec_res_mngr_dump(
    int unit, dnx_sw_state_dump_filters_t filters);

int algo_l3_db_fec_alloc_l3_fec_res_mngr_fec_res_manager_dump(
    int unit, int sub_resource_id, dnx_sw_state_dump_filters_t filters);

int algo_l3_db_egr_pointed_alloc_dump(
    int unit, dnx_sw_state_dump_filters_t filters);

int algo_l3_db_egr_pointed_alloc_egr_pointed_res_manager_dump(
    int unit, dnx_sw_state_dump_filters_t filters);

int algo_l3_db_algo_l3_templates_dump(
    int unit, dnx_sw_state_dump_filters_t filters);

int algo_l3_db_algo_l3_templates_ecmp_consistent_manager_dump(
    int unit, dnx_sw_state_dump_filters_t filters);

int algo_l3_db_algo_l3_templates_vrrp_vsi_tcam_table_dump(
    int unit, dnx_sw_state_dump_filters_t filters);

int algo_l3_db_algo_l3_templates_ecmp_profile_hier_table_dump(
    int unit, int ecmp_profile_hier_table_idx_0, dnx_sw_state_dump_filters_t filters);

int algo_l3_db_algo_l3_templates_vrrp_exem_tcam_table_dump(
    int unit, dnx_sw_state_dump_filters_t filters);

int algo_l3_db_vrrp_exem_l2_station_id_alloc_dump(
    int unit, dnx_sw_state_dump_filters_t filters);

int algo_l3_db_vrrp_exem_l2_station_id_alloc_res_bitmap_dump(
    int unit, dnx_sw_state_dump_filters_t filters);

int algo_l3_db_vrrp_db_dump(
    int unit, dnx_sw_state_dump_filters_t filters);

int algo_l3_db_vrrp_db_database_enable_dump(
    int unit, int database_enable_idx_0, dnx_sw_state_dump_filters_t filters);

int algo_l3_db_rif_alloc_dump(
    int unit, dnx_sw_state_dump_filters_t filters);

int algo_l3_db_rif_alloc_rif_res_manager_dump(
    int unit, dnx_sw_state_dump_filters_t filters);

int algo_l3_db_rif_alloc_intf_rif_res_mngr_dump(
    int unit, dnx_sw_state_dump_filters_t filters);

int algo_l3_db_tp_modes_dump(
    int unit, int tp_modes_idx_0, dnx_sw_state_dump_filters_t filters);

int algo_l3_db_tp_modes_l3_ecmp_tunnel_priority_modes_res_mngr_dump(
    int unit, int tp_modes_idx_0, dnx_sw_state_dump_filters_t filters);

int algo_l3_db_vip_ecmp_alloc_dump(
    int unit, dnx_sw_state_dump_filters_t filters);

int algo_l3_db_vip_ecmp_alloc_vip_ecmp_res_manager_dump(
    int unit, dnx_sw_state_dump_filters_t filters);

int algo_l3_db_fec_db_info_dump(
    int unit, dnx_sw_state_dump_filters_t filters);

int algo_l3_db_fec_db_info_fec_db_dump(
    int unit, int direction, int hierarhy, dnx_sw_state_dump_filters_t filters);

int algo_l3_db_out_rif_result_type_info_dump(
    int unit, int out_rif_result_type_info_idx_0, dnx_sw_state_dump_filters_t filters);

int algo_l3_db_mac_compress_id_alloc_dump(
    int unit, dnx_sw_state_dump_filters_t filters);

int algo_l3_db_mac_compress_id_alloc_mac_compress_id_bitmap_dump(
    int unit, int mac_compress_id_bitmap_idx_0, dnx_sw_state_dump_filters_t filters);

int algo_l3_db_ipv6_msb32_compress_id_alloc_dump(
    int unit, dnx_sw_state_dump_filters_t filters);

int algo_l3_db_ipv6_msb32_compress_id_alloc_ipv6_msb32_compress_id_bitmap_dump(
    int unit, int ipv6_msb32_compress_id_bitmap_idx_0, dnx_sw_state_dump_filters_t filters);

int algo_l3_db_mac_compress_ref_dump(
    int unit, int mac_compress_ref_idx_0, dnx_sw_state_dump_filters_t filters);

int algo_l3_db_ipv6_msb32_compress_ref_dump(
    int unit, int ipv6_msb32_compress_ref_idx_0, dnx_sw_state_dump_filters_t filters);

#endif /* DNX_SW_STATE_DIAGNOSTIC */

#endif /* __DNX_ALGO_L3_DIAGNOSTIC_H__ */
