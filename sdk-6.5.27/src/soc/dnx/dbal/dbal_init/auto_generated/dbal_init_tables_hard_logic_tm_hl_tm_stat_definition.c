
/*
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2022 Broadcom Inc. All rights reserved.
 * 
 */

shr_error_e
_dbal_init_tables_hard_logic_tm_hl_tm_stat_definition_stat_rjct_filter_group_init(
int unit,
table_db_struct_t * cur_table_param,
dbal_logical_table_t * table_info)
{
    dbal_logical_table_t * table_entry = table_info + DBAL_TABLE_STAT_RJCT_FILTER_GROUP;
    int is_valid = TRUE;
    uint8 is_skip_table_init = FALSE;
    char * current_image = NULL;
    dbal_maturity_level_e maturity_level;
    SHR_FUNC_INIT_VARS(unit);
    dbal_init_table_db_struct_clear(cur_table_param);
    maturity_level = DBAL_MATURITY_HIGH;
    SHR_IF_ERR_EXIT(dbal_db_init_table_general_info_and_image_handle(unit, table_entry, DBAL_TABLE_STAT_RJCT_FILTER_GROUP, is_valid, maturity_level, "STAT_RJCT_FILTER_GROUP", DBAL_ACCESS_METHOD_HARD_LOGIC, current_image, &is_skip_table_init));
    if (is_skip_table_init)
    {
        SHR_EXIT();
    }
    table_entry->table_type = DBAL_TABLE_TYPE_DIRECT;
    table_entry->nof_labels = 1;
    DBAL_DB_INIT_TABLE_LABELS_ALLOC(table_entry)
    table_entry->table_labels[0] = DBAL_LABEL_STAT;
    {
        int field_index = 0;
        dbal_table_field_info_t * dbal_db_field;
        table_db_field_params_struct_t db_field;
        DBAL_DB_INIT_TABLE_INTERFACE_KEY_FIELDS_ALLOC(table_entry, 1);
        {
            dbal_db_field = &table_entry->keys_info[field_index];
            SHR_IF_ERR_EXIT(dbal_db_init_table_field_set_mandatory_values(unit, DBAL_FIELD_DROP_REASON, DBAL_FIELD_TYPE_DEF_UINT, dbal_db_field));
            dbal_db_init_table_field_params_init(&db_field);
            db_field.size = 6;
            db_field.max_value = dnx_data_stat.drop_reasons.nof_drop_reasons_get(unit)-1;
            SHR_IF_ERR_EXIT(dbal_db_init_table_field_set_optional_or_default_values(unit, table_entry, dbal_db_field, &db_field, TRUE));
            field_index += dbal_db_field->nof_instances;
        }
        table_entry->nof_key_fields = field_index;
        dbal_db_init_table_calculate_key_size(table_entry);
    }
    {
        int field_index = 0;
        int result_type_counter = 0;
        dbal_table_field_info_t * dbal_db_field;
        table_db_field_params_struct_t db_field;
        DBAL_DB_INIT_TABLE_NOF_RESULT_TYPES_SET(table_entry, 1);
        SHR_IF_ERR_EXIT(dbal_db_init_table_db_interface_results_alloc(unit, table_entry));
        DBAL_DB_INIT_TABLE_NOF_RESULT_FIELDS_SET(table_entry, (table_entry->multi_res_info[result_type_counter]), 0 + 8);
        DBAL_DB_INIT_TABLE_INTERFACE_RESULT_FIELDS_ALLOC(table_entry, table_entry->multi_res_info[result_type_counter]);
        {
            dbal_db_field = &table_entry->multi_res_info[result_type_counter].results_info[field_index];
            SHR_IF_ERR_EXIT(dbal_db_init_table_field_set_mandatory_values(unit, DBAL_FIELD_STAT_DROP_REASON_RJCT_MASK, DBAL_FIELD_TYPE_DEF_BOOL, dbal_db_field));
            dbal_db_init_table_field_params_init(&db_field);
            db_field.nof_instances = 8;
            SHR_IF_ERR_EXIT(dbal_db_init_table_field_set_optional_or_default_values(unit, table_entry, dbal_db_field, &db_field, FALSE));
            field_index += dbal_db_field->nof_instances;
        }
    }
    dbal_db_init_table_db_struct_access_clear(cur_table_param, table_entry);
    table_entry->core_mode = DBAL_CORE_MODE_SBC;
    dbal_db_init_table_add_result_type_physical_values_by_result_type_index(table_entry);
    {
        int map_idx = 0;
        int access_counter;
        map_idx = 0;
        access_counter = 0;
        sal_strncpy(cur_table_param->hl_access[map_idx].mapping_result_name, EMPTY, sizeof(cur_table_param->hl_access[map_idx].mapping_result_name));
        if (DBAL_IS_JR2_A0 || DBAL_IS_JR2_B0)
        {
            {
                table_db_access_params_struct_t * access_params;
                {
                    access_params = &cur_table_param->hl_access[map_idx].access[access_counter];
                    dbal_db_init_table_db_struct_hl_access_params_clear(access_params);
                    access_counter++;
                    access_params->access_field_id = DBAL_FIELD_STAT_DROP_REASON_RJCT_MASK;
                    access_params->access_type = DBAL_HL_ACCESS_REGISTER;
                    {
                        SHR_IF_ERR_EXIT(dbal_db_init_table_set_access_register_memory(unit, access_params, CGM_DROP_REASON_RJCT_MASKr, DROP_REASON_0_RJCT_MASKf));
                        access_params->data_offset.formula_cb = stat_rjct_filter_group_stat_drop_reason_rjct_mask_dataoffset_0_cb;
                    }
                }
                {
                    access_params = &cur_table_param->hl_access[map_idx].access[access_counter];
                    dbal_db_init_table_db_struct_hl_access_params_clear(access_params);
                    access_counter++;
                    access_params->access_field_id = DBAL_FIELD_STAT_DROP_REASON_RJCT_MASK;
                    access_params->access_type = DBAL_HL_ACCESS_REGISTER;
                    access_params->inst_idx = 1;
                    {
                        SHR_IF_ERR_EXIT(dbal_db_init_table_set_access_register_memory(unit, access_params, CGM_DROP_REASON_RJCT_MASKr, DROP_REASON_1_RJCT_MASKf));
                        access_params->data_offset.formula_cb = stat_rjct_filter_group_stat_drop_reason_rjct_mask_dataoffset_0_cb;
                    }
                }
                {
                    access_params = &cur_table_param->hl_access[map_idx].access[access_counter];
                    dbal_db_init_table_db_struct_hl_access_params_clear(access_params);
                    access_counter++;
                    access_params->access_field_id = DBAL_FIELD_STAT_DROP_REASON_RJCT_MASK;
                    access_params->access_type = DBAL_HL_ACCESS_REGISTER;
                    access_params->inst_idx = 2;
                    {
                        SHR_IF_ERR_EXIT(dbal_db_init_table_set_access_register_memory(unit, access_params, CGM_DROP_REASON_RJCT_MASKr, DROP_REASON_2_RJCT_MASKf));
                        access_params->data_offset.formula_cb = stat_rjct_filter_group_stat_drop_reason_rjct_mask_dataoffset_0_cb;
                    }
                }
                {
                    access_params = &cur_table_param->hl_access[map_idx].access[access_counter];
                    dbal_db_init_table_db_struct_hl_access_params_clear(access_params);
                    access_counter++;
                    access_params->access_field_id = DBAL_FIELD_STAT_DROP_REASON_RJCT_MASK;
                    access_params->access_type = DBAL_HL_ACCESS_REGISTER;
                    access_params->inst_idx = 3;
                    {
                        SHR_IF_ERR_EXIT(dbal_db_init_table_set_access_register_memory(unit, access_params, CGM_DROP_REASON_RJCT_MASKr, DROP_REASON_3_RJCT_MASKf));
                        access_params->data_offset.formula_cb = stat_rjct_filter_group_stat_drop_reason_rjct_mask_dataoffset_0_cb;
                    }
                }
                {
                    access_params = &cur_table_param->hl_access[map_idx].access[access_counter];
                    dbal_db_init_table_db_struct_hl_access_params_clear(access_params);
                    access_counter++;
                    access_params->access_field_id = DBAL_FIELD_STAT_DROP_REASON_RJCT_MASK;
                    access_params->access_type = DBAL_HL_ACCESS_REGISTER;
                    access_params->inst_idx = 4;
                    {
                        SHR_IF_ERR_EXIT(dbal_db_init_table_set_access_register_memory(unit, access_params, CGM_DROP_REASON_RJCT_MASKr, DROP_REASON_4_RJCT_MASKf));
                        access_params->data_offset.formula_cb = stat_rjct_filter_group_stat_drop_reason_rjct_mask_dataoffset_0_cb;
                    }
                }
                {
                    access_params = &cur_table_param->hl_access[map_idx].access[access_counter];
                    dbal_db_init_table_db_struct_hl_access_params_clear(access_params);
                    access_counter++;
                    access_params->access_field_id = DBAL_FIELD_STAT_DROP_REASON_RJCT_MASK;
                    access_params->access_type = DBAL_HL_ACCESS_REGISTER;
                    access_params->inst_idx = 5;
                    {
                        SHR_IF_ERR_EXIT(dbal_db_init_table_set_access_register_memory(unit, access_params, CGM_DROP_REASON_RJCT_MASKr, DROP_REASON_5_RJCT_MASKf));
                        access_params->data_offset.formula_cb = stat_rjct_filter_group_stat_drop_reason_rjct_mask_dataoffset_0_cb;
                    }
                }
                {
                    access_params = &cur_table_param->hl_access[map_idx].access[access_counter];
                    dbal_db_init_table_db_struct_hl_access_params_clear(access_params);
                    access_counter++;
                    access_params->access_field_id = DBAL_FIELD_STAT_DROP_REASON_RJCT_MASK;
                    access_params->access_type = DBAL_HL_ACCESS_REGISTER;
                    access_params->inst_idx = 6;
                    {
                        SHR_IF_ERR_EXIT(dbal_db_init_table_set_access_register_memory(unit, access_params, CGM_DROP_REASON_RJCT_MASKr, DROP_REASON_6_RJCT_MASKf));
                        access_params->data_offset.formula_cb = stat_rjct_filter_group_stat_drop_reason_rjct_mask_dataoffset_0_cb;
                    }
                }
                {
                    access_params = &cur_table_param->hl_access[map_idx].access[access_counter];
                    dbal_db_init_table_db_struct_hl_access_params_clear(access_params);
                    access_counter++;
                    access_params->access_field_id = DBAL_FIELD_STAT_DROP_REASON_RJCT_MASK;
                    access_params->access_type = DBAL_HL_ACCESS_REGISTER;
                    access_params->inst_idx = 7;
                    {
                        SHR_IF_ERR_EXIT(dbal_db_init_table_set_access_register_memory(unit, access_params, CGM_DROP_REASON_RJCT_MASKr, DROP_REASON_7_RJCT_MASKf));
                        access_params->data_offset.formula_cb = stat_rjct_filter_group_stat_drop_reason_rjct_mask_dataoffset_0_cb;
                    }
                }
            }
        }
        if (DBAL_IS_J2C_A0 || DBAL_IS_Q2A_A0 || DBAL_IS_Q2A_B0 || DBAL_IS_J2P_A0 || DBAL_IS_J2X_A0)
        {
            {
                table_db_access_params_struct_t * access_params;
                {
                    access_params = &cur_table_param->hl_access[map_idx].access[access_counter];
                    dbal_db_init_table_db_struct_hl_access_params_clear(access_params);
                    access_counter++;
                    access_params->access_field_id = DBAL_FIELD_STAT_DROP_REASON_RJCT_MASK;
                    access_params->access_type = DBAL_HL_ACCESS_REGISTER;
                    {
                        SHR_IF_ERR_EXIT(dbal_db_init_table_set_access_register_memory(unit, access_params, CGM_STAT_RJCT_REASON_RJCT_MASKr, STAT_RJCT_REASON_0_RJCT_MASKf));
                        access_params->data_offset.formula_cb = stat_rjct_filter_group_stat_drop_reason_rjct_mask_dataoffset_0_cb;
                    }
                }
                {
                    access_params = &cur_table_param->hl_access[map_idx].access[access_counter];
                    dbal_db_init_table_db_struct_hl_access_params_clear(access_params);
                    access_counter++;
                    access_params->access_field_id = DBAL_FIELD_STAT_DROP_REASON_RJCT_MASK;
                    access_params->access_type = DBAL_HL_ACCESS_REGISTER;
                    access_params->inst_idx = 1;
                    {
                        SHR_IF_ERR_EXIT(dbal_db_init_table_set_access_register_memory(unit, access_params, CGM_STAT_RJCT_REASON_RJCT_MASKr, STAT_RJCT_REASON_1_RJCT_MASKf));
                        access_params->data_offset.formula_cb = stat_rjct_filter_group_stat_drop_reason_rjct_mask_dataoffset_0_cb;
                    }
                }
                {
                    access_params = &cur_table_param->hl_access[map_idx].access[access_counter];
                    dbal_db_init_table_db_struct_hl_access_params_clear(access_params);
                    access_counter++;
                    access_params->access_field_id = DBAL_FIELD_STAT_DROP_REASON_RJCT_MASK;
                    access_params->access_type = DBAL_HL_ACCESS_REGISTER;
                    access_params->inst_idx = 2;
                    {
                        SHR_IF_ERR_EXIT(dbal_db_init_table_set_access_register_memory(unit, access_params, CGM_STAT_RJCT_REASON_RJCT_MASKr, STAT_RJCT_REASON_2_RJCT_MASKf));
                        access_params->data_offset.formula_cb = stat_rjct_filter_group_stat_drop_reason_rjct_mask_dataoffset_0_cb;
                    }
                }
                {
                    access_params = &cur_table_param->hl_access[map_idx].access[access_counter];
                    dbal_db_init_table_db_struct_hl_access_params_clear(access_params);
                    access_counter++;
                    access_params->access_field_id = DBAL_FIELD_STAT_DROP_REASON_RJCT_MASK;
                    access_params->access_type = DBAL_HL_ACCESS_REGISTER;
                    access_params->inst_idx = 3;
                    {
                        SHR_IF_ERR_EXIT(dbal_db_init_table_set_access_register_memory(unit, access_params, CGM_STAT_RJCT_REASON_RJCT_MASKr, STAT_RJCT_REASON_3_RJCT_MASKf));
                        access_params->data_offset.formula_cb = stat_rjct_filter_group_stat_drop_reason_rjct_mask_dataoffset_0_cb;
                    }
                }
                {
                    access_params = &cur_table_param->hl_access[map_idx].access[access_counter];
                    dbal_db_init_table_db_struct_hl_access_params_clear(access_params);
                    access_counter++;
                    access_params->access_field_id = DBAL_FIELD_STAT_DROP_REASON_RJCT_MASK;
                    access_params->access_type = DBAL_HL_ACCESS_REGISTER;
                    access_params->inst_idx = 4;
                    {
                        SHR_IF_ERR_EXIT(dbal_db_init_table_set_access_register_memory(unit, access_params, CGM_STAT_RJCT_REASON_RJCT_MASKr, STAT_RJCT_REASON_4_RJCT_MASKf));
                        access_params->data_offset.formula_cb = stat_rjct_filter_group_stat_drop_reason_rjct_mask_dataoffset_0_cb;
                    }
                }
                {
                    access_params = &cur_table_param->hl_access[map_idx].access[access_counter];
                    dbal_db_init_table_db_struct_hl_access_params_clear(access_params);
                    access_counter++;
                    access_params->access_field_id = DBAL_FIELD_STAT_DROP_REASON_RJCT_MASK;
                    access_params->access_type = DBAL_HL_ACCESS_REGISTER;
                    access_params->inst_idx = 5;
                    {
                        SHR_IF_ERR_EXIT(dbal_db_init_table_set_access_register_memory(unit, access_params, CGM_STAT_RJCT_REASON_RJCT_MASKr, STAT_RJCT_REASON_5_RJCT_MASKf));
                        access_params->data_offset.formula_cb = stat_rjct_filter_group_stat_drop_reason_rjct_mask_dataoffset_0_cb;
                    }
                }
                {
                    access_params = &cur_table_param->hl_access[map_idx].access[access_counter];
                    dbal_db_init_table_db_struct_hl_access_params_clear(access_params);
                    access_counter++;
                    access_params->access_field_id = DBAL_FIELD_STAT_DROP_REASON_RJCT_MASK;
                    access_params->access_type = DBAL_HL_ACCESS_REGISTER;
                    access_params->inst_idx = 6;
                    {
                        SHR_IF_ERR_EXIT(dbal_db_init_table_set_access_register_memory(unit, access_params, CGM_STAT_RJCT_REASON_RJCT_MASKr, STAT_RJCT_REASON_6_RJCT_MASKf));
                        access_params->data_offset.formula_cb = stat_rjct_filter_group_stat_drop_reason_rjct_mask_dataoffset_0_cb;
                    }
                }
                {
                    access_params = &cur_table_param->hl_access[map_idx].access[access_counter];
                    dbal_db_init_table_db_struct_hl_access_params_clear(access_params);
                    access_counter++;
                    access_params->access_field_id = DBAL_FIELD_STAT_DROP_REASON_RJCT_MASK;
                    access_params->access_type = DBAL_HL_ACCESS_REGISTER;
                    access_params->inst_idx = 7;
                    {
                        SHR_IF_ERR_EXIT(dbal_db_init_table_set_access_register_memory(unit, access_params, CGM_STAT_RJCT_REASON_RJCT_MASKr, STAT_RJCT_REASON_7_RJCT_MASKf));
                        access_params->data_offset.formula_cb = stat_rjct_filter_group_stat_drop_reason_rjct_mask_dataoffset_0_cb;
                    }
                }
            }
        }
        cur_table_param->hl_access[map_idx].nof_access = access_counter;
    }
    SHR_IF_ERR_EXIT(dbal_db_init_table_add(unit, cur_table_param, DBAL_TABLE_STAT_RJCT_FILTER_GROUP, table_info));
exit:
    SHR_FUNC_EXIT;
}

shr_error_e
dbal_init_tables_hard_logic_tm_hl_tm_stat_definition_init(
int unit,
table_db_struct_t * cur_table_param,
dbal_logical_table_t * table_info)
{
    SHR_FUNC_INIT_VARS(unit);
    SHR_IF_ERR_EXIT(_dbal_init_tables_hard_logic_tm_hl_tm_stat_definition_stat_rjct_filter_group_init(unit, cur_table_param, table_info));
exit:
    SHR_FUNC_EXIT;
}
