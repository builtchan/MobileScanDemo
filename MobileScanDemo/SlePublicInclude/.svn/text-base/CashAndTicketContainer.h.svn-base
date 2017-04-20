/*
 * CashAndTicketContainer.h
 *
 *  Created on: Jun 25, 2014
 *      Author: root
 */

#ifndef CASHANDTICKETCONTAINER_H_
#define CASHANDTICKETCONTAINER_H_

/* 钱箱的类型*/
typedef enum
{
	EM_CASHBOX_TYPE_SAFEBOX = 1,	//现金回收箱
	EM_CASHBOX_TYPE_LOOP = 2,		//循环找零箱
	EM_CASHBOX_TYPE_SPARE = 3,		//备用找零箱
	EM_CASHBOX_TYPE_SUPPLY = 4,		//找零补充箱
	EM_CASHBOX_TYPE_WASTE = 5,		//找零废钞回收箱
	EM_CASHBOX_TYPE_ESCROW = 6,		//现金暂存区
	EM_CASHBOX_TYPE_PASSENGER = 0xFF,	//乘客
}EM_CASH_CONTAINER_TYPE;

/* 票箱的类型*/
typedef enum
{
	EM_TICKETBOX_TYPE_NORMAL = 1,		//票箱
	EM_TICKETBOX_TYPE_WASTE = 2,		//废票箱
	EM_TICKETBOX_TYPE_SUPPLY = 3,		//补充箱，用于Token
	EM_TICKETBOX_TYPE_WITHDRAW = 4,		//清空回收箱，用于Token
	EM_TICKETBOX_TYPE_ESCROW = 5,		//车票暂存区
	EM_TICKETBOX_TYPE_PASSENGER = 0xFF,	//乘客
}EM_TICKET_CONTAINER_TYPE;

/* 钱箱票箱编号*/
typedef enum
{
	EM_BOX_NO_1 = 1,         //1号箱
	EM_BOX_NO_2 = 2,         //2号箱
	EM_BOX_NO_3 = 3,         //3号箱
	EM_BOX_NO_4 = 4,	     //4号箱
	EM_BOX_NO_5 = 5,         //5号箱
	EM_BOX_NO_6 = 6,	     //6号箱
	EM_BOX_NO_7 = 7,	     //7号箱
	EM_BOX_NO_8 = 8,	     //8号箱
	EM_BOX_NO_ALL = 0xFF,   //所有箱子
}EM_BOX_NO;


//定义现金动作类型；
typedef enum
{
	EM_CASH_ACTION_TYPE_ACCEPT = 1, /* 接收 */
	EM_CASH_ACTION_TYPE_REJECT = 2, /* 拒收 */
	EM_CASH_ACTION_TYPE_REFUND = 3, /* 退还 */
	EM_CASH_ACTION_TYPE_ENCASH = 4, /* 收入 */
	EM_CASH_ACTION_TYPE_CHANGE = 5, /* 找零 */
	EM_CASH_ACTION_TYPE_CHANGE_RECYCLE = 6, /* 找零回收 */
	EM_CASH_ACTION_TYPE_CLEAR = 7,  /* 清空 */
	EM_CASH_ACTION_TYPE_SUPPLY = 8,  /* 补充 */
}EM_CASH_ACTION_TYPE;

//定义车票动作类型；
typedef enum
{
	EM_TICKET_ACTION_TYPE_PROVIDE = 1, /* 提票 */
	EM_TICKET_ACTION_TYPE_WIWHDRAW = 2, /* 回收票卡 */
	EM_TICKET_ACTION_TYPE_OUT = 3,      /* 出票 */
	EM_TICKET_ACTION_TYPE_CLEAR = 4,      /* 清空 */
	EM_TICKET_ACTION_TYPE_SUPPLY = 5,      /* 补充 */

}EM_TICKET_ACTION_TYPE;

//定义现金类型；
typedef enum
{
	EM_CASH_TYPE_COIN = 1, /* 硬币 */
	EM_CASH_TYPE_BANKNOTE = 2, /* 纸币 */
}EM_CASH_TYPE;

typedef struct _ST_CASHBOX_LOCATION
{
	EM_CASH_TYPE emCashType;    //现金类型
	EM_CASH_CONTAINER_TYPE emCashboxType;    //钱箱类型
	EM_BOX_NO emCashboxNo;	//钱箱序号
}ST_CASH_CONTAINER_LOCATION;

typedef struct _ST_TICKETBOX_LOCATION
{
	EM_TICKET_CONTAINER_TYPE emTicketboxType;    //票箱类型
	EM_BOX_NO emTicketboxNo;	//票箱序号
}ST_TICKET_CONTAINER_LOCATION;

