/*
 * CSleDataApp.h
 *
 *  Created on: Aug 20, 2014
 *      Author: root
 */

#ifndef CSLEDATAAPP_H_
#define CSLEDATAAPP_H_

#include <loki/Singleton.h>
#include <loki/Factory.h>
#include <loki/Sequence.h>


#include "IAfcApp.h"
#include "TransCashData.h"
#include "TransTicketData.h"
#include "AfcPublic.h"

#include "SleParamAttriDefPublic.h"

using namespace Loki;//引用命名空间
using namespace std;

class ISleDataApp : public IAfcApp
{
public:

	/*! \fn 		SaveBizDataRecord
	* \brief        保存业务数据记录
	* \param[in]    const ST_BIZ_DATA_RECORD * pstBizDataRecord    业务数据记录
	* \return
	* \author		wangzp
	* \date			2014-10-10
	*/
	virtual bool SaveBizDataRecord(const ST_BIZ_DATA_RECORD * pstBizDataRecord)=0;

	virtual int  UpdateRunDate(const char * pszDate) = 0;
	/*! \fn 		SavePetCardConsumeUD
	* \brief        保存储值卡消费UD
	* \param[in]    ST_UD_DATA_CSS stUDDataCss
	* \return 		true  保存成功    false  保存失败
	* \author		wangzp
	* \date			2014-08-06
	*/
	virtual bool SavePetCardConsumeUD(ST_UD_DATA_CSS stUDDataCss) = 0;

	/*! \fn 		SaveTicketIssueUD
	* \brief        保存票卡发售UD
	* \param[in]    int iPrice         单价
	* \param[in]    int iTicketCount   数量
	* \return 		true  显示成功    false  显示失败
	* \author		wangzp
	* \date			2014-08-06
	*/
	virtual bool SaveTicketIssueUD(ST_BUSINESS_CONTEXT_DATA *pstBusiContextData, ST_TPU_TRANS_RESULT *pstTransResult, ST_TICKET_TRANS_DETAIL_INFO * pstTicketTransDetailInfo) = 0;

	/*! \fn 		SaveAgTransRecord
	* \brief        保存AG交易记录
	* \param[in]    ST_TICKETBOX_CHANGE_INFO * pstTicketBoxChangeInfo    票卡容器位置
	* \return
	* \author		wangzp
	* \date			2014-10-10
	*/
	virtual bool SaveAgTransRecord(ST_AG_PASSENGER_TRANS * pstAgPassengerTransInfo)=0;
	/*! \fn 		SaveTvmTransRecord
	* \brief        保存TVM交易记录
	* \param[in]    ST_TICKETBOX_CHANGE_INFO * pstTicketBoxChangeInfo    票卡容器位置
	* \return
	* \author
	* \date			2014-10-10
	*/
	virtual bool SaveTvmTransRecord(ST_TVM_PASSENGER_TRANS* pstTvmPassengerTransInfo, EM_TRANSACATION_RESULT emTransacationResult) = 0;

	/*! \fn 		SaveTicketTransLogAndReserve
	* \brief        保存票卡交易记录及库存
	* \param[in]    CTransCashData * pcTransCashData
	* \param[in]    bool bMaintenceTestFlag 维修测试标记
	* \return 		true  显示成功    false  显示失败
	* \author
	* \date			2014-08-06
	*/
	virtual bool SaveCashTransInfo(unsigned int uiTransID, CTransCashData * pcTransCashData, bool bMaintenceTestFlag) = 0;
	virtual bool SaveTicketTransInfo(unsigned int uiTransID, CTransTicketData * pcTransTicketData, bool bMaintenceTestFlag) = 0;

    /*! \fn 		GetUdsn
	 * \brief       获取UDSN序列号
	 * param in bAdd 是否先递增在返回，默认先递增在返回
	*/
	virtual ulong GetUdsn(EM_SEQ_TYPE emSeqType, bool bAdd = true)=0;

	/*! \fn 		GetUdsn
	 * \brief       更新UDSN序列号
	 */
	virtual bool UpdateUdsn(EM_SEQ_TYPE emSeqType, int iIncreament) = 0;

	/*! \fn 		GetSAMsn
	 * \brief       获取SAM卡SN序列号
	 */
	virtual ulong GetSAMsn() = 0;


