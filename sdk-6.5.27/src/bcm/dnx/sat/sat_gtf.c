
/*
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2022 Broadcom Inc. All rights reserved.
 */
#ifdef BSL_LOG_MODULE
#error "BSL_LOG_MODULE redefined"
#endif
#define BSL_LOG_MODULE BSL_LS_BCMDNX_SAT

#include <soc/sand/shrextend/shrextend_debug.h>
#include <bcm/sat.h>
#include <soc/dnx/dbal/dbal.h>
#include <soc/dnx/dnx_err_recovery_manager.h>
#include <bcm/types.h>
#include <bcm_int/dnx/sat/sat.h>

#include <soc/memory.h>
#include <soc/feature.h>
#include <soc/types.h>
#include <soc/register.h>
#include <soc/dnx/swstate/auto_generated/access/sat_access.h>

#include <bcm_int/dnx/algo/swstate/auto_generated/access/algo_sat_access.h>

static shr_error_e dnx_sat_gtf_packet_header_config_clean(
    int unit,
    int pkt_header_base,
    int pkt_header_len);

static shr_error_e
dnx_sat_gtf_config_rate_get(
    int unit,
    bcm_sat_gtf_t gtf_id,
    uint32 *gtf_config_rate,
    uint32 *gtf_rate_compensation,
    int *packet_length_compensation)
{
    uint32 entry_handle_id;

    SHR_FUNC_INIT_VARS(unit);
    DBAL_FUNC_INIT_VARS(unit);

    SHR_IF_ERR_EXIT(DBAL_HANDLE_ALLOC(unit, DBAL_TABLE_SAT_TX_STAT_SW, &entry_handle_id));

    dbal_entry_key_field8_set(unit, entry_handle_id, DBAL_FIELD_TX_FLOW_ID, gtf_id);
    dbal_value_field32_request(unit, entry_handle_id, DBAL_FIELD_GTF_RATE_CMP, INST_SINGLE, gtf_rate_compensation);
    dbal_value_field32_request(unit, entry_handle_id, DBAL_FIELD_GTF_PKT_LEN_CMP, INST_SINGLE,
                               (uint32 *) packet_length_compensation);
    dbal_value_field32_request(unit, entry_handle_id, DBAL_FIELD_GTF_CONFIG_RATE, INST_SINGLE, gtf_config_rate);

    SHR_IF_ERR_EXIT(dbal_entry_get(unit, entry_handle_id, DBAL_COMMIT));
exit:
    DBAL_FUNC_FREE_VARS;
    SHR_FUNC_EXIT;
}

static shr_error_e
dnx_sat_gtf_is_paired_get(
    int unit,
    bcm_sat_gtf_t gtf_id,
    uint32 *is_paired)
{
    uint32 entry_handle_id;

    SHR_FUNC_INIT_VARS(unit);
    DBAL_FUNC_INIT_VARS(unit);

    *is_paired = 0;

    if (DNX_SAT_GTF_ID_IS_VALID_EVC_ID(gtf_id))
    {

        SHR_IF_ERR_EXIT(DBAL_HANDLE_ALLOC(unit, DBAL_TABLE_SAT_EVC_PAIR_CONFIG, &entry_handle_id));

        dbal_entry_key_field8_set(unit, entry_handle_id, DBAL_FIELD_EVC_ID, (gtf_id >> 1));

        dbal_value_field32_request(unit, entry_handle_id, DBAL_FIELD_EVC_PAIR_SET, INST_SINGLE, is_paired);

        SHR_IF_ERR_EXIT(dbal_entry_get(unit, entry_handle_id, DBAL_COMMIT));
    }

exit:
    DBAL_FUNC_FREE_VARS;
    SHR_FUNC_EXIT;
}

static shr_error_e
dnx_sat_gtf_is_paired_set(
    int unit,
    bcm_sat_gtf_t gtf_id,
    uint32 is_paired)
{
    uint32 entry_handle_id;

    SHR_FUNC_INIT_VARS(unit);
    DBAL_FUNC_INIT_VARS(unit);

    if (DNX_SAT_GTF_ID_IS_VALID_EVC_ID(gtf_id))
    {

        SHR_IF_ERR_EXIT(DBAL_HANDLE_ALLOC(unit, DBAL_TABLE_SAT_EVC_PAIR_CONFIG, &entry_handle_id));

        dbal_entry_key_field8_set(unit, entry_handle_id, DBAL_FIELD_EVC_ID, (gtf_id >> 1));

        dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_EVC_PAIR_SET, INST_SINGLE, is_paired);

        SHR_IF_ERR_EXIT(dbal_entry_commit(unit, entry_handle_id, DBAL_COMMIT));
    }

exit:
    DBAL_FUNC_FREE_VARS;
    SHR_FUNC_EXIT;
}

static shr_error_e
dnx_sat_gtf_id_priority_verify(
    int unit,
    bcm_sat_gtf_t gtf_id,
    int priority)
{
    uint8 is_allocated = 0;
    uint32 is_paired = 0;

    SHR_FUNC_INIT_VARS(unit);

    SHR_RANGE_VERIFY(gtf_id, DNX_SAT_GTF_ID_MIN, DNX_SAT_GTF_ID_MAX, _SHR_E_PARAM, "gtf_id");

    SHR_IF_ERR_EXIT(algo_sat_db.sat_res_alloc_gtf_id.is_allocated(unit, gtf_id, &is_allocated));

    if (!is_allocated)
    {
        SHR_ERR_EXIT(_SHR_E_NOT_FOUND, "Error: gtf_id  %d does not exist\n", gtf_id);
    }

    if (priority != bcmSatGtfPriCir)
    {
        if (DNX_SAT_GTF_ID_IS_VALID_EVC_ID(gtf_id))
        {
            SHR_IF_ERR_EXIT(dnx_sat_gtf_is_paired_get(unit, gtf_id, &is_paired));
        }

        if (!is_paired)
        {
            SHR_ERR_EXIT(_SHR_E_PARAM, "Error: gtf_id  %d is not paired\n", gtf_id);
        }

        SHR_IF_ERR_EXIT(algo_sat_db.sat_res_alloc_gtf_id.is_allocated(unit, gtf_id + 1, &is_allocated));

        if (!is_allocated)
        {
            SHR_ERR_EXIT(_SHR_E_NOT_FOUND, "Error: gtf_id  %d does not exist\n", gtf_id + 1);
        }
    }

exit:
    SHR_FUNC_EXIT;
}

shr_error_e
dnx_sat_gtf_config_rate_set(
    int unit,
    bcm_sat_gtf_t gtf_id,
    uint32 gtf_config_rate,
    uint32 gtf_rate_compensation,
    int packet_length_compensation)
{
    uint32 entry_handle_id;

    SHR_FUNC_INIT_VARS(unit);
    DBAL_FUNC_INIT_VARS(unit);

    SHR_IF_ERR_EXIT(DBAL_HANDLE_ALLOC(unit, DBAL_TABLE_SAT_TX_STAT_SW, &entry_handle_id));

    dbal_entry_key_field8_set(unit, entry_handle_id, DBAL_FIELD_TX_FLOW_ID, gtf_id);
    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_GTF_RATE_CMP, INST_SINGLE, gtf_rate_compensation);
    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_GTF_PKT_LEN_CMP, INST_SINGLE,
                                 (uint32) packet_length_compensation);
    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_GTF_CONFIG_RATE, INST_SINGLE, gtf_config_rate);

    SHR_IF_ERR_EXIT(dbal_entry_commit(unit, entry_handle_id, DBAL_COMMIT));
exit:
    DBAL_FUNC_FREE_VARS;
    SHR_FUNC_EXIT;
}

static shr_error_e
dnx_sat_gtf_create_verify(
    int unit,
    uint32 flags,
    bcm_sat_gtf_t * gtf_id)
{
    uint8 is_allocated = 0;
    int legal_flags = 0;

    SHR_FUNC_INIT_VARS(unit);
    SHR_NULL_CHECK(gtf_id, _SHR_E_PARAM, "gtf_id ");

    DNX_SAT_IS_SUPPORTED_CHECK(unit);

    legal_flags |= BCM_SAT_GTF_WITH_ID | BCM_SAT_GTF_ALLOC_PAIR;
    if (flags & ~legal_flags)
    {
        SHR_ERR_EXIT(_SHR_E_PARAM, "Error: unsupported flag combination\n");
    }

    if (flags & BCM_SAT_GTF_WITH_ID)
    {
        SHR_RANGE_VERIFY(*gtf_id, DNX_SAT_GTF_ID_MIN, DNX_SAT_GTF_ID_MAX, _SHR_E_PARAM, "gtf_id");
        SHR_IF_ERR_EXIT(algo_sat_db.sat_res_alloc_gtf_id.is_allocated(unit, *gtf_id, &is_allocated));

        if (flags & BCM_SAT_GTF_ALLOC_PAIR)
        {

            if (!DNX_SAT_GTF_ID_IS_VALID_EVC_ID(*gtf_id))
            {
                SHR_ERR_EXIT(_SHR_E_PARAM, "Error: invalid GTF ID\n");
            }

            if (!is_allocated)
            {
                SHR_IF_ERR_EXIT(algo_sat_db.sat_res_alloc_gtf_id.is_allocated(unit, *gtf_id + 1, &is_allocated));
            }
        }
    }

    if (is_allocated)
    {
        SHR_ERR_EXIT(_SHR_E_EXISTS, "Error: GTF with id %d exists\n", *gtf_id);
    }

exit:
    SHR_FUNC_EXIT;
}

shr_error_e
dnx_sat_gtf_create(
    int unit,
    uint32 flags,
    bcm_sat_gtf_t * gtf_id)
{
    uint32 entry_handle_id;
    uint32 packet_cnt_hw = 0;
    uint32 byte_cnt_hw[2] = { 0 };
    int is_eir;
    int is_paired = 0;

    SHR_FUNC_INIT_VARS(unit);
    DBAL_FUNC_INIT_VARS(unit);

    SHR_IF_ERR_EXIT(dnx_sat_gtf_id_allocate(unit, flags, gtf_id));

    if (flags & BCM_SAT_GTF_ALLOC_PAIR)
    {
        bcm_sat_gtf_t odd_gtf_id;

        is_paired = 1;

        flags |= BCM_SAT_GTF_WITH_ID;
        odd_gtf_id = *gtf_id + 1;

        SHR_IF_ERR_EXIT(dnx_sat_gtf_id_allocate(unit, flags, &odd_gtf_id));

        SHR_IF_ERR_EXIT(dnx_sat_gtf_is_paired_set(unit, *gtf_id, 1));
    }

    for (is_eir = 0; is_eir <= is_paired; ++is_eir)
    {

        SHR_IF_ERR_EXIT(DBAL_HANDLE_ALLOC(unit, DBAL_TABLE_SAT_TX_STAT_GET, &entry_handle_id));

        dbal_entry_key_field8_set(unit, entry_handle_id, DBAL_FIELD_TX_FLOW_ID, *gtf_id + is_eir);
        dbal_value_field32_request(unit, entry_handle_id, DBAL_FIELD_TX_PKT_COUNTERS, INST_SINGLE, &packet_cnt_hw);
        dbal_value_field_arr32_request(unit, entry_handle_id, DBAL_FIELD_TX_BYTE_COUNTERS, INST_SINGLE, byte_cnt_hw);
        SHR_IF_ERR_EXIT(dbal_entry_get(unit, entry_handle_id, DBAL_COMMIT));

        SHR_IF_ERR_EXIT(DBAL_HANDLE_CLEAR(unit, DBAL_TABLE_SAT_TX_STAT_SW, entry_handle_id));
        dbal_entry_key_field8_set(unit, entry_handle_id, DBAL_FIELD_TX_FLOW_ID, *gtf_id + is_eir);
        SHR_IF_ERR_EXIT(dbal_entry_clear(unit, entry_handle_id, DBAL_COMMIT));
    }

exit:
    DBAL_FUNC_FREE_VARS;
    SHR_FUNC_EXIT;
}

shr_error_e
bcm_dnx_sat_gtf_create(
    int unit,
    uint32 flags,
    bcm_sat_gtf_t * gtf_id)
{
    SHR_FUNC_INIT_VARS(unit);
    DNX_ERR_RECOVERY_START(unit);

    SHR_INVOKE_VERIFY_DNXC(dnx_sat_gtf_create_verify(unit, flags, gtf_id));
    LOG_VERBOSE(BSL_LS_BCM_SAT, ("%s %d: u(%d) flags(%d) gtf_id(%d)\n", BSL_FUNC, BSL_LINE, unit, flags, (*gtf_id)));

    SHR_IF_ERR_EXIT(dnx_sat_gtf_create(unit, flags, gtf_id));

exit:
    DNX_ERR_RECOVERY_END(unit);
    SHR_FUNC_EXIT;
}

static shr_error_e
dnx_sat_gtf_packet_gen_set(
    int unit,
    bcm_sat_gtf_t gtf_id,
    int enable)
{
    uint32 entry_handle_id;
    uint32 rate_pattern_mode = 0;

    SHR_FUNC_INIT_VARS(unit);
    DBAL_FUNC_INIT_VARS(unit);

    SHR_IF_ERR_EXIT(DBAL_HANDLE_ALLOC(unit, DBAL_TABLE_SAT_TX_RATE_CONTROL, &entry_handle_id));

    dbal_entry_key_field8_set(unit, entry_handle_id, DBAL_FIELD_TX_FLOW_ID, gtf_id);

    dbal_value_field32_request(unit, entry_handle_id, DBAL_FIELD_BURST_MODE, INST_SINGLE, &rate_pattern_mode);

    SHR_IF_ERR_EXIT(dbal_entry_get(unit, entry_handle_id, DBAL_COMMIT));

    SHR_IF_ERR_EXIT(DBAL_HANDLE_ALLOC(unit, DBAL_TABLE_SAT_TX_ENABLE, &entry_handle_id));

    dbal_entry_key_field8_set(unit, entry_handle_id, DBAL_FIELD_TX_FLOW_ID, gtf_id);

    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_PKT_GEN_ENABLE, INST_SINGLE, enable);

    SHR_IF_ERR_EXIT(dbal_entry_commit(unit, entry_handle_id, DBAL_COMMIT));

    if (rate_pattern_mode == 1)
    {

        SHR_IF_ERR_EXIT(DBAL_HANDLE_ALLOC(unit, DBAL_TABLE_SAT_TX_RATE_CONTROL, &entry_handle_id));

        dbal_entry_key_field8_set(unit, entry_handle_id, DBAL_FIELD_TX_FLOW_ID, gtf_id);

        dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_STOP_ITER_CNT_RESET, INST_SINGLE, 1);

        SHR_IF_ERR_EXIT(dbal_entry_commit(unit, entry_handle_id, DBAL_COMMIT));

        SHR_IF_ERR_EXIT(DBAL_HANDLE_ALLOC(unit, DBAL_TABLE_SAT_TX_RATE_CONTROL, &entry_handle_id));

        dbal_entry_key_field8_set(unit, entry_handle_id, DBAL_FIELD_TX_FLOW_ID, gtf_id);

        dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_STOP_ITER_CNT_RESET, INST_SINGLE, 0);

        SHR_IF_ERR_EXIT(dbal_entry_commit(unit, entry_handle_id, DBAL_COMMIT));
    }

exit:
    DBAL_FUNC_FREE_VARS;
    SHR_FUNC_EXIT;
}

shr_error_e
dnx_sat_reset_timer_config(
    int unit)
{
    uint32 freq_hz = 0;
    uint32 clocks_per_cycle = 0;
    uint32 entry_handle_id;
    SHR_FUNC_INIT_VARS(unit);
    DBAL_FUNC_INIT_VARS(unit);

    freq_hz = dnx_data_device.general.core_clock_khz_get(unit) * 1000;
    clocks_per_cycle = (freq_hz / (DNX_DATA_MAX_SAT_GENERAL_GRANULARITY / DNX_SAT_BITS_PER_BYTE));
    if (clocks_per_cycle == 0)
    {
        SHR_ERR_EXIT(_SHR_E_INTERNAL, " Frequency is error \n");
    }
    SHR_IF_ERR_EXIT(DBAL_HANDLE_ALLOC(unit, DBAL_TABLE_SAT_TIMER_CONFIG, &entry_handle_id));
    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_NUM_CLKS_IN_CYCLE, INST_SINGLE, clocks_per_cycle);
    SHR_IF_ERR_EXIT(dbal_entry_commit(unit, entry_handle_id, DBAL_COMMIT));
exit:
    DBAL_FUNC_FREE_VARS;
    SHR_FUNC_EXIT;
}

static shr_error_e
dnx_sat_gtf_destroy_verify(
    int unit,
    bcm_sat_gtf_t gtf_id)
{
    uint8 is_allocated = 0;

    SHR_FUNC_INIT_VARS(unit);
    SHR_RANGE_VERIFY(gtf_id, DNX_SAT_GTF_ID_MIN, DNX_SAT_GTF_ID_MAX, _SHR_E_PARAM, "gtf_id");

    DNX_SAT_IS_SUPPORTED_CHECK(unit);

    SHR_IF_ERR_EXIT(algo_sat_db.sat_res_alloc_gtf_id.is_allocated(unit, gtf_id, &is_allocated));

    if (!is_allocated)
    {
        SHR_ERR_EXIT(_SHR_E_NOT_FOUND, "Error: gtf_id  %d does not exist\n", gtf_id);
    }

exit:
    SHR_FUNC_EXIT;
}

