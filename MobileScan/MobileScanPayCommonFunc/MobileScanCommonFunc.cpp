/*
 * MobileScanCommonFunc.cpp
 *
 *  Created on: Apr 18, 2017
 *      Author: chenjc
 */

#include "MobileScanCommonFunc.h"

REGISTER_COMM_WEB_PAT_BIZ(CMobileScanPayCommonFunc)

char m_szErrorInfo[10][256] = {"","乘客取消订单","预支付链接获取超时","获取支付结果超时","部分出票失败","全部出票失败","查询超时","撤销支付"};		//错误信息 暂时写死

CMobileScanPayCommonFunc::CMobileScanPayCommonFunc(CLogOper2 * pcLog)
{
	m_pCommonLog = pcLog;
	m_pQrCodePayAtomic  = new CQRCPay(pcLog);

	m_iConnectTimeOut = 5000;
	m_iWaitPayTimeOut = 5000;
	m_iTryTime = 3;
	m_bExitThread = false;
	m_bNetworkOK = false;
	m_pHandler = NULL;
	m_bOrderSend = false;
	m_bCreateQRCodeOk = false;
	m_bConfirmTrans = false;
	m_bFaultTrans = false;
	m_bCancelTrans = false;
	m_emRespFaultCode = EM_SYSTEM_ERROR;
	m_iErrorCode = 0;
	m_stCommonState = EM_DEVICE_COMMON_STATE_COMM_FAILTURE;
	memset(&m_stMobileScanStatus,0,sizeof(m_stMobileScanStatus));

	memset(&m_stOrderCommitRespData,0,sizeof(m_stOrderCommitRespData));
	memset(&m_stQRCodeRespData,0,sizeof(m_stQRCodeRespData));
	memset(&m_stPayResultReq,0,sizeof(m_stPayResultReq));
	memset(&m_stPayResultData,0,sizeof(m_stPayResultData));
	memset(&m_stExecResultReq,0,sizeof(m_stExecResultReq));
	memset(&m_stTransFaultReq,0,sizeof(m_stTransFaultReq));
	//初始化互斥锁
	pthread_mutex_init(&m_BizThreadMutex,NULL);

}

CMobileScanPayCommonFunc::~CMobileScanPayCommonFunc()
{
	if(NULL != m_pQrCodePayAtomic)
		delete m_pQrCodePayAtomic;
}

bool CMobileScanPayCommonFunc::Connect(const char* pszComPath, int iBaud, int iDataBits, char cParity, int iStopBits)
{
	return true;
}

bool CMobileScanPayCommonFunc::Connect(const char* pszComPath)
{
	m_pCommonLog->LogDebug("[%s][%s][%d] Connect!", __FILE__ , __FUNCTION__, __LINE__);
	//todo 用于设备认证
	int iRet;
	iRet = m_pQrCodePayAtomic->S009HeartBeat();			//暂时用心跳
	if(0 == iRet)
	{
		m_pCommonLog->LogDebug("[%s][%s][%d] Connect Ok!", __FILE__ , __FUNCTION__, __LINE__);
		m_stMobileScanStatus.emCommonState = EM_DEVICE_COMMON_STATE_OK;
	}
	else
	{
		m_pCommonLog->LogDebug("[%s][%s][%d] Connect Failed!", __FILE__ , __FUNCTION__, __LINE__);
		m_stMobileScanStatus.emCommonState = EM_DEVICE_COMMON_STATE_COMM_FAILTURE;
		AddErrorCode(EM_OUTLINE_FAULT);
	}

	if(0 != pthread_create(&m_BizThreadId,NULL,BizThread,(void*)this))
	{
		m_bExitThread = false;
		m_bThread = false;
		m_pCommonLog->LogError("[%s][%s][%d] BizThread create failed!", __FILE__ , __FUNCTION__, __LINE__);
	}
	else
	{
		m_bThread = true;
		m_pCommonLog->LogError("[%s][%s][%d] BizThread has been created!", __FILE__ , __FUNCTION__, __LINE__);
	}
	return true;
}
void CMobileScanPayCommonFunc::Disconnect()
{
	m_pCommonLog->LogDebug("[%s][%s][%d] Disconnect!", __FILE__ , __FUNCTION__, __LINE__);
	if(m_bThread)
	{
		m_pCommonLog->LogDebug("[%s][%s][%d] close thread start!", __FILE__ , __FUNCTION__, __LINE__);
		m_bThread = false;
		while(!m_bExitThread)
		{
			usleep(500);
		}
		void * pthread_exit_result;
		pthread_join(m_BizThreadId,&pthread_exit_result);
		m_pCommonLog->LogDebug("[%s][%s][%d] close thread end!", __FILE__ , __FUNCTION__, __LINE__);
		pthread_mutex_destroy(&m_BizThreadMutex);
	}
	m_pCommonLog->LogDebug("[%s][%s][%d] Disconnect finished!", __FILE__ , __FUNCTION__, __LINE__);
}

