/** \file diag_dnx_field_qualifier.c
 *
 * Diagnostics procedures, for DNX, for 'qualifier' operations.
 *
 */
/*
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2022 Broadcom Inc. All rights reserved.
 */
#ifdef BSL_LOG_MODULE
#error "BSL_LOG_MODULE redefined"
#endif

#define BSL_LOG_MODULE BSL_LS_BCMDNX_FLDDIAGSDNX
/*
 * Include files.
 * {
 */
#include <sal/appl/sal.h>

#include <soc/sand/shrextend/shrextend_debug.h>

#include <soc/dnx/swstate/auto_generated/access/dnx_field_access.h>
#include <soc/dnx/swstate/auto_generated/access/dnx_field_context_access.h>
#include <soc/dnx/swstate/auto_generated/access/dnx_field_qualifier_access.h>
#include <soc/dnx/field/tcam/tcam_handler.h>

#include <bcm_int/dnx/field/field.h>
#include <bcm_int/dnx/field/field_group.h>
#include <bcm_int/dnx/field/field_entry.h>
#include <bcm_int/dnx/field/field_map.h>
#include <bcm_int/dnx/algo/field/algo_field.h>

#include <appl/diag/sand/diag_sand_framework.h>
#include <appl/diag/sand/diag_sand_prt.h>
#include <appl/diag/dnx/diag_dnx_field.h>
#include "diag_dnx_field_qualifier.h"
#include "diag_dnx_field_utils.h"
#include <src/bcm/dnx/field/map/field_map_local.h>
#include <soc/dnx/dnx_data/auto_generated/dnx_data_field_map.h>

extern const dnx_field_qual_map_t dnx_global_qual_map[bcmFieldQualifyCount];

/*
 * }
 */

/*
 * DEFINEs
 * {
 */
/*
 * }
 */
/*
 * TYPEDEFs
 * {
 */
/*
 * }
 */
/*
 * MACROs
 * {
 */
/*
 * Options
 * {
 */
/*
 * }
 */

/*
 * Global and Static
 * {
 */
extern const char *bcm_qual_description[bcmFieldQualifyCount];

static shr_error_e
diag_dnx_field_qual_user_init(
    int unit)
{
    SHR_FUNC_INIT_VARS(unit);

    SHR_IF_ERR_EXIT(diag_dnx_field_generic_init(unit, FALSE));

exit:
    SHR_FUNC_EXIT;
}

/* *INDENT-OFF* */
/**
 *  'Help' description for Qualifier display (shell commands).
 */
static sh_sand_man_t Field_qualifier_user_list_man = {
    .brief = "'id'- displays the basic info about a specific field qualifier or range of qualifiers",
    .full = "'id' display for a range of field qualifiers. Range is specified via 'qualifier'.\r\n"
            "If no 'id' is specified then '0'-'nof_quals-1' is assumed (0-255).\r\n"
            "If only one value is specified for 'id' then this single value range is assumed.\r\n",
    .synopsis = "[id=<lower value>-<upper value>]",
    .examples = ""
                "\n" "id=0-20",
    .init_cb =  diag_dnx_field_qual_user_init,
};

static sh_sand_man_t field_map_cs_man = {
    .brief = "Present bcm qualifiers valid for context selection",
    .full = "Present bcm qualifiers valid for context selection, per stage show DBAL field representing this qualifier",
    .synopsis = NULL,
    .examples = ""
                "\n" "name=ForwardingLayerIndex stage=ipmf1"
                "\n" "stage=ipmf1 "
                "\n" "stage=ipmf3 show_desc=false",
};

static sh_sand_man_t field_map_qual_man = {
    .brief = "Present bcm qualifiers valid for key construction",
    .full = "Present bcm qualifiers valid for key construction, per stage show DBAL field representing this qualifier",
    .synopsis = NULL,
    .examples = "\n" "name=InPort stage=IPMF1 class=meta",
};

static sh_sand_option_t field_map_cs_options[] = {
    {"name",  SAL_FIELD_TYPE_STR, "Filter qualifier by comparing this substring to the name", ""},
    {DIAG_DNX_FIELD_OPTION_STAGE, SAL_FIELD_TYPE_UINT32, "Show only qualifier for the stage", "STAGE_LOWEST-STAGE_HIGHEST", (void *)Field_qualifier_diag_stage_enum_table, "STAGE_LOWEST-STAGE_HIGHEST"},
    {DIAG_DNX_FIELD_OPTION_SHOW_DESC, SAL_FIELD_TYPE_BOOL, "Show qualifiers description", "true"},
    {NULL}
};

static sh_sand_option_t Field_qualifier_user_list_options[] = {
    {DIAG_DNX_FIELD_OPTION_ID,  SAL_FIELD_TYPE_UINT32, "Lowest-highest user defined qualifier ids to get its info",       "MIN-MAX",       (void *)Field_qualifier_enum_table, "MIN-MAX"},
    {NULL}
};

static sh_sand_option_t field_map_qualifier_bcm_options[] = {
    {"name",  SAL_FIELD_TYPE_STR,  "Filter qualifier by comparing this substring to the name", ""},
    {DIAG_DNX_FIELD_OPTION_STAGE, SAL_FIELD_TYPE_UINT32, "Show only qualifier for the stage", "STAGE_LOWEST-STAGE_HIGHEST", (void *)Field_qualifier_diag_stage_enum_table, "STAGE_LOWEST-STAGE_HIGHEST"},
    {"class", SAL_FIELD_TYPE_ENUM, "Filter qualifier by class (layer, header, meta)", "all", (void *)Field_qual_class_enum_table},
    {DIAG_DNX_FIELD_OPTION_SHOW_DESC, SAL_FIELD_TYPE_BOOL, "Show qualifiers description", "true"},
    {NULL}
};

static sh_sand_option_t field_map_qualifier_dnx_options[] = {
    {"name",  SAL_FIELD_TYPE_STR,  "Filter qualifier by comparing this substring to the name", ""},
    {DIAG_DNX_FIELD_OPTION_STAGE, SAL_FIELD_TYPE_UINT32, "Show only qualifier for the stage", "STAGE_LOWEST-STAGE_HIGHEST", (void *)Field_qualifier_diag_stage_enum_table, "STAGE_LOWEST-STAGE_HIGHEST"},
    {"class", SAL_FIELD_TYPE_ENUM, "Filter qualifier by class (layer, header, meta)", "all", (void *)Field_qual_class_enum_table},
    {NULL}
};


static sh_sand_option_t field_map_qualifier_virtualwire_options[] = {
    {DIAG_DNX_FIELD_OPTION_ID,  SAL_FIELD_TYPE_UINT32, "Lowest-highest user defined virtualwire qualifier ids", "MIN-MAX", (void *)Field_qualifier_vw_enum_table, "MIN-MAX"},
    {DIAG_DNX_FIELD_OPTION_VW_NAME,  SAL_FIELD_TYPE_STR,  "Filter virtualwire qualifier by comparing this substring to the virtualwire name", ""},
    {DIAG_DNX_FIELD_OPTION_STAGE, SAL_FIELD_TYPE_UINT32, "Show only virtualwire qualifier for the stage", "STAGE_LOWEST-STAGE_HIGHEST", (void *)Field_qualifier_diag_stage_enum_table, "STAGE_LOWEST-STAGE_HIGHEST"},
    {NULL}
};


/*
 * }
 */
/* *INDENT-ON* */

/**
 * \brief
 *   This function prints the size of a qualifier, including its parts.
 * \param [in] unit - The unit number.
 * \param [in] nof_mappings - How many parts the qualifier has.
 * \param [in] qual_sizes - Array of sizes of DNX_FIELD_QAUL_MAX_NOF_MAPPINGS parts.
 * \param [in] qual_size_total - Total size of all parts.
 * \param [out] qual_size_string - The output sting. If one part just prints its size,
 *                                 if more than one prints equation.
 *                                 Array of size DIAG_DNX_FIELD_UTILS_STR_SIZE.
 *
 * \return
 *   Error code (as per 'shr_error_e').
 * \see
 *   shr_error_e
 */
