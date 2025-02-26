/*
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2022 Broadcom Inc. All rights reserved.
 */

/** \file lif_mngr.c
 *
 *  Lif algorithms initialization and deinitialization.
 */

#ifdef BSL_LOG_MODULE
#error "BSL_LOG_MODULE redefined"
#endif
#define BSL_LOG_MODULE BSL_LS_BCMDNX_LIF

/*************
 * INCLUDES  *
 *************/
/*
 * {
 */
#include <soc/sand/shrextend/shrextend_debug.h>
#include <sal/appl/sal.h>
#include <soc/dnx/dnx_data/auto_generated/dnx_data_lif.h>
#include <soc/dnx/dnx_data/auto_generated/dnx_data_l3.h>
#include <bcm_int/dnx/algo/swstate/auto_generated/access/lif_mngr_access.h>
#include <soc/dnx/dbal/dbal.h>
#include <bcm_int/dnx/algo/lif_mngr/lif_mngr.h>
#include <bcm_int/dnx/algo/algo_gpm.h>
#include "global_lif_allocation.h"
#include "lif_mngr_internal.h"
#include "lif_table_mngr.h"
#include "src/soc/dnx/dbal/dbal_internal.h"
#include <bcm_int/dnx/cmn/dnxcmn.h>
#include <soc/dnx/swstate/auto_generated/access/algo_lif_access.h>
#include <soc/dnx/utils/dnx_pp_programmability_utils.h>
#include <soc/dnx/mdb.h>
#include <soc/dnxc/swstate/types/sw_state_htb_create.h>

/*
 * }
 */
/*************
 * DEFINES   *
 *************/
/*
 * {
 */

#define DNX_ALGO_LIF_MNGR_REDUCED_MODE_NOF_LIFS 100

#define DNX_ALGO_LIF_OUTLIF_LOGICAL_STAGE_STRING "LOGICAL_"

#define DNX_ALGO_LIF_MNGR_DPC_LIFS_HASH_TABLE_FACTOR 0.4

/*
 * }
 */
/*************
 * MACROS    *
 *************/
/*
 * {
 */

/*
 * }
 */
/*************
 * TYPE DEFS *
 *************/
/*
 * {
 */
extern shr_error_e dbal_tables_physical_table_get(
    int unit,
    dbal_tables_e table_id,
    int physical_tbl_index,
    dbal_physical_tables_e * physical_table_id);

/*
 * }
 */
/*************
 * GLOBALS   *
 *************/
/*
 * {
 */

/*
 * }
 */
/*************
 * FUNCTIONS *
 *************/
/*
 * {
 */

shr_error_e
dnx_lif_mngr_phase_string_to_id(
    int unit,
    char *logical_phase_str,
    dnx_algo_local_outlif_logical_phase_e * logical_phase)
{
    int logical_phase_index, strlen_input, strlen_logical;

    SHR_FUNC_INIT_VARS(unit);

    strlen_input = sal_strnlen(logical_phase_str, SHR_SAND_DEFAULT_MAX_STRING_OPERATION_LENGTH);
    strlen_logical =
        sal_strnlen(DNX_ALGO_LIF_OUTLIF_LOGICAL_STAGE_STRING, SHR_SAND_DEFAULT_MAX_STRING_OPERATION_LENGTH);
    *logical_phase = DNX_ALGO_LOCAL_OUTLIF_LOGICAL_PHASE_INVALID;

    /*
     * Retrieve the logical phase from the last character of the phase name, 
     * assuming the string prefix is correct 
     */
    if ((strlen_input == (strlen_logical + 1)) &&
        (sal_strncmp(logical_phase_str, DNX_ALGO_LIF_OUTLIF_LOGICAL_STAGE_STRING, strlen_logical) == 0))
    {
        logical_phase_index = logical_phase_str[strlen_logical] - '1';

        if ((logical_phase_index >= DNX_ALGO_LOCAL_OUTLIF_LOGICAL_PHASE_FIRST) &&
            (logical_phase_index < DNX_ALGO_LOCAL_OUTLIF_LOGICAL_PHASE_COUNT))
        {
            *logical_phase = logical_phase_index;
        }
    }

    /*
     * In case the supplied logical phase string is invalid
     */
    if (*logical_phase == DNX_ALGO_LOCAL_OUTLIF_LOGICAL_PHASE_INVALID)
    {
        SHR_ERR_EXIT(_SHR_E_NOT_FOUND, "Error, logical phase not found (%s)\n", logical_phase_str);
    }

exit:
    SHR_FUNC_EXIT;
}

shr_error_e
dnx_lif_mngr_eedb_table_rt_has_linked_list(
    int unit,
    dbal_tables_e table_id,
    int res_type_idx,
    uint8 *has_link_list)
{
    uint8 found_next_ptr = FALSE;
    CONST dbal_logical_table_t *table;

    SHR_FUNC_INIT_VARS(unit);

    SHR_IF_ERR_EXIT(dbal_tables_table_get(unit, table_id, &table));

    if (res_type_idx < 0)
    {
        SHR_ERR_EXIT(_SHR_E_INTERNAL, "result type cannot have negative value at that point (%d)\n", res_type_idx);
    }

    if ((table->access_method == DBAL_ACCESS_METHOD_MDB) && dbal_table_is_out_lif(table))
    {
        if (res_type_idx < table->nof_result_types)
        {
            found_next_ptr = table->multi_res_info[res_type_idx].has_link_list;
        }
        else
        {
            SHR_ERR_EXIT(_SHR_E_INTERNAL, "Illegal result type index %d for table %s. num of result types is %d\n",
                         res_type_idx, table->table_name, table->nof_result_types);
        }
    }
    else
    {
        SHR_ERR_EXIT(_SHR_E_INTERNAL, "API can not called with table which is not EEDB table. table %s.\n",
                     table->table_name);
    }
    *has_link_list = found_next_ptr;

exit:
    SHR_FUNC_EXIT;
}

/*
 * Set table id and result type from SW state
 * by local inlif
 */
shr_error_e
dnx_lif_mngr_inlif_sw_info_table_id_and_result_type_set(
    int unit,
    int local_in_lif,
    int core_id,
    dbal_tables_e table_id,
    uint32 result_type)
{
    dbal_physical_tables_e physical_table_id;
    ingress_lif_info_t ingress_lif_info;

    SHR_FUNC_INIT_VARS(unit);
    DBAL_FUNC_INIT_VARS(unit);

    /*
     * Verify that the configuration is for all the cores
     */
    if ((core_id != _SHR_CORE_ALL))
    {
        SHR_ERR_EXIT(_SHR_E_INTERNAL,
                     "Error: local In-LIF 0x%08X Accessed with wrong core value - %d", local_in_lif, core_id);
    }

    /*
     * format the set data to the SW state structure
     */
    ingress_lif_info.dbal_table_id = table_id;
    ingress_lif_info.dbal_result_type = result_type;

    /*
     * Get the physical table associated with this lif format.
     */
    SHR_IF_ERR_EXIT(dbal_tables_physical_table_get(unit, table_id, DBAL_PHY_DB_DEFAULT_INDEX, &physical_table_id));

    /*
     * Set the appropriate local In-LIF SW State table
     */
    if (LIF_MNGR_DB_IS_INLIF_SBC(unit, physical_table_id))
    {
        SHR_IF_ERR_EXIT(lif_mngr_db.local_lif_info.ingress_lif1.set(unit, local_in_lif, &ingress_lif_info));
    }
    else
    {
        SHR_IF_ERR_EXIT(lif_mngr_db.local_lif_info.ingress_lif2.set(unit, local_in_lif, &ingress_lif_info));
    }

exit:
    DBAL_FUNC_FREE_VARS;
    SHR_FUNC_EXIT;
}

shr_error_e
dnx_lif_mngr_inlif_sw_info_table_id_and_result_type_get(
    int unit,
    int local_in_lif,
    int core_id,
    dbal_physical_tables_e physical_table_id,
    dbal_tables_e * table_id,
    uint32 *result_type)
{
    ingress_lif_info_t ingress_lif_info;

    SHR_FUNC_INIT_VARS(unit);
    DBAL_FUNC_INIT_VARS(unit);

    /*
     * Retrieve the local In-LIF info from the appropriate SW State table
     */

    if (LIF_MNGR_DB_IS_INLIF_SBC(unit, physical_table_id))
    {
        SHR_IF_ERR_EXIT(lif_mngr_db.local_lif_info.ingress_lif1.get(unit, local_in_lif, &ingress_lif_info));
    }
    else
    {
        SHR_IF_ERR_EXIT(lif_mngr_db.local_lif_info.ingress_lif2.get(unit, local_in_lif, &ingress_lif_info));

    }
    if (ingress_lif_info.dbal_table_id == DBAL_TABLE_EMPTY)
    {
        SHR_SET_CURRENT_ERR(_SHR_E_NOT_FOUND);
        SHR_EXIT();
    }

    /*
     * Retrieve the returned parameters from the SW state structure
     */
    SHR_IF_NOT_NULL_FILL(table_id, ingress_lif_info.dbal_table_id);
    SHR_IF_NOT_NULL_FILL(result_type, ingress_lif_info.dbal_result_type);

exit:
    DBAL_FUNC_FREE_VARS;
    SHR_FUNC_EXIT;
}