int CMobileScanPayCommonFunc::GetCommQuality()
{
	m_pCommonLog->LogDebug("[%s][%s][%d] GetCommQuality!", __FILE__ , __FUNCTION__, __LINE__);
	return m_bNetworkOK;
}

int CMobileScanPayCommonFunc::Init(const void * pParam)
{
	m_pCommonLog->LogDebug("[%s][%s][%d] Init!", __FILE__ , __FUNCTION__, __LINE__);
	//todo 用于初始化超时等参数？
	return COMMOM_FUNC_OK;
}

int CMobileScanPayCommonFunc::Reset(bool bResetFirmware, const void *pParam)
{
	m_pCommonLog->LogDebug("[%s][%s][%d] Reset!", __FILE__ , __FUNCTION__, __LINE__);
	return COMMOM_FUNC_OK;
}

int CMobileScanPayCommonFunc::GetDeviceStatus(void *pParam)
{
	//todo
	if(NULL == pParam)
		return COMMOM_FUNC_FAIL;
	memcpy(pParam,&m_stMobileScanStatus,sizeof(m_stMobileScanStatus));

	return COMMOM_FUNC_OK;
}

bool CMobileScanPayCommonFunc::paymentBegin(const void *pData)
{
	m_pCommonLog->LogDebug("[%s][%s][%d] paymentBegin!", __FILE__ , __FUNCTION__, __LINE__);
	//todo
	ST_ORDER_COMMIT_REQ stOrderCommitReq;
	memset(&stOrderCommitReq,0,sizeof(stOrderCommitReq));
	memset(&m_stOrderCommitRespData,0,sizeof(m_stOrderCommitRespData));

	ST_TVM_PASSENGER_TRANS * stTvmPassengerTrans = (ST_TVM_PASSENGER_TRANS * )pData;

	//支付通道编码
	if(EM_PAYMENT_SUB_METHOD_WECHAT == stTvmPassengerTrans->emPaySubMethod)
		sprintf(stOrderCommitReq.szPaymentVender,"1002");
	else if(EM_PAYMENT_SUB_METHOD_ALIPAY == stTvmPassengerTrans->emPaySubMethod)
		sprintf(stOrderCommitReq.szPaymentVender,"1001");
	else
	{
		m_pCommonLog->LogError("[%s][%s][%d] no such payment method [%d]!", __FILE__ , __FUNCTION__, __LINE__,stTvmPassengerTrans->emPaySubMethod);
		return false;
	}
	//起点站代码 todo 暂时写死
	sprintf(stOrderCommitReq.szPickupStationCode,"0101");

	if(0 != stTvmPassengerTrans->dwDesStationID)
	{
		sprintf(stOrderCommitReq.szGetoffStationCode,"%d",stTvmPassengerTrans->dwDesStationID);		//终点站代码
		sprintf(stOrderCommitReq.szSingleTicketType,"0");											//是否时站点购票
	}
	else
		sprintf(stOrderCommitReq.szSingleTicketType,"1");

	sprintf(stOrderCommitReq.szSingleTicketPrice,"%d",stTvmPassengerTrans->iUnitPrice);				//单程票票价
	sprintf(stOrderCommitReq.szSingleTicketNum,"%d",stTvmPassengerTrans->iCountFromPassenger);		//购买数量

	m_pCommonLog->LogDebug("[%s][%s][%d]stOrderCommitReq: 支付通道=%s ,起点站=%s ,终点站=%s ,单程票票价=%s ,购买数量=%s ,是否时站点购票=%s !", __FILE__ , __FUNCTION__, __LINE__,\
			stOrderCommitReq.szPaymentVender,stOrderCommitReq.szPickupStationCode,stOrderCommitReq.szGetoffStationCode,stOrderCommitReq.szSingleTicketPrice,\
			stOrderCommitReq.szSingleTicketNum,stOrderCommitReq.szSingleTicketType);

	//todo 5秒超时
	int i = 0,iRet = 99;
	for(;i < m_iTryTime; i++)
	{
		iRet = m_pQrCodePayAtomic->S001OrderCommit(&stOrderCommitReq,&m_stOrderCommitRespData);
		if(0 == iRet)
		{
			m_bOrderSend = true;
			m_pCommonLog->LogDebug("[%s][%s][%d]订单提交响应数据 : ParnorNo = %s ,OrderNo = %s , subject = %s, body = %s, payType = %s, amount = %s, account = %s, NotifyUrl = %s, merchantCert = %s, timeout = %d", __FILE__ , __FUNCTION__, __LINE__,\
					m_stOrderCommitRespData.szPartnerNo,m_stOrderCommitRespData.szOrderNo,m_stOrderCommitRespData.szSubject,m_stOrderCommitRespData.szBody,\
					m_stOrderCommitRespData.szPayType,m_stOrderCommitRespData.szAmount,m_stOrderCommitRespData.szAccount,m_stOrderCommitRespData.szNotifyUrl,\
					m_stOrderCommitRespData.szMerchantCert,m_stOrderCommitRespData.iTimeOut);
			break;
		}
		else
			m_pCommonLog->LogError("[%s][%s][%d]S001OrderCommit failed ,try [%d] time! iRet = %d", __FILE__ , __FUNCTION__, __LINE__,i + 1,iRet);
	}
	if(i == m_iTryTime)
	{
		m_bOrderSend = false;
		return false;
	}

	return true;
}

