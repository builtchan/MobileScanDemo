/*
 * CQRCPay.cpp
 *
 *  Created on: 2017-4-11
 *      Author: root
 */

#include "SLEWebServiceSoap.nsmap"
//#include "SLEWebServiceSoap12.nsmap"
#include "CQRCPay.h"

CQRCPay::CQRCPay(CLogOper2 * pLog) {
	// TODO Auto-generated constructor stub
	cSLEWebServiceSoapProxy = new SLEWebServiceSoapProxy();
	m_pLog = pLog;
}

CQRCPay::~CQRCPay() {
	// TODO Auto-generated destructor stub
}

int CQRCPay::S001OrderCommit(ST_ORDER_COMMIT_REQ *pstOrderCommitReq, ST_ORDER_COMMIT_RESP *pstOrderCommitResp)
{
	int iRet = 9999;
	ST_REQ_BASE stReqBase;
	memset(&stReqBase, 0, sizeof(stReqBase));
	PackHeadReq(&stReqBase);

	ns1__OrderCommitReq cns1__OrderCommitReq;

	cns1__OrderCommitReq.reqSysDate = strdup(stReqBase.szReqSysDate);
	cns1__OrderCommitReq.operationCode = strdup(stReqBase.szOperationCode);
	cns1__OrderCommitReq.cityCode = strdup(stReqBase.szCityCode);
	cns1__OrderCommitReq.deviceId = strdup(stReqBase.szDeviceId);
	cns1__OrderCommitReq.channelType = strdup(stReqBase.szChannelType);

	char szPaymentCode[64] = {0};
	cns1__OrderCommitReq.paymentCode = strdup(szPaymentCode);
	cns1__OrderCommitReq.paymentVendor = strdup(pstOrderCommitReq->szPaymentVender);
	cns1__OrderCommitReq.pickupStationCode = strdup(pstOrderCommitReq->szPickupStationCode);
	cns1__OrderCommitReq.getOffStationCode = strdup(pstOrderCommitReq->szGetoffStationCode);
	cns1__OrderCommitReq.singleTicketPrice = strdup(pstOrderCommitReq->szSingleTicketPrice);
	cns1__OrderCommitReq.singleTicketNum = strdup(pstOrderCommitReq->szSingleTicketNum);
	cns1__OrderCommitReq.singleTicketType = strdup(pstOrderCommitReq->szSingleTicketType);

	m_pLog->LogDebug("[%s][%s][%d] reqSysDate 	  = %s", __FILE__ , __FUNCTION__, __LINE__,cns1__OrderCommitReq.reqSysDate);
	m_pLog->LogDebug("[%s][%s][%d] operationCode  = %s", __FILE__ , __FUNCTION__, __LINE__,cns1__OrderCommitReq.operationCode);
	m_pLog->LogDebug("[%s][%s][%d] cityCode 	  = %s", __FILE__ , __FUNCTION__, __LINE__,cns1__OrderCommitReq.cityCode);
	m_pLog->LogDebug("[%s][%s][%d] deviceId 	  = %s", __FILE__ , __FUNCTION__, __LINE__,cns1__OrderCommitReq.deviceId);
	m_pLog->LogDebug("[%s][%s][%d] channelType 	  = %s", __FILE__ , __FUNCTION__, __LINE__,cns1__OrderCommitReq.channelType);

	m_pLog->LogDebug("[%s][%s][%d] paymentVendor 	    = %s", __FILE__ , __FUNCTION__, __LINE__,cns1__OrderCommitReq.paymentVendor);
	m_pLog->LogDebug("[%s][%s][%d] pickupStationCode 	= %s", __FILE__ , __FUNCTION__, __LINE__,cns1__OrderCommitReq.pickupStationCode);
	m_pLog->LogDebug("[%s][%s][%d] getOffStationCode 	= %s", __FILE__ , __FUNCTION__, __LINE__,cns1__OrderCommitReq.getOffStationCode);
	m_pLog->LogDebug("[%s][%s][%d] singleTicketPrice 	= %s", __FILE__ , __FUNCTION__, __LINE__,cns1__OrderCommitReq.singleTicketPrice);
	m_pLog->LogDebug("[%s][%s][%d] singleTicketNum 	    = %s", __FILE__ , __FUNCTION__, __LINE__,cns1__OrderCommitReq.singleTicketNum);
	m_pLog->LogDebug("[%s][%s][%d] singleTicketType 	= %s", __FILE__ , __FUNCTION__, __LINE__,cns1__OrderCommitReq.singleTicketType);

	_ns1__S1_USCORE001 ns1__S1_USCORE001;
	_ns1__S1_USCORE001Response ns1__S1_USCORE001Response;

	ns1__S1_USCORE001.orderCommitReq = &cns1__OrderCommitReq;

	cSLEWebServiceSoapProxy->S1_USCORE001(&ns1__S1_USCORE001, &ns1__S1_USCORE001Response);

	char szResult[5] = {0};
	memcpy(szResult, ns1__S1_USCORE001Response.S1_USCORE001Result->respCode, 4);
	iRet = atoi(szResult);

	if(iRet == 0)
	{
		memcpy(pstOrderCommitResp->szPartnerNo, ns1__S1_USCORE001Response.S1_USCORE001Result->partnerNo, 3);
		memcpy(pstOrderCommitResp->szOrderNo, ns1__S1_USCORE001Response.S1_USCORE001Result->orderNo, 30);
		memcpy(pstOrderCommitResp->szSubject, ns1__S1_USCORE001Response.S1_USCORE001Result->subject, 255);
		memcpy(pstOrderCommitResp->szBody, ns1__S1_USCORE001Response.S1_USCORE001Result->body, 255);
		memcpy(pstOrderCommitResp->szPayType, ns1__S1_USCORE001Response.S1_USCORE001Result->payType, 4);
		memcpy(pstOrderCommitResp->szAmount, ns1__S1_USCORE001Response.S1_USCORE001Result->amount, 6);
		memcpy(pstOrderCommitResp->szAccount, ns1__S1_USCORE001Response.S1_USCORE001Result->account, 32);
		memcpy(pstOrderCommitResp->szNotifyUrl, ns1__S1_USCORE001Response.S1_USCORE001Result->notifyUrl, 255);
		memcpy(pstOrderCommitResp->szMerchantCert, ns1__S1_USCORE001Response.S1_USCORE001Result->merchantCert, 128);
		pstOrderCommitResp->iTimeOut = ns1__S1_USCORE001Response.S1_USCORE001Result->timeout;
	}

	return iRet;
}

