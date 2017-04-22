/*
 * VirObjTvmMaintenceForCore.h
 *
 *  Created on: Dec 18, 2014
 *      Author: longjg
 */

#ifndef VIROBJTVMMAINTENCEFORCORE_H_
#define VIROBJTVMMAINTENCEFORCORE_H_

#include "VirObjectBase.h"

#include "ipcpublic.h"

#include "IpcManager.h"
#include "IpcMsgSortContainer.h"
#include "IpcMsgText.h"


class CVirObjMaintenceForCore : public CVirObjectBase
{
public:
	CVirObjMaintenceForCore();
	virtual ~CVirObjMaintenceForCore();

//	void NotifyChangeContainerInfo();
	//票箱更换开始结果通知
	//param[in] bool bAllAllow 1：全部允许，0：不是全部允许
	//param[in] list<ST_TICKET_CONTAINER_LOCATION>* pErrorBoxList 问题钱票箱LOCATION记录集
	void TicketboxChangeBeginResultNotify(bool bAllAllow,list<ST_TICKET_CONTAINER_LOCATION>  *pRecordList);
	//票箱更换开始结果通知解析
	//param[out] bool piAllAllow 1：全部允许，0：不是全部允许
	//param[out] list<ST_TICKET_CONTAINER_LOCATION>* pErrorBoxList 问题钱票箱LOCATION记录集
	void TicketboxChangeBeginResultNotifyParse(CIpcMsgText * pcIpcRawData, list<ST_TICKET_CONTAINER_LOCATION>  *pRecordList, bool* pbAllAllow);

	//票箱更换结束结果通知
	//param[in] list<ST_TIC_CONTAINER_CHANGE_INFO>* pErrorBoxList 问题钱票箱LOCATION记录集
	void TicketboxChangeFinishResultNotify(list<ST_TICKETBOX_CHANGE_INFO>* pRecordList);
	//票箱更换结束结果通知解析
	//param[out] list<ST_TIC_CONTAINER_CHANGE_INFO>* pErrorBoxList 问题钱票箱LOCATION记录集
	void TicketboxChangeFinishResultNotifyParse(CIpcMsgText * pcIpcRawData, list<ST_TICKETBOX_CHANGE_INFO>  *pRecordList);

	//票箱更换过程状态变化通知
	//param[in] list<ST_CASH_CONTAINER_INFO>* pTicketBoxInfoList 票箱信息记录集
	void TicketboxChangeStatusNotify(bool bIsNormalChange, list<ST_TICKETBOX_INFO>* pRecordList);

	//票箱更换过程状态变化通知解析
	//param[in] list<ST_CASH_CONTAINER_INFO>* pTicketBoxInfoList 票箱信息记录集

	void TicketboxChangeStatusNotifyParse(CIpcMsgText* pcIpcRawData, list<ST_TICKETBOX_INFO>* pRecordList, bool* pbIsNormalChange);


	//票箱解锁
	//param[in] bool bUnlock 解锁true成功 false失败
//	void TicketboxUnlockNotify(bool bUnlock);
	//票箱解锁
	//param[out] bool bUnlock 解锁true成功 false失败
//	void TicketboxUnlockNotifyParse(CIpcMsgText * pcIpcRawData,bool* pbUnlock);

	//钱箱更换开始结果通知
	//param[in] bool bAllAllow 1：全部允许，0：不是全部允许
	//param[in] list<ST_TICKET_CONTAINER_LOCATION>* pErrorBoxList 问题钱票箱LOCATION记录集
	void CashboxChangeBeginResultNotify(bool bAllAllow,list<ST_CASH_CONTAINER_LOCATION>  *pErrorBoxList);
	//钱箱更换开始结果通知解析
	//param[out] bool bAllAllow 1：全部允许，0：不是全部允许
	//param[out] list<ST_TICKET_CONTAINER_LOCATION>* pErrorBoxList 问题钱票箱LOCATION记录集
	void CashboxChangeBeginResultNotifyParse(CIpcMsgText * pcIpcRawData, list<ST_CASH_CONTAINER_LOCATION>  *pRecordList, bool* pbAllAllow);

	//钱箱更换结束结果通知
	//param[in] list<ST_TIC_CONTAINER_CHANGE_INFO>* pErrorBoxList 问题钱票箱LOCATION记录集
	void CashboxChangeFinishResultNotify(list<ST_CASHBOX_CHANGE_INFO>* pRecordList);
	//钱箱更换结束结果通知解析
	//param[out] list<ST_TIC_CONTAINER_CHANGE_INFO>* pErrorBoxList 问题钱票箱LOCATION记录集
	void CashboxChangeFinishResultNotifyParse(CIpcMsgText * pcIpcRawData, list<ST_CASHBOX_CHANGE_INFO>  *pRecordList);

	//钱箱更换过程状态变化通知
	//param[in] list<ST_CASH_CONTAINER_INFO>* pTicketBoxInfoList 票箱信息记录集
	void CashboxChangeStatusNotify(bool bIsNormalChange, list<ST_CASHBOX_INFO>* pRecordList);
	//钱箱更换过程状态变化通知解析
	//param[in] list<ST_CASH_CONTAINER_INFO>* pTicketBoxInfoList 票箱信息记录集
	void CashboxChangeStatusNotifyParse(CIpcMsgText* pcIpcRawData, list<ST_CASHBOX_INFO>* pRecordList, bool* pbIsNormalChange);

//	//钱箱解锁
//	//param[in] bool bUnlock 解锁true成功 false失败
//	void CashboxUnlockNotify(bool bUnlock);
//	//钱箱解锁
//	//param[out] bool bUnlock 解锁true成功 false失败
//	void CashboxUnlockNotifyParse(CIpcMsgText * pcIpcRawData,bool* pbUnlock);

//	bool AsyncCallToCore(const ST_TEXT_DATA * pstTextData);
//	bool SyncCallToCore(const ST_TEXT_DATA * pstTextData, ST_TEXT_DATA * pstData);

