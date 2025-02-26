/** \file diag_dnx_cmdlist.c
 *
 * Purpose: List of commands specific for SOC_IS_DNX devices
 */
/**
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2022 Broadcom Inc. All rights reserved.
 * 
 */

#include <appl/diag/shell.h>
#include <appl/diag/cmdlist.h>
#include <appl/diag/sand/diag_sand_prt.h>
#include <appl/diag/sand/diag_sand_framework.h>
#include <appl/diag/sand/diag_sand_access.h>
#include <appl/diag/sand/diag_sand_packet.h>
#include <appl/diag/sand/diag_sand_mbist.h>
#include <appl/diag/dnxc/diag_dnxc_diag.h>
#include <appl/diag/dnx/diag_dnx_cmdlist.h>
#include <appl/diag/dnx/diag_dnx_utils.h>
#include <appl/diag/dnx/diag_dnx_field.h>
#include <appl/diag/dnx/diag_dnx_l2.h>
#include <appl/diag/dnx/diag_dnx_fabric.h>
#include <appl/reference/dnx/appl_ref_init_deinit.h>
#include <src/appl/reference/dnx/minicontroller/diag_dnx_minicon.h>
#include <appl/diag/dnx/diag_dnx_diag.h>
#include <bcm_int/dnx/algo/port/algo_port_mgmt.h>

#ifdef INCLUDE_CTEST
#include <appl/ctest/dnx/ctest_dnx_root.h>
#include <appl/ctest/dnxc/ctest_dnxc_system.h>
#endif

#ifdef DNX_SW_STATE_DIAGNOSTIC
#include "swstate/auto_generated/diagnostic/swstate_commandline.h"
#include "../dnxc/swstate/auto_generated/diagnostic/swstate_commandline.h"
#endif /* DNX_SW_STATE_DIAGNOSTIC */

#include "knet/diag_dnx_knet.h"
#include "arr/diag_dnx_arr.h"
#include "adapter/diag_dnx_adapter.h"
#include "crps/diag_dnx_crps.h"
#include "dbal/diag_dnx_dbal.h"
#include "pp/diag_dnx_pp.h"
#include "export/diag_dnx_export.h"
#include "gpm/diag_dnx_gpm.h"
#include "reset/diag_dnx_reset.h"
#include "mdb/diag_dnx_mdb.h"
#include "utils/diag_dnx_utils_sbusdma_desc.h"
#include "meter/diag_dnx_meter.h"
#include "port/diag_dnx_port.h"
#include "tm/diag_dnx_tm.h"
#include "dram/diag_dnx_dram.h"
#include "tx/diag_dnx_tx.h"
#include "vlan/diag_dnx_vlan.h"
#include "l3/diag_dnx_l3.h"
#include "stg/diag_dnx_stg.h"
#include "lsm/diag_dnx_lsm.h"
#include "stif/diag_dnx_stif.h"
#include "oam/diag_dnx_oam.h"
#include "nif/diag_dnx_nif.h"
#include "trap/diag_dnx_trap.h"
#include "../dnxc/diag_dnxc.h"
#include "../dnxc/thread/diag_dnxc_thread.h"
#include "time_analyzer/diag_dnx_time_analyzer.h"
#include "srv6/diag_dnx_srv6.h"
#include "allocation_mngr/diag_dnx_allocation_mngr.h"
#include <appl/diag/dnx/diag_dnx_lif.h>
#include "error_recovery/diag_dnx_error_recovery.h"
#if defined(INCLUDE_KBP)
#include "kbp/diag_dnx_kbp.h"
#endif
#include "framer/diag_dnx_flexe.h"
#include "framer/diag_dnx_framer.h"
#ifdef INCLUDE_XFLOW_MACSEC
#include <dnx/diag_dnx_sec.h>
#endif
#include "flow/diag_dnx_flow.h"
#include "swstate/diag_dnx_swstate.h"

