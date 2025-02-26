/*
 * 
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2022 Broadcom Inc. All rights reserved.
 *
 */

#ifdef BSL_LOG_MODULE
#error "BSL_LOG_MODULE redefined"
#endif
#define BSL_LOG_MODULE BSL_LS_SOCDNX_KBPDNX
#include <shared/bsl.h>
#include <soc/dnx/kbp/kbp_common.h>
#include <soc/dnx/dnx_data/auto_generated/dnx_data_stif.h>

#if defined(INCLUDE_KBP)

#include <sal/types.h>
#include <bcm_int/dnx/kbp/kbp_mngr.h>
#include <shared/utilex/utilex_bitstream.h>
#include <bcm_int/dnx/algo/port/algo_port_mgmt.h>
#include <soc/dnx/utils/dnx_pp_programmability_utils.h>

#include <sal/core/boot.h>

const int g_kbp_compiled = 1;

#define DNX_KBP_INDIRECT_COMMIT_MODE_CHECK_AND_UPDATE(_db_entry_, _mode_) \
do { \
     \
    if ((_db_entry_) == NULL) \
    { \
         \
        if ((_mode_) == DBAL_INDIRECT_COMMIT_MODE_UPDATE) \
        { \
            SHR_ERR_EXIT(_SHR_E_NOT_FOUND, "The update flag was used on an entry that doesn't exists.\n"); \
        } \
        (_mode_) = DBAL_INDIRECT_COMMIT_MODE_NORMAL; \
    } \
    else \
    { \
         \
        if ((_mode_) == DBAL_INDIRECT_COMMIT_MODE_NORMAL) \
        { \
            SHR_ERR_EXIT(_SHR_E_EXISTS, "This entry already exists, to modify it the update flag should be used.\n"); \
        } \
        (_mode_) = DBAL_INDIRECT_COMMIT_MODE_UPDATE; \
    } \
} while (0)

shr_error_e
dnx_kbp_error_translation(
    kbp_status kbp_err)
{
    shr_error_e translated_err;

    switch (kbp_err)
    {
        case KBP_OK:
            translated_err = _SHR_E_NONE;
            break;
        case KBP_INVALID_ARGUMENT:
        case KBP_LPM_MASK_INVALID:
            translated_err = _SHR_E_PARAM;
            break;
        case KBP_OUT_OF_MEMORY:
            translated_err = _SHR_E_MEMORY;
            break;
        case KBP_INVALID_HANDLE:
        case KBP_PREFIX_NOT_FOUND:
            translated_err = _SHR_E_NOT_FOUND;
            break;
        case KBP_DB_WB_LOCATION_BUSY:
            translated_err = _SHR_E_EXISTS;
            break;
        case KBP_DB_FULL:
        case KBP_OUT_OF_DBA:
        case KBP_OUT_OF_UIT:
        case KBP_OUT_OF_UDA:
        case KBP_OUT_OF_AD:
        case KBP_EXHAUSTED_PCM_RESOURCE:
            translated_err = _SHR_E_FULL;
            break;
        default:
            translated_err = _SHR_E_INTERNAL;
    }

    return translated_err;
}

uint32
dnx_kbp_calculate_prefix_length(
    uint32 *payload_mask,
    uint32 max_key_size_in_bits)
{
    int uint32_index;
    uint32 max_key_size_in_uint32 = BITS2WORDS(max_key_size_in_bits);
    uint32 prefix_length = 0;

    for (uint32_index = max_key_size_in_uint32 - 1; uint32_index >= 0; uint32_index--)
    {

        if (payload_mask[uint32_index] == SAL_UINT32_MAX)
        {
            prefix_length += SAL_UINT32_NOF_BITS;
        }
        else
        {
            prefix_length += SAL_UINT32_NOF_BITS - (utilex_msb_bit_on(~payload_mask[uint32_index]) + 1);
            break;
        }
    }

    return prefix_length;
}

