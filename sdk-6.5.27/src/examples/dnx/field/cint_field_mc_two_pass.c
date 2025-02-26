/*
 *
 *  Initializes the stacking programmable mode application.
 *
 * Configuration:
 *
 * Test Scenario - start
  cint ../../../../src/examples/dnx/field/cint_field_mc_two_pass.c
  cint
  int unit = 0;
  field_mc_two_pass_main(unit);
  exit;
 * Test Scenario - end
 *
 *Note:
 *This is PMF part of Scheduled Fabric+Egress MC(option #1) 
 * in $SDK/src/examples/sand/cint_sch_fab_eg_mc.c

 */

/* *INDENT-OFF* */

/** Number of Actions (used as array size) */
int FTMH_NOF_IPMF2_ACTIONS          = 1;
/** Number of Data Qualifiers needed (used as array size) */
int FTMH_NOF_IPMF2_QUALIFIERS       = 1;
/** Number of FEMs in IPMF2 (used as array size) */
int FTMH_NOF_IPMF2_FEMS             = 0;
/** Number of Field Groups needed (used as array size) */
int FTMH_NOF_FG                     = 1;


/** Take 19 bits LSB as MC-ID from orignal FTMH Header[67:49] (19b) */
int MC_ID_or_OutLIF_QUAL_OFFSET     = 49;


/** Length of mcid_or_outlif Qualifier from orignal FTMH Header[67:49] (19b) */
int MC_ID_or_OutLIF_QUAL_LENGTH     = 19;



/** Length of user defined MC ID DESTINATION action (19b) */
int MC_ID_DST_ACTION_LENGTH         = 19;



bcm_field_presel_entry_id_t mc_ipmf1_presel_entry_id;


/**
 * Structure, which contains information,
 * for creating of user actions and predefined one.
 */
struct field_ftmh_qual_info_t {
    char * name;
    bcm_field_qualify_t qual_id;
    uint32 qual_length;
    bcm_field_qualify_attach_info_t qual_attach_info;
};

/**
 * Structure, which contains need information,
 * for creating of user actions and predefined one.
 */
struct field_ftmh_action_info_t {
    char * name;
    bcm_field_action_t action_id;
    bcm_field_action_info_t action_info;
};

/**
 * Structure, which contains need information
 * for configuring of FEM condition actions.
 */
struct field_ftmh_fem_action_info_t {
    int nof_conditions;
    int * condition_ids;
    int nof_extractions;
    int nof_mapping_bits;
    /*
     * Structure replacing FEM_ID to indicate selected FEM by
     * its priority in the general FES/FEM structure.
     * See DNX_FIELD_ACTION_PRIORITY_POSITION_FEM_ID_GET
     */
    bcm_field_array_n_position_t field_array_n_position;
    bcm_field_fem_action_info_t fem_action_info;
};

/**
 * Structure, which contains all needed information
 * about configuring of one field group.
 */
struct field_ftmh_fg_info_t {
    bcm_field_group_t fg_id;
    bcm_field_context_t context_id;
    bcm_field_stage_t stage;
    bcm_field_group_type_t fg_type;
    int nof_quals;
    int nof_actions;
    int nof_fems;
    field_ftmh_qual_info_t * ftmh_qual_info;
    field_ftmh_action_info_t * ftmh_action_info;
    field_ftmh_fem_action_info_t * ftmh_fem_action_info;
};


/** IPMF2 Qualifiers info. */
field_ftmh_qual_info_t cint_field_ftmh_ipmf2_qual_info_array[FTMH_NOF_IPMF2_QUALIFIERS] = {
  /** qual_name  |  qual_id   |   qual_size     |  input_type    |    input_arg  |  qual_offset  */
    {"ftmh_mcid_or_outlif_qual", 0, MC_ID_or_OutLIF_QUAL_LENGTH,
        {bcmFieldInputTypeLayerAbsolute, 0, MC_ID_or_OutLIF_QUAL_OFFSET}}
};



/**
 * IPMF2 Action info.
 * For actions, which are not user define, we need only BCM action ID.
 */
