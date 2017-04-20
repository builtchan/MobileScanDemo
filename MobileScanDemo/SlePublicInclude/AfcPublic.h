/*
 * AfcPublic.h
 *
 *  Created on: Jun 25, 2014
 *      Author: root
 */

#ifndef AFCPUBLIC_H_
#define AFCPUBLIC_H_

#define UD_DATA_MAX_SIZE    2048 //edit by limg at 20160622: 512 --> 2048, 南宁的交易数据长度为 600多
#define AR_DATA_MAX_SIZE    512
#define         CHAR_TWO_LENGTH                         2
#define         CHAR_THREE_LENGTH                       3
#define         CHAR_FOUR_LENGTH                        4
#define         CHAR_SIX_LENGTH                         6
#define         CHAR_SEVEN_LENGTH                       7
#define         CHAR_EIGHT_LENGTH                       8
#define         CHAR_TEN_LENGTH                         10
#define         CHAR_FOURTEEN_LENGTH            14
#define         CHAR_LENGTH_255                         255
#define         CHAR_ONE_K_BYTE                        1024
#define         CHAR_TWO_K_BYTE                        2048

#define PACKED __attribute__( ( packed, aligned(1) ) )

#define MAKEWORD(a, b)      ((WORD)(((BYTE)((DWORD)(a) & 0xff)) | ((WORD)((BYTE)((DWORD)(b) & 0xff))) << 8))
#define MAKELONG(a, b)      ((DWORD)(((WORD)((DWORD)(a) & 0xffff)) | ((DWORD)((WORD)((DWORD)(b) & 0xffff))) << 16))
#define LOWORD(l)           ((WORD)((DWORD)(l) & 0xffff))
#define HIWORD(l)           ((WORD)((DWORD)(l) >> 16))
#define LOBYTE(w)           ((BYTE)((DWORD)(w) & 0xff))
#define HIBYTE(w)           ((BYTE)((DWORD)(w) >> 8))


#define	COMMOM_FUNC_OK         1    //执行成功
#define	COMMOM_FUNC_FAIL       0    //执行失败
#define	COMMOM_FUNC_CMDERR   (-1)   //指令错误，没有被执行
#define	COMMOM_FUNC_UNSUPP   (-2)   //模块不支持此项功能

#define FUNC_OK 		0
#define FUNC_NOT_OK		-1000
#define FUNC_FAILED		0x80000000   /*执行失败*/


#define PROGREESS_REPORT_TYPE_DOWNLOAD		1
#define PROGREESS_REPORT_TYPE_INIT			2
#define PROGREESS_REPORT_TYPE_PARAM			3


#include "AfcErrorCode.h"
#include "AfcStatusTable.h"
#include "string.h"
//定义LOKI配置文件--wangzp at 11th, Aug,2014
#define SLE_LOKI_FILE "/Afc/Config/Loki_Sle_Cfg.xml"
//定义SleCore的配置文件--wangyzh at 4th, Sep,2014
#define SLE_CORE "/Afc/Config/Sle_Core.xml"
//定义LedCfg的配置文件--wangyzh at 2014.12.03
#define SLE_LED_CFG "/Afc/Config/SleLedCfg.xml"
//定义SleSpec.xml的配置文件--wangyzh at 2015.02.02
#define SLE_SPEC_CFG "/Afc/Config/SleSpec.xml"
//定义LineStation.xml的配置文件--wangyzh at 2015.04.17
#define SLE_LINE_STATION "/Afc/Config/LineStation.xml"
//定义ComXml.xml的配置文件--wangyzh at 2015.05.06
#define COM_XML "/Afc/Config/ComXml.xml"
//定义打印模板的配置文件--shaopf at 2015.05.13
#define TEMPLATE_FILE_PATH "/Afc/Config/PrinterTemplate.xml"
//定义版本维修配置文件
#define MAINTAIN_CFG "/Afc/Config/OperatorCfg.xml"

//票价列表文件, 开机启动时根据从读卡器获取到的票价列表, 动态生成
#define SLE_TICKET_PRICE_LIST "/Afc/Config/ProductPriceConfig.xml"

class CLogOper2;
extern CLogOper2 g_LogMainBiz; 		  //主体业务处理日志对象
extern CLogOper2 g_LogDeviceTpuUnit1; //硬件适配层读卡器日志对象
extern CLogOper2 g_LogDeviceTpuUnit2; //硬件适配层读卡器日志对象
extern CLogOper2 g_LogDeviceTpuUnit3; //硬件适配层读卡器日志对象

extern CLogOper2 g_LogDeviceBillDispenser; //硬件适配层纸币找零日志对象
extern CLogOper2 g_LogDeviceBillIdentify;  //硬件适配层纸币识别日志对象
extern CLogOper2 g_LogDeviceCoinDispenser; //硬件适配层硬币找零日志对象
extern CLogOper2 g_LogDeviceCoinIdentify;  //硬件适配层硬币识别日志对象
extern CLogOper2 g_LogDeviceValueCard;     //充值卡支付
extern CLogOper2 g_LogDeviceBankCard;      //银行卡支付
extern CLogOper2 g_LogDeviceWebCard;       //网络支付
extern CLogOper2 g_LogDeviceNfcCard;       //NFC支付
extern CLogOper2 g_LogDeviceVoucherCard;   //代金券支付
extern CLogOper2 g_LogDeviceOther;         //其他支付方式
extern CLogOper2 g_LogDeviceTicketIssue;   //车票发行
extern CLogOper2 g_LogDeviceSleDio;   	   			   //Dio模块
extern CLogOper2 g_LogDeviceSleUps;   	   			   //Ups模块
extern CLogOper2 g_LogDeviceTvmPrintOperator;   	   //维修打印机
extern CLogOper2 g_LogDeviceTvmPrintPassenger;   	   //乘客打印机
extern CLogOper2 g_LogDeviceTvmLedDouble;   	       //LED显示屏
extern CLogOper2 g_LogDeviceTvmOperboard;   	       //Tvm维修面板
extern CLogOper2 g_LogDeviceAgGate;   	               //AG阻挡装置模块
extern CLogOper2 g_LogDeviceAgDio;   	               //AG DIO模块
extern CLogOper2 g_LogDeviceAgTicketWithDraw;   	   //AG 车票回收模块
extern CLogOper2 g_LogDeviceRfidReader1;   	   	   //设备单独的RFID，1#
extern CLogOper2 g_LogDeviceRfidReader2;   	   	   //设备单独的RFID，2#
extern CLogOper2 g_LogDeviceRfidReader3;   	   	   //设备单独的RFID，3#

extern CLogOper2 g_LogDeviceMobilePay;				//手机支付

/* 运营服务管理类型枚举 wangzp 20160730 */
typedef enum
{
	EM_RUN_MANAGEMENT_START = 1,    //运营开始
	EM_RUN_MANAGEMENT_END = 2,    //运营结束
	EM_RUN_MANAGEMENT_SWITCH_DATE = 3,    //切换运营日
}EM_RUN_MANAGEMENT_DEF;

/*
 * 异步命令枚举，用于IPC的异步使用
 * wangzp
 * 20150408
 */
typedef enum
{
	EM_ASYN_CMD_SYN_CLOCK = 0,    //时钟同步
	EM_ASYN_CMD_RUN_START = 1,    //运营开始
	EM_ASYN_CMD_RUN_END = 2,    //运营结束
}EM_ASYN_CMD_TYPE;


/*测试模式状态*/
typedef enum
{
	EM_TEST_MODE_STATUS_OPEN = 1,  //测试模式打开
	EM_TEST_MODE_STATUS_CLOSE = 2, //测试模式关闭
}EM_TEST_MODE_STATUS;


typedef enum __EM_ALARM_LIGHT__
{
	EM_ALARM_LIGHT_BLACK = 0, //黑
	EM_ALARM_LIGHT_RED = 1, //红
	EM_ALARM_LIGHT_GREEN = 2, //绿
	EM_ALARM_LIGHT_YELLOW = 3, //黄
	EM_ALARM_LIGHT_BLUE = 4, //蓝
	EM_ALARM_LIGHT_PURPLE = 5, //紫
	EM_ALARM_LIGHT_CYAN = 6, //青
	EM_ALARM_LIGHT_WHITE = 7, //白
	//ALL,//所有
}EM_ALARM_LIGHT;

/*
 * 维修灯颜色枚举
 */
typedef enum
{
	EM_LED_OFF = 0x00,
	EM_LED_GREEN = 0x01,
	EM_LED_RED = 0x02,
	EM_LED_GREEN_SHINE = 0x03,
	EM_LED_RED_SHINE = 0x04,
}EM_OPER_LED_COLOR;

//定义部件编号枚举
typedef enum
{
	EM_SLE_UNIT_TYPE_SYSTEM_MODE_NO               		= 1,    /*系统模块编码*/
	EM_SLE_UNIT_TYPE_TVM_COIN_MODE_NO                   = 2,    /*Tvm硬币模块部件编码*/
	EM_SLE_UNIT_TYPE_TVM_BANKNOTE_DISPENSER_MODE_NO 	= 3,    /*Tvm纸币找零模块部件编码*/
	EM_SLE_UNIT_TYPE_TVM_BANKNOTE_IDENTIFIER_MODE_NO    = 4,    /*Tvm纸币识别模块部件编码*/
	EM_SLE_UNIT_TYPE_TVM_ISSUE_MODE_NO                  = 5,    /*Tvm车票发行模块部件编码*/
	EM_SLE_UNIT_TYPE_AG_WITHDRAW_MODE_NO                = 6,    /*Ag车票回收模块部件编码*/
	EM_SLE_UNIT_TYPE_TVM_VENDING_TPU_MODE_NO            = 7,    /*Tvm售票TPU模块部件编码*/
	EM_SLE_UNIT_TYPE_TVM_RECHARGE_DESKTOP_TPU_MODE_NO   = 8,   /*Tvm充值TPU模块部件编码*/
	EM_SLE_UNIT_TYPE_AG_ENTRY_TPU_MODE_NO               = 9,    /*Ag进站TPU模块部件编码*/
	EM_SLE_UNIT_TYPE_AG_EXIT_TPU_MODE_NO                = 10,   /*Ag出站TPU模块部件编码*/
	EM_SLE_UNIT_TYPE_TVM_TICKET_PRINTER_MODE_NO         = 11,   /*Tvm乘客打印机模块部件编码*/
	EM_SLE_UNIT_TYPE_TVM_MAINTENANCE_PRINTER_MODE_NO    = 12,   /*Tvm维修打印机模块部件编码*/
	EM_SLE_UNIT_TYPE_TVM_DIO_MODE_NO                    = 13,   /*TvmDIO模块部件编码*/
	EM_SLE_UNIT_TYPE_AG_DIO_MODE_NO            			= 14,   /*Ag DIO部件编码*/
	EM_SLE_UNIT_TYPE_AG_GATE_MODE_NO                    = 15,   /*Ag门模块部件编码*/
	EM_SLE_UNIT_TYPE_TVM_BANKNOTE_LOOP_MODE_NO          = 16,   /*Tvm纸币循环模块部件编码*/
	EM_SLE_UNIT_TYPE_TVM_LED_DOUBLE_NO                  = 17,   /*TvmLED显示模块编码*/
	EM_SLE_UNIT_TYPE_TVM_OPERBORAD_NO                   = 18,   /*Tvm维修面板模块编码*/
	EM_SLE_UNIT_TYPE_TVM_UPS_NO                         = 19,   /*TvmUPS模块编码*/
	EM_SLE_UNIT_TYPE_AG_UPS_NO							= 20,   /*AgUPS模块编码*/
	EM_SLE_UNIT_TYPE_BOM_UPS_NO							= 21,   /*BomUPS模块编码*/
	EM_SLE_UNIT_TYPE_BOM_PRINTER_NO						= 22,	/*Bom打印机模块编码*/
	EM_SLE_UNIT_TYPE_BOM_VENDING_TPU					= 23,	/*Bom售票TPU*/
	EM_SLE_UNIT_TYPE_BOM_DESKTOP_TPU					= 24,	/*Bom桌面Tpu*/
	EM_SLE_UNIT_TYPE_BOM_TICKET_ISSUE					= 25,	/*Bom的车票发行*/
	EM_SLE_UNIT_TYPE_SLE_RFID_READER					= 26,	/*RFID读写器*/
	EM_SLE_UNIT_TYPE_SLE_RFID_READER_EX1				= 27,	/*RFID读写器*/
	EM_SLE_UNIT_TYPE_SLE_RFID_READER_EX2				= 28,	/*RFID读写器*/
	EM_SLE_UNIT_TYPE_TCM_TPU_MODE_NO					= 29,	/*TCM TPU*/

	EN_SLE_UNIT_TYPE_TVM_MOBILE_SCAN_NO 				= 30,	/*手机扫二维码支付*/
}EM_SLE_UNIT_TYPE;