shr_error_e
dnx_sat_gtf_destroy(
    int unit,
    bcm_sat_gtf_t gtf_id)
{
    int pkt_gen_en = 0;
    dnx_sat_data_t psat_data;
    dnx_sat_gtf_pkt_hdr_tbl_info_t header_tbl_data;
    int old_profile = 0;
    int new_profile = 0;
    int is_allocated = 0;
    int is_last = 0;
    int nof_allocate_gtf = 0;
    uint32 pkt_header_len = 0;

    SHR_FUNC_INIT_VARS(unit);

    SHR_INVOKE_VERIFY_DNXC(dnx_sat_gtf_destroy_verify(unit, gtf_id));

    LOG_VERBOSE(BSL_LS_BCM_SAT, ("%s %d: u(%d) gtf_id(%d)\n", BSL_FUNC, BSL_LINE, unit, gtf_id));

    pkt_gen_en = 0;
    SHR_IF_ERR_EXIT(dnx_sat_gtf_packet_gen_set(unit, gtf_id, pkt_gen_en));

    sal_memset(&psat_data, 0, sizeof(dnx_sat_data_t));
    SHR_IF_ERR_EXIT(dnx_sat_data_get(unit, &psat_data));

    old_profile = psat_data.gtf_header_id[gtf_id];

    psat_data.gtf_header_id[gtf_id] = 0;

    sal_memset(&header_tbl_data, 0, sizeof(header_tbl_data));

    SHR_IF_ERR_EXIT(dnx_am_template_sat_pkt_header_length_get(unit, old_profile, &pkt_header_len));

    SHR_IF_ERR_EXIT(dnx_am_template_sat_pkt_header_exchange
                    (unit, 0, &header_tbl_data, old_profile, &is_last, &new_profile, &is_allocated));
    psat_data.gtf_header_id[gtf_id] = new_profile;

    if (is_last)
    {
        uint16 old_pkt_header_base = 0;

        SHR_IF_ERR_EXIT(sat_pkt_header_info.pkt_header_base.get(unit, old_profile, &old_pkt_header_base));

        SHR_IF_ERR_EXIT(dnx_sat_gtf_packet_header_config_clean(unit, old_pkt_header_base, pkt_header_len));

        SHR_IF_ERR_EXIT(dnx_sat_pkt_header_mem_free(unit, (pkt_header_len + 4) / 4, old_pkt_header_base));

        SHR_IF_ERR_EXIT(sat_pkt_header_info.pkt_header_base.set(unit, old_profile, 0));
    }

    SHR_IF_ERR_EXIT(dnx_sat_gtf_id_free(unit, gtf_id));
    SHR_IF_ERR_EXIT(algo_sat_db.sat_res_alloc_gtf_id.nof_allocated_elements_in_range_get(unit, 0, DNX_SAT_GTF_ID_MAX,
                                                                                         &nof_allocate_gtf));
    if (nof_allocate_gtf == 0)
    {

        psat_data.rate_mode = 0;

        psat_data.granularity_flag = 0;
        dnx_sat_reset_timer_config(unit);
    }

    SHR_IF_ERR_EXIT(dnx_sat_data_set(unit, &psat_data));
exit:
    SHR_FUNC_EXIT;
}

shr_error_e
bcm_dnx_sat_gtf_destroy(
    int unit,
    bcm_sat_gtf_t gtf_id)
{
    uint32 is_paired = 0;

    SHR_FUNC_INIT_VARS(unit);
    DNX_ERR_RECOVERY_START(unit);

    SHR_INVOKE_VERIFY_DNXC(dnx_sat_gtf_destroy_verify(unit, gtf_id));

    LOG_VERBOSE(BSL_LS_BCM_SAT, ("%s %d: u(%d) gtf_id(%d)\n", BSL_FUNC, BSL_LINE, unit, gtf_id));

    if (DNX_SAT_GTF_ID_IS_VALID_EVC_ID(gtf_id))
    {
        SHR_IF_ERR_EXIT(dnx_sat_gtf_is_paired_get(unit, gtf_id, &is_paired));
    }

    if (is_paired)
    {

        SHR_INVOKE_VERIFY_DNXC(dnx_sat_gtf_destroy_verify(unit, gtf_id + 1));
        SHR_IF_ERR_EXIT(dnx_sat_gtf_destroy(unit, gtf_id + 1));
    }

    SHR_IF_ERR_EXIT(dnx_sat_gtf_destroy(unit, gtf_id));

    if (is_paired)
    {

        SHR_IF_ERR_EXIT(dnx_sat_gtf_is_paired_set(unit, gtf_id, 0));
    }

exit:
    DNX_ERR_RECOVERY_END(unit);
    SHR_FUNC_EXIT;
}

shr_error_e
bcm_dnx_sat_gtf_destroy_all(
    int unit)
{
    int pkt_gen_en = 0;
    dnx_sat_data_t psat_data;
    bcm_sat_gtf_t gtf_id;
    int is_last = 0;
    dnx_sat_gtf_pkt_hdr_tbl_info_t header_tbl_data;
    int old_profile = 0;
    int new_profile = 0;
    int is_header_id_allocated = 0;
    uint8 is_gtf_allocated = 0;
    uint16 old_pkt_header_base = 0;
    uint32 pkt_header_len = 0;

    SHR_FUNC_INIT_VARS(unit);
    DNX_ERR_RECOVERY_START(unit);

    DNX_SAT_IS_SUPPORTED_CHECK(unit);

    LOG_VERBOSE(BSL_LS_BCM_SAT, ("%s %d: u(%d)\n", BSL_FUNC, BSL_LINE, unit));
    sal_memset(&psat_data, 0, sizeof(dnx_sat_data_t));
    SHR_IF_ERR_EXIT(dnx_sat_data_get(unit, &psat_data));

    pkt_gen_en = 0;
    for (gtf_id = DNX_SAT_GTF_ID_MIN; gtf_id <= DNX_SAT_GTF_ID_MAX; gtf_id++)
    {

        SHR_IF_ERR_EXIT(algo_sat_db.sat_res_alloc_gtf_id.is_allocated(unit, gtf_id, &is_gtf_allocated));
        if (is_gtf_allocated)
        {

            SHR_IF_ERR_EXIT(dnx_sat_gtf_packet_gen_set(unit, gtf_id, pkt_gen_en));

            old_profile = psat_data.gtf_header_id[gtf_id];

            SHR_IF_ERR_EXIT(sat_pkt_header_info.pkt_header_base.get(unit, old_profile, &old_pkt_header_base));

            SHR_IF_ERR_EXIT(dnx_am_template_sat_pkt_header_length_get(unit, old_profile, &pkt_header_len));

            sal_memset(&header_tbl_data, 0, sizeof(header_tbl_data));
            SHR_IF_ERR_EXIT(dnx_am_template_sat_pkt_header_exchange
                            (unit, 0, &header_tbl_data, old_profile, &is_last, &new_profile, &is_header_id_allocated));
            psat_data.gtf_header_id[gtf_id] = new_profile;

            if (is_last)
            {

                SHR_IF_ERR_EXIT(dnx_sat_gtf_packet_header_config_clean(unit, old_pkt_header_base, pkt_header_len));

                SHR_IF_ERR_EXIT(dnx_sat_pkt_header_mem_free(unit, (pkt_header_len + 4) / 4, old_pkt_header_base));

                SHR_IF_ERR_EXIT(sat_pkt_header_info.pkt_header_base.set(unit, old_profile, 0));
            }
            SHR_IF_ERR_EXIT(dnx_sat_gtf_id_free(unit, gtf_id));
        }
    }

    psat_data.rate_mode = 0;

    psat_data.granularity_flag = 0;
    SHR_IF_ERR_EXIT(dnx_sat_data_set(unit, &psat_data));
    dnx_sat_reset_timer_config(unit);

exit:
    DNX_ERR_RECOVERY_END(unit);
    SHR_FUNC_EXIT;
}

static shr_error_e
dnx_sat_gtf_rate_from_internal_rate_convert(
    int unit,
    uint32 rate_mnt_val,
    uint32 rate_exp_val,
    uint32 flags,
    uint32 *rate)
{
    uint32 entry_handle_id;
    uint32 bytes_per_cycle = 0;
    uint32 cycles_per_sec = 0;
    uint32 clocks_per_sec = 0;
    uint32 clocks_per_cycle = 0;
    uint64 rate64bits;
    uint32 rate_div;

    SHR_FUNC_INIT_VARS(unit);
    DBAL_FUNC_INIT_VARS(unit);

    if (rate == NULL)
    {
        SHR_IF_ERR_EXIT(_SHR_E_PARAM);
    }

    SHR_IF_ERR_EXIT(DBAL_HANDLE_ALLOC(unit, DBAL_TABLE_SAT_TIMER_CONFIG, &entry_handle_id));
    dbal_value_field32_request(unit, entry_handle_id, DBAL_FIELD_NUM_CLOCKS_SEC, INST_SINGLE, &clocks_per_sec);
    dbal_value_field32_request(unit, entry_handle_id, DBAL_FIELD_NUM_CLKS_IN_CYCLE, INST_SINGLE, &clocks_per_cycle);
    SHR_IF_ERR_EXIT(dbal_entry_get(unit, entry_handle_id, DBAL_COMMIT));
    if (clocks_per_cycle != 0)
    {
        cycles_per_sec = clocks_per_sec / clocks_per_cycle;
    }
    else
    {
        SHR_ERR_EXIT(_SHR_E_INTERNAL, " Frequency is error \n");
    }

    SHR_IF_ERR_EXIT(utilex_compute_complex_to_mnt_exp(rate_mnt_val, rate_exp_val, 1, 0, &bytes_per_cycle));

    if (flags)
    {
        *rate = bytes_per_cycle;
    }
    else
    {

        rate_div = 125;
        COMPILER_64_ZERO(rate64bits);
        COMPILER_64_ADD_32(rate64bits, bytes_per_cycle);
        COMPILER_64_UMUL_32(rate64bits, cycles_per_sec);
        COMPILER_64_UDIV_32(rate64bits, rate_div);
        *rate = COMPILER_64_LO(rate64bits);
    }
    SHR_IF_ERR_EXIT(_SHR_E_NONE);

exit:
    DBAL_FUNC_FREE_VARS;
    SHR_FUNC_EXIT;
}

static shr_error_e
dnx_sat_gtf_rate_to_internal_rate_convert(
    int unit,
    uint32 rate,
    uint32 flags,
    uint32 mnt_nof_bits,
    uint32 exp_nof_bits,
    uint32 granularity,
    uint32 *rate_mnt_val,
    uint32 *rate_exp_val)
{
    uint32 entry_handle_id;
    uint32 bytes_per_cycle = 0;
    uint32 clocks_per_sec = 0;
    uint32 clocks_per_cycle = 0;
    uint32 old_clocks_per_cycle = 0;
    int nof_allocate_gtf = 0;
    uint64 rate64bits;

    SHR_FUNC_INIT_VARS(unit);
    DBAL_FUNC_INIT_VARS(unit);

    SHR_NULL_CHECK(rate_mnt_val, _SHR_E_PARAM, "rate_mnt_val ");
    SHR_NULL_CHECK(rate_exp_val, _SHR_E_PARAM, "rate_exp_val ");

    COMPILER_64_ZERO(rate64bits);

    if ((flags & BCM_SAT_GTF_RATE_WITH_GRANULARITY) && (granularity == 0))
    {
        SHR_ERR_EXIT(_SHR_E_PARAM, "Parameter granularity can't be zero \n");
    }

    SHR_IF_ERR_EXIT(DBAL_HANDLE_ALLOC(unit, DBAL_TABLE_SAT_TIMER_CONFIG, &entry_handle_id));
    dbal_value_field32_request(unit, entry_handle_id, DBAL_FIELD_NUM_CLOCKS_SEC, INST_SINGLE, &clocks_per_sec);
    dbal_value_field32_request(unit, entry_handle_id, DBAL_FIELD_NUM_CLKS_IN_CYCLE, INST_SINGLE, &clocks_per_cycle);
    SHR_IF_ERR_EXIT(dbal_entry_get(unit, entry_handle_id, DBAL_COMMIT));
    old_clocks_per_cycle = clocks_per_cycle;

    if (!(flags & BCM_SAT_GTF_RATE_WITH_GRANULARITY) && clocks_per_sec && clocks_per_cycle)
    {
        granularity = clocks_per_sec / clocks_per_cycle;
    }

    if (granularity == 0)
    {
        SHR_ERR_EXIT(_SHR_E_PARAM, " parameter error !!! \n");
    }

    if (flags & BCM_SAT_GTF_RATE_IN_PACKETS)
    {
        if (flags & BCM_SAT_GTF_RATE_WITH_GRANULARITY)
        {
            clocks_per_cycle = clocks_per_sec / granularity;
            bytes_per_cycle = rate / granularity;
        }
        else
        {
            clocks_per_cycle = clocks_per_sec;
            bytes_per_cycle = rate;
        }
    }
    else
    {

        COMPILER_64_SET(rate64bits, 0, rate);
        COMPILER_64_UMUL_32(rate64bits, 125);
        COMPILER_64_UDIV_32(rate64bits, granularity);
        bytes_per_cycle = COMPILER_64_LO(rate64bits);
        clocks_per_cycle = clocks_per_sec / granularity;
    }

    if (old_clocks_per_cycle != clocks_per_cycle)
    {
        SHR_IF_ERR_EXIT(algo_sat_db.
                        sat_res_alloc_gtf_id.nof_allocated_elements_in_range_get(unit, 0, DNX_SAT_GTF_ID_MAX,
                                                                                 &nof_allocate_gtf));
        if (nof_allocate_gtf > 1)
        {
            SHR_ERR_EXIT(BCM_E_PARAM, "Fail(%s), more than one gtf inuse, granularity can't changed.\n",
                         soc_errmsg(BCM_E_PARAM));
        }
        SHR_IF_ERR_EXIT(DBAL_HANDLE_ALLOC(unit, DBAL_TABLE_SAT_TIMER_CONFIG, &entry_handle_id));
        dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_NUM_CLKS_IN_CYCLE, INST_SINGLE,
                                     clocks_per_cycle);
        SHR_IF_ERR_EXIT(dbal_entry_commit(unit, entry_handle_id, DBAL_COMMIT));
    }

    SHR_IF_ERR_EXIT(utilex_break_to_mnt_exp_round_up
                    (bytes_per_cycle, mnt_nof_bits, exp_nof_bits, 0, rate_mnt_val, rate_exp_val));

exit:
    DBAL_FUNC_FREE_VARS;
    SHR_FUNC_EXIT;
}

static shr_error_e
dnx_sat_gtf_bandwidth_get(
    int unit,
    bcm_sat_gtf_t gtf_id,
    int priority,
    bcm_sat_gtf_bandwidth_t * bw)
{
    dbal_tables_e table_id;
    dbal_fields_e key_field_id;
    int key_value;
    uint32 entry_handle_id;
    uint32 rate_mnt_val = 0, rate_exp_val = 0;
    uint32 burst_mnt_val = 0, burst_exp_val = 0;
    uint32 crdt_per_pkt = 0;
    uint32 complex = 0;
    uint32 clocks_per_sec, clocks_per_cycle;

    SHR_FUNC_INIT_VARS(unit);
    DBAL_FUNC_INIT_VARS(unit);

    table_id =
        (priority == bcmSatGtfPriAll) ? DBAL_TABLE_SAT_EVC_TX_BANDWIDTH_CONTROL : DBAL_TABLE_SAT_TX_BANDWIDTH_CONTROL;
    key_field_id = (priority == bcmSatGtfPriAll) ? DBAL_FIELD_EVC_ID : DBAL_FIELD_TX_FLOW_ID;
    key_value = (priority == bcmSatGtfPriAll) ? (gtf_id >> 1) : gtf_id;

    SHR_IF_ERR_EXIT(DBAL_HANDLE_ALLOC(unit, table_id, &entry_handle_id));

    dbal_entry_key_field8_set(unit, entry_handle_id, key_field_id, key_value);

    dbal_value_field32_request(unit, entry_handle_id, DBAL_FIELD_BYTES_PER_CYCLE_MANTISSA, INST_SINGLE, &rate_mnt_val);
    dbal_value_field32_request(unit, entry_handle_id, DBAL_FIELD_BYTES_PER_CYCLE_EXPONENT, INST_SINGLE, &rate_exp_val);
    dbal_value_field32_request(unit, entry_handle_id, DBAL_FIELD_MAX_CREDITS_MANTISSA, INST_SINGLE, &burst_mnt_val);
    dbal_value_field32_request(unit, entry_handle_id, DBAL_FIELD_MAX_CREDITS_EXPONENT, INST_SINGLE, &burst_exp_val);
    dbal_value_field32_request(unit, entry_handle_id, DBAL_FIELD_CREDITS_PER_PACKET_EN, INST_SINGLE, &crdt_per_pkt);

    SHR_IF_ERR_EXIT(dbal_entry_get(unit, entry_handle_id, DBAL_COMMIT));

    bw->flags = crdt_per_pkt ? BCM_SAT_GTF_RATE_IN_PACKETS : BCM_SAT_GTF_RATE_IN_BYTES;

    SHR_IF_ERR_EXIT(DBAL_HANDLE_ALLOC(unit, DBAL_TABLE_SAT_TIMER_CONFIG, &entry_handle_id));
    dbal_value_field32_request(unit, entry_handle_id, DBAL_FIELD_NUM_CLOCKS_SEC, INST_SINGLE, &clocks_per_sec);
    dbal_value_field32_request(unit, entry_handle_id, DBAL_FIELD_NUM_CLKS_IN_CYCLE, INST_SINGLE, &clocks_per_cycle);
    SHR_IF_ERR_EXIT(dbal_entry_get(unit, entry_handle_id, DBAL_COMMIT));

    if ((clocks_per_sec / clocks_per_cycle) != DNX_DATA_MAX_SAT_GENERAL_GRANULARITY)
    {
        bw->flags |= BCM_SAT_GTF_RATE_WITH_GRANULARITY;

        bw->granularity = clocks_per_sec / clocks_per_cycle;
    }

    SHR_IF_ERR_EXIT(dnx_sat_gtf_rate_from_internal_rate_convert
                    (unit, rate_mnt_val, rate_exp_val, crdt_per_pkt, &(bw->rate)));

    SHR_IF_ERR_EXIT(utilex_compute_complex_to_mnt_exp(burst_mnt_val, burst_exp_val, 1, 0, &complex));

    bw->max_burst = (crdt_per_pkt) ? complex : (complex / 125);

    SHR_EXIT();

exit:
    DBAL_FUNC_FREE_VARS;
    SHR_FUNC_EXIT;
}

shr_error_e
bcm_dnx_sat_gtf_bandwidth_get(
    int unit,
    bcm_sat_gtf_t gtf_id,
    int priority,
    bcm_sat_gtf_bandwidth_t * bw)
{
    bcm_sat_gtf_bandwidth_t dnx_bandwidth;
    uint32 gtf_config_rate, gtf_rate_factor;
    int packet_length_compensation;
    bcm_sat_gtf_t gtf_to_get = gtf_id;
    uint32 is_paired = 0;

    SHR_FUNC_INIT_VARS(unit);
    DNX_ERR_RECOVERY_START(unit);

    DNX_SAT_IS_SUPPORTED_CHECK(unit);

    LOG_VERBOSE(BSL_LS_BCM_SAT, ("%s %d: u(%d) gtf_id(%d) priority(%d) \n", BSL_FUNC, BSL_LINE,
                                 unit, gtf_id, priority));

    if (DNX_SAT_GTF_ID_IS_VALID_EVC_ID(gtf_id))
    {
        SHR_IF_ERR_EXIT(dnx_sat_gtf_is_paired_get(unit, gtf_id, &is_paired));
    }

    if (!is_paired && (priority != bcmSatGtfPriCir))
    {
        LOG_WARN(BSL_LS_BCM_SAT, ("GTF is not paired but priority is not CIR, ignore priority\n"));
        priority = bcmSatGtfPriCir;
    }

    SHR_INVOKE_VERIFY_DNXC(dnx_sat_gtf_id_priority_verify(unit, gtf_id, priority));
    SHR_NULL_CHECK(bw, _SHR_E_PARAM, "bw");

    if (priority == bcmSatGtfPriEir)
    {
        gtf_to_get += 1;
    }

    sal_memset(&dnx_bandwidth, 0, sizeof(dnx_bandwidth));
    SHR_IF_ERR_EXIT(dnx_sat_gtf_bandwidth_get(unit, gtf_to_get, priority, &dnx_bandwidth));

    SHR_IF_ERR_EXIT(dnx_sat_gtf_config_rate_get
                    (unit, gtf_to_get, &gtf_config_rate, &gtf_rate_factor, &packet_length_compensation));

    bw->rate = gtf_config_rate;
    bw->max_burst = dnx_bandwidth.max_burst;
    bw->flags = dnx_bandwidth.flags;
    bw->granularity = dnx_bandwidth.granularity;

    SHR_IF_ERR_EXIT(_SHR_E_NONE);

exit:
    DNX_ERR_RECOVERY_END(unit);
    SHR_FUNC_EXIT;
}

