/*
 * DIOCommonFunction.h
 *
 *  Created on: Feb 13, 2014
 *      Author: root
 */

#ifndef DIOCOMMONFUNCTION_H_
#define DIOCOMMONFUNCTION_H_

#include <loki/Singleton.h>
#include <loki/Factory.h>
#include <loki/Sequence.h>
#include "IDeviceCommonFunction.h"

using namespace Loki;

/*
//警报灯颜色
typedef enum __EM_CSS_ALARM_LIGHT_COLOR__
{
	 RED,  	//红色
	 YELLOW,	//黄色
	 GREEN,
	 BLUE,
	// ALL
}EM_CSS_ALARM_LIGHT_COLOR;
*/
typedef enum __EM_ALARM_LIGHT__
{
	EM_ALARM_LIGHT_BLACK = 0, //黑
	EM_ALARM_LIGHT_RED = 1, //红
	EM_ALARM_LIGHT_GREEN = 2, //绿
	EM_ALARM_LIGHT_YELLOW = 3, //黄
	EM_ALARM_LIGHT_BLUE = 4, //蓝
	EM_ALARM_LIGHT_PURPLE = 5, //紫
	EM_ALARM_LIGHT_CYAN = 6, //青
	EM_ALARM_LIGHT_WHITE = 7, //白
	//ALL,//所有
}EM_ALARM_LIGHT;

enum EM_CSS_OPENCEILING_WIZARD
{
	RED_LIGHT_EXIT,	//0
	GREEN_LIGHT_EXIT,	//1
	RED_LIGHT_ENTRY,	//2
	GREEN_LIGHT_ENTRY,	//3
	EXIT_GREEN_ENTRY_RED,	//4
	EXIT_RED_ENTRY_GREEN,	//5
	BI_RED,		//6
	BI_GREEN	//7
};


//警报灯类型
enum EM_CSS_ALARM_TYPE
{
	 BLACKLIST,  	  		//黑名单卡
	 BADCARD,		  		//坏卡
	 UNLAWFUL_BREAK		//非法闯入
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




typedef struct _ST_DI_STATUS_
{
	unsigned char DICTRL_ENTRY_TOP_REPAIR 		:1;	//进站上盖打开
	unsigned char DICTRL_ENTRY_BOTTOM_REPAIR 		:1;	//进站下盖打开
	unsigned char DICTRL_ENTRY_SIDE_REPAIR 		:1;	//进站侧盖打开
	unsigned char DICTRL_EXIT_TOP_REPAIR 			:1;	//出站上盖打开

	unsigned char DICTRL_EXIT_BOTTOM_REPAIR 		:1;	//出站下盖打开
	unsigned char DICTRL_EXIT_SIDE_REPAIR 		:1;	//出站侧盖打开
	unsigned char Reserved0					 		:1;	//预留
	unsigned char Reserved1					 		:1;	//预留

} DISTATUS_STRUCT_CSS;

enum EM_DIRECTION
{
	DIRECTION_EXIT,	// 出站
	DIRECTION_ENTRY, // 进站
	DIRECTION_FREE,	// 进出站已经完成，处于空闲状态
};

class IAgDioCommonFunction : public IDeviceCommonFunction
{
public:
	virtual bool ExecInit() = 0;//初始化
	virtual bool FasSignalFeedBack(bool bEmergent) = 0;//FAS紧急模式的响应信号
	virtual bool HeatModuleSwitch(bool bSwitch) = 0;//加热模块开关
	virtual bool GetDiStatus(DISTATUS_STRUCT_CSS * pDIStatus) = 0;//获取状态
	virtual bool OpenDoor(EM_DIRECTION emDirection) = 0;//打开扇门

	virtual bool OpenLamp(EM_ALARM_LIGHT emColor, EM_DIRECTION emDirection) = 0;//打开警报灯
	virtual bool CloseLamp(EM_ALARM_LIGHT emColor, EM_DIRECTION emDirection) = 0;
	//emColor 颜色 bEntry 方向 usTimes 次数(0一直闪烁) iOnTime 闪灯时间(ms) iOffTime 灭灯时间(ms)
	virtual bool FlashLamp(EM_ALARM_LIGHT emColor, EM_DIRECTION emDirection, unsigned short usTimes, unsigned int iOnTime, unsigned int iOffTime, bool bImmediate) = 0;

	virtual bool OpenCeilingWizard(EM_CSS_OPENCEILING_WIZARD emLight) = 0;//开顶棚向导指示灯
	virtual bool ControlDirIndication(EM_CSS_INDICATOR_LIGHT_TYPE emLight) = 0;//打开通行指示灯

	virtual bool OpenLampReject() = 0; //回收退票灯亮
	virtual bool CloseLampReject() = 0;
	virtual bool FlashLampReject(unsigned short usLightTimes, unsigned int iOnTime, unsigned int iOffTime, bool bImmediate) = 0;

	virtual bool OpenLampPolling( EM_DIRECTION emDirection) = 0; //刷卡灯
	virtual bool CloseLampPolling(EM_DIRECTION emDirection) = 0;
	virtual bool FlashLampPolling(EM_DIRECTION emDirection, unsigned short usLightTimes, unsigned int iOnTime, unsigned int iOffTime, bool bImmediate) = 0;


	virtual bool OpenLampInsert() = 0; //投卡灯
	virtual bool CloseLampInsert() = 0;
	virtual bool FlashLampInsert(unsigned short usLightTimes, unsigned int iOnTime, unsigned int iOffTime, bool bImmediate) = 0;


	virtual bool OpenLampCheck(EM_DIRECTION emDirection) = 0; //稽查灯
	virtual bool CloseLampCheck(EM_DIRECTION emDirection) = 0;
	virtual bool FlashLampCheck(EM_DIRECTION emDirection, unsigned short usLightTimes, unsigned int iOnTime, unsigned int iOffTime, bool bImmediate) = 0;

	virtual bool OpenLampIndication(EM_DIRECTION emDirection) = 0; // 警报方向指示灯  部分设备不存在
	virtual bool CloseLampIndication(EM_DIRECTION emDirection) = 0;
	virtual bool FlashLampIndication(EM_DIRECTION emDirection, unsigned short usLightTimes, unsigned int iOnTime, unsigned int iOffTime, bool bImmediate) = 0;

	virtual bool BuzzerTest(bool bSwitch) = 0;

	virtual void TestPort(unsigned int iAddr, unsigned int iBit, bool bHigh) = 0;


};



class CLogOper2;
typedef Loki::SingletonHolder
<
        Loki::Factory<IAgDioCommonFunction, std::string, Seq<CLogOper2*> >,
        CreateUsingNew, Loki::LongevityLifetime::DieAsSmallObjectChild

> DIOBaseFactory;

#define REGISTER_COMM_DIO_BIZ(className) \
namespace {                                                                            \
	IAgDioCommonFunction* CreateDIOBase(CLogOper2 *m_SleLog ) { return new className(m_SleLog ); }                                              \
const bool DIOBaseFactory__ = DIOBaseFactory::Instance().Register( #className, CreateDIOBase );  \
}

class IAgDioCommonFunction;
extern IAgDioCommonFunction *pDIOUnitBase;



#endif /* DIOCOMMONFUNCTION_H_ */
