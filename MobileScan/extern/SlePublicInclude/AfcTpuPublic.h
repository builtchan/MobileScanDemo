/*
 * AfcTpuPublic.h
 *
 *  Created on: Jan 29, 2015
 *      Author: wugang
 */

#ifndef AFCTPUPUBLIC_H_
#define AFCTPUPUBLIC_H_

#include "AfcPublic.h"
#include "SleParamAttriDefPublic.h"

//交易数据类型： 交易数据记录类别：0x01：存入一卡通表中的交易数据；  0x02：存入一票通表中的交易数据
typedef enum
{
	//UD 类型 ： 存入一卡通表中的交易数据
	EM_UD_CATEGORY_CSS_YKT = 0x99,

	//UD 类型： 存入一票通表中的交易数据
	EM_UD_CATEGORY_CSS_YPT = 0x01,

	//UD 类型： 存入NFC表中的交易数据
	EM_UD_CATEGORY_CSS_NFC = 0x02,

	//UD 类型： 存入银行表中的交易数据
	EM_UD_CATEGORY_CSS_BANK = 0x03,

}EM_UD_CATEGORY_CSS;

/*************************************** 数据类定义 ******************************************/

//车票有效性检查和交易结果枚举
typedef enum
{
	EM_TICKET_TRANS_RESULT_OK = 0,		//OK,预读OK,有效性检查OK
	EM_TICKET_TRANS_RESULT_EXPIRED = 1,		//车票过期
	EM_TICKET_TRANS_RESULT_OUTSIDE = 2,		//区段外车票
	EM_TICKET_TRANS_RESULT_INSUFFICIENT_BALANCE = 3,		//余额/余次不足
	EM_TICKET_TRANS_RESULT_OVERTIME = 4,		//超过滞留时间
	EM_TICKET_TRANS_RESULT_DATA_ERROR = 5,		//车票数据无效
	EM_TICKET_TRANS_RESULT_BKACKLIST = 6,		//黑名单车票
	EM_TICKET_TRANS_RESULT_RW_FAILTRUE = 7,		//车票读写失败
	EM_TICKET_TRANS_RESULT_TYPE_INVALID = 8,		//车票类型不能进行当前业务
	EM_TICKET_TRANS_RESULT_MULTI_TICKETS = 9,		//多张车票
	EM_TICKET_TRANS_RESULT_PLEASE_INPUT_CARD = 10, //请投入车票：用于AGM根据物理卡类型进行提示
	EM_TICKET_TRANS_RESULT_PLEASE_SWIPE_CARD = 11, //请刷卡：用于AGM根据物理卡类型进行提示
	EM_TICKET_TRANS_RESULT_CARD_MOVED = 12, //闪卡,请重新放卡
	EM_TICKET_TRANS_RESULT_OTHER_ERROR = 0xFF,		//其他错误
}EM_TICKET_TRANS_RESULT;

//车票产品种类
typedef enum
{
	EM_CSS_PRODUCTY_CATEGORY_PURSE     	= 0x01,//钱包
	EM_CSS_PRODUCTY_CATEGORY_MULTIRIDE	= 0x02,//计次
	EM_CSS_PRODUCTY_CATEGORY_PERIOD 	= 0x03,//定期
	EM_CSS_PRODUCTY_CATEGORY_NO_VALUE   = 0x04,//无数值属性的种类，如： 用于HRB车站工作票
	EM_CSS_PRODUCTY_CATEGORY_UNKNOWN 	= 0xFF,//未知

}EM_CSS_PRODUCTY_CATEGORY;

//发行商ID
typedef enum
{
	//发行商ID，ACC
	EM_CSS_PRODUCT_ISSUERID_ACC = 0x01,

	//发行商ID，OCT
	EM_CSS_PRODUCT_ISSUERID_OCT = 0x99,

	/*未知发型商ID*/
	EM_CSS_PRODUCT_ISSUERID_UNKNOWN = 0xFF,


}EM_CSS_PRODUCT_ISSUER_ID;

