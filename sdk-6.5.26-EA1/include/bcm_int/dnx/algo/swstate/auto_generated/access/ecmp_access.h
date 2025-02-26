/** \file algo/swstate/auto_generated/access/ecmp_access.h
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

#ifndef __ECMP_ACCESS_H__
#define __ECMP_ACCESS_H__

#include <bcm_int/dnx/algo/swstate/auto_generated/types/ecmp_types.h>
#include <bcm_int/dnx/algo/res_mngr/res_mngr.h>
#include <bcm_int/dnx/algo/res_mngr/res_mngr_internal.h>
#include <soc/dnxc/swstate/callbacks/sw_state_ll_callbacks.h>
#include <soc/dnxc/swstate/types/sw_state_linked_list.h>
/*
 * TYPEDEFs
 */

/**
 * implemented by: ecmp_db_info_is_init
 */
typedef int (*ecmp_db_info_is_init_cb)(
    int unit, uint8 *is_init);

/**
 * implemented by: ecmp_db_info_init
 */
typedef int (*ecmp_db_info_init_cb)(
    int unit);

/**
 * implemented by: ecmp_db_info_members_tbl_addr_profile_link_lists_create_empty
 */
typedef int (*ecmp_db_info_members_tbl_addr_profile_link_lists_create_empty_cb)(
    int unit, sw_state_ll_init_info_t *init_info);

/**
 * implemented by: ecmp_db_info_members_tbl_addr_profile_link_lists_nof_elements
 */
typedef int (*ecmp_db_info_members_tbl_addr_profile_link_lists_nof_elements_cb)(
    int unit, uint32 ll_head_index, uint32 *nof_elements);

/**
 * implemented by: ecmp_db_info_members_tbl_addr_profile_link_lists_node_value
 */
typedef int (*ecmp_db_info_members_tbl_addr_profile_link_lists_node_value_cb)(
    int unit, sw_state_ll_node_t node, uint32 *value);

/**
 * implemented by: ecmp_db_info_members_tbl_addr_profile_link_lists_node_update
 */
typedef int (*ecmp_db_info_members_tbl_addr_profile_link_lists_node_update_cb)(
    int unit, sw_state_ll_node_t node, const uint32 *value);

/**
 * implemented by: ecmp_db_info_members_tbl_addr_profile_link_lists_next_node
 */
typedef int (*ecmp_db_info_members_tbl_addr_profile_link_lists_next_node_cb)(
    int unit, uint32 ll_head_index, sw_state_ll_node_t node, sw_state_ll_node_t *next_node);

/**
 * implemented by: ecmp_db_info_members_tbl_addr_profile_link_lists_previous_node
 */
typedef int (*ecmp_db_info_members_tbl_addr_profile_link_lists_previous_node_cb)(
    int unit, uint32 ll_head_index, sw_state_ll_node_t node, sw_state_ll_node_t *prev_node);

/**
 * implemented by: ecmp_db_info_members_tbl_addr_profile_link_lists_add_first
 */
typedef int (*ecmp_db_info_members_tbl_addr_profile_link_lists_add_first_cb)(
    int unit, uint32 ll_head_index, const uint32 *value);

/**
 * implemented by: ecmp_db_info_members_tbl_addr_profile_link_lists_add_last
 */
typedef int (*ecmp_db_info_members_tbl_addr_profile_link_lists_add_last_cb)(
    int unit, uint32 ll_head_index, const uint32 *value);

/**
 * implemented by: ecmp_db_info_members_tbl_addr_profile_link_lists_remove_node
 */
typedef int (*ecmp_db_info_members_tbl_addr_profile_link_lists_remove_node_cb)(
    int unit, uint32 ll_head_index, sw_state_ll_node_t node);

/**
 * implemented by: ecmp_db_info_members_tbl_addr_profile_link_lists_get_first
 */
typedef int (*ecmp_db_info_members_tbl_addr_profile_link_lists_get_first_cb)(
    int unit, uint32 ll_head_index, sw_state_ll_node_t *node);

/**
 * implemented by: ecmp_db_info_consistent_hashing_manager_handle_set
 */
