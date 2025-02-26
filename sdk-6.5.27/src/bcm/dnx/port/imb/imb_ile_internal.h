/** \file imb_ile_internal.h
 *
 */
/*
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2022 Broadcom Inc. All rights reserved.
 */
#ifndef IMB_ILE_INTERNAL_H_INCLUDED
/*
 * {
 */
#define IMB_ILE_INTERNAL_H_INCLUDED

#ifndef BCM_DNX_SUPPORT
#error "This file is for use by DNX family only!"
#endif

/*
 * INCLUDE FILES:
 * {
 */
#include <bcm/port.h>

/*
 * }
 */
/*
 * DEFINES:
 * {
 */
#define IMB_ILE_PHY_INVALID (-1)

/*
 * }
 */
/*
 * MACROs
 * {
 */
/*
 * }
 */
/*
 * Functions
 * {
 */
/**
 * \brief - Enable ILE port in wrapper. This action essentially reset the port in the ILKN core,
 * but without affecting the ILKN core configurations. this reset is done before any access to the PM phys.
 *
 * \param [in] unit - chip unit id.
 * \param [in] port - logical port
 * \param [in] flags - flags
 * \param [in] enable - enable / disable indication.
 *
 * \return
 *   int - see _SHR_E*
 *
 * \remarks
 *   * None
 * \see
 *   * None
 */
int imb_ile_port_wrapper_enable_set(
    int unit,
    bcm_port_t port,
    uint32 flags,
    int enable);

/**
 * \brief - get the ILE core, port status in wrapper.
 *
 * \param [in] unit - chip unit id.
 * \param [in] port - logical port
 * \param [out] enable - enable / disable indication.
 *
 * \return
 *   int - see _SHR_E*
 *
 * \remarks
 *   * None
 * \see
 *   * None
 */
int imb_ile_port_wrapper_enable_get(
    int unit,
    bcm_port_t port,
    int *enable);

/**
 * \brief - set number of segments to be used by the port
 *
 * \param [in] unit - chip unit id
 * \param [in] port - logical port
 * \param [in] nof_segments - number of segments to set. (0/2/4)
 *
 * \return
 *   int - see _SHR_E_*
 *
 * \remarks
 *   * None
 * \see
 *   * None
 */
int imb_ile_port_nof_segments_set(
    int unit,
    bcm_port_t port,
    int nof_segments);

/**
 * \brief - enable segments to be used by the port
 *
 * \param [in] unit - chip unit id
 * \param [in] port - logical port
 * \param [in] nof_segments - number of segments to set. (0/2/4)
 * there can be only two ways to divide the segments:
 * 1. ILKN0 gets 4 segments (no ILKN1)
 * 2. each ILKN port gets two segments. in this case ILKN0 will
 * take segments 0 and 1, and ILKN1 will take segments 2,3.
 * \param [in] enable - enable/disable
 *
 * \return
 *   int - see _SHR_E_*
 *
 * \remarks
 *   * None
 * \see
 *   * None
 */
int imb_ile_port_segments_enable_set(
    int unit,
    bcm_port_t port,
    int nof_segments,
    int enable);

/**
 * \brief - set ILKN to operate over fabric links instead of NIF
 *        phys.
 *
 * \param [in] unit - chip unit id.
 * \param [in] port - logical port
 * \param [in] is_over_fabric - is port over fabric indication
 *
 * \return
 *   int - see _SHR_E*
 *
 * \remarks
 *   * None
 * \see
 *   * None
 */
int imb_ile_port_ilkn_over_fabric_set(
    int unit,
    bcm_port_t port,
    int is_over_fabric);

/**
 * \brief - set ILKN port to operate as ELK port (in JR2 this
 *        is the only valid option for ILKN)
 *
 * \param [in] unit - chip unit id
 * \param [in] port - logical port
 * \param [in] is_elk - is ILKN port used for ELK connection
 *
 * \return
 *   int - see _SHR_E*
 *
 * \remarks
 *   * None
 * \see
 *   * None
 */
int imb_ile_port_ilkn_elk_set(
    int unit,
    bcm_port_t port,
    int is_elk);

/**
 * \brief - reset ELK RX
 */
int imb_ile_port_elk_rx_reset_set(
    int unit,
    bcm_port_t port,
    int in_reset);

/**
 * \brief - set ILKN ELK data mux: for data or ELK
 *
 * \param [in] unit - chip unit id
 * \param [in] port - logical port
 * \param [in] is_elk - is ILKN port used for ELK connection
 *
 * \return
 *   int - see _SHR_E*
 *
 * \remarks
 *   * None
 * \see
 *   * None
 */
