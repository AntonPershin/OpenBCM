/*
 * 
 *
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2022 Broadcom Inc. All rights reserved.
 *
 * RAMON DEFS H
 */
#include <shared/bsl.h>
#include <shared/utilex/utilex_bitstream.h>
#include <soc/dnxf/cmn/dnxf_diag.h>
#include <soc/dnxf/cmn/mbcm.h>
#include <sal/appl/io.h>
#include <soc/dnxc/error.h>
#include <soc/dnxf/cmn/dnxf_defs.h>
#include <soc/util.h>

#include <soc/dnxf/dnxf_data/auto_generated/dnxf_data.h>
#include <soc/dnxf/dnxf_data/auto_generated/dnxf_data_device.h>
#include <soc/dnxf/dnxf_data/auto_generated/dnxf_data_fabric.h>
#include <soc/dnxf/dnxf_data/auto_generated/dnxf_data_max_device.h>
#include <soc/dnxf/dnxf_data/auto_generated/dnxf_data_max_fabric.h>

#include <bcm/fabric.h>

#include <soc/dnxf/cmn/dnxf_diag.h>
#include <soc/dnxf/cmn/mbcm.h>
#include <soc/dnxf/cmn/dnxf_drv.h>
#include <soc/dnxf/ramon/ramon_cgm.h>
#include <soc/dnxf/ramon/ramon_diag.h>
#ifdef BSL_LOG_MODULE
#error "BSL_LOG_MODULE redefined"
#endif

#define BSL_LOG_MODULE BSL_LS_SOCDNX_DIAG

#define CCH_CONNECTIVITY_LINK_BIT_VALID             22
#define CCH_CONNECTIVITY_LINK_SOURCE_LVL_START_BIT  11
#define CCH_CONNECTIVITY_LINK_SOURCE_LVL_NOF_BITS   3
#define CCH_CONNECTIVITY_LINK_SOURCE_ID_MASK        0x7FF
#define CCH_CONNECTIVITY_LINK_SOURCE_DEVICE_STAR_BIT 14

void
soc_dnxf_counters_info_init(
    soc_dnxf_counters_info_t * fe_counters_info)
{
    int pipe_idx = 0, priority_idx;

    for (pipe_idx = 0; pipe_idx < DNXF_DATA_MAX_FABRIC_PIPES_MAX_NOF_PIPES; pipe_idx++)
    {
        fe_counters_info->dch_fe1_counters_info[pipe_idx].dch_total_in = 0;
        fe_counters_info->dch_fe1_counters_info[pipe_idx].dch_fifo_discard = 0;
        fe_counters_info->dch_fe1_counters_info[pipe_idx].dch_unreach_discard = 0;
        fe_counters_info->dch_fe1_counters_info[pipe_idx].dch_max_fifo_cells = 0;
        fe_counters_info->dch_fe1_counters_info[pipe_idx].dch_total_out = 0;

        fe_counters_info->dch_fe3_counters_info[pipe_idx].dch_total_in = 0;
        fe_counters_info->dch_fe3_counters_info[pipe_idx].dch_fifo_discard = 0;
        fe_counters_info->dch_fe3_counters_info[pipe_idx].dch_unreach_discard = 0;
        fe_counters_info->dch_fe3_counters_info[pipe_idx].dch_max_fifo_cells = 0;
        fe_counters_info->dch_fe3_counters_info[pipe_idx].dch_total_out = 0;

        fe_counters_info->dtm_fe1_counters_info[pipe_idx].dtm_total_in_nlr = 0;
        fe_counters_info->dtm_fe1_counters_info[pipe_idx].dtm_total_in_lr = 0;
        fe_counters_info->dtm_fe1_counters_info[pipe_idx].dtm_max_fifo_cells_nlr = 0;
        fe_counters_info->dtm_fe1_counters_info[pipe_idx].dtm_max_fifo_cells_lr = 0;
        fe_counters_info->dtm_fe1_counters_info[pipe_idx].dtm_total_out_nlr = 0;
        fe_counters_info->dtm_fe1_counters_info[pipe_idx].dtm_total_out_lr = 0;

        fe_counters_info->dtm_fe3_counters_info[pipe_idx].dtm_total_in_nlr = 0;
        fe_counters_info->dtm_fe3_counters_info[pipe_idx].dtm_total_in_lr = 0;
        fe_counters_info->dtm_fe3_counters_info[pipe_idx].dtm_max_fifo_cells_nlr = 0;
        fe_counters_info->dtm_fe3_counters_info[pipe_idx].dtm_max_fifo_cells_lr = 0;
        fe_counters_info->dtm_fe3_counters_info[pipe_idx].dtm_total_out_nlr = 0;
        fe_counters_info->dtm_fe3_counters_info[pipe_idx].dtm_total_out_lr = 0;

        fe_counters_info->dtl_fe1_counters_info[pipe_idx].dtl_total_in_lr = 0;
        fe_counters_info->dtl_fe1_counters_info[pipe_idx].dtl_total_in_nlr = 0;
        fe_counters_info->dtl_fe1_counters_info[pipe_idx].dtl_max_fifo_cells_lr = 0;
        fe_counters_info->dtl_fe1_counters_info[pipe_idx].dtl_max_fifo_cells_nlr = 0;
        fe_counters_info->dtl_fe3_counters_info[pipe_idx].dtl_total_in_lr = 0;
        fe_counters_info->dtl_fe3_counters_info[pipe_idx].dtl_total_in_nlr = 0;
        fe_counters_info->dtl_fe3_counters_info[pipe_idx].dtl_max_fifo_cells_lr = 0;
        fe_counters_info->dtl_fe3_counters_info[pipe_idx].dtl_max_fifo_cells_nlr = 0;
        for (priority_idx = 0; priority_idx < 4; priority_idx++)
        {
            fe_counters_info->dtl_fe1_counters_info[pipe_idx].dtl_total_dropped_lr_cells[priority_idx] = 0;
            fe_counters_info->dtl_fe1_counters_info[pipe_idx].dtl_total_dropped_nlr_cells[priority_idx] = 0;
            fe_counters_info->dtl_fe3_counters_info[pipe_idx].dtl_total_dropped_lr_cells[priority_idx] = 0;
            fe_counters_info->dtl_fe3_counters_info[pipe_idx].dtl_total_dropped_nlr_cells[priority_idx] = 0;
        }
        fe_counters_info->dtl_fe1_counters_info[pipe_idx].dtl_total_out = 0;
        fe_counters_info->dtl_fe3_counters_info[pipe_idx].dtl_total_out = 0;
    }

    fe_counters_info->nof_pipes = 0;

}