/*! \brief
* 	系统关机状态
* 	wangzp
*/
typedef enum
{
	EM_SYSTEM_RUNNING							= 1,	    //运行
	EM_SYSTEM_SHUTDOWN							= 2,	    //关机
	EM_SYSTEM_REBOOT							= 3,	    //重启
	EM_SYSTEM_SOFT_WARE_REBOOT				    = 4,	    //软件重启
}EM_SYSTEM_SHUTDOWN_STATUS;

/*! \brief
* 	系统重启或则软件重启
* 	张保兵
*/
typedef enum
{
	EM_SC_SHUT_DOWN							= 0,	    //SC下发指令关机
	EM_OPER_SHUT_DOWN							= 1,		//维修关机
	EM_AFC_PROC_RESTART						= 2,	    //boot发起软件重启
	EM_SYS_DEVICE_RESTART						= 3,	    //boot发起系统启动
}EM_SYSTEM_RESTART_CMD;

/*! \brief
* 	运行控制命令
* 	jiangzj
*/
typedef enum
{
	EM_SHUT_DOWN						= 0x0101,	    //电源关闭	正常(TVM AG EQM )
	EM_RESTART							= 0x0102,	    //重新启动	关机后重启 (TVM AG EQM )
	EM_RUN_START						= 0x0103,	    //运营开始    (TVM AG EQM 该控制对于COMM与CORE不走控制命令，走运营控制)
	EM_RUN_END							= 0x0104,	    //运营结束        (TVM AG EQM 该控制对于COMM与CORE不走控制命令，走运营控制)
	EM_UNWAKE_MODE						= 0x0105,	    //睡眠模式        (TVM AG EQM )
	EM_WAKE_ON_LAN						= 0x0106,	    //远程唤醒        (TVM AG EQM)
	EM_START_SERVICE					= 0x0107,	    //开始服务    (TVM AG EQM)-----
	EM_PAUSE_SERVICE					= 0x0108,	    //暂停服务    (TVM AG EQM)------
	EM_ENTRY_WAY						= 0x0201,	    //进站	双向(AG)
	EM_EXIT_WAY							= 0x0202,	    //出站      (AG)
	EM_DOUBLE_WAY						= 0x0203,	    //双向          (AG)
	EM_GATE_ALWAYS_ON					= 0x0204,	    //闸门常开        (AG)
	EM_GATE_NORMALLY_CLOSE				= 0x0205,	    //闸门常闭        (AG)
	EM_DEGRADE_RUN_OPEN					= 0x0301,	    //降级运行开	允许(TVM)
	EM_DEGRADE_RUN_CLOSE 				= 0x0302,	    //降级运行关	禁止TVM进(TVM)
	EM_NO_CHANGE_MODE					= 0x0303,	    //无找零模式	强制进入非找(TVM)----
	EM_NO_RECEIVE_BILL_MODE				= 0x0304,	    //不收纸币模式	强制(TVM)--------
	EM_NO_SELL_TICKET_MODE				= 0x0305,	    //只充值模式	强制进入非售(TVM)---
	EM_NO_PRINT_MODE 					= 0x0306,	    //无打印模式	强制进入非打(TVM)---
	EM_N0_BILL_CHANGE_MODE				= 0x0307,	    //无纸币找零	强制(TVM)----
	EM_NO_COIN_CHANGE_MODE				= 0x0308,	    //无硬币找零	强制进入无硬(TVM)---
	EM_RESUME_NORMAL_MODE				= 0x0309,	    //恢复正常模式	退出(TVM)----
	EM_CLEAR_MONEY						= 0x030A,	    //清空钱币	清空钱币  (TVM)
	EM_NO_RECEIVE_COIN_MODE				= 0x030B,	    //不收硬币模式	(TVM)------
//	EM_CASH_BOX_PASSWORD_TEST			= 0x030C,	    //取钱箱随机密码验证	预留(TVM)
	EM_ONLY_RECEIVE_BILL_MODE			= 0X0310,		//只收纸币----
	EM_ONLY_RECEIVE_COIN_MODE			= 0X0311,		//只收硬币-----
	EM_ONLY_TICKET_ONLY_COINCHANGE		= 0X0312,		//只售票/只硬币找零
	EM_TICKET_BILLCHANGE_MODE 			= 0x0313,		//a4	03		只售票/只纸币找零
//	EM_TICKET_NOCHANGE_MODE				= 0x0314,		//只售票/无找零
//	EM_ONLY_BILLCHANGE_MODE				= 0x0315,		//服务中/只纸币找零
//	EM_ONLY_COINCHANGE_MODE				= 0x0316,		//服务中/只硬币找零
	EM_BANK_CARD_RECHARGE_MODE         = 0x0317,       //只银行卡充值
	EM_ACC_CARD_SLE_ONLY_MODE          = 0x0318,       //只储值卡售票

	EM_SELL_TICKET_MODE					= 0x0401,	    //只售票模式    (BOM)----
	EM_COMPENSATION_MODE				= 0x0402,	    //补票模式        (BOM)
	EM_SELL_AND_COMPENSATION_MODE		= 0x0403,	    //售补票模式       (BOM)
	EM_FORCE_LOG_OUT					= 0x0404,       //强制登出      (BOM)
	EM_SWITCH_BIZ_DATE					= 0x0501,		//切换运营日(SLE自定义)
	EM_RESTART_AFC_SOFT					= 0x0601,		//AFC软件重启

	EM_AG_HEIGHT_CHECK_SENSOR_ON		= 0x0701,		//AG身高检测传感器开启
	EM_AG_HEIGHT_CHECK_SENSOR_CLOSE		= 0x0801,		//AG身高检测传感器关闭

	EM_AG_ENTRY_AISLE_TYPE_NORMAL		= 0x0802,		//AG进站通道类型设置-正常通道
	EM_AG_ENTRY_AISLE_TYPE_COMMON		= 0x0803,		//AG进站通道类型设置-通用通道
	EM_AG_ENTRY_AISLE_TYPE_SPECIAL		= 0x0804,		//AG进站通道类型设置-专用通道
	EM_AG_EXIT_AISLE_TYPE_NORMAL		= 0x0805,		//AG出站通道类型设置-正常通道
	EM_AG_EXIT_AISLE_TYPE_COMMON		= 0x0806,		//AG出站通道类型设置-通用通道
	EM_AG_EXIT_AISLE_TYPE_SPECIAL		= 0x0807,		//AG出站通道类型设置-专用通道

/****************以下控制命令前提是不干涉其他功能，只是单独某项功能的开启关闭*****************/

	EM_TVM_SUPPORT_RECHARGE_MODE		= 0x0901,		//TVM支持充值服务(开启充值功能)
	EM_TVM_UNSUPPORT_RECHARGE_MODE		= 0x0902,		//TVM不支持充值服务(关闭充值功能)

	EM_TVM_SUPPORT_VEND_TICKET_MODE		= 0x0903,		//TVM支持发售单程票(开启发售单程票功能)
	EM_TVM_UNSUPPORT_VEND_TICKET_MODE	= 0x0904,		//TVM不支持发售单程票(关闭发售单程票功能)

	EM_TVM_SUPPORT_COIN_CHANGE_MODE		= 0x0905,		//TVM支持硬币找零(开启硬币找零功能)
	EM_TVM_UNSUPPORT_COIN_CHANGE_MODE	= 0x0906,		//TVM不支持硬币找零(关闭硬币找零功能)

	EM_TVM_SUPPORT_BILL_CHANGE_MODE		= 0x0907,		//TVM支持纸币找零(开启纸币找零功能)
	EM_TVM_UNSUPPORT_BILL_CHANGE_MODE	= 0x0908,		//TVM不支持纸币找零(关闭纸币找零功能)

	EM_TVM_SUPPORT_RECEIVE_COIN_MODE	= 0x0909,		//TVM支持接收硬币(开启接收硬币功能)
	EM_TVM_UNSUPPORT_RECEIVE_COIN_MODE	= 0x0910,		//TVM不支持接收硬币(关闭接收硬币功能)

	EM_TVM_SUPPORT_RECEIVE_BILL_MODE	= 0x0911,		//TVM支持接收纸币(开启接收纸币功能)
	EM_TVM_UNSUPPORT_RECEIVE_BILL_MODE	= 0x0912,		//TVM不支持接收纸币(关闭接收纸币功能)

}EM_SLE_RUN_CONTROL_CMD;

/*sle交易类型*/
typedef enum
{
	EM_TRANSACATION_TYPE_TVM_VENDING  		 = 0x01,    //售票
	EM_TRANSACATION_TYPE_TVM_CHARGE       	 = 0x02,    //充值
	EM_TRANSACATION_TYPE_TVM_QUERY         	 = 0x03,    //查询
	EM_TRANSACATION_TYPE_AG_ENTRY			 = 0x04, 	//AG进站
	EM_TRANSACATION_TYPE_AG_WITHDRAW_EXIT		 = 0x05, 	//AG回收出站
	EM_TRANSACATION_TYPE_AG_UNWITHDRAW_EXIT		 = 0x06, 	//AG刷卡出站
	EM_TRANSACATION_TYPE_SVCARD_CONSUME_FOR_VENDING   = 0x07,    //储值卡扣款
}EM_SLE_TRANSACATION_TYPE;