//卡片使用方式_出站刷卡或投入(回收)
typedef enum
{
	EM_CARD_USED_WAY_WITHDRAW = 0x01, //出站投入(回收)
	EM_CARD_USED_WAY_NON_WITHDRAW = 0x02, //出站刷卡
	EM_CARD_USED_WAY_UNKNOWN = 0xFF, //未知
}EM_CARD_USED_WAY;

// 票卡回收状态
typedef enum
{
	EM_TICKET_NO_WITHDRAW = 0x00, //不回收
	EM_TICKET_NORMAL_WITHDRAW = 0x01, //正常回收
	EM_TICKET_BADTICKET_WITHDRAW = 0x02, //废票回收
	EM_TICKET_OVERCOUNT_WITHDRAW = 0x03, //达到最大次数卡回收
	EM_TICKET_BATCH_WITHDRAW = 0x04, //批次回收
}EM_TICKET_WITHDRAW_WAY;


/* Polling卡信息 */
typedef struct _ST_POLLING_CARD_INFO_CSS_
{
	EM_TICKET_TRANS_RESULT emPollResult;	//寻卡结果
	EM_CARD_USED_WAY emCardUsedWay;			//卡片使用方式_出站刷卡或投入(回收),仅AG有效，TVM、BOM忽略
	int iCardPhyType;						//卡物理类型
	char szPhyCardNo[21];					//物理卡号
	int iAntennaMark;						//寻卡天线标志：	1：表示天线A寻到卡片；	2：表示天线B寻到卡片；4：表示天线C寻到卡片。
	unsigned int uiUdSeqKey;				//需要更新的UDSN 键值，由TPU 模块根据车票类型进行项目化实现，并传给数据存储模块直接保存
	unsigned int uiSamSeqKey;				//需要更新的UDSN 键值，由TPU 模块根据车票类型进行项目化实现，并传给数据存储模块直接保存
}ST_TPU_POLLING_CARD_INFO;


/* 票卡交易记录 */
typedef struct _ST_CSS_CARDINFO_TRANS_LOG_INFO_
{
	/* 交易类型 */
	unsigned int uiTransType;

	/* 交易类型中文，直接用于UI显示 */
	char szTransTypeCn[20];

	/* 交易类型中文，直接用于UI显示 */
	char szTransTypeEn[40];

	/* 交易金额 ，*/
	unsigned int uiTransactionValue;

	/* 交易车站 */
	unsigned int uiTransactionStationCode;

	/* 交易终端号 */
	char szTransactionTerminationCode[20];

	/* 交易时间 */
	char szTransactionDateTime[15];

}ST_CSS_CARDINFO_TRANS_LOG_INFO;

/* 票卡旅程信息 */
typedef struct _ST_CSS_CARDINFO_JOURNEY_INFO_
{
	/* 旅程状态 */
	unsigned int uiJourneyStatus;

	/*旅程状态中文信息*/
	char szJourneyStatusCn[20];

	/*旅程状态英文信息*/
	char szJourneyStatusEn[20];

	/* 进站车站编码 */
	unsigned int uiEntryStationCode;

	/* 进站时间 */
	char szEntryDateTime[15];

	/* 出站车站编码 */
	unsigned int uiExitStationCode;

	/* 出站时间 */
	char szExitDateTime[15];


}ST_CSS_CARDINFO_JOURNEY_INFO;


typedef struct _ST_TPU_SALE_INFO_
{
	  //乘客类型	1HEX	CCHS标准规定的乘客的类别, UI赋值
	  unsigned char ucPassengerType;

	  //起点站（或区段）站码	4HEX	按照起止站售票时填入的起始车站位置信息
	  unsigned char szBeginStation[4];

	  //终点站（或区段）站码	4	HEX	按照起止站售票时填入的终止车站位置信息
	  unsigned char szEndStation[4];

	  char szBeginValidDate[9];//有效起始日期 20150101

	  unsigned char ucSeatType;	// 坐席类型s, 由UI赋值

	  unsigned char ucLanguageType;	// 语言类型, 由UI赋值

	  bool bPreIssueFlag;// 预售标志 false: 其他   true:预售票

	  unsigned char szReserve[100];	//预留


}ST_TPU_SALE_INFO;

