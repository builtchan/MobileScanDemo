/*
 * AfcStatusTable.h
 *
 *  Created on: Jan 13, 2015
 *      Author: wangzp
 *     comment: sle all status table for sc
 */

#ifndef AFCSTATUSTABLE_H_
#define AFCSTATUSTABLE_H_

#include "AfcErrorCode.h"
#include "SleParamAttriDefPublic.h"

//定义类型别名
typedef unsigned char BYTE;
typedef unsigned short int WORD;
typedef unsigned int DWORD;

//定义容器个数宏--wangzp
#define CONTAINER_COUNT_ONE 1
#define CONTAINER_COUNT_FOUR 4
#define CONTAINER_COUNT_SIX  6

#define SYSTEM_ERROR_CODE_COUNT 20    //上报SC的故障码个数定义

typedef enum
{
	EM_DEVICE_COMMON_STATE_OK = 1,			//模块完好，能提供全功能服务
	EM_DEVICE_COMMON_STATE_WARNING = 2,		//模块能提供全功能服务，但有预警信息
	EM_DEVICE_COMMON_STATE_DEGRAD = 3,		//模块部分功能不能使用，但能提供能够降级服务
	EM_DEVICE_COMMON_STATE_MAINTAIN = 4,	//模块需要维护（如票箱不到位、满、空），不能提供服务
	EM_DEVICE_COMMON_STATE_REMOVE = 5,		//模块不到位，不能提供服务
	EM_DEVICE_COMMON_STATE_FAILTURE = 6,	//模块故障，不能提供服务
	EM_DEVICE_COMMON_STATE_DLING = 7,		//模块正在下载软件，不能提供服务
	EM_DEVICE_COMMON_STATE_UNINIT = 8,		//设备没有初始化，或者初始化没有完成，不能提供服务
	EM_DEVICE_COMMON_STATE_COMM_FAILTURE = 9,	//设备通信失败，不能提供服务
	EM_DEVICE_COMMON_STATE_CONNECT_ERROR = 10,	//打开COM口失败，不能提供服务
}EM_DEVICE_COMMON_STATE;

/* 钱箱的物理状态枚举类型*/
typedef enum
{
	EM_BOX_PHYSICS_STATUS_BOX_UNEXIST = 11,					// 钱票箱不存在
	EM_BOX_PHYSICS_STATUS_BOX_UNKNOWN = 10,				    // 钱票箱状态未知
	EM_BOX_PHYSICS_STATUS_BOX_LOST = 9,               		// 钱票箱未安装 卸下
	EM_BOX_PHYSICS_STATUS_BOX_RFID_ERROR = 8,			    //RFID错误
	EM_BOX_PHYSICS_STATUS_BOX_POS_ERROR = 7,			    // 钱票箱位置错误
	EM_BOX_PHYSICS_STATUS_BOX_ILLEGAL_INSTALL = 6,          // 钱票箱非法安装
	EM_BOX_PHYSICS_STATUS_BOX_SLOT_UNOPEN = 5,				//出入口未打开
	EM_BOX_PHYSICS_STATUS_BOX_FULL = 4,                     // 钱票箱已满
	EM_BOX_PHYSICS_STATUS_BOX_EMPTY = 3,                    // 钱票箱已空
	EM_BOX_PHYSICS_STATUS_BOX_NEARLY_FULL = 2,              // 钱票箱将满
	EM_BOX_PHYSICS_STATUS_BOX_NEARLY_EMPTY = 1,             // 钱票箱将空
	EM_BOX_PHYSICS_STATUS_BOX_OK = 0 , 	                    // 钱票箱正常
}EM_BOX_PHYSICS_STATUS;

typedef struct _ST_DEVICE_ERROR_CODE_
{
	int iErrorCode;			//故障代码
	char czAdditionalInfo[16];  //故障附加信息
} ST_DEVICE_ERROR_CODE;

/*公有的状态结构体*/
typedef struct _ST_COMMON_STATUS_
{
	EM_DEVICE_COMMON_STATE emCommonState;	//通用状态值
	int iErrorCodeNumber;
	ST_DEVICE_ERROR_CODE  stErrorCode[5];	//当前故障代码，最多5个
} ST_COMMON_STATUS;

//TPU状态结构体

/*SAM卡状态枚举类型*/
typedef enum
{
	EM_SAM_STATE_TYPE_OK = 0x00,					//SAM卡状态OK
	EM_SAM_STATE_TYPE_LOST = 0x01,					//SAM卡缺失
	EM_SAM_STATE_TYPE_UNPASS = 0x02,				//SAM卡未认证
	EM_SAM_STATE_TYPE_ALL_AUTH_OVER = 0x03,			//所有的授权金额用尽
	EM_SAM_STATE_TYPE_RECHARGE_AUTH_OVER = 0x04,	//充值授权金额用尽
	EM_SAM_STATE_TYPE_VENDING_AUTH_OVER = 0x05,		//售票授权金额用尽
	EM_SAM_STATE_TYPE_NETWORK_FAIL = 0x06,			//网络通信失败
	EM_SAM_STATE_TYPE_UNEXIST = 0xFF,				//不存在SAM卡
}EM_SAM_STATE_TYPE;

