
/*
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2022 Broadcom Inc. All rights reserved.
 */

#include <stdlib.h>
#include <sal/core/libc.h>
#include <soc/drv.h>
#include <sal/core/alloc.h>
#include <sal/appl/sal.h>
#include <sal/appl/io.h>
#include <sal/types.h>
#include <shared/bsl.h>
#include <shared/util.h>
#include <shared/dbx/dbx_xml.h>
#include <shared/dbx/dbx_file.h>
#include <shared/utilex/utilex_str.h>
#include <soc/sand/sand_aux_access.h>
#include <soc/dnx/dnx_data/auto_generated/dnx_data_ingress_cs.h>
#include <soc/dnx/dnx_data/auto_generated/dnx_data_l2.h>
#include <soc/dnx/dnx_data/auto_generated/dnx_data_esem.h>
#include <soc/dnx/swstate/auto_generated/access/dbal_access.h>
#include <shared/utilex/utilex_integer_arithmetic.h>
#include <soc/mcm/memregs.h>
#include <soc/dnx/mdb.h>
#include <soc/dnx/kbp/kbp_common.h>

#ifdef BCM_DNX_SUPPORT
#include <src/soc/dnx/dbal/dbal_init/auto_generated/dbal_init_tables_hard_logic.h>
#include <src/soc/dnx/dbal/dbal_init/auto_generated/dbal_init_tables_sw_state.h>
#include <src/soc/dnx/dbal/dbal_init/auto_generated/dbal_init_tables_tcam_context_selection.h>
#include <src/soc/dnx/dbal/dbal_init/auto_generated/dbal_init_tables_mdb.h>
#include <src/soc/dnx/dbal/dbal_init/auto_generated/dbal_init_tables_pemla.h>
#include <src/soc/dnx/dbal/dbal_init/auto_generated/dbal_init_hw_entity_groups.h>
#endif
#include <bcm_int/dnx/init/init_time_analyzer.h>
#include <soc/dnxc/swstate/dnxc_sw_state_utils.h>
#include <shared/utilex/utilex_bitstream.h>
#include <soc/dnx/utils/dnx_pp_programmability_utils.h>
#include "dbal_internal.h"
#include "dbal_formula_cb.h"
#include "dbal_hl_access.h"
#ifdef BCM_ACCESS_SUPPORT
#include <soc/dnxc/dnxc_access.h>
#endif

#define DBAL_IS_VALID_FUNCTION_ATTRIBUTES_IN_FORMULA(function_attributes_in_formula) ((function_attributes_in_formula)->end_index != 0)

typedef struct
{

    int start_index;

    int end_index;

    dbal_formula_operations_e formula_operation_function;
} function_attributes_in_formula_t;

static char *dnx_data_delimiters = ".(),";

static char *physical_db_id_delimiters = ".";

extern uint32 G_dbal_field_full_mask[DBAL_PHYSICAL_RES_SIZE_IN_WORDS];

#define INVALID_ARRm   {DBAL_HL_ACCESS_HW_ENTITY_INVALID,DBAL_HL_ACCESS_HW_ENTITY_INVALID,DBAL_HL_ACCESS_HW_ENTITY_INVALID,DBAL_HL_ACCESS_HW_ENTITY_INVALID,DBAL_HL_ACCESS_HW_ENTITY_INVALID, DBAL_HL_ACCESS_HW_ENTITY_INVALID,DBAL_HL_ACCESS_HW_ENTITY_INVALID,DBAL_HL_ACCESS_HW_ENTITY_INVALID,DBAL_HL_ACCESS_HW_ENTITY_INVALID,DBAL_HL_ACCESS_HW_ENTITY_INVALID, \
                        DBAL_HL_ACCESS_HW_ENTITY_INVALID,DBAL_HL_ACCESS_HW_ENTITY_INVALID,DBAL_HL_ACCESS_HW_ENTITY_INVALID,DBAL_HL_ACCESS_HW_ENTITY_INVALID,DBAL_HL_ACCESS_HW_ENTITY_INVALID, DBAL_HL_ACCESS_HW_ENTITY_INVALID,DBAL_HL_ACCESS_HW_ENTITY_INVALID,DBAL_HL_ACCESS_HW_ENTITY_INVALID,DBAL_HL_ACCESS_HW_ENTITY_INVALID,DBAL_HL_ACCESS_HW_ENTITY_INVALID}

#define INVALID_ARRr   {DBAL_HL_ACCESS_HW_ENTITY_INVALID,DBAL_HL_ACCESS_HW_ENTITY_INVALID,DBAL_HL_ACCESS_HW_ENTITY_INVALID,DBAL_HL_ACCESS_HW_ENTITY_INVALID,DBAL_HL_ACCESS_HW_ENTITY_INVALID, DBAL_HL_ACCESS_HW_ENTITY_INVALID,DBAL_HL_ACCESS_HW_ENTITY_INVALID,DBAL_HL_ACCESS_HW_ENTITY_INVALID,DBAL_HL_ACCESS_HW_ENTITY_INVALID,DBAL_HL_ACCESS_HW_ENTITY_INVALID, \
                        DBAL_HL_ACCESS_HW_ENTITY_INVALID,DBAL_HL_ACCESS_HW_ENTITY_INVALID,DBAL_HL_ACCESS_HW_ENTITY_INVALID,DBAL_HL_ACCESS_HW_ENTITY_INVALID,DBAL_HL_ACCESS_HW_ENTITY_INVALID, DBAL_HL_ACCESS_HW_ENTITY_INVALID,DBAL_HL_ACCESS_HW_ENTITY_INVALID,DBAL_HL_ACCESS_HW_ENTITY_INVALID,DBAL_HL_ACCESS_HW_ENTITY_INVALID,DBAL_HL_ACCESS_HW_ENTITY_INVALID}

#define DBAL_INIT_COPY_N_STR(dest, src, length) \
do                                                      \
{                                                       \
    sal_strncpy_s(dest, src, length);                 \
}while (0);

#define DBAL_DB_PARSE_IS_INT(_int_formula) (_int_formula != DBAL_DB_INVALID)
#define DBAL_DB_PARSE_IS_CB_FORMULA(_ag_cb_formula) (_ag_cb_formula != NULL)
#define DBAL_DB_PARSE_IS_INT_OR_CB_FORMULA(_int_formula, _ag_cb_formula) (DBAL_DB_PARSE_IS_INT(_int_formula) || DBAL_DB_PARSE_IS_CB_FORMULA(_ag_cb_formula))

#define DBAL_DB_INIT_TABLE_DB_FIELD_EFFECTIVE_SIZE_CALCULATE(_field_info) (_field_info->field_nof_bits + _field_info->offset_in_logical_field)

#define DBAL_DB_INIT_TABLE_DB_FIELD_IS_CONST_VALID(_field_info) (SHR_IS_BITSET(_field_info->field_indication_bm, DBAL_FIELD_IND_IS_CONST_VALID))

#define DBAL_DB_INIT_TABLE_DB_FIELD_SIZE_ABOVE_32_MIN_VALUE_VERIFY(_unit, _field_id, _min_value)         \
    if (_min_value != 0)                                                                                      \
    {                                                                                                        \
        SHR_ERR_EXIT(_SHR_E_INTERNAL, "Min values cannot be set with fields larger than 32bits. field %s\n", \
                     dbal_field_to_string(_unit, _field_id));                                                  \
    }

#define DBAL_DB_INIT_TABLE_DB_FIELD_SET_ARR_PREFIX_VERIFY(_unit, _field_info)                                         \
    if ((_field_info->field_type == DBAL_FIELD_TYPE_DEF_UINT) && (_field_info->field_id != DBAL_FIELD_RESERVED))      \
    {                                                                                                               \
        SHR_ERR_EXIT(_SHR_E_INTERNAL, "field %s with type uint cannot use arr prefix\n",                            \
                     dbal_field_to_string(_unit, _field_info->field_id));                                             \
    }

#define DBAL_DB_INIT_TABLE_ALLOC_RESULT_FIELDS_FOR_SUPERSET_RESULT_TYPE(_table_entry)                               \
        SHR_ALLOC_SET_ZERO(_table_entry->multi_res_info[_table_entry->nof_result_types].results_info,               \
                           DBAL_TABLE_MAX_NUM_OF_RESULT_FIELDS_PER_RES_TYPE * sizeof(dbal_table_field_info_t),      \
                           "dynamic rest type allocation", "%s%s%s\r\n", _table_entry->table_name, EMPTY, EMPTY);

#define DBAL_DB_INIT_TABLE_UPDATE_HW_ERROR_AND_EXIT_INIT_IF_CORE_MODE_NOT_SET(_table_id, _table_entry)  \
    if (_table_entry->core_mode == DBAL_CORE_NONE)                                                      \
    {                                                                                                   \
        LOG_ERROR(BSL_LOG_MODULE,                                                                       \
                  (BSL_META_U(unit, "Table %s is not mapped for this device\n\n"),                      \
                   dbal_logical_table_to_string(unit, _table_id)));                                     \
        SHR_IF_ERR_EXIT(dbal_tables_update_hw_error(unit, _table_id));                                  \
        SHR_EXIT();                                                                                     \
    }

#define DBAL_DB_INIT_TABLE_DB_FIELD_EMPTY_VERIFY(_table_entry, _field_info)                          \
    if (_field_info->field_id == DBAL_FIELD_EMPTY)                                                   \
    {                                                                                                \
        SHR_ERR_EXIT(_SHR_E_INTERNAL, "Invalid field ID in table %s \n", _table_entry->table_name);  \
    }

#define DBAL_DB_INIT_L2P_FIELD_ID_HAS_VALID_INTERFACE_FIELD_VERIFY(_table_entry, _field_id)                           \
    if ((_table_entry->table_type == DBAL_TABLE_TYPE_DIRECT) && (!_field_id))                                         \
    {                                                                                                                 \
        SHR_ERR_EXIT(_SHR_E_INTERNAL, "Direct table expect to have a valid field_id. For hard logic table: %s\n",     \
                     _table_entry->table_name);                                                                       \
    }

#define VSI_TABLE_NAME (dbal_logical_table_to_string(unit, dnx_data_l2.vsi.vsi_table_get(unit)))

#define DBAL_DB_INIT_TABLE_SKIP_SET_ALLOCATOR_FIELD(_table_entry)                                       \
    (((_table_entry->access_method == DBAL_ACCESS_METHOD_MDB) && (_table_entry->nof_key_fields > 1)     \
    && _table_entry->core_mode == DBAL_CORE_MODE_SBC)  ||                                               \
    ((_table_entry->access_method == DBAL_ACCESS_METHOD_MDB) && (_table_entry->nof_key_fields > 2)      \
    && _table_entry->core_mode == DBAL_CORE_MODE_DPC))

#define DBAL_DB_INIT_TABLE_SKIP_ALLOCATOR_FOR_VSI_FIELD(_table_entry,_field_info)                   \
        ((sal_strncmp(table_entry->table_name, VSI_TABLE_NAME, DBAL_MAX_STRING_LENGTH) != 0)        \
             && (field_info->field_id == DBAL_FIELD_VSI))

#define DBAL_DB_INIT_FIELD_TYPE_IS_COMMON_OR_DEFAULT_VERIFY(_fld_type_ent)                              \
    if (SHR_IS_BITSET(_fld_type_ent->field_indication_bm, DBAL_FIELD_IND_IS_COMMON)                     \
         && SHR_IS_BITSET(_fld_type_ent->field_indication_bm, DBAL_FIELD_IND_IS_DEFAULT))               \
    {                                                                                                   \
        SHR_ERR_EXIT(_SHR_E_INTERNAL,                                                                   \
                     "A field type is either common, default or with a specific image, please update the GeneralInfo \n"); \
    }

#define DBAL_DB_INIT_TABLE_IMAGE_SPECIFIC_TABLE_INDICATION_SET(_table_entry, _is_standard_table, _table_custom_image)  \
    if (_is_standard_table || ((_table_custom_image) != NULL))                                                         \
    {                                                                                                                  \
        SHR_BITSET(_table_entry->indications_bm, DBAL_TABLE_IND_IS_IMAGE_SPECIFIC_TABLE);                              \
    }

shr_error_e
dbal_db_init_dynamic_dbal_tables_sw_state(
    int unit)
{
    int table_index;
    int nof_dynamic_tables;
    int nof_dynamic_xml_tables = 0;
    uint8 res_type_index;
    int nof_multi_res_types;

    SHR_FUNC_INIT_VARS(unit);

    nof_dynamic_tables = dnx_data_dbal.table.nof_dynamic_tables_get(unit);
    SHR_IF_ERR_EXIT(dbal_db.tables_properties.alloc(unit));

    SHR_IF_ERR_EXIT(DBAL_DYNAMIC_TBL_IN_SW_STATE.alloc(unit));
    for (table_index = 0; table_index < nof_dynamic_tables; table_index++)
    {

        SHR_IF_ERR_EXIT(DBAL_DYNAMIC_TBL_IN_SW_STATE.labels.alloc(unit, table_index));

        SHR_IF_ERR_EXIT(DBAL_DYNAMIC_TBL_IN_SW_STATE.key_info_data.alloc(unit, table_index));

        SHR_IF_ERR_EXIT(DBAL_DYNAMIC_TBL_IN_SW_STATE.multi_res_info_data.alloc(unit, table_index));

        SHR_IF_ERR_EXIT(DBAL_DYNAMIC_TBL_IN_SW_STATE.res_info_data.alloc(unit, table_index));

#if defined(INCLUDE_KBP)
        SHR_IF_ERR_EXIT(DBAL_DYNAMIC_TBL_IN_SW_STATE.access_info.alloc(unit, table_index, sizeof(kbp_db_handles_t)));
#endif
    }

    if (DBAL_DYNAMIC_XML_TABLES_ENABLED)
    {
        nof_dynamic_xml_tables = dnx_data_dbal.table.nof_dynamic_xml_tables_get(unit);
        SHR_IF_ERR_EXIT(DBAL_DYNAMIC_XML_TBL_IN_SW_STATE.alloc(unit));

        for (table_index = 0; table_index < nof_dynamic_xml_tables; table_index++)
        {

            SHR_IF_ERR_EXIT(DBAL_DYNAMIC_XML_TBL_IN_SW_STATE.labels.alloc(unit, table_index));

            SHR_IF_ERR_EXIT(DBAL_DYNAMIC_XML_TBL_IN_SW_STATE.key_info_data.alloc(unit, table_index));

            SHR_IF_ERR_EXIT(DBAL_DYNAMIC_XML_TBL_IN_SW_STATE.multi_res_info_data.alloc(unit, table_index));

            SHR_IF_ERR_EXIT(DBAL_DYNAMIC_XML_TBL_IN_SW_STATE.res_info_data.alloc(unit, table_index));
        }
    }

    SHR_IF_ERR_EXIT(DBAL_SW_STATE_PPMC_RES_TYPE.multi_res_info_status.alloc(unit));
    SHR_IF_ERR_EXIT(DBAL_SW_STATE_PPMC_RES_TYPE.multi_res_info_data_sep.alloc(unit));
    nof_multi_res_types = dnx_data_dbal.table.nof_dynamic_tables_ppmc_multi_result_types_get(unit);
    for (res_type_index = 0; res_type_index < nof_multi_res_types; res_type_index++)
    {
        SHR_IF_ERR_EXIT(DBAL_SW_STATE_PPMC_RES_TYPE.
                        multi_res_info_status.set(unit, res_type_index, DBAL_MULTI_RES_INFO_AVAIL));
        SHR_IF_ERR_EXIT(DBAL_SW_STATE_PPMC_RES_TYPE.multi_res_info_data_sep.res_info_data.alloc(unit, res_type_index));
    }

exit:
    SHR_FUNC_EXIT;
}

shr_error_e
dbal_db_init_dynamic_dbal_tables_memory(
    int unit)
{
    dbal_logical_table_t *table;
    int table_index;
    int nof_tables;
    int labels_size_bytes;
    int key_info_data_size_bytes;
    int multi_res_info_data_size_bytes;
    int multi_res_info_results_info_data_size_bytes;
    int nof_multi_res_types;
    uint8 multi_res_type_index;
    int dynamic_entries_start_index;

    SHR_FUNC_INIT_VARS(unit);

    nof_tables = dnx_data_dbal.table.nof_dynamic_tables_get(unit);
    dynamic_entries_start_index = DBAL_NOF_TABLES;
    if (DBAL_DYNAMIC_XML_TABLES_ENABLED)
    {
        dynamic_entries_start_index = DBAL_NOF_STATIC_TABLES;
        nof_tables += (DBAL_NOF_TABLES - DBAL_NOF_STATIC_TABLES);
    }

    for (table_index = 0; table_index < nof_tables; table_index++)
    {

        SHR_IF_ERR_EXIT(dbal_tables_table_get_internal(unit, table_index + dynamic_entries_start_index, &table));

        SHR_IF_ERR_EXIT(dbal_logical_table_t_init(unit, table));

        labels_size_bytes = dnx_data_dbal.table.nof_dynamic_tables_labels_get(unit) * sizeof(dbal_labels_e);
        if (labels_size_bytes)
        {
            SHR_ALLOC_SET_ZERO(table->table_labels, labels_size_bytes,
                               "table labels allocation", "%s%s%s\r\n", table->table_name, EMPTY, EMPTY);
        }

        key_info_data_size_bytes =
            dnx_data_dbal.table.nof_dynamic_tables_key_fields_get(unit) * sizeof(dbal_table_field_info_t);
        if (key_info_data_size_bytes)
        {
            SHR_ALLOC_SET_ZERO(table->keys_info, key_info_data_size_bytes,
                               "key fields info allocation", "%s%s%s\r\n", table->table_name, EMPTY, EMPTY);
        }

        nof_multi_res_types = dnx_data_dbal.table.nof_dynamic_tables_multi_result_types_get(unit);
        multi_res_info_data_size_bytes = nof_multi_res_types * sizeof(multi_res_info_t);
        multi_res_info_results_info_data_size_bytes =
            dnx_data_dbal.table.nof_dynamic_tables_result_fields_get(unit) * sizeof(dbal_table_field_info_t);
        if (multi_res_info_data_size_bytes)
        {
            SHR_ALLOC_SET_ZERO(table->multi_res_info, multi_res_info_data_size_bytes,
                               "multiple results info allocation", "%s%s%s\r\n", table->table_name, EMPTY, EMPTY);

            for (multi_res_type_index = 0; multi_res_type_index < nof_multi_res_types; multi_res_type_index++)
            {
                table->multi_res_info[multi_res_type_index].results_info = NULL;
                SHR_ALLOC_SET_ZERO(table->multi_res_info[multi_res_type_index].results_info,
                                   multi_res_info_results_info_data_size_bytes, "results fields info allocation",
                                   "%s%s%s\r\n", table->table_name, EMPTY, EMPTY);
            }
        }

#if defined(INCLUDE_KBP)
        if (dnx_kbp_device_enabled(unit))
        {

            SHR_ALLOC_SET_ZERO(table->kbp_handles, sizeof(kbp_db_handles_t) * DNX_KBP_NOF_DBS_PER_CORE,
                               "multiple result direct mapping allocation", "%s%s%s\r\n", table->table_name, EMPTY,
                               EMPTY);
        }
#endif
    }

exit:
    SHR_FUNC_EXIT;
}

static shr_error_e
dbal_db_parse_dnx_data_sdk(
    int unit,
    char *full_map,
    dbal_parsed_db_dnx_data_struct_t * int_or_dnx_data)
{
    char *dnx_data_label;
    char *saveptr = NULL;
    char *data_str;

    SHR_FUNC_INIT_VARS(unit);

    data_str = sal_strnstr(full_map, "->", SHR_SAND_DEFAULT_MAX_STRING_OPERATION_LENGTH);
    if (data_str != NULL)
    {
        sal_strncpy_s(int_or_dnx_data->member, data_str + 2, sizeof(int_or_dnx_data->member));
    }

    dnx_data_label = sal_strtok_r(full_map, dnx_data_delimiters, &saveptr);

    dnx_data_label += sal_strnlen(DB_INIT_DNX_DATA_SDK_MODULE_PREFIX, SHR_SAND_DEFAULT_MAX_STRING_OPERATION_LENGTH);

    sal_strncpy_s(int_or_dnx_data->module, dnx_data_label, sizeof(int_or_dnx_data->module));

    dnx_data_label = sal_strtok_r(NULL, dnx_data_delimiters, &saveptr);
    if (dnx_data_label != NULL)
    {
        sal_strncpy_s(int_or_dnx_data->submodule, dnx_data_label, sizeof(int_or_dnx_data->submodule));
    }
    else
    {
        SHR_ERR_EXIT(_SHR_E_INTERNAL, "dnx data do not include submodule:%s\n", full_map);
    }

    dnx_data_label = sal_strtok_r(NULL, dnx_data_delimiters, &saveptr);

    data_str = sal_strnstr(dnx_data_label, DB_INIT_DNX_DATA_GET_SUFFIX, SHR_SAND_DEFAULT_MAX_STRING_OPERATION_LENGTH);
    if (data_str != NULL)
    {
        dnx_data_label[sal_strnlen(dnx_data_label, SHR_SAND_DEFAULT_MAX_STRING_OPERATION_LENGTH) -
                       sal_strnlen(DB_INIT_DNX_DATA_GET_SUFFIX, SHR_SAND_DEFAULT_MAX_STRING_OPERATION_LENGTH)] = 0;
        sal_strncpy_s(int_or_dnx_data->data, dnx_data_label, sizeof(int_or_dnx_data->data));
    }

    dnx_data_label = sal_strtok_r(NULL, dnx_data_delimiters, &saveptr);
    if (dnx_data_label != NULL)
    {
        if (sal_strncmp(dnx_data_label, "unit", 5) > 0)
        {
            SHR_ERR_EXIT(_SHR_E_INTERNAL, "unit argument is expected\n");
        }
    }

    dnx_data_label = sal_strtok_r(NULL, dnx_data_delimiters, &saveptr);
    if (dnx_data_label != NULL)
    {
        if (!sal_strncmp(int_or_dnx_data->data, DB_INIT_DNX_DATA_FEATURE, SHR_SAND_DEFAULT_MAX_STRING_OPERATION_LENGTH))
        {
            data_str =
                sal_strnstr(dnx_data_label, int_or_dnx_data->submodule, SHR_SAND_DEFAULT_MAX_STRING_OPERATION_LENGTH);
            if (data_str == NULL)
            {
                SHR_ERR_EXIT(_SHR_E_INTERNAL, "module and submodule are expected in the feature name\n");
            }

            sal_strncpy_s(int_or_dnx_data->data,
                          data_str + sal_strnlen(int_or_dnx_data->submodule,
                                                 SHR_SAND_DEFAULT_MAX_STRING_OPERATION_LENGTH) + 1,
                          sizeof(int_or_dnx_data->data));
            SHR_EXIT();
        }
        else
        {
            int_or_dnx_data->key1 = sal_atoi(dnx_data_label);
        }
    }

    dnx_data_label = sal_strtok_r(NULL, dnx_data_delimiters, &saveptr);
    if (dnx_data_label != NULL)
    {
        int_or_dnx_data->key2 = sal_atoi(dnx_data_label);;
    }

exit:
    SHR_FUNC_EXIT;
}

static shr_error_e
dbal_db_parse_dnx_data(
    int unit,
    char *full_map,
    dbal_parsed_db_dnx_data_struct_t * int_or_dnx_data)
{
    char *dnx_data_label;
    char *saveptr = NULL;

    SHR_FUNC_INIT_VARS(unit);

    dnx_data_label = sal_strtok_r(full_map, dnx_data_delimiters, &saveptr);

    dnx_data_label = sal_strtok_r(NULL, dnx_data_delimiters, &saveptr);
    if (dnx_data_label != NULL)
    {
        sal_strncpy_s(int_or_dnx_data->module, dnx_data_label, sizeof(int_or_dnx_data->module));
    }
    else
    {
        SHR_ERR_EXIT(_SHR_E_INTERNAL, "dnx data do not include module:%s\n", full_map);
    }

    dnx_data_label = sal_strtok_r(NULL, dnx_data_delimiters, &saveptr);
    if (dnx_data_label != NULL)
    {
        sal_strncpy_s(int_or_dnx_data->submodule, dnx_data_label, sizeof(int_or_dnx_data->submodule));
    }
    else
    {
        SHR_ERR_EXIT(_SHR_E_INTERNAL, "dnx data do not include submodule:%s\n", full_map);
    }

    dnx_data_label = sal_strtok_r(NULL, dnx_data_delimiters, &saveptr);
    if (dnx_data_label != NULL)
    {
        sal_strncpy_s(int_or_dnx_data->data, dnx_data_label, sizeof(int_or_dnx_data->data));
    }
    else
    {
        SHR_ERR_EXIT(_SHR_E_INTERNAL, "dnx data do not include data:%s\n", full_map);
    }

    dnx_data_label = sal_strtok_r(NULL, dnx_data_delimiters, &saveptr);
    if (dnx_data_label != NULL)
    {
        sal_strncpy_s(int_or_dnx_data->member, dnx_data_label, sizeof(int_or_dnx_data->member));
    }
    else
    {
        sal_strncpy_s(int_or_dnx_data->member, EMPTY, sizeof(int_or_dnx_data->member));
    }

    dnx_data_label = sal_strtok_r(NULL, dnx_data_delimiters, &saveptr);
    if (dnx_data_label != NULL)
    {
        int_or_dnx_data->key1 = sal_atoi(dnx_data_label);
    }
    else
    {
        int_or_dnx_data->key1 = 0;
    }

    dnx_data_label = sal_strtok_r(NULL, dnx_data_delimiters, &saveptr);
    if (dnx_data_label != NULL)
    {
        int_or_dnx_data->key2 = sal_atoi(dnx_data_label);
    }
    else
    {
        int_or_dnx_data->key2 = 0;
    }

exit:
    SHR_FUNC_EXIT;
}

static shr_error_e
dbal_db_parse_phyiscal_db_id(
    int unit,
    char *full_map,
    dbal_physical_tables_e * physical_db_id)
{
    char *phyiscal_db_label;
    char *saveptr = NULL;

    SHR_FUNC_INIT_VARS(unit);

    phyiscal_db_label = sal_strtok_r(full_map, physical_db_id_delimiters, &saveptr);

    phyiscal_db_label = sal_strtok_r(NULL, physical_db_id_delimiters, &saveptr);
    if (phyiscal_db_label != NULL)
    {
        SHR_IF_ERR_EXIT(dbal_physical_table_string_to_id(unit, phyiscal_db_label, physical_db_id));
    }
    else
    {
        SHR_ERR_EXIT(_SHR_E_INTERNAL, "Physical DB is not valid:%s\n", full_map);
    }

exit:
    SHR_FUNC_EXIT;
}

static shr_error_e
dbal_db_dnx_data_get_value(
    int unit,
    dbal_parsed_db_dnx_data_struct_t * parsed_dnx_data,
    uint32 *return_value)
{
    const uint32 *data_from_dnx;

    SHR_FUNC_INIT_VARS(unit);

    data_from_dnx = dnxc_data_utils_generic_2d_data_get(unit, parsed_dnx_data->module, parsed_dnx_data->submodule,
                                                        parsed_dnx_data->data, parsed_dnx_data->member,
                                                        parsed_dnx_data->key1, parsed_dnx_data->key2);
    if (data_from_dnx == NULL)
    {
        SHR_ERR_EXIT(_SHR_E_NOT_FOUND, "DNX_DATA data cannot be found\n"
                     "module: %s, submodule: %s, data: %s, member: %s, key1=%d, key2=%d\n",
                     parsed_dnx_data->module, parsed_dnx_data->submodule, parsed_dnx_data->data,
                     (parsed_dnx_data->member == NULL) ? EMPTY : parsed_dnx_data->member,
                     parsed_dnx_data->key1, parsed_dnx_data->key2);
    }
    *return_value = *data_from_dnx;

exit:
    SHR_FUNC_EXIT;
}

