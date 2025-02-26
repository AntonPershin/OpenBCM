/*
 * 
 This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 
 Copyright 2007-2022 Broadcom Inc. All rights reserved. File: cint_vpls_mp_basic.c Purpose: basic example for VPLS. 
 */

/*
 * 
 * Configuration:
 * 
 * Test Scenario - start
 * cint;
 * cint_reset();
 * exit;
  cint ../../../../src/examples/dnx/utility/cint_dnx_utils_global.c
  cint ../../../../src/examples/dnx/cint_ip_route_basic.c
  cint ../../../../src/examples/dnx/vpls/cint_vpls_pwe_tagged_mode_basic.c
  cint ../../../../src/examples/dnx/utility/cint_dnx_utils_vlan_translate.c
  cint
  int unit = 0; 
  int rv = 0; 
  int in_port = 200; 
  int out_port = 201;
  rv = vpls_pwe_tagged_mode_basic_main(unit,in_port,out_port);
  print rv; 
 * Test Scenario - end
 * 
 *  Scenario configured in this cint:
 * 
 *  ~~~~~~~~~~~~~~~~~~~~~~~~~
 *   Basic VPLS Termination
 *  ~~~~~~~~~~~~~~~~~~~~~~~~~
 *  One MPLS label is terminated with the PWE label. 
 *  Lookup in MAC table for ethernet forwarding.
 *
 *  Traffic:
 * 
 *  Send the following traffic:
 *
 *  ##############################################################################################
 *  Sending packet from port == 200 :   ----------->
 *   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 *   |    +-+-+-+-+-+-+-+-+-+-+-+-+-++-+-+-+-+-+-+-+-+-++-+-+-+-+-+-+-+-+-+-+-+-+-++-+-+-+-
 *   |    |      DA              | SA                   ||   MPLS   ||  PWE         ||      DA              |     SA                || vlan | tpid
 *   |    |0C:00:02:00:01   |0c:00:02:00:00   ||Label:3333||Label:3456  ||11:00:00:01:12 |0c:00:02:00:00    || 5    | 0x8100
 *   |    |                         |                       ||Exp:0     ||                  ||                  |                               ||
 *   |    |                         |                       ||TTL:20    ||                  ||                  |                           ||
 *   |    +-+-+-+-+-+-+-+-+-+-+-+-+-+--+-+-+-+-+-+-+-+-++-+-+-+-+-+-+-+-+-+-+-+-+-+--+-+-+-
 *   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * 
 *  Receiving packet on port == 201:   <------------
 *   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 *   |    +-+-+-+-+-+-+-+-+-+-+-+-+-++-+-+-++-+-+-+-+-+-+-+-+-+-+-+-+-++-+-+-+-
 *   |    |      DA              |     SA                || vlan | tpid
 *   |    |11:00:00:01:12 |0c:00:02:00:00    || 5    | 0x8100
 *   |    |              |              ||          ||               ||      ||
 *   |    |              |              ||          ||               ||      ||
 *   |    +-+-+-+-+-+-+-+-+-+-+-+-+-+--+-+-++-+-+-+-+-+-+-+-+-+-+-+-+-+--+-+-+-
 *   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * ###############################################################################################
 *
 *  ~~~~~~~~~~~~~~~~~~~~~~~~~
 *   Basic VPLS encapsulation
 *  ~~~~~~~~~~~~~~~~~~~~~~~~~
 *  Route into a PWE over MPLS core. 
 *  Exit with a packet including an MPLS and PWE labels.
 *
 *  Traffic:
 * 
 *  Send the following traffic:
 *
 *  ##############################################################################################
 *  Receiving packet on port == 201:   <------------
 *   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 *   |    +-+-+-+-+-+-+-+-+-+-+-+-+-++-+-+-++-+-+-+-+-+-+-+-+-+-+-+-+-++-+-+-+-
 *   |    |      DA              |     SA                || vlan | tpid
 *   |    |0c:00:02:00:00   |11:00:00:01:12    || 5    | 0x8100
 *   |    |              |              ||          ||               ||      ||
 *   |    |              |              ||          ||               ||      ||
 *   |    +-+-+-+-+-+-+-+-+-+-+-+-+-+--+-+-++-+-+-+-+-+-+-+-+-+-+-+-+-+--+-+-+-
 *   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 *
 *  Sending packet from port == 200 :   ----------->
 *   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 *   |    +-+-+-+-+-+-+-+-+-+-+-+-+-++-+-+-+-+-+-+-+-+-++-+-+-+-+-+-+-+-+-+-+-+-+-++-+-+-+-
 *   |    |      DA              | SA                   ||   MPLS   ||  PWE         ||      DA              |     SA                || vlan | tpid
 *   |    |0c:00:02:00:01   |00:00:00:cd:1d   ||Label:3333||Label:3456  || 0c:00:02:00:00   |11:00:00:01:12  || 1111 | 0x8100
 *   |    |                         |                       ||Exp:0     ||                  ||               ||      ||
 *   |    |                         |                       ||TTL:20    ||                  ||               ||      ||
 *   |    +-+-+-+-+-+-+-+-+-+-+-+-+-+--+-+-+-+-+-+-+-+-++-+-+-+-+-+-+-+-+-+-+-+-+-+--+-+-+-
 *   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * ###############################################################################################
 *
 * ###############################################################################################
 * P2P (cross connect):
 * This cint shows also two examples for VPLS P2P traffic:
 * Gliful and Glifless PWE tagged mode - both for access->core and for core->access traffic
 * vpls_pwe_tagged_mode_p2p_basic_main
 * vpls_pwe_tagged_mode_basic_indexed_native_ac_p2p_main
 * ###############################################################################################
 */

struct cint_vpls_pwe_tagged_mode_basic_info_s
{
    int access_port;            /* incoming port from acsess side */
    int core_port;              /* incoming port from core side */
    int core_eth_rif;           /* core RIF */
    bcm_vpn_t service_vsi;      /* vsi id */
    bcm_gport_t mpls_port_id_ing;       /* global lif encoded as MPLS port for service (ingress side) */
    bcm_gport_t mpls_port_id_eg;        /* global lif encoded as MPLS port for service (egress side) */
    bcm_gport_t outer_ac_vlan_port_id;  /* vlan port id of the ac_port, used for ingress */
    bcm_if_t pwe_encap_id;      /* The global lif of the EEDB PWE entry. */
    bcm_if_t indexed_ac_encap_id;       /* The global lif of the indexed AC entry. */
    int core_arp_id;            /* Id for core ARP entry */
    int mpls_fec_id;            /* service 1 fec id for encapsulation entry - outlif for MPLS entry in EEDB */
    bcm_mac_t core_eth_rif_mac; /* mac for core RIF */
    bcm_mac_t core_next_hop_mac;        /* mac for next hop */
    bcm_mac_t service_mac_1;    /* first mac address for service 1 */
    bcm_mac_t service_mac_2;    /* second mac address for service 1 */
    int outer_tpid;             /* Outer tpid for application */
    int inner_tpid;             /* Inner tpid for application */
    bcm_if_t mpls_tunnel_id;    /* tunnel id for encapsulation entry */
    bcm_mpls_label_t service_mpls_tunnel_label_1;       /* pushed label */
    bcm_mpls_label_t service_mpls_tunnel_label_2;       /* pushed label */
    bcm_mpls_label_t service_pwe_label; /* pwe label */
    bcm_vlan_t outer_ac_egress_outer_vlan;
    bcm_vlan_t outer_ac_egress_inner_vlan;
    bcm_vlan_t ingress_canonical_outer_vlan;
    bcm_vlan_t ingress_canonical_inner_vlan;
    bcm_vlan_t egress_canonical_outer_vlan;
    bcm_vlan_t egress_canonical_inner_vlan;
    bcm_port_tag_format_class_t tag_format_untagged;
    bcm_port_tag_format_class_t tag_format_double_tagged;
    bcm_gport_t ingress_native_ac_vlan_port_id; /* vlan port id of the inner ac_port, used for ingress */
    bcm_gport_t egress_native_ac_vlan_port_id;  /* vlan port id of the inner ac_port, used for egress */
    bcm_gport_t access_egress_vlan_port_id;     /* vlan port id of the access port, used for egress at terination flow */
    uint32 egress_vlan_edit_profile, ingress_vlan_edit_profile;
    bcm_gport_t access_port_ac_in_lif;
};

cint_vpls_pwe_tagged_mode_basic_info_s cint_vpls_pwe_tagged_mode_basic_info = {
    /*
     * ports : access_port | core_port 
     */
    200, 201,
    /*
     * core_eth_rif
     */
    30,
    /*
     * service_vsi  
     */
    10,
    /*
     * mpls_port_id_ing|eg | outer_ac_vlan_port_id | pwe_encap_id | indexed_ac_encap_id
     */
    9999, 18888, 1111, 0, 0,
    /*
     * core_arp_id
     */
    12290,
    /*
     * mpls_fec_id  
     */
    50001,
    /*
     * core_eth_rif_mac
     */
    {0x00, 0x0F, 0x00, 0x02, 0x0A, 0x22},
    /*
     * core_next_hop_mac  
     */
    {0x00, 0x00, 0x00, 0x00, 0xCD, 0x1D},
    /*
     * service_mac_1   |   service_mac_2 
     */
    {0x00, 0x0C, 0x00, 0x02, 0x0C, 0x33}, {0x00, 0x0C, 0x00, 0x02, 0x0C, 0x44},
    /*
     * outer_tpid | inner_tpid 
     */
    0x9100, 0x8100,
    /*
     * mpls_tunnel_id 
     */
    40962,
    /*
     * service_mpls_tunnel_label_1  | service_mpls_tunnel_label_2 |  service_pwe_label
     */
    4444, 5555, 3333,
    /*
     * outer_ac_egress_outer_vlan | outer_ac_egress_inner_vlan
     */
    327, 427,
    /*
     * ingress_canonical_outer_vlan | ingress_canonical_inner_vlan
     */
    1000, 2000,
    /*
     * egress_canonical_outer_vlan | egress_canonical_inner_vlan
     */
    1000, 2000,
    /*
     * tag_format_untagged,  tag_format_double_tagged
     */
    0, 16,
    /*
     * ingress_native_ac_vlan_port_id,egress_native_ac_vlan_port_id,access_egress_vlan_port_id
     */
    0x1234, 0x6321, 0x8567,
    /*
     * egress_vlan_edit_profile, ingress_vlan_edit_profile 
     */
    4, 5,
    /*
     * access_port ac in lif
     */
    0

};

struct cint_vpls_pwe_tagged_mode_extended_p2p_info_s
{
    int nof_service_tag_types;             /* Kinds of nof_service_tags.*/
    int ing_outer_stag;                    /* Outer service tag for termination flow.*/
    int ing_inner_stag;                    /* inner service tag for termination flow.*/
    bcm_gport_t mpls_port_id_ing[4];       /* global lif encoded as MPLS port for service (ingress side) */
    bcm_gport_t access_egress_vlan_port_id[4];     /* vlan port id of the access port, used for egress at termination flow */
    bcm_gport_t access_egress_vlan_port_id2[4];     /* vlan port id of the access port, used for egress at termination flow */
    bcm_mpls_label_t service_pwe_label[4]; /* pwe label */
    bcm_port_tag_format_class_t egr_tag_format[3];  /* tag format for nof service tag = 0/1/2 cases.*/
    bcm_vlan_action_t egr_vlan_action[3][2]; /* Outer and inner vlan action for nof service tag = 0/1/2 cases.*/
    bcm_vlan_t egress_outer_vlan[3];         /* Egress Outer lan for core -> customer traffic. Used by EVE in nof service tag = 0/1/2 cases.*/
    bcm_vlan_t egress_inner_vlan[3];         /* Egress Inner lan for core -> customer traffic. Used by EVE in nof service tag = 0/1/2 cases.*/
};

cint_vpls_pwe_tagged_mode_extended_p2p_info_s cint_vpls_pwe_tagged_mode_extended_p2p_info = {
    /** nof_service_tag_types: 0/1/2/x */
    4,
    /** ing_outer_stag */
    200,
    /** ing_inner_stag */
    300,
    /** mpls_port_id for nof_service_tag = 0/1/2/x*/
    {9000, 9001, 9002, 9003},
    /** access_egress_vlan_port_id for nof_service_tag = 0/1/2/x*/
    {0x1500, 0x1501, 0x1502, 0x1503},
    /** access_egress_vlan_port_id2 for nof_service_tag = 0/1/2/x*/
    {0x2500, 0x2501, 0x2502, 0x2503},
    /** pwe label for nof_service_tag = 0/1/2/x*/
    {3000, 3001, 3302, 3303},
    /** egr_tag_format for nof_service_tag = 0/1/2 */
    {0, 4, 16},
    /** egr_vlan_action for nof_service_tag = 0/1/2 */
    {{bcmVlanActionAdd, bcmVlanActionAdd}, {bcmVlanActionReplace, bcmVlanActionAdd}, {bcmVlanActionReplace, bcmVlanActionReplace}},
    /** egress_outer_vlan for nof_service_tag = 0/1/2/x*/
    {1000, 1001, 1002},
    /** egress_inner_vlan for nof_service_tag = 0/1/2/x*/
    {2000, 2001, 2002}
};


int verbose1 = 1;

/*
 * This variable is relevant to OAM.
 * For downmep, global lif should be set in ingress LIF DB.
 * After setting is_oam to 1, then global lif for native AC in pwe indexed tagged mode will be set.
 */
int is_oam = 0;

int pwe_network_domain = 507;

void
vpls_pwe_tagged_mode_basic_init(
    int access_port,
    int core_port)
{

    cint_vpls_pwe_tagged_mode_basic_info.access_port = access_port;
    cint_vpls_pwe_tagged_mode_basic_info.core_port = core_port;

}

/*
 * Creates the AC In-Lif for Access AC port.
 * In case of p2p - keep the value to cross connect it
 */
int
vpls_pwe_tagged_mode_basic_access_ac_create(
    int unit,
    int in_port,
    int eth_rif,
    int is_p2p,
    bcm_gport_t *ac_in_lif)
{

    if(!is_p2p)
    {
        BCM_IF_ERROR_RETURN_MSG(in_port_intf_set(unit, in_port, eth_rif), "");
    }
    else
    {
        bcm_vlan_port_t vlan_port;
        bcm_vlan_port_t_init(&vlan_port);
        vlan_port.port = in_port;
        vlan_port.vsi = eth_rif;
        vlan_port.criteria = BCM_VLAN_PORT_MATCH_PORT;
        vlan_port.flags = BCM_VLAN_PORT_CREATE_INGRESS_ONLY;

        BCM_IF_ERROR_RETURN_MSG(bcm_vlan_port_create(unit, vlan_port), "");
        printf("vpls_pwe_tagged_mode_basic_access_ac_create(): port = %d, in_lif = 0x%08X\n", vlan_port.port, vlan_port.vlan_port_id);
        *ac_in_lif = vlan_port.vlan_port_id;
    }

    return BCM_E_NONE;
}

