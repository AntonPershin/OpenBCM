/**
 * \file fabric_mesh.c $Id$ Fabric Mesh Configuration for DNX.
 */

#ifdef BSL_LOG_MODULE
#error "BSL_LOG_MODULE redefined"
#endif
#define BSL_LOG_MODULE BSL_LS_BCMDNX_FABRIC

#include <soc/sand/shrextend/shrextend_debug.h>
#include <bcm/error.h>
#include <bcm/fabric.h>
#include <bcm/types.h>

#include <bcm_int/common/multicast.h>

#include <bcm_int/dnx/auto_generated/dnx_stk_dispatch.h>
#include <bcm_int/dnx/cmn/dnxcmn.h>
#include <bcm_int/dnx/stk/stk_sys.h>
#include <bcm_int/dnx/fabric/fabric.h>
#include <bcm_int/dnx/fabric/fabric_mesh.h>
#include <bcm_int/dnx/port/port.h>
#include <bcm_int/dnx/tdm/tdm.h>
#include <bcm_int/dnx/algo/port/algo_port_mgmt.h>

#include <soc/dnx/swstate/auto_generated/access/dnx_fabric_access.h>
#include <soc/dnx/dnx_err_recovery_manager.h>

#include <shared/utilex/utilex_u64.h>
#include <soc/dnx/dnx_data/auto_generated/dnx_data_fabric.h>
#include <soc/dnx/dnx_data/auto_generated/dnx_data_tdm.h>
#include <soc/sand/sand_aux_access.h>

#include <soc/dnx/dbal/dbal.h>
#include <soc/dnx/dbal/auto_generated/dbal_defines_fields.h>
#include <soc/dnx/dbal/auto_generated/dbal_defines_tables.h>

#define DNX_FABRIC_SYS_FREQ_RES_19 (1 << 19)

/**
 * \brief
 *   Verify local destination id, which is actually the group id
 *   after removing the group's bit using BCM_FABRIC_GROUP_MODID_UNSET.
 * \param [in] unit         - *   The unit number.
 * \param [in] destination  - *   Destination, that should be group.
 * \return
 *   See \ref shr_error_e
 * \remark
 *   * None.
 * \see
 *   * None.
 */
static shr_error_e
dnx_fabric_local_dest_id_verify(
    int unit,
    bcm_module_t destination)
{
    bcm_module_t local_dest_id;
    SHR_FUNC_INIT_VARS(unit);

    if (!BCM_FABRIC_MODID_IS_GROUP(destination))
    {
        SHR_ERR_EXIT(_SHR_E_PARAM, "destination should be a group");
    }
    local_dest_id = BCM_FABRIC_GROUP_MODID_UNSET(destination);

    if (local_dest_id < 0)
    {
        SHR_ERR_EXIT(_SHR_E_PARAM, "invalid dest_id");
    }

    if (local_dest_id >= dnx_data_fabric.mesh.nof_dest_get(unit))
    {
        int is_mesh_mc = dnx_data_fabric.mesh.multicast_enable_get(unit);

        SHR_ERR_EXIT(_SHR_E_PARAM, "in %s mode there can only be %d destinations",
                     (is_mesh_mc ? "Mesh MC" : "Mesh"), dnx_data_fabric.mesh.nof_dest_get(unit));
    }

exit:
    SHR_FUNC_EXIT;
}

/*
 * See .h file.
 */
shr_error_e
dnx_fabric_mesh_init(
    int unit)
{
    uint32 entry_handle_id;
    uint32 is_mesh = dnx_data_fabric.general.connect_mode_get(unit) != DNX_FABRIC_CONNECT_MODE_FE;
    uint32 is_mesh_mc = dnx_data_fabric.mesh.multicast_enable_get(unit);
    uint32 max_nof_dest = dnx_data_fabric.mesh.max_nof_dest_get(unit);
    SHR_FUNC_INIT_VARS(unit);
    DBAL_FUNC_INIT_VARS(unit);

    SHR_IF_ERR_EXIT(DBAL_HANDLE_ALLOC(unit, DBAL_TABLE_FABRIC_MESH_CONFIG, &entry_handle_id));

    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_MESH_MODE, INST_SINGLE, is_mesh ? 1 : 0);
    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_MESH_MC_ENABLE, INST_SINGLE,
                                 (is_mesh && !is_mesh_mc) ? 0 : 1);
    if (!dnx_data_fabric.tdm.feature_get(unit, dnx_data_fabric_tdm_blocks_dont_exist))
    {
        dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_MESH_MC_BMP_TDM_SRC, INST_SINGLE, 1);
    }
    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_MESH_MULTI_FAP, INST_SINGLE, is_mesh ? 1 : 0);
    SHR_IF_ERR_EXIT(dbal_entry_commit(unit, entry_handle_id, DBAL_COMMIT));

    /*
     * Configuration for destination devices in FCT for MESH mode is needed in order
     * to have a correct link load balancing for the control cells.
     * It is not needed when only single destination device is supported.
     */
    if (is_mesh && max_nof_dest > 1)
    {
        int dest_group_id;
        uint32 invalid_modid = dnx_data_device.general.invalid_fap_id_get(unit);
        uint32 nof_dest_group_id = dnx_data_fabric.mesh.max_nof_dest_get(unit);

        for (dest_group_id = 0; dest_group_id < nof_dest_group_id; ++dest_group_id)
        {
            SHR_IF_ERR_EXIT(dnx_fabric_mesh_device_id_dest_set(unit, dest_group_id, 0, invalid_modid));
        }
    }

exit:
    DBAL_FUNC_FREE_VARS;
    SHR_FUNC_EXIT;
}

/**
 * See .h file.
 */
shr_error_e
dnx_fabric_mesh_device_id_local_set(
    int unit,
    bcm_core_t core,
    int modid_index,
    bcm_module_t modid)
{
    uint32 entry_handle_id;
    SHR_FUNC_INIT_VARS(unit);
    DBAL_FUNC_INIT_VARS(unit);

    /*
     * when writing to first index (0), need to write all indexes
     * this is achieved by writing FABRIC_MESH_DEV_ID_LOCAL_INIT table
     */
    SHR_IF_ERR_EXIT(DBAL_HANDLE_ALLOC(unit, ((modid_index == 0) ?
                                             DBAL_TABLE_FABRIC_MESH_DEV_ID_LOCAL_INIT :
                                             DBAL_TABLE_FABRIC_MESH_DEV_ID_LOCAL), &entry_handle_id));

    dbal_entry_key_field32_set(unit, entry_handle_id, DBAL_FIELD_CORE, core);

    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_MESH_MODE_DEV_ID,
                                 ((modid_index == 0) ? INST_SINGLE : modid_index), modid);

    SHR_IF_ERR_EXIT(dbal_entry_commit(unit, entry_handle_id, DBAL_COMMIT));

exit:
    DBAL_FUNC_FREE_VARS;
    SHR_FUNC_EXIT;
}

/**
 * See .h file.
 */
shr_error_e
dnx_fabric_mesh_device_id_dest_set(
    int unit,
    int dest_group_id,
    int modid_index,
    bcm_module_t modid)
{
    uint32 entry_handle_id;
    SHR_FUNC_INIT_VARS(unit);
    DBAL_FUNC_INIT_VARS(unit);

    /*
     * when writing to first index (0), need to write all indexes
     * this is achieved by writing FABRIC_MESH_DEV_ID_DEST_INIT table
     */
    SHR_IF_ERR_EXIT(DBAL_HANDLE_ALLOC(unit, ((modid_index == 0) ?
                                             DBAL_TABLE_FABRIC_MESH_DEV_ID_DEST_INIT :
                                             DBAL_TABLE_FABRIC_MESH_DEV_ID_DEST), &entry_handle_id));

    dbal_entry_key_field32_set(unit, entry_handle_id, DBAL_FIELD_MESH_GROUP_ID, dest_group_id);

    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_MESH_MODE_DEV_ID,
                                 ((modid_index == 0) ? INST_SINGLE : modid_index), modid);

    SHR_IF_ERR_EXIT(dbal_entry_commit(unit, entry_handle_id, DBAL_COMMIT));

exit:
    DBAL_FUNC_FREE_VARS;
    SHR_FUNC_EXIT;
}