static shr_error_e
dnx_sat_gtf_bandwidth_set(
    int unit,
    bcm_sat_gtf_t gtf_id,
    int priority,
    bcm_sat_gtf_bandwidth_t * bw,
    uint32 gtf_rate_factor)
{
    dbal_tables_e table_id;
    dbal_fields_e key_field_id;
    int key_value;
    uint32 entry_handle_id;
    uint32 mnt_nof_bits = 0, exp_nof_bits = 0;
    uint32 rate_mnt_val = 0, rate_exp_val = 0;
    uint32 burst_mnt_val = 0, burst_exp_val = 0;
    uint32 max_rate;

    SHR_FUNC_INIT_VARS(unit);
    DBAL_FUNC_INIT_VARS(unit);

    if (!(bw->flags & BCM_SAT_GTF_RATE_IN_PACKETS) && gtf_rate_factor)
    {

        max_rate = bw->rate * (gtf_rate_factor / DNX_SAT_GTF_RATE_CMP_CONVERSION);
    }
    else
    {
        max_rate = bw->rate;
    }

    SHR_IF_ERR_EXIT(dbal_tables_field_size_get
                    (unit, DBAL_TABLE_SAT_TX_BANDWIDTH_CONTROL, DBAL_FIELD_BYTES_PER_CYCLE_MANTISSA, FALSE, 0, 0,
                     (int *) (&mnt_nof_bits)));
    SHR_IF_ERR_EXIT(dbal_tables_field_size_get
                    (unit, DBAL_TABLE_SAT_TX_BANDWIDTH_CONTROL, DBAL_FIELD_BYTES_PER_CYCLE_EXPONENT, FALSE, 0, 0,
                     (int *) (&exp_nof_bits)));

    SHR_IF_ERR_EXIT(dnx_sat_gtf_rate_to_internal_rate_convert
                    (unit, max_rate, bw->flags, mnt_nof_bits, exp_nof_bits, bw->granularity, &rate_mnt_val,
                     &rate_exp_val));

    SHR_IF_ERR_EXIT(dbal_tables_field_size_get
                    (unit, DBAL_TABLE_SAT_TX_BANDWIDTH_CONTROL, DBAL_FIELD_MAX_CREDITS_MANTISSA, FALSE, 0, 0,
                     (int *) (&mnt_nof_bits)));
    SHR_IF_ERR_EXIT(dbal_tables_field_size_get
                    (unit, DBAL_TABLE_SAT_TX_BANDWIDTH_CONTROL, DBAL_FIELD_MAX_CREDITS_EXPONENT, FALSE, 0, 0,
                     (int *) (&exp_nof_bits)));
    if (bw->flags & BCM_SAT_GTF_RATE_IN_PACKETS)
    {
        SHR_IF_ERR_EXIT(utilex_break_to_mnt_exp_round_up
                        (bw->max_burst, mnt_nof_bits, exp_nof_bits, 0, &burst_mnt_val, &burst_exp_val));
    }
    else
    {
        SHR_IF_ERR_EXIT(utilex_break_to_mnt_exp_round_up
                        (bw->max_burst * 125, mnt_nof_bits, exp_nof_bits, 0, &burst_mnt_val, &burst_exp_val));
    }

    table_id =
        (priority == bcmSatGtfPriAll) ? DBAL_TABLE_SAT_EVC_TX_BANDWIDTH_CONTROL : DBAL_TABLE_SAT_TX_BANDWIDTH_CONTROL;
    key_field_id = (priority == bcmSatGtfPriAll) ? DBAL_FIELD_EVC_ID : DBAL_FIELD_TX_FLOW_ID;
    key_value = (priority == bcmSatGtfPriAll) ? (gtf_id >> 1) : gtf_id;

    SHR_IF_ERR_EXIT(DBAL_HANDLE_ALLOC(unit, table_id, &entry_handle_id));

    dbal_entry_key_field8_set(unit, entry_handle_id, key_field_id, key_value);

    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_BYTES_PER_CYCLE_MANTISSA, INST_SINGLE, rate_mnt_val);
    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_BYTES_PER_CYCLE_EXPONENT, INST_SINGLE, rate_exp_val);
    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_MAX_CREDITS_MANTISSA, INST_SINGLE, burst_mnt_val);
    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_MAX_CREDITS_EXPONENT, INST_SINGLE, burst_exp_val);

    if (bw->flags & BCM_SAT_GTF_RATE_IN_PACKETS)
    {
        dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_CREDITS_PER_PACKET_EN, INST_SINGLE, 1);
    }
    else
    {
        dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_CREDITS_PER_PACKET_EN, INST_SINGLE, 0);
    }

    SHR_IF_ERR_EXIT(dbal_entry_commit(unit, entry_handle_id, DBAL_COMMIT));

exit:
    DBAL_FUNC_FREE_VARS;
    SHR_FUNC_EXIT;
}

static shr_error_e
dnx_sat_gtf_bandwidth_set_verify(
    int unit,
    bcm_sat_gtf_t gtf_id,
    bcm_sat_gtf_bandwidth_t * bw,
    uint32 gtf_rate_factor)
{
    uint8 is_allocated;
    uint32 max_rate;
    SHR_FUNC_INIT_VARS(unit);

    SHR_NULL_CHECK(bw, _SHR_E_PARAM, "bw ");
    SHR_RANGE_VERIFY(gtf_id, DNX_SAT_GTF_ID_MIN, DNX_SAT_GTF_ID_MAX, _SHR_E_PARAM, "gtf_id");
    max_rate = bw->rate * ((float) gtf_rate_factor / DNX_SAT_GTF_RATE_CMP_CONVERSION);

    if (bw->flags & BCM_SAT_GTF_RATE_IN_PACKETS)
    {
        SHR_MAX_VERIFY(max_rate, DNX_SAT_GTF_BW_PPS_RATE_MAX, _SHR_E_PARAM, "rate");
    }
    else
    {
        SHR_MAX_VERIFY(max_rate, DNX_SAT_GTF_BW_RATE_MAX, _SHR_E_PARAM, "rate");
    }
    SHR_MAX_VERIFY(bw->max_burst, DNX_SAT_GTF_BW_BURST_MAX, _SHR_E_PARAM, "max_burst");

    SHR_IF_ERR_EXIT(algo_sat_db.sat_res_alloc_gtf_id.is_allocated(unit, gtf_id, &is_allocated));

    if (!is_allocated)
    {
        SHR_ERR_EXIT(_SHR_E_NOT_FOUND, "Error: gtf_id  %d does not exist\n", gtf_id);
    }

exit:
    SHR_FUNC_EXIT;
}

shr_error_e
bcm_dnx_sat_gtf_bandwidth_set(
    int unit,
    bcm_sat_gtf_t gtf_id,
    int priority,
    bcm_sat_gtf_bandwidth_t * bw)
{
    bcm_sat_gtf_bandwidth_t dnx_bandwidth;
    dnx_sat_data_t psat_data;
    bcm_sat_gtf_t gtf_to_set = gtf_id;
    uint8 rate_mode = 0;
    uint8 is_granularity_set = 1;
    uint32 gtf_rate_factor, gtf_config_rate;
    int packet_length_compensation;
    uint32 is_paired = 0;

    SHR_FUNC_INIT_VARS(unit);
    DNX_ERR_RECOVERY_START(unit);

    DNX_SAT_IS_SUPPORTED_CHECK(unit);

    if (DNX_SAT_GTF_ID_IS_VALID_EVC_ID(gtf_id))
    {
        SHR_IF_ERR_EXIT(dnx_sat_gtf_is_paired_get(unit, gtf_id, &is_paired));
    }

    if (!is_paired && (priority != bcmSatGtfPriCir))
    {
        LOG_WARN(BSL_LS_BCM_SAT, ("GTF is not paired but priority is not CIR, ignore priority\n"));
        priority = bcmSatGtfPriCir;
    }

    SHR_INVOKE_VERIFY_DNXC(dnx_sat_gtf_id_priority_verify(unit, gtf_id, priority));
    SHR_NULL_CHECK(bw, _SHR_E_PARAM, "bw");

    if (priority == bcmSatGtfPriEir)
    {

        gtf_to_set += 1;
    }

    SHR_IF_ERR_EXIT(dnx_sat_gtf_config_rate_get
                    (unit, gtf_to_set, &gtf_config_rate, &gtf_rate_factor, &packet_length_compensation));
    SHR_INVOKE_VERIFY_DNXC(dnx_sat_gtf_bandwidth_set_verify(unit, gtf_to_set, bw, gtf_rate_factor));

    if (priority != bcmSatGtfPriAll)
    {
        SHR_IF_ERR_EXIT(dnx_sat_gtf_config_rate_set
                        (unit, gtf_to_set, bw->rate, gtf_rate_factor, packet_length_compensation));
        LOG_VERBOSE(BSL_LS_BCM_SAT,
                    ("%s %d: u(%d) gtf_id(%d) priority(%d) rate(%d) max_burst(%d)\n", BSL_FUNC, BSL_LINE, unit, gtf_id,
                     priority, bw->rate, bw->max_burst));
    }

    sal_memset(&dnx_bandwidth, 0, sizeof(dnx_bandwidth));
    sal_memset(&psat_data, 0, sizeof(dnx_sat_data_t));
    SHR_IF_ERR_EXIT(dnx_sat_data_get(unit, &psat_data));

    if (bw->flags & BCM_SAT_GTF_RATE_WITH_GRANULARITY)
    {

        if (bw->granularity == 0)
        {
            SHR_ERR_EXIT(BCM_E_PARAM, "Fail(%s) granularity shouldn't be zero \n", soc_errmsg(BCM_E_PARAM));
        }

        if (is_granularity_set == psat_data.granularity_flag)
        {
            LOG_WARN(BSL_LS_BCM_SAT, (BSL_META_U(unit,
                                                 "Warning : Granularity is shared by all GTFs, which will influce all the GTF  granularity\n")));
        }

        psat_data.granularity_flag = 1;
    }

    if (bw->flags & BCM_SAT_GTF_RATE_IN_PACKETS)
    {
        rate_mode = DNX_SAT_PPS_MODE;
    }
    else
    {
        rate_mode = DNX_SAT_BPS_MODE;
    }

    if (0 == psat_data.rate_mode)
    {
        psat_data.rate_mode = rate_mode;
        if (rate_mode == DNX_SAT_PPS_MODE)
        {

            psat_data.granularity_flag = 1;
        }
    }
    else if (rate_mode != psat_data.rate_mode)
    {
        SHR_ERR_EXIT(BCM_E_PARAM,
                     "Fail(%s)  BPS/PPS mode conflicts with global rate mode (which is decided by first GTF ), you should delete all GTFs before change it\n",
                     soc_errmsg(BCM_E_PARAM));
    }

    dnx_bandwidth.rate = bw->rate;
    dnx_bandwidth.max_burst = bw->max_burst;
    dnx_bandwidth.flags = bw->flags;
    dnx_bandwidth.granularity = bw->granularity;

    SHR_IF_ERR_EXIT(dnx_sat_gtf_bandwidth_set(unit, gtf_to_set, priority, &dnx_bandwidth, gtf_rate_factor));

    SHR_IF_ERR_EXIT(dnx_sat_data_set(unit, &psat_data));

exit:
    DNX_ERR_RECOVERY_END(unit);
    SHR_FUNC_EXIT;
}

static shr_error_e
dnx_sat_gtf_traverse_verify(
    int unit,
    void *user_data)
{
    SHR_FUNC_INIT_VARS(unit);
    SHR_NULL_CHECK(user_data, _SHR_E_PARAM, "user_data ");

    DNX_SAT_IS_SUPPORTED_CHECK(unit);

    SHR_EXIT();
exit:
    SHR_FUNC_EXIT;
}

shr_error_e
bcm_dnx_sat_gtf_traverse(
    int unit,
    bcm_sat_gtf_traverse_cb cb,
    void *user_data)
{
    bcm_sat_ctf_t gtf_id;
    uint8 is_gtf_allocated;

    SHR_FUNC_INIT_VARS(unit);
    DNX_ERR_RECOVERY_NOT_NEEDED(unit);

    SHR_INVOKE_VERIFY_DNXC(dnx_sat_gtf_traverse_verify(unit, user_data));

    LOG_VERBOSE(BSL_LS_BCM_SAT, ("%s %d: u(%d) \n", BSL_FUNC, BSL_LINE, unit));

    for (gtf_id = DNX_SAT_GTF_ID_MIN; gtf_id <= DNX_SAT_GTF_ID_MAX; gtf_id++)
    {

        SHR_IF_ERR_EXIT(algo_sat_db.sat_res_alloc_gtf_id.is_allocated(unit, gtf_id, &is_gtf_allocated));
        if (is_gtf_allocated)
        {

            (*cb) (unit, gtf_id, user_data);
        }
    }

exit:
    SHR_FUNC_EXIT;
}

void
dnx_sat_packet_config_dump(
    bcm_sat_gtf_packet_config_t * config)
{
    int ii = 0, pri = 0, ele = 0;

    if (!LOG_CHECK(BSL_LS_BCM_SAT | BSL_VERBOSE))
    {
        return;
    }
    if (config == NULL)
    {
        return;
    }

    cli_out("\n");
    cli_out("  payload_type:%d\n", config->payload.payload_type);
    cli_out("  payload_pattern:");
    ele = (config->payload.payload_type == bcmSatPayloadConstant8Bytes) ? 8 : 4;
    if (config->payload.payload_type != bcmSatPayloadPRBS)
    {
        for (ii = 0; ii < ele; ii++)
        {
            cli_out("%02x ", config->payload.payload_pattern[ii]);
        }
    }
    cli_out("\n");
    for (pri = 0; pri < BCM_SAT_GTF_NUM_OF_PRIORITIES; pri++)
    {
        cli_out("  %s packet_edit:\n", ((pri == 0) ? "cir" : "eir"));
        cli_out("    packet_length:");
        for (ii = 0; ii < BCM_SAT_GTF_PACKET_LENGTH_NUM_OF_PATTERNS; ii++)
        {
            cli_out("%d ", config->packet_edit[pri].packet_length[ii]);
        }
        cli_out("\n");
        cli_out("    packet_length_pattern:");
        for (ii = 0; ii < BCM_SAT_GTF_PACKET_MAX_PATTERN_LENGTH; ii++)
        {
            cli_out("%d ", config->packet_edit[pri].packet_length_pattern[ii]);
        }
        cli_out("\n");
        cli_out("    pattern_length:%d\n", config->packet_edit[pri].pattern_length);
        cli_out("    number_of_stamps:%d\n", config->packet_edit[pri].number_of_stamps);
        for (ii = 0; ii < config->packet_edit[pri].number_of_stamps; ii++)
        {
            cli_out
                ("    stamp(%d):  stamp_type:%d  field_type:%d  inc_step:%d  inc_period_packets:%d  value:%d  offset:%d\n",
                 ii, config->packet_edit[pri].stamps[ii].stamp_type, config->packet_edit[pri].stamps[ii].field_type,
                 config->packet_edit[pri].stamps[ii].inc_step, config->packet_edit[pri].stamps[ii].inc_period_packets,
                 config->packet_edit[pri].stamps[ii].value, config->packet_edit[pri].stamps[ii].offset);
        }
        cli_out("    number_of_ctfs:%d\n", config->packet_edit[pri].number_of_ctfs);
        cli_out("    flags:%d\n", config->packet_edit[pri].flags);
    }
    cli_out("  packet_context_id:%d\n", config->packet_context_id);
    cli_out("  offsets:\n");
    cli_out("    seq_number_offset:%d\n", config->offsets.seq_number_offset);
    cli_out("    timestamp_offset:%d\n", config->offsets.timestamp_offset);
}

static shr_error_e
dnx_sat_gtf_stamp_field_verify(
    int unit,
    bcm_sat_gtf_packet_edit_t * pkt_edit,
    dnx_sat_gtf_stamp_field_tbl_info_t * stamp_field_info)
{
    int ii;

    SHR_FUNC_INIT_VARS(unit);
    SHR_NULL_CHECK(pkt_edit, _SHR_E_PARAM, "pkt_edit ");
    SHR_NULL_CHECK(stamp_field_info, _SHR_E_PARAM, "stamp_field_info ");

    for (ii = 0; ii < pkt_edit->number_of_stamps; ii++)
    {
        if (pkt_edit->stamps[ii].stamp_type == bcmSatStampConstant2Bit)
        {
            SHR_ERR_EXIT(_SHR_E_PARAM, "Error: bcmSatStampConstant2Bit is not supported\n");
        }
    }

exit:
    SHR_FUNC_EXIT;
}