//交易数据快照结构体
typedef struct __ST_TRANS_RESULT_CSS__
{
	/* 交易结果
	* 		交易成功时：EM_TICKET_TRANS_RESULT_OK
	* 		检票失败时，指定原因；
	* 		售票失败：EM_TICKET_TRANS_RESULT_OTHER_ERROR
	*/
	EM_TICKET_TRANS_RESULT emTransResult;

	EM_TICKET_WITHDRAW_WAY emWithdrawFlag;	//票卡回收状态

	/* 高级黑名单	1HEX 	false：否，true：是；	*/
	bool bHighBlacklist;

	/* 车票产品种类
	*    0x01 钱包;
	*    0x02 计次；
	*    0x03 定期；
	*    0x04 无产品种类属性（既无余额，也无余次，也无定期属性）；
	*    0xFF 未知产品类型 */
	EM_CSS_PRODUCTY_CATEGORY emCssProductyCategory;

	/* 车票发行商	2HEX 与导则约定有关的具体票种类型 CSS_PRODUCT_ISSUERID_ACC = 0x01, 城市通： CSS_PRODUCT_ISSUERID_OCT = 0x99 */
	EM_CSS_PRODUCT_ISSUER_ID emCssProductIssuerId;

	/* 车票产品类型	2HEX 与导则约定有关的具体票种类型
	*  该字段，在保存收益信息时，会同步到 Busi_Incoming 表中，在结算业务数据生成时， 依据该字段，来按类别（单程票、地铁储值票、城市通票）统计： 免费更新、付费更新
	* [WH]票卡主类型
	* 01.单程票; 02.储值票; 03.乘次票 ;04.定期票; 05.ID票 ;07.员工票
	**/
	unsigned short usProductyType;

	/* 车票产品类型	2HEX 与导则约定有关的具体票种类型，项目中，借用其用于表示以下内容，以便于与上位机进行业务的其他控制：	 *
	*	[WH] 票卡子类型
	*	 0=成人 ;1=学生/小孩; 2=老人优惠票 ;3=纪念票
	*  */
	unsigned short usProductySubType;

	/* 城市通卡发行流水号或一票通逻辑卡号	4HEX */
	char szCardNo[21];//卡逻辑编号 CardNo［21］ NN:为票卡物理卡号

	/* 操作前余额	4HEX 计次卡填次，定期卡该字段无效 */
	int iBeforAmount;

	int iTransValue;

	/* 操作后余额	4HEX	计次卡填次，定期卡该字段无效
	 * WH：售票业务 操作后余额 */
	int iAfterAmount;

	/* 票卡锁定状态	1HEX	false：票卡未锁定，true：票卡被锁定；*/
	bool 	bBlockFlag;

	/* 票卡截止日期	票卡可有效使用的截至日期 20151231235959*/
	char  	szCardValidDate[15];

	/* 票卡物理类型	1HEX	  注10
 	 NN:十进制：0,地铁ULT卡； 4,明珠CPU卡；*/
	unsigned char  	ucCardPhysicalType;

	unsigned char ucSeatType;	// 坐席类型s, 由UI赋值

	unsigned char ucLanguageType;	// 语言类型, 由UI赋值

	int iTpuErrorCode;					//项目化故障码，TPU返回
	unsigned char reserve[100];
}ST_TPU_TRANS_RESULT;