bool CMobileScanPayCommonFunc::confirmPayment(const void *pData)
{
	m_pCommonLog->LogDebug("[%s][%s][%d] confirmPayment!", __FILE__ , __FUNCTION__, __LINE__);

	memset(&m_stExecResultReq,0,sizeof(m_stExecResultReq));
	ST_TVM_PASSENGER_TRANS * stTvmPassengerTrans = (ST_TVM_PASSENGER_TRANS * )pData;

	strcpy(m_stExecResultReq.szOrderNo,m_stQRCodeRespData.szOrderNo);
	m_stExecResultReq.iTakeSingleTicketNum = stTvmPassengerTrans->iTransCount;
	sprintf(m_stExecResultReq.szTakeSingleTicketDate,"%s%s",stTvmPassengerTrans->szEndDate,stTvmPassengerTrans->szEndTime);

	m_pCommonLog->LogDebug("[%s][%s][%d] m_stExecResultReq: szOrderNo = %s, 乘客选择张数 = %d , 实际交易数量 = %d, 交易日期 = %s  !", __FILE__ , __FUNCTION__, __LINE__,
			m_stExecResultReq.szOrderNo,stTvmPassengerTrans->iCountFromPassenger,m_stExecResultReq.iTakeSingleTicketNum,m_stExecResultReq.szTakeSingleTicketDate);

	//todo 失败交易？
	if(stTvmPassengerTrans->iCountFromPassenger != stTvmPassengerTrans->iTransCount)
	{
		strcpy(m_stTransFaultReq.szOrderNo,stTvmPassengerTrans->szOrderNo);
		m_stTransFaultReq.iTakeSingleTicketNum = stTvmPassengerTrans->iTransCount;
		sprintf(m_stTransFaultReq.szFaultOccurDate,"%s%s",stTvmPassengerTrans->szEndDate,stTvmPassengerTrans->szEndTime);
		if(0 != stTvmPassengerTrans->iTransCount)
			m_stTransFaultReq.emErrorCode = EM_PART_TICKET_OUT_FAULT;
		else
			m_stTransFaultReq.emErrorCode = EM_ALL_TICKET_OUT_FAULT;
		sprintf(m_stTransFaultReq.szErrorMessage,"%s",m_szErrorInfo[m_stTransFaultReq.emErrorCode]);
		m_bFaultTrans = true;
		m_pCommonLog->LogDebug("[%s][%s][%d] 失败交易!", __FILE__ , __FUNCTION__, __LINE__);
	}
	else
		m_bFaultTrans = false;
	m_bConfirmTrans = true;

	return true;
}

