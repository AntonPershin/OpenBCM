/*  Feature  : Broadscan
 *
 *  Usage    : BCM.0> cint bsc_vxlan_5Tuple_VNIDRangeCheck_export_remote.c
 *
 *  config   : broadscan_config.bcm
 *
 *  Log file : bsc_vxlan_5Tuple_VNIDRangeCheck_export_remote_log.txt
 *  
 *  Test Topology :
 *
 *                   +------------------------------+ 
 *                   |                              |
 *                   |                              |
 *                   |                              |
 *  ingress_port     |                              |  Egress Port (Local CPU)
 *  +----------------+          SWITCH              +------------------------+
 *                   |                              |
 *                   |                              |
 *                   |                              | 
 *                   |                              |
 *                   |                              |
 *                   +------------------------------+
 *
 *  Summary:
 *  ========
 *  This CINT configures Broadscan Engine to export a record to remote collector when packets with VNID 
 *  is between any of the two ranges (0x345550-0x345770) and (0x365660-0x365670) are recieved on a ingress port.
 *  Flow Selection is composed of 5 tuple. We use CPU port as remote collector in this case.
 * 
 *   Make a note that SDK comes with two utilities.
 *  1. "ftrmon" which is Flow tracker Monitoring which can be used for local CPU is used as collector over DMA
 *  2. "ftrmon" which is Flow tracker Remote Monitoring can be used when local CPU is used as remote collector
 *      with IFFIX encapsulation.
 *
 *  Both the utilties will help us decode the export packets. Especially ftrmon will help user to decode
 *  IPFIX header along with records.
 *
 *  Detailed steps done in the CINT script:
 *  =======================================
 *    1) Step1 - Test Setup (Done in test_setup()):
 *    =============================================
 *      a) Select one ingress port configure it in Loopback mode.
 *      b) Start "ftrmon" utility to decode recieved IPFX packet which has export record
 *
 *    2) Step2 - Configuration 
 *    ===================================================================================
 *      a) Flow tracker checker create
 *      b) Add an action to flow check
 *      c) Setup flow group (Done in broadscan_flow_group_setup())
 *      d) Attach Flow checker to Flow group
 *      e) Setup forwarding path for Collector (Done in broadscan_collector_setup()):
 *      f) Create collector with all IPFIX encapsulation details (Done in broadscan_collector_create()).
 *      g) Validate and Install template (broadscan_template_install()).
 *      h) Attach template and collector to Group
 *      i) Create Flow Selection (broadscan_flow_selection())
 *      j) Set Trigger for Flow export
 *
 *    3) Step3 - Verification (verify())
 *    =======================================================================
 *      a) Transmit two of the below IPV4 packet on ingress_port.
 *        Packet:
 *        ======
 *       0000 0000 0002 0000 0000 2222 8100 0016 
 *       0800 4500 0064 0001 0000 1011 D4D4 0A0A
 *       0A01 C0A8 0101 FFFF 2118 0050 0000 3974 
 *       3101 3456 6717 0000 0000 11BB 0000 0000 
 *       11AA 8100 0015 0800 4500 002E 0000 0000
 *       40FF AFCB 0A00 0001 C000 0005 0001 0203
 *       0405 0607 0809 0A0B 0C0D 0E0F 1011 1213
 *       1415 1617 1819
 *
 *      b) Expected Result:
 *      ===================
 *      After Step 11.a, the packet flow will be learnt as a part of flow selection
 *      and this can be see as a part of broadscan_stat_check() which is part of the
 *      verification step as below.
 *
 *     +++++++++++++++++++++++++++++++++++++++++++++++++++++
 *     Printing Group stats for Group Id : = 1000
 *      bcm_flowtracker_group_stat_t group_stats = {
 *              uint64 flow_exceeded_count = {0x00000000 0x00000000}
 *              uint64 flow_missed_count = {0x00000000 0x00000000}
 *              uint64 flow_aged_out_count = {0x00000000 0x00000000}
 *              uint64 flow_learnt_count = {0x00000000 0x00000001}
 *              uint64 flow_meter_exceeded_count = {0x00000000 0x00000000}
 *     int $$ = 0 (0x0)
 *     +++++++++++++++++++++++++++++++++++++++++++++++++++++
 *
 *      In addtion to that it is expected thet 'ftrmon' utility decode the recieved IPFIX packet
 *      and display the below information.
 *
 *   [bcmFtRMon.0]
 *   [bcmFtRMon.0]Packet[1]: Total 1
 *   [bcmFtRMon.0]*************************************************
 *   [bcmFtRMon.0]0000: 00 00 00 00 00 c0 00 00
 *   [bcmFtRMon.0]0001: 00 00 00 f0 81 00 06 00
 *   [bcmFtRMon.0]0002: 08 00 45 84 00 ac 00 00
 *   [bcmFtRMon.0]0003: 00 00 09 11 69 79 0a 82
 *   [bcmFtRMon.0]0004: 56 2a 0a 82 b0 0a 1f 91
 *   [bcmFtRMon.0]0005: 08 07 00 98 3e 75 00 0a
 *   [bcmFtRMon.0]0006: 00 90 00 00 00 00 00 00
 *   [bcmFtRMon.0]0007: 00 00 00 00 00 01 1e fe
 *   [bcmFtRMon.0]0008: 00 80 01 d0 03 e8 00 08
 *   [bcmFtRMon.0]0009: 00 00 00 00 00 00 00 00
 *   [bcmFtRMon.0]0010: 00 00 00 00 00 00 00 00
 *   [bcmFtRMon.0]0011: 00 00 00 00 00 00 00 00
 *   [bcmFtRMon.0]0012: 00 00 00 00 00 00 00 00
 *   [bcmFtRMon.0]0013: 00 00 00 00 00 00 00 00
 *   [bcmFtRMon.0]0014: 11 21 18 ff ff c0 a8 01
 *   [bcmFtRMon.0]0015: 01 0a 0a 0a 01 00 00 00
 *   [bcmFtRMon.0]0016: 00 01 00 00 00 00 00 00
 *   [bcmFtRMon.0]0017: 00 01 00 00 00 00 00 00
 *   [bcmFtRMon.0]0018: 00 00 00 00 00 00 00 00
 *   [bcmFtRMon.0]0019: 00 00 00 00 00 00 00 00
 *   [bcmFtRMon.0]0020: 00 00 00 00 00 00 00 00
 *   [bcmFtRMon.0]0021: 00 00 00 00 00 00 00 00
 *   [bcmFtRMon.0]0022: 00 00 00 00 00 00 00 00
 *   [bcmFtRMon.0]0023: 00 00 00 00 00 00 00 00
 *   [bcmFtRMon.0]0024: 00 00 ee ee ee ee ee ee
 *   [bcmFtRMon.0]*************************************************
 *   [bcmFtRMon.0]Packet[1]:
 *   Packet[1]:   Ethernet: dst<00:00:00:00:00:c0> src<00:00:00:00:00:f0> Tagged Packet ProtID<0x8100> Ctrl<0x0600> Internet Protocol
 *    (IP)
 *    Packet[1]:   IP: V(4) src<10.130.86.42> dst<10.130.176.10> hl<5> service-type<132> tl<172> id<0> frg-off<0> ttl<9> > chk-sum<0x6
 *    979>
 *    [bcmFtRMon.0]*************************************************
 *    [bcmFtRMon.0]IPFIX version = 10 (0x0a)
 *    [bcmFtRMon.0]IPFIX message length = 144 (0x90)
 *    [bcmFtRMon.0]IPFIX export timestamp = 00 (0x00)
 *    [bcmFtRMon.0]IPFIX sequence number = 00 (0x00)
 *    [bcmFtRMon.0]IPFIX observation domain id = 01 (0x01)
 *    [bcmFtRMon.0]*************************************************
 *    [bcmFtRMon.0]*************************************************
 *    [bcmFtRMon.0]IPFIX data set # 01, set_id = 7934 (0x1efe) record length = 128
 *    [bcmFtRMon.0]Template Id matching with set id 7934 is 0 and num of elements = 11
 *    [bcmFtRMon.0]Template Id:  0 Info Element( 0) = 15 (            Reserved) Size = 02
 *    [bcmFtRMon.0]Template Id:  0 Info Element( 1) = 14 (    FlowtrackerGroup) Size = 02
 *    [bcmFtRMon.0]Template Id:  0 Info Element( 2) = 15 (            Reserved) Size = 42
 *    [bcmFtRMon.0]Template Id:  0 Info Element( 3) =  6 (          IPProtocol) Size = 01
 *    [bcmFtRMon.0]Template Id:  0 Info Element( 4) =  5 (           L4DstPort) Size = 02
 *    [bcmFtRMon.0]Template Id:  0 Info Element( 5) =  4 (           L4SrcPort) Size = 02
 *    [bcmFtRMon.0]Template Id:  0 Info Element( 6) =  1 (             DstIPv4) Size = 04
 *    [bcmFtRMon.0]Template Id:  0 Info Element( 7) =  0 (             SrcIPv4) Size = 04
 *    [bcmFtRMon.0]Template Id:  0 Info Element( 8) = 15 (            Reserved) Size = 09
 *    [bcmFtRMon.0]Template Id:  0 Info Element( 9) =  7 (            PktCount) Size = 04
 *    [bcmFtRMon.0]Template Id:  0 Info Element(10) = 15 (            Reserved) Size = 52
 *    [bcmFtRMon.0]Info Element:: 15 (            Reserved) | Size: 02 | Value: (????)
 *    [bcmFtRMon.0]Info Element:: 14 (    FlowtrackerGroup) | Size: 02 | Value: 0x03e8(1000)
 *    [bcmFtRMon.0]Info Element:: 15 (            Reserved) | Size: 42 | Value: (????)
 *    [bcmFtRMon.0]Info Element:: 06 (          IPProtocol) | Size: 01 | Value: 0x11(17)
 *    [bcmFtRMon.0]Info Element:: 05 (           L4DstPort) | Size: 02 | Value: 0x2118(8472)
 *    [bcmFtRMon.0]Info Element:: 04 (           L4SrcPort) | Size: 02 | Value: 0xffff(65535)
 *    [bcmFtRMon.0]Info Element:: 01 (             DstIPv4) | Size: 04 | Value: (192.168.1.1)
 *    [bcmFtRMon.0]Info Element:: 00 (             SrcIPv4) | Size: 04 | Value: (10.10.10.1)
 *    [bcmFtRMon.0]Info Element:: 15 (            Reserved) | Size: 09 | Value: (????)
 *    [bcmFtRMon.0]Info Element:: 07 (            PktCount) | Size: 04 | Value: 0x00000001(00000001)
 *    [bcmFtRMon.0]Info Element:: 15 (            Reserved) | Size: 52 | Value: (????)
 *    [bcmFtRMon.0]*************************************************
 */