/*单条UD结构信息*/
typedef struct __ST_SINGLE_UD_DATA_CSS__
{
	//交易记录类型代码 0x01：地铁单程类车票； 0x02：地铁储值类车票； 0x03：明珠卡/一卡通/城市卡/市民卡类车票；
	unsigned short ucUdCategoryProj;   //char --> short

	unsigned char ucCardPhType;

	unsigned int uiProductType;

	unsigned int uiUDType;

	unsigned int uiUDSubType;

	unsigned int uiUdsnFromTpu;

	//需要更新的UDSN 键值，由TPU 模块根据车票类型进行项目化实现，并传给数据存储模块直接保存
	unsigned int uiUdSeqKey;

	//需要更新的UDSN 键值，由TPU 模块根据车票类型进行项目化实现，并传给数据存储模块直接保存
	unsigned int uiSamSeqKey;

	unsigned int uiTranValue;

	unsigned int uiDeposit;

	unsigned int uiServiceFee;

	//根据不同交易记录类型，UD数据体长度不同
	unsigned int uiTransDataLength;

	//根据不同交易记录类型，UD 数据信息格式不同
	unsigned char szTransData[UD_DATA_MAX_SIZE];

}ST_SINGLE_UD_DATA_CSS;

/*UD结构信息*/
typedef struct _ST_UD_DATA_CSS_
{
	//增加UD类别的解析
	EM_UD_CATEGORY_CSS emUdCategoryCss;

	//地方标准约定的UD分类
	unsigned short ucUdCategoryProj;  //char --> short

	//预留一次交易产生多条数据的应用； UD数据不存在或非立即返回UD数据时设置为0
	unsigned char ucUdCount;

	//单条UD结构信息 列表
	ST_SINGLE_UD_DATA_CSS arSingleUdDataProjList[6];

}ST_UD_DATA_CSS;


/*单条AR结构信息*/
typedef struct _ST_SINGLE_AR_DATA_CSS_
{
	unsigned char ucArKey;
	unsigned char ucArKeyIncreasement; //AR增加值

}ST_SINGLE_AR_DATA_CSS;


//AR数据结构体：
typedef struct __ST_AR_DATA_CSS__
{
	unsigned char ucARnum;

	//单条UD结构信息 列表
	ST_SINGLE_AR_DATA_CSS stArSingleUdDataProjList[AR_DATA_MAX_SIZE];

}ST_AR_DATA_CSS;




typedef struct __ST_TICKET_TRANS_DETAIL_INFO__
{
	ST_UD_DATA_CSS stUDData;		//UD数据记录

	ST_AR_DATA_CSS stArData;		//UD数据记录

}ST_TICKET_TRANS_DETAIL_INFO;



/* TPU环境数据 */
typedef struct __ST_TPU_CONTEXT_DATA__
{
	/*交易（业务）类型 */
	EM_SLE_TRANSACATION_TYPE emTransType;

	//操作员代码，字符串类型， 例如： 15411001, 没有填'/0'
	char szOperatorCode[20];

	//运营日期， 有效长度8位字符的字符串， 如：20141119
	char szRunDate[9];

	//业务日期， 有效长度8位字符的字符串， 如：20141119
	char szBusiDate[9];

	//业务时间， 有效长度8位字符的字符串， 如：154134
	char szBusiTime[7];

	//付费方式： 0x01 现金； 0x02 储值卡支付； 0x03 银行卡支付； 0x04 代金卷支付； 0x05 其他；
	EM_PAYMENT_METHOD emPaymentMethod;

	//UD流水号
	unsigned long ulUDSN;

	//SAM卡交易流水号
	unsigned long ulSamSN;

	//储值卡购买单程票时，储值卡逻辑卡号，其他情况填0
	unsigned char szSvtCardSn[21];

	//产品类型： 用于售票，检票填0
	unsigned int uiProductType;

	//车票产品子类型	 2HEX, 用于售票，检票填0
	unsigned short usProductSubType;

	//卡押金： 用于售票，检票填0
	unsigned int uiDepositValue;

	//卡成本费： 用于售票，检票填0
	unsigned int uiCardFee;

	//服务费： 用于售补退票，检票填0
	unsigned int uiServiceFee;

	//交易金额，售票填票价，检票填0
	unsigned int uiTransactionValue;

	//[DL] 必填项， 优惠金额	HEX	4
	unsigned int uiDiscountValue;

	//计次类车票使用次数	2HEX	非计次类车票，该字段填0
	unsigned int uiTicketUseCount;

	//测试标记： false：正常票 true：测试票 .  保存数据时，也需要使用该字段
	bool bTestFalg;	//

	unsigned char szReserve[100];	//预留
}ST_TPU_CONTEXT_DATA;


