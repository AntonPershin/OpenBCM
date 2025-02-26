/** \file mirror.c
 * 
 *
 * General MIRROR functionality for DNX. \n
 * Note - Due to backward compatbility, this module is named "mirror" although mirror is \n
 * just one application of snif. In General snif supports the following applications: \n
 * snoop, mirror, statistical sampling.
 * Dedicated set of MIRROR APIs are distributed between mirror_*.c files: \n
 * mirror.c, mirror_command.c
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
#define BSL_LOG_MODULE BSL_LS_BCMDNX_MIRROR

/*
 * Include files.
 * {
 */

#include <soc/sand/shrextend/shrextend_debug.h>
#include <soc/dnx/dnx_data/auto_generated/dnx_data_device.h>
#include <soc/dnx/dnx_data/auto_generated/dnx_data_snif.h>
#include <soc/dnx/dnx_data/auto_generated/dnx_data_ingr_congestion.h>
#include <soc/dnx/dnx_data/auto_generated/dnx_data_headers.h>
#include <soc/dnx/dnx_data/auto_generated/dnx_data_vlan.h>
#include <soc/dnx/dnx_err_recovery_manager.h>
#include <bcm_int/dnx/algo/swstate/auto_generated/access/dnx_mirror_access.h>
#include <soc/dnx/dbal/dbal.h>

#include <bcm/mirror.h>
#include <bcm/types.h>
#include <bcm/stat.h>
#include <bcm_int/dnx/mirror/mirror.h>
#include <bcm_int/dnx/algo/algo_gpm.h>
#include <bcm_int/dnx/algo/port/algo_port_mgmt.h>
#include <bcm_int/dnx/stat/crps/crps_mgmt.h>
#include <bcm_int/dnx/port/port_pp.h>
#include <shared/gport.h>
#include "mirror_profile.h"
#include "mirror_profile_alloc.h"
#include "mirror_rule.h"
#include "mirror_rcy.h"
#include "mirror_header.h"

/**
 * \brief - Verify mirror destination profile attributes for BCM-API: bcm_dnx_mirror_destination_create()
 *
 * \par DIRECT_INPUT:
 *   \param [in] unit - Unit ID
 *   \param [in] mirror_dest - Mirror destination attributes
 *
 * \remark
 *   * None
 * \see
 *   * None
 */