static shr_error_e
diag_dnx_field_qualifier_string_size_split(
    int unit,
    int nof_mappings,
    uint32 qual_sizes[DNX_FIELD_QAUL_MAX_NOF_MAPPINGS],
    uint32 qual_size_total,
    char qual_size_string[DIAG_DNX_FIELD_UTILS_STR_SIZE])
{
    char qual_size_string_buff[DIAG_DNX_FIELD_UTILS_STR_SIZE] = { 0 };
    char qual_size_string_buff_added[DIAG_DNX_FIELD_UTILS_STR_SIZE] = { 0 };
    int qual_part_index;
    int sum_qual_size_parts;

    SHR_FUNC_INIT_VARS(unit);

    sal_memset(qual_size_string, 0x0, sizeof(qual_size_string[0]) * DIAG_DNX_FIELD_UTILS_STR_SIZE);

    if (nof_mappings <= 0 || nof_mappings > DNX_FIELD_QAUL_MAX_NOF_MAPPINGS)
    {
        SHR_ERR_EXIT(_SHR_E_INTERNAL, "Qualifier has %d mappings, must be between (1-%d).\n",
                     nof_mappings, DNX_FIELD_QAUL_MAX_NOF_MAPPINGS);
    }

    DIAG_DNX_FIELD_UTILS_STR_INPUT_VERIFY(NULL, "%d", qual_sizes[0]);
    sal_snprintf(qual_size_string_buff, sizeof(qual_size_string_buff), "%d", qual_sizes[0]);
    sum_qual_size_parts = qual_sizes[0];

    for (qual_part_index = 1; qual_part_index < nof_mappings; qual_part_index++)
    {
        DIAG_DNX_FIELD_UTILS_STR_INPUT_VERIFY(qual_size_string_buff_added, "+%d", qual_sizes[qual_part_index]);
        sal_snprintf(qual_size_string_buff_added, sizeof(qual_size_string_buff_added), "+%d",
                     qual_sizes[qual_part_index]);
        DIAG_DNX_FIELD_UTILS_STR_INPUT_VERIFY(qual_size_string_buff, "%s", qual_size_string_buff_added);
        sal_strncat_s(qual_size_string_buff, qual_size_string_buff_added, sizeof(qual_size_string_buff));
        sum_qual_size_parts += qual_sizes[qual_part_index];
    }

    if (sum_qual_size_parts != qual_size_total)
    {
        SHR_ERR_EXIT(_SHR_E_INTERNAL, "Sum of the sizes of all parts of the qualifier is %d, "
                     "but given %d. number of parts %d.\n", sum_qual_size_parts, qual_size_total, nof_mappings);
    }

    if (nof_mappings > 1)
    {
        DIAG_DNX_FIELD_UTILS_STR_INPUT_VERIFY(qual_size_string_buff_added, "=%d", qual_size_total);
        sal_snprintf(qual_size_string_buff_added, sizeof(qual_size_string_buff_added), "=%d", qual_size_total);
        DIAG_DNX_FIELD_UTILS_STR_INPUT_VERIFY(qual_size_string_buff, "%s", qual_size_string_buff_added);
        sal_strncat_s(qual_size_string_buff, qual_size_string_buff_added, sizeof(qual_size_string_buff));
    }

    sal_strncpy_s(qual_size_string, qual_size_string_buff, sizeof(qual_size_string[0]) * DIAG_DNX_FIELD_UTILS_STR_SIZE);

exit:
    SHR_FUNC_EXIT;
}

/**
 * \brief
 *   This function prints the offset of a qualifier, including its parts.
 * \param [in] unit - The unit number.
 * \param [in] nof_mappings - How many parts the qualifier has.
 * \param [in] qual_offsets - Array of offsets of DNX_FIELD_QAUL_MAX_NOF_MAPPINGS parts.
 * \param [out] qual_offset_string - The output sting, printing all offsets.
 *                                   Array of size DIAG_DNX_FIELD_UTILS_STR_SIZE.
 *
 * \return
 *   Error code (as per 'shr_error_e').
 * \see
 *   shr_error_e
 */
static shr_error_e
diag_dnx_field_qualifier_string_offset_split(
    int unit,
    int nof_mappings,
    int qual_offsets[DNX_FIELD_QAUL_MAX_NOF_MAPPINGS],
    char qual_offset_string[DIAG_DNX_FIELD_UTILS_STR_SIZE])
{
    char qual_offset_string_buff[DIAG_DNX_FIELD_UTILS_STR_SIZE] = { 0 };
    char qual_offset_string_buff_added[DIAG_DNX_FIELD_UTILS_STR_SIZE] = { 0 };
    int qual_part_index;

    SHR_FUNC_INIT_VARS(unit);

    sal_memset(qual_offset_string, 0x0, sizeof(qual_offset_string[0]) * DIAG_DNX_FIELD_UTILS_STR_SIZE);

    if (nof_mappings <= 0 || nof_mappings > DNX_FIELD_QAUL_MAX_NOF_MAPPINGS)
    {
        SHR_ERR_EXIT(_SHR_E_INTERNAL, "Qualifier has %d mappings, must be between (1-%d).\n",
                     nof_mappings, DNX_FIELD_QAUL_MAX_NOF_MAPPINGS);
    }

    DIAG_DNX_FIELD_UTILS_STR_INPUT_VERIFY(NULL, "%d", qual_offsets[0]);
    sal_snprintf(qual_offset_string_buff, sizeof(qual_offset_string_buff), "%d", qual_offsets[0]);

    for (qual_part_index = 1; qual_part_index < nof_mappings; qual_part_index++)
    {
        DIAG_DNX_FIELD_UTILS_STR_INPUT_VERIFY(qual_offset_string_buff_added, ", %d", qual_offsets[qual_part_index]);
        sal_snprintf(qual_offset_string_buff_added, sizeof(qual_offset_string_buff_added), ", %d",
                     qual_offsets[qual_part_index]);
        DIAG_DNX_FIELD_UTILS_STR_INPUT_VERIFY(qual_offset_string_buff, "%s", qual_offset_string_buff_added);
        sal_strncat_s(qual_offset_string_buff, qual_offset_string_buff_added, sizeof(qual_offset_string_buff));
    }

    sal_strncpy_s(qual_offset_string, qual_offset_string_buff,
                  sizeof(qual_offset_string[0]) * DIAG_DNX_FIELD_UTILS_STR_SIZE);

exit:
    SHR_FUNC_EXIT;
}

