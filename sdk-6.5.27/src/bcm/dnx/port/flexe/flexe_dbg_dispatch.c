
/*
 *         
 * 
 * 
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2022 Broadcom Inc. All rights reserved.
 *     
 * DO NOT EDIT THIS FILE!
 *
 */

#ifndef BCM_DNX_SUPPORT
#error "This file is for use by DNX family only!"
#endif /* BCM_DNX_SUPPORT */

#include <bcm_int/dnx/algo/swstate/auto_generated/access/dnx_algo_flexe_core_access.h>
#include <flexe_drv.h>
#include <bcm_int/dnx/port/flexe/flexe_core.h>
#include <bcm_int/dnx/port/flexe/flexe_core_dispatch.h>

#ifdef INCLUDE_FLEXE_DBG

#include <bcm_int/dnx/port/flexe/flexe_dbg.h>

#include <bcm_int/dnx/port/flexe/flexe_dbg.h>

const __flexe_core__dispatch__t__ flexe_core_flexe_dbg_driver = {

    flexe_dbg_init,
    flexe_dbg_deinit,
    flexe_dbg_sync,
    flexe_dbg_group_phy_add,
    flexe_dbg_group_phy_remove,
    flexe_dbg_client_add,
    flexe_dbg_client_delete,
    flexe_dbg_mac_client_add,
    flexe_dbg_mac_client_delete,
    flexe_dbg_sar_client_add,
    flexe_dbg_sar_client_delete,
    flexe_dbg_rateadpt_add,
    flexe_dbg_rateadpt_delete,
    NULL,       /* flexe_core_rateadpt_get */
    flexe_dbg_sar_channel_map_set,
    flexe_dbg_66b_switch_set,
    flexe_dbg_66b_switch_get,
    flexe_dbg_66b_switch_reverse_get,
    flexe_dbg_oh_logical_phy_id_set,
    flexe_dbg_oh_logical_phy_id_get,
    flexe_dbg_oh_group_id_set,
    flexe_dbg_oh_group_id_get,
    flexe_dbg_oh_client_id_set,
    flexe_dbg_oh_client_id_get,
    flexe_dbg_oh_cr_bit_set,
    flexe_dbg_oh_cr_bit_get,
    flexe_dbg_oh_ca_bit_set,
    flexe_dbg_oh_ca_bit_get,
    flexe_dbg_oh_c_bit_set,
    flexe_dbg_oh_c_bit_get,
    flexe_dbg_oh_sc_bit_set,
    flexe_dbg_oh_sc_bit_get,
    flexe_dbg_active_calendar_set,
    flexe_dbg_active_calendar_get,
    flexe_dbg_oh_alarm_status_get,
    flexe_dbg_oh_cal_mismatch_ts_get,
    flexe_dbg_oam_alarm_status_get,
    flexe_dbg_oam_base_period_set,
    flexe_dbg_oam_base_period_get,
    flexe_dbg_oam_base_insert_enable_set,
    flexe_dbg_oam_base_insert_enable_get,
    flexe_dbg_oam_bypass_enable_set,
    flexe_dbg_oam_bypass_enable_get,
    flexe_dbg_sar_oam_bypass_enable_set,
    flexe_dbg_sar_oam_bypass_enable_get,
    flexe_dbg_oam_local_fault_insert_set,
    flexe_dbg_oam_local_fault_insert_get,
    flexe_dbg_oam_remote_fault_insert_set,
    flexe_dbg_oam_remote_fault_insert_get,
    flexe_dbg_oam_rdi_insert_set,
    flexe_dbg_oam_rdi_insert_get,
    flexe_dbg_oam_sd_alm_block_num_set,
    flexe_dbg_oam_sd_alm_block_num_get,
    flexe_dbg_oam_sd_alm_trigger_thr_set,
    flexe_dbg_oam_sd_alm_trigger_thr_get,
    flexe_dbg_oam_sd_alm_clear_thr_set,
    flexe_dbg_oam_sd_alm_clear_thr_get,
    flexe_dbg_oam_sf_bip8_alm_block_num_set,
    flexe_dbg_oam_sf_bip8_alm_block_num_get,
    flexe_dbg_oam_sf_bip8_alm_trigger_thr_set,
    flexe_dbg_oam_sf_bip8_alm_trigger_thr_get,
    flexe_dbg_oam_sf_bip8_alm_clear_thr_set,
    flexe_dbg_oam_sf_bip8_alm_clear_thr_get,
    flexe_dbg_oam_sd_bei_alm_block_num_set,
    flexe_dbg_oam_sd_bei_alm_block_num_get,
    flexe_dbg_oam_sd_bei_alm_trigger_thr_set,
    flexe_dbg_oam_sd_bei_alm_trigger_thr_get,
    flexe_dbg_oam_sd_bei_alm_clear_thr_set,
    flexe_dbg_oam_sd_bei_alm_clear_thr_get,
    flexe_dbg_oam_sf_bei_alm_block_num_set,
    flexe_dbg_oam_sf_bei_alm_block_num_get,
    flexe_dbg_oam_sf_bei_alm_trigger_thr_set,
    flexe_dbg_oam_sf_bei_alm_trigger_thr_get,
    flexe_dbg_oam_sf_bei_alm_clear_thr_set,
    flexe_dbg_oam_sf_bei_alm_clear_thr_get,
    flexe_dbg_oam_bip8_counter_get,
    flexe_dbg_oam_bei_counter_get,
    flexe_dbg_oam_pkt_count_get,
    flexe_dbg_oam_base_pkt_count_get,
    flexe_dbg_phy_default_config_set,
    flexe_dbg_oam_alarm_collection_timer_step_set,
    flexe_dbg_oam_alarm_collection_timer_step_get,
    flexe_dbg_oam_alarm_collection_step_count_set,
    flexe_dbg_oam_alarm_collection_step_count_get,
    flexe_dbg_sar_cell_mode_set,
    flexe_dbg_sar_cell_mode_get,
    NULL,       /* flexe_core_sar_cell_mode_per_channel_set */
    flexe_dbg_busa_channel_map_set,
    flexe_dbg_client_local_fault_get,
    flexe_dbg_client_remote_fault_get,
    flexe_dbg_sar_client_local_fault_get,
    flexe_dbg_sar_client_remote_fault_get,
    flexe_dbg_1588_pkt_header_set,
    flexe_dbg_1588_pkt_header_get,
    flexe_dbg_oh_oam_pkt_mac_set,
    flexe_dbg_oh_oam_pkt_mac_get,
    flexe_dbg_bas_oam_to_ext_processor_set,
    flexe_dbg_bas_oam_to_ext_processor_get,
    flexe_dbg_ptp_2step_tx_info_get,
    flexe_dbg_sar_jitter_fifo_level_set,
    flexe_dbg_sar_jitter_fifo_level_get,
    flexe_dbg_oam_bas_bip_recal_enable_set,
    flexe_dbg_oam_bas_bip_recal_enable_get,
    flexe_dbg_oam_bas_period_mismatch_trigger_los_alarm_set,
    flexe_dbg_oam_bas_period_mismatch_trigger_los_alarm_get,
    flexe_dbg_deskew_alarm_trigger_lf_set,
    flexe_dbg_deskew_alarm_trigger_lf_get,
    flexe_dbg_sar_enable_set,
    flexe_dbg_sar_enable_get,
    NULL,       /* flexe_core_flr_rate_generator_divider_set */
    NULL,       /* flexe_core_flr_logical_to_serdes_lane_set */
    NULL,       /* flexe_core_mac_client_ghao_config_set */
    NULL,       /* flexe_core_sar_client_ghao_config_set */
    NULL,       /* flexe_core_schedule_calendar_switch */
    NULL,       /* flexe_core_flexe_client_ghao_cal_switch */
    NULL,       /* flexe_core_flexe_client_ghao_complete */
    NULL,       /* flexe_core_flexe_client_ghao_stop */
    NULL,       /* flexe_core_l1_eth_1588_enable_set */
    NULL,       /* flexe_core_stat_channel_config_set */
    NULL,       /* flexe_core_stat_mac_counter_get */
    NULL,       /* flexe_core_oam_timeslot_delete */
    NULL,       /* flexe_core_oam_timeslot_add */
    NULL,       /* flexe_core_register_get */
    NULL,       /* flexe_core_memory_get */
    NULL,       /* flexe_core_soft_reset */
};

#endif /* INCLUDE_FLEXE_DBG */
