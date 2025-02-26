/** \file init_pemla.c
 *
 * DNX pemla init and deinit sequence functions.
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
#define BSL_LOG_MODULE BSL_LS_BCMDNX_INITSEQDNX

/*
 * Include files.
 * {
 */
/** allow drv.h include explicitly */
#ifdef _SOC_DRV_H
#undef _SOC_DRV_H
#endif

#include <sal/core/libc.h>
#include <soc/sand/shrextend/shrextend_debug.h>
#include <soc/drv.h> /** needed for soc property functions */
#include <soc/dnx/dbal/dbal.h>
#include <soc/dnx/dnx_data/auto_generated/dnx_data_device.h>
#include <soc/dnx/dnx_data/auto_generated/dnx_data_dev_init.h>
#include <soc/dnxc/swstate/dnxc_sw_state_utils.h>
#include <soc/dnx/pemladrv/pemladrv.h>
#include <shared/dbx/dbx_file.h>
#include <shared/utilex/utilex_str.h>
#include <include/soc/dnx/dnx_data/auto_generated/dnx_data_headers.h>
#include <soc/dnx/pemladrv/auto_generated/pemladrv.h>
#include <soc/sand/sand_signals.h>
#include <soc/dnx/dnx_data/auto_generated/dnx_data_pp.h>
#include <soc/dnx/kbp/kbp_common.h>
#include <appl/diag/system.h>
#include <soc/dnx/dnx_data/auto_generated/dnx_data_debug.h>
#include <soc/dnx/dnx_data/auto_generated/dnx_data_dev_init.h>
#include <soc/dnx/swstate/auto_generated/access/pp_access.h>
#include <soc/dnx/pemladrv/auto_generated/dbx_pre_compiled_dnx2_ucode.h>
#include "init_pemla.h"
#ifdef BCM_SHARED_LIB_SDK
#include <src/sal/appl/pre_compiled_bridge_router_pemla_init_db.h>
#endif /* BCM_SHARED_LIB_SDK */

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

typedef enum
{
    DNX_TCAM_STAGE_VT1 = 0,
    DNX_TCAM_STAGE_VT23 = 1,
    DNX_TCAM_STAGE_VT45 = 2,
    DNX_TCAM_STAGE_FWD12 = 3,
    DNX_TCAM_NOF_STAGES = 4
} dnx_tcam_stages_e;

extern void dbal_pemla_status_set(
    int unit,
    dbal_status_e status);

extern shr_error_e dbal_pemla_tables_init(
    int unit);

static shr_error_e
dnx_init_pemla_get_ucode_filepath(
    int unit,
    const char *ucode_file_name,
    char *rel_file_path,
    char *file_path,
    uint32 *use_file)
{
    int copied_chars;
    const char *ucode_rel_path;

    SHR_FUNC_INIT_VARS(unit);

    if (sal_strncmp(ucode_file_name, EMPTY, 2) == 0)
    {
        ucode_rel_path = dnx_data_pp.application.ucode_get(unit)->relative_path;
    }
    else
    {
        ucode_rel_path = ucode_file_name;
    }

    copied_chars = sal_snprintf(rel_file_path, RHFILE_MAX_SIZE, "%s", ucode_rel_path);

    if ((copied_chars < 0) || (copied_chars >= RHFILE_MAX_SIZE))
    {
        SHR_ERR_EXIT(_SHR_E_PARAM, "ERROR: Relative path to uCode file too long: %s.\n", rel_file_path);
    }

    /*
     * get ucode full path
     */
    SHR_SET_CURRENT_ERR(dbx_file_get_file_path
                        (unit, rel_file_path, CONF_OPEN_PER_DEVICE | CONF_OPEN_CURRENT_DEVICE_ONLY, file_path));
    if (SHR_FUNC_VAL_IS(_SHR_E_NOT_FOUND))
    {
        if (dnx_data_dev_init.general.feature_get(unit, dnx_data_dev_init_general_application_v1))
        {
            if (pre_compiled_dnx2_pemla_db_string_exist(unit, rel_file_path))
            {
                *use_file = FALSE;
                SHR_SET_CURRENT_ERR(_SHR_E_NONE);
            }
        }
        if (*use_file == TRUE)
        {
            SHR_ERR_EXIT(_SHR_E_NOT_FOUND, "ucode file does not exist: %s\n", file_path);
        }
    }
    else if (SHR_GET_CURRENT_ERR() != _SHR_E_NONE)
    {
        SHR_IF_ERR_EXIT(SHR_GET_CURRENT_ERR());
    }
#ifndef BCM_SHARED_LIB_SDK
    /** Check that ucode file exists  */
    else
    {
        FILE *file = sal_fopen(file_path, "r");
        if (!file)
        {
            SHR_ERR_EXIT(_SHR_E_NOT_FOUND, "can not open ucode file: %s\n", file_path);
        }
        else
        {
            fclose(file);
        }
    }
#endif /* BCM_SHARED_LIB_SDK */

exit:
    SHR_FUNC_EXIT;
}

#ifndef BCM_SHARED_LIB_SDK
static shr_error_e
dnx_init_pemla_get_ucode_file(
    int unit,
    uint32 use_file,
    const char *file_name,
    const char *rel_file_path,
    FILE ** fp,
    char ***lines,
    int *read_lines)
{
    const char *fname;

    SHR_FUNC_INIT_VARS(unit);

    if (use_file)
    {
        if (file_name != NULL)
        {
            fname = file_name;
        }
        else
        {
            SHR_ERR_EXIT(_SHR_E_PARAM, "ERROR: ucode file name must be provided.\n");
        }

        if ((*fp = sal_fopen((char *) fname, "r")) == NULL)
        {
            /*
             * printf("Can't open file '%s'. Exit.\n", file_name);
             */
            SHR_ERR_EXIT(_SHR_E_PARAM, "ERROR: failed to read from %s.\n", fname);
        }
    }
    else
    {
        if (dnx_data_dev_init.general.feature_get(unit, dnx_data_dev_init_general_application_v1))
        {
            *lines = pre_compiled_dnx2_pemla_db_ucode_get(unit, rel_file_path);
        }
        if (*lines == NULL)
        {
            *read_lines = -1;
        }
    }

exit:
    SHR_FUNC_EXIT;
}

