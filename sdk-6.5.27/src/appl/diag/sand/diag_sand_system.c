/**
 * \file diag_sand_system.c
 *
 * System commands for dnx/dnxf shells
 *
 */
/*
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2022 Broadcom Inc. All rights reserved.
 */
#include <sal/appl/sal.h>

#include <shared/dbx/dbx_xml.h>
#include <shared/dbx/dbx_file.h>
#include <soc/sand/shrextend/shrextend_debug.h>

#include <soc/drv.h>
#include <appl/diag/sand/diag_sand_framework.h>

#include <appl/diag/bslenable.h>
#include <appl/diag/parse.h>
#include <appl/diag/sand/diag_sand_utils.h>
#include <appl/diag/sand/diag_sand_prt.h>
#include <appl/diag/sand/diag_sand_system.h>
#ifdef BCM_DNX_SUPPORT
#include <bcm_int/dnx/cmn/dnxcmn.h>
#include <soc/dnx/dnx_err_recovery_manager.h>
#include <soc/dnx/dnx_er_db.h>
#endif

#include <ibde.h>

#include "diag_sand_framework_internal.h"

#define BSL_LOG_MODULE BSL_LS_APPL_SHELL

/*
 * Number of non-functional characters in argument output format
 */
#define SH_SAND_ARGUMENT_PREFIX_BASE    4
/*
 * Number of characters added to argument prefix if it is free one
 */
#define SH_SAND_ARGUMENT_FREE_TAG_SIZE  5

#define SH_SAND_LABEL_REGEX(_regex, _label) \
do { \
    sal_snprintf(_regex, SH_SAND_MAX_TOKEN_SIZE, "(,|^)+ *%s *(,|$)+", _label); \
} while(0)

/*
 * Internal structure used in sh_sand_example_internal_add.
 */
typedef struct
{
    /*
     * Range start.
     */
    char start[SH_SAND_MAX_KEYWORD_SIZE];
    /*
     * Range ind
     */
    char end[SH_SAND_MAX_KEYWORD_SIZE];
    /*
     * Option keyword.
     */
    char keyword[SH_SAND_MAX_KEYWORD_SIZE];
    /*
     * Flag to mark the option has range.
     */
    uint8 is_range_option;
    /*
     * Flag to mark the option has value.
     */
    uint8 equal;
} sh_sand_range_example_t;

static void
sh_sand_examples_list_free(
    int unit,
    rhlist_t * test_list)
{
    sh_sand_test_t *test_invoke;
    if (test_list == NULL)
    {
        /*
         * List was never created or freed already
         */
        return;
    }
    /*
     * Go through each element and free allocations
     */
    RHITERATOR(test_invoke, test_list)
    {
        if (test_invoke->params != NULL)
        {
            sal_free(test_invoke->params);
        }
    }
    utilex_rhlist_free_all(test_list);
}

shr_error_e
sh_sand_example_add(
    int unit,
    int flags,
    sh_sand_cmd_t * sh_sand_cmd,
    rhlist_t * examples_list,
    char *arguments_string)
{
    int str_size;
    sh_sand_test_t *example_invoke;
    rhhandle_t void_example;
    char example_name[RHNAME_MAX_SIZE];

    SHR_FUNC_INIT_VARS(unit);

    sal_snprintf(example_name, RHNAME_MAX_SIZE - 1, "%s_%d", sh_sand_cmd->keyword, RHLNUM(examples_list));
    /*
     * We always need to have something in a string even if it is empty, so start from allocation size 1
     */
    str_size = 1;
    /*
     * + Command
     */
    if (flags & SH_SAND_EXAMPLES_FULL)
    {
        str_size += sal_strnlen(sh_sand_cmd->cmd_only, SH_SAND_MAX_TOKEN_SIZE);
    }
    /*
     * + Space + arguments list
     */
    if (!ISEMPTY(arguments_string))
    {
        str_size += 1 + sal_strnlen(arguments_string, SH_SAND_MAX_TOKEN_SIZE);
    }

    if (utilex_rhlist_entry_add_tail(examples_list, example_name, RHID_TO_BE_GENERATED, &void_example) != _SHR_E_NONE)
    {
        SHR_CLI_EXIT(_SHR_E_INIT, "Error - failed to add example:%s to the command list:%s\n",
                     arguments_string, sh_sand_cmd->cmd_only);
    }
    example_invoke = void_example;
    /*
     * Allocate 'str_size + 1' since we shall, further on (See sh_sand_usage_verify(), towards the end),
     * add '\n'.
     */
    if ((example_invoke->params = sal_alloc(str_size + 1, "ShellInvokeParams")) == NULL)
    {
        SHR_CLI_EXIT(_SHR_E_MEMORY, "Error - failed to allocate memory for example:%s on:\"%s\"\n",
                     arguments_string, sh_sand_cmd->cmd_only);
    }

    /*
     * If FULL command requested copy first command itself, otherwise NULLify the string
     */
    if (flags & SH_SAND_EXAMPLES_FULL)
    {
        sal_strncpy(example_invoke->params, sh_sand_cmd->cmd_only, str_size - 1);
        /** Add space before arguments */
        if (!ISEMPTY(arguments_string))
        {
            sal_strncat(example_invoke->params, " ", 2);
        }
    }
    else
    {
        example_invoke->params[0] = 0;
    }

    /*
     * If there are arguments concatenate them with space in between
     */
    if (!ISEMPTY(arguments_string))
    {
        sal_snprintf(example_invoke->params + sal_strnlen(example_invoke->params, SH_SAND_MAX_TOKEN_SIZE),
                     str_size - sal_strnlen(example_invoke->params, SH_SAND_MAX_TOKEN_SIZE), "%s", arguments_string);
    }
    /*
     * Make string NULL-terminated
     */
    example_invoke->params[str_size - 1] = 0;

exit:
    SHR_FUNC_EXIT;
}

/**
 * \brief Generates examples.
 * \param [in]  unit            - unit id
 * \param [out] flags           - misc flags controlling examples list generation
 * \param [in]  sh_sand_cmd     - pointer to leaf command
 * \param [out] examples_list   - pointer to the list of examples to be generated by this routine
 * \param [in] arguments_string - Argument's string to create the examples from
 * \retval _SHR_E_NONE for success
 * \retval _SHR_E_PARAM problem with input parameters, usage should be printed by calling procedure
 * \retval other errors for other failure type
 * \remark
 *    None
 */
static shr_error_e
sh_sand_example_internal_add(
    int unit,
    int flags,
    sh_sand_cmd_t * sh_sand_cmd,
    rhlist_t * examples_list,
    char *arguments_string)
{
    int index = 0;
    uint32 place_to_change = 1;
    uint32 option_index = 0;
    uint32 example_count = 1;

    char **tokens = NULL;
    uint32 maxtokens = 100;
    uint32 option_count = 0;

    char **per_keyword_tokens = NULL;
    uint32 maxtokens_per_keyword = 2;
    uint32 tokens_per_keyword_count = 0;

    char **range_tokens = NULL;
    uint32 maxtokens_per_range = 2;
    uint32 range_count = 0;
    uint32 value = 0;
    uint32 start = 0, end = 0;

    char buf[SH_SAND_MAX_KEYWORD_SIZE];

    sh_sand_range_example_t examples_range[100];
    char **example_string = NULL;

    SHR_FUNC_INIT_VARS(unit);

    /*
     * In case there is no range option, simply add the example and exit.
     */
    if (sal_strstr(arguments_string, "..") == NULL)
    {
        SHR_CLI_EXIT_IF_ERR(sh_sand_example_add(unit, flags, sh_sand_cmd, examples_list, arguments_string), "");
        SHR_EXIT();
    }

    sal_memset(examples_range, 0, sizeof(sh_sand_range_example_t) * 100);
    /*
     * If examples string is not empty, split it into separate options strings
     */
    if ((tokens = utilex_str_split(arguments_string, " ", maxtokens, &option_count)) == NULL)
    {
        SHR_ERR_EXIT(_SHR_E_FAIL, "failed to parse example string %s\n", arguments_string);
    }

    /*
     * loop over all example's options.
     */
    for (option_index = 0; option_index < option_count; option_index++)
    {
        /*
         * In case there is boolean option add the keyword and continue.
         */
        if (!sal_strstr(tokens[option_index], "="))
        {
            sal_strncpy_s(examples_range[option_index].keyword, tokens[option_index], SH_SAND_MAX_KEYWORD_SIZE);
            continue;
        }

        /*
         * Split the example option to value and keyword.
         */
        if ((per_keyword_tokens =
             utilex_str_split(tokens[option_index], "=", maxtokens_per_keyword, &tokens_per_keyword_count)) == NULL)
        {
            SHR_ERR_EXIT(_SHR_E_FAIL, "failed to parse example string %s\n", arguments_string);
        }

        /*
         * add the keyword to the db.
         */
        sal_strncpy_s(examples_range[option_index].keyword, per_keyword_tokens[0], SH_SAND_MAX_KEYWORD_SIZE);

        if (per_keyword_tokens[1] != NULL)
        {
            /*
             * Save the value of the keyword and free the tokens.
             */
            sal_memset(buf, 0, SH_SAND_MAX_KEYWORD_SIZE);
            sal_strncpy_s(buf, per_keyword_tokens[1], SH_SAND_MAX_KEYWORD_SIZE);
            utilex_str_split_free(per_keyword_tokens, tokens_per_keyword_count);

            /*
             * If the value contains .. split it to start and end.
             * And configure the db accordingly.
             */
            if (sal_strstr(buf, ".."))
            {
                if ((range_tokens = utilex_str_split(buf, "..", maxtokens_per_range, &range_count)) == NULL)
                {
                    SHR_ERR_EXIT(_SHR_E_FAIL, "failed to parse example string %s\n", arguments_string);
                }
                sal_strncpy_s(examples_range[option_index].start, range_tokens[0], SH_SAND_MAX_KEYWORD_SIZE);
                sal_strncpy_s(examples_range[option_index].end, range_tokens[1], SH_SAND_MAX_KEYWORD_SIZE);
                examples_range[option_index].is_range_option = 1;
                utilex_str_split_free(range_tokens, range_count);

                if (!utilex_str_is_decimal(examples_range[option_index].start) ||
                    !utilex_str_is_decimal(examples_range[option_index].end))
                {
                    SHR_CLI_EXIT_IF_ERR(sh_sand_example_add(unit, flags, sh_sand_cmd, examples_list, arguments_string),
                                        "");
                    SHR_EXIT();
                }

                SHR_IF_ERR_EXIT(utilex_str_stoul(examples_range[option_index].start, &start));
                SHR_IF_ERR_EXIT(utilex_str_stoul(examples_range[option_index].end, &end));
                example_count = example_count * ((end - start) + 1);
            }
            else
            {
                sal_strncpy_s(examples_range[option_index].start, buf, SH_SAND_MAX_KEYWORD_SIZE);
                sal_strncpy_s(examples_range[option_index].end, buf, SH_SAND_MAX_KEYWORD_SIZE);
                examples_range[option_index].is_range_option = 0;
            }
            examples_range[option_index].equal = 1;
        }
        else
        {
            /*
             * In case we do not have a per_keyword_tokens second element, just free the tokens.
             */
            utilex_str_split_free(per_keyword_tokens, tokens_per_keyword_count);
        }
    }

    /*
     * Allocate list to store all examples.
     */
    example_string = sal_alloc(sizeof(char *) * example_count, "example_string array");
    for (index = 0; index < example_count; index++)
    {
        example_string[index] = sal_alloc(sal_strnlen(arguments_string, SH_SAND_MAX_TOKEN_SIZE) + 1, "token");
        sal_memset(example_string[index], 0, sal_strnlen(arguments_string, SH_SAND_MAX_TOKEN_SIZE) + 1);
    }

    /*
     * Set the example strings, option by option.
     */
    for (option_index = 0; option_index < option_count; option_index++)
    {
        if (examples_range[option_index].is_range_option == 1)
        {
            SHR_IF_ERR_EXIT(utilex_str_stoul(examples_range[option_index].start, &start));
            SHR_IF_ERR_EXIT(utilex_str_stoul(examples_range[option_index].end, &end));
            place_to_change = place_to_change * ((end - start) + 1);
            value = start;
        }

        for (index = 0; index < example_count; index++)
        {
            if (option_index != 0)
            {
                sal_strncat_s(example_string[index], " ", sal_strnlen(arguments_string, SH_SAND_MAX_TOKEN_SIZE));
            }

            sal_strncat_s(example_string[index], examples_range[option_index].keyword,
                          sal_strnlen(arguments_string, SH_SAND_MAX_TOKEN_SIZE));

            if (examples_range[option_index].equal)
            {
                sal_strncat_s(example_string[index], "=", sal_strnlen(arguments_string, SH_SAND_MAX_TOKEN_SIZE));
            }
            if (examples_range[option_index].is_range_option == 0)
            {
                sal_strncat_s(example_string[index], examples_range[option_index].start,
                              sal_strnlen(arguments_string, SH_SAND_MAX_TOKEN_SIZE));
            }
            else
            {
                if ((index % (example_count / place_to_change)) == 0 && index != 0)
                {
                    value++;
                }

                if (value > end)
                {
                    value = start;
                }

                sal_memset(buf, 0, SH_SAND_MAX_KEYWORD_SIZE);
                sal_itoa(buf, value, 10, 0, 0);
                sal_strncat_s(example_string[index], buf, sal_strnlen(arguments_string, SH_SAND_MAX_TOKEN_SIZE));
            }
        }
    }

    /*
     * Add all examples to the list.
     */
    for (index = 0; index < example_count; index++)
    {
        SHR_CLI_EXIT_IF_ERR(sh_sand_example_add(unit, flags, sh_sand_cmd, examples_list, example_string[index]), "");
    }

exit:
    utilex_str_split_free(tokens, option_count);
    if (example_string != NULL)
    {
        for (index = 0; index < example_count; index++)
        {
            SHR_FREE(example_string[index]);
        }
        SHR_FREE(example_string);
    }
    SHR_FUNC_EXIT;
}