field_ftmh_action_info_t cint_field_ftmh_ipmf2_action_info_array[FTMH_NOF_IPMF2_ACTIONS] = {
/** {action_name}   |  action_id  |    { stage | action_type | size | prefix_size | prefix_value | name  } */
    {"dest_mc_act", 0, {0, bcmFieldActionForward, MC_ID_DST_ACTION_LENGTH, 13, 3, {0}}}
};


/**
 * Array, which contains information per field group. Like:
 * fg_id, fg_type, quals, actions, fem_info.
 */
static field_ftmh_fg_info_t cint_ftmh_fg_info_array[FTMH_NOF_FG] = {
    /** IPMF2 field group info */
    {
        0,   /** Field group ID */
        0,    /** context ID */
        bcmFieldStageIngressPMF2,   /** Field stage */
        bcmFieldGroupTypeDirectExtraction,  /** Field group type */
        FTMH_NOF_IPMF2_QUALIFIERS,  /** Number of tested qualifiers */
        FTMH_NOF_IPMF2_ACTIONS, /** Number of tested actions */
        FTMH_NOF_IPMF2_FEMS, /** Number of tested fems */
        cint_field_ftmh_ipmf2_qual_info_array,   /** Qualifiers info */
        cint_field_ftmh_ipmf2_action_info_array, /** Actions info */
        NULL  /** FEM actions info */
    }
};


/* *INDENT-ON* */

/**
 * This function is used to create a context and configure
 * the relevant program for the testing.
 */
int
field_ftmh_context(
    int unit,
    bcm_field_context_t *context_id)
{
    bcm_field_context_info_t context_info;
    bcm_field_presel_entry_data_t presel_entry_data;
    bcm_field_context_param_info_t param_info;
    int int_bcmFieldStageIngressPMF1;
    int int_bcmFieldStageIngressPMF3;
    uint32 ing_port_pmf_cs_profile = 3;
    void *dest_char;

    printf("Running: field_ftmh_context()\n");

    BCM_IF_ERROR_RETURN_MSG(bcm_port_class_set(unit, recycle_port_mc, bcmPortClassFieldIngressPMF1PacketProcessingPortCs, ing_port_pmf_cs_profile), "");

    bcm_field_context_info_t_init(&context_info);
    dest_char = &(context_info.name[0]);
    sal_strncpy_s(dest_char, "MC_TWO_PASS_IPMF1", sizeof(context_info.name));
    BCM_IF_ERROR_RETURN_MSG(bcm_field_context_create(unit, 0, bcmFieldStageIngressPMF1, &context_info, context_id), "");

    bcm_field_context_param_info_t_init(&param_info);
    param_info.param_type = bcmFieldContextParamTypeSystemHeaderProfile;
    param_info.param_val = bcmFieldSystemHeaderProfileNone;
    BCM_IF_ERROR_RETURN_MSG(bcm_field_context_param_set(unit, 0, bcmFieldStageIngressPMF1, *context_id, &param_info), "");

    bcm_field_presel_entry_id_info_init(&mc_ipmf1_presel_entry_id);
    /** For iPMF2, iPMF1 presel must be configured. */
    mc_ipmf1_presel_entry_id.presel_id = 2;
    mc_ipmf1_presel_entry_id.stage = bcmFieldStageIngressPMF1;

    bcm_field_presel_entry_data_info_init(&presel_entry_data);
    presel_entry_data.nof_qualifiers = 1;
    presel_entry_data.context_id = *context_id;
    presel_entry_data.entry_valid = TRUE;

    presel_entry_data.qual_data[0].qual_type = bcmFieldQualifyPortClassPacketProcessing;
    presel_entry_data.qual_data[0].qual_arg = 0;
    presel_entry_data.qual_data[0].qual_value = ing_port_pmf_cs_profile;
    presel_entry_data.qual_data[0].qual_mask = 0x1F;
    BCM_IF_ERROR_RETURN_MSG(bcm_field_presel_set(unit, 0, &mc_ipmf1_presel_entry_id, &presel_entry_data), "");

    return BCM_E_NONE;
}


