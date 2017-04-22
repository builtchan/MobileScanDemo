/*
 * ITvmUiApp.h
 *
 *  Created on: Aug 20, 2014
 *      Author: root
 */

#ifndef ITVMUIAPP_H_
#define ITVMUIAPP_H_

#include "AfcPublic.h"
#include "ipcpublic.h"
#include "TransCashData.h"
#include "TransTicketData.h"

#include <loki/Singleton.h>
#include <loki/Factory.h>
#include <loki/Sequence.h>
using namespace Loki;//引用命名空间

class ITvmUiApp : public IAfcApp
{
public:

	/*! \fn 		RefreshRunMode
	* \brief        状态发生变化时,刷新显示界面
	* \param[in]
	* \return
	* \author		wugang
	* \date			2014-09-11
	*/
	virtual void RefreshRunMode() = 0;

	/*	函数描述：根据交易类型设置交易开始
			参数说明：
			入参：
		EM_SLE_TRANSACATION_TYPE  emTransType ：交易类型。
		  返回值：
		0:成功 ，-1 ：false;*/
	virtual void TransBegin(EM_SLE_TRANSACATION_TYPE emTransType) = 0;
	virtual void TransEnd(EM_SLE_TRANSACATION_TYPE emTransType) = 0;
	/*! \fn 		ShowPaymentInfo
	* \brief        显示支付界面
	* \param[in]    ST_TVM_PAYMENT_NOTIFY_INFO * pstPaymentInfo   支付信息
	* \return
	* \author		wangzp
	* \date			2014-08-06
	*/
	virtual void ShowPaymentInfo(const ST_TVM_PAYMENT_NOTIFY_INFO * pstPaymentInfo, const ST_DENO_INFO * pstAllowBillDeno, const ST_DENO_INFO * pstAllowCoinDeno) = 0;

	/*! \fn 		RefreshPaymentInfo
	* \brief        刷新显示支付界面
	* \param[in]    DWORD dwTotalPrice   应付金额
	* \param[in]    DWORD dwTicketCount        交易总数量
	* \param[in]    DWORD dwPaymentAmount          已支付总金额
	* \return
	* \author		wugang
	* \date			2014-08-06
	* */
	virtual void RefreshCashPaymentAmount(DWORD dwPaymentAmount) = 0;
	virtual void RefreshPaymentInfo(DWORD dwTotalPrice, DWORD dwTicketCount, DWORD dwPaymentAmount) = 0;

	virtual void PaymentFinish() = 0;

	/*! \fn 		ShowConfirmButton
	* \brief        显示确定按钮界面
	* \param[in]    EM_TRANSACATION_TYPE emTransType
	* \return
	* \author		wangzp
	* \date			2014-08-06
	*/
	virtual void ShowConfirmButton(EM_SLE_TRANSACATION_TYPE emTransType) = 0;
//	virtual void ShowConfirmButton(EM_TVM_TRANS_TYPE emTransType) = 0;
	/*! \fn 		ShowVendingProcess
	* \brief        显示售票信息界面
	* \param[in]    pVendingRequestInfo   售票信息
	*  \param[in]   iVendedCount 已处理数量,为0标识开始处理
	* \return
	* \author		wangzp
	* \date			2014-08-06
	*/
	virtual void ShowVendingProcess(ST_TVM_VENDING_REQUEST_INFO * pVendingRequestInfo, int iVendedCount) = 0;

	/*! \fn 		ShowChangingProcess
	* \brief        显示找零信息界面
	* \param[in]    pVendingRequestInfo   交易快照
	*  \param[in]   iTotalChangeAmount 找零总金额
	* \return
	* \author		wangzp
	* \date			2014-08-06
	*/
	virtual void ShowChangingProcess(ST_TVM_VENDING_REQUEST_INFO * pVendingRequestInfo, int iTotalChangeAmount, int iAlreadyChangeAmount, bool bBillChange, bool bCoinChange) = 0;
	/*! \fn 		ShowTransCancel
	* \brief        显示交易取消界面
	* \param[in]
	* \return 		true  显示成功    false  显示失败
	* \author		wangzp
	* \date			2014-08-06
	*/
	virtual void ShowTransCancelBegin(bool bBillReturn, bool bCoinReturn) = 0;
	virtual void ShowTransCancelResult(EM_TRANSACATION_RESULT emTransacationResult, bool bSvt, bool bBankcard) = 0;


	/*! \fn 		HandleTransEndInfo
	* \brief        交易结束处理，给界面发交易结束通知
	* \param[in]    ST_TRANS_DATA_INFO stTransDataInfo    交易信息结构体
	* \param[in]    int iTransSnapshootLogCount           交易快照记录数
	* \param[in]    int iTransSnapshootLen                交易快照记录长度
	* \param[in]    ST_TRANRESULT_CSS stTransResultCss    交易快照结构体
	* \return 		true  处理成功    false  处理失败
	* \author		wangzp
	* \date			2014-08-06
	*/
	virtual void ShowVendingResult(EM_TRANSACATION_RESULT emTransacationResult, ST_TVM_VENDING_REQUEST_INFO * pstVendingInfo, CTransCashData * pcTransCashData, int iVendTicketCount, bool bSvt, bool bBankcard) = 0;


	/*! \fn 		ShowHelpProcessInfo
	* \brief        显示招援处理界面
	* \param[in]    bFireOrCancel:	true 触发求助; false 取消求助
	* \return 		true  显示成功    false  显示失败
	* \author		wangzp
	* \date			2014-08-06
	*/
	virtual bool ShowHelpProcessInfo(bool bFireOrCancel) = 0;

