
/*
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2022 Broadcom Inc. All rights reserved.
 */

#ifndef __TRUNK_TYPES_H__
#define __TRUNK_TYPES_H__

#include <soc/dnxc/swstate/dnxc_sw_state_h_includes.h>
#include <include/soc/dnx/dnx_data/auto_generated/dnx_data_device.h>
#include <include/soc/dnx/dnx_data/auto_generated/dnx_data_trunk.h>


typedef struct {
    uint32 system_port;
    uint32 flags;
    int index;
    int spa_member_id;
    uint32 protecting_system_port;
} trunk_group_member_info_t;

typedef struct {
    int psc;
    int psc_profile_id;
    trunk_group_member_info_t* members;
    int nof_members;
    int last_member_added_index;
    int in_use;
    uint32* pp_ports;
    uint32 in_header_type;
    uint32 out_header_type;
    uint32 flags;
    int master_trunk_id;
} trunk_group_info_t;

typedef struct {
    trunk_group_info_t* groups;
} trunk_pool_info_t;

typedef struct {
    int trunk_id;
    uint32 flags;
} trunk_system_port_entry_t;

typedef struct {
    trunk_system_port_entry_t* trunk_system_port_entries;
} trunk_system_port_db_t;

typedef struct {
    int psc_profile_type;
    int max_nof_members;
} profile_info_t;

typedef struct {
    int assigned_psc_profile;
    int ref_counter;
} user_profile_info_t;

typedef struct {
    uint32 chm_handle;
    profile_info_t* profile_info;
    user_profile_info_t* user_profile_info;
} psc_general_info_t;

typedef struct {
    trunk_pool_info_t* pools;
    trunk_system_port_db_t trunk_system_port_db;
    psc_general_info_t psc_general_info;
} trunk_info_t;


#endif 
