
/* *INDENT-OFF* */
/*
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2022 Broadcom Inc. All rights reserved.
 */
#ifndef _DNX_DATA_MAX_INGRESS_CS_H_

#define _DNX_DATA_MAX_INGRESS_CS_H_




#ifndef BCM_DNX_SUPPORT
#error "This file is for use by DNX (JR2) family only!"
#endif



#define DNX_DATA_MAX_INGRESS_CS_PROPERTIES_CS_BUFFER_NOF_BITS_MAX (1)
#ifdef BCM_DNX2_SUPPORT

#undef DNX_DATA_MAX_INGRESS_CS_PROPERTIES_CS_BUFFER_NOF_BITS_MAX

#define DNX_DATA_MAX_INGRESS_CS_PROPERTIES_CS_BUFFER_NOF_BITS_MAX (200)

#endif 


#define DNX_DATA_MAX_INGRESS_CS_PROPERTIES_NOF_BITS_ENTRY_SIZE_PREFIX (1)
#ifdef BCM_DNX2_SUPPORT

#undef DNX_DATA_MAX_INGRESS_CS_PROPERTIES_NOF_BITS_ENTRY_SIZE_PREFIX

#define DNX_DATA_MAX_INGRESS_CS_PROPERTIES_NOF_BITS_ENTRY_SIZE_PREFIX (1)

#endif 




#endif 