/*
 * 定义单个现金信息结构体
 * 数量默认为1
 * wangzp
 */
typedef struct
{
	EM_CASH_TYPE emCashType;
	int iDenomination;//面额，单位：分，如果1元纸币，则值为100
	char szGrownSize[20];//冠字号
	bool bBadMoney;//是否假币
}ST_CASH_INFO;

//钱箱数据信息定义用于业务与APP之间的参数
typedef struct _ST_BIZ_CASH_DATA_INFO
{
	EM_CASH_ACTION_TYPE emTvmAction;    //引起钱流转的动作
//	int iDenomination;
	int iCount;     //单个现金种类的数量（通过面额和冠字号以及流入/流出位置来区分现金种类) 当iCout>1时，为不区分单张现金信息，如：清空，补充操作等，如果为1，则区分
	ST_CASH_INFO stCashInfo;
	ST_CASH_CONTAINER_LOCATION stOriginLocation;
	ST_CASH_CONTAINER_LOCATION stDestinationLocation;
}ST_BIZ_CASH_DATA_INFO;

//票箱数据信息定义用于业务与APP之间的参数
typedef struct _ST_TICKETBOX_DATA_UNIT_INFO
{
	EM_TICKET_ACTION_TYPE emTvmAction;    //引起票流转的动作
	int iTicketType;  //票卡类型
	int iCount;
	ST_TICKET_CONTAINER_LOCATION stOriginLocation;
	ST_TICKET_CONTAINER_LOCATION stDestinationLocation;
}ST_BIZ_TICKET_DATA_INFO;

/*钱票箱安装状态（逻辑）*/
typedef enum
{
	//票箱状态值	票箱状态名称
	CONTAINER_INSTALL_STATUS_NORMAL_ONLOAD= 0x01,					  /*正常安装*/
	CONTAINER_INSTALL_STATUS_LAWLESSLY_ONLOAD= 0x02,				/*非法安装*/
	CONTAINER_INSTALL_STATUS_NORMAL_OFFLOAD= 0x03,					/*正常卸下*/
	CONTAINER_INSTALL_STATUS_LAWLESSLY_OFFLOAD= 0x04,				/*非法卸下*/
}EM_CONTAINER_INSTALL_STATUS;
/*钱票箱安装状态（逻辑）*/

//容器操作类型longjg
typedef enum _EM_CONTAINER_OPERATION_TYPE_
{
	EM_CONTAINER_OPERATION_TYPE_SET = 0x01,							//安装
	EM_CONTAINER_OPERATION_TYPE_DOWN = 0x02,						//卸下
	EM_CONTAINER_OPERATION_TYPE_SUPPLY = 0x03,						//补充
	EM_CONTAINER_OPERATION_TYPE_FLUSH = 0x04,						//清空
	EM_CONTAINER_OPERATION_TYPE_DOWN_AND_SET = 0x05,    			//卸下且安装
	EM_CONTAINER_OPERATION_TYPE_RECYCLE = 0x06,						//回收
	EM_CONTAINER_OPERATION_TYPE_GO_UP = 0x07,						//上升
	EM_CONTAINER_OPERATION_TYPE_GO_DOWN = 0x08,						//下降
	EM_CONTAINER_OPERATION_TYPE_UNLOCK = 0x09,						//解锁
	EM_CONTAINER_OPERATION_TYPE_LOCK = 0x0A,						//上锁
	EM_CONTAINER_OPERATION_TYPE_INIT = 0x0B,						//对箱子的归属部件初始化
}EM_CONTAINER_OPERATION_TYPE;

//容器操作反馈结果longjg
typedef enum _EM_CONTAINER_OPERATION_RESULT_
{
	EM_CONTAINER_OPERATION_RESULT_TIME_OUT_NO_ACTION = 0x01,		//超时未响应
	EM_CONTAINER_OPERATION_RESULT_ACTION_EXE_FAIL = 0x02,			//动作执行失败
	EM_CONTAINER_OPERATION_RESULT_ACTION_EXE_SUCCESS = 0x03,		//动作执行成功
}EM_CONTAINER_OPERATION_RESULT;

typedef enum
{
	//票箱状态值	票箱状态名称
	EM_CONTAINER_POSITION_STATUS_STORE= 0x01,		/*在库*/
	EM_CONTAINER_POSITION_STATUS_OPERATOR= 0x02,	/*在手*/
	EM_CONTAINER_POSITION_STATUS_DEVICE= 0x03,		/*在设备*/
}EM_CONTAINER_POSITION_STATUS;

