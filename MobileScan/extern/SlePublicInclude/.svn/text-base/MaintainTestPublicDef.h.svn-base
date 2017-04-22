/*
 * MaintainTestPublicDef.h
 *
 *  Created on: Mar 25, 2015
 *      Author: longjg
 */

#ifndef MAINTAINTESTPUBLICDEF_H_
#define MAINTAINTESTPUBLICDEF_H_

#define MAX_PARAM_NUM 10
#define MAX_PARAM_LENGTH 100

//参数有效性
typedef enum _EM_PARAM_EFFECTIVENESS_
{
	EM_PARAM_INVALID = 0x00,						//参数无效
	EM_PARAM_VALID = 0x01,							//参数有效
}EM_PARAM_EFFECTIVENESS;

//测试类型
typedef enum _EM_TEST_TYPE_
{
	EM_COMMON_TEST = 0x01,							//一般测试
	EM_CON_TEST_START = 0x02,						//连续测试开始
	EM_CON_TEST_END = 0x03,							//连续测试结束
}EM_TEST_TYPE;

//测试执行结果
typedef enum _EM_TEST_EXCUTE_RESULT_
{
	EM_COMMON_TEST_EXCUTE_SUCCESS = 0x01,			//一般测试执行成功
	EM_COMMON_TEST_EXCUTE_FAILURE = 0x02,			//一般测试执行失败
	EM_PROCESS_MSG_FAILURE = 0x03,					//进程间消息失败
	EM_GET_STATUS_FAILURE = 0x04,					//获取状态失败
	EM_TEST_PRODUCE_ABNORMAL = 0x05,				//测试出现异常情况
	EM_INPUT_IS_WRONG_PLEASE_TRY_AGAIN = 0x06, 		//输入有误请重新输入
	EM_CON_TEST_IN_PROGRESS = 0x07,					//连续测试正在执行
	EM_CON_TEST_EXCUTE_FINISH = 0x08,				//连续测试执行成功
	EM_CON_TEST_EXCUTE_FAILURE = 0x09,				//连续测试执行失败
}EM_TEST_EXCUTE_RESULT;

//特殊返回值是否有效
typedef enum _EM_SPECIAL_RETURN_EFFECTIVENESS_
{
	EM_SPECIAL_RETURN_INVALID = 0x00,				//特殊返回值无效
	EM_SPECIAL_RETURN_VALID = 0x01,					//特殊返回值有效
}EM_SPECIAL_RETURN_EFFECTIVENESS;

//部件测试发起数据
typedef struct _ST_TEST_REQUEST_MSG_
{
	EM_SLE_UNIT_TYPE emSleUnitType;					//测试部件ID枚举值
	EM_MANITAIN_DEVICE_TEST emMaintainDeviceTest;	//功能码枚举值
	EM_PARAM_EFFECTIVENESS emParamEffectiveness;	//参数有效性
	EM_TEST_TYPE emTestType;						//测试类型
}ST_TEST_REQUEST_MSG;

//IPC维修测试中多个char*类型作为入参时的应用
typedef struct _ST_FUNC_PARAM_INFO_
{
	char szParam[MAX_PARAM_LENGTH];
	unsigned int uiParamRealLength;
}ST_FUNC_PARAM_INFO;

//IPC维修测试中多个char*类型作为入参时的应用
typedef struct _ST_FUNC_INPUT_PARAM_
{
	unsigned int uiRealInputParamNum;						//实际入参数目
	ST_FUNC_PARAM_INFO stFuncParamInfo[MAX_PARAM_NUM];		//入参结构信息
}ST_FUNC_INPUT_PARAM;

//维修测试软件升级入参结构信息(预留以后可能应用)
typedef struct _ST_SOFTWARE_UPDATE_INPUT_PARAM_
{
	char szPortName[MAX_PARAM_LENGTH];						//端口号
	int iBaud;												//波特率
	int iDataBits;											//数据位
	char cParity;											//校验方式
	int iStopBits;											//停止位
	char szFileName[MAX_PARAM_LENGTH];						//固件软件存放文件路径
	int iBlockSize;											//每帧数据大小
}ST_SOFTWARE_UPDATE_INPUT_PARAM;

