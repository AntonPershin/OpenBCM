
/* *INDENT-OFF* */
/*
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2022 Broadcom Inc. All rights reserved.
 */
#ifndef _DNX_DATA_FABRIC_H_

#define _DNX_DATA_FABRIC_H_

#include <sal/limits.h>
#include <shared/utilex/utilex_framework.h>
#include <soc/property.h>
#include <soc/sand/shrextend/shrextend_debug.h>
#include <soc/dnxc/dnxc_data/dnxc_data_utils.h>
#include <soc/dnxc/dnxc_data/dnxc_data_mgmt.h>
#include <bcm/fabric.h>
#include <soc/dnxc/fabric.h>
#include <soc/dnx/dbal/auto_generated/dbal_defines_tables.h>
#include <soc/dnx/dbal/auto_generated/dbal_defines_fields.h>
#include <bcm_int/dnx/fabric/fabric_cgm.h>
#include <soc/dnx/dnx_data/auto_generated/dnx_data_max_fabric.h>



#ifndef BCM_DNX_SUPPORT
#error "This file is for use by DNX family only!"
#endif



shr_error_e dnx_data_if_fabric_init(
    int unit);






typedef struct
{
    int size;
} dnx_data_fabric_general_fmac_bus_size_t;


typedef struct
{
    uint32 min_phy_id;
    uint32 max_phy_id;
} dnx_data_fabric_general_pll_phys_t;


typedef struct
{
    int special_pll_check;
    int nof_plls;
} dnx_data_fabric_general_pm_properties_t;


typedef struct
{
    int enable;
} dnx_data_fabric_general_force_single_pll_t;


typedef struct
{
    uint32 size;
} dnx_data_fabric_general_supported_fmac_tx_padding_sizes_t;



typedef enum
{
    dnx_data_fabric_general_blocks_exist,
    dnx_data_fabric_general_clock_power_down,
    dnx_data_fabric_general_blocks_reset_required_before_power_down,
    dnx_data_fabric_general_fabric_full_power_down,
    dnx_data_fabric_general_fsrd_clock_power_down,
    dnx_data_fabric_general_is_used,
    dnx_data_fabric_general_is_jr1_in_system_supported,
    dnx_data_fabric_general_bw_update,
    dnx_data_fabric_general_clk_repeater_disable,
    dnx_data_fabric_general_is_symb_errors_per_frame_supported,
    dnx_data_fabric_general_retimer_functionality_supported,
    dnx_data_fabric_general_mirror_supported,
    dnx_data_fabric_general_fmac_tx_padding_supported,
    dnx_data_fabric_general_is_nrz_supported,
    dnx_data_fabric_general_fec_ber_proj_supported,
    dnx_data_fabric_general_linkup_indication_map_supported,
    dnx_data_fabric_general_serdes_lpi_access_supported,
    dnx_data_fabric_general_is_ber_calc_supported,

    
    _dnx_data_fabric_general_feature_nof
} dnx_data_fabric_general_feature_e;



typedef int(
    *dnx_data_fabric_general_feature_get_f) (
    int unit,
    dnx_data_fabric_general_feature_e feature);


typedef uint32(
    *dnx_data_fabric_general_nof_lcplls_get_f) (
    int unit);


typedef uint32(
    *dnx_data_fabric_general_fmac_clock_khz_get_f) (
    int unit);


typedef uint32(
    *dnx_data_fabric_general_fmac_tx_padding_min_port_speed_get_f) (
    int unit);


typedef uint32(
    *dnx_data_fabric_general_nof_ber_proj_error_analyzer_counters_get_f) (
    int unit);


typedef uint32(
    *dnx_data_fabric_general_connect_mode_get_f) (
    int unit);


typedef const dnx_data_fabric_general_fmac_bus_size_t *(
    *dnx_data_fabric_general_fmac_bus_size_get_f) (
    int unit,
    int mode);


typedef const dnx_data_fabric_general_pll_phys_t *(
    *dnx_data_fabric_general_pll_phys_get_f) (
    int unit,
    int lcpll);


typedef const dnx_data_fabric_general_pm_properties_t *(
    *dnx_data_fabric_general_pm_properties_get_f) (
    int unit,
    int pm_index);


typedef const dnx_data_fabric_general_force_single_pll_t *(
    *dnx_data_fabric_general_force_single_pll_get_f) (
    int unit,
    int pm);


typedef const dnx_data_fabric_general_supported_fmac_tx_padding_sizes_t *(
    *dnx_data_fabric_general_supported_fmac_tx_padding_sizes_get_f) (
    int unit,
    int index);



typedef struct
{
    
    dnx_data_fabric_general_feature_get_f feature_get;
    
    dnx_data_fabric_general_nof_lcplls_get_f nof_lcplls_get;
    
    dnx_data_fabric_general_fmac_clock_khz_get_f fmac_clock_khz_get;
    
    dnx_data_fabric_general_fmac_tx_padding_min_port_speed_get_f fmac_tx_padding_min_port_speed_get;
    
    dnx_data_fabric_general_nof_ber_proj_error_analyzer_counters_get_f nof_ber_proj_error_analyzer_counters_get;
    
    dnx_data_fabric_general_connect_mode_get_f connect_mode_get;
    
    dnx_data_fabric_general_fmac_bus_size_get_f fmac_bus_size_get;
    
    dnxc_data_table_info_get_f fmac_bus_size_info_get;
    
    dnx_data_fabric_general_pll_phys_get_f pll_phys_get;
    
    dnxc_data_table_info_get_f pll_phys_info_get;
    
    dnx_data_fabric_general_pm_properties_get_f pm_properties_get;
    
    dnxc_data_table_info_get_f pm_properties_info_get;
    
    dnx_data_fabric_general_force_single_pll_get_f force_single_pll_get;
    
    dnxc_data_table_info_get_f force_single_pll_info_get;
    
    dnx_data_fabric_general_supported_fmac_tx_padding_sizes_get_f supported_fmac_tx_padding_sizes_get;
    
    dnxc_data_table_info_get_f supported_fmac_tx_padding_sizes_info_get;
} dnx_data_if_fabric_general_t;






typedef struct
{
    bcm_pbmp_t supported_links;
} dnx_data_fabric_links_general_t;


typedef struct
{
    uint32 tx_polarity;
    uint32 rx_polarity;
} dnx_data_fabric_links_polarity_t;


typedef struct
{
    uint32 speed;
    bcm_port_phy_fec_t fec_type;
    uint32 is_valid;
} dnx_data_fabric_links_supported_interfaces_t;


typedef struct
{
    bcm_port_phy_fec_t fec_type;
} dnx_data_fabric_links_default_fec_t;


typedef struct
{
    bcm_port_phy_fec_t fec_type;
    bcm_port_control_t control_type;
    uint32 is_valid;
} dnx_data_fabric_links_supported_fec_controls_t;



typedef enum
{
    dnx_data_fabric_links_load_balancing_periodic_event_enabled,
    dnx_data_fabric_links_isolation_needed_before_disable_full_reset,
    dnx_data_fabric_links_is_mac_groups_load_balancing_supported,
    dnx_data_fabric_links_is_wfd_supported,
    dnx_data_fabric_links_is_enhanced_load_balancing_supported,
    dnx_data_fabric_links_credit_based_llfc_supported,
    dnx_data_fabric_links_link_local_remote_fault_support,
    dnx_data_fabric_links_fec_machines_set_at_init_only,
    dnx_data_fabric_links_serdes_lock_determines_link_status,

    
    _dnx_data_fabric_links_feature_nof
} dnx_data_fabric_links_feature_e;



typedef int(
    *dnx_data_fabric_links_feature_get_f) (
    int unit,
    dnx_data_fabric_links_feature_e feature);


typedef uint32(
    *dnx_data_fabric_links_nof_links_get_f) (
    int unit);


typedef uint32(
    *dnx_data_fabric_links_nof_links_per_core_get_f) (
    int unit);


typedef uint32(
    *dnx_data_fabric_links_max_link_id_get_f) (
    int unit);


typedef uint32(
    *dnx_data_fabric_links_usec_between_load_balancing_events_get_f) (
    int unit);


