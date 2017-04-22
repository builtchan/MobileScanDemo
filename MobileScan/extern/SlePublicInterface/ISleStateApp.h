/*
 * CSleDataApp.h
 *
 *  Created on: Sep 17, 2014
 *      Author: wangzp
 */

//将环境APP的代码移植
//安全状态添加故障码


#ifndef ISTATEAPP_H_
#define ISTATEAPP_H_

#include "AfcPublic.h"

#include <set>
#include <map>
#include <loki/Singleton.h>
#include <loki/Factory.h>
#include <loki/Sequence.h>
using namespace Loki;//引用命名空间

using namespace std;


class ISleStateApp : public IAfcApp
{
public:

	/*! \fn 		SetTvmLimitTransType
		*
		* \brief        设置TVM限制交易命令
		* \param[in]    EM_STATUS_SOURCE emSleBizType
		* \param[in]    EM_TVM_LIMIT_TRANSACATION_CMD emTvmLimitTransCmd
		* \return 		none
		* \author		wangzp
		* \date			2014-09-17
		*/
		virtual void SetTvmLimitTransCmd(EM_STATUS_SOURCE emSleBizType, EM_TVM_LIMIT_TRANSACATION_CMD emTvmLimitTransCmd) = 0;

		/*! \fn 		SetAgLimitTransType
		*
		* \brief        设置AG限制交易命令
		* \param[in]    EM_RUN_STATE_FOR_SC emRunSatae
		* \param[in]    EM_TVM_LIMIT_TRANSACATION_CMD emTvmLimitTransCmd
		* \return 		none
		* \author		wangzp
		* \date			2014-09-17
		*/
		virtual void SetAgLimitTransCmd(EM_STATUS_SOURCE emSleBizType, EM_AG_LIMIT_TRANSACATION_CMD emAgLimitTransCmd) = 0;

	/*! \fn 		SetSystemServiceMode
		*
		* \brief        设置系统服务模式
		* \param[in]    EM_RUN_STATE_FOR_SC emRunSatae
		* \param[in]    EM_SLE_SERVICE_MDDE emServiceMode
		* \param[in]    bool bEffective    生效标志
		* \return 		none
		* \author		wangzp
		* \date			2014-09-17
		*/
		virtual void SetSystemServiceMode(EM_STATUS_SOURCE emSleBizType, EM_SLE_SERVICE_MDDE emServiceMode, bool bEffective) = 0;

	/*! \fn 		SetSystemRunMode
		*
		* \brief        设置系统运营模式
		* \param[in]    EM_RUN_STATE_FOR_SC emRunSatae
		* \param[in]    EM_SYSTEM_RUN_MODE emRunMode
		* \return 		none
		* \author		wangzp
		* \date			2014-09-17
		*/
		virtual void SetSystemRunMode(EM_STATUS_SOURCE emSleBizType, EM_SYSTEM_RUN_MODE emRunMode, bool bEffective) = 0;

	/*! \fn 		GetSystemRunMode
		*
		* \brief        获取系统运营模式
		* \param[in]    none
		* \return 		ST_SYSTEM_RUN_MODE
		* \author		wangzp
		* \date			2014-09-17
		*/
		virtual ST_SYSTEM_RUN_MODE GetSystemRunMode() = 0;

	/*! \fn 		SetSystemRunState
		*
		* \brief        设置系统运营状态
		* \param[in]    EM_RUN_STATE_FOR_SC emRunSatae
		* \return 		none
		* \author		wangzp
		* \date			2014-09-17
		*/
		virtual void SetSystemRunState(EM_STATUS_SOURCE emSleBizType, EM_RUN_STATE emRunSatae) = 0;

	/*! \fn 		GetSystemRunState
		*
		* \brief        获取系统运营状态
		* \param[in]    none
		* \return 		EM_RUN_STATE_FOR_SC
		* \author		wangzp
		* \date			2014-09-17
		*/
		virtual EM_RUN_STATE GetSystemRunState() = 0;