/**
 * \brief
 *   Associate between the group (local_dest) and the module-ids in it.
 * \param [in] unit         - *   The unit number.
 * \param [in] group        - *   The group id.
 * \param [in] modid_count  - *   Number of modids in modid_array param.
 * \param [in] modid_array  - *   Array of modids to be associated with local_dest group.
 * \return
 *   See \ref shr_error_e
 * \remark
 *   * None.
 * \see
 *   * dnx_fabric_modid_group_get.
 */
static shr_error_e
dnx_fabric_modid_group_set(
    int unit,
    bcm_module_t group,
    int modid_count,
    bcm_module_t * modid_array)
{
    int modid_index;
    bcm_module_t dest_group_id = BCM_FABRIC_GROUP_MODID_UNSET(group);
    SHR_FUNC_INIT_VARS(unit);

    SHR_IF_ERR_EXIT(dnx_fabric_db.modids_to_group_map.nof_modids.set(unit, dest_group_id, modid_count));
    for (modid_index = 0; modid_index < modid_count; ++modid_index)
    {
        /*
         * Set modids in sw state.
         */
        SHR_IF_ERR_EXIT(dnx_fabric_db.modids_to_group_map.modids.set(unit, dest_group_id, modid_index,
                                                                     modid_array[modid_index]));

        /*
         * Set modids in HW only if we support more then one destination device in MESH.
         * If we support only one, nothing needs to be written inside HW.
         */
        if (dnx_data_fabric.mesh.max_nof_dest_get(unit) > 1)
        {
            SHR_IF_ERR_EXIT(dnx_fabric_mesh_device_id_dest_set
                            (unit, dest_group_id, modid_index, modid_array[modid_index]));
        }
    }

exit:
    SHR_FUNC_EXIT;
}

/**
 * \brief
 *   Get the modids associated with a group.
 * \param [in]  unit            - *   The unit number.
 * \param [in]  group           - *   The group id.
 * \param [in]  modid_max_count - *   The length of the given modid_array.
 * \param [out] modid_array     - *   Array of modids associated with local_dest group.
 * \param [out] modid_count     - *   Number of actual modids in modid_array.
 * \return
 *   See \ref shr_error_e
 * \remark
 *   * None.
 * \see
 *   * dnx_fabric_modid_group_set.
 */
static shr_error_e
dnx_fabric_modid_group_get(
    int unit,
    bcm_module_t group,
    int modid_max_count,
    bcm_module_t * modid_array,
    int *modid_count)
{
    int modid_index;
    int id_count = 0;
    bcm_module_t local_dest_id = BCM_FABRIC_GROUP_MODID_UNSET(group);
    SHR_FUNC_INIT_VARS(unit);

    SHR_IF_ERR_EXIT(dnx_fabric_db.modids_to_group_map.nof_modids.get(unit, local_dest_id, &id_count));
    if (modid_max_count < id_count)
    {
        SHR_ERR_EXIT(_SHR_E_PARAM, "modid_array is too small to contain all FAP id's");
    }

    *modid_count = id_count;

    for (modid_index = 0; modid_index < id_count; modid_index++)
    {
        SHR_IF_ERR_EXIT(dnx_fabric_db.modids_to_group_map.modids.get(unit, local_dest_id, modid_index,
                                                                     &modid_array[modid_index]));
    }

exit:
    SHR_FUNC_EXIT;
}

/**
 * \brief
 *   Set per mc_id to which destinations to replicate.
 * \param [in] unit         - The unit number.
 * \param [in] mc_id        - The multicast id.
 * \param [in] destid_count - Number of destinations in destid_array.
 * \param [in] destid_array - Array of destinations to replicate to.
 * \return
 *   See \ref shr_error_e
 */
static shr_error_e
dnx_fabric_multicast_set(
    int unit,
    bcm_multicast_t mc_id,
    uint32 destid_count,
    bcm_module_t * destid_array)
{
    int dest;
    uint32 mc_rep = 0;
    bcm_module_t dest_group_id;
    bcm_core_t core;
    int fap_id_index;
    uint32 max_nof_dest = dnx_data_fabric.mesh.max_nof_dest_get(unit);

    uint32 entry_handle_id;

    SHR_FUNC_INIT_VARS(unit);

    DBAL_FUNC_INIT_VARS(unit);

    for (dest = 0; dest < destid_count; ++dest)
    {
        /** Group destination */
        if (BCM_FABRIC_MODID_IS_GROUP(destid_array[dest]))
        {
            dest_group_id = BCM_FABRIC_GROUP_MODID_UNSET(destid_array[dest]);
            if (max_nof_dest < dest_group_id + 1)
            {
                SHR_ERR_EXIT(_SHR_E_INTERNAL, "Destination group id %d is bigger than maximum allowed which is %d",
                             destid_array[dest], max_nof_dest);
            }
            /** Multicast replication is 5 bits bitmap. LSB are always external destinations.
             *  We enable the needed replication bit by shifting based on destination index.
             */
            mc_rep |= 1 << dest_group_id;
        }
        /** Local core destination */
        else
        {
            SHR_IF_ERR_EXIT(dnx_stk_sys_modid_local_core_get(unit, destid_array[dest], &core, &fap_id_index));
            /*
             * MSB of Multicast bits are for local/core destinations. We offset by the known value of max_nof_dest.
             */
            mc_rep |= 1 << (core + max_nof_dest);
        }
    }

    SHR_IF_ERR_EXIT(DBAL_HANDLE_ALLOC(unit, DBAL_TABLE_FABRIC_MESH_MC_DB, &entry_handle_id));

    dbal_entry_key_field32_set(unit, entry_handle_id, DBAL_FIELD_MESH_MC_ID, mc_id);
    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_MESH_MC_REP, INST_SINGLE, mc_rep);

    SHR_IF_ERR_EXIT(dbal_entry_commit(unit, entry_handle_id, DBAL_COMMIT));

exit:
    DBAL_FUNC_FREE_VARS;
    SHR_FUNC_EXIT;
}

/**
 * \brief
 *   Get per mc_id which destinations gets replicated.
 * \param [in] unit             - The unit number.
 * \param [in] mc_id            - The multicast id.
 * \param [in] destid_count_max - Size of the given destid_array.
 * \param [out] destid_count    - Number of destinations in destid_array.
 * \param [out] destid_array    - Array of destinations which gets replicated.
 * \return
 *   See \ref shr_error_e
 */
static shr_error_e
dnx_fabric_multicast_get(
    int unit,
    bcm_multicast_t mc_id,
    uint32 destid_count_max,
    int *destid_count,
    bcm_module_t * destid_array)
{
    uint32 mc_rep = 0;
    bcm_module_t *pdest = destid_array;
    bcm_module_t dest = 0;
    bcm_core_t core;
    uint32 entry_handle_id;
    uint32 local_mask;
    uint32 max_nof_dest = dnx_data_fabric.mesh.max_nof_dest_get(unit);

    SHR_FUNC_INIT_VARS(unit);
    DBAL_FUNC_INIT_VARS(unit);

    *destid_count = 0;

    SHR_IF_ERR_EXIT(DBAL_HANDLE_ALLOC(unit, DBAL_TABLE_FABRIC_MESH_MC_DB, &entry_handle_id));

    dbal_entry_key_field32_set(unit, entry_handle_id, DBAL_FIELD_MESH_MC_ID, mc_id);
    SHR_IF_ERR_EXIT(dbal_entry_get(unit, entry_handle_id, DBAL_GET_ALL_FIELDS));
    /*
     * Get MC_REP from entry
     */
    SHR_IF_ERR_EXIT(dbal_entry_handle_value_field32_get(unit, entry_handle_id, DBAL_FIELD_MESH_MC_REP,
                                                        INST_SINGLE, &mc_rep));

    SHR_BITCOUNT_RANGE(&mc_rep, *destid_count, 0, DNX_FABRIC_MESH_MC_REPLICATION_LENGTH);

    if (destid_count_max < *destid_count)
    {
        *destid_count = 0;
        SHR_ERR_EXIT(_SHR_E_PARAM, "destid_array is too short to contain all dest id's");
    }

    for (int dest_group_id = 0; dest_group_id < max_nof_dest; dest_group_id++)
    {
        /** Multicast replication is 5 bits bitmap. LSB are always external destinations.
         *  We check every external destination and save it if replication for it is enabled.
         */
        if (mc_rep & (1 << dest_group_id))
        {
            dest = dest_group_id;
            *pdest = BCM_FABRIC_GROUP_MODID_SET(dest);
            ++pdest;
        }
    }

    DNXCMN_CORES_ITER(unit, BCM_CORE_ALL, core)
    {
        /** Local destinations are positioned on MSB, so we offset with max_nof_dest.*/
        local_mask = (1 << (core + max_nof_dest));
        if (mc_rep & local_mask)
        {
            /** get first FAP ID of the core 0 */
            SHR_IF_ERR_EXIT(dnx_stk_sys_modid_get(unit, core, 0, (uint32 *) pdest));
            ++pdest;
        }
    }

exit:
    DBAL_FUNC_FREE_VARS;
    SHR_FUNC_EXIT;
}

