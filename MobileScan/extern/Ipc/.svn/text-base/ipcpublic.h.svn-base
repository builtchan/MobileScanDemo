/*!\file ipcpublic.h
 * \brief
 * \version
 * \author zhangbb
 * \date 2013-10-18
 */
#ifndef IPCPUBLIC_H_
#define IPCPUBLIC_H_
#include "AfcPublic.h"
//#include "IpcMsgCommCore.h"

/*
 * 电源管理消息通知类型
 * wangzp
 * 20150825
 */
typedef enum
{
	EM_POWER_OFF_NOTIFY = 1, //市电断开
	EM_POWER_ON_NOTIFY = 2, //市电恢复
	EM_POWER_LEVEL_NOTIFY = 3, //市电电量通知
}EM_POWER_MSG_NOTIFY;

/*
 * 寄存器数据
 * wangzp
 * 20150608
 */
typedef struct
{
	DWORD dwRegisterKey;
	DWORD dwRegisterValue;
}ST_REGISTER_DATA;

//------------------------------IIpcAgBizObject-------------------------------
/*! \brief 定义枚举型的数据结构ST_WORK_MODE
 *  \modify gyh 20140327
*/
typedef enum
{
    SUMMARY_EMER_GENCY_MODE = 1,//紧急模式
    SUMMARY_MAINTENANCE_MODE = 2,//维护模式
    SUMMARY_CLOSE_SERVICE_MODE = 3,//关闭服务模式
    SUMMARY_OUT_OF_SERVICE_MODE = 4,//暂停服务模式
    SUMMARY_ACTIVE_SERVICE_MODE = 5,//服务模式
}EM_SUMMARY_WORK_MODE;
/*!<工作模式>*/
/*! \brief 定义枚举型的数据结构
 * \modify gyh 20140327
*/
typedef enum
{
    ENTRY_OUT_OF = 1,//进站暂停模式
    ENTRY_CHECKING_FREE = 2,//进站免检
    WAITE_SWIPING = 3,//关闭服务模式
    OUT_OF_SWIPING = 4,//暂停服务模式
}EM_ENTRY_WORK_MODE;

typedef enum
{
    EXIT_OUT_OF = 1,   //进站暂停模式 1有效
    EXIT_CHECKING_FREE = 2,//进站免检 1有效
    WAITE_FOR_SWIPING_CARD = 3,//关闭服务模式 1有效
    OUT_OF_SWIPING_CARD = 4,//暂停服务模式 1有效
}EM_EXIT_WORK_MODE;






typedef struct __ST_AG_WORK_MODE__
{
        DWORD iInitUnfinish:1;		//初始化未完成 1有效
        DWORD iAllowEntryCheck:1;		//允许进站检票 1有效
        DWORD iAllowExitSwingCheck:1;	//允许出站刷卡检票 1有效
        DWORD iAllowExitWithdrawCheck:1;	//允许出站回收检票 1有效
        DWORD iOutOfServiceMode:1;		//暂停服务模式 1有效
        DWORD iCloseServiceMode:1;		//关闭服务模式 1有效
        DWORD iTrainFailureMode:1;			//列车故障模式 1有效
        DWORD iEmergencyMode:1;			//紧急模式 1有效
        DWORD iMaintain:1;                //维修模式1有效
        DWORD iPausePoll:1;                //等待对方通行暂停刷卡 1有效
        DWORD iEnterFree:1;                //进站免检
        DWORD iExitFree:1;                //出站免检
        DWORD :20;			           //预留
}ST_IPC_AG_WORK_MODE;

typedef struct __ST_WORK_MODE_TYPE__
{
    int iSummaryWorkMode:8 ;
    int iEntryWorkMode:8;
    int iExitWorkMode:8;
    int iExitRecycleWorkMode:8;
}ST_WORK_MODE_TYPE;

/*!<工作模式>*/
/*! \brief 定义枚举型的数据结构PHYSICAL_CONFIG
*
*/
typedef enum
{
    ENTRY_MACHINE = 1,		//进站机 1
    EXIT_MACHINE = 2,			//出站机 2
    DOUBLE_SIDE_MACHINE = 3,		//双向机 3
}EM_PHYSICAL_CONFIG;


typedef struct __ST_RECSET__
{
    int iErrorCode;
    char szAdditionalInfo[16];
}ST_RECSET;
/*! \brief 定义枚举型的数据结构ST_MODE_NOTIFY_DATA_INFO
 *  \modify gyh 20140327
*/
typedef struct __ST_MODE_NOTIFY_DATA_INFO__
{
    unsigned short  iDataFormat;	//数据格式=1：定长记录数据（包括单一数据体）
    unsigned short iRecNum;		//记录数量：故障代码数量
    unsigned short iRecLen;		//记录长度 =20
    ST_RECSET *stRecset;	//20*记录数
}ST_MODE_NOTIFY_DATA_INFO;


//查票通知信息


typedef struct __ST_CHECK_TICKET_RESULT7__
{
    unsigned short usCabinLevel ;
    unsigned short usLanguageType;
}ST_CHECK_TICKET_RESULT7;

typedef struct  __ST_CHECK_TICKET_OK_RESULT__
{
    int iTicketType;
    int iCheckTicketType;
    int iSpending;
    int iCardBalance; //卡内余额/余次
    int iValidDate; //有效期
    ST_CHECK_TICKET_RESULT7  stCabinValidDateInfo;//仓位语、言信息
}ST_CHECK_TICKET_OK_RESULT;
//-----------------------------------------------------------------
typedef struct __ST_STATE_CODE__
{
    DWORD iEntrySide:1;		//进站端通道，1有效
    DWORD iExitSide:1;		//出站端通道，1有效
    DWORD iEntrySideBusy:1;	//进站端忙，1有效
    DWORD iExitSidBusy:1;		//出站端忙，1有效
    DWORD iEntryFollow:1;		//进站尾随，1有效
    DWORD iExitFollow:1;	//出战尾随，1有效
    DWORD iReserve:28;
}ST_STATE_CODE;
typedef struct __ST_STATE_INFO__
{
    int iEntryAuthValue;
    int iExitAuthValue;
    ST_STATE_CODE stStateCode;
}ST_STATE_INFO;

//----------------------------end-------------------------------------


//********************************************IIpcTvmPassengerObject************************

/*! \brief 定义枚举型的数据结构ST_PAY_TYPE
*	支付类型枚举信息
*/
//typedef enum
//{
//    EM_PAY_TYPE_CASH_PAY = 0, //默认现金
//    EM_PAY_TYPE_BANCKCARD = 1,//银行卡
//    EM_PAY_TYPE_CST_PAY = 3,//储值卡
//    EM_PAY_TYPE_RERVERSE = 4,//预留
//}EM_PAY_TYPE;

/*! \brief 定义枚举型的数据结构TICKET_INFO
*	购票信息界面显示结构
*/
typedef struct _TICKET_INFO__
{
    unsigned int szDestination;	//目的车站
    unsigned int iSinglePrice; //单价金额
    unsigned int iTicketNum; //购票数量
    BYTE iTicketType;        //车票类型
    BYTE iCabinLevel;			//船舱登记
    BYTE iLanguageType;   //语言种类；
    int iReserve1;	//预留
    int iReserve2;	//预留
} TICKET_INFO;

/*! \brief 定义枚举型的数据结构TRANS_TYPE_CODE
* 	交易类型
*/
//typedef enum
//{
//    OPERTYPE_SJT_SALE	= 1,	//购票
//    OPERTYPE_CST_CHARGE	= 2,	//充值
//    OPERTYPE_CST_QUERY  = 3,	//查询
//}TRANS_TYPE_CODE;





/*! \brief 定义枚举型的数据结构ST_PAY_MODE_CODE
*	支付模式
*/
typedef  struct __ST_PAY_MODE_CODE__
{
    unsigned char AllowBill:1; //Bit 0：允许纸币，1有效
    unsigned char AllowCoin:1;//Bit 1：允许硬币，1有效	EM_IPCMSG_CORE_INNER_AG_INSERT_TICKET = 0x0011,		//AG车票投入通知

    unsigned char AllowSVT:1;//Bit 2：允许储值卡，1有效
    unsigned char AllowBankCard:1;//Bit 3：允许银行卡，1有效
    unsigned char AllowNfc:1;//Bit 4：允许NFC，1有效
    unsigned char AllowWeb:1;//Bit 5：允许网络预付，1有效
    unsigned char AllowVoucher:1;//Bit 6：允许代金券，1有效
    unsigned char AllowOther:1;//Bit 7：允许其他第三方，1有效
} ST_PAY_MODE_CODE;

/*! \brief 定义枚举型的数据结构ST_CHANDE_MODE_CODE
*	找零模式
*/
typedef  struct __ST_CHANGE_MODE_CODE__
{
    unsigned char NormalMode:1;//Bit0：正常找零
    unsigned char NoChangeMode:1;//Bit 1：无找零模式
    unsigned char NoCoinChangeMode:1;//Bit2：无硬币找零
    unsigned char NoBillChangeMode:1;//Bit3：无纸币找零
    unsigned char NoPartCoinChangeMode:1;//Bit4：无部分币值硬币找零
    unsigned char NoPartBillChangeMode:1;//Bit5：无部分币值纸币找零
    unsigned char Reserve:2;//Bit6~bit7：预留
} ST_CHANDE_MODE_CODE;