static shr_error_e
dnx_sat_gtf_get_stamp_field(
    int unit,
    bcm_sat_gtf_packet_edit_t * pkt_edit,
    dnx_sat_gtf_stamp_field_tbl_info_t * stamp_field_info)
{
    int cur_pos = 0;

    SHR_FUNC_INIT_VARS(unit);

    if (stamp_field_info->stamp_2_ena == 1)
    {

        SHR_ERR_EXIT(_SHR_E_PARAM, "JR2 support 16bits stamp, rather than 2 bits\n");
    }

    if (stamp_field_info->counter_8_ena == 1)
    {
        pkt_edit->stamps[cur_pos].stamp_type = bcmSatStampCounter8Bit;
        pkt_edit->stamps[cur_pos].inc_step = stamp_field_info->counter_8_inc_step;
        pkt_edit->stamps[cur_pos].inc_period_packets = stamp_field_info->counter_8_period;

        if (stamp_field_info->counter_8_shift == 0)
        {
            pkt_edit->stamps[cur_pos].offset = (stamp_field_info->counter_8_offset) * DNX_SAT_BITS_PER_BYTE;
        }
        else
        {
            pkt_edit->stamps[cur_pos].offset =
                (stamp_field_info->counter_8_offset - 1) * DNX_SAT_BITS_PER_BYTE + (DNX_SAT_BITS_PER_BYTE -
                                                                                    stamp_field_info->counter_8_shift);
        }

        ++cur_pos;
    }

    if (stamp_field_info->counter_16_ena == 1)
    {
        pkt_edit->stamps[cur_pos].stamp_type = bcmSatStampCounter16Bit;
        pkt_edit->stamps[cur_pos].inc_step = stamp_field_info->counter_16_inc_step;
        pkt_edit->stamps[cur_pos].inc_period_packets = stamp_field_info->counter_16_period;

        if (stamp_field_info->counter_16_shift == 0)
        {
            pkt_edit->stamps[cur_pos].offset = (stamp_field_info->counter_16_offset) * DNX_SAT_BITS_PER_BYTE;
        }
        else
        {
            pkt_edit->stamps[cur_pos].offset =
                (stamp_field_info->counter_16_offset - 1) * DNX_SAT_BITS_PER_BYTE + (DNX_SAT_BITS_PER_BYTE -
                                                                                     stamp_field_info->counter_16_shift);
        }

        ++cur_pos;
    }

    if (stamp_field_info->stamp_16_ena == 1)
    {
        pkt_edit->stamps[cur_pos].stamp_type = bcmSatStampConstant16Bit;
        pkt_edit->stamps[cur_pos].value = stamp_field_info->stamp_16_value;

        if (stamp_field_info->stamp_16_shift == 0)
        {
            pkt_edit->stamps[cur_pos].offset = stamp_field_info->stamp_16_offset * DNX_SAT_BITS_PER_BYTE;
        }
        else
        {
            pkt_edit->stamps[cur_pos].offset =
                (stamp_field_info->stamp_16_offset - 1) * DNX_SAT_BITS_PER_BYTE + (DNX_SAT_BITS_PER_BYTE -
                                                                                   stamp_field_info->stamp_16_shift);
        }

        ++cur_pos;
    }

    pkt_edit->number_of_stamps = cur_pos;

    SHR_EXIT();

exit:
    SHR_FUNC_EXIT;
}

static shr_error_e
dnx_sat_gtf_construct_stamp_field(
    int unit,
    bcm_sat_gtf_packet_edit_t * pkt_edit,
    dnx_sat_gtf_stamp_field_tbl_info_t * stamp_field_info)
{
    const uint32 field_2_cnt_8_mask[7] = { 0xff, 0xe0, 0xc0, 0xff, 0xff, 0xff, 0xff };
    const uint32 field_2_cnt_16_mask[7] = { 0xffff, 0xe000, 0xc000, 0xffff, 0xffff, 0xfff0, 0xfff0 };
    const bcm_sat_stamp_t *tmp_stamp;
    int ii = 0;
    int tmp_stamp_offset_bits = 0;

    SHR_FUNC_INIT_VARS(unit);

    SHR_INVOKE_VERIFY_DNXC(dnx_sat_gtf_stamp_field_verify(unit, pkt_edit, stamp_field_info));

    for (ii = 0; ii < pkt_edit->number_of_stamps; ii++)
    {
        tmp_stamp = &(pkt_edit->stamps[ii]);

        if (tmp_stamp->stamp_type == bcmSatStampCounter8Bit)
        {
            tmp_stamp_offset_bits = tmp_stamp->offset;
            stamp_field_info->counter_8_ena = 1;
            stamp_field_info->counter_8_offset =
                (tmp_stamp_offset_bits / DNX_SAT_BITS_PER_BYTE) +
                ((tmp_stamp_offset_bits % DNX_SAT_BITS_PER_BYTE) ? 1 : 0);
            stamp_field_info->counter_8_shift =
                (DNX_SAT_BITS_PER_BYTE - (tmp_stamp_offset_bits % DNX_SAT_BITS_PER_BYTE)) % DNX_SAT_BITS_PER_BYTE;
            stamp_field_info->counter_8_mask = field_2_cnt_8_mask[tmp_stamp->field_type];
            stamp_field_info->counter_8_inc_step = tmp_stamp->inc_step;
            stamp_field_info->counter_8_period = tmp_stamp->inc_period_packets;
        }
        else if (tmp_stamp->stamp_type == bcmSatStampCounter16Bit)
        {
            tmp_stamp_offset_bits = tmp_stamp->offset;
            stamp_field_info->counter_16_ena = 1;
            stamp_field_info->counter_16_offset =
                (tmp_stamp_offset_bits / DNX_SAT_BITS_PER_BYTE) +
                ((tmp_stamp_offset_bits % DNX_SAT_BITS_PER_BYTE) ? 1 : 0);
            stamp_field_info->counter_16_shift =
                (DNX_SAT_BITS_PER_BYTE - (tmp_stamp_offset_bits % DNX_SAT_BITS_PER_BYTE)) % DNX_SAT_BITS_PER_BYTE;
            stamp_field_info->counter_16_mask = field_2_cnt_16_mask[tmp_stamp->field_type];
            stamp_field_info->counter_16_inc_step = tmp_stamp->inc_step;
            stamp_field_info->counter_16_period = tmp_stamp->inc_period_packets;
        }
        else if (tmp_stamp->stamp_type == bcmSatStampConstant16Bit)
        {
            tmp_stamp_offset_bits = tmp_stamp->offset;
            stamp_field_info->stamp_16_ena = 1;
            if (tmp_stamp_offset_bits % DNX_SAT_BITS_PER_BYTE == 0)
            {
                stamp_field_info->stamp_16_offset = tmp_stamp_offset_bits / DNX_SAT_BITS_PER_BYTE;
                stamp_field_info->stamp_16_shift = 0;
            }
            else
            {
                stamp_field_info->stamp_16_offset = tmp_stamp_offset_bits / DNX_SAT_BITS_PER_BYTE + 1;
                stamp_field_info->stamp_16_shift =
                    DNX_SAT_BITS_PER_BYTE - tmp_stamp_offset_bits % DNX_SAT_BITS_PER_BYTE;
            }
            stamp_field_info->stamp_16_value = tmp_stamp->value;
        }
    }
    SHR_EXIT();
exit:
    SHR_FUNC_EXIT;
}

static shr_error_e
dnx_sat_gtf_packet_header_field_verify(
    int unit,
    bcm_pkt_t * pkt_hdr,
    dnx_sat_gtf_pkt_hdr_tbl_info_t * pkt_hdr_info)
{
    SHR_FUNC_INIT_VARS(unit);
    SHR_NULL_CHECK(pkt_hdr, _SHR_E_PARAM, "pkt_hdr ");
    SHR_NULL_CHECK(pkt_hdr_info, _SHR_E_PARAM, "pkt_hdr_info ");
exit:
    SHR_FUNC_EXIT;
}

shr_error_e
dnx_sat_gtf_construct_packet_header(
    int unit,
    bcm_pkt_t * pkt_hdr,
    dnx_sat_gtf_pkt_hdr_tbl_info_t * pkt_hdr_info)
{
    SHR_FUNC_INIT_VARS(unit);

    SHR_INVOKE_VERIFY_DNXC(dnx_sat_gtf_packet_header_field_verify(unit, pkt_hdr, pkt_hdr_info));

    sal_memcpy(pkt_hdr_info->pkt_header, pkt_hdr->pkt_data[0].data, pkt_hdr->pkt_data[0].len);

    pkt_hdr_info->pkt_header_len = pkt_hdr->pkt_data[0].len;

exit:
    SHR_FUNC_EXIT;
}

shr_error_e
dnx_sat_gtf_get_packet_header(
    int unit,
    bcm_pkt_t * pkt_hdr,
    dnx_sat_gtf_pkt_hdr_tbl_info_t * pkt_hdr_info)
{
    SHR_FUNC_INIT_VARS(unit);

    SHR_INVOKE_VERIFY_DNXC(dnx_sat_gtf_packet_header_field_verify(unit, pkt_hdr, pkt_hdr_info));

    sal_memcpy(pkt_hdr->pkt_data[0].data, pkt_hdr_info->pkt_header, pkt_hdr_info->pkt_header_len);
    pkt_hdr->pkt_data[0].len = pkt_hdr_info->pkt_header_len;

exit:
    SHR_FUNC_EXIT;
}

static shr_error_e
dnx_sat_gtf_packet_header_config_set(
    int unit,
    int pkt_header_base,
    dnx_sat_gtf_pkt_hdr_tbl_info_t * config)
{
    uint32 entry_handle_id;
    uint8 pkt_hdr_lsb[DNX_SAT_PKT_HERDER_LSB_FIELD_SIZE] = { 0 };
    uint8 pkt_hdr_msb[DNX_SAT_PKT_HERDER_MSB_FIELD_SIZE] = { 0 };
    uint8 entry, start, end;
    int ii, pos, loop, loop_count;
    SHR_FUNC_INIT_VARS(unit);
    DBAL_FUNC_INIT_VARS(unit);

    SHR_IF_ERR_EXIT(dnx_sat_dynamic_memory_access_set(unit, 1));

    SHR_IF_ERR_EXIT(DBAL_HANDLE_ALLOC(unit, DBAL_TABLE_SAT_TX_PKT_HEADER_CONFIG, &entry_handle_id));

    entry = (pkt_header_base << 2) / DNX_SAT_PKT_HERDER_SIZE;
    start = (pkt_header_base << 2) % DNX_SAT_PKT_HERDER_SIZE;

    loop_count = ((start + config->pkt_header_len) > DNX_SAT_PKT_HERDER_SIZE) ? 2 : 1;
    end = (loop_count > 1) ? DNX_SAT_PKT_HERDER_SIZE : (start + config->pkt_header_len);
    pos = 0;

    for (loop = 0; loop < loop_count; ++loop)
    {
        if (loop == 1)
        {
            entry += 1;
            end = start + config->pkt_header_len - DNX_SAT_PKT_HERDER_SIZE;
            start = 0;
        }

        dbal_entry_key_field8_set(unit, entry_handle_id, DBAL_FIELD_SAT_PACKET_HEADER_INDEX, entry);

        SHR_IF_ERR_EXIT(dbal_entry_get(unit, entry_handle_id, DBAL_GET_ALL_FIELDS));

        dbal_entry_handle_value_field_arr8_get(unit, entry_handle_id, DBAL_FIELD_TX_PACKET_HEADER_LOW, INST_SINGLE,
                                               pkt_hdr_lsb);
        dbal_entry_handle_value_field_arr8_get(unit, entry_handle_id, DBAL_FIELD_TX_PACKET_HEADER_HIGH, INST_SINGLE,
                                               pkt_hdr_msb);

        for (ii = start; ii < end; ii++, pos++)
        {
            if (ii < DNX_SAT_PKT_HERDER_MSB_FIELD_SIZE)
            {
                pkt_hdr_msb[DNX_SAT_PKT_HERDER_MSB_FIELD_SIZE - ii - 1] = config->pkt_header[pos];
            }
            else
            {
                pkt_hdr_lsb[DNX_SAT_PKT_HERDER_SIZE - ii - 1] = config->pkt_header[pos];
            }
        }

        dbal_entry_value_field_arr8_set(unit, entry_handle_id, DBAL_FIELD_TX_PACKET_HEADER_LOW, INST_SINGLE,
                                        pkt_hdr_lsb);
        dbal_entry_value_field_arr8_set(unit, entry_handle_id, DBAL_FIELD_TX_PACKET_HEADER_HIGH, INST_SINGLE,
                                        pkt_hdr_msb);

        SHR_IF_ERR_EXIT(dbal_entry_commit(unit, entry_handle_id, DBAL_COMMIT));

        LOG_VERBOSE(BSL_LS_BCM_SAT,
                    ("%s %d: u(%d) pkt_header_base %d pkt_header_len %d start %d end %d\n", BSL_FUNC, BSL_LINE, unit,
                     pkt_header_base, config->pkt_header_len, start, end));
    }

exit:
    dnx_sat_dynamic_memory_access_set(unit, 0);
    DBAL_FUNC_FREE_VARS;
    SHR_FUNC_EXIT;
}

static shr_error_e
dnx_sat_gtf_packet_header_config_clean(
    int unit,
    int pkt_header_base,
    int pkt_header_len)
{
    dnx_sat_gtf_pkt_hdr_tbl_info_t config;

    SHR_FUNC_INIT_VARS(unit);
    DBAL_FUNC_INIT_VARS(unit);

    sal_memset(&config, 0, sizeof(config));
    config.pkt_header_len = pkt_header_len;

    SHR_IF_ERR_EXIT(dnx_sat_gtf_packet_header_config_set(unit, pkt_header_base, &config));

exit:
    DBAL_FUNC_FREE_VARS;
    SHR_FUNC_EXIT;
}

static shr_error_e
dnx_sat_gtf_packet_header_config_get(
    int unit,
    int header_profile,
    dnx_sat_gtf_pkt_hdr_tbl_info_t * config)
{
    uint32 entry_handle_id;
    uint8 pkt_hdr_lsb[DNX_SAT_PKT_HERDER_LSB_FIELD_SIZE];
    uint8 pkt_hdr_msb[DNX_SAT_PKT_HERDER_MSB_FIELD_SIZE];
    uint16 pkt_header_base = 0;
    uint32 pkt_header_len;
    uint8 entry, start, end;
    int ii, pos, loop, loop_count;

    SHR_FUNC_INIT_VARS(unit);
    DBAL_FUNC_INIT_VARS(unit);

    SHR_IF_ERR_EXIT(sat_pkt_header_info.pkt_header_base.get(unit, header_profile, &pkt_header_base));

    SHR_IF_ERR_EXIT(dnx_am_template_sat_pkt_header_length_get(unit, header_profile, &pkt_header_len));

    SHR_IF_ERR_EXIT(dnx_sat_dynamic_memory_access_set(unit, 1));

    SHR_IF_ERR_EXIT(DBAL_HANDLE_ALLOC(unit, DBAL_TABLE_SAT_TX_PKT_HEADER_CONFIG, &entry_handle_id));

    entry = (pkt_header_base << 2) / DNX_SAT_PKT_HERDER_SIZE;
    start = (pkt_header_base << 2) % (DNX_SAT_PKT_HERDER_SIZE - 1);

    loop_count = ((start + pkt_header_len) > DNX_SAT_PKT_HERDER_SIZE) ? 2 : 1;
    end = (loop_count > 1) ? DNX_SAT_PKT_HERDER_SIZE : (start + pkt_header_len);
    pos = 0;

    for (loop = 0; loop < loop_count; ++loop)
    {
        if (loop == 1)
        {
            entry += 1;
            end = start + pkt_header_len - DNX_SAT_PKT_HERDER_SIZE;
            start = 0;
        }

        dbal_entry_key_field8_set(unit, entry_handle_id, DBAL_FIELD_SAT_PACKET_HEADER_INDEX, entry);

        SHR_IF_ERR_EXIT(dbal_entry_get(unit, entry_handle_id, DBAL_GET_ALL_FIELDS));

        dbal_entry_handle_value_field_arr8_get(unit, entry_handle_id, DBAL_FIELD_TX_PACKET_HEADER_LOW, INST_SINGLE,
                                               pkt_hdr_lsb);
        dbal_entry_handle_value_field_arr8_get(unit, entry_handle_id, DBAL_FIELD_TX_PACKET_HEADER_HIGH, INST_SINGLE,
                                               pkt_hdr_msb);

        for (ii = start; ii < end; ii++, pos++)
        {
            if (ii < DNX_SAT_PKT_HERDER_MSB_FIELD_SIZE)
            {
                config->pkt_header[pos] = pkt_hdr_msb[DNX_SAT_PKT_HERDER_MSB_FIELD_SIZE - ii - 1];
            }
            else
            {
                config->pkt_header[pos] = pkt_hdr_lsb[DNX_SAT_PKT_HERDER_SIZE - ii - 1];
            }
        }
    }

    config->pkt_header_len = pkt_header_len;

exit:
    dnx_sat_dynamic_memory_access_set(unit, 0);
    DBAL_FUNC_FREE_VARS;
    SHR_FUNC_EXIT;
}