static shr_error_e
dbal_db_init_condition_parsing(
    int unit,
    dbal_tables_e table_id,
    dbal_access_condition_info_t * entry_condition,
    table_db_access_condition_struct_t * condition_params)
{
    SHR_FUNC_INIT_VARS(unit);

    if (condition_params->condition_type != DBAL_CONDITION_NONE)
    {
        entry_condition->type = condition_params->condition_type;
        if (condition_params->field_id != DBAL_FIELD_EMPTY)
        {
            int field_index, rv;
            entry_condition->field_id = condition_params->field_id;

            rv = dbal_tables_field_index_in_table_get_no_err(unit, table_id, entry_condition->field_id, TRUE, 0, 0,
                                                             &field_index);
            entry_condition->field_pos_in_table = field_index;
            if (rv)
            {
                SHR_ERR_EXIT(_SHR_E_INTERNAL,
                             "mapping condition uses an invalid field:%s for table:%s\n",
                             dbal_field_to_string(unit, entry_condition->field_id),
                             dbal_logical_table_to_string(unit, table_id));
            }
        }
        if (condition_params->enum_val != DBAL_DB_INVALID)
        {
            entry_condition->value[0] = condition_params->enum_val;
        }
        else
        {
            entry_condition->value[0] = condition_params->value;
        }
        sal_memcpy(entry_condition->mask, G_dbal_field_full_mask, DBAL_PHYSICAL_RES_SIZE_IN_BYTES);
    }

exit:
    SHR_FUNC_EXIT;
}

static shr_error_e
dbal_db_parse_formula_start_function_index(
    int unit,
    dbal_tables_e table_id,
    char *str_to_parse,
    int offset,
    int *dbal_start_function_index)
{
    int str_len = sal_strnlen(str_to_parse, SHR_SAND_DEFAULT_MAX_STRING_OPERATION_LENGTH);

    SHR_FUNC_INIT_VARS(unit);

    *dbal_start_function_index = offset;

    while (*dbal_start_function_index < str_len)
    {

        if (sal_strncasecmp
            (&(str_to_parse[*dbal_start_function_index]), DBAL_LOG2_FUNCTION,
             sal_strnlen(DBAL_LOG2_FUNCTION, SHR_SAND_DEFAULT_MAX_STRING_OPERATION_LENGTH)) == 0)
        {
            SHR_EXIT();
        }
        (*dbal_start_function_index)++;
    }
    SHR_ERR_EXIT(_SHR_E_INTERNAL, "Can't find start of dbal function in formula %s in table %s\n",
                 str_to_parse, dbal_logical_table_to_string(unit, table_id));
exit:
    SHR_FUNC_EXIT;
}

static shr_error_e
dbal_db_parse_formula_end_function_index(
    int unit,
    dbal_tables_e table_id,
    char *str_to_parse,
    int offset,
    int *function_end_index)
{

    int str_len = sal_strnlen(str_to_parse, SHR_SAND_DEFAULT_MAX_STRING_OPERATION_LENGTH);
    int index;
    int open_parenthesis = 0;

    SHR_FUNC_INIT_VARS(unit);

    if (str_to_parse[offset] != '(')
    {
        SHR_ERR_EXIT(_SHR_E_INTERNAL, "It was expected to have a ( at this point in %s in table %s",
                     &(str_to_parse[offset]), dbal_logical_table_to_string(unit, table_id));
    }

    for (index = offset; index < str_len; index++)
    {
        if (str_to_parse[index] == '(')
        {
            open_parenthesis++;
        }
        else if (str_to_parse[index] == ')')
        {
            open_parenthesis--;
            if (open_parenthesis == 0)
            {
                *function_end_index = index;
                SHR_EXIT();
            }
        }
    }
    SHR_ERR_EXIT(_SHR_E_INTERNAL, "Can't find end of dbal function in formula in %s in table %s",
                 str_to_parse, dbal_logical_table_to_string(unit, table_id));

exit:
    SHR_FUNC_EXIT;
}

static shr_error_e
dbal_db_parse_formula_function_index_ranges(
    int unit,
    dbal_tables_e table_id,
    char *curr_str,
    function_attributes_in_formula_t * dbal_function_ranges)
{

    int index = 0;
    int dbal_function_ranges_index = 0;

    SHR_FUNC_INIT_VARS(unit);

    while (sal_strnstr(&(curr_str[index]), DBAL_LOG2_FUNCTION, SHR_SAND_DEFAULT_MAX_STRING_OPERATION_LENGTH) != NULL)
    {

        if (dbal_function_ranges_index >= DBAL_OFFSET_FORMULA_MAX_NUM_OF_VARS - 1)
        {
            SHR_ERR_EXIT(_SHR_E_INTERNAL, "Number of dbal function in formula %s is too long in table %s\n",
                         curr_str, dbal_logical_table_to_string(unit, table_id));
        }

        SHR_IF_ERR_EXIT(dbal_db_parse_formula_start_function_index(unit, table_id,
                                                                   curr_str,
                                                                   index,
                                                                   &(dbal_function_ranges
                                                                     [dbal_function_ranges_index].start_index)));

        SHR_IF_ERR_EXIT(dbal_db_parse_formula_end_function_index(unit, table_id,
                                                                 curr_str,
                                                                 dbal_function_ranges
                                                                 [dbal_function_ranges_index].start_index +
                                                                 sal_strnlen(DBAL_LOG2_FUNCTION,
                                                                             SHR_SAND_DEFAULT_MAX_STRING_OPERATION_LENGTH),
                                                                 &(dbal_function_ranges
                                                                   [dbal_function_ranges_index].end_index)));

        dbal_function_ranges[dbal_function_ranges_index].formula_operation_function = DBAL_FORMULA_OPERATION_F_LOG2;

        index = dbal_function_ranges[dbal_function_ranges_index].end_index + 1;

        dbal_function_ranges_index++;
    }

exit:
    SHR_FUNC_EXIT;
}

static uint8
dbal_db_parse_formula_index_in_function_range(
    int unit,
    int index,
    function_attributes_in_formula_t * dbal_function_ranges)
{
    int dbal_function_ranges_index = 0;
    for (dbal_function_ranges_index = 0; dbal_function_ranges_index < DBAL_OFFSET_FORMULA_MAX_NUM_OF_VARS - 1;
         dbal_function_ranges_index++)
    {

        if (!DBAL_IS_VALID_FUNCTION_ATTRIBUTES_IN_FORMULA(&dbal_function_ranges[dbal_function_ranges_index]))
        {
            return FALSE;
        }

        else if ((index >= dbal_function_ranges[dbal_function_ranges_index].start_index)
                 && (index <= dbal_function_ranges[dbal_function_ranges_index].end_index))
        {
            return TRUE;
        }
    }
    return FALSE;
}

static uint8
dbal_db_parse_formula_is_dbal_function(
    int unit,
    char *curr_str,
    function_attributes_in_formula_t * dbal_function_ranges)
{
    if (DBAL_IS_VALID_FUNCTION_ATTRIBUTES_IN_FORMULA(dbal_function_ranges))
    {
        int str_len = sal_strnlen(curr_str, SHR_SAND_DEFAULT_MAX_STRING_OPERATION_LENGTH);
        return (dbal_function_ranges->start_index == 0) && (dbal_function_ranges->end_index == str_len - 1);
    }
    return FALSE;
}

static uint32
dbal_str_stoul(
    char *str,
    uint32 *val)
{
    char ch;
    ch = str[0];
    if (!((ch >= '0') && (ch <= '9')))
    {
        return _SHR_E_PARAM;
    }

    return utilex_str_stoul(str, val);
}

static void
dbal_db_parse_offset_int(
    int int_formula,
    dbal_int_or_cb_t * formula)
{
    formula->val = int_formula;
}

static void
dbal_db_parse_offset_int_or_cb_formula(
    int int_formula,
    dnx_dbal_formula_offset_cb ag_cb_formula,
    dbal_int_or_cb_t * formula)
{

    if (DBAL_DB_PARSE_IS_INT(int_formula))
    {
        dbal_db_parse_offset_int(int_formula, formula);
    }

    else if (DBAL_DB_PARSE_IS_CB_FORMULA(ag_cb_formula))
    {
        formula->cb = ag_cb_formula;
    }
}

static shr_error_e
dbal_db_parse_offset_formula(
    int unit,
    dbal_tables_e table_id,
    uint8 is_res_type_mapping,
    char *str_formula,
    dbal_offset_formula_t * formula,
    uint8 allow_dynamic_fields)
{
    int str_len;
    char curr_str[DBAL_MAX_EXTRA_LONG_STRING_LENGTH];
    int nof_plus_minus_operands = 0;
    int plus_minus_operands[DBAL_OFFSET_FORMULA_MAX_NUM_OF_VARS - 1] = { 0 };
    int nof_mult_div_mod_operands = 0;
    int mult_div_mod_operands[DBAL_OFFSET_FORMULA_MAX_NUM_OF_VARS - 1] = { 0 };
    int index = 0;
    int nof_operands;
    uint8 plus_or_mult;
    char *cb_token;
    uint32 nof_values = 0;
    char **decoded_values_list = NULL;
    function_attributes_in_formula_t dbal_function_ranges[DBAL_OFFSET_FORMULA_MAX_NUM_OF_VARS - 1];
    uint8 formula_is_dbal_function;

    SHR_FUNC_INIT_VARS(unit);

    DBAL_INIT_COPY_N_STR(formula->as_string, str_formula, DBAL_MAX_EXTRA_LONG_STRING_LENGTH);
    DBAL_INIT_COPY_N_STR(curr_str, str_formula, DBAL_MAX_EXTRA_LONG_STRING_LENGTH);

    sal_memset(dbal_function_ranges, 0, sizeof(dbal_function_ranges));

    str_len = sal_strnlen(str_formula, SHR_SAND_DEFAULT_MAX_STRING_OPERATION_LENGTH);
    {

        if (sal_strnstr(str_formula, DBAL_INIT_FORMULA_CB_INDICATOR, SHR_SAND_DEFAULT_MAX_STRING_OPERATION_LENGTH) ==
            str_formula)
        {

            if ((decoded_values_list = utilex_str_split(str_formula, "=", 2, &nof_values)) == NULL)
            {
                SHR_ERR_EXIT(_SHR_E_FAIL, "Failed to parse offset formula: %s\n", str_formula);
            }

            cb_token = decoded_values_list[1];

            while (sal_strncmp
                   (formula_offset_cb_map[index].cb_str, DBAL_FORMULA_CB_LAST_CB,
                    SHR_SAND_DEFAULT_MAX_STRING_OPERATION_LENGTH))
            {
                if (!sal_strncmp
                    (formula_offset_cb_map[index].cb_str, cb_token, SHR_SAND_DEFAULT_MAX_STRING_OPERATION_LENGTH))
                {
                    if (formula_offset_cb_map[index].cb == NULL)
                    {
                        SHR_ERR_EXIT(_SHR_E_PARAM, "Formula CB %s is pointing to NULL", cb_token);
                    }
                    formula->formula_offset_cb = formula_offset_cb_map[index].cb;
                    SHR_EXIT();
                }
                index++;
            }
            if (sal_strncmp
                (formula_offset_cb_map[index].cb_str, "last_cb", SHR_SAND_DEFAULT_MAX_STRING_OPERATION_LENGTH))
            {
                SHR_ERR_EXIT(_SHR_E_INTERNAL, "Unrecognized formula cb string");
            }
        }

        dbal_db_parse_formula_function_index_ranges(unit, table_id, curr_str, dbal_function_ranges);

        index = 0;

        while (index < str_len)
        {

            if (dbal_db_parse_formula_index_in_function_range(unit, index, dbal_function_ranges))
            {
                index++;
                continue;
            }

            if ((curr_str[index] == '+') || ((curr_str[index] == '-') && (curr_str[index + 1] != '>')))
            {
                if (nof_plus_minus_operands >= DBAL_OFFSET_FORMULA_MAX_NUM_OF_VARS - 1)
                {
                    SHR_ERR_EXIT(_SHR_E_INTERNAL, "ERROR number of elements in formula %s is too long table %s\n",
                                 formula->as_string, dbal_logical_table_to_string(unit, table_id));
                }
                plus_minus_operands[nof_plus_minus_operands] = index;
                nof_plus_minus_operands++;
            }
            index++;
        }

        if (nof_plus_minus_operands == 0)
        {

            index = 0;
            while (index < str_len)
            {

                if (dbal_db_parse_formula_index_in_function_range(unit, index, dbal_function_ranges))
                {
                    index++;
                    continue;
                }

                if (nof_mult_div_mod_operands >= DBAL_OFFSET_FORMULA_MAX_NUM_OF_VARS - 1)
                {
                    SHR_ERR_EXIT(_SHR_E_INTERNAL, "ERROR number of elements in formula %s is too long table %s\n",
                                 formula->as_string, dbal_logical_table_to_string(unit, table_id));
                }
                if ((curr_str[index] == '*') || (curr_str[index] == '/') || (curr_str[index] == '%'))
                {
                    mult_div_mod_operands[nof_mult_div_mod_operands] = index;
                    nof_mult_div_mod_operands++;
                }
                index++;
            }
        }

        nof_operands = nof_plus_minus_operands == 0 ? nof_mult_div_mod_operands : nof_plus_minus_operands;
        plus_or_mult = nof_plus_minus_operands == 0 ? 0 : 1;

        formula_is_dbal_function = dbal_db_parse_formula_is_dbal_function(unit, curr_str, dbal_function_ranges);

        if (formula_is_dbal_function)
        {
            char val_str[DBAL_MAX_EXTRA_LONG_STRING_LENGTH] = { '\0' };
            int parameter_start_index = dbal_function_ranges[0].start_index + sal_strnlen(DBAL_LOG2_FUNCTION,
                                                                                          SHR_SAND_DEFAULT_MAX_STRING_OPERATION_LENGTH)
                + 1;
            int parameter_string_length = dbal_function_ranges[0].end_index - parameter_start_index;

            int nof_elements = 1;
            formula->nof_vars = nof_elements;
            SHR_ALLOC_SET_ZERO(formula->val_as_formula, nof_elements * sizeof(dbal_offset_formula_t),
                               "val_as_formula", "%s%s%s\r\n", EMPTY, EMPTY, EMPTY);
            formula->val = 0xFFFFFFFF;
            formula->field_id = DBAL_FIELD_EMPTY;

            formula->action[0] = dbal_function_ranges[0].formula_operation_function;

            sal_strncpy(val_str, &(curr_str[parameter_start_index]), parameter_string_length);
            SHR_IF_ERR_EXIT(dbal_db_parse_offset_formula
                            (unit, table_id, is_res_type_mapping, val_str,
                             &formula->val_as_formula[0], allow_dynamic_fields));
        }

        else if (nof_operands == 0)
        {
            int res;
            formula->nof_vars = 1;
            formula->val_as_formula = NULL;
            formula->key_val = FALSE;
            formula->val = 0xFFFFFFFF;

            if (sal_strncmp(curr_str, "KEY", sizeof(curr_str)) == 0)
            {
                formula->key_val = TRUE;
                if (!allow_dynamic_fields)
                {
                    SHR_ERR_EXIT(_SHR_E_PARAM,
                                 "KEY in formula is a dynamic information that cannot be used in that place.\n");
                }
            }
            else if (sal_strncmp(curr_str, "RESULT", sizeof(curr_str)) == 0)
            {
                if (is_res_type_mapping)
                {
                    SHR_ERR_EXIT(_SHR_E_PARAM, "Mapping field RESULT_TYPE cannot be done using RESULT size\n");
                }
                formula->result_size = TRUE;
                if (!allow_dynamic_fields)
                {
                    SHR_ERR_EXIT(_SHR_E_PARAM,
                                 "RESULT in formula is a dynamic information that cannot be used in that place.\n");
                }
            }
            else if (sal_strncmp(curr_str, "INSTANCE", sizeof(curr_str)) == 0)
            {
                formula->instance_index = TRUE;
                if (!allow_dynamic_fields)
                {
                    SHR_ERR_EXIT(_SHR_E_PARAM,
                                 "INSTANCE in formula is a dynamic information that cannot be used in that place.\n");
                }
            }
            else if (sal_strnstr(curr_str, DB_INIT_PHYDB_INDICATION, sizeof(curr_str)) != NULL)
            {
                dbal_physical_tables_e physical_db_id;
                int physical_db_size_val = 0;

                SHR_IF_ERR_EXIT(dbal_db_parse_phyiscal_db_id(unit, curr_str, &physical_db_id));
                SHR_IF_ERR_EXIT(mdb_db_infos.capacity.get(unit, physical_db_id, &physical_db_size_val));

                formula->val = (uint32) physical_db_size_val;
            }
            else
            {
                if (sal_strnstr(curr_str, DB_INIT_DNX_DATA_INDICATION, sizeof(curr_str)) != NULL)
                {
                    uint8 negative_check = FALSE;
                    uint32 dnx_data_val = 0;
                    dbal_parsed_db_dnx_data_struct_t parsed_dnx_data;
                    if (curr_str[0] == '!')
                    {
                        negative_check = TRUE;
                    }
                    SHR_IF_ERR_EXIT(dbal_db_parse_dnx_data(unit, curr_str, &parsed_dnx_data));
                    SHR_IF_ERR_EXIT(dbal_db_dnx_data_get_value(unit, &parsed_dnx_data, &dnx_data_val));
                    formula->val = (dnx_data_val > UTILEX_I32_MAX) ? UTILEX_I32_MAX : (int) dnx_data_val;
                    if (negative_check == TRUE)
                    {
                        formula->val = !formula->val;
                    }
                }
                else if (sal_strnstr(curr_str, DB_INIT_DNX_DATA_SDK_MODULE_PREFIX, sizeof(curr_str)) != NULL)
                {
                    uint8 negative_check = FALSE;
                    uint32 dnx_data_val = 0;
                    dbal_parsed_db_dnx_data_struct_t parsed_dnx_data = { {0} };
                    if (curr_str[0] == '!')
                    {
                        negative_check = TRUE;
                    }
                    SHR_IF_ERR_EXIT(dbal_db_parse_dnx_data_sdk(unit, curr_str, &parsed_dnx_data));
                    SHR_IF_ERR_EXIT(dbal_db_dnx_data_get_value(unit, &parsed_dnx_data, &dnx_data_val));
                    formula->val = (dnx_data_val > UTILEX_I32_MAX) ? UTILEX_I32_MAX : (int) dnx_data_val;
                    if (negative_check == TRUE)
                    {
                        formula->val = !formula->val;
                    }
                }
                else
                {
                    if (dbal_str_stoul(curr_str, (uint32 *) &formula->val) != _SHR_E_NONE)
                    {
                        res = dbal_field_string_to_id_no_error(unit, curr_str, &formula->field_id);
                        if (res == _SHR_E_NOT_FOUND)
                        {
                            SHR_ERR_EXIT(_SHR_E_INTERNAL,
                                         "Formula contain a string (%s) that not related to table %s with ID %d \n",
                                         curr_str, dbal_logical_table_to_string(unit, table_id), table_id);
                        }
                        else
                        {
                            if (!allow_dynamic_fields)
                            {
                                SHR_ERR_EXIT(_SHR_E_PARAM,
                                             "Field names in formula is a dynamic information that cannot be used in that place,"
                                             "table %s formula %s\n", dbal_logical_table_to_string(unit, table_id),
                                             str_formula);
                            }
                            if (is_res_type_mapping)
                            {
                                int rv;
                                int field_index;
                                rv = dbal_tables_field_index_in_table_get_no_err(unit, table_id, formula->field_id,
                                                                                 TRUE, 0, 0, &field_index);
                                if (rv == _SHR_E_NOT_FOUND)
                                {
                                    SHR_ERR_EXIT(_SHR_E_PARAM,
                                                 "RESULT_TYPE mapping with field %s is illegal (it is result field or not in table %s)\n",
                                                 curr_str, dbal_logical_table_to_string(unit, table_id));
                                }

                                formula->is_result = 0;
                                formula->field_pos_in_table = field_index;
                            }
                            else
                            {
                                int rv;
                                int field_index;

                                rv = dbal_tables_field_index_in_table_get_no_err(unit, table_id, formula->field_id,
                                                                                 TRUE, 0, 0, &field_index);
                                if (rv == _SHR_E_NOT_FOUND)
                                {
                                    CONST dbal_logical_table_t *table;
                                    SHR_IF_ERR_EXIT(dbal_tables_table_get(unit, table_id, &table));

                                    if (table->nof_result_types < 1)
                                    {

                                        rv = dbal_tables_field_index_in_table_get_no_err(unit, table_id,
                                                                                         formula->field_id, FALSE, 0, 0,
                                                                                         &field_index);
                                        if (rv != _SHR_E_NONE)
                                        {

                                            formula->is_result = DBAL_TABLE_FIELD_KEY_OR_RESULT;
                                            formula->field_pos_in_table = DBAL_TABLE_FIELD_POSITION_UNKNOWN;
                                        }
                                        else
                                        {

                                            formula->is_result = 1;
                                            formula->field_pos_in_table = field_index;
                                        }
                                    }
                                    else
                                    {
                                        formula->is_result = DBAL_TABLE_FIELD_KEY_OR_RESULT;
                                        formula->field_pos_in_table = DBAL_TABLE_FIELD_POSITION_UNKNOWN;
                                    }
                                }
                                else
                                {

                                    formula->is_result = 0;
                                    formula->field_pos_in_table = field_index;
                                }
                            }
                        }
                    }
                }
            }
        }

        else
        {
            uint8 found_operand = FALSE;
            char val_str[DBAL_MAX_EXTRA_LONG_STRING_LENGTH];
            int str_index = 0;
            int sub_str_index = 0;
            int operand_index = 0;
            int num_of_elements = nof_operands + 1;
            formula->nof_vars = num_of_elements;

            sal_memset(val_str, 0, sizeof(val_str));
            SHR_ALLOC_SET_ZERO(formula->val_as_formula, num_of_elements * sizeof(dbal_offset_formula_t),
                               "val_as_formula", "%s%s%s\r\n", EMPTY, EMPTY, EMPTY);

            formula->val = 0xFFFFFFFF;
            formula->field_id = DBAL_FIELD_EMPTY;

            while (str_index < str_len)
            {
                found_operand = FALSE;
                if (plus_or_mult)
                {
                    if (nof_plus_minus_operands >= DBAL_OFFSET_FORMULA_MAX_NUM_OF_VARS - 1)
                    {
                        SHR_ERR_EXIT(_SHR_E_INTERNAL, "ERROR number of elements in formula %s is too long table %s\n",
                                     formula->as_string, dbal_logical_table_to_string(unit, table_id));
                    }
                    if (str_index == plus_minus_operands[operand_index])
                    {
                        found_operand = TRUE;
                        if (curr_str[plus_minus_operands[operand_index]] == '+')
                        {
                            formula->action[operand_index] = DBAL_FORMULA_OPERATION_ADD;
                        }
                        else if (curr_str[plus_minus_operands[operand_index]] == '-')
                        {
                            formula->action[operand_index] = DBAL_FORMULA_OPERATION_SUBTRACT;
                        }
                        else
                        {
                            SHR_ERR_EXIT(_SHR_E_INTERNAL, "Illegal path in algorithm\n");
                        }
                    }
                }
                else
                {
                    if (nof_plus_minus_operands >= DBAL_OFFSET_FORMULA_MAX_NUM_OF_VARS - 1)
                    {
                        SHR_ERR_EXIT(_SHR_E_INTERNAL, "ERROR number of elements in formula %s is too long table %s\n",
                                     formula->as_string, dbal_logical_table_to_string(unit, table_id));
                    }
                    if (str_index == mult_div_mod_operands[operand_index])
                    {
                        found_operand = TRUE;
                        if (curr_str[mult_div_mod_operands[operand_index]] == '%')
                        {
                            formula->action[operand_index] = DBAL_FORMULA_OPERATION_MODULO;
                        }
                        else if (curr_str[mult_div_mod_operands[operand_index]] == '/')
                        {
                            formula->action[operand_index] = DBAL_FORMULA_OPERATION_DIVIDE;
                        }
                        else if (curr_str[mult_div_mod_operands[operand_index]] == '*')
                        {
                            formula->action[operand_index] = DBAL_FORMULA_OPERATION_MULTIPLY;
                        }
                        else
                        {
                            SHR_ERR_EXIT(_SHR_E_INTERNAL, "Illegal path in algorithm\n");
                        }
                    }
                }

                if (found_operand)
                {
                    val_str[sub_str_index] = '\0';
                    SHR_IF_ERR_EXIT(dbal_db_parse_offset_formula
                                    (unit, table_id, is_res_type_mapping, val_str,
                                     &formula->val_as_formula[operand_index], allow_dynamic_fields));
                    sub_str_index = 0;
                    operand_index++;
                    str_index++;
                }
                else
                {
                    val_str[sub_str_index++] = curr_str[str_index++];
                }
            }
            val_str[sub_str_index] = '\0';
            SHR_IF_ERR_EXIT(dbal_db_parse_offset_formula
                            (unit, table_id, is_res_type_mapping, val_str,
                             &formula->val_as_formula[operand_index], allow_dynamic_fields));
        }
    }
exit:
    utilex_str_split_free(decoded_values_list, nof_values);
    SHR_FUNC_EXIT;
}

static shr_error_e
dbal_db_init_offset_parsing(
    int unit,
    dbal_offset_encode_info_t * entry_offset,
    table_db_offset_in_hw_struct_t * offset_params)
{
    SHR_FUNC_INIT_VARS(unit);

    if (DBAL_DB_PARSE_IS_INT_OR_CB_FORMULA(offset_params->formula_int, offset_params->formula_cb))
    {
        SHR_ALLOC_SET_ZERO(entry_offset->formula, 1 * sizeof(dbal_int_or_cb_t),
                           "formula", "%s%s%s\r\n", EMPTY, EMPTY, EMPTY);

        dbal_db_parse_offset_int_or_cb_formula(offset_params->formula_int, offset_params->formula_cb,
                                               entry_offset->formula);
    }
exit:
    SHR_FUNC_EXIT;
}

static void
dbal_tables_formulas_free(
    dbal_offset_formula_t * formula,
    int formula_index_in_array)
{
    if (formula != NULL)
    {
        int ii;
        for (ii = formula->nof_vars - 1; ii >= 0; ii--)
        {
            dbal_tables_formulas_free(&formula->val_as_formula[ii], ii);
        }
        if (formula_index_in_array == 0)
        {
            SHR_FREE(formula);
        }
    }
}

