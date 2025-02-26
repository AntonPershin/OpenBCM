/** \file appl_ref_init_deinit.c
 * init and deinit functions to be used by the INIT_DNX command.
 */

/*
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2022 Broadcom Inc. All rights reserved.
 */

#ifdef BSL_LOG_MODULE
#error "BSL_LOG_MODULE redefined"
#endif
#define BSL_LOG_MODULE BSL_LS_APPLDNX_INITSEQDNX

/*
* INCLUDE FILES:
* {
*/

#include <soc/sand/shrextend/shrextend_debug.h>
#include <bcm/init.h>
#include <bcm/cosq.h>
#include <bcm/stack.h>
/** this include is needed to skip wb testing for sys_params parsing */
#include <bcm_int/dnx/init/init.h>

#include <appl/diag/sand/diag_sand_utils.h>
#include <appl/diag/shell.h>
#include <soc/dnxc/dnxc_ha.h>
#include <bcm_int/dnx/algo/port/algo_port_mgmt.h>
#include <soc/dnx/dnx_data/auto_generated/dnx_data.h>
#include <soc/dnx/dnx_data/auto_generated/dnx_data_field.h>
#include <soc/dnx/dnx_data/auto_generated/dnx_data_headers.h>
#include <soc/dnx/dnx_data/auto_generated/dnx_data_dev_init.h>
#include <soc/dnx/utils/dnx_pp_programmability_utils.h>
#include <soc/drv_prop.h>
#include <soc/dnx/dbal/dbal.h>
#include <soc/dnx/dnx_err_recovery_manager.h>

#include <appl/reference/dnxc/appl_ref_init_deinit.h>
#include <appl/reference/dnxc/appl_ref_init_utils.h>
#include <appl/reference/dnx/appl_ref_init_deinit.h>
#include <appl/reference/dnx/appl_ref_sys_ports.h>
#include <appl/reference/dnx/appl_ref_sniff_ports.h>
#include <appl/reference/dnx/appl_ref_e2e_scheme.h>
#include <appl/reference/dnx/appl_ref_dynamic_port.h>
#include "appl_ref_mtu_compressed_layer_type.h"
#include "appl_ref_oam_init.h"
#include "appl_ref_l2_init.h"
#include "appl_ref_vlan_init.h"
#include "appl_ref_qos_init.h"
#include "appl_ref_rx_trap_init.h"
#include "appl_ref_dram_init.h"
#include "appl_ref_hard_reset_init.h"
#include "appl_ref_compensation_init.h"
#include "appl_ref_sys_device.h"
#include "appl_ref_kbp_init.h"
#include "appl_ref_linkscan_init.h"
#include "appl_ref_field_j1_itmh_init.h"
#include "appl_ref_field_j1_itmh_pph_init.h"
#include "appl_ref_field_itmh_pph_init.h"
#include "appl_ref_field_ftmh_mc_init.h"
#include "appl_ref_field_rch_handle_init.h"
#include "appl_ref_field_nat_init.h"
#include "appl_ref_srv6_field_init_deinit.h"
#include "appl_ref_field_init.h"
#include "appl_ref_eedb_access_init.h"
#include <appl/reference/dnxc/appl_ref_intr.h>
#include <appl/reference/dnxc/appl_ref_shell_threads.h>
#include "appl_ref_rx_init.h"

/*
 * }
 */

/**
 * Skip the initiallization of Non-L1 datapath
 */
static shr_error_e
l1_mode_skip(
    int unit,
    int *dynamic_flags)
{
    SHR_FUNC_INIT_VARS(unit);

    if (!dnx_data_dev_init.general.feature_get(unit, dnx_data_dev_init_general_is_pp_used))
    {
        *dynamic_flags = UTILEX_SEQ_STEP_F_SKIP;
    }
    SHR_FUNC_EXIT;
}