	void ModeNotify(ST_AGM_MODE_NOTIFY * pstWorkModeNotify,int iErrCount, const ST_DEVICE_ERROR_CODE *pstErr);

	void LoginRequestResponse(EM_LOGIN_VERIFY_RESULT emLoginVerifyResult);

//------------------------------------------------------------------------------------------------------------------------------------
	/*! \fn CVirObjMaintenceForCore::CommonTestAck(ST_TEST_FEEDBACK_MSG stTestFeedBackMsg, void* pStatusData, int iStatusDataLength)
	 * \brief 			一般测试应答(core给维修的应答)
	 * \param[in]		pstTestFeedBackMsg		部件测试反馈数据
	 * \param[in]		pStatusData				模块状态结构体
	 * \param[in]		iStatusDataLength		状态结构体数据长度
	 * \return			无
	 * \author 			longjg
	 * \date 			2015－3-24
	 */
	void CommonTestAck(ST_TEST_FEEDBACK_MSG stTestFeedBackMsg, void* pStatusData, int iStatusDataLength);
	void CommonTestAck(ST_TEST_FEEDBACK_MSG stTestFeedBackMsg, void* pStatusData, int iStatusDataLength, DWORD uiSpecialValue);
	void CommonTestAck(ST_TEST_FEEDBACK_MSG stTestFeedBackMsg, void* pStatusData, int iStatusDataLength, BYTE *pData, int iDataLength);
	void CommonTestAck(ST_TEST_FEEDBACK_MSG stTestFeedBackMsg, void* pStatusData, int iStatusDataLength, DWORD uiSpecialValue, BYTE *pData, int iDataLength);

