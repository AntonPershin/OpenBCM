/** \file algo_port_verify.c
 *
 *  PORT manager, Port utilities, and Port verifiers.
 *
 *  Algo port managment:
 *  * MGMT APIs
 *    - Used to configure algo port module
 *    - located in algo_port_mgmt.h (source code algo_port_mgmt.c)
 *  * Utility APIs
 *    - Provide utilities functions which will make the BCM module cleaner and simpler
 *    - located in algo_port_utils.h (source code algo_port_utils.c
 *  * Verify APIs
 *    - Provide a set of APIs which verify port attributes
 *    - These verifiers used to verify algo port functions input.
 *    - These verifiers can be used out side of the module, if requried.
 *    - located in algo_port_verify.h (source code algo_port_verify.c)
 *  * SOC APIs
 *    - Provide set of functions to set / restore  and remove soc info data
 *    - Only the port related members will be configured by this module (other modules should not set those memebers directly)
 *    - The relevant members are: 'port to block access', 'port names' and 'port bitmaps'
 *    - located in algo_port_soc.c (all the functions are module internals)
 *  * Module internal definitions - algo_port_internal.h
 *  * Data bases - use sw state mechanism - XML file is algo_port.xml
 *
 *  No need to include each sub module seperately.
 *  Including: 'algo_port_mgmt.h' will includes all the sub modules
 */
/*
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2022 Broadcom Inc. All rights reserved.
 */
#ifdef BSL_LOG_MODULE
#error "BSL_LOG_MODULE redefined"
#endif
#define BSL_LOG_MODULE BSL_LS_BCMDNX_PORT

/*
 * Include files.
 * {
 */

#include <soc/sand/shrextend/shrextend_debug.h>
#include <bcm/types.h>

#include <bcm_int/dnx/algo/port/algo_port_mgmt.h>
#include "bcm_int/dnx/tdm/tdm.h"
#include <bcm_int/dnx/algo/lane_map/algo_lane_map.h>
#include <include/bcm_int/dnx/cmn/dnxcmn.h>

#include <bcm_int/dnx/algo/swstate/auto_generated/access/dnx_algo_port_access.h>
#include <soc/dnx/dnx_data/auto_generated/dnx_data_device.h>
#include <soc/dnx/dnx_data/auto_generated/dnx_data_port.h>
#include <soc/dnx/dnx_data/auto_generated/dnx_data_nif.h>
#include <soc/dnx/dnx_data/auto_generated/dnx_data_tdm.h>
#include <soc/dnx/dnx_data/auto_generated/dnx_data_fabric.h>
#include <soc/dnx/dnx_data/auto_generated/dnx_data_ingr_reassembly.h>
#include <soc/dnx/dnx_data/auto_generated/dnx_data_sch.h>
#include <soc/dnx/dnx_data/auto_generated/dnx_data_dev_init.h>
#include <soc/dnx/dnx_data/auto_generated/dnx_data_stif.h>
#include <soc/dnx/dnx_data/auto_generated/dnx_data_egr_queuing.h>
#include <soc/dnx/dnx_data/auto_generated/dnx_data_egr_queuing_v1.h>

#include <soc/memory.h>
#include <soc/feature.h>
#include <soc/dnxc/drv_dnxc_utils.h>
#include "algo_port_internal.h"

/*
 * }
 */

/*
 * See .h file
 */
shr_error_e
dnx_algo_port_free_verify(
    int unit,
    bcm_port_t logical_port)
{
    dnx_algo_port_state_e state;
    SHR_FUNC_INIT_VARS(unit);

    /** verify port range */
    if (logical_port < 0 || logical_port >= SOC_MAX_NUM_PORTS)
    {
        SHR_ERR_EXIT(_SHR_E_PORT, "Logical port is out of range %d. Max is %d.\n", logical_port, SOC_MAX_NUM_PORTS - 1);
    }

    /** Verify that port is free */
    SHR_IF_ERR_EXIT(dnx_algo_port_db.logical.state.get(unit, logical_port, &state));
    if (state != DNX_ALGO_PORT_STATE_INVALID)
    {
        SHR_ERR_EXIT(_SHR_E_PORT, "Logical port expected to be free %d.\n", logical_port);
    }

exit:
    SHR_FUNC_EXIT;
}

/*
 * See .h file
 */
shr_error_e
dnx_algo_port_valid_verify(
    int unit,
    bcm_port_t logical_port)
{
    dnx_algo_port_state_e state;
    SHR_FUNC_INIT_VARS(unit);

    /** verify port range */
    if (logical_port < 0 || logical_port >= SOC_MAX_NUM_PORTS)
    {
        SHR_ERR_EXIT(_SHR_E_PORT, "Logical port is out of range %d. Max is %d.\n", logical_port, SOC_MAX_NUM_PORTS - 1);
    }

    /** Verify that port is valid */
    SHR_IF_ERR_EXIT(dnx_algo_port_db.logical.state.get(unit, logical_port, &state));
    if (state == DNX_ALGO_PORT_STATE_INVALID)
    {
        SHR_ERR_EXIT(_SHR_E_PORT, "Logical port expected to be valid %d.\n", logical_port);
    }

exit:
    SHR_FUNC_EXIT;
}
/*
 * See .h file
 */
shr_error_e
dnx_algo_port_type_verify(
    int unit,
    bcm_port_t logical_port,
    dnx_algo_port_type_e port_type)
{
    dnx_algo_port_info_s actual_port_info;
    char port_info_sxp[DNX_ALGO_PORT_TYPE_STR_LENGTH];
    char port_info_got[DNX_ALGO_PORT_TYPE_STR_LENGTH];
    SHR_FUNC_INIT_VARS(unit);

    /** get port type */
    SHR_IF_ERR_EXIT(dnx_algo_port_info_get(unit, logical_port, &actual_port_info));

    /** compare port type */
    if (actual_port_info.port_type != port_type)
    {
        SHR_IF_ERR_EXIT(dnx_algo_port_type_str_get(unit, port_type, port_info_sxp));
        SHR_IF_ERR_EXIT(dnx_algo_port_type_str_get(unit, actual_port_info.port_type, port_info_got));
        SHR_ERR_EXIT(_SHR_E_PARAM, "unexpected port type Expect %s, got %s.\n", port_info_sxp, port_info_got);
    }

exit:
    SHR_FUNC_EXIT;
}

/*
 * See .h file
 */
shr_error_e
dnx_algo_port_pp_dsp_valid_verify(
    int unit,
    bcm_core_t core,
    bcm_port_t pp_dsp)
{
    int valid;
    int nof_pp_dsp;
    SHR_FUNC_INIT_VARS(unit);

    /** verify core */
    DNXCMN_CORE_VALIDATE(unit, core, FALSE);

    /** verify PP DSP */
    nof_pp_dsp = dnx_data_port.general.nof_pp_dsp_get(unit);
    if (pp_dsp < 0 || pp_dsp >= nof_pp_dsp)
    {
        SHR_ERR_EXIT(_SHR_E_PORT, "PP DSP is out of range %d. Max is %d.\n", pp_dsp, nof_pp_dsp - 1);
    }

    /** Verify that port is valid */
    SHR_IF_ERR_EXIT(dnx_algo_port_db.pp_dsp_db.valid.get(unit, core, pp_dsp, &valid));
    if (!valid)
    {
        SHR_ERR_EXIT(_SHR_E_PORT, "pp dsp expected to be valid (core %d, pp dsp %d) .\n", core, pp_dsp);
    }

exit:
    SHR_FUNC_EXIT;
}

/*
 * See .h file
 */
shr_error_e
dnx_algo_port_in_tm_port_valid_verify(
    int unit,
    bcm_core_t core,
    bcm_port_t in_tm_port)
{
    int valid;
    int nof_in_tm_ports;
    SHR_FUNC_INIT_VARS(unit);

    /** verify core range */
    DNXCMN_CORE_VALIDATE(unit, core, FALSE);

    /** verify IN TM port */
    nof_in_tm_ports = dnx_data_port.general.nof_in_tm_ports_get(unit);
    if (in_tm_port < 0 || in_tm_port >= nof_in_tm_ports)
    {
        SHR_ERR_EXIT(_SHR_E_PORT, "IN TM port is out of range %d. Max is %d.\n", in_tm_port, nof_in_tm_ports - 1);
    }

    /** Verify that port is valid */
    SHR_IF_ERR_EXIT(dnx_algo_port_db.in_tm.ref_count.get(unit, core, in_tm_port, &valid));
    if (!valid)
    {
        SHR_ERR_EXIT(_SHR_E_PORT, "IN TM port expected to be valid (core %d, IN TM port %d) .\n", core, in_tm_port);
    }

exit:
    SHR_FUNC_EXIT;
}

/*
 * See .h file
 */