int imb_ile_port_ilkn_elk_data_mux_set(
    int unit,
    bcm_port_t port,
    int is_elk);

/**
 * \brief - set ILKN credits source
 *
 * \param [in] unit - chip unit id
 * \param [in] port - logical port
 *
 * \return
 *   int - see _SHR_E*
 *
 * \remarks
 *   * None
 * \see
 *   * None
 */
int imb_ile_port_ilkn_credits_source_set(
    int unit,
    bcm_port_t port);

/**
 * \brief - reset the ILKN port. this is the main reset for the
 *        port which affect all prior configurations. this
 *        should be the first reset before starting any ILKN
 *        core configurations.
 *
 * \param [in] unit - chip unit id.
 * \param [in] port - logical port
 * \param [in] is_core_reset - indicated if to reset entire core
 * \param [in] in_reset - in reset indication:
 * 0 => out-of-reset
 * 1 => in-reset
 *
 * \return
 *   int - see _SHR_E*
 *
 * \remarks
 *   * None
 * \see
 *   * None
 */
int imb_ile_port_reset_set(
    int unit,
    bcm_port_t port,
    int is_core_reset,
    int in_reset);

/**
 * \brief - get latch down indication for the port.
 *
 * \param [in] unit - chip unit id
 * \param [in] port - logical port
 * \param [out] is_latch_low_aligned - returned latch low
 *        indication.
 *
 * \return
 *   int - see _SHR_E*
 *
 * \remarks
 *   * None
 * \see
 *   * None
 */
int imb_ile_port_latch_down_get(
    int unit,
    bcm_port_t port,
    uint32 *is_latch_low_aligned);

/**
 * \brief - reset the bypass interface in the CDU.
 * when ILKN port is operating over NIF, the CDU logic needs to
 * be bypassed. this enables the bypass interface to take place.
 *
 * \param [in] unit - chip unit id
 * \param [in] port - logical port
 * \param [in] flags - direction of the bypass interface:
 * IMB_ILE_DIRECTION_TX/RX
 * \param [in] enable - enable/ disable the bypass interface
 *        indication
 *
 * \return
 *   int - see _SHR_E*
 *
 * \remarks
 *   * None
 * \see
 *   * None
 */
int imb_ile_port_bypass_if_enable_set(
    int unit,
    bcm_port_t port,
    uint32 flags,
    int enable);

/**
 * \brief - Select ILKN over W40 in Framer
 */
/**
 * \brief - select/unselect ILKN over W40 in Framer
 *
 * \param [in] unit - chip unit id
 * \param [in] port - logical port
 * \param [in] select_ilkn - TRUE = select/ FALSE = unselect
 *
 * \return
 *   int - see _SHR_E*
 *
 * \remarks
 *   * None
 * \see
 *   * None
 */
int imb_ile_port_frmr_ilkn_select_set(
    int unit,
    bcm_port_t port,
    int select_ilkn);

/**
 * \brief - returns if XPMD interface should be enabled
 *
 * \param [in] unit - chip unit id
 * \param [in] port - logical port
 * \param [out] is_xpmd_enabled - whether to use xpmd interface
 * \return
 *   int - see _SHR_E*
 *
 * \remarks
 *   * None
 * \see
 *   * None
 */
int imb_ilu_is_xpmd_enabled(
    int unit,
    bcm_port_t port,
    uint8 *is_xpmd_enabled);

/**
 * \brief - Reset XPMD Async Fifo in the CDU.
 * when ILKN port is operating over NIF, the CDU logic needs to
 * be bypassed. this enables the XPMD interface to take place.
 *
 * \param [in] unit - chip unit id
 * \param [in] port - logical port
 * \param [in] flags - direction of the bypass interface:
 * IMB_ILE_DIRECTION_TX/RX
 * \param [in] in_reset - in reset indication:
 * 0 => out-of-reset
 * 1 => in-reset
 *
 * \return
 *   int - see _SHR_E*
 *
 * \remarks
 *   * None
 * \see
 *   * None
 */
int imb_ile_port_async_fifo_reset(
    int unit,
    bcm_port_t port,
    uint32 flags,
    uint8 in_reset);
/**
 * \brief - Enable the XPMD interface in the CDU.
 * when ILKN port is operating over NIF, the CDU logic needs to
 * be bypassed. this enables the XPMD interface to take place.
 *
 * \param [in] unit - chip unit id
 * \param [in] port - logical port
 * \param [in] flags - direction of the bypass interface:
 * IMB_ILE_DIRECTION_TX/RX
 * \param [in] enable - enable/ disable the bypass interface
 *        indication
 *
 * \return
 *   int - see _SHR_E*
 *
 * \remarks
 *   * None
 * \see
 *   * None
 */