shr_error_e
dnx_kbp_prefix_len_to_mask(
    int unit,
    int prefix_length,
    uint32 max_key_size_in_bits,
    dbal_physical_entry_t * entry)
{
    uint32 max_key_size_in_uint32 = BITS2WORDS(max_key_size_in_bits);
    SHR_FUNC_INIT_VARS(unit);

    sal_memset(entry->k_mask, 0x0, DBAL_PHYSICAL_KEY_SIZE_IN_WORDS * sizeof(entry->k_mask[0]));

    if ((prefix_length >= 0) && (prefix_length <= max_key_size_in_bits))
    {
        int index;
        for (index = 0; index < max_key_size_in_uint32; index++)
        {
            if (prefix_length > index * SAL_UINT32_NOF_BITS)
            {
                int local_prefix_length = prefix_length - index * SAL_UINT32_NOF_BITS;
                entry->k_mask[max_key_size_in_uint32 - 1 - index] =
                    _shr_ip_mask_create(local_prefix_length >
                                        SAL_UINT32_NOF_BITS ? SAL_UINT32_NOF_BITS : local_prefix_length);
            }
            else
            {
                break;
            }
        }
    }
    else
    {
        SHR_ERR_EXIT(_SHR_E_PARAM, " Error: Prefix must be between 0 and %d, prefix given: %d.\n",
                     max_key_size_in_bits, prefix_length);
    }

exit:
    SHR_FUNC_EXIT;
}

shr_error_e
dnx_kbp_buffer_dbal_to_kbp(
    int unit,
    uint32 nof_bits,
    uint32 *data_in,
    uint8 *data_out)
{
    uint32 nof_bytes = BITS2BYTES(nof_bits);
    int32 byte_index;
    int byte_counter = 0;
    int32 uint32_index;
    uint8 align_bits = BYTES2BITS(nof_bytes) - nof_bits;

    SHR_FUNC_INIT_VARS(unit);

    SHR_NULL_CHECK(data_in, _SHR_E_PARAM, "data_in");
    SHR_NULL_CHECK(data_out, _SHR_E_PARAM, "data_out");

    byte_index = nof_bytes;
    uint32_index = 0;
    while (byte_index--)
    {
        int data_offset = (((nof_bytes - byte_index - 1) % 4) * 8);
        byte_counter++;
        data_out[byte_index] = (data_in[uint32_index] >> data_offset) & 0xFF;
        if ((byte_counter) % 4 == 0)
        {
            uint32_index++;
        }
    }

    if (align_bits != 0)
    {
        uint8 data_remainder = 0x00;
        byte_index = nof_bytes;
        while (byte_index--)
        {
            uint8 tmp_data_out = (data_out[byte_index] << align_bits) | data_remainder;
            data_remainder = data_out[byte_index] >> (8 - align_bits);
            data_out[byte_index] = tmp_data_out;
        }
    }

exit:
    SHR_FUNC_EXIT;
}

shr_error_e
dnx_kbp_buffer_kbp_to_dbal(
    int unit,
    uint32 nof_bits,
    uint8 *data_in,
    uint32 *data_out)
{
    uint32 nof_bytes = BITS2BYTES(nof_bits);
    uint32 nof_uint32 = BITS2WORDS(nof_bits);
    int32 byte_index;
    int32 uint32_index;
    int byte_counter = 0;
    uint8 align_bits = BYTES2BITS(nof_bytes) - nof_bits;
    uint32 tmp_data_out;
    SHR_FUNC_INIT_VARS(unit);

    SHR_NULL_CHECK(data_in, _SHR_E_PARAM, "data_in");
    SHR_NULL_CHECK(data_out, _SHR_E_PARAM, "data_out");

    byte_index = nof_bytes;
    uint32_index = 0;
    data_out[uint32_index] = 0x00000000;

    while (byte_index--)
    {
        int data_offset = (((nof_bytes - byte_index - 1) % 4) * 8);
        byte_counter++;
        tmp_data_out = data_in[byte_index] << (data_offset);
        data_out[uint32_index] |= tmp_data_out;

        if (((byte_counter) % 4 == 0) && (byte_index != 0))
        {
            uint32_index++;
            data_out[uint32_index] = 0x0;
        }
    }

    if (align_bits != 0)
    {
        uint32 data_remainder = 0x00000000;
        uint32_index = nof_uint32;
        while (uint32_index--)
        {
            tmp_data_out = (data_out[uint32_index] >> align_bits) | data_remainder;
            data_remainder = (data_out[uint32_index] << (32 - align_bits));
            data_out[uint32_index] = tmp_data_out;
        }
    }

exit:
    SHR_FUNC_EXIT;
}

