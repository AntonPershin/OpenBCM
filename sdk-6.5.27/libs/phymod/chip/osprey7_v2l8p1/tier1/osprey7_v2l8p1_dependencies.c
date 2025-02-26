/*
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2022 Broadcom Inc. All rights reserved.
 * 
*/

#include "osprey7_v2l8p1_dependencies.h"
#include "common/srds_api_err_code.h"
#include "osprey7_v2l8p1_common.h"
#include <phymod/phymod.h>
#include <phymod/phymod_system.h>
#include <phymod/acc/phymod_tsc_iblk.h>
#include "osprey7_v2l8p1_fields.h"
#include "osprey7_v2l8p1_field_access.h"
#include "osprey7_v2l8p1_interface.h"
#include "osprey7_v2l8p1_functions.h"


err_code_t osprey7_v2l8p1_pmd_mwr_reg(srds_access_t *sa__, uint16_t addr, uint16_t mask, uint8_t lsb, uint16_t val) {
    uint32_t mymask = ( uint32_t) mask;
    phymod_access_t sa_copy;
    uint32_t i;
    uint32_t error_code;

    uint32_t data = ((mymask << 16) & 0xffff0000) | val << lsb;

    error_code=0;
    PHYMOD_MEMCPY(&sa_copy, sa__, sizeof(srds_access_t));
    for(i=1; i <= 0x80; i = i << 1) {
        if ( i & sa__->lane_mask ) {
            sa_copy.lane_mask = i;
            error_code+=phymod_tscbh_iblk_write(&sa_copy, (PHYMOD_REG_ACC_TSC_IBLK | 0x10000 | (uint32_t) addr), data);
        }
    }
    if(error_code)
      return  ERR_CODE_DATA_NOTAVAIL;
    return  ERR_CODE_NONE;
}

uint8_t osprey7_v2l8p1_get_lane(srds_access_t *sa__) {
    if (sa__->lane_mask == 0x1) {
        return ( 0 );
    } else if (sa__->lane_mask == 0x2) {
        return ( 1 );
    } else if (sa__->lane_mask == 0x4) {
        return ( 2 );
    } else if (sa__->lane_mask == 0x8) {
        return ( 3 );
    } else if (sa__->lane_mask == 0x10) {
        return ( 4 );
    } else if (sa__->lane_mask == 0x20) {
        return ( 5 );
    } else if (sa__->lane_mask == 0x40) {
        return ( 6 );
    } else if (sa__->lane_mask == 0x80) {
        return ( 7 );
    } else {
        return ( 0 );
    }
}

err_code_t osprey7_v2l8p1_delay_ns(srds_access_t *sa__, uint16_t delay_ns) {
    uint32_t delay;
    delay = delay_ns / 1000;
    if (!delay ) {
        delay = 1;
    }
    PHYMOD_USLEEP(delay);
    return ( 0 );
}

err_code_t osprey7_v2l8p1_delay_ms(srds_access_t *sa__, uint32_t delay_ms) {

    uint32_t delay;
    delay = delay_ms * 1000;
    if (!delay ) {
        delay = 1;
    }
    PHYMOD_USLEEP(delay);
    return ( 0 );
}

err_code_t osprey7_v2l8p1_pmd_wr_reg(srds_access_t *sa__, uint16_t address, uint16_t val){
    uint32_t data = 0xffff & val;
    uint32_t error_code;
    error_code = phymod_tscbh_iblk_write(sa__, (PHYMOD_REG_ACC_TSC_IBLK | 0x10000 | (uint32_t) address), data);
    if(error_code)
        return  ERR_CODE_DATA_NOTAVAIL;
    return  ERR_CODE_NONE;
}

err_code_t osprey7_v2l8p1_delay_us(srds_access_t *sa__, uint32_t delay_us){
    PHYMOD_USLEEP(delay_us);
    return ( 0 );
}

err_code_t osprey7_v2l8p1_pmd_rdt_reg(phymod_access_t *pa, uint16_t address, uint16_t *val) {
    uint32_t data;
    uint32_t error_code;

    error_code = phymod_tscbh_iblk_read(pa, (PHYMOD_REG_ACC_TSC_IBLK | 0x10000 | (uint32_t) address), &data);
    data = data & 0xffff;
    *val = (uint16_t)data;
    if(error_code)
        return  ERR_CODE_DATA_NOTAVAIL;
    return ( 0 );
}

uint8_t osprey7_v2l8p1_get_core(srds_access_t *sa__) {
    return(0);
}

err_code_t osprey7_v2l8p1_pmd_wr_pram(srds_access_t *sa__, uint8_t val){

    return ERR_CODE_NONE;

}

err_code_t osprey7_v2l8p1_set_lane(srds_access_t *sa__, uint8_t lane_index)
{
    sa__->lane_mask = 1 << lane_index;
    return ERR_CODE_NONE;

}

uint8_t osprey7_v2l8p1_get_pll_idx(srds_access_t *sa__)
{
    uint32_t data;
    data = sa__->pll_idx;
    return (data & 0x1);
}

err_code_t osprey7_v2l8p1_set_pll_idx(srds_access_t *sa__, uint8_t pll_index)
{
    sa__->pll_idx = pll_index;
    return ERR_CODE_NONE;
}

uint8_t osprey7_v2l8p1_get_micro_idx(srds_access_t *sa__)
{
    uint32_t data;
    data = sa__->pll_idx;
    return (data & 0x3);
}

err_code_t osprey7_v2l8p1_set_micro_idx(srds_access_t *sa__, uint8_t micro_index)
{
    sa__->pll_idx = micro_index;
    return ERR_CODE_NONE;

}

srds_info_t *osprey7_v2l8p1_get_info_table_address(srds_access_t *sa__)
{
    return (srds_info_t *) (sa__->pmd_info_ptr);
}