typedef enum
{
	//2.3	钱票箱RFID的适用性
	EM_CONTAINER_RFID_TYPE_RW = 1,	//1	Read/Write RFID	具有RFID，需读写
	EM_CONTAINER_RFID_TYPE_R = 2,	//2	Read  RFID	具有RFID，仅读
	EM_CONTAINER_RFID_TYPE_NONE = 3,	//3	No RFID	没有RFID
}EM_CONTAINER_RFID_TYPE;

typedef enum
{
	//2.4	钱票箱RFID读写器的适用性
	EM_CONTAINER_RFID_READER_TYPE_FIRMWARE = 1,	//1	Firmware	由硬件模块负责RFID处理
	EM_CONTAINER_RFID_READER_TYPE_RFID1 = 2,		//2	RFID1	由1#独立RFID读写器处理
	EM_CONTAINER_RFID_READER_TYPE_RFID2 = 3,		//3	RFID2	由2#独立RFID读写器处理
	EM_CONTAINER_RFID_READER_TYPE_RFID3 = 4,		//4	RFID3	由3#独立RFID读写器处理
	EM_CONTAINER_RFID_READER_TYPE_NONE = 5,		//5	No RFID	没有RFID
}EM_CONTAINER_RFID_READER_TYPE;

typedef enum
{
	//2.5	钱票箱”新值”来源的适用性
	EM_CONTAINER_VALUE_FROM_RFID = 1,	//1	RFID	从RFID读取
	EM_CONTAINER_VALUE_FROM_INPUT = 2,	//2	INPUT	操作员输入
	EM_CONTAINER_VALUE_FROM_DEFAULT = 3,	//3	DEFAULT VALUE	设为默认值
	EM_CONTAINER_VALUE_FROM_RFID_AND_INPUT = 4,  //从RFID和INPUT， 若两者不一致INPUT优先
}EM_CONTAINER_VALUE_FROM;

typedef enum
{
	//2.6	钱票箱ID来源的适用性
	EM_CONTAINER_ID_FROM_RFID = 1,	//1	RFID	从RFID读取
	EM_CONTAINER_ID_FROM_INPUT = 2,	//2	INPUT	操作员输入
	EM_CONTAINER_ID_FROM_DEFAULT = 3,	//3	DEFAULT VALUE	设为默认值
}EM_CONTAINER_ID_FROM;

typedef enum
{
	//2.7	钱票箱到位检测的适用性
	EM_CONTAINER_READY_DETECT_FROM_RFID = 1,	//1	RFID	根据RFID判断
	EM_CONTAINER_READY_DETECT_FROM_SENSOR = 2,	//2	SENSOR	根据到位传感器判断
	EM_CONTAINER_READY_DETECT_FROM_NONE = 3,	//3	NONE	不检测
}EM_CONTAINER_READY_DETECT_FROM;

typedef enum
{
	//2.8	钱票箱锁的适用性
	EM_CONTAINER_LOCK_TYPE_ELECT = 1,	//1	电子锁	由软件控制
	EM_CONTAINER_LOCK_TYPE_NO_ELECT = 2,	//2	无电子锁	由机械控制
}EM_CONTAINER_LOCK_TYPE;

typedef enum
{
	//2.9	非法更换的适用性
	EM_CONTAINER_ILLEGAL_CHANGE_ALLOW = 1,	//1	完全允许，等同正常更换
	EM_CONTAINER_ILLEGAL_CHANGE_LOG = 2,	//2	允许，记录非法更换
	EM_CONTAINER_ILLEGAL_CHANGE_REFUSE = 3,	//3	不允许
}EM_CONTAINER_ILLEGAL_CHANGE_FLAG;


typedef enum
{
	//2.10	状态计算的适用性
	EM_CONTAINER_STATE_COMPUTE_COMPREHENSIVE = 1,	//1	综合物理状态和逻辑状态进行计算
	EM_CONTAINER_STATE_COMPUTE_PHYSICAL = 2,	//2	只考虑物理状态，不考虑逻辑状态
	EM_CONTAINER_STATE_COMPUTE_LOGIC = 3,	//3	只考虑逻辑状态，不考虑物理状态
}EM_CONTAINER_STATE_COMPUTE_FLAG;