static shr_error_e
diag_dnx_field_map_cs_print(
    int unit,
    char *match_n,
    dnx_field_stage_e stage,
    uint8 show_desc,
    prt_control_t * prt_ctr)
{
    bcm_field_qualify_t bcm_qual;
    int dnx_cs_qual_size;
    shr_error_e rv;
    SHR_FUNC_INIT_VARS(unit);

    for (bcm_qual = 0; bcm_qual < bcmFieldQualifyCount; bcm_qual++)
    {
        const dnx_field_cs_qual_map_t *cs_qual_map_p;
        int cs_qual_iter = -1;
        dnx_field_cs_qual_e cs_dnx_qual;
        dbal_fields_e dbal_field_id = DBAL_FIELD_EMPTY;
        bcm_field_qualify_t cs_bcm_qual = bcm_qual;
        dnx_field_qual_t lr_dnx_qual_wthout_stage = dnx_global_qual_map[bcm_qual].dnx_qual;
        dnx_field_qual_t lr_dnx_qual = DNX_FIELD_QUAL_TYPE_INVALID;
        int is_lr_qual = FALSE;
        uint8 raw_qual_found = FALSE;
        bcm_field_qualify_t bcm_qual_raw;

        if (DNX_QUAL_CLASS(lr_dnx_qual_wthout_stage) == DNX_FIELD_QUAL_CLASS_LAYER_RECORD)
        {
            dnx_field_layer_record_qual_e lr_dnx_qual_id = DNX_QUAL_ID(lr_dnx_qual_wthout_stage);
            if ((lr_dnx_qual_id != DNX_FIELD_LR_QUAL_PROTOCOL) &&
                (lr_dnx_qual_id != DNX_FIELD_LR_QUAL_OFFSET) && (lr_dnx_qual_id != DNX_FIELD_LR_QUAL_QUALIFIER))
            {
                const dnx_field_qual_map_t *qual_map_entry_pp;
                bsl_severity_t original_severity_fld_proc;
                uint32 qual_size;
                cs_bcm_qual = bcmFieldQualifyForwardingLayerQualifier;
                is_lr_qual = TRUE;
                lr_dnx_qual = DNX_QUAL(DNX_FIELD_QUAL_CLASS_LAYER_RECORD, stage, DNX_QUAL_ID(lr_dnx_qual_wthout_stage));
                rv = dnx_field_map_qual_bcm_to_dnx_int(unit, stage, FALSE, bcm_qual, &lr_dnx_qual, &qual_map_entry_pp);
                if (rv == _SHR_E_NOT_FOUND)
                {
                    continue;
                }
                SHR_IF_ERR_EXIT(rv);
                if (lr_dnx_qual != DNX_QUAL(DNX_FIELD_QUAL_CLASS_LAYER_RECORD, stage, lr_dnx_qual_id))
                {
                    SHR_ERR_EXIT(_SHR_E_INTERNAL,
                                 "For qual \"%s\" is layer record qualifier but mismatch 0x%x vs 0x%x.\n",
                                 dnx_field_bcm_qual_text(unit, cs_bcm_qual), lr_dnx_qual,
                                 DNX_QUAL(DNX_FIELD_QUAL_CLASS_LAYER_RECORD, stage, lr_dnx_qual_id));
                }
                SHR_GET_SEVERITY_FOR_MODULE_SPECIFIC(BSL_LS_BCMDNX_FLDPROCDNX, original_severity_fld_proc);
                SHR_SET_SEVERITY_FOR_MODULE_SPECIFIC(BSL_LS_BCMDNX_FLDPROCDNX, bslSeverityFatal);
                rv = dnx_field_map_dnx_qual_size(unit, stage, lr_dnx_qual, NULL, NULL, &qual_size);
                /** Verify the qualifier is supported by this device */
                SHR_SET_SEVERITY_FOR_MODULE_SPECIFIC(BSL_LS_BCMDNX_FLDPROCDNX, original_severity_fld_proc);
                if (rv == _SHR_E_PARAM)
                {
                    continue;
                }
            }
        }

        cs_qual_map_p = &dnx_field_map_stage_info[stage].cs_qual_map[cs_bcm_qual];

        if (cs_qual_map_p->nof == 0)
        {
            continue;
        }

        /** Sanity check */
        if (cs_qual_map_p->nof < 0)
        {
            SHR_ERR_EXIT(_SHR_E_INTERNAL, "For qual \"%s\" stage \"%s\", nof %d.\n",
                         dnx_field_bcm_qual_text(unit, cs_bcm_qual), dnx_field_stage_text(unit, stage),
                         cs_qual_map_p->nof);
        }

        /** Sanity check */
        if (is_lr_qual && (cs_qual_map_p->qual_type_bcm_to_dnx_conversion_cb != NULL))
        {
            SHR_ERR_EXIT(_SHR_E_INTERNAL,
                         "Qual \"%s\" stage \"%s\" is a layer record qualifier, but has type conversion.\n",
                         dnx_field_bcm_qual_text(unit, cs_bcm_qual), dnx_field_stage_text(unit, stage));
        }

        if (!ISEMPTY(match_n) && !sal_strcasestr(dnx_field_bcm_qual_text(unit, bcm_qual), match_n))
        {
            continue;
        }

        if (cs_qual_map_p->nof == 1)
        {
            cs_dnx_qual = cs_qual_map_p->dnx_qual;
            if ((cs_dnx_qual == DNX_FIELD_CS_QUAL_INVALID) ||
                (cs_dnx_qual < 0) || (cs_dnx_qual >= DNX_FIELD_CS_QUAL_NOF))
            {
                SHR_ERR_EXIT(_SHR_E_INTERNAL, "For qual \"%s\" stage \"%s\", nof %d, "
                             "DNX qualifer (%d) is invalid.\n",
                             dnx_field_bcm_qual_text(unit, cs_bcm_qual), dnx_field_stage_text(unit, stage),
                             cs_qual_map_p->nof, cs_dnx_qual);
            }
            dbal_field_id = dnx_data_field_map.qual.cs_get(unit, stage, cs_dnx_qual)->dbal_field;
            if (dbal_field_id == DBAL_FIELD_EMPTY)
            {
                continue;
            }
        }
        else
        {
            /** Find the first legal CS qualifier. */
            for (cs_qual_iter = 0; cs_qual_iter < cs_qual_map_p->nof; cs_qual_iter++)
            {
                cs_dnx_qual = cs_qual_map_p->dnx_qual_array[cs_qual_iter];
                if ((cs_dnx_qual == DNX_FIELD_CS_QUAL_INVALID) ||
                    (cs_dnx_qual < 0) || (cs_dnx_qual >= DNX_FIELD_CS_QUAL_NOF))
                {
                    SHR_ERR_EXIT(_SHR_E_INTERNAL, "For qual \"%s\" stage \"%s\", nof %d, "
                                 "DNX qualifer %d (%d) is invalid.\n",
                                 dnx_field_bcm_qual_text(unit, cs_bcm_qual), dnx_field_stage_text(unit, stage),
                                 cs_qual_map_p->nof, cs_qual_iter, cs_dnx_qual);
                }
                dbal_field_id = dnx_data_field_map.qual.cs_get(unit, stage, cs_dnx_qual)->dbal_field;
                if (dbal_field_id != DBAL_FIELD_EMPTY)
                {
                    break;
                }
            }
            if (cs_qual_iter == cs_qual_map_p->nof)
            {
                /** No legal CS qualifier found. */
                continue;
            }
        }

        /** Sanity check. */
        if (dbal_field_id == DBAL_FIELD_EMPTY)
        {
            SHR_ERR_EXIT(_SHR_E_INTERNAL, "dbal_field_id not set.\n");
        }

        rv = dbal_tables_field_size_get(unit, dnx_field_map_stage_info[stage].cs_table_id, dbal_field_id,
                                        TRUE, 0, 0, &dnx_cs_qual_size);
        SHR_IF_ERR_EXIT_EXCEPT_IF(rv, _SHR_E_NOT_FOUND);
        if (rv == _SHR_E_NOT_FOUND)
        {
            continue;
        }

        PRT_ROW_ADD(PRT_ROW_SEP_UNDERSCORE_BEFORE);
        PRT_CELL_SET("%s", dnx_field_bcm_qual_text(unit, bcm_qual));
        if (show_desc == TRUE)
        {
            PRT_CELL_SET("%s", bcm_qual_description[bcm_qual]);
        }
        PRT_CELL_SET("%s", dbal_field_to_string(unit, dbal_field_id));
        /** DBAL field size, and bits in field for LR.*/
        if (is_lr_qual)
        {
            int lr_offset;
            int nof_mappings;
            uint32 qual_size;

            SHR_IF_ERR_EXIT(dnx_field_map_dnx_qual_size(unit, stage, lr_dnx_qual, &nof_mappings, NULL, &qual_size));
            if (nof_mappings != 1)
            {
                SHR_ERR_EXIT(_SHR_E_INTERNAL,
                             "LR qualifier is split. Unexpected. Not supported in context selection.\n");
            }
            SHR_IF_ERR_EXIT(dnx_field_map_dnx_lr_qual_offset_in_lr_qual(unit, stage, lr_dnx_qual, &lr_offset));
            PRT_CELL_SET("%d (%d:%d)", dnx_cs_qual_size, lr_offset, (lr_offset + qual_size - 1));
        }
        else
        {
            PRT_CELL_SET("%d", dnx_cs_qual_size);
        }

        /** Raw qual*/
        if (is_lr_qual)
        {
            if (BCM_TO_DNX_IS_BAISC_OBJ(dnx_global_qual_map[bcm_qual].flags))
            {
                raw_qual_found = TRUE;
                bcm_qual_raw = bcm_qual;
            }
            else
            {
                for (bcm_qual_raw = 0; bcm_qual_raw < bcmFieldQualifyCount; bcm_qual_raw++)
                {
                    if (dnx_global_qual_map[bcm_qual].dnx_qual == dnx_global_qual_map[bcm_qual_raw].dnx_qual &&
                        BCM_TO_DNX_IS_BAISC_OBJ(dnx_global_qual_map[bcm_qual_raw].flags))
                    {
                        raw_qual_found = TRUE;
                        break;
                    }
                }

            }
        }
        else
        {
            /**
             * In case current qualifier is marked as basic_object, we should present it.
             * Otherwise we should find the basic qualifier for current BCM qual.
             */
            if (BCM_TO_DNX_IS_BAISC_OBJ(cs_qual_map_p->flags))
            {
                raw_qual_found = TRUE;
                bcm_qual_raw = bcm_qual;
            }
            else
            {
                for (bcm_qual_raw = 0; bcm_qual_raw < bcmFieldQualifyCount; bcm_qual_raw++)
                {
                    int match = FALSE;
                    if (dnx_field_map_stage_info[stage].cs_qual_map[bcm_qual_raw].nof != cs_qual_map_p->nof)
                    {
                        continue;
                    }
                    if (cs_qual_map_p->nof == 1)
                    {
                        if (dnx_field_map_stage_info[stage].cs_qual_map[bcm_qual_raw].dnx_qual ==
                            dnx_field_map_stage_info[stage].cs_qual_map[bcm_qual].dnx_qual)
                        {
                            match = TRUE;
                        }
                    }
                    else
                    {
                        int cs_qual_iter_raw;
                        for (cs_qual_iter_raw = 0; cs_qual_iter_raw < cs_qual_map_p->nof; cs_qual_iter_raw++)
                        {
                            if (dnx_field_map_stage_info[stage].
                                cs_qual_map[bcm_qual_raw].dnx_qual_array[cs_qual_iter_raw] ==
                                dnx_field_map_stage_info[stage].cs_qual_map[bcm_qual].dnx_qual_array[cs_qual_iter_raw])
                            {
                                match = TRUE;
                                break;
                            }
                        }
                    }
                    if (match &&
                        BCM_TO_DNX_IS_BAISC_OBJ(dnx_field_map_stage_info[stage].cs_qual_map[bcm_qual_raw].flags))
                    {
                        raw_qual_found = TRUE;
                        break;
                    }
                }
            }
        }
        if (raw_qual_found)
        {
            PRT_CELL_SET("%s", dnx_field_bcm_qual_text(unit, bcm_qual_raw));
        }
        else
        {
            PRT_CELL_SET("-");
        }

        PRT_CELL_SET("%s", dnx_field_stage_text(unit, stage));

        /*
         * Print the other DBAL fields.
         */
        if (cs_qual_map_p->nof > 1)
        {
            /** Sanity check. */
            if (cs_qual_iter < 0)
            {
                SHR_ERR_EXIT(_SHR_E_INTERNAL, "cs_qual_iter %d not set.\n", cs_qual_iter);
            }
            while (cs_qual_iter < cs_qual_map_p->nof)
            {
                for (cs_qual_iter++; cs_qual_iter < cs_qual_map_p->nof; cs_qual_iter++)
                {
                    int cs_qual_iter_2;
                    int appeared_before = FALSE;
                    cs_dnx_qual = cs_qual_map_p->dnx_qual_array[cs_qual_iter];
                    if ((cs_dnx_qual == DNX_FIELD_CS_QUAL_INVALID) ||
                        (cs_dnx_qual < 0) || (cs_dnx_qual >= DNX_FIELD_CS_QUAL_NOF))
                    {
                        SHR_ERR_EXIT(_SHR_E_INTERNAL, "For qual \"%s\" stage \"%s\", nof %d, "
                                     "DNX qualifer %d (%d) is invalid.\n",
                                     dnx_field_bcm_qual_text(unit, cs_bcm_qual), dnx_field_stage_text(unit, stage),
                                     cs_qual_map_p->nof, cs_qual_iter, cs_dnx_qual);
                    }
                    /** Do not print one that appeared already again.*/
                    for (cs_qual_iter_2 = 0; cs_qual_iter_2 < cs_qual_iter; cs_qual_iter_2++)
                    {
                        if (cs_dnx_qual == cs_qual_map_p->dnx_qual_array[cs_qual_iter_2])
                        {
                            appeared_before = TRUE;
                            break;
                        }
                    }
                    if (appeared_before)
                    {
                        continue;
                    }
                    dbal_field_id = dnx_data_field_map.qual.cs_get(unit, stage, cs_dnx_qual)->dbal_field;
                    if (dbal_field_id != DBAL_FIELD_EMPTY)
                    {
                        break;
                    }
                }
                if (cs_qual_iter == cs_qual_map_p->nof)
                {
                    continue;
                }
                /** Sanity check. */
                if (dbal_field_id == DBAL_FIELD_EMPTY)
                {
                    SHR_ERR_EXIT(_SHR_E_INTERNAL, "dbal_field_id not set.\n");
                }
                rv = dbal_tables_field_size_get(unit, dnx_field_map_stage_info[stage].cs_table_id, dbal_field_id,
                                                TRUE, 0, 0, &dnx_cs_qual_size);
                SHR_IF_ERR_EXIT_EXCEPT_IF(rv, _SHR_E_NOT_FOUND);
                if (rv == _SHR_E_NOT_FOUND)
                {
                    continue;
                }

                PRT_ROW_ADD(PRT_ROW_SEP_NONE);
                PRT_CELL_SKIP(1);
                if (show_desc == TRUE)
                {
                    PRT_CELL_SKIP(1);
                }
                PRT_CELL_SET("%s", dbal_field_to_string(unit, dbal_field_id));
                /** DBAL field size, and bits in field for LR.*/
                if (is_lr_qual)
                {
                    int lr_offset;
                    int nof_mappings;
                    uint32 qual_size;

                    SHR_IF_ERR_EXIT(dnx_field_map_dnx_qual_size(unit, stage, lr_dnx_qual,
                                                                &nof_mappings, NULL, &qual_size));
                    if (nof_mappings != 1)
                    {
                        SHR_ERR_EXIT(_SHR_E_INTERNAL,
                                     "LR qualifier is split. Unexpected. Not supported in context selection.\n");
                    }
                    SHR_IF_ERR_EXIT(dnx_field_map_dnx_lr_qual_offset_in_lr_qual(unit, stage, lr_dnx_qual, &lr_offset));
                    PRT_CELL_SET("%d (%d:%d)", dnx_cs_qual_size, lr_offset, (lr_offset + qual_size - 1));
                }
                else
                {
                    PRT_CELL_SET("%d", dnx_cs_qual_size);
                }
                PRT_CELL_SKIP(2);
            }
        }
    }

exit:
    SHR_FUNC_EXIT;
}

