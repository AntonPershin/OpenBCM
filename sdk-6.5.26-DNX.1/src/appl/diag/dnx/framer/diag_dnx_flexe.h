/**
 * \file diag_dnx_flexe.h Contains all of the flexE diag&test declarations for external usage
 */
/*
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2022 Broadcom Inc. All rights reserved.
 */
#ifndef DIAG_DNX_FLEXE_H_INCLUDED
#define DIAG_DNX_FLEXE_H_INCLUDED

/****************************
 * FlexE core include file *
 ****************************/
#include <appl/diag/sand/diag_sand_framework.h>

/*************
 * GLOBALS   *
 *************/
extern sh_sand_man_t sh_dnx_diag_flexe_man;
extern sh_sand_cmd_t sh_dnx_diag_flexe_cmds[];

/*************
 * DEFINES   *
 *************/

#define FLEXE_COUNTER_REG_NOF_FIELD     4

#define DIAG_FLEXE_CHANNEL_GPORT_SET(_gport, _channel)      \
            ((_gport) = (0xFFFFF << 12)  | ((_channel) & 0xFF))
#define DIAG_FLEXE_GPORT_IS_FLEXE_CHANNEL(_gport)           \
            ((((_gport) >> 12) & 0xFFFFF) == 0xFFFFF)

/*************
 * TYPE DEFS *
 *************/
typedef struct sh_flexe_counter_register_s
{
    soc_reg_t reg;
    soc_block_type_t block;
    soc_field_t cnt_field[FLEXE_COUNTER_REG_NOF_FIELD];
    char *description[FLEXE_COUNTER_REG_NOF_FIELD];
    int nof_fields;
    uint32 flags;
} sh_flexe_counter_register_t;

typedef struct sh_flexe_block_counter_s
{
    char *block_name;
    sh_flexe_counter_register_t *counter_regs;
    uint32 counter_num;
} sh_flexe_block_counter_t;

typedef struct sh_flexe_core_counter_s
{
    char *counter_name;
    uint32 address;
    uint32 is_memory;

    /*
     * only valid for memory
     */
    uint32 num_bits;
    uint32 num_entry;

    uint32 flags;
} sh_flexe_core_counter_t;

typedef struct sh_flexe_core_module_s
{
    char *module_name;
    uint32 base_address;

    sh_flexe_core_counter_t *counter_reg;
    uint32 counter_num;
} sh_flexe_core_module_t;

typedef enum
{
    diag_flexe_counter_print_default,
    diag_flexe_counter_print_nozero,
    diag_flexe_counter_print_all,
} diag_flexe_counter_print_opt_e;

typedef enum
{
    diag_flexe_core_module_mcmaxrx = 0,
    diag_flexe_core_module_mcmaxtx,
    diag_flexe_core_module_b66sar_rx,
    diag_flexe_core_module_b66sar_tx,
    diag_flexe_core_module_cpb_egress_mac,
    diag_flexe_core_module_flexe_macrx,
    diag_flexe_core_module_num,

    diag_flexe_core_module_sar = 0x10,
    diag_flexe_core_module_all,
    diag_flexe_core_module_none,
} diag_flexe_core_module_t;

typedef enum
{
    diag_flexe_core_conf_b66switch,
    diag_flexe_core_conf_b66sar,
    diag_flexe_core_conf_oam_alarm,
    diag_flexe_core_conf_oh_alarm,
    diag_flexe_core_conf_oam_counter,

} diag_flexe_core_conf_t;

typedef struct
{
    int debug_id;
    char *usage;
    char *usage_2;
    char *usage_3;
    char *usage_4;
    char *fun_prototype;
    char *fun_prototype_2;
    char *fun_prototype_3;
    char *fun_prototype_4;
} diag_flexe_debug_func_info_t;

/*******************************************************************/
/**************Diag flexe internal function*************************/
/*******************************************************************/
shr_error_e diag_flexe_reg_read(
    int unit,
    int address,
    uint32 *value);

shr_error_e diag_flexe_mem_read(
    int unit,
    int address,
    int index,
    int width,
    uint32 *value);

shr_error_e diag_flexe_reg_write(
    int unit,
    int address,
    uint32 value);