static shr_error_e
dnx_sat_gtf_packet_config_set(
    int unit,
    bcm_sat_gtf_t gtf_id,
    int pkt_header_base,
    uint32 header_len,
    bcm_sat_gtf_packet_config_t * config)
{
    int rv = _SHR_E_NONE;
    uint32 payload_type = 0;
    uint32 entry_handle_id;
    uint32 payload_rpt_pattern[DNX_SAT_PAYLOAD_MAX_PATTERN_NOF_U32] = { 0 };
    dnx_sat_gtf_stamp_field_tbl_info_t stamp_field_info;
    uint32 sequence_ena = 0;
    uint32 sequence_period = 0;
    uint32 sequence_offset = 0;
    uint32 seq_number_wrap_around = 0;
    uint32 pkt_add_crc = 0;
    uint32 pkt_add_tlv = 0;
    uint32 crc_offset = 0;
    uint32 offset = 0;
    uint32 length_pattern[DNX_SAT_PKT_LENGTH_PATTERN_FIELD_SIZE] = { 0 };
    int ii = 0;
    int priority = 0;
    uint32 pkt_length_fields[DNX_SAT_GTF_PACKET_LENGTH_NUM_OF_PATTERNS] = {
        DBAL_FIELD_PKT_LENGTH_0,
        DBAL_FIELD_PKT_LENGTH_1,
        DBAL_FIELD_PKT_LENGTH_2,
        DBAL_FIELD_PKT_LENGTH_3,
        DBAL_FIELD_PKT_LENGTH_4,
        DBAL_FIELD_PKT_LENGTH_5,
        DBAL_FIELD_PKT_LENGTH_6,
        DBAL_FIELD_PKT_LENGTH_7
    };

    SHR_FUNC_INIT_VARS(unit);
    DBAL_FUNC_INIT_VARS(unit);

    if (config->payload.payload_type == bcmSatPayloadConstant8Bytes)
    {
        rv = dnx_sat_packet_config_exp_payload_uint8_to_long(config->payload.payload_pattern,
                                                             DNX_SAT_PAYLOAD_MAX_PATTERN_NOF_U8, 0,
                                                             payload_rpt_pattern);
        SHR_IF_ERR_EXIT(rv);
        payload_type = 0;
    }
    else if (config->payload.payload_type == bcmSatPayloadConstant4Bytes)
    {
        rv = dnx_sat_packet_config_exp_payload_uint8_to_long(config->payload.payload_pattern,
                                                             DNX_SAT_PAYLOAD_MAX_PATTERN_NOF_U8 / 2, 0,
                                                             payload_rpt_pattern);
        SHR_IF_ERR_EXIT(rv);
        payload_type = 1;
    }
    else if (config->payload.payload_type == bcmSatPayloadPRBS)
    {
        payload_type = 2;
    }
    else
    {
        SHR_ERR_EXIT(_SHR_E_PARAM, "payload_type ERROR\n");
    }

    sal_memset(&(stamp_field_info), 0, sizeof(stamp_field_info));
    rv = dnx_sat_gtf_construct_stamp_field(unit, &(config->packet_edit[priority]), &(stamp_field_info));
    SHR_IF_ERR_EXIT(rv);

    if (config->offsets.seq_number_offset != DNX_SAT_GTF_SEQ_NUM_DISABLE)
    {
        sequence_ena = 1;
        sequence_offset = config->offsets.seq_number_offset;

        sequence_period = config->packet_edit[priority].number_of_ctfs - 1;
    }
    else
    {
        sequence_ena = 0;
    }

    if (config->packet_edit[priority].flags & BCM_SAT_GTF_PACKET_EDIT_ADD_END_TLV)
    {
        pkt_add_tlv = 1;
    }
    else
    {
        pkt_add_tlv = 0;
    }

    if (config->packet_edit[priority].flags & BCM_SAT_GTF_PACKET_EDIT_ADD_CRC)
    {
        pkt_add_crc = 1;
        crc_offset = config->offsets.crc_byte_offset;
    }
    else
    {
        pkt_add_crc = 0;
    }

    SHR_IF_ERR_EXIT(dnx_sat_dynamic_memory_access_set(unit, 1));

    if (dnx_data_sat.tx_flow_param.feature_get(unit, dnx_data_sat_tx_flow_param_seq_number_wrap_around))
    {

        SHR_IF_ERR_EXIT(DBAL_HANDLE_ALLOC(unit, DBAL_TABLE_SAT_SEQ_NUM_WRAP_AROUND, &entry_handle_id));

        dbal_value_field32_request(unit, entry_handle_id, DBAL_FIELD_SEQ_NUM_WRAP_AROUND, INST_SINGLE,
                                   &seq_number_wrap_around);

        SHR_IF_ERR_EXIT(dbal_entry_get(unit, entry_handle_id, DBAL_COMMIT));

        SHR_IF_ERR_EXIT(DBAL_HANDLE_CLEAR(unit, DBAL_TABLE_SAT_TX_PKT_PARAM_CONFIG, entry_handle_id));
    }
    else
    {

        SHR_IF_ERR_EXIT(DBAL_HANDLE_ALLOC(unit, DBAL_TABLE_SAT_TX_PKT_PARAM_CONFIG, &entry_handle_id));
    }

    dbal_entry_key_field8_set(unit, entry_handle_id, DBAL_FIELD_TX_FLOW_ID, gtf_id);

    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_PAYLOAD_TYPE, INST_SINGLE, payload_type);

    dbal_entry_value_field_arr32_set(unit, entry_handle_id, DBAL_FIELD_RPT_PATTERN, INST_SINGLE, payload_rpt_pattern);

    for (ii = 0; ii < DNX_SAT_GTF_PACKET_LENGTH_NUM_OF_PATTERNS; ii++)
    {
        dbal_entry_value_field32_set(unit, entry_handle_id, pkt_length_fields[ii], INST_SINGLE,
                                     config->packet_edit[priority].packet_length[ii]);
    }

    offset = 0;
    for (ii = 0; ii < config->packet_edit[priority].pattern_length; ii++)
    {
        SHR_BITCOPY_RANGE(length_pattern, offset, &(config->packet_edit[priority].packet_length_pattern[ii]), 0, 3);
        offset += 3;
    }
    dbal_entry_value_field_arr32_set(unit, entry_handle_id, DBAL_FIELD_LENGTH_PATTERN, INST_SINGLE, length_pattern);
    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_LENGTH_PATTERN_SIZE, INST_SINGLE,
                                 config->packet_edit[priority].pattern_length - 1);

    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_STMP_16_BIT_ENABLE, INST_SINGLE,
                                 stamp_field_info.stamp_16_ena);
    if (stamp_field_info.stamp_16_ena != 0)
    {
        dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_STMP_16_BIT_OFFSET, INST_SINGLE,
                                     stamp_field_info.stamp_16_offset);
        dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_STMP_16_BIT_SHIFT, INST_SINGLE,
                                     stamp_field_info.stamp_16_shift);
        dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_STMP_16_BIT_VALUE, INST_SINGLE,
                                     stamp_field_info.stamp_16_value);
    }

    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_CNTR_8_BIT_ENABLE, INST_SINGLE,
                                 stamp_field_info.counter_8_ena);
    if (stamp_field_info.counter_8_ena != 0)
    {
        dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_CNTR_8_BIT_OFFSET, INST_SINGLE,
                                     stamp_field_info.counter_8_offset);
        dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_CNTR_8_BIT_SHIFT, INST_SINGLE,
                                     stamp_field_info.counter_8_shift);
        dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_CNTR_8_BIT_MASK, INST_SINGLE,
                                     stamp_field_info.counter_8_mask);
        dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_CNTR_8_BIT_INC_STEP, INST_SINGLE,
                                     stamp_field_info.counter_8_inc_step);
        dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_CNTR_8_BIT_PERIOD, INST_SINGLE,
                                     stamp_field_info.counter_8_period);
        dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_CNTR_8_BIT_NEXT_VALUE, INST_SINGLE, 0);
    }

    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_CNTR_16_BIT_ENABLE, INST_SINGLE,
                                 stamp_field_info.counter_16_ena);
    if (stamp_field_info.counter_16_ena != 0)
    {
        dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_CNTR_16_BIT_OFFSET, INST_SINGLE,
                                     stamp_field_info.counter_16_offset);
        dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_CNTR_16_BIT_SHIFT, INST_SINGLE,
                                     stamp_field_info.counter_16_shift);
        dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_CNTR_16_BIT_MASK, INST_SINGLE,
                                     stamp_field_info.counter_16_mask);
        dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_CNTR_16_BIT_INC_STEP, INST_SINGLE,
                                     stamp_field_info.counter_16_inc_step);
        dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_CNTR_16_BIT_PERIOD, INST_SINGLE,
                                     stamp_field_info.counter_16_period);
        dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_CNTR_16_BIT_NEXT_VALUE, INST_SINGLE, 0);
    }

    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_SEQ_NUM_ENABLE, INST_SINGLE, sequence_ena);
    if (sequence_ena == 1)
    {
        dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_SEQ_NUM_PERIOD, INST_SINGLE, sequence_period);
        dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_SEQ_NUM_OFFSET, INST_SINGLE, sequence_offset);
        dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_SEQ_NUM_NEXT_VALUE, INST_SINGLE,
                                     seq_number_wrap_around);
    }

    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_ADD_END_TLV, INST_SINGLE, pkt_add_tlv);
    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_CRC_32_ENABLE, INST_SINGLE, pkt_add_crc);
    if (pkt_add_crc == 1)
    {
        dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_CRC_32_OFFSET, INST_SINGLE, crc_offset);
    }

    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_CHANNEL_NUM, INST_SINGLE, 0);

    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_FLOW_CORE_ID, INST_SINGLE,
                                 config->packet_context_id);

    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_PKT_HEADER_POINT, INST_SINGLE, pkt_header_base);

    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_PKT_HEADER_LENGTH, INST_SINGLE, header_len);

    SHR_IF_ERR_EXIT(dbal_entry_commit(unit, entry_handle_id, DBAL_COMMIT));

exit:
    dnx_sat_dynamic_memory_access_set(unit, 0);
    DBAL_FUNC_FREE_VARS;
    SHR_FUNC_EXIT;
}

static shr_error_e
dnx_sat_gtf_packet_config_get(
    int unit,
    bcm_sat_gtf_t gtf_id,
    bcm_sat_gtf_packet_config_t * config)
{
    int rv = _SHR_E_NONE;
    uint32 payload_type = 0;
    uint32 entry_handle_id;
    uint32 payload_rpt_pattern[DNX_SAT_PAYLOAD_MAX_PATTERN_NOF_U32] = { 0 };
    dnx_sat_gtf_stamp_field_tbl_info_t stamp_field_info;
    uint32 gtf_config_rate, gtf_rate_factor;
    uint32 sequence_ena = 0;
    uint32 sequence_period = 0;
    uint32 sequence_offset = 0;
    uint32 pkt_add_crc = 0;
    uint32 pkt_add_tlv = 0;
    uint32 crc_offset = 0;
    uint32 offset = 0;
    uint32 length_pattern[DNX_SAT_PKT_LENGTH_PATTERN_FIELD_SIZE] = { 0 };
    uint32 length_pattern_size = 0;
    int ii = 0;
    uint32 packet_length[8] = { 0 };
    uint32 pkt_length_fields[DNX_SAT_GTF_PACKET_LENGTH_NUM_OF_PATTERNS] = {
        DBAL_FIELD_PKT_LENGTH_0,
        DBAL_FIELD_PKT_LENGTH_1,
        DBAL_FIELD_PKT_LENGTH_2,
        DBAL_FIELD_PKT_LENGTH_3,
        DBAL_FIELD_PKT_LENGTH_4,
        DBAL_FIELD_PKT_LENGTH_5,
        DBAL_FIELD_PKT_LENGTH_6,
        DBAL_FIELD_PKT_LENGTH_7
    };

    SHR_FUNC_INIT_VARS(unit);
    DBAL_FUNC_INIT_VARS(unit);

    SHR_IF_ERR_EXIT(dnx_sat_dynamic_memory_access_set(unit, 1));

    sal_memset(&(stamp_field_info), 0, sizeof(stamp_field_info));

    SHR_IF_ERR_EXIT(DBAL_HANDLE_ALLOC(unit, DBAL_TABLE_SAT_TX_PKT_PARAM_CONFIG, &entry_handle_id));

    dbal_entry_key_field8_set(unit, entry_handle_id, DBAL_FIELD_TX_FLOW_ID, gtf_id);
    dbal_value_field32_request(unit, entry_handle_id, DBAL_FIELD_PAYLOAD_TYPE, INST_SINGLE, &payload_type);

    dbal_value_field_arr32_request(unit, entry_handle_id, DBAL_FIELD_RPT_PATTERN, INST_SINGLE, payload_rpt_pattern);

    for (ii = 0; ii < DNX_SAT_GTF_PACKET_LENGTH_NUM_OF_PATTERNS; ii++)
    {
        dbal_value_field32_request(unit, entry_handle_id, pkt_length_fields[ii], INST_SINGLE, &(packet_length[ii]));
    }

    dbal_value_field_arr32_request(unit, entry_handle_id, DBAL_FIELD_LENGTH_PATTERN, INST_SINGLE, length_pattern);
    dbal_value_field32_request(unit, entry_handle_id, DBAL_FIELD_LENGTH_PATTERN_SIZE, INST_SINGLE,
                               &length_pattern_size);

    dbal_value_field32_request(unit, entry_handle_id, DBAL_FIELD_STMP_16_BIT_ENABLE, INST_SINGLE,
                               &(stamp_field_info.stamp_16_ena));
    dbal_value_field32_request(unit, entry_handle_id, DBAL_FIELD_STMP_16_BIT_OFFSET, INST_SINGLE,
                               &(stamp_field_info.stamp_16_offset));
    dbal_value_field32_request(unit, entry_handle_id, DBAL_FIELD_STMP_16_BIT_SHIFT, INST_SINGLE,
                               &(stamp_field_info.stamp_16_shift));
    dbal_value_field32_request(unit, entry_handle_id, DBAL_FIELD_STMP_16_BIT_VALUE, INST_SINGLE,
                               &(stamp_field_info.stamp_16_value));

    dbal_value_field32_request(unit, entry_handle_id, DBAL_FIELD_CNTR_8_BIT_ENABLE, INST_SINGLE,
                               &(stamp_field_info.counter_8_ena));
    dbal_value_field32_request(unit, entry_handle_id, DBAL_FIELD_CNTR_8_BIT_OFFSET, INST_SINGLE,
                               &(stamp_field_info.counter_8_offset));
    dbal_value_field32_request(unit, entry_handle_id, DBAL_FIELD_CNTR_8_BIT_SHIFT, INST_SINGLE,
                               &(stamp_field_info.counter_8_shift));
    dbal_value_field32_request(unit, entry_handle_id, DBAL_FIELD_CNTR_8_BIT_MASK, INST_SINGLE,
                               &(stamp_field_info.counter_8_mask));
    dbal_value_field32_request(unit, entry_handle_id, DBAL_FIELD_CNTR_8_BIT_INC_STEP, INST_SINGLE,
                               &(stamp_field_info.counter_8_inc_step));
    dbal_value_field32_request(unit, entry_handle_id, DBAL_FIELD_CNTR_8_BIT_PERIOD, INST_SINGLE,
                               &(stamp_field_info.counter_8_period));

    dbal_value_field32_request(unit, entry_handle_id, DBAL_FIELD_CNTR_16_BIT_ENABLE, INST_SINGLE,
                               &(stamp_field_info.counter_16_ena));
    dbal_value_field32_request(unit, entry_handle_id, DBAL_FIELD_CNTR_16_BIT_OFFSET, INST_SINGLE,
                               &(stamp_field_info.counter_16_offset));
    dbal_value_field32_request(unit, entry_handle_id, DBAL_FIELD_CNTR_16_BIT_SHIFT, INST_SINGLE,
                               &(stamp_field_info.counter_16_shift));
    dbal_value_field32_request(unit, entry_handle_id, DBAL_FIELD_CNTR_16_BIT_MASK, INST_SINGLE,
                               &(stamp_field_info.counter_16_mask));
    dbal_value_field32_request(unit, entry_handle_id, DBAL_FIELD_CNTR_16_BIT_INC_STEP, INST_SINGLE,
                               &(stamp_field_info.counter_16_inc_step));
    dbal_value_field32_request(unit, entry_handle_id, DBAL_FIELD_CNTR_16_BIT_PERIOD, INST_SINGLE,
                               &(stamp_field_info.counter_16_period));

    dbal_value_field32_request(unit, entry_handle_id, DBAL_FIELD_SEQ_NUM_ENABLE, INST_SINGLE, &sequence_ena);
    dbal_value_field32_request(unit, entry_handle_id, DBAL_FIELD_SEQ_NUM_OFFSET, INST_SINGLE, &sequence_offset);
    dbal_value_field32_request(unit, entry_handle_id, DBAL_FIELD_SEQ_NUM_PERIOD, INST_SINGLE, &sequence_period);

    dbal_value_field32_request(unit, entry_handle_id, DBAL_FIELD_ADD_END_TLV, INST_SINGLE, &pkt_add_tlv);
    dbal_value_field32_request(unit, entry_handle_id, DBAL_FIELD_CRC_32_ENABLE, INST_SINGLE, &pkt_add_crc);
    dbal_value_field32_request(unit, entry_handle_id, DBAL_FIELD_CRC_32_OFFSET, INST_SINGLE, &crc_offset);

    dbal_value_field32_request(unit, entry_handle_id, DBAL_FIELD_FLOW_CORE_ID, INST_SINGLE,
                               &(config->packet_context_id));

    SHR_IF_ERR_EXIT(dbal_entry_get(unit, entry_handle_id, DBAL_COMMIT));
    SHR_IF_ERR_EXIT(dnx_sat_gtf_config_rate_get
                    (unit, gtf_id, &gtf_config_rate, &gtf_rate_factor, &config->offsets.packet_length_compensation));

    for (ii = 0; ii < DNX_SAT_GTF_PACKET_LENGTH_NUM_OF_PATTERNS; ii++)
    {
        config->packet_edit[0].packet_length[ii] = packet_length[ii];
    }

    config->packet_edit[0].pattern_length = length_pattern_size + 1;
    offset = 0;
    for (ii = 0; ii < config->packet_edit[0].pattern_length; ii++)
    {
        SHR_BITCOPY_RANGE(&(config->packet_edit[0].packet_length_pattern[ii]), 0, length_pattern, offset, 3);
        offset += 3;
    }

    if (payload_type == 0)
    {
        rv = dnx_sat_packet_config_exp_payload_long_to_uint8(config->payload.payload_pattern,
                                                             DNX_SAT_PAYLOAD_MAX_PATTERN_NOF_U8, 0,
                                                             payload_rpt_pattern);
        SHR_IF_ERR_EXIT(rv);
        config->payload.payload_type = bcmSatPayloadConstant8Bytes;
    }
    else if (payload_type == 1)
    {
        rv = dnx_sat_packet_config_exp_payload_long_to_uint8(config->payload.payload_pattern,
                                                             DNX_SAT_PAYLOAD_MAX_PATTERN_NOF_U8 / 2, 0,
                                                             payload_rpt_pattern);
        SHR_IF_ERR_EXIT(rv);
        config->payload.payload_type = bcmSatPayloadConstant4Bytes;
    }
    else if (payload_type == 2)
    {
        config->payload.payload_type = bcmSatPayloadPRBS;
    }

    rv = dnx_sat_gtf_get_stamp_field(unit, &(config->packet_edit[0]), &(stamp_field_info));
    SHR_IF_ERR_EXIT(rv);

    if (sequence_ena)
    {
        config->offsets.seq_number_offset = sequence_offset;
        config->packet_edit[0].number_of_ctfs = sequence_period + 1;
    }
    else
    {
        config->offsets.seq_number_offset = DNX_SAT_GTF_SEQ_NUM_DISABLE;
    }

    if (pkt_add_tlv)
    {
        config->packet_edit[0].flags = config->packet_edit[0].flags | BCM_SAT_GTF_PACKET_EDIT_ADD_END_TLV;
    }

    if (pkt_add_crc)
    {
        config->packet_edit[0].flags = config->packet_edit[0].flags | BCM_SAT_GTF_PACKET_EDIT_ADD_CRC;
        config->offsets.crc_byte_offset = crc_offset;
    }

exit:
    dnx_sat_dynamic_memory_access_set(unit, 0);
    DBAL_FUNC_FREE_VARS;
    SHR_FUNC_EXIT;
}