/*sle业务类型*/
typedef enum
{
	EM_BUSINESS_TYPE_CASHBOX_SET  		 = 0x01,    //钱箱安装
	EM_BUSINESS_TYPE_CASHBOX_DOWN        = 0x02,    //钱箱卸下
	EM_BUSINESS_TYPE_CASHBOX_FLUSH       = 0x03,    //钱箱清空
	EM_BUSINESS_TYPE_CASHBOX_SUPPLY		 = 0x04, 	//补充找零
	EM_BUSINESS_TYPE_TICKETBOX_SET		 = 0x05, 	//票箱安装
	EM_BUSINESS_TYPE_TICKETBOX_DOWN		 = 0x06, 	//票箱卸下
	EM_BUSINESS_TYPE_TICKETBOX_FLUSH     = 0x07,    //票箱清空
	EM_BUSINESS_TYPE_TICKETBOX_SUPPLY	 = 0x08, 	//补充车票
	EM_BUSINESS_TYPE_TVM_BALANCE		 = 0x09, 	//TVM结算
	EM_BUSINESS_TYPE_AG_BALANCE			 = 0x0A, 	//AG审计
	EM_BUSINESS_TYPE_BOM_SHIFT_BALANCE	 = 0x0B, 	//BOM班次结算
	EM_BUSINESS_TYPE_TVM_AUDIT			 = 0x0C, 	//TVM审计
	EM_BUSINESS_TYPE_CASHBOX_AUTO_RECYCLE= 0x0D,    //Hopper自动回收
	EM_BUSINESS_TYPE_TVM_FAULT           = 0x0E,    //tvm故障交易
}EM_SLE_BUSINESS_TYPE;

/*sle事件类型*/
typedef enum
{
	EM_EVENT_TYPE_BLACKLIST  		 		= 0x01,    //黑名单使用, Param: 卡号 char szCardNo[21]
	EM_EVENT_TYPE_GATE_ENTRY_INTRUSION      = 0x02,    //非法进闸， Param：无
	EM_EVENT_TYPE_GATE_EXIT_INTRUSION       = 0x03,    //非法出闸， Param：无
	EM_EVENT_TYPE_LOGIN_TIMEOUT		 		= 0x04, 	//维修门打开后一定时间内未登录， Param：无
	EM_EVENT_TYPE_LOGIN_FIAL		 		= 0x05, 	//维修门打开后3次登录失败， Param：无
	EM_EVENT_TYPE_ILLEGAL_CASHBOX_DOWN		= 0x06, 	//非法移动钱箱， Param：钱箱号，char szBoxID[9]
	EM_EVENT_TYPE_ILLEGAL_TICKETBOX_DOWN    = 0x07,    //非法移动票箱， Param：票箱号，char szBoxID[9]
	EM_EVENT_TYPE_TICKET_AMOUNT_OUT	 		= 0x08, 	//票卡余额超过设定值, Param: 卡号 char szCardNo[21];
	EM_EVENT_TYPE_LOGIN		 				= 0x09, 	//登陆， Param：无
	EM_EVENT_TYPE_LOGOUT					= 0x0A, 	//登出， Param：无
	EM_EVENT_TYPE_OCCER_ERROR	 			= 0x0B, 	//SLE发生故障， Param：故障代码，int iErrCode, bool bOccer
	EM_EVENT_TYPE_BOM_HELP	 				= 0x0C, 	//BOM 求救， Param：无
	EM_EVENT_TYPE_SETTLEMENT_OK	 			= 0x0D, 	//结算通过， Param：无
	EM_EVENT_TYPE_SETTLEMENT_NG	 			= 0x0E, 	//结算失败 Param：无
	EM_EVENT_TYPE_CLOCK_DIFF				= 0x10,		//时钟差异

}EM_SLE_EVENT_TYPE;

//乘客操作相关动作
typedef enum
{
	EM_TVM_PASSENGER_ACTION_TYPE_CLICK_PRICE_BUTTON,	//TVM乘客点击票价按钮，Param:票价，int
	EM_TVM_PASSENGER_ACTION_TYPE_CLICK_STATION_BUTTON,	//TVM乘客点击车站按钮，Param:车站ID，BYTE[4]
	EM_TVM_PASSENGER_ACTION_TYPE_CLICK_TICKET_NUM_BUTTON,//TVM乘客点击票卡张数按钮，Param:票卡张数，int
	EM_TVM_PASSENGER_ACTION_TYPE_CLICK_CANCEL_BUTTON,	//TVM乘客点击取消按钮，Param:无
	EM_TVM_PASSENGER_ACTION_TYPE_CLICK_CONFIRM_BUTTON,	//TVM乘客点击确认按钮，Param:无
	EM_TVM_PASSENGER_ACTION_TYPE_CLICK_RECHARGE_BUTTON,	//TVM乘客点击充值按钮，Param:无
	EM_TVM_PASSENGER_ACTION_TYPE_CLICK_INQUIRE_BUTTON,	//TVM乘客点击查询按钮，Param:无
	EM_TVM_PASSENGER_ACTION_TYPE_CLICK_PAYMENT_BUTTON,	//TVM乘客点击支付方式按钮，Param:ST_TVM_PAY_TYPE
	EM_TVM_PASSENGER_ACTION_TYPE_TIMEOUT,				//TVM超时未操作，Param:无
	EM_TVM_PASSENGER_ACTION_TYPE_INSERT_CARD,			//TVM充值卡座乘客插入车票，Param:无
	EM_TVM_PASSENGER_ACTION_TYPE_INSERT_BANKCARD,		//TVM乘客插入银行卡，Param:无
	EM_TVM_PASSENGER_ACTION_TYPE_INSERT_COIN,			//TVM乘客投入硬币，Param:硬币数量，面额
	EM_TVM_PASSENGER_ACTION_TYPE_INSERT_BILL,			//TVM乘客投入纸币，Param:纸币数量，面额

	/******************************************TVIP**************************************/
	EM_TVM_PASSENGER_ACTION_TYPE_SCAN_QRCODE,			//TVM乘客扫描二维码, param:无
	EM_TVM_PASSENGER_ACTION_TYPE_CONFIRM_QRCODE_PAYMETHOD,	//TVM乘客确认二维码支付支付通道, param:支付通道
	EM_TVM_PASSENGER_ACTION_TYPE_QRCODE_PAY,			//TVM乘客二维码支付，param:支付金额
	EM_TVM_PASSENGER_ACTION_TYPE_QRCODE_TRANS_RESULT,			//TVM乘客二维码支付，交易请求结果，param:结果
	EM_TVM_PASSENGER_ACTION_ORDER_EXECUTE_START,			//TVM订单开始执行，锁定通道
	EM_TVM_PASSENGER_ACTION_ORDER_EXECUTE_SUCCESS,			//TVM订单开始执行成功，param:
	EM_TVM_PASSENGER_ACTION_ORDER_EXECUTE_FAULT,			//TVM订单执行故障，param:响应码
	EM_TVM_PASSENGER_ACTION_TYPE_CLICK_FEICH_BUTTON,		//TVM乘客点击取票按钮，Param:无
	EM_TVM_PASSENGER_ACTION_TYPE_OUT_TICKET_AUTH_START,		//TVM出票认证开始，Param:无
	EM_TVM_PASSENGER_ACTION_TYPE_QRCODE_OUT_TICKET_AUTH_RESULT,			//TVM乘客二维码取票出票认证结果，param:结果
	/******************************************TVIP END**************************************/


	EM_TVM_PASSENGER_ACTION_TYPE_TAKEAWAY_CHANGE,		//TVM乘客取走找零，Param:无
	EM_TVM_PASSENGER_ACTION_TYPE_TAKEAWAY_CARD,			//TVM充值卡座乘客取走车票，Param:无
	EM_TVM_PASSENGER_ACTION_TYPE_TAKEAWAY_BANKCARD,		//TVM乘客取走银行卡，Param:无
	EM_TVM_PASSENGER_ACTION_RESP_CALCULATE_PRICE_RESULT,//TVM乘客动作反馈，计算票价结果，Param:票价，int
	EM_TVM_PASSENGER_ACTION_RESP_REJECT_COIN,			//TVM乘客动作反馈，拒收硬币，Param:面额，int，0标识不能识别
	EM_TVM_PASSENGER_ACTION_RESP_REJECT_BILL,			//TVM乘客动作反馈，拒收纸币，Param:面额，int，0标识不能识别
	EM_TVM_PASSENGER_ACTION_RESP_VENDING_START,			//TVM乘客动作反馈，开始售票，Param:无
	EM_TVM_PASSENGER_ACTION_RESP_VENDING_FINISH,		//TVM乘客动作反馈，售票完成，Param:写票OK数量int，出票数量int
	EM_TVM_PASSENGER_ACTION_RESP_VENDING_OK,			//TVM乘客动作反馈，售票1张OK，Param:无
	EM_TVM_PASSENGER_ACTION_RESP_VENDING_FAIL,			//TVM乘客动作反馈，售票失败，Param:无
	EM_TVM_PASSENGER_ACTION_RESP_VENDING_REJECT,		//TVM乘客动作反馈，售票回收，Param:无
	EM_TVM_PASSENGER_ACTION_RESP_CHANGE_JUDGE_START,	//TVM乘客动作反馈，开始找零预判，Param:无
	EM_TVM_PASSENGER_ACTION_RESP_CHANGE_JUDGE_FINISH,	//TVM乘客动作反馈，找零预判完成，Param:无
	EM_TVM_PASSENGER_ACTION_RESP_CHANGE_JUDGE_FAILTURE,	//TVM乘客动作反馈，找零预判失败，Param:无
	EM_TVM_PASSENGER_ACTION_RESP_CHANGE_START,			//TVM乘客动作反馈，开始找零，Param:找零金额 int
	EM_TVM_PASSENGER_ACTION_RESP_CHANGE_FINISH,			//TVM乘客动作反馈，找零完成，Param:纸币找零金额int，硬币找零金额int
	EM_TVM_PASSENGER_ACTION_RESP_RECHARGE_START,		//TVM乘客动作反馈，开始充值，Param:无
	EM_TVM_PASSENGER_ACTION_RESP_RECHARGE_FINISH,		//TVM乘客动作反馈，充值完成，Param:无
	EM_TVM_PASSENGER_ACTION_RESP_REFUND_START,			//TVM乘客动作反馈，开始退币，Param:无
	EM_TVM_PASSENGER_ACTION_RESP_REFUND_FINISH,			//TVM乘客动作反馈，退币完成，Param:无
	EM_TVM_PASSENGER_ACTION_RESP_ENCASH_START,			//TVM乘客动作反馈，钱币压箱开始，Param:无
	EM_TVM_PASSENGER_ACTION_RESP_ENCASH_FINISH,			//TVM乘客动作反馈，钱币压箱完成，Param:无
	EM_TVM_PASSENGER_ACTION_RESP_THU_FAILTURE,			//TVM乘客动作反馈，交易过程中车票发行模块故障，Param:故障数量int，故障码int[5]
	EM_TVM_PASSENGER_ACTION_RESP_CHU_FAILTURE,			//TVM乘客动作反馈，交易过程中硬币模块故障，Param:故障数量int，故障码int[5]
	EM_TVM_PASSENGER_ACTION_RESP_BHU_FAILTURE,			//TVM乘客动作反馈，交易过程中纸币模块故障，Param:故障数量int，故障码int[5]
	EM_TVM_PASSENGER_ACTION_RESP_BILL_CHANGER_FAILTURE,	//TVM乘客动作反馈，交易过程中纸币找零模块故障，Param:故障数量int，故障码int[5]
	EM_TVM_PASSENGER_ACTION_RESP_TPU_FAILTURE,			//TVM乘客动作反馈，交易过程中TPU模块故障，Param:TPU类型 int,故障数量int，故障码int[5]

	EM_AG_PASSENGER_ACTION_TYPE_INSERT_TICKET,			//AG乘客插入车票，Param:无
	EM_AG_PASSENGER_ACTION_TYPE_ENTRY_SWIPE,			//AG乘客进站端刷卡，Param:无
	EM_AG_PASSENGER_ACTION_TYPE_EXIT_SWIPE,				//AG乘客出站端刷卡，Param:无
	EM_AG_PASSENGER_ACTION_TYPE_ENTRY_PASS_ONE,			//AG进站方向乘客通过1人，Param:无
	EM_AG_PASSENGER_ACTION_TYPE_EXIT_PASS_ONE,			//AG出站方向乘客通过1人，Param:无
	EM_AG_PASSENGER_ACTION_TYPE_ENTRY_TIMEOUT,			//AG进站方向超时未通过1人，Param:无
	EM_AG_PASSENGER_ACTION_TYPE_EXIT_TIMEOUT,			//AG出站方向超时未通过1人，Param:无
	EM_AG_PASSENGER_ACTION_TYPE_ENTRY_TAILING,			//AG进站方向尾随，Param:无
	EM_AG_PASSENGER_ACTION_TYPE_EXIT_TAILING,			//AG出站方向尾随，Param:无
	EM_AG_PASSENGER_ACTION_TYPE_ENTRY_INTRUDE,			//AG进站方向闯入，Param:无
	EM_AG_PASSENGER_ACTION_TYPE_EXIT_INTRUDE,			//AG出站方向闯入，Param:无
	EM_AG_PASSENGER_ACTION_TYPE_ENTRY_FORCE_PASS,		//AG进站方向强行闯关通过1人，Param:无
	EM_AG_PASSENGER_ACTION_TYPE_EXIT_FORCE_PASS,		//AG出站方向强行闯关通过1人，Param:无
	EM_AG_PASSENGER_ACTION_RESP_CHECK_OK,				//AG乘客检票OK，Param:车票类型ID int, 车票ID char szCardNo[21];
	EM_AG_PASSENGER_ACTION_RESP_CHECK_NG,				//AG乘客检票NG，Param:失败原因 EM_TICKET_TRANS_RESULT，TPU原厂故障码 int
	EM_AG_PASSENGER_ACTION_RESP_RECYCLE_OK,				//AG车票回收OK，Param:无
	EM_AG_PASSENGER_ACTION_RESP_RECYCLE_FAIL,			//AG车票回收失败，Param:无

}EM_SLE_PASSENGER_ACTION_TYPE;

