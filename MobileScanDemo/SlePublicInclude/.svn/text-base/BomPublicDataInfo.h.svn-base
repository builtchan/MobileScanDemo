/*
 * 说明：仅支持未经压缩的WAV格式文件
 *       支持多线程并发调用
 * wugang 2013.05.22
 * */

#ifndef BOMPUBLICDATAINFO_H_
#define BOMPUBLICDATAINFO_H_

/********************************************************************************************/

//TPU 相关 错误码： 0x80020801 ~ 0x800209FF
#define TPU_ERROR_CODE_TPU_PROCESS_FAILED     					   0x00001000 /*TPU执行失败*/
#define TPU_ERROR_CODE_CARD_BEEN_BLOCKED_NEED_GET_UD               0x00001001 /*黑名单锁卡，需要获取UD*/
#define TPU_ERROR_CODE_CARD_EXPIRED                                0x00001002 /*卡片过期*/
#define TPU_ERROR_CODE_CARD_STATUS_ILLEGAL						   0x00001003 /*卡状态非法*/
#define TPU_ERROR_CODE_REMAINING_VALUE_LACK						   0x00001004 /*余额不足*/
#define TPU_ERROR_CODE_READ_CARD_FAILED                            0x00001005 /*读卡失败*/
#define TPU_ERROR_CODE_WRITE_CARD_FAILED                           0x00001006 /*读卡失败*/
#define TPU_ERROR_CODE_TPU_STATUS_ILLEGAL						   0x00001007 /*TPU状态非法*/
#define TPU_ERROR_CODE_POLL_CARD_FAILED						       0x00001010 /*寻卡类错误*/
#define TPU_NO_CARD										   		   0x00001014 /*无卡*/
#define TPU_ERROR_CODE_AGAIN_SWIPINGCARD				   		   0x00001015 /*需要重新刷卡*/
#define TPU_ERROR_CODE_M1_CARD_AUTH_ERROR  						   0x00001020 /*M1卡认证错误*/
#define TPU_ERROR_CODE_SAM_PROCESS_ERROR						   0x00001030 /*SAM卡处理公共类错误*/
#define TPU_ERROR_CODE_COMM_ERROR 								   0x00001040 /*通讯接口类错误*/
#define TPU_ERROR_CODE_BUSI1_PROCESS_ERROR                         0x00001050 /*一票通业务处理类错误*/
#define TPU_ERROR_CODE_BUSI2_PROCESS_ERROR                         0x00001060 /*一卡通/城市通业务处理类错误*/
#define TPU_ERROR_CODE_CONFIG_PARAM_ERROR                          0x00001070 /*配置参数类错误*/
#define TPU_ERROR_CODE_USAGE_DATA_ERROR                            0x00001080 /*UD类错误*/
#define TPU_ERROR_CODE_HARDWARE_ERROR							   0x00001090 /*硬件类错误*/
#define TPU_ERROR_CODE_B1										   0x000010B1 /*卡片充值操作未完成，请重新放卡*/
#define TPU_ERROR_CODE_B2										   0x000010B2 /*卡片充值操作未完成，不是同一张卡，请重新放卡*/
#define TPU_ERROR_CODE_B3										   0x000010B3 /*一卡通授权额度已用尽或已到期，需重新授权*/
#define TPU_ERROR_CODE_UNKNOWN_ERROR							   0x000010F0 /*未归类错误*/

#define TPU_BLACKLIST_CARD_HAS_BEEN_BLOCKED                        0x000010E1 /*黑名单卡，且已被锁定*/
#define TPU_OVER_ONE_CARD										   0x000010E2 /*超过1张卡*/
#define TPU_ERROR_CARD_PHY_TYPE									   0x00001101 /*卡物理类型错误*/
#define TPU_ERROR_CODE_ONLINE_COMMNUNICATION_FAILED      		   0x00001201 /*TPU处理在线通讯失败，此时上层业务不应调用TPU 的GetLastError*/
#define TPU_ERROR_CODE_NO_SAM_INFO                                 0x00001202 /*TPU中未获取到SAM卡信息*/
#define TPU_REVALUE_CHECK_FAILED                                   0x00001210 /*充值核对失败，请人工检查充值情况*/
#define TPU_REVALUE_EXCEPTION_BY_REVALUE_CHECK                     0x00001211 /*充值核对判定充值异常，请人工检查充值情况*/