shr_error_e
dnx_lif_mngr_inlif_sw_info_table_id_and_result_type_delete(
    int unit,
    int core_id,
    uint32 local_in_lif,
    dbal_tables_e table_id)
{
    dbal_physical_tables_e physical_table_id;
    ingress_lif_info_t ingress_lif_info;

    SHR_FUNC_INIT_VARS(unit);
    DBAL_FUNC_INIT_VARS(unit);

    /*
     * Verify that the deltetion is from all the cores
     */
    if (core_id != _SHR_CORE_ALL)
    {
        SHR_ERR_EXIT(_SHR_E_INTERNAL,
                     "Error: local In-LIF 0x%08X Accessed with wrong core value - %d", local_in_lif, core_id);
    }

    /*
     * Get the physical table associated with this lif format.
     */
    SHR_IF_ERR_EXIT(dbal_tables_physical_table_get(unit, table_id, DBAL_PHY_DB_DEFAULT_INDEX, &physical_table_id));

    /*
     * Set the entry to reset values
     */
    ingress_lif_info.dbal_table_id = DBAL_TABLE_EMPTY;
    ingress_lif_info.dbal_result_type = 0;

    /*
     * Reset the entry from the relevant SW State
     */
    if (LIF_MNGR_DB_IS_INLIF_SBC(unit, physical_table_id))
    {
        SHR_IF_ERR_EXIT(lif_mngr_db.local_lif_info.ingress_lif1.set(unit, local_in_lif, &ingress_lif_info));
    }
    else
    {
        SHR_IF_ERR_EXIT(lif_mngr_db.local_lif_info.ingress_lif2.set(unit, local_in_lif, &ingress_lif_info));
    }

exit:
    DBAL_FUNC_FREE_VARS;
    SHR_FUNC_EXIT;
}

/** given inlif returns the related DBAL table, it is done by performing lookup in all the existing hash tables */

shr_error_e
dnx_lif_mngr_outlif_to_dbal_table(
    int unit,
    int local_out_lif,
    dbal_tables_e * dbal_table_id,
    int *hash_table_index,
    egress_lif_info_per_table_t * lif_sw_info)
{
    int index = 0;
    int max_hash_tables;
    int dbal_table_as_int;
    uint8 found;

    SHR_FUNC_INIT_VARS(unit);

    SHR_IF_ERR_EXIT(lif_mngr_db.number_of_outlif_tables.get(unit, &max_hash_tables));

    while (index < max_hash_tables)
    {
        int rv;
        rv = lif_mngr_db.local_lif_info.egress_lif_sw_info_per_table_htb.find(unit, index, &local_out_lif, lif_sw_info);
        SHR_IF_ERR_EXIT_EXCEPT_IF(rv, _SHR_E_NOT_FOUND);
        if (rv == _SHR_E_NONE)
        {
            break;
        }
        index++;
    }

    if (index == max_hash_tables)
    {
        SHR_SET_CURRENT_ERR(_SHR_E_NOT_FOUND);
        SHR_EXIT();
    }

    SHR_IF_ERR_EXIT(lif_mngr_db.local_lif_info.
                    egress_lif_table_to_index_htb.get_by_index(unit, index, &dbal_table_as_int, &found));

    if (!found)
    {
        SHR_ERR_EXIT(_SHR_E_INTERNAL, "Failed to retrieve dbal table from index %d for lif 0x%08X", index,
                     local_out_lif);
    }

    (*hash_table_index) = index;
    (*dbal_table_id) = dbal_table_as_int;

exit:
    SHR_FUNC_EXIT;
}

/** Stores the outlif info in SWSTATE */
shr_error_e
dnx_lif_mngr_outlif_sw_info_add(
    int unit,
    lif_mngr_local_outlif_info_t * outlif_info)
{
    egress_lif_info_t egress_lif_info = { 0 };
    uint8 found, ll_exists = FALSE;
    dnx_local_outlif_ll_indication_e ll_indication = DNX_LOCAL_OUTLIF_LL_OPTIONAL;
    int local_out_lif = outlif_info->local_outlif;
    int result_type;

    SHR_FUNC_INIT_VARS(unit);

    if ((_SHR_IS_FLAG_SET(outlif_info->local_lif_flags, DNX_ALGO_LIF_MNGR_LOCAL_OUTLIF_RESERVE))
        && !(_SHR_IS_FLAG_SET(outlif_info->local_lif_flags, DNX_ALGO_LIF_MNGR_LOCAL_OUTLIF_REPLACE)))
    {
        /*
         * If reserving an entry, then the "active" result type is the alternative one.
         * Write it.
         */
        result_type = outlif_info->alternative_result_type;
    }
    else
    {
        result_type = outlif_info->dbal_result_type;
    }

    /*
     * Retrieve the LL exists indication for the Out-LIF
     */
    if (_SHR_IS_FLAG_SET(outlif_info->local_lif_flags, DNX_ALGO_LIF_MNGR_LOCAL_OUTLIF_FORCE_LINKED_LIST))
    {
        ll_exists = TRUE;
    }
    else if (_SHR_IS_FLAG_SET(outlif_info->local_lif_flags, DNX_ALGO_LIF_MNGR_LOCAL_OUTLIF_NO_LINKED_LIST))
    {
        ll_exists = FALSE;
    }
    else        /* No flag */
    {
        if (!_SHR_IS_FLAG_SET(outlif_info->local_lif_flags, DNX_ALGO_LIF_MNGR_LOCAL_OUTLIF_IGNORE_PHASE_ALLOC_MISMATCH))
        {
            dbal_to_phase_info_t dbal_to_phase_info = { 0 };
            dbal_to_phase_info.dbal_result_type = result_type;
            dbal_to_phase_info.dbal_table = outlif_info->dbal_table_id;
            SHR_IF_ERR_EXIT(local_outlif_info.logical_phase_info.
                            dbal_valid_combinations.find(unit, outlif_info->logical_phase, &dbal_to_phase_info,
                                                         &ll_indication, &found));

            if (!found)
            {
                SHR_ERR_EXIT(_SHR_E_INTERNAL,
                             "entry not found in logical phases hash table: logical table %d, table_id %s, result type %s",
                             outlif_info->logical_phase + 1, dbal_logical_table_to_string(unit,
                                                                                          outlif_info->dbal_table_id),
                             dbal_result_type_to_string(unit, outlif_info->dbal_table_id, result_type));
            }
        }

        if ((ll_indication == DNX_LOCAL_OUTLIF_LL_OPTIONAL) ||
            (_SHR_IS_FLAG_SET
             (outlif_info->local_lif_flags, DNX_ALGO_LIF_MNGR_LOCAL_OUTLIF_IGNORE_PHASE_ALLOC_MISMATCH)))
        {
            SHR_IF_ERR_EXIT(dnx_lif_mngr_eedb_table_rt_has_linked_list
                            (unit, outlif_info->dbal_table_id, result_type, &ll_exists));
        }
        else if (ll_indication == DNX_LOCAL_OUTLIF_LL_ALWAYS)
        {
            ll_exists = TRUE;
        }
        else if (ll_indication == DNX_LOCAL_OUTLIF_LL_NEVER)
        {
            ll_exists = FALSE;
        }
    }

    egress_lif_info.logical_phase = outlif_info->logical_phase;
    egress_lif_info.dbal_table_id = outlif_info->dbal_table_id;
    egress_lif_info.dbal_result_type = result_type;
    egress_lif_info.ll_exists = ll_exists;

    /*
     * Insert the entry to the SW DB
     */
    SHR_IF_ERR_EXIT(lif_mngr_db.local_lif_info.egress_lif_htb.insert(unit, &local_out_lif, &egress_lif_info, &found));
    if (!found)
    {
        SHR_ERR_EXIT(_SHR_E_INTERNAL, "Error: Failed to store LIF manager info for local Out-LIF 0x%08X, found - %d",
                     local_out_lif, found);
    }

#if 0
    {
        int dbal_table_as_int = outlif_info->dbal_table_id;
        uint32 index;
        egress_lif_info_per_table_t lif_sw_info = { 0 };

        lif_sw_info.dbal_result_type = result_type;
        lif_sw_info.ll_exists = ll_exists;
        lif_sw_info.logical_phase = outlif_info->logical_phase;
        SHR_IF_ERR_EXIT(lif_mngr_db.local_lif_info.
                        egress_lif_table_to_index_htb.find(unit, &dbal_table_as_int, &index, &found));
        if (!found)
        {
            SHR_ERR_EXIT(_SHR_E_INTERNAL,
                         "entry not found in egress_lif_table_to_index_htb: table %d, table_id %s, result type %s",
                         outlif_info->dbal_table_id, dbal_logical_table_to_string(unit, outlif_info->dbal_table_id),
                         dbal_result_type_to_string(unit, outlif_info->dbal_table_id, result_type));
        }
        SHR_IF_ERR_EXIT(lif_mngr_db.local_lif_info.
                        egress_lif_sw_info_per_table_htb.insert(unit, index, &local_out_lif, &lif_sw_info));
        SHR_EXIT();
    }
#endif

exit:
    SHR_FUNC_EXIT;
}