shr_error_e
dnx_algo_port_in_tm_port_free_verify(
    int unit,
    dnx_algo_port_info_s port_info,
    bcm_core_t core,
    bcm_port_t in_tm_port)
{
    int valid;
    int nof_in_tm_ports;
    bcm_port_t master_logical_port;
    dnx_algo_port_info_s master_port_info;

    SHR_FUNC_INIT_VARS(unit);

    /** verify core */
    DNXCMN_CORE_VALIDATE(unit, core, FALSE);

    /** verify tm port */
    nof_in_tm_ports = dnx_data_port.general.nof_in_tm_ports_get(unit);
    if (in_tm_port < 0 || in_tm_port >= nof_in_tm_ports)
    {
        SHR_ERR_EXIT(_SHR_E_PORT, "IN TM port is out of range %d. Max is %d.\n", in_tm_port, nof_in_tm_ports - 1);
    }

    if (!dnx_data_ingr_reassembly.context.feature_get(unit, dnx_data_ingr_reassembly_context_pp_tm_context))
    {
        /** Verify that port is not valid */
        SHR_IF_ERR_EXIT(dnx_algo_port_db.in_tm.ref_count.get(unit, core, in_tm_port, &valid));

        if (valid)
        {
            if (!DNX_ALGO_PORT_TYPE_IS_RCY_MIRROR(unit, port_info) &&
                !(DNX_ALGO_PORT_TYPE_IS_RCY(unit, port_info) &&
                  dnx_data_ingr_reassembly.context.feature_get(unit, dnx_data_ingr_reassembly_context_pp_tm_context)))
            {
                SHR_ERR_EXIT(_SHR_E_PORT, "IN TM port expected to be free (core %d, in tm port %d) .\n",
                             core, in_tm_port);
            }
            else
            {
                SHR_IF_ERR_EXIT(dnx_algo_port_db.in_tm.master_logical_port.get(unit, core, in_tm_port,
                                                                               &master_logical_port));
                SHR_IF_ERR_EXIT(dnx_algo_port_info_get(unit, master_logical_port, &master_port_info));
                if (port_info.port_type != master_port_info.port_type)
                {
                    SHR_ERR_EXIT(_SHR_E_PORT,
                                 "IN TM port is in use by port %d (core %d, in tm port %d) which is not on the same interface .\n",
                                 master_logical_port, core, in_tm_port);
                }
            }
        }
    }

exit:
    SHR_FUNC_EXIT;
}

/*
 * See .h file
 */
shr_error_e
dnx_algo_port_pp_dsp_free_verify(
    int unit,
    dnx_algo_port_info_s port_info,
    bcm_core_t core,
    bcm_port_t pp_dsp)
{
    int valid;
    int nof_pp_dsp;

    SHR_FUNC_INIT_VARS(unit);

    /** verify core */
    DNXCMN_CORE_VALIDATE(unit, core, FALSE);

    /** verify pp dsp */
    nof_pp_dsp = dnx_data_port.general.nof_pp_dsp_get(unit);
    if (pp_dsp < 0 || pp_dsp >= nof_pp_dsp)
    {
        SHR_ERR_EXIT(_SHR_E_PORT, "PP DSP is out of range %d. Max is %d.\n", pp_dsp, nof_pp_dsp - 1);
    }

    /** verify pp dsp is not reserved pp dsp */
    /** reserved for ERP */
    if (!DNX_ALGO_PORT_TYPE_IS_ERP(unit, port_info))
    {
        if ((pp_dsp + 1) % dnx_data_port.general.nof_pp_dsp_per_fap_id_get(unit) == 0)
        {
            SHR_ERR_EXIT(_SHR_E_PORT, "PP DSP reserved for ERP %d.\n", pp_dsp);
        }
    }
    else
    {
        if (pp_dsp != dnx_data_port.general.erp_pp_dsp_get(unit))
        {
            SHR_ERR_EXIT(_SHR_E_PORT, "ERP PP DSP was set to %d, should be %d.\n", pp_dsp,
                         dnx_data_port.general.erp_pp_dsp_get(unit));
        }
    }
    /** reserved PP DSP (used for returned credits in LAG SCH)*/
    if (pp_dsp == dnx_data_port.general.reserved_pp_dsp_get(unit))
    {
        SHR_ERR_EXIT(_SHR_E_PORT, "PP DSP %d is reserved and cannot be used.\n", pp_dsp);
    }

    /** Verify that port is not valid */
    SHR_IF_ERR_EXIT(dnx_algo_port_db.pp_dsp_db.valid.get(unit, core, pp_dsp, &valid));

    if (valid)
    {
        SHR_ERR_EXIT(_SHR_E_PORT, "PP DSP expected to be free (core %d, pp dsp %d) .\n", core, pp_dsp);
    }

exit:
    SHR_FUNC_EXIT;
}

/*
 * See .h file
 */
shr_error_e
dnx_algo_port_out_tm_port_free_verify(
    int unit,
    dnx_algo_port_info_s port_info,
    bcm_core_t core,
    bcm_port_t out_tm_port,
    dnx_algo_port_db_2d_handle_t interface_handle)
{
    int valid;
    int nof_out_tm_ports;
    dnx_algo_port_db_2d_handle_t master_interface_handle;
    bcm_port_t master_logical_port;

    SHR_FUNC_INIT_VARS(unit);

    /** verify core */
    DNXCMN_CORE_VALIDATE(unit, core, FALSE);
    /** verify tm port */
    nof_out_tm_ports = dnx_data_port.general.nof_out_tm_ports_get(unit);
    if (out_tm_port < 0 || out_tm_port >= nof_out_tm_ports)
    {
        SHR_ERR_EXIT(_SHR_E_PORT, "OUT TM port is out of range %d. Max is %d.\n", out_tm_port, nof_out_tm_ports - 1);
    }

    /** Verify that port is not valid */
    SHR_IF_ERR_EXIT(dnx_algo_port_db.out_tm.ref_count.get(unit, core, out_tm_port, &valid));

    if (valid)
    {
        if (!DNX_ALGO_PORT_TYPE_IS_RCY(unit, port_info) && !DNX_ALGO_PORT_TYPE_IS_OLP(unit, port_info))
        {
            SHR_ERR_EXIT(_SHR_E_PORT, "OUT TM port expected to be free (core %d, out tm port %d) .\n", core,
                         out_tm_port);
        }
        else
        {
            SHR_IF_ERR_EXIT(dnx_algo_port_db.out_tm.master_logical_port.get(unit, core, out_tm_port,
                                                                            &master_logical_port));
            SHR_IF_ERR_EXIT(dnx_algo_port_db.logical.interface_handle.get(unit, master_logical_port,
                                                                          &master_interface_handle));
            if (!DNX_ALGO_PORT_2D_HANDLE_EQ(master_interface_handle, interface_handle))
            {
                SHR_ERR_EXIT(_SHR_E_PORT,
                             "port %d: OUT TM port is in use by a port on a different interface (core %d, in tm port %d) .\n",
                             master_logical_port, core, out_tm_port);
            }
        }
    }

exit:
    SHR_FUNC_EXIT;
}

/*
 * See .h file
 */
shr_error_e
dnx_algo_port_out_tm_add_verify(
    int unit,
    dnx_algo_port_info_s port_info,
    bcm_core_t core,
    bcm_port_t out_tm_port,
    dnx_algo_port_tm_add_t * info,
    int if_id_h0,
    int if_id_h1)
{
    int valid;
    dnx_algo_port_db_2d_handle_t out_tm_handle;
    int master_nof_priorities;
    dnx_algo_port_db_2d_handle_t interface_handle;

    SHR_FUNC_INIT_VARS(unit);

    interface_handle.h0 = if_id_h0;
    interface_handle.h1 = if_id_h1;

    /** out tm port Verify */
    SHR_IF_ERR_EXIT(dnx_algo_port_out_tm_port_free_verify(unit, port_info, core, info->out_tm_port, interface_handle));

    out_tm_handle.h0 = core;
    out_tm_handle.h1 = info->out_tm_port;
    SHR_IF_ERR_EXIT(dnx_algo_port_db.out_tm.ref_count.get(unit, out_tm_handle.h0, out_tm_handle.h1, &valid));
    if (valid)
    {

        SHR_IF_ERR_EXIT(dnx_algo_port_db.out_tm.priorities.get(unit, out_tm_handle.h0, out_tm_handle.h1,
                                                               &master_nof_priorities));

        if (info->num_priorities != master_nof_priorities)
        {
            SHR_ERR_EXIT(_SHR_E_PARAM,
                         "OUT TM PORT (%d, %d) has %d priorities. requested %d priorties.\n", core, info->out_tm_port,
                         master_nof_priorities, info->num_priorities);
        }

    }

exit:
    SHR_FUNC_EXIT;
}

/*
 * See .h file
 */
shr_error_e
dnx_algo_port_pp_dsp_allowed_verify(
    int unit,
    bcm_core_t core,
    uint32_t pp_dsp,
    int nof_fap_ids_per_core)
{
    SHR_FUNC_INIT_VARS(unit);

    if (nof_fap_ids_per_core > 0)
    {
        /*
         * check only if at least one fap ID is defined
         * in no fap ID is defined
         * the check will be executed again in first traffic_enable for all ports
         */
        if (pp_dsp >= dnx_data_port.general.nof_pp_dsp_per_fap_id_get(unit) * nof_fap_ids_per_core)
        {
            SHR_ERR_EXIT(_SHR_E_PARAM,
                         "PP DSP %d is not allowed with %d FAP IDs per core.\n", pp_dsp, nof_fap_ids_per_core);

        }

    }

exit:
    SHR_FUNC_EXIT;
}

/*
 * See .h file
 */
