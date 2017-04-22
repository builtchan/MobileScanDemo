/*
 * CTvmTicketHandlerApp.h
 *
 *  Created on: Aug 19, 2014
 *      Author: wangzp
 */

#ifndef CTVMTICKETHANDLERAPP_H_
#define CTVMTICKETHANDLERAPP_H_

#include "AfcPublic.h"
#include "ipcpublic.h"
#include "TransTicketData.h"
#include <map>
#include <loki/Singleton.h>
#include <loki/Factory.h>
#include <loki/Sequence.h>
using namespace Loki;//引用命名空间

using namespace std;

class ITvmTicketHandlerApp : public IAfcApp
{
public:

	/*! \fn 		ConsumeValidity
	* \brief        卡消费有效性验证
	* \param[in]	天线
	* \param[in]    int iConsumeMoney  消费金额
	* \param[in]   	emTransType 交易金额
	* \param[out]	返回读到的卡信息
	* \return 		true  有效    false  无效
	* \author		wangyzh
	* \date			2015-12-05
	*/
	virtual bool ConsumeValidity(int iAntenna, int iConsumeMoney, EM_SLE_TRANSACATION_TYPE emTransType, ST_TPU_READ_CARD_INFO *pstTpuReadCardInfo) = 0;

	/*! \fn 		PetCardConsume
	* \brief        卡消费
	* \param[in]	天线区域
	* \param[in]  	stBusiContextData  业务交易入参
	* \param[out]	交易结果
	* \param[out]	交易快照
	* \param[out]	交易信息
	* \return 		true  扣款成功    false  扣款失败
	* \author		wangzp
	* \date			2014-08-06
	*/
	virtual bool PetCardConsume(int iAntenna, ST_BUSINESS_CONTEXT_DATA *pstBusiContextData, ST_TPU_TRANS_RESULT * pstTransResultSnapshot, ST_TICKET_TRANS_DETAIL_INFO * pstTransDetailInfo) = 0;

	/*! \fn 		Issue
	* \brief        发售车票
	* \param[in]    int iTicketType    票卡类型
	* \param[out]   ST_TRANRESULT_CSS * pstTransResultCss    交易快照结构体
	* \param[out]   ST_UD_DATA_CSS * pstUDDataCss            UD结构体
	* \param[out]   ST_ARDATA_CSS * pstARDataCss             AR数据结构体
	* \param[out]   list<ST_TICKETBOX_DATA_UNIT_INFO> * pIssueInfoList    票卡流转数据信息结构体
	* \param[out]   ST_TICKET_ISSUE_PROCESS_INFO * pstTvmIssueProcessInfo    发售过程中信息记录结构体
	* \return 		EM_FUN_RET_TPYE
	* \author		wangzp
	* \date			2014-08-06
	*/

	virtual bool Issue(ST_TVM_VENDING_REQUEST_INFO stTvmVendRequestInfo, EM_PAYMENT_METHOD emPaymentMethod,DWORD iCurrentCount, bool bTestTicket, bool * pbWriteOK, bool * pbOutOK,
			ST_TPU_TRANS_RESULT * pstTransResultSnapshot, ST_TICKET_TRANS_DETAIL_INFO * pstTransDetailInfo,ST_BUSINESS_CONTEXT_DATA *pstBusiContextData) = 0;

	/*! \fn 		GetTicketPrice
	* \brief        获取票价
	* \param[in]    int iStationCode    目的车站编码
	* \param[out]   int * piTicketPrice    票价
	* \return 		none
	* \author		wangzp
	* \date			2014-08-06
	*/
	virtual DWORD GetTicketPrice(ST_TPU_CALCULATE_PRICE_PARAM stParam, DWORD * piDiscountValue) = 0;

	/*! \fn 		GetStationList
	* \brief        获取车站列表
	* \param[in]    int iLineID    线路编码（0 全部线路）
	* \param[out]   list<DWORD> * pStationList    车站列表
	* \return 		none
	* \author		wangzp
	* \date			2014-08-06
	*/
	virtual void GetStationList(int iPrice, list<DWORD> * pStationList) = 0;

	/*! \fn 		OperateTicketbox
	 * \brief 		操作票箱
	 * param[in] 	stTicketboxLocation: 票箱ID
	 * param[in] 	emBoxOpType：票箱的操作 上锁 解锁 补充
	 * param[in]	iTimeout ： 超时时间，单位 s
	 * 返回值： 		操作结果
	 * \author: 	wugang
	 * \date 		2015-02-20
	*/
	virtual bool OperateTicketbox(ST_TICKET_CONTAINER_LOCATION stTicketboxLocation,  EM_CONTAINER_OPERATION_TYPE emBoxOpType, int iTimeout) = 0;

