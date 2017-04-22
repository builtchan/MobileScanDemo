/*
 * AfcErrorCode.h
 *
 *  Created on: Dec 31, 2014
 *      Author: root
 */

#ifndef AFCERRORCODE_H_
#define AFCERRORCODE_H_



typedef enum
{
	/*系统服务模式 编号101-105*/
	EM_SYSTEM_ERROR_CODE_MAINTENCE_MODE = 101,    //系统维修模式
	EM_SYSTEM_ERROR_CODE_EMERGENCE_MODE = 102,    //系统紧急模式
	EM_SYSTEM_ERROR_CODE_CLOSE_MODE = 103,        //系统关闭模式
	EM_SYSTEM_ERROR_CODE_STOP_SERVICE = 104,      //系统暂停服务

	/*系统软件，配置文件，参数故障 编号：106-120*/
	EM_SYSTEM_ERROR_CODE_SOFTWARE_UPDATE = 106,   		//软件升级
	EM_SYSTEM_ERROR_CODE_PARAMETER_PRASE_FAIL = 107,    //参数解析失败
	EM_SYSTEM_ERROR_CODE_PARAMETER_UPDATE = 108,  		//参数升级
	EM_SYSTEM_ERROR_CODE_PARAMETER_ERROR = 109,   		//参数错误
	EM_SYSTEM_ERROR_CODE_DOWNLOAD_FAIL     = 110,   	//参数下载失败
	EM_SYSTEM_ERROR_CODE_SLEEP_MODE     = 111,   		//睡眠
	EM_SYSTEM_ERROR_CODE_CONFIG_ERROR     = 112,   		//配置错误
	EM_SYSTEM_ERROR_CODE_SOFT_VERSION_ERROR     = 113,  //软件版本错误

	EM_SYSTEM_ERROR_CODE_TIU_TICBOX_EMPTY     = 114,   			//车票发行单元票箱逻辑空
	EM_SYSTEM_ERROR_CODE_TIU_INVALID_TICBOX_FULL     = 115,   	//车票发行单元废票箱逻辑满
	EM_SYSTEM_ERROR_CODE_TIU_WITHDRAW_TICBOX_FULL     = 116,  	//车票发行单元回收箱逻辑满
	EM_SYSTEM_ERROR_CODE_TRU_TICBOX_FULL     = 117,  			//车票回收单元票箱逻辑满
	EM_SYSTEM_ERROR_CODE_TRU_INVALID_TICBOX_FULL     = 118,  	//车票回收单元废票箱逻辑满
	EM_SYSTEM_ERROR_CODE_BILL_SPARE_CHANGER_BOX_EMPTY = 119, 	//纸币找零箱逻辑空
	EM_SYSTEM_ERROR_CODE_BILL_CHANGER_INVALID_BOX_FULL = 120, 	//纸币找零废钞箱逻辑满
	EM_SYSTEM_ERROR_CODE_BILL_WITHDRAW_BOX_FULL = 121, 			//纸币回收箱逻辑满
	EM_SYSTEM_ERROR_CODE_COIN_LOOP_CHANGER_BOX_EMPTY = 122, 	//硬币循环找零箱逻辑空
	EM_SYSTEM_ERROR_CODE_COIN_WITHDRAW_BOX_FULL = 123, 			//硬币回收箱逻辑满

	/*系统时钟，数据库，网络，磁盘等故障，运营状态等 编号：121-129*/
	EM_SYSTEM_ERROR_CODE_LOCK_ERROR = 124,        	    	//时钟故障
	EM_SYSTEM_ERROR_CODE_NETWORK_ERROR = 125,				//与SC网络故障
	EM_SYSTEM_ERROR_CODE_NO_RUN_MODE = 126,                	//非运营中
	EM_SYSTEM_ERROR_CODE_DATABASE_FAULT = 127,              //数据库故障
	EM_SYSTEM_ERROR_CODE_DATABASE_CAPACITY_LOW = 128,       //数据库空间不足
	EM_SYSTEM_ERROR_CODE_DISK_CAPACITY_LOW = 129,           //磁盘空间不够
	EM_SYSTEM_ERROR_CODE_SHUTDOWN_OR_REBOOT = 130,          //系统关机或重启

	/*系统运营模式 编号：130-140*/
	EM_SYSTEM_ERROR_CODE_RUN_MODE_TIME_FREE = 131,           //系统时间免检
	EM_SYSTEM_ERROR_CODE_RUN_MODE_DATE_FREE = 132,           //系统日期免检
	EM_SYSTEM_ERROR_CODE_RUN_MODE_FARE_FREE = 133,           //系统车费免检
	EM_SYSTEM_ERROR_CODE_RUN_MODE_ENTRY_FREE = 134,           //系统进站免检
	EM_SYSTEM_ERROR_CODE_RUN_MODE_ENTRY_ORDER_FREE = 135,      //系统进站次序免检
	EM_SYSTEM_ERROR_CODE_RUN_MODE_EXIT_ORDER_FREE = 168,      //系统出站次序免检
	EM_SYSTEM_ERROR_CODE_RUN_MODE_EXIT_FREE = 136,      	//系统出站免检
	EM_SYSTEM_ERROR_CODE_RUN_MODE_24HOUR_RUN = 137,           //系统24小时运营
	EM_SYSTEM_ERROR_CODE_RUN_MODE_DELAY = 138,               //系统延长运营
	EM_SYSTEM_ERROR_CODE_RUN_MODE_NO_PRINT = 139,               //无打印模式
	EM_SYSTEM_ERROR_CODE_RUN_MODE_TRAINFAULT = 140,           //系统列车故障模式

	/*环境APP产生的系统无法服务或业务降级服务141-160*/
	EM_SYSTEM_ERROR_CODE_TRESPASS = 141,                        //非法入侵
	EM_SYSTEM_ERROR_CODE_LOW_POWER = 142,                   	//电量低
	EM_SYSTEM_ERROR_CODE_INTERUPT = 143,                   		//外电中断
	EM_SYSTEM_ERROR_CODE_DOORO_UNLOCKED = 145,                  //维修门关闭未锁
	EM_SYSTEM_ERROR_CODE_DOOROPENED = 146,                     	//维修门打开
	EM_SYSTEM_ERROR_CODE_URGENT = 147,                         	//紧急
	EM_SYSTEM_ERROR_CODE_POWER_ERROR = 149,                    	//电源模块故障故障
	EM_SYSTEM_ERROR_CODE_BOX_BAFFLE_UN_OPEND = 150,           	//箱子翻版未打开
	EM_SYSTEM_ERROR_CODE_PRINTER_REMOVE = 151,                 	//打印机不到位
	EM_SYSTEM_ERROR_CODE_CASH_SAFE_GATE_OPENED = 152,          	//现金安全门打开

	EM_SYSTEM_ERROR_CODE_BILL_SPARE_CHANGER_BOX_FAIL = 153,          //纸币箱找零失败
	EM_SYSTEM_ERROR_CODE_BILL_LOOP_CHANGER_BOX_FAIL = 154,          //循环纸币箱找零失败
	EM_SYSTEM_ERROR_CODE_COIN_SPARE_CHANGER_BOX_FAIL = 155,          //备用硬币箱找零失败
	EM_SYSTEM_ERROR_CODE_COIN_LOOP_CHANGER_BOX_FAIL = 156,          //循环硬币箱找零失败
	EM_SYSTEM_ERROR_CODE_COIN_BOX_REMOVE = 157,         			//硬币箱未到位
	EM_SYSTEM_ERROR_CODE_BILL_LOOP_CHANGER_BOX_EMPTY = 158, 		//纸币循环找零箱逻辑空
	EM_SYSTEM_ERROR_CODE_COIN_SPARE_CHANGER_BOX_EMPTY = 159, 		//硬币备用找零箱逻辑空
	EM_SYSTEM_ERROR_CODE_TIU_TICBOX_FAIL     = 160,   				//车票发行单元票箱提票失败

	/*系统其他故障 编号：161-165*/
	EM_SYSTEM_ERROR_CODE_OPERATOR_LOGIN = 161,            //维修业务设置TVM控制命令-操作员登录
	EM_SYSTEM_ERROR_CODE_TRADE_ERROR = 162,                  //票卡业务-故障交易
	EM_SYSTEM_ERROR_CODE_BILL_REFUND_ERROR = 163,                  //票卡业务-纸币退币失败
	EM_SYSTEM_ERROR_CODE_COIN_REFUND_ERROR = 164,                  //票卡业务-硬币退币失败

	/*设备无法服务或业务降级服务166-199*/
	EM_TVM_ERROR_CODE_VENDING_TPU_CONTINUOUS_FAIL = 166,     //售票TPU连续读写卡失败
	EM_TVM_ERROR_CODE_RECHARGE_TPU_CONTINUOUS_FAIL = 167,  //充值TPU连续写卡失败
	EM_TVM_ERROR_CODE_ENVIRONMENT_WARING = 171,                  //警报
	EM_TVM_ERROR_CODE_ISSUE_REMOVE = 172,                      //发行单元不到位
	EM_TVM_ERROR_CODE_BANKNOTE_DISPENSER_REMOVE = 173,         //纸币找零单元不到位
	EM_TVM_ERROR_CODE_BANKNOTE_IDENTIFY_REMOVE = 174,          //纸币识别单元不到位
	EM_TVM_ERROR_CODE_COIN_DISPENSER_REMOVE = 175,             //硬币单元不到位
	EM_TVM_ERROR_CODE_COIN_IDENTIFY_REMOVE = 176,              //硬币识别单元不到位
	EM_TVM_ERROR_CODE_BANKNOTE_LOOP_REMOVE = 177,              //纸币循环不到位
	EM_TVM_ERROR_CODE_COINBOX1_REMOVE = 178,                   //1#硬币钱箱不到位
	EM_TVM_ERROR_CODE_COINBOX2_REMOVE = 179,                   //2#硬币钱箱不到位
	EM_TVM_ERROR_CODE_VENDING_ONLY = 180,                      //TVM只售票
	EM_TVM_ERROR_CODE_RECHARGE_ONLY = 181,                     //TVM只充值
	EM_TVM_ERROR_CODE_QUERY_ONLY = 182,                        //TVM只查询
	EM_AG_ERROR_CODE_WITH_DRAW_REMOVE = 185,                  //回收单元不到位

	EM_AG_ERROR_CODE_ENTRY_ONLY = 186,                               //AG只进站
	EM_AG_ERROR_CODE_EXIT_ONLY = 187,                                //AG只出站


	EM_TVM_ERROR_CODE_NO_CHANGE = 189,                         //无找零
	EM_TVM_ERROR_CODE_NO_BILL_CHANGE = 190,                         //无纸币找零
	EM_TVM_ERROR_CODE_NO_COIN_CHANGE = 191,                         //无硬币找零
	EM_TVM_ERROR_CODE_NO_BILL_PAY = 192,                         //无纸币支付
	EM_TVM_ERROR_CODE_NO_COIN_PAY = 193,                         //无硬币支付
	EM_TVM_ERROR_CODE_NO_PRECARD_PAY = 194,                         //无储值卡支付
	EM_TVM_ERROR_CODE_NO_BANKCARD_PAY = 195,                         //无银行卡支付
	EM_TVM_ERROR_CODE_ONLY_BILL_PAY = 196,                         //只纸币支付
	EM_TVM_ERROR_CODE_ONLY_COIN_PAY = 197,                         //只硬币支付
	EM_TVM_ERROR_CODE_ONLY_PRECARD_PAY = 198,                         //只储值卡支付
	EM_TVM_ERROR_CODE_ONLY_BANKCARD_PAY = 199,                         //只银行卡支付

}EM_SYSTEM_ERRORCODE;