static shr_error_e
soc_prop_verify(
    int unit,
    uint32 use_file,
    const char *rel_file_path,
    const char *file_name)
{
    FILE *fp = NULL;
    char **lines = NULL;
    char *line = NULL;          /* input line */
    int read_lines = 0;
    int line_no = 0;
    int read_soc = 0;

    SHR_FUNC_INIT_VARS(unit);

    SHR_IF_ERR_EXIT(dnx_init_pemla_get_ucode_file(unit, use_file, file_name, rel_file_path, &fp, &lines, &read_lines));

    if (use_file)
    {
        SHR_ALLOC_ERR_EXIT(line, sizeof(*line) * SHR_SAND_DEFAULT_MAX_STRING_OPERATION_LENGTH,
                           "line for soc_prop_verify", "%s%s%s", "line", EMPTY, EMPTY);
    }

    /*
     * Read one line per iteration and parse it
     */
    while (read_lines >= 0)
    {
        if (use_file)
        {
            sal_memset(line, 0, sizeof(*line) * SHR_SAND_DEFAULT_MAX_STRING_OPERATION_LENGTH);
            if (sal_fgets(line, sizeof(*line) * SHR_SAND_DEFAULT_MAX_STRING_OPERATION_LENGTH, fp) == NULL)
            {
                read_lines = -1;
                continue;
            }
        }
        else
        {
            line = lines[line_no];
            if (line == NULL)
            {
                read_lines = -1;
                continue;
            }
        }
        /*
         * DBUG INFO
         */
        line_no++;
        {
            /*
             * Skip empty lines and comments
             */
            if ((sal_strnlen(line, SHR_SAND_DEFAULT_MAX_STRING_OPERATION_LENGTH) == 0) || (line[0] == '\n')
                || (line[0] == '#'))
            {
            }
            else if (sal_strncmp(line, "/*PEMLA_SOC_START", sizeof("/*PEMLA_SOC_START") - 1) == 0)
            {
                read_soc = 1;
            }
            else if (sal_strncmp(line, "PEMLA_SOC_END*/", sizeof("PEMLA_SOC_END*/") - 1) == 0)
            {
                break;
            }
            else if (read_soc)
            {
                char soc_name[SOC_PROPERTY_NAME_MAX];
                char soc_pemla_value[SOC_PROPERTY_VALUE_MAX];
                char *soc_sdk_value;
                sal_memset(soc_name, 0, sizeof(soc_name));
                sal_memset(soc_pemla_value, 0, sizeof(soc_pemla_value));
                if (sscanf(line, "%s %s", soc_name, soc_pemla_value) != 2)
                {
                    SHR_ERR_EXIT(_SHR_E_PARAM, "Bad line format. Skip and continue with next line.\n");
                }
                else
                {
                    soc_sdk_value = soc_property_get_str(unit, soc_name);
                    if (soc_sdk_value)
                    {
                        if (sal_strncmp(soc_pemla_value, soc_sdk_value, sizeof(soc_pemla_value)) != 0)
                        {
                            SHR_ERR_EXIT(_SHR_E_PARAM,
                                         "SOC property values not aligned. In PEMLA %s = %s, but in SDK it is %s \n",
                                         soc_name, soc_pemla_value, soc_sdk_value);
                        }
                    }
                    else
                    {
                        SHR_ERR_EXIT(_SHR_E_PARAM,
                                     "SOC property values not defined. In PEMLA %s = %s, but in SDK it is %s \n",
                                     soc_name, soc_pemla_value, soc_sdk_value);
                    }
                }
            }
        }
    }   /* End of while loop over all lines in file */

exit:
    if (use_file)
    {
        if (fp)
        {
            fclose(fp);
        }
        SHR_FREE(line);
    }
    SHR_FUNC_EXIT;
}

shr_error_e
pemla_patches_get(
    int unit,
    dnx_pemla_patch * pemla_patches,
    int *nof_patches)
{
    FILE *fp = NULL;
    char **lines = NULL;
    char *line = NULL;          /* input line */
    int read_lines = 0;
    int line_no = 0;
    int read_patch = 0;
    uint32 use_file = TRUE;
    char rel_file_path[RHFILE_MAX_SIZE];
    char file_path[RHFILE_MAX_SIZE];

    SHR_FUNC_INIT_VARS(unit);

    SHR_IF_ERR_EXIT(dnx_init_pemla_get_ucode_filepath(unit, EMPTY, rel_file_path, file_path, &use_file));

    SHR_IF_ERR_EXIT(dnx_init_pemla_get_ucode_file(unit, use_file, file_path, rel_file_path, &fp, &lines, &read_lines));

    if (use_file)
    {
        SHR_ALLOC_ERR_EXIT(line, sizeof(*line) * SHR_SAND_DEFAULT_MAX_STRING_OPERATION_LENGTH,
                           "line for pemla_patches_get", "%s%s%s", "line", EMPTY, EMPTY);
    }

    /*
     * Read one line per iteration and parse it
     */
    while (read_lines >= 0)
    {
        if (use_file)
        {
            sal_memset(line, 0, sizeof(*line) * SHR_SAND_DEFAULT_MAX_STRING_OPERATION_LENGTH);
            if (sal_fgets(line, sizeof(*line) * SHR_SAND_DEFAULT_MAX_STRING_OPERATION_LENGTH, fp) == NULL)
            {
                read_lines = -1;
                continue;
            }
        }
        else
        {
            line = lines[line_no];
            if (line == NULL)
            {
                read_lines = -1;
                continue;
            }
        }
        /*
         * DBUG INFO
         */
        line_no++;
        {
            /*
             * Skip empty lines and comments
             */
            if ((sal_strnlen(line, SHR_SAND_DEFAULT_MAX_STRING_OPERATION_LENGTH) == 0) || (line[0] == '\n')
                || (line[0] == '#'))
            {
            }
            else if (sal_strncmp(line, "/*PEMLA_PATCHS_START", sizeof("/*PEMLA_PATCHS_START") - 1) == 0)
            {
                read_patch = 1;
            }
            else if (sal_strncmp(line, "PEMLA_PATCHS_END*/", sizeof("PEMLA_PATCHS_END*/") - 1) == 0)
            {
                break;
            }
            else if (read_patch)
            {
                if ((*nof_patches) < MAX_NOF_PEMLA_PATCHES)
                {
                    sal_memset(pemla_patches[*nof_patches].str, 0, sizeof(pemla_patches[*nof_patches].str));
                    if (sscanf(line, "%d %[^\n]", &pemla_patches[*nof_patches].id, pemla_patches[*nof_patches].str) !=
                        2)
                    {
                        SHR_ERR_EXIT(_SHR_E_PARAM, "Bad line format. Skip and continue with next line.\n");
                    }
                    (*nof_patches)++;
                }
                else
                {
                    SHR_ERR_EXIT(_SHR_E_PARAM,
                                 "Too many patches included, please update MAX_NOF_PEMLA_PATCHES value\n");
                }
            }
        }
    }   /* End of while loop over all lines in file */

exit:
    if (use_file)
    {
        if (fp)
        {
            fclose(fp);
        }
        if (line)
        {
            SHR_FREE(line);
        }
    }
    SHR_FUNC_EXIT;
}

/**
* /brief
*  Gets the build release version
*
* \param [in] unit         - Device ID
* \param [in] build_release - Input string.
* \param [out] internal_build_release - Buffer to store the build release version
*
* \return
*   shr_error_e - Error Type
* \remark
*   * None
* \see
*   * None
*/
static shr_error_e
dnx_init_pemla_build_release_version_get(
    int unit,
    char *build_release,
    char *internal_build_release)
{
    uint32 index = 0;
    uint32 begin_from_id = 0;
    uint32 end_at_id = 0;
    uint32 build_release_len = 0;

    SHR_FUNC_INIT_VARS(unit);

    build_release_len = sal_strnlen(build_release, SOC_PROPERTY_VALUE_MAX);
    for (index = 0; index < build_release_len; index++)
    {
        if (build_release[index] == '-' && begin_from_id == 0)
        {
            begin_from_id = index + 1;
        }
        else if (build_release[index] == '_')
        {
            end_at_id = index;
        }
    }

    /*
     * This means we do not have hash at the end of the string.
     */
    if (end_at_id == 0)
    {
        end_at_id = build_release_len;
    }

    sal_strncpy(internal_build_release, &build_release[begin_from_id], (end_at_id - begin_from_id));

    SHR_EXIT();
exit:
    SHR_FUNC_EXIT;
}