shr_error_e
dnx_lif_mngr_outlif_sw_info_get(
    int unit,
    int local_out_lif,
    dbal_tables_e * dbal_table_id,
    uint32 *result_type,
    dnx_algo_local_outlif_logical_phase_e * logical_phase,
    uint32 *fixed_entry_size,
    uint8 *has_ll,
    uint8 *is_count_profile)
{
    egress_lif_info_t egress_lif_info = { 0 };
    uint8 found;

    SHR_FUNC_INIT_VARS(unit);

    /*
     * Retrieve the entry from the SW DB
     */
    SHR_IF_ERR_EXIT(lif_mngr_db.local_lif_info.egress_lif_htb.find(unit, &local_out_lif, &egress_lif_info, &found));
    if (!found)
    {
        SHR_SET_CURRENT_ERR(_SHR_E_NOT_FOUND);
        SHR_EXIT();
    }

    /*
     * Format the requested fields from the SW DB structure
     */
    SHR_IF_NOT_NULL_FILL(dbal_table_id, egress_lif_info.dbal_table_id);
    SHR_IF_NOT_NULL_FILL(result_type, egress_lif_info.dbal_result_type);
    SHR_IF_NOT_NULL_FILL(has_ll, egress_lif_info.ll_exists);
    SHR_IF_NOT_NULL_FILL(is_count_profile, egress_lif_info.stat_pp_etpp_is_count_profile);
    SHR_IF_NOT_NULL_FILL(fixed_entry_size, 0);
    SHR_IF_NOT_NULL_FILL(logical_phase, egress_lif_info.logical_phase);

exit:
    SHR_FUNC_EXIT;
}

shr_error_e
dnx_lif_mngr_outlif_sw_info_delete(
    int unit,
    int local_out_lif,
    dbal_tables_e optional_dbal_table_id)
{
    SHR_FUNC_INIT_VARS(unit);

    /*
     * Delete the entry from the SW DB
     */
    SHR_IF_ERR_EXIT(lif_mngr_db.local_lif_info.egress_lif_htb.delete(unit, &local_out_lif));

exit:
    SHR_FUNC_EXIT;
}

shr_error_e
dnx_lif_mngr_outlif_sw_info_is_count_profile_set(
    int unit,
    int local_out_lif,
    dbal_tables_e dbal_table_id)
{
    egress_lif_info_t egress_lif_info = { 0 };
    uint8 found;
    SHR_FUNC_INIT_VARS(unit);

    /*
     * Retrieve the local Out-LIF information
     */
    SHR_IF_ERR_EXIT(lif_mngr_db.local_lif_info.egress_lif_htb.find(unit, &local_out_lif, &egress_lif_info, &found));
    if (!found)
    {
        SHR_ERR_EXIT(_SHR_E_NOT_FOUND,
                     "Error: Failed to retrieve LIF manager info for local Out-LIF 0x%08X, found - %d", local_out_lif,
                     found);
    }

    /*
     * Add an entry for the local Out-LIF information, updated with is_count_profile indication
     */
    egress_lif_info.stat_pp_etpp_is_count_profile = TRUE;
    SHR_IF_ERR_EXIT(lif_mngr_db.local_lif_info.egress_lif_htb.insert(unit, &local_out_lif, &egress_lif_info, &found));
    if (!found)
    {
        SHR_ERR_EXIT(_SHR_E_INTERNAL, "Error: Failed to insert LIF manager info for local Out-LIF 0x%08X, found - %d",
                     local_out_lif, found);
    }

exit:
    SHR_FUNC_EXIT;
}

#if 0
shr_error_e
dnx_lif_mngr_outlif_sw_info_get(
    int unit,
    int local_out_lif,
    dbal_tables_e * dbal_table_id,
    uint32 *result_type,
    dnx_algo_local_outlif_logical_phase_e * logical_phase,
    uint32 *fixed_entry_size,
    uint8 *has_ll,
    uint8 *is_count_profile)
{
    uint32 index;
    egress_lif_info_per_table_t lif_sw_info = { 0 };

    SHR_FUNC_INIT_VARS(unit);

    if (dbal_table_id && ((*dbal_table_id) != DBAL_TABLE_EMPTY) && ((*dbal_table_id) < DBAL_NOF_TABLES))
    {
        int dbal_table_as_int = (*dbal_table_id);
        uint8 found;
        SHR_IF_ERR_EXIT(lif_mngr_db.local_lif_info.
                        egress_lif_table_to_index_htb.find(unit, &dbal_table_as_int, &index, &found));
        if (!found)
        {
            SHR_ERR_EXIT(_SHR_E_INTERNAL,
                         "entry not found in egress_lif_table_to_index_htb: logical table %d, table_id %s",
                         (*dbal_table_id), dbal_logical_table_to_string(unit, (*dbal_table_id)));
        }
        SHR_IF_ERR_EXIT(lif_mngr_db.local_lif_info.
                        egress_lif_sw_info_per_table_htb.find(unit, index, &local_out_lif, &lif_sw_info));
    }
    else
    {
        int hash_table_index;
        SHR_IF_ERR_EXIT_WITH_MSG_EXCEPT_IF(dnx_lif_mngr_outlif_to_dbal_table
                                           (unit, local_out_lif, dbal_table_id, &hash_table_index, &lif_sw_info),
                                           _SHR_E_NOT_FOUND);
        index = hash_table_index;
    }

    SHR_IF_NOT_NULL_FILL(result_type, lif_sw_info.dbal_result_type);
    SHR_IF_NOT_NULL_FILL(has_ll, lif_sw_info.ll_exists);
    SHR_IF_NOT_NULL_FILL(is_count_profile, lif_sw_info.stat_pp_etpp_is_count_profile);
    SHR_IF_NOT_NULL_FILL(fixed_entry_size, 0);
    SHR_IF_NOT_NULL_FILL(logical_phase, lif_sw_info.logical_phase);

exit:
    SHR_FUNC_EXIT;
}

shr_error_e
dnx_lif_mngr_outlif_sw_info_delete(
    int unit,
    int local_out_lif,
    dbal_tables_e optional_dbal_table_id)
{
    uint32 hash_tbl_idx = optional_dbal_table_id;

    SHR_FUNC_INIT_VARS(unit);

    if (optional_dbal_table_id == DBAL_TABLE_EMPTY)
    {
        int hash_table_index;
        egress_lif_info_per_table_t lif_sw_info = { 0 };

        SHR_IF_ERR_EXIT_WITH_MSG_EXCEPT_IF(dnx_lif_mngr_outlif_to_dbal_table
                                           (unit, local_out_lif, &optional_dbal_table_id, &hash_table_index,
                                            &lif_sw_info), _SHR_E_NOT_FOUND);
        hash_tbl_idx = hash_table_index;
    }
    else
    {
        uint8 found;
        int dbal_table_as_int = optional_dbal_table_id;
        SHR_IF_ERR_EXIT(lif_mngr_db.local_lif_info.
                        egress_lif_table_to_index_htb.find(unit, &dbal_table_as_int, &hash_tbl_idx, &found));
        if (!found)
        {
            SHR_SET_CURRENT_ERR(_SHR_E_NOT_FOUND);
            SHR_EXIT();
        }
    }

    SHR_IF_ERR_EXIT(lif_mngr_db.local_lif_info.
                    egress_lif_sw_info_per_table_htb.delete(unit, hash_tbl_idx, &local_out_lif));

exit:
    SHR_FUNC_EXIT;
}

shr_error_e
dnx_lif_mngr_outlif_sw_info_is_count_profile_set(
    int unit,
    int local_out_lif,
    dbal_tables_e dbal_table_id)
{
    uint8 found;
    int dbal_table_as_int = (dbal_table_id);
    uint32 index;
    egress_lif_info_per_table_t lif_sw_info = { 0 };

    SHR_FUNC_INIT_VARS(unit);

    SHR_IF_ERR_EXIT(lif_mngr_db.local_lif_info.
                    egress_lif_table_to_index_htb.find(unit, &dbal_table_as_int, &index, &found));
    if (!found)
    {
        SHR_ERR_EXIT(_SHR_E_INTERNAL,
                     "entry not found in egress_lif_table_to_index_htb: logical table %d, table_id %s",
                     (dbal_table_id), dbal_logical_table_to_string(unit, (dbal_table_id)));
    }
    SHR_IF_ERR_EXIT(lif_mngr_db.local_lif_info.
                    egress_lif_sw_info_per_table_htb.find(unit, index, &local_out_lif, &lif_sw_info));
    lif_sw_info.stat_pp_etpp_is_count_profile = TRUE;

    SHR_IF_ERR_EXIT(lif_mngr_db.local_lif_info.
                    egress_lif_sw_info_per_table_htb.replace(unit, index, &local_out_lif, &lif_sw_info));

exit:
    SHR_FUNC_EXIT;
}
#endif

/**
 * \brief - Verify inlif info struct: \ref lif_mngr_local_inlif_info_t.
 *  By default, all fields are always checked, according to the dbal/device data legal values.
 *
 *  This functions assumes that for DPC lifs all core id options are legal, so if only a specific
 *  core is required, it must be checked outside this function.
 *
 *  The field 'dbal_result_type' is not required in most APIs that use this sturct, and it can be set
 *     to 0 if it's not required.
 *
 * \param [in] unit - Identifier of the device to access.
 * \param [in] ignore_id  - If this boolean arguemnt is TRUE, then the 'local_inlif' field of 'inlif_info' \n
 *                          will not be verified.
 * \param [in] inlif_info - The fields in this struct will be checked as described above. \n
 *                          See \ref lif_mngr_local_inlif_info_t for description of specific fields.
 *
 * \return
 *   shr_error_e
 *
 * \remark
 *   * None
 * \see
 *   lif_mngr_local_inlif_info_t
 */
