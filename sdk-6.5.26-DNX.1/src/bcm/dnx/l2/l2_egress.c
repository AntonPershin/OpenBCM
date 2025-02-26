/** \file l2_egress.c
 * 
 *
 * L2 procedures for DNX.
 *
 * This file contains functions for managing l2 egress APIs.
 */
/*
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2022 Broadcom Inc. All rights reserved.
 */
#ifdef BSL_LOG_MODULE
#error "BSL_LOG_MODULE redefined"
#endif
#define BSL_LOG_MODULE BSL_LS_BCMDNX_L2
/*
 * Include files which are specifically for DNX. Final location.
 * {
 */
#include <soc/sand/shrextend/shrextend_debug.h>
#include <soc/dnx/dnx_err_recovery_manager.h>
/*
 * }
 */
/*
 * Include files currently used for DNX. To be modified and moved to
 * final location.
 * {
 */
#include <soc/dnx/dbal/dbal.h>
#include <soc/dnx/mdb.h>
#include <soc/dnx/dnx_data/auto_generated/dnx_data_l2.h>
#include <soc/dnx/dnx_data/auto_generated/dnx_data_flow.h>
#include <soc/dnx/dnx_data/auto_generated/dnx_data_headers.h>
/*
 * }
 */
/*
 * Include files.
 * {
 */
#include <bcm_int/dnx/algo/algo_gpm.h>
#include <bcm_int/dnx/lif/lif_lib.h>
#include <bcm/types.h>
#include <bcm/l2.h>
#include <bcm_int/dnx/vlan/vlan.h>
#include <bcm_int/dnx/algo/lif_mngr/lif_mngr.h>
#include "src/bcm/dnx/flow/porting/rch_flow.h"
/*
 * }
 */

/*
 * Defines
 * {
 */

/*
 * }
 */

/**
 * \brief
 * Translate rcycle app to etpp forward code to write on RCY outlif entry
 */
static shr_error_e
dnx_l2_egress_recycle_app_to_forward_code_translate(
    int unit,
    bcm_l2_egress_recycle_app_t recycle_app,
    uint32 *fwd_code)
{
    SHR_FUNC_INIT_VARS(unit);
    SHR_NULL_CHECK(fwd_code, _SHR_E_PARAM, "fwd_code");

    switch (recycle_app)
    {
        case bcmL2EgressRecycleAppDropAndContinue:
            *fwd_code = DBAL_ENUM_FVAL_EGRESS_FWD_CODE_RCH_DROP_AND_CONT;
            break;
        case bcmL2EgressRecycleAppExtendedEncap:
            *fwd_code = DBAL_ENUM_FVAL_EGRESS_FWD_CODE_RCH_EXT_ENCAP;
            break;
        case bcmL2EgressRecycleAppExtendedTerm:
            *fwd_code = DBAL_ENUM_FVAL_EGRESS_FWD_CODE_RCH_XTERMINATION;
            break;
        case bcmL2EgressRecycleAppRedirectVrf:
            *fwd_code = DBAL_ENUM_FVAL_EGRESS_FWD_CODE_RCH_VRF_REDIRECT;
            break;
        case bcmL2EgressRecycleAppSrv6UspPsp:
            *fwd_code = DBAL_ENUM_FVAL_EGRESS_FWD_CODE_RCH_SRV6_USP_PSP;
            break;
        default:
            SHR_ERR_EXIT(_SHR_E_INTERNAL, "Unknown RCY app %d\n", recycle_app);
            break;
    }

exit:
    SHR_FUNC_EXIT;
}

/**
 * \brief
 * Translate etpp forward code that is written on RCY outlif entry to rcycle app
 */
static shr_error_e
dnx_l2_egress_forward_code_to_recycle_app_translate(
    int unit,
    uint32 fwd_code,
    bcm_l2_egress_recycle_app_t * recycle_app)
{
    SHR_FUNC_INIT_VARS(unit);
    SHR_NULL_CHECK(recycle_app, _SHR_E_PARAM, "recycle_app");

    switch (fwd_code)
    {
        case DBAL_ENUM_FVAL_EGRESS_FWD_CODE_RCH_DROP_AND_CONT:
            *recycle_app = bcmL2EgressRecycleAppDropAndContinue;
            break;
        case DBAL_ENUM_FVAL_EGRESS_FWD_CODE_RCH_EXT_ENCAP:
            *recycle_app = bcmL2EgressRecycleAppExtendedEncap;
            break;
        case DBAL_ENUM_FVAL_EGRESS_FWD_CODE_RCH_XTERMINATION:
            *recycle_app = bcmL2EgressRecycleAppExtendedTerm;
            break;
        case DBAL_ENUM_FVAL_EGRESS_FWD_CODE_RCH_VRF_REDIRECT:
            *recycle_app = bcmL2EgressRecycleAppRedirectVrf;
            break;
        case DBAL_ENUM_FVAL_EGRESS_FWD_CODE_RCH_SRV6_USP_PSP:
            *recycle_app = bcmL2EgressRecycleAppSrv6UspPsp;
            break;
        default:
            SHR_ERR_EXIT(_SHR_E_INTERNAL, "fwd_code %d is not a RCY forward code\n", fwd_code);
            break;
    }

exit:
    SHR_FUNC_EXIT;
}