	/*! \fn 		SetSystemCommunicateState
		*
		* \brief        设置系统网络通信状态
		* \param[in]    EM_CONNECT_STATE_CODE emConnectState
		* \return 		none
		* \author		wangzp
		* \date			2014-09-17
		*/
		virtual void SetNetCommunicateState(EM_STATUS_SOURCE emSleBizType, EM_CONNECT_STATE_CODE emConnectState) = 0;

	/*! \fn 		GetSystemCommunicateState
		*
		* \brief        获取系统网络通信状态
		* \param[in]    none
		* \return 		EM_CONNECT_STATE_CODE
		* \author		wangzp
		* \date			2014-09-17
		*/
		virtual EM_CONNECT_STATE_CODE GetSystemCommunicateState() = 0;

		/*! \fn 		SetSystemCommunicateState
				*
				* \brief        设置sle运行状态
				* \param[in]    EM_SLE_RUN_STATUS emSleRunState
				* \return 		none
				* \author		liuyp
				* \date			2016-09-17
		*/
		virtual void SetSleRunState(EM_STATUS_SOURCE emSleBizType, EM_SLE_RUN_STATUS emSleRunState)= 0;

		/* \brief        获取sle运行状态
				* \param[in]    none
				* \return 		EM_SLE_RUN_STATUS
				* \author		liuyp
				* \date			2016-09-17
		*/
		virtual EM_SLE_RUN_STATUS  GetSleRunState()= 0;

	/*! \fn 		SetSystemClockState
		*
		* \brief        设置系统时钟状态
		* \param[in]    EM_CLOCK_DIFFERENCE_CODE emClockDifference
		* \return 		none
		* \author		wangzp
		* \date			2014-09-17
		*/
		virtual void SetSystemClockState(EM_STATUS_SOURCE emSleBizType, EM_CLOCK_STATE emClockDifference) = 0;

	/*! \fn 		GetSystemClockState
		*
		* \brief        获取系统时钟状态
		* \param[in]    none
		* \return 		EM_CLOCK_DIFFERENCE_CODE
		* \author		wangzp
		* \date			2014-09-17
		*/
		virtual EM_CLOCK_STATE GetSystemClockState() = 0;

	/*! \fn 		SetSystemLoginState
		*
		* \brief        设置系统系统登录状态
		* \param[in]    EM_LOGIN_STATE_CODE emLoginState
		* \return 		none
		* \author		wangzp
		* \date			2014-09-17
		*/
		virtual void SetSystemLoginState(EM_STATUS_SOURCE emSleBizType, EM_LOGIN_STATE_CODE emLoginState) = 0;

	/*! \fn 		GetSystemLoginState
		*
		* \brief        获取系统系统登录状态
		* \param[in]    none
		* \return 		EM_LOGIN_STATE_CODE
		* \author		wangzp
		* \date			2014-09-17
		*/
		virtual EM_LOGIN_STATE_CODE GetSystemLoginState() = 0;

	/*! \fn 		SetSystemSCAutoRunState
		*
		* \brief        设置系统SC自动运营状态
		* \param[in]    EM_SC_AUTO_RUN_STATE_CODE emSCAutoRunState
		* \return 		none
		* \author		wangzp
		* \date			2014-09-17
		*/
		virtual void SetSystemSCAutoRunState(EM_STATUS_SOURCE emSleBizType, EM_SC_AUTO_RUN_STATE_CODE emSCAutoRunState) = 0;

	/*! \fn 		SetSystemRescueMenuState
		*
		* \brief        设置招援按钮状态
		* \param[in]    EM_SEEK_RESCUE_MENU_STATE_CODE emSeekRescueMenuState
		* \return 		none
		* \author		wangzp
		* \date			2014-09-17
		*/
		virtual void SetSystemRescueMenuState(EM_SEEK_RESCUE_MENU_STATE_CODE emSeekRescueMenuState) = 0;