shr_error_e
dnx_init_pemla_release_verify(
    int unit,
    uint32 use_file,
    const char *rel_file_path,
    const char *file_name)
{
    FILE *fp = NULL;
    char **lines = NULL;
    char *line = NULL;          /* input line */
    int read_lines = 0;
    int line_no = 0;
    int read_sdk_version = 0;
    VersionInfo *pemla_version;
    char dummy[SOC_PROPERTY_NAME_MAX];
    char sdk_version_value[SOC_PROPERTY_VALUE_MAX];
    int sdk_match = 0;
    char chip_name[SOC_PROPERTY_VALUE_MAX];
    char chip_revision[SOC_PROPERTY_VALUE_MAX];
    char pemla_chip_name[SOC_PROPERTY_VALUE_MAX];
    char pemla_chip_revision[SOC_PROPERTY_VALUE_MAX];
    int chip_dev, pemla_chip_dev;
    char internal_build_release[SOC_PROPERTY_VALUE_MAX];
    char internal_sdk_version_value[SOC_PROPERTY_VALUE_MAX];

    SHR_FUNC_INIT_VARS(unit);

    sal_memset(dummy, 0, sizeof(dummy));
    sal_memset(sdk_version_value, 0, sizeof(sdk_version_value));
    sal_memset(chip_name, 0, sizeof(chip_name));
    sal_memset(chip_revision, 0, sizeof(chip_revision));
    sal_memset(pemla_chip_name, 0, sizeof(pemla_chip_name));
    sal_memset(pemla_chip_revision, 0, sizeof(pemla_chip_revision));
    sal_memset(internal_build_release, 0, sizeof(internal_build_release));
    sal_memset(internal_sdk_version_value, 0, sizeof(internal_sdk_version_value));

    SHR_IF_ERR_EXIT(dnx_get_version(unit, 0, &pemla_version));

    SHR_IF_ERR_EXIT(dnx_init_pemla_get_ucode_file(unit, use_file, file_name, rel_file_path, &fp, &lines, &read_lines));

    if (use_file)
    {
        SHR_ALLOC_ERR_EXIT(line, sizeof(*line) * SHR_SAND_DEFAULT_MAX_STRING_OPERATION_LENGTH,
                           "line for dnx_init_pemla_release_verify", "%s%s%s", "line", EMPTY, EMPTY);
    }

    /*
     * Read one line per iteration and parse it
     */
    while (read_lines >= 0)
    {
        if (use_file)
        {
            sal_memset(line, 0, sizeof(*line) * SHR_SAND_DEFAULT_MAX_STRING_OPERATION_LENGTH);
            if (sal_fgets(line, sizeof(*line) * SHR_SAND_DEFAULT_MAX_STRING_OPERATION_LENGTH, fp) == NULL)
            {
                read_lines = -1;
                continue;
            }
        }
        else
        {
            line = lines[line_no];
            if (line == NULL)
            {
                read_lines = -1;
                continue;
            }
        }
        /*
         * DBUG INFO
         */
        line_no++;
        {
            if ((sal_strnlen(line, SHR_SAND_DEFAULT_MAX_STRING_OPERATION_LENGTH) == 0) || (line[0] == '\n')
                || (line[0] == '#'))
            {
                /*
                 * Skip empty lines and comments
                 */
            }
            else if (sal_strncmp(line, "/*SDK_VERSION_START", sizeof("/*SDK_VERSION_START") - 1) == 0)
            {
                read_sdk_version = 1;
            }
            else if (sal_strncmp(line, "SDK_VERSION_END*/", sizeof("SDK_VERSION_END*/") - 1) == 0)
            {
                read_sdk_version = 0;
                break;
            }
            else if (read_sdk_version)
            {
                SHR_IF_ERR_EXIT(dnx_init_pemla_build_release_version_get(unit, _build_release, internal_build_release));
                if (sscanf(line, "%s %s", dummy, sdk_version_value) != 2)
                {
                    SHR_ERR_EXIT(_SHR_E_PARAM, "Bad line format.\n");
                }
                else
                {
                    SHR_IF_ERR_EXIT(dnx_init_pemla_build_release_version_get
                                    (unit, sdk_version_value, internal_sdk_version_value));
                    if (sal_strncmp(internal_sdk_version_value, internal_build_release, sizeof(internal_build_release))
                        != 0)
                    {
                        SHR_ERR_EXIT(_SHR_E_PARAM, "SDK version is not aligned: SDK(%s) != UCODE(%s).\n",
                                     internal_build_release, internal_sdk_version_value);
                    }
                    else
                    {
                        sdk_match = 1;
                    }
                }

            }
        }
    }

    if (!sdk_match)
    {
        SHR_ERR_EXIT(_SHR_E_PARAM, "Missing SDK version validation.\n");
    }

    /** construct file name using the device ID and revision */
    if (sscanf(soc_dev_name(unit), "BCM8%[^_]_%s", chip_name, chip_revision) != 2)
    {
        SHR_ERR_EXIT(_SHR_E_PARAM, "Bad device name format.\n");
    }
    chip_dev = sal_strtoul(chip_name, NULL, 16);
    chip_dev &= (0xFFFF << dnx_data_device.general.nof_sku_bits_get(unit));
    chip_revision[1] = '0';

    if (sscanf(pemla_version->device_str, "%[^_]_%s", pemla_chip_name, pemla_chip_revision) != 2)
    {
        SHR_ERR_EXIT(_SHR_E_PARAM, "Bad pemla device name format.\n");
    }
    pemla_chip_dev = sal_strtoul(pemla_chip_name, NULL, 16);
    /** change lower case letter do upper case */
    utilex_str_to_upper(pemla_chip_revision);

    if ((chip_dev != pemla_chip_dev)
        && (sal_strncmp(chip_revision, pemla_chip_revision, sizeof(pemla_chip_revision) - 1) != 0))
    {
        SHR_ERR_EXIT(_SHR_E_PARAM, "Device version is not alidned: Device(%s) != UCODE(%s).\n", soc_dev_name(unit),
                     pemla_version->device_str);
    }

exit:
    if (use_file)
    {
        if (fp)
        {
            fclose(fp);
        }
        SHR_FREE(line);
    }
    SHR_FUNC_EXIT;
}
#endif /* BCM_SHARED_LIB_SDK */

/**
* /brief
*  Check if Stages that cannot access PEM set with disable
*
* \param [in] unit         - Device ID
*
* \return
*   shr_error_e - Error Type
* \remark
*   * None
* \see
*   * None
*/
static shr_error_e
dnx_init_pemla_first_stage_pem_invalid_verify(
    int unit)
{
    uint32 entry_handle_id = 0;
    uint32 pem_enable = 0;
    SHR_FUNC_INIT_VARS(unit);
    DBAL_FUNC_INIT_VARS(unit);

    SHR_IF_ERR_EXIT(DBAL_HANDLE_ALLOC(unit, DBAL_TABLE_VTT1_PEM_CONTROLLER, &entry_handle_id));

    dbal_entry_key_field32_set(unit, entry_handle_id, DBAL_FIELD_CORE_ID, 0);
    dbal_value_field32_request(unit, entry_handle_id, DBAL_FIELD_PEM_ENABLED, INST_SINGLE, &pem_enable);
    SHR_IF_ERR_EXIT(dbal_entry_get(unit, entry_handle_id, DBAL_COMMIT));
    if (pem_enable)
    {
        SHR_ERR_EXIT(_SHR_E_CONFIG, "ucode contains PEM access on VTT1 - This is not allowed\n");
    }

exit:
    DBAL_FUNC_FREE_VARS SHR_FUNC_EXIT;
}

shr_error_e
dnx_init_pemla_custom_init(
    int unit,
    const char *ucode_file_name)
{
    char rel_file_path[RHFILE_MAX_SIZE];
    uint32 use_file = TRUE;
    char file_path[RHFILE_MAX_SIZE];

    SHR_FUNC_INIT_VARS(unit);

    SHR_IF_ERR_EXIT(dnx_init_pemla_get_ucode_filepath(unit, ucode_file_name, rel_file_path, file_path, &use_file));

    SHR_IF_ERR_EXIT(dnx_pemladrv_init(unit, sw_state_is_warm_boot(unit), use_file, rel_file_path, file_path));

#ifndef BCM_SHARED_LIB_SDK
    /*
     * Verify PEMLA and SDK versions
     */
    SHR_IF_ERR_EXIT(dnx_init_pemla_release_verify(unit, use_file, rel_file_path, file_path));
    /*
     * verify soc_properties according to uCode
     */
    SHR_IF_ERR_EXIT(soc_prop_verify(unit, use_file, rel_file_path, file_path));
#endif /* BCM_SHARED_LIB_SDK */

    if (dnx_data_debug.feature.feature_get(unit, dnx_data_debug_feature_pem_vt_init_fix))
    {
        SHR_IF_ERR_EXIT(dnx_init_pemla_first_stage_pem_invalid_verify(unit));
    }

    /*
     * This command is here instead of being in dbal init sequence,
     * as DBAL init sequence runs before pemla init sequence, but the dbal pemla
     * verify needs to be run after pemla init.
     */
    SHR_IF_ERR_EXIT(dbal_pemla_tables_init(unit));

    dbal_pemla_status_set(unit, DBAL_STATUS_DBAL_INIT_DONE);

exit:
    SHR_FUNC_EXIT;
}

