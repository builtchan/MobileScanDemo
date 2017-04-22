/*
 * VirObjTvmCoreForUI.h
 *
 *  Created on: Aug 29, 2014
 *      Author: root
 */

#ifndef VIROBJTVMCOREFORUI_H_
#define VIROBJTVMCOREFORUI_H_

#include "VirObjectBase.h"

class CVirObjTvmCoreForUI :public CVirObjectBase
{
public:
	CVirObjTvmCoreForUI();
	virtual ~CVirObjTvmCoreForUI();

	/*! \fn void OperateAheadTrans(EM_TVM_OPERATE emAction);
	 * \brief 		乘客交易前操作
	 * \param[in] 	emAction 动作
	 * \return  	无
	 * \author 		xuefeng
	 * \date 		2014－9－2
	*/

	void OperateAheadTrans(EM_TVM_OPERATE emAction);

	//解析IPC报文 slecore进程调用
	//stIpcData 要解析的原始数据
	void OperateAheadTransParse(const CIpcMsgText * pcIpcRawData, EM_TVM_OPERATE *emAction);

	/*! \fn void VendingTransRequest(int iDstID, int iPrice, int iTicketNum, ST_TVM_VENDING_REQUEST_INFO stInfo);
	 * \brief 		售票交易请求
	 * \param[in] 	iDstID 	目的车站ID 0表示无效。参数1无效时参数2必须有效
	 * \param[in]   iPrice  单价金额 0表示无效。参数2无效时参数1必须有效
	 * \param[in]   iTicketNum  购票数量，不能小于1
	 * \param[in]   stInfo 	//Byte 0: 车票类型，默认值：0
							//Byte 1:舱位等级，默认值：0
							//Byte 2:语言种类，默认值：0
							//Byte 3:预留
	 * \return  	无
	 * \author 		xuefeng
	 * \date 		2014－9－2
	*/
	void VendingTransRequest(const ST_TVM_VENDING_REQUEST_INFO * pstInfo);

	//解析IPC报文 slecore进程调用
	void VendingTransRequestParse(const CIpcMsgText * pcIpcRawData, ST_TVM_VENDING_REQUEST_INFO * pstInfo);

	/*! \fn void RechargeTransRequest(int iPrice);
	 * \brief 		充值交易请求
	 * \param[in] 	emRechargeID 充值交易方式 iPrice 乘客选择充值金额，0表示乘客没有选择 打印标记
	 * \return  	无
	 * \author 		xuefeng
	 * \date 		2014－9－2
	*/
	void RechargeTransRequest(const ST_TVM_RECHARGE_REQUEST_INFO *pstInfo);

	//解析IPC报文 slecore进程调用
	void RechargeTransRequestParse(const CIpcMsgText * pcIpcRawData, ST_TVM_RECHARGE_REQUEST_INFO *pstInfo);


	/*! \fn void QueryTransRequest();
	 * \brief 		查询交易请求
	 * \param[in] 	无
	 * \return  	无
	 * \author 		xuefeng
	 * \date 		2014－9－2
	*/
	void QueryTransRequest();

	/*! \fn void ConfirmTransRequest(EM_TVM_TRANS_TYPE emType, int iTransSumPrice, int iPaySumPrice);
	 * \brief 		乘客确认交易
	 * \param[in] 	emType 交易类型 1售票 2充值
	 * \param[in]   iTransSumPrice  交易总价金额
	 * \param[in]   iPaySumPrice  支付总金额
	 * \return  	无
	 * \author 		xuefeng
	 * \date 		2014－9－2
	*/
	void ConfirmTransRequest(const ST_TVM_CONFIRM_REQUEST_INFO *stInfo);
	//解析IPC报文 slecore进程调用
	void ConfirmTransRequestParse(const CIpcMsgText * pcIpcRawData, ST_TVM_CONFIRM_REQUEST_INFO *pstInfo);