typedef struct _ST_CASHBOX_CONFIG_INFO_
{
	unsigned int uiMediumType;									//钱箱钱币面额，或者票箱车票类型
	EM_CONTAINER_RFID_TYPE emContainerRfidType;					//钱票箱RFID的适用性
	EM_CONTAINER_RFID_READER_TYPE emContainerRfidReaderType;	//钱票箱RFID读写器的适用性
	EM_CONTAINER_VALUE_FROM emContainerValueFrom;				//钱票箱”新值”来源的适用性
	EM_CONTAINER_ID_FROM emContainerIdFrom;						//钱票箱ID来源的适用性
	EM_CONTAINER_READY_DETECT_FROM emContainerReadyDetectFrom;	//钱票箱到位检测的适用性
	EM_CONTAINER_LOCK_TYPE emSetLockType;						//钱票箱锁的适用性-安装
	EM_CONTAINER_LOCK_TYPE emDownLockType;						//钱票箱锁的适用性-卸下
	EM_CONTAINER_LOCK_TYPE emSupplyLockType;					//钱票箱锁的适用性-补充
	bool bTypeValidCheck;				//介质类型有效性检查
	unsigned int iDefaultID;			//缺省ID
	int iDefaultValue;					//缺省”新值”
	int iLockTimeoutTime;				//锁超时时间参数
	EM_CONTAINER_ILLEGAL_CHANGE_FLAG emIllegalChangeDownFlag;		//非法更换的适用性-卸下
	EM_CONTAINER_ILLEGAL_CHANGE_FLAG emIllegalChangeSetFlag;		//非法更换的适用性-安装
	EM_CONTAINER_STATE_COMPUTE_FLAG emStateComputeFlag;				//状态计算的适用性
}ST_CONTAINER_CONFIG_INFO;


typedef struct _ST_TICKETBOX_RFID_INFO_
{
	unsigned char szBoxID[4]; 			//票箱编号
	unsigned char szDeviceID[8]; 		//设备ID
    unsigned char szStationID[4] ;  	//车站ID
	ST_TICKET_CONTAINER_LOCATION stInstallLocation ; 		//票箱在设备中的安装位置
	char szOperatorCode[20];			//操作员代码，字符串类型， 例如： 15411001, 没有填'/0'
	EM_CONTAINER_POSITION_STATUS emCBoxPositionStatus ;   	//票箱位置状态
	EM_CONTAINER_INSTALL_STATUS emBoxInstallStatusAfter ;  	//操作后票箱状态                                             //操作后票箱状态       [ 0x01：正常安装；0x02：非法安装 0x03：正常卸下；0x04：非法卸下]
	unsigned int uiProductType;			//产品类型
	unsigned short usProductSubType; 	//车票产品子类型
	unsigned int uiTicketCount;			//票卡数量
    unsigned char szRfidOriginalData[2048];					//读出的RFID原始数据
}ST_TICKETBOX_RFID_INFO;

typedef struct _ST_CASHBOX_RFID_INFO_
{
	unsigned char szBoxID[4]; 		//钱箱编号
	unsigned char szDeviceID[8]; 	//设备ID
    unsigned char szStationID[4] ;  //车站ID
    ST_CASH_CONTAINER_LOCATION stInstallLocation ; 		//钱箱在设备中的安装位置
	char szOperatorCode[20];		//操作员代码，字符串类型， 例如： 15411001, 没有填'/0'
	EM_CONTAINER_POSITION_STATUS emCBoxPositionStatus ;   	//钱箱位置状态
	EM_CONTAINER_INSTALL_STATUS emBoxInstallStatusAfter ;   //操作后钱箱状态                                             //操作后票箱状态       [ 0x01：正常安装；0x02：非法安装 0x03：正常卸下；0x04：非法卸下]
	unsigned int uiDenomination;	//面额,0 表示多币种回收箱
	unsigned int uiCashCount;		//钱币总数量,纸币的张数或硬币的总张数或枚数。
	unsigned int uiCashAmount;		//钱币总金额
    unsigned char szRfidOriginalData[2048];					//读出的RFID原始数据
}ST_CASHBOX_RFID_INFO;


typedef struct
{
  int iDenomination;        //面额
  int iCount;               //当前张数
}ST_CASH_DETAIL_INFO_RECORD;


typedef struct
{
  int iRecordCount;               //面额种类数量
  ST_CASH_DETAIL_INFO_RECORD szCashDetailInfoRecordStruct[20];
}ST_CASH_DETAIL_INFO;


typedef struct
{
  int iTicketType;        //票种类
  int iCount;             //当前数量
}ST_TICKET_DETAIL_INFO_RECORD;


typedef struct
{
  int iRecordCount;               //面额种类数量
  ST_TICKET_DETAIL_INFO_RECORD szTicketDetailInfoRecordStruct[20];
}ST_TICKET_DETAIL_INFO;