/**
 * \brief Routine serves to generate array of examples per leaf command
 * \param [in]  unit            - unit id
 * \param [out] flags           - misc flags controlling examples list generation
 * \param [in]  sh_sand_cmd     - pointer to leaf command
 * \param [out] examples_list_p - pointer to the list of examples to be generated by this routine
 * \retval _SHR_E_NONE for success
 * \retval _SHR_E_PARAM problem with input parameters, usage should be printed by calling procedure
 * \retval other errors for other failure type
 * \remark
 *    If no examples string was provided in man structure, there will be only 1 element with option-less command
 *    Responsibility of caller to free the array using utilex_str_split_free
 */
static shr_error_e
sh_sand_examples_list_get(
    int unit,
    int flags,
    sh_sand_cmd_t * sh_sand_cmd,
    rhlist_t ** examples_list_p)
{
    int i_tok;
    char **tokens = NULL;
    uint32 maxtokens = 100;
    rhlist_t *examples_list = NULL;
    uint32 examples_num = 0;

    SHR_FUNC_INIT_VARS(unit);

    if ((sh_sand_cmd == NULL) || (sh_sand_cmd->man == NULL))
    {   /* On this stage there is no need to print message, all errors should be rectified by verify */
        SHR_EXIT();
    }

    SHR_NULL_CHECK(examples_list_p, _SHR_E_PARAM, "examples_list_p");

    if ((examples_list = utilex_rhlist_create("ShellCommandExamples", sizeof(sh_sand_test_t), 1)) == NULL)
    {
        SHR_CLI_EXIT(_SHR_E_MEMORY, "ERROR - Failed to allocate list for test invocations on:%s\n",
                     sh_sand_cmd->keyword);
    }

    if (!ISEMPTY(sh_sand_cmd->man->examples))
    {
        /*
         * If examples string is not empty, split it into separate options strings
         */
        if ((tokens = utilex_str_split(sh_sand_cmd->man->examples, "\n", maxtokens, &examples_num)) == NULL)
        {
            SHR_ERR_EXIT(_SHR_E_FAIL, "failed to parse example string %s\n", sh_sand_cmd->man->examples);
        }
        for (i_tok = 0; i_tok < examples_num; i_tok++)
        {
            SHR_CLI_EXIT_IF_ERR(sh_sand_example_internal_add(unit, flags, sh_sand_cmd, examples_list, tokens[i_tok]),
                                "");
        }
    }

    if ((flags & SH_SAND_EXAMPLES_DYNAMIC) && (sh_sand_cmd->man->example_generate_cb != NULL))
    {
        sh_sand_cmd->man->example_generate_cb(unit, flags, sh_sand_cmd, examples_list);
    }

    if (RHLNUM(examples_list) == 0)
    {
        SHR_CLI_EXIT_IF_ERR(sh_sand_example_add(unit, flags, sh_sand_cmd, examples_list, ""), "");
    }

    *examples_list_p = examples_list;

exit:
    utilex_str_split_free(tokens, examples_num);
    if (!SHR_FUNC_VAL_IS(_SHR_E_NONE))
    {
        sh_sand_examples_list_free(unit, examples_list);
    }
    SHR_FUNC_EXIT;
}

/**
 * \brief Routine serves to generate array of examples per leaf command
 * \param [in]  unit           - unit id
 * \param [in]  sh_sand_cmd    - pointer to leaf command
 * \param [out] synopsis_p     - pointer to the synopsis string array
 * \param [out] synopsis_num_p - pointer to the number of element in synopsis array
 * \retval _SHR_E_NONE for success
 * \retval _SHR_E_PARAM problem with input parameters, usage should be printed by calling procedure
 * \retval other errors for other failure type
 * \remark
 *    If no synopsis string was provided in man structure, there will be only 1 element with option-less command
 *    Responsibility of caller to free the array using utilex_str_split_free
 */
static shr_error_e
sh_sand_synopsis_get(
    int unit,
    sh_sand_cmd_t * sh_sand_cmd,
    char ***synopsis_p,
    uint32 *synopsis_num_p)
{
    int i_tok;
    char **tokens = NULL;
    uint32 maxtokens = 100;
    char **synopsis = NULL;
    uint32 synopsis_num = 0;
    int str_size;
    SHR_FUNC_INIT_VARS(unit);

    if ((sh_sand_cmd == NULL) || (sh_sand_cmd->man == NULL))
    {   /* On this stage there is no need to print message, all errors should be rectified by verify */
        SHR_EXIT();
    }

    if (!ISEMPTY(sh_sand_cmd->man->synopsis))
    {
        /*
         * If synopsis string is not empty, split it into separate options strings
         */
        if ((tokens = utilex_str_split(sh_sand_cmd->man->synopsis, "\n", maxtokens, &synopsis_num)) == NULL)
        {
            SHR_ERR_EXIT(_SHR_E_FAIL, "failed to parse synopsis string:\"%s\"\n", sh_sand_cmd->man->synopsis);
        }
        /*
         * Allocate pointer array for full commands
         */
        if ((synopsis = sal_alloc(sizeof(char *) * synopsis_num, "synopsis")) == NULL)
        {
            SHR_ERR_EXIT(_SHR_E_MEMORY, "failed to allocate memory for synopsis:\"%s\"\n", sh_sand_cmd->man->synopsis);
        }
        for (i_tok = 0; i_tok < synopsis_num; i_tok++)
        {
            synopsis[i_tok] = NULL;
        }
        for (i_tok = 0; i_tok < synopsis_num; i_tok++)
        {
            /*
             * Go through all options and create full commands
             */
            str_size =
                sal_strnlen(tokens[i_tok], SH_SAND_MAX_TOKEN_SIZE) + sal_strnlen(sh_sand_cmd->cmd_only,
                                                                                 SH_SAND_MAX_TOKEN_SIZE) + 3;
            if ((synopsis[i_tok] = sal_alloc(str_size, "synopsis_item")) == NULL)
            {
                SHR_ERR_EXIT(_SHR_E_MEMORY, "failed to allocate memory for synopsis:\"%s\"\n",
                             sh_sand_cmd->man->synopsis);
            }

            sal_snprintf(synopsis[i_tok], str_size - 1, "%s %s", sh_sand_cmd->cmd_only, tokens[i_tok]);
        }
    }
    else
    {
        sh_sand_option_t *option_p;
        char option_only[RHSTRING_MAX_SIZE];
        char *format_str;
        char *cmd_str;
        sh_sand_option_t *all_options[SH_SAND_MAX_OPTIONS];
        int options_cnt = 0;
        int ii;

        /*
         * If synopsis string is not defined, it will be auto-generated
         */
        synopsis_num = 1;
        /*
         * Allocate pointer array for full commands
         */
        if ((synopsis = sal_alloc(sizeof(char *) * synopsis_num, "synopsis")) == NULL)
        {
            SHR_ERR_EXIT(_SHR_E_MEMORY, "failed to allocate memory for synopsis:\"%s\"\n", sh_sand_cmd->man->synopsis);
        }
        if ((cmd_str = sal_alloc(SH_SAND_MAX_TOKEN_SIZE, "synopsis_item")) == NULL)
        {
            SHR_SET_CURRENT_ERR(_SHR_E_MEMORY);
            SHR_EXIT();
        }
        /*
         * Copy the command and then add options
         */
        sal_strncpy(cmd_str, sh_sand_cmd->cmd_only, SH_SAND_MAX_TOKEN_SIZE - 1);

        sh_sand_options_get_recursive(sh_sand_cmd->options, &options_cnt, all_options);

        /*
         * If synopsis was not provided auto-generate one from options
         */
        for (ii = 0, option_p = all_options[ii]; ii < options_cnt; ii++, option_p = all_options[ii])
        {
            switch (option_p->type)
            {
                case SAL_FIELD_TYPE_BOOL:
                    format_str = "[=no]";
                    break;
                default:
                    format_str = "=<...>";
                    break;
            }
            if (option_p->def == NULL)
            {   /** The one without default is must */
                sal_snprintf(option_only, RHSTRING_MAX_SIZE - 1, " %s%s", option_p->keyword, format_str);
            }
            else
            {   /** When default is present cli parameter is optional */
                sal_snprintf(option_only, RHSTRING_MAX_SIZE - 1, " [%s%s]", option_p->keyword, format_str);
            }
            sal_strncpy(cmd_str + strlen(cmd_str), " ", SH_SAND_MAX_TOKEN_SIZE - 1 - strlen(cmd_str));
            sal_strncpy(cmd_str + strlen(cmd_str), option_only, SH_SAND_MAX_TOKEN_SIZE - 1 - strlen(cmd_str));
        }

        synopsis[0] = cmd_str;
    }

    *synopsis_p = synopsis;
    *synopsis_num_p = synopsis_num;

exit:
    utilex_str_split_free(tokens, synopsis_num);
    if (!SHR_FUNC_VAL_IS(_SHR_E_NONE) && (synopsis != NULL))
    {
        utilex_str_split_free(synopsis, synopsis_num);
    }
    SHR_FUNC_EXIT;
}

static void
sh_sand_print(
    char *string,
    int left_margin,
    int right_margin,
    int term_width)
{
    int token_size;
    int str_shift, print_size;
    int str_offset = 0;
    int str_size = strlen(string);

    token_size = term_width - left_margin - right_margin;

    do
    {
        /*
         * Print left margin
         */
        diag_sand_prt_char(left_margin, ' ');
        /*
         * Get shift where last white space in the token or first new line are situated
         */
        str_shift = utilex_str_get_shift(string + str_offset, token_size);
        /*
         * Print string up to this delimiter, print only specified number of characters(str_shift) from the string
         * If the last character in string to be printed is \n - do not double it, so print 1 character less
         */
        print_size = (*(string + str_offset + str_shift - 1) == '\n') ? (str_shift - 1) : (str_shift);

        LOG_CLI((BSL_META("%.*s\n"), print_size, string + str_offset));
        /*
         * Update current string offset taking into account delimiter
         */
        str_offset += str_shift;
    }
    while (str_offset < str_size);      /* once current offset exceeds string length stop */
}

static int
sh_sand_argument_prefix_size(
    sh_sand_option_t * options)
{
    char *def_str;
    sh_sand_option_t *option;
    int lead_size = SH_SAND_ARGUMENT_PREFIX_BASE, cur_size;
    sh_sand_option_t *all_options[SH_SAND_MAX_OPTIONS];
    int options_cnt = 0;
    int ii;

    sh_sand_options_get_recursive(options, &options_cnt, all_options);
    /*
     * Calculate the longest string consisting from option name type and default
     */
    for (ii = 0, option = all_options[ii]; ii < options_cnt; ii++, option = all_options[ii])
    {
        if (option->def == NULL)
        {
            def_str = "NONE";
        }
        else if (ISEMPTY(option->def))
        {
            def_str = "EMPTY";
        }
        else
        {
            def_str = option->def;
        }

        cur_size = SH_SAND_ARGUMENT_PREFIX_BASE + sal_strnlen(option->keyword, RHNAME_MAX_SIZE) +
            sal_strnlen(sal_field_type_str(option->type), RHNAME_MAX_SIZE) + sal_strnlen(def_str, RHNAME_MAX_SIZE);

        if (option->flags & SH_SAND_ARG_FREE)
        {
            cur_size += SH_SAND_ARGUMENT_FREE_TAG_SIZE;
        }
        /*
         * Don't touch lead_size if cur_size is more than certain max, otherwise increase is up to highest but not
         * bigger than this max
         */
        lead_size = (cur_size > 48) ? lead_size : ((cur_size > lead_size) ? cur_size : lead_size);
    }
    return lead_size;
}

static void
sh_sand_print_enums_recursive(
    sh_sand_enum_t * enum_entry,
    int left_margin)
{
    for (; !ISEMPTY(enum_entry->string) || enum_entry->inherited_enum != NULL; enum_entry++)
    {
        if (enum_entry->inherited_enum != NULL)
        {
            sh_sand_print_enums_recursive(enum_entry->inherited_enum, left_margin);
        }
        if (!ISEMPTY(enum_entry->string))
        {
            diag_sand_prt_char(left_margin + 3, ' ');
            if (ISEMPTY(enum_entry->desc))
            {
                LOG_CLI((BSL_META("%-10s - %s\n"), enum_entry->string, "TBD"));
            }
            else
            {
                LOG_CLI((BSL_META("%-10s - %s\n"), enum_entry->string, enum_entry->desc));
            }
        }
    }
}

static void
sh_sand_print_options_recursive(
    int unit,
    sh_sand_option_t * options,
    int left_margin,
    int right_margin,
    int term_width,
    int lead_size,
    char *format_str)
{
    int token_size;
    int str_shift;
    int str_offset;
    int str_size;
    char *def_str, *keyword;
    char lead_str[RHSTRING_MAX_SIZE];
    sh_sand_option_t *option;
    sh_sand_enum_t *enum_entry;

    for (option = options; option->keyword != NULL || option->inherited_options != NULL; option++)
    {
        if (option->inherited_options != NULL)
        {
            sh_sand_print_options_recursive(unit, option->inherited_options, left_margin, right_margin, term_width,
                                            lead_size, format_str);
            if (ISEMPTY(option->keyword))
            {
                continue;
            }
        }

        if (option->def == NULL)
        {
            def_str = "NONE";
        }
        else if (ISEMPTY(option->def))
        {
            def_str = "EMPTY";
        }
        else
        {
            def_str = option->def;
        }

        if (option->full_key != NULL)
        {
            keyword = option->full_key;
        }
        else
        {
            keyword = option->keyword;
        }

        if (option->flags & SH_SAND_ARG_FREE)
        {
            sal_snprintf(lead_str, RHSTRING_MAX_SIZE - 1, "%s (free,%s:%s)", keyword, sal_field_type_str(option->type),
                         def_str);
        }
        else
        {
            sal_snprintf(lead_str, RHSTRING_MAX_SIZE - 1, "%s (%s:%s)", keyword, sal_field_type_str(option->type),
                         def_str);
        }

        diag_sand_prt_char(left_margin, ' ');
        cli_out(format_str, lead_str);

        token_size = term_width - (left_margin + 3 + lead_size) - right_margin;
        str_size = strlen(option->desc);
        str_offset = 0;
        /*
         * If lead size if too long - move to the next line and take shift
         */
        if (sal_strnlen(lead_str, RHNAME_MAX_SIZE) > lead_size)
        {
            cli_out("\n");
            diag_sand_prt_char(left_margin + lead_size, ' ');
        }
        cli_out(" - ");
        do
        {
            if (str_offset != 0)
            {
                /*
                 * Print left margin
                 */
                diag_sand_prt_char(left_margin + 3 + lead_size, ' ');
            }
            /*
             * Get shift where last white space in the token or first new line are situated
             */
            str_shift = utilex_str_get_shift(option->desc + str_offset, token_size);
            /*
             * Print string up to this delimiter, print only specified number of characters(str_shift) from the string
             */
            LOG_CLI((BSL_META("%.*s\n"), str_shift, option->desc + str_offset));
            /*
             * Update current string offset taking into account delimiter
             */
            str_offset += str_shift;
        }
        while (str_offset < str_size);  /* once current offset exceeds string length stop */

        enum_entry = (sh_sand_enum_t *) (option->ext_ptr);
        if (!ISEMPTY(option->valid_range))
        {
            char start_str[RHNAME_MAX_SIZE], end_str[RHNAME_MAX_SIZE];
            if (sh_sand_option_valid_range_get(unit, option, start_str, end_str) == _SHR_E_NONE)
            {
                diag_sand_prt_char(left_margin + 3, ' ');
                LOG_CLI((BSL_META("\033[1m%s\033[0m\n"), "Valid Range"));

                diag_sand_prt_char(left_margin + 3, ' ');
                LOG_CLI((BSL_META("%-10s - from:%s to:%s\n"), "", start_str, end_str));
            }
        }
        if (enum_entry != NULL)
        {
            diag_sand_prt_char(left_margin + 3, ' ');
            if (option->type == SAL_FIELD_TYPE_ENUM)
            {
                LOG_CLI((BSL_META("\033[1m%s\033[0m\n"), "Available Values"));
            }
            else
            {
                LOG_CLI((BSL_META("\033[1m%s\033[0m\n"), "Predefined Values"));
            }

            sh_sand_print_enums_recursive(enum_entry, left_margin);
        }
    }
}