int CQRCPay::S004OrderExecuteResult(ST_ORDER_EXECUTE_RESULT_REQ *pstOrderExecuteResultReq)
{
	int iRet = 9999;
	ST_REQ_BASE stReqBase;
	memset(&stReqBase, 0, sizeof(stReqBase));
	PackHeadReq(&stReqBase);

	ns1__OrderExecuteResultReq cns1__OrderExecuteResultReq;

	cns1__OrderExecuteResultReq.reqSysDate = strdup(stReqBase.szReqSysDate);
	cns1__OrderExecuteResultReq.operationCode = strdup(stReqBase.szOperationCode);
	cns1__OrderExecuteResultReq.cityCode = strdup(stReqBase.szCityCode);
	cns1__OrderExecuteResultReq.deviceId = strdup(stReqBase.szDeviceId);
	cns1__OrderExecuteResultReq.channelType = strdup(stReqBase.szChannelType);

	cns1__OrderExecuteResultReq.orderNo = strdup(pstOrderExecuteResultReq->szOrderNo);
	cns1__OrderExecuteResultReq.takeSingleTicketNum = pstOrderExecuteResultReq->iTakeSingleTicketNum;
	cns1__OrderExecuteResultReq.takeSingleTicketDate = strdup(pstOrderExecuteResultReq->szTakeSingleTicketDate);

	_ns1__S1_USCORE004 ns1__S1_USCORE004;
	_ns1__S1_USCORE004Response ns1__S1_USCORE004Response;

	ns1__S1_USCORE004.orderExecuteResultReq = &cns1__OrderExecuteResultReq;

	cSLEWebServiceSoapProxy->S1_USCORE004(&ns1__S1_USCORE004, &ns1__S1_USCORE004Response);

	char szResult[5] = {0};
	memcpy(szResult, ns1__S1_USCORE004Response.S1_USCORE004Result->respCode, 4);
	iRet = atoi(szResult);

	return iRet;
}