	//------------------------------------------------------------------------------------------------------------------------------------
	/*! \fn CVirObjMaintenceForCore::LoopReadSensorTestNotify(ST_TEST_FEEDBACK_MSG stTestFeedBackMsg,
 							unsigned int iSensorStatus1, unsigned int iSensorStatus2, unsigned int piSensorNum, void* pStatusData, int iStatusDataLength)
	 * \brief 			22.连续读传感器测试过程通知(core通知维修)
	 * \param[in]		stTestFeedBackMsg		部件测试反馈数据
	 * \param[in]		iSensorStatus1			传感器状态1~32
	 * \param[in]		iSensorStatus2			传感器状态33~64
	 * \param[in]		iSensorNum				传感器数量
	 * \param[in]		pSendStatusData			模块状态结构体
	 * \param[in]		iStatusDataLength		状态结构体数据长度
	 * \return			无
	 * \author 			longjg
	 * \date 			2015－3-24
	 */
	void LoopReadSensorTestNotify(ST_TEST_FEEDBACK_MSG stTestFeedBackMsg, unsigned int iSensorStatus1, unsigned int iSensorStatus2, unsigned int iSensorNum, void* pStatusData, int iStatusDataLength);
	/*! \fn CVirObjMaintenceForCore::LoopReadSensorTestNotifyParse(CIpcMsgText* pcIpcSrcData, ST_TEST_FEEDBACK_MSG* pstTestFeedBackMsg,
												unsigned int* piSensorStatus1, unsigned int* piSensorStatus2, nsigned int* piSensorNum, void* pStatusData, int iStatusDataLength)
	 * \brief 			22.连续读传感器测试过程通知解析(给维修调用)
	 * \param[in]		pcIpcSrcData			Ipc源数据
	 * \param[in]		pstTestFeedBackMsg		部件测试反馈数据
	 * \param[in]		piSensorStatus1			传感器状态1~32
	 * \param[in]		piSensorStatus2			传感器状态33~64
	 * \param[in]		piSensorNum				传感器数量
	 * \param[in]		pSendStatusData			模块状态结构体
	 * \param[in]		iStatusDataLength		状态结构体数据长度
	 * \return			无
	 * \author 			longjg
	 * \date 			2015－3-24
	 */
	void LoopReadSensorTestNotifyParse(CIpcMsgText* pcIpcSrcData, ST_TEST_FEEDBACK_MSG* pstTestFeedBackMsg, unsigned int* piSensorStatus1, unsigned int* piSensorStatus2, unsigned int* piSensorNum, void* pStatusData, int* piStatusDataLength);
//------------------------------------------------------------------------------------------------------------------------------------
	/*! \fn CVirObjMaintenceForCore::TruLoopRecycleTestNotify(EM_TEST_EXCUTE_RESULT emTestExcuteResult, unsigned int iRecycleCount, void* pStatusData, int iStatusDataLength)
	 * \brief 			23.车票回收模块连续回收票卡测试过程通知(core通知维修)
	 * \param[in]		emTestExcuteResult		部件测试执行结果
	 * \param[in]		iRecycleCount			回收数量
	 * \param[in]		pStatusData				状态结构体数据
	 * \param[in]		iStatusDataLength		状态结构体数据长度
	 * \return			无
	 * \author 			longjg
	 * \date 			2015－3-24
	 */
	void TruLoopRecycleTestNotify(EM_TEST_EXCUTE_RESULT emTestExcuteResult, unsigned int iRecycleCount, void* pStatusData, int iStatusDataLength);
	/*! \fn CVirObjMaintenceForCore::TruLoopRecycleTestNotifyParse(CIpcMsgText* pcIpcSrcData, EM_TEST_EXCUTE_RESULT* pemTestExcuteResult, unsigned int* piRecycleCount, void* pStatusData, int* piStatusDataLength)
	 * \brief 			23.车票回收模块连续回收票卡测试过程通知解析(给维修调用)
	 * \param[in]		pcIpcSrcData			Ipc源数据
	 * \param[in]		emTestExcuteResult		部件测试执行结果
	 * \param[in]		iRecycleCount			回收数量
	 * \param[in]		pStatusData				状态结构体数据
	 * \param[in]		iStatusDataLength		状态结构体数据长度
	 * \return			无
	 * \author 			longjg
	 * \date 			2015－3-24
	 */
	void TruLoopRecycleTestNotifyParse(CIpcMsgText* pcIpcSrcData, EM_TEST_EXCUTE_RESULT* pemTestExcuteResult, unsigned int* piRecycleCount, void* pStatusData, int* piStatusDataLength);
//------------------------------------------------------------------------------------------------------------------------------------
	/*! \fn CVirObjMaintenceForCore::TruLoopRefundTestNotify(EM_TEST_EXCUTE_RESULT emTestExcuteResult, unsigned int iRefundCount, void* pStatusData, int iStatusDataLength)
	 * \brief 			24.车票回收模块连续退还票卡测试过程通知(core通知维修)
	 * \param[in]		emTestExcuteResult		部件测试执行结果
	 * \param[in]		iRefundCount			退还数量
	 * \param[in]		pStatusData				状态结构体数据
	 * \param[in]		iStatusDataLength		状态结构体数据长度
	 * \return			无
	 * \author 			longjg
	 * \date 			2015－3-24
	 */
	void TruLoopRefundTestNotify(EM_TEST_EXCUTE_RESULT emTestExcuteResult, unsigned int iRefundCount, void* pStatusData, int iStatusDataLength);
	/*! \fn CVirObjMaintenceForCore::TruLoopRefundTestNotifyParse(CIpcMsgText* pcIpcSrcData, EM_TEST_EXCUTE_RESULT* pemTestExcuteResult, unsigned int* piRefundCount, void* pStatusData, int* piStatusDataLength)
	 * \brief 			24.车票回收模块连续退还票卡测试过程通知解析(给维修调用)
	 * \param[in]		pcIpcSrcData			Ipc源数据
	 * \param[in]		emTestExcuteResult		部件测试执行结果
	 * \param[in]		piRefundCount			退还数量
	 * \param[in]		pStatusData				状态结构体数据
	 * \param[in]		iStatusDataLength		状态结构体数据长度
	 * \return			无
	 * \author 			longjg
	 * \date 			2015－3-24
	 */
	void TruLoopRefundTestNotifyParse(CIpcMsgText* pcIpcSrcData, EM_TEST_EXCUTE_RESULT* pemTestExcuteResult, unsigned int* piRefundCount, void* pStatusData, int* piStatusDataLength);
//--------------------------------------------------------------------------------------------------------------------------------------
	/*! \fn CVirObjMaintenceForCore::TPULoopPollCardNotify(ST_TEST_FEEDBACK_MSG stTestFeedBackMsg, EM_POLLED_CARD_RESULT emPolledCardResult,
										unsigned int iCardNo, void* pStatusData, int iStatusDataLength)
	 * \brief 			25.TPU连续寻卡过程通知(core通知维修)
	 * \param[in]		stTestFeedBackMsg		部件测试反馈数据
	 * \param[in]		emPolledCardResult		寻卡结果
	 * \param[in]		iCardNo					卡号
	 * \param[in]		pStatusData				状态结构体数据
	 * \param[in]		iStatusDataLength		状态结构体数据长度
	 * \return			无
	 * \author 			longjg
	 * \date 			2015－3-24
	 */
	void TPULoopPollCardNotify(ST_TEST_FEEDBACK_MSG stTestFeedBackMsg, EM_POLLED_CARD_RESULT emPolledCardResult,  char *szCardNo, int iCardNoLength, void* pStatusData, int iStatusDataLength);
	void TPULoopPollCardNotify(ST_TEST_FEEDBACK_MSG stTestFeedBackMsg, void* pstTpuPollCardInfo, int iTpuPollCardInfoLength, void* pStatusData, int iStatusDataLength);
	/*! \fn CVirObjMaintenceForCore::TPULoopPollCardNotifyParse(CIpcMsgText* pcIpcSrcData, ST_TEST_FEEDBACK_MSG* pstTestFeedBackMsg, EM_POLLED_CARD_RESULT* pemPolledCardResult,
										unsigned int* piCardNo, void* pStatusData, int* piStatusDataLength)
	 * \brief 			25.TPU连续寻卡过程通知解析(给维修调用)
	 * \param[in]		pcIpcSrcData			Ipc源数据
	 * \param[in]		pstTestFeedBackMsg		部件测试反馈数据
	 * \param[in]		pemPolledCardResult		寻卡结果
	 * \param[in]		piCardNo				卡号
	 * \param[in]		pStatusData				状态结构体数据
	 * \param[in]		iStatusDataLength		状态结构体数据长度
	 * \return			无
	 * \author 			longjg
	 * \date 			2015－3-24
	 */
	void TPULoopPollCardNotifyParse(CIpcMsgText* pcIpcSrcData, ST_TEST_FEEDBACK_MSG* pstTestFeedBackMsg, EM_POLLED_CARD_RESULT* pemPolledCardResult,  char *szCardNo, int *piCardNoLength, void* pStatusData, int* piStatusDataLength);
	void TPULoopPollCardNotifyParse(CIpcMsgText* pcIpcSrcData, ST_TEST_FEEDBACK_MSG* pstTestFeedBackMsg, void* stTpuPollCardInfo, int* piTpuPollCardInfoLength, void* pStatusData, int* piStatusDataLength);
	//--------------------------------------------------------------------------------------------------------------------------------------
	/*! \fn CVirObjMaintenceForCore::TiuLoopIssueTestNotify(EM_TEST_EXCUTE_RESULT emTestExcuteResult, int iFinishedCount, void* pStatusData, int iStatusDataLength)
	 * \brief 			26.车票发行模块连续出票测试过程通知(core通知维修)
	 * \param[in]		emTestExcuteResult		部件测试执行结果
	 * \param[in]		iFinishedCount			出票数量
	 * \param[in]		pStatusData				状态结构体数据
	 * \param[in]		iStatusDataLength		状态结构体数据长度
	 * \return			无
	 * \author 			longjg
	 * \date 			2015－3-24
	 */
	void TiuLoopIssueTestNotify(EM_TEST_EXCUTE_RESULT emTestExcuteResult, int iFinishedCount, void* pStatusData, int iStatusDataLength);
	/*! \fn CVirObjMaintenceForCore::TiuLoopIssueTestNotifyParse(CIpcMsgText* pcIpcSrcData, EM_TEST_EXCUTE_RESULT *pemTestExcuteResult, int *piFinishedCount, void* pStatusData, int *piStatusDataLength)
	 * \brief 			26.车票发行模块连续出票测试过程通知解析(给维修调用)
	 * \param[in]		pcIpcSrcData			Ipc源数据
	 * \param[in]		pemTestExcuteResult		部件测试执行结果
	 * \param[in]		piFinishedCount			出票数量
	 * \param[in]		pStatusData				状态结构体数据
	 * \param[in]		iStatusDataLength		状态结构体数据长度
	 * \return			无
	 * \author 			longjg
	 * \date 			2015－3-24
	 */
	void TiuLoopIssueTestNotifyParse(CIpcMsgText * pcIpcSrcData, EM_TEST_EXCUTE_RESULT *pemTestExcuteResult, int *piFinishedCount, void* pStatusData, int *piStatusDataLength);
//--------------------------------------------------------------------------------------------------------------------------------------
	/*! \fn CVirObjMaintenceForCore::TiuLoopRecycleTestNotify(EM_TEST_EXCUTE_RESULT emTestExcuteResult, int iFinishedCount, void* pStatusData, int iStatusDataLength)
	 * \brief 			27.车票发行模块连续回收测试过程通知(core通知维修)
	 * \param[in]		emTestExcuteResult		部件测试执行结果
	 * \param[in]		iFinishedCount			回收数量
	 * \param[in]		pStatusData				状态结构体数据
	 * \param[in]		iStatusDataLength		状态结构体数据长度
	 * \return			无
	 * \author 			longjg
	 * \date 			2015－3-24
	 */
	void TiuLoopRecycleTestNotify(EM_TEST_EXCUTE_RESULT emTestExcuteResult, int iFinishedCount, void* pStatusData, int iStatusDataLength);
	/*! \fn CVirObjMaintenceForCore::TiuLoopRecycleTestNotify(CIpcMsgText* pcIpcSrcData, EM_TEST_EXCUTE_RESULT emTestExcuteResult, int iFinishedCount, void* pStatusData, int iStatusDataLength)
	 * \brief 			27.车票发行模块连续回收测试过程通知(给维修调用)
	 * \param[in]		pcIpcSrcData			Ipc源数据
	 * \param[in]		emTestExcuteResult		部件测试执行结果
	 * \param[in]		iFinishedCount			回收数量
	 * \param[in]		pStatusData				状态结构体数据
	 * \param[in]		iStatusDataLength		状态结构体数据长度
	 * \return			无
	 * \author 			longjg
	 * \date 			2015－3-24
	 */
	void TiuLoopRecycleTestNotifyParse(CIpcMsgText* pcIpcSrcData, EM_TEST_EXCUTE_RESULT *pemTestExcuteResult, int *piFinishedCount, void* pStatusData, int *piStatusDataLength);
//--------------------------------------------------------------------------------------------------------------------------------------
	/*! \fn CVirObjMaintenceForCore::CashLoopPressInBoxTestNotify(ST_TEST_FEEDBACK_MSG stTestFeedBackMsg,
	 	 	 	 	 	 	 	 	 ST_CASH_BRIEFLY_STORAGE_AREA stBrieflyStorageArea, void* pStatusData, int iStatusDataLength)
	 * \brief 			28.现金模块连续投币压箱测试过程通知(core通知维修)
	 * \param[in]		stTestFeedBackMsg				部件测试反馈数据
	 * \param[in]		stBrieflyStorageArea			暂存区记录数据
	 * \param[in]		pStatusData						状态结构体数据
	 * \param[in]		iStatusDataLength				状态结构体数据长度
	 * \return			无
	 * \author 			longjg
	 * \date 			2015－3-24
	 */
	void CashLoopPressInBoxTestNotify(ST_TEST_FEEDBACK_MSG stTestFeedBackMsg, ST_CASH_BRIEFLY_STORAGE_AREA stBrieflyStorageArea, void* pStatusData, int iStatusDataLength);
	/*! \fn CVirObjMaintenceForCore::CashLoopPressInBoxTestNotifyParse(CIpcMsgText* pcIpcSrcData, ST_TEST_FEEDBACK_MSG* pstTestFeedBackMsg
								ST_CASH_BRIEFLY_STORAGE_AREA* pstBrieflyStorageArea, void* pStatusData, int* piStatusDataLength)
	 * \brief 			28.现金模块连续投币压箱测试过程通知解析(给维修调用)
	 * \param[in]		pcIpcSrcData					Ipc源数据
	 * \param[in]		pstTestFeedBackMsg				部件测试执行结果
	 * \param[in]		pstBrieflyStorageArea			暂存区记录数据
	 * \param[in]		pStatusData						状态结构体数据
	 * \param[in]		piStatusDataLength				状态结构体数据长度
	 * \return			无
	 * \author 			longjg
	 * \date 			2015－3-24
	 */
	void CashLoopPressInBoxTestNotifyParse(CIpcMsgText* pcIpcSrcData, ST_TEST_FEEDBACK_MSG* pstTestFeedBackMsg, ST_CASH_BRIEFLY_STORAGE_AREA* pstBrieflyStorageArea, void* pStatusData, int* piStatusDataLength);

