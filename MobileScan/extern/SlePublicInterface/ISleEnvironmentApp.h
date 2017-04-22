/*
 * IEnvironmentApp.h
 *
 *  Created on: Aug 21, 2014
 *      Author: root
 */

#ifndef IENVIRONMENTAPP_H_
#define IENVIRONMENTAPP_H_

#include "AfcPublic.h"
#include "ILedCommonFunction.h"
#include <string>
#include <loki/Singleton.h>
#include <loki/Factory.h>
#include <loki/Sequence.h>
using namespace Loki;//引用命名空间

using namespace std;



//定义LED显示出现方式类型枚举
typedef enum
{
	EM_SLE_LED_APPEAR_TYPE_NOW 					 = 0,      /*立即显示*/
	EM_SLE_LED_APPEAR_TYPE_LEFT_UNFOLD 			 = 1,	   /*左边展开*/
	EM_SLE_LED_APPEAR_TYPE_RIGHT_UNFOLD 		 = 2,	   /*右边展开*/
	EM_SLE_LED_APPEAR_TYPE_FROM_IN_TO_LEFT_RIGHT = 3,	   /*从中间向两边展开*/
	EM_SLE_LED_APPEAR_TYPE_FROM_IN_TO_UP_DOWN 	 = 4,	   /*从中间向上下展开*/
	EM_SLE_LED_APPEAR_TYPE_SEGMENT_UNFOLD 		 = 5,	   /*分段展开*/
	EM_SLE_LED_APPEAR_TYPE_LEFT_MOVE 			 = 6,	   /*向左边移出*/
	EM_SLE_LED_APPEAR_TYPE_RIGHT_MOVE			 = 7,	   /*向右边移出*/
	EM_SLE_LED_APPEAR_TYPE_UP_MOVE 				 = 8,      /*向上边移出*/
	EM_SLE_LED_APPEAR_TYPE_DOWN_MOVE 			 = 9,      /*向下边移出*/
	EM_SLE_LED_APPEAR_TYPE_UP_ROLL 				 = 10,     /*向上滚动*/
	EM_SLE_LED_APPEAR_TYPE_LEFT_ROLL 			 = 11,     /*向左滚动*/
	EM_SLE_LED_APPEAR_TYPE_RIGHT_ROLL	 		 = 12,     /*向右滚动*/
}EM_SLE_LED_APPEAR_TYPE;

//显示的水平对齐方式
typedef enum
{
	EM_SLE_LED_ALIGN_TYPE_LEFT   = 0,  /*左对齐*/
	EM_SLE_LED_ALIGN_TYPE_MIDDLE = 1,  /*水平居中*/
	EM_SLE_LED_ALIGN_TYPE_RIGHT  = 2,  /*右对齐*/
}EM_SLE_LED_ALIGN_TYPE;



//动态显示文字点数枚举类型
typedef enum
{
	EM_SLE_LED_TEXT_TYPE_8   = 0,  /*8点文字*/
	EM_SLE_LED_TEXT_TYPE_16  = 2,  /*16点文字*/
	EM_SLE_LED_TEXT_TYPE_24  = 3,  /*24点文字*/
	EM_SLE_LED_TEXT_TYPE_32  = 4,  /*32点文字*/
}EM_SLE_LED_TEXT_TYPE;


//Led显示信息结构体
typedef struct _ST_LED_SHOW_INFO_
{
	int iWndId;//窗口Id
	EM_LED_DOUBLE_SHOW_TYPE emLedDoubleShowType;//显示类型（静态显示，动态显示）
	EM_SLE_LED_APPEAR_TYPE emSleLedAppearType;//出现方式
	EM_SLE_LED_ALIGN_TYPE emSleLedAlignType;//对齐方式
	ST_SLE_LED_RGB_INFO stSleLedRgbInfo; //颜色结构体
	unsigned char ucTextSpeed;//速度,数值越小速度越快.
	unsigned short usTextDisplayTime;//停留时间,单位秒
	EM_SLE_LED_TEXT_TYPE emSleLedTextType;//动态显示文字点数
	BYTE ucFontSize;//静态显示文字大小
	unsigned char ucTextBuf[20480];//文字串以0x00作为结束字符
}ST_LED_SHOW_INFO;


