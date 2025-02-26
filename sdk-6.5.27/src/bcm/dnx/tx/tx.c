/** \file tx.c
 * 
 *
 * TX procedures for DNX.
 *
 * Here add DESCRIPTION.
 */
/*
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2022 Broadcom Inc. All rights reserved.
 */
#ifdef BSL_LOG_MODULE
#error "BSL_LOG_MODULE redefined"
#endif
#define BSL_LOG_MODULE BSL_LS_BCMDNX_TX
/*
 * Include files which are specifically for DNX. Final location.
 * {
 */
#include <soc/sand/shrextend/shrextend_debug.h>
#include <bcm_int/common/tx.h>
/*
 * }
 */
/*
 * Include files currently used for DNX. To be modified and moved to
 * final location.
 * {
 */
#include <shared/bslenum.h>
#include <bcm/types.h>
#include <bcm/tx.h>
#include <soc/dnx/dnx_data/auto_generated/dnx_data_adapter.h>
#include <soc/dnx/dnx_data/auto_generated/dnx_data_device.h>
#include <soc/dnx/dnx_visibility.h>
#include <soc/dnx/dnx_err_recovery_manager.h>
#include <soc/dnx/swstate/auto_generated/access/dnx_rx_access.h>
#include <soc/dnx/dbal/dbal.h>
#ifdef ADAPTER_SERVER_MODE
#include <soc/sand/sand_signals.h>
#include <soc/dnxc/dnxc_adapter_reg_access.h>
#include <soc/cm.h>
#endif

#ifdef BCM_ACCESS_SUPPORT
#include <soc/access/access.h>
#include <soc/access/pkt_tx.h>
#endif

/*
 * }
 */

/*
 * Macros and definitions
 * {
 */

/*
 * Min packet length in bytes
 */
#define MIN_PACKET_LENGTH_NO_CRC   60
/*
 * CRC size in bytes
 */
#define PACKET_LENGTH_CRC_SIZE     4
/*
 * Min packet length, include CRC. in bytes
 */
#define MIN_PACKET_LENGTH_WITH_CRC (MIN_PACKET_LENGTH_NO_CRC + PACKET_LENGTH_CRC_SIZE)
/*
 * Channel is always derived from table PktSrcToChannelMap.
 */
#define CPU_CHANNEL_SOURCE_0        0x0
/*
 * Channel is derived from module header (if exists) or from table PktSrcToChannelMap.
 */
#define CPU_CHANNEL_SOURCE_1        0x1
/*
 * Channel is derived from module header (if exists) or from register CpuChannel.
 */
#define CPU_CHANNEL_SOURCE_2        0x2
/*
 * Channel is always derived register CpuChannel.
 */
#define CPU_CHANNEL_SOURCE_3        0x3

/*
 * }
 */