	void TpuLoopUpdateTestNotify(ST_TEST_FEEDBACK_MSG stTestFeedBackMsg, ST_LOOP_UPDATE_STATUS_FEEDBACK stLoopUpdateStatusFeedback, void* pStatusData, int iStatusDataLength);
	void TpuLoopUpdateTestNotifyParse(CIpcMsgText* pcIpcSrcData, ST_TEST_FEEDBACK_MSG* pstTestFeedBackMsg, ST_LOOP_UPDATE_STATUS_FEEDBACK* pstLoopUpdateStatusFeedback, void* pStatusData, int* piStatusDataLength);
//--------------------------------------------------------------------------------------------------------------------------------------
	/*! \fn CVirObjMaintenceForCore::CashLoopRefundTestNotify(ST_TEST_FEEDBACK_MSG stTestFeedBackMsg,
								ST_CASH_BRIEFLY_STORAGE_AREA stBrieflyStorageArea, void* pStatusData, int iStatusDataLength)
	 * \brief 			29.现金模块连续投币退还测试过程通知(core通知维修)
	 * \param[in]		stTestFeedBackMsg				部件测试反馈数据
	 * \param[in]		stBrieflyStorageArea			暂存区记录数据
	 * \param[in]		pStatusData						状态结构体数据
	 * \param[in]		iStatusDataLength				状态结构体数据长度
	 * \return			无
	 * \author 			longjg
	 * \date 			2015－3-24
	 */
	void CashLoopRefundTestNotify(ST_TEST_FEEDBACK_MSG stTestFeedBackMsg, ST_CASH_BRIEFLY_STORAGE_AREA stBrieflyStorageArea, void* pStatusData, int iStatusDataLength);
	/*! \fn CVirObjMaintenceForCore::CashLoopRefundTestNotifyParse(CIpcMsgText* pcIpcSrcData, ST_TEST_FEEDBACK_MSG* pstTestFeedBackMsg,
								ST_CASH_BRIEFLY_STORAGE_AREA* pstBrieflyStorageArea, void* pStatusData, int* piStatusDataLength)
	 * \brief 			29.现金模块连续投币退还测试过程通知(给维修调用)
	 * \param[in]		pcIpcSrcData					Ipc源数据
	 * \param[in]		pstTestFeedBackMsg				部件测试反馈数据
	 * \param[in]		pstBrieflyStorageArea			暂存区记录数据
	 * \param[in]		pStatusData						状态结构体数据
	 * \param[in]		piStatusDataLength				状态结构体数据长度
	 * \return			无
	 * \author 			longjg
	 * \date 			2015－3-24
	 */
	void CashLoopRefundTestNotifyParse(CIpcMsgText* pcIpcSrcData, ST_TEST_FEEDBACK_MSG* pstTestFeedBackMsg, ST_CASH_BRIEFLY_STORAGE_AREA* pstBrieflyStorageArea, void* pStatusData, int* piStatusDataLength);
//--------------------------------------------------------------------------------------------------------------------------------------
	/*! \fn CVirObjMaintenceForCore::CashLoopChangeTestNotify(ST_TEST_FEEDBACK_MSG stTestFeedBackMsg, unsigned int iChangeSum
								unsigned int iChangeSumAmount, void* pStatusData, int iStatusDataLength)
	 * \brief 			30.现金模块连续投币找零测试过程通知(core通知维修)
	 * \param[in]		stTestFeedBackMsg				部件测试反馈数据
	 * \param[in]		iChangeSum						找零总数
	 * \param[in]		iChangeSumAmount				找零总金额
	 * \param[in]		pStatusData						状态结构体数据
	 * \param[in]		iStatusDataLength				状态结构体数据长度
	 * \return			无
	 * \author 			longjg
	 * \date 			2015－3-24
	 */
	void CashLoopChangeTestNotify(ST_TEST_FEEDBACK_MSG stTestFeedBackMsg, unsigned int iChangeSum, unsigned int iChangeSumAmount, void* pStatusData, int iStatusDataLength);
	/*! \fn CVirObjMaintenceForCore::CashLoopChangeTestNotifyParse(CIpcMsgText* pcIpcSrcData, ST_TEST_FEEDBACK_MSG* pstTestFeedBackMsg, unsigned int* piChangeSum
								unsigned int* piChangeSumAmount, void* pStatusData, int* piStatusDataLength)
	 * \brief 			30.现金模块连续投币找零测试过程通知解析(给维修调用)
	 * \param[in]		pcIpcSrcData					Ipc源数据
	 * \param[in]		pstTestFeedBackMsg				部件测试反馈数据
	 * \param[in]		iChangeSum						找零总数
	 * \param[in]		iChangeSumAmount				找零总金额
	 * \param[in]		pStatusData						状态结构体数据
	 * \param[in]		iStatusDataLength				状态结构体数据长度
	 * \return			无
	 * \author 			longjg
	 * \date 			2015－3-24
	 */
	void CashLoopChangeTestNotifyParse(CIpcMsgText* pcIpcSrcData, ST_TEST_FEEDBACK_MSG* pstTestFeedBackMsg, unsigned int* piChangeSum, unsigned int* piChangeSumAmount, void* pStatusData, int* piStatusDataLength);
//-------------------------------------------------------------------------------------------------------------------------------------
	/*! \fn CVirObjMaintenceForCore::GcuLoopChangeTestNotify(EM_TEST_EXCUTE_RESULT emTestExcuteResult, unsigned int iReleaseSum,
											void* pStatusData, int iStatusDataLength)
	 * \brief 			31.门模块连续通行测试过程通知(core通知维修)
	 * \param[in]		emTestExcuteResult				部件测试执行结果
	 * \param[in]		iReleaseSum						总通过人数
	 * \param[in]		pStatusData						状态结构体数据
	 * \param[in]		iStatusDataLength				状态结构体数据长度
	 * \return			无
	 * \author 			longjg
	 * \date 			2015－3-24
	 */
	void GcuLoopGoThroughTestNotify(EM_TEST_EXCUTE_RESULT emTestExcuteResult, unsigned int iReleaseSum, void* pStatusData, int iStatusDataLength);
	/*! \fn CVirObjMaintenceForCore::GcuLoopChangeTestNotifyParse(CIpcMsgText* pcIpcSrcData, EM_TEST_EXCUTE_RESULT* pemTestExcuteResult,
												unsigned int* piReleaseSum, void* pStatusData, int* piStatusDataLength)
	 * \brief 			31.门模块连续通行测试过程通知解析(给维修调用)
	 * \param[in]		pcIpcSrcData					Ipc源数据
	 * \param[in]		pemTestExcuteResult				部件测试执行结果
	 * \param[in]		piReleaseSum					总通过人数
	 * \param[in]		pStatusData						状态结构体数据
	 * \param[in]		piStatusDataLength				状态结构体数据长度
	 * \return			无
	 * \author 			longjg
	 * \date 			2015－3-24
	 */
	void GcuLoopGoThroughTestNotifyParse(CIpcMsgText* pcIpcSrcData, EM_TEST_EXCUTE_RESULT* pemTestExcuteResult, unsigned int* piReleaseSum, void* pStatusData, int* piStatusDataLength);
//-------------------------------------------------------------------------------------------------------------------------------------
	/*! \fn CVirObjMaintenceForCore::LoopElectromotorTestNotify(ST_TEST_FEEDBACK_MSG stTestFeedBackMsg, void* pStatusData, int iStatusDataLength)
	 * \brief 			32.连续电机测试过程通知(core通知维修)
	 * \param[in]		pemTestExcuteResult				部件测试执行结果
	 * \param[in]		pstTestFeedBackMsg				部件测试反馈数据
	 * \param[in]		pStatusData						状态结构体数据
	 * \param[in]		piStatusDataLength				状态结构体数据长度
	 * \return			无
	 * \author 			longjg
	 * \date 			2015－3-24
	 */
	void LoopElectromotorTestNotify(ST_TEST_FEEDBACK_MSG stTestFeedBackMsg, void* pStatusData, int iStatusDataLength);
	/*! \fn CVirObjMaintenceForCore::LoopElectromotorTestNotifyParse(CIpcMsgText* pcIpcSrcData, ST_TEST_FEEDBACK_MSG* pstTestFeedBackMsg, void* pStatusData, int* piStatusDataLength)
	 * \brief 			32.连续电机测试过程通知解析(给维修调用)
	 * \param[in]		pcIpcSrcData					Ipc源数据
	 * \param[in]		pemTestExcuteResult				部件测试执行结果
	 * \param[in]		pstTestFeedBackMsg				部件测试反馈数据
	 * \param[in]		pStatusData						状态结构体数据
	 * \param[in]		piStatusDataLength				状态结构体数据长度
	 * \return			无
	 * \author 			longjg
	 * \date 			2015－3-24
	 */
	void LoopElectromotorTestNotifyParse(CIpcMsgText* pcIpcSrcData, ST_TEST_FEEDBACK_MSG* pstTestFeedBackMsg, void* pStatusData, int* piStatusDataLength);
//-------------------------------------------------------------------------------------------------------------------------------------
	/*! \fn CVirObjMaintenceForCore::LoopElectromagnetTestNotify(ST_TEST_FEEDBACK_MSG stTestFeedBackMsg, void* pStatusData, int iStatusDataLength)
	 * \brief 			33.连续电磁铁测试过程通知(core通知维修)
	 * \param[in]		pstTestFeedBackMsg				部件测试反馈数据
	 * \param[in]		pStatusData						状态结构体数据
	 * \param[in]		piStatusDataLength				状态结构体数据长度
	 * \return			无
	 * \author 			longjg
	 * \date 			2015－3-24
	 */
	void LoopElectromagnetTestNotify(ST_TEST_FEEDBACK_MSG stTestFeedBackMsg, void* pStatusData, int iStatusDataLength);
	/*! \fn CVirObjMaintenceForCore::LoopElectromagnetTestNotifyParse(CIpcMsgText* pcIpcSrcData,ST_TEST_FEEDBACK_MSG* pstTestFeedBackMsg,
														void* pStatusData, int* piStatusDataLength)
	 * \brief 			33.连续电磁铁测试过程通知解析(给维修调用)
	 * \param[in]		pcIpcSrcData					Ipc源数据
	 * \param[in]		pstTestFeedBackMsg				部件测试反馈数据
	 * \param[in]		pStatusData						状态结构体数据
	 * \param[in]		piStatusDataLength				状态结构体数据长度
	 * \return			无
	 * \author 			longjg
	 * \date 			2015－3-24
	 */
	void LoopElectromagnetTestNotifyParse(CIpcMsgText* pcIpcSrcData, ST_TEST_FEEDBACK_MSG* pstTestFeedBackMsg, void* pStatusData, int* piStatusDataLength);
//-------------------------------------------------------------------------------------------------------------------------------------
	/*! \fn DeviceStatusNotify
	 * \brief 			状态变化通知
	 * \param[in]		list<ST_IPCMSG_ADDITIONAL_RECORD> *pRecordList    记录列表
	 * \return			无
	 * \author 			wangzp
	 * \date 			2015－03-31
	 */
	void DeviceStatusNotify(list<ST_IPCMSG_ADDITIONAL_RECORD> *pRecordList);