int
vpls_pwe_tagged_mode_basic_configure_port_properties(
    int unit,
    int access_port,
    int core_port,
    bcm_vpn_t service_vsi,
    int core_eth_rif,
    int is_cross_connect)
{
    char error_msg[200]={0,};

    /*
     * set class for both ports 
     */
    if (!BCM_GPORT_IS_TRUNK(access_port) && !BCM_GPORT_IS_TRUNK(core_port)) {
        snprintf(error_msg, sizeof(error_msg), "port=%d", access_port);
        BCM_IF_ERROR_RETURN_MSG(bcm_port_class_set(unit, access_port, bcmPortClassId, access_port), error_msg);

        snprintf(error_msg, sizeof(error_msg), "port=%d", core_port);
        BCM_IF_ERROR_RETURN_MSG(bcm_port_class_set(unit, core_port, bcmPortClassId, core_port), error_msg);
    }

    /*
     * Set In-Port to In ETh-RIF 
     */

    BCM_IF_ERROR_RETURN_MSG(vpls_pwe_tagged_mode_basic_access_ac_create(unit, access_port, service_vsi, is_cross_connect, &(cint_vpls_pwe_tagged_mode_basic_info.access_port_ac_in_lif)), "intf_in");

    /*
     * Set In-Port to In ETh-RIF 
     */
    BCM_IF_ERROR_RETURN_MSG(in_port_intf_set(unit, core_port, core_eth_rif), "intf_in");

    /*
     * Set Out-Port default properties 
     */
    BCM_IF_ERROR_RETURN_MSG(out_port_set(unit, access_port), "intf_out");

    /*
     * Set Out-Port default properties 
     */
    BCM_IF_ERROR_RETURN_MSG(out_port_set(unit, core_port), "intf_out");

    return BCM_E_NONE;
}

int
vpls_pwe_tagged_mode_basic_create_vsis(
    int unit,
    bcm_vpn_t service_vsi,
    int core_eth_rif)
{

    char error_msg[200]={0,};

    /*
     * create vlan based on the vsi (vpn) 
     */
    snprintf(error_msg, sizeof(error_msg), "Failed to create VLAN %d", service_vsi);
    BCM_IF_ERROR_RETURN_MSG(bcm_vlan_create(unit, service_vsi), error_msg);

    /*
     * create vlan based on the vsi (vpn) 
     */
    snprintf(error_msg, sizeof(error_msg), "Failed to create VLAN %d", core_eth_rif);
    BCM_IF_ERROR_RETURN_MSG(bcm_vlan_create(unit, core_eth_rif), error_msg);

    return BCM_E_NONE;
}

int
vpls_pwe_tagged_mode_basic_create_l3_interfaces(
    int unit,
    int core_eth_rif,
    bcm_mac_t core_eth_rif_mac)
{


    BCM_IF_ERROR_RETURN_MSG(intf_eth_rif_create(unit, core_eth_rif, core_eth_rif_mac), "pwe_intf");

    return BCM_E_NONE;
}

int
vpls_pwe_tagged_mode_basic_create_arp_entry(
    int unit,
    int *core_arp_id,
    bcm_mac_t core_next_hop_mac,
    int core_eth_rif)
{

    /*
     * Configure ARP entry 
     */
    BCM_IF_ERROR_RETURN_MSG(l3__egress_only_encap__create(unit, 0, core_arp_id, core_next_hop_mac, core_eth_rif),
        "create AC egress object ARP only");

    return BCM_E_NONE;

}

int
vpls_pwe_tagged_mode_basic_create_fec_entry(
    int unit,
    int fec_id,
    bcm_if_t tunnel_id,
    int port)
{
    int temp_out_rif;
    int flags = 0;
    uint32 system_headers_mode = *(dnxc_data_get(unit,  "headers", "system_headers", "system_headers_mode", NULL));
    /**
     * Under below scenarios, this case tests the FEC format of dest+EEI:
     * 1. JR2 works under JR1 system headers mode;
     */
    if (system_headers_mode == 0)
    {
        flags = BCM_L3_ENCAP_SPACE_OPTIMIZED;
    }
    /*
     * Create FEC: 
     * 1) Give a fec id. 
     * 2) Tunnel id of the encapsulation entry. 
     * 3) Arp id will be given with the only_encap call, so give 0. 
     * 4) Give the out port. 
     */
    int fec_flags2 = 0;
    if(*dnxc_data_get(unit, "l3", "feature", "separate_fwd_rpf_dbs", NULL))
    {
        fec_flags2 |= BCM_L3_FLAGS2_FWD_ONLY;
    }
    BCM_IF_ERROR_RETURN_MSG(l3__egress_only_fec__create(unit, fec_id, tunnel_id, 0, port, flags, fec_flags2),
        "create egress object FEC only");

    /*
     * The termination scenario doesn't need FEC. 
     * We bridge out of the core with no usage of FEC.
     */

    return BCM_E_NONE;
}

int
vpls_pwe_tagged_mode_basic_create_mpls_tunnel(
    int unit,
    bcm_mpls_label_t outer_label,
    bcm_mpls_label_t inner_label,
    int num_labels,
    int arp_id,
    bcm_if_t * tunnel_id,
    int is_virtual)
{

    bcm_mpls_egress_label_t label_array[2];

    bcm_mpls_egress_label_t_init(&label_array[0]);
    bcm_mpls_egress_label_t_init(&label_array[1]);

    /*
     * Label to be pushed as part of the MPLS tunnel.
     */
    label_array[0].label = outer_label;

    label_array[0].flags = BCM_MPLS_EGRESS_LABEL_WITH_ID | BCM_MPLS_EGRESS_LABEL_TTL_DECREMENT;
    if (!is_virtual)
    {
        label_array[0].encap_access = bcmEncapAccessTunnel3;
    }
    BCM_L3_ITF_SET(label_array[0].tunnel_id, BCM_L3_ITF_TYPE_LIF, *tunnel_id);
    
    /*
     * Set the next pointer of this entry to be the arp. This configuration is new compared to Jericho, where the arp
     * pointer used to be connected to the EEDB entry via bcm_l3_egress_create (with egress flag indication).
     */
    label_array[0].l3_intf_id = arp_id;

    if (num_labels == 2)
    {
        label_array[1].label = inner_label;
        label_array[1].flags = BCM_MPLS_EGRESS_LABEL_WITH_ID | BCM_MPLS_EGRESS_LABEL_TTL_DECREMENT;
        label_array[1].tunnel_id = label_array[0].tunnel_id;
        label_array[1].l3_intf_id = label_array[0].l3_intf_id;
        label_array[1].encap_access = label_array[0].encap_access;
    }

    BCM_IF_ERROR_RETURN_MSG(bcm_mpls_tunnel_initiator_create(unit, 0, num_labels, label_array), "");

    *tunnel_id = label_array[0].tunnel_id;

    printf("mpls encapsulation tunnel id: 0x%08x\n", *tunnel_id);

    return BCM_E_NONE;

}

int
vpls_pwe_tagged_mode_basic_create_termination_stack(
    int unit,
    bcm_mpls_label_t * labels,
    int nof_labels)
{
    bcm_mpls_tunnel_switch_t entry;
    int i;
    /*
     * Create a stack of MPLS labels to be terminated 
     */

    for (i = 0; i < nof_labels; i++)
    {
        bcm_mpls_tunnel_switch_t_init(&entry);

        entry.action = BCM_MPLS_SWITCH_ACTION_POP;

        /*
         * incoming label
         * only the mpls tunnel label needs to be defined here.
         * pwe label will be handed as part of the ingress mpls_port_add api
         */
        entry.label = labels[i];

        BCM_IF_ERROR_RETURN_MSG(bcm_mpls_tunnel_switch_create(unit, &entry), "");
    }

    return BCM_E_NONE;

}

int
vpls_pwe_tagged_mode_basic_l2_addr_add(
    int unit,
    int vsi,
    bcm_mac_t mac,
    bcm_if_t encap_id,
    int fec_id)
{
    bcm_l2_addr_t l2addr;

    bcm_l2_addr_t_init(&l2addr, mac, vsi);
    l2addr.flags |= BCM_L2_STATIC;
    l2addr.encap_id = encap_id;
    BCM_GPORT_FORWARD_PORT_SET(l2addr.port, fec_id);
    BCM_IF_ERROR_RETURN_MSG(bcm_l2_addr_add(unit, l2addr), "");

    return BCM_E_NONE;
}

/*
 * Create PWE encapsulation with the mpls tunnel in the link list.
 */
int
vpls_pwe_tagged_mode_basic_mpls_port_add_encapsulation_with_tunnel(
    int unit,
    bcm_gport_t * mpls_port_id,
    bcm_mpls_label_t pwe_label,
    bcm_if_t * encap_id,
    int is_virtual,
    bcm_if_t tunnel_if)
{
    bcm_mpls_port_t mpls_port;
    bcm_gport_t gport_id;

    bcm_mpls_port_t_init(&mpls_port);
    mpls_port.flags |= BCM_MPLS_PORT_WITH_ID | BCM_MPLS_PORT_EGRESS_TUNNEL;
    mpls_port.flags2 |= BCM_MPLS_PORT2_EGRESS_ONLY;

    BCM_GPORT_SUB_TYPE_LIF_SET(gport_id, 0, *mpls_port_id);
    BCM_GPORT_MPLS_PORT_ID_SET(mpls_port.mpls_port_id, gport_id);
    mpls_port.egress_label.label = pwe_label;
    mpls_port.egress_label.flags = BCM_MPLS_EGRESS_LABEL_TTL_DECREMENT;
    mpls_port.egress_tunnel_if = tunnel_if;
    if (!is_virtual)
    {
        /* If the native AC is Gliful, the phase of the PWE entry should be higher than the former */
        mpls_port.egress_label.encap_access = bcmEncapAccessTunnel2;
    }

    BCM_IF_ERROR_RETURN_MSG(bcm_mpls_port_add(unit, 0, mpls_port), "encapsulation");

    *mpls_port_id = mpls_port.mpls_port_id;
    *encap_id = mpls_port.encap_id;

    printf("pwe encapsulation id: 0x%08X with tuunel if: 0x%08X\n", *mpls_port_id, tunnel_if);

    return BCM_E_NONE;
}


int
vpls_pwe_tagged_mode_basic_mpls_port_add_encapsulation(
    int unit,
    bcm_gport_t * mpls_port_id,
    bcm_mpls_label_t pwe_label,
    bcm_if_t * encap_id,
    int is_virtual)
{

    BCM_IF_ERROR_RETURN_MSG(vpls_pwe_tagged_mode_basic_mpls_port_add_encapsulation_with_tunnel(unit,
                mpls_port_id, pwe_label, encap_id, is_virtual, 0), "");

    return BCM_E_NONE;
}

int
vpls_pwe_tagged_mode_basic_mpls_port_add_termination(
    int unit,
    bcm_gport_t * mpls_port_id,
    bcm_mpls_label_t pwe_label,
    bcm_if_t * encap_id,
    int fec_id,
    bcm_vpn_t vpn)
{
    char error_msg[200]={0,};
    bcm_mpls_port_t mpls_port;
    bcm_gport_t gport_id;

    bcm_mpls_port_t_init(&mpls_port);
    mpls_port.flags |= BCM_MPLS_PORT_WITH_ID | BCM_MPLS_PORT_SERVICE_TAGGED | BCM_MPLS_PORT_EGRESS_TUNNEL;
    mpls_port.flags2 |= BCM_MPLS_PORT2_INGRESS_ONLY | (vpn ? 0 : BCM_MPLS_PORT2_CROSS_CONNECT);
    mpls_port.nof_service_tags = 2;

    BCM_GPORT_SUB_TYPE_LIF_SET(gport_id, 0, *mpls_port_id);
    BCM_GPORT_MPLS_PORT_ID_SET(mpls_port.mpls_port_id, gport_id);
    /*
     * encap_id is the egress outlif - used for learning 
     */
    mpls_port.encap_id = *encap_id;
    mpls_port.criteria = BCM_MPLS_PORT_MATCH_LABEL;
    mpls_port.match_label = pwe_label;
    /** connect PWE entry to created MPLS encapsulation entry for learning */
    BCM_L3_ITF_SET(mpls_port.egress_tunnel_if, BCM_L3_ITF_TYPE_FEC, fec_id);

    BCM_IF_ERROR_RETURN_MSG(bcm_mpls_port_add(unit, vpn, mpls_port), "");

    *mpls_port_id = mpls_port.mpls_port_id;

    printf("ingress mpls_port_id: 0x%08x\n", *mpls_port_id);

    pwe_network_domain = (*dnxc_data_get(unit, "port", "general", "ingress_vlan_domain_size", NULL) > 9) ? 0x7e3 : 507;
    snprintf(error_msg, sizeof(error_msg), "port=%d", mpls_port.mpls_port_id);
    BCM_IF_ERROR_RETURN_MSG(bcm_port_class_set(unit, mpls_port.mpls_port_id, bcmPortClassIngress, pwe_network_domain), error_msg);
    return BCM_E_NONE;
}

int
vpls_pwe_tagged_mode_basic_vswitch_add_core_outer_ac(
    int unit,
    bcm_gport_t port,
    int vsi,
    bcm_gport_t * vlan_port_id)
{
    bcm_vlan_port_t vlan_port;
    int is_two_dev = 0;
    /*
     * add port, according to port_vlan_vlan 
     */
    bcm_vlan_port_t_init(&vlan_port);

    /*
     * set port attribures, key <port-vlan-vlan>
     */
    vlan_port.port = port;
    vlan_port.flags = BCM_VLAN_PORT_CREATE_EGRESS_ONLY | BCM_VLAN_PORT_VLAN_TRANSLATION;
    vlan_port.criteria = BCM_VLAN_PORT_MATCH_PORT_VLAN;
    vlan_port.vsi = vsi;

    BCM_IF_ERROR_RETURN_MSG(bcm_vlan_port_create(unit, &vlan_port), "");
    *vlan_port_id = vlan_port.vlan_port_id;

    printf("outer_ac_vlan_port_id: 0x%08x\n", *vlan_port_id);

    /*
     * BCM_IF_ERROR_RETURN_MSG(bcm_vswitch_port_add(unit, cint_vpls_pwe_tagged_mode_basic_info.core_eth_rif, vlan_port.vlan_port_id), "");
     */

    return BCM_E_NONE;
}

/*
 * Define a VLAN port to forward the native eth DA to. 
 * The resulting vlan_port_id is saved in cint_vpls_pwe_tagged_mode_basic_info.access_egress_vlan_port_id. 
 * Connect the Native DA to the egress vlan port.
 */
int
vpls_pwe_tagged_mode_add_network_egress_outer_ac(
    int unit,
    bcm_vpn_t vsi,
    bcm_mac_t mac,
    bcm_gport_t * egress_vlan_port_id,
    bcm_port_t port,
    int is_cross_connect)
{
    bcm_vlan_port_t vlan_port;
    bcm_l2_addr_t l2addr;

    /*
     * Add VLAN port in egress
     */
    bcm_vlan_port_t_init(&vlan_port);
    vlan_port.flags |= BCM_VLAN_PORT_WITH_ID;
    vlan_port.vsi = 0;
    vlan_port.criteria = BCM_VLAN_PORT_MATCH_NONE;
    vlan_port.port = port;
    BCM_GPORT_SUB_TYPE_LIF_SET(vlan_port.vlan_port_id, 0, *egress_vlan_port_id);
    BCM_GPORT_VLAN_PORT_ID_SET(vlan_port.vlan_port_id, vlan_port.vlan_port_id);
    BCM_IF_ERROR_RETURN_MSG(bcm_vlan_port_create(unit, &vlan_port), "");
    *egress_vlan_port_id = vlan_port.vlan_port_id;
    printf("egress_vlan_port_id: 0x%08x\n", *egress_vlan_port_id);

    BCM_IF_ERROR_RETURN_MSG(bcm_vswitch_port_add(unit, vsi, vlan_port.vlan_port_id), "");

    /*
     * Connect the native DA to the egress vlan port
     * In case of not P2P case
     */
    if(!is_cross_connect)
    {
        bcm_l2_addr_t_init(&l2addr, mac, vsi);
        l2addr.flags |= BCM_L2_STATIC;
        l2addr.port = *egress_vlan_port_id;
        BCM_IF_ERROR_RETURN_MSG(bcm_l2_addr_add(unit, l2addr), "");
    }
    return BCM_E_NONE;
}