static shr_error_e
bare_metal_skip(
    int unit,
    int *dynamic_flags)
{
    uint8 is_default_image = FALSE;

    SHR_FUNC_INIT_VARS(unit);

    *dynamic_flags = 0;

    if (!_SHR_IS_FLAG_SET(dnxc_data_mgmt_state_get(unit), DNXC_DATA_STATE_F_DEV_DATA_DONE))
    {
        SHR_EXIT();
    }

    SHR_IF_ERR_EXIT(dnx_pp_prgm_default_image_check(unit, &is_default_image));

    if (!is_default_image)
    {
        *dynamic_flags = UTILEX_SEQ_STEP_F_SKIP;
    }
    SHR_IF_ERR_EXIT(l1_mode_skip(unit, dynamic_flags));

exit:
    SHR_FUNC_EXIT;
}

/**
 * Skip the initiallization of Oamp module when Oamp is disabled
 */
static shr_error_e
oam_skip(
    int unit,
    int *dynamic_flags)
{
    uint8 is_default_image = FALSE;
    uint8 is_oam_not_supported = FALSE;

    SHR_FUNC_INIT_VARS(unit);

    *dynamic_flags = 0;

    SHR_IF_ERR_EXIT(dnx_pp_prgm_default_image_check(unit, &is_default_image));
    is_oam_not_supported = dnx_data_oam.general.feature_get(unit, dnx_data_oam_general_oam_not_supported);

    if ((!is_default_image) || (is_oam_not_supported == 1))
    {
        *dynamic_flags = DNX_INIT_STEP_F_SKIP;
    }
    SHR_IF_ERR_EXIT(l1_mode_skip(unit, dynamic_flags));

exit:
    SHR_FUNC_EXIT;
}

/**
 * Skip the initiallization of itmh_pph module when itmh is disabled
 */
static shr_error_e
appl_dnx_field_itmh_pph_cb(
    int unit,
    int *dynamic_flags)
{
    SHR_FUNC_INIT_VARS(unit);

    /*
     * ITMH_PPH appl is not relevant in case of ITMH appl is disabled
     */
    if (soc_property_suffix_num_get(unit, 0, spn_APPL_ENABLE, "field_itmh_pph", 1)
        && !soc_property_suffix_num_get(unit, 0, spn_APPL_ENABLE, "field_itmh", 1))
    {
        SHR_ERR_EXIT(_SHR_E_FAIL, "ITMH_PPH appl cannot be enabled when ITMH appl is disabled\n");
    }

    /*
     * Assuming PPH is not exposed in bare metal
     * to support need to do similar check as for ITMH only (check if layer type configured)
     * */
    SHR_IF_ERR_EXIT(bare_metal_skip(unit, dynamic_flags));
exit:
    SHR_FUNC_EXIT;
}

/**
 * Skip the initiallization of itmh_pph module when itmh is disabled
 */
static shr_error_e
appl_dnx_field_itmh_cb(
    int unit,
    int *dynamic_flags)
{
    uint8 is_illegal = FALSE;
    SHR_FUNC_INIT_VARS(unit);

    /*
     * ITMH_ appl is not relevant if layer type ITMH is not mapped on an image
     */
    SHR_IF_ERR_EXIT(dbal_fields_is_illegal_value
                    (unit, DBAL_FIELD_LAYER_TYPES, DBAL_ENUM_FVAL_LAYER_TYPES_ITMH, &is_illegal));
    if (is_illegal)
    {
        *dynamic_flags = UTILEX_SEQ_STEP_F_SKIP;
    }
    SHR_IF_ERR_EXIT(l1_mode_skip(unit, dynamic_flags));

exit:
    SHR_FUNC_EXIT;
}

/*
 * Typedefs.
 * {
 */

/*
 * }
 */

/*
 * Globals.
 * {
 */

/*
 * }
 */

/**
 * \brief - init of first step of appl ref
 *
 * \param [in] unit - unit #
 * \return
 * \see
 *   * None
 */
int
appl_dnx_first_init(
    int unit)
{
    SHR_FUNC_INIT_VARS(unit);

    SHR_IF_ERR_EXIT(dnx_err_recovery_transaction_no_support_counter_inc(unit, __func__));

    SHR_EXIT();
exit:
    SHR_FUNC_EXIT;
}

