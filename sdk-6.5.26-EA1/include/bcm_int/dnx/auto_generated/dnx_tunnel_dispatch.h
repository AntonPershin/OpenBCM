/*
 * DO NOT EDIT THIS FILE!
 * This file is auto-generated.
 * Edits to this file will be lost when it is regenerated.
 *
 * 
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2022 Broadcom Inc. All rights reserved.
 *
 * File:        dnx_tunnel_dispatch.h
 * Purpose:     dnx tunnel driver BCM API dispatch table
 * Generator:   modules_dispatch.py
 */

#ifndef _BCM_INT_DNX_TUNNEL_DISPATCH_H
#define _BCM_INT_DNX_TUNNEL_DISPATCH_H

#include <bcm/types.h>
#include <bcm_int/dispatch.h>

#ifdef BCM_DNX_SUPPORT

extern int bcm_dnx_tunnel_dscp_map_port_get(int,bcm_port_t,bcm_tunnel_dscp_map_t *);
extern int bcm_dnx_tunnel_dscp_map_port_set(int,bcm_port_t,bcm_tunnel_dscp_map_t *);
extern int bcm_dnx_tunnel_initiator_get(int,bcm_l3_intf_t *,bcm_tunnel_initiator_t *);
extern int bcm_dnx_tunnel_config_set(int,bcm_tunnel_config_t *);
extern int bcm_dnx_tunnel_terminator_get(int,bcm_tunnel_terminator_t *);
extern int bcm_dnx_tunnel_dscp_map_create(int,uint32,int *);
extern int bcm_dnx_tunnel_dscp_map_get(int,int,bcm_tunnel_dscp_map_t *);
extern int bcm_dnx_tunnel_config_get(int,bcm_tunnel_config_t *);
extern int bcm_dnx_tunnel_initiator_clear(int,bcm_l3_intf_t *);
extern int bcm_dnx_tunnel_terminator_config_get(int,bcm_tunnel_terminator_config_key_t *,bcm_tunnel_terminator_config_action_t *);
extern int bcm_dnx_tunnel_terminator_add(int,bcm_tunnel_terminator_t *);
extern int bcm_dnx_tunnel_terminator_config_delete(int,bcm_tunnel_terminator_config_key_t *);
extern int bcm_dnx_tunnel_terminator_delete(int,bcm_tunnel_terminator_t *);
extern int bcm_dnx_tunnel_terminator_update(int,bcm_tunnel_terminator_t *);
extern int bcm_dnx_tunnel_terminator_config_add(int,uint32,bcm_tunnel_terminator_config_key_t *,bcm_tunnel_terminator_config_action_t *);
extern int bcm_dnx_tunnel_terminator_vlan_get(int,bcm_gport_t,bcm_vlan_vector_t *);
extern int bcm_dnx_tunnel_initiator_set(int,bcm_l3_intf_t *,bcm_tunnel_initiator_t *);
extern int bcm_dnx_tunnel_initiator_create(int,bcm_l3_intf_t *,bcm_tunnel_initiator_t *);
extern int bcm_dnx_tunnel_terminator_create(int,bcm_tunnel_terminator_t *);
extern int bcm_dnx_tunnel_terminator_config_traverse(int,bcm_tunnel_terminator_config_traverse_info_t,bcm_tunnel_terminator_config_traverse_cb,void *);
extern int bcm_dnx_tunnel_terminator_vlan_set(int,bcm_gport_t,bcm_vlan_vector_t);
extern int bcm_dnx_tunnel_dscp_map_destroy(int,int);
extern int bcm_dnx_tunnel_terminator_traverse(int,bcm_tunnel_terminator_traverse_cb,void *);
extern int bcm_dnx_tunnel_initiator_traverse(int,bcm_tunnel_initiator_traverse_cb,void *);
extern int bcm_dnx_tunnel_dscp_map_set(int,int,bcm_tunnel_dscp_map_t *);

#endif /* BCM_DNX_SUPPORT */
#endif /* !_BCM_INT_DNX_TUNNEL_DISPATCH_H */