static shr_error_e
diag_dnx_field_map_cs_cb(
    int unit,
    args_t * args,
    sh_sand_control_t * sand_control)
{

    char *match_n;
    dnx_field_stage_e stage_lower, stage_upper;
    dnx_field_stage_e stage_index;
    uint8 show_desc;

    PRT_INIT_VARS;
    SHR_FUNC_INIT_VARS(unit);

    SH_SAND_GET_UINT32_RANGE(DIAG_DNX_FIELD_OPTION_STAGE, stage_lower, stage_upper);
    SH_SAND_GET_STR("name", match_n);
    SH_SAND_GET_BOOL(DIAG_DNX_FIELD_OPTION_SHOW_DESC, show_desc);

    PRT_TITLE_SET("CS Map");
    PRT_COLUMN_ADD("bcmQualifier");
    if (show_desc == TRUE)
    {
        PRT_COLUMN_ADD_FLEX(PRT_FLEX_ASCII, "Description");
    }
    PRT_COLUMN_ADD("CS Field");
    PRT_COLUMN_ADD("Field Size (bits)");
    PRT_COLUMN_ADD("Raw");
    PRT_COLUMN_ADD("Stage");

    for (stage_index = stage_lower; stage_index <= stage_upper; stage_index++)
    {
        dnx_field_stage_e field_stage;
        SHR_IF_ERR_EXIT(diag_dnx_field_utils_stage_str_to_enum_val_conversion
                        (unit, Field_qualifier_diag_stage_enum_table[stage_index].string, &field_stage));

        if (dnx_field_map_stage_info[field_stage].cs_qual_map == NULL)
        {
            if (stage_lower == stage_upper)
            {
                SHR_ERR_EXIT(_SHR_E_INTERNAL, "stage \"%s\" has no context selection. \n",
                             dnx_field_stage_text(unit, field_stage));
            }
            else
            {
                continue;
            }
        }

        SHR_IF_ERR_EXIT(diag_dnx_field_map_cs_print(unit, match_n, field_stage, show_desc, prt_ctr));
    }

    PRT_COMMITX;

exit:
    PRT_FREE;
    SHR_FUNC_EXIT;
}

/**
 * \brief
 *   This function sets relevant information about usage of the initial keys
 *   by context modes (compare and hashing).
 * \param [in] unit - The unit number.
 * \param [in] do_row_sep_none_add_p - Flag to indicate whether to print
 *  a row without separator.
 * \param [in] context_id - Context Id for which information for
 *  initial key usage have to be presented.
 * \param [in] dnx_qual_id - DNX ID of the current qualifier.
 * \param [in] context_name_p - Name of the given context ID to be
 *  presented in the relevant cell.
 * \param [in] key_info_p - Key information about the current context mode, contains
 *  key_id, key_template and attach information.
 * \param [in] ctx_mode_name_p - Name of the current context mode, can be one
 *  of following (CMP1, CMP2 and HASH).
 * \param [in] prt_ctr - Pointer to control structure used by pretty printing,
 *  declared by PRT_INIT_VARS().
 *
 * \return
 *   Error code (as per 'shr_error_e').
 * \see
 *   shr_error_e
 */