//部件测试反馈数据
typedef struct _ST_TEST_FEEDBACK_MSG_
{
	EM_SLE_UNIT_TYPE emSleUnitType;					//测试部件ID枚举值
	EM_MANITAIN_DEVICE_TEST emMaintainDeviceTest;	//功能码枚举值
	EM_TEST_EXCUTE_RESULT emTestExcuteResult;		//测试执行结果
	EM_SPECIAL_RETURN_EFFECTIVENESS emReturnEffect;	//特殊返回值是否有效
}ST_TEST_FEEDBACK_MSG;

//播放设备枚举类型
typedef enum _EM_PALY_DEVICE_TYPE_
{
	EM_PLAY_VOICE_BOX = 0x01,						//播放音箱
	EM_PLAY_BUZZER = 0x02,							//播放蜂鸣器
}EM_PALY_DEVICE_TYPE;

//连接枚举类型
typedef enum _EM_CONNECT_TYPE_
{
	EM_SERIAL_PORT_CONNECT = 0x01,					//串口连接
	EM_SC_TO_TCP_CONNECT = 0x02,					//SC TCP通信连接
	EM_SC_TO_FTP_CONNECT = 0x03,					//SC FTP通信连接
	EM_YKT_SERVER_CONNECT = 0x04,					//一卡通服务器通信连接
	EM_ONLINE_PAYMENT_CONNECT = 0x05,				//在线支付服务器通信连接
}EM_CONNECT_TYPE;

//通行指示部件类型
typedef enum _EM_PASS_INDICATE_DEVICE_TYPE_
{
	EM_PASSAGEWAY_INDICATE = 0x01,					//通道指示
	EM_CEILING_WIZARD = 0x02,						//顶棚向导
}EM_PASS_INDICATE_DEVICE_TYPE;

//通行方式
typedef enum _EM_GO_THROUGH_WAY_
{
	EM_ALL_ALLOW_GO_THROUGH = 0x01,					//全部允许通行
	EM_ONLY_ALLOW_GET_IN = 0x02,					//只进站允许
	EM_FORBID_GET_IN = 0x03,						//进站禁止通行
	EM_ONLY_ALLOW_COME_OUT = 0x04,					//只出站允许
	EM_FORBID_COME_OUT = 0x05,						//出站禁止
	EM_ALL_FORBID_GO_THROUGH = 0x06,				//全部禁止通行
}EM_GO_THROUGH_WAY;

//灯光类型
typedef enum _EM_LAMPLIGHT_TYPE_
{
	EM_DEVICE_ALL_LAMPLIGHT = 0x00,						//设备所有灯光
	EM_AG_SWIPING_CARD_INDICATE_LAMP = 0x01,			//AG刷卡指示灯
	EM_AG_INSERT_TICKET_INDICATE_LAMP = 0x02,			//AG投票指示灯
	EM_AG_TOPLIGHT = 0x03,								//AG顶灯
	EM_AG_REFUND_TICKET_INDICATE_LAMP = 0x04,			//AG退票指示灯
	EM_AG_CHECK_LAMP = 0x05,							//AG稽查灯
	EM_AG_LAMP_RESERVED = 0x06,							//AG预留灯
	EM_TVM_BILL_PAYMENT_INDICATE_LAMP = 0x07,			//TVM纸币支付指示灯
	EM_TVM_COIN_PAYMENT_INDICATE_LAMP = 0x08,			//TVM硬币支付指示灯
	EM_TVM_SVT_PAYMENT_INDICATE_LAMP = 0x09,			//TVM储值卡支付指示灯
	EM_TVM_BANK_CARD_PAYMENT_INDICATE_LAMP = 0x0A,		//TVM银行卡支付指示灯
	EM_TVM_TDC_PAYMENT_INDICATE_LAMP = 0x0B,			//TVM二维码支付指示灯(TDC:TWO-DEMENSION-CODE)
	EM_TVM_NFC_PAYMENT_INDICATE_LAMP = 0x0C,			//TVM近距离通信支付(NFC:NEAR-FEILD-COMMUNICATION)
	EM_TVM_OTHER_PAYMENT_INDICATE_LAMP = 0x0D,			//TVM其他支付指示灯
	EM_TVM_SVT_STATUS_INDICATE_LAMP = 0x0E,				//TVM储值卡状态指示灯
	EM_TVM_PRINT_RECEIPT_INDICATE_LAMP = 0x0F,			//TVM打印屏条指示灯
	EM_TVM_GET_TICKET_INDICATE_LAMP = 0x10,				//TVM取票指示灯
	EM_TVM_GET_TICKET_LIGHTING = 0x11,					//TVM取票照明灯
	EM_TVM_BILL_CHANGE_INDICATE_LAMP = 0x12,			//TVM纸币找零指示灯
	EM_TVM_ALARM_LAMP = 0x13,							//TVM警报灯
	EM_TVM_FRONT_PANEL_LIGHTING = 0x14,					//TVM前面板照明灯
	EM_TVM_MAINTAIN_PANEL_INDICATE_LAMP = 0x15,			//维修面板指示灯
	EM_AG_GOTHROUGH_LAPM = 0x16,						//AG通行指示灯
	EM_AG_WARING_LAMP = 0x17,							//AG警报灯
}EM_LAMPLIGHT_TYPE;