/*打印机模块故障类型*/
typedef enum {

	EM_PRINTER_PORT_ERROR = 1101,					//端口号错误
	EM_PRINTER_COMM_FAIL = 1102,					//通信错误
	EM_PRINTER_PAPER_NEARLY_OUT = 1103,				//打印机模块纸将尽
	EM_PRINTER_PAPER_OUT = 1104,					//打印机模块纸尽
	EM_PRINTER_PAPER_JAM = 1105,					//打印机卡纸
	EM_PRINTER_COVER_OPEN = 1106,					//打印机模块上盖打开
	EM_PRINTER_CUTER_ERROR = 1107,					//打印机切刀错
	EM_PRINTER_ORIGINAL_ERROR = 1108,				//打印机原始故障(通过附加数据进行显示，如： 1108(01))

}EM_PRINTER_FAULT_TYPE;

/*硬币故障类型*/
typedef enum EM_CSSCION_FAULT_TYPE_
{
	EM_CSSCOIN_FAULT_TYPE_PORT_ERROR         		= 201,//端口号错误
	EM_CSSCOIN_FAULT_TYPE_COMM_FAIL          		= 202,//通信错误
	EM_CSSCOIN_FAULT_TYPE_SENSOR_FAULT       		= 203,//传感器故障
	EM_CSSCOIN_FAULT_TYPE_ACCEPTER_FAULT     		= 204,//识别器故障
	EM_CSSCOIN_FAULT_TYPE_COMM_HOOPER_FAULT  		= 205,//HOPPER通讯故障
	EM_CSSCOIN_FAULT_TYPE_COMM_RFID_FAULT    		= 206,//RFID通讯故障
	EM_CSSCOIN_FAULT_TYPE_ExCow_FAULT        		= 207,//暂存电机故障
	EM_CSSCOIN_FAULT_TYPE_SENSOR_DIRTY       		= 208,//传感器需要维修
	EM_CSSCOIN_FAULT_TYPE_JAM_CASH           		= 209,//卡币
	EM_CSSCOIN_FAULT_TYPE_BOX_FULL           		= 210,//钱箱满
	EM_CSSCOIN_FAULT_TYPE_BOX_UNFIX			 		= 211,//钱箱未按装
	EM_CSSCOIN_FAULT_TYPE_BOX_FIX_ERROR     		= 212,//钱箱安装错误
	EM_CSSCOIN_FAULT_TYPE_HOPPER_EMPTY       		= 213,//两Hopper空
	EM_CSSCOIN_FAULT_TYPE_UPDATE_FAIL		 		= 214,//升级失败
	EM_CSSCOIN_FAULT_TYPE_ERROR              		= 215,//硬币单元单元故障
	EM_CSSCION_FAULT_TYPE_REMOVE 			 		= 216,//硬币单元单元不到位
	EM_CSSCION_FAULT_TYPE_ORIGINAL_ERROR 			= 217,//硬币单元原始故障(通过附加数据进行显示，如：217() )
}EM_CSSCION_FAULT_TYPE;