	/*! \fn 		SetCashSafeDoorState
		*
		* \brief        设置现金安全门综合状态
		* \param[in]    EM_CASH_SAFE_DOOR_STATE_CODE emCashSafeDoorState
		* \return 		none
		* \author		wangzp
		* \date			2014-09-17
		*/
		virtual void SetCashSafeDoorState(EM_STATUS_SOURCE emSleBizType, EM_CASH_SAFE_DOOR_STATE_CODE emCashSafeDoorState) = 0;

		/*! \fn 		SetBoxBaffleState
			*
			* \brief        设置箱子翻版综合状态
			* \param[in]    EM_BOX_BAFFLE_STATE emBoxBaffleState
			* \return 		none
			* \author		longjg
			* \date			2016-11-17
			*/
		virtual void SetBoxBaffleState(EM_STATUS_SOURCE emSleBizType, EM_BOX_BAFFLE_STATE emBoxBaffleState) = 0;

	/*! \fn 		SetMaintenceDoorSyntheticState
		*
		* \brief        设置维修门综合状态
		* \param[in]    EM_MAINTENCE_DOOR_STATE emMaintenceDoorSyntheticState
		* \return 		none
		* \author		wangzp
		* \date			2014-09-17
		*/
		virtual void SetMaintenceDoorSyntheticState(EM_STATUS_SOURCE emSleBizType, EM_MAINTENCE_DOOR_STATE emMaintenceDoorSyntheticState) = 0;

	/*! \fn 		GetMaintenceDoorSyntheticState
		*
		* \brief        获取维修门综合状态
		* \param[in]    none
		* \return 		EM_MAINTENCE_DOOR_STATE
		* \author		wangzp
		* \date			2014-09-17
		*/
		virtual EM_MAINTENCE_DOOR_STATE GetMaintenceDoorSyntheticState() = 0;

	/*! \fn 		SetSecurityStatus
		*
		* \brief        设置安全状态
		* \param[in]    EM_SECURITY_STATUS emSecurityStatus
		* \return 		none
		* \author		wangzp
		* \date			2014-09-17
		*/
		virtual void SetSecurityStatus(EM_STATUS_SOURCE emSleBizType, EM_SECURITY_STATUS emSecurityStatus) = 0;

	/*! \fn 		SetSystemDiskUseStatus
		*
		* \brief        设置磁盘空间状态
		* \param[in]    EM_SYSTEM_ALL_DISK_USE_CODE emSystemDiskUse
		* \return 		none
		* \author		wangzp
		* \date			2014-09-17
		*/
		virtual void SetSystemDiskUseStatus(EM_STATUS_SOURCE emSleBizType, EM_SYSTEM_ALL_DISK_USE_CODE emSystemDiskUse) = 0;

	/*! \fn 		SetSystemDBDiskUseStatus
		*
		* \brief        设置数据库磁盘空间状态
		* \param[in]    EM_SYSTEM_DB_DISK_USE_CODE emSystemDBUse
		* \return 		none
		* \author		wangzp
		* \date			2014-09-17
		*/
		virtual void SetSystemDBDiskUseStatus(EM_STATUS_SOURCE emSleBizType, EM_SYSTEM_DB_DISK_USE_CODE emSystemDBUse) = 0;

	/*! \fn 		SetSystemCPUUseStatus
		*
		* \brief        设置CPU使用状态
		* \param[in]    EM_CPU_USE_CODE emCPUUse
		* \return 		none
		* \author		wangzp
		* \date			2014-09-17
		*/
		virtual void SetSystemCPUUseStatus(EM_CPU_USE_CODE emCPUUse) = 0;

	/*! \fn 		SetSystemCPUUseStatus
		*
		* \brief        设置内存使用状态
		* \param[in]    EM_RAM_USE_CODE emRamUse
		* \return 		none
		* \author		wangzp
		* \date			2014-09-17
		*/
		virtual void SetSystemRAMUseStatus(EM_RAM_USE_CODE emRamUse) = 0;


