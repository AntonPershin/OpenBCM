/** \file algo_oam.c
 * 
 *
 * Resource and templates needed for the oam feature.
 *
 */
/*
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2022 Broadcom Inc. All rights reserved.
 */

#ifdef BSL_LOG_MODULE
#error "BSL_LOG_MODULE redefined"
#endif
#define BSL_LOG_MODULE BSL_LS_BCMDNX_TEMPLATEMNGR
/**
* INCLUDE FILES:
* {
*/
#include <soc/sand/shrextend/shrextend_debug.h>
#include <bcm/types.h>
#include <soc/dnx/mdb.h>
#include <src/bcm/dnx/oam/oam_internal.h>
#include <bcm_int/dnx/algo/oam/algo_oam.h>
#include <bcm_int/dnx/algo/oamp/algo_oamp_v1.h>
#include <soc/dnx/dnx_data/auto_generated/dnx_data_oam.h>
#include <src/bcm/dnx/oam/oam_oamp.h>
#include <bcm_int/dnx/algo/swstate/auto_generated/access/algo_oam_access.h>

/** Callbacks needed for the template used in oam   */

void
dnx_oam_group_icc_profile_print_cb(
    int unit,
    const void *data)
{
#ifdef DNX_SW_STATE_DIAGNOSTIC
    dnx_oam_group_icc_profile_data_t *icc_profile_data = (dnx_oam_group_icc_profile_data_t *) data;
#endif
    SW_STATE_PRETTY_PRINT_INIT_VARIABLES();
    SW_STATE_PRETTY_PRINT_ADD_LINE(SW_STATE_PRETTY_PRINT_TYPE_UINT8, "icc_profile_data[5]", (*icc_profile_data)[5],
                                   NULL, "0x%x");
    SW_STATE_PRETTY_PRINT_ADD_LINE(SW_STATE_PRETTY_PRINT_TYPE_UINT8, "icc_profile_data[4]", (*icc_profile_data)[4],
                                   NULL, "0x%x");
    SW_STATE_PRETTY_PRINT_ADD_LINE(SW_STATE_PRETTY_PRINT_TYPE_UINT8, "icc_profile_data[3]", (*icc_profile_data)[3],
                                   NULL, "0x%x");
    SW_STATE_PRETTY_PRINT_ADD_LINE(SW_STATE_PRETTY_PRINT_TYPE_UINT8, "icc_profile_data[2]", (*icc_profile_data)[2],
                                   NULL, "0x%x");
    SW_STATE_PRETTY_PRINT_ADD_LINE(SW_STATE_PRETTY_PRINT_TYPE_UINT8, "icc_profile_data[1]", (*icc_profile_data)[1],
                                   NULL, "0x%x");
    SW_STATE_PRETTY_PRINT_ADD_LINE(SW_STATE_PRETTY_PRINT_TYPE_UINT8, "icc_profile_data[0]", (*icc_profile_data)[0],
                                   NULL, "0x%x");
    SW_STATE_PRETTY_PRINT_FINISH();
    return;
}

/*
 * See prototype definition for function description in algo_oam.h
 */
void
dnx_oam_oamp_tpid_profile_print_cb(
    int unit,
    const void *data)
{
#ifdef DNX_SW_STATE_DIAGNOSTIC
    uint16 tpid = *(uint16 *) data;
#endif
    SW_STATE_PRETTY_PRINT_INIT_VARIABLES();

    SW_STATE_PRETTY_PRINT_ADD_LINE(SW_STATE_PRETTY_PRINT_TYPE_UINT16, "TPID", tpid, NULL, "0x%08X");
    SW_STATE_PRETTY_PRINT_FINISH();

    return;
}

/*
 * See prototype definition for function description in algo_oam.h
 */
void
dnx_oam_oamp_sa_mac_msb_profile_print_cb(
    int unit,
    const void *data)
{
#ifdef DNX_SW_STATE_DIAGNOSTIC
    bcm_mac_t *sa_mac_msb = (bcm_mac_t *) data;
#endif
    SW_STATE_PRETTY_PRINT_INIT_VARIABLES();

    SW_STATE_PRETTY_PRINT_ADD_LINE(SW_STATE_PRETTY_PRINT_TYPE_MAC, "Source MAC MSB", *sa_mac_msb, NULL, NULL);

    SW_STATE_PRETTY_PRINT_FINISH();

    return;
}

