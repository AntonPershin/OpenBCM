/*
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2022 Broadcom Inc. All rights reserved.
 */
 
/* 
 * MPLS-TP Section OAM will be a super set of MPLS-TP LSP OAM  and PWE OAM by running OAM at {portxVlan} 
 * common to LSPs and PWEs.This CINT is a reference example for MPLS TP Section OAM
 *  
 * Configuration:
 * cint;                                                                  
 * cint_reset();                                                          
 * exit;  
 * cint ../../../../src/examples/sand/cint_ip_route_basic.c 
 * cint ../../../../src/examples/dpp/utility/cint_utils_l3.c 
 * cint ../../../../src/examples/sand/utility/cint_sand_utils_mpls.c
 * cint ../../../../src/examples/dpp/utility/cint_utils_mpls_port.c 
 * cint ../../../../src/examples/dpp/utility/cint_utils_l2.c 
 * cint ../../../../src/examples/sand/utility/cint_sand_utils_l2.c
 * cint ../../../../src/examples/dpp/utility/cint_utils_multicast.c 
 * cint ../../../../src/examples/dpp/utility/cint_utils_port.c 
 * cint ../../../../src/examples/sand/utility/cint_sand_utils_global.c  
 * cint ../../../../src/examples/sand/utility/cint_sand_utils_global.c  
 * cint ../../../../src/examples/dpp/utility/cint_utils_oam.c
 * cint ../../../../src/examples/sand/utility/cint_sand_utils_oam.c
 * cint ../../../../src/examples/sand/cint_vpls_mp_basic.c 
 * cint ../../../../src/examples/dpp/cint_oam.c              
 * cint ../../../../src/examples/sand/cint_sand_oam.c
 * cint ../../../../src/examples/dnx/oam/cint_oam_action.c
 * cint ../../../../src/examples/dnx/crps/cint_crps_oam_config.c
 * cint ../../../../src/examples/dnx/oam/cint_oam_basic.c
 * cint ../../../../src/examples/dpp/cint_oam_y1731_over_tunnel.c
 * cint ../../../../src/examples/sand/cint_sand_oam_y1731_over_tunnel.c
 * cint ../../../../src/examples/sand/cint_sand_oam_mpls_tp_section.c  
 * cint                                                                   
 * int unit = 0; 
 * int rv = 0; 
 * int in_port = 200; 
 * int out_port = 201;
 * rv = oam_run_with_defaults_mpls_tp_section(unit,in_port,out_port);
 * print rv; 
 * 
*/

int  verbose1=0;
/*Global variable for Section OAM */
/*AC LIF used for Section OAM */
bcm_gport_t section_oam_in_gport = 0;

/* Will hold all ports of the application */
int mpls_tp_path_port_array[2];
/* If a specific tunnel_id is required for the POP entry, it can be set here */
int static_in_tunnel_id = -1;

/* Will define which combination of egress label flags are used */
/*  ##############################################################################################
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 *  2) Only in QAX and above devices: Configuration of egress label separate TTL/EXP modes
 *  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 *  Test the configuration of egress label separate TTL/EXP modes.
 *  Set the mpls_various_scenarios_flag_mode value:
 * 
 *  mpls_various_scenarios_flag_mode = 0 - TTL_SET/EXP_SET
 *  mpls_various_scenarios_flag_mode = 1 - TTL_COPY/EXP_SET
 *  mpls_various_scenarios_flag_mode = 2 - TTL_SET/EXP_COPY
 *  mpls_various_scenarios_flag_mode = 3 - TTL_COPY/EXP_COPY
*/
int mpls_tp_path_flag_mode = -1;