/**
 * \brief
 *    Enable/Disable link delay measurement and sync cells transmit.
 * \param [in] unit  - The unit number.
 * \param [in] links_in_topology_count - nof links in array.
 * \param [in] links_in_topology - array of links.
 * \param [in] disable_link_delay_measurement  - Enable/Disable link delay measurement for the given links.
 * \param [in] enable_topology  - indicates to update or clear topology configurations.
 * \return
 *   See shr_error_e
 * \remark
 *   * None.
 * \see
 *   * None.
 */
static shr_error_e
dnx_fabric_update_link_delay_measurement_and_sync_cells(
    int unit,
    int links_in_topology_count,
    bcm_port_t * links_in_topology,
    int disable_link_delay_measurement,
    int enable_topology)
{
    uint32 entry_handle_id;
    int i_link, fabric_link;
    int enable_link_delay = 0;
    int enable_sync_cells = 0;

    SHR_FUNC_INIT_VARS(unit);
    DBAL_FUNC_INIT_VARS(unit);

    SHR_IF_ERR_EXIT(DBAL_HANDLE_ALLOC(unit, DBAL_TABLE_FABRIC_MESH_TOPOLOGY_LINKS, &entry_handle_id));

    /*
     * Link delay measurement and sync cells transmit are enabled by default for all links in HW but we disabled them on INIT.
     * In this function we will configure links for a specific destination group and will enable sync cells transmit for all.
     * Link delay measurement will be enabled only if the current FAP needs to measure it towards the destination we configure.
     */
    for (i_link = 0; i_link < links_in_topology_count; ++i_link)
    {
        if (enable_topology)
        {
            /*
             * Enable/disable link delay measurement
             * Sync cells always enabled for links in a topology.
             */
            enable_link_delay = !disable_link_delay_measurement;
            enable_sync_cells = 1;
        }
        else
        {
            /*
             * Clear topology - reset Link delay and sync cells transmit to 0 for all links in the given destination topology
             */
            enable_link_delay = 0;
            enable_sync_cells = 0;
        }
        SHR_IF_ERR_EXIT(dnx_algo_port_fabric_link_get(unit, links_in_topology[i_link], &fabric_link));

        dbal_entry_key_field32_set(unit, entry_handle_id, DBAL_FIELD_FABRIC_LINK, fabric_link);
        dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_ENABLE, INST_SINGLE, enable_link_delay);
        dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_TX_CELLS_ENABLE, INST_SINGLE, enable_sync_cells);
        SHR_IF_ERR_EXIT(dbal_entry_commit(unit, entry_handle_id, DBAL_COMMIT));
    }

exit:
    DBAL_FUNC_FREE_VARS;
    SHR_FUNC_EXIT;
}

/*
 * \brief
 *   Set/Unset links topology.
 * \param [in] unit          - The unit number.
 * \param [in] group - The destination id.
 * \param [in] links_count   - Number of links in links_array.
 * \param [in] links_array   - Array of links to be mapped to local_dest_id.
 * \param [in] enable -
 *                      1 - Set links topology to local_dest_id.
 *                      0 - Unset links topology to local_dest_id.
 */