//警报指示灯序号
typedef enum _EM_ALARM_LIGHT_TYPE_
{
	 EM_ENTRY_LIGHT = 0x01,								//进站灯
	 EM_EXIT_LIGHT = 0x02,								//出站灯
	 EM_BOTH_LIGHT = 0x03,								//所有灯
}EM_ALARM_LIGHT_TYPE;

//通行功能类型
typedef enum _EM_GO_THROUGH_FUNC_TYPE_
{
	EM_ENTRY_REALEASE_ONE = 0x01,						//进站放行一人
	EM_EXIT_REALEASE_ONE = 0x02,						//出站放行一人
}EM_GO_THROUGH_FUNC_TYPE;

//车票回收功能类型
typedef enum _EM_TRU_FUNC_TYPE_
{
	EM_OPEN_SHUTTER = 0x01,								//开启接收(打开舌档)
	EM_CLOSE_SHUTTER = 0x02,							//关闭接收(关闭接收)
	EM_RECEIVE_TICKET_TO_BOX = 0x03,					//回收
	EM_REFUND_TICKET = 0x04,							//退还
}EM_TRU_FUNC_TYPE;

//RFID操作类型
typedef enum _EM_RFID_OPERATE_TYPE_
{
	EM_READ_RFID = 0x01,								//读RFID
	EM_WRITE_RFID = 0x02,								//写RFID
}EM_RFID_OPERATE_TYPE;

//显示部件类型
typedef enum _EM_DISPLAY_PARTS_TYPE_
{
	EM_TVM_RUN_STATUS_DISPLAYER = 0x01,					//TVM运营状态显示器
	EM_TVM_PASSENGER_DISPLAYER = 0x02,					//TVM乘客显示器
	EM_TVM_MAINTAIN_DISPLAYER = 0x03,					//TVM维护显示器
	EM_AG_ENTRY_DISPLAYER = 0x04,						//AG进站显示器
	EM_AG_EXIT_DISPLAYER = 0x05,						//AG出站显示器
	EM_BOM_OPERATOR_DISPLAYER = 0x06,					//BOM操作员显示器
	EM_BOM_PAID_AREA_PASSENGER_DISPLAYER = 0x07,		//BOM付费区乘客显示器
	EM_BOM_UN_PAID_AREA_PASSENGER_DISPLAYER = 0x08,		//BOM非付费区乘客显示器
	EM_EQM_PASSENGER_DISPLAYER = 0x09,					//EQM乘客显示器
}EM_DISPLAY_PARTS_TYPE;

//现金支付功能类型
typedef enum _EM_CASH_PAYMENT_FUNC_TYPE_
{
	EM_OPEN_COIN_ELECTROMAGNET = 0x01,					//开启硬币电磁铁
	EM_CLOSE_COIN_ELECTROMAGNET = 0x02,					//关闭硬币电磁铁
	EM_OPEN_IDENTIFY = 0x03,							//开启识别
	EM_CLOSE_IDENTIFY = 0x04,							//关闭识别
	EM_RECEIVE_CASH_TO_BOX = 0x05,						//压钱入箱
	EM_REFUND_CASH = 0x06,								//退还现金
}EM_CASH_PAYMENT_FUNC_TYPE;

