/* 
 * 
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2022 Broadcom Inc. All rights reserved.
 *
 * DFE topology example example:
 * 
 * The example simulate:
 *  1. set topology for local module
 *  2. set topology for faps group
 *
 */


/*set topology for local module*/
int
local_mapping_set(int unit) {
    bcm_port_t links_array[3];
    bcm_module_t local_module;

    /*define local module id*/
    local_module = 1;
    BCM_FABRIC_LOCAL_MODID_SET(local_module);
    
    /*map local module id with module id*/ 
    BCM_IF_ERROR_RETURN_MSG(bcm_fabric_modid_local_mapping_set(unit, local_module, 512), "");

    /*select links*/
    links_array[0] = 1;
    links_array[1] = 2;
    links_array[2] = 3;

    /*set topology using module id*/
    BCM_IF_ERROR_RETURN_MSG(bcm_fabric_link_topology_set(unit, 512, 3, links_array), ""); 

    /*define second local module id*/
    local_module = 2;                                              
    BCM_FABRIC_LOCAL_MODID_SET(local_module);

    /*map local module id with module id*/ 
    BCM_IF_ERROR_RETURN_MSG(bcm_fabric_modid_local_mapping_set(unit, local_module, 25), "");

    /*select links*/
    links_array[0] = 4;
    links_array[1] = 5;
    links_array[2] = 6;

    /*set topology using local module id*/
    BCM_IF_ERROR_RETURN_MSG(bcm_fabric_link_topology_set(unit, local_module, 3, links_array), ""); /*with local modid*/

    printf("local_mapping_set: PASS\n");
    return BCM_E_NONE;
}


/*set topology for local module*/
int
cint_fe_local_fap_mapping_set(int fe_unit,
                              int fap_modid,
                              int local_fap_modid,
                              int modid_offset)
{
    char error_msg[200]={0,};
    int fe_link;
    uint32 max_nof_fe_links = *(dnxc_data_get(fe_unit, "port", "general", "nof_links", NULL));
    bcm_fabric_link_connectivity_t connectivity_links[max_nof_fe_links];
    int nof_links_connected_to_fap = 0, nof_connectivity_links;
    bcm_port_t fe_to_fap_links_array[max_nof_fe_links] = { 0 };
    bcm_module_t local_module;

    snprintf(error_msg, sizeof(error_msg), "failed: unit %d.", fe_unit);
    BCM_IF_ERROR_RETURN_MSG(bcm_fabric_link_connectivity_status_get(fe_unit, max_nof_fe_links, connectivity_links, &nof_connectivity_links), error_msg);

    for (fe_link = 0; fe_link < nof_connectivity_links; fe_link++)
    {
        if (connectivity_links[fe_link].module_id == fap_modid && connectivity_links[fe_link].device_type != bcmFabricDeviceTypeUnknown)
        {
            fe_to_fap_links_array[nof_links_connected_to_fap] = fe_link;
            nof_links_connected_to_fap++;
        }
    }

    if (*(dnxc_data_get(fe_unit, "device", "general", "serdes_support", NULL)))
    {
        if (nof_links_connected_to_fap == 0) {
            printf("ERROR! No Links found to fap with modid %d, \n", fap_modid);
            return BCM_E_PARAM;
        }
    }

    /*define local module id*/
    BCM_FABRIC_LOCAL_MODID_SET(local_fap_modid);

    /*map local module id with module id*/
    BCM_IF_ERROR_RETURN_MSG(bcm_fabric_modid_local_mapping_set(fe_unit, local_fap_modid, fap_modid - modid_offset), "");

    /*set topology using module id*/
    BCM_IF_ERROR_RETURN_MSG(bcm_fabric_link_topology_set(fe_unit, local_fap_modid, nof_links_connected_to_fap, fe_to_fap_links_array), "");

    return BCM_E_NONE;
}



/*set topology for faps group*/
int
faps_group_set(int unit) {
    bcm_module_t modid_array[3];
    bcm_port_t links_array[3];
    bcm_module_t g;

    /*define faps group*/
    g = 1;
    BCM_FABRIC_GROUP_MODID_SET(g);

    /*select module ids*/
    modid_array[0] = 1;
    modid_array[1] = 2;
    modid_array[2] = 3;

    /*map faps groups with selected module ids*/
    BCM_IF_ERROR_RETURN_MSG(bcm_fabric_modid_group_set(unit,  g, 3, modid_array), "");

    /*select links*/
    links_array[0] = 1;
    links_array[1] = 2;
    links_array[2] = 3;

    /*set faps group topology*/
    BCM_IF_ERROR_RETURN_MSG(bcm_fabric_link_topology_set(unit, g, 3, links_array), ""); /*with local modid*/
    
    printf("faps_group_set: PASS\n");
    return BCM_E_NONE;
}

