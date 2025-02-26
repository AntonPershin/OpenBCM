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

#ifndef _BLACKHAWK7_L8P2_H__H_
#define _BLACKHAWK7_L8P2_H__H_

#include <phymod/phymod_definitions.h>
/*Initialize phymod module*/
int blackhawk7_l8p2_core_identify(const phymod_core_access_t* core, uint32_t core_id, uint32_t* is_identified);

/*Retrive core information*/
int blackhawk7_l8p2_core_info_get(const phymod_core_access_t* core, phymod_core_info_t* info);

/*Set\get lane mapping*/
int blackhawk7_l8p2_core_lane_map_set(const phymod_core_access_t* core, const phymod_lane_map_t* lane_map);
int blackhawk7_l8p2_core_lane_map_get(const phymod_core_access_t* core, phymod_lane_map_t* lane_map);

/*Reset Core*/
int blackhawk7_l8p2_core_reset_set(const phymod_core_access_t* core, phymod_reset_mode_t reset_mode, phymod_reset_direction_t direction);
int blackhawk7_l8p2_core_reset_get(const phymod_core_access_t* core, phymod_reset_mode_t reset_mode, phymod_reset_direction_t* direction);

/*Set\get firmware operation mode*/
int blackhawk7_l8p2_phy_firmware_lane_config_set(const phymod_phy_access_t* phy, phymod_firmware_lane_config_t fw_lane_config);
int blackhawk7_l8p2_phy_firmware_lane_config_get(const phymod_phy_access_t* phy, phymod_firmware_lane_config_t* fw_lane_config);

/* re-tune rx path*/
int blackhawk7_l8p2_phy_rx_restart(const phymod_phy_access_t* phy);

/*Set phy polarity*/
int blackhawk7_l8p2_phy_polarity_set(const phymod_phy_access_t* phy, const phymod_polarity_t* polarity);
int blackhawk7_l8p2_phy_polarity_get(const phymod_phy_access_t* phy, phymod_polarity_t* polarity);

/*Set\Get TX Parameters*/
int blackhawk7_l8p2_phy_tx_set(const phymod_phy_access_t* phy, const phymod_tx_t* tx);
int blackhawk7_l8p2_phy_tx_get(const phymod_phy_access_t* phy, phymod_tx_t* tx);

/*Request for default TX parameters configuration per media type*/
int blackhawk7_l8p2_phy_media_type_tx_get(const phymod_phy_access_t* phy, phymod_media_typed_t media, phymod_tx_t* tx);

/*Set\Get TX override Parameters*/
int blackhawk7_l8p2_phy_tx_override_set(const phymod_phy_access_t* phy, const phymod_tx_override_t* tx_override);
int blackhawk7_l8p2_phy_tx_override_get(const phymod_phy_access_t* phy, phymod_tx_override_t* tx_override);

/*Set\Get RX Parameters*/
int blackhawk7_l8p2_phy_rx_set(const phymod_phy_access_t* phy, const phymod_rx_t* rx);
int blackhawk7_l8p2_phy_rx_get(const phymod_phy_access_t* phy, phymod_rx_t* rx);

/*PHY Rx adaptation resume*/
int blackhawk7_l8p2_phy_rx_adaptation_resume(const phymod_phy_access_t* phy);

/*TX transmission control*/
int blackhawk7_l8p2_phy_tx_lane_control_set(const phymod_phy_access_t* phy, phymod_phy_tx_lane_control_t tx_control);
int blackhawk7_l8p2_phy_tx_lane_control_get(const phymod_phy_access_t* phy, phymod_phy_tx_lane_control_t* tx_control);

/*Rx control*/
int blackhawk7_l8p2_phy_rx_lane_control_set(const phymod_phy_access_t* phy, phymod_phy_rx_lane_control_t rx_control);
int blackhawk7_l8p2_phy_rx_lane_control_get(const phymod_phy_access_t* phy, phymod_phy_rx_lane_control_t* rx_control);

/*Set\Get CL72*/
int blackhawk7_l8p2_phy_cl72_set(const phymod_phy_access_t* phy, uint32_t cl72_en);
int blackhawk7_l8p2_phy_cl72_get(const phymod_phy_access_t* phy, uint32_t* cl72_en);

/*Get CL72 status*/
int blackhawk7_l8p2_phy_cl72_status_get(const phymod_phy_access_t* phy, phymod_cl72_status_t* status);