//打印机切纸操作
typedef enum _EM_PRINTER_CUT_PAPER_OPERAT_TYPE_
{
	EM_PRINTER_CUT_PAPER = 0x01,						//打印机切纸
	EM_PRINTER_NO_CUT_PAPER = 0x02,						//打印机不切纸
}EM_PRINTER_CUT_PAPER_OPERAT_TYPE;

//车票发行功能类型
typedef enum _EM_TIU_FUNC_TYPE_
{
	EM_ONLY_FETCH_TICKET = 0x01,						//单提票
	EM_PREFETCH_TICKET_AND_FETCH_TICKET = 0x02,			//预提票+提票
	EM_ONLY_PREFETCH_TICKET = 0x03,						//预提票
	EM_WITHDRAW_TICKET = 0x04,							//回收
	EM_WALKTHROUGH_TICKET = 0x05,						//预排票
	EM_EJECT_TICKET = 0x06,								//排票
}EM_TIU_FUNC_TYPE;

//硬件适配层单步测试参数1,测试项目类型
typedef enum _EM_STEP_TEST_ITEM_
{
	EM_ELCETROMOTOR_TEST = 0x01,						//电动机测试
	EM_ELECTROMAGNET_TEST = 0x02,						//电磁铁测试
	EM_BUZZER_TEST = 0x03,								//蜂鸣器测试
	EM_LAMPLIGHT_TEST = 0x04,							//灯光测试
}EM_STEP_TEST_ITEM;

//硬件适配层单步测试，灯光测试参数2(把灯光类型和灯光颜色封在一起)
typedef struct _ST_LAMPLIGHT_ACTION_TYPE_
{
	EM_LAMPLIGHT_TYPE emLamplightType;					//灯光类型
	unsigned char usLamplightColor;						//灯光颜色(1~7红绿黄蓝紫青白,只有灭亮的采用0,1)
}ST_LAMPLIGHT_ACTION_TYPE;

//电机动作类型
typedef enum _EM_ELCETROMOTOR_ACTION_TYPE_
{
	EM_ELCETROMOTOR_FORWARD = 0x01,						//电动机正转
	EM_ELCETROMOTOR_ROLLBACK = 0x02,					//电动机反转
	EM_FIRST_FORWARD_THEN_ROLLBACK = 0x03,				//电动机先正转再反转
}EM_ELCETROMOTOR_ACTION_TYPE;

//硬件适配层单步测试，电机测试参数2(把电机编号和动作封在一起)
typedef struct _ST_ELCETROMOTOR_ACTION_TYPE_
{
	unsigned int iElectromotorNo;						//电机编号
	EM_ELCETROMOTOR_ACTION_TYPE emActionType;			//电机动作类型
	unsigned int iActionTime;							//动作时间	单位：ms
}ST_ELCETROMOTOR_ACTION_TYPE;

typedef enum _EM_ELECTROMAGNET_TYPE_
{
	EM_ALL_ELECTROMAGNET = 0x00,						//所有电磁铁
	EM_COIN_SHUTTER_ELECTROMAGNET = 0x01,				//硬币舌档电磁铁
	EM_SVT_SHUTTER_ELECTROMAGNET = 0x02,				//储值卡舌档电磁铁
	EM_AG_SORT_SHUTTER_ELECTROMAGNET = 0x03,			//AG分拣舌档电磁铁
	EM_AG_VOTE_TICKET_SHUTTER_ELECTROMAGNET = 0x04,		//AG投票口舌档电磁铁
	EM_AG_RECYCLE_CABIN_ELECTROMAGNET = 0x05,			//AG回收舱电磁铁
	EM_AG_RECYCLE_REFUND_TICKET_ELECTROMAGNET = 0x06,	//AG回收退票电磁铁
	EM_AG_RECYCLE_SHUNT_ELECTROMAGNET = 0x07,			//AG回收分流电磁铁
}EM_ELECTROMAGNET_TYPE;

