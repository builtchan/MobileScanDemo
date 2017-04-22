/*
 * GateCommonFunction.h
 *
 *  Created on: Nov 19, 2013
 *      Author: root
 */

#ifndef GATEWITHDIOCOMMONFUNCTION_H_
#define GATEWITHDIOCOMMONFUNCTION_H_

#include "IDeviceCommonFunction.h"
#include "IDIOEventHandler.h"

#include <loki/Singleton.h>
#include <loki/Factory.h>
#include <loki/Sequence.h>
#include <CLogOper2.h>

using namespace Loki;



typedef struct _ST_PCM_PARAM_
{
	int iAuthTimeOut;		//授权信号保留时间（秒）		 	01h 	PATO 	Passage Authorization Time-Out 	1s 		01h – FEh 	15
	int iPassTimeOut;		//通过门单元后的离开时间（0.1秒）04h 		LATO 	Leave Aisle Time-Out 			100 ms 	00h – FEh 	20
	int iBuzzerOnTimeOut;	//报警持续时间（0.1秒）			02h 	BOTO 	Buzzer On Time-Out 				100 ms 	00h - FEh 	10
	int iBuzzerDelayTimeOut;	//报警等待时间（0.1秒）		03h 	BDTO 	Buzzer Delay Time-Out 			100 ms 	00h – FEh 	20
	int iSensorTimeOut;	//传感器遮挡报警的时间（秒）			05h 	SSTO 	Sensor Self-Test Time-Out 		1s 		01h – FEh 	180
	int iSafetyAreaTimeOut;	//安全区阻挡时间（秒）			0Ah 	OSST 	Override Safety Sensors TimeOut	1s 		00h – FFh 	30
	int iFlapCloseTimeOut;	//通过后关门时间（0.1秒）		00h 	FCTO 	Flap Closing Time-Out 			100 ms 	00h - FEh 	0
	int iContinuousFlowTimeOut;	//大件物体通过时间（0.1秒）	0Dh 	CFTO 	Continuous Flow Time-Out 		100 ms 	01h – FFh 	15
	int iChildDetectionLevel;	//儿童检测水平				24h     CDSL    Child Detection Sensitivity Level 	10h:low; 20h:medium low; 30h: medium high; 40h: high
}ST_PCM_PARAM;


enum EM_DIRECTION
{
	DIRECTION_EXIT,	// 出站
	DIRECTION_ENTRY, // 进站
	DIRECTION_FREE,	// 进出站已经完成，处于空闲状态
};

enum EM_CSS_OPENCEILING_WIZARD
{
	RED_LIGHT_EXIT,
	GREEN_LIGHT_EXIT,
	RED_LIGHT_ENTRY,
	GREEN_LIGHT_ENTRY,
	EXIT_GREEN_ENTRY_RED,
	EXIT_RED_ENTRY_GREEN,
	BI_RED,
	BI_GREEN
};

//通行指示器打显示类型
enum EM_CSS_INDICATOR_LIGHT_TYPE
{
	 ENTRY_INDIRCATOR_RED = 0, //进站红色
	 ENTRY_INDIRCATOR_GREEN = 1, //进站绿色
	 EXIT_INDIRCATOR_RED = 2, //出站红色
	 EXIT_INDIRCATOR_GREEN = 3, //出站绿色
	 ENTRY_GREEN_EXIT_RED = 4, //进站绿色出站红色
	 ENTRY_RED_EXIT_GREEN = 5, //进站红色出站绿色
	 BIDIRECTIONAL_INDIRCATOR_GREEN = 6, //双向绿色
	 BIDIRECTIONAL_INDIRCATOR_RED = 7 //双向红色
};

class IGateWithDioCommonFunction : public IDeviceCommonFunction
{
public:
	/*! \fn IGateCommomFunction::GetWorkMode(EM_GATE_WORKMODE *pemMode)
	 * \brief 		获取工作模式
	 * \param[out]  pemMode 工作模式
	 * \return		同Init
	 * \author 		吴刚
	 * \date 		2013－11－27
	*/
	virtual int GetWorkMode(EM_GATE_WORKMODE *pemMode) = 0;

	/*! \fn IGateCommomFunction::SetWorkMode(EM_GATE_WORKMODE emMode)
	 * \brief 		设置工作模式
	 * \param[in]   emMode 工作模式
	 * \return		同Init
	 * \author 		吴刚
	 * \date 		2013－11－27
	*/
	virtual int SetWorkMode(EM_GATE_WORKMODE emMode) = 0;