int CQRCPay::S005OrderExecuteFault(ST_ORDER_EXECUTE_FAULT_REQ *pstOrderExecuteFaultReq)
{
	int iRet = 9999;
	ST_REQ_BASE stReqBase;
	memset(&stReqBase, 0, sizeof(stReqBase));
	PackHeadReq(&stReqBase);

	ns1__OrderExecuteFaultReq cns1__OrderExecuteFaultReq;

	cns1__OrderExecuteFaultReq.reqSysDate = strdup(stReqBase.szReqSysDate);
	cns1__OrderExecuteFaultReq.operationCode = strdup(stReqBase.szOperationCode);
	cns1__OrderExecuteFaultReq.cityCode = strdup(stReqBase.szCityCode);
	cns1__OrderExecuteFaultReq.deviceId = strdup(stReqBase.szDeviceId);
	cns1__OrderExecuteFaultReq.channelType = strdup(stReqBase.szChannelType);

	cns1__OrderExecuteFaultReq.orderNo = strdup(pstOrderExecuteFaultReq->szOrderNo);
	cns1__OrderExecuteFaultReq.takeSingleTicketNum = pstOrderExecuteFaultReq->iTakeSingleTicketNum;
	cns1__OrderExecuteFaultReq.faultOccurDate = strdup(pstOrderExecuteFaultReq->szFaultOccurDate);
	cns1__OrderExecuteFaultReq.faultSlipSeq = strdup(pstOrderExecuteFaultReq->szFaultSlipSeq);
	char szErrorCode[5] = {0};
	sprintf(szErrorCode, "%04d", pstOrderExecuteFaultReq->emErrorCode);
	cns1__OrderExecuteFaultReq.faultSlipSeq = strdup(szErrorCode);
	cns1__OrderExecuteFaultReq.errorMessage = strdup(pstOrderExecuteFaultReq->szErrorMessage);

	_ns1__S1_USCORE005 ns1__S1_USCORE005;
	_ns1__S1_USCORE005Response ns1__S1_USCORE005Response;

	ns1__S1_USCORE005.orderExecuteFaultReq = &cns1__OrderExecuteFaultReq;

	cSLEWebServiceSoapProxy->S1_USCORE005(&ns1__S1_USCORE005, &ns1__S1_USCORE005Response);

	char szResult[5] = {0};
	memcpy(szResult, ns1__S1_USCORE005Response.S1_USCORE005Result->respCode, 4);
	iRet = atoi(szResult);

	return iRet;
}

int CQRCPay::S009HeartBeat()
{
	int iRet = 9999;
	ST_REQ_BASE stReqBase;
	memset(&stReqBase, 0, sizeof(stReqBase));
	PackHeadReq(&stReqBase);

	ns1__HeartBeatReq cns1__HeartBeatReq;

	cns1__HeartBeatReq.reqSysDate = strdup(stReqBase.szReqSysDate);
	cns1__HeartBeatReq.operationCode = strdup(stReqBase.szOperationCode);
	cns1__HeartBeatReq.cityCode = strdup(stReqBase.szCityCode);
	cns1__HeartBeatReq.deviceId = strdup(stReqBase.szDeviceId);
	cns1__HeartBeatReq.channelType = strdup(stReqBase.szChannelType);

	m_pLog->LogDebug("[%s][%s][%d] reqSysDate 		= %s", __FILE__ , __FUNCTION__, __LINE__,cns1__HeartBeatReq.reqSysDate);
	m_pLog->LogDebug("[%s][%s][%d] operationCode  	= %s", __FILE__ , __FUNCTION__, __LINE__,cns1__HeartBeatReq.operationCode);
	m_pLog->LogDebug("[%s][%s][%d] cityCode 	 	= %s", __FILE__ , __FUNCTION__, __LINE__,cns1__HeartBeatReq.cityCode);
	m_pLog->LogDebug("[%s][%s][%d] deviceId 		= %s", __FILE__ , __FUNCTION__, __LINE__,cns1__HeartBeatReq.deviceId);
	m_pLog->LogDebug("[%s][%s][%d] channelType 		= %s", __FILE__ , __FUNCTION__, __LINE__,cns1__HeartBeatReq.channelType);

	_ns1__S1_USCORE009 ns1__S1_USCORE009;
	_ns1__S1_USCORE009Response ns1__S1_USCORE009Response;

	ns1__S1_USCORE009.heartBeatReq = &cns1__HeartBeatReq;

	cSLEWebServiceSoapProxy->S1_USCORE009(&ns1__S1_USCORE009, &ns1__S1_USCORE009Response);

	char szResult[5] = {0};
	memcpy(szResult, ns1__S1_USCORE009Response.S1_USCORE009Result->respCode, 4);

	iRet = atoi(szResult);

	return iRet;
}