/*! \brief 定义枚举型的数据结构TICKET_VALIDITY
*	车票有效性：
*/
//typedef enum
//{
//    TICKET_VALIDITY_VALID = 1,	//有效
//    TICKET_VALIDITY_NO_LOCAL_SYSTEM	= 2,//非本系统车票
//    TICKET_VALIDITY_NOT_READERABLE = 3,	//车票不可读
//    TICKET_VALIDITY_NO_CURRENT_BIZ  =  4,	//车票不可进行当前业务
//} TICKET_VALIDITY;

/*! \brief 定义枚举型的数据结构ST_PAY_TYPE
*	付款类型
*/

/*! \brief 定义枚举型的数据结构EN_CURRENT_ACTION_TYPE
*	当前动作类型
*/
//typedef enum
//{
//    EN_CURRENT_ACTION_TYPE_SALE = 0, //售票
//    EN_CURRENT_ACTION_TYPE_CHARGE=1,//充值	EM_IPCMSG_CORE_INNER_AG_INSERT_TICKET = 0x0011,		//AG车票投入通知

//    EN_CURRENT_ACTION_TYPE_CHANGE = 2,//找零
//}EN_CURRENT_ACTION_TYPE;

//****************************************end****************************************************



//交易金额信息
typedef struct __ST_AMOUNT_INFO__
{
    int iTicketPrice;//票价总金额
    int iPayTotalAmount;//支付总金额
    int iShoudChangeAmount;// 应找零金额
    int iActualChangeAmount;// 实际找零金额
    bool bExitDisputedTicket;//Byte0：争议票0：不存在争议票 1：存在争议票，发售成功后出票失败
    bool bExsitChange;//Byte1：争议找零 0：不存在争议找零 1：存在争议找零，找零出钞口卡币
}ST_AMOUNT_INFO;

typedef struct  __ST_CHECK_TICKET_RESULT__
{
	/* 车票发行商	2HEX 与导则约定有关的具体票种类型 CSS_PRODUCT_ISSUERID_ACC = 0x01, 城市通： CSS_PRODUCT_ISSUERID_OCT = 0x99 */
	EM_CSS_PRODUCT_ISSUER_ID emCssProductIssuerId;
	/* 车票产品类型	2HEX 与导则约定有关的具体票种类型
	*  该字段，在保存收益信息时，会同步到 Busi_Incoming 表中，在结算业务数据生成时， 依据该字段，来按类别（单程票、地铁储值票、城市通票）统计： 免费更新、付费更新
	* [WH]票卡主类型
	* 01.单程票; 02.储值票; 03.乘次票 ;04.定期票; 05.ID票 ;07.员工票
	**/
	unsigned short usProductyType;
	unsigned short usProductySubType;
	/*交易（业务）类型 */
	EM_SLE_TRANSACATION_TYPE emTransType;
	//交易结果
	EM_TICKET_TRANS_RESULT emTransResult;
	//车票产品种类
	EM_CSS_PRODUCTY_CATEGORY emCssProductyCategory;

    int iAmount; //消费金额
    int iCardBalance; //卡内余额/余次
    int iValidDate; //有效期
	unsigned char ucSeatType;		// 仓位信息   --坐席类型s, 由UI赋值
	unsigned char ucLanguageType;	// 语言信息, 由UI赋值
	int iTpuErrorCode;					//项目化故障码，TPU返回
	unsigned char szReverve[100];	//预留
}ST_CHECK_TICKET_RESULT;

//AG工作模式通知
typedef struct
{
    //工作模式
    DWORD iWorkModeMaintence:1;//  Bit 0：非维修模式，1维修模式
    DWORD iWorkModeAllowEntry:1;//  Bit 1：允许进站检票，1有效
    DWORD iWorkModeAllowExitWd:1;//  Bit 2：允许出站回收检票，1有效
    DWORD iWorkModeAllowExitUnwd:1;//  Bit 3：允许出站刷卡检票，1有效
    DWORD iWorkModeOutService:1;//  Bit 4：暂停服务模式，1有效
    DWORD iWorkModeCloseService:1;//  Bit 5：关闭服务模式，1有效
    DWORD iWorkModeTrainFail:1;//  Bit 6：列车故障模式，1有效
    DWORD iWorkModeEmergency:1;//  Bit 7：紧急模式，1有效
    //运营模式
    DWORD iRunModeTrainFault:1;            //是否列车故障模式
    DWORD iRunModeFreeDate:1;              //是否日期免检模式
    DWORD iRunModeFreeTime:1;              //是否日期免检模式
    DWORD iRunModeFreeFare:1;              //是否车费免检模式
    DWORD iRunModeFreeEntryExit:1;         //是否进出站免检
    DWORD iRunModeFreeEntry:1;             //是否进站免检
    DWORD iRunMode24hour:1;                //是否24小时运营
    DWORD iDelayRunTime:1;					//是否延长运营时间

    DWORD iEntrySideMode:4;					//进站端模式 EM_AG_SIDE_MODE类型
    DWORD iExitWdSideMode:4;				//出站回收端模式 EM_AG_SIDE_MODE类型
    DWORD iExitUnwdSideMode:4;				//出站刷卡端模式 EM_AG_SIDE_MODE类型

	DWORD:4;				//预留

	EM_AG_DEVICE_SUB_TYPE emAgmType;		//AG设备子类型

}ST_AGM_MODE_NOTIFY;


typedef struct __ST_VERSION_INFO__
{
    int iVersionRec;		//版本记录n条
    char cBodyName[10];		//主体名称
    int iVersionInfoLen;		//版本信息长度
    char InfoLen[128];		//信息长度
}ST_VERSION_INFO;
//通道状态
typedef struct __ST_CHANNEL_STATE__
{
	BYTE cPowerOn:1;				//模块重新上电 1有效
	BYTE cEntryForce:1;				//进站闯入 1有效
	BYTE cExitForce:1;				//出站闯入 1有效
	BYTE cEntryTrailing:1;			//进站尾随 1有效
	BYTE cExitTrailing:1;			//出站尾随 1有效
	BYTE cEntryBusy:1;				//进站忙 1有效
	BYTE cExitBusy:1;				//出站忙 1有效
	BYTE cReserve2:1;				//预留

}ST_CHANNEL_STATE;

//**************************************************************************************************

#define MAX_ADDITIONAL_DATE_LENGTH 8192
/*!<消息文本结构体 SLE薛峰*/
typedef struct __ST_TEXT_DATA__
{
    int iMsgID;
    int iParam[6];
    int iAdditionalDataLen;
    unsigned char szAdditionalData[MAX_ADDITIONAL_DATE_LENGTH];
}ST_TEXT_DATA;

/*!<消息长度最大值 SLE薛峰*/
#define MAX_MSG_LENGTH  (1024 * 5)

/*!<消息队列通信数据结构 SLE薛峰*/
typedef struct __ST_IPC_MSG__
{
    int iMsgType;								/*!<消息类型*/
    unsigned char szMsgContent[MAX_MSG_LENGTH];	/*!<消息内容*/
}ST_IPC_MSG;

typedef struct _ST_IPCMSG_ADDITIONAL_RECORD_
{
    int iRecordLen;
    unsigned char szRecordData[MAX_ADDITIONAL_DATE_LENGTH];
}ST_IPCMSG_ADDITIONAL_RECORD;
//******************************************************************************************
//支付结构体信息
typedef struct  __ST_PAY_TYPE__
{
     unsigned int ucDefaultPayType:1; //默认
     unsigned int ucPayTypeCash :1;//现金
     unsigned int ucPayTypeBankCard:1;//银行卡
     unsigned int ucPayTypeSvtPay:1;//储值卡	EM_IPCMSG_CORE_INNER_AG_INSERT_TICKET = 0x0011,		//AG车票投入通知

     unsigned int ucReverse:28; //Bit~28
}ST_PAY_TYPE;

//购票信息界面显示结构
typedef struct __ST_TICKET_INFO__
{
    unsigned int szDestination;	//目的车站
    unsigned int iSinglePrice; //单价金额
    unsigned int iTicketNum; //购票数量
    unsigned int iTicketType;        //车票类型
//	unsigned int iCabinLevel;		//舱位等级
//	unsigned int iLanguageType;   //语言种类
    ST_PAY_TYPE  PayloadType;	//付款方式
    int iReserve;	//预留
} ST_TICKET_INFO;



/*! \brief 定义枚举型的数据结构EM_ASSISTANCE_STATE
* 	招援按钮状态
*/
typedef enum
{
    EM_ASSISTANCE_STATE_START = 0x00,/*按下招援按钮*/
    EM_ASSISTANCE_STATE_END	= 0x01,	/*取消招援按钮按下*/
}EM_ASSISTANCE_STATE;

//物理类型
typedef enum
{
    EM_PHYSICAL_TYPE_ENTRY = 1,		//进站机 1
    EM_PHYSICAL_TYPE_EXIT = 2,	//出站机 2
    EM_PHYSICAL_TYPE_DOUBLE = 3,	//双向机 3
}EM_PHYSICAL_TYPE;

// 票卡处理信息
typedef struct __ST_TICKET_TRANS_INFO__
{
int  iTotalTicketNum ;
int  iTotalChange;
int  iFinishedTicketNum;
int  iFinishedChange;
} ST_TICKET_TRANS_INFO;