	/*! \fn DeviceStatusNotifyParse
	 * \brief 			状态变化通知解析
	 * \param[in]		CIpcMsgText * pcIpcText    IPC报文
	 * \param[out]		list<ST_IPCMSG_ADDITIONAL_RECORD> *pRecordList    记录列表
	 * \return			无
	 * \author 			wangzp
	 * \date 			2015－03-31
	 */
	void DeviceStatusNotifyParse(CIpcMsgText * pcIpcText, list<ST_IPCMSG_ADDITIONAL_RECORD> *pRecordList);

	/*! \fn AgOperUIShowOrHide
	 * \brief 			AG维修界面显示或隐藏
	 * \param[in]		EM_UI_SHOW_OR_HIDE emUiShowOrHide
	 * \return			无
	 * \author 			wangzp
	 * \date 			2015－03-31
	 */
	void AgOperUIShowOrHide(EM_UI_SHOW_OR_HIDE emUiShowOrHide);

	/*! \fn AgOperUIShowOrHideParse
	 * \brief 			AG维修界面显示或隐藏解析
	 * \param[in]		CIpcMsgText * pcIpcText
	 * \param[out]		EM_UI_SHOW_OR_HIDE * pemUiShowOrHide
	 * \return			无
	 * \author 			wangzp
	 * \date 			2015－03-31
	 */
	void AgOperUIShowOrHideParse(CIpcMsgText * pcIpcText, EM_UI_SHOW_OR_HIDE * pemUiShowOrHide);