	/*! \fn 		GetCashboxInfo
	* 	\brief      获取指定位置的钱箱信息
	* 	\param[in]  ST_CASH_CONTAINER_LOCATION stCashContainerLocation    钱箱位置
	* 	\param[out] ST_CASHBOX_INFO *pstCashboxInfo 指定位置的钱箱信息
	*   \return     成功，返回COMMOM_FUNC_OK； 失败，返回COMMOM_FUNC_FAIL；
	* 	\author
	* 	\date		2015-02-09
	*/
	virtual int GetCashboxInfo(ST_CASH_CONTAINER_LOCATION stCashboxLocation, ST_CASHBOX_INFO *pstCashboxInfo) = 0;
	virtual int SetCashboxInfo(ST_CASH_CONTAINER_LOCATION stCashboxLocation, ST_CASHBOX_INFO stCashboxInfo) = 0;

	virtual int GetTicketboxInfo(ST_TICKET_CONTAINER_LOCATION stTicketboxLocation, ST_TICKETBOX_INFO *pstCashboxInfo) = 0;
	virtual int SetTicketboxInfo(ST_TICKET_CONTAINER_LOCATION stTicketboxLocation, ST_TICKETBOX_INFO stCashboxInfo) = 0;


	/*! \fn 		SaveCashContainerChangeRecord
	* \brief        保存钱箱更换业务记录（业务数据等）
	* \param[in]    ST_TICKET_CONTAINER_LOCATION * pstTicketContainerLocation    票卡容器位置
	* \return
	* \author		wangzp
	* \date			2014-10-10
	*/
	virtual bool SaveCashContainerChangeRecord(ST_CASHBOX_CHANGE_INFO * pstCashboxChangeInfo) = 0;
	virtual bool SaveCashContainerChangeRecord(list<ST_CASHBOX_CHANGE_INFO> *pstCashboxChangeInfoList) = 0;

	/*! \fn 		SaveTicContainerChangeRecord
	* \brief        保存票箱更换记录
	* \param[in]    ST_TICKETBOX_CHANGE_INFO * pstTicketBoxChangeInfo    票卡容器位置
	* \return
	* \author		wangzp
	* \date			2014-10-10
	*/
	virtual bool SaveTicContainerChangeRecord(ST_TICKETBOX_CHANGE_INFO * pstTicketBoxChangeInfo)=0;
	virtual bool SaveTicContainerChangeRecord(list<ST_TICKETBOX_CHANGE_INFO> * pstTicketBoxChangeInfoList)=0;

	/*! \fn 		SavePrintVoucherInfo
	* \brief        保存打印票据信息
	* \param[in]    ST_PRINT_VOUCHER_INFO * pstPrintVoucherInfo   票据信息
	* \param[in]    map<int, string> * pPrintObjectDataMap   打印数据
	* \return
	* \author		wangzp
	* \date			2014-10-10
	*/
	virtual bool SavePrintVoucherInfo(ST_PRINT_VOUCHER_INFO * pstPrintVoucherInfo, map<int, string> * pPrintObjectDataMap)=0;

	/*! \fn 		GetPrintVoucherInfo
	* \brief        获取打印票据信息
	* \param[in]    DWORD uiUdsn  记录标识号
	* \param[out]    ST_PRINT_VOUCHER_INFO * pstPrintVoucherInfo   票据信息
	* \param[out]    map<int, string> * pPrintObjectDataMap   打印数据
	* \return
	* \author		wangzp
	* \date			2014-10-10
	*/
	virtual bool GetPrintVoucherInfo(DWORD uiUdsn, DWORD uiVoucherType, ST_PRINT_VOUCHER_INFO * pstPrintVoucherInfo, map<int, string> * pPrintObjectDataMap)=0;

	/*! \fn 		GetPrintVoucherInfo
	* \brief        获取一段连续的寄存器数据
	* \param[in,out]    map<DWORD, DWORD> * puiRegDataMap : <index, value>, index为入参，value为出参
	* \return
	* \author
	* \date			2015-05-12
	*/
	virtual bool GetRegisterData(map<DWORD, DWORD> * puiRegDataMap)=0;

	/*! \fn 		SetRegisterValue
	* \brief        设置寄存器数据
	* \param[in]    map<DWORD, DWORD> * puiRegDataMap : <index, value>
	* \return
	* \author
	* \date			2015-05-12
	*/
	virtual bool SetRegisterValue(map<DWORD, DWORD> * puiRegDataMap)=0;

	virtual bool GetRegisterBlanceData(EM_SETTLEMENT_TRIGGERTYPE_DEF emType, map<DWORD, DWORD> * puiRegDataMap, char * szLastBalanceTime)=0;