//票卡处理动作	EM_IPCMSG_CORE_INNER_AG_INSERT_TICKET = 0x0011,		//AG车票投入通知

typedef enum
{
    EM_TRANS_ACTION_TYPE_ISSUE = 0,  	//发售中
    EM_TRANS_ACTION_TYPE_RECHARGE = 1,	//充值中
    EM_TRANS_ACTION_TYPE_CHANGE = 2,  	//找零中
    EM_TRANS_ACTION_TYPE_CANCEL = 3		//取消中
}EM_TRANS_ACTION_TYPE;

//支付信息typedef struct

typedef struct __ST_PAYMENTINFO__
{
    int iTradeTotalAmount;
    int iTicketNum;
    int iPayTotalAmount;
}ST_PAYMENTINFO;
//
////交易结果
// typedef enum
//{
//        EM_TRANS_RESULT_TICKET_SUCCESS = 1,//售票成功
//        EM_TRANS_RESULT_TICKET_FAILUE_RETURN_CHANGE_SUCCESS= 2,//售票失败、退款/找零成功
//        EM_TRANS_RESULT_TICKET_FAILUE_FAULTTRAN = 3,//售票失败，故障交易
//        EM_TRANS_RESULT_TICKET_FAIUE_JAM_FAULTTRAN = 4,//售票失败，卡币，故障交易
//        EM_TRANS_RESULT_TICKET_CANCEL_NOT_PUT_COIN_ = 5,//售票取消，未投币
//        EM_TRANS_RESULT_TICKET_CONCEL_REFUND_SUCCESS= 6,//售票取消，退款成功
//        EM_TRANS_RESULT_TICKET_CONCEL_REFUND_JAM_FAULTTRAN= 7,//售票取消，退款卡币，故障交易
//        EM_TRANS_RESULT_RECHARG_SUCCESS = 101,//充值成功
//        EM_TRANS_RESULT_RECHARG_FAILUE_REFUND_SUCCESS = 102,//充值失败，退款成功
//        EM_TRANS_RESULT_RECHARG_FAILUE_FAULTTRAN= 103,//充值失败，故障交易
//        EM_TRANS_RESULT_RECHARG_FAILUE_JAM_FAULTTRAN= 104,//充值失败，卡币，故障交易
//        EM_TRANS_RESULT_RECHARG_CANCEL_NOT_PUT_COIN= 105,//充值取消，未投币
//        EM_TRANS_RESULT_RECHARG_CANCEL_REFUND_JAM_SUCCESS= 106,//充值取消，退款成功
//        EM_TRANS_RESULT_RECHARG_CANCEL_REFUND_JAM_FAULTTRAN= 107,//充值取消，退款卡币，故障交易
//        EM_TRANS_RESULT_RECHARG_INVALIDITY_CARD= 108,//充值插入数据无效卡
//        EM_TRANS_RESULT_RECHARG_INVALIDITY_TYPE_CARD= 109,//充值插入不允许充值类型卡
//        EM_TRANS_RESULT_RECHARG_BLACK_LIST_CARD= 110,//充值插入黑名单卡
//        EM_TRANS_RESULT_QUERY_OVER= 201,//查询结束
//        EM_TRANS_RESULT_QUERY_INVALIDITY_CARD= 202,//查询插入数据无效卡
//        EM_TRANS_RESULT_QUERY_BLACK_LIST_CARD= 203,//查询插入黑名单卡
//} EM_TRANS_RESULT_CODE;


typedef enum
{
    EM_IPC_KEY_TVM_PASSENGER=80000,//TVM界面通信key标识
    EM_IPC_KEY_SLE_CORE_BIZ =80001,//SLE业务key标识
    EM_IPC_KEY_AG_PASSENGER =80002,//AG界面通信key标识
    EM_IPC_KEY_SLE_OPERATOR  =80003,//Operator业务通信key标识
    EM_IPC_KEY_SLE_COMM  =80004,//SLE COMM通信key标识
    EM_IPC_KEY_SLE_BOOT  =80005,//SLE BOOT业务通信key标识
    EM_IPC_KEY_OPER_UI   =80006, //维修界面
    //boot
    //comm
    //operui
}EM_IPC_KEY;


//大连AG界面CORE通信用，不能删！
typedef enum
{
   EM_PASSENGERS_PRETRADE_OPER_ID = 0x1101,//乘客交易前操作
   EM_TICKETING_TRANSACTION_ID = 0x1102,//售票交易请求
   EM_RECHARGE_ID = 0x1103,//充值交易请求
   EM_INQUIRE_ID = 0x1104,//查询交易请求
   EM_PASSENGER_TRANSACTION_CONFIRM_ID = 0x1105,//乘客确认交易
   EM_CANCEL_TRANSACTION_ID = 0x1106,//乘客取消交易
   EM_TICKETS_QUERY_ID = 0x1107,//票价查询
   EM_STATION_SEARCH_ID = 0x1108,//站点查询
   EM_TVM_VERSION_SEARCH_ID = 0x1109,  //版本查询
  //   = 0x110A,//请求招援
}EM_TVM_FOR_UI_MSG_ID;

typedef enum
{
 EM_TVM_WORK_MODE_NOTIFY_ID = 0x1110 ,//插入通知
 EM_INSERT_TICKET_ID = 0x1111,//票卡插入通知
 EM_PAYMENT_INFO_ID = 0x1112, //支付信息通知
 EM_CONFIRM_BUTTON_ID = 0x1113, //显示确认按钮通知
 EM_TICKET_CARD_PROCESSING_ID = 0x1114, //票卡处理通知
 EM_TRANS_OVER_ID = 0x1115, //交易结束通知
 EM_RECRUITAID_ID = 0x1116 ,//招援通知
}EM_TVM_FOR_BIZ_MSG_ID;

typedef enum
{
EM_AG_WORK_MODE_NOTIFY_ID = 0x1210,// 模式通知
EM_CHECK_SUCCESS_ID = 0x1211, //检票成功通知
EM_CHECK_FAIL_ID = 0x1212, //检票失败通知
EM_PASSAGE = 0x1213,//通道状态通知
EM_VERSION_SEARCH_ID = 0x1214, //版本信息通知
EM_AG_ENTRY_FREE_ID = 0x1215,  //进站免捡
EM_AG_ENTRY_PAUSE_ID = 0x1216, //进站暂停
EM_AG_WAIT_POLL_ID = 0x1217, //等待刷卡
EM_AG_PAUSE_POLL_ID = 0x1218, //暂停寻卡
EM_AG_POLL_CARD_ID = 0x1219, //寻到卡
}EM_AG_FOR_BIZ_MSG_ID;



