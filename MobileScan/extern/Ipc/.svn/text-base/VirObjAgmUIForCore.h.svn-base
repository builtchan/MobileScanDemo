/*
 * VirObjAgmUIForCore.h
 *
 *  Created on: 2015-2-2
 *      Author: root
 */

#ifndef VIROBJAGMUIFORCORE_H_
#define VIROBJAGMUIFORCORE_H_

#include <stdlib.h>
#include <string.h>

#include "VirObjectBase.h"
#include "ipcpublic.h"
#include "IpcManager.h"
#include "IpcMsgSortContainer.h"
#include "IpcMsgText.h"

#define MSTTESTDAT_ARRAY_LEN 24

class CVirObjAgmUIForCore : public CVirObjectBase
{

public :
	CVirObjAgmUIForCore();
	virtual ~CVirObjAgmUIForCore();

   /*! \fn CVirObjAgmUIForCore::ModeNotify(ST_WORK_MODE_NOTIFY * pstWorkModeNotify)
	* \brief 		模式通知，当主业务模式发生变化时实时向界面发送模式通知
	* \param[in] 	pstWorkModeNotify：工作模式
	* \return 		无
	* \author 	    shaopf
	* \date 		2015－2－10
	*/
	void  ModeNotify(ST_AGM_MODE_NOTIFY *pstWorkModeNotify, list<ST_IPCMSG_ADDITIONAL_RECORD> *pRecordList);

	void  ModeNotifyParse(CIpcMsgText *pcIpcSrcData, ST_AGM_MODE_NOTIFY *pstWorkModeNotify, list<ST_IPCMSG_ADDITIONAL_RECORD>  *pRecordList);


	/*! \fn CVirObjAgmUIForCore::CheckSuccessNotify()
	* \brief 		检票成功通知，进出站检票成功后，AG业务通知界面
	* \param[in] 	ST_CHECK_TICKET_RESULT 差票成功通知信息
	* \return 		无
	* \author 		shaopf
	* \date 		2015－2－10
	*/
	void CheckSuccessNotify( ST_CHECK_TICKET_RESULT* pstCheckTicketResult);

	void CheckSuccessNotifyParse(CIpcMsgText * pcIpcSrcData, ST_CHECK_TICKET_RESULT* pstCheckTicketResult);


	/*! \fn CVirObjAgmUIForCore::CheckFailNotify()
	* \brief 		检票失败通知，进行充值和售票业务时，TVM检测到乘客支付，通知界面更新显示信
	* \param[in] 	ST_CHECK_TICKET_RESULT，查票失败通知信息
	* \return 		无
	* \author 		shaopf
	* \date 		2015－2－10
	*/
	void CheckFailNotify(ST_CHECK_TICKET_RESULT* pstCheckTicketResultfail) ;
	void CheckFailNotifyParse(CIpcMsgText * pcIpcSrcData, ST_CHECK_TICKET_RESULT* pstCheckTicketResultfail) ;


	/*! \fn CVirObjAgmUIForCore::ChannelStateNotify()
	* \brief 		通道状态通知，通道状态发生变化时，通知界面。
	* \param[in] 	iEntryDirAuthValue：进站方向授权值
	* \param[in] 	iExitDirAuthValue：出站方向授权值
	* \param[in] 	ST_CHANNEL_STATE：通道状态通知
	* \return 		无
	* \author 		shaopf
	* \date 		2015－2－10
	*/
	void ChannelStateNotify(int iEntryAuthValue, int iExitAuthValue, ST_CHANNEL_STATE* pstChannelState) ;

	void ChannelStateNotifyParse(CIpcMsgText * pcIpcSrcData, int *piEntryAuthValue, int *piExitAuthValue, ST_CHANNEL_STATE* pstChannelState) ;

	void InitProcessNotify(EM_SLE_UNIT_TYPE emUnitType, int iProcess, int iResult);
	void InitProcessNotifyParse(const CIpcMsgText * pcIpcRawData, int * piUnitType, int * piProcess, int * piResult);
	void VersionQueryAnswer(list<ST_CSS_VERSION_INFO>  *pVersionRecordList);

	/*! \fn 		PollCardNotify()
	* \brief 		寻卡通知，进行充值和查询业务时，检测到乘客插入已放卡，通知界面。
	* \param[in] 	emTransType：交易类型
	* \param[in] 	emValidity：卡的有效性
	* \param[in] 	pstTpuReadCardInfo：读到的卡信息
	* \return 		无
	* \author 		shaopf
	* \date 		2015－07－30
	*/
	void PollCardNotify(EM_SLE_TRANSACATION_TYPE emTransType, EM_TVM_VALIDITY emValidity, const ST_TPU_READ_CARD_INFO *pstTpuReadCardInfo);
	void PollCardNotifyParse(CIpcMsgText *pcIpcSrcData, EM_SLE_TRANSACATION_TYPE *pemTransType, EM_TVM_VALIDITY *pemValidity, ST_TPU_READ_CARD_INFO *pstTpuReadCardInfo);

	/*! \fn 		SwitchModeNotify()
	* \brief 		闸机验票模式跟检票模式切换通知。
	* \param[in] 	bQueryMode： true 表示验票模式; false 表示检票模式.
	* \return 		无
	* \author 		shaopf
	* \date 		2015－08－05
	*/
	void SwitchModeNotify(bool bQueryMode);
	void SwitchModeNotifyParse(CIpcMsgText *pcIpcSrcData, bool *pbQueryMode);

	void AgWdTicketSuccessNotify(ST_TICKET_CONTAINER_LOCATION stTicketContainerLocation);
	void AgWdTicketSuccessNotifyParse(CIpcMsgText* pcIpcSrcData, ST_TICKET_CONTAINER_LOCATION* pstTicketContainerLocation);
private:

};


#endif /* VIROBJAGMUIFORCORE_H_ */