typedef int (*ecmp_db_info_consistent_hashing_manager_handle_set_cb)(
    int unit, uint32 consistent_hashing_manager_handle);

/**
 * implemented by: ecmp_db_info_consistent_hashing_manager_handle_get
 */
typedef int (*ecmp_db_info_consistent_hashing_manager_handle_get_cb)(
    int unit, uint32 *consistent_hashing_manager_handle);

/**
 * implemented by: ecmp_db_info_ecmp_res_manager_set
 */
typedef int (*ecmp_db_info_ecmp_res_manager_set_cb)(
    int unit, dnx_algo_res_t ecmp_res_manager);

/**
 * implemented by: ecmp_db_info_ecmp_res_manager_get
 */
typedef int (*ecmp_db_info_ecmp_res_manager_get_cb)(
    int unit, dnx_algo_res_t *ecmp_res_manager);

/**
 * implemented by: ecmp_db_info_ecmp_res_manager_create
 */
typedef int (*ecmp_db_info_ecmp_res_manager_create_cb)(
    int unit, dnx_algo_res_create_data_t * data, void *extra_arguments);

/**
 * implemented by: ecmp_db_info_ecmp_res_manager_allocate_single
 */
typedef int (*ecmp_db_info_ecmp_res_manager_allocate_single_cb)(
    int unit, uint32 flags, void *extra_arguments, int *element);

/**
 * implemented by: ecmp_db_info_ecmp_res_manager_free_single
 */
typedef int (*ecmp_db_info_ecmp_res_manager_free_single_cb)(
    int unit, int element, void *extra_arguments);

/**
 * implemented by: ecmp_db_info_ecmp_res_manager_is_allocated
 */
typedef int (*ecmp_db_info_ecmp_res_manager_is_allocated_cb)(
    int unit, int element, uint8 *is_allocated);

/**
 * implemented by: ecmp_db_info_ecmp_res_manager_get_next
 */
typedef int (*ecmp_db_info_ecmp_res_manager_get_next_cb)(
    int unit, int *element);

/**
 * implemented by: ecmp_db_info_ecmp_res_manager_print
 */
typedef int (*ecmp_db_info_ecmp_res_manager_print_cb)(
    int unit);

/**
 * implemented by: ecmp_db_info_ecmp_res_manager_advanced_algorithm_info_get
 */
typedef int (*ecmp_db_info_ecmp_res_manager_advanced_algorithm_info_get_cb)(
    int unit, void *algorithm_info);

/**
 * implemented by: ecmp_db_info_ecmp_extended_res_manager_set
 */
typedef int (*ecmp_db_info_ecmp_extended_res_manager_set_cb)(
    int unit, dnx_algo_res_t ecmp_extended_res_manager);

/**
 * implemented by: ecmp_db_info_ecmp_extended_res_manager_get
 */
typedef int (*ecmp_db_info_ecmp_extended_res_manager_get_cb)(
    int unit, dnx_algo_res_t *ecmp_extended_res_manager);

/**
 * implemented by: ecmp_db_info_ecmp_extended_res_manager_create
 */
typedef int (*ecmp_db_info_ecmp_extended_res_manager_create_cb)(
    int unit, dnx_algo_res_create_data_t * data, void *extra_arguments);

/**
 * implemented by: ecmp_db_info_ecmp_extended_res_manager_allocate_single
 */
typedef int (*ecmp_db_info_ecmp_extended_res_manager_allocate_single_cb)(
    int unit, uint32 flags, void *extra_arguments, int *element);

/**
 * implemented by: ecmp_db_info_ecmp_extended_res_manager_free_single
 */
typedef int (*ecmp_db_info_ecmp_extended_res_manager_free_single_cb)(
    int unit, int element, void *extra_arguments);

/**
 * implemented by: ecmp_db_info_ecmp_extended_res_manager_is_allocated
 */
typedef int (*ecmp_db_info_ecmp_extended_res_manager_is_allocated_cb)(
    int unit, int element, uint8 *is_allocated);

/**
 * implemented by: ecmp_db_info_ecmp_extended_res_manager_get_next
 */
typedef int (*ecmp_db_info_ecmp_extended_res_manager_get_next_cb)(
    int unit, int *element);

