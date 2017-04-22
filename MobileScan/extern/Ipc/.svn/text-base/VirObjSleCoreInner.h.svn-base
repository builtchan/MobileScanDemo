/*
 * VirObjTvmCoreForUI.h
 *
 *  Created on: Aug 29, 2014
 *      Author: root
 */

#ifndef VIROBJSLECOREINNER_H_
#define VIROBJSLECOREINNER_H_

#include "AfcPublic.h"
#include "VirObjectBase.h"
#include "IpcManager.h"

class CVirObjSleCoreInner :public CVirObjectBase
{
public:
	CVirObjSleCoreInner();
	virtual ~CVirObjSleCoreInner();

	void AgInsertTicketNotify();

//	void AgPollingTicketNotify(ST_POLLING_NOTIFY_PARAM * pstParam);
//	void AgPollingTicketNotifyParse(CIpcMsgText * pcIpcSrcData, ST_POLLING_NOTIFY_PARAM *pstParam);

	/*!\fn  CashPaymentNotify(list<ST_CASH_INFO> stCashInfoList)
	 *\brief 投入通知. 由业务层实现类回调函数注入下层部件接口类。
	 *\param[in] pCashInfoList 支付信息列表(支持多张/枚)
	 *\return
	 *\author: longjg
	 *\date 2016-11-11
	 */
	void CashPaymentNotify(list<ST_CASH_INFO> stCashInfoList);

	/*!\fn CashPaymentNotifyParse(CIpcMsgText* pcIpcRawData, list<ST_CASH_INFO>* pList)
	 *\brief 投入通知解析.
	 *\param[in] pList 支付信息列表(支持多张/枚)
	 *\return
	 *\author: longjg
	 *\date 2016-11-11
	 */
	void CashPaymentNotifyParse(CIpcMsgText* pcIpcRawData, list<ST_CASH_INFO>* pList);

	/*
	 * Func Brief:发往业务层的现金模块故障通知
	 */
	void TvmCashPaymentErrorNotify(EM_CASH_TYPE emCashType);
	/*
	 * Func Brief:现金模块故障通知解析
	 */
	void TvmCashPaymentErrorNotifyParse(CIpcMsgText * pcIpcSrcData, EM_CASH_TYPE * pemCashType);
	/*
	 * Func Brief:发往业务层的现金拒收通知
	 */
	void TvmCashPaymentRejectNotify(EM_CASH_TYPE emCashType, int iCount);
	/*
	 * Func Brief:现金拒收通知解析
	 */
	void TvmCashPaymentRejectNotifyParse(CIpcMsgText * pcIpcSrcData, EM_CASH_TYPE * pemCashType,int *iCount);

	/*
	 * Func Brief:人到Tvm前方通知
	 */
	void TvmPeopleComeNotify();
	/*
	 * Func Brief:人离开Tvm通知
	 */
	void TvmPeopleLeaveNotify();
	/*
	 * Func Brief:按下招援按钮通知
	 */
	void PushHelpButton();

//	/*
//	 * Func Brief:松开招援按钮通知
//	 */
//	void ReleaseHelpButton();

	void TvmInsertTicketNotify(bool bTicketInsert);//wangyzh修改加上参数
	void TvmInsertTicketNotifyParse(CIpcMsgText * pcIpcSrcData, bool *pbTicketInsert);


	void TvmBankcardInsertNotify();

	void SleStatusChangeNotify();

	void VendingTransferFirstPayCashParse(CIpcMsgText * pcIpcSrcData, ST_TVM_VENDING_REQUEST_INFO *pstInfo, EM_CASH_TYPE * pemCashType, int * piAmount);
	void VendingTransferFirstPayCashParse(const ST_TVM_VENDING_REQUEST_INFO *pstInfo, EM_CASH_TYPE emCashType, int iAmount, CIpcMsgText * pcIpcDesData);

	void AgPollingCardNotify(EM_SLE_TRANSACATION_TYPE emTransType, const ST_TPU_POLLING_CARD_INFO * pstPollingNotify);
	void AgPollingCardNotifyParse(CIpcMsgText * pcIpcSrcData, ST_TPU_POLLING_CARD_INFO * pstPollingNotify);

	void CashboxChangeNotify(ST_CASH_CONTAINER_LOCATION stCashboxLocation, EM_CONTAINER_OPERATION_TYPE emOperationType);
	void CashboxChangeNotifyParse(CIpcMsgText * pcIpcSrcData, ST_CASH_CONTAINER_LOCATION * pstCashboxLocation, EM_CONTAINER_OPERATION_TYPE * pemOperationType);

	void TicboxChangeNotify(ST_TICKET_CONTAINER_LOCATION stTicboxLocation, EM_CONTAINER_OPERATION_TYPE emOperationType);
	void TicboxChangeNotifyParse(CIpcMsgText * pcIpcSrcData, ST_TICKET_CONTAINER_LOCATION *pstTicboxLocation, EM_CONTAINER_OPERATION_TYPE * pemOperationType);

	void ContainerChangeNotify(ST_CONTAINER_LOCATION stContainerLocation, EM_CONTAINER_OPERATION_TYPE emOperationType);
	void ContainerChangeNotifyParse(CIpcMsgText* pcIpcSrcData, ST_CONTAINER_LOCATION* pstContainerLocation, EM_CONTAINER_OPERATION_TYPE* pemOperationType);

	void SendFirmwareTestEndFromMaintenceUI(ST_TEST_REQUEST_MSG stTestRequestMsg);

	/*wangyzh修改*/
	void TvmPollingCardNotify();

	void AgmPollingCardNotify();

	/*wangzp添加*/
	bool PowerLevelNotify(EM_POWER_MSG_NOTIFY emPowerMsgNotify, int iPowerLevel);
private:
	CIpcManager *m_pCManager; //发送IPC消息 ，接收IPC消息管理器
};

#endif /* VIROBJSLECOREINNER_H_ */