/****************支付找零App的配置文件移动wangyzh start****************/
//加载XML文件中，支付策略配置
typedef struct _ST_PAYMENT_STRATEGY_
{
	//EM_SLE_TRANSACATION_TYPE emTransactionType;
	//int iTicketType;
	bool bPayWay[16];//bPayWay[0]:其他支付,bPayWay[1]:代金券支付,bPayWay[2]:网络支付,bPayWay[3]:手机支付,bPayWay[4]:银行卡支付,bPayWay[5]:硬币支付,bPayWay[6]:纸币支付,bPayWay[7]:充值卡支付,
	ST_DENO_INFO stBillPay;
	ST_DENO_INFO stCoinPay;
	bool bChangeType[2];//bChangeType[0]：硬币找零,bChangeType[1]:纸币找零
	bool bFraud;//乘客欺骗
}ST_PAYMENT_STRATEGY;
/*******************wangyzh end******************/

class ISleEnvironmentApp : public IAfcApp
{
public:

	/*! \fn 		SetOperatorCode
	* \brief        设置操作员
	* \param[in]    szOperatorCode  操作员代码，登出时，为空串
	* \return
	* \author		wugang
	* \date			2015-02-20
	*/
	virtual void SetOperatorCode(const char * szOperatorCode) = 0;

	/*! \fn 		GetOperatorCode
	* \brief        获取操作员，没有操作员时，返回空串
	* \param[in]
	* \return 		操作员代码
	* \author		wugang
	* \date			2015-02-20
	*/
	virtual const char * GetOperatorCode() = 0;

	/*! \fn 		GetDeviceType
	* \brief        获取设备类型
	* \param[in]
	* \return 		EM_SLE_DEVICE_TYPE枚举值
	* \author		wangzp
	* \date			2014-08-06
	*/
	virtual EM_SLE_DEVICE_TYPE GetDeviceType() = 0;

	/*! \fn 		PrintTicketFaultReceipt
	* \brief        打印售票故障单
	* \param[in]
	* \param[in]
	* \return 		true  打印成功    false  打印失败
	* \author		wangzp
	* \date			2014-08-06
	*/
//	virtual bool PrintToPassenger(const char * pszPrintText) = 0;

	/*! \fn 		PrintTextByTemplateId
	* \brief        按照模板文本信息打印
	* \param[in]	iTemplateId -- 指定打印的模板Id
	* \param[in]	pPrintObjectDataMap -- 数据库对应的信息记录
	* \return 		true  打印成功    false  打印失败
	* \author
	* \date			2014-08-06
	*/
	virtual bool PrintTextByTemplateId(int iVoucherType, bool bToPassenger, int iTemplateId, map<int, string> *pPrintObjectDataMap, bool bReprint) = 0;

//	virtual bool PrintToPassenger(int iTemplateId, std::map<int, std::string> *pPrintObjectDataMap) = 0;
//	virtual bool PrintToOperator(const char * pszPrintText) = 0;
	virtual bool ShowLedScreen(ST_LED_SHOW_INFO stLedShowInfo) = 0;


	/*! \fn 		GetRunDate
	 * \brief 获取运营日期
	 * \param[out] pszRunDate
	 * \return 		true  成功   false 失败
	 */
	virtual bool GetRunDate(char* pszRunDate) = 0;

	/*! \fn 		GetPaymentStrategyMap();
	* \brief 		获取支付找零策略Map
	* \param[in]  	no
	* \return 		支付找零策略Map
	* \author		wangyzh
	* \date			2015-01-13
	*/
	virtual map<WORD, ST_PAYMENT_STRATEGY> * GetPaymentStrategyMap() = 0;

	/*! \fn 		GetChangeBoxConfigInfoMap();
	* \brief 		获取找零钱箱配置信息Map
	* \param[in]  	no
	* \return 		找零钱箱配置信息Map
	* \author		wangyzh
	* \date			2015-01-13
	*/
	virtual map<DWORD, int> * GetChangeBoxConfigInfoMap() = 0;

