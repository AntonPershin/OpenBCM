/* $Id: 
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2022 Broadcom Inc. All rights reserved. 
 *  
 * File: cint_rx_trap_erpp_trap_to_cpu.c
 * Purpose: Example for creating and setting an ERPP action profile which traps packet to CPU.
 *
 * cint ../../../../src/examples/dnx/traps/cint_rx_trap_erpp_trap_to_cpu.c
 *
 * Main Function:
 *      cint_rx_trap_erpp_trap_to_cpu_main(unit, rcy_port, &erpp_trap_id, ipmf1_context_id);
 * Destroy Function:
 *      cint_rx_trap_erpp_trap_to_cpu_destroy(unit, erpp_trap_id);
 *
 * Additional Notes: 
 * Since the destination of the packet cannot be changed at ERPP we recycle the packet
 * and configure an ingress trap to redirect the packet to CPU.
 * In the cint we use a preconfigured trap bcmRxTrapDfltRedirectToCpuPacket, 
 * to configure additional actions for ingress trap please create a user-define ingress trap bcmRxTrapUserDefine.
 *
 * To configure $rcy_port in specific $core,add this line with desired values to relevant config.bc, file:
 * ucode_port_$rcy_port=RCY0.0:core_$core.$rcy_port
 *
 * Example Config:
 * Test Scenario - start
  cint ../../../../src/examples/dnx/traps/cint_rx_trap_erpp_trap_to_cpu.c
  cint
  int erpp_trap_id;
  cint_rx_trap_erpp_trap_to_cpu_main(0, rcy_port, &erpp_trap_id, ipmf1_context_id);
 * Test Scenario - end
 */

