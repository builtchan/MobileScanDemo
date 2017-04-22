/*
 * ILedCommonFunction.h
 *
 *  Created on: Sep 26, 2014
 *      Author: wangyzh
 */

#ifndef ILEDCOMMONFUNCTION_H_
#define ILEDCOMMONFUNCTION_H_

#include "AfcPublic.h"
#include "IDeviceCommonFunction.h"
#include <loki/Singleton.h>
#include <loki/Factory.h>
#include <loki/Sequence.h>
#include <CLogOper2.h>

#include <map>

using namespace Loki;
using namespace std;

/*全屏显示数据入参结构体*/
typedef struct _ST_LED_DOUBLE_SHOW_WND_
{
	unsigned char ucColor;//1-7七个颜色（红绿黄蓝紫青白）
	unsigned char Reserve[3];
}ST_LED_DOUBLE_SHOW_WND;

/***********发送文本数据到指定窗口(LEYARD_LED_DOUBLE_CMD_SEND_TEXT)***************/
typedef struct _ST_LED_DOUBLE_SEND_TEXT_
{
	unsigned char ucTextDisplayStyle;//显示方式，0x00-0x0c();
	unsigned char ucTextAignStyle;//对齐方式,0:左对齐，1:水平居中，2:右对齐
	unsigned char ucTextSpeed;//速度,数值越小速度越快.
	unsigned char ucTextDisplayTime[2];//停留时间,单位秒
	//第一行的文字
	unsigned char ucTextColor;//1-7表示：红绿黄蓝紫青白==bit(4-7)
	unsigned char ucTextPointNum;//8点文字:(0).16点文字:(2).24点文字:(3).32点文字:(4)==bit(0-3)
	unsigned char ucTextBuf[20480];//字符串内容,每三个字节标识一个英文字符
	int iTextBufSize;//字符串大小
}ST_LED_DOUBLE_SEND_TEXT;

/*************划分窗口显示指令结构体(LEYARD_LED_DOUBLE_CMD_DEVIDE_SHOW_WINDOW)**************/
typedef struct _ST_LED_DOUBLE_WINDOW_LACATION_
{
	unsigned char ucWindowPosX[2];//窗口x的坐标高位在前
	unsigned char ucWindowPosY[2];//窗口y的坐标高位在前
	unsigned char ucWindowWidth[2];//窗口的宽度高位在前
	unsigned char ucWindowHeight[2];//窗口的高度高位在前
}ST_LED_DOUBLE_WINDOW_LACATION;

//Led三基色结构体
typedef struct _ST_SLE_LED_RGB_INFO_
{
	BYTE ucColorR;
	BYTE ucColorG;
	BYTE ucColorB;
}ST_SLE_LED_RGB_INFO;

/***********发送静态文本数据到指定窗口(LED_DOUBLE_CMD_SEND_SATAIC_TEXT)***************/
typedef struct _ST_LED_DOUBLE_SEND_STATIC_TEXT_
{
	unsigned char ucDateType;//数据类型，01表示简单文本数据
	unsigned char ucTextHorizonAlignStyle;//水平对齐方式.0:左对齐，1:水平居中，2:右对齐
	ST_LED_DOUBLE_WINDOW_LACATION stTextShowArea;//显示的窗口区域
	unsigned char ucTextFontSize;//文本字体的大小bit0-3
	unsigned char ucTextFontColorR;//颜色的红色分量
	unsigned char ucTextFontColorG;//颜色的绿色分量
	unsigned char ucTextFontColorB;//颜色的黄色分量
	unsigned char ucTextBuf[20480];//文字串以0x00作为结束字符
	int  iTextBufSize;
}ST_LED_DOUBLE_SEND_STATIC_TEXT;

/*显示类型*/
typedef enum _EM_LED_DOUBLE_SHOW_TYPE_
{
	EM_LED_TEST_TYPE_SHOW_DYNAMIC    = 0,//动态显示
	EM_LED_TEST_TYPE_SHOW_STATIC     = 1,//静态显示
}EM_LED_DOUBLE_SHOW_TYPE;

/*显示参数*/
typedef struct _ST_LED_SHOW_PARAM_
{
	int  iWndId;
	EM_LED_DOUBLE_SHOW_TYPE emLedDoubleShowType;//0,动态显示. 1,静态显示
	ST_LED_DOUBLE_SEND_TEXT stLedDoubleSendText;//动态文本的参数
	ST_LED_DOUBLE_SEND_STATIC_TEXT stDoubleSendStaticText;//静态文本的参数结构体
}ST_LED_SHOW_PARAM;

/*初始化参数，Leyard  LED 显示屏*/
typedef struct _ST_LED_SHOW_INIT_PARAM_
{
	int  iControlCardId;//控制卡ID
	unsigned char ucLightness;//显示屏的亮度
}PACKED ST_LED_SHOW_INIT_PARAM;

class ILedCommonFunction : public IDeviceCommonFunction
{
public:
	//led 特有的命令接口
	/* virtual int ShowText(ST_LED_SHOW_PARAM stLedShowParam) = 0;
	 * 显示文本命令
	 * param[in]:文本显示参数结构体（控制卡ID，窗口号,文本内容,显示方式（true:动态显示，false:静态显示））
	 * author:wangyzh
	 * data:2014-10-09
	 * return:COMMOM_FUNC_OK         1    //执行成功
	 * \      COMMOM_FUNC_FAIL       0    //执行失败
     * \      COMMOM_FUNC_CMDERR   (-1)   //指令错误，没有被执行
	 * \      COMMOM_FUNC_UNSUPP   (-2)   //模块不支持此项功能
	 */
	virtual int ShowText(ST_LED_SHOW_PARAM *pstLedShowParam) = 0;


	/* virtual int FullShow(unsigned char ucControlId, ST_LED_DOUBLE_SHOW_WND stLedDoubleShowWnd) = 0;
	 * 全屏显示命令
	 * param[in]:全屏显示结构体入参
	 * author:wangyzh
	 * data:2014-10-09
	 * return:同Init函数
	 */
	virtual int FullShow(ST_LED_DOUBLE_SHOW_WND stLedDoubleShowWnd) = 0;


	/* virtual int  LedPowerOn(bool bOn) = 0;
	 * //软件开关屏命令
	 * param[in]:开关参数bool值
	 * author:wangyzh
	 * data:2014-10-10
	 * return:同Init参数
	 * */
	virtual int  LedPowerOn(bool bOn) = 0;				//软件开关屏命令

	/* virtual int LedFormat() = 0;
	 * ////格式化命令
	 * author:wangyzh
	 * data:2014-10-10
	 * return:同Init参数
	 * */
	virtual int LedFormat() = 0;				//格式化命令


};
class CLogOper2;
typedef Loki::SingletonHolder
<
	Loki::Factory<ILedCommonFunction, std::string, Seq<CLogOper2*> >,
	CreateUsingNew, Loki::LongevityLifetime::DieAsSmallObjectChild
> LedBaseFactory;

#define REGISTER_COMM_LED_BIZ(className) \
namespace {                                                                            \
	ILedCommonFunction* CreateLedBase(CLogOper2 *m_SleLog ) { return new className(m_SleLog ); }                                              \
const bool LedBaseFactory = LedBaseFactory::Instance().Register( #className, CreateLedBase );  \
}

class ICashCommonFunction;
extern ICashCommonFunction *pCashUnitBase;

#endif /* ILEDCOMMONFUNCTION_H_ */