//sam卡的类型
typedef enum
{
	EM_SAM_TYPE_YPT = 0x00,     //一票通SAM卡
	EM_SAM_TYPE_YKT = 0x01, 	//一卡通SAM卡
	EM_SAM_TYPE_NFC = 0x02, 	//NFC sam卡
	EM_SAM_TYPE_BANK = 0x03,	//银行SAM卡
	EM_SAM_TYPE_RESERV1 = 0x04, //预留SAM卡1
	EM_SAM_TYPE_RESERV2 = 0x05, //预留SAM卡2
	EM_SAM_TYPE_RESERV3 = 0x06,	//预留SAM卡3
	EM_SAM_TYPE_RESERV4 = 0x07, //预留SAM卡4
}EM_SAM_TYPE;
/*SAM卡类型和状态结构体*/
typedef struct
{
	EM_SAM_TYPE emSamType;
	EM_SAM_STATE_TYPE emSamStateType;
	char szSamId[21];					//SAM 卡编号
	int iSamSvtBalance ;				// SAM卡SVTBalance (非地铁卡此值为)
	int iSamTripCountBalance;			// SAM卡TripCountBalance (非地铁卡此值为)
	int iSamSjtBalance;				// SAM卡SJTBalance (非地铁卡此值为)
	int iSamOtherBalance;
} ST_SAM_TYPE_STATE;

/*SAM卡状态结构体*/
typedef struct _ST_TPU_STATUS_
{
	EM_DEVICE_COMMON_STATE emCommonState;	//通用状态值
	int iErrorCodeNumber;					//描述故障代码的数量，取值0~5
	ST_DEVICE_ERROR_CODE stErrorCode[5];	//当前故障代码，最多5个
	ST_SAM_TYPE_STATE stSamTypeState[8];	//SAM卡状态和类型
}ST_TPU_STATUS;

/*AG DIO状态结构体*/
typedef struct _ST_AG_DIO_STATUS_
{
	EM_DEVICE_COMMON_STATE emCommonState;	//通用状态值
	int iErrorCodeNumber;
	ST_DEVICE_ERROR_CODE  stErrorCode[5];		//当前故障代码，最多5个
	unsigned int uiDIOStatus;				//DIO状态
} ST_AG_DIO_STATUS;


/*现金状态结构体*/
typedef struct _ST_CASH_STATUS_
{
	EM_DEVICE_COMMON_STATE emCommonState;	//通用状态值
	int iErrorCodeNumber;
	ST_DEVICE_ERROR_CODE  stErrorCode[5];		//当前故障代码，最多5个
	bool bAcceptState;							//当前是否允许现金投入
	bool bCanAcceptCash;							//当前接收功能是否OK
	bool bCanChangeCash;							//当前找零功能是否OK
	EM_BOX_PHYSICS_STATUS emszCashContainerStatus[CONTAINER_COUNT_FOUR];  //现金回收箱
	EM_BOX_PHYSICS_STATUS emszLoopChangeBoxStatus[CONTAINER_COUNT_SIX];	//循环找零箱
	EM_BOX_PHYSICS_STATUS emszSpareChangeBoxStatus[CONTAINER_COUNT_FOUR];   //备用找零箱
	EM_BOX_PHYSICS_STATUS emszCashSupplyBoxStatus[CONTAINER_COUNT_FOUR];  //找零补充箱
	EM_BOX_PHYSICS_STATUS emszChangeWasteBoxStatus[CONTAINER_COUNT_ONE];//    //找零废钞回收箱
} ST_CASH_STATUS;

/*LED条屏显示状态定义*/
typedef struct _ST_LED_STATUS_
{
	EM_DEVICE_COMMON_STATE emCommonState;	//通用状态值
	int iErrorCodeNumber;
	ST_DEVICE_ERROR_CODE  stErrorCode[5];		//当前故障代码，最多5个
} ST_LED_STATUS;

typedef struct _ST_RFID_STATUS_
{
	EM_DEVICE_COMMON_STATE emCommonState;	//通用状态值
	int iErrorCodeNumber;
	ST_DEVICE_ERROR_CODE  stErrorCode[5];		//当前故障代码，最多5个
} ST_RFID_STATUS;



//DIO状态定义
typedef struct _ST_DIO_STATUS_
{
	EM_DEVICE_COMMON_STATE emCommonState;	//通用状态值
	int iErrorCodeNumber;					//描述故障代码的数量，取值0~5
	ST_DEVICE_ERROR_CODE pstErrorCode[5];	//当前故障代码，最多5个
	unsigned int uiDistatus;				//DI状态
}ST_DIO_STATUS;

//发行单元状态定义
typedef struct _ST_ISSUE_STATUS_
{
	EM_DEVICE_COMMON_STATE emDeviceCommonState;				//通用状态值
	int iCurrentFaultCodeNumber;							//故障码计数
	ST_DEVICE_ERROR_CODE  stDeviceFaultCode[5];				//当前故障代码,最多允许5个
	int iPreFetchPosTicketCount;							//等待位(预提位)票数量
	int iReadWritePosTicketCount;							//读卡位(天线区)票数量
	bool bWaitingTakeOut;									//票口是否有票等待取出
	EM_BOX_PHYSICS_STATUS emTicketBoxStatus[CONTAINER_COUNT_FOUR];				//票箱
	EM_BOX_PHYSICS_STATUS emWithdrawBoxStatus[CONTAINER_COUNT_FOUR];			//回收箱
	EM_BOX_PHYSICS_STATUS emSupplyBoxStatus[CONTAINER_COUNT_FOUR];  			//补充箱
	EM_BOX_PHYSICS_STATUS emInvalidBoxStatus;   			//废票箱
}ST_ISSUE_STATUS;

/*打印机状态定义*/
typedef struct _ST_PRINTER_STATUS_
{
	EM_DEVICE_COMMON_STATE emCommonState;	//通用状态值
	int iErrorCodeNumber;
	ST_DEVICE_ERROR_CODE  stErrorCode[5];		//当前故障代码，最多5个

} ST_PRINTER_STATUS;

