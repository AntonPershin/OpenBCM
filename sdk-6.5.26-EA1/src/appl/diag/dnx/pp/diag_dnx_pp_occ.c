/** \file diag_dnx_pp_occ.c
 *
 * Occupation Management Diagnostic Command - Retrieves all allocated in and outlif profile resources.
 */

/*************
 * INCLUDES  *
 *************/
#include "diag_dnx_pp.h"
#include <bcm_int/dnx/algo/lif_mngr/algo_out_lif_profile.h>
#include <bcm_int/dnx/algo/swstate/auto_generated/access/algo_lif_profile_access.h>
#include <bcm_int/dnx/lif/in_lif_profile.h>
#include <soc/dnx/dnx_data/auto_generated/dnx_data_dev_init.h>
#include <soc/dnx/dnx_data/auto_generated/dnx_data_headers.h>
#include <soc/dnx/dnx_data/auto_generated/dnx_data_qos.h>
#include <soc/dnx/dnx_data/auto_generated/dnx_data_switch.h>
/*************
 * DEFINES   *
 *************/

#ifdef BSL_LOG_MODULE
#error "BSL_LOG_MODULE redefined"
#endif
#define BSL_LOG_MODULE BSL_LS_SOCDNX_DIAGPPDNX

/**
 * \brief
 *    A diagnostics function that prints the MDB cluster allocation per hierarchy
 * \param [in] unit - unit ID
 * \param [in] args - arguments passed to the function according to the diag mechanism
 * \param [in] sand_control - passed according to the diag mechanism
 * \return
 *   \retval Zero if no error was detected
 *   \retval Negative if error was detected. See \ref shr_error_e
 */
static shr_error_e
sh_dnx_pp_occ_etpp_profile_print_cmd(
    int unit,
    args_t * args,
    sh_sand_control_t * sand_control)
{
    uint32 entry_handle_id, out_lif_profile, out_lif_orientation, split_horizon_enable, oam_priority_map_profile,
        outlif_profile_width;
    int is_end;
    PRT_INIT_VARS;
    SHR_FUNC_INIT_VARS(unit);
    DBAL_FUNC_INIT_VARS(unit);

    is_end = 0;
    out_lif_profile = 0;
    out_lif_orientation = 0;
    split_horizon_enable = 0;
    oam_priority_map_profile = 0;

    PRT_TITLE_SET("ETPP Outlif Profile allocation");
    outlif_profile_width = utilex_log2_round_up(dnx_data_lif.out_lif.nof_out_lif_profiles_get(unit));
    PRT_INFO_ADD("Outlif profile width = %d", outlif_profile_width);
    PRT_COLUMN_ADD_FLEX(PRT_FLEX_ASCII, "Outlif Profile");
    PRT_COLUMN_ADD_FLEX(PRT_FLEX_ASCII, "Outlif Orientation");
    PRT_COLUMN_ADD_FLEX(PRT_FLEX_ASCII, "Split Horizon");
    PRT_COLUMN_ADD_FLEX(PRT_FLEX_ASCII, "OAM Priority Map Profile");

#if defined(BCM_DNX2_SUPPORT)
    if (dnx_data_lif.global_lif.feature_get(unit, dnx_data_lif_global_lif_outlif_profile_in_glem))
    {
        SHR_IF_ERR_EXIT(DBAL_HANDLE_ALLOC(unit, DBAL_TABLE_ETPP_OUT_LIF_PROFILE_TABLE, &entry_handle_id));
    }
#endif
    /** Taking a handle */
    SHR_IF_ERR_EXIT(dbal_iterator_init(unit, entry_handle_id, DBAL_ITER_MODE_GET_ALL_EXCEPT_DEFAULT));
    /*
     * Receive first entry in table.
     */
    SHR_IF_ERR_EXIT(dbal_iterator_get_next(unit, entry_handle_id, &is_end));
    while (!is_end)
    {
        PRT_ROW_ADD(PRT_ROW_SEP_UNDERSCORE);
        SHR_IF_ERR_EXIT(dbal_entry_handle_key_field_arr32_get
                        (unit, entry_handle_id, DBAL_FIELD_OUT_LIF_PROFILE, &out_lif_profile));
        PRT_CELL_SET("%d", out_lif_profile);
        SHR_IF_ERR_EXIT(dbal_entry_handle_value_field32_get
                        (unit, entry_handle_id, DBAL_FIELD_OUT_LIF_ORIENTATION, INST_SINGLE, &out_lif_orientation));
        PRT_CELL_SET("%d", out_lif_orientation);
        SHR_IF_ERR_EXIT(dbal_entry_handle_value_field32_get
                        (unit, entry_handle_id, DBAL_FIELD_SPLIT_HORIZON_ENABLE, INST_SINGLE, &split_horizon_enable));
        PRT_CELL_SET("%d", split_horizon_enable);
        SHR_IF_ERR_EXIT(dbal_entry_handle_value_field32_get
                        (unit, entry_handle_id, DBAL_FIELD_OAM_PRIORITY_MAP_PROFILE, INST_SINGLE,
                         &oam_priority_map_profile));
        PRT_CELL_SET("%d", oam_priority_map_profile);
        /** Receive next entry in table.*/
        SHR_IF_ERR_EXIT(dbal_iterator_get_next(unit, entry_handle_id, &is_end));
    }
    PRT_COMMITX;
exit:
    PRT_FREE;
    DBAL_FUNC_FREE_VARS;
    SHR_FUNC_EXIT;
}

/**
 * \brief The function fills 3 arrays of acl, ingress and egress bits with the 'x' character,
 * used as helper to emphasize on the relevant bits for the diagnostic.
 */
static void
sh_dnx_pp_occ_in_lif_profile_masked_bits_print(
    int unit,
    char *acl_bits,
    char *egress_bits,
    char *ingress_bits,
    char *native_indexed_mode_bits)
{
    int bit;
    int nof_ingress_profile_bits = 0;
    int nof_egress_profile_bits = 0;
    int same_interface_number_of_bits = 0, preserve_dscp_number_of_bits = 0;
    int system_headers_mode;

    system_headers_mode = dnx_data_headers.system_headers.system_headers_mode_get(unit);
    /** Print egress bits information from inlif profile*/
    if (system_headers_mode == DBAL_ENUM_FVAL_SYSTEM_HEADERS_MODE_JERICHO2_MODE)
    {
        nof_egress_profile_bits = IN_LIF_PROFILE_EGRESS_RESERVED_NOF_BITS;
        nof_ingress_profile_bits = NOF_IN_LIF_PROFILE_INGRESS_BITS;
    }
    else if ((system_headers_mode == DBAL_ENUM_FVAL_SYSTEM_HEADERS_MODE_JERICHO_MODE)
             && !dnx_data_lif.feature.feature_get(unit, dnx_data_lif_feature_iop_mode_orientation_selection))
    {
        if (JR_COMP_MODE_SAME_PRESERVE_DSCP_PER_INLIF(dnx_data_qos.qos.routing_dscp_preserve_mode_get(unit)))
        {
            preserve_dscp_number_of_bits = 1;
        }
        if (JR_COMP_MODE_SAME_IF_MODE_1B_ALLOCATION
            (dnx_data_lif.in_lif.in_lif_profile_allocate_same_interface_mode_get(unit)))
        {
            same_interface_number_of_bits = 1;
        }
        else if (JR_COMP_MODE_SAME_IF_MODE_2B_ALLOCATION
                 (dnx_data_lif.in_lif.in_lif_profile_allocate_same_interface_mode_get(unit)))
        {
            same_interface_number_of_bits = 2;
        }

        /** In IOP mode if policer is enabled - both inner and outer DP have the same value and only 1 bit is allocated for them. It is wrong to calculate also  IVE_OUTER_QOS_DP_PROFILE_NOF_BITS */
        nof_egress_profile_bits =
            IN_LIF_ORIENTATION_NOF_BITS + IVE_INNER_QOS_DP_PROFILE_NOF_BITS + same_interface_number_of_bits +
            preserve_dscp_number_of_bits;
        nof_ingress_profile_bits =
            NOF_IN_LIF_PROFILE_BITS - (IN_LIF_PROFILE_PMF_RESERVED_NOF_BITS + NATIVE_INDEXED_MODE_NOF_BITS +
                                       nof_egress_profile_bits);
    }
    else
    {
        nof_ingress_profile_bits =
            (NOF_IN_LIF_PROFILE_BITS - IN_LIF_PROFILE_EGRESS_NOF_BITS_JR_MODE - IN_LIF_PROFILE_PMF_RESERVED_NOF_BITS -
             NATIVE_INDEXED_MODE_NOF_BITS);
        nof_egress_profile_bits = IN_LIF_PROFILE_EGRESS_NOF_BITS_JR_MODE;
    }
    for (bit = 0; bit < IN_LIF_PROFILE_PMF_RESERVED_NOF_BITS + 1; bit++)
    {
        if (bit < IN_LIF_PROFILE_PMF_RESERVED_NOF_BITS)
        {
            acl_bits[bit] = 'x';
        }
        else
        {
            acl_bits[bit] = '\0';
        }
    }
    for (bit = 0; bit < nof_ingress_profile_bits + 1; bit++)
    {
        if (bit < nof_ingress_profile_bits)
        {
            ingress_bits[bit] = 'x';
        }
        else
        {
            ingress_bits[bit] = '\0';
        }
    }
    for (bit = 0; bit < nof_egress_profile_bits + 1; bit++)
    {
        if (bit < nof_egress_profile_bits)
        {
            egress_bits[bit] = 'x';
        }
        else
        {
            egress_bits[bit] = '\0';
        }
    }
    for (bit = 0; bit < NATIVE_INDEXED_MODE_NOF_BITS + 1; bit++)
    {
        if (bit < NATIVE_INDEXED_MODE_NOF_BITS)
        {
            native_indexed_mode_bits[bit] = 'x';
        }
        else
        {
            native_indexed_mode_bits[bit] = '\0';
        }
    }
}

/**
 * \brief The function fills 3 arrays of acl, ingress and egress bits with the 'x' character,
 * used as helper to emphasize on the relevant bits for the diagnostic.
 */
static void
sh_dnx_pp_occ_eth_rif_profile_masked_bits_print(
    int unit,
    char *acl_bits,
    char *egress_bits,
    char *ingress_bits)
{
    int bit;
    int nof_ingress_profile_bits;
    int nof_egress_profile_bits;
    int system_headers_mode;

    system_headers_mode = dnx_data_headers.system_headers.system_headers_mode_get(unit);
    /** Print egress bits information from inlif profile*/
    if ((system_headers_mode == DBAL_ENUM_FVAL_SYSTEM_HEADERS_MODE_JERICHO2_MODE) ||
        (dnx_data_qos.qos.routing_dscp_preserve_mode_get(unit) != 1))
    {
        nof_ingress_profile_bits = NOF_ETH_RIF_PROFILE_INGRESS_BITS;
        nof_egress_profile_bits = ETH_RIF_PROFILE_EGRESS_RESERVED_NOF_BITS;
        egress_bits[0] = '\0';
    }
    else
    {
        if (dnx_data_lif.feature.feature_get(unit, dnx_data_lif_feature_iop_mode_orientation_selection))
        {
            nof_ingress_profile_bits =
                (NOF_ETH_RIF_PROFILE_BITS - IN_LIF_PROFILE_EGRESS_NOF_BITS_JR_MODE -
                 ETH_RIF_PROFILE_PMF_RESERVED_NOF_BITS);
            nof_egress_profile_bits = IN_LIF_PROFILE_EGRESS_NOF_BITS_JR_MODE;
        }
        else
        {
            nof_ingress_profile_bits =
                (NOF_ETH_RIF_PROFILE_BITS - IN_LIF_PROFILE_EGRESS_NOF_BITS_DSCP_MODE -
                 ETH_RIF_PROFILE_PMF_RESERVED_NOF_BITS);
            nof_egress_profile_bits = IN_LIF_PROFILE_EGRESS_NOF_BITS_DSCP_MODE;
        }
        for (bit = 0; bit < nof_egress_profile_bits + 1; bit++)
        {
            if (bit < nof_egress_profile_bits)
            {
                egress_bits[bit] = 'x';
            }
            else
            {
                egress_bits[bit] = '\0';
            }
        }
    }
    for (bit = 0; bit < ETH_RIF_PROFILE_PMF_RESERVED_NOF_BITS + 1; bit++)
    {
        if (bit < ETH_RIF_PROFILE_PMF_RESERVED_NOF_BITS)
        {
            acl_bits[bit] = 'x';
        }
        else
        {
            acl_bits[bit] = '\0';
        }
    }
    for (bit = 0; bit < nof_ingress_profile_bits + 1; bit++)
    {
        if (bit < nof_ingress_profile_bits)
        {
            ingress_bits[bit] = 'x';
        }
        else
        {
            ingress_bits[bit] = '\0';
        }
    }
}
static void
sh_dnx_pp_occ_masked_bits_print(
    int nof_bits_to_print,
    int total_bits,
    char *prefix_value_binary_buffer,
    char *prefix_value_binary_buffer_full)
{
    if (nof_bits_to_print > sal_strnlen(prefix_value_binary_buffer, SHR_SAND_DEFAULT_MAX_STRING_OPERATION_LENGTH))
    {
        for (int i = 0, j = 0; i < (total_bits + 1); i++)
        {
            if (nof_bits_to_print >
                sal_strnlen(prefix_value_binary_buffer, SHR_SAND_DEFAULT_MAX_STRING_OPERATION_LENGTH))
            {
                prefix_value_binary_buffer_full[i] = '0';
                nof_bits_to_print--;
            }
            else
            {
                prefix_value_binary_buffer_full[i] = prefix_value_binary_buffer[j];
                j++;
            }
        }
    }
    else
    {
        sal_strncpy(prefix_value_binary_buffer_full, prefix_value_binary_buffer, nof_bits_to_print);
    }
}
/**
 * \brief The function prints the egress bits from the inlif profile
 */