/** Used to configure the user qualifiers. */
int
field_ftmh_user_qual_config(
    int unit,
    bcm_field_stage_t field_stage,
    field_ftmh_qual_info_t * ftmh_qual_info)
{
    bcm_field_qualifier_info_create_t qual_info;
    void *dest_char;

    printf("Running: field_ftmh_user_qual_config()\n");

    bcm_field_qualifier_info_create_t_init(&qual_info);
    dest_char = &(qual_info.name[0]);
    sal_strncpy_s(dest_char, ftmh_qual_info->name, sizeof(qual_info.name));
    qual_info.size = ftmh_qual_info->qual_length;

    return BCM_E_NONE;
}

/** Used to configure the user defined actions. */
int
field_ftmh_user_action_config(
    int unit,
    bcm_field_stage_t field_stage,
    field_ftmh_action_info_t * ftmh_action_info)
{
    bcm_field_action_info_t action_info;
    void *dest_char;

    printf("Running: field_itmh_user_action_config()\n");
    bcm_field_action_info_t_init(&action_info);

    action_info.action_type = ftmh_action_info->action_info.action_type;
    dest_char = &(action_info.name[0]);
    sal_strncpy_s(dest_char, ftmh_action_info->name, sizeof(action_info.name));
    action_info.size = ftmh_action_info->action_info.size;
    action_info.stage = field_stage;
    action_info.prefix_size = ftmh_action_info->action_info.prefix_size;
    action_info.prefix_value = ftmh_action_info->action_info.prefix_value;

    BCM_IF_ERROR_RETURN_MSG(bcm_field_action_create(unit, 0, &action_info, &(ftmh_action_info->action_id)), "");
    return BCM_E_NONE;
}

/** This function is configuring all needed FEM actions. */
int
field_ftmh_fem_action_config(
    int unit,
    bcm_field_group_t fg_id,
    field_ftmh_fem_action_info_t * ftmh_fem_action_info)
{
    int mapping_bits_index, conditions_index, extractions_index;
    bcm_field_fem_action_info_t fem_action_info;
    int *condition_id = ftmh_fem_action_info->condition_ids;
    bcm_field_action_priority_t action_priority;

    printf("Running: field_ftmh_fem_action_config()\n");
    bcm_field_fem_action_info_t_init(&fem_action_info);

    fem_action_info.fem_input.input_offset = ftmh_fem_action_info->fem_action_info.fem_input.input_offset;
    fem_action_info.condition_msb = ftmh_fem_action_info->fem_action_info.condition_msb;
    for (conditions_index = 0; conditions_index < ftmh_fem_action_info->nof_conditions; conditions_index++)
    {
        fem_action_info.fem_condition[condition_id[conditions_index]].extraction_id =
            ftmh_fem_action_info->fem_action_info.fem_condition[conditions_index].extraction_id;
        fem_action_info.fem_condition[condition_id[conditions_index]].is_action_valid =
            ftmh_fem_action_info->fem_action_info.fem_condition[conditions_index].is_action_valid;
    }
    for (extractions_index = 0; extractions_index < ftmh_fem_action_info->nof_extractions; extractions_index++)
    {
        fem_action_info.fem_extraction[extractions_index].action_type =
            ftmh_fem_action_info->fem_action_info.fem_extraction[extractions_index].action_type;
        fem_action_info.fem_extraction[extractions_index].increment =
            ftmh_fem_action_info->fem_action_info.fem_extraction[extractions_index].increment;
        for (mapping_bits_index = 0; mapping_bits_index < ftmh_fem_action_info->nof_mapping_bits; mapping_bits_index++)
        {
            fem_action_info.fem_extraction[extractions_index].output_bit[mapping_bits_index].offset =
                ftmh_fem_action_info->fem_action_info.fem_extraction[extractions_index].
                output_bit[mapping_bits_index].offset;
            fem_action_info.fem_extraction[extractions_index].output_bit[mapping_bits_index].forced_value =
                ftmh_fem_action_info->fem_action_info.fem_extraction[extractions_index].
                output_bit[mapping_bits_index].forced_value;
            fem_action_info.fem_extraction[extractions_index].output_bit[mapping_bits_index].source_type =
                ftmh_fem_action_info->fem_action_info.fem_extraction[extractions_index].
                output_bit[mapping_bits_index].source_type;
        }
    }
    {
        int array_id, position;

        array_id = ftmh_fem_action_info->field_array_n_position.array_id;
        position = ftmh_fem_action_info->field_array_n_position.fem_position_in_array;
        action_priority = BCM_FIELD_ACTION_POSITION(array_id,position);
    }
    BCM_IF_ERROR_RETURN_MSG(bcm_field_fem_action_add(unit, 0, fg_id, action_priority, &fem_action_info), "");

    return BCM_E_NONE;
}