/**
 * \brief - deinit of first step of appl ref
 *
 * \param [in] unit - unit #
 * \return
 * \see
 *   * None
 */
int
appl_dnx_first_deinit(
    int unit)
{
    SHR_FUNC_INIT_VARS(unit);

    SHR_EXIT();
exit:
    SHR_FUNC_EXIT;
}

/**
 * \brief - init of last meaningful step of appl ref
 *
 * \param [in] unit - unit #
 * \return
 * \see
 *   * None
 */
int
appl_dnx_end_init(
    int unit)
{
    SHR_FUNC_INIT_VARS(unit);

    SHR_IF_ERR_EXIT(dnx_err_recovery_transaction_no_support_counter_dec(unit));

    SHR_EXIT();
exit:
    SHR_FUNC_EXIT;
}

/**
 * \brief - deinit of last meaningful step of appl ref
 *
 * \param [in] unit - unit #
 * \return
 * \see
 *   * None
 */
int
appl_dnx_end_deinit(
    int unit)
{
    SHR_FUNC_INIT_VARS(unit);

    SHR_EXIT();
exit:
    SHR_FUNC_EXIT;
}

/* *INDENT-OFF* */

/**
 * \brief DNX reference applications sequence
 *        * Each reference application in the init sequence should be added here.
 *        * Each application can be enabled or disabled using a dedicated.
 *          soc property which uses the "suffix" as an argument: 'appl_enable_<suffix>=0/1'.
 *        * Additional information can be passed to the applications by using a dedicated
 *          soc property: 'appl_param_<suffix>=val'.
 *        * The last step must be all NULLs./
 */
