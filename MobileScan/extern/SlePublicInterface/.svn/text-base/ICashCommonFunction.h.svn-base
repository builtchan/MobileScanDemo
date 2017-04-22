/*
 * ICashCommonFunction.h
 *
 *  Created on: Jul 25, 2014
 *      Author: root
 */

#ifndef ICASHCOMMONFUNCTION_H_
#define ICASHCOMMONFUNCTION_H_

#include "AfcPublic.h"
#include "ICashEventHandler.h"
#include "IDeviceCommonFunction.h"
#include "IRfidCommonFunction.h"

#include <loki/Singleton.h>
#include <loki/Factory.h>
#include <loki/Sequence.h>
#include <CLogOper2.h>

#include <map>

using namespace Loki;
using namespace std;


// 纸币类型，长度和厚度信息
typedef struct _ST_BDU_PARAM_
{
	BYTE cDenoLenInfo[4];//4个钱箱的长度//单位：1毫米
	BYTE cLenError; //长度误差：单位：毫米

	BYTE cDenoThickInfo[4];//4个钱箱的厚度//单位：0.01毫米
	BYTE cThickError; //厚度误差：单位：0.01毫米

	BYTE cDenoWidthInfo[4];//钱箱1的宽度//单位:1毫米
	BYTE cWidthError; //宽度误差：单位：1毫米

	BYTE cBoxType[4];//4个钱箱的类型  //钱箱的位置

	BYTE cNumOfRej; //找零回收次数
	BYTE cReserve[16];
} ST_BDU_PARAM;


typedef struct _ST_CASH_CHANGE_PARAM_
{
	unsigned int uiLoopChangeBoxNum[4];//循环找零箱，包括硬币的循环Hopper，纸币的循环鼓
	unsigned int uiSpareChangeBoxNum[4];//备用找零箱，包括硬币的备用找零，纸币找零模块的找零箱，纸币循环模块的备用找零箱
}ST_CASH_CHANGE_PARAM;



//硬币初始化参数
typedef struct _ST_COIN_INIT_PARAM
{
	WORD wProjectID;
	WORD wOperWay;
    char cSafeBoxCount;//项目中现金安全箱（回收箱）的实际个数		[<=4]
	char cSupplyBoxCount;//项目中补充箱的实际个数		[<=4]
	char cHopperBoxCount;//项目中Hopper的实际个数		[<=4]
	char bReserve;//广州项目用 1:收入硬币到回收箱 0:收入硬币到Hopper2
	WORD wDenoHopper[4];//项目中hopper1面额		[以分为单位]
	char bReserve2;//广州项目用 1:右识别 0:左识别
	char bReserve3;//预留
}ST_COIN_INIT_PARAM;


//定义纸币识别模块接收安全级别
typedef enum
{
	EM_BIM_SECURITY_LEVEL_LOW = 1,						//低安全级别，高接收率
	EM_BIM_SECURITY_LEVEL_MID = 2,						//中间级别
	EM_BIM_SECURITY_LEVEL_HIGH = 3,						//高安全级别，低接收率

}EM_BIM_SECURITY_LEVEL;

//定义设置参数的结构体成员
typedef struct _ST_BIM_SET_PARAM_DEFINE_
{
	EM_BIM_SECURITY_LEVEL iSecurityLevel;					//设置指定纸币的安全等级
	char szCountryBillCode[3];								//激活指定国家纸币
	char reserve[128];										//预留
}ST_BIM_PARAM_DEFINE ;
////异步消息回调类接口 业务层实现
//class ICashEventHandler;

class ICashCommonFunction : public IDeviceCommonFunction, public IRfidCommonFunction
{
public:
	/*int CashChange(ST_CASH_CHANGE_PARAM stChangeCount, ST_CASH_CHANGE_PARAM *pstChangedCount,  ST_CASH_CHANGE_PARAM *pstRecycleCount)
	 *param[in]  stChangeCount：要找零的个数
	 *param[out] *pstChangedCount：实际找零的个数
	 *param[out] *pstRecycleCount：实际回收到废钞箱的个数
	 *\return
	 *2014-8-21
	 *author:hehj
	 */
//	virtual int CashChange(ST_CASH_CHANGE_PARAM stChangeCount, ST_CASH_CHANGE_PARAM *pstChangedCount,  ST_CASH_CHANGE_PARAM *pstRecycleCount) = 0;
	virtual int CashChange(ST_CASH_CHANGE_PARAM stChangeCount, list<ST_BIZ_CASH_DATA_INFO> * pstBizCashDataInfo) = 0;