static shr_error_e
dnx_lif_mngr_local_inlif_info_verify(
    int unit,
    int ignore_id,
    lif_mngr_local_inlif_info_t * inlif_info)
{
    dbal_physical_tables_e physical_table_id;
    int is_replace, is_reserve;
    int entry_size_bits;

    SHR_FUNC_INIT_VARS(unit);

    SHR_NULL_CHECK(inlif_info, _SHR_E_INTERNAL, "inlif_info");

    /*
     * Verify the REPLACE and RESERVE flags.
     */
    is_reserve = _SHR_IS_FLAG_SET(inlif_info->local_lif_flags, DNX_ALGO_LIF_MNGR_LOCAL_INLIF_RESERVE);
    is_replace = _SHR_IS_FLAG_SET(inlif_info->local_lif_flags, DNX_ALGO_LIF_MNGR_LOCAL_INLIF_REPLACE);

    if (is_reserve || is_replace)
    {
        /**Verify only if old_result type is not 0*/
        if (inlif_info->old_result_type != 0)
        {
            /*
             * Verify alternative result type.
             */
            SHR_IF_ERR_EXIT(dbal_tables_payload_size_get
                            (unit, inlif_info->dbal_table_id, inlif_info->old_result_type, &entry_size_bits));
        }

    }

    /*
     * Get the physical table associated with this lif format. The physical table will tell us
     *  whether it's a DPC or SBC lif table.
     */
    SHR_IF_ERR_EXIT(dbal_tables_physical_table_get(unit, inlif_info->dbal_table_id, DBAL_PHY_DB_DEFAULT_INDEX,
                                                   &physical_table_id));

    if (LIF_MNGR_DB_IS_INLIF_SBC(unit, physical_table_id))
    {
        /*
         * This is the SBC table. Verify that core is _SHR_CORE_ALL.
         */
        if (inlif_info->core_id != _SHR_CORE_ALL)
        {
            SHR_ERR_EXIT(_SHR_E_INTERNAL,
                         "Dbal logical table %s is shared by cores, so core_id must be _SHR_CORE_ALL. Given %d.",
                         dbal_logical_table_to_string(unit, inlif_info->dbal_table_id), inlif_info->core_id);
        }

        if (ignore_id == FALSE)
        {
            /*
             * If required, verify that lif id in index 0 is legal.
             * We only check this ID because this is the ID shared by cores inlif table is using.
             * Lif IDs in different array indexes are not used.
             */
            LIF_MNGR_LOCAL_SBC_IN_LIF_VERIFY(unit, inlif_info->local_inlif);
        }
    }
    else if (LIF_MNGR_DB_IS_INLIF_DPC(unit, physical_table_id))
    {
        /*
         * This is a DPC table, so just verify that the core is legal. _SHR_CORE_ALL is also legal.
         */
        DNXCMN_CORE_VALIDATE(unit, inlif_info->core_id, TRUE);

        if (ignore_id == FALSE)
        {
            uint8 is_allocated_on_all_cores;
            /*
             * Check that the lif id is legal, and that it's either allocated on all cores or on a single core, and compare it to
             * the input.
             */
            LIF_MNGR_LOCAL_DPC_IN_LIF_VERIFY(unit, inlif_info->local_inlif);
            /*
             * For save memory, inlif_table_dpc_all_cores_indication resource isn't allocated
             */
            if (DNXCMN_CHIP_IS_MULTI_CORE(unit))
            {
                SHR_IF_ERR_EXIT(lif_mngr_db.local_inlif.
                                inlif_table_dpc_all_cores_indication.bit_get(unit, inlif_info->local_inlif,
                                                                             &is_allocated_on_all_cores));
            }
            else
            {
                is_allocated_on_all_cores = 1;
            }

            if (!is_allocated_on_all_cores && inlif_info->core_id == _SHR_CORE_ALL)
            {
                SHR_ERR_EXIT(_SHR_E_INTERNAL,
                             "Inlif is indicated to be allocated on all cores, but it's actually allocated"
                             "on every core separately.");
            }
            else if (is_allocated_on_all_cores && inlif_info->core_id != _SHR_CORE_ALL)
            {
                SHR_ERR_EXIT(_SHR_E_INTERNAL,
                             "Inlif is indicated to be allocated only on core %d, but it's actually allocated"
                             "on all cores at once.", inlif_info->core_id);

            }
        }
    }
    else
    {
        SHR_ERR_EXIT(_SHR_E_INTERNAL, "Wrong dbal logical table: %s",
                     dbal_logical_table_to_string(unit, inlif_info->dbal_table_id));
    }

    /*
     * Only check result type if it's > 0, otherwise it's always legal.
     */
    if (inlif_info->dbal_result_type != 0)
    {
        /*
         * Calling the get function is enough, because it has a built in error indication if the result type
         * is illegal.
         */
        SHR_IF_ERR_EXIT(dbal_tables_payload_size_get
                        (unit, inlif_info->dbal_table_id, inlif_info->dbal_result_type, &entry_size_bits));
    }

exit:
    SHR_FUNC_EXIT;
}

/**
 * \brief - Verify out info struct: \ref lif_mngr_local_outlif_info_t.
 *  By default, all fields are always checked, according to the dbal/device data legal values.
 *
 *  The field 'dbal_result_type' is not required in most APIs that use this sturct, and it can be set
 *     to 0 if it's not required.
 *
 * \param [in] unit - Identifier of the device to access.
 * \param [in] ignore_id - If this boolean arguemnt is TRUE, then the 'local_outlif' field of 'outlif_info' \n
 *                          will not be verified.
 * \param [in] outlif_info - The fields in this struct will be checked as described above. \n
 *                          See \ref lif_mngr_local_outlif_info_t for description of specific fields.
 * \param [in] outlif_hw_info - This struct will be NULL checked. \n
 *
 * \return
 *   shr_error_e
 *
 * \remark
 *   * None
 * \see
 *   lif_mngr_local_outlif_info_t
 */