typedef uint32(
    *dnx_data_fabric_links_kr_fec_supported_get_f) (
    int unit);


typedef uint32(
    *dnx_data_fabric_links_wfd_max_hw_weight_get_f) (
    int unit);


typedef uint32(
    *dnx_data_fabric_links_load_balancing_profile_id_min_get_f) (
    int unit);


typedef uint32(
    *dnx_data_fabric_links_load_balancing_profile_id_max_get_f) (
    int unit);


typedef uint32(
    *dnx_data_fabric_links_fabric_pm_type_get_f) (
    int unit);


typedef uint32(
    *dnx_data_fabric_links_core_mapping_mode_get_f) (
    int unit);


typedef const dnx_data_fabric_links_general_t *(
    *dnx_data_fabric_links_general_get_f) (
    int unit);


typedef const dnx_data_fabric_links_polarity_t *(
    *dnx_data_fabric_links_polarity_get_f) (
    int unit,
    int link);


typedef const dnx_data_fabric_links_supported_interfaces_t *(
    *dnx_data_fabric_links_supported_interfaces_get_f) (
    int unit,
    int index);


typedef const dnx_data_fabric_links_default_fec_t *(
    *dnx_data_fabric_links_default_fec_get_f) (
    int unit,
    int speed);


typedef const dnx_data_fabric_links_supported_fec_controls_t *(
    *dnx_data_fabric_links_supported_fec_controls_get_f) (
    int unit,
    int index);



typedef struct
{
    
    dnx_data_fabric_links_feature_get_f feature_get;
    
    dnx_data_fabric_links_nof_links_get_f nof_links_get;
    
    dnx_data_fabric_links_nof_links_per_core_get_f nof_links_per_core_get;
    
    dnx_data_fabric_links_max_link_id_get_f max_link_id_get;
    
    dnx_data_fabric_links_usec_between_load_balancing_events_get_f usec_between_load_balancing_events_get;
    
    dnx_data_fabric_links_kr_fec_supported_get_f kr_fec_supported_get;
    
    dnx_data_fabric_links_wfd_max_hw_weight_get_f wfd_max_hw_weight_get;
    
    dnx_data_fabric_links_load_balancing_profile_id_min_get_f load_balancing_profile_id_min_get;
    
    dnx_data_fabric_links_load_balancing_profile_id_max_get_f load_balancing_profile_id_max_get;
    
    dnx_data_fabric_links_fabric_pm_type_get_f fabric_pm_type_get;
    
    dnx_data_fabric_links_core_mapping_mode_get_f core_mapping_mode_get;
    
    dnx_data_fabric_links_general_get_f general_get;
    
    dnxc_data_table_info_get_f general_info_get;
    
    dnx_data_fabric_links_polarity_get_f polarity_get;
    
    dnxc_data_table_info_get_f polarity_info_get;
    
    dnx_data_fabric_links_supported_interfaces_get_f supported_interfaces_get;
    
    dnxc_data_table_info_get_f supported_interfaces_info_get;
    
    dnx_data_fabric_links_default_fec_get_f default_fec_get;
    
    dnxc_data_table_info_get_f default_fec_info_get;
    
    dnx_data_fabric_links_supported_fec_controls_get_f supported_fec_controls_get;
    
    dnxc_data_table_info_get_f supported_fec_controls_info_get;
} dnx_data_if_fabric_links_t;






typedef struct
{
    int chain;
    int index_in_chain;
} dnx_data_fabric_blocks_fsrd_sbus_chain_t;


typedef struct
{
    int chain;
    int index_in_chain;
} dnx_data_fabric_blocks_fmac_sbus_chain_t;


typedef struct
{
    int master_fsrd_index;
} dnx_data_fabric_blocks_fsrd_ref_clk_master_t;



typedef enum
{

    
    _dnx_data_fabric_blocks_feature_nof
} dnx_data_fabric_blocks_feature_e;



typedef int(
    *dnx_data_fabric_blocks_feature_get_f) (
    int unit,
    dnx_data_fabric_blocks_feature_e feature);


typedef uint32(
    *dnx_data_fabric_blocks_nof_instances_fmac_get_f) (
    int unit);


typedef uint32(
    *dnx_data_fabric_blocks_nof_links_in_fmac_get_f) (
    int unit);


typedef uint32(
    *dnx_data_fabric_blocks_nof_instances_fsrd_get_f) (
    int unit);


typedef uint32(
    *dnx_data_fabric_blocks_nof_links_in_fsrd_get_f) (
    int unit);


typedef uint32(
    *dnx_data_fabric_blocks_nof_fmacs_in_fsrd_get_f) (
    int unit);


typedef uint32(
    *dnx_data_fabric_blocks_nof_pms_get_f) (
    int unit);


typedef uint32(
    *dnx_data_fabric_blocks_nof_links_in_pm_get_f) (
    int unit);


typedef uint32(
    *dnx_data_fabric_blocks_nof_fmacs_in_pm_get_f) (
    int unit);


typedef uint32(
    *dnx_data_fabric_blocks_nof_instances_fdtl_get_f) (
    int unit);


typedef uint32(
    *dnx_data_fabric_blocks_nof_links_in_fdtl_get_f) (
    int unit);


typedef uint32(
    *dnx_data_fabric_blocks_nof_sbus_chains_get_f) (
    int unit);


typedef const dnx_data_fabric_blocks_fsrd_sbus_chain_t *(
    *dnx_data_fabric_blocks_fsrd_sbus_chain_get_f) (
    int unit,
    int fsrd_id);


typedef const dnx_data_fabric_blocks_fmac_sbus_chain_t *(
    *dnx_data_fabric_blocks_fmac_sbus_chain_get_f) (
    int unit,
    int fmac_id);


typedef const dnx_data_fabric_blocks_fsrd_ref_clk_master_t *(
    *dnx_data_fabric_blocks_fsrd_ref_clk_master_get_f) (
    int unit,
    int fsrd_index);



typedef struct
{
    
    dnx_data_fabric_blocks_feature_get_f feature_get;
    
    dnx_data_fabric_blocks_nof_instances_fmac_get_f nof_instances_fmac_get;
    
    dnx_data_fabric_blocks_nof_links_in_fmac_get_f nof_links_in_fmac_get;
    
    dnx_data_fabric_blocks_nof_instances_fsrd_get_f nof_instances_fsrd_get;
    
    dnx_data_fabric_blocks_nof_links_in_fsrd_get_f nof_links_in_fsrd_get;
    
    dnx_data_fabric_blocks_nof_fmacs_in_fsrd_get_f nof_fmacs_in_fsrd_get;
    
    dnx_data_fabric_blocks_nof_pms_get_f nof_pms_get;
    
    dnx_data_fabric_blocks_nof_links_in_pm_get_f nof_links_in_pm_get;
    
    dnx_data_fabric_blocks_nof_fmacs_in_pm_get_f nof_fmacs_in_pm_get;
    
    dnx_data_fabric_blocks_nof_instances_fdtl_get_f nof_instances_fdtl_get;
    
    dnx_data_fabric_blocks_nof_links_in_fdtl_get_f nof_links_in_fdtl_get;
    
    dnx_data_fabric_blocks_nof_sbus_chains_get_f nof_sbus_chains_get;
    
    dnx_data_fabric_blocks_fsrd_sbus_chain_get_f fsrd_sbus_chain_get;
    
    dnxc_data_table_info_get_f fsrd_sbus_chain_info_get;
    
    dnx_data_fabric_blocks_fmac_sbus_chain_get_f fmac_sbus_chain_get;
    
    dnxc_data_table_info_get_f fmac_sbus_chain_info_get;
    
    dnx_data_fabric_blocks_fsrd_ref_clk_master_get_f fsrd_ref_clk_master_get;
    
    dnxc_data_table_info_get_f fsrd_ref_clk_master_info_get;
} dnx_data_if_fabric_blocks_t;







typedef enum
{

    
    _dnx_data_fabric_reachability_feature_nof
} dnx_data_fabric_reachability_feature_e;



typedef int(
    *dnx_data_fabric_reachability_feature_get_f) (
    int unit,
    dnx_data_fabric_reachability_feature_e feature);