static shr_error_e
dnx_mirror_destination_create_verify(
    int unit,
    bcm_mirror_destination_t * mirror_dest)
{
    int action_profile_id, i;
    uint8 is_allocated;
    uint32 max_val, max_val_stat_type;
    uint32 drop_group_bmp_mask = 0;

    SHR_FUNC_INIT_VARS(unit);

    action_profile_id = 0;
    action_profile_id = BCM_GPORT_MIRROR_GET(mirror_dest->mirror_dest_id);
    /*
     * verify valid flags
     */
    if (mirror_dest->flags & ~(BCM_MIRROR_DEST_WITH_ID |
                               BCM_MIRROR_DEST_REPLACE |
                               BCM_MIRROR_DEST_TUNNEL_WITH_ENCAP_ID |
                               BCM_MIRROR_DEST_IS_SNOOP | BCM_MIRROR_DEST_IS_STAT_SAMPLE |
                               BCM_MIRROR_DEST_EGRESS_ADD_ORIG_SYSTEM_HEADER |
                               BCM_MIRROR_DEST_UPDATE_EXT_COUNTERS | BCM_MIRROR_DEST_OUT_MIRROR_DISABLE))

    {
        SHR_ERR_EXIT(_SHR_E_PARAM, "An unsupported bcm mirror destination flag was specified : 0x%lx",
                     (unsigned long) mirror_dest->flags);
    }
    if (mirror_dest->flags2 & ~(BCM_MIRROR_DEST_FLAGS2_UPDATE_EXT_STAT_VALID |
                                BCM_MIRROR_DEST_FLAGS2_UPDATE_EXT_STAT_TYPES | BCM_MIRROR_DEST_FLAGS2_MIRROR_ON_DROP |
                                BCM_MIRROR_DEST_FLAGS2_PAD_TO_CROP_SIZE_ENABLE))
    {
        SHR_ERR_EXIT(_SHR_E_PARAM, "An unsupported bcm mirror destination flag2 was specified : 0x%lx",
                     (unsigned long) mirror_dest->flags2);
    }

    if ((dnx_data_snif.ingress.feature_get(unit, dnx_data_snif_ingress_ext_stat_dedicated_config) == FALSE))
    {
        if (mirror_dest->flags & BCM_MIRROR_DEST_UPDATE_EXT_COUNTERS)
        {
            SHR_ERR_EXIT(_SHR_E_PARAM, "External stat flags are not supported");
        }
        if (mirror_dest->flags2 & (BCM_MIRROR_DEST_FLAGS2_UPDATE_EXT_STAT_VALID |
                                   BCM_MIRROR_DEST_FLAGS2_UPDATE_EXT_STAT_TYPES))
        {
            SHR_ERR_EXIT(_SHR_E_PARAM, "External stat flags2 are not supported");
        }
    }
    /*
     * 1. Verify that BCM_MIRROR_DEST_REPLACE flag (modify existing mirror attributes) is given along with
     *    BCM_MIRROR_DEST_WITH_ID(use specific ID for mirror command) flag.
     * 2. Verify that the given profile is already allocated
     */
    if (mirror_dest->flags & BCM_MIRROR_DEST_REPLACE)
    {
        if (!(mirror_dest->flags & BCM_MIRROR_DEST_WITH_ID))
        {
            SHR_ERR_EXIT(_SHR_E_PARAM, "BCM_MIRROR_DEST_REPLACE flag has to be given along with"
                         "BCM_MIRROR_DEST_WITH_ID flag");
        }

        /** Set gport according to sniff type and action_profile_id */
        if (mirror_dest->flags & BCM_MIRROR_DEST_IS_SNOOP)
        {
            BCM_GPORT_MIRROR_SNOOP_SET(mirror_dest->mirror_dest_id, action_profile_id);
        }
        else if (mirror_dest->flags & BCM_MIRROR_DEST_IS_STAT_SAMPLE)
        {
            BCM_GPORT_MIRROR_STAT_SAMPLE_SET(mirror_dest->mirror_dest_id, action_profile_id);
        }
        else
        {
            BCM_GPORT_MIRROR_MIRROR_SET(mirror_dest->mirror_dest_id, action_profile_id);
        }

        /** check whether the given sniff profile is allocated, if not return an error */
        SHR_IF_ERR_EXIT(dnx_mirror_profile_is_allocated(unit, mirror_dest->mirror_dest_id, &is_allocated));
        if (is_allocated == FALSE)
        {
            SHR_ERR_EXIT(_SHR_E_PARAM, "BCM_MIRROR_DEST_REPLACE flag has to be used on existing profiles"
                         "Specified destination profile id ID: %d has not been allocated", action_profile_id);
        }
    }

    /*
     * verify profile id is in range
     */
    if (mirror_dest->flags & BCM_MIRROR_DEST_WITH_ID)
    {
        if (action_profile_id > DNX_MIRROR_PROFILE_INGRESS_PROFILE_MAX(unit))
        {
            SHR_ERR_EXIT(_SHR_E_PARAM, "Specified destination ID: %d is out of range", action_profile_id);
        }
    }

    /*
     * verify packet header update flags
     */
    if (mirror_dest->packet_control_updates.valid & ~(BCM_MIRROR_PKT_HEADER_UPDATE_PRIO |
                                                      BCM_MIRROR_PKT_HEADER_UPDATE_COLOR |
                                                      BCM_MIRROR_PKT_HEADER_UPDATE_IN_PORT |
                                                      BCM_MIRROR_PKT_HEADER_UPDATE_VSQ |
                                                      BCM_MIRROR_PKT_HEADER_UPDATE_ECN_CNM_CANCEL |
                                                      BCM_MIRROR_PKT_HEADER_UPDATE_TRUNK_HASH_RESULT |
                                                      BCM_MIRROR_PKT_HEADER_UPDATE_ECN_VALUE |
                                                      BCM_MIRROR_PKT_HEADER_UPDATE_METADATA |
                                                      BCM_MIRROR_PKT_HEADER_UPDATE_FABRIC_HEADER_EDITING))
    {
        SHR_ERR_EXIT(_SHR_E_PARAM, "An unsupported bcm mirror packet header control flag was specified : 0x%lx",
                     (unsigned long) mirror_dest->packet_control_updates.valid);
    }

    /*
     * Verify parameters range
     */
    if (mirror_dest->packet_copy_size != 0)
    {
        {
            if (mirror_dest->packet_copy_size != dnx_data_snif.ingress.crop_size_get(unit))
            {
                SHR_ERR_EXIT(_SHR_E_PARAM, "ingress cropping size=%d is invalid", mirror_dest->packet_copy_size);
            }
        }
    }

    if (mirror_dest->egress_packet_copy_size != 0)
    {
        {
            if (mirror_dest->egress_packet_copy_size != dnx_data_snif.egress.crop_size_granularity_get(unit))
            {
                SHR_ERR_EXIT(_SHR_E_PARAM, "egress cropping size=%d is invalid", mirror_dest->egress_packet_copy_size);
            }
        }
    }

    SHR_MAX_VERIFY(mirror_dest->sample_rate_dividend, dnx_data_snif.ingress.prob_max_val_get(unit),
                   _SHR_E_PARAM, "sample_rate_dividend is out of range.\n");
    SHR_MAX_VERIFY(mirror_dest->sample_rate_divisor, dnx_data_snif.ingress.prob_max_val_get(unit),
                   _SHR_E_PARAM, "sample_rate_divisor is out of range.\n");

    max_val = dnx_data_lif.global_lif.nof_global_out_lifs_get(unit) - 1;
    SHR_MAX_VERIFY(mirror_dest->encap_id, max_val, _SHR_E_PARAM, "encap_id is out of range.\n");
    SHR_IF_ERR_EXIT(dbal_tables_field_predefine_value_get(unit,
                                                          DBAL_TABLE_SNIF_COMMAND_TABLE,
                                                          DBAL_FIELD_TC,
                                                          FALSE, 0, 0, DBAL_PREDEF_VAL_MAX_VALUE, &max_val));
    SHR_MAX_VERIFY(mirror_dest->packet_control_updates.prio, max_val,
                   _SHR_E_PARAM, "packet_control_updates.prio is out of range.\n");
    SHR_IF_ERR_EXIT(dbal_tables_field_predefine_value_get(unit,
                                                          DBAL_TABLE_SNIF_COMMAND_TABLE,
                                                          DBAL_FIELD_DP,
                                                          FALSE, 0, 0, DBAL_PREDEF_VAL_MAX_VALUE, &max_val));
    SHR_MAX_VERIFY(mirror_dest->packet_control_updates.color, max_val,
                   _SHR_E_PARAM, "packet_control_updates.color is out of range.\n");
    {
        SHR_IF_ERR_EXIT(dbal_tables_field_predefine_value_get(unit,
                                                              DBAL_TABLE_SNIF_COMMAND_TABLE,
                                                              DBAL_FIELD_IN_PP_PORT,
                                                              FALSE, 0, 0, DBAL_PREDEF_VAL_MAX_VALUE, &max_val));
    }
    SHR_MAX_VERIFY(mirror_dest->packet_control_updates.in_port, max_val,
                   _SHR_E_PARAM, "packet_control_updates.in_port is out of range.\n");
    SHR_IF_ERR_EXIT(dbal_tables_field_predefine_value_get(unit,
                                                          DBAL_TABLE_SNIF_COMMAND_TABLE,
                                                          DBAL_FIELD_ST_VSQ_PTR,
                                                          FALSE, 0, 0, DBAL_PREDEF_VAL_MAX_VALUE, &max_val));
    SHR_MAX_VERIFY(mirror_dest->packet_control_updates.vsq, max_val,
                   _SHR_E_PARAM, "packet_control_updates.vsq is out of range.\n");
    SHR_IF_ERR_EXIT(dbal_tables_field_predefine_value_get(unit,
                                                          DBAL_TABLE_SNIF_COMMAND_TABLE,
                                                          DBAL_FIELD_LAG_LB_KEY,
                                                          FALSE, 0, 0, DBAL_PREDEF_VAL_MAX_VALUE, &max_val));
    SHR_MAX_VERIFY(mirror_dest->packet_control_updates.trunk_hash_result, max_val,
                   _SHR_E_PARAM, "packet_control_updates.trunk_hash_result is out of range.\n");
    SHR_IF_ERR_EXIT(dbal_tables_field_predefine_value_get(unit,
                                                          DBAL_TABLE_SNIF_COMMAND_TABLE,
                                                          DBAL_FIELD_ADMIT_PROFILE,
                                                          FALSE, 0, 0, DBAL_PREDEF_VAL_MAX_VALUE, &max_val));
    SHR_MAX_VERIFY(mirror_dest->packet_control_updates.ecn_value, max_val,
                   _SHR_E_PARAM, "packet_control_updates.ecn_value is out of range.\n");
    SHR_IF_ERR_EXIT(dbal_tables_field_predefine_value_get(unit,
                                                          DBAL_TABLE_SNIF_COUNTING_TABLE,
                                                          DBAL_FIELD_INT_STAT_OBJ_META_DATA,
                                                          FALSE, 0, 0, DBAL_PREDEF_VAL_MAX_VALUE, &max_val));
    SHR_MAX_VERIFY(mirror_dest->packet_control_updates.metadata, max_val,
                   _SHR_E_PARAM, "packet_control_updates.metadata is out of range.\n");
    SHR_MAX_VERIFY(mirror_dest->egress_sample_rate_dividend, dnx_data_snif.egress.prob_max_val_get(unit),
                   _SHR_E_PARAM, "egress_sample_rate_dividend is out of range.\n");
    SHR_MAX_VERIFY(mirror_dest->egress_sample_rate_divisor, dnx_data_snif.egress.prob_max_val_get(unit),
                   _SHR_E_PARAM, "egress_sample_rate_divisor is out of range.\n");

    if (!dnx_data_snif.egress.feature_get(unit, dnx_data_snif_egress_probability_sample)
        && (mirror_dest->egress_sample_rate_dividend < mirror_dest->egress_sample_rate_divisor))
    {
        SHR_ERR_EXIT(_SHR_E_PARAM, "egress mirror probability sampling not supported by this device.\n");
    }

    SHR_MAX_VERIFY(mirror_dest->is_recycle_strict_priority, 1,
                   _SHR_E_PARAM, "is_recycle_strict_priority is out of range.\n");

    /** ext stat verify */
    if (dnx_data_snif.ingress.feature_get(unit, dnx_data_snif_ingress_ext_stat_dedicated_config))
    {
        SHR_IF_ERR_EXIT(dbal_tables_field_predefine_value_get(unit,
                                                              DBAL_TABLE_SNIF_COUNTING_TABLE,
                                                              DBAL_FIELD_EXT_STAT_DATA_ID,
                                                              FALSE, 0, 0, DBAL_PREDEF_VAL_MAX_VALUE, &max_val));
        SHR_IF_ERR_EXIT(dbal_tables_field_predefine_value_get(unit,
                                                              DBAL_TABLE_SNIF_COUNTING_TABLE,
                                                              DBAL_FIELD_EXT_STAT_DATA_OPCODE,
                                                              FALSE, 0, 0, DBAL_PREDEF_VAL_MAX_VALUE,
                                                              &max_val_stat_type));
        for (i = 0; i < BCM_MIRROR_EXT_STAT_ID_COUNT; i++)
        {
            SHR_MAX_VERIFY(mirror_dest->ext_stat_type_id[i], max_val_stat_type,
                           _SHR_E_PARAM, "ext_stat_type_id[%d] is out of range.\n", i);
            SHR_MAX_VERIFY(mirror_dest->ext_stat_id[i], max_val, _SHR_E_PARAM, "ext_stat_id[%d] is out of range.\n", i);
        }
        SHR_MAX_VERIFY(mirror_dest->ext_stat_valid, 1, _SHR_E_PARAM, "ext_stat_valid is out of range.\n");
    }

    /** mirror on drop profile verification */
    if (mirror_dest->flags2 & BCM_MIRROR_DEST_FLAGS2_MIRROR_ON_DROP)
    {
        int profile, mod_profile_index, nof_admit_profiles, admit_profile_index;
        int *drop_group_bmp;

        /** verify whether mirror on drop is supported on this device */
        if (dnx_data_ingr_congestion.
            mirror_on_drop.feature_get(unit, dnx_data_ingr_congestion_mirror_on_drop_is_supported) == FALSE)
        {
            SHR_ERR_EXIT(_SHR_E_PARAM, "Mirror on Drop feature is not supported for this device\n");
        }

        /** verify correct bitmap is used */
        if (dnx_data_snif.ingress.feature_get(unit, dnx_data_snif_ingress_mirror_on_drop_admit_profile_supported))
        {
            if (mirror_dest->drop_group_bmp != BCM_MIRROR_DROP_GROUP_BMP_ALL)
            {
                SHR_ERR_EXIT(_SHR_E_PARAM, "drop_group_bmp is no longer supported, instead use drop_group_bmp_array");
            }
        }

        /** get the amount of mirror on drop admit profiles */
        SHR_IF_ERR_EXIT(dnx_mirror_on_drop_nof_admit_profiles_get(unit, &nof_admit_profiles));

        /** iterate over admit profiles */
        for (admit_profile_index = 0; admit_profile_index < nof_admit_profiles; admit_profile_index++)
        {
            /** determine mirror on drop group bitmap */
            if (dnx_data_snif.ingress.feature_get(unit, dnx_data_snif_ingress_mirror_on_drop_admit_profile_supported))
            {
                drop_group_bmp = &(mirror_dest->drop_group_bmp_array[admit_profile_index]);
            }
            else
            {
                drop_group_bmp = &(mirror_dest->drop_group_bmp);
            }

            /** verify drop group bitmap */
            if (*drop_group_bmp != BCM_MIRROR_DROP_GROUP_BMP_ALL)
            {
                if (dnx_data_snif.ingress.nof_mirror_on_drop_profiles_get(unit) == 1)
                {
                    /** On devices where we only have 1 MoD profile, always set all */
                    *drop_group_bmp = BCM_MIRROR_DROP_GROUP_BMP_ALL;
                }
                else
                {
                    /** If user did not specify to set all MoD profiles and we have more than 1, check range of IDs */
                    SHR_BITSET_RANGE(&drop_group_bmp_mask, dnx_data_snif.ingress.nof_mirror_on_drop_profiles_get(unit),
                                     (SAL_UINT32_NOF_BITS -
                                      dnx_data_snif.ingress.nof_mirror_on_drop_profiles_get(unit)));
                    if ((drop_group_bmp_mask & *drop_group_bmp) != 0)
                    {
                        SHR_ERR_EXIT(_SHR_E_PARAM,
                                     "Mirror on drop sniff profiles bitmap has IDs out of range, max ID is %d.\n",
                                     (dnx_data_snif.ingress.nof_mirror_on_drop_profiles_get(unit) - 1));
                    }
                }
            }

            SHR_BIT_ITER((uint32 *) drop_group_bmp, dnx_data_snif.ingress.nof_mirror_on_drop_profiles_get(unit),
                         mod_profile_index)
            {
                /** verify that mirror on drop profile not already exists */
                SHR_IF_ERR_EXIT(dnx_mirror_db.mirror_on_drop_profile.get(unit, admit_profile_index,
                                                                         mod_profile_index, &profile));
                if ((profile != DNX_MIRROR_ON_DROP_INVALID_PROFILE) && !(mirror_dest->flags & BCM_MIRROR_DEST_REPLACE))
                {
                    SHR_ERR_EXIT(_SHR_E_PARAM, "Mirror on drop sniff profile already exists = %d.\n", profile);
                }
            }
            /** Mirror on drop profile doesn't support probability */
            if (mirror_dest->sample_rate_dividend < mirror_dest->sample_rate_divisor)
            {
                SHR_ERR_EXIT(_SHR_E_PARAM, "Mirror probability sampling not supported for mirror on drop profile.\n");
            }

            /** destination must be of type VOQ */
            if (!BCM_GPORT_IS_UCAST_QUEUE_GROUP(mirror_dest->gport)
                && !BCM_GPORT_IS_MCAST_QUEUE_GROUP(mirror_dest->gport))
            {
                SHR_ERR_EXIT(_SHR_E_PARAM, "Destination must be VOQ for mirror on drop profile.\n");
            }
        }
    }

exit:
    SHR_FUNC_EXIT;
}

/**
 * \brief - Verify mirror destination profile attributes for BCM-API: bcm_dnx_mirror_destination_destroy()
 *
 * \par DIRECT_INPUT:
 *   \param [in] unit - Unit ID
 *   \param [in] mirror_dest_id - gport of mirror profile
 *
 * \remark
 *   * None
 * \see
 *   * None
 */
