/*
 * CSleDataApp.h
 *
 *  Created on: Aug 20, 2014
 *      Author: root
 */

#ifndef IVOUCHERPAYMENTFUNCTION_H_
#define IVOUCHERPAYMENTFUNCTION_H_

#include "IDeviceCommonFunction.h"
#include <loki/Singleton.h>
#include <loki/Factory.h>
#include <loki/Sequence.h>
#include "CLogOper2.h"

using namespace Loki;

class IVoucherPaymentFunction : public IDeviceCommonFunction
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
	Loki::Factory<IVoucherPaymentFunction, std::string, Seq<CLogOper2*> >,
	CreateUsingNew, Loki::LongevityLifetime::DieAsSmallObjectChild
> VoucherBaseFactory;

#define REGISTER_COMM_VOUCHER_BIZ(className) \
namespace {                                                                            \
	IVoucherPaymentFunction* CreateVoucherBase(CLogOper2 *m_SleLog ) { return new className(m_SleLog ); }                                              \
const bool VoucherBaseFactory = VoucherBaseFactory::Instance().Register( #className, CreateVoucherBase );  \
}

class IVoucherPaymentFunction;
extern IVoucherPaymentFunction *pVoucherUnitBase;

#endif /* IVOUCHERPAYMENTFUNCTION_H_ */
