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
 * File:        dnx_multicast_dispatch.h
 * Purpose:     dnx multicast driver BCM API dispatch table
 * Generator:   modules_dispatch.py
 */

#ifndef _BCM_INT_DNX_MULTICAST_DISPATCH_H
#define _BCM_INT_DNX_MULTICAST_DISPATCH_H

#include <bcm/types.h>
#include <bcm_int/dispatch.h>

#ifdef BCM_DNX_SUPPORT

extern int bcm_dnx_multicast_encap_extension_delete_all(int);
extern int bcm_dnx_multicast_get(int,bcm_multicast_t,uint32,int,bcm_multicast_replication_t *,int *);
extern int bcm_dnx_multicast_group_destroy(int,uint32,bcm_multicast_t);
extern int bcm_dnx_multicast_stat_control_get(int,bcm_core_t,uint32,int,bcm_multicast_stat_control_type_t,int *);
extern int bcm_dnx_multicast_encap_extension_get(int,uint32,bcm_if_t,int,bcm_if_t *,int *);
extern int bcm_dnx_multicast_vpls_encap_get(int,bcm_multicast_t,bcm_gport_t,bcm_gport_t,bcm_if_t *);
extern int bcm_dnx_multicast_set(int,bcm_multicast_t,uint32,int,bcm_multicast_replication_t *);
extern int bcm_dnx_multicast_bfr_id_add(int,bcm_multicast_t,uint32,int,uint32 *,bcm_multicast_replication_t *);
extern int bcm_dnx_multicast_egress_object_encap_get(int,bcm_multicast_t,bcm_if_t,bcm_if_t *);
extern int bcm_dnx_multicast_bfr_id_get(int,bcm_multicast_t,uint32,int,uint32 *,bcm_multicast_replication_t *);
extern int bcm_dnx_multicast_bfr_id_delete(int,bcm_multicast_t,uint32,int,uint32 *,bcm_multicast_replication_t *);
extern int bcm_dnx_multicast_l3_encap_get(int,bcm_multicast_t,bcm_gport_t,bcm_if_t,bcm_if_t *);
extern int bcm_dnx_multicast_delete(int,bcm_multicast_t,uint32,int,bcm_multicast_replication_t *);
extern int bcm_dnx_multicast_vxlan_encap_get(int,bcm_multicast_t,bcm_gport_t,bcm_gport_t,bcm_if_t *);
extern int bcm_dnx_multicast_encap_extension_create(int,uint32,bcm_if_t *,int,bcm_if_t *);
extern int bcm_dnx_multicast_add(int,bcm_multicast_t,uint32,int,bcm_multicast_replication_t *);
extern int bcm_dnx_multicast_encap_extension_traverse(int,bcm_multicast_encap_extension_traverse_cb,void *);
extern int bcm_dnx_multicast_vlan_encap_get(int,bcm_multicast_t,bcm_gport_t,bcm_gport_t,bcm_if_t *);
extern int bcm_dnx_multicast_create(int,uint32,bcm_multicast_t *);
extern int bcm_dnx_multicast_group_get(int,bcm_multicast_t,uint32 *);
extern int bcm_dnx_multicast_stat_control_set(int,bcm_core_t,uint32,int,bcm_multicast_stat_control_type_t,int);
extern int bcm_dnx_multicast_encap_extension_destroy(int,uint32,bcm_if_t);
extern int bcm_dnx_multicast_destroy(int,bcm_multicast_t);

#endif /* BCM_DNX_SUPPORT */
#endif /* !_BCM_INT_DNX_MULTICAST_DISPATCH_H */
