/*
 * CAgTicketHandlerApp.h
 *
 *  Created on: Aug 19, 2014
 *      Author: wangzp
 */

#ifndef CAGTICKETHANDLERAPP_H_
#define CAGTICKETHANDLERAPP_H_

#include "AfcPublic.h"
#include "IAfcApp.h"
#include <map>
#include <loki/Singleton.h>
#include <loki/Factory.h>
#include <loki/Sequence.h>
using namespace Loki;//引用命名空间

using namespace std;

class IAgTicketHandlerApp : public IAfcApp
{
public:


	/*! \fn 		EntryCheck(ST_TPU_POLLING_CARD_INFO stPollingInfo, ST_BUSINESS_CONTEXT_DATA *pstBusiContextData, ST_TPU_TRANS_RESULT * pstTpuTransResult)=0;
	* \brief        进站检票APP
	* \param[in]
	* 		stPollingInfo :  Polling返回信息，作为检票调用的入参
	* \param[out]
	* 		pstTpuTransResult : 交易结果
	* 		pstBusiContextData ： 交易业务信息
	* \return 		true: 进行了检票； false： 没有检票
	* 		        注：检票结果（车票无效或者OK）在出参反馈，此时的返回值是true；只有在调用读写器检票功能失败，没有执行检票动作时，返回false
	* \author		wugang
	* \date			2015-01-30
	*/
	virtual bool EntryCheck(ST_TPU_POLLING_CARD_INFO stPollingInfo, ST_BUSINESS_CONTEXT_DATA *pstBusiContextData, ST_TPU_TRANS_RESULT * pstTpuTransResult)=0;

	/*! \fn 		ExitWdCheck(ST_TPU_POLLING_CARD_INFO *pstPollingInfo, ST_BUSINESS_CONTEXT_DATA *pstBusiContextData, ST_TPU_TRANS_RESULT * pstTpuTransResult)=0;
	* \brief        出站回收检票APP,应用于插卡触发
	* \param[in]    无
	* \param[out]
	* 		pstTpuTransResult : 交易结果
	* 		pstBusiContextData ： 交易业务信息
	* \return 		true: 进行了检票； false： 没有检票
	* 		        注：检票结果（车票无效或者OK）在出参反馈，此时的返回值是true；只有在调用读写器检票功能失败，没有执行检票动作时，返回false
	* \author		wugang
	* \date			2015-01-30
	*/
	virtual bool ExitWdCheck(ST_TPU_POLLING_CARD_INFO *pstPollingInfo, ST_BUSINESS_CONTEXT_DATA *pstBusiContextData, ST_TPU_TRANS_RESULT * pstTpuTransResult)=0;

	/*! \fn 		ExitWdCheck(ST_BUSINESS_CONTEXT_DATA *pstBusiContextData, ST_TPU_TRANS_RESULT * pstTpuTransResult)=0;
	* \brief        出站回收检票APP,应用于寻卡触发（预读）
	* \param[in]
	* 		stPollingInfo :  Polling返回信息，作为检票调用的入参
	* \param[out]
	* 		pstTpuTransResult : 交易结果
	* 		pstBusiContextData ： 交易业务信息
	* \return 		true: 进行了检票； false： 没有检票
	* 		        注：检票结果（车票无效或者OK）在出参反馈，此时的返回值是true；只有在调用读写器检票功能失败，没有执行检票动作时，返回false
	* \author		wugang
	* \date			2015-01-30
	*/
	virtual bool ExitWdCheck(ST_TPU_POLLING_CARD_INFO stPollingInfo, ST_BUSINESS_CONTEXT_DATA *pstBusiContextData, ST_TPU_TRANS_RESULT * pstTpuTransResult)=0;

	/*! \fn 		virtual bool ExitUnwdCheck(ST_TPU_POLLING_CARD_INFO stPollingInfo, ST_BUSINESS_CONTEXT_DATA *pstBusiContextData, ST_TPU_TRANS_RESULT * pstTpuTransResult)=0;
	* \brief        出站刷卡检票APP
	* \param[in]
	* 		stPollingInfo :  Polling返回信息，作为检票调用的入参
	* \param[out]
	* 		pstTpuTransResult : 交易结果
	* 		pstBusiContextData ： 交易业务信息
	* \return 		true: 进行了检票； false： 没有检票
	* 		        注：检票结果（车票无效或者OK）在出参反馈，此时的返回值是true；只有在调用读写器检票功能失败，没有执行检票动作时，返回false
	* \author		wugang
	* \date			2015-01-30
	*/
	virtual bool ExitUnwdCheck(ST_TPU_POLLING_CARD_INFO stPollingInfo, ST_BUSINESS_CONTEXT_DATA *pstBusiContextData, ST_TPU_TRANS_RESULT * pstTpuTransResult)=0;

