#ifndef BIZDATAGEN_H_
#define BIZDATAGEN_H_

#include <loki/Singleton.h>
#include <loki/Factory.h>
#include <loki/Sequence.h>
using namespace Loki;

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "TransCashData.h"
#include "TransTicketData.h"
#include "PubSleDb.h"
#include "CLogOper2.h"

#include "AfcPublic.h"
#include "IAfcApp.h"


#define MAX_DATA_LEN 2048


class ISleBizDataGenApp : public IAfcApp
{

public:
	//保存TVM审计数据
	virtual int GenBizAgAuditData(const void * pstAgAuditDataInfo, int iDataLen, ST_BIZ_DATA_RECORD * pstBizDataRecord) = 0;

	//保存TVM审计数据
	virtual int GenBizTvmAuditData(const void * pstTvmAuditDataInfo, int iDataLen, ST_BIZ_DATA_RECORD * pstBizDataRecord) = 0;

	/*! \fn 		GenBizTvmSettlementData
	* \brief 		保存TVM结算业务数据
	* \param[in]  	no
	* \return 		true: 初始化成功；false：初始化失败
	* \author		wangzp
	* \date			2015-05-22
	*/
	virtual int GenBizTvmSettlementData(int iBalanceID, void * pstTvmSettlementDataInfo, int iDataLen, ST_BIZ_DATA_RECORD * pstBizDataRecord) = 0;

	//保存TVM结算业务数据
	virtual int GenBizTvmBalanceData(int iBalanceID, void * pstTvmBalanceDataInfo, int iDataLen, ST_BIZ_DATA_RECORD * pstBizDataRecord) = 0;
	//保存票箱更换业务数据
	virtual int GenBizDataTicketBoxChange(ST_TICKETBOX_CHANGE_INFO stTicketBoxChangeInfo, ST_BIZ_DATA_RECORD *pstBizDataRecord) = 0;
	virtual int GenBizDataTicketBoxChange(list<ST_TICKETBOX_CHANGE_INFO> * pstTicketBoxChangeInfo, ST_BIZ_DATA_RECORD *pstBizDataRecord) = 0;

	//保存钱箱更换业务数据
	virtual int GenBizDataCashBoxChange(ST_CASHBOX_CHANGE_INFO stCashboxChangeInfo, ST_BIZ_DATA_RECORD *pstBizDataRecord) = 0;
	virtual int GenBizDataCashBoxChange(list<ST_CASHBOX_CHANGE_INFO> * pstCashboxChangeInfo, ST_BIZ_DATA_RECORD *pstBizDataRecord) = 0;

	/* 设置事件类数据的项目化信息，如：事件类数据的名称、数据类型等等 */
	virtual int SetEventLogProjectInfo(ST_EVENT_RECORD stEventRecord, ST_BIZ_DATA_RECORD *pstBizDataRecord) = 0;

	/* 保存TVM结算数据，包括自动结存数据和结帐数据 */
//	virtual int SaveTvmBalanceData(ST_TVM_BALANCE_DATA_INFO stTvmBalanceDataInfo, ST_BIZ_DATA_RECORD *pstBizDataRecord) = 0;
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
	virtual bool SaveTvmTransRecord(ST_TVM_PASSENGER_TRANS * pstTvmPassengerTransInfo, EM_TRANSACATION_RESULT emTransacationResult) = 0;
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

	// 保存操作日志
	virtual bool GenBizDataOperateLog(ST_OPERATION_LOG * pstOperLog,ST_BIZ_DATA_RECORD *pstBizDataRecord)=0;

	/*! \fn 		SaveBizDataTvmFault
	* \brief        保存Tvm故障交易
	* \param[in]    ST_TVM_FAULT_DATA * pstTvmFaultData
	* \return
	* \author		lyp
	* \date			2016-10-13
	*/
	virtual bool GenBizDataTvmFault(ST_TVM_FAULT_DATA * pstTvmFaultData,ST_BIZ_DATA_RECORD *pstBizDataRecord)=0;
};


class CLogOper2;

typedef Loki::SingletonHolder<	Loki::Factory<ISleBizDataGenApp, std::string, Seq<CLogOper2*> > > BizDataGenFactory;

#define REGISTER_BIZDATAGEN(className) \
namespace {                                                                            \
	ISleBizDataGenApp* createBizDataGen(CLogOper2 *pSleLog) { return new className(pSleLog); }                                              \
const bool BizDataGenFactory__ = BizDataGenFactory::Instance().Register( #className, createBizDataGen );  \
}

extern ISleBizDataGenApp *pstBizDataGen;


#endif /*BIZDATAGEN_H_*/