shr_error_e
dnx_algo_port_hr_param_verify(
    int unit,
    bcm_core_t core,
    int hr_id)
{
    int nof_hrs;

    SHR_FUNC_INIT_VARS(unit);

    /** verify core */
    DNXCMN_CORE_VALIDATE(unit, core, FALSE);

    /** verify hr id */
    nof_hrs = dnx_data_sch.flow.nof_hr_get(unit);
    if (hr_id < 0 || hr_id >= nof_hrs)
    {
        SHR_ERR_EXIT(_SHR_E_PARAM, "HR id is out of range %d. Max is %d.\n", hr_id, nof_hrs - 1);
    }

exit:
    SHR_FUNC_EXIT;
}

/*
 * See .h file
 */
shr_error_e
dnx_algo_port_hr_valid_verify(
    int unit,
    bcm_core_t core,
    int hr_id)
{
    int valid;

    SHR_FUNC_INIT_VARS(unit);

    /** verify parameters */
    SHR_IF_ERR_EXIT(dnx_algo_port_hr_param_verify(unit, core, hr_id));

    /** Verify that hr is valid */
    SHR_IF_ERR_EXIT(dnx_algo_port_db.sch.ref_count.get(unit, core, hr_id, &valid));
    if (!valid)
    {
        SHR_ERR_EXIT(_SHR_E_PORT, "SCH info expected to be valid (core %d, hr %d) .\n", core, hr_id);
    }

exit:
    SHR_FUNC_EXIT;
}

/*
 * See .h file
 */
shr_error_e
dnx_algo_port_pp_port_valid_verify(
    int unit,
    bcm_core_t core,
    bcm_port_t pp_port)
{
    int valid;
    int nof_pp_ports;
    SHR_FUNC_INIT_VARS(unit);

    /** verify core */
    DNXCMN_CORE_VALIDATE(unit, core, FALSE);

    /** verify pp port */
    nof_pp_ports = dnx_data_port.general.nof_pp_ports_get(unit);
    if (pp_port < 0 || pp_port >= nof_pp_ports)
    {
        SHR_ERR_EXIT(_SHR_E_PORT, "PP port is out of range %d. Max is %d.\n", core, nof_pp_ports - 1);
    }

    /** Verify that port is valid */
    SHR_IF_ERR_EXIT(dnx_algo_port_db.pp.ref_count.get(unit, core, pp_port, &valid));
    if (!valid)
    {
        SHR_ERR_EXIT(_SHR_E_PORT, "PP port expected to be valid (core %d, pp port %d) .\n", core, pp_port);
    }

exit:
    SHR_FUNC_EXIT;
}

/*
 * See .h file
 */
shr_error_e
dnx_algo_port_fabric_link_valid_verify(
    int unit,
    int fabric_link)
{
    int valid;
    int nof_fabric_links;
    SHR_FUNC_INIT_VARS(unit);

    /** verify fabric link */
    nof_fabric_links = dnx_data_fabric.links.nof_links_get(unit);
    if (fabric_link < 0 || fabric_link >= nof_fabric_links)
    {
        SHR_ERR_EXIT(_SHR_E_PARAM, "Fabric link is out of range %d. Max is %d.\n", fabric_link, nof_fabric_links - 1);
    }

    /** Verify that port is valid */
    SHR_IF_ERR_EXIT(dnx_algo_port_db.fabric.valid.get(unit, fabric_link, &valid));
    if (!valid)
    {
        SHR_ERR_EXIT(_SHR_E_PARAM, "Fabric link expected to be valid (%d) .\n", fabric_link);
    }

exit:
    SHR_FUNC_EXIT;
}

/*
 * See .h file
 */
shr_error_e
dnx_algo_port_flexe_client_index_valid_verify(
    int unit,
    dnx_algo_port_type_e port_type,
    int client_index)
{
    int valid;
    int nof_clients;
    int flexe_handle;
    SHR_FUNC_INIT_VARS(unit);

    if (port_type == DNX_ALGO_PORT_TYPE_FLEXE_CLIENT)
    {
        /** verify client-id range */
        nof_clients = dnx_data_nif.flexe.nof_clients_get(unit);
        SHR_RANGE_VERIFY(client_index, 0, nof_clients - 1, _SHR_E_PARAM, "FlexE client ID is out of range.\n");

        /** Verify that client is valid */
        flexe_handle = client_index;
        SHR_IF_ERR_EXIT(dnx_algo_port_db.flexe.client.valid.get(unit, flexe_handle, &valid));
    }
    else if (port_type == DNX_ALGO_PORT_TYPE_FRAMER_MAC)
    {
        /** verify client-id range */
        nof_clients = dnx_data_nif.mac_client.nof_clients_get(unit);
        SHR_RANGE_VERIFY(client_index, 0, nof_clients - 1, _SHR_E_PARAM, "FlexE client ID is out of range.\n");

        /** Verify that client is valid */
        flexe_handle = client_index;
        SHR_IF_ERR_EXIT(dnx_algo_port_db.flexe.mac.valid.get(unit, flexe_handle, &valid));
    }
    else if (port_type == DNX_ALGO_PORT_TYPE_FRAMER_SAR)
    {
        /** verify client-id range */
        nof_clients = dnx_data_nif.sar_client.nof_clients_get(unit);
        SHR_RANGE_VERIFY(client_index, 0, nof_clients - 1, _SHR_E_PARAM, "FlexE client ID is out of range.\n");

        /** Verify that client is valid */
        flexe_handle = client_index;
        SHR_IF_ERR_EXIT(dnx_algo_port_db.flexe.sar.valid.get(unit, flexe_handle, &valid));
    }
    else
    {
        SHR_ERR_EXIT(_SHR_E_INTERNAL, "Unexpected port type\n");
    }

    if (!valid)
    {
        SHR_ERR_EXIT(_SHR_E_PARAM, "FlexE client expected to be valid (%d) .\n", client_index);
    }

exit:
    SHR_FUNC_EXIT;
}

/*
 * See .h file
 */
shr_error_e
dnx_algo_port_fabric_phy_verify(
    int unit,
    int fabric_phy)
{
    SHR_FUNC_INIT_VARS(unit);

    if (fabric_phy < 0 || fabric_phy >= dnx_data_fabric.links.nof_links_get(unit))
    {
        SHR_ERR_EXIT(_SHR_E_PARAM, "phy is out of bound - %d \n", fabric_phy);
    }

exit:
    SHR_FUNC_EXIT;
}

/**
 * \brief - Get ILKN connectivity option that matches ILKN core and its phys
 *          if phys range is illegal for ILKN core - report error
 *
 *   \param [in] unit - Relevant unit
 *   \param [in] ilkn_id - ilkn interface index
 *   \param [in] first_phy_in_port - first phy assigned to port
 *   \param [in] last_phy_in_port -last phy assigned to port
 *   \param [out] mode - connectivity mode
 *   \param [out] is_mode_found - does any mode matches range?
 *
 * \return
 *   shr_error_e
 *
 * \remark
 *   Return value is meaningful only if is_mode_found == TRUE
 *
 * \see
 *   * None
 */
shr_error_e
dnx_algo_port_ilkn_matching_connectivity_mode_find(
    int unit,
    uint32 ilkn_id,
    int first_phy_in_port,
    int last_phy_in_port,
    int *mode,
    int *is_mode_found)
{
    int first_phy_in_range;
    int last_phy_in_range;

    SHR_FUNC_INIT_VARS(unit);

    *is_mode_found = FALSE;
    for (*mode = DNX_ALGO_PORT_ILKN_CONNECTIVITY_MODE_UNDETERMINED; *mode < DNX_ALGO_PORT_ILKN_CONNECTIVITY_MODE_COUNT;
         (*mode)++)
    {
        first_phy_in_range = dnx_data_nif.ilkn.connectivity_options_get(unit, ilkn_id, *mode)->first_phy;
        last_phy_in_range = dnx_data_nif.ilkn.connectivity_options_get(unit, ilkn_id, *mode)->last_phy;

        if (first_phy_in_port >= first_phy_in_range && last_phy_in_port <= last_phy_in_range)
        {
            *is_mode_found = TRUE;
            break;
        }
    }

    SHR_FUNC_EXIT;
}

/**
 * \brief - Get ILKN connectivity mode
 *
 *   \param [in] unit - Relevant unit
 *   \param [in] core - device core
 *   \param [out] mode - connectivity mode
 *
 * \return
 *   shr_error_e
 *
 * \remark
 *   * None
 *
 * \see
 *   * None
 */
shr_error_e
dnx_algo_port_ilkn_current_connectivity_mode_find(
    int unit,
    int core,
    int *mode)
{
    dnx_algo_port_ilkn_access_info_t existing_port_info;
    bcm_pbmp_t phys_in_existing_port;
    bcm_pbmp_t all_ilkn_ports;
    int existing_port_ilkn_id;
    int first_phy_in_existing_port;
    int last_phy_in_existing_port;
    int existing_port;
    int is_mode_found;
    int port_count;

    SHR_FUNC_INIT_VARS(unit);

    *mode = DNX_ALGO_PORT_ILKN_CONNECTIVITY_MODE_UNDETERMINED;
    SHR_IF_ERR_EXIT(dnx_algo_port_logicals_get(unit, core, DNX_ALGO_PORT_LOGICALS_TYPE_NIF_ILKN,
                                               DNX_ALGO_PORT_LOGICALS_F_MASTER_ONLY, &all_ilkn_ports));
    _SHR_PBMP_COUNT(all_ilkn_ports, port_count);

    if (port_count > 0)
    {
        _SHR_PBMP_FIRST(all_ilkn_ports, existing_port);

        /*
         * get ILKN ID and phy range of existing port
         */
        SHR_IF_ERR_EXIT(dnx_algo_port_ilkn_access_info_get(unit, existing_port, &existing_port_info));
        existing_port_ilkn_id = existing_port_info.ilkn_id;
        SHR_IF_ERR_EXIT(dnx_algo_port_nif_phys_get(unit, existing_port, 0, &phys_in_existing_port));
        _SHR_PBMP_FIRST(phys_in_existing_port, first_phy_in_existing_port);
        _SHR_PBMP_LAST(phys_in_existing_port, last_phy_in_existing_port);

        /*
         * check which (and whether) connectivity mode is dictated by existing port
         */
        SHR_IF_ERR_EXIT(dnx_algo_port_ilkn_matching_connectivity_mode_find(unit,
                                                                           existing_port_ilkn_id,
                                                                           first_phy_in_existing_port,
                                                                           last_phy_in_existing_port, mode,
                                                                           &is_mode_found));
    }

exit:
    SHR_FUNC_EXIT;
}

