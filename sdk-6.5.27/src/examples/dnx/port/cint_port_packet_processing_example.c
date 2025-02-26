/* 
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2022 Broadcom Inc. All rights reserved.
 *
 * File:        cint_port_packet_processing_example.c
 * Purpose:     Example of adding a port and applying pp properties to it
 *
 * Example includes:
 *      Adding one port configuration including port header type configuration, applying packet processing properties
 *
 * Usage Example:
 * Test Scenario - start
    *c
    *cint_reset();
    *exit;
    cint ../../../../src/examples/dnx/port/cint_dynamic_port_add_remove.c
    cint ../../../../src/examples/dnx/port/cint_port_packet_processing_example.c
 
    c
    print "add port 18";
    int unit;
    bcm_port_t port;
    int rate_mhz;
    int fec_type;
    unit = 0;
    port = 18;
    bcm_pbmp_t phy_pbmp;
    BCM_PBMP_CLEAR(phy_pbmp);
    BCM_PBMP_PORT_SET(phy_pbmp,port);
    rate_mhz = 10000;
    fec_type = BCM_PORT_RESOURCE_DEFAULT_REQUEST;
    int port_header_type_in = BCM_SWITCH_PORT_HEADER_TYPE_INJECTED_2_PP;
    int port_header_type_out = BCM_SWITCH_PORT_HEADER_TYPE_ETH;
    print cint_port_packet_processing_add_eth_port(unit,port,phy_pbmp,rate_mhz,fec_type,port_header_type_in,port_header_type_out);
 
    c
    print "Set port header type";
    int unit;
    bcm_port_t port;
    int port_header_type_in;
    int port_header_type_out;
    unit = 0;
    port = 18;
    port_header_type_in = BCM_SWITCH_PORT_HEADER_TYPE_INJECTED_2_PP;
    port_header_type_out = BCM_SWITCH_PORT_HEADER_TYPE_ETH;
    print cint_port_packet_processing_header_type_set(unit,port,port_header_type_in,port_header_type_out);
    exit;
 
    c
    print "Set packet processing propeties to removed trunk member"
    int unit;
    bcm_port_t port;
    bcm_vlan_t vlan;
    bcm_gport_t vlan_port_id; 
    unit = 0;
    port = 18;
    vlan = 5;
    print cint_port_packet_processing_removed_trunk_member_pp_properties_set(unit,port,vlan,&vlan_port_id);
    exit;
 
    c
    print ""
    int unit;
    bcm_port_t port;
    bcm_vlan_t vlan;
    unit = 0;
    port = 18;
    vlan = 5;
    print cint_port_packet_processing_pp_properties_unset(unit,port,vlan);
    exit;
 * Test Scenario - end

 */

/**
 * \brief - Configure pp properties to removed trunk member
 * Configure vlan domain, set VLAN-membership-namespace, set vlan port membership,
 * configure vlan for untagged cases, configure in_lif same interface
 * enable learning, set port default-LIF to simple bridge and set stp state to FORWARD,
 * Create vlan port with match criteria the port itself 
 *  
 * \param [in] unit - Unit ID
 * \param [in] port - Logical port
 * \param [in] vlan - Vlan ID 
 * \param [out] vlan_port_id - Vlan port ID  
 *
 * \return
 *   int
 *
 * \remark
 *   * None
 * \see
 *   * None
 */
int
cint_port_packet_processing_removed_trunk_member_pp_properties_set(
    int unit,
    bcm_port_t port,
    bcm_vlan_t vlan,
    bcm_gport_t  *vlan_port_id)
{
    uint32 class_id;
    uint32 flags;
    bcm_vlan_port_t vlan_port;
    char error_msg[200]={0,};

    flags = BCM_PORT_LEARN_ARL | BCM_PORT_LEARN_FWD;
    class_id = port;

    /** Configure vlan domain per port*/
    BCM_IF_ERROR_RETURN_MSG(bcm_port_class_set(unit, port, bcmPortClassId, class_id), "");

    /** Set VLAN-membership-namespace */
    BCM_IF_ERROR_RETURN_MSG(bcm_port_class_set(unit, port, bcmPortClassVlanMember, class_id), "");

    /** Set vlan port membership */
    BCM_IF_ERROR_RETURN_MSG(bcm_vlan_gport_add(unit, BCM_VLAN_DEFAULT, port, 0), "");

    /** Configure inlif same interface*/
    BCM_IF_ERROR_RETURN_MSG(bcm_port_control_set(unit, port, bcmPortControlBridge, TRUE), "");

    /** Configure vlan for untag cases*/
    BCM_IF_ERROR_RETURN_MSG(bcm_port_untagged_vlan_set(unit, port, BCM_VLAN_DEFAULT), "");

    /** Enable learning */
    BCM_IF_ERROR_RETURN_MSG(bcm_port_learn_set(unit, port, flags), "");

    /** Configure default stp state as FORWARD per ethernet port */
    BCM_IF_ERROR_RETURN_MSG(bcm_port_stp_set(unit, port, BCM_STG_STP_FORWARD), "");

    /** Set port default-LIF to simple bridge:  */
    BCM_IF_ERROR_RETURN_MSG(bcm_vlan_control_port_set(unit, port, bcmVlanTranslateIngressMissDrop, 0), "");

    /** Create VLAN-Port with criteria BCM_VLAN_PORT_MATCH_PORT */
    bcm_vlan_port_t_init(&vlan_port);
    vlan_port.flags = BCM_VLAN_PORT_CREATE_INGRESS_ONLY;
    vlan_port.criteria = BCM_VLAN_PORT_MATCH_PORT;
    vlan_port.port = port;
    vlan_port.vsi = vlan;
    snprintf(error_msg, sizeof(error_msg), "for port %d, vsi - %d", port, vlan);
    BCM_IF_ERROR_RETURN_MSG(bcm_vlan_port_create(unit, &vlan_port), error_msg);
    *vlan_port_id = vlan_port.vlan_port_id;

    return BCM_E_NONE;
}