typedef uint32(
    *dnx_data_fabric_reachability_resolution_get_f) (
    int unit);


typedef uint32(
    *dnx_data_fabric_reachability_gen_period_get_f) (
    int unit);


typedef uint32(
    *dnx_data_fabric_reachability_full_cycle_period_nsec_get_f) (
    int unit);


typedef uint32(
    *dnx_data_fabric_reachability_watchdog_resolution_get_f) (
    int unit);


typedef uint32(
    *dnx_data_fabric_reachability_watchdog_period_usec_get_f) (
    int unit);



typedef struct
{
    
    dnx_data_fabric_reachability_feature_get_f feature_get;
    
    dnx_data_fabric_reachability_resolution_get_f resolution_get;
    
    dnx_data_fabric_reachability_gen_period_get_f gen_period_get;
    
    dnx_data_fabric_reachability_full_cycle_period_nsec_get_f full_cycle_period_nsec_get;
    
    dnx_data_fabric_reachability_watchdog_resolution_get_f watchdog_resolution_get;
    
    dnx_data_fabric_reachability_watchdog_period_usec_get_f watchdog_period_usec_get;
} dnx_data_if_fabric_reachability_t;







typedef enum
{
    dnx_data_fabric_mesh_is_supported,

    
    _dnx_data_fabric_mesh_feature_nof
} dnx_data_fabric_mesh_feature_e;



typedef int(
    *dnx_data_fabric_mesh_feature_get_f) (
    int unit,
    dnx_data_fabric_mesh_feature_e feature);


typedef uint32(
    *dnx_data_fabric_mesh_max_mc_id_get_f) (
    int unit);


typedef uint32(
    *dnx_data_fabric_mesh_max_nof_dest_get_f) (
    int unit);


typedef uint32(
    *dnx_data_fabric_mesh_multicast_enable_get_f) (
    int unit);


typedef uint32(
    *dnx_data_fabric_mesh_nof_dest_get_f) (
    int unit);



typedef struct
{
    
    dnx_data_fabric_mesh_feature_get_f feature_get;
    
    dnx_data_fabric_mesh_max_mc_id_get_f max_mc_id_get;
    
    dnx_data_fabric_mesh_max_nof_dest_get_f max_nof_dest_get;
    
    dnx_data_fabric_mesh_multicast_enable_get_f multicast_enable_get;
    
    dnx_data_fabric_mesh_nof_dest_get_f nof_dest_get;
} dnx_data_if_fabric_mesh_t;






typedef struct
{
    uint32 supported;
} dnx_data_fabric_cell_supported_pcp_modes_t;



typedef enum
{
    dnx_data_fabric_cell_use_max_fda_reassembly_timer_value,
    dnx_data_fabric_cell_pcp_require_continous_on_local,
    dnx_data_fabric_cell_format_always_with_pcp,
    dnx_data_fabric_cell_pcp_force_no_packing,
    dnx_data_fabric_cell_multiple_cell_formats_supported,

    
    _dnx_data_fabric_cell_feature_nof
} dnx_data_fabric_cell_feature_e;



typedef int(
    *dnx_data_fabric_cell_feature_get_f) (
    int unit,
    dnx_data_fabric_cell_feature_e feature);


typedef uint32(
    *dnx_data_fabric_cell_nof_priorities_get_f) (
    int unit);


typedef uint32(
    *dnx_data_fabric_cell_vsc256_max_size_get_f) (
    int unit);


typedef uint32(
    *dnx_data_fabric_cell_max_vsc_format_size_get_f) (
    int unit);


typedef uint32(
    *dnx_data_fabric_cell_sr_cell_header_offset_get_f) (
    int unit);


typedef uint32(
    *dnx_data_fabric_cell_sr_cell_nof_instances_get_f) (
    int unit);


typedef uint32(
    *dnx_data_fabric_cell_ctrl_cells_init_fifo_empty_iterations_get_f) (
    int unit);


typedef uint32(
    *dnx_data_fabric_cell_default_packing_mode_get_f) (
    int unit);


typedef uint32(
    *dnx_data_fabric_cell_pcp_enable_get_f) (
    int unit);


typedef uint32(
    *dnx_data_fabric_cell_cell_format_get_f) (
    int unit);


typedef const dnx_data_fabric_cell_supported_pcp_modes_t *(
    *dnx_data_fabric_cell_supported_pcp_modes_get_f) (
    int unit,
    int pcp_mode);



typedef struct
{
    
    dnx_data_fabric_cell_feature_get_f feature_get;
    
    dnx_data_fabric_cell_nof_priorities_get_f nof_priorities_get;
    
    dnx_data_fabric_cell_vsc256_max_size_get_f vsc256_max_size_get;
    
    dnx_data_fabric_cell_max_vsc_format_size_get_f max_vsc_format_size_get;
    
    dnx_data_fabric_cell_sr_cell_header_offset_get_f sr_cell_header_offset_get;
    
    dnx_data_fabric_cell_sr_cell_nof_instances_get_f sr_cell_nof_instances_get;
    
    dnx_data_fabric_cell_ctrl_cells_init_fifo_empty_iterations_get_f ctrl_cells_init_fifo_empty_iterations_get;
    
    dnx_data_fabric_cell_default_packing_mode_get_f default_packing_mode_get;
    
    dnx_data_fabric_cell_pcp_enable_get_f pcp_enable_get;
    
    dnx_data_fabric_cell_cell_format_get_f cell_format_get;
    
    dnx_data_fabric_cell_supported_pcp_modes_get_f supported_pcp_modes_get;
    
    dnxc_data_table_info_get_f supported_pcp_modes_info_get;
} dnx_data_if_fabric_cell_t;






typedef struct
{
    uint32 uc[DNX_DATA_MAX_FABRIC_CELL_NOF_PRIORITIES];
    uint32 mc[DNX_DATA_MAX_FABRIC_CELL_NOF_PRIORITIES];
    char *name;
    soc_dnxc_fabric_pipe_map_type_t type;
    int min_hp_mc;
    int tdm_pipe;
} dnx_data_fabric_pipes_map_t;


typedef struct
{
    uint32 nof_pipes;
    uint32 uc[DNX_DATA_MAX_FABRIC_CELL_NOF_PRIORITIES];
    uint32 mc[DNX_DATA_MAX_FABRIC_CELL_NOF_PRIORITIES];
    char *name;
    soc_dnxc_fabric_pipe_map_type_t type;
    int min_hp_mc;
    int tdm_pipe;
} dnx_data_fabric_pipes_valid_map_config_t;


typedef struct
{
    uint32 index;
} dnx_data_fabric_pipes_dtq_subcontexts_t;



typedef enum
{
    dnx_data_fabric_pipes_ocb_wfq,
    dnx_data_fabric_pipes_local_route_pipe_supported,
    dnx_data_fabric_pipes_global_config_supported,

    
    _dnx_data_fabric_pipes_feature_nof
} dnx_data_fabric_pipes_feature_e;



typedef int(
    *dnx_data_fabric_pipes_feature_get_f) (
    int unit,
    dnx_data_fabric_pipes_feature_e feature);


typedef uint32(
    *dnx_data_fabric_pipes_max_nof_pipes_get_f) (
    int unit);


typedef uint32(
    *dnx_data_fabric_pipes_max_nof_contexts_get_f) (
    int unit);


typedef uint32(
    *dnx_data_fabric_pipes_max_nof_subcontexts_get_f) (
    int unit);


typedef uint32(
    *dnx_data_fabric_pipes_nof_pipes_get_f) (
    int unit);


typedef uint32(
    *dnx_data_fabric_pipes_multi_pipe_system_get_f) (
    int unit);


typedef const dnx_data_fabric_pipes_map_t *(
    *dnx_data_fabric_pipes_map_get_f) (
    int unit);


typedef const dnx_data_fabric_pipes_valid_map_config_t *(
    *dnx_data_fabric_pipes_valid_map_config_get_f) (
    int unit,
    int config_id);


typedef const dnx_data_fabric_pipes_dtq_subcontexts_t *(
    *dnx_data_fabric_pipes_dtq_subcontexts_get_f) (
    int unit,
    int dtq,
    int is_ocb_only);



