
/* *INDENT-OFF* */
/*
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2022 Broadcom Inc. All rights reserved.
 */
#ifndef _DNXF_DATA_MAX_FABRIC_H_

#define _DNXF_DATA_MAX_FABRIC_H_




#ifndef BCM_DNXF_SUPPORT
#error "This file is for use by DNXF family only!"
#endif


#define DNXF_DATA_MAX_FABRIC_GENERAL_MAX_NOF_PIPES (1)
#ifdef BCM_DNXF1_SUPPORT

#undef DNXF_DATA_MAX_FABRIC_GENERAL_MAX_NOF_PIPES
#define DNXF_DATA_MAX_FABRIC_GENERAL_MAX_NOF_PIPES (3)

#endif 

#define DNXF_DATA_MAX_FABRIC_PIPES_MAX_NOF_PIPES (1)
#ifdef BCM_DNXF1_SUPPORT

#undef DNXF_DATA_MAX_FABRIC_PIPES_MAX_NOF_PIPES
#define DNXF_DATA_MAX_FABRIC_PIPES_MAX_NOF_PIPES (3)

#endif 

#define DNXF_DATA_MAX_FABRIC_PIPES_LOCAL_ROUTE_PIPE_INDEX (1)
#ifdef BCM_DNXF1_SUPPORT

#undef DNXF_DATA_MAX_FABRIC_PIPES_LOCAL_ROUTE_PIPE_INDEX
#define DNXF_DATA_MAX_FABRIC_PIPES_LOCAL_ROUTE_PIPE_INDEX (1)

#endif 

#define DNXF_DATA_MAX_FABRIC_MULTICAST_TABLE_ROW_SIZE_IN_UINT32 (1)
#ifdef BCM_DNXF1_SUPPORT

#undef DNXF_DATA_MAX_FABRIC_MULTICAST_TABLE_ROW_SIZE_IN_UINT32
#define DNXF_DATA_MAX_FABRIC_MULTICAST_TABLE_ROW_SIZE_IN_UINT32 (7)

#endif 

#define DNXF_DATA_MAX_FABRIC_FIFOS_GRANULARITY (1)
#ifdef BCM_DNXF1_SUPPORT

#undef DNXF_DATA_MAX_FABRIC_FIFOS_GRANULARITY
#define DNXF_DATA_MAX_FABRIC_FIFOS_GRANULARITY (4)

#endif 

#define DNXF_DATA_MAX_FABRIC_FIFOS_MIN_DEPTH (1)
#ifdef BCM_DNXF1_SUPPORT

#undef DNXF_DATA_MAX_FABRIC_FIFOS_MIN_DEPTH
#define DNXF_DATA_MAX_FABRIC_FIFOS_MIN_DEPTH (16)

#endif 

#define DNXF_DATA_MAX_FABRIC_FIFOS_MAX_UNUSED_RESOURCES (1)
#ifdef BCM_DNXF1_SUPPORT

#undef DNXF_DATA_MAX_FABRIC_FIFOS_MAX_UNUSED_RESOURCES
#define DNXF_DATA_MAX_FABRIC_FIFOS_MAX_UNUSED_RESOURCES (36)

#endif 

#define DNXF_DATA_MAX_FABRIC_FIFOS_RX_RESOURCES (1)
#ifdef BCM_DNXF1_SUPPORT

#undef DNXF_DATA_MAX_FABRIC_FIFOS_RX_RESOURCES
#define DNXF_DATA_MAX_FABRIC_FIFOS_RX_RESOURCES (768)

#endif 

#define DNXF_DATA_MAX_FABRIC_FIFOS_MID_RESOURCES (1)
#ifdef BCM_DNXF1_SUPPORT

#undef DNXF_DATA_MAX_FABRIC_FIFOS_MID_RESOURCES
#define DNXF_DATA_MAX_FABRIC_FIFOS_MID_RESOURCES (4608)

#endif 

#define DNXF_DATA_MAX_FABRIC_FIFOS_TX_RESOURCES (1)
#ifdef BCM_DNXF1_SUPPORT

#undef DNXF_DATA_MAX_FABRIC_FIFOS_TX_RESOURCES
#define DNXF_DATA_MAX_FABRIC_FIFOS_TX_RESOURCES (4096)