typedef enum
{
	EM_POWER_LEVEL_NORMAL = 1, //电量正常
	EM_POWER_LEVEL_WARN = 2, //电量报警
	EM_POWER_LEVEL_LOW = 3, //电量低
}EM_POWER_LEVEL_TYPE;

/*UPS状态定义*/
typedef struct _ST_UPS_STATUS_ {
	EM_DEVICE_COMMON_STATE emCommonState; //通用状态值
	int iErrorCodeNumber;
	ST_DEVICE_ERROR_CODE stErrorCode[5];  //当前故障代码，最多5个
	bool bUpsOnline;                      //UPS是否在线
	int iPowerLevel;
	EM_POWER_LEVEL_TYPE emPowerLevelType;
} ST_UPS_STATUS;

typedef struct _ST_MOBILESCAN_STATUS_
{
	EM_DEVICE_COMMON_STATE emCommonState; //通用状态值
	int iErrorCodeNumber;
	ST_DEVICE_ERROR_CODE stErrorCode[5];  //当前故障代码，最多5个

}ST_MOBILESCAN_STATUS;

//工作状态枚举值
typedef enum __EM_WD_WORK_STATE__
{
	EM_WD_WORK_STATE_IDLE = 0,								//投入口关闭，空闲态
	EM_WD_WORK_STATE_WAIT_INSERT = 1,						//投入口开启，等待投票
	EM_WD_WORK_STATE_WAIT_RW = 2,							//投入口关闭，读写区有票，等待处理
	EM_WD_WORK_STATE_WAIT_TAKEAWAY = 3,						//投入口关闭，返还口持票，等待取走
	EM_WD_WORK_STATE_UNKNOWN = 4,							//状态未知
}EM_WD_WORK_STATE;

//回收单元状态定义
typedef struct _ST_WITHDRAW_STATUS_
{
	EM_DEVICE_COMMON_STATE emDeviceCommonState;				//通用状态值
	int iCurrentFaultCodeNumber;							//故障码计数
	ST_DEVICE_ERROR_CODE  stDeviceFaultCode[5];				//当前故障代码,最多允许5个
	EM_BOX_PHYSICS_STATUS emWithdrawBoxStatus[CONTAINER_COUNT_FOUR];			//回收箱
	EM_BOX_PHYSICS_STATUS emWasteBoxStatus;   				//废票箱
    EM_WD_WORK_STATE emWorkState;							//工作状态
}ST_WITHDRAW_STATUS;


typedef	enum
{
	/*
	 *   进/出类型     检票状态     次序免检状态
	 *     进站        可检票       不次序免检
	 *     进站        可检票       次序免检
	 *     进站        不检票          X
	 *     出站        可检票       不次序免检
	 *     出站        可检票       次序免检
	 *     出站        不检票          X
	 *     关闭模式，暂停服务工作模式
	 *     自由进出站类型(双向免检)
	 *     双向控制类型(双向都不检票)
	 * */
	/*
	 *   进站检票状态     出站检票状态    	次序免检状态
	 *     进站可检票      出站可检票     	无次序免检		1
	 *     进站可检票      出站可检票     	进站次序免检		7
	 *     进站可检票      出站可检票     	出站次序免检		6
	 *     进站可检票      出站可检票     	进出均次序免检		8
	 *     进站可检票      出站不可检票		仅进站次序免检		4
	 *     进站可检票      出站不可检票   	进站无次序免检		2
	 *     进站不可检票    出站可检票		仅出站次序免检		5
	 *     进站不可检票    出站可检票   		出站无次序免检		3
	 *     关闭模式，暂停服务工作模式						0
	 *
	 * */

	PCM_MODE_OUT_OF_SERVICE 			= 0,		       /*!<关闭模式，暂停服务工作模式*/
	PCM_MODE_ENTRY_CONTROL_EXIT_CONTROL	= 1,		/*!<双向控制类型*/
	PCM_MODE_ENTRY_CONTROL_EXIT_LOCK	= 2,		/*!<单进模式，进站控制类型*/
	PCM_MODE_ENTRY_LOCK_EXIT_CONTROL	= 3,		/*!<单出模式，出站控制类型*/
	PCM_MODE_ENTRY_FREE_EXIT_LOCKED		= 4,         /*!<进闸免检模式N*/
	PCM_MODE_ENTRY_LOCKED_EXIT_FREE		= 5,          /*!<出闸免检模式	*/
	PCM_MODE_ENTRY_CONTROL_EXIT_FREE	= 6,			/*!<进闸检票、出闸免检模式，自由出站类型*/
	PCM_MODE_ENTRY_FREE_EXIT_CONTROL	= 7,			/*!<出闸检票、进闸免检模式，自由进站类型*/
	PCM_MODE_ENTRY_FREE_EXIT_FREE		= 8,			/*!<自由进出站类型*/
}EM_GATE_WORKMODE;
typedef	enum
{
	PCM_TYPE_KEEP_OPEN	= 0,			/*!<常开模式*/
	PCM_TYPE_KEEP_CLOSE	= 1,			/*!<常闭模式*/
}EM_CSS_DOOR_WORKMODE;
typedef struct __ST_HEIGHT_REGISTER_AUXI__
{
	//unsigned int AUXI_RESERVE0   :28; // R

	unsigned int AUXI_HS4   :1; // R
	unsigned int AUXI_HS3   :1; // R
	unsigned int AUXI_HS2   :1; // R
	unsigned int AUXI_HS1   :1;	// R
} ST_HEIGHT_REGISTER_STATUS;
typedef struct _ST_GATE_ALARM_STATUS_
{
	bool bPowerOn;		//模块重新上电
	bool bEntryForce;		//进站闯入
	bool bExitForce;		//出站闯入
	bool bEntryTrailing;		//进站尾随
	bool bExitTrailing;		//出站尾随
	bool bEntryBusy;		//进站忙
	bool bExitBusy;		//出站忙
	bool bEntryAuthWaiting;		//进站授权中
	bool bExitAuthWaiting;		//出站授权中
}ST_GATE_ALARM_STATUS;
typedef struct _ST_GATE_AISLE_DATA_
{
	int  iEntryAuth;	/*!<进站方向开门信号数*/
	int  iExitAuth;	/*!<出站方向开门信号数*/
	int  iIntrusion; 	/*!<闯关数量*/
	int  iTailGating; 	/*!<尾随通过数量*/
	int  iEntryCancel; 	/*!<进站超时取消数量*/
	int  iExitCancel; 	/*!<出站超时取消数量*/
} ST_GATE_AISLE_DATA;
typedef struct _ST_DOOR_UNIT_STATUS_
{
	EM_DEVICE_COMMON_STATE emCommonState;	//通用状态值
	int iErrorCodeNumber;					//描述故障代码的数量，取值0~5
	ST_DEVICE_ERROR_CODE pstErrorCode[5];			//当前故障代码，最多5个
	ST_GATE_ALARM_STATUS stAlarm;		//警报状态
	ST_GATE_AISLE_DATA stAisleData; 	//通道相关数据
	EM_CSS_DOOR_WORKMODE emDoorMode;	//门模式
	EM_GATE_WORKMODE emGateMode;	//工作模式
	ST_HEIGHT_REGISTER_STATUS  stHeigtRegisterStatus; //高位传感器状态
	bool bMaintainMode;			//是否维修模式
	bool bTestMode;				//是否测试模式
	bool bSwEmergency;	//是否通过串口设置为紧急
	bool bEmergency;	//是否通过紧急接入电缆设置为紧急
	bool bCheckChild;	//是否开启儿童检测
} ST_DOOR_UNIT_STATUS;
/*******************************************************以下系统级别定义，供SC使用*******************************************************/