	/*! \fn 		SetSystemOperationStatus
		*
		* \brief        设置系统当前状态
		* \param[in]    EM_SLE_OPERATION_STATUS emSleRunStatus
		* \return 		none
		* \author		wangzp
		* \date			2014-09-17
		*/
		virtual void SetSystemOperationStatus(EM_STATUS_SOURCE emSleBizType, EM_SLE_OPERATION_STATUS emSleRunStatus) = 0;

	/*! \fn 		GetSystemRunStatus
		*
		* \brief        获取系统当前状态
		* \param[in]    EM_SLE_OPERATION_STATUS emSleRunStatus
		* \return 		none
		* \author		wangzp
		* \date			2014-09-17
		*/
		virtual EM_SLE_OPERATION_STATUS GetSystemOperationStatus() = 0;

	/*! \fn 		AddSystemErrorToHashMap
	    *
		* \brief        增加某个故障码信息到本地故障码哈析表
		* \param[in]    int iErrorCode    故障码
		* \param[in]    EM_STATUS_SOURCE emStatusSource        发生源
		* \return 		true  设置成功    false  集合中无该故障码
		* \author		wangzp
		* \date			2014-09-17
		*/
		virtual bool AddSystemErrorCode(int iErrorCode, const char * pAddtionalInfo, EM_STATUS_SOURCE emStatusSource) = 0;

	/*! \fn 		ClearSystemErrorCode
		*
		* \brief        清除某个故障码信息到本地故障码哈析表
		* \param[in]    int iErrorCode    故障码
		* \param[in]    EM_STATUS_SOURCE emStatusSource        发生源
		* \return 		true  设置成功    false  集合中无该故障码
		* \author		wangzp
		* \date			2014-09-17
		*/
		virtual bool ClearSystemErrorCode(int iErrorCode, EM_STATUS_SOURCE emStatusSource) = 0;

	/*! \fn 		SetSystemPaymentControl
		*
		* \brief        设置系统支付控制命令
		* \param[in]    ST_TVM_PAY_TYPE stPaymentMethod    支付方式
		* \return 		none
		* \author		wangzp
		* \date			2014-09-17
		*/
		virtual void SetSystemPaymentControl(ST_TVM_PAY_TYPE stPaymentMethod) = 0;

	/*! \fn 		SetSystemChangeControl
		*
		* \brief        设置系统找零控制命令
		* \param[in]    bool bSupportChange    true：有找零    false：无找零
		* \return 		none
		* \author		wangzp
		* \date			2014-09-17
		*/
		virtual void SetSystemChangeControl(bool bSupportBillChange, bool bSupportCoinChange) = 0;

	/*! \fn 		CanDoTransation
		*
		* \brief        交易预判
		* \param[in]    EM_TRANSACATION_TYPE emTransType    交易类型
		* \return 		true   可交易    false  不可交易
		* \author		wangzp
		* \date			2014-09-17
		*/
		virtual bool CanDoTransation(EM_SLE_TRANSACATION_TYPE emTransType) = 0;

	/*! \fn 		GetCashTypeCanChange
		*
		* \brief        获取可找零的现金类型
		* \return 		无
		* \author		wangzp
		* \date			2014-09-17
		*/
		virtual void GetCashTypeCanChange(bool * bBillCanChange, bool * bCoinCanChange) = 0;

	/*! \fn 		IsSystemServiceMode
		*
		* \brief        是否为指定服务模式
		* \param[in]    EM_SLE_RUN_MDDE emSleRunMode   指定的运营模式
		* \return 		true   维修模式    false  非维修模式
		* \author		wangzp
		* \date			2014-09-17
		*/
		virtual bool IsSystemServiceMode(EM_SLE_SERVICE_MDDE emSleRunMode) = 0;