int CQRCPay::S018SnapQRCodePrePayURLQuery(char *szOrderNo, ST_SNAP_QRCODE_PREPAY_URL_QUERY_RESP *pstSnapQRCodePrePayURLQueryResp)
{
	int iRet = 9999;
	ST_REQ_BASE stReqBase;
	memset(&stReqBase, 0, sizeof(stReqBase));
	PackHeadReq(&stReqBase);

	ns1__SnapQRCodePrePayURLQueryReq cns1__SnapQRCodePrePayURLQueryReq;

	cns1__SnapQRCodePrePayURLQueryReq.reqSysDate = strdup(stReqBase.szReqSysDate);
	cns1__SnapQRCodePrePayURLQueryReq.operationCode = strdup(stReqBase.szOperationCode);
	cns1__SnapQRCodePrePayURLQueryReq.cityCode = strdup(stReqBase.szCityCode);
	cns1__SnapQRCodePrePayURLQueryReq.deviceId = strdup(stReqBase.szDeviceId);
	cns1__SnapQRCodePrePayURLQueryReq.channelType = strdup(stReqBase.szChannelType);

	cns1__SnapQRCodePrePayURLQueryReq.orderNo = strdup(szOrderNo);

	_ns1__S1_USCORE018 ns1__S1_USCORE018;
	_ns1__S1_USCORE018Response ns1__S1_USCORE018Response;

	ns1__S1_USCORE018.snapQRCodePrePayURLQueryReq = &cns1__SnapQRCodePrePayURLQueryReq;

	cSLEWebServiceSoapProxy->S1_USCORE018(&ns1__S1_USCORE018, &ns1__S1_USCORE018Response);

	char szResult[5] = {0};
	memcpy(szResult, ns1__S1_USCORE018Response.S1_USCORE018Result->respCode, 4);
	iRet = atoi(szResult);

	if(iRet == 0)
	{
		memcpy(pstSnapQRCodePrePayURLQueryResp->szOrderNo, ns1__S1_USCORE018Response.S1_USCORE018Result->orderNo, 30);
		memcpy(pstSnapQRCodePrePayURLQueryResp->szDeviceId, ns1__S1_USCORE018Response.S1_USCORE018Result->deviceId, 10);
		memcpy(pstSnapQRCodePrePayURLQueryResp->szQrCode, ns1__S1_USCORE018Response.S1_USCORE018Result->qrCode, 1024);
	}

	return iRet;
}