cint_reset();

bcm_port_t ingress_port;
const int BSCAN_MAX_INFO_ELEMENTS = 40;
const int BSCAN_NUM_EXPORT_ELEMENTS = 41;
int fte_export_profile_id=-1;

/* This function is written so that hardcoding of port 
 * numbers in Cint scripts is removed. This function gives
 * required number of ports
 */
bcm_error_t portNumbersGet(int unit, int *port_list, int num_ports)
{

	int i=0,port=0,rv=BCM_E_NONE;
	bcm_port_config_t configP;
	bcm_pbmp_t ports_pbmp;

	rv = bcm_port_config_get(unit,&configP);
	if(BCM_FAILURE(rv)) {
		printf("\nError in retrieving port configuration: %s.\n",bcm_errmsg(rv));
		return rv;
	}

	ports_pbmp = configP.e;
	for (i= 1; i < BCM_PBMP_PORT_MAX; i++) {
		if (BCM_PBMP_MEMBER(&ports_pbmp,i)&& (port < num_ports)) {
			port_list[port]=i;
			port++;
		}
	}

	if (( port == 0 ) || ( port != num_ports )) {
		printf("portNumbersGet() failed \n");
		return -1;
	}

	return BCM_E_NONE;

}

/* 
 * Configures ingress port in loopback mode 
 */
bcm_error_t ingress_port_setup(int unit, bcm_port_t port)
{
	bcm_field_qset_t  qset;
	bcm_field_group_t group;
	bcm_field_entry_t entry;

	BCM_IF_ERROR_RETURN(bcm_port_loopback_set(unit, port, BCM_PORT_LOOPBACK_MAC));

	return BCM_E_NONE;
}

/*   Select one ingress port and configure them in 
 *   Loopback mode. Start flow tracker remote monitoring application.
 *   Ingress port setup is done in ingress_port_setup(). 
 */