static shr_error_e
dnx_mirror_destination_destroy_verify(
    int unit,
    bcm_gport_t mirror_dest_id)
{
    uint8 is_allocated;
    int action_profile_id;

    SHR_FUNC_INIT_VARS(unit);

    /** Verify valid gport type */
    if (BCM_GPORT_IS_MIRROR(mirror_dest_id) == FALSE)
    {
        SHR_ERR_EXIT(_SHR_E_PARAM, "Specified mirror destination has incorrect gport type: 0x%x", mirror_dest_id);
    }

    /** check whether the given snif profile is allocated, if not return an error */
    SHR_IF_ERR_EXIT(dnx_mirror_profile_is_allocated(unit, mirror_dest_id, &is_allocated));
    if (is_allocated == FALSE)

    {
        action_profile_id = BCM_GPORT_MIRROR_GET(mirror_dest_id);
        SHR_ERR_EXIT(_SHR_E_PARAM, "The given profile: %d wasn't allocated", action_profile_id);
    }

exit:
    SHR_FUNC_EXIT;
}

/**
 * \brief - Verify mirror destination profile attributes for BCM-API: bcm_dnx_mirror_destination_get()
 *
 * \par DIRECT_INPUT:
 *   \param [in] unit - Unit ID
 *   \param [in] mirror_dest_id - gport of mirror profile
 *   \param [in] mirror_dest - Mirror destination attributes
 *
 * \remark
 *   * None
 * \see
 *   * None
 */
static shr_error_e
dnx_mirror_destination_get_verify(
    int unit,
    bcm_gport_t mirror_dest_id,
    bcm_mirror_destination_t * mirror_dest)
{
    SHR_FUNC_INIT_VARS(unit);

    SHR_NULL_CHECK(mirror_dest, _SHR_E_PARAM, "mirror_dest");

    /** Set mirror on drop group bit map for backward compatibility*/
    if ((dnx_data_snif.ingress.nof_mirror_on_drop_profiles_get(unit) == 1) &&
        (mirror_dest->flags2 & BCM_MIRROR_DEST_FLAGS2_MIRROR_ON_DROP))
    {
        mirror_dest->drop_group_bmp = -1;
    }
    /*
     * Same verify function as for bcm_dnx_mirror_destination_destroy() API,
     * since both the get() and destroy() APIs expect the same input parameters - a valid mirror profile.
     */
    SHR_IF_ERR_EXIT(dnx_mirror_destination_destroy_verify(unit, mirror_dest_id));

exit:
    SHR_FUNC_EXIT;
}

/**
 * \brief - Verify mirror rule destination flags for BCM-API: bcm_mirror_port_vlan_destination_*()
 *
 * \par DIRECT_INPUT:
 *   \param [in] unit - Unit ID
 *   \param [in] port - original port
 *   \param [in] vlan - original vlan id
 *   \param [in] flags - [BCM_MIRROR_PORT_INGRESS | BCM_MIRROR_PORT_EGRESS | BCM_MIRROR_PORT_UNTAGGED_ONLY | BCM_MIRROR_PORT_TAGGED_DEFAULT]
 *
 * \remark
 *   * None
 * \see
 *   * None
 */
static shr_error_e
dnx_mirror_port_vlan_destination_flag_verify(
    int unit,
    bcm_port_t port,
    bcm_vlan_t vlan,
    uint32 flags)
{
    SHR_FUNC_INIT_VARS(unit);

    /*
     * verify the supported flags
     */
    if (flags & ~(BCM_MIRROR_PORT_INGRESS | BCM_MIRROR_PORT_EGRESS | BCM_MIRROR_PORT_DELETE_ALL |
                  BCM_MIRROR_PORT_UNTAGGED_ONLY | BCM_MIRROR_PORT_TAGGED_DEFAULT))
    {
        SHR_ERR_EXIT(_SHR_E_PARAM, "An unsupported bcm mirror port flags was specified: 0x%x", flags);
    }

    /*
     * verify that BCM_MIRROR_PORT_INGRESS or BCM_MIRROR_PORT_EGRESS were set
     */
    if ((flags & (BCM_MIRROR_PORT_INGRESS | BCM_MIRROR_PORT_EGRESS)) == 0)
    {
        SHR_ERR_EXIT(_SHR_E_PARAM, "At least one of BCM_MIRROR_PORT_INGRESS/BCM_MIRROR_PORT_EGRESS"
                     "flags should be specified with this API: 0x%x", flags);
    }

    /*
     * when vlan is not mentioned extra flags BCM_MIRROR_PORT_UNTAGGED_ONLY | BCM_MIRROR_PORT_TAGGED_DEFAULT
     * can be set but not together
     */
    if (vlan == BCM_VLAN_INVALID)
    {
        if ((flags & BCM_MIRROR_PORT_UNTAGGED_ONLY) && (flags & BCM_MIRROR_PORT_TAGGED_DEFAULT))
        {
            SHR_ERR_EXIT(_SHR_E_PARAM,
                         "BCM_MIRROR_PORT_UNTAGGED_ONLY & BCM_MIRROR_PORT_TAGGED_DEFAULT can't be specified together");
        }

        /*
         * Flags BCM_MIRROR_PORT_UNTAGGED_ONLY and BCM_MIRROR_PORT_TAGGED_DEFAULT are valid for
         * ingress APIs only
         */
        if ((flags & BCM_MIRROR_PORT_UNTAGGED_ONLY) && (flags & BCM_MIRROR_PORT_EGRESS))
        {
            SHR_ERR_EXIT(_SHR_E_PARAM,
                         "BCM_MIRROR_PORT_UNTAGGED_ONLY & BCM_MIRROR_PORT_EGRESS can't be specified together");
        }

        if ((flags & BCM_MIRROR_PORT_TAGGED_DEFAULT) && (flags & BCM_MIRROR_PORT_EGRESS))
        {
            SHR_ERR_EXIT(_SHR_E_PARAM,
                         "BCM_MIRROR_PORT_TAGGED_DEFAULT & BCM_MIRROR_PORT_EGRESS can't be specified together");
        }
    }
    else
    {
        if (flags & ~(BCM_MIRROR_PORT_INGRESS | BCM_MIRROR_PORT_EGRESS | BCM_MIRROR_PORT_DELETE_ALL))
        {
            SHR_ERR_EXIT(_SHR_E_PARAM, "An unsupported bcm mirror port flags was specified: 0x%x", flags);
        }
    }

exit:
    SHR_FUNC_EXIT;
}

/**
 * \brief - Verify mirror destination addition rule for BCM-API: bcm_dnx_mirror_port_vlan_destination_add()
 *
 * \par DIRECT_INPUT:
 *   \param [in] unit - Unit ID
 *   \param [in] port - original port
 *   \param [in] vlan - original vlan id
 *   \param [in] flags - [BCM_MIRROR_PORT_INGRESS | BCM_MIRROR_PORT_EGRESS | BCM_MIRROR_PORT_UNTAGGED_ONLY | BCM_MIRROR_PORT_TAGGED_DEFAULT]
 *   \param [in] destid - Mirror destination (profile) index
 *
 * \remark
 *   * None
 * \see
 *   * None
 */
static shr_error_e
dnx_mirror_port_vlan_destination_add_verify(
    int unit,
    bcm_port_t port,
    bcm_vlan_t vlan,
    uint32 flags,
    bcm_gport_t destid)
{
    uint8 is_allocated;
    uint32 action_profile_id, dft_action_profile_id;
    SHR_FUNC_INIT_VARS(unit);

    action_profile_id = BCM_GPORT_MIRROR_GET(destid);

    /*
     * verify valid flags
     */
    SHR_IF_ERR_EXIT(dnx_mirror_port_vlan_destination_flag_verify(unit, port, vlan, flags));

    /*
     * check destid validity
     */
    if (!BCM_GPORT_IS_MIRROR_MIRROR(destid))
    {
        SHR_ERR_EXIT(_SHR_E_PARAM, "Destination gport (0x%x) is not supported. this API supports only mirror rules",
                     destid);
    }

    /*
     * Check whether the profile id is in the range of mirror profile ids which can be pointed out by vlan rules
     */
    if ((flags & BCM_MIRROR_PORT_INGRESS) && (action_profile_id >= dnx_data_snif.ingress.mirror_nof_profiles_get(unit)))
    {
        SHR_ERR_EXIT(_SHR_E_PARAM, "Specified profile id (%u) can not be used for this API", action_profile_id);
    }

    if ((flags & BCM_MIRROR_PORT_EGRESS) && (action_profile_id >= dnx_data_snif.egress.mirror_nof_profiles_get(unit)))
    {
        SHR_ERR_EXIT(_SHR_E_PARAM, "Specified profile id (%u) can not be used for this API", action_profile_id);
    }

    /*
     * check whether the given profile is allocated, if not return an error
     */
    SHR_IF_ERR_EXIT(dnx_mirror_profile_is_allocated(unit, destid, &is_allocated));
    if (is_allocated == FALSE)
    {
        action_profile_id = BCM_GPORT_MIRROR_GET(destid);
        SHR_ERR_EXIT(_SHR_E_PARAM, "Specified destination profile id (%u) has not been allocated", action_profile_id);
    }

    SHR_IF_ERR_EXIT(dnx_mirror_rule_get(unit, port, BCM_VLAN_INVALID, flags, &dft_action_profile_id));
    if (vlan != BCM_VLAN_INVALID)
    {
        SHR_IF_ERR_EXIT(dnx_mirror_rule_get(unit, port, vlan, flags, &action_profile_id));
        /*
         * Allow to add only when: 1. not set 2. already set by default
         * if the port & vlan are pointing to non-default profile and profile not equal to default
         * error should be returned.
         */
        if ((action_profile_id != BCM_MIRROR_INVALID_PROFILE) && (action_profile_id != dft_action_profile_id))
        {
            SHR_ERR_EXIT(_SHR_E_PARAM, "Specified port & vlan are pointing to non-default profile: %u",
                         action_profile_id);
        }
    }
    else
    {
        /*
         * Allow to set only when it is not set
         */
        if (dft_action_profile_id != BCM_MIRROR_INVALID_PROFILE)
        {
            SHR_ERR_EXIT(_SHR_E_PARAM, "Specified port are pointing to default profile: %u", dft_action_profile_id);
        }
    }
exit:
    SHR_FUNC_EXIT;
}

/**
 * \brief - Verify mirror destination deletion rule for BCM-API: bcm_dnx_mirror_port_vlan_destination_delete()
 *
 * \par DIRECT_INPUT:
 *   \param [in] unit - Unit ID
 *   \param [in] port - original port
 *   \param [in] vlan - original vlan id
 *   \param [in] flags - [BCM_MIRROR_PORT_INGRESS | BCM_MIRROR_PORT_EGRESS | BCM_MIRROR_PORT_UNTAGGED_ONLY | BCM_MIRROR_PORT_TAGGED_DEFAULT]
 *   \param [in] destid - Mirror destination (profile) index
 *   \param [in] current_profile_id - current mirror destination (profile) index
 *
 * \remark
 *   * None
 * \see
 *   * None
 */