static shr_error_e
dnx_fabric_link_topology_set(
    int unit,
    bcm_module_t group,
    int links_count,
    bcm_port_t * links_array,
    int enable)
{
    uint32 entry_handle_id;
    uint32 fabric_links_entry_handle_id;
    int i_link, i;
    uint32 min_local_modid;
    uint32 min_dest_modid;
    uint32 max_nof_fap_ids_per_device = dnx_data_device.general.max_nof_fap_ids_per_device_get(unit);
    bcm_module_t *dest_fap_id_arr = NULL;
    bcm_stk_modid_config_t *local_fap_id_arr = NULL;
    int fap_id_count = 0;
    bcm_module_t local_dest_id = BCM_FABRIC_GROUP_MODID_UNSET(group);
    int max_nof_dest_get = dnx_data_fabric.mesh.max_nof_dest_get(unit);
    int nof_local_fap_ids;
    int fabric_link;
    uint32 nof_links = dnx_data_fabric.links.nof_links_get(unit);
    int disable_link_delay_measurement = 0;

    SHR_FUNC_INIT_VARS(unit);
    DBAL_FUNC_INIT_VARS(unit);

    SHR_ALLOC_SET_ZERO(dest_fap_id_arr, sizeof(bcm_module_t) * max_nof_fap_ids_per_device, "dest_fap_id_arr",
                       "%s%s%s\r\n", EMPTY, EMPTY, EMPTY);
    SHR_ALLOC_SET_ZERO(local_fap_id_arr, sizeof(bcm_stk_modid_config_t) * max_nof_fap_ids_per_device,
                       "local_fap_id_arr", "%s%s%s\r\n", EMPTY, EMPTY, EMPTY);

    /*
     * Verify that destinations modids are configured for this destination group.
     */
    SHR_IF_ERR_EXIT(dnx_fabric_modid_group_get
                    (unit, local_dest_id, max_nof_fap_ids_per_device, dest_fap_id_arr, &fap_id_count));
    if (fap_id_count == 0)
    {
        SHR_ERR_EXIT(_SHR_E_CONFIG,
                     "There are no destination modids configured for group %d. Configure them with bcm_fabric_modid_group_set.",
                     local_dest_id);
    }
    /*
     * Configure SW STATE with topology information. 
     */
    if (enable)
    {
        for (i_link = 0; i_link < links_count; ++i_link)
        {
            SHR_IF_ERR_EXIT(dnx_algo_port_fabric_link_get(unit, links_array[i_link], &fabric_link));
            SHR_IF_ERR_EXIT(dnx_fabric_db.mesh_topology.links.set(unit, local_dest_id, fabric_link, TRUE));
        }
    }
    else
    {
        /*
         * Clear all links if topology for this destination is disabled 
         */
        for (i_link = 0; i_link < nof_links; ++i_link)
        {
            SHR_IF_ERR_EXIT(dnx_fabric_db.mesh_topology.links.set(unit, local_dest_id, i_link, FALSE));
        }
    }

    /*
     * Map external destination id with links connected to it.
     * In cases where there is only single destination device, we can skip this configuration.
     */
    if (max_nof_dest_get > 1)
    {
        SHR_IF_ERR_EXIT(DBAL_HANDLE_ALLOC(unit, DBAL_TABLE_FABRIC_MESH_REPLICATION_LINK_MAP, &entry_handle_id));

        dbal_entry_key_field32_set(unit, entry_handle_id, DBAL_FIELD_MESH_DEST_ID, local_dest_id);

        if (enable == TRUE)
        {
            for (i_link = 0; i_link < links_count; ++i_link)
            {
                SHR_IF_ERR_EXIT(dnx_algo_port_fabric_link_get(unit, links_array[i_link], &fabric_link));
                dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_MESH_LINK_ENABLE, fabric_link, TRUE);
            }
        }
        else
        {
            dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_MESH_LINK_ENABLE, INST_ALL, FALSE);
        }

        SHR_IF_ERR_EXIT(dbal_entry_commit(unit, entry_handle_id, DBAL_COMMIT));
    }
    /*
     * Update modid to context map
     */
    if (fap_id_count > 0)
    {
        /** The first contexts are for local cores so we do offset with nof_cores for the device */
        int group_ctx = (enable) ? (dnx_data_device.general.nof_cores_get(unit) + local_dest_id) : 0;
        int i_fap_id;

        for (i_fap_id = 0; i_fap_id < fap_id_count; ++i_fap_id)
        {
            SHR_IF_ERR_EXIT(dnx_stk_sys_mesh_dqcq_map_set(unit, dest_fap_id_arr[i_fap_id], group_ctx));
        }
    }

    /** Find minimum local modid */
    SHR_IF_ERR_EXIT(bcm_dnx_stk_modid_config_get_all
                    (unit, max_nof_fap_ids_per_device, local_fap_id_arr, &nof_local_fap_ids));
    min_local_modid = local_fap_id_arr[0].modid;
    for (i = 1; i < nof_local_fap_ids; i++)
    {
        min_local_modid = UTILEX_MIN(min_local_modid, local_fap_id_arr[i].modid);
    }

    /** Find minimum destination modid */
    min_dest_modid = dest_fap_id_arr[0];
    for (i = 1; i < fap_id_count; i++)
    {
        min_dest_modid = UTILEX_MIN(min_dest_modid, dest_fap_id_arr[i]);
    }

    disable_link_delay_measurement = (min_dest_modid > min_local_modid) ? 1 : 0;
    if (disable_link_delay_measurement)
    {
        int is_empty;
        /*
         * Here we will disable link measurement for currently configured topology, but we make sure that we won't affect
         * other topology configurations made on this device.
         */
        SHR_IF_ERR_EXIT(dnx_fabric_update_link_delay_measurement_and_sync_cells
                        (unit, links_count, links_array, disable_link_delay_measurement, enable));

        if (dnx_data_fabric.debug.feature_get(unit, dnx_data_fabric_debug_mesh_topology_replication) == 1)
        {
            SHR_IF_ERR_EXIT(DBAL_HANDLE_ALLOC
                            (unit, DBAL_TABLE_FABRIC_MESH_TOPOLOGY_LINKS, &fabric_links_entry_handle_id));
            is_empty = 1;
            for (i_link = 0; i_link < nof_links; ++i_link)
            {
                uint32 is_enabled = 0;

                dbal_entry_key_field32_set(unit, fabric_links_entry_handle_id, DBAL_FIELD_FABRIC_LINK, i_link);
                dbal_value_field32_request(unit, fabric_links_entry_handle_id, DBAL_FIELD_ENABLE, INST_SINGLE,
                                           &is_enabled);
                SHR_IF_ERR_EXIT(dbal_entry_get(unit, fabric_links_entry_handle_id, DBAL_COMMIT));

                if (is_enabled == 1)
                {
                    is_empty = 0;
                    break;
                }
            }

            SHR_IF_ERR_EXIT(DBAL_HANDLE_CLEAR
                            (unit, DBAL_TABLE_FABRIC_MESH_TOPOLOGY_INIT, fabric_links_entry_handle_id));
            dbal_entry_value_field32_set(unit, fabric_links_entry_handle_id, DBAL_FIELD_MESH_CONFIG_1, INST_SINGLE,
                                         is_empty ? 0x0 : dnx_data_fabric.mesh_topology.mesh_config_1_get(unit));
            SHR_IF_ERR_EXIT(dbal_entry_commit(unit, fabric_links_entry_handle_id, DBAL_COMMIT));
        }
    }
    else
    {
        /*
         * Here we will enable link measurement for links of currently configured topology.
         */
        SHR_IF_ERR_EXIT(dnx_fabric_update_link_delay_measurement_and_sync_cells
                        (unit, links_count, links_array, disable_link_delay_measurement, enable));

        /*
         * FMAC Does not work in emulation
         */
        if (!(soc_sand_is_emulation_system(unit) && DNX_FABRIC_FMAC_EMULATION_NOT_SUPPORTED(unit)))
        {
            SHR_IF_ERR_EXIT(DBAL_HANDLE_ALLOC
                            (unit, DBAL_TABLE_FABRIC_MESH_TOPOLOGY_LINKS, &fabric_links_entry_handle_id));
            for (i_link = 0; i_link < links_count; ++i_link)
            {
                int fabric_link;

                SHR_IF_ERR_EXIT(dnx_algo_port_fabric_link_get(unit, links_array[i_link], &fabric_link));

                dbal_entry_key_field32_set(unit, fabric_links_entry_handle_id, DBAL_FIELD_FABRIC_LINK, fabric_link);
                dbal_entry_value_field32_set(unit, fabric_links_entry_handle_id, DBAL_FIELD_MODE_0, INST_SINGLE,
                                             enable);
                if (dnx_data_fabric.general.feature_get(unit, dnx_data_fabric_general_retimer_functionality_supported))
                {
                    dbal_entry_value_field32_set(unit, fabric_links_entry_handle_id, DBAL_FIELD_MODE_1, INST_SINGLE,
                                                 !enable);
                }
                SHR_IF_ERR_EXIT(dbal_entry_commit(unit, fabric_links_entry_handle_id, DBAL_COMMIT));
            }
        }
    }

    LOG_VERBOSE(BSL_LOG_MODULE,
                (BSL_META_U
                 (unit,
                  "Set topology for:\n dest group = %d , nof links = %d , enable topology = %d, measure link delay = %d\n"),
                 local_dest_id, links_count, enable, !disable_link_delay_measurement));

exit:
    SHR_FREE(local_fap_id_arr);
    SHR_FREE(dest_fap_id_arr);
    DBAL_FUNC_FREE_VARS;
    SHR_FUNC_EXIT;
}

/**
 * \brief
 *   Get association of links with a destination.
 * \param [in] unit             - The unit number.
 * \param [in] group            - The destination id.
 * \param [in] max_links_count  - Size of the given links_array array.
 * \param [out] links_count     - Number of received links in links_array.
 * \param [out] links_array     - Array of links associated with local_dest_id.
 * \return
 *   See \ref shr_error_e
 */
static shr_error_e
dnx_fabric_link_topology_get(
    int unit,
    bcm_module_t group,
    int max_links_count,
    int *links_count,
    bcm_port_t * links_array)
{
    int i_link;
    int nof_links = dnx_data_fabric.links.nof_links_get(unit);
    bcm_port_t link_arr[DNX_DATA_MAX_FABRIC_LINKS_NOF_LINKS];
    bcm_module_t local_dest_id = BCM_FABRIC_GROUP_MODID_UNSET(group);
    SHR_FUNC_INIT_VARS(unit);

    *links_count = 0;

    /*
     * Get links bitmap associated with local_dest_id
     */
    for (i_link = 0; i_link < nof_links; ++i_link)
    {
        int status;
        SHR_IF_ERR_EXIT(dnx_fabric_db.mesh_topology.links.get(unit, local_dest_id, i_link, &status));
        if (status == TRUE)
        {
            bcm_port_t logical_port;
            SHR_IF_ERR_EXIT(dnx_algo_port_fabric_link_to_logical_get(unit, i_link, &logical_port));
            link_arr[*links_count] = logical_port;
            ++(*links_count);
        }
    }

    /*
     * Update array if sufficient for all links
     */
    if (max_links_count < *links_count)
    {
        *links_count = 0;
        SHR_ERR_EXIT(_SHR_E_PARAM, "links_array is too short to contain all links");
    }
    else
    {
        for (i_link = 0; i_link < *links_count; ++i_link)
        {
            links_array[i_link] = link_arr[i_link];
        }
    }

exit:
    SHR_FUNC_EXIT;
}

/**
 * \brief - Verify routine for associated BCM API
 * \param [in] unit        - The unit number.
 * \param [in] destination - The destination id.
 * \param [in] links_count - Number of links in links_array.
 * \param [in] links_array - Array of links to be mapped to local_dest_id.
 * \return
 *   See \ref shr_error_e
 */