/**
 * \brief
 * Verify l2 egress parameters for BCM-API: bcm_dnx_l2_egress_create().
 * check the supported flags
 */
static shr_error_e
dnx_l2_egress_create_verify(
    int unit,
    bcm_l2_egress_t * egr)
{
    uint32 supported_flags, header_flags;
    uint8 no_black_hole_for_unknown_destination =
        dnx_data_l2.feature.feature_get(unit, dnx_data_l2_feature_no_black_hole_for_unknown_destination);

    SHR_FUNC_INIT_VARS(unit);
    SHR_NULL_CHECK(egr, _SHR_E_PARAM, "egr");
    supported_flags =
        BCM_L2_EGRESS_WITH_ID | BCM_L2_EGRESS_REPLACE | BCM_L2_EGRESS_RECYCLE_HEADER |
        BCM_L2_EGRESS_DEST_PORT | BCM_L2_EGRESS_EXTENDED_COPY_DEST_ENCAP;
    if (dnx_data_headers.
        system_headers.feature_get(unit, dnx_data_headers_system_headers_system_headers_ibch1_supported))
    {
        supported_flags |= BCM_L2_EGRESS_PORT_INJECTION_MAP;
    }
    /** Check if the set flags are supported*/
    if (egr->flags & ~supported_flags)
    {
        SHR_ERR_EXIT(_SHR_E_UNAVAIL, "The used flag = 0x%08X is not in the range of supported ones", egr->flags);
    }
    /** Verify WITH_ID and REPLACE flags */
    if (_SHR_IS_FLAG_SET(egr->flags, BCM_L2_EGRESS_REPLACE) && !_SHR_IS_FLAG_SET(egr->flags, BCM_L2_EGRESS_WITH_ID))
    {
        SHR_ERR_EXIT(_SHR_E_PARAM, "BCM_L2_EGRESS_REPLACE can't be used without BCM_L2_EGRESS_WITH_ID");
    }

    if ((_SHR_IS_FLAG_SET(egr->flags, BCM_L2_EGRESS_DEST_PORT))
        && (egr->recycle_app != bcmL2EgressRecycleAppExtendedEncap))
    {
        SHR_ERR_EXIT(_SHR_E_PARAM,
                     "BCM_L2_EGRESS_DEST_PORT can be used only for recycle_app bcmL2EgressRecycleAppExtendedEncap!");
    }

    if ((_SHR_IS_FLAG_SET(egr->flags, BCM_L2_EGRESS_EXTENDED_COPY_DEST_ENCAP))
        && (egr->recycle_app != bcmL2EgressRecycleAppExtendedEncap))
    {
        SHR_ERR_EXIT(_SHR_E_PARAM,
                     "BCM_L2_EGRESS_EXTENDED_COPY_DEST_ENCAP can be used only for recycle_app bcmL2EgressRecycleAppExtendedEncap!");
    }

    if (egr->dest_encap_id != 0)
    {
        SHR_ERR_EXIT(_SHR_E_PARAM, "egr->dest_encap_id should be 0!");
    }

    if (!_SHR_IS_FLAG_SET(egr->flags, BCM_L2_EGRESS_DEST_PORT) && (egr->dest_port != 0))
    {
        SHR_ERR_EXIT(_SHR_E_PARAM, "egr->dest_port!=0 should be 0 when BCM_L2_EGRESS_DEST_PORT is not set!");
    }
    /** Check if black hole is a valid destination */
    if ((no_black_hole_for_unknown_destination) && BCM_GPORT_IS_BLACK_HOLE(egr->dest_port))
    {
        SHR_ERR_EXIT(_SHR_E_PARAM, "Black hole is not a valid gport destination!\n");
    }
    /** unsupported fields */
    if (egr->outer_tpid != 0)
    {
        SHR_ERR_EXIT(_SHR_E_UNAVAIL, "outer_tpid field is not supported");
    }
    if (!BCM_MAC_IS_ZERO(egr->dest_mac))
    {
        SHR_ERR_EXIT(_SHR_E_UNAVAIL, "dest_mac field is not supported");
    }
    if (!BCM_MAC_IS_ZERO(egr->src_mac))
    {
        SHR_ERR_EXIT(_SHR_E_UNAVAIL, "src_mac field is not supported");
    }
    if (egr->outer_vlan != 0)
    {
        SHR_ERR_EXIT(_SHR_E_UNAVAIL, "outer_vlan field is not supported");
    }
    if (egr->inner_vlan != 0)
    {
        SHR_ERR_EXIT(_SHR_E_UNAVAIL, "inner_vlan field is not supported");
    }
    if (egr->outer_prio != 0)
    {
        SHR_ERR_EXIT(_SHR_E_UNAVAIL, "outer_prio field is not supported");
    }
    if (egr->inner_tpid != 0)
    {
        SHR_ERR_EXIT(_SHR_E_UNAVAIL, "inner_tpid field is not supported");
    }
    if (egr->l3_intf != 0)
    {
        SHR_ERR_EXIT(_SHR_E_UNAVAIL, "l3_intf field is not supported");
    }
    if (egr->vlan_qos_map_id != 0)
    {
        SHR_ERR_EXIT(_SHR_E_UNAVAIL, "vlan_qos_map_id field is not supported");
    }
    if (egr->mpls_extended_label_value != 0)
    {
        SHR_ERR_EXIT(_SHR_E_UNAVAIL, "mpls_extended_label_value field is not supported");
    }
    if (egr->recycle_app >= bcmL2EgressRecycleAppCount || (int) (egr->recycle_app) < 0)
    {
        SHR_ERR_EXIT(_SHR_E_PARAM, "Recycle_App is invalid, must be in range 0-%d\n", bcmL2EgressRecycleAppCount - 1);
    }
    if (egr->recycle_app == bcmL2EgressRecycleAppReflector)
    {
        SHR_ERR_EXIT(_SHR_E_PARAM, "Recycle_App bcmL2EgressRecycleAppReflector is invalid");
    }
    if (egr->vlan_port_id != 0 && !BCM_GPORT_IS_VLAN_PORT(egr->vlan_port_id))
    {
        SHR_ERR_EXIT(_SHR_E_PARAM, "vlan_port_id is expected to be a vlan port gport");
    }
    if (egr->ethertype != 0)
    {
        SHR_ERR_EXIT(_SHR_E_UNAVAIL, "ethertype field is not supported");
    }
    if (egr->recycle_header_extension_length != 0)
    {
        if (egr->recycle_header_extension_length > dnx_data_l2.general.l2_egress_max_extention_size_bytes_get(unit))
        {
            SHR_ERR_EXIT(_SHR_E_PARAM, "recycle_header_extension_length is limited to %d Bytes",
                         dnx_data_l2.general.l2_egress_max_extention_size_bytes_get(unit));
        }
        if (egr->recycle_app != bcmL2EgressRecycleAppExtendedTerm)
        {
            SHR_ERR_EXIT(_SHR_E_PARAM, "recycle_header_extension_length can be set only with Ext. termination flow");
        }
    }

    if (egr->additional_egress_termination_size != 0)
    {
        if (egr->additional_egress_termination_size >
            dnx_data_l2.general.l2_egress_max_additional_termination_size_bytes_get(unit))
        {
            SHR_ERR_EXIT(_SHR_E_PARAM, "additional_egress_termination_size is limited to %d Bytes in this device",
                         dnx_data_l2.general.l2_egress_max_additional_termination_size_bytes_get(unit));
        }
        if (egr->recycle_app != bcmL2EgressRecycleAppExtendedTerm)
        {
            SHR_ERR_EXIT(_SHR_E_PARAM, "recycle_header_extension_length can be set only with Ext. termination flow");
        }
    }

    if ((egr->vrf > 0) && (egr->recycle_app != bcmL2EgressRecycleAppRedirectVrf))
    {
        SHR_ERR_EXIT(_SHR_E_PARAM, "vrf can be set only with vrf redirect flow");
    }

    if (egr->recycle_app == bcmL2EgressRecycleAppRedirectVrf)
    {
        if ((egr->vrf < 0) || (egr->vrf >= dnx_data_l3.vrf.nof_vrf_get(unit)))
        {
            SHR_ERR_EXIT(_SHR_E_PARAM, "VRF %d is out of range, should be equal to or bigger than 0 and lower than %d.",
                         egr->vrf, dnx_data_l3.vrf.nof_vrf_get(unit));
        }
    }
    /**egress qos model*/
    if (egr->egress_qos_model.egress_ttl != bcmQosEgressModelUniform)
    {
        SHR_ERR_EXIT(_SHR_E_PARAM, "L2 egress ttl model only support uniform");
    }
    if (egr->egress_qos_model.egress_ecn != bcmQosEgressEcnModelInvalid)
    {
        SHR_ERR_EXIT(_SHR_E_PARAM, "L2 egress does not support ecn");
    }
    if ((egr->recycle_app != bcmL2EgressRecycleAppExtendedEncap) &&
        (egr->egress_qos_model.egress_qos != bcmQosEgressModelInitial))
    {
        SHR_ERR_EXIT(_SHR_E_PARAM, "only extend encap support egress qos model configuration");
    }
    if ((egr->egress_qos_model.egress_qos != bcmQosEgressModelInitial)
        && (egr->egress_qos_model.egress_qos != bcmQosEgressModelUniform))
    {
        SHR_ERR_EXIT(_SHR_E_PARAM, "L2 egress qos model only support uniform or initial");
    }

    /** Verify the Header flags is set */
    header_flags = BCM_L2_EGRESS_RECYCLE_HEADER;
    SHR_NOF_SET_BITS_IN_RANGE_VERIFY(egr->flags, header_flags, 1, 1,
                                     _SHR_E_PARAM, "Either BCM_L2_EGRESS_RECYCLE_HEADER must be set");

    /** encap stage */
    if ((egr->encap_access != bcmEncapAccessInvalid) &&
        (egr->encap_access != bcmEncapAccessAc) && (egr->encap_access != bcmEncapAccessArp))
    {
        SHR_ERR_EXIT(_SHR_E_PARAM,
                     "egr->encap_access (%d) is invalid, supported values are bcmEncapAccessInvalid, bcmEncapAccessAc, bcmEncapAccessArp",
                     egr->encap_access);
    }

exit:
    SHR_FUNC_EXIT;
}