	/*! \fn IGateCommomFunction::GetDoorWorkMode(EM_CSS_DOOR_WORKMODE * pemMode)
	 * \brief 		获取门工作模式
	 * \param[out]  pemMode 门工作模式
	 * \return		同Init
	 * \author 		吴刚
	 * \date 		2013－11－27
	*/
	virtual int GetDoorWorkMode(EM_CSS_DOOR_WORKMODE * pemMode) = 0;

	/*! \fn IGateCommomFunction::SetWorkMode(EM_GATE_WORKMODE emMode)
	 * \brief 		设置门工作模式
	 * \param[in]   emMode 门工作模式
	 * \return		同Init
	 * \author 		吴刚
	 * \date 		2013－11－27
	*/
	virtual int SetDoorWorkMode(EM_CSS_DOOR_WORKMODE emMode) = 0;

	/*! \fn IGateCommomFunction::GetEmergencyMode(bool *pbSwem， bool * pbEm)
	 * \brief 		获取紧急模式
	 * \param[out]  pbSwem 是否通过串口设置为紧急
	 * \param[out]  pbEm 是否通过紧急接入电缆设置为紧急
	 * \return		同Init
	 * \author 		吴刚
	 * \date 		2013－11－27
	*/
	virtual int GetEmergencyMode(bool *pbSwem,  bool * pbEm) = 0;

	/*! \fn IGateCommomFunction::SetEmergencyMode(bool set)
	 * \brief 		通过串口设置或取消紧急模式
	 * \param[in]   set true: 设置；false：取消
	 * \return		同Init
	 * \author 		吴刚
	 * \date 		2013－11－27
	*/
	virtual int SetEmergencyMode(bool set) = 0;

	/*! \fn IGateCommomFunction::GetMaintainceMode(bool *pbSet)
	 * \brief 		获取维护模式
	 * \param[out]  pbSet 是否通为维护模式
	 * \return		同Init
	 * \author 		吴刚
	 * \date 		2013－11－27
	*/
	virtual int GetMaintainceMode(bool *pbSet) = 0;

	/*! \fn IGateCommomFunction::GetChildCheck(bool *pbCheck)
	 * \brief 		获取儿童检测状态
	 * \param[out]  pbCheck 是否开启儿童检测。true: 开启；false：未开启
	 * \return		同Init
	 * \author 		吴刚
	 * \date 		2013－11－27
	*/
	virtual int GetChildCheck(bool *pbCheck) = 0;

	/*! \fn IGateCommomFunction::SetChildCheck(bool bCheck)
	 * \brief 		设置儿童检测状态
	 * \param[in]   bCheck true: 开启；false：关闭
	 * \return		同Init
	 * \author 		吴刚
	 * \date 		2013－11－27
	*/
	virtual int SetChildCheck(bool bCheck) = 0;

	/*! \fn IGateCommomFunction::GetAlarmStatus(ST_GATE_ALARM_STATUS *pstAlarmStatus)
	 * \brief 		获取警报信息
	 * \param[out]  pstAlarmStatus 警报信息
	 * \return		同Init
	 * \author 		吴刚
	 * \date 		2013－11－27
	*/
	virtual int GetAlarmStatus(ST_GATE_ALARM_STATUS *pstAlarmStatus) = 0;

	/*! \fn IGateCommomFunction::ClearAlarms()
	 * \brief 		清除警报
	 * \return		同Init
	 * \author 		吴刚
	 * \date 		2013－11－27
	*/
	virtual int ClearAlarms() = 0;

	/*! \fn IGateCommomFunction::GetAisleStatus(ST_CHANNEL_STATUS_CSS *pstStatus)
	 * \brief 		获取通道相关数据
	 * \param[out]  pstAisleData 通道相关数据
	 * \return		同Init
	 * \author 		吴刚
	 * \date 		2013－11－27
	*/
	virtual int GetAisleData(ST_GATE_AISLE_DATA *pstAisleData) = 0;

	/*! \fn IGateCommomFunction::GetAisleStatus(ST_CHANNEL_STATUS_CSS *pstStatus)
	 * \brief 		开门
	 * \param[in]  bEntryDir true: 进站方向  false: 出站方向
	 * \return		同Init
	 * \author 		吴刚
	 * \date 		2013－11－27
	*/
	virtual int OpenDoor(bool bEntryDir) = 0;

	/*! \fn IGateCommomFunction::Polling(bool *pbRegChanged)
	 * \brief 		开门
	 * \param[out]  pbRegChanged true: 有变化  false: 无变化
	 * \return		同Init
	 * \author 		吴刚
	 * \date 		2013－11－27
	*/
	virtual int Polling(bool *pbRegChanged) = 0;

