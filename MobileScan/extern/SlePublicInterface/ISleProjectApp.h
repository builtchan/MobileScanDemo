/*
 * ITvmUiApp.h
 *
 *  Created on: Aug 20, 2014
 *      Author: root
 */

#ifndef ISLEPROJECTAPP_H_
#define ISLEPROJECTAPP_H_

#include "AfcPublic.h"
#include "IRfidCommonFunction.h"
#include "IGateWithDioCommonFunction.h"
#include "ITPUCommonFunction.h"
#include "ISleBizDataGenApp.h"
#include "ipcpublic.h"
#include "ISleEnvironmentApp.h"

#include <loki/Singleton.h>
#include <loki/Factory.h>
#include <loki/Sequence.h>
using namespace Loki;//引用命名空间

typedef enum
{
	EM_BUZZER_ALARM = 1,
	EM_SOUND_ALARM = 2,
	EM_OTHER_ALARM = 3,
}EM_ALARM_TYPE;

typedef enum
{
	EM_ALARM_TYPE_MAINTENCE_DOOR_TIMEOUT = 1,   			 //维修门打开超时时间未登录
	EM_ALARM_TYPE_CASH_DOOR_TIMEOUT = 2,        			//现金安全打开
	EM_ALARM_TYPE_ILLEGAL_LOGIN = 3,            			//非法登录（即超过规定次数的非法输入)
	EM_ALARM_TYPE_ILLEGAL_CHANGE_CASH_CONTAINER = 4,    	//非法更换现金容器
	EM_ALARM_TYPE_ILLEGAL_CHANGE_TICKET_CONTAINER = 5,    	//非法更换票卡容器
	EM_ALARM_TYPE_LOW_POWER_LEVEL = 6,						//低电量报警
}EM_ALARM_TRIGGER_TYPE;


typedef enum
{
	EM_WAV_TYPE_INSERT_CARD = 1,   			 //请插卡

}EM_WAV_TYPE;


class ISleProjectApp : public IAfcApp
{
public:
	/*! \fn 		PowerOffHandle
	* \brief        市电断开处理
	* \param[in]    EM_ALARM_TYPE emAlarm  报警类型
	* \param[out]
	* \return 		true，存在；false，不存在
	* \author	    wangzp
	* \date			2015-08-25
	*/
	virtual bool PowerOffHandle() = 0;

	/*! \fn 		AlarmHandle
	* \brief        报警处理
	* \param[in]    EM_ALARM_TYPE emAlarm  报警类型
	* \param[out]
	* \return 		true，存在；false，不存在
	* \author	    wangzp
	* \date			2015-07-04
	*/
	virtual bool AlarmHandle(EM_ALARM_TRIGGER_TYPE emAlarm, bool bOpen) = 0;


	/*! \fn 		WavHandle
	* \brief        声音处理
	* \param[in]    EM_WAV_TYPE emWavType  报警类型
	* \param[out]
	* \return 		true，存在；false，不存在
	* \author	    lyp
	* \date			2017-04-04
	*/
	virtual bool WavHandle(EM_WAV_TYPE emWavType, bool bOpen) = 0;

	/*! \fn 		TvmFaultTransHandle
	* \brief        TVM故障交易处理
	* \param[in]    const ST_TVM_PASSENGER_TRANS * pstTvmPassengerTransResult   交易结果
	* \param[out]
	* \return 		true，存在；false，不存在
	* \author	    wangzp
	* \date			2015-07-04
	*/
	virtual bool TvmFaultTransHandle(const ST_TVM_PASSENGER_TRANS * pstTvmPassengerTransResult, EM_TRANSACATION_RESULT emTransResult) = 0;

	/*! \fn 		PollingCashContainerRfidInfo
	* \brief        通过RFID检查钱箱是否存在
	* \param[in]    stCashboxLocation 指定钱箱
	* \param[out]
	* \return 		true，存在；false，不存在
	* \author		wugang
	* \date			2015-02-19
	*/
	virtual bool PollingCashContainerRfidInfo(IRfidCommonFunction * pRfidReader, ST_CASH_CONTAINER_LOCATION stCashboxLocation) = 0;

