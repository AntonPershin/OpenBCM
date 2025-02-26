/** \file src/bcm/dnx/trunk/trunk_dbal_access.h
 * 
 * Internal DNX TRUNK dbal access APIs to be used in trunk 
 * module 
 * 
 */

/*
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2022 Broadcom Inc. All rights reserved.
 */

#ifndef _BCM_DNX_TRUNK_TRUNKDBALACCESS_H_INCLUDED
/*
 * { 
 */
#define _BCM_DNX_TRUNK_TRUNKDBALACCESS_H_INCLUDED

/**
 * \brief This file is only used by DNX (JR2 family). Including it by
 * software that is not specific to DNX is an error.
 */
#ifndef BCM_DNX_SUPPORT
#error "This file is for use by DNX family only!"
#endif

#include <soc/dnx/swstate/auto_generated/types/trunk_types.h>
#include "trunk_temp_structs_to_skip_papi.h"

/**
 * \brief - set trunk pool attributes
 * 
 * \param [in] unit - unit number
 * \param [in] pool - index for pool
 * \param [in] pool_mode - represents the pool size mode - how 
 *        many groups and how many members in the group
 *   
 * \return
 *   shr_error_e 
 *   
 * \remark
 *   * None
 * \see
 *   * None
 */
shr_error_e dnx_trunk_dbal_access_trunk_pool_attributes_set(
    int unit,
    int pool,
    int pool_mode);

/**
 * \brief - set egress trunk attributes
 *
 * \param [in] unit - unit number
 * \param [in] size_mode - size mode to set for table.
 *
 * \return
 *   shr_error_e
 *
 * \remark
 *   * None
 * \see
 *   * None
 */
shr_error_e dnx_trunk_dbal_access_egress_trunk_attributes_set(
    int unit,
    int size_mode);

/**
 * \brief - set a system port to a trunk member
 * 
 * \param [in] unit - unit
 * \param [in] pool - pool index
 * \param [in] group - group index
 * \param [in] member - member index
 * \param [in] system_port_id - destination system port to
 *        map to given member
 *   
 * \return
 *   shr_error_e 
 *   
 * \remark
 *   * None
 * \see
 *   * None
 */
shr_error_e dnx_trunk_dbal_access_trunk_members_set(
    int unit,
    int pool,
    int group,
    int member,
    uint32 system_port_id);

/**
 * \brief - get a system port mapped to a trunk member
 *
 * \param [in] unit - unit
 * \param [in] pool - pool index
 * \param [in] group - group index
 * \param [in] member - member index
 * \param [out] system_port_id - destination system port
 *        mapped to given member
 *
 * \return
 *   shr_error_e
 *
 * \remark
 *   * None
 * \see
 *   * None
 */
shr_error_e dnx_trunk_dbal_access_trunk_members_get(
    int unit,
    int pool,
    int group,
    int member,
    uint32 *system_port_id);

/**
 * \brief - copy a member from one index to another.
 * This function includes copying both the master and the backup member when applicable.
 *
 * \param [in] unit - unit
 * \param [in] pool - pool index
 * \param [in] group - group index
 * \param [in] member - member index to copy
 * \param [in] new_member - member index to copy into
 *
 * \return
 *   shr_error_e
 *
 * \remark
 *   * None
 * \see
 *   * None
 */
shr_error_e dnx_trunk_dbal_access_trunk_members_copy(
    int unit,
    int pool,
    int group,
    int member,
    int new_member);

/**
 * \brief - set a protecting system port to a trunk member
 *
 * \param [in] unit - unit
 * \param [in] pool - pool index
 * \param [in] group - group index
 * \param [in] member - member index
 * \param [in] system_port_id - protecting destination system port to
 *        map to given member
 *
 * \return
 *   shr_error_e
 *
 * \remark
 *   * None
 * \see
 *   * None
 */
shr_error_e dnx_trunk_dbal_access_trunk_protection_members_set(
    int unit,
    int pool,
    int group,
    int member,
    uint32 system_port_id);

/**
 * \brief - get a protecting system port to a trunk member
 *
 * \param [in] unit - unit
 * \param [in] pool - pool index
 * \param [in] group - group index
 * \param [in] member - member index
 * \param [in] system_port_id - protecting destination system port
 *        mapped to given member
 *
 * \return
 *   shr_error_e
 *
 * \remark
 *   * None
 * \see
 *   * None
 */
shr_error_e dnx_trunk_dbal_access_trunk_protection_members_get(
    int unit,
    int pool,
    int group,
    int member,
    uint32 *system_port_id);