	/*! \fn 		GetAgSideRunMode
		*
		* \brief        获取AG端运营模式
		* \param[in]    EM_AG_SIDE emAgSide    端枚举
		* \return 		EM_AG_SIDE_MODE        端运营模式
		* \author		wangzp
		* \date			2014-09-17
		*/
		virtual EM_AG_SIDE_MODE GetAgSideRunMode(EM_AG_SIDE emAgSide) = 0;

	/*! \fn 		SystemCanServe
		*
		* \brief        系统是否可以服务
		* \param[in]    none
		* \return 		true   维修模式    false  非维修模式
		* \author		wangzp
		* \date			2014-09-17
		*/
		virtual bool SystemCanServe() = 0;


	/*! \fn 		CanChangeByCashbox
		*
		* \brief        判断某钱箱是否可以找零
		* \param[in]    ST_CASH_CONTAINER_LOCATION stCashboxID    钱箱ID
		* \return 		true    可找零    false    不可找零
		* \author		wangzp
		* \date			2014-09-17
		*/
		virtual bool CanChangeByCashbox(ST_CASH_CONTAINER_LOCATION stCashboxID) = 0;

	/*! \fn 		GetPaymentMethod
	    *
		* \brief        获取支付方式
		* \param[out]   ST_TVM_PAY_TYPE * pstPaymentMethod    支付方式
		* \return 		none
		* \author		wangzp
		* \date			2014-09-17
		*/
		virtual void GetPaymentMethodByState(ST_TVM_PAY_TYPE * pstPaymentMethod) = 0;

	/*! \fn 		GetChangeDenominationInfo
		*
		* \brief        获取各币种找零情况
		* \param[out]   BYTE * pbDenomination   根据币种顺序依次排序，暂定找零币种最多8种，例如只币种2可找零，则返回0x02
		* \return 		none
		* \author		wangzp
		* \date			2014-09-17
		*/
	//	virtual void GetChangeDenominationInfo(WORD * pwDenomination) = 0;

	/*! \fn 		GetErrorCodeSet
		*
		* \brief        获取故障代码集合
		* \param[out]   map<int, ST_SYSTEM_ERROR_CODE_INFO> * pErrorCodeMap    故障码集合
		* \return 		none
		* \author		wangzp
		* \date			2014-09-17
		*/
		virtual void GetErrorCodeSet(map<int, ST_SYSTEM_ERROR_CODE_INFO> * pErrorCodeMap) = 0;

	/*! \fn 		GetErrorCodeInfoByErrorCode
		*
		* \brief        根据故障码ID获取该故障码信息
		* \param[in]    int iErrorCode
		* \param[out]   ST_SYSTEM_ERROR_CODE_INFO * pErrorCodeInfo
		* \return 		true    有该故障码信息    false    无该故障码信息
		* \author		wangzp
		* \date			2014-09-17
		*/
	virtual bool GetErrorCodeInfoByErrorCode(int iErrorCode, ST_SYSTEM_ERROR_CODE_INFO * pErrorCodeInfo) = 0;

		/*! \fn 		GetUnitStatus
		*
		* \brief        获取指定部件全状态
		* \param[in]    EM_SLE_UNIT_TYPE emSleUnitType
		* \param[out]   void * pStatus 状态
		* \param[out]   int * piMessageLen 状态长度
		* \return 		none
		* \author		wangzp
		* \date			2014-09-17
		*/
	virtual void GetUnitStatus(EM_SLE_UNIT_TYPE emSleUnitType, void * pStatus, int * piStatusLen) = 0;

		/*! \fn 		GetCashboxStatus
		*
		* \brief        获取指定钱箱状态
		* \param[in]    stCashboxLocation    指定钱箱
		* \return 		钱箱状态
		* \author		wugang
		* \date			2015-02-20
		*/
		virtual EM_BOX_PHYSICS_STATUS GetCashboxStatus(ST_CASH_CONTAINER_LOCATION stCashboxLocation) = 0;