/*
 * See .h file
 */
shr_error_e
dnx_algo_port_ilkn_phys_12lane_mode_verify(
    int unit,
    int core,
    bcm_port_t logical_port,
    uint32 ilkn_id,
    bcm_pbmp_t phys)
{
    const dnx_data_nif_ilkn_connectivity_options_t *connectivity_options;
    char *mode_strs[] = { "undetermined", "6 lane per interface", "8 lane per interface" };
    int mode;
    int dummy_mode;
    int is_mode_found;
    int first_phy_in_port;
    int last_phy_in_port;

    SHR_FUNC_INIT_VARS(unit);

    _SHR_PBMP_FIRST(phys, first_phy_in_port);
    _SHR_PBMP_LAST(phys, last_phy_in_port);
    SHR_IF_ERR_EXIT(dnx_algo_port_ilkn_current_connectivity_mode_find(unit, core, &mode));

    if (mode == DNX_ALGO_PORT_ILKN_CONNECTIVITY_MODE_UNDETERMINED)
    {
        /*
         * verify phys range is legal for at least one mode
         */
        SHR_IF_ERR_EXIT(dnx_algo_port_ilkn_matching_connectivity_mode_find(unit, ilkn_id, first_phy_in_port,
                                                                           last_phy_in_port, &dummy_mode,
                                                                           &is_mode_found));
        if (!is_mode_found)
        {
            SHR_ERR_EXIT(_SHR_E_CONFIG,
                         "port %d lanes %d-%d are not supported for ILKN interface %d\n",
                         logical_port, first_phy_in_port, last_phy_in_port, ilkn_id);
        }
    }

    else
    {
        /*
         * verify phys range is legal for current mode
         */
        connectivity_options = dnx_data_nif.ilkn.connectivity_options_get(unit, ilkn_id, mode);
        if (first_phy_in_port < connectivity_options->first_phy || last_phy_in_port > connectivity_options->last_phy)
        {
            SHR_ERR_EXIT(_SHR_E_CONFIG,
                         "port %d lanes %d-%d are not supported for ILKN interface %d in %s mode\n",
                         logical_port, first_phy_in_port, last_phy_in_port, ilkn_id, mode_strs[mode]);
        }
    }

exit:
    SHR_FUNC_EXIT;
}

/*
 * See .h file
 */
shr_error_e
dnx_algo_port_ilkn_over_fabric_phys_verify(
    int unit,
    bcm_port_t logical_port,
    bcm_pbmp_t phys)
{
    int pm_id = 0;
    int link_id = 0;
    uint32 pm_bypassed_links[1] = { 0 };
    uint32 is_bypassed = 0;
    int nof_links_in_pm = 0;
    int nof_fabric_pms = 0;
    bcm_pbmp_t bypassed_phys_bmp;
    bcm_pbmp_t illegal_phys_bmp;
    bcm_pbmp_t ilkn_port_bmp;
    bcm_pbmp_t fabric_link_bmp;
    bcm_port_t port;
    int is_over_fabric = 0;
    int ilkn_is_supported = 0;
    SHR_FUNC_INIT_VARS(unit);

    nof_links_in_pm = dnx_data_fabric.blocks.nof_links_in_pm_get(unit);
    nof_fabric_pms = dnx_data_fabric.blocks.nof_pms_get(unit);
    ilkn_is_supported = dnx_data_nif.ilkn.feature_get(unit, dnx_data_nif_ilkn_is_supported);

    /*
     *  Make sure all requested links are in bypass mode
     */
    BCM_PBMP_CLEAR(bypassed_phys_bmp);

    for (pm_id = 0; pm_id < nof_fabric_pms; pm_id++)
    {
        pm_bypassed_links[0] = dnx_data_fabric.ilkn.bypass_info_get(unit, pm_id)->links;

        for (link_id = 0; link_id < nof_links_in_pm; link_id++)
        {
            is_bypassed = (ilkn_is_supported && SHR_BITGET(pm_bypassed_links, link_id)) ? 1 : 0;
            if (is_bypassed)
            {
                BCM_PBMP_PORT_ADD(bypassed_phys_bmp, pm_id * nof_links_in_pm + link_id);
            }
        }
    }

    BCM_PBMP_ASSIGN(illegal_phys_bmp, phys);
    BCM_PBMP_REMOVE(illegal_phys_bmp, bypassed_phys_bmp);
    if (!BCM_PBMP_IS_NULL(illegal_phys_bmp))
    {
        SHR_ERR_EXIT(_SHR_E_INTERNAL, "ILKN port %d is assigned to phys which are not in bypass mode\n", logical_port);
    }

    /*
     * Make sure no ILKN ports using those phys
     */
    SHR_IF_ERR_EXIT(dnx_algo_port_logicals_get
                    (unit, BCM_CORE_ALL, DNX_ALGO_PORT_LOGICALS_TYPE_NIF_ILKN, DNX_ALGO_PORT_LOGICALS_F_MASTER_ONLY,
                     &ilkn_port_bmp));

    BCM_PBMP_PORT_REMOVE(ilkn_port_bmp, logical_port);
    BCM_PBMP_ITER(ilkn_port_bmp, port)
    {
        SHR_IF_ERR_EXIT(dnx_algo_port_nif_ilkn_is_over_fabric_get(unit, port, &is_over_fabric));
        if (is_over_fabric)
        {
            SHR_IF_ERR_EXIT(dnx_algo_port_nif_phys_get(unit, port, 0, &fabric_link_bmp));

            BCM_PBMP_AND(fabric_link_bmp, phys);
            if (!BCM_PBMP_IS_NULL(fabric_link_bmp))
            {
                SHR_ERR_EXIT(_SHR_E_INTERNAL, "port %d and port %d share phys.\n", logical_port, port);
            }
        }
    }
exit:
    SHR_FUNC_EXIT;
}

/*
 * See .h file
 */