#define BSL_LOG_MODULE BSL_LS_APPL_SHELL

extern sh_sand_legacy_cmd_t sh_dnx_legacy_commands[];
extern sh_sand_man_t sh_dnx_visibility_man;
extern sh_sand_cmd_t sh_dnx_visibility_cmds[];
extern sh_sand_man_t sh_dnx_tdm_man;
extern sh_sand_cmd_t sh_dnx_tdm_cmds[];
extern sh_sand_man_t sh_dnx_gtimer_man;
extern sh_sand_cmd_t sh_dnx_gtimer_cmds[];

/*
 * List valid ports for dynamic port usage
 * in diagnositc command
 */
sh_sand_enum_t cmd_dnx_sh_valid_ports_table[] = {
    {"eth1", -1},
    {"eth2", -1},
    {"eth3", -1},
    {"eth4", -1},
    {"cpu1", -1},
    {"cpu2", -1},
    {"cpu3", -1},
    {"cpu4", -1},
    {NULL}
};

#define CMD_DNX_SH_PER_TYPE_VALID_PORT_NUM (4)

static sh_sand_man_t sh_dnx_man = {
    .brief = "Invocation point for dnx specific commands",
    .full = "DNX specific commands. Use \"dnx cmdname usage\" for details\n"
};

#ifndef BCM_SHARED_LIB_SDK
/* *INDENT-OFF* */
static sh_sand_cmd_t sh_dnx_commands[] = {
  /* Name                 | Leaf Action          | Junction Array Pointer         | Options for Leaf         | Usage */
    {"access",            NULL,                  sh_sand_access_cmds,             NULL,                      &sh_sand_access_man        , NULL, NULL, SH_CMD_NO_XML_VERIFY},
#ifdef ADAPTER_SERVER_MODE
    {"adapter",           NULL,                  sh_dnx_adapter_cmds,             NULL,                      &sh_dnx_adapter_man},
#endif
    {"AllocationManager", NULL,                  sh_dnx_allocation_mngr_cmds,     NULL,                      &sh_dnx_allocation_mngr_man, NULL, NULL, SH_CMD_NO_XML_VERIFY},
    {"application",       NULL,                  sh_dnxc_appl_cmds,               NULL,                      &sh_dnxc_appl_man},
    {"arr",               NULL,                  sh_dnx_arr_cmds,                 NULL,                      &sh_dnx_arr_man},
    {"avs",               NULL,                  sh_dnxc_avs_cmds,                NULL,                      &sh_dnxc_avs_man},
    {"calibrate",         sh_dnxc_calibrate_cmd, NULL,                            NULL,                      &sh_dnxc_calibrate_man     , NULL, NULL, SH_CMD_SKIP_EXEC * SH_CMD_INIT_REQUIRED},
    {"clear",             NULL,                  sh_dnxc_clear_cmds,              NULL,                      &sh_dnxc_clear_man},
    {"compare",           NULL,                  sh_dnx_err_rec_comparison_cmds,  NULL,                      &sh_dnx_err_rec_comparison_jrnl_man},
    {"counter",           cmd_dnxc_counter,      NULL,                            dnxc_counter_options,      &sh_dnx_counter_man        , NULL, NULL, SH_CMD_SKIP_MEMORY_CHECK},
    {"crps",              NULL,                  sh_dnx_crps_cmds,                NULL,                      &sh_dnx_crps_man},
    {"data",              NULL,                  sh_dnxc_data_cmds,               NULL,                      &sh_dnxc_data_man},
    {"dbal",              NULL,                  sh_dnx_dbal_cmds,                NULL,                      &sh_dnx_dbal_man},
    {"DEviceReset",       sh_dnx_reset_cmd,      NULL,                            sh_dnx_reset_options,      &sh_dnx_reset_man          , NULL, NULL, SH_CMD_NO_XML_VERIFY * SH_CMD_INIT_REQUIRED},
    {"DmaDescAgg",        NULL,                  sh_dnx_utils_sbusdma_desc_cmds,  NULL,              &sh_dnx_utils_sbusdma_desc_man},
    /** diag is for backward compatibility commands only, no new functionality should use it */
    {"diag",              NULL,                  sh_dnxc_diag_cmds,               NULL,                      &sh_dnxc_diag_man},
    {"dram",              NULL,                  sh_dnx_dram_cmds,                NULL,                      &sh_dnx_dram_man           , NULL, NULL, SH_CMD_CONDITIONAL, sh_cmd_is_dram_available},
    {"export",            cmd_dnx_export_script, NULL,                            dnx_export_script_options, &dnx_export_script_man},
    {"fabric",            NULL,                  sh_dnxc_fabric_cmds,             NULL,                      &sh_dnxc_fabric_man        , NULL, NULL, SH_CMD_CONDITIONAL, sh_cmd_is_fabric_available},
    {"field",             NULL,                  Sh_dnx_field_cmds,               NULL,                      &Sh_dnx_field_man},
    {"FLexE",             NULL,                  sh_dnx_diag_flexe_cmds,          NULL,                      &sh_dnx_diag_flexe_man     , NULL, NULL, SH_CMD_CONDITIONAL * SH_CMD_NO_XML_VERIFY * SH_CMD_NOT_RELEASE, sh_cmd_is_flexe_available},
#ifndef NO_FRAMER_LIB_BUILD
    {"Framer",            NULL,                  sh_dnx_diag_framer_cmds,         NULL,                      &sh_dnx_diag_framer_man    , NULL, NULL, SH_CMD_CONDITIONAL * SH_CMD_NO_XML_VERIFY, sh_cmd_is_flexe_gen2},
#endif
    {"flow",              NULL,                  sh_dnx_flow_cmds,                NULL,                      &sh_dnx_flow_man},
    {"gpm",               NULL,                  sh_dnx_gpm_cmds,                 NULL,                      &sh_dnx_gpm_man},
    {"gtimer",            NULL,                  sh_dnx_gtimer_cmds,              NULL,                      &sh_dnx_gtimer_man},
    {"init_dnx",          sh_dnxc_init_dnx_cmd,  NULL,                            sh_dnxc_init_dnx_options,  &sh_dnxc_init_dnx_man      , NULL, NULL, SH_CMD_SKIP_EXEC * SH_CMD_INIT_REQUIRED},
    
    {"interrupt",         NULL,                  sh_dnxc_intr_cmds,               NULL,                      &sh_dnxc_intr_man},
#if defined(INCLUDE_KBP)
    {"kbp",               NULL,                  sh_dnx_kbp_cmds,                 NULL,                      &sh_dnx_kbp_man},
#endif
    {"layer2",            NULL,                  sh_dnx_l2_cmds,                  NULL,                      &sh_dnx_l2_man},
    {"layer3",            NULL,                  sh_dnx_l3_cmds,                  NULL,                      &sh_dnx_l3_man},
    {"linkscan",          cmd_dnxc_linkscan,     NULL,                            dnxc_linkscan_options,     &sh_dnx_linkscan_man},
    {"lif",               NULL,                  sh_dnx_lif_cmds,                 NULL,                      &sh_dnx_lif_man},
    {"lsm",               NULL,                  Dnx_lsm_cmds,                    NULL,                      &Dnx_lsm_man},
    {"mbist",             NULL,                  sh_sand_mbist_cmds,              NULL,                      &sh_sand_mbist_man         , NULL, NULL, SH_CMD_NOT_RELEASE},
    {"mdb",               NULL,                  sh_dnx_mdb_cmds,                 NULL,                      &sh_dnx_mdb_man            , NULL, NULL, SH_CMD_SKIP_MEMORY_CHECK},
    {"meter",             NULL,                  sh_dnx_meter_cmds,               NULL,                      &sh_dnx_meter_man},
    {"MTA",               NULL,                  sh_dnxc_mta_cmds,                NULL,                      &sh_dnxc_mta_man           , NULL, NULL, SH_CMD_NOT_RELEASE},
    {"MINICONtroller",    NULL,                  sh_dnx_minicon_cmds,             NULL,                      &sh_dnx_minicon_man        , NULL, NULL, SH_CMD_CONDITIONAL, diag_minicom_bare_metal_check},
    {"nif",               NULL,                  sh_dnx_nif_cmds,                 NULL,                      &sh_dnx_nif_man},
    {"oam",               NULL,                  sh_dnx_oam_cmds,                 NULL,                      &sh_dnx_oam_man},
    {"packet",            NULL,                  sh_sand_packet_cmds,             NULL,                      &sh_sand_packet_man        , NULL, NULL, SH_CMD_SKIP_MEMORY_CHECK},
    {"pbmp",              cmd_dnxc_pbmp,         NULL,                            dnxc_pbmp_options,         &sh_dnxc_pbmp_man},
    {"phy",               NULL,                  sh_dnxc_phy_cmds,                NULL,                      &sh_dnxc_phy_man},
    {"port",              NULL,                  sh_dnx_port_cmds,                NULL,                      &sh_dnx_port_man},
    {"PP",                NULL,                  sh_dnx_pp_cmds,                  NULL,                      &sh_dnx_pp_man},
#ifdef INCLUDE_XFLOW_MACSEC
    {"SEC",               NULL,                  sh_dnx_sec_cmds,                 NULL,                      &sh_dnx_sec_man            , NULL, NULL, SH_CMD_CONDITIONAL * SH_CMD_NO_XML_VERIFY * SH_CMD_NOT_RELEASE, sh_cmd_is_sec_available},
#endif
    {"SER",               NULL,                  sh_dnx_diag_ser_cmds,            NULL,                      &sh_dnxc_diag_ser_man},
    {"show",              NULL,                  sh_dnxc_show_cmds,               NULL,                      &sh_dnxc_show_man          , NULL, NULL, SH_CMD_INIT_REQUIRED},
    {"signal",            NULL,                  sh_sand_signal_cmds,             NULL,                      &sh_sand_signal_man        , NULL, NULL, SH_CMD_NO_XML_VERIFY},
    {"soc",               cmd_dnxc_soc,          NULL,                            NULL,                      &sh_dnxc_soc_man           , NULL, NULL, SH_CMD_NO_XML_VERIFY},
    {"srv6",              NULL,                  sh_dnx_srv6_diag_cmds,           NULL,                      &sh_dnx_srv6_man},
    {"stg",               NULL,                  sh_dnx_stg_cmds,                 NULL,                      &sh_dnx_stg_man},
    {"stif",              NULL,                  sh_dnx_stif_cmds,                NULL,                      &sh_dnx_stif_man},
    {"TeCHSupport",       NULL,                  sh_dnxc_techsupport_cmds,        NULL,                      &sh_dnxc_techsupport_man   , NULL, NULL, SH_CMD_SKIP_EXEC},
    {"TimeAnalyzer",      NULL,                  sh_dnx_time_analyzer_cmds,       NULL,                      &sh_dnx_time_analyzer_man},
    {"tdm",               NULL,                  sh_dnx_tdm_cmds,                 NULL,                      &sh_dnx_tdm_man            , NULL, NULL, SH_CMD_CONDITIONAL, sh_dnx_is_tdm_available},
    {"tm",                NULL,                  sh_dnx_tm_cmds,                  NULL,                      &sh_dnx_tm_man},
    {"transaction",       NULL,                  sh_dnx_err_rec_transaction_cmds, NULL,                      &sh_dnx_err_rec_transaction_jrnl_man},
    {"ERRor_Recovery",    NULL,                  sh_dnx_err_rec_cmds,             NULL,                      &sh_dnx_err_rec_man},
    {"trap",              NULL,                  sh_dnx_trap_cmds,                NULL,                      &sh_dnx_trap_man},
    {"THreaD",            NULL,                  sh_dnxc_thread_cmds,             NULL,                      &sh_dnxc_thread_man        , NULL, NULL, SH_CMD_SKIP_EXEC},
    {"visibility",        NULL,                  sh_dnx_visibility_cmds,          NULL,                      &sh_dnx_visibility_man},
    {"vlan",              NULL,                  sh_dnx_vlan_cmds,                NULL,                      &sh_dnx_vlan_man},
#ifdef BCM_WARM_BOOT_SUPPORT
    {"warmboot",          NULL,                  sh_dnxc_warmboot_cmds,           NULL,                      &sh_dnxc_warmboot_man      , NULL, NULL, SH_CMD_NO_XML_VERIFY, NULL, NULL, NULL, "", NULL, NULL, "FL_WARMBOOT"},
#endif
#ifdef INCLUDE_CTEST
    {"FRameWork",         NULL,                  sh_sand_shell_cmds,              NULL,                      &sh_sand_shell_man},
#endif
    {"tx",                sh_dnx_tx,             NULL,                            sh_dnx_tx_options,         &sh_dnx_tx_man             , NULL, NULL, SH_CMD_SKIP_EXEC},
#ifndef ADAPTER_SERVER_MODE
    {"DmaRomTest",        NULL,                  sh_dnx_drt_cmds,                 NULL,                      &sh_dnx_drt_man            , NULL, NULL, SH_CMD_SKIP_EXEC},
#endif
    {NULL} /* This line should always stay as last one */
};