bool CMobileScanPayCommonFunc::cancelPayment(const void *pData)
{
	m_pCommonLog->LogDebug("[%s][%s][%d] cancelPayment!", __FILE__ , __FUNCTION__, __LINE__);
	m_bOrderSend = false;
	m_bCreateQRCodeOk = false;
	m_bConfirmTrans = false;

	memset(&m_stTransFaultReq,0,sizeof(m_stTransFaultReq));
	ST_TVM_PASSENGER_TRANS * stTvmPassengerTrans = (ST_TVM_PASSENGER_TRANS * )pData;
	strcpy(m_stTransFaultReq.szOrderNo,stTvmPassengerTrans->szOrderNo);
	m_stTransFaultReq.iTakeSingleTicketNum = stTvmPassengerTrans->iTransCount;
	sprintf(m_stTransFaultReq.szFaultOccurDate,"%s%s",stTvmPassengerTrans->szEndDate,stTvmPassengerTrans->szEndTime);
	m_stTransFaultReq.emErrorCode = EM_ORDER_CANCEL;
	sprintf(m_stTransFaultReq.szErrorMessage,"%s",m_szErrorInfo[EM_ORDER_CANCEL]);

	m_bCancelTrans = true;

	return true;
}


bool CMobileScanPayCommonFunc::RegEventHandler(CIWebPayEvenHandler * pcCashEventHandler )
{
	m_pHandler = pcCashEventHandler;
	return true;
}

CIWebPayEvenHandler *CMobileScanPayCommonFunc::GetEventHandler()
{
	return m_pHandler;
}