shr_error_e
dnx_algo_port_ilkn_phys_verify(
    int unit,
    int core,
    bcm_port_t port,
    uint32 ilkn_id,
    bcm_pbmp_t phys)
{
    imb_dispatch_type_t pm_imb_type;
    int iter_phy, first_phy, ethu_id;
    int non_facing_id = -1, ilkn_port_i, second_ilkn_port = -1, facing_core_id, is_facing = 1, pm_index, ilkn_core;
    uint8 non_facing_found = FALSE;
    bcm_pbmp_t all_ilkn_ports;
    bcm_pbmp_t second_port_phys;
    dnx_algo_port_ilkn_access_info_t port_i_ilkn_info;
    SHR_FUNC_INIT_VARS(unit);

    ilkn_core = ilkn_id / dnx_data_nif.ilkn.ilkn_unit_if_nof_get(unit);
    _SHR_PBMP_FIRST(phys, first_phy);

    SHR_IF_ERR_EXIT(dnx_algo_phy_to_ethu_id_get(unit, first_phy, &ethu_id));

    pm_imb_type = dnx_data_nif.eth.ethu_properties_get(unit, ethu_id)->type;

    _SHR_PBMP_ITER(phys, iter_phy)
    {
        SHR_IF_ERR_EXIT(dnx_algo_phy_to_ethu_id_get(unit, iter_phy, &ethu_id));
        if (dnx_data_nif.eth.ethu_properties_get(unit, ethu_id)->type != pm_imb_type)
        {
            SHR_ERR_EXIT(_SHR_E_CONFIG,
                         "unsupported phy combination for port %d: ilkn port can't be combined from more than 1 PM type.\n",
                         port);
        }
    }
    if ((pm_imb_type == imbDispatchTypeImb_clu)
        && dnx_data_nif.ilkn.feature_get(unit, dnx_data_nif_ilkn_clu_ilkn_selectors))
    {
        _SHR_PBMP_ITER(phys, iter_phy)
        {
            pm_index =
                dnx_data_nif.eth.phy_map_get(unit,
                                             (iter_phy / dnx_data_nif.eth.phy_map_granularity_get(unit)))->pm_index;

            facing_core_id = dnx_data_nif.ilkn.nif_pms_get(unit, pm_index)->facing_core_index;
            is_facing = (facing_core_id == ilkn_core) ? 1 : 0;
            /*
             * If non-facing PM found store the facing core id and check if it's the first non-facing
             */
            if (!is_facing)
            {
                if (!non_facing_found)
                {
                    non_facing_found = TRUE;
                    non_facing_id = facing_core_id;
                }
                /*
                 * If there is more than 1 non-facing ilkn core for the same ilkn port - return error
                 */
                if (non_facing_id != facing_core_id)
                {
                    SHR_ERR_EXIT(_SHR_E_CONFIG,
                                 "unsupported phy combination: more than 1 PM which connected to non-facing ilkn core can't be configured for the same ilkn core. please refer to UM for more information ");

                }
            }   /* if (!is_facing) */
        }/*_SHR_PBMP_ITER(phys, iter_phy)*/

        /*
         * If there is lanes which are non-facing core need also to check if there is another port on the same ilkn
         * core, if yes, need to do same check
         */
        if (non_facing_found)
        {
            /*
             * Retrieve all ilkn ports which were already configured
             */
            SHR_IF_ERR_EXIT(dnx_algo_port_logicals_get
                            (unit, core, DNX_ALGO_PORT_LOGICALS_TYPE_NIF_ILKN, DNX_ALGO_PORT_LOGICALS_F_MASTER_ONLY,
                             &all_ilkn_ports));
            /*
             * iterate over all Ilkn ports and check if MAC is is the same as given port
             */
            BCM_PBMP_ITER(all_ilkn_ports, ilkn_port_i)
            {
                SHR_IF_ERR_EXIT(dnx_algo_port_ilkn_access_info_get(unit, ilkn_port_i, &port_i_ilkn_info));
                if (port_i_ilkn_info.ilkn_core == ilkn_core)
                {
                    second_ilkn_port = ilkn_port_i;
                    break;
                }
            }

            /*
             * There is another ilkn port on the same ilkn core
             */
            if (second_ilkn_port != -1)
            {
                /*
                 * Extract ilkn phys for the other port
                 */
                SHR_IF_ERR_EXIT(dnx_algo_port_nif_phys_get(unit, second_ilkn_port, 0, &second_port_phys));

                _SHR_PBMP_ITER(second_port_phys, iter_phy)
                {
                    pm_index =
                        dnx_data_nif.eth.phy_map_get(unit,
                                                     (iter_phy /
                                                      dnx_data_nif.eth.phy_map_granularity_get(unit)))->pm_index;

                    facing_core_id = dnx_data_nif.ilkn.nif_pms_get(unit, pm_index)->facing_core_index;
                    is_facing = (facing_core_id == ilkn_core) ? 1 : 0;
                    if (!is_facing)
                    {
                        if (non_facing_id != facing_core_id)
                        {
                            SHR_ERR_EXIT(_SHR_E_CONFIG,
                                         "unsupported phy combination: more than 1 PM which connected to non-facing ilkn core can't be configured for the same ilkn core. please refer to UM for more information ");

                        }
                    }   /* if (!is_facing) */
                }/*_SHR_PBMP_ITER(second_port_phys, iter_phy)*/
            }   /* if (ilkn_nof_ports == 1 ) */
        }       /* if ( non_facing_found ) */
    }   /* if ((pm_imb_type == imbDispatchTypeImb_clu) && dnx_data_nif.ilkn.feature_get(unit,
         * dnx_data_nif_ilkn_clu_ilkn_selectors)) */
exit:
    SHR_FUNC_EXIT;
}

/*
 * See .h file
 */
shr_error_e
dnx_algo_port_nif_phys_verify(
    int unit,
    bcm_port_t logical_port,
    dnx_algo_port_info_s port_info,
    bcm_pbmp_t phys)
{
    const dnx_data_nif_phys_general_t *phys_info;
    bcm_pbmp_t unsupported_phys, pm_phys;
    char phys_str[_SHR_PBMP_FMT_LEN];
    bcm_port_t active_nif_port;
    int phy_id, is_active = 0, i, pm_index;
    bcm_pbmp_t phys_to_check;
    dnx_algo_port_info_s active_port_info;
    dnx_algo_pm_info_t pm_info;
    int first_phy;
    int nof_phys = 0;
    int table_index;
    int pm_lower_bound;

    SHR_FUNC_INIT_VARS(unit);

    /*
     * Get supported phys per device and throw an error if phys include unsupported phy
     */
    /** get phys info from dnx data */
    phys_info = dnx_data_nif.phys.general_get(unit);

    /** calc bitmap of unsupported phys */
    BCM_PBMP_ASSIGN(unsupported_phys, phys);
    BCM_PBMP_REMOVE(unsupported_phys, phys_info->supported_phys);

    /** if this bitmap is not empty throw an error */
    if (!BCM_PBMP_IS_NULL(unsupported_phys))
    {
        _SHR_PBMP_FMT(unsupported_phys, phys_str);
        SHR_ERR_EXIT(_SHR_E_INTERNAL, "Unsupported nif phys for port %d ( %s ).\n", logical_port, phys_str);
    }

    /*
     * Make sure no one else using those phys
     */
    BCM_PBMP_ITER(phys, phy_id)
    {
        SHR_IF_ERR_EXIT(dnx_algo_port_nif_phy_active_get(unit, phy_id, &is_active));
        if (is_active)
        {
            /*
             * ILKN over fabric port will not go into this API, hence setting
             * "is_over_fabric" flag to "0".
             */
            SHR_IF_ERR_EXIT(dnx_algo_port_nif_phy_to_logical_get(unit, phy_id, 0, 0, &active_nif_port));
            SHR_ERR_EXIT(_SHR_E_INTERNAL, "port %d and port %d share phys.\n", logical_port, active_nif_port);
        }
    }

    /*
     * If the port is on PM 4x25.
     * Make sure the PM does not mix ETH and ILKN ports
     */
    _SHR_PBMP_CLEAR(phys_to_check);

    BCM_PBMP_ITER(phys, phy_id)
    {
        SHR_IF_ERR_EXIT(dnx_algo_phy_pm_info_get(unit, phy_id, &pm_info));
        if (pm_info.dispatch_type == portmodDispatchTypePm4x25)
        {
            _SHR_PBMP_OR(phys_to_check, pm_info.phys);
        }
    }

    /** remove phys of the new port - they are already checked */
    BCM_PBMP_REMOVE(phys_to_check, phys);

    BCM_PBMP_ITER(phys_to_check, phy_id)
    {
        SHR_IF_ERR_EXIT(dnx_algo_port_nif_phy_active_get(unit, phy_id, &is_active));
        if (is_active)
        {
            /*
             * ILKN over fabric port will not go into this API, hence setting
             * "is_over_fabric" flag to "FALSE".
             */
            SHR_IF_ERR_EXIT(dnx_algo_port_nif_phy_to_logical_get(unit, phy_id, FALSE, 0, &active_nif_port));
            SHR_IF_ERR_EXIT(dnx_algo_port_info_get(unit, active_nif_port, &active_port_info));
            if (DNX_ALGO_PORT_TYPE_IS_NIF_ILKN(unit, port_info, DNX_ALGO_PORT_TYPE_INCLUDE(ELK, L1)) !=
                DNX_ALGO_PORT_TYPE_IS_NIF_ILKN(unit, active_port_info, DNX_ALGO_PORT_TYPE_INCLUDE(ELK, L1)))
            {
                SHR_ERR_EXIT(_SHR_E_PARAM, "port %d and port %d are on the same PM 4x25 and are not of the same type\n",
                             logical_port, active_nif_port);
            }
        }
    }

    /*
     * Verify if using correct PHYs for flexe physical port
     */
    if (DNX_ALGO_PORT_TYPE_IS_FRAMER_PHY(unit, port_info))
    {
        for (i = 0; i < dnx_data_nif.framer.nof_pms_per_framer_get(unit); ++i)
        {
            /*
             * Get supported PM
             */
            pm_index = dnx_data_nif.flexe.supported_pms_get(unit, 0)->nif_pms[i];
            /*
             * Get PM PHYs
             */
            pm_phys = dnx_data_nif.eth.pm_properties_get(unit, pm_index)->phys;
            /*
             * Verify the PHY assignment
             */
            BCM_PBMP_ASSIGN(unsupported_phys, phys);
            BCM_PBMP_REMOVE(unsupported_phys, pm_phys);
            if (BCM_PBMP_IS_NULL(unsupported_phys))
            {
                break;
            }
        }
        if (i == dnx_data_nif.framer.nof_pms_per_framer_get(unit))
        {
            SHR_ERR_EXIT(_SHR_E_PARAM, "FlexE phy assignment is incorrect.\n");
        }
    }

    /*
     * Verify if the number of lanes and the first phy of the port are legal
     */
    if (DNX_ALGO_PORT_TYPE_IS_NIF_ETH(unit, port_info, DNX_ALGO_PORT_TYPE_INCLUDE(STIF, L1, MGMT, FRAMER_MGMT))
        || DNX_ALGO_PORT_TYPE_IS_FRAMER_PHY(unit, port_info) || DNX_ALGO_PORT_TYPE_IS_OTN_PHY(unit, port_info))
    {
        _SHR_PBMP_COUNT(phys, nof_phys);
        if ((nof_phys > 1) && ((nof_phys % 2) != 0))
        {
            SHR_ERR_EXIT(_SHR_E_PARAM, "A %d-lane port is not supported.\n", nof_phys);
        }
        _SHR_PBMP_FIRST(phys, first_phy);
        table_index = first_phy / dnx_data_nif.eth.phy_map_granularity_get(unit);
        pm_index = dnx_data_nif.eth.phy_map_get(unit, table_index)->pm_index;
        pm_phys = dnx_data_nif.eth.pm_properties_get(unit, pm_index)->phys;
        _SHR_PBMP_FIRST(pm_phys, pm_lower_bound);
        if (((first_phy - pm_lower_bound) % nof_phys) != 0)
        {
            SHR_ERR_EXIT(_SHR_E_PARAM, "The first phy(%d) is illegal for a %d-lane port.\n", first_phy, nof_phys);
        }
    }
exit:
    SHR_FUNC_EXIT;
}
/*
 * See .h file
 */