static shr_error_e
dnx_mirror_port_vlan_destination_delete_verify(
    int unit,
    bcm_port_t port,
    bcm_vlan_t vlan,
    uint32 flags,
    bcm_gport_t destid,
    uint32 current_profile_id)
{
    uint8 is_allocated;
    uint32 received_profile_id;
    SHR_FUNC_INIT_VARS(unit);

    /*
     * verify valid flags
     */
    SHR_IF_ERR_EXIT(dnx_mirror_port_vlan_destination_flag_verify(unit, port, vlan, flags));

    SHR_IF_ERR_EXIT(dnx_mirror_rule_get(unit, port, vlan, flags, &received_profile_id));
    if (current_profile_id == BCM_MIRROR_INVALID_PROFILE)
    {
        SHR_ERR_EXIT(_SHR_E_PARAM, "Invalid of mirror profile");
    }

    if (received_profile_id == BCM_MIRROR_INVALID_PROFILE)
    {
        if (!(flags & BCM_MIRROR_PORT_DELETE_ALL))
        {
            SHR_ERR_EXIT(_SHR_E_PARAM, "the port mirror is not mapped to a profile");
        }
    }

    /*
     * If delelte all not to check
     */
    if (!(flags & BCM_MIRROR_PORT_DELETE_ALL) && (current_profile_id != received_profile_id))
    {
        SHR_ERR_EXIT(_SHR_E_PARAM, "the delete configured profile doesn't exist on the port");
    }

    /*
     * for BCM_MIRROR_PORT_DELETE_ALL destid (profile) does not specified and therefore does not need to be checked
     */
    if ((flags & BCM_MIRROR_PORT_DELETE_ALL) == 0)
    {
        /*
         * check destid validity
         */
        if (!BCM_GPORT_IS_MIRROR_MIRROR(destid))
        {
            SHR_ERR_EXIT(_SHR_E_PARAM, "Destination gport (0x%x) is not supported. this API supports only mirror rules",
                         destid);
        }

        received_profile_id = BCM_GPORT_MIRROR_GET(destid);
        /*
         * check whether the given profile is allocated, if not return an error
         */
        SHR_IF_ERR_EXIT(dnx_mirror_profile_is_allocated(unit, destid, &is_allocated));
        if (is_allocated == FALSE)
        {
            SHR_ERR_EXIT(_SHR_E_PARAM, "Specified destination profile id (%d) has not been allocated",
                         received_profile_id);
        }
    }

exit:
    SHR_FUNC_EXIT;
}
/**
 * \brief - Verify mirror destination counter command for BCM-API: bcm_dnx_mirror_destination_count_command_get()
 *
 * \par DIRECT_INPUT:
 *   \param [in] unit - Unit ID
 *   \param [in] core_id - specific core or core "ALL"
 *   \param [in] mirror_dest_id - Sniff destination (profile) index
 *   \param [in] counter_cmd_id - counter command id (interface)
 *
 * \remark
 *   * None
 * \see
 *   * None
 */
static shr_error_e
dnx_mirror_destination_count_command_get_verify(
    int unit,
    bcm_core_t core_id,
    bcm_gport_t mirror_dest_id,
    int counter_cmd_id)
{
    int action_profile_id = 0;
    uint8 is_allocated;

    SHR_FUNC_INIT_VARS(unit);

    /** check whether the given sniff profile is allocated, if not return an error */
    SHR_IF_ERR_EXIT(dnx_mirror_profile_is_allocated(unit, mirror_dest_id, &is_allocated));
    if (is_allocated == FALSE)
    {
        action_profile_id = BCM_GPORT_MIRROR_GET(mirror_dest_id);

        SHR_ERR_EXIT(_SHR_E_PARAM, "snif profile id %d is not allocated mirror_dest_id: 0x%x\n", action_profile_id,
                     mirror_dest_id);
    }

    /*
     * Command id verification
     */
    SHR_IF_ERR_EXIT(dnx_crps_mgmt_counter_command_id_verify
                    (unit, bcmStatCounterInterfaceIngressReceivePp, counter_cmd_id));

exit:
    SHR_FUNC_EXIT;
}

/**
 * \brief - Verify mirror destination counter command for BCM-API: bcm_dnx_mirror_destination_count_command_set()
 *
 * \par DIRECT_INPUT:
 *   \param [in] unit - Unit ID
 *   \param [in] core_id - specific core or core "ALL"
 *   \param [in] mirror_dest_id - Sniff destination (profile) index
 *   \param [in] counter_cmd_id - counter command id (interface)
 *   \param [in] mirror_count_info - structure which contains sniff counting attributes
 *
 * \remark
 *   * None
 * \see
 *   * None
 */
static shr_error_e
dnx_mirror_destination_count_command_set_verify(
    int unit,
    bcm_core_t core_id,
    bcm_gport_t mirror_dest_id,
    int counter_cmd_id,
    bcm_mirror_profile_cmd_count_t * mirror_count_info)
{
    int action_profile_id = 0;
    uint8 is_allocated;

    SHR_FUNC_INIT_VARS(unit);

    /** check whether the given sniff profile is allocated, if not return an error */
    SHR_IF_ERR_EXIT(dnx_mirror_profile_is_allocated(unit, mirror_dest_id, &is_allocated));
    if (is_allocated == FALSE)
    {
        action_profile_id = BCM_GPORT_MIRROR_GET(mirror_dest_id);

        SHR_ERR_EXIT(_SHR_E_PARAM, "snif profile id %d is not allocated mirror_dest_id: 0x%x\n", action_profile_id,
                     mirror_dest_id);
    }

    /*
     * Command id verification
     */
    SHR_IF_ERR_EXIT(dnx_crps_mgmt_counter_command_id_verify
                    (unit, bcmStatCounterInterfaceIngressReceivePp, counter_cmd_id));
    if (mirror_count_info->is_meter == 1)
    {
        SHR_ERR_EXIT(_SHR_E_PARAM, "Meter is not supported - bcm_mirror_destination_count_command_set\n");
    }
    /*
     * if need to count, verify that there is an engine that is possible to count it
     */
    if (mirror_count_info->is_counted == 1)
    {
        SHR_IF_ERR_EXIT(dnx_crps_mgmt_counter_generation_verify
                        (unit, core_id, bcmStatCounterInterfaceIngressReceivePp,
                         counter_cmd_id, mirror_count_info->type_id, mirror_count_info->object_stat_id));
    }

exit:
    SHR_FUNC_EXIT;
}

/**
 * \brief - Allocate mirror profile and set its attributes
 *
 * \par DIRECT_INPUT:
 *   \param [in] unit - Unit-ID
 *   \param [in] mirror_dest - Mirror profile attributes: \n
 *   * mirror_dest.mirror_dest_id - gport representing the command id. gport: BCM_GPORT_MIRROR \n
 *   * mirror_dest.gport - gport representing the destination of the command \n
 *   * mirror_dest.flags - the following flags are supported: \n
 *     * BCM_MIRROR_DEST_WITH_ID - allocate certain snif profile ID given in mirror_dest.gport \n
 *     * BCM_MIRROR_DEST_REPLACE - update already allocated profile \n
 *     * BCM_MIRROR_DEST_UPDATE_COUNTER - update counting attributes
 *     * BCM_MIRROR_DEST_IS_SNOOP - snif command is snoop (default is mirror)
 *   * mirror_dest.sample_rate_dividend - dividend of the probabiity to
 *     perfrom the snif command, the probability is calculated as following: \n
 *     mirror_dest.sample_rate_dividend/mirror_dest.sample_rate_divisor
 *   * mirror_dest.sample_rate_divisor - divisor of the probabiity to perfrom the snif \n
 *     command, the probability is calculated as following: \n
 *     mirror_dest.sample_rate_dividend/mirror_dest.sample_rate_divisor \n
 *   * mirror_dest.packet_copy_size - crop size in bytes (how many bytes to snif from the original packet)
 *   * mirror_dest.packet_control_updates - packet control parameters:  \n
 *     *  valid - Used to specify which fields to use for header changes. Possible values will be named
 *                BCM_MIRROR_PKT_HEADER_UPDATE_*
 *     * color - drop precedence (DP)
 *     * prio - traiffc class (TC)
 *     * ecn_value - ECN capable and congestion encoding
 *     * trunk_hash_result - LAG load balancing key
 *     * in_port - ingress port
 *     * vsq - statistics VSQ pointer (VSQ-D)
 *
 * \par INDIRECT INPUT:
 *   * Allocation manger of SNIF_INGRESS_MIRROR_PROFILES
 * \par DIRECT OUTPUT:
 *   int
 * \par INDIRECT OUTPUT
 *   * None
 * \remark
 *  * This API creates and configures the SNIF profile. 3 SNIF applications are supported: \n
 *    Mirror (Ingress/Egress), Snoop(Ingress/Egress), Statistical sample(Ingress).
 *  * Upon creation of a SNIF rule, see \ref bcm_dnx_mirror_port_vlan_destination_add API for
 *    example, this profile should be mapped to the SNIF rule.
 *
 * \see
 *   * None
 */
int
bcm_dnx_mirror_destination_create(
    int unit,
    bcm_mirror_destination_t * mirror_dest)
{
    SHR_FUNC_INIT_VARS(unit);
    DNX_ERR_RECOVERY_START(unit);

    /** Verify API attributes and ID */
    SHR_INVOKE_VERIFY_DNXC(dnx_mirror_destination_create_verify(unit, mirror_dest));

    /** Allocate(if required) profile and configure its attributes in HW */
    SHR_IF_ERR_EXIT(dnx_mirror_profile_create(unit, mirror_dest));

exit:
    DNX_ERR_RECOVERY_END(unit);
    SHR_FUNC_EXIT;
}

/**
 * \brief - Destroy(deallocate) an allocated mirror profile
 *
 * \par DIRECT_INPUT:
 *   \param [in] unit - Unit ID
 *   \param [in] mirror_dest_id - Gport of profile ID to be destroyed
 *
 * \remark
 *   * None
 * \see
 *   * None
 */
int
bcm_dnx_mirror_destination_destroy(
    int unit,
    bcm_gport_t mirror_dest_id)
{
    SHR_FUNC_INIT_VARS(unit);
    DNX_ERR_RECOVERY_START(unit);

    /** Verify parameters */
    SHR_INVOKE_VERIFY_DNXC(dnx_mirror_destination_destroy_verify(unit, mirror_dest_id));

    /** Deallocate profile and roll HW back to defaults */
    SHR_IF_ERR_EXIT(dnx_mirror_profile_destroy(unit, mirror_dest_id));

exit:
    DNX_ERR_RECOVERY_END(unit);
    SHR_FUNC_EXIT;
}