typedef struct
{
    
    dnx_data_fabric_pipes_feature_get_f feature_get;
    
    dnx_data_fabric_pipes_max_nof_pipes_get_f max_nof_pipes_get;
    
    dnx_data_fabric_pipes_max_nof_contexts_get_f max_nof_contexts_get;
    
    dnx_data_fabric_pipes_max_nof_subcontexts_get_f max_nof_subcontexts_get;
    
    dnx_data_fabric_pipes_nof_pipes_get_f nof_pipes_get;
    
    dnx_data_fabric_pipes_multi_pipe_system_get_f multi_pipe_system_get;
    
    dnx_data_fabric_pipes_map_get_f map_get;
    
    dnxc_data_table_info_get_f map_info_get;
    
    dnx_data_fabric_pipes_valid_map_config_get_f valid_map_config_get;
    
    dnxc_data_table_info_get_f valid_map_config_info_get;
    
    dnx_data_fabric_pipes_dtq_subcontexts_get_f dtq_subcontexts_get;
    
    dnxc_data_table_info_get_f dtq_subcontexts_info_get;
} dnx_data_if_fabric_pipes_t;







typedef enum
{

    
    _dnx_data_fabric_debug_feature_nof
} dnx_data_fabric_debug_feature_e;



typedef int(
    *dnx_data_fabric_debug_feature_get_f) (
    int unit,
    dnx_data_fabric_debug_feature_e feature);


typedef int(
    *dnx_data_fabric_debug_mesh_topology_size_get_f) (
    int unit);


typedef uint32(
    *dnx_data_fabric_debug_mesh_topology_fast_get_f) (
    int unit);



typedef struct
{
    
    dnx_data_fabric_debug_feature_get_f feature_get;
    
    dnx_data_fabric_debug_mesh_topology_size_get_f mesh_topology_size_get;
    
    dnx_data_fabric_debug_mesh_topology_fast_get_f mesh_topology_fast_get;
} dnx_data_if_fabric_debug_t;







typedef enum
{
    dnx_data_fabric_mesh_topology_calendar_mode_supported,

    
    _dnx_data_fabric_mesh_topology_feature_nof
} dnx_data_fabric_mesh_topology_feature_e;



typedef int(
    *dnx_data_fabric_mesh_topology_feature_get_f) (
    int unit,
    dnx_data_fabric_mesh_topology_feature_e feature);


typedef uint32(
    *dnx_data_fabric_mesh_topology_mesh_init_get_f) (
    int unit);


typedef uint32(
    *dnx_data_fabric_mesh_topology_mesh_config_1_get_f) (
    int unit);



typedef struct
{
    
    dnx_data_fabric_mesh_topology_feature_get_f feature_get;
    
    dnx_data_fabric_mesh_topology_mesh_init_get_f mesh_init_get;
    
    dnx_data_fabric_mesh_topology_mesh_config_1_get_f mesh_config_1_get;
} dnx_data_if_fabric_mesh_topology_t;







typedef enum
{
    dnx_data_fabric_tdm_blocks_dont_exist,

    
    _dnx_data_fabric_tdm_feature_nof
} dnx_data_fabric_tdm_feature_e;



typedef int(
    *dnx_data_fabric_tdm_feature_get_f) (
    int unit,
    dnx_data_fabric_tdm_feature_e feature);


typedef int(
    *dnx_data_fabric_tdm_priority_get_f) (
    int unit);



typedef struct
{
    
    dnx_data_fabric_tdm_feature_get_f feature_get;
    
    dnx_data_fabric_tdm_priority_get_f priority_get;
} dnx_data_if_fabric_tdm_t;






typedef struct
{
    dbal_tables_e dbal_table;
    dbal_fields_e dbal_key1;
    dbal_fields_e dbal_key2;
    dbal_fields_e dbal_result;
    dnx_fabric_cgm_control_index_type_e index_type;
    int user_range;
    int user_min;
    int user_max;
    int is_valid;
    char *err_msg;
} dnx_data_fabric_cgm_access_map_t;


typedef struct
{
    int normal_weight;
    int congested_weight;
    int threshold;
} dnx_data_fabric_cgm_ingress_dynamic_wfq_configs_t;



typedef enum
{
    dnx_data_fabric_cgm_egress_drop_low_prio_mc,
    dnx_data_fabric_cgm_egress_fifo_static_size,
    dnx_data_fabric_cgm_is_egress_drop_tdm_latency_supported,
    dnx_data_fabric_cgm_is_static_shaper_supported,
    dnx_data_fabric_cgm_is_adaptive_tfl_shaper_supported,
    dnx_data_fabric_cgm_is_adaptive_mnol_shaper_supported,
    dnx_data_fabric_cgm_is_adaptive_shaper_watermarks_limited,
    dnx_data_fabric_cgm_static_shaper_fix_factor,
    dnx_data_fabric_cgm_is_global_cell_shaper_supported,
    dnx_data_fabric_cgm_is_local_unicast_dynamic_wfq_supported,
    dnx_data_fabric_cgm_is_ingress_dynamic_wfq_supported,

    
    _dnx_data_fabric_cgm_feature_nof
} dnx_data_fabric_cgm_feature_e;



typedef int(
    *dnx_data_fabric_cgm_feature_get_f) (
    int unit,
    dnx_data_fabric_cgm_feature_e feature);


typedef uint32(
    *dnx_data_fabric_cgm_nof_rci_levels_get_f) (
    int unit);


typedef uint32(
    *dnx_data_fabric_cgm_nof_rci_threshold_levels_get_f) (
    int unit);


typedef uint32(
    *dnx_data_fabric_cgm_egress_drop_th_clocks_resolution_get_f) (
    int unit);


typedef uint32(
    *dnx_data_fabric_cgm_egress_fifo_fc_threshold_get_f) (
    int unit);


typedef uint32(
    *dnx_data_fabric_cgm_static_shaper_credit_resolution_bytes_get_f) (
    int unit);


typedef uint32(
    *dnx_data_fabric_cgm_cgm_adaptive_tfl_shaper_zone_nof_get_f) (
    int unit);


typedef uint32(
    *dnx_data_fabric_cgm_cgm_global_cell_shaper_max_rate_get_f) (
    int unit);


typedef uint32(
    *dnx_data_fabric_cgm_rci_link_level_factor_max_value_get_f) (
    int unit);


typedef uint32(
    *dnx_data_fabric_cgm_local_unicast_dynamic_wfq_max_threshold_value_get_f) (
    int unit);


typedef uint32(
    *dnx_data_fabric_cgm_local_unicast_dynamic_wfq_high_threshold_get_f) (
    int unit);


typedef uint32(
    *dnx_data_fabric_cgm_local_unicast_dynamic_wfq_low_threshold_get_f) (
    int unit);


typedef uint32(
    *dnx_data_fabric_cgm_local_unicast_dynamic_wfq_high_weight_get_f) (
    int unit);


typedef uint32(
    *dnx_data_fabric_cgm_local_unicast_dynamic_wfq_low_weight_get_f) (
    int unit);


typedef uint32(
    *dnx_data_fabric_cgm_llfc_type_default_get_f) (
    int unit);


typedef const dnx_data_fabric_cgm_access_map_t *(
    *dnx_data_fabric_cgm_access_map_get_f) (
    int unit,
    int control_type);


typedef const dnx_data_fabric_cgm_ingress_dynamic_wfq_configs_t *(
    *dnx_data_fabric_cgm_ingress_dynamic_wfq_configs_get_f) (
    int unit,
    int wfq_input);