typedef struct
{
	ST_CASH_CONTAINER_LOCATION stCashboxLocation;
	EM_CONTAINER_INSTALL_STATUS emInstallStatus;
	EM_BOX_PHYSICS_STATUS emCashboxStatus;
	char szBoxID[9];

	int iCashCount;		//数量
	int iCashAmount;	//总金额
	int iDenomination;	//面额，对于多种面额钱箱，填0

	ST_CASH_DETAIL_INFO stCashDetailInfo;

	char szInstallOperatorID[20];     //箱子安装操作员ID
	char szInstallDate[9];    //箱子安装日期
	char szInstallTime[7];    //箱子安装时间
	int iInstallCount;        //安装时的初始数量

}ST_CASHBOX_INFO;

typedef struct
{
	ST_TICKET_CONTAINER_LOCATION stTicketboxLocation;
	EM_CONTAINER_INSTALL_STATUS emInstallStatus;
	EM_BOX_PHYSICS_STATUS emTicketboxStatus;
	char szBoxID[9];

	int iTicketCount;	//数量
	int iTicketType;	//票类型
	ST_TICKET_DETAIL_INFO stTicketDetailInfo;	//明细

	char szInstallOperatorID[20];     //箱子安装操作员ID
	char szInstallDate[9];    //箱子安装日期
	char szInstallTime[7];    //箱子安装时间
	int iInstallCount;        //安装时的初始数量

}ST_TICKETBOX_INFO;


/* brief 钱箱更换结构体 */
typedef struct
{
	unsigned int uiAfcSeq;	//AFC业务数据序号
	ST_CASH_CONTAINER_LOCATION stCashboxLocation;
	EM_CONTAINER_OPERATION_TYPE em_OperationType;
	EM_CONTAINER_INSTALL_STATUS emInstallStatus;
	//操作员代码，字符串类型， 例如： 15411001, 没有填'/0'
	char szOperatorCode[20];
	//运营日期， 有效长度8位字符的字符串， 如：20141119
	char szRunDate[9];
	//业务日期， 有效长度8位字符的字符串， 如：20141119
	char szBusiDate[9];
	//业务时间， 有效长度8位字符的字符串， 如：154134
	char szBusiTime[7];
	unsigned char szDeviceCode[8];
	char szBoxID[9];

	//更换前
	int iCashCountBefore;	//数量
	int iCashAmountBefore;	//总金额，对于多面额箱子安装时，填写0；
	ST_CASH_DETAIL_INFO stCashDetailInfoBefore;	//明细

	//更换后
	int iCashCountAfter;	//数量
	int iCashAmountAfter;	//总金额
	ST_CASH_DETAIL_INFO stCashDetailInfoAfter;	//明细
}ST_CASHBOX_CHANGE_INFO;


/* brief 票箱更换结构体 */
typedef struct
{
	unsigned int uiAfcSeq;	//AFC业务数据序号
	ST_TICKET_CONTAINER_LOCATION stTicketboxLocation;
	EM_CONTAINER_OPERATION_TYPE em_OperationType;
	EM_CONTAINER_INSTALL_STATUS emInstallStatus;
	//操作员代码，字符串类型， 例如： 15411001, 没有填'/0'
	char szOperatorCode[20];
	//运营日期， 有效长度8位字符的字符串， 如：20141119
	char szRunDate[9];
	//业务日期， 有效长度8位字符的字符串， 如：20141119
	char szBusiDate[9];
	//业务时间， 有效长度8位字符的字符串， 如：154134
	char szBusiTime[7];
	unsigned char szDeviceCode[8];
	char szBoxID[9];

	//更换前
	int iTicketCountBefore;	//数量
	ST_TICKET_DETAIL_INFO stTicketDetailInfoBefore;	//明细
	//更换后
	int iTicketCountAfter;	//数量
	ST_TICKET_DETAIL_INFO stTicketDetailInfoAfter;	//明细

}ST_TICKETBOX_CHANGE_INFO;

//钱箱更换中 手动输入数据信息
typedef struct _ST_CASH_BOX_INPUT_INFO_
{
	ST_CASH_CONTAINER_LOCATION  stCashBoxPosition;		//钱箱位置信息
	bool bInputInfoForCount;							//是否输入数量
	bool bInputInfoForBoxId;							//是否输入箱子ID
	bool bInputDeno;									//是否输入面额
	int iCount;											//换上的数量
	char szBoxId[9];									//换上箱子的ID
	int iDeno;											//换上的箱子面额
}ST_CASH_BOX_INPUT_INFO;

//票箱更换中 手动输入数据信息
typedef struct _ST_TICKET_BOX_INPUT_INFO
{
	ST_TICKET_CONTAINER_LOCATION  stTicketBoxPosition;	//票箱位置信息
	bool bInputInfoForCount;							//是否输入数量
	bool bInputInfoForBoxId;							//是否输入箱子ID
	bool bInputTicketType;								//是否输入票卡类型
	int iCount;											//换上的数量
	char szBoxId[9];									//换上箱子的ID
	int iTicketType;									//换上的箱子票卡类型
} ST_TICKET_BOX_INPUT_INFO;