/* 业务环境数据 */
typedef struct __ST_BUSINESS_CONTEXT_DATA__
{
	ST_TPU_CONTEXT_DATA stTpuContextData;

	//交易（业务）子类型，如：BOM 超时补票、超程补票、
	EM_SLE_TRANSACATION_SUB_TYPE emTransSubType;

	/*Tvm交易流水号， 用于Tvm 10张票，作为1笔交易（一个TranId）的 分析 */
	unsigned long ulTranId;

	//产品发行商ID： 来自UI， 用于售单程票等
	unsigned int uiProductIssuerId;

	//产品发行商ID：根据读卡结果 获取的发型商ID
	unsigned int uiLavProductIssuerId;

	//卡片种类： 从卡里读取的产品类型
	unsigned int uiLavProductType;

	//产品类型： 从卡里读取的产品类型
	unsigned int uiLavCardPHType;

	/* 城市通卡发行流水号或一票通逻辑卡号	4HEX 注： 根据读卡器结果记录，而非交易结果，防止写卡失败时，无法记录该信息 */
	char szCardNo[21];//卡逻辑编号 CardNo［21］

	//SAM 卡号
	char szSamId[21];

	unsigned char szReserve[100];	//预留
}ST_BUSINESS_CONTEXT_DATA;


typedef struct _ST_TPU_READ_CARD_PARAM_
{
	/* 合法性检查标志 1HEX
	 * 注1： 通过该标志设定R/W读卡信息时是否自动做合法性检查.
	 * 0x01：读卡时，R/W自动做合法性检查； 0x02：读卡时，R/W不做合法性检查
	 */
	unsigned char ucValidCheckMark;
	/* 业务功能代码  1HEX
	 * 注2：业务功能代码：描述不同的读卡后，SLE需要执行的业务功能，具体如下：
	 * 		0x01：进站；0x02：出站；0x03：售卡；0x04：补票；0x05：充值；
	 * 		0x06：退卡；0x07：替换旧卡；0x08：替换新卡；0x09：激活；
	 * 		0x10：延期；0x11：挂失；0x12：抵消；0x13：解挂；0x14：退资；0xFF：其他业务
	 */
	EM_SLE_TRANSACATION_TYPE emTransType;
	/* 付费区标志	1HEX    0x01：付费区；0x02：非付费区 */
	unsigned char ucAreaPaidMark;
	/* 当前时间 20140505060708 */
	char szTransTime[15];
	/* 天线寻卡标记 1HEX, bit0: A天线, bit1: B天线, bit2: C天线
	 *  1：只有A天线寻卡;2：只有B天线寻卡；3：双天线同时寻卡;	4:只有C天线寻卡; 5:A、C天线寻卡; 6:B、C天线寻卡;  7:A、B、C天线寻卡
	  */
	unsigned char ucAntennaMark;

	/* 历史交易读取标记 1HEX
	 * 注6：历史交易读取标记：0x00：表示不读取卡片内的历史交易记录； 0x01：表示读取卡片内的历史交易记录
	 */
	unsigned char ucGetTransLog;

	unsigned char szReserve[100];	//预留
}ST_TPU_READ_CARD_PARAM;