/*
 * For Ingress:
 * Define AC for inner ETH validation on packets going from core to customer.
 * The resulting vlan_port_id is saved in cint_vpls_pwe_tagged_mode_basic_info.ingress_native_ac_vlan_port_id.
 * For Egress:
 * Define a VLAN port to forward the native eth DA to. 
 * The resulting vlan_port_id is saved in cint_vpls_pwe_tagged_mode_basic_info.access_egress_vlan_port_id. 
 * Connect the Native DA to the egress vlan port.
 */
int
vpls_pwe_tagged_mode_add_network_native_ac(
    int unit,
    bcm_vpn_t vsi,
    bcm_mac_t mac,
    bcm_gport_t * ingress_vlan_port_id,
    bcm_gport_t * egress_vlan_port_id,
    bcm_gport_t mpls_port_id,
    bcm_vlan_t outer_vlan,
    bcm_vlan_t inner_vlan,
    bcm_port_t port,
    int is_virtual,
    int ingress_ac_native_wide_data_enable,
    int is_cross_connect,
    int is_set_global_lif)
{
    bcm_vlan_port_t vlan_port;
    bcm_l2_addr_t l2addr;
    /*
     * add port.
     */
    bcm_vlan_port_t_init(&vlan_port);
    if (is_set_global_lif) {
        vlan_port.flags = BCM_VLAN_PORT_NATIVE;
    } else {
        vlan_port.flags = BCM_VLAN_PORT_NATIVE | BCM_VLAN_PORT_CREATE_INGRESS_ONLY;
    }

    if (is_virtual)
    {
        vlan_port.flags |= BCM_VLAN_PORT_VLAN_TRANSLATION;
    }
    else
    {
        vlan_port.flags |= BCM_VLAN_PORT_WITH_ID;
        if (is_set_global_lif) {
            BCM_GPORT_SUB_TYPE_LIF_SET(vlan_port.vlan_port_id,
                0, *ingress_vlan_port_id);
        } else {
            BCM_GPORT_SUB_TYPE_LIF_SET(vlan_port.vlan_port_id,
                BCM_GPORT_SUB_TYPE_LIF_EXC_INGRESS_ONLY, *ingress_vlan_port_id);
        }
        BCM_GPORT_VLAN_PORT_ID_SET(vlan_port.vlan_port_id, vlan_port.vlan_port_id);
    }
    if (ingress_ac_native_wide_data_enable)
    {
        vlan_port.flags |= BCM_VLAN_PORT_INGRESS_WIDE;    
    }
    vlan_port.vsi = is_set_global_lif ? 0 : vsi;
    vlan_port.criteria = BCM_VLAN_PORT_MATCH_NONE;
    BCM_IF_ERROR_RETURN_MSG(bcm_vlan_port_create(unit, &vlan_port), "");
    /*
     * Save the created vlan_port_id
     */
    *ingress_vlan_port_id = vlan_port.vlan_port_id;
    if (is_set_global_lif) {
        BCM_IF_ERROR_RETURN_MSG(bcm_vswitch_port_add(unit, vsi, vlan_port.vlan_port_id), "");
    }
    
    printf("native ac = 0x%08x\n", vlan_port.vlan_port_id);

    /*
     * Add Match
     */
    bcm_port_match_info_t match_info;
    bcm_port_match_info_t_init(&match_info);
    match_info.flags = BCM_PORT_MATCH_INGRESS_ONLY | BCM_PORT_MATCH_NATIVE;
    match_info.port = mpls_port_id;
    match_info.match = BCM_PORT_MATCH_PORT_VLAN_STACKED;        /* Match 2 tags */
    match_info.match_vlan = outer_vlan;
    match_info.match_inner_vlan = inner_vlan;
    BCM_IF_ERROR_RETURN_MSG(bcm_port_match_add(unit, vlan_port.vlan_port_id, &match_info), "");

    /*
     * Add VLAN port in egress
     */
    BCM_IF_ERROR_RETURN_MSG(vpls_pwe_tagged_mode_add_network_egress_outer_ac(unit, vsi, mac,
                                                          egress_vlan_port_id,
                                                          port,
                                                          is_cross_connect), "");

    return BCM_E_NONE;
}

/*
 * Creating p2p connection from the native AC to the out AC
 * The connection is used for core->access packets.
 */
int
vpls_pwe_tagged_mode_add_cross_connect_native_ac(
    int unit,
    bcm_gport_t ingress_vlan_port_id,
    bcm_gport_t egress_vlan_port_id)
{
    bcm_vswitch_cross_connect_t gports;

    bcm_vswitch_cross_connect_t_init(&gports);
    gports.port1 = ingress_vlan_port_id;
    gports.port2 = egress_vlan_port_id;
    gports.encap1 = BCM_FORWARD_ENCAP_ID_INVALID;
    gports.encap2 = BCM_FORWARD_ENCAP_ID_INVALID;
    gports.flags = BCM_VSWITCH_CROSS_CONNECT_DIRECTIONAL;
    BCM_IF_ERROR_RETURN_MSG(bcm_vswitch_cross_connect_add(unit, gports), "");
    return BCM_E_NONE;
}

/*
 * Creating p2p connection from the access AC to the Native AC encapsulated in pwe packets
 * The access AC contain the FEC and the MPLS tunnel.
 * FEC is pointing to the out Native AC
 * The connection is used for access->core packets.
 */
int
vpls_pwe_tagged_mode_add_cross_connect_access_ac(
    int unit,
    bcm_gport_t ac_inlif,
    bcm_if_t encap_id,
    int mpls_fec_id)
{
    bcm_vswitch_cross_connect_t gports;

    bcm_vswitch_cross_connect_t_init(&gports);
    gports.port1 = ac_inlif;
    BCM_GPORT_FORWARD_PORT_SET(gports.port2, mpls_fec_id);
    gports.encap2 = encap_id;
    gports.encap1 = BCM_FORWARD_ENCAP_ID_INVALID;
    gports.flags = BCM_VSWITCH_CROSS_CONNECT_DIRECTIONAL;
    BCM_IF_ERROR_RETURN_MSG(bcm_vswitch_cross_connect_add(unit, gports), "");
    return BCM_E_NONE;
}

/*
 * Define AC for inner ETH validation on packets going from customer to core.
 * This creates a SW DB entry that is later used by VLAN translation APIs for setting inner ETH editting.
 * The resulting vlan_port_id is saved in vlan_port_id.
 */
int
vpls_pwe_tagged_mode_add_core_native_ac(
    int unit,
    bcm_vpn_t vsi,
    bcm_gport_t mpls_port_id,
    bcm_gport_t * vlan_port_id,
    int is_virtual,
    int *encap_id)
{
    bcm_vlan_port_t vlan_port;
    /*
     * add port.
     */
    bcm_vlan_port_t_init(&vlan_port);
    vlan_port.flags = BCM_VLAN_PORT_NATIVE | BCM_VLAN_PORT_CREATE_EGRESS_ONLY | BCM_VLAN_PORT_STAT_EGRESS_ENABLE;
    if (is_virtual)
    {
        vlan_port.flags |= BCM_VLAN_PORT_VLAN_TRANSLATION;
    }
    vlan_port.vsi = vsi;
    if (!is_virtual)
    {
        vlan_port.tunnel_id = mpls_port_id;
        vlan_port.flags |= BCM_VLAN_PORT_WITH_ID;
        BCM_GPORT_SUB_TYPE_LIF_SET(vlan_port.vlan_port_id,
            BCM_GPORT_SUB_TYPE_LIF_EXC_EGRESS_ONLY, *vlan_port_id);
        BCM_GPORT_VLAN_PORT_ID_SET(vlan_port.vlan_port_id, vlan_port.vlan_port_id);
        
        vlan_port.criteria = BCM_VLAN_PORT_MATCH_NONE;
    }
    else
    {
        vlan_port.port = mpls_port_id;
        vlan_port.criteria = BCM_VLAN_PORT_MATCH_PORT_VLAN;
    }
    
    BCM_IF_ERROR_RETURN_MSG(bcm_vlan_port_create(unit, &vlan_port), "");
    /*
     * Save the created vlan_port_id
     */
    *vlan_port_id = vlan_port.vlan_port_id;
    *encap_id = vlan_port.encap_id;

    printf("core native ac = 0x%x\n", *vlan_port_id);

    return BCM_E_NONE;
}

/*
 * Main function for basic mpls vpls scenario.
 */
int
vpls_pwe_tagged_mode_basic_main(
    int unit,
    int access_port,
    int core_port)
{
    char error_msg[200]={0,};
    int nof_labels = 2;
    int dummy_encap_id;

    BCM_IF_ERROR_RETURN_MSG(get_first_fec_in_range_which_not_in_ecmp_range(unit, 0, 0, &cint_vpls_pwe_tagged_mode_basic_info.mpls_fec_id), "");

    vpls_pwe_tagged_mode_basic_init(access_port, core_port);

    /*
     * Configure AC and PWE ports
     */
    BCM_IF_ERROR_RETURN_MSG(vpls_pwe_tagged_mode_basic_configure_port_properties(unit, cint_vpls_pwe_tagged_mode_basic_info.access_port,
                                                              cint_vpls_pwe_tagged_mode_basic_info.core_port,
                                                              cint_vpls_pwe_tagged_mode_basic_info.service_vsi,
                                                              cint_vpls_pwe_tagged_mode_basic_info.core_eth_rif, FALSE), "");

    BCM_IF_ERROR_RETURN_MSG(vpls_pwe_tagged_mode_basic_create_vsis(unit, cint_vpls_pwe_tagged_mode_basic_info.service_vsi,
                                                cint_vpls_pwe_tagged_mode_basic_info.core_eth_rif), "");

    /*
     * Configure L3 interfaces 
     */
    BCM_IF_ERROR_RETURN_MSG(vpls_pwe_tagged_mode_basic_create_l3_interfaces(unit, cint_vpls_pwe_tagged_mode_basic_info.core_eth_rif,
                                                         cint_vpls_pwe_tagged_mode_basic_info.core_eth_rif_mac), "");

    /*
     * Configure an ARP entries
     */
    BCM_IF_ERROR_RETURN_MSG(vpls_pwe_tagged_mode_basic_create_arp_entry(unit, &(cint_vpls_pwe_tagged_mode_basic_info.core_arp_id),
                                                     cint_vpls_pwe_tagged_mode_basic_info.core_next_hop_mac,
                                                     cint_vpls_pwe_tagged_mode_basic_info.core_eth_rif), "");

    /*
     * Configure a push entry.
     */
    BCM_IF_ERROR_RETURN_MSG(vpls_pwe_tagged_mode_basic_create_mpls_tunnel(unit,
                                                       cint_vpls_pwe_tagged_mode_basic_info.service_mpls_tunnel_label_1,
                                                       cint_vpls_pwe_tagged_mode_basic_info.service_mpls_tunnel_label_2,
                                                       2, cint_vpls_pwe_tagged_mode_basic_info.core_arp_id,
                                                       &cint_vpls_pwe_tagged_mode_basic_info.mpls_tunnel_id,
                                                       1), "");

    /*
     * Configure fec entry 
     */
    BCM_IF_ERROR_RETURN_MSG(vpls_pwe_tagged_mode_basic_create_fec_entry(unit, cint_vpls_pwe_tagged_mode_basic_info.mpls_fec_id,
                                                     cint_vpls_pwe_tagged_mode_basic_info.mpls_tunnel_id,
                                                     cint_vpls_pwe_tagged_mode_basic_info.core_port), "");

    /*
     * Configure a termination label for the ingress flow  
     */
    bcm_mpls_label_t label_array[2];
    label_array[0] = cint_vpls_pwe_tagged_mode_basic_info.service_mpls_tunnel_label_1;
    label_array[1] = cint_vpls_pwe_tagged_mode_basic_info.service_mpls_tunnel_label_2;
    BCM_IF_ERROR_RETURN_MSG(vpls_pwe_tagged_mode_basic_create_termination_stack(unit, label_array, 2), "");

    /*
     * configure PWE tunnel - egress flow 
     */
    BCM_IF_ERROR_RETURN_MSG(vpls_pwe_tagged_mode_basic_mpls_port_add_encapsulation(unit,
                                                                &(cint_vpls_pwe_tagged_mode_basic_info.mpls_port_id_eg),
                                                                cint_vpls_pwe_tagged_mode_basic_info.service_pwe_label,
                                                                &(cint_vpls_pwe_tagged_mode_basic_info.pwe_encap_id),
                                                                1), "");

    /*
     * configure PWE tunnel - ingress flow 
     */
    BCM_IF_ERROR_RETURN_MSG(vpls_pwe_tagged_mode_basic_mpls_port_add_termination(unit,
                                                              &(cint_vpls_pwe_tagged_mode_basic_info.mpls_port_id_ing),
                                                              cint_vpls_pwe_tagged_mode_basic_info.service_pwe_label,
                                                              &(cint_vpls_pwe_tagged_mode_basic_info.pwe_encap_id),
                                                              cint_vpls_pwe_tagged_mode_basic_info.mpls_fec_id,
                                                              cint_vpls_pwe_tagged_mode_basic_info.service_vsi), "");

    /** define ac and pwe ports */
    BCM_IF_ERROR_RETURN_MSG(vpls_pwe_tagged_mode_basic_vswitch_add_core_outer_ac(unit, cint_vpls_pwe_tagged_mode_basic_info.core_port,
                                                              cint_vpls_pwe_tagged_mode_basic_info.core_eth_rif,
                                                              &
                                                              (cint_vpls_pwe_tagged_mode_basic_info.outer_ac_vlan_port_id)), "");

    /*
     * add l2 addresses to be defined as static - no learning needed
     */
    BCM_IF_ERROR_RETURN_MSG(vpls_pwe_tagged_mode_basic_l2_addr_add(unit, cint_vpls_pwe_tagged_mode_basic_info.service_vsi,
                                                cint_vpls_pwe_tagged_mode_basic_info.service_mac_2,
                                                cint_vpls_pwe_tagged_mode_basic_info.pwe_encap_id,
                                                cint_vpls_pwe_tagged_mode_basic_info.mpls_fec_id), "");

    /*
     * Set tag formats for un tagged and double tagged packets
     */
    BCM_IF_ERROR_RETURN_MSG(vpls_pwe_tagged_mode_basic_tag_formats_set(unit), "");

    /*
     * Configure EVE for access to core traffic: add two service tags 
     */
    snprintf(error_msg, sizeof(error_msg), "port=0x%08x", cint_vpls_pwe_tagged_mode_basic_info.outer_ac_vlan_port_id);
    BCM_IF_ERROR_RETURN_MSG(vlan_translate_ive_eve_translation_set(unit, cint_vpls_pwe_tagged_mode_basic_info.outer_ac_vlan_port_id,
                                                cint_vpls_pwe_tagged_mode_basic_info.outer_tpid,
                                                cint_vpls_pwe_tagged_mode_basic_info.inner_tpid, bcmVlanActionAdd,
                                                bcmVlanActionAdd,
                                                cint_vpls_pwe_tagged_mode_basic_info.outer_ac_egress_outer_vlan,
                                                cint_vpls_pwe_tagged_mode_basic_info.outer_ac_egress_inner_vlan,
                                                cint_vpls_pwe_tagged_mode_basic_info.egress_vlan_edit_profile,
                                                cint_vpls_pwe_tagged_mode_basic_info.tag_format_untagged, 0), error_msg);

    /*
     * Add AC for inner ETH IVE (removing/replacing service tags)
     * For Ingress flow
     */
    printf("Inner AC glifless configuration\n\n");
    BCM_IF_ERROR_RETURN_MSG(vpls_pwe_tagged_mode_add_network_native_ac(unit, cint_vpls_pwe_tagged_mode_basic_info.service_vsi,
                                                    cint_vpls_pwe_tagged_mode_basic_info.service_mac_1,
                                                    &
                                                    (cint_vpls_pwe_tagged_mode_basic_info.ingress_native_ac_vlan_port_id),
                                                    &
                                                    (cint_vpls_pwe_tagged_mode_basic_info.access_egress_vlan_port_id),
                                                    cint_vpls_pwe_tagged_mode_basic_info.mpls_port_id_ing,
                                                    cint_vpls_pwe_tagged_mode_basic_info.ingress_canonical_outer_vlan,
                                                    cint_vpls_pwe_tagged_mode_basic_info.ingress_canonical_inner_vlan,
                                                    cint_vpls_pwe_tagged_mode_basic_info.access_port, 1, FALSE, FALSE, FALSE), "");

    /*
     * Configure IVE for core to access traffic: delete two service tags 
     */
    snprintf(error_msg, sizeof(error_msg), "port=0x%08x", cint_vpls_pwe_tagged_mode_basic_info.ingress_native_ac_vlan_port_id);
    BCM_IF_ERROR_RETURN_MSG(vlan_translate_ive_eve_translation_set(unit,
                                                cint_vpls_pwe_tagged_mode_basic_info.ingress_native_ac_vlan_port_id,
                                                0,
                                                0,
                                                bcmVlanActionDelete,
                                                bcmVlanActionDelete,
                                                0,
                                                0,
                                                cint_vpls_pwe_tagged_mode_basic_info.ingress_vlan_edit_profile,
                                                cint_vpls_pwe_tagged_mode_basic_info.tag_format_double_tagged, 1), error_msg);

    /*
     * Add AC for inner ETH EVE (adding service tags)
     * For Egress flow
     */
    BCM_IF_ERROR_RETURN_MSG(vpls_pwe_tagged_mode_add_core_native_ac(unit, cint_vpls_pwe_tagged_mode_basic_info.service_vsi,
                                                 cint_vpls_pwe_tagged_mode_basic_info.mpls_port_id_eg,
                                                 &(cint_vpls_pwe_tagged_mode_basic_info.egress_native_ac_vlan_port_id),
                                                 1, &dummy_encap_id), "");
    /*
     * Add EVE for the AC created in the previous step
     */
    snprintf(error_msg, sizeof(error_msg), "port=0x%08x", cint_vpls_pwe_tagged_mode_basic_info.egress_native_ac_vlan_port_id);
    BCM_IF_ERROR_RETURN_MSG(vlan_translate_ive_eve_translation_set(unit,
                                                cint_vpls_pwe_tagged_mode_basic_info.egress_native_ac_vlan_port_id,
                                                cint_vpls_pwe_tagged_mode_basic_info.outer_tpid,
                                                cint_vpls_pwe_tagged_mode_basic_info.inner_tpid,
                                                bcmVlanActionAdd,
                                                bcmVlanActionAdd,
                                                cint_vpls_pwe_tagged_mode_basic_info.egress_canonical_outer_vlan,
                                                cint_vpls_pwe_tagged_mode_basic_info.egress_canonical_inner_vlan,
                                                cint_vpls_pwe_tagged_mode_basic_info.egress_vlan_edit_profile,
                                                cint_vpls_pwe_tagged_mode_basic_info.tag_format_untagged, 0), error_msg);

    return BCM_E_NONE;
}

