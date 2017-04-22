/*
 * VirObjTvmUIForCore.h
 *
 *  Created on: Aug 29, 2014
 *      Author: root
 */

#ifndef VIROBJTVMUIFORCORE_H_
#define VIROBJTVMUIFORCORE_H_

#include "VirObjectBase.h"

#include "ipcpublic.h"

#include "IpcManager.h"
#include "IpcMsgSortContainer.h"
#include "IpcMsgText.h"

class CVirObjTvmUIForCore : public CVirObjectBase
{
public:
	CVirObjTvmUIForCore();
	virtual ~CVirObjTvmUIForCore();


	//1)模式通知，主业务定时向界面发送模式通知。当模式发生变化时，主业务负责实时发送。
	//工作模式
	//找零模式，1有效
	void ModeNotify (const ST_TVM_MODE_NOTIFY *pstModeNotify, list<ST_IPCMSG_ADDITIONAL_RECORD> *pRecordList);

	//IPC报文解析，UI进程调用
	void ModeNotifyParse (CIpcMsgText * pcIpcRawData, ST_TVM_WORK_MODE *pstWorkMode, list<ST_IPCMSG_ADDITIONAL_RECORD>  *pRecordList);


	//2)票卡插入通知，进行充值和查询业务时，TVM检测到乘客插入票卡，通知界面。
	//交易类型
	//车票有效性
	//wangyzh修改入参函数交易类型的结构体
	void CardInsertNotify(EM_SLE_TRANSACATION_TYPE emTransType, EM_TVM_VALIDITY emValidity, const ST_TPU_READ_CARD_INFO *pstTpuReadCardInfo);
//	void CardInsertNotify(EM_TVM_TRANS_TYPE emType, EM_TVM_VALIDITY emValidity, const ST_TPU_READ_CARD_INFO *pstTpuReadCardInfo);
	//IPC报文解析，UI进程调用
	void CardInsertNotifyParse(const CIpcMsgText * pcIpcRawData, EM_SLE_TRANSACATION_TYPE *pemTransType, EM_TVM_VALIDITY *emValidity, ST_TPU_READ_CARD_INFO *pstTpuReadCardInfo);


	//3)支付信息通知，进行充值和售票业务时，TVM开启支付时，或者检测到乘客支付时，通知界面更新显示信息。
	//交易总价
	//交易数量
	//支付总金额
	//支付方式
	//纸币面额
	//硬币面额
	void PayInfoNotify(const ST_TVM_PAYMENT_NOTIFY_INFO * pstPaymentNotifyInfo, const ST_DENO_INFO * pstAllowBillDeno, const ST_DENO_INFO * pstAllowCoinDeno);
	//IPC报文解析，UI进程调用
	void PayInfoNotifyParse(CIpcMsgText * pcIpcRawData, ST_TVM_PAYMENT_NOTIFY_INFO * pstPaymentNotifyInfo, ST_DENO_INFO * pstAllowBillDeno, ST_DENO_INFO * pstAllowCoinDeno);


	//4)显示确认按钮通知，进行充值和售票业务时，业务层可以配置是否由乘客确认后，才触发交易。在这种情况下，业务层在判断支付金额满足交易条件，且确认钱币接收装置已经关闭时，向界面发送显示确认按钮通知。界面显示确认按钮后，如果乘客修改票价等信息，造成支付金额不满足交易条件，则由界面自行隐藏确认按钮。
	//交易类型
	void ShowConfirmNotify(EM_SLE_TRANSACATION_TYPE emTransType);
	//IPC报文解析，UI进程调用
	void ShowConfirmNotifyParse(const CIpcMsgText * pcIpcRawData, EM_SLE_TRANSACATION_TYPE *pemTransType);


	//5)票卡处理通知，进行充值和售票业务时，交易确认后，TVM开始对票卡进行处理时，通知界面。
	//交易类型
	//处理票卡数量
	//找零金额
	//当前动作
	//已经处理票数量
	//已经找零金额
	void TicketProcessNotify(const ST_TVM_PROCESS_NOTIFY_INFO *pstInfo);
	//IPC报文解析，UI进程调用
	void TicketProcessNotifyParse(const CIpcMsgText * pcIpcRawData, ST_TVM_PROCESS_NOTIFY_INFO *pstInfo);


	//6)交易结束通知
	//交易信息
	//票价总金额
	//支付总金额
	//总找零金额
	//实际找零金额
	//争议票
	//附加数据
	void TransResultNotify(const ST_TVM_TRANS_OVER_NOTIFY_INFO *pstInfo);
	//IPC报文解析，UI进程调用
	void TransResultNotifyParse(const CIpcMsgText * pcIpcRawData, ST_TVM_TRANS_OVER_NOTIFY_INFO *pstInfo);

	void TransStartNotify(EM_SLE_TRANSACATION_TYPE emTransType);
	void TransStartNotifyParse(const CIpcMsgText * pcIpcRawData, EM_SLE_TRANSACATION_TYPE * piTransType);

	void TransEndNotify();

	void InitProcessNotify(EM_SLE_UNIT_TYPE emUnitType, int iProcess, int iResult);
	void InitProcessNotifyParse(const CIpcMsgText * pcIpcRawData, int * piUnitType, int * piProcess, int * piResult);
	//IPC报文解析，UI进程调用

	//7)招援通知，乘客按下召援按钮时，TVM发送招援通知。
	//bHelpOrCancel:  true 触发求助; false 取消求助
	void HelpNotify(bool bHelpOrCancel);

	// 探测到有人通知
	//bHumanCome: true 有人接近; false 有人离去
	void HumanNotify(bool bHumanCome);
	//IPC报文解析，UI进程调用
	void HelpNotifyParse(const CIpcMsgText * pcIpcRawData, bool * pbHelpOrCancel);


	void PriceQueryAnswer(DWORD iDstPrice);
	void StationQueryAnswer(list<unsigned int>  *pRecordList);
	void PriceSetQueryAnswer(set<DWORD> * pPriceSet);
	void VersionQueryAnswer(list<ST_CSS_VERSION_INFO>  *pVersionRecordList);

	//20160510xuefeng
	void FlashCardNotify(EM_TVM_RECHARGE_FLASH emFlashCard);
	//IPC报文解析，UI进程调用
	void FlashCardNotifyParse(const CIpcMsgText * pcIpcRawData, EM_TVM_RECHARGE_FLASH *pemFlashCard);

	//20161107chenjc
	void SystemDataNotify(list<ST_TICKETBOX_INFO> * const pstTicketboxList, list<ST_CASHBOX_INFO>* const pCashBoxInfoList, map<DWORD, DWORD> * const RegisterDataMap);
	//IPC报文解析，UI进程调用
	void SystemDataNotifyParse(CIpcMsgText *pcIpcSrcData, list<ST_TICKETBOX_INFO> * pstTicketboxList, list<ST_CASHBOX_INFO>* pCashContainerList, map<DWORD, DWORD> * RegisterDataMap);

private:
	CIpcManager *m_pCManager; //发送IPC消息 ，接收IPC消息管理器
};

#endif /* VIROBJTVMUIFORCORE_H_ */