/*tvm交易类型通知*/
typedef enum
{
	EM_TVM_LIMIT_TRANSACATION_CMD_NORMAL                 = 0,       //正常
	EM_TVM_LIMIT_TRANSACATION_CMD_ONLY_VENDING  		 = 0x01,    //只售票
	EM_TVM_LIMIT_TRANSACATION_CMD_ONLY_RECHARGE       	 = 0x02,    //只充值
}EM_TVM_LIMIT_TRANSACATION_CMD;

/*AG交易类型通知*/
typedef enum
{
	EM_AG_LIMIT_TRANSACATION_CMD_BIDIR               = 0x03,    //双向
	EM_AG_LIMIT_TRANSACATION_CMD_ONLY_ENTRY  		 = 0x01,    //只进站
	EM_AG_LIMIT_TRANSACATION_CMD_ONLY_EXIT       	 = 0x02,    //只出站
}EM_AG_LIMIT_TRANSACATION_CMD;

///*交易类型（即工作模式）*/
//typedef struct
//{
//	bool bTransTypeTvmVending;                          //售票
//	bool bTransTypeTvmRecharge;                         //充值
//	bool bTransTypeTvmQuery;                            //查询
//	bool bTransTypeAgEntry;                             //进站
//	bool bTransTypeAgSjtExit;                           //回收出站
//	bool bTransTypeAgSvCardExit;                        //刷卡出站
//}ST_SLE_TRANSACATION_TYPE;


//定义SLE系统服务模式枚举   AG有关检票服务模式待加
typedef enum
{
	EM_SLE_SERVICE_MDDE_SERVICE = 0,         //服务
	EM_SLE_SERVICE_MODE_MAINTAIN = 1,        //维修
	EM_SLE_SERVICE_MODE_EMERGENCY = 2,       //紧急
	EM_SLE_SERVICE_MODE_CLOSE_MODE =3,      //关闭模式
	EM_SLE_SERVICE_MODE_STOP_SERVICE = 4,    //暂停服务
	//EM_SLE_SERVICE_MODE_TRAIN_FAULT,     //列车故障
	EM_SLE_SERVICE_MODE_RESERVE1,
	EM_SLE_SERVICE_MODE_RESERVE2,
	EM_SLE_SERVICE_MODE_RESERVE3,
	EM_SLE_SERVICE_MODE_RESERVE4,
}EM_SLE_SERVICE_MDDE;

//定义SLE系统服务模式结构体   AG有关检票服务模式待加
typedef struct
{
	bool bSleServiveModeNormal;          //服务
	bool bSleServiveModeMaintence;       //维修
	bool bSleServiveModeEmergency;       //紧急
	bool bSleServiveModeCloseMode;       //关闭模式
	bool bSleServiveModeStopMode;        //暂停服务
	//bool bSleServiveModeTrainFault;      //列车故障
	bool bReserve1;
	bool bReserve2;
	bool bReserve3;
	bool bReserve4;
}ST_SLE_SERVICE_MODE;


//定义AG端运营模式   AG有关检票运营模式待加
typedef enum
{
	EM_AG_SIDE_MODE_READY = 1,      //服务就绪
	EM_AG_SIDE_MODE_PAUSE = 2,    //暂缓检票
	EM_AG_SIDE_MODE_FREE = 3,       //免检模式
	EM_AG_SIDE_MODE_OOS = 4,    //暂停服务
}EM_AG_SIDE_MODE;

typedef enum
{
	EM_AG_SIDE_ENTRY = 1,    //进站端
	EM_AG_SIDE_EXIT_WD,       //出站回收端
	EM_AG_SIDE_EXIT_UNWD,      //出站刷卡端
}EM_AG_SIDE;