/**
 * \brief - swap a protecting system port with mapped system port to a trunk member
 *
 * \param [in] unit - unit
 * \param [in] pool - pool index
 * \param [in] group - group index
 * \param [in] member - member index
 *
 * \return
 *   shr_error_e
 *
 * \remark
 *   * None
 * \see
 *   * None
 */
shr_error_e dnx_trunk_dbal_access_trunk_protection_members_swap(
    int unit,
    int pool,
    int group,
    int member);

/**
 * \brief - set trunk attributes - PSC and PSC algo inputs
 * 
 * \param [in] unit - unit number
 * \param [in] pool - pool index
 * \param [in] group - group index
 * \param [in] psc - port selection criteria in BCM format
 * \param [in] psc_algo_input - algo input for PSC - according 
 *        to the PSC this is meaning either a profile id or a
 *        number in corolation to nof members
 *   
 * \return
 *   shr_error_e 
 *   
 * \remark
 *   * None
 * \see
 *   * None
 */
shr_error_e dnx_trunk_dbal_access_trunk_attributes_set(
    int unit,
    int pool,
    int group,
    int psc,
    int psc_algo_input);

/**
 * \brief - setting smooth division profile configuration
 * 
 * \param [in] unit - unit number
 * \param [in] profile_index - profile index
 * \param [in] entry_index - entry index
 * \param [in] member_destination - tm index of the member in 
 *        the trunk
 *   
 * \return
 *   shr_error_e 
 *   
 * \remark
 *   * None
 * \see
 *   * None
 */
shr_error_e dnx_trunk_dbal_access_smooth_division_profile_configuration_set(
    int unit,
    int profile_index,
    int entry_index,
    int member_destination);

/**
 * \brief - set flow aggregate mapping
 *
 * \param [in] unit - unit number
 * \param [in] base_flow_agg_bundle - flow aggregate bundle
 * \param [in] base_flow_id - base flow id or base VOQ - VOQ divided by bundle size
 * \param [in] pool - trunk pool index
 * \param [in] group - trunk group index
 * \param [in] tc_size - tc_size
 *
 * \return
 *   shr_error_e
 *
 * \remark
 *   * None
 * \see
 *   * None
 */
shr_error_e dnx_trunk_dbal_access_flow_agg_group_map_set(
    int unit,
    int base_flow_agg_bundle,
    int base_flow_id,
    int pool,
    int group,
    int tc_size);

/**
 * \brief - get flow aggregate mapping
 *
 * \param [in] unit - unit number
 * \param [in] base_flow_agg_bundle - flow aggregate bundle
 * \param [out] base_flow_id - base flow id or base VOQ - VOQ divided by bundle size
 * \param [out] pool - trunk pool index
 * \param [out] group - trunk group index
 * \param [out] tc_size - tc_size
 *
 * \return
 *   shr_error_e
 *
 * \remark
 *   * None
 * \see
 *   * None
 */
shr_error_e dnx_trunk_dbal_access_flow_agg_group_map_get(
    int unit,
    int base_flow_agg_bundle,
    int *base_flow_id,
    int *pool,
    int *group,
    int *tc_size);

/**
 * \brief - set consistent hashing profile configurations
 *
 * \param [in] unit - unit number
 * \param [in] profile_index - profile index
 * \param [in] member_base - member base
 * \param [in] member_mode - member mode
 * \param [in] max_size - max size of profile
 *
 * \return
 *   shr_error_e
 *
 * \remark
 *   * None
 * \see
 *   * None
 */
shr_error_e dnx_trunk_dbal_access_consistent_hashing_profile_configurations_set(
    int unit,
    int profile_index,
    int member_base,
    int member_mode,
    int max_size);

/**
 * \brief - get consistent hashing profile configurations
 *
 * \param [in] unit - unit number
 * \param [in] profile_index - profile index
 * \param [out] member_base - member base
 * \param [out] member_mode - member mode
 * \param [out] max_size - max size of profile
 *
 * \return
 *   shr_error_e
 *
 * \remark
 *   * None
 * \see
 *   * None
 */
shr_error_e dnx_trunk_dbal_access_consistent_hashing_profile_configurations_get(
    int unit,
    int profile_index,
    int *member_base,
    int *member_mode,
    int *max_size);

/**
 * \brief - set consistent hashing profile members
 *
 * \param [in] unit - unit number
 * \param [in] hashed_index - entry to update
 * \param [in] is_double_entry - indication if entry should be interpreted as 2 entries
 * \param [in] first_mapped_member - first mapped member
 * \param [in] second_mapped_member - in case of double entry, this is the second entry
 *
 * \return
 *   shr_error_e
 *
 * \remark
 *   * None
 * \see
 *   * None
 */