static shr_error_e
dnx_lif_mngr_local_outlif_info_verify(
    int unit,
    int ignore_id,
    lif_mngr_local_outlif_info_t * outlif_info,
    dnx_algo_local_outlif_hw_info_t * outlif_hw_info)
{
    dbal_physical_tables_e physical_table_id;
    dnx_algo_local_outlif_logical_phase_e outlif_logical_phase;
    int is_reserve, is_replace;
    int entry_size_bits;
    uint8 found;
    dnx_local_outlif_ll_indication_e ll_indication;

    SHR_FUNC_INIT_VARS(unit);

    SHR_NULL_CHECK(outlif_info, _SHR_E_INTERNAL, "outlif_info");
    SHR_NULL_CHECK(outlif_hw_info, _SHR_E_INTERNAL, "outlif_hw_info");

    /*
     * Check outlif phase.
     * Calling the get function is enough, because it has a built in error indication if the no phase mapping
     * was found.
     */
    outlif_logical_phase = outlif_info->logical_phase;

    if (!_SHR_IS_FLAG_SET(outlif_info->local_lif_flags, DNX_ALGO_LIF_MNGR_LOCAL_OUTLIF_IGNORE_PHASE_ALLOC_MISMATCH))
    {
        /*
         * Verify {logical phase, dbal table, result type} valid combinations
         */
        dbal_to_phase_info_t dbal_to_phase_info = { 0 };
        dbal_to_phase_info.dbal_result_type = outlif_info->dbal_result_type;
        dbal_to_phase_info.dbal_table = outlif_info->dbal_table_id;
        SHR_IF_ERR_EXIT(local_outlif_info.logical_phase_info.
                        dbal_valid_combinations.find(unit, outlif_logical_phase, &dbal_to_phase_info, &ll_indication,
                                                     &found));

        if (found == 0)
        {
            SHR_ERR_EXIT(_SHR_E_INTERNAL, "For logical phase %d, the combination: {%s,%s} is not valid",
                         outlif_logical_phase + 1, dbal_logical_table_to_string(unit, outlif_info->dbal_table_id),
                         dbal_result_type_to_string(unit, outlif_info->dbal_table_id, outlif_info->dbal_result_type));
        }

        if (ll_indication != DNX_LOCAL_OUTLIF_LL_OPTIONAL)
        {
            if ((_SHR_IS_FLAG_SET(outlif_info->local_lif_flags, DNX_ALGO_LIF_MNGR_LOCAL_OUTLIF_FORCE_LINKED_LIST))
                && (ll_indication == DNX_LOCAL_OUTLIF_LL_NEVER))
            {
                SHR_ERR_EXIT(_SHR_E_INTERNAL,
                             "DNX_ALGO_LIF_MNGR_LOCAL_OUTLIF_FORCE_LINKED_LIST flag is set but for phsae %d: {%s, %s} link list indication is set to NEVER",
                             outlif_logical_phase, dbal_logical_table_to_string(unit, outlif_info->dbal_table_id),
                             dbal_result_type_to_string(unit, outlif_info->dbal_table_id,
                                                        outlif_info->dbal_result_type));
            }
            if ((_SHR_IS_FLAG_SET(outlif_info->local_lif_flags, DNX_ALGO_LIF_MNGR_LOCAL_OUTLIF_NO_LINKED_LIST))
                && (ll_indication == DNX_LOCAL_OUTLIF_LL_ALWAYS))
            {
                dbal_table_field_info_t field_info;
                int rv;

                /*
                 * Special case - no next pointer field, but we force link list usage 
                 */
                rv = dbal_tables_field_info_get_no_err(unit, outlif_info->dbal_table_id, DBAL_FIELD_NEXT_OUTLIF_POINTER,
                                                       0, outlif_info->dbal_result_type, 0, &field_info);

                if (rv == _SHR_E_NONE)
                {
                    SHR_ERR_EXIT(_SHR_E_INTERNAL,
                                 "DNX_ALGO_LIF_MNGR_LOCAL_OUTLIF_NO_LINKED_LIST flag is set but for phsae %d: {%s, %s} link list indication is set to ALWAYS",
                                 outlif_logical_phase, dbal_logical_table_to_string(unit, outlif_info->dbal_table_id),
                                 dbal_result_type_to_string(unit, outlif_info->dbal_table_id,
                                                            outlif_info->dbal_result_type));
                }
            }
        }
    }

    /*
     * Get the physical table associated with this lif format. Verify that the physical table is EEDB.
     */
    SHR_IF_ERR_EXIT(dbal_tables_physical_table_get(unit, outlif_info->dbal_table_id, DBAL_PHY_DB_DEFAULT_INDEX,
                                                   &physical_table_id));

    if (physical_table_id != DBAL_PHYSICAL_TABLE_EEDB_1
        && physical_table_id != DBAL_PHYSICAL_TABLE_EEDB_2
        && physical_table_id != DBAL_PHYSICAL_TABLE_EEDB_3 && physical_table_id != DBAL_PHYSICAL_TABLE_EEDB_4
        && physical_table_id != DBAL_PHYSICAL_TABLE_EEDB_5 && physical_table_id != DBAL_PHYSICAL_TABLE_EEDB_6
        && physical_table_id != DBAL_PHYSICAL_TABLE_EEDB_7 && physical_table_id != DBAL_PHYSICAL_TABLE_EEDB_8)
    {
        SHR_ERR_EXIT(_SHR_E_INTERNAL, "Wrong dbal logical table: %s",
                     dbal_logical_table_to_string(unit, outlif_info->dbal_table_id));
    }

    /*
     * Only check result type if it's >0, otherwise it's not interesting.
     */
    if (outlif_info->dbal_result_type != 0)
    {
        /*
         * Calling the get function is enough, because it has a built in error indication if the result type
         * is illegal.
         */
        SHR_IF_ERR_EXIT(dbal_tables_payload_size_get
                        (unit, outlif_info->dbal_table_id, outlif_info->dbal_result_type, &entry_size_bits));
    }

    /*
     * Verify the REPLACE and RESERVE flags.
     */
    is_reserve = _SHR_IS_FLAG_SET(outlif_info->local_lif_flags, DNX_ALGO_LIF_MNGR_LOCAL_OUTLIF_RESERVE);
    is_replace = _SHR_IS_FLAG_SET(outlif_info->local_lif_flags, DNX_ALGO_LIF_MNGR_LOCAL_OUTLIF_REPLACE);

    if (is_reserve && is_replace)
    {
        int ll_match;
        /*
         * Verify alternative result type.
         */
        SHR_IF_ERR_EXIT(dbal_tables_payload_size_get
                        (unit, outlif_info->dbal_table_id, outlif_info->alternative_result_type, &entry_size_bits));

        /*
         * Verify ll match.
         */
        SHR_IF_ERR_EXIT(dnx_algo_local_outlif_ll_match_check(unit, outlif_info, &ll_match));

        /*
         * Internal lif manager restriction
         * We don't allow ll mismatch, in case the new lif consumes more entries than the original one, and the new lif doesn't have a
         * ll and the original did. This might cause hanging lifs, which have nothing pointing at them
         */
        if ((!ll_match)
            &&
            (!_SHR_IS_FLAG_SET
             (outlif_info->local_lif_flags, DNX_ALGO_LIF_MNGR_LOCAL_OUTLIF_REPLACE_ALLOW_LL_MISMIATCH)))
        {
            SHR_ERR_EXIT(_SHR_E_INTERNAL,
                         "Can't have a new result type with linked list and old type without linked list, in case the new result type requires more entries than the original one (and a new lif id).");
        }

    }

    if (!ignore_id)
    {
        LIF_MNGR_LOCAL_OUT_LIF_VERIFY(unit, outlif_info->local_outlif);
    }

exit:
    SHR_FUNC_EXIT;
}

/*
 * Verification fuction for dnx_lif_mngr_lif_allocate.
 * Note - it's possible to verify the global lif id if the WITH_ID flag was given,
 *  but we currently skip it because it's checked in the main function by calling the global lif
 *  verify function.
 */
static shr_error_e
dnx_lif_mngr_lif_allocate_verify(
    int unit,
    uint32 flags,
    lif_mngr_global_lif_info_t * global_lif_info,
    lif_mngr_local_inlif_info_t * inlif_info,
    lif_mngr_local_outlif_info_t * outlif_info,
    dnx_algo_local_outlif_hw_info_t * outlif_hw_info)
{
    int is_ingress, is_egress, dont_allocate_global_lif;
    SHR_FUNC_INIT_VARS(unit);

    dont_allocate_global_lif = _SHR_IS_FLAG_SET(flags, LIF_MNGR_DONT_ALLOCATE_GLOBAL_LIF);

    is_ingress = (inlif_info != NULL);
    is_egress = (outlif_info != NULL);

    if (!dont_allocate_global_lif)
    {
        SHR_NULL_CHECK(global_lif_info, _SHR_E_INTERNAL, "global_lif_info");
    }

    if ((!is_ingress) && (!is_egress))
    {
        /*
         * A lif can be either an inlif or an outlif, or both (symmetric). If neither side is given as
         *   input, then the lif has no meaning.
         */
        SHR_ERR_EXIT(_SHR_E_INTERNAL, "At least one of inlif_info or outlif_info must be not NULL.");
    }

    if (is_ingress && is_egress && dont_allocate_global_lif)
    {
        /*
         * If there's no global lif, then allocating both ingress and egress global lifs is meaningless,
         * since without global lifs they can't be symmetric. Instead, allocate them in two separate calls.
         */
        SHR_ERR_EXIT(_SHR_E_INTERNAL,
                     "If don't allocate global lif was indicated, only one direction (ingress or egress) "
                     "can be used.");
    }

    /*
     * Verify inlif info.
     */
    if ((is_ingress) && (!dnx_data_lif.in_lif.feature_get(unit, dnx_data_lif_in_lif_phy_db_dpc)))
    {
        /*
         * We set the argument 'ignore_ids' to TRUE because local lifs can't be allocated WITH_ID,
         * so the IDs are ignored and shouldn't be verified.
         */
        SHR_IF_ERR_EXIT(dnx_lif_mngr_local_inlif_info_verify(unit, TRUE, inlif_info));
    }

    /*
     * Verify outlif info.
     */
    if (is_egress)
    {
        /*
         * We set the argument 'ignore_ids' to TRUE because local lifs can't be allocated WITH_ID,
         * so the IDs are ignored and shouldn't be verified.
         */
        SHR_IF_ERR_EXIT(dnx_lif_mngr_local_outlif_info_verify(unit, TRUE, outlif_info, outlif_hw_info));
    }

exit:
    SHR_FUNC_EXIT;
}