static shr_error_e
diag_dnx_field_qualifier_ctx_mode_key_usage_cmp_hash_info_set(
    int unit,
    uint8 *do_row_sep_none_add_p,
    dnx_field_context_t context_id,
    dnx_field_qual_id_t dnx_qual_id,
    char *context_name_p,
    dnx_field_context_key_info_t * key_info_p,
    char *ctx_mode_name_p,
    prt_control_t * prt_ctr)
{
    uint32 qual_index;
    dnx_field_qual_t cs_qual;

    SHR_FUNC_INIT_VARS(unit);

    /** Iterate over all valid qualifiers for the current context mode. */
    for (qual_index = 0; qual_index < DNX_DATA_MAX_FIELD_GROUP_NOF_QUALS_PER_FG &&
         key_info_p->key_template.key_qual_map[qual_index].qual_type != DNX_FIELD_QUAL_TYPE_INVALID; qual_index++)
    {
        cs_qual = DNX_QUAL_ID(key_info_p->key_template.key_qual_map[qual_index].qual_type);
        /** Get information about the current Field action. */
        if (cs_qual == dnx_qual_id)
        {
            if (*do_row_sep_none_add_p)
            {
                PRT_ROW_ADD(PRT_ROW_SEP_NONE);
                /**
                 * In case one action is used by more than one FG, we have to skip cells:
                 * Qualifier ID, Name, Size.
                 */
                PRT_CELL_SKIP(3);
            }

            if (sal_strncmp(context_name_p, "", DBAL_MAX_STRING_LENGTH))
            {
                PRT_CELL_SET("CTX: %d / \"%s (%s)\"", context_id, context_name_p, ctx_mode_name_p);
            }
            else
            {
                PRT_CELL_SET("CTX: %d / \"N/A (%s)\"", context_id, ctx_mode_name_p);
            }

            *do_row_sep_none_add_p = TRUE;
            break;
        }
    }

exit:
    SHR_FUNC_EXIT;
}

/**
 * \brief
 *   This function displays FG IDs in which the specified by the caller Field qualifiers
 *   per qualifier ID or range of IDs  (optional) is used.
 * \param [in] unit - The unit number.
 * \param [in] dnx_qual_id - DNX ID of the current qualifier.
 * \param [in] prt_ctr - Pointer to control structure used by pretty printing,
 *  declared by PRT_INIT_VARS().
 *
 * \return
 *   Error code (as per 'shr_error_e').
 * \see
 *   shr_error_e
 */
static shr_error_e
diag_dnx_field_qualifier_list_fg_ctx_usage_cb(
    int unit,
    dnx_field_qual_id_t dnx_qual_id,
    prt_control_t * prt_ctr)
{
    dnx_field_group_full_info_t *fg_info_p = NULL;
    uint8 is_fg_allocated;
    dnx_field_qual_t fg_qual;
    int max_nof_fg, fg_id_index, fg_qual_iter;
    uint8 do_row_sep_none_add;
    uint8 max_nof_cs_lines, ctx_id_index;
    uint8 ctx_is_alloc;
    char context_name[DBAL_MAX_STRING_LENGTH];
    dnx_field_context_mode_t context_mode;
    dnx_field_context_compare_info_t compare_info;
    dnx_field_context_hashing_info_t hashing_info;
    char ctx_mode_name[DIAG_DNX_FIELD_UTILS_STR_SIZE];
    dnx_field_qual_class_e dnx_qual_class;

    SHR_FUNC_INIT_VARS(unit);

    SHR_ALLOC(fg_info_p, sizeof(dnx_field_group_full_info_t), "The FG full info", "%s%s%s\r\n", EMPTY, EMPTY, EMPTY);

    max_nof_fg = dnx_data_field.group.nof_fgs_get(unit);
    max_nof_cs_lines = dnx_data_field.common_max_val.nof_contexts_get(unit);

    do_row_sep_none_add = FALSE;

    /** Iterate over maximum number of FGs. */
    for (fg_id_index = 0; fg_id_index < max_nof_fg; fg_id_index++)
    {
        /** Check if the FG is being allocated. */
        SHR_IF_ERR_EXIT(dnx_algo_field_group_is_allocated(unit, fg_id_index, &is_fg_allocated));
        if (!is_fg_allocated)
        {
            /** If FG_ ID is not allocated, move to next FG ID. */
            continue;
        }

        /** Get information about the current Field Group. */
        SHR_IF_ERR_EXIT(dnx_field_group_get(unit, fg_id_index, fg_info_p));

        /** Iterate over all quals in the FG and stop if the qual is being found. */
        for (fg_qual_iter = 0; fg_qual_iter < DNX_DATA_MAX_FIELD_GROUP_NOF_QUALS_PER_FG &&
             fg_info_p->group_basic_info.dnx_quals[fg_qual_iter] != DNX_FIELD_QUAL_TYPE_INVALID; fg_qual_iter++)
        {
            dnx_qual_class = DNX_QUAL_CLASS(fg_info_p->group_basic_info.dnx_quals[fg_qual_iter]);
            fg_qual = DNX_QUAL_ID(fg_info_p->group_basic_info.dnx_quals[fg_qual_iter]);
            /** Get information about the current Field action. */
            if ((fg_qual == dnx_qual_id) && (dnx_qual_class == DNX_FIELD_QUAL_CLASS_USER))
            {
                if (do_row_sep_none_add)
                {
                    PRT_ROW_ADD(PRT_ROW_SEP_NONE);
                    /**
                     * In case one action is used by more than one FG, we have to skip cells:
                     * Qualifier ID, Name, Size.
                     */
                    PRT_CELL_SKIP(3);
                }

                if (sal_strncmp(fg_info_p->group_basic_info.name, "", sizeof(fg_info_p->group_basic_info.name)))
                {
                    PRT_CELL_SET("FG: %d / \"%s\"", fg_id_index, fg_info_p->group_basic_info.name);
                }
                else
                {
                    PRT_CELL_SET("FG: %d / \"N/A\"", fg_id_index);
                }

                do_row_sep_none_add = TRUE;
                break;
            }
        }
    }

    /** Iterate over maximum number of FGs. */
    for (ctx_id_index = 0; ctx_id_index < max_nof_cs_lines; ctx_id_index++)
    {
        /** Check if the current Context ID is allocated. */
        SHR_IF_ERR_EXIT(dnx_field_context_id_is_allocated(unit, DNX_FIELD_STAGE_IPMF1, ctx_id_index, &ctx_is_alloc));
        if (!ctx_is_alloc)
        {
            continue;
        }

        sal_memset(context_name, 0, sizeof(context_name));
        /** Take the name for current context from the SW state. */
        SHR_IF_ERR_EXIT(dnx_field_context_sw.context_info.name.
                        value.stringget(unit, ctx_id_index, DNX_FIELD_STAGE_IPMF1, context_name));

        SHR_IF_ERR_EXIT(dnx_field_context_mode_t_init(unit, &context_mode));
        /** If the current context is allocated, get the information about it. */
        SHR_IF_ERR_EXIT(dnx_field_context_mode_get(unit, DNX_FIELD_STAGE_IPMF1, ctx_id_index, &context_mode));

        /** Get information for compare, hash, state table modes for the current context. */
        SHR_IF_ERR_EXIT(diag_dnx_field_utils_cmp_hash_key_usage_info_get
                        (unit, ctx_id_index, context_mode, &compare_info, &hashing_info));

        /** In case one of the compare pairs has valid mode, present its information, otherwise skip it. */
        if (context_mode.context_ipmf1_mode.compare_mode_1 != DNX_FIELD_CONTEXT_COMPARE_MODE_NONE ||
            context_mode.context_ipmf1_mode.compare_mode_2 != DNX_FIELD_CONTEXT_COMPARE_MODE_NONE)
        {
            uint8 cmp_key_index;
            uint8 max_num_cmp_keys;
            uint8 cmp_pair_index;
            uint8 max_num_cmp_pairs;
            max_num_cmp_pairs = dnx_data_field.compare.nof_compare_pairs_get(unit);
            max_num_cmp_keys = dnx_data_field.compare.nof_keys_get(unit);

            for (cmp_pair_index = 0; cmp_pair_index < max_num_cmp_pairs; cmp_pair_index++)
            {
                for (cmp_key_index = 0; cmp_key_index < max_num_cmp_keys; cmp_key_index++)
                {
                    if (cmp_pair_index == DNX_FIELD_CONTEXT_COMPARE_MODE_PAIR_1)
                    {
                        sal_strncpy_s(ctx_mode_name, "CMP1", sizeof(ctx_mode_name));
                        SHR_IF_ERR_EXIT(diag_dnx_field_qualifier_ctx_mode_key_usage_cmp_hash_info_set
                                        (unit, &do_row_sep_none_add, ctx_id_index, dnx_qual_id, context_name,
                                         &compare_info.pair_1.key_info[cmp_key_index], ctx_mode_name, prt_ctr));
                    }
                    else
                    {
                        sal_strncpy_s(ctx_mode_name, "CMP2", sizeof(ctx_mode_name));
                        SHR_IF_ERR_EXIT(diag_dnx_field_qualifier_ctx_mode_key_usage_cmp_hash_info_set
                                        (unit, &do_row_sep_none_add, ctx_id_index, dnx_qual_id, context_name,
                                         &compare_info.pair_2.key_info[cmp_key_index], ctx_mode_name, prt_ctr));
                    }
                }
            }
        }

        /** In case hashing has valid mode, present its information, otherwise skip it. */
        if (context_mode.context_ipmf1_mode.hash_mode != DNX_FIELD_CONTEXT_HASH_MODE_DISABLED)
        {
            sal_strncpy_s(ctx_mode_name, "HASH", sizeof(ctx_mode_name));
            SHR_IF_ERR_EXIT(diag_dnx_field_qualifier_ctx_mode_key_usage_cmp_hash_info_set
                            (unit, &do_row_sep_none_add, ctx_id_index, dnx_qual_id, context_name,
                             &hashing_info.key_info, ctx_mode_name, prt_ctr));
        }
    }

exit:
    SHR_FREE(fg_info_p);
    SHR_FUNC_EXIT;
}