//电磁铁动作类型
typedef enum _EM_ELECTROMAGNET_ACTION_TYPE_
{
	EM_RECOVER_WORK_STATUS = 0x00,						//恢复测试前动作(正常工作时的状态)
	EM_ELECTROMAGNET_ATTRACT = 0x01,					//电磁铁吸合
	EM_ELECTROMAGNET_REALEASE = 0x02,					//电磁铁放开
	EM_FIRST_ATTRACT_THEN_REALEASE = 0x03,				//电磁铁先吸合再放开
}EM_ELECTROMAGNET_ACTION_TYPE;

//硬件适配层单步测试，电磁铁测试参数2(把电磁铁编号和动作封在一起)
typedef struct _ST_ELECTROMAGNET_ACTION_TYPE_
{
	EM_ELECTROMAGNET_TYPE emElectromagnetNo;			//电磁铁类型
	EM_ELECTROMAGNET_ACTION_TYPE emActionType;			//电磁铁动作类型
}ST_ELECTROMAGNET_ACTION_TYPE;

//寻卡操作类型
typedef enum _EM_POLLING_CARD_OPERAT_TYPE_
{
	EM_ONLY_A_ANTENNA_POLLING_CARD = 0x01,				//只有A天线寻卡
	EM_ONLY_B_ANTENNA_POLLING_CARD = 0x02,				//只有B天线寻卡
	EM_A_B_ANTENNA_POLLING_CARD = 0x03,					//A和B天线同时寻卡
	EM_ONLY_C_ANTENNA_POLLING_CARD = 0x04,				//只有C天线寻卡
	EM_A_C_ANTENNA_POLLING_CARD = 0x05,					//A和C天线同时寻卡
	EM_B_C_ANTENNA_POLLING_CARD = 0x06,					//B和C天线同时寻卡
	EM_A_B_C_ANTENNA_POLLING_CARD = 0x07,				//A和B和C天线同时寻卡
}EM_POLLING_CARD_OPERAT_TYPE;

//寻卡结果
typedef enum _EM_POLLED_CARD_RESULT_
{
	EM_NO_POLLED_CARD = 0x00,							//没有寻到卡
	EM_A_POLLED_CARD = 0x01,							//A天线寻到卡
	EM_B_POLLED_CARD = 0x02,							//B天线寻到卡
	EM_C_POLLED_CARD = 0x04,							//C天线寻到卡
}EM_POLLED_CARD_RESULT;

//连续通行方向
typedef enum _EM_CON_GO_THROUGH_DIRECTION_
{
	EM_CON_GO_THROUGH_ENTRY = 0x01,						//连续进站
	EM_CON_GO_THROUGH_EXIT = 0x02,						//连续出站
}EM_CON_GO_THROUGH_DIRECTION;

//现金模块暂存区
typedef struct _ST_CASH_BRIEFLY_STORAGE_AREA_
{
	unsigned int iBrieflyStorageNum;					//暂存区数量
	unsigned int iBrieflyStorageAmount;					//暂存区金额
	unsigned int iBrieflyStorageSumNum;					//总数量
	unsigned int iBrieflyStorageSumAmount;				//总金额
}ST_CASH_BRIEFLY_STORAGE_AREA;

//连续升级状态反馈
typedef struct _ST_LOOP_UPDATE_STATUS_FEEDBACK_
{
	char szParamId[MAX_PARAM_LENGTH];
	char szParamTypeCn[MAX_PARAM_LENGTH];
	char szDataBaseParamInfo[MAX_PARAM_LENGTH];
	char szTpuCurParamInfo[MAX_PARAM_LENGTH];
	char szIsNeedUpdate[MAX_PARAM_LENGTH];
	char szUpdateStatus[MAX_PARAM_LENGTH];
}ST_LOOP_UPDATE_STATUS_FEEDBACK;

//门单元单步打开关闭测试
typedef enum _EM_GCU_STEP_CONTROL_TYPE_
{
	EM_GCU_STEP_CONTROL_CLOSE = 0x00,					//门关闭
	EM_GCU_STEP_CONTROL_OPEN = 0x01,					//门打开
}EM_GCU_STEP_CONTROL_TYPE;

#endif /* MAINTAINTESTPUBLICDEF_H_ */