typedef enum
{
	EM_IPCMSG_CORE_INNER_AG_INSERT_TICKET = 0x0011,		//AG车票投入通知
	EM_IPCMSG_CORE_INNER_AG_ENTRY_POLLING_TICKET = 0x0012,	//AG进站端寻卡通知
	EM_IPCMSG_CORE_INNER_AG_EXIT_WD_POLLING_TICKET = 0x0013,	//AG出站端回收寻卡通知
	EM_IPCMSG_CORE_INNER_AG_EXIT_UNWD_POLLING_TICKET = 0x0014,	//AG出站端刷卡寻卡通知
	EM_IPCMSG_CORE_INNER_EQM_POLLING_TICKET = 0x0015,	//EQM寻卡通知

	EM_IPCMSG_CORE_INNER_TVM_CASH_PAY = 0x0021,			//TVM现金投入通知
	EM_IPCMSG_CORE_INNER_TVM_PAYMENT_ERROR = 0x0022,	//TVM现金支付故障通知
	EM_IPCMSG_CORE_INNER_TVM_INSERT_OR_REFUND_CARD = 0x0023,		//TVM票卡插入通知
	EM_IPCMSG_CORE_INNER_TVM_INSERT_BANKCARD = 0x0024,	//TVM银行卡插入通知
	EM_IPCMSG_CORE_INNER_TVM_CASH_REJECT = 0x0025,		//TVM现金退币通知
	EM_IPCMSG_CORE_INNER_TVM_QRENCODE_PAY = 0x0026,     //二维码支付通知（TVIP）
	EM_IPCMSG_CORE_INNER_TVM_QRENCODE_PAY_RESULT_NOTIFY = 0x0027, //二维码支付结果通知（TVIP）

	EM_IPCMSG_CORE_INNER_SLE_STATUS_CHANGED = 0x0031,	//SLE模式/状态变化通知
	EM_IPCMSG_CORE_INNER_SLE_CASHBOX_OPERATION = 0x0041,	//钱箱被安装或卸下
	EM_IPCMSG_CORE_INNER_SLE_TICKETBOX_OPERATION = 0x0042,	//票箱被安装或卸下
	EM_IPCMSG_CORE_INNER_TVM_POLL_CARD = 0x0043,		//查询业务寻卡通知
	EM_IPCMSG_CORE_INNER_AG_QUERY_POLL_CARD = 0x0044,	//AG查询业务寻卡通知
	EM_IPCMSG_CORE_INNER_POWER_LEVEL_NOTIFY = 0x0045,	//电源管理通知

	EM_IPCMSG_CORE_INNER_SLE_CONTAINER_OPERATION = 0x0046,		//容器被安装或卸下(用于对接新版(维修QT版本)的钱票箱更换业务)longjg

	EM_IPCMSG_CORE_VENDING_TRANSFER_FIRST_PAY_CASH = 0x00A1,	//支付业务拼接-售票中转消息：首次投币
	EM_IPCMSG_CORE_VENDING_TRANSFER_INSERT_SVT = 0x00A2,		//支付业务拼接-售票中转消息：插入处置卡
	EM_IPCMSG_CORE_VENDING_TRANSFER_INSERT_BANKCARD = 0x00A3,	//支付业务拼接-售票中转消息：插入银行卡

	EM_IPCMSG_CORE_CHARGE_TRANSFER_FIRST_PAY_CASH = 0x00B1,	//支付业务拼接-充值中转消息：首次投币
	EM_IPCMSG_CORE_CHARGE_TRANSFER_INSERT_SVT = 0x00B2,		//支付业务拼接-充值中转消息：插入处置卡
	EM_IPCMSG_CORE_CHARGE_TRANSFER_INSERT_BANKCARD = 0x00B3,	//支付业务拼接-充值中转消息：插入银行卡

    EM_IPCMSG_TVMPASSENGER_TO_CORE_OPER_BEFORE_TRANS = 0x1101,	 //乘客交易前操作	请求报文
    EM_IPCMSG_TVMPASSENGER_TO_CORE_VENDING_BY_ALL = 0x1110, 	 //未确定支付方式的售票交易请求
    EM_IPCMSG_TVMPASSENGER_TO_CORE_VENDING_BY_CASH = 0x1111,	 //现金支付售票交易请求
    EM_IPCMSG_TVMPASSENGER_TO_CORE_VENDING_BY_SVT = 0x1112,		 //储值卡支付售票交易请求
    EM_IPCMSG_TVMPASSENGER_TO_CORE_VENDING_BY_BANKCARD = 0x1113, //银行卡支付售票交易请求
    EM_IPCMSG_TVMPASSENGER_TO_CORE_VENDING_BY_NFC = 0x1114,      //NFC支付售票交易请求
    EM_IPCMSG_TVMPASSENGER_TO_CORE_VENDING_BY_WEB = 0x1115,		 //网络预付售票交易请求
    EM_IPCMSG_TVMPASSENGER_TO_CORE_VENDING_BY_VOUCHER = 0x1116,	 //代金券支付售票交易请求
    EM_IPCMSG_TVMPASSENGER_TO_CORE_VENDING_BY_OTHER = 0x1117,	 //其他第三方支付售票交易请求	请求报文
    EM_IPCMSG_TVMPASSENGER_TO_CORE_VENDING_BY_QRCODE = 0x1118,	 //二维码支付售票交易请求请求	请求报文（TVIP）见：void CVirObjTvmCoreForUI::VendingTransRequest(const ST_TVM_VENDING_REQUEST_INFO * pstInfo)
    EM_IPCMSG_TVMPASSENGER_TO_CORE_VENDING_PAY_CONFIRM = 0x1119, //二维码支付确认请求			请求报文（TVIP）

    EM_IPCMSG_TVMPASSENGER_TO_CORE_CHARGE_BY_ALL = 0x1120, 		//未确定支付方式的充值交易请求请求
    EM_IPCMSG_TVMPASSENGER_TO_CORE_CHARGE_BY_CASH = 0x1121,		//现金支付充值交易请求请求
    EM_IPCMSG_TVMPASSENGER_TO_CORE_CHARGE_BY_SVT = 0x1122,		//储值卡支付充值交易请求请求
    EM_IPCMSG_TVMPASSENGER_TO_CORE_CHARGE_BY_BANKCARD = 0x1123,	//银行卡支付充值交易请求请求
    EM_IPCMSG_TVMPASSENGER_TO_CORE_CHARGE_BY_NFC = 0x1124,	//NFC支付充值交易请求请求
    EM_IPCMSG_TVMPASSENGER_TO_CORE_CHARGE_BY_WEB = 0x1125,		//网络预付充值交易请求请求
    EM_IPCMSG_TVMPASSENGER_TO_CORE_CHARGE_BY_VOUCHER = 0x1126,	//代金券支付充值交易请求请求
    EM_IPCMSG_TVMPASSENGER_TO_CORE_CHARGE_BY_OTHER = 0x1127,	//其他第三方支付充值交易请求请求	请求报文

    EM_IPCMSG_TVMPASSENGER_TO_CORE_QUERY_TICKET = 0x1131,			//查询交易请求	请求报文
    EM_IPCMSG_TVMPASSENGER_TO_CORE_CONFIRM_TRANS = 0x1141, 			//乘客确认交易	请求报文
    EM_IPCMSG_TVMPASSENGER_TO_CORE_CANCEL_TRANS = 0x1142, 			//乘客取消交易	请求报文
    EM_IPCMSG_TVMPASSENGER_TO_CORE_QUERY_PRICE = 0x1151,			//票价查询	请求报文
    EM_IPCMSG_TVMPASSENGER_TO_CORE_QUERY_STATIONS = 0x1152,			//站点查询	请求报文
    EM_IPCMSG_TVMPASSENGER_TO_CORE_QUERY_VERSION = 0x1153, 			//版本查询	请求报文
    EM_IPCMSG_TVMPASSENGER_TO_CORE_QUERY_PRICE_SET = 0x1154,		//票价集合查询	请求报文
    EM_IPCMSG_TVMPASSENGER_TO_CORE_HELP_REQUEST = 0x1161, 			//请求招援	请求报文
    EM_IPCMSG_TVMPASSENGER_TO_CORE_HUMAN_SENSOR_COME = 0x1162,		//人体传感器  感应到人
    EM_IPCMSG_TVMPASSENGER_TO_CORE_HUMAN_SENSOR_LEAVE = 0X1163,		//人体传感器  人离开

    EM_IPCMSG_TVMPASSENGER_TO_CORE_ENTER_MAINTANCE_REQUEST = 0X1164,		//当TVM TCM没有维修键盘时由界面触发此消息，进入维修
    EM_IPCMSG_TVMPASSENGER_TO_CORE_FLASH_CARD_CONTINUE = 0X1165,//闪卡回复

    EM_IPCMSG_TVMPASSENGER_TO_CORE_TVM_UI_ALL_STATUS_REQUEST = 0X1170,		//TVM全状态请求
    EM_IPCMSG_TVMPASSENGER_TO_CORE_AG_UI_ALL_STATUS_REQUEST = 0X1171,		//AG全状态请求
    //wangyzh20150617添加ipc消息
    EM_IPCMSG_TVMPASSENGER_TO_CORE_PRINT_REQUEST = 0x1173,	//TVM充值业务打印消息

    EM_IPCMSG_CORE_TO_TVMPASSENGER_MODE_NOTIFY = 0x1171,			//模式通知	通知报文
    EM_IPCMSG_CORE_TO_TVMPASSENGER_CARD_INSERT_NOTIFY = 0x1181, 	//票卡插入通知	通知报文
    EM_IPCMSG_CORE_TO_TVMPASSENGER_PAYMENT_NOTIFY = 0x1182, 		//支付信息通知	通知报文
    EM_IPCMSG_CORE_TO_TVMPASSENGER_SHOW_CONFIRM_NOTIFY = 0x1183,	//显示确认按钮通知	通知报文
    EM_IPCMSG_CORE_TO_TVMPASSENGER_TICKET_HANDLING_NOTIFY = 0x1184,//票卡处理通知	通知报文
    EM_IPCMSG_CORE_TO_TVMPASSENGER_TRANS_RESULT_NOTIFY = 0x1185, 		//交易结果通知	通知报文
    EM_IPCMSG_CORE_TO_TVMPASSENGER_TRANS_END_NOTIFY = 0x1186, 		//交易结束通知	通知报文
    EM_IPCMSG_CORE_TO_TVMPASSENGER_HELP_NOTIFY = 0x1187, 			//招援通知	通知报文
    EM_IPCMSG_CORE_TO_TVMPASSENGER_TRANS_START_NOTIFY = 0x1188, 	//交易开始通知	通知报文
    EM_IPCMSG_CORE_TO_TVMPASSENGER_INIT_NOTIFY = 0x1189, 			//初始化进度通知
    EM_IPCMSG_CORE_TO_TVMPASSENGER_FLASH_CARD_NOTIFY = 0x1190, 			//闪卡	通知报文
    EM_IPCMSG_CORE_TO_TVMPASSENGER_PASSENGER_COME = 0x1191, 			//人来	通知报文
    EM_IPCMSG_CORE_TO_TVMPASSENGER_PASSENGER_GO = 0x1192, 			//人走	通知报文
    EM_IPCMSG_CORE_TO_TVMPASSENGER_SYSTEM_DATA_NOTIFY = 0x1193,      //数据通知


    EM_IPCMSG_AGPASSENGER_TO_CORE_QUERY_VERSION = 0x1201, 			//版本查询	请求报文
    EM_IPCMSG_CORE_TO_AGPASSENGER_WORK_MODE_NOTIFY = 0x1210,// 模式通知
    EM_IPCMSG_CORE_TO_AGPASSENGER_CHECK_SUCCESS_NOTIFY = 0x1211, //检票成功通知
    EM_IPCMSG_CORE_TO_AGPASSENGER_CHECK_FAIL_NOTIFY = 0x1212, //检票失败通知
    EM_IPCMSG_CORE_TO_AGPASSENGER_CHANNEL_STATE_NOTIFY = 0x1213,//通道状态通知
    EM_IPCMSG_CORE_TO_AGPASSENGER_INIT_NOTIFY = 0x1289, 			//初始化进度通知

//    EM_IPCMSG_CORE_TO_AGPASSENGER_VERSION_SEARCH_NOTIFY = 0x1214, //版本信息通知
    EM_IPCMSG_CORE_TO_AGPASSENGER_SWITCH_MODE_NOTIFY = 0x1215,  //闸机验票模式，检票模式切换通知
    EM_IPCMSG_CORE_TO_AGPASSENGER_ENTRY_PAUSE_NOTIFY = 0x1216, //进站暂停
    EM_IPCMSG_CORE_TO_AGPASSENGER_WAIT_POLL_NOTIFY = 0x1217, //等待刷卡
    EM_IPCMSG_CORE_TO_AGPASSENGER_PAUSE_POLL_NOTIFY = 0x1218, //暂停寻卡
    EM_IPCMSG_CORE_TO_AGPASSENGER_POLL_CARD_NOTIFY = 0x1219, //寻到卡
    EM_IPCMSG_CORE_TO_AGPASSENGER_WD_TICKET_SUCCESS_NOTIFY = 0x0120, 		//AG 票卡回收成功通知

    //维修给主控发送的消息
	EM_IPCMSG_MAINTENCE_TO_CORE_LOGIN							= 0x2001,	//登录请求
	EM_IPCMSG_MAINTENCE_TO_CORE_LOGOUT							= 0x2002,	//登出请求
	EM_IPCMSG_MAINTENCE_TO_CORE_COMMAND							= 0x2003,	//控制命令请求
	EM_IPCMSG_MAINTENCE_TO_CORE_TIME_SYNC                       = 0x2004,	//时钟同步请求
	EM_IPCMSG_MAINTENCE_TO_CORE_EDITION_INFO					= 0x2005,	//版本信息请求
	EM_IPCMSG_MAINTENCE_TO_CORE_CASH_CONTAINER_CHANGE_BEGIN		= 0x2006,	//钱箱更换开始请求
	EM_IPCMSG_MAINTENCE_TO_CORE_CASH_CONTAINER_CHANGE_END		= 0x2007,	//钱箱更换完成请求
	EM_IPCMSG_MAINTENCE_TO_CORE_CASH_CONTAINER_UNLOCK			= 0x2008,	//钱箱操作请求
	EM_IPCMSG_MAINTENCE_TO_CORE_CASH_CONTAINER_FLUSH			= 0x2009,	//钱箱清空请求
	EM_IPCMSG_MAINTENCE_TO_CORE_ADD_CHANGE_ONE_BY_ONE			= 0x200A,	//逐张补充找零请求
	EM_IPCMSG_MAINTENCE_TO_CORE_TIC_CONTAINER_CHANGE_BEGIN		= 0x200B,	//票箱更换开始请求
	EM_IPCMSG_MAINTENCE_TO_CORE_TIC_CONTAINER_CHANGE_END		= 0x200C,	//票箱更换完成请求
	EM_IPCMSG_MAINTENCE_TO_CORE_TIC_CONTAINER_UNLOCK			= 0x200D,	//票箱操作请求
	EM_IPCMSG_MAINTENCE_TO_CORE_TIC_CONTAINER_FLUSH				= 0x200E,	//票箱清空请求
	EM_IPCMSG_MAINTENCE_TO_CORE_SETTLEMENT							= 0x200F,	//结算请求
	EM_IPCMSG_MAINTENCE_TO_CORE_CLEAR_ERROR						= 0x2010,	//一键错误重置请求
	EM_IPCMSG_MAINTENCE_TO_CORE_BREAK_SECRITY					= 0x2011,	//入侵通知
	EM_IPCMSG_MAINTENCE_TO_CORE_FIRMWARE_TEST_SET_MODE			= 0x2012,	//测试模式设置
	EM_IPCMSG_MAINTENCE_TO_CORE_FIRMWARE_TEST					= 0x2013,	//测试请求
	EM_IPCMSG_MAINTENCE_TO_CORE_ALL_STATUS_REQUEST				= 0x2014,	//状态请求
	EM_IPCMSG_MAINTENCE_TO_CORE_RUN_MODE_SETTING				= 0x2015,	//运营模式设置
	EM_IPCMSG_MAINTENCE_TO_CORE_RUN_CONTROL_CMD					= 0x2016,	//运营控制命令(iParam0:1:运营开始  2:运营结束)
	EM_IPCMSG_MAINTENCE_TO_CORE_VOUCHER_PRINT					= 0x2017,	//单据补打命令
	EM_IPCMSG_MAINTENCE_TO_CORE_RELOAD_PARAM                    = 0x2018,   //重新加载参数
	EM_IPCMSG_MAINTENCE_TO_CORE_FLUSH_FOR_BALANCE               = 0x2019,   //结帐所用清空钱票箱
	EM_IPCMSG_MAINTENCE_TO_CORE_EIXT_MAINTENCE_MODE              = 0x2020,   //退出维修模式
	EM_IPCMSG_MAINTENCE_TO_CORE_BALANCE							= 0x2021,	//结存请求
	EM_IPCMSG_MAINTENCE_TO_CORE_FIRMWARE_INIT_BIZ               = 0x2022,	//用于各类部件初始化请求(非测试应用请求)
	EM_IPCMSG_MAINTENCE_TO_CORE_BOX_UP_DOWN_BIZ   				= 0x2023,	//用于各类箱子上升下降请求(非测试应用请求)

	EM_IPCMSG_MAINTENCE_TO_CORE_CONTAINER_CHANGE_BEGIN          = 0x2024,	//容器更换请求(用于对接新版(维修QT版本)的钱票箱更换业务)longjg
	EM_IPCMSG_MAINTENCE_TO_CORE_CONTAINER_CHANGE_END          	= 0x2025,	//容器更换请求(用于对接新版(维修QT版本)的钱票箱更换业务)longjg
	EM_IPCMSG_MAINTENCE_TO_CORE_CONTAINER_SPECIAL_OPER			= 0x2026,	//容器更换的特殊操作请求(如, 解锁/升降/初始化, 用于对接新版(维修QT版本)的钱票箱更换业务)longjg

	EM_IPCMSG_MAINTENCE_TO_CORE_BALANCE_BEGIN 					= 0x2027,	//结算开始请求(用于对接新版(维修QT版本)的结算业务)longjg
	EM_IPCMSG_MAINTENCE_TO_CORE_BALANCE_END 					= 0x2028,	//结算结束请求(用于对接新版(维修QT版本)的结算业务)longjg

	EM_IPCMSG_MAINTENCE_TO_COMM_TPU_PARAM_IMPORT_NOTIFY_BY_UDISK	= 0x2200,	//U盘tpu参数导入通知
	EM_IPCMSG_MAINTENCE_TO_COMM_LOGIN_NOTIFY						= 0x2201,	//维修登录通知
	EM_IPCMSG_MAINTENCE_TO_COMM_LOGOUT_NOTIFY						= 0x2202,	//维修登出通知

	EM_IPCMSG_CORE_TO_MAINTENCE_CASH_CONTAINER_FLUSH_NOTIFY			= 0x2101,	//钱箱清空过程通知
	EM_IPCMSG_CORE_TO_MAINTENCE_TIC_CONTAINER_FLUSH_NOTIFY			= 0x2102,	//票箱清空过程通知
	EM_IPCMSG_CORE_TO_MAINTENCE_ADD_CHANGE_ONE_BY_ONE_NOTIFY		= 0x2103,	//逐张补充找零过程通知
	EM_IPCMSG_CORE_TO_MAINTENCE_TIC_CONTAINER_CHANGE_BEGIN_RESULT	= 0x2104,	//票箱更换开始结果通知
	EM_IPCMSG_CORE_TO_MAINTENCE_TIC_CONTAINER_CHANGE_END_RESULT		= 0x2105,	//票箱更换完成结果通知
	EM_IPCMSG_CORE_TO_MAINTENCE_TIC_CONTAINER_CHANGE_INFO_NOTIFY	= 0x2106,	//票箱更换过程状态变化通知
	EM_IPCMSG_CORE_TO_MAINTENCE_CASH_CONTAINER_CHANGE_BEGIN_RESULT	= 0x2107,	//钱箱更换开始结果通知
	EM_IPCMSG_CORE_TO_MAINTENCE_CASH_CONTAINER_CHANGE_END_RESULT	= 0x2108,	//钱箱更换完成结果通知
	EM_IPCMSG_CORE_TO_MAINTENCE_CASH_CONTAINER_CHANGE_INFO_NOTIFY	= 0x2109,	//钱箱更换过程状态变化通知
	EM_IPCMSG_CORE_TO_MAINTENCE_DEVICE_STATUS_NOTIFY				= 0x210A,	//设备状态通知
	EM_IPCMSG_CORE_TO_MAINTENCE_FIRMWARE_TEST_PROCESS_NOTIFY		= 0x210B,	//连续测试过程通知
	EM_IPCMSG_CORE_TO_MAINTENCE_ASYN_CMD_FINISH_NOTIFY				= 0x210C,	//异步消息完成通知
	EM_IPCMSG_CORE_TO_MAINTENCE_EXIT_NOTIFY							= 0x210D,	//进程退出通知
	EM_IPCMSG_CORE_TO_MAINTENCE_SHOW_HIDE_NOTIFY					= 0x210E,	//界面显示/隐藏通知
	EM_IPCMSG_CORE_TO_MAINTENCE_CONTAINER_STATUS_NOTIFY				= 0x210F,	//容器状态变更通知

	EM_IPCMSG_COMM_CORE_CONNECT_STATUS	    			= 0x3101,		//	连接状态报告
	EM_IPCMSG_COMM_CORE_SYNCTIME_NOTIFY	        		= 0x3102,		//	时钟同步通知
	EM_IPCMSG_COMM_CORE_PARAM_DOWNLOAD	    			= 0x3103,		//	参数/软件下载完成报告
	EM_IPCMSG_COMM_CORE_DEVICE_STATUS_REQUEST	 		= 0x3104,		//	查询设备状态请求
	EM_IPCMSG_COMM_CORE_RUN_BEGIN_END		 			= 0x3105,		//	运营开始结束完成报告
	EM_IPCMSG_COMM_CORE_CONTROL_CMD_NOTIFY	 			= 0x3106,		//	设备控制命令通知
	EM_IPCMSG_COMM_CORE_RUN_MODE_NOTIFY 				= 0x3107,		//	本站运营模式控制命令通知
	EM_IPCMSG_COMM_CORE_HOURS_24_SETUP_NOTIFY 			= 0x3108,		//	24小时运营控制命令通知
	EM_IPCMSG_COMM_CORE_DELAY_TIME_SETUP_NOTIFY 		= 0x3109,		//	延长运营时间命令通知
	EM_IPCMSG_COMM_CORE_QUERY_VERSION 					= 0x3110, 		//版本查询	请求报文
	EM_IPCMSG_COMM_CORE_EXTERN_MODE_NOTIFY 				= 0x3111, 		//外站模式控通知
	EM_IPCMSG_COMM_CORE_RUN_CONTROL_CMD 				= 0x3112, 		//运营控制命令(iParam0:1:运营开始  2:运营结束  3:运营日切换)
	EM_IPCMSG_COMM_CORE_FLUSH_CONTROL_CMD 				= 0x3113, 		//清空控制命令
	EM_IPCMSG_COMM_CORE_GET_REGISTER_DATA 				= 0x3114, 		//获取寄存器数据
	EM_IPCMSG_COMM_CORE_COMMON_CMD                      = 0x3120,       //通用控制命令
	//	EM_IPCMSG_COMM_CORE_CERTIFICATION_DONE  = 0x3105,		//	逻辑连接时序结果报告
	//	EM_IPCMSG_COMM_CORE_SALE_TICKET_LIMIT_NOTIFY = 0x3112,		//	售票限制命令通知


	EM_IPCMSG_CORE_COMM_RUN_END_NOTIFY 					= 0x3151,		//	运营结束通知
	EM_IPCMSG_CORE_COMM_LOGON_NOTIFY 					= 0x3152,		//	登录登出请求
	EM_IPCMSG_CORE_COMM_SWITCH_RUN_DATE 				= 0x3153,		//	切换运营日通知
	EM_IPCMSG_CORE_ASSISTANCE_REQUEST 					= 0x3154,		//	设备招援请求
	EM_IPCMSG_CORE_COMM_SOFTWARE_EXIT 					= 0x3155,		//	软件退出通知
	EM_IPCMSG_CORE_COMM_DEVICE_STATUS_NOTIFY 			= 0x3156,		//	设备状态通知
	EM_IPCMSG_CORE_COMM_BALANCE_FINISH_NOTIFY           = 0x3157,       //  结算完成通知
	//	EM_IPCMSG_CORE_COMM_RUN_MODE_CHANGE_NOTIFY = 0x3152,		//	运营模式改变通知
	//	EM_IPCMSG_CORE_COMM_PARAM_UPDATE_NOTIFY = 0x3153,		//	参数更新完成通知

	EM_IPCMSG_OPERUI_TO_MAINTENCE_LEAVE_MAINTENCE           = 0x4000,       // 退出维修模式
	EM_IPCMSG_OPERUI_TO_MAINTENCE_LOGIN                     = 0x4001,       // 登录


//运营服务 0x4020 - 0x4039
	EM_IPCMSG_OPERUI_TO_MAINTENCE_RUN_SERVICE_RUN_START     = 0x4020,       // 运营开始
	EM_IPCMSG_OPERUI_TO_MAINTENCE_RUN_SERVICE_RUN_END       = 0x4021,       // 运营结束

//查询 0x4040 - 0x4059

	EM_IPCMSG_OPERUI_TO_MAINTENCE_DATA_QUERY_SYSTEM         = 0x4040,       // 系统状态
	EM_IPCMSG_OPERUI_TO_MAINTENCE_DATA_QUERY_SAM            = 0x4041,       // SAM卡查询

//系统设置 0x4060 - 0x4079

	EM_IPCMSG_OPERUI_TO_MAINTENCE_SYS_GET_DATE_ENQ          = 0x4060,       // 日期设置
	EM_IPCMSG_OPERUI_TO_MAINTENCE_SYS_SET_DATE              = 0x4061,       // 日期设置


	EM_IPCMSG_OPERUI_TO_MAINTENCE_SYS_GET_IP_ENQ            = 0x4062,       // IP设置
	EM_IPCMSG_OPERUI_TO_MAINTENCE_SYS_SET_IP                = 0x4063,       // IP设置

	EM_IPCMSG_OPERUI_TO_MAINTENCE_SYS_GET_SC_IP_ENQ         = 0x4064,       // SC IP
	EM_IPCMSG_OPERUI_TO_MAINTENCE_SYS_SET_SC_IP             = 0x4065,       // SC IP

	EM_IPCMSG_OPERUI_TO_MAINTENCE_SYS_GET_SC_PORT_ENQ       = 0x4066,       // SC端口
	EM_IPCMSG_OPERUI_TO_MAINTENCE_SYS_SET_SC_PORT           = 0x4067,       // SC端口

	EM_IPCMSG_OPERUI_TO_MAINTENCE_SYS_GET_LINE_NO_ENQ       = 0x4068,       // 线路编码
	EM_IPCMSG_OPERUI_TO_MAINTENCE_SYS_SET_LINE_NO           = 0x4069,       // 线路编码

	EM_IPCMSG_OPERUI_TO_MAINTENCE_SYS_GET_DEVICE_NO_ENQ     = 0x406A,       //设备编号
	EM_IPCMSG_OPERUI_TO_MAINTENCE_SYS_SET_DEVICE_NO         = 0x406B,       //设备编号



//部件测试 0x4080 - 0x4099
    //TPU
    EM_IPCMSG_OPERUI_TO_MAINTENCE_REPAIR_RECHARGE_READER_INIT  = 0x4080,       // 充值读卡器 初始化
    EM_IPCMSG_OPERUI_TO_MAINTENCE_REPAIR_RECHARGE_READER_READ  = 0x4081,       // 充值读卡器 寻卡
    EM_IPCMSG_OPERUI_TO_MAINTENCE_REPAIR_RECHARGE_READER_QUERY_VERSION  = 0x4082,       // 充值读卡器 版本查询
    EM_IPCMSG_OPERUI_TO_MAINTENCE_REPAIR_RECHARGE_READER_PARAM_COMPARE  = 0x4083,       // 充值读卡器 比较
    EM_IPCMSG_OPERUI_TO_MAINTENCE_REPAIR_RECHARGE_READER_PARAM_UPDATE  = 0x4084,       // 充值读卡器 升级
    EM_IPCMSG_OPERUI_TO_MAINTENCE_REPAIR_RECHARGE_READER_PARAM_ONEKEY_UPDATE = 0x4085,
    //纸币接收
    EM_IPCMSG_OPERUI_TO_MAINTENCE_ONINNERMSG = 0x4090,  //维修见面发给oper进程的相关ipc消息号
    EM_IPCMSG_OPERUI_TO_MAINTENCE_ONINNERMSG_RESULT = 0x4390,//回复的结构
//    EM_IPCMSG_OPERUI_TO_MAINTENCE_REPAIR_ACCEPTER_INIT  = 0x4090,       // 纸币接收单元 初始化
//    EM_IPCMSG_OPERUI_TO_MAINTENCE_REPAIR_ACCEPTER_RESET  = 0x4091,       //纸币接收单元 错误重置
//    EM_IPCMSG_OPERUI_TO_MAINTENCE_REPAIR_ACCEPTER_STATE  = 0x4092,       //纸币接收单元 状态请求
//    EM_IPCMSG_OPERUI_TO_MAINTENCE_REPAIR_ACCEPTER_QUERY_VERSION  = 0x4093,       // 版本查询
//    EM_IPCMSG_OPERUI_TO_MAINTENCE_REPAIR_ACCEPTER_ACCEPT  = 0x4094,       // 开启识别
//    EM_IPCMSG_OPERUI_TO_MAINTENCE_REPAIR_ACCEPTER_FORBID  = 0x4095,       // 关闭识别
//    EM_IPCMSG_OPERUI_TO_MAINTENCE_REPAIR_ACCEPTER_ENCASH  = 0x4096,       // 纸币压入
//    EM_IPCMSG_OPERUI_TO_MAINTENCE_REPAIR_ACCEPTER_REFUND = 0x4097, //纸币退还


    EM_IPCMSG_OPERUI_TO_MAINTENCE_CONTAINER_CHANGE_BEGIN = 0x4098,			//容器更换请求(用于对接新版(维修QT版本)的钱票箱更换业务)longjg
	EM_IPCMSG_OPERUI_TO_MAINTENCE_CONTAINER_CHANGE_END = 0x4099,			//容器更换请求(用于对接新版(维修QT版本)的钱票箱更换业务)longjg
	EM_IPCMSG_OPERUI_TO_MAINTENCE_CONTAINER_SPECIAL_OPER = 0x409A,			//容器更换的特殊操作请求(如, 解锁/升降/初始化, 用于对接新版(维修QT版本)的钱票箱更换业务)longjg

//故障处理 0x4100 - 0x4120

	EM_IPCMSG_OPERUI_TO_MAINTENCE_ERROR_CLEAR               = 0x4100,       // 一键错误重置

	EM_IPCMSG_OPERUI_TO_MAINTENCE_SYS_FUNC_RESTART          = 0x4120,       // 重启
	EM_IPCMSG_OPERUI_TO_MAINTENCE_SYS_FUNC_SHUTDOWN         = 0x4121,       // 系统关机

//服务控制
	EM_IPCMSG_OPERUI_TO_MAINTENCE_SERVICE_CONTROL_NORMAL_MODE         = 0x4140,       //服务控制 正常服务
	EM_IPCMSG_OPERUI_TO_MAINTENCE_SERVICE_CONTROL_OUT_SERVICE_MODE         = 0x4141,       //服务控制 暂停服务


	EM_IPCMSG_MAINTENCE_TO_OPERUI_REPAIR_RECHARGE_READER_READ_PROCESS  = 0x4200,       // 充值读卡器 寻卡过程
	EM_IPCMSG_MAINTENCE_TO_OPERUI_REPAIR_RECHARGE_READER_INIT_RESULT   = 0x4201,       //充值读卡器 初始化结果

	EM_IPCMSG_MAINTENCE_TO_OPERUI_DATA_QUERY_SYSTEM_STATUS             = 0x4202,       // 系统查询
	EM_IPCMSG_MAINTENCE_TO_OPERUI_LOGIN                                = 0x4203,


	EM_IPCMSG_MAINTENCE_TO_OPERUI_SYS_GET_IP            = 0x4204,       // IP
	EM_IPCMSG_MAINTENCE_TO_OPERUI_SYS_GET_SC_IP         = 0x4205,       // SC IP
	EM_IPCMSG_MAINTENCE_TO_OPERUI_SYS_GET_SC_PORT       = 0x4206,       // SC端口
	EM_IPCMSG_MAINTENCE_TO_OPERUI_SYS_GET_LINE_NO       = 0x4207,       // 线路编码
	EM_IPCMSG_MAINTENCE_TO_OPERUI_SYS_GET_DEVICE_NO     = 0x4208,       //设备编号


	EM_IPCMSG_MAINTENCE_TO_OPERUI_RUN_START_NOTIFY      = 0x4209,       //
	EM_IPCMSG_MAINTENCE_TO_OPERUI_RUN_END_NOTIFY      = 0x420A,       //
	EM_IPCMSG_MAINTENCE_TO_OPERUI_REPAIR_RECHARGE_READER_QUERY_VERSION_RESULT   = 0x420B,       //充值读卡器 初始化结果
	EM_IPCMSG_MAINTENCE_TO_OPERUI_REPAIR_RECHARGE_READER_PARAM_COMPARE_RESULT   = 0x420C,       //充值读卡器 初始化结果
	EM_IPCMSG_MAINTENCE_TO_OPERUI_REPAIR_RECHARGE_READER_PARAM_ONEKEY_UPDATE_RESULT   = 0x420D,       //充值读卡器 初始化结果

	EM_IPCMSG_MAINTENCE_TO_OPERUI_CONTAINER_STATUS_NOTIFY = 0x4300,	//容器状态变更通知

	//add by mabin 20170321
//    EM_IPCMSG_OPERUI_TO_MAINTENCE_REPAIR_RESULT_ACCEPTER_INIT  = 0x4390,       // 纸币接收单元 初始化
//    EM_IPCMSG_OPERUI_TO_MAINTENCE_REPAIR_RESULT_ACCEPTER_RESET  = 0x4391,       //纸币接收单元 错误重置
//    EM_IPCMSG_OPERUI_TO_MAINTENCE_REPAIR_RESULT_ACCEPTER_STATE  = 0x4392,       //纸币接收单元 状态请求
//    EM_IPCMSG_OPERUI_TO_MAINTENCE_REPAIR_RESULT_ACCEPTER_QUERY_VERSION  = 0x4393,       // 版本查询
//    EM_IPCMSG_OPERUI_TO_MAINTENCE_REPAIR_RESULT_ACCEPTER_ACCEPT  = 0x4394,       // 开启识别
//    EM_IPCMSG_OPERUI_TO_MAINTENCE_REPAIR_RESULT_ACCEPTER_FORBID  = 0x4395,       // 关闭识别
//    EM_IPCMSG_OPERUI_TO_MAINTENCE_REPAIR_RESULT_ACCEPTER_ENCASH  = 0x4396,       // 纸币压入
//    EM_IPCMSG_OPERUI_TO_MAINTENCE_REPAIR_RESULT_ACCEPTER_REFUND = 0x4397, //纸币退还

	//add end 20170321
	EM_IPCMSG_GENERAL_MESSAGE					      = 0x5001,       //IPC通用消息

}EM_IPCMSG_ID;