/* 读卡信息 */
typedef struct _ST_TPU_READ_CARD_INFO_
{
	/*卡物理编号*/
	char szPhyCardNo[21];

	/* 逻辑卡号 */
	char szLogicCardNo[21];

	/*卡面印刷号*/
	char szCardSurfaceNo[21];

	/* 卡数据长度	1HEX	返回的卡片信息的长度
	 * 卡片种类，描述卡片的应用大类别：
	 * 		0x01：城市通S50/S70卡片；      0x02：城市通CPU卡；
	 * 		0x11：一票通S50/S70卡片；      0x12：一票通UL卡；     0x13：一票通CPU卡；
	 * 这里暂时不定义枚举类型，因为TJ 0x13表示的就是 一票通纪念票；
	 * 会与SleDataSaveProcessor中获取UDSN有关（HRB 三种， TJ、BJ都是两种） */
	//GZ项目：车票主类型
	unsigned char ucCardPHType;

	/* [HRB] 产品类型
	 *     单程票(车票种类 0x00) : 0x64单程票； 0x69表示福利票
	 *     储值票(车票种类 0x0A) ： 0xA0 普通储值票;  0xA1	记名储值票; 0xA2	优惠老人票; 0xA3	优惠学生票; 0xA4	敬老卡;
	 *     计次票(车票种类 0x0B) ： 0xB0	普通计次票  0xB1	记名计次票  0xB2	计次月票
	 *     计时票(车票种类 0x0C) ： 0xC0	计时月票
	 *     工作票(车票种类 0x0D)  :  0xD0	特殊工作票  0xD1	普通工作票  0xD2	指定车站工作票  0xD3	限次工作票
	 *     城市通卡(车票种类 0x10)
	 *
	 *  该字段，在保存收益信息时，会同步到 Busi_Incoming 表中，在结算业务数据生成时， 依据该字段，来按类别（单程票、地铁储值票、城市通票）统计： 免费更新、付费更新
	 *
	 * */
	//GZ项目：车票子类型
	unsigned int uiProductyType;

	/* 车票产品子类型	1HEX */
	unsigned short usProductySubType;

	/* 车票产品种类
	 * 【HRB】 车票种类
	 *		0x00单程票； 0x01表示预付值票; 0x02 纪念票； 0x03日票；
	 *		0x0A 储值票；0x0B 计次票；0x0C计时票；0x0D工作票； 0x10城市通卡等；
	 **/
	unsigned int uiTicketFamily;

	/*产品名称中文信息*/
	char szProductNameCn[20];

	/*产品名称英文信息*/
	char szProductNameEn[40];

	/* 卡余额，可能为负数 */
	int iRemainingValue; //卡余额

	/* 卡押金 */
	unsigned int uiDepositValue;

	/* 车票产品种类
	 *    0x01 钱包; 0x02 计次； 0x03 定期；
	 *    0x04 无产品种类属性（既无余额，也无余次，也无定期属性）；  0xFF 未知产品类型 */
	EM_CSS_PRODUCTY_CATEGORY emCssProductyCategory;

	/* 车票发行商	2HEX 与导则约定有关的具体票种类型
	 *  一票通       CSS_PRODUCT_ISSUERID_ACC = 0x01
	 *  城市通： CSS_PRODUCT_ISSUERID_OCT = 0x99 */
	EM_CSS_PRODUCT_ISSUER_ID emCssProductIssuerId;

	/* 有效起始时间 char[15] */
	char szValidStartDateTime[15];

	/* 有效截止时间 char[15] */
	char szValidEndDateTime[15];

	/* 票卡旅程信息 */
	ST_CSS_CARDINFO_JOURNEY_INFO stCardJourneyInfo;

	/* 交易记录个数 */
	unsigned int uiTransLogCount;

	/* 交易记录循环体，按照最大10条处理 */
	ST_CSS_CARDINFO_TRANS_LOG_INFO stCardInfoTransLogArray[20];

	/* 付费区补票建议代码 1HEX 给操作员提供的补票建议 */
	unsigned char ucCpstCodeProposed;

	/* 建议补票金额	4HEX */
	unsigned int uiCompensationValueProposed;

	/* 建议退票金额	4HEX */
	unsigned int uiRefundTicketValueProposed;

	/* 退票折旧费	4HEX */
	unsigned int uiDepreciationCost;

	/* 建议退票手续费金额	4HEX */
	unsigned int uiRefundTicketServiceFeeProposed;

	/* 是否为大额卡	1HEX 0x00=否；0x01=是；  */
	unsigned char isBigMoneyCard;

	/*1HEX 0x00=否；0x01=是；*/
	unsigned char ucIsBlacklist;

	/*0x00 Nomal class,0x01:First class*/
	/*NN复用为退卡标记 0：不可退；1：可退*/
	unsigned char ucSeatFlag;

	/* 天线标志	1HEX	0x01：天线A寻到卡；0x02：天线B寻到卡  0x03 :天线C寻到卡*/
	unsigned char ucAntennaMark;

	/*补票类型：0x00表示补钱，0x01表示补次*/
	unsigned char ucCompensationValueTypeProposed;

	/*其它业务读卡时，表示是否为过期卡：0x00为有效期内，0x01为过有效期*/
	unsigned char ucRidesOverdue;

	/*计次、计值标志位:0x00：表示计值卡，0x01：表示计次卡*/
	unsigned char ucWalletType;

	//需要更新的UDSN 键值，由TPU 模块根据车票类型进行项目化实现，并传给数据存储模块直接保存
	unsigned int uiUdSeqKey;

	//需要更新的UDSN 键值，由TPU 模块根据车票类型进行项目化实现，并传给数据存储模块直接保存
	unsigned int uiSamSeqKey;

	//SAM 卡号
	char szSamId[21];	//处理这张车票的SAM

	/*预留*/
	char szReserved[5];//为添加 “票卡状态”cCardStatus，和“是否可售票”cIsIssueTicket 将该数组由8字节改为6字节 modify by Guozh 20151116

	/*是否可售票 0x00:不可售；0x01：可售；*/
	char cIsIssueTicket;

	/*票卡状态 add by Guozh 20150519*/
	char cCardStatus;

	//是否可充值 0x00:不可充；0x01：可充；*/
	char cIsAddValue;

	unsigned int uiSaleCardStation;

	/* 卡片信息，根据读卡结果，将原始卡片信息（读卡器可能以Bit返回） 转换后的结果
	 * 【HRB】对于HRB项目，读卡器返回的内容是按照Bit来进行处理的，
	 * 		  转换后，szCardInfoParsed中存储的为具有特定含义的可读格式（以Byte为单位）
	 *  在使用时，在具体项目实现类（如：CBusinessProcBizHrb）中，根据产品类型，进行强制转换或memcpy,以
	 *  转换为特定项目所需的格式进行处理，如票卡查询，需要将解析后的卡片结果，写入json文件；
	 **/
   int iCardInfoParsedLen;
   unsigned char szCardInfoParsed[2048];

}ST_TPU_READ_CARD_INFO;