	/*! \fn 		ReadCashContainerRfidInfo
	* \brief        读取指定钱箱的RFID信息
	* \param[in]    stCashboxLocation 指定钱箱
	* \param[out]    pstCashboxRfidInfo 读取的RFID信息
	* \return 		true，读取成功；false，读取失败
	* \author		wugang
	* \date			2015-02-19
	*/
	virtual bool ReadCashContainerRfidInfo(IRfidCommonFunction * pRfidReader, ST_CASH_CONTAINER_LOCATION stCashboxLocation, ST_CASHBOX_RFID_INFO * pstCashboxRfidInfo) = 0;

	/*! \fn 		WriteCashContainerRfidInfo
	* \brief        写入指定钱箱的RFID信息
	* \param[in]    stCashboxLocation 指定钱箱
	* \param[out]    pstCashboxRfidInfo 写入的RFID信息
	* \return 		true，写入成功；false，写入失败
	* \author		wugang
	* \date			2015-02-19
	*/
	virtual bool WriteCashContainerRfidInfo(IRfidCommonFunction * pRfidReader, ST_CASH_CONTAINER_LOCATION stCashboxLocation, const ST_CASHBOX_RFID_INFO * pstCashboxRfidInfo) = 0;

	/*! \fn 		PollingCashContainerRfidInfo
	* \brief        通过RFID检查票箱是否存在
	* \param[in]    stTicketboxLocation 指定钱箱
	* \param[out]
	* \return 		true，存在；false，不存在
	* \author		wugang
	* \date			2015-02-19
	*/
	virtual bool PollingTicketContainerRfidInfo(IRfidCommonFunction * pRfidReader, ST_TICKET_CONTAINER_LOCATION stTicketboxLocation) = 0;

	/*! \fn 		ReadTicketContainerRfidInfo
	* \brief        读取指定票箱的RFID信息
	* \param[in]    stTicketboxLocation 指定票箱
	* \param[out]    pstTicketboxRfidInfo 读取的RFID信息
	* \return 		true，读取成功；false，读取失败
	* \author		wugang
	* \date			2015-02-19
	*/
	virtual bool ReadTicketContainerRfidInfo(IRfidCommonFunction * pRfidReader, ST_TICKET_CONTAINER_LOCATION stTicketboxLocation, ST_TICKETBOX_RFID_INFO * pstTicketboxRfidInfo) = 0;

	/*! \fn 		WriteTicketContainerRfidInfo
	* \brief        写入指定票箱的RFID信息
	* \param[in]    stTicketboxLocation 指定票箱
	* \param[out]    pstTicketboxRfidInfo 写入的RFID信息
	* \return 		true，写入成功；false，写入失败
	* \author		wugang
	* \date			2015-02-19
	*/
	virtual bool WriteTicketContainerRfidInfo(IRfidCommonFunction * pRfidReader, ST_TICKET_CONTAINER_LOCATION stTicketboxLocation, const ST_TICKETBOX_RFID_INFO * pstTicketboxRfidInfo) = 0;

	/*! \fn 		GetBusinessUdsnKey
	* \brief        获取业务UDSN的key值
	* \param[in]    emBusinessType 业务类型
	* \param[in]    emDeviceType 设备类型
	* \param[in]    stCashboxLocation 钱箱ID
	* \param[in]    stTicketboxLocation 票箱ID
	* \return 		key值
	* \author		wugang
	* \date			2015-04-01
	*/
	virtual int GetBusinessUdsnKey(EM_SLE_BUSINESS_TYPE emBusinessType, ST_CASH_CONTAINER_LOCATION stCashboxLocation) = 0;
	virtual int GetBusinessUdsnKey(EM_SLE_BUSINESS_TYPE emBusinessType, ST_TICKET_CONTAINER_LOCATION stTicketboxLocation) = 0;
	virtual int GetBusinessUdsnKey(EM_SLE_BUSINESS_TYPE emBusinessType) = 0;

	/*! \fn 		GetBusinessUdsnKey
	* \brief        获取事件UDSN的key值
	* \param[in]    emEventType 事件类型
	* \param[in]    emDeviceType 设备类型
	* \return 		key值
	* \author		wugang
	* \date			2015-04-01
	*/
	virtual int GetEventUdsnKey(EM_SLE_EVENT_TYPE emEventType) = 0;