//业务线程
void *CMobileScanPayCommonFunc::BizThread(void *arg)
{
	CMobileScanPayCommonFunc * pMobileScanComm = (CMobileScanPayCommonFunc *)arg;
	pMobileScanComm->m_pCommonLog->LogDebug("[%s][%s][%d] BizThread!", __FILE__ , __FUNCTION__, __LINE__);
	int iRet = 9999;
	int iTimeout = 0;
	//todo
	while(pMobileScanComm->m_bThread)
	{
		//1、已提交订单成功，执行支付链接请求
		if(pMobileScanComm->m_bOrderSend)
		{
			pMobileScanComm->m_pCommonLog->LogDebug("[%s][%s][%d] 已提交订单成功，执行支付链接请求!", __FILE__ , __FUNCTION__, __LINE__);
			pthread_mutex_lock(&pMobileScanComm->m_BizThreadMutex);
			int i = 0;
			for(;i < pMobileScanComm->m_iTryTime; i++)
			{
				iRet = pMobileScanComm->m_pQrCodePayAtomic->S018SnapQRCodePrePayURLQuery(pMobileScanComm->m_stOrderCommitRespData.szOrderNo,&pMobileScanComm->m_stQRCodeRespData);
				if(EM_OPERATION_SUCCESS == iRet)
				{
					if(0 != strcmp(pMobileScanComm->m_stOrderCommitRespData.szOrderNo,pMobileScanComm->m_stQRCodeRespData.szOrderNo))
					{
						pMobileScanComm->m_pCommonLog->LogError("[%s][%s][%d] 唯一订单号不一致! [%s]  != [%s]", __FILE__ , __FUNCTION__, __LINE__,\
								pMobileScanComm->m_stOrderCommitRespData.szOrderNo,pMobileScanComm->m_stQRCodeRespData.szOrderNo);
						//todo
						pMobileScanComm->m_pHandler->FailtureNotify(NULL);
					}
					pMobileScanComm->m_pCommonLog->LogDebug("[%s][%s][%d] 唯一订单号一致!", __FILE__ , __FUNCTION__, __LINE__);

					if(pMobileScanComm->m_pHandler != NULL)
					{
						//todo
						if(0 == strlen(pMobileScanComm->m_stQRCodeRespData.szQrCode))
						{
							strcpy(pMobileScanComm->m_stQRCodeRespData.szQrCode,"假装在支付。。。");
						}
						pMobileScanComm->m_pHandler->QRCodeDataNotify((const void*)pMobileScanComm->m_stQRCodeRespData.szQrCode);
					}
					else
						pMobileScanComm->m_pCommonLog->LogError("[%s][%s][%d] m_pHandler == NULL!", __FILE__ , __FUNCTION__, __LINE__);

					pMobileScanComm->m_bOrderSend = false;
					pMobileScanComm->m_bCreateQRCodeOk = true;
					memset(&pMobileScanComm->m_stPayResultReq,0,sizeof(pMobileScanComm->m_stPayResultReq));
					strcpy(pMobileScanComm->m_stPayResultReq.szOrderNo,pMobileScanComm->m_stQRCodeRespData.szOrderNo);
					strcpy(pMobileScanComm->m_stPayResultReq.szQrCode,pMobileScanComm->m_stQRCodeRespData.szQrCode);
					break;
				}
				else
				{
					if(!pMobileScanComm->ExecFailedResultAnalyse(iRet))
					{
						//todo 直接执行故障通知
						pMobileScanComm->m_pCommonLog->LogDebug("[%s][%s][%d] m_bOrderSend!", __FILE__ , __FUNCTION__, __LINE__);
						pMobileScanComm->m_pHandler->FailtureNotify(NULL);
						pMobileScanComm->m_bOrderSend = false;
						break;
					}
				}
				//todo  timeout
				if(pMobileScanComm->m_bOrderSend)
					sleep(1);
			}
			if(i != pMobileScanComm->m_iTryTime)
				pMobileScanComm->m_pCommonLog->LogDebug("[%s][%s][%d] 获取二维码成功!", __FILE__ , __FUNCTION__, __LINE__);
			pthread_mutex_unlock(&pMobileScanComm->m_BizThreadMutex);
		}
		//2、已生成二维码，轮寻支付结果
		if(pMobileScanComm->m_bCreateQRCodeOk)
		{
			pthread_mutex_lock(&pMobileScanComm->m_BizThreadMutex);
			iRet = pMobileScanComm->m_pQrCodePayAtomic->S019SnapQRCodePayResultQuery(&pMobileScanComm->m_stPayResultReq,&pMobileScanComm->m_stPayResultData);
			if(EM_OPERATION_SUCCESS == iRet)
			{
				//todo 返回数据
				pMobileScanComm->m_pHandler->PaymentNotify((const void *)&pMobileScanComm->m_stPayResultData);
				pMobileScanComm->m_bCreateQRCodeOk = false;
			}
			else
			{
				if(!pMobileScanComm->ExecFailedResultAnalyse(iRet) || iTimeout >= 60)
				{
					if(iTimeout >= 60)
						pMobileScanComm->m_pCommonLog->LogDebug("[%s][%s][%d] 等待支付超时!", __FILE__ , __FUNCTION__, __LINE__);
					//todo 直接执行故障通知
					pMobileScanComm->m_pHandler->FailtureNotify(NULL);
					pMobileScanComm->m_bCreateQRCodeOk = false;
				}
			}
			if(pMobileScanComm->m_bCreateQRCodeOk)
			{
				iTimeout ++;
				sleep(1);
			}
			else
				iTimeout = 0;
			pthread_mutex_unlock(&pMobileScanComm->m_BizThreadMutex);
		}
		//3、确认交易(正常交易) todo 是否是结束交易,上传不成功需要等网络好了补传
		if(pMobileScanComm->m_bConfirmTrans && !pMobileScanComm->m_bFaultTrans)
		{
			pMobileScanComm->m_pCommonLog->LogDebug("[%s][%s][%d] m_bConfirmTrans = %d, m_bFaultTrans = %d!", __FILE__ , __FUNCTION__, __LINE__,\
					pMobileScanComm->m_bConfirmTrans,pMobileScanComm->m_bFaultTrans);
			pthread_mutex_lock(&pMobileScanComm->m_BizThreadMutex);
			int i = 0;
			for(;i < pMobileScanComm->m_iTryTime; i++)
			{
				iRet = pMobileScanComm->m_pQrCodePayAtomic->S004OrderExecuteResult(&pMobileScanComm->m_stExecResultReq);
				if(EM_OPERATION_SUCCESS == iRet)
				{
					pMobileScanComm->m_pCommonLog->LogDebug("[%s][%s][%d] 确认交易成功!", __FILE__ , __FUNCTION__, __LINE__);
					pMobileScanComm->m_bConfirmTrans = false;
					pMobileScanComm->m_bFaultTrans = false;
				}
				else
				{
					if(!pMobileScanComm->ExecFailedResultAnalyse(iRet))
					{
						//todo 直接执行故障通知
						pMobileScanComm->m_pCommonLog->LogDebug("[%s][%s][%d] 确认交易(正常交易)!", __FILE__ , __FUNCTION__, __LINE__);
						pMobileScanComm->m_pHandler->FailtureNotify(NULL);
						pMobileScanComm->m_bConfirmTrans = false;
						pMobileScanComm->m_bCreateQRCodeOk = false;
						break;
					}
				}
			}
			pthread_mutex_unlock(&pMobileScanComm->m_BizThreadMutex);
			//todo 请求次数？
		}
		//4、确认交易(故障交易) todo 是否是结束交易,上传不成功需要等网络好了补传
		//5、取消交易  上传不成功需要等网络好了补传
		if(pMobileScanComm->m_bCancelTrans || (pMobileScanComm->m_bConfirmTrans && pMobileScanComm->m_bFaultTrans))
		{
			pMobileScanComm->m_pCommonLog->LogDebug("[%s][%s][%d] m_bCancelTrans = %d , m_bConfirmTrans = %d, m_bFaultTrans = %d!", __FILE__ , __FUNCTION__, __LINE__,\
					pMobileScanComm->m_bCancelTrans,pMobileScanComm->m_bConfirmTrans,pMobileScanComm->m_bFaultTrans);
			pthread_mutex_lock(&pMobileScanComm->m_BizThreadMutex);
			int i = 0;
			for(;i < pMobileScanComm->m_iTryTime; i++)
			{
				iRet = pMobileScanComm->m_pQrCodePayAtomic->S005OrderExecuteFault(&pMobileScanComm->m_stTransFaultReq);
				if(EM_OPERATION_SUCCESS == iRet)
				{
					if(pMobileScanComm->m_bCancelTrans )
					{
						pMobileScanComm->m_pCommonLog->LogDebug("[%s][%s][%d] 取消交易处理成功!", __FILE__ , __FUNCTION__, __LINE__);
						pMobileScanComm->m_bCancelTrans = false;
					}
					else
					{
						pMobileScanComm->m_pCommonLog->LogDebug("[%s][%s][%d] 故障交易处理成功!", __FILE__ , __FUNCTION__, __LINE__);
						pMobileScanComm->m_bConfirmTrans = false;
						pMobileScanComm->m_bFaultTrans = false;
					}

					break;
				}
				else
				{
					if(!pMobileScanComm->ExecFailedResultAnalyse(iRet))
					{
						//todo 直接执行故障通知
						if(pMobileScanComm->m_bCancelTrans )
						{
							pMobileScanComm->m_pCommonLog->LogDebug("[%s][%s][%d] 取消交易 失败!", __FILE__ , __FUNCTION__, __LINE__);
							pMobileScanComm->m_bCancelTrans = false;
						}
						else
						{
							pMobileScanComm->m_pCommonLog->LogDebug("[%s][%s][%d] 确认交易(故障交易) 失败!", __FILE__ , __FUNCTION__, __LINE__);
							pMobileScanComm->m_bConfirmTrans = false;
							pMobileScanComm->m_bFaultTrans = false;
						}
						pMobileScanComm->m_pHandler->FailtureNotify(NULL);
						pMobileScanComm->m_bCreateQRCodeOk = false;
						break;
					}
				}
			}
			pthread_mutex_unlock(&pMobileScanComm->m_BizThreadMutex);
			usleep(200);
		}

	}
	pMobileScanComm->m_bExitThread = true;
	return NULL;
}