//界面显示或隐藏枚举
typedef enum
{
	EM_UI_HIDE = 1,    //界面隐藏
	EM_UI_SHOW = 2,    //界面显示
}EM_UI_SHOW_OR_HIDE;


typedef struct
{
    ST_TVM_WORK_MODE stWorkMode;
	ST_DENO_INFO stAllowBillDeno;
	ST_DENO_INFO stAllowCoinDeno;
}ST_TVM_MODE_NOTIFY;

typedef enum
{
	//交易类型：
	EM_TVM_TRANS_TYPE_SELECT = 0,	//0：选择阶段
	EM_TVM_TRANS_TYPE_VENDING = 1,	//1：售票
	EM_TVM_TRANS_TYPE_RECHARGE = 2,	//2：充值
	EM_TVM_TRANS_TYPE_QUERY = 3,	//3：查询
	EM_TVM_TRANS_TYPE_CHANGE = 4,   //4 找零
}EM_TVM_TRANS_TYPE;


typedef enum
{
	EM_TVM_VALIDITY_VALID_RECHARGE = 0,// 0：读卡成功并且可以充值
	EM_TVM_VALIDITY_VALID_NO_RECHARGE = 1,//1：读卡成功不可充值
	EM_TVM_VALIDITY_INVALID = 2,//2：读卡失败
}EM_TVM_VALIDITY;