//站员操作相关动作
typedef enum
{
	EM_SLE_STAFF_ACTION_TYPE_LOGIN,				//SLE操作员登录，Param: 操作员ID char[20];
	EM_SLE_STAFF_ACTION_TYPE_LOGOUT,			//SLE操作员登出，Param: 操作员ID char[20];
	EM_SLE_STAFF_ACTION_TYPE_PWD_ERROR,			//SLE操作员密码输入错误，Param: 操作员ID char[20];
}EM_SLE_STAFF_ACTION_TYPE;

//版本类型
typedef enum
{
	EM_AFC_VERSION_TYPE_MAIN_SOFTWARE = 1,			//主软件
	EM_AFC_VERSION_TYPE_LIB_SOFTWARE = 2,			//产品库软件
	EM_AFC_VERSION_TYPE_MANAGER_SOFTWARE = 3,		//管理软件
	EM_AFC_VERSION_TYPE_HARDWARE = 4,				//硬件
	EM_AFC_VERSION_TYPE_SLAVE_UNIT_RFID = 5,		//从属RFID
	EM_AFC_VERSION_TYPE_SLAVE_UNIT_HOPPER1 = 6,		//从属HOPPER1
	EM_AFC_VERSION_TYPE_SLAVE_UNIT_HOPPER2 = 7,		//从属HOPPER2
	EM_AFC_VERSION_TYPE_SLAVE_UNIT_1 = 11,			//从属部件1，根据具体模块不同定义
	EM_AFC_VERSION_TYPE_SLAVE_UNIT_2 = 12,			//从属部件2，根据具体模块不同定义
	EM_AFC_VERSION_TYPE_SLAVE_UNIT_3 = 13,			//从属部件3，根据具体模块不同定义
	EM_AFC_VERSION_TYPE_SLAVE_UNIT_4 = 14,			//从属部件4，根据具体模块不同定义
	EM_AFC_VERSION_TYPE_SLAVE_UNIT_5 = 15,			//从属部件5，根据具体模块不同定义
}EM_CSS_VERSION_TYPE;

//交易子类型
typedef enum
{
	EM_TRANSACATION_SUB_TYPE_COMPENSATION_OVERTIME  		 = 0x11,    //超时更新
	EM_TRANSACATION_SUB_TYPE_COMPENSATION_OVERRIDE       	 = 0x12,    //超程更新
	EM_TRANSACATION_SUB_TYPE_COMPENSATION_REPAIRE_ENTRY    	 = 0x13,    //进站更新
	EM_TRANSACATION_SUB_TYPE_COMPENSATION_REPAIRE_EXIT       = 0x14,    //出站更新

	EM_TRANSACATION_SUB_TYPE_SALE_EXITTICKET_FREE            = 0x21,    //发售免费出站票
	EM_TRANSACATION_SUB_TYPE_SALE_EXITTICKET_PAID            = 0x22,    //发售付费出站票
	EM_TRANSACATION_SUB_TYPE_SALE_EXITTICKET_PAID_PENALTY    = 0x23,    //发售付费出站票

	EM_TRANSACATION_SUB_TYPE_NON_COMMERCIAL_INCOMING  		 = 0x31,    //非营业型收入
	EM_TRANSACATION_SUB_TYPE_NON_COMMERCIAL_EXPENDITURE  	 = 0x32,    //非营业型支出

	EM_TRANSACATION_SUB_TYPE_NONE  	 = 0,    //没有子类型

}EM_SLE_TRANSACATION_SUB_TYPE;


