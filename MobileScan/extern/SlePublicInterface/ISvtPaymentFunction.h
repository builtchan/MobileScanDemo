/*
 * CSleDataApp.h
 *
 *  Created on: Aug 20, 2014
 *      Author: root
 */

#ifndef ISVTPAYMENTFUNCTION_H_
#define ISVTPAYMENTFUNCTION_H_

#include "IDeviceCommonFunction.h"
#include <loki/Singleton.h>
#include <loki/Factory.h>
#include <loki/Sequence.h>
#include "CLogOper2.h"

using namespace Loki;

class ISvtPaymentFunction : public IDeviceCommonFunction
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
	Loki::Factory<ISvtPaymentFunction, std::string, Seq<CLogOper2*> >,
	CreateUsingNew, Loki::LongevityLifetime::DieAsSmallObjectChild
> SvtBaseFactory;

#define REGISTER_COMM_SVT_BIZ(className) \
namespace {                                                                            \
	ISvtPaymentFunction* CreateSvtBase(CLogOper2 *m_SleLog ) { return new className(m_SleLog ); }                                              \
const bool SvtBaseFactory = SvtBaseFactory::Instance().Register( #className, CreateSvtBase );  \
}

class ISvtPaymentFunction;
extern ISvtPaymentFunction *pSvtUnitBase;


#endif /* ISVTPAYMENTFUNCTION_H_ */
