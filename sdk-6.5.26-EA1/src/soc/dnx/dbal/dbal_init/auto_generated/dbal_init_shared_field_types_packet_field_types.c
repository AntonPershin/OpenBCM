
/*
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2022 Broadcom Inc. All rights reserved.
 * 
 */

shr_error_e
_dbal_init_shared_field_types_packet_field_types_ipv4_init(
int unit,
field_type_db_struct_t * cur_field_type_param,
dbal_field_types_basic_info_t ** field_types_info)
{
    dbal_field_types_basic_info_t * cur_field_types_info = field_types_info[DBAL_FIELD_TYPE_DEF_IPV4];
    int is_valid = TRUE;
    SHR_FUNC_INIT_VARS(unit);
    dbal_init_field_type_db_struct_clear(unit, cur_field_type_param);
    SHR_IF_ERR_EXIT(dbal_db_init_field_type_general_info_set(unit, cur_field_types_info, "IPV4", 32, is_valid, FALSE, DBAL_FIELD_PRINT_TYPE_IPV4, 1, FALSE));
    dbal_init_field_type_default_restrict_values(cur_field_type_param);
    SHR_IF_ERR_EXIT(dbal_db_init_field_type_add(unit, cur_field_type_param, cur_field_types_info));
exit:
    SHR_FUNC_EXIT;
}

shr_error_e
_dbal_init_shared_field_types_packet_field_types_ipv6_init(
int unit,
field_type_db_struct_t * cur_field_type_param,
dbal_field_types_basic_info_t ** field_types_info)
{
    dbal_field_types_basic_info_t * cur_field_types_info = field_types_info[DBAL_FIELD_TYPE_DEF_IPV6];
    int is_valid = TRUE;
    SHR_FUNC_INIT_VARS(unit);
    dbal_init_field_type_db_struct_clear(unit, cur_field_type_param);
    SHR_IF_ERR_EXIT(dbal_db_init_field_type_general_info_set(unit, cur_field_types_info, "IPV6", 128, is_valid, FALSE, DBAL_FIELD_PRINT_TYPE_IPV6, 1, FALSE));
    dbal_init_field_type_default_restrict_values(cur_field_type_param);
    SHR_IF_ERR_EXIT(dbal_db_init_field_type_add(unit, cur_field_type_param, cur_field_types_info));
exit:
    SHR_FUNC_EXIT;
}

shr_error_e
_dbal_init_shared_field_types_packet_field_types_l2_mac_init(
int unit,
field_type_db_struct_t * cur_field_type_param,
dbal_field_types_basic_info_t ** field_types_info)
{
    dbal_field_types_basic_info_t * cur_field_types_info = field_types_info[DBAL_FIELD_TYPE_DEF_L2_MAC];
    int is_valid = TRUE;
    SHR_FUNC_INIT_VARS(unit);
    dbal_init_field_type_db_struct_clear(unit, cur_field_type_param);
    SHR_IF_ERR_EXIT(dbal_db_init_field_type_general_info_set(unit, cur_field_types_info, "L2_MAC", 48, is_valid, FALSE, DBAL_FIELD_PRINT_TYPE_MAC, 1, FALSE));
    dbal_init_field_type_default_restrict_values(cur_field_type_param);
    SHR_IF_ERR_EXIT(dbal_db_init_field_type_add(unit, cur_field_type_param, cur_field_types_info));
exit:
    SHR_FUNC_EXIT;
}

shr_error_e
_dbal_init_shared_field_types_packet_field_types_ipv4_dscp_init(
int unit,
field_type_db_struct_t * cur_field_type_param,
dbal_field_types_basic_info_t ** field_types_info)
{
    dbal_field_types_basic_info_t * cur_field_types_info = field_types_info[DBAL_FIELD_TYPE_DEF_IPV4_DSCP];
    int is_valid = TRUE;
    SHR_FUNC_INIT_VARS(unit);
    dbal_init_field_type_db_struct_clear(unit, cur_field_type_param);
    SHR_IF_ERR_EXIT(dbal_db_init_field_type_general_info_set(unit, cur_field_types_info, "IPV4_DSCP", 6, is_valid, FALSE, DBAL_FIELD_PRINT_TYPE_UINT32, 1, FALSE));
    dbal_init_field_type_default_restrict_values(cur_field_type_param);
    SHR_IF_ERR_EXIT(dbal_db_init_field_type_add(unit, cur_field_type_param, cur_field_types_info));
exit:
    SHR_FUNC_EXIT;
}

shr_error_e
_dbal_init_shared_field_types_packet_field_types_ipv4_ecn_init(
int unit,
field_type_db_struct_t * cur_field_type_param,
dbal_field_types_basic_info_t ** field_types_info)
{
    dbal_field_types_basic_info_t * cur_field_types_info = field_types_info[DBAL_FIELD_TYPE_DEF_IPV4_ECN];
    int is_valid = TRUE;
    SHR_FUNC_INIT_VARS(unit);
    dbal_init_field_type_db_struct_clear(unit, cur_field_type_param);
    SHR_IF_ERR_EXIT(dbal_db_init_field_type_general_info_set(unit, cur_field_types_info, "IPV4_ECN", 2, is_valid, FALSE, DBAL_FIELD_PRINT_TYPE_UINT32, 1, FALSE));
    dbal_init_field_type_default_restrict_values(cur_field_type_param);
    SHR_IF_ERR_EXIT(dbal_db_init_field_type_add(unit, cur_field_type_param, cur_field_types_info));
exit:
    SHR_FUNC_EXIT;
}

shr_error_e
_dbal_init_shared_field_types_packet_field_types_ip_protocol_init(
int unit,
field_type_db_struct_t * cur_field_type_param,
dbal_field_types_basic_info_t ** field_types_info)
{
    dbal_field_types_basic_info_t * cur_field_types_info = field_types_info[DBAL_FIELD_TYPE_DEF_IP_PROTOCOL];
    int is_valid = TRUE;
    SHR_FUNC_INIT_VARS(unit);
    dbal_init_field_type_db_struct_clear(unit, cur_field_type_param);
    SHR_IF_ERR_EXIT(dbal_db_init_field_type_general_info_set(unit, cur_field_types_info, "IP_PROTOCOL", 8, is_valid, FALSE, DBAL_FIELD_PRINT_TYPE_UINT32, 1, FALSE));
    dbal_init_field_type_default_restrict_values(cur_field_type_param);
    SHR_IF_ERR_EXIT(dbal_db_init_field_type_add(unit, cur_field_type_param, cur_field_types_info));
exit:
    SHR_FUNC_EXIT;
}

shr_error_e
_dbal_init_shared_field_types_packet_field_types_ipv4_tos_init(
int unit,
field_type_db_struct_t * cur_field_type_param,
dbal_field_types_basic_info_t ** field_types_info)
{
    dbal_field_types_basic_info_t * cur_field_types_info = field_types_info[DBAL_FIELD_TYPE_DEF_IPV4_TOS];
    int is_valid = TRUE;
    SHR_FUNC_INIT_VARS(unit);
    dbal_init_field_type_db_struct_clear(unit, cur_field_type_param);
    SHR_IF_ERR_EXIT(dbal_db_init_field_type_general_info_set(unit, cur_field_types_info, "IPV4_TOS", 8, is_valid, FALSE, DBAL_FIELD_PRINT_TYPE_UINT32, 1, FALSE));
    dbal_init_field_type_default_restrict_values(cur_field_type_param);
    SHR_IF_ERR_EXIT(dbal_db_init_field_type_add(unit, cur_field_type_param, cur_field_types_info));
exit:
    SHR_FUNC_EXIT;
}

shr_error_e
_dbal_init_shared_field_types_packet_field_types_ipv4_header_reserved_flag_init(
int unit,
field_type_db_struct_t * cur_field_type_param,
dbal_field_types_basic_info_t ** field_types_info)
{
    dbal_field_types_basic_info_t * cur_field_types_info = field_types_info[DBAL_FIELD_TYPE_DEF_IPV4_HEADER_RESERVED_FLAG];
    int is_valid = TRUE;
    SHR_FUNC_INIT_VARS(unit);
    dbal_init_field_type_db_struct_clear(unit, cur_field_type_param);
    SHR_IF_ERR_EXIT(dbal_db_init_field_type_general_info_set(unit, cur_field_types_info, "IPV4_HEADER_RESERVED_FLAG", 1, is_valid, FALSE, DBAL_FIELD_PRINT_TYPE_BOOL, 1, FALSE));
    dbal_init_field_type_default_restrict_values(cur_field_type_param);
    SHR_IF_ERR_EXIT(dbal_db_init_field_type_add(unit, cur_field_type_param, cur_field_types_info));
exit:
    SHR_FUNC_EXIT;
}

shr_error_e
_dbal_init_shared_field_types_packet_field_types_ipv4_header_df_flag_init(
int unit,
field_type_db_struct_t * cur_field_type_param,
dbal_field_types_basic_info_t ** field_types_info)
{
    dbal_field_types_basic_info_t * cur_field_types_info = field_types_info[DBAL_FIELD_TYPE_DEF_IPV4_HEADER_DF_FLAG];
    int is_valid = TRUE;
    SHR_FUNC_INIT_VARS(unit);
    dbal_init_field_type_db_struct_clear(unit, cur_field_type_param);
    SHR_IF_ERR_EXIT(dbal_db_init_field_type_general_info_set(unit, cur_field_types_info, "IPV4_HEADER_DF_FLAG", 1, is_valid, FALSE, DBAL_FIELD_PRINT_TYPE_BOOL, 1, FALSE));
    dbal_init_field_type_default_restrict_values(cur_field_type_param);
    SHR_IF_ERR_EXIT(dbal_db_init_field_type_add(unit, cur_field_type_param, cur_field_types_info));
exit:
    SHR_FUNC_EXIT;
}