/*
 * Main function indexed native ac scenario.
 */
int
vpls_pwe_tagged_mode_basic_indexed_native_ac_main(
    int unit,
    int access_port,
    int core_port,
    int ingress_ac_native_wide_data_enable)
{
    char error_msg[200]={0,};
    int nof_labels = 2;
    int is_set_global_lif = is_oam ? TRUE: FALSE;

    cint_vpls_pwe_tagged_mode_basic_info.ingress_native_ac_vlan_port_id = *dnxc_data_get(unit, "l3", "rif", "nof_rifs", NULL) + 0x234;

    BCM_IF_ERROR_RETURN_MSG(get_first_fec_in_range_which_not_in_ecmp_range(unit, 0, 0, &cint_vpls_pwe_tagged_mode_basic_info.mpls_fec_id), "");

    vpls_pwe_tagged_mode_basic_init(access_port, core_port);

    /*
     * Configure AC and PWE ports
     */
    BCM_IF_ERROR_RETURN_MSG(vpls_pwe_tagged_mode_basic_configure_port_properties(unit, cint_vpls_pwe_tagged_mode_basic_info.access_port,
                                                              cint_vpls_pwe_tagged_mode_basic_info.core_port,
                                                              cint_vpls_pwe_tagged_mode_basic_info.service_vsi,
                                                              cint_vpls_pwe_tagged_mode_basic_info.core_eth_rif, FALSE), "");

    BCM_IF_ERROR_RETURN_MSG(vpls_pwe_tagged_mode_basic_create_vsis(unit, cint_vpls_pwe_tagged_mode_basic_info.service_vsi,
                                                cint_vpls_pwe_tagged_mode_basic_info.core_eth_rif), "");

    /*
     * Configure L3 interfaces 
     */
    BCM_IF_ERROR_RETURN_MSG(vpls_pwe_tagged_mode_basic_create_l3_interfaces(unit, cint_vpls_pwe_tagged_mode_basic_info.core_eth_rif,
                                                         cint_vpls_pwe_tagged_mode_basic_info.core_eth_rif_mac), "");

    /*
     * Configure an ARP entries
     */
    BCM_IF_ERROR_RETURN_MSG(vpls_pwe_tagged_mode_basic_create_arp_entry(unit, &(cint_vpls_pwe_tagged_mode_basic_info.core_arp_id),
                                                     cint_vpls_pwe_tagged_mode_basic_info.core_next_hop_mac,
                                                     cint_vpls_pwe_tagged_mode_basic_info.core_eth_rif), "");

    /*
     * Configure a push entry.
     */
    BCM_IF_ERROR_RETURN_MSG(vpls_pwe_tagged_mode_basic_create_mpls_tunnel(unit,
                                                       cint_vpls_pwe_tagged_mode_basic_info.service_mpls_tunnel_label_1,
                                                       cint_vpls_pwe_tagged_mode_basic_info.service_mpls_tunnel_label_2,
                                                       2, cint_vpls_pwe_tagged_mode_basic_info.core_arp_id,
                                                       &cint_vpls_pwe_tagged_mode_basic_info.mpls_tunnel_id,
                                                       0), "");

    /*
     * Configure fec entry 
     */
    BCM_IF_ERROR_RETURN_MSG(vpls_pwe_tagged_mode_basic_create_fec_entry(unit, cint_vpls_pwe_tagged_mode_basic_info.mpls_fec_id,
                                                     cint_vpls_pwe_tagged_mode_basic_info.mpls_tunnel_id,
                                                     cint_vpls_pwe_tagged_mode_basic_info.core_port), "");

    /*
     * Configure a termination label for the ingress flow  
     */
    bcm_mpls_label_t label_array[2];
    label_array[0] = cint_vpls_pwe_tagged_mode_basic_info.service_mpls_tunnel_label_1;
    label_array[1] = cint_vpls_pwe_tagged_mode_basic_info.service_mpls_tunnel_label_2;
    BCM_IF_ERROR_RETURN_MSG(vpls_pwe_tagged_mode_basic_create_termination_stack(unit, label_array, 2), "");

    /*
     * configure PWE tunnel - egress flow 
     */
    BCM_IF_ERROR_RETURN_MSG(vpls_pwe_tagged_mode_basic_mpls_port_add_encapsulation(unit,
                                                                &(cint_vpls_pwe_tagged_mode_basic_info.mpls_port_id_eg),
                                                                cint_vpls_pwe_tagged_mode_basic_info.service_pwe_label,
                                                                &(cint_vpls_pwe_tagged_mode_basic_info.pwe_encap_id),
                                                                0), "");

    /*
     * configure PWE tunnel - ingress flow 
     */
    BCM_IF_ERROR_RETURN_MSG(vpls_pwe_tagged_mode_basic_mpls_port_add_termination(unit,
                                                              &(cint_vpls_pwe_tagged_mode_basic_info.mpls_port_id_ing),
                                                              cint_vpls_pwe_tagged_mode_basic_info.service_pwe_label,
                                                              &(cint_vpls_pwe_tagged_mode_basic_info.pwe_encap_id),
                                                              cint_vpls_pwe_tagged_mode_basic_info.mpls_fec_id,
                                                              cint_vpls_pwe_tagged_mode_basic_info.service_vsi), "");

    /** define ac and pwe ports */
    BCM_IF_ERROR_RETURN_MSG(vpls_pwe_tagged_mode_basic_vswitch_add_core_outer_ac(unit, cint_vpls_pwe_tagged_mode_basic_info.core_port,
                                                              cint_vpls_pwe_tagged_mode_basic_info.core_eth_rif,
                                                              &(cint_vpls_pwe_tagged_mode_basic_info.outer_ac_vlan_port_id)), "");

    /*
     * Set tag formats for un tagged and double tagged packets
     */
    BCM_IF_ERROR_RETURN_MSG(vpls_pwe_tagged_mode_basic_tag_formats_set(unit), "");

    /*
     * Configure EVE for access to core traffic: add two service tags 
     */
    snprintf(error_msg, sizeof(error_msg), "port=0x%08x", cint_vpls_pwe_tagged_mode_basic_info.outer_ac_vlan_port_id);
    BCM_IF_ERROR_RETURN_MSG(vlan_translate_ive_eve_translation_set(unit, cint_vpls_pwe_tagged_mode_basic_info.outer_ac_vlan_port_id,
                                                cint_vpls_pwe_tagged_mode_basic_info.outer_tpid,
                                                cint_vpls_pwe_tagged_mode_basic_info.inner_tpid, bcmVlanActionAdd,
                                                bcmVlanActionAdd,
                                                cint_vpls_pwe_tagged_mode_basic_info.outer_ac_egress_outer_vlan,
                                                cint_vpls_pwe_tagged_mode_basic_info.outer_ac_egress_inner_vlan,
                                                cint_vpls_pwe_tagged_mode_basic_info.egress_vlan_edit_profile,
                                                cint_vpls_pwe_tagged_mode_basic_info.tag_format_untagged, 0), error_msg);

    /*
     * Add AC for inner ETH IVE (removing/replacing service tags)
     * For Ingress flow. Also add the outer AC that is the result of 
     * Ethernet forwarding with the exposed DA. 
     */
    BCM_IF_ERROR_RETURN_MSG(vpls_pwe_tagged_mode_add_network_native_ac(unit, cint_vpls_pwe_tagged_mode_basic_info.service_vsi,
                                                    cint_vpls_pwe_tagged_mode_basic_info.service_mac_1,
                                                    &
                                                    (cint_vpls_pwe_tagged_mode_basic_info.ingress_native_ac_vlan_port_id),
                                                    &
                                                    (cint_vpls_pwe_tagged_mode_basic_info.access_egress_vlan_port_id),
                                                    cint_vpls_pwe_tagged_mode_basic_info.mpls_port_id_ing,
                                                    cint_vpls_pwe_tagged_mode_basic_info.ingress_canonical_outer_vlan,
                                                    cint_vpls_pwe_tagged_mode_basic_info.ingress_canonical_inner_vlan,
                                                    cint_vpls_pwe_tagged_mode_basic_info.access_port, 0, 
                                                    ingress_ac_native_wide_data_enable, FALSE, is_set_global_lif), "");
    /*
     * Add IVE for the AC created in the previous step
     */
    snprintf(error_msg, sizeof(error_msg), "port=0x%08x", cint_vpls_pwe_tagged_mode_basic_info.ingress_native_ac_vlan_port_id);
    BCM_IF_ERROR_RETURN_MSG(vlan_translate_ive_eve_translation_set(unit,
                                                cint_vpls_pwe_tagged_mode_basic_info.ingress_native_ac_vlan_port_id,
                                                0,
                                                0,
                                                bcmVlanActionDelete,
                                                bcmVlanActionDelete,
                                                0,
                                                0,
                                                cint_vpls_pwe_tagged_mode_basic_info.ingress_vlan_edit_profile,
                                                cint_vpls_pwe_tagged_mode_basic_info.tag_format_double_tagged, 1), error_msg);
    /*
     * Add AC for inner ETH EVE (adding service tags)
     * For Egress flow
     */
    BCM_IF_ERROR_RETURN_MSG(vpls_pwe_tagged_mode_add_core_native_ac(unit, 0,
                                                 cint_vpls_pwe_tagged_mode_basic_info.mpls_port_id_eg,
                                                 &(cint_vpls_pwe_tagged_mode_basic_info.egress_native_ac_vlan_port_id),
                                                 0, &(cint_vpls_pwe_tagged_mode_basic_info.indexed_ac_encap_id)), "");
    /*
     * Add EVE for the AC created in the previous step
     */
    snprintf(error_msg, sizeof(error_msg), "port=0x%08x", cint_vpls_pwe_tagged_mode_basic_info.egress_native_ac_vlan_port_id);
    BCM_IF_ERROR_RETURN_MSG(vlan_translate_ive_eve_translation_set(unit,
                                                cint_vpls_pwe_tagged_mode_basic_info.egress_native_ac_vlan_port_id,
                                                cint_vpls_pwe_tagged_mode_basic_info.outer_tpid,
                                                cint_vpls_pwe_tagged_mode_basic_info.inner_tpid,
                                                bcmVlanActionAdd, bcmVlanActionAdd,
                                                cint_vpls_pwe_tagged_mode_basic_info.egress_canonical_outer_vlan,
                                                cint_vpls_pwe_tagged_mode_basic_info.egress_canonical_inner_vlan,
                                                cint_vpls_pwe_tagged_mode_basic_info.egress_vlan_edit_profile,
                                                cint_vpls_pwe_tagged_mode_basic_info.tag_format_untagged, 0), error_msg);

    /*
     * add l2 addresses to be defined as static - no learning needed
     */
    BCM_IF_ERROR_RETURN_MSG(vpls_pwe_tagged_mode_basic_l2_addr_add(unit, cint_vpls_pwe_tagged_mode_basic_info.service_vsi,
                                                cint_vpls_pwe_tagged_mode_basic_info.service_mac_2,
                                                cint_vpls_pwe_tagged_mode_basic_info.indexed_ac_encap_id,
                                                cint_vpls_pwe_tagged_mode_basic_info.mpls_fec_id), "");

    return BCM_E_NONE;
}

