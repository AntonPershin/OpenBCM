/** \file imb_feu.h
 *
 */

#ifndef _IMB_FEU_H__H_
#define _IMB_FEU_H__H_

#include <soc/portmod/portmod.h>
#include <bcm/port.h>
#include <bcm/cosq.h>
#include <bcm_int/dnx/port/imb/imb_diag.h>
#include <bcm_int/dnx/cosq/ingress/cosq_ingress_port.h>
#include <soc/dnxc/dnxc_port.h>
/*initialize an IMB.*/
int imb_feu_init(
    int unit,
    const imb_create_info_t * imb_info);

/*Add new IMB (Interface Management Block) port*/
int imb_feu_port_attach(
    int unit,
    bcm_port_t port,
    uint32 flags);

/*Remove an existing IMB (Interface Management Block) port*/
int imb_feu_port_detach(
    int unit,
    bcm_port_t port);

/*Enable / disable a port*/
int imb_feu_port_enable_set(
    int unit,
    bcm_port_t port,
    uint32 flags,
    int enable);

/*Set / get priority configuration for the port*/
int imb_feu_port_priority_config_set(
    int unit,
    bcm_port_t port,
    const bcm_port_prio_config_t * priority_config);
int imb_feu_port_priority_config_get(
    int unit,
    bcm_port_t port,
    bcm_port_prio_config_t * priority_config);

/*Set the Start TX threshold.*/
int imb_feu_port_tx_start_thr_set(
    int unit,
    bcm_port_t port,
    int speed,
    int start_tx_thr);
int imb_feu_port_tx_start_thr_get(
    int unit,
    bcm_port_t port,
    int *start_tx_thr);

/*Set/get the PRD Enable mode.*/
int imb_feu_prd_enable_set(
    int unit,
    bcm_port_t port,
    int enable_mode);
int imb_feu_prd_enable_get(
    int unit,
    bcm_port_t port,
    int *enable_mode);

/*Set/get PRD Properties.*/
int imb_feu_prd_properties_set(
    int unit,
    bcm_port_t port,
    imb_prd_properties_t property,
    uint32 val);
int imb_feu_prd_properties_get(
    int unit,
    bcm_port_t port,
    imb_prd_properties_t property,
    uint32 *val);

/*Set/get PRD Port Profile.*/
int imb_feu_prd_port_profile_map_set(
    int unit,
    bcm_port_t port,
    uint32 profile);
int imb_feu_prd_port_profile_map_get(
    int unit,
    bcm_port_t port,
    uint32 *profile);

/*Configure PRD priority maps.*/
int imb_feu_prd_map_set(
    int unit,
    bcm_port_t port,
    bcm_cosq_ingress_port_drop_map_t map,
    uint32 key,
    uint32 priority,
    uint32 is_tdm);
int imb_feu_prd_map_get(
    int unit,
    bcm_port_t port,
    bcm_cosq_ingress_port_drop_map_t map,
    uint32 key,
    uint32 *priority,
    uint32 *is_tdm);

/*Configure PRD thresholds.*/
int imb_feu_prd_threshold_set(
    int unit,
    bcm_port_t port,
    uint32 priority,
    uint32 threshold);
int imb_feu_prd_threshold_get(
    int unit,
    bcm_port_t port,
    uint32 priority,
    uint32 *threshold);

/*Get maximum PRD threshold value.*/
int imb_feu_prd_threshold_max_get(
    int unit,
    bcm_port_t port,
    uint32 *threshold);

/*Configure PRD TPIDs per port.*/
int imb_feu_prd_tpid_set(
    int unit,
    bcm_port_t port,
    uint32 tpid_index,
    uint32 tpid_value);
int imb_feu_prd_tpid_get(
    int unit,
    bcm_port_t port,
    uint32 tpid_index,
    uint32 *tpid_value);

/*Get PRD counter for the corresponding FIFO (RMC).*/
int imb_feu_prd_drop_count_get(
    int unit,
    bcm_port_t port,
    bcm_port_nif_scheduler_t sch_priority,
    uint64 *count);

/*Set/Get PRD Configurable Ether types.*/
int imb_feu_prd_custom_ether_type_set(
    int unit,
    bcm_port_t port,
    uint32 ether_type_code,
    uint32 ether_type_val);
int imb_feu_prd_custom_ether_type_get(
    int unit,
    bcm_port_t port,
    uint32 ether_type_code,
    uint32 *ether_type_val);