static int
dnx_fabric_link_topology_set_verify(
    int unit,
    bcm_module_t destination,
    int links_count,
    bcm_port_t * links_array)
{
    int nof_fabric_links, i;
    SHR_FUNC_INIT_VARS(unit);

    if (!dnx_data_fabric.links.nof_links_get(unit))
    {
        SHR_ERR_EXIT(_SHR_E_PARAM, "bcm_fabric_link_topology_set is not supported for devices without fabric links\n");
    }

    /*
     * Validate links_count
     */
    if (links_count < 0)
    {
        SHR_ERR_EXIT(_SHR_E_PARAM, "links_count should be 0 and up");
    }
    else if (links_count != 0)
    {
        SHR_NULL_CHECK(links_array, _SHR_E_PARAM, "links_array");
    }
    /*
     * Validate mesh mode
     */
    if ((dnx_data_fabric.general.connect_mode_get(unit) != DNX_FABRIC_CONNECT_MODE_MESH))
    {
        SHR_ERR_EXIT(_SHR_E_CONFIG, "bcm_fabric_link_topology_set is only valid in mesh mode");
    }

    nof_fabric_links = dnx_data_fabric.links.nof_links_get(unit);
    if (links_count > nof_fabric_links)
    {
        SHR_ERR_EXIT(_SHR_E_PARAM, "links_count value is too big");
    }
    /*
     * Validate links in links_array are valid
     */
    for (i = 0; i < links_count; ++i)
    {
        /*
         * dnx_algo_port_valid_verify
         */
        SHR_IF_ERR_EXIT(dnx_algo_port_type_verify(unit, links_array[i], DNX_ALGO_PORT_TYPE_FABRIC));
    }
    /*
     * Validate destination
     */
    SHR_IF_ERR_EXIT(dnx_fabric_local_dest_id_verify(unit, destination));

exit:
    SHR_FUNC_EXIT;
}

/**
 * \brief
 *   Associate links with destination.
 * \param [in] unit             - The unit number.
 * \param [in] destination      - The destination id for which to map the links. Should be set/unset using the macros:
 *                                  BCM_FABRIC_GROUP_MODID_SET(dest_id)
 *                                  BCM_FABRIC_GROUP_MODID_UNSET(dest_id)
 * \param [out] links_count     - Number of received logical ports in links_array.
 * \param [out] links_array     - Array of logical ports associated with local_dest_id.
 * \return
 *   See \ref shr_error_e
 */
int
bcm_dnx_fabric_link_topology_set(
    int unit,
    bcm_module_t destination,
    int links_count,
    bcm_port_t * links_array)
{
    int i;
    bcm_port_t logical_port_array[DNX_DATA_MAX_FABRIC_LINKS_NOF_LINKS];
    SHR_FUNC_INIT_VARS(unit);
    DNX_ERR_RECOVERY_START(unit);

    /*
     * Make sure to proceed with logical ports only and translate all fabric gports to logical ports.
     */
    for (i = 0; i < links_count; ++i)
    {
        SHR_IF_ERR_EXIT(dnx_port_logical_verify(unit, links_array[i]));
        SHR_IF_ERR_EXIT(dnx_port_logical_get(unit, links_array[i], &logical_port_array[i]));
    }

    SHR_INVOKE_VERIFY_DNXC(dnx_fabric_link_topology_set_verify(unit, destination, links_count, logical_port_array));

    /*
     * Set links topology
     */
    if (links_count == 0)
    {
        int unset_links_count = 0;
        bcm_module_t unset_links_array[DNX_DATA_MAX_FABRIC_LINKS_NOF_LINKS] = { 0 };
        int nof_fabric_links = dnx_data_fabric.links.nof_links_get(unit);
        /*
         * Get links needed to remove
         */
        SHR_IF_ERR_EXIT(dnx_fabric_link_topology_get(unit, destination, nof_fabric_links, &unset_links_count,
                                                     unset_links_array));
        SHR_IF_ERR_EXIT(dnx_fabric_link_topology_set(unit, destination, unset_links_count, unset_links_array, 0));
    }
    else
    {
        SHR_IF_ERR_EXIT(dnx_fabric_link_topology_set(unit, destination, links_count, logical_port_array, 1));
    }

exit:
    DNX_ERR_RECOVERY_END(unit);
    SHR_FUNC_EXIT;
}

/**
 * \brief - Verify routine for associated BCM API
 * \param [in] unit             - The unit number.
 * \param [in] destination      - The destination group.
 * \param [in] max_links_count  - Size of the given links_array array.
 * \param [out] links_count     - Number of received links in links_array.
 * \param [out] links_array     - Array of links associated with local_dest_id.
 * \return
 *   See \ref shr_error_e
 */
static int
dnx_fabric_link_topology_get_verify(
    int unit,
    bcm_module_t destination,
    int max_links_count,
    int *links_count,
    bcm_port_t * links_array)
{
    SHR_FUNC_INIT_VARS(unit);

    if (!dnx_data_fabric.links.nof_links_get(unit))
    {
        SHR_ERR_EXIT(_SHR_E_PARAM, "bcm_fabric_link_topology_get is not supported for devices without fabric links\n");
    }

    SHR_NULL_CHECK(links_array, _SHR_E_PARAM, "links_array");
    /*
     * Validate max_links_count
     */
    if (max_links_count < 0)
    {
        SHR_ERR_EXIT(_SHR_E_PARAM, "illegal max_links_count");
    }
    else if (max_links_count != 0)
    {
        SHR_NULL_CHECK(links_count, _SHR_E_PARAM, "links_count");
    }
    /*
     * Validate mesh mode
     */
    if ((dnx_data_fabric.general.connect_mode_get(unit) != DNX_FABRIC_CONNECT_MODE_MESH))
    {
        SHR_ERR_EXIT(_SHR_E_CONFIG, "bcm_fabric_link_topology_get is only valid in mesh mode");
    }
    /*
     * Validate destination
     */
    SHR_IF_ERR_EXIT(dnx_fabric_local_dest_id_verify(unit, destination));

exit:
    SHR_FUNC_EXIT;
}

/**
 * \brief
 *   Get association of links with a destination.
 * \param [in] unit             - The unit number.
 * \param [in] destination      - The destination id for which to map the links. Should be set/unset using the macros:
 *                                  BCM_FABRIC_GROUP_MODID_SET(dest_id)
 *                                  BCM_FABRIC_GROUP_MODID_UNSET(dest_id)
 * \param [in] max_links_count  - Length of the array to fill links_array in. 
 *                                Should be equal to or bigger than the number of links associated with the destination id.
 * \param [out] links_count     - Number of received logical ports in links_array.
 * \param [out] links_array     - Array of logical ports associated with local_dest_id.
 * \return
 *   See \ref shr_error_e
 */
int
bcm_dnx_fabric_link_topology_get(
    int unit,
    bcm_module_t destination,
    int max_links_count,
    int *links_count,
    bcm_port_t * links_array)
{
    SHR_FUNC_INIT_VARS(unit);
    DNX_ERR_RECOVERY_NOT_NEEDED(unit);

    SHR_INVOKE_VERIFY_DNXC(dnx_fabric_link_topology_get_verify(unit, destination, max_links_count, links_count,
                                                               links_array));
    /*
     * Get links topology
     */
    SHR_IF_ERR_EXIT(dnx_fabric_link_topology_get(unit, destination, max_links_count, links_count, links_array));

exit:
    SHR_FUNC_EXIT;
}

/**
 * \brief - Verify routine for associated BCM API
 * \param [in] unit         - The unit number.
 * \param [in] mc_id        - The multicast id.
 * \param [in] flags        - Flags (not in use)
 * \param [in] destid_count - Number of destinations in destid_array.
 * \param [in] destid_array - Array of destinations to replicate to.
 * \return
 *   See \ref shr_error_e
 */