//定义终端设备单据类型(用于打印)
typedef enum _EM_SLE_DEVICE_VOUCHER_TYPE_
{
	EM_SLE_DEVICE_COIN_SUPPLY_BOX_NORMAL_CHANGE_VOUCHER = 1,			//硬币补充箱正常更换小单
	EM_SLE_DEVICE_COIN_SUPPLY_BOX_ILLEGAL_CHANGE_VOUCHER = 2,			//硬币补充箱非法更换小单
	EM_SLE_DEVICE_COIN_WITHDRAW_BOX_NORMAL_CHANGE_VOUCHER = 3,			//硬币回收箱正常更换小单
	EM_SLE_DEVICE_COIN_WITHDRAW_BOX_ILLEGAL_CHANGE_VOUCHER = 4,			//硬币回收箱非法更换小单
	EM_SLE_DEVICE_COIN_CLEAR_EMPTY_VOUCHER = 5,							//硬币清空小单

	EM_SLE_DEVICE_BILL_SUPPLY_VOUCHER = 6,								//纸币补充小单
	EM_SLE_DEVICE_BILL_SPARE_CHANGE_BOX_ILLEGAL_CHANGE_VOUCHER = 7,		//纸币备用找零箱非法更换小单
	EM_SLE_DEVICE_BILL_WITHDRAW_BOX_NORMAL_CHANGE_VOUCHER = 8,			//纸币回收箱正常更换小单
	EM_SLE_DEVICE_BILL_WITHDRAW_BOX_ILLEGAL_CHANGE_VOUCHER = 9,			//纸币回收箱非法更换小单
	EM_SLE_DEVICE_BILL_WASTE_BOX_NORMAL_CHANGE_VOUCHER = 10,			//纸币废钞箱正常更换小单
	EM_SLE_DEVICE_BILL_WASTE_BOX_ILLEGAL_CHANGE_VOUCHER = 11,			//纸币废钞箱非法更换小单
	EM_SLE_DEVICE_BILL_SPARE_CHANGE_BOX_NORMAL_CHANGE_VOUCHER = 12,		//纸币备用找零箱正常更换小单

	EM_SLE_DEVICE_TICKET_SUPPLY_BOX_NORMAL_CHANGE_VOUCHER = 13,			//车票补充小单
	EM_SLE_DEVICE_TICKET_WITHDRAW_BOX_NORMAL_CHANGE_VOUCHER = 14,		//车票回收箱正常更换小单
	EM_SLE_DEVICE_TICKET_WITHDRAW_BOX_ILLEGAL_CHANGE_VOUCHER = 15,		//车票回收箱非法更换小单
	EM_SLE_DEVICE_TICKET_WASTE_BOX_NORMAL_CHANGE_VOUCHER = 16,			//车票废票箱正常更换小单
	EM_SLE_DEVICE_TICKET_WASTE_BOX_ILLEGAL_CHANGE_VOUCHER = 17,			//车票废票箱非法更换小单
	EM_SLE_DEVICE_TICKET_CLEAR_EMPTY_VOUCHER = 18,						//车票清空小单

	EM_SLE_DEVICE_SETTLE_VOUCHER = 19,									//TVM收益单据
	EM_SLE_DEVICE_FAULT_TRANS_LESS_CHANGE_VOUCHER = 20,					//少找零小单
	EM_SLE_DEVICE_FAULT_TRANS_LESS_OUTTICKET_VOUCHER = 21,				//少出票小单

	EM_SLE_DEVICE_RECHARGE_PRINT_VOUCHER = 22,							//充值成功单据
	EM_SLE_DEVICE_RECHARGE_FAULT_PRINT_VOUCHER = 23,					//充值故障单据(充值未成功, 但退款失败)
	EM_SLE_DEVICE_COIN_SPARE_CHANGE_BOX_NORMAL_CHANGE_VOUCHER = 24,    	//硬币备用找零箱更换小单
	EM_SLE_DEVICE_COIN_SPARE_CHANGE_BOX_ILLEGAL_CHANGE_VOUCHER = 25,   	//硬币备用找零箱非法更换小单
	EM_SLE_DEVICE_COIN_SPARE_CHANGE_BOX_SUPPLY_VOUCHER = 26,			//硬币备用找零箱补充(安装)小单

	EM_SLE_DEVICE_BILL_SUPPLY_BOX_NORMAL_CHANGE = 27,					//纸币补充箱正常更换小单
	EM_SLE_DEVICE_BILL_SUPPLY_BOX_ILLEGAL_CHANGE = 28,					//纸币补充箱非法更换小单
	EM_SLE_DEVICE_BILL_CLEAR_EMPTY_VOUCHER = 29,						//纸币清空小单

	EM_SLE_DEVICE_AUTO_BALANCE_VOUCHER = 30,							//TVM自动结存单据（长单）
	EM_SLE_DEVICE_RECHARGE_ABNORMAL_PRINT_VOUCHER = 31,					//充值异常单据(闪卡单据)
	EM_SLE_DEVICE_SVT_BUY_TICKET_FAULT_PRINT_VOUCHER = 32,				//储值卡购票故障单据(扣费成功但是出票少了)

	EM_SLE_DEVICE_CANCEL_TRANS_REFUND_CASH_FAIL_VOUCHER = 33,			//交易取消退款失败单据

	EM_SLE_DEVICE_COIN_WD_BOX_LOAD_VOUCHER = 34,						//硬币回收箱安装小单
	EM_SLE_DEVICE_COIN_WASTE_BOX_LOAD_VOUCHER = 35,						//硬币废钞箱安装小单

	EM_SLE_DEVICE_BILL_WD_BOX_LOAD_VOUCHER = 36,						//纸币回收箱安装小单
	EM_SLE_DEVICE_BILL_WASTE_BOX_LOAD_VOUCHER = 37,						//纸币废钞箱安装小单

	EM_SLE_DEVICE_TICKET_WD_BOX_LOAD_VOUCHER = 38,						//车票回收箱安装小单
	EM_SLE_DEVICE_TICKET_WASTE_BOX_LOAD_VOUCHER = 39,					//车票废票箱安装小单

	/*故障单据以后依次添加*/
}EM_SLE_DEVICE_VOUCHER_TYPE;