int port1; /* port1*/
int port2; /* port2 */
int tpid = 0x8100;     /* tpid value for all vlan tags in the application*/
int vlan1 = 16; /* First vlan for this application */
bcm_mac_t remote_mac = {0x00, 0x11, 0x00, 0x00, 0x02, 0x22}; /* mac address for remote station */
bcm_mac_t global_mac = {0x00, 0x11, 0x00, 0x00, 0x01, 0x11}; /* global mac for this application */
bcm_mac_t my_mac_lsb = {0x00, 0x00, 0x00, 0x00, 0x01, 0x11}; /* my mac lsb for this application */
bcm_mac_t mpls_mac = {0x00, 0x11, 0x00, 0x00, 0x01, 0x13}; /* my mac for mpls side */
bcm_mac_t pwe_mac1 = {0x00, 0x00, 0x00, 0x00, 0x01, 0x18}; /* mac address from first pwe*/
bcm_mac_t pwe_mac2 = {0x00, 0x00, 0x00, 0x00, 0x01, 0x19}; /* mac address from second pwe*/
bcm_mac_t pwe_mac3 = {0x00, 0x00, 0x00, 0x00, 0x01, 0x1a}; /* mac address from third pwe*/
bcm_mac_t vpn2_mac = {0x00, 0x00, 0x00, 0x00, 0x01, 0x12}; /* mac address of vpn 2 */
bcm_vpn_t vpn_id1 = 15; /* vpn */
bcm_vpn_t vpn_id2 = 16; /* vpn */
int fec1 = 0; /* fec 1*/
int fec2 = 0; /* fec 2*/
int fec3 = 0; /* fec 3*/
int fec4 = 0; /* fec 4*/
int in_tunnel_id = 0; /* in tunnel id */
int tunnel_id1 = 0; /* tunnel id 1*/
int tunnel_id2 = 0; /* tunnel id 2*/
int tunnel_id3 = 0; /* tunnel id 3*/
int tunnel_id4 = 0; /* tunnel id 2*/
int tunnel_id5 = 0; /* tunnel id 3*/
int arp_encap_id1 = 0; /* ARP/LL id 1*/
int arp_encap_id2 = 0; /* ARP/LL id 2*/
int arp_encap_id3 = 0; /* ARP/LL id 3*/
int arp_encap_id4 = 0; /* ARP/LL id 4*/
int arp_encap_id5 = 0; /* ARP/LL id 5*/
bcm_mpls_label_t pwe_label1 = 3000; /* pwe label 1*/
bcm_mpls_label_t egr_pwe_label1 = 4000; /* egress pwe label 1*/

bcm_gport_t mpls_port_id1 = 0x20000; /* mpls_port_id1*/
bcm_gport_t mpls_port_encap_id1 = 0; /* mpls_port_encap_id1*/
bcm_gport_t vport_id1 = 0; /* mpls_port_id1*/
bcm_mpls_label_t tunnel_label = 800; /* tunnel_label */
bcm_mpls_label_t egr_tunnel_label = 700; /* egr_tunnel_label */

int exp1 = 2; /* egress label exp1 */
int exp2 = 1; /* egress label exp2 */

int arp_ac_1tag_stat_oam_if_test = 0;

void mpls_tp_path_info_init(int unit,
                    int portx,
                    int porty
                    ) {
    mpls_tp_path_port_array[0] = port1 = portx;
    mpls_tp_path_port_array[1] = port2 = porty;
}

/* Configure properties for ports of the application */
int mpls_tp_path_configure_port_properties(int unit, int *port_array, int nof_ports){
    int rv = BCM_E_NONE;
    int i;
    bcm_pbmp_t pbmp;

    for (i=0; i< nof_ports; i++) {
        /* set VLAN domain to each port */
        rv = port__vlan_domain__set(unit, port_array[i], port_array[i]); /* 1 */  /* 2 */
        if (rv != BCM_E_NONE) {
            printf("Error, in port__vlan_domain__set, port=%d, \n", port_array[i]);
            return rv;
        }

        /*
         * Set Out-Port default properties
         */
        rv = out_port_set(unit, port_array[i]);
        if (rv != BCM_E_NONE)
        {
            printf("Error, out_port_set intf_out, port=%d, \n", port_array[i]);
            return rv;
        }

    }
    return rv;
}