/**
* \brief -
* Verify function for BCM-API: bcm_dnx_l2_egress_get()
*
* \param [in] unit - relevant unit.
* \param [in] encap_id - Encapsulation index
* \param [in] egr - Pointer to information about
*                   device-independent L2 egress structure.
*
* \return
*   shr_error_e
*
* \remark
*   * None
* \see
* bcm_dnx_l2_egress_get
*/
static shr_error_e
dnx_l2_egress_get_verify(
    int unit,
    bcm_if_t encap_id,
    bcm_l2_egress_t * egr)
{
    SHR_FUNC_INIT_VARS(unit);
    SHR_NULL_CHECK(egr, _SHR_E_PARAM, "egr");

   /** check encap id is an interface of type lif */
    if (!BCM_L3_ITF_TYPE_IS_LIF(encap_id))
    {
        SHR_ERR_EXIT(_SHR_E_PARAM, "bcm_dnx_l2_egress_get is supported only with encap_id of type lif\n");
    }

exit:
    SHR_FUNC_EXIT;
}

/**
* \brief -
* Verify function for BCM-API: bcm_dnx_l2_egress_destroy()
*
* \param [in] unit - relevant unit.
* \param [in] encap_id - Encapsulation index to delete
*
* \return
*   shr_error_e
*
* \remark
*   * None
* \see
* bcm_dnx_l2_egress_destroy
*/
static shr_error_e
dnx_l2_egress_destroy_verify(
    int unit,
    bcm_if_t encap_id)
{
    SHR_FUNC_INIT_VARS(unit);

   /** check encap id is an interface of type lif */
    if (!BCM_L3_ITF_TYPE_IS_LIF(encap_id))
    {
        SHR_ERR_EXIT(_SHR_E_PARAM, "bcm_dnx_l2_egress_destroy is supported only with encap_id of type lif\n");
    }

exit:
    SHR_FUNC_EXIT;
}