/**
 * \brief - Remove pp properties from a port
 * Remove vlan domain, VLAN-membership-namespace, vlan port membership,
 * vlan for untagged cases. Disable in_lif same interface and learning.
 * Set port default-LIF to drop-LIF and disable stp state.
 *  
 * \param [in] unit - Unit ID
 * \param [in] port - Logical port
 *
 * \return
 *   int
 *
 * \remark
 *   * None
 * \see
 *   * None
 */
int
cint_port_packet_processing_pp_properties_unset(
    int unit,
    bcm_port_t port)
{
    bcm_vlan_port_t vlan_port;

    /** Remove vlan domain */
    BCM_IF_ERROR_RETURN_MSG(bcm_port_class_set(unit, port, bcmPortClassId, 0), "");

    /** Remove VLAN-membership-namespace */
    BCM_IF_ERROR_RETURN_MSG(bcm_port_class_set(unit, port, bcmPortClassVlanMember, 0), "");

    /** Delete vlan port membership */
    BCM_IF_ERROR_RETURN_MSG(bcm_vlan_gport_delete(unit, BCM_VLAN_DEFAULT, port), "");

    /** Disable inlif same interface*/
    BCM_IF_ERROR_RETURN_MSG(bcm_port_control_set(unit, port, bcmPortControlBridge, FALSE), "");

    /** Remove vlan for untag cases*/
    BCM_IF_ERROR_RETURN_MSG(bcm_port_untagged_vlan_set(unit, port, 0), "");

    /** Configure stp state to DISABLE */
    BCM_IF_ERROR_RETURN_MSG(bcm_port_stp_set(unit, port, BCM_STG_STP_DISABLE), "");

    /** Enable drop using drop-LIF */
    BCM_IF_ERROR_RETURN_MSG(bcm_vlan_control_port_set(unit, port, bcmVlanTranslateIngressMissDrop, 1), "");

    return BCM_E_NONE;
}

/**
 * \brief   Full example to add port and set relevant shapers
 *  
 * stage 1: Add new port
 * stage 2: Configure NIF
 * stage 3: configure egr and sch shapers
 * stage 4: Configure PP properties
 * stage 5: configure application reference
 * stage 6: enable the port 
 *  
 * \param [in] unit  - Unit number
 * \param [in] port  - Logical port to add
 * \param [in] mapping_info - Logical port mapping info
 * \param [in] interface_info  - physical port info
 * \param [in] resource - NIF resource (speed, link training and FEC.
 *                              All other struct fields, including FW control word - are ignored
 * \param [in] dfe_mode - dfe mode: on, low power or off
 * \param [in] medium_type - medium type: backplane, copper cable or optic
 * \param [in] header_type_in  - incomming header type
 * \param [in] header_type_out - outgoing header type
 * \param [in] flags  - flags for bcm_port_add API (BCM_PORT_ADD_XX_PORT)
 *
 * \return
 *   int
 *
 * \remark
 *   * None
 * \see
 *   * None
 *
 */
int
cint_port_packet_processing_add_port_full_example(
    int unit,
    bcm_port_t port,
    bcm_port_mapping_info_t mapping_info,
    bcm_port_interface_info_t interface_info,
    bcm_port_resource_t resource,
    dfe_mode_t dfe_mode,
    medium_type_t medium_type,
    int header_type_in,
    int header_type_out,
    uint32 flags)
{

    return cint_port_packet_processing_add_ports_full_example(unit, 1, &port, &mapping_info, &interface_info, &resource, &dfe_mode, 
                                                &medium_type, &header_type_in, &header_type_out, &flags);
}