static shr_error_e
sh_dnx_pp_occ_ingress_profile_egress_bits_print(
    int unit,
    args_t * args,
    sh_sand_control_t * sand_control)
{
    uint32 entry_handle_id, in_lif_profile, in_lif_orientation, inner_dp_profile,
        outer_dp_profile, in_lif_same_interface, preserve_dscp_mode;
    int is_end, egress_msb_bit, nof_ingress_bits;
    char *buffer = NULL;
    char *acl_bits_p = NULL;
    char *ingress_bits_p = NULL;
    char *native_indexed_mode_bits = NULL;
    char *egress_bits_p = NULL;
    char *prefix_value_binary_buffer = NULL;
    char *prefix_value_binary_buffer_full = NULL;
    int saved_index, default_entry;
    char *acl_profile_bits = NULL;
    char *egress_profile_bits = NULL;

    PRT_INIT_VARS;
    SHR_FUNC_INIT_VARS(unit);
    DBAL_FUNC_INIT_VARS(unit);
    SHR_ALLOC(acl_bits_p, sizeof(*acl_bits_p) * (IN_LIF_PROFILE_PMF_RESERVED_NOF_BITS + 1),
              "acl_bits_p", "%s%s%s", EMPTY, EMPTY, EMPTY);
    SHR_ALLOC(ingress_bits_p, sizeof(*ingress_bits_p) * (NOF_IN_LIF_PROFILE_INGRESS_BITS + 1),
              "ingress_bits_p", "%s%s%s", EMPTY, EMPTY, EMPTY);
    SHR_ALLOC(egress_bits_p, sizeof(*egress_bits_p) * (IN_LIF_PROFILE_EGRESS_RESERVED_NOF_BITS + 1), "egress_bits_p",
              "%s%s%s", EMPTY, EMPTY, EMPTY);
    SHR_ALLOC(native_indexed_mode_bits, sizeof(*native_indexed_mode_bits) * (NATIVE_INDEXED_MODE_NOF_BITS + 1),
              "native_indexed_mode_bits", "%s%s%s", EMPTY, EMPTY, EMPTY);
    SHR_ALLOC_SET_ZERO(prefix_value_binary_buffer,
                       sizeof(*prefix_value_binary_buffer) * (IN_LIF_PROFILE_EGRESS_RESERVED_NOF_BITS + 1),
                       "prefix_value_binary_buffer", "%s%s%s", EMPTY, EMPTY, EMPTY);
    SHR_ALLOC_SET_ZERO(prefix_value_binary_buffer_full,
                       sizeof(*prefix_value_binary_buffer_full) * (IN_LIF_PROFILE_EGRESS_RESERVED_NOF_BITS + 1),
                       "prefix_value_binary_buffer_full", "%s%s%s", EMPTY, EMPTY, EMPTY);
    SHR_ALLOC_SET_ZERO(buffer, sizeof(*buffer) * (DBAL_MAX_PRINTABLE_BUFFER_SIZE + 1), "buffer", "%s%s%s", EMPTY, EMPTY,
                       EMPTY);
    SHR_ALLOC(acl_profile_bits, sizeof(*acl_profile_bits) * (DBAL_MAX_STRING_LENGTH + 1), "acl_profile_bits", "%s%s%s",
              EMPTY, EMPTY, EMPTY);
    SHR_ALLOC(egress_profile_bits, sizeof(*egress_profile_bits) * (DBAL_MAX_STRING_LENGTH + 1), "egress_profile_bits",
              "%s%s%s", EMPTY, EMPTY, EMPTY);

    is_end = 0;
    in_lif_profile = 0;
    in_lif_orientation = 0;
    inner_dp_profile = 0;
    outer_dp_profile = 0;
    in_lif_same_interface = 0;
    egress_msb_bit = IN_LIF_PROFILE_PMF_RESERVED_START_BIT;
    nof_ingress_bits = NOF_IN_LIF_PROFILE_INGRESS_BITS + NATIVE_INDEXED_MODE_NOF_BITS;
    saved_index = 0;
    default_entry = 0;
    preserve_dscp_mode = DISABLE_PRESERVE_DSCP_MODE;

    sh_dnx_pp_occ_in_lif_profile_masked_bits_print(unit, acl_bits_p, egress_bits_p, ingress_bits_p,
                                                   native_indexed_mode_bits);
    PRT_TITLE_SET("InLIF Ingress-PP profile");

    if (IN_LIF_PROFILE_PMF_RESERVED_NOF_BITS == 0)
    {
        sal_snprintf(acl_profile_bits, DBAL_MAX_STRING_LENGTH, "%s", "No ACL profile bits");
    }
    else
    {
        sal_snprintf(acl_profile_bits, DBAL_MAX_STRING_LENGTH, "%s%d %s %d%s", "ACL profile bits [",
                     NOF_IN_LIF_PROFILE_BITS - 1, ":", IN_LIF_PROFILE_PMF_RESERVED_START_BIT, "]");
    }

    if (IN_LIF_PROFILE_EGRESS_RESERVED_NOF_BITS == 0)
    {
        sal_snprintf(egress_profile_bits, DBAL_MAX_STRING_LENGTH, "%s", "No Egress profile bits");
    }
    else
    {
        sal_snprintf(egress_profile_bits, DBAL_MAX_STRING_LENGTH, "%s%d %s %d%s", "Egress profile bits [",
                     IN_LIF_PROFILE_PMF_RESERVED_START_BIT - 1, ":", IN_LIF_PROFILE_EGRESS_RESERVED_START_BIT, "]");
    }

    if (NATIVE_INDEXED_MODE_NOF_BITS)
    {
        if (IN_LIF_PROFILE_EGRESS_RESERVED_START_BIT - NATIVE_INDEXED_MODE_NOF_BITS > 0)
        {
            PRT_INFO_ADD
                ("Profile bits separation: %s, %s, Native Indexed Mode bits = [%d : %d], Ingress profile bits = [%d : %d]",
                 acl_profile_bits, egress_profile_bits,
                 IN_LIF_PROFILE_EGRESS_RESERVED_START_BIT - 1,
                 IN_LIF_PROFILE_EGRESS_RESERVED_START_BIT - NATIVE_INDEXED_MODE_NOF_BITS,
                 IN_LIF_PROFILE_EGRESS_RESERVED_START_BIT - NATIVE_INDEXED_MODE_NOF_BITS - 1, 0);
        }
        else
        {
            PRT_INFO_ADD
                ("Profile bits separation: %s, %s, Native Indexed Mode bits = [%d : %d], No ingress profile bits",
                 acl_profile_bits, egress_profile_bits,
                 IN_LIF_PROFILE_EGRESS_RESERVED_START_BIT - 1,
                 IN_LIF_PROFILE_EGRESS_RESERVED_START_BIT - NATIVE_INDEXED_MODE_NOF_BITS);
        }
    }
    else
    {
        if (IN_LIF_PROFILE_EGRESS_RESERVED_NOF_BITS == 0)
        {
            PRT_INFO_ADD
                ("Profile bits separation: %s, No egress profile bits, Ingress profile bits = [%d : %d]",
                 acl_profile_bits, IN_LIF_PROFILE_EGRESS_RESERVED_START_BIT - 1, 0);
        }
        else if (IN_LIF_PROFILE_EGRESS_RESERVED_START_BIT == 0)
        {
            PRT_INFO_ADD
                ("Profile bits separation: %s, %s, No ingress profile bits", acl_profile_bits, egress_profile_bits);
        }
        else if (IN_LIF_PROFILE_EGRESS_RESERVED_START_BIT > 0)
        {
            PRT_INFO_ADD
                ("Profile bits separation: %s, %s, Ingress profile bits = [%d : %d]",
                 acl_profile_bits, egress_profile_bits, IN_LIF_PROFILE_EGRESS_RESERVED_START_BIT - 1, 0);
        }
    }
    PRT_COMMITX;
    if (IN_LIF_PROFILE_EGRESS_RESERVED_NOF_BITS != 0)
    {
        PRT_TITLE_SET("Egress bits");
    }
    else
    {
        PRT_TITLE_SET("Values of the egress properties for all InLif profiles");
    }

    PRT_COLUMN_ADD_FLEX(PRT_FLEX_ASCII, "InLif Profile");
    PRT_COLUMN_ADD_FLEX(PRT_FLEX_ASCII, "Orientation");
    PRT_COLUMN_ADD_FLEX(PRT_FLEX_ASCII, "Inner DP");
    PRT_COLUMN_ADD_FLEX(PRT_FLEX_ASCII, "Outer DP");
    PRT_COLUMN_ADD_FLEX(PRT_FLEX_ASCII, "Same interface");
    PRT_COLUMN_ADD_FLEX(PRT_FLEX_ASCII, "Preserve DSCP");

    /** Taking a handle */
    SHR_IF_ERR_EXIT(DBAL_HANDLE_ALLOC(unit, DBAL_TABLE_IN_LIF_PROFILE_TABLE, &entry_handle_id));
    SHR_IF_ERR_EXIT(dbal_iterator_init(unit, entry_handle_id, DBAL_ITER_MODE_ALL));
    /*
     * Receive first entry in table.
     */
    SHR_IF_ERR_EXIT(dbal_iterator_get_next(unit, entry_handle_id, &is_end));
    while (!is_end)
    {
        SHR_IF_ERR_EXIT(dbal_entry_handle_key_field_arr32_get
                        (unit, entry_handle_id, DBAL_FIELD_IN_LIF_PROFILE, &in_lif_profile));
        in_lif_profile = in_lif_profile & ((1 << egress_msb_bit) - 1);
        in_lif_profile = in_lif_profile >> nof_ingress_bits;
        if ((saved_index < in_lif_profile) || ((default_entry == 0) && (in_lif_profile == 0)))
        {

            sal_itoa(prefix_value_binary_buffer, in_lif_profile, 2, 0, 0);
            sh_dnx_pp_occ_masked_bits_print(IN_LIF_PROFILE_EGRESS_RESERVED_NOF_BITS,
                                            IN_LIF_PROFILE_EGRESS_RESERVED_NOF_BITS, prefix_value_binary_buffer,
                                            prefix_value_binary_buffer_full);

            SHR_IF_ERR_EXIT(dbal_entry_handle_value_field32_get
                            (unit, entry_handle_id, DBAL_FIELD_IN_LIF_ORIENTATION, INST_SINGLE, &in_lif_orientation));

            SHR_IF_ERR_EXIT(dbal_entry_handle_value_field32_get
                            (unit, entry_handle_id, DBAL_FIELD_INNER_DP_PROFILE, INST_SINGLE, &inner_dp_profile));
            SHR_IF_ERR_EXIT(dbal_entry_handle_value_field32_get
                            (unit, entry_handle_id, DBAL_FIELD_OUTER_DP_PROFILE, INST_SINGLE, &outer_dp_profile));
            SHR_IF_ERR_EXIT(dbal_entry_handle_value_field32_get
                            (unit, entry_handle_id, DBAL_FIELD_IN_LIF_SAME_INTERFACE, INST_SINGLE,
                             &in_lif_same_interface));
            SHR_IF_ERR_EXIT(dbal_table_field32_printable_string_get
                            (unit, DBAL_TABLE_IN_LIF_PROFILE_TABLE, DBAL_FIELD_IN_LIF_SAME_INTERFACE, 0,
                             in_lif_same_interface, NULL, 0, FALSE, buffer));
            PRT_ROW_ADD(PRT_ROW_SEP_UNDERSCORE);
            if (IN_LIF_PROFILE_EGRESS_RESERVED_NOF_BITS == 0)
            {
                PRT_CELL_SET("%s%s%s", acl_bits_p, native_indexed_mode_bits, ingress_bits_p);
            }
            else
            {
                PRT_CELL_SET("%s%s%s%s", acl_bits_p, prefix_value_binary_buffer_full, native_indexed_mode_bits,
                             ingress_bits_p);
            }

            if ((in_lif_orientation >= IN_LIF_ORIENTATION_NOF_VALUES && (in_lif_orientation > 0)) ||
                (inner_dp_profile >= IVE_INNER_QOS_DP_PROFILE_NOF_VALUES && (inner_dp_profile > 0)) ||
                (outer_dp_profile >= IVE_OUTER_QOS_DP_PROFILE_NOF_VALUES && (outer_dp_profile > 0)) ||
                (in_lif_same_interface == DBAL_ENUM_FVAL_IN_LIF_SAME_INTERFACE_INVALID))
            {

                PRT_CELL_SET("%s", "N/A");
                PRT_CELL_SET("%s", "N/A");
                PRT_CELL_SET("%s", "N/A");
                PRT_CELL_SET("%s", "N/A");
                /** In JR2 mode preserve dscp feature is not enabled for inlif profile*/
                PRT_CELL_SET("%s", "N/A");
            }
            else
            {
                PRT_CELL_SET("%d", in_lif_orientation);
                PRT_CELL_SET("%d", inner_dp_profile);
                PRT_CELL_SET("%d", outer_dp_profile);
                PRT_CELL_SET("%s", buffer);
                /** In JR2 mode preserve dscp feature is not enabled for inlif profile*/
                PRT_CELL_SET("%d", preserve_dscp_mode);
            }

            /** Receive next entry in table.*/
            saved_index = in_lif_profile;
            if (in_lif_profile == 0)
            {
                default_entry = 1;
            }
        }
        SHR_IF_ERR_EXIT(dbal_iterator_get_next(unit, entry_handle_id, &is_end));
    }
    PRT_COMMITX;

exit:
    SHR_FREE(acl_bits_p);
    SHR_FREE(ingress_bits_p);
    SHR_FREE(egress_bits_p);
    SHR_FREE(native_indexed_mode_bits);
    SHR_FREE(prefix_value_binary_buffer);
    SHR_FREE(prefix_value_binary_buffer_full);
    SHR_FREE(buffer);
    SHR_FREE(acl_profile_bits);
    SHR_FREE(egress_profile_bits);
    PRT_FREE;
    DBAL_FUNC_FREE_VARS;
    SHR_FUNC_EXIT;
}

/**
 * \brief The function prints the egress bits from the inlif profile
 */