/**
 * \brief
 * Write to L2 egress entry out-LIF table.
 *
 *   \param [in] unit - Relevant unit.
 *   \param [in] egr - A pointer to the struct that holds
 *     information for the L2 egress encapsulation entry
 *   \param [in] table_result_type- relevant result type of the table
 *   \param [in] local_outlif -
 *     Local-Out-LIF whose entry should be added to out-LIF table.
 */
static shr_error_e
dnx_l2_egress_table_set(
    int unit,
    bcm_l2_egress_t * egr,
    int table_result_type,
    uint32 local_outlif)
{
    uint32 entry_handle_id;
    uint32 fwd_code;
    uint32 control_lif;
    uint32 destination;

    SHR_FUNC_INIT_VARS(unit);
    DBAL_FUNC_INIT_VARS(unit);
    SHR_NULL_CHECK(egr, _SHR_E_PARAM, "egr");

    /** Take DBAL handle */
    SHR_IF_ERR_EXIT(DBAL_HANDLE_ALLOC(unit, DBAL_TABLE_EEDB_RCH, &entry_handle_id));

    /** Set KEY field */
    dbal_entry_key_field32_set(unit, entry_handle_id, DBAL_FIELD_OUT_LIF, local_outlif);

    /** Set DATA fields */
    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_RESULT_TYPE, INST_SINGLE, table_result_type);

    SHR_IF_ERR_EXIT(dnx_l2_egress_recycle_app_to_forward_code_translate(unit, egr->recycle_app, &fwd_code));

    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_FWD_CODE, INST_SINGLE, fwd_code);

    /** control lif.
     *  if not filled by user, use default value */
    if (egr->vlan_port_id != 0)
    {
        dnx_algo_gpm_gport_hw_resources_t gport_hw_resources;
        int flags = DNX_ALGO_GPM_GPORT_HW_RESOURCES_LOCAL_LIF_INGRESS;
        sal_memset(&gport_hw_resources, 0, sizeof(dnx_algo_gpm_gport_hw_resources_t));
        SHR_IF_ERR_REPLACE_AND_EXIT(dnx_algo_gpm_gport_to_hw_resources
                                    (unit, egr->vlan_port_id, flags, &gport_hw_resources), _SHR_E_NOT_FOUND,
                                    _SHR_E_PARAM);
        control_lif = gport_hw_resources.local_in_lif;
    }
    else
    {
        /** use recycle default lif */
        SHR_IF_ERR_EXIT(dnx_vlan_port_ingress_default_recyle_lif_get(unit, FALSE, &control_lif));
    }

    /**qos model default is initial, so that copy nwk_qos from pph */
    if (egr->egress_qos_model.egress_qos == bcmQosEgressModelUniform)
    {
        dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_RCH_QOS_MODEL, INST_SINGLE,
                                     DBAL_ENUM_FVAL_RCH_QOS_MODEL_UNIFORM);
    }
    else
    {
        dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_RCH_QOS_MODEL, INST_SINGLE,
                                     DBAL_ENUM_FVAL_RCH_QOS_MODEL_INITIAL);
    }

    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_EXT_TERM_OFFSET, INST_SINGLE,
                                 egr->recycle_header_extension_length);
    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_BTS_ADDITIONAL_TERMINATION_SIZE, INST_SINGLE,
                                 egr->additional_egress_termination_size);
    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_CONTROL_LIF, INST_SINGLE, control_lif);

    if (_SHR_IS_FLAG_SET(egr->flags, BCM_L2_EGRESS_DEST_PORT))
    {
        /** Resolve forward information from egr->dest_port */
        SHR_IF_ERR_EXIT(algo_gpm_encode_destination_field_from_gport
                        (unit, ALGO_GPM_ENCODE_DESTINATION_FLAGS_NONE, egr->dest_port, &destination));
        dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_DESTINATION, INST_SINGLE, destination);
        dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_SERVICE_TYPE_IS_P2P, INST_SINGLE, TRUE);
    }
    else
    {
        dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_SERVICE_TYPE_IS_P2P, INST_SINGLE, FALSE);
    }

    if (_SHR_IS_FLAG_SET(egr->flags, BCM_L2_EGRESS_EXTENDED_COPY_DEST_ENCAP))
    {
        dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_OUTLIF_0_PUSHED_TO_STACK, INST_SINGLE, 1);
    }

    if (egr->recycle_app == bcmL2EgressRecycleAppRedirectVrf)
    {
        dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_GLOB_IN_LIF, INST_SINGLE, egr->vrf);
    }
    /** Write to HW */
    SHR_IF_ERR_EXIT(dbal_entry_commit(unit, entry_handle_id, DBAL_COMMIT));

