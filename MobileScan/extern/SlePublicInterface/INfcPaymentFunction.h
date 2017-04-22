/*
 * CSleDataApp.h
 *
 *  Created on: Aug 20, 2014
 *      Author: root
 */

#ifndef INFCPAYMENTFUNCTION_H_
#define INFCPAYMENTFUNCTION_H_

#include "IDeviceCommonFunction.h"
#include <loki/Singleton.h>
#include <loki/Factory.h>
#include <loki/Sequence.h>
#include "CLogOper2.h"

using namespace Loki;

class INfcPaymentFunction : public IDeviceCommonFunction
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
	Loki::Factory<INfcPaymentFunction, std::string, Seq<CLogOper2*> >,
	CreateUsingNew, Loki::LongevityLifetime::DieAsSmallObjectChild
> NfcBaseFactory;

#define REGISTER_COMM_NFC_BIZ(className) \
namespace {                                                                            \
	INfcPaymentFunction* CreateNfcBase(CLogOper2 *m_SleLog ) { return new className(m_SleLog ); }                                              \
const bool NfcBaseFactory = NfcBaseFactory::Instance().Register( #className, CreateNfcBase );  \
}

class INfcPaymentFunction;
extern INfcPaymentFunction *pNfcUnitBase;

#endif /* INFCPAYMENTFUNCTION_H_ */