static int
dnx_fabric_multicast_set_verify(
    int unit,
    bcm_multicast_t mc_id,
    uint32 flags,
    uint32 destid_count,
    bcm_module_t * destid_array)
{
    int dest = 0;
    uint32 is_mesh = FALSE;
    uint32 is_tdm_supported = 0;
    uint32 is_mesh_mc = dnx_data_fabric.mesh.multicast_enable_get(unit);
    uint32 max_mesh_replication = 0;
    SHR_FUNC_INIT_VARS(unit);

    SHR_NULL_CHECK(destid_array, _SHR_E_PARAM, "destid_array");

    if (dnx_data_tdm.params.feature_get(unit, dnx_data_tdm_params_is_supported))
    {
        is_tdm_supported = dnx_data_tdm.params.mode_get(unit) != TDM_MODE_NONE;
    }

    if (!dnx_data_fabric.general.feature_get(unit, dnx_data_fabric_general_blocks_exist))
    {
        SHR_ERR_EXIT(_SHR_E_UNAVAIL, "bcm_fabric_multicast_set is not supported on devices without fabric");
    }

    /** activate mesh-mc for mesh and single fap topology */
    if (dnx_data_fabric.general.connect_mode_get(unit) != DNX_FABRIC_CONNECT_MODE_FE)
    {
        is_mesh = TRUE;
    }
    /*
     * Validate device mode
     */
    if (!is_mesh || (!is_mesh_mc && !is_tdm_supported))
    {
        SHR_ERR_EXIT(_SHR_E_CONFIG,
                     "bcm_fabric_multicast_set is supported only in MESH mode with TDM support or in MESH_MC mode");
    }
    /*
     * Validate mc_id
     */
    SHR_RANGE_VERIFY(mc_id, 0, dnx_data_fabric.mesh.max_mc_id_get(unit), _SHR_E_PARAM, "illegal mc_id");
    /*
     * Validate flags
     */
    SHR_MASK_VERIFY(flags, 0, _SHR_E_PARAM, "Unrecognized flags");
    /*
     * Validate destid_count
     */
    max_mesh_replication = dnx_data_fabric.mesh.nof_dest_get(unit) + dnx_data_device.general.nof_cores_get(unit);
    if (destid_count > max_mesh_replication)
    {
        SHR_ERR_EXIT(_SHR_E_PARAM, "too many destinations");
    }
    /*
     * Validate destinations in dest_array
     */
    for (dest = 0; dest < destid_count; ++dest)
    {
        if (BCM_FABRIC_MODID_IS_GROUP(destid_array[dest]))
        {
            /** validate local_dest fits configuration */
            SHR_IF_ERR_EXIT(dnx_fabric_local_dest_id_verify(unit, destid_array[dest]));
        }
        else
        {

            int is_local;

            SHR_IF_ERR_EXIT(dnx_stk_sys_modid_is_local_get(unit, destid_array[dest], &is_local));
            if (!is_local)
            {
                SHR_ERR_EXIT(_SHR_E_PARAM, "invalid dest_id %d", destid_array[dest]);
            }
        }
    }

exit:
    SHR_FUNC_EXIT;
}

/**
 * \brief
 *   Set per mc_id to which destinations to replicate.
 * \param [in] unit         - The unit number.
 * \param [in] group        - The Multicast ID to configure its Destination IDs replications.
 * \param [in] flags        - Flags (not in use)
 * \param [in] destid_count - Number of Destination IDs this Multicast ID will replicate to.
 * \param [in] destid_array - Array of Destination IDs this Multicast ID will replicate to.
 * \return
 *   See \ref shr_error_e
 */
int
bcm_dnx_fabric_multicast_set(
    int unit,
    bcm_multicast_t group,
    uint32 flags,
    uint32 destid_count,
    bcm_module_t * destid_array)
{
    SHR_FUNC_INIT_VARS(unit);
    DNX_ERR_RECOVERY_START(unit);

    SHR_INVOKE_VERIFY_DNXC(dnx_fabric_multicast_set_verify(unit, group, flags, destid_count, destid_array));
    /*
     * Configure fabric replication
     */
    SHR_IF_ERR_EXIT(dnx_fabric_multicast_set(unit, group, destid_count, destid_array));

exit:
    DNX_ERR_RECOVERY_END(unit);
    SHR_FUNC_EXIT;
}

/**
 * \brief
 *   Set per mc_id to which destinations to replicate.
 * \param [in] unit             - The unit number.
 * \param [in] mc_id            - The Multicast ID to configure its Destination IDs replications.
 * \param [in] flags            - Flags (not in use)
 * \param [in] destid_count_max - Length of the array to fill the destid_array. Should be equal to or bigger than the number of destid associated with the Multicast ID.
 * \param [in] destid_count     - Number of Destination IDs this Multicast ID will replicate to.
 * \param [in] destid_array     - Array of Destination IDs this Multicast ID will replicate to.
 * \return
 *   See \ref shr_error_e
 */
static int
dnx_fabric_multicast_get_verify(
    int unit,
    bcm_multicast_t mc_id,
    uint32 flags,
    int destid_count_max,
    int *destid_count,
    bcm_module_t * destid_array)
{
    uint32 is_mesh = FALSE;
    uint32 is_tdm_supported = 0;
    uint32 is_mesh_mc = dnx_data_fabric.mesh.multicast_enable_get(unit);
    SHR_FUNC_INIT_VARS(unit);

    SHR_NULL_CHECK(destid_array, _SHR_E_PARAM, "destid_array");
    SHR_NULL_CHECK(destid_count, _SHR_E_PARAM, "destid_count");

    if (dnx_data_tdm.params.feature_get(unit, dnx_data_tdm_params_is_supported))
    {
        is_tdm_supported = dnx_data_tdm.params.mode_get(unit) != TDM_MODE_NONE;
    }

    /** activate mesh-mc for mesh and single fap topology */
    if (dnx_data_fabric.general.connect_mode_get(unit) != DNX_FABRIC_CONNECT_MODE_FE)
    {
        is_mesh = TRUE;
    }
    /*
     * Validate device mode
     */
    if (!is_mesh || (!is_mesh_mc && !is_tdm_supported))
    {
        SHR_ERR_EXIT(_SHR_E_CONFIG,
                     "bcm_fabric_multicast_get is supported only in MESH mode with TDM support or in MESH_MC mode");
    }
    /*
     * Validate mc_id
     */
    SHR_RANGE_VERIFY(mc_id, 0, dnx_data_fabric.mesh.max_mc_id_get(unit), _SHR_E_PARAM, "illegal mc_id");
    /*
     * Validate flags
     */
    SHR_MASK_VERIFY(flags, 0, _SHR_E_PARAM, "Unrecognized flags");
    /*
     * Validate destid_count_max
     */
    if (destid_count_max <= 0)
    {
        SHR_ERR_EXIT(_SHR_E_PARAM, "illegal destid_count_max");
    }

exit:
    SHR_FUNC_EXIT;
}

/**
 * \brief
 *   Get per mc_id which destinations gets replicated.
 * \param [in] unit             - The unit number.
 * \param [in] group            - The Multicast ID to configure its Destination IDs replications.
 * \param [in] flags            - Flags (not in use)
 * \param [in] destid_count_max - Size of the given destid_array.
 * \param [out] destid_count     - Number of destinations in destid_array.
 * \param [out] destid_array     - Array of destinations which gets replicated.
 * \return
 *   See shr_error_e
 * \remark
 *   Note that if there are several modid(s) on a core of local device,
 *   the first modid is returned
 */
int
bcm_dnx_fabric_multicast_get(
    int unit,
    bcm_multicast_t group,
    uint32 flags,
    int destid_count_max,
    int *destid_count,
    bcm_module_t * destid_array)
{
    SHR_FUNC_INIT_VARS(unit);
    DNX_ERR_RECOVERY_NOT_NEEDED(unit);

    SHR_INVOKE_VERIFY_DNXC(dnx_fabric_multicast_get_verify(unit, group, flags, destid_count_max, destid_count,
                                                           destid_array));
    /*
     * Get fabric replication configuration
     */
    SHR_IF_ERR_EXIT(dnx_fabric_multicast_get(unit, group, destid_count_max, destid_count, destid_array));

exit:
    SHR_FUNC_EXIT;
}

/**
 * \brief - Verify routine for BCM API
 * \param [in] unit         - *   The unit number.
 * \param [in] group        - *   The group id.
 * \param [in] modid_count  - *   Number of modids in modid_array param.
 * \param [in] modid_array  - *   Array of modids to be associated with local_dest group.
 * \return
 *   See \ref shr_error_e
 * \remark
 *   * None.
 * \see
 *   * bcm_dnx_fabric_modid_group_get.
 */
static int
dnx_fabric_modid_group_set_verify(
    int unit,
    bcm_module_t group,
    int modid_count,
    bcm_module_t * modid_array)
{
    int i_modid = 0;
    uint32 max_nof_fap_ids_per_device = 0;
    SHR_FUNC_INIT_VARS(unit);

    SHR_NULL_CHECK(modid_array, _SHR_E_PARAM, "modid_array");

    /*
     * Validate MESH mode
     */
    if (dnx_data_fabric.general.connect_mode_get(unit) != DNX_FABRIC_CONNECT_MODE_MESH)
    {
        SHR_ERR_EXIT(_SHR_E_CONFIG, "bcm_fabric_modid_group_set is only valid in mesh mode");
    }

    /*
     * Validate modid_count
     */
    max_nof_fap_ids_per_device = dnx_data_device.general.max_nof_fap_ids_per_device_get(unit);
    SHR_RANGE_VERIFY(modid_count, 1, max_nof_fap_ids_per_device, _SHR_E_PARAM, "modid_count should be between 1 and %u",
                     max_nof_fap_ids_per_device);

    /*
     * Validate faps in array are valid
     */
    for (i_modid = 0; i_modid < modid_count; ++i_modid)
    {
        SHR_RANGE_VERIFY(modid_array[i_modid], 0, dnx_data_device.general.nof_faps_get(unit) - 1, _SHR_E_PARAM,
                         "fap id %d is invalid", modid_array[i_modid]);
    }

    /*
     * Validate group
     */
    SHR_IF_ERR_EXIT(dnx_fabric_local_dest_id_verify(unit, group));

exit:
    SHR_FUNC_EXIT;
}