/**
 * \brief
 *   This function displays Field qualifiers per qualifier ID or range of IDs  (optional), specified by the caller.
 * \param [in] unit - The unit number.
 * \param [in] args -
 *   Null terminated string. Contains 'Options': List of arguments as shown on screen (typed by caller/user)
 * \param [in] sand_control -
 *   Control information related to each of the 'options' entered by the caller (and contained in
 *   'args')
 *
 * \return
 *   Error code (as per 'shr_error_e').
 * \see
 *   shr_error_e
 */
static shr_error_e
diag_dnx_field_qualifier_user_list_cb(
    int unit,
    args_t * args,
    sh_sand_control_t * sand_control)
{
    bcm_field_qualify_t qual_id_lower, qual_id_upper;
    int do_display;
    dnx_field_qual_id_t dnx_qual_id;
    dnx_field_user_qual_info_t user_qual_info;
    bcm_field_qualify_t qual_id;
    bcm_field_qualifier_info_get_t qual_info;

    PRT_INIT_VARS;
    SHR_FUNC_INIT_VARS(unit);
    SH_SAND_GET_UINT32_RANGE(DIAG_DNX_FIELD_OPTION_ID, qual_id_lower, qual_id_upper);

    PRT_TITLE_SET("FIELD_User_Defined_Qualifiers");
    PRT_COLUMN_ADD_FLEX(PRT_FLEX_ASCII, "Qualifier ID");
    PRT_COLUMN_ADD_FLEX(PRT_FLEX_ASCII, "Name");
    PRT_COLUMN_ADD_FLEX(PRT_FLEX_ASCII, "Size");
    PRT_COLUMN_ADD_FLEX(PRT_FLEX_ASCII, "FG / Context (mode)");

    do_display = FALSE;
    for (qual_id = (BCM_FIELD_FIRST_USER_QUALIFIER_ID + qual_id_lower);
         qual_id <= (BCM_FIELD_FIRST_USER_QUALIFIER_ID + qual_id_upper); qual_id++)
    {
       /**
        * Check if the specified qualifier ID or rage of qualifier IDs are valid.
        */
        dnx_qual_id = qual_id - dnx_data_field.qual.user_1st_get(unit);
        SHR_IF_ERR_EXIT(dnx_field_qual_sw_db.info.get(unit, dnx_qual_id, &user_qual_info));
        if (user_qual_info.valid == FALSE)
        {
            continue;
        }
        /** Get information about the current Field qualifier. */
        SHR_IF_ERR_EXIT(bcm_field_qualifier_info_get(unit, qual_id, bcmFieldStageCount, &qual_info));

        PRT_ROW_ADD(PRT_ROW_SEP_UNDERSCORE_BEFORE);
        PRT_CELL_SET("%d", dnx_qual_id);
       /**
        * Check if Field qualifier name is being provided, in case no set N/A as default value,
        * in other case set the provided name.
        */
        if (sal_strncmp((char *) (qual_info.name), "", sizeof(qual_info.name)))
        {
            PRT_CELL_SET("%s", qual_info.name);
        }
        else
        {
            PRT_CELL_SET("N/A");
        }

        PRT_CELL_SET("%d", qual_info.size);

        SHR_IF_ERR_EXIT(diag_dnx_field_qualifier_list_fg_ctx_usage_cb(unit, dnx_qual_id, prt_ctr));

        do_display = TRUE;
    }

    if (do_display)
    {
        PRT_COMMITX;
    }
    else
    {
        /*
         * If nothing was printed then just clear loaded PRT memory.
         * This could be left to 'exit' but it is clearer here.
         */
        PRT_FREE;
        LOG_CLI_EX("\r\n" "NO allocated field qualifiers were found on specified filters!! %s%s%s%s\r\n\n", EMPTY,
                   EMPTY, EMPTY, EMPTY);
    }

exit:
    PRT_FREE;
    SHR_FUNC_EXIT;
}

static sh_sand_man_t field_map_qual_bcm_man = {
    .brief = "Present valid bcm qualifiers and the set of dnx qualifier IDs",
    .full = "Present valid bcm qualifiers and the set of dnx qualifier IDs",
    .synopsis = "[name=<bcm qualifier name>] [stage=<IPMF1 | IPMF2 | IPMF3 | EPMF>] [class=<meta|layer|header>]\n",
    .examples = "\n" "name=InPort stage=ipmf1\n" "class=meta\n" "stage=ipmf1 \n" "stage=ipmf3 show_desc=false",
};