static shr_error_e
dnx_kbp_entry_lpm_kbp_update(
    int unit,
    kbp_db_t_p db_p,
    kbp_ad_db_t_p ad_db_p,
    struct kbp_ad *ad_entry,
    uint8 *asso_data,
    uint32 payload_size_in_bits,
    uint32 access_bmp_indication,
    kbp_db_handles_t * kbp_handles,
    struct kbp_entry *db_entry,
    uint8 *add_entry)
{
    struct kbp_entry_info entry_info;
    SHR_FUNC_INIT_VARS(unit);

    DNX_KBP_TRY(kbp_entry_get_info(db_p, db_entry, &entry_info));

    if (ad_db_p == entry_info.ad_db)
    {

        if (payload_size_in_bits != 0)
        {
            DNX_KBP_TRY(kbp_ad_db_update_entry(ad_db_p, ad_entry, asso_data));
        }
        *add_entry = FALSE;
    }
    else
    {

        SHR_ERR_EXIT(_SHR_E_PARAM,
                     "Attempting to update an entry payload located in different AD DB, which could cause traffic loss\n");
    }

exit:
    SHR_FUNC_EXIT;
}

shr_error_e
dnx_kbp_entry_lpm_get(
    int unit,
    kbp_db_t_p db_p,
    kbp_ad_db_t_p ad_db_p,
    uint32 key[DBAL_PHYSICAL_KEY_SIZE_IN_WORDS],
    uint32 key_size_in_bits,
    uint32 payload[DBAL_PHYSICAL_RES_SIZE_IN_WORDS],
    uint32 payload_size_in_bits,
    uint32 prefix_length,
    kbp_db_handles_t * op2_kbp_handles,
    uint32 *op2_payload_size)
{
    kbp_status res;
    struct kbp_entry *db_entry = NULL;
    struct kbp_ad *ad_entry = NULL;
    struct kbp_entry_info entry_info;
    uint8 data[DBAL_PHYSICAL_KEY_SIZE_IN_BYTES] = { 0 };
    uint8 asso_data[DBAL_PHYSICAL_RES_SIZE_IN_BYTES] = { 0 };
    uint32 payload_size_in_bytes = BITS2BYTES(payload_size_in_bits);

    SHR_FUNC_INIT_VARS(unit);

    SHR_IF_ERR_EXIT(dnx_kbp_buffer_dbal_to_kbp(unit, key_size_in_bits, key, data));

    kbp_db_get_prefix_handle(db_p, data, prefix_length, &db_entry);
    if (db_entry == NULL)
    {

        SHR_SET_CURRENT_ERR(_SHR_E_NOT_FOUND);
        SHR_EXIT();
    }

    res = kbp_entry_get_info(db_p, db_entry, &entry_info);
    if (res == KBP_PENDING_ENTRY)
    {

        SHR_SET_CURRENT_ERR(_SHR_E_NOT_FOUND);
        SHR_EXIT();
    }
    if (entry_info.active == 0)
    {

        SHR_SET_CURRENT_ERR(_SHR_E_NOT_FOUND);
        SHR_EXIT();
    }

    DNX_KBP_TRY(kbp_entry_get_ad(db_p, db_entry, &ad_entry));
    if (ad_entry == NULL)
    {
        SHR_ERR_EXIT(_SHR_E_INTERNAL, " Error: kbp_entry_get_ad() Failed\n");
    }

    sal_memset(asso_data, 0x0, sizeof(asso_data[0]) * payload_size_in_bytes);

    if (ad_db_p == NULL)
    {
        ad_db_p = entry_info.ad_db;
    }
    DNX_KBP_TRY(kbp_ad_db_get(ad_db_p, ad_entry, asso_data));

    SHR_IF_ERR_EXIT(dnx_kbp_buffer_kbp_to_dbal(unit, payload_size_in_bits, asso_data, payload));

    if (op2_payload_size && op2_kbp_handles)
    {
        if (ad_db_p == op2_kbp_handles->ad_db_p[DNX_KBP_AD_DB_INDEX_OPTIMIZED])
        {

            *op2_payload_size = op2_kbp_handles->opt_result_size;
        }
        else if (ad_db_p == op2_kbp_handles->ad_db_p[DNX_KBP_AD_DB_INDEX_LARGE_OPTIMIZED])
        {

            *op2_payload_size = op2_kbp_handles->large_opt_result_size;
        }
        else if (ad_db_p == op2_kbp_handles->ad_db_zero_size_p)
        {

            *op2_payload_size = 0;
        }
        else if (ad_db_p == op2_kbp_handles->ad_db_p[DNX_KBP_AD_DB_INDEX_REGULAR])
        {

            *op2_payload_size = op2_kbp_handles->regular_result_size;
        }
        else
        {
            *op2_payload_size = payload_size_in_bits;
        }
    }

exit:
    SHR_FUNC_EXIT;
}

