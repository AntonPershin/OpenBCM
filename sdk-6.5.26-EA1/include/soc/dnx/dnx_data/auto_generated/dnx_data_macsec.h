
/* *INDENT-OFF* */
/*
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2022 Broadcom Inc. All rights reserved.
 */
#ifndef _DNX_DATA_MACSEC_H_

#define _DNX_DATA_MACSEC_H_

#include <sal/limits.h>
#include <soc/property.h>
#include <soc/sand/shrextend/shrextend_debug.h>
#include <shared/utilex/utilex_framework.h>
#include <soc/dnxc/dnxc_data/dnxc_data_utils.h>
#include <soc/dnxc/dnxc_data/dnxc_data_mgmt.h>
#include <soc/dnx/dnx_data/auto_generated/dnx_data_max_macsec.h>



#ifndef BCM_DNX_SUPPORT
#error "This file is for use by DNX (JR2) family only!"
#endif



shr_error_e dnx_data_if_macsec_init(
    int unit);






typedef struct
{
    uint32 macsec_id;
} dnx_data_macsec_general_pm_to_macsec_t;


typedef struct
{
    uint32 nof_pms;
} dnx_data_macsec_general_macsec_instances_t;


typedef struct
{
    uint32 instance_id;
} dnx_data_macsec_general_macsec_block_mapping_t;



typedef enum
{
    dnx_data_macsec_general_macsec_block_exists,
    dnx_data_macsec_general_is_hw_reset_init_done_supported,
    dnx_data_macsec_general_is_shared_macsec_supported,
    dnx_data_macsec_general_is_macsec_wrapper_main_enable,
    dnx_data_macsec_general_is_port_based_supported,
    dnx_data_macsec_general_an_full_range_supported,
    dnx_data_macsec_general_rfc_6054_supported,

    
    _dnx_data_macsec_general_feature_nof
} dnx_data_macsec_general_feature_e;



typedef int(
    *dnx_data_macsec_general_feature_get_f) (
    int unit,
    dnx_data_macsec_general_feature_e feature);


typedef uint32(
    *dnx_data_macsec_general_macsec_nof_get_f) (
    int unit);


typedef uint32(
    *dnx_data_macsec_general_macsec_in_core_nof_get_f) (
    int unit);


typedef uint32(
    *dnx_data_macsec_general_ports_in_macsec_nof_get_f) (
    int unit);


typedef uint32(
    *dnx_data_macsec_general_etype_nof_get_f) (
    int unit);


typedef uint32(
    *dnx_data_macsec_general_etype_not_zero_verify_get_f) (
    int unit);


typedef uint32(
    *dnx_data_macsec_general_tx_threshold_get_f) (
    int unit);


typedef uint32(
    *dnx_data_macsec_general_macsec_tdm_cal_max_depth_get_f) (
    int unit);


typedef uint32(
    *dnx_data_macsec_general_macsec_tdm_cal_hw_depth_get_f) (
    int unit);


typedef uint32(
    *dnx_data_macsec_general_association_number_full_range_nof_get_f) (
    int unit);


typedef uint32(
    *dnx_data_macsec_general_sectag_offset_min_value_get_f) (
    int unit);


typedef uint32(
    *dnx_data_macsec_general_supported_entries_nof_get_f) (
    int unit);


typedef uint32(
    *dnx_data_macsec_general_is_macsec_enabled_get_f) (
    int unit);


typedef uint32(
    *dnx_data_macsec_general_is_power_optimization_enabled_get_f) (
    int unit);


typedef const dnx_data_macsec_general_pm_to_macsec_t *(
    *dnx_data_macsec_general_pm_to_macsec_get_f) (
    int unit,
    int ethu_index);


typedef const dnx_data_macsec_general_macsec_instances_t *(
    *dnx_data_macsec_general_macsec_instances_get_f) (
    int unit,
    int macsec_id);


typedef const dnx_data_macsec_general_macsec_block_mapping_t *(
    *dnx_data_macsec_general_macsec_block_mapping_get_f) (
    int unit,
    int is_mss,
    int block_id);