//车票发行单元故障类型
typedef enum _EM_TOKEN_ISSUE_FAULT_TYPE
{
	EM_ISSUE_PORT_ERROR = 501,				//端口号错误
	EM_ISSUE_COMM_FAIL = 502,				//通信错误
	EM_ISSUE_SENSOR_FAULT = 503,			//传感器故障
	EM_ISSUE_SENSOR_DIRTY = 504,			//传感器需要维修
	EM_ISSUE_JAM_TICKET = 505,				//卡票
	EM_ISSUE_TICKET_BOX_EMPTY = 506,		//票箱空
	EM_ISSUE_TICKET_BOX_UNFIX = 507,		//票箱未安装
	EM_ISSUE_WITHDRAW_BOX_FULL = 508,		//回收箱满
	EM_ISSUE_WITHDRAW_BOX_UNFIX = 509,		//回收箱未安装
	EM_ISSUE_INVALID_BOX_FULL = 510,		//废票箱满
	EM_ISSUE_INVALID_BOX_UNFIX = 511,		//废票箱未安装
	EM_ISSUE_TICKET_BOX_FIX_ERROR = 512,	//票箱安装错误
	EM_ISSUE_ERROR = 513,					//发行单元其他故障
	EM_ISSUE_REMOVE = 514,					//发行单元未到位
	EM_ISSUE_ORIGINAL_ERROR = 515,			//发行单元原始故障(通过附加数据进行显示，如：515() )
}EM_TOKEN_ISSUE_FAULT_TYPE;