	/*! \fn 		virtual bool GetUdData(ST_TICKET_TRANS_DETAIL_INFO * pstTicketTransUdInfo) = 0;
	* \brief        出站刷卡检票APP
	* \param[in]
	* 		emTransType : 交易类型
	* \param[out]
	* 		pstTicketTransUdInfo : 交易UD数据
	* \return 		true: 获取了UD数据； false： 没有UD数据
	* \author		wugang
	* \date			2015-01-30
	*/
	virtual bool GetUdData(EM_SLE_TRANSACATION_TYPE emTransType, ST_TICKET_TRANS_DETAIL_INFO * pstTicketTransUdInfo) = 0;

	/*! \fn 		virtual bool StartWork(bool bEntry, bool bExitWd, bool bExitUnwd) = 0;
	* \brief        开启检票服务
	* \param[in]
	* 		bEntry :  开启进站端检票
	* 		bExitWd： 开启出站回收端检票
	* 		bExitUnwd： 开启出站刷卡端检票
	* \param[out]   无
	* \return 		true: 开启成功； false： 开启失败
	* \author		wugang
	* \date			2015-01-30
	*/
	virtual bool StartWork(bool bEntry, bool bExitWd, bool bExitUnwd) = 0;

	/*! \fn 		virtual bool StopWork() = 0;
	* \brief        停止检票服务
	* \param[in]    无
	* \param[out]   无
	* \return 		true: 停止成功； false： 停止失败
	* \author		wugang
	* \date			2015-01-30
	*/
	virtual bool StopWork() = 0;

	/*! \fn 		virtual bool RejectTicket() = 0;
	* \brief        拒绝投入回收模块的车票，将该车票退还
	* \param[in]    无
	* \param[out]   无
	* \return 		true: 退还成功； false： 退还失败
	* \author		wugang
	* \date			2015-01-30
	*/
	virtual bool MoveTicket(EM_TICKET_WITHDRAW_WAY emWithdrawWay, EM_CSS_PRODUCTY_CATEGORY emCssProductyCategory, EM_CSS_PRODUCT_ISSUER_ID emCssProductIssuerId, unsigned short usProductyType, ST_TICKET_CONTAINER_LOCATION * pstTicketboxLocation) = 0;

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

	/*! \fn 		AcceptPassengerCard(EM_SLE_TRANSACATION_TYPE emTransType)
	 * \brief 		接受乘客放卡
	 * param[in]	emTransType 设备当前处理的业务
	 * 返回值： 		bool
	 * \author: 	wangyzh/shaopf
	 * \date 		2015-07-02
	*/
	virtual bool AcceptPassengerCard(EM_SLE_TRANSACATION_TYPE emTransType) = 0;

	/*! \fn 		RefundPassengerCard(EM_SLE_TRANSACATION_TYPE emTransType)
	 * \brief 		读取卡信息
	 * param[in]	emTransType 			设备当前处理的业务
	 * param[out]	pstTpuReadCardInfo 		读取的卡的全部信息
	 * 返回值： 		bool
	 * \author: 	shaopf
	 * \date 		2015-07-29
	*/
	virtual bool ReadPassengerCardInfo(EM_SLE_TRANSACATION_TYPE emTransType, ST_TPU_READ_CARD_INFO *pstTpuReadCardInfo) = 0;

	/*! \fn 		StopPollCard()
	 * \brief 		停止寻卡
	 * param[in]	无
	 * param[out]	无
	 * 返回值： 		bool
	 * \author: 	shaopf
	 * \date 		2015-07-29
	*/
	virtual bool StopPollCard() = 0;

	/*! \fn 		SwitchTPUWorkMode()
	 * \brief 		改变TPU工作模式（检票，验票）
	 * param[in]	bQueryMode 		true：验票模式；false：检票模式
	 * 返回值： 		bool
	 * \author: 	shaopf
	 * \date 		2015-07-29
	*/
//	virtual bool SwitchTPUWorkMode(bool bQueryMode) = 0;
protected:
	CLogOper2 *m_pLog; /*!< */

};
class CLogOper2;
typedef Loki::SingletonHolder
<
	Loki::Factory<IAgTicketHandlerApp, std::string, Seq<CLogOper2*> >,
	CreateUsingNew, Loki::LongevityLifetime::DieAsSmallObjectChild
> AgTicketHandlerAppFactory;

#define REGISTER_AFC_AGTICKETHANDLERAPP_OBJECT(className)                                                      \
namespace {                                                                            \
	IAgTicketHandlerApp* createAgTicketHandlerAppBase(CLogOper2 *m_pBizLog) { return new className(m_pBizLog); }                                              \
const bool AgTicketHandlerAppFactory__ = AgTicketHandlerAppFactory::Instance().Register( #className, createAgTicketHandlerAppBase );  \
}
class IAgTicketHandlerApp;
extern	IAgTicketHandlerApp *g_pIAfcAgTicketHandlerApp;

#endif /* CAGTICKETHANDLERAPP_H_ */