static const appl_dnxc_init_step_t appl_dnx_ref_apps_steps[] = {
    /*STEP_ID                              NAME                          SUFFIX             INIT_FUNC                                        DEINIT_FUNC                       FLAG_CB                        STEP_FLAGS                                SUB_LIST*/
    {APPL_DNX_STEP_FIRST,                  "Misc First Step",            "first",            appl_dnx_first_init,                            appl_dnx_first_deinit,            NULL,                           STANDALONE,                              NULL},
#if defined(INCLUDE_KBP)
    {APPL_DNX_STEP_KBP,                    "KBP",                        "kbp",              appl_dnx_kbp_init,                              appl_dnx_kbp_deinit,              NULL,                           DEF_PROP_EN | PARALLEL,                  NULL},
#endif
    {APPL_DNX_STEP_SYS_PARAMS,             "System Params",              "sys_params",       appl_dnx_sys_params_parse,                      appl_dnx_sys_params_free,         wb_test_mode_skip,              DEF_PROP_EN | STANDALONE,                NULL},
    {APPL_DNX_STEP_SYS_DEVICE,             "System Device",              "sys_device",       appl_dnx_sys_device_init,                       NULL,                             NULL,                           DEF_PROP_EN | WB_SKIP,                   NULL},
/** APPL_DNX_STEP_EEDB_ACCESS must be before APPL_DNX_STEP_SYS_PORTS as it adds ports which need to be handled by subsequent steps */
    {APPL_DNX_STEP_EEDB_ACCESS,            "EEDB Access",                "eedb_access",      appl_dnx_eedb_access_init,                      NULL,                             appl_dnx_eedb_access_cb,        DEF_PROP_EN | WB_SKIP,                   NULL},
    {APPL_DNX_STEP_SYS_PORTS,              "System Ports",               "sys_ports" ,       appl_dnx_sys_ports_init,                        NULL,                             NULL,                           DEF_PROP_EN | WB_SKIP | TIME_PER_DEV,    NULL},
    {APPL_DNX_STEP_SNIFF_PORTS,            "Sniff Ports",                "sniff_ports",      appl_dnx_sniff_ports_init,                      NULL,                             NULL,                           DEF_PROP_EN | WB_SKIP,                   NULL},
    {APPL_DNX_STEP_PP_ETH_PROCESSING,      "Port initial settings",      "dyn_ports" ,       appl_dnx_dyn_ports_packet_processing_eth_init,  NULL,                             NULL,                           DEF_PROP_EN | WB_SKIP,                   NULL},
    {APPL_DNX_STEP_LINKSCAN,               "Linkscan",                   "linkscan" ,        appl_dnx_linkscan_init,                         appl_dnx_linkscan_deinit,         NULL,                           DEF_PROP_EN | WB_SKIP | TIME_PER_DEV,    NULL},
    {APPL_DNX_STEP_E2E_SCHEME,             "E2E Scheme",                 "e2e_scheme",       appl_dnx_e2e_scheme_init,                       NULL,                              NULL,                          DEF_PROP_EN | WB_SKIP | TIME_PER_DEV,    NULL},
    {APPL_DNX_STEP_L2,                     "L2",                         "l2",               appl_dnx_l2_init,                               NULL,                              bare_metal_skip,               DEF_PROP_EN | WB_SKIP,                   NULL},
    {APPL_DNX_STEP_VLAN,                   "Vlan",                       "vlan",             appl_dnx_vlan_init,                             NULL,                              bare_metal_skip,               DEF_PROP_EN | WB_SKIP | TIME_PER_DEV,    NULL},
    {APPL_DNX_STEP_COMPRESSED_LAYER_TYPE,  "Compressed layer type",      "clt",              appl_dnx_mtu_compressed_layer_type_init,        NULL,                              bare_metal_skip,               DEF_PROP_EN | WB_SKIP,                   NULL},
    {APPL_DNX_STEP_OAM,                    "Oam",                        "oam",              appl_dnx_oam_init,                              NULL,                              oam_skip,                     DEF_PROP_EN | WB_SKIP | TIME_PER_DEV,    NULL},
    {APPL_DNX_STEP_QOS,                    "QOS",                        "qos",              appl_dnx_qos_init,                              NULL,                              l1_mode_skip,                  DEF_PROP_EN | WB_SKIP | TIME_PER_DEV,    NULL},
    {APPL_DNX_STEP_RX_TRAP,                "RX Trap",                    "rx_trap",          appl_dnx_rx_trap_init,                          NULL,                              NULL,                          DEF_PROP_EN | WB_SKIP,                   NULL},
    {APPL_DNX_STEP_ITMH_PPH,               "Field ITMH_PPH",             "field_itmh_pph",   appl_dnx_field_itmh_pph_init,                   NULL,                              appl_dnx_field_itmh_pph_cb,    DEF_PROP_EN | WB_SKIP | TIME_PER_DEV,    NULL},
    {APPL_DNX_STEP_ITMH,                   "Field ITMH",                 "field_itmh",       appl_dnx_field_itmh_init,                       NULL,                              appl_dnx_field_itmh_cb,               DEF_PROP_EN | WB_SKIP,                   NULL},
    {APPL_DNX_STEP_J1_ITMH,                "Field J1 ITMH",              "field_j1_itmh",    appl_dnx_field_j1_itmh_init,                    NULL,                              appl_dnx_field_j1_itmh_cb,     DEF_PROP_EN | WB_SKIP,                   NULL},
    {APPL_DNX_STEP_J1_ITMH_PPH,            "Field J1 ITMH_PPH",          "field_j1_itmh_pph",appl_dnx_field_j1_itmh_pph_init,                NULL,                              appl_dnx_field_j1_itmh_pph_cb, DEF_PROP_EN | WB_SKIP,                   NULL},
    {APPL_DNX_STEP_FTMH_MC,                "Field FTMH MC",              "field_ftmh_mc",    appl_dnx_field_ftmh_mc_init,                    NULL,                              appl_dnx_field_ftmh_mc_cb,     DEF_PROP_EN | WB_SKIP,                   NULL},
    {APPL_DNX_STEP_RCH_HANDLE,             "Field RCH handle",           "field_rch_handle", appl_dnx_field_rch_handle_init,                 NULL,                              bare_metal_skip,               DEF_PROP_EN | WB_SKIP,                   NULL},
    {APPL_DNX_STEP_SRV6,                   "Field SRV6",                 "field_srv6",       appl_dnx_field_srv6_init,                       NULL,                              appl_dnx_field_srv6_cb,        DEF_PROP_EN | WB_SKIP | TIME_PER_DEV,    NULL},
    {APPL_DNX_STEP_NAT,                    "Field NAT",                  "field_nat",        appl_dnx_field_nat_init,                        NULL,                              NULL,                          DEF_PROP_DIS | WB_SKIP | TIME_PER_DEV,   NULL},
    {APPL_DNX_STEP_INTERRUPT,              "Interrupt Init",             "intr_init",        appl_dnxc_interrupt_init,                       appl_dnxc_interrupt_deinit,        NULL,                          DEF_PROP_EN,                             NULL},
    {APPL_DNX_STEP_DRAM,                   "Dram cb registration",       "dram_cb_reg",      appl_dnx_dram_cb_register,                      appl_dnx_dram_cb_unregister,       NULL,                          DEF_PROP_EN,                             NULL}, /* this step should run after WB */
    {APPL_DNX_STEP_HARD_RESET,             "Hard Reset cb registration", "hard_reset_cb_reg",appl_dnx_hard_reset_cb_register,                appl_dnx_hard_reset_cb_unregister, NULL,                          DEF_PROP_EN,                             NULL},
    {APPL_DNX_STEP_VISIBILITY,             "Visibility Config",          "visibility",       appl_dnx_sys_vis_enable,                        NULL,                              l1_mode_skip,                  DEF_PROP_EN | WB_SKIP,                   NULL},
    {APPL_DNX_STEP_COMPENSATION,           "Compensation",               "compensation",     appl_dnx_compensation_init,                     NULL,                              NULL,                          DEF_PROP_EN | WB_SKIP,                   NULL},
    {APPL_DNX_STEP_RX,                     "RX",                         "rx",               appl_dnx_rx_init,                               appl_dnx_rx_deinit,                NULL,                          DEF_PROP_EN | MEM_TEST_SKIP,             NULL},
    {APPL_DNX_STEP_TRAFFIC_EN,             "Traffic Enable",             "traffic",          appl_dnx_sys_traffic_enable,                    NULL,                              NULL,                          DEF_PROP_EN | WB_SKIP,                   NULL}, /* this step must be last */
    {APPL_DNX_STEP_SHELL_THREADS,          "Shell threads",              "shell_threads",    NULL,                                           appl_dnxc_shell_threads_deinit,    NULL,                          DEF_PROP_EN,                             NULL},
    {APPL_DNX_STEP_END,                    "Misc End Step",              "end",              appl_dnx_end_init,                              appl_dnx_end_deinit,               NULL,                          STANDALONE,                              NULL},
    {APPL_DNX_STEP_LAST_STEP,              NULL,                         NULL,               NULL,                                           NULL,                              NULL,                          0,                                       NULL} /* Last step must be all NULLs*/

};