/*Core Initialization*/
int blackhawk7_l8p2_core_init(const phymod_core_access_t* core, const phymod_core_init_config_t* init_config, const phymod_core_status_t* core_status);

/*Core vco freq get function*/
int blackhawk7_l8p2_phy_pll_multiplier_get(const phymod_phy_access_t* phy, uint32_t* core_vco_pll_multiplier);

/*Phy Initialization*/
int blackhawk7_l8p2_phy_init(const phymod_phy_access_t* phy, const phymod_phy_init_config_t* init_config);

/*Set\get loopback mode*/
int blackhawk7_l8p2_phy_loopback_set(const phymod_phy_access_t* phy, phymod_loopback_mode_t loopback, uint32_t enable);
int blackhawk7_l8p2_phy_loopback_get(const phymod_phy_access_t* phy, phymod_loopback_mode_t loopback, uint32_t* enable);

/*Get rx pmd locked indication. This API will clear the pmd_lock_change indication.*/
int blackhawk7_l8p2_phy_rx_pmd_locked_get(const phymod_phy_access_t* phy, uint32_t* rx_pmd_locked);

/*Get Lane Bit Map of rx pmd lock and pmd lock change indication. */
int blackhawk7_l8p2_phy_rx_pmd_lock_status_get(const phymod_phy_access_t* phy, uint32_t* rx_pmd_locked, uint32_t* rx_pmd_lock_change);

/*Get rx pmd locked indication*/
int blackhawk7_l8p2_phy_rx_signal_detect_get(const phymod_phy_access_t* phy, uint32_t* rx_signal_detect);

/*Read phymod register*/
int blackhawk7_l8p2_phy_reg_read(const phymod_phy_access_t* phy, uint32_t reg_addr, uint32_t* val);

/*Write phymod register*/
int blackhawk7_l8p2_phy_reg_write(const phymod_phy_access_t* phy, uint32_t reg_addr, uint32_t val);

/*eye margin estimate get*/
int blackhawk7_l8p2_phy_eye_margin_est_get(const phymod_phy_access_t* phy, phymod_eye_margin_mode_t eye_margin_mode, uint32_t* value);

/*Set the interface mode, speed and other configuration related to interface.*/
int blackhawk7_l8p2_phy_speed_config_set(const phymod_phy_access_t* phy, const phymod_phy_speed_config_t* speed_config, const phymod_phy_pll_state_t* old_pll_state, phymod_phy_pll_state_t* new_pll_state);
int blackhawk7_l8p2_phy_speed_config_get(const phymod_phy_access_t* phy, phymod_phy_speed_config_t* speed_config);

/* get default tx taps*/
int blackhawk7_l8p2_phy_tx_taps_default_get(const phymod_phy_access_t* phy, phymod_phy_signalling_method_t mode, phymod_tx_t* tx);

/* get default tx taps*/
int blackhawk7_l8p2_phy_lane_config_default_get(const phymod_phy_access_t* phy, phymod_phy_signalling_method_t mode, phymod_firmware_lane_config_t* lane_config);

/* get PMD micro code and length*/
int blackhawk7_l8p2_phy_firmware_load_info_get(const phymod_phy_access_t* phy, phymod_firmware_load_info_t* info);

/* enable tx pam4 precoder for extended reach channel*/
int blackhawk7_l8p2_phy_tx_pam4_precoder_enable_set(const phymod_phy_access_t* phy, int enable);
int blackhawk7_l8p2_phy_tx_pam4_precoder_enable_get(const phymod_phy_access_t* phy, int* enable);

/* Power down PLL*/
int blackhawk7_l8p2_phy_pll_pwrdn(const phymod_phy_access_t* phy, uint32_t pll_index, uint32_t pwrdn);

/*Set/Get the channel loss hint for PAM4 speed */
int blackhawk7_l8p2_phy_channel_loss_hint_set(const phymod_phy_access_t* phy, uint32_t channel_loss);
int blackhawk7_l8p2_phy_channel_loss_hint_get(const phymod_phy_access_t* phy, uint32_t* channel_loss);

/* initialize the PMD info data structure */
int blackhawk7_l8p2_phy_pmd_info_init(const phymod_phy_access_t* phy);

#endif /*_BLACKHAWK7_L8P2_H_*/