/*
 * See prototype definition for function description in algo_oam.h
 */
void
dnx_slm_oamp_measurement_period_print_cb(
    int unit,
    const void *data)
{
#ifdef DNX_SW_STATE_DIAGNOSTIC
    uint16 *slm_measurement_period = (uint16 *) data;
#endif
    SW_STATE_PRETTY_PRINT_INIT_VARIABLES();
    SW_STATE_PRETTY_PRINT_ADD_LINE(SW_STATE_PRETTY_PRINT_TYPE_UINT16, "slm measurement period",
                                   slm_measurement_period[0], NULL, "0x%04X");
    SW_STATE_PRETTY_PRINT_FINISH();
    return;
}

/*
 * See prototype definition for function description in algo_oam.h
 */
void
dnx_oam_oamp_oamp_trap_tcam_print_cb(
    int unit,
    const void *data)
{
#ifdef DNX_SW_STATE_DIAGNOSTIC
    dnx_oam_oamp_trap_tcam_entry_t *trap_tcam_data = (dnx_oam_oamp_trap_tcam_entry_t *) data;
#endif
    SW_STATE_PRETTY_PRINT_INIT_VARIABLES();
    SW_STATE_PRETTY_PRINT_ADD_LINE(SW_STATE_PRETTY_PRINT_TYPE_UINT32, "Trap code",
                                   trap_tcam_data->trap_code, NULL, "0x%08X");
    SW_STATE_PRETTY_PRINT_ADD_LINE(SW_STATE_PRETTY_PRINT_TYPE_UINT8, "MEP type",
                                   trap_tcam_data->mep_type, NULL, "0x%02X");
    SW_STATE_PRETTY_PRINT_FINISH();
    return;
}

/*
 * See prototype definition for function description in algo_oamp_v2.h
 */
void
dnx_oam_oamp_v2_stamp_tlv_profile_print_cb(
    int unit,
    const void *data)
{
#ifdef DNX_SW_STATE_DIAGNOSTIC
    dnx_oam_oamp_v2_stamp_tlv_profile_t *tlv_data = (dnx_oam_oamp_v2_stamp_tlv_profile_t *) data;
#endif
    SW_STATE_PRETTY_PRINT_INIT_VARIABLES();

    SW_STATE_PRETTY_PRINT_ADD_LINE(SW_STATE_PRETTY_PRINT_TYPE_UINT8, "STAMP TLV Flags", tlv_data->stamp_flags, NULL,
                                   "%d");

    SW_STATE_PRETTY_PRINT_FINISH();

    return;
}

/*
 * See prototype definition for function description in algo_oamp_v2.h
 */
void
dnx_oam_oamp_v2_tlv_profile_print_cb(
    int unit,
    const void *data)
{
#ifdef DNX_SW_STATE_DIAGNOSTIC
    dnx_oam_oamp_v2_tlv_profile_t *tlv_data = (dnx_oam_oamp_v2_tlv_profile_t *) data;
#endif
    SW_STATE_PRETTY_PRINT_INIT_VARIABLES();

    SW_STATE_PRETTY_PRINT_ADD_LINE(SW_STATE_PRETTY_PRINT_TYPE_UINT8, "TLV Value #1", tlv_data->value1, NULL, "%d");

    SW_STATE_PRETTY_PRINT_ADD_LINE(SW_STATE_PRETTY_PRINT_TYPE_UINT16, "TLV Length #1", tlv_data->length1, NULL, "%d");

    SW_STATE_PRETTY_PRINT_ADD_LINE(SW_STATE_PRETTY_PRINT_TYPE_UINT8, "TLV Type #1", tlv_data->type1, NULL, "%d");

    SW_STATE_PRETTY_PRINT_ADD_LINE(SW_STATE_PRETTY_PRINT_TYPE_UINT8, "TLV Value #2", tlv_data->value2, NULL, "%d");

    SW_STATE_PRETTY_PRINT_ADD_LINE(SW_STATE_PRETTY_PRINT_TYPE_UINT16, "TLV Length #2", tlv_data->length2, NULL, "%d");

    SW_STATE_PRETTY_PRINT_ADD_LINE(SW_STATE_PRETTY_PRINT_TYPE_UINT8, "TLV Type #2", tlv_data->type2, NULL, "%d");

    SW_STATE_PRETTY_PRINT_ADD_LINE(SW_STATE_PRETTY_PRINT_TYPE_UINT16, "TLV zero padding", tlv_data->padding, NULL,
                                   "%d");

    SW_STATE_PRETTY_PRINT_FINISH();

    return;
}