shr_error_e
dnx_kbp_entry_lpm_add(
    int unit,
    kbp_db_t_p db_p,
    kbp_ad_db_t_p ad_db_p,
    uint32 key[DBAL_PHYSICAL_KEY_SIZE_IN_WORDS],
    uint32 key_size_in_bits,
    uint32 payload[DBAL_PHYSICAL_RES_SIZE_IN_WORDS],
    uint32 payload_size_in_bits,
    uint32 prefix_length,
    uint8 *indirect_commit_mode,
    uint32 op2_access_bmp_indication,
    kbp_db_handles_t * op2_kbp_handles)
{
    kbp_status res;
    struct kbp_entry *db_entry = NULL;
    struct kbp_ad *ad_entry = NULL;
    uint8 data[DBAL_PHYSICAL_KEY_SIZE_IN_BYTES] = { 0 };
    uint8 asso_data[DBAL_PHYSICAL_RES_SIZE_IN_BYTES] = { 0 };
    uint8 add_entry = TRUE;
    uint8 delete_ad_entry = TRUE;

    SHR_FUNC_INIT_VARS(unit);

    SHR_IF_ERR_EXIT(dnx_kbp_buffer_dbal_to_kbp(unit, key_size_in_bits, key, data));
    SHR_IF_ERR_EXIT(dnx_kbp_buffer_dbal_to_kbp(unit, payload_size_in_bits, payload, asso_data));

    kbp_db_get_prefix_handle(db_p, data, prefix_length, &db_entry);

    DNX_KBP_INDIRECT_COMMIT_MODE_CHECK_AND_UPDATE(db_entry, *indirect_commit_mode);

    if ((*indirect_commit_mode) != DBAL_INDIRECT_COMMIT_MODE_NORMAL)
    {

        DNX_KBP_TRY(kbp_entry_get_ad(db_p, db_entry, &ad_entry));
        if (op2_kbp_handles == NULL)
        {

            DNX_KBP_TRY(kbp_ad_db_update_entry(ad_db_p, ad_entry, asso_data));
            add_entry = FALSE;
        }
        else
        {

            SHR_IF_ERR_EXIT(dnx_kbp_entry_lpm_kbp_update(unit, db_p, ad_db_p, ad_entry, asso_data, payload_size_in_bits,
                                                         op2_access_bmp_indication, op2_kbp_handles, db_entry,
                                                         &add_entry));
        }
    }

    if (add_entry)
    {

        DNX_KBP_TRY(kbp_db_add_prefix(db_p, data, prefix_length, &db_entry));

#if 0

        if (_SHR_IS_FLAG_SET(op2_access_bmp_indication, DNX_KBP_ACCESS_BMP_INDICATION_DEFAULT_ENTRY))
        {
            enum kbp_db_entry_meta_priority db_meta_priority;

            DNX_KBP_TRY(kbp_db_get_property(db_p, KBP_PROP_ENTRY_META_PRIORITY, &db_meta_priority));

            DNX_KBP_TRY(kbp_entry_set_property
                        (db_p, db_entry, KBP_ENTRY_PROP_META_PRIORITY, KBP_ENTRY_META_PRIORITY_2, db_meta_priority));
        }
#endif

        if (op2_kbp_handles && (ad_db_p == op2_kbp_handles->ad_db_zero_size_p))
        {

            delete_ad_entry = FALSE;
            ad_entry = op2_kbp_handles->ad_entry_zero_size_p;
        }
        else
        {
            res = kbp_ad_db_add_entry(ad_db_p, asso_data, &ad_entry);
            if (dnx_kbp_error_translation(res) != _SHR_E_NONE)
            {

                kbp_db_delete_entry(db_p, db_entry);
                SHR_ERR_EXIT(_SHR_E_INTERNAL, " Error: kbp_ad_db_add_entry Failed\n");
            }
        }

        res = kbp_entry_add_ad(db_p, db_entry, ad_entry);
        if (dnx_kbp_error_translation(res) != _SHR_E_NONE)
        {

            kbp_db_delete_entry(db_p, db_entry);
            if (delete_ad_entry)
            {
                kbp_ad_db_delete_entry(ad_db_p, ad_entry);
            }
            SHR_ERR_EXIT(_SHR_E_INTERNAL, " Error: kbp_entry_add_ad Failed\n");
        }
    }

    if (!_SHR_IS_FLAG_SET(op2_access_bmp_indication, DNX_KBP_ACCESS_BMP_INDICATION_CACHING_ENABLED))
    {
        res = kbp_db_install(db_p);
        if (dnx_kbp_error_translation(res) != _SHR_E_NONE)
        {

            kbp_db_delete_entry(db_p, db_entry);
            if (delete_ad_entry)
            {
                kbp_ad_db_delete_entry(ad_db_p, ad_entry);
            }

            if (dnx_kbp_error_translation(res) == _SHR_E_FULL)
            {
                SHR_ERR_EXIT(_SHR_E_FULL, " Error: Table is full, %s\n", kbp_get_status_string(res));
            }
            else
            {
                SHR_ERR_EXIT(_SHR_E_INTERNAL, " Error: kbp_db_install failed with: %s.\n", kbp_get_status_string(res));
            }
        }
    }

exit:
    SHR_FUNC_EXIT;
}