/**
 * \brief - Retrieve mirror profile attributes.
 *
 * \par DIRECT_INPUT:
 *   \param [in] unit - Unit ID
 *   \param [in] mirror_dest_id - Gport representing the mirror profile.
 *   \param [out] mirror_dest - Mirror profile attributes. For more info see \ref bcm_dnx_mirror_destination_create.
 *
 * \remark
 *   * None
 * \see
 *   * None
 */
int
bcm_dnx_mirror_destination_get(
    int unit,
    bcm_gport_t mirror_dest_id,
    bcm_mirror_destination_t * mirror_dest)
{
    SHR_FUNC_INIT_VARS(unit);
    DNX_ERR_RECOVERY_NOT_NEEDED(unit);

    /** Verify parameters */
    SHR_INVOKE_VERIFY_DNXC(dnx_mirror_destination_get_verify(unit, mirror_dest_id, mirror_dest));

    /** Initialize the Mirror destination struct */
    bcm_mirror_destination_t_init(mirror_dest);

    /** Retrieve mirror attributes */
    SHR_IF_ERR_EXIT(dnx_mirror_profile_get(unit, mirror_dest_id, mirror_dest));

exit:
    SHR_FUNC_EXIT;
}

/**
 * \brief -
 *
 * \par DIRECT_INPUT:
 *   \param [in] unit -
 *   \param [in] cb -
 *   \param [in] user_data -
 *
 * \remark
 *   * None
 * \see
 *   * None
 */
int
bcm_dnx_mirror_destination_traverse(
    int unit,
    bcm_mirror_destination_traverse_cb cb,
    void *user_data)
{
    uint32 action_profile_id;
    bcm_mirror_destination_t mirror_dest;
    uint8 is_allocated;
    uint32 ret;
    uint32 snif_type;
    bcm_gport_t gport;

    SHR_FUNC_INIT_VARS(unit);
    DNX_ERR_RECOVERY_NOT_NEEDED(unit);

    SHR_NULL_CHECK(cb, _SHR_E_PARAM, "cb");

    for (action_profile_id = DNX_MIRROR_PROFILE_INGRESS_PROFILE_MIN;
         action_profile_id < dnx_data_snif.ingress.nof_profiles_get(unit); ++action_profile_id)
    {
        for (snif_type = _SHR_GPORT_MIRROR_SUBTYPE_VAL_MIRROR;
             snif_type <= _SHR_GPORT_MIRROR_SUBTYPE_VAL_STAT_SAMPLE; ++snif_type)
        {
            _SHR_GPORT_MIRROR_FULL_SET(gport, action_profile_id, snif_type);
            SHR_IF_ERR_EXIT(dnx_mirror_profile_is_allocated(unit, gport, &is_allocated));
            if (is_allocated)
            {
                SHR_IF_ERR_EXIT(bcm_dnx_mirror_destination_get(unit, gport, &mirror_dest));
                ret = cb(unit, &mirror_dest, user_data);
                if (ret)
                {
                    SHR_ERR_EXIT(_SHR_E_FAIL, "callback function returned error value %d for mirror destination %u",
                                 ret, (unsigned) action_profile_id);
                }
            }
        }
    }

exit:
    SHR_FUNC_EXIT;
}

/**
 * \brief - API implementation of mapping port & vlan to a mirror destination profile
 *
 * \par DIRECT_INPUT:
 *   \param [in] unit - Unit ID
 *   \param [in] port
 *   \param [in] vlan - vlan id. BCM_VLAN_INVALID is an indicates for un-tagged mapping
 *   \param [in] flags - [BCM_MIRROR_PORT_INGRESS | BCM_MIRROR_PORT_EGRESS | BCM_MIRROR_PORT_UNTAGGED_ONLY | BCM_MIRROR_PORT_TAGGED_DEFAULT]
 *   \param [in] destid - Mirror destination (profile) index
 *   \param [in] options - not used
 *
 * \remark
 *   * None
 * \see
 *   * None
 */
int
bcm_dnx_mirror_port_vlan_destination_add(
    int unit,
    bcm_port_t port,
    bcm_vlan_t vlan,
    uint32 flags,
    bcm_gport_t destid,
    bcm_mirror_options_t options)
{
    SHR_FUNC_INIT_VARS(unit);
    DNX_ERR_RECOVERY_START(unit);

    /** Verify parameters */
    SHR_INVOKE_VERIFY_DNXC(dnx_mirror_port_vlan_destination_add_verify(unit, port, vlan, flags, destid));

    /** add mirror destination rule for ingress and egress accordingly */
    if (flags & BCM_MIRROR_PORT_INGRESS)
    {
        SHR_IF_ERR_EXIT(dnx_mirror_rule_add(unit, port, vlan, flags & (~BCM_MIRROR_PORT_EGRESS), destid));
    }
    if (flags & BCM_MIRROR_PORT_EGRESS)
    {
        SHR_IF_ERR_EXIT(dnx_mirror_rule_add(unit, port, vlan, flags & (~BCM_MIRROR_PORT_INGRESS), destid));
    }

exit:
    DNX_ERR_RECOVERY_END(unit);
    SHR_FUNC_EXIT;
}

/**
 * \brief - API implementation of getting the map of port & vlan to a mirror destination profile
 *
 * \par DIRECT_INPUT:
 *   \param [in] unit - Unit ID
 *   \param [in] port
 *   \param [in] vlan - vlan id. BCM_VLAN_INVALID is an indicates for un-tagged mapping
 *   \param [in] flags - [BCM_MIRROR_PORT_INGRESS | BCM_MIRROR_PORT_EGRESS | BCM_MIRROR_PORT_UNTAGGED_ONLY | BCM_MIRROR_PORT_TAGGED_DEFAULT]
 *   \param [in] mirror_dest_size - the size of destid array
 *   \param [in] destid - Mirror destination (profile) index array
 *   \param [in] destcount - the number of destinations returnred by this API. Maximum 2 in a case which both ingress and egress are mapped to destination
 *   \param [in] options - not used
 *
 * \remark
 *   * None
 * \see
 *   * None
 */
int
bcm_dnx_mirror_port_vlan_destination_get(
    int unit,
    bcm_port_t port,
    bcm_vlan_t vlan,
    uint32 flags,
    uint32 mirror_dest_size,
    bcm_gport_t * destid,
    uint32 *destcount,
    bcm_mirror_options_t * options)
{
    uint32 action_profile_id;
    SHR_FUNC_INIT_VARS(unit);
    DNX_ERR_RECOVERY_NOT_NEEDED(unit);

    /** Verify parameters */
    SHR_INVOKE_VERIFY_DNXC(dnx_mirror_port_vlan_destination_flag_verify(unit, port, vlan, flags));

    *destcount = 0;

    /*
     * get ingress mirror destination
     */
    if (flags & BCM_MIRROR_PORT_INGRESS)
    {
        SHR_IF_ERR_EXIT(dnx_mirror_rule_get(unit, port, vlan, flags & (~BCM_MIRROR_PORT_EGRESS), &action_profile_id));
        if (*destcount < mirror_dest_size)
        {
            BCM_GPORT_MIRROR_SET(destid[*destcount], action_profile_id);
            *destcount += 1;
        }
        else
        {
            SHR_ERR_EXIT(_SHR_E_CONFIG, "mirror_dest_size (%d) is too small to contain all destinations",
                         mirror_dest_size);
        }
    }

    /*
     * get egress mirror destination
     */
    if (flags & BCM_MIRROR_PORT_EGRESS)
    {
        SHR_IF_ERR_EXIT(dnx_mirror_rule_get(unit, port, vlan, flags & (~BCM_MIRROR_PORT_INGRESS), &action_profile_id));
        if (*destcount < mirror_dest_size)
        {
            BCM_GPORT_MIRROR_SET(destid[*destcount], action_profile_id);
            *destcount += 1;
        }
        else
        {
            SHR_ERR_EXIT(_SHR_E_CONFIG, "mirror_dest_size (%d) is to small too contain all destinations",
                         mirror_dest_size);
        }
    }

exit:
    SHR_FUNC_EXIT;
}

/**
 * \brief - API implementation of un-mapping port & vlan to a mirror destination profile
 *
 * \par DIRECT_INPUT:
 *   \param [in] unit - Unit ID
 *   \param [in] port
 *   \param [in] vlan - vlan id. BCM_VLAN_INVALID is an indicates for un-tagged mapping
 *   \param [in] flags - [BCM_MIRROR_PORT_INGRESS | BCM_MIRROR_PORT_EGRESS | BCM_MIRROR_PORT_UNTAGGED_ONLY | BCM_MIRROR_PORT_TAGGED_DEFAULT | BCM_MIRROR_PORT_DELETE_ALL]
 *   \param [in] destid - Mirror destination (profile) index
 *
 * \remark
 *   * there is only 1 mirror destination mapped to vlan & port. when BCM_MIRROR_PORT_DELETE_ALL is specified,
 *     the input destination is discarded and the un-map takes place without any verification
 * \see
 *   * None
 */
int
bcm_dnx_mirror_port_vlan_dest_delete(
    int unit,
    bcm_port_t port,
    bcm_vlan_t vlan,
    uint32 flags,
    bcm_gport_t destid)
{
    uint32 current_profile_id, profile_id_to_check;
    SHR_FUNC_INIT_VARS(unit);
    DNX_ERR_RECOVERY_START(unit);

    /*
     * Need to check the mir_dest_id
     */
    profile_id_to_check = BCM_GPORT_MIRROR_GET(destid);

    /*
     * delete ingress mirror destination rule
     */
    if ((flags & BCM_MIRROR_PORT_INGRESS))
    {
        /** get current profile id */
        SHR_IF_ERR_EXIT(dnx_mirror_rule_get(unit, port, vlan, (flags & ~BCM_MIRROR_PORT_EGRESS), &current_profile_id));

        /** Verify parameters */
        SHR_INVOKE_VERIFY_DNXC(dnx_mirror_port_vlan_destination_delete_verify
                               (unit, port, vlan, (flags & ~BCM_MIRROR_PORT_EGRESS), destid, profile_id_to_check));
        if (current_profile_id != BCM_MIRROR_INVALID_PROFILE)
        {
            SHR_IF_ERR_EXIT(dnx_mirror_rule_delete
                            (unit, port, vlan, (flags & ~BCM_MIRROR_PORT_EGRESS), current_profile_id));
        }
    }

    /*
     * delete egress mirror destination rule
     */
    if ((flags & BCM_MIRROR_PORT_EGRESS))
    {
        /** get current profile id */
        SHR_IF_ERR_EXIT(dnx_mirror_rule_get(unit, port, vlan, (flags & ~BCM_MIRROR_PORT_INGRESS), &current_profile_id));

        /** Verify parameters */
        SHR_INVOKE_VERIFY_DNXC(dnx_mirror_port_vlan_destination_delete_verify
                               (unit, port, vlan, (flags & ~BCM_MIRROR_PORT_INGRESS), destid, profile_id_to_check));
        if (current_profile_id != BCM_MIRROR_INVALID_PROFILE)
        {
            SHR_IF_ERR_EXIT(dnx_mirror_rule_delete
                            (unit, port, vlan, (flags & ~BCM_MIRROR_PORT_INGRESS), current_profile_id));
        }
    }

exit:
    DNX_ERR_RECOVERY_END(unit);
    SHR_FUNC_EXIT;
}