	/*! \fn CashFlushInfoNotify
	 * \brief 			钱箱清空过程通知
	 * \param[in]		EM_FLUSH_STATUS emFlushStatus    清空状态
	 * \param[in]		const list<ST_CASH_FLUSH_DATA_RECORD> * pstCashFlushRecordList
	 * \return			无
	 * \author 			wangzp
	 * \date 			2015－03-31
	 */
	void CashFlushInfoNotify(EM_FLUSH_STATUS emFlushStatus, list<ST_CASH_FLUSH_PARAM> * const pstCashFlushRecordList);

	/*! \fn CashFlushInfoNotifyParse
	 * \brief 			钱箱清空通知解析
	 * \param[in]		CIpcMsgText * pcIpcText    IPC报文
	 * \param[out]		list<ST_IPCMSG_ADDITIONAL_RECORD> *pRecordList    记录列表
	 * \return			无
	 * \author 			wangzp
	 * \date 			2015－03-31
	 */
	void CashFlushInfoNotifyParse(CIpcMsgText * pcIpcText, EM_FLUSH_STATUS* pemFlushStatus, list<ST_CASH_FLUSH_PARAM> *pRecordList);

	/*! \fn TokenFlushInfoNotify
	 * \brief 			Token清空过程通知
	 * \param[in]		EM_FLUSH_STATUS emFlushStatus    清空状态
	 * \param[in]		const list<ST_TOKEN_FLUSH_DATA_RECORD> * pstCashFlushRecordList
	 * \return			无
	 * \author 			wangzp
	 * \date 			2015－03-31
	 */
	void TokenFlushInfoNotify(EM_FLUSH_STATUS emFlushStatus, list<ST_TICKET_FLUSH_PARAM> * const pstTokenFlushRecordList);