#define TPU_ERROR_CODE_OVERTIME                                    0x00001221 /* 超时 */
#define TPU_ERROR_CODE_OVERRIDE                                    0x00001222 /* 超程 */
#define TPU_ERROR_CODE_OVERRIDE_OVERTIME                           0x00001223 /* 超时、超程 */


//0x80020001 ~ 0x8002005F 权限相关错误
#define PRIV_OPERATOR_NULL                                         0x00002001 /*操作员为空L*/
#define PRIV_PASSWORD_NULL                                         0x00002002 /*密码为空*/
#define PRIV_PASSWORD_NOT_MATCH                                    0x00002003 /*密码不匹配*/

#define PRIV_OPERATOR_NOT_EXIST                                    0x00002005 /*操作员不存在*/
#define PRIV_OPERATOR_INFO_QUERY_FAILED                            0x00002006 /*查询操作员信息失败*/
#define PRIV_OPERATOR_USED_BEFORE_ACTIVE                           0x00002007 /*未到操作员启用时间*/
#define PRIV_OPERATOR_EXPIRED                                      0x00002008 /*操作员已过期*/
#define PRIV_OPERATOR_NO_PERMISSION                                0x00002009 /*操作员无授权功能*/
#define PRIV_OPERATOR_IS_SUPER_ADMIN                               0x0000200A /*超级操作员*/

#define PRIV_OPERATOR_LOCKED_SUCESS                                0x0000200B /*操作员锁定成功*/
#define PRIV_OPERATOR_LOCKED_ONLINE_FAILED                         0x0000200C /*在线锁定操作员失败*/
#define PRIV_OPERATOR_LOCKED_LOCAL_FAILED                          0x0000200D /*本地锁定操作员失败*/
#define PRIV_OPERATOR_GET_LOCKED_STATUS_FAILED                     0x0000200E /*获取操作员锁定状态失败*/
#define PRIV_OPERATOR_UNLOCKED_FAILED                              0x0000200F /*操作员解锁失败*/
#define PRIV_OPERATOR_HAS_BEEN_LOCKED                              0x00002010 /*操作员已锁定*/

#define PRIV_LOGIN_FAILED                                          0x00002021 /*操作员登录失败*/
#define PRIV_LOGIN_VERIFY_ACCOUNT_ONLINE_FAILED                    0x00002022 /*在线验证失败*/
#define PRIV_LOGIN_OFF_LINE_FOR_NETWORK_STATUS                     0x00002023 /*网络状态错误，需脱机登录*/
#define PRIV_LOGIN_FAILED_ERROR_DEVICE_SYSTEM_STATUS               0x00002024 /*错误的设备系统状态*/
#define PRIV_LOGIN_LOGOUT_SEND_NOTIFY_FAILED                       0x00002025 /*发送登录、登出通知失败*/

#define PRIV_CHANGE_PASSWORD_FAILED                                0x00002031 /*修改密码失败*/
#define PRIV_CHANGE_PASSWORD_NEW_PASSWORD_NULL                     0x00002032 /*新密码为空*/
#define PRIV_CHANGE_PASSWORD_OLD_PASSWORD_INPUT_ERROR              0x00002033 /*旧密码输入错误*/
#define PRIV_CHANGE_PASSWORD_CONFIRM_PASSWORD_NOT_MATCH            0x00002034 /*新密码与确认密码不匹配*/
#define PRIV_CHANGE_PASSWORD_OLD_NEW_PASSEORD_IS_SAME              0x00002035 /*新密码与旧密码相同*/
#define PRIV_CHANGE_PASSWORD_OK              	   				   0x00002036 /*密码修改成功*/

#define PRIV_LOGOUT_FAILED                                         0x00002041 /*登出失败*/
#define PRIV_LOGOUT_ONLINE_FAILED                                  0x00002042 /*在线登出失败*/
#define PRIV_LOGOUT_REFUSED_BY_SC                                  0x00002043 /*拒绝登出*/
#define PRIV_UNLOCK_OPERATOR_FAILED                                0x00002051 /*解除锁定失败*/