/* Set tag formats for un tagged and double tagged packets*/
int
vpls_pwe_tagged_mode_basic_tag_formats_set(
    int unit)
{
    char error_msg[200]={0,};

    bcm_port_tpid_class_t port_tpid_class;
    /*
     * set tag format for untagged packets 
     */
    bcm_port_tpid_class_t_init(&port_tpid_class);
    port_tpid_class.port = cint_vpls_pwe_tagged_mode_basic_info.core_port;
    port_tpid_class.tpid1 = BCM_PORT_TPID_CLASS_TPID_INVALID;
    port_tpid_class.tpid2 = BCM_PORT_TPID_CLASS_TPID_INVALID;
    port_tpid_class.tag_format_class_id = cint_vpls_pwe_tagged_mode_basic_info.tag_format_untagged;
    port_tpid_class.flags = BCM_PORT_TPID_CLASS_EGRESS_ONLY;
    port_tpid_class.vlan_translation_action_id = 0;
    snprintf(error_msg, sizeof(error_msg), "port=%d", port_tpid_class.port);
    BCM_IF_ERROR_RETURN_MSG(bcm_port_tpid_class_set(unit, &port_tpid_class), error_msg);

    /*
     * set tag format for double tagged packets 
     */
    bcm_port_tpid_class_t_init(&port_tpid_class);
    port_tpid_class.port = cint_vpls_pwe_tagged_mode_basic_info.mpls_port_id_ing;
    port_tpid_class.tpid1 = cint_vpls_pwe_tagged_mode_basic_info.outer_tpid;
    port_tpid_class.tpid2 = cint_vpls_pwe_tagged_mode_basic_info.inner_tpid;
    port_tpid_class.tag_format_class_id = cint_vpls_pwe_tagged_mode_basic_info.tag_format_double_tagged;
    port_tpid_class.flags = BCM_PORT_TPID_CLASS_INGRESS_ONLY;
    port_tpid_class.vlan_translation_action_id = 0;
    snprintf(error_msg, sizeof(error_msg), "port=0x%08x", port_tpid_class.port);
    BCM_IF_ERROR_RETURN_MSG(bcm_port_tpid_class_set(unit, &port_tpid_class), error_msg);

    return BCM_E_NONE;
}


/*
 * Main function for basic mpls vpls scenario.
 */
int
vpls_pwe_tagged_mode_p2p_basic_main(
    int unit,
    int access_port,
    int core_port)
{
    char error_msg[200]={0,};
    int nof_labels = 2;
    int dummy_encap_id;

    BCM_IF_ERROR_RETURN_MSG(get_first_fec_in_range_which_not_in_ecmp_range(unit, 0, 0, &cint_vpls_pwe_tagged_mode_basic_info.mpls_fec_id), "");

    vpls_pwe_tagged_mode_basic_init(access_port, core_port);

    /*
     * Configure AC and PWE ports
     */
    BCM_IF_ERROR_RETURN_MSG(vpls_pwe_tagged_mode_basic_configure_port_properties(unit, cint_vpls_pwe_tagged_mode_basic_info.access_port,
                                                              cint_vpls_pwe_tagged_mode_basic_info.core_port,
                                                              cint_vpls_pwe_tagged_mode_basic_info.service_vsi,
                                                              cint_vpls_pwe_tagged_mode_basic_info.core_eth_rif, TRUE), "");

    BCM_IF_ERROR_RETURN_MSG(vpls_pwe_tagged_mode_basic_create_vsis(unit, cint_vpls_pwe_tagged_mode_basic_info.service_vsi,
                                                cint_vpls_pwe_tagged_mode_basic_info.core_eth_rif), "");

    /*
     * Configure L3 interfaces
     */
    BCM_IF_ERROR_RETURN_MSG(vpls_pwe_tagged_mode_basic_create_l3_interfaces(unit, cint_vpls_pwe_tagged_mode_basic_info.core_eth_rif,
                                                         cint_vpls_pwe_tagged_mode_basic_info.core_eth_rif_mac), "");

    /*
     * Configure an ARP entries
     */
    BCM_IF_ERROR_RETURN_MSG(vpls_pwe_tagged_mode_basic_create_arp_entry(unit, &(cint_vpls_pwe_tagged_mode_basic_info.core_arp_id),
                                                     cint_vpls_pwe_tagged_mode_basic_info.core_next_hop_mac,
                                                     cint_vpls_pwe_tagged_mode_basic_info.core_eth_rif), "");

    /*
     * Configure a push entry.
     */
    BCM_IF_ERROR_RETURN_MSG(vpls_pwe_tagged_mode_basic_create_mpls_tunnel(unit,
                                                       cint_vpls_pwe_tagged_mode_basic_info.service_mpls_tunnel_label_1,
                                                       cint_vpls_pwe_tagged_mode_basic_info.service_mpls_tunnel_label_2,
                                                       2, cint_vpls_pwe_tagged_mode_basic_info.core_arp_id,
                                                       &cint_vpls_pwe_tagged_mode_basic_info.mpls_tunnel_id,
                                                       1), "");

    /*
     * Configure fec entry
     */
    BCM_IF_ERROR_RETURN_MSG(vpls_pwe_tagged_mode_basic_create_fec_entry(unit, cint_vpls_pwe_tagged_mode_basic_info.mpls_fec_id,
                                                     cint_vpls_pwe_tagged_mode_basic_info.mpls_tunnel_id,
                                                     cint_vpls_pwe_tagged_mode_basic_info.core_port), "");

    /*
     * Configure a termination label for the ingress flow
     */
    bcm_mpls_label_t label_array[2];
    label_array[0] = cint_vpls_pwe_tagged_mode_basic_info.service_mpls_tunnel_label_1;
    label_array[1] = cint_vpls_pwe_tagged_mode_basic_info.service_mpls_tunnel_label_2;
    BCM_IF_ERROR_RETURN_MSG(vpls_pwe_tagged_mode_basic_create_termination_stack(unit, label_array, 2), "");

    /*
     * configure PWE tunnel - egress flow
     */
    BCM_IF_ERROR_RETURN_MSG(vpls_pwe_tagged_mode_basic_mpls_port_add_encapsulation(unit,
                                                                &(cint_vpls_pwe_tagged_mode_basic_info.mpls_port_id_eg),
                                                                cint_vpls_pwe_tagged_mode_basic_info.service_pwe_label,
                                                                &(cint_vpls_pwe_tagged_mode_basic_info.pwe_encap_id),
                                                                1), "");

    /*
     * configure PWE tunnel - ingress flow
     */
    BCM_IF_ERROR_RETURN_MSG(vpls_pwe_tagged_mode_basic_mpls_port_add_termination(unit,
                                                              &(cint_vpls_pwe_tagged_mode_basic_info.mpls_port_id_ing),
                                                              cint_vpls_pwe_tagged_mode_basic_info.service_pwe_label,
                                                              &(cint_vpls_pwe_tagged_mode_basic_info.pwe_encap_id),
                                                              cint_vpls_pwe_tagged_mode_basic_info.mpls_fec_id,
                                                              cint_vpls_pwe_tagged_mode_basic_info.service_vsi), "");

    /** define ac and pwe ports */
    BCM_IF_ERROR_RETURN_MSG(vpls_pwe_tagged_mode_basic_vswitch_add_core_outer_ac(unit, cint_vpls_pwe_tagged_mode_basic_info.core_port,
                                                              cint_vpls_pwe_tagged_mode_basic_info.core_eth_rif,
                                                              &(cint_vpls_pwe_tagged_mode_basic_info.outer_ac_vlan_port_id)), "");

    /*
     * cross connecting the access ac port id with the pwe and mpls tunnels
     */
    BCM_IF_ERROR_RETURN_MSG(vpls_pwe_tagged_mode_add_cross_connect_access_ac(unit,
                                                cint_vpls_pwe_tagged_mode_basic_info.access_port_ac_in_lif,
                                                cint_vpls_pwe_tagged_mode_basic_info.pwe_encap_id, cint_vpls_pwe_tagged_mode_basic_info.mpls_fec_id), "");

    /*
     * Set tag formats for un tagged and double tagged packets
     */
    BCM_IF_ERROR_RETURN_MSG(vpls_pwe_tagged_mode_basic_tag_formats_set(unit), "");

    /*
     * Configure EVE for access to core traffic: add two service tags
     */
    snprintf(error_msg, sizeof(error_msg), "port=0x%08x", cint_vpls_pwe_tagged_mode_basic_info.outer_ac_vlan_port_id);
    BCM_IF_ERROR_RETURN_MSG(vlan_translate_ive_eve_translation_set(unit, cint_vpls_pwe_tagged_mode_basic_info.outer_ac_vlan_port_id,
                                                cint_vpls_pwe_tagged_mode_basic_info.outer_tpid,
                                                cint_vpls_pwe_tagged_mode_basic_info.inner_tpid, bcmVlanActionAdd,
                                                bcmVlanActionAdd,
                                                cint_vpls_pwe_tagged_mode_basic_info.outer_ac_egress_outer_vlan,
                                                cint_vpls_pwe_tagged_mode_basic_info.outer_ac_egress_inner_vlan,
                                                cint_vpls_pwe_tagged_mode_basic_info.egress_vlan_edit_profile,
                                                cint_vpls_pwe_tagged_mode_basic_info.tag_format_untagged, 0), error_msg);

    /*
     * Add AC for inner ETH IVE (removing/replacing service tags)
     * For Ingress flow
     */
    printf("Inner AC glifless configuration\n\n");
    BCM_IF_ERROR_RETURN_MSG(vpls_pwe_tagged_mode_add_network_native_ac(unit, cint_vpls_pwe_tagged_mode_basic_info.service_vsi,
                                                    cint_vpls_pwe_tagged_mode_basic_info.service_mac_1,
                                                    &
                                                    (cint_vpls_pwe_tagged_mode_basic_info.ingress_native_ac_vlan_port_id),
                                                    &
                                                    (cint_vpls_pwe_tagged_mode_basic_info.access_egress_vlan_port_id),
                                                    cint_vpls_pwe_tagged_mode_basic_info.mpls_port_id_ing,
                                                    cint_vpls_pwe_tagged_mode_basic_info.ingress_canonical_outer_vlan,
                                                    cint_vpls_pwe_tagged_mode_basic_info.ingress_canonical_inner_vlan,
                                                    cint_vpls_pwe_tagged_mode_basic_info.access_port, 0, FALSE, TRUE, FALSE), "");

    /*
     * Add Cross connect in case of p2p
     */
    BCM_IF_ERROR_RETURN_MSG(vpls_pwe_tagged_mode_add_cross_connect_native_ac(unit,
                                                cint_vpls_pwe_tagged_mode_basic_info.ingress_native_ac_vlan_port_id,
                                                cint_vpls_pwe_tagged_mode_basic_info.access_egress_vlan_port_id), "");
    /*
     * Configure IVE for core to access traffic: delete two service tags
     */
    snprintf(error_msg, sizeof(error_msg), "port=0x%08x", cint_vpls_pwe_tagged_mode_basic_info.ingress_native_ac_vlan_port_id);
    BCM_IF_ERROR_RETURN_MSG(vlan_translate_ive_eve_translation_set(unit,
                                                cint_vpls_pwe_tagged_mode_basic_info.ingress_native_ac_vlan_port_id,
                                                0,
                                                0,
                                                bcmVlanActionDelete,
                                                bcmVlanActionDelete,
                                                0,
                                                0,
                                                cint_vpls_pwe_tagged_mode_basic_info.ingress_vlan_edit_profile,
                                                cint_vpls_pwe_tagged_mode_basic_info.tag_format_double_tagged, 1), error_msg);

    /*
     * Add AC for inner ETH EVE (adding service tags in P2P (vsi=0))
     * For Egress flow
     */
    BCM_IF_ERROR_RETURN_MSG(vpls_pwe_tagged_mode_add_core_native_ac(unit, 0 /*cint_vpls_pwe_tagged_mode_basic_info.service_vsi */,
                                                 cint_vpls_pwe_tagged_mode_basic_info.mpls_port_id_eg,
                                                 &(cint_vpls_pwe_tagged_mode_basic_info.egress_native_ac_vlan_port_id),
                                                 1, &dummy_encap_id), "");
    /*
     * Add EVE for the AC created in the previous step
     */
    snprintf(error_msg, sizeof(error_msg), "port=0x%08x", cint_vpls_pwe_tagged_mode_basic_info.egress_native_ac_vlan_port_id);
    BCM_IF_ERROR_RETURN_MSG(vlan_translate_ive_eve_translation_set(unit,
                                                cint_vpls_pwe_tagged_mode_basic_info.egress_native_ac_vlan_port_id,
                                                cint_vpls_pwe_tagged_mode_basic_info.outer_tpid,
                                                cint_vpls_pwe_tagged_mode_basic_info.inner_tpid,
                                                bcmVlanActionAdd,
                                                bcmVlanActionAdd,
                                                cint_vpls_pwe_tagged_mode_basic_info.egress_canonical_outer_vlan,
                                                cint_vpls_pwe_tagged_mode_basic_info.egress_canonical_inner_vlan,
                                                cint_vpls_pwe_tagged_mode_basic_info.egress_vlan_edit_profile,
                                                cint_vpls_pwe_tagged_mode_basic_info.tag_format_untagged, 0), error_msg);

    return BCM_E_NONE;
}

/*
 * Main function indexed native ac scenario.
 */