#endif 

#define DNXF_DATA_MAX_FABRIC_FIFOS_REDUCED_RX_RESOURCES (1)
#ifdef BCM_DNXF1_SUPPORT

#undef DNXF_DATA_MAX_FABRIC_FIFOS_REDUCED_RX_RESOURCES
#define DNXF_DATA_MAX_FABRIC_FIFOS_REDUCED_RX_RESOURCES (768)

#endif 

#define DNXF_DATA_MAX_FABRIC_FIFOS_DFL_RESOURCES (1)

#define DNXF_DATA_MAX_FABRIC_FIFOS_REDUCED_DFL_RESOURCES (1)

#define DNXF_DATA_MAX_FABRIC_FIFOS_RX_FULL_OFFSET (1)
#ifdef BCM_DNXF1_SUPPORT

#undef DNXF_DATA_MAX_FABRIC_FIFOS_RX_FULL_OFFSET
#define DNXF_DATA_MAX_FABRIC_FIFOS_RX_FULL_OFFSET (4)

#endif 

#define DNXF_DATA_MAX_FABRIC_FIFOS_MID_FULL_OFFSET (1)
#ifdef BCM_DNXF1_SUPPORT

#undef DNXF_DATA_MAX_FABRIC_FIFOS_MID_FULL_OFFSET
#define DNXF_DATA_MAX_FABRIC_FIFOS_MID_FULL_OFFSET (12)

#endif 

#define DNXF_DATA_MAX_FABRIC_FIFOS_TX_FULL_OFFSET (1)
#ifdef BCM_DNXF1_SUPPORT

#undef DNXF_DATA_MAX_FABRIC_FIFOS_TX_FULL_OFFSET
#define DNXF_DATA_MAX_FABRIC_FIFOS_TX_FULL_OFFSET (12)

#endif 

#define DNXF_DATA_MAX_FABRIC_FIFOS_DFL_BANK_WR_THRESHOLD_OFFSET (1)

#define DNXF_DATA_MAX_FABRIC_FIFOS_DFL_BANK_ADMIT_THRESHOLD_ADDITIONAL_OFFSET (1)

#define DNXF_DATA_MAX_FABRIC_CONGESTION_NOF_PROFILES (1)
#ifdef BCM_DNXF1_SUPPORT

#undef DNXF_DATA_MAX_FABRIC_CONGESTION_NOF_PROFILES
#define DNXF_DATA_MAX_FABRIC_CONGESTION_NOF_PROFILES (2)

#endif 

#define DNXF_DATA_MAX_FABRIC_CONGESTION_NOF_THRESHOLD_PRIORITIES (1)
#ifdef BCM_DNXF1_SUPPORT

#undef DNXF_DATA_MAX_FABRIC_CONGESTION_NOF_THRESHOLD_PRIORITIES
#define DNXF_DATA_MAX_FABRIC_CONGESTION_NOF_THRESHOLD_PRIORITIES (4)

#endif 

#define DNXF_DATA_MAX_FABRIC_CONGESTION_NOF_THRESHOLD_LEVELS (1)
#ifdef BCM_DNXF1_SUPPORT

#undef DNXF_DATA_MAX_FABRIC_CONGESTION_NOF_THRESHOLD_LEVELS
#define DNXF_DATA_MAX_FABRIC_CONGESTION_NOF_THRESHOLD_LEVELS (3)

#endif 

#define DNXF_DATA_MAX_FABRIC_CONGESTION_NOF_THRESHOLD_INDEX_DIMENSIONS (1)
#ifdef BCM_DNXF1_SUPPORT

#undef DNXF_DATA_MAX_FABRIC_CONGESTION_NOF_THRESHOLD_INDEX_DIMENSIONS
#define DNXF_DATA_MAX_FABRIC_CONGESTION_NOF_THRESHOLD_INDEX_DIMENSIONS (2)

#endif 

#define DNXF_DATA_MAX_FABRIC_CONGESTION_NOF_DFL_BANKS (1)
#ifdef BCM_DNXF1_SUPPORT

#undef DNXF_DATA_MAX_FABRIC_CONGESTION_NOF_DFL_BANKS
#define DNXF_DATA_MAX_FABRIC_CONGESTION_NOF_DFL_BANKS (10)

#endif 