		/*! \fn 		GetTicketboxStatus
		*
		* \brief        获取指定票箱状态
		* \param[in]    stTicketboxLocation    指定票箱
		* \return 		票箱状态
		* \author		wugang
		* \date			2015-02-20
		*/
		virtual EM_BOX_PHYSICS_STATUS GetTicketboxStatus(ST_TICKET_CONTAINER_LOCATION stTicketboxLocation) = 0;

	/*! \fn 		GateStatusHandleImmediately
		*
		* \brief        立即处理门模块的状态，包括：采集，计算，存储
		* \param[in]    none
		* \return 		none
		* \author		wangzp
		* \date			2015-03-06
		*/
		virtual void GateStatusHandleImmediately() = 0;

//	/*! \fn 		HandleUnitStatusImmediately
//		*
//		* \brief        立即采集，加工状态
//		* \param[in]    none
//		* \return 		none
//		* \author		wangzp
//		* \date			2015-04-17
//		*/
//		virtual void HandleUnitStatusImmediately(EM_SLE_UNIT_TYPE emSleUnitType) = 0;
//
//	/*! \fn 		GetAllUnitStatusImmediately
//		*
//		* \brief        立即采集，加工状态
//		* \param[in]    none
//		* \return 		none
//		* \author		wangzp
//		* \date			2015-04-17
//		*/
//		virtual void HandleAllUnitStatusImmediately() = 0;

	/*! \fn 		SetSystemShutDownStatus
		*
		* \brief        设置系统关机状态
		* \param[in]    EM_SYSTEM_SHUTDOWN_STATUS emSystemShutDownStatus    系统关机状态
		* \return 		none
		* \author		wangzp
		* \date			2015-03-06
		*/
		virtual void SetSystemShutDownStatus(EM_STATUS_SOURCE emSleBizType, EM_SYSTEM_SHUTDOWN_STATUS emSystemShutDownStatus) = 0;

	/*! \fn 		GetSystemShutDownStatus
		*
		* \brief        获取系统关机状态
		* \param[in]    none
		* \return 		none
		* \author		wangzp
		* \date			2015-03-06
		*/
		virtual EM_SYSTEM_SHUTDOWN_STATUS GetSystemShutDownStatus() = 0;

		/*! \fn 		SetTicketboxActionStatus
			*
			* \brief        设置票箱动作状态
			* \param[in]    bFail: true， 设置失败状态 false, 解除失败状态
			* \return 		none
			* \author		wugang
			* \date			2015-05-22
			*/
		virtual void SetTicketboxActionStatus(ST_TICKET_CONTAINER_LOCATION stTicketboxLocation, bool bFail) = 0;
		/*! \fn 		SetCashboxActionStatus
			*
			* \brief        设置票箱动作状态
			* \param[in]    bFail: true， 设置失败状态 false, 解除失败状态
			* \return 		none
			* \author		wugang
			* \date			2015-05-22
			*/
		virtual void SetCashboxActionStatus(ST_CASH_CONTAINER_LOCATION stCashboxLocation, bool bFail) = 0;
protected:
	CLogOper2 *m_pBizLog; /*!< */
};

class CLogOper2;
typedef Loki::SingletonHolder
<
	Loki::Factory<ISleStateApp, std::string, Seq<CLogOper2*> >,
	CreateUsingNew, Loki::LongevityLifetime::DieAsSmallObjectChild
> SleStateAppFactory;

#define REGISTER_AFC_SLESTATEAPP_OBJECT(className)                                                      \
namespace {                                                                            \
	ISleStateApp* createSleStateAppBase(CLogOper2 *m_pBizLog) { return new className(m_pBizLog); }                                              \
const bool SleStateAppFactory__ = SleStateAppFactory::Instance().Register( #className, createSleStateAppBase );  \
}
class ISleStateApp;
extern	ISleStateApp *g_pIAfcSleStateApp;
#endif /* ISTATEAPP_H_ */
