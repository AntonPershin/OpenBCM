/* \file sw_state_htb.h
 *
 * DNX hash table create APIs
 *
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2022 Broadcom Inc. All rights reserved.
 *
 */

#ifndef INCLUDE_SOC_DNXC_SWSTATE_TYPES_SW_STATE_HTB_RB_H_
#define INCLUDE_SOC_DNXC_SWSTATE_TYPES_SW_STATE_HTB_RB_H_

#include <soc/dnxc/swstate/sw_state_features.h>
#include <shared/utilex/utilex_framework.h>
#include <soc/dnxc/swstate/sw_state_defs.h>
#include <soc/dnxc/swstate/dnxc_sw_state.h>
#include <soc/dnxc/swstate/types/sw_state_occupation_bitmap.h>
#include <soc/dnxc/swstate/types/sw_state_cb.h>
#include <shared/bitop.h>
#include <include/soc/dnxc/swstate/types/sw_state_htb_create.h>

#define SW_STATE_HTB_VERIFY_HTB_IS_ACTIVE(htb) \
  { \
    if (htb == NULL) { \
      SHR_SET_CURRENT_ERR(_SHR_E_INTERNAL) ; \
      SHR_EXIT() ; \
    } \
  }

#define SW_STATE_HTB_VERIFY_UNIT_IS_LEGAL(_unit) \
  if (((int)_unit < 0) || (_unit >= SOC_MAX_NUM_DEVICES)) \
  { \
     \
    SHR_SET_CURRENT_ERR(_SHR_E_PARAM) ; \
    SHR_EXIT() ; \
  }

#define SW_STATE_HTB_RH_HASH_ALGORITHM_MAX_NAME_LENGTH 100

#define SW_STATE_HTB_RH_CREATE(node_id, htb, init_info, alloc_flags) \
    SHR_IF_ERR_EXIT(sw_state_htb_rh_create(unit, node_id, &htb, init_info, alloc_flags))

#define SW_STATE_HTB_RH_INSERT(htb, table_idx, key, data) \
    SHR_IF_ERR_EXIT(sw_state_htb_rh_insert(unit, htb, table_idx, (SHR_BITDCL *)key, (SHR_BITDCL *)data))

#define SW_STATE_HTB_RH_REPLACE(htb, table_idx, key, data) \
    SHR_IF_ERR_EXIT(sw_state_htb_rh_replace(unit, htb, table_idx, (SHR_BITDCL *)key, (SHR_BITDCL *)data))

#define SW_STATE_HTB_RH_FIND(htb, table_idx, key, data, offset) \
    SHR_IF_ERR_EXIT(sw_state_htb_rh_find(unit, htb, table_idx,(SHR_BITDCL *)key, (SHR_BITDCL *)data, offset))

#define SW_STATE_HTB_RH_DELETE(htb, table_idx, key) \
    SHR_IF_ERR_EXIT(sw_state_htb_rh_delete(unit, htb, table_idx, (SHR_BITDCL *)key))

#define SW_STATE_HTB_RH_DELETE_ALL(htb) \
    SHR_IF_ERR_EXIT(sw_state_htb_rh_delete_all(unit, htb))

#define SW_STATE_HTB_RH_PRINT(htb) \
    SHR_IF_ERR_EXIT(sw_state_htb_rh_print(unit, htb))

#define SW_STATE_HTB_RH_DEFAULT_PRINT(unit, htb) \
    sw_state_htb_rh_print(unit, *(htb))

typedef shr_error_e(
    *sw_state_htb_traverse_cb) (
    int unit,
    void *key,
    void *data);

typedef struct sw_state_htb_sandbox_s
{
    SHR_BITDCL *key;
    SHR_BITDCL *key_compare;
    SHR_BITDCL *key_swap;

    SHR_BITDCL *encoded_key;
    SHR_BITDCL *data;
    SHR_BITDCL *data_swap;
    SHR_BITDCL *psl;
    SHR_BITDCL *curr_psl;
} sw_state_htb_sandbox_t;

typedef struct
{

    uint32 node_id;

    SHR_BITDCL *metadata;

    uint32 key_size;

    uint32 key_offset;

    uint32 data_size;

    uint32 data_offset;

    uint32 psl_size;

    uint32 psl_offset;

    uint32 metadata_size;

    uint32 max_nof_elements;

    uint32 max_allowed_nof_elements;

    uint32 nof_used_elements;

    uint32 load_factor;

    sw_state_htb_hash_func_e hash_func;

    uint32 flags;

    char print_cb_name[SW_STATE_CB_DB_NAME_STR_SIZE];

    struct sw_state_htb_s *reverse_map;

    sw_state_htb_sandbox_t sandbox;
}  *sw_state_htb_t;

typedef uint32 (
    *sw_state_htb_hashing) (
    int unit,
    sw_state_htb_t htb,
    SHR_BITDCL * const key);

typedef struct
{
    char hash_name[SW_STATE_HTB_RH_HASH_ALGORITHM_MAX_NAME_LENGTH];
    sw_state_htb_hashing hash_cb;
} sw_state_htb_hash_algorithm_cb_t;

shr_error_e sw_state_htb_rh_create(
    int unit,
    uint32 node_id,
    sw_state_htb_t * htb,
    sw_state_htb_create_info_t * create_info,
    uint32 alloc_flags);

shr_error_e sw_state_htb_rh_insert(
    int unit,
    sw_state_htb_t htb,
    uint32 table_idx,
    void *const key,
    void *const data);

shr_error_e sw_state_htb_rh_find(
    int unit,
    sw_state_htb_t htb,
    uint32 table_idx,
    void *const key,
    void *data,
    uint32 *offset);

shr_error_e sw_state_htb_rh_delete(
    int unit,
    sw_state_htb_t htb,
    uint32 table_idx,
    void *const key);

shr_error_e sw_state_htb_traverse(
    int unit,
    sw_state_htb_t htb,
    sw_state_htb_traverse_cb traverse_func);

shr_error_e sw_state_htb_rh_replace(
    int unit,
    sw_state_htb_t htb,
    uint32 table_idx,
    void *const key,
    void *const data);

shr_error_e sw_state_htb_find_reverse(
    int unit,
    sw_state_htb_t htb,
    uint32 table_idx,
    void *const data,
    void *key);

shr_error_e sw_state_htb_rh_print(
    int unit,
    sw_state_htb_t htb);

shr_error_e sw_state_htb_rh_delete_all(
    int unit,
    sw_state_htb_t htb);

#endif