shr_error_e
dnx_kbp_entry_lpm_delete(
    int unit,
    kbp_db_t_p db_p,
    kbp_ad_db_t_p ad_db_p,
    uint32 key[DBAL_PHYSICAL_KEY_SIZE_IN_WORDS],
    uint32 key_size_in_bits,
    uint32 prefix_length,
    uint32 op2_access_bmp_indication,
    kbp_db_handles_t * op2_kbp_handles,
    struct kbp_entry *op2_db_entry_in)
{
    struct kbp_entry *db_entry = NULL;
    struct kbp_ad *ad_entry = NULL;
    struct kbp_entry_info entry_info;
    uint8 data[DBAL_PHYSICAL_KEY_SIZE_IN_BYTES] = { 0 };

    SHR_FUNC_INIT_VARS(unit);

    if (op2_db_entry_in == NULL)
    {

        SHR_IF_ERR_EXIT(dnx_kbp_buffer_dbal_to_kbp(unit, key_size_in_bits, key, data));
        DNX_KBP_TRY(kbp_db_get_prefix_handle(db_p, data, prefix_length, &db_entry));
    }
    else
    {

        db_entry = op2_db_entry_in;
    }
    if (db_entry == NULL)
    {
        SHR_ERR_EXIT(_SHR_E_NOT_FOUND, "Entry not found.");
    }

    if (ad_db_p == NULL)
    {
        DNX_KBP_TRY(kbp_entry_get_info(db_p, db_entry, &entry_info));
        ad_db_p = entry_info.ad_db;
    }

    DNX_KBP_TRY(kbp_entry_get_ad(db_p, db_entry, &ad_entry));
    if (ad_entry == NULL)
    {
        SHR_ERR_EXIT(_SHR_E_INTERNAL, " Error: kbp_entry_get_ad() Failed\n");
    }

