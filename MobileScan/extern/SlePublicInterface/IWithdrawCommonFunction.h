/***************************************************************

*程序名称：IWithdrawCommonFunction.h

*版本号：1.0

*功能描述：中软Token回收模块业务接口定义

*作者：龙金贵

*创建日期：2015-01-27

*修改记录：

****************************************************************/

#ifndef IWITHDRAWCOMMONFUNCTION_H_
#define IWITHDRAWCOMMONFUNCTION_H_

#include "AfcPublic.h"
#include "IDeviceCommonFunction.h"
#include "IWithdrawEventHandler.h"
#include "IRfidCommonFunction.h"

#include <loki/Singleton.h>
#include <loki/Factory.h>
#include <loki/Sequence.h>
#include <CLogOper2.h>

using namespace Loki;

//回收单元初始化参数
typedef enum _EM_RECYCLE_INIT_PARAM_
{
	EM_RESIDUAL_WITHDRAW = 0,			//残币收入
	EM_RESIDUAL_REFUND = 1,				//残币退还
}EM_RECYCLE_INIT_PARAM;

//版本信息结构体
typedef struct _ST_RECYCLE_VERSION_
{
	BYTE btMainVersionNo;						//主版本
	BYTE btSubVersionNo;						//子版本
	WORD wVersionYear;							//年
	BYTE btVersionMonth;						//月
	BYTE btVersionDay;							//日
	WORD wRfidVersionNo;						//RFID版本号
}ST_RECYCLE_VERSION;

class IWithdrawCommonFunction : public IDeviceCommonFunction, public IRfidCommonFunction
{
public:
//--------------------------------------------------------------------------------------------------------
	/*! \fn IWithdrawCommonFunction::Work();
	 * \brief 			1.正常工作(打开舌档)
	 * \return			COMMOM_FUNC_OK         1    执行成功
	 * \            	COMMOM_FUNC_FAIL       0    执行失败
	 * \            	COMMOM_FUNC_CMDERR   (-1)   指令错误，没有被执行
	 * \            	COMMOM_FUNC_UNSUPP   (-2)   模块不支持此项功能
	 * \author 			longjg
	 * \date 			2015－01-27
	 *  */
	virtual int Work() = 0;
//--------------------------------------------------------------------------------------------------------
	/*! \fn IWithdrawCommonFunction::Pause();
	 * \brief 			2.暂停工作(关闭舌档)
	 * \return			同Work()函数
	 * \author 			longjg
	 * \date 			2015－01-27
	 *  */
	virtual int Pause() = 0;

