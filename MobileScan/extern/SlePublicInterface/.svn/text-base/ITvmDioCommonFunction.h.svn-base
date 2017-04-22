/*
 * IDIOCommonFunction.h
 *
 *  Created on: Nov 27, 2014
 *      Author: longjg
 */

#ifndef IDIOCOMMONFUNCTION_H_
#define IDIOCOMMONFUNCTION_H_

#include "IDeviceCommonFunction.h"
#include "IDIOEventHandler.h"

#include <loki/Singleton.h>
#include <loki/Factory.h>
#include <loki/Sequence.h>
#include "CLogOper2.h"
#include "AfcPublic.h"

using namespace Loki;

typedef struct _ST_TVMDIO_INIT_PARAM_DI_
{
	unsigned char ucBitIndex;	//部件本身上报的 bit序号， 0～15
	unsigned char ucValid;	    //高低电平有效性, 0 or 1, 有效: 到位，门关, 无报警, 电源OK，有人接近，有卡插入,求助按钮按下
	unsigned short usUnitID;	//部件ID，当是部件时, 则取值平台中部件ID 的统一定义(EM_SLE_UNIT_TYPE), 若是DIO自身的到位(如: 维修门到位), 则对应EM_ADDITIONAL_DO_UNIT_ID
}ST_TVMDIO_INIT_PARAM_DI;

typedef struct _ST_TVMDIO_INIT_PARAM_
{
	unsigned char ucProjectNo;    //项目编号(0.公司内部全功能版本; 1.北京项目; 2.天津3号线版本; 3.长春3号线; 4.哈尔滨1号)
	unsigned char ucPermitColor;  //允许操作时的亮灯颜色, 如允许插入储值卡时的灯颜色
	unsigned char ucForbidColor;  //禁止操作时的亮灯颜色,
	unsigned char ucLampTime;     //亮灯持续时间
	ST_TVMDIO_INIT_PARAM_DI szDi[16];

}ST_TVMDIO_INIT_PARAM;

class ITvmDioCommonFunction : public IDeviceCommonFunction
{
public:

	virtual void SetDiStatusHandler(IDIOEventHandler* pcHanlder) = 0;
	virtual IDIOEventHandler* GetDiStatusHandler( ) = 0;

	virtual int SetWorkMode(EM_SLE_SERVICE_MDDE stWorkMode) = 0;
/*	函数描述：根据交易类型设置交易开始后相关DO管脚。
		参数说明：
		入参：
	EM_TRAN_TYPE  emTransType ：交易类型。
	  返回值：
	0:成功 ，-1 ：false;*/
	virtual int TransBegin(EM_SLE_TRANSACATION_TYPE emTransType, EM_SVTCARD_HOLDER_TYPE emHolderType) = 0;

	/*	函数描述：根据支付类型设置相关相关DO管脚。
		参数说明：
		入参：
	ST_TVM_PAY_TYPE stTvmPayType ：支付类型，可同时打开多个支付设备。
	int iStep （0-n）支付阶段。目前仅对于银行卡支付有效。例：银行卡支付时，iStep为0时，表示打开银行卡卡座，iStep为1时，表示打开密码键盘。
	  返回值：
	0:成功 ，-1 ：false;*/
	virtual int PaymentBegin(EM_SLE_TRANSACATION_TYPE emTransType, ST_TVM_PAY_TYPE stTvmPayType, int iStep) = 0;

	/*	函数描述：根据支付类型设置相关相关DO管脚。
		参数说明：
		入参：
	ST_TVM_PAY_TYPE stTvmPayType ：支付类型，可同时关闭多个支付设备。
	  返回值：
	0:成功 ，-1 ：false;*/
	virtual int PaymentFinish(EM_SLE_TRANSACATION_TYPE emTransType, ST_TVM_PAY_TYPE stTvmPayType) = 0;
	/*	函数描述：预留。
		参数说明：
		入参：
	无
	  返回值：
	0:成功 ，-1 ：false;*/
	//virtual int TransConfirm() = 0;

	/*	函数描述：根据业务类型设置相关相关DO管脚。
		参数说明：
		入参：
	EM_TRAN_TYPE  emTransType ：交易类型。售票交易：设置出票口相关DO。
	充值交易/查询业务：设置充值卡座相关DO
	bool  bBillChange    是否设置纸币找零相关DO。
	bool  bCoinCharge    是否设置硬币找零相关DO
	bool bReceipt        是否设置打印单据相关DO
	  返回值：
	0:成功 ，-1 ：false;*/
	//virtual  int  TransCancel()=0;

	/*	函数描述：预留。
		参数说明：
		入参：
	无
	  返回值：
	0:成功 ，-1 ：false;*/
	virtual int TransProcessing(bool bTicket, bool bBillChange, bool bCoinChange, bool bBillReturn, bool bCoinReturn) = 0;

	/*	函数描述：根据业务类型设置相关相关DO管脚。
		参数说明：
		入参：
	EM_TRAN_TYPE  emTransType ：交易类型。售票交易：设置出票口相关DO。
	充值交易/查询业务：设置充值卡座相关DO
	bool  bBillChange    是否设置纸币找零相关DO。
	bool  bCoinCharge    是否设置硬币找零相关DO
	bool bReceipt        是否设置打印单据相关DO
	  返回值：
	0:成功 ，-1 ：false;*/
	virtual int TransFinish(bool bPrintReceipt, bool bSvt, bool bBankcard)=0;




	/*函数描述：设置单个DO相应管脚电平。
	参数说明：
	入参：
	EM_DO_NAME emDOName：指定单个管脚定义
	EM_DO_SIGNAL emDOValue：电平定义
	返回值：0:成功 ，-1 ：false;
    */

	//virtual  int TestDO(EM_DO_NAME emDOName,EM_DO_SIGNAL emDOValue)=0;


	/*函数描述：设置单个LED相应颜色。
	参数说明：
	入参：
	EM_LED_DO_NAME emDOName：指定单个LED管脚
	EM_DO_COLOR emDOValue：颜色定义
	返回值：0:成功 ，-1 ：false;
    */

//	virtual	 int TestLedDO(EM_LED_DO_NAME emDOName,EM_DO_COLOR emDOValue)=0;
};

typedef Loki::SingletonHolder
<
	Loki::Factory<ITvmDioCommonFunction, std::string, Seq<CLogOper2*> >,
	CreateUsingNew, Loki::LongevityLifetime::DieAsSmallObjectChild
> TvmDioCommonFunctionFactory;

#define REGISTER_TVMDIO_CLASS(className) \
namespace {                                                                            \
	ITvmDioCommonFunction* create(CLogOper2 *pSleLog) { return new className(pSleLog); }                                              \
const bool TvmDioCommonFunctionFactory__ = TvmDioCommonFunctionFactory::Instance().Register( #className, create );  \
}


#endif /* IDIOCOMMONFUNCTION_H_ */