void
soc_dnxf_queues_info_init(
    int unit,
    soc_dnxf_queues_info_t * fe_queues_info)
{
    int pipe_idx, block_idx, dfl_bank_idx, link_group_idx, dtm_fifo_idx, sub_bank_idx;

    for (pipe_idx = 0; pipe_idx < DNXF_DATA_MAX_FABRIC_PIPES_MAX_NOF_PIPES; pipe_idx++)
    {
        for (block_idx = 0; block_idx < dnxf_data_device.blocks.nof_instances_dch_get(unit); block_idx++)
        {
            for (link_group_idx = 0; link_group_idx < dnxf_data_device.blocks.nof_dch_link_groups_get(unit);
                 link_group_idx++)
            {
                fe_queues_info->dch_queues_info[pipe_idx].nof_dch[block_idx].
                    dch_link_group[link_group_idx].most_occupied_link = 0;
                fe_queues_info->dch_queues_info[pipe_idx].nof_dch[block_idx].
                    dch_link_group[link_group_idx].max_occupancy_value = 0;
                fe_queues_info->dch_queues_info[pipe_idx].nof_dch[block_idx].
                    dch_link_group[link_group_idx].link_group_first_link = 0;
                fe_queues_info->dch_queues_info[pipe_idx].nof_dch[block_idx].
                    dch_link_group[link_group_idx].link_group_last_link = 0;
                SOC_PBMP_CLEAR(fe_queues_info->dch_queues_info[pipe_idx].
                               nof_dch[block_idx].dch_link_group[link_group_idx].link_group_links);
            }
        }

        for (block_idx = 0; block_idx < dnxf_data_device.blocks.nof_instances_dcml_get(unit); block_idx++)
        {
            for (dtm_fifo_idx = 0; dtm_fifo_idx < dnxf_data_device.blocks.nof_dtm_fifos_get(unit); dtm_fifo_idx++)
            {
                fe_queues_info->dtm_queues_info[pipe_idx].nof_dtm[block_idx].fifo_max_occupancy_value[dtm_fifo_idx] = 0;
            }
        }

        for (block_idx = 0; block_idx < dnxf_data_device.blocks.nof_instances_dcml_get(unit); block_idx++)
        {
            fe_queues_info->dtl_queues_info_nlr[pipe_idx].nof_dtl[block_idx].most_occupied_link = 0;
            fe_queues_info->dtl_queues_info_nlr[pipe_idx].nof_dtl[block_idx].max_occupancy_value = 0;
            fe_queues_info->dtl_queues_info_lr[pipe_idx].nof_dtl[block_idx].most_occupied_link = 0;
            fe_queues_info->dtl_queues_info_lr[pipe_idx].nof_dtl[block_idx].max_occupancy_value = 0;
            SOC_PBMP_CLEAR(fe_queues_info->dtl_queues_info_nlr[pipe_idx].nof_dtl[block_idx].link_group_links);
            SOC_PBMP_CLEAR(fe_queues_info->dtl_queues_info_lr[pipe_idx].nof_dtl[block_idx].link_group_links);
        }

    }

    for (block_idx = 0; block_idx < dnxf_data_device.blocks.nof_instances_dcml_get(unit); block_idx++)
    {
        for (dfl_bank_idx = 0; dfl_bank_idx < dnxf_data_fabric.congestion.nof_dfl_banks_get(unit); dfl_bank_idx++)
        {
            for (sub_bank_idx = 0; sub_bank_idx < dnxf_data_fabric.congestion.nof_dfl_sub_banks_get(unit);
                 sub_bank_idx++)
            {
                fe_queues_info->dfl_queues_info[block_idx].
                    nof_dfl[dfl_bank_idx].sub_bank_min_free_entries_value[sub_bank_idx] = 0;
            }
        }
    }

    fe_queues_info->nof_pipes = 0;

}