bcm_field_group_t cint_in_port_qaul_fg_id = 0;
bcm_field_entry_t cint_ent_id;
/**
* \brief
*  Configures the written above
* \param [in] unit        -  Device id
* \param [in] in_port     -  in pp_port id
* \param [in] ipmf1_context_id - The context used in iPMF1
* \return
*   int - Error Type
* \remark
*   * None
* \see
*   * None
*/
int cint_field_in_port_qual_trap_action_create(int unit, int in_port, bcm_field_context_t ipmf1_context_id)
{
    bcm_field_group_info_t fg_info;
    bcm_field_group_attach_info_t attach_info;
    bcm_field_context_info_t context_info;
    bcm_field_entry_info_t ent_info;
    bcm_field_action_info_t action_info;
    void *dest_char;
    int trap_id;
    bcm_gport_t trap_gport;


    /*
     * Create and attach TCAM group in iPMF1
     */
    bcm_field_group_info_t_init(&fg_info);
    fg_info.fg_type = bcmFieldGroupTypeTcam;
    fg_info.stage = bcmFieldStageIngressPMF1;
    fg_info.nof_quals = 1;
    fg_info.qual_types[0] = bcmFieldQualifyInPort;
    fg_info.nof_actions = 1;
    fg_info.action_types[0] = bcmFieldActionTrap;

    printf("Creating first group\n");
    dest_char = &(fg_info.name[0]);
    sal_strncpy_s(dest_char, "In_port_qual", sizeof(fg_info.name));
    BCM_IF_ERROR_RETURN_MSG(bcm_field_group_add(unit, 0, &fg_info, &cint_in_port_qaul_fg_id), "");

    /*
     * Attach the FG to context
     */
    bcm_field_group_attach_info_t_init(&attach_info);

    attach_info.key_info.nof_quals = fg_info.nof_quals;
    attach_info.key_info.qual_types[0] = fg_info.qual_types[0];
    attach_info.payload_info.nof_actions = fg_info.nof_actions;
    attach_info.payload_info.action_types[0] = fg_info.action_types[0];
    attach_info.key_info.qual_info[0].input_type = bcmFieldInputTypeMetaData;
    attach_info.key_info.qual_info[0].input_arg = 0;
    attach_info.key_info.qual_info[0].offset = 0;

    printf("Attaching field group\n");
    BCM_IF_ERROR_RETURN_MSG(bcm_field_group_context_attach(unit, 0, cint_in_port_qaul_fg_id, ipmf1_context_id, &attach_info), "");

    bcm_field_entry_info_t_init(&ent_info);
    ent_info.priority = 1;
    ent_info.nof_entry_quals = fg_info.nof_quals;
    ent_info.entry_qual[0].type = fg_info.qual_types[0];
    ent_info.entry_qual[0].value[0] = in_port;
    ent_info.entry_qual[0].mask[0] = 0x1ff;

	bcm_rx_trap_type_get(unit, 0, bcmRxTrapDfltRedirectToCpuPacket, &trap_id);
    BCM_GPORT_TRAP_SET(trap_gport,trap_id,15,0);
    ent_info.nof_entry_actions = fg_info.nof_actions;
    ent_info.entry_action[0].type = fg_info.action_types[0];
    ent_info.entry_action[0].value[0] = trap_gport;

    printf("Adding Entry\n");
    BCM_IF_ERROR_RETURN_MSG(bcm_field_entry_add(unit, 0, cint_in_port_qaul_fg_id, &ent_info, &cint_ent_id), "");
    return BCM_E_NONE;
}

 /**
 * \brief  
 *  Main function for configuring ERPP trap id to redirect packet to CPU
 * \par DIRECT INPUT: 
 *   \param [in] unit      -  Unit Id
 *   \param [in] rcy_port  -  Recycle port
 *   \param [in] erpp_trap_id_p - erpp trap id
 *   \param [in] ipmf1_context_id - The context used in iPMF1
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
int cint_rx_trap_erpp_trap_to_cpu_main(
    int unit,
    int rcy_port,
    int* erpp_trap_id_p,
    bcm_field_context_t ipmf1_context_id)
{
    int ingress_trap_id;
    bcm_rx_trap_config_t trap_config;

    BCM_IF_ERROR_RETURN_MSG(bcm_rx_trap_type_create(unit, 0, bcmRxTrapEgUserDefine, erpp_trap_id_p), "");

    bcm_rx_trap_config_t_init(&trap_config);
    trap_config.flags = BCM_RX_TRAP_UPDATE_DEST;
    trap_config.dest_port = rcy_port;

    BCM_IF_ERROR_RETURN_MSG(bcm_rx_trap_set(unit, *erpp_trap_id_p, &trap_config), "");

    BCM_IF_ERROR_RETURN_MSG(cint_field_in_port_qual_trap_action_create(unit, rcy_port, ipmf1_context_id), "");

    return BCM_E_NONE;    
}

/**
* \brief
*  Destroy all configuration done
* \param [in] unit        -  Device id
* \param [in] ipmf1_context_id - The context used in iPMF1
* \return
*   int - Error Type
* \remark
*   * None
* \see
*   * None
*/
int cint_field_in_port_qual_action_trap_destroy(int unit, bcm_field_context_t ipmf1_context_id)
{
    char error_msg[200]={0,};

    /* Delete entry from Field group */
    snprintf(error_msg, sizeof(error_msg), "entry %d from fg %d", cint_ent_id, cint_in_port_qaul_fg_id);
    BCM_IF_ERROR_RETURN_MSG(bcm_field_entry_delete(unit, cint_in_port_qaul_fg_id, NULL, cint_ent_id), error_msg);
    /* Detach the IPMF1 FG from its context */
    snprintf(error_msg, sizeof(error_msg), "fg %d from context %d", cint_in_port_qaul_fg_id, ipmf1_context_id);
    BCM_IF_ERROR_RETURN_MSG(bcm_field_group_context_detach(unit, cint_in_port_qaul_fg_id, ipmf1_context_id), error_msg);

    /* Delete  FG */
    snprintf(error_msg, sizeof(error_msg), "fg %d", cint_in_port_qaul_fg_id);
    BCM_IF_ERROR_RETURN_MSG(bcm_field_group_delete(unit, cint_in_port_qaul_fg_id), error_msg);

    return BCM_E_NONE;
}

/**
* \brief  
*  Destroy erpp trap
* \par DIRECT INPUT: 
*   \param [in] unit      -  Unit Id
*   \param [in] erpp_trap_id - ERPP trap id
*   \param [in] ipmf1_context_id - The context used in iPMF1
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
int cint_rx_trap_erpp_trap_to_cpu_destroy(
    int unit,
    int erpp_trap_id,
    bcm_field_context_t ipmf1_context_id)
{

    BCM_IF_ERROR_RETURN_MSG(bcm_rx_trap_type_destroy(unit, erpp_trap_id), "destroying erpp trap");
    
    BCM_IF_ERROR_RETURN_MSG(cint_field_in_port_qual_action_trap_destroy(unit, ipmf1_context_id), "");

    return BCM_E_NONE;
}