	/*! \fn 		GetAgTransOkLampColor
	* \brief        AG交易结束后，亮灯
	* \param[in]    pstTransResultSnapshot 交易结果信息
	* \param[in]    pstBusiContextData 交易上下文信息
	* \param[in]    pDioUnit DIO对象
	* \return
	* \author		wugang
	* \date			2015-04-10
	*/
	virtual void AgTransLampAndSound(ST_TPU_TRANS_RESULT * pstTransResultSnapshot, ST_BUSINESS_CONTEXT_DATA *pstBusiContextData, IGateWithDioCommonFunction * pDioUnit) = 0;

	/*! \fn 		AgStateLampAndSound
	* \brief        状态变化时
	* \param[in]    stDoorStatus 门模块状态
	* \param[in]    stSystemStatus 系统状态
	* \param[in]    pDioUnit DIO对象
	* \return
	* \author		wugang
	* \date			2015-04-10
	*/
	virtual void AgStateLampAndSound(ST_DOOR_UNIT_STATUS stDoorStatus, ST_AG_SYSTEM_STATUS stSystemStatus, IGateWithDioCommonFunction * pDioUnit) = 0;

	/*! \fn 		MakeProjectEventData
	* \brief        生成项目化事件数据
	* \param[in]    pstEventRecord 事件记录
	* \param[out]   pstEventRecord 事件记录
	* \return
	* \author		wugang
	* \date			2015-04-10
	*/
	virtual void MakeProjectEventData(ST_EVENT_RECORD * pstEventRecord) = 0;

	/*! \fn 		LogPassengerAction
	* \brief        记录乘客动作相关日志
	* \param[in]    emActionType 乘客动作类型
	* \param[out]   pParam 动作参数
	* \return
	* \author		wugang
	* \date			2015-04-11
	*/
	virtual void LogPassengerAction(EM_SLE_PASSENGER_ACTION_TYPE emActionType, const void * pParam) = 0;

	/*! \fn 		PrintCashboxOperationReceipt
	* \brief        打印操作钱箱票据
	* \param[in]    pstCashboxOperationInfo 操作钱箱信息
	* \param[out]   无
	* \return
	* \author		wugang
	* \date			2015-04-11
	*/
	virtual void PrintCashboxOperationReceipt(list<ST_CASHBOX_CHANGE_INFO> * pstCashboxOperationInfoList) = 0;

	/*! \fn 		PrintTicketboxOperationReceipt
	* \brief        打印操作票箱票据
	* \param[in]    pstTicketboxOperationInfo 操作票箱信息
	* \param[out]   无
	* \return
	* \author		wugang
	* \date			2015-04-11
	*/
	virtual void PrintTicketboxOperationReceipt(list<ST_TICKETBOX_CHANGE_INFO> * pstTicketboxOperationInfoList) = 0;

	/*! \fn 		RePrintReceipt
	* \brief        单据补打
	* \param[in]    DWORD uiUSDN    票据USDN
	* \param[in]    DWORD uiReceiptType    单据类型
	* \return       true 补打成功    false 补打失败
	* \author		wangzp
	* \date			2015-04-11
	*/
	virtual bool RePrintReceipt(DWORD uiUSDN, DWORD uiReceiptType) = 0;

	/*! \fn 		GenTvmOperBalanceBizData
	* \brief        生成TVM结帐业务数据
	* \param[in]    list<ST_IPCMSG_ADDITIONAL_RECORD> * pstIpcRecord
	* \param[out]   无
	* \return
	* \author		wangzp
	* \date			2015-04-11
	*/
	//virtual bool GenTvmOperBalanceBizData(list<ST_IPCMSG_ADDITIONAL_RECORD> * pstIpcRecord) = 0;

	/*! \fn 		GenTvmOperBalanceReceiptBizData
	* \brief        生成TVM结帐小单业务数据
	* \param[in]    pstTicketboxOperationInfo 操作票箱信息
	* \param[out]   无
	* \return
	* \author		wangzp
	* \date			2015-04-11
	*/
	//virtual bool GenTvmOperBalanceReceiptBizData(list<ST_IPCMSG_ADDITIONAL_RECORD> * pstIpcRecord) = 0;