#define DNXF_DATA_MAX_FABRIC_CONGESTION_NOF_DFL_SUB_BANKS (1)
#ifdef BCM_DNXF1_SUPPORT

#undef DNXF_DATA_MAX_FABRIC_CONGESTION_NOF_DFL_SUB_BANKS
#define DNXF_DATA_MAX_FABRIC_CONGESTION_NOF_DFL_SUB_BANKS (2)

#endif 

#define DNXF_DATA_MAX_FABRIC_CONGESTION_NOF_DFL_BANK_ENTRIES (1)
#ifdef BCM_DNXF1_SUPPORT

#undef DNXF_DATA_MAX_FABRIC_CONGESTION_NOF_DFL_BANK_ENTRIES
#define DNXF_DATA_MAX_FABRIC_CONGESTION_NOF_DFL_BANK_ENTRIES (3600)

#endif 

#define DNXF_DATA_MAX_FABRIC_CONGESTION_NOF_RCI_BITS (1)
#ifdef BCM_DNXF1_SUPPORT

#undef DNXF_DATA_MAX_FABRIC_CONGESTION_NOF_RCI_BITS
#define DNXF_DATA_MAX_FABRIC_CONGESTION_NOF_RCI_BITS (2)

#endif 

#define DNXF_DATA_MAX_FABRIC_CONGESTION_MAX_WFQ_WEIGHT_VALUE (1)
#ifdef BCM_DNXF1_SUPPORT

#undef DNXF_DATA_MAX_FABRIC_CONGESTION_MAX_WFQ_WEIGHT_VALUE
#define DNXF_DATA_MAX_FABRIC_CONGESTION_MAX_WFQ_WEIGHT_VALUE (127)

#endif 

#define DNXF_DATA_MAX_FABRIC_FIFO_DMA_FABRIC_CELL_NOF_ENTRIES_PER_CELL (1)
#ifdef BCM_DNXF1_SUPPORT

#undef DNXF_DATA_MAX_FABRIC_FIFO_DMA_FABRIC_CELL_NOF_ENTRIES_PER_CELL
#define DNXF_DATA_MAX_FABRIC_FIFO_DMA_FABRIC_CELL_NOF_ENTRIES_PER_CELL (4)

#endif 

#define DNXF_DATA_MAX_FABRIC_FIFO_DMA_NOF_CHANNELS (1)
#ifdef BCM_DNXF1_SUPPORT

#undef DNXF_DATA_MAX_FABRIC_FIFO_DMA_NOF_CHANNELS
#define DNXF_DATA_MAX_FABRIC_FIFO_DMA_NOF_CHANNELS (8)

#endif 

#define DNXF_DATA_MAX_FABRIC_FIFO_DMA_ENTRY_SIZE (1)
#ifdef BCM_DNXF1_SUPPORT

#undef DNXF_DATA_MAX_FABRIC_FIFO_DMA_ENTRY_SIZE
#define DNXF_DATA_MAX_FABRIC_FIFO_DMA_ENTRY_SIZE (80)

#endif 

#define DNXF_DATA_MAX_FABRIC_FIFO_DMA_MAX_NOF_ENTRIES (1)
#ifdef BCM_DNXF1_SUPPORT

#undef DNXF_DATA_MAX_FABRIC_FIFO_DMA_MAX_NOF_ENTRIES
#define DNXF_DATA_MAX_FABRIC_FIFO_DMA_MAX_NOF_ENTRIES (16384)

#endif 

#define DNXF_DATA_MAX_FABRIC_FIFO_DMA_MIN_NOF_ENTRIES (1)
#ifdef BCM_DNXF1_SUPPORT

#undef DNXF_DATA_MAX_FABRIC_FIFO_DMA_MIN_NOF_ENTRIES
#define DNXF_DATA_MAX_FABRIC_FIFO_DMA_MIN_NOF_ENTRIES (64)

#endif 

#define DNXF_DATA_MAX_FABRIC_RXTX_NOF_TX_CHANNELS (1)

#define DNXF_DATA_MAX_FABRIC_RXTX_NOF_EP_IP_INSTANCES (1)

#define DNXF_DATA_MAX_FABRIC_RXTX_PKTSRC_ID_TO_CHANNEL_BIT_FIELD_SIZE (1)