/**
* /brief
*  Converts TCAM stage to relevant DBAL table
*
* \param [in] unit         - Device ID
* \param [in] tcam_stage   - tcam stage to convert
* \param [out] dbal_table_id  - The converted DBAL table
*
* \return
*   shr_error_e - Error Type
* \remark
*   * None
* \see
*   * None
*/
static shr_error_e
dnx_init_pemla_stage_to_tcam_kbr_info_table(
    int unit,
    dnx_tcam_stages_e tcam_stage,
    dbal_tables_e * dbal_table_id)
{

    SHR_FUNC_INIT_VARS(unit);
    SHR_NULL_CHECK(dbal_table_id, _SHR_E_PARAM, "dbal_table_id");

    switch (tcam_stage)
    {
        case DNX_TCAM_STAGE_VT1:
        {
            *dbal_table_id = DBAL_TABLE_KLEAP_VT1_KBR_INFO;
            break;
        }
        case DNX_TCAM_STAGE_VT23:
        {
            *dbal_table_id = DBAL_TABLE_KLEAP_VT23_KBR_INFO;
            break;
        }
        case DNX_TCAM_STAGE_VT45:
        {
            *dbal_table_id = DBAL_TABLE_KLEAP_VT45_KBR_INFO;
            break;
        }
        case DNX_TCAM_STAGE_FWD12:
        {
            *dbal_table_id = DBAL_TABLE_KLEAP_FWD12_KBR_INFO;
            break;
        }
        default:
        {
            SHR_ERR_EXIT(_SHR_E_UNAVAIL, "Illegal tcam stage %d \n", tcam_stage);
            break;
        }
    }

exit:
    SHR_FUNC_EXIT;

}
/**
* /brief
*  Saves to swstate table information per app_db_id, its TCAM stage and relevant contexts
*
* \param [in] unit         - Device ID
* \param [in] dbal_stage   - dbal stage
*
* \return
*   shr_error_e - Error Type
* \remark
*   * None
* \see
*   * None
*/
static shr_error_e
dnx_init_pemla_tcam_tables(
    int unit,
    int dbal_stage)
{
    uint32 entry_handle_id, app_db_id, stage, tcam_stage, ffc_bitmap, oam_identification_enable, oam_tcam_db;
    uint32 ffc_bitmap_fwd[] = { 0, 0 };
    uint8 is_illegal;
    dbal_tables_e dbal_table_id;
    dbal_enum_value_field_tcam_stage_e previous_tcam_stage;
    dbal_enum_value_field_fwd1_context_id_e oam_context_profile;
    dbal_physical_tables_e kbrinfo_vt1[] = { 2 };
    dbal_physical_tables_e kbrinfo_vt23[] = { 5, 6 };
    dbal_physical_tables_e kbrinfo_vt45[] = { 5 };
    dbal_physical_tables_e kbrinfo_fwd12[] = { 2, 3, 12, 13 };
    int context_profile_max_val, context_profile, kbr_idx;
    int table_is_active = 0;

    SHR_FUNC_INIT_VARS(unit);
    DBAL_FUNC_INIT_VARS(unit);

    SHR_IF_ERR_EXIT(dnx_init_pemla_stage_to_tcam_kbr_info_table(unit, dbal_stage, &dbal_table_id));

    SHR_IF_ERR_EXIT(dbal_tables_is_table_active(unit, dbal_table_id, &table_is_active));

    if (!table_is_active)
    {
        SHR_EXIT();
    }

    SHR_IF_ERR_EXIT(dbal_tables_field_max_value_get
                    (unit, dbal_table_id, DBAL_FIELD_CONTEXT_PROFILE, TRUE, FALSE, 0, &context_profile_max_val));
    SHR_IF_ERR_EXIT(DBAL_HANDLE_ALLOC(unit, dbal_table_id, &entry_handle_id));
    for (context_profile = 0; context_profile < context_profile_max_val; context_profile++)
    {
        dbal_entry_key_field32_set(unit, entry_handle_id, DBAL_FIELD_CONTEXT_PROFILE, context_profile);
        switch (dbal_table_id)
        {
            case DBAL_TABLE_KLEAP_VT1_KBR_INFO:
            {
                for (kbr_idx = 0; kbr_idx < (sizeof(kbrinfo_vt1) / sizeof(dbal_physical_tables_e)); kbr_idx++)
                {
                    dbal_entry_key_field32_set(unit, entry_handle_id, DBAL_FIELD_KBR_IDX, kbrinfo_vt1[kbr_idx]);
                    SHR_IF_ERR_EXIT(dbal_entry_get(unit, entry_handle_id, DBAL_GET_ALL_FIELDS));
                    SHR_IF_ERR_EXIT(dbal_entry_handle_value_field32_get
                                    (unit, entry_handle_id, DBAL_FIELD_FFC_BITMAP, INST_SINGLE, &ffc_bitmap));
                    /** If the FFC Bitmap is different than 0, we have a lookup, so we store the app_db_id*/
                    if (ffc_bitmap != 0)
                    {
                        SHR_IF_ERR_EXIT(dbal_entry_handle_value_field32_get
                                        (unit, entry_handle_id, DBAL_FIELD_APP_DB_ID, INST_SINGLE, &app_db_id));

                        /** save in sw state information about which app_db_id to which stage it belongs*/
                        SHR_IF_ERR_EXIT(DBAL_HANDLE_CLEAR(unit, DBAL_TABLE_TCAM_APP_DB_TO_STAGE, entry_handle_id));
                        dbal_entry_key_field32_set(unit, entry_handle_id, DBAL_FIELD_APP_DB_ID, app_db_id);
                        /** Get the TCAM stage assigned to this APP_DB_ID, if it's none, then overwrite it.*/
                        SHR_IF_ERR_EXIT(dbal_entry_get(unit, entry_handle_id, DBAL_GET_ALL_FIELDS));
                        SHR_IF_ERR_EXIT(dbal_entry_handle_value_field32_get
                                        (unit, entry_handle_id, DBAL_FIELD_TCAM_STAGE, INST_SINGLE,
                                         &previous_tcam_stage));
                        if ((previous_tcam_stage == DBAL_ENUM_FVAL_TCAM_STAGE_NONE)
                            || (previous_tcam_stage == DBAL_ENUM_FVAL_TCAM_STAGE_VT1))
                        {
                            dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_TCAM_STAGE, INST_SINGLE,
                                                         DBAL_ENUM_FVAL_TCAM_STAGE_VT1);
                            /** Save information to which context it belongs */
                            dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_RELEVANT_CONTEXT_PROFILE,
                                                         context_profile, TRUE);
                            SHR_IF_ERR_EXIT(dbal_entry_commit(unit, entry_handle_id, DBAL_COMMIT));
                        }
                        else
                        {
                            SHR_ERR_EXIT(_SHR_E_PARAM, "The given app_db_id [%d] already belongs to different stage \n",
                                         app_db_id);
                        }
                        SHR_IF_ERR_EXIT(DBAL_HANDLE_CLEAR(unit, dbal_table_id, entry_handle_id));
                    }
                }
                break;
            }
            case DBAL_TABLE_KLEAP_VT23_KBR_INFO:
            {
                for (kbr_idx = 0; kbr_idx < (sizeof(kbrinfo_vt23) / sizeof(dbal_physical_tables_e)); kbr_idx++)
                {
                    dbal_entry_key_field32_set(unit, entry_handle_id, DBAL_FIELD_KBR_IDX, kbrinfo_vt23[kbr_idx]);
                    SHR_IF_ERR_EXIT(dbal_entry_get(unit, entry_handle_id, DBAL_GET_ALL_FIELDS));
                    SHR_IF_ERR_EXIT(dbal_entry_handle_value_field32_get
                                    (unit, entry_handle_id, DBAL_FIELD_FFC_BITMAP, INST_SINGLE, &ffc_bitmap));
                    /** If the FFC Bitmap is different than 0, we have a lookup, so we store the app_db_id*/
                    if (ffc_bitmap != 0)
                    {
                        SHR_IF_ERR_EXIT(dbal_entry_handle_value_field32_get
                                        (unit, entry_handle_id, DBAL_FIELD_APP_DB_ID, INST_SINGLE, &app_db_id));
                        /** Get information about the stage*/
                        SHR_IF_ERR_EXIT(DBAL_HANDLE_CLEAR
                                        (unit, DBAL_TABLE_KLEAP_VT23_RESOURCES_MAPPING, entry_handle_id));
                        SHR_IF_ERR_EXIT(dbal_entry_get(unit, entry_handle_id, DBAL_GET_ALL_FIELDS));
                        SHR_IF_ERR_EXIT(dbal_entry_handle_value_field32_get
                                        (unit, entry_handle_id, DBAL_FIELD_KBR_SELECTOR, kbrinfo_vt23[kbr_idx],
                                         &stage));
                        tcam_stage =
                            (stage ==
                             DBAL_ENUM_FVAL_KLEAP_STAGE_SELECTOR_STAGE_A) ? DBAL_ENUM_FVAL_TCAM_STAGE_VT2 :
                            DBAL_ENUM_FVAL_TCAM_STAGE_VT3;

                        SHR_IF_ERR_EXIT(DBAL_HANDLE_CLEAR(unit, DBAL_TABLE_TCAM_APP_DB_TO_STAGE, entry_handle_id));
                        dbal_entry_key_field32_set(unit, entry_handle_id, DBAL_FIELD_APP_DB_ID, app_db_id);
                        /** Get the TCAM stage assigned to this APP_DB_ID, if it's none, then overwrite it.*/
                        SHR_IF_ERR_EXIT(dbal_entry_get(unit, entry_handle_id, DBAL_GET_ALL_FIELDS));
                        SHR_IF_ERR_EXIT(dbal_entry_handle_value_field32_get
                                        (unit, entry_handle_id, DBAL_FIELD_TCAM_STAGE, INST_SINGLE,
                                         &previous_tcam_stage));
                        if ((previous_tcam_stage == DBAL_ENUM_FVAL_TCAM_STAGE_NONE)
                            || (previous_tcam_stage == tcam_stage))
                        {
                            dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_TCAM_STAGE, INST_SINGLE,
                                                         tcam_stage);
                            dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_RELEVANT_CONTEXT_PROFILE,
                                                         context_profile, TRUE);
                            SHR_IF_ERR_EXIT(dbal_entry_commit(unit, entry_handle_id, DBAL_COMMIT));

                        }
                        else
                        {
                            SHR_ERR_EXIT(_SHR_E_PARAM, "The given app_db_id [%d] already belongs to different stage \n",
                                         app_db_id);
                        }
                        SHR_IF_ERR_EXIT(DBAL_HANDLE_CLEAR(unit, dbal_table_id, entry_handle_id));
                        dbal_entry_key_field32_set(unit, entry_handle_id, DBAL_FIELD_CONTEXT_PROFILE, context_profile);
                    }
                }
                break;
            }
            case DBAL_TABLE_KLEAP_VT45_KBR_INFO:
            {
                for (kbr_idx = 0; kbr_idx < (sizeof(kbrinfo_vt45) / sizeof(dbal_physical_tables_e)); kbr_idx++)
                {
                    dbal_entry_key_field32_set(unit, entry_handle_id, DBAL_FIELD_KBR_IDX, kbrinfo_vt45[kbr_idx]);
                    SHR_IF_ERR_EXIT(dbal_entry_get(unit, entry_handle_id, DBAL_GET_ALL_FIELDS));
                    SHR_IF_ERR_EXIT(dbal_entry_handle_value_field32_get
                                    (unit, entry_handle_id, DBAL_FIELD_FFC_BITMAP, INST_SINGLE, &ffc_bitmap));
                    /** If the FFC Bitmap is different than 0, we have a lookup, so we store the app_db_id*/
                    if (ffc_bitmap != 0)
                    {
                        SHR_IF_ERR_EXIT(dbal_entry_handle_value_field32_get
                                        (unit, entry_handle_id, DBAL_FIELD_APP_DB_ID, INST_SINGLE, &app_db_id));
                        /** Get information about the stage*/
                        SHR_IF_ERR_EXIT(DBAL_HANDLE_CLEAR
                                        (unit, DBAL_TABLE_KLEAP_VT45_RESOURCES_MAPPING, entry_handle_id));
                        SHR_IF_ERR_EXIT(dbal_entry_get(unit, entry_handle_id, DBAL_GET_ALL_FIELDS));
                        SHR_IF_ERR_EXIT(dbal_entry_handle_value_field32_get
                                        (unit, entry_handle_id, DBAL_FIELD_KBR_SELECTOR, kbrinfo_vt45[kbr_idx],
                                         &stage));
                        tcam_stage =
                            (stage ==
                             DBAL_ENUM_FVAL_KLEAP_STAGE_SELECTOR_STAGE_A) ? DBAL_ENUM_FVAL_TCAM_STAGE_VT4 :
                            DBAL_ENUM_FVAL_TCAM_STAGE_VT5;

                        SHR_IF_ERR_EXIT(DBAL_HANDLE_CLEAR(unit, DBAL_TABLE_TCAM_APP_DB_TO_STAGE, entry_handle_id));
                        dbal_entry_key_field32_set(unit, entry_handle_id, DBAL_FIELD_APP_DB_ID, app_db_id);
                        /** Get the TCAM stage assigned to this APP_DB_ID, if it's none, then overwrite it.*/
                        SHR_IF_ERR_EXIT(dbal_entry_get(unit, entry_handle_id, DBAL_GET_ALL_FIELDS));
                        SHR_IF_ERR_EXIT(dbal_entry_handle_value_field32_get
                                        (unit, entry_handle_id, DBAL_FIELD_TCAM_STAGE, INST_SINGLE,
                                         &previous_tcam_stage));
                        if ((previous_tcam_stage == DBAL_ENUM_FVAL_TCAM_STAGE_NONE)
                            || (previous_tcam_stage == tcam_stage))
                        {
                            dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_TCAM_STAGE, INST_SINGLE,
                                                         tcam_stage);
                            dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_RELEVANT_CONTEXT_PROFILE,
                                                         context_profile, TRUE);
                            SHR_IF_ERR_EXIT(dbal_entry_commit(unit, entry_handle_id, DBAL_COMMIT));

                        }
                        else
                        {
                            SHR_ERR_EXIT(_SHR_E_PARAM, "The given app_db_id [%d] already belongs to different stage \n",
                                         app_db_id);
                        }
                        SHR_IF_ERR_EXIT(DBAL_HANDLE_CLEAR(unit, dbal_table_id, entry_handle_id));
                    }
                }
                break;
            }
            case DBAL_TABLE_KLEAP_FWD12_KBR_INFO:
            {
                for (kbr_idx = 0; kbr_idx < (sizeof(kbrinfo_fwd12) / sizeof(dbal_physical_tables_e)); kbr_idx++)
                {
                    dbal_entry_key_field32_set(unit, entry_handle_id, DBAL_FIELD_FWD12_KBR_ID, kbrinfo_fwd12[kbr_idx]);
                    SHR_IF_ERR_EXIT(dbal_entry_get(unit, entry_handle_id, DBAL_GET_ALL_FIELDS));
                    SHR_IF_ERR_EXIT(dbal_entry_handle_value_field_arr32_get
                                    (unit, entry_handle_id, DBAL_FIELD_FFC_BITMAP, INST_SINGLE, ffc_bitmap_fwd));
                    /** If the FFC Bitmap is different than 0, we have a lookup, so we store the app_db_id*/
                    if ((ffc_bitmap_fwd[0] != 0) || (ffc_bitmap_fwd[1] != 0))
                    {
                        SHR_IF_ERR_EXIT(dbal_entry_handle_value_field32_get
                                        (unit, entry_handle_id, DBAL_FIELD_APP_DB_ID, INST_SINGLE, &app_db_id));
                        /** Get information about the stage*/
                        SHR_IF_ERR_EXIT(DBAL_HANDLE_CLEAR
                                        (unit, DBAL_TABLE_KLEAP_FWD12_RESOURCES_MAPPING, entry_handle_id));
                        SHR_IF_ERR_EXIT(dbal_entry_get(unit, entry_handle_id, DBAL_GET_ALL_FIELDS));
                        SHR_IF_ERR_EXIT(dbal_entry_handle_value_field32_get
                                        (unit, entry_handle_id, DBAL_FIELD_KBR_SELECTOR, kbrinfo_fwd12[kbr_idx],
                                         &stage));
                        tcam_stage =
                            (stage ==
                             DBAL_ENUM_FVAL_KLEAP_STAGE_SELECTOR_STAGE_A) ? DBAL_ENUM_FVAL_TCAM_STAGE_FWD1 :
                            DBAL_ENUM_FVAL_TCAM_STAGE_FWD2;

                        SHR_IF_ERR_EXIT(DBAL_HANDLE_CLEAR(unit, DBAL_TABLE_TCAM_APP_DB_TO_STAGE, entry_handle_id));
                        dbal_entry_key_field32_set(unit, entry_handle_id, DBAL_FIELD_APP_DB_ID, app_db_id);
                        /** Get the TCAM stage assigned to this APP_DB_ID, if it's none, then overwrite it.*/
                        SHR_IF_ERR_EXIT(dbal_entry_get(unit, entry_handle_id, DBAL_GET_ALL_FIELDS));
                        SHR_IF_ERR_EXIT(dbal_entry_handle_value_field32_get
                                        (unit, entry_handle_id, DBAL_FIELD_TCAM_STAGE, INST_SINGLE,
                                         &previous_tcam_stage));
                        if ((previous_tcam_stage == DBAL_ENUM_FVAL_TCAM_STAGE_NONE)
                            || (previous_tcam_stage == tcam_stage))
                        {
                            dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_TCAM_STAGE, INST_SINGLE,
                                                         tcam_stage);
                            dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_RELEVANT_CONTEXT_PROFILE,
                                                         context_profile, TRUE);
                            SHR_IF_ERR_EXIT(dbal_entry_commit(unit, entry_handle_id, DBAL_COMMIT));
                        }
                        else
                        {
                            SHR_ERR_EXIT(_SHR_E_PARAM, "The given app_db_id [%d] already belongs to different stage \n",
                                         app_db_id);
                        }
                        SHR_IF_ERR_EXIT(DBAL_HANDLE_CLEAR(unit, dbal_table_id, entry_handle_id));
                        dbal_entry_key_field32_set(unit, entry_handle_id, DBAL_FIELD_CONTEXT_PROFILE, context_profile);
                    }
                }
               /**
                * For FWD1 stage, check the ingress context enablers,
                * if the OAM TCAM Identification is enabled, then save its relevant context and app_db_id
                */
                SHR_IF_ERR_EXIT(DBAL_HANDLE_CLEAR(unit, DBAL_TABLE_OAM_TCAM_IDENTIFICATION_APPDB, entry_handle_id));
                SHR_IF_ERR_EXIT(dbal_entry_get(unit, entry_handle_id, DBAL_GET_ALL_FIELDS));
                SHR_IF_ERR_EXIT(dbal_entry_handle_value_field32_get
                                (unit, entry_handle_id, DBAL_FIELD_IDENTIFICATION_APPDB_0, INST_SINGLE, &oam_tcam_db));

                SHR_IF_ERR_EXIT(DBAL_HANDLE_CLEAR
                                (unit, DBAL_TABLE_INGRESS_IRPP_FWD1_CONTEXT_PROPERTIES, entry_handle_id));
                for (oam_context_profile = 0; oam_context_profile < DBAL_NOF_ENUM_FWD1_CONTEXT_ID_VALUES;
                     oam_context_profile++)
                {
                    SHR_IF_ERR_EXIT(dbal_fields_is_illegal_value
                                    (unit, DBAL_FIELD_FWD1_CONTEXT_ID, oam_context_profile, &is_illegal));
                    if (is_illegal)
                    {
                        continue;
                    }
                    dbal_entry_key_field32_set(unit, entry_handle_id, DBAL_FIELD_FWD1_CONTEXT_ID, oam_context_profile);
                    SHR_IF_ERR_EXIT(dbal_entry_get(unit, entry_handle_id, DBAL_GET_ALL_FIELDS));
                    SHR_IF_ERR_EXIT(dbal_entry_handle_value_field32_get
                                    (unit, entry_handle_id, DBAL_FIELD_OAM_TCAM_IDENTIFICATION_ENABLE, INST_SINGLE,
                                     &oam_identification_enable));
                    if (oam_identification_enable)
                    {
                        uint32 ctx_profile_inst_id;

                        SHR_IF_ERR_EXIT(dbal_fields_enum_hw_value_get
                                        (unit, DBAL_FIELD_FWD1_CONTEXT_ID, oam_context_profile, &ctx_profile_inst_id));

                        SHR_IF_ERR_EXIT(DBAL_HANDLE_CLEAR(unit, DBAL_TABLE_TCAM_APP_DB_TO_STAGE, entry_handle_id));
                        dbal_entry_key_field32_set(unit, entry_handle_id, DBAL_FIELD_APP_DB_ID, oam_tcam_db);
                        dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_TCAM_STAGE, INST_SINGLE,
                                                     DBAL_ENUM_FVAL_TCAM_STAGE_FWD1);
                        dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_RELEVANT_CONTEXT_PROFILE,
                                                     ctx_profile_inst_id, TRUE);
                        SHR_IF_ERR_EXIT(dbal_entry_commit(unit, entry_handle_id, DBAL_COMMIT));

                        SHR_IF_ERR_EXIT(DBAL_HANDLE_CLEAR
                                        (unit, DBAL_TABLE_INGRESS_IRPP_FWD1_CONTEXT_PROPERTIES, entry_handle_id));
                    }
                }
                SHR_IF_ERR_EXIT(DBAL_HANDLE_CLEAR(unit, dbal_table_id, entry_handle_id));
                break;
            }
            default:
            {
                SHR_ERR_EXIT(_SHR_E_PARAM,
                             "Unsupported dbal stage %d for Field static tables init, stage should be FLP or VT\n",
                             dbal_table_id);
            }
        }
    }