int
bcm_dnx_tx(
    int unit,
    bcm_pkt_t * pkt,
    void *cookie)
{
#ifdef ADAPTER_SERVER_MODE
    uint32 adapter_loopback_enable;
    adapter_ms_id_e ms_id = ADAPTER_MS_ID_FIRST_MS;
    int packet_size = pkt->pkt_data->len;
    int packet_orig_size = pkt->pkt_data->len;
    uint8 *adapter_pkt_data_p = NULL;
    uint8 *adapter_orig_pkt_data_p = pkt->pkt_data->data;
    int adapter_units_num;
#endif

    SHR_FUNC_INIT_VARS(unit);

    DNX_ERR_RECOVERY_NOT_NEEDED(unit);

    /*
     * Clear Debug Signals Memory - return status irrelevant
     */
    if (!(pkt->flags & BCM_TX_NO_VISIBILITY_RESUME))
    {
        dnx_visibility_resume(unit, BCM_CORE_ALL,
                              BCM_INSTRU_CONTROL_FLAG_DIRECTION_INGRESS | BCM_INSTRU_CONTROL_FLAG_DIRECTION_EGRESS);
    }

#ifdef ADAPTER_SERVER_MODE
    /** clearing the signals cache is made for all units, */
    /** in order to support packet transmitted between units. (multi device scenario) */
    /** in adapter all units ordered from zero to nof devices */
    /** in addition, it is assume that when nof_sub_units > 1, there is only single unit. */
    adapter_units_num = (dnx_data_device.general.nof_core_groups_get(unit) > 1) ? 1 : soc_cm_get_num_devices();
    for (int i = 0; i < adapter_units_num; i++)
    {
        sand_adapter_clear_signals(i);
    }

    /** Gets the value of the adapter_loopback_enable from the dnx_data */
    adapter_loopback_enable = dnx_data_adapter.tx.loopback_enable_get(unit);

    if (adapter_loopback_enable == 1)
    {
        ms_id = ADAPTER_MS_ID_LOOPBACK;
    }

    /*
     * Use a different flow for sending a packet in adapter.
     * Support the CRC flags and the NO_PAD flag, in order to keep same behavior like on chip
     */
    if (!_SHR_IS_FLAG_SET(pkt->flags, BCM_TX_NO_PAD) && (pkt->pkt_data->len < MIN_PACKET_LENGTH_WITH_CRC))
    {
        packet_size = MIN_PACKET_LENGTH_WITH_CRC;
    }
    if (_SHR_IS_FLAG_SET(pkt->flags, BCM_TX_CRC_REGEN) && !_SHR_IS_FLAG_SET(pkt->flags, BCM_TX_CRC_ALLOC))
    {
        packet_size -= PACKET_LENGTH_CRC_SIZE;
    }

    if (packet_size <= pkt->pkt_data->len)
    {
        pkt->pkt_data->len = packet_size;
    }
    else
    {
        SHR_ALLOC_SET_ZERO_ERR_EXIT(adapter_pkt_data_p, packet_size, "adapter_pkt_data_p", "%s%s%s", EMPTY, EMPTY,
                                    EMPTY);
        adapter_orig_pkt_data_p = pkt->pkt_data->data;
        pkt->pkt_data->data = adapter_pkt_data_p;
        sal_memcpy(adapter_pkt_data_p, adapter_orig_pkt_data_p, pkt->pkt_data->len);
        pkt->pkt_data->len = packet_size;
    }

    SHR_IF_ERR_EXIT(adapter_send_buffer(unit, (uint32) ms_id, (uint32) (pkt->src_gport),
                                        pkt->pkt_data->len, pkt->pkt_data->data, 1));

    pkt->pkt_data->len = packet_orig_size;
    pkt->pkt_data->data = adapter_orig_pkt_data_p;
    SHR_FREE(adapter_pkt_data_p);

#else

    /** Regular TX handling */
    SHR_NULL_CHECK(pkt, _SHR_E_PARAM, "pointer to pkt is not valid");

#ifdef BCM_ACCESS_SUPPORT
    if (ACCESS_IS_INITIALIZED(unit))
    {
        SHR_IF_ERR_EXIT(bcm_access_tx(unit, pkt, cookie));
    }
    else
#endif
    {
        SHR_IF_ERR_EXIT(bcm_common_tx(unit, pkt, cookie));
    }

#endif

exit:
#ifdef ADAPTER_SERVER_MODE
    SHR_FREE(adapter_pkt_data_p);
#endif
    SHR_FUNC_EXIT;
}

/**
 * \brief
 *   Transmit an array of packets
 * \par DIRECT INPUT:
 *   \param [in] unit  -  Unit ID
 *   \param [in] pkt  -  array of pointers to packets to transmit
 *   \param [in] count  -  Number of packets in the array
 *   \param [in] all_done_cb  -  Chain done callback function
 *   \param [in] cookie  -  Callback cookie
 * \par INDIRECT INPUT:
 *   * None
 * \par DIRECT OUTPUT:
 *   shr_error_e - Error Type
 * \par INDIRECT OUTPUT:
 *   * None
 * \remark
 *   Packets are sent synchronously
 * \see
 *   * None
 */
int
bcm_dnx_tx_array(
    int unit,
    bcm_pkt_t ** pkt,
    int count,
    bcm_pkt_cb_f all_done_cb,
    void *cookie)
{
    SHR_FUNC_INIT_VARS(unit);
    DNX_ERR_RECOVERY_NOT_NEEDED(unit);

#ifdef BCM_ACCESS_SUPPORT
    if (ACCESS_IS_INITIALIZED(unit))
    {
        SHR_IF_ERR_EXIT(BCM_E_UNAVAIL);
    }
    else
#endif
    {
        SHR_IF_ERR_EXIT(bcm_common_tx_array(unit, pkt, count, all_done_cb, cookie));
    }

exit:
    SHR_FUNC_EXIT;
}

/**
 * \brief
 *   Transmit a linked list of packets
 * \par DIRECT INPUT:
 *   \param [in] unit  -  Unit ID
 *   \param [in] pkt  -  Pointer to linked list of packets
 *   \param [in] all_done_cb  -  Chain done callback function
 *   \param [in] cookie  -  Callback cookie
 * \par INDIRECT INPUT:
 *   * None
 * \par DIRECT OUTPUT:
 *   shr_error_e - Error Type
 * \par INDIRECT OUTPUT:
 *   * None
 * \remark
 *   Packets are sent synchronously
 * \see
 *   * None
 */
int
bcm_dnx_tx_list(
    int unit,
    bcm_pkt_t * pkt,
    bcm_pkt_cb_f all_done_cb,
    void *cookie)
{
    SHR_FUNC_INIT_VARS(unit);
    DNX_ERR_RECOVERY_NOT_NEEDED(unit);

#ifdef BCM_ACCESS_SUPPORT
    if (ACCESS_IS_INITIALIZED(unit))
    {
        SHR_IF_ERR_EXIT(BCM_E_UNAVAIL);
    }
    else
#endif
    {
        SHR_IF_ERR_EXIT(bcm_common_tx_list(unit, pkt, all_done_cb, cookie));
    }

exit:
    SHR_FUNC_EXIT;
}