//typedef struct
//{
//	//允许支付方式：1有效
//	int iDefault:1;//Bit 0：默认
//	int iCash:1;//Bit 1：现金
//	int iBankCard:1;//Bit 2：银行卡
//	int iSaveCard:1;//Bit 3：储值卡
//	int iReserved:28;//Bit4 ~31：预留
//}ST_TVM_PAY_METHOD;

//
//
//typedef struct
//{
//    int deno1:1;		//面值1元
//    int deno2:1;		//面值2元
//    int deno5:1;
//    int :1;
//
//    int deno10:1;
//    int deno20:1;
//    int deno50:1;
//    int :1;
//
//    int deno100:1;
//    int deno200:1;
//    int deno500:1;
//    int :1;
//
//    int deno1000:1;
//    int deno2000:1;
//    int deno5000:1;
//    int :1;
//
//    int deno10000:1;
//    int deno20000:1;
//    int deno50000:1;
//    int :1;
//
//    int deno100000:1;
//    int deno200000:1;
//    int deno500000:1;
//    int :1;
//
//    int :8;			//预留
//}ST_TVM_DENOMINATION;

//
////交易结果
//typedef enum
//{
//	EM_TVM_TRANS_RESULT_TICKET_SUCCESS = 1,//售票成功
//	EM_TVM_TRANS_RESULT_TICKET_FAILUE_RETURN_CHANGE_SUCCESS= 2,//售票失败、退款/找零成功
//	EM_TVM_TRANS_RESULT_TICKET_FAILUE_FAULTTRAN = 3,//售票失败，故障交易
//	EM_TVM_TRANS_RESULT_TICKET_FAIUE_JAM_FAULTTRAN = 4,//售票失败，卡币，故障交易
//	EM_TVM_TRANS_RESULT_TICKET_CANCEL_NOT_PUT_COIN_ = 5,//售票取消，未投币
//	EM_TVM_TRANS_RESULT_TICKET_CONCEL_REFUND_SUCCESS = 6,//售票取消，退款成功
//	EM_TVM_TRANS_RESULT_TICKET_CONCEL_REFUND_JAM_FAULTTRAN = 7,//售票取消，退款卡币，故障交易
//	EM_TVM_TRANS_RESULT_RECHARG_SUCCESS = 101,//充值成功
//	EM_TVM_TRANS_RESULT_RECHARG_FAILUE_REFUND_SUCCESS = 102,//充值失败，退款成功
//	EM_TVM_TRANS_RESULT_RECHARG_FAILUE_FAULTTRAN = 103,//充值失败，故障交易
//	EM_TVM_TRANS_RESULT_RECHARG_FAILUE_JAM_FAULTTRAN = 104,//充值失败，卡币，故障交易
//	EM_TVM_TRANS_RESULT_RECHARG_CANCEL_NOT_PUT_COIN = 105,//充值取消，未投币
//	EM_TVM_TRANS_RESULT_RECHARG_CANCEL_REFUND_JAM_SUCCESS = 106,//充值取消，退款成功
//	EM_TVM_TRANS_RESULT_RECHARG_CANCEL_REFUND_JAM_FAULTTRAN = 107,//充值取消，退款卡币，故障交易
//	EM_TVM_TRANS_RESULT_RECHARG_INVALIDITY_CARD = 108,//充值插入数据无效卡
//	EM_TVM_TRANS_RESULT_RECHARG_INVALIDITY_TYPE_CARD = 109,//充值插入不允许充值类型卡
//	EM_TVM_TRANS_RESULT_RECHARG_BLACK_LIST_CARD = 110,//充值插入黑名单卡
//	EM_TVM_TRANS_RESULT_QUERY_OVER = 201,//查询结束
//	EM_TVM_TRANS_RESULT_QUERY_INVALIDITY_CARD = 202,//查询插入数据无效卡
//	EM_TVM_TRANS_RESULT_QUERY_BLACK_LIST_CARD = 203,//查询插入黑名单卡
//} EM_TVM_TRANS_RESULT;