const soc_dnxf_diag_flag_str_t soc_dnxf_diag_flag_str_fabric_cell_snake_test_stages[] = {
    {SOC_DNXF_SNAKE_TEST_FAILURE_STAGE_REGISTER_CONFIG, "REGISTER_CONFIG"},
    {SOC_DNXF_SNAKE_TEST_FAILURE_STAGE_GET_OUT_OF_RESET, "GET_OUT_OF_RESET"},
    {SOC_DNXF_SNAKE_TEST_FAILURE_STAGE_DATA_CELL_GENERATION, "DATA_CELL_GENERATION"},
    {SOC_DNXF_SNAKE_TEST_FAILURE_STAGE_CONTROL_CELL_GENERATION, "CONTROL_CELL_GENERATION"},
    {SOC_DNXF_SNAKE_TEST_FAILURE_STAGE_DATA_CELL_FILTER_WRITE_COMMAND, "DATA_CELL_FILTER_WRITE_COMMAND"},
    {SOC_DNXF_SNAKE_TEST_FAILURE_STAGE_CONTROL_CELL_FILTER_WRITE_COMMAND, "CONTROL_CELL_FILTER_WRITE_COMMAND"},
    {SOC_DNXF_SNAKE_TEST_FAILURE_STAGE_DATA_CELL_FILTER_READ_COMMAND,
     "DATA_CELL_FILTER_READ_COMMAND (data cells drop occurred)"},
    {SOC_DNXF_SNAKE_TEST_FAILURE_STAGE_CONTROL_CELL_FILTER_READ_COMMAND,
     "CONTROL_CELL_FILTER_READ_COMMAND (control cells drop occurred)"},
    {0x0, NULL},
};

shr_error_e
soc_dnxf_diag_fabric_cell_snake_test_interrupts_name_get(
    int unit,
    const soc_dnxf_diag_flag_str_t ** intr_names)
{
    int rv;
    SHR_FUNC_INIT_VARS(unit);

    rv = MBCM_DNXF_DRIVER_CALL(unit, mbcm_dnxf_diag_fabric_cell_snake_test_interrupts_name_get, (unit, intr_names));
    SHR_IF_ERR_EXIT(rv);

exit:
    SHR_FUNC_EXIT;
}

shr_error_e
soc_dnxf_diag_cell_pipe_counter_get(
    int unit,
    int pipe,
    uint64 *counter)
{
    int rv;
    SHR_FUNC_INIT_VARS(unit);

    rv = MBCM_DNXF_DRIVER_CALL(unit, mbcm_dnxf_diag_cell_pipe_counter_get, (unit, pipe, counter));
    SHR_IF_ERR_EXIT(rv);

exit:
    SHR_FUNC_EXIT;
}

