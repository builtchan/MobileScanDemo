/*
 * IUpsCommonFunction.H
 *
 *  Created on: Aug 7, 2014
 *      Author: wangyzh
 */

#ifndef IUPSCOMMONFUNCTION_H_
#define IUPSCOMMONFUNCTION_H_



#include "AfcPublic.h"
#include "IDeviceCommonFunction.h"
#include "IUpsEventHandler.h"

#include <loki/Singleton.h>
#include <loki/Factory.h>
#include <loki/Sequence.h>
#include <CLogOper2.h>

using namespace Loki;

class IUpsCommonFunction : public IDeviceCommonFunction
{
public:
	/* virtual int PowerOff(unsigned int *puiPowerDelay) = 0;
	 * 关机命令
	 * param[in]:关机延迟时间
	 * \return		同Init
	 *  2014-8-7
	 *  author: wangyzh
	 *  */
	virtual int PowerOff(unsigned int *puiPowerDelay) = 0;

	/* virtual int GetPower(unsigned int *puiPowerRe) = 0;
	 * 获取电量命令
	 * param[out] 电量的大小
	 * \return		同Init
	 *  2014-8-7
	 *  author: wangyzh
	 *  */
	virtual int GetPower(unsigned int *puiPowerRe) = 0;

	/* virtual int RegisterUpsEvent(IUpsEventHandler * pUpsEventHandler) = 0;
	 * 注册UPS回调事件
	 * param[in] IUpsEventHandler * pUpsEventHandler
	 * \return		同Init
	 *  2014-8-7
	 *  author: wangzp
	 *  */
	virtual int RegisterUpsEvent(IUpsEventHandler * pUpsEventHandler) = 0;
};


typedef Loki::SingletonHolder
<
	Loki::Factory<IUpsCommonFunction, std::string, Seq<CLogOper2*> >,
	CreateUsingNew, Loki::LongevityLifetime::DieAsSmallObjectChild
> UpsBaseFactory;

#define REGISTER_COMM_UPS_BIZ(className) \
namespace {                                                                            \
	IUpsCommonFunction* create(CLogOper2 *pSleLog) { return new className(pSleLog); }                                              \
const bool UpsBaseFactory__ = UpsBaseFactory::Instance().Register( #className, create );  \
}



class IUpsCommonFunction;
extern IUpsCommonFunction *pUpsUnitBase;

#endif /* IUPSCOMMONFUNCTION_H_ */