shr_error_e
_dbal_init_shared_field_types_packet_field_types_ipv6_tos_init(
int unit,
field_type_db_struct_t * cur_field_type_param,
dbal_field_types_basic_info_t ** field_types_info)
{
    dbal_field_types_basic_info_t * cur_field_types_info = field_types_info[DBAL_FIELD_TYPE_DEF_IPV6_TOS];
    int is_valid = TRUE;
    SHR_FUNC_INIT_VARS(unit);
    dbal_init_field_type_db_struct_clear(unit, cur_field_type_param);
    SHR_IF_ERR_EXIT(dbal_db_init_field_type_general_info_set(unit, cur_field_types_info, "IPV6_TOS", 8, is_valid, FALSE, DBAL_FIELD_PRINT_TYPE_UINT32, 1, FALSE));
    dbal_init_field_type_default_restrict_values(cur_field_type_param);
    SHR_IF_ERR_EXIT(dbal_db_init_field_type_add(unit, cur_field_type_param, cur_field_types_info));
exit:
    SHR_FUNC_EXIT;
}

shr_error_e
_dbal_init_shared_field_types_packet_field_types_ipv6_flow_label_init(
int unit,
field_type_db_struct_t * cur_field_type_param,
dbal_field_types_basic_info_t ** field_types_info)
{
    dbal_field_types_basic_info_t * cur_field_types_info = field_types_info[DBAL_FIELD_TYPE_DEF_IPV6_FLOW_LABEL];
    int is_valid = TRUE;
    SHR_FUNC_INIT_VARS(unit);
    dbal_init_field_type_db_struct_clear(unit, cur_field_type_param);
    SHR_IF_ERR_EXIT(dbal_db_init_field_type_general_info_set(unit, cur_field_types_info, "IPV6_FLOW_LABEL", 20, is_valid, FALSE, DBAL_FIELD_PRINT_TYPE_UINT32, 1, FALSE));
    dbal_init_field_type_default_restrict_values(cur_field_type_param);
    SHR_IF_ERR_EXIT(dbal_db_init_field_type_add(unit, cur_field_type_param, cur_field_types_info));
exit:
    SHR_FUNC_EXIT;
}

shr_error_e
_dbal_init_shared_field_types_packet_field_types_ipv6_hop_limit_init(
int unit,
field_type_db_struct_t * cur_field_type_param,
dbal_field_types_basic_info_t ** field_types_info)
{
    dbal_field_types_basic_info_t * cur_field_types_info = field_types_info[DBAL_FIELD_TYPE_DEF_IPV6_HOP_LIMIT];
    int is_valid = TRUE;
    SHR_FUNC_INIT_VARS(unit);
    dbal_init_field_type_db_struct_clear(unit, cur_field_type_param);
    SHR_IF_ERR_EXIT(dbal_db_init_field_type_general_info_set(unit, cur_field_types_info, "IPV6_HOP_LIMIT", 8, is_valid, FALSE, DBAL_FIELD_PRINT_TYPE_UINT32, 1, FALSE));
    dbal_init_field_type_default_restrict_values(cur_field_type_param);
    SHR_IF_ERR_EXIT(dbal_db_init_field_type_add(unit, cur_field_type_param, cur_field_types_info));
exit:
    SHR_FUNC_EXIT;
}

shr_error_e
_dbal_init_shared_field_types_packet_field_types_l4_port_init(
int unit,
field_type_db_struct_t * cur_field_type_param,
dbal_field_types_basic_info_t ** field_types_info)
{
    dbal_field_types_basic_info_t * cur_field_types_info = field_types_info[DBAL_FIELD_TYPE_DEF_L4_PORT];
    int is_valid = TRUE;
    SHR_FUNC_INIT_VARS(unit);
    dbal_init_field_type_db_struct_clear(unit, cur_field_type_param);
    SHR_IF_ERR_EXIT(dbal_db_init_field_type_general_info_set(unit, cur_field_types_info, "L4_PORT", 16, is_valid, FALSE, DBAL_FIELD_PRINT_TYPE_UINT32, 1, FALSE));
    dbal_init_field_type_default_restrict_values(cur_field_type_param);
    SHR_IF_ERR_EXIT(dbal_db_init_field_type_add(unit, cur_field_type_param, cur_field_types_info));
exit:
    SHR_FUNC_EXIT;
}

shr_error_e
_dbal_init_shared_field_types_packet_field_types_l4_src_port_init(
int unit,
field_type_db_struct_t * cur_field_type_param,
dbal_field_types_basic_info_t ** field_types_info)
{
    dbal_field_types_basic_info_t * cur_field_types_info = field_types_info[DBAL_FIELD_TYPE_DEF_L4_SRC_PORT];
    int is_valid = TRUE;
    SHR_FUNC_INIT_VARS(unit);
    dbal_init_field_type_db_struct_clear(unit, cur_field_type_param);
    SHR_IF_ERR_EXIT(dbal_db_init_field_type_general_info_set(unit, cur_field_types_info, "L4_SRC_PORT", 16, is_valid, FALSE, DBAL_FIELD_PRINT_TYPE_UINT32, 1, FALSE));
    dbal_init_field_type_default_restrict_values(cur_field_type_param);
    SHR_IF_ERR_EXIT(dbal_db_init_field_type_add(unit, cur_field_type_param, cur_field_types_info));
exit:
    SHR_FUNC_EXIT;
}

shr_error_e
_dbal_init_shared_field_types_packet_field_types_l4_dst_port_init(
int unit,
field_type_db_struct_t * cur_field_type_param,
dbal_field_types_basic_info_t ** field_types_info)
{
    dbal_field_types_basic_info_t * cur_field_types_info = field_types_info[DBAL_FIELD_TYPE_DEF_L4_DST_PORT];
    int is_valid = TRUE;
    SHR_FUNC_INIT_VARS(unit);
    dbal_init_field_type_db_struct_clear(unit, cur_field_type_param);
    SHR_IF_ERR_EXIT(dbal_db_init_field_type_general_info_set(unit, cur_field_types_info, "L4_DST_PORT", 16, is_valid, FALSE, DBAL_FIELD_PRINT_TYPE_UINT32, 1, FALSE));
    dbal_init_field_type_default_restrict_values(cur_field_type_param);
    SHR_IF_ERR_EXIT(dbal_db_init_field_type_add(unit, cur_field_type_param, cur_field_types_info));
exit:
    SHR_FUNC_EXIT;
}

shr_error_e
_dbal_init_shared_field_types_packet_field_types_tcp_ctl_init(
int unit,
field_type_db_struct_t * cur_field_type_param,
dbal_field_types_basic_info_t ** field_types_info)
{
    dbal_field_types_basic_info_t * cur_field_types_info = field_types_info[DBAL_FIELD_TYPE_DEF_TCP_CTL];
    int is_valid = TRUE;
    SHR_FUNC_INIT_VARS(unit);
    dbal_init_field_type_db_struct_clear(unit, cur_field_type_param);
    SHR_IF_ERR_EXIT(dbal_db_init_field_type_general_info_set(unit, cur_field_types_info, "TCP_CTL", 6, is_valid, FALSE, DBAL_FIELD_PRINT_TYPE_UINT32, 1, FALSE));
    dbal_init_field_type_default_restrict_values(cur_field_type_param);
    SHR_IF_ERR_EXIT(dbal_db_init_field_type_add(unit, cur_field_type_param, cur_field_types_info));
exit:
    SHR_FUNC_EXIT;
}

shr_error_e
_dbal_init_shared_field_types_packet_field_types_next_protocol_init(
int unit,
field_type_db_struct_t * cur_field_type_param,
dbal_field_types_basic_info_t ** field_types_info)
{
    dbal_field_types_basic_info_t * cur_field_types_info = field_types_info[DBAL_FIELD_TYPE_DEF_NEXT_PROTOCOL];
    int is_valid = TRUE;
    SHR_FUNC_INIT_VARS(unit);
    dbal_init_field_type_db_struct_clear(unit, cur_field_type_param);
    SHR_IF_ERR_EXIT(dbal_db_init_field_type_general_info_set(unit, cur_field_types_info, "NEXT_PROTOCOL", 8, is_valid, FALSE, DBAL_FIELD_PRINT_TYPE_UINT32, 1, FALSE));
    sal_memset(cur_field_type_param->define, 0x0, 3 * sizeof(dbal_db_defines_info_struct_t));
    sal_strncpy(cur_field_type_param->define[0].define_name, "ICMP", sizeof(cur_field_type_param->define[0].define_name));
    cur_field_type_param->define[0].define_value = 1;
    sal_strncpy(cur_field_type_param->define[1].define_name, "IGMP", sizeof(cur_field_type_param->define[1].define_name));
    cur_field_type_param->define[1].define_value = 2;
    sal_strncpy(cur_field_type_param->define[2].define_name, "ICMPV6", sizeof(cur_field_type_param->define[2].define_name));
    cur_field_type_param->define[2].define_value = 58;
    cur_field_type_param->nof_defined_vals = 3;
    dbal_init_field_type_default_restrict_values(cur_field_type_param);
    SHR_IF_ERR_EXIT(dbal_db_init_field_type_add(unit, cur_field_type_param, cur_field_types_info));
exit:
    SHR_FUNC_EXIT;
}