/**
 * \brief
 *      Full example to add ports and set relevant shapers
 *      This example is used to configure port resouces for multi ports
 *      simultaneously using API bcm_port_resource_multi_set. This example
 *      can provide better port VCO assignment when configuring multi ports
 *      on one PM.
 * stage 1: Add new ports
 * stage 2: Configure NIF resources
 * stage 3: Configure egr and sch shapers
 * stage 4: Configure switch port header types for both directions
 * stage 5: Configure application reference
 * stage 6: Enable the ports 
 *  
 * \param [in] unit - Unit number.
 * \param [in] nof_ports -  Number of ports
 * \param [in] port_list  -  Ports array
 * \param [in] mapping_info - Logical port mapping info
 * \param [in] interface_info - physical port info
 * \param [in] resource - NIF resource (speed, link training and FEC.
 *                              All other struct fields, including FW control word - are ignored
 * \param [in] dfe_mode - dfe mode: on, low power or off
 * \param [in] medium_type - medium type: backplane, copper cable or optic
 * \param [in] header_type_in - incomming header type
 * \param [in] header_type_out - outgoing header type
 * \param [in] flags - flags for bcm_port_add API
 *
 * \return
 *   int
 *
 * \remark
 *   * None
 * \see
 *   * None
 *
 */

int
cint_port_packet_processing_add_ports_full_example(
    int unit,
    int nof_ports,
    bcm_port_t *port_list,
    bcm_port_mapping_info_t *mapping_info,
    bcm_port_interface_info_t *interface_info,
    bcm_port_resource_t *resource,
    dfe_mode_t *dfe_mode,
    medium_type_t *medium_type,
    int *header_type_in,
    int *header_type_out,
    uint32 *flags)
{

    appl_dnx_sys_device_t *sys_params;
    int device_id[nof_ports];
    int devid;
    int i;
    
    /** Get a pointer to the system parameters */
    BCM_IF_ERROR_RETURN_MSG(appl_dnx_sys_device_params_get(unit, &sys_params), "");
    /** always assume local port */
    devid = sys_params->unit_to_device_index[unit];

    for(i=0; i < nof_ports; i++)
    {
        device_id[i] = devid;
    }

    BCM_IF_ERROR_RETURN_MSG(cint_dyn_port_add_ports_full_example_pp(unit, nof_ports, port_list, device_id, mapping_info, interface_info, resource, dfe_mode,
                                                   medium_type, header_type_in, header_type_out, flags, 1), "");
    return BCM_E_NONE;

}


/** 
 * \brief - The below cint function is an example for adding normal eth port
 *  Port description:
 *  - Logical port, phys and rate - user decision (input arguments)
 *  - SerDes configuration to suite simple loopback or p2p cable connected port:
 *     - Link training: 'on'
 *     - DFE: 'on'
 *     - medium type: 'copper'
 *  - NIF interface: ETH
 *  - Header type (in and out): user decision
 *  - FEC: default according to speed
 *  - TM port: same id as the logical port
 *  - Priorities: 2
 *
 * */
int
cint_port_packet_processing_add_eth_port(
    int unit,
    bcm_port_t port,
    bcm_pbmp_t phy_pbmp,
    int rate_mhz,
    int fec_type,
    int header_type_in,
    int header_type_out)
{
    bcm_port_mapping_info_t mapping_info;
    bcm_port_interface_info_t interface_info;
    int first_phy;
    int nof_links_per_core;
    uint32 nof_cores, nof_links;
    bcm_port_resource_t resource;
    dfe_mode_t dfe_mode;
    medium_type_t medium_type;
    uint32 flags = 0;
    char error_msg[200]={0,};

    /** init vars */
    sal_memset(&interface_info, 0, sizeof(interface_info));
    bcm_port_mapping_info_t_init(&mapping_info);
    bcm_port_resource_t_init(resource);

    /** Configuring  interface_info*/
    interface_info.interface = BCM_PORT_IF_NIF_ETH;
    BCM_PBMP_ASSIGN(interface_info.phy_pbmp, phy_pbmp);

    /** Configuring  mapping_info*/
    BCM_PBMP_ITER(phy_pbmp, first_phy)
    {
        break;
    }
    nof_links = *(dnxc_data_get(unit, "nif", "phys", "nof_phys", NULL));
    nof_cores = *(dnxc_data_get(unit, "device", "general", "nof_cores", NULL));
    nof_links_per_core = nof_links / nof_cores;
    mapping_info.core = first_phy / nof_links_per_core;
    mapping_info.channel = 0;
    mapping_info.tm_port = port;
    mapping_info.num_priorities = 2;

    /** Configuring NIF resource*/
    resource.port = port;
    resource.speed = rate_mhz;
    resource.fec_type = fec_type;
    resource.link_training = 1;
    resource.phy_lane_config = BCM_PORT_RESOURCE_DEFAULT_REQUEST;
    /** We can't pass default inside phy_lane_config so we pass 2 of them (dfe_mode and medium type) - specifically */
    dfe_mode = dfe_on;
    medium_type = copper_cable;

    /** Add the port */
    snprintf(error_msg, sizeof(error_msg), "unit: %d, logical_port: %d", unit, port);
    BCM_IF_ERROR_RETURN_MSG(cint_port_packet_processing_add_port_full_example(unit, port, mapping_info, interface_info, resource,
                                             dfe_mode, medium_type, header_type_in, header_type_out, flags), error_msg);

    return BCM_E_NONE;
}