/*****************************************BOM主业务信息码************************************/
//读卡错误信息码
#define BOM_READ_CARD_NON_CARD			       				   	   0x00004001//无卡
#define BOM_READ_CARD_GET_ERRORCODE_SUCCESS			               0x00004002//获取错误码成功
#define BOM_READ_CARD_GET_ERRORCODE_FAILED				           0x00004003//获取错误码失败
#define BOM_READ_CARD_CARDTYPE_ERROR       				           0x00004004//卡类型错误
#define BOM_READ_CARD_ABOUT_FAILED			       		   	       0x00004005//中止失败
#define BOM_READ_CARD_JUMP_HISTORY_UI			       		       0x00004006//跳转历史交易记录界面
#define BOM_READ_CARD_JUMP_RETURN_QUERY_UI			       	       0x00004007//返回到查询界面
#define BOM_READ_CARD_SHOW_TPU_ERRORINFO			       	       0x00004008//显示读卡器错误信息
#define BOM_READ_CARD_ANALYZE_SUCCESS						       0x00004009//票卡分析成功


//发售UL卡错误信息码
#define BOM_SALE_UL_TICKET_GET_FINE_FAILED					   	   0x00004010//获取罚款金额失败
#define BOM_SALE_UL_TICKET_STATAR_THREAD_FAILED					   0x00004011//售UL卡时启动线程失败
#define BOM_SALE_UL_TICKET_STATAR_THREAD_WAIT					   0x00004012//售UL卡时启动线程等待
#define BOM_SALE_UL_TICKET_PROVIDE_CARD_FAILED					   0x00004013//提票失败
#define BOM_SALE_UL_TICKET_SAVE_DATABASE_TICKETBOXINFO_FAILED	   0x00004014//更新数据库中票箱数量失败
#define BOM_SALE_UL_TICKET_WITHDRAW_CARD_FAILED					   0x00004015//回收票卡失败
#define BOM_SALE_UL_TICKET_SALE_FAILED					   		   0x00004016//售卡失败
#define BOM_SALE_UL_TICKET_EJECT_CARD_FAILED					   0x00004017//出票失败
#define BOM_SALE_UL_TICKET_ALIKE_CARD       				       0x00004018//同一张卡
#define BOM_SALE_UL_TICKET_UPDATE_UI_BOX_COUNT			       	   0x00004019//更新界面票箱数量
#define BOM_SALE_UL_TICKET_WRITEORSAVEDATE_FAILED			       0x0000401A//写卡或保存数据失败
#define BOM_SALE_UL_TICKET_SALE_SUCCESS					   		   0x0000401B//售卡成功
#define BOM_SALE_UL_TICKET_TICKETBOX_EMPTY					   	   0x0000401C//票箱已空
#define BOM_SALE_UL_TICKET_SALE_CARD_ADD					   	   0x0000401D//售卡成功后界面数量自增
#define BOM_SALE_UL_TICKET_SETERROR_FAILED					   	   0x0000401E//错误重置发行单元失败
#define BOM_SALE_UL_TICKET_EMPTY					   			   0x0000401F//清空界面提示

#define BOM_SALE_UL_TICKET_INPUT_PRICE					   		   0x00004020//请输入票价
#define BOM_SALE_UL_TICKET_INPUT_PIECE					   		   0x00004021//请输入张数
#define BOM_SALE_UL_TICKET_INPUT_STATION					   	   0x00004139//请输入车站

#define BOM_SALE_UL_TICKET_FARE_CALCULATION_FAILED		   		   0x00004022//计算票价失败
#define BOM_SALE_UL_TICKET_INPUT_ORIGIN_STATION					   0x00004023//请选择进站车站
#define BOM_SALE_UL_TICKET_INPUT_DESITINATION_STATION			   0x00004024//请选择出站车站

#define BOM_PRINT_SUCCESS					            		   0x00004025//打印单据成功
#define BOM_PRINT_FAILED	                					   0x00004026//打印单据失败

#define BOM_REFUND_UL_TICKET_INPUT_MONEY	                	   0x00004027//请输入退票金额
#define BOM_REFUND_UL_TICKET_SUCCESS_PRINT_SUCCESS	               0x00004028//退票成功,打印单据成功
#define BOM_REFUND_UL_TICKET_SUCCESS_PRINT_FAULT	               0x00004029//退票成功,打印单据失败
#define BOM_REFUND_UL_TICKET_SAVE_DATA_FAULT	    	           0x0000402A//保存数据失败