#define DNXF_DATA_MAX_FABRIC_RXTX_PKTSRC_ID_TO_DEST_FIELD_SIZE (1)

#define DNXF_DATA_MAX_FABRIC_RXTX_MAX_NOF_SUB_CHANNELS_USED (1)

#define DNXF_DATA_MAX_FABRIC_CELL_MAX_VSC_FORMAT_SIZE (1)
#ifdef BCM_DNXF1_SUPPORT

#undef DNXF_DATA_MAX_FABRIC_CELL_MAX_VSC_FORMAT_SIZE
#define DNXF_DATA_MAX_FABRIC_CELL_MAX_VSC_FORMAT_SIZE (256)

#endif 

#define DNXF_DATA_MAX_FABRIC_CELL_RX_CPU_CELL_MAX_PAYLOAD_SIZE (1)
#ifdef BCM_DNXF1_SUPPORT

#undef DNXF_DATA_MAX_FABRIC_CELL_RX_CPU_CELL_MAX_PAYLOAD_SIZE
#define DNXF_DATA_MAX_FABRIC_CELL_RX_CPU_CELL_MAX_PAYLOAD_SIZE (1024)

#endif 

#define DNXF_DATA_MAX_FABRIC_CELL_RX_MAX_NOF_CPU_BUFFERS (1)
#ifdef BCM_DNXF1_SUPPORT

#undef DNXF_DATA_MAX_FABRIC_CELL_RX_MAX_NOF_CPU_BUFFERS
#define DNXF_DATA_MAX_FABRIC_CELL_RX_MAX_NOF_CPU_BUFFERS (8)

#endif 

#define DNXF_DATA_MAX_FABRIC_CELL_SOURCE_ROUTED_CELLS_HEADER_OFFSET (1)
#ifdef BCM_DNXF1_SUPPORT

#undef DNXF_DATA_MAX_FABRIC_CELL_SOURCE_ROUTED_CELLS_HEADER_OFFSET
#define DNXF_DATA_MAX_FABRIC_CELL_SOURCE_ROUTED_CELLS_HEADER_OFFSET (32)

#endif 

#define DNXF_DATA_MAX_FABRIC_TOPOLOGY_MAX_LINK_SCORE (1)
#ifdef BCM_DNXF1_SUPPORT

#undef DNXF_DATA_MAX_FABRIC_TOPOLOGY_MAX_LINK_SCORE
#define DNXF_DATA_MAX_FABRIC_TOPOLOGY_MAX_LINK_SCORE (120)

#endif 

#define DNXF_DATA_MAX_FABRIC_TOPOLOGY_NOF_SYSTEM_MODID (1)
#ifdef BCM_DNXF1_SUPPORT

#undef DNXF_DATA_MAX_FABRIC_TOPOLOGY_NOF_SYSTEM_MODID
#define DNXF_DATA_MAX_FABRIC_TOPOLOGY_NOF_SYSTEM_MODID (2048)

#endif 

#define DNXF_DATA_MAX_FABRIC_TOPOLOGY_NOF_LOCAL_MODID (1)
#ifdef BCM_DNXF1_SUPPORT

#undef DNXF_DATA_MAX_FABRIC_TOPOLOGY_NOF_LOCAL_MODID
#define DNXF_DATA_MAX_FABRIC_TOPOLOGY_NOF_LOCAL_MODID (192)

#endif 

#define DNXF_DATA_MAX_FABRIC_TOPOLOGY_NOF_LOCAL_MODID_FE13 (1)
#ifdef BCM_DNXF1_SUPPORT

#undef DNXF_DATA_MAX_FABRIC_TOPOLOGY_NOF_LOCAL_MODID_FE13
#define DNXF_DATA_MAX_FABRIC_TOPOLOGY_NOF_LOCAL_MODID_FE13 (96)

#endif 

#define DNXF_DATA_MAX_FABRIC_TOPOLOGY_ALL_REACHABLE_FAP_GROUP_SIZE (1)
#ifdef BCM_DNXF1_SUPPORT

#undef DNXF_DATA_MAX_FABRIC_TOPOLOGY_ALL_REACHABLE_FAP_GROUP_SIZE
#define DNXF_DATA_MAX_FABRIC_TOPOLOGY_ALL_REACHABLE_FAP_GROUP_SIZE (32)