shr_error_e
_dbal_init_shared_field_types_packet_field_types_vxlan_next_protocol_init(
int unit,
field_type_db_struct_t * cur_field_type_param,
dbal_field_types_basic_info_t ** field_types_info)
{
    dbal_field_types_basic_info_t * cur_field_types_info = field_types_info[DBAL_FIELD_TYPE_DEF_VXLAN_NEXT_PROTOCOL];
    int is_valid = TRUE;
    SHR_FUNC_INIT_VARS(unit);
    dbal_init_field_type_db_struct_clear(unit, cur_field_type_param);
    SHR_IF_ERR_EXIT(dbal_db_init_field_type_general_info_set(unit, cur_field_types_info, "VXLAN_NEXT_PROTOCOL", 8, is_valid, FALSE, DBAL_FIELD_PRINT_TYPE_ENUM, 1, FALSE));
    cur_field_type_param->nof_enum_vals = DBAL_ENUM_FVAL_VXLAN_NEXT_PROTOCOL_IPT + 1;
    DBAL_INIT_FIELD_TYPES_ENUMS_CLEAR(cur_field_type_param);
    {
        DBAL_INIT_FIELD_TYPES_ENUM_NAME_SET(cur_field_type_param, DBAL_ENUM_FVAL_VXLAN_NEXT_PROTOCOL_DEFAULT, "DEFAULT");
        DBAL_INIT_FIELD_TYPES_ENUM_NAME_SET(cur_field_type_param, DBAL_ENUM_FVAL_VXLAN_NEXT_PROTOCOL_IPV4, "IPV4");
        DBAL_INIT_FIELD_TYPES_ENUM_NAME_SET(cur_field_type_param, DBAL_ENUM_FVAL_VXLAN_NEXT_PROTOCOL_IPV6, "IPV6");
        DBAL_INIT_FIELD_TYPES_ENUM_NAME_SET(cur_field_type_param, DBAL_ENUM_FVAL_VXLAN_NEXT_PROTOCOL_ETHERNET, "ETHERNET");
        DBAL_INIT_FIELD_TYPES_ENUM_NAME_SET(cur_field_type_param, DBAL_ENUM_FVAL_VXLAN_NEXT_PROTOCOL_NSH, "NSH");
        DBAL_INIT_FIELD_TYPES_ENUM_NAME_SET(cur_field_type_param, DBAL_ENUM_FVAL_VXLAN_NEXT_PROTOCOL_MPLS, "MPLS");
        DBAL_INIT_FIELD_TYPES_ENUM_NAME_SET(cur_field_type_param, DBAL_ENUM_FVAL_VXLAN_NEXT_PROTOCOL_IPT, "IPT");
    }
    dbal_init_field_type_default_restrict_values(cur_field_type_param);
    {
        dbal_db_enum_info_struct_t * enum_info = cur_field_type_param->enums;
        enum_info[DBAL_ENUM_FVAL_VXLAN_NEXT_PROTOCOL_DEFAULT].value_from_mapping = 0;
        enum_info[DBAL_ENUM_FVAL_VXLAN_NEXT_PROTOCOL_IPV4].value_from_mapping = 1;
        enum_info[DBAL_ENUM_FVAL_VXLAN_NEXT_PROTOCOL_IPV6].value_from_mapping = 2;
        enum_info[DBAL_ENUM_FVAL_VXLAN_NEXT_PROTOCOL_ETHERNET].value_from_mapping = 3;
        enum_info[DBAL_ENUM_FVAL_VXLAN_NEXT_PROTOCOL_NSH].value_from_mapping = 4;
        enum_info[DBAL_ENUM_FVAL_VXLAN_NEXT_PROTOCOL_MPLS].value_from_mapping = 5;
        enum_info[DBAL_ENUM_FVAL_VXLAN_NEXT_PROTOCOL_IPT].value_from_mapping = 6;
    }
    SHR_IF_ERR_EXIT(dbal_db_init_field_type_add(unit, cur_field_type_param, cur_field_types_info));
exit:
    SHR_FUNC_EXIT;
}

shr_error_e
_dbal_init_shared_field_types_packet_field_types_ethertype_init(
int unit,
field_type_db_struct_t * cur_field_type_param,
dbal_field_types_basic_info_t ** field_types_info)
{
    dbal_field_types_basic_info_t * cur_field_types_info = field_types_info[DBAL_FIELD_TYPE_DEF_ETHERTYPE];
    int is_valid = TRUE;
    SHR_FUNC_INIT_VARS(unit);
    dbal_init_field_type_db_struct_clear(unit, cur_field_type_param);
    SHR_IF_ERR_EXIT(dbal_db_init_field_type_general_info_set(unit, cur_field_types_info, "ETHERTYPE", 16, is_valid, FALSE, DBAL_FIELD_PRINT_TYPE_UINT32, 1, FALSE));
    sal_memset(cur_field_type_param->define, 0x0, 6 * sizeof(dbal_db_defines_info_struct_t));
    sal_strncpy(cur_field_type_param->define[0].define_name, "IPV4", sizeof(cur_field_type_param->define[0].define_name));
    cur_field_type_param->define[0].define_value = 2048;
    sal_strncpy(cur_field_type_param->define[1].define_name, "MPLS", sizeof(cur_field_type_param->define[1].define_name));
    cur_field_type_param->define[1].define_value = 34887;
    sal_strncpy(cur_field_type_param->define[2].define_name, "PPP", sizeof(cur_field_type_param->define[2].define_name));
    cur_field_type_param->define[2].define_value = 34916;
    sal_strncpy(cur_field_type_param->define[3].define_name, "IPV6", sizeof(cur_field_type_param->define[3].define_name));
    cur_field_type_param->define[3].define_value = 34525;
    sal_strncpy(cur_field_type_param->define[4].define_name, "1588", sizeof(cur_field_type_param->define[4].define_name));
    cur_field_type_param->define[4].define_value = 35063;
    sal_strncpy(cur_field_type_param->define[5].define_name, "FCOE", sizeof(cur_field_type_param->define[5].define_name));
    cur_field_type_param->define[5].define_value = 35078;
    cur_field_type_param->nof_defined_vals = 6;
    dbal_init_field_type_default_restrict_values(cur_field_type_param);
    SHR_IF_ERR_EXIT(dbal_db_init_field_type_add(unit, cur_field_type_param, cur_field_types_info));
exit:
    SHR_FUNC_EXIT;
}

shr_error_e
_dbal_init_shared_field_types_packet_field_types_udp_port_init(
int unit,
field_type_db_struct_t * cur_field_type_param,
dbal_field_types_basic_info_t ** field_types_info)
{
    dbal_field_types_basic_info_t * cur_field_types_info = field_types_info[DBAL_FIELD_TYPE_DEF_UDP_PORT];
    int is_valid = TRUE;
    SHR_FUNC_INIT_VARS(unit);
    dbal_init_field_type_db_struct_clear(unit, cur_field_type_param);
    SHR_IF_ERR_EXIT(dbal_db_init_field_type_general_info_set(unit, cur_field_types_info, "UDP_PORT", 16, is_valid, FALSE, DBAL_FIELD_PRINT_TYPE_UINT32, 1, FALSE));
    sal_memset(cur_field_type_param->define, 0x0, 15 * sizeof(dbal_db_defines_info_struct_t));
    sal_strncpy(cur_field_type_param->define[0].define_name, "PTP_EVENT_MSG", sizeof(cur_field_type_param->define[0].define_name));
    cur_field_type_param->define[0].define_value = 319;
    sal_strncpy(cur_field_type_param->define[1].define_name, "PTP_GENERAL_MSG", sizeof(cur_field_type_param->define[1].define_name));
    cur_field_type_param->define[1].define_value = 320;
    sal_strncpy(cur_field_type_param->define[2].define_name, "BFD_SINGLE_HOP", sizeof(cur_field_type_param->define[2].define_name));
    cur_field_type_param->define[2].define_value = 3784;
    sal_strncpy(cur_field_type_param->define[3].define_name, "BFD_MULTI_HOP", sizeof(cur_field_type_param->define[3].define_name));
    cur_field_type_param->define[3].define_value = 4784;
    sal_strncpy(cur_field_type_param->define[4].define_name, "BFD_ECHO", sizeof(cur_field_type_param->define[4].define_name));
    cur_field_type_param->define[4].define_value = 3785;
    sal_strncpy(cur_field_type_param->define[5].define_name, "GENEVE", sizeof(cur_field_type_param->define[5].define_name));
    cur_field_type_param->define[5].define_value = 6081;
    sal_strncpy(cur_field_type_param->define[6].define_name, "IPV4", sizeof(cur_field_type_param->define[6].define_name));
    cur_field_type_param->define[6].define_value = 26117;
    sal_strncpy(cur_field_type_param->define[7].define_name, "MICROBFD", sizeof(cur_field_type_param->define[7].define_name));
    cur_field_type_param->define[7].define_value = 6784;
    sal_strncpy(cur_field_type_param->define[8].define_name, "IPV6", sizeof(cur_field_type_param->define[8].define_name));
    cur_field_type_param->define[8].define_value = 26133;
    sal_strncpy(cur_field_type_param->define[9].define_name, "L2TP", sizeof(cur_field_type_param->define[9].define_name));
    cur_field_type_param->define[9].define_value = 1701;
    sal_strncpy(cur_field_type_param->define[10].define_name, "MPLS", sizeof(cur_field_type_param->define[10].define_name));
    cur_field_type_param->define[10].define_value = 6635;
    sal_strncpy(cur_field_type_param->define[11].define_name, "ETH", sizeof(cur_field_type_param->define[11].define_name));
    cur_field_type_param->define[11].define_value = 0;
    sal_strncpy(cur_field_type_param->define[12].define_name, "VXLAN", sizeof(cur_field_type_param->define[12].define_name));
    cur_field_type_param->define[12].define_value = 4789;
    sal_strncpy(cur_field_type_param->define[13].define_name, "VXLAN_GPE", sizeof(cur_field_type_param->define[13].define_name));
    cur_field_type_param->define[13].define_value = 4790;
    sal_strncpy(cur_field_type_param->define[14].define_name, "SEAMLESS_BFD", sizeof(cur_field_type_param->define[14].define_name));
    cur_field_type_param->define[14].define_value = 7784;
    cur_field_type_param->nof_defined_vals = 15;
    dbal_init_field_type_default_restrict_values(cur_field_type_param);
    SHR_IF_ERR_EXIT(dbal_db_init_field_type_add(unit, cur_field_type_param, cur_field_types_info));
exit:
    SHR_FUNC_EXIT;
}

shr_error_e
_dbal_init_shared_field_types_packet_field_types_mpls_label_init(
int unit,
field_type_db_struct_t * cur_field_type_param,
dbal_field_types_basic_info_t ** field_types_info)
{
    dbal_field_types_basic_info_t * cur_field_types_info = field_types_info[DBAL_FIELD_TYPE_DEF_MPLS_LABEL];
    int is_valid = TRUE;
    SHR_FUNC_INIT_VARS(unit);
    dbal_init_field_type_db_struct_clear(unit, cur_field_type_param);
    SHR_IF_ERR_EXIT(dbal_db_init_field_type_general_info_set(unit, cur_field_types_info, "MPLS_LABEL", 20, is_valid, FALSE, DBAL_FIELD_PRINT_TYPE_UINT32, 1, FALSE));
    dbal_init_field_type_default_restrict_values(cur_field_type_param);
    SHR_IF_ERR_EXIT(dbal_db_init_field_type_add(unit, cur_field_type_param, cur_field_types_info));
exit:
    SHR_FUNC_EXIT;
}