	/*! \fn 		GetChangeBoxConfigInfoMap();
	* \brief 		获取找零顺序配置信息Map
	* \param[in]  	no
	* \return 		找零钱箱顺序配置信息Map
	* \author		wangyzh
	* \date			2015-01-13
	*/
	virtual map<int, ST_CASH_CONTAINER_LOCATION> * GetChangeOrderMap() = 0;

	/* int GetDeno(ST_CASH_CONTAINER_LOCATION stCashContainerLocation);
	 * 获取面额
	 * param[in]: 当前找零的箱子位置信息
	 * return:面额(0为失败)
	 * 2015-01-13
	 * author: wangyzh
	 */
	virtual int GetDeno(ST_CASH_CONTAINER_LOCATION stCashContainerLocation) = 0;

	virtual bool GetChangeCashboxLocationFromDeno(int iDeno, ST_CASH_CONTAINER_LOCATION * pCashboxLocation, int * piCashboxLocationCount) = 0;
	virtual int GetChangeDenoSet(int * piChangeDeno) = 0;

	virtual void GetCurrentRunDate(char * szRunDateBuf) = 0;

	/*! \fn 		GetDenoNoByDeno
	* \brief        根据找零面额获取币种编号
	* \param[in]    int iDeno    币种面额
	* \return 		币种编号
	* \author		wangzp
	* \date			2015-02-12
	*/
	virtual BYTE GetDenoNoByDeno(int iDeno) = 0;

	/*! \fn 		GetDenoByDenoNo
	* \brief        根据找零编号获取币种面额
	* \param[in]    BYTE ucDenoNo 币种编号
	* \return 		正常：面额    异常：0
	* \author		wangzp
	* \date			2015-02-12
	*/
	virtual int GetDenoByDenoNo(BYTE ucDenoNo) = 0;

	/*! \fn 		GetAllCashContainerList
	* \brief        获取所有钱箱列表
	* \param[out]    pstCashboxList 钱箱列表
	* \return 		无
	* \author		wugang
	* \date			2015-02-19
	*/
	virtual void GetAllCashContainerList(list<ST_CASH_CONTAINER_LOCATION> * pstCashboxList) = 0;

	/*! \fn 		GetAllTicketContainerList
	* \brief        获取所有票箱列表
	* \param[out]    pstTicketboxList 票箱列表
	* \return 		无
	* \author		wugang
	* \date			2015-02-19
	*/
	virtual void GetAllTicketContainerList(list<ST_TICKET_CONTAINER_LOCATION> * pstTicketboxList) = 0;

	/*! \fn 		GetCashContainerConfigInfo
	* \brief        获取指定钱箱的配置信息
	* \param[in]    stCashboxLocation 指定钱箱
	* \param[out]    pstCashboxConfigInfo 钱箱的配置信息
	* \return 		true，获取成功；false，获取失败
	* \author		wugang
	* \date			2015-02-19
	*/
	virtual bool GetCashContainerConfigInfo(ST_CASH_CONTAINER_LOCATION stCashboxLocation, ST_CONTAINER_CONFIG_INFO * pstCashboxConfigInfo) = 0;

	/*! \fn 		GetTicketContainerConfigInfo
	* \brief        获取指定票箱的配置信息
	* \param[in]    stTicketboxLocation 指定票箱
	* \param[out]    pstTicketboxConfigInfo 票箱的配置信息
	* \return 		true，获取成功；false，获取失败
	* \author		wugang
	* \date			2015-02-19
	*/

	virtual bool GetTicketContainerConfigInfo(ST_TICKET_CONTAINER_LOCATION stTicketboxLocation, ST_CONTAINER_CONFIG_INFO * pstTicketboxConfigInfo) = 0;
	/*! \fn 		PollingCashContainerRfidInfo
	* \brief        通过RFID检查钱箱是否存在
	* \param[in]    stCashboxLocation 指定钱箱
	* \param[out]
	* \return 		true，存在；false，不存在
	* \author		wugang
	* \date			2015-02-19
	*/
	virtual bool PollingCashContainerRfidInfo(ST_CASH_CONTAINER_LOCATION stCashboxLocation) = 0;