exit:
    DBAL_FUNC_FREE_VARS;
    SHR_FUNC_EXIT;
}

/**
 * \brief
 * Reset given entry from L2 egress out-LIF table.
 *
 *   \param [in] unit - Relevant unit.
 *   \param [in] local_outlif -
 *     Local-Out-LIF whose entry should be reset.
 *   \param [in] result_type - result type associated with local lif
 */
static shr_error_e
dnx_l2_egress_table_clear(
    int unit,
    uint32 local_outlif,
    uint32 result_type)
{
    uint32 entry_handle_id;

    SHR_FUNC_INIT_VARS(unit);
    DBAL_FUNC_INIT_VARS(unit);

    /** Taking a handle */
    SHR_IF_ERR_EXIT(DBAL_HANDLE_ALLOC(unit, DBAL_TABLE_EEDB_RCH, &entry_handle_id));

    /** Setting key fields -- DBAL_RESULT_TYPE_EEDB_RCH_ETPS_RCHv2 */
    dbal_entry_key_field32_set(unit, entry_handle_id, DBAL_FIELD_OUT_LIF, local_outlif);

    /** Setting result type */
    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_RESULT_TYPE, INST_SINGLE, result_type);

    /** clearing the entry */
    SHR_IF_ERR_EXIT(dbal_entry_clear(unit, entry_handle_id, DBAL_COMMIT));

exit:
    DBAL_FUNC_FREE_VARS;
    SHR_FUNC_EXIT;
}

/**
 * \brief
 * Read from L2 egress entry out-LIF table.
 *
 *   \param [in] unit - Relevant unit.
 *   \param [out] egr - A pointer to the struct that holds
 *     information for the L2 egress encapsulation entry
 *   \param [in] local_outlif -
 *     Local-Out-LIF whose entry should be returned.
 *   \param [in] result_type - result type associated with local lif
 */