/*运营状态枚举*/
typedef enum
{
	EM_RUN_STATE_RUN_START_SUCCESS		= 0x00,	/*<运营开始状态*/
	EM_RUN_STATE_RUN_STARTING		= 0x01,	/*<正在运营开始中*/
	EM_RUN_STATE_RUN_START_FAILURE		= 0x02,	/*<运营开始失败*/
	EM_RUN_STATE_RUN_END_SUCCESS		= 0x03,	/*<运营结束状态*/
	EM_RUN_STATE_RUN_ENDING			= 0x04,	/*<正在运营结束中*/
	EM_RUN_STATE_RUN_END_FAILURE		= 0x05,	/*<运营结束失败*/
	EM_RUN_STATE_RUN_DATE_SWITCHING			= 0x06,	/*<运营日切换中*/
}EM_RUN_STATE;

typedef enum
{
	EM_SYSTEM_RUN_MODE_NORMAL,                               //正常模式
	EM_SYSTEM_RUN_MODE_TRAIN_FAULT,                           //列车故障模式
	EM_SYSTEM_RUN_MODE_FREE_DATE,                             //日期免检模式
	EM_SYSTEM_RUN_MODE_FREE_TIME,                             //时间免检模式
	EM_SYSTEM_RUN_MODE_FREE_ORDER_ENTER,                         //进站次序免检模式
	EM_SYSTEM_RUN_MODE_FREE_ORDER_EXIT,                         //进站次序免检模式
	EM_SYSTEM_RUN_MODE_FREE_ENTRY,                             //进站免检模式
	EM_SYSTEM_RUN_MODE_FREE_FARE,                             //车费免检模式
	EM_SYSTEM_RUN_MODE_24HOUR,                             //24小时运营
	EM_SYSTEM_RUN_MODE_DELAY_RUN,                             //延长运营时间
	EM_SYSTEM_RUN_MODE_NO_PRINT,                             //无打印模式
	EM_SYSTEM_RUN_MODE_FREE_EXIT,                             //出站免检模式
	EM_SYSTEM_RUN_MODE_EMERGENCY,                            //紧急模式，仅用于降级模式，下发给TPU，不用作其他用途
	EM_SYSTEM_RUN_MODE_RESERVE2,
	EM_SYSTEM_RUN_MODE_RESERVE3,
}EM_SYSTEM_RUN_MODE;
typedef struct
{
	bool bRunModeNormal;                               //正常模式
	bool bRunModeTrainFault;                           //是否列车故障模式
	bool bRunModeFreeDate;                             //是否日期免检模式
	bool bRunModeFreeTime;                             //是否日期免检模式
	bool bRunModeFreeFare;                             //是否车费免检模式
	bool bRunModeFreeOrderEntry;                        //是否进站次序免检
	bool bRunModeFreeOrderExit;                        //是否出站次序免检
	bool bRunModeFreeEntry;                            //是否进站免检
	bool bRunMode24hour;                               //是否24小时运营
	bool bDelayRunTime;								   //是否延长运营时间
	bool bNoPrintMode;                                 //是否为无打印模式
	bool bRunModeFreeExit;                            //是否出站免检
	bool bEmergency;                                  //是否紧急模式
	bool bReserve2Mode;
	bool bReserve3Mode;
} ST_SYSTEM_RUN_MODE;

/*! \brief 定义枚举型的数据结构CONNECT_STATE_CODE
* 	注6 连接状态（0x010107）的状态值
*/
typedef enum
{
	EM_CONNECT_STATE_COMM_INTERRUPT	= 0x00,	/*通讯中断*/
	EM_CONNECT_STATE_COMM_NORMAL 		= 0x01,	/*通讯正常*/
	//EM_CONNECT_STATE_COMM_RECOVERING 	= 0x02,	/*通讯恢复中*/
}EM_CONNECT_STATE_CODE;

/*! \brief 定义枚举型的数据结构CLOCK_DIFFERENCE_CODE
* 	注7 时钟差异（0x010108）的状态值
*/
typedef enum
{
	EM_CLOCK_DIFFERENCE_NORMAL	=0x00,	/*时钟正常*/
	EM_CLOCK_DIFFERENCE_WARNING	= 0x01,	/*时钟警告*/
	EM_CLOCK_DIFFERENCE_FAULT	= 0x02,	/*时钟故障*/
}EM_CLOCK_STATE;

/*! \brief 定义枚举型的数据结构LOGGIN_STATE_CODE
* 	注8 登录状态（0x010109）的状态值
*/
typedef enum
{
	EM_LOGIN_STATE_WITH_NOBODY	= 0x00,  /*无人登录,退出登录后的状态*/
	EM_LOGIN_STATE_WITH_SOMEBODY	= 0x01,	/*有人登陆,登陆成功后的状态*/
	EM_LOGIN_STATE_ACCOUNT_LOCKED	= 0x02,	/*账户锁定,账户锁定后的状态，有人登录成功后状态改变*/
}EM_LOGIN_STATE_CODE;

/*! \brief 定义枚举型的数据结构DEVICE_AUTO_RUNNING_STATE_CODE
* 	注9-1	设备自动运行时间表状态（0x01010A）的状态值
*/
typedef enum
{
	EM_DEVICE_FAULT_STATE_NO_FAULT			= 0x00,	/*设备没有故障状态*/
	EM_DEVICE_FAULT_STATE_FAULT			= 0x01,	/*设备出现故障*/
}EM_DEVICE_FAULT_STATE_CODE;