#define BOM_COMPENSATION_TICKET_UNABLE_HANDLE			    	   0x00004040//该车票无法处理
#define BOM_COMPENSATION_TICKET_DISPENSE_UPDATE			    	   0x00004041//该车票不需更新
#define BOM_COMPENSATION_TICKET_REMAINING_DEFICIENCY	    	   0x00004042//卡内余额不足，请充值
#define BOM_COMPENSATION_INVALID_CPSTCODE				    	   0x00004043//无效建议代码
#define BOM_COMPENSATION_TICKET_SUCCESS							   0x00004044//补票成功
#define BOM_COMPENSATION_TICKET_FAILT							   0x00004045//补票失败
#define BOM_COMPENSATION_TICKET_TPU_FAILT						   0x00004046//读卡器补票失败
#define BOM_COMPENSATION_TICKET_INPUT_ENTER_STATION				   0x00004047//请输入进站车站
#define BOM_COMPENSATION_TICKET_INPUT_EXIT_STATION				   0x00004048//请输出进站车站


#define BOM_COMPENSATION_TICKET_JUMP_ADDVALUE_UI				   0x00004901//跳转到充值界面
#define BOM_COMPENSATION_TICKET_JUMP_PAY_EXITTICKET_UI			   0x00004902//跳转到发售付费出站票界面
#define BOM_COMPENSATION_TICKET_JUMP_FREE_EXITTICKET_UI			   0x00004903//跳转到发售免费出站票界面



#define BOM_INPUT_MONEY_EMPTY					    	       	   0x00004901//输入金额为空
#define BOM_TICKET_OPERATION_NO_BUSINESS		    	           0x00004999//此票种暂不支持此业务


typedef struct _BOM_FUNC_ {
	char Id[10];
	char Value[10];
} BOM_FUNC;

typedef struct _ST_EXECUTION_INFO
{
	int Fare;//票价
	int SaleNum;//发售张数
	int TotalNum;//总张数
	char ResultMsg[256];//提示信息

	int iResult; 	//结果

	char OperId[10]; //操作员
	int RemainingRetryTimes;//剩余次数
	BOM_FUNC *Funcs;//功能ID数组
	int FuncCount;//功能ID个数

} ST_EXECUTION_INFO;

typedef struct _ST_DEVICE_BASE_INFO
{
	char operName[30];//操作员姓名
	int shiftNO;//班次流水号
	char deviceId[15];//设备ID
	char localIP[20];//本地IP
	char bomSoftVersion[30];//BOM软件版本
	char deskTpuVersion[30];//桌面TPU软件版本
	char issueTpuVersion[30];//发行TPU软件版本
	int paidAreaFlag;//付费区标志
}ST_DEVICE_BASE_INFO;

typedef struct _ST_DEVICE_BASE_STATUS
{
	int workMode;//工作模式
	int printerStatus;//打印机状态
	int deskTpuStatus;//桌面读卡器状态
	int issueTpuStatus;//发行读卡器状态
	int issueStatus;//发行状态
	int upsStatus;//UPS状态
	int netStatus;//网络状态
	int stationMode;//车站模式
	char runDate[10];//运营日
}ST_DEVICE_BASE_STATUS;

typedef struct _ST_ISSUE_BOXCOUNT
{
	int numberOfBox1;//票箱1数量
	int numberOfBox2;//票箱2数量
	int numberOfBox3;//票箱3数量
}ST_ISSUE_BOXCOUNT;

typedef struct _ST_BOM_STATUS_INFO
{
	ST_DEVICE_BASE_INFO stDeviceBaseInfo;
	ST_DEVICE_BASE_STATUS stDeviceBaseStatus;
	ST_ISSUE_BOXCOUNT stIssueBoxCount;
} ST_BOM_STATUS_INFO;

typedef struct _ST_TRANSACTIONINFO_ {
	int mTradeSqe;              //编号
	char TradeMoney[10];        //交易金额
	char TradeTypeCN[50];       //交易类型
	char TradeTerminal[30];     //交易车站
	char TradeTime[20];         //交易时间
} ST_TRANSACTIONINFO;