    DNX_KBP_TRY(kbp_db_delete_entry(db_p, db_entry));

    if (!_SHR_IS_FLAG_SET(op2_access_bmp_indication, DNX_KBP_ACCESS_BMP_INDICATION_CACHING_ENABLED))
    {
        DNX_KBP_TRY(kbp_db_install(db_p));

        if (!(op2_kbp_handles && (ad_db_p == op2_kbp_handles->ad_db_zero_size_p)))
        {
            DNX_KBP_TRY(kbp_ad_db_delete_entry(ad_db_p, ad_entry));
        }
    }

exit:
    SHR_FUNC_EXIT;
}

static shr_error_e
dnx_kbp_cache_db_verify(
    int unit,
    dbal_tables_e dbal_table_id,
    uint32 *db_id,
    kbp_db_handles_t * op2_kbp_handles)
{
    uint8 is_allocated = FALSE;
    SHR_FUNC_INIT_VARS(unit);

    SHR_IF_ERR_EXIT(KBP_ACCESS.is_init(unit, &is_allocated));
    if (!is_allocated)
    {
        SHR_ERR_EXIT(_SHR_E_CONFIG, "KBP manager is not initialized; Caching operation cannot be performed.");
    }
    if (!dnx_kbp_device_enabled(unit))
    {
        SHR_ERR_EXIT(_SHR_E_CONFIG, "KBP is not enabled; Caching operation cannot be performed.");
    }
    SHR_IF_ERR_EXIT(dbal_tables_app_db_id_get(unit, dbal_table_id, db_id, NULL));
    SHR_IF_ERR_EXIT(KBP_ACCESS.db_handles_info.get(unit, (*db_id), op2_kbp_handles));
    if (op2_kbp_handles->db_p == NULL)
    {
        SHR_ERR_EXIT(_SHR_E_CONFIG,
                     "KBP Device is not Synced or the table is not in use; Caching operation cannot be performed.");
    }

exit:
    SHR_FUNC_EXIT;
}

static shr_error_e
dnx_kbp_cache_db_delete_unused_entries_internal(
    int unit,
    kbp_db_handles_t op2_kbp_handles,
    uint8 is_rollback)
{
    SHR_FUNC_INIT_VARS(unit);

    if (op2_kbp_handles.ad_db_p[DNX_KBP_AD_DB_INDEX_REGULAR] != NULL)
    {
        DNX_KBP_TRY_ROLLBACK(kbp_ad_db_delete_unused_entries(op2_kbp_handles.ad_db_p[DNX_KBP_AD_DB_INDEX_REGULAR]),
                             is_rollback);
    }
    if (DNX_KBP_USE_OPTIMIZED_RESULT)
    {
        if (op2_kbp_handles.ad_db_p[DNX_KBP_AD_DB_INDEX_OPTIMIZED] != NULL)
        {
            DNX_KBP_TRY_ROLLBACK(kbp_ad_db_delete_unused_entries
                                 (op2_kbp_handles.ad_db_p[DNX_KBP_AD_DB_INDEX_OPTIMIZED]), is_rollback);
        }
        if (op2_kbp_handles.ad_db_p[DNX_KBP_AD_DB_INDEX_LARGE_OPTIMIZED] != NULL)
        {
            DNX_KBP_TRY_ROLLBACK(kbp_ad_db_delete_unused_entries
                                 (op2_kbp_handles.ad_db_p[DNX_KBP_AD_DB_INDEX_LARGE_OPTIMIZED]), is_rollback);
        }
    }

exit:
    SHR_FUNC_EXIT;
}

static shr_error_e
dnx_kbp_cache_db_clear_internal(
    int unit,
    kbp_db_handles_t op2_kbp_handles,
    uint8 is_rollback)
{
    SHR_FUNC_INIT_VARS(unit);

    DNX_KBP_TRY_ROLLBACK(kbp_db_delete_all_pending_entries(op2_kbp_handles.db_p), is_rollback);

    SHR_IF_ERR_EXIT(dnx_kbp_cache_db_delete_unused_entries_internal(unit, op2_kbp_handles, is_rollback));

exit:
    SHR_FUNC_EXIT;
}