typedef enum
{

	EM_SEQ_TYPE_BUSI_PUB_SEQ 	= 3001,   			/*公共流水号，数据存储模块专用*/
	EM_SEQ_TYPE_ACC_UDSN     	= 3002,
	EM_SEQ_TYPE_YKT_UDSN    	= 3003,
	EM_SEQ_TYPE_AFC_SEQ			= 3004,             /*AFC数据流水号*/

	EM_SEQ_TYPE_TVM_TRANS_SEQ	= 3006,             /*TVM交易流水号*/
	EM_SEQ_TYPE_OPR_SEQ			= 3007,             /*操作流水号*/
	EM_SEQ_TYPE_TIC_BOX_SEQ	 	= 3008,           	/*票箱更换流水号*/
	EM_SEQ_TYPE_BILL_BOX_SEQ	= 3009,           	/*纸币钱箱更换流水号*/
	EM_SEQ_TYPE_COIN_BOX_SEQ	= 3010,           	/*硬币钱箱更换流水号*/

	EM_SEQ_TYPE_EVENT_SEQ 		= 3016, 			/*事件流水号*/
	EM_SEQ_TYPE_UNDEF_SEQ 		= 3017,


	EM_SEQ_TYPE_ACC_UDSN_SV  	= 3021, 			//一票通储值票

	//SAM1 对应的UDSN；在各设备中， SAM1分别对应： BOM 桌面一卡通充值SAM； AG 进站一卡通SAM
	EM_SEQ_TYPE_UDSN_SAM1       = 3026,

	//SAM2 对应的UDSN；在各设备中， SAM2分别对应： BOM 桌面一卡通消费SAM； AG 出站一卡通SAM
	EM_SEQ_TYPE_UDSN_SAM2       = 3027,             //SAM2 对应的UDSN；

	EM_SEQ_TYPE_UDSN_SAM3       = 3028,             //SAM3 对应的UDSN；

	EM_SEQ_TYPE_RECORD_SN_YPT 	= 3012, 			/*一卡通RecordSN，用于 YKT 交易数据存储流水号，而非直接使用TPU返回的UDSN*/
	EM_SEQ_TYPE_RECORD_SN_YKT 	= 3013, 			/*一票通RecordSN，用于 YPT 交易数据存储，而非直接使用TPU返回的UDSN*/
	EM_SEQ_TYPE_SETTLEMENT_SEQ 	= 3101,             /* 结算流水号*/
	EM_SEQ_TYPE_BALANCE_SEQ 	= 3102,             /* 操作员结帐流水号*/

	EM_SEQ_TYPE_AUDIT_DATA_SEQ  = 3150,             /*审计数据落地流水号*/

	EM_SEQ_TYPE_VOUCHER_FOR_PASSENGER 	= 3201,             /* 乘客票据流水号*/
	EM_SEQ_TYPE_VOUCHER_FOR_OPERATOR 	= 3202,             /* 操作员票据流水号*/

	EM_SEQ_TYPE_COIN_SUPPLY_VOUCHER = 3301,								//硬币补充小单流水号
	EM_SEQ_TYPE_COIN_SUPPLY_BOX_ILLEGAL_CHANGE_VOUCHER = 3302,			//硬币补充箱非法卸下小单流水号 //key值不存在非法与正常 在此作为卸下key值使用
	EM_SEQ_TYPE_COIN_WITHDRAW_BOX_NORMAL_CHANGE_VOUCHER = 3303,			//硬币回收箱正常卸下小单流水号
	EM_SEQ_TYPE_COIN_WITHDRAW_BOX_ILLEGAL_CHANGE_VOUCHER = 3304,		//硬币回收箱非法卸下小单流水号
	EM_SEQ_TYPE_COIN_CLEAR_EMPTY_VOUCHER = 3305,						//硬币清空小单流水号
	EM_SEQ_TYPE_COIN_WITHDRAW_BOX_SET_VOUCHER = 3306,					//硬币回收箱安装流水号
	EM_SEQ_TYPE_COIN_SPARE_BOX_DOWN_VOUCHER = 3307,						//硬币备用找零箱卸下小单流水号
	EM_SEQ_TYPE_COIN__AUTO_RECYCLE_VOUCHER = 3308,						//硬币hopper自动回收
	EM_SEQ_TYPE_COIN_SUPPLY_BOX_DOWN_VOUCHER = 3309,					//硬币补充箱卸下小单流水号 //key值不存在非法与正常 在此作为卸下key值使用

	EM_SEQ_TYPE_BILL_SUPPLY_VOUCHER = 3310,								//纸币补充小单流水号
	EM_SEQ_TYPE_BILL_SPARE_CHANGE_BOX_ILLEGAL_CHANGE_VOUCHER = 3311,	//纸币备用找零箱非法卸下小单流水号
	EM_SEQ_TYPE_BILL_WITHDRAW_BOX_NORMAL_CHANGE_VOUCHER = 3312,			//纸币回收箱正常更换小单流水号
	EM_SEQ_TYPE_BILL_WITHDRAW_BOX_ILLEGAL_CHANGE_VOUCHER = 3313,		//纸币回收箱非法换下小单流水号
	EM_SEQ_TYPE_BILL_WASTE_BOX_NORMAL_CHANGE_VOUCHER = 3314,			//纸币废钞箱正常更换小单流水号
	EM_SEQ_TYPE_BILL_WASTE_BOX_DOWN_VOUCHER = 3315,						//纸币废钞箱换下小单流水号
	EM_SEQ_TYPE_BILL_SPARE_CHANGE_BOX_NORMAL_CHANGE_VOUCHER = 3316,		//纸币备用找零箱正常卸下小单流水号
	EM_SEQ_TYPE_BILL_SUPPLY_BOX_DOWN_VOUCHER = 3317,					//纸币找零补充箱卸下小单流水号
	EM_SEQ_TYPE_BILL_CLEAR_EMPTY_VOUCHER = 3318,						//纸币清空小单流水号
	EM_SEQ_TYPE_BILL_WITHDRAW_BOX_SET_VOUCHER = 3319,					//纸币回收箱换上小单流水号
	EM_SEQ_TYPE_BILL_WASTE_BOX_SET_VOUCHER = 3410,						//纸币废钞箱换上小单流水号
	EM_SEQ_TYPE_BILL_AUTO_RECYCLE_VOUCHER = 3411,						//纸币循环鼓自动回收


	EM_SEQ_TYPE_TICKET_SUPPLY_VOUCHER = 3320,							//车票补充小单流水号
	EM_SEQ_TYPE_TICKET_SUPPLY_BOX_ILLEGAL_CHANGE_VOUCHER = 3321,		//车票补充箱非法卸下小单流水号
	EM_SEQ_TYPE_TICKET_WITHDRAW_BOX_NORMAL_CHANGE_VOUCHER = 3322,		//车票回收箱正常更换小单流水号
	EM_SEQ_TYPE_TICKET_WITHDRAW_BOX_ILLEGAL_CHANGE_VOUCHER = 3323,		//车票回收箱非法更换小单流水号
	EM_SEQ_TYPE_TICKET_WASTE_BOX_NORMAL_CHANGE_VOUCHER = 3324,			//车票废票箱正常更换小单流水号
	EM_SEQ_TYPE_TICKET_WASTE_BOX_ILLEGAL_CHANGE_VOUCHER = 3325,			//车票废票箱非法换下小单流水号
	EM_SEQ_TYPE_TICKET_CLEAR_EMPTY_VOUCHER = 3326,						//车票清空小单流水号
	EM_SEQ_TYPE_TICKET_WITHDRAW_BOX_SET_VOUCHER = 3327,					//车票回收箱安装流水号
	EM_SEQ_TYPE_TICKET_WASTE_BOX_SET_VOUCHER = 3328,					//车票废票箱换上单流水号
	EM_SEQ_TYPE_TICKET_SUPPLY_BOX_DOWN_VOUCHER = 3329,					//车票补充箱卸下小单流水号

	EM_SEQ_TYPE_FAULT_TRANS_LESS_CHANGE_VOUCHER = 3330,					//少找零小单流水号
	EM_SEQ_TYPE_FAULT_TRANS_LESS_OUTTICKET_VOUCHER = 3331,				//少出票小单流水号
}EM_SEQ_TYPE;






//定义状态或故障码来源
typedef enum
{
	EM_FROM_SYSTEM,
	EM_FROM_SC,
	EM_FROM_OPERATOR,
}EM_STATUS_SOURCE;


//定义LOKI配置结构体信息--wangzp at 11th, Aug,2014
typedef struct __ST_SLE_LOKI_INFO__
{
	char szClassId[128];		//类标识ID
	char szClassName[128];	//类名称
	bool bIsEnable;			//是否启用标志
}ST_SLE_LOKI_INFO;


//定义Sle设备类型枚举
typedef enum
{
	EM_TVM_DEVICE = 1,    /*TVM*/
	EM_AG_DEVICE  = 2,    /*AG*/
	EM_BOM_DEVICE = 3,    /*BOM*/
	EM_TCM_DEVICE = 4,    /*TCM*/
	EM_AVM_DEVICE = 5,    /*AVM*/
	EM_TOM_DEVICE = 6,    /*TOM*/
}EM_SLE_DEVICE_TYPE;

//定义设备子类型, 用于区分不同类型TVM/CVM/AG等, 主要用于区分AG
typedef enum EM_SLE_DEVICE_SUB_TYPE
{
	EM_SLE_NO_SUB_TYPE = 0x00,								/*!<无设备子类型*/
	EM_SLE_AG_SUB_STANDARD_ENTRY = 0x01,					/*!<标准进站AG*/
	EM_SLE_AG_SUB_STANDARD_EXIT = 0x02,						/*!<标准出站AG*/
	EM_SLE_AG_SUB_STANDARD_ENTRY_AND_EXIT = 0x03, 			/*!<标准双向AG*/
	EM_SLE_AG_SUB_WIDE_CHUNNEL_ENTRY = 0x04,				/*!<宽通道进站AG*/
	EM_SLE_AG_SUB_WIDE_CHUNNEL_EXIT  = 0x05,				/*!<宽通道出站AG*/
	EM_SLE_AG_SUB_WIDE_CHUNNEL_ENTRY_AND_EXIT = 0x06,		/*!<宽通道双向AG*/
}EM_SLE_DEVICE_SUB_TYPE;

//定义闸机检票时相应的配置信息
typedef struct _ST_CHECK_TICKET_CFG_INFO_
{
	int iTicketType;										//票卡类型
	char szTicketChName[50];								//卡中文名
	char szTicketEnName[50];								//卡英文名
	EM_ALARM_LIGHT emAlarmLight;							//对应的灯光颜色
	int iSoundType;											//声音类别(项目化, 根据配置生效)
	/*
	以后根据需要再添加一些其他的相关检票对应配置信息
	 */
}ST_CHECK_TICKET_CFG_INFO;

/*!
 * \brief 发售过程中出票信息记录
 */
typedef struct
{
	int iWriteTicketOKCount;	//写票成功数量
	int iOutTicketOKCount;			//出票成功数量
	int iProvideCount[8];		//提票数量,1~8号票箱
	int iRejectCount;			//回收数量
//	int iEscrowCountBefore;		//交易前暂存区数量
//	int iEscrowCountAfter;		//交易后暂存区数量
}ST_TICKET_ISSUE_PROCESS_INFO;



 /************************************** 数据类定义 end *******************************************/

/*************************************** 业务层定义 ******************************************/

typedef enum
{
	EM_TRANSACATION_RESULT_TVM_VENDING_OK = 1,						//售票找零完全成功
	EM_TRANSACATION_RESULT_TVM_VENDING_CANCEL_OK = 2,				//售票取消完全成功
	EM_TRANSACATION_RESULT_TVM_VENDING_NG_CHANGE_OK = 3,			//售票失败, 退款/找零成功
	EM_TRANSACATION_RESULT_TVM_VENDING_CHANGE_NG = 4,				//售票完成, 找零卡币, 故障交易
	EM_TRANSACATION_RESULT_TVM_VENDING_CANCEL_JAM = 5,				//售票取消, 退款卡币, 故障交易
	EM_TRANSACATION_RESULT_TVM_VENDING_SVT_CONSUME_FAIL = 6,		//售票Svt扣款失败, 取消交易成功
	EM_TRANSACATION_RESULT_TVM_VENDING_SVT_OUT_TICKET_FAIL = 7, 	//售票Svt扣费成功, 但出票失败, 故障交易
	EM_TRANSACATION_RESULT_TVM_RECHARGE_OK = 101,					//充值成功
	EM_TRANSACATION_RESULT_TVM_RECHARGE_NG_REFUND_OK = 102,			//充值失败, 退款成功
	EM_TRANSACATION_RESULT_TVM_RECHARGE_CANCEL_OK = 103,			//充值取消, 退款成功
	EM_TRANSACATION_RESULT_TVM_RECHARGE_REFUND_JAM = 104,			//充值失败, 退币卡币, 故障交易
	EM_TRANSACATION_RESULT_TVM_RECHARGE_CANCEL_JAM = 105,			//充值取消, 退款卡币, 故障交易
	EM_TRANSACATION_RESULT_TVM_RECHARGE_CARD_DATA_INVALID = 106,	//充值插入数据无效卡
	EM_TRANSACATION_RESULT_TVM_RECHARGE_CARD_TYPE_INVALID = 107,	//充值插入不允许充值类型卡
	EM_TRANSACATION_RESULT_TVM_RECHARGE_CARD_BLACKLIST = 108,		//充值插入黑名单卡
	EM_TRANSACATION_RESULT_TVM_EQUERY_OK = 201,						//查询结束
	EM_TRANSACATION_RESULT_TVM_EQUERY_CARD_DATA_INVALID = 202,		//查询插入数据无效卡
	EM_TRANSACATION_RESULT_TVM_EQUERY_CARD_BLACKLIST = 203,			//查询插入黑名单卡
}EM_TRANSACATION_RESULT;


/* 车站信息列表，用UI 、打印等使用 */
typedef struct StationInfoCss_t
{

  /*车站编码*/
  unsigned int StationId;

  /*车站所属线路*/
  unsigned int LineId;

  /*车站中文名称*/
  char StationNameCN[100];

  /*车站英文名称*/
  char StationNameEN[100];

}ST_SLE_STATION_LIST_CSS;

/*!
 * \brief ST_ERROR_INFO 表结构体
 */
typedef struct
{
	int	ErrorID;							//错误ID
	int	ErrorCode;							//错误代码
	char szErrorName[50];					//错误含义
}ST_ERROR_INFO;