	/*! \fn 		GetTransTicketData
	 * \brief 		获取交易的票卡的数据信息
	 * param[out]	交易数据的类
	 * 返回值： 		无
	 * \author: 	wangyzh
	 * \date 		2015-05-07
	*/
	virtual void GetTransTicketData(CTransTicketData *pcTransTicketData) = 0;

	/*! \fn 		AcceptPassengerCard(EM_SLE_TRANSACATION_TYPE emTransType)
	 * \brief 		接受乘客放卡
	 * param[in]	emTransType 设备当前处理的业务
	 * 返回值： 		bool
	 * \author: 	wangyzh/shaopf
	 * \date 		2015-07-02
	*/
	virtual bool AcceptPassengerCard(EM_SLE_TRANSACATION_TYPE emTransType) = 0;

	/*! \fn 		RefundPassengerCard(EM_SLE_TRANSACATION_TYPE emTransType)
	 * \brief 		退还乘客卡
	 * param[in]	emTransType 设备当前处理的业务
	 * 返回值： 		bool
	 * \author: 	wangyzh/shaopf
	 * \date 		2015-07-02
	*/
	virtual bool RefundPassengerCard(EM_SLE_TRANSACATION_TYPE emTransType) = 0;

	/*! \fn 		RefundPassengerCard(EM_SLE_TRANSACATION_TYPE emTransType)
	 * \brief 		读取卡信息
	 * param[in]	emTransType 			设备当前处理的业务
	 * param[out]	pstTpuReadCardInfo 		读取的卡的全部信息
	 * 返回值： 		bool
	 * \author: 	wangyzh/shaopf
	 * \date 		2015-07-02
	*/
	virtual bool ReadPassengerCardInfo(EM_SLE_TRANSACATION_TYPE emTransType, ST_TPU_READ_CARD_INFO *pstTpuReadCardInfo) = 0;

	/*! \fn 		Recharge() = 0;
	 * \brief 		充值
	 * param[in]	emPaymentMethod 		付费方式
	 * param[in]	stRechargeInfo 			充值请求信息
	 * param[in]	pstTpuReadCardInfo 		读取的卡的全部信息
	 * param[out]	pstTpuTransResult 		充值交易数据快照
	 * param[out]	pstTransDetailInfo		交易产生的UD数据信息
	 * param[out]	pstBusiContextData 		业务环境数据
	 * 返回值： 		bool
	 * \author: 	wangyzh/shaopf
	 * \date 		2015-07-02
	*/
	virtual bool Recharge(EM_RECHARGE_CONTROL_PARAM emRechargeControlParam, EM_PAYMENT_METHOD emPaymentMethod,  ST_TVM_RECHARGE_REQUEST_INFO stRechargeInfo, const ST_TPU_READ_CARD_INFO *pstTpuReadCardInfo,\
			ST_TPU_TRANS_RESULT * pstTpuTransResult, ST_TICKET_TRANS_DETAIL_INFO * pstTransDetailInfo, ST_BUSINESS_CONTEXT_DATA *pstBusiContextData) = 0;

	/*! \fn 		StopPollCard()
	 * \brief 		停止寻卡,仅仅针对贴卡方式
	 * param[in]	无
	 * param[out]	无
	 * 返回值： 		bool
	 * \author: 	wangyzh
	 * \date 		2015-07-02
	*/
	virtual bool StopPollCard() = 0;
protected:
	CLogOper2 *m_pBizLog; /*!< */

};
class CLogOper2;
typedef Loki::SingletonHolder
<
	Loki::Factory<ITvmTicketHandlerApp, std::string, Seq<CLogOper2*> >,
	CreateUsingNew, Loki::LongevityLifetime::DieAsSmallObjectChild
> TvmTicketHandlerAppFactory;

#define REGISTER_AFC_TVMTICKETHANDLERAPP_OBJECT(className)                                                      \
namespace {                                                                            \
	ITvmTicketHandlerApp* createTvmTicketHandlerAppBase(CLogOper2 *m_pBizLog) { return new className(m_pBizLog); }                                              \
const bool TvmTicketHandlerAppFactory__ = TvmTicketHandlerAppFactory::Instance().Register( #className, createTvmTicketHandlerAppBase );  \
}
class ITvmTicketHandlerApp;
extern	ITvmTicketHandlerApp *g_pIAfcTvmTicketHandlerApp;

#endif /* CTVMTICKETHANDLERAPP_H_ */