sh_sand_man_t sh_swstate_root_man = {
    .brief = "SwState specific commands",
    .full  = "Root command for swstate tree. Use \"swstate usage\" for details\n"
};

/*
 * Invokes field is used to transfer system command array per command, relevant only for root level,
 * where no invokes are used
 */
sh_sand_cmd_t sh_all_dnx_commands[] = {
  /* Name                   | Action        | Node Array                    | Options       | Usage */
  /* This line must always stay first one - it is used to get to device specific commands */
    {"dnx",                 NULL,           sh_dnx_commands,                NULL,            &sh_dnx_man,          NULL, (sh_sand_invoke_t *)sh_sand_sys_cmds, SH_CMD_VERIFY * SH_CMD_SKIP_ROOT},
#ifdef INCLUDE_CTEST
    {"CTest",               NULL,           sh_dnx_ctest_commands,          NULL,            &sh_dnx_ctest_man,    NULL, (sh_sand_invoke_t *)sh_dnxc_sys_ctest_cmds},
#endif
#ifdef DNX_SW_STATE_DIAGNOSTIC
    
    {"swstate",             NULL,           sh_dnx_swstate_cmds,            NULL,            &sh_swstate_root_man, NULL, (sh_sand_invoke_t *)sh_sand_sys_cmds, SH_CMD_NO_PREFIX_NAME_LOOKUP},
    {"swstate_dnxc",        NULL,           sh_dnxc_swstate_cmds,           NULL,            &sh_swstate_root_man, NULL, (sh_sand_invoke_t *)sh_sand_sys_cmds, SH_CMD_NO_PREFIX_NAME_LOOKUP},
#endif /* DNX_SW_STATE_DIAGNOSTIC */
    {"swstate_new",         NULL,           sh_dnx_swstate_new_cmds,        NULL,            &sh_swstate_new_man,  NULL, (sh_sand_invoke_t *)sh_sand_sys_cmds, SH_CMD_NO_PREFIX_NAME_LOOKUP},
    {NULL} /* This line should always stay as last one */
};