shr_error_e
_dbal_init_shared_field_types_packet_field_types_bos_init(
int unit,
field_type_db_struct_t * cur_field_type_param,
dbal_field_types_basic_info_t ** field_types_info)
{
    dbal_field_types_basic_info_t * cur_field_types_info = field_types_info[DBAL_FIELD_TYPE_DEF_BOS];
    int is_valid = TRUE;
    SHR_FUNC_INIT_VARS(unit);
    dbal_init_field_type_db_struct_clear(unit, cur_field_type_param);
    SHR_IF_ERR_EXIT(dbal_db_init_field_type_general_info_set(unit, cur_field_types_info, "BOS", 1, is_valid, FALSE, DBAL_FIELD_PRINT_TYPE_BOOL, 1, FALSE));
    dbal_init_field_type_default_restrict_values(cur_field_type_param);
    SHR_IF_ERR_EXIT(dbal_db_init_field_type_add(unit, cur_field_type_param, cur_field_types_info));
exit:
    SHR_FUNC_EXIT;
}

shr_error_e
_dbal_init_shared_field_types_packet_field_types_mpls_header_init(
int unit,
field_type_db_struct_t * cur_field_type_param,
dbal_field_types_basic_info_t ** field_types_info)
{
    dbal_field_types_basic_info_t * cur_field_types_info = field_types_info[DBAL_FIELD_TYPE_DEF_MPLS_HEADER];
    int is_valid = TRUE;
    SHR_FUNC_INIT_VARS(unit);
    dbal_init_field_type_db_struct_clear(unit, cur_field_type_param);
    SHR_IF_ERR_EXIT(dbal_db_init_field_type_general_info_set(unit, cur_field_types_info, "MPLS_HEADER", 32, is_valid, FALSE, DBAL_FIELD_PRINT_TYPE_STRUCTURE, 1, FALSE));
    cur_field_types_info->nof_struct_fields = 4;
    SHR_IF_ERR_EXIT(dbal_db_init_field_type_struct_alloc(unit, cur_field_types_info));
    cur_field_types_info->struct_field_info[0].struct_field_id = DBAL_FIELD_TTL;
    cur_field_types_info->struct_field_info[0].length = 8;
    cur_field_types_info->struct_field_info[1].struct_field_id = DBAL_FIELD_BOS;
    cur_field_types_info->struct_field_info[1].length = 1;
    cur_field_types_info->struct_field_info[2].struct_field_id = DBAL_FIELD_EXP;
    cur_field_types_info->struct_field_info[3].struct_field_id = DBAL_FIELD_MPLS_LABEL;
    cur_field_types_info->struct_field_info[3].length = 20;
    dbal_init_field_type_default_restrict_values(cur_field_type_param);
    SHR_IF_ERR_EXIT(dbal_db_init_field_type_add(unit, cur_field_type_param, cur_field_types_info));
exit:
    SHR_FUNC_EXIT;
}

shr_error_e
_dbal_init_shared_field_types_packet_field_types_rch_time_stamp_init(
int unit,
field_type_db_struct_t * cur_field_type_param,
dbal_field_types_basic_info_t ** field_types_info)
{
    dbal_field_types_basic_info_t * cur_field_types_info = field_types_info[DBAL_FIELD_TYPE_DEF_RCH_TIME_STAMP];
    int is_valid = TRUE;
    SHR_FUNC_INIT_VARS(unit);
    dbal_init_field_type_db_struct_clear(unit, cur_field_type_param);
    SHR_IF_ERR_EXIT(dbal_db_init_field_type_general_info_set(unit, cur_field_types_info, "RCH_TIME_STAMP", 1, is_valid, FALSE, DBAL_FIELD_PRINT_TYPE_BOOL, 1, FALSE));
    dbal_init_field_type_default_restrict_values(cur_field_type_param);
    SHR_IF_ERR_EXIT(dbal_db_init_field_type_add(unit, cur_field_type_param, cur_field_types_info));
exit:
    SHR_FUNC_EXIT;
}

shr_error_e
_dbal_init_shared_field_types_packet_field_types_rch_forwarding_additional_info_init(
int unit,
field_type_db_struct_t * cur_field_type_param,
dbal_field_types_basic_info_t ** field_types_info)
{
    dbal_field_types_basic_info_t * cur_field_types_info = field_types_info[DBAL_FIELD_TYPE_DEF_RCH_FORWARDING_ADDITIONAL_INFO];
    int is_valid = TRUE;
    SHR_FUNC_INIT_VARS(unit);
    dbal_init_field_type_db_struct_clear(unit, cur_field_type_param);
    SHR_IF_ERR_EXIT(dbal_db_init_field_type_general_info_set(unit, cur_field_types_info, "RCH_FORWARDING_ADDITIONAL_INFO", 4, is_valid, FALSE, DBAL_FIELD_PRINT_TYPE_UINT32, 1, FALSE));
    dbal_init_field_type_default_restrict_values(cur_field_type_param);
    SHR_IF_ERR_EXIT(dbal_db_init_field_type_add(unit, cur_field_type_param, cur_field_types_info));
exit:
    SHR_FUNC_EXIT;
}

shr_error_e
_dbal_init_shared_field_types_packet_field_types_rch_visibility_init(
int unit,
field_type_db_struct_t * cur_field_type_param,
dbal_field_types_basic_info_t ** field_types_info)
{
    dbal_field_types_basic_info_t * cur_field_types_info = field_types_info[DBAL_FIELD_TYPE_DEF_RCH_VISIBILITY];
    int is_valid = TRUE;
    SHR_FUNC_INIT_VARS(unit);
    dbal_init_field_type_db_struct_clear(unit, cur_field_type_param);
    SHR_IF_ERR_EXIT(dbal_db_init_field_type_general_info_set(unit, cur_field_types_info, "RCH_VISIBILITY", 1, is_valid, FALSE, DBAL_FIELD_PRINT_TYPE_BOOL, 1, FALSE));
    dbal_init_field_type_default_restrict_values(cur_field_type_param);
    SHR_IF_ERR_EXIT(dbal_db_init_field_type_add(unit, cur_field_type_param, cur_field_types_info));
exit:
    SHR_FUNC_EXIT;
}

shr_error_e
_dbal_init_shared_field_types_packet_field_types_gach_indication_init(
int unit,
field_type_db_struct_t * cur_field_type_param,
dbal_field_types_basic_info_t ** field_types_info)
{
    dbal_field_types_basic_info_t * cur_field_types_info = field_types_info[DBAL_FIELD_TYPE_DEF_GACH_INDICATION];
    int is_valid = TRUE;
    SHR_FUNC_INIT_VARS(unit);
    dbal_init_field_type_db_struct_clear(unit, cur_field_type_param);
    SHR_IF_ERR_EXIT(dbal_db_init_field_type_general_info_set(unit, cur_field_types_info, "GACH_INDICATION", 4, is_valid, FALSE, DBAL_FIELD_PRINT_TYPE_UINT32, 1, FALSE));
    dbal_init_field_type_default_restrict_values(cur_field_type_param);
    SHR_IF_ERR_EXIT(dbal_db_init_field_type_add(unit, cur_field_type_param, cur_field_types_info));
exit:
    SHR_FUNC_EXIT;
}

shr_error_e
_dbal_init_shared_field_types_packet_field_types_ach_ver_init(
int unit,
field_type_db_struct_t * cur_field_type_param,
dbal_field_types_basic_info_t ** field_types_info)
{
    dbal_field_types_basic_info_t * cur_field_types_info = field_types_info[DBAL_FIELD_TYPE_DEF_ACH_VER];
    int is_valid = TRUE;
    SHR_FUNC_INIT_VARS(unit);
    dbal_init_field_type_db_struct_clear(unit, cur_field_type_param);
    SHR_IF_ERR_EXIT(dbal_db_init_field_type_general_info_set(unit, cur_field_types_info, "ACH_VER", 4, is_valid, FALSE, DBAL_FIELD_PRINT_TYPE_UINT32, 1, FALSE));
    dbal_init_field_type_default_restrict_values(cur_field_type_param);
    SHR_IF_ERR_EXIT(dbal_db_init_field_type_add(unit, cur_field_type_param, cur_field_types_info));
exit:
    SHR_FUNC_EXIT;
}

shr_error_e
_dbal_init_shared_field_types_packet_field_types_ach_header_init(
int unit,
field_type_db_struct_t * cur_field_type_param,
dbal_field_types_basic_info_t ** field_types_info)
{
    dbal_field_types_basic_info_t * cur_field_types_info = field_types_info[DBAL_FIELD_TYPE_DEF_ACH_HEADER];
    int is_valid = TRUE;
    SHR_FUNC_INIT_VARS(unit);
    dbal_init_field_type_db_struct_clear(unit, cur_field_type_param);
    SHR_IF_ERR_EXIT(dbal_db_init_field_type_general_info_set(unit, cur_field_types_info, "ACH_HEADER", 32, is_valid, FALSE, DBAL_FIELD_PRINT_TYPE_STRUCTURE, 1, FALSE));
    cur_field_types_info->nof_struct_fields = 4;
    SHR_IF_ERR_EXIT(dbal_db_init_field_type_struct_alloc(unit, cur_field_types_info));
    cur_field_types_info->struct_field_info[0].struct_field_id = DBAL_FIELD_CHANNEL_TYPE;
    cur_field_types_info->struct_field_info[0].length = 16;
    cur_field_types_info->struct_field_info[1].struct_field_id = DBAL_FIELD_RESERVED;
    cur_field_types_info->struct_field_info[1].length = 8;
    cur_field_types_info->struct_field_info[2].struct_field_id = DBAL_FIELD_ACH_VER;
    cur_field_types_info->struct_field_info[2].length = 4;
    cur_field_types_info->struct_field_info[3].struct_field_id = DBAL_FIELD_GACH_INDICATION;
    cur_field_types_info->struct_field_info[3].length = 4;
    dbal_init_field_type_default_restrict_values(cur_field_type_param);
    SHR_IF_ERR_EXIT(dbal_db_init_field_type_add(unit, cur_field_type_param, cur_field_types_info));
exit:
    SHR_FUNC_EXIT;
}