static shr_error_e
sh_dnx_pp_occ_ingress_profile_jr_mode_egress_bits_print(
    int unit,
    args_t * args,
    sh_sand_control_t * sand_control)
{
    uint32 entry_handle_id, in_lif_profile, egress_reserved_start_bit;
    int is_end, egress_msb_bit, entries_to_print, nof_ingress_bits, in_lif_profile_jr_mode,
        in_lif_profile_exclude_orientation, same_interface, orientation, in_lif_orientation;
    char *acl_bits_p = NULL;
    char *ingress_bits_p = NULL;
    char *egress_bits_p = NULL;
    char *native_indexed_mode_bits = NULL;
    int saved_index, default_entry;
    char *prefix_value_binary_buffer = NULL;
    char *prefix_value_binary_buffer_full = NULL;
    in_lif_profile_info_egress_t egress_fields_info;

    PRT_INIT_VARS;
    SHR_FUNC_INIT_VARS(unit);
    DBAL_FUNC_INIT_VARS(unit);
    SHR_ALLOC(acl_bits_p, sizeof(*acl_bits_p) * (IN_LIF_PROFILE_PMF_RESERVED_NOF_BITS + 1),
              "acl_bits_p", "%s%s%s", EMPTY, EMPTY, EMPTY);
    SHR_ALLOC(ingress_bits_p,
              sizeof(*ingress_bits_p) * (IN_LIF_PROFILE_PMF_RESERVED_START_BIT -
                                         IN_LIF_PROFILE_EGRESS_NOF_BITS_JR_MODE - NATIVE_INDEXED_MODE_NOF_BITS + 1),
              "ingress_bits_p", "%s%s%s", EMPTY, EMPTY, EMPTY);
    SHR_ALLOC(egress_bits_p, sizeof(*egress_bits_p) * IN_LIF_PROFILE_EGRESS_NOF_BITS_JR_MODE + 1, "egress_bits_p",
              "%s%s%s", EMPTY, EMPTY, EMPTY);
    SHR_ALLOC(native_indexed_mode_bits, sizeof(*native_indexed_mode_bits) * (NATIVE_INDEXED_MODE_NOF_BITS + 1),
              "native_indexed_mode_bits", "%s%s%s", EMPTY, EMPTY, EMPTY);
    SHR_ALLOC_SET_ZERO(prefix_value_binary_buffer,
                       sizeof(*prefix_value_binary_buffer) * (IN_LIF_PROFILE_EGRESS_NOF_BITS_JR_MODE + 1),
                       "prefix_value_binary_buffer", "%s%s%s", EMPTY, EMPTY, EMPTY);
    SHR_ALLOC_SET_ZERO(prefix_value_binary_buffer_full,
                       sizeof(*prefix_value_binary_buffer_full) * (IN_LIF_PROFILE_EGRESS_NOF_BITS_JR_MODE + 1),
                       "prefix_value_binary_buffer_full", "%s%s%s", EMPTY, EMPTY, EMPTY);

    is_end = 0;
    in_lif_profile = 0;
    in_lif_orientation = 0;
    egress_msb_bit = IN_LIF_PROFILE_PMF_RESERVED_START_BIT;
    nof_ingress_bits =
        (NOF_IN_LIF_PROFILE_BITS - IN_LIF_PROFILE_EGRESS_NOF_BITS_JR_MODE - IN_LIF_PROFILE_PMF_RESERVED_NOF_BITS -
         NATIVE_INDEXED_MODE_NOF_BITS);
    saved_index = 0;
    default_entry = 0;
    entries_to_print = 0;
    in_lif_profile_jr_mode = 0;
    in_lif_profile_exclude_orientation = 0;
    egress_reserved_start_bit = IN_LIF_PROFILE_PMF_RESERVED_START_BIT - IN_LIF_PROFILE_EGRESS_NOF_BITS_JR_MODE;
    same_interface = dnx_data_lif.in_lif.in_lif_profile_allocate_same_interface_mode_get(unit);
    orientation = dnx_data_lif.in_lif.in_lif_profile_allocate_orientation_get(unit);
    sal_memset(&egress_fields_info, 0, sizeof(in_lif_profile_info_egress_t));

    sh_dnx_pp_occ_in_lif_profile_masked_bits_print(unit, acl_bits_p, egress_bits_p, ingress_bits_p,
                                                   native_indexed_mode_bits);
    PRT_TITLE_SET("InLIF Ingress-PP profile");
    PRT_INFO_ADD
        ("Profile bits separation: ACL profile bits = [%d : %d], Egress lif profile bits = [%d : %d], number of Ingress lif profile bits = [%d : %d]",
         NOF_IN_LIF_PROFILE_BITS - 1, IN_LIF_PROFILE_PMF_RESERVED_START_BIT, IN_LIF_PROFILE_PMF_RESERVED_START_BIT - 1,
         IN_LIF_PROFILE_PMF_RESERVED_START_BIT - IN_LIF_PROFILE_EGRESS_NOF_BITS_JR_MODE,
         IN_LIF_PROFILE_PMF_RESERVED_START_BIT - IN_LIF_PROFILE_EGRESS_NOF_BITS_JR_MODE - 1, 0);
    PRT_COMMITX;
    PRT_TITLE_SET("Egress bits");

    PRT_COLUMN_ADD_FLEX(PRT_FLEX_ASCII, "InLif Profile");
    PRT_COLUMN_ADD_FLEX(PRT_FLEX_ASCII, "Orientation");
    PRT_COLUMN_ADD_FLEX(PRT_FLEX_ASCII, "System Scope same interface");
    PRT_COLUMN_ADD_FLEX(PRT_FLEX_ASCII, "Device Scope same interface");
    PRT_COLUMN_ADD_FLEX(PRT_FLEX_ASCII, "Outer DP");
    PRT_COLUMN_ADD_FLEX(PRT_FLEX_ASCII, "Inner DP");
    PRT_COLUMN_ADD_FLEX(PRT_FLEX_ASCII, "Preserve DSCP");

    /** Taking a handle */
    SHR_IF_ERR_EXIT(DBAL_HANDLE_ALLOC(unit, DBAL_TABLE_IN_LIF_PROFILE_TABLE, &entry_handle_id));
    SHR_IF_ERR_EXIT(dbal_iterator_init(unit, entry_handle_id, DBAL_ITER_MODE_ALL));
    /*
     * Receive first entry in table.
     */
    SHR_IF_ERR_EXIT(dbal_iterator_get_next(unit, entry_handle_id, &is_end));
    while (!is_end)
    {
        SHR_IF_ERR_EXIT(dbal_entry_handle_key_field_arr32_get
                        (unit, entry_handle_id, DBAL_FIELD_IN_LIF_PROFILE, &in_lif_profile));
        in_lif_profile = in_lif_profile & ((1 << egress_msb_bit) - 1);
        in_lif_profile = in_lif_profile >> (nof_ingress_bits + NATIVE_INDEXED_MODE_NOF_BITS);
        if ((saved_index < in_lif_profile) || ((default_entry == 0) && (in_lif_profile == 0)))
        {
            PRT_ROW_ADD(PRT_ROW_SEP_UNDERSCORE);
            sal_itoa(prefix_value_binary_buffer, in_lif_profile, 2, 0, 0);
            sh_dnx_pp_occ_masked_bits_print(IN_LIF_PROFILE_EGRESS_NOF_BITS_JR_MODE,
                                            IN_LIF_PROFILE_EGRESS_NOF_BITS_JR_MODE,
                                            prefix_value_binary_buffer, prefix_value_binary_buffer_full);
            PRT_CELL_SET("%s%s%s%s", acl_bits_p, prefix_value_binary_buffer_full, native_indexed_mode_bits,
                         ingress_bits_p);

            SHR_IF_ERR_EXIT(dnx_in_lif_profile_algo_extract_egress_profile
                            (unit, in_lif_profile << egress_reserved_start_bit, &egress_fields_info,
                             &in_lif_profile_jr_mode, &in_lif_profile_exclude_orientation, &in_lif_orientation, LIF));
            if ((orientation > 0) && (same_interface == 0)
                && (dnx_data_qos.qos.routing_dscp_preserve_mode_get(unit) != 1))
            {
                PRT_CELL_SET("%d", egress_fields_info.in_lif_orientation);
                PRT_CELL_SET("%d", 0);
                PRT_CELL_SET("%d", 0);
                PRT_CELL_SET("%d", 0);
                PRT_CELL_SET("%d", 0);
                PRT_CELL_SET("%d", 0);
            }
            else if (same_interface == JR_COMP_MODE_ONLY_SYS_SCOPE_ENABLED_BY_SOC_PROPERTIES)
            {
                PRT_CELL_SET("%d", egress_fields_info.in_lif_orientation);
                PRT_CELL_SET("%d", egress_fields_info.lif_same_interface_mode);
                PRT_CELL_SET("%d", 0);
                PRT_CELL_SET("%d", 0);
                PRT_CELL_SET("%d", 0);
                PRT_CELL_SET("%d", 0);
                if ((orientation == 0) && (entries_to_print == 1))
                {
                    break;
                }
                entries_to_print = entries_to_print + 1;
            }
            else if (same_interface == JR_COMP_MODE_ONLY_DEV_SCOPE_ENABLED_BY_SOC_PROPERTIES)
            {
                PRT_CELL_SET("%d", egress_fields_info.in_lif_orientation);
                PRT_CELL_SET("%d", 0);
                PRT_CELL_SET("%d", egress_fields_info.lif_same_interface_mode);
                PRT_CELL_SET("%d", 0);
                PRT_CELL_SET("%d", 0);
                PRT_CELL_SET("%d", 0);
                if ((orientation == 0) && (entries_to_print == 1))
                {
                    break;
                }
                entries_to_print = entries_to_print + 1;
            }
            else if (same_interface == JR_COMP_MODE_BOTH_DEV_AND_SYS_SCOPE_ENABLED_BY_SOC_PROPERTIES)
            {
                PRT_CELL_SET("%d", 0);
                PRT_CELL_SET("%d", ((egress_fields_info.lif_same_interface_mode >> 1) & 1));
                PRT_CELL_SET("%d", (egress_fields_info.lif_same_interface_mode & 1));
                PRT_CELL_SET("%d", 0);
                PRT_CELL_SET("%d", 0);
                PRT_CELL_SET("%d", 0);
            }
            else if (dnx_data_lif.in_lif.in_lif_profile_allocate_policer_outer_dp_get(unit) &&
                     dnx_data_lif.in_lif.in_lif_profile_allocate_policer_inner_dp_get(unit))
            {
                PRT_CELL_SET("%d", 0);
                PRT_CELL_SET("%d", 0);
                PRT_CELL_SET("%d", 0);
                PRT_CELL_SET("%d", egress_fields_info.ive_outer_qos_dp_profile);
                PRT_CELL_SET("%d", egress_fields_info.ive_inner_qos_dp_profile);
                PRT_CELL_SET("%d", 0);
            }
            else if (dnx_data_qos.qos.routing_dscp_preserve_mode_get(unit) == 1)
            {
                PRT_CELL_SET("%d", egress_fields_info.in_lif_orientation);
                PRT_CELL_SET("%d", 0);
                PRT_CELL_SET("%d", 0);
                PRT_CELL_SET("%d", 0);
                PRT_CELL_SET("%d", 0);
                PRT_CELL_SET("%d", egress_fields_info.preserve_dscp_mode);
            }
            /** Receive next entry in table.*/
            saved_index = in_lif_profile;
            if (in_lif_profile == 0)
            {
                default_entry = 1;
            }
        }
        SHR_IF_ERR_EXIT(dbal_iterator_get_next(unit, entry_handle_id, &is_end));
    }
    PRT_COMMITX;

exit:
    SHR_FREE(acl_bits_p);
    SHR_FREE(ingress_bits_p);
    SHR_FREE(egress_bits_p);
    SHR_FREE(native_indexed_mode_bits);
    SHR_FREE(prefix_value_binary_buffer);
    SHR_FREE(prefix_value_binary_buffer_full);
    PRT_FREE;
    DBAL_FUNC_FREE_VARS;
    SHR_FUNC_EXIT;
}

/**
 * \brief The function prints the egress bits from the inlif profile
 */