//车票回收单元故障类型
typedef enum _EM_TICKET_RECYCLE_FAULT_TYPE_
{
	EM_REC_PORT_ERROR = 601,				//端口号错误
	EM_REC_COMM_FAIL = 602,					//通信错误
	EM_REC_RFID_COMM_FAULT = 603,			//RFID通信故障
	EM_REC_SENSOR_FAULT = 604,				//传感器故障
	EM_REC_SENSOR_DIRTY = 605,				//传感器需要维修
	EM_REC_SHUTTER_MAGNET_FAULT = 606,		//舌挡电磁铁故障
	EM_REC_MAGNET_FAULT = 607,				//其他电磁铁故障
	EM_REC_JAM_TICKET = 608,				//卡票
	EM_REC_WITHDRAW_BOX_UNFIX = 609,		//回收箱未安装
	EM_REC_WITHDRAW_BOX_FULL = 610,			//回收箱满
	EM_REC_WITHDRAW_BOX_CLOSE = 611,		//回收箱未打开
	EM_REC_WITHDRAW_BOX_UP_DOWN_FAULT = 612,//回收箱升降故障
	EM_REC_WASTE_BOX_UNFIX = 613,			//废票箱未安装
	EM_REC_WASTE_BOX_FULL = 614,			//废票箱满
	EM_REC_WASTE_BOX_CLOSE = 615,			//废票箱未打开
	EM_REC_WASTE_BOX_UP_DOWN_FAULT = 616,	//废票箱升降故障
	EM_REC_INVALID_TICKET_BOX = 617,		//无效票箱(Rfid读写故障/票箱安装错误？)
	EM_REC_TICKET_BOX_FIX_ERROR = 618,		//票箱安装错误
	EM_RECYCLE_ERROR = 619,					//回收单元其他故障
	EM_REC_REFUND_EXIT_EXIST_TICKET = 620,	//回收单元退票口有票
	EM_REC_ORIGINAL_ERROR 			= 621,  //回收单元原始故障(通过附加数据进行显示，如： 621())
}EM_TICKET_RECYCLE_FAULT_TYPE;