	virtual bool ShowManComeProcessInfo(bool bFireOrCancel) = 0;

	//更新张数信息
	virtual void RefreshBuyTicketCount(DWORD dwBuyTicketCount, DWORD dwPrice) = 0;

/*--------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------*/
/********************************wangyzh20150617添加函数**********************************************/
	/*! \fn 		ShowTicketInfo
	* \brief        显示票卡的信息
	* \param[in]    交易类型
	* \param[in]   	票卡的有效性 0：读卡成功可充值 1：读卡成功不可充值 2：读卡失败
	* \param[in]	票卡的信息
	* \return
	* \author		wangyzh
	* \date			2015-06-17
	*/
	virtual void ShowTicketInfo(EM_SLE_TRANSACATION_TYPE emSleTransaction, EM_TVM_VALIDITY emTvmValidity, const ST_TPU_READ_CARD_INFO *pstTpuReadCardInfo) = 0;

	/*! \fn 		ShowRechargeProcess
	* \brief        显示充值过程
	* param[in]		充值信息结构体
	* \return
	* \author		wangyzh
	* \date			2015-06-17
	*/
	virtual void ShowRechargeProcess(ST_TVM_RECHARGE_REQUEST_INFO stRechargeInfo) = 0;


	/*! \fn 		RefreshRechargeValue
	* \brief        更新充值金额界面
	* param[in]		更新充值金额的入参金额
	* \return
	* \author		wangyzh
	* \date			2015-06-18
	*/
	virtual void RefreshRechargeValue(DWORD dwRechargeAmount) = 0;

	/*! \fn 		ShowRechargeChangingProcess
	* \brief        显示充值找零过程
	* param[in] 	充值结构体
	* param[in]		找零总金额
	* param[in]		已找零金额
	* param[in]		纸币找零标记
	* param[in]		硬币找零标记
	* \return
	* \author		wangyzh
	* \date			2015-06-17
	*/
	virtual void ShowRechargeChangingProcess(ST_TVM_RECHARGE_REQUEST_INFO stRechargeInfo, int iTotalChangeAmount, int iAlreadyChangeAmount, bool bBillChange, bool bCoinChange) = 0;


	/*! \fn 		ShowRechargeResult
	* \brief        显示充值结果
	* param[in] 	交易结果
	* param[in]		充值结构体信息
	* param[in]		现金流转结构体
	* param[in]		储值卡的点亮标记
	* param[in]		银行卡的点亮标记
	* param[in]		打印的标记
	* \return
	* \author		wangyzh
	* \date			2015-06-17
	*/
	virtual void ShowRechargeResult(EM_TRANSACATION_RESULT emTransResult, ST_TVM_RECHARGE_REQUEST_INFO * pstRechargeInfo, CTransCashData * pcTransCashData, bool bSvt, bool bBank, bool bShowPrintBtn) = 0;

	/*! \fn 		ShowTicketCardTaken
	* \brief        显示票卡取走
	* \return
	* \author		wangyzh
	* \date			2015-06-19
	*/
	virtual void ShowTicketCardTaken() = 0;

	/*! \fn 		ShowQueryResult
	* \brief        显示查询结果
	* param[in] 	交易结果
	* \return
	* \author		wangyzh
	* \date			2015-07-03
	*/
	virtual void ShowQueryResult(EM_TRANSACATION_RESULT emTransResult) = 0;

	/*! \fn 		CashRejectedNotify
	* \brief        现金被拒收通知
	* param[in]
	* \return
	* \author		shaopf
	* \date			2015-07-27
	*/
	virtual void CashRejectedNotify() = 0;


	/*! \fn 		ShowSvtVendingResult
	* \brief        显示储值卡售单程票结果
	* \param[in]    EM_TRANSACATION_RESULT    交易结果
	* \param[in]    ST_TVM_VENDING_REQUEST_INFO    售票信息
	* \param[in]    CTransCashData                现金流转数据
	* \param[in]    iVendTicketCount 写票成功的数量
	* \param[in]
	* \param[in]
	* \param[in]	卡信息
	* \return 		true  处理成功    false  处理失败
	* \author		wangyzh
	* \date			2015-12-02
	*/
	virtual void ShowSvtVendingResult(EM_TRANSACATION_RESULT emTransacationResult, ST_TVM_VENDING_REQUEST_INFO * pstVendingInfo, CTransCashData * pcTransCashData, int iVendTicketCount, bool bSvt, bool bBankcard, const ST_TPU_READ_CARD_INFO *pstTpuReadCardInfo) = 0;

	virtual void FlashCardNotify(EM_TVM_RECHARGE_FLASH emFlashCard) = 0;

protected:
	CLogOper2 *m_pBizLog; /*!< */
};

class CLogOper2;
typedef Loki::SingletonHolder
<
	Loki::Factory<ITvmUiApp, std::string, Seq<CLogOper2*> >,
	CreateUsingNew, Loki::LongevityLifetime::DieAsSmallObjectChild
> TvmUiAppFactory;

#define REGISTER_AFC_TVMUIAPP_OBJECT(className)                                                      \
namespace {                                                                            \
	ITvmUiApp* createTvmUiAppBase(CLogOper2 *m_pBizLog) { return new className(m_pBizLog); }                                              \
const bool TvmUiAppFactory__ = TvmUiAppFactory::Instance().Register( #className, createTvmUiAppBase );  \
}
class ITvmUiApp;
extern	ITvmUiApp *g_pIAfcTvmUiApp;


#endif /* ITVMUIAPP_H_ */