static shr_error_e
sh_dnx_pp_occ_ingress_profile_jr_mode_not_fixed_egress_bits_print(
    int unit,
    args_t * args,
    sh_sand_control_t * sand_control)
{
    uint32 entry_handle_id, in_lif_profile;
    int is_end, egress_msb_bit, nof_ingress_bits;
    char *acl_bits_p = NULL;
    char *ingress_bits_p = NULL;
    char *egress_bits_p = NULL;
    char *native_indexed_mode_bits = NULL;
    int saved_index, default_entry;
    char *prefix_value_binary_buffer = NULL;
    char *prefix_value_binary_buffer_full = NULL;
    in_lif_profile_info_egress_t egress_fields_info;
    int in_lif_profile_jr_mode = 0, in_lif_profile_exclude_orientation = 0, in_lif_orientation =
        0, egress_reserved_nof_bits = 0, preserve_dscp_number_of_bits = 0, same_interface_number_of_bits = 0;

    PRT_INIT_VARS;
    SHR_FUNC_INIT_VARS(unit);
    DBAL_FUNC_INIT_VARS(unit);

    if (JR_COMP_MODE_SAME_PRESERVE_DSCP_PER_INLIF(dnx_data_qos.qos.routing_dscp_preserve_mode_get(unit)))
    {
        preserve_dscp_number_of_bits = 1;
    }
    if (JR_COMP_MODE_SAME_IF_MODE_1B_ALLOCATION
        (dnx_data_lif.in_lif.in_lif_profile_allocate_same_interface_mode_get(unit)))
    {
        same_interface_number_of_bits = 1;
    }
    else if (JR_COMP_MODE_SAME_IF_MODE_2B_ALLOCATION
             (dnx_data_lif.in_lif.in_lif_profile_allocate_same_interface_mode_get(unit)))
    {
        same_interface_number_of_bits = 2;
    }

    /** In IOP mode if policer is enabled - both inner and outer DP have the same value and only 1 bit is allocated for them. It is wrong to calculate also  IVE_OUTER_QOS_DP_PROFILE_NOF_BITS */
    egress_reserved_nof_bits =
        IN_LIF_ORIENTATION_NOF_BITS + IVE_INNER_QOS_DP_PROFILE_NOF_BITS + same_interface_number_of_bits +
        preserve_dscp_number_of_bits;

    SHR_ALLOC(acl_bits_p, sizeof(*acl_bits_p) * (IN_LIF_PROFILE_PMF_RESERVED_NOF_BITS + 1),
              "acl_bits_p", "%s%s%s", EMPTY, EMPTY, EMPTY);
    SHR_ALLOC(ingress_bits_p,
              sizeof(*ingress_bits_p) * (IN_LIF_PROFILE_PMF_RESERVED_START_BIT - egress_reserved_nof_bits -
                                         NATIVE_INDEXED_MODE_NOF_BITS + 1), "ingress_bits_p", "%s%s%s", EMPTY, EMPTY,
              EMPTY);
    SHR_ALLOC(egress_bits_p, sizeof(*egress_bits_p) * (egress_reserved_nof_bits + 1), "egress_bits_p", "%s%s%s", EMPTY,
              EMPTY, EMPTY);
    SHR_ALLOC(native_indexed_mode_bits, sizeof(*native_indexed_mode_bits) * (NATIVE_INDEXED_MODE_NOF_BITS + 1),
              "native_indexed_mode_bits", "%s%s%s", EMPTY, EMPTY, EMPTY);
    SHR_ALLOC_SET_ZERO(prefix_value_binary_buffer, sizeof(*prefix_value_binary_buffer) * (egress_reserved_nof_bits + 1),
                       "prefix_value_binary_buffer", "%s%s%s", EMPTY, EMPTY, EMPTY);
    SHR_ALLOC_SET_ZERO(prefix_value_binary_buffer_full,
                       sizeof(*prefix_value_binary_buffer_full) * (egress_reserved_nof_bits + 1),
                       "prefix_value_binary_buffer_full", "%s%s%s", EMPTY, EMPTY, EMPTY);

    is_end = 0;
    in_lif_profile = 0;
    egress_msb_bit = IN_LIF_PROFILE_PMF_RESERVED_START_BIT;
    nof_ingress_bits =
        (NOF_IN_LIF_PROFILE_BITS - egress_reserved_nof_bits - IN_LIF_PROFILE_PMF_RESERVED_NOF_BITS -
         NATIVE_INDEXED_MODE_NOF_BITS);
    saved_index = 0;
    default_entry = 0;
    sh_dnx_pp_occ_in_lif_profile_masked_bits_print(unit, acl_bits_p, egress_bits_p, ingress_bits_p,
                                                   native_indexed_mode_bits);
    PRT_TITLE_SET("InLIF Ingress-PP profile");

    if (egress_reserved_nof_bits == 0)
    {
        PRT_INFO_ADD
            ("Profile bits separation: ACL profile bits = [%d : %d], No egress profile bits, Ingress profile bits = [%d : %d]",
             NOF_IN_LIF_PROFILE_BITS - 1, IN_LIF_PROFILE_PMF_RESERVED_START_BIT,
             IN_LIF_PROFILE_EGRESS_RESERVED_START_BIT - 1, 0);
    }
    else if (IN_LIF_PROFILE_PMF_RESERVED_START_BIT - egress_reserved_nof_bits == 0)
    {
        PRT_INFO_ADD
            ("Profile bits separation: ACL profile bits = [%d : %d], Egress profile bits = [%d : %d], No ingress profile bits",
             NOF_IN_LIF_PROFILE_BITS - 1, IN_LIF_PROFILE_PMF_RESERVED_START_BIT,
             IN_LIF_PROFILE_PMF_RESERVED_START_BIT - 1, IN_LIF_PROFILE_EGRESS_RESERVED_START_BIT);
    }
    else if (IN_LIF_PROFILE_PMF_RESERVED_START_BIT - egress_reserved_nof_bits > 0)
    {
        PRT_INFO_ADD
            ("Profile bits separation: ACL profile bits = [%d : %d], Egress profile bits = [%d : %d], Ingress profile bits = [%d : %d]",
             NOF_IN_LIF_PROFILE_BITS - 1, IN_LIF_PROFILE_PMF_RESERVED_START_BIT,
             IN_LIF_PROFILE_PMF_RESERVED_START_BIT - 1,
             IN_LIF_PROFILE_PMF_RESERVED_START_BIT - egress_reserved_nof_bits,
             IN_LIF_PROFILE_PMF_RESERVED_START_BIT - egress_reserved_nof_bits - 1, 0);

    }

    PRT_COMMITX;
    PRT_TITLE_SET("Egress bits");

    PRT_COLUMN_ADD_FLEX(PRT_FLEX_ASCII, "InLif Profile");
    PRT_COLUMN_ADD_FLEX(PRT_FLEX_ASCII, "Orientation");
    PRT_COLUMN_ADD_FLEX(PRT_FLEX_ASCII, "System Scope same interface");
    PRT_COLUMN_ADD_FLEX(PRT_FLEX_ASCII, "Device Scope same interface");
    PRT_COLUMN_ADD_FLEX(PRT_FLEX_ASCII, "Outer DP");
    PRT_COLUMN_ADD_FLEX(PRT_FLEX_ASCII, "Inner DP");
    PRT_COLUMN_ADD_FLEX(PRT_FLEX_ASCII, "Preserve DSCP");

    /** Taking a handle */
    SHR_IF_ERR_EXIT(DBAL_HANDLE_ALLOC(unit, DBAL_TABLE_IN_LIF_PROFILE_TABLE, &entry_handle_id));
    SHR_IF_ERR_EXIT(dbal_iterator_init(unit, entry_handle_id, DBAL_ITER_MODE_ALL));
    /*
     * Receive first entry
     */
    SHR_IF_ERR_EXIT(dbal_iterator_get_next(unit, entry_handle_id, &is_end));
    while (!is_end)
    {
        SHR_IF_ERR_EXIT(dbal_entry_handle_key_field_arr32_get
                        (unit, entry_handle_id, DBAL_FIELD_IN_LIF_PROFILE, &in_lif_profile));
        /** Remove pmf bits */
        in_lif_profile = in_lif_profile & ((1 << egress_msb_bit) - 1);
        /** Remove ingress bits */
        in_lif_profile = in_lif_profile >> (nof_ingress_bits + NATIVE_INDEXED_MODE_NOF_BITS);
        if ((saved_index < in_lif_profile) || ((default_entry == 0) && (in_lif_profile == 0)))
        {
            PRT_ROW_ADD(PRT_ROW_SEP_UNDERSCORE);
            sal_itoa(prefix_value_binary_buffer, in_lif_profile, 2, 0, 0);
            sh_dnx_pp_occ_masked_bits_print(egress_reserved_nof_bits,
                                            egress_reserved_nof_bits,
                                            prefix_value_binary_buffer, prefix_value_binary_buffer_full);

            if (egress_reserved_nof_bits == 0)
            {
                PRT_CELL_SET("%s%s%s", acl_bits_p, native_indexed_mode_bits, ingress_bits_p);
            }
            else
            {
                PRT_CELL_SET("%s%s%s%s", acl_bits_p, prefix_value_binary_buffer_full, native_indexed_mode_bits,
                             ingress_bits_p);
            }
            SHR_IF_ERR_EXIT(dnx_in_lif_profile_algo_extract_egress_profile_and_orientation_iop_mode
                            (unit, in_lif_profile << (IN_LIF_PROFILE_PMF_RESERVED_START_BIT - egress_reserved_nof_bits),
                             &egress_fields_info, &in_lif_profile_jr_mode, &in_lif_profile_exclude_orientation,
                             &in_lif_orientation));

            if ((egress_fields_info.in_lif_orientation >= IN_LIF_ORIENTATION_NOF_VALUES
                 && (egress_fields_info.in_lif_orientation > 0))
                || (egress_fields_info.ive_inner_qos_dp_profile >= IVE_INNER_QOS_DP_PROFILE_NOF_VALUES
                    && (egress_fields_info.ive_inner_qos_dp_profile > 0))
                || (egress_fields_info.ive_outer_qos_dp_profile >= IVE_OUTER_QOS_DP_PROFILE_NOF_VALUES
                    && (egress_fields_info.ive_outer_qos_dp_profile > 0)))
            {
                PRT_CELL_SET("%s", "N/A");
                PRT_CELL_SET("%s", "N/A");
                PRT_CELL_SET("%s", "N/A");
                PRT_CELL_SET("%s", "N/A");
                PRT_CELL_SET("%s", "N/A");
                PRT_CELL_SET("%s", "N/A");
            }
            else
            {
                PRT_CELL_SET("%d", egress_fields_info.in_lif_orientation);
                if (SAME_INTERFACE_MODE_NOF_VALUES == 0)
                {
                    PRT_CELL_SET("%d", 0);
                    PRT_CELL_SET("%d", 0);
                }
                else if (SAME_INTERFACE_MODE_NOF_VALUES == JR_COMP_MODE_ONLY_SYS_SCOPE_ENABLED_BY_SOC_PROPERTIES)
                {
                    PRT_CELL_SET("%d", egress_fields_info.lif_same_interface_mode);
                    PRT_CELL_SET("%d", 0);
                }
                else if (SAME_INTERFACE_MODE_NOF_VALUES == JR_COMP_MODE_ONLY_DEV_SCOPE_ENABLED_BY_SOC_PROPERTIES)
                {
                    PRT_CELL_SET("%d", 0);
                    PRT_CELL_SET("%d", egress_fields_info.lif_same_interface_mode);
                }
                else if (SAME_INTERFACE_MODE_NOF_VALUES ==
                         JR_COMP_MODE_BOTH_DEV_AND_SYS_SCOPE_ENABLED_BY_SOC_PROPERTIES)
                {
                    PRT_CELL_SET("%d", ((egress_fields_info.lif_same_interface_mode >> 1) & 1));
                    PRT_CELL_SET("%d", (egress_fields_info.lif_same_interface_mode & 1));
                }
                PRT_CELL_SET("%d", egress_fields_info.ive_outer_qos_dp_profile);
                PRT_CELL_SET("%d", egress_fields_info.ive_inner_qos_dp_profile);
                PRT_CELL_SET("%d", egress_fields_info.preserve_dscp_mode);
            }
                /** Receive next entry in table.*/
            saved_index = in_lif_profile;
            if (in_lif_profile == 0)
            {
                default_entry = 1;
            }
        }
        SHR_IF_ERR_EXIT(dbal_iterator_get_next(unit, entry_handle_id, &is_end));
    }
    PRT_COMMITX;

exit:
    SHR_FREE(acl_bits_p);
    SHR_FREE(ingress_bits_p);
    SHR_FREE(egress_bits_p);
    SHR_FREE(native_indexed_mode_bits);
    SHR_FREE(prefix_value_binary_buffer);
    SHR_FREE(prefix_value_binary_buffer_full);
    PRT_FREE;
    DBAL_FUNC_FREE_VARS;
    SHR_FUNC_EXIT;
}

static shr_error_e
sh_dnx_pp_occ_eth_rif_profile_jr_mode_egress_bits_print(
    int unit,
    args_t * args,
    sh_sand_control_t * sand_control)
{
    uint32 entry_handle_id, eth_rif_egress_profile, egress_reserved_start_bit;
    int is_end, egress_msb_bit, nof_ingress_bits, eth_rif_profile_jr_mode,
        eth_rif_profile_exclude_orientation, eth_rif_orientation, nof_egress_profile_bits;
    char *acl_bits_p = NULL;
    char *ingress_bits_p = NULL;
    char *egress_bits_p = NULL;
    int saved_index, default_entry;
    char *prefix_value_binary_buffer = NULL;
    char *prefix_value_binary_buffer_full = NULL;
    in_lif_profile_info_egress_t egress_fields_info;

    PRT_INIT_VARS;
    SHR_FUNC_INIT_VARS(unit);
    DBAL_FUNC_INIT_VARS(unit);

    is_end = 0;
    eth_rif_egress_profile = 0;
    eth_rif_orientation = 0;
    egress_msb_bit = ETH_RIF_PROFILE_PMF_RESERVED_START_BIT;
    saved_index = 0;
    default_entry = 0;
    eth_rif_profile_jr_mode = 0;
    eth_rif_profile_exclude_orientation = 0;

    if (dnx_data_lif.feature.feature_get(unit, dnx_data_lif_feature_iop_mode_orientation_selection))
    {
        nof_egress_profile_bits = IN_LIF_PROFILE_EGRESS_NOF_BITS_JR_MODE;
    }
    else
    {
        nof_egress_profile_bits = 1;
    }
    nof_ingress_bits = (NOF_ETH_RIF_PROFILE_BITS - nof_egress_profile_bits - ETH_RIF_PROFILE_PMF_RESERVED_NOF_BITS);
    egress_reserved_start_bit = ETH_RIF_PROFILE_PMF_RESERVED_START_BIT - nof_egress_profile_bits;
    SHR_ALLOC(acl_bits_p, sizeof(*acl_bits_p) * (ETH_RIF_PROFILE_PMF_RESERVED_NOF_BITS + 1),
              "acl_bits_p", "%s%s%s", EMPTY, EMPTY, EMPTY);
    SHR_ALLOC(ingress_bits_p,
              sizeof(*ingress_bits_p) * (NOF_ETH_RIF_PROFILE_INGRESS_BITS - nof_egress_profile_bits + 1),
              "ingress_bits_p", "%s%s%s", EMPTY, EMPTY, EMPTY);
    SHR_ALLOC(egress_bits_p, sizeof(*egress_bits_p) * nof_egress_profile_bits + 1, "egress_bits_p",
              "%s%s%s", EMPTY, EMPTY, EMPTY);
    SHR_ALLOC_SET_ZERO(prefix_value_binary_buffer, sizeof(*prefix_value_binary_buffer) * (nof_egress_profile_bits + 1),
                       "prefix_value_binary_buffer", "%s%s%s", EMPTY, EMPTY, EMPTY);
    SHR_ALLOC_SET_ZERO(prefix_value_binary_buffer_full,
                       sizeof(*prefix_value_binary_buffer_full) * (nof_egress_profile_bits + 1),
                       "prefix_value_binary_buffer_full", "%s%s%s", EMPTY, EMPTY, EMPTY);

    sal_memset(&egress_fields_info, 0, sizeof(in_lif_profile_info_egress_t));

    sh_dnx_pp_occ_eth_rif_profile_masked_bits_print(unit, acl_bits_p, egress_bits_p, ingress_bits_p);
    PRT_TITLE_SET("InLIF Ingress-PP profile");
    PRT_INFO_ADD
        ("Profile bits separation: ACL profile bits = [%d : %d], Egress lif profile bits = [%d : %d], number of Ingress lif/vsi profile bits = [%d : %d]",
         NOF_ETH_RIF_PROFILE_BITS - 1, ETH_RIF_PROFILE_PMF_RESERVED_START_BIT,
         ETH_RIF_PROFILE_PMF_RESERVED_START_BIT - 1,
         ETH_RIF_PROFILE_PMF_RESERVED_START_BIT - nof_egress_profile_bits,
         ETH_RIF_PROFILE_PMF_RESERVED_START_BIT - nof_egress_profile_bits - 1, 0);
    PRT_COMMITX;
    PRT_TITLE_SET("Egress bits");

    PRT_COLUMN_ADD_FLEX(PRT_FLEX_ASCII, "InLif Profile");
    PRT_COLUMN_ADD_FLEX(PRT_FLEX_ASCII, "Orientation");
    PRT_COLUMN_ADD_FLEX(PRT_FLEX_ASCII, "System Scope same interface");
    PRT_COLUMN_ADD_FLEX(PRT_FLEX_ASCII, "Device Scope same interface");
    PRT_COLUMN_ADD_FLEX(PRT_FLEX_ASCII, "Outer DP");
    PRT_COLUMN_ADD_FLEX(PRT_FLEX_ASCII, "Inner DP");
    PRT_COLUMN_ADD_FLEX(PRT_FLEX_ASCII, "Preserve DSCP");

    /** Taking a handle */
    SHR_IF_ERR_EXIT(DBAL_HANDLE_ALLOC(unit, DBAL_TABLE_IN_LIF_PROFILE_TABLE, &entry_handle_id));
    SHR_IF_ERR_EXIT(dbal_iterator_init(unit, entry_handle_id, DBAL_ITER_MODE_GET_ALL_EXCEPT_DEFAULT));
    /*
     * Receive first entry in table.
     */
    SHR_IF_ERR_EXIT(dbal_iterator_get_next(unit, entry_handle_id, &is_end));
    while (!is_end)
    {
        SHR_IF_ERR_EXIT(dbal_entry_handle_key_field_arr32_get
                        (unit, entry_handle_id, DBAL_FIELD_IN_LIF_PROFILE, &eth_rif_egress_profile));
        /** If the inlif profile is in the rif range*/
        if ((eth_rif_egress_profile >> NOF_ETH_RIF_PROFILE_BITS) == IN_LIF_PROFILE_TABLE_MSB_PREFIX)
        {
            eth_rif_egress_profile = eth_rif_egress_profile & ((1 << egress_msb_bit) - 1);
            eth_rif_egress_profile = eth_rif_egress_profile >> nof_ingress_bits;
            if ((saved_index < eth_rif_egress_profile) || ((default_entry == 0) && (eth_rif_egress_profile == 0)))
            {
                PRT_ROW_ADD(PRT_ROW_SEP_UNDERSCORE);
                sal_itoa(prefix_value_binary_buffer, eth_rif_egress_profile, 2, 0, 0);
                sh_dnx_pp_occ_masked_bits_print(nof_egress_profile_bits,
                                                nof_egress_profile_bits,
                                                prefix_value_binary_buffer, prefix_value_binary_buffer_full);
                PRT_CELL_SET("%s%s%s", acl_bits_p, prefix_value_binary_buffer_full, ingress_bits_p);
                SHR_IF_ERR_EXIT(dnx_eth_rif_profile_algo_extract_egress_profile
                                (unit, eth_rif_egress_profile << egress_reserved_start_bit, &egress_fields_info,
                                 &eth_rif_profile_jr_mode, &eth_rif_profile_exclude_orientation, &eth_rif_orientation));
                PRT_CELL_SET("%d", egress_fields_info.in_lif_orientation);
                PRT_CELL_SET("%d", egress_fields_info.lif_same_interface_mode);
                PRT_CELL_SET("%d", egress_fields_info.lif_same_interface_mode);
                PRT_CELL_SET("%d", egress_fields_info.ive_outer_qos_dp_profile);
                PRT_CELL_SET("%d", egress_fields_info.ive_inner_qos_dp_profile);
                PRT_CELL_SET("%d", egress_fields_info.preserve_dscp_mode);
                /** Receive next entry in table.*/
                saved_index = eth_rif_egress_profile;
                if (eth_rif_egress_profile == 0)
                {
                    default_entry = 1;
                }
            }
        }
        SHR_IF_ERR_EXIT(dbal_iterator_get_next(unit, entry_handle_id, &is_end));
    }
    PRT_COMMITX;

exit:
    SHR_FREE(acl_bits_p);
    SHR_FREE(ingress_bits_p);
    SHR_FREE(egress_bits_p);
    SHR_FREE(prefix_value_binary_buffer);
    SHR_FREE(prefix_value_binary_buffer_full);
    PRT_FREE;
    DBAL_FUNC_FREE_VARS;
    SHR_FUNC_EXIT;
}
/**
 * \brief The function prints the ingress bits from the inlif profile
 */
