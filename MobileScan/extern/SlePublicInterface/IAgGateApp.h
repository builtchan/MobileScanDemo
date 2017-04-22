/*
 * IAgGateApp.h
 *
 *  Created on: Aug 20, 2014
 *      Author: root
 */

#ifndef IAGGATEAPP_H_
#define IAGGATEAPP_H_

#include "IAfcApp.h"
#include "AfcPublic.h"
#include "ipcpublic.h"
#include "IGateWithDioCommonFunction.h"

#include <loki/Singleton.h>
#include <loki/Factory.h>
#include <loki/Sequence.h>

using namespace Loki;//引用命名空间

class IAgGateApp : public IAfcApp
{
public:

	/*! \fn 		ReleaseOne
	* \brief
	* \param[in]
	* \return
	* \author		wugang
	* \date			2014-09-11
	*/
	virtual void ReleaseOne(bool bEntryDir) = 0;
	virtual void SetEmergencyMode(bool set) = 0;
	virtual void SetWorkMode(EM_GATE_WORKMODE emMode) = 0;
	virtual void SetMaintanceMode(bool set)=0;

protected:
	CLogOper2 *m_pLog; /*!< */
};

class CLogOper2;
typedef Loki::SingletonHolder
<
	Loki::Factory<IAgGateApp, std::string, Seq<CLogOper2*> >,
	CreateUsingNew, Loki::LongevityLifetime::DieAsSmallObjectChild
> AgGateAppFactory;

#define REGISTER_AFC_AGGATEAPP_OBJECT(className)                                                      \
namespace {                                                                            \
	IAgGateApp* createAgGateAppBase(CLogOper2 *m_pBizLog) { return new className(m_pBizLog); }                                              \
const bool AgGateAppFactory__ = AgGateAppFactory::Instance().Register( #className, createAgGateAppBase );  \
}
class IAgGateApp;
extern	IAgGateApp *g_pIAfcAgGateApp;


#endif /* IAGGATEAPP_H_ */