static shr_error_e
dbal_calculate_offset_from_formula(
    int unit,
    dbal_entry_handle_t * entry_handle,
    dbal_tables_e table_id,
    dbal_fields_e current_mapped_field_id,
    dbal_offset_formula_t * formula,
    uint32 *result)
{
    int ii = 0;
    uint32 vars[DBAL_OFFSET_FORMULA_MAX_NUM_OF_VARS] = { 0 };
    uint32 curr_result = 0;

    SHR_FUNC_INIT_VARS(unit);

    if (formula->formula_offset_cb)
    {
        SHR_IF_ERR_EXIT(formula->formula_offset_cb(unit, entry_handle, current_mapped_field_id, result));
        SHR_EXIT();
    }

    for (ii = 0; ii < formula->nof_vars; ii++)
    {
        if (formula->nof_vars == 1)
        {
            if (formula->val != 0xFFFFFFFF)
            {
                vars[ii] = formula->val;
            }
            else if (formula->field_id != DBAL_FIELD_EMPTY)
            {
                dbal_table_field_info_t field_info = { 0 };

                if (formula->field_id == DBAL_FIELD_CORE_ID)
                {
                    vars[ii] = entry_handle->core_id;
                    if ((entry_handle->core_id == DBAL_CORE_ALL)
                        || (entry_handle->core_id == DBAL_CORE_NOT_INITIALIZED))
                    {
                        SHR_ERR_EXIT(_SHR_E_INTERNAL, "Illegal usage of core in formula.\n");
                    }
                }
                else
                {
                    int rv = 0;

                    if (formula->is_result == DBAL_TABLE_FIELD_KEY_OR_RESULT)
                    {
                        int field_index;

                        rv = dbal_tables_field_index_in_table_get_no_err(unit,
                                                                         table_id,
                                                                         formula->field_id, TRUE, 0, 0, &field_index);
                        if (rv == _SHR_E_NONE)
                        {
                            formula->is_result = 0;
                            formula->field_pos_in_table = field_index;
                        }
                        else
                        {

                            rv = dbal_tables_field_index_in_table_get_no_err(unit,
                                                                             table_id,
                                                                             formula->field_id,
                                                                             FALSE,
                                                                             entry_handle->cur_res_type,
                                                                             0, &field_index);
                            if (rv == _SHR_E_NONE)
                            {
                                formula->is_result = 1;
                                formula->field_pos_in_table = field_index;
                            }
                        }
                    }

                    if (formula->field_pos_in_table == DBAL_TABLE_FIELD_POSITION_UNKNOWN)
                    {
                        SHR_ERR_EXIT(_SHR_E_INTERNAL, "Field %s is not part of table %s\n",
                                     dbal_field_to_string(unit, formula->field_id), entry_handle->table->table_name);
                    }
                    if (formula->is_result == 0)
                    {
                        field_info = (entry_handle->table->keys_info[formula->field_pos_in_table]);
                        SHR_IF_ERR_EXIT(dbal_field_from_buffer_get(unit, &field_info, formula->field_id,
                                                                   entry_handle->phy_entry.key, &vars[ii]));

                        if (SHR_BITGET(field_info.field_indication_bm, DBAL_FIELD_IND_IS_FIELD_ENUM))
                        {
                            SHR_IF_ERR_EXIT(dbal_fields_enum_hw_value_get
                                            (unit, formula->field_id, vars[ii], &vars[ii]));
                        }
                    }
                    else if (formula->is_result == 1)
                    {
                        if (entry_handle->cur_res_type == DBAL_RESULT_TYPE_NOT_INITIALIZED)
                        {
                            SHR_ERR_EXIT(_SHR_E_INTERNAL,
                                         "Result type was not initialized cannot perform action table %s\n",
                                         entry_handle->table->table_name);
                        }

                        field_info =
                            (entry_handle->table->
                             multi_res_info[entry_handle->cur_res_type].results_info[formula->field_pos_in_table]);
                        vars[ii] = field_info.field_nof_bits;
                    }
                    else
                    {
                        SHR_ERR_EXIT(_SHR_E_INTERNAL, "Calculate offset formula, Unexpected error from "
                                     "dbal_table_field_info_get_no_err\n");
                    }
                }
            }
            else if (formula->key_val)
            {
                uint32 key_size = entry_handle->table->key_size;
                vars[ii] = entry_handle->phy_entry.key[0] & ((1 << key_size) - 1);
            }
            else if (formula->result_size)
            {
                if (entry_handle->cur_res_type == DBAL_RESULT_TYPE_NOT_INITIALIZED)
                {
                    SHR_ERR_EXIT(_SHR_E_INTERNAL, "Result type was not initialized cannot perform action table %s\n",
                                 entry_handle->table->table_name);
                }

                vars[ii] = DBAL_RES_INFO.entry_payload_size;
            }
            else if (formula->instance_index)
            {
                dbal_table_field_info_t *field_info =
                    &(entry_handle->table->
                      multi_res_info[entry_handle->cur_res_type].results_info[formula->field_pos_in_table]);
                vars[ii] = field_info->inst_idx;
            }
            else
            {

                SHR_IF_ERR_EXIT(dbal_calculate_offset_from_formula
                                (unit, entry_handle, table_id, current_mapped_field_id, &formula->val_as_formula[ii],
                                 &vars[ii]));
            }
        }
        else
        {

            SHR_IF_ERR_EXIT(dbal_calculate_offset_from_formula
                            (unit, entry_handle, table_id, current_mapped_field_id, &formula->val_as_formula[ii],
                             &vars[ii]));
        }
    }

    for (ii = 0; ii < formula->nof_vars; ii++)
    {

        if (ii == 0)
        {
            switch (formula->action[ii])
            {

                case DBAL_FORMULA_OPERATION_F_LOG2:
                    curr_result = utilex_log2_round_up(vars[ii]);
                    break;

                default:
                    curr_result = vars[0];
                    break;
            }
        }

        else
        {
            switch (formula->action[ii - 1])
            {
                case DBAL_FORMULA_OPERATION_MULTIPLY:
                    curr_result *= vars[ii];
                    break;
                case DBAL_FORMULA_OPERATION_SUBTRACT:
                    curr_result -= vars[ii];
                    break;
                case DBAL_FORMULA_OPERATION_DIVIDE:
                    curr_result /= vars[ii];
                    break;
                case DBAL_FORMULA_OPERATION_MODULO:
                    curr_result %= vars[ii];
                    break;
                case DBAL_FORMULA_OPERATION_ADD:
                    curr_result += vars[ii];
                    break;
                default:
                    SHR_ERR_EXIT(_SHR_E_INTERNAL, "Unknown action in formula\n");
                    break;
            }
        }
    }

    *result = curr_result;

exit:
    SHR_FUNC_EXIT;
}

shr_error_e
dbal_db_parse_dnx_data_indication(
    int unit,
    dbal_db_int_or_dnx_data_info_struct_t * int_or_dnx_data_as_formula,
    char *value_to_parse,
    uint8 is_mandatory,
    int default_val,
    char *str_child_name,
    char *str_to_read)
{
    uint32 formula_val = 0;

    SHR_FUNC_INIT_VARS(unit);

    DNX_INIT_TIME_ANALYZER_DBAL_INIT_START(unit, DNX_INIT_TIME_ANALYSER_DBAL_L_INIT_DNX_DATA_PARSING);

    if (value_to_parse == NULL)
    {
        if (is_mandatory)
        {
            SHR_ERR_EXIT(_SHR_E_INTERNAL, "Missing mandatory information in XML tag:%s,%s\n", str_child_name,
                         str_to_read);
        }
        else
        {
            int_or_dnx_data_as_formula->int_val = default_val;
            SHR_EXIT();
        }
    }

    if (sal_strncmp(value_to_parse, "INVALID", SHR_SAND_DEFAULT_MAX_STRING_OPERATION_LENGTH) == 0)
    {
        int_or_dnx_data_as_formula->is_invalid = 1;
        SHR_EXIT();
    }

    sal_strncpy_s(int_or_dnx_data_as_formula->formula_as_string, value_to_parse,
                  sizeof(int_or_dnx_data_as_formula->formula_as_string));

    if (utilex_str_stoul(int_or_dnx_data_as_formula->formula_as_string, (uint32 *) &int_or_dnx_data_as_formula->int_val)
        == _SHR_E_NONE)
    {
        SHR_EXIT();
    }

    int_or_dnx_data_as_formula->formula = NULL;

    SHR_ALLOC_SET_ZERO_ERR_EXIT(int_or_dnx_data_as_formula->formula, 1 * sizeof(dbal_offset_formula_t),
                                "formula", "%s%s%s\r\n", EMPTY, EMPTY, EMPTY);

    SHR_IF_ERR_EXIT(dbal_db_parse_offset_formula
                    (unit, DBAL_NOF_TABLES, FALSE, int_or_dnx_data_as_formula->formula_as_string,
                     int_or_dnx_data_as_formula->formula, FALSE));

    SHR_IF_ERR_EXIT(dbal_calculate_offset_from_formula
                    (unit, NULL, DBAL_NOF_TABLES, DBAL_FIELD_EMPTY, int_or_dnx_data_as_formula->formula, &formula_val));

    int_or_dnx_data_as_formula->int_val = (int) formula_val;

    dbal_tables_formulas_free(int_or_dnx_data_as_formula->formula, 0);

exit:
    DNX_INIT_TIME_ANALYZER_DBAL_INIT_STOP(unit, DNX_INIT_TIME_ANALYSER_DBAL_L_INIT_DNX_DATA_PARSING);
    SHR_FUNC_EXIT;
}

static shr_error_e
dbal_db_init_field_type_define_add(
    int unit,
    field_type_db_struct_t * fld_type_prm,
    dbal_field_types_basic_info_t * fld_type_ent)
{
    int max_value_for_define = 0;
    int ii;

    SHR_FUNC_INIT_VARS(unit);

    fld_type_ent->nof_defines_values = fld_type_prm->nof_defined_vals;
    if (fld_type_ent->nof_defines_values > DBAL_FIELD_MAX_NUM_OF_DEFINE_VALUES)
    {
        SHR_ERR_EXIT(_SHR_E_INTERNAL, "Field %s has more define values than max allowed.\n", fld_type_ent->name);
    }

    SHR_ALLOC_SET_ZERO(fld_type_ent->defines_info,
                       fld_type_ent->nof_defines_values * sizeof(dbal_defines_info_t),
                       "defines info allocation", "%s%s%s\r\n", fld_type_ent->name, EMPTY, EMPTY);
    {
        if (fld_type_ent->max_size > 32)
        {
            SHR_ERR_EXIT(_SHR_E_INTERNAL, "Defined values cannot be bigger that 32 bits long, %s\n",
                         fld_type_ent->name);
        }
        else if (fld_type_ent->max_size == 32)
        {
            max_value_for_define = UTILEX_U32_MAX;
        }
        else
        {
            max_value_for_define = ((1 << fld_type_ent->max_size) - 1);
        }
    }
    for (ii = 0; ii < fld_type_prm->nof_defined_vals; ii++)
    {
        sal_strncat_s(fld_type_ent->defines_info[ii].name, fld_type_prm->define[ii].define_name,
                      sizeof(fld_type_ent->defines_info[ii].name));
        fld_type_ent->defines_info[ii].value = fld_type_prm->define[ii].define_value;
        if (fld_type_ent->defines_info[ii].value > max_value_for_define)
        {
            SHR_ERR_EXIT(_SHR_E_INTERNAL,
                         "Illegal value for Define. field size is %d, defined value is %d. field %s\n",
                         fld_type_ent->max_size, fld_type_ent->defines_info[ii].value, fld_type_ent->name);
        }
    }

exit:
    SHR_FUNC_EXIT;
}

static shr_error_e
dbal_db_init_field_type_enum_add(
    int unit,
    field_type_db_struct_t * fld_type_prm,
    dbal_field_types_basic_info_t * fld_type_ent)
{
    uint32 max_value_for_enum_mapping = 0;
    int ii;
    uint8 is_zero_mapping_exists = FALSE;

    SHR_FUNC_INIT_VARS(unit);

    if (fld_type_ent->nof_enum_values > DBAL_FIELD_MAX_NUM_OF_ENUM_VALUES)
    {
        SHR_ERR_EXIT(_SHR_E_INTERNAL, "Field %s has more enums values than max allowed.\n", fld_type_ent->name);
    }

    if (fld_type_ent->max_size > 32)
    {
        SHR_ERR_EXIT(_SHR_E_INTERNAL, "Enum fields cannot be bigger that 32 bits long, %s\n", fld_type_ent->name);
    }
    else
    {
        max_value_for_enum_mapping = (fld_type_ent->max_size == 32) ? 0xffffffff : ((1 << fld_type_ent->max_size) - 1);
    }

    SHR_ALLOC_SET_ZERO(fld_type_ent->enum_val_info,
                       fld_type_ent->nof_enum_values * sizeof(dbal_enum_decoding_info_t),
                       "enum info allocation", "%s%s%s\r\n", fld_type_ent->name, EMPTY, EMPTY);

    fld_type_ent->encode_info.encode_mode = DBAL_VALUE_FIELD_ENCODE_ENUM;

    fld_type_ent->min_value = 0;
    fld_type_ent->max_value = fld_type_prm->nof_enum_vals - 1;

    for (ii = 0; ii < fld_type_prm->nof_enum_vals; ii++)
    {
        int str_len = sal_strnlen(fld_type_prm->enums[ii].name_from_interface,
                                  sizeof(fld_type_prm->enums[ii].name_from_interface));
        if (str_len > 2 * DBAL_MAX_STRING_LENGTH)
        {
            SHR_ERR_EXIT(_SHR_E_INTERNAL, "Name size error field %s enum name %s\n", fld_type_ent->name,
                         fld_type_prm->enums[ii].name_from_interface);
        }
        if (str_len == 0)
        {

            fld_type_prm->enums[ii].is_invalid_value_from_mapping = TRUE;

        }
        sal_strncat_s(fld_type_ent->enum_val_info[ii].name, fld_type_prm->enums[ii].name_from_interface,
                      2 * DBAL_MAX_STRING_LENGTH);
        if (fld_type_prm->enums[ii].is_invalid_value_from_mapping)
        {

            fld_type_ent->enum_val_info[ii].is_invalid = TRUE;
            fld_type_ent->enum_val_info[ii].value = 0;
            fld_type_ent->nof_invalid_enum_values++;
            continue;
        }
        else
        {
            fld_type_ent->enum_val_info[ii].value = fld_type_prm->enums[ii].value_from_mapping;
        }

        if (((uint32) fld_type_prm->enums[ii].value_from_mapping) > max_value_for_enum_mapping)
        {
            SHR_ERR_EXIT(_SHR_E_INTERNAL,
                         "Illegal value for HW mapping in enum. field size is %d, hw value is %d. field %s\n",
                         fld_type_ent->max_size, fld_type_prm->enums[ii].value_from_mapping, fld_type_ent->name);
        }

        if (fld_type_ent->enum_val_info[ii].value == 0)
        {
            is_zero_mapping_exists = TRUE;
        }
    }
    if (!is_zero_mapping_exists)
    {
        SHR_ERR_EXIT(_SHR_E_INTERNAL, "Illegal value for HW mapping in enum. zero value must be in use. field %s\n",
                     fld_type_ent->name);
    }

exit:
    SHR_FUNC_EXIT;
}

shr_error_e
dbal_db_init_field_type_struct_alloc(
    int unit,
    dbal_field_types_basic_info_t * fld_type_ent)
{
    SHR_FUNC_INIT_VARS(unit);

    if (fld_type_ent->nof_struct_fields > DBAL_FIELD_MAX_NUM_OF_STRUCT_FIELDS)
    {
        SHR_ERR_EXIT(_SHR_E_INTERNAL, "Field %s has more struct fields than max allowed.\n", fld_type_ent->name);
    }

    SHR_ALLOC_SET_ZERO(fld_type_ent->struct_field_info,
                       fld_type_ent->nof_struct_fields * sizeof(dbal_sub_struct_field_info_t),
                       "struct field info allocation", "%s%s%s\r\n", fld_type_ent->name, EMPTY, EMPTY);

    fld_type_ent->encode_info.encode_mode = DBAL_VALUE_FIELD_ENCODE_NONE;

exit:
    SHR_FUNC_EXIT;
}

static shr_error_e
dbal_db_init_field_type_child_add(
    int unit,
    field_type_db_struct_t * fld_type_prm,
    dbal_field_types_basic_info_t * fld_type_ent)
{
    int ii;

    SHR_FUNC_INIT_VARS(unit);

    if (fld_type_ent->nof_child_fields > DBAL_FIELD_MAX_NUM_OF_CHILD_FIELDS)
    {
        SHR_ERR_EXIT(_SHR_E_INTERNAL, "Field %s has more child fields than max allowed.\n", fld_type_ent->name);
    }

    SHR_ALLOC_SET_ZERO(fld_type_ent->sub_field_info, fld_type_ent->nof_child_fields * sizeof(dbal_sub_field_info_t),
                       "sub field info allocation", "%s%s%s\r\n", fld_type_ent->name, EMPTY, EMPTY);

    for (ii = 0; ii < fld_type_prm->nof_childs; ii++)
    {
        SHR_IF_ERR_EXIT(dbal_field_string_to_id(unit, fld_type_prm->childs[ii].name,
                                                &fld_type_ent->sub_field_info[ii].sub_field_id));

        if (fld_type_ent->reference_field_id != DBAL_FIELD_TYPE_DEF_EMPTY)
        {
            fld_type_ent->sub_field_info[ii].encode_info.encode_mode = DBAL_VALUE_FIELD_ENCODE_PREFIX;
            SHR_IF_ERR_EXIT(dbal_field_types_enum_name_to_hw_value_get(unit,
                                                                       fld_type_ent->reference_field_id,
                                                                       fld_type_prm->childs[ii].name,
                                                                       &fld_type_ent->sub_field_info[ii].
                                                                       encode_info.input_param));
        }
        else
        {
            fld_type_ent->sub_field_info[ii].encode_info.encode_mode = fld_type_prm->childs[ii].encode_type;
            fld_type_ent->sub_field_info[ii].encode_info.input_param = fld_type_prm->childs[ii].encode_param1;
        }
    }
exit:
    SHR_FUNC_EXIT;
}

shr_error_e
dbal_db_init_field_type_add(
    int unit,
    field_type_db_struct_t * fld_type_prm,
    dbal_field_types_basic_info_t * fld_type_ent)
{
    int ii;

    SHR_FUNC_INIT_VARS(unit);

    DBAL_DB_INIT_FIELD_TYPE_IS_COMMON_OR_DEFAULT_VERIFY(fld_type_ent);

    SHR_BITSET(fld_type_ent->field_indication_bm, DBAL_FIELD_IND_IS_VALID);

    if (fld_type_prm->max_value != DBAL_DB_INVALID)
    {
        fld_type_ent->max_value = fld_type_prm->max_value;
    }
    else
    {
        if (fld_type_ent->max_size > 32)
        {
            fld_type_ent->max_value = 0;
        }
        else
        {
            fld_type_ent->max_value = utilex_max_value_by_size(fld_type_ent->max_size);
        }
    }

    if (fld_type_prm->min_value != DBAL_DB_INVALID)
    {
        fld_type_ent->min_value = fld_type_prm->min_value;
    }
    else
    {
        fld_type_ent->min_value = 0;
    }

    if (fld_type_prm->const_value != DBAL_DB_INVALID)
    {
        fld_type_ent->const_value = fld_type_prm->const_value;
        fld_type_ent->min_value = fld_type_ent->const_value;
        fld_type_ent->max_value = fld_type_ent->const_value;
        SHR_BITSET(fld_type_ent->field_indication_bm, DBAL_FIELD_IND_IS_CONST_VALID);
    }
    else
    {
        SHR_BITCLR(fld_type_ent->field_indication_bm, DBAL_FIELD_IND_IS_CONST_VALID);
    }

    for (ii = 0; ii < fld_type_prm->nof_illegal_value; ii++)
    {
        fld_type_ent->illegal_values[ii] = fld_type_prm->illegal_values[ii];
    }
    fld_type_ent->nof_illegal_values = fld_type_prm->nof_illegal_value;

    if (fld_type_ent->encode_info.encode_mode == DBAL_VALUE_FIELD_ENCODE_VALID_IND)
    {
        if ((fld_type_ent->max_size - 1) >= 32)
        {
            SHR_ERR_EXIT(_SHR_E_INTERNAL, "Illegal max size for field %s with valid indication\n", fld_type_ent->name);
        }
        fld_type_ent->max_value = ((uint32) 1 << (fld_type_ent->max_size - 1)) - 1;
    }

    fld_type_ent->nof_child_fields = fld_type_prm->nof_childs;
    if (fld_type_ent->nof_child_fields > 0)
    {
        SHR_IF_ERR_EXIT(dbal_db_init_field_type_child_add(unit, fld_type_prm, fld_type_ent));
    }

    fld_type_ent->nof_enum_values = fld_type_prm->nof_enum_vals;
    if (fld_type_ent->nof_enum_values > 0)
    {
        SHR_IF_ERR_EXIT(dbal_db_init_field_type_enum_add(unit, fld_type_prm, fld_type_ent));
    }

    fld_type_ent->nof_defines_values = fld_type_prm->nof_defined_vals;
    if (fld_type_ent->nof_defines_values > 0)
    {
        SHR_IF_ERR_EXIT(dbal_db_init_field_type_define_add(unit, fld_type_prm, fld_type_ent));
    }

    if (fld_type_ent->encode_info.encode_mode != DBAL_VALUE_FIELD_ENCODE_NONE)
    {
        if (fld_type_ent->max_size > 32)
        {
            SHR_ERR_EXIT(_SHR_E_INTERNAL, "Illegal field %s encoding, not supported for field bigger than 32 bit\n",
                         fld_type_ent->name);
        }
    }

    SHR_BITCLR(fld_type_ent->field_indication_bm, DBAL_FIELD_IND_IS_DYNAMIC);

exit:
    SHR_FUNC_EXIT;
}

static shr_error_e
dbal_db_init_direct_capacity_calculate(
    int unit,
    dbal_logical_table_t * table)
{
    int ii;
    SHR_FUNC_INIT_VARS(unit);

    table->max_capacity = 1;
    for (ii = 0; ii < table->nof_key_fields; ii++)
    {
        table->max_capacity *= (table->keys_info[ii].max_value + 1);
    }

    SHR_FUNC_EXIT;
}

static shr_error_e
dbal_db_init_table_hl_tcam_capacity_calculate(
    int unit,
    dbal_logical_table_t * table)
{
    uint32 max_index;
    dbal_hl_l2p_field_info_t *field_info =
        &table->hl_mapping_multi_res[0].
        l2p_hl_info[DBAL_HL_ACCESS_MEMORY].l2p_fields_info[DBAL_HL_TCAM_ACCESS_TYPE_KEY];

    SHR_FUNC_INIT_VARS(unit);

    SHR_IF_ERR_EXIT(dbal_hl_access_memory_max_index_get_per_access(unit, field_info->memory[0], table, &max_index));
    table->max_capacity = 1 + max_index;

    if (field_info->entry_offset_info.formula != NULL)
    {

        uint32 entry_offset;
        dbal_entry_handle_t entry_handle;
        for (int ii = 0; ii < table->max_capacity; ++ii)
        {
            entry_handle.phy_entry.entry_hw_id = ii;
            SHR_IF_ERR_EXIT(dbal_hl_offset_calculate(unit, &entry_handle, field_info,
                                                     ii, &(field_info->entry_offset_info), &entry_offset));
            if (entry_offset > table->max_capacity)
            {
                table->max_capacity = ii - 1;
                break;
            }
        }
    }

exit:
    SHR_FUNC_EXIT;
}

static shr_error_e
dbal_db_init_table_capacity_calculate(
    int unit,
    dbal_tables_e table_id,
    dbal_logical_table_t * table,
    table_db_struct_t * table_params)
{
    soc_mem_t mem;
    SHR_FUNC_INIT_VARS(unit);

    switch (table->access_method)
    {
        case DBAL_ACCESS_METHOD_KBP:
            table->max_capacity = 0;
            break;

        case DBAL_ACCESS_METHOD_PEMLA:
            SHR_IF_ERR_EXIT(dbal_db_init_direct_capacity_calculate(unit, table));
            break;

        case DBAL_ACCESS_METHOD_TCAM_CS:
            if (table->tcam_cs_mapping != NULL)
            {
                mem = table->tcam_cs_mapping->memory;
                table->max_capacity = SOC_MEM_INFO(unit, mem).index_max + 1;
            }
            break;

        case DBAL_ACCESS_METHOD_MDB:

            table->max_capacity = 0;
            break;

        case DBAL_ACCESS_METHOD_SW_STATE:
        {
            {
                if (table->table_type == DBAL_TABLE_TYPE_DIRECT)
                {
                    SHR_IF_ERR_EXIT(dbal_db_init_direct_capacity_calculate(unit, table));
                }
                else
                {

                    table->max_capacity = 0;
                }
            }
            break;
        }
        case DBAL_ACCESS_METHOD_HARD_LOGIC:
        {
            {
                if (table->table_type == DBAL_TABLE_TYPE_DIRECT)
                {
                    SHR_IF_ERR_EXIT(dbal_db_init_direct_capacity_calculate(unit, table));
                }
                else if (table->table_type == DBAL_TABLE_TYPE_TCAM_DIRECT)
                {
                    SHR_IF_ERR_EXIT(dbal_db_init_table_hl_tcam_capacity_calculate(unit, table));
                }
                else
                {
                    SHR_ERR_EXIT(_SHR_E_INTERNAL, "Unsupported table type for hard logic table: %s. Table %s \n",
                                 dbal_table_type_to_string(unit, table->table_type), table->table_name);
                }
            }
            break;
        }
        default:
            SHR_ERR_EXIT(_SHR_E_INTERNAL, "Illegal access method\n");
    }

exit:
    SHR_FUNC_EXIT;
}

static shr_error_e
dbal_db_init_table_db_field_has_single_field_type_verify(
    int unit,
    dbal_fields_e field_id,
    dbal_field_types_defs_e actual_field_type)
{
    dbal_field_types_defs_e expected_field_type;

    SHR_FUNC_INIT_VARS(unit);

    SHR_IF_ERR_EXIT(dbal_fields_field_type_get(unit, field_id, &expected_field_type));

    if (actual_field_type != expected_field_type)
    {
        SHR_ERR_EXIT(_SHR_E_INTERNAL, "field %s has multiple types definition: type1=%s type2=%s\n",
                     dbal_field_to_string(unit, field_id),
                     dbal_field_types_def_to_string(unit, expected_field_type),
                     dbal_field_types_def_to_string(unit, actual_field_type));
    }

exit:
    SHR_FUNC_EXIT;
}

static shr_error_e
dbal_db_init_table_db_field_core_field_type_verify(
    int unit,
    dbal_fields_e field_id,
    dbal_field_types_defs_e actual_field_type)
{
    SHR_FUNC_INIT_VARS(unit);
    if ((actual_field_type == DBAL_FIELD_TYPE_DEF_CORE_ID) && (field_id != DBAL_FIELD_CORE_ID))
    {
        SHR_ERR_EXIT(_SHR_E_INTERNAL, "field type CORE_ID only valid for field CORE_ID\n");
    }
exit:
    SHR_FUNC_EXIT;
}

static shr_error_e
dbal_db_init_table_db_field_set_field_type_verify(
    int unit,
    dbal_fields_e field_id,
    dbal_field_types_defs_e actual_field_type)
{
    SHR_FUNC_INIT_VARS(unit);
    SHR_IF_ERR_EXIT(dbal_db_init_table_db_field_has_single_field_type_verify(unit, field_id, actual_field_type));
    if (actual_field_type == DBAL_FIELD_TYPE_DEF_CORE_ID)
    {
        SHR_IF_ERR_EXIT(dbal_db_init_table_db_field_core_field_type_verify(unit, field_id, actual_field_type));
    }
exit:
    SHR_FUNC_EXIT;
}

#define DBAL_DB_INIT_TABLE_DB_FIELD_SET_FIELD_TYPE(unit, _field_info, _field_type) \
    SHR_IF_ERR_EXIT(dbal_db_init_table_db_field_set_field_type_verify(unit, _field_info->field_id, _field_type)); \
    _field_info->field_type = _field_type;

static shr_error_e
dbal_db_init_table_db_field_set_const_value_up_to_32(
    int unit,
    dbal_table_field_info_t * field_info,
    int const_value)
{
    uint32 field_dft_const_value = 0;
    uint8 field_dft_const_value_valid = 0;

    SHR_FUNC_INIT_VARS(unit);

    SHR_IF_ERR_EXIT(dbal_fields_const_value_get
                    (unit, field_info->field_id, &field_dft_const_value, &field_dft_const_value_valid));

    if (const_value != DBAL_DB_INVALID)
    {
        field_info->const_value = const_value;
    }
    else if (field_dft_const_value_valid)
    {
        field_info->const_value = field_dft_const_value;
    }

    if (field_dft_const_value_valid || (const_value != DBAL_DB_INVALID))
    {
        SHR_BITSET(field_info->field_indication_bm, DBAL_FIELD_IND_IS_CONST_VALID);
    }

exit:
    SHR_FUNC_EXIT;
}

static shr_error_e
dbal_db_init_table_db_field_set_const_value_above_32(
    int unit,
    dbal_table_field_info_t * field_info,
    int const_value)
{
    uint32 field_dft_const_value = 0;
    uint8 field_dft_const_value_valid = 0;

    SHR_FUNC_INIT_VARS(unit);

    SHR_IF_ERR_EXIT(dbal_fields_const_value_get
                    (unit, field_info->field_id, &field_dft_const_value, &field_dft_const_value_valid));

    if (field_dft_const_value_valid || (const_value != DBAL_DB_INVALID))
    {
        if (field_dft_const_value != 0)
        {
            SHR_ERR_EXIT(_SHR_E_INTERNAL,
                         "Const value can only be set to zero with fields larger than 32bits. field %s\n",
                         dbal_field_to_string(unit, field_info->field_id));
        }

        field_info->const_value = 0;
        SHR_BITSET(field_info->field_indication_bm, DBAL_FIELD_IND_IS_CONST_VALID);
    }

exit:
    SHR_FUNC_EXIT;
}

