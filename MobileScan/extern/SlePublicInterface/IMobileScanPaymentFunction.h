/*
 * IMobileScanPaymentFunction.h
 *
 *  Created on: Apr 17, 2017
 *      Author: chenjc
 */

#ifndef IMOBILESCANPAYMENTFUNCTION_H_
#define IMOBILESCANPAYMENTFUNCTION_H_

#include "IDeviceCommonFunction.h"
#include "IWebPayEvenHandler.h"
#include <loki/Singleton.h>
#include <loki/Factory.h>
#include <loki/Sequence.h>
#include "CLogOper2.h"

using namespace Loki;

class IMobileScanPaymentFunction : public IDeviceCommonFunction
{
public:
	/*! \fn 		paymentBegin
	* \brief
	* \param[in]	开启支付所需请求数据
	* \return 		true  成功    false  失败
	* \author
	* \date			20170417
	*/
	virtual bool paymentBegin(const void *pData) = 0;

	/*! \fn 		confirmPayment
	* \brief
	* \param[in]	交易完成所需确认数据
	* \return 		true  成功    false  失败
	* \author
	* \date			20170417
	*/
	virtual bool confirmPayment(const void *pData) = 0;

	/*! \fn 		cancelPayment
	* \brief
	* \param[in]	取消交易所需确认数据
	* \return 		true  成功    false  失败
	* \author
	* \date			20170417
	*/
	virtual bool cancelPayment(const void *pData) = 0;

	/* bool RegEventHandle(CIWebPayEvenHandler * pcBillEventHandler );
	 *\brief 注册事件句柄，返回给上层产生事件
	 *\param[in] 事件句柄
	 *\return  true--注册事件成功  false--注册事件失败
	 *\author: chenjc
	 *\date 2017-4-18
	 */
	virtual bool RegEventHandler(CIWebPayEvenHandler * pcWebPayEventHandler) = 0;

	/* bool CIWebPayEvenHandler * GetEventHandler();
	 *\brief
	 *\param[in]
	 *\return  CIWebPayEvenHandler对象
	 *\author: chenjc
	 *\date 2017-4-18
	 */
	virtual CIWebPayEvenHandler * GetEventHandler() = 0;

};

class CLogOper2;
typedef Loki::SingletonHolder
<
	Loki::Factory<IMobileScanPaymentFunction, std::string, Seq<CLogOper2*> >,
	CreateUsingNew, Loki::LongevityLifetime::DieAsSmallObjectChild
> WebBaseFactory;

#define REGISTER_COMM_WEB_PAT_BIZ(className) \
namespace {                                                                            \
	IMobileScanPaymentFunction* CreateWebBase(CLogOper2 *m_SleLog ) { return new className(m_SleLog ); }                                              \
const bool WebBaseFactory = WebBaseFactory::Instance().Register( #className, CreateWebBase );  \
}

class IMobileScanPaymentFunction;
extern IMobileScanPaymentFunction *pMobileScanUnitBase;

#endif /* IMOBILESCANPAYMENTFUNCTION_H_ */