int
vpls_pwe_tagged_mode_basic_indexed_native_ac_p2p_main(
    int unit,
    int access_port,
    int core_port,
    int ingress_ac_native_wide_data_enable)
{
    char error_msg[200]={0,};
    int nof_labels = 2;

    BCM_IF_ERROR_RETURN_MSG(get_first_fec_in_range_which_not_in_ecmp_range(unit, 0, 0, &cint_vpls_pwe_tagged_mode_basic_info.mpls_fec_id), "");

    vpls_pwe_tagged_mode_basic_init(access_port, core_port);

    /*
     * Configure AC and PWE ports
     */
    BCM_IF_ERROR_RETURN_MSG(vpls_pwe_tagged_mode_basic_configure_port_properties(unit, cint_vpls_pwe_tagged_mode_basic_info.access_port,
                                                              cint_vpls_pwe_tagged_mode_basic_info.core_port,
                                                              cint_vpls_pwe_tagged_mode_basic_info.service_vsi,
                                                              cint_vpls_pwe_tagged_mode_basic_info.core_eth_rif, TRUE), "");

    BCM_IF_ERROR_RETURN_MSG(vpls_pwe_tagged_mode_basic_create_vsis(unit, cint_vpls_pwe_tagged_mode_basic_info.service_vsi,
                                                cint_vpls_pwe_tagged_mode_basic_info.core_eth_rif), "");

    /*
     * Configure L3 interfaces
     */
    BCM_IF_ERROR_RETURN_MSG(vpls_pwe_tagged_mode_basic_create_l3_interfaces(unit, cint_vpls_pwe_tagged_mode_basic_info.core_eth_rif,
                                                         cint_vpls_pwe_tagged_mode_basic_info.core_eth_rif_mac), "");

    /*
     * Configure an ARP entries
     */
    BCM_IF_ERROR_RETURN_MSG(vpls_pwe_tagged_mode_basic_create_arp_entry(unit, &(cint_vpls_pwe_tagged_mode_basic_info.core_arp_id),
                                                     cint_vpls_pwe_tagged_mode_basic_info.core_next_hop_mac,
                                                     cint_vpls_pwe_tagged_mode_basic_info.core_eth_rif), "");

    /*
     * Configure a push entry.
     */
    BCM_IF_ERROR_RETURN_MSG(vpls_pwe_tagged_mode_basic_create_mpls_tunnel(unit,
                                                       cint_vpls_pwe_tagged_mode_basic_info.service_mpls_tunnel_label_1,
                                                       cint_vpls_pwe_tagged_mode_basic_info.service_mpls_tunnel_label_2,
                                                       2, cint_vpls_pwe_tagged_mode_basic_info.core_arp_id,
                                                       &cint_vpls_pwe_tagged_mode_basic_info.mpls_tunnel_id,
                                                       0), "");

    /*
     * Configure fec entry
     */
    BCM_IF_ERROR_RETURN_MSG(vpls_pwe_tagged_mode_basic_create_fec_entry(unit, cint_vpls_pwe_tagged_mode_basic_info.mpls_fec_id,
                                                     cint_vpls_pwe_tagged_mode_basic_info.mpls_tunnel_id,
                                                     cint_vpls_pwe_tagged_mode_basic_info.core_port), "");

    /*
     * Configure a termination label for the ingress flow
     */
    bcm_mpls_label_t label_array[2];
    label_array[0] = cint_vpls_pwe_tagged_mode_basic_info.service_mpls_tunnel_label_1;
    label_array[1] = cint_vpls_pwe_tagged_mode_basic_info.service_mpls_tunnel_label_2;
    BCM_IF_ERROR_RETURN_MSG(vpls_pwe_tagged_mode_basic_create_termination_stack(unit, label_array, 2), "");

    /*
     * configure PWE tunnel - egress flow
     */
    BCM_IF_ERROR_RETURN_MSG(vpls_pwe_tagged_mode_basic_mpls_port_add_encapsulation(unit,
                                                                &(cint_vpls_pwe_tagged_mode_basic_info.mpls_port_id_eg),
                                                                cint_vpls_pwe_tagged_mode_basic_info.service_pwe_label,
                                                                &(cint_vpls_pwe_tagged_mode_basic_info.pwe_encap_id),
                                                                0), "");

    /*
     * configure PWE tunnel - ingress flow
     */
    BCM_IF_ERROR_RETURN_MSG(vpls_pwe_tagged_mode_basic_mpls_port_add_termination(unit,
                                                              &(cint_vpls_pwe_tagged_mode_basic_info.mpls_port_id_ing),
                                                              cint_vpls_pwe_tagged_mode_basic_info.service_pwe_label,
                                                              &(cint_vpls_pwe_tagged_mode_basic_info.pwe_encap_id),
                                                              cint_vpls_pwe_tagged_mode_basic_info.mpls_fec_id,
                                                              cint_vpls_pwe_tagged_mode_basic_info.service_vsi), "");

    /** define ac and pwe ports */
    BCM_IF_ERROR_RETURN_MSG(vpls_pwe_tagged_mode_basic_vswitch_add_core_outer_ac(unit, cint_vpls_pwe_tagged_mode_basic_info.core_port,
                                                              cint_vpls_pwe_tagged_mode_basic_info.core_eth_rif,
                                                              &
                                                              (cint_vpls_pwe_tagged_mode_basic_info.outer_ac_vlan_port_id)), "");

    /*
     * Set tag formats for un tagged and double tagged packets
     */
    BCM_IF_ERROR_RETURN_MSG(vpls_pwe_tagged_mode_basic_tag_formats_set(unit), "");

    /*
     * Configure EVE for access to core traffic: add two service tags
     */
    snprintf(error_msg, sizeof(error_msg), "port=0x%08x", cint_vpls_pwe_tagged_mode_basic_info.outer_ac_vlan_port_id);
    BCM_IF_ERROR_RETURN_MSG(vlan_translate_ive_eve_translation_set(unit, cint_vpls_pwe_tagged_mode_basic_info.outer_ac_vlan_port_id,
                                                cint_vpls_pwe_tagged_mode_basic_info.outer_tpid,
                                                cint_vpls_pwe_tagged_mode_basic_info.inner_tpid, bcmVlanActionAdd,
                                                bcmVlanActionAdd,
                                                cint_vpls_pwe_tagged_mode_basic_info.outer_ac_egress_outer_vlan,
                                                cint_vpls_pwe_tagged_mode_basic_info.outer_ac_egress_inner_vlan,
                                                cint_vpls_pwe_tagged_mode_basic_info.egress_vlan_edit_profile,
                                                cint_vpls_pwe_tagged_mode_basic_info.tag_format_untagged, 0), error_msg);

    /*
     * Add AC for inner ETH IVE (removing/replacing service tags)
     * For Ingress flow. Also add the outer AC that is the result of
     * Ethernet forwarding with the exposed DA.
     */
    BCM_IF_ERROR_RETURN_MSG(vpls_pwe_tagged_mode_add_network_native_ac(unit, cint_vpls_pwe_tagged_mode_basic_info.service_vsi,
                                                    cint_vpls_pwe_tagged_mode_basic_info.service_mac_1,
                                                    &(cint_vpls_pwe_tagged_mode_basic_info.ingress_native_ac_vlan_port_id),
                                                    &(cint_vpls_pwe_tagged_mode_basic_info.access_egress_vlan_port_id),
                                                    cint_vpls_pwe_tagged_mode_basic_info.mpls_port_id_ing,
                                                    cint_vpls_pwe_tagged_mode_basic_info.ingress_canonical_outer_vlan,
                                                    cint_vpls_pwe_tagged_mode_basic_info.ingress_canonical_inner_vlan,
                                                    cint_vpls_pwe_tagged_mode_basic_info.access_port, 0,
                                                    ingress_ac_native_wide_data_enable, TRUE, FALSE), "");

    /*
     * Add Cross connect in case of p2p
     */
    BCM_IF_ERROR_RETURN_MSG(vpls_pwe_tagged_mode_add_cross_connect_native_ac(unit,
                                                cint_vpls_pwe_tagged_mode_basic_info.ingress_native_ac_vlan_port_id,
                                                cint_vpls_pwe_tagged_mode_basic_info.access_egress_vlan_port_id), "");

    /*
     * Add IVE for the AC created in the previous step
     */
    snprintf(error_msg, sizeof(error_msg), "port=0x%08x", cint_vpls_pwe_tagged_mode_basic_info.ingress_native_ac_vlan_port_id);
    BCM_IF_ERROR_RETURN_MSG(vlan_translate_ive_eve_translation_set(unit,
                                                cint_vpls_pwe_tagged_mode_basic_info.ingress_native_ac_vlan_port_id,
                                                0,
                                                0,
                                                bcmVlanActionDelete,
                                                bcmVlanActionDelete,
                                                0,
                                                0,
                                                cint_vpls_pwe_tagged_mode_basic_info.ingress_vlan_edit_profile,
                                                cint_vpls_pwe_tagged_mode_basic_info.tag_format_double_tagged, 1), error_msg);
    /*
     * Add AC for inner ETH EVE (adding service tags)
     * For Egress flow
     */
    BCM_IF_ERROR_RETURN_MSG(vpls_pwe_tagged_mode_add_core_native_ac(unit, 0,
                                                 cint_vpls_pwe_tagged_mode_basic_info.mpls_port_id_eg,
                                                 &(cint_vpls_pwe_tagged_mode_basic_info.egress_native_ac_vlan_port_id),
                                                 0, &(cint_vpls_pwe_tagged_mode_basic_info.indexed_ac_encap_id)), "");
    /*
     * Add EVE for the AC created in the previous step
     */
    snprintf(error_msg, sizeof(error_msg), "port=0x%08x", cint_vpls_pwe_tagged_mode_basic_info.egress_native_ac_vlan_port_id);
    BCM_IF_ERROR_RETURN_MSG(vlan_translate_ive_eve_translation_set(unit,
                                                cint_vpls_pwe_tagged_mode_basic_info.egress_native_ac_vlan_port_id,
                                                cint_vpls_pwe_tagged_mode_basic_info.outer_tpid,
                                                cint_vpls_pwe_tagged_mode_basic_info.inner_tpid,
                                                bcmVlanActionAdd, bcmVlanActionAdd,
                                                cint_vpls_pwe_tagged_mode_basic_info.egress_canonical_outer_vlan,
                                                cint_vpls_pwe_tagged_mode_basic_info.egress_canonical_inner_vlan,
                                                cint_vpls_pwe_tagged_mode_basic_info.egress_vlan_edit_profile,
                                                cint_vpls_pwe_tagged_mode_basic_info.tag_format_untagged, 0), error_msg);

    BCM_IF_ERROR_RETURN_MSG(vpls_pwe_tagged_mode_add_cross_connect_access_ac(unit,
                                                cint_vpls_pwe_tagged_mode_basic_info.access_port_ac_in_lif,
                                                cint_vpls_pwe_tagged_mode_basic_info.indexed_ac_encap_id, cint_vpls_pwe_tagged_mode_basic_info.mpls_fec_id), "");
    return BCM_E_NONE;
}

/*
 * Add a symmetric native AC.
 * For core -> customer traffic, it's the ingress native AC classified with native vlans and PWE.
 * For customer -> core traffic, it's the egress native AC pointed by the customer DA with PWE in the linked pointer.
 */
int
vpls_pwe_tagged_mode_add_symmetric_native_ac(
    int unit,
    bcm_vpn_t vsi,
    bcm_gport_t * vlan_port_id,
    bcm_gport_t ingress_mpls_port_id,
    bcm_gport_t egress_mpls_port_id,
    bcm_vlan_t outer_vlan,
    bcm_vlan_t inner_vlan,
    bcm_port_t port,
    int * native_ac_encap_id)
{
    bcm_vlan_port_t vlan_port;
    bcm_l2_addr_t l2addr;
    /*
     * add port.
     */
    bcm_vlan_port_t_init(&vlan_port);
    vlan_port.flags = BCM_VLAN_PORT_NATIVE;
    vlan_port.flags |= BCM_VLAN_PORT_WITH_ID;
    BCM_GPORT_SUB_TYPE_LIF_SET(vlan_port.vlan_port_id, 0, *vlan_port_id);
    BCM_GPORT_VLAN_PORT_ID_SET(vlan_port.vlan_port_id, vlan_port.vlan_port_id);
    vlan_port.tunnel_id = egress_mpls_port_id;
    vlan_port.vsi = 0;
    vlan_port.port = port; /** For learned destination.*/
    vlan_port.criteria = BCM_VLAN_PORT_MATCH_NONE;
    BCM_IF_ERROR_RETURN_MSG(bcm_vlan_port_create(unit, &vlan_port), "");
    /*
     * Save the created vlan_port_id
     */
    *vlan_port_id = vlan_port.vlan_port_id;
    *native_ac_encap_id = vlan_port.encap_id;

    BCM_IF_ERROR_RETURN_MSG(bcm_vswitch_port_add(unit, vsi, vlan_port.vlan_port_id), "");
    
    printf("symmetric native ac = 0x%08x\n", vlan_port.vlan_port_id);

    /*
     * Add Match
     */
    bcm_port_match_info_t match_info;
    bcm_port_match_info_t_init(&match_info);
    match_info.flags = BCM_PORT_MATCH_INGRESS_ONLY | BCM_PORT_MATCH_NATIVE;
    match_info.port = ingress_mpls_port_id;
    match_info.match = BCM_PORT_MATCH_PORT_VLAN_STACKED;        /* Match 2 tags */
    match_info.match_vlan = outer_vlan;
    match_info.match_inner_vlan = inner_vlan;
    BCM_IF_ERROR_RETURN_MSG(bcm_port_match_add(unit, vlan_port.vlan_port_id, &match_info), "");

    return BCM_E_NONE;
}

/*
 * Main function indexed native ac learning scenario.
 * For core -> customer, static MACT is added.
 *     After the traffic, native SA and native AC should be learned.
 * For customer -> core, no static MACT is added.
 *     The learned MACT should work.
 */