	/*! \fn 		PrintTvmOperBalanceReceipt
	* \brief        打印TVM结帐单据
	* \param[in]    pstTicketboxOperationInfo 操作票箱信息
	* \param[out]   无
	* \return
	* \author		wangzp
	* \date			2015-04-11
	*/
	//virtual void PrintTvmOperBalanceReceipt(list<ST_IPCMSG_ADDITIONAL_RECORD> * pstIpcRecord) = 0;

	/*! \fn 		TvmBalanceHandle
	* \brief        TVM收益结算处理，该函数在清空之前做，避免后续清空或更换卡住导致无法对账，该部分只包含交易中参与对账的信息，例如：发售，找零，接收金额和数量
	* \param[in]    bool bPrint 是否打印单据
	* \param[in]    bool bSave 是否保存数据
	* \param[out]   ST_IPCMSG_ADDITIONAL_RECORD * pstIpcRecord
	* \return
	* \author		wangzp
	* \date			2016-07-25
	*/
	virtual bool TvmSettlementHandle(EM_SETTLEMENT_TRIGGERTYPE_DEF emType, list<ST_IPCMSG_ADDITIONAL_RECORD> * pstIpcRecord) = 0;


	/*! \fn 		TvmBalanceHandle
	* \brief        TVM结算处理
	* \param[in]    EM_BALANCE_TYPE_DEF emBalanceType    结算类型
	* \param[out]   char * pszBalanceInfo    结算信息
	* \param[out]   int * piBalanceInfoLen    结算信息长度
	* \return
	* \author		wangzp
	* \date			2015-05-12
	*/
	virtual bool TvmBalanceHandle(EM_SETTLEMENT_TRIGGERTYPE_DEF emSettlementTriggerType, list<ST_IPCMSG_ADDITIONAL_RECORD> * pstIpcRecord, string strRemark = "") = 0;

	/*! \fn 		TvmAuditDataHandle
	* \brief        生成TVM审计数据
	* \param[in]
	* \param[out]   无
	* \return
	* \author		wangzp
	* \date			2015-05-23
	*/
	virtual bool TvmAuditDataHandle() = 0;

	/*! \fn 		AGAuditDataHandle
	* \brief        生成AG审计数据
	* \param[in]
	* \param[out]   无
	* \return
	* \author		wangzp
	* \date			2015-05-24
	*/
	virtual bool AgAuditDataHandle() = 0;

	/*! \fn 		CanDoParamSwitchByToOos
	* \brief        是否可以进行参数生效
	* \param[in]
	* \param[out]   无
	* \return
	* \author		wangzp
	* \date			2015-05-24
	*/
	virtual bool CanDoParamSwitchByToOos() = 0;

	/*! \fn 		ParamSwitch
	* \brief        进行参数生效
	* \param[in]
	* \param[out]   无
	* \return
	* \author		wangzp
	* \date			2015-05-24
	*/
	virtual bool ParamSwitch() = 0;

	/*! \fn 		SetTpuRunDate
	* \brief        进行TPU运营日期设置切换
	* \param[in]
	* \param[out]   无
	* \return
	* \author		longjg
	* \date			2016-11-18
	*/
	virtual void SetTpuRunDate() = 0;

	/*! \fn 		SetParamSwitchInfo
	* \brief        设置参数切换信息
	* \param[in]
	* \param[out]   无
	* \return
	* \author		wangzp
	* \date			2015-05-24
	*/
	virtual bool SetParamSwitchInfo(bool bRestart) = 0;


	/*! \fn 		TpuSoftwareVerAutoUpdate
	* \brief        Tpu软件版本自动比对升级
	* \return		true/false
	* \author		longjg
	* \date			2015-08-05
	*/
	virtual bool TpuSoftwareVerAutoUpdate() = 0;

	/*! \fn 		TpuParamVerAutoUpdate
	* \brief        Tpu参数版本自动比对升级
	* \return		true/false
	* \author		longjg
	* \date			2015-08-05
	*/
	virtual bool TpuParamVerAutoUpdate() = 0;

