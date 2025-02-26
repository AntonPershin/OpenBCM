/** \file algo/swstate/auto_generated/access/lif_table_mngr_access.h
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

#ifndef __LIF_TABLE_MNGR_ACCESS_H__
#define __LIF_TABLE_MNGR_ACCESS_H__

#include <bcm_int/dnx/algo/swstate/auto_generated/types/lif_table_mngr_types.h>
#include <soc/dnxc/swstate/callbacks/sw_state_htb_callbacks.h>
#include <soc/dnxc/swstate/types/sw_state_hash_table.h>
/*
 * TYPEDEFs
 */

/**
 * implemented by: lif_table_mngr_db_is_init
 */
typedef int (*lif_table_mngr_db_is_init_cb)(
    int unit, uint8 *is_init);

/**
 * implemented by: lif_table_mngr_db_init
 */
typedef int (*lif_table_mngr_db_init_cb)(
    int unit);

/**
 * implemented by: lif_table_mngr_db_valid_fields_per_egress_lif_htb_create
 */
typedef int (*lif_table_mngr_db_valid_fields_per_egress_lif_htb_create_cb)(
    int unit, sw_state_htbl_init_info_t *init_info);

/**
 * implemented by: lif_table_mngr_db_valid_fields_per_egress_lif_htb_find
 */
typedef int (*lif_table_mngr_db_valid_fields_per_egress_lif_htb_find_cb)(
    int unit, const int *key, local_lif_info_t *value, uint8 *found);

/**
 * implemented by: lif_table_mngr_db_valid_fields_per_egress_lif_htb_insert
 */
typedef int (*lif_table_mngr_db_valid_fields_per_egress_lif_htb_insert_cb)(
    int unit, const int *key, const local_lif_info_t *value, uint8 *success);

/**
 * implemented by: lif_table_mngr_db_valid_fields_per_egress_lif_htb_get_next
 */
typedef int (*lif_table_mngr_db_valid_fields_per_egress_lif_htb_get_next_cb)(
    int unit, SW_STATE_HASH_TABLE_ITER *iter, const int *key, const local_lif_info_t *value);

/**
 * implemented by: lif_table_mngr_db_valid_fields_per_egress_lif_htb_clear
 */
typedef int (*lif_table_mngr_db_valid_fields_per_egress_lif_htb_clear_cb)(
    int unit);

/**
 * implemented by: lif_table_mngr_db_valid_fields_per_egress_lif_htb_delete
 */
typedef int (*lif_table_mngr_db_valid_fields_per_egress_lif_htb_delete_cb)(
    int unit, const int *key);

#ifdef BCM_DNX2_SUPPORT
/**
 * implemented by: lif_table_mngr_db_valid_fields_per_ingress_lif1_set
 */
typedef int (*lif_table_mngr_db_valid_fields_per_ingress_lif1_set_cb)(
    int unit, uint32 valid_fields_per_ingress_lif1_idx_0, CONST local_lif_info_t *valid_fields_per_ingress_lif1);
#endif /* BCM_DNX2_SUPPORT*/ 

#ifdef BCM_DNX2_SUPPORT
/**
 * implemented by: lif_table_mngr_db_valid_fields_per_ingress_lif1_get
 */
typedef int (*lif_table_mngr_db_valid_fields_per_ingress_lif1_get_cb)(
    int unit, uint32 valid_fields_per_ingress_lif1_idx_0, local_lif_info_t *valid_fields_per_ingress_lif1);
#endif /* BCM_DNX2_SUPPORT*/ 

#ifdef BCM_DNX2_SUPPORT
/**
 * implemented by: lif_table_mngr_db_valid_fields_per_ingress_lif1_alloc
 */
typedef int (*lif_table_mngr_db_valid_fields_per_ingress_lif1_alloc_cb)(
    int unit, uint32 nof_instances_to_alloc_0);
#endif /* BCM_DNX2_SUPPORT*/ 

#ifdef BCM_DNX2_SUPPORT
/**
 * implemented by: lif_table_mngr_db_valid_fields_per_ingress_lif2_set
 */
typedef int (*lif_table_mngr_db_valid_fields_per_ingress_lif2_set_cb)(
    int unit, uint32 valid_fields_per_ingress_lif2_idx_0, CONST local_lif_info_t *valid_fields_per_ingress_lif2);
#endif /* BCM_DNX2_SUPPORT*/ 

#ifdef BCM_DNX2_SUPPORT
/**
 * implemented by: lif_table_mngr_db_valid_fields_per_ingress_lif2_get
 */
typedef int (*lif_table_mngr_db_valid_fields_per_ingress_lif2_get_cb)(
    int unit, uint32 valid_fields_per_ingress_lif2_idx_0, local_lif_info_t *valid_fields_per_ingress_lif2);
#endif /* BCM_DNX2_SUPPORT*/ 

#ifdef BCM_DNX2_SUPPORT
/**
 * implemented by: lif_table_mngr_db_valid_fields_per_ingress_lif2_alloc
 */
typedef int (*lif_table_mngr_db_valid_fields_per_ingress_lif2_alloc_cb)(
    int unit, uint32 nof_instances_to_alloc_0);
#endif /* BCM_DNX2_SUPPORT*/ 

/**
 * implemented by: lif_table_mngr_db_lif_table_info_htb_create
 */