static shr_error_e
dnx_sat_gtf_packet_config_set_verify(
    int unit,
    bcm_sat_gtf_t gtf_id,
    bcm_sat_gtf_packet_config_t * config)
{
    int priority;
    int ii = 0;
    uint8 is_allocated = 0;
    int max_seq_number_offset = 0;
    int max_crc_byte_offset = 0;
    float avg_gtf_pkt_len = 0;
    int total_gtf_pkt_len = 0;
    int gtf_num = 0;
    uint32 gtf_config_rate, old_pkt_len_compensation;
    int old_gtf_pkt_len_crt;
    uint32 gtf_rate_compensation;
    int nof_cores = dnx_data_device.general.nof_cores_get(unit);
    int stamp_count[bcmSatStampCount] = { 0 };

    SHR_FUNC_INIT_VARS(unit);
    DNX_SAT_IS_SUPPORTED_CHECK(unit);

    SHR_RANGE_VERIFY(gtf_id, DNX_SAT_GTF_ID_MIN, DNX_SAT_GTF_ID_MAX, _SHR_E_PARAM, "gtf_id");
    SHR_RANGE_VERIFY(config->sat_header_type, bcmSatHeaderUserDefined, bcmSatHeaderY1731, _SHR_E_PARAM,
                     "sat_header_type only support UserDefined");
    SHR_NULL_CHECK(config->header_info.pkt_data, _SHR_E_PARAM, "config->header_info.pkt_data");
    SHR_RANGE_VERIFY(config->header_info.pkt_data[0].len, DNX_SAT_GTF_PKT_HDR_LEN_MIN,
                     (DNX_SAT_GTF_PKT_HDR_LEN_MAX), _SHR_E_PARAM, "header_info.pkt_data[0].len");
    SHR_RANGE_VERIFY(config->payload.payload_type, bcmSatPayloadConstant8Bytes, (bcmSatPayloadsCount - 1), _SHR_E_PARAM,
                     "payload_type");
    SHR_MAX_VERIFY(config->packet_context_id, (nof_cores - 1), _SHR_E_PARAM, "packet_context_id");
    SHR_IF_ERR_EXIT(dnx_sat_max_value_get(unit, dnxSATGtfSeqNumOffset, &max_seq_number_offset));
    SHR_IF_ERR_EXIT(dnx_sat_max_value_get(unit, dnxSATGtfCrcOffset, &max_crc_byte_offset));
    SHR_MAX_VERIFY(config->offsets.seq_number_offset, max_seq_number_offset, _SHR_E_PARAM, "max_seq_number_offset");
    SHR_MAX_VERIFY(config->offsets.crc_byte_offset, max_crc_byte_offset, _SHR_E_PARAM, "max_crc_byte_offset");

    SHR_IF_ERR_EXIT(algo_sat_db.sat_res_alloc_gtf_id.is_allocated(unit, gtf_id, &is_allocated));

    if (!is_allocated)
    {
        SHR_ERR_EXIT(_SHR_E_NOT_FOUND, "Error: gtf_id  %d does not exist\n", gtf_id);
    }

    for (priority = 0; priority < (BCM_SAT_GTF_NUM_OF_PRIORITIES - 1); priority++)
    {
        SHR_RANGE_VERIFY(config->packet_edit[priority].pattern_length, 1, BCM_SAT_GTF_PACKET_MAX_PATTERN_LENGTH,
                         _SHR_E_PARAM, "pattern_length");

        for (ii = 0; ii < config->packet_edit[priority].pattern_length; ii++)
        {
            SHR_MAX_VERIFY(config->packet_edit[priority].packet_length_pattern[ii],
                           DNX_SAT_GTF_PKT_LEN_PATN_INX_MAX, _SHR_E_PARAM, "packet_length_pattern");
        }
        for (ii = 0; ii < BCM_SAT_GTF_PACKET_LENGTH_NUM_OF_PATTERNS; ii++)
        {
            if ((config->packet_edit[priority].packet_length[ii] != 0)
                && (config->packet_edit[priority].packet_length[ii] < dnx_data_sat.generator.gtf_min_pkt_len_get(unit)))
            {
                SHR_ERR_EXIT(_SHR_E_PARAM, "packet length must be larger than %d\n",
                             dnx_data_sat.generator.gtf_min_pkt_len_get(unit) - 1);
            }
            if (config->packet_edit[priority].packet_length[ii])
            {
                total_gtf_pkt_len += config->packet_edit[priority].packet_length[ii];
                gtf_num++;
            }
        }
        SHR_MAX_VERIFY(config->packet_edit[priority].number_of_stamps, BCM_SAT_GTF_MAX_STAMPS,
                       _SHR_E_PARAM, "number_of_stamps");
        SHR_RANGE_VERIFY(config->packet_edit[priority].number_of_ctfs, DNX_SAT_GTF_SEQ_PERIOD_MIN,
                         DNX_SAT_GTF_SEQ_PERIOD_MAX, _SHR_E_PARAM, "number_of_ctfs");

        stamp_count[bcmSatStampConstant2Bit] = stamp_count[bcmSatStampCounter8Bit] =
            stamp_count[bcmSatStampCounter16Bit] = 0;
        for (ii = 0; ii < BCM_SAT_GTF_MAX_STAMPS; ii++)
        {
            SHR_RANGE_VERIFY(config->packet_edit[priority].stamps[ii].stamp_type, bcmSatStampInvalid,
                             (bcmSatStampCount - 1), _SHR_E_PARAM, "stamp_type");
            SHR_RANGE_VERIFY(config->packet_edit[priority].stamps[ii].field_type, bcmSatStampFieldUserDefined,
                             (bcmSatStampFieldsCount - 1), _SHR_E_PARAM, "stamp_field_type");

            if ((config->packet_edit[priority].stamps[ii].stamp_type == bcmSatStampCounter8Bit) ||
                (config->packet_edit[priority].stamps[ii].stamp_type == bcmSatStampCounter16Bit))
            {
                SHR_RANGE_VERIFY(config->packet_edit[priority].stamps[ii].inc_step, DNX_SAT_GTF_STAMP_INC_STEP_MIN,
                                 _SHR_E_PARAM, DNX_SAT_GTF_STAMP_INC_STEP_MAX, "stamp_inc_step");
                SHR_MAX_VERIFY(config->packet_edit[priority].stamps[ii].inc_period_packets,
                               DNX_SAT_GTF_STAMP_INC_PERIOD_MAX, _SHR_E_PARAM, "stamp_inc_period_packets");
            }
            else if (config->packet_edit[priority].stamps[ii].stamp_type == bcmSatStampConstant2Bit)
            {
                SHR_ERR_EXIT(BCM_E_PARAM, "Jericho 2 support 16bits constant rather than 2 bits\n");
            }
            else if (config->packet_edit[priority].stamps[ii].stamp_type == bcmSatStampConstant16Bit)
            {
                SHR_MAX_VERIFY(config->packet_edit[priority].stamps[ii].value,
                               DNX_SAT_GTF_STAMP_16_bit_VALUE_MAX, _SHR_E_PARAM, "stamp_value");
            }
            stamp_count[config->packet_edit[priority].stamps[ii].stamp_type]++;
        }

        if ((stamp_count[bcmSatStampConstant2Bit] > 1) ||
            (stamp_count[bcmSatStampCounter8Bit] > 1) ||
            (stamp_count[bcmSatStampCounter16Bit] > 1) || (stamp_count[bcmSatStampConstant16Bit] > 1))
        {
            SHR_ERR_EXIT(BCM_E_PARAM,
                         " a CIR/EIR can have only one 2bit stamp, one 8bit counter and one 16bit counter\n");
        }
    }
    if (gtf_num)
    {
        avg_gtf_pkt_len = (float) total_gtf_pkt_len / gtf_num;
        SHR_RANGE_VERIFY(config->offsets.packet_length_compensation, (int) (0 - avg_gtf_pkt_len + 1),
                         (int) avg_gtf_pkt_len, _SHR_E_PARAM, "gtf packet length compensation");
        gtf_rate_compensation =
            (int) ((avg_gtf_pkt_len / (avg_gtf_pkt_len + config->offsets.packet_length_compensation)) *
                   DNX_SAT_GTF_RATE_CMP_CONVERSION);
        SHR_IF_ERR_EXIT(dnx_sat_gtf_config_rate_get
                        (unit, gtf_id, &gtf_config_rate, &old_pkt_len_compensation, &old_gtf_pkt_len_crt));
        gtf_config_rate = gtf_config_rate * ((float) gtf_rate_compensation / DNX_SAT_GTF_RATE_CMP_CONVERSION);
        SHR_MAX_VERIFY(gtf_config_rate, DNX_SAT_GTF_BW_PPS_RATE_MAX, _SHR_E_PARAM, "gtf max rate");
    }
    else
    {
        SHR_ERR_EXIT(_SHR_E_PARAM, "Error: all packet length zero for gtf %d\n", gtf_id);
    }
exit:
    SHR_FUNC_EXIT;
}

shr_error_e
bcm_dnx_sat_gtf_packet_config_set(
    int unit,
    bcm_sat_gtf_t gtf_id,
    bcm_sat_gtf_packet_config_t * config)
{
    bcm_sat_gtf_packet_config_t *dnx_pkt_cfg = NULL;
    int ii = 0;
    dnx_sat_data_t psat_data;
    uint8 pkt_data[128];
    dnx_sat_gtf_pkt_hdr_tbl_info_t header_tbl_data;
    int priority;
    int old_profile = 0;
    int new_profile = 0;
    int is_allocated = 0;
    int is_last = 0;
    uint32 gtf_rate_factor = DNX_SAT_GTF_RATE_CMP_CONVERSION;
    float avg_gtf_pkt_len = 0;
    int total_gtf_pkt_len = 0;
    bcm_sat_gtf_bandwidth_t bw;
    int gtf_num = 0;
    uint16 saved_pkt_header_base = 0;
    uint32 saved_pkt_header_len = 0;
    int pkt_header_base = 0;

    SHR_FUNC_INIT_VARS(unit);
    DNX_ERR_RECOVERY_START(unit);
    LOG_VERBOSE(BSL_LS_BCM_SAT, ("%s %d: u(%d) gtf_id(%d)\n", BSL_FUNC, BSL_LINE, unit, gtf_id));

    SHR_INVOKE_VERIFY_DNXC(dnx_sat_gtf_packet_config_set_verify(unit, gtf_id, config));

    sal_memset(&header_tbl_data, 0, sizeof(header_tbl_data));
    sal_memset(&psat_data, 0, sizeof(dnx_sat_data_t));
    SHR_IF_ERR_EXIT(dnx_sat_data_get(unit, &psat_data));

    SHR_IF_ERR_EXIT(bcm_dnx_sat_gtf_bandwidth_get(unit, gtf_id, 0, &bw));
    SHR_MAX_VERIFY(bw.rate * ((float) gtf_rate_factor / DNX_SAT_GTF_RATE_CMP_CONVERSION),
                   DNX_SAT_GTF_BW_PPS_RATE_MAX, _SHR_E_PARAM, "gtf max rate");

    priority = 0;

    for (ii = 0; ii < BCM_SAT_GTF_PACKET_LENGTH_NUM_OF_PATTERNS; ii++)
    {
        if (config->packet_edit[priority].packet_length[ii])
        {
            total_gtf_pkt_len += config->packet_edit[priority].packet_length[ii];
            gtf_num++;
        }
    }

    if (gtf_num)
    {
        avg_gtf_pkt_len = (float) total_gtf_pkt_len / gtf_num;
        gtf_rate_factor =
            (int) ((avg_gtf_pkt_len / (avg_gtf_pkt_len + config->offsets.packet_length_compensation)) *
                   DNX_SAT_GTF_RATE_CMP_CONVERSION);
    }

    SHR_IF_ERR_EXIT(dnx_sat_gtf_config_rate_set
                    (unit, gtf_id, bw.rate, gtf_rate_factor, config->offsets.packet_length_compensation));
    SHR_IF_ERR_EXIT(dnx_sat_gtf_bandwidth_set(unit, gtf_id, priority, &bw, gtf_rate_factor));

    SHR_NULL_CHECK(config, _SHR_E_PARAM, "config ");

    dnx_sat_packet_config_dump(config);

    SHR_ALLOC(dnx_pkt_cfg, sizeof(bcm_sat_gtf_packet_config_t), "dnx_sat_gtf_packet_config", "%s%s%s\r\n", EMPTY, EMPTY,
              EMPTY);
    if (dnx_pkt_cfg == NULL)
    {
        SHR_ERR_EXIT(_SHR_E_MEMORY, "unit %d, failed to allocate gtf packet memory \n", unit);
    }

    sal_memset(dnx_pkt_cfg, 0, sizeof(bcm_sat_gtf_packet_config_t));

    dnx_pkt_cfg->header_info.pkt_data = &(dnx_pkt_cfg->header_info._pkt_data);
    dnx_pkt_cfg->header_info.blk_count = 1;
    dnx_pkt_cfg->header_info.pkt_data[0].data = pkt_data;
    dnx_pkt_cfg->header_info.pkt_data[0].len = config->header_info.pkt_data[0].len;
    sal_memcpy(dnx_pkt_cfg->header_info.pkt_data[0].data, config->header_info.pkt_data[0].data,
               sizeof(uint8) * config->header_info.pkt_data[0].len);
    dnx_pkt_cfg->payload.payload_type = config->payload.payload_type;
    sal_memcpy(dnx_pkt_cfg->payload.payload_pattern, config->payload.payload_pattern,
               sizeof(uint8) * BCM_SAT_PAYLOAD_MAX_PATTERN_SIZE);
    for (priority = 0; priority < (BCM_SAT_GTF_NUM_OF_PRIORITIES - 1); priority++)
    {
        sal_memcpy(dnx_pkt_cfg->packet_edit[priority].packet_length, config->packet_edit[priority].packet_length,
                   sizeof(uint32) * BCM_SAT_GTF_PACKET_LENGTH_NUM_OF_PATTERNS);
        sal_memcpy(dnx_pkt_cfg->packet_edit[priority].packet_length_pattern,
                   config->packet_edit[priority].packet_length_pattern,
                   sizeof(uint32) * BCM_SAT_GTF_PACKET_MAX_PATTERN_LENGTH);
        dnx_pkt_cfg->packet_edit[priority].pattern_length = config->packet_edit[priority].pattern_length;

        dnx_pkt_cfg->packet_edit[priority].number_of_stamps = config->packet_edit[priority].number_of_stamps;
        for (ii = 0; ii < config->packet_edit[priority].number_of_stamps; ii++)
        {
            dnx_pkt_cfg->packet_edit[priority].stamps[ii].stamp_type =
                config->packet_edit[priority].stamps[ii].stamp_type;
            dnx_pkt_cfg->packet_edit[priority].stamps[ii].field_type =
                config->packet_edit[priority].stamps[ii].field_type;
            if ((config->packet_edit[priority].stamps[ii].stamp_type == bcmSatStampCounter8Bit)
                || (config->packet_edit[priority].stamps[ii].stamp_type == bcmSatStampCounter16Bit))
            {
                dnx_pkt_cfg->packet_edit[priority].stamps[ii].inc_step =
                    config->packet_edit[priority].stamps[ii].inc_step;
                dnx_pkt_cfg->packet_edit[priority].stamps[ii].inc_period_packets =
                    config->packet_edit[priority].stamps[ii].inc_period_packets;
            }
            else if ((config->packet_edit[priority].stamps[ii].stamp_type == bcmSatStampConstant2Bit) ||
                     (config->packet_edit[priority].stamps[ii].stamp_type == bcmSatStampConstant16Bit))
            {
                dnx_pkt_cfg->packet_edit[priority].stamps[ii].value = config->packet_edit[priority].stamps[ii].value;
            }
            dnx_pkt_cfg->packet_edit[priority].stamps[ii].offset = config->packet_edit[priority].stamps[ii].offset;
        }
        dnx_pkt_cfg->packet_edit[priority].number_of_ctfs = config->packet_edit[priority].number_of_ctfs;
        if (config->packet_edit[priority].flags & BCM_SAT_GTF_PACKET_EDIT_ADD_END_TLV)
        {
            dnx_pkt_cfg->packet_edit[priority].flags |= BCM_SAT_GTF_PACKET_EDIT_ADD_END_TLV;
        }
        if (config->packet_edit[priority].flags & BCM_SAT_GTF_PACKET_EDIT_ADD_CRC)
        {
            dnx_pkt_cfg->packet_edit[priority].flags |= BCM_SAT_GTF_PACKET_EDIT_ADD_CRC;
        }
    }
    dnx_pkt_cfg->packet_context_id = config->packet_context_id;
    dnx_pkt_cfg->offsets.seq_number_offset = config->offsets.seq_number_offset;
    dnx_pkt_cfg->offsets.crc_byte_offset = config->offsets.crc_byte_offset;
    dnx_pkt_cfg->offsets.packet_length_compensation = config->offsets.packet_length_compensation;

    old_profile = psat_data.gtf_header_id[gtf_id];

    SHR_IF_ERR_EXIT(dnx_am_template_sat_pkt_header_length_get(unit, old_profile, &saved_pkt_header_len));

    SHR_IF_ERR_EXIT(sat_pkt_header_info.pkt_header_base.get(unit, old_profile, &saved_pkt_header_base));

    SHR_IF_ERR_EXIT(dnx_sat_gtf_construct_packet_header(unit, &(dnx_pkt_cfg->header_info), &header_tbl_data));
    SHR_IF_ERR_EXIT(dnx_am_template_sat_pkt_header_exchange
                    (unit, 0, &header_tbl_data, old_profile, &is_last, &new_profile, &is_allocated));

    psat_data.gtf_header_id[gtf_id] = new_profile;

    SHR_IF_ERR_EXIT(dnx_sat_data_set(unit, &psat_data));

    pkt_header_base = saved_pkt_header_base;

    if (is_allocated)
    {

        SHR_IF_ERR_EXIT(dnx_sat_pkt_header_mem_allocate
                        (unit, (header_tbl_data.pkt_header_len + 4) / 4, &pkt_header_base));

        LOG_VERBOSE(BSL_LS_BCM_SAT, ("%s %d: u(%d) gtf_id(%d) new_profile %d pkt_header_base %d\n", BSL_FUNC, BSL_LINE,
                                     unit, gtf_id, new_profile, pkt_header_base));

        SHR_IF_ERR_EXIT(sat_pkt_header_info.pkt_header_base.set(unit, new_profile, pkt_header_base));

        SHR_IF_ERR_EXIT(dnx_sat_gtf_packet_header_config_set(unit, pkt_header_base, &header_tbl_data));
    }

    if (is_last || (is_allocated && (new_profile == old_profile)))
    {

        SHR_IF_ERR_EXIT(dnx_sat_gtf_packet_header_config_clean(unit, saved_pkt_header_base, saved_pkt_header_len));

        SHR_IF_ERR_EXIT(dnx_sat_pkt_header_mem_free(unit, (saved_pkt_header_len + 4) / 4, saved_pkt_header_base));

        if (old_profile != new_profile)
        {

            SHR_IF_ERR_EXIT(sat_pkt_header_info.pkt_header_base.set(unit, old_profile, 0));
        }
    }

    SHR_IF_ERR_EXIT(dnx_sat_gtf_packet_config_set
                    (unit, gtf_id, pkt_header_base, header_tbl_data.pkt_header_len, dnx_pkt_cfg));

exit:
    DNX_ERR_RECOVERY_END(unit);
    SHR_FREE(dnx_pkt_cfg);
    SHR_FUNC_EXIT;

}

shr_error_e
bcm_dnx_sat_gtf_packet_config(
    int unit,
    bcm_sat_gtf_t gtf_id,
    bcm_sat_gtf_packet_config_t * config)
{

    SHR_FUNC_INIT_VARS(unit);
    DNX_ERR_RECOVERY_START(unit);
    SHR_IF_ERR_EXIT(bcm_dnx_sat_gtf_packet_config_set(unit, gtf_id, config));

exit:
    DNX_ERR_RECOVERY_END(unit);
    SHR_FUNC_EXIT;
}

