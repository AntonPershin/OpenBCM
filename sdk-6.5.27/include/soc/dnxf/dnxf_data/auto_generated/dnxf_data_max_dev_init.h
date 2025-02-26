
/* *INDENT-OFF* */
/*
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2022 Broadcom Inc. All rights reserved.
 */
#ifndef _DNXF_DATA_MAX_DEV_INIT_H_

#define _DNXF_DATA_MAX_DEV_INIT_H_




#ifndef BCM_DNXF_SUPPORT
#error "This file is for use by DNXF family only!"
#endif


#define DNXF_DATA_MAX_DEV_INIT_TIME_INIT_TOTAL_TIME (1)
#ifdef BCM_DNXF1_SUPPORT

#undef DNXF_DATA_MAX_DEV_INIT_TIME_INIT_TOTAL_TIME
#define DNXF_DATA_MAX_DEV_INIT_TIME_INIT_TOTAL_TIME (14560000)

#endif 

#define DNXF_DATA_MAX_DEV_INIT_TIME_APPL_INIT_TOTAL_TIME (1)
#ifdef BCM_DNXF1_SUPPORT

#undef DNXF_DATA_MAX_DEV_INIT_TIME_APPL_INIT_TOTAL_TIME
#define DNXF_DATA_MAX_DEV_INIT_TIME_APPL_INIT_TOTAL_TIME (20000000)

#endif 

#define DNXF_DATA_MAX_DEV_INIT_TIME_DOWN_DEVIATION_TOTAL (1)
#ifdef BCM_DNXF1_SUPPORT

#undef DNXF_DATA_MAX_DEV_INIT_TIME_DOWN_DEVIATION_TOTAL
#define DNXF_DATA_MAX_DEV_INIT_TIME_DOWN_DEVIATION_TOTAL (10)

#endif 

#define DNXF_DATA_MAX_DEV_INIT_TIME_UP_DEVIATION_TOTAL (1)
#ifdef BCM_DNXF1_SUPPORT

#undef DNXF_DATA_MAX_DEV_INIT_TIME_UP_DEVIATION_TOTAL
#define DNXF_DATA_MAX_DEV_INIT_TIME_UP_DEVIATION_TOTAL (10)

#endif 

#define DNXF_DATA_MAX_DEV_INIT_TIME_TEST_SENSITIVITY (1)
#ifdef BCM_DNXF1_SUPPORT

#undef DNXF_DATA_MAX_DEV_INIT_TIME_TEST_SENSITIVITY
#define DNXF_DATA_MAX_DEV_INIT_TIME_TEST_SENSITIVITY (0)

#endif 

#define DNXF_DATA_MAX_DEV_INIT_CMC_CMC_NUM (1)
#ifdef BCM_DNXF1_SUPPORT

#undef DNXF_DATA_MAX_DEV_INIT_CMC_CMC_NUM
#define DNXF_DATA_MAX_DEV_INIT_CMC_CMC_NUM (2)

#endif 

#define DNXF_DATA_MAX_DEV_INIT_CMC_NUM_CPU_COSQ (1)
#ifdef BCM_DNXF1_SUPPORT

#undef DNXF_DATA_MAX_DEV_INIT_CMC_NUM_CPU_COSQ
#define DNXF_DATA_MAX_DEV_INIT_CMC_NUM_CPU_COSQ (64)

#endif 




#endif 