#if defined(BROADCOM_DEBUG)
/**
 * \brief
 *   Display info about tx state
 * \par DIRECT INPUT:
 *   \param [in] unit  -  Unit ID
 * \par INDIRECT INPUT:
 *   * None
 * \par DIRECT OUTPUT:
 *   shr_error_e - Error Type
 * \par INDIRECT OUTPUT:
 *   * None
 * \remark
 *   * None
 * \see
 *   * None
 */
int
bcm_dnx_tx_show(
    int unit)
{
    SHR_FUNC_INIT_VARS(unit);
    DNX_ERR_RECOVERY_NOT_NEEDED(unit);

#ifdef BCM_ACCESS_SUPPORT
    if (ACCESS_IS_INITIALIZED(unit))
    {
        SHR_IF_ERR_EXIT(bcm_access_tx_show(unit));
    }
    else
#endif
    {
        SHR_IF_ERR_EXIT(bcm_common_tx_show(unit));
    }

exit:
    SHR_FUNC_EXIT;
}

/**
 * \brief
 *   Display info about a DV that is setup for TX
 * \par DIRECT INPUT:
 *   \param [in] unit  -  Unit ID
 *   \param [in] dv    -  The DV to show info about
 * \par INDIRECT INPUT:
 *   * None
 * \par DIRECT OUTPUT:
 *   shr_error_e - Error Type
 * \par INDIRECT OUTPUT:
 *   * None
 * \remark
 *   * Mainly, dumps the tx_dv_info_t structure; then calls soc_dma_dump_dv
 * \see
 *   * None
 */
int
bcm_dnx_tx_dv_dump(
    int unit,
    void *dv_p)
{
    SHR_FUNC_INIT_VARS(unit);
    DNX_ERR_RECOVERY_NOT_NEEDED(unit);

    SHR_NULL_CHECK(dv_p, _SHR_E_PARAM, "dv_p");
#ifdef BCM_ACCESS_SUPPORT
    if (ACCESS_IS_INITIALIZED(unit))
    {
        SHR_IF_ERR_EXIT(bcm_access_tx_dv_dump(unit, dv_p));
    }
    else
#endif
    {
        SHR_IF_ERR_EXIT(bcm_common_tx_dv_dump(unit, dv_p));
    }

exit:
    SHR_FUNC_EXIT;
}
#endif

/**
 * \brief
 *   Initialize BCM TX API
 * \par DIRECT INPUT:
 *   \param [in] unit  -  Unit ID
 * \par INDIRECT INPUT:
 *   * None
 * \par DIRECT OUTPUT:
 *   shr_error_e - Error Type
 * \par INDIRECT OUTPUT:
 *   * None
 * \remark
 *   Please see bcm_common_tx_init
 * \see
 *   * None
 */
shr_error_e
dnx_tx_init(
    int unit)
{
    uint32 entry_handle_id;

    SHR_FUNC_INIT_VARS(unit);
    DBAL_FUNC_INIT_VARS(unit);

#ifdef BCM_ACCESS_SUPPORT
    if (ACCESS_IS_INITIALIZED(unit))
    {
        SHR_IF_ERR_EXIT(bcm_access_tx_init(unit));
    }
    else
#endif
    {
        SHR_IF_ERR_EXIT(bcm_common_tx_init(unit));
    }

    /*
     * JR2 and above - CPU channel derived from module header (if exists), otherwise 0
     */
    if (!sw_state_is_warm_boot(unit))
    {
        SHR_IF_ERR_EXIT(DBAL_HANDLE_ALLOC(unit, DBAL_TABLE_SYSTEM_CPU_CHANNEL_CONFIGURATION, &entry_handle_id));
        dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_CPU_CHANNEL_SELECT, INST_SINGLE,
                                     CPU_CHANNEL_SOURCE_2);
        dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_CPU_CHANNEL, INST_SINGLE, 0);
        SHR_IF_ERR_EXIT(dbal_entry_commit(unit, entry_handle_id, DBAL_COMMIT));
    }

exit:
    DBAL_FUNC_FREE_VARS;
    SHR_FUNC_EXIT;
}

/**
 * \brief
 *   De-initialize BCM TX API
 * \par DIRECT INPUT:
 *   \param [in] unit  -  Unit ID
 * \par INDIRECT INPUT:
 *   * None
 * \par DIRECT OUTPUT:
 *   shr_error_e - Error Type
 * \par INDIRECT OUTPUT:
 *   * None
 * \remark
 *   free resource allocated in bcm_tx_init
 * \see
 *   * None
 */
shr_error_e
dnx_tx_deinit(
    int unit)
{
    SHR_FUNC_INIT_VARS(unit);

#ifdef BCM_ACCESS_SUPPORT
    if (ACCESS_IS_INITIALIZED(unit))
    {
        SHR_IF_ERR_EXIT(bcm_access_tx_deinit(unit));
    }
    else
#endif
    {
        SHR_IF_ERR_EXIT(bcm_common_tx_deinit(unit));
    }

exit:
    SHR_FUNC_EXIT;
}