#else /* BCM_SHARED_LIB_SDK */

static sh_sand_cmd_t sh_dnx_commands_lib_sdk[] = {
  /* Name         | Leaf Action          | Junction Array Pointer | Options for Leaf         | Usage */
    {"access",      NULL,                 sh_sand_access_cmds,    NULL,                     &sh_sand_access_man},
    {"application", NULL,                 sh_dnxc_appl_cmds,      NULL,                     &sh_dnxc_appl_man},
    {"dbal",        NULL,                 sh_dnx_dbal_cmds,       NULL,                     &sh_dnx_dbal_man},
    /** diag is for backward compatibility commands only, no new functionality should use it */
    {"diag",        NULL,                 sh_dnxc_diag_cmds,      NULL,                     &sh_dnxc_diag_man},
    {"init_dnx",    sh_dnxc_init_dnx_cmd, NULL,                   sh_dnxc_init_dnx_options, &sh_dnxc_init_dnx_man, NULL, NULL, SH_CMD_SKIP_EXEC},
    {"packet",      NULL,                 sh_sand_packet_cmds,    NULL,                     &sh_sand_packet_man},
    {"PP",          NULL,                 sh_dnx_pp_cmds,         NULL,                     &sh_dnx_pp_man},
    {"signal",      NULL,                 sh_sand_signal_cmds,    NULL,                     &sh_sand_signal_man},
    {"visibility",  NULL,                 sh_dnx_visibility_cmds, NULL,                     &sh_dnx_visibility_man},
    {"tx",          sh_dnx_tx,            NULL,                   sh_dnx_tx_options,        &sh_dnx_tx_man       , NULL, NULL, SH_CMD_SKIP_EXEC},
    {NULL} /* This line should always stay as last one */
};