typedef struct _SAM_INFO_
{
 /*SAM 卡类型*/
  unsigned char ucSamType;

  /*SAM 卡编号*/
  char szSamId[21];

}SAM_INFO_CSS;




typedef enum
{
	/* 01：桌面；02：BOM发行；03 TVM发行； 04 TVM 充值； 05 EQM；
	 * 	  07： AG进站； 08： AG出站； 09：AG双向；*/
	EM_BOM_DESK_TPU = 0x01,
	EM_BOM_ISSUE_TPU = 0x02,
	EM_TVM_ISSUE_TPU = 0x03,
	EM_TVM_RECHARGE_TPU = 0x04,
	EM_TCM_TPU = 0x05,
	EM_AGM_ENTRY_TPU = 0x07,
	EM_AGM_EXIT_TPU = 0x08,
	EM_AGM_DOUBLE_TPU = 0x09,

}EM_TPU_DEVICE_SUB_TYPE;

typedef struct _ST_TPU_VAR_INIT_PARAM_
{
	unsigned char szBomShiftID[4];//BOM班次
	unsigned char szOperaterID[10];// 操作员ID  【20160622_limg】 读卡器初始化参数中，将操作员由 4---> 10，以支持字符串格式传递
	char szOperationDate[9];	//  运营日期，取当前运营日,YYYYMMDD
	char szCurrentDate[9]; // 当前日历日期，取当前日期,YYYYMMDD
	bool bDeviceTestMode; // 设备测试状态 false:normal,true:testmode
	ST_SYSTEM_RUN_MODE stStationRunMode;	// 车站运营模式
}PACKED ST_TPU_VAR_INIT_PARAM;