static shr_error_e
dnx_sat_gtf_packet_config_get_verify(
    int unit,
    bcm_sat_gtf_t gtf_id,
    bcm_sat_gtf_packet_config_t * config)
{
    SHR_FUNC_INIT_VARS(unit);
    DNX_SAT_IS_SUPPORTED_CHECK(unit);
    SHR_NULL_CHECK(config, _SHR_E_PARAM, "config ");
    SHR_NULL_CHECK(config->header_info.pkt_data, _SHR_E_PARAM, "config->header_info.pkt_data");
    SHR_RANGE_VERIFY(gtf_id, DNX_SAT_GTF_ID_MIN, DNX_SAT_GTF_ID_MAX, _SHR_E_PARAM, "gtf_id");
    SHR_EXIT();
exit:
    SHR_FUNC_EXIT;
}

shr_error_e
bcm_dnx_sat_gtf_packet_config_get(
    int unit,
    bcm_sat_gtf_t gtf_id,
    bcm_sat_gtf_packet_config_t * config)
{
    dnx_sat_gtf_pkt_hdr_tbl_info_t header_tbl_data;
    uint32 header_id = 0;
    dnx_sat_data_t psat_data;

    SHR_FUNC_INIT_VARS(unit);
    DNX_ERR_RECOVERY_START(unit);

    SHR_INVOKE_VERIFY_DNXC(dnx_sat_gtf_packet_config_get_verify(unit, gtf_id, config));

    LOG_VERBOSE(BSL_LS_BCM_SAT, ("%s %d: u(%d) gtf_id(%d)\n", BSL_FUNC, BSL_LINE, unit, gtf_id));

    sal_memset(&header_tbl_data, 0, sizeof(header_tbl_data));
    sal_memset(&psat_data, 0, sizeof(dnx_sat_data_t));
    SHR_IF_ERR_EXIT(dnx_sat_data_get(unit, &psat_data));
    header_id = psat_data.gtf_header_id[gtf_id];

    SHR_IF_ERR_EXIT(dnx_sat_gtf_packet_header_config_get(unit, header_id, &header_tbl_data););
    SHR_IF_ERR_EXIT(dnx_sat_gtf_get_packet_header(unit, &(config->header_info), &header_tbl_data));
    SHR_IF_ERR_EXIT(dnx_sat_gtf_packet_config_get(unit, gtf_id, config));

exit:
    DNX_ERR_RECOVERY_END(unit);
    SHR_FUNC_EXIT;
}

static shr_error_e
dnx_sat_gtf_packet_start_verify(
    int unit,
    bcm_sat_gtf_t gtf_id)
{
    int packet_length = 0;
    bcm_sat_gtf_packet_config_t config;
    SHR_FUNC_INIT_VARS(unit);

    SHR_IF_ERR_EXIT(dnx_sat_gtf_packet_config_get(unit, gtf_id, &config));
    for (int ii = 0; ii < DNX_SAT_GTF_PACKET_LENGTH_NUM_OF_PATTERNS; ii++)
    {
        packet_length += config.packet_edit[0].packet_length[ii];
    }
    if (!packet_length)
    {
        SHR_ERR_EXIT(_SHR_E_PARAM, "packet config for gtf(%d) not exist\n", gtf_id);
    }

exit:
    SHR_FUNC_EXIT;
}

shr_error_e
bcm_dnx_sat_gtf_packet_start(
    int unit,
    bcm_sat_gtf_t gtf_id,
    bcm_sat_gtf_pri_t priority)
{
    uint32 is_paired = 0;

    SHR_FUNC_INIT_VARS(unit);
    DNX_ERR_RECOVERY_START(unit);
    DNX_SAT_IS_SUPPORTED_CHECK(unit);

    if (DNX_SAT_GTF_ID_IS_VALID_EVC_ID(gtf_id))
    {
        SHR_IF_ERR_EXIT(dnx_sat_gtf_is_paired_get(unit, gtf_id, &is_paired));
    }

    if (!is_paired && (priority != bcmSatGtfPriCir))
    {
        LOG_WARN(BSL_LS_BCM_SAT, ("GTF is not paired but priority is not CIR, ignore priority\n"));
        priority = bcmSatGtfPriCir;
    }

    SHR_INVOKE_VERIFY_DNXC(dnx_sat_gtf_id_priority_verify(unit, gtf_id, priority));
    SHR_INVOKE_VERIFY_DNXC(dnx_sat_gtf_packet_start_verify(unit, gtf_id));

    LOG_VERBOSE(BSL_LS_BCM_SAT, ("%s %d: u(%d) gtf_id(%d) priority(%d)\n", BSL_FUNC, BSL_LINE, unit, gtf_id, priority));

    if ((priority == bcmSatGtfPriCir) || (priority == bcmSatGtfPriAll))
    {

        SHR_IF_ERR_EXIT(dnx_sat_gtf_packet_gen_set(unit, gtf_id, 1));
    }

    if ((priority == bcmSatGtfPriEir) || (priority == bcmSatGtfPriAll))
    {

        SHR_IF_ERR_EXIT(dnx_sat_gtf_packet_gen_set(unit, gtf_id + 1, 1));
    }

exit:
    DNX_ERR_RECOVERY_END(unit);
    SHR_FUNC_EXIT;
}

shr_error_e
bcm_dnx_sat_gtf_packet_stop(
    int unit,
    bcm_sat_gtf_t gtf_id,
    bcm_sat_gtf_pri_t priority)
{
    uint32 is_paired = 0;

    SHR_FUNC_INIT_VARS(unit);
    DNX_ERR_RECOVERY_START(unit);
    DNX_SAT_IS_SUPPORTED_CHECK(unit);

    if (DNX_SAT_GTF_ID_IS_VALID_EVC_ID(gtf_id))
    {
        SHR_IF_ERR_EXIT(dnx_sat_gtf_is_paired_get(unit, gtf_id, &is_paired));
    }

    if (!is_paired && (priority != bcmSatGtfPriCir))
    {
        LOG_WARN(BSL_LS_BCM_SAT, ("GTF is not paired but priority is not CIR, ignore priority\n"));
        priority = bcmSatGtfPriCir;
    }

    SHR_INVOKE_VERIFY_DNXC(dnx_sat_gtf_id_priority_verify(unit, gtf_id, priority));

    LOG_VERBOSE(BSL_LS_BCM_SAT, ("%s %d: u(%d) gtf_id(%d) priority(%d)\n", BSL_FUNC, BSL_LINE, unit, gtf_id, priority));

    if ((priority == bcmSatGtfPriCir) || (priority == bcmSatGtfPriAll))
    {

        SHR_IF_ERR_EXIT(dnx_sat_gtf_packet_gen_set(unit, gtf_id, 0));
    }

    if ((priority == bcmSatGtfPriEir) || (priority == bcmSatGtfPriAll))
    {

        SHR_IF_ERR_EXIT(dnx_sat_gtf_packet_gen_set(unit, gtf_id + 1, 0));
    }

exit:
    DNX_ERR_RECOVERY_END(unit);
    SHR_FUNC_EXIT;
}

static shr_error_e
dnx_sat_gtf_rate_pattern_get(
    int unit,
    bcm_sat_gtf_t gtf_id,
    bcm_sat_gtf_rate_pattern_t * config)
{
    uint32 entry_handle_id;
    uint32 high_mnt_val = 0, high_exp_val = 0, low_mnt_val = 0, low_exp_val = 0;
    uint32 interval_cnt_to_cfg;
    uint32 rate_pattern_mode = 0;
    uint32 complex = 0;

    SHR_FUNC_INIT_VARS(unit);
    DBAL_FUNC_INIT_VARS(unit);

    SHR_IF_ERR_EXIT(DBAL_HANDLE_ALLOC(unit, DBAL_TABLE_SAT_TX_RATE_CONTROL, &entry_handle_id));

    dbal_entry_key_field8_set(unit, entry_handle_id, DBAL_FIELD_TX_FLOW_ID, gtf_id);

    dbal_value_field32_request(unit, entry_handle_id, DBAL_FIELD_THRESHOLD_UPPER_MANTISSA, INST_SINGLE, &high_mnt_val);
    dbal_value_field32_request(unit, entry_handle_id, DBAL_FIELD_THRESHOLD_UPPER_EXPONENT, INST_SINGLE, &high_exp_val);
    dbal_value_field32_request(unit, entry_handle_id, DBAL_FIELD_THRESHOLD_LOWER_MANTISSA, INST_SINGLE, &low_mnt_val);
    dbal_value_field32_request(unit, entry_handle_id, DBAL_FIELD_THRESHOLD_LOWER_EXPONENT, INST_SINGLE, &low_exp_val);

    dbal_value_field32_request(unit, entry_handle_id, DBAL_FIELD_STOP_ITER_CNT, INST_SINGLE,
                               &(config->stop_iter_count));
    dbal_value_field32_request(unit, entry_handle_id, DBAL_FIELD_STOP_BURST_CNT, INST_SINGLE,
                               &(config->stop_burst_count));
    dbal_value_field32_request(unit, entry_handle_id, DBAL_FIELD_STOP_INTERVAL_CNT, INST_SINGLE,
                               &(config->stop_interval_count));
    dbal_value_field32_request(unit, entry_handle_id, DBAL_FIELD_BURST_PKT_WEIGHT, INST_SINGLE,
                               &(config->burst_packet_weight));
    dbal_value_field32_request(unit, entry_handle_id, DBAL_FIELD_INTERVAL_PKT_WEIGHT, INST_SINGLE,
                               &(config->interval_packet_weight));

    dbal_value_field32_request(unit, entry_handle_id, DBAL_FIELD_BURST_MODE, INST_SINGLE, &rate_pattern_mode);

    dbal_value_field32_request(unit, entry_handle_id, DBAL_FIELD_SET_INTRVAL_CNT_TO_CFG, INST_SINGLE,
                               &interval_cnt_to_cfg);

    SHR_IF_ERR_EXIT(dbal_entry_get(unit, entry_handle_id, DBAL_COMMIT));

    if (interval_cnt_to_cfg == 0x1)
    {
        config->flags |= BCM_SAT_GTF_RATE_PATTERN_STOP_INTERVAL_EQ_BURST;
    }

    SHR_IF_ERR_EXIT(utilex_compute_complex_to_mnt_exp(high_mnt_val, high_exp_val, 1, 0, &complex));
    config->high_threshold = complex / 125;

    SHR_IF_ERR_EXIT(utilex_compute_complex_to_mnt_exp(low_mnt_val, low_exp_val, 1, 0, &complex));
    config->low_threshold = complex / 125;

    if (rate_pattern_mode == 0)
    {
        config->rate_pattern_mode = (config->high_threshold == config->low_threshold) ?
            bcmSatGtfRatePatternContinues : bcmSatGtfRatePatternSimpleBurst;
    }
    else if (rate_pattern_mode == 1)
    {
        config->rate_pattern_mode = bcmSatGtfRatePatternCombined;
    }
    else if (rate_pattern_mode == 3)
    {
        config->rate_pattern_mode = bcmSatGtfRatePatternInterval;
    }
    else
    {
        SHR_ERR_EXIT(_SHR_E_PARAM, "Fail   in parsing rate_pattern_mode(%d) \n", rate_pattern_mode);
    }

exit:
    DBAL_FUNC_FREE_VARS;
    SHR_FUNC_EXIT;
}

static shr_error_e
dnx_sat_evc_rate_pattern_get(
    int unit,
    bcm_sat_gtf_t gtf_id,
    bcm_sat_gtf_rate_pattern_t * config)
{
    uint32 entry_handle_id;
    uint32 high_mnt_val = 0, high_exp_val = 0, low_mnt_val = 0, low_exp_val = 0;
    uint32 complex = 0;
    int evc_id;

    SHR_FUNC_INIT_VARS(unit);
    DBAL_FUNC_INIT_VARS(unit);

    evc_id = gtf_id >> 1;

    SHR_IF_ERR_EXIT(DBAL_HANDLE_ALLOC(unit, DBAL_TABLE_SAT_EVC_TX_RATE_CONTROL, &entry_handle_id));

    dbal_entry_key_field8_set(unit, entry_handle_id, DBAL_FIELD_EVC_ID, evc_id);

    dbal_value_field32_request(unit, entry_handle_id, DBAL_FIELD_THRESHOLD_UPPER_MANTISSA, INST_SINGLE, &high_mnt_val);
    dbal_value_field32_request(unit, entry_handle_id, DBAL_FIELD_THRESHOLD_UPPER_EXPONENT, INST_SINGLE, &high_exp_val);
    dbal_value_field32_request(unit, entry_handle_id, DBAL_FIELD_THRESHOLD_LOWER_MANTISSA, INST_SINGLE, &low_mnt_val);
    dbal_value_field32_request(unit, entry_handle_id, DBAL_FIELD_THRESHOLD_LOWER_EXPONENT, INST_SINGLE, &low_exp_val);

    SHR_IF_ERR_EXIT(dbal_entry_get(unit, entry_handle_id, DBAL_COMMIT));

    SHR_IF_ERR_EXIT(utilex_compute_complex_to_mnt_exp(high_mnt_val, high_exp_val, 1, 0, &complex));
    config->high_threshold = complex / 125;

    SHR_IF_ERR_EXIT(utilex_compute_complex_to_mnt_exp(low_mnt_val, low_exp_val, 1, 0, &complex));
    config->low_threshold = complex / 125;

exit:
    DBAL_FUNC_FREE_VARS;
    SHR_FUNC_EXIT;
}

shr_error_e
bcm_dnx_sat_gtf_rate_pattern_get(
    int unit,
    bcm_sat_gtf_t gtf_id,
    int priority,
    bcm_sat_gtf_rate_pattern_t * config)
{
    bcm_sat_gtf_rate_pattern_t dnx_rate_pattern;
    bcm_sat_gtf_t gtf_to_get = gtf_id;
    uint32 is_paired = 0;

    SHR_FUNC_INIT_VARS(unit);
    DNX_ERR_RECOVERY_START(unit);
    DNX_SAT_IS_SUPPORTED_CHECK(unit);

    if (DNX_SAT_GTF_ID_IS_VALID_EVC_ID(gtf_id))
    {
        SHR_IF_ERR_EXIT(dnx_sat_gtf_is_paired_get(unit, gtf_id, &is_paired));
    }

    if (!is_paired && (priority != bcmSatGtfPriCir))
    {
        LOG_WARN(BSL_LS_BCM_SAT, ("GTF is not paired but priority is not CIR, ignore priority\n"));
        priority = bcmSatGtfPriCir;
    }

    SHR_INVOKE_VERIFY_DNXC(dnx_sat_gtf_id_priority_verify(unit, gtf_id, priority));
    SHR_NULL_CHECK(config, _SHR_E_PARAM, "config ");

    LOG_VERBOSE(BSL_LS_BCM_SAT, ("%s %d: u(%d) \n", BSL_FUNC, BSL_LINE, unit));

    if (priority == bcmSatGtfPriAll)
    {
        SHR_IF_ERR_EXIT(dnx_sat_evc_rate_pattern_get(unit, gtf_id, &dnx_rate_pattern));
        config->high_threshold = dnx_rate_pattern.high_threshold;
        config->low_threshold = dnx_rate_pattern.low_threshold;
    }
    else
    {
        if (priority == bcmSatGtfPriEir)
        {
            gtf_to_get += 1;
        }

        sal_memset(&dnx_rate_pattern, 0, sizeof(dnx_rate_pattern));
        SHR_IF_ERR_EXIT(dnx_sat_gtf_rate_pattern_get(unit, gtf_to_get, &dnx_rate_pattern));

        config->rate_pattern_mode = dnx_rate_pattern.rate_pattern_mode;
        config->high_threshold = dnx_rate_pattern.high_threshold;
        config->low_threshold = dnx_rate_pattern.low_threshold;
        config->stop_iter_count = dnx_rate_pattern.stop_iter_count;
        config->stop_burst_count = dnx_rate_pattern.stop_burst_count;
        config->stop_interval_count = dnx_rate_pattern.stop_interval_count;
        config->burst_packet_weight = dnx_rate_pattern.burst_packet_weight;
        config->interval_packet_weight = dnx_rate_pattern.interval_packet_weight;
        if (dnx_rate_pattern.flags & BCM_SAT_GTF_RATE_PATTERN_STOP_INTERVAL_EQ_BURST)
        {
            config->flags |= BCM_SAT_GTF_RATE_PATTERN_STOP_INTERVAL_EQ_BURST;
        }
    }

    SHR_EXIT();

exit:
    DNX_ERR_RECOVERY_END(unit);
    SHR_FUNC_EXIT;
}