static shr_error_e
sh_dnx_pp_occ_in_lif_profile_ingress_bits_print(
    int unit,
    args_t * args,
    sh_sand_control_t * sand_control)
{
    uint32 entry_handle_id, rpf_mode, in_lif_profile, icmpv4_trap_handling_profile, entry_handle_id_vsi_profile,
        entry_handle_id_mapped_in_lif_profile, icmpv6_trap_handling_profile, arp_trap_handling_profile,
        igmp_trap_handling_profile, non_auth_8021x_trap_handling_profile, cs_in_lif_vtt_profile, cs_in_lif_fwd_profile,
        oam_default_profile, da_not_found_destination_profile, dhcp_trap_handling_profile, routing_enablers_profile,
        l2tp_trap_handling_profile, in_lif_orientation = 0, ive_outer_qos_dp_profile = 0, ive_inner_qos_dp_profile =
        0, lif_same_interface_mode = 0, acl_bits_value = 0, in_lif_profile_ingress_bits = 0, msb_bit = 0;
    int is_end, nof_ingress_bits, system_headers_mode, preserve_dscp_number_of_bits = 0, same_interface_number_of_bits =
        0, egress_nof_bits = 0;
    char *prefix_value_binary_buffer = NULL, *acl_value_binary_buffer = NULL;
    char *prefix_value_binary_buffer_full = NULL, *acl_value_binary_buffer_full = NULL;
    char *buffer = NULL;
    char *acl_bits_p = NULL;
    char *ingress_bits_p = NULL;
    char *egress_bits_p = NULL;
    char *native_indexed_mode_bits = NULL;
    int saved_index, default_entry, in_lif_profile_used_bits_mask = 0, egress_reserved_nof_bits =
        0, in_lif_profile_egress_reserved_start_bit = 0;
    in_lif_template_data_t in_lif_profile_template_data;

    PRT_INIT_VARS;
    SHR_FUNC_INIT_VARS(unit);
    DBAL_FUNC_INIT_VARS(unit);
    SHR_ALLOC(acl_bits_p, sizeof(*acl_bits_p) * (IN_LIF_PROFILE_PMF_RESERVED_NOF_BITS + 1),
              "acl_bits_p", "%s%s%s", EMPTY, EMPTY, EMPTY);
    SHR_ALLOC(native_indexed_mode_bits, sizeof(*native_indexed_mode_bits) * (NATIVE_INDEXED_MODE_NOF_BITS + 1),
              "native_indexed_mode_bits", "%s%s%s", EMPTY, EMPTY, EMPTY);
    SHR_ALLOC_SET_ZERO(buffer, sizeof(*buffer) * (DBAL_MAX_PRINTABLE_BUFFER_SIZE + 1), "buffer", "%s%s%s", EMPTY, EMPTY,
                       EMPTY);

    system_headers_mode = dnx_data_headers.system_headers.system_headers_mode_get(unit);
    nof_ingress_bits = NOF_IN_LIF_PROFILE_INGRESS_BITS;
    /** Print egress bits information from inlif profile*/
    if (system_headers_mode == DBAL_ENUM_FVAL_SYSTEM_HEADERS_MODE_JERICHO2_MODE)
    {
        SHR_ALLOC(egress_bits_p, sizeof(*egress_bits_p) * (IN_LIF_PROFILE_EGRESS_RESERVED_NOF_BITS + 1),
                  "egress_bits_p", "%s%s%s", EMPTY, EMPTY, EMPTY);

    }
    else if ((system_headers_mode == DBAL_ENUM_FVAL_SYSTEM_HEADERS_MODE_JERICHO_MODE)
             && !dnx_data_lif.feature.feature_get(unit, dnx_data_lif_feature_iop_mode_orientation_selection))
    {
        if (JR_COMP_MODE_SAME_PRESERVE_DSCP_PER_INLIF(dnx_data_qos.qos.routing_dscp_preserve_mode_get(unit)))
        {
            preserve_dscp_number_of_bits = 1;
        }
        if (JR_COMP_MODE_SAME_IF_MODE_1B_ALLOCATION
            (dnx_data_lif.in_lif.in_lif_profile_allocate_same_interface_mode_get(unit)))
        {
            same_interface_number_of_bits = 1;
        }
        else if (JR_COMP_MODE_SAME_IF_MODE_2B_ALLOCATION
                 (dnx_data_lif.in_lif.in_lif_profile_allocate_same_interface_mode_get(unit)))
        {
            same_interface_number_of_bits = 2;
        }

        egress_nof_bits =
            IN_LIF_ORIENTATION_NOF_BITS + IVE_INNER_QOS_DP_PROFILE_NOF_BITS + same_interface_number_of_bits +
            preserve_dscp_number_of_bits;
        nof_ingress_bits =
            (NOF_IN_LIF_PROFILE_BITS - egress_nof_bits - IN_LIF_PROFILE_PMF_RESERVED_NOF_BITS -
             NATIVE_INDEXED_MODE_NOF_BITS);
        SHR_ALLOC(egress_bits_p, sizeof(*egress_bits_p) * (egress_nof_bits + 1), "egress_bits_p", "%s%s%s", EMPTY,
                  EMPTY, EMPTY);
    }
    else
    {
        SHR_ALLOC(egress_bits_p, sizeof(*egress_bits_p) * IN_LIF_PROFILE_EGRESS_NOF_BITS_JR_MODE + 1,
                  "egress_bits_p", "%s%s%s", EMPTY, EMPTY, EMPTY);
        nof_ingress_bits =
            (NOF_IN_LIF_PROFILE_BITS - IN_LIF_PROFILE_EGRESS_NOF_BITS_JR_MODE - IN_LIF_PROFILE_PMF_RESERVED_NOF_BITS -
             NATIVE_INDEXED_MODE_NOF_BITS);
    }
    SHR_ALLOC(ingress_bits_p, sizeof(*ingress_bits_p) * (nof_ingress_bits + 1),
              "ingress_bits_p", "%s%s%s", EMPTY, EMPTY, EMPTY);
    SHR_ALLOC_SET_ZERO(prefix_value_binary_buffer, sizeof(*prefix_value_binary_buffer) * (nof_ingress_bits + 1),
                       "prefix_value_binary_buffer", "%s%s%s", EMPTY, EMPTY, EMPTY);
    SHR_ALLOC_SET_ZERO(prefix_value_binary_buffer_full,
                       sizeof(*prefix_value_binary_buffer_full) * (nof_ingress_bits + 1),
                       "prefix_value_binary_buffer_full", "%s%s%s", EMPTY, EMPTY, EMPTY);
    SHR_ALLOC_SET_ZERO(acl_value_binary_buffer,
                       sizeof(*acl_value_binary_buffer) * (IN_LIF_PROFILE_PMF_RESERVED_NOF_BITS + 1),
                       "acl_value_binary_buffer", "%s%s%s", EMPTY, EMPTY, EMPTY);
    SHR_ALLOC_SET_ZERO(acl_value_binary_buffer_full,
                       sizeof(*acl_value_binary_buffer_full) * (IN_LIF_PROFILE_PMF_RESERVED_NOF_BITS + 1),
                       "acl_value_binary_buffer_full", "%s%s%s", EMPTY, EMPTY, EMPTY);
    sal_memset(&in_lif_profile_template_data, 0, sizeof(in_lif_template_data_t));

    is_end = 0;
    rpf_mode = 0;
    in_lif_profile = 0;
    l2tp_trap_handling_profile = 0;
    icmpv4_trap_handling_profile = 0;
    icmpv6_trap_handling_profile = 0;
    arp_trap_handling_profile = 0;
    igmp_trap_handling_profile = 0;
    non_auth_8021x_trap_handling_profile = 0;
    cs_in_lif_vtt_profile = 0;
    cs_in_lif_fwd_profile = 0;
    da_not_found_destination_profile = 0;
    saved_index = 0;
    oam_default_profile = 0;

    sh_dnx_pp_occ_in_lif_profile_masked_bits_print(unit, acl_bits_p, egress_bits_p, ingress_bits_p,
                                                   native_indexed_mode_bits);
    if (nof_ingress_bits != 0)
    {
        PRT_TITLE_SET("Ingress bits");
    }
    else
    {
        PRT_TITLE_SET("Values of the ingress properties for all InLif profiles");
    }
    PRT_COLUMN_ADD_FLEX(PRT_FLEX_ASCII, "InLif Profile");
    if (dnx_data_lif.in_lif.feature_get(unit, dnx_data_lif_in_lif_use_in_lif_profile_range_allocation_per_pmf_profiles))
    {
        PRT_COLUMN_ADD_FLEX(PRT_FLEX_ASCII, "Field class ID");

    }

    PRT_COLUMN_ADD_FLEX(PRT_FLEX_ASCII, "Routing enablers profile");

    PRT_COLUMN_ADD_FLEX(PRT_FLEX_ASCII, "RPF mode");
    PRT_COLUMN_ADD_FLEX(PRT_FLEX_ASCII, "L2TP profile");
    PRT_COLUMN_ADD_FLEX(PRT_FLEX_ASCII, "ICMPV4 profile");
    PRT_COLUMN_ADD_FLEX(PRT_FLEX_ASCII, "ICMPV6 profile");
    PRT_COLUMN_ADD_FLEX(PRT_FLEX_ASCII, "ARP Profile");
    PRT_COLUMN_ADD_FLEX(PRT_FLEX_ASCII, "IGMP Profile");
    PRT_COLUMN_ADD_FLEX(PRT_FLEX_ASCII, "DHCP Profile");
    PRT_COLUMN_ADD_FLEX(PRT_FLEX_ASCII, "Non auth 802tx Profile");
    PRT_COLUMN_ADD_FLEX(PRT_FLEX_ASCII, "CS InLif VTT Profile");
    PRT_COLUMN_ADD_FLEX(PRT_FLEX_ASCII, "CS InLif FWD Profile");
    PRT_COLUMN_ADD_FLEX(PRT_FLEX_ASCII, "DA not found destination Profile");
    PRT_COLUMN_ADD_FLEX(PRT_FLEX_ASCII, "OAM Default Profile");
    if (dnx_data_lif.in_lif.feature_get(unit, dnx_data_lif_in_lif_use_mapped_in_lif_profile))
    {
        PRT_COLUMN_ADD_FLEX(PRT_FLEX_ASCII, "Orientation");
        PRT_COLUMN_ADD_FLEX(PRT_FLEX_ASCII, "QOS inner DP");
        PRT_COLUMN_ADD_FLEX(PRT_FLEX_ASCII, "QOS Outer DP");
        PRT_COLUMN_ADD_FLEX(PRT_FLEX_ASCII, "Same interface");
    }

    saved_index = 0;
    default_entry = 0;

    /** Taking a handle */
    SHR_IF_ERR_EXIT(DBAL_HANDLE_ALLOC(unit, DBAL_TABLE_IN_LIF_PROFILE_TABLE, &entry_handle_id));
    SHR_IF_ERR_EXIT(DBAL_HANDLE_ALLOC(unit, DBAL_TABLE_VSI_PROFILE_TABLE, &entry_handle_id_vsi_profile));
    if (dnx_data_lif.in_lif.feature_get(unit, dnx_data_lif_in_lif_use_mapped_in_lif_profile))
    {
        SHR_IF_ERR_EXIT(DBAL_HANDLE_ALLOC
                        (unit, DBAL_TABLE_MAPPED_IN_LIF_PROFILE_TABLE, &entry_handle_id_mapped_in_lif_profile));
    }
    SHR_IF_ERR_EXIT(dbal_iterator_init(unit, entry_handle_id, DBAL_ITER_MODE_GET_ALL_EXCEPT_DEFAULT));
    /*
     * Receive first entry in table.
     */
    SHR_IF_ERR_EXIT(dbal_iterator_get_next(unit, entry_handle_id, &is_end));
    while (!is_end)
    {
        SHR_IF_ERR_EXIT(dbal_entry_handle_key_field_arr32_get
                        (unit, entry_handle_id, DBAL_FIELD_IN_LIF_PROFILE, &in_lif_profile));
        if (dnx_data_lif.
            in_lif.feature_get(unit, dnx_data_lif_in_lif_use_in_lif_profile_range_allocation_per_pmf_profiles)
            && (IN_LIF_PROFILE_PMF_RESERVED_NOF_BITS > 0))
        {
            /** Get the MSB bit from 8bits in_lif_profile */
            utilex_bitstream_get_field(&in_lif_profile, 7, 1, &msb_bit);
            if (msb_bit == 1)
            {
                /** In this case it is IN_RIF profile, no need to check the rest entries as they will be also IN_RIF profiles */
                break;
            }
            SHR_IF_ERR_EXIT(dnx_in_lif_profile_used_bits_mask_get
                            (unit, &in_lif_profile_used_bits_mask, &egress_reserved_nof_bits,
                             &in_lif_profile_egress_reserved_start_bit));
            in_lif_profile = in_lif_profile & in_lif_profile_used_bits_mask;
        }
        else
        {
            in_lif_profile = in_lif_profile & ((1 << nof_ingress_bits) - 1);
            in_lif_profile_ingress_bits = in_lif_profile;
        }

        if ((saved_index < in_lif_profile) || ((default_entry == 0) && (in_lif_profile == 0)))
        {
            PRT_ROW_ADD(PRT_ROW_SEP_UNDERSCORE);
            if (dnx_data_lif.
                in_lif.feature_get(unit, dnx_data_lif_in_lif_use_in_lif_profile_range_allocation_per_pmf_profiles))
            {
                /** Get the value of the ACL bits */
                utilex_bitstream_get_field(&in_lif_profile, IN_LIF_PROFILE_PMF_RESERVED_START_BIT,
                                           IN_LIF_PROFILE_PMF_RESERVED_NOF_BITS, &acl_bits_value);
                /** Convert acl_bits_value to binary value */
                sal_itoa(acl_value_binary_buffer, acl_bits_value, 2, 0, 0);
                sh_dnx_pp_occ_masked_bits_print(IN_LIF_PROFILE_PMF_RESERVED_NOF_BITS,
                                                IN_LIF_PROFILE_PMF_RESERVED_NOF_BITS, acl_value_binary_buffer,
                                                acl_value_binary_buffer_full);
                /** Take only the ingress bits */
                utilex_bitstream_get_field(&in_lif_profile, 0, NOF_IN_LIF_PROFILE_INGRESS_BITS,
                                           &in_lif_profile_ingress_bits);
            }
            sal_itoa(prefix_value_binary_buffer, in_lif_profile_ingress_bits, 2, 0, 0);
            sh_dnx_pp_occ_masked_bits_print(nof_ingress_bits, nof_ingress_bits, prefix_value_binary_buffer,
                                            prefix_value_binary_buffer_full);
            if (nof_ingress_bits == 0)
            {
                if (dnx_data_lif.
                    in_lif.feature_get(unit, dnx_data_lif_in_lif_use_in_lif_profile_range_allocation_per_pmf_profiles)
                    && (IN_LIF_PROFILE_PMF_RESERVED_NOF_BITS > 0))
                {
                    PRT_CELL_SET("%s%s%s", acl_value_binary_buffer_full, egress_bits_p, native_indexed_mode_bits);
                }
                else
                {
                    PRT_CELL_SET("%s%s%s", acl_bits_p, egress_bits_p, native_indexed_mode_bits);
                }
            }
            else
            {
                if (dnx_data_lif.
                    in_lif.feature_get(unit, dnx_data_lif_in_lif_use_in_lif_profile_range_allocation_per_pmf_profiles)
                    && (IN_LIF_PROFILE_PMF_RESERVED_NOF_BITS > 0))
                {
                    PRT_CELL_SET("%s%s%s%s", acl_value_binary_buffer_full, egress_bits_p, native_indexed_mode_bits,
                                 prefix_value_binary_buffer_full);
                }
                else
                {
                    PRT_CELL_SET("%s%s%s%s", acl_bits_p, egress_bits_p, native_indexed_mode_bits,
                                 prefix_value_binary_buffer_full);
                }
            }
            if (dnx_data_lif.
                in_lif.feature_get(unit, dnx_data_lif_in_lif_use_in_lif_profile_range_allocation_per_pmf_profiles))
            {
                SHR_IF_ERR_EXIT(dnx_in_lif_profile_template_data_get
                                (unit, in_lif_profile, LIF, &in_lif_profile_template_data));
                PRT_CELL_SET("%d", in_lif_profile_template_data.field_class_id);
            }
            dbal_entry_key_field32_set(unit, entry_handle_id_vsi_profile, DBAL_FIELD_VSI_PROFILE, in_lif_profile);
            SHR_IF_ERR_EXIT(dbal_entry_get(unit, entry_handle_id_vsi_profile, DBAL_GET_ALL_FIELDS));
            SHR_IF_ERR_EXIT(dbal_entry_handle_value_field32_get
                            (unit, entry_handle_id_vsi_profile, DBAL_FIELD_ROUTING_ENABLERS_PROFILE, INST_SINGLE,
                             &routing_enablers_profile));
            PRT_CELL_SET("%d", routing_enablers_profile);
            SHR_IF_ERR_EXIT(dbal_entry_handle_value_field32_get
                            (unit, entry_handle_id, DBAL_FIELD_RPF_MODE, INST_SINGLE, &rpf_mode));
            SHR_IF_ERR_EXIT(dbal_table_field32_printable_string_get
                            (unit, DBAL_TABLE_IN_LIF_PROFILE_TABLE, DBAL_FIELD_RPF_MODE, 0, rpf_mode, NULL, 0,
                             FALSE, buffer));
            PRT_CELL_SET("%s", buffer);
            SHR_IF_ERR_EXIT(dbal_entry_handle_value_field32_get
                            (unit, entry_handle_id, DBAL_FIELD_L_2_CP_TRAP_HANDLING_PROFILE, INST_SINGLE,
                             &l2tp_trap_handling_profile));
            PRT_CELL_SET("%d", l2tp_trap_handling_profile);
            SHR_IF_ERR_EXIT(dbal_entry_handle_value_field32_get
                            (unit, entry_handle_id, DBAL_FIELD_ICMPV4_TRAP_HANDLING_PROFILE, INST_SINGLE,
                             &icmpv4_trap_handling_profile));
            PRT_CELL_SET("%d", icmpv4_trap_handling_profile);
            SHR_IF_ERR_EXIT(dbal_entry_handle_value_field32_get
                            (unit, entry_handle_id, DBAL_FIELD_ICMPV6_TRAP_HANDLING_PROFILE, INST_SINGLE,
                             &icmpv6_trap_handling_profile));
            PRT_CELL_SET("%d", icmpv6_trap_handling_profile);
            SHR_IF_ERR_EXIT(dbal_entry_handle_value_field32_get
                            (unit, entry_handle_id, DBAL_FIELD_ARP_TRAP_HANDLING_PROFILE, INST_SINGLE,
                             &arp_trap_handling_profile));
            PRT_CELL_SET("%d", arp_trap_handling_profile);
            SHR_IF_ERR_EXIT(dbal_entry_handle_value_field32_get
                            (unit, entry_handle_id, DBAL_FIELD_IGMP_TRAP_HANDLING_PROFILE, INST_SINGLE,
                             &igmp_trap_handling_profile));
            PRT_CELL_SET("%d", igmp_trap_handling_profile);
            SHR_IF_ERR_EXIT(dbal_entry_handle_value_field32_get
                            (unit, entry_handle_id, DBAL_FIELD_DHCP_TRAP_HANDLING_PROFILE, INST_SINGLE,
                             &dhcp_trap_handling_profile));
            PRT_CELL_SET("%d", dhcp_trap_handling_profile);
            SHR_IF_ERR_EXIT(dbal_entry_handle_value_field32_get
                            (unit, entry_handle_id, DBAL_FIELD_NON_AUTH_8021X_TRAP_HANDLING_PROFILE, INST_SINGLE,
                             &non_auth_8021x_trap_handling_profile));
            PRT_CELL_SET("%d", non_auth_8021x_trap_handling_profile);
            SHR_IF_ERR_EXIT(dbal_entry_handle_value_field32_get
                            (unit, entry_handle_id, DBAL_FIELD_CS_IN_LIF_VTT_TO_VTT_PROFILE, INST_SINGLE,
                             &cs_in_lif_vtt_profile));
            PRT_CELL_SET("%d", cs_in_lif_vtt_profile);
            SHR_IF_ERR_EXIT(dbal_entry_handle_value_field32_get
                            (unit, entry_handle_id, DBAL_FIELD_CS_IN_LIF_FLP_TO_FLP_PROFILE, INST_SINGLE,
                             &cs_in_lif_fwd_profile));
            PRT_CELL_SET("%d", cs_in_lif_fwd_profile);
            SHR_IF_ERR_EXIT(dbal_entry_handle_value_field32_get
                            (unit, entry_handle_id, DBAL_FIELD_DA_NOT_FOUND_DESTINATION_PROFILE, INST_SINGLE,
                             &da_not_found_destination_profile));
            PRT_CELL_SET("%d", da_not_found_destination_profile);
            SHR_IF_ERR_EXIT(dbal_entry_handle_value_field32_get
                            (unit, entry_handle_id, DBAL_FIELD_OAM_DEFAULT_PROFILE, INST_SINGLE, &oam_default_profile));
            PRT_CELL_SET("%d", oam_default_profile);
            if (dnx_data_lif.in_lif.feature_get(unit, dnx_data_lif_in_lif_use_mapped_in_lif_profile))
            {
                dbal_entry_key_field32_set(unit, entry_handle_id_mapped_in_lif_profile,
                                           DBAL_FIELD_MAPPED_IN_LIF_PROFILE, in_lif_profile);
                SHR_IF_ERR_EXIT(dbal_entry_get(unit, entry_handle_id_mapped_in_lif_profile, DBAL_GET_ALL_FIELDS));
                SHR_IF_ERR_EXIT(dbal_entry_handle_value_field32_get
                                (unit, entry_handle_id_mapped_in_lif_profile, DBAL_FIELD_IN_LIF_ORIENTATION,
                                 INST_SINGLE, &in_lif_orientation));
                PRT_CELL_SET("%d", in_lif_orientation);
                SHR_IF_ERR_EXIT(dbal_entry_handle_value_field32_get
                                (unit, entry_handle_id_mapped_in_lif_profile, DBAL_FIELD_INNER_DP_PROFILE, INST_SINGLE,
                                 &ive_outer_qos_dp_profile));
                PRT_CELL_SET("%d", ive_outer_qos_dp_profile);
                SHR_IF_ERR_EXIT(dbal_entry_handle_value_field32_get
                                (unit, entry_handle_id_mapped_in_lif_profile, DBAL_FIELD_OUTER_DP_PROFILE, INST_SINGLE,
                                 &ive_inner_qos_dp_profile));
                PRT_CELL_SET("%d", ive_inner_qos_dp_profile);
                SHR_IF_ERR_EXIT(dbal_entry_handle_value_field32_get
                                (unit, entry_handle_id_mapped_in_lif_profile, DBAL_FIELD_IN_LIF_SAME_INTERFACE,
                                 INST_SINGLE, &lif_same_interface_mode));
                SHR_IF_ERR_EXIT(dbal_table_field32_printable_string_get
                                (unit, DBAL_TABLE_MAPPED_IN_LIF_PROFILE_TABLE, DBAL_FIELD_IN_LIF_SAME_INTERFACE, 0,
                                 lif_same_interface_mode, NULL, 0, FALSE, buffer));
                PRT_CELL_SET("%s", buffer);
            }
            /** Receive next entry in table.*/
            saved_index = in_lif_profile;
            if (in_lif_profile == 0)
            {
                default_entry = 1;
            }
        }
        SHR_IF_ERR_EXIT(dbal_iterator_get_next(unit, entry_handle_id, &is_end));
    }
    PRT_COMMITX;
exit:
    SHR_FREE(acl_bits_p);
    SHR_FREE(ingress_bits_p);
    SHR_FREE(egress_bits_p);
    SHR_FREE(native_indexed_mode_bits);
    SHR_FREE(buffer);
    SHR_FREE(prefix_value_binary_buffer);
    SHR_FREE(prefix_value_binary_buffer_full);
    SHR_FREE(acl_value_binary_buffer);
    SHR_FREE(acl_value_binary_buffer_full);
    PRT_FREE;
    DBAL_FUNC_FREE_VARS;
    SHR_FUNC_EXIT;
}

