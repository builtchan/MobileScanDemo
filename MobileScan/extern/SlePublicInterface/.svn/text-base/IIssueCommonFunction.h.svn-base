/*
 * IssueCommonFunction.h
 *
 *  Created on: Jul 15, 2014
 *      Author: longjg
 */

#ifndef ISSUECOMMONFUNCTION_H_
#define ISSUECOMMONFUNCTION_H_

#include "AfcPublic.h"

#include "IDeviceCommonFunction.h"
#include "IIssueEventHandler.h"
#include "IRfidCommonFunction.h"

#include <loki/Singleton.h>
#include <loki/Factory.h>
#include <loki/Sequence.h>
#include <CLogOper2.h>

using namespace Loki;

//Token发行参数
typedef enum _EM_TOKEN_ISSUE_PARAM
{
	EM_RESIDUAL_TOKEN_WITHDRAW = 0,			//残币收入
	EM_RESIDUAL_TOKEN_REFUND = 1,			//残币退还
	EM_RESIDUAL_TOKEN_NO_ACTION = 2,		//无动作
}EM_TOKEN_ISSUE_PARAM;

//记录信息(25个字节)
typedef struct _ST_ISSUE_PARAM_INFO_
{
	short HopperATokenNum;								//HopperA中Token数量(2字节有符号整数,低字节在前) 							(设置参数/获取参数)
	short HopperBTokenNum;								//HopperB中Token数量(2字节有符号整数,低字节在前) 							(设置参数/获取参数)
	unsigned short HopperAToInvalidBoxTokenNum;			//从HopperA到废票箱的Token数量(2字节无符号整数,低字节在前)					(设置参数/获取参数)
	unsigned short HopperBToInvalidBoxTokenNum;			//从HopperB到废票箱的Token数量(2字节无符号整数,低字节在前)					(设置参数/获取参数)
	unsigned short HopperAToWithdrawBoxTokenNum;		//从HopperA到回收箱Token数量(2字节无符号整数,低字节在前)					(设置参数/获取参数)
	unsigned short HopperBToWithdrawBoxTokenNum;		//从HopperB到回收箱Token数量(2字节无符号整数,低字节在前)					(设置参数/获取参数)
	unsigned short HopperAToOutTicketExitTokenNum;		//从HopperA到出票口Token数量(2字节无符号整数,低字节在前)					(设置参数/获取参数)
	unsigned short HopperBToOutTicketExitTokenNum;		//从HopperB到出票口Token数量(2字节无符号整数,低字节在前)					(设置参数/获取参数)
	unsigned char BrieflyStorageATokenType;				//暂存区A中Token类型(0无TOKEN;1有A类TOKEN;3有未知类型TOKEN)				(获取参数)
	unsigned char BrieflyStorageBTokenType;				//暂存区B中Token类型(0无TOKEN;2有B类TOKEN;3有未知类型TOKEN)				(获取参数)
	unsigned char ReadWriteAreaTokenType;				//读写区Token类型(0无TOKEN;1有A类TOKEN;2有B类TOKEN;3有未知类型TOKEN)		(获取参数)
	BYTE ucWorkMode;									//0:读写暂存都不预存.1:读写暂存都预存A类车票.2:读写暂存都预存B类车票			(设置参数/获取参数)
	BYTE szReserved[10];								//保留,以后扩展
}PACKED ST_ISSUE_PARAM_INFO;


//版本信息结构体
typedef struct _ST_ISSUE_VERSION
{
	BYTE btMainVersionNo;						//主版本
	BYTE btSubVersionNo;						//子版本
	WORD wVersionYear;							//年
	BYTE btVersionMonth;						//月
	BYTE btVersionDay;							//日
	WORD wHopperOneVersionNo;					//hopper1版本号
	WORD wHopperTwoVersionNo;					//hopper2版本号
	WORD wRfidVersionNo;						//RFID版本号
}ST_ISSUE_VERSION;

class IIssueCommonFunction : public IDeviceCommonFunction, public IRfidCommonFunction
{
public:
	/*! \fn IIssueCommonFunction::FetchTicket(bool bPreFetch, bool bFetch, ST_TICKET_CONTAINER_LOCATION stBoxNo)
	 * \brief 			1.提票
	 * param[in] 		bPreFetch 					是否执行预提票
	 * param[in]		bFetch						是否执行提票
	 * param[in] 		stBoxNo  					包含钱票箱类型:emTicketboxType		钱票箱序号：emTicketboxNo
	 * param[in] 		piActualFetchCount			实际从票箱的出票数量
	 * \return			COMMOM_FUNC_OK         1    执行成功
	 * \            	COMMOM_FUNC_FAIL       0    执行失败
	 * \            	COMMOM_FUNC_CMDERR   (-1)   指令错误，没有被执行
	 * \            	COMMOM_FUNC_UNSUPP   (-2)   模块不支持此项功能
	 * \author 			longjg
	 * \date 			2014－10-8
	 */
	virtual int FetchTicket(bool bPreFetch, bool bFetch, ST_TICKET_CONTAINER_LOCATION stBoxNo) = 0;