/*! \brief 定义枚举型的数据结构SC_AUTO_RUN_STATE_CODE
* 	SC自动运行时间表状态（0x020101）的状态值
*/
typedef enum
{
	//登录状态值	登录状态名称
	EM_SC_AUTO_RUN_STATE_STOP		= 0x00,	/*!<	车站自动运行状态停用*/
	EM_SC_AUTO_RUN_STATE_START		= 0x01,	/*!<	车站自动运行状态启用*/
}EM_SC_AUTO_RUN_STATE_CODE;

/*! \brief 定义枚举型的数据结构SYSTEM_DISK_CODE
* 	注12-7	系统磁盘空间状态(0x040102)的状态值
*/
typedef enum
{
	EM_SYSTEM_ALL_DISK_USE_NORMAL		= 0x01,			/*系统磁盘空间正常*/
	EM_SYSTEM_ALL_DISK_USE_LACK		= 0x02,			/*系统磁盘空间不足*/
	EM_SYSTEM_ALL_DISK_USE_BAD		= 0x03,			/*系统磁盘空间严重不足*/
}EM_SYSTEM_ALL_DISK_USE_CODE;

/*! \brief 定义枚举型的数据结构SYSTEM_DISK_CODE
* 	注12-7	数据库磁盘空间状态(0x040102)的状态值
*/
typedef enum
{
	EM_SYSTEM_DB_DISK_USE_NORMAL		= 0x01,			/*数据库磁盘空间正常*/
	EM_SYSTEM_DB_DISK_USE_LACK		= 0x02,			/*数据库磁盘空间不足*/
	EM_SYSTEM_DB_DISK_USE_BAD		= 0x03,			/*数据库磁盘空间严重不足*/
}EM_SYSTEM_DB_DISK_USE_CODE;

/*! \brief 定义枚举型的数据结构CPU_USE_CODE
* 	注12-7	CPU状态(0x040201)的状态值
*/
typedef enum
{
	EM_CPU_USE_NORMAL			= 0x01,			/*CPU利用正常*/
	EM_CPU_USE_LACK				= 0x02,			/*CPU利用偏高*/
	EM_CPU_USE_BUSY				= 0x03,			/*CPU忙*/
}EM_CPU_USE_CODE;

/*! \brief M_RAM_USE_CODE
* 	注12-8	内存状态的状态值
*/
typedef enum
{
	EM_RAM_USE_NORMAL			= 0x01,			/*CPU利用正常*/
	EM_RAM_USE_LACK				= 0x02,			/*CPU利用偏高*/
	EM_RAM_USE_BUSY				= 0x03,			/*CPU忙*/
}EM_RAM_USE_CODE;
/*! \brief 定义枚举型的数据结构CASH_SAFE_DOOR_STATE_CODE
* 	注18 现金安全门状态(0x0E0101)的状态值
*/
typedef enum
{
	EM_CASH_SAFE_DOOR_STATE_NORMAL_CLOSE	= 0x00,	/*现金安全门正常关闭*/
	EM_CASH_SAFE_DOOR_STATE_NORMAL_OPEN	= 0x01,	/*现金安全门正常打开*/
	EM_CASH_SAFE_DOOR_STATE_ILLEGAL_OPEN	= 0x02,	/*现金安全门非法打开*/
}EM_CASH_SAFE_DOOR_STATE_CODE;

typedef enum _EM_BOX_BAFFLE_STATE_
{
	EM_BOX_BAFFLE_STATE_CLOSE = 0x00,			/*箱子翻版关闭*/
	EM_BOX_BAFFLE_STATE_OPEN = 0x01,			/*箱子翻版打开*/
}EM_BOX_BAFFLE_STATE;

/*! \brief 定义枚举型的数据结构SEEK_RESCUE_MENU_STATE_CODE
* 	注21 招援按钮状态(0x110101)的状态值
*/
typedef enum
{
	EM_SEEK_RESCUE_MENU_STATE_NORMAL	= 0x00,	/*非招援状态*/
	EM_SEEK_RESCUE_MENU_STATE_PRESS_DOWN	= 0x01,	/*招援状态*/
}EM_SEEK_RESCUE_MENU_STATE_CODE;

/*AG设备子类型*/
typedef enum
{
	EM_AG_DEVICE_SUB_TYPE_STANDARD_ENTRY = 0x01,    //标准进站
	EM_AG_DEVICE_SUB_TYPE_STANDARD_EXIT,     //标准出站
	EM_AG_DEVICE_SUB_TYPE_STANDARD_BOTHWAY, //双向
	EM_AG_DEVICE_SUB_TYPE_BROAD_CHANNEL_ENTRY,    //宽通道进站
	EM_AG_DEVICE_SUB_TYPE_BROAD_CHANNEL_EXIT,     //宽通道出站
	EM_AG_DEVICE_SUB_TYPE_BROAD_CHANNEL_BOTHWAY,  //宽通道双向
}EM_AG_DEVICE_SUB_TYPE;

//儿童检测
typedef enum
{
	EM_CHILD_CHECK_OPEN,
	EM_CHILD_CHECK_CLOSE,
}EM_CHILD_CHECK;

/*ISAM卡状态*/
typedef enum
{
	EM_ISAM_STATE_NOT_VERIFY			= 0x00,  /*ISAM状态未验证*/
	EM_ISAM_STATE_VERIFIED				= 0x01,  /*ISAM状态已验证*/
}EM_ISAM_STATE_CODE;

/*! \brief 定义枚举型的数据结构MAINTAIN_KEY_BOARD_STATE_CODE
* 	注38：维修键盘状态(0x1B0101)
*/
typedef enum//定义成统一格式结构提

{
	EM_MAINTAIN_KEY_BOARD_NORMAL							= 0x00,	/*维修面板正常工作*/
	EM_MAINTAIN_KEY_BOARD_COMMUNICATION_FAULT				= 0x01,	/*维修面板通信故障*/
	EM_MAINTAIN_KEY_BOARD_POWER_OFF							= 0x02,	/*维修面板断电*/
}EM_MAINTENCE_KEY_BOARD_STATE;