/*
 * See prototype definition for function description in algo_oamp_v2.h
 */
void
dnx_oam_oamp_v2_oam_ch_2_small_profile_print_cb(
    int unit,
    const void *data)
{
#ifdef DNX_SW_STATE_DIAGNOSTIC
    algo_oamp_v2_oam_ch_2_small_profile_t *oam_ch_2_data = (algo_oamp_v2_oam_ch_2_small_profile_t *) data;
#endif
    SW_STATE_PRETTY_PRINT_INIT_VARIABLES();

    SW_STATE_PRETTY_PRINT_ADD_LINE(SW_STATE_PRETTY_PRINT_TYPE_UINT8, "oam_ch_2_data->icc_data[5]",
                                   oam_ch_2_data->icc_data[5], NULL, "0x%x");
    SW_STATE_PRETTY_PRINT_ADD_LINE(SW_STATE_PRETTY_PRINT_TYPE_UINT8, "oam_ch_2_data->icc_data[4]",
                                   oam_ch_2_data->icc_data[4], NULL, "0x%x");
    SW_STATE_PRETTY_PRINT_ADD_LINE(SW_STATE_PRETTY_PRINT_TYPE_UINT8, "oam_ch_2_data->icc_data[3]",
                                   oam_ch_2_data->icc_data[3], NULL, "0x%x");
    SW_STATE_PRETTY_PRINT_ADD_LINE(SW_STATE_PRETTY_PRINT_TYPE_UINT8, "oam_ch_2_data->icc_data[2]",
                                   oam_ch_2_data->icc_data[2], NULL, "0x%x");
    SW_STATE_PRETTY_PRINT_ADD_LINE(SW_STATE_PRETTY_PRINT_TYPE_UINT8, "oam_ch_2_data->icc_data[1]",
                                   oam_ch_2_data->icc_data[1], NULL, "0x%x");
    SW_STATE_PRETTY_PRINT_ADD_LINE(SW_STATE_PRETTY_PRINT_TYPE_UINT8, "oam_ch_2_data->icc_data[0]",
                                   oam_ch_2_data->icc_data[0], NULL, "0x%x");

    SW_STATE_PRETTY_PRINT_FINISH();

    return;
}

/*
 * See prototype definition for function description in algo_oam.h
 */
void
dnx_oam_server_device_index_print_cb(
    int unit,
    const void *data)
{
#ifdef DNX_SW_STATE_DIAGNOSTIC
    uint8 server_device_index = *(uint8 *) data;
#endif
    SW_STATE_PRETTY_PRINT_INIT_VARIABLES();

    SW_STATE_PRETTY_PRINT_ADD_LINE(SW_STATE_PRETTY_PRINT_TYPE_UINT8, "OAM server device", server_device_index, NULL,
                                   "0x%x");
    SW_STATE_PRETTY_PRINT_FINISH();

    return;
}

/**
 * \brief - This function creates the resource configuration 
 *        needed for the OAM group allocation
 * \param [in] unit - Number of hardware unit used.
 *   
 * \return
 *   shr_error_e 
 *   
 * \remark
 *  * None
 * \see
 *   * None
 */