shr_error_e
_dbal_init_shared_field_types_packet_field_types_channel_type_init(
int unit,
field_type_db_struct_t * cur_field_type_param,
dbal_field_types_basic_info_t ** field_types_info)
{
    dbal_field_types_basic_info_t * cur_field_types_info = field_types_info[DBAL_FIELD_TYPE_DEF_CHANNEL_TYPE];
    int is_valid = TRUE;
    SHR_FUNC_INIT_VARS(unit);
    dbal_init_field_type_db_struct_clear(unit, cur_field_type_param);
    SHR_IF_ERR_EXIT(dbal_db_init_field_type_general_info_set(unit, cur_field_types_info, "CHANNEL_TYPE", 16, is_valid, FALSE, DBAL_FIELD_PRINT_TYPE_UINT32, 1, FALSE));
    dbal_init_field_type_default_restrict_values(cur_field_type_param);
    SHR_IF_ERR_EXIT(dbal_db_init_field_type_add(unit, cur_field_type_param, cur_field_types_info));
exit:
    SHR_FUNC_EXIT;
}

shr_error_e
_dbal_init_shared_field_types_packet_field_types_tpid_init(
int unit,
field_type_db_struct_t * cur_field_type_param,
dbal_field_types_basic_info_t ** field_types_info)
{
    dbal_field_types_basic_info_t * cur_field_types_info = field_types_info[DBAL_FIELD_TYPE_DEF_TPID];
    int is_valid = TRUE;
    SHR_FUNC_INIT_VARS(unit);
    dbal_init_field_type_db_struct_clear(unit, cur_field_type_param);
    SHR_IF_ERR_EXIT(dbal_db_init_field_type_general_info_set(unit, cur_field_types_info, "TPID", 16, is_valid, FALSE, DBAL_FIELD_PRINT_TYPE_UINT32, 1, FALSE));
    sal_memset(cur_field_type_param->define, 0x0, 2 * sizeof(dbal_db_defines_info_struct_t));
    sal_strncpy(cur_field_type_param->define[0].define_name, "DOT1BR", sizeof(cur_field_type_param->define[0].define_name));
    cur_field_type_param->define[0].define_value = 35135;
    sal_strncpy(cur_field_type_param->define[1].define_name, "MIM", sizeof(cur_field_type_param->define[1].define_name));
    cur_field_type_param->define[1].define_value = 35047;
    cur_field_type_param->nof_defined_vals = 2;
    dbal_init_field_type_default_restrict_values(cur_field_type_param);
    SHR_IF_ERR_EXIT(dbal_db_init_field_type_add(unit, cur_field_type_param, cur_field_types_info));
exit:
    SHR_FUNC_EXIT;
}

shr_error_e
_dbal_init_shared_field_types_packet_field_types_tni_init(
int unit,
field_type_db_struct_t * cur_field_type_param,
dbal_field_types_basic_info_t ** field_types_info)
{
    dbal_field_types_basic_info_t * cur_field_types_info = field_types_info[DBAL_FIELD_TYPE_DEF_TNI];
    int is_valid = TRUE;
    SHR_FUNC_INIT_VARS(unit);
    dbal_init_field_type_db_struct_clear(unit, cur_field_type_param);
    SHR_IF_ERR_EXIT(dbal_db_init_field_type_general_info_set(unit, cur_field_types_info, "TNI", 24, is_valid, FALSE, DBAL_FIELD_PRINT_TYPE_UINT32, 1, FALSE));
    dbal_init_field_type_default_restrict_values(cur_field_type_param);
    SHR_IF_ERR_EXIT(dbal_db_init_field_type_add(unit, cur_field_type_param, cur_field_types_info));
exit:
    SHR_FUNC_EXIT;
}

shr_error_e
_dbal_init_shared_field_types_packet_field_types_exp_init(
int unit,
field_type_db_struct_t * cur_field_type_param,
dbal_field_types_basic_info_t ** field_types_info)
{
    dbal_field_types_basic_info_t * cur_field_types_info = field_types_info[DBAL_FIELD_TYPE_DEF_EXP];
    int is_valid = TRUE;
    SHR_FUNC_INIT_VARS(unit);
    dbal_init_field_type_db_struct_clear(unit, cur_field_type_param);
    SHR_IF_ERR_EXIT(dbal_db_init_field_type_general_info_set(unit, cur_field_types_info, "EXP", 3, is_valid, FALSE, DBAL_FIELD_PRINT_TYPE_UINT32, 1, FALSE));
    dbal_init_field_type_default_restrict_values(cur_field_type_param);
    SHR_IF_ERR_EXIT(dbal_db_init_field_type_add(unit, cur_field_type_param, cur_field_types_info));
exit:
    SHR_FUNC_EXIT;
}

shr_error_e
_dbal_init_shared_field_types_packet_field_types_vlan_id_init(
int unit,
field_type_db_struct_t * cur_field_type_param,
dbal_field_types_basic_info_t ** field_types_info)
{
    dbal_field_types_basic_info_t * cur_field_types_info = field_types_info[DBAL_FIELD_TYPE_DEF_VLAN_ID];
    int is_valid = TRUE;
    SHR_FUNC_INIT_VARS(unit);
    dbal_init_field_type_db_struct_clear(unit, cur_field_type_param);
    SHR_IF_ERR_EXIT(dbal_db_init_field_type_general_info_set(unit, cur_field_types_info, "VLAN_ID", 12, is_valid, FALSE, DBAL_FIELD_PRINT_TYPE_UINT32, 1, FALSE));
    dbal_init_field_type_default_restrict_values(cur_field_type_param);
    SHR_IF_ERR_EXIT(dbal_db_init_field_type_add(unit, cur_field_type_param, cur_field_types_info));
exit:
    SHR_FUNC_EXIT;
}

shr_error_e
_dbal_init_shared_field_types_packet_field_types_vni_init(
int unit,
field_type_db_struct_t * cur_field_type_param,
dbal_field_types_basic_info_t ** field_types_info)
{
    dbal_field_types_basic_info_t * cur_field_types_info = field_types_info[DBAL_FIELD_TYPE_DEF_VNI];
    int is_valid = TRUE;
    SHR_FUNC_INIT_VARS(unit);
    dbal_init_field_type_db_struct_clear(unit, cur_field_type_param);
    SHR_IF_ERR_EXIT(dbal_db_init_field_type_general_info_set(unit, cur_field_types_info, "VNI", 24, is_valid, FALSE, DBAL_FIELD_PRINT_TYPE_UINT32, 1, FALSE));
    dbal_init_field_type_default_restrict_values(cur_field_type_param);
    SHR_IF_ERR_EXIT(dbal_db_init_field_type_add(unit, cur_field_type_param, cur_field_types_info));
exit:
    SHR_FUNC_EXIT;
}

shr_error_e
_dbal_init_shared_field_types_packet_field_types_bier_mpls_init(
int unit,
field_type_db_struct_t * cur_field_type_param,
dbal_field_types_basic_info_t ** field_types_info)
{
    dbal_field_types_basic_info_t * cur_field_types_info = field_types_info[DBAL_FIELD_TYPE_DEF_BIER_MPLS];
    int is_valid = TRUE;
    SHR_FUNC_INIT_VARS(unit);
    dbal_init_field_type_db_struct_clear(unit, cur_field_type_param);
    SHR_IF_ERR_EXIT(dbal_db_init_field_type_general_info_set(unit, cur_field_types_info, "BIER_MPLS", 10, is_valid, FALSE, DBAL_FIELD_PRINT_TYPE_UINT32, 1, FALSE));
    dbal_init_field_type_default_restrict_values(cur_field_type_param);
    SHR_IF_ERR_EXIT(dbal_db_init_field_type_add(unit, cur_field_type_param, cur_field_types_info));
exit:
    SHR_FUNC_EXIT;
}

shr_error_e
_dbal_init_shared_field_types_packet_field_types_ipv4_flags_init(
int unit,
field_type_db_struct_t * cur_field_type_param,
dbal_field_types_basic_info_t ** field_types_info)
{
    dbal_field_types_basic_info_t * cur_field_types_info = field_types_info[DBAL_FIELD_TYPE_DEF_IPV4_FLAGS];
    int is_valid = TRUE;
    SHR_FUNC_INIT_VARS(unit);
    dbal_init_field_type_db_struct_clear(unit, cur_field_type_param);
    SHR_IF_ERR_EXIT(dbal_db_init_field_type_general_info_set(unit, cur_field_types_info, "IPV4_FLAGS", 3, is_valid, FALSE, DBAL_FIELD_PRINT_TYPE_UINT32, 1, FALSE));
    dbal_init_field_type_default_restrict_values(cur_field_type_param);
    SHR_IF_ERR_EXIT(dbal_db_init_field_type_add(unit, cur_field_type_param, cur_field_types_info));
exit:
    SHR_FUNC_EXIT;
}

shr_error_e
_dbal_init_shared_field_types_packet_field_types_ttl_init(
int unit,
field_type_db_struct_t * cur_field_type_param,
dbal_field_types_basic_info_t ** field_types_info)
{
    dbal_field_types_basic_info_t * cur_field_types_info = field_types_info[DBAL_FIELD_TYPE_DEF_TTL];
    int is_valid = TRUE;
    SHR_FUNC_INIT_VARS(unit);
    dbal_init_field_type_db_struct_clear(unit, cur_field_type_param);
    SHR_IF_ERR_EXIT(dbal_db_init_field_type_general_info_set(unit, cur_field_types_info, "TTL", 8, is_valid, FALSE, DBAL_FIELD_PRINT_TYPE_UINT32, 1, FALSE));
    dbal_init_field_type_default_restrict_values(cur_field_type_param);
    SHR_IF_ERR_EXIT(dbal_db_init_field_type_add(unit, cur_field_type_param, cur_field_types_info));
exit:
    SHR_FUNC_EXIT;
}