/* Create attachment circuits  */
int mpls_tp_path_create_l2_interfaces(int unit){
    int rv = BCM_E_NONE;
    int flags = BCM_VLAN_PORT_CREATE_INGRESS_ONLY;

    /* Create a vlan port*/
    rv = l2__port_vlan__create(unit, flags,  port1, vpn_id2, &vport_id1, vlan1); /* 1 */  /* 2 */
    if (rv != BCM_E_NONE) {
        print rv;
        printf("Error, in l2__port_vlan__create\n");
        return rv;
    }
    printf("vlan gport created:0x%x\n", vport_id1);    

    if(is_device_or_above(unit, JERICHO2))
    {
        rv = bcm_vlan_gport_add(unit, vpn_id2, port1, 0);
        if (rv != BCM_E_NONE)
        {
            printf("Error, bcm_vlan_gport_add \n");
            return rv;
        }
    }

    rv = in_port_section_oam_intf_set(unit, port2);
    if (rv != BCM_E_NONE)
    {
        printf("Error, in_port_section_oam_intf_set \n");
        return rv;
    }

    if(is_device_or_above(unit, JERICHO2))
    {
        rv = bcm_vswitch_port_add(unit, vpn_id1, section_oam_in_gport);
        if (rv != BCM_E_NONE)
        {
            printf("Error, bcm_vswitch_port_add\n");
            return rv;
        }
    }
    return rv;
}

/* Create egress mpls entries (in the EEDB) */
int mpls_tp_path_create_egress_tunnels(int unit){
    int rv = BCM_E_NONE;
    mpls__egress_tunnel_utils_s mpls_tunnel_properties[5];
    int egress_label_flags;
    int tunnel_index = 0;
    qax_egress_label_custom_flags = 1;

    if(mpls_tp_path_flag_mode == 0) {
        egress_label_flags = BCM_MPLS_EGRESS_LABEL_TTL_SET|BCM_MPLS_EGRESS_LABEL_EXP_SET;
    } else if(mpls_tp_path_flag_mode == 1){
        egress_label_flags = BCM_MPLS_EGRESS_LABEL_TTL_COPY|BCM_MPLS_EGRESS_LABEL_EXP_SET;
    } else if(mpls_tp_path_flag_mode == 2){
        egress_label_flags = BCM_MPLS_EGRESS_LABEL_TTL_SET|BCM_MPLS_EGRESS_LABEL_EXP_COPY;
    } else if(mpls_tp_path_flag_mode == 3) {
        egress_label_flags = BCM_MPLS_EGRESS_LABEL_TTL_COPY|BCM_MPLS_EGRESS_LABEL_EXP_COPY;
    }

    /* Build an EEDB entry with two tunnels */
    mpls_tunnel_properties[tunnel_index].label_in = egr_tunnel_label;
    mpls_tunnel_properties[tunnel_index].egress_action = BCM_MPLS_EGRESS_ACTION_PUSH;
	mpls_tunnel_properties[tunnel_index].label_out = mpls_default_egress_label_value;
	mpls_tunnel_properties[tunnel_index].force_flags = 0;
	mpls_tunnel_properties[tunnel_index].flags = egress_label_flags;
    mpls_tunnel_properties[tunnel_index].with_exp = 1;
    mpls_tunnel_properties[tunnel_index].exp = 2;
    mpls_tunnel_properties[tunnel_index].ttl = 20;
    mpls_tunnel_properties[tunnel_index].ext_exp = 4;
    mpls_tunnel_properties[tunnel_index].ext_ttl = 20;
    mpls_tunnel_properties[tunnel_index].next_pointer_intf = arp_encap_id1;

	
    /* Create egress tunnel */
    rv  = mpls__create_tunnel_initiator__set(unit, &(mpls_tunnel_properties[tunnel_index])); /* 1 */
    if (rv != BCM_E_NONE) {
        print rv;
        printf("Error, in mpls__create_tunnel_initiator__set\n");
        return rv;
    }
    tunnel_id1 = mpls_tunnel_properties[tunnel_index].tunnel_id;
    tunnel_index++;
    printf("Tunnel ID created is 0x%x\n", tunnel_id1);
    return rv;
}

/* Configure L3information (router interfaces) */
int mpls_tp_path_create_l3_interfaces(int unit){
    int rv = BCM_E_NONE;
    create_l3_intf_s l3_intf[2];
    create_l3_egress_s l3_egress;

    l3_intf[0].my_lsb_mac = my_mac_lsb;
    l3_intf[0].my_global_mac = global_mac;
    l3_intf[0].rif = vpn_id1;
    l3_intf[0].vsi = vpn_id1;
    l3_intf[0].rpf_valid = 0;
    l3_intf[0].skip_mymac = 0;
	
    /* create rif */
    rv = l3__intf_rif__create(unit, &(l3_intf[0])); /* 1 */  /* 2 */
    if (rv != BCM_E_NONE) {
        print rv;
        printf("Error, in l3__intf_rif__create\n");
        return rv;
    }

    rv = BCM_E_NONE;
    return rv;
}