typedef struct
{
    
    dnx_data_fabric_cgm_feature_get_f feature_get;
    
    dnx_data_fabric_cgm_nof_rci_levels_get_f nof_rci_levels_get;
    
    dnx_data_fabric_cgm_nof_rci_threshold_levels_get_f nof_rci_threshold_levels_get;
    
    dnx_data_fabric_cgm_egress_drop_th_clocks_resolution_get_f egress_drop_th_clocks_resolution_get;
    
    dnx_data_fabric_cgm_egress_fifo_fc_threshold_get_f egress_fifo_fc_threshold_get;
    
    dnx_data_fabric_cgm_static_shaper_credit_resolution_bytes_get_f static_shaper_credit_resolution_bytes_get;
    
    dnx_data_fabric_cgm_cgm_adaptive_tfl_shaper_zone_nof_get_f cgm_adaptive_tfl_shaper_zone_nof_get;
    
    dnx_data_fabric_cgm_cgm_global_cell_shaper_max_rate_get_f cgm_global_cell_shaper_max_rate_get;
    
    dnx_data_fabric_cgm_rci_link_level_factor_max_value_get_f rci_link_level_factor_max_value_get;
    
    dnx_data_fabric_cgm_local_unicast_dynamic_wfq_max_threshold_value_get_f local_unicast_dynamic_wfq_max_threshold_value_get;
    
    dnx_data_fabric_cgm_local_unicast_dynamic_wfq_high_threshold_get_f local_unicast_dynamic_wfq_high_threshold_get;
    
    dnx_data_fabric_cgm_local_unicast_dynamic_wfq_low_threshold_get_f local_unicast_dynamic_wfq_low_threshold_get;
    
    dnx_data_fabric_cgm_local_unicast_dynamic_wfq_high_weight_get_f local_unicast_dynamic_wfq_high_weight_get;
    
    dnx_data_fabric_cgm_local_unicast_dynamic_wfq_low_weight_get_f local_unicast_dynamic_wfq_low_weight_get;
    
    dnx_data_fabric_cgm_llfc_type_default_get_f llfc_type_default_get;
    
    dnx_data_fabric_cgm_access_map_get_f access_map_get;
    
    dnxc_data_table_info_get_f access_map_info_get;
    
    dnx_data_fabric_cgm_ingress_dynamic_wfq_configs_get_f ingress_dynamic_wfq_configs_get;
    
    dnxc_data_table_info_get_f ingress_dynamic_wfq_configs_info_get;
} dnx_data_if_fabric_cgm_t;







typedef enum
{
    dnx_data_fabric_dtqs_dynamic_dtqs_supported,

    
    _dnx_data_fabric_dtqs_feature_nof
} dnx_data_fabric_dtqs_feature_e;



typedef int(
    *dnx_data_fabric_dtqs_feature_get_f) (
    int unit,
    dnx_data_fabric_dtqs_feature_e feature);


typedef uint32(
    *dnx_data_fabric_dtqs_max_nof_subdtqs_get_f) (
    int unit);


typedef uint32(
    *dnx_data_fabric_dtqs_max_nof_dtqs_get_f) (
    int unit);


typedef uint32(
    *dnx_data_fabric_dtqs_max_size_get_f) (
    int unit);


typedef uint32(
    *dnx_data_fabric_dtqs_ocb_only_size_get_f) (
    int unit);


typedef uint32(
    *dnx_data_fabric_dtqs_nof_active_dtqs_get_f) (
    int unit);



typedef struct
{
    
    dnx_data_fabric_dtqs_feature_get_f feature_get;
    
    dnx_data_fabric_dtqs_max_nof_subdtqs_get_f max_nof_subdtqs_get;
    
    dnx_data_fabric_dtqs_max_nof_dtqs_get_f max_nof_dtqs_get;
    
    dnx_data_fabric_dtqs_max_size_get_f max_size_get;
    
    dnx_data_fabric_dtqs_ocb_only_size_get_f ocb_only_size_get;
    
    dnx_data_fabric_dtqs_nof_active_dtqs_get_f nof_active_dtqs_get;
} dnx_data_if_fabric_dtqs_t;






typedef struct
{
    uint32 links;
} dnx_data_fabric_ilkn_bypass_info_t;



typedef enum
{

    
    _dnx_data_fabric_ilkn_feature_nof
} dnx_data_fabric_ilkn_feature_e;



typedef int(
    *dnx_data_fabric_ilkn_feature_get_f) (
    int unit,
    dnx_data_fabric_ilkn_feature_e feature);


typedef const dnx_data_fabric_ilkn_bypass_info_t *(
    *dnx_data_fabric_ilkn_bypass_info_get_f) (
    int unit,
    int pm_id);



typedef struct
{
    
    dnx_data_fabric_ilkn_feature_get_f feature_get;
    
    dnx_data_fabric_ilkn_bypass_info_get_f bypass_info_get;
    
    dnxc_data_table_info_get_f bypass_info_info_get;
} dnx_data_if_fabric_ilkn_t;







typedef enum
{

    
    _dnx_data_fabric_dbal_feature_nof
} dnx_data_fabric_dbal_feature_e;



typedef int(
    *dnx_data_fabric_dbal_feature_get_f) (
    int unit,
    dnx_data_fabric_dbal_feature_e feature);


typedef uint32(
    *dnx_data_fabric_dbal_link_rci_threshold_bits_nof_get_f) (
    int unit);


typedef uint32(
    *dnx_data_fabric_dbal_cgm_llfc_threshold_bits_nof_get_f) (
    int unit);


typedef uint32(
    *dnx_data_fabric_dbal_cgm_llfc_threshold_max_value_get_f) (
    int unit);


typedef uint32(
    *dnx_data_fabric_dbal_cgm_llfc_ingress_ipt_ctx_mapping_bits_nof_get_f) (
    int unit);


typedef uint32(
    *dnx_data_fabric_dbal_egress_fifo_drop_threshold_bits_nof_get_f) (
    int unit);


typedef uint32(
    *dnx_data_fabric_dbal_egress_fifo_drop_threshold_max_value_get_f) (
    int unit);


typedef uint32(
    *dnx_data_fabric_dbal_cgm_link_fifo_base_address_bits_nof_get_f) (
    int unit);


typedef uint32(
    *dnx_data_fabric_dbal_cgm_link_fifo_base_address_max_value_get_f) (
    int unit);


typedef uint32(
    *dnx_data_fabric_dbal_cgm_egress_fifo_base_address_bits_nof_get_f) (
    int unit);


typedef uint32(
    *dnx_data_fabric_dbal_cgm_egress_fifo_base_address_max_value_get_f) (
    int unit);


typedef uint32(
    *dnx_data_fabric_dbal_cgm_egress_fifo_fc_threshold_bits_nof_get_f) (
    int unit);


typedef uint32(
    *dnx_data_fabric_dbal_cgm_egress_fifo_fc_threshold_max_value_get_f) (
    int unit);


typedef uint32(
    *dnx_data_fabric_dbal_cgm_egress_fifo_fc_full_level_min_value_get_f) (
    int unit);


typedef uint32(
    *dnx_data_fabric_dbal_cgm_egress_fifo_fc_full_level_max_value_get_f) (
    int unit);


typedef uint32(
    *dnx_data_fabric_dbal_cgm_egress_fifo_fc_full_level_bits_nof_get_f) (
    int unit);


typedef uint32(
    *dnx_data_fabric_dbal_cgm_egress_drop_mc_low_prio_th_bits_nof_get_f) (
    int unit);


typedef uint32(
    *dnx_data_fabric_dbal_cgm_egress_dynamic_wfq_th_bits_nof_get_f) (
    int unit);


typedef uint32(
    *dnx_data_fabric_dbal_cgm_ingress_fc_threshold_max_value_get_f) (
    int unit);


typedef uint32(
    *dnx_data_fabric_dbal_cgm_static_shaper_calendar_bits_nof_get_f) (
    int unit);


typedef uint32(
    *dnx_data_fabric_dbal_fabric_transmit_wfq_index_bits_nof_get_f) (
    int unit);


typedef uint32(
    *dnx_data_fabric_dbal_fabric_transmit_wfq_index_max_value_get_f) (
    int unit);


typedef uint32(
    *dnx_data_fabric_dbal_mesh_topology_init_config_2_bits_nof_get_f) (
    int unit);


typedef uint32(
    *dnx_data_fabric_dbal_fabric_transmit_dtq_fc_thresholds_bits_nof_get_f) (
    int unit);


typedef uint32(
    *dnx_data_fabric_dbal_fabric_transmit_pdq_size_bits_nof_get_f) (
    int unit);


typedef uint32(
    *dnx_data_fabric_dbal_adaptive_shaper_threshold_bits_nof_get_f) (
    int unit);