shr_error_e
dnx_kbp_cache_db_commit_internal(
    int unit,
    kbp_db_handles_t op2_kbp_handles)
{
    int res = 0;
    SHR_FUNC_INIT_VARS(unit);

    res = kbp_db_install(op2_kbp_handles.db_p);
    if (res != KBP_OK)
    {

        SHR_IF_ERR_EXIT(dnx_kbp_cache_db_clear_internal(unit, op2_kbp_handles, TRUE));

        if (dnx_kbp_error_translation(res) == _SHR_E_FULL)
        {
            SHR_ERR_EXIT(_SHR_E_FULL, "Error: Table is full during cache commit, %s.\n", kbp_get_status_string(res));
        }
        else
        {
            SHR_ERR_EXIT(_SHR_E_INTERNAL, "Error: kbp_db_install failed during cache commit with: %s.\n",
                         kbp_get_status_string(res));
        }
    }

exit:
    SHR_FUNC_EXIT;
}

shr_error_e
dnx_kbp_cache_db_enable(
    int unit,
    dbal_tables_e dbal_table_id)
{
    uint32 db_id = 0;
    kbp_db_handles_t op2_kbp_handles = { 0 };
    SHR_FUNC_INIT_VARS(unit);

    SHR_IF_ERR_EXIT(dnx_kbp_cache_db_verify(unit, dbal_table_id, &db_id, &op2_kbp_handles));
    SHR_IF_ERR_EXIT(KBP_ACCESS.db_handles_info.caching_enabled.set(unit, db_id, TRUE));

exit:
    SHR_FUNC_EXIT;
}

shr_error_e
dnx_kbp_cache_db_commit(
    int unit,
    dbal_tables_e dbal_table_id)
{
    uint32 db_id = 0;
    kbp_db_handles_t op2_kbp_handles = { 0 };
    SHR_FUNC_INIT_VARS(unit);

    SHR_IF_ERR_EXIT(dnx_kbp_cache_db_verify(unit, dbal_table_id, &db_id, &op2_kbp_handles));
    if (op2_kbp_handles.caching_enabled)
    {

        SHR_SET_CURRENT_ERR(dnx_kbp_cache_db_commit_internal(unit, op2_kbp_handles));

        SHR_IF_ERR_EXIT(KBP_ACCESS.db_handles_info.caching_enabled.set(unit, db_id, FALSE));
    }
    else
    {
        SHR_ERR_EXIT(_SHR_E_CONFIG, "Caching is not enabled for KBP DB %d; Caching cannot be performed.\n", db_id);
    }

exit:
    SHR_FUNC_EXIT;
}

shr_error_e
dnx_kbp_cache_db_clear(
    int unit,
    dbal_tables_e dbal_table_id,
    uint32 nof_entries_to_clear)
{
    uint32 db_id = 0;
    kbp_db_handles_t op2_kbp_handles = { 0 };
    SHR_FUNC_INIT_VARS(unit);
    DBAL_FUNC_INIT_VARS(unit);

    SHR_IF_ERR_EXIT(dnx_kbp_cache_db_verify(unit, dbal_table_id, &db_id, &op2_kbp_handles));

    SHR_SET_CURRENT_ERR(dnx_kbp_cache_db_clear_internal(unit, op2_kbp_handles, FALSE));

    SHR_IF_ERR_EXIT(KBP_ACCESS.db_handles_info.caching_enabled.set(unit, db_id, FALSE));

    if (nof_entries_to_clear)
    {
        SHR_IF_ERR_EXIT(dbal_db.tables_properties.nof_entries.dec(unit, dbal_table_id, nof_entries_to_clear));
    }

exit:
    DBAL_FUNC_FREE_VARS;
    SHR_FUNC_EXIT;
}