	/*! \fn 		GetDBHandle
	* \brief        获取数据访问句柄
	* \param[in]    int iDataType :  数据访问类型，如果只有1个数据源，忽略此参数
	* \return       数据访问句柄
	* \author
	* \date			2015-05-12
	*/
	virtual void * GetDBHandle(int iDataType)=0;

	/*! \fn 		BackupRegisterDataTable
	* \brief        备份寄存器数据表
	* \param[in]    EM_BALANCE_TYPE_DEF emType    结算类型
	* \return
	* \author		wangzp
	* \date			2015-05-12
	*/
	virtual bool BackupRegisterDataTable(EM_SETTLEMENT_TRIGGERTYPE_DEF emType)=0;

	// 保存操作日志
	virtual bool SaveBizDataOperateLog(ST_OPERATION_LOG * pstOperLog)=0;

	/*! \fn 		SaveBizDataTvmFault
	* \brief        保存Tvm故障交易
	* \param[in]    ST_TVM_FAULT_DATA * pstTvmFaultData
	* \return
	* \author		lyp
	* \date			2016-10-13
	*/
	virtual bool SaveBizDataTvmFault(ST_TVM_FAULT_DATA * pstTvmFaultData)=0;


public: //参数配置相关

	/*! \fn 		ReloadParam(EM_PARAM_TYPE_DEF emParamType)
	* \ brief 		重新加载参数
	* \ param[in]  	EM_PARAM_TYPE_DEF emParamType
	* \ param[out]  	szValue  ： 参数的字符串类型值
	* \ return 		true: 初始化成功；false：初始化失败
	* \ author
	* \ date			2015-01-14
	*/
	virtual bool ReloadParam(EM_PARAM_TYPE_DEF emParamType)=0;

	/*! \fn 		SetStandardParamValue(EM_STANDARD_PARAM_KEY emParamKey, char *szValue)
	* \ brief 		设置标准参数值
	* \ param[in]  	paramKey ： 参数主键Key，详见： EM_STANDARD_PARAM_KEY
	* \ param[out]  	szValue  ： 参数的字符串类型值
	* \ return 		true: 初始化成功；false：初始化失败
	* \ author
	* \ date			2015-01-14
	*/
	virtual bool SetStandardParamValue(EM_STANDARD_PARAM_KEY emParamKey, char *szValue)=0;

	/*! \fn 		SetStandardParamValue(EM_STANDARD_PARAM_KEY emParamKey, unsigned int uiValue)
	* \ brief 		设置标准参数值
	* \ param[in]  	paramKey ： 参数主键Key，详见： EM_STANDARD_PARAM_KEY
	* \ param[out]  uiValue  ： 参数的整数类型值
	* \ return 		true: 初始化成功；false：初始化失败
	* \ author
	* \ date			2015-01-14
	*/
	virtual	bool SetStandardParamValue(EM_STANDARD_PARAM_KEY emParamKey, unsigned int uiValue) = 0;

	/*! \fn 		GetStandardParamValue(EM_STANDARD_PARAM_KEY emParamKey , char *szValue)
	* \ brief 		获取标准参数值
	* \ param[in]  	paramKey ： 参数主键Key，详见： EM_STANDARD_PARAM_KEY
	* \ param[out]  	szValue  ： 参数的字符串类型值
	* \ return 		true: 初始化成功；false：初始化失败
	* \ author
	* \ date			2015-01-14
	*/
	virtual bool GetStandardParamCharValue(EM_STANDARD_PARAM_KEY emParamKey, char *szValue) = 0;

	/*! \fn 		GetStandardParamValue(EM_STANDARD_PARAM_KEY emParamKey, unsigned int *uiValue)
	* \ brief 		获取标准参数值
	* \ param[in]  	paramKey ： 参数主键Key，详见： EM_STANDARD_PARAM_KEY
	* \ param[out]  uiValue  ： 参数的整数类型值
	* \ return 		true: 初始化成功；false：初始化失败
	* \ author
	* \ date			2015-01-14
	*/
	virtual	bool GetStandardParamIntValue(EM_STANDARD_PARAM_KEY uiParamKey, unsigned int *uiValue) = 0;


	/*! \fn 		SetEnvParamValue(EM_ENV_PARAM_KEY emParamKey , char* szValue)
	* \ brief 		设置运行环境相关参数值
	* \ param[in]  	paramKey ： 参数主键Key，详见： EM_ENV_PARAM_KEY
	* \ param[out]  	szValue  ： 参数的字符串类型值
	* \ return 		true: 初始化成功；false：初始化失败
	* \ author
	* \ date			2015-01-14
	*/
	virtual bool SetEnvParamValue(EM_ENV_PARAM_KEY emParamKey, char *szValue) = 0;