shr_error_e dnx_trunk_dbal_access_consistent_hashing_members_map_set(
    int unit,
    int hashed_index,
    int is_double_entry,
    uint32 first_mapped_member,
    uint32 second_mapped_member);

/**
 * \brief - get consistent hashing profile members
 *
 * \param [in] unit - unit number
 * \param [in] hashed_index - entry to get
 * \param [in] is_double_entry - indication if entry should be interpreted as 2 entries
 * \param [out] first_mapped_member - first mapped member
 * \param [out] second_mapped_member - in case of double entry, this is the second entry
 *
 * \return
 *   shr_error_e
 *
 * \remark
 *   * None
 * \see
 *   * None
 */
shr_error_e dnx_trunk_dbal_access_consistent_hashing_members_map_get(
    int unit,
    int hashed_index,
    int is_double_entry,
    uint32 *first_mapped_member,
    uint32 *second_mapped_member);

/**
 * \brief - set trunk egress multicast resolution table
 * 
 * \param [in] unit - unit number
 * \param [in] core - core to update
 * \param [in] egress_trunk_profile - relevant egress trunk 
 *        profile
 * \param [in] lb_key - load balancing key to update
 * \param [in] out_port - value of the out port - the port 
 *        trough which the packet will leave if the lb-key and
 *        profile were matched
 *   
 * \return
 *   shr_error_e 
 *   
 * \remark
 *   * None
 * \see
 *   * None
 */
shr_error_e dnx_trunk_dbal_access_trunk_egress_mc_resolution_set(
    int unit,
    int core,
    int egress_trunk_profile,
    int lb_key,
    uint32 out_port);

/**
 * \brief - get trunk egress multicast resolution table
 * 
 * \param [in] unit - unit number
 * \param [in] core - core to get
 * \param [in] egress_trunk_profile - egress trunk profile to 
 *        get
 * \param [in] lb_key - load balancing key to get
 * \param [in] out_port - recieved value of the out port
 *   
 * \return
 *   shr_error_e 
 *   
 * \remark
 *   * None
 * \see
 *   * None
 */
shr_error_e dnx_trunk_dbal_access_trunk_egress_mc_resolution_get(
    int unit,
    int core,
    int egress_trunk_profile,
    int lb_key,
    uint32 *out_port);

/**
 * \brief - set a range of values to trunk egress multicast 
 *        resolution table
 * 
 * \param [in] unit - unit nubmer
 * \param [in] core - core index
 * \param [in] egress_trunk_profile - egress trunk profile
 * \param [in] first - first in range
 * \param [in] range - size of range
 * \param [in] out_port - out port to update
 *   
 * \return
 *   shr_error_e 
 *   
 * \remark
 *   * None
 * \see
 *   * None
 */
shr_error_e dnx_trunk_dbal_access_trunk_egress_range_set(
    int unit,
    int core,
    int egress_trunk_profile,
    int first,
    int range,
    uint32 out_port);

/**
 * \brief - set active configuration selector
 * 
 * \param [in] unit - unit number
 * \param [in] multiple_configuration_enable - enable multiple 
 *        configuarations
 * \param [in] active_configuration - determine active 
 *        configuration
 *   
 * \return
 *   shr_error_e 
 *   
 * \remark
 *   * None
 * \see
 *   * None
 */
shr_error_e dnx_trunk_dbal_access_trunk_active_configuration_selector_set(
    int unit,
    uint32 multiple_configuration_enable,
    uint32 active_configuration);

/**
 * \brief - get active configuration selector
 * 
 * \param [in] unit - unit number
 * \param [in] multiple_configuration_enable - is multiple 
 *        configurations enabled
 * \param [in] active_configuration - returns the active 
 *        configuration
 *   
 * \return
 *   shr_error_e 
 *   
 * \remark
 *   * None
 * \see
 *   * None
 */
shr_error_e dnx_trunk_dbal_access_trunk_active_configuration_selector_get(
    int unit,
    uint32 *multiple_configuration_enable,
    uint32 *active_configuration);

/**
 * \brief - set flow aggregate attributes
 *
 * \param [in] unit - unit number
 * \param [in] enable - is enabled
 *
 * \return
 *   shr_error_e
 *
 * \remark
 *   * None
 * \see
 *   * None
 */
shr_error_e dnx_trunk_dbal_access_flow_agg_attributes_set(
    int unit,
    uint8 enable);

#endif /* _BCM_DNX_TRUNK_TRUNKDBALACCESS_H_INCLUDED */