int imb_ile_port_xpmd_lane_enable(
    int unit,
    bcm_port_t port,
    uint32 flags,
    int enable);

/**
* \brief - Get the lane map info for ILKN port.
*
* \param [in] unit - chip unit id
* \param [in] port - logical port
* \param [in] nof_lanes - max lanes per ILKN core
* \param [out] rx_lane_map - Rx lane map info per ILKN core
* \param [out] tx_lane_map - Tx lane map info per ILKN core
*
* \return
*   int - see _SHR_E*
*
* \remarks
*   * None
* \see
*   * None
*/

shr_error_e imb_ile_port_ilkn_port_lane_map_get(
    int unit,
    bcm_port_t port,
    int nof_lanes,
    int *rx_lane_map,
    int *tx_lane_map);

/**
* \brief - Get the lane map info for ILKN core.
*
* \param [in] unit - chip unit id
* \param [in] port - logical port
* \param [in] nof_lanes - max lanes per ILKN pm
* \param [in] first_phy - PM first phy
* \param [out] phy_lane_map -lane map info per ILKN pm
*
* \return
*   int - see _SHR_E*
*
* \remarks
*   * None
* \see
*   * None
*/

shr_error_e imb_ile_port_ilkn_pm_lane_map_get(
    int unit,
    bcm_port_t port,
    int nof_lanes,
    int first_phy,
    phymod_lane_map_t * phy_lane_map);

/**
* \brief - Set the FEC units for ILKN port.
*
* \param [in] unit - chip unit id
* \param [in] port - logical port
* \param [in] is_reset - if to reset fec_units (done on port remove)
* \param [in] fec_enable - enable or disable fec units for this port
* \param [in] fec_bypass_valid - indicates if FEC bypass should be configured
* \param [in] fec_bypass_enable - enable or disable fec bypass for this port.
*
* \return
*   int - see _SHR_E*
*
* \remarks
*   * None
* \see
*   * None
*/
shr_error_e imb_ile_port_ilkn_fec_units_set(
    int unit,
    bcm_port_t port,
    int is_reset,
    int fec_enable,
    int fec_bypass_valid,
    int fec_bypass_enable);

/**
 * \brief - prepare to get rx counter for setting ilkn rx ctrl.
 *
 * \param [in] unit - chip unit id
 * \param [in] port - logical port
 * \param [in] channel - port channel
 *
 * \return
 *   int - see _SHR_E*
 *
 * \remarks
 *   * None
 * \see
 *   * None
 */
int imb_ile_port_ilkn_rx_counter_get_prepared_by_channel(
    int unit,
    bcm_port_t port,
    int channel);

/**
 * \brief - prepare to get rx counter for setting ilkn tx ctrl.
 *
 * \param [in] unit - chip unit id
 * \param [in] port - logical port
 * \param [in] channel - port channel
 *
 * \return
 *   int - see _SHR_E*
 *
 * \remarks
 *   * None
 * \see
 *   * None
 */
int imb_ile_port_ilkn_tx_counter_get_prepared_by_channel(
    int unit,
    bcm_port_t port,
    int channel);

/**
 * \brief - get one ILKN counter from HW.
 *
 * \param [in] unit - chip unit id
 * \param [in] port - logical port
 * \param [in] field_id - dbal_field.
 * \param [out] val - the vaule of the counter.
 *
 * \return
 *   int - see _SHR_E*
 *
 * \remarks
 *   * None
 * \see
 *   * None
 */
int imb_ile_port_ilkn_counter_dbal_get(
    int unit,
    bcm_port_t port,
    dbal_fields_e field_id,
    uint32 *val);

/**
 * \brief - get one ILKN fec counter from HW.
 *
 * \param [in] unit - chip unit id
 * \param [in] port - logical port
 * \param [in] fec_unit - fec instance
 * \param [in] field_id - dbal_field.
 * \param [out] val - the vaule of the counter.
 *
 * \return
 *   int - see _SHR_E*
 *
 * \remarks
 *   * None
 * \see
 *   * None
 */
int imb_ile_port_ilkn_fec_counter_dbal_get(
    int unit,
    bcm_port_t port,
    uint32 fec_unit,
    dbal_fields_e field_id,
    uint32 *val);

/**
 * \brief - enable/disable ILKN TX traffic pause in reaction to RxLLFC.
 *
 * \param [in] unit - chip unit id
 * \param [in] port - logical port
 * \param [in] enable - enable/disable ILKN TX traffic pause in reaction to RxLLFC.
 *
 * \return
 *   int - see _SHR_E*
 *
 * \remarks
 *   * None
 * \see
 *   * None
 */