static shr_error_e
dnx_algo_oam_group_id_init(
    int unit)
{
    int capacity = 0;
    dnx_algo_res_create_data_t data;
    SHR_FUNC_INIT_VARS(unit);

    /*
     * Init algo_oam sw state module.
     */
    SHR_IF_ERR_EXIT(algo_oam_db.init(unit));

    sal_memset(&data, 0, sizeof(dnx_algo_res_create_data_t));
    /** First element id for group id res mngr */
    data.first_element = 0;
    /** Number of groups that can be configured for device   */

    /*
     * Get Number of groups ==================== Number of entries in lif db = (IOEM_capacity - 100) / 2 ( size of
     * elemnt is 30 bits, each entry has <60) Number of endpoints = 8 * Number of entries in lif db Number of groups
     * = Number of endpoints 
     */

    if (DNX_OAMP_IS_V1(unit))
    {
        SHR_IF_ERR_EXIT(mdb_db_infos.capacity.get(unit, DBAL_PHYSICAL_TABLE_IOEM_1, &capacity));
    }
    if (capacity <= 100)
    {
        data.nof_elements = 1;
    }
    else
    {
        data.nof_elements = 8 * (capacity - 100) / 2;
    }

    data.flags = 0;
    sal_strncpy(data.name, DNX_ALGO_OAM_GROUP_ID, DNX_ALGO_RES_MNGR_MAX_NAME_LENGTH - 1);
    SHR_IF_ERR_EXIT(algo_oam_db.oam_group_id.create(unit, &data, NULL));

exit:
    SHR_FUNC_EXIT;
}

/**
 * \brief - This function creates the resource configuration
 *        needed for the OAM profile allocation. 4 different
 *        pools should be created (1 per type).
 * \param [in] unit - Number of hardware unit used.
 *
 * \return
 *   shr_error_e
 *
 * \remark
 *  * None
 * \see
 *   * None
 */
static shr_error_e
dnx_algo_oam_profile_id_init(
    int unit)
{
    dnx_algo_res_create_data_t data;
    SHR_FUNC_INIT_VARS(unit);

    sal_memset(&data, 0, sizeof(dnx_algo_res_create_data_t));

    data.flags = 0;
    /*
     * First element id for profile id res mngr (0 is used for
     * default profile)
     */
    data.first_element = 1;
    /*
     * Number of profiles that can be configured for device
     * non-acc profiles (excluding profile 0)
     */
    data.nof_elements = dnx_data_oam.general.oam_nof_non_acc_action_profiles_get(unit) - 1;

    /** Ingress non-acc */
    sal_strncpy(data.name, DNX_ALGO_OAM_PROFILE_ID_ING, DNX_ALGO_RES_MNGR_MAX_NAME_LENGTH - 1);

    SHR_IF_ERR_EXIT(algo_oam_db.oam_profile_id_ing.create(unit, &data, NULL));
    /** Egress non-acc */
    sal_strncpy(data.name, DNX_ALGO_OAM_PROFILE_ID_EG, DNX_ALGO_RES_MNGR_MAX_NAME_LENGTH - 1);

    SHR_IF_ERR_EXIT(algo_oam_db.oam_profile_id_eg.create(unit, &data, NULL));

    /*
     * Number of profiles that can be configured for device
     * acc profiles (excluding profile 0)
     */
    data.nof_elements = dnx_data_oam.general.oam_nof_acc_action_profiles_get(unit) - 1;

    /** Ingress acc */
    sal_strncpy(data.name, DNX_ALGO_OAM_PROFILE_ID_ING_ACC, DNX_ALGO_RES_MNGR_MAX_NAME_LENGTH - 1);

    SHR_IF_ERR_EXIT(algo_oam_db.oam_profile_id_ing_acc.create(unit, &data, NULL));

    /** Egress acc */
    data.nof_elements = dnx_data_oam.general.oam_nof_acc_action_profiles_get(unit) -
        dnx_data_oam.general.oam_nof_reserved_egr_acc_action_profiles_get(unit);

    sal_strncpy(data.name, DNX_ALGO_OAM_PROFILE_ID_EG_ACC, DNX_ALGO_RES_MNGR_MAX_NAME_LENGTH - 1);

    SHR_IF_ERR_EXIT(algo_oam_db.oam_profile_id_eg_acc.create(unit, &data, NULL));

exit:
    SHR_FUNC_EXIT;
}