//定义容器内存储物质类型longjg
typedef enum _EM_CONTAINER_STORE_TYPE_
{
	EM_CONTAINER_STORE_TYPE_COIN = 1,									//硬币
	EM_CONTAINER_STORE_TYPE_BANKNOTE = 2,								//纸币
	EM_CONTAINER_STORE_TYPE_TICKET = 3,									//票卡
}EM_CONTAINER_STORE_TYPE;

//定义容器类型longjg
typedef enum _EM_CONTAINER_TYPE_
{
	EM_CONTAINER_TYPE_CASH_RECYCLE_BOX = 1,								//现金回收箱
	EM_CONTAINER_TYPE_LOOP_CHANGE_BOX = 2,								//循环找零箱
	EM_CONTAINER_TYPE_SPARE_CHANGE_BOX = 3,								//备用找零箱
	EM_CONTAINER_TYPE_CHANGE_SUPPLY_BOX = 4,							//找零补充箱
	EM_CONTAINER_TYPE_WASTE_CASH_BOX = 5,								//找零废钞箱
	EM_CONTAINER_TYPE_CASH_ESCROW = 6,									//现金暂存区

	EM_CONTAINER_TYPE_NORMAL_TICKET_BOX = 11,							//票箱
	EM_CONTAINER_TYPE_WASTE_TICKET_BOX = 12,							//废票箱
	EM_CONTAINER_TYPE_SUPPLY_TICKET_BOX = 13,							//补充箱
	EM_CONTAINER_TYPE_TICKET_RECYCLE_BOX = 14,							//清空回收箱
	EM_CONTAINER_TYPE_TICKET_ESCROW = 15,								//车票暂存区

	EM_CONTAINER_TYPE_PASSENGER = 0xFF,									//乘客
}EM_CONTAINER_TYPE;

//定义容器位置信息longjg
typedef struct _ST_CONTAINER_LOCATION_
{
	EM_CONTAINER_STORE_TYPE emContainerStoreType;    					//容器存储类型
	EM_CONTAINER_TYPE emContainerType;    								//容器类型
	EM_BOX_NO emContainerBoxNo;											//容器序号
}ST_CONTAINER_LOCATION;

//定义容器内存储记录信息longjg
typedef struct _ST_CONTAINER_RECORD_INFO_
{
	DWORD dwStoreInfo;													//容器内存储物质的信息(涉及现金填面额, 涉及票卡填票卡类型, 初始值来自主控, 更换结束用于维修界面输入信息回馈)
	WORD wStoreNumBeforeContainerChange;								//容器更换前存储的数量(进入更换前的初始数量)
	WORD wCurStoreNum;													//容器当前的数量(只有换下操作或者换补充过程完成才会发生变化)
	WORD wInputSupplyNum;												//容器补充的数量(用于维修界面输入信息回馈)
}ST_CONTAINER_RECORD_INFO;