	/*! \fn 		SetEnvParamValue(EM_ENV_PARAM_KEY emParamKey, unsigned int uiValue)
	* \ brief 		设置运行环境相关参数值
	* \ param[in]  	paramKey ： 参数主键Key，详见： EM_ENV_PARAM_KEY
	* \ param[out]  uiValue  ： 参数的整数类型值
	* \ return 		true: 初始化成功；false：初始化失败
	* \ author
	* \ date			2015-01-14
	*/
	virtual	bool SetEnvParamValue(EM_ENV_PARAM_KEY emParamKey, unsigned int uiValue) = 0;

	/*! \fn 		GetStandardParamValue(EM_ENV_PARAM_KEY emParamKey, char* szValue)
	* \ brief 		获取运行环境相关参数值
	* \ param[in]  	paramKey ： 参数主键Key，详见： EM_ENV_PARAM_KEY
	* \ param[out]  	szValue  ： 参数的字符串类型值
	* \ return 		true: 初始化成功；false：初始化失败
	* \ author
	* \ date			2015-01-14
	*/
	virtual bool GetEnvParamCharValue(EM_ENV_PARAM_KEY emParamKey, char *szValue) = 0;

	/*! \fn 		GetStandardParamValue(EM_ENV_PARAM_KEY uiParamId, unsigned int *uiValue)
	* \ brief 		获取运行环境相关参数值
	* \ param[in]  	paramKey ： 参数主键Key，详见： EM_ENV_PARAM_KEY
	* \ param[out]  uiValue  ： 参数的整数类型值
	* \ return 		true: 初始化成功；false：初始化失败
	* \ author
	* \ date			2015-01-14
	*/
	virtual	bool GetEnvParamIntValue(EM_ENV_PARAM_KEY emParamKey, unsigned int *uiValue) = 0;


	/*! \fn
	* \ brief 		设置设备个性化参数值
	* \ param[in]  	paramKey ： 参数主键Key，详见： EM_SPEC_PARAM_KEY
	* \ param[out]  	szValue  ： 参数的字符串类型值
	* \ return 		true: 初始化成功；false：初始化失败
	* \ author
	* \ date			2015-01-14
	*/
	virtual bool SetSpecParamValue(EM_SPEC_PARAM_KEY emParamKey, char *szValue) = 0;

	/*! \fn
	* \ brief 		设置设备个性化参数值
	* \ param[in]  	paramKey ： 参数主键Key，详见： EM_SPEC_PARAM_KEY
	* \ param[out]  uiValue  ： 参数的整数类型值
	* \ return 		true: 初始化成功；false：初始化失败
	* \ author
	* \ date			2015-01-14
	*/
	virtual bool SetSpecParamValue(EM_SPEC_PARAM_KEY emParamKey, unsigned int uiValue) = 0;

	/*! \fn
	* \ brief 		设置设备个性化参数值 - byte数组类型的数据，如设备编号为：0x13210201;
	* \ param[in]  	emParamKey 参数主键Key，详见： EM_SPEC_PARAM_KEY
	* \ param[in]  	szValue 待设置的值
	* \ param[in]   iSize   待设置的值的长度
	* \ return 		true: 初始化成功；false：初始化失败
	* \ author
	* \ date			2015-01-14
	*/
	virtual bool SetSpecParamValue(EM_SPEC_PARAM_KEY emParamKey, const unsigned char *szValue, int iSize) = 0;

	/*! \fn
	* \ brief 		获取设备个性化参数值
	* \ param[in]  	paramKey ： 参数主键Key，详见： EM_SPEC_PARAM_KEY
	* \ param[out]  	szValue  ： 参数的字符串类型值
	* \ return 		true: 初始化成功；false：初始化失败
	* \ author
	* \ date			2015-01-14
	*/
	virtual bool GetSpecParamCharValue(EM_SPEC_PARAM_KEY emParamKey, char *szValue) = 0;

	/*! \fn
	* \ brief 		获取设备个性化参数值
	* \ param[in]  	paramKey ： 参数主键Key，详见： EM_SPEC_PARAM_KEY
	* \ param[out]  uiValue  ： 参数的整数类型值
	* \ return 		true: 初始化成功；false：初始化失败
	* \ author
	* \ date			2015-01-14
	*/
	virtual bool GetSpecParamIntValue(EM_SPEC_PARAM_KEY emParamKey, unsigned int *uiValue) = 0;


