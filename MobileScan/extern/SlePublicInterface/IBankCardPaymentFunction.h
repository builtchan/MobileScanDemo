/*
 * CSleDataApp.h
 *
 *  Created on: Aug 20, 2014
 *      Author: root
 */

#ifndef IBANKCARDPAYMENTFUNCTION_H_
#define IBANKCARDPAYMENTFUNCTION_H_

#include "IDeviceCommonFunction.h"
#include <loki/Singleton.h>
#include <loki/Factory.h>
#include <loki/Sequence.h>
#include "CLogOper2.h"


using namespace Loki;

class IBankCardPaymentFunction : public IDeviceCommonFunction
{
public:

	/*! \fn 		Open
	* \brief        开启接受插入
	* \param[in]
	* \return 		true  成功    false  失败
	* \author
	* \date			2014-08-06
	*/
	virtual bool Open() = 0;

};

class CLogOper2;
typedef Loki::SingletonHolder
<
	Loki::Factory<IBankCardPaymentFunction, std::string, Seq<CLogOper2*> >,
	CreateUsingNew, Loki::LongevityLifetime::DieAsSmallObjectChild
> BankCardBaseFactory;

#define REGISTER_COMM_BANKCARD_BIZ(className) \
namespace {                                                                            \
	IBankCardPaymentFunction* CreateBankCardBase(CLogOper2 *m_SleLog ) { return new className(m_SleLog ); }                                              \
const bool BankCardBaseFactory = BankCardBaseFactory::Instance().Register( #className, CreateCashBase );  \
}

class IBankCardPaymentFunction;
extern IBankCardPaymentFunction *pBankCardUnitBase;


#endif /* IBANKCARDPAYMENTFUNCTION_H_ */
