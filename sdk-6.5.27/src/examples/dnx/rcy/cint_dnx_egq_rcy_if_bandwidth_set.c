/* 
 *
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2022 Broadcom Inc. All rights reserved.
 *
 * Need to also include "src/examples/sand/cint_l2_traverse.c"
 * for l2_entry_add function
 *
 * Main examples:
 *
 * cint_dnx_mirror_config - Add L2 entry for a specified destination port, configure an outbound mirror destinattion with 
 * specified mirror port and set the Recycle mirror interface rate. Disable EIR shapers in order to use the CIR shapers.
 *
 * cint_dnx_recycle_config - Add L2 entry for a specified recycle port and set the Recycle mirror interface rate.
 * Disable EIR shapers in order to use the CIR shapers.
 *
 * Traffic for both cases:
 *     Destination MAC: 00:00:00:00:00:01
 *     VLAN ID: 100
 * 
 */

/** Function to set the Recycle interface
  * rate on a specified core.
  * - unit : Unit ID
  * - core : on which core to set the rate
  * - rate : rate to set in kbits
  */
int cint_dnx_recycle_bandwidth_set(
    int unit,
    bcm_core_t core,
    int rate)
{
    bcm_gport_t gp;

    BCM_COSQ_GPORT_RCY_SET(gp,core);
    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_bandwidth_set(unit,gp,0,0,rate,0), "");
    return BCM_E_NONE;
}

/** Function to set the Recycle Mirror interface
  * rate on a specified core.
  * - unit : Unit ID
  * - core : on which core to set the rate
  * - rate : rate to set in kbits
  */
int cint_dnx_mirror_bandwidth_set(
    int unit,
    bcm_core_t core,
    int rate)
{
    bcm_gport_t gp;

    BCM_COSQ_GPORT_RCY_MIRR_SET(gp,core);
    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_bandwidth_set(unit,gp,0,0,rate,0), "");
    return BCM_E_NONE;
}

/** Function to create an outbound mirror destination
  * and a mirroring rule which will point to it.
  * - unit : Unit ID
  * - dest_port : destination port according to which the mirror rule will point to the mirror destination
  * - mirror_port : mirror port for the mirror destination
  * - is_lossless : indicates if the mirror destination is strict priority
  */
int cint_dnx_mirror_destination_create_add(
    int unit,
    bcm_port_t dest_port,
    bcm_port_t mirror_port,
    int is_lossless)
{
    bcm_gport_t mirror_gport;
    bcm_mirror_destination_t mirror_dest;

    /** Create mirror destination */
    BCM_GPORT_LOCAL_SET(mirror_gport, mirror_port);
    BCM_IF_ERROR_RETURN_MSG(bcm_stk_gport_sysport_get(unit, mirror_gport, &mirror_dest.gport), "");
    mirror_dest.is_recycle_strict_priority = (is_lossless ? 1 : 0);
    BCM_IF_ERROR_RETURN_MSG(bcm_mirror_destination_create(unit, mirror_dest), "");

    /** Add the in_gport to the mirror destination */
    BCM_IF_ERROR_RETURN_MSG(bcm_mirror_port_dest_add(unit, dest_port, BCM_MIRROR_PORT_EGRESS, mirror_dest.mirror_dest_id), "");
    return BCM_E_NONE;
}

/** Function to configure rge Recycle and Mirror weights
  * for the recycle interface EIR shapers.
  * - unit : Unit ID
  * - core : on which core to set the weight
  * - recycle_weight : recycled traffic wirght
  * - mirror_weight : recycled traffic wirght
  */
int cint_dnx_recycle_mirror_weight_config(
    int unit,
    bcm_core_t core,
    int recycle_weight,
    int mirror_weight)
{
    bcm_gport_t gp_mirror;
    bcm_gport_t gp_recycle;

    /** Set the weight of the mirror traffic*/
    BCM_COSQ_GPORT_RCY_MIRR_SET(gp_mirror,core);
    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_sched_set(unit, gp_mirror, 0, -1, mirror_weight), "");

    /** Set the weight of the recycle traffic*/
    BCM_COSQ_GPORT_RCY_SET(gp_recycle,core);
    BCM_IF_ERROR_RETURN_MSG(bcm_cosq_gport_sched_set(unit, gp_recycle, 0, -1, recycle_weight), "");
    return BCM_E_NONE;
}

/** Main unction for Mirror example.
  * - unit : Unit ID
  * - dest_port : destination port for which the L2 entry and the mirror destination rule will be created
  * - mirror_recycle_port : mirror recycle port which will be mapped to the destination port and used for sniffed traffic
  * - mirror_port : port for the mirror destination (mirrored traffic will be forwarded to it)
  * - rate : rate to set the recycle mirror interface with
  * - is_lossless : indicates if the mirror destination is strict priority
  */