	/*! \fn 		GetAllTpuForAutoUpdate
	* \brief        获取当前设备所有TPU对象
	* \return		true/false
	* \author		longjg
	* \date			2015-08-05
	*/
//	virtual void GetAllTpuForAutoUpdate(list<ITPUCommonFunction *>* pcTpuList) = 0;

	virtual bool IsNeedDownloadParamForTpu(ST_TPU_PARAM_VERSION_INFO stTpuParamVerInfo, ST_SLE_SINGLE_PARAM_VERSION_INFO stSleSingleParamVerInfo) = 0;

	/*! \fn 		RechargePrintVoucher
	* \brief        充值打印单据
	* \param[in]  	DWORD uiTransID    交易序列号
	* \param[in]	读卡信息的结构体
	* \param[in]  	ST_TVM_RECHARGE_REQUEST_INFO    充值信息
	* \return 		true，存在；false，不存在
	* \author	    wangyzh
	* \date			2015-07-30
	*/
	virtual bool RechargePrintVoucher(DWORD uiTransID, const ST_TPU_READ_CARD_INFO *pstTpuReadCardInfo, ST_TVM_RECHARGE_REQUEST_INFO  stRechargeInfo) = 0;


	/*! \fn 		RechargePrintVoucher
	* \brief        充值故障打印单据
	* \param[in]  	DWORD uiTransID    交易序列号
	* \param[in]	读卡信息的结构体
	* \param[in]  	乘客交易结果结构体
	* \return 		true，存在；false，不存在
	* \author	    wangyzh
	* \date			2015-07-31
	*/
	virtual bool RechargeFaultPrintVoucher(DWORD uiTransID, const ST_TPU_READ_CARD_INFO *pstTpuReadCardInfo, const ST_TVM_PASSENGER_TRANS * pstTvmPassengerTransResult, ST_TPU_TRANS_RESULT stTransResultSnapshot) = 0;

	virtual bool RechargeAbnormalPrintVoucher(DWORD uiTransID, const ST_TPU_READ_CARD_INFO *pstTpuReadCardInfo, ST_TVM_RECHARGE_REQUEST_INFO stRechargeInfo, bool bAcceptCashResult) = 0;
	/*! \fn 		LedShowParam
	* \brief        条屏显示参数函数
	* \param[in]	是否显示的标记
	* \param[in]	条屏显示的入参,
	* \return		bool true为成功  false为失败
	* \author		wangyzh
	* \date			2015-08-04
	*/
	virtual bool LedShowParam(bool bShow, ST_LED_SHOW_INFO stLedShowInfo) = 0;

	/*! \fn 		SvtPaySjtFaultVoucher
	* \brief        储值卡购买单程票故障单据
	* \param[in]  	DWORD uiTransID    交易序列号
	* \param[in]	读卡信息的结构体
	* \param[in]  	乘客售票结构体
	* \return		bool true为成功  false为失败
	* \author		wangyzh
	* \date			2015-08-04
	*/
	virtual bool SvtPaySjtFaultVoucher(DWORD uiTransID, const ST_TPU_READ_CARD_INFO *pstTpuReadCardInfo, ST_TVM_VENDING_REQUEST_INFO stVendingInfo, int iWriteTicketOKCount, int iOutTicketOKCount, bool bChangeResult) = 0;



protected:
	CLogOper2 *m_pBizLog; /*!< */
};

class CLogOper2;
typedef Loki::SingletonHolder
<
	Loki::Factory<ISleProjectApp, std::string, Seq<CLogOper2*> >,
	CreateUsingNew, Loki::LongevityLifetime::DieAsSmallObjectChild
> SleProjectAppFactory;

#define REGISTER_AFC_SLEPROJECTAPP_OBJECT(className)                                                      \
namespace {                                                                            \
	ISleProjectApp* createSleProjectAppBase(CLogOper2 *m_pBizLog) { return new className(m_pBizLog); }                                              \
const bool SleProjectAppFactory__ = SleProjectAppFactory::Instance().Register( #className, createSleProjectAppBase );  \
}
class ISleProjectApp;
extern	ISleProjectApp *g_pIAfcSleProjectApp;


#endif /* ISLEPROJECTAPP_H_ */