exit:
    DBAL_FUNC_FREE_VARS;
    SHR_FUNC_EXIT;
}
/**
 * \brief
 * Check init_pemla.h
 */
shr_error_e
dnx_init_pemla_app_db_id_to_stage_get(
    int unit,
    uint32 app_db_id,
    uint32 *tcam_stage)
{
    uint32 entry_handle_id;
    SHR_FUNC_INIT_VARS(unit);
    DBAL_FUNC_INIT_VARS(unit);

    SHR_IF_ERR_EXIT(DBAL_HANDLE_ALLOC(unit, DBAL_TABLE_TCAM_APP_DB_TO_STAGE, &entry_handle_id));
    dbal_entry_key_field32_set(unit, entry_handle_id, DBAL_FIELD_APP_DB_ID, app_db_id);
    SHR_IF_ERR_EXIT(dbal_entry_get(unit, entry_handle_id, DBAL_GET_ALL_FIELDS));
    SHR_IF_ERR_EXIT(dbal_entry_handle_value_field32_get
                    (unit, entry_handle_id, DBAL_FIELD_TCAM_STAGE, INST_SINGLE, tcam_stage));

exit:
    DBAL_FUNC_FREE_VARS;
    SHR_FUNC_EXIT;
}

static shr_error_e
dnx_init_handler_id_to_app_db_id_get(
    int unit,
    uint32 handler_id,
    uint32 *app_db_id)
{
    dbal_tables_e table_id;
    uint32 associated_handler_id, associated_app_db_id;
    int rv, associated_app_db_size;

    SHR_FUNC_INIT_VARS(unit);
    /** Iterate over all tcam tables to find the one, which has the same handler id as the input one */
    SHR_IF_ERR_EXIT(dbal_tables_next_table_get
                    (unit, DBAL_TABLE_EMPTY, DBAL_LABEL_NONE, DBAL_ACCESS_METHOD_MDB, DBAL_PHYSICAL_TABLE_TCAM,
                     DBAL_TABLE_TYPE_TCAM, &table_id));
    while (table_id != DBAL_TABLE_EMPTY)
    {
        rv = (dbal_tables_tcam_handler_id_get(unit, table_id, &associated_handler_id));
        SHR_IF_ERR_EXIT_EXCEPT_IF(rv, _SHR_E_NOT_FOUND);
        if (handler_id == associated_handler_id)
        {
            SHR_IF_ERR_EXIT(dbal_tables_app_db_id_get(unit, table_id, &associated_app_db_id, &associated_app_db_size));
            *app_db_id = associated_app_db_id;
            break;
        }
        SHR_IF_ERR_EXIT(dbal_tables_next_table_get
                        (unit, table_id, DBAL_LABEL_NONE, DBAL_ACCESS_METHOD_MDB, DBAL_PHYSICAL_TABLE_TCAM,
                         DBAL_TABLE_TYPE_TCAM, &table_id));
    }
exit:
    SHR_FUNC_EXIT;
}