/**
 * \brief The function prints the egress bits from the inlif profile
 */
static shr_error_e
sh_dnx_pp_occ_ingress_profile_native_indexed_mode_bits_print(
    int unit,
    args_t * args,
    sh_sand_control_t * sand_control)
{
    uint32 entry_handle_id, in_lif_profile;
    int is_end, native_idx_mode_msb_bit, nof_ingress_bits;
    char *acl_bits_p = NULL;
    char *ingress_bits_p = NULL;
    char *native_indexed_mode_bits = NULL;
    char *egress_bits_p = NULL;
    char *prefix_value_binary_buffer = NULL;
    int saved_index, default_entry;

    PRT_INIT_VARS;
    SHR_FUNC_INIT_VARS(unit);
    DBAL_FUNC_INIT_VARS(unit);
    SHR_ALLOC(acl_bits_p, sizeof(*acl_bits_p) * (IN_LIF_PROFILE_PMF_RESERVED_NOF_BITS + 1),
              "acl_bits_p", "%s%s%s", EMPTY, EMPTY, EMPTY);
    SHR_ALLOC(ingress_bits_p, sizeof(*ingress_bits_p) * (NOF_IN_LIF_PROFILE_INGRESS_BITS + 1),
              "ingress_bits_p", "%s%s%s", EMPTY, EMPTY, EMPTY);
    SHR_ALLOC(egress_bits_p, sizeof(*egress_bits_p) * (IN_LIF_PROFILE_EGRESS_RESERVED_NOF_BITS + 1), "egress_bits_p",
              "%s%s%s", EMPTY, EMPTY, EMPTY);
    SHR_ALLOC(native_indexed_mode_bits, sizeof(*native_indexed_mode_bits) * (NATIVE_INDEXED_MODE_NOF_BITS + 1),
              "native_indexed_mode_bits", "%s%s%s", EMPTY, EMPTY, EMPTY);
    SHR_ALLOC_SET_ZERO(prefix_value_binary_buffer,
                       sizeof(*prefix_value_binary_buffer) * (NATIVE_INDEXED_MODE_NOF_BITS + 1),
                       "prefix_value_binary_buffer", "%s%s%s", EMPTY, EMPTY, EMPTY);

    is_end = 0;
    in_lif_profile = 0;
    native_idx_mode_msb_bit = IN_LIF_PROFILE_EGRESS_RESERVED_START_BIT;
    nof_ingress_bits = NOF_IN_LIF_PROFILE_INGRESS_BITS;
    saved_index = 0;
    default_entry = 0;

    sh_dnx_pp_occ_in_lif_profile_masked_bits_print(unit, acl_bits_p, egress_bits_p, ingress_bits_p,
                                                   native_indexed_mode_bits);

    PRT_TITLE_SET("Native Indexed mode bits");
    PRT_COLUMN_ADD_FLEX(PRT_FLEX_ASCII, "InLif Profile");
    PRT_COLUMN_ADD_FLEX(PRT_FLEX_ASCII, "Native Indexed Mode");
    /** Taking a handle */
    SHR_IF_ERR_EXIT(DBAL_HANDLE_ALLOC(unit, DBAL_TABLE_IN_LIF_PROFILE_TABLE, &entry_handle_id));
    SHR_IF_ERR_EXIT(dbal_iterator_init(unit, entry_handle_id, DBAL_ITER_MODE_ALL));
    /*
     * Receive first entry in table.
     */
    SHR_IF_ERR_EXIT(dbal_iterator_get_next(unit, entry_handle_id, &is_end));
    while (!is_end)
    {
        SHR_IF_ERR_EXIT(dbal_entry_handle_key_field_arr32_get
                        (unit, entry_handle_id, DBAL_FIELD_IN_LIF_PROFILE, &in_lif_profile));
        in_lif_profile = in_lif_profile & ((1 << native_idx_mode_msb_bit) - 1);
        in_lif_profile = in_lif_profile >> nof_ingress_bits;
        if ((saved_index < in_lif_profile) || ((default_entry == 0) && (in_lif_profile == 0)))
        {
            PRT_ROW_ADD(PRT_ROW_SEP_UNDERSCORE);
            sal_itoa(prefix_value_binary_buffer, in_lif_profile, 2, 0, 0);
            PRT_CELL_SET("%s%s%s%s", acl_bits_p, egress_bits_p, prefix_value_binary_buffer, ingress_bits_p);
            PRT_CELL_SET("%d", in_lif_profile);
            /** Receive next entry in table.*/
            saved_index = in_lif_profile;
            if (in_lif_profile == 0)
            {
                default_entry = 1;
            }
        }
        SHR_IF_ERR_EXIT(dbal_iterator_get_next(unit, entry_handle_id, &is_end));
    }
    PRT_COMMITX;

exit:
    SHR_FREE(acl_bits_p);
    SHR_FREE(ingress_bits_p);
    SHR_FREE(egress_bits_p);
    SHR_FREE(native_indexed_mode_bits);
    SHR_FREE(prefix_value_binary_buffer);
    PRT_FREE;
    DBAL_FUNC_FREE_VARS;
    SHR_FUNC_EXIT;
}

/**
 * \brief
 *    A diagnostics function that prints the inlif profile allocated resources
 * \param [in] unit - unit ID
 * \param [in] args - arguments passed to the function according to the diag mechanism
 * \param [in] sand_control - passed according to the diag mechanism
 * \return
 *   \retval Zero if no error was detected
 *   \retval Negative if error was detected. See \ref shr_error_e
 */