int CQRCPay::S019SnapQRCodePayResultQuery(ST_SNAP_QRCODE_PAY_RESULT_REQ *pstSnapQRCodePayResultQueryReq, ST_SNAP_QRCODE_PAY_RESULT_RESP *pstSnapQRCodePayResultQueryResp)
{
	int iRet = 9999;
	ST_REQ_BASE stReqBase;
	memset(&stReqBase, 0, sizeof(stReqBase));
	PackHeadReq(&stReqBase);

	ns1__SnapQRCodePayResultQueryReq cns1__SnapQRCodePayResultQueryReq;

	cns1__SnapQRCodePayResultQueryReq.reqSysDate = strdup(stReqBase.szReqSysDate);
	cns1__SnapQRCodePayResultQueryReq.operationCode = strdup(stReqBase.szOperationCode);
	cns1__SnapQRCodePayResultQueryReq.cityCode = strdup(stReqBase.szCityCode);
	cns1__SnapQRCodePayResultQueryReq.deviceId = strdup(stReqBase.szDeviceId);
	cns1__SnapQRCodePayResultQueryReq.channelType = strdup(stReqBase.szChannelType);

	cns1__SnapQRCodePayResultQueryReq.orderNo = strdup(pstSnapQRCodePayResultQueryReq->szOrderNo);
	cns1__SnapQRCodePayResultQueryReq.qrCode = strdup(pstSnapQRCodePayResultQueryReq->szQrCode);

	_ns1__S1_USCORE019 ns1__S1_USCORE019;
	_ns1__S1_USCORE019Response ns1__S1_USCORE019Response;

	ns1__S1_USCORE019.snapQRCodePayResultQueryReq = &cns1__SnapQRCodePayResultQueryReq;

	cSLEWebServiceSoapProxy->S1_USCORE019(&ns1__S1_USCORE019, &ns1__S1_USCORE019Response);

	char szResult[5] = {0};
	memcpy(szResult, ns1__S1_USCORE019Response.S1_USCORE019Result->respCode, 4);
	iRet = atoi(szResult);

	if(iRet == 0)
	{
		memcpy(pstSnapQRCodePayResultQueryResp->szOrderNo, ns1__S1_USCORE019Response.S1_USCORE019Result->orderNo, 30);
		memcpy(pstSnapQRCodePayResultQueryResp->szPaymentDate, ns1__S1_USCORE019Response.S1_USCORE019Result->orderNo, 14);
		memcpy(pstSnapQRCodePayResultQueryResp->szAmount, ns1__S1_USCORE019Response.S1_USCORE019Result->orderNo, 32);
		memcpy(pstSnapQRCodePayResultQueryResp->szPaymentAccount, ns1__S1_USCORE019Response.S1_USCORE019Result->orderNo, 128);
		memcpy(pstSnapQRCodePayResultQueryResp->szPaymentResult, ns1__S1_USCORE019Response.S1_USCORE019Result->orderNo, 16);
		memcpy(pstSnapQRCodePayResultQueryResp->szPaymentDesc, ns1__S1_USCORE019Response.S1_USCORE019Result->orderNo, 255);
		memcpy(pstSnapQRCodePayResultQueryResp->szUserName, ns1__S1_USCORE019Response.S1_USCORE019Result->orderNo, 100);
	}

	return iRet;
}

int CQRCPay::PackHeadReq(ST_REQ_BASE *pstReqBase)
{
	time_t timer;
	struct tm* t_tm;
	time(&timer);
	t_tm = localtime(&timer);
	sprintf(pstReqBase->szReqSysDate,"%4d%02d%02d%02d%02d%02d", t_tm->tm_year+1900,
	t_tm->tm_mon+1, t_tm->tm_mday, t_tm->tm_hour, t_tm->tm_min, t_tm->tm_sec);

//	pstReqBase->szReqSysDate[sizeof(pstReqBase->szReqSysDate)] = '\0';
//
//	strcpy(pstReqBase->szOperationCode,"01025004");
//	pstReqBase->szOperationCode[sizeof(pstReqBase->szOperationCode)] = '\0';
//	strcpy(pstReqBase->szCityCode,"0102");
//	pstReqBase->szCityCode[sizeof(pstReqBase->szCityCode)] = '\0';
//	strcpy(pstReqBase->szDeviceId,"0101020001");
//	pstReqBase->szDeviceId[sizeof(pstReqBase->szDeviceId)] = '\0';
//	strcpy(pstReqBase->szChannelType,"01");
//	pstReqBase->szChannelType[sizeof(pstReqBase->szChannelType) ] = '\0';

	sprintf(pstReqBase->szOperationCode,"010250");
	sprintf(pstReqBase->szCityCode,"0102");
	sprintf(pstReqBase->szDeviceId,"0101020001");
	sprintf(pstReqBase->szChannelType,"01");

	return 0;
}