/*! \brief 定义枚举型的数据结构MAINTAIN_DOOR_SYNTHETIC_STATE_CODE
* 	注39 维修门状态（0x1C0101，0x1C0201，0x1C0301，0x1C0401）
*/
typedef enum
{
	EM_MAINTAIN_DOOR_NORMAL_OPEN									= 0x00,	/*维修门正常打开*/
	EM_MAINTAIN_DOOR_NORMAL_CLOSE									= 0x01,	/*维修门正常关闭*/
	EM_MAINTAIN_DOOR_ILLEGAL_OPEN									= 0x02,	/*维修门非法打开*/
	EM_MAINTAIN_DOOR_CLOSE_UNCLOCK									= 0x03,	/*维修门关闭未锁*/
}EM_MAINTENCE_DOOR_STATE;

/*加热模块状态*/
typedef enum//定义成统一格式结构提
{
	EM_HOT_STATUS_NORMAL					= 0x00,	/*加热正常*/
	EM_HOT_STATUS_FAULT						= 0x01,	/*加热故障*/
}EM_HOT_STATUS;

/*安全性状态*/
typedef enum                                        //  安全状态
{
	EM_SECURITY_STATUS_NORMAL                =0x00,
	EM_SECURITY_STATUS_ILLEGAL               =0x01,
}EM_SECURITY_STATUS;

typedef enum                                       //初始化机器
{
	EM_INITIALIZATION_STATE_MACHINE_NORMAL   =0x00,
	EM_INITIALIZATION_STATE_MACHINE_INITING   =0x01,
}EM_INITIALIZATION_STATE_MACHINE;

/*工作模式*/
typedef enum	//定义成boll结构提，8种
{
	EM_WORK_MODE_TICKET_CHARGE 			= 0x00,//售充值模式
	EM_WORK_MODE_TICKET_ONLY	 		= 0x01,//仅售票模式
	EM_WORK_MODE_RECHARGE_ONLY			= 0x03, //仅充值模式
	EM_WORK_MODE_CARD_TICKET_ONLY		= 0x02,  //仅储值卡售票
	EM_WORK_MODE_NO_SERVICE				= 0x04, //无服务
}EM_WORK_MODE_CODE;

//TVM支付类型定义，用于业务与APP之间参数传递
typedef struct
{
	bool bBanknotePay;   //纸币支付
	bool bCoinPay;       //硬币支付
	bool bSvtPay;    	//储值卡支付
	bool bBankCardPay; 	//银行卡支付
	bool bNfcPay; 		//NFC支付
	bool bWebPay;       //网络预付
	bool bVoucherPay;	//代金卷支付
	bool bOtherPay;		//其他第三方支付
	bool bQRCodePay;    //二维码支付
}ST_TVM_PAY_TYPE;

//找零模式
//typedef enum
//{
//	EM_NONE_CHANGE_TYPE			= 0x00,//无找零
//	EM_COIN_CHANGE_ONLY			= 0x01,//只硬币找零
//	EM_BILL_CHANGE_ONLY			= 0x02,//只纸币找零
//	EM_ALL_CHANGE_TYPE			= 0x03,//纸硬币找零
//}EM_TVM_CHANGE_TYPE;


typedef enum _EM_SLE_RUN_STATUS_
{
	SLE_FREE				= 0,	//空闲状态
	SLE_IN_TRANS			= 1,	//交易中
	SLE_IN_TEST				= 2,    //测试中
	SLE_IN_CHANGE_TIC_BOX	= 3,	//更换票箱中
	SLE_IN_ISSUE_CONTINUE	= 4,	//连续提票中
}EM_SLE_RUN_STATUS;

/*
 * 外部设置状态
 */
typedef struct
{
	EM_RUN_STATE emRunSatae;                           //运营开始结束状态
	EM_CONNECT_STATE_CODE emConnectState;                     //通信链接状态
	EM_CLOCK_STATE emClockDifference;               //时钟差异
	EM_LOGIN_STATE_CODE emLoginState;                         //登录状态
	EM_SC_AUTO_RUN_STATE_CODE emSCAutoRunState;               //
	EM_SYSTEM_ALL_DISK_USE_CODE emSystemDiskUse;              //磁盘使用情况
	EM_SYSTEM_DB_DISK_USE_CODE emSystemDBUse;                 //数据库使用情况
	EM_CPU_USE_CODE emCPUUse;                                 //CPU使用情况
	EM_RAM_USE_CODE emRamUse;                                 //内存使用情况
	EM_CASH_SAFE_DOOR_STATE_CODE emCashSafeDoorState;         //现金安全门状态
	EM_SEEK_RESCUE_MENU_STATE_CODE emSeekRescueMenuState;     //招援按钮
	//EM_AG_DEVICE_SUB_TYPE emAgDeviceSubType;                  //AG设备子类型
	EM_AG_LIMIT_TRANSACATION_CMD emAgLimitTransCmd;          //通道方向
	EM_MAINTENCE_DOOR_STATE emMaintenceDoorSyntheticState;     //维修门状态
	EM_SECURITY_STATUS emSecurityStatus;                       //安全性状态
//	EM_INITIALIZATION_STATE_MACHINE emInitializationState;     //设备初始化状态
	ST_SYSTEM_RUN_MODE stSystemRunMode;           //运营模式
	EM_AG_APPLICATION_TYPE emAgApplicationType[2];     //闸机应用类型 下标0：进站 1：出站    added by wangzp at 30th, Oct,2015
	EM_BOM_SALE_COMPENSATION_MODE emBomSaleCompensationMode; //BOM 售补票模式
	EM_SLE_RUN_STATUS             emSleRunStatus;  //设备运行状态
}ST_SYSTEM_SETTING_STATUS;