/**
 * \brief - This function creates the templates needed for the
 *        OAM features
 *
 * \param [in] unit - Number of hardware unit used.
 *
 * \return
 *   shr_error_e
 *
 * \remark
 *   * Templates created are:\n
 *      1.OAM Accelerated MEP ICC profile Table: LONG type group name
 *      ICC profiles which contain 6 bytes of the group name.\n
 * \see
 *   * None
 */
static shr_error_e
dnx_algo_oam_init_templates(
    int unit)
{
    int capacity = 0;
    dnx_algo_template_create_data_t oam_group_icc_profile_data,
        slm_oamp_measurement_period_profile_data, oam_trap_code_tcam_data;
    uint32 nof_icc_profiles, nof_references = 0;
    int nof_trap_code_tcam;
    SHR_FUNC_INIT_VARS(unit);

    /** Get values from DNX data   */
    nof_icc_profiles = dnx_data_oam.oamp.nof_icc_profiles_get(unit);

    /*
     * Get Number of endpoints ======================= Number of entries in lif db = (IOEM_capacity - 100) / 2 ( size
     * of elemnt is 30 bits, each entry has <60) Number of endpoints = 8 * Number of entries in lif db 
     */

    if (DNX_OAMP_IS_V1(unit))
    {
        SHR_IF_ERR_EXIT(mdb_db_infos.capacity.get(unit, DBAL_PHYSICAL_TABLE_IOEM_1, &capacity));
        nof_references = 8 * (capacity - 100) / 2;
        if (capacity <= 100)
        {
            nof_references = 1;
        }
        else
        {
            nof_references = 8 * (capacity - 100) / 2;
        }
    }
    else
    {
    }

    /** Create template for OAMP ICC map table */
    sal_memset(&oam_group_icc_profile_data, 0, sizeof(dnx_algo_template_create_data_t));
    oam_group_icc_profile_data.flags = 0;
    oam_group_icc_profile_data.first_profile = 0;
    oam_group_icc_profile_data.nof_profiles = nof_icc_profiles;
    oam_group_icc_profile_data.max_references = nof_references;
    oam_group_icc_profile_data.default_profile = 0;
    oam_group_icc_profile_data.data_size = sizeof(dnx_oam_group_icc_profile_data_t);
    oam_group_icc_profile_data.default_data = NULL;
    sal_strncpy(oam_group_icc_profile_data.name, DNX_ALGO_OAM_GROUP_ICC_PROFILE,
                DNX_ALGO_TEMPLATE_MNGR_MAX_NAME_LENGTH - 1);

    SHR_IF_ERR_EXIT(algo_oam_db.oam_group_icc_profile.create(unit, &oam_group_icc_profile_data, NULL));

    /*
     * Init Trap Code Tcam Index template
     */
    nof_trap_code_tcam = dnx_data_oam.oamp.oam_nof_trap_code_tcam_get(unit);
    sal_memset(&oam_trap_code_tcam_data, 0, sizeof(dnx_algo_template_create_data_t));
    oam_trap_code_tcam_data.first_profile = 0;
    oam_trap_code_tcam_data.nof_profiles = nof_trap_code_tcam;
    oam_trap_code_tcam_data.flags = 0;
    oam_trap_code_tcam_data.max_references = nof_references;
    oam_trap_code_tcam_data.default_profile = 0;
    oam_trap_code_tcam_data.data_size = sizeof(dnx_oam_oamp_trap_tcam_entry_t);
    oam_trap_code_tcam_data.default_data = NULL;
    sal_strncpy(oam_trap_code_tcam_data.name, DNX_ALGO_OAM_TRAP_CODE_TCAM_DATA,
                DNX_ALGO_TEMPLATE_MNGR_MAX_NAME_LENGTH - 1);

    SHR_IF_ERR_EXIT(algo_oam_db.oam_trap_tcam_index.create(unit, &oam_trap_code_tcam_data, NULL));

    /** Get values from DNX data   */
    nof_references = dnx_data_oam.general.oam_nof_endpoints_get(unit);

    /** Create template for SLM measurement period   */
    sal_memset(&slm_oamp_measurement_period_profile_data, 0, sizeof(dnx_algo_template_create_data_t));
    slm_oamp_measurement_period_profile_data.flags = 0;
    slm_oamp_measurement_period_profile_data.first_profile = 0;
    slm_oamp_measurement_period_profile_data.nof_profiles = 8;
    slm_oamp_measurement_period_profile_data.max_references = nof_references;
    slm_oamp_measurement_period_profile_data.default_profile = 0;
    slm_oamp_measurement_period_profile_data.data_size = sizeof(uint16);
    slm_oamp_measurement_period_profile_data.default_data = NULL;
    sal_strncpy(slm_oamp_measurement_period_profile_data.name, DNX_SLM_OAMP_TEMPLATE_TX_RATE,
                DNX_ALGO_TEMPLATE_MNGR_MAX_NAME_LENGTH - 1);

    SHR_IF_ERR_EXIT(algo_oam_db.
                    slm_oamp_measurement_period.create(unit, &slm_oamp_measurement_period_profile_data, NULL));

exit:
    SHR_FUNC_EXIT;
}