// 支付开始函数的参数结构体
typedef struct __ST_DENOMINATION__
{
	unsigned int deno1:1;		//面值1单位
	unsigned int deno2:1;		//面值2单位
	unsigned int deno5:1;		//
	unsigned int reserve1:1;		//

	unsigned int deno10:1;
	unsigned int deno20:1;
	unsigned int deno50:1;
	unsigned int deno25:1;

	unsigned int deno100:1;
	unsigned int deno200:1;
	unsigned int deno500:1;
	unsigned int deno250:1;

	unsigned int deno1000:1;
	unsigned int deno2000:1;
	unsigned int deno5000:1;
	unsigned int deno2500:1;

	unsigned int uiDenoUnit:16;			//货币单位
}ST_DENO_INFO;


/************************************************** 状态定义 ***********************************************/
//定义系统当前运行状态，由业务层调用设置状态
typedef enum
{
	TVM_FREE		= 0,			//
	TVM_IN_TRANS	= 1,			//
	TVM_IN_FIRMWARE_TEST		= 2,       		//
	TVM_IN_CHANGE_TIC_BOX		= 3,	//更换钱票箱中
	TVM_IN_CHANGE_CASH_BOX      = 4,    //更换钱票箱中
	TVM_IN_ISSUE_FLUSH		= 5,	//票卡清空中
	TVM_IN_BILL_FLUSH		= 6,	//纸币清空中
	TVM_INITING         =7,	//初始化
	TVM_BALANCING     = 8,//结算中
	TVM_PARAM_DOWNLOADING  = 9, //SLE参数下载中
	TVM_SOFTWARE_DOWNLOADING  = 10, //SLE软件下载中
}EM_SLE_OPERATION_STATUS;


/************************************************* 状态定义end *********************************************/

//付费方式（仅业务层使用）： 0x01 现金； 0x02 储值卡支付； 0x03 银行卡支付； 0x04 代金卷支付； 0x05 其他；
typedef enum
{
	PAYMENT_METHOD_UNINIT = 0x00, 			/* 未初始化 */

	PAYMENT_METHOD_CASH = 0x01, 			/* 现金 */

	PAYMENT_METHOD_SV_CARD = 0x02, 			/* 储值卡支付 */

	PAYMENT_METHOD_BANK_CARD = 0x03, 		/* 银行卡支付 */

	PAYMENT_METHOD_NFC = 0x04, 				/* NFC支付 */

	PAYMENT_WEB = 0x05, 					/* 网络预付 */

	PAYMENT_METHOD_VOUCHER = 0x06, 			/* 代金卷支付 */

	PAYMENT_METHOD_OTHER = 0x07, 			/* 其他第三方支付 */

	PAYMENT_METHOD_QRCODE = 0x08, 			/* 二维码支付 */

	PAYMENT_METHOD_DEBIT_CARD = 0x09, 		/* 借记银行卡支付 */

	PAYMENT_METHOD_BLUE_CARD = 0x0A,	 	/* 信用卡支付 */

}EM_PAYMENT_METHOD;


/*支付子方式: 支付通道 */
typedef enum
{
	EM_PAYMENT_SUB_METHOD_WECHAT = 1,    //微信
	EM_PAYMENT_SUB_METHOD_ALIPAY = 2,    //支付宝
}EM_PAYMENT_SUB_METHOD;



//定义APP层LOKI配置ID配置，即在map<std::string, IAfcApp*> m_pcAppMap中充当KEY角色
#define TVM_PAY_CHANGE_APP_KEY    (string)"ITvmPaymentAndChangeApp"    //支付找零APPkey
#define TVM_TICKET_HANDLER_APP_KEY    (string)"ITvmTicketHandlerApp"    //票卡处理APPkey
#define SLE_DATA_APP_KEY    (string)"ISleDataApp"    //数据处理APPkey
#define TVM_UI_APP_KEY    (string)"ITvmPassengerUiApp"    //UI处理APPkey
#define SLE_ENVIRONMENT_APP_KEY    (string)"ISleEnvironmentApp"    //Sle环境APPkey
#define SLE_STATE_APP_KEY    (string)"ISleStateApp"    //Sle状态APPkey
#define AG_TICKET_HANDLER_APP_KEY    (string)"IAgTicketHandlerApp"    //AG票卡处理APPkey
#define AG_GATE_APP_KEY    (string)"IAgGateApp"    //AG通道APPkey
#define AG_UI_APP_KEY    (string)"IAgUiApp"    //UI处理APPkey
#define SLE_PROJECT_APP_KEY    (string)"ISleProjectApp"    //项目化APPkey
#define SLE_BIZ_DATA_GEN_APP_KEY (string) "ISleBizDataGenApp"//业务数据存储APP


//定义状态APP计算因子集合类别
typedef enum
{
	EM_STATE_APP_CALCULATE_FACTOR_SYSTEM_YPF_SET = 1,    //状态APP计算因子系统集合
	EM_STATE_APP_CALCULATE_FACTOR_VEND_YPF_SET,          //状态APP计算因子售票集合
	EM_STATE_APP_CALCULATE_FACTOR_CHARGE_YPF_SET,        //状态APP计算因子充值集合
	EM_STATE_APP_CALCULATE_FACTOR_VEND_COMPOUND_SET,     //状态APP计算因子售票混合集合
	EM_STATE_APP_CALCULATE_FACTOR_CHARGE_COMPOUND_SET,   //状态APP计算因子充值混合集合
}EM_STATE_APP_CALCULATE_FACTOR_SET_TYPE;
/*************************************** APP层定义 end******************************************/

//2014-09-18---wangyzh
/*************************************FirmWare层定义*********************************************/
//定义Firmare层LOKI配置ID配置，即在map<std::string,IDeviceCommonFunction*> m_pcFirmWareMap中充当KEY角色
#define STR_SYSTEM      		  (std::string)"sle_system"   	 //系统模块
#define STR_BANKNOTE_CHANGER      (std::string)"BillDispenser"   //纸币找零
#define STR_BANKNOTE_ACCEPTER     (std::string)"BillIdentify"    //纸币识别
#define STR_COIN_CHANGER          (std::string)"CoinDispenser"   //硬币找零
#define STR_COIN_ACCEPTER         (std::string)"CoinIdentify"    //硬币识别
#define STR_VALUE_CARD            (std::string)"ValueCard"       //充值卡支付
#define STR_BANK_CARD             (std::string)"BankCard"        //银行卡支付

#define STR_WEB_CARD              (std::string)"WebCard"         //网络支付
#define STR_NFC_CARD              (std::string)"NfcCard"         //nfc支付
#define STR_VOUCHER_CARD          (std::string)"VoucherCard"     //代金券支付
#define STR_OTHER                 (std::string)"Other"           //其他支付方式
#define STR_TPU_RECHARGE          (std::string)"TvmRechargeTpu"  //TvmTpu充值
#define STR_TPU_VENDING			  (std::string)"TvmVendingTpu"	 //TvmTpu交易,若只有一个TPU，该TPU有效
#define STR_TICKET_ISSUE          (std::string)"TicketIssue"     //车票发行
#define STR_TVM_DIO               (std::string)"TvmDio"          //TvmDio，模块
#define STR_TVM_UPS               (std::string)"TvmUps"          //TvmUps，模块
#define STR_TVM_PRINT_OPERATOR    (std::string)"TvmPrintOperator"//维修打印机
#define STR_TVM_PRINT_PASSENGER   (std::string)"TvmPrintPassenger"//乘客打印机
#define STR_TVM_LED_DOUBLE        (std::string)"TvmLedDouble"     //LED显示屏
#define STR_TVM_OPERBORAD         (std::string)"TvmOperboard"     //Tvm维修面板

#define STR_AG_GATE               (std::string)"AgGate"          //AG阻挡装置模块
#define STR_AG_DIO                (std::string)"AgDio"           //AG DIO模块
#define STR_AG_TRU                (std::string)"AgTru"           //AG 车票回收模块
#define STR_AG_ENTRY_TPU          (std::string)"AgEntryTpu"      //AG 进站TPU
#define STR_AG_EXIT_WD_TPU        (std::string)"AgExitWdTpu"     //AG 出站回收TPU
#define STR_AG_EXIT_UNWD_TPU      (std::string)"AgExitUnwdTpu"   //AG 出站刷卡TPU
#define STR_AG_UPS                (std::string)"AgUps"   		 //AG 出站刷卡TPU

#define STR_BOM_DESK_TPU		  (std::string)"BomDeskTpu"		 // Bom桌面Tpu
#define STR_BOM_ISSUE_TPU		  (std::string)"BomIssueTpu"	 // Bom发行Tpu
#define STR_TCM_TPU				  (std::string)"TcmTpu"			 // TCM的TPU

#define STR_RFID_READER1		  (std::string)"RfidReader1"	 //设备单独的RFID，1#
#define STR_RFID_READER2		  (std::string)"RfidReader2"	 //设备单独的RFID，2#
#define STR_RFID_READER3		  (std::string)"RfidReader3"	 //设备单独的RFID，3#

#define STR_MOBILE_SCAN		  	  (std::string)"TvmMobileScan"	 //手机扫描

/*************************************FirmWare层定义 end*********************************************/


/*
 * 系统故障代码信息定义,用于状态应用，UI应用以及业务层
 * wangzp
 */
typedef struct _ST_SYSTEM_ERROR_CODE_INFO
{
	ST_DEVICE_ERROR_CODE stDeviceErrorCode;
	EM_STATUS_SOURCE emSleBizType;     //生成故障码的来源
	DWORD dwErrorCodeGenerateTime;    //故障代码产生时间日期和时间以&分隔，例如20140919&120001
	DWORD dwErrorCodeClearTime;       //故障代码消除时间日期和时间以&分隔
} ST_SYSTEM_ERROR_CODE_INFO;

/*登录登出附加数据结构体*/
typedef struct
{
	char	szOperatorId[9];		//操作员ID
	char	szPwdId[32];			//操作员密码
	char	szShiftID[2];			/*操作员班次号: mayl add 2012-4-25*/
}ST_LOGIN_REQUEST_INFO;

//登录验证结果
typedef enum _EM_LOGIN_VERIFY_RESULT_
{
	EM_LOGIN_VERIFY_SUCCESS = 0x00,	//登录验证成功
	EM_REPEAT_LOGIN = 0x01,			//重复登录
	EM_LOGIN_VERIFY_FAIL = 0x02, //登录失败
}EM_LOGIN_VERIFY_RESULT;

//操作员登录登出类型
typedef enum _EM_OPERATOR_NOTIFY_TYPE_
{
	EM_OPERATOR_LOGIN = 0x00,							//操作员登录
	EM_OPERATOR_LOGOUT = 0x01,							//操作员登出
}EM_OPERATOR_NOTIFY_TYPE;