/*/纸币找零单元故障类型*/
enum EM_BDU_FAULT_TYPE {
	EM_BDU_PORT_ERROR    	= 301,//端口号错误
	EM_BDU_COMM_FAIL     	= 302,//通信错误
	EM_BDU_SENSOR_FAULT  	= 303,//传感器故障
	EM_BDU_SENSOR_DIRTY  	= 304,//传感器需要维修
	EM_BDU_JAM_BILL      	= 305,//卡钞
	EM_BDU_BOX_EMPTY     	= 306,//钱箱空
	EM_BDU_BOX_FILL      	= 307,//钱箱满
	EM_BDU_BOX_UNFIX     	= 308,//钱箱未安装
	EM_BDU_BOX_FIX_ERROR 	= 309,//钱箱安装错误
	EM_BDU_ERROR         	= 310,//纸币找零单元故障
	EM_BDU_ORIGINAL_ERROR 	= 311,//纸币找零单元原始故障(通过附加数据进行显示，如： 311())
};

/*纸币识别模块故障类型*/
typedef enum {

	EM_BIM_PORT_ERROR = 401,					//端口号错误
	EM_BIM_COMM_FAIL = 402,						//通信错误
	EM_BIM_SENSOR_FAULT = 403,					//传感器故障
	EM_BIM_SENSOR_DIRTY = 404,					//传感器需要维修
	EM_BIM_JAM_BILL = 405,						//卡钞
	EM_BIM_BOX_NEARLY_FILL = 406,				//钱箱将满
	EM_BIM_BOX_FILL = 407,						//钱箱满
	EM_BIM_BOX_UNFIX = 408,					//钱箱未安装
	EM_BIM_BOX_FIX_ERROR = 409,				//钱箱安装错误
	EM_BIM_ERROR = 410,							//纸币识别模块故障
	EM_BIM_ORIGINAL_ERROR 	= 411,//纸币识别模块原始故障(通过附加数据进行显示，如： 411)

}EM_BIM_FAULT_TYPE;

/*TPU 售票读卡器故障类型*/