//票卡查询信息
typedef struct _ST_CARDINFO_ROOT_ {
	char CardSerialNumber[30];                         //物理卡号
	char CardPHType[20];							   //票卡芯片类型
	char LogicCardNo[30];							  //逻辑卡号
	char ProductyType[50];							  //产品类型
	int iTicketType;									//票卡类型
	char CardStatus[30];							  //票卡状态
	char RemainingValue[10];							//卡余额
	char ValidStartDateTime[15];                       //有效起始时间
	char ValidEndDateTime[15];						  //有效结束时间
	char JourneyStatus[20];							  //旅程状态/进出站状态
	char EnterStationCode[30];						  //进站站点
	char EnterStationDeviceCode[12];				  //进站设备ID
	char EnterStationDataTime[15];				  //进站时间
	char ExitStationCode[30];						  //出站站点
	char ExitStationDeviceCode[12];				  //出站设备ID
	char ExitStationDataTime[15];				  //出站时间
	char CardMainType[5];							  //卡主类型
	char ProductySubType[5];						  //卡子类型
	char UsableStationCode1[30];						  //可使用站点1
	char UsableStationCode2[30];						  //可使用站点2
	char CompensationValueProposed[30];				  //建议补票金额
	char CompensationServiceFee[30];					  //更新手续费
	char CardDepositValue[10];						  //卡押金
	char SaleCardStation[12];						  //售票设备号
	char AnalyzeResult[100];                            //分析结果
	char OperatingInstructions[100];					//操作说明
	char IssueDeposit[10];								// 发售押金
	char IssueRemainingValue[10];								// 发售余额
	char IssuePrice[10];								  //售票金额
	char IssueTimes[10];								  //发售次数
	char IssueEndDateTime[15];						  //售后有效期


	char LasUseTerminalID[10];				  //最近使用设备
	char LastUseTranTime[15]; 					  //最近交易时间
	char LastUseType[30];						  //最近交易类型


	char FillMinValue[10];								//最小充值金额/次数
	char FillMaxValue[10];								//最大充值金额/次数
	char FillEndDateTime[15];						  //充值后有效期

	char RefundTicketServiceFeeProposed[10];			  //退款手续费
	char RefundTicketValueProposed[10];				  //退款金额
	char DepreciationCharge[10];								// 折旧费

	char BlockUnLockMoney[10];						 //黑名单解锁手续费

	char DelayTicketServiceFeeProposed[10];			 //延期手续费
	char DelayEndDateTime[15];						  //延期后有效期

	char ActiveServiceFeeProposed[10];					//激活手续费
	char ActiveFlagCN[20];								  //激活状态
	char ValidBeginTimeOfActive[15];					  //激活后有效开始时间
	char ValidEndTimeOfActive[15];					  //激活后有效结束时间

	char ReplaceOldCardValue[10];						//转出金额
	char ReplaceOldRemainingValue[10];						//余额
	char ReplaceOldDepositValue[10];						//押金
	char ReplaceOldServiceFeeProposed[10];						//手续费

	char ReplaceNewDepositValue[10];						//押金
	char ReplaceNewEndTimeOfActive[15];					  //替换后有效期

	char ValidAreaID[10];							  //可使用区段编号
	char ExitTicketFlag[30];							//出站票标志
	char BlacklistFlag[30];								//黑名单标志
	char PreAssignment[30];								//预赋值标志
	char IsEntryStationFlag[3];						  //进出站标志
	char CityCode[5];								  //城市代码
	char IndustryCode[10];							  //行业代码
	char IssuerCode[10];								  //发行商代码
	char IssueDate[15];								  //发行日期
	char IssueSn[20];								  //发行流水号
	char TranTimesOfDay[5];							  //日乘坐次数
	char TranTimesOfMonth[5];						  //月乘坐累计次数

	char LastFillValueTerminalID[10];				  //最近充值终端编号
	char LastFillValueTranTime[15]; 					  //最近充值时间
	char LastFillTranValue[10];						  //最近充值金额
	char FillValueOfTatal[10];						  //充值总金额
	char LastFillValue[10];							  //最近充值值
	char PersnalSex[5];                               //性别
	char WorkUnit[30];							      //工作单位
	char PersnalCardID[30];							  //证件号码
	char PersnalName[30];							  //姓名
	char PersnalCardType[5];						  //证件类型
	int RechargeFlag;                               //充值标志
	int UpdateFlag;								//更新标志
	int IssueFlag;								//发售标志
	int ActiveFlag;								//激活标志
	int DelayFlag;								//延期标志
	int RefundFlag;								//退票标志
	int UnlockFlag;								//解锁标志
	int ReplaceOldCard;							//旧卡转出
	int ReplaceNewCard;							//新卡转入
	int IsShowHistoryTran;						//显示历史交易信息
	ST_TRANSACTIONINFO * mTranSactionInfos;
	int mTranSactionCount;
	int mResultCode;
} ST_CARDINFO_ROOT;