uint8
dnx_kbp_device_enabled(
    int unit)
{
    uint8 is_std_1 = FALSE;
    int rv = 0;
    int is_supported = FALSE;

    rv = dnx_pp_prgm_default_image_check(unit, &is_std_1);

    if (dnx_data_elk.general.feature_get(unit, dnx_data_elk_general_is_kbp_supported))
    {
        if (SAL_BOOT_PLISIM && (is_std_1) && (rv == 0))
        {
            is_supported = TRUE;
        }
        else if (!SAL_BOOT_PLISIM)
        {
            if ((dnx_data_elk.general.device_type_get(unit) == DNX_KBP_DEV_TYPE_BCM52311) ||
                (dnx_data_elk.general.device_type_get(unit) == DNX_KBP_DEV_TYPE_BCM52321))
            {
                is_supported = TRUE;
            }
            else if (dnx_data_stif.general.feature_get(unit, dnx_data_stif_general_is_tap_supported) &&
                     ((dnx_data_elk.general.device_type_get(unit) == DNX_KBP_DEV_TYPE_BCM5235) ||
                      (dnx_data_elk.general.device_type_get(unit) == DNX_KBP_DEV_TYPE_BCM52321_BCM5235)))
            {
                is_supported = TRUE;
            }
        }
    }

    return is_supported;
}

uint8
dnx_kbp_interface_enabled(
    int unit)
{
    bcm_pbmp_t port_pbmp;
    shr_error_e res;

    res = (dnx_algo_port_logicals_get(unit, BCM_CORE_ALL, DNX_ALGO_PORT_LOGICALS_TYPE_NIF_ILKN_ELK, 0, &port_pbmp));
    if (SHR_FAILURE(res))
    {
        return FALSE;
    }
    else
    {
        return (!SAL_BOOT_PLISIM && !dnx_data_elk.connectivity.blackhole_get(unit)
                && BCM_PBMP_NOT_NULL(port_pbmp)) ? TRUE : FALSE;
    }
}

shr_error_e
dnx_kbp_valid_key_width(
    int unit,
    uint32 width,
    uint32 *valid_width)
{
    SHR_FUNC_INIT_VARS(unit);

    if (width == 0)
    {
        *valid_width = 0;
    }
    else if (width <= 40)
    {
        *valid_width = 40;
    }
    else if (width <= 80)
    {
        *valid_width = 80;
    }
    else if (width <= 160)
    {
        *valid_width = 160;
    }
    else if (width <= 320)
    {
        *valid_width = 320;
    }
    else if (width <= 480)
    {
        *valid_width = 480;
    }
    else if (width <= 640)
    {
        *valid_width = 640;
    }
    else
    {
        SHR_ERR_EXIT(_SHR_E_INTERNAL, "Invalid KBP key width %d. Key cannot be bigger than 640\n", width);
    }

exit:
    SHR_FUNC_EXIT;
}

shr_error_e
dnx_kbp_valid_result_width(
    int unit,
    uint32 width,
    uint32 *valid_width)
{
    SHR_FUNC_INIT_VARS(unit);

    if (width == 0)
    {
        *valid_width = 0;
    }
    else if (width <= 24)
    {
        *valid_width = 24;
    }
    else if (width <= 32)
    {
        *valid_width = 32;
    }
    else if (width <= 48)
    {
        *valid_width = 48;
    }
    else if (width <= 64)
    {
        *valid_width = 64;
    }
    else if (width <= 128)
    {
        *valid_width = 128;
    }
    else
    {
        SHR_ERR_EXIT(_SHR_E_INTERNAL, "Invalid KBP result width %d. Result cannot be bigger than 128\n", width);
    }

exit:
    SHR_FUNC_EXIT;
}

#else

/* *INDENT-OFF* */
const int g_kbp_compiled = 0;
uint8 dnx_kbp_device_enabled(int unit) { return 0; }
uint8 dnx_kbp_interface_enabled(int unit) { return 0; }
shr_error_e dnx_kbp_valid_key_width(int unit, uint32 width, uint32 *valid_width){DNX_KBP_DUMMY_PROTOTYPE_ERR_MSG("dnx_kbp_valid_key_width")}
shr_error_e dnx_kbp_valid_result_width(int unit, uint32 width, uint32 *valid_width){DNX_KBP_DUMMY_PROTOTYPE_ERR_MSG("dnx_kbp_valid_result_width")}


#endif