shr_error_e
soc_dnxf_diag_fabric_traffic_profile_get(
    int unit,
    int source_id,
    int dest_id,
    soc_dnxf_diag_fabric_traffic_profile_t * traffic_profile)
{
    soc_dnxc_filter_type_t filter_type_arr[5];
    uint32 filter_val[5];
    int priority, count;
    uint32 filter_count = 0;
    int rv;
    SHR_FUNC_INIT_VARS(unit);

    filter_type_arr[0] = soc_dnxc_filter_type_priority;
    filter_type_arr[1] = soc_dnxc_filter_type_traffic_cast;

    filter_count = 2;
    if (source_id != -1)
    {
        filter_type_arr[filter_count] = soc_dnxc_filter_type_source_id;
        filter_val[filter_count] = source_id;
        filter_count++;
    }
    if (dest_id != -1)
    {
        filter_type_arr[filter_count] = soc_dnxc_filter_type_dest_id;
        filter_val[filter_count] = dest_id;
        filter_count++;
    }

    filter_val[1] = 0;
    for (priority = 0; priority < soc_dnxf_fabric_priority_nof; priority++)
    {
        filter_val[0] = priority;
        rv = soc_dnxf_cell_filter_set(unit, SOC_CELL_FILTER_FLAG_DONT_TRAP, filter_count, filter_type_arr, filter_val);
        SHR_IF_ERR_EXIT(rv);
        sal_usleep(30000);

        rv = soc_dnxf_cell_filter_count_get(unit, &count);
        SHR_IF_ERR_EXIT(rv);

        sal_usleep(30000);

        rv = soc_dnxf_cell_filter_count_get(unit, &count);
        SHR_IF_ERR_EXIT(rv);

        traffic_profile->unicast[priority] = count ? 1 : 0;
    }

    filter_val[1] = 2;
    for (priority = 0; priority < soc_dnxf_fabric_priority_nof; priority++)
    {
        filter_val[0] = priority;
        rv = soc_dnxf_cell_filter_set(unit, SOC_CELL_FILTER_FLAG_DONT_TRAP, filter_count, filter_type_arr, filter_val);
        SHR_IF_ERR_EXIT(rv);
        sal_usleep(30000);

        rv = soc_dnxf_cell_filter_count_get(unit, &count);
        SHR_IF_ERR_EXIT(rv);

        sal_usleep(30000);

        rv = soc_dnxf_cell_filter_count_get(unit, &count);
        SHR_IF_ERR_EXIT(rv);

        traffic_profile->multicast[priority] = count ? 1 : 0;
    }

exit:
    SHR_FUNC_EXIT;
}

shr_error_e
soc_dnxf_diag_connectivity_status_reg_parse(
    int unit,
    uint32 reg_val,
    bcm_fabric_link_connectivity_t * link_partner)
{
    uint32 source_lvl;
    int link_mask;
    SHR_FUNC_INIT_VARS(unit);

    if (reg_val & (0x1 << CCH_CONNECTIVITY_LINK_BIT_VALID))
    {
        link_partner->module_id = reg_val & CCH_CONNECTIVITY_LINK_SOURCE_ID_MASK;

        SHR_IF_ERR_EXIT(utilex_bitstream_get_field
                        (&reg_val, CCH_CONNECTIVITY_LINK_SOURCE_LVL_START_BIT,
                         CCH_CONNECTIVITY_LINK_SOURCE_LVL_NOF_BITS, &source_lvl));

        switch (source_lvl)
        {
            case soc_dnxc_device_type_actual_value_FAP_1:
            case soc_dnxc_device_type_actual_value_FIP:
            case soc_dnxc_device_type_actual_value_FOP:
            case soc_dnxc_device_type_actual_value_FAP:
                link_partner->device_type = bcmFabricDeviceTypeFAP;
                break;
            case soc_dnxc_device_type_actual_value_FE3:
            case soc_dnxc_device_type_actual_value_FE1:
                link_partner->device_type = bcmFabricDeviceTypeFE13;
                break;
            case soc_dnxc_device_type_actual_value_FE2:
            case soc_dnxc_device_type_actual_value_FE2_1:
                link_partner->device_type = bcmFabricDeviceTypeFE2;
                break;
        }

        link_mask = dnxf_data_port.general.link_mask_get(unit);
        link_partner->link_id = (reg_val >> CCH_CONNECTIVITY_LINK_SOURCE_DEVICE_STAR_BIT) & link_mask;
    }
    else
    {
        link_partner->link_id = DNXC_FABRIC_LINK_NO_CONNECTIVITY;
    }

exit:
    SHR_FUNC_EXIT;
}

#undef BSL_LOG_MODULE
