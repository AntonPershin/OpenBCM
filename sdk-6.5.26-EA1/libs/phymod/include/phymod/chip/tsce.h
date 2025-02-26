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

#ifndef _TSCE_H__H_
#define _TSCE_H__H_

#include <phymod/phymod_definitions.h>
/*Initialize phymod module*/
int tsce_core_identify(const phymod_core_access_t* core, uint32_t core_id, uint32_t* is_identified);

/*Retrive core information*/
int tsce_core_info_get(const phymod_core_access_t* core, phymod_core_info_t* info);

/*Set\get lane mapping*/
int tsce_core_lane_map_set(const phymod_core_access_t* core, const phymod_lane_map_t* lane_map);
int tsce_core_lane_map_get(const phymod_core_access_t* core, phymod_lane_map_t* lane_map);

/*Reset Core*/
int tsce_core_reset_set(const phymod_core_access_t* core, phymod_reset_mode_t reset_mode, phymod_reset_direction_t direction);
int tsce_core_reset_get(const phymod_core_access_t* core, phymod_reset_mode_t reset_mode, phymod_reset_direction_t* direction);

/*Retrive firmware information*/
int tsce_core_firmware_info_get(const phymod_core_access_t* core, phymod_core_firmware_info_t* fw_info);

/*Set\get firmware operation mode*/
int tsce_phy_firmware_core_config_set(const phymod_phy_access_t* phy, phymod_firmware_core_config_t fw_core_config);
int tsce_phy_firmware_core_config_get(const phymod_phy_access_t* phy, phymod_firmware_core_config_t* fw_core_config);

/*Set\get firmware operation mode*/
int tsce_phy_firmware_lane_config_set(const phymod_phy_access_t* phy, phymod_firmware_lane_config_t fw_lane_config);
int tsce_phy_firmware_lane_config_get(const phymod_phy_access_t* phy, phymod_firmware_lane_config_t* fw_lane_config);

/*Start\Stop the sequencer*/
int tsce_core_pll_sequencer_restart(const phymod_core_access_t* core, uint32_t flags, phymod_sequencer_operation_t operation);

/*Wait for core event*/
int tsce_core_wait_event(const phymod_core_access_t* core, phymod_core_event_t event, uint32_t timeout);

/* re-tune rx path*/
int tsce_phy_rx_restart(const phymod_phy_access_t* phy);

/*Set phy polarity*/
int tsce_phy_polarity_set(const phymod_phy_access_t* phy, const phymod_polarity_t* polarity);
int tsce_phy_polarity_get(const phymod_phy_access_t* phy, phymod_polarity_t* polarity);

/*Set\Get TX Parameters*/
int tsce_phy_tx_set(const phymod_phy_access_t* phy, const phymod_tx_t* tx);
int tsce_phy_tx_get(const phymod_phy_access_t* phy, phymod_tx_t* tx);

/*Set\Get TX override Parameters*/
int tsce_phy_tx_override_set(const phymod_phy_access_t* phy, const phymod_tx_override_t* tx_override);
int tsce_phy_tx_override_get(const phymod_phy_access_t* phy, phymod_tx_override_t* tx_override);

/*Set\Get RX Parameters*/
int tsce_phy_rx_set(const phymod_phy_access_t* phy, const phymod_rx_t* rx);
int tsce_phy_rx_get(const phymod_phy_access_t* phy, phymod_rx_t* rx);

/*PHY Rx adaptation resume*/
int tsce_phy_rx_adaptation_resume(const phymod_phy_access_t* phy);

/*Reset phy*/
int tsce_phy_reset_set(const phymod_phy_access_t* phy, const phymod_phy_reset_t* reset);
int tsce_phy_reset_get(const phymod_phy_access_t* phy, phymod_phy_reset_t* reset);

/*Control phy power*/
int tsce_phy_power_set(const phymod_phy_access_t* phy, const phymod_phy_power_t* power);
int tsce_phy_power_get(const phymod_phy_access_t* phy, phymod_phy_power_t* power);

/*Control phy hg2 codec*/
int tsce_phy_hg2_codec_control_set(const phymod_phy_access_t* phy, phymod_phy_hg2_codec_t hg2_codec);
int tsce_phy_hg2_codec_control_get(const phymod_phy_access_t* phy, phymod_phy_hg2_codec_t* hg2_codec);

/*TX transmission control*/
int tsce_phy_tx_lane_control_set(const phymod_phy_access_t* phy, phymod_phy_tx_lane_control_t tx_control);
int tsce_phy_tx_lane_control_get(const phymod_phy_access_t* phy, phymod_phy_tx_lane_control_t* tx_control);

/*Rx control*/
int tsce_phy_rx_lane_control_set(const phymod_phy_access_t* phy, phymod_phy_rx_lane_control_t rx_control);
int tsce_phy_rx_lane_control_get(const phymod_phy_access_t* phy, phymod_phy_rx_lane_control_t* rx_control);

/*forced speed FEC control*/
int tsce_phy_fec_enable_set(const phymod_phy_access_t* phy, uint32_t enable);
int tsce_phy_fec_enable_get(const phymod_phy_access_t* phy, uint32_t* enable);