	/*! \fn TokenFlushInfoNotifyParse
	 * \brief 			Token清空通知解析
	 * \param[in]		CIpcMsgText * pcIpcText    IPC报文
	 * \param[out]		list<ST_TOKEN_FLUSH_DATA_RECORD> *pRecordList    记录列表
	 * \return			无
	 * \author 			wangzp
	 * \date 			2015－03-31
	 */
	void TokenFlushInfoNotifyParse(CIpcMsgText * pcIpcText, EM_FLUSH_STATUS* pemFlushStatus, list<ST_TICKET_FLUSH_PARAM> * const pRecordList);

	/*! \fn CashSupplyInfoNotify
	 * \brief 			现金补充过程通知
	 * \param[in]		EM_FLUSH_STATUS emFlushStatus    清空状态
	 * \param[in]		list<ST_CASH_FLUSH_DATA_RECORD> * const pstCashSupplyRecordList
	 * \return			无
	 * \author 			wangzp
	 * \date 			2015－03-31
	 */
	void CashSupplyInfoNotify(EM_SUPPLY_STATUS emSupplyStatus, list<ST_CASH_FLUSH_DATA_RECORD> * const pstCashSupplyRecordList);

	/*! \fn CashSupplyInfoNotifyParse
	 * \brief 			现金补充过程通知解析
	 * \param[in]		CIpcMsgText * pcIpcText    IPC报文
	 * \param[out]		list<ST_CASH_FLUSH_DATA_RECORD> *pRecordList    记录列表
	 * \return			无
	 * \author 			wangzp
	 * \date 			2015－03-31
	 */
	void CashSupplyInfoNotifyParse(CIpcMsgText * pcIpcText, list<ST_CASH_FLUSH_DATA_RECORD> *pstCashSupplyRecordList);