#endif 

#define DNXF_DATA_MAX_FABRIC_TOPOLOGY_ALL_REACHABLE_MAX_NOF_IGNORE_FAPS (1)
#ifdef BCM_DNXF1_SUPPORT

#undef DNXF_DATA_MAX_FABRIC_TOPOLOGY_ALL_REACHABLE_MAX_NOF_IGNORE_FAPS
#define DNXF_DATA_MAX_FABRIC_TOPOLOGY_ALL_REACHABLE_MAX_NOF_IGNORE_FAPS (16)

#endif 

#define DNXF_DATA_MAX_FABRIC_GPD_IN_TIME (1)
#ifdef BCM_DNXF1_SUPPORT

#undef DNXF_DATA_MAX_FABRIC_GPD_IN_TIME
#define DNXF_DATA_MAX_FABRIC_GPD_IN_TIME (60)

#endif 

#define DNXF_DATA_MAX_FABRIC_GPD_OUT_TIME (1)
#ifdef BCM_DNXF1_SUPPORT

#undef DNXF_DATA_MAX_FABRIC_GPD_OUT_TIME
#define DNXF_DATA_MAX_FABRIC_GPD_OUT_TIME (200)

#endif 

#define DNXF_DATA_MAX_FABRIC_REACHABILITY_TABLE_ROW_SIZE_IN_UINT32 (1)
#ifdef BCM_DNXF1_SUPPORT

#undef DNXF_DATA_MAX_FABRIC_REACHABILITY_TABLE_ROW_SIZE_IN_UINT32
#define DNXF_DATA_MAX_FABRIC_REACHABILITY_TABLE_ROW_SIZE_IN_UINT32 (7)

#endif 

#define DNXF_DATA_MAX_FABRIC_REACHABILITY_TABLE_GROUP_SIZE (1)
#ifdef BCM_DNXF1_SUPPORT

#undef DNXF_DATA_MAX_FABRIC_REACHABILITY_TABLE_GROUP_SIZE
#define DNXF_DATA_MAX_FABRIC_REACHABILITY_TABLE_GROUP_SIZE (32)

#endif 

#define DNXF_DATA_MAX_FABRIC_REACHABILITY_RMGR_UNITS (1)
#ifdef BCM_DNXF1_SUPPORT

#undef DNXF_DATA_MAX_FABRIC_REACHABILITY_RMGR_UNITS
#define DNXF_DATA_MAX_FABRIC_REACHABILITY_RMGR_UNITS (32)

#endif 

#define DNXF_DATA_MAX_FABRIC_REACHABILITY_GPD_RMGR_TIME_FACTOR (1)
#ifdef BCM_DNXF1_SUPPORT

#undef DNXF_DATA_MAX_FABRIC_REACHABILITY_GPD_RMGR_TIME_FACTOR
#define DNXF_DATA_MAX_FABRIC_REACHABILITY_GPD_RMGR_TIME_FACTOR (4)

#endif 

#define DNXF_DATA_MAX_FABRIC_REACHABILITY_GEN_RATE_LINK_DELTA (1)
#ifdef BCM_DNXF1_SUPPORT

#undef DNXF_DATA_MAX_FABRIC_REACHABILITY_GEN_RATE_LINK_DELTA
#define DNXF_DATA_MAX_FABRIC_REACHABILITY_GEN_RATE_LINK_DELTA (15)

#endif 

#define DNXF_DATA_MAX_FABRIC_REACHABILITY_GEN_RATE_FULL_CYCLE (1)
#ifdef BCM_DNXF1_SUPPORT

#undef DNXF_DATA_MAX_FABRIC_REACHABILITY_GEN_RATE_FULL_CYCLE
#define DNXF_DATA_MAX_FABRIC_REACHABILITY_GEN_RATE_FULL_CYCLE (44800)

#endif 

#define DNXF_DATA_MAX_FABRIC_REACHABILITY_GPD_GEN_RATE_FULL_CYCLE (1)
#ifdef BCM_DNXF1_SUPPORT

#undef DNXF_DATA_MAX_FABRIC_REACHABILITY_GPD_GEN_RATE_FULL_CYCLE
#define DNXF_DATA_MAX_FABRIC_REACHABILITY_GPD_GEN_RATE_FULL_CYCLE (10000)

