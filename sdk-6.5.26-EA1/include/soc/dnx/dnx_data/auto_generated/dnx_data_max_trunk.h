
/* *INDENT-OFF* */
/*
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2022 Broadcom Inc. All rights reserved.
 */
#ifndef _DNX_DATA_MAX_TRUNK_H_

#define _DNX_DATA_MAX_TRUNK_H_




#ifndef BCM_DNX_SUPPORT
#error "This file is for use by DNX (JR2) family only!"
#endif



#define DNX_DATA_MAX_TRUNK_PARAMETERS_NOF_POOLS (1)
#ifdef BCM_DNX2_SUPPORT

#undef DNX_DATA_MAX_TRUNK_PARAMETERS_NOF_POOLS

#define DNX_DATA_MAX_TRUNK_PARAMETERS_NOF_POOLS (2)

#endif 


#define DNX_DATA_MAX_TRUNK_PARAMETERS_MAX_NOF_MEMBERS_IN_POOL (1)
#ifdef BCM_DNX2_SUPPORT

#undef DNX_DATA_MAX_TRUNK_PARAMETERS_MAX_NOF_MEMBERS_IN_POOL

#define DNX_DATA_MAX_TRUNK_PARAMETERS_MAX_NOF_MEMBERS_IN_POOL (16384)

#endif 


#define DNX_DATA_MAX_TRUNK_PARAMETERS_MAX_NOF_GROUPS_IN_POOL (1)
#ifdef BCM_DNX2_SUPPORT

#undef DNX_DATA_MAX_TRUNK_PARAMETERS_MAX_NOF_GROUPS_IN_POOL

#define DNX_DATA_MAX_TRUNK_PARAMETERS_MAX_NOF_GROUPS_IN_POOL (8192)

#endif 


#define DNX_DATA_MAX_TRUNK_PARAMETERS_SPA_POOL_SHIFT (1)
#ifdef BCM_DNX2_SUPPORT

#undef DNX_DATA_MAX_TRUNK_PARAMETERS_SPA_POOL_SHIFT

#define DNX_DATA_MAX_TRUNK_PARAMETERS_SPA_POOL_SHIFT (14)

#endif 


#define DNX_DATA_MAX_TRUNK_PARAMETERS_SPA_TYPE_SHIFT (1)
#ifdef BCM_DNX2_SUPPORT

#undef DNX_DATA_MAX_TRUNK_PARAMETERS_SPA_TYPE_SHIFT

#define DNX_DATA_MAX_TRUNK_PARAMETERS_SPA_TYPE_SHIFT (15)

#endif 


#define DNX_DATA_MAX_TRUNK_PSC_CONSISTANT_HASHING_SMALL_GROUP_SIZE_IN_BITS (1)
#ifdef BCM_DNX2_SUPPORT

#undef DNX_DATA_MAX_TRUNK_PSC_CONSISTANT_HASHING_SMALL_GROUP_SIZE_IN_BITS

#define DNX_DATA_MAX_TRUNK_PSC_CONSISTANT_HASHING_SMALL_GROUP_SIZE_IN_BITS (4)

#endif 


#define DNX_DATA_MAX_TRUNK_PSC_SMOOTH_DIVISION_MAX_NOF_MEMBER (1)
#ifdef BCM_DNX2_SUPPORT

#undef DNX_DATA_MAX_TRUNK_PSC_SMOOTH_DIVISION_MAX_NOF_MEMBER

#define DNX_DATA_MAX_TRUNK_PSC_SMOOTH_DIVISION_MAX_NOF_MEMBER (16)

#endif 


#define DNX_DATA_MAX_TRUNK_PSC_SMOOTH_DIVISION_ENTRIES_PER_PROFILE (1)
#ifdef BCM_DNX2_SUPPORT

#undef DNX_DATA_MAX_TRUNK_PSC_SMOOTH_DIVISION_ENTRIES_PER_PROFILE

#define DNX_DATA_MAX_TRUNK_PSC_SMOOTH_DIVISION_ENTRIES_PER_PROFILE (256)

#endif 


#define DNX_DATA_MAX_TRUNK_GRACEFUL_FIRST_HW_CONFIGURATION (1)
#ifdef BCM_DNX2_SUPPORT

#undef DNX_DATA_MAX_TRUNK_GRACEFUL_FIRST_HW_CONFIGURATION

#define DNX_DATA_MAX_TRUNK_GRACEFUL_FIRST_HW_CONFIGURATION (0)

#endif 


#define DNX_DATA_MAX_TRUNK_GRACEFUL_SECOND_HW_CONFIGURATION (1)
#ifdef BCM_DNX2_SUPPORT

#undef DNX_DATA_MAX_TRUNK_GRACEFUL_SECOND_HW_CONFIGURATION

#define DNX_DATA_MAX_TRUNK_GRACEFUL_SECOND_HW_CONFIGURATION (1)

#endif 




#endif 