static shr_error_e
dnx_init_app_db_id_to_handler_get(
    int unit,
    uint32 app_db_id,
    uint32 *handler_id)
{
    dbal_tables_e table_id;
    uint32 associated_app_db_id;
    int associated_app_db_size;
    int rv;

    SHR_FUNC_INIT_VARS(unit);
    /** Iterate over all tcam tables to find the one, which has the same handler id as the input one */
    SHR_IF_ERR_EXIT(dbal_tables_next_table_get
                    (unit, DBAL_TABLE_EMPTY, DBAL_LABEL_NONE, DBAL_ACCESS_METHOD_MDB, DBAL_PHYSICAL_TABLE_TCAM,
                     DBAL_TABLE_TYPE_TCAM, &table_id));
    while (table_id != DBAL_TABLE_EMPTY)
    {
        rv = (dbal_tables_app_db_id_get(unit, table_id, &associated_app_db_id, &associated_app_db_size));
        SHR_IF_ERR_EXIT_EXCEPT_IF(rv, _SHR_E_NOT_FOUND);
        if (app_db_id == associated_app_db_id)
        {
            SHR_IF_ERR_EXIT(dbal_tables_tcam_handler_id_get(unit, table_id, handler_id));
            break;
        }
        SHR_IF_ERR_EXIT(dbal_tables_next_table_get
                        (unit, table_id, DBAL_LABEL_NONE, DBAL_ACCESS_METHOD_MDB, DBAL_PHYSICAL_TABLE_TCAM,
                         DBAL_TABLE_TYPE_TCAM, &table_id));
    }
exit:
    SHR_FUNC_EXIT;
}