shr_error_e diag_flexe_mem_write(
    int unit,
    int address,
    int index,
    int width,
    uint32 *value);

shr_error_e dnx_diag_flexe_groups_get(
    int unit,
    bcm_pbmp_t * groups);

/*
    get the flow connect at flexe core internal.
*/
shr_error_e dnx_diag_flexe_flow_get_client(
    int unit,
    bcm_port_t src_port,
    uint32 *dst_num,
    bcm_port_t * dst_port);

/*
    get the flow from virtual_clien to eth/ILKN.
*/
shr_error_e dnx_diag_flexe_flow_get_virtual_client(
    int unit,
    bcm_port_t src_port,
    bcm_port_t * dst_port);

/*
    get the flow from ETH to virtual client.
*/
shr_error_e dnx_diag_flexe_flow_get_eth(
    int unit,
    bcm_port_t src_port,
    bcm_port_t * dst_port);

/*
    get the flow from ILKN to virtual client.
*/
shr_error_e dnx_diag_flexe_flow_get_ilkn(
    int unit,
    bcm_port_t src_port,
    bcm_port_t * dst_port);

shr_error_e diag_flexe_algo_port_info_get(
    int unit,
    bcm_port_t logical_port,
    dnx_algo_port_info_s * port_info);

shr_error_e diag_flexe_core_b66_switch_get(
    int unit,
    int ram_id,
    uint32 src_channel,
    uint32 *dst_num,
    uint32 *dst_channel);

/*****************************************************************/
/*****************FlexE cmd internal API**************************/
/*****************************************************************/
shr_error_e dnx_diag_flexe_core_counter_clear(
    int unit);

/*
    print flexe core counter
*/
shr_error_e dnx_diag_flexe_core_counter_print(
    int unit,
    int in_hex,
    int print_opt,
    uint32 module_id,
    sh_sand_control_t * sand_control);

shr_error_e dnx_diag_flexe_core_dump_b66switch(
    int unit,
    sh_sand_control_t * sand_control);

shr_error_e dnx_diag_flexe_core_dump_b66sar(
    int unit,
    sh_sand_control_t * sand_control);

shr_error_e dnx_diag_flexe_core_dump_oam_alarm(
    int unit,
    sh_sand_control_t * sand_control);

shr_error_e dnx_diag_flexe_core_dump_oh_alarm(
    int unit,
    sh_sand_control_t * sand_control);

shr_error_e dnx_diag_flexe_core_dump_oam_cnt(
    int unit,
    int channel,
    sh_sand_control_t * sand_control);

shr_error_e dnx_flexe_1588_ptp_delay_test(
    int unit,
    int phy_instance,
    int test_num,
    sh_sand_control_t * sand_control);

shr_error_e dnx_diag_flexe_core_reset(
    int unit);

int dnx_diag_is_flexe_core_enabled(
    int unit);

shr_error_e sh_cmd_is_flexe_available(
    int unit,
    rhlist_t * test_list);

shr_error_e sh_cmd_is_flexe_gen2(
    int unit,
    rhlist_t * test_list);

/*******************************************************************/
/*****************FlexE core relate define**************************/
/*******************************************************************/
/* FlexE counter: single memory entry with multi field */
#define FLEXE_CORE_COUNTER_FLAG_MPL         0x1
#define FLEXE_CORE_COUNTER_MPL_NUM          9

#define FLEXE_CORE_REG_BASE_ADDR        0
#define FLEXE_CORE_RAM_BASE_ADDR        0x60000

#define FLEXE_CORE_REG_MEM_MAX_SIZE_U32 32
#define FLEXE_CORE_COUNTER_MAX_SIZE_U32 8

#define DIAG_FLEXE_FLOW_DST_PORT_MAX    3
#define DIAG_DISP_ROW_MAX_LEN           80

#define DIAG_FLEXE_PORT_NAME_LEN        16
#define DIAG_DISP_SLOT_NUM_IN_ROW       10
#define DIAG_DISP_PORT_NUM_IN_ROW       16
#define DIAG_DISP_SLOT_TIME_STRING_LEN  80

#endif /* DIAG_DNX_FLEXE_H_INCLUDED */