shr_error_e
dnx_algo_port_nif_phy_verify(
    int unit,
    int nif_phy)
{
    bcm_pbmp_t supported_phys;

    SHR_FUNC_INIT_VARS(unit);

    if (nif_phy < 0 || nif_phy >= dnx_data_nif.phys.nof_phys_get(unit))
    {
        SHR_ERR_EXIT(_SHR_E_PARAM, "phy is out of bound - %d \n", nif_phy);
    }
    /*
     * Verify if phy is supported on SKU
     */
    supported_phys = dnx_data_nif.phys.general_get(unit)->supported_phys;
    if (!BCM_PBMP_MEMBER(supported_phys, nif_phy))
    {
        SHR_ERR_EXIT(_SHR_E_PARAM, "phy is not supported on this SKU - %d \n", nif_phy);
    }

exit:
    SHR_FUNC_EXIT;
}

/** See header file */
shr_error_e
dnx_algo_port_mc_add_verify(
    int unit,
    bcm_port_t logical_port,
    dnx_algo_port_info_s port_info,
    dnx_algo_port_common_add_t * common_info)
{
    SHR_FUNC_INIT_VARS(unit);

    if (dnx_data_egr_queuing_v1.general.feature_get(unit, dnx_data_egr_queuing_v1_general_v1_supported))
    {
    }
    else
    {
        /** fail with message that MC prefix is not supported for device */
        SHR_ERR_EXIT(_SHR_E_PARAM, "Device Arch does not support this option\n");
    }

exit:
    SHR_FUNC_EXIT;
}

/*
 * See .h file
 */
shr_error_e
dnx_algo_port_sch_add_verify(
    int unit,
    bcm_port_t logical_port,
    dnx_algo_port_info_s port_info,
    bcm_core_t core,
    dnx_algo_port_db_2d_handle_t interface_id,
    dnx_algo_port_tm_add_t * info)
{
    int sch_if_valid;
    bcm_port_t master_port;
    int if_priority_propagation_enable;
    int master_sch_priorities;
    dnx_algo_port_db_2d_handle_t sch_handle;
    int sch_handle_valid;

    SHR_FUNC_INIT_VARS(unit);

    if (DNX_ALGO_PORT_TYPE_IS_E2E_SCH(unit, port_info))
    {
        SHR_IF_ERR_EXIT(dnx_algo_port_db.sch_interface.
                        valid.get(unit, interface_id.h0, interface_id.h1, &sch_if_valid));
        if (sch_if_valid)
        {
            SHR_IF_ERR_EXIT(dnx_algo_port_db.sch_interface.
                            priority_propagation_enable.get(unit, interface_id.h0, interface_id.h1,
                                                            &if_priority_propagation_enable));

            if (info->sch_priority_propagation_enable != if_priority_propagation_enable)
            {
                SHR_ERR_EXIT(_SHR_E_PARAM,
                             "port (%d) priority propagation enable should be equal on all ports of the interface\n",
                             logical_port);

            }
            if (info->sch_priority_propagation_enable)
            {
                SHR_IF_ERR_EXIT(dnx_algo_port_db.sch_interface.
                                master_logical_port.get(unit, interface_id.h0, interface_id.h1, &master_port));
                SHR_IF_ERR_EXIT(dnx_algo_port_sch_priorities_nof_get(unit, master_port, &master_sch_priorities));
                if (info->sch_priorities != master_sch_priorities)
                {
                    SHR_ERR_EXIT(_SHR_E_PARAM,
                                 "port (%d) - in priority propagation mode, num of sch priorities should be equal on all ports of the interface\n",
                                 logical_port);
                }
            }
        }

        sch_handle.h0 = core;
        sch_handle.h1 = info->base_hr;

        SHR_IF_ERR_EXIT(dnx_algo_port_db.sch.ref_count.get(unit, sch_handle.h0, sch_handle.h1, &sch_handle_valid));
        if (sch_handle_valid)
        {
            SHR_IF_ERR_EXIT(dnx_algo_port_db.sch.sch_priorities.get(unit, sch_handle.h0, sch_handle.h1,
                                                                    &master_sch_priorities));
            if (master_sch_priorities != info->sch_priorities)
            {
                SHR_ERR_EXIT(_SHR_E_PARAM,
                             "port %d: sch exists with %d priorities. requested %d priorties.\n", logical_port,
                             master_sch_priorities, info->sch_priorities);
            }
        }

    }
exit:
    SHR_FUNC_EXIT;
}

/**
 * \brief -
 * Verify TSN related information
 *
 * \param [in] unit - Relevant unit.
 * \param [in] logical_port - required logical port.
 * \param [in] port_info - basic info about port.
 * \param [in] nif_handle - NIF interface handle
 * \param [in] eth_info - NIF Ethernet info
 *
 * \return
 *   see shr_error_e
 * \remark
 *   * None
 * \see
 *   * None
 */
static shr_error_e
dnx_algo_port_preemption_add_verify(
    int unit,
    bcm_port_t logical_port,
    dnx_algo_port_info_s port_info,
    int nif_handle,
    dnx_algo_port_nif_eth_add_t * eth_info)
{
    int valid;
    int frame_preemptable;

    SHR_FUNC_INIT_VARS(unit);

    SHR_IF_ERR_EXIT(dnx_algo_port_db.nif.valid.get(unit, nif_handle, &valid));

    if (valid)
    {
        /** channelized port */
        SHR_IF_ERR_EXIT(dnx_algo_port_db.nif.frame_preemptable.get(unit, nif_handle, &frame_preemptable));

        if (eth_info->frame_preemptable != frame_preemptable)
        {
            SHR_ERR_EXIT(_SHR_E_PARAM,
                         "port (%d) frame preemptable status should be equal on all ports of the interface\n",
                         logical_port);

        }
    }

exit:
    SHR_FUNC_EXIT;
}

/**
 * \brief -
 * Verify PLL 2x2 serdes setting limitations
 *
 * \param [in] unit - Relevant unit.
 * \param [in] logical_port - required logical port.
 * \param [in] port_info - basic info about port.
 * \param [in] phys - port phys bitmap.
 *
 * \return
 *   see shr_error_e
 * \remark
 *   * None
 * \see
 *   * None
 */
static shr_error_e
dnx_algo_port_pll_2x2_add_verify(
    int unit,
    bcm_port_t logical_port,
    dnx_algo_port_info_s port_info,
    bcm_pbmp_t phys)
{
    int phy, other_phy_in_pair, is_phy_active = FALSE;
    bcm_port_t logical_port_tmp;
    dnx_algo_port_info_s tmp_port_info;

    SHR_FUNC_INIT_VARS(unit);

    BCM_PBMP_ITER(phys, phy)
    {
        other_phy_in_pair = (phy % 2 == 0) ? (phy + 1) : (phy - 1);

        SHR_IF_ERR_EXIT(dnx_algo_port_nif_phy_active_get(unit, other_phy_in_pair, &is_phy_active));
        if (is_phy_active)
        {
            SHR_IF_ERR_EXIT(dnx_algo_port_nif_phy_to_logical_get(unit, other_phy_in_pair, 0, 0, &logical_port_tmp));
        }
        else
        {
            continue;
        }

        SHR_IF_ERR_EXIT(dnx_algo_port_info_get(unit, logical_port_tmp, &tmp_port_info));

        if ((DNX_ALGO_PORT_TYPE_IS_NIF_ILKN(unit, port_info, 0)
             && (!DNX_ALGO_PORT_TYPE_IS_NIF_ILKN(unit, tmp_port_info, 0)))
            || (!DNX_ALGO_PORT_TYPE_IS_NIF_ILKN(unit, port_info, 0)
                && (DNX_ALGO_PORT_TYPE_IS_NIF_ILKN(unit, tmp_port_info, 0))))
        {
            SHR_ERR_EXIT(_SHR_E_PARAM, "ILKN and Non-ILKN ports can't share same Serdes pair on same PLL.\n");
        }
    }

exit:
    SHR_FUNC_EXIT;
}

/*
 * See .h file
 */