static shr_error_e
sh_dnx_pp_occ_inlif_profile_print_cmd(
    int unit,
    args_t * args,
    sh_sand_control_t * sand_control)
{
    int system_headers_mode;
    SHR_FUNC_INIT_VARS(unit);
    system_headers_mode = dnx_data_headers.system_headers.system_headers_mode_get(unit);
    /** Print egress bits information from inlif profile*/
    if (!dnx_data_lif.in_lif.feature_get(unit, dnx_data_lif_in_lif_mapped_in_lif_profile))
    {
        /**
         * This function should execute only for devices that do not support lif profile remap.
         * For such that do support it and the egress bits are not part of the template (IOP mode), there's a dedicated function
         */
        SHR_IF_ERR_EXIT(sh_dnx_pp_occ_ingress_profile_egress_bits_print(unit, args, sand_control));
    }
    else if ((system_headers_mode == DBAL_ENUM_FVAL_SYSTEM_HEADERS_MODE_JERICHO_MODE)
             && dnx_data_lif.feature.feature_get(unit, dnx_data_lif_feature_iop_mode_orientation_selection))
    {
        SHR_IF_ERR_EXIT(sh_dnx_pp_occ_ingress_profile_jr_mode_egress_bits_print(unit, args, sand_control));
    }
    else if ((system_headers_mode == DBAL_ENUM_FVAL_SYSTEM_HEADERS_MODE_JERICHO_MODE)
             && !dnx_data_lif.feature.feature_get(unit, dnx_data_lif_feature_iop_mode_orientation_selection))
    {
        SHR_IF_ERR_EXIT(sh_dnx_pp_occ_ingress_profile_jr_mode_not_fixed_egress_bits_print(unit, args, sand_control));
    }
    if (NATIVE_INDEXED_MODE_NOF_BITS)
    {
        SHR_IF_ERR_EXIT(sh_dnx_pp_occ_ingress_profile_native_indexed_mode_bits_print(unit, args, sand_control));
    }
    /** Print ingress bits information from inlif profile*/
    SHR_IF_ERR_EXIT(sh_dnx_pp_occ_in_lif_profile_ingress_bits_print(unit, args, sand_control));

exit:

    SHR_FUNC_EXIT;
}

/**
 * \brief
 *    A diagnostics function that prints the vsi profile allocated resources
 * \param [in] unit - unit ID
 * \param [in] args - arguments passed to the function according to the diag mechanism
 * \param [in] sand_control - passed according to the diag mechanism
 * \return
 *   \retval Zero if no error was detected
 *   \retval Negative if error was detected. See \ref shr_error_e
 */
static shr_error_e
sh_dnx_pp_occ_eth_rif_profile_ingress_bits_print(
    int unit,
    args_t * args,
    sh_sand_control_t * sand_control)
{
    uint32 entry_handle_id_vsi_profile = 0, entry_handle_id_lif_profile = 0, routing_enablers_profile, vsi_profile,
        ivl_svl_mode, fwd_type;
    int is_end, saved_profile, default_entry, ingress_bits_mask, nof_ingress_bits, nof_egress_bits;
    char *prefix_value_binary_buffer = NULL;
    char *prefix_value_binary_buffer_full = NULL;
    uint32 rpf_mode, icmpv4_trap_handling_profile, icmpv6_trap_handling_profile, arp_trap_handling_profile,
        igmp_trap_handling_profile, non_auth_8021x_trap_handling_profile, cs_in_lif_vtt_profile, cs_in_lif_fwd_profile,
        oam_default_profile, da_not_found_destination_profile, dhcp_trap_handling_profile, in_lif_lb_profile,
        l2tp_trap_handling_profile;
    char *acl_bits_p = NULL;
    char *ingress_bits_p = NULL;
    char *egress_bits_p = NULL;
    char *buffer = NULL;
    char *acl_profile_bits = NULL;

    PRT_INIT_VARS;
    SHR_FUNC_INIT_VARS(unit);
    DBAL_FUNC_INIT_VARS(unit);
    SHR_ALLOC(acl_bits_p, sizeof(*acl_bits_p) * (ETH_RIF_PROFILE_PMF_RESERVED_NOF_BITS + 1),
              "acl_bits_p", "%s%s%s", EMPTY, EMPTY, EMPTY);
    SHR_ALLOC_SET_ZERO(buffer, sizeof(*buffer) * (DBAL_MAX_PRINTABLE_BUFFER_SIZE + 1), "buffer", "%s%s%s", EMPTY, EMPTY,
                       EMPTY);
    SHR_ALLOC(acl_profile_bits, sizeof(*acl_profile_bits) * (DBAL_MAX_STRING_LENGTH + 1), "acl_profile_bits", "%s%s%s",
              EMPTY, EMPTY, EMPTY);

    is_end = 0;
    routing_enablers_profile = 0;
    vsi_profile = 0;
    ivl_svl_mode = 0;
    fwd_type = 0;
    saved_profile = CALCULATE_VSI_PROFILE_FROM_ETH_RIF_PROFILE(VSI_MSB_PREFIX, 1);
    default_entry = CALCULATE_VSI_PROFILE_FROM_ETH_RIF_PROFILE(VSI_MSB_PREFIX, 1);
    nof_ingress_bits = 0;
    nof_egress_bits = 0;

    if (ETH_RIF_PROFILE_PMF_RESERVED_NOF_BITS == 0)
    {
        sal_snprintf(acl_profile_bits, DBAL_MAX_STRING_LENGTH, "%s", "No ACL profile bits");
    }
    else
    {
        sal_snprintf(acl_profile_bits, DBAL_MAX_STRING_LENGTH, "%s%d %s %d%s", "ACL profile bits [",
                     NOF_ETH_RIF_PROFILE_BITS - 1, ":", ETH_RIF_PROFILE_PMF_RESERVED_START_BIT, "]");
    }

    if ((dnx_data_headers.system_headers.system_headers_mode_get(unit) ==
         DBAL_ENUM_FVAL_SYSTEM_HEADERS_MODE_JERICHO2_MODE)
        ||
        ((dnx_data_headers.system_headers.system_headers_mode_get(unit) ==
          DBAL_ENUM_FVAL_SYSTEM_HEADERS_MODE_JERICHO_MODE)
         && !(dnx_data_qos.qos.routing_dscp_preserve_mode_get(unit) == 1)))
    {
        nof_ingress_bits = NOF_ETH_RIF_PROFILE_INGRESS_BITS;
        SHR_ALLOC(egress_bits_p, sizeof(*egress_bits_p) * 1, "egress_bits_p", "%s%s%s", EMPTY, EMPTY, EMPTY);
        PRT_TITLE_SET("Ingress-PP VSI profile table");
        PRT_INFO_ADD
            ("Profile bits separation: %s, Ingress ETH RIF profile bits = [%d : %d]",
             acl_profile_bits, ETH_RIF_PROFILE_EGRESS_RESERVED_START_BIT - 1, 0);
        PRT_COMMITX;
    }
    else
    {
        if (dnx_data_lif.feature.feature_get(unit, dnx_data_lif_feature_iop_mode_orientation_selection))
        {
            nof_egress_bits = IN_LIF_PROFILE_EGRESS_NOF_BITS_JR_MODE;
        }
        else
        {
            nof_egress_bits = IN_LIF_PROFILE_EGRESS_NOF_BITS_DSCP_MODE;
        }
        nof_ingress_bits = NOF_ETH_RIF_PROFILE_INGRESS_BITS - nof_egress_bits;
        SHR_ALLOC(egress_bits_p, sizeof(*egress_bits_p) * (nof_egress_bits + 1),
                  "egress_bits_p", "%s%s%s", EMPTY, EMPTY, EMPTY);
    }
    ingress_bits_mask = (1 << nof_ingress_bits) - 1;
    SHR_ALLOC(ingress_bits_p, sizeof(*ingress_bits_p) * (nof_ingress_bits + 1),
              "ingress_bits_p", "%s%s%s", EMPTY, EMPTY, EMPTY);
    SHR_ALLOC_SET_ZERO(prefix_value_binary_buffer, sizeof(*prefix_value_binary_buffer) * (nof_ingress_bits + 1),
                       "prefix_value_binary_buffer", "%s%s%s", EMPTY, EMPTY, EMPTY);
    SHR_ALLOC_SET_ZERO(prefix_value_binary_buffer_full,
                       sizeof(*prefix_value_binary_buffer_full) * (nof_ingress_bits + 1),
                       "prefix_value_binary_buffer_full", "%s%s%s", EMPTY, EMPTY, EMPTY);

    sh_dnx_pp_occ_eth_rif_profile_masked_bits_print(unit, acl_bits_p, egress_bits_p, ingress_bits_p);
    PRT_TITLE_SET("ETH RIF profile");
    PRT_COLUMN_ADD_FLEX(PRT_FLEX_ASCII, "ETH RIF Profile");
    PRT_COLUMN_ADD_FLEX(PRT_FLEX_ASCII, "Routing Enablers Profile");
    PRT_COLUMN_ADD_FLEX(PRT_FLEX_ASCII, "IVL/SVL Lookup Mode");
    PRT_COLUMN_ADD_FLEX(PRT_FLEX_ASCII, "MCv4 forwarding type");
    PRT_COLUMN_ADD_FLEX(PRT_FLEX_ASCII, "MCv6 forwarding type");
    if (dnx_data_switch.load_balancing.hashing_selection_per_layer_get(unit))
    {
        PRT_COLUMN_ADD_FLEX(PRT_FLEX_ASCII, "LIF LB enablers profile");
    }
    PRT_COLUMN_ADD_FLEX(PRT_FLEX_ASCII, "RPF mode");
    PRT_COLUMN_ADD_FLEX(PRT_FLEX_ASCII, "L2TP profile");
    PRT_COLUMN_ADD_FLEX(PRT_FLEX_ASCII, "ICMPV4 profile");
    PRT_COLUMN_ADD_FLEX(PRT_FLEX_ASCII, "ICMPV6 profile");
    PRT_COLUMN_ADD_FLEX(PRT_FLEX_ASCII, "ARP Profile");
    PRT_COLUMN_ADD_FLEX(PRT_FLEX_ASCII, "IGMP Profile");
    PRT_COLUMN_ADD_FLEX(PRT_FLEX_ASCII, "DHCP Profile");
    PRT_COLUMN_ADD_FLEX(PRT_FLEX_ASCII, "Non auth 802tx Profile");
    PRT_COLUMN_ADD_FLEX(PRT_FLEX_ASCII, "CS InLif VTT Profile");
    PRT_COLUMN_ADD_FLEX(PRT_FLEX_ASCII, "CS InLif FWD Profile");
    PRT_COLUMN_ADD_FLEX(PRT_FLEX_ASCII, "DA not found destination Profile");
    PRT_COLUMN_ADD_FLEX(PRT_FLEX_ASCII, "OAM Default Profile");

    /** Taking a handle */
    SHR_IF_ERR_EXIT(DBAL_HANDLE_ALLOC(unit, DBAL_TABLE_VSI_PROFILE_TABLE, &entry_handle_id_vsi_profile));
    SHR_IF_ERR_EXIT(DBAL_HANDLE_ALLOC(unit, DBAL_TABLE_IN_LIF_PROFILE_TABLE, &entry_handle_id_lif_profile));

    SHR_IF_ERR_EXIT(dbal_iterator_init(unit, entry_handle_id_vsi_profile, DBAL_ITER_MODE_GET_ALL_EXCEPT_DEFAULT));

    /*
     * Receive first entry in table.
     */
    SHR_IF_ERR_EXIT(dbal_iterator_get_next(unit, entry_handle_id_vsi_profile, &is_end));
    while (!is_end)
    {
        SHR_IF_ERR_EXIT(dbal_entry_handle_key_field_arr32_get
                        (unit, entry_handle_id_vsi_profile, DBAL_FIELD_VSI_PROFILE, &vsi_profile));
        if ((((saved_profile & ingress_bits_mask) < (vsi_profile & ingress_bits_mask))
             && (vsi_profile >= CALCULATE_VSI_PROFILE_FROM_ETH_RIF_PROFILE(VSI_MSB_PREFIX, 1)))
            || ((default_entry == CALCULATE_VSI_PROFILE_FROM_ETH_RIF_PROFILE(VSI_MSB_PREFIX, 1))
                && (vsi_profile == CALCULATE_VSI_PROFILE_FROM_ETH_RIF_PROFILE(VSI_MSB_PREFIX, 1))))
        {
            PRT_ROW_ADD(PRT_ROW_SEP_UNDERSCORE);
            sal_itoa(prefix_value_binary_buffer, vsi_profile & ingress_bits_mask, 2, 0, 0);
            sh_dnx_pp_occ_masked_bits_print(nof_ingress_bits, nof_ingress_bits, prefix_value_binary_buffer,
                                            prefix_value_binary_buffer_full);
            PRT_CELL_SET("%s%s%s", acl_bits_p, egress_bits_p, prefix_value_binary_buffer_full);
            SHR_IF_ERR_EXIT(dbal_entry_handle_value_field32_get
                            (unit, entry_handle_id_vsi_profile, DBAL_FIELD_ROUTING_ENABLERS_PROFILE, INST_SINGLE,
                             &routing_enablers_profile));
            PRT_CELL_SET("%d", routing_enablers_profile);
            SHR_IF_ERR_EXIT(dbal_entry_handle_value_field32_get
                            (unit, entry_handle_id_vsi_profile, DBAL_FIELD_VSI_PROFILE_BRIDGE, INST_SINGLE,
                             &ivl_svl_mode));
            PRT_CELL_SET("%d", ivl_svl_mode);
            SHR_IF_ERR_EXIT(dbal_entry_handle_value_field32_get
                            (unit, entry_handle_id_vsi_profile, DBAL_FIELD_L2_V4_MC_FWD_TYPE, INST_SINGLE, &fwd_type));
            PRT_CELL_SET("%d", fwd_type);
            SHR_IF_ERR_EXIT(dbal_entry_handle_value_field32_get
                            (unit, entry_handle_id_vsi_profile, DBAL_FIELD_L2_V6_MC_FWD_TYPE, INST_SINGLE, &fwd_type));
            PRT_CELL_SET("%d", fwd_type);

            dbal_entry_key_field32_set(unit, entry_handle_id_lif_profile, DBAL_FIELD_IN_LIF_PROFILE,
                                       (vsi_profile & 0xFF));
            SHR_IF_ERR_EXIT(dbal_entry_get(unit, entry_handle_id_lif_profile, DBAL_GET_ALL_FIELDS));
            if (dnx_data_switch.load_balancing.hashing_selection_per_layer_get(unit))
            {
                SHR_IF_ERR_EXIT(dbal_entry_handle_value_field32_get
                                (unit, entry_handle_id_lif_profile, DBAL_FIELD_IN_LIF_LB_PROFILE, INST_SINGLE,
                                 &in_lif_lb_profile));
                PRT_CELL_SET("%d", in_lif_lb_profile);
            }
            SHR_IF_ERR_EXIT(dbal_entry_handle_value_field32_get
                            (unit, entry_handle_id_lif_profile, DBAL_FIELD_RPF_MODE, INST_SINGLE, &rpf_mode));
            SHR_IF_ERR_EXIT(dbal_table_field32_printable_string_get
                            (unit, DBAL_TABLE_IN_LIF_PROFILE_TABLE, DBAL_FIELD_RPF_MODE, 0, rpf_mode, NULL, 0,
                             FALSE, buffer));
            PRT_CELL_SET("%s", buffer);
            SHR_IF_ERR_EXIT(dbal_entry_handle_value_field32_get
                            (unit, entry_handle_id_lif_profile, DBAL_FIELD_L_2_CP_TRAP_HANDLING_PROFILE, INST_SINGLE,
                             &l2tp_trap_handling_profile));
            PRT_CELL_SET("%d", l2tp_trap_handling_profile);
            SHR_IF_ERR_EXIT(dbal_entry_handle_value_field32_get
                            (unit, entry_handle_id_lif_profile, DBAL_FIELD_ICMPV4_TRAP_HANDLING_PROFILE, INST_SINGLE,
                             &icmpv4_trap_handling_profile));
            PRT_CELL_SET("%d", icmpv4_trap_handling_profile);
            SHR_IF_ERR_EXIT(dbal_entry_handle_value_field32_get
                            (unit, entry_handle_id_lif_profile, DBAL_FIELD_ICMPV6_TRAP_HANDLING_PROFILE, INST_SINGLE,
                             &icmpv6_trap_handling_profile));
            PRT_CELL_SET("%d", icmpv6_trap_handling_profile);
            SHR_IF_ERR_EXIT(dbal_entry_handle_value_field32_get
                            (unit, entry_handle_id_lif_profile, DBAL_FIELD_ARP_TRAP_HANDLING_PROFILE, INST_SINGLE,
                             &arp_trap_handling_profile));
            PRT_CELL_SET("%d", arp_trap_handling_profile);
            SHR_IF_ERR_EXIT(dbal_entry_handle_value_field32_get
                            (unit, entry_handle_id_lif_profile, DBAL_FIELD_IGMP_TRAP_HANDLING_PROFILE, INST_SINGLE,
                             &igmp_trap_handling_profile));
            PRT_CELL_SET("%d", igmp_trap_handling_profile);
            SHR_IF_ERR_EXIT(dbal_entry_handle_value_field32_get
                            (unit, entry_handle_id_lif_profile, DBAL_FIELD_DHCP_TRAP_HANDLING_PROFILE, INST_SINGLE,
                             &dhcp_trap_handling_profile));
            PRT_CELL_SET("%d", dhcp_trap_handling_profile);
            SHR_IF_ERR_EXIT(dbal_entry_handle_value_field32_get
                            (unit, entry_handle_id_lif_profile, DBAL_FIELD_NON_AUTH_8021X_TRAP_HANDLING_PROFILE,
                             INST_SINGLE, &non_auth_8021x_trap_handling_profile));
            PRT_CELL_SET("%d", non_auth_8021x_trap_handling_profile);
            SHR_IF_ERR_EXIT(dbal_entry_handle_value_field32_get
                            (unit, entry_handle_id_lif_profile, DBAL_FIELD_CS_IN_LIF_VTT_TO_VTT_PROFILE, INST_SINGLE,
                             &cs_in_lif_vtt_profile));
            PRT_CELL_SET("%d", cs_in_lif_vtt_profile);
            SHR_IF_ERR_EXIT(dbal_entry_handle_value_field32_get
                            (unit, entry_handle_id_lif_profile, DBAL_FIELD_CS_IN_LIF_FLP_TO_FLP_PROFILE, INST_SINGLE,
                             &cs_in_lif_fwd_profile));
            PRT_CELL_SET("%d", cs_in_lif_fwd_profile);
            SHR_IF_ERR_EXIT(dbal_entry_handle_value_field32_get
                            (unit, entry_handle_id_lif_profile, DBAL_FIELD_DA_NOT_FOUND_DESTINATION_PROFILE,
                             INST_SINGLE, &da_not_found_destination_profile));
            PRT_CELL_SET("%d", da_not_found_destination_profile);
            SHR_IF_ERR_EXIT(dbal_entry_handle_value_field32_get
                            (unit, entry_handle_id_lif_profile, DBAL_FIELD_OAM_DEFAULT_PROFILE, INST_SINGLE,
                             &oam_default_profile));
            PRT_CELL_SET("%d", oam_default_profile);
            saved_profile = vsi_profile;
            if (vsi_profile == CALCULATE_VSI_PROFILE_FROM_ETH_RIF_PROFILE(VSI_MSB_PREFIX, 1))
            {
                default_entry = CALCULATE_VSI_PROFILE_FROM_ETH_RIF_PROFILE(VSI_MSB_PREFIX, 2);
            }

        }
        /** Receive next entry in table.*/
        SHR_IF_ERR_EXIT(dbal_iterator_get_next(unit, entry_handle_id_vsi_profile, &is_end));
    }
    PRT_COMMITX;
exit:
    SHR_FREE(acl_bits_p);
    SHR_FREE(ingress_bits_p);
    SHR_FREE(egress_bits_p);
    SHR_FREE(buffer);
    SHR_FREE(acl_profile_bits);
    SHR_FREE(prefix_value_binary_buffer);
    SHR_FREE(prefix_value_binary_buffer_full);
    PRT_FREE;
    DBAL_FUNC_FREE_VARS;
    SHR_FUNC_EXIT;
}