static shr_error_e
dbal_db_init_table_db_field_handle_const_value(
    int unit,
    dbal_table_field_info_t * field_info,
    int const_value)
{
    int field_effective_size;
    SHR_FUNC_INIT_VARS(unit);

    field_effective_size = DBAL_DB_INIT_TABLE_DB_FIELD_EFFECTIVE_SIZE_CALCULATE(field_info);

    if (field_effective_size <= 32)
    {
        SHR_IF_ERR_EXIT(dbal_db_init_table_db_field_set_const_value_up_to_32(unit, field_info, const_value));
    }
    else
    {
        SHR_IF_ERR_EXIT(dbal_db_init_table_db_field_set_const_value_above_32(unit, field_info, const_value));
    }

    if (DBAL_DB_INIT_TABLE_DB_FIELD_IS_CONST_VALID(field_info))
    {
        field_info->min_value = field_info->const_value;
        field_info->max_value = field_info->const_value;
    }
exit:
    SHR_FUNC_EXIT;
}

static shr_error_e
dbal_db_init_table_db_field_set_field_nof_bits(
    int unit,
    dbal_table_field_info_t * field_info,
    int size)
{
    SHR_FUNC_INIT_VARS(unit);

    if ((size != 0) || (field_info->field_id == DBAL_FIELD_RESULT_TYPE))
    {
        field_info->field_nof_bits = size;
    }
    else
    {
        uint32 field_def_size = 0;
        SHR_IF_ERR_EXIT(dbal_fields_max_size_get(unit, field_info->field_id, &field_def_size));
        field_info->field_nof_bits = field_def_size;
    }

exit:
    SHR_FUNC_EXIT;
}

static shr_error_e
dbal_db_init_table_db_field_effective_size_validate(
    int unit,
    dbal_logical_table_t * table_entry,
    dbal_table_field_info_t * field_info)
{
    int field_effective_size;
    uint32 field_def_size = 0;

    SHR_FUNC_INIT_VARS(unit);

    field_effective_size = DBAL_DB_INIT_TABLE_DB_FIELD_EFFECTIVE_SIZE_CALCULATE(field_info);
    SHR_IF_ERR_EXIT(dbal_fields_max_size_get(unit, field_info->field_id, &field_def_size));

    if (field_effective_size > field_def_size)
    {
        SHR_ERR_EXIT(_SHR_E_INTERNAL,
                     "field %s in table %s is longer than its default max size. offset=%d, size=%d\n",
                     dbal_field_to_string(unit, field_info->field_id), table_entry->table_name,
                     field_info->offset_in_logical_field, field_info->field_nof_bits);
    }
exit:
    SHR_FUNC_EXIT;
}

static shr_error_e
dbal_db_init_table_db_field_set_max_value_validate_above_32(
    int unit,
    dbal_table_field_info_t * field_info,
    int max_value)
{
    SHR_FUNC_INIT_VARS(unit);
    if (max_value != DBAL_DB_INVALID)
    {
        SHR_ERR_EXIT(_SHR_E_INTERNAL, "Max values cannot be set with fields larger than 32bits. field %s\n",
                     dbal_field_to_string(unit, field_info->field_id));
    }
exit:
    SHR_FUNC_EXIT;
}

static shr_error_e
dbal_db_init_table_db_field_set_max_value(
    int unit,
    dbal_table_field_info_t * field_info,
    int max_value,
    uint8 has_arr_prefix_width)
{
    int field_effective_size;
    uint32 field_def_size = 0;
    uint32 field_def_max_value = 0;
    dbal_field_types_basic_info_t *field_type_info;

    SHR_FUNC_INIT_VARS(unit);

    field_effective_size = DBAL_DB_INIT_TABLE_DB_FIELD_EFFECTIVE_SIZE_CALCULATE(field_info);

    if (field_effective_size > 32)
    {
        SHR_IF_ERR_EXIT(dbal_db_init_table_db_field_set_max_value_validate_above_32(unit, field_info, max_value));
        field_info->max_value = 0;
        SHR_EXIT();
    }

    SHR_IF_ERR_EXIT(dbal_fields_max_size_get(unit, field_info->field_id, &field_def_size));
    SHR_IF_ERR_EXIT(dbal_fields_max_value_get(unit, field_info->field_id, &field_def_max_value));

    SHR_IF_ERR_EXIT(dbal_fields_field_types_info_get(unit, field_info->field_id, &field_type_info));

    if (field_type_info->encode_info.encode_mode != DBAL_VALUE_FIELD_ENCODE_ENUM)
    {
        uint32 max_value_effective_size = utilex_max_value_by_size(field_effective_size);

        if (field_def_size > 32)
        {
            field_info->max_value = max_value_effective_size;
        }
        else
        {
            field_info->max_value = UTILEX_MIN(field_def_max_value, max_value_effective_size);
        }
    }
    else
    {

        field_info->max_value = field_def_max_value;

        if ((field_def_size > field_info->field_nof_bits) && !has_arr_prefix_width)
        {
            field_info->max_value = utilex_max_value_by_size(field_info->field_nof_bits);
        }
    }

    if (max_value != DBAL_DB_INVALID)
    {
        field_info->max_value = UTILEX_MIN(field_info->max_value, max_value);
    }
exit:
    SHR_FUNC_EXIT;
}

static shr_error_e
dbal_db_init_table_db_field_set_min_value(
    int unit,
    dbal_table_field_info_t * field_info,
    int min_value)
{

    int field_effective_size;
    uint32 field_def_min_value = 0;

    SHR_FUNC_INIT_VARS(unit);

    field_effective_size = DBAL_DB_INIT_TABLE_DB_FIELD_EFFECTIVE_SIZE_CALCULATE(field_info);

    if (field_effective_size > 32)
    {
        DBAL_DB_INIT_TABLE_DB_FIELD_SIZE_ABOVE_32_MIN_VALUE_VERIFY(unit, field_info->field_id, min_value);
        field_info->min_value = min_value;
        SHR_EXIT();
    }

    SHR_IF_ERR_EXIT(dbal_fields_min_value_get(unit, field_info->field_id, &field_def_min_value));

    if (min_value == 0)
    {
        field_info->min_value = field_def_min_value;
    }
    else
    {
        field_info->min_value = UTILEX_MAX(field_def_min_value, min_value);
    }

exit:
    SHR_FUNC_EXIT;
}

static shr_error_e
dbal_db_init_table_db_field_set_arr_prefix(
    int unit,
    dbal_table_field_info_t * field_info,
    int arr_prefix_width,
    int arr_prefix_value)
{
    int field_effective_size;

    SHR_FUNC_INIT_VARS(unit);

    field_effective_size = DBAL_DB_INIT_TABLE_DB_FIELD_EFFECTIVE_SIZE_CALCULATE(field_info);

    if ((field_effective_size <= 32) && arr_prefix_width)
    {
        CONST dbal_field_types_basic_info_t *field_type_info;
        DBAL_DB_INIT_TABLE_DB_FIELD_SET_ARR_PREFIX_VERIFY(unit, field_info);
        SHR_IF_ERR_EXIT(dbal_field_types_info_get(unit, field_info->field_type, &field_type_info));
        field_info->arr_prefix_size =
            DBAL_FIELD_ARR_PREFIX_SIZE_CALCULATE(field_type_info->max_size, field_info->field_nof_bits);
        field_info->arr_prefix =
            DBAL_FIELD_ARR_PREFIX_VALUE_CALCULATE(arr_prefix_width, arr_prefix_value, field_info->arr_prefix_size);
    }
exit:
    SHR_FUNC_EXIT;
}

static shr_error_e
dbal_db_init_table_multiple_instances_verify(
    int unit,
    dbal_logical_table_t * table,
    uint8 is_key_fields,
    dbal_table_field_info_t * field_info,
    uint32 max_nof_instances,
    uint8 is_validate_nof_instances)
{
    SHR_FUNC_INIT_VARS(unit);

    if (is_key_fields)
    {
        SHR_ERR_EXIT(_SHR_E_INTERNAL, "Table %s, multiple instances for key fields. field %s is not supported \n",
                     table->table_name, dbal_field_to_string(unit, field_info->field_id));
    }

    if (is_validate_nof_instances && (field_info->nof_instances > max_nof_instances))
    {
        SHR_ERR_EXIT(_SHR_E_INTERNAL,
                     "Table %s, field %s has nof instances (%d) greater than max nof instances (%d) \n",
                     table->table_name, dbal_field_to_string(unit, field_info->field_id), field_info->nof_instances,
                     max_nof_instances);
    }

exit:
    SHR_FUNC_EXIT;
}

static shr_error_e
dbal_db_init_table_db_field_set_multiple_instances(
    int unit,
    dbal_logical_table_t * table_entry,
    dbal_table_field_info_t * field_info,
    uint8 is_key_fields,
    uint32 max_nof_instances,
    uint8 is_validate_nof_instances)
{
    int jj;
    SHR_FUNC_INIT_VARS(unit);

    DBAL_VERIFICATIONS(dbal_db_init_table_multiple_instances_verify
                       (unit, table_entry, is_key_fields, field_info, max_nof_instances, is_validate_nof_instances));

    for (jj = 1; jj < field_info->nof_instances; jj++)
    {
        dbal_table_field_info_t *field_info_instance = field_info + jj;
        sal_memcpy(field_info_instance, field_info, sizeof(dbal_table_field_info_t));

        field_info_instance->field_id = field_info->field_id;

        field_info_instance->inst_idx = jj;

        DBAL_VERIFICATIONS(dbal_db_init_table_db_field_has_single_field_type_verify
                           (unit, field_info_instance->field_id, field_info_instance->field_type));
    }
exit:
    SHR_FUNC_EXIT;
}

static shr_error_e
dbal_db_init_validate_nof_instances(
    int unit,
    dbal_logical_table_t * table_entry,
    dbal_table_field_info_t * field_info,
    uint8 is_key_fields)
{
    SHR_FUNC_INIT_VARS(unit);

    if ((is_key_fields == 0) && (field_info->nof_instances == 0))
    {
        SHR_ERR_EXIT(_SHR_E_INTERNAL, "Table %s, field %s, Number of instances = 0. Use"
                     "Valid attribute to disable a result field", table_entry->table_name,
                     dbal_field_to_string(unit, field_info->field_id));
    }
exit:
    SHR_FUNC_EXIT;
}

shr_error_e
dbal_db_init_table_field_set_optional_or_default_values(
    int unit,
    dbal_logical_table_t * table_entry,
    dbal_table_field_info_t * field_info,
    table_db_field_params_struct_t * field_read_data,
    uint8 is_key_fields)
{
    SHR_FUNC_INIT_VARS(unit);

    field_info->offset_in_logical_field = field_read_data->offset;
    field_info->permission = field_read_data->permission;
    SHR_IF_ERR_EXIT(dbal_db_init_table_db_field_set_field_nof_bits(unit, field_info, field_read_data->size));

    DBAL_VERIFICATIONS(dbal_db_init_table_db_field_effective_size_validate(unit, table_entry, field_info));

    SHR_IF_ERR_EXIT(dbal_db_init_table_db_field_handle_const_value(unit, field_info, field_read_data->const_value));
    if (!DBAL_DB_INIT_TABLE_DB_FIELD_IS_CONST_VALID(field_info))
    {
        SHR_IF_ERR_EXIT(dbal_db_init_table_db_field_set_max_value(unit, field_info, field_read_data->max_value,
                                                                  (field_read_data->arr_prefix_width != 0)));
        SHR_IF_ERR_EXIT(dbal_db_init_table_db_field_set_min_value(unit, field_info, field_read_data->min_value));
    }
    if (!is_key_fields && field_read_data->arr_prefix_width)
    {
        SHR_IF_ERR_EXIT(dbal_db_init_table_db_field_set_arr_prefix
                        (unit, field_info, field_read_data->arr_prefix_width, field_read_data->arr_prefix_value));
    }

    field_info->nof_instances = field_read_data->nof_instances;

    SHR_IF_ERR_EXIT(dbal_db_init_validate_nof_instances(unit, table_entry, field_info, is_key_fields));

    if (field_info->nof_instances > 1)
    {
        SHR_IF_ERR_EXIT(dbal_db_init_table_db_field_set_multiple_instances
                        (unit, table_entry, field_info, is_key_fields,
                         field_read_data->max_nof_instances, field_read_data->is_validate_nof_instances));
    }
exit:
    SHR_FUNC_EXIT;
}

void
dbal_db_init_table_calculate_key_size(
    dbal_logical_table_t * table_entry)
{
    int field_index;
    table_entry->key_size = 0;
    for (field_index = 0; field_index < table_entry->nof_key_fields; field_index++)
    {
        table_entry->key_size += table_entry->keys_info[field_index].field_nof_bits;
    }
}

shr_error_e
dbal_db_init_table_db_interface_results_alloc(
    int unit,
    dbal_logical_table_t * table_entry)
{
    int nof_multi_res_types;

    SHR_FUNC_INIT_VARS(unit);

    if (SHR_IS_BITSET(table_entry->indications_bm, DBAL_TABLE_IND_HAS_RESULT_TYPE)
        && sal_strncasecmp(table_entry->table_name, "ETM_PP_DESCRIPTOR_EXPANSION",
                           sizeof(table_entry->table_name)) != 0)
    {

        nof_multi_res_types = table_entry->nof_result_types + 1;
    }
    else if (sal_strncasecmp(table_entry->table_name, "ETM_PP_DESCRIPTOR_EXPANSION", sizeof(table_entry->table_name)) ==
             0)
    {
        nof_multi_res_types = dnx_data_dbal.table.nof_dynamic_tables_ppmc_multi_result_types_get(unit);
    }
    else
    {
        nof_multi_res_types = table_entry->nof_result_types;
    }

    SHR_ALLOC_SET_ZERO(table_entry->multi_res_info, (nof_multi_res_types * sizeof(multi_res_info_t)),
                       "multiple results info allocation", "%s%s%s\r\n", table_entry->table_name, EMPTY, EMPTY);
exit:
    SHR_FUNC_EXIT;
}

shr_error_e
dbal_db_init_table_add_result_type_physical_values_by_reference_field(
    int unit,
    multi_res_info_t * multi_res_info,
    dbal_field_types_defs_e reference_field)
{
    SHR_FUNC_INIT_VARS(unit);

    if ((reference_field == DBAL_FIELD_TYPE_DEF_EMPTY) || (multi_res_info->is_disabled))
    {
        SHR_EXIT();
    }

    multi_res_info->reference_field_id = reference_field;
    multi_res_info->result_type_nof_hw_values = 1;
    SHR_IF_ERR_EXIT(dbal_field_types_enum_name_to_hw_value_get(unit, multi_res_info->reference_field_id,
                                                               multi_res_info->result_type_name,
                                                               &(multi_res_info->result_type_hw_value[0])));
exit:
    SHR_FUNC_EXIT;
}

void
dbal_db_init_table_add_result_type_physical_values_by_result_type_index(
    dbal_logical_table_t * table_entry)
{
    multi_res_info_t *multi_res_info;
    int result_type_index;
    for (result_type_index = 0; result_type_index < table_entry->nof_result_types; result_type_index++)
    {
        multi_res_info = &(table_entry->multi_res_info[result_type_index]);
        multi_res_info->result_type_hw_value[0] = result_type_index;
        multi_res_info->result_type_nof_hw_values = 1;
    }
}

static shr_error_e
dbal_db_init_table_alloc_result_fields_for_dynamic_result_types(
    int unit,
    dbal_logical_table_t * table_entry)
{
    int ii = 0;
    int nof_result_fields = dnx_data_dbal.table.nof_dynamic_tables_result_fields_get(unit);
    int nof_multi_res_types = dnx_data_dbal.table.nof_dynamic_tables_ppmc_multi_result_types_get(unit);

    SHR_FUNC_INIT_VARS(unit);

    for (ii = table_entry->nof_result_types; ii < nof_multi_res_types; ii++)
    {
        SHR_ALLOC_SET_ZERO(table_entry->multi_res_info[ii].results_info,
                           (nof_result_fields * sizeof(dbal_table_field_info_t)), "results fields info allocation",
                           "%s%s%s\r\n", table_entry->table_name, EMPTY, EMPTY);
    }
exit:
    SHR_FUNC_EXIT;
}

static shr_error_e
dbal_db_init_table_alloc_result_fields_for_superset_result_type_or_for_dynamic_result_types(
    int unit,
    dbal_tables_e table_id,
    dbal_logical_table_t * table_entry)
{
    SHR_FUNC_INIT_VARS(unit);

    DNX_INIT_TIME_ANALYZER_DBAL_INIT_START(unit, DNX_INIT_TIME_ANALYSER_DBAL_L_INIT_ADD_TABLE_IF);

    if (table_id == DBAL_TABLE_ETM_PP_DESCRIPTOR_EXPANSION)
    {
        SHR_IF_ERR_EXIT(dbal_db_init_table_alloc_result_fields_for_dynamic_result_types(unit, table_entry));
    }
    else if (SHR_IS_BITSET(table_entry->indications_bm, DBAL_TABLE_IND_HAS_RESULT_TYPE))
    {
        DBAL_DB_INIT_TABLE_ALLOC_RESULT_FIELDS_FOR_SUPERSET_RESULT_TYPE(table_entry);
    }

exit:
    SHR_FUNC_EXIT;
}

shr_error_e
dbal_db_init_field_hw_entity_validate(
    int unit,
    int table_id,
    dbal_hl_l2p_field_info_t * access,
    uint8 is_reg,
    uint8 print_error)
{
    int is_field_exist;
    CONST dbal_logical_table_t *table;
    int memreg = is_reg ? access->reg[0] : access->memory[0];

    SHR_FUNC_INIT_VARS(unit);

    if (access->hw_field == DBAL_HL_ACCESS_HW_FIELD_INVALID)
    {
        SHR_EXIT();
    }

    SHR_IF_ERR_EXIT(dbal_tables_table_get(unit, table_id, &table));
    SHR_IF_ERR_EXIT(dbal_hl_access_is_field_exist_per_access(unit, table, memreg, access->hw_field,
                                                             !is_reg, &is_field_exist));

    if (!is_field_exist)
    {
#if !defined(SOC_NO_NAMES)
        SHR_ERR_EXIT(_SHR_E_ACCESS, "Table %s, invalid field: %s \n",
                     table->table_name, SOC_FIELD_NAME(unit, access->hw_field));
#else
        SHR_ERR_EXIT(_SHR_E_ACCESS, "Table %s, invalid field: %d \n", table->table_name, access->hw_field);
#endif
    }

exit:
    SHR_FUNC_EXIT;
}

static shr_error_e
dbal_db_init_hw_element_group_hw_entity_verify(
    int unit,
    int hw_entity,
    uint8 is_reg,
    dbal_tables_e table_id)
{
    int rv = 0;
    CONST dbal_logical_table_t *table;

    SHR_FUNC_INIT_VARS(unit);

    SHR_IF_ERR_EXIT(dbal_tables_table_get(unit, table_id, &table));

    rv = dbal_hl_access_regmem_validate(unit, table_id, hw_entity, is_reg);

    SHR_IF_ERR_EXIT_EXCEPT_IF(rv, _SHR_E_INTERNAL);

    if (rv == _SHR_E_INTERNAL)
    {
        const char *hw_entity_name = dbal_hl_access_regmem_name_get(unit, table, hw_entity, !is_reg);

        if (DBAL_DEVICE_STATE_UNDER_DEVELOPMENT == dnx_data_dbal.db_init.dbal_device_state_get(unit))
        {
            LOG_VERBOSE(BSL_LOG_MODULE,
                        (BSL_META_U(unit, "dbal_db_init_hw_element_group_handle : " "hw entity not found (%s)\n"),
                         hw_entity_name));
        }
        else
        {
            LOG_ERROR(BSL_LOG_MODULE,
                      (BSL_META_U(unit, "dbal_db_init_hw_element_group_handle: " "hw entity not found (%s)\n"),
                       hw_entity_name));
        }
    }

exit:
    SHR_FUNC_EXIT;
}

static shr_error_e
dbal_db_init_is_hw_group_exist(
    int unit,
    hl_group_info_t * group_info,
    dbal_hw_entity_group_e hw_entity_group_id,
    dbal_tables_e table_id)
{
    SHR_FUNC_INIT_VARS(unit);

    if (group_info->group_hw_entity_num == 0)
    {
        SHR_ERR_EXIT(_SHR_E_INTERNAL, "Table %s: hw group %s is not defined\n",
                     dbal_logical_table_to_string(unit, table_id),
                     dbal_hw_entity_group_to_string(unit, hw_entity_group_id));
    }

exit:
    SHR_FUNC_EXIT;
}

shr_error_e
dbal_db_init_hw_element_group_handle(
    int unit,
    dbal_tables_e table_id,
    dbal_hw_entity_group_e hw_entity_group_id,
    dbal_hl_l2p_field_info_t * access_entry,
    int *is_reg)
{
    hl_group_info_t *group_info;
    int hw_entity_index;
    int hw_entity;
    uint32 is_new_access;

    SHR_FUNC_INIT_VARS(unit);

    SHR_IF_ERR_EXIT(dbal_tables_group_info_get(unit, hw_entity_group_id, &group_info));

    SHR_IF_ERR_EXIT_NO_MSG(dbal_db_init_is_hw_group_exist(unit, group_info, hw_entity_group_id, table_id));

    (*is_reg) = group_info->is_reg;

    if (*is_reg)
    {
        SHR_ALLOC_SET_ZERO(access_entry->reg, ((group_info->group_hw_entity_num + 1) * sizeof(int)),
                           "HL access register", "%s%s%s\r\n", dbal_hw_entity_group_to_string(unit, hw_entity_group_id),
                           EMPTY, EMPTY);
    }
    else
    {
        SHR_ALLOC_SET_ZERO(access_entry->memory, ((group_info->group_hw_entity_num + 1) * sizeof(int)),
                           "HL access memory", "%s%s%s\r\n", dbal_hw_entity_group_to_string(unit, hw_entity_group_id),
                           EMPTY, EMPTY);
    }

    SHR_IF_ERR_EXIT(dbal_tables_indication_get(unit, table_id, DBAL_TABLE_IND_IS_NEW_ACCESS, &is_new_access));

    for (hw_entity_index = 0; hw_entity_index < group_info->group_hw_entity_num; hw_entity_index++)
    {
        hw_entity = group_info->hw_entity_id[hw_entity_index];
        if (!is_new_access)
        {
            SHR_IF_ERR_EXIT(dbal_db_init_hw_element_group_hw_entity_verify(unit, hw_entity, *is_reg, table_id));
        }

        if (*is_reg)
        {
            access_entry->reg[hw_entity_index] = hw_entity;
        }
        else
        {
            access_entry->memory[hw_entity_index] = hw_entity;
        }
    }
    if (*is_reg)
    {
        access_entry->reg[hw_entity_index] = DBAL_HL_ACCESS_HW_ENTITY_INVALID;
    }
    else
    {
        access_entry->memory[hw_entity_index] = DBAL_HL_ACCESS_HW_ENTITY_INVALID;
    }

exit:
    SHR_FUNC_EXIT;
}

shr_error_e
dbal_db_init_hw_element_group_info_init(
    int unit,
    hl_groups_info_t * groups_info)
{
    SHR_FUNC_INIT_VARS(unit);

    groups_info->nof_groups = DBAL_NOF_HW_ENTITY_GROUPS;
    groups_info->group_info = NULL;

    SHR_ALLOC_SET_ZERO(groups_info->group_info, (DBAL_NOF_HW_ENTITY_GROUPS * sizeof(hl_group_info_t)),
                       "group_info", "%s%s%s\r\n", EMPTY, EMPTY, EMPTY);

    if (DBAL_IS_DNX2(unit))
    {
        SHR_IF_ERR_EXIT(dbal_init_hw_entity_groups_init(unit, groups_info->group_info));
    }
exit:
    SHR_FUNC_EXIT;
}

static shr_error_e
dbal_db_init_table_add_access_conditions(
    int unit,
    dbal_tables_e table_id,
    dbal_hl_l2p_field_info_t * access_entry,
    table_db_access_params_struct_t * access_params)
{
    int ii;
    SHR_FUNC_INIT_VARS(unit);

    access_entry->nof_conditions = access_params->nof_conditions;
    if (access_entry->nof_conditions > 0)
    {
        if (access_entry->nof_conditions > DBAL_FIELD_MAX_NUM_OF_CONDITIONS)
        {
            SHR_ERR_EXIT(_SHR_E_INTERNAL, "Table %s has more conditions than max allowed.\n",
                         dbal_logical_table_to_string(unit, table_id));
        }

        SHR_ALLOC_SET_ZERO(access_entry->mapping_condition,
                           access_entry->nof_conditions * sizeof(dbal_access_condition_info_t), "HL mapping condition",
                           "%s%s%s\r\n", dbal_logical_table_to_string(unit, table_id), EMPTY, EMPTY);
    }

    for (ii = 0; ii < access_params->nof_conditions; ii++)
    {
        SHR_IF_ERR_EXIT(dbal_db_init_condition_parsing(unit, table_id, &access_entry->mapping_condition[ii],
                                                       &access_params->access_condition[ii]));
    }

exit:
    SHR_FUNC_EXIT;
}

static shr_error_e
dbal_db_init_table_add_hl_memory_register(
    int unit,
    dbal_tables_e table_id,
    dbal_hl_l2p_field_info_t * access_entry,
    table_db_access_params_struct_t * access_params)
{
    int is_reg = 0;

    SHR_FUNC_INIT_VARS(unit);

    if (access_params->hw_entity_group_id != DBAL_HW_ENTITY_GROUP_EMPTY)
    {
        access_entry->hw_entity_group_id = access_params->hw_entity_group_id;
        SHR_IF_ERR_EXIT(dbal_db_init_hw_element_group_handle
                        (unit, table_id, access_params->hw_entity_group_id, access_entry, &is_reg));
    }
    else
    {
        is_reg = (access_params->access_type == DBAL_HL_ACCESS_REGISTER);
        SHR_IF_ERR_EXIT(dbal_hl_access_regmem_validate(unit, table_id, access_params->reg_mem_hw_entity_id, is_reg));

        if (!is_reg)
        {
            SHR_ALLOC_SET_ZERO(access_entry->memory, 2 * sizeof(soc_mem_t), "HL access memory",
                               "%s%s%s\r\n", dbal_hw_entity_group_to_string(unit, access_params->reg_mem_hw_entity_id),
                               EMPTY, EMPTY);

            access_entry->memory[0] = access_params->reg_mem_hw_entity_id;
            access_entry->memory[1] = DBAL_HL_ACCESS_HW_ENTITY_INVALID;

            if (access_params->alias_reg_mem_hw_entity_id != DBAL_HL_ACCESS_HW_ENTITY_INVALID)
            {
                access_entry->alias_memory = access_params->alias_reg_mem_hw_entity_id;
            }
        }
        else
        {
            SHR_ALLOC_SET_ZERO(access_entry->reg, 2 * sizeof(soc_reg_t), "HL access register",
                               "%s%s%s\r\n", dbal_hw_entity_group_to_string(unit, access_params->reg_mem_hw_entity_id),
                               EMPTY, EMPTY);
            access_entry->reg[0] = access_params->reg_mem_hw_entity_id;
            access_entry->reg[1] = DBAL_HL_ACCESS_HW_ENTITY_INVALID;

            if (access_params->alias_reg_mem_hw_entity_id != DBAL_HL_ACCESS_HW_ENTITY_INVALID)
            {
                access_entry->alias_reg = access_params->alias_reg_mem_hw_entity_id;
            }
        }
    }

    access_entry->hw_field = access_params->hw_field;

    access_entry->encode_info.encode_mode = access_params->encode_type;
    access_entry->encode_info.input_param = access_params->encode_param1;

    SHR_IF_ERR_EXIT(dbal_db_init_offset_parsing(unit, &access_entry->array_offset_info, &access_params->array_offset));
    SHR_IF_ERR_EXIT(dbal_db_init_offset_parsing(unit, &access_entry->block_index_info, &access_params->block_index));
    SHR_IF_ERR_EXIT(dbal_db_init_offset_parsing(unit, &access_entry->entry_offset_info, &access_params->entry_offset));
    SHR_IF_ERR_EXIT(dbal_db_init_offset_parsing(unit, &access_entry->data_offset_info, &access_params->data_offset));
    SHR_IF_ERR_EXIT(dbal_db_init_offset_parsing
                    (unit, &access_entry->alias_data_offset_info, &access_params->alias_data_offset));
    SHR_IF_ERR_EXIT(dbal_db_init_offset_parsing(unit, &access_entry->group_offset_info, &access_params->group_offset));
exit:
    SHR_FUNC_EXIT;
}