bcm_error_t test_setup(int unit)
{
	int port_list[1];

	if (BCM_E_NONE != portNumbersGet(unit, port_list, 1)) {
		printf("portNumbersGet() failed\n");
		return -1;
	}

	ingress_port = port_list[0];

	if (BCM_E_NONE != ingress_port_setup(unit, ingress_port)) {
		printf("ingress_port_setup() failed for port %d\n", ingress_port);
		return -1;
	}

        /* "ftrmon" is flow tracker remote monitoring tool like a packet watcher
         * tool for processing remote collector IPFIX packets (received at CPU dest port)
         * can be accessed using the ?ftrmon? diag command.
         */
        bshell(unit, "ftrmon start");
        bshell(unit, "ftrmon report +decode");
        bshell(unit, "ftrmon report +count");
        bshell(unit, "counter interval=1000");

	return BCM_E_NONE;
}

/*     Trasmits the packet from ingress port
 *     Checks the packets ingress using "show counters"
 *     Also checks Broadscan counters.
 */
int 
verify(int unit, bcm_flowtracker_group_t flow_group_id)
{
	char   str[512];
	int rv = BCM_E_NONE;
	bshell(unit, "hm ieee");
	printf("Transmiting  packet on ingress_port:%d\n", ingress_port);
	snprintf(str, 512, "tx 2 pbm=%d 
			data=0x00000000000200000000222281000016080045000064000100001011D4D40A0A0A01C0A80101FFFF21180050000039743101345667170000000011BB0000000011AA8100001508004500002E0000000040FFAFCB0A000001C0000005000102030405060708090A0B0C0D0E0F10111213141516171819;
		sleep 1", ingress_port);
	bshell(unit, str);
	printf("Executing 'show c'\n");
	bshell(unit, "show c");
	rv = broadscan_stat_check(unit, flow_group_id);

	if (BCM_FAILURE(rv)) {
		printf("Failed to fetch Group stats for group: %d\n", flow_group_id);
		return rv;
	}

	return rv;
}

/* Flow selection in Broadscan is done with the help of flex key gen logic 
 * which is very similar to flexible Field processor. Flow selection consists 
 * of two stages. Flow Preselection and flow key selection.
 */
int
broadscan_flow_selection(int unit, int *ftfp_group, bcm_flowtracker_group_t flow_group_id,
			int ipprot, int vnid)
{
	int rv = BCM_E_NONE;
	bcm_field_entry_t presel_eid;     
	bcm_field_presel_t ftfp_presel_id1;
	bcm_field_group_config_t ftfp_group_config;
	bcm_field_entry_t ftfp_entry; 

	/* STAGE 1 ==> Flow Preselection Stage*/

	/* Presel to select Vxlan IPv4 packet formats */
	rv = bcm_field_presel_create(unit, &ftfp_presel_id1);
	if (BCM_FAILURE(rv)) {
		printf("\n Failed to create a presel =%d\n", rv);
		return rv;
	}
	presel_eid = ftfp_presel_id1 | BCM_FIELD_QUALIFY_PRESEL;
	BCM_IF_ERROR_RETURN(bcm_field_qualify_Stage(unit, presel_eid, 
				bcmFieldStageIngressFlowtracker));
        BCM_IF_ERROR_RETURN(bcm_field_qualify_PktType(unit, presel_eid,
				 bcmFieldPktTypeIp4Vxlan));


	/* STAGE 2 ==> Flow key selection stage*/

	bcm_field_group_config_t_init(&ftfp_group_config);
	ftfp_group_config.flags |= BCM_FIELD_GROUP_CREATE_WITH_PRESELSET;
	BCM_FIELD_PRESEL_ADD(ftfp_group_config.preselset, ftfp_presel_id1);

	BCM_FIELD_QSET_INIT(ftfp_group_config.qset);
	BCM_FIELD_QSET_ADD(ftfp_group_config.qset, bcmFieldQualifyStageIngressFlowtracker);
	BCM_FIELD_QSET_ADD(ftfp_group_config.qset, bcmFieldQualifyOuterVlanId);
	BCM_FIELD_QSET_ADD(ftfp_group_config.qset, bcmFieldQualifyVlanFormat);
	BCM_FIELD_QSET_ADD(ftfp_group_config.qset, bcmFieldQualifyInnerVlanId);
	BCM_FIELD_QSET_ADD(ftfp_group_config.qset, bcmFieldQualifyIpProtocol);
	BCM_FIELD_QSET_ADD(ftfp_group_config.qset, bcmFieldQualifyVxlanNetworkId);
	BCM_FIELD_QSET_ADD(ftfp_group_config.qset, bcmFieldQualifyVxlanHeaderBits8_31);
	BCM_FIELD_QSET_ADD(ftfp_group_config.qset, bcmFieldQualifyVxlanHeaderBits56_63);
	BCM_FIELD_QSET_ADD(ftfp_group_config.qset, bcmFieldQualifyVxlanFlags);
	BCM_FIELD_QSET_ADD(ftfp_group_config.qset, bcmFieldQualifyInPort);
	BCM_FIELD_QSET_ADD(ftfp_group_config.qset, bcmFieldQualifyInnerSrcIp);
	BCM_FIELD_QSET_ADD(ftfp_group_config.qset, bcmFieldQualifyInnerIpProtocol);
	BCM_FIELD_QSET_ADD(ftfp_group_config.qset, bcmFieldQualifyInnerTtl);
	BCM_FIELD_QSET_ADD(ftfp_group_config.qset, bcmFieldQualifyInnerL4DstPort);
	BCM_FIELD_QSET_ADD(ftfp_group_config.qset, bcmFieldQualifyInnerL4SrcPort);
	ftfp_group_config.mode = bcmFieldGroupModeAuto;
	rv = bcm_field_group_config_create(unit, &ftfp_group_config);
	if (BCM_FAILURE(rv)) {
		printf("\n Failed to create a field group =%d\n", rv);
		return rv;
	}
	*ftfp_group = ftfp_group_config.group;

	/* Create an entry in Flow tracker FP gorup */
	BCM_IF_ERROR_RETURN(bcm_field_entry_create(unit, *ftfp_group, &ftfp_entry));
        BCM_IF_ERROR_RETURN(bcm_field_qualify_VxlanNetworkId(unit, ftfp_entry, vnid, 0xffffff));
	BCM_IF_ERROR_RETURN(bcm_field_qualify_IpProtocol(unit, ftfp_entry, ipprot, 0xff)); 
	BCM_IF_ERROR_RETURN(bcm_field_action_add(unit, ftfp_entry, 
					bcmFieldActionFlowtrackerGroupId, flow_group_id, 0));
	rv =  bcm_field_entry_install(unit, ftfp_entry);
	if (BCM_FAILURE(rv)) {
		printf("\n Failed to create a field group entry with error =%d\n", rv);
		return rv;
	}

	return rv;
}


/* Flowtracker Group is the prime object in flow tracking which identifies 
 * what to track, how to track ,what to export and when to export. 
 * All major flow functions  like aging, metering, learning is associated with flow group.
 * This function does the following
 * 	Creates Flow Gorup
 * 	Add Max limit for Flow Learning
 *	Sets Tracking parameters for Flow Group
 *	Sets Age time to max
 */	
int
broadscan_flow_group_setup(int unit, int flow_group_id, int flow_gorup_options, 
		bcm_flowtracker_group_info_t flow_group_info,
		bcm_flowtracker_tracking_param_info_t *traking_param_list, 
		int num_tracking_list, int flow_limit)
{
	int rv = BCM_E_NONE;

	/* Creating Flow TRacker Group */
	rv = bcm_flowtracker_group_create (unit, flow_gorup_options, &flow_group_id, &flow_group_info);
	if (BCM_FAILURE(rv)) {
		printf("\n Failed to create a flow tracker group =%d\n", rv);
		return rv;
	}  

	/* Configuring max number of flows for this group */
	rv = bcm_flowtracker_group_flow_limit_set(unit, flow_group_id, flow_limit);
	if (BCM_FAILURE(rv)) {
		printf("\n Failed to set max limit for a group =%d\n", rv);
		return rv;
	}  

	/* Configure tracking parameters for this group */
	rv = bcm_flowtracker_group_tracking_params_set(unit, flow_group_id, num_tracking_list, 
			*traking_param_list);
	if (BCM_FAILURE(rv)) {
		printf("\n Failed to set tracking params =%d\n", rv);
		return rv;
	}  
	/* Setting Flow grouop Age time to max for debugging */
	rv = bcm_flowtracker_group_age_timer_set(unit, flow_group_id, 86400000);
	if (BCM_FAILURE(rv)) {
		printf("\n Failed to set age limit to flow group =%d\n", rv);
		return rv;
	}
	return rv;
}

/* Flow checkers helps to check the flow with some arithmetic checks and operations. 
 * Based on the outcome of that check, an action can be triggered.
 * This function does the following
 *  	Created Flow Check
 *  	Adds specific actions when the check results positive
 *  	Also sets what needs to be exported in case the result is positive
 */

int 
broadscan_add_check(int unit, int check_options, int min_value, int max_value, 
		bcm_flowtracker_tracking_param_type_t check_track_param, 
		bcm_flowtracker_check_operation_t check_operation, 
		bcm_flowtracker_check_action_info_t check_action_info, 
		bcm_flowtracker_check_t check_id)
{

	int rv = BCM_E_NONE;
	/* Flowtracker check information. */
	bcm_flowtracker_check_info_t check_info;
	bcm_flowtracker_check_info_t_init(&check_info);
	check_info.param = check_track_param;
	check_info.min_value = min_value;
	check_info.max_value = max_value;
	check_info.operation = check_operation;

	/* Create a flow check */ 
	rv =  bcm_flowtracker_check_create(unit, check_options, check_info, &check_id);
	if (BCM_FAILURE(rv)) {
		printf("\n Failed to setup flow check =%d\n", rv);
		return rv;
	}  
	/* Add an action to the flow check */
	rv =  bcm_flowtracker_check_action_info_set(unit, check_id, check_action_info);
	if (BCM_FAILURE(rv)) {
		printf("\n Failed to add flow action =%d\n", rv);
		return rv;
	}  

	return rv;

}

struct fte_export_element_map_s {
	bcm_flowtracker_tracking_param_type_t tracking_param;
	bcm_flowtracker_export_element_type_t export_element;
	int data_size;
};
fte_export_element_map_s  fte_export_element_maps[BSCAN_NUM_EXPORT_ELEMENTS] =  {
    { bcmFlowtrackerTrackingParamTypeSrcIPv4,           bcmFlowtrackerExportElementTypeSrcIPv4,           4,  },
    { bcmFlowtrackerTrackingParamTypeDstIPv4,           bcmFlowtrackerExportElementTypeDstIPv4,           4,  },
    { bcmFlowtrackerTrackingParamTypeL4SrcPort,         bcmFlowtrackerExportElementTypeL4SrcPort,         2,  },
    { bcmFlowtrackerTrackingParamTypeL4DstPort,         bcmFlowtrackerExportElementTypeL4DstPort,         2,  },
    { bcmFlowtrackerTrackingParamTypeSrcIPv6,           bcmFlowtrackerExportElementTypeSrcIPv6,           16, },
    { bcmFlowtrackerTrackingParamTypeDstIPv6,           bcmFlowtrackerExportElementTypeDstIPv6,           16, },
    { bcmFlowtrackerTrackingParamTypeIPProtocol,        bcmFlowtrackerExportElementTypeIPProtocol,        1,  },
    { bcmFlowtrackerTrackingParamTypePktCount,          bcmFlowtrackerExportElementTypePktCount,          4,  },
    { bcmFlowtrackerTrackingParamTypeByteCount,         bcmFlowtrackerExportElementTypeByteCount,         4,  },
    { bcmFlowtrackerTrackingParamTypeVRF,               bcmFlowtrackerExportElementTypeVRF,               2,  },
    { bcmFlowtrackerTrackingParamTypeTTL,               bcmFlowtrackerExportElementTypeTTL,               1,  },
    { bcmFlowtrackerTrackingParamTypeIPLength,          bcmFlowtrackerExportElementTypeIPLength,          2,  },
    { bcmFlowtrackerTrackingParamTypeIP6Length,         bcmFlowtrackerExportElementTypeIP6Length,         2,  },
    { bcmFlowtrackerTrackingParamTypeTcpWindowSize,     bcmFlowtrackerExportElementTypeTcpWindowSize,     2,  },
    { bcmFlowtrackerTrackingParamTypeDosAttack,         bcmFlowtrackerExportElementTypeDosAttack,         4,  },
    { bcmFlowtrackerTrackingParamTypeVxlanNetworkId,    bcmFlowtrackerExportElementTypeVxlanNetworkId,    3,  },
    { bcmFlowtrackerTrackingParamTypeNextHeader,        bcmFlowtrackerExportElementTypeNextHeader,        1,  },
    { bcmFlowtrackerTrackingParamTypeHopLimit,          bcmFlowtrackerExportElementTypeHopLimit,          1,  },
    { bcmFlowtrackerTrackingParamTypeInnerSrcIPv4,      bcmFlowtrackerExportElementTypeInnerSrcIPv4,      4,  },
    { bcmFlowtrackerTrackingParamTypeInnerDstIPv4,      bcmFlowtrackerExportElementTypeInnerDstIPv4,      4,  },
    { bcmFlowtrackerTrackingParamTypeInnerL4SrcPort,    bcmFlowtrackerExportElementTypeInnerL4SrcPort,    2,  },
    { bcmFlowtrackerTrackingParamTypeInnerL4DstPort,    bcmFlowtrackerExportElementTypeInnerL4DstPort,    2,  },
    { bcmFlowtrackerTrackingParamTypeInnerSrcIPv6,      bcmFlowtrackerExportElementTypeInnerSrcIPv6,      16, },
    { bcmFlowtrackerTrackingParamTypeInnerDstIPv6,      bcmFlowtrackerExportElementTypeInnerDstIPv6,      16, },
    { bcmFlowtrackerTrackingParamTypeInnerIPProtocol,   bcmFlowtrackerExportElementTypeInnerIPProtocol,   1,  },
    { bcmFlowtrackerTrackingParamTypeInnerTTL,          bcmFlowtrackerExportElementTypeInnerTTL,          1,  },
    { bcmFlowtrackerTrackingParamTypeInnerIPLength,     bcmFlowtrackerExportElementTypeInnerIPLength,     2,  },
    { bcmFlowtrackerTrackingParamTypeInnerNextHeader,   bcmFlowtrackerExportElementTypeInnerNextHeader,   1,  },
    { bcmFlowtrackerTrackingParamTypeInnerHopLimit,     bcmFlowtrackerExportElementTypeInnerHopLimit,     1,  },
    { bcmFlowtrackerTrackingParamTypeInnerIP6Length,    bcmFlowtrackerExportElementTypeInnerIP6Length,    2,  },
    { bcmFlowtrackerTrackingParamTypeTcpFlags,          bcmFlowtrackerExportElementTypeTcpFlags,          1,  },
    { bcmFlowtrackerTrackingParamTypeOuterVlanTag,      bcmFlowtrackerExportElementTypeOuterVlanTag,      2,  },
    { bcmFlowtrackerTrackingParamTypeTimestampNewLearn,      bcmFlowtrackerExportElementTypeTimestampNewLearn,      6,  },
    { bcmFlowtrackerTrackingParamTypeTimestampFlowStart,      bcmFlowtrackerExportElementTypeTimestampFlowStart,      6,  },
    { bcmFlowtrackerTrackingParamTypeTimestampFlowEnd,      bcmFlowtrackerExportElementTypeTimestampFlowEnd,      6,  },
    { bcmFlowtrackerTrackingParamTypeTimestampCheckEvent1,      bcmFlowtrackerExportElementTypeTimestampCheckEvent1,      6,  },
    { bcmFlowtrackerTrackingParamTypeTimestampCheckEvent2,      bcmFlowtrackerExportElementTypeTimestampCheckEvent2,      6,  },
    { bcmFlowtrackerTrackingParamTypeInnerDosAttack,   bcmFlowtrackerExportElementTypeInnerDosAttack,      4,  },
    { bcmFlowtrackerTrackingParamTypeTunnelClass,      bcmFlowtrackerExportElementTypeTunnelClass,      3,  },
    { bcmFlowtrackerTrackingParamTypeFlowtrackerCheck,      bcmFlowtrackerExportElementTypeFlowtrackerCheck,      2,  },
};
int 
fte_tracking_param_xlate(int unit,
		bcm_flowtracker_tracking_param_type_t elem,
		uint32 *size,
		bcm_flowtracker_export_element_type_t *info_elem)
{
	int ix;

	for (ix = 0; ix < BSCAN_NUM_EXPORT_ELEMENTS; ix++) {
		if (fte_export_element_maps[ix].tracking_param == elem) {
			*info_elem = fte_export_element_maps[ix].export_element;
			*size = fte_export_element_maps[ix].data_size;
			break;
		}
	}

	return BCM_E_NONE;
} 


/* Broadscan has debug counter that are avaiable for Flow group
 * Below funtion helps retrieve the stats for debugging
 */
int 
broadscan_stat_check(int unit, bcm_flowtracker_group_t flow_group_id)
{
	int rv = BCM_E_NONE;
	bcm_flowtracker_group_stat_t group_stats;
	bcm_flowtracker_group_stat_t_init(&group_stats);
	rv = bcm_flowtracker_group_stat_get(unit, flow_group_id, &group_stats);
	if (BCM_FAILURE(rv)) {
		printf("Failed to fetch Group stats for group: %d\n", flow_group_id);
		return rv;
	}
	printf("////////////////////////////////////////////////////////////\n");
	printf("Printing Group stats for Group Id : = %d\n", flow_group_id);
	print group_stats;
	printf("////////////////////////////////////////////////////////////\n");
	return rv;
}

/* The template is a handshake between collector and exporter on how the 
 * exported data will look like. Template provides the following information.
 *   1. Key of flow to be tracked
 *   2. Associated data to be exported of tracked flow.
 *   3. Order in which flow information(Record) to be sent.
 * Based on the above information, SW will try to allocate HW resources 
 * As the order of how data exported is also very important, SW will 
 * have to make sure that same order is maintained in HW. To address this 
 * SDK will validate if template can be written in the hardware in the 
 * exact order as user has asked for. If that is not possible then SDK 
 * will reconfigure the template according to hardware configuration 
 * and updated template will be sent to user. Also make a note that User 
 * application over SDK should work as an Exporter which shares template 
 * information with collector using template IPFIX messages.
 * This Function does following
 * 	Validates the temaplate
 * 	Creates a template 
 */
int 
broadscan_template_install(int unit,
		bcm_flowtracker_group_t flow_group_id,
		bcm_collector_t collector_id,
		bcm_flowtracker_export_template_t *template_id,
		uint16 fte_set_id)
{

	int ix, elem, rv = BCM_E_NONE;
	uint32 options = 0x0;
	int max_in_export_elements = 0;
	int max_out_export_elements = 0;
	int actual_out_export_elements = 0;
	bcm_flowtracker_tracking_param_info_t tracking_params[BSCAN_MAX_INFO_ELEMENTS];
	bcm_flowtracker_export_element_info_t export_elems_ip[BSCAN_MAX_INFO_ELEMENTS];
	bcm_flowtracker_export_element_info_t export_elems_op[BSCAN_MAX_INFO_ELEMENTS];

	rv = bcm_flowtracker_group_tracking_params_get(unit,
			flow_group_id,
			BSCAN_MAX_INFO_ELEMENTS,
			tracking_params,
			&max_in_export_elements);
	if (BCM_FAILURE(rv)) {
		printf("Failed to fetch tracking params for group: %d\n", flow_group_id);
		return rv;
	}  

	/* Init ip/op element */
	for (ix = 0; ix < BSCAN_MAX_INFO_ELEMENTS; ix++) {
		export_elems_ip[ix].data_size = 0;
		export_elems_ip[ix].element = bcmFlowtrackerExportElementTypeReserved;

		export_elems_op[ix].data_size = 0;
		export_elems_op[ix].element = bcmFlowtrackerExportElementTypeReserved;
	}

	for (ix = 0; ix < max_in_export_elements; ix++) {
		rv = fte_tracking_param_xlate(unit,
				tracking_params[ix].param,
				&(export_elems_ip[ix].data_size),
				&(export_elems_ip[ix].element));
		if (BCM_FAILURE(rv)) {
			printf ("translating tracking param %d to export element failed\n", tracking_params[ix].param);
			return rv;
		}
	}

	/* Add flowgroup to info elems  */
	export_elems_ip[ix].element = bcmFlowtrackerExportElementTypeFlowtrackerGroup;
	export_elems_ip[ix].data_size = 2;
	max_in_export_elements++;
	/* Get max number of output elements */
	rv = bcm_flowtracker_export_template_validate(unit,
			flow_group_id,
			max_in_export_elements,
			export_elems_ip,
			0,
			NULL,
			&max_out_export_elements);
	if (BCM_FAILURE(rv)) {
		printf ("validate template for template with flow_group_id = %d Failed to get MAX\n", *template_id);
		return rv;
	}
	/* Validates the template */
	rv = bcm_flowtracker_export_template_validate(unit,
			flow_group_id,
			max_in_export_elements,
			export_elems_ip,
			max_out_export_elements,
			export_elems_op,
			&actual_out_export_elements);
	if (BCM_FAILURE(rv)) {
		printf ("validate template for template with flow_group_id = %d\n", *template_id);
		return rv;
	}

	printf("***********************************\n");
	printf("max_in_export_elements %d  max_out_export_elements %d actual_out_export_elements %d \r\n", max_in_export_elements, max_out_export_elements, actual_out_export_elements);
	printf("Input information elements: \n");
	for (ix = 0; ix < max_in_export_elements; ix++) {
		elem = (export_elems_ip[ix].element);
		printf("\tinput info element (%d): elem = %d and size = %d\n", ix, elem, export_elems_ip[ix].data_size);
	}
	printf("***********************************\n");


	printf("***********************************\n");
	printf("Output information elements: \n");
	for (ix = 0; ix < actual_out_export_elements; ix++) {
		elem = (export_elems_op[ix].element);
		printf("\toutput info element (%d): elem = %d and size = %d\n", ix, elem, export_elems_op[ix].data_size);
	}
	printf("***********************************\n");

	/* Created Export Templete */
	rv = bcm_flowtracker_export_template_create(unit, options,
			*template_id,
			fte_set_id,
			actual_out_export_elements,
			export_elems_op);
	if (BCM_FAILURE(rv)) {
		printf ("creating template failed template_id = %d\n", *template_id);
		return rv;
	}

	return rv;
}                                                 


/* Broadscan can export the flows based on some user configured
 * triggers. The triggers can be configured at the flowtracker group.
 * This function will configure the trigger for a specific Flow Group.
 */
int
broadscan_set_trigger(int unit, bcm_flowtracker_group_t flow_group_id, int trigger)
{
        int rv = BCM_E_NONE;
        bcm_flowtracker_export_trigger_info_t trig_info;
        rv = bcm_flowtracker_group_export_trigger_get(unit, flow_group_id, &trig_info);
        if (BCM_FAILURE(rv)) {
                printf("\n Failed to get flow group trigger %d\n", rv);
                return rv;
        }

        BCM_FLOWTRACKER_TRIGGER_SET(trig_info, trigger);
        rv = bcm_flowtracker_group_export_trigger_set(unit, flow_group_id, &trig_info);
        if (BCM_FAILURE(rv)) {
                printf("\n Failed to set flow group trigger %d\n", rv);
                return rv;
        }

        return rv;

}


/* Setting up forwaring path for collector so that IPFIX export
 * packets from Broadscan Engine will be forwarded  to remote
 * collector reachable via collector port
 */
int
broadscan_collector_setup(int unit, bcm_vlan_t fte_coll_vlan, bcm_mac_t fte_coll_dst_mac, bcm_port_t fte_coll_port)
{
        bcm_pbmp_t        pbmp, upbmp;
        bcm_l2_addr_t     l2_addr;
        bcm_field_qset_t  qset;
        bcm_field_group_t group;
        bcm_field_entry_t entry;

        /* Create vlan to redirect export packets */
        BCM_IF_ERROR_RETURN(bcm_vlan_create(unit, fte_coll_vlan));
        BCM_PBMP_CLEAR(pbmp);
        BCM_PBMP_CLEAR(upbmp);
        BCM_PBMP_PORT_ADD(pbmp, fte_coll_port);
        BCM_IF_ERROR_RETURN(bcm_vlan_port_add(unit, fte_coll_vlan, pbmp, upbmp));

        /* Add static MAC address */
        bcm_l2_addr_t_init(&l2_addr, fte_coll_dst_mac, fte_coll_vlan);
        l2_addr.flags = BCM_L2_STATIC;
        l2_addr.port  = fte_coll_port;
        BCM_IF_ERROR_RETURN(bcm_l2_addr_add(unit, &l2_addr));

        return 0;
}

/* Creates broadscan collector with all IPFIX header details */
int
broadscan_collector_create(int unit, int collector_id, bcm_collector_info_t collector_info)
{
        int rv = BCM_E_NONE;
        uint32 options = 0;

        options = BCM_FLOWTRACKER_COLLECTOR_WITH_ID;

        rv = bcm_collector_create(unit,
                        options, &collector_id, collector_info);
        if (BCM_FAILURE(rv)) {
                printf("\n Failed to create collector ret=%d\n", rv);
                return rv;
        }

        return rv;
}

/* Main functuion to configure Broadscan Engine*/
int execute()
{
	int unit = 0; 
	int ftfp_group;	
	int rv = BCM_E_NONE;

        bshell(unit, "config show; a ; version");
 
	/* Setting up test bed */ 
	rv = test_setup(unit);   
	if (BCM_FAILURE(rv)) {
		printf("\n Failed to setup test bed =%d\n", rv);
		return rv;
	} else {
		printf ("\n !!! Test Setup Done Succesfully !!!!\r\n");
	}

        uint16 udp_dp = 8472; /* UDP dst port used for OTV */
        rv = bcm_switch_control_set(unit, bcmSwitchVxlanUdpDestPortSet, udp_dp);
        if (BCM_FAILURE(rv)) {
                printf("\n Failed to set Vxlan UDP Dest Port =%d\n", rv);
        }

	/* Flow checkers helps to check the flow with some arithmetic checks and operations. 
	 * Based on the outcome of that check, an action can be triggered.
	 * In this script we will two check for packets coming in particular two vnid ranges
	 * and increment the counter as an action */  

        /* Setting up first flow checker */
	int min_value = 0x112000; /* VNID min value for range */
	int max_value = 0x345770; /* VNID max value for range */
	bcm_flowtracker_check_t check_id_1 = 0x4000000; /* checker ID to attach it to Flow group */     
	int check_options = BCM_FLOWTRACKER_CHECK_WITH_ID;
	bcm_flowtracker_check_operation_t check_operation;
	bcm_flowtracker_tracking_param_type_t check_track_param;
	bcm_flowtracker_check_action_info_t check_action_info;
	bcm_flowtracker_check_action_info_t_init(&check_action_info);
	check_action_info.param = bcmFlowtrackerTrackingParamTypeNone;
	check_action_info.action = bcmFlowtrackerCheckActionCounterIncr; /* Action to be performed */

	check_track_param = bcmFlowtrackerTrackingParamTypeVxlanNetworkId; /* Check on VNID */
	check_operation = bcmFlowtrackerCheckOpInRange; /* Check operation which is range*/

	rv = broadscan_add_check(unit, check_options, min_value, max_value, check_track_param, 
			check_operation, check_action_info, check_id_1);
	if (BCM_FAILURE(rv)) {
		printf("\n Failed to setup a First Flow checker =%d\n", rv);
		return rv;
	} else {
		printf ("\n !!! Added First Flow checker Succesfully !!!!\r\n");
	}  							


        /* Setting up Second flow checker */
        min_value = 0x365660; /* VNID min value for range */
        max_value = 0x365670; /* VNID max value for range */
	bcm_flowtracker_check_t check_id_2= 0x4000001; /* checker ID to attach it to Flow group */     

        rv = broadscan_add_check(unit, check_options, min_value, max_value, check_track_param,
                        check_operation, check_action_info, check_id_2);
        if (BCM_FAILURE(rv)) {
                printf("\n Failed to setup a Second Flow checker =%d\n", rv);
                return rv;
        } else {
                printf ("\n !!! Added Second Flow checker Succesfully !!!!\r\n");
        }

	/* Flowtracker Group is the prime object in flow tracking which identifies 
	 * what to track, how to track ,  what to export and when to export. 
	 * All major flow functions  like aging, metering, learning is associated with flow group.*/
	int flow_group_id = 1000; /* Flow Group ID */
	int num_tracking_list = 6; /* Number of tracking params list */
	int tracking_param_tuple[5] =  {bcmFlowtrackerTrackingParamTypeSrcIPv4,
		bcmFlowtrackerTrackingParamTypeDstIPv4, 
		bcmFlowtrackerTrackingParamTypeL4SrcPort,
		bcmFlowtrackerTrackingParamTypeL4DstPort,
		bcmFlowtrackerTrackingParamTypeIPProtocol};
	bcm_flowtracker_group_info_t flow_group_info;
	bcm_flowtracker_group_info_t_init(&flow_group_info);
	bcm_flowtracker_tracking_param_info_t tracking_param_list[num_tracking_list];
	int flow_gorup_options = BCM_FLOWTRACKER_GROUP_WITH_ID;
	int flow_limit = 100; /* Maximum number of flows for this group */
	int i = 0;
	/* Add 5 Tuple as a part of tracking params */
	for (i=0; i<5; i++) {
		tracking_param_list[i].flags = BCM_FLOWTRACKER_TRACKING_PARAM_TYPE_KEY; 
		tracking_param_list[i].param = tracking_param_tuple[i];
	}
	/* Add pkt count as data for exporting in record */
	tracking_param_list[i].flags = 0; /* Zero to notify as data which will be exported */
	tracking_param_list[i].param = bcmFlowtrackerTrackingParamTypePktCount;

	rv = broadscan_flow_group_setup(unit, flow_group_id, flow_gorup_options, 
			flow_group_info, &tracking_param_list, num_tracking_list, flow_limit);
	if (BCM_FAILURE(rv)) {
		printf("\n Failed to setup a Flow Group =%d\n", rv);
		return rv;
	} else {
		printf ("\n !!! Flow Group Setup Done Succesfully !!!!\r\n");
	}  							

	/* Once the Flow group is created attach First flow checker to the group */
	rv = bcm_flowtracker_group_check_add(unit, flow_group_id, check_id_1);
	if (BCM_FAILURE(rv)) {
		printf("\n Failed to add First flow checker to a Flow Group =%d\n", rv);
		return rv;
	} else {
		printf ("\n !!! Attched First flow checker to the group Succesfully !!!!\r\n");
	}  


	/* Attach Second flow checker to the group */
	rv = bcm_flowtracker_group_check_add(unit, flow_group_id, check_id_2);
	if (BCM_FAILURE(rv)) {
		printf("\n Failed to add Second flow checker to a Flow Group =%d\n", rv);
		return rv;
	} else {
		printf ("\n !!! Attched Second flow checker to the group Succesfully !!!!\r\n");
	}  

        /* Given that we now setup Flow Groups along and tracking params,
         * We now setup a the Flow Expor Part starting up with collector setup*/

        /* Collector is a receiver of information from exporter which is generated from
         * tracking a particular flow. The collector is distinguished by its L2/L3 information.
         * The data is encapsulated into this L2/L3 header and sent mostly over UDP.*/

        /* Collector Info */
        bcm_port_t    fte_coll_port        = 0; /* Settign up CPU port as remote collector */
        bcm_mac_t     fte_coll_dst_mac     = {0x00, 0x00, 0x00, 0x00, 0x00, 0xc0};
        bcm_vlan_t    fte_coll_vlan        = 0x600;
        bcm_mac_t     fte_coll_src_mac     = {0x00, 0x00, 0x00, 0x00, 0x00, 0xf0};
        uint16        fte_coll_tpid        = 0x8100;
        bcm_ip_t      fte_coll_src_ip      = 0x0a82562a;
        bcm_ip_t      fte_coll_dst_ip      = 0x0a82b00a;
        uint8         fte_coll_dscp        = 0xE1;
        uint8         fte_coll_ttl         = 9;
        uint16        fte_coll_mtu         = 1500;
        uint16        fte_set_id           = 0x1efe;
        bcm_l4_port_t fte_coll_l4_src_port = 0x1F91;
        bcm_l4_port_t fte_coll_l4_dst_port = 0x0807;
        int           collector_id         = 0;
        bcm_collector_info_t collector_info;
        bcm_collector_export_profile_t profile_info;

        bcm_collector_info_t_init(&collector_info);
        bcm_collector_export_profile_t_init(&profile_info);

        /* Flowtracker collector information. */
        sal_memcpy(collector_info.eth.dst_mac, fte_coll_dst_mac, 6);
        sal_memcpy(collector_info.eth.src_mac, fte_coll_src_mac, 6);

        /* Ethernet encapsulation of the packet sent to collector. */
        collector_info.eth.vlan_tag_structure =
                BCM_FLOWTRACKER_COLLECTOR_ETH_HDR_SINGLE_TAGGED;
        collector_info.eth.outer_vlan_tag = fte_coll_vlan;
        collector_info.eth.outer_tpid     = fte_coll_tpid;

        /* IPv4 encapsulation of the packet sent to collector. */
        collector_info.ipv4.src_ip        = fte_coll_src_ip;
        collector_info.ipv4.dst_ip        = fte_coll_dst_ip;
        collector_info.ipv4.dscp          = fte_coll_dscp;
        collector_info.ipv4.ttl           = fte_coll_ttl;

        /* UDP encapsulation of the packet sent to collector. */
        collector_info.udp.src_port       = fte_coll_l4_src_port;
        collector_info.udp.dst_port       = fte_coll_l4_dst_port;
        collector_info.transport_type     = bcmCollectorTransportTypeIpv4Udp; /* Transport type
                                             used for exporting flow data to the collector.*/

        /* export profile */
        profile_info.wire_format = bcmCollectorWireFormatIpfix;
        profile_info.max_packet_length = fte_coll_mtu;

        /* Setting up path for IPFIX export packets towards collector */
        rv = broadscan_collector_setup(unit, fte_coll_vlan, fte_coll_dst_mac, fte_coll_port);
        if (BCM_FAILURE(rv)) {
                printf("\n Failed to setup collector =%d\n", rv);
                return rv;
        } else {
                printf ("\n !!! Collector Setup Done Succesfully !!!!\r\n");
        }

        /* Creating Collector */
        rv = broadscan_collector_create(unit, collector_id, collector_info);
        if (BCM_FAILURE(rv)) {
                printf("\n Failed to setup collector =%d\n", rv);
                return rv;
        } else {
                printf ("\n !!! Created Collector Succesfully !!!!\r\n");
        }

        /* Create Export Profile */
        rv = bcm_collector_export_profile_create(unit, 0, &fte_export_profile_id, &profile_info);
        if (rv != BCM_E_NONE) {
            printf("\n Failed to create export profile ret=%d\n", rv);
            return BCM_E_INTERNAL;
        }

	/* The template is a handshake between collector and exporter on how the exported 
	 * data will look like. Template provides the following information. 
	 * 1. Key of flow to be tracked
	 * 2. Associated data to be exported of tracked flow.
	 * 3. Order in which flow information(Record) to be sent.*/

	bcm_flowtracker_export_template_t template_id;
	rv = broadscan_template_install( unit, flow_group_id, collector_id, &template_id, fte_set_id);
	if (BCM_FAILURE(rv)) {
		printf ("Failed to setup a template (%d) failed rv = %d\n", template_id, rv);
		return rv;
	} else {
		printf ("\n !!! Template Setup done Succesfully !!!!\r\n");
	}

	/* Attach Template and Collector to Group */ 

	rv = bcm_flowtracker_group_collector_attach(unit, flow_group_id, collector_id, fte_export_profile_id, template_id);
	if (BCM_FAILURE(rv)) {
		printf ("Attaching template (%d) and collector (%d) to group (%d) failed rv = %d\n",
				template_id, collector_id, flow_group_id, rv);
		return rv;
	} else {
		printf ("\n !!! Attached Template and Collector to Group Succesfully !!!!\r\n");
	}

	/* Creating Flow Selection */
        int ipprot = 17; /*UDP */
        int vnid = 0x345667;
	rv = broadscan_flow_selection(unit, &ftfp_group, flow_group_id, ipprot, vnid); 
	if (BCM_FAILURE(rv)) {
		printf("\n Failed to create Flow Selection =%d\n", rv);
		return rv;
	} else {
		printf ("\n !!! Created Flow Selection Succesfully !!!!\r\n");
	}


        /* Set Trigger for Flow export */
        rv = broadscan_set_trigger(unit, flow_group_id, bcmFlowtrackerExportTriggerNewLearn);
        if (BCM_FAILURE(rv)) {
                printf("\n Failed to set trigger for Flow export =%d\n", rv);
                return rv;
        } else {
                printf ("\n !!! Configured Trigger for Flow export Succesfully !!!!\r\n");
        }


	rv = verify(unit, flow_group_id);
	if (BCM_FAILURE(rv)) {
		printf("\n Failed to verify =%d\n", rv);
		return rv;
	}

	return rv;
}

const char *auto_execute = (ARGC == 1) ? ARGV[0] : "YES";
if (!sal_strcmp(auto_execute, "YES")) {
  print execute();
}