/*Change OUI to consortium OUI*/
int tsce_phy_autoneg_oui_set(const phymod_phy_access_t* phy, phymod_autoneg_oui_t an_oui);
int tsce_phy_autoneg_oui_get(const phymod_phy_access_t* phy, phymod_autoneg_oui_t* an_oui);

/*energy efficient control*/
int tsce_phy_eee_set(const phymod_phy_access_t* phy, uint32_t enable);
int tsce_phy_eee_get(const phymod_phy_access_t* phy, uint32_t* enable);

/*Set the interface mode, speed and other configuration related to interface.*/
int tsce_phy_interface_config_set(const phymod_phy_access_t* phy, uint32_t flags, const phymod_phy_inf_config_t* config);
int tsce_phy_interface_config_get(const phymod_phy_access_t* phy, uint32_t flags, phymod_ref_clk_t ref_clock, phymod_phy_inf_config_t* config);

/*Set\Get CL72*/
int tsce_phy_cl72_set(const phymod_phy_access_t* phy, uint32_t cl72_en);
int tsce_phy_cl72_get(const phymod_phy_access_t* phy, uint32_t* cl72_en);

/*Get CL72 status*/
int tsce_phy_cl72_status_get(const phymod_phy_access_t* phy, phymod_cl72_status_t* status);

/*Set\Get autoneg*/
int tsce_phy_autoneg_ability_set(const phymod_phy_access_t* phy, const phymod_autoneg_ability_t* an_ability_set_type);
int tsce_phy_autoneg_ability_get(const phymod_phy_access_t* phy, phymod_autoneg_ability_t* an_ability_get_type);

/*Get  remote link autoneg*/
int tsce_phy_autoneg_remote_ability_get(const phymod_phy_access_t* phy, phymod_autoneg_ability_t* an_ability_get_type);

/*Set\Get autoneg*/
int tsce_phy_autoneg_set(const phymod_phy_access_t* phy, const phymod_autoneg_control_t* an);
int tsce_phy_autoneg_get(const phymod_phy_access_t* phy, phymod_autoneg_control_t* an, uint32_t* an_done);

/*Set\Get autoneg restart*/
int tsce_phy_autoneg_restart_set(const phymod_phy_access_t* phy, const phymod_autoneg_control_t* an);

/*Get Autoneg status*/
int tsce_phy_autoneg_status_get(const phymod_phy_access_t* phy, phymod_autoneg_status_t* status);

/*Core Initialization*/
int tsce_core_init(const phymod_core_access_t* core, const phymod_core_init_config_t* init_config, const phymod_core_status_t* core_status);

/*Core vco freq get function*/
int tsce_phy_pll_multiplier_get(const phymod_phy_access_t* phy, uint32_t* core_vco_pll_multiplier);

/*Phy Initialization*/
int tsce_phy_init(const phymod_phy_access_t* phy, const phymod_phy_init_config_t* init_config);

/*Set\get loopback mode*/
int tsce_phy_loopback_set(const phymod_phy_access_t* phy, phymod_loopback_mode_t loopback, uint32_t enable);
int tsce_phy_loopback_get(const phymod_phy_access_t* phy, phymod_loopback_mode_t loopback, uint32_t* enable);

/*Get rx pmd locked indication. This API will clear the pmd_lock_change indication.*/
int tsce_phy_rx_pmd_locked_get(const phymod_phy_access_t* phy, uint32_t* rx_pmd_locked);

/*Get rx pmd locked indication*/
int tsce_phy_rx_signal_detect_get(const phymod_phy_access_t* phy, uint32_t* rx_signal_detect);

/*Get link up status indication*/
int tsce_phy_link_status_get(const phymod_phy_access_t* phy, uint32_t* link_status);

/*Set/Get User Speed Paramateres*/
int tsce_phy_pcs_userspeed_set(const phymod_phy_access_t* phy, const phymod_pcs_userspeed_config_t* config);
int tsce_phy_pcs_userspeed_get(const phymod_phy_access_t* phy, phymod_pcs_userspeed_config_t* config);

/*Read phymod register*/
int tsce_phy_reg_read(const phymod_phy_access_t* phy, uint32_t reg_addr, uint32_t* val);

/*Write phymod register*/
int tsce_phy_reg_write(const phymod_phy_access_t* phy, uint32_t reg_addr, uint32_t val);

/*eye margin estimate get*/
int tsce_phy_eye_margin_est_get(const phymod_phy_access_t* phy, phymod_eye_margin_mode_t eye_margin_mode, uint32_t* value);

/* Set/Get synce clock config*/
int tsce_phy_synce_clk_ctrl_set(const phymod_phy_access_t* phy, phymod_synce_clk_ctrl_t cfg);
int tsce_phy_synce_clk_ctrl_get(const phymod_phy_access_t* phy, phymod_synce_clk_ctrl_t* cfg);

/*Get rx ppm*/
int tsce_phy_rx_ppm_get(const phymod_phy_access_t* phy, int16_t* rx_ppm);

/*Set or get the Master mode on SGMII.*/
int tsce_phy_master_set(const phymod_phy_access_t* phy, phymod_master_mode_t master_mode);
int tsce_phy_master_get(const phymod_phy_access_t* phy, phymod_master_mode_t* master_mode);

#endif /*_TSCE_H_*/