	/*! \fn IIssueCommonFunction::PreProcessTicket();
	 * \brief 			2.预出票(票卡读写完毕后从读卡位到出票口暂存区)
	 * \return			同FetchTicket()函数
	 * \author 			longjg
	 * \date 			2014－10-8
	 *  */
	virtual int PreProcessTicket() = 0;

	/*! \fn IIssueCommonFunction::PopTicket();
	 * \brief 			3.出票(把出票口暂存区的票发售给乘客)
	 * \return			同FetchTicket()函数
	 * \author 			longjg
	 * \date 			2014－10-8
	 */
	virtual int PopTicket() = 0;

	/*! \fn IIssueCommonFunction::WithdrawTicket()
	 * \brief 			4.回收(在读写票卡过程中,出现了读写失败,例如票卡损坏,票卡为黑名单,票卡使用次数超限,票卡回收等,需要将票卡回收到废票箱中)
	 * \return			同FetchTicket()函数
	 * \author 			longjg
	 * \date 			2014－10-8
	 */
	virtual int WithdrawTicket() = 0;

	/*! \fn IIssueCommonFunction::FlushBegin(ST_TICKET_CONTAINER_LOCATION stBoxNo)
	 * \brief			5.清空票箱(把票箱中的票存到回收箱)
	 * param[in] 		stBoxNo  					包含钱票箱类型:emTicketboxType		钱票箱序号：emTicketboxNo
	 * \return			同FetchTicket()函数
	 * \author 			longjg
	 * \date 			2014－10-8
	 */
	virtual int FlushBegin(bool bSync, ST_TICKET_CONTAINER_LOCATION stBoxNo) = 0;

	/*! \fn IIssueCommonFunction::ReplaceTicketBox(ST_TICKET_CONTAINER_LOCATION stBoxNo, EM_BOX_OPERATION emBoxOp, int iTimeOut);
	 * \brief			6.钱票箱换上换下函数
	 * param[in] 		stBoxNo  					包含钱票箱类型:emTicketboxType		钱票箱序号：emTicketboxNo
	 * param[in] 		emBoxOp						钱票箱操作(EM_BOX_OPERATION_LOCK->上锁;EM_BOX_OPERATION_UNLOCK->解锁)
	 * param[in]		iTimeOut					钱票箱解锁超时时间
	 * \return			同FetchTicket()函数
	 * \author 			longjg
	 * \date 			2014－10-8
	 */
	virtual int OperateTicketBox(ST_TICKET_CONTAINER_LOCATION stBoxNo, EM_CONTAINER_OPERATION_TYPE emBoxOp, int iTimeout) = 0;

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

	/* bool RegEventHandle(IIssueEventHandler* pITokenEventHandler);
	 *\brief 			9.注册事件句柄，返回给上层产生事件
	 *\param[in] 		pITokenEventHandler			事件句柄
	 *\return  			true--注册事件成功  false--注册事件失败
	 *\author: 			longjg
	 *\date 			2014－10-8
	 */
	virtual bool RegEventHandle(IIssueEventHandler* pITokenEventHandler) = 0;
	virtual IIssueEventHandler* GetEventHandle() = 0;
};


class CLogOper;
typedef Loki::SingletonHolder
<
	Loki::Factory<IIssueCommonFunction, std::string, Seq<CLogOper2*> >,
	CreateUsingNew, Loki::LongevityLifetime::DieAsSmallObjectChild
> IssueBaseFactory;

#define REGISTER_COMM_ISSUE_BIZ(className) \
namespace {                                                                            \
	IIssueCommonFunction* CreateIssueBase(CLogOper2 *m_SleLog ) { return new className(m_SleLog ); }                                              \
const bool IssueBaseFactory__ = IssueBaseFactory::Instance().Register( #className, CreateIssueBase );  \
}

class IIssueCommonFunction;
extern IIssueCommonFunction *pIssueUnitBase;

#endif /* ISSUECOMMONFUNCTION_H_ */