//初始化TPU结构体
typedef struct _ST_TPU_INIT_PARAM_
{
	unsigned int uiDelayTime; 		// TPU 自动ABORT延时时间 或异步超时时间, 单位：豪秒

	/*
	 * 中软设备子类型，需要再具体项目中，进行转换
	 * 	  01：桌面；02：BOM发行；03 TVM发行； 04 TVM 充值； 05 EQM；
	 * 	  07： AG进站； 08： AG出站； 09：AG双向；
	 * */
	EM_TPU_DEVICE_SUB_TYPE emTpuSubType; //设备子类型
	EM_SLE_UNIT_TYPE emSleUnitType; //设备类型id
	int iSamCount;                  //Sam卡的数量

	/* 车站位置信息
	 *	【HRB】 该字段在Hrb项目中，未使用， 而是直接从DeviceCode中提取车站信息；
	 **/
	unsigned char szAgentCode[4];		// 运营公司或参与方

	unsigned char  AntennaConfig;		// add by chen liye	// 天线配置：0x00：单天线；0x01：双天线且天线A优先寻卡；0x02：双天线且天线B优先寻卡。
	EM_AG_APPLICATION_TYPE emTpuAgAisleType;	//通道类型,wangyzh添加AG闸机类型

	unsigned char szDeviceCode[20];	// 设备ID, 从SleSpec.xml获取
	unsigned int  emDeviceType; //设备类型, 从SleSpec.xml获取
	unsigned char szStationPLInfo[4];	//从SleSpec.xml获取

	ST_TPU_VAR_INIT_PARAM stVarParam;	//

	unsigned char szReserve[100];	//预留
}PACKED ST_TPU_INIT_PARAM;

////TPU参数类型
//typedef enum
//{
//	EM_TPU_PARAM_VERSION_TYPE_CURRENT   = 0x01,//当前参数
//	EM_TPU_PARAM_VERSION_TYPE_FUTURE	= 0x02,//将来参数
//}EM_TPU_PARAM_VERSION_TYPE;
//
typedef struct _ST_TPU_PARAM_VERSION_INFO_
{
	char szParaID[10];//参数类型ID
	char szParaVer[50];//版本号，字符串
	char szTakeEffectTime[15];  //YYYYMMDDHHMMSS
	EM_SLE_PARAM_VERSION_TYPE emVerType;		//0: 当前版本；1：将来版本

}ST_TPU_PARAM_VERSION_INFO;

typedef struct _ST_TPU_CALCULATE_PRICE_PARAM_
{
	unsigned int uiRawStation;	//出发车站
	unsigned int uiDestinationStation;	//目的车站
	unsigned short usProductyType;	//车票类型
	unsigned short usProductySubType;	//车票子类型，没有填0
	unsigned char ucCardType;	//卡片种类，没有填0
	unsigned char ucTicketLevel;	//舱位等级，没有填0
	unsigned char ucPassengerType;	//乘客类型，没有填0
	unsigned char szReserve[9];	//预留
}ST_TPU_CALCULATE_PRICE_PARAM;

typedef struct _SERVICE_COMMUNICATION_INFO
{
 /*IP地址*/
  char stIPAddress[25];

  /*端口号*/
  int iPort;

  /*超时时间*/
  int iOverTime;

}SERVICE_COMMUNICATION_INFO;

//通讯地址信息
typedef struct _ONLINE_BUSINESS_INFO
{
	SERVICE_COMMUNICATION_INFO stYPTCommInfo;//一票通通讯信息
	SERVICE_COMMUNICATION_INFO stOCTCommInfo;//一卡通通讯信息
}ONLINE_BUSINESS_INFO;

#endif /* AFCTPUPUBLIC_H_ */
