/*
 * ITvmUiApp.h
 *
 *  Created on: Aug 20, 2014
 *      Author: root
 */

#ifndef IAGUIAPP_H_
#define IAGUIAPP_H_

#include "AfcPublic.h"
#include "ipcpublic.h"
#include "TransCashData.h"
#include "TransTicketData.h"

#include <loki/Singleton.h>
#include <loki/Factory.h>
#include <loki/Sequence.h>
using namespace Loki;//引用命名空间

class IAgUiApp : public IAfcApp
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

	virtual void ShowTransSuccess(ST_TPU_TRANS_RESULT * pstTransResultSnapshot, ST_BUSINESS_CONTEXT_DATA *pstBusiContextData) = 0;
	virtual void ShowTransFail(ST_TPU_TRANS_RESULT * pstTransResultSnapshot, ST_BUSINESS_CONTEXT_DATA *pstBusiContextData) = 0;

	/*! \fn 		ShowTicketInfo
	* \brief        显示票卡的信息
	* \param[in]    交易类型
	* \param[in]   	票卡的有效性 0：读卡成功可充值 1：读卡成功不可充值 2：读卡失败
	* \param[in]	票卡的信息
	* \return
	* \author		shaopf
	* \date			2015-07-30
	*/
	virtual void ShowTicketInfo(EM_SLE_TRANSACATION_TYPE emSleTransaction, EM_TVM_VALIDITY emTvmValidity, const ST_TPU_READ_CARD_INFO *pstTpuReadCardInfo) = 0;

protected:
	CLogOper2 *m_pBizLog; /*!< */
};

class CLogOper2;
typedef Loki::SingletonHolder
<
	Loki::Factory<IAgUiApp, std::string, Seq<CLogOper2*> >,
	CreateUsingNew, Loki::LongevityLifetime::DieAsSmallObjectChild
> AgUiAppFactory;

#define REGISTER_AFC_AGUIAPP_OBJECT(className)                                                      \
namespace {                                                                            \
	IAgUiApp* createAgUiAppBase(CLogOper2 *m_pBizLog) { return new className(m_pBizLog); }                                              \
const bool AgUiAppFactory__ = AgUiAppFactory::Instance().Register( #className, createAgUiAppBase );  \
}
class IAgUiApp;
extern	IAgUiApp *g_pIAfcAgUiApp;


#endif /* IAGUIAPP_H_ */