	/*! \fn
	* \ brief 		获取设备个性化参数值 - byte数组类型的数据，如设备编号为：0x13210201;
	* \ param[in]  	emParamKey 参数主键Key，详见： EM_SPEC_PARAM_KEY
	* \ param[out] 	szValue 获取到的值
	* \ param[out]  iSize   获取到的值的长度
	* \ return 		true: 初始化成功；false：初始化失败
	* \ author
	* \ date			2015-01-14
	*/
	virtual bool GetSpecParamArrayValue(EM_SPEC_PARAM_KEY emParamKey, unsigned char *szValue, int * piSize) = 0;


public: //参数版本信息
	/*! \fn
	* \ brief 		获取指定参数版本类型的参数版本信息列表
	* \ param[in]   EM_SLE_PARAM_VERSION_TYPE emParamVersionType
	* \ param[out]
	* \ return
	* \ author
	* \ date
	*/
	virtual int GetParamVersionInfo(EM_SLE_PARAM_VERSION_TYPE emParamVersionType, ST_SLE_PARAM_VERSION_INFO *pstSleParamVersionInfo) = 0;

	/*! \fn
	* \ brief 		获取指定参数版本类型、指定参数类型的参数版本信息
	* \ param[in]   EM_SLE_PARAM_VERSION_TYPE emParamVersionType
	* \ param[in]   char szParamType
	* \ param[out]
	* \ return
	* \ author
	* \ date
	*/
	virtual int GetParamVersionInfo(EM_SLE_PARAM_VERSION_TYPE emParamVersionType, char *szParamType, ST_SLE_SINGLE_PARAM_VERSION_INFO *pstSleSingleParamVersion) = 0;

	/*! \fn 		GetTpuVersionInfo
	* \brief        获取TPU版本信息
	* \param[in]	bSoftwareVerInfo			软件版本信息
	* \param[in]	bParamVerInfo				参数版本信息
	* \param[in]	emParamVersionType			版本类型
	* \param[out]	pstSleParamVersionInfo		获取到的具体版本信息
	* \return		true/false					成功/失败
	* \author		longjg
	* \date			2015-08-05
	*/
	virtual bool GetTpuVersionInfo(bool bSoftwareVerInfo, bool bParamVerInfo, EM_SLE_PARAM_VERSION_TYPE emParamVersionType, ST_SLE_PARAM_VERSION_INFO* pstSleParamVersionInfo) = 0;


public: //结算相关信息
	/*! \fn 		GenBalanceMainTabInfo
	* \brief        生成结算信息主表
	* \param[in]    ulong balanceId 结算流水号
	* \return       true:success false:failed
	* \author		wangzp
	* \date			2016-08-01
	*/
	virtual bool GenBalanceMainTabInfo(EM_BALANCE_DATA_CAL_TYPE emBalanceDataCalType, ulong balanceId, const char * pBalanceDate, const char * pBalanceTime, const char * pRunDate, const char * pOperatorCode, EM_SETTLEMENT_TRIGGERTYPE_DEF emSettlementTriggerType) = 0;

	/*! \fn 		GenCashContainerFlowBalanceInfo
	* \brief        生成现金箱流转结算信息
	* \param[in]    ulong balanceId 结算流水号
	* \return       true:success false:failed
	* \author		wangzp
	* \date			2016-08-01
	*/
	virtual bool GenCashContainerFlowBalanceInfo(EM_BALANCE_DATA_CAL_TYPE emBalanceDataCalType, ulong balanceId) = 0;

	/*! \fn 		GenTicketContainerFlowBalanceInfo
	* \brief        生成票箱流转结算信息
	* \param[in]    ulong balanceId 结算流水号
	* \return       true:success false:failed
	* \author		wangzp
	* \date			2016-08-01
	*/
	virtual bool GenTicketContainerFlowBalanceInfo(EM_BALANCE_DATA_CAL_TYPE emBalanceDataCalType, ulong balanceId) = 0;

	/*! \fn 		GenContainerChangeBalanceInfo
	* \brief        生成钱票箱更换结算信息
	* \param[in]    EM_BALANCE_DATA_CAL_TYPE emBalanceDataCalType 结算类型
	* \param[in]    ulong balanceId 结算流水号
	* \return       true:success false:failed
	* \author		wangzp
	* \date			2016-08-01
	*/
	virtual bool GenContainerChangeBalanceInfo(EM_BALANCE_DATA_CAL_TYPE emBalanceDataCalType, ulong balanceId) = 0;