/**
 * \brief
 *   Associate between the group (local_dest) and the module-ids in it.
 * \param [in] unit         - *   The unit number.
 * \param [in] group        - *   The destination id for which to map the Module IDs. Should be set/unset using the macros:
 *                                BCM_FABRIC_GROUP_MODID_SET(dest_id)
 *                                BCM_FABRIC_GROUP_MODID_UNSET(dest_id)
 * \param [in] modid_count  - *   Number of Module IDs to associate with the destination.
 * \param [in] modid_array  - *   Array of Module IDs to associate with the destination.
 * \return
 *   See \ref shr_error_e
 * \remark
 *   * None.
 * \see
 *   * bcm_dnx_fabric_modid_group_get.
 */
int
bcm_dnx_fabric_modid_group_set(
    int unit,
    bcm_module_t group,
    int modid_count,
    bcm_module_t * modid_array)
{
    SHR_FUNC_INIT_VARS(unit);
    DNX_ERR_RECOVERY_START(unit);

    SHR_INVOKE_VERIFY_DNXC(dnx_fabric_modid_group_set_verify(unit, group, modid_count, modid_array));
    /*
     * Associate modids with group
     */
    SHR_IF_ERR_EXIT(dnx_fabric_modid_group_set(unit, group, modid_count, modid_array));
exit:
    DNX_ERR_RECOVERY_END(unit);
    SHR_FUNC_EXIT;
}

/**
 * \brief *   Verify routine for BCM API that obtains the modids associated with a group.
 * \param [in]  unit            - *   The unit number.
 * \param [in]  group           - *   The group id.
 * \param [in]  modid_max_count - *   The length of the given modid_array.
 * \param [out] modid_array     - *   Array of modids associated with local_dest group.
 * \param [out] modid_count     - *   Number of actual modids in modid_array.
 * \return
 *   See \ref shr_error_e
 * \remark
 *   * None.
 * \see
 *   * bcm_dnx_fabric_modid_group_set.
 */
static int
dnx_fabric_modid_group_get_verify(
    int unit,
    bcm_module_t group,
    int modid_max_count,
    bcm_module_t * modid_array,
    int *modid_count)
{
    SHR_FUNC_INIT_VARS(unit);

    SHR_NULL_CHECK(modid_array, _SHR_E_PARAM, "modid_array");
    SHR_NULL_CHECK(modid_count, _SHR_E_PARAM, "modid_count");

    /*
     * Validate mesh mode
     */
    if (dnx_data_fabric.general.connect_mode_get(unit) != DNX_FABRIC_CONNECT_MODE_MESH)
    {
        SHR_ERR_EXIT(_SHR_E_CONFIG, "bcm_fabric_modid_group_get is only valid in mesh mode");
    }
    /*
     * Validate modid_max_count
     */
    if (modid_max_count <= 0)
    {
        SHR_ERR_EXIT(_SHR_E_PARAM, "illegal modid_max_count");
    }
    /*
     * Validate group
     */
    SHR_IF_ERR_EXIT(dnx_fabric_local_dest_id_verify(unit, group));

exit:
    SHR_FUNC_EXIT;
}

/**
 * \brief -   Get the modids associated with a group.
 * \param [in] unit             - The unit number.
 * \param [in] group            - The destination id for which to map the Module IDs. Should be set/unset using the macros:
 *                                    BCM_FABRIC_GROUP_MODID_SET(dest_id)
 *                                    BCM_FABRIC_GROUP_MODID_UNSET(dest_id)
 * \param [in] modid_max_count  - Should be equal to or bigger than the number of Module IDs associated with the destination id.
 * \param [in] modid_count      - Number of Module IDs to associate with the destination.
 * \param [in] modid_array      - Array of Module IDs to associate with the destination.
 * \return
 *   See \ref shr_error_e
 * \remark
 *   * None.
 * \see
 *   * bcm_dnx_fabric_modid_group_get.
 */
int
bcm_dnx_fabric_modid_group_get(
    int unit,
    bcm_module_t group,
    int modid_max_count,
    bcm_module_t * modid_array,
    int *modid_count)
{
    SHR_FUNC_INIT_VARS(unit);
    DNX_ERR_RECOVERY_NOT_NEEDED(unit);

    SHR_INVOKE_VERIFY_DNXC(dnx_fabric_modid_group_get_verify(unit, group, modid_max_count, modid_array, modid_count));
    /*
     * Get modids associated with this group
     */
    SHR_IF_ERR_EXIT(dnx_fabric_modid_group_get(unit, group, modid_max_count, modid_array, modid_count));
exit:
    SHR_FUNC_EXIT;
}

/**
 * \brief
 *   Set system ref clock frequency.
 */
static shr_error_e
dnx_fabric_mesh_topology_core_clock_frequency_init(
    int unit)
{
    uint32 entry_handle_id;
    uint32 device_core_clock_khz = 0;
    uint32 system_ref_clock_khz = 0;
    uint32 intg = 0;
    COMPILER_UINT64 frac, frac_x, frac_x2;
    SHR_FUNC_INIT_VARS(unit);
    DBAL_FUNC_INIT_VARS(unit);

    /*
     * Enable the fraction mode over cal.
     */
    SHR_IF_ERR_EXIT(DBAL_HANDLE_ALLOC(unit, DBAL_TABLE_FABRIC_MESH_TOPOLOGY_INIT, &entry_handle_id));
    if (dnx_data_fabric.mesh_topology.feature_get(unit, dnx_data_fabric_mesh_topology_calendar_mode_supported))
    {
        dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_MULTI_FAP_3, INST_SINGLE, 0x1);
        SHR_IF_ERR_EXIT(dbal_entry_commit(unit, entry_handle_id, DBAL_COMMIT));
    }

    device_core_clock_khz = DNXCMN_CORE_CLOCK_KHZ_GET(unit);
    system_ref_clock_khz = dnx_data_device.general.system_ref_core_clock_khz_get(unit);
    intg = system_ref_clock_khz / device_core_clock_khz;

    COMPILER_64_SET(frac, 0, 0);

    COMPILER_64_SET(frac_x, 0, 0);

    COMPILER_64_SET(frac_x, 0, system_ref_clock_khz);
    COMPILER_64_UMUL_32(frac_x, DNX_FABRIC_SYS_FREQ_RES_19);

    COMPILER_64_COPY(frac, frac_x);
    UTILEX_64_UDIV_32(frac, device_core_clock_khz);

    if (device_core_clock_khz <= system_ref_clock_khz)
    {
        COMPILER_64_SET(frac_x2, 0, intg);
        COMPILER_64_UMUL_32(frac_x2, DNX_FABRIC_SYS_FREQ_RES_19);
        if (COMPILER_64_GT(frac_x2, frac))
        {
            /*
             * If frac is amaller than frac_x2 then set it to zero.
             */
            COMPILER_64_SET(frac, 0, 0);
        }
        else
        {
            COMPILER_64_SUB_64(frac, frac_x2);
        }
    }

    /*
     * Set the System clock frequency
     */
/**    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_SYS_CONFIG_1, INST_SINGLE, frac.arr[0]);  **/
    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_SYS_CONFIG_1, INST_SINGLE, COMPILER_64_LO(frac));

    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_SYS_CONFIG_2, INST_SINGLE, intg);
    SHR_IF_ERR_EXIT(dbal_entry_commit(unit, entry_handle_id, DBAL_COMMIT));

    SHR_IF_ERR_EXIT(dnx_fabric_db.system_upgrade.state_0.set(unit, system_ref_clock_khz));