	/*! \fn IGateCommomFunction::GetAisleStatus(ST_CHANNEL_STATUS_CSS *pstStatus)
	 * \brief 		获取高位传感器状态
	 * \param[out]  pstAisleData 通道相关数据
	 * \return		同Init
	 * \author 		lyp
	 * \date 		2014－06－26
	*/
	virtual int GetHeightSensorStatus(ST_HEIGHT_REGISTER_STATUS *stAuxiStatus)= 0;

	/*------------------------------------------------------------------------*/
	//DIO部分
	virtual void SetDiStatusHandler(IDIOEventHandler* pcHanlder) = 0;
	virtual IDIOEventHandler* GetDiStatusHandler() = 0;
	virtual bool FasSignalFeedBack(bool bEmergent) = 0;//FAS紧急模式的响应信号
	virtual bool HeatModuleSwitch(bool bSwitch) = 0;//加热模块开关
//	virtual bool GetDiStatus(DISTATUS_STRUCT_CSS * pDIStatus) = 0;//获取状态

	virtual bool OpenLamp(EM_ALARM_LIGHT emColor, EM_DIRECTION emDirection) = 0;//打开警报灯
	virtual bool CloseLamp(EM_ALARM_LIGHT emColor, EM_DIRECTION emDirection) = 0;
	//emColor 颜色 bEntry 方向 usTimes 次数(0一直闪烁) iOnTime 闪灯时间(ms) iOffTime 灭灯时间(ms)
	virtual bool FlashLamp(EM_ALARM_LIGHT emColor, EM_DIRECTION emDirection, unsigned short usTimes, unsigned int iOnTime, unsigned int iOffTime, bool bImmediate) = 0;

	virtual bool OpenCeilingWizard(EM_CSS_OPENCEILING_WIZARD emLight) = 0;//开顶棚向导指示灯
	virtual bool ControlDirIndication(EM_CSS_INDICATOR_LIGHT_TYPE emLight) = 0;//打开通行指示灯

	virtual bool OpenLampReject() = 0; //回收退票灯亮
	virtual bool CloseLampReject() = 0;
	virtual bool FlashLampReject(unsigned short usLightTimes, unsigned int iOnTime, unsigned int iOffTime, bool bImmediate) = 0;

	virtual bool OpenLampPolling(EM_ALARM_LIGHT emColor, EM_DIRECTION emDirection) = 0; //刷卡灯
	virtual bool CloseLampPolling(EM_ALARM_LIGHT emColor,EM_DIRECTION emDirection) = 0;
	virtual bool FlashLampPolling(EM_DIRECTION emDirection, unsigned short usLightTimes, unsigned int iOnTime, unsigned int iOffTime, bool bImmediate) = 0;


	virtual bool OpenLampInsert() = 0; //投卡灯
	virtual bool CloseLampInsert() = 0;
	virtual bool FlashLampInsert(unsigned short usLightTimes, unsigned int iOnTime, unsigned int iOffTime, bool bImmediate) = 0;


	virtual bool OpenLampCheck(EM_ALARM_LIGHT emColor,EM_DIRECTION emDirection) = 0; //稽查灯
	virtual bool CloseLampCheck(EM_ALARM_LIGHT emColor, EM_DIRECTION emDirection) = 0;
	virtual bool FlashLampCheck(EM_ALARM_LIGHT emColor,EM_DIRECTION emDirection, unsigned short usLightTimes, unsigned int iOnTime, unsigned int iOffTime, bool bImmediate) = 0;

	virtual bool OpenLampIndication(EM_DIRECTION emDirection) = 0; //
	virtual bool CloseLampIndication(EM_DIRECTION emDirection) = 0;
	virtual bool FlashLampIndication(EM_DIRECTION emDirection, unsigned short usLightTimes, unsigned int iOnTime, unsigned int iOffTime, bool bImmediate) = 0;

	virtual bool BuzzerTest(bool bSwitch) = 0;

	virtual void TestPort(unsigned int iAddr, unsigned int iBit, bool bHigh) = 0;

};


class CLogOper;
typedef Loki::SingletonHolder
<
	Loki::Factory<IGateWithDioCommonFunction, std::string, Seq<CLogOper2*> >,
	CreateUsingNew, Loki::LongevityLifetime::DieAsSmallObjectChild
> GateWithDioBaseFactory;

#define REGISTER_COMM_GATE_WITH_DIO_BIZ(className) \
namespace {                                                                            \
	IGateWithDioCommonFunction* CreateGateWithDioBase(CLogOper2 *m_SleLog ) { return new className(m_SleLog ); }                                              \
const bool GateWithDioBaseFactory__ = GateWithDioBaseFactory::Instance().Register( #className, CreateGateWithDioBase );  \
}

class IGateWithDioCommonFunction;
extern IGateWithDioCommonFunction *pGateWithDioUnitBase;

#endif /* GATEWITHDIOCOMMONFUNCTION_H_ */