	/*! \fn 		GenTvmTransBalanceInfo
	* \brief        生成交易结算信息
	* \param[in]    ulong balanceId 结算流水号
	* \return       true:success false:failed
	* \author		wangzp
	* \date			2016-08-01
	*/
	virtual bool GenTvmTransBalanceInfo(EM_BALANCE_DATA_CAL_TYPE emBalanceDataCalType, ulong balanceId) = 0;

	/*! \fn 		GenTvmContainerBalanceInfo
	* \brief
	* \param[in]    EM_BALANCE_DATA_CAL_TYPE emBalanceDataCalType
	* \param[in]    ulong balanceId 结算流水号
	* \param[in]    int iType    钱票类型
	* \param[in]    int iContainerType
	* \param[in]    int iContainerNo
	* \param[in]    int iBalanceCount    结存数量
	* \param[in]    int iBalanceAmount   结存金额
	* \return       true:success false:failed
	* \author		wangzp
	* \date			2016-08-01
	*/
	virtual bool GenTvmContainerBalanceInfo(EM_BALANCE_DATA_CAL_TYPE emBalanceDataCalType, ulong balanceId, int iType, int iContainerType, int iContainerNo, int iBalanceCount, int iBalanceAmount) = 0;

	/*! \fn 		GetTvmContainerBalanceInfo
	* \brief
	* \param[in]    EM_BALANCE_DATA_CAL_TYPE emBalanceDataCalType
	* \param[in]    ulong balanceId 结算流水号
	* \param[in]    int iType    钱票类型
	* \param[in]    int iContainerType
	* \param[in]    int iContainerNo
	* \param[out]    int iBalanceCount    结存数量
	* \param[out]    int iBalanceAmount   结存金额
	* \return       true:success false:failed
	* \author		wangzp
	* \date			2016-08-01
	*/
	virtual bool GetTvmContainerBalanceInfo(EM_BALANCE_DATA_CAL_TYPE emBalanceDataCalType, ulong balanceId, int iType, int iContainerType, int iContainerNo, int &iBalanceCount, int &iBalanceAmount) = 0;

	/*! \fn 		GetBalanceMainInfoByID
	* \brief        获取交易结算信息
	* \param[in]    ulong balanceId 结算流水号
	* \param[out]   char * pBalanceDate
	* \param[out]   char * pBalanceTime
	* \param[out]   char * pOperatorCode
	* \return       true:success false:failed
	* \author		wangzp
	* \date			2016-08-01
	*/
	virtual bool GetBalanceMainInfoByID(EM_BALANCE_DATA_CAL_TYPE emBalanceDataCalType, ulong balanceId, char * pBalanceDate, char * pBalanceTime, char * pOperatorCode, char * pRunDate, EM_SETTLEMENT_TRIGGERTYPE_DEF * pemSettlementTriggerType) = 0;

	/*! \fn 		GetBalanceCashFlowInfoByID
	* \brief        获取现金箱流转信息
	* \param[in]    ulong balanceId 结算流水号                              流水号
	* \param[in]    ST_CASH_CONTAINER_LOCATION stCashContainerLocation    统计的现金箱位置
	* \param[in]    EM_CASH_ACTION_TYPE emCashActionType     动作类型
	* \param[in]    bool bTestFlag           测试标记
	* \param[out]   DWORD * dwTotalCount     累计总数量
	* \param[out]   DWORD * dwTotalAmount    累计总金额
	* \return       true:success false:failed
	* \author		wangzp
	* \date			2016-08-01
	*/
	virtual bool GetBalanceCashFlowInfoByID(EM_BALANCE_DATA_CAL_TYPE emBalanceDataCalType, ulong balanceId, ST_CASH_CONTAINER_LOCATION stCashContainerLocation, EM_CASH_ACTION_TYPE emCashActionType, bool bTestFlag, DWORD &dwTotalCount, DWORD &dwTotalAmount) = 0;

	/*! \fn 		GetBalanceTicFlowInfoByID
	* \brief        获取票箱流转信息
	* \param[in]    ulong balanceId 结算流水号                              流水号
	* \param[in]    ST_TICKET_CONTAINER_LOCATION stTicContainerLocation    统计的票箱位置
	* \param[in]    EM_TICKET_ACTION_TYPE emTicActionType    动作类型
	* \param[in]    bool bTestFlag           测试标记
	* \param[out]   DWORD * dwTotalCount     累计总数量
	* \return       true:success false:failed
	* \author		wangzp
	* \date			2016-08-01
	*/
	virtual bool GetBalanceTicFlowInfoByID(EM_BALANCE_DATA_CAL_TYPE emBalanceDataCalType, ulong balanceId, ST_TICKET_CONTAINER_LOCATION stTicContainerLocation, EM_TICKET_ACTION_TYPE emTicActionType, bool bTestFlag, DWORD &dwTotalCount, DWORD &dwTotalAmount) = 0;