/*Set/Get PRD TCAM entries (for the soft stage).*/
int imb_feu_prd_flex_key_entry_set(
    int unit,
    bcm_port_t port,
    uint32 key_index,
    const dnx_cosq_prd_tcam_entry_info_t * entry_info);
int imb_feu_prd_flex_key_entry_get(
    int unit,
    bcm_port_t port,
    uint32 key_index,
    dnx_cosq_prd_tcam_entry_info_t * entry_info);

/*Set/Get PRD TCAM key size per Ether type (for the soft stage).*/
int imb_feu_prd_ether_type_size_set(
    int unit,
    bcm_port_t port,
    uint32 ether_type_code,
    uint32 ether_type_size);
int imb_feu_prd_ether_type_size_get(
    int unit,
    bcm_port_t port,
    uint32 ether_type_code,
    uint32 *ether_type_size);

/*Set/Get PRD TCAM key offset base per Ether type (for the soft stage).*/
int imb_feu_prd_tcam_entry_key_offset_base_set(
    int unit,
    bcm_port_t port,
    uint32 ether_type_code,
    uint32 offset_base);
int imb_feu_prd_tcam_entry_key_offset_base_get(
    int unit,
    bcm_port_t port,
    uint32 ether_type_code,
    uint32 *offset_base);

/*Set/Get PRD TCAM key offset value per Ether type (for the soft stage).*/
int imb_feu_prd_tcam_entry_key_offset_set(
    int unit,
    bcm_port_t port,
    uint32 ether_type_code,
    uint32 offset_index,
    uint32 offset_value);
int imb_feu_prd_tcam_entry_key_offset_get(
    int unit,
    bcm_port_t port,
    uint32 ether_type_code,
    uint32 offset_index,
    uint32 *offset_value);

/*Set/Get PRD Control Frame proeprties. if a packet is identified as control frame, it will automatically get the highest priority.*/
int imb_feu_prd_control_frame_set(
    int unit,
    bcm_port_t port,
    uint32 control_frame_index,
    const bcm_cosq_ingress_drop_control_frame_config_t * control_frame_config);
int imb_feu_prd_control_frame_get(
    int unit,
    bcm_port_t port,
    uint32 control_frame_index,
    bcm_cosq_ingress_drop_control_frame_config_t * control_frame_config);

/*Set/Get PRD MPLS special label proeprties. if a packet is identified as MPLS special label and the label value matches to one of the saved special labels, the priority and TDM indication will be taken from the label properties.*/
int imb_feu_prd_mpls_special_label_set(
    int unit,
    bcm_port_t port,
    uint32 label_index,
    const bcm_cosq_ingress_port_drop_mpls_special_label_config_t * label_config);
int imb_feu_prd_mpls_special_label_get(
    int unit,
    bcm_port_t port,
    uint32 label_index,
    bcm_cosq_ingress_port_drop_mpls_special_label_config_t * label_config);

/*Configure calendar for FlexE related ports*/
int imb_feu_calendar_set(
    int unit,
    uint32 flags);

/*Configure FIFO resources for flexe client*/
int imb_feu_port_fifo_resource_set(
    int unit,
    bcm_port_t port,
    uint32 flags);

/*Configure L1 Mismatch rate configuration for RMC.*/
int imb_feu_port_l1_mismatch_rate_rx_config_set(
    int unit,
    bcm_port_t port,
    int tx_speed,
    int enable);
/**
 * \brief - Reset the FlexE client credit in FEU-TX
 *
 */
shr_error_e imb_feu_port_credit_tx_reset(
    int unit,
    bcm_port_t port);
/**
 * \brief - Configure FEU scheduler
 *
 */
int imb_feu_port_scheduler_config_set(
    int unit,
    bcm_port_t port,
    int enable);
/**
 * \brief - Enable / disable egress flush with error recovery.
 *
 */
int imb_feu_port_er_tx_egress_flush_set(
    int unit,
    bcm_port_t port,
    int flush_enable);
/**
 * \brief - Get the latest packet PRD priority and TDM indication of a port
 *
 */
int imb_feu_prd_port_last_packet_priority_get(
    int unit,
    bcm_port_t port,
    uint32 *priority,
    uint32 *tdm,
    uint32 *valid);

#endif /*_IMB_FEU_H_*/