/**
 * \brief - This function creates the template needed for sa mac msb profiles
 *
 * \param [in] unit - Number of hardware unit used.
 *
 * \return
 *   shr_error_e
 *
 * \remark
 *
 * \see
 *   * None
 */
static shr_error_e
dnx_algo_oam_oamp_sa_mac_msb_template_init(
    int unit)
{
    dnx_algo_template_create_data_t oam_sa_mac_msb_profile_data;
    uint32 max_nof_endpoint_id;
    uint32 nof_sa_mac_profiles;
    SHR_FUNC_INIT_VARS(unit);

    /** Get values from DNX data   */
    nof_sa_mac_profiles = dnx_data_oam.oamp.oam_nof_sa_mac_profiles_get(unit);
    max_nof_endpoint_id = dnx_data_oam.oamp.max_nof_endpoint_id_get(unit);

    /** Create template for SA MAC msb */
    sal_memset(&oam_sa_mac_msb_profile_data, 0, sizeof(dnx_algo_template_create_data_t));
    oam_sa_mac_msb_profile_data.flags = 0;
    oam_sa_mac_msb_profile_data.first_profile = 0;
    oam_sa_mac_msb_profile_data.nof_profiles = nof_sa_mac_profiles;
    oam_sa_mac_msb_profile_data.max_references = max_nof_endpoint_id;
    oam_sa_mac_msb_profile_data.default_profile = 0;
    oam_sa_mac_msb_profile_data.data_size = sizeof(bcm_mac_t);
    oam_sa_mac_msb_profile_data.default_data = NULL;
    sal_strncpy(oam_sa_mac_msb_profile_data.name, DNX_ALGO_OAM_OAMP_SA_MAC_MSB_PROFILE_TEMPLATE,
                DNX_ALGO_RES_MNGR_MAX_NAME_LENGTH - 1);

    SHR_IF_ERR_EXIT(algo_oam_db.oam_sa_mac_msb_profile_template.create(unit, &oam_sa_mac_msb_profile_data, NULL));
exit:
    SHR_FUNC_EXIT;
}

/**
 * \brief - This function creates the template for the OAM tpid profiles.
 *          Used for ETH OAM tpid
 *
 * \param [in] unit - Number of hardware unit used.
 *
 * \return
 *   shr_error_e
 *
 * \remark
 *   * None
 * \see
 *   * None
 */
static shr_error_e
dnx_algo_oam_oamp_tpid_profile_id_init(
    int unit)
{
    dnx_algo_template_create_data_t tpid_profile_data;
    SHR_FUNC_INIT_VARS(unit);

    sal_memset(&tpid_profile_data, 0, sizeof(dnx_algo_template_create_data_t));
    tpid_profile_data.flags = 0;
    tpid_profile_data.first_profile = 0;
    tpid_profile_data.nof_profiles = dnx_data_oam.oamp.oam_nof_tpid_profiles_get(unit);
    /** Two tags per endpoint could be configured(outer/inner tag) */
    tpid_profile_data.max_references = 2 * dnx_data_oam.general.oam_nof_oamp_meps_get(unit);
    tpid_profile_data.default_profile = 0;
    tpid_profile_data.data_size = sizeof(uint16);
    tpid_profile_data.default_data = NULL;
    sal_strncpy(tpid_profile_data.name, DNX_ALGO_OAM_OAMP_TPID_PROFILE_TEMPLATE,
                DNX_ALGO_TEMPLATE_MNGR_MAX_NAME_LENGTH - 1);

    SHR_IF_ERR_EXIT(algo_oam_db.eth_oam_tpid_profile.create(unit, &tpid_profile_data, NULL));

exit:
    SHR_FUNC_EXIT;
}