	/*! \fn SynClockFinishNotify
	 * \brief 			异步命令完成通知
	 * \param[in]		bool bSuccess    是否成功
	 * \param[in]		bool bSuccess    是否成功
	 * \return			无
	 * \author 			wangzp
	 * \date 			2015－03-31
	 */
	void AsynCmdFinishNotify(EM_ASYN_CMD_TYPE emAsynCmdType, bool bSuccess, list<ST_IPCMSG_ADDITIONAL_RECORD> * pstIpcRecord);

	/*! \fn SynClockFinishNotifyParse
	 * \brief 			异步命令完成通知解析
	 * \param[in]		CIpcMsgText * pcIpcText    IPC报文
	 * \param[out]		bool * pbSuccess
	 * \return			无
	 * \author 			wangzp
	 * \date 			2015－03-31
	 */
	void AsynCmdFinishNotifyParse(CIpcMsgText * pcIpcText, EM_ASYN_CMD_TYPE * pemAsynCmdType, bool * pbSuccess, list<ST_IPCMSG_ADDITIONAL_RECORD> * pstIpcRecord);

	/*! \fn ProcessExitNotify
	 * \brief 			进程退出通知
	 * \param[in]
	 * \return			无
	 * \author 			wangzp
	 * \date 			2015－03-31
	 */
	void ProcessExitNotify();

	/*! \fn ControlCmdAck
	 * \brief 			控制命令应答
	 * \param[in]		bool bOk
	 * \return			无
	 * \author 			wangzp
	 * \date 			2015－03-31
	 */
	void ControlCmdAck(bool bOk);
	/*CashBoxFlushRequestResponse()
	 * \brief 			清空请求应答
	 * \param[in]		bool bOk
	 * \return			无
	 * \author 			hehj
	 * \date 			2015－04-11
	 */
	void CashBoxFlushRequestResponse(bool bOk);
	/*TicketBoxFlushRequestResponse()
	 * \brief 			清空请求应答
	 * \param[in]		bool bOk
	 * \return			无
	 * \author 			hehj
	 * \date 			2015－04-11
	 */
	void TicketBoxFlushRequestResponse(bool bOk);

	/*CashBoxFlushRequestResponse
	 * \brief 			错误重置请求应答
	 * \param[in]		bool bOk
	 * \return			无
	 * \author 			wangzp
	 * \date 			2015－04-11
	 */
	void ErrorClearRequestResponse(bool bOk,list<ST_IPCMSG_ADDITIONAL_RECORD> *pRecordList);
	/*CashBoxFlushRequestResponse
	 * \brief 			版本请求应答
	 * \param[in]		bool bOk
	 * \return			无
	 * \author 			hehj
	 * \date 			2015－04-11
	 */
	void VersionInfoRequestResponse(bool bOk,list<ST_IPCMSG_ADDITIONAL_RECORD> *pRecordList);

	void VersionQueryAnswer(list<ST_CSS_VERSION_INFO>  *pVersionRecordList);

	void SettlementAnswer(bool bResult, list<ST_IPCMSG_ADDITIONAL_RECORD> *pRecordList);
	void BalanceAnswer(bool bResult, list<ST_IPCMSG_ADDITIONAL_RECORD> *pRecordList);

	void VoucherPrintAnswer(bool bOK);
	void RunModeCmdAnswer(bool bOk);
	void CommonLoopTestEndNotify(BYTE emUnitID, BYTE emTestID);
	void FlushCommandAnswer(bool bOK);
	void UnitInitCommandAnswer(bool bOK);
	void ControlBoxUpDownCommandAnswer(bool bOK);

	//容器更换请求应答
	void ContainerChangeRequestAnswer(map<DWORD, ST_CONTAINER_DETAIL_INFO> stContainerDetailInfoMap);

	//容器操作请求应答
	void ContainerOperationRequestAnswer(EM_CONTAINER_OPERATION_RESULT emOperResult);

	//容器状态变更通知
	void ContainerStatusNotify(ST_CONTAINER_DETAIL_INFO stContainerDetailInfo);

	//容器状态变更通知解析
	void ContainerChangeNotifyParse(CIpcMsgText* pcIpcSrcData, ST_CONTAINER_DETAIL_INFO* pstContainerDetailInfo);

	//容器更换结束请求应答
	void ContainerChangeEndRequestAnswer(bool bContainerChangeEndResult);
private:
	CIpcManager *m_pCManager; //发送IPC消息 ，接收IPC消息管理器
};

#endif /* VIROBJTVMMAINTENCEFORCORE_H_ */