void CMobileScanPayCommonFunc::AddErrorCode(int iErrorCode)
{
	if(m_stMobileScanStatus.iErrorCodeNumber < 5)
	{
		m_stMobileScanStatus.stErrorCode[m_stMobileScanStatus.iErrorCodeNumber].iErrorCode = iErrorCode;
	}
}

void CMobileScanPayCommonFunc::AddErrorCode(int iErrorCode,const char* pszErrorInfo)
{
	if(m_stMobileScanStatus.iErrorCodeNumber < 5)
	{
		m_stMobileScanStatus.stErrorCode[m_stMobileScanStatus.iErrorCodeNumber].iErrorCode = iErrorCode;
		memcpy(m_stMobileScanStatus.stErrorCode[m_stMobileScanStatus.iErrorCodeNumber].czAdditionalInfo,pszErrorInfo,16);
	}
}

bool CMobileScanPayCommonFunc::ExecFailedResultAnalyse(int iRet)
{
	static int iOldRet = 0;
	if(iOldRet != iRet)
	{
		iOldRet = iRet;
		switch(iRet)
		{
		case EM_PARA_ERROR:
			m_pCommonLog->LogDebug("[%s][%s][%d] iRet=%d, 参数错误,直接执行S1-005订单执行故障!", __FILE__ , __FUNCTION__, __LINE__,iRet);
			return false;
		case EM_PAYMENT_ERROR:
			m_pCommonLog->LogDebug("[%s][%s][%d] iRet=%d, 支付失败,直接执行S1-005订单执行故障!", __FILE__ , __FUNCTION__, __LINE__,iRet);
			return false;
		case EM_ORDER_CODE_ERROR:
			m_pCommonLog->LogDebug("[%s][%s][%d] iRet=%d, 订单号码错误,直接执行S1-005订单执行故障!", __FILE__ , __FUNCTION__, __LINE__,iRet);
			return false;
		case EM_TOKEN_ERROR:
			m_pCommonLog->LogDebug("[%s][%s][%d] iRet=%d, Token错误,直接执行S1-005订单执行故障!", __FILE__ , __FUNCTION__, __LINE__,iRet);
			return false;
		case EM_ILLEGAL_DEVICE:
			m_pCommonLog->LogDebug("[%s][%s][%d] iRet=%d, 非法设备编码,直接执行S1-005订单执行故障!", __FILE__ , __FUNCTION__, __LINE__,iRet);
			return false;
		case EM_NO_ORDER_PAYMENT:
			m_pCommonLog->LogDebug("[%s][%s][%d] iRet=%d, 订单未支付,直接执行S1-005订单执行故障!", __FILE__ , __FUNCTION__, __LINE__,iRet);
			return false;
		case EM_TICKET_TAKEN:
			m_pCommonLog->LogDebug("[%s][%s][%d] iRet=%d, 订单已取票,直接执行S1-005订单执行故障!", __FILE__ , __FUNCTION__, __LINE__,iRet);
			return false;
		case EM_ORDER_LOCKED:
			m_pCommonLog->LogDebug("[%s][%s][%d] iRet=%d, 订单锁定,直接执行S1-005订单执行故障!", __FILE__ , __FUNCTION__, __LINE__,iRet);
			return false;
		case EM_ORDER_REFUND:
			m_pCommonLog->LogDebug("[%s][%s][%d] iRet=%d, 订单已退款,直接执行S1-005订单执行故障!", __FILE__ , __FUNCTION__, __LINE__,iRet);
			return false;
		case EM_SYSTEM_ERROR:
			m_pCommonLog->LogDebug("[%s][%s][%d] iRet=%d, 系统错误,直接执行S1-005订单执行故障!", __FILE__ , __FUNCTION__, __LINE__,iRet);
			return false;
		default:
			m_pCommonLog->LogDebug("[%s][%s][%d] 未知 iRet = %d!", __FILE__ , __FUNCTION__, __LINE__,iRet);
			return true;
		}
	}
	return true;
}