	/*! \fn 		ReadCashContainerRfidInfo
	* \brief        读取指定钱箱的RFID信息
	* \param[in]    stCashboxLocation 指定钱箱
	* \param[out]    pstCashboxRfidInfo 读取的RFID信息
	* \return 		true，读取成功；false，读取失败
	* \author		wugang
	* \date			2015-02-19
	*/
	virtual bool ReadCashContainerRfidInfo(ST_CASH_CONTAINER_LOCATION stCashboxLocation, ST_CASHBOX_RFID_INFO * pstCashboxRfidInfo) = 0;

	/*! \fn 		GetCashContainerRfidInfo
	* \brief        获取保存到内存的RFID信息
	* \param[in]    stCashboxLocation 指定钱箱
	* \param[out]    pstCashboxRfidInfo RFID信息
	* \return 		true，获取成功；false，获取失败
	* \author		wugang
	* \date			2015-02-19
	*/
	virtual bool GetCashContainerRfidInfo(ST_CASH_CONTAINER_LOCATION stCashboxLocation, ST_CASHBOX_RFID_INFO * pstCashboxRfidInfo) = 0;

	/*! \fn 		WriteCashContainerRfidInfo
	* \brief        写入指定钱箱的RFID信息
	* \param[in]    stCashboxLocation 指定钱箱
	* \param[out]    pstCashboxRfidInfo 写入的RFID信息
	* \return 		true，写入成功；false，写入失败
	* \author		wugang
	* \date			2015-02-19
	*/
	virtual bool WriteCashContainerRfidInfo(ST_CASH_CONTAINER_LOCATION stCashboxLocation, const ST_CASHBOX_RFID_INFO * pstCashboxRfidInfo) = 0;

	/*! \fn 		PollingCashContainerRfidInfo
	* \brief        通过RFID检查票箱是否存在
	* \param[in]    stTicketboxLocation 指定钱箱
	* \param[out]
	* \return 		true，存在；false，不存在
	* \author		wugang
	* \date			2015-02-19
	*/
	virtual bool PollingTicketContainerRfidInfo(ST_TICKET_CONTAINER_LOCATION stTicketboxLocation) = 0;

	/*! \fn 		ReadTicketContainerRfidInfo
	* \brief        读取指定票箱的RFID信息
	* \param[in]    stTicketboxLocation 指定票箱
	* \param[out]    pstTicketboxRfidInfo 读取的RFID信息
	* \return 		true，读取成功；false，读取失败
	* \author		wugang
	* \date			2015-02-19
	*/
	virtual bool ReadTicketContainerRfidInfo(ST_TICKET_CONTAINER_LOCATION stTicketboxLocation, ST_TICKETBOX_RFID_INFO * pstTicketboxRfidInfo) = 0;

	/*! \fn 		GetTicketContainerRfidInfo
	* \brief        获取保存到内存的RFID信息
	* \param[in]    stTicketboxLocation 指定票箱
	* \param[out]    pstTicketboxRfidInfo RFID信息
	* \return 		true，获取成功；false，获取失败
	* \author		wugang
	* \date			2015-02-19
	*/
	virtual bool GetTicketContainerRfidInfo(ST_TICKET_CONTAINER_LOCATION stTicketboxLocation, ST_TICKETBOX_RFID_INFO * pstTicketboxRfidInfo) = 0;

	/*! \fn 		WriteTicketContainerRfidInfo
	* \brief        写入指定票箱的RFID信息
	* \param[in]    stTicketboxLocation 指定票箱
	* \param[out]    pstTicketboxRfidInfo 写入的RFID信息
	* \return 		true，写入成功；false，写入失败
	* \author		wugang
	* \date			2015-02-19
	*/
	virtual bool WriteTicketContainerRfidInfo(ST_TICKET_CONTAINER_LOCATION stTicketboxLocation, const ST_TICKETBOX_RFID_INFO * pstTicketboxRfidInfo) = 0;

	/*! \fn 		SetSystemPaymentControl
	*
	* \brief        设置系统支付控制
	* \param[in]    ST_TVM_PAY_TYPE stPaymentMethod    支付方式
	* \return 		none
	* \author		wangzp
	* \date			2014-09-17
	*/
	virtual void GetSystemPaymentControl(ST_TVM_PAY_TYPE * pstPaymentMethod) = 0;