shr_error_e
_dbal_init_shared_field_types_packet_field_types_srh_segment_left_init(
int unit,
field_type_db_struct_t * cur_field_type_param,
dbal_field_types_basic_info_t ** field_types_info)
{
    dbal_field_types_basic_info_t * cur_field_types_info = field_types_info[DBAL_FIELD_TYPE_DEF_SRH_SEGMENT_LEFT];
    int is_valid = TRUE;
    SHR_FUNC_INIT_VARS(unit);
    dbal_init_field_type_db_struct_clear(unit, cur_field_type_param);
    SHR_IF_ERR_EXIT(dbal_db_init_field_type_general_info_set(unit, cur_field_types_info, "SRH_SEGMENT_LEFT", 8, is_valid, FALSE, DBAL_FIELD_PRINT_TYPE_UINT32, 1, FALSE));
    dbal_init_field_type_default_restrict_values(cur_field_type_param);
    SHR_IF_ERR_EXIT(dbal_db_init_field_type_add(unit, cur_field_type_param, cur_field_types_info));
exit:
    SHR_FUNC_EXIT;
}

shr_error_e
_dbal_init_shared_field_types_packet_field_types_srh_last_entry_init(
int unit,
field_type_db_struct_t * cur_field_type_param,
dbal_field_types_basic_info_t ** field_types_info)
{
    dbal_field_types_basic_info_t * cur_field_types_info = field_types_info[DBAL_FIELD_TYPE_DEF_SRH_LAST_ENTRY];
    int is_valid = TRUE;
    SHR_FUNC_INIT_VARS(unit);
    dbal_init_field_type_db_struct_clear(unit, cur_field_type_param);
    SHR_IF_ERR_EXIT(dbal_db_init_field_type_general_info_set(unit, cur_field_types_info, "SRH_LAST_ENTRY", 8, is_valid, FALSE, DBAL_FIELD_PRINT_TYPE_UINT32, 1, FALSE));
    dbal_init_field_type_default_restrict_values(cur_field_type_param);
    SHR_IF_ERR_EXIT(dbal_db_init_field_type_add(unit, cur_field_type_param, cur_field_types_info));
exit:
    SHR_FUNC_EXIT;
}

shr_error_e
_dbal_init_shared_field_types_packet_field_types_srh_flags_init(
int unit,
field_type_db_struct_t * cur_field_type_param,
dbal_field_types_basic_info_t ** field_types_info)
{
    dbal_field_types_basic_info_t * cur_field_types_info = field_types_info[DBAL_FIELD_TYPE_DEF_SRH_FLAGS];
    int is_valid = TRUE;
    SHR_FUNC_INIT_VARS(unit);
    dbal_init_field_type_db_struct_clear(unit, cur_field_type_param);
    SHR_IF_ERR_EXIT(dbal_db_init_field_type_general_info_set(unit, cur_field_types_info, "SRH_FLAGS", 8, is_valid, FALSE, DBAL_FIELD_PRINT_TYPE_UINT32, 1, FALSE));
    dbal_init_field_type_default_restrict_values(cur_field_type_param);
    SHR_IF_ERR_EXIT(dbal_db_init_field_type_add(unit, cur_field_type_param, cur_field_types_info));
exit:
    SHR_FUNC_EXIT;
}

shr_error_e
_dbal_init_shared_field_types_packet_field_types_srh_tag_init(
int unit,
field_type_db_struct_t * cur_field_type_param,
dbal_field_types_basic_info_t ** field_types_info)
{
    dbal_field_types_basic_info_t * cur_field_types_info = field_types_info[DBAL_FIELD_TYPE_DEF_SRH_TAG];
    int is_valid = TRUE;
    SHR_FUNC_INIT_VARS(unit);
    dbal_init_field_type_db_struct_clear(unit, cur_field_type_param);
    SHR_IF_ERR_EXIT(dbal_db_init_field_type_general_info_set(unit, cur_field_types_info, "SRH_TAG", 16, is_valid, FALSE, DBAL_FIELD_PRINT_TYPE_UINT32, 1, FALSE));
    dbal_init_field_type_default_restrict_values(cur_field_type_param);
    SHR_IF_ERR_EXIT(dbal_db_init_field_type_add(unit, cur_field_type_param, cur_field_types_info));
exit:
    SHR_FUNC_EXIT;
}

shr_error_e
_dbal_init_shared_field_types_packet_field_types_srh_header_ext_length_init(
int unit,
field_type_db_struct_t * cur_field_type_param,
dbal_field_types_basic_info_t ** field_types_info)
{
    dbal_field_types_basic_info_t * cur_field_types_info = field_types_info[DBAL_FIELD_TYPE_DEF_SRH_HEADER_EXT_LENGTH];
    int is_valid = TRUE;
    SHR_FUNC_INIT_VARS(unit);
    dbal_init_field_type_db_struct_clear(unit, cur_field_type_param);
    SHR_IF_ERR_EXIT(dbal_db_init_field_type_general_info_set(unit, cur_field_types_info, "SRH_HEADER_EXT_LENGTH", 8, is_valid, FALSE, DBAL_FIELD_PRINT_TYPE_UINT32, 1, FALSE));
    dbal_init_field_type_default_restrict_values(cur_field_type_param);
    SHR_IF_ERR_EXIT(dbal_db_init_field_type_add(unit, cur_field_type_param, cur_field_types_info));
exit:
    SHR_FUNC_EXIT;
}

shr_error_e
_dbal_init_shared_field_types_packet_field_types_srh_routing_type_init(
int unit,
field_type_db_struct_t * cur_field_type_param,
dbal_field_types_basic_info_t ** field_types_info)
{
    dbal_field_types_basic_info_t * cur_field_types_info = field_types_info[DBAL_FIELD_TYPE_DEF_SRH_ROUTING_TYPE];
    int is_valid = TRUE;
    SHR_FUNC_INIT_VARS(unit);
    dbal_init_field_type_db_struct_clear(unit, cur_field_type_param);
    SHR_IF_ERR_EXIT(dbal_db_init_field_type_general_info_set(unit, cur_field_types_info, "SRH_ROUTING_TYPE", 8, is_valid, FALSE, DBAL_FIELD_PRINT_TYPE_UINT32, 1, FALSE));
    dbal_init_field_type_default_restrict_values(cur_field_type_param);
    SHR_IF_ERR_EXIT(dbal_db_init_field_type_add(unit, cur_field_type_param, cur_field_types_info));
exit:
    SHR_FUNC_EXIT;
}

shr_error_e
_dbal_init_shared_field_types_packet_field_types_fih_type_init(
int unit,
field_type_db_struct_t * cur_field_type_param,
dbal_field_types_basic_info_t ** field_types_info)
{
    dbal_field_types_basic_info_t * cur_field_types_info = field_types_info[DBAL_FIELD_TYPE_DEF_FIH_TYPE];
    int is_valid = TRUE;
    SHR_FUNC_INIT_VARS(unit);
    dbal_init_field_type_db_struct_clear(unit, cur_field_type_param);
    SHR_IF_ERR_EXIT(dbal_db_init_field_type_general_info_set(unit, cur_field_types_info, "FIH_TYPE", 2, is_valid, FALSE, DBAL_FIELD_PRINT_TYPE_UINT32, 1, FALSE));
    dbal_init_field_type_default_restrict_values(cur_field_type_param);
    SHR_IF_ERR_EXIT(dbal_db_init_field_type_add(unit, cur_field_type_param, cur_field_types_info));
exit:
    SHR_FUNC_EXIT;
}

shr_error_e
_dbal_init_shared_field_types_packet_field_types_fii_tc_init(
int unit,
field_type_db_struct_t * cur_field_type_param,
dbal_field_types_basic_info_t ** field_types_info)
{
    dbal_field_types_basic_info_t * cur_field_types_info = field_types_info[DBAL_FIELD_TYPE_DEF_FII_TC];
    int is_valid = TRUE;
    SHR_FUNC_INIT_VARS(unit);
    dbal_init_field_type_db_struct_clear(unit, cur_field_type_param);
    SHR_IF_ERR_EXIT(dbal_db_init_field_type_general_info_set(unit, cur_field_types_info, "FII_TC", 3, is_valid, FALSE, DBAL_FIELD_PRINT_TYPE_UINT32, 1, FALSE));
    dbal_init_field_type_default_restrict_values(cur_field_type_param);
    SHR_IF_ERR_EXIT(dbal_db_init_field_type_add(unit, cur_field_type_param, cur_field_types_info));
exit:
    SHR_FUNC_EXIT;
}

shr_error_e
_dbal_init_shared_field_types_packet_field_types_fii_bos_init(
int unit,
field_type_db_struct_t * cur_field_type_param,
dbal_field_types_basic_info_t ** field_types_info)
{
    dbal_field_types_basic_info_t * cur_field_types_info = field_types_info[DBAL_FIELD_TYPE_DEF_FII_BOS];
    int is_valid = TRUE;
    SHR_FUNC_INIT_VARS(unit);
    dbal_init_field_type_db_struct_clear(unit, cur_field_type_param);
    SHR_IF_ERR_EXIT(dbal_db_init_field_type_general_info_set(unit, cur_field_types_info, "FII_BOS", 3, is_valid, FALSE, DBAL_FIELD_PRINT_TYPE_UINT32, 1, FALSE));
    dbal_init_field_type_default_restrict_values(cur_field_type_param);
    SHR_IF_ERR_EXIT(dbal_db_init_field_type_add(unit, cur_field_type_param, cur_field_types_info));
exit:
    SHR_FUNC_EXIT;
}

shr_error_e
_dbal_init_shared_field_types_packet_field_types_fii_ttl_init(
int unit,
field_type_db_struct_t * cur_field_type_param,
dbal_field_types_basic_info_t ** field_types_info)
{
    dbal_field_types_basic_info_t * cur_field_types_info = field_types_info[DBAL_FIELD_TYPE_DEF_FII_TTL];
    int is_valid = TRUE;
    SHR_FUNC_INIT_VARS(unit);
    dbal_init_field_type_db_struct_clear(unit, cur_field_type_param);
    SHR_IF_ERR_EXIT(dbal_db_init_field_type_general_info_set(unit, cur_field_types_info, "FII_TTL", 8, is_valid, FALSE, DBAL_FIELD_PRINT_TYPE_UINT32, 1, FALSE));
    dbal_init_field_type_default_restrict_values(cur_field_type_param);
    SHR_IF_ERR_EXIT(dbal_db_init_field_type_add(unit, cur_field_type_param, cur_field_types_info));
exit:
    SHR_FUNC_EXIT;
}