static shr_error_e
dbal_db_init_l2p_field_id_has_valid_interface_field(
    int unit,
    dbal_tables_e table_id,
    dbal_logical_table_t * table_entry,
    dbal_fields_e field_id,
    uint8 inst_idx,
    int result_idx,
    uint8 *has_valid_interface_field)
{

    SHR_FUNC_INIT_VARS(unit);

    DBAL_DB_INIT_L2P_FIELD_ID_HAS_VALID_INTERFACE_FIELD_VERIFY(table_entry, field_id);

    if (table_entry->table_type == DBAL_TABLE_TYPE_DIRECT)
    {
        int field_index_in_table = 0;
        int rv = dbal_tables_field_index_in_table_get_no_err(unit, table_id, field_id, FALSE, result_idx, inst_idx,
                                                             &field_index_in_table);
        SHR_IF_ERR_EXIT_EXCEPT_IF(rv, _SHR_E_NOT_FOUND);
        *has_valid_interface_field = UTILEX_NUM2BOOL(rv != _SHR_E_NOT_FOUND);
    }

    else
    {
        *has_valid_interface_field = TRUE;
    }

exit:
    SHR_FUNC_EXIT;

}

static shr_error_e
dbal_db_init_nof_valid_access_fields_get(
    int unit,
    dbal_tables_e table_id,
    dbal_logical_table_t * table_entry,
    table_db_hl_access_struct_t * hl_access_param,
    int result_idx,
    int nof_valid_access_fields[])
{
    int access_param_index;
    uint8 has_valid_interface_field = FALSE;
    dbal_hard_logic_access_types_e access_type;

    SHR_FUNC_INIT_VARS(unit);

    for (access_param_index = 0; access_param_index < hl_access_param->nof_access; access_param_index++)
    {
        dbal_fields_e access_field_id = hl_access_param->access[access_param_index].access_field_id;
        uint8 access_field_inst_idx = hl_access_param->access[access_param_index].inst_idx;
        SHR_IF_ERR_EXIT(dbal_db_init_l2p_field_id_has_valid_interface_field
                        (unit, table_id, table_entry, access_field_id, access_field_inst_idx, result_idx,
                         &has_valid_interface_field));

        if (has_valid_interface_field)
        {
            access_type = hl_access_param->access[access_param_index].access_type;
            nof_valid_access_fields[access_type]++;
        }
    }
exit:
    SHR_FUNC_EXIT;

}

static shr_error_e
dbal_db_init_hl_l2p_fields_alloc_and_init_with_default_internal(
    int unit,
    dbal_tables_e table_id,
    dbal_hl_access_info_t * hl_mapping,
    int nof_valid_access_fields[])
{
    int access_type_index, access_field_index;

    CONST static dbal_hl_l2p_field_info_t hl_default_mapping = {
        DBAL_FIELD_EMPTY,
        0,
        0,
        0,
        0,
        {0},
        0,
        0,
        0,
        NULL,
        NULL,
        0,
        DBAL_HL_ACCESS_HW_FIELD_INVALID,
        0,
        DBAL_HW_ENTITY_GROUP_EMPTY,
        {0},
        {0},
        {0},
        {0},
        {0},
        DBAL_HL_ACCESS_HW_ENTITY_INVALID,
        DBAL_HL_ACCESS_HW_ENTITY_INVALID,
        {0},
        0,
        NULL
    };

    SHR_FUNC_INIT_VARS(unit);

    for (access_type_index = 0; access_type_index < DBAL_NOF_HL_ACCESS_TYPES; access_type_index++)
    {

        hl_mapping->l2p_hl_info[access_type_index].l2p_fields_info = NULL;
        if (nof_valid_access_fields[access_type_index] > 0)
        {
            SHR_ALLOC_ERR_EXIT(hl_mapping->l2p_hl_info[access_type_index].l2p_fields_info,
                               nof_valid_access_fields[access_type_index] * sizeof(dbal_hl_l2p_field_info_t),
                               "HL Access allocation", "%s%s%s\r\n", dbal_logical_table_to_string(unit, table_id),
                               EMPTY, EMPTY);

            for (access_field_index = 0; access_field_index < nof_valid_access_fields[access_type_index];
                 access_field_index++)
            {
                hl_mapping->l2p_hl_info[access_type_index].l2p_fields_info[access_field_index] = hl_default_mapping;
            }
        }
    }
exit:
    SHR_FUNC_EXIT;
}

static shr_error_e
dbal_db_init_hl_l2p_fields_alloc_and_init_with_default(
    int unit,
    dbal_tables_e table_id,
    dbal_logical_table_t * table_entry,
    table_db_hl_access_struct_t * hl_access_param,
    int result_idx)
{

    int nof_valid_access_fields[DBAL_NOF_HL_ACCESS_TYPES] = { 0 };
    dbal_hl_access_info_t *hl_mapping = &table_entry->hl_mapping_multi_res[result_idx];

    SHR_FUNC_INIT_VARS(unit);

    SHR_IF_ERR_EXIT(dbal_db_init_nof_valid_access_fields_get
                    (unit, table_id, table_entry, hl_access_param, result_idx, nof_valid_access_fields));
    dbal_db_init_hl_l2p_fields_alloc_and_init_with_default_internal(unit, table_id, hl_mapping,
                                                                    nof_valid_access_fields);

exit:
    SHR_FUNC_EXIT;
}

static shr_error_e
dbal_db_init_hl_l2p_field_set(
    int unit,
    dbal_tables_e table_id,
    dbal_logical_table_t * table_entry,
    table_db_access_params_struct_t * access_param,
    dbal_hl_l2p_field_info_t * access_entry)
{
    dbal_fields_e access_field_id = access_param->access_field_id;

    SHR_FUNC_INIT_VARS(unit);

    if (table_entry->table_type == DBAL_TABLE_TYPE_DIRECT)
    {
        access_entry->field_id = access_field_id;
    }
    else if (DBAL_TABLE_IS_TCAM(table_entry))
    {

        access_entry->hl_tcam_access_type = access_param->tcam_access_type;
    }
    else
    {
        SHR_ERR_EXIT(_SHR_E_INTERNAL, "Unsupported table type for hard logic table: %s. Table %s \n",
                     dbal_table_type_to_string(unit, table_entry->table_type), table_entry->table_name);
    }

    access_entry->access_nof_bits = access_param->access_size;
    access_entry->access_offset = access_param->access_offset;
    access_entry->inst_idx = access_param->inst_idx;

    switch (access_param->access_type)
    {
        case DBAL_HL_ACCESS_MEMORY:
        case DBAL_HL_ACCESS_REGISTER:
        {
            int rv = dbal_db_init_table_add_hl_memory_register(unit, table_id, access_entry, access_param);
            if (rv)
            {
                SHR_SET_CURRENT_ERR(rv);
                SHR_EXIT();
            }
            break;
        }
        default:
            break;
    }

    SHR_IF_ERR_EXIT(dbal_db_init_table_add_access_conditions(unit, table_id, access_entry, access_param));

exit:
    SHR_FUNC_EXIT;
}

static shr_error_e
dbal_db_init_add_result_type_hl_mapping(
    int unit,
    dbal_tables_e table_id,
    dbal_logical_table_t * table_entry,
    table_db_hl_access_struct_t * hl_access_param,
    int result_idx)
{
    int access_param_index;
    dbal_hl_l2p_field_info_t *access_entry;
    dbal_hard_logic_access_types_e access_type;
    dbal_hl_access_info_t *hl_mapping = &table_entry->hl_mapping_multi_res[result_idx];
    int rv = _SHR_E_NONE;
    SHR_FUNC_INIT_VARS(unit);

    SHR_IF_ERR_EXIT(dbal_db_init_hl_l2p_fields_alloc_and_init_with_default
                    (unit, table_id, table_entry, hl_access_param, result_idx));

    for (access_param_index = 0; access_param_index < hl_access_param->nof_access; access_param_index++)
    {
        uint8 has_valid_interface_field = FALSE;
        table_db_access_params_struct_t *access_param = &hl_access_param->access[access_param_index];
        SHR_IF_ERR_EXIT(dbal_db_init_l2p_field_id_has_valid_interface_field
                        (unit, table_id, table_entry, access_param->access_field_id, access_param->inst_idx, result_idx,
                         &has_valid_interface_field));

        if (!has_valid_interface_field)
        {
            continue;
        }

        access_type = access_param->access_type;

        access_entry = hl_mapping->l2p_hl_info[access_type].l2p_fields_info
            + hl_mapping->l2p_hl_info[access_type].num_of_access_fields;
        hl_mapping->l2p_hl_info[access_type].num_of_access_fields++;

        rv = dbal_db_init_hl_l2p_field_set(unit, table_id, table_entry, access_param, access_entry);
        if (rv)
        {
            SHR_SET_CURRENT_ERR(rv);
            SHR_EXIT();
        }
    }

exit:
    SHR_FUNC_EXIT;
}

static uint8
is_dbal_db_init_status_incompatible_image(
    int unit,
    uint8 is_standard_table,
    uint8 is_compatible_with_all_images)
{

    return ((!is_compatible_with_all_images) && (is_standard_table) && (!dbal_image_name_is_std_1(unit)));
}

shr_error_e
dbal_db_init_table_incompatible_image_indication_set(
    int unit,
    dbal_tables_e table_id,
    uint8 is_standard_table,
    uint8 is_compatible_with_all_images)
{

    SHR_FUNC_INIT_VARS(unit);

    if (!is_dbal_db_init_status_incompatible_image(unit, is_standard_table, is_compatible_with_all_images))
    {
        SHR_EXIT();
    }

    if (sw_state_is_warm_boot(unit))
    {
        SHR_EXIT();
    }

    SHR_IF_ERR_EXIT(DBAL_SW_STATE_TBL_PROP.table_status.set(unit, table_id, DBAL_TABLE_INCOMPATIBLE_IMAGE));

exit:
    SHR_FUNC_EXIT;
}

static shr_error_e
dbal_db_init_table_add_mapping_mdb(
    int unit,
    dbal_logical_table_t * table_entry,
    dbal_tables_e table_id,
    table_db_struct_t * table_params)
{
    dbal_core_mode_e core_mode;
    SHR_FUNC_INIT_VARS(unit);

    if (table_params->mdb_access->app_db_id_size != 0)
    {
        table_entry->app_id_size = table_params->mdb_access->app_db_id_size;
        table_entry->app_id = table_params->mdb_access->app_db_id;
    }

    SHR_IF_ERR_EXIT(dbal_physical_table_string_to_id
                    (unit, table_params->mdb_access->phy_db, &table_entry->physical_db_id[0]));
    table_entry->nof_physical_tables = 1;

    SHR_IF_ERR_EXIT(dbal_mdb_phy_table_is_valid(unit, table_entry->physical_db_id[0]));
    core_mode = dbal_mdb_phy_table_core_mode_get(unit, table_entry->physical_db_id[0]);

    if (!dnx_data_dbal.table.feature_get(unit, dnx_data_dbal_table_support_mdb_general_phys_db))
    {

        if (DBAL_MAX_NUM_OF_CORES > 1)
        {
            if ((table_entry->core_mode == DBAL_CORE_MODE_DPC) || (core_mode == DBAL_CORE_MODE_DPC))
            {
                int core_idx;
                for (core_idx = 1; core_idx < dnx_data_device.general.nof_cores_per_core_group_get(unit); core_idx++)
                {
                    table_entry->physical_db_id[core_idx] = table_entry->physical_db_id[0] + core_idx;
                }
                table_entry->nof_physical_tables = dnx_data_device.general.nof_cores_per_core_group_get(unit);
            }
        }
        else
        {

            int num_of_dbs_to_duplicate = 2;
            if ((table_entry->core_mode == DBAL_CORE_MODE_DPC) || (core_mode == DBAL_CORE_MODE_DPC))
            {
                int core_idx;
                for (core_idx = 1; core_idx < num_of_dbs_to_duplicate; core_idx++)
                {
                    table_entry->physical_db_id[core_idx] = table_entry->physical_db_id[0] + core_idx;
                }
                table_entry->nof_physical_tables = num_of_dbs_to_duplicate;
            }
        }
    }

    if (table_entry->table_type != DBAL_TABLE_TYPE_LPM)
    {
        SHR_IF_ERR_EXIT(dbal_tables_hitbit_enable(unit, table_id, TRUE));
    }

exit:
    SHR_FUNC_EXIT;
}

static shr_error_e
dbal_db_init_table_add_mapping_tcam_cs(
    int unit,
    dbal_logical_table_t * table_entry,
    dbal_tables_e table_id,
    table_db_struct_t * table_params)
{
    int rv;
    dbal_tcam_cs_stage_info_t cs_tcam_db_stage_info;
    int hw_key_size = table_entry->key_size;

    SHR_FUNC_INIT_VARS(unit);

    table_entry->dbal_stage = table_params->pipe_stage;

    if (table_entry->core_mode == DBAL_CORE_MODE_DPC)
    {
        hw_key_size = table_entry->key_size - DBAL_CORE_SIZE_IN_BITS;
    }

    if (table_entry->dbal_stage >= DBAL_NOF_STAGES ||
        dnx_data_ingress_cs.properties.per_stage_get(unit, table_entry->dbal_stage)->valid == FALSE)
    {
        SHR_ERR_EXIT(_SHR_E_INTERNAL, "Context Selection dbal_stage %s (%d) does not have DNX data.\n",
                     dbal_stage_to_string(unit, table_entry->dbal_stage), table_entry->dbal_stage);
    }

    rv = dbal_tcam_cs_stage_info_get(unit, table_entry->dbal_stage, &cs_tcam_db_stage_info);
    if (SHR_FAILURE(rv))
    {
        LOG_CLI((BSL_META_U(unit, "Error in table %s init\n"), table_entry->table_name));
        SHR_IF_ERR_EXIT(dbal_tables_update_hw_error(unit, table_id));
        SHR_EXIT();
    }

    if (hw_key_size > cs_tcam_db_stage_info.line_length_key_only)
    {
        SHR_ERR_EXIT(_SHR_E_INTERNAL, "DBAL table %s (%d), that uses context selection dbal_stage %s (%d) "
                     "has more bits on key (%d) than the CS TCAM it uses (%d).\n",
                     dbal_logical_table_to_string(unit, table_id), table_id,
                     dbal_stage_to_string(unit, table_entry->dbal_stage), table_entry->dbal_stage,
                     hw_key_size, cs_tcam_db_stage_info.line_length_key_only);
    }

    if (cs_tcam_db_stage_info.line_length_with_key_size_prefix >
        dnx_data_ingress_cs.properties.cs_buffer_nof_bits_max_get(unit))
    {
        SHR_ERR_EXIT(_SHR_E_INTERNAL, "Context Selection dbal_stage %s (%d) has more bits on key (%d) "
                     "than the value provided in DNX DATA as the maximum for all CS TCAMs (%d).\n",
                     dbal_stage_to_string(unit, table_entry->dbal_stage), table_entry->dbal_stage,
                     cs_tcam_db_stage_info.line_length_with_key_size_prefix,
                     dnx_data_ingress_cs.properties.cs_buffer_nof_bits_max_get(unit));
    }

    if (cs_tcam_db_stage_info.line_length_with_key_size_prefix <= 0 || cs_tcam_db_stage_info.line_length_key_only <= 0)
    {
        SHR_ERR_EXIT(_SHR_E_INTERNAL, "Context Selection dbal_stage %s (%d) has zero key.\n",
                     dbal_stage_to_string(unit, table_entry->dbal_stage), table_entry->dbal_stage);
    }

    if (cs_tcam_db_stage_info.supports_half_entries)
    {

        if (((cs_tcam_db_stage_info.line_length_with_key_size_prefix % 2) != 0) ||
            ((cs_tcam_db_stage_info.line_length_key_only % 2) != 0))
        {
            SHR_ERR_EXIT(_SHR_E_INTERNAL, "Context Selection dbal_stage %s (%d) supports half entries, but line "
                         "length is not even (%d).\n",
                         dbal_stage_to_string(unit, table_entry->dbal_stage), table_entry->dbal_stage,
                         cs_tcam_db_stage_info.line_length_with_key_size_prefix);
        }

        if ((cs_tcam_db_stage_info.line_length_with_key_size_prefix <
             (2 * dnx_data_ingress_cs.properties.nof_bits_entry_size_prefix_get(unit))) ||
            (cs_tcam_db_stage_info.line_length_with_key_size_prefix < cs_tcam_db_stage_info.line_length_key_only) ||
            (cs_tcam_db_stage_info.line_length_key_only < 0))
        {
            SHR_ERR_EXIT(_SHR_E_INTERNAL, "Context Selection dbal_stage %s (%d) supports half entries, but key "
                         "size (%d) is not sufficient for entry size prefix.\n",
                         dbal_stage_to_string(unit, table_entry->dbal_stage), table_entry->dbal_stage,
                         cs_tcam_db_stage_info.line_length_with_key_size_prefix);
        }

        if (hw_key_size > cs_tcam_db_stage_info.line_length_key_only)
        {
            SHR_ERR_EXIT(_SHR_E_INTERNAL, "Context Selection dbal_stage %s (%d) supports half entries, but key "
                         "size (%d) of DBAL table exceeds full key size (%d) of the CS TCAM.\n",
                         dbal_stage_to_string(unit, table_entry->dbal_stage), table_entry->dbal_stage,
                         hw_key_size, cs_tcam_db_stage_info.line_length_key_only);
        }

        if (hw_key_size > (cs_tcam_db_stage_info.line_length_key_only / 2))
        {
            SHR_ERR_EXIT(_SHR_E_PARAM,
                         "Full entries in a CS TCAM that supports half entries not yet supported. "
                         "table %s (%d), CS TCAM %s (%d), key size %d out of %d.\n",
                         dbal_logical_table_to_string(unit, table_id), table_id,
                         dbal_stage_to_string(unit, table_entry->dbal_stage), table_entry->dbal_stage,
                         hw_key_size, cs_tcam_db_stage_info.line_length_key_only);
        }
    }

    SHR_ALLOC_SET_ZERO(table_entry->tcam_cs_mapping, sizeof(dbal_cs_access_info_t),
                       "CS mapping allocation", "%s%s%s\r\n", table_entry->table_name, EMPTY, EMPTY);

    table_entry->tcam_cs_mapping->memory = table_params->cs_access->reg_mem_hw_entity_id;
exit:
    SHR_FUNC_EXIT;
}

static shr_error_e
dbal_db_init_table_add_mapping_pemla(
    int unit,
    dbal_logical_table_t * table_entry,
    dbal_tables_e table_id,
    table_db_struct_t * table_params)
{
    int ii;
    int nof_key_fields, nof_result_fields;

    SHR_FUNC_INIT_VARS(unit);

    table_entry->app_id = 0;

    nof_key_fields = table_entry->nof_key_fields;
    nof_result_fields = table_entry->multi_res_info[0].nof_result_fields;

    SHR_ALLOC_SET_ZERO(table_entry->pemla_mapping.key_fields_mapping, nof_key_fields * sizeof(uint32),
                       "pemla key mapping allocation", "%s%s%s\r\n", table_entry->table_name, EMPTY, EMPTY);

    SHR_ALLOC_SET_ZERO(table_entry->pemla_mapping.result_fields_mapping, nof_result_fields * sizeof(uint32),
                       "pemla result mapping allocation", "%s%s%s\r\n", table_entry->table_name, EMPTY, EMPTY);

    for (ii = 0; ii < nof_key_fields; ii++)
    {
        table_entry->pemla_mapping.key_fields_mapping[ii] = table_params->pemla_access->pemla_key_mapping[ii];
    }

    for (ii = 0; ii < nof_result_fields; ii++)
    {
        table_entry->pemla_mapping.result_fields_mapping[ii] = table_params->pemla_access->pemla_result_mapping[ii];
    }

exit:
    SHR_FUNC_EXIT;
}

static shr_error_e
dbal_db_init_hl_sw_size_per_result_type_get(
    int unit,
    dbal_tables_e table_id,
    dbal_logical_table_t * table_entry,
    int result_idx,
    int *hl_sw_size_per_result_type)
{
    int sw_access_field_index;
    dbal_hl_l2p_field_info_t *access_entry;
    int nof_sw_access_field =
        table_entry->hl_mapping_multi_res[result_idx].l2p_hl_info[DBAL_HL_ACCESS_SW].num_of_access_fields;
    SHR_FUNC_INIT_VARS(unit);

    *hl_sw_size_per_result_type = 0;

    for (sw_access_field_index = 0; sw_access_field_index < nof_sw_access_field; sw_access_field_index++)
    {
        access_entry =
            &table_entry->hl_mapping_multi_res[result_idx].
            l2p_hl_info[DBAL_HL_ACCESS_SW].l2p_fields_info[sw_access_field_index];

        if (access_entry->access_nof_bits == 0)
        {
            int field_size = 0;
            SHR_IF_ERR_EXIT(dbal_tables_field_size_get
                            (unit, table_id, access_entry->field_id, FALSE, result_idx, 0, &field_size));
            *hl_sw_size_per_result_type += field_size;
        }
        else
        {
            *hl_sw_size_per_result_type += access_entry->access_nof_bits;
        }
    }

exit:
    SHR_FUNC_EXIT;

}

static shr_error_e
dbal_db_init_table_add_mapping_hard_logic(
    int unit,
    dbal_logical_table_t * table_entry,
    dbal_tables_e table_id,
    table_db_struct_t * table_params)
{
    int max_hl_sw_part_size_bytes = 0, hl_sw_sizse_per_result_type = 0;
    int ii, jj;
    int rv;

    table_db_hl_access_struct_t *hl_access_param;
    SHR_FUNC_INIT_VARS(unit);

    DNX_INIT_TIME_ANALYZER_DBAL_INIT_START(unit, DNX_INIT_TIME_ANALYSER_DBAL_L_INIT_ADD_TABLE_MAP_HL);

    if (table_params->is_hook_active)
    {
        SHR_BITSET(table_entry->indications_bm, DBAL_TABLE_IND_IS_HOOK_ACTIVE);
    }

    SHR_ALLOC_SET_ZERO(table_entry->hl_mapping_multi_res,
                       table_entry->nof_result_types * sizeof(dbal_hl_access_info_t),
                       "multiple result direct mapping allocation", "%s%s%s\r\n",
                       table_entry->table_name, EMPTY, EMPTY);

    for (ii = 0; ii < table_entry->nof_result_types; ii++)
    {

        if (table_entry->nof_result_types > 1)
        {
            for (jj = 0; jj < table_entry->nof_result_types; jj++)
            {
                if (sal_strncmp(table_entry->multi_res_info[ii].result_type_name,
                                table_params->hl_access[jj].mapping_result_name,
                                sizeof(table_entry->multi_res_info[ii].result_type_name)) == 0)
                {
                    break;
                }
            }
            if (jj == table_entry->nof_result_types)
            {
                SHR_ERR_EXIT(_SHR_E_INTERNAL, "Cannot find result type %s in result mapping names. table:%s\n",
                             table_entry->multi_res_info[ii].result_type_name, table_entry->table_name);
            }
        }
        else
        {
            jj = 0;
        }

        if (table_entry->multi_res_info[ii].is_disabled)
        {
            continue;
        }
        hl_access_param = &table_params->hl_access[jj];

        DNX_INIT_TIME_ANALYZER_DBAL_INIT_START(unit, DNX_INIT_TIME_ANALYSER_DBAL_L_INIT_ADD_TABLE_MAP_HL_RES_TYPE);
        rv = dbal_db_init_add_result_type_hl_mapping(unit, table_id, table_entry, hl_access_param, ii);
        DNX_INIT_TIME_ANALYZER_DBAL_INIT_STOP(unit, DNX_INIT_TIME_ANALYSER_DBAL_L_INIT_ADD_TABLE_MAP_HL_RES_TYPE);

        if (SHR_FAILURE(rv))
        {
            SHR_IF_ERR_EXIT(dbal_tables_update_hw_error(unit, table_id));
            SHR_EXIT();
        }

        SHR_IF_ERR_EXIT(dbal_db_init_hl_sw_size_per_result_type_get
                        (unit, table_id, table_entry, ii, &hl_sw_sizse_per_result_type));

        max_hl_sw_part_size_bytes = UTILEX_MAX(max_hl_sw_part_size_bytes, BITS2BYTES(hl_sw_sizse_per_result_type));
    }

    if (max_hl_sw_part_size_bytes > 0)
    {

        table_entry->sw_access_info.sw_payload_length_bytes = max_hl_sw_part_size_bytes;
    }

    DNX_INIT_TIME_ANALYZER_DBAL_INIT_STOP(unit, DNX_INIT_TIME_ANALYSER_DBAL_L_INIT_ADD_TABLE_MAP_HL);

exit:
    SHR_FUNC_EXIT;
}

shr_error_e
dbal_db_init_table_add(
    int unit,
    table_db_struct_t * table_params,
    dbal_tables_e table_id,
    dbal_logical_table_t * table_info)
{
    dbal_logical_table_t *table_entry;

    SHR_FUNC_INIT_VARS(unit);

    table_entry = table_info + table_id;

    SHR_IF_ERR_EXIT(dbal_db_init_table_alloc_result_fields_for_superset_result_type_or_for_dynamic_result_types
                    (unit, table_id, table_entry));

    DBAL_DB_INIT_TABLE_UPDATE_HW_ERROR_AND_EXIT_INIT_IF_CORE_MODE_NOT_SET(table_id, table_entry);

    {
        dbal_table_status_e table_status;
        SHR_IF_ERR_EXIT(DBAL_SW_STATE_TBL_PROP.table_status.get(unit, table_id, &table_status));
        if (table_status == DBAL_TABLE_INCOMPATIBLE_IMAGE)
        {

            if (table_id != DBAL_TABLE_ETM_PP_DESCRIPTOR_EXPANSION)
            {
                SHR_EXIT();
            }
        }
    }

    switch (table_entry->access_method)
    {
        case DBAL_ACCESS_METHOD_HARD_LOGIC:
            SHR_IF_ERR_EXIT(dbal_db_init_table_add_mapping_hard_logic(unit, table_entry, table_id, table_params));
            break;

        case DBAL_ACCESS_METHOD_MDB:
            DNX_INIT_TIME_ANALYZER_DBAL_INIT_START(unit, DNX_INIT_TIME_ANALYSER_DBAL_L_INIT_ADD_TABLE_MAP_MDB);
            SHR_IF_ERR_EXIT(dbal_db_init_table_add_mapping_mdb(unit, table_entry, table_id, table_params));
            DNX_INIT_TIME_ANALYZER_DBAL_INIT_STOP(unit, DNX_INIT_TIME_ANALYSER_DBAL_L_INIT_ADD_TABLE_MAP_MDB);
            break;

        case DBAL_ACCESS_METHOD_TCAM_CS:
            DNX_INIT_TIME_ANALYZER_DBAL_INIT_START(unit, DNX_INIT_TIME_ANALYSER_DBAL_L_INIT_ADD_TABLE_MAP_TCAM_CS);
            SHR_IF_ERR_EXIT(dbal_db_init_table_add_mapping_tcam_cs(unit, table_entry, table_id, table_params));
            DNX_INIT_TIME_ANALYZER_DBAL_INIT_STOP(unit, DNX_INIT_TIME_ANALYSER_DBAL_L_INIT_ADD_TABLE_MAP_TCAM_CS);
            break;

        case DBAL_ACCESS_METHOD_SW_STATE:
            break;

        case DBAL_ACCESS_METHOD_PEMLA:
            SHR_IF_ERR_EXIT(dbal_db_init_table_add_mapping_pemla(unit, table_entry, table_id, table_params));
            break;

        case DBAL_ACCESS_METHOD_KBP:
#if defined(INCLUDE_KBP)
            SHR_ALLOC_SET_ZERO(table_entry->kbp_handles, sizeof(kbp_db_handles_t) * DNX_KBP_NOF_DBS_PER_CORE,
                               "KBP handles allocation", "%s%s%s\r\n", table_entry->table_name, EMPTY, EMPTY);
#endif
            break;
        default:
            break;
    }

    SHR_IF_ERR_EXIT(dbal_db_init_table_capacity_calculate(unit, table_id, table_entry, table_params));

exit:
    SHR_FUNC_EXIT;
}