shr_error_e
dnx_algo_port_common_add_verify(
    int unit,
    bcm_port_t logical_port,
    dnx_algo_port_info_s port_info,
    int if_id_h0,
    int if_id_h1,
    dnx_algo_port_common_add_t * info)
{
    int valid_interface;
    int is_channelized, is_ingress_interleave;
    dnx_algo_port_if_tdm_mode_e if_tdm_mode;

    SHR_FUNC_INIT_VARS(unit);

    SHR_IF_ERR_EXIT(dnx_algo_port_db.interface.valid.get(unit, if_id_h0, if_id_h1, &valid_interface));

    /** Channelized interface*/
    if (valid_interface)
    {
        /** Do not allow to add channels to non-channelized interface */
        SHR_IF_ERR_EXIT(dnx_algo_port_db.interface.is_channelized.get(unit, if_id_h0, if_id_h1, &is_channelized));
        if (!is_channelized)
        {
            SHR_ERR_EXIT(_SHR_E_PARAM, "port %d cannot be added existing non-channelized interface \n", logical_port);
        }

        /** is channelized */
        if (info->is_channelized != is_channelized)
        {
            SHR_ERR_EXIT(_SHR_E_PARAM,
                         "is_channelized attribute of port %d must match to all the ports over the interface \n",
                         logical_port);
        }

        SHR_IF_ERR_EXIT(dnx_algo_port_db.interface.
                        is_ingress_interleave.get(unit, if_id_h0, if_id_h1, &is_ingress_interleave));
        /** is ingress interleaved */
        if (info->is_ingress_interleave != is_ingress_interleave)
        {
            SHR_ERR_EXIT(_SHR_E_PARAM,
                         "is_ingress_interleave attribute of port %d must match to all the ports over the interface \n",
                         logical_port);
        }

        /** TDM interface mode */
        SHR_IF_ERR_EXIT(dnx_algo_port_db.interface.tdm_mode.get(unit, if_id_h0, if_id_h1, &if_tdm_mode));
        if (if_tdm_mode != info->if_tdm_mode)
        {
            SHR_ERR_EXIT(_SHR_E_PARAM,
                         "if_tdm_mode attribute of port %d must match to all the ports over the interface \n",
                         logical_port);
        }
    }

exit:
    SHR_FUNC_EXIT;
}

/*
 * See .h file
 */
shr_error_e
dnx_algo_port_tm_add_verify(
    int unit,
    bcm_port_t logical_port,
    dnx_algo_port_info_s port_info,
    int if_id_h0,
    int if_id_h1,
    dnx_algo_port_tm_add_t * info)
{
    int valid_tm_interface;
    int is_egress_interleave, egress_interface, if_master_port;
    dnx_algo_port_info_s master_port_info;

    SHR_FUNC_INIT_VARS(unit);

    /*
     * If tm_interface_id is allocated -
     * assume that it's channelized interface with already configured interface
     */
    SHR_IF_ERR_EXIT(dnx_algo_port_db.tm_interface.valid.get(unit, if_id_h0, if_id_h1, &valid_tm_interface));

    /** Channelized interface*/
    if (valid_tm_interface)
    {
        SHR_IF_ERR_EXIT(dnx_algo_port_db.tm_interface.
                        master_logical_port.get(unit, if_id_h0, if_id_h1, &if_master_port));
        SHR_IF_ERR_EXIT(dnx_algo_port_db.logical.info.get(unit, if_master_port, &master_port_info));

        if (!DNX_ALGO_PORT_TYPE_IS_L1(unit, port_info) && !DNX_ALGO_PORT_TYPE_IS_L1(unit, master_port_info))
        {
            /** is egress interleave */
            SHR_IF_ERR_EXIT(dnx_algo_port_db.tm_interface.
                            is_egress_interleave.get(unit, if_id_h0, if_id_h1, &is_egress_interleave));
            if (info->is_egress_interleave != is_egress_interleave)
            {
                SHR_ERR_EXIT(_SHR_E_PARAM,
                             "is_egress_interleave attribute of port %d must match to all the ports over the interface \n",
                             logical_port);
            }
            /** egress interface */
            SHR_IF_ERR_EXIT(dnx_algo_port_db.tm_interface.egr_if.get(unit, if_id_h0, if_id_h1, &egress_interface));
            if (egress_interface != info->egress_interface)
            {
                SHR_ERR_EXIT(_SHR_E_PARAM,
                             "egress_interface attribute of port %d must match to all the ports over the interface \n",
                             logical_port);
            }
        }
    }

exit:
    SHR_FUNC_EXIT;
}

/*
 * See .h file
 */
shr_error_e
dnx_algo_port_nif_add_verify(
    int unit,
    bcm_port_t logical_port,
    dnx_algo_port_info_s port_info,
    dnx_algo_port_if_add_t * info)
{
    int first_phy, first_phy_wo_fabric_offset;
    int nif_handle;
    int valid;
    bcm_port_t master_port;
    dnx_algo_port_info_s master_port_info;
    int master_interface_offset;
    bcm_pbmp_t master_phys;
    int phy;
    uint32 is_over_fabric = 0;
    dnx_algo_port_db_2d_handle_t interface_id;
    dnx_algo_lane_map_type_e lane_map_type;

    SHR_FUNC_INIT_VARS(unit);

    if (DNX_ALGO_PORT_TYPE_IS_NIF_ILKN(unit, port_info, DNX_ALGO_PORT_TYPE_INCLUDE(ELK, L1)))
    {
        is_over_fabric = info->ilkn_info.is_ilkn_over_fabric;
    }

    /*
     * Check if master port or not
     */

    _SHR_PBMP_FIRST(info->phys, first_phy);
    first_phy_wo_fabric_offset = first_phy;
    if (is_over_fabric)
    {
        SHR_IF_ERR_EXIT(dnx_algo_port_fabric_phy_verify(unit, first_phy));

        /** Add fabric links offset for NIF DB handle */
        first_phy += dnx_data_port.general.fabric_phys_offset_get(unit);
    }
    else
    {
        SHR_IF_ERR_EXIT(dnx_algo_port_nif_phy_verify(unit, first_phy));
    }

    nif_handle = first_phy;

    SHR_IF_ERR_EXIT(dnx_algo_port_db.nif.valid.get(unit, nif_handle, &valid));

    if (valid)
    {
        /** NIF ETH L1 or FlexE PHY or OTN PHY port shouldn't be channelized */
        if (DNX_ALGO_PORT_TYPE_IS_NIF_ETH_L1(unit, port_info, TRUE)
            || DNX_ALGO_PORT_TYPE_IS_FLEXE_PHY(unit, port_info, TRUE) || DNX_ALGO_PORT_TYPE_IS_OTN_PHY(unit, port_info))
        {
            SHR_ERR_EXIT(_SHR_E_INTERNAL, "port (%d) is not allowed to be channelized.\n", logical_port);
        }

        /*
         * i.e. channelized port
         */
        /** make sure that channel is defined */
        if (info->common_info.in_channel == -1 || info->common_info.out_channel == -1)
        {
            SHR_ERR_EXIT(_SHR_E_INTERNAL, "port (%d) is channelized. expecting channel != -1 .\n", logical_port);
        }

        /*
         *  Make sure that indeed the already defined port is identical
         */

        SHR_IF_ERR_EXIT(dnx_algo_port_db.nif.master_logical_port.get(unit, nif_handle, &master_port));

        /** port type */
        SHR_IF_ERR_EXIT(dnx_algo_port_db.logical.info.get(unit, master_port, &master_port_info));
        if ((port_info.port_type != master_port_info.port_type)
            && !DNX_ALGO_PORT_TYPE_IS_NIF_ILKN(unit, master_port_info, DNX_ALGO_PORT_TYPE_INCLUDE(L1)))
        {
            SHR_ERR_EXIT(_SHR_E_INTERNAL,
                         "port (%d) is channelized. expecting identical port type to master port (%d).\n",
                         logical_port, master_port);
        }
        /** interface offset */
        SHR_IF_ERR_EXIT(dnx_algo_port_db.logical.interface_offset.get(unit, master_port, &master_interface_offset));
        if (info->interface_offset != master_interface_offset)
        {
            SHR_ERR_EXIT(_SHR_E_INTERNAL,
                         "port (%d) is channelized. expecting identical interface offset to master port (%d).\n",
                         logical_port, master_port);
        }
        /** phys */

        SHR_IF_ERR_EXIT(dnx_algo_port_db.nif.phys.get(unit, nif_handle, &master_phys));

        if (!BCM_PBMP_EQ(info->phys, master_phys))
        {
            SHR_ERR_EXIT(_SHR_E_INTERNAL, "port (%d) is channelized. expecting identical phys to master port (%d).\n",
                         logical_port, master_port);
        }
    }
    else
    { /** i.e. master port */

        /*
         * Make sure that no one else is using those phys
         */
        if (!is_over_fabric)
        {
            SHR_IF_ERR_EXIT(dnx_algo_port_nif_phys_verify(unit, logical_port, port_info, info->phys));
        }
        else
        {
            SHR_IF_ERR_EXIT(dnx_algo_port_ilkn_over_fabric_phys_verify(unit, logical_port, info->phys));
        }

        /** Lane Map verify, make sure all the lanes have been mapped and Lane map boundaries are correct*/

        lane_map_type = is_over_fabric ? DNX_ALGO_LANE_MAP_FABRIC_SIDE : DNX_ALGO_LANE_MAP_NIF_SIDE;

        if (!dnx_data_dev_init.general.access_only_get(unit) && !dnx_data_dev_init.general.heat_up_get(unit))
        {
            {
                BCM_PBMP_ITER(info->phys, phy)
                {
                    SHR_IF_ERR_EXIT(dnx_algo_lane_map_port_add_verify
                                    (unit, lane_map_type, port_info, is_over_fabric, phy));
                }
            }
        }
    }
    SHR_IF_ERR_EXIT(dnx_algo_port_stif_verify
                    (unit, logical_port, port_info, first_phy_wo_fabric_offset, is_over_fabric));

    if (DNX_ALGO_PORT_TYPE_IS_E2E_SCH(unit, port_info))
    {
        SHR_IF_ERR_EXIT(dnx_algo_port_db_interface_id_get(unit, port_info, info->core, info->interface_offset,
                                                          &info->phys, -1, &interface_id.h0, &interface_id.h1));
        SHR_IF_ERR_EXIT(dnx_algo_port_sch_add_verify(unit, logical_port, port_info, info->core, interface_id,
                                                     &info->tm_info));
    }

    if (DNX_ALGO_PORT_TYPE_IS_MC(unit, port_info))
    {
        SHR_IF_ERR_EXIT(dnx_algo_port_mc_add_verify(unit, logical_port, port_info, &info->common_info));
    }

    if (DNX_ALGO_PORT_TYPE_IS_NIF_ETH(unit, port_info, 0))
    {
        SHR_IF_ERR_EXIT(dnx_algo_port_preemption_add_verify(unit, logical_port, port_info, first_phy, &info->eth_info));
    }

    /*
     * In case BH 2x2 is supported check that on the same 2x2 serdes pair there is no ILKN and non-ILKN port
     */
    if ((DNX_ALGO_PORT_TYPE_IS_NIF(unit, port_info, 0))
        && (dnx_data_nif.global.feature_get(unit, dnx_data_nif_global_bh_2x2_supported)))
    {
        SHR_IF_ERR_EXIT(dnx_algo_port_pll_2x2_add_verify(unit, logical_port, port_info, info->phys));
    }

exit:
    SHR_FUNC_EXIT;
}