int CMobileScanPayCommonFunc::GetVersion(EM_SLE_UNIT_TYPE emUnitType, list<ST_CSS_VERSION_INFO> * pstVersionInfoList)
{
	return COMMOM_FUNC_UNSUPP;
}

int CMobileScanPayCommonFunc::GetParam(void * pParam)
{
	return COMMOM_FUNC_UNSUPP;
}

int CMobileScanPayCommonFunc::SetParam(const void * pParam)
{
	return COMMOM_FUNC_UNSUPP;
}

int CMobileScanPayCommonFunc::GetLogData(int iLogType, unsigned char *pszBuffer, int iBuffer)
{
	return COMMOM_FUNC_UNSUPP;
}

int CMobileScanPayCommonFunc::ClearLogData(int iLogType)
{
	return COMMOM_FUNC_UNSUPP;
}

int CMobileScanPayCommonFunc::SetMaintainMode(bool set)
{
	return COMMOM_FUNC_UNSUPP;
}

int CMobileScanPayCommonFunc::SetTestMode(bool set)
{
	return COMMOM_FUNC_UNSUPP;
}

int CMobileScanPayCommonFunc::StepTest(int iTestItem, const unsigned char *pszTestParam)
{
	return COMMOM_FUNC_UNSUPP;
}
int CMobileScanPayCommonFunc::TestSensorStatus(unsigned char *pszStatus, int *piSensorNum)
{
	return COMMOM_FUNC_UNSUPP;
}
int CMobileScanPayCommonFunc::UpdateFireWare(const char *szPortName, int iBaud, int iDataBits, char cParity,
			int iStopBits, const char *szFileName, int iBlockSize, IProgressReport *pcProgressReport)
{
	return COMMOM_FUNC_UNSUPP;
}