static shr_error_e
dbal_db_init_field_type_duplication_verify(
    int unit,
    dbal_field_types_basic_info_t * field_types_info,
    int is_valid)
{
    SHR_FUNC_INIT_VARS(unit);

    if (is_valid && SHR_BITGET(field_types_info->field_indication_bm, DBAL_FIELD_IND_IS_VALID))
    {
        SHR_ERR_EXIT(_SHR_E_INTERNAL, "Field type %s was already defined\n", field_types_info->name);
    }

    SHR_EXIT();
exit:
    SHR_FUNC_EXIT;
}

shr_error_e
dbal_db_init_field_type_general_info_set(
    int unit,
    dbal_field_types_basic_info_t * cur_field_types_info,
    char *name,
    int size,
    int is_valid,
    uint8 has_resource_name,
    dbal_field_print_type_e print_type,
    uint8 is_default,
    uint8 is_standard_1)
{
    SHR_FUNC_INIT_VARS(unit);

    SHR_IF_ERR_EXIT(dbal_db_init_field_type_duplication_verify(unit, cur_field_types_info, is_valid));

    sal_strncpy_s(cur_field_types_info->name, name, sizeof(cur_field_types_info->name));

    cur_field_types_info->max_size = size;

    cur_field_types_info->print_type = print_type;

    if (is_default)
    {
        SHR_BITSET(cur_field_types_info->field_indication_bm, DBAL_FIELD_IND_IS_DEFAULT);
    }
    if (is_standard_1)
    {
        SHR_BITSET(cur_field_types_info->field_indication_bm, DBAL_FIELD_IND_IS_STANDARD_1);
    }
    if (has_resource_name)
    {
        SHR_BITSET(cur_field_types_info->field_indication_bm, DBAL_FIELD_IND_IS_ALLOCATOR);
    }

    SHR_EXIT();
exit:
    SHR_FUNC_EXIT;
}

static void
dbal_db_init_offset_init(
    table_db_offset_in_hw_struct_t * offset)
{
    offset->formula_int = DBAL_DB_INVALID;
    offset->formula_cb = NULL;
}

shr_error_e
dbal_db_init_table_set_access_register_memory(
    int unit,
    table_db_access_params_struct_t * access_params,
    int reg_mem_hw_entity_id,
    int hw_field)
{
    SHR_FUNC_INIT_VARS(unit);

    DNX_INIT_TIME_ANALYZER_DBAL_INIT_START(unit, DNX_INIT_TIME_ANALYSER_DBAL_L_INIT_ACCESS_REGISTER_MEMORY);

    access_params->reg_mem_hw_entity_id = reg_mem_hw_entity_id;

    dbal_db_init_offset_init(&(access_params->group_offset));
    dbal_db_init_offset_init(&(access_params->array_offset));
    dbal_db_init_offset_init(&(access_params->entry_offset));
    dbal_db_init_offset_init(&(access_params->block_index));
    dbal_db_init_offset_init(&(access_params->data_offset));
    dbal_db_init_offset_init(&(access_params->alias_data_offset));

    access_params->hw_field = hw_field;

    access_params->alias_reg_mem_hw_entity_id = DBAL_HL_ACCESS_HW_ENTITY_INVALID;

    DNX_INIT_TIME_ANALYZER_DBAL_INIT_STOP(unit, DNX_INIT_TIME_ANALYSER_DBAL_L_INIT_ACCESS_REGISTER_MEMORY);

    SHR_EXIT();
exit:
    SHR_FUNC_EXIT;
}

shr_error_e
dbal_db_init_table_set_access_condition(
    int unit,
    table_db_access_condition_struct_t * access_condition,
    dbal_condition_types_e type,
    dbal_fields_e field,
    int value,
    uint32 enum_value)
{
    SHR_FUNC_INIT_VARS(unit);
    access_condition->condition_type = type;
    access_condition->field_id = field;
    access_condition->value = value;
    access_condition->enum_val = enum_value;
    SHR_EXIT();

exit:
    SHR_FUNC_EXIT;
}

shr_error_e
dbal_db_init_hard_logic_direct_set_access_type(
    int unit,
    table_db_access_params_struct_t * access_params,
    dbal_hard_logic_access_types_e access_type)
{
    SHR_FUNC_INIT_VARS(unit);

    access_params->access_type = access_type;

    SHR_FUNC_EXIT;
}

void
dbal_db_init_table_set_mandatory_access_field_values(
    int unit,
    dbal_fields_e access_field_id,
    dbal_hard_logic_access_types_e access_type,
    table_db_access_params_struct_t * access_params)
{
    access_params->access_field_id = access_field_id;
    access_params->access_type = access_type;
}

void
dbal_db_init_table_set_pemla_mapping_by_index(
    table_db_struct_t * table_param,
    dbal_logical_table_t * table_entry)
{
    int ii;

    for (ii = 0; ii < table_entry->nof_key_fields; ii++)
    {
        table_param->pemla_access->pemla_key_mapping[ii] = ii;
    }
    for (ii = 0; ii < table_entry->multi_res_info[0].nof_result_fields; ii++)
    {
        table_param->pemla_access->pemla_result_mapping[ii] = ii;
    }
}

shr_error_e
dbal_db_init_table_tcam_cs_mapping_add(
    int unit,
    table_db_struct_t * cur_table_param,
    soc_mem_t mem)
{
    SHR_FUNC_INIT_VARS(unit);

    cur_table_param->cs_access->reg_mem_hw_entity_id = mem;

    SHR_EXIT();
exit:
    SHR_FUNC_EXIT;
}

void
dbal_db_init_table_db_struct_hl_access_params_clear(
    table_db_access_params_struct_t * access)
{
    sal_memset(access, 0x0, sizeof(table_db_access_params_struct_t));
}

void
dbal_db_init_table_db_struct_hl_access_clear(
    table_db_struct_t * table_db,
    dbal_logical_table_t * table_entry)
{
    int map_idx = 0;
    for (map_idx = 0; map_idx < table_entry->nof_result_types; map_idx++)
    {
        table_db->hl_access[map_idx].nof_access = 0;
        sal_memset(table_db->hl_access[map_idx].mapping_result_name, 0x0,
                   sizeof(table_db->hl_access[map_idx].mapping_result_name));
    }
}

void
dbal_db_init_table_db_struct_access_clear(
    table_db_struct_t * cur_table_param,
    dbal_logical_table_t * table_entry)
{
    DNX_INIT_TIME_ANALYZER_DBAL_INIT_START(0, DNX_INIT_TIME_ANALYSER_DBAL_L_INIT_STRUCT_ACCESS_CLEAR);
    switch (table_entry->access_method)
    {
        case DBAL_ACCESS_METHOD_MDB:
            sal_memset(cur_table_param->mdb_access, 0x0, sizeof(table_db_mdb_access_struct_t));
            break;
        case DBAL_ACCESS_METHOD_TCAM_CS:
            sal_memset(cur_table_param->cs_access, 0x0, sizeof(table_db_cs_access_struct_t));
            break;
        case DBAL_ACCESS_METHOD_HARD_LOGIC:
            dbal_db_init_table_db_struct_hl_access_clear(cur_table_param, table_entry);

            break;
        case DBAL_ACCESS_METHOD_SW_STATE:

            break;
        case DBAL_ACCESS_METHOD_PEMLA:
            sal_memset(cur_table_param->pemla_access, 0x0, sizeof(table_db_pemla_access_struct_t));
            break;
        case DBAL_ACCESS_METHOD_KBP:

            break;
        default:
            break;
    }

    DNX_INIT_TIME_ANALYZER_DBAL_INIT_STOP(0, DNX_INIT_TIME_ANALYSER_DBAL_L_INIT_STRUCT_ACCESS_CLEAR);
}

void
dbal_init_field_type_default_restrict_values(
    field_type_db_struct_t * cur_field_type_param)
{

    cur_field_type_param->nof_illegal_value = 0;
    cur_field_type_param->min_value = DBAL_DB_INVALID;
    cur_field_type_param->max_value = DBAL_DB_INVALID;
    cur_field_type_param->const_value = DBAL_DB_INVALID;
}

void
dbal_init_field_type_db_struct_clear(
    int unit,
    field_type_db_struct_t * cur_field_type_param)
{

    dbal_db_child_field_info_struct_t *childs = cur_field_type_param->childs;
    dbal_db_enum_info_struct_t *enums = cur_field_type_param->enums;
    dbal_db_defines_info_struct_t *define = cur_field_type_param->define;
    int *illegal_values = cur_field_type_param->illegal_values;

    sal_memset(cur_field_type_param, 0x0, sizeof(field_type_db_struct_t));

    cur_field_type_param->childs = childs;
    cur_field_type_param->enums = enums;
    cur_field_type_param->define = define;
    cur_field_type_param->illegal_values = illegal_values;
}

shr_error_e
dbal_db_init_dynamic_result_type_clear(
    int unit,
    multi_res_info_t * multi_res_info)
{
    dbal_table_field_info_t *results_info;

    SHR_FUNC_INIT_VARS(unit);

    results_info = multi_res_info->results_info;

    sal_memset(results_info, 0,
               dnx_data_dbal.table.nof_dynamic_tables_result_fields_get(unit) * sizeof(dbal_table_field_info_t));

    sal_memset(multi_res_info, 0, sizeof(multi_res_info_t));

    multi_res_info->results_info = results_info;

    SHR_EXIT();
exit:
    SHR_FUNC_EXIT;
}

static shr_error_e
dbal_db_init_table_duplication_verify(
    int unit,
    dbal_logical_table_t * table_entry,
    uint8 new_table_is_valid_and_mature,
    char *table_name)
{
    uint8 previous_table_is_valid_and_mature = (table_entry->maturity_level != DBAL_MATURITY_LOW);
    SHR_FUNC_INIT_VARS(unit);

    if (new_table_is_valid_and_mature && previous_table_is_valid_and_mature)
    {
        SHR_ERR_EXIT(_SHR_E_INTERNAL,
                     "table already initialized %s there are more than one definition of the table \n", table_name);
    }
    SHR_EXIT();
exit:
    SHR_FUNC_EXIT;
}

static shr_error_e
dbal_db_init_table_invalid_image_verify(
    int unit,
    uint8 is_valid_and_mature,
    char *table_custom_image,
    char *table_name)
{

    uint8 table_is_standard_image_or_compatible_with_all_images = (table_custom_image == NULL);
    uint8 table_custom_image_is_current_image = FALSE;

    SHR_FUNC_INIT_VARS(unit);

    if (!is_valid_and_mature)
    {
        SHR_EXIT();
    }

    if (table_is_standard_image_or_compatible_with_all_images)
    {
        SHR_EXIT();
    }

    SHR_IF_ERR_EXIT(dnx_pp_prgm_current_image_check(unit, table_custom_image, &table_custom_image_is_current_image));

    if (!table_custom_image_is_current_image)
    {
        char *current_image = NULL;
        SHR_IF_ERR_EXIT(dnx_pp_prgm_device_image_name_get(unit, &current_image));
        SHR_ERR_EXIT(_SHR_E_INTERNAL,
                     "table %s has invalid image: %s. Expected image: %s \n",
                     table_name, table_custom_image, current_image);
    }
exit:
    SHR_FUNC_EXIT;
}

static void
dbal_db_init_table_init_skip(
    int unit,
    dbal_logical_table_t * table_entry,
    uint8 new_table_is_valid_and_mature,
    uint8 *is_skip_table_init)
{
    uint8 previous_table_is_valid = (table_entry->maturity_level != DBAL_MATURITY_LOW);
    *is_skip_table_init = (previous_table_is_valid && !new_table_is_valid_and_mature);
}

static void
dbal_db_init_table_general_info_set(
    dbal_logical_table_t * table_entry,
    char *table_name,
    dbal_access_method_e access_method,
    dbal_maturity_level_e maturity_level,
    int is_valid)
{
    table_entry->access_method = access_method;
    sal_strncpy_s(table_entry->table_name, table_name, sizeof(table_entry->table_name));
    if (is_valid)
    {
        table_entry->maturity_level = maturity_level;
    }
}

shr_error_e
dbal_db_init_table_general_info_and_image_handle(
    int unit,
    dbal_logical_table_t * table_entry,
    dbal_tables_e table_id,
    int is_valid,
    dbal_maturity_level_e maturity_level,
    char *table_name,
    dbal_access_method_e access_method,
    char *custom_image,
    uint8 is_compatible_with_all_images,
    uint8 *is_skip_table_init)
{
    uint8 is_standard = (!is_compatible_with_all_images && (custom_image == NULL));
    uint8 is_valid_and_mature = UTILEX_NUM2BOOL(is_valid) && (maturity_level != DBAL_MATURITY_LOW);
    SHR_FUNC_INIT_VARS(unit);

    DNX_INIT_TIME_ANALYZER_DBAL_INIT_START(unit, DNX_INIT_TIME_ANALYSER_DBAL_L_INIT_GENERAL_INFO);

    dbal_db_init_table_init_skip(unit, table_entry, is_valid_and_mature, is_skip_table_init);
    if (*is_skip_table_init)
    {
        SHR_EXIT();
    }
    SHR_IF_ERR_EXIT(dbal_db_init_table_invalid_image_verify(unit, is_valid_and_mature, custom_image, table_name));

    SHR_IF_ERR_EXIT(dbal_db_init_table_duplication_verify(unit, table_entry, is_valid_and_mature, table_name));

    dbal_db_init_table_general_info_set(table_entry, table_name, access_method, maturity_level, is_valid);

    if ((access_method == DBAL_ACCESS_METHOD_KBP) && (!dnx_kbp_device_enabled(unit)))
    {
        table_entry->maturity_level = DBAL_MATURITY_LOW;

        if (!sw_state_is_warm_boot(unit))
        {
            SHR_IF_ERR_EXIT(DBAL_SW_STATE_TBL_PROP.table_status.set(unit, table_id, DBAL_NOF_TABLE_STATUS));
        }
    }

    DBAL_DB_INIT_TABLE_IMAGE_SPECIFIC_TABLE_INDICATION_SET(table_entry, is_standard, custom_image);
    SHR_IF_ERR_EXIT(dbal_db_init_table_incompatible_image_indication_set
                    (unit, table_id, is_standard, is_compatible_with_all_images));

    if (!is_valid || (table_entry->maturity_level == DBAL_MATURITY_LOW))
    {
        *is_skip_table_init = TRUE;
        SHR_EXIT();
    }
    DNX_INIT_TIME_ANALYZER_DBAL_INIT_STOP(unit, DNX_INIT_TIME_ANALYSER_DBAL_L_INIT_GENERAL_INFO);

exit:
    SHR_FUNC_EXIT;
}

void
dbal_db_init_table_field_params_init(
    table_db_field_params_struct_t * field_db)
{
    field_db->valid = TRUE;
    field_db->size = 0;
    field_db->offset = 0;
    field_db->max_value = DBAL_DB_INVALID;
    field_db->min_value = 0;
    field_db->nof_instances = 1;
    field_db->max_nof_instances = DBAL_TABLE_DEFAULT_MAX_NOF_INSTANCES;
    field_db->is_validate_nof_instances = 0;
    field_db->const_value = DBAL_DB_INVALID;
    field_db->permission = DBAL_PERMISSION_ALL;
    field_db->arr_prefix_value = 0;
    field_db->arr_prefix_width = 0;
}

shr_error_e
dbal_db_init_table_field_set_mandatory_values(
    int unit,
    dbal_fields_e field_id,
    dbal_field_types_defs_e field_type,
    dbal_table_field_info_t * field_info)
{
    SHR_FUNC_INIT_VARS(unit);
    SHR_NULL_CHECK(field_info, _SHR_E_INTERNAL,
                   "Number or result fields is 0. Might be caused by nof_instances set to 0"
                   " from dnx data.\n" "Use Valid attribute for disabling result fields");
    field_info->field_id = field_id;
    DBAL_DB_INIT_TABLE_DB_FIELD_SET_FIELD_TYPE(unit, field_info, field_type);
exit:
    SHR_FUNC_EXIT;
}

void
dbal_db_init_table_set_field_arr_prefix(
    int unit,
    table_db_field_params_struct_t * field_db,
    uint32 arr_prefix_value,
    uint32 arr_prefix_width)
{
    field_db->arr_prefix_value = arr_prefix_value;
    field_db->arr_prefix_width = arr_prefix_width;
}

void
dbal_init_table_db_struct_clear(
    table_db_struct_t * cur_table_param)
{
    table_db_mdb_access_struct_t *mdb_access;
    table_db_hl_access_struct_t *hl_access;
    table_db_cs_access_struct_t *cs_access;
    table_db_pemla_access_struct_t *pemla_access;

    DNX_INIT_TIME_ANALYZER_DBAL_INIT_START(0, DNX_INIT_TIME_ANALYSER_DBAL_L_INIT_STRUCT_CLEAR);

    mdb_access = cur_table_param->mdb_access;
    hl_access = cur_table_param->hl_access;
    cs_access = cur_table_param->cs_access;
    pemla_access = cur_table_param->pemla_access;

    sal_memset(cur_table_param, 0x0, sizeof(table_db_struct_t));

    cur_table_param->mdb_access = mdb_access;
    cur_table_param->hl_access = hl_access;
    cur_table_param->cs_access = cs_access;
    cur_table_param->pemla_access = pemla_access;

    DNX_INIT_TIME_ANALYZER_DBAL_INIT_STOP(0, DNX_INIT_TIME_ANALYSER_DBAL_L_INIT_STRUCT_CLEAR);
}

shr_error_e
dnx_dbal_post_init_operations(
    int unit)
{
    SHR_FUNC_INIT_VARS(unit);

    SHR_IF_ERR_EXIT(dbal_handles_init(unit));

exit:
    SHR_FUNC_EXIT;
}

shr_error_e
dnx_dbal_pre_deinit_operations(
    int unit)
{
    SHR_FUNC_INIT_VARS(unit);

    SHR_IF_ERR_EXIT(dbal_handles_deinit(unit));

exit:
    SHR_FUNC_EXIT;
}

static shr_error_e
dbal_db_init_tables_hard_logic_init(
    int unit,
    table_db_struct_t * cur_table_param,
    dbal_logical_table_t * table_info)
{
    SHR_FUNC_INIT_VARS(unit);
    DNX_INIT_TIME_ANALYZER_DBAL_INIT_START(unit, DNX_INIT_TIME_ANALYSER_DBAL_L_HL_INIT);
    if (DBAL_IS_DNX2(unit))
    {
        SHR_IF_ERR_EXIT(dbal_init_tables_hard_logic_init(unit, cur_table_param, table_info));
    }
    DNX_INIT_TIME_ANALYZER_DBAL_INIT_STOP(unit, DNX_INIT_TIME_ANALYSER_DBAL_L_HL_INIT);
exit:
    SHR_FUNC_EXIT;
}

static shr_error_e
dbal_db_init_tables_sw_state_init(
    int unit,
    table_db_struct_t * cur_table_param,
    dbal_logical_table_t * table_info)
{
    SHR_FUNC_INIT_VARS(unit);
    DNX_INIT_TIME_ANALYZER_DBAL_INIT_START(unit, DNX_INIT_TIME_ANALYSER_DBAL_L_SW_STATE_INIT);
    if (DBAL_IS_DNX2(unit))
    {
        SHR_IF_ERR_EXIT(dbal_init_tables_sw_state_init(unit, cur_table_param, table_info));
    }
    DNX_INIT_TIME_ANALYZER_DBAL_INIT_STOP(unit, DNX_INIT_TIME_ANALYSER_DBAL_L_SW_STATE_INIT);
exit:
    SHR_FUNC_EXIT;
}

static shr_error_e
dbal_db_init_tables_tcam_context_selection_init(
    int unit,
    table_db_struct_t * cur_table_param,
    dbal_logical_table_t * table_info)
{
    SHR_FUNC_INIT_VARS(unit);
    DNX_INIT_TIME_ANALYZER_DBAL_INIT_START(unit, DNX_INIT_TIME_ANALYSER_DBAL_L_TCAMCON_INIT);

    if (DBAL_IS_DNX2(unit))
    {
        SHR_IF_ERR_EXIT(dbal_init_tables_tcam_context_selection_init(unit, cur_table_param, table_info));
    }
    SHR_EXIT();
    DNX_INIT_TIME_ANALYZER_DBAL_INIT_STOP(unit, DNX_INIT_TIME_ANALYSER_DBAL_L_TCAMCON_INIT);
exit:
    SHR_FUNC_EXIT;
}

static shr_error_e
dbal_db_init_tables_pemla_init(
    int unit,
    table_db_struct_t * cur_table_param,
    dbal_logical_table_t * table_info)
{
    SHR_FUNC_INIT_VARS(unit);
    DNX_INIT_TIME_ANALYZER_DBAL_INIT_START(unit, DNX_INIT_TIME_ANALYSER_DBAL_PEMLA_INIT);

    if (DBAL_IS_DNX2(unit))
    {
        SHR_IF_ERR_EXIT(dbal_init_tables_pemla_init(unit, cur_table_param, table_info));
    }
    SHR_EXIT();
    DNX_INIT_TIME_ANALYZER_DBAL_INIT_STOP(unit, DNX_INIT_TIME_ANALYSER_DBAL_PEMLA_INIT);
exit:
    SHR_FUNC_EXIT;
}

static shr_error_e
dbal_db_init_tables_mdb_init(
    int unit,
    table_db_struct_t * cur_table_param,
    dbal_logical_table_t * table_info)
{
    SHR_FUNC_INIT_VARS(unit);

    DNX_INIT_TIME_ANALYZER_DBAL_INIT_START(unit, DNX_INIT_TIME_ANALYSER_DBAL_MDB_INIT);

    if (DBAL_IS_DNX2(unit))
    {
        SHR_IF_ERR_EXIT(dbal_init_tables_mdb_init(unit, cur_table_param, table_info));
    }
    DNX_INIT_TIME_ANALYZER_DBAL_INIT_STOP(unit, DNX_INIT_TIME_ANALYSER_DBAL_MDB_INIT);

exit:
    SHR_FUNC_EXIT;
}

shr_error_e
dbal_db_init_logical_tables(
    int unit,
    dbal_logical_table_t * table_info)
{
    table_db_struct_t *cur_table_param = NULL;

    SHR_FUNC_INIT_VARS(unit);
    SHR_ALLOC_ERR_EXIT(cur_table_param, sizeof(table_db_struct_t),
                       "logical_tables,cur_table_param", "%s%s%s\r\n", EMPTY, EMPTY, EMPTY);
    cur_table_param->mdb_access = NULL;
    SHR_ALLOC_ERR_EXIT(cur_table_param->mdb_access, sizeof(table_db_mdb_access_struct_t),
                       "logical_table,pemla_access", "%s%s%s\r\n", EMPTY, EMPTY, EMPTY);
    cur_table_param->hl_access = NULL;
    SHR_ALLOC_ERR_EXIT(cur_table_param->hl_access,
                       DBAL_MAX_NUMBER_OF_RESULT_TYPES * sizeof(table_db_hl_access_struct_t), "logical_table,hl_access",
                       "%s%s%s\r\n", EMPTY, EMPTY, EMPTY);
    cur_table_param->cs_access = NULL;
    SHR_ALLOC_ERR_EXIT(cur_table_param->cs_access, sizeof(table_db_cs_access_struct_t),
                       "logical_table,cs_access", "%s%s%s\r\n", EMPTY, EMPTY, EMPTY);
    cur_table_param->pemla_access = NULL;
    SHR_ALLOC_ERR_EXIT(cur_table_param->pemla_access, sizeof(table_db_pemla_access_struct_t),
                       "logical_table,pemla_access", "%s%s%s\r\n", EMPTY, EMPTY, EMPTY);

    SHR_IF_ERR_EXIT(dbal_db_init_tables_hard_logic_init(unit, cur_table_param, table_info));
    SHR_IF_ERR_EXIT(dbal_db_init_tables_sw_state_init(unit, cur_table_param, table_info));
    SHR_IF_ERR_EXIT(dbal_db_init_tables_tcam_context_selection_init(unit, cur_table_param, table_info));
    SHR_IF_ERR_EXIT(dbal_db_init_tables_pemla_init(unit, cur_table_param, table_info));
    SHR_IF_ERR_EXIT(dbal_db_init_tables_mdb_init(unit, cur_table_param, table_info));
exit:
    SHR_FREE(cur_table_param->mdb_access);
    SHR_FREE(cur_table_param->hl_access);
    SHR_FREE(cur_table_param->cs_access);
    SHR_FREE(cur_table_param->pemla_access);
    SHR_FREE(cur_table_param);
    SHR_FUNC_EXIT;
}

shr_error_e
dbal_logical_table_t_init(
    int unit,
    dbal_logical_table_t * table_info)
{
    CONST static dbal_logical_table_t table_default = {
        "",
        DBAL_MATURITY_LOW,
        0,
        NULL,
        DBAL_TABLE_TYPE_NONE,
        0,
        {0},
        0,
        NULL,
        0,
        0,
        DBAL_FIELD_EMPTY,
        NULL,
        0,
        NULL,
        0,
        0,
        DBAL_CORE_NONE,
        DBAL_NOF_ACCESS_METHODS,
        0,
        {0},
        0,
        {DBAL_PHYSICAL_TABLE_NONE},
        0,
        0,
        DBAL_NOF_STAGES,
        NULL,
        NULL,
        {NULL},
        NULL
    };

    SHR_FUNC_INIT_VARS(unit);

    (*table_info) = table_default;

    SHR_FUNC_EXIT;
}

shr_error_e
dbal_logical_dynamic_table_t_init(
    int unit,
    dbal_logical_table_t * table_info)
{
    SHR_FUNC_INIT_VARS(unit);

    table_info->maturity_level = 0;
    table_info->nof_labels = DBAL_TABLE_TYPE_NONE;
    table_info->max_capacity = 0;
    table_info->indications_bm[0] = 0;
    table_info->nof_key_fields = 0;
    table_info->key_size = 0;
    table_info->core_id_nof_bits = 0;
    table_info->allocator_field_id = DBAL_FIELD_EMPTY;
    table_info->nof_result_types = 0;
    table_info->max_payload_size = 0;
    table_info->max_nof_result_fields = 0;
    table_info->core_mode = DBAL_CORE_NONE;
    table_info->access_method = DBAL_NOF_ACCESS_METHODS;
    table_info->sw_access_info.sw_payload_length_bytes = 0;
    table_info->nof_physical_tables = 0;
    table_info->physical_db_id[0] = DBAL_PHYSICAL_TABLE_NONE;
    table_info->physical_db_id[1] = DBAL_PHYSICAL_TABLE_NONE;
    table_info->app_id = 0;
    table_info->app_id_size = 0;
    table_info->dbal_stage = DBAL_NOF_STAGES;
    table_info->table_type = DBAL_TABLE_TYPE_NONE;
    sal_memset(table_info->table_name, 0x0, sizeof(table_info->table_name));

    SHR_FUNC_EXIT;
}

shr_error_e
dbal_db_init_table_alloc(
    int unit,
    dbal_logical_table_t * table_info)
{
    int table_index;

    SHR_FUNC_INIT_VARS(unit);

    for (table_index = 0; table_index < DBAL_NOF_TABLES; table_index++)
    {
        SHR_IF_ERR_EXIT(dbal_logical_table_t_init(unit, &(table_info[table_index])));
    }

exit:
    SHR_FUNC_EXIT;
}