static shr_error_e
diag_dnx_field_map_qual_bcm_print(
    int unit,
    char *match_n,
    dnx_field_stage_e stage,
    dnx_field_qual_class_e in_class,
    uint8 show_desc,
    prt_control_t * prt_ctr)
{
    dnx_field_qual_class_e class;
    int nof_mappings;
    uint32 qual_sizes[DNX_FIELD_QAUL_MAX_NOF_MAPPINGS];
    uint32 qual_size_total;
    char qual_size_string[DIAG_DNX_FIELD_UTILS_STR_SIZE];
    bcm_field_qualify_t bcm_qual;
    bcm_field_qualify_t bcm_qual_raw;
    dnx_field_qual_t dnx_qual;
    dnx_field_qual_t dnx_qual_raw;
    const dnx_field_qual_map_t *meta_qual_map_p = NULL;
    shr_error_e rv;

    bsl_severity_t original_severity_fld_proc = BSL_INFO;

    SHR_FUNC_INIT_VARS(unit);

    dnx_qual_raw = 0;

    for (bcm_qual = 0; bcm_qual < bcmFieldQualifyCount; bcm_qual++)
    {
        /** Don't start checking if the qualifier don't fit the filer. */
        if (!ISEMPTY(match_n) && !sal_strcasestr(dnx_field_bcm_qual_text(unit, bcm_qual), match_n))
        {
            continue;
        }

        rv = dnx_field_map_qual_bcm_to_dnx_int(unit, stage, FALSE, bcm_qual, &dnx_qual, &meta_qual_map_p);
        if (rv == _SHR_E_PARAM || rv == _SHR_E_NOT_FOUND)
        {
            continue;
        }
        SHR_IF_ERR_EXIT(rv);
        class = DNX_QUAL_CLASS(dnx_qual);
        if ((in_class != DNX_FIELD_QUAL_CLASS_NOF) && (class != in_class))
        {
            continue;
        }

        SHR_GET_SEVERITY_FOR_MODULE_SPECIFIC(BSL_LS_BCMDNX_FLDPROCDNX, original_severity_fld_proc);
        SHR_SET_SEVERITY_FOR_MODULE_SPECIFIC(BSL_LS_BCMDNX_FLDPROCDNX, bslSeverityFatal);
        rv = dnx_field_map_dnx_qual_size(unit, stage, dnx_qual, &nof_mappings, qual_sizes, &qual_size_total);
        /** Verify the qualifier is supported by this device */
        SHR_SET_SEVERITY_FOR_MODULE_SPECIFIC(BSL_LS_BCMDNX_FLDPROCDNX, original_severity_fld_proc);
        if (rv == _SHR_E_PARAM)
        {
            continue;
        }
        SHR_IF_ERR_EXIT(rv);
        SHR_IF_ERR_EXIT(diag_dnx_field_qualifier_string_size_split
                        (unit, nof_mappings, qual_sizes, qual_size_total, qual_size_string));

        PRT_ROW_ADD(PRT_ROW_SEP_NONE);
        PRT_CELL_SET("%s", dnx_field_bcm_qual_text(unit, bcm_qual));
        if (show_desc == TRUE)
        {
            PRT_CELL_SET("%s", bcm_qual_description[bcm_qual]);
        }
        PRT_CELL_SET("%s", qual_size_string);
        PRT_CELL_SET("%s", dnx_field_qual_class_text(class));
        /**
         * In case current qualifier is marked as basic_object, we should present it.
         * Otherwise we should find the basic qualifier for current BCM qual.
         */
        if (BCM_TO_DNX_IS_BAISC_OBJ(meta_qual_map_p->flags))
        {
            PRT_CELL_SET("%s", dnx_field_bcm_qual_text(unit, bcm_qual));
        }
        else
        {
            uint8 raw_qual_found = FALSE;
            for (bcm_qual_raw = 0; bcm_qual_raw < bcmFieldQualifyCount; bcm_qual_raw++)
            {
                rv = dnx_field_map_qual_bcm_to_dnx_int(unit, stage, FALSE, bcm_qual_raw, &dnx_qual_raw,
                                                       &meta_qual_map_p);
                if (rv == _SHR_E_PARAM || rv == _SHR_E_NOT_FOUND)
                {
                    continue;
                }
                SHR_IF_ERR_EXIT(rv);
                if (BCM_TO_DNX_IS_BAISC_OBJ(meta_qual_map_p->flags) && (dnx_qual == dnx_qual_raw))
                {
                    PRT_CELL_SET("%s", dnx_field_bcm_qual_text(unit, bcm_qual_raw));
                    raw_qual_found = TRUE;
                    break;
                }
            }

            /**
             * If no raw qualifier was found, it means that the current qualifier don't have
             * the macro BCM_TO_DNX_IS_BAISC_OBJ and in such case we present current BCM qual.
             */
            if (!raw_qual_found)
            {
                PRT_CELL_SET("%s", dnx_field_bcm_qual_text(unit, bcm_qual));
            }
        }
        PRT_CELL_SET("%s", dnx_field_dnx_qual_text(unit, dnx_qual));

        PRT_CELL_SET("%s", dnx_field_stage_text(unit, stage));
    }

exit:
    SHR_FUNC_EXIT;
}

static shr_error_e
diag_dnx_field_map_qual_bcm_cb(
    int unit,
    args_t * args,
    sh_sand_control_t * sand_control)
{
    char *match_n;
    dnx_field_qual_class_e in_class;
    dnx_field_stage_e stage_lower, stage_upper;
    dnx_field_stage_e stage_index;
    uint8 show_desc;

    PRT_INIT_VARS;
    SHR_FUNC_INIT_VARS(unit);

    SH_SAND_GET_UINT32_RANGE(DIAG_DNX_FIELD_OPTION_STAGE, stage_lower, stage_upper);
    SH_SAND_GET_ENUM("class", in_class);
    SH_SAND_GET_STR("name", match_n);
    SH_SAND_GET_BOOL(DIAG_DNX_FIELD_OPTION_SHOW_DESC, show_desc);

    PRT_TITLE_SET("Qualifier Map");
    PRT_COLUMN_ADD("bcmQualifer");
    if (show_desc == TRUE)
    {
        PRT_COLUMN_ADD_FLEX(PRT_FLEX_ASCII, "Description");
    }
    PRT_COLUMN_ADD("Size");
    PRT_COLUMN_ADD("Class");
    PRT_COLUMN_ADD("Raw");
    PRT_COLUMN_ADD("DNX Qualifier");
    PRT_COLUMN_ADD("Stage");

    for (stage_index = stage_lower; stage_index <= stage_upper; stage_index++)
    {
        dnx_field_stage_e field_stage;
        SHR_IF_ERR_EXIT(diag_dnx_field_utils_stage_str_to_enum_val_conversion
                        (unit, Field_qualifier_diag_stage_enum_table[stage_index].string, &field_stage));

        SHR_IF_ERR_EXIT(diag_dnx_field_map_qual_bcm_print(unit, match_n, field_stage, in_class, show_desc, prt_ctr));
    }

    PRT_COMMITX;

exit:
    PRT_FREE;
    SHR_FUNC_EXIT;
}

static sh_sand_man_t field_map_qual_dnx_man = {
    .brief = "Present valid dnx qualifiers info",
    .full = "Present valid dnx qualifiers and their parameters",
    .synopsis = "[name=<dnx qualifier name>] [stage=<IPMF1 | IPMF2 | IPMF3 | EPMF>] [class=<meta|layer|header>]\n",
    .examples = "\n" "name=IN_PORT stage=ipmf1 class=meta\n" "name=IN_PORT stage=ipmf1 ",
};

static shr_error_e
diag_dnx_field_map_qual_dnx_print(
    int unit,
    char *match_n,
    dnx_field_stage_e stage,
    dnx_field_qual_class_e in_class,
    prt_control_t * prt_ctr)
{
    int i_qual;
    dnx_field_qual_t *dnx_qual_list = NULL;
    int dnx_field_qual_num;
    CONST char *dnx_qual_name;
    int nof_mappings;
    uint32 qual_sizes[DNX_FIELD_QAUL_MAX_NOF_MAPPINGS];
    uint32 qual_size_total;
    int offsets[DNX_FIELD_QAUL_MAX_NOF_MAPPINGS];
    char qual_size_string[DIAG_DNX_FIELD_UTILS_STR_SIZE];
    char qual_offset_string[DIAG_DNX_FIELD_UTILS_STR_SIZE];
    bcm_field_qualify_t bcm_qual;
    uint8 bcm_qual_found;
    dnx_field_qual_class_e class;

    SHR_FUNC_INIT_VARS(unit);

    SHR_IF_ERR_EXIT(dnx_field_map_qual_list(unit, stage, &dnx_qual_list, &dnx_field_qual_num));

    for (i_qual = 0; i_qual < dnx_field_qual_num; i_qual++)
    {
        dnx_qual_name = dnx_field_dnx_qual_text(unit, dnx_qual_list[i_qual]);
        class = DNX_QUAL_CLASS(dnx_qual_list[i_qual]);

        if (!ISEMPTY(match_n) && !sal_strcasestr(dnx_qual_name, match_n))
            continue;

        if ((in_class != DNX_FIELD_QUAL_CLASS_NOF) && (class != in_class))
        {
            continue;
        }

        SHR_IF_ERR_EXIT(dnx_field_map_dnx_qual_size
                        (unit, stage, dnx_qual_list[i_qual], &nof_mappings, qual_sizes, &qual_size_total));
        SHR_IF_ERR_EXIT(diag_dnx_field_qualifier_string_size_split
                        (unit, nof_mappings, qual_sizes, qual_size_total, qual_size_string));
        SHR_IF_ERR_EXIT(dnx_field_map_dnx_qual_offset(unit, stage, dnx_qual_list[i_qual], &nof_mappings, offsets));
        SHR_IF_ERR_EXIT(diag_dnx_field_qualifier_string_offset_split(unit, nof_mappings, offsets, qual_offset_string));
        SHR_IF_ERR_EXIT(dnx_field_map_qual_dnx_to_bcm_int
                        (unit, stage, dnx_qual_list[i_qual], &bcm_qual, &bcm_qual_found));

        PRT_ROW_ADD(PRT_ROW_SEP_NONE);
        PRT_CELL_SET("%s", dnx_qual_name);
        PRT_CELL_SET("%s", dnx_field_qual_class_text(class));
        PRT_CELL_SET("%s", qual_size_string);
        PRT_CELL_SET("%s", qual_offset_string);
        if (bcm_qual_found)
        {
            PRT_CELL_SET("%s", dnx_field_bcm_qual_text(unit, bcm_qual));
        }
        else
        {
            PRT_CELL_SET("N/A");
        }

        PRT_CELL_SET("%s", dnx_field_stage_text(unit, stage));
    }

exit:
    if (dnx_qual_list != NULL)
        sal_free(dnx_qual_list);
    SHR_FUNC_EXIT;
}