typedef uint32(
    *dnx_data_fabric_dbal_adaptive_shaper_factor_bits_nof_get_f) (
    int unit);


typedef uint32(
    *dnx_data_fabric_dbal_adaptive_shaper_mnol_bits_nof_get_f) (
    int unit);


typedef uint32(
    *dnx_data_fabric_dbal_global_cell_shaper_allowed_cells_bits_nof_get_f) (
    int unit);


typedef uint32(
    *dnx_data_fabric_dbal_global_cell_shaper_allowed_cells_granularity_get_f) (
    int unit);


typedef uint32(
    *dnx_data_fabric_dbal_global_cell_shaper_allowed_cells_max_value_get_f) (
    int unit);


typedef uint32(
    *dnx_data_fabric_dbal_global_cell_shaper_time_frame_bits_nof_get_f) (
    int unit);


typedef uint32(
    *dnx_data_fabric_dbal_global_cell_shaper_time_frame_max_value_get_f) (
    int unit);


typedef uint32(
    *dnx_data_fabric_dbal_global_cell_shaper_cnt_bits_nof_get_f) (
    int unit);


typedef uint32(
    *dnx_data_fabric_dbal_fdr_links_offset_get_f) (
    int unit);


typedef uint32(
    *dnx_data_fabric_dbal_fabric_cgm_rci_high_severity_min_nof_links_bits_nof_get_f) (
    int unit);


typedef uint32(
    *dnx_data_fabric_dbal_priority_bits_nof_get_f) (
    int unit);


typedef uint32(
    *dnx_data_fabric_dbal_nof_links_bits_nof_get_f) (
    int unit);



typedef struct
{
    
    dnx_data_fabric_dbal_feature_get_f feature_get;
    
    dnx_data_fabric_dbal_link_rci_threshold_bits_nof_get_f link_rci_threshold_bits_nof_get;
    
    dnx_data_fabric_dbal_cgm_llfc_threshold_bits_nof_get_f cgm_llfc_threshold_bits_nof_get;
    
    dnx_data_fabric_dbal_cgm_llfc_threshold_max_value_get_f cgm_llfc_threshold_max_value_get;
    
    dnx_data_fabric_dbal_cgm_llfc_ingress_ipt_ctx_mapping_bits_nof_get_f cgm_llfc_ingress_ipt_ctx_mapping_bits_nof_get;
    
    dnx_data_fabric_dbal_egress_fifo_drop_threshold_bits_nof_get_f egress_fifo_drop_threshold_bits_nof_get;
    
    dnx_data_fabric_dbal_egress_fifo_drop_threshold_max_value_get_f egress_fifo_drop_threshold_max_value_get;
    
    dnx_data_fabric_dbal_cgm_link_fifo_base_address_bits_nof_get_f cgm_link_fifo_base_address_bits_nof_get;
    
    dnx_data_fabric_dbal_cgm_link_fifo_base_address_max_value_get_f cgm_link_fifo_base_address_max_value_get;
    
    dnx_data_fabric_dbal_cgm_egress_fifo_base_address_bits_nof_get_f cgm_egress_fifo_base_address_bits_nof_get;
    
    dnx_data_fabric_dbal_cgm_egress_fifo_base_address_max_value_get_f cgm_egress_fifo_base_address_max_value_get;
    
    dnx_data_fabric_dbal_cgm_egress_fifo_fc_threshold_bits_nof_get_f cgm_egress_fifo_fc_threshold_bits_nof_get;
    
    dnx_data_fabric_dbal_cgm_egress_fifo_fc_threshold_max_value_get_f cgm_egress_fifo_fc_threshold_max_value_get;
    
    dnx_data_fabric_dbal_cgm_egress_fifo_fc_full_level_min_value_get_f cgm_egress_fifo_fc_full_level_min_value_get;
    
    dnx_data_fabric_dbal_cgm_egress_fifo_fc_full_level_max_value_get_f cgm_egress_fifo_fc_full_level_max_value_get;
    
    dnx_data_fabric_dbal_cgm_egress_fifo_fc_full_level_bits_nof_get_f cgm_egress_fifo_fc_full_level_bits_nof_get;
    
    dnx_data_fabric_dbal_cgm_egress_drop_mc_low_prio_th_bits_nof_get_f cgm_egress_drop_mc_low_prio_th_bits_nof_get;
    
    dnx_data_fabric_dbal_cgm_egress_dynamic_wfq_th_bits_nof_get_f cgm_egress_dynamic_wfq_th_bits_nof_get;
    
    dnx_data_fabric_dbal_cgm_ingress_fc_threshold_max_value_get_f cgm_ingress_fc_threshold_max_value_get;
    
    dnx_data_fabric_dbal_cgm_static_shaper_calendar_bits_nof_get_f cgm_static_shaper_calendar_bits_nof_get;
    
    dnx_data_fabric_dbal_fabric_transmit_wfq_index_bits_nof_get_f fabric_transmit_wfq_index_bits_nof_get;
    
    dnx_data_fabric_dbal_fabric_transmit_wfq_index_max_value_get_f fabric_transmit_wfq_index_max_value_get;
    
    dnx_data_fabric_dbal_mesh_topology_init_config_2_bits_nof_get_f mesh_topology_init_config_2_bits_nof_get;
    
    dnx_data_fabric_dbal_fabric_transmit_dtq_fc_thresholds_bits_nof_get_f fabric_transmit_dtq_fc_thresholds_bits_nof_get;
    
    dnx_data_fabric_dbal_fabric_transmit_pdq_size_bits_nof_get_f fabric_transmit_pdq_size_bits_nof_get;
    
    dnx_data_fabric_dbal_adaptive_shaper_threshold_bits_nof_get_f adaptive_shaper_threshold_bits_nof_get;
    
    dnx_data_fabric_dbal_adaptive_shaper_factor_bits_nof_get_f adaptive_shaper_factor_bits_nof_get;
    
    dnx_data_fabric_dbal_adaptive_shaper_mnol_bits_nof_get_f adaptive_shaper_mnol_bits_nof_get;
    
    dnx_data_fabric_dbal_global_cell_shaper_allowed_cells_bits_nof_get_f global_cell_shaper_allowed_cells_bits_nof_get;
    
    dnx_data_fabric_dbal_global_cell_shaper_allowed_cells_granularity_get_f global_cell_shaper_allowed_cells_granularity_get;
    
    dnx_data_fabric_dbal_global_cell_shaper_allowed_cells_max_value_get_f global_cell_shaper_allowed_cells_max_value_get;
    
    dnx_data_fabric_dbal_global_cell_shaper_time_frame_bits_nof_get_f global_cell_shaper_time_frame_bits_nof_get;
    
    dnx_data_fabric_dbal_global_cell_shaper_time_frame_max_value_get_f global_cell_shaper_time_frame_max_value_get;
    
    dnx_data_fabric_dbal_global_cell_shaper_cnt_bits_nof_get_f global_cell_shaper_cnt_bits_nof_get;
    
    dnx_data_fabric_dbal_fdr_links_offset_get_f fdr_links_offset_get;
    
    dnx_data_fabric_dbal_fabric_cgm_rci_high_severity_min_nof_links_bits_nof_get_f fabric_cgm_rci_high_severity_min_nof_links_bits_nof_get;
    
    dnx_data_fabric_dbal_priority_bits_nof_get_f priority_bits_nof_get;
    
    dnx_data_fabric_dbal_nof_links_bits_nof_get_f nof_links_bits_nof_get;
} dnx_data_if_fabric_dbal_t;







typedef enum
{

    
    _dnx_data_fabric_mesh_mc_feature_nof
} dnx_data_fabric_mesh_mc_feature_e;



typedef int(
    *dnx_data_fabric_mesh_mc_feature_get_f) (
    int unit,
    dnx_data_fabric_mesh_mc_feature_e feature);


typedef uint32(
    *dnx_data_fabric_mesh_mc_nof_replication_get_f) (
    int unit);



typedef struct
{
    
    dnx_data_fabric_mesh_mc_feature_get_f feature_get;
    
    dnx_data_fabric_mesh_mc_nof_replication_get_f nof_replication_get;
} dnx_data_if_fabric_mesh_mc_t;