static shr_error_e
dnx_l2_egress_table_get(
    int unit,
    bcm_l2_egress_t * egr,
    uint32 local_outlif,
    uint32 result_type)
{
    uint32 entry_handle_id;
    uint32 fwd_code;
    uint32 control_lif;
    uint32 qos_model;
    uint32 recycle_default_lif;
    uint32 extended_termination_offset;
    uint32 additional_egress_termination_size;
    int flags;
    uint32 destination;

    SHR_FUNC_INIT_VARS(unit);
    DBAL_FUNC_INIT_VARS(unit);
    SHR_NULL_CHECK(egr, _SHR_E_PARAM, "egr");

    /** Taking a handle */
    SHR_IF_ERR_EXIT(DBAL_HANDLE_ALLOC(unit, DBAL_TABLE_EEDB_RCH, &entry_handle_id));

    /** Setting key fields -- DBAL_RESULT_TYPE_EEDB_RCH_ETPS_RCHv2 */
    dbal_entry_key_field32_set(unit, entry_handle_id, DBAL_FIELD_OUT_LIF, local_outlif);

    /** Setting result type */
    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_RESULT_TYPE, INST_SINGLE, result_type);
    SHR_IF_ERR_EXIT(dbal_entry_get(unit, entry_handle_id, DBAL_GET_ALL_FIELDS));

    /**
     * Get egress encapsulation data from dbal table
     */

    SHR_IF_ERR_EXIT(dbal_entry_handle_value_field32_get
                    (unit, entry_handle_id, DBAL_FIELD_FWD_CODE, INST_SINGLE, &fwd_code));

    SHR_IF_ERR_EXIT(dnx_l2_egress_forward_code_to_recycle_app_translate(unit, fwd_code, &egr->recycle_app));
    egr->flags |= BCM_L2_EGRESS_RECYCLE_HEADER;

    SHR_IF_ERR_EXIT(dbal_entry_handle_value_field32_get
                    (unit, entry_handle_id, DBAL_FIELD_CONTROL_LIF, INST_SINGLE, &control_lif));

    SHR_IF_ERR_EXIT(dbal_entry_handle_value_field32_get
                    (unit, entry_handle_id, DBAL_FIELD_RCH_QOS_MODEL, INST_SINGLE, &qos_model));

    SHR_IF_ERR_EXIT(dbal_entry_handle_value_field32_get
                    (unit, entry_handle_id, DBAL_FIELD_EXT_TERM_OFFSET, INST_SINGLE, &extended_termination_offset));
    egr->recycle_header_extension_length = extended_termination_offset;

    SHR_IF_ERR_EXIT(dbal_entry_handle_value_field32_get
                    (unit, entry_handle_id, DBAL_FIELD_BTS_ADDITIONAL_TERMINATION_SIZE, INST_SINGLE,
                     &additional_egress_termination_size));
    egr->additional_egress_termination_size = additional_egress_termination_size;

    if (egr->recycle_app == bcmL2EgressRecycleAppExtendedEncap)
    {
        uint32 outlif_0_push_to_stack = 0;
        SHR_IF_ERR_EXIT(dbal_entry_handle_value_field32_get
                        (unit, entry_handle_id, DBAL_FIELD_DESTINATION, INST_SINGLE, &destination));
        if (destination != 0)
        {
            egr->flags |= BCM_L2_EGRESS_DEST_PORT;
        }
        /** Get egr->dest_port from destination */
        SHR_IF_ERR_EXIT(algo_gpm_gport_from_encoded_destination_field
                        (unit, ALGO_GPM_ENCODE_DESTINATION_FLAGS_NONE, destination, &egr->dest_port));

        SHR_IF_ERR_EXIT(dbal_entry_handle_value_field32_get
                        (unit, entry_handle_id, DBAL_FIELD_OUTLIF_0_PUSHED_TO_STACK, INST_SINGLE,
                         &outlif_0_push_to_stack));
        if (outlif_0_push_to_stack != 0)
        {
            egr->flags |= BCM_L2_EGRESS_EXTENDED_COPY_DEST_ENCAP;
        }

        if (_SHR_IS_FLAG_SET(egr->flags, BCM_L2_EGRESS_EXTENDED_COPY_DEST_ENCAP))
        {
            dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_OUTLIF_0_PUSHED_TO_STACK, INST_SINGLE, 1);
        }

    }

    /*
     * return to the user the control lif, only if it's not the
     * default lif
     */
    SHR_IF_ERR_EXIT(dnx_vlan_port_ingress_default_recyle_lif_get(unit, FALSE, &recycle_default_lif));

    if (control_lif != recycle_default_lif)
    {
        dnx_algo_gpm_gport_hw_resources_t gport_hw_resources;
        sal_memset(&gport_hw_resources, 0, sizeof(dnx_algo_gpm_gport_hw_resources_t));
        flags = DNX_ALGO_GPM_GPORT_HW_RESOURCES_SBC_LOCAL_LIF_INGRESS;
        SHR_IF_ERR_EXIT_EXCEPT_IF(dnx_algo_gpm_gport_from_lif
                                  (unit, flags, _SHR_CORE_ALL, (int) control_lif, &egr->vlan_port_id),
                                  _SHR_E_NOT_FOUND);
    }

    if (qos_model == DBAL_ENUM_FVAL_RCH_QOS_MODEL_UNIFORM)
    {
        egr->egress_qos_model.egress_qos = bcmQosEgressModelUniform;
    }
    else
    {
        egr->egress_qos_model.egress_qos = bcmQosEgressModelInitial;
    }

    if (egr->recycle_app == bcmL2EgressRecycleAppRedirectVrf)
    {
        SHR_IF_ERR_EXIT(dbal_entry_handle_value_field32_get
                        (unit, entry_handle_id, DBAL_FIELD_GLOB_IN_LIF, INST_SINGLE, (uint32 *) &egr->vrf));
    }

exit:
    DBAL_FUNC_FREE_VARS;
    SHR_FUNC_EXIT;
}

/**
 * \brief - The API creates and configures recycle header.
 *
 * \param [in] unit - Relevant unit
 * \param [in] egr - A pointer to the structure, holding information about the recycle header entry.
 *                 * egr -> encap_id - l3_intf: recycle encapsulation ID
 *                 * egr -> flags - Supported flags are: BCM_L2_EGRESS_WITH_ID, BCM_L2_EGRESS_REPLACE, BCM_L2_EGRESS_RECYCLE_HEADER.
 *                                When creating recycle header with given encap_id, the BCM_L2_EGRESS_WITH_ID had to be set.
 *                                When replacing the information for certain enty both flags BCM_L2_EGRESS_WITH_ID, BCM_L2_EGRESS_REPLACE
 *                                need to be set and a valid encap_id to be given.
 *                                The flag BCM_L2_RECYCLE_HEADER must always be present, when recycle header is being created in  the EEDB
 * \return
 *   int
 *
 * \remark
 *   * None
 * \see
 *   * None
 */