	/*! \fn IWithdrawCommonFunction::Pause(ST_AG_WORK_MODE stAgWorkMode);
	 * \brief 			2.暂停工作(关闭舌档),根据系统状态 关闭舌档
	 * \return			同Work()函数
	 * \author 			longjg
	 * \date 			2015－01-27
	 *  */
	virtual int Pause(ST_AG_WORK_MODE stAgWorkMode) = 0;
//--------------------------------------------------------------------------------------------------------
	/*! \fn IWithdrawCommonFunction::Withdraw(ST_TICKET_CONTAINER_LOCATION stBoxNo);
	 * \brief 			3.从读卡位回收车票到指定票箱
	 * \param[in]		stBoxNo						包含钱票箱类型:emTicketboxType		钱票箱序号：emTicketboxNo
	 * \return			同Work()函数
	 * \author 			longjg
	 * \date 			2015－01-27
	 *  */
	virtual int Withdraw(ST_TICKET_CONTAINER_LOCATION stBoxNo) = 0;
//--------------------------------------------------------------------------------------------------------
	/*! \fn IWithdrawCommonFunction::Refund();
	 * \brief 			4.从读卡位退还读写失败的废票
	 * \return			同Work()函数
	 * \author 			longjg
	 * \date 			2015－01-27
	 *  */
	virtual int Refund() = 0;
//--------------------------------------------------------------------------------------------------------
	/*! \fn IWithdrawCommonFunction::OperateTicketBox(ST_TICKET_CONTAINER_LOCATION stBoxNo, EM_BOX_OPERATION emBoxOp, int iTimeOut);
	 * \brief			5.钱票箱换上换下函数
	 * param[in] 		stBoxNo  					包含钱票箱类型:emTicketboxType		钱票箱序号：emTicketboxNo
	 * param[in] 		emBoxOpType						钱票箱操作(EM_BOX_OPERATION_LOCK->上锁;EM_BOX_OPERATION_UNLOCK->解锁)
	 * param[in]		iTimeOut					钱票箱解锁超时时间
	 * \return			同Work()函数
	 * \author 			longjg
	 * \date 			2015－01-27
	 */
	virtual int OperateTicketBox(ST_TICKET_CONTAINER_LOCATION stBoxNo, EM_CONTAINER_OPERATION_TYPE emBoxOpType, int iTimeout) = 0;
//--------------------------------------------------------------------------------------------------------
	/*! \fn IWithdrawCommonFunction::ReadBoxRFID(ST_TICKET_CONTAINER_LOCATION stBoxNo, BYTE szBlockMark[16], void  *pReadData,  int * piReadDatalen)
	 * \brief 			6.读取票箱Rfid信息
	 * param[in] ST_TICKET_CONTAINER_LOCATION: 票箱的ID
	 * param[in] szBlockMark，块标识
	 *           bit0~bit127,分别代表块0~块127，1有效，0无效；
	 *           根据RFID类型不同,每个“块/扇区“的长度可能为4，16不等。
	 * param[out] pReadData：读取钱箱RFID的数据
	 * param[out] piReadDatalen：读取RFID的数据长度。该长度=每块的长度*读取块的数量
	 *返回值：Int
	 */
//	virtual int ReadBoxRFID(ST_TICKET_CONTAINER_LOCATION stBoxNo, BYTE szBlockMark[16], void  *pReadData,  int * piReadDatalen) = 0;
//--------------------------------------------------------------------------------------------------------
	/*! \fn IWithdrawCommonFunction::WriteBoxRFID(ST_TICKET_CONTAINER_LOCATION stBoxNo, BYTE szBlockMark[16], const void *pWriteData, int iWriteDatalen)
	 * \brief 			7.写入票箱Rfid信息
	 * param[in] emCashboxType: 钱箱的类型
	 * param[in] emBoxNo：钱箱号
	 * param[in] szBlockMark，块标识
	 *           bit0~bit127,分别代表块0~块127，1有效，0无效；
	 *           根据RFID类型不同,每个“块/扇区“的长度可能为4，16不等。
	 * param[in] pReadData：欲写入的钱箱的RFID信息
	 * param[in] iWriteDatalen：钱箱RFID信息长度。该长度=每块的长度*写入块的数量
	 *返回值：Int
	 */
//	virtual int WriteBoxRFID(ST_TICKET_CONTAINER_LOCATION stBoxNo, BYTE szBlockMark[16], const void *pWriteData, int iWriteDatalen) = 0;
//--------------------------------------------------------------------------------------------------------
	/*! \fn IWithdrawCommonFunction::RegEventHandle(IWithdrawEventHandler* pIWithdrawEventHandler);
	 *\brief 			8.注册事件句柄，返回给上层产生事件
	 *\param[in] 		pITokenEventHandler					事件句柄
	 *\return  			true/false							true--注册事件成功  false--注册事件失败
	 *\author: 			longjg
	 *\date 			2015－01-27
	 */
	virtual bool RegEventHandle(IWithdrawEventHandler* pIWithdrawEventHandler) = 0;
	virtual IWithdrawEventHandler* GetEventHandle( ) = 0;
//--------------------------------------------------------------------------------------------------------
};

class CLogOper;
typedef Loki::SingletonHolder
<
    Loki::Factory<IWithdrawCommonFunction, std::string, Seq<CLogOper2*> >,
    CreateUsingNew, Loki::LongevityLifetime::DieAsSmallObjectChild
> WithdrawBaseFactory;

#define REGISTER_COMM_WITHDRAW_BIZ(className) \
namespace {                                                                            \
	IWithdrawCommonFunction* CreateWithdrawBase(CLogOper2 *m_SleLog ) { return new className(m_SleLog ); }                                              \
const bool WithdrawBaseFactory__ = WithdrawBaseFactory::Instance().Register( #className, CreateWithdrawBase );  \
}

class IWithdrawCommonFunction;
extern IWithdrawCommonFunction *pWithdrawUnitBase;

#endif /* IWITHDRAWCOMMONFUNCTION_H_ */