//定义容器当前逻辑状态
typedef enum _EM_CONTAINER_PHYSICS_STATUS_
{
	EM_CONTAINER_PHYSICS_STATUS_INSTALLED = 0x01,						//已安装
	EM_CONTAINER_PHYSICS_STATUS_REPLACED = 0x02,						//已换下
}EM_CONTAINER_PHYSICS_STATUS;

//定义容器详细记录信息longjg
typedef struct _ST_CONTAINER_DETAIL_INFO_
{
	ST_CONTAINER_LOCATION stContainerLocation;							//容器位置
	EM_CONTAINER_INSTALL_STATUS emLogicalStatus;						//容器逻辑状态
	EM_BOX_PHYSICS_STATUS emDeviceStatus;								//容器部件状态
	EM_CONTAINER_PHYSICS_STATUS emPhyStatus;							//容器物理状态
	char szContainerId[9];												//容器Id(初始值来自主控, 更换结束用于维修界面输入信息回馈)

	int iStoreTotalNum;													//容器内物质存储总数量
	int iStoreTotalAmount;												//容器内物质存储总金额(如不涉及金额填0)

	int iSupplyTotalNum;												//容器补充的总数量(用于维修界面输入信息回馈)
	int iContainerRecordCount;											//容器存储记录条数
	ST_CONTAINER_RECORD_INFO stRecordInfoArray[20];						//容器内存储记录信息集合

	char szInstallOperatorID[20];     									//容器安装时的操作员Id
	char szInstallDate[9];    											//容器安装日期
	char szInstallTime[7];    											//容器安装时间
}ST_CONTAINER_DETAIL_INFO;

//定义结算任务状态longjg
typedef enum _EM_BALANCE_TASK_STATUS_
{
	EM_TASK_STATUS_FLUSHING = 0x01,										//清空进行中
	EM_TASK_STATUS_FLUSHED = 0x02,										//清空完成
	EM_TASK_STATUS_FLUSH_FAIL = 0x03,									//清空失败
	EM_TASK_STATUS_PLEASE_UNLOAD_AFTER_UNLOCK = 0x04,					//请解锁后换下
	EM_TASK_STATUS_PLEASE_UNLOAD = 0x05,								//请换下
	EM_TASK_STATUS_HAS_BEEN_REPLACED = 0x06,							//已换下
	EM_TASK_STATUS_RECYCLING = 0x07,									//回收进行中
}EM_BALANCE_TASK_STATUS;

//定义结算任务完成情况
typedef enum _EM_BALANCE_TASK_COMPLETE_STATUS_
{
	EM_TASK_COMPLETE_STATUS_FINISHED = 0x01,							//已完成
	EM_TASK_COMPLETE_STATUS_UNFINISHED = 0x02,							//未完成
}EM_BALANCE_TASK_COMPLETE_STATUS;

//结算结果详细信息
typedef struct _ST_BALANCE_DETAIL_INFO_
{
	int iDeno;
	int iNum;
}ST_BALANCE_DETAIL_INFO;

//定义结算时的动作类型
typedef enum _EM_BALANCE_ACTION_TYPE_
{
	EM_BALANCE_ACTION_TYPE_FLUSH = 1,									//清空
	EM_BALANCE_ACTION_TYPE_CHANGE = 2,									//更换
}EM_BALANCE_ACTION_TYPE;

//定义结算配置信息
typedef struct _ST_BALANCE_CFG_
{
	int iBalanceTaskNo;													//结算任务编号
	char szBalanceTaskName[50];											//结算任务名称
	ST_CONTAINER_LOCATION stContainerLocation;							//容器位置
	EM_BALANCE_ACTION_TYPE emBalanceActionType;							//结算时的动作类型
	bool bIsRelatedToEmpty;												//是否与清空关联
	bool bIsValidBalanceTask;											//有效的结算任务(纳入了结算流程)
}ST_BALANCE_CFG;

//定义结算任务信息longjg
typedef struct _ST_BALANCE_TASK_INFO_
{
	ST_BALANCE_CFG stBalanceCfg;										//结算配置信息
	bool bIsCashBox;													//是否为钱箱
	EM_BALANCE_TASK_STATUS emBalanceTaskStatus;							//结算任务状态
	EM_BALANCE_TASK_COMPLETE_STATUS emBalanceTaskCompleteStatus;		//结算任务完成情况
	int iDetailInfoCount;												//结算详细信息条目
	ST_BALANCE_DETAIL_INFO stBalanceInfoArray[10];						//结算详细信息
}ST_BALANCE_TASK_INFO;


#endif /* CASHANDTICKETCONTAINER_H_ */