	/*!\fn  int PaymentBegin (ST_DENO_INFO stAcceptDeno)
	 *\brief 支付开始. 描述乘客点选金额或车站或充值之后，主业务启动支付，触发交易开始业务。
	 *\param[in] 	stAcceptDeno-- 接收币种 1.接收 0.不接收
	 *\param[out]
	 *\return
	 */
	virtual int PaymentBegin (ST_DENO_INFO stAcceptDeno) = 0;

	/*!\fn  int PaymentPause(bool bSync)
	 *\brief 支付暂停
			  描述支付完成，主业务进行票卡处理前，对支付模块的动作。
			  现金模块在显示确认按钮之前调用。
			  支付模块处于交易状态，接受此功能调用。
	 *\param[in] 	bSync  同步或异步
	 *\param[out]
	 *\return 同Init
	 */
	virtual int PaymentPause(bool bSync) = 0;

	/*!\fn  int ConfirmPayment (int * iEncashCount);
	 *\brief	支付确认。
	 *\param[out]	ipEncashCount	-- encashCount  data
	 *\return 同Init
	 */
	virtual int ConfirmPayment (int * ipEncashCount, map<int, ST_CASH_CONTAINER_LOCATION> * pDenominationCashboxMap) = 0;

	/*!\fn  int ConfirmPayment (int * iEncashCount);
	 *\brief	支付取消。
	 *\param[out]	ipRefundCount	-- RefundCount  data
	 *\return 同Init
	 */
	virtual int CancelPayment (int * ipRefundCount ) = 0;

	/* bool RegEventHandle(ICoinEventHandler * pcBillEventHandler );
	 *\brief 注册事件句柄，返回给上层产生事件
	 *\param[in] 事件句柄
	 *\return  true--注册事件成功  false--注册事件失败
	 *\author: hehj
	 *\date 2014-8-19
	 */
	virtual bool RegEventHandler(ICashEventHandler * pcCashEventHandler) = 0;

	/* bool GetEventHandle(ICoinEventHandler * pcBillEventHandler );
	 *\brief 注册事件句柄，返回给上层产生事件
	 *\param[in]
	 *\return  ICashEventHandler对象
	 *\author: hehj
	 *\date 2014-8-19
	 */
	virtual ICashEventHandler * GetEventHandler() = 0;

	/*int OperateCashbox(EM_CASH_CONTAINER_TYPE emCashboxType, EM_BOX_NO emBoxNo,  EM_BOX_OPERATION emBoxOp)
	 * \brief 操作现金箱
	 * param[in] emCashboxType: 钱箱的类型
	 * param[in] emBoxNo：钱箱号
	 * param[in] emBoxOpType：钱箱的操作 上锁 解锁 补充
	 * param[in] iTimeout ： 超时时间，单位 s
	 * 返回值：Int
	 * \author: hehj
	 * \date 2014-8-21
	 */
	virtual int OperateCashbox(EM_CASH_CONTAINER_TYPE emCashboxType, EM_BOX_NO emBoxNo,  EM_CONTAINER_OPERATION_TYPE emBoxOpType, int iTimeout) = 0;

	/*
	 * Func Brief:判断现金接收模块是否开启识别
	 */
	virtual bool IsAcceptedState() = 0;

	/*int CashFlush(bool bSync, ST_CASH_CHANGE_PARAM stCashFlushCount, ST_CASH_CHANGE_PARAM* pstCashFlushedCount)
	 * \brief	 钱箱清空
     * param[in] bSync 同步/异步
     *              True：同步，通过pstCashFlushedCount返回清空结果
     *             False：异步，即刻返回，通过FlushNotify回调函数返回清空过程和结果
	 * param[in]  stCashFlushCount 要清空的数量，3种取值：
     *                             0：不清空
     *                            0xFFFFFFFF：全部清空
     *                            其他值：清空指定数量
	 */
	virtual int CashFlush(bool bSync, ST_CASH_CHANGE_PARAM stCashFlushCount, ST_CASH_CHANGE_PARAM* pstCashFlushedCount) = 0;

};


class CLogOper2;
typedef Loki::SingletonHolder
<
	Loki::Factory<ICashCommonFunction, std::string, Seq<CLogOper2*> >,
	CreateUsingNew, Loki::LongevityLifetime::DieAsSmallObjectChild
> CashBaseFactory;

#define REGISTER_COMM_CASH_BIZ(className) \
namespace {                                                                            \
	ICashCommonFunction* CreateCashBase(CLogOper2 *m_SleLog ) { return new className(m_SleLog ); }                                              \
const bool CashBaseFactory__ = CashBaseFactory::Instance().Register( #className, CreateCashBase );  \
}

class ICashCommonFunction;
extern ICashCommonFunction *pCashUnitBase;

#endif /* ICASHCOMMONFUNCTION_H_ */