static void
sh_sand_print_arguments(
    int unit,
    sh_sand_option_t * options,
    int left_margin,
    int right_margin,
    int term_width)
{
    char format_str[RHKEYWORD_MAX_SIZE];
    int lead_size;

    diag_sand_prt_char(left_margin, ' ');
    LOG_CLI((BSL_META("\033[1m%s\033[0m\n\n"), "Argument (type:default) - description"));

    lead_size = sh_sand_argument_prefix_size(options);

    sal_snprintf(format_str, RHKEYWORD_MAX_SIZE, "%s-%ds", "%", lead_size);

    sh_sand_print_options_recursive(unit, options, left_margin, right_margin, term_width, lead_size, format_str);
}

static shr_error_e
sh_sand_usage_leaf_tabular(
    int unit,
    sh_sand_cmd_t * sh_sand_cmd,
    sh_sand_control_t * sand_control)
{
    sh_sand_option_t *option;
    int flag;
    char **tokens = NULL;
    uint32 realtokens = 0;
    rhlist_t *examples_list = NULL;
    sh_sand_test_t *example;
    int first_example = TRUE;

    PRT_INIT_VARS;
    SHR_FUNC_INIT_VARS(unit);

    if ((sh_sand_cmd == NULL) || (sh_sand_cmd->man == NULL))
    {   /* On this stage there is no need to print message, all errors should be rectified by verify */
        SHR_EXIT();
    }

    PRT_TITLE_SET("%s", "Usage");

    PRT_COLUMN_ADD("Item");
    PRT_COLUMN_ADD("Argument");
    PRT_COLUMN_ADD_FLEX(PRT_FLEX_ASCII, "Description");
    PRT_COLUMN_ADD("Type");
    PRT_COLUMN_ADD("Default");

    PRT_ROW_ADD(PRT_ROW_SEP_UNDERSCORE);
    PRT_CELL_SET("SYNOPSIS");
    PRT_CELL_SKIP(1);
    SHR_CLI_EXIT_IF_ERR(sh_sand_synopsis_get(unit, sh_sand_cmd, &tokens, &realtokens), "");
    {
        int i_tok;
        for (i_tok = 0; i_tok < realtokens; i_tok++)
        {
            if (i_tok != 0)
            {
                PRT_ROW_ADD(PRT_ROW_SEP_NONE);
                PRT_CELL_SKIP(1);
            }
            PRT_CELL_SET("%s", tokens[i_tok]);
        }
    }

    PRT_ROW_ADD(PRT_ROW_SEP_UNDERSCORE);
    PRT_CELL_SET("DESCRIPTION");
    PRT_CELL_SKIP(1);
    if (!ISEMPTY(sh_sand_cmd->man->full))
    {
        PRT_CELL_SET("%s", sh_sand_cmd->man->full);
    }
    else
    {
        PRT_CELL_SET("%s", sh_sand_cmd->man->brief);
    }

    if ((sh_sand_cmd->options != NULL)
        && (sh_sand_cmd->options->keyword != NULL || sh_sand_cmd->options->inherited_options != NULL))
    {
        sh_sand_option_t *all_options[SH_SAND_MAX_OPTIONS];
        int options_cnt = 0;
        int enum_entries_cnt = 0;
        sh_sand_enum_t *enum_entry;
        sh_sand_enum_t *all_enum_entries[SH_SAND_MAX_ENUM_ENTRIES];
        int ii, jj;

        PRT_ROW_ADD(PRT_ROW_SEP_NONE);
        PRT_CELL_SET("OPTIONS");

        sh_sand_options_get_recursive(sh_sand_cmd->options, &options_cnt, all_options);
        for (ii = 0, option = all_options[ii]; ii < options_cnt; ii++, option = all_options[ii])
        {
            char *def_str;
            if (option->def == NULL)
            {
                def_str = "NONE";
            }
            else if (ISEMPTY(option->def))
            {
                def_str = "EMPTY";
            }
            else
            {
                def_str = option->def;
            }
            /*
             * For the first option skip 1 cell, for all others allocate new row
             */
            if (option != sh_sand_cmd->options)
            {
                PRT_ROW_ADD(PRT_ROW_SEP_NONE);
                PRT_CELL_SKIP(1);
            }
            if (option->full_key != NULL)
            {
                PRT_CELL_SET("%s", option->full_key);
            }
            else
            {
                PRT_CELL_SET("%s", option->keyword);
            }
            PRT_CELL_SET("%s", option->desc);
            PRT_CELL_SET("%s", sal_field_type_str(option->type));
            PRT_CELL_SET("%s", def_str);

            /*
             * Reset enum entries counter to 0.
             */
            enum_entries_cnt = 0;
            sh_sand_enum_entries_get_recursive((sh_sand_enum_t *) (option->ext_ptr), &enum_entries_cnt,
                                               all_enum_entries);
            for (jj = 0, enum_entry = all_enum_entries[jj]; jj < enum_entries_cnt;
                 jj++, enum_entry = all_enum_entries[jj])
            {
                PRT_ROW_ADD(PRT_ROW_SEP_NONE);
                PRT_CELL_SKIP(1);
                PRT_CELL_SET_SHIFT(1, "%s", enum_entry->string);
                if (!ISEMPTY(enum_entry->desc))
                {
                    PRT_CELL_SET_SHIFT(1, "%s", enum_entry->desc);
                }
                else
                {
                    PRT_CELL_SET_SHIFT(1, "%s", "TBD");
                }
            }
        }
        PRT_ROW_SET_MODE(PRT_ROW_SEP_UNDERSCORE);
    }

    /*
     * Show system options only when all option used
     */
    SH_SAND_GET_BOOL("all", flag);
    if (flag == TRUE)
    {
        sh_sand_option_t *all_options[SH_SAND_MAX_OPTIONS];
        int options_cnt = 0;
        int enum_entries_cnt = 0;
        sh_sand_enum_t *enum_entry;
        sh_sand_enum_t *all_enum_entries[SH_SAND_MAX_ENUM_ENTRIES];
        int ii, jj;

        PRT_ROW_ADD(PRT_ROW_SEP_NONE);
        PRT_CELL_SET("SYSTEM OPTIONS");

        sh_sand_options_get_recursive(sh_sand_sys_arguments, &options_cnt, all_options);
        for (ii = 0, option = all_options[ii]; ii < options_cnt; ii++, option = all_options[ii])
        {
            char *def_str;
            if (option->def == NULL)
            {
                def_str = "NONE";
            }
            else if (ISEMPTY(option->def))
            {
                def_str = "EMPTY";
            }
            else
            {
                def_str = option->def;
            }

            /*
             * For the first option skip 1 cell, for all others allocate new row
             */
            if (option != *all_options)
            {
                PRT_ROW_ADD(PRT_ROW_SEP_NONE);
            }
            PRT_CELL_SET("%s", option->keyword);
            PRT_CELL_SET("%s", option->desc);
            PRT_CELL_SET("%s", sal_field_type_str(option->type));
            PRT_CELL_SET("%s", def_str);

            /*
             * Reset enum entries counter to 0.
             */
            enum_entries_cnt = 0;
            sh_sand_enum_entries_get_recursive((sh_sand_enum_t *) (option->ext_ptr), &enum_entries_cnt,
                                               all_enum_entries);
            for (jj = 0, enum_entry = all_enum_entries[jj]; jj < enum_entries_cnt;
                 jj++, enum_entry = all_enum_entries[jj])
            {
                PRT_ROW_ADD(PRT_ROW_SEP_NONE);
                PRT_CELL_SKIP(1);
                PRT_CELL_SET_SHIFT(1, "%s", enum_entry->string);
                if (!ISEMPTY(enum_entry->desc))
                {
                    PRT_CELL_SET_SHIFT(1, "%s", enum_entry->desc);
                }
                else
                {
                    PRT_CELL_SET_SHIFT(1, "%s", "TBD");
                }
            }
        }
        PRT_ROW_SET_MODE(PRT_ROW_SEP_UNDERSCORE);
    }
    /*
     * Now print examples
     */
    SHR_CLI_EXIT_IF_ERR(sh_sand_examples_list_get(unit, SH_SAND_EXAMPLES_FULL, sh_sand_cmd, &examples_list), "");
    RHITERATOR(example, examples_list)
    {
        PRT_ROW_ADD(PRT_ROW_SEP_NONE);
        if (first_example == TRUE)
        {
            first_example = FALSE;
            PRT_CELL_SET("EXAMPLES");
        }
        else
        {
            PRT_CELL_SKIP(1);
        }
        PRT_CELL_SKIP(1);
        PRT_CELL_SET("%s", example->params);
    }

    PRT_COMMITX;
exit:
    sh_sand_examples_list_free(unit, examples_list);
    utilex_str_split_free(tokens, realtokens);
    PRT_FREE;
    SHR_FUNC_EXIT;
}

static shr_error_e
sh_sand_usage_leaf(
    int unit,
    sh_sand_cmd_t * sh_sand_cmd,
    sh_sand_control_t * sand_control)
{
    int columns, margin;
    int flag;
    rhlist_t *examples_list = NULL;
    sh_sand_test_t *example;
    char **tokens = NULL;
    uint32 realtokens = 0;

    SHR_FUNC_INIT_VARS(unit);

    if ((sh_sand_cmd == NULL) || (sh_sand_cmd->man == NULL))
    {   /* On this stage there is no need to print message, all errors should be rectified by verify */
        SHR_EXIT();
    }

    SH_SAND_GET_BOOL("tabular", flag);
    if (flag == TRUE)
    {
        sh_sand_usage_leaf_tabular(unit, sh_sand_cmd, sand_control);
        goto exit;
    }

    SH_SAND_GET_INT32("column", columns);
    SH_SAND_GET_INT32("margin", margin);

    LOG_CLI((BSL_META("\n\033[1m%s\033[0m\n"), "SYNOPSIS"));
    SHR_CLI_EXIT_IF_ERR(sh_sand_synopsis_get(unit, sh_sand_cmd, &tokens, &realtokens), "");
    {
        int i_tok;
        for (i_tok = 0; i_tok < realtokens; i_tok++)
        {
            sh_sand_print(tokens[i_tok], margin, margin, columns);
        }
    }
    utilex_str_split_free(tokens, realtokens);
    tokens = NULL;

    LOG_CLI((BSL_META("\n\033[1m%s\033[0m\n"), "DESCRIPTION"));
    if (!ISEMPTY(sh_sand_cmd->man->full))
    {
        sh_sand_print((char *) sh_sand_cmd->man->full, margin, margin, columns);
    }
    else
    {
        sh_sand_print((char *) sh_sand_cmd->man->brief, margin, margin, columns);
    }

    if ((sh_sand_cmd->options != NULL) && (sh_sand_cmd->options->keyword != NULL))
    {
        LOG_CLI((BSL_META("\n\033[1m%s\033[0m\n"), "ARGUMENTS"));
        sh_sand_print_arguments(unit, sh_sand_cmd->options, margin, margin, columns);
    }

    SH_SAND_GET_BOOL("all", flag);
    if (flag == TRUE)
    {
        LOG_CLI((BSL_META("\n\033[1m%s\033[0m\n"), "SYSTEM ARGUMENTS"));
        sh_sand_print_arguments(unit, sh_sand_sys_arguments, margin, margin, columns);
    }
    else
    {
        LOG_CLI((BSL_META("\n\033[1m%s\033[0m\n"), "NOTE: to show SYSTEM ARGUMENTS add 'all' to usage command"));
    }

    LOG_CLI((BSL_META("\n\033[1m%s\033[0m\n"), "EXAMPLES"));
    SHR_CLI_EXIT_IF_ERR(sh_sand_examples_list_get
                        (unit, SH_SAND_EXAMPLES_FULL | SH_SAND_EXAMPLES_DYNAMIC, sh_sand_cmd, &examples_list), "");
    RHITERATOR(example, examples_list)
    {
        sh_sand_print(example->params, margin, margin, columns);
    }

    LOG_CLI((BSL_META("\n")));

exit:
    sh_sand_examples_list_free(unit, examples_list);
    utilex_str_split_free(tokens, realtokens);
    SHR_FUNC_EXIT;
}