shr_error_e
_dbal_init_shared_field_types_packet_field_types_hdr_length_init(
int unit,
field_type_db_struct_t * cur_field_type_param,
dbal_field_types_basic_info_t ** field_types_info)
{
    dbal_field_types_basic_info_t * cur_field_types_info = field_types_info[DBAL_FIELD_TYPE_DEF_HDR_LENGTH];
    int is_valid = TRUE;
    SHR_FUNC_INIT_VARS(unit);
    dbal_init_field_type_db_struct_clear(unit, cur_field_type_param);
    SHR_IF_ERR_EXIT(dbal_db_init_field_type_general_info_set(unit, cur_field_types_info, "HDR_LENGTH", 8, is_valid, FALSE, DBAL_FIELD_PRINT_TYPE_UINT32, 1, FALSE));
    dbal_init_field_type_default_restrict_values(cur_field_type_param);
    SHR_IF_ERR_EXIT(dbal_db_init_field_type_add(unit, cur_field_type_param, cur_field_types_info));
exit:
    SHR_FUNC_EXIT;
}

shr_error_e
_dbal_init_shared_field_types_packet_field_types_dest_opt_type_init(
int unit,
field_type_db_struct_t * cur_field_type_param,
dbal_field_types_basic_info_t ** field_types_info)
{
    dbal_field_types_basic_info_t * cur_field_types_info = field_types_info[DBAL_FIELD_TYPE_DEF_DEST_OPT_TYPE];
    int is_valid = TRUE;
    SHR_FUNC_INIT_VARS(unit);
    dbal_init_field_type_db_struct_clear(unit, cur_field_type_param);
    SHR_IF_ERR_EXIT(dbal_db_init_field_type_general_info_set(unit, cur_field_types_info, "DEST_OPT_TYPE", 8, is_valid, FALSE, DBAL_FIELD_PRINT_TYPE_UINT32, 1, FALSE));
    dbal_init_field_type_default_restrict_values(cur_field_type_param);
    SHR_IF_ERR_EXIT(dbal_db_init_field_type_add(unit, cur_field_type_param, cur_field_types_info));
exit:
    SHR_FUNC_EXIT;
}

shr_error_e
_dbal_init_shared_field_types_packet_field_types_dest_opt_length_init(
int unit,
field_type_db_struct_t * cur_field_type_param,
dbal_field_types_basic_info_t ** field_types_info)
{
    dbal_field_types_basic_info_t * cur_field_types_info = field_types_info[DBAL_FIELD_TYPE_DEF_DEST_OPT_LENGTH];
    int is_valid = TRUE;
    SHR_FUNC_INIT_VARS(unit);
    dbal_init_field_type_db_struct_clear(unit, cur_field_type_param);
    SHR_IF_ERR_EXIT(dbal_db_init_field_type_general_info_set(unit, cur_field_types_info, "DEST_OPT_LENGTH", 8, is_valid, FALSE, DBAL_FIELD_PRINT_TYPE_UINT32, 1, FALSE));
    dbal_init_field_type_default_restrict_values(cur_field_type_param);
    SHR_IF_ERR_EXIT(dbal_db_init_field_type_add(unit, cur_field_type_param, cur_field_types_info));
exit:
    SHR_FUNC_EXIT;
}

shr_error_e
_dbal_init_shared_field_types_packet_field_types_flow_id_basic_init(
int unit,
field_type_db_struct_t * cur_field_type_param,
dbal_field_types_basic_info_t ** field_types_info)
{
    dbal_field_types_basic_info_t * cur_field_types_info = field_types_info[DBAL_FIELD_TYPE_DEF_FLOW_ID_BASIC];
    int is_valid = TRUE;
    SHR_FUNC_INIT_VARS(unit);
    dbal_init_field_type_db_struct_clear(unit, cur_field_type_param);
    SHR_IF_ERR_EXIT(dbal_db_init_field_type_general_info_set(unit, cur_field_types_info, "FLOW_ID_BASIC", 32, is_valid, FALSE, DBAL_FIELD_PRINT_TYPE_UINT32, 1, FALSE));
    dbal_init_field_type_default_restrict_values(cur_field_type_param);
    SHR_IF_ERR_EXIT(dbal_db_init_field_type_add(unit, cur_field_type_param, cur_field_types_info));
exit:
    SHR_FUNC_EXIT;
}

shr_error_e
_dbal_init_shared_field_types_packet_field_types_flow_id_ext_init(
int unit,
field_type_db_struct_t * cur_field_type_param,
dbal_field_types_basic_info_t ** field_types_info)
{
    dbal_field_types_basic_info_t * cur_field_types_info = field_types_info[DBAL_FIELD_TYPE_DEF_FLOW_ID_EXT];
    int is_valid = TRUE;
    SHR_FUNC_INIT_VARS(unit);
    dbal_init_field_type_db_struct_clear(unit, cur_field_type_param);
    SHR_IF_ERR_EXIT(dbal_db_init_field_type_general_info_set(unit, cur_field_types_info, "FLOW_ID_EXT", 32, is_valid, FALSE, DBAL_FIELD_PRINT_TYPE_UINT32, 1, FALSE));
    dbal_init_field_type_default_restrict_values(cur_field_type_param);
    SHR_IF_ERR_EXIT(dbal_db_init_field_type_add(unit, cur_field_type_param, cur_field_types_info));
exit:
    SHR_FUNC_EXIT;
}

shr_error_e
_dbal_init_shared_field_types_packet_field_types_dip_mask_init(
int unit,
field_type_db_struct_t * cur_field_type_param,
dbal_field_types_basic_info_t ** field_types_info)
{
    dbal_field_types_basic_info_t * cur_field_types_info = field_types_info[DBAL_FIELD_TYPE_DEF_DIP_MASK];
    int is_valid = TRUE;
    SHR_FUNC_INIT_VARS(unit);
    dbal_init_field_type_db_struct_clear(unit, cur_field_type_param);
    SHR_IF_ERR_EXIT(dbal_db_init_field_type_general_info_set(unit, cur_field_types_info, "DIP_MASK", 8, is_valid, FALSE, DBAL_FIELD_PRINT_TYPE_UINT32, 1, FALSE));
    dbal_init_field_type_default_restrict_values(cur_field_type_param);
    SHR_IF_ERR_EXIT(dbal_db_init_field_type_add(unit, cur_field_type_param, cur_field_types_info));
exit:
    SHR_FUNC_EXIT;
}

shr_error_e
_dbal_init_shared_field_types_packet_field_types_sip_mask_init(
int unit,
field_type_db_struct_t * cur_field_type_param,
dbal_field_types_basic_info_t ** field_types_info)
{
    dbal_field_types_basic_info_t * cur_field_types_info = field_types_info[DBAL_FIELD_TYPE_DEF_SIP_MASK];
    int is_valid = TRUE;
    SHR_FUNC_INIT_VARS(unit);
    dbal_init_field_type_db_struct_clear(unit, cur_field_type_param);
    SHR_IF_ERR_EXIT(dbal_db_init_field_type_general_info_set(unit, cur_field_types_info, "SIP_MASK", 8, is_valid, FALSE, DBAL_FIELD_PRINT_TYPE_UINT32, 1, FALSE));
    dbal_init_field_type_default_restrict_values(cur_field_type_param);
    SHR_IF_ERR_EXIT(dbal_db_init_field_type_add(unit, cur_field_type_param, cur_field_types_info));
exit:
    SHR_FUNC_EXIT;
}

shr_error_e
_dbal_init_shared_field_types_packet_field_types_fieh_ext_data_init(
int unit,
field_type_db_struct_t * cur_field_type_param,
dbal_field_types_basic_info_t ** field_types_info)
{
    dbal_field_types_basic_info_t * cur_field_types_info = field_types_info[DBAL_FIELD_TYPE_DEF_FIEH_EXT_DATA];
    int is_valid = TRUE;
    SHR_FUNC_INIT_VARS(unit);
    dbal_init_field_type_db_struct_clear(unit, cur_field_type_param);
    SHR_IF_ERR_EXIT(dbal_db_init_field_type_general_info_set(unit, cur_field_types_info, "FIEH_EXT_DATA", 16, is_valid, FALSE, DBAL_FIELD_PRINT_TYPE_UINT32, 1, FALSE));
    dbal_init_field_type_default_restrict_values(cur_field_type_param);
    SHR_IF_ERR_EXIT(dbal_db_init_field_type_add(unit, cur_field_type_param, cur_field_types_info));
exit:
    SHR_FUNC_EXIT;
}

shr_error_e
_dbal_init_shared_field_types_packet_field_types_pcp_init(
int unit,
field_type_db_struct_t * cur_field_type_param,
dbal_field_types_basic_info_t ** field_types_info)
{
    dbal_field_types_basic_info_t * cur_field_types_info = field_types_info[DBAL_FIELD_TYPE_DEF_PCP];
    int is_valid = TRUE;
    SHR_FUNC_INIT_VARS(unit);
    dbal_init_field_type_db_struct_clear(unit, cur_field_type_param);
    SHR_IF_ERR_EXIT(dbal_db_init_field_type_general_info_set(unit, cur_field_types_info, "PCP", 3, is_valid, FALSE, DBAL_FIELD_PRINT_TYPE_UINT32, 1, FALSE));
    dbal_init_field_type_default_restrict_values(cur_field_type_param);
    SHR_IF_ERR_EXIT(dbal_db_init_field_type_add(unit, cur_field_type_param, cur_field_types_info));
exit:
    SHR_FUNC_EXIT;
}

shr_error_e
_dbal_init_shared_field_types_packet_field_types_dei_init(
int unit,
field_type_db_struct_t * cur_field_type_param,
dbal_field_types_basic_info_t ** field_types_info)
{
    dbal_field_types_basic_info_t * cur_field_types_info = field_types_info[DBAL_FIELD_TYPE_DEF_DEI];
    int is_valid = TRUE;
    SHR_FUNC_INIT_VARS(unit);
    dbal_init_field_type_db_struct_clear(unit, cur_field_type_param);
    SHR_IF_ERR_EXIT(dbal_db_init_field_type_general_info_set(unit, cur_field_types_info, "DEI", 1, is_valid, FALSE, DBAL_FIELD_PRINT_TYPE_UINT32, 1, FALSE));
    dbal_init_field_type_default_restrict_values(cur_field_type_param);
    SHR_IF_ERR_EXIT(dbal_db_init_field_type_add(unit, cur_field_type_param, cur_field_types_info));
exit:
    SHR_FUNC_EXIT;
}

