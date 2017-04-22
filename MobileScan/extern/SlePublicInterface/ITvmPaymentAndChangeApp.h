/*
 * TVMPayment.h
 *
 *  Created on: Aug 16, 2014
 *      Author: wangzp
 */

#ifndef ITVMPAYMENTANDCHANGEAPP_H_
#define ITVMPAYMENTANDCHANGEAPP_H_

#include "AfcPublic.h"
#include "TransCashData.h"
#include <list>
#include <map>
#include <loki/Singleton.h>
#include <loki/Factory.h>
#include <loki/Sequence.h>
using namespace Loki;//引用命名空间
using namespace std;

class ITvmPaymentAndChangeApp : public IAfcApp
{
public:

	/*! \fn 		PayBegin
	* \brief 		开启支付
	* \param[in]  	ST_TVM_PAY_TYPE    stTvmPayType    支持的支付类型, 开启值为true的支付类型
	* \param[in]  	ST_TVM_PAY_TYPE    * pstTvmPayType    开启成功的支付类型
	* \return 		none
	* \author		wangzp
	* \date			2014-08-06
	*/
	virtual void PaymentBegin(EM_SLE_TRANSACATION_TYPE emTransType, int iTicketType, int iTotalPrice, CTransCashData * pCTransCashData,
			ST_TVM_PAY_TYPE stTvmPayType, ST_TVM_PAY_TYPE * pstTvmPayOkType,
			ST_DENO_INFO * pstAccpeptedBanknote, ST_DENO_INFO * pstAccpeptedBankcoin) = 0;

	virtual void CashPaymentContinue(EM_SLE_TRANSACATION_TYPE emTransType, int iTicketType, int iTotalPrice, CTransCashData * pCTransCashData,
			ST_TVM_PAY_TYPE stTvmPayType, ST_TVM_PAY_TYPE * pstTvmPayOkType,
			ST_DENO_INFO * pstAccpeptedBanknote, ST_DENO_INFO * pstAccpeptedBankcoin) = 0;


	/*! \fn 		PaymentPause
	* \brief 		同步执行关闭所有支付
	* \param[in]  	bool bSync    是否同步
	* \return 		none
	* \author		wangzp
	* \date			2014-08-06
	*/
	virtual void PaymentPause(bool bSync) = 0;

	/*! \fn 		PaymentPause
	* \brief 		同步执行关闭指定方式支付
	* \param[in]  	bool bSync    是否同步
	* \param[in]  	ST_TVM_PAY_TYPE    stTvmPayType    关闭值为false的支付类型
	* \return 		none
	* \author		wangzp
	* \date			2014-08-06
	*/
	virtual void PaymentPause(bool bSync, ST_TVM_PAY_TYPE stTvmPayType) = 0;

	/*! \fn 		PaymentConfirm
	* \brief 		收入现金，结束支付
	* \param[in]	bPressInBill  		压入纸币
	* \param[in]	bPressInCoin		压入硬币
	* \param[out]  	pBanknoteDenominationCashboxMap    	实际收入纸币信息列表
	* \param[out]  	pCoinDenominationCashboxMap    		实际收入硬币信息列表
	* \param[out]  	piBanknoteEncashCount    			实际收入纸币信息数目
	* \param[out]  	piCoinEncashCount    				实际收入硬币信息数目
	* \return 		none
	* \author		Longjg
	* \date			2016-12-31
	*/
	virtual void PaymentConfirm(bool bPressInBill, bool bPressInCoin, map<int, ST_CASH_CONTAINER_LOCATION>* pBanknoteDenominationCashboxMap, map<int, ST_CASH_CONTAINER_LOCATION>* pCoinDenominationCashboxMap, int* piBanknoteEncashCount, int* piCoinEncashCount) = 0;

	/*! \fn 		PaymentCancel
	* \brief        交易取消
	* \param[in]
	* \return 		交易取消退还执行结果结构体
	* \author		wangzp
	* \date			2014-08-06
	*/
	/* modify by liuchao 20170329
	virtual void PaymentCancel(bool * pbBanknoteOK, bool * pbCoinOK) = 0;
	*/
	virtual void PaymentCancel(bool * pbBanknoteOK, bool * pbCoinOK, EM_SLE_TRANSACATION_TYPE emTransType, int * iBankRefundCount, int *iCoinRefundCount) = 0;


	/*! \fn 		ChangeJudge
	* \brief 		找零预判
	* \param[int]   int iChangeMoney  需要找零金额
	* \return 		true  找零预判OK    false  找零预判NG
	* \author		wangzp
	* \date			2014-08-06
	*/
	virtual bool ChangeJudge(EM_SLE_TRANSACATION_TYPE emTransType, int iTicketType,int iChangeMoney) = 0;

	/*! \fn 		Change
	* \brief        现金找零
	* \param[in]    int iChangeMoney  需要找零金额
	* \param[out]   map<int,ST_MEDIA_DATA_UNIT_INFO> * pMap    实际找零信息容器
	* \return 		true  找零OK    false  找零NG
	* \author		wangzp
	* \date			2014-08-06
	*/
	virtual bool Change(EM_SLE_TRANSACATION_TYPE emTransType, int iTicketType,int iChangeMoney, int * piActuallyChangeMoney, list<ST_BIZ_CASH_DATA_INFO> * pChangeInfoList) = 0;

	virtual bool PaymentValidJudge(ST_TVM_PAY_TYPE stTvmPayType) = 0;

	/*! \fn 		OperateCashbox
	 * \brief 		操作钱箱
	 * param[in] 	stCashboxLocation: 钱箱ID
	 * param[in] 	emBoxOpType：钱箱的操作 上锁 解锁 补充
	 * param[in]	iTimeout ： 超时时间，单位 s
	 * 返回值： 		操作结果
	 * \author: 	wugang
	 * \date 		2015-02-20
	*/
	virtual bool OperateCashbox(ST_CASH_CONTAINER_LOCATION stCashboxLocation,  EM_CONTAINER_OPERATION_TYPE emBoxOpType, int iTimeout) = 0;

protected:
	CLogOper2 *m_pBizLog; /*!< */
};

class CLogOper2;
typedef Loki::SingletonHolder
<
	Loki::Factory<ITvmPaymentAndChangeApp, std::string, Seq<CLogOper2*> >,
	CreateUsingNew, Loki::LongevityLifetime::DieAsSmallObjectChild
> TvmPaymentAndChangeAppFactory;

#define REGISTER_AFC_TVMPAYMENTANDCHANGEAPP_OBJECT(className)     \
namespace {                                                                            \
	ITvmPaymentAndChangeApp* CreateTvmPaymentAndChangeAppBase(CLogOper2 *m_pBizLog) { return new className(m_pBizLog); }                                              \
const bool TvmPaymentAndChangeAppFactory__ = TvmPaymentAndChangeAppFactory::Instance().Register( #className, CreateTvmPaymentAndChangeAppBase );  \
}
class ITvmPaymentAndChangeApp;
extern	ITvmPaymentAndChangeApp *g_pIAfcTvmPaymentAndChangeApp;

#endif /* ITVMPAYMENTANDCHANGEAPP_H_ */
