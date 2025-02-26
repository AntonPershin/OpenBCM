
/* *INDENT-OFF* */
/*
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2022 Broadcom Inc. All rights reserved.
 */
#ifndef _DNX_DATA_DBAL_H_

#define _DNX_DATA_DBAL_H_

#include <sal/limits.h>
#include <shared/utilex/utilex_framework.h>
#include <soc/property.h>
#include <soc/sand/shrextend/shrextend_debug.h>
#include <soc/dnxc/dnxc_data/dnxc_data_utils.h>
#include <soc/dnxc/dnxc_data/dnxc_data_mgmt.h>
#include <soc/dnx/dnx_data/auto_generated/dnx_data_max_dbal.h>



#ifndef BCM_DNX_SUPPORT
#error "This file is for use by DNX family only!"
#endif



shr_error_e dnx_data_if_dbal_init(
    int unit);






typedef struct
{
    char *file_name;
} dnx_data_dbal_diag_loggerInfo_t;


typedef struct
{
    int value1;
} dnx_data_dbal_diag_example_1_key_t;


typedef struct
{
    int value1;
} dnx_data_dbal_diag_example_2_keys_t;



typedef enum
{

    
    _dnx_data_dbal_diag_feature_nof
} dnx_data_dbal_diag_feature_e;



typedef int(
    *dnx_data_dbal_diag_feature_get_f) (
    int unit,
    dnx_data_dbal_diag_feature_e feature);


typedef const dnx_data_dbal_diag_loggerInfo_t *(
    *dnx_data_dbal_diag_loggerInfo_get_f) (
    int unit);


typedef const dnx_data_dbal_diag_example_1_key_t *(
    *dnx_data_dbal_diag_example_1_key_get_f) (
    int unit,
    int key1);


typedef const dnx_data_dbal_diag_example_2_keys_t *(
    *dnx_data_dbal_diag_example_2_keys_get_f) (
    int unit,
    int key1,
    int key2);



typedef struct
{
    
    dnx_data_dbal_diag_feature_get_f feature_get;
    
    dnx_data_dbal_diag_loggerInfo_get_f loggerInfo_get;
    
    dnxc_data_table_info_get_f loggerInfo_info_get;
    
    dnx_data_dbal_diag_example_1_key_get_f example_1_key_get;
    
    dnxc_data_table_info_get_f example_1_key_info_get;
    
    dnx_data_dbal_diag_example_2_keys_get_f example_2_keys_get;
    
    dnxc_data_table_info_get_f example_2_keys_info_get;
} dnx_data_if_dbal_diag_t;







typedef enum
{
    dnx_data_dbal_db_init_invalid_feature_example,
    dnx_data_dbal_db_init_zero_size_payload_support,
    dnx_data_dbal_db_init_support_encoding_for_hl_tcam,

    
    _dnx_data_dbal_db_init_feature_nof
} dnx_data_dbal_db_init_feature_e;



typedef int(
    *dnx_data_dbal_db_init_feature_get_f) (
    int unit,
    dnx_data_dbal_db_init_feature_e feature);


typedef uint32(
    *dnx_data_dbal_db_init_dbal_device_state_get_f) (
    int unit);


typedef uint32(
    *dnx_data_dbal_db_init_run_ltt_after_wm_test_get_f) (
    int unit);



typedef struct
{
    
    dnx_data_dbal_db_init_feature_get_f feature_get;
    
    dnx_data_dbal_db_init_dbal_device_state_get_f dbal_device_state_get;
    
    dnx_data_dbal_db_init_run_ltt_after_wm_test_get_f run_ltt_after_wm_test_get;
} dnx_data_if_dbal_db_init_t;







typedef enum
{
    dnx_data_dbal_table_support_mdb_general_phys_db,

    
    _dnx_data_dbal_table_feature_nof
} dnx_data_dbal_table_feature_e;



typedef int(
    *dnx_data_dbal_table_feature_get_f) (
    int unit,
    dnx_data_dbal_table_feature_e feature);


typedef uint32(
    *dnx_data_dbal_table_nof_dynamic_tables_get_f) (
    int unit);


typedef uint32(
    *dnx_data_dbal_table_nof_dynamic_xml_tables_get_f) (
    int unit);


typedef uint32(
    *dnx_data_dbal_table_nof_dynamic_tables_labels_get_f) (
    int unit);


typedef uint32(
    *dnx_data_dbal_table_nof_dynamic_tables_key_fields_get_f) (
    int unit);


typedef uint32(
    *dnx_data_dbal_table_nof_dynamic_tables_result_fields_get_f) (
    int unit);


typedef uint32(
    *dnx_data_dbal_table_nof_dynamic_tables_multi_result_types_get_f) (
    int unit);


typedef uint32(
    *dnx_data_dbal_table_nof_dynamic_tables_ppmc_multi_result_types_get_f) (
    int unit);


typedef uint32(
    *dnx_data_dbal_table_nof_dynamic_and_static_tables_get_f) (
    int unit);



typedef struct
{
    
    dnx_data_dbal_table_feature_get_f feature_get;
    
    dnx_data_dbal_table_nof_dynamic_tables_get_f nof_dynamic_tables_get;
    
    dnx_data_dbal_table_nof_dynamic_xml_tables_get_f nof_dynamic_xml_tables_get;
    
    dnx_data_dbal_table_nof_dynamic_tables_labels_get_f nof_dynamic_tables_labels_get;
    
    dnx_data_dbal_table_nof_dynamic_tables_key_fields_get_f nof_dynamic_tables_key_fields_get;
    
    dnx_data_dbal_table_nof_dynamic_tables_result_fields_get_f nof_dynamic_tables_result_fields_get;
    
    dnx_data_dbal_table_nof_dynamic_tables_multi_result_types_get_f nof_dynamic_tables_multi_result_types_get;
    
    dnx_data_dbal_table_nof_dynamic_tables_ppmc_multi_result_types_get_f nof_dynamic_tables_ppmc_multi_result_types_get;
    
    dnx_data_dbal_table_nof_dynamic_and_static_tables_get_f nof_dynamic_and_static_tables_get;
} dnx_data_if_dbal_table_t;







typedef enum
{

    
    _dnx_data_dbal_hw_ent_feature_nof
} dnx_data_dbal_hw_ent_feature_e;



typedef int(
    *dnx_data_dbal_hw_ent_feature_get_f) (
    int unit,
    dnx_data_dbal_hw_ent_feature_e feature);


typedef uint32(
    *dnx_data_dbal_hw_ent_nof_direct_maps_get_f) (
    int unit);


typedef uint32(
    *dnx_data_dbal_hw_ent_nof_groups_maps_get_f) (
    int unit);



typedef struct
{
    
    dnx_data_dbal_hw_ent_feature_get_f feature_get;
    
    dnx_data_dbal_hw_ent_nof_direct_maps_get_f nof_direct_maps_get;
    
    dnx_data_dbal_hw_ent_nof_groups_maps_get_f nof_groups_maps_get;
} dnx_data_if_dbal_hw_ent_t;





typedef struct
{
    
    dnx_data_if_dbal_diag_t diag;
    
    dnx_data_if_dbal_db_init_t db_init;
    
    dnx_data_if_dbal_table_t table;
    
    dnx_data_if_dbal_hw_ent_t hw_ent;
} dnx_data_if_dbal_t;




extern dnx_data_if_dbal_t dnx_data_dbal;


#endif 