static void
dbal_superset_result_type_field_add(
    int unit,
    multi_res_info_t * superset_res_type,
    int field_idx,
    dbal_table_field_info_t * field_info)
{
    superset_res_type->results_info[field_idx].field_id = field_info->field_id;
    superset_res_type->results_info[field_idx].field_type = field_info->field_type;
    superset_res_type->results_info[field_idx].nof_instances = field_info->nof_instances;
    superset_res_type->results_info[field_idx].field_nof_bits =
        field_info->field_nof_bits + field_info->arr_prefix_size;
    superset_res_type->results_info[field_idx].max_value = field_info->max_value;
    superset_res_type->results_info[field_idx].min_value = field_info->min_value;
    superset_res_type->results_info[field_idx].offset_in_logical_field = field_info->offset_in_logical_field;
    sal_memcpy(superset_res_type->results_info[field_idx].field_indication_bm, field_info->field_indication_bm,
               sizeof(field_info->field_indication_bm));
    superset_res_type->nof_result_fields++;
}

static shr_error_e
dbal_superset_result_type_field_modify(
    int unit,
    multi_res_info_t * superset_res_type,
    int field_idx,
    dbal_table_field_info_t * field_info)
{
    uint32 tmp_field_value = 0, field_max_value = 0;
    SHR_FUNC_INIT_VARS(unit);

    if ((field_info->arr_prefix_size) && (!(SHR_BITGET(field_info->field_indication_bm, DBAL_FIELD_IND_IS_FIELD_ENUM))))
    {
        tmp_field_value = ((1 << field_info->field_nof_bits) - 1);
        SHR_IF_ERR_EXIT(dbal_fields_encode_prefix(unit, &tmp_field_value, field_info->arr_prefix,
                                                  field_info->field_nof_bits,
                                                  field_info->field_nof_bits + field_info->arr_prefix_size,
                                                  &field_max_value));
    }
    else
    {
        field_max_value = field_info->max_value;
    }

    if (superset_res_type->results_info[field_idx].field_nof_bits <
        (field_info->field_nof_bits + field_info->arr_prefix_size))
    {
        superset_res_type->results_info[field_idx].field_nof_bits =
            field_info->field_nof_bits + field_info->arr_prefix_size;
    }

    if (superset_res_type->results_info[field_idx].max_value < field_max_value)
    {
        superset_res_type->results_info[field_idx].max_value = field_max_value;
    }

    if (superset_res_type->results_info[field_idx].min_value > field_info->min_value)
    {
        superset_res_type->results_info[field_idx].min_value = field_info->min_value;
    }

    if (superset_res_type->results_info[field_idx].offset_in_logical_field > field_info->offset_in_logical_field)
    {
        superset_res_type->results_info[field_idx].offset_in_logical_field = field_info->offset_in_logical_field;
    }

exit:
    SHR_FUNC_EXIT;
}

static shr_error_e
dbal_superset_result_type_child_fields_merge(
    int unit,
    multi_res_info_t * superset_res_type,
    int field_idx,
    int nof_merge_sub_fields,
    int *merge_sub_field_idx)
{
    int child_idx, child_idx_in_superset;
    dbal_table_field_info_t *sub_field_info;
    SHR_FUNC_INIT_VARS(unit);

    for (child_idx = 0; child_idx < nof_merge_sub_fields; child_idx++)
    {

        child_idx_in_superset = merge_sub_field_idx[child_idx] - child_idx;
        sub_field_info = &(superset_res_type->results_info[child_idx_in_superset]);
        SHR_IF_ERR_EXIT(dbal_superset_result_type_field_modify(unit, superset_res_type, field_idx, sub_field_info));

        sal_memmove(sub_field_info, sub_field_info + 1,
                    (sizeof(*sub_field_info) * (superset_res_type->nof_result_fields - child_idx_in_superset)));
        sal_memset(&(superset_res_type->results_info[superset_res_type->nof_result_fields--]), 0,
                   sizeof(*sub_field_info));
    }

exit:
    SHR_FUNC_EXIT;
}

shr_error_e
dbal_superset_result_type_field_update(
    int unit,
    multi_res_info_t * superset_res_type,
    dbal_table_field_info_t * field_info)
{
    int field_idx, merge_sub_field_idx[DBAL_FIELD_MAX_NUM_OF_CHILD_FIELDS], nof_merge_sub_fields = 0;
    int superset_buffer_offset = 0;
    dbal_sub_field_info_t *sub_field_info;
    dbal_fields_e exising_field_id;
    shr_error_e rv;
    SHR_FUNC_INIT_VARS(unit);

    sal_memset(merge_sub_field_idx, 0, sizeof(merge_sub_field_idx));
    for (field_idx = 0; field_idx < (superset_res_type->nof_result_fields); field_idx++)
    {

        exising_field_id = superset_res_type->results_info[field_idx].field_id;
        rv = dbal_fields_sub_field_info_get_internal(unit, field_info->field_id, exising_field_id, &sub_field_info);
        if (SHR_SUCCESS(rv) || (exising_field_id == field_info->field_id))
        {
            break;
        }

        if (SHR_BITGET(field_info->field_indication_bm, DBAL_FIELD_IND_IS_PARENT_FIELD))
        {
            rv = dbal_fields_sub_field_info_get_internal(unit, exising_field_id, field_info->field_id, &sub_field_info);
            if (SHR_SUCCESS(rv))
            {
                merge_sub_field_idx[nof_merge_sub_fields++] = field_idx + 1;
            }
        }
    }

    if (field_idx == (superset_res_type->nof_result_fields))
    {

        if (SHR_BITGET(field_info->field_indication_bm, DBAL_FIELD_IND_IS_PARENT_FIELD))
        {
            field_idx = 1;
            sal_memmove(&(superset_res_type->results_info[field_idx + 1]), &superset_res_type->results_info[field_idx],
                        (sizeof(dbal_table_field_info_t) * (superset_res_type->nof_result_fields - field_idx)));
            sal_memset(&(superset_res_type->results_info[field_idx]), 0, sizeof(dbal_table_field_info_t));
        }

        dbal_superset_result_type_field_add(unit, superset_res_type, field_idx, field_info);

        if (SHR_BITGET(field_info->field_indication_bm, DBAL_FIELD_IND_IS_PARENT_FIELD))
        {
            dbal_superset_result_type_child_fields_merge(unit, superset_res_type, field_idx, nof_merge_sub_fields,
                                                         merge_sub_field_idx);
        }
    }

    else
    {

        SHR_IF_ERR_EXIT(dbal_superset_result_type_field_modify(unit, superset_res_type, field_idx, field_info));
    }

    if (field_idx)
    {
        superset_buffer_offset = superset_res_type->results_info[field_idx - 1].bits_offset_in_buffer +
            superset_res_type->results_info[field_idx - 1].field_nof_bits;
    }

    for (; field_idx < (superset_res_type->nof_result_fields); field_idx++)
    {
        superset_res_type->results_info[field_idx].bits_offset_in_buffer = superset_buffer_offset;
        if (superset_res_type->results_info[field_idx].field_id == DBAL_FIELD_EMPTY)
        {
            break;
        }
        superset_buffer_offset += superset_res_type->results_info[field_idx].field_nof_bits;
    }

exit:
    SHR_FUNC_EXIT;
}

static uint8
dbal_db_init_table_iterator_bitmap_allocation_supported(
    int unit,
    dbal_tables_e table_id,
    dbal_logical_table_t * table)
{

    if ((dbal_table_is_out_lif(table)) || (dbal_table_is_in_lif(unit, table)) || (table_id == DBAL_TABLE_GLOBAL_RIF_EM))
    {
        return TRUE;
    }

    switch (table_id)
    {

        case DBAL_TABLE_EXAMPLE_TABLE_CONST_VALUES:
        case DBAL_TABLE_EXAMPLE_TABLE_ILLEGAL_VALUES:
            return TRUE;
            break;

        case DBAL_TABLE_INGRESS_PP_PORT:
        case DBAL_TABLE_EGRESS_PP_PORT:
            return TRUE;
            break;

        case DBAL_TABLE_FIELD_PMF_A_SELECT_KEY_N_FES:
        case DBAL_TABLE_FIELD_PMF_B_SELECT_KEY_N_FES:
        case DBAL_TABLE_QOS_EGRESS_NETWORK_QOS_MAPPING_PACKET:
        case DBAL_TABLE_GLOBAL_TPID:
            return TRUE;
            break;

        default:
            break;
    }

    return FALSE;
}

static shr_error_e
dbal_db_init_alloc_bit_num_get(
    int unit,
    dbal_tables_e table_id,
    dbal_logical_table_t * table,
    uint32 *alloc_bit_num)
{
    SHR_FUNC_INIT_VARS(unit);

    if (table->table_type == DBAL_TABLE_TYPE_EM)
    {
        if (table_id == DBAL_TABLE_GLOBAL_RIF_EM)
        {
            *alloc_bit_num = dnx_data_l3.rif.nof_rifs_get(unit);
        }
        else
        {
            SHR_ERR_EXIT(_SHR_E_INTERNAL, "iterator optimized is not supported for EM tables %s\n", table->table_name);
        }
    }
    else
    {
        if ((table->nof_key_fields == 1) && (table->max_capacity))
        {
            *alloc_bit_num = table->max_capacity;
        }
        else if (table->key_size > 0)
        {
            uint32 max_entry_key_value;
            SHR_IF_ERR_EXIT(dbal_tables_max_key_value_get(unit, table_id, &max_entry_key_value));
            *alloc_bit_num = max_entry_key_value;
        }
    }

exit:
    SHR_FUNC_EXIT;
}

static shr_error_e
dbal_db_init_table_iterator_bitmap_allocation(
    int unit,
    dbal_tables_e table_id,
    dbal_logical_table_t * table)
{
    uint32 alloc_bit_num = 0;
    uint8 max_core = 1;

    SHR_FUNC_INIT_VARS(unit);

    SHR_IF_ERR_EXIT(dbal_db_init_alloc_bit_num_get(unit, table_id, table, &alloc_bit_num));

    if (alloc_bit_num > 0)
    {
        int core_index;

        SHR_BITSET(table->indications_bm, DBAL_TABLE_IND_IS_ITERATOR_OPTIMIZED);

        SHR_ALLOC_SET_ZERO(table->iterator_optimized, (DBAL_MAX_NUM_OF_CORES * sizeof(uint32 *)),
                           "iterator optimized info allocation", "%s%s%s\r\n", table->table_name, EMPTY, EMPTY);

        if (!sw_state_is_warm_boot(unit))
        {
            DBAL_SW_STATE_TBL_PROP.iterator_optimized.alloc(unit, table_id);
        }

        if (table->core_mode == DBAL_CORE_MODE_DPC)
        {
            max_core = DBAL_MAX_NUM_OF_CORES;
        }

        for (core_index = 0; core_index < max_core; core_index++)
        {
            SHR_ALLOC_SET_ZERO(table->iterator_optimized[core_index], WORDS2BYTES(BITS2WORDS(alloc_bit_num) + 1),
                               "iterator optimized info allocation", "%s%s%s\r\n", table->table_name, EMPTY, EMPTY);
            if (!sw_state_is_warm_boot(unit))
            {
                DBAL_SW_STATE_TBL_PROP.iterator_optimized.bitmap.alloc_bitmap(unit, table_id, core_index,
                                                                              alloc_bit_num);
            }
            else
            {

                DBAL_SW_STATE_TBL_PROP.iterator_optimized.bitmap.bit_range_read(unit, table_id, core_index, 0, 0,
                                                                                alloc_bit_num,
                                                                                (SHR_BITDCL *)
                                                                                table->iterator_optimized[core_index]);
            }
        }
    }
    else
    {
        SHR_ERR_EXIT(_SHR_E_INTERNAL, "no bitmap size to allocate for optimized %s\n", table->table_name);
    }
exit:
    SHR_FUNC_EXIT;
}

static shr_error_e
dbal_db_init_table_interface_field_indications_update(
    int unit,
    dbal_logical_table_t * table,
    dbal_table_field_info_t * field_info)
{
    dbal_field_types_basic_info_t *field_type_info;
    dbal_field_print_type_e field_print_type;
    SHR_FUNC_INIT_VARS(unit);

    if (dbal_fields_is_parent_field(unit, field_info->field_id))
    {
        SHR_BITSET(field_info->field_indication_bm, DBAL_FIELD_IND_IS_PARENT_FIELD);
    }
    if (dbal_fields_is_field_encoded(unit, field_info->field_id))
    {
        SHR_BITSET(field_info->field_indication_bm, DBAL_FIELD_IND_IS_FIELD_ENCODED);
    }

    SHR_IF_ERR_EXIT(dbal_fields_print_type_get(unit, field_info->field_id, &field_print_type));
    if ((field_print_type == DBAL_FIELD_PRINT_TYPE_MAC) || (field_print_type == DBAL_FIELD_PRINT_TYPE_IPV6))
    {
        SHR_BITSET(field_info->field_indication_bm, DBAL_FIELD_IND_IS_FIELD_ADDRESS);
    }

    SHR_IF_ERR_EXIT(dbal_fields_field_types_info_get(unit, field_info->field_id, &field_type_info));
    if (field_type_info->encode_info.encode_mode == DBAL_VALUE_FIELD_ENCODE_ENUM)
    {
        SHR_BITSET(field_info->field_indication_bm, DBAL_FIELD_IND_IS_FIELD_ENUM);
    }

    if (SHR_BITGET(field_info->field_indication_bm, DBAL_FIELD_IND_IS_CONST_VALID))
    {
        SHR_BITSET(table->indications_bm, DBAL_TABLE_IND_RESULT_CONST_VALUE_EXISTS);
    }
exit:
    SHR_FUNC_EXIT;
}

static shr_error_e
dbal_db_init_table_interface_key_field_allocator_update(
    int unit,
    dbal_table_field_info_t * field_info)
{
    uint8 is_allocator;
    SHR_FUNC_INIT_VARS(unit);

    SHR_IF_ERR_EXIT(dbal_fields_is_allocator_get(unit, field_info->field_id, &is_allocator));
    if (is_allocator && !SHR_IS_BITSET(field_info->field_indication_bm, DBAL_FIELD_IND_IS_ALLOCATOR_DISABLED))
    {
        SHR_BITSET(field_info->field_indication_bm, DBAL_FIELD_IND_IS_ALLOCATOR);
    }
exit:
    SHR_FUNC_EXIT;
}

static void
dbal_db_init_table_interface_table_allocator_update(
    int unit,
    dbal_logical_table_t * table_entry,
    dbal_table_field_info_t * field_info)
{
    if (!DBAL_DB_INIT_TABLE_SKIP_SET_ALLOCATOR_FIELD(table_entry)
        && (table_entry->allocator_field_id == DBAL_FIELD_EMPTY)
        && (SHR_IS_BITSET(field_info->field_indication_bm, DBAL_FIELD_IND_IS_ALLOCATOR)))
    {
        table_entry->allocator_field_id = field_info->field_id;
    }

    if (DBAL_DB_INIT_TABLE_SKIP_ALLOCATOR_FOR_VSI_FIELD(table_entry, field_info))
    {
        table_entry->allocator_field_id = DBAL_FIELD_EMPTY;
    }
}

static shr_error_e
dbal_db_init_table_interface_key_field_indications_update(
    int unit,
    dbal_logical_table_t * table_entry,
    dbal_table_field_info_t * field_info)
{
    SHR_FUNC_INIT_VARS(unit);
    SHR_IF_ERR_EXIT(dbal_db_init_table_interface_field_indications_update(unit, table_entry, field_info));

    if (!DBAL_DB_INIT_TABLE_SKIP_SET_ALLOCATOR_FIELD(table_entry))
    {
        SHR_IF_ERR_EXIT(dbal_db_init_table_interface_key_field_allocator_update(unit, field_info));
    }

    if (DBAL_DB_INIT_TABLE_SKIP_ALLOCATOR_FOR_VSI_FIELD(table_entry, field_info))
    {
        SHR_BITCLR(field_info->field_indication_bm, DBAL_FIELD_IND_IS_ALLOCATOR);
    }

    if (SHR_BITGET(field_info->field_indication_bm, DBAL_FIELD_IND_IS_CONST_VALID))
    {
        SHR_BITSET(table_entry->indications_bm, DBAL_TABLE_IND_KEY_CONST_VALUE_EXISTS);
    }

exit:
    SHR_FUNC_EXIT;
}

shr_error_e
dbal_db_init_table_interface_key_post_process(
    int unit,
    dbal_logical_table_t * table)
{
    int jj;
    int bits_offset_in_key = 0;
    uint8 is_core_in_key = FALSE;
    dbal_table_field_info_t *field_info;

    SHR_FUNC_INIT_VARS(unit);

    for (jj = 0; jj < table->nof_key_fields; jj++)
    {
        field_info = &(table->keys_info[jj]);

        DBAL_DB_INIT_TABLE_DB_FIELD_EMPTY_VERIFY(table, field_info);

        if (field_info->field_id == DBAL_FIELD_CORE_ID)
        {
            is_core_in_key = TRUE;

            if (field_info->field_nof_bits != DBAL_CORE_SIZE_IN_BITS)
            {
                SHR_ERR_EXIT(_SHR_E_INTERNAL, "Field core ID has to be %d bit(s) field. table %s\n",
                             DBAL_CORE_SIZE_IN_BITS, table->table_name);
            }
            table->core_id_nof_bits = field_info->field_nof_bits;
        }
        else
        {

            field_info->bits_offset_in_buffer = bits_offset_in_key;
            bits_offset_in_key += field_info->field_nof_bits;
        }

        SHR_IF_ERR_EXIT(dbal_db_init_table_interface_key_field_indications_update(unit, table, field_info));

        dbal_db_init_table_interface_table_allocator_update(unit, table, field_info);

    }

    if (table->table_type != DBAL_TABLE_TYPE_DIRECT)
    {
        if (table->key_size > DBAL_PHYSICAL_KEY_SIZE_IN_BITS)
        {
            SHR_ERR_EXIT(_SHR_E_PARAM, "Table %s - key size (%d) is larger than max allowed (%d).\n",
                         table->table_name, table->key_size, DBAL_PHYSICAL_KEY_SIZE_IN_BITS);
        }

    }
    else
    {
        if (table->key_size > DBAL_TABLE_DIRECT_MAX_KEY_NOF_BITS)
        {
            SHR_ERR_EXIT(_SHR_E_INTERNAL, "table %s Key is bigger than %db (%d ) not supported\n", table->table_name,
                         DBAL_TABLE_DIRECT_MAX_KEY_NOF_BITS, table->key_size);
        }
    }

    if (table->core_mode == DBAL_CORE_MODE_DPC && !is_core_in_key)
    {
        SHR_ERR_EXIT(_SHR_E_INTERNAL, "DPC tables must have core field in Key table %s\n", table->table_name);
    }

exit:
    SHR_FUNC_EXIT;
}

shr_error_e
dbal_db_init_table_interface_result_post_process(
    int unit,
    dbal_tables_e table_id,
    uint32 result_lsb_padding,
    dbal_logical_table_t * table)
{
    int jj, qq;
    int bits_offset_in_payload;
    int max_payload_size, max_nof_result_fields;
    dbal_table_field_info_t *field_info;
    multi_res_info_t *superset_res_type = NULL;

    SHR_FUNC_INIT_VARS(unit);

    max_payload_size = 0;
    max_nof_result_fields = 0;
    if (SHR_IS_BITSET(table->indications_bm, DBAL_TABLE_IND_HAS_RESULT_TYPE)
        && (table_id != DBAL_TABLE_ETM_PP_DESCRIPTOR_EXPANSION))
    {
        superset_res_type = &(table->multi_res_info[table->nof_result_types]);
    }

    for (qq = 0; qq < table->nof_result_types; qq++)
    {
        multi_res_info_t *result_type_set = &(table->multi_res_info[qq]);
        bits_offset_in_payload = result_lsb_padding;
        result_type_set->entry_payload_size = result_lsb_padding;
        for (jj = 0; jj < result_type_set->nof_result_fields; jj++)
        {
            field_info = &(result_type_set->results_info[jj]);

            DBAL_DB_INIT_TABLE_DB_FIELD_EMPTY_VERIFY(table, field_info);

            if (field_info->field_id == DBAL_FIELD_CORE_ID)
            {
                SHR_ERR_EXIT(_SHR_E_INTERNAL, "The field CORE_ID cannot be used as result fields. table %s \n",
                             table->table_name);
            }

            result_type_set->results_info[jj].bits_offset_in_buffer = bits_offset_in_payload;
            bits_offset_in_payload += result_type_set->results_info[jj].field_nof_bits;

            result_type_set->entry_payload_size += result_type_set->results_info[jj].field_nof_bits;

            SHR_IF_ERR_EXIT(dbal_db_init_table_interface_field_indications_update(unit, table, field_info));

            if (SHR_IS_BITSET(table->indications_bm, DBAL_TABLE_IND_HAS_RESULT_TYPE) && superset_res_type)
            {
                SHR_IF_ERR_EXIT(dbal_superset_result_type_field_update(unit, superset_res_type, field_info));
            }
        }

        max_payload_size = UTILEX_MAX(max_payload_size, result_type_set->entry_payload_size);
        max_nof_result_fields = UTILEX_MAX(max_nof_result_fields, result_type_set->nof_result_fields);
        if (superset_res_type)
        {
            sal_strncpy_s(superset_res_type->result_type_name, "superset", DBAL_MAX_STRING_LENGTH - 1);
        }
    }
    table->max_payload_size = max_payload_size;
    table->max_nof_result_fields = max_nof_result_fields;
    if (table->max_payload_size > DBAL_PHYSICAL_RES_SIZE_IN_BITS)
    {
        SHR_ERR_EXIT(_SHR_E_PARAM, "Table %s - result size (%d) is larger than max allowed (%d).\n",
                     table->table_name, table->max_payload_size, DBAL_PHYSICAL_RES_SIZE_IN_BITS);
    }

    if ((table_id == DBAL_TABLE_ETM_PP_DESCRIPTOR_EXPANSION)
        && (table->nof_result_types != ETM_PP_DESCRIPTOR_EXPANSION_NOF_STATIC_RES_TYPES))
    {
        SHR_ERR_EXIT(_SHR_E_INTERNAL, "Table ETM_PP_DESCRIPTOR_EXPANSION has more SATIC result types than expected!\n");
    }

exit:
    SHR_FUNC_EXIT;
}

shr_error_e
dbal_db_init_table_interface_post_process(
    int unit,
    dbal_tables_e table_id,
    uint32 result_lsb_padding,
    dbal_logical_table_t * table)
{
    SHR_FUNC_INIT_VARS(unit);

    if ((table->core_mode != DBAL_CORE_MODE_SBC) && (table->core_mode != DBAL_CORE_MODE_DPC))
    {
        SHR_ERR_EXIT(_SHR_E_INTERNAL, "Invalid core mode for table %s\n", table->table_name);
    }

    SHR_IF_ERR_EXIT(dbal_db_init_table_interface_key_post_process(unit, table));
    SHR_IF_ERR_EXIT(dbal_db_init_table_interface_result_post_process(unit, table_id, result_lsb_padding, table));

    if (dbal_db_init_table_iterator_bitmap_allocation_supported(unit, table_id, table))
    {
        SHR_IF_ERR_EXIT(dbal_db_init_table_iterator_bitmap_allocation(unit, table_id, table));
    }

    if (table->table_type == DBAL_TABLE_TYPE_LPM)
    {
        SHR_IF_ERR_EXIT(dbal_tables_indication_set
                        (unit, table_id, DBAL_TABLE_IND_IS_NONE_DIRECT_FORCE_OPTIMIZED, TRUE));
    }

exit:
    SHR_FUNC_EXIT;
}

static shr_error_e
dbal_db_init_table_sw_post_process(
    int unit,
    dbal_logical_table_t * table)
{
    int qq;
    int max_sw_payload_size;
    multi_res_info_t *result_type_set;
    SHR_FUNC_INIT_VARS(unit);
    max_sw_payload_size = 0;
    for (qq = 0; qq < table->nof_result_types; qq++)
    {
        result_type_set = &(table->multi_res_info[qq]);
        max_sw_payload_size = UTILEX_MAX(max_sw_payload_size, BITS2BYTES(result_type_set->entry_payload_size));
    }
    table->sw_access_info.sw_payload_length_bytes = max_sw_payload_size;
    if (table->sw_access_info.sw_payload_length_bytes > DBAL_PHYSICAL_RES_SIZE_IN_BYTES)
    {
        SHR_ERR_EXIT(_SHR_E_INTERNAL, "table %s, result length for SW table id %d bytes exceeding the max %u bytes.\n",
                     table->table_name, table->sw_access_info.sw_payload_length_bytes,
                     (unsigned) DBAL_PHYSICAL_RES_SIZE_IN_BYTES);
    }

exit:
    SHR_FUNC_EXIT;
}

static void
dbal_db_init_table_reverse_instance_order(
    dbal_table_field_info_t * field_info)
{

    dbal_table_field_info_t *field_info_instance_low = NULL;
    dbal_table_field_info_t *field_info_instance_high = NULL;
    int offset_temp = 0;
    int nof_instance = field_info->nof_instances;
    int instance_index;

    for (instance_index = 0; instance_index < nof_instance / 2; instance_index++)
    {
        field_info_instance_low = field_info + instance_index;
        field_info_instance_high = field_info + nof_instance - 1 - instance_index;

        offset_temp = field_info_instance_low->bits_offset_in_buffer;
        field_info_instance_low->bits_offset_in_buffer = field_info_instance_high->bits_offset_in_buffer;
        field_info_instance_high->bits_offset_in_buffer = offset_temp;
    }
}

static void
dbal_db_init_table_fields_reverse_instance_order(
    dbal_table_field_info_t * field_infos,
    int nof_fields)
{
    int field_index;
    int nof_instance;
    dbal_table_field_info_t *field_info;

    for (field_index = 0; field_index < nof_fields;)
    {
        field_info = &field_infos[field_index];
        nof_instance = field_info->nof_instances;
        if (nof_instance > 1)
        {
            dbal_db_init_table_reverse_instance_order(field_info);
        }
        field_index += nof_instance;
    }
}

static void
dbal_db_init_table_key_and_result_reverse_instance_order(
    dbal_tables_e table_id,
    dbal_logical_table_t * table)
{
    int result_type_index;
    multi_res_info_t *multi_res_info;

    dbal_db_init_table_fields_reverse_instance_order(table->keys_info, table->nof_key_fields);

    for (result_type_index = 0; result_type_index < table->nof_result_types; result_type_index++)
    {
        multi_res_info = &table->multi_res_info[result_type_index];
        dbal_db_init_table_fields_reverse_instance_order(multi_res_info->results_info,
                                                         multi_res_info->nof_result_fields);
    }
}