int cint_dnx_mirror_config(
    int unit,
    bcm_port_t dest_port,
    bcm_port_t mirror_recycle_port,
    bcm_port_t mirror_port,
    int rate,
    int is_lossless)
{
    int rv;
    uint32 flags;
    bcm_gport_t dest_gport;
    bcm_port_interface_info_t interface_info;
    bcm_port_mapping_info_t   mapping_info;
    bcm_mac_t mac = {0x0,0x0,0x0,0x0,0x0,0x1};
    int vlan = 100;

    /** Unmap the dest_port if it had previous mapping to a mirror recycle port */
    BCM_IF_ERROR_RETURN_MSG(sand_mirror_port_to_rcy_port_map(unit, dest_port, 0, BCM_PORT_INVALID, 0, 0), "");

    /** Map the dest_port to the specified mirror_recycle_port */
    BCM_IF_ERROR_RETURN_MSG(sand_mirror_port_to_rcy_port_map(unit, dest_port, 0, mirror_recycle_port, 0, 0), "");

    /** Delete L2 entry, in case previous entry for the same MAC and VAN exists */
    rv = bcm_l2_addr_delete(unit, mac, vlan);
    if (rv == BCM_E_NOT_FOUND) {
        rv = BCM_E_NONE;
    }
    BCM_IF_ERROR_RETURN_MSG(rv, "");

    /** Add an L2 entry for the destination port */
    BCM_GPORT_LOCAL_SET(dest_gport, dest_port);
    BCM_IF_ERROR_RETURN_MSG(l2_entry_add(unit, mac, vlan, 0, dest_gport, 0), "");

    /** Create a mirror destination with the mirror_port and add the dest_port to the mirror destination */
    BCM_IF_ERROR_RETURN_MSG(cint_dnx_mirror_destination_create_add(unit, dest_port, mirror_port, is_lossless), "");

    /** Get the dest_port information in order to determine the core */
    BCM_IF_ERROR_RETURN_MSG(bcm_port_get(unit, dest_port, &flags, &interface_info, &mapping_info), "");

    /** Set the rate of mirror recycle interface on the corresponding core */
    BCM_IF_ERROR_RETURN_MSG(cint_dnx_mirror_bandwidth_set(unit, mapping_info.core, rate), "");

    /** Disable EIR shapers on the corresponding core in order to use the CIR shapers */
    BCM_IF_ERROR_RETURN_MSG(cint_dnx_recycle_mirror_weight_config(unit, mapping_info.core, 0, 0), "");
    return BCM_E_NONE;
}

/** Main unction for Recycle example.
  * - unit : Unit ID
  * - recycle_port : recycle port for which the L2 entry will bw created and the rate will be set
  * - rate : rate to set the recycle interface with
  */
int cint_dnx_recycle_config(
    int unit,
    bcm_port_t recycle_port,
    int rate)
{
    int rv;
    uint32 flags;
    bcm_gport_t gport;
    bcm_port_interface_info_t interface_info;
    bcm_port_mapping_info_t   mapping_info;
    bcm_mac_t mac = {0x0,0x0,0x0,0x0,0x0,0x1};
    int vlan = 100;

    /** Delete L2 entry, in case previous entry for the same MAC and VAN exists */
    rv = bcm_l2_addr_delete(unit, mac, vlan);
    if (rv == BCM_E_NOT_FOUND) {
        rv = BCM_E_NONE;
    }
    BCM_IF_ERROR_RETURN_MSG(rv, "");

    /** Add an L2 entry for the recycle port */
    BCM_GPORT_LOCAL_SET(gport, recycle_port);
    BCM_IF_ERROR_RETURN_MSG(l2_entry_add(unit, mac, vlan, 0, gport, 0), "");

    /** Get the recycle_port information in order to determine the core */
    BCM_IF_ERROR_RETURN_MSG(bcm_port_get(unit, recycle_port, &flags, &interface_info, &mapping_info), "");

    /** Set the rate of recycle interface on the corresponding core */
    BCM_IF_ERROR_RETURN_MSG(cint_dnx_recycle_bandwidth_set(unit, mapping_info.core, rate), "");

    /** Disable EIR shapers on the corresponding core in order to use the CIR shapers */
    BCM_IF_ERROR_RETURN_MSG(cint_dnx_recycle_mirror_weight_config(unit, mapping_info.core, 0, 0), "");
    return BCM_E_NONE;
}