/**
 * This function creates field group, with all relevant information to it and adding it to the context.
 */
int
field_ftmh_group_config(
    int unit,
    field_ftmh_fg_info_t * ftmh_fg_info)
{
    int qual_index, action_index, fem_index;
    bcm_field_group_info_t fg_info;
    bcm_field_group_attach_info_t attach_info;
    void *dest_char;

    printf("Running: field_ftmh_group_config()\n");

    BCM_IF_ERROR_RETURN_MSG(field_ftmh_context(unit, &(ftmh_fg_info->context_id)), "");

    bcm_field_group_info_t_init(&fg_info);
    dest_char = &(fg_info.name[0]);
    sal_strncpy_s(dest_char, "MC_TWO_PASS_FG", sizeof(fg_info.name));
    bcm_field_group_attach_info_t_init(&attach_info);
    fg_info.fg_type = ftmh_fg_info->fg_type;
    fg_info.stage = ftmh_fg_info->stage;
    fg_info.nof_quals = ftmh_fg_info->nof_quals;
    fg_info.nof_actions = ftmh_fg_info->nof_actions;
    attach_info.key_info.nof_quals = fg_info.nof_quals;
    attach_info.payload_info.nof_actions = fg_info.nof_actions;
    /**
     * Iterate over all qualifiers for current field group. Using field_itmh_user_qual_config()
     * to create all user define qualifiers internal function.
     */
    for (qual_index = 0; qual_index < fg_info.nof_quals; qual_index++)
    {
        BCM_IF_ERROR_RETURN_MSG(field_ftmh_user_qual_config(unit, fg_info.stage, &(ftmh_fg_info->ftmh_qual_info[qual_index])), "");
        fg_info.qual_types[qual_index] = ftmh_fg_info->ftmh_qual_info[qual_index].qual_id;
        attach_info.key_info.qual_types[qual_index] = ftmh_fg_info->ftmh_qual_info[qual_index].qual_id;
        attach_info.key_info.qual_info[qual_index].input_type =
            ftmh_fg_info->ftmh_qual_info[qual_index].qual_attach_info.input_type;
        attach_info.key_info.qual_info[qual_index].input_arg =
            ftmh_fg_info->ftmh_qual_info[qual_index].qual_attach_info.input_arg;
        attach_info.key_info.qual_info[qual_index].offset =
            ftmh_fg_info->ftmh_qual_info[qual_index].qual_attach_info.offset;
    }

    /**
     * Iterate over all actions for current field group. For those, which are user define,
     * use field_ftmh_user_action_config() internal function.
     */
    for (action_index = 0; action_index < fg_info.nof_actions; action_index++)
    {
        if (ftmh_fg_info->ftmh_action_info[action_index].name == NULL)
        {
            fg_info.action_types[action_index] = ftmh_fg_info->ftmh_action_info[action_index].action_id;
            fg_info.action_with_valid_bit[action_index] = FALSE;
            attach_info.payload_info.action_types[action_index] =
                ftmh_fg_info->ftmh_action_info[action_index].action_id;
        }
        else
        {
            BCM_IF_ERROR_RETURN_MSG(field_ftmh_user_action_config(unit, fg_info.stage, ftmh_fg_info->ftmh_action_info[action_index]), "");

            fg_info.action_types[action_index] = ftmh_fg_info->ftmh_action_info[action_index].action_id;
            fg_info.action_with_valid_bit[action_index] = FALSE;
            attach_info.payload_info.action_types[action_index] = ftmh_fg_info->ftmh_action_info[action_index].action_id;
        }
    }

    BCM_IF_ERROR_RETURN_MSG(bcm_field_group_add(unit, 0, &fg_info, &(ftmh_fg_info->fg_id)), "");

    for (fem_index = 0; fem_index < ftmh_fg_info->nof_fems; fem_index++)
    {
        BCM_IF_ERROR_RETURN_MSG(field_ftmh_fem_action_config(unit, ftmh_fg_info->fg_id, ftmh_fg_info->ftmh_fem_action_info[fem_index]), "");
    }

    BCM_IF_ERROR_RETURN_MSG(bcm_field_group_context_attach(unit, 0, ftmh_fg_info->fg_id, ftmh_fg_info->context_id, &attach_info), "");

    return BCM_E_NONE;
}