shr_error_e
dbal_init_shared_field_types_packet_field_types_init(
int unit,
field_type_db_struct_t * cur_field_type_param,
dbal_field_types_basic_info_t ** field_types_info)
{
    SHR_FUNC_INIT_VARS(unit);
    SHR_IF_ERR_EXIT(_dbal_init_shared_field_types_packet_field_types_ipv4_init(unit, cur_field_type_param, field_types_info));
    SHR_IF_ERR_EXIT(_dbal_init_shared_field_types_packet_field_types_ipv6_init(unit, cur_field_type_param, field_types_info));
    SHR_IF_ERR_EXIT(_dbal_init_shared_field_types_packet_field_types_l2_mac_init(unit, cur_field_type_param, field_types_info));
    SHR_IF_ERR_EXIT(_dbal_init_shared_field_types_packet_field_types_ipv4_dscp_init(unit, cur_field_type_param, field_types_info));
    SHR_IF_ERR_EXIT(_dbal_init_shared_field_types_packet_field_types_ipv4_ecn_init(unit, cur_field_type_param, field_types_info));
    SHR_IF_ERR_EXIT(_dbal_init_shared_field_types_packet_field_types_ip_protocol_init(unit, cur_field_type_param, field_types_info));
    SHR_IF_ERR_EXIT(_dbal_init_shared_field_types_packet_field_types_ipv4_tos_init(unit, cur_field_type_param, field_types_info));
    SHR_IF_ERR_EXIT(_dbal_init_shared_field_types_packet_field_types_ipv4_header_reserved_flag_init(unit, cur_field_type_param, field_types_info));
    SHR_IF_ERR_EXIT(_dbal_init_shared_field_types_packet_field_types_ipv4_header_df_flag_init(unit, cur_field_type_param, field_types_info));
    SHR_IF_ERR_EXIT(_dbal_init_shared_field_types_packet_field_types_ipv6_tos_init(unit, cur_field_type_param, field_types_info));
    SHR_IF_ERR_EXIT(_dbal_init_shared_field_types_packet_field_types_ipv6_flow_label_init(unit, cur_field_type_param, field_types_info));
    SHR_IF_ERR_EXIT(_dbal_init_shared_field_types_packet_field_types_ipv6_hop_limit_init(unit, cur_field_type_param, field_types_info));
    SHR_IF_ERR_EXIT(_dbal_init_shared_field_types_packet_field_types_l4_port_init(unit, cur_field_type_param, field_types_info));
    SHR_IF_ERR_EXIT(_dbal_init_shared_field_types_packet_field_types_l4_src_port_init(unit, cur_field_type_param, field_types_info));
    SHR_IF_ERR_EXIT(_dbal_init_shared_field_types_packet_field_types_l4_dst_port_init(unit, cur_field_type_param, field_types_info));
    SHR_IF_ERR_EXIT(_dbal_init_shared_field_types_packet_field_types_tcp_ctl_init(unit, cur_field_type_param, field_types_info));
    SHR_IF_ERR_EXIT(_dbal_init_shared_field_types_packet_field_types_next_protocol_init(unit, cur_field_type_param, field_types_info));
    SHR_IF_ERR_EXIT(_dbal_init_shared_field_types_packet_field_types_vxlan_next_protocol_init(unit, cur_field_type_param, field_types_info));
    SHR_IF_ERR_EXIT(_dbal_init_shared_field_types_packet_field_types_ethertype_init(unit, cur_field_type_param, field_types_info));
    SHR_IF_ERR_EXIT(_dbal_init_shared_field_types_packet_field_types_udp_port_init(unit, cur_field_type_param, field_types_info));
    SHR_IF_ERR_EXIT(_dbal_init_shared_field_types_packet_field_types_mpls_label_init(unit, cur_field_type_param, field_types_info));
    SHR_IF_ERR_EXIT(_dbal_init_shared_field_types_packet_field_types_bos_init(unit, cur_field_type_param, field_types_info));
    SHR_IF_ERR_EXIT(_dbal_init_shared_field_types_packet_field_types_mpls_header_init(unit, cur_field_type_param, field_types_info));
    SHR_IF_ERR_EXIT(_dbal_init_shared_field_types_packet_field_types_rch_time_stamp_init(unit, cur_field_type_param, field_types_info));
    SHR_IF_ERR_EXIT(_dbal_init_shared_field_types_packet_field_types_rch_forwarding_additional_info_init(unit, cur_field_type_param, field_types_info));
    SHR_IF_ERR_EXIT(_dbal_init_shared_field_types_packet_field_types_rch_visibility_init(unit, cur_field_type_param, field_types_info));
    SHR_IF_ERR_EXIT(_dbal_init_shared_field_types_packet_field_types_gach_indication_init(unit, cur_field_type_param, field_types_info));
    SHR_IF_ERR_EXIT(_dbal_init_shared_field_types_packet_field_types_ach_ver_init(unit, cur_field_type_param, field_types_info));
    SHR_IF_ERR_EXIT(_dbal_init_shared_field_types_packet_field_types_ach_header_init(unit, cur_field_type_param, field_types_info));
    SHR_IF_ERR_EXIT(_dbal_init_shared_field_types_packet_field_types_channel_type_init(unit, cur_field_type_param, field_types_info));
    SHR_IF_ERR_EXIT(_dbal_init_shared_field_types_packet_field_types_tpid_init(unit, cur_field_type_param, field_types_info));
    SHR_IF_ERR_EXIT(_dbal_init_shared_field_types_packet_field_types_tni_init(unit, cur_field_type_param, field_types_info));
    SHR_IF_ERR_EXIT(_dbal_init_shared_field_types_packet_field_types_exp_init(unit, cur_field_type_param, field_types_info));
    SHR_IF_ERR_EXIT(_dbal_init_shared_field_types_packet_field_types_vlan_id_init(unit, cur_field_type_param, field_types_info));
    SHR_IF_ERR_EXIT(_dbal_init_shared_field_types_packet_field_types_vni_init(unit, cur_field_type_param, field_types_info));
    SHR_IF_ERR_EXIT(_dbal_init_shared_field_types_packet_field_types_bier_mpls_init(unit, cur_field_type_param, field_types_info));
    SHR_IF_ERR_EXIT(_dbal_init_shared_field_types_packet_field_types_ipv4_flags_init(unit, cur_field_type_param, field_types_info));
    SHR_IF_ERR_EXIT(_dbal_init_shared_field_types_packet_field_types_ttl_init(unit, cur_field_type_param, field_types_info));
    SHR_IF_ERR_EXIT(_dbal_init_shared_field_types_packet_field_types_srh_segment_left_init(unit, cur_field_type_param, field_types_info));
    SHR_IF_ERR_EXIT(_dbal_init_shared_field_types_packet_field_types_srh_last_entry_init(unit, cur_field_type_param, field_types_info));
    SHR_IF_ERR_EXIT(_dbal_init_shared_field_types_packet_field_types_srh_flags_init(unit, cur_field_type_param, field_types_info));
    SHR_IF_ERR_EXIT(_dbal_init_shared_field_types_packet_field_types_srh_tag_init(unit, cur_field_type_param, field_types_info));
    SHR_IF_ERR_EXIT(_dbal_init_shared_field_types_packet_field_types_srh_header_ext_length_init(unit, cur_field_type_param, field_types_info));
    SHR_IF_ERR_EXIT(_dbal_init_shared_field_types_packet_field_types_srh_routing_type_init(unit, cur_field_type_param, field_types_info));
    SHR_IF_ERR_EXIT(_dbal_init_shared_field_types_packet_field_types_fih_type_init(unit, cur_field_type_param, field_types_info));
    SHR_IF_ERR_EXIT(_dbal_init_shared_field_types_packet_field_types_fii_tc_init(unit, cur_field_type_param, field_types_info));
    SHR_IF_ERR_EXIT(_dbal_init_shared_field_types_packet_field_types_fii_bos_init(unit, cur_field_type_param, field_types_info));
    SHR_IF_ERR_EXIT(_dbal_init_shared_field_types_packet_field_types_fii_ttl_init(unit, cur_field_type_param, field_types_info));
    SHR_IF_ERR_EXIT(_dbal_init_shared_field_types_packet_field_types_hdr_length_init(unit, cur_field_type_param, field_types_info));
    SHR_IF_ERR_EXIT(_dbal_init_shared_field_types_packet_field_types_dest_opt_type_init(unit, cur_field_type_param, field_types_info));
    SHR_IF_ERR_EXIT(_dbal_init_shared_field_types_packet_field_types_dest_opt_length_init(unit, cur_field_type_param, field_types_info));
    SHR_IF_ERR_EXIT(_dbal_init_shared_field_types_packet_field_types_flow_id_basic_init(unit, cur_field_type_param, field_types_info));
    SHR_IF_ERR_EXIT(_dbal_init_shared_field_types_packet_field_types_flow_id_ext_init(unit, cur_field_type_param, field_types_info));
    SHR_IF_ERR_EXIT(_dbal_init_shared_field_types_packet_field_types_dip_mask_init(unit, cur_field_type_param, field_types_info));
    SHR_IF_ERR_EXIT(_dbal_init_shared_field_types_packet_field_types_sip_mask_init(unit, cur_field_type_param, field_types_info));
    SHR_IF_ERR_EXIT(_dbal_init_shared_field_types_packet_field_types_fieh_ext_data_init(unit, cur_field_type_param, field_types_info));
    SHR_IF_ERR_EXIT(_dbal_init_shared_field_types_packet_field_types_pcp_init(unit, cur_field_type_param, field_types_info));
    SHR_IF_ERR_EXIT(_dbal_init_shared_field_types_packet_field_types_dei_init(unit, cur_field_type_param, field_types_info));
exit:
    SHR_FUNC_EXIT;
}