static shr_error_e
cmd_usage_exec(
    int unit,
    args_t * args,
    sh_sand_cmd_t * sh_sand_cmd,
    void *flex_ptr,
    int flags)
{
    int columns;
    sh_sand_control_t *sand_control;
    SHR_FUNC_INIT_VARS(unit);

    sand_control = (sh_sand_control_t *) flex_ptr;
    SH_SAND_GET_INT32("column", columns);

    diag_sand_prt_char(columns, '*');
    cli_out("\n* %s\n", sh_sand_cmd->cmd_only);
    diag_sand_prt_char(columns, '*');
    cli_out("\n\n");

    SHR_CLI_EXIT_IF_ERR(sh_sand_usage_leaf(unit, sh_sand_cmd, sand_control),
                        "Error on usage for:%s", sh_sand_cmd->cmd_only);

exit:
    SHR_FUNC_EXIT;
}

static shr_error_e
sh_sand_usage_branch(
    int unit,
    sh_sand_cmd_t * sh_sand_cmd_a,
    sh_sand_control_t * sand_control)
{
    sh_sand_cmd_t *sh_sand_cmd;
    sh_sand_cmd_t *sh_sys_cmds_a = sand_control->sh_sys_cmd_a;
    int flag;
    int flags = 0;
    PRT_INIT_VARS;
    SHR_FUNC_INIT_VARS(unit);

    SH_SAND_GET_BOOL("list", flag);
    if (flag == TRUE)
    {
        SHR_SET_CURRENT_ERR(sh_sand_cmd_traverse(unit, NULL, sand_control->sh_sand_cmd_a, cmd_usage_exec, (void *) sand_control, 0, NULL        /* label 
                                                                                                                                                 */ ));
        SHR_EXIT();
    }
    PRT_TITLE_SET("%s", "Supported commands");

    PRT_COLUMN_ADD("Command");
    PRT_COLUMN_ADD_FLEX(PRT_FLEX_ASCII, "Description");
    SH_SAND_CMD_ITERATOR(sh_sand_cmd, sh_sand_cmd_a, flags)
    {
        PRT_ROW_ADD(PRT_ROW_SEP_NONE);
        if (!ISEMPTY(sh_sand_cmd->full_key))
        {
            PRT_CELL_SET("%s", sh_sand_cmd->full_key);
        }
        else
        {
            PRT_CELL_SET("%s", sh_sand_cmd->keyword);
        }
        if (sh_sand_cmd->man && !ISEMPTY(sh_sand_cmd->man->brief))
        {
            PRT_CELL_SET("%s", sh_sand_cmd->man->brief);
        }
    }
    PRT_ROW_SET_MODE(PRT_ROW_SEP_UNDERSCORE);
    PRT_ROW_ADD(PRT_ROW_SEP_UNDERSCORE);
    PRT_CELL_SET("%s", "System Commands");
    SH_SAND_GET_BOOL("all", flag);
    if ((flag == TRUE) && (sh_sys_cmds_a != NULL))
    {
        SH_SAND_CMD_ITERATOR(sh_sand_cmd, sh_sys_cmds_a, flags)
        {
            PRT_ROW_ADD(PRT_ROW_SEP_NONE);
            if (!ISEMPTY(sh_sand_cmd->full_key))
            {
                PRT_CELL_SET("%s", sh_sand_cmd->full_key);
            }
            else
            {
                PRT_CELL_SET("%s", sh_sand_cmd->keyword);
            }
            if (sh_sand_cmd->man && !ISEMPTY(sh_sand_cmd->man->brief))
            {
                PRT_CELL_SET("%s", sh_sand_cmd->man->brief);
            }
        }
    }
    else
    {
        PRT_CELL_SET("%s", "To show System Commands add 'all' to usage command");
    }
    PRT_COMMITX;
exit:
    PRT_FREE;
    SHR_FUNC_EXIT;
}

sh_sand_man_t sys_usage_man = {
    .brief = "Print list of commands available",
    .full = "Print list of commands available for the command"
};

/* *INDENT-OFF* */
sh_sand_option_t sys_usage_arguments[] = {
    {"column",  SAL_FIELD_TYPE_INT32, "Maximum columns number for output",          "120"},
    {"margin",  SAL_FIELD_TYPE_INT32, "Left&Right margin of defined display width", "6"},
    {"tabular", SAL_FIELD_TYPE_BOOL,  "Print usage in tabular view",                "No"},
    {"all",     SAL_FIELD_TYPE_BOOL,  "Show all including system ones",             "No"},
    {"list",    SAL_FIELD_TYPE_BOOL,  "Show usage of all leafs inside the branch",  "No"},
    {NULL}
};
/* *INDENT-ON* */

shr_error_e
sys_usage_cmd(
    int unit,
    args_t * args,
    sh_sand_control_t * sand_control)
{
    SHR_FUNC_INIT_VARS(unit);

    if (sand_control->sh_sand_cmd_a)
    {
        sh_sand_usage_branch(unit, sand_control->sh_sand_cmd_a, sand_control);
    }
    else if (sand_control->sh_sand_cmd)
    {
        sh_sand_usage_leaf(unit, sand_control->sh_sand_cmd, sand_control);
    }

    SHR_FUNC_EXIT;
}

shr_error_e
sys_manual_label_match(
    int unit,
    char *label,
    char **label_tokens,
    uint32 tokens_count,
    uint8 *match)
{
    int token_index = 0;
    void *match_h = NULL;
    char regex[SH_SAND_MAX_TOKEN_SIZE];

    SHR_FUNC_INIT_VARS(NO_UNIT);

    *match = FALSE;

    if (tokens_count == 0 || label_tokens == NULL)
    {
        *match = TRUE;
        SHR_EXIT();
    }

    sal_memset(regex, 0, SH_SAND_MAX_TOKEN_SIZE);

    for (token_index = 0; token_index < tokens_count; token_index++)
    {
        sal_memset(regex, 0, SH_SAND_MAX_TOKEN_SIZE);

        SH_SAND_LABEL_REGEX(regex, label_tokens[token_index]);

        SHR_IF_ERR_EXIT(diag_sand_compare_init(regex, &match_h));

        *match = diag_sand_compare(match_h, label);

        if (*match == TRUE)
        {
            SHR_EXIT();
        }
    }

exit:
    diag_sand_compare_close(match_h);
    SHR_FUNC_EXIT;
}

#ifdef INCLUDE_CTEST
/*
 * Below commands are relevant only if CTEST included
 * {
 */
static sh_sand_man_t sys_verify_man = {
    .brief = "Verifies command definition",
    .full = "Verifies brief and full description, arguments, enum values for arguments ans so on."
        "Prints report on all errors found",
};

/* *INDENT-OFF* */
static sh_sand_option_t sys_verify_arguments[] = {
    {"all",     SAL_FIELD_TYPE_BOOL,  "Performs additional checks on usage",             "No"},
    {NULL}
};

static shr_error_e
sh_sand_usage_error(
    int unit,
    shell_flex_t * shell_flex_p,
    char *command_n,
    char *option_n,
    char *error_str,
    int *first)
{
    prt_control_t *prt_ctr = NULL;
    SHR_FUNC_INIT_VARS(unit);

    if (shell_flex_p != NULL)
    {
        shell_flex_p->failed++;
        prt_ctr = shell_flex_p->prt_ctr;
    }

    if (prt_ctr != NULL)
    {
        PRT_ROW_ADD(PRT_ROW_SEP_NONE);
        if ((*first) == 0)
        {
            PRT_CELL_SKIP(1);
        }
        else
        {
            *first = 0;
            PRT_CELL_SET("%s", command_n);
        }
        PRT_CELL_SET("%s", option_n);
        PRT_CELL_SET("%s", error_str);
    }
    else
    {
        LOG_CLI((BSL_META("cmd:'%s' argument:'%s' - '%s'"), command_n, option_n, error_str));
    }
exit:
    SHR_FUNC_EXIT;
}

/*
* The function checks of if an argument is present either in full or short form and is not
* occasional part of other word of an example / string of examples.
*/

static uint8
sh_sand_example_verify(
    char *examples,
    sh_sand_option_t *option)
{
    char *option_ptr;

    if (((sal_strcasestr(examples, option->keyword) == NULL) &&
        ((ISEMPTY(option->short_key)) ||
        ((option_ptr = sal_strcasestr(examples, option->short_key)) == NULL) ||
        ((option_ptr[sal_strnlen(option->short_key, RHNAME_MAX_SIZE)] != '=') &&
        (option_ptr[sal_strnlen(option->short_key, RHNAME_MAX_SIZE)] != ' ')  &&
        (option_ptr[sal_strnlen(option->short_key, RHNAME_MAX_SIZE)] != '\n') &&
        (option_ptr[sal_strnlen(option->short_key, RHNAME_MAX_SIZE)] != '"')))))
        {
            return 0;
        }
    return 1;
}

static shr_error_e
sh_sand_usage_verify(
    int unit,
    args_t * args,
    sh_sand_cmd_t * sh_sand_cmd,
    void *flex_ptr,
    int flags)
{
    sh_sand_man_t *man;
    sh_sand_option_t *option;
    sh_sand_enum_t *enum_entry;
    shell_flex_t *shell_flex_p = (shell_flex_t *) flex_ptr;
    int first = 1;
    char error_str[RHSTRING_MAX_SIZE];
    rhlist_t *examples_list = NULL;
    sh_sand_test_t *example;
    uint8 dynamic_example_found = FALSE;
    char examples_list_string[SH_SAND_MAX_TOKEN_SIZE];
    

    SHR_FUNC_INIT_VARS(unit);

    if ((man = sh_sand_cmd->man) == NULL)
    {
        sh_sand_usage_error(unit, shell_flex_p, sh_sand_cmd->cmd_only, "", "No manual", &first);
        SHR_EXIT();
    }
    else
    {
        int length;
        if (ISEMPTY(man->brief))
        {
            sh_sand_usage_error(unit, shell_flex_p, sh_sand_cmd->cmd_only, "", "Empty Brief Description", &first);
        }
        else if (utilex_is_prime_flag_set(flags, SH_CMD_ALL))
        {
            if ((length = sal_strnlen(man->brief, SH_SAND_MAX_TOKEN_SIZE)) >= RHSTRING_MAX_SIZE)
            {
                sal_snprintf(error_str, RHSTRING_MAX_SIZE - 1,
                             "Brief size:%d is longer than:%d", length, RHSTRING_MAX_SIZE);
                sh_sand_usage_error(unit, shell_flex_p, sh_sand_cmd->cmd_only, "", error_str, &first);
            }
            else if (length < RHKEYWORD_MAX_SIZE)
            {
                sal_snprintf(error_str, RHSTRING_MAX_SIZE - 1,
                             "Brief size:%d is less than:%d", length, RHKEYWORD_MAX_SIZE);
                sh_sand_usage_error(unit, shell_flex_p, sh_sand_cmd->cmd_only, "", error_str, &first);
            }
            /** Do not check full description for branches */
            if ((sh_sand_cmd->child_cmd_a != NULL) && ISEMPTY(man->full))
            {
                sh_sand_usage_error(unit, shell_flex_p, sh_sand_cmd->cmd_only, "", "No full description", &first);
            }
        }
    }

    if ((option = sh_sand_cmd->options) != NULL)
    {
        sh_sand_option_t *all_options[SH_SAND_MAX_OPTIONS];
        int options_cnt = 0;
        int enum_entries_cnt = 0;
        sh_sand_enum_t *all_enum_entries[SH_SAND_MAX_ENUM_ENTRIES];
        int ii, jj;

        sh_sand_options_get_recursive(sh_sand_cmd->options, &options_cnt, all_options);
        for (ii = 0, option = all_options[ii]; ii < options_cnt; ii++, option = all_options[ii])
        {
            /*
             * Verify description of command, option and enum
             */
            if (ISEMPTY(option->desc))
            {
                sh_sand_usage_error(unit, shell_flex_p, sh_sand_cmd->cmd_only, option->keyword, "No description",
                                    &first);
            }

            /*
             * Reset enum entries counter to 0.
             */
            enum_entries_cnt = 0;
            sh_sand_enum_entries_get_recursive((sh_sand_enum_t *) (option->ext_ptr), &enum_entries_cnt, all_enum_entries);
            for (jj = 0, enum_entry = all_enum_entries[jj]; jj < enum_entries_cnt; jj++, enum_entry = all_enum_entries[jj])
            {
                if (ISEMPTY(enum_entry->desc))
                {
                    sal_snprintf(error_str, RHSTRING_MAX_SIZE - 1, "No description for enum:%s", enum_entry->string);
                    sh_sand_usage_error(unit, shell_flex_p, sh_sand_cmd->cmd_only, option->keyword, error_str, &first);
                }
            }
            /*
             * Do not check presence for free variables or
             * the ones that were specifically marked as not participating in examples for any reason
             */
            if (option->flags & (SH_SAND_ARG_FREE | SH_SAND_ARG_QUIET))
                continue;
            /*
             * Check whether arguments exist in statics examples
             * if not found, will check in dynamics examples: generates a list of examples and then
             * each example, if argument found - will stop check and continue for the next function
             */

            if (ISEMPTY(man->examples) || !sh_sand_example_verify(man->examples, option))
            {
                if (man->example_generate_cb != NULL)
                {
                    examples_list = utilex_rhlist_create("ShellCommandDynamicExamples", sizeof(sh_sand_test_t), 1);
                    man->example_generate_cb(unit, 0, sh_sand_cmd, examples_list);
                    RHITERATOR(example, examples_list)
                    {
                        if ( !dynamic_example_found && sh_sand_example_verify(example->params, option))
                        {
                            dynamic_example_found = TRUE;
                        }
                        if (sal_strstr(example->params, "file=") != NULL)
                        {
                            sh_sand_usage_error(unit, shell_flex_p, sh_sand_cmd->cmd_only, option->keyword,
                                                "you are not allowed to save the examples to external file", &first);
                        }
                    }
                }
                if (!dynamic_example_found)
                {
                    char *tmp_str;
                    if (option->def == NULL)
                    {
                        tmp_str = "Argument with no default must be used in examples";
                    }
                    else
                    {
                        tmp_str = "Not used in examples";
                    }
                    sh_sand_usage_error(unit, shell_flex_p, sh_sand_cmd->cmd_only, option->keyword, tmp_str, &first);
                }

            }
            else
            {
                if (sal_strstr(man->examples, "file=") != NULL)
                {
                    sh_sand_usage_error(unit, shell_flex_p, sh_sand_cmd->cmd_only, option->keyword,
                                        "you are not allowed to save the examples to external file", &first);
                }
            }
        }

        /*
         * Verify that example is not shown twice for same command list
         */
        SHR_CLI_EXIT_IF_ERR(sh_sand_examples_list_get(unit, SH_SAND_EXAMPLES_FULL | SH_SAND_EXAMPLES_DYNAMIC, sh_sand_cmd, &examples_list), "");
        sal_memset(examples_list_string, 0, SH_SAND_MAX_TOKEN_SIZE);

        RHITERATOR(example, examples_list)
        {
            sal_strncat(example->params, "\n", 2);
            if(sal_strstr(examples_list_string, example->params) != NULL)
            {
                example->params[sal_strnlen(example->params, SH_SAND_MAX_TOKEN_SIZE)-2] = 0;
                sh_sand_usage_error(unit, shell_flex_p, sh_sand_cmd->cmd_only, example->params,
                                   ("you are not allowed to add same example twice"), &first);
            }
            else {
                /*
                 * To prevent buffer overflow, set max_concat_len to be len of max_len minus cur_len of examples_list_string
                 * (minus 1 since sal_strncat adds at most size+1 chars)
                 */
                size_t max_concat_len = SH_SAND_MAX_TOKEN_SIZE - sal_strnlen(examples_list_string, SH_SAND_MAX_TOKEN_SIZE) - 1;
                sal_strncat(examples_list_string, example->params, sal_strnlen(example->params, max_concat_len));
            }
        }
    }

exit:
    SHR_FUNC_EXIT;
}


