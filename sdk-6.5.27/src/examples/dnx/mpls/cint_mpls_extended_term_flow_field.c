/*
 * 
 This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 
 Copyright 2007-2022 Broadcom Inc. All rights reserved. File: cint_mpls_5_label_term_field.c  
 */

/*
 * The below CINT demonstrates identify all LSR missing packets which doesn't come from rcy port,
 * and recycle these packets to 2nd pass.
 *
 */

bcm_field_group_t mpls_extended_term_fg_id = 0;
 /**
  * \brief
  *
  *  Setup ingress PMF rules to identify all LSR missing packets not come from rcy port and trap to recycle port.
  *
  * \param [in] unit     - The unit number.
  * \param [in] in_port  - in port.
  * \param [in] rcy_port - recycle port
  * \param [in] rcy_extended_term_encap_id - encap id
  *
  * \return
  *  int - Error Type, in sense of bcm_error_t
  *
  */
 int mpls_field_extended_term_flow_set_ipmf1(int unit, 
       int in_port, 
       int rcy_port, 
       bcm_if_t rcy_extended_term_encap_id)
 {
    char error_msg[200]={0,};
    bcm_field_group_info_t fg_info;
    bcm_field_group_attach_info_t attach_info;
    int nof_quals = 2;
    int nof_actions = 1;
    int ii = 0;
    int context_id;
    void *dest_char;
    bcm_field_entry_info_t entry_info;
    bcm_field_entry_t entry_handle;
    int mpls_unknown_label_trap_id = 0xc;
    uint32 normal_port_profile = 2;
    bcm_gport_t gport_trap = 0;
    int new_trap_id = 0;
    bcm_rx_trap_config_t config;
    int trap_strength = 6;
    uint32 ibch1_supported = *dnxc_data_get(unit, "headers", "system_headers", "system_headers_ibch1_supported", NULL);

    /* Set ipmf_port_profile to differ general port(2) and rcycle port(0) */
    BCM_IF_ERROR_RETURN_MSG(bcm_port_class_set(unit, in_port, bcmPortClassFieldIngressPMF1PacketProcessingPort, normal_port_profile),
        "with type == bcmPortClassFieldIngressPMF1PacketProcessingPort");

    if (!ibch1_supported)
    {
        /** Configure RCH port of Extended Termination type */
        snprintf(error_msg, sizeof(error_msg), "for rch_port %d", rcy_port);
        BCM_IF_ERROR_RETURN_MSG(bcm_port_control_set(unit, rcy_port, bcmPortControlRecycleApp, bcmPortControlRecycleAppExtendedTerm), error_msg);
    }

    context_id = *dnxc_data_get(unit, "field", "context", "default_context", NULL);
    bcm_field_group_info_t_init(&fg_info);
    fg_info.fg_type = bcmFieldGroupTypeTcam;
    fg_info.stage = bcmFieldStageIngressPMF1;
    fg_info.nof_quals = nof_quals;
    fg_info.qual_types[0] = bcmFieldQualifyRxTrapCode;
    fg_info.qual_types[1] = bcmFieldQualifyPortClassPacketProcessing;
    fg_info.nof_actions = nof_actions;
    fg_info.action_types[0] = bcmFieldActionTrap;

    if (mpls_extended_term_fg_id == 0)
    {
        dest_char = &(fg_info.name[0]);
        sal_strncpy_s(dest_char, "MPLS_LABEL_FWD_MISS", sizeof(fg_info.name));
        BCM_IF_ERROR_RETURN_MSG(bcm_field_group_add(unit, 0, &fg_info, &mpls_extended_term_fg_id), "");

        bcm_field_group_attach_info_t_init(&attach_info);

        attach_info.key_info.nof_quals = fg_info.nof_quals;
        attach_info.payload_info.nof_actions = fg_info.nof_actions;

        for (ii = 0; ii < fg_info.nof_quals; ii++)
        {
            attach_info.key_info.qual_types[ii] = fg_info.qual_types[ii];
        }
        for (ii = 0; ii < fg_info.nof_actions; ii++)
        {
            attach_info.payload_info.action_types[ii] = fg_info.action_types[ii];
            attach_info.payload_info.action_info[ii].priority = BCM_FIELD_ACTION_PRIORITY(0, (ii + 1));
        }

        attach_info.key_info.qual_info[0].input_type = bcmFieldInputTypeMetaData;
        attach_info.key_info.qual_info[1].input_type = bcmFieldInputTypeMetaData;
        BCM_IF_ERROR_RETURN_MSG(bcm_field_group_context_attach(unit, 0, mpls_extended_term_fg_id, context_id, &attach_info), "");
    }

    /*
     * Create a trap that new destination is rcy port and bring extended term encap to egress.
     */
    BCM_IF_ERROR_RETURN_MSG(bcm_rx_trap_type_create(unit, 0, bcmRxTrapUserDefine, &new_trap_id), "");

    bcm_rx_trap_config_t_init(&config);
    config.flags = BCM_RX_TRAP_UPDATE_DEST | BCM_RX_TRAP_UPDATE_ENCAP_ID;
    config.dest_port = rcy_port;
    config.trap_strength = 0;
    BCM_L3_ITF_LIF_TO_GPORT_TUNNEL(config.encap_id, rcy_extended_term_encap_id);
    BCM_IF_ERROR_RETURN_MSG(bcm_rx_trap_set(unit, new_trap_id, &config), "");     
    BCM_GPORT_TRAP_SET(gport_trap, new_trap_id, trap_strength, 0);

    /*
     * Qualify all LSR miss packets from normal port, 
     * Trap these packet to recycle port and stard term more label at 2nd pass.
     */
    bcm_field_entry_info_t_init(&entry_info);
    entry_info.nof_entry_actions = fg_info.nof_actions;
    entry_info.nof_entry_quals = fg_info.nof_quals;
    entry_info.entry_qual[0].type = bcmFieldQualifyRxTrapCode;
    entry_info.entry_qual[0].value[0] = mpls_unknown_label_trap_id;
    entry_info.entry_qual[0].mask[0] = 0x1FF;
    entry_info.entry_qual[1].type = bcmFieldQualifyPortClassPacketProcessing;
    entry_info.entry_qual[1].value[0] = normal_port_profile;
    entry_info.entry_qual[1].mask[0] = 0x7;
    entry_info.entry_action[0].type = bcmFieldActionTrap;
    entry_info.entry_action[0].value[0] = gport_trap;
    BCM_IF_ERROR_RETURN_MSG(bcm_field_entry_add(unit, 0, mpls_extended_term_fg_id, &entry_info, &entry_handle), "");

    return BCM_E_NONE;
 }