/**
 * See bcm_dnx_mirror_port_vlan_dest_delete function
 */
int
bcm_dnx_mirror_port_vlan_dest_delete_all(
    int unit,
    bcm_port_t port,
    bcm_vlan_t vlan,
    uint32 flags)
{
    return bcm_dnx_mirror_port_vlan_dest_delete(unit, port, vlan, flags | BCM_MIRROR_PORT_DELETE_ALL, 0);
}

/**
 * See bcm_dnx_mirror_port_vlan_destination_add function
 */
int
bcm_dnx_mirror_port_destination_add(
    int unit,
    bcm_port_t port,
    uint32 flags,
    bcm_gport_t mirror_dest,
    bcm_mirror_options_t options)
{
    return bcm_dnx_mirror_port_vlan_destination_add(unit, port, BCM_VLAN_INVALID, flags, mirror_dest, options);
}

/**
 * See bcm_dnx_mirror_port_vlan_destination_get function
 */
int
bcm_dnx_mirror_port_destination_get(
    int unit,
    bcm_port_t port,
    uint32 flags,
    int mirror_dest_size,
    bcm_gport_t * mirror_dest,
    int *mirror_dest_count,
    bcm_mirror_options_t * options)
{
    return bcm_dnx_mirror_port_vlan_destination_get(unit, port, BCM_VLAN_INVALID, flags, mirror_dest_size, mirror_dest,
                                                    (uint32 *) mirror_dest_count, options);
}

/**
 * See bcm_dnx_mirror_port_vlan_dest_delete function
 */
int
bcm_dnx_mirror_port_dest_delete(
    int unit,
    bcm_port_t port,
    uint32 flags,
    bcm_gport_t mirror_dest_id)
{
    return bcm_dnx_mirror_port_vlan_dest_delete(unit, port, BCM_VLAN_INVALID, flags, mirror_dest_id);
}

/**
 * See bcm_dnx_mirror_port_vlan_dest_delete_all function
 */
int
bcm_dnx_mirror_port_dest_delete_all(
    int unit,
    bcm_port_t port,
    uint32 flags)
{
    return bcm_dnx_mirror_port_vlan_dest_delete(unit, port, BCM_VLAN_INVALID, flags | BCM_MIRROR_PORT_DELETE_ALL, 0);
}

/**
 * See bcm_dnx_mirror_port_vlan_dest_add function
 */
int
bcm_dnx_mirror_port_vlan_dest_add(
    int unit,
    bcm_port_t port,
    bcm_vlan_t vlan,
    uint32 flags,
    bcm_gport_t destid)
{
    bcm_mirror_options_t options = { 0 };
    return bcm_dnx_mirror_port_vlan_destination_add(unit, port, vlan, flags, destid, options);
}

/**
 * See bcm_dnx_mirror_port_vlan_dest_get function
 */
int
bcm_dnx_mirror_port_vlan_dest_get(
    int unit,
    bcm_port_t port,
    bcm_vlan_t vlan,
    uint32 flags,
    uint32 mirror_dest_size,
    bcm_gport_t * destid,
    uint32 *destcount)
{
    return bcm_dnx_mirror_port_vlan_destination_get(unit, port, vlan, flags, mirror_dest_size, destid, destcount, NULL);
}

/**
 * See bcm_dnx_mirror_port_vlan_dest_add function
 */
int
bcm_dnx_mirror_port_dest_add(
    int unit,
    bcm_port_t port,
    uint32 flags,
    bcm_gport_t mirror_dest)
{
    bcm_mirror_options_t options = { 0 };
    return bcm_dnx_mirror_port_vlan_destination_add(unit, port, BCM_VLAN_INVALID, flags, mirror_dest, options);
}

/**
 * See bcm_dnx_mirror_port_vlan_dest_get function
 */
int
bcm_dnx_mirror_port_dest_get(
    int unit,
    bcm_port_t port,
    uint32 flags,
    int mirror_dest_size,
    bcm_gport_t * mirror_dest,
    int *mirror_dest_count)
{
    return bcm_dnx_mirror_port_vlan_destination_get(unit, port, BCM_VLAN_INVALID, flags, mirror_dest_size, mirror_dest,
                                                    (uint32 *) mirror_dest_count, NULL);
}

/**
 * \brief - API implementation to get counter command attributes for sniff destination (profile)
 *
 * \par DIRECT_INPUT:
 *   \param [in] unit - Unit ID
 *   \param [in] core_id - specific core or core "ALL"
 *   \param [in] mirror_dest_id - Sniff destination (profile) index
 *   \param [in] counter_cmd_id - counter command id (interface)
 *   \param [in] flags - not used
 *   \param [in] mirror_count_info - structure which contains sniff counting attributes
 *
 * \remark
 *   * all members of mirro_count_info structure can get BCM_MIRROR_COUNT_AS_ORIG as value.
 *     at this case the original packet decision is taken
 * \see
 *   * None
 */
int
bcm_dnx_mirror_destination_count_command_get(
    int unit,
    bcm_core_t core_id,
    bcm_gport_t mirror_dest_id,
    int counter_cmd_id,
    uint32 flags,
    bcm_mirror_profile_cmd_count_t * mirror_count_info)
{
    SHR_FUNC_INIT_VARS(unit);
    DNX_ERR_RECOVERY_NOT_NEEDED(unit);

    SHR_INVOKE_VERIFY_DNXC(dnx_mirror_destination_count_command_get_verify
                           (unit, core_id, mirror_dest_id, counter_cmd_id));

    SHR_IF_ERR_EXIT(dnx_mirror_profile_count_command_get
                    (unit, core_id, mirror_dest_id, counter_cmd_id, mirror_count_info));

exit:
    SHR_FUNC_EXIT;
}

/**
 * \brief - API implementation to set counter command attributes for sniff destination (profile)
 *
 * \par DIRECT_INPUT:
 *   \param [in] unit - Unit ID
 *   \param [in] core_id - specific core or core "ALL"
 *   \param [in] mirror_dest_id - Sniff destination (profile) index
 *   \param [in] counter_cmd_id - counter command id (interface)
 *   \param [in] flags - not used
 *   \param [in] mirror_count_info - structure which contains sniff counting attributes
 *
 * \remark
 *   * all members of mirro_count_info structure can get BCM_MIRROR_COUNT_AS_ORIG as value.
 *     at this case the original packet decision is taken
 * \see
 *   * None
 */
int
bcm_dnx_mirror_destination_count_command_set(
    int unit,
    bcm_core_t core_id,
    bcm_gport_t mirror_dest_id,
    int counter_cmd_id,
    uint32 flags,
    bcm_mirror_profile_cmd_count_t * mirror_count_info)
{
    SHR_FUNC_INIT_VARS(unit);
    DNX_ERR_RECOVERY_START(unit);

    SHR_INVOKE_VERIFY_DNXC(dnx_mirror_destination_count_command_set_verify
                           (unit, core_id, mirror_dest_id, counter_cmd_id, mirror_count_info));

    SHR_IF_ERR_EXIT(dnx_mirror_profile_count_command_set
                    (unit, core_id, mirror_dest_id, counter_cmd_id, mirror_count_info));

exit:
    DNX_ERR_RECOVERY_END(unit);
    SHR_FUNC_EXIT;
}

/*
 * See .h file
 */
shr_error_e
bcm_dnx_mirror_port_to_rcy_port_map_get(
    int unit,
    uint32 flags,
    bcm_port_t forward_port,
    bcm_mirror_port_to_rcy_map_info_t * rcy_map_info)
{
    SHR_FUNC_INIT_VARS(unit);
    DNX_ERR_RECOVERY_NOT_NEEDED(unit);

    SHR_NULL_CHECK(rcy_map_info, _SHR_E_PARAM, "rcy_map_info");

    /** verify that gport isn't trunk gport */
    if (BCM_GPORT_IS_TRUNK(forward_port))
    {
        SHR_ERR_EXIT(_SHR_E_PARAM, "trunk gport type is not supported.\n");
    }

    sal_memset(rcy_map_info, 0x0, sizeof(*rcy_map_info));

    SHR_IF_ERR_EXIT(dnx_mirror_port_to_rcy_port_map_get(unit, forward_port, rcy_map_info));

exit:
    SHR_FUNC_EXIT;
}

/*
 * See .h file
 */
shr_error_e
bcm_dnx_mirror_port_to_rcy_port_map_set(
    int unit,
    uint32 flags,
    bcm_port_t forward_port,
    bcm_mirror_port_to_rcy_map_info_t * rcy_map_info)
{
    uint32 supported_flags = 0;

    SHR_FUNC_INIT_VARS(unit);
    DNX_ERR_RECOVERY_START(unit);

    SHR_NULL_CHECK(rcy_map_info, _SHR_E_PARAM, "rcy_map_info");
    SHR_MASK_VERIFY(flags, supported_flags, _SHR_E_PARAM, "some of the flags are not supported.\n");

    /** verify that gport isn't trunk gport */
    if (BCM_GPORT_IS_TRUNK(forward_port))
    {
        SHR_ERR_EXIT(_SHR_E_PARAM, "trunk gport type is not supported.\n");
    }

    if (rcy_map_info->rcy_mirror_port == BCM_PORT_INVALID)
    {
        /** unmap forward port */
        SHR_IF_ERR_EXIT(dnx_mirror_port_to_rcy_port_unmap_set(unit, forward_port, rcy_map_info));
    }
    else
    {
        /** map forward port */
        SHR_IF_ERR_EXIT(dnx_mirror_port_to_rcy_port_map_set(unit, forward_port, rcy_map_info));
    }

exit:
    DNX_ERR_RECOVERY_END(unit);
    SHR_FUNC_EXIT;
}