typedef struct
{
    
    dnx_data_macsec_general_feature_get_f feature_get;
    
    dnx_data_macsec_general_macsec_nof_get_f macsec_nof_get;
    
    dnx_data_macsec_general_macsec_in_core_nof_get_f macsec_in_core_nof_get;
    
    dnx_data_macsec_general_ports_in_macsec_nof_get_f ports_in_macsec_nof_get;
    
    dnx_data_macsec_general_etype_nof_get_f etype_nof_get;
    
    dnx_data_macsec_general_etype_not_zero_verify_get_f etype_not_zero_verify_get;
    
    dnx_data_macsec_general_tx_threshold_get_f tx_threshold_get;
    
    dnx_data_macsec_general_macsec_tdm_cal_max_depth_get_f macsec_tdm_cal_max_depth_get;
    
    dnx_data_macsec_general_macsec_tdm_cal_hw_depth_get_f macsec_tdm_cal_hw_depth_get;
    
    dnx_data_macsec_general_association_number_full_range_nof_get_f association_number_full_range_nof_get;
    
    dnx_data_macsec_general_sectag_offset_min_value_get_f sectag_offset_min_value_get;
    
    dnx_data_macsec_general_supported_entries_nof_get_f supported_entries_nof_get;
    
    dnx_data_macsec_general_is_macsec_enabled_get_f is_macsec_enabled_get;
    
    dnx_data_macsec_general_is_power_optimization_enabled_get_f is_power_optimization_enabled_get;
    
    dnx_data_macsec_general_pm_to_macsec_get_f pm_to_macsec_get;
    
    dnxc_data_table_info_get_f pm_to_macsec_info_get;
    
    dnx_data_macsec_general_macsec_instances_get_f macsec_instances_get;
    
    dnxc_data_table_info_get_f macsec_instances_info_get;
    
    dnx_data_macsec_general_macsec_block_mapping_get_f macsec_block_mapping_get;
    
    dnxc_data_table_info_get_f macsec_block_mapping_info_get;
} dnx_data_if_macsec_general_t;






typedef struct
{
    uint32 payload_len;
} dnx_data_macsec_ingress_udf_t;



typedef enum
{

    
    _dnx_data_macsec_ingress_feature_nof
} dnx_data_macsec_ingress_feature_e;



typedef int(
    *dnx_data_macsec_ingress_feature_get_f) (
    int unit,
    dnx_data_macsec_ingress_feature_e feature);


typedef uint32(
    *dnx_data_macsec_ingress_flow_nof_get_f) (
    int unit);


typedef uint32(
    *dnx_data_macsec_ingress_policy_nof_get_f) (
    int unit);


typedef uint32(
    *dnx_data_macsec_ingress_secure_assoc_nof_get_f) (
    int unit);


typedef uint32(
    *dnx_data_macsec_ingress_udf_nof_bits_get_f) (
    int unit);


typedef uint32(
    *dnx_data_macsec_ingress_mgmt_rule_exact_nof_get_f) (
    int unit);


typedef uint32(
    *dnx_data_macsec_ingress_tpid_nof_get_f) (
    int unit);


typedef uint32(
    *dnx_data_macsec_ingress_cpu_flex_map_nof_get_f) (
    int unit);


typedef uint32(
    *dnx_data_macsec_ingress_sc_tcam_nof_get_f) (
    int unit);


typedef uint32(
    *dnx_data_macsec_ingress_sa_per_sc_nof_get_f) (
    int unit);


typedef uint32(
    *dnx_data_macsec_ingress_invalidate_sa_get_f) (
    int unit);


typedef uint32(
    *dnx_data_macsec_ingress_secure_channel_nof_get_f) (
    int unit);


typedef const dnx_data_macsec_ingress_udf_t *(
    *dnx_data_macsec_ingress_udf_get_f) (
    int unit,
    int type);