shr_error_e
static sys_verify_cmd(
    int unit,
    args_t * args,
    sh_sand_control_t * sand_control)
{
    shell_flex_t shell_flex;
    int all_flag, flags = 0;
    char *test_command;

    PRT_INIT_VARS;
    SHR_FUNC_INIT_VARS(unit);

    if(sand_control->sh_sand_cmd_a == NULL)
    {
        test_command = sand_control->sh_sand_cmd->cmd_only;
    }
    else if(sand_control->sh_sand_cmd_a->parent_cmd)
    {
        test_command = sand_control->sh_sand_cmd_a->parent_cmd->cmd_only;
    }
    else
    {
        test_command = "Root Level";
    }
    PRT_TITLE_SET("UsageTEST results for:%s", test_command);

    SH_SAND_GET_BOOL("all", all_flag);
    if (all_flag == TRUE)
        utilex_prime_flag_set(&flags, SH_CMD_ALL);

    PRT_COLUMN_ADD("Command");
    PRT_COLUMN_ADD("Argument");
    PRT_COLUMN_ADD_FLEX(PRT_FLEX_ASCII, "Error");
    shell_flex.failed = 0;
    shell_flex.succeeded = 0;
    shell_flex.skipped = 0;
    shell_flex.prt_ctr = prt_ctr;

    if (sand_control->sh_sand_cmd_a)
    {
        /** Invoke callback for branches as well as for leafs */
        utilex_prime_flag_set(&flags, SH_CMD_TRAVERSE_ALL);
        SHR_SET_CURRENT_ERR(sh_sand_cmd_traverse
                         (unit, NULL, sand_control->sh_sand_cmd_a, sh_sand_usage_verify, (void *) &shell_flex, flags, NULL /*label*/));
    }
    else if (sand_control->sh_sand_cmd)
    {
        sh_sand_usage_verify(unit, NULL, sand_control->sh_sand_cmd, (void *) &shell_flex, flags);
    }

    if(shell_flex.failed != 0)
    {
        SHR_SET_CURRENT_ERR(_SHR_E_INTERNAL);
        PRT_ROW_ADD(PRT_ROW_SEP_UNDERSCORE_BEFORE);
        PRT_CELL_SET("Failures:");
        PRT_CELL_SET("%d", shell_flex.failed);
    }
    else
    {
        PRT_INFO_ADD("No Failures");
        PRT_INFO_SET_MODE(PRT_ROW_SEP_UNDERSCORE_BEFORE)
    }
    PRT_COMMITX;
exit:
    PRT_FREE;
    SHR_FUNC_EXIT;
}

/* *INDENT-OFF* */
static sh_sand_man_t sys_exec_man = {
    .brief = "Perform all commands under the node",
    .full = "Perform all commands under the node, excluding the ones that have arguments without defaults",
    .synopsis = "[dnx] command [command stack] exec [all] [lg] [fail] [force]",
};

static sh_sand_option_t sys_exec_arguments[] = {
    {"all", SAL_FIELD_TYPE_BOOL, "Execute all shell commands ignoring errors", "No"},
    {"logger", SAL_FIELD_TYPE_BOOL, "Log all commands execution as it happens", "No"},
    {"failed", SAL_FIELD_TYPE_BOOL, "Results table will show only failed tests", "No"},
    {"force", SAL_FIELD_TYPE_BOOL, "Execute all shell commands ignoring SKIP flag", "No"},
    {"quiet", SAL_FIELD_TYPE_BOOL, "DO not print regular command log - only the resulting table", "No"},
    {"write", SAL_FIELD_TYPE_BOOL, "Save command output to XML file under the name of the command", "No"},
    {"memory", SAL_FIELD_TYPE_BOOL, "Verify the example frees all allocated memory", "No"},
    {"verify", SAL_FIELD_TYPE_BOOL, "Verify the XML result VS gold one", "No"},
    {"show", SAL_FIELD_TYPE_BOOL, "Only Show examples, do not execute", "No"},
    {"list", SAL_FIELD_TYPE_STR, "Filter list name from XML file", "simple"},
    {NULL}
};
/* *INDENT-ON* */
/**
 * \brief
 *      Looks for specified argument and excludes it from the example
 * \param [in] unit - unit id
 * \param [in] arguments_str - string of single example
 * \param [in] argument      - argument to be excluded from example
 * \param [in] value_substring - exclude only if argument value has this string
 *
 * \retval
 *     _SHR_E_EXISTS - if argument exists but does not contain value substring
 *     _SHR_E_NONE in any other case
 */
static shr_error_e
sh_sand_exclude_argument(
    int unit,
    char *arguments_str,
    char *argument,
    char *value_substring)
{
    int k_cur, arg_offset;
    char *arg_ptr, *space_ptr;
    char *value_substring_found;

    SHR_FUNC_INIT_VARS(unit);
    /*
     * Find if there is an argument in the string
     */
    if ((arg_ptr = sal_strcasestr(arguments_str, argument)) == NULL)
    {
        SHR_EXIT();
    }
    /*
     * Offset of the place where argument starts
     */
    arg_offset = arg_ptr - arguments_str;
    /*
     * Verify that argument is either at the beginning of the line or there is ' ' before it
     * If not - there was other name with this argument name being part of it
     */
    if ((arg_offset != 0) && (arguments_str[arg_offset - 1] != ' '))
    {
        SHR_EXIT();
    }

    /*
     * Found the space after the argument
     */
    space_ptr = sal_strcasestr(arg_ptr, " ");
    /*
     * We found the argument according to the name
     * If the argument value substring is provided, check that it is contained in value
     * If the value_substring is not found - leave, argument was used with something else
     */
    if ((value_substring != NULL) && (value_substring_found = sal_strcasestr(arg_ptr, value_substring)) == NULL)
    {
        /*
         * If there no space or space_ptr is less than found value_ptr - we can leave
         */
        if ((space_ptr == NULL) || (value_substring_found < space_ptr))
        {
            SHR_SET_CURRENT_ERR(_SHR_E_EXISTS);
            SHR_EXIT();
        }
    }

    if (space_ptr != NULL)
    {
        /*
         * Copy all after ' ' to the place of file and NULL terminate it
         */
        for (k_cur = 0; space_ptr[1 + k_cur] != 0; k_cur++)
        {
            arg_ptr[k_cur] = space_ptr[1 + k_cur];
        }
        arg_ptr[k_cur] = 0;
    }
    else if (arg_offset == 0)
    {
        /*
         * No space after the argument - just NULL terminate the source to annihilate the argument,
         */
        arguments_str[arg_offset] = 0;
    }
    else
    {
        /*
         * if argument was not first terminate on space before argument
         */
        arguments_str[arg_offset - 1] = 0;
    }

exit:
    SHR_FUNC_EXIT;
}

static shr_error_e
cmd_shell_exec_compare(
    int unit,
    sh_sand_cmd_t * sh_sand_cmd,
    char *filename,
    char *file_only,
    void *flex_ptr,
    int flags)
{
    sal_usecs_t usec;
    shell_flex_t *shell_flex_p = (shell_flex_t *) flex_ptr;
    prt_control_t *prt_ctr;
    sh_sand_control_t *sand_control;
    char *filter_n;

    SHR_FUNC_INIT_VARS(unit);

    if ((shell_flex_p == NULL) || ((prt_ctr = shell_flex_p->prt_ctr) == NULL) ||
        ((sand_control = shell_flex_p->sand_control) == NULL))
    {
        SHR_ERR_EXIT(_SHR_E_INTERNAL, "Memory Error\n");
    }

    PRT_ROW_ADD(PRT_ROW_SEP_NONE);

    PRT_CELL_SET("%s - xml output verify", sh_sand_cmd->cmd_only);
    usec = sal_time_usecs();

    if (utilex_is_prime_flag_set(flags, SH_CMD_LOG))
    {
        LOG_CLI((BSL_META("Compare output with gold result for Command:'%s'\n"), sh_sand_cmd->cmd_only));
    }

    SH_SAND_GET_STR("list", filter_n);

    SHR_SET_CURRENT_ERR(sh_sand_gold_compare(unit, filename, file_only, filter_n, flags));

    /*
     * Check if the command is not to be skipped when running in batch, then add options if any
     */
    if (utilex_is_prime_flag_set(sh_sand_cmd->flags, SH_CMD_SKIP_EXEC)
        && !utilex_is_prime_flag_set(flags, SH_CMD_FORCE))
    {
        PRT_CELL_SET("%s", "SKIP");
        shell_flex_p->skipped++;
        if (utilex_is_prime_flag_set(flags, SH_CMD_FAILURE_ONLY))
        {
            /*
             * Do not record succeeded tests - only failed ones
             */
            PRT_ROW_DELETE();
            SHR_EXIT();
        }
    }
    else
    {
        if (SHR_GET_CURRENT_ERR() == _SHR_E_EMPTY)
        {
            PRT_CELL_SET("%s", "No XML Output");
            shell_flex_p->succeeded++;
            SHR_SET_CURRENT_ERR(_SHR_E_NONE);
        }
        else if (SHR_GET_CURRENT_ERR() == _SHR_E_NOT_FOUND)
        {
            PRT_CELL_SET("%s", "No Gold Result");
            shell_flex_p->failed++;
        }
        else if (SHR_GET_CURRENT_ERR() == _SHR_E_FAIL)
        {
            PRT_CELL_SET("%s", "Comparison Failed");
            shell_flex_p->failed++;
        }
        else
        {
            if (SHR_GET_CURRENT_ERR() == _SHR_E_NONE)
            {
                shell_flex_p->succeeded++;
                if (utilex_is_prime_flag_set(flags, SH_CMD_FAILURE_ONLY))
                {
                    /*
                     * Do not record succeeded tests - only failed ones
                     */
                    PRT_ROW_DELETE();
                    SHR_EXIT();
                }
            }
            else
            {
                shell_flex_p->failed++;
            }
            PRT_CELL_SET("%s", shrextend_errmsg_get(SHR_GET_CURRENT_ERR()));
        }
    }

    usec = sal_time_usecs() - usec;
    PRT_CELL_SET("%u", usec);

exit:
    if (utilex_is_prime_flag_set(flags, SH_CMD_LOG))
    {
        if (SHR_GET_CURRENT_ERR() == _SHR_E_NONE)
        {
            LOG_CLI((BSL_META("\tSuccess\n")));
        }
        else
        {
            LOG_CLI((BSL_META("\tFailure\n")));
        }
    }
    SHR_FUNC_EXIT;
}