/* Configure fec entries */
int mpls_tp_path_create_fec_entries(int unit){
    int rv = BCM_E_NONE;
    create_l3_egress_s l3_egress[4];

    /* Set LL for egress tunnel */
    l3_egress[0].fec_id = 0;
    l3_egress[0].arp_encap_id = 0;
    l3_egress[0].out_gport = port2;
    l3_egress[0].vlan = vlan1; /* next hop vlan*/
    l3_egress[0].out_tunnel_or_rif = tunnel_id1; /* tunnel */
    l3_egress[0].next_hop_mac_addr = mpls_mac;
    l3_egress[0].failover_id = 0;
    l3_egress[0].failover_if_id = 0;
    rv = l3__egress__create(unit, &(l3_egress[0])); /* 1 */
    if (rv != BCM_E_NONE) {
        print rv;
        printf("Error, in l3__egress__create\n");
        return rv;
    }
	arp_encap_id1 = l3_egress[0].arp_encap_id;
    printf("ARP encap ID1 is 0x%x\n", arp_encap_id1);
    return rv;
}

/* Configure fec entries
 * ARP_ENCAP_TYPE:ETPS_ARP_AC_1TAG_STAT
*/
int mpls_tp_path_create_fec_entries_1(int unit){
    int rv = BCM_E_NONE;
    create_l3_egress_s l3_egress[4];

    /* Set LL for egress tunnel */
    l3_egress[0].fec_id = 0;
    l3_egress[0].arp_encap_id = 0;
    l3_egress[0].out_gport = port2;
    l3_egress[0].vlan = vlan1; /* next hop vlan*/
    l3_egress[0].out_tunnel_or_rif = tunnel_id1; /* tunnel */
    l3_egress[0].next_hop_mac_addr = mpls_mac;
    l3_egress[0].failover_id = 0;
    l3_egress[0].failover_if_id = 0;

    /*In JR2, FEC and ARP created sperately*/
    l3_egress[0].l3_flags2 |= (BCM_L3_FLAGS2_VLAN_TRANSLATION|BCM_L3_FLAGS2_EGRESS_STAT_ENABLE);
    rv = l3__egress_only_encap__create(unit, &l3_egress[0]);
    if (rv != BCM_E_NONE) {
        printf("Error, l3__egress_only_encap__create\n");
        return rc;
    }
    arp_encap_id1 = l3_egress[0].arp_encap_id;

    /*JR2, Set intf in FEC if it exists, otherwise arp_encap_id. But won't both unless intf is RIF. */
    if (BCM_L3_ITF_TYPE_IS_LIF(l3_egress[0].arp_encap_id) && BCM_L3_ITF_TYPE_IS_LIF(l3_egress[0].out_tunnel_or_rif)) {
        /** FEC can't carry two outlifs, if encap_id was created in above call, set it to 0 temporarily.*/
        l3_egress[0].arp_encap_id = 0;
    }
    l3_egress[0].l3_flags2 &= (~(BCM_L3_FLAGS2_VLAN_TRANSLATION|BCM_L3_FLAGS2_EGRESS_STAT_ENABLE));
    rv = l3__egress_only_fec__create(unit,  &l3_egress[0]);
    if (rv != BCM_E_NONE) {
        printf("Error, l3__egress_only_fec__create\n");
        return rv;
    }
    l3_egress[0].arp_encap_id = arp_encap_id1;

    printf("ARP encap ID1 is 0x%x\n", arp_encap_id1);
    return rv;
}