shr_error_e
dnx_lif_mngr_lif_allocate(
    int unit,
    uint32 flags,
    lif_mngr_global_lif_info_t * global_lif_info,
    lif_mngr_local_inlif_info_t * inlif_info,
    lif_mngr_local_outlif_info_t * outlif_info,
    dnx_algo_local_outlif_hw_info_t * outlif_hw_info)
{
    int global_lif_tmp;
    /*
     * The is_ingress, is_egress flags are used to indicate whether we'll allocate ingress/egress lifs in this function.
     * In some cases, we might choose not to allocate the egress global lif. In this case, the allocate_egress_global_lif flags
     * will be set to FALSE.
     */
    int is_ingress, is_egress, allocate_global_lif;
    uint32 global_lif_allocation_flags, global_lif_direction_flags;
    lif_mapping_local_lif_payload_t local_lif_payload;
    uint32 dbal_result_type;

    SHR_FUNC_INIT_VARS(unit);

    /*
     * Step 0: Verify input and set allocation flags.
     *
     * Verify local lif info. We verify global lif info below so we don't need to calculate all the
     * flags twice.
     */
    SHR_INVOKE_VERIFY_DNXC(dnx_lif_mngr_lif_allocate_verify
                           (unit, flags, global_lif_info, inlif_info, outlif_info, outlif_hw_info));

    is_ingress = (inlif_info != NULL);
    is_egress = (outlif_info != NULL);
    global_lif_allocation_flags = 0;
    global_lif_direction_flags = 0;

    /*
     * Don't allocate egress global lif if don't allocate global lif flag is set.
     */
    allocate_global_lif = !_SHR_IS_FLAG_SET(flags, LIF_MNGR_DONT_ALLOCATE_GLOBAL_LIF);

    if (allocate_global_lif)
    {
        /*
         * Take only the flags relevant for global lif allocation.
         */
        global_lif_allocation_flags |=
            (flags &
             (LIF_MNGR_GLOBAL_LIF_WITH_ID | LIF_MNGR_L2_GPORT_GLOBAL_LIF | LIF_MNGR_ONE_SIDED_SYMMETRIC_GLOBAL_LIF));

        /*
         * Set DNX_ALGO_LIF_INGRESS/EGRESS flags according to the required allocation.
         */
        global_lif_direction_flags = DNX_ALGO_GLOBAL_LIF_ALLOCATION_SET_DIRECTION_FLAGS(is_ingress, is_egress);

        /*
         * We use a temporary variable for global lif throughout the function for code simplicity.
         */
        global_lif_tmp = global_lif_info->global_lif;
    }

    /*
     * Step 1: Allocate lifs.
     *
     */

    /*
     * Allocate local inlif.
     */
    if ((is_ingress) && (!dnx_data_lif.in_lif.feature_get(unit, dnx_data_lif_in_lif_phy_db_dpc)))
    {
        /*
         * Allocate.
         */
        SHR_IF_ERR_EXIT(dnx_algo_local_inlif_allocate(unit, inlif_info));
    }

    /*
     * Allocate local outlif.
     */
    if (is_egress)
    {
        /*
         * Allocate.
         */
        SHR_IF_ERR_EXIT(dnx_algo_local_outlif_allocate(unit, outlif_info, outlif_hw_info));
    }

    /*
     * Allocate global lif.
     */
    if (allocate_global_lif)
    {
        global_lif_alloc_info_t alloc_info = { 0 };

        alloc_info.bta = global_lif_info->bta;
        alloc_info.outlif_intf = global_lif_info->outlif_intf;
        if (is_egress && dnx_data_lif.global_lif.global_lif_group_max_val_get(unit))
        {
        }
        SHR_IF_ERR_EXIT(dnx_algo_global_lif_allocation_allocate(unit, global_lif_allocation_flags,
                                                                global_lif_direction_flags, &alloc_info,
                                                                &global_lif_tmp));

        global_lif_info->global_lif = global_lif_tmp;
    }
    else
    {
        /*
         * If no global lif was required, then if the user even passed a global lif pointer, fill it
         * with invalid indication.
         */
        if (global_lif_info)
        {
            global_lif_info->global_lif = LIF_MNGR_INVALID;
        }
    }

    /*
     * Step 2: Create lif mapping.
     */
    if (is_ingress && allocate_global_lif)
    {
        /*
         * Create ingress mapping.
         */
        sal_memset(&local_lif_payload, 0, sizeof(local_lif_payload));
        local_lif_payload.local_lifs_array.local_lifs[0] = inlif_info->local_inlif;

        SHR_IF_ERR_EXIT(dbal_tables_physical_table_get(unit, inlif_info->dbal_table_id, DBAL_PHY_DB_DEFAULT_INDEX,
                                                       &local_lif_payload.phy_table));

        SHR_IF_ERR_EXIT(dnx_algo_lif_mapping_create
                        (unit, DNX_ALGO_LIF_INGRESS, global_lif_tmp, &local_lif_payload, TRUE));
    }

    if (is_egress && allocate_global_lif)
    {
        /*
         * Create egress mapping.
         * Don't do it if we didn't allocate egress global lif.
         */
        sal_memset(&local_lif_payload, 0, sizeof(local_lif_payload));
        local_lif_payload.local_lifs_array.local_lifs[0] = outlif_info->local_outlif;
        SHR_IF_ERR_EXIT(dnx_algo_lif_mapping_create
                        (unit, DNX_ALGO_LIF_EGRESS, global_lif_tmp, &local_lif_payload, TRUE));
    }

    /*
     * Step 3: Save LIF TABLE DBAL ID and type in SW state.
     */
    if (is_ingress)
    {
        if ((_SHR_IS_FLAG_SET(inlif_info->local_lif_flags, DNX_ALGO_LIF_MNGR_LOCAL_INLIF_RESERVE))
            && !(_SHR_IS_FLAG_SET(inlif_info->local_lif_flags, DNX_ALGO_LIF_MNGR_LOCAL_INLIF_REPLACE)))
        {
            /*
             * If reserving an entry, then the "active" result type is the old one.
             * Write it.
             */
            dbal_result_type = inlif_info->old_result_type;
        }
        else
        {
            dbal_result_type = inlif_info->dbal_result_type;
        }

        if (_SHR_IS_FLAG_SET(inlif_info->local_lif_flags, DNX_ALGO_LIF_MNGR_LOCAL_INLIF_REPLACE))
        {
            /*
             * If the replace flag is set, then remove the old result type before writing the new one.
             */
            SHR_IF_ERR_EXIT(dnx_lif_mngr_inlif_sw_info_table_id_and_result_type_delete
                            (unit, inlif_info->core_id, inlif_info->local_inlif, inlif_info->dbal_table_id));
        }

        /*
         * Store info in SW state
         */
        SHR_IF_ERR_EXIT(dnx_lif_mngr_inlif_sw_info_table_id_and_result_type_set
                        (unit, inlif_info->local_inlif, inlif_info->core_id, inlif_info->dbal_table_id,
                         dbal_result_type));
    }
    if (is_egress)
    {
        if (_SHR_IS_FLAG_SET(outlif_info->local_lif_flags, DNX_ALGO_LIF_MNGR_LOCAL_OUTLIF_REPLACE))
        {
            /*
             * If the replace flag is set, then remove the old result type before writing the new one.
             */
            SHR_IF_ERR_EXIT(dnx_lif_mngr_outlif_sw_info_delete
                            (unit, outlif_info->local_outlif, outlif_info->dbal_table_id));

        }

        SHR_IF_ERR_EXIT(dnx_lif_mngr_outlif_sw_info_add(unit, outlif_info));
    }
exit:
    SHR_FUNC_EXIT;
}

static shr_error_e
dnx_lif_mngr_lif_free_verify(
    int unit,
    int global_lif,
    lif_mngr_local_inlif_info_t * inlif_info,
    lif_mngr_local_outlif_info_t * outlif_info,
    dnx_algo_local_outlif_hw_info_t * outlif_hw_info)
{
    int is_ingress, is_egress, free_global_lif;
    uint32 global_lif_direction_flags;
    SHR_FUNC_INIT_VARS(unit);

    is_ingress = (inlif_info != NULL);
    is_egress = (outlif_info != NULL);
    free_global_lif = (global_lif != LIF_MNGR_INVALID);

    if (!is_ingress && !is_egress)
    {
        /*
         * A lif can be either an inlif or an outlif, or both (symmetric). If neither side is given as
         *   input, then the lif has no meaning.
         */
        SHR_ERR_EXIT(_SHR_E_INTERNAL,
                     "inlif_info is NULL and local_outlif is LIF_MNGR_INVALID. At least one must be valid.");
    }

    if (!free_global_lif && is_ingress && is_egress)
    {
        /*
         * If there's no global lif, then freeing both ingress and egress global lifs is meaningless,
         * since without global lifs they can't be symmetric. Instead, free them in two separate calls.
         */
        SHR_ERR_EXIT(_SHR_E_INTERNAL, "If don't free global lif was indicated, only one direction (ingress or egress) "
                     "can be used.");
    }

    /*
     * Verify global lif is it's in use.
     */
    if (free_global_lif)
    {
        /*
         * Set DNX_ALGO_LIF_INGRESS/EGRESS flags according to the required deallocation.
         */
        global_lif_direction_flags = DNX_ALGO_GLOBAL_LIF_ALLOCATION_SET_DIRECTION_FLAGS(is_ingress, is_egress);

        SHR_IF_ERR_EXIT(dnx_algo_global_lif_allocation_verify
                        (unit, DNX_ALGO_GLOBAL_LIF_ALLOCATION_DEALLOCATE_VERIFY, global_lif_direction_flags,
                         NULL, global_lif));
    }

    if ((is_ingress) && (!dnx_data_lif.in_lif.feature_get(unit, dnx_data_lif_in_lif_phy_db_dpc)))
    {
        SHR_IF_ERR_EXIT(dnx_lif_mngr_local_inlif_info_verify(unit, FALSE, inlif_info));
    }

    if (is_egress)
    {
        LIF_MNGR_LOCAL_OUT_LIF_VERIFY(unit, outlif_info->local_outlif);

        SHR_NULL_CHECK(outlif_hw_info, _SHR_E_INTERNAL, "outlif_hw_info");
    }

exit:
    SHR_FUNC_EXIT;
}