/*TVM工作模式*/
typedef struct
{
    //Byte 0：工作模式
    DWORD iWorkModeMaintence:1;//  Bit 0：非维修模式，1维修模式
    DWORD iWorkModeAllowVending:1;//  Bit 1：允许售票，1有效
    DWORD iWorkModeAllowRecharge:1;//  Bit 2：允许充值，1有效
    DWORD iWorkModeNoPrint:1;//  Bit 3：无打印模式，1有效
    DWORD iWorkModeOutService:1;//  Bit 4：暂停服务模式，1有效
    DWORD iWorkModeCloseService:1;//  Bit 5：关闭服务模式，1有效
    DWORD iWorkModeTrainFail:1;//  Bit 6：列车故障模式，1有效
    DWORD iWorkModeEmergency:1;//  Bit 7：紧急模式，1有效

    //Byte 1：支付模式
    DWORD iPayModeAllowBill:1;//  Bit 0：允许纸币，1有效
    DWORD iPayModeAllowCoin:1;//  Bit 1：允许硬币，1有效
    DWORD iPayModeAllowSvt:1;		// Bit 2： 储值卡支付，1有效
    DWORD iPayModeAllowBankCard:1;//  Bit 3：允许银行卡，1有效
    DWORD iPayModeAllowNfc:1;		// Bit 4： NFC支付，1有效
    DWORD iPayModeAllowWeb:1;		// Bit 5：网络预付，1有效
    DWORD iPayModeAllowVoucher:1;	// Bit 6：代金卷支付，1有效
	DWORD iiPayModeAllowOther:1;	// Bit 7：其他第三方支付

	//Byte 2：找零模式，1有效
	DWORD iNormalChange:1;//  Bit0：正常找零
	DWORD iNoChange:1;//  Bit 1：无找零模式
	DWORD iNoPartCoinChange:1;//  Bit2：无部分币值找零
	DWORD :1;//Bit3：预留

	//补充工作模式
    DWORD iWorkModeAllowQuery:1;//  Bit 2：允许查询，1有效
	DWORD :3;//Bit5~bit7：预留

	//Byte 3：找零币值
	DWORD iNoChangeDenoNo:6;//  Bit 0~bit5：无1#~6#币值找零，1有效
	DWORD :2;

	WORD uiChangeDeno[6];	//对应1#~6#找零币值
}ST_TVM_WORK_MODE;

/*AG工作模式*/
typedef struct
{
    //Byte 0：工作模式
    DWORD iWorkModeMaintence:1;//  Bit 0：非维修模式，1维修模式
    DWORD iWorkModeAllowEntry:1;//  Bit 1：允许进站检票，1有效
    DWORD iWorkModeAllowExitWd:1;//  Bit 2：允许出站回收检票，1有效
    DWORD iWorkModeAllowExitUnwd:1;//  Bit 3：允许出站刷卡检票，1有效
    DWORD iWorkModeOutService:1;//  Bit 4：暂停服务模式，1有效
    DWORD iWorkModeCloseService:1;//  Bit 5：关闭服务模式，1有效
    DWORD iWorkModeTrainFail:1;//  Bit 6：列车故障模式，1有效
    DWORD iWorkModeEmergency:1;//  Bit 7：紧急模式，1有效

    //Byte 1-3：预留
  	DWORD :24;

	WORD reserve[6];	//预留
}ST_AG_WORK_MODE;
/*
 * TVM上报的状态
 */
typedef struct
{
	ST_SYSTEM_SETTING_STATUS stSystemSettingStatus;    //外部设置状态
	ST_TVM_WORK_MODE stTvmWorkMode;
	int iErrorCodeCount;
	ST_DEVICE_ERROR_CODE pstErrorCode[SYSTEM_ERROR_CODE_COUNT];
}ST_TVM_SYSTEM_STATUS;

/*
 * AG上报的状态
 */
typedef struct
{
	ST_SYSTEM_SETTING_STATUS stSystemSettingStatus;    //外部设置状态
	ST_AG_WORK_MODE stAgWorkMode;
	int iErrorCodeCount;
	ST_DEVICE_ERROR_CODE pstErrorCode[SYSTEM_ERROR_CODE_COUNT];
}ST_AG_SYSTEM_STATUS;


/*BOM工作模式*/
typedef struct
{
    //Byte 0：工作模式
    DWORD iWorkModeDeviceMode:1;//  Bit 0：设备故障模式，1设备正常
    DWORD iWorkModeOperationArea:1;//Bit 1:0非付费区，1付费区
    DWORD iWorkModeOperatorLogon:1;//Bit 2：0无用户登录，1用户登录
    DWORD iWorkModeTrainFail:1;//  Bit 3：列车故障模式，1有效
    DWORD iWorkModeEmergency:1;//  Bit 4：紧急模式，1有效

    //Byte 1-3：预留
  	DWORD :24;

	WORD reserve[6];	//预留
}ST_BOM_WORK_MODE;

/*
 *BOM上报的状态
 */
typedef struct
{
	ST_SYSTEM_SETTING_STATUS stSystemSettingStatus;    //外部设置状态
	ST_BOM_WORK_MODE stBOMWorkMode;
	int iErrorCodeCount;
	ST_DEVICE_ERROR_CODE pstErrorCode[SYSTEM_ERROR_CODE_COUNT];
}ST_BOM_SYSTEM_STATUS;
#endif /* AFCSTATUSTABLE_H_ */