/**
 * \brief
 *    A diagnostics function that prints the inlif profile allocated resources
 * \param [in] unit - unit ID
 * \param [in] args - arguments passed to the function according to the diag mechanism
 * \param [in] sand_control - passed according to the diag mechanism
 * \return
 *   \retval Zero if no error was detected
 *   \retval Negative if error was detected. See \ref shr_error_e
 */
static shr_error_e
sh_dnx_pp_occ_eth_rif_profile_print_cmd(
    int unit,
    args_t * args,
    sh_sand_control_t * sand_control)
{
    int system_headers_mode;
    SHR_FUNC_INIT_VARS(unit);
    system_headers_mode = dnx_data_headers.system_headers.system_headers_mode_get(unit);
    /** Print egress bits information from inlif profile*/
    if ((system_headers_mode == DBAL_ENUM_FVAL_SYSTEM_HEADERS_MODE_JERICHO_MODE) &&
        (dnx_data_qos.qos.routing_dscp_preserve_mode_get(unit) == 1))
    {
        SHR_IF_ERR_EXIT(sh_dnx_pp_occ_eth_rif_profile_jr_mode_egress_bits_print(unit, args, sand_control));
    }
    /** Print ingress bits information from inlif profile*/
    SHR_IF_ERR_EXIT(sh_dnx_pp_occ_eth_rif_profile_ingress_bits_print(unit, args, sand_control));

exit:

    SHR_FUNC_EXIT;
}

/**
 * \brief
 *    A diagnostics function that prints the inlif profile allocated resources
 * \param [in] unit - unit ID
 * \param [in] args - arguments passed to the function according to the diag mechanism
 * \param [in] sand_control - passed according to the diag mechanism
 * \return
 *   \retval Zero if no error was detected
 *   \retval Negative if error was detected. See \ref shr_error_e
 */
#if defined(BCM_DNX2_SUPPORT)
static shr_error_e
sh_dnx_pp_occ_erpp_profile_print_cmd(
    int unit,
    args_t * args,
    sh_sand_control_t * sand_control)
{
    uint32 entry_handle_id, out_lif_profile, ttl_threshold, ttl_threshold_index, entry_handle_tth_threshold_id;
    int is_end, outlif_profile_width, max_number_of_pp_profiles;
    char *prefix_value_binary_buffer = NULL;
    char *prefix_value_binary_buffer_full = NULL;
    char *acl_bits_p = NULL;
    int system_headers_mode, iop_mode_outlif_selection;
    PRT_INIT_VARS;
    SHR_FUNC_INIT_VARS(unit);
    DBAL_FUNC_INIT_VARS(unit);

    is_end = 0;
    out_lif_profile = 0;
    ttl_threshold = 0;
    ttl_threshold_index = 0;
    entry_handle_tth_threshold_id = 0;
    system_headers_mode = dnx_data_headers.system_headers.system_headers_mode_get(unit);
    iop_mode_outlif_selection = dnx_data_lif.feature.feature_get(unit, dnx_data_lif_feature_iop_mode_outlif_selection);

    /** In IOP mode, the RIFs are added in the namespace of the LIF and have only 1 bit for lif profile */
    if ((system_headers_mode == DBAL_ENUM_FVAL_SYSTEM_HEADERS_MODE_JERICHO2_MODE) ||
        (iop_mode_outlif_selection == FALSE))
    {
        outlif_profile_width = utilex_log2_round_up(dnx_data_lif.out_lif.nof_erpp_out_lif_profiles_get(unit));
    }
    else
    {
        outlif_profile_width = utilex_log2_round_up(DNX_ALGO_ERPP_IOP_MODE_OUTLIF_SELECTION_NOF_PROFILES);
    }

    max_number_of_pp_profiles = (1 << (outlif_profile_width)) - 1;

    SHR_ALLOC(acl_bits_p, sizeof(*acl_bits_p) * 2, "acl_bits_p", "%s%s%s", EMPTY, EMPTY, EMPTY);
    SHR_ALLOC_SET_ZERO(prefix_value_binary_buffer, sizeof(*prefix_value_binary_buffer) * (outlif_profile_width + 1),
                       "prefix_value_binary_buffer", "%s%s%s", EMPTY, EMPTY, EMPTY);
    SHR_ALLOC_SET_ZERO(prefix_value_binary_buffer_full,
                       sizeof(*prefix_value_binary_buffer_full) * (outlif_profile_width + 1),
                       "prefix_value_binary_buffer_full", "%s%s%s", EMPTY, EMPTY, EMPTY);

    acl_bits_p[0] = 'x';
    acl_bits_p[1] = 0;

    PRT_TITLE_SET("ERPP outlif profile");
    PRT_INFO_ADD
        ("Profile bits separation: ACL profile bits = [%d : %d], ERPP RIF Profile bits = [%d : %d]",
         outlif_profile_width, outlif_profile_width, outlif_profile_width - 1, 0);
    PRT_COMMITX;

    PRT_TITLE_SET("ERPP PP RIF Profile allocation");
    PRT_COLUMN_ADD_FLEX(PRT_FLEX_ASCII, "ERPP OutRif Profile");
    PRT_COLUMN_ADD_FLEX(PRT_FLEX_ASCII, "TTL Threshold");

    /** Taking a handle */
    SHR_IF_ERR_EXIT(DBAL_HANDLE_ALLOC(unit, DBAL_TABLE_ERPP_OUT_LIF_PROFILE_TABLE, &entry_handle_id));
    SHR_IF_ERR_EXIT(DBAL_HANDLE_ALLOC(unit, DBAL_TABLE_ERPP_TTL_SCOPE_TABLE, &entry_handle_tth_threshold_id));
    SHR_IF_ERR_EXIT(dbal_iterator_init(unit, entry_handle_id, DBAL_ITER_MODE_GET_ALL_EXCEPT_DEFAULT));
    /*
     * Receive first entry in table.
     */
    SHR_IF_ERR_EXIT(dbal_iterator_get_next(unit, entry_handle_id, &is_end));
    while (!is_end)
    {
        PRT_ROW_ADD(PRT_ROW_SEP_UNDERSCORE);
        SHR_IF_ERR_EXIT(dbal_entry_handle_key_field_arr32_get
                        (unit, entry_handle_id, DBAL_FIELD_OUT_LIF_PROFILE, &out_lif_profile));
        sal_itoa(prefix_value_binary_buffer, out_lif_profile, 2, 0, 0);
        sh_dnx_pp_occ_masked_bits_print(outlif_profile_width, outlif_profile_width, prefix_value_binary_buffer,
                                        prefix_value_binary_buffer_full);
        PRT_CELL_SET("%s%s", acl_bits_p, prefix_value_binary_buffer_full);
        SHR_IF_ERR_EXIT(dbal_entry_handle_value_field32_get
                        (unit, entry_handle_id, DBAL_FIELD_OUTLIF_TTL_SCOPE_INDEX, INST_SINGLE, &ttl_threshold_index));
        /** Receive next entry in table.*/
        SHR_IF_ERR_EXIT(dbal_iterator_get_next(unit, entry_handle_id, &is_end));
        dbal_entry_key_field32_set(unit, entry_handle_tth_threshold_id, DBAL_FIELD_OUTLIF_TTL_SCOPE_INDEX,
                                   ttl_threshold_index);
        SHR_IF_ERR_EXIT(dbal_entry_get(unit, entry_handle_tth_threshold_id, DBAL_GET_ALL_FIELDS));
        SHR_IF_ERR_EXIT(dbal_entry_handle_value_field32_get
                        (unit, entry_handle_tth_threshold_id, DBAL_FIELD_TTL_SCOPE, INST_SINGLE, &ttl_threshold));
        PRT_CELL_SET("%d", ttl_threshold);
        if (out_lif_profile == max_number_of_pp_profiles)
        {
            break;
        }
    }
    PRT_COMMITX;
exit:
    SHR_FREE(acl_bits_p);
    SHR_FREE(prefix_value_binary_buffer);
    SHR_FREE(prefix_value_binary_buffer_full);
    PRT_FREE;
    DBAL_FUNC_FREE_VARS;
    SHR_FUNC_EXIT;
}
#endif


sh_sand_man_t sh_dnx_pp_occ_sub_man = {
    .brief = "Displays inlif and  outlif profile allocated resources",
    .compatibility = DIAG_DNX_PP_BARE_METAL_NOT_AVAILABLE_COMMAND
};

static sh_sand_man_t sh_dnx_pp_occ_outlif_profile_sub_man = {
    .brief = "Displays outlif profile allocated resources",
};

static sh_sand_man_t sh_dnx_pp_occ_inlif_profile_sub_man = {
    .brief = "Displays inlif profile allocated resources",
};

static sh_sand_man_t sh_dnx_pp_occ_etpp_profile_sub_man = {
    .brief = "Displays ETPP profile allocated resources",
    .full =
        "Displays ETPP profile allocated resources, such as orientation, OAM priority map profile and split horizon",
};
#if defined(BCM_DNX2_SUPPORT)
static sh_sand_man_t sh_dnx_pp_occ_erpp_profile_sub_man = {
    .brief = "Displays ERPP profile allocated resources",
    .full = "Displays ERPP profile allocated resources, such as ERPP filters enablers per outlif profile",
};
#endif

static sh_sand_man_t sh_dnx_pp_occ_eth_rif_profile_sub_man = {
    .brief = "Displays ETH RIF profile allocated resources",
    .full = "Displays ETH RIF profile allocated resources. The resources are shared for ACL bits\
            inlif profile dedicated for egress usage and ingress profile bits ",
};

sh_sand_cmd_t sh_dnx_pp_occ_outlif_profile_sub_cmd[] = {

    /*
     * keyword, action, command, options, man
     */
#if defined(BCM_DNX2_SUPPORT)
    {"Etpp", sh_dnx_pp_occ_etpp_profile_print_cmd, NULL, NULL, &sh_dnx_pp_occ_etpp_profile_sub_man},
#endif
#if defined(BCM_DNX2_SUPPORT)
    {"Erpp", sh_dnx_pp_occ_erpp_profile_print_cmd, NULL, NULL, &sh_dnx_pp_occ_erpp_profile_sub_man},
#endif
    {NULL}
};

sh_sand_cmd_t sh_dnx_pp_occ_inlif_profile_sub_cmd[] = {

    /*
     * keyword, action, command, options, man
     */
    {
     "InLif", sh_dnx_pp_occ_inlif_profile_print_cmd, NULL, NULL, &sh_dnx_pp_occ_inlif_profile_sub_man},
    {
     "EthRif", sh_dnx_pp_occ_eth_rif_profile_print_cmd, NULL, NULL, &sh_dnx_pp_occ_eth_rif_profile_sub_man},
    {
     NULL}
};
sh_sand_cmd_t sh_dnx_pp_occ_sub_cmd[] = {

    /*
     * keyword, action, command, options, man
     */
    {
     "Ingress", NULL, sh_dnx_pp_occ_inlif_profile_sub_cmd, NULL, &sh_dnx_pp_occ_inlif_profile_sub_man},
    {
     "Egress", NULL, sh_dnx_pp_occ_outlif_profile_sub_cmd, NULL, &sh_dnx_pp_occ_outlif_profile_sub_man},
    {
     NULL}
};