/*
 * This function sets all required HW configuration for FTMH
 * processing when working in STACKING programmable mode.
 * Configures 1 field database of direct extraction
 * mode in order to extract ftmh information from the
 * header.
 * The header information is used to perform actions (such as
 * change destination) In adding the new header profile is set
 * according to the stacking type.
 */
int
field_mc_two_pass_main(
    int unit)
{
    int fg_index = 0;

    /**
     * Parsing the global array "cint_ftmh_fg_info_array[]" with all needed
     * information for the field group.
     */

    for (fg_index = 0; fg_index < FTMH_NOF_FG; fg_index++)
    {
        BCM_IF_ERROR_RETURN_MSG(field_ftmh_group_config(unit, &(cint_ftmh_fg_info_array[fg_index])), "");
    }

    return BCM_E_NONE;
}

/** Destroys all allocated data from the FTMH configuration. */
int
field_mc_two_pass_destroy(
    int unit)
{
    int fg_index, qual_index, action_index, fem_index;
    bcm_field_presel_entry_data_t presel_entry_data;
    field_ftmh_fg_info_t ftmh_fg_info;

    printf("Running: field_mc_two_pass_destroy()\n");

    bcm_field_presel_entry_data_info_init(&presel_entry_data);
    presel_entry_data.entry_valid = FALSE;
    presel_entry_data.context_id = 0;
    BCM_IF_ERROR_RETURN_MSG(bcm_field_presel_set(unit, 0, &mc_ipmf1_presel_entry_id, &presel_entry_data), "");

    for (fg_index = 0; fg_index < FTMH_NOF_FG; fg_index++)
    {
        ftmh_fg_info = cint_ftmh_fg_info_array[fg_index];
        BCM_IF_ERROR_RETURN_MSG(bcm_field_group_context_detach(unit, ftmh_fg_info.fg_id,
                                            ftmh_fg_info.context_id), "");

        for (fem_index = 0; fem_index < ftmh_fg_info.nof_fems; fem_index++)
        {
            bcm_field_action_priority_t action_priority;
            int array_id, position;

            array_id = ftmh_fg_info.ftmh_fem_action_info[fem_index].field_array_n_position.array_id;
            position = ftmh_fg_info.ftmh_fem_action_info[fem_index].field_array_n_position.fem_position_in_array;
            action_priority = BCM_FIELD_ACTION_POSITION(array_id,position);
            BCM_IF_ERROR_RETURN_MSG(bcm_field_fem_action_delete(unit, ftmh_fg_info.fg_id,action_priority), "");
        }

        BCM_IF_ERROR_RETURN_MSG(bcm_field_group_delete(unit, ftmh_fg_info.fg_id), "");

        BCM_IF_ERROR_RETURN_MSG(bcm_field_context_destroy(unit, bcmFieldStageIngressPMF1, ftmh_fg_info.context_id), "");
        for (qual_index = 0; qual_index < ftmh_fg_info.nof_quals; qual_index++)
        {
            BCM_IF_ERROR_RETURN_MSG(bcm_field_qualifier_destroy(unit, ftmh_fg_info.ftmh_qual_info[qual_index].qual_id), "");
        }

        for (action_index = 0; action_index < ftmh_fg_info.nof_actions; action_index++)
        {
            if (ftmh_fg_info.ftmh_action_info[action_index].name != NULL)
            {
                BCM_IF_ERROR_RETURN_MSG(bcm_field_action_destroy(unit, ftmh_fg_info.ftmh_action_info[action_index].action_id), "");
            }
        }
    }
    return BCM_E_NONE;
}