/**
 * \brief - This function creates the template for the OAM server device index.
 *          Used for OAM server-client model
 *
 * \param [in] unit - Number of hardware unit used.
 *
 * \return
 *   shr_error_e
 *
 * \remark
 *   * None
 * \see
 *   * None
 */
static shr_error_e
dnx_algo_oam_server_device_index_template_init(
    int unit)
{
    dnx_algo_template_create_data_t server_device_index_data;
    SHR_FUNC_INIT_VARS(unit);

    sal_memset(&server_device_index_data, 0, sizeof(dnx_algo_template_create_data_t));
    server_device_index_data.flags = 0;
    server_device_index_data.first_profile = 1;
    server_device_index_data.nof_profiles = dnx_data_oam.general.oam_nof_server_device_profile_get(unit);
    server_device_index_data.max_references = dnx_data_oam.general.oam_nof_oamp_meps_get(unit);
    server_device_index_data.default_profile = 1;
    server_device_index_data.data_size = sizeof(uint8);
    server_device_index_data.default_data = NULL;
    sal_strncpy(server_device_index_data.name, DNX_ALGO_OAM_SERVER_DEVICE_INDEX_TEMPLATE,
                DNX_ALGO_TEMPLATE_MNGR_MAX_NAME_LENGTH - 1);

    SHR_IF_ERR_EXIT(algo_oam_db.oam_server_device_index.create(unit, &server_device_index_data, NULL));

exit:
    SHR_FUNC_EXIT;
}

/**
 * \brief - This function creates the template for the OAM lif.
 *          Used for OAM primary VLAN
 *
 * \param [in] unit - Number of hardware unit used.
 *
 * \return
 *   shr_error_e
 *
 * \remark
 *   * None
 * \see
 *   * None
 */
static shr_error_e
dnx_algo_oam_primary_vlan_oam_lif_id_init(
    int unit)
{
    dnx_algo_res_create_data_t data;
    SHR_FUNC_INIT_VARS(unit);

    sal_memset(&data, 0, sizeof(dnx_algo_res_create_data_t));
    /** First element id for oam lif id res mngr */
    data.first_element = 1;
    /** Number of oam lifs that can be configured for device, Not set MAX to avoid consume resources */
    data.nof_elements = dnx_data_lif.global_lif.nof_global_l2_gport_lifs_get(unit) / 32;
    data.flags = 0;
    sal_strncpy(data.name, DNX_ALGO_OAM_LIF_ID, DNX_ALGO_RES_MNGR_MAX_NAME_LENGTH - 1);
    SHR_IF_ERR_EXIT(algo_oam_db.oam_primary_vlan_oam_lif.create(unit, &data, NULL));

exit:
    SHR_FUNC_EXIT;
}

/**
 * See algo_oam.h
 */
shr_error_e
dnx_algo_oam_init(
    int unit)
{
    SHR_FUNC_INIT_VARS(unit);

    SHR_IF_ERR_EXIT(dnx_algo_oam_group_id_init(unit));
    SHR_IF_ERR_EXIT(dnx_algo_oam_profile_id_init(unit));
    SHR_IF_ERR_EXIT(dnx_algo_oam_init_templates(unit));
    SHR_IF_ERR_EXIT(dnx_algo_oam_oamp_sa_mac_msb_template_init(unit));
    SHR_IF_ERR_EXIT(dnx_algo_oam_oamp_tpid_profile_id_init(unit));
    SHR_IF_ERR_EXIT(dnx_algo_oam_server_device_index_template_init(unit));
    SHR_IF_ERR_EXIT(dnx_algo_oam_primary_vlan_oam_lif_id_init(unit));

exit:
    SHR_FUNC_EXIT;
}

/**
 * }
 */