#endif 

#define DNXF_DATA_MAX_FABRIC_REACHABILITY_WATCHDOG_RATE (1)
#ifdef BCM_DNXF1_SUPPORT

#undef DNXF_DATA_MAX_FABRIC_REACHABILITY_WATCHDOG_RATE
#define DNXF_DATA_MAX_FABRIC_REACHABILITY_WATCHDOG_RATE (100000)

#endif 

#define DNXF_DATA_MAX_FABRIC_SYSTEM_UPGRADE_MAX_MASTER_ID (1)
#ifdef BCM_DNXF1_SUPPORT

#undef DNXF_DATA_MAX_FABRIC_SYSTEM_UPGRADE_MAX_MASTER_ID
#define DNXF_DATA_MAX_FABRIC_SYSTEM_UPGRADE_MAX_MASTER_ID (2047)

#endif 

#define DNXF_DATA_MAX_FABRIC_SYSTEM_UPGRADE_PARAM_0 (1)
#ifdef BCM_DNXF1_SUPPORT

#undef DNXF_DATA_MAX_FABRIC_SYSTEM_UPGRADE_PARAM_0
#define DNXF_DATA_MAX_FABRIC_SYSTEM_UPGRADE_PARAM_0 (10)

#endif 

#define DNXF_DATA_MAX_FABRIC_SYSTEM_UPGRADE_PARAM_1 (1)
#ifdef BCM_DNXF1_SUPPORT

#undef DNXF_DATA_MAX_FABRIC_SYSTEM_UPGRADE_PARAM_1
#define DNXF_DATA_MAX_FABRIC_SYSTEM_UPGRADE_PARAM_1 (8388607)

#endif 

#define DNXF_DATA_MAX_FABRIC_SYSTEM_UPGRADE_PARAM_2 (1)
#ifdef BCM_DNXF1_SUPPORT

#undef DNXF_DATA_MAX_FABRIC_SYSTEM_UPGRADE_PARAM_2
#define DNXF_DATA_MAX_FABRIC_SYSTEM_UPGRADE_PARAM_2 (10000)

#endif 

#define DNXF_DATA_MAX_FABRIC_SYSTEM_UPGRADE_PARAM_3 (1)
#ifdef BCM_DNXF1_SUPPORT

#undef DNXF_DATA_MAX_FABRIC_SYSTEM_UPGRADE_PARAM_3
#define DNXF_DATA_MAX_FABRIC_SYSTEM_UPGRADE_PARAM_3 (300000)

#endif 

#define DNXF_DATA_MAX_FABRIC_SYSTEM_UPGRADE_PARAM_4 (1)
#ifdef BCM_DNXF1_SUPPORT

#undef DNXF_DATA_MAX_FABRIC_SYSTEM_UPGRADE_PARAM_4
#define DNXF_DATA_MAX_FABRIC_SYSTEM_UPGRADE_PARAM_4 (1000)

#endif 

#define DNXF_DATA_MAX_FABRIC_SYSTEM_UPGRADE_PARAM_5 (1)
#ifdef BCM_DNXF1_SUPPORT

#undef DNXF_DATA_MAX_FABRIC_SYSTEM_UPGRADE_PARAM_5
#define DNXF_DATA_MAX_FABRIC_SYSTEM_UPGRADE_PARAM_5 (100000)

#endif 

#define DNXF_DATA_MAX_FABRIC_SYSTEM_UPGRADE_PARAM_7 (1)
#ifdef BCM_DNXF1_SUPPORT

#undef DNXF_DATA_MAX_FABRIC_SYSTEM_UPGRADE_PARAM_7
#define DNXF_DATA_MAX_FABRIC_SYSTEM_UPGRADE_PARAM_7 (100)

#endif 

#define DNXF_DATA_MAX_FABRIC_REGRESSION_MINIMUM_SYSTEM_REF_CLK (1)
#ifdef BCM_DNXF1_SUPPORT

#undef DNXF_DATA_MAX_FABRIC_REGRESSION_MINIMUM_SYSTEM_REF_CLK
#define DNXF_DATA_MAX_FABRIC_REGRESSION_MINIMUM_SYSTEM_REF_CLK (1200000)

#endif 




#endif 

