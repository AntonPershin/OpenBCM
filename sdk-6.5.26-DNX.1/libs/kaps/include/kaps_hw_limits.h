

#ifndef __KAPS_HW_LIMITS_H
#define __KAPS_HW_LIMITS_H

#ifdef __cplusplus
extern "C" {
#endif




#define ALIGN_UP(value, align) (((value) + ((align) - 1)) & ~((align) - 1))





#define KAPS_BITS_IN_BYTE (8)



#define KAPS_HW_MAX_KPUS (4)



#define KAPS_HW_MAX_SEARCH_DB (8)



#define KAPS_MAX_INSTRUCTION_CYCLES (2)


#define KAPS_MAX_CASCADED_DEVICES (4)


#define KAPS_MAX_BROADCAST_DEVICES (8)







#define KAPS_HW_MAX_RANGE_COMPARES (4)



#define KAPS_HW_MAX_NUM_RPB_BLOCKS (4)


#define KAPS_HW_MAX_NUM_ADS2_BLOCKS (2)






#define KAPS_HW_MAX_DBA_WIDTH_1 (640)



#define KAPS_HW_MAX_DBA_WIDTH_8 (KAPS_HW_MAX_DBA_WIDTH_1 / KAPS_BITS_IN_BYTE)




#define KAPS_HW_MIN_DBA_WIDTH_1 (80)



#define KAPS_HW_MIN_DBA_WIDTH_8 (KAPS_HW_MIN_DBA_WIDTH_1 / KAPS_BITS_IN_BYTE)




#define KAPS_HW_MAX_UDA_WIDTH_1 (256)


#define KAPS_HW_MAX_UDA_WIDTH_8 (KAPS_HW_MAX_UDA_WIDTH_1 / KAPS_BITS_IN_BYTE)


#define KAPS_HW_MIN_UDA_WIDTH_1 (32)


#define KAPS_HW_MIN_UDA_WIDTH_8 (KAPS_HW_MIN_UDA_WIDTH_1 / KAPS_BITS_IN_BYTE)




#define KAPS_HW_MINIMUM_PRIORITY (0x3FFFFF)


#define KAPS_HW_PRIORITY_SIZE_1 (24)


#define KAPS_HW_PRIORITY_SIZE_8 (KAPS_HW_PRIORITY_SIZE_1 / KAPS_BITS_IN_BYTE)



#define KAPS_HW_MAX_AB (256)



#define KAPS_HW_MAX_DBA_SB (64)



#define KAPS_HW_MAX_LTRS (128)


#define KAPS_HW_MAX_LTR_DUAL_PORT (64)



#define KAPS_LPM_KEY_MAX_WIDTH_1 (160)


#define KAPS_LPM_KEY_MAX_WIDTH_8 (20)


#define KAPS_HW_MAX_SEARCH_KEY_WIDTH_1 (1280)

#define KAPS_HW_MAX_SEARCH_KEY_WIDTH_8 (160)



#define KAPS_HW_HIT_INDEX_WIDTH_1 (24)



#define KAPS_HW_MAX_UDM_SIZE_MB (8)


 

 

 #define KAPS_MAX_NUM_OF_SEGMENTS_PER_KEY   (15)



 #define KAPS_MAX_NUM_HB_BLOCKS              (28)



#define KAPS_MAX_NUM_CORES                   (2)



#define KAPS_UDM_PER_UDC                     (4)


#define KAPS_NUM_DB_PER_DEVICE               (16)


#define KAPS_MAX_NUM_DEVICES                 (4)


#define KAPS_FIB_MAX_INDEX_RANGE             (0xFFFFFF)

#define KAPS_ALLOC_UDM_MAX_COLS             (28)



#define KAPS_HW_MAX_DT_PER_DB (2)




#define HW_MAX_PCM_BLOCKS (16)



#define KAPS_HW_LPU_WIDTH_1 (1024)


#define KAPS_HW_LPU_WIDTH_8 (KAPS_HW_LPU_WIDTH_1 / KAPS_BITS_IN_BYTE)




#define KAPS_HW_MAX_DBA_DT_PER_DB (2)



#define KAPS_HW_MAX_LPUS_PER_DB (16)


#define KAPS_HW_MAX_LPUS_PER_LPM_DB (16)


#define KAPS_MAX_NUM_DAISY_CHAINS (1)



#define KAPS_HW_MAX_NUM_LPU_GRAN (21)




#define KAPS_HW_MAX_PCM_ENTRIES (1024)



#define KAPS_HW_LPM_SMALLEST_GRAN    (8)


#define KAPS_HW_LPM_MAX_GRAN (168)


#define KAPS_HW_MAX_LPUS_PER_LSN (8)





#define KAPS_HW_MAX_NUM_SMALL_BB_PER_DB_GROUP (16)



#define KAPS_HW_MAX_NUM_ROWS_IN_SMALL_BB (512)



#define MAX_RPT_LOPOFF_IN_BYTES (16)




#ifdef __cplusplus
}
#endif
#endif                          