/*
 * Invokes field is used to transfer system command array per command, relevant only for root level,
 * where no invokes are used
 */
sh_sand_cmd_t sh_all_dnx_commands[] = {
  /* Name     | Action | Node Array           | Options | Usage */
  /* This line must always stay first one - it is used to get to device specific commands */
    {"dnx",     NULL, sh_dnx_commands_lib_sdk,       NULL, &sh_dnx_man,          NULL, (sh_sand_invoke_t *)sh_sand_sys_cmds, SH_CMD_VERIFY * SH_CMD_SKIP_ROOT},
    {NULL} /* This line should always stay as last one */
};

#endif /* BCM_SHARED_LIB_SDK */
/* *INDENT-ON* */

#if defined(INCLUDE_CTEST)
extern shr_error_e cmd_dbal_dyn_ut_test_names_creation(
    int unit);
#endif

shr_error_e
cmd_dnx_sh_valid_ports_init(
    int unit)
{
    int port_i = 0;
    bcm_gport_t port;
    bcm_port_config_t port_config;

    SHR_FUNC_INIT_VARS(unit);

    SHR_IF_ERR_EXIT(bcm_port_config_get(unit, &port_config));

    /** Init ethernet ports */
    BCM_PBMP_ITER(port_config.e, port)
    {
        cmd_dnx_sh_valid_ports_table[port_i++].value = port;
        if (port_i >= CMD_DNX_SH_PER_TYPE_VALID_PORT_NUM)
        {
            break;
        }
    }

    /** Init CPU ports */
    port_i = CMD_DNX_SH_PER_TYPE_VALID_PORT_NUM;
    BCM_PBMP_ITER(port_config.cpu, port)
    {
        cmd_dnx_sh_valid_ports_table[port_i++].value = port;
        if (port_i >= 2 * CMD_DNX_SH_PER_TYPE_VALID_PORT_NUM)
        {
            break;
        }
    }

exit:
    SHR_FUNC_EXIT;
}