/*
 * See .h file
 */
shr_error_e
dnx_algo_port_tdm_mode_supported_verify(
    int unit,
    dnx_algo_port_tdm_mode_e tdm_mode)
{
    SHR_FUNC_INIT_VARS(unit);

    /*
     * Verify that tdm mode is supported.
     * When new device. more sophisticated verify will be requried (using dnx data).
     */
    if (tdm_mode < 0 || tdm_mode >= DNX_ALGO_PORT_TDM_MODE_NOF)
    {
        SHR_ERR_EXIT(_SHR_E_PARAM, "TDM mode is not supported - %d.\n", tdm_mode);
    }

exit:
    SHR_FUNC_EXIT;
}

/*
 * See .h file
 */
shr_error_e
dnx_algo_port_sch_if_id_verify(
    int unit,
    int if_id)
{
    SHR_FUNC_INIT_VARS(unit);

    /*
     * Verify that sch interface id is valid.
     * Assuming there are no overlaps (skip this check)
     */
    if (if_id < 0 || if_id >= dnx_data_sch.interface.nof_sch_interfaces_get(unit))
    {
        SHR_ERR_EXIT(_SHR_E_PARAM, "SCH interface id is not supported - %d.\n", if_id);
    }

exit:
    SHR_FUNC_EXIT;
}

/*
 * See .h file
 */
shr_error_e
dnx_algo_port_channel_free_verify(
    int unit,
    bcm_port_t logical_port,
    dnx_algo_port_db_2d_handle_t interface_handle,
    int channel,
    int is_out)
{
    int interface_valid;
    bcm_port_t master_logical_port, logical_port_channel;
    int channel_id;
    bcm_pbmp_t logical_port_channels;
    SHR_FUNC_INIT_VARS(unit);

    /** verify range */
    SHR_RANGE_VERIFY(channel, 0, dnx_data_port.general.max_nof_channels_get(unit) - 1,
                     _SHR_E_PARAM, "channel ID out of range for port %d.\n", logical_port);

    /** verify handle */
    DNX_ALGO_PORT_2D_HANDLE_VERIFY(interface_handle);
    SHR_IF_ERR_EXIT(dnx_algo_port_db.interface.
                    valid.get(unit, interface_handle.h0, interface_handle.h1, &interface_valid));
    if (interface_valid)
    {
        /** get master port of the same interface */
        SHR_IF_ERR_EXIT(dnx_algo_port_db.interface.
                        master_logical_port.get(unit, interface_handle.h0, interface_handle.h1, &master_logical_port));

        /** get all channels */
        SHR_IF_ERR_EXIT(dnx_algo_port_channels_get(unit, master_logical_port, 0, &logical_port_channels));
        /** remove new port */
        BCM_PBMP_PORT_REMOVE(logical_port_channels, logical_port);

        /** iterate over ports and make sure channels is not used */
        BCM_PBMP_ITER(logical_port_channels, logical_port_channel)
        {
            if (is_out)
            {
                SHR_IF_ERR_EXIT(dnx_algo_port_out_channel_get(unit, logical_port_channel, &channel_id));
            }
            else
            {
                SHR_IF_ERR_EXIT(dnx_algo_port_in_channel_get(unit, logical_port_channel, &channel_id));

            }
            if (channel_id == channel)
            {
                SHR_ERR_EXIT(_SHR_E_PARAM, "Adding port %d %s channel %d is already used by logical port %d.\n",
                             logical_port, (is_out ? "out" : "in"), channel, logical_port_channel);
            }
        }
    }
    else
    {
        /** do nothing the interface is not used */
    }

exit:
    SHR_FUNC_EXIT;
}
/*
 * See .h file
 */
shr_error_e
dnx_algo_port_special_interface_offset_verify(
    int unit,
    dnx_algo_port_info_s port_info,
    int interface_offset)
{
    SHR_FUNC_INIT_VARS(unit);

    if (dnx_data_egr_queuing_v1.general.feature_get(unit, dnx_data_egr_queuing_v1_general_v1_supported))
    {
    }
    else
    {
        if (DNX_ALGO_PORT_TYPE_IS_RCY(unit, port_info))
        {
            SHR_RANGE_VERIFY(interface_offset, -1, dnx_data_egr_queuing.params.nof_egr_rcy_interfaces_get(unit) - 1,
                             _SHR_E_PARAM, "interface offset %d is not expected.\n", interface_offset);
        }
        else if (DNX_ALGO_PORT_TYPE_IS_OLP(unit, port_info))
        {
            SHR_RANGE_VERIFY(interface_offset, -1, dnx_data_egr_queuing.params.nof_egr_olp_interfaces_get(unit) - 1,
                             _SHR_E_PARAM, "interface offset %d is not expected.\n", interface_offset);
        }
        else
        {
            SHR_RANGE_VERIFY(interface_offset, -1, -1,
                             _SHR_E_PARAM, "interface offset %d is not expected. (should be set to -1)\n",
                             interface_offset);
        }
    }

exit:
    SHR_FUNC_EXIT;

}

/*
 * See .h file
 */
shr_error_e
dnx_algo_port_stif_verify(
    int unit,
    bcm_port_t port,
    dnx_algo_port_info_s port_info,
    int first_phy,
    int is_over_fabric)
{
    int lane_idx;
    int is_stif;
    int first_lane_in_ethu, nof_lanes_in_ethu;
    bcm_port_t temp_logical_port;
    dnx_algo_port_info_s temp_port_info;
    SHR_FUNC_INIT_VARS(unit);
    if (dnx_data_stif.config.feature_get(unit, dnx_data_stif_config_mixing_ports_limitation) == TRUE)
    {
        if (DNX_ALGO_PORT_TYPE_IS_NIF
            (unit, port_info, DNX_ALGO_PORT_TYPE_INCLUDE(ELK, STIF, L1, FLEXE, MGMT, FRAMER_MGMT)))
        {
            is_stif = DNX_ALGO_PORT_TYPE_IS_NIF_ETH_STIF(unit, port_info);
            SHR_IF_ERR_EXIT(dnx_algo_phy_ethu_lane_info_get(unit, first_phy, &first_lane_in_ethu, &nof_lanes_in_ethu));

            for (lane_idx = 0; lane_idx < nof_lanes_in_ethu; lane_idx++)
            {
                SHR_IF_ERR_EXIT(dnx_algo_port_nif_phy_to_logical_get
                                (unit, (first_lane_in_ethu + lane_idx), is_over_fabric, 0, &temp_logical_port));
                if (temp_logical_port != DNX_ALGO_PORT_INVALID)
                {
                    SHR_IF_ERR_EXIT(dnx_algo_port_info_get(unit, temp_logical_port, &temp_port_info));
                    if (is_stif != DNX_ALGO_PORT_TYPE_IS_NIF_ETH_STIF(unit, temp_port_info))
                    {
                        SHR_ERR_EXIT(_SHR_E_PARAM,
                                     "Mixing STIF and none STIF ports in the same eth unit (CDU/CLU) is not allowed. ports: {%d,%d} \n",
                                     port, temp_logical_port);
                    }
                }
            }
        }
    }
exit:
    SHR_FUNC_EXIT;
}

/*
 * See .h file
 */
shr_error_e
dnx_algo_port_tdm_usage_verify(
    int unit,
    int tdm_is_set)
{
    SHR_FUNC_INIT_VARS(unit);

    /** verify is_tdm */
    if (tdm_is_set)
    {
        if (!dnx_data_tdm.params.feature_get(unit, dnx_data_tdm_params_is_supported))
        {
            SHR_ERR_EXIT(_SHR_E_PARAM, "TDM is not supported by device\n");
        }
        if (dnx_data_tdm.params.mode_get(unit) == TDM_MODE_NONE)
        {
            SHR_ERR_EXIT(_SHR_E_PARAM, "TDM parameter shouldn't be used when TDM is disabled!\n");
        }
    }
exit:
    SHR_FUNC_EXIT;
}