typedef struct _ST_BOM_UI_RESPONSE_DATA
{
	char OperId[10];        //操作员ID
	char Password[10];		//密码
	char Logintype[3];		//登录类型
	char IP[20];			//本机IP地址
	char NetMask[20];		//本机网络掩码
	char NetGate[20];		//本机网关
	char NumberInput[50];	//循环测试张数
	char DateTime[20];		//界面时间
	char FtpIp[20];			//FtpIP
	char FtpUser[10];		//FtpUser
	char FtpPwd[10];		//FtpPwd
	char DeviceCode[12];	//界面输入的设备编号
	char StationCode[6];	//界面输入的车站编号
	char LineCode[4];		//界面的输入的线路编号
	char ScIp[20];			//SC通信地址
	char CommPort[10];		//通信端口
	char TicketSetValue[5];	//售票设置
	char SaleCompensationValue[5]; //售补票模式
	char AutoId[10];		//单据补打ID
	char ParamID[10];		//参数ID

	char EndDateTime[20];	//结束时间
	char StartDateTime[20];	//开始时间

	char ProductType[10];	//票卡类型
	char IssuerId[10];		//发行商ID
	char PriceInput[10];	//票价
	char PieceInput[10];	//张数
	char SourceStation[10];	//起始车站编码
	char DestStation[10];	//终点车站编码

	char PaymentsCause[5];	//支付类型
	char FaultRefundTicketId[30];  //退款故障码
	char FaultRefundTicketValue[10]; //故障退款金额

	char RefundTicketValueProposed[10];  //退款金额
	char TransactionValue[10];	//交易金额
	char TransactionTimes[10];  //交易次数
	char TotalMoney[10];		//合计
	char ShouldInComeMoney[10];	//实收
	char Recharge[10];			//找零
	char DepositValue[10];		//押金
	char RefundTicketServiceFeeProposed[10];	//退款手续费
	char RefundType[5];			//退款类型
	char CompensationValueProposed[10];		//更新金额
	char Fines[10];				//罚款金额

	char RemainingValue[10];								// 余额
	char DepreciationCharge[10];								// 折旧费

	char IsPrint[5];			//是否打印；0：不打印；1：打印

	//个性化申请
	char PassengerName[30];		//姓名
	char Sex[5];				//性别
	char DateOfBirth[20];		//出生日期
	char IdentityType[5];		//证件类型
	char IdentityID[20];		//证件ID
	char TicketType[20];		//车票类型
	char PhoneNumber1[20];		//电话1
	char PhoneNumber2[20];		//电话2
	char HomeAddress[20];		//地址
	char ApplicationSeq[30];	//申请单号

	char TicBoxCount1[10];		//票箱1数量
	char TicBoxCount2[10];		//票箱2数量
	char TicBoxCount3[10];		//票箱3数量

	char PaidAreaFlag[5];		//付费区标志；0：非付费区；1：付费区

} ST_BOM_UI_RESPONSE_DATA;

typedef struct SETTLEMENT_SettlementDateInfo_t {
	int iShiftId;
	char SettlementData[2048];
} SETTLEMENT_SettlementDateInfo;

typedef struct SETTLEMENT_Root_t {
	SETTLEMENT_SettlementDateInfo * mSettlementDateInfos;
	char CurSettlementData[20];
	int SettlementCount;
	char RunDate[10];
	int ResultCode;
} SETTLEMENT_Root;


typedef enum
{
	TPU_STATE_NORMAL	= 0x00,	/*读写器正常*/
	TPU_STATE_SAM_ERROR	= 0x01,	/*读写器SAM错误*/
	TPU_STATE_NO_COMMUNICATION = 0x02,	/*无通讯*/
	TPU_STATE_SAM_MISMATCH	= 0x03,	/*SAM卡不匹配*/

}TPU_STATE_CODE;

#endif /*BOMPUBLICDATAINFO_H_*/