shr_error_e
cmd_dnx_sh_init(
    int unit)
{
    SHR_FUNC_INIT_VARS(unit);

    SHR_CLI_EXIT_IF_ERR(sh_sand_root_init(unit, sh_all_dnx_commands, sh_dnx_legacy_commands),
                        "DNX Shell Root Init Failed\n");

#if defined(INCLUDE_CTEST)
    SHR_IF_ERR_EXIT(cmd_dbal_dyn_ut_test_names_creation(unit));
#endif
exit:
    SHR_FUNC_EXIT;
}

shr_error_e
cmd_dnx_sh_deinit(
    int unit)
{
    SHR_FUNC_INIT_VARS(unit);

    SHR_CLI_EXIT_IF_ERR(sh_sand_root_deinit(unit), "DNX Shell Root Deinit Failed\n");

exit:
    SHR_FUNC_EXIT;
}

shr_error_e
cmd_dnx_sh_calibrate(
    int unit)
{
    SHR_FUNC_INIT_VARS(unit);

    SHR_CLI_EXIT_IF_ERR(sh_sand_cmd_calibrate(unit, sh_all_dnx_commands, sh_dnx_legacy_commands),
                        "DNX Shell Root Calibration Failed\n");

exit:
    SHR_FUNC_EXIT;
}