/**
 * \brief DNX reference Field applications sequence
 *        * Each refernce application in the init sequence should be added here.
 *        * Each application can be enabled or disabled using a dedicated.
 *          soc property which uses the "suffix" as an argument: 'appl_enable_<suffix>=0/1'.
 *        * Additional information can be passed to the applications by using a dedicated
 *          soc property: 'appl_param_<suffix>=val'.
 *        * The last step must be all NULLs.
 */
static const appl_dnxc_init_step_t appl_dnx_ref_field_apps_steps[] = {
    /*STEP_ID                              NAME                         SUFFIX                 INIT_FUNC                                DEINIT_FUNC    FLAG_CB                                  STEP_FLAGS                           SUB_LIST*/
    {APPL_DNX_STEP_FP_FEC_DEST,         "Field FEC Dest",         "fec_dest_init",       appl_dnx_field_fec_dest_init,         NULL,          appl_dnx_field_fec_dest_cb,           DEF_PROP_EN | WB_SKIP,               NULL},
    {APPL_DNX_STEP_FP_OAM_INDEX,        "Field OAM FWD Index",    "oam_fwd_idx_init",    appl_dnx_field_oam_layer_index_init,  NULL,          appl_dnx_field_oam_layer_index_cb,    DEF_PROP_EN | WB_SKIP | TIME_PER_DEV,   NULL},
    {APPL_DNX_STEP_FP_TRAP_L4,          "Field L4 Trap",          "L4_trap_init",        appl_dnx_field_trap_l4_init,          NULL,          appl_dnx_field_trap_l4_cb,            DEF_PROP_DIS| WB_SKIP,               NULL},
    {APPL_DNX_STEP_FP_OAM_STAT,         "Field OAM Stat",         "oam_stat_init",       appl_dnx_field_oam_stat_init,         NULL,          appl_dnx_field_oam_stat_cb,           DEF_PROP_EN | WB_SKIP,               NULL},
    {APPL_DNX_STEP_FP_FLOW_ID,          "Field Flow Id",          "flow_id_init",        appl_dnx_field_flow_id_init,          NULL,          appl_dnx_field_flow_id_cb,            DEF_PROP_EN | WB_SKIP,               NULL},
    {APPL_DNX_STEP_FP_ROO,              "Field ROO",              "roo_init",            appl_dnx_field_roo_init,              NULL,          appl_dnx_field_roo_cb,                DEF_PROP_EN | WB_SKIP,               NULL},
    {APPL_DNX_STEP_FP_DISABLE_ERPP_COUNTERS, "Field Disable ERPP Counters", "disable_erpp_counters_init", appl_dnx_field_disable_erpp_counters_init, NULL, appl_dnx_field_disable_erpp_counters_cb, DEF_PROP_EN | WB_SKIP, NULL},
    {APPL_DNX_STEP_FP_IPMC_INLIF,       "Field IPMC INLIF",       "ipmc_inlif_init",     appl_dnx_field_ipmc_inlif_init,       NULL,          appl_dnx_field_ipmc_inlif_cb,         DEF_PROP_EN | WB_SKIP,               NULL},
    {APPL_DNX_STEP_FP_EBTR_ETH_LAYER,   "Field ebtr eth layer",   "ebtr_eth_lyaer",      appl_dnx_field_eth_fwd_layer_ebtr,    NULL,          appl_dnx_field_ebtr_eth_layer_cb,     DEF_PROP_EN | WB_SKIP,               NULL},
    {APPL_DNX_STEP_FP_BIER,             "Field bier",             "bier",                appl_dnx_field_bier_init,             NULL,          NULL,                                 DEF_PROP_EN | WB_SKIP,               NULL},
    {APPL_DNX_STEP_FP_J1_SAME_PORT,     "Field J1 Same port",     "j1_same_p_init",      appl_dnx_field_j1_same_port_init,     NULL,          appl_dnx_field_j1_same_port_cb,       DEF_PROP_EN | WB_SKIP,               NULL},
    {APPL_DNX_STEP_FP_LEARN_AND_LIMIT,  "Field Learn and Limit",  "learn_and_limit_init",appl_dnx_field_learn_and_limit_init,  NULL,          appl_dnx_field_learn_and_limit_cb,    DEF_PROP_EN | WB_SKIP,               NULL},
    {APPL_DNX_STEP_FP_LEARN_NULLIFY_KEY_MSBS,  "Field Learn Nullify Key msbs",  "learn_nullify_key_msbs",appl_dnx_field_learn_nullify_key_msbs_init,  NULL,       appl_dnx_field_learn_nullify_key_msbs_cb,    DEF_PROP_EN | WB_SKIP,  NULL},
    {APPL_DNX_STEP_FP_J1_PHP,           "Field J1 PHP",           "j1 php_init",         appl_dnx_field_jr1_php_init,          NULL,          appl_dnx_field_j1_php_cb,             DEF_PROP_EN | WB_SKIP,               NULL},
    {APPL_DNX_STEP_LAST_STEP,              NULL,                        NULL,                  NULL,                                    NULL,          NULL,                                    0,                                   NULL} /* Last step must be all NULLs*/

};


