
/* *INDENT-OFF* */
/*
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2022 Broadcom Inc. All rights reserved.
 */
#ifndef _DNX_DATA_MAX_PLL_H_

#define _DNX_DATA_MAX_PLL_H_




#ifndef BCM_DNX_SUPPORT
#error "This file is for use by DNX (JR2) family only!"
#endif



#define DNX_DATA_MAX_PLL_PLL1_NOF_PLL1  (1)
#ifdef BCM_DNX2_SUPPORT

#undef DNX_DATA_MAX_PLL_PLL1_NOF_PLL1

#define DNX_DATA_MAX_PLL_PLL1_NOF_PLL1  (4)

#endif 


#define DNX_DATA_MAX_PLL_PLL3_NOF_PLL3  (1)
#ifdef BCM_DNX2_SUPPORT

#undef DNX_DATA_MAX_PLL_PLL3_NOF_PLL3

#define DNX_DATA_MAX_PLL_PLL3_NOF_PLL3  (4)

#endif 


#define DNX_DATA_MAX_PLL_PLL3_VCO_CLOCK (1)
#ifdef BCM_DNX2_SUPPORT

#undef DNX_DATA_MAX_PLL_PLL3_VCO_CLOCK

#define DNX_DATA_MAX_PLL_PLL3_VCO_CLOCK (6250)

#endif 


#define DNX_DATA_MAX_PLL_PLL3_KP        (1)
#ifdef BCM_DNX2_SUPPORT

#undef DNX_DATA_MAX_PLL_PLL3_KP

#define DNX_DATA_MAX_PLL_PLL3_KP        (5)

#endif 


#define DNX_DATA_MAX_PLL_PLL3_KI        (1)
#ifdef BCM_DNX2_SUPPORT

#undef DNX_DATA_MAX_PLL_PLL3_KI

#define DNX_DATA_MAX_PLL_PLL3_KI        (3)

#endif 


#define DNX_DATA_MAX_PLL_PLL3_EN_CTRL   (1)
#ifdef BCM_DNX2_SUPPORT

#undef DNX_DATA_MAX_PLL_PLL3_EN_CTRL

#define DNX_DATA_MAX_PLL_PLL3_EN_CTRL   (29)

#endif 


#define DNX_DATA_MAX_PLL_PLL3_EN_CTRL_BYP (1)
#ifdef BCM_DNX2_SUPPORT

#undef DNX_DATA_MAX_PLL_PLL3_EN_CTRL_BYP

#define DNX_DATA_MAX_PLL_PLL3_EN_CTRL_BYP (93)

#endif 


#define DNX_DATA_MAX_PLL_PLL3_ROUTE_CTR_BYP (1)
#ifdef BCM_DNX2_SUPPORT

#undef DNX_DATA_MAX_PLL_PLL3_ROUTE_CTR_BYP

#define DNX_DATA_MAX_PLL_PLL3_ROUTE_CTR_BYP (252)

#endif 


#define DNX_DATA_MAX_PLL_PLL3_REF_CLOCK_125 (1)
#ifdef BCM_DNX2_SUPPORT

#undef DNX_DATA_MAX_PLL_PLL3_REF_CLOCK_125

#define DNX_DATA_MAX_PLL_PLL3_REF_CLOCK_125 (125)

#endif 


#define DNX_DATA_MAX_PLL_PLL3_REF_CLOCK_156_25 (1)
#ifdef BCM_DNX2_SUPPORT

#undef DNX_DATA_MAX_PLL_PLL3_REF_CLOCK_156_25

#define DNX_DATA_MAX_PLL_PLL3_REF_CLOCK_156_25 (156)

#endif 


#define DNX_DATA_MAX_PLL_PLL3_REF_CLOCK_312_5 (1)
#ifdef BCM_DNX2_SUPPORT

#undef DNX_DATA_MAX_PLL_PLL3_REF_CLOCK_312_5

#define DNX_DATA_MAX_PLL_PLL3_REF_CLOCK_312_5 (312)

#endif 


#define DNX_DATA_MAX_PLL_PLL4_NOF_PLL4  (1)
#ifdef BCM_DNX2_SUPPORT

#undef DNX_DATA_MAX_PLL_PLL4_NOF_PLL4

#define DNX_DATA_MAX_PLL_PLL4_NOF_PLL4  (7)

#endif 




#endif 

