/* $Id: 
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2022 Broadcom Inc. All rights reserved. 
 *  
 * File: cint_rx_trap_icmp_redirect.c
 * Purpose: Simple example how to set icmp redirect to cpu.
 *
 * cint 
 * cint ../../../../src/examples/dnx/traps/cint_rx_trap_icmp_redirect.c
 *
 * Main Function:
 *      cint_rx_trap_icmp_redirect_main(unit);
 * Destroy Function:
 *      cint_rx_trap_icmp_redirect_cleanup(unit);
 *
 * Example Config:
 * Test Scenario - start
  cint ../../../../src/examples/dnx/traps/cint_rx_trap_icmp_redirect.c
  cint
  cint_rx_trap_icmp_redirect_main(0);
 * Test Scenario - end
 */

int cint_rx_trap_icmp_redirect_trap_id = -1;

 /**
 * \brief  
 *  Main function for bcmSwitchIcmpRedirectToCpu configuration
 * \par DIRECT INPUT: 
 *   \param [in] unit      -  Unit Id
 * \par INDIRECT INPUT: 
 *   * None
 * \par DIRECT OUTPUT: 
 *   int -  Error Type
 * \par INDIRECT OUTPUT: 
 *   * None
 * \remark 
 *   * None
 * \see
 *   * None
 */
int cint_rx_trap_icmp_redirect_main(
int unit,
int fwd_strength)
{
    bcm_rx_trap_config_t config;
    uint32 system_headers_mode = *(dnxc_data_get(unit,  "headers", "system_headers", "system_headers_mode", NULL));

    bcm_rx_trap_config_t_init(&config);
    config.trap_strength = fwd_strength;
    config.flags = BCM_RX_TRAP_UPDATE_DEST;
    config.dest_port = BCM_GPORT_LOCAL_CPU;

    if (system_headers_mode == 0)
    {
        BCM_IF_ERROR_RETURN_MSG(cint_utils_rx_trap_create_and_set(unit, 0, bcmRxTrapIcmpRedirect, &config, &cint_rx_trap_icmp_redirect_trap_id), "");
    }
    else
    {
        BCM_IF_ERROR_RETURN_MSG(bcm_rx_trap_type_get(unit, 0, bcmRxTrapIcmpRedirect, &cint_rx_trap_icmp_redirect_trap_id), "");
    }

    BCM_IF_ERROR_RETURN_MSG(bcm_rx_trap_set(unit, cint_rx_trap_icmp_redirect_trap_id, config), "");

    return BCM_E_NONE;
}

/**
* \brief  
*  Cleanup of cint_rx_trap_icmp_redirect_main configuration
* \par DIRECT INPUT: 
*   \param [in] unit      -  Unit Id
* \par INDIRECT INPUT: 
*   * None
* \par DIRECT OUTPUT: 
*   int -  Error Type
* \par INDIRECT OUTPUT: 
*   * None
* \remark 
*   * None
* \see
*   * None
*/
int cint_rx_trap_icmp_redirect_destroy(
int unit)
{
    BCM_IF_ERROR_RETURN_MSG(bcm_rx_trap_type_destroy(unit, cint_rx_trap_icmp_redirect_trap_id), "");

    return BCM_E_NONE;
}

/**
 * Configuration of route with InLIF=OutLIF, packet will be routed from in_port to out-port
 * packet to send:
 *  - in port = in_port
 *  - DA = {0x00, 0x0c, 0x00, 0x02, 0x00, 0x00}
 *  - DIP = 0x7fffff00-0x7fffff0f (192.255.255.0-192.255.255.15)
 */