	/*! \fn 		GetBalanceCashContainerChangeInfoByID
	* \brief        获取现金箱更换信息
	* \param[in]    ulong balanceId 结算流水号                              流水号
	* \param[in]    ST_CASH_CONTAINER_LOCATION stCashContainerLocation    统计的现金箱位置
	* \param[in]    EM_CONTAINER_OPERATION_TYPE emOperType     操作类型
	* \param[in]    bool bTestFlag           测试标记
	* \param[out]   DWORD * dwTotalCount     累计总数量
	* \param[out]   DWORD * dwTotalAmount    累计总金额
	* \return       true:success false:failed
	* \author		wangzp
	* \date			2016-08-01
	*/
	virtual bool GetBalanceCashContainerChangeInfoByID(EM_BALANCE_DATA_CAL_TYPE emBalanceDataCalType, ulong balanceId, ST_CASH_CONTAINER_LOCATION stCashContainerLocation, EM_CONTAINER_OPERATION_TYPE emOperType, bool bTestFlag, DWORD &dwTotalCount, DWORD &dwTotalAmount) = 0;

	/*! \fn 		GetBalanceTicketContainerChangeInfoByID
	* \brief        获取票箱更换信息
	* \param[in]    ulong balanceId 结算流水号                              流水号
	* \param[in]    ST_TICKET_CONTAINER_LOCATION stTicContainerLocation    统计的票箱位置
	* \param[in]    EM_CONTAINER_OPERATION_TYPE emOperType    操作类型
	* \param[in]    bool bTestFlag           测试标记
	* \param[out]   DWORD * dwTotalCount     累计总数量
	* \return       true:success false:failed
	* \author		wangzp
	* \date			2016-08-01
	*/
	virtual bool GetBalanceTicketContainerChangeInfoByID(EM_BALANCE_DATA_CAL_TYPE emBalanceDataCalType, ulong balanceId, ST_TICKET_CONTAINER_LOCATION stTicContainerLocation, EM_CONTAINER_OPERATION_TYPE emOperType, bool bTestFlag, DWORD &dwTotalCount, DWORD &dwTotalAmount) = 0;

	/*! \fn 		GetBalanceTransInfo
	* \brief        获取现金箱流转信息
	* \param[in]    ulong balanceId 结算流水号                              流水号
	* \param[in]    EM_PAYMENT_METHOD emPaymentMethod        支付方式
	* \param[in]    EM_SLE_TRANSACATION_TYPE emSleTransType     交易类型
	* \param[in]    bool bTestFlag           测试标记
	* \param[out]   int pMapTotalTransSumByUnitPrice     按票价统计的累计总金额
	* \param[out]   int pMapTotalTransCountByUnitPrice   按票价统计的累计总数量
	* \return       true:success false:failed
	* \author		wangzp
	* \date			2016-08-01
	*/
	virtual bool GetBalanceTransInfo(EM_BALANCE_DATA_CAL_TYPE emBalanceDataCalType, ulong balanceId, EM_PAYMENT_METHOD emPaymentMethod, EM_SLE_TRANSACATION_TYPE emSleTransType, map<int, int> *pMapTotalTransSumByUnitPrice, map<int, int> *pMapTotalTransCountByUnitPrice) = 0;

	/*! \fn 		GetBalanceTransInfo
	* \brief        获取故障交易信息
	* \param[in]    ulong balanceId 结算流水号                              流水号
	* \param[in]    EM_SLE_TRANSACATION_TYPE emSleTransType     交易类型
	* \param[in]    bool bTestFlag           测试标记
	* \param[out]   int &iTotalTransCount     累计总数量
	* \param[out]   int &iTotalTransAmount    累计总金额
	* \param[in]    int iTransBalance         交易结算类型：等于0正常；1为少找零；-1为多找零:2为默认值，忽略该值
	* \return       true:success false:failed
	* \author		wangzp
	* \date			2016-08-01
	*/
	virtual bool GetBalanceTransFaultInfo(EM_BALANCE_DATA_CAL_TYPE emBalanceDataCalType, ulong balanceId, EM_SLE_TRANSACATION_TYPE emSleTransType, int &iTransTimes, int &iTotalTransAmount, int iTransBalance) = 0;