/*事件记录结构体*/
typedef struct
{
	unsigned int uiEventSeq;		//AFC事件序号
	unsigned char szDeviceID[8]; 	//设备ID
	EM_SLE_EVENT_TYPE emEventType;	//事件类型ID
	char szOperatorCode[20];		//操作员代码，字符串类型， 例如： 15411001, 没有填'/0'
	char szRunDate[9];				//运营日期， 有效长度8位字符的字符串， 如：20141119
	char szBusiDate[9];				//业务日期， 有效长度8位字符的字符串， 如：20141119
	char szBusiTime[7];				//业务时间， 有效长度8位字符的字符串， 如：154134
	BYTE szEventParam[64];			//事件参数
	int iEventParamLength;			//事件参数的有效长度
	BYTE szEventProjectData[1024];	//报给SC的项目化数据
	int iEventProjectDataLength;	//项目化数据的有效长度
}ST_EVENT_RECORD;


/* 参数版本类型 */
typedef enum
{
	/* 当前版本 */
	EM_SLE_PARAM_VERSION_TYPE_CURRENT = 0,

	/* 将来版本 */
	EM_SLE_PARAM_VERSION_TYPE_FUTURE  = 1

}EM_SLE_PARAM_VERSION_TYPE;


/* 单个参数版本信息结构 */
typedef struct _ST_SLE_SINGLE_PARAM_VERSION_INFO_
{
	/* 参数ID信息(参数类型) */
	char szParamType[10];

	/* 参数主版本信息，如：主控版本信息 */
	char szParamMainVersion[20];

	/* 参数子版本信息，如：参数组件版本信息 */
	char szParamSubVersion[20];

	/* 参数实际版本，如：DL TPU的版本，在参数同步过程中为日期时间格式，而读卡器内部实际版本则为： V001.001.006，实际存储时，可以保存为数字106，也可以直接保存V001.001.006。在参数同步模块存储更新库表时，根据项目实际情况进行同步即可 */
	char szParamRealVersion[20];

	/* 参数文件名称 */
	char szParamFileName[50];

	/* 参数文件存储路径 */
	char szParamFilePath[50];

	/* 参数生效方式，从数据表 Param_Effective_Type 中获取 */
	int iEffectiveMode;

	/* 是否TPU使用，从数据表 Param_Effective_Type 中获取 */
	int iIsTpuUsed;

	/* 参数描述，从数据表Param_Effective_Type 中获取，如： 票型参数等 */
	char szParamDesc[50];

	/* 生效日期，8byte，如：20120619表示2012年06月19日 */
	char effectiveDate[10];

	/* 生效时间：6byte, 如：153215表示15点32分15秒 */
	char effectiveTime[8];

	/* 生效时间：将时间转换为数字：如1970年开始的秒数 */
	unsigned int effectiveTimeT;

	int iTpuParamType;	//区分TPU 参数(1) 和 软件(2)
	/* 预留 */
	char szReverse[20];


}ST_SLE_SINGLE_PARAM_VERSION_INFO;


/* 最大参数个数 */
const int MAX_SLE_PARAM_COUNT = 100;
typedef struct _ST_SLE_PARAM_VERSION_INFO_
{
	/* 参数版本类型 */
	EM_SLE_PARAM_VERSION_TYPE emParamVersionType;

	/*参数个数*/
	int iParamCount;

	/* 参数版本信息 数组 */
	ST_SLE_SINGLE_PARAM_VERSION_INFO arSingleParamVersion[MAX_SLE_PARAM_COUNT];

}ST_SLE_PARAM_VERSION_INFO;




/* 设备模式 */
typedef struct _ST_COMMON_RUN_MODE
{
	DWORD Train_disruption_mode        	:1;		//0：列车故障模式  1
	DWORD Entry_order_override_mode    	:1;    //1：进站次序免检模式 2
	DWORD Date_override_mode          	:1;    //2：日期免检模式  4
	DWORD Time_override_mode          	:1;    //3：时间免检模式  8
	DWORD Under_fare_override_mode 	    :1;    //4：费用免检模式  16
	DWORD Emergency_mode          		:1;    //5：紧急模式     32
	DWORD Entry_override_mode    		:1;    //1：进站免检模式  64
	DWORD Exit_override_mode    		:1;    //1：出站免检模式  128
	DWORD Exit_order_override_mode      :1;		//出站次序免检模式 256
	DWORD reserve_mode2          		:1;		//预留模式2
	DWORD reserve_mode3          		:1;		//预留模式3
	DWORD           					:21;

} ST_COMMON_RUN_MODE;

/*维修部件测试项*/
typedef enum _EM_MANITAIN_DEVICE_TEST_
{
	EM_MANITAIN_PLAY_TEST = 0x01,					//播放测试
	EM_MAINTAIN_CONNECT_TEST = 0x02,				//连接测试
	EM_MAINTAIN_INIT_TEST = 0x03,					//初始化测试
	EM_MAINTAIN_ERROR_RESET_TEST = 0x04,			//错误重置测试
	EM_MAINTAIN_STATUS_REQUEST_TEST = 0x05,			//状态请求测试
	EM_MAINTAIN_PASS_INDICATE_TEST = 0x06, 			//通行指示测试
	EM_MAINTAIN_LAMPLIGHT_TEST = 0x07,				//灯光测试
	EM_MAINTAIN_PASSAGEWAY_MODE_TEST = 0x08,		//通道模式测试
	EM_MAINTAIN_GO_THROUGH_TEST = 0x09,				//通行测试
	EM_MAINTAIN_TICKET_RECYCLE_TEST = 0x10,			//车票回收测试
	EM_MAINTAIN_CASH_BOX_UNLOCK_TEST = 0x11,		//钱箱开锁测试
	EM_MAINTAIN_TICKET_BOX_UNLOCK_TEST = 0x12,		//票箱开锁测试
	EM_MAINTAIN_CASH_BOX_RFID_TEST = 0x13,			//钱箱RFID测试
	EM_MAINTAIN_TICKET_BOX_RFID_TEST = 0x14,		//票箱RFID测试
	EM_MAINTAIN_VIEMING_SCREEN_TEST = 0x15,			//显示屏测试
	EM_MAINTAIN_CASH_PAYMENT_TEST = 0x16,			//现金支付测试
	EM_MAINTAIN_CASH_CHANGE_TEST = 0x17, 			//现金找零测试
	EM_MAINTAIN_PRINTER_TEST = 0x18,				//打印机测试
	EM_MAINTAIN_TICKET_ISSUE_TEST = 0x19,			//车票发行测试
	EM_MAINTAIN_ELECTROMOTOR_TEST = 0x20,			//电机测试
	EM_MAINTAIN_ELECTROMAGNET_TEST = 0x21,			//电磁铁测试
	EM_MAINTAIN_CON_READ_SENSOR_TEST = 0x22,		//连续读传感器测试
	EM_MAINTAIN_TRU_CON_RECYCLE_TEST = 0x23,		//车票回收模块连续回收测试
	EM_MAINTAIN_TRU_CON_REFUND_TEST = 0x24,			//车票回收模块连续退票测试
	EM_MAINTAIN_TPU_CON_POLL_CARD_TEST = 0x25,		//TPU连续寻卡测试
	EM_MAINTAIN_TIU_CON_ISSUE_TICKET_TEST = 0x26,	//车票发行模块连续发行票卡测试
	EM_MAINTAIN_TIU_CON_RECYCLE_TEST = 0x27,		//车票发行模块连续回收票卡测试
	EM_MAINTAIN_CASH_CON_PRESS_IN_BOX_TEST = 0x28,	//现金模块连续投币压箱测试
	EM_MAINTAIN_CASH_CON_REFUND_TEST = 0x29,		//现金模块连续投币退还测试
	EM_MAINTAIN_CASH_CON_CHANGE_TEST = 0x30,		//现金模块连续找零测试
	EM_MAINTAIN_GCU_CON_GO_THROUGH_TEST = 0x31,		//门模块连续通行测试
	EM_MAINTAIN_CON_ELECTROMOTOR_TEST = 0x32,		//连续电机测试
	EM_MAINTAIN_CON_ELECTROMAGNET_TEST = 0x33,		//连续电磁铁测试
	EM_MAINTAIN_LOOP_TEST_FINISH = 0x34,			//连续测试结束
	EM_MAINTAIN_TPU_PARAM_VERSION_REQUEST = 0x35,	//TPU参数版本查询
	EM_MAINTAIN_TPU_PARAM_DOWNLOAD = 0x36,			//TPU参数下载
	EM_MAINTAIN_TPU_SOFTWARE_DOWNLOAD = 0x37,		//TPU软件下载
	EM_MAINTAIN_TPU_AUTO_COMPARE_UPDATE = 0x38,		//TPU自动比对升级(一键升级)
	EM_MAINTAIN_TPU_LOOP_AUTO_COMPARE_UPDATE = 0x39,//TPU连续自动升级(实时反映当前升级状态,避免一键升级的界面持续画圈,类似卡死现象)
	EM_MAINTAIN_UNIT_SOFTWARE_UPDATE = 0x40,		//部件软件升级
	EM_MAINTAIN_GCU_DOOR_STEP_CONTROL_TEST = 0x41,	//门单元门模块单步控制测试
	EM_MAINTAIN_CASH_BOX_RFID_RW = 0x42,			//钱箱RFID读写
	EM_MAINTAIN_TICKET_BOX_RFID_RW = 0x43,			//票箱RFID读写
}EM_MANITAIN_DEVICE_TEST;

#include "CashAndTicketContainer.h"
#include "AfcTpuPublic.h"
#include "MaintainTestPublicDef.h"

/*
 * 清空状态枚举
 * wangzp
 * 20150401
 */
typedef enum
{
	EM_FLUSHING = 1,//清空/回收中
	EM_FLUSHED = 2,//清空/回收完成
	EM_FLUSHED_FAULT = 3,//清空/回收失败
	EM_SOME_TICKET_FLUSHED = 4,	//部分车票清空完成(用于处理类似郑州项目部分票卡清空完成(如清空通道内车票或指定数目车票)库存却全部归0的问题)
}EM_FLUSH_STATUS;

/*
 * 补充状态枚举
 * wangzp
 * 20150401
 */
typedef enum
{
	EM_SUPPLYING = 1,
	EM_SUPPLYED = 2,
}EM_SUPPLY_STATUS;

/*
 * 钱清空数据记录集，同样适用于补充
 * wangzp
 * 20150401
 */
typedef struct
{
	ST_CASH_CONTAINER_LOCATION stCashContainerLocation;
	int iDenomination;    //清空面额，单位：分
	int iFlushCount;      //清空数量
}ST_CASH_FLUSH_DATA_RECORD;

/*
 * Token清空数据记录集
 * wangzp
 * 20150401
 */
typedef struct
{
	ST_TICKET_CONTAINER_LOCATION stTicContainerLocation;
	int iFlushCount;      //清空数量
}ST_TOKEN_FLUSH_DATA_RECORD;
/*
 * 钱清空数据数据
 */