int cint_rx_trap_route_with_inlif_equals_outlif(
    int unit,
    int in_port,
    int out_port)
{
    int host_format = 0;
    int is_arp_plus_ac = 0;
    int do_raw = 0;
    int kaps_result = 0xB006;    
    int intf_in = 100;          /* Incoming packet ETH-RIF */
    int intf_out = 100;         /* Outgoing packet ETH-RIF */
    /*
     * Set 'fec' as on the coresponding test. See, for example,
     * AT_Dnx_Cint_l3_ip_route_basic_raw
     */
    int fec;
    int vrf = 1;
    int encap_id = 8193;         /* ARP-Link-layer (needs to be higher than 8192 for Jer Plus) */
    bcm_mac_t intf_in_mac_address = { 0x00, 0x0c, 0x00, 0x02, 0x00, 0x00 };     /* my-MAC */
    bcm_mac_t intf_out_mac_address = { 0x00, 0x0c, 0x00, 0x02, 0x00, 0x01 };    /* my-MAC */
    bcm_mac_t arp_next_hop_mac = { 0x00, 0x00, 0x00, 0x00, 0xcd, 0x1d };        /* next_hop_mac */
    bcm_gport_t gport;
    uint32 route = 0x7fffff00;
    uint32 host = 0x7fffff02;
    uint32 mask = 0xfffffff0;
    l3_ingress_intf ingress_rif;
    l3_ingress_intf_init(&ingress_rif);
    uint32 flags2 = 0;
    int vlan = 100;
    /*
     * used to pass fec in host.l3a_intf
     */
    int encoded_fec;

    char *err_proc_name;
    char *proc_name;

    proc_name = "cint_rx_trap_route_with_inlif_equals_outlif";
    printf("%s(): Enter. in_port %d out_port %d do_raw %d host_format %d kaps_result 0x%08X\r\n",proc_name, in_port, out_port, do_raw, host_format,kaps_result);

    BCM_IF_ERROR_RETURN_MSG(get_first_fec_in_range_which_not_in_ecmp_range(unit, 0, 0, &kaps_result), "");

    /*
     * encap id for must be > 2k
     */
    encap_id = 0x1384;

    /*
     * MyMac assignment
     */
    intf_out_mac_address[0] = 0x00;
    intf_out_mac_address[1] = 0x12;
    intf_out_mac_address[2] = 0x34;
    intf_out_mac_address[3] = 0x56;
    intf_out_mac_address[4] = 0x78;
    intf_out_mac_address[5] = 0x9a;

    fec = kaps_result;

    /*
     * 1. Set In-Port to In ETh-RIF
     */
    BCM_IF_ERROR_RETURN_MSG(in_port_intf_set(unit, in_port, intf_in), "");

    /*
     * 2. Set Out-Port default properties, in case of ARP+AC no need
     */
    BCM_IF_ERROR_RETURN_MSG(out_port_set(unit, out_port), "");
    
    /*
     * 3. Create ETH-RIF and set its properties 
     */
    BCM_IF_ERROR_RETURN_MSG(intf_eth_rif_create(unit, intf_in, intf_in_mac_address), "");
    
    /*
     * 4. Set Incoming ETH-RIF properties 
     */
    ingress_rif.vrf = vrf;
    ingress_rif.intf_id = intf_in;
    BCM_IF_ERROR_RETURN_MSG(intf_ingress_rif_set(unit, &ingress_rif), "");

    /*
     * 5. Create ARP and set its properties
     */
    if (is_arp_plus_ac)
    {
        flags2 |= BCM_L3_FLAGS2_VLAN_TRANSLATION;
    }
    printf("%s(): Going to call l3__egress_only_encap__create_inner() with encap_id 0x%08X, flags2 0x%08X\n",
                proc_name, encap_id, flags2);
    BCM_IF_ERROR_RETURN_MSG(l3__egress_only_encap__create_inner(unit, 0, &encap_id, arp_next_hop_mac, vlan, 0, flags2), "");

    if (is_arp_plus_ac)
    {
        /*
         * for arp+ac, bcm_vlan_port_translation_set is the API which sets the AC part in
         * the ARP+AC entry in EEDB
         */
        printf("%s(): We have arp_plus_ac. Call bcm_vlan_port_translation_set()\n",proc_name);
        bcm_vlan_port_translation_t lif_translation_info;
        bcm_vlan_port_translation_t_init(&lif_translation_info);
        int arp_outlif;
        int vlan_edit_profile = 7;
        bcm_gport_t arp_ac_gport;

        arp_outlif = BCM_L3_ITF_VAL_GET(encap_id);
        BCM_GPORT_SUB_TYPE_L3_VLAN_TRANSLATION_SET(arp_ac_gport, arp_outlif);
        BCM_GPORT_VLAN_PORT_ID_SET(arp_ac_gport, arp_ac_gport);

        /*
        * Perform vlan editing:
        */
        BCM_IF_ERROR_RETURN_MSG(vlan_translate_ive_eve_translation_set(unit, arp_ac_gport,         /* lif  */
                                                          0x9100,               /* outer_tpid */
                                                          0x8100,               /* inner_tpid */
                                                          bcmVlanActionArpVlanTranslateAdd,  /* outer_action */
                                                          bcmVlanActionNone,                 /* inner_action */
                                                          vlan,                 /* new_outer_vid */
                                                          2*vlan,               /* new_inner_vid */
                                                          vlan_edit_profile,    /* vlan_edit_profile */
                                                          0,                    /* tag_format - must be untag! */
                                                          FALSE                 /* is_ive */
                                                          ), "");

        /*
        * Check that the VLAN Edit info was set correctly:
        */
        bcm_vlan_port_translation_t lif_translation_info_get;
        lif_translation_info_get.flags = BCM_VLAN_ACTION_SET_EGRESS;
        lif_translation_info_get.gport = arp_ac_gport;
        
        lif_translation_info_get.new_outer_vlan = 0xFFFFFFFF;
        lif_translation_info_get.new_inner_vlan = 0xFFFFFFFF;
        lif_translation_info_get.vlan_edit_class_id = 0xFFFFFFFF;

        BCM_IF_ERROR_RETURN_MSG(bcm_vlan_port_translation_get(unit, &lif_translation_info_get), "");

        if (lif_translation_info_get.new_outer_vlan != vlan) {
            printf("%s(): Error, get.new_outer_vlan = %d  set.new_outer_vlan = %d\n", proc_name, 
                   lif_translation_info_get.new_outer_vlan, vlan);

            return BCM_E_INTERNAL;
        }

        if (lif_translation_info_get.new_inner_vlan != 2*vlan) {
            printf("%s(): Error, get.new_inner_vlan = %d  set.new_inner_vlan = %d\n", proc_name, 
                   lif_translation_info_get.new_inner_vlan, 2*vlan);

            return BCM_E_INTERNAL;
        }

        if (lif_translation_info_get.vlan_edit_class_id != vlan_edit_profile) {
            printf("%s(): Error, get.vlan_edit_class_id = %d  set.vlan_edit_class_id = %d\n", proc_name, 
                   lif_translation_info_get.vlan_edit_class_id, vlan_edit_profile);

            return BCM_E_INTERNAL;
        }
    }

    /*
     * 6. Create FEC and set its properties
     */
    int fec_flags2 = 0;
    if(*dnxc_data_get(unit, "l3", "feature", "separate_fwd_rpf_dbs", NULL))
    {
        fec_flags2 |= BCM_L3_FLAGS2_FWD_ONLY;
    }

    printf("%s(): host_format %d. Create main FEC and set its properties.\r\n",proc_name, host_format);
    BCM_GPORT_LOCAL_SET(gport, out_port);

    BCM_IF_ERROR_RETURN_MSG(l3__egress_only_fec__create_inner(unit, fec, intf_out, encap_id, gport, 0, fec_flags2, 0, 0, &encoded_fec), "");
    printf("%s(): fec 0x%08X encoded_fec 0x%08X.\r\n",proc_name, fec, encoded_fec);

    /*
     * 7. Add Route entry
     */
    printf("%s(): Add route entry. Raw %d. route 0x%08X mask 0x%08X vrf %d fec 0x%08X. \n",proc_name, do_raw, route, mask, vrf, fec);
    if (do_raw != 0)
    {
        BCM_IF_ERROR_RETURN_MSG(add_route_ipv4_raw(unit, route, mask, vrf, fec), "");
        err_proc_name = "add_route_ipv4_raw";
    }
    else
    {
        BCM_IF_ERROR_RETURN_MSG(add_route_ipv4(unit, route, mask, vrf, fec), "");
        err_proc_name = "add_route_ipv4";
    }
    
    /*
     * 8. Add host entry
     */
    int _l3_itf;
    BCM_L3_ITF_SET(&_l3_itf, BCM_L3_ITF_TYPE_FEC, fec);
    BCM_GPORT_LOCAL_SET(gport, out_port);
    if (host_format == 1)
    {
        BCM_IF_ERROR_RETURN_MSG(add_host_ipv4(unit, host, vrf, _l3_itf, intf_out, 0), "");
    }
    else if (host_format == 2)
    {
        BCM_IF_ERROR_RETURN_MSG(add_host_ipv4(unit, host, vrf, intf_out, encap_id /* arp id */ , gport), "");
    }
    else
    {
        BCM_IF_ERROR_RETURN_MSG(add_host_ipv4(unit, host, vrf, _l3_itf, 0, 0), "");
    }

    printf("%s(): Exit\r\n",proc_name);
    return BCM_E_NONE;
}