/**
 * \brief
 *   Verify mirror destination profile attributes for BCM-API: bcm_dnx_mirror_header_info_set()
 *
 * \param [in] unit - The unit number
 * \param [in] flags - BCM_MIRROR_DEST_IS_SNOOP Snif command is snoop (default is mirror).
 *                   -  BCM_MIRROR_DEST_EGRESS_ADD_ORIG_SYSTEM_HEADER Keep original system header
 *                   -  BCM_MIRROR_DEST_OUT_MIRROR_DISABLE is not used in JR2.  Outbound mirroring
 *                       is always disabled for mirrored packets
 * \param [in] mirror_dest_id - Gport representing the command id. gport: BCM_GPORT_MIRROR
 * \param [in] mirror_header_info - system header information
 *
 * \return
 *   \retval Non-zero in case of an error
 *   \retval Zero in case of NO ERROR
 * \remark
 *   * None
 * \see
 *   * None
 */
static shr_error_e
dnx_mirror_header_info_verify(
    int unit,
    uint32 flags,
    bcm_gport_t mirror_dest_id,
    bcm_mirror_header_info_t * mirror_header_info)
{
    int action_profile_id;
    uint8 is_allocated;
    int ii;

    SHR_FUNC_INIT_VARS(unit);

    SHR_NULL_CHECK(mirror_header_info, _SHR_E_PARAM, "mirror_header_info");

    action_profile_id = 0;

    /*
     * verify valid flags
     */
    if (flags & ~(BCM_MIRROR_DEST_IS_SNOOP | BCM_MIRROR_DEST_IS_STAT_SAMPLE |
                  BCM_MIRROR_DEST_EGRESS_ADD_ORIG_SYSTEM_HEADER | BCM_MIRROR_DEST_STAMP_IVE_ACTION_ID))
    {
        SHR_ERR_EXIT(_SHR_E_PARAM, "An unsupported bcm mirror destination flag was specified : 0x%lx",
                     (unsigned long) flags);
    }

    /*
     * verify profile id is in range
     */
    action_profile_id = BCM_GPORT_MIRROR_GET(mirror_dest_id);

    if (action_profile_id > DNX_MIRROR_PROFILE_INGRESS_PROFILE_MAX(unit))
    {
        SHR_ERR_EXIT(_SHR_E_PARAM, "Specified destination ID: %d is out of range", action_profile_id);
    }

    /** check whether the given sniff profile is allocated, if not return an error */
    SHR_IF_ERR_EXIT(dnx_mirror_profile_is_allocated(unit, mirror_dest_id, &is_allocated));
    if (is_allocated == FALSE)
    {
        SHR_ERR_EXIT(_SHR_E_PARAM, "BCM_MIRROR_DEST_REPLACE flag has to be used on existing profiles"
                     "Specified destination profile id ID: %d has not been allocated", action_profile_id);
    }

    if (mirror_header_info->tm.ase_ext.ase_type == bcmPktDnxAseTypeMirrorOnDrop)
    {
        if (dnx_data_ingr_congestion.
            mirror_on_drop.feature_get(unit, dnx_data_ingr_congestion_mirror_on_drop_is_supported) == FALSE)
        {
            SHR_ERR_EXIT(_SHR_E_PARAM, "Mirror on Drop feature is not supported for this device\n");
        }
    }

    if (mirror_header_info->pp.force_mirror && mirror_header_info->pp.eth_header_remove)
    {
        SHR_ERR_EXIT(_SHR_E_PARAM, "eth_header_remove could not be used with force_mirror\n");
    }

    if ((mirror_header_info->udh[0].size > dnx_data_headers.udh.data_type0_size_get(unit))
        || (mirror_header_info->udh[1].size > dnx_data_headers.udh.data_type1_size_get(unit))
        || (mirror_header_info->udh[2].size > dnx_data_headers.udh.data_type2_size_get(unit))
        || (mirror_header_info->udh[3].size > dnx_data_headers.udh.data_type3_size_get(unit)))
    {
        SHR_ERR_EXIT(_SHR_E_PARAM, "UDH size is not valid\n");
    }

    for (ii = 0; ii < (sizeof(mirror_header_info->udh) / sizeof(mirror_header_info->udh[0])); ++ii)
    {
        if ((mirror_header_info->udh[ii].size != 0) &&
            (dnx_data_headers.system_headers.system_headers_mode_get(unit) ==
             DBAL_ENUM_FVAL_SYSTEM_HEADERS_MODE_JERICHO_MODE)
            && !(flags & BCM_MIRROR_DEST_EGRESS_ADD_ORIG_SYSTEM_HEADER))
        {
            SHR_ERR_EXIT(_SHR_E_PARAM, "Device works in Jericho compatible mode but UDH size is not 0\n");
        }
    }

    if (flags & BCM_MIRROR_DEST_STAMP_IVE_ACTION_ID)
    {
        if (dnx_data_headers.system_headers.system_headers_mode_get(unit) ==
            DBAL_ENUM_FVAL_SYSTEM_HEADERS_MODE_JERICHO_MODE)
        {
            SHR_ERR_EXIT(_SHR_E_PARAM, "IVE can't stamp when device works in Jericho compatible mode\n");
        }
        if (mirror_header_info->pp.ingress_vlan_translate_action_id >=
            dnx_data_vlan.vlan_translate.nof_ingress_vlan_edit_action_ids_get(unit))
        {
            SHR_ERR_EXIT(_SHR_E_PARAM, "Illegal IVE action id %u\n",
                         mirror_header_info->pp.ingress_vlan_translate_action_id);
        }
    }

exit:
    SHR_FUNC_EXIT;
}

/**
 * \brief
 *   Set system header information into a known mirror profile.
 *
 * \param [in] unit    -  device unit number.
 * \param [in] flags   - If input flags have BCM_MIRROR_DEST_IS_SNOOP, this means snif command is snoop.
 *                       If input flags have BCM_MIRROR_DEST_IS_STAT_SAMPLE, this means snif command is stat.
 *                       Other input flags mean the snif command is mirror.
 *                       If input flags with BCM_MIRROR_DEST_EGRESS_ADD_ORIG_SYSTEM_HEADER,
 *                       this means keep original system header function will be enabled.
 * \param [in] mirror_dest_id   - Gport representing the command id. gport: BCM_GPORT_MIRROR
 * \param [in] mirror_header_info - system header information.
 *        [in] mirror_header_info.ftmh - Jericho2 or Jericho FTMH system header context according to system headers mode.
 *        [in] mirror_header_info.internal - Jericho2 or Jericho PPH system header context according to system headers mode.
 *
 * \return
 *   \retval Non-zero in case of an error
 *   \retval Zero in case of NO ERROR
 *
 * \remark
 *   The mirror profile should be created by API bcm_mirror_destination_create first. So
 *   that system header function woul work.
 * \see
 *   * None
 */
shr_error_e
bcm_dnx_mirror_header_info_set(
    int unit,
    uint32 flags,
    bcm_gport_t mirror_dest_id,
    bcm_mirror_header_info_t * mirror_header_info)
{
    SHR_FUNC_INIT_VARS(unit);
    DNX_ERR_RECOVERY_START(unit);

    /** Verify flags and ID */
    SHR_INVOKE_VERIFY_DNXC(dnx_mirror_header_info_verify(unit, flags, mirror_dest_id, mirror_header_info));

    /** Allocate(if required) profile and configure system header into HW */
    SHR_IF_ERR_EXIT(dnx_mirror_header_system_header_set(unit, flags, mirror_dest_id, mirror_header_info));

exit:
    DNX_ERR_RECOVERY_END(unit);
    SHR_FUNC_EXIT;
}

/**
 * \brief
 *   Get system header information from a known mirror profile.
 *
 * \param [in] unit       -  device unit number.
 * \param [in] mirror_dest_id   - Gport representing the command id. gport: BCM_GPORT_MIRROR
 * \param [in,out] flags - If input flags have BCM_MIRROR_DEST_IS_SNOOP, this means snif command is snoop.
 *                         If input flags have BCM_MIRROR_DEST_IS_STAT_SAMPLE, this means snif command is stat.
 *                         Other input flags mean the snif command is mirror.
 *                         If out flags with BCM_MIRROR_DEST_EGRESS_ADD_ORIG_SYSTEM_HEADER,
 *                         this means keep original system header function is enabled.
 * \param [out] mirror_header_info - system header information.
 *        [out] mirror_header_info.ftmh - Jericho2 or Jericho FTMH system header context according to system headers mode.
 *        [out] mirror_header_info.internal - Jericho2 or Jericho PPH system header context according to system headers mode.
 *
 * \return
 *   \retval Non-zero in case of an error
 *   \retval Zero in case of NO ERROR
 *
 * \remark
 *   The mirror profile should be created by API bcm_mirror_destination_create first. So
 *   that system header function woul work.
 * \see
 *   * None
 */
shr_error_e
bcm_dnx_mirror_header_info_get(
    int unit,
    bcm_gport_t mirror_dest_id,
    uint32 *flags,
    bcm_mirror_header_info_t * mirror_header_info)
{
    SHR_FUNC_INIT_VARS(unit);
    DNX_ERR_RECOVERY_NOT_NEEDED(unit);

    /** Verify flags and ID */
    SHR_INVOKE_VERIFY_DNXC(dnx_mirror_header_info_verify(unit, *flags, mirror_dest_id, mirror_header_info));

    /** Allocate(if required) profile and configure system header into HW */
    SHR_IF_ERR_EXIT(dnx_mirror_header_system_header_get(unit, mirror_dest_id, flags, mirror_header_info));

exit:
    SHR_FUNC_EXIT;
}

/*
 * See .h file
 */
