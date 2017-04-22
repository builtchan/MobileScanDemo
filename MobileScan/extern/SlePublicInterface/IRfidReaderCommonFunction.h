/***************************************************************

*程序名称：IRfidReaderCommonFunction.h

*版本号：1.0

*功能描述：中软Token回收模块业务接口定义

*作者：龙金贵

*创建日期：2015-01-27

*修改记录：

****************************************************************/

#ifndef IRFIDREADERCOMMONFUNCTION_H_
#define IRFIDREADERCOMMONFUNCTION_H_

#include "AfcPublic.h"
#include "IDeviceCommonFunction.h"
#include "IRfidCommonFunction.h"

#include <loki/Singleton.h>
#include <loki/Factory.h>
#include <loki/Sequence.h>
#include <CLogOper2.h>

using namespace Loki;



class IRfidReaderCommonFunction : public IDeviceCommonFunction, public IRfidCommonFunction
{
public:

};

class CLogOper;
typedef Loki::SingletonHolder
<
	Loki::Factory<IRfidReaderCommonFunction, std::string, Seq<CLogOper2*> >,
	CreateUsingNew, Loki::LongevityLifetime::DieAsSmallObjectChild
> RfidReaderBaseFactory;

#define REGISTER_COMM_RFIDREADER_BIZ(className) \
namespace {                                                                            \
	IRfidReaderCommonFunction* CreateRfidReaderBase(CLogOper2 *m_SleLog ) { return new className(m_SleLog ); }                                              \
const bool RfidReaderBaseFactory__ = RfidReaderBaseFactory::Instance().Register( #className, CreateRfidReaderBase );  \
}

class IRfidReaderCommonFunction;
extern IRfidReaderCommonFunction *pRfidReaderUnitBase;

#endif /* IRFIDREADERCOMMONFUNCTION_H_ */