typedef struct
{
	EM_SLE_TRANSACATION_TYPE emTransType:8;
	EM_TRANSACATION_RESULT emTransResult:8;
	int iDstTikectNum:8;
	int iActualTicketNum:8;
}ST_TVM_TRANS_INFO;


typedef struct
{
	int iNone:8;//Byte0：争议票	  0：不存在争议票	  1：存在争议票，发售成功后出票失败
	int iVendingFail:8;//Byte1：争议找零	  0：不存在争议找零  1：存在争议找零，找零出钞口卡币
	int iPrintFlag:8;//Byte2：是否显示打印按钮	  0:不显示打印按钮	  1:显示打印按钮
	int iReserve:8;//预留
}ST_TVM_QUARREL;


//动作：
typedef enum
{
	EM_TVM_OPERATE_BEGIN = 1,//1：开始操作
	EM_TVM_OPERATE_END = 2,//2：结束操作
}EM_TVM_OPERATE;


typedef struct
{
	DWORD dwMsgID;          	//消息ID
	DWORD dwDesStationID;		//目的车站ID	//0表示无效, 参数1无效时参数2必须有效
	DWORD dwTicketPrice;		//单价金额,	//0表示无效。参数2无效时参数1必须有效
	DWORD dwTicketCount;		//购票数量，不能小于1
	DWORD uiTicketType;			//车票类型，必须赋值
	WORD usTicketSubType;		//Byte 0-1: 车票子类型，默认值：0
	BYTE ucLevel;				//Byte 2:舱位等级，默认值：0
	BYTE ucPassengerType;		//Byte 3:乘客类型
	BYTE ucLanguage;			//Byte 0:语言种类，默认值：0
	BYTE ucCardType;			//Byte 1:卡片类型
	WORD reserve1;				//预留			//rename by limg at 20170406 for NetPay:
	EM_SLE_TRANSACATION_TYPE emSleTransType; 	//交易类型：由界面赋值，用于触发交易时 add by limg at 20170406 for NetPay:
	EM_PAYMENT_METHOD emPaymentMethod;     	    //支付类型   add by limg at 20170406 for NetPay:
	EM_PAYMENT_SUB_METHOD emPaymentSubMethod;   //支付子类型，如：微信或支付宝 add by limg at 20170406 for NetPay:
	WORD reserve2;								//预留 	add by limg at 20170406 for NetPay:
}ST_TVM_VENDING_REQUEST_INFO;