typedef struct _ST_CASH_FLUSH_PARAM_
{
	ST_CASH_CONTAINER_LOCATION stOutCashbox;	//清出的钱箱
	ST_CASH_CONTAINER_LOCATION stInCashbox;		//收入的钱箱
	int iCount;									//清出的数量
	int iDeno;									//币种
}ST_CASH_FLUSH_PARAM;
/*
 * 票清空数据数据
 */
typedef struct _ST_TICKET_FLUSH_PARAM_
{
	ST_TICKET_CONTAINER_LOCATION stOutTicketbox;	//清出的票箱 hopper
	ST_TICKET_CONTAINER_LOCATION stInTicketbox;		//收入的票箱
	int iCount;									//清出的数量
}ST_TICKET_FLUSH_PARAM;
//版本信息
typedef struct _ST_CSS_VERSION_INFO_
{
	EM_SLE_UNIT_TYPE emUnitType;		// 部件类型
	EM_CSS_VERSION_TYPE emVersionType;	//版本类型
	char szMainVersion[40];				//版本
	char szReleaseTime[20];				//发布日期时间,没有填充0x00
}ST_CSS_VERSION_INFO;


typedef struct _ST_TVM_HELP_INFO_
{
	bool bFireOrCancel;	//true 触发求助; false 取消求助
	int iHelpStatus;	//1. 卡币； 2. 找零失败；   3：不满足找零条件而没有找零；  0：其他
	char szHelpTime[15];	//发生时间
}ST_TVM_HELP_INFO;

typedef struct _ST_PRINT_VOUCHER_INFO_
{
	DWORD uiUdsn;			//票据UDSN
	bool bForPassenger;		//true: 乘客；false:操作员
	DWORD uiVoucherType;	//票据类型，项目定义枚举值
	char szTypeName[50];	//票据类型,用于显示
	int iTemplateId;		//打印格式模板ID
	//操作员代码，字符串类型， 例如： 15411001, 没有填'/0'
	char szOperatorCode[20];

	//运营日期， 有效长度8位字符的字符串， 如：20141119
	char szRunDate[9];

	//业务日期， 有效长度8位字符的字符串， 如：20141119
	char szBusiDate[9];

	//业务时间， 有效长度8位字符的字符串， 如：154134
	char szBusiTime[7];

}ST_PRINT_VOUCHER_INFO;

typedef enum
{
	EM_BALANCE_DATA_CAL_SETTLEMENT    = 1,    //结帐：收益
	EM_BALANCE_DATA_CAL_BALANCE    = 2,    //结存
}EM_BALANCE_DATA_CAL_TYPE;

typedef enum
{
	EM_SETTLEMENT_TRIGGERTYPE_OPERATOR    = 1,    //操作员结帐
	EM_SETTLEMENT_TRIGGERTYPE_RUN_END    = 2,    //运营结束
	EM_SETTLEMENT_TRIGGERTYPE_SWITCH_RUN_DATE      = 3,    //切换运营日结算
}EM_SETTLEMENT_TRIGGERTYPE_DEF;

typedef enum
{
	EM_REFUND_CASH_TYPE_NONE   = 0,	//没有退币动作
	EM_REFUND_CASH_TYPE_OK	= 1,	//退币成功
	EM_REFUND_CASH_TYPE_FAIL = 2,	//退币失败
}EM_REFUND_CASH_TYPE;

typedef struct _ST_TVM_PASSENGER_TRANS_
{
	DWORD uiTransID;	//交易流水号
	EM_SLE_TRANSACATION_TYPE emTransType;	/*交易（业务）类型 */
	char szBeginDate[9];//交易开始日期,如：20141119
	char szBeginTime[7];//交易开始时间,如：154134
	char szEndDate[9];//交易结束日期,如：20141119
	char szEndTime[7];//交易结束时间,如：154134
	DWORD dwDesStationID;	//目的车站ID	//0表示无效
	DWORD uiTicketType;		//车票类型
	WORD usTicketSubType;	//Byte 0-1: 车票子类型，默认值：0
	BYTE ucLevel;			//Byte 2:舱位等级，默认值：0
	BYTE ucPassengerType;	//Byte 3:乘客类型
	BYTE ucCardType;		//Byte 1:卡片类型
	EM_PAYMENT_METHOD emPaymentMethod;	//付费方式
	int iCountFromPassenger;	//乘客选择交易数量，对于充值交易为1
	int iUnitPrice;				//单价
	int iTotalPrice;			//应付金额 = iCountFromPassenger*iUnitPrice
	int iPaymentAmount;			//已付金额
	int iTransCount;			//实际交易数量, 对于充值交易为1或者0
	int iTransAmount;			//实际交易金额 = iTransCount*iUnitPrice
	int iChangeAmount;			//实际找零金额
	int iTransBalance;			//交易结算 = iPaymentAmount-iTransAmount-iChangeAmount； 等于0正常；大于0为少找零；小于0为多找零
	int iOutFailCount;			//仅对售票有效,写票成功，但出票失败数量
	int iPaymentBill;			//应退币纸币金额
	EM_REFUND_CASH_TYPE emReturnBill;			//纸币退币结果
	int iPaymentCoin;			//应退币硬币金额
	EM_REFUND_CASH_TYPE emReturnCoin;			//硬币退币结果
	bool bPrintVoucher;			//是否为乘客打印了凭据

	//add by limg at 20170307: 以下三个字段用于 手机支付
	EM_PAYMENT_SUB_METHOD emPaySubMethod;    //支付子方式(支付通道)
	char szOrderNo[100];     /* 订单号 */
	char szOrderToken[1024]; /* 令牌信息 */


}ST_TVM_PASSENGER_TRANS;


typedef struct _ST_OPERATION_LOG_
{	 char szOperatorId[32];
	 int  iOperResult;
	 int  iOperLevel;
	 int  iOperCode;
	 char szKey1[32];
	 char szKey2[32];
	 char szRemark[64];
}ST_OPERATION_LOG;



typedef struct _ST_AG_PASSENGER_TRANS_
{
	EM_SLE_TRANSACATION_TYPE emTransType;	/*交易（业务）类型 */
	ST_TPU_TRANS_RESULT stTransResult;
	ST_TICKET_CONTAINER_LOCATION stWithdrawTicketbox;	//回收票箱或者乘客
}ST_AG_PASSENGER_TRANS;

/* 数据存储模块-系统基础数据 */
typedef struct _ST_SLE_DATA_SYS_BASIC_INFO_
{
	/* 车站编码，比如： 0115 , 表示 01 号线、15车站*/
	char szStationCode[5];

	/* 设备编码，比如： 01151801 , 表示 01 号线、15车站 BOM 01号机*/
	char szDeviceCode[17];

	EM_SLE_DEVICE_TYPE emDeviceType;



}ST_SLE_DATA_SYS_BASIC_INFO;


/*业务数据结构体*/
typedef struct _ST_BIZ_DATA_RECORD_
{
	/* */
	unsigned int uiBusiType;

	/* */
	char szBusiTypeCN[50];

	/* 操作员代码，字符串类型， 例如： 15411001, 没有填'/0' */
	char szOperatorCode[20];

	/* 运营日期， 有效长度8位字符的字符串， 如：20141119 */
	char szRunDate[9];

	/* 业务日期， 有效长度8位字符的字符串， 如：20141119 */
	char szBusiDate[9];

	/* 业务时间， 有效长度8位字符的字符串， 如：154134 */
	char szBusiTime[7];

	/* 数据流水号 */
	unsigned int uiDataSeq;

	/* 数据类型 */
	unsigned int uiDataType;

	/* 数据子类型 */
	unsigned int uiDataSubType;

	/* 公共流水号 */
	unsigned int uiBusiPubSN;

	/* 测试标记 */
	unsigned int uiTestFlag;

	/* 产品化平台数据长度 */
	unsigned int uiCssProductDataLength;

	/* 产品化平台数据 */
	char szCssProductDataContent[256];

	/* 项目化数据长度 */
	unsigned int uiProjectDataLength;

	/* 项目化数据内容 */
	char szProjectDataContent[1024];


}ST_BIZ_DATA_RECORD;

//充值或查询卡座方式
typedef enum
{
	EM_SVTCARD_HOLDER_TYPE_INSERT = 1,			//插卡方式
	EM_SVTCARD_HOLDER_TYPE_POLLING = 2,			//寻卡方式
	EM_SVTCARD_HOLDER_TYPE_SWALLOW = 3,			//吞卡方式

}EM_SVTCARD_HOLDER_TYPE;

//wangyzh20150618添加打印配置选项
//打印配置选项
typedef enum
{
	EM_PRINT_CFG_TYPE_PRINT = 0,				//0:无条件打印(显示充值无打印是否继续充值)
	EM_PRINT_CFG_TYPE_NO_PRINT = 1,				//1:无条件不打印()
	EM_PRINT_CFG_TYPE_NOTIFY_PASSENGER_SEL = 2,	//2:充值完成后显示乘客选择打印界面(显示充值无打印是否继续充值)
	EM_PRINT_CFG_TYPE_RECHARGE_REQUEST_SEL = 3,	//3:充值前让乘客选择打印(充值请求时选择)
	EM_PRINT_CFG_TYPE_CONFIRM_SEL = 4,			//4:充值前让乘客选择打印（显示充值无打印是否继续充值)
}EM_PRINT_CFG_TYPE;

//充值参数
typedef enum _EM_RECHARGE_CONTROL_PARAM_
{
	EM_NORMAL_RECHARGE = 0,
	EM_FLASH_CARD_RECHARGE_CONFIRM = 1,
	EM_FLASH_CARD_RECHARGE_CANCEL = 2,
}EM_RECHARGE_CONTROL_PARAM;

//结算更换箱子信息(专用于更换中的异常操作,比如结算中发生非法更换或是在未按提示顺序卸下箱子等)
typedef struct _ST_BALANCE_BOX_INFO_
{
	bool bCoinSpareBoxOne;
	bool bCoinSpareBoxTwo;
	bool bCoinWdBox1;
	bool bCoinWdBox2;
	bool bBillCashWdBox;
	bool bBillSpareOneBox;
	bool bBillSpareTwoBox;
	bool bBillWasteBox;
	bool bTicketBox1;
	bool bTicketBox2;
	bool bTicketWdBox1;
	bool bTicketWdBox2;
	bool bTicketWasteBox;
	bool bBillSupplyBoxOne;
	bool bBillSupplyBoxTwo;
}ST_BALANCE_BOX_INFO;

/**
 TVM故障交易(6204)
*/
typedef struct _ST_TVM_FAULT_DATA_
{

  /**故障单ID*/
  int iFaultCertificateID;
  /**对应交易流水号*/
  int iUDSN;
  /**应退款金额*/
  int iRefundValue;
  /**故障原因*/
  int iFaultReason;

}ST_TVM_FAULT_DATA;


#endif /* AFCPUBLIC_H_ */