static shr_error_e
cmd_shell_exec_single(
    int unit,
    int *core,
    args_t * args,
    sh_sand_cmd_t * sh_sand_cmd,
    char *options_str,
    void *flex_ptr,
    int flags)
{
    args_t *leaf_args = NULL;
    char command_str[SH_SAND_MAX_TOKEN_SIZE] = { 0 };
    sal_usecs_t usec;
    char *str_next;
    sh_sand_control_t sand_ctr_m;
    shell_flex_t *shell_flex_p = (shell_flex_t *) flex_ptr;
    prt_control_t *prt_ctr;
    unsigned long alloc_start = 0, free_start = 0;
    unsigned long alloc_end = 0, free_end = 0;
    uint32 current_not_freed_chunks_start = 0;
    uint32 current_not_freed_chunks_end = 0;

    SHR_FUNC_INIT_VARS(unit);

    sal_memset(&sand_ctr_m, 0, sizeof(sh_sand_control_t));

    if ((shell_flex_p == NULL) || ((prt_ctr = shell_flex_p->prt_ctr) == NULL))
    {
        SHR_ERR_EXIT(_SHR_E_INTERNAL, "Memory Error\n");
    }

    PRT_ROW_ADD(PRT_ROW_SEP_NONE);

    /*
     * Create actual command line
     */
    sal_snprintf(command_str, SH_SAND_MAX_TOKEN_SIZE - 1, "%s %s", sh_sand_cmd->cmd_only, options_str);

    PRT_CELL_SET("%s", command_str);
    usec = sal_time_usecs();

    if (utilex_is_prime_flag_set(flags, SH_CMD_LOG))
    {
        LOG_CLI((BSL_META("Command:'%s'\n"), command_str));
    }

    if ((leaf_args = sal_alloc(sizeof(args_t), "leafs")) == NULL)
    {
        SHR_SET_CURRENT_ERR(_SHR_E_MEMORY);
        PRT_CELL_SET("Memory Error");
        SHR_EXIT();
    }
    sal_memset(leaf_args, 0, sizeof(args_t));

    if (!ISEMPTY(options_str))
    {
        if (diag_parse_args(options_str, &str_next, leaf_args))
        {       /* Parses up to ; or EOL */
            SHR_SET_CURRENT_ERR(_SHR_E_PARAM);
            PRT_CELL_SET("Shell Error");
        }
    }

    /*
     * Check if the command is not to be skipped when running in batch, then add options if any
     */
    if (utilex_is_prime_flag_set(flags, SH_CMD_EXEC_LIST_ONLY))
    {
        SHR_SET_CURRENT_ERR(_SHR_E_NONE);
        PRT_CELL_SET("%s", "List");
    }
    else if (utilex_is_prime_flag_set(sh_sand_cmd->flags, SH_CMD_SKIP_EXEC)
             && !utilex_is_prime_flag_set(flags, SH_CMD_FORCE))
    {
        PRT_CELL_SET("%s", "SKIP");
        shell_flex_p->skipped++;
        if (utilex_is_prime_flag_set(flags, SH_CMD_FAILURE_ONLY))
        {
            /*
             * Do not record succeeded tests - only failed ones
             */
            PRT_ROW_DELETE();
            SHR_EXIT();
        }
    }
    else if (SHR_FAILURE
             (sh_sand_option_list_process(unit, core, leaf_args, sh_sand_cmd, &sand_ctr_m, sh_sand_cmd->flags)))
    {
        SHR_SET_CURRENT_ERR(_SHR_E_PARAM);
        PRT_CELL_SET("%s", "Argument Error");
        shell_flex_p->failed++;
    }
    else
    {
        if (utilex_is_prime_flag_set(flags, SH_CMD_SILENT))
        {
            sh_process_command(unit, "debug appl shell warn");
        }
        sand_ctr_m.sh_sand_cmd = sh_sand_cmd;
        /** get memory allocation before running current step */
        sal_get_alloc_counters_main_thr(&(alloc_start), &(free_start));

#ifdef BCM_DNX_SUPPORT
        if (SOC_IS_DNX(unit))
        {
            /** get the amount of allocated memory before the action*/
            SHR_IF_ERR_EXIT(dnx_rollback_journal_get_current_alloc_memory(unit, &current_not_freed_chunks_start));
        }
#endif

        SHR_SET_CURRENT_ERR(sh_sand_cmd->action(unit, leaf_args, &sand_ctr_m));

#ifdef BCM_DNX_SUPPORT
        if (SOC_IS_DNX(unit))
        {
            /** get the amount of allocated memory after the action*/
            SHR_IF_ERR_EXIT(dnx_rollback_journal_get_current_alloc_memory(unit, &current_not_freed_chunks_end));
        }
#endif

    /** get memory allocation after ctest run */
        sal_get_alloc_counters_main_thr(&(alloc_end), &(free_end));

        if (utilex_is_prime_flag_set(flags, SH_CMD_SILENT))
        {
            sh_process_command(unit, "debug appl shell info");
        }

        if (!utilex_is_prime_flag_set(sh_sand_cmd->flags, SH_CMD_SKIP_MEMORY_CHECK))
        {
        /** "current_not_freed_chunks_end - current_not_freed_chunks_start" gives the number of chunks 
         *  that are allocated during command execution and have not yet been rollbacked.
         *  The value is substracted from the total amount of allocated memory, since the memory check happens before the rollback.
         */
            if ((SHR_GET_CURRENT_ERR() == _SHR_E_NONE)
                && ((alloc_end - alloc_start) - (current_not_freed_chunks_end - current_not_freed_chunks_start)) !=
                (free_end - free_start))
            {
                SHR_SET_CURRENT_ERR(_SHR_E_MEMORY);
            }
        }

        if (SHR_GET_CURRENT_ERR() == _SHR_E_NONE)
        {
            shell_flex_p->succeeded++;
            if (utilex_is_prime_flag_set(flags, SH_CMD_FAILURE_ONLY))
            {
                /*
                 * Do not record succeeded tests - only failed ones
                 */
                PRT_ROW_DELETE();
                SHR_EXIT();
            }
        }
        else
        {
            shell_flex_p->failed++;
        }
        if (SHR_GET_CURRENT_ERR() == _SHR_E_MEMORY)
        {
            PRT_CELL_SET("%s", "Memory Leak");
        }
        else
        {
            PRT_CELL_SET("%s", shrextend_errmsg_get(SHR_GET_CURRENT_ERR()));
        }

    }

    usec = sal_time_usecs() - usec;
    PRT_CELL_SET("%u", usec);
    if (!utilex_is_prime_flag_set(sh_sand_cmd->flags, SH_CMD_SKIP_MEMORY_CHECK))
    {
        PRT_CELL_SET("%lu",
                     (alloc_end - alloc_start) - (current_not_freed_chunks_end - current_not_freed_chunks_start));
        PRT_CELL_SET("%lu", free_end - free_start);
    }
    else
    {
        PRT_CELL_SET("%s", "     -");
        PRT_CELL_SET("%s", "     -");
    }
exit:
    if (utilex_is_prime_flag_set(flags, SH_CMD_LOG))
    {
        if (SHR_GET_CURRENT_ERR() == _SHR_E_NONE)
        {
            LOG_CLI((BSL_META("\tSuccess\n")));
        }
        else
        {
            LOG_CLI((BSL_META("\tFailure\n")));
        }
    }
    /*
     * Clean allocations from sand_ctr
     */
    sh_sand_option_list_clean(unit, &sand_ctr_m);
    /*
     * Free memory used for argument parsing
     */
    if (leaf_args != NULL)
    {
        sal_free(leaf_args);
    }
    SHR_FUNC_EXIT;
}

static shr_error_e
cmd_shell_exec(
    int unit,
    args_t * args,
    sh_sand_cmd_t * sh_sand_cmd,
    void *flex_ptr,
    int flags)
{
    shr_error_e cur_error;
    char add_arguments_str[SH_SAND_MAX_TOKEN_SIZE] = { 0 };
    char filename[SH_SAND_MAX_TOKEN_SIZE];
    char file_only[SH_SAND_MAX_TOKEN_SIZE];
    shell_flex_t *shell_flex_p = (shell_flex_t *) flex_ptr;
    sh_sand_control_t *sand_control;
    int verify_flag;
    int gold_flag;
    int cur_rv = _SHR_E_NONE;
    rhlist_t *examples_list = NULL;
    sh_sand_test_t *example;
    char args_str[SH_SAND_MAX_TOKEN_SIZE] = { 0 };
    int core = 0;
    int nof_cores = 1;
    int custom_flag = 0;
    int _flags = 0;
    char *custom_filename = NULL;

    SHR_FUNC_INIT_VARS(unit);

    if ((shell_flex_p == NULL) || ((sand_control = shell_flex_p->sand_control) == NULL))
    {
        SHR_ERR_EXIT(_SHR_E_INTERNAL, "Memory Error\n");
    }

    SH_SAND_GET_BOOL("verify", verify_flag);
    SH_SAND_GET_BOOL("gold", gold_flag);
    SH_SAND_IS_PRESENT("custom_verify", custom_flag);

    if (sh_sand_cmd->man == NULL)
    {
        SHR_CLI_EXIT(_SHR_E_INTERNAL, "Man pointer NULL for:%s", sh_sand_cmd->cmd_only);
    }
#ifndef NO_FILEIO
    if (utilex_is_prime_flag_set(flags, SH_CMD_OUTPUT_XML))
    {
        /** Add file= with the filename created from the command path */
        sh_sand_gold_filename(sh_sand_cmd->cmd_only, file_only);

        if (custom_flag == TRUE)
        {
            SH_SAND_GET_STR("custom_verify", custom_filename);
            sal_memset(file_only, 0, SH_SAND_MAX_TOKEN_SIZE);
            sal_strncpy(file_only, custom_filename, SH_SAND_MAX_TOKEN_SIZE - 1);
            utilex_prime_flag_set(&_flags, SH_CMD_CUSTOM_XML_VERIFY);
            sal_snprintf(add_arguments_str, SH_SAND_MAX_TOKEN_SIZE - 1, "file=%s gold custom_verify=%s", file_only,
                         file_only);
        }

        if (gold_flag == TRUE)
        {
            if (!custom_flag)
            {
                sal_snprintf(add_arguments_str, SH_SAND_MAX_TOKEN_SIZE - 1, "file=%s gold", file_only);
            }
            /*
             * Delete the file cleaning the place for new dumps
             */
            SHR_CLI_EXIT_IF_ERR(sh_sand_gold_path(unit, _flags, file_only, filename),
                                "Gold result file:'%s' cannot be obtained\n", filename);
        }
        else
        {

            char folder[RHFILE_MAX_SIZE] = { 0 };
            SHR_CLI_EXIT_IF_ERR(dbx_file_dir_create("xml"), "Failed to create 'xml'\n");
            SHR_CLI_EXIT_IF_ERR(dbx_file_dir_create("xml/gold"), "Failed to create 'xml/gold'\n");
            sal_snprintf(folder, RHFILE_MAX_SIZE, "xml/gold/");
            SHR_IF_ERR_EXIT(dbx_file_add_device_specific_suffix(unit, folder, TRUE));

            sal_snprintf(filename, SH_SAND_MAX_TOKEN_SIZE - 1, "%s/%s", folder, file_only);
            sal_snprintf(add_arguments_str, SH_SAND_MAX_TOKEN_SIZE - 1, "file=%s", filename);
        }
        /*
         * In both gold and regular writing remove first the existing one
         */
        SHR_CLI_EXIT_IF_ERR(dbx_file_remove(filename), "");
    }
#endif
    /*
     * Invoke init callback is set
     */
    if (sh_sand_cmd->man->init_cb)
    {
#ifdef BCM_DNX_SUPPORT
        if (SOC_IS_DNX(unit))
        {
            /*
             * If no deinit is defined - invoke transaction rollback
             */
            if (sh_sand_cmd->man->deinit_cb == NULL)
            {
                DNX_ROLLBACK_JOURNAL_START(unit);
            }
        }
#endif /* BCM_DNX_SUPPORT */

        SHR_CLI_EXIT_IF_ERR(sh_sand_cmd->man->init_cb(unit), "Init Callback on:%s failed\n", sh_sand_cmd->cmd_only);

    }

    SHR_CLI_EXIT_IF_ERR(sh_sand_examples_list_get(unit, SH_SAND_EXAMPLES_DYNAMIC, sh_sand_cmd, &examples_list), "");
    RHITERATOR(example, examples_list)
    {
        if (utilex_is_prime_flag_set(flags, SH_CMD_OUTPUT_XML))
        {
            if (sh_sand_exclude_argument(unit, example->params, "file=", ".xml") == _SHR_E_EXISTS)
            {
                /*
                 * Skip test of command that has used file argument for different purpose
                 * Do not test this example in framework write test and stop testing this command
                 */
                SHR_SET_CURRENT_ERR(_SHR_E_NONE);
                break;
            }
        }
        sal_snprintf(args_str, SH_SAND_MAX_TOKEN_SIZE - 1, "%s", example->params);
        if (!ISEMPTY(add_arguments_str))
        {
            sal_snprintf(args_str + sal_strnlen(args_str, SH_SAND_MAX_TOKEN_SIZE),
                         SH_SAND_MAX_TOKEN_SIZE - 1 - sal_strnlen(args_str, SH_SAND_MAX_TOKEN_SIZE), " %s",
                         add_arguments_str);
        }

        if (utilex_is_prime_flag_set(sh_sand_cmd->flags, SH_CMD_EXEC_PER_CORE))
        {
            /*
             * if SH_CMD_EXEC_PER_CORE flag is set update the nof_cores.
             */
            SHR_CLI_EXIT_IF_ERR(sh_sand_nof_cores_get(unit, &nof_cores), "Failed to get the number of cores.");
        }

#ifdef BCM_DNX_SUPPORT
        if (SOC_IS_DNX(unit))
        {
            int core_id = (nof_cores == 1) ? 0 : BCM_CORE_ALL;
            DNXCMN_CORES_ITER(unit, core_id, core)
            {
                cur_error = cmd_shell_exec_single(unit, &core, args, sh_sand_cmd, args_str, flex_ptr, flags);
                /*
                 * Preserve error for exit if it was one
                 */
                if (cur_error != _SHR_E_NONE)
                {
                    cur_rv = cur_error;
                    break;
                }
            }
        }
        else
#endif
        {
            for (core = 0; core < nof_cores; core++)
            {
                cur_error = cmd_shell_exec_single(unit, &core, args, sh_sand_cmd, args_str, flex_ptr, flags);
                /*
                 * Preserve error for exit if it was one
                 */
                if (cur_error != _SHR_E_NONE)
                {
                    cur_rv = cur_error;
                    break;
                }
            }
        }
    }

#if !defined(NO_FILEIO)
    /*
     * Compare content of freshly baked XMl with gold result
     */
    if (utilex_is_prime_flag_set(flags, SH_CMD_OUTPUT_XML))
    {
        if (verify_flag == TRUE)
        {
            if (custom_flag == TRUE)
            {
                utilex_prime_flag_set(&flags, SH_CMD_CUSTOM_XML_VERIFY);
            }

            cur_rv = cmd_shell_exec_compare(unit, sh_sand_cmd, filename, file_only, flex_ptr, flags);
        }
        else if (gold_flag == TRUE)
        {
            /*
             * Check first if gold result exists
             */
            if (sh_sand_gold_exists(unit, sh_sand_cmd->cmd_only) == _SHR_E_NONE)
            {
                if ((cur_rv =
                     diag_sand_prt_gold_sanitize(unit, _flags, sh_sand_cmd->cmd_only, file_only)) != _SHR_E_NONE)
                {
                    shell_flex_p->failed++;
                }
            }
        }
    }
#endif /* #if !defined(NO_FILEIO) */

    /*
     * Each command will be separated by underscore line in resulting table
     */
    {
        prt_control_t *prt_ctr = ((shell_flex_t *) flex_ptr)->prt_ctr;
        PRT_ROW_SET_MODE(PRT_ROW_SEP_UNDERSCORE);
    }

    if (sh_sand_cmd->man->deinit_cb)
    {
        SHR_CLI_EXIT_IF_ERR(sh_sand_cmd->man->deinit_cb(unit), "DeInit Callback on:%s failed\n", sh_sand_cmd->cmd_only);
    }
#ifdef BCM_DNX_SUPPORT
    else if (SOC_IS_DNX(unit) && (sh_sand_cmd->man->init_cb))
    {
        DNX_ROLLBACK_JOURNAL_END_AND_CLEAR(unit);
    }
#endif /* BCM_DNX_SUPPORT */
    SHR_SET_CURRENT_ERR(cur_rv);
exit:
    sh_sand_examples_list_free(unit, examples_list);
    SHR_FUNC_EXIT;
}