//add by limg at 20160623: 兼容 TJEQM 任意车站间票价查询的功能
typedef struct
{
	DWORD dwMsgID;          	//消息ID
	DWORD dwOriginStationID;	//起始车站ID	//0表示无效, 参数1无效时参数2必须有效 a
	DWORD dwDesStationID;		//目的车站ID	//0表示无效, 参数1无效时参数2必须有效
	DWORD uiTicketType;			//车票类型，必须赋值
	WORD usTicketSubType;		//Byte 0-1: 车票子类型，默认值：0
	BYTE ucLevel;				//Byte 2:舱位等级，默认值：0
	BYTE ucPassengerType;		//Byte 3:乘客类型
	DWORD reserve1;				//预留
	DWORD reserve2;				//预留
}ST_TICKET_PRICE_REQUEST_INFO;


typedef struct
{
	DWORD dwMsgID;          //消息ID
	DWORD dwRechargeAmount;	//乘客选择充值金额，0表示乘客没有选择
	DWORD dwTicketType;		//车票类型，0表示车票类型不由乘客选择
	int iPrintFlag;			//0:不打印 1:打印
	int reserve1;	//预留
	int reserve2;	//预留
	int reserve3;	//预留
}ST_TVM_RECHARGE_REQUEST_INFO;

typedef struct
{
	DWORD dwTotalPrice;	//交易总价金额
	DWORD dwTicketCount;	//交易数量
	DWORD dwPaymentAmount;	//支付总金额
	DWORD bAllowBill:1;		//  Bit 0：允许纸币，1有效
	DWORD bAllowCoin:1;	//  Bit 1：允许硬币，1有效
	DWORD bAllowSvt:1;	//  Bit 2：允许储值卡，1有效
	DWORD bAllowBankCard:1;	//  Bit 3：允许银行卡，1有效
	DWORD bAllowNfc:1;	//  Bit 4：允许NFC，1有效
	DWORD bAllowWeb:1;	//  Bit 5：允许网络预付，1有效
	DWORD bAllowVoucher:1;	//  Bit 6：允许代金券，1有效
	DWORD bAllowOther:1;	//  Bit 7：允许其他第三方，1有效
	DWORD bAllowQRCode:1;	//  Bit 8：允许二维码，1有效 add by limg at 20170406 for NetPay:
	DWORD reserve1:23;	//Bit9 ~31：预留               edit by limg at 20170406 for NetPay: 24 -->23

	DWORD bCashRejected : 1; // Bit 0: 0表示现金已接收；1 表示现金被拒收
	DWORD reserve2 : 31;	//预留
	DWORD reserve3;		//预留

}ST_TVM_PAYMENT_NOTIFY_INFO;

typedef struct
{
    EM_SLE_TRANSACATION_TYPE emType; //交易类型
	DWORD iTransSumPrice; //交易总金额
	DWORD iPaySumPrice; //支付总金额
	int iPrintFlag;//0:不打印 1:打印

}ST_TVM_CONFIRM_REQUEST_INFO;


typedef struct
{
    EM_SLE_TRANSACATION_TYPE emType; //交易类型
	DWORD iTransSumPrice; //交易总金额
	DWORD iPaySumPrice; //支付总金额

}ST_TVM_CANCEL_REQUEST_INFO;

typedef struct
{
	WORD wDataType; //数据类型
	WORD wStationAmount; //匹配的车站数量
	DWORD dwStationLen; //车站长度
	BYTE bStationList[MAX_ADDITIONAL_DATE_LENGTH]; //车站列表

}ST_TVM_STATION_REQUEST_INFO;


//typedef struct
//{
//	WORD wDataType; //数据类型
//	WORD wVersionAmount; //版本记录数量
//	DWORD dwVersionLen; //版本信息记录长度
//	BYTE bStationList[60]; //主体名称：STR，10byte 版本信息长度：STR，50byte
//
//}ST_TVM_VERSION_REQUEST_INFO;




typedef struct
{
    EM_SLE_TRANSACATION_TYPE emType;   //交易类型
	DWORD dwTicketNum; //处理票数量
	DWORD dwChange; //找零金额
	EM_TRANS_ACTION_TYPE emAction; //票卡处理动作
	DWORD dwProcessedCardNum; //已处理票数量
	DWORD dwChangedNum; //已找零金额

}ST_TVM_PROCESS_NOTIFY_INFO;

typedef struct
{
    ST_TVM_TRANS_INFO  stTvmTransInfo;   	//交易信息
    int iTicketSumPrice; 					//票价总金额
    int iPaySumPrice; 						//支付总金额
    int iTotalChangePrice; 					//应找零金额
    int iActualChangedPrice; 				//实际找零金额
    ST_TVM_QUARREL stQuarrel; 				//争议
    ST_TPU_READ_CARD_INFO stTpuReadCardInfo;

}ST_TVM_TRANS_OVER_NOTIFY_INFO;

/*添加充值卡信息通知界面结构体*/
typedef struct
{
    ST_TVM_TRANS_INFO  stTvmTransInfo;   	//交易信息
    int iTicketSumPrice; 					//票价总金额
    int iPaySumPrice; 						//支付总金额
    int iTotalChangePrice; 					//应找零金额
    int iActualChangedPrice; 				//实际找零金额
    ST_TVM_QUARREL stQuarrel; 				//争议

}ST_TVM_RECHARGE_SVT_CARD_INFO;

typedef enum
{
	EM_TVM_RECHARGE_FLASH_CARD = 0,// 0闪卡
	EM_TVM_RECHARGE_FLASH_OTHER_CARD = 1,//1：非同一张卡
}EM_TVM_RECHARGE_FLASH;

#endif /* IPCPUBLIC_H_ */