int
bcm_dnx_l2_egress_create(
    int unit,
    bcm_l2_egress_t * egr)
{
    dnx_algo_gpm_gport_hw_resources_t gport_hw_resources;
    lif_mngr_local_outlif_info_t outlif_info;
    lif_mngr_global_lif_info_t global_lif_info = { 0 };
    int lif_alloc_flags = 0;
    int table_result_type = 0;
    int lif_get_flags = 0;
    bcm_gport_t gport;
    dnx_algo_local_outlif_logical_phase_e logical_phase;

    SHR_FUNC_INIT_VARS(unit);
    DNX_ERR_RECOVERY_NOT_NEEDED(unit);

    /** Verification of input parameters */
    SHR_INVOKE_VERIFY_DNXC(dnx_l2_egress_create_verify(unit, egr));

    if (dnx_data_flow.general.feature_get(unit, dnx_data_flow_general_is_flow_enabled_for_legacy_applications))
    {
        SHR_IF_ERR_EXIT(dnx_rch_create_flow(unit, egr));
        SHR_EXIT();
    }
    sal_memset(&gport_hw_resources, 0, sizeof(dnx_algo_gpm_gport_hw_resources_t));

    /** WITH_ID flag is used - get global out-lif ID */
    if (_SHR_IS_FLAG_SET(egr->flags, BCM_L2_EGRESS_WITH_ID))
    {
        /** Add alloc_with_id flag */
        global_lif_info.global_lif = BCM_L3_ITF_VAL_GET(egr->encap_id);
        lif_alloc_flags |= LIF_MNGR_GLOBAL_LIF_WITH_ID;
    }
    table_result_type = DBAL_RESULT_TYPE_EEDB_RCH_ETPS_RCHV2;

    /** Select the proper encap stage. */
    if (egr->encap_access == bcmEncapAccessInvalid)
    {
        if (egr->recycle_app == bcmL2EgressRecycleAppExtendedEncap)
        {
            logical_phase = DNX_ALGO_LOCAL_OUTLIF_LOGICAL_PHASE_7;
        }
        else
        {
            logical_phase = DNX_ALGO_LOCAL_OUTLIF_LOGICAL_PHASE_8;
        }
    }
    else
    {
        SHR_IF_ERR_EXIT(dnx_lif_lib_encap_access_to_logical_phase_convert(unit, egr->encap_access, &logical_phase));
    }

    /** Allocate new egr out-LIF - REPLACE flag is not set */
    if (!_SHR_IS_FLAG_SET(egr->flags, BCM_L2_EGRESS_REPLACE))
    {
        /** fill the local outlif info. */
        sal_memset(&outlif_info, 0, sizeof(lif_mngr_local_outlif_info_t));
        outlif_info.dbal_table_id = DBAL_TABLE_EEDB_RCH;
        outlif_info.logical_phase = logical_phase;

        /** Allocate LIF - WITH_ID if the flag was set */
        SHR_IF_ERR_EXIT(dnx_lif_lib_allocate(unit, lif_alloc_flags, &global_lif_info, NULL, &outlif_info));
        /** update returned Encap ID's */
        BCM_L3_ITF_SET(egr->encap_id, BCM_L3_ITF_TYPE_LIF, global_lif_info.global_lif);
        /** Add entry to out-LIF table */
        SHR_IF_ERR_EXIT(dnx_l2_egress_table_set(unit, egr, table_result_type, outlif_info.local_outlif));
        /** Write global to local LIF mapping to GLEM. */
        SHR_IF_ERR_EXIT(dnx_lif_lib_add_to_glem
                        (unit, _SHR_CORE_ALL, global_lif_info.global_lif, outlif_info.local_outlif, TRUE));
    }

    /** Replace existing out-LIF */
    else
    {
        /** get GPort HW resources (global and local tunnel outlif) */
        lif_get_flags =
            DNX_ALGO_GPM_GPORT_HW_RESOURCES_LOCAL_LIF_EGRESS | DNX_ALGO_GPM_GPORT_HW_RESOURCES_GLOBAL_LIF_EGRESS;

        BCM_L3_ITF_LIF_TO_GPORT_TUNNEL(gport, egr->encap_id);

        /** we don't have gport here, so we're using gport tunnel */
        SHR_IF_ERR_REPLACE_AND_EXIT(dnx_algo_gpm_gport_to_hw_resources(unit, gport, lif_get_flags, &gport_hw_resources),
                                    _SHR_E_NOT_FOUND, _SHR_E_PARAM);

        /** Check that eep is an index of a RCH OutLIF (in SW DB) */
        if (gport_hw_resources.outlif_dbal_table_id != DBAL_TABLE_EEDB_RCH)
        {
            SHR_ERR_EXIT(_SHR_E_NOT_FOUND, "Illegal to replace non RCH OutLIF to RCH OutLIF");
        }
        /** Check that encap stage is not changed */
        if (gport_hw_resources.logical_phase != logical_phase)
        {
            SHR_ERR_EXIT(_SHR_E_PARAM, "encap_access is not changable in replace operation.");
        }

        /** Add entry to out-LIF table */
        SHR_IF_ERR_EXIT(dnx_l2_egress_table_set(unit, egr, table_result_type, gport_hw_resources.local_out_lif));
    }

exit:
    SHR_FUNC_EXIT;
}