static shr_error_e
sys_exec_cmd(
    int unit,
    args_t * args,
    sh_sand_control_t * sand_control)
{
    int flags = 0, in_flag;
    shell_flex_t shell_flex;
    sal_usecs_t usec;
    int cur_rv = _SHR_E_NONE;

    unsigned long alloc_start, free_start, alloc_end, free_end;

    PRT_INIT_VARS;
    SHR_FUNC_INIT_VARS(NO_UNIT);

    SH_SAND_GET_BOOL("all", in_flag);
    if (in_flag == TRUE)
        utilex_prime_flag_set(&flags, SH_CMD_ALL);
    SH_SAND_GET_BOOL("logger", in_flag);
    if (in_flag == TRUE)
        utilex_prime_flag_set(&flags, SH_CMD_LOG);
    SH_SAND_GET_BOOL("force", in_flag);
    if (in_flag == TRUE)
        utilex_prime_flag_set(&flags, SH_CMD_FORCE);
    SH_SAND_GET_BOOL("failed", in_flag);
    if (in_flag == TRUE)
        utilex_prime_flag_set(&flags, SH_CMD_FAILURE_ONLY);
    SH_SAND_GET_BOOL("quiet", in_flag);
    if (in_flag == TRUE)
        utilex_prime_flag_set(&flags, SH_CMD_SILENT);
    SH_SAND_GET_BOOL("write", in_flag);
    if (in_flag == TRUE)
        utilex_prime_flag_set(&flags, SH_CMD_OUTPUT_XML);
    SH_SAND_GET_BOOL("show", in_flag);
    if (in_flag == TRUE)
        utilex_prime_flag_set(&flags, SH_CMD_EXEC_LIST_ONLY);
    if (utilex_is_prime_flag_set(sand_control->sh_sand_cmd->flags, SH_CMD_SKIP_MEMORY_CHECK))
        utilex_prime_flag_set(&flags, SH_CMD_SKIP_MEMORY_CHECK);

    PRT_TITLE_SET("%s", "Commands Examples Execution");
    PRT_COLUMN_ADD_FLEX(PRT_FLEX_ASCII, "Command");
    PRT_COLUMN_ADD("Status");
    PRT_COLUMN_ADD("Time(usec)");
    PRT_COLUMN_ALIGN;

    PRT_COLUMN_ADD("Memory Alloc");
    PRT_COLUMN_ADD("Memory Free");

    shell_flex.failed = 0;
    shell_flex.succeeded = 0;
    shell_flex.skipped = 0;
    shell_flex.prt_ctr = prt_ctr;
    shell_flex.sand_control = sand_control;

    usec = sal_time_usecs();
    /** get memory allocation before running current step */
    sal_get_alloc_counters(&(alloc_start), &(free_start));

    if (sand_control->sh_sand_cmd_a)
    {
        cur_rv = sh_sand_cmd_traverse(unit, NULL, sand_control->sh_sand_cmd_a, cmd_shell_exec, (void *) &shell_flex, flags, NULL        /* label 
                                                                                                                                         */ );
    }
    else if (sand_control->sh_sand_cmd)
    {
        cur_rv =
            SHR_SET_CURRENT_ERR(cmd_shell_exec(unit, NULL, sand_control->sh_sand_cmd, (void *) &shell_flex, flags));
    }
    PRT_ROW_ADD(PRT_ROW_SEP_UNDERSCORE_BEFORE);
    PRT_CELL_SET("Failed:%d", shell_flex.failed);
    PRT_CELL_SET("Success:%d", shell_flex.succeeded);
    usec = sal_time_usecs() - usec;
    PRT_CELL_SET("%u", usec);

    /** get memory allocation after ctest run */
    sal_get_alloc_counters(&(alloc_end), &(free_end));
    PRT_CELL_SET("%lu", alloc_end - alloc_start);
    PRT_CELL_SET("%lu", free_end - free_start);
    PRT_COMMITX;
    SHR_SET_CURRENT_ERR(cur_rv);
exit:
    PRT_FREE;
    SHR_FUNC_EXIT;
}
/*
 * Above commands are relevant only if CTEST included
 * }
 */
#endif /* INCLUDE_CTEST */

#ifndef NO_FILEIO
/**
 * \brief
 * List all defined tests for node or leaf
 * \param [in] sh_sand_cmd - pointer to command which will generate output
 * \param [in] filename    - pointer to allocated space where resulting test name will be formed
 *
 * \remark
 *     Routine does not return the failure - if something went wrong test will fail
 */
static void
sh_sand_fill_output_name(
    sh_sand_cmd_t * sh_sand_cmd,
    char *filename)
{
    /*
     * Currently all dumps will start from shell_ - we may change it if we need
     */
    sal_snprintf(filename, SH_SAND_MAX_TOKEN_SIZE - 1, "shell_");
    /*
     * Each command contain space separated command line, append entire command chain (spaces will be turned to _ below
     */
    sal_strncat_s(filename, sh_sand_cmd->cmd_only, SH_SAND_MAX_TOKEN_SIZE);
    /*
     * Finally append xml extension
     */
    sal_strncat_s(filename, ".xml", SH_SAND_MAX_TOKEN_SIZE);
    /*
     * Replace all non-compliant characters in the test name by underscore
     */
    utilex_str_escape(filename, '_');
    /*
     * Make it all lower case to ease the view
     */
    utilex_str_to_lower(filename);
    return;
}

static shr_error_e
sh_sand_manual_leaf_enums_recursive(
    int unit,
    sh_sand_enum_t * enum_entry,
    char *keyword,
    int depth,
    void *values_node)
{
    void *value_node;
    char *def_str;

    SHR_FUNC_INIT_VARS(unit);

    for (; !ISEMPTY(enum_entry->string) || enum_entry->inherited_enum != NULL; enum_entry++)
    {
        if (enum_entry->inherited_enum != NULL)
        {
            SHR_IF_ERR_EXIT_NO_MSG(sh_sand_manual_leaf_enums_recursive
                                   (unit, enum_entry->inherited_enum, keyword, depth, values_node));
            if (ISEMPTY(enum_entry->string))
            {
                continue;
            }
        }
        if ((value_node = dbx_xml_child_add(values_node, "value", depth + 4)) == NULL)
        {
            SHR_CLI_EXIT(_SHR_E_FAIL, "failed to add enum value node to EnumValues of %s node\n", keyword);
        }
        RHDATA_SET_STR(value_node, "name", enum_entry->string);
        if (ISEMPTY(enum_entry->desc))
        {
            def_str = "TBD";
        }
        else
        {
            def_str = enum_entry->desc;
        }
        RHDATA_SET_STR(value_node, "description", def_str);
        dbx_xml_node_end(value_node, depth + 4);
    }

exit:
    SHR_FUNC_EXIT;
}

static shr_error_e
sh_sand_manual_leaf_options_recursive(
    int unit,
    sh_sand_option_t * options,
    char *keyword,
    int depth,
    void *options_node)
{
    void *single_node;
    sh_sand_option_t *option;

    SHR_FUNC_INIT_VARS(unit);

    for (option = options; option->keyword != NULL || option->inherited_options != NULL; option++)
    {
        char *def_str;
        if (option->inherited_options != NULL)
        {
            SHR_IF_ERR_EXIT_NO_MSG(sh_sand_manual_leaf_options_recursive
                                   (unit, option->inherited_options, keyword, depth, options_node));
            if (ISEMPTY(option->keyword))
            {
                continue;
            }
        }
        if ((single_node = dbx_xml_child_add(options_node, "argument", depth + 2)) == NULL)
        {
            SHR_CLI_EXIT(_SHR_E_FAIL, "failed to add argument node to %s node\n", keyword);
        }
        RHDATA_SET_STR(single_node, "name", option->keyword);
        RHDATA_SET_STR(single_node, "type", sal_field_type_str(option->type));
        if (option->def == NULL)
        {
            def_str = "NONE";
        }
        else if (ISEMPTY(option->def))
        {
            def_str = "EMPTY";
        }
        else
        {
            def_str = option->def;
        }
        RHDATA_SET_STR(single_node, "default", def_str);
        if (option->desc)
        {
            RHDATA_SET_STR(single_node, "description", option->desc);
        }
        if (option->ext_ptr != NULL)
        {
            sh_sand_enum_t *enum_entry = (sh_sand_enum_t *) (option->ext_ptr);
            void *values_node;
            if ((values_node = dbx_xml_child_add(single_node, "EnumValues", depth + 3)) == NULL)
            {
                SHR_CLI_EXIT(_SHR_E_FAIL, "failed to add EnumValues node to %s node\n", option->keyword);
            }

            SHR_IF_ERR_EXIT_NO_MSG(sh_sand_manual_leaf_enums_recursive
                                   (unit, enum_entry, option->keyword, depth, values_node));
            dbx_xml_node_end(values_node, depth + 3);
        }
        dbx_xml_node_end(single_node, depth + 2);
    }

exit:
    SHR_FUNC_EXIT;
}

/*
 * user Manual generation command is not relevant for NO-FILEIO systems
 * {
 */
static shr_error_e
sh_sand_manual_leaf(
    int unit,
    sh_sand_cmd_t * sh_sand_cmd,
    void *parent_node,
    int depth,
    char **label_tokens,
    uint32 token_count,
    sh_manual_type_e manual_type)
{
    void *cur_node;
    char **synopsis = NULL;
    uint32 synopsis_num = 0;
    rhlist_t *examples_list = NULL;
    sh_sand_test_t *example;
    void *examples_node, *item_node;
    uint8 label_match = FALSE;

    SHR_FUNC_INIT_VARS(unit);

    SHR_NULL_CHECK(sh_sand_cmd, _SHR_E_PARAM, "sh_sand_cmd");

    SHR_CLI_EXIT_IF_ERR(sys_manual_label_match(unit, sh_sand_cmd->label, label_tokens, token_count, &label_match),
                        "Error in regex label match.");

    if (((manual_type == MANUAL_TYPE_SHELL_RELEASE || manual_type == MANUAL_TYPE_SHELL) && label_match == FALSE) ||
        (!(manual_type == MANUAL_TYPE_SHELL) && utilex_is_prime_flag_set(sh_sand_cmd->flags, SH_CMD_NOT_RELEASE)) ||
        (manual_type == MANUAL_TYPE_CTEST && !(utilex_is_prime_flag_set(sh_sand_cmd->flags, CTEST_UM))))
    {
        SHR_EXIT();
    }

    if ((cur_node = dbx_xml_child_add(parent_node, sh_sand_cmd->keyword, depth)) == NULL)
    {
        SHR_ERR_EXIT(_SHR_E_FAIL, "failed to add %s node\n", sh_sand_cmd->keyword);
    }
    if ((sh_sand_cmd->man != NULL) && (sh_sand_cmd->man->brief != NULL))
    {
        RHDATA_SET_STR(cur_node, "Brief", (char *) sh_sand_cmd->man->brief);
    }
    if ((sh_sand_cmd->man != NULL) && (sh_sand_cmd->man->full != NULL))
    {
        RHDATA_SET_STR(cur_node, "Description", (char *) sh_sand_cmd->man->full);
    }
    if ((sh_sand_cmd->man != NULL) && (sh_sand_cmd->man->compatibility != NULL))
    {
        RHDATA_SET_STR(cur_node, "Support", (char *) sh_sand_cmd->man->compatibility);
    }

    if (!ISEMPTY(sh_sand_cmd->cmd_only))
    {
        char filename[SH_SAND_MAX_TOKEN_SIZE];
        char file_only[SH_SAND_MAX_TOKEN_SIZE];

        sh_sand_fill_output_name(sh_sand_cmd, file_only);

        if ((sh_sand_gold_path(unit, 0, file_only, filename) == _SHR_E_NONE) && (dbx_file_exists(filename)))
        {
            RHDATA_SET_STR(cur_node, "XML", "Yes");
        }
        else
        {
            RHDATA_SET_STR(cur_node, "XML", "No");
        }
    }

    SHR_CLI_EXIT_IF_ERR(sh_sand_synopsis_get(unit, sh_sand_cmd, &synopsis, &synopsis_num), "");
    {
        void *synopsis_node, *item_node;
        int i_ex;
        if ((synopsis_node = dbx_xml_child_add(cur_node, "Synopsis", depth + 1)) == NULL)
        {
            SHR_CLI_EXIT(_SHR_E_FAIL, "failed to add synopsis node to %s node\n", sh_sand_cmd->keyword);
        }
        for (i_ex = 0; i_ex < synopsis_num; i_ex++)
        {
            if ((item_node = dbx_xml_child_add(synopsis_node, "item", depth + 2)) == NULL)
            {
                SHR_CLI_EXIT(_SHR_E_FAIL, "failed to add item node to parent for %s\n", sh_sand_cmd->keyword);
            }
            RHDATA_SET_STR(item_node, "command", synopsis[i_ex]);
            dbx_xml_node_end(item_node, depth + 2);
        }
        dbx_xml_node_end(synopsis_node, depth + 1);
    }

    if ((examples_node = dbx_xml_child_add(cur_node, "Examples", depth + 1)) == NULL)
    {
        SHR_CLI_EXIT(_SHR_E_FAIL, "failed to add examples node to %s node\n", sh_sand_cmd->keyword);
    }

    SHR_CLI_EXIT_IF_ERR(sh_sand_examples_list_get
                        (unit, SH_SAND_EXAMPLES_FULL | SH_SAND_EXAMPLES_DYNAMIC, sh_sand_cmd, &examples_list), "");
    RHITERATOR(example, examples_list)
    {
        if ((item_node = dbx_xml_child_add(examples_node, "item", depth + 2)) == NULL)
        {
            SHR_CLI_EXIT(_SHR_E_FAIL, "failed to add item node to parent for %s\n", sh_sand_cmd->keyword);
        }
        RHDATA_SET_STR(item_node, "command", example->params);
        dbx_xml_node_end(item_node, depth + 2);
    }
    dbx_xml_node_end(examples_node, depth + 1);

    if (sh_sand_cmd->options != NULL)
    {
        void *options_node;
        if ((options_node = dbx_xml_child_add(cur_node, "Arguments", depth + 1)) == NULL)
        {
            SHR_CLI_EXIT(_SHR_E_FAIL, "failed to add argument node to %s node\n", sh_sand_cmd->keyword);
        }

        SHR_IF_ERR_EXIT_NO_MSG(sh_sand_manual_leaf_options_recursive
                               (unit, sh_sand_cmd->options, sh_sand_cmd->keyword, depth, options_node));
        dbx_xml_node_end(options_node, depth + 1);
    }
    dbx_xml_node_end(cur_node, depth);

exit:
    sh_sand_examples_list_free(unit, examples_list);
    utilex_str_split_free(synopsis, synopsis_num);
    SHR_FUNC_EXIT;
}