static shr_error_e
dnx_init_pemla_context_sharing_handler_ids_get(
    int unit,
    uint32 handler_id,
    uint32 *handler_ids_same_ctx)
{
    uint32 entry_handle_id, saved_tcam_stage, tcam_stage_idx, app_db_id;
    uint32 *saved_context_profile = NULL;
    uint32 *context_profile_idx = NULL;
    uint32 *app_db_ids_same_ctx = NULL;
    int nof_instances, instance_idx, app_db_id_max, app_db_id_idx, saved_app_db_id_idx;
    SHR_FUNC_INIT_VARS(unit);
    DBAL_FUNC_INIT_VARS(unit);
    app_db_id = 0;
    /** based on the handler_id, retrieve information of the app_db_id*/
    SHR_IF_ERR_EXIT(dnx_init_handler_id_to_app_db_id_get(unit, handler_id, &app_db_id));

    SHR_IF_ERR_EXIT(DBAL_HANDLE_ALLOC(unit, DBAL_TABLE_TCAM_APP_DB_TO_STAGE, &entry_handle_id));
    dbal_entry_key_field32_set(unit, entry_handle_id, DBAL_FIELD_APP_DB_ID, app_db_id);
    SHR_IF_ERR_EXIT(dbal_entry_get(unit, entry_handle_id, DBAL_GET_ALL_FIELDS));
    SHR_IF_ERR_EXIT(dbal_entry_handle_value_field32_get
                    (unit, entry_handle_id, DBAL_FIELD_TCAM_STAGE, INST_SINGLE, &saved_tcam_stage));
    SHR_IF_ERR_EXIT(dbal_tables_field_nof_instance_get
                    (unit, DBAL_TABLE_TCAM_APP_DB_TO_STAGE, DBAL_FIELD_RELEVANT_CONTEXT_PROFILE, 0, 0, &nof_instances));
    /** for the given app_db_id, get all relevant contexts */
    SHR_ALLOC_ERR_EXIT(saved_context_profile, sizeof(*saved_context_profile) * nof_instances,
                       "saved_context_profile array", "%s%s%s", "saved_context_profile", EMPTY, EMPTY);
    SHR_ALLOC_ERR_EXIT(context_profile_idx, sizeof(*context_profile_idx) * nof_instances,
                       "context_profile_idx array", "%s%s%s", "context_profile_idx", EMPTY, EMPTY);

    SHR_ALLOC_ERR_EXIT(app_db_ids_same_ctx, sizeof(*app_db_ids_same_ctx) * nof_instances,
                       "app_db_ids_same_ctx array", "%s%s%s", "app_db_ids_same_ctx", EMPTY, EMPTY);
    sal_memset(saved_context_profile, 0, sizeof(uint32) * nof_instances);
    sal_memset(context_profile_idx, 0, sizeof(uint32) * nof_instances);
    sal_memset(app_db_ids_same_ctx, 0, sizeof(uint32) * nof_instances);
    for (instance_idx = 0; instance_idx < nof_instances; instance_idx++)
    {
        SHR_IF_ERR_EXIT(dbal_entry_handle_value_field32_get
                        (unit, entry_handle_id, DBAL_FIELD_RELEVANT_CONTEXT_PROFILE, instance_idx,
                         &saved_context_profile[instance_idx]));
    }
    /** Loop over all other app_db_ids, if any shares the same context profile with the given one, save it*/
    SHR_IF_ERR_EXIT(dbal_tables_field_max_value_get
                    (unit, DBAL_TABLE_TCAM_APP_DB_TO_STAGE, DBAL_FIELD_APP_DB_ID, TRUE, FALSE, 0, &app_db_id_max));
    for (app_db_id_idx = 0, saved_app_db_id_idx = 0; app_db_id_idx < app_db_id_max; app_db_id_idx++)
    {
        dbal_entry_key_field32_set(unit, entry_handle_id, DBAL_FIELD_APP_DB_ID, app_db_id_idx);
        SHR_IF_ERR_EXIT(dbal_entry_get(unit, entry_handle_id, DBAL_GET_ALL_FIELDS));
        SHR_IF_ERR_EXIT(dbal_entry_handle_value_field32_get
                        (unit, entry_handle_id, DBAL_FIELD_TCAM_STAGE, INST_SINGLE, &tcam_stage_idx));
        if (saved_tcam_stage == tcam_stage_idx)
        {
            for (instance_idx = 0; instance_idx < nof_instances; instance_idx++)
            {
                SHR_IF_ERR_EXIT(dbal_entry_handle_value_field32_get
                                (unit, entry_handle_id, DBAL_FIELD_RELEVANT_CONTEXT_PROFILE, instance_idx,
                                 &context_profile_idx[instance_idx]));
                if ((context_profile_idx[instance_idx] == saved_context_profile[instance_idx])
                    && (saved_context_profile[instance_idx] == TRUE) && (app_db_id != app_db_id_idx))
                {
                    app_db_ids_same_ctx[saved_app_db_id_idx] = app_db_id_idx;
                    saved_app_db_id_idx++;
                }
            }
        }
    }
    /** retrieve per each of the saved app_db_ids, the handler id*/
    for (app_db_id_idx = 0; app_db_id_idx < (sizeof(*app_db_ids_same_ctx) / sizeof(uint32)); app_db_id_idx++)
    {
        SHR_IF_ERR_EXIT(dnx_init_app_db_id_to_handler_get
                        (unit, app_db_ids_same_ctx[app_db_id_idx], &handler_ids_same_ctx[app_db_id_idx]));
    }
exit:
    SHR_FREE(app_db_ids_same_ctx);
    SHR_FREE(saved_context_profile);
    SHR_FREE(context_profile_idx);
    DBAL_FUNC_FREE_VARS;
    SHR_FUNC_EXIT;
}