typedef struct
{
    uint32 sram;
    uint32 mixs;
    uint32 mixd;
    uint32 mix_mixs;
    uint32 mix_mixd;
    uint32 s2d;
} dnx_data_fabric_transmit_pdq_to_dqcq_fc_th_select_t;


typedef struct
{
    uint32 almost_full_th;
    uint32 almost_empty_th;
    uint32 bucket_size;
    uint32 bucket_fc_threshold;
    uint32 period;
    uint32 tokens_delta0;
    uint32 tokens_delta1;
    uint32 tokens_delta2;
    uint32 tokens_delta3;
} dnx_data_fabric_transmit_eir_fc_leaky_bucket_t;


typedef struct
{
    uint32 fifo_in_between;
    uint32 fifo_partially_almost_full;
    uint32 fifo_almost_full;
    uint32 fifo_partially_almost_empty;
    uint32 fifo_not_stable;
    uint32 fifo_almost_empty;
} dnx_data_fabric_transmit_eir_fc_leaky_bucket_delta_select_t;


typedef struct
{
    uint32 threshold;
} dnx_data_fabric_transmit_dtq_fc_local_thresholds_t;


typedef struct
{
    uint32 threshold;
} dnx_data_fabric_transmit_dtq_fc_fabric_thresholds_t;


typedef struct
{
    uint32 threshold;
} dnx_data_fabric_transmit_dtq_fc_ocb_thresholds_t;


typedef struct
{
    uint32 set_total_th;
    uint32 mask_dtq_0_th;
    uint32 mask_dtq_1_th;
    uint32 mask_local_th;
} dnx_data_fabric_transmit_dtq_to_pdq_ocb_thresholds_t;


typedef struct
{
    uint32 set_total_th;
    uint32 set_total_fabric_th;
    uint32 set_total_local_th;
    uint32 mask_dtq_0_th;
    uint32 mask_dtq_1_th;
    uint32 mask_local_th;
} dnx_data_fabric_transmit_dtq_to_pdq_non_ocb_thresholds_t;


typedef struct
{
    uint32 context;
    uint32 fc;
    dbal_fields_e single_dtq;
    dbal_fields_e dual_dtq;
    dbal_fields_e triple_dtq;
    int valid;
} dnx_data_fabric_transmit_dtq_to_pdq_fc_mapping_t;



typedef enum
{
    dnx_data_fabric_transmit_eir_fc_leaky_backet,
    dnx_data_fabric_transmit_dtq_fc_torwards_pdq,
    dnx_data_fabric_transmit_local_wfq_supported,

    
    _dnx_data_fabric_transmit_feature_nof
} dnx_data_fabric_transmit_feature_e;



typedef int(
    *dnx_data_fabric_transmit_feature_get_f) (
    int unit,
    dnx_data_fabric_transmit_feature_e feature);


typedef uint32(
    *dnx_data_fabric_transmit_pdqs_total_size_get_f) (
    int unit);


typedef uint32(
    *dnx_data_fabric_transmit_nof_pdqs_get_f) (
    int unit);


typedef uint32(
    *dnx_data_fabric_transmit_s2d_pdq_size_get_f) (
    int unit);


typedef uint32(
    *dnx_data_fabric_transmit_pdq_sram_fc_th_get_f) (
    int unit);


typedef uint32(
    *dnx_data_fabric_transmit_pdq_mixs_fc_th_get_f) (
    int unit);


typedef uint32(
    *dnx_data_fabric_transmit_pdq_mixd_fc_th_get_f) (
    int unit);


typedef uint32(
    *dnx_data_fabric_transmit_pdq_mix_mixs_fc_th_get_f) (
    int unit);


typedef uint32(
    *dnx_data_fabric_transmit_pdq_mix_mixd_fc_th_get_f) (
    int unit);


typedef uint32(
    *dnx_data_fabric_transmit_pdq_ocb_fc_th_get_f) (
    int unit);


typedef uint32(
    *dnx_data_fabric_transmit_pdq_dram_delete_fc_th_get_f) (
    int unit);


typedef uint32(
    *dnx_data_fabric_transmit_pdq_sram_delete_fc_th_get_f) (
    int unit);


typedef uint32(
    *dnx_data_fabric_transmit_pdq_s2d_fc_th_get_f) (
    int unit);


typedef uint32(
    *dnx_data_fabric_transmit_pdq_sram_eir_fc_th_get_f) (
    int unit);


typedef uint32(
    *dnx_data_fabric_transmit_pdq_mixs_eir_fc_th_get_f) (
    int unit);


typedef uint32(
    *dnx_data_fabric_transmit_pdq_mixd_eir_fc_th_get_f) (
    int unit);


typedef uint32(
    *dnx_data_fabric_transmit_pdq_ocb_eir_fc_th_get_f) (
    int unit);


typedef const dnx_data_fabric_transmit_pdq_to_dqcq_fc_th_select_t *(
    *dnx_data_fabric_transmit_pdq_to_dqcq_fc_th_select_get_f) (
    int unit,
    int dqcq_priority);


typedef const dnx_data_fabric_transmit_eir_fc_leaky_bucket_t *(
    *dnx_data_fabric_transmit_eir_fc_leaky_bucket_get_f) (
    int unit);


typedef const dnx_data_fabric_transmit_eir_fc_leaky_bucket_delta_select_t *(
    *dnx_data_fabric_transmit_eir_fc_leaky_bucket_delta_select_get_f) (
    int unit);


typedef const dnx_data_fabric_transmit_dtq_fc_local_thresholds_t *(
    *dnx_data_fabric_transmit_dtq_fc_local_thresholds_get_f) (
    int unit,
    int dtq_fc);


typedef const dnx_data_fabric_transmit_dtq_fc_fabric_thresholds_t *(
    *dnx_data_fabric_transmit_dtq_fc_fabric_thresholds_get_f) (
    int unit,
    int dtq_fc);


typedef const dnx_data_fabric_transmit_dtq_fc_ocb_thresholds_t *(
    *dnx_data_fabric_transmit_dtq_fc_ocb_thresholds_get_f) (
    int unit,
    int dtq_fc);


typedef const dnx_data_fabric_transmit_dtq_to_pdq_ocb_thresholds_t *(
    *dnx_data_fabric_transmit_dtq_to_pdq_ocb_thresholds_get_f) (
    int unit,
    int dtq_fc);


typedef const dnx_data_fabric_transmit_dtq_to_pdq_non_ocb_thresholds_t *(
    *dnx_data_fabric_transmit_dtq_to_pdq_non_ocb_thresholds_get_f) (
    int unit,
    int dtq_fc);


typedef const dnx_data_fabric_transmit_dtq_to_pdq_fc_mapping_t *(
    *dnx_data_fabric_transmit_dtq_to_pdq_fc_mapping_get_f) (
    int unit,
    int index);