typedef enum {
	EM_TPU_PORT_ERROR = 1,					        	//端口错误
	EM_TPU_COMM_FAIL = 2,						        //串口通信错误
	EM_TPU_PARAM_LOST = 3,			           			//TPU参数缺失
	EM_TPU_OTHER_ERROR = 4,					        	//其他故障
    /*上述故障时故障代码*/
	EM_TPU_SAM_YPT_LOST = 5,							//一票通SAM卡缺失
	EM_TPU_SAM_YKT_LOST = 6,							//一卡通SAM卡缺失
	EM_TPU_SAM_NFC_LOST = 7,							//NFC SAM卡缺失
	EM_TPU_SAM_BANK_LOST = 8,							//BANK SAM卡缺失
	EM_TPU_SAM_RESERVE1_LOST = 9,						//预留SAM卡1缺失
	EM_TPU_SAM_RESERVE2_LOST = 10,						//预留SAM卡2缺失
	EM_TPU_SAM_RESERVE3_LOST = 11,						//预留SAM卡3缺失
	EM_TPU_SAM_RESERVE4_LOST = 12,						//预留SAM卡4缺失
	EM_TPU_SAM_YPT_UNPASS = 13,						    //一票通SAM卡未认证
	EM_TPU_SAM_YKT_UNPASS = 14, 						//一卡通SAM卡未认证
	EM_TPU_SAM_NFC_UNPASS = 15,							//NFC SAM卡未认证
	EM_TPU_SAM_BANK_UNPASS = 16,						//银行 SAM卡未认证
	EM_TPU_SAM_RESERVE1_UNPASS = 17,					//预留SAM卡1未认证
	EM_TPU_SAM_RESERVE2_UNPASS = 18,					//预留SAM卡2未认证
	EM_TPU_SAM_RESERVE3_UNPASS = 19,					//预留SAM卡3未认证
	EM_TPU_SAM_RESERVE4_UNPASS = 20,					//预留SAM卡4未认证
	EM_TPU_YPT_AUTHORIZE_AMOUNT_OVER = 21,	            //一票通SAM卡授权金额用尽
	EM_TPU_YKT_AUTHORIZE_AMOUNT_OVER = 22,	            //一卡通SAM卡授权金额用尽
	EM_TPU_NFC_AUTHORIZE_AMOUNT_OVER = 23,				//NFC SAM卡授权金额用尽
	EM_TPU_BANK_AUTHORIZE_AMOUNT_OVER = 24,				//银行卡 SAM卡授权金额用尽
	EM_TPU_RESERVE1_AUTHORIZE_AMOUNT_OVER = 25,			//预留SAM卡1授权金额用尽
	EM_TPU_RESERVE2_AUTHORIZE_AMOUNT_OVER = 26,			//预留SAM卡2授权金额用尽
	EM_TPU_RESERVE3_AUTHORIZE_AMOUNT_OVER = 27,			//预留SAM卡3授权金额用尽
	EM_TPU_RESERVE4_AUTHORIZE_AMOUNT_OVER = 28,			//预留SAM卡4授权金额用尽
	EM_TPU_YPT_NEWORK_FAIL = 29,						//一票通SAM卡网络通信失败
	EM_TPU_YKT_NEWORK_FAIL = 30,						//一卡通SAM卡网络通信失败
	EM_TPU_NFC_NEWORK_FAIL = 31,						//NFC SAM卡网络通信失败
	EM_TPU_BANK_NEWORK_FAIL = 32,						//BANK SAM卡网络通信失败
	EM_TPU_RESERVE1_NEWORK_FAIL = 33,					//预留 SAM卡1网络通信失败
	EM_TPU_RESERVE2_NEWORK_FAIL = 34,					//预留 SAM卡2网络通信失败
	EM_TPU_RESERVE3_NEWORK_FAIL = 35,					//预留 SAM卡3网络通信失败
	EM_TPU_RESERVE4_NEWORK_FAIL = 36,					//预留 SAM卡4网络通信失败
	EM_TPU_YPT_VENDING_AUTHORIZE_AMOUNT_OVER = 37,	    //一票通SAM卡售票授权金额用尽
	EM_TPU_YPT_RECHARGE_AUTHORIZE_AMOUNT_OVER = 38,	    //一票通SAM卡充值授权金额用尽
	EM_TPU_ORIGINAL_ERROR 	= 39,						//TPU原始故障(通过附加数据进行显示，如： )
}EM_TPU_FAULT_TYPE;