shr_error_e
dbal_db_init_table_mdb_post_process(
    int unit,
    dbal_tables_e table_id,
    uint32 result_lsb_padding,
    dbal_logical_table_t * table)
{
    int qq, kk;
    int bits_offset_in_buffer;
    multi_res_info_t *result_type_set;
    uint32 key_width = 0, key_prefix_size = 0;

    SHR_FUNC_INIT_VARS(unit);

    if (table->table_type == DBAL_TABLE_TYPE_LPM)
    {
        key_width = dnx_data_mdb.kaps.key_width_in_bits_get(unit);
        key_prefix_size = dnx_data_mdb.kaps.key_prefix_length_get(unit);
    }

    if (dbal_table_is_out_lif(table))
    {
        SHR_BITSET(table->indications_bm, DBAL_TABLE_IND_SW_RESULT_TYPE_NO_ACCESS);
    }

    for (qq = 0; qq < table->nof_result_types; qq++)
    {
        result_type_set = &(table->multi_res_info[qq]);
        bits_offset_in_buffer = result_lsb_padding;
        for (kk = result_type_set->nof_result_fields - 1; kk >= 0; kk--)
        {
            result_type_set->results_info[kk].bits_offset_in_buffer = bits_offset_in_buffer;
            bits_offset_in_buffer += result_type_set->results_info[kk].field_nof_bits;
            if (SHR_IS_BITSET(table->indications_bm, DBAL_TABLE_IND_RESULT_TYPE_MAPPED_TO_SW)
                && (result_type_set->results_info[kk].field_id == DBAL_FIELD_RESULT_TYPE)
                && !SHR_IS_BITSET(table->indications_bm, DBAL_TABLE_IND_SW_RESULT_TYPE_NO_ACCESS))
            {
                table->sw_access_info.sw_payload_length_bytes =
                    BITS2BYTES(result_type_set->results_info[kk].field_nof_bits);
            }
            else if (result_type_set->results_info[kk].field_id == DBAL_FIELD_NEXT_OUTLIF_POINTER)
            {
                result_type_set->has_link_list = TRUE;
            }
        }
    }

    bits_offset_in_buffer = 0;
    if (table->table_type == DBAL_TABLE_TYPE_LPM)
    {
        for (kk = 0; kk < table->nof_key_fields; kk++)
        {
            if (table->keys_info[kk].field_id != DBAL_FIELD_CORE_ID)
            {
                bits_offset_in_buffer += table->keys_info[kk].field_nof_bits;
                table->keys_info[kk].bits_offset_in_buffer = key_width - (key_prefix_size + bits_offset_in_buffer);
                if (table->keys_info[kk].bits_offset_in_buffer < 0)
                {
                    SHR_ERR_EXIT(_SHR_E_INTERNAL, "table %s, invalid key size for LPM table.\n", table->table_name);
                }
            }
        }
        table->key_size = key_width;
    }
    else
    {
        for (kk = table->nof_key_fields - 1; kk >= 0; kk--)
        {
            if (table->keys_info[kk].field_id != DBAL_FIELD_CORE_ID)
            {
                table->keys_info[kk].bits_offset_in_buffer = bits_offset_in_buffer;
                bits_offset_in_buffer += table->keys_info[kk].field_nof_bits;
            }
        }
    }

    if ((table->key_size > SAL_UINT32_NOF_BITS) && (table->table_type == DBAL_TABLE_TYPE_DIRECT))
    {
        SHR_ERR_EXIT(_SHR_E_INTERNAL, "MDB tables's key of type direct is limited to 32 bit. table %s\n",
                     table->table_name);
    }

    if (table->key_size > DBAL_PHYSICAL_KEY_SIZE_IN_BITS)
    {
        SHR_ERR_EXIT(_SHR_E_PARAM, "Table %s - key size (%d) is larger than max allowed (%d).\n",
                     table->table_name, table->key_size, DBAL_PHYSICAL_KEY_SIZE_IN_BITS);
    }
    if (table->max_payload_size > DBAL_PHYSICAL_RES_SIZE_IN_BITS)
    {
        SHR_ERR_EXIT(_SHR_E_PARAM, "Table %s - result size (%d) is larger than max allowed (%d).\n",
                     table->table_name, table->max_payload_size, DBAL_PHYSICAL_RES_SIZE_IN_BITS);
    }
    if (!sw_state_is_warm_boot(unit))
    {

        if ((table->physical_db_id[0] == DBAL_PHYSICAL_TABLE_LEXEM)
            || (table->physical_db_id[0] == DBAL_PHYSICAL_TABLE_SEXEM_3)
            || (table->physical_db_id[1] == DBAL_PHYSICAL_TABLE_LEXEM)
            || (table->physical_db_id[1] == DBAL_PHYSICAL_TABLE_SEXEM_3))
        {
            SHR_BITSET(table->indications_bm, DBAL_TABLE_IND_IS_LEARNING_EN);
        }
    }

    if (DBAL_TABLE_IS_TCAM(table))
    {
        SHR_BITSET(table->indications_bm, DBAL_TABLE_IND_IS_PRIORITY_SUPPORTED);
    }

    dbal_db_init_table_key_and_result_reverse_instance_order(table_id, table);

exit:
    SHR_FUNC_EXIT;
}

#if defined(INCLUDE_KBP)
shr_error_e
dbal_db_init_table_kbp_post_process(
    int unit,
    dbal_tables_e table_id,
    uint32 result_lsb_padding,
    dbal_logical_table_t * table)
{
    int qq, kk;
    int bits_offset_in_buffer;
    multi_res_info_t *result_type_set;
    uint32 key_width = 0, key_prefix_size = 0;

    SHR_FUNC_INIT_VARS(unit);

    SHR_IF_ERR_EXIT(dnx_kbp_valid_key_width(unit, table->key_size, &key_width));

    if (table_id < DBAL_NOF_TABLES)
    {
        uint32 payload_size;
        SHR_IF_ERR_EXIT(dnx_kbp_valid_result_width(unit, table->max_payload_size, &payload_size));
        table->max_payload_size = payload_size;
    }
    key_prefix_size = 0;

    for (qq = 0; qq < table->nof_result_types; qq++)
    {
        result_type_set = &(table->multi_res_info[qq]);
        bits_offset_in_buffer = 0;
        for (kk = result_type_set->nof_result_fields - 1; kk >= 0; kk--)
        {
            result_type_set->results_info[kk].bits_offset_in_buffer = bits_offset_in_buffer;
            bits_offset_in_buffer += result_type_set->results_info[kk].field_nof_bits;
            if (SHR_IS_BITSET(table->indications_bm, DBAL_TABLE_IND_RESULT_TYPE_MAPPED_TO_SW)
                && (result_type_set->results_info[kk].field_id == DBAL_FIELD_RESULT_TYPE))
            {
                table->sw_access_info.sw_payload_length_bytes =
                    BITS2BYTES(result_type_set->results_info[kk].field_nof_bits);
            }
            if (result_type_set->results_info[kk].field_id == DBAL_FIELD_NEXT_OUTLIF_POINTER)
            {
                result_type_set->has_link_list = TRUE;
            }
        }
    }

    bits_offset_in_buffer = 0;
    for (kk = 0; kk < table->nof_key_fields; kk++)
    {
        if (table->keys_info[kk].field_id != DBAL_FIELD_CORE_ID)
        {
            bits_offset_in_buffer += table->keys_info[kk].field_nof_bits;
            table->keys_info[kk].bits_offset_in_buffer = key_width - (key_prefix_size + bits_offset_in_buffer);
            if (table->keys_info[kk].bits_offset_in_buffer < 0)
            {
                SHR_ERR_EXIT(_SHR_E_INTERNAL, "table %s, invalid key size for LPM table.\n", table->table_name);
            }
        }
    }
    table->key_size = key_width;

    if ((table->key_size > SAL_UINT32_NOF_BITS) && (table->table_type == DBAL_TABLE_TYPE_DIRECT))
    {
        SHR_ERR_EXIT(_SHR_E_INTERNAL, "MDB tables's key of type direct is limited to 32 bit. table %s\n",
                     table->table_name);
    }

    if (table->key_size > DBAL_PHYSICAL_KEY_SIZE_IN_BITS)
    {
        SHR_ERR_EXIT(_SHR_E_PARAM, "Table %s - key size (%d) is larger than max allowed (%d).\n",
                     table->table_name, table->key_size, DBAL_PHYSICAL_KEY_SIZE_IN_BITS);
    }
    if (table->max_payload_size > DBAL_PHYSICAL_RES_SIZE_IN_BITS)
    {
        SHR_ERR_EXIT(_SHR_E_PARAM, "Table %s - result size (%d) is larger than max allowed (%d).\n",
                     table->table_name, table->max_payload_size, DBAL_PHYSICAL_RES_SIZE_IN_BITS);
    }
    if (DBAL_TABLE_IS_TCAM(table))
    {
        SHR_BITSET(table->indications_bm, DBAL_TABLE_IND_IS_PRIORITY_SUPPORTED);
    }

    dbal_db_init_table_key_and_result_reverse_instance_order(table_id, table);

exit:
    SHR_FUNC_EXIT;
}
#else
/* *INDENT-OFF* */
shr_error_e dbal_db_init_table_kbp_post_process(int unit,dbal_tables_e table_id,uint32 result_lsb_padding,dbal_logical_table_t * table){DNX_KBP_DUMMY_PROTOTYPE_ERR_MSG("dbal_db_init_table_kbp_post_process")}

#endif


static shr_error_e
dbal_db_init_table_hl_tcam_post_process(
    int unit,
    dbal_logical_table_t * table)
{
    int iter;
    dbal_hl_l2p_info_t *access_info = &(table->hl_mapping_multi_res[0].l2p_hl_info[DBAL_HL_ACCESS_MEMORY]);
    uint32 data_size;

    SHR_FUNC_INIT_VARS(unit);

    
    if (table->hl_mapping_multi_res[0].l2p_hl_info[DBAL_HL_ACCESS_REGISTER].num_of_access_fields != 0)
    {
        SHR_ERR_EXIT(_SHR_E_PARAM, "HL TCAM does not support mapping to register. Table: %s\n", table->table_name);
    }
    
    for (iter = 0; iter < access_info->num_of_access_fields; ++iter)
    {
        if (access_info->l2p_fields_info[iter].nof_conditions != 0)
        {
            SHR_ERR_EXIT(_SHR_E_PARAM, "Table %s (HL TCAM) - conditions are not supported \n", table->table_name);
        }
    }

    for (iter = 0; iter < access_info->num_of_access_fields; ++iter)
    {
        int len_from_memory = 0;
        dbal_hl_l2p_field_info_t *l2p_fields_info = &access_info->l2p_fields_info[iter];

#ifdef BCM_ACCESS_SUPPORT
        if (ACCESS_IS_INITIALIZED(unit))
        {
            SHR_IF_ERR_EXIT(dnx_mem_sw_init_is_custom(unit, l2p_fields_info->memory[0],
                                                      &(table->hl_mapping_multi_res[0].is_default_non_standard)));
        }
        else
#endif
        {
            SHR_IF_ERR_EXIT(dnx_init_mem_default_mode_get(unit, l2p_fields_info->memory[0],
                                                          &(table->hl_mapping_multi_res[0].is_default_non_standard)));
        }

        
        if (l2p_fields_info->hw_field != DBAL_HL_ACCESS_HW_FIELD_INVALID)
        {
            dbal_hl_tcam_access_type_e access_type_id = l2p_fields_info->hl_tcam_access_type;
            
            SHR_IF_ERR_EXIT(dbal_hl_access_field_info_get_per_access(unit, table, l2p_fields_info->memory[0],
                                                                     l2p_fields_info->hw_field,
                                                                     DBAL_HL_NEW_ACCESS_SCOPE_GLOBAL_FIELD, 1, NULL,
                                                                     &len_from_memory, NULL));
            
            switch (access_type_id)
            {
                case DBAL_HL_TCAM_ACCESS_TYPE_KEY:
                case DBAL_HL_TCAM_ACCESS_TYPE_KEY_MASK:
                    data_size = table->key_size;
                    break;
                case DBAL_HL_TCAM_ACCESS_TYPE_RESULT:
                    
                    data_size = table->max_payload_size - 1;
                    break;
                case DBAL_HL_TCAM_ACCESS_TYPE_VALID_BIT:
                    data_size = len_from_memory;
                    break;
                default:
                    SHR_ERR_EXIT(_SHR_E_PARAM,
                                 "hl_tcam_access_type was not set to a valid value in table %s, l2p_fields_info[%d] \n",
                                 table->table_name, iter);
            }

            l2p_fields_info->nof_bits_in_interface = data_size;
            if (data_size > len_from_memory)
            {
                SHR_ERR_EXIT(_SHR_E_PARAM,
                             "Illegal size in table %s , hl_tcam_access_type %s, length from memory is %d, but size from table is %u \n",
                             table->table_name, dbal_hl_tcam_access_type_to_string(unit, access_type_id),
                             len_from_memory, data_size);
            }
        }
    }

exit:
    SHR_FUNC_EXIT;
}

static shr_error_e
dbal_db_init_table_hl_direct_memory_post_process(
    int unit,
    dbal_logical_table_t * table,
    dbal_hl_l2p_field_info_t * curr_l2p_field,
    multi_res_info_t * result_type_set,
    int field_in_table,
    int res_type)
{
    int is_default_non_standard = 0;

    SHR_FUNC_INIT_VARS(unit);

    if (!SHR_IS_BITSET(table->indications_bm, DBAL_TABLE_IND_IS_NEW_ACCESS)
        && !SOC_MEM_IS_VALID(unit, curr_l2p_field->memory[0]))
    {
        SHR_ERR_EXIT(_SHR_E_INTERNAL, "The field %s, table %s mapped to invalid memory, result type %s\n",
                     dbal_field_to_string(unit, result_type_set->results_info[field_in_table].field_id),
                     table->table_name, result_type_set->result_type_name);
    }

    if (curr_l2p_field->hw_field != DBAL_HL_ACCESS_HW_FIELD_INVALID)
    {
        SHR_IF_ERR_EXIT(dbal_hl_access_field_offset_get_per_access(unit, table, curr_l2p_field, 1,
                                                                   &curr_l2p_field->hw_field_offset_in_mem));
    }

    if (curr_l2p_field->alias_memory != DBAL_HL_ACCESS_HW_ENTITY_INVALID)
    {
#ifdef BCM_ACCESS_SUPPORT
        if (ACCESS_IS_INITIALIZED(unit))
        {
            SHR_IF_ERR_EXIT(dnx_mem_sw_init_is_custom(unit, curr_l2p_field->alias_memory, &is_default_non_standard));
        }
        else
#endif
        {
            SHR_IF_ERR_EXIT(dnx_init_mem_default_mode_get
                            (unit, curr_l2p_field->alias_memory, &is_default_non_standard));
        }
        curr_l2p_field->is_default_non_standard = is_default_non_standard;
    }
    else
    {
#ifdef BCM_ACCESS_SUPPORT
        if (ACCESS_IS_INITIALIZED(unit))
        {
            SHR_IF_ERR_EXIT(dnx_mem_sw_init_is_custom(unit, curr_l2p_field->memory[0], &is_default_non_standard));
        }
        else
#endif
        {
            SHR_IF_ERR_EXIT(dnx_init_mem_default_mode_get(unit, curr_l2p_field->memory[0], &is_default_non_standard));
        }
        curr_l2p_field->is_default_non_standard = is_default_non_standard;
    }

    if (is_default_non_standard)
    {
        table->hl_mapping_multi_res[res_type].is_default_non_standard = 1;
        SHR_BITSET(table->indications_bm, DBAL_TABLE_IND_IS_DEFAULT_NON_STANDARD);
    }
    if ((curr_l2p_field->array_offset_info.formula != NULL)
        || (curr_l2p_field->entry_offset_info.formula != NULL)
        || (curr_l2p_field->data_offset_info.formula != NULL)
        || (curr_l2p_field->block_index_info.formula != NULL)
        || (curr_l2p_field->alias_data_offset_info.formula != NULL))
    {
        SHR_BITCLR(table->indications_bm, DBAL_TABLE_IND_RANGE_SET_SUPPORTED);
    }

exit:
    SHR_FUNC_EXIT;
}

static shr_error_e
dbal_db_init_table_hl_direct_register_post_process(
    int unit,
    dbal_logical_table_t * table,
    dbal_hl_l2p_field_info_t * curr_l2p_field,
    multi_res_info_t * result_type_set,
    int field_in_table,
    int res_type)
{
    int is_default_non_standard = 0;

    SHR_FUNC_INIT_VARS(unit);

    SHR_BITCLR(table->indications_bm, DBAL_TABLE_IND_RANGE_SET_SUPPORTED);

    if (!curr_l2p_field->reg ||
        ((!SHR_IS_BITSET(table->indications_bm, DBAL_TABLE_IND_IS_NEW_ACCESS))
         && !SOC_REG_IS_VALID(unit, curr_l2p_field->reg[0])))
    {
        SHR_ERR_EXIT(_SHR_E_INTERNAL,
                     "The field %s, table %s mapped to invalid register, result type %s\n",
                     dbal_field_to_string(unit, result_type_set->results_info[field_in_table].field_id),
                     table->table_name, result_type_set->result_type_name);
    }

    SHR_IF_ERR_EXIT(dbal_hl_reg_default_mode_get_per_access(unit,
                                                            curr_l2p_field->reg[0],
                                                            SHR_IS_BITSET(table->indications_bm,
                                                                          DBAL_TABLE_IND_IS_NEW_ACCESS),
                                                            &is_default_non_standard));

    curr_l2p_field->is_default_non_standard = is_default_non_standard;
    if (is_default_non_standard)
    {
        table->hl_mapping_multi_res[res_type].is_default_non_standard = 1;
        SHR_BITSET(table->indications_bm, DBAL_TABLE_IND_IS_DEFAULT_NON_STANDARD);
        if (SHR_IS_BITSET(table->indications_bm, DBAL_TABLE_IND_IS_ITERATOR_OPTIMIZED))
        {
            SHR_ERR_EXIT(_SHR_E_UNAVAIL, "Iterator optimized is not supported for non-standard default, table[%s]",
                         table->table_name);
        }
    }

    if (curr_l2p_field->hw_field != DBAL_HL_ACCESS_HW_FIELD_INVALID)
    {
        SHR_IF_ERR_EXIT(dbal_hl_access_field_offset_get_per_access(unit, table, curr_l2p_field, 0,
                                                                   &curr_l2p_field->hw_field_offset_in_mem));
    }

exit:
    SHR_FUNC_EXIT;
}


shr_error_e
dbal_db_init_table_hl_direct_post_process(
    int unit,
    dbal_logical_table_t * table)
{
    int res_type, jj;
    dbal_hard_logic_access_types_e hl_access_type;
    int bits_offset_in_sw_payload = 0;
    multi_res_info_t *result_type_set;
    dbal_hl_l2p_field_info_t *curr_l2p_field;

    SHR_FUNC_INIT_VARS(unit);

    SHR_BITSET(table->indications_bm, DBAL_TABLE_IND_RANGE_SET_SUPPORTED);
    for (res_type = 0; res_type < table->nof_result_types; res_type++)
    {
        int total_of_mapped_fields = 0;
        result_type_set = &(table->multi_res_info[res_type]);
        bits_offset_in_sw_payload = 0;
        table->hl_mapping_multi_res[res_type].is_default_non_standard = 0;

        for (hl_access_type = 0; hl_access_type < DBAL_NOF_HL_ACCESS_TYPES; hl_access_type++)
        {
            if (hl_access_type == DBAL_HL_ACCESS_UNMAPPED)
            {
                continue;
            }

            total_of_mapped_fields +=
                table->hl_mapping_multi_res[res_type].l2p_hl_info[hl_access_type].num_of_access_fields;
            for (jj = 0; jj < table->hl_mapping_multi_res[res_type].l2p_hl_info[hl_access_type].num_of_access_fields;
                 jj++)
            {
                int field_in_table = 0;
                curr_l2p_field = &table->hl_mapping_multi_res[res_type].l2p_hl_info[hl_access_type].l2p_fields_info[jj];

                
                for (field_in_table = 0; field_in_table < result_type_set->nof_result_fields; field_in_table++)
                {
                    if ((result_type_set->results_info[field_in_table].field_id == curr_l2p_field->field_id)
                        && (result_type_set->results_info[field_in_table].inst_idx == curr_l2p_field->inst_idx))
                    {
                        break;
                    }
                }

                if (field_in_table == result_type_set->nof_result_fields)
                {
                    SHR_ERR_EXIT(_SHR_E_INTERNAL, "L2P field %s not found in table %s as result field, "
                                 "result type %s\n",
                                 dbal_field_to_string(unit, curr_l2p_field->field_id), table->table_name,
                                 result_type_set->result_type_name);
                }
                curr_l2p_field->field_pos_in_interface = field_in_table;
                curr_l2p_field->nof_bits_in_interface = (curr_l2p_field->access_nof_bits != 0) ?
                    curr_l2p_field->access_nof_bits : result_type_set->results_info[field_in_table].field_nof_bits;
                curr_l2p_field->offset_in_interface = curr_l2p_field->access_offset +
                    result_type_set->results_info[field_in_table].bits_offset_in_buffer;
                
                switch (hl_access_type)
                {
                    case DBAL_HL_ACCESS_MEMORY:
                        SHR_IF_ERR_EXIT(dbal_db_init_table_hl_direct_memory_post_process(unit,
                                                                                         table,
                                                                                         curr_l2p_field,
                                                                                         result_type_set,
                                                                                         field_in_table, res_type));
                        break;
                    case DBAL_HL_ACCESS_REGISTER:
                        SHR_IF_ERR_EXIT(dbal_db_init_table_hl_direct_register_post_process(unit,
                                                                                           table,
                                                                                           curr_l2p_field,
                                                                                           result_type_set,
                                                                                           field_in_table, res_type));
                        break;
                    case DBAL_HL_ACCESS_SW:
                        SHR_BITCLR(table->indications_bm, DBAL_TABLE_IND_RANGE_SET_SUPPORTED);
                        curr_l2p_field->field_pos_in_interface = field_in_table;
                        
                        if (curr_l2p_field->access_nof_bits == 0)
                        {
                            curr_l2p_field->access_nof_bits =
                                result_type_set->results_info[field_in_table].field_nof_bits;
                        }
                        curr_l2p_field->nof_bits_in_interface = curr_l2p_field->access_nof_bits;
                        curr_l2p_field->offset_in_interface =
                            curr_l2p_field->access_offset +
                            result_type_set->results_info[field_in_table].bits_offset_in_buffer;
                        
                        curr_l2p_field->access_offset = bits_offset_in_sw_payload;
                        bits_offset_in_sw_payload += curr_l2p_field->access_nof_bits;
                        break;
                    default:
                        SHR_ERR_EXIT(_SHR_E_INTERNAL, "Invalid access type, %d, for hard-logic table: %s\n",
                                     hl_access_type, table->table_name);
                        break;
                }

                if (curr_l2p_field->alias_data_offset_info.formula != NULL)
                {
                    if (curr_l2p_field->memory[0] != DBAL_HL_ACCESS_HW_ENTITY_INVALID)
                    {
                        SHR_IF_ERR_EXIT(dbal_hl_access_memreg_size_get_per_access(unit,
                                                                                  curr_l2p_field->memory[0],
                                                                                  SHR_IS_BITSET
                                                                                  (table->indications_bm,
                                                                                   DBAL_TABLE_IND_IS_NEW_ACCESS),
                                                                                  &curr_l2p_field->alias_data_offset_info.internal_inparam));
                    }
                    else
                    {
                        SHR_ERR_EXIT(_SHR_E_INTERNAL,
                                     "table %s not supported aliasing with offset to registers\n", table->table_name);
                    }

                }
            }
        }

        if (total_of_mapped_fields < result_type_set->nof_result_fields)
        {
            SHR_ERR_EXIT(_SHR_E_INTERNAL, "table %s not all fields are mapped %d of %d \n", table->table_name,
                         total_of_mapped_fields, result_type_set->nof_result_fields);
        }
    }

exit:
    SHR_FUNC_EXIT;
}

shr_error_e
dbal_db_init_tables_post_process(
    int unit,
    dbal_logical_table_t * tables_info)
{
    int table_id;
    dbal_logical_table_t *table = NULL;
    dbal_table_status_e table_status;
    shr_error_e rv;
    int is_wb = sw_state_is_warm_boot(unit);

    SHR_FUNC_INIT_VARS(unit);

    for (table_id = 0; table_id < DBAL_NOF_STATIC_TABLES; table_id++)
    {
        SHR_IF_ERR_EXIT(DBAL_SW_STATE_TBL_PROP.table_status.get(unit, table_id, &table_status));
        table = &tables_info[table_id];
        

        if (is_wb)
        {
            if ((table_status == DBAL_TABLE_NOT_INITIALIZED) || (table_status == DBAL_TABLE_HW_ERROR))
            {
                continue;
            }
        }
        else
        {
            if ((table_status == DBAL_NOF_TABLE_STATUS) || (table_status == DBAL_TABLE_HW_ERROR)
                || (table->maturity_level == DBAL_MATURITY_LOW))
            {
                if ((table_status != DBAL_TABLE_HW_ERROR) && ((table_status != DBAL_TABLE_NOT_INITIALIZED)))
                {
                    SHR_IF_ERR_EXIT(DBAL_SW_STATE_TBL_PROP.
                                    table_status.set(unit, table_id, DBAL_TABLE_NOT_INITIALIZED));
                }
                continue;
            }
        }

        SHR_IF_ERR_EXIT(dbal_db_init_table_interface_post_process(unit, table_id, 0, table));

        
        if (table_status == DBAL_TABLE_INCOMPATIBLE_IMAGE)
        {
            continue;
        }

        
        switch (table->access_method)
        {
            case DBAL_ACCESS_METHOD_MDB:
                SHR_IF_ERR_EXIT(dbal_db_init_table_mdb_post_process(unit, table_id, 0, table));
                break;
            case DBAL_ACCESS_METHOD_KBP:
                SHR_IF_ERR_EXIT(dbal_db_init_table_kbp_post_process(unit, table_id, 0, table));
                break;
            case DBAL_ACCESS_METHOD_TCAM_CS:
                break;
            case DBAL_ACCESS_METHOD_HARD_LOGIC:
                if (SHR_IS_BITSET(table->indications_bm, DBAL_TABLE_IND_IS_NEW_ACCESS)
                    && !SOC_IS_NEW_ACCESS_INITIALIZED(unit))
                {
                    SHR_ERR_EXIT(_SHR_E_INTERNAL, "New access is not initialized");
                }
                
                if (table->table_type == DBAL_TABLE_TYPE_TCAM_DIRECT)
                {
                    rv = dbal_db_init_table_hl_tcam_post_process(unit, table);
                }
                else
                {
                    rv = dbal_db_init_table_hl_direct_post_process(unit, table);
                }

                if (SHR_FAILURE(rv))
                {
                    
                    if (rv == _SHR_E_UNAVAIL)
                    {
                        SHR_SET_CURRENT_ERR(rv);
                        SHR_EXIT();
                    }
                    else
                    {
                        SHR_IF_ERR_EXIT(dbal_tables_update_hw_error(unit, table_id));
                        continue;
                    }
                }
                break;
            case DBAL_ACCESS_METHOD_SW_STATE:
                SHR_IF_ERR_EXIT(dbal_db_init_table_sw_post_process(unit, table));
                break;

            case DBAL_ACCESS_METHOD_PEMLA:
            default:
                break;
        }

        if (!is_wb)
        {
            
            SHR_IF_ERR_EXIT(DBAL_SW_STATE_TBL_PROP.table_status.set(unit, table_id, DBAL_TABLE_INITIALIZED));
            
            SHR_IF_ERR_EXIT(DBAL_SW_STATE_TBL_PROP.indications_bm.set(unit, table_id, table->indications_bm[0]));
        }
        else
        {
            
            SHR_IF_ERR_EXIT(DBAL_SW_STATE_TBL_PROP.indications_bm.get(unit, table_id, table->indications_bm));
        }
    }

exit:
    SHR_FUNC_EXIT;
}

void
dbal_db_init_sw_state_set_indirect_table_size(
    int unit,
    dbal_logical_table_t * table_entry,
    dnx_dbal_formula_offset_cb indirect_table_size_cb,
    int indirect_table_size_int)
{
    if (indirect_table_size_cb)
    {
        table_entry->sw_access_info.table_size_formula.cb = indirect_table_size_cb;
    }
    else
    {
        table_entry->sw_access_info.table_size_formula.val = indirect_table_size_int;
    }
}

shr_error_e
dbal_db_init_table_set_mdb_info(
    int unit,
    table_db_struct_t * cur_table_param,
    char *phy_db,
    int app_db_id_size,
    int app_db_id,
    dbal_stage_e stage)
{
    SHR_FUNC_INIT_VARS(unit);
    
    sal_strncpy_s(cur_table_param->mdb_access->phy_db, phy_db, sizeof(cur_table_param->mdb_access->phy_db));
    
    cur_table_param->mdb_access->app_db_id_size = app_db_id_size;
    
    cur_table_param->mdb_access->app_db_id = app_db_id;
    
    cur_table_param->pipe_stage = stage;
    SHR_EXIT();
exit:
    SHR_FUNC_EXIT;
}

shr_error_e
dbal_db_init_hw_entity_group_general_info_set(
    int unit,
    hl_group_info_t * group_info,
    uint32 element_counter,
    uint8 is_reg)
{
    SHR_FUNC_INIT_VARS(unit);

    
    group_info->group_hw_entity_num = element_counter;
    
    group_info->is_reg = is_reg;

    SHR_EXIT();
exit:
    SHR_FUNC_EXIT;
}

void
dbal_db_init_hw_entity_group_reg_mem_name_set(
    int unit,
    hl_group_info_t * group_info,
    int element_index,
    int reg_or_mem_id)
{
    group_info->hw_entity_id[element_index] = reg_or_mem_id;
}