	/*! \fn 		UpdateCashBoxChangeFlowBalanceFlag
	* \brief        更新钱箱更换流水表结算标记
	* \param[in]    const PubSleDb * pPubSleDb    操作数据库对象
	* \param[in]    EM_BALANCE_TYPE_DEF emBalanceType
	* \return	    true    更新成功    false    更新失败
	* \author		wangzp
	* \date			2015-05-12
	*/
	virtual bool UpdateCashBoxChangeFlowBalanceFlag(EM_BALANCE_DATA_CAL_TYPE emBalanceDataCalType, ulong balanceId) = 0;

	/*! \fn 		UpdateTicBoxChangeFlowBalanceFlag
	* \brief        更新票箱更换流水表结算标记
	* \param[in]    const PubSleDb * pPubSleDb    操作数据库对象
	* \param[in]    EM_BALANCE_TYPE_DEF emBalanceType
	* \return	    true    更新成功    false    更新失败
	* \author		wangzp
	* \date			2015-05-12
	*/
	virtual bool UpdateTicBoxChangeFlowBalanceFlag(EM_BALANCE_DATA_CAL_TYPE emBalanceDataCalType, ulong balanceId) = 0;

	/*! \fn 		UpdateTransMainTableBalanceFlag
	* \brief        更新交易主表结算标记
	* \param[in]    const PubSleDb * pPubSleDb    操作数据库对象
	* \param[in]    EM_BALANCE_TYPE_DEF emBalanceType
	* \return	    true    更新成功    false    更新失败
	* \author		wangzp
	* \date			2015-05-12
	*/
	virtual bool UpdateTransMainTableBalanceFlag(EM_BALANCE_DATA_CAL_TYPE emBalanceDataCalType, ulong balanceId) = 0;

	/*! \fn 		UpdateTransIncomingBalanceFlag
	* \brief        更新收益表结算标记
	* \param[in]    const PubSleDb * pPubSleDb    操作数据库对象
	* \param[in]    EM_BALANCE_TYPE_DEF emBalanceType
	* \return	    true    更新成功    false    更新失败
	* \author		wangzp
	* \date			2015-05-12
	*/
	virtual bool UpdateTransIncomingBalanceFlag(EM_BALANCE_DATA_CAL_TYPE emBalanceDataCalType, ulong balanceId) = 0;

	/*! \fn 		UpdateTransCashFlowBalanceFlag
	* \brief        更新现金交易流转结算标记
	* \param[in]    const PubSleDb * pPubSleDb    操作数据库对象
	* \param[in]    EM_BALANCE_TYPE_DEF emBalanceType
	* \return	    true    更新成功    false    更新失败
	* \author		wangzp
	* \date			2015-05-12
	*/
	virtual bool UpdateTransCashFlowBalanceFlag(EM_BALANCE_DATA_CAL_TYPE emBalanceDataCalType, ulong balanceId) = 0;

	/*! \fn 		UpdateTransTicketFlowBalanceFlag
	* \brief        更新票卡交易流转结算标记
	* \param[in]    const PubSleDb * pPubSleDb    操作数据库对象
	* \param[in]    EM_BALANCE_TYPE_DEF emBalanceType
	* \return	    true    更新成功    false    更新失败
	* \author		wangzp
	* \date			2015-05-12
	*/
	virtual bool UpdateTransTicketFlowBalanceFlag(EM_BALANCE_DATA_CAL_TYPE emBalanceDataCalType, ulong balanceId) = 0;
public: //事件

	virtual bool EventLog(ST_EVENT_RECORD stEventRecord) = 0;

protected:
	CLogOper2 *m_p_SleDataLogBiz; /*!< */
	CLogOper2 *m_p_SleDataLog;

};

class CLogOper2;
typedef Loki::SingletonHolder
<
	Loki::Factory<ISleDataApp, std::string, Seq<CLogOper2*> >,
	CreateUsingNew, Loki::LongevityLifetime::DieAsSmallObjectChild
> SleDataAppFactory;

#define REGISTER_AFC_SLEDATAAPP_OBJECT(className)                                                      \
namespace {                                                                            \
	ISleDataApp* createSleDataAppBase(CLogOper2 *m_pBizLog) { return new className(m_pBizLog); }                                              \
const bool SleDataAppFactory__ = SleDataAppFactory::Instance().Register( #className, createSleDataAppBase );  \
}
class ISleDataApp;
extern	ISleDataApp *g_pIAfcSleDataApp;


#endif /* CSLEDATAAPP_H_ */