typedef int (*lif_table_mngr_db_lif_table_info_htb_create_cb)(
    int unit, sw_state_htbl_init_info_t *init_info);

/**
 * implemented by: lif_table_mngr_db_lif_table_info_htb_find
 */
typedef int (*lif_table_mngr_db_lif_table_info_htb_find_cb)(
    int unit, const int *key, lif_table_mngr_table_info_t *value, uint8 *found);

/**
 * implemented by: lif_table_mngr_db_lif_table_info_htb_insert
 */
typedef int (*lif_table_mngr_db_lif_table_info_htb_insert_cb)(
    int unit, const int *key, const lif_table_mngr_table_info_t *value, uint8 *success);

/**
 * implemented by: lif_table_mngr_db_lif_table_info_htb_get_next
 */
typedef int (*lif_table_mngr_db_lif_table_info_htb_get_next_cb)(
    int unit, SW_STATE_HASH_TABLE_ITER *iter, const int *key, const lif_table_mngr_table_info_t *value);

/**
 * implemented by: lif_table_mngr_db_lif_table_info_htb_clear
 */
typedef int (*lif_table_mngr_db_lif_table_info_htb_clear_cb)(
    int unit);

/**
 * implemented by: lif_table_mngr_db_lif_table_info_htb_delete
 */
typedef int (*lif_table_mngr_db_lif_table_info_htb_delete_cb)(
    int unit, const int *key);

/*
 * STRUCTs
 */

/**
 * This structure holds the access functions for the variable valid_fields_per_egress_lif_htb
 */
typedef struct {
    lif_table_mngr_db_valid_fields_per_egress_lif_htb_create_cb create;
    lif_table_mngr_db_valid_fields_per_egress_lif_htb_find_cb find;
    lif_table_mngr_db_valid_fields_per_egress_lif_htb_insert_cb insert;
    lif_table_mngr_db_valid_fields_per_egress_lif_htb_get_next_cb get_next;
    lif_table_mngr_db_valid_fields_per_egress_lif_htb_clear_cb clear;
    lif_table_mngr_db_valid_fields_per_egress_lif_htb_delete_cb delete;
} lif_table_mngr_db_valid_fields_per_egress_lif_htb_cbs;

#ifdef BCM_DNX2_SUPPORT
/**
 * This structure holds the access functions for the variable local_lif_info_t
 */
typedef struct {
    lif_table_mngr_db_valid_fields_per_ingress_lif1_set_cb set;
    lif_table_mngr_db_valid_fields_per_ingress_lif1_get_cb get;
    lif_table_mngr_db_valid_fields_per_ingress_lif1_alloc_cb alloc;
} lif_table_mngr_db_valid_fields_per_ingress_lif1_cbs;
#endif /* BCM_DNX2_SUPPORT*/ 

#ifdef BCM_DNX2_SUPPORT
/**
 * This structure holds the access functions for the variable local_lif_info_t
 */
typedef struct {
    lif_table_mngr_db_valid_fields_per_ingress_lif2_set_cb set;
    lif_table_mngr_db_valid_fields_per_ingress_lif2_get_cb get;
    lif_table_mngr_db_valid_fields_per_ingress_lif2_alloc_cb alloc;
} lif_table_mngr_db_valid_fields_per_ingress_lif2_cbs;
#endif /* BCM_DNX2_SUPPORT*/ 

/**
 * This structure holds the access functions for the variable lif_table_info_htb
 */
typedef struct {
    lif_table_mngr_db_lif_table_info_htb_create_cb create;
    lif_table_mngr_db_lif_table_info_htb_find_cb find;
    lif_table_mngr_db_lif_table_info_htb_insert_cb insert;
    lif_table_mngr_db_lif_table_info_htb_get_next_cb get_next;
    lif_table_mngr_db_lif_table_info_htb_clear_cb clear;
    lif_table_mngr_db_lif_table_info_htb_delete_cb delete;
} lif_table_mngr_db_lif_table_info_htb_cbs;

/**
 * This structure holds the access functions for the variable lif_table_mngr_sw_state_t
 */
typedef struct {
    lif_table_mngr_db_is_init_cb is_init;
    lif_table_mngr_db_init_cb init;
    /**
     * Access struct for valid_fields_per_egress_lif_htb
     */
    lif_table_mngr_db_valid_fields_per_egress_lif_htb_cbs valid_fields_per_egress_lif_htb;
#ifdef BCM_DNX2_SUPPORT
    /**
     * Access struct for valid_fields_per_ingress_lif1
     */
    lif_table_mngr_db_valid_fields_per_ingress_lif1_cbs valid_fields_per_ingress_lif1;
#endif /* BCM_DNX2_SUPPORT*/ 
#ifdef BCM_DNX2_SUPPORT
    /**
     * Access struct for valid_fields_per_ingress_lif2
     */
    lif_table_mngr_db_valid_fields_per_ingress_lif2_cbs valid_fields_per_ingress_lif2;
#endif /* BCM_DNX2_SUPPORT*/ 
    /**
     * Access struct for lif_table_info_htb
     */
    lif_table_mngr_db_lif_table_info_htb_cbs lif_table_info_htb;
} lif_table_mngr_db_cbs;

/*
 * Global Variables
 */

/*
 * Global Variables
 */

extern lif_table_mngr_db_cbs lif_table_mngr_db;

#endif /* __LIF_TABLE_MNGR_ACCESS_H__ */