static shr_error_e
sh_sand_manual_branch(
    int unit,
    char *parent_name,
    char *parent_description,
    sh_sand_cmd_t * sh_sand_cmd_a,
    void *parent_node,
    int depth,
    char **label_tokens,
    uint32 token_count,
    sh_manual_type_e manual_type)
{
    sh_sand_cmd_t *sh_sand_cmd;
    void *cur_node;
    uint8 label_match = FALSE;

    SHR_FUNC_INIT_VARS(unit);
    SHR_NULL_CHECK(sh_sand_cmd_a, _SHR_E_INTERNAL, "sh_sand_cmd_a");

    SHR_CLI_EXIT_IF_ERR(sys_manual_label_match(unit, sh_sand_cmd_a->label, label_tokens, token_count, &label_match),
                        "Error in regex label match.");

    if (((!ISEMPTY(parent_name) && label_match) &&
         (manual_type == MANUAL_TYPE_SHELL ||
          (manual_type == MANUAL_TYPE_SHELL_RELEASE
           && !utilex_is_prime_flag_set(sh_sand_cmd_a->flags, SH_CMD_NOT_RELEASE))))
        || (manual_type == MANUAL_TYPE_CTEST && utilex_is_prime_flag_set(sh_sand_cmd_a->flags, CTEST_UM)))
    {
        if ((cur_node = dbx_xml_child_add(parent_node, parent_name, depth)) == NULL)
        {
            SHR_CLI_EXIT(_SHR_E_FAIL, "failed to add %s node\n", parent_name);
        }
        if (!ISEMPTY(parent_description))
        {
            RHDATA_SET_STR(cur_node, "Brief", parent_description);
        }
        if ((sh_sand_cmd = sh_sand_cmd_a->parent_cmd) != NULL)
        {
            if ((sh_sand_cmd->man != NULL) && (sh_sand_cmd->man->compatibility != NULL))
            {
                RHDATA_SET_STR(cur_node, "Support", (char *) sh_sand_cmd->man->compatibility);
            }
        }
    }
    else
    {
        cur_node = parent_node;
    }

    /*
     * For Manual we document all commands, that may run on certain device/device family, even if in present HW/SW
     * Configuration they are not available
     */
    SH_SAND_CMD_ITERATOR(sh_sand_cmd, sh_sand_cmd_a, SH_CMD_FLAGS_NONE)
    {

        if (sh_sand_cmd->child_cmd_a != NULL)
        {
            if (sh_sand_cmd->man != NULL)
            {
                parent_description = (char *) sh_sand_cmd->man->brief;
            }
            else
            {
                parent_description = NULL;
            }
            SHR_CLI_EXIT_IF_ERR(sh_sand_manual_branch(unit, sh_sand_cmd->full_key, parent_description,
                                                      sh_sand_cmd->child_cmd_a, cur_node, depth + 1, label_tokens,
                                                      token_count, manual_type), "");
        }
        else if (sh_sand_cmd->action != NULL)
        {
            SHR_CLI_EXIT_IF_ERR(sh_sand_manual_leaf
                                (unit, sh_sand_cmd, cur_node, depth + 1, label_tokens, token_count, manual_type), "");
        }
        else
        {
            SHR_CLI_EXIT(_SHR_E_INTERNAL, "Error(Command is neither node, nor leaf) on:%s\n", sh_sand_cmd->keyword);
        }
    }
    if ((label_match && ((manual_type == MANUAL_TYPE_SHELL) ||
                         (manual_type == MANUAL_TYPE_SHELL_RELEASE
                          && !utilex_is_prime_flag_set(sh_sand_cmd->flags, SH_CMD_NOT_RELEASE))))
        || (manual_type == MANUAL_TYPE_CTEST && utilex_is_prime_flag_set(sh_sand_cmd_a->flags, CTEST_UM)))
    {
        dbx_xml_node_end(cur_node, depth);
    }

exit:
    SHR_FUNC_EXIT;
}

#ifndef NO_FILEIO
static sh_sand_man_t sys_manual_man = {
    .brief = "Export usage to xml file. By default it will be manual.xml placed in $PWD."
        "Argument 'file' may be used to assign any other name or/and path",
    .examples = "file=Full_UM.xml\n"
};
#endif

static shr_error_e
sys_manual_cmd(
    int unit,
    args_t * args,
    sh_sand_control_t * sand_control)
{
    sh_manual_type_e manual_type = MANUAL_TYPE_SHELL;
    int release;
    char *introduction =
        "This document presents description of all shell commands written in the context of framework,"
        "that provides unified approach in command invocation and usage."
        "All commands are organized in command tree, where leaves are actual executable commands."
        "Manual presents description, synopsis, arguments and examples per each leaf."
        "Each argument has certain type which defines input format, as may be see from argument description"
        "Argument may have default and thus not required on command line, if there is no default(tagged by 'None' in usage)"
        "user must provide it."
        "All arguments should be provided in arg=<value> paradigm with 2 exceptions:"
        "1. Boolean argument provided without value imply 'TRUE', "
        "2. Argument with 'free' tag allows omitting argument name, providing values only. Values without argument names "
        "will be associated with free argument according to the order. 1st nameless argument to the 1st free one,"
        "2nd to the second and so on"
        "Besides the arguments presented per command, there are system arguments that may be used with any leaf,"
        "There are also system commands which may be invoked after each branch or leaf, see details below"
        ""
        "## If you want to create a user manual for the shell command, please do the following:"
        "load the driver and call the command:"
        "{device_type} manual file=manual.xml"
        "example:"
        "dnx manual file=manual.xml"
        ""
        "## if you want to generate examples :"
        "load the driver and save the output to a external file (e.g.: {device_id}_exec_log.txt) and call the command:"
        "{device_type} exec logger"
        "example:"
        "dnx exec logger"
        ""
        "## To transfer the user manual from XML to HTML, you should download 'saxon9he.jar'"
        "java -jar saxon9he.jar -s:manual.xml -xsl:$SDK/tools/sand/manual/{device_id}_Manual_XSLT.xsl -o:manual.html"
        ""
        "## if you have decided to use the examples option and HTML, use the following PYTHON program from the sdk root folder:"
        "tools/sand/manual/cmd_examples.py --device_id " "{device_id}" "--input {device_id}_exec_log.txt";

    SHR_FUNC_INIT_VARS(unit);
    SH_SAND_GET_BOOL("RELease", release);
    if (release == TRUE)
        manual_type = MANUAL_TYPE_SHELL_RELEASE;
    SHR_IF_ERR_EXIT(sys_manual_cmd_internal(unit, args, sand_control, introduction, manual_type));

exit:
    SHR_FUNC_EXIT;

}

shr_error_e
sys_manual_cmd_internal(
    int unit,
    args_t * args,
    sh_sand_control_t * sand_control,
    char *introduction,
    sh_manual_type_e manual_type)
{
    char *filename;
    void *top_node, *intro_node;
    char **label_tokens = NULL;
    char *label;
    uint32 maxtokens = 100;
    uint32 realtokens = 0;

    SHR_FUNC_INIT_VARS(NO_UNIT);

    SH_SAND_GET_STR("file", filename);
    /*
     * Validate input
     */
    if (ISEMPTY(filename))
    {
        if (manual_type == MANUAL_TYPE_CTEST)
            filename = "ctest_manual.xml";
        else
            filename = "manual.xml";
    }
    else
    {
        if (dbx_file_get_type(filename) != DBX_FILE_XML)
        {
            SHR_CLI_EXIT(_SHR_E_PARAM, "File must have .xml suffix. File name was:\"%s\"\n", filename);
        }
    }

    SH_SAND_GET_STR("label", label);
    utilex_str_white_spaces_remove(label);
    label_tokens = utilex_str_split(label, ",", maxtokens, &realtokens);

    /*
     * Create XML Document
     */
    if ((top_node = dbx_file_get_xml_top(unit, filename, "top",
                                         CONF_OPEN_CREATE | CONF_OPEN_OVERWRITE | CONF_OPEN_CURRENT_LOC)) == NULL)
    {
        SHR_CLI_EXIT(_SHR_E_FAIL, "Failed to create:\"%s\"\n", filename);
    }

    if ((intro_node = dbx_xml_child_add(top_node, "General", 1)) == NULL)
        SHR_CLI_EXIT(_SHR_E_FAIL, "failed to add introduction node\n");

    RHDATA_SET_STR(intro_node, "Introduction", (char *) introduction);

    /*
     * Add system arguments description
     */
    if (manual_type != MANUAL_TYPE_CTEST)
    {
        sh_sand_cmd_t system_arguments_cmd;

        sal_memset(&system_arguments_cmd, 0, sizeof(sh_sand_cmd_t));

        system_arguments_cmd.keyword = system_arguments_cmd.full_key = "System_Arguments";
        system_arguments_cmd.man = &sh_sand_sys_arguments_man;
        system_arguments_cmd.options = sh_sand_sys_arguments;
        sh_sand_manual_leaf(unit, &system_arguments_cmd, intro_node, 1, label_tokens, realtokens, manual_type);
    }
    /*
     *  Add System Command Section
     */
    if (sand_control->sh_sys_cmd_a != NULL)
    {
        SHR_CLI_EXIT_IF_ERR(sh_sand_manual_branch(unit, "System_Commands",
                                                  "Commands applicable after each regular command",
                                                  sand_control->sh_sys_cmd_a, intro_node, 1,
                                                  label_tokens, realtokens, manual_type), "");
    }
    /*
     * For leaf just fill one node and left, for node go into recursion on the entire branch
     */
    if (sand_control->sh_sand_cmd_a)
    {
        SHR_CLI_EXIT_IF_ERR(sh_sand_manual_branch
                            (unit, NULL, NULL, sand_control->sh_sand_cmd_a, top_node, 0, label_tokens, realtokens,
                             manual_type), "");
    }
    else if (sand_control->sh_sand_cmd)
    {
        SHR_CLI_EXIT_IF_ERR(sh_sand_manual_leaf
                            (unit, sand_control->sh_sand_cmd, top_node, 0, label_tokens, realtokens, manual_type), "");
    }

    dbx_xml_top_save(top_node, filename);
    dbx_xml_top_close(top_node);

exit:
    utilex_str_split_free(label_tokens, realtokens);
    SHR_FUNC_EXIT;
}
/*
 * }
 */
#endif

#ifndef __KERNEL__
/*
 * Set severity corresponding to bsl meta identifier as specified
 * and return originally stored severity.
 */
static bsl_severity_t
set_log_level_to(
    unsigned long meta_identifier,
    bsl_severity_t required_severity)
{
    int layer, source;
    bsl_severity_t stored_severity;

    layer = BSL_LAYER_GET(meta_identifier);
    source = BSL_SOURCE_GET(meta_identifier);
    stored_severity = bslenable_get(layer, source);
    bslenable_set((bsl_layer_t) layer, (bsl_source_t) source, required_severity);
    return (stored_severity);
}
#endif /* __KERNEL__ */

char cmd_set_device_usage[] =
    "\n Change the device identification (PCIE device+revision ID) to the SDK.\n"
    "Usages:\n" "set_device <device ID> <revision ID>\n" "\n";

cmd_result_t
cmd_set_device(
    int unit,
    args_t * a)
{
#ifndef __KERNEL__
    bsl_severity_t original_severity;
    cmd_result_t ret;
    char *param;
    uint32 dev_id;
    uint32 rev_id;
    ibde_dev_t *dev = (ibde_dev_t *) bde->get_dev(CMDEV(unit).dev.dev);

    /*
     * Set log level of I2C to 'warning'. Restore at exit.
     */
    original_severity = set_log_level_to(BSL_LS_SOC_I2C, bslSeverityWarn);

    /*
     * get dev id
     */
    param = ARG_GET(a);
    if (!param)
    {
        return CMD_USAGE;
    }
    else
    {
        dev_id = sal_ctoi(param, 0);
    }

    /*
     * get rev id
     */
    param = ARG_GET(a);
    if (!param)
    {
        rev_id = DNXC_A0_REV_ID;
    }
    else
    {
        rev_id = sal_ctoi(param, 0);
    }

    CMDEV(unit).dev.dev_id = dev_id;
    CMDEV(unit).dev.rev_id = rev_id;

    dev->device = dev_id;
    dev->rev = rev_id;

    ret = CMD_OK;

    /*
     * Restore log level of I2C.
     */
    set_log_level_to(BSL_LS_SOC_I2C, original_severity);
    return (ret);
#else /* __KERNEL__ */
    cli_out("This function is unavailable in Kernel mode\n");
    return CMD_USAGE;
#endif /* __KERNEL__ */
}

/* *INDENT-OFF* */
#ifndef NO_FILEIO
sh_sand_option_t sys_manual_arguments[] = {
    {"label"  ,   SAL_FIELD_TYPE_STR,   "Specific label to sort the commands with.",  ""},
    {"RELease",   SAL_FIELD_TYPE_BOOL,  "User manual for release"                  ,"No"},
    {NULL}
};
#endif

sh_sand_cmd_t sh_sand_sys_cmds[] = {
    {"usage",           sys_usage_cmd,  NULL, sys_usage_arguments,  &sys_usage_man},
    {"help",            sys_usage_cmd,  NULL, sys_usage_arguments,  &sys_usage_man},
#ifndef NO_FILEIO
    {"manual",          sys_manual_cmd, NULL, sys_manual_arguments, &sys_manual_man},
#endif
#ifdef INCLUDE_CTEST
    {"exec",            sys_exec_cmd,   NULL, sys_exec_arguments,   &sys_exec_man},
    {"UsageTEST",       sys_verify_cmd, NULL, sys_verify_arguments, &sys_verify_man},
#endif
    {NULL}
};
/* *INDENT-ON* */