shr_error_e
dnx_lif_mngr_lif_free(
    int unit,
    int global_lif,
    lif_mngr_local_inlif_info_t * inlif_info,
    lif_mngr_local_outlif_info_t * outlif_info,
    dnx_algo_local_outlif_hw_info_t * outlif_hw_info,
    int dont_release_sw_info)
{
    int is_ingress, is_egress, free_global_lif;
    uint32 global_lif_direction_flags;
    SHR_FUNC_INIT_VARS(unit);

    is_ingress = (inlif_info != NULL);
    is_egress = (outlif_info != NULL);
    free_global_lif = (global_lif != LIF_MNGR_INVALID);

    /*
     * 0. Verify lif information.
     */
    SHR_INVOKE_VERIFY_DNXC(dnx_lif_mngr_lif_free_verify(unit, global_lif, inlif_info, outlif_info, outlif_hw_info));

    /*
     * Steps 1,2: Dellocate lifs, and remove mapping.
     */

    /*
     * Free global lif is it's in use.
     */
    if (free_global_lif)
    {
        /*
         * Set DNX_ALGO_LIF_INGRESS/EGRESS flags according to the required deallocation.
         */
        global_lif_direction_flags = DNX_ALGO_GLOBAL_LIF_ALLOCATION_SET_DIRECTION_FLAGS(is_ingress, is_egress);

        SHR_IF_ERR_EXIT(dnx_algo_global_lif_allocation_free(unit, global_lif_direction_flags, global_lif));
    }

    /*
     * Deallocate and unmap inlif.
     */
    if (is_ingress)
    {
        if (!dnx_data_lif.in_lif.feature_get(unit, dnx_data_lif_in_lif_phy_db_dpc))
        {
            /*
             * Deallocate.
             */
            SHR_IF_ERR_EXIT(dnx_algo_local_inlif_free(unit, inlif_info));

            if (free_global_lif)
            {
                /*
                 * Remove ingress mapping.
                 */
                SHR_IF_ERR_EXIT(dnx_algo_lif_mapping_remove(unit, DNX_ALGO_LIF_INGRESS, global_lif));
            }

            /*
             * Delete from SW state LIF to DBAL table id and type mapping.
             */
            if (!dont_release_sw_info)
            {
                SHR_IF_ERR_EXIT(dnx_lif_mngr_inlif_sw_info_table_id_and_result_type_delete
                                (unit, inlif_info->core_id, inlif_info->local_inlif, inlif_info->dbal_table_id));
            }
        }
    }

    /*
     * Deallocate and unmap outlif.
     */
    if (is_egress)
    {
        SHR_IF_ERR_EXIT(dnx_lif_mngr_outlif_sw_info_get
                        (unit, outlif_info->local_outlif, &outlif_info->dbal_table_id,
                         &outlif_info->dbal_result_type, &outlif_info->logical_phase, NULL, NULL, NULL));

        /*
         * Deallocate.
         */
        SHR_IF_ERR_EXIT(dnx_algo_local_outlif_free(unit, outlif_info, outlif_hw_info));
        /*
         * Remove egress mapping, only if the global lif exists.
         */
        if (free_global_lif)
        {
            SHR_IF_ERR_EXIT(dnx_algo_lif_mapping_remove(unit, DNX_ALGO_LIF_EGRESS, global_lif));
        }

        if (!dont_release_sw_info)
        {
            SHR_IF_ERR_EXIT(dnx_lif_mngr_outlif_sw_info_delete
                            (unit, outlif_info->local_outlif, outlif_info->dbal_table_id));
        }
    }

exit:
    SHR_FUNC_EXIT;
}

shr_error_e
dnx_algo_lif_mngr_nof_glem_lines_get(
    int unit,
    int *nof_glem_lines)
{
    int nof_phy_glem_1_lines, nof_phy_glem_2_lines;

    SHR_FUNC_INIT_VARS(unit);
    SHR_NULL_CHECK(nof_glem_lines, _SHR_E_INTERNAL, "nof_glem_lines");

    if (dnx_data_lif.global_lif.use_mdb_size_get(unit))
    {
        SHR_IF_ERR_EXIT(mdb_db_infos.capacity.get(unit, DBAL_PHYSICAL_TABLE_GLEM_1, &nof_phy_glem_1_lines));
        SHR_IF_ERR_EXIT(mdb_db_infos.capacity.get(unit, DBAL_PHYSICAL_TABLE_GLEM_2, &nof_phy_glem_2_lines));
        *nof_glem_lines = UTILEX_MIN(nof_phy_glem_1_lines, nof_phy_glem_2_lines);
    }
    else
    {
        *nof_glem_lines = DNX_ALGO_LIF_MNGR_REDUCED_MODE_NOF_LIFS;
    }

exit:
    SHR_FUNC_EXIT;
}

shr_error_e
dnx_algo_lif_mngr_nof_local_outlifs_get(
    int unit,
    int *nof_local_outlifs)
{
    int phy_eedb_max_capacity;
    dbal_physical_tables_e dbal_physical_table_id;
    uint32 max_entries_per_bank = 0;

    SHR_FUNC_INIT_VARS(unit);
    SHR_NULL_CHECK(nof_local_outlifs, _SHR_E_INTERNAL, "nof_local_outlifs");

    *nof_local_outlifs = 0;

    if (!dnx_data_lif.out_lif.feature_get(unit, dnx_data_lif_out_lif_per_phase_algo))
    {
        if (!DNX_ALGO_OUTLIF_IS_POINTER_BIGGER_THAN_EEDB_RESOURCE)
        {
            /*
             * Calculate the maximum number of outlifs stored in EEDB banks
             * Find the phase with smallest granularity, max entries per bank
             * Multiply number of banks by max entries per bank
             */
            for (dbal_physical_table_id = DBAL_PHYSICAL_TABLE_EEDB_1;
                 dbal_physical_table_id <= DBAL_PHYSICAL_TABLE_EEDB_8; dbal_physical_table_id++)
            {
                uint32 phase_entries_per_bank;

                SHR_IF_ERR_EXIT(mdb_eedb_table_nof_entries_per_cluster_type_get
                                (unit, dbal_physical_table_id, MDB_EEDB_BANK, &phase_entries_per_bank));

                if (phase_entries_per_bank > max_entries_per_bank)
                {
                    max_entries_per_bank = phase_entries_per_bank;
                }
            }
            /*
             * For eedb banks, we can't determine exactly how many outlifs will be, since it depends on dynamic allocation
             * of a shared resource. So we take a precaution, the maximum outlifs per bank multiplied by the number of
             * banks
             */
            *nof_local_outlifs =
                dnx_data_mdb.dh.macro_type_info_get(unit, MDB_EEDB_BANK)->nof_clusters * max_entries_per_bank;
        }

        SHR_IF_ERR_EXIT(mdb_db_infos.capacity.get(unit, DBAL_PHYSICAL_TABLE_EEDB_1, &phy_eedb_max_capacity));
        *nof_local_outlifs += phy_eedb_max_capacity;
        SHR_IF_ERR_EXIT(mdb_db_infos.capacity.get(unit, DBAL_PHYSICAL_TABLE_EEDB_3, &phy_eedb_max_capacity));
        *nof_local_outlifs += phy_eedb_max_capacity;
        SHR_IF_ERR_EXIT(mdb_db_infos.capacity.get(unit, DBAL_PHYSICAL_TABLE_EEDB_5, &phy_eedb_max_capacity));
        *nof_local_outlifs += phy_eedb_max_capacity;
        SHR_IF_ERR_EXIT(mdb_db_infos.capacity.get(unit, DBAL_PHYSICAL_TABLE_EEDB_7, &phy_eedb_max_capacity));
        *nof_local_outlifs += phy_eedb_max_capacity;
    }
    else
    {
        /*
         * For per phase algo mode, need to sum all of the tables, since every table is unique
         */
        SHR_IF_ERR_EXIT(mdb_db_infos.capacity.get(unit, DBAL_PHYSICAL_TABLE_EEDB_1, &phy_eedb_max_capacity));
        *nof_local_outlifs += phy_eedb_max_capacity;
        SHR_IF_ERR_EXIT(mdb_db_infos.capacity.get(unit, DBAL_PHYSICAL_TABLE_EEDB_2, &phy_eedb_max_capacity));
        *nof_local_outlifs += phy_eedb_max_capacity;
        SHR_IF_ERR_EXIT(mdb_db_infos.capacity.get(unit, DBAL_PHYSICAL_TABLE_EEDB_3, &phy_eedb_max_capacity));
        *nof_local_outlifs += phy_eedb_max_capacity;
        SHR_IF_ERR_EXIT(mdb_db_infos.capacity.get(unit, DBAL_PHYSICAL_TABLE_EEDB_4, &phy_eedb_max_capacity));
        *nof_local_outlifs += phy_eedb_max_capacity;
        SHR_IF_ERR_EXIT(mdb_db_infos.capacity.get(unit, DBAL_PHYSICAL_TABLE_EEDB_5, &phy_eedb_max_capacity));
        *nof_local_outlifs += phy_eedb_max_capacity;
        SHR_IF_ERR_EXIT(mdb_db_infos.capacity.get(unit, DBAL_PHYSICAL_TABLE_EEDB_6, &phy_eedb_max_capacity));
        *nof_local_outlifs += phy_eedb_max_capacity;
        SHR_IF_ERR_EXIT(mdb_db_infos.capacity.get(unit, DBAL_PHYSICAL_TABLE_EEDB_7, &phy_eedb_max_capacity));
        *nof_local_outlifs += phy_eedb_max_capacity;
        SHR_IF_ERR_EXIT(mdb_db_infos.capacity.get(unit, DBAL_PHYSICAL_TABLE_EEDB_8, &phy_eedb_max_capacity));
        *nof_local_outlifs += phy_eedb_max_capacity;
    }

exit:
    SHR_FUNC_EXIT;
}