int
vpls_pwe_tagged_mode_basic_indexed_native_ac_learn_main(
    int unit,
    int access_port,
    int core_port)
{
    char error_msg[200]={0,};

    if (*dnxc_data_get(unit, "l2", "feature", "learn_payload_native_update_enable", NULL) == 0) {
        return BCM_E_UNAVAIL;
    }

    cint_vpls_pwe_tagged_mode_basic_info.ingress_native_ac_vlan_port_id = *dnxc_data_get(unit, "l3", "rif", "nof_rifs", NULL) + 0x234;

    vpls_pwe_tagged_mode_basic_init(access_port, core_port);

    /*
     * Configure AC and PWE ports
     */
    BCM_IF_ERROR_RETURN_MSG(vpls_pwe_tagged_mode_basic_configure_port_properties(unit, cint_vpls_pwe_tagged_mode_basic_info.access_port,
                                                              cint_vpls_pwe_tagged_mode_basic_info.core_port,
                                                              cint_vpls_pwe_tagged_mode_basic_info.service_vsi,
                                                              cint_vpls_pwe_tagged_mode_basic_info.core_eth_rif, FALSE), "");

    BCM_IF_ERROR_RETURN_MSG(vpls_pwe_tagged_mode_basic_create_vsis(unit, cint_vpls_pwe_tagged_mode_basic_info.service_vsi,
                                                cint_vpls_pwe_tagged_mode_basic_info.core_eth_rif), "");

    /*
     * Configure L3 interfaces 
     */
    BCM_IF_ERROR_RETURN_MSG(vpls_pwe_tagged_mode_basic_create_l3_interfaces(unit, cint_vpls_pwe_tagged_mode_basic_info.core_eth_rif,
                                                         cint_vpls_pwe_tagged_mode_basic_info.core_eth_rif_mac), "");

    /*
     * Configure an ARP entries
     */
    BCM_IF_ERROR_RETURN_MSG(vpls_pwe_tagged_mode_basic_create_arp_entry(unit, &(cint_vpls_pwe_tagged_mode_basic_info.core_arp_id),
                                                     cint_vpls_pwe_tagged_mode_basic_info.core_next_hop_mac,
                                                     cint_vpls_pwe_tagged_mode_basic_info.core_eth_rif), "");

    /*
     * Configure a push entry.
     */
    BCM_IF_ERROR_RETURN_MSG(vpls_pwe_tagged_mode_basic_create_mpls_tunnel(unit,
                                                       cint_vpls_pwe_tagged_mode_basic_info.service_mpls_tunnel_label_1,
                                                       cint_vpls_pwe_tagged_mode_basic_info.service_mpls_tunnel_label_2,
                                                       2, cint_vpls_pwe_tagged_mode_basic_info.core_arp_id,
                                                       &cint_vpls_pwe_tagged_mode_basic_info.mpls_tunnel_id,
                                                       0), "");


    /*
     * Configure a termination label for the ingress flow  
     */
    bcm_mpls_label_t label_array[2];
    label_array[0] = cint_vpls_pwe_tagged_mode_basic_info.service_mpls_tunnel_label_1;
    label_array[1] = cint_vpls_pwe_tagged_mode_basic_info.service_mpls_tunnel_label_2;
    BCM_IF_ERROR_RETURN_MSG(vpls_pwe_tagged_mode_basic_create_termination_stack(unit, label_array, 2), "");

    /*
     * configure PWE encapsulation with LSP in the link list - egress flow 
     */
    BCM_IF_ERROR_RETURN_MSG(vpls_pwe_tagged_mode_basic_mpls_port_add_encapsulation_with_tunnel(unit,
                                                                &(cint_vpls_pwe_tagged_mode_basic_info.mpls_port_id_eg),
                                                                cint_vpls_pwe_tagged_mode_basic_info.service_pwe_label,
                                                                &(cint_vpls_pwe_tagged_mode_basic_info.pwe_encap_id),
                                                                0,
                                                                cint_vpls_pwe_tagged_mode_basic_info.mpls_tunnel_id), "");

    /*
     * configure PWE tunnel - ingress flow 
     */
    BCM_IF_ERROR_RETURN_MSG(vpls_pwe_tagged_mode_basic_mpls_port_add_termination(unit,
                                                              &(cint_vpls_pwe_tagged_mode_basic_info.mpls_port_id_ing),
                                                              cint_vpls_pwe_tagged_mode_basic_info.service_pwe_label,
                                                              &(cint_vpls_pwe_tagged_mode_basic_info.pwe_encap_id),
                                                              cint_vpls_pwe_tagged_mode_basic_info.mpls_fec_id,
                                                              cint_vpls_pwe_tagged_mode_basic_info.service_vsi), "");

    /** define ac and pwe ports */
    BCM_IF_ERROR_RETURN_MSG(vpls_pwe_tagged_mode_basic_vswitch_add_core_outer_ac(unit, cint_vpls_pwe_tagged_mode_basic_info.core_port,
                                                              cint_vpls_pwe_tagged_mode_basic_info.core_eth_rif,
                                                              &(cint_vpls_pwe_tagged_mode_basic_info.outer_ac_vlan_port_id)), "");

    /*
     * Set tag formats for un tagged and double tagged packets
     */
    BCM_IF_ERROR_RETURN_MSG(vpls_pwe_tagged_mode_basic_tag_formats_set(unit), "");

    /*
     * Configure EVE for access to core traffic: add two service tags 
     */
    snprintf(error_msg, sizeof(error_msg), "port=0x%08x", cint_vpls_pwe_tagged_mode_basic_info.outer_ac_vlan_port_id);
    BCM_IF_ERROR_RETURN_MSG(vlan_translate_ive_eve_translation_set(unit, cint_vpls_pwe_tagged_mode_basic_info.outer_ac_vlan_port_id,
                                                cint_vpls_pwe_tagged_mode_basic_info.outer_tpid,
                                                cint_vpls_pwe_tagged_mode_basic_info.inner_tpid,
                                                bcmVlanActionAdd,
                                                bcmVlanActionAdd,
                                                cint_vpls_pwe_tagged_mode_basic_info.outer_ac_egress_outer_vlan,
                                                cint_vpls_pwe_tagged_mode_basic_info.outer_ac_egress_inner_vlan,
                                                cint_vpls_pwe_tagged_mode_basic_info.egress_vlan_edit_profile,
                                                cint_vpls_pwe_tagged_mode_basic_info.tag_format_untagged, 0), error_msg);

    /*
     * Add symmetric native AC for inner ETH IVE/EVE (removing/replacing service tags)
     * for both core -> customer and customer -> core traffic.
     */
    BCM_IF_ERROR_RETURN_MSG(vpls_pwe_tagged_mode_add_symmetric_native_ac(unit, cint_vpls_pwe_tagged_mode_basic_info.service_vsi,
                                                      &(cint_vpls_pwe_tagged_mode_basic_info.ingress_native_ac_vlan_port_id),
                                                      cint_vpls_pwe_tagged_mode_basic_info.mpls_port_id_ing,
                                                      cint_vpls_pwe_tagged_mode_basic_info.mpls_port_id_eg,
                                                      cint_vpls_pwe_tagged_mode_basic_info.ingress_canonical_outer_vlan,
                                                      cint_vpls_pwe_tagged_mode_basic_info.ingress_canonical_inner_vlan,
                                                      cint_vpls_pwe_tagged_mode_basic_info.access_port,
                                                      &(cint_vpls_pwe_tagged_mode_basic_info.indexed_ac_encap_id)), "");
    cint_vpls_pwe_tagged_mode_basic_info.egress_native_ac_vlan_port_id = cint_vpls_pwe_tagged_mode_basic_info.ingress_native_ac_vlan_port_id;

    /*
     * Also add the outer AC that is the result of Ethernet forwarding with the exposed DA.
     */
    BCM_IF_ERROR_RETURN_MSG(vpls_pwe_tagged_mode_add_network_egress_outer_ac(unit, cint_vpls_pwe_tagged_mode_basic_info.service_vsi,
                                                          cint_vpls_pwe_tagged_mode_basic_info.service_mac_1,
                                                          &(cint_vpls_pwe_tagged_mode_basic_info.access_egress_vlan_port_id),
                                                          cint_vpls_pwe_tagged_mode_basic_info.access_port,
                                                          0), "");

    /*
     * Add IVE for the AC created in the previous step
     */
    snprintf(error_msg, sizeof(error_msg), "port=0x%08x", cint_vpls_pwe_tagged_mode_basic_info.ingress_native_ac_vlan_port_id);
    BCM_IF_ERROR_RETURN_MSG(vlan_translate_ive_eve_translation_set(unit,
                                                cint_vpls_pwe_tagged_mode_basic_info.ingress_native_ac_vlan_port_id,
                                                0,
                                                0,
                                                bcmVlanActionDelete,
                                                bcmVlanActionDelete,
                                                0,
                                                0,
                                                cint_vpls_pwe_tagged_mode_basic_info.ingress_vlan_edit_profile,
                                                cint_vpls_pwe_tagged_mode_basic_info.tag_format_double_tagged, 1), error_msg);

    /*
     * Add EVE for the AC created in the previous step
     */
    snprintf(error_msg, sizeof(error_msg), "port=0x%08x", cint_vpls_pwe_tagged_mode_basic_info.egress_native_ac_vlan_port_id);
    BCM_IF_ERROR_RETURN_MSG(vlan_translate_ive_eve_translation_set(unit,
                                                cint_vpls_pwe_tagged_mode_basic_info.egress_native_ac_vlan_port_id,
                                                cint_vpls_pwe_tagged_mode_basic_info.outer_tpid,
                                                cint_vpls_pwe_tagged_mode_basic_info.inner_tpid,
                                                bcmVlanActionAdd, bcmVlanActionAdd,
                                                cint_vpls_pwe_tagged_mode_basic_info.egress_canonical_outer_vlan,
                                                cint_vpls_pwe_tagged_mode_basic_info.egress_canonical_inner_vlan,
                                                cint_vpls_pwe_tagged_mode_basic_info.egress_vlan_edit_profile,
                                                cint_vpls_pwe_tagged_mode_basic_info.tag_format_untagged, 0), error_msg);

    return BCM_E_NONE;
}

int
vpls_pwe_tagged_mode_basic_mpls_port_add_termination_p2p(
    int unit,
    bcm_gport_t out_port,
    bcm_gport_t * mpls_port_id,
    bcm_mpls_label_t pwe_label,
    int nof_service_tag)
{
    bcm_mpls_port_t mpls_port;
    bcm_gport_t gport_id;

    bcm_mpls_port_t_init(&mpls_port);
    if (*mpls_port_id != 0)
    {
         mpls_port.flags = BCM_MPLS_PORT_WITH_ID;
    }
    mpls_port.flags |= BCM_MPLS_PORT_EGRESS_TUNNEL;
    mpls_port.flags2 |= BCM_MPLS_PORT2_INGRESS_ONLY | BCM_MPLS_PORT2_CROSS_CONNECT;
    if (nof_service_tag > 0) {
        mpls_port.flags |= BCM_MPLS_PORT_SERVICE_TAGGED;
    }
    if (nof_service_tag <= 2) {
        mpls_port.nof_service_tags = nof_service_tag;
    } else {
        mpls_port.flags2 |= BCM_MPLS_PORT2_SERVICE_TAGGED_BASED_HEADER_ONLY;
    }

    BCM_GPORT_SUB_TYPE_LIF_SET(gport_id, 0, *mpls_port_id);
    BCM_GPORT_MPLS_PORT_ID_SET(mpls_port.mpls_port_id, gport_id);
    mpls_port.criteria = BCM_MPLS_PORT_MATCH_LABEL;
    mpls_port.match_label = pwe_label;
    mpls_port.port = out_port;
    BCM_IF_ERROR_RETURN_MSG(bcm_mpls_port_add(unit, 0, mpls_port), "");

    *mpls_port_id = mpls_port.mpls_port_id;

    printf("ingress mpls_port_id with service tag %d: 0x%08x\n", nof_service_tag, *mpls_port_id);

    return BCM_E_NONE;
}

int
vpls_pwe_tagged_mode_basic_flexible_connect_add(
    int unit,
    bcm_gport_t mpls_port_id,
    int nof_match_vlan,
    bcm_vlan_t match_vlan,
    bcm_vlan_t match_inner_vlan,
    bcm_gport_t out_port,
    bcm_if_t encap_id)
{
    bcm_vswitch_flexible_connect_match_t port_match; 
    bcm_vswitch_flexible_connect_fwd_t port_fwd;

    bcm_vswitch_flexible_connect_match_t_init(&port_match);
    bcm_vswitch_flexible_connect_fwd_t_init(&port_fwd);

    port_match.match_port = mpls_port_id;
    port_match.match = BCM_PORT_MATCH_PORT;
    if (nof_match_vlan > 0) {
        port_match.match_vlan = match_vlan;
        port_match.match = BCM_PORT_MATCH_PORT_VLAN;
    }
    if (nof_match_vlan > 1) {
        port_match.match_inner_vlan = match_inner_vlan;
        port_match.match = BCM_PORT_MATCH_PORT_VLAN_STACKED;
    }

    port_fwd.forward_port = out_port;
    port_fwd.forward_encap = encap_id;

    BCM_IF_ERROR_RETURN_MSG(bcm_vswitch_flexible_connect_add(unit, 0, &port_match, &port_fwd), "");

    return BCM_E_NONE;
}

int
vpls_pwe_tagged_mode_basic_flexible_connect_delete(
    int unit,
    bcm_gport_t mpls_port_id,
    int nof_match_vlan,
    bcm_vlan_t match_vlan,
    bcm_vlan_t match_inner_vlan)
{
    bcm_vswitch_flexible_connect_match_t port_match; 
    bcm_vswitch_flexible_connect_fwd_t port_fwd;

    bcm_vswitch_flexible_connect_match_t_init(&port_match);
    bcm_vswitch_flexible_connect_fwd_t_init(&port_fwd);

    port_match.match_port = mpls_port_id;
    port_match.match = BCM_PORT_MATCH_PORT;
    if (nof_match_vlan > 0) {
        port_match.match_vlan = match_vlan;
        port_match.match = BCM_PORT_MATCH_PORT_VLAN;
    }
    if (nof_match_vlan > 1) {
        port_match.match_inner_vlan = match_inner_vlan;
        port_match.match = BCM_PORT_MATCH_PORT_VLAN_STACKED;
    }

    BCM_IF_ERROR_RETURN_MSG(bcm_vswitch_flexible_connect_delete(unit, &port_match), "");

    return BCM_E_NONE;
}


/*
 * Confirations for VPLS pwe-tagged-mode with Exended P2P.
 * Only the Core -> customer and neccessary vlan translations are relevant.
 * 4 pwe terminators are created with nof service tags = 0/1/2/x.
 * 3 egress ACs are created for nof service tags = 0/1/2.
 *   2 additional egress ACs are created for nof service tags = 1/2 for LP case.
 * Flexible connections are added between the pwe terminator and the egress ACs.
 * So, we have the following EXTENDED_P2P entries:
 * a. 2 2_vid entries: 1) 1 for 2_stag HP; 2) 1 for x_stag HP;
 * b. 3 1_vid entries: 1) 1 for 1_stag HP; 2) 1 for x_stag HP & LP; 3) 1 for 2_stag LP;
 * c. 3 0_vid entries: 1) 1 for 0_stag HP; 2) 1 for x_stag HP & LP; 3) 1 for 1_stag LP;
 *
 */