static shr_error_e
diag_dnx_field_map_qual_dnx_cb(
    int unit,
    args_t * args,
    sh_sand_control_t * sand_control)
{
    char *match_n;
    dnx_field_qual_class_e in_class;
    dnx_field_stage_e stage_lower, stage_upper;
    dnx_field_stage_e stage_index;

    PRT_INIT_VARS;
    SHR_FUNC_INIT_VARS(unit);

    /** Get the inputs from Shell. */
    SH_SAND_GET_UINT32_RANGE(DIAG_DNX_FIELD_OPTION_STAGE, stage_lower, stage_upper);
    SH_SAND_GET_ENUM("class", in_class);
    SH_SAND_GET_STR("name", match_n);

    PRT_TITLE_SET("DNX Qualifier List");
    PRT_COLUMN_ADD("Field Name");
    PRT_COLUMN_ADD("Class");
    PRT_COLUMN_ADD("Size");
    PRT_COLUMN_ADD("Offset");
    PRT_COLUMN_ADD("BCM");
    PRT_COLUMN_ADD("Stage");

    for (stage_index = stage_lower; stage_index <= stage_upper; stage_index++)
    {
        dnx_field_stage_e field_stage;
        SHR_IF_ERR_EXIT(diag_dnx_field_utils_stage_str_to_enum_val_conversion
                        (unit, Field_qualifier_diag_stage_enum_table[stage_index].string, &field_stage));

        SHR_IF_ERR_EXIT(diag_dnx_field_map_qual_dnx_print(unit, match_n, field_stage, in_class, prt_ctr));
    }

    PRT_COMMITX;

exit:
    PRT_FREE;
    SHR_FUNC_EXIT;
}

static sh_sand_man_t field_map_qual_virtualwire_man = {
    .brief = "Present valid virtualwire qualifiers info",
    .full = "Present valid virtualwire qualifiers and their parameters",
    .synopsis = "[vw_name=<virtualwire name>] [stage=<IPMF1 | IPMF2 | IPMF3 | EPMF>] [id=<virtualwire id>]\n",
    .examples = "\n" "vw_name= stage=ipmf1 id=8292-8390",
};

static shr_error_e
diag_dnx_field_qualifier_virtualwire_print(
    int unit,
    uint32 qual_id_lower,
    uint32 qual_id_upper,
    char *vw_match_n,
    dnx_field_stage_e stage,
    prt_control_t * prt_ctr)
{
    int bcm_vw_qual_id;
    int nof_mappings;
    uint32 qual_sizes[DNX_FIELD_QAUL_MAX_NOF_MAPPINGS];
    uint32 qual_size_total;
    char qual_size_string[DIAG_DNX_FIELD_UTILS_STR_SIZE];
    const dnx_field_qual_map_t *meta_qual_map_p = NULL;

    SHR_FUNC_INIT_VARS(unit);

    for (bcm_vw_qual_id = qual_id_lower; bcm_vw_qual_id <= qual_id_upper; bcm_vw_qual_id++)
    {
        dnx_field_qual_t dnx_vw_qual;
        CONST char *vw_name;
        shr_error_e rv =
            dnx_field_map_qual_bcm_to_dnx_int(unit, stage, FALSE, bcm_vw_qual_id, &dnx_vw_qual, &meta_qual_map_p);
        if (rv == _SHR_E_PARAM || rv == _SHR_E_NOT_FOUND)
        {
            continue;
        }
        SHR_IF_ERR_EXIT(rv);

        vw_name = dnx_field_dnx_qual_text(unit, dnx_vw_qual);

        if (!ISEMPTY(vw_match_n) && !sal_strcasestr(vw_name, vw_match_n))
        {
            continue;
        }

        SHR_IF_ERR_EXIT(dnx_field_map_dnx_qual_size
                        (unit, stage, dnx_vw_qual, &nof_mappings, qual_sizes, &qual_size_total));
        SHR_IF_ERR_EXIT(diag_dnx_field_qualifier_string_size_split
                        (unit, nof_mappings, qual_sizes, qual_size_total, qual_size_string));

        PRT_ROW_ADD(PRT_ROW_SEP_NONE);
        PRT_CELL_SET("%d", bcm_vw_qual_id);
        PRT_CELL_SET("%s", vw_name);
        PRT_CELL_SET("%s", qual_size_string);
        PRT_CELL_SET("%s", dnx_field_stage_text(unit, stage));
    }

exit:
    SHR_FUNC_EXIT;
}

static shr_error_e
diag_dnx_field_qualifier_virtualwire_cb(
    int unit,
    args_t * args,
    sh_sand_control_t * sand_control)
{
    char *vw_match_n;
    dnx_field_stage_e stage_lower, stage_upper;
    dnx_field_stage_e stage_index;
    uint32 qual_id_lower, qual_id_upper;

    PRT_INIT_VARS;
    SHR_FUNC_INIT_VARS(unit);

    /** Get the inputs from Shell. */
    SH_SAND_GET_UINT32_RANGE(DIAG_DNX_FIELD_OPTION_STAGE, stage_lower, stage_upper);
    SH_SAND_GET_UINT32_RANGE(DIAG_DNX_FIELD_OPTION_ID, qual_id_lower, qual_id_upper);
    SH_SAND_GET_STR(DIAG_DNX_FIELD_OPTION_VW_NAME, vw_match_n);

    PRT_TITLE_SET("Virtual Wire Qualifier Map");
    PRT_COLUMN_ADD("Qualifier ID");
    PRT_COLUMN_ADD("VW Name");
    PRT_COLUMN_ADD("Size");
    PRT_COLUMN_ADD("Stage");

    for (stage_index = stage_lower; stage_index <= stage_upper; stage_index++)
    {
        dnx_field_stage_e field_stage;
        SHR_IF_ERR_EXIT(diag_dnx_field_utils_stage_str_to_enum_val_conversion
                        (unit, Field_qualifier_diag_stage_enum_table[stage_index].string, &field_stage));

        SHR_IF_ERR_EXIT(diag_dnx_field_qualifier_virtualwire_print
                        (unit, qual_id_lower, qual_id_upper, vw_match_n, field_stage, prt_ctr));
    }

    PRT_COMMITX;

exit:
    PRT_FREE;
    SHR_FUNC_EXIT;
}

/* *INDENT-OFF* */
/*
 * Global and Static
 * {
 */
/*
 * }
 */


/*
 * Globals required at end because they reference static procedures/tables above.
 * {
 */
/**
 * \brief
 *   List of shell options for 'qualifier' shell commands (bcm, dnx)
 */

static sh_sand_cmd_t sh_dnx_field_qualifier_cmds[] = {
    {"BCM",      diag_dnx_field_map_qual_bcm_cb,        NULL, field_map_qualifier_bcm_options,          &field_map_qual_bcm_man},
    {"DNX",      diag_dnx_field_map_qual_dnx_cb,        NULL, field_map_qualifier_dnx_options,          &field_map_qual_dnx_man},
    {NULL}
};

sh_sand_cmd_t Sh_dnx_field_qualifier_cmds[] = {
    {"ContextSelect", diag_dnx_field_map_cs_cb, NULL,  field_map_cs_options,      &field_map_cs_man},
    {"PReDefined",     NULL,            sh_dnx_field_qualifier_cmds, NULL, &field_map_qual_man},
    {"USeR",     diag_dnx_field_qualifier_user_list_cb, NULL, Field_qualifier_user_list_options,    &Field_qualifier_user_list_man},
    {"VirtualWire",     diag_dnx_field_qualifier_virtualwire_cb, NULL, field_map_qualifier_virtualwire_options,    &field_map_qual_virtualwire_man},
    {NULL}
};
/* *INDENT-ON* */
/*
 * }
 */