/**
 * implemented by: ecmp_db_info_ecmp_extended_res_manager_print
 */
typedef int (*ecmp_db_info_ecmp_extended_res_manager_print_cb)(
    int unit);

/**
 * implemented by: ecmp_db_info_ecmp_extended_res_manager_advanced_algorithm_info_get
 */
typedef int (*ecmp_db_info_ecmp_extended_res_manager_advanced_algorithm_info_get_cb)(
    int unit, void *algorithm_info);

/**
 * implemented by: ecmp_db_info_ecmp_user_profile_res_mngr_create
 */
typedef int (*ecmp_db_info_ecmp_user_profile_res_mngr_create_cb)(
    int unit, dnx_algo_res_create_data_t * data, void *extra_arguments);

/**
 * implemented by: ecmp_db_info_ecmp_user_profile_res_mngr_allocate_single
 */
typedef int (*ecmp_db_info_ecmp_user_profile_res_mngr_allocate_single_cb)(
    int unit, uint32 flags, void *extra_arguments, int *element);

/**
 * implemented by: ecmp_db_info_ecmp_user_profile_res_mngr_free_single
 */
typedef int (*ecmp_db_info_ecmp_user_profile_res_mngr_free_single_cb)(
    int unit, int element, void *extra_arguments);

/**
 * implemented by: ecmp_db_info_ecmp_user_profile_res_mngr_is_allocated
 */
typedef int (*ecmp_db_info_ecmp_user_profile_res_mngr_is_allocated_cb)(
    int unit, int element, uint8 *is_allocated);

/**
 * implemented by: ecmp_db_info_ecmp_user_profile_res_mngr_nof_free_elements_get
 */
typedef int (*ecmp_db_info_ecmp_user_profile_res_mngr_nof_free_elements_get_cb)(
    int unit, int *nof_free_elements);

/**
 * implemented by: ecmp_db_info_ecmp_user_profile_res_mngr_get_next
 */
typedef int (*ecmp_db_info_ecmp_user_profile_res_mngr_get_next_cb)(
    int unit, int *element);

/**
 * implemented by: ecmp_db_info_ecmp_user_profile_res_mngr_print
 */
typedef int (*ecmp_db_info_ecmp_user_profile_res_mngr_print_cb)(
    int unit);

/**
 * implemented by: ecmp_db_info_ecmp_user_profile_data_set
 */
typedef int (*ecmp_db_info_ecmp_user_profile_data_set_cb)(
    int unit, uint32 ecmp_user_profile_data_idx_0, CONST l3_ecmp_user_profile_t *ecmp_user_profile_data);

/**
 * implemented by: ecmp_db_info_ecmp_user_profile_data_get
 */
typedef int (*ecmp_db_info_ecmp_user_profile_data_get_cb)(
    int unit, uint32 ecmp_user_profile_data_idx_0, l3_ecmp_user_profile_t *ecmp_user_profile_data);

/**
 * implemented by: ecmp_db_info_ecmp_user_profile_data_alloc
 */
typedef int (*ecmp_db_info_ecmp_user_profile_data_alloc_cb)(
    int unit, uint32 nof_instances_to_alloc_0);

/**
 * implemented by: ecmp_db_info_ecmp_fec_members_table_set
 */
typedef int (*ecmp_db_info_ecmp_fec_members_table_set_cb)(
    int unit, uint32 ecmp_fec_members_table_idx_0, uint32 ecmp_fec_members_table_idx_1, uint8 ecmp_fec_members_table);

/**
 * implemented by: ecmp_db_info_ecmp_fec_members_table_get
 */
typedef int (*ecmp_db_info_ecmp_fec_members_table_get_cb)(
    int unit, uint32 ecmp_fec_members_table_idx_0, uint32 ecmp_fec_members_table_idx_1, uint8 *ecmp_fec_members_table);

/**
 * implemented by: ecmp_db_info_ecmp_fec_members_table_alloc
 */
typedef int (*ecmp_db_info_ecmp_fec_members_table_alloc_cb)(
    int unit, uint32 nof_instances_to_alloc_0, uint32 nof_instances_to_alloc_1);

