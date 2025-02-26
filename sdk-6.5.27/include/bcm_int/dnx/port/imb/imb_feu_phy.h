
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

#ifndef _IMB_FEU_PHY_H__H_
#define _IMB_FEU_PHY_H__H_

#include <soc/portmod/portmod.h>
#include <bcm/port.h>
#include <bcm/cosq.h>
#include <bcm_int/dnx/port/imb/imb_diag.h>
#include <bcm_int/dnx/cosq/ingress/cosq_ingress_port.h>
#include <soc/dnxc/dnxc_port.h>
/*initialize an IMB.*/
int imb_feu_phy_init(
    int unit,
    const imb_create_info_t * imb_info,
    imb_specific_create_info_t * imb_specific_info);

/*De-initialize an existing IMB.*/
int imb_feu_phy_deinit(
    int unit,
    const imb_create_info_t * imb_info,
    imb_specific_create_info_t * imb_specific_info);

/*Add new IMB (Interface Management Block) port*/
int imb_feu_phy_port_attach(
    int unit,
    bcm_port_t port,
    uint32 flags);

/*Remove an existing IMB (Interface Management Block) port*/
int imb_feu_phy_port_detach(
    int unit,
    bcm_port_t port);

/*Enable / disable a port*/
int imb_feu_phy_port_enable_set(
    int unit,
    bcm_port_t port,
    uint32 flags,
    int enable);
int imb_feu_phy_port_enable_get(
    int unit,
    bcm_port_t port,
    int *enable);

/*Config MIB counter max size.*/
int imb_feu_phy_port_cntmaxsize_set(
    int unit,
    bcm_port_t port,
    int val);
int imb_feu_phy_port_cntmaxsize_get(
    int unit,
    bcm_port_t port,
    int *val);

/*Get port's default resource configurations*/
int imb_feu_phy_port_resource_default_get(
    int unit,
    bcm_port_t port,
    uint32 flags,
    bcm_port_resource_t * resource);

/*Configure calendar for FlexE related ports*/
int imb_feu_phy_calendar_set(
    int unit,
    bcm_port_t port,
    uint32 flags);

/*IMB post init after speed configuration is ready*/
int imb_feu_phy_post_init(
    int unit,
    int imb_id);

/*FlexE core port related configuration.*/
int imb_feu_phy_flexe_core_port_config_set(
    int unit,
    bcm_port_t port,
    uint32 flags,
    int instance_id,
    int speed);

/*Get two-step PTP PHY timesync tx info for port. */
int imb_feu_phy_port_timesync_tx_info_get(
    int unit,
    bcm_port_t port,
    bcm_port_timesync_tx_info_t * tx_info);

/*1588 for L1 ETH ports enable set/get.*/
int imb_feu_phy_port_l1_eth_1588_enable_set(
    int unit,
    bcm_port_t port,
    uint32 flags,
    int enable);
int imb_feu_phy_port_l1_eth_1588_enable_get(
    int unit,
    bcm_port_t port,
    uint32 flags,
    int *enable);

#endif /*_IMB_FEU_PHY_H_*/