/**
 * \brief DNX init sequence
 *        * Each step in the init sequence should be added here
 *        * The init sequence has 2 main phases:
 *          1. Initialize SDK (create unit and init bcm)
 *          2. Run default reference applications - each application can be enabled or disabled using a dedicated
 *             soc property which uses the "suffix" as an argument: 'appl_enable_<suffix>=0/1'
 *        * The last step must be all NULLs
 */
static const appl_dnxc_init_step_t appl_dnx_init_steps[] = {
    /*STEP_ID                   NAME                     SUFFIX          INIT_FUNC                DEINIT_FUNC                 FLAGS_CB          STEP_FLAGS                         SUB_LIST*/
    {APPL_DNX_STEP_SDK,         "SDK",                   "",             appl_dnxc_sdk_init,      appl_dnxc_sdk_deinit,       NULL,             STANDALONE | ACCESS | TIME_PER_DEV,   NULL},
    {APPL_DNX_STEP_APPS,        "Applications",          "ref",          NULL,                    NULL,                       NULL,             DEF_PROP_EN | TIME_PER_DEV,           appl_dnx_ref_apps_steps},
    {APPL_DNX_STEP_FP_APPS,     "Field Applications",    "field_app",    NULL,                    NULL,                       bare_metal_skip,  DEF_PROP_EN | TIME_PER_DEV,           appl_dnx_ref_field_apps_steps},
    {APPL_DNX_STEP_INIT_DONE,   "Init Done",             "init_done",    appl_dnx_init_done_init, appl_dnx_init_done_deinit,  NULL,             DEF_PROP_EN | JOIN,                   NULL}, /* this step must be last */
    {APPL_DNX_STEP_LAST_STEP,    NULL,                    NULL,          NULL,                    NULL,                       NULL,             0,                                    NULL}  /* Last step must be all NULLs*/
};