cmd_t bcm_dnx_cmd_list[] = {

    {"DMA", cmd_sand_dma, cmd_sand_dma_usage, "DMA Facilities Interface"},
    {"Dump", cmd_sand_mem_get, cmd_sand_mem_get_usage, "Dump an address space or registers"},
    {"Getreg", cmd_sand_reg_get, cmd_sand_reg_get_usage, "Get register"},
#ifdef INCLUDE_I2C
    {"I2C", cmd_i2c, cmd_i2c_usage, "Inter-Integrated Circuit (I2C) Bus commands"},
#endif
#ifdef INCLUDE_KNET
    {"KNETctrl", cmd_dnx_knet, cmd_dnx_knet_usage, "Manage kernel network functions"},
#endif
    {"LISTmem", cmd_sand_mem_list, cmd_sand_mem_list_usage, "List the entry format for a given table"},
    {"Listreg", cmd_sand_reg_list, cmd_sand_reg_list_usage, "List register fields"},
    {"MODify", cmd_sand_mem_modify, cmd_sand_mem_modify_usage, "Modify table entry by field names"},
    {"Modreg", cmd_sand_reg_modify, cmd_sand_reg_modify_usage, "Register Read/Modify/Write"},
    {"PacketWatcher", pw_command, pw_usage, "Monitor ports for packets"},
    {"PCIC", cmd_sand_pcic_access, cmd_sand_pcic_access_usage, "Access to PCI configuration space"},
    {"pcie", cmd_sand_pcie_reg, cmd_sand_pcie_reg_usage, "Read/Write from devices via pcie"},
#ifdef PORTMOD_DIAG
    {"PortMod", cmd_portmod_diag, portmod_diag_usage, "portmod diagnostics"},
#endif
    {"Set_Device", cmd_set_device, cmd_set_device_usage, "Common set_device command"},
    {"Setreg", cmd_sand_reg_set, cmd_sand_reg_set_usage, "Set register"},
#ifdef INCLUDE_TEST
    {"TestClear", test_clear, test_clear_usage, "Clear run statistics for a test"},
    {"TestList", test_print_list, test_list_usage, "List loaded tests and status"},
    {"TestMode", test_mode, test_mode_usage, "Set global test run modes"},
    {"TestParameters", test_parameters, test_parameters_usage, "Set test Parameters"},
    {"TestRun", test_run, test_run_usage, "Run a specific or selected tests"},
    {"TestSelect", test_select, test_select_usage, "Select tests for running"},
#endif
    {"Write", cmd_sand_mem_write, cmd_sand_mem_write_usage, "Write entry(s) into a table"},
#ifdef BCM_EASY_RELOAD_SUPPORT
    {"XXReload", cmd_xxreload, cmd_xxreload_usage, "\"Easy\" Reload control"},
#endif /* defined(BCM_EASY_RELOAD_SUPPORT) || defined(BCM_EASY_RELOAD_WB_COMPAT_SUPPORT) */
};

int bcm_dnx_cmd_cnt = COUNTOF(bcm_dnx_cmd_list);
