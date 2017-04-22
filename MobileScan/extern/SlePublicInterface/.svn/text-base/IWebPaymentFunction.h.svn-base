/*
 * CSleDataApp.h
 *
 *  Created on: Aug 20, 2014
 *      Author: root
 */

#ifndef IWEBPAYMENTFUNCTION_H_
#define IWEBPAYMENTFUNCTION_H_

#include "IDeviceCommonFunction.h"
#include <loki/Singleton.h>
#include <loki/Factory.h>
#include <loki/Sequence.h>
#include "CLogOper2.h"

using namespace Loki;

class IWebPaymentFunction : public IDeviceCommonFunction
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
	Loki::Factory<IWebPaymentFunction, std::string, Seq<CLogOper2*> >,
	CreateUsingNew, Loki::LongevityLifetime::DieAsSmallObjectChild
> WebBaseFactory;

#define REGISTER_COMM_WEB_BIZ(className) \
namespace {                                                                            \
	IWebPaymentFunction* CreateWebBase(CLogOper2 *m_SleLog ) { return new className(m_SleLog ); }                                              \
const bool WebBaseFactory = WebBaseFactory::Instance().Register( #className, CreateWebBase );  \
}

class IWebPaymentFunction;
extern IWebPaymentFunction *pWebUnitBase;

#endif /* IWEBPAYMENTFUNCTION_H_ */