static shr_error_e
dnx_sat_gtf_rate_pattern_set(
    int unit,
    bcm_sat_gtf_t gtf_id,
    bcm_sat_gtf_rate_pattern_t * config)
{
    uint32 entry_handle_id;
    uint32 up_mnt_nof_bits = 0, up_exp_nof_bits = 0;
    uint32 low_mnt_nof_bits = 0, low_exp_nof_bits = 0;
    uint32 high_mnt_val = 0, high_exp_val = 0, low_mnt_val = 0, low_exp_val = 0;
    uint32 field_data = 0;
    uint32 is_pkt_mode = 0;

    SHR_FUNC_INIT_VARS(unit);
    DBAL_FUNC_INIT_VARS(unit);

    SHR_IF_ERR_EXIT(DBAL_HANDLE_ALLOC(unit, DBAL_TABLE_SAT_TX_BANDWIDTH_CONTROL, &entry_handle_id));

    dbal_entry_key_field8_set(unit, entry_handle_id, DBAL_FIELD_TX_FLOW_ID, gtf_id);

    dbal_value_field32_request(unit, entry_handle_id, DBAL_FIELD_CREDITS_PER_PACKET_EN, INST_SINGLE, &is_pkt_mode);

    SHR_IF_ERR_EXIT(dbal_entry_get(unit, entry_handle_id, DBAL_COMMIT));

    SHR_IF_ERR_EXIT(dbal_tables_field_size_get
                    (unit, DBAL_TABLE_SAT_TX_RATE_CONTROL, DBAL_FIELD_THRESHOLD_UPPER_MANTISSA, FALSE, 0, 0,
                     (int *) (&up_mnt_nof_bits)));
    SHR_IF_ERR_EXIT(dbal_tables_field_size_get
                    (unit, DBAL_TABLE_SAT_TX_RATE_CONTROL, DBAL_FIELD_THRESHOLD_UPPER_EXPONENT, FALSE, 0, 0,
                     (int *) (&up_exp_nof_bits)));

    SHR_IF_ERR_EXIT(dbal_tables_field_size_get
                    (unit, DBAL_TABLE_SAT_TX_RATE_CONTROL, DBAL_FIELD_THRESHOLD_LOWER_MANTISSA, FALSE, 0, 0,
                     (int *) (&low_mnt_nof_bits)));
    SHR_IF_ERR_EXIT(dbal_tables_field_size_get
                    (unit, DBAL_TABLE_SAT_TX_RATE_CONTROL, DBAL_FIELD_THRESHOLD_LOWER_EXPONENT, FALSE, 0, 0,
                     (int *) (&low_exp_nof_bits)));

    SHR_IF_ERR_EXIT(utilex_break_to_mnt_exp_round_up
                    (is_pkt_mode ? config->high_threshold : (config->high_threshold * 125), up_mnt_nof_bits,
                     up_exp_nof_bits, 0, &high_mnt_val, &high_exp_val));
    SHR_IF_ERR_EXIT(utilex_break_to_mnt_exp_round_up
                    (is_pkt_mode ? config->low_threshold : (config->low_threshold * 125), low_mnt_nof_bits,
                     low_exp_nof_bits, 0, &low_mnt_val, &low_exp_val));

    if ((config->rate_pattern_mode == bcmSatGtfRatePatternContinues)
        || (config->rate_pattern_mode == bcmSatGtfRatePatternSimpleBurst))
    {
        field_data = 0;
    }
    else if (config->rate_pattern_mode == bcmSatGtfRatePatternCombined)
    {
        field_data = 1;
    }
    else if (config->rate_pattern_mode == bcmSatGtfRatePatternInterval)
    {
        field_data = 3;
    }
    else
    {
        SHR_ERR_EXIT(_SHR_E_PARAM, "Fail  rate_pattern_mode(%d) is not supported\n", config->rate_pattern_mode);
    }

    SHR_IF_ERR_EXIT(DBAL_HANDLE_ALLOC(unit, DBAL_TABLE_SAT_TX_RATE_CONTROL, &entry_handle_id));

    dbal_entry_key_field8_set(unit, entry_handle_id, DBAL_FIELD_TX_FLOW_ID, gtf_id);

    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_THRESHOLD_UPPER_MANTISSA, INST_SINGLE, high_mnt_val);
    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_THRESHOLD_UPPER_EXPONENT, INST_SINGLE, high_exp_val);
    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_THRESHOLD_LOWER_MANTISSA, INST_SINGLE, low_mnt_val);
    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_THRESHOLD_LOWER_EXPONENT, INST_SINGLE, low_exp_val);

    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_BURST_MODE, INST_SINGLE, field_data);
    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_STOP_ITER_CNT, INST_SINGLE, config->stop_iter_count);
    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_STOP_BURST_CNT, INST_SINGLE,
                                 config->stop_burst_count);
    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_STOP_INTERVAL_CNT, INST_SINGLE,
                                 config->stop_interval_count);
    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_BURST_PKT_WEIGHT, INST_SINGLE,
                                 config->burst_packet_weight);
    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_INTERVAL_PKT_WEIGHT, INST_SINGLE,
                                 config->interval_packet_weight);

    if (config->flags & BCM_SAT_GTF_RATE_PATTERN_STOP_INTERVAL_EQ_BURST)
    {
        dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_SET_INTRVAL_CNT_TO_CFG, INST_SINGLE, 1);
    }
    else
    {
        dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_SET_INTRVAL_CNT_TO_CFG, INST_SINGLE, 0);
    }

    SHR_IF_ERR_EXIT(dbal_entry_commit(unit, entry_handle_id, DBAL_COMMIT));

exit:
    DBAL_FUNC_FREE_VARS;
    SHR_FUNC_EXIT;
}

static shr_error_e
dnx_sat_gtf_rate_pattern_set_verify(
    int unit,
    bcm_sat_gtf_t gtf_id,
    bcm_sat_gtf_rate_pattern_t * config)
{
    int stop_iter_max = 0;
    SHR_FUNC_INIT_VARS(unit);

    SHR_NULL_CHECK(config, _SHR_E_PARAM, "config ");
    SHR_RANGE_VERIFY(config->high_threshold, DNX_SAT_GTF_RATE_PATN_HIGH_TH_MIN,
                     DNX_SAT_GTF_RATE_PATN_HIGH_TH_MAX, _SHR_E_PARAM, "high_threshold");
    SHR_RANGE_VERIFY(config->low_threshold, DNX_SAT_GTF_RATE_PATN_LOW_TH_MIN, DNX_SAT_GTF_RATE_PATN_LOW_TH_MAX,
                     _SHR_E_PARAM, "low_threshold");

    SHR_IF_ERR_EXIT(dnx_sat_max_value_get(unit, dnxSATGtfRateStopIter, &stop_iter_max));

    SHR_MAX_VERIFY(config->stop_iter_count, stop_iter_max, _SHR_E_PARAM, "stop_iter_count");

    if (config->rate_pattern_mode == bcmSatGtfRatePatternContinues)
    {
        if (config->high_threshold != config->low_threshold)
        {
            SHR_ERR_EXIT(_SHR_E_PARAM,
                         "Fail in continues mode, high_threshold(%d) should equals to low_threshold(%d)\n",
                         config->high_threshold, config->low_threshold);
        }
    }
    else if (config->rate_pattern_mode == bcmSatGtfRatePatternSimpleBurst)
    {
        if (config->high_threshold <= config->low_threshold)
        {
            SHR_ERR_EXIT(_SHR_E_PARAM,
                         "Fail in simplebusrt mode, high_threshold(%d) should greater to low_threshold(%d)\n",
                         config->high_threshold, config->low_threshold);
        }
    }
    else if (config->rate_pattern_mode == bcmSatGtfRatePatternCombined)
    {
        if (config->high_threshold < config->low_threshold)
        {
            SHR_ERR_EXIT(_SHR_E_PARAM,
                         "Fail in combined mode, high_threshold(%d) should greater or equal to low_threshold(%d)\n",
                         config->high_threshold, config->low_threshold);
        }
    }
    else if (config->rate_pattern_mode == bcmSatGtfRatePatternInterval)
    {
        if (config->high_threshold < config->low_threshold)
        {
            SHR_ERR_EXIT(_SHR_E_PARAM,
                         "Fail in interval mode, high_threshold(%d) should greater or equal to low_threshold(%d)\n",
                         config->high_threshold, config->low_threshold);
        }
    }
    else
    {
        SHR_ERR_EXIT(_SHR_E_PARAM, "Fail  rate_pattern_mode(%d) is not supported\n", config->rate_pattern_mode);
    }

    SHR_EXIT();
exit:
    SHR_FUNC_EXIT;
}

static shr_error_e
dnx_sat_evc_rate_pattern_set(
    int unit,
    bcm_sat_gtf_t gtf_id,
    bcm_sat_gtf_rate_pattern_t * config)
{
    uint32 entry_handle_id;
    uint32 up_mnt_nof_bits = 0, up_exp_nof_bits = 0;
    uint32 low_mnt_nof_bits = 0, low_exp_nof_bits = 0;
    uint32 high_mnt_val = 0, high_exp_val = 0, low_mnt_val = 0, low_exp_val = 0;
    uint32 is_pkt_mode = 0;
    int evc_id;

    SHR_FUNC_INIT_VARS(unit);
    DBAL_FUNC_INIT_VARS(unit);

    evc_id = gtf_id >> 1;

    SHR_IF_ERR_EXIT(DBAL_HANDLE_ALLOC(unit, DBAL_TABLE_SAT_EVC_TX_BANDWIDTH_CONTROL, &entry_handle_id));

    dbal_entry_key_field8_set(unit, entry_handle_id, DBAL_FIELD_EVC_ID, evc_id);

    dbal_value_field32_request(unit, entry_handle_id, DBAL_FIELD_CREDITS_PER_PACKET_EN, INST_SINGLE, &is_pkt_mode);

    SHR_IF_ERR_EXIT(dbal_entry_get(unit, entry_handle_id, DBAL_COMMIT));

    SHR_IF_ERR_EXIT(dbal_tables_field_size_get
                    (unit, DBAL_TABLE_SAT_TX_RATE_CONTROL, DBAL_FIELD_THRESHOLD_UPPER_MANTISSA, FALSE, 0, 0,
                     (int *) (&up_mnt_nof_bits)));
    SHR_IF_ERR_EXIT(dbal_tables_field_size_get
                    (unit, DBAL_TABLE_SAT_TX_RATE_CONTROL, DBAL_FIELD_THRESHOLD_UPPER_EXPONENT, FALSE, 0, 0,
                     (int *) (&up_exp_nof_bits)));

    SHR_IF_ERR_EXIT(dbal_tables_field_size_get
                    (unit, DBAL_TABLE_SAT_TX_RATE_CONTROL, DBAL_FIELD_THRESHOLD_LOWER_MANTISSA, FALSE, 0, 0,
                     (int *) (&low_mnt_nof_bits)));
    SHR_IF_ERR_EXIT(dbal_tables_field_size_get
                    (unit, DBAL_TABLE_SAT_TX_RATE_CONTROL, DBAL_FIELD_THRESHOLD_LOWER_EXPONENT, FALSE, 0, 0,
                     (int *) (&low_exp_nof_bits)));

    SHR_IF_ERR_EXIT(utilex_break_to_mnt_exp_round_up
                    (is_pkt_mode ? config->high_threshold : (config->high_threshold * 125), up_mnt_nof_bits,
                     up_exp_nof_bits, 0, &high_mnt_val, &high_exp_val));
    SHR_IF_ERR_EXIT(utilex_break_to_mnt_exp_round_up
                    (is_pkt_mode ? config->low_threshold : (config->low_threshold * 125), low_mnt_nof_bits,
                     low_exp_nof_bits, 0, &low_mnt_val, &low_exp_val));

    SHR_IF_ERR_EXIT(DBAL_HANDLE_ALLOC(unit, DBAL_TABLE_SAT_EVC_TX_RATE_CONTROL, &entry_handle_id));

    dbal_entry_key_field8_set(unit, entry_handle_id, DBAL_FIELD_EVC_ID, evc_id);

    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_THRESHOLD_UPPER_MANTISSA, INST_SINGLE, high_mnt_val);
    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_THRESHOLD_UPPER_EXPONENT, INST_SINGLE, high_exp_val);
    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_THRESHOLD_LOWER_MANTISSA, INST_SINGLE, low_mnt_val);
    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_THRESHOLD_LOWER_EXPONENT, INST_SINGLE, low_exp_val);

    SHR_IF_ERR_EXIT(dbal_entry_commit(unit, entry_handle_id, DBAL_COMMIT));

exit:
    DBAL_FUNC_FREE_VARS;
    SHR_FUNC_EXIT;
}

static shr_error_e
dnx_sat_evc_rate_pattern_set_verify(
    int unit,
    bcm_sat_gtf_t gtf_id,
    bcm_sat_gtf_rate_pattern_t * config)
{
    SHR_FUNC_INIT_VARS(unit);

    SHR_NULL_CHECK(config, _SHR_E_PARAM, "config ");
    SHR_RANGE_VERIFY(gtf_id, DNX_SAT_GTF_ID_MIN, DNX_SAT_GTF_ID_MAX, _SHR_E_PARAM, "gtf_id");
    SHR_RANGE_VERIFY(config->high_threshold, DNX_SAT_GTF_RATE_PATN_HIGH_TH_MIN,
                     DNX_SAT_GTF_RATE_PATN_HIGH_TH_MAX, _SHR_E_PARAM, "high_threshold");
    SHR_RANGE_VERIFY(config->low_threshold, DNX_SAT_GTF_RATE_PATN_LOW_TH_MIN, DNX_SAT_GTF_RATE_PATN_LOW_TH_MAX,
                     _SHR_E_PARAM, "low_threshold");

    SHR_EXIT();
exit:
    SHR_FUNC_EXIT;
}

shr_error_e
bcm_dnx_sat_gtf_rate_pattern_set(
    int unit,
    bcm_sat_gtf_t gtf_id,
    int priority,
    bcm_sat_gtf_rate_pattern_t * config)
{
    bcm_sat_gtf_rate_pattern_t dnx_rate_pattern;
    bcm_sat_gtf_t gtf_to_set = gtf_id;
    uint32 is_paired = 0;

    SHR_FUNC_INIT_VARS(unit);
    DNX_ERR_RECOVERY_START(unit);
    DNX_SAT_IS_SUPPORTED_CHECK(unit);

    if (DNX_SAT_GTF_ID_IS_VALID_EVC_ID(gtf_id))
    {
        SHR_IF_ERR_EXIT(dnx_sat_gtf_is_paired_get(unit, gtf_id, &is_paired));
    }

    if (!is_paired && (priority != bcmSatGtfPriCir))
    {
        LOG_WARN(BSL_LS_BCM_SAT, ("GTF is not paired but priority is not CIR, ignore priority\n"));
        priority = bcmSatGtfPriCir;
    }

    SHR_INVOKE_VERIFY_DNXC(dnx_sat_gtf_id_priority_verify(unit, gtf_id, priority));
    SHR_NULL_CHECK(config, _SHR_E_PARAM, "config");

    sal_memset(&dnx_rate_pattern, 0, sizeof(dnx_rate_pattern));

    if (priority == bcmSatGtfPriAll)
    {
        SHR_INVOKE_VERIFY_DNXC(dnx_sat_evc_rate_pattern_set_verify(unit, gtf_id, config));

        dnx_rate_pattern.high_threshold = config->high_threshold;
        dnx_rate_pattern.low_threshold = config->low_threshold;
        SHR_IF_ERR_EXIT(dnx_sat_evc_rate_pattern_set(unit, gtf_id, &dnx_rate_pattern));
    }
    else
    {
        if (priority == bcmSatGtfPriEir)
        {
            gtf_to_set += 1;
        }

        SHR_INVOKE_VERIFY_DNXC(dnx_sat_gtf_rate_pattern_set_verify(unit, gtf_to_set, config));

        LOG_VERBOSE(BSL_LS_BCM_SAT, ("%s %d: u(%d) gtf_id(%d) priority(%d)\n"
                                     "  rate_pattern_mode(%d)\n"
                                     "  high_threshold(%d) low_threshold(%d)\n"
                                     "  stop_iter_count(%d) stop_burst_count(%d) stop_interval_count(%d)\n"
                                     "  burst_packet_weight(%d) interval_packet_weight(%d) flags(%d)\n", BSL_FUNC,
                                     BSL_LINE, unit, gtf_id, priority, config->rate_pattern_mode,
                                     config->high_threshold, config->low_threshold, config->stop_iter_count,
                                     config->stop_burst_count, config->stop_interval_count, config->burst_packet_weight,
                                     config->interval_packet_weight, config->flags));

        if (config->flags & BCM_SAT_GTF_RATE_PATTERN_STOP_INTERVAL_EQ_BURST)
        {
            dnx_rate_pattern.flags |= BCM_SAT_GTF_RATE_PATTERN_STOP_INTERVAL_EQ_BURST;
        }
        dnx_rate_pattern.rate_pattern_mode = config->rate_pattern_mode;
        dnx_rate_pattern.high_threshold = config->high_threshold;
        dnx_rate_pattern.low_threshold = config->low_threshold;
        dnx_rate_pattern.stop_iter_count = config->stop_iter_count;
        dnx_rate_pattern.stop_burst_count = config->stop_burst_count;
        dnx_rate_pattern.stop_interval_count = config->stop_interval_count;
        dnx_rate_pattern.burst_packet_weight = config->burst_packet_weight;
        dnx_rate_pattern.interval_packet_weight = config->interval_packet_weight;

        SHR_IF_ERR_EXIT(dnx_sat_gtf_rate_pattern_set(unit, gtf_to_set, &dnx_rate_pattern));
    }

exit:
    DNX_ERR_RECOVERY_END(unit);
    SHR_FUNC_EXIT;
}

shr_error_e
dnx_sat_gtf_stat_multi_get(
    int unit,
    bcm_sat_gtf_t gtf_id,
    uint64 *packet_cnt,
    uint64 *byte_cnt)
{
    uint32 entry_handle_id;
    uint32 packet_cnt_hw = 0;
    uint32 byte_cnt_hw[2] = { 0 };

    SHR_FUNC_INIT_VARS(unit);
    DBAL_FUNC_INIT_VARS(unit);

    SHR_IF_ERR_EXIT(DBAL_HANDLE_ALLOC(unit, DBAL_TABLE_SAT_TX_STAT_GET, &entry_handle_id));

    dbal_entry_key_field8_set(unit, entry_handle_id, DBAL_FIELD_TX_FLOW_ID, gtf_id);

    dbal_value_field32_request(unit, entry_handle_id, DBAL_FIELD_TX_PKT_COUNTERS, INST_SINGLE, &packet_cnt_hw);
    dbal_value_field_arr32_request(unit, entry_handle_id, DBAL_FIELD_TX_BYTE_COUNTERS, INST_SINGLE, byte_cnt_hw);

    SHR_IF_ERR_EXIT(dbal_entry_get(unit, entry_handle_id, DBAL_COMMIT));

    COMPILER_64_SET(*byte_cnt, byte_cnt_hw[1], byte_cnt_hw[0]);
    COMPILER_64_SET(*packet_cnt, 0, packet_cnt_hw);

exit:
    DBAL_FUNC_FREE_VARS;
    SHR_FUNC_EXIT;
}

static shr_error_e
dnx_sat_gtf_stat_multi_get_verify(
    int unit,
    bcm_sat_gtf_t gtf_id,
    bcm_sat_gtf_stat_multi_t * stat)
{
    uint8 is_allocated = 0;
    SHR_FUNC_INIT_VARS(unit);
    DNX_SAT_IS_SUPPORTED_CHECK(unit);
    SHR_NULL_CHECK(stat, _SHR_E_PARAM, "stat ");
    SHR_RANGE_VERIFY(gtf_id, DNX_SAT_GTF_ID_MIN, DNX_SAT_GTF_ID_MAX, _SHR_E_PARAM, "gtf_id");
    SHR_IF_ERR_EXIT(algo_sat_db.sat_res_alloc_gtf_id.is_allocated(unit, gtf_id, &is_allocated));

    if (!is_allocated)
    {
        SHR_ERR_EXIT(_SHR_E_NOT_FOUND, "Error: GTF with id %d not exists\n", gtf_id);
    }

    SHR_EXIT();
exit:
    SHR_FUNC_EXIT;
}

shr_error_e
bcm_dnx_sat_gtf_stat_multi_get(
    int unit,
    bcm_sat_gtf_t gtf_id,
    bcm_sat_gtf_stat_multi_t * stat)
{
    uint64 packet_cnt = COMPILER_64_INIT(0, 0);
    uint64 byte_cnt = COMPILER_64_INIT(0, 0);

    SHR_FUNC_INIT_VARS(unit);
    DNX_ERR_RECOVERY_NOT_NEEDED(unit);

    SHR_INVOKE_VERIFY_DNXC(dnx_sat_gtf_stat_multi_get_verify(unit, gtf_id, stat));

    LOG_VERBOSE(BSL_LS_BCM_SAT, ("%s %d: u(%d) gtf_id(%d) \n", BSL_FUNC, BSL_LINE, unit, gtf_id));

    SHR_IF_ERR_EXIT(dnx_sat_gtf_stat_multi_get(unit, gtf_id, &packet_cnt, &byte_cnt));

    COMPILER_64_COPY(stat->transmitted_packet_cnt, packet_cnt);
    COMPILER_64_COPY(stat->transmitted_byte_cnt, byte_cnt);

exit:
    SHR_FUNC_EXIT;
}