/* Configure a tunnel POP for MPLS encapsulated packets */
int mpls_tp_path_configure_tunnel_switch_pop(int unit, bcm_mpls_label_t label) {
    mpls__ingress_tunnel_utils_s switch_entry;
    int rv;
    int mpls_label_indexed_enable = soc_property_get(unit , "mpls_termination_label_index_enable",0);

    switch_entry.action = BCM_MPLS_SWITCH_ACTION_POP;
    switch_entry.label = label;
    if (mpls_label_indexed_enable) {
         int label_val = label;
         BCM_MPLS_INDEXED_LABEL_SET(switch_entry.label, label_val, 1);
    }
    if (static_in_tunnel_id != -1) {
        switch_entry.flags = BCM_MPLS_SWITCH_WITH_ID;
        switch_entry.tunnel_id = static_in_tunnel_id;
    }

    rv = mpls__add_switch_entry(unit, &switch_entry); /* 2 */
    if(rv != BCM_E_NONE) {
        printf("Error, in bcm_mpls_tunnel_switch_create,\n");
        return rv;
    }

    printf("in lif is: %d\n",switch_entry.tunnel_id);

    in_tunnel_id = switch_entry.tunnel_id;

    return rv;
}

/* Configure pwe entries */
int mpls_tp_path_create_pwe_entries(int unit){
    int rv = BCM_E_NONE;
    mpls_port_utils_s mpls_port_properties[3];
    bcm_if_t pwe_encap_id;


    /* Create regular pwe entry (one pwe label, no mpls label in second half entry) */
    mpls_port_properties[0].ingress_pwe_label = pwe_label1;
    mpls_port_properties[0].egress_pwe_label = egr_pwe_label1;
	mpls_port_properties[0].egress_label_flags = 0;
    mpls_port_properties[0].egress_mpls_tunnel_id = tunnel_id1;
    mpls_port_properties[0].vpn = vpn_id2;
    mpls_port_properties[0].port = port2;
    if(is_device_or_above(unit, JERICHO2))
    {
        mpls_port_properties[0].flags = BCM_MPLS_PORT_WITH_ID;
        BCM_GPORT_SUB_TYPE_LIF_SET(mpls_port_properties[0].mpls_port_id, 0, mpls_port_id1);
        BCM_GPORT_MPLS_PORT_ID_SET(mpls_port_properties[0].mpls_port_id, mpls_port_properties[0].mpls_port_id);
    }
    rv = mpls_port__mp_create_ingress_egress_mpls_port(unit, &(mpls_port_properties[0])); /* 1 */
    if (rv != BCM_E_NONE) {
        printf("Error, in mpls_port__mp_create_ingress_egress_mpls_port\n");
        return rv;
    }

    mpls_port_id1 = mpls_port_properties[0].mpls_port_id;
    mpls_port_encap_id1 = mpls_port_properties[0].encap_id;

    return rv;
}

/* Create MACT entries*/
int mpls_tp_path_create_l2_forwarding(int unit){
    int rv = BCM_E_NONE;
    rv = l2__mact_entry_create(unit, pwe_mac1, vpn_id2, mpls_port_id1); /* 1 */
    if (rv != BCM_E_NONE) {
        print rv;
        printf("Error, in l2__mact_entry_create\n");
        return rv;
    }


    return rv;
}