/**
 * \brief -
 * BCM API: Get l2 egress object configuration.
 * \param [in] unit - relevant unit.
 * \param [in] encap_id - Encapsulation index
 * \param [out] egr - Pointer to information about
 *        device-independent L2 egress object.
 *        service:
 *          - [out] outer_tpid - outer vlan tag TPID.
 *          - [out] inner_tpid - inner vlan tag TPID.
 *          - [out] dest_mac - Destination MAC address to replace with.
 *          - [out] encap_id - encap_id given.
 *          - [out] flags - with BCM_L2_EGRESS_RECYCLE_HEADER.
 *
 * \return
 *   shr_error_e
 *
 * \remark
 *   * None
 * \see
 *   * None
 */
int
bcm_dnx_l2_egress_get(
    int unit,
    bcm_if_t encap_id,
    bcm_l2_egress_t * egr)
{
    dnx_algo_gpm_gport_hw_resources_t gport_hw_resources;
    bcm_gport_t gport;
    uint32 flags;

    SHR_FUNC_INIT_VARS(unit);
    DNX_ERR_RECOVERY_NOT_NEEDED(unit);

    /** Verification of input parameters */
    SHR_INVOKE_VERIFY_DNXC(dnx_l2_egress_get_verify(unit, encap_id, egr));

    if (dnx_data_flow.general.feature_get(unit, dnx_data_flow_general_is_flow_enabled_for_legacy_applications))
    {
        SHR_IF_ERR_EXIT(dnx_rch_get_flow(unit, encap_id, egr));
        SHR_EXIT();
    }

    /** Get local outlif from he resources */
    BCM_L3_ITF_LIF_TO_GPORT_TUNNEL(gport, encap_id);

    flags = DNX_ALGO_GPM_GPORT_HW_RESOURCES_LOCAL_LIF_EGRESS | DNX_ALGO_GPM_GPORT_HW_RESOURCES_GLOBAL_LIF_EGRESS;
    SHR_IF_ERR_REPLACE_AND_EXIT(dnx_algo_gpm_gport_to_hw_resources(unit, gport, flags, &gport_hw_resources),
                                _SHR_E_NOT_FOUND, _SHR_E_PARAM);

    /** Set return values in egr */
    bcm_l2_egress_t_init(egr);
    egr->encap_id = encap_id;

    SHR_IF_ERR_EXIT(dnx_l2_egress_table_get
                    (unit, egr, gport_hw_resources.local_out_lif, gport_hw_resources.outlif_dbal_result_type));

    /** Set the encap stage.*/
    SHR_IF_ERR_EXIT(dnx_lif_lib_logical_phase_to_encap_access_convert
                    (unit, gport_hw_resources.logical_phase, &egr->encap_access));
    /** Rerune Invalid instead if it's the same as the Invalid stage.*/
    if ((egr->encap_access == bcmEncapAccessArp && egr->recycle_app == bcmL2EgressRecycleAppExtendedEncap) ||
        (egr->encap_access == bcmEncapAccessAc))
    {
        egr->encap_access = bcmEncapAccessInvalid;
    }
exit:
    SHR_FUNC_EXIT;
}

/**
 * \brief -
 * BCM API: Destroy l2 egress object configuration.
 * \param [in] unit - relevant unit.
 * \param [in] encap_id - Encapsulation index
 *
 * \return
 *   shr_error_e
 *
 * \remark
 *   * None
 * \see
 *   * None
 */
int
bcm_dnx_l2_egress_destroy(
    int unit,
    bcm_if_t encap_id)
{
    dnx_algo_gpm_gport_hw_resources_t gport_hw_resources;
    bcm_gport_t gport;
    uint32 flags;

    SHR_FUNC_INIT_VARS(unit);
    DNX_ERR_RECOVERY_NOT_NEEDED(unit);

    /** Verification of input parameters */
    SHR_INVOKE_VERIFY_DNXC(dnx_l2_egress_destroy_verify(unit, encap_id));

    if (dnx_data_flow.general.feature_get(unit, dnx_data_flow_general_is_flow_enabled_for_legacy_applications))
    {
        SHR_IF_ERR_EXIT(dnx_rch_destroy_flow(unit, encap_id));
        SHR_EXIT();
    }

    /** Get local outlif from he resources */
    BCM_L3_ITF_LIF_TO_GPORT_TUNNEL(gport, encap_id);

    flags = DNX_ALGO_GPM_GPORT_HW_RESOURCES_LOCAL_LIF_EGRESS | DNX_ALGO_GPM_GPORT_HW_RESOURCES_GLOBAL_LIF_EGRESS;
    SHR_IF_ERR_REPLACE_AND_EXIT(dnx_algo_gpm_gport_to_hw_resources(unit, gport, flags, &gport_hw_resources),
                                _SHR_E_NOT_FOUND, _SHR_E_PARAM);

    /** Clear --- table values */
    SHR_IF_ERR_EXIT(dnx_l2_egress_table_clear
                    (unit, gport_hw_resources.local_out_lif, gport_hw_resources.outlif_dbal_result_type));

    /** Remove global to local LIF mapping from GLEM. core-Id=0 until bcm_dnx_l2_egress_create is fixed */
    SHR_IF_ERR_EXIT(dnx_lif_lib_remove_from_glem(unit, _SHR_CORE_ALL, gport_hw_resources.global_out_lif));

    /** Free LIF */
    SHR_IF_ERR_EXIT(dnx_lif_lib_free(unit, gport_hw_resources.global_out_lif, NULL, gport_hw_resources.local_out_lif));

exit:
    SHR_FUNC_EXIT;
}