typedef struct
{
    
    dnx_data_fabric_transmit_feature_get_f feature_get;
    
    dnx_data_fabric_transmit_pdqs_total_size_get_f pdqs_total_size_get;
    
    dnx_data_fabric_transmit_nof_pdqs_get_f nof_pdqs_get;
    
    dnx_data_fabric_transmit_s2d_pdq_size_get_f s2d_pdq_size_get;
    
    dnx_data_fabric_transmit_pdq_sram_fc_th_get_f pdq_sram_fc_th_get;
    
    dnx_data_fabric_transmit_pdq_mixs_fc_th_get_f pdq_mixs_fc_th_get;
    
    dnx_data_fabric_transmit_pdq_mixd_fc_th_get_f pdq_mixd_fc_th_get;
    
    dnx_data_fabric_transmit_pdq_mix_mixs_fc_th_get_f pdq_mix_mixs_fc_th_get;
    
    dnx_data_fabric_transmit_pdq_mix_mixd_fc_th_get_f pdq_mix_mixd_fc_th_get;
    
    dnx_data_fabric_transmit_pdq_ocb_fc_th_get_f pdq_ocb_fc_th_get;
    
    dnx_data_fabric_transmit_pdq_dram_delete_fc_th_get_f pdq_dram_delete_fc_th_get;
    
    dnx_data_fabric_transmit_pdq_sram_delete_fc_th_get_f pdq_sram_delete_fc_th_get;
    
    dnx_data_fabric_transmit_pdq_s2d_fc_th_get_f pdq_s2d_fc_th_get;
    
    dnx_data_fabric_transmit_pdq_sram_eir_fc_th_get_f pdq_sram_eir_fc_th_get;
    
    dnx_data_fabric_transmit_pdq_mixs_eir_fc_th_get_f pdq_mixs_eir_fc_th_get;
    
    dnx_data_fabric_transmit_pdq_mixd_eir_fc_th_get_f pdq_mixd_eir_fc_th_get;
    
    dnx_data_fabric_transmit_pdq_ocb_eir_fc_th_get_f pdq_ocb_eir_fc_th_get;
    
    dnx_data_fabric_transmit_pdq_to_dqcq_fc_th_select_get_f pdq_to_dqcq_fc_th_select_get;
    
    dnxc_data_table_info_get_f pdq_to_dqcq_fc_th_select_info_get;
    
    dnx_data_fabric_transmit_eir_fc_leaky_bucket_get_f eir_fc_leaky_bucket_get;
    
    dnxc_data_table_info_get_f eir_fc_leaky_bucket_info_get;
    
    dnx_data_fabric_transmit_eir_fc_leaky_bucket_delta_select_get_f eir_fc_leaky_bucket_delta_select_get;
    
    dnxc_data_table_info_get_f eir_fc_leaky_bucket_delta_select_info_get;
    
    dnx_data_fabric_transmit_dtq_fc_local_thresholds_get_f dtq_fc_local_thresholds_get;
    
    dnxc_data_table_info_get_f dtq_fc_local_thresholds_info_get;
    
    dnx_data_fabric_transmit_dtq_fc_fabric_thresholds_get_f dtq_fc_fabric_thresholds_get;
    
    dnxc_data_table_info_get_f dtq_fc_fabric_thresholds_info_get;
    
    dnx_data_fabric_transmit_dtq_fc_ocb_thresholds_get_f dtq_fc_ocb_thresholds_get;
    
    dnxc_data_table_info_get_f dtq_fc_ocb_thresholds_info_get;
    
    dnx_data_fabric_transmit_dtq_to_pdq_ocb_thresholds_get_f dtq_to_pdq_ocb_thresholds_get;
    
    dnxc_data_table_info_get_f dtq_to_pdq_ocb_thresholds_info_get;
    
    dnx_data_fabric_transmit_dtq_to_pdq_non_ocb_thresholds_get_f dtq_to_pdq_non_ocb_thresholds_get;
    
    dnxc_data_table_info_get_f dtq_to_pdq_non_ocb_thresholds_info_get;
    
    dnx_data_fabric_transmit_dtq_to_pdq_fc_mapping_get_f dtq_to_pdq_fc_mapping_get;
    
    dnxc_data_table_info_get_f dtq_to_pdq_fc_mapping_info_get;
} dnx_data_if_fabric_transmit_t;






typedef struct
{
    uint32 value;
} dnx_data_fabric_system_upgrade_target_t;



typedef enum
{
    dnx_data_fabric_system_upgrade_is_system_upgrade_supported,
    dnx_data_fabric_system_upgrade_is_system_upgrade_master_supported,

    
    _dnx_data_fabric_system_upgrade_feature_nof
} dnx_data_fabric_system_upgrade_feature_e;



typedef int(
    *dnx_data_fabric_system_upgrade_feature_get_f) (
    int unit,
    dnx_data_fabric_system_upgrade_feature_e feature);


typedef uint32(
    *dnx_data_fabric_system_upgrade_max_master_id_get_f) (
    int unit);


typedef uint32(
    *dnx_data_fabric_system_upgrade_param_0_get_f) (
    int unit);


typedef uint32(
    *dnx_data_fabric_system_upgrade_param_1_get_f) (
    int unit);


typedef uint32(
    *dnx_data_fabric_system_upgrade_param_2_get_f) (
    int unit);


typedef uint32(
    *dnx_data_fabric_system_upgrade_param_3_get_f) (
    int unit);


typedef uint32(
    *dnx_data_fabric_system_upgrade_param_4_get_f) (
    int unit);


typedef uint32(
    *dnx_data_fabric_system_upgrade_param_5_get_f) (
    int unit);


typedef uint32(
    *dnx_data_fabric_system_upgrade_param_7_get_f) (
    int unit);


typedef const dnx_data_fabric_system_upgrade_target_t *(
    *dnx_data_fabric_system_upgrade_target_get_f) (
    int unit,
    int target);



typedef struct
{
    
    dnx_data_fabric_system_upgrade_feature_get_f feature_get;
    
    dnx_data_fabric_system_upgrade_max_master_id_get_f max_master_id_get;
    
    dnx_data_fabric_system_upgrade_param_0_get_f param_0_get;
    
    dnx_data_fabric_system_upgrade_param_1_get_f param_1_get;
    
    dnx_data_fabric_system_upgrade_param_2_get_f param_2_get;
    
    dnx_data_fabric_system_upgrade_param_3_get_f param_3_get;
    
    dnx_data_fabric_system_upgrade_param_4_get_f param_4_get;
    
    dnx_data_fabric_system_upgrade_param_5_get_f param_5_get;
    
    dnx_data_fabric_system_upgrade_param_7_get_f param_7_get;
    
    dnx_data_fabric_system_upgrade_target_get_f target_get;
    
    dnxc_data_table_info_get_f target_info_get;
} dnx_data_if_fabric_system_upgrade_t;







typedef enum
{
    dnx_data_fabric_regression_is_mesh_mc_always_enabled,
    dnx_data_fabric_regression_is_power_measurement_supported,
    dnx_data_fabric_regression_is_hist_errcnt_thresh_used,

    
    _dnx_data_fabric_regression_feature_nof
} dnx_data_fabric_regression_feature_e;



typedef int(
    *dnx_data_fabric_regression_feature_get_f) (
    int unit,
    dnx_data_fabric_regression_feature_e feature);


typedef uint32(
    *dnx_data_fabric_regression_minimum_system_ref_clk_get_f) (
    int unit);


typedef uint32(
    *dnx_data_fabric_regression_soft_reset_with_fabric_max_exec_time_get_f) (
    int unit);


typedef uint32(
    *dnx_data_fabric_regression_soft_reset_with_fabric_avg_exec_time_get_f) (
    int unit);



typedef struct
{
    
    dnx_data_fabric_regression_feature_get_f feature_get;
    
    dnx_data_fabric_regression_minimum_system_ref_clk_get_f minimum_system_ref_clk_get;
    
    dnx_data_fabric_regression_soft_reset_with_fabric_max_exec_time_get_f soft_reset_with_fabric_max_exec_time_get;
    
    dnx_data_fabric_regression_soft_reset_with_fabric_avg_exec_time_get_f soft_reset_with_fabric_avg_exec_time_get;
} dnx_data_if_fabric_regression_t;





typedef struct
{
    
    dnx_data_if_fabric_general_t general;
    
    dnx_data_if_fabric_links_t links;
    
    dnx_data_if_fabric_blocks_t blocks;
    
    dnx_data_if_fabric_reachability_t reachability;
    
    dnx_data_if_fabric_mesh_t mesh;
    
    dnx_data_if_fabric_cell_t cell;
    
    dnx_data_if_fabric_pipes_t pipes;
    
    dnx_data_if_fabric_debug_t debug;
    
    dnx_data_if_fabric_mesh_topology_t mesh_topology;
    
    dnx_data_if_fabric_tdm_t tdm;
    
    dnx_data_if_fabric_cgm_t cgm;
    
    dnx_data_if_fabric_dtqs_t dtqs;
    
    dnx_data_if_fabric_ilkn_t ilkn;
    
    dnx_data_if_fabric_dbal_t dbal;
    
    dnx_data_if_fabric_mesh_mc_t mesh_mc;
    
    dnx_data_if_fabric_transmit_t transmit;
    
    dnx_data_if_fabric_system_upgrade_t system_upgrade;
    
    dnx_data_if_fabric_regression_t regression;
} dnx_data_if_fabric_t;




extern dnx_data_if_fabric_t dnx_data_fabric;


#endif 