/* Main function for mpls tp path creation */
int mpls_tp_path_create(int unit, int port1, int port2){
    int rv = BCM_E_NONE;

	mpls_tp_path_info_init(unit, port1, port2);
	
    /* configure vpn */
    rv = mpls_port__vswitch_vpls_vpn_create__set(unit, vpn_id1); /* 1 */  /* 2 */
    if (rv != BCM_E_NONE) {
        printf("Error, in mpls_port__vswitch_vpls_vpn_create__set\n");
        return rv;
    }
    
    /* configure vpn */
    rv = mpls_port__vswitch_vpls_vpn_create__set(unit, vpn_id2); /* 1 */  /* 2 */
    if (rv != BCM_E_NONE) {
        printf("Error, in mpls_port__vswitch_vpls_vpn_create__set\n");
        return rv;
    }

    /* Configure port properties for this application */
    rv = mpls_tp_path_configure_port_properties(unit, mpls_tp_path_port_array ,2); /* 1 */  /* 2 */
    if (rv != BCM_E_NONE) {
        print rv;
        printf("Error, in mpls_tp_path_configure_port_properties\n");
        return rv;
    }   
    
    /* Configure L2 information */
    rv = mpls_tp_path_create_l2_interfaces(unit);  /* 1 */  /* 2 */
    if (rv != BCM_E_NONE) {
        print rv;
        printf("Error, in mpls_tp_path_create_l2_interfaces\n");
        return rv;
    }

    /* Configure L3 information (router interfaces) */
    rv = mpls_tp_path_create_l3_interfaces(unit);   /* 1 */  /* 2 */
    if (rv != BCM_E_NONE) {
        print rv;
        printf("Error, in mpls_tp_path_create_l3_interfaces\n");
        return rv;
    }

    /* Configure mpls entries */
    rv = mpls_tp_path_create_egress_tunnels(unit); /* 1 */  /* 2 */
    if (rv != BCM_E_NONE) {
        print rv;
        printf("Error, in mpls_tp_path_create_egress_tunnels\n");
        return rv;
    }

    /* Configure L3 information (router interfaces) */
    if(arp_ac_1tag_stat_oam_if_test){
        rv = mpls_tp_path_create_fec_entries_1(unit);
    } else {
        rv = mpls_tp_path_create_fec_entries(unit);
    }

    if (rv != BCM_E_NONE) {
        print rv;
        printf("Error, in mpls_tp_path_create_fec_entries\n");
        return rv;
    }

    /* Configure tunnel switch entry */
    rv = mpls_tp_path_configure_tunnel_switch_pop(unit, tunnel_label); /* 2 */
    if (rv != BCM_E_NONE) {
        print rv;
        printf("Error, in mpls_tp_path_configure_tunnel_switch_pop\n");
        return rv;
    }

    /* Configure pwe entries */
    rv = mpls_tp_path_create_pwe_entries(unit); /* 1 */  /* 2 */
    if (rv != BCM_E_NONE) {
        print rv;
        printf("Error, in mpls_tp_path_create_pwe_entries\n");
        return rv;
    }

    /* Create l2 forwarding entries */
    rv = mpls_tp_path_create_l2_forwarding(unit);  /* 1 */  /* 2 */
    if (rv != BCM_E_NONE) {
        print rv;
        printf("Error, in mpls_tp_path_create_l2_forwarding\n");
        return rv;
    }

    return rv;
}
/*Currently using this on QUX for UP MEP packet trap by Section OAM verification is having forwarding issue*/
/* Function to set-up MPLS-TP path and creating accelarated Section OAM endpoint */
int oam_run_with_defaults_mpls_tp_section(int unit, int port1, int port2){
    int rv = BCM_E_NONE;
    int lm_counter_base_id;
    uint64 arg;
	bcm_gport_t out_gport = 0;
    bcm_oam_mpls_tp_channel_type_t  channel_type;
    bcm_oam_group_info_t group_info_short_ma;
    uint8 short_name[BCM_OAM_GROUP_NAME_LENGTH] = { 1, 3, 2, 0xab, 0xcd };
    bcm_oam_endpoint_info_t mep_not_acc_info;
    bcm_oam_endpoint_info_t rmep_info;

    rv = mpls_tp_path_create(unit, port1, port2);
    if (rv != BCM_E_NONE) {
        print rv;
        printf("Error, in mpls_tp_path_create\n");
        return rv;
    }
    printf("Done with MPLS TP path creation\n");

    if (arp_ac_1tag_stat_oam_if_test) {

       /*
        * Set Counter Range for PCP based counters.
        * As default all counter range defined as non-PCP.
        * To use PCP based counters, limited counter range
        * should be set.
        * To set all counters for PCP,
        * range_min = range_max = 0 should be used.
        */

        /* Config Range to : Min=0, Max=0 . That allows the counters to be set */
          COMPILER_64_ZERO(arg);
          BCM_IF_ERROR_RETURN_MSG(bcm_oam_control_set(unit, bcmOamControlLmPcpCounterRangeMin, arg), "");
          BCM_IF_ERROR_RETURN_MSG(bcm_oam_control_set(unit, bcmOamControlLmPcpCounterRangeMax, arg), "");
    }

    if(is_device_or_above(unit, JERICHO2))
    {
        rv = set_counter_resource(unit, port1, 0, 1, &lm_counter_base_id);
        BCM_IF_ERROR_RETURN(rv);
    }
    else
    {
        rv = set_counter_source_and_engines(unit, &lm_counter_base_id, port1);
        BCM_IF_ERROR_RETURN(rv);
    }

    rv = register_events(unit);
    BCM_IF_ERROR_RETURN(rv);
    
    channel_type = bcmOamMplsTpChannelPweonoam;
    rv = bcm_oam_mpls_tp_channel_type_tx_set(unit, channel_type, 0x8902);
    BCM_IF_ERROR_RETURN(rv);

    channel_type = bcmOamMplsTpChannelY1731;
    rv = bcm_oam_mpls_tp_channel_type_tx_set(unit, channel_type, 0x8902);
    BCM_IF_ERROR_RETURN(rv);

    bcm_oam_group_info_t_init(&group_info_short_ma);
    sal_memcpy(group_info_short_ma.name, short_name, BCM_OAM_GROUP_NAME_LENGTH);
    rv = bcm_oam_group_create(unit, &group_info_short_ma);
    BCM_IF_ERROR_RETURN(rv);

    bcm_oam_endpoint_info_t_init(&mep_acc_info);
    mep_acc_info.type = bcmOAMEndpointTypeBhhSection;
    /** Profile */
    if(is_device_or_above(unit, JERICHO2))
    {
       BCM_GPORT_TUNNEL_ID_SET(out_gport, arp_encap_id1);
       rv = config_oam_section_profile(unit, section_oam_in_gport, out_gport, oam_is_dual_ended_lm, &mep_acc_info);
       if (rv != BCM_E_NONE)
       {
           printf("Error no %d, in config_oam_section_profile.\n", rv);
           return rv;
       }
    
    }

    /*TX*/
    mep_acc_info.group = group_info_short_ma.id;
    mep_acc_info.level = 5;
    BCM_GPORT_SYSTEM_PORT_ID_SET(mep_acc_info.tx_gport, port2);
    mep_acc_info.name = 456;
    mep_acc_info.ccm_period = 100;
    if(arp_ac_1tag_stat_oam_if_test) {
        mep_acc_info.lm_flags |= BCM_OAM_LM_PCP;
    }

    mep_acc_info.opcode_flags |= BCM_OAM_OPCODE_CCM_IN_HW;
    mep_acc_info.egress_label.label = 13;
    mep_acc_info.egress_label.ttl = 0xa;
    mep_acc_info.egress_label.exp = 1;

    /*RX*/
    mep_acc_info.gport = section_oam_in_gport;
	BCM_L3_ITF_LIF_TO_GPORT_TUNNEL(mep_acc_info.mpls_out_gport, arp_encap_id1);
	mep_acc_info.intf_id = arp_encap_id1;
    mep_acc_info.lm_counter_base_id = lm_counter_base_id;
    /*mep_acc_info.timestamp_format = bcmOAMTimestampFormatIEEE1588v1;*/

    printf("bcm_oam_endpoint_create mep_acc_info\n");
    rv = bcm_oam_endpoint_create(unit, &mep_acc_info);
    if (rv != BCM_E_NONE) {
        printf("(%s) \n",bcm_errmsg(rv));
        return rv;
    }
    printf("created MEP with id %d\n", mep_acc_info.id);
 
    bcm_oam_endpoint_info_t_init(&rmep_info);
    rmep_info.local_id = mep_acc_info.id;
    rmep_info.type = bcmOAMEndpointTypeBhhSection;
    rmep_info.ccm_period = 0;
    if(is_device_or_above(unit, JERICHO2) &&
       (*(dnxc_data_get(unit, "oam", "oamp",
       "rmep_db_non_zero_lifetime_units_limitation", NULL)))) {
        /** Needed to avoid limitation in JR2 A0 */
        rmep_info.ccm_period = BCM_OAM_ENDPOINT_CCM_PERIOD_10MS;
    }
    rmep_info.flags |= BCM_OAM_ENDPOINT_REMOTE;
    rmep_info.loc_clear_threshold = 1;
	rmep_info.name = 124;
    rv = bcm_oam_endpoint_create(unit, &rmep_info);
    if (rv != BCM_E_NONE) {
        printf("(%s) \n",bcm_errmsg(rv));
        return rv;
    }
    printf("created RMEP with id %d\n", rmep_info.id);

    /* Store endpoint info in global parameter.*/
    ep.gport =  mep_acc_info.gport;
    ep.id = mep_acc_info.id;
    ep.rmep_id = rmep_info.id;

    return rv;
}

