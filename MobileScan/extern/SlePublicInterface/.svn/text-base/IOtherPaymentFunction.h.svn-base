/*
 * CSleDataApp.h
 *
 *  Created on: Aug 20, 2014
 *      Author: root
 */

#ifndef IOTHERPAYMENTFUNCTION_H_
#define IOTHERPAYMENTFUNCTION_H_

#include "IDeviceCommonFunction.h"
#include <loki/Singleton.h>
#include <loki/Factory.h>
#include <loki/Sequence.h>
#include "CLogOper2.h"

using namespace Loki;
class IOtherPaymentFunction : public IDeviceCommonFunction
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
	Loki::Factory<IOtherPaymentFunction, std::string, Seq<CLogOper2*> >,
	CreateUsingNew, Loki::LongevityLifetime::DieAsSmallObjectChild
> OtherBaseFactory;

#define REGISTER_COMM_OTHER_BIZ(className) \
namespace {                                                                            \
	IOtherPaymentFunction* CreateOtherBase(CLogOper2 *m_SleLog ) { return new className(m_SleLog ); }                                              \
const bool OtherBaseFactory = OtherBaseFactory::Instance().Register( #className, CreateOtherBase );  \
}

class IOtherPaymentFunction;
extern IOtherPaymentFunction *pOtherUnitBase;


#endif /* IOTHERPAYMENTFUNCTION_H_ */