shr_error_e
dnx_mirror_init(
    int unit)
{
    uint32 entry_handle_id;
    int tm_action_value, tm_action_type;

    SHR_FUNC_INIT_VARS(unit);
    DBAL_FUNC_INIT_VARS(unit);

    /** Init mirror SW state */
    SHR_IF_ERR_EXIT(dnx_mirror_db.init(unit));

    /** Init mirror resource manager */
    SHR_IF_ERR_EXIT(dnx_mirror_profile_res_mngr_init(unit));

    /** Init sniff profile tables */
    SHR_IF_ERR_EXIT(dnx_mirror_profile_tables_init(unit));

    /** Set TM_ACTION_TYPE snif mapping */
    SHR_IF_ERR_EXIT(DBAL_HANDLE_ALLOC(unit, DBAL_TABLE_TM_ACTION_TYPE_TO_SNIF_MAPPING, &entry_handle_id));
    for (tm_action_type = 0; tm_action_type < DBAL_NOF_ENUM_TM_ACTION_TYPE_VALUES; tm_action_type++)
    {
        dbal_entry_key_field32_set(unit, entry_handle_id, DBAL_FIELD_TM_ACTION_TYPE, tm_action_type);
        tm_action_value = (tm_action_type == DBAL_ENUM_FVAL_TM_ACTION_TYPE_FORWARD) ? FALSE : TRUE;
        dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_IS_SNIF, INST_SINGLE, tm_action_value);
        SHR_IF_ERR_EXIT(dbal_entry_commit(unit, entry_handle_id, DBAL_COMMIT));
    }

    if (dnx_data_snif.egress.feature_get(unit, dnx_data_snif_egress_probability_sample))
    {
        SHR_IF_ERR_EXIT(DBAL_HANDLE_CLEAR(unit, DBAL_TABLE_SNIF_EGRESS_INIT_PROBABILITY, entry_handle_id));
        /**
        * Init value for random number generator.
        * Can be any value other than 0.
        */
        dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_MIRROR_INIT_PROBABILITY, INST_SINGLE,
                                     0xFFFFFFFF);
        dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_SNOOP_INIT_PROBABILITY, INST_SINGLE, 0xFFFFFFFF);
        SHR_IF_ERR_EXIT(dbal_entry_commit(unit, entry_handle_id, DBAL_COMMIT));
    }

    /** Egress null profile need to be configured to disable profile */
    if (dnx_data_snif.egress.feature_get(unit, dnx_data_snif_egress_egress_null_profile))
    {
        SHR_IF_ERR_EXIT(DBAL_HANDLE_CLEAR(unit, DBAL_TABLE_SNIF_GENERAL_CONFIG, entry_handle_id));
        dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_EGRESS_MIRROR_ACTION_NULL_PROFILE, INST_SINGLE,
                                     DNX_MIRROR_EGRESS_DISABLE_PROFILE_IDX(unit));
        SHR_IF_ERR_EXIT(dbal_entry_commit(unit, entry_handle_id, DBAL_COMMIT));
    }

    if (dnx_data_snif.egress.feature_get(unit, dnx_data_snif_egress_egress_mirror_mode))
    {
        SHR_IF_ERR_EXIT(DBAL_HANDLE_CLEAR(unit, DBAL_TABLE_SNIF_GENERAL_CONFIG, entry_handle_id));
        /** enable chicken bit */
        dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_EGRESS_MIRROR_MODE, INST_SINGLE, 0);
        SHR_IF_ERR_EXIT(dbal_entry_commit(unit, entry_handle_id, DBAL_COMMIT));
    }

exit:
    DBAL_FUNC_FREE_VARS;
    SHR_FUNC_EXIT;
}

/*
 * See .h file
 */
shr_error_e
dnx_mirror_on_drop_nof_admit_profiles_get(
    int unit,
    int *nof_admit_profiles)
{
    SHR_FUNC_INIT_VARS(unit);

    if (dnx_data_snif.ingress.feature_get(unit, dnx_data_snif_ingress_mirror_on_drop_admit_profile_supported))
    {
        *nof_admit_profiles = BCM_MIRROR_ADMIT_PROFILES_NOF;
    }
    else
    {
        *nof_admit_profiles = 1;
    }

    SHR_FUNC_EXIT;
}

/**
 * \brief - verify function of bcm_dnx_mirror_port_info_get()
 *
 * \par DIRECT_INPUT:
 *   \param [in] unit -
 *  Relevant unit.
 *   \param [in] port -
 *  Port - mirror recycling port
 *   \param [in] flags -
 *  not used
 * \par INDIRECT INPUT:
 *     \param [in] info -
 * \par DIRECT OUTPUT:
 *   shr_error_e
 * \par INDIRECT OUTPUT
     None
 * \remark
     None
 * \see
     None
 */
static int
dnx_mirror_port_info_get_verify(
    int unit,
    bcm_port_t port,
    uint32 flags,
    bcm_mirror_port_info_t * info)
{
    bcm_port_t local_port;
    SHR_FUNC_INIT_VARS(unit);

    /** Verify logical port */
    local_port = (BCM_GPORT_IS_LOCAL(port)) ? BCM_GPORT_LOCAL_GET(port) : port;
    SHR_IF_ERR_EXIT(dnx_algo_port_valid_verify(unit, local_port));

    SHR_NULL_CHECK(info, _SHR_E_PARAM, "info");

exit:
    SHR_FUNC_EXIT;
}

/**
 * \brief - Get system port gport for mirror recycling port
 *
 * \par DIRECT_INPUT:
 *   \param [in] unit -
 *  Relevant unit.
 *   \param [in] port -
 *  Port - mirror recycling port
 *   \param [in] flags -
 *  not used
 * \par INDIRECT INPUT:
 * \par DIRECT OUTPUT:
 *   shr_error_e
 * \par INDIRECT OUTPUT
 *     \param [out] info -
 *  returns system port gport in info
 * \remark
     None
 * \see
     None
 */
int
bcm_dnx_mirror_port_info_get(
    int unit,
    bcm_port_t port,
    uint32 flags,
    bcm_mirror_port_info_t * info)
{
    bcm_port_t local_port;
    uint32 ptc;
    bcm_core_t core_id;
    uint32 sysport_id;
    uint32 entry_handle_id;

    SHR_FUNC_INIT_VARS(unit);
    DNX_ERR_RECOVERY_NOT_NEEDED(unit);
    DBAL_FUNC_INIT_VARS(unit);

    /** Verify */
    SHR_INVOKE_VERIFY_DNXC(dnx_mirror_port_info_get_verify(unit, port, flags, info));

    /** Verify logical port */
    local_port = (BCM_GPORT_IS_LOCAL(port)) ? BCM_GPORT_LOCAL_GET(port) : port;
    SHR_IF_ERR_EXIT(dnx_algo_port_valid_verify(unit, local_port));

    SHR_IF_ERR_EXIT(dnx_port_ptc_get(unit, local_port, &ptc, &core_id));

    SHR_IF_ERR_EXIT(DBAL_HANDLE_ALLOC(unit, DBAL_TABLE_INGRESS_PTC_PORT, &entry_handle_id));
    dbal_entry_key_field32_set(unit, entry_handle_id, DBAL_FIELD_CORE_ID, core_id);
    dbal_entry_key_field32_set(unit, entry_handle_id, DBAL_FIELD_PTC, ptc);
    dbal_value_field32_request(unit, entry_handle_id, DBAL_FIELD_SOURCE_SYSTEM_PORT, INST_SINGLE, &sysport_id);
    SHR_IF_ERR_EXIT(dbal_entry_get(unit, entry_handle_id, DBAL_COMMIT));

    BCM_GPORT_SYSTEM_PORT_ID_SET(info->mirror_system_id, sysport_id);

exit:
    DBAL_FUNC_FREE_VARS;
    SHR_FUNC_EXIT;
}

/**
 * \brief - verify function of bcm_dnx_mirror_port_info_set()
 *
 * \par DIRECT_INPUT:
 *     \param [in] unit -
 *    Relevant unit.
 *     \param [in] port -
 *    Port - mirror recycling port
 *     \param [in] flags -
 *    not used
 * \par INDIRECT INPUT:
 *     \param [in] info -
 * \par DIRECT OUTPUT:
 *     shr_error_e
 * \par INDIRECT OUTPUT
     None
 * \remark
     None
 * \see
     None
 */
static int
dnx_mirror_port_info_set_verify(
    int unit,
    bcm_port_t port,
    uint32 flags,
    bcm_mirror_port_info_t * info)
{
    bcm_port_t port_local;
    bcm_gport_t gport;
    uint32 sysport_id;
    SHR_FUNC_INIT_VARS(unit);

    /** Verify logical port */
    port_local = (BCM_GPORT_IS_LOCAL(port)) ? BCM_GPORT_LOCAL_GET(port) : port;
    SHR_IF_ERR_EXIT(dnx_algo_port_valid_verify(unit, port_local));

    SHR_NULL_CHECK(info, _SHR_E_PARAM, "info");

    gport = info->mirror_system_id;
    sysport_id = (BCM_GPORT_IS_SYSTEM_PORT(gport)) ? BCM_GPORT_SYSTEM_PORT_ID_GET(gport) : gport;

    if (sysport_id > dnx_data_device.general.max_nof_system_ports_get(unit))
    {
        SHR_ERR_EXIT(_SHR_E_PARAM, "system port (%u) is out of range, range is 0 - %d", sysport_id,
                     dnx_data_device.general.invalid_system_port_get(unit));
    }

exit:
    SHR_FUNC_EXIT;
}

/**
 * \brief - Set system port gport for mirror recycling port
 *
 * \par DIRECT_INPUT:
 *     \param [in] unit -
 *    Relevant unit.
 *     \param [in] port -
 *    mirror recycling local port
 *     \param [in] flags -
 *    not used
 * \par INDIRECT INPUT:
 *     \param [in] info -
 *    system port gport for mirror recycling port
 * \par DIRECT OUTPUT:
 *     shr_error_e
 * \par INDIRECT OUTPUT
     None
 * \remark
     None
 * \see
     None
 */
int
bcm_dnx_mirror_port_info_set(
    int unit,
    bcm_port_t port,
    uint32 flags,
    bcm_mirror_port_info_t * info)
{
    bcm_port_t port_local;
    uint32 ptc;
    bcm_core_t core_id;
    uint32 entry_handle_id;
    bcm_gport_t gport;
    uint32 sysport_id;

    SHR_FUNC_INIT_VARS(unit);
    DBAL_FUNC_INIT_VARS(unit);
    DNX_ERR_RECOVERY_START(unit);

    SHR_NULL_CHECK(info, _SHR_E_PARAM, "info");

    /** Verify */
    SHR_INVOKE_VERIFY_DNXC(dnx_mirror_port_info_set_verify(unit, port, flags, info));

    port_local = (BCM_GPORT_IS_LOCAL(port)) ? BCM_GPORT_LOCAL_GET(port) : port;
    gport = info->mirror_system_id;
    sysport_id = (BCM_GPORT_IS_SYSTEM_PORT(gport)) ? BCM_GPORT_SYSTEM_PORT_ID_GET(gport) : gport;

    SHR_IF_ERR_EXIT(dnx_port_ptc_get(unit, port_local, &ptc, &core_id));

    SHR_IF_ERR_EXIT(DBAL_HANDLE_ALLOC(unit, DBAL_TABLE_INGRESS_PTC_PORT, &entry_handle_id));
    dbal_entry_key_field32_set(unit, entry_handle_id, DBAL_FIELD_CORE_ID, core_id);
    dbal_entry_key_field32_set(unit, entry_handle_id, DBAL_FIELD_PTC, ptc);
    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_SOURCE_SYSTEM_PORT, INST_SINGLE, sysport_id);
    SHR_IF_ERR_EXIT(dbal_entry_commit(unit, entry_handle_id, DBAL_COMMIT));

exit:
    DNX_ERR_RECOVERY_END(unit);
    DBAL_FUNC_FREE_VARS;
    SHR_FUNC_EXIT;
}