int
vpls_pwe_tagged_mode_basic_extended_p2p_main(
    int unit,
    int access_port,
    int access_port2,
    int core_port)
{
    char error_msg[200]={0,};
    int idx, egr_ac_encap_id;

    vpls_pwe_tagged_mode_basic_init(access_port, core_port);

    /*
     * Configure AC and PWE ports
     */
    BCM_IF_ERROR_RETURN_MSG(vpls_pwe_tagged_mode_basic_configure_port_properties(unit, cint_vpls_pwe_tagged_mode_basic_info.access_port,
                                                              cint_vpls_pwe_tagged_mode_basic_info.core_port,
                                                              cint_vpls_pwe_tagged_mode_basic_info.service_vsi,
                                                              cint_vpls_pwe_tagged_mode_basic_info.core_eth_rif, FALSE), "");

    BCM_IF_ERROR_RETURN_MSG(vpls_pwe_tagged_mode_basic_create_vsis(unit, cint_vpls_pwe_tagged_mode_basic_info.service_vsi,
                                                cint_vpls_pwe_tagged_mode_basic_info.core_eth_rif), "");

    /*
     * Configure L3 interfaces 
     */
    BCM_IF_ERROR_RETURN_MSG(vpls_pwe_tagged_mode_basic_create_l3_interfaces(unit, cint_vpls_pwe_tagged_mode_basic_info.core_eth_rif,
                                                         cint_vpls_pwe_tagged_mode_basic_info.core_eth_rif_mac), "");

    /*
     * Configure a termination label for the ingress flow  
     */
    bcm_mpls_label_t label_array[2];
    label_array[0] = cint_vpls_pwe_tagged_mode_basic_info.service_mpls_tunnel_label_1;
    label_array[1] = cint_vpls_pwe_tagged_mode_basic_info.service_mpls_tunnel_label_2;
    BCM_IF_ERROR_RETURN_MSG(vpls_pwe_tagged_mode_basic_create_termination_stack(unit, label_array, 2), "");

    /*
     * Configuration for nof service tags = 0/1/2
     */
    for (idx = 0; idx < cint_vpls_pwe_tagged_mode_extended_p2p_info.nof_service_tag_types - 1; idx++) {
        /** configure PWE tunnel - ingress flow for nof_service_tags = 0/1/2 */
        snprintf(error_msg, sizeof(error_msg), "idx %d", idx);
        BCM_IF_ERROR_RETURN_MSG(vpls_pwe_tagged_mode_basic_mpls_port_add_termination_p2p(unit,
                  core_port,
                  &(cint_vpls_pwe_tagged_mode_extended_p2p_info.mpls_port_id_ing[idx]),
                  cint_vpls_pwe_tagged_mode_extended_p2p_info.service_pwe_label[idx],
                  idx), error_msg);

        /** Also add the outer AC that is the result of Ethernet forwarding with the exposed DA.*/
        BCM_IF_ERROR_RETURN_MSG(vpls_pwe_tagged_mode_add_network_egress_outer_ac(unit,
                   cint_vpls_pwe_tagged_mode_basic_info.service_vsi,
                   cint_vpls_pwe_tagged_mode_basic_info.service_mac_1,
                   &(cint_vpls_pwe_tagged_mode_extended_p2p_info.access_egress_vlan_port_id[idx]),
                   cint_vpls_pwe_tagged_mode_basic_info.access_port,
                   1), error_msg);

        /** Add the flexible connext entries. */
        printf("Add flexible connection, nof_vlan %d: pwe(0x%08X) + vid1(%d) + vid2(%d) -> outport(%d) + outAC(0x%08X)\n",
               idx, cint_vpls_pwe_tagged_mode_extended_p2p_info.mpls_port_id_ing[idx],
               cint_vpls_pwe_tagged_mode_extended_p2p_info.ing_outer_stag,
               cint_vpls_pwe_tagged_mode_extended_p2p_info.ing_inner_stag,
               cint_vpls_pwe_tagged_mode_basic_info.access_port,
               cint_vpls_pwe_tagged_mode_extended_p2p_info.access_egress_vlan_port_id[idx]);

        egr_ac_encap_id = BCM_GPORT_SUB_TYPE_LIF_VAL_GET(cint_vpls_pwe_tagged_mode_extended_p2p_info.access_egress_vlan_port_id[idx]);
        BCM_IF_ERROR_RETURN_MSG(vpls_pwe_tagged_mode_basic_flexible_connect_add(unit,
                  cint_vpls_pwe_tagged_mode_extended_p2p_info.mpls_port_id_ing[idx],
                  idx,
                  cint_vpls_pwe_tagged_mode_extended_p2p_info.ing_outer_stag,
                  cint_vpls_pwe_tagged_mode_extended_p2p_info.ing_inner_stag,
                  cint_vpls_pwe_tagged_mode_basic_info.access_port,
                  egr_ac_encap_id), error_msg);

        /** Add EVE for the AC created in the previous step for 0tag case */
        snprintf(error_msg, sizeof(error_msg), "port=0x%08x",
            cint_vpls_pwe_tagged_mode_extended_p2p_info.access_egress_vlan_port_id[idx]);
        BCM_IF_ERROR_RETURN_MSG(vlan_translate_ive_eve_translation_set(unit,
                  cint_vpls_pwe_tagged_mode_extended_p2p_info.access_egress_vlan_port_id[idx],
                  cint_vpls_pwe_tagged_mode_basic_info.outer_tpid,
                  cint_vpls_pwe_tagged_mode_basic_info.inner_tpid,
                  cint_vpls_pwe_tagged_mode_extended_p2p_info.egr_vlan_action[idx][0],
                  cint_vpls_pwe_tagged_mode_extended_p2p_info.egr_vlan_action[idx][1],
                  cint_vpls_pwe_tagged_mode_extended_p2p_info.egress_outer_vlan[idx],
                  cint_vpls_pwe_tagged_mode_extended_p2p_info.egress_inner_vlan[idx],
                  cint_vpls_pwe_tagged_mode_basic_info.egress_vlan_edit_profile,
                  cint_vpls_pwe_tagged_mode_extended_p2p_info.egr_tag_format[idx], 0), error_msg);



        /*
         * Repeat the above configurations for the 2nd lookup when the primary lookup doesn't hit.
         */
        if (idx > 0) {

            /** Add the outer AC for the 2nd lookup results*/
            snprintf(error_msg, sizeof(error_msg), "idx %d", idx);
            BCM_IF_ERROR_RETURN_MSG(vpls_pwe_tagged_mode_add_network_egress_outer_ac(unit,
                   cint_vpls_pwe_tagged_mode_basic_info.service_vsi,
                   cint_vpls_pwe_tagged_mode_basic_info.service_mac_1,
                   &(cint_vpls_pwe_tagged_mode_extended_p2p_info.access_egress_vlan_port_id2[idx]),
                   access_port2,
                   1), error_msg);

            /** Add the flexible connext entries.*/
            printf("Add flexible connection, nof_vlan %d: pwe(0x%08X) + vid1(%d) + vid2(%d) -> outport(%d) + outAC(0x%08X)\n",
               idx - 1, cint_vpls_pwe_tagged_mode_extended_p2p_info.mpls_port_id_ing[idx],
               cint_vpls_pwe_tagged_mode_extended_p2p_info.ing_outer_stag,
               cint_vpls_pwe_tagged_mode_extended_p2p_info.ing_inner_stag,
               access_port2,
               cint_vpls_pwe_tagged_mode_extended_p2p_info.access_egress_vlan_port_id2[idx]);

            egr_ac_encap_id = BCM_GPORT_SUB_TYPE_LIF_VAL_GET(cint_vpls_pwe_tagged_mode_extended_p2p_info.access_egress_vlan_port_id2[idx]);
            BCM_IF_ERROR_RETURN_MSG(vpls_pwe_tagged_mode_basic_flexible_connect_add(unit,
                  cint_vpls_pwe_tagged_mode_extended_p2p_info.mpls_port_id_ing[idx],
                  idx - 1,
                  cint_vpls_pwe_tagged_mode_extended_p2p_info.ing_outer_stag,
                  cint_vpls_pwe_tagged_mode_extended_p2p_info.ing_inner_stag,
                  access_port2,
                  egr_ac_encap_id), error_msg);

            /** Add EVE for the AC created in the previous step for 0tag case */
            snprintf(error_msg, sizeof(error_msg), "port=0x%08x",
                cint_vpls_pwe_tagged_mode_extended_p2p_info.access_egress_vlan_port_id2[idx]);
            BCM_IF_ERROR_RETURN_MSG(vlan_translate_ive_eve_translation_set(unit,
                  cint_vpls_pwe_tagged_mode_extended_p2p_info.access_egress_vlan_port_id2[idx],
                  cint_vpls_pwe_tagged_mode_basic_info.outer_tpid,
                  cint_vpls_pwe_tagged_mode_basic_info.inner_tpid,
                  cint_vpls_pwe_tagged_mode_extended_p2p_info.egr_vlan_action[idx][0],
                  cint_vpls_pwe_tagged_mode_extended_p2p_info.egr_vlan_action[idx][1],
                  cint_vpls_pwe_tagged_mode_extended_p2p_info.egress_outer_vlan[idx] + 100,
                  cint_vpls_pwe_tagged_mode_extended_p2p_info.egress_inner_vlan[idx] + 100,
                  cint_vpls_pwe_tagged_mode_basic_info.egress_vlan_edit_profile,
                  cint_vpls_pwe_tagged_mode_extended_p2p_info.egr_tag_format[idx], 0), error_msg);

        }
    }

    /** Configuration a PWE terminator with nof service tags = X (depending on packet tag format)*/
    snprintf(error_msg, sizeof(error_msg), "idx %d", idx);
    BCM_IF_ERROR_RETURN_MSG(vpls_pwe_tagged_mode_basic_mpls_port_add_termination_p2p(unit,
                  core_port,
                  &(cint_vpls_pwe_tagged_mode_extended_p2p_info.mpls_port_id_ing[3]),
                  cint_vpls_pwe_tagged_mode_extended_p2p_info.service_pwe_label[3],
                  idx), error_msg);

    /** Cross connect the above pwe terminator to kinds of tag format cases: 0/1/2*/
    for (idx = 0; idx < 3; idx++) {
        printf("Add flexible connection, nof_vlan %d: pwe(0x%08X) + vid1(%d) + vid2(%d) -> outport(%d) + outAC(0x%08X)\n",
               idx, cint_vpls_pwe_tagged_mode_extended_p2p_info.mpls_port_id_ing[3],
               cint_vpls_pwe_tagged_mode_extended_p2p_info.ing_outer_stag,
               cint_vpls_pwe_tagged_mode_extended_p2p_info.ing_inner_stag,
               cint_vpls_pwe_tagged_mode_basic_info.access_port,
               cint_vpls_pwe_tagged_mode_extended_p2p_info.access_egress_vlan_port_id[idx]);

        egr_ac_encap_id = BCM_GPORT_SUB_TYPE_LIF_VAL_GET(cint_vpls_pwe_tagged_mode_extended_p2p_info.access_egress_vlan_port_id[idx]);
        snprintf(error_msg, sizeof(error_msg), "idx %d", idx);
        BCM_IF_ERROR_RETURN_MSG(vpls_pwe_tagged_mode_basic_flexible_connect_add(unit,
                  cint_vpls_pwe_tagged_mode_extended_p2p_info.mpls_port_id_ing[3],
                  idx,
                  cint_vpls_pwe_tagged_mode_extended_p2p_info.ing_outer_stag,
                  cint_vpls_pwe_tagged_mode_extended_p2p_info.ing_inner_stag,
                  cint_vpls_pwe_tagged_mode_basic_info.access_port,
                  egr_ac_encap_id), error_msg);

    }

    /*
     * By default the packet with sevice tags in pwe_tagged_mode will be discarded if no match in 
     * native classification. It's done by a P2P default LIF.
     * We need to abondan the discard or lower it's priority for Extended P2P. 
     */
    int gport, trap_id;
    BCM_IF_ERROR_RETURN_MSG(bcm_rx_trap_type_get(unit, 0, bcmRxTrapDfltDroppedPacket, &trap_id), "");

    BCM_GPORT_TRAP_SET(gport, 0, 0, trap_id);
    BCM_IF_ERROR_RETURN_MSG(bcm_vlan_control_set (unit, bcmVlanNativeVplsServiceTaggedMiss, gport),
        "bcmVlanNativeVplsServiceTaggedMiss");

    return BCM_E_NONE;
}


/*
 * Remove the High Priority entries, the the Low Priority entries should be used.
 * This should be used after the following config to verify the priority entries.
 *   vpls_pwe_tagged_mode_basic_extended_p2p_main()
 *
 * 4 HP entries: 1) 1 2_vid entry for x_stag (incoming 2 tag);
 *               2) 1 2_vid entry for 2_stag;
 *               3) 1 1_vid entry for 1_stag;
 *               4) 1 0_vid entry for 0_stag;
 */
int
vpls_pwe_tagged_mode_basic_extended_p2p_remove_hp_entry(
    int unit)
{
    int idx, egr_ac_encap_id;

    /** remove the HP entries for 2/1/0_stag case.*/
    printf("HP: remove the 2/1/0 tag entries for 2/1/0_stag case \n");
    for (idx = 0; idx < 3; idx ++ )
    {
        printf("HP: Remove flexible connection, nof_vlan %d: pwe(0x%08X) + vid1(%d) + vid2(%d)\n",
               idx, cint_vpls_pwe_tagged_mode_extended_p2p_info.mpls_port_id_ing[idx],
               cint_vpls_pwe_tagged_mode_extended_p2p_info.ing_outer_stag,
               cint_vpls_pwe_tagged_mode_extended_p2p_info.ing_inner_stag);

        egr_ac_encap_id = BCM_GPORT_SUB_TYPE_LIF_VAL_GET(cint_vpls_pwe_tagged_mode_extended_p2p_info.access_egress_vlan_port_id[idx]);
        BCM_IF_ERROR_RETURN_MSG(vpls_pwe_tagged_mode_basic_flexible_connect_delete(unit,
                      cint_vpls_pwe_tagged_mode_extended_p2p_info.mpls_port_id_ing[idx],
                      idx,
                      cint_vpls_pwe_tagged_mode_extended_p2p_info.ing_outer_stag,
                      cint_vpls_pwe_tagged_mode_extended_p2p_info.ing_inner_stag), "for 2_tag");
    }

    /** remove the 2tag entries for x_stag case.*/
    idx = 3;
    printf("HP: remove the 2tag entries for x_stag case \n");
    printf("HP: Remove flexible connection, nof_vlan %d: pwe(0x%08X) + vid1(%d) + vid2(%d)\n",
               2, cint_vpls_pwe_tagged_mode_extended_p2p_info.mpls_port_id_ing[idx],
               cint_vpls_pwe_tagged_mode_extended_p2p_info.ing_outer_stag,
               cint_vpls_pwe_tagged_mode_extended_p2p_info.ing_inner_stag);

    egr_ac_encap_id = BCM_GPORT_SUB_TYPE_LIF_VAL_GET(cint_vpls_pwe_tagged_mode_extended_p2p_info.access_egress_vlan_port_id[idx]);
    BCM_IF_ERROR_RETURN_MSG(vpls_pwe_tagged_mode_basic_flexible_connect_delete(unit,
                  cint_vpls_pwe_tagged_mode_extended_p2p_info.mpls_port_id_ing[idx],
                  idx,
                  cint_vpls_pwe_tagged_mode_extended_p2p_info.ing_outer_stag,
                  cint_vpls_pwe_tagged_mode_extended_p2p_info.ing_inner_stag), "for x_tag");

    return BCM_E_NONE;
}

/*
 * Remove the Low Priority entries, packet should be dropped.
 * This should be used after the following config to verify the priority entries. 
 *   vpls_pwe_tagged_mode_basic_extended_p2p_main()
 *   vpls_pwe_tagged_mode_basic_extended_p2p_remove_hp_entry()
 *
 * 3 LP entries: 1) 1 1_vid for x_stag (incoming 2 tag);
 *               2) 1 1_vid for 2_stag;
 *               3) 1 0_vid for 1_stag;
 * 1 LP entries: 1) 1 0_vid for x_stag (incoming 1 tag);
 */
int
vpls_pwe_tagged_mode_basic_extended_p2p_remove_lp_entry(
    int unit)
{
    int idx, egr_ac_encap_id;

    /** remove the LP entries for 2/1_stag case.*/
    printf("LP: remove the 1/0 tag entries for 2/1_stag case \n");
    for (idx = 1; idx < 3; idx ++ )
    {
        printf("LP: Remove flexible connection, nof_vlan %d: pwe(0x%08X) + vid1(%d) + vid2(%d)\n",
               idx - 1, cint_vpls_pwe_tagged_mode_extended_p2p_info.mpls_port_id_ing[idx],
               cint_vpls_pwe_tagged_mode_extended_p2p_info.ing_outer_stag,
               cint_vpls_pwe_tagged_mode_extended_p2p_info.ing_inner_stag);

        egr_ac_encap_id = BCM_GPORT_SUB_TYPE_LIF_VAL_GET(cint_vpls_pwe_tagged_mode_extended_p2p_info.access_egress_vlan_port_id2[idx]);
        BCM_IF_ERROR_RETURN_MSG(vpls_pwe_tagged_mode_basic_flexible_connect_delete(unit,
                      cint_vpls_pwe_tagged_mode_extended_p2p_info.mpls_port_id_ing[idx],
                      idx - 1,
                      cint_vpls_pwe_tagged_mode_extended_p2p_info.ing_outer_stag,
                      cint_vpls_pwe_tagged_mode_extended_p2p_info.ing_inner_stag), "for 2/1_stag");
    }

    /** remove the 0/1tag entries for x_stag case.*/
    printf("LP: remove the 1/0 tag entries for x_stag case \n");
    for (idx = 0; idx < 2; idx ++ )
    {
        printf("LP: Remove flexible connection, nof_vlan %d: pwe(0x%08X) + vid1(%d) + vid2(%d)\n",
               idx, cint_vpls_pwe_tagged_mode_extended_p2p_info.mpls_port_id_ing[3],
               cint_vpls_pwe_tagged_mode_extended_p2p_info.ing_outer_stag,
               cint_vpls_pwe_tagged_mode_extended_p2p_info.ing_inner_stag);

        egr_ac_encap_id = BCM_GPORT_SUB_TYPE_LIF_VAL_GET(cint_vpls_pwe_tagged_mode_extended_p2p_info.access_egress_vlan_port_id[idx]);
        BCM_IF_ERROR_RETURN_MSG(vpls_pwe_tagged_mode_basic_flexible_connect_delete(unit,
                      cint_vpls_pwe_tagged_mode_extended_p2p_info.mpls_port_id_ing[3],
                      idx,
                      cint_vpls_pwe_tagged_mode_extended_p2p_info.ing_outer_stag,
                      cint_vpls_pwe_tagged_mode_extended_p2p_info.ing_inner_stag), "for x_tag");
    }
    return BCM_E_NONE;
}