int imb_ile_port_rx_llfc_enable_set(
    int unit,
    bcm_port_t port,
    int enable);

/**
 * \brief - set the various mux selectors in the cdu/clu blocks for the ilkn port.
 *
 * \param [in] unit - chip unit id
 * \param [in] port - logical port
 *
 * \return
 *   int - see _SHR_E*
 *
 * \remarks
 *   * None
 * \see
 *   * None
 */
int imb_ile_port_mux_selectors_set(
    int unit,
    bcm_port_t port);

/**
 * \brief - Reset the various mux selectors in the cdu/clu blocks for the ilkn port.
 * Currently only TX enabler MUX which enable/disable  CLUP to transmit for up/down CLUP is relevant.
 * In case it's a single port on the ilkn core, or if all second port's lanes are facing - need to reset this mux for not transmitting for up/down CLUP for power optimization.
 *
 * \param [in] unit - chip unit id
 * \param [in] port - logical port
 * \param [in] pm_imb_type - port PM type
 * \param [in] ilkn_nof_ports - number of ilkn ports in the same ilkn core
 *
 * \return
 *   int - see _SHR_E*
 *
 * \remarks
 *   * None
 * \see
 *   * None
 */
int imb_ile_port_mux_selectors_reset(
    int unit,
    bcm_port_t port,
    int pm_imb_type,
    int ilkn_nof_ports);

/**
 * \brief - get the ILKN alignment status from HW.
 *
 * \param [in] unit - chip unit id
 * \param [in] port - logical port
 * \param [out] live_status - alignment live status
 *
 * \return
 *   int - see _SHR_E*
 *
 * \remarks
 *   * None
 * \see
 *   * None
 */
int imb_ile_port_alignment_live_status_get(
    int unit,
    bcm_port_t port,
    uint32 *live_status);

/**
 * \brief - get the ILKN alignment lost/achieved counters.
 *
 * \param [in] unit - chip unit id
 * \param [in] port - logical port
 * \param [out] achieved_counter - the number of times alignment was achieved
 * \param [out] lost_counter - the number of times alignment was lost
 *
 * \return
 *   int - see _SHR_E*
 *
 * \remarks
 *   * None
 * \see
 *   * None
 */
int imb_ile_port_alignment_counters_get(
    int unit,
    bcm_port_t port,
    uint32 *achieved_counter,
    uint32 *lost_counter);
 /*
  * }
  */

/**
 * \brief - Configure power down of ILE
 *
 */
int imb_ile_power_down_set(
    int unit,
    int ilkn_core_id,
    int power_down);

/**
 * \brief - Configure global reset of FEC
 *
 */
int imb_ile_internal_fec_global_enable_set(
    int unit,
    int ilkn_core,
    int fec_enable);

/**
 * \brief - Checks whether fec bypass is enable
 *
 */
int imb_ile_port_ilkn_is_fec_bypass_enable(
    int unit,
    int port,
    int *fec_bypass_enable);

/**
 * \brief - get ilu bursts drop counter value per HRF
 *
 * \param [in] unit - chip unit id
 * \param [in] port - logical port
 * \param [out] burst_count - counter value
 *
 * \return
 *   int - see _SHR_E_*
 *
 * \remarks
 *   * None
 * \see
 *   * None
 */
int imb_ilu_burst_drop_count_get(
    int unit,
    bcm_port_t port,
    uint64 *burst_count);

/**
 * \brief - Check whether there are other ILKN ports using the same ETHU
 *
 * \param [in] unit - chip unit id
 * \param [in] port - logical port
 * \param [in] cdu_id - global cdu id (not cdu id in core)
 * \param [out] is_only_port_on_ethu - TRUE if other ILKN ports are using this ETHU, FALSE otherwise
 *
 * \return
 *   int - see _SHR_E_*
 *
 * \remarks
 *   * None
 * \see
 *   * None
 */
int imb_ile_port_is_only_ilkn_port_on_cdu_get(
    int unit,
    bcm_port_t port,
    int cdu_id,
    int *is_only_port_on_ethu);

/**
 * \brief - Configure the PM lock status mux and interrupt masks to receive interrupt when lock status changes
 *
 * \param [in] unit - chip unit id
 * \param [in] port - logical port
 * \param [in] enable - TRUE to enable FALSE to disable
 *
 * \return
 *   int - see _SHR_E_*
 *
 * \remarks
 *   * None
 * \see
 *   * None
 */
int imb_ile_port_lock_status_interrupt_enable_set(
    int unit,
    bcm_port_t port,
    int enable);

#endif/*_IMB_ILE_INTERNAL_H_INCLUDED_*/