/*TVM运营状态显示器故障类型*/
enum EM_LED_DOUBLE_FAULT_TYPE
{
	EM_LED_DOUBLE_PORT_ERROR    = 1701,//端口号错误
	EM_LED_DOUBLE_COMM_FAIL     = 1702,//通信错误
	EM_LED_DOUBLE_ORIGINAL_ERROR 	= 1703,				//运营状态显示器原始故障(通过附加数据进行显示，如： )
	//LED单元故障
};

/*TVM运营状态UPS故障类型*/
enum EM_TVM_UPS_FAULT_TYPE
{
	EM_TVM_UPS_PORT_ERROR    = 1901,//端口号错误
	EM_TVM_UPS_COMM_FAIL     = 1902,//通信错误
	EM_TVM_UPS_ORIGINAL_ERROR 	= 1903,				//UPS原始故障(通过附加数据进行显示，如： )
};
/*AG运营状态UPS故障类型*/
enum EM_AG_DOUBLE_FAULT_TYPE
{
	EM_AG_UPS_PORT_ERROR    = 2001,//端口号错误
	EM_AG_UPS_COMM_FAIL     = 2002,//通信错误
	EM_AG_UPS_ORIGINAL_ERROR 	= 2003,				//UPS原始故障(通过附加数据进行显示，如： )
};
/*RFID READER故障类型*/
enum EM_RFID_FAULT_TYPE
{
	EM_RFID_PORT_ERROR    = 2601,//端口号错误
	EM_RFID_COMM_FAIL     = 2602,//通信错误
	EM_RFID_ORIGINAL_ERROR 	= 2603,				//RFID原始故障(通过附加数据进行显示，如： )
	//LED单元故障
};

/*TVM DIO故障类型*/
enum EM_TVM_DIO_FAULT_TYPE
{
	EM_TVM_DIO_PORT_ERROR    = 1301,//端口号错误
	EM_TVM_DIO_COMM_FAIL     = 1302,//通信错误
	EM_TVM_DIO_ORIGINAL_ERROR 	= 1303,				//DIO原始故障(通过附加数据进行显示，如： )

};

//AG 门模块故障代码
enum EM_DOOR_FAULT_TYPE
{
	EM_DOOR_PORT_ERROR	= 1501,	//\0	3	通信端口错误
	EM_DOOR_COMM_FAIL = 1502,	//\0	3	通信失败
	EM_DOOR_MECH_FAIL = 1503,	//\0	3	机械故障
	EM_DOOR_SENSOR_FAIL = 1504,	//“传感器编号”	3	传感器故障
	EM_DOOR_CABLE_FAIL	= 1505,	//“0”：进站；“1”：出站；“2”：进出站	3	控制线缆异常
	EM_DOOR_ORIGINAL_ERROR 	= 1506,				//门模块原始故障(通过附加数据进行显示，如： )

};

/*纸币循环模块故障类型*/
typedef enum {

	EM_BIM_RECYCLE_PORT_ERROR = 1601,					//端口号错误
	EM_BIM_RECYCLE_COMM_FAIL = 1602,					//通信错误
	EM_BIM_RECYCLE_SENSOR_FAULT = 1603,					//传感器故障
	EM_BIM_RECYCLE_SENSOR_DIRTY = 1604,					//传感器需要维修
	EM_BIM_RECYCLE_JAM_BILL = 1605,						//卡钞
	EM_BIM_RECYCLE_BOX_NEARLY_FILL = 1606,				//钱箱将满
	EM_BIM_RECYCLE_BOX_FILL = 1607,						//钱箱满
	EM_BIM_RECYCLE_BOX_UNFIX = 1608,					//钱箱未安装
	EM_BIM_RECYCLE_BOX_FIX_ERROR = 1609,				//钱箱安装错误
	EM_BIM_RECYCLE_ERROR = 1610,						//纸币循环模块故障
	EM_BIM_RECYCLE_ORIGINAL_ERROR 	= 1611,				//纸币循环模块原始故障(通过附加数据进行显示，如： )

}EM_BIM_RECYCLE_FAULT_TYPE;


#endif /* AFCERRORCODE_H_ */