exit:
    DBAL_FUNC_FREE_VARS;
    SHR_FUNC_EXIT;
}

/**
 * See .h file
 */
shr_error_e
dnx_fabric_mesh_topology_init(
    int unit)
{
    uint32 entry_handle_id;
    SHR_FUNC_INIT_VARS(unit);
    DBAL_FUNC_INIT_VARS(unit);

    SHR_IF_ERR_EXIT(dnx_fabric_mesh_topology_core_clock_frequency_init(unit));

    SHR_IF_ERR_EXIT(DBAL_HANDLE_ALLOC(unit, DBAL_TABLE_FABRIC_MESH_TOPOLOGY_INIT, &entry_handle_id));
    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_MESH_INIT, INST_SINGLE,
                                 dnx_data_fabric.mesh_topology.mesh_init_get(unit));
    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_MESH_CONFIG_1, INST_SINGLE, 0x0);
    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_MESH_CONFIG_2, INST_SINGLE, 0xd);
    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_MESH_CONFIG_3, INST_SINGLE, 0x0);
    SHR_IF_ERR_EXIT(dbal_entry_commit(unit, entry_handle_id, DBAL_COMMIT));

    SHR_IF_ERR_EXIT(DBAL_HANDLE_CLEAR(unit, DBAL_TABLE_FABRIC_MESH_TOPOLOGY_INIT, entry_handle_id));
    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_FAST_CONFIG_1, INST_SINGLE, 0x5);
    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_FAST_CONFIG_2, INST_SINGLE, 0xc);
    SHR_IF_ERR_EXIT(dbal_entry_commit(unit, entry_handle_id, DBAL_COMMIT));

    SHR_IF_ERR_EXIT(DBAL_HANDLE_CLEAR(unit, DBAL_TABLE_FABRIC_MESH_TOPOLOGY, entry_handle_id));
    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_FAST, INST_SINGLE, 0x0);
    SHR_IF_ERR_EXIT(dbal_entry_commit(unit, entry_handle_id, DBAL_COMMIT));

    SHR_IF_ERR_EXIT(DBAL_HANDLE_CLEAR(unit, DBAL_TABLE_FABRIC_MESH_TOPOLOGY_INIT, entry_handle_id));
    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_FILTER_ENABLE, INST_SINGLE, 0x1);
    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_FILTER_TH, INST_SINGLE, 0x1800);
    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_FILTER_DC, INST_SINGLE, 0x0);
    SHR_IF_ERR_EXIT(dbal_entry_commit(unit, entry_handle_id, DBAL_COMMIT));

    if (dnx_data_fabric.general.connect_mode_get(unit) == DNX_FABRIC_CONNECT_MODE_MESH)
    {
        /*
         * Disable link delay measurement and mesh topology sync cells for all links, since they are enabled by default.
         * They will be updated when configuring topology for the device.
         */
        int i_link = 0;

        for (i_link = 0; i_link < dnx_data_fabric.links.nof_links_get(unit); ++i_link)
        {
            SHR_IF_ERR_EXIT(DBAL_HANDLE_CLEAR(unit, DBAL_TABLE_FABRIC_MESH_TOPOLOGY_LINKS, entry_handle_id));

            dbal_entry_key_field32_set(unit, entry_handle_id, DBAL_FIELD_FABRIC_LINK, i_link);
            dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_ENABLE, INST_SINGLE, 0);
            dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_TX_CELLS_ENABLE, INST_SINGLE, 0);

            SHR_IF_ERR_EXIT(dbal_entry_commit(unit, entry_handle_id, DBAL_COMMIT));
        }
    }

exit:
    DBAL_FUNC_FREE_VARS;
    SHR_FUNC_EXIT;
}

/**
 * See .h file
 */
shr_error_e
dnx_fabric_mesh_topology_get(
    int unit,
    soc_dnxc_fabric_mesh_topology_diag_t * mesh_topology_diag)
{
    uint32 entry_handle_id;
    uint32 link = 0;
    uint32 is_valid = 0;
    uint32 value = 0;
    uint32 nof_links = dnx_data_fabric.links.nof_links_get(unit);
    SHR_FUNC_INIT_VARS(unit);
    DBAL_FUNC_INIT_VARS(unit);

    SHR_IF_ERR_EXIT(DBAL_HANDLE_ALLOC(unit, DBAL_TABLE_FABRIC_MESH_TOPOLOGY_STATUS, &entry_handle_id));
    dbal_value_field32_request(unit, entry_handle_id, DBAL_FIELD_INDICATION_1, INST_SINGLE,
                               &mesh_topology_diag->indication_1);
    dbal_value_field32_request(unit, entry_handle_id, DBAL_FIELD_INDICATION_2, INST_SINGLE,
                               &mesh_topology_diag->indication_2);
    SHR_IF_ERR_EXIT(dbal_entry_get(unit, entry_handle_id, DBAL_COMMIT));

    SHR_IF_ERR_EXIT(DBAL_HANDLE_CLEAR(unit, DBAL_TABLE_FABRIC_MESH_TOPOLOGY_LINKS_STATUS, entry_handle_id));
    for (link = 0; link < nof_links; ++link)
    {
        dbal_entry_key_field32_set(unit, entry_handle_id, DBAL_FIELD_FABRIC_LINK, link);
        dbal_value_field32_request(unit, entry_handle_id, DBAL_FIELD_LINK_STATUS_IS_VALID, INST_SINGLE, &is_valid);
        dbal_value_field32_request(unit, entry_handle_id, DBAL_FIELD_LINK_STATUS_VALUE, INST_SINGLE, &value);
        SHR_IF_ERR_EXIT(dbal_entry_get(unit, entry_handle_id, DBAL_COMMIT));

        mesh_topology_diag->type2_list[link] = is_valid ? value : -1;
    }
    mesh_topology_diag->link_list_count = nof_links;

    SHR_IF_ERR_EXIT(DBAL_HANDLE_CLEAR(unit, DBAL_TABLE_FABRIC_MESH_TOPOLOGY_STATUS, entry_handle_id));
    dbal_value_field32_request(unit, entry_handle_id, DBAL_FIELD_RX_CONTROL_CELLS_TYPE1, INST_SINGLE,
                               &mesh_topology_diag->rx_control_cells_type1);
    dbal_value_field32_request(unit, entry_handle_id, DBAL_FIELD_RX_CONTROL_CELLS_TYPE2, INST_SINGLE,
                               &mesh_topology_diag->rx_control_cells_type2);
    dbal_value_field32_request(unit, entry_handle_id, DBAL_FIELD_INDICATION_3, INST_SINGLE,
                               &mesh_topology_diag->indication_3);
    dbal_value_field32_request(unit, entry_handle_id, DBAL_FIELD_INDICATION_4, INST_SINGLE,
                               &mesh_topology_diag->indication_4);
    dbal_value_field32_request(unit, entry_handle_id, DBAL_FIELD_CONTROL_CELLS_TYPE3, INST_SINGLE,
                               &mesh_topology_diag->control_cells_type3);
    dbal_value_field32_request(unit, entry_handle_id, DBAL_FIELD_STATUS_1, INST_SINGLE, &mesh_topology_diag->status_1);
    dbal_value_field32_request(unit, entry_handle_id, DBAL_FIELD_STATUS_1_ID1, INST_SINGLE,
                               &mesh_topology_diag->status_1_id1);
    dbal_value_field32_request(unit, entry_handle_id, DBAL_FIELD_STATUS_1_ID2, INST_SINGLE,
                               &mesh_topology_diag->status_1_id2);
    dbal_value_field32_request(unit, entry_handle_id, DBAL_FIELD_STATUS_2, INST_SINGLE, &mesh_topology_diag->status_2);
    dbal_value_field32_request(unit, entry_handle_id, DBAL_FIELD_STATUS_2_ID1, INST_SINGLE,
                               &mesh_topology_diag->status_2_id1);
    dbal_value_field32_request(unit, entry_handle_id, DBAL_FIELD_STATUS_2_ID2, INST_SINGLE,
                               &mesh_topology_diag->status_2_id2);
    SHR_IF_ERR_EXIT(dbal_entry_get(unit, entry_handle_id, DBAL_COMMIT));

exit:
    DBAL_FUNC_FREE_VARS;
    SHR_FUNC_EXIT;
}

#undef BSL_LOG_MODULE