/**
 * implemented by: ecmp_db_info_ecmp_group_size_minus_one_set
 */
typedef int (*ecmp_db_info_ecmp_group_size_minus_one_set_cb)(
    int unit, uint32 ecmp_group_size_minus_one_idx_0, uint32 ecmp_group_size_minus_one_idx_1, uint16 ecmp_group_size_minus_one);

/**
 * implemented by: ecmp_db_info_ecmp_group_size_minus_one_get
 */
typedef int (*ecmp_db_info_ecmp_group_size_minus_one_get_cb)(
    int unit, uint32 ecmp_group_size_minus_one_idx_0, uint32 ecmp_group_size_minus_one_idx_1, uint16 *ecmp_group_size_minus_one);

/**
 * implemented by: ecmp_db_info_ecmp_group_size_minus_one_alloc
 */
typedef int (*ecmp_db_info_ecmp_group_size_minus_one_alloc_cb)(
    int unit);

/*
 * STRUCTs
 */

/**
 * This structure holds the access functions for the variable members_tbl_addr_profile_link_lists
 */
typedef struct {
    ecmp_db_info_members_tbl_addr_profile_link_lists_create_empty_cb create_empty;
    ecmp_db_info_members_tbl_addr_profile_link_lists_nof_elements_cb nof_elements;
    ecmp_db_info_members_tbl_addr_profile_link_lists_node_value_cb node_value;
    ecmp_db_info_members_tbl_addr_profile_link_lists_node_update_cb node_update;
    ecmp_db_info_members_tbl_addr_profile_link_lists_next_node_cb next_node;
    ecmp_db_info_members_tbl_addr_profile_link_lists_previous_node_cb previous_node;
    ecmp_db_info_members_tbl_addr_profile_link_lists_add_first_cb add_first;
    ecmp_db_info_members_tbl_addr_profile_link_lists_add_last_cb add_last;
    ecmp_db_info_members_tbl_addr_profile_link_lists_remove_node_cb remove_node;
    ecmp_db_info_members_tbl_addr_profile_link_lists_get_first_cb get_first;
} ecmp_db_info_members_tbl_addr_profile_link_lists_cbs;

/**
 * This structure holds the access functions for the variable consistent_hashing_manager_handle
 */
typedef struct {
    ecmp_db_info_consistent_hashing_manager_handle_set_cb set;
    ecmp_db_info_consistent_hashing_manager_handle_get_cb get;
} ecmp_db_info_consistent_hashing_manager_handle_cbs;

/**
 * This structure holds the access functions for the variable ecmp_res_manager
 */
typedef struct {
    ecmp_db_info_ecmp_res_manager_set_cb set;
    ecmp_db_info_ecmp_res_manager_get_cb get;
    ecmp_db_info_ecmp_res_manager_create_cb create;
    ecmp_db_info_ecmp_res_manager_allocate_single_cb allocate_single;
    ecmp_db_info_ecmp_res_manager_free_single_cb free_single;
    ecmp_db_info_ecmp_res_manager_is_allocated_cb is_allocated;
    ecmp_db_info_ecmp_res_manager_get_next_cb get_next;
    ecmp_db_info_ecmp_res_manager_print_cb print;
    ecmp_db_info_ecmp_res_manager_advanced_algorithm_info_get_cb advanced_algorithm_info_get;
} ecmp_db_info_ecmp_res_manager_cbs;

/**
 * This structure holds the access functions for the variable ecmp_extended_res_manager
 */
typedef struct {
    ecmp_db_info_ecmp_extended_res_manager_set_cb set;
    ecmp_db_info_ecmp_extended_res_manager_get_cb get;
    ecmp_db_info_ecmp_extended_res_manager_create_cb create;
    ecmp_db_info_ecmp_extended_res_manager_allocate_single_cb allocate_single;
    ecmp_db_info_ecmp_extended_res_manager_free_single_cb free_single;
    ecmp_db_info_ecmp_extended_res_manager_is_allocated_cb is_allocated;
    ecmp_db_info_ecmp_extended_res_manager_get_next_cb get_next;
    ecmp_db_info_ecmp_extended_res_manager_print_cb print;
    ecmp_db_info_ecmp_extended_res_manager_advanced_algorithm_info_get_cb advanced_algorithm_info_get;
} ecmp_db_info_ecmp_extended_res_manager_cbs;