	/*! \fn void CancelTransRequest(EM_TVM_TRANS_TYPE emType, int iTransSumPrice, int iPaySumPrice);
	 * \brief 		乘客取消交易请求
	 * \param[in] 	emType 交易类型
	 * \param[in]	iTransSumPrice 交易总价金额
	 * \param[in]   iPaySumPrice 支付总金额
	 * \return  	无
	 * \author 		xuefeng
	 * \date 		2014－9－2
	*/
	void CancelTransRequest(const ST_TVM_CANCEL_REQUEST_INFO *pstInfo);
	//解析IPC报文 slecore进程调用
	void CancelTransRequestParse(const CIpcMsgText * pcIpcRawData, ST_TVM_CANCEL_REQUEST_INFO *pstInfo);

	/*! \fn void PriceQueryRequest(int iDstID, int *piDstPrice);
	 * \brief 		充值交易请求
	 * \param[in]   DWORD dwDesStationID;	//目的车站ID
	 * \param[in]   DWORD dwTicketPrice;	//填0
	 * \param[in]   DWORD dwTicketCount;	//填0
	 * \param[in]   DWORD uiTicketType;		//车票类型，必须赋值
	 * \param[in]   WORD usTicketSubType;	//车票子类型，默认值：0
	 * \param[in]   BYTE ucLevel;			//舱位等级，默认值：0
	 * \param[in]   BYTE ucPassengerType;	//乘客类型，默认值：0
	 * \param[in]   BYTE ucLanguage;		//填0
	 * \param[in]   BYTE ucCardType;		//卡片类型，默认值：0
	 * \param[out]	piDstPrice 目的车站票价
	 * \return  	无
	 * \author 		xuefeng
	 * \date 		2014－9－2
	*/
	void PriceQueryRequest(const ST_TICKET_PRICE_REQUEST_INFO * pstInfo, DWORD *puiDstPrice);
	void PriceQueryRequestParse(const CIpcMsgText * pcIpcRawData, ST_TICKET_PRICE_REQUEST_INFO * pstInfo);

	/*! \fn void StationQueryRequest(int iDstPrice, int *piAddiLen, void *pStationList);
	 * \brief 		站点查询
	 * \param[in] 	iDstPrice 目的票价
	 * \param[out]  piAddiLen 数据长度
	 * \param[out]  pStationList 车站列表
	 * \return  	无
	 * \author 		xuefeng
	 * \date 		2014－9－2
	*/
	void StationQueryRequest(int iDstPrice, list<unsigned int>  *pRecordList);

	/*! \fn void PriceSetQueryRequest(int iDstPrice, list<unsigned int>  *pRecordList);
	 * \brief 		票价集合查询
	 * \param[in] 	无
	 * \param[out]  pPriceSet 票价集合
	 * \return  	无
	 * \author 		wugang
	 * \date 		2015－4－18
	*/
	void PriceSetQueryRequest(set<unsigned int>  *pPriceSet);

	/*! \fn void VersionQueryRequest(int *piAddiLen, void *pAddiData);
	 * \brief 		版本查询
	 * \param[out] 	piAddiLen 数据长度
	 * \param[out]  pAddiData 版本信息
	 * \return  	无
	 * \author 		xuefeng
	 * \date 		2014－9－2
	*/
	bool VersionQueryRequest(list<ST_CSS_VERSION_INFO>  *pVersionRecordList);

	/*! \fn void HelpRequest(ST_TVM_HELP stHelp);
	 * \brief 		请求招援
	 * \param[in] 	bHelpOrCancel:  true 触发求助; false 取消求助
	 * \return  	无
	 * \author 		xuefeng
	 * \date 		2014－9－2
	*/
	void HelpRequest(bool bHelpOrCancel);
	//解析IPC报文 slecore进程调用
	void HelpRequestParse(const CIpcMsgText * pcIpcRawData, bool * pbHelpOrCancel);

	//wangyzh20150618
	void VoucherRequest(EM_SLE_TRANSACATION_TYPE emSleType, bool bPrint);
	void VoucherRequestParse(const CIpcMsgText * pcIpcRawData, EM_SLE_TRANSACATION_TYPE *emSleType, bool *pbPrint);

	//guocq20150814
	void EnterMaintanceRequest();
	void EnterMaintanceRequestParse();


	//xuefeng20160510
	void FlashCardContinueRequest(bool bConfirmOrCancel);
	void FlashCardContinueRequestParse(const CIpcMsgText * pcIpcRawData,  bool *pbConfirmOrCancel);

};

#endif /* VIROBJTVMCOREFORUI_H_ */