static shr_error_e
dnx_algo_lif_mngr_dpc_sbc_nof_inlifs_get(
    int unit,
    int *nof_sbc_lifs,
    int *nof_dpc_lifs)
{
    int use_mdb_size;
    SHR_FUNC_INIT_VARS(unit);

    use_mdb_size = dnx_data_lif.global_lif.use_mdb_size_get(unit);

    {
        if (nof_sbc_lifs)
        {
            if (use_mdb_size)
            {
                SHR_IF_ERR_EXIT(mdb_db_infos.capacity.get(unit, DBAL_PHYSICAL_TABLE_INLIF_1, nof_sbc_lifs));
            }
            else
            {
                *nof_sbc_lifs = DNX_ALGO_LIF_MNGR_REDUCED_MODE_NOF_LIFS;
            }
        }

        if (nof_dpc_lifs)
        {
            if (use_mdb_size)
            {
                int nof_inlif3_lifs;
                SHR_IF_ERR_EXIT(mdb_db_infos.capacity.get(unit, DBAL_PHYSICAL_TABLE_INLIF_2, nof_dpc_lifs));
                SHR_IF_ERR_EXIT(mdb_db_infos.capacity.get(unit, DBAL_PHYSICAL_TABLE_INLIF_3, &nof_inlif3_lifs));
                *nof_dpc_lifs = UTILEX_MIN(*nof_dpc_lifs, nof_inlif3_lifs);
            }
            else
            {
                *nof_dpc_lifs = DNX_ALGO_LIF_MNGR_REDUCED_MODE_NOF_LIFS;
            }
        }
    }

exit:
    SHR_FUNC_EXIT;
}

shr_error_e
dnx_algo_lif_mngr_max_inlif_id_get(
    int unit,
    int *nof_sbc_lifs,
    int *nof_dpc_lifs)
{
    SHR_FUNC_INIT_VARS(unit);

    SHR_IF_ERR_EXIT(dnx_algo_lif_mngr_dpc_sbc_nof_inlifs_get(unit, nof_sbc_lifs, nof_dpc_lifs));

exit:
    SHR_FUNC_EXIT;
}

shr_error_e
dnx_algo_lif_mngr_nof_inlifs_for_hash_get(
    int unit,
    int *nof_inlifs)
{
    int nof_sbc_lifs = 0, nof_dpc_lifs = 0;

    SHR_FUNC_INIT_VARS(unit);

    SHR_IF_ERR_EXIT(dnx_algo_lif_mngr_dpc_sbc_nof_inlifs_get(unit, &nof_sbc_lifs, &nof_dpc_lifs));

    *nof_inlifs = nof_sbc_lifs + nof_dpc_lifs;

exit:
    SHR_FUNC_EXIT;
}


shr_error_e
dbal_table_to_hash_idx_init(
    int unit)
{
    dbal_tables_e table_id = DBAL_TABLE_EMPTY;
    int nof_elements = 0;
    sw_state_idx_htbl_init_info_t init_info;
    int lif_dbal_table_array[100] = { 0 }; /** temp array that holds info before adding to SWSTATE */
    int ii;
    int nof_local_outlifs;

    SHR_FUNC_INIT_VARS(unit);

    sal_memset(&init_info, 0, sizeof(sw_state_idx_htbl_init_info_t));

    SHR_IF_ERR_EXIT(dbal_tables_next_table_get
                    (unit, table_id, DBAL_LABEL_NONE, DBAL_ACCESS_METHOD_MDB, DBAL_PHYSICAL_TABLE_NONE,
                     DBAL_TABLE_TYPE_DIRECT, &table_id));

    while (table_id != DBAL_TABLE_EMPTY)
    {
        CONST dbal_logical_table_t *table;

        SHR_IF_ERR_EXIT(dbal_tables_table_get(unit, table_id, &table));

        if (dbal_table_is_out_lif(table))
        {
            lif_dbal_table_array[nof_elements++] = table_id;
        }

        if (nof_elements >= 100)
        {
            SHR_ERR_EXIT(_SHR_E_INTERNAL, "nof tables exceded max possible tables");
        }

        SHR_IF_ERR_EXIT(dbal_tables_next_table_get
                        (unit, table_id, DBAL_LABEL_NONE, DBAL_ACCESS_METHOD_MDB, DBAL_PHYSICAL_TABLE_NONE,
                         DBAL_TABLE_TYPE_DIRECT, &table_id));
    }

    sal_memset(&init_info, 0, sizeof(sw_state_idx_htbl_init_info_t));

    /** creating the hash table for the mapping */
    init_info.max_nof_elements = nof_elements;
    init_info.expected_nof_elements = nof_elements;

    SHR_IF_ERR_EXIT(lif_mngr_db.local_lif_info.egress_lif_table_to_index_htb.create(unit, &init_info));

    for (ii = 0; ii < nof_elements; ii++)
    {
        uint32 index = 0;
        uint8 success = FALSE;
        SHR_IF_ERR_EXIT(lif_mngr_db.local_lif_info.
                        egress_lif_table_to_index_htb.insert(unit, &lif_dbal_table_array[ii], &index, &success));
    }

    SHR_IF_ERR_EXIT(lif_mngr_db.number_of_outlif_tables.set(unit, nof_elements));

    /** creating the multihead hash tables per dbal table - hash table with the info   */

    SHR_IF_ERR_EXIT(dnx_algo_lif_mngr_nof_local_outlifs_get(unit, &nof_local_outlifs));

    if (nof_local_outlifs > 0)
    {
        sw_state_htb_create_info_t egress_outlif_sw_info;

        sal_memset(&egress_outlif_sw_info, 0, sizeof(egress_outlif_sw_info));

        egress_outlif_sw_info.max_nof_elements = nof_local_outlifs;
        egress_outlif_sw_info.nof_htbs = nof_elements;
        egress_outlif_sw_info.flags = SW_STATE_HTB_CREATE_INFO_MULTI_TABLE;

        SHR_IF_ERR_EXIT(lif_mngr_db.local_lif_info.
                        egress_lif_sw_info_per_table_htb.create(unit, &egress_outlif_sw_info));
    }

exit:
    SHR_FUNC_EXIT;
}

shr_error_e
dnx_algo_lif_mngr_init(
    int unit)
{
    dnx_algo_res_create_data_t inlif_data, outlif_data;
    uint8 is_init;

    uint8 is_std_1 = TRUE;

    SHR_FUNC_INIT_VARS(unit);

    sal_memset(&inlif_data, 0, sizeof(dnx_algo_res_create_data_t));
    sal_memset(&outlif_data, 0, sizeof(dnx_algo_res_create_data_t));

    /*
     * Initialize lif mngr sw state.
     */
    SHR_IF_ERR_EXIT(lif_mngr_db.is_init(unit, &is_init));

    if (!is_init)
    {
        SHR_IF_ERR_EXIT(lif_mngr_db.init(unit));
    }

    /*
     * Initialize the lif mapping module.
     */
    SHR_IF_ERR_EXIT(dnx_algo_lif_mapping_init(unit));

    if (!dnx_data_lif.in_lif.feature_get(unit, dnx_data_lif_in_lif_phy_db_dpc))
    {
        /*
         * Initialize the local inlif allocation module.
         */
        SHR_IF_ERR_EXIT(dnx_algo_local_inlif_allocation_init(unit));
    }

    /*
     * Initialize the local outlif allocation module.
     */
    SHR_IF_ERR_EXIT(dnx_algo_local_outlif_allocation_init(unit));

    /*
     * Initialize the global lif allocation module.
     */
    SHR_IF_ERR_EXIT(dnx_algo_global_lif_allocation_init(unit));

    /*
     * Initialize the LIF Table Manager module.
     */
    SHR_IF_ERR_EXIT(dnx_pp_prgm_default_image_check(unit, &is_std_1));
    if (is_std_1)
    {
        SHR_IF_ERR_EXIT(dnx_algo_lif_table_mngr_init(unit));
    }

    /*
     * Check that GLEM is allocated
     */
    {
        uint8 is_glem1_allocated, is_glem2_allocated;

        SHR_IF_ERR_EXIT(mdb_table_is_allocated_get(unit, DBAL_PHYSICAL_TABLE_GLEM_1, &is_glem1_allocated));
        SHR_IF_ERR_EXIT(mdb_table_is_allocated_get(unit, DBAL_PHYSICAL_TABLE_GLEM_2, &is_glem2_allocated));
        if (!is_glem1_allocated && !is_glem2_allocated)
        {
            SHR_ERR_EXIT(_SHR_E_PARAM,
                         "Removing GLEM resources is currently not supported. Please make sure MDB profile contains GLEM.\n");
        }
    }

    

exit:
    SHR_FUNC_EXIT;
}

shr_error_e
dnx_algo_lif_mngr_deinit(
    int unit)
{
    SHR_FUNC_INIT_VARS(unit);

    /*
     * Deinitialize the local outlif allocation module.
     */
    SHR_IF_ERR_EXIT(dnx_algo_local_outlif_allocation_deinit(unit));

    /*
     * Deinitialize the lif mapping module.
     */
    SHR_IF_ERR_EXIT(dnx_algo_lif_mapping_deinit(unit));

    /*
     * sw state module deinit is done automatically at device deinit
     */

exit:
    SHR_FUNC_EXIT;
}

/*
 * }
 */