/**
 * This structure holds the access functions for the variable ecmp_user_profile_res_mngr
 */
typedef struct {
    ecmp_db_info_ecmp_user_profile_res_mngr_create_cb create;
    ecmp_db_info_ecmp_user_profile_res_mngr_allocate_single_cb allocate_single;
    ecmp_db_info_ecmp_user_profile_res_mngr_free_single_cb free_single;
    ecmp_db_info_ecmp_user_profile_res_mngr_is_allocated_cb is_allocated;
    ecmp_db_info_ecmp_user_profile_res_mngr_nof_free_elements_get_cb nof_free_elements_get;
    ecmp_db_info_ecmp_user_profile_res_mngr_get_next_cb get_next;
    ecmp_db_info_ecmp_user_profile_res_mngr_print_cb print;
} ecmp_db_info_ecmp_user_profile_res_mngr_cbs;

/**
 * This structure holds the access functions for the variable l3_ecmp_user_profile_t
 */
typedef struct {
    ecmp_db_info_ecmp_user_profile_data_set_cb set;
    ecmp_db_info_ecmp_user_profile_data_get_cb get;
    ecmp_db_info_ecmp_user_profile_data_alloc_cb alloc;
} ecmp_db_info_ecmp_user_profile_data_cbs;

/**
 * This structure holds the access functions for the variable ecmp_fec_members_table
 */
typedef struct {
    ecmp_db_info_ecmp_fec_members_table_set_cb set;
    ecmp_db_info_ecmp_fec_members_table_get_cb get;
    ecmp_db_info_ecmp_fec_members_table_alloc_cb alloc;
} ecmp_db_info_ecmp_fec_members_table_cbs;

/**
 * This structure holds the access functions for the variable ecmp_group_size_minus_one
 */
typedef struct {
    ecmp_db_info_ecmp_group_size_minus_one_set_cb set;
    ecmp_db_info_ecmp_group_size_minus_one_get_cb get;
    ecmp_db_info_ecmp_group_size_minus_one_alloc_cb alloc;
} ecmp_db_info_ecmp_group_size_minus_one_cbs;

/**
 * This structure holds the access functions for the variable ecmp_sw_db_info_t
 */
typedef struct {
    ecmp_db_info_is_init_cb is_init;
    ecmp_db_info_init_cb init;
    /**
     * Access struct for members_tbl_addr_profile_link_lists
     */
    ecmp_db_info_members_tbl_addr_profile_link_lists_cbs members_tbl_addr_profile_link_lists;
    /**
     * Access struct for consistent_hashing_manager_handle
     */
    ecmp_db_info_consistent_hashing_manager_handle_cbs consistent_hashing_manager_handle;
    /**
     * Access struct for ecmp_res_manager
     */
    ecmp_db_info_ecmp_res_manager_cbs ecmp_res_manager;
    /**
     * Access struct for ecmp_extended_res_manager
     */
    ecmp_db_info_ecmp_extended_res_manager_cbs ecmp_extended_res_manager;
    /**
     * Access struct for ecmp_user_profile_res_mngr
     */
    ecmp_db_info_ecmp_user_profile_res_mngr_cbs ecmp_user_profile_res_mngr;
    /**
     * Access struct for ecmp_user_profile_data
     */
    ecmp_db_info_ecmp_user_profile_data_cbs ecmp_user_profile_data;
    /**
     * Access struct for ecmp_fec_members_table
     */
    ecmp_db_info_ecmp_fec_members_table_cbs ecmp_fec_members_table;
    /**
     * Access struct for ecmp_group_size_minus_one
     */
    ecmp_db_info_ecmp_group_size_minus_one_cbs ecmp_group_size_minus_one;
} ecmp_db_info_cbs;

/*
 * Global Variables
 */

/*
 * Global Variables
 */

extern ecmp_db_info_cbs ecmp_db_info;

#endif /* __ECMP_ACCESS_H__ */