	/* int GetTicketType(ST_TICKET_CONTAINER_LOCATION stTicketContainerLocation);
	 * 获取票箱内车票类型
	 * param[in]: 当前票箱位置信息
	 * return:面额(0为失败)
	 * 2015-01-13
	 * author: wugang
	 */
	virtual DWORD GetTicketType(ST_TICKET_CONTAINER_LOCATION stTicketContainerLocation) = 0;

	/* void EventLog(EM_SLE_EVENT_TYPE emEventType, const BYTE * szParam, int iParamLength)
	 * 记录事件
	 * param[in]: emEventType 事件类型ID
	 * param[in]: szParam 事件参数， NULL表示没有参数
	 * param[in]: iParamLength 事件参数长度
	 * return:
	 * 2015-04-10
	 * author: wugang
	 */
	virtual void EventLog(EM_SLE_EVENT_TYPE emEventType, const BYTE * szParam, int iParamLength) = 0;

	/*! \fn 		LogPassengerAction
	* \brief        记录乘客动作相关日志
	* \param[in]    emActionType 乘客动作类型
	* \param[in]   pParam 动作参数
	* \return
	* \author		wugang
	* \date			2015-04-11
	*/
	virtual void LogPassengerAction(EM_SLE_PASSENGER_ACTION_TYPE emActionType, const void * pParam) = 0;


	/*! \fn 		CheckSoftVersion;
	* \brief        获取并检查软件版本信息
	* \return 		true: 检查OK;  false: 版本无效
	* \author       wugang
	* \date			2015-04-12
	*/
	virtual bool CheckSoftVersion() = 0;

	/*! \fn 		GetVersionRecordList;
	* \brief        获取版本信息list
	* \return 		list, 不得改变
	* \author       wugang
	* \date			2015-04-12
	*/
	virtual list<ST_CSS_VERSION_INFO>  * GetVersionRecordList() = 0;

	/*! \fn 		RefreshVersionRecordList;
	* \brief        重新加载获取版本信息list
	* \return 		无
	* \author       wugang
	* \date			2015-04-12
	*/
	virtual void RefreshVersionRecordList() = 0;


	/*! \fn 		GetBizCardType;
	* \brief        返回当前业务支持的卡座类型
	* \param[in]	当前的业务类型(1:售票，2：充值，3：查询)
	* \param[out]	当前业务支持的卡座类型
	* \return 		bool true:成功 false：失败
	* \author       wangyzh
	* \date			2015-07-13
	*/
	virtual bool GetBizCardType(int iBizType, EM_SVTCARD_HOLDER_TYPE *pemSvtCardHolderType) = 0;

	//读取当前的结算流程配置longjg
	virtual bool GetBalanceCfg(map<int, ST_BALANCE_TASK_INFO>* pstBalanceTaskMap) = 0;

	//更新当前的结算流程配置longjg
	virtual bool UpdateBalanceCfg(map<int, ST_BALANCE_TASK_INFO> stBalanceTaskMap) = 0;
protected:
	CLogOper2 *m_pBizLog; /*!< */


};


class CLogOper2;
typedef Loki::SingletonHolder
<
	Loki::Factory<ISleEnvironmentApp, std::string, Seq<CLogOper2*> >,
	CreateUsingNew, Loki::LongevityLifetime::DieAsSmallObjectChild
> SleEnvironmentAppFactory;

#define REGISTER_AFC_SLEENVIRONMENTAPP_OBJECT(className)                                                      \
namespace {                                                                            \
	ISleEnvironmentApp* createSleEnvironmentAppBase(CLogOper2 *m_pBizLog) { return new className(m_pBizLog); }                                              \
const bool SleEnvironmentAppFactory__ = SleEnvironmentAppFactory::Instance().Register( #className, createSleEnvironmentAppBase );  \
}
class ISleEnvironmentApp;
extern	ISleEnvironmentApp *g_pIAfcSleEnvironmentApp;

#endif /* IENVIRONMENTAPP_H_ */