/* *INDENT-ON* */

/*
 * See .h file
 */
shr_error_e
appl_dnx_step_list_get(
    int unit,
    const appl_dnxc_init_step_t ** appl_steps)
{
    SHR_FUNC_INIT_VARS(unit);

    /*
     * return pointer to the list of DNX application init steps
     */
    *appl_steps = appl_dnx_init_steps;

    SHR_FUNC_EXIT;
}

/*
 * See .h file
 */
shr_error_e
appl_dnx_per_dev_step_time_threshold_get(
    int unit,
    int step_id,
    utilex_step_time_dnx_data * step_id_dnx_data)
{
    SHR_FUNC_INIT_VARS(unit);

    /*
     * Get the per-device threshold for specified step
     */
    step_id_dnx_data->step_time = dnx_data_dev_init.time.appl_step_time_get(unit, step_id)->time;
    step_id_dnx_data->down_deviation = dnx_data_dev_init.time.appl_step_time_get(unit, step_id)->down_deviation;
    step_id_dnx_data->up_deviation = dnx_data_dev_init.time.appl_step_time_get(unit, step_id)->up_deviation;
    step_id_dnx_data->test_sensitivity = dnx_data_dev_init.time.test_sensitivity_get(unit);
    step_id_dnx_data->non_perc_up_deviation =
        dnx_data_dev_init.time.appl_step_time_get(unit, step_id)->non_perc_up_deviation;

    SHR_FUNC_EXIT;
}

/*
 * See .h file
 */
shr_error_e
appl_dnx_per_dev_full_time_threshold_get(
    int unit,
    utilex_step_time_dnx_data * step_id_dnx_data)
{
    SHR_FUNC_INIT_VARS(unit);

    /*
     * Get the per-device threshold for specified step
     */
    step_id_dnx_data->step_time = dnx_data_dev_init.time.appl_init_total_time_get(unit);
    step_id_dnx_data->down_deviation = dnx_data_dev_init.time.down_deviation_total_get(unit);
    step_id_dnx_data->up_deviation = dnx_data_dev_init.time.up_deviation_total_get(unit);
    step_id_dnx_data->test_sensitivity = dnx_data_dev_init.time.test_sensitivity_get(unit);

    SHR_FUNC_EXIT;
}