typedef struct
{
    
    dnx_data_macsec_ingress_feature_get_f feature_get;
    
    dnx_data_macsec_ingress_flow_nof_get_f flow_nof_get;
    
    dnx_data_macsec_ingress_policy_nof_get_f policy_nof_get;
    
    dnx_data_macsec_ingress_secure_assoc_nof_get_f secure_assoc_nof_get;
    
    dnx_data_macsec_ingress_udf_nof_bits_get_f udf_nof_bits_get;
    
    dnx_data_macsec_ingress_mgmt_rule_exact_nof_get_f mgmt_rule_exact_nof_get;
    
    dnx_data_macsec_ingress_tpid_nof_get_f tpid_nof_get;
    
    dnx_data_macsec_ingress_cpu_flex_map_nof_get_f cpu_flex_map_nof_get;
    
    dnx_data_macsec_ingress_sc_tcam_nof_get_f sc_tcam_nof_get;
    
    dnx_data_macsec_ingress_sa_per_sc_nof_get_f sa_per_sc_nof_get;
    
    dnx_data_macsec_ingress_invalidate_sa_get_f invalidate_sa_get;
    
    dnx_data_macsec_ingress_secure_channel_nof_get_f secure_channel_nof_get;
    
    dnx_data_macsec_ingress_udf_get_f udf_get;
    
    dnxc_data_table_info_get_f udf_info_get;
} dnx_data_if_macsec_ingress_t;







typedef enum
{

    
    _dnx_data_macsec_egress_feature_nof
} dnx_data_macsec_egress_feature_e;



typedef int(
    *dnx_data_macsec_egress_feature_get_f) (
    int unit,
    dnx_data_macsec_egress_feature_e feature);


typedef uint32(
    *dnx_data_macsec_egress_secure_assoc_nof_get_f) (
    int unit);


typedef uint32(
    *dnx_data_macsec_egress_soft_expiry_threshold_profiles_nof_get_f) (
    int unit);


typedef uint32(
    *dnx_data_macsec_egress_an_bit_nof_get_f) (
    int unit);


typedef uint32(
    *dnx_data_macsec_egress_sa_per_sc_nof_get_f) (
    int unit);


typedef uint32(
    *dnx_data_macsec_egress_secure_channel_nof_get_f) (
    int unit);



typedef struct
{
    
    dnx_data_macsec_egress_feature_get_f feature_get;
    
    dnx_data_macsec_egress_secure_assoc_nof_get_f secure_assoc_nof_get;
    
    dnx_data_macsec_egress_soft_expiry_threshold_profiles_nof_get_f soft_expiry_threshold_profiles_nof_get;
    
    dnx_data_macsec_egress_an_bit_nof_get_f an_bit_nof_get;
    
    dnx_data_macsec_egress_sa_per_sc_nof_get_f sa_per_sc_nof_get;
    
    dnx_data_macsec_egress_secure_channel_nof_get_f secure_channel_nof_get;
} dnx_data_if_macsec_egress_t;







typedef enum
{

    
    _dnx_data_macsec_wrapper_feature_nof
} dnx_data_macsec_wrapper_feature_e;



typedef int(
    *dnx_data_macsec_wrapper_feature_get_f) (
    int unit,
    dnx_data_macsec_wrapper_feature_e feature);


typedef uint32(
    *dnx_data_macsec_wrapper_macsec_arb_ports_nof_get_f) (
    int unit);


typedef uint32(
    *dnx_data_macsec_wrapper_per_port_speed_max_mbps_get_f) (
    int unit);


typedef uint32(
    *dnx_data_macsec_wrapper_wrapper_speed_max_mbps_get_f) (
    int unit);


typedef uint32(
    *dnx_data_macsec_wrapper_framer_ports_offset_get_f) (
    int unit);


typedef uint32(
    *dnx_data_macsec_wrapper_nof_tags_get_f) (
    int unit);



typedef struct
{
    
    dnx_data_macsec_wrapper_feature_get_f feature_get;
    
    dnx_data_macsec_wrapper_macsec_arb_ports_nof_get_f macsec_arb_ports_nof_get;
    
    dnx_data_macsec_wrapper_per_port_speed_max_mbps_get_f per_port_speed_max_mbps_get;
    
    dnx_data_macsec_wrapper_wrapper_speed_max_mbps_get_f wrapper_speed_max_mbps_get;
    
    dnx_data_macsec_wrapper_framer_ports_offset_get_f framer_ports_offset_get;
    
    dnx_data_macsec_wrapper_nof_tags_get_f nof_tags_get;
} dnx_data_if_macsec_wrapper_t;





typedef struct
{
    
    dnx_data_if_macsec_general_t general;
    
    dnx_data_if_macsec_ingress_t ingress;
    
    dnx_data_if_macsec_egress_t egress;
    
    dnx_data_if_macsec_wrapper_t wrapper;
} dnx_data_if_macsec_t;




extern dnx_data_if_macsec_t dnx_data_macsec;


#endif 