/**
 * \brief
 * Check init_pemla.h
 */
shr_error_e
dnx_init_pemla_context_sharing_handler_ids_save(
    int unit,
    uint32 handler_id)
{
    uint32 entry_handle_id;
    uint32 *handler_ids_same_ctx = NULL;
    int nof_instances, handler_idx;
    SHR_FUNC_INIT_VARS(unit);
    DBAL_FUNC_INIT_VARS(unit);

    nof_instances = 1;
    SHR_IF_ERR_EXIT(dbal_tables_field_nof_instance_get
                    (unit, DBAL_TABLE_HANDLER_IDS_INFO, DBAL_FIELD_SHARED_HANDLER_IDS, 0, 0, &nof_instances));
    SHR_ALLOC_ERR_EXIT(handler_ids_same_ctx, sizeof(*handler_ids_same_ctx) * nof_instances,
                       "handler_ids_same_ctx array", "%s%s%s", "handler_ids_same_ctx", EMPTY, EMPTY);
    sal_memset(handler_ids_same_ctx, 0, sizeof(uint32) * nof_instances);
    /** For the given handler_id, return the handler_ids associated with it.
     * Afterwards save in sw state indication as instance idx, if the sharing handler_id exists.
     */
    SHR_IF_ERR_EXIT(dnx_init_pemla_context_sharing_handler_ids_get(unit, handler_id, handler_ids_same_ctx));
    SHR_IF_ERR_EXIT(DBAL_HANDLE_ALLOC(unit, DBAL_TABLE_HANDLER_IDS_INFO, &entry_handle_id));
    dbal_entry_key_field32_set(unit, entry_handle_id, DBAL_FIELD_HANDLER_ID_INFO, handler_id);
    for (handler_idx = 0; handler_idx < (sizeof(*handler_ids_same_ctx) / sizeof(uint32)); handler_idx++)
    {
        if (handler_ids_same_ctx[handler_idx] == TRUE)
        {
            dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_SHARED_HANDLER_IDS,
                                         handler_ids_same_ctx[handler_idx], TRUE);
            SHR_IF_ERR_EXIT(dbal_entry_commit(unit, entry_handle_id, DBAL_COMMIT));
        }
    }
exit:
    SHR_FREE(handler_ids_same_ctx);
    DBAL_FUNC_FREE_VARS;
    SHR_FUNC_EXIT;
}
/**
 * \brief
 * Check init_pemla.h
 */
shr_error_e
dnx_init_pemla_context_sharing_handler_ids_get_cb(
    int unit,
    uint32 handler_id,
    uint32 *handler_ids_same_ctx)
{
    uint32 entry_handle_id, is_shared;
    int nof_instances, handler_idx, handler_id_idx;
    SHR_FUNC_INIT_VARS(unit);
    DBAL_FUNC_INIT_VARS(unit);

    /**
     * The function gets handler_id and checks the saved information in sw state.
     * Per each handler_id, the instance is checked and if it is set to true.
     * In case it is, the instance_idx represents the handler_id to be returned
     */
    SHR_IF_ERR_EXIT(dbal_tables_field_nof_instance_get
                    (unit, DBAL_TABLE_HANDLER_IDS_INFO, DBAL_FIELD_SHARED_HANDLER_IDS, 0, 0, &nof_instances));
    SHR_IF_ERR_EXIT(DBAL_HANDLE_ALLOC(unit, DBAL_TABLE_HANDLER_IDS_INFO, &entry_handle_id));
    dbal_entry_key_field32_set(unit, entry_handle_id, DBAL_FIELD_HANDLER_ID_INFO, handler_id);
    SHR_IF_ERR_EXIT(dbal_entry_get(unit, entry_handle_id, DBAL_GET_ALL_FIELDS));
    for (handler_idx = 0, handler_id_idx = 0; handler_idx < nof_instances; handler_idx++)
    {
        SHR_IF_ERR_EXIT(dbal_entry_handle_value_field32_get
                        (unit, entry_handle_id, DBAL_FIELD_SHARED_HANDLER_IDS, handler_idx, &is_shared));
        if (is_shared == TRUE)
        {
            handler_ids_same_ctx[handler_id_idx] = handler_idx;
            handler_id_idx++;
            /**Always write to the last element of the array DNX_FIELD_TCAM_HANDLER_INVALID, as expected by the dnx_field_tcam_bank_algo_check_context_collision */
            handler_ids_same_ctx[handler_id_idx] = DNX_FIELD_TCAM_HANDLER_INVALID;
        }
    }
exit:
    DBAL_FUNC_FREE_VARS;
    SHR_FUNC_EXIT;
}
shr_error_e
dnx_init_pemla_init(
    int unit)
{
    int tcam_stage;

    SHR_FUNC_INIT_VARS(unit);

    SHR_IF_ERR_EXIT(dnx_init_pemla_custom_init(unit, EMPTY));

    for (tcam_stage = 0; tcam_stage < DNX_TCAM_NOF_STAGES; tcam_stage++)
    {
        SHR_IF_ERR_EXIT(dnx_init_pemla_tcam_tables(unit, tcam_stage));
    }

    if (!SOC_WARM_BOOT(unit))
    {
        SHR_IF_ERR_EXIT(pp_db.init(unit));
    }

exit:
    SHR_FUNC_EXIT;
}

shr_error_e
dnx_init_pemla_deinit(
    int unit)
{
    SHR_FUNC_INIT_VARS(unit);

    SHR_IF_ERR_EXIT(dnx_pemladrv_deinit(unit));

exit:
    SHR_FUNC_EXIT;
}
