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

//	sprintf(stReqBase.szReqSysDate,"20161031084245");
	sprintf(stReqBase.szOperationCode,"S1-001");
//	sprintf(stReqBase.szCityCode,"020");
//	sprintf(stReqBase.szDeviceId,"0501020004");
//	sprintf(stReqBase.szChannelType,"01");

	cns1__OrderCommitReq.reqSysDate = strdup(stReqBase.szReqSysDate);
	cns1__OrderCommitReq.operationCode = strdup(stReqBase.szOperationCode);
	cns1__OrderCommitReq.cityCode = strdup(stReqBase.szCityCode);
	cns1__OrderCommitReq.deviceId = strdup(stReqBase.szDeviceId);
	cns1__OrderCommitReq.channelType = strdup(stReqBase.szChannelType);

	char szPaymentCode[64];
	memset(szPaymentCode,0,sizeof(szPaymentCode));
	cns1__OrderCommitReq.paymentCode = strdup(szPaymentCode);

//	memset(pstOrderCommitReq,0,sizeof(ST_ORDER_COMMIT_REQ));
//	sprintf(pstOrderCommitReq->szPaymentVender,"1001");
//	sprintf(pstOrderCommitReq->szPickupStationCode,"0501");
//	sprintf(pstOrderCommitReq->szSingleTicketPrice,"900");
//	sprintf(pstOrderCommitReq->szSingleTicketNum,"1");
//	sprintf(pstOrderCommitReq->szSingleTicketType,"1");

	cns1__OrderCommitReq.paymentVendor = strdup(pstOrderCommitReq->szPaymentVender);
	cns1__OrderCommitReq.pickupStationCode = strdup(pstOrderCommitReq->szPickupStationCode);
	cns1__OrderCommitReq.getOffStationCode = strdup(pstOrderCommitReq->szGetoffStationCode);
	cns1__OrderCommitReq.singleTicketPrice = strdup(pstOrderCommitReq->szSingleTicketPrice);
	cns1__OrderCommitReq.singleTicketNum = strdup(pstOrderCommitReq->szSingleTicketNum);
	cns1__OrderCommitReq.singleTicketType = strdup(pstOrderCommitReq->szSingleTicketType);

	m_pLog->LogDebug("[%s][%s][%d] reqSysDate    = %s", __FILE__ , __FUNCTION__, __LINE__,cns1__OrderCommitReq.reqSysDate);
	m_pLog->LogDebug("[%s][%s][%d] operationCode = %s", __FILE__ , __FUNCTION__, __LINE__,cns1__OrderCommitReq.operationCode);
	m_pLog->LogDebug("[%s][%s][%d] cityCode      = %s", __FILE__ , __FUNCTION__, __LINE__,cns1__OrderCommitReq.cityCode);
	m_pLog->LogDebug("[%s][%s][%d] deviceId      = %s", __FILE__ , __FUNCTION__, __LINE__,cns1__OrderCommitReq.deviceId);
	m_pLog->LogDebug("[%s][%s][%d] channelType   = %s", __FILE__ , __FUNCTION__, __LINE__,cns1__OrderCommitReq.channelType);

	m_pLog->LogDebug("[%s][%s][%d] paymentVendor     = %s", __FILE__ , __FUNCTION__, __LINE__,cns1__OrderCommitReq.paymentVendor);
	m_pLog->LogDebug("[%s][%s][%d] pickupStationCode = %s", __FILE__ , __FUNCTION__, __LINE__,cns1__OrderCommitReq.pickupStationCode);
	m_pLog->LogDebug("[%s][%s][%d] getOffStationCode = %s", __FILE__ , __FUNCTION__, __LINE__,cns1__OrderCommitReq.getOffStationCode);
	m_pLog->LogDebug("[%s][%s][%d] singleTicketPrice = %s", __FILE__ , __FUNCTION__, __LINE__,cns1__OrderCommitReq.singleTicketPrice);
	m_pLog->LogDebug("[%s][%s][%d] singleTicketNum   = %s", __FILE__ , __FUNCTION__, __LINE__,cns1__OrderCommitReq.singleTicketNum);
	m_pLog->LogDebug("[%s][%s][%d] singleTicketType  = %s", __FILE__ , __FUNCTION__, __LINE__,cns1__OrderCommitReq.singleTicketType);

	_ns1__S1_USCORE001 ns1__S1_USCORE001;
	_ns1__S1_USCORE001Response ns1__S1_USCORE001Response;

	ns1__S1_USCORE001.orderCommitReq = &cns1__OrderCommitReq;

	cSLEWebServiceSoapProxy->S1_USCORE001(&ns1__S1_USCORE001, &ns1__S1_USCORE001Response);

	char szResult[5] = {0};
	strcpy(szResult,ns1__S1_USCORE001Response.S1_USCORE001Result->respCode);
	iRet = atoi(szResult);

	m_pLog->LogDebug("[%s][%s][%d] szResult  = %s", __FILE__ , __FUNCTION__, __LINE__,ns1__S1_USCORE001Response.S1_USCORE001Result->respCode);

	if(iRet == 0)
	{
		m_pLog->LogDebug("[%s][%s][%d] partnerNo     = %s", __FILE__ , __FUNCTION__, __LINE__,ns1__S1_USCORE001Response.S1_USCORE001Result->partnerNo);
		m_pLog->LogDebug("[%s][%s][%d] orderNo       = %s", __FILE__ , __FUNCTION__, __LINE__,ns1__S1_USCORE001Response.S1_USCORE001Result->orderNo);
		m_pLog->LogDebug("[%s][%s][%d] subject       = %s", __FILE__ , __FUNCTION__, __LINE__,ns1__S1_USCORE001Response.S1_USCORE001Result->subject);
		m_pLog->LogDebug("[%s][%s][%d] body          = %s", __FILE__ , __FUNCTION__, __LINE__,ns1__S1_USCORE001Response.S1_USCORE001Result->body);
		m_pLog->LogDebug("[%s][%s][%d] payType       = %s", __FILE__ , __FUNCTION__, __LINE__,ns1__S1_USCORE001Response.S1_USCORE001Result->payType);
		m_pLog->LogDebug("[%s][%s][%d] amount        = %s", __FILE__ , __FUNCTION__, __LINE__,ns1__S1_USCORE001Response.S1_USCORE001Result->amount);
		m_pLog->LogDebug("[%s][%s][%d] account       = %s", __FILE__ , __FUNCTION__, __LINE__,ns1__S1_USCORE001Response.S1_USCORE001Result->account);
		m_pLog->LogDebug("[%s][%s][%d] account       = %s", __FILE__ , __FUNCTION__, __LINE__,ns1__S1_USCORE001Response.S1_USCORE001Result->account);
		m_pLog->LogDebug("[%s][%s][%d] notifyUrl     = %s", __FILE__ , __FUNCTION__, __LINE__,ns1__S1_USCORE001Response.S1_USCORE001Result->notifyUrl);
		m_pLog->LogDebug("[%s][%s][%d] merchantCert  = %s", __FILE__ , __FUNCTION__, __LINE__,ns1__S1_USCORE001Response.S1_USCORE001Result->merchantCert);
		m_pLog->LogDebug("[%s][%s][%d] timeout       = %d", __FILE__ , __FUNCTION__, __LINE__,ns1__S1_USCORE001Response.S1_USCORE001Result->timeout);

		if(NULL != ns1__S1_USCORE001Response.S1_USCORE001Result->partnerNo)
			strcpy(pstOrderCommitResp->szPartnerNo, ns1__S1_USCORE001Response.S1_USCORE001Result->partnerNo);
		if(NULL != ns1__S1_USCORE001Response.S1_USCORE001Result->orderNo)
			strcpy(pstOrderCommitResp->szOrderNo, ns1__S1_USCORE001Response.S1_USCORE001Result->orderNo);
		if(NULL != ns1__S1_USCORE001Response.S1_USCORE001Result->subject)
			strcpy(pstOrderCommitResp->szSubject, ns1__S1_USCORE001Response.S1_USCORE001Result->subject);
		if(NULL != ns1__S1_USCORE001Response.S1_USCORE001Result->body)
			strcpy(pstOrderCommitResp->szBody, ns1__S1_USCORE001Response.S1_USCORE001Result->body);
		if(NULL != ns1__S1_USCORE001Response.S1_USCORE001Result->payType)
			strcpy(pstOrderCommitResp->szPayType, ns1__S1_USCORE001Response.S1_USCORE001Result->payType);
		if(NULL != ns1__S1_USCORE001Response.S1_USCORE001Result->amount)
			strcpy(pstOrderCommitResp->szAmount, ns1__S1_USCORE001Response.S1_USCORE001Result->amount);
		if(NULL != ns1__S1_USCORE001Response.S1_USCORE001Result->account)
			strcpy(pstOrderCommitResp->szAccount, ns1__S1_USCORE001Response.S1_USCORE001Result->account);
		if(NULL != ns1__S1_USCORE001Response.S1_USCORE001Result->notifyUrl)
			strcpy(pstOrderCommitResp->szNotifyUrl, ns1__S1_USCORE001Response.S1_USCORE001Result->notifyUrl);
		if(NULL != ns1__S1_USCORE001Response.S1_USCORE001Result->merchantCert)
			strcpy(pstOrderCommitResp->szMerchantCert, ns1__S1_USCORE001Response.S1_USCORE001Result->merchantCert);
		pstOrderCommitResp->iTimeOut = ns1__S1_USCORE001Response.S1_USCORE001Result->timeout;
	}

	m_pLog->LogDebug("[%s][%s][%d] S001OrderCommit finish", __FILE__ , __FUNCTION__, __LINE__);
	return iRet;
}

int CQRCPay::S004OrderExecuteResult(ST_ORDER_EXECUTE_RESULT_REQ *pstOrderExecuteResultReq)
{
	int iRet = 9999;
	ST_REQ_BASE stReqBase;
	memset(&stReqBase, 0, sizeof(stReqBase));
	PackHeadReq(&stReqBase);

	ns1__OrderExecuteResultReq cns1__OrderExecuteResultReq;

//	sprintf(stReqBase.szReqSysDate,"20161031084245");
	sprintf(stReqBase.szOperationCode,"S1-004");
//	sprintf(stReqBase.szCityCode,"020");
//	sprintf(stReqBase.szDeviceId,"0501020004");
//	sprintf(stReqBase.szChannelType,"01");

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
	m_pLog->LogDebug("[%s][%s][%d] szResult  = %s", __FILE__ , __FUNCTION__, __LINE__,ns1__S1_USCORE004Response.S1_USCORE004Result->respCode);
	return iRet;
}

int CQRCPay::S005OrderExecuteFault(ST_ORDER_EXECUTE_FAULT_REQ *pstOrderExecuteFaultReq)
{
	int iRet = 9999;
	ST_REQ_BASE stReqBase;
	memset(&stReqBase, 0, sizeof(stReqBase));
	PackHeadReq(&stReqBase);

	ns1__OrderExecuteFaultReq cns1__OrderExecuteFaultReq;

//	sprintf(stReqBase.szReqSysDate,"20161031084245");
	sprintf(stReqBase.szOperationCode,"S1-005");
//	sprintf(stReqBase.szCityCode,"020");
//	sprintf(stReqBase.szDeviceId,"0501020004");
//	sprintf(stReqBase.szChannelType,"01");

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

	m_pLog->LogDebug("[%s][%s][%d] szResult  = %s", __FILE__ , __FUNCTION__, __LINE__,ns1__S1_USCORE005Response.S1_USCORE005Result->respCode);
	return iRet;
}

int CQRCPay::S009HeartBeat()
{
	int iRet = 9999;
	ST_REQ_BASE stReqBase;
	memset(&stReqBase, 0, sizeof(stReqBase));
	PackHeadReq(&stReqBase);

	ns1__HeartBeatReq cns1__HeartBeatReq;

//	sprintf(stReqBase.szReqSysDate,"20161031084245");
	sprintf(stReqBase.szOperationCode,"S1-009");
//	sprintf(stReqBase.szCityCode,"020");
//	sprintf(stReqBase.szDeviceId,"0501020004");
//	sprintf(stReqBase.szChannelType,"01");

	cns1__HeartBeatReq.reqSysDate = strdup(stReqBase.szReqSysDate);
	cns1__HeartBeatReq.operationCode = strdup(stReqBase.szOperationCode);
	cns1__HeartBeatReq.cityCode = strdup(stReqBase.szCityCode);
	cns1__HeartBeatReq.deviceId = strdup(stReqBase.szDeviceId);
	cns1__HeartBeatReq.channelType = strdup(stReqBase.szChannelType);

	m_pLog->LogDebug("[%s][%s][%d] reqSysDate    = %s", __FILE__ , __FUNCTION__, __LINE__,cns1__HeartBeatReq.reqSysDate);
	m_pLog->LogDebug("[%s][%s][%d] operationCode = %s", __FILE__ , __FUNCTION__, __LINE__,cns1__HeartBeatReq.operationCode);
	m_pLog->LogDebug("[%s][%s][%d] cityCode      = %s", __FILE__ , __FUNCTION__, __LINE__,cns1__HeartBeatReq.cityCode);
	m_pLog->LogDebug("[%s][%s][%d] deviceId      = %s", __FILE__ , __FUNCTION__, __LINE__,cns1__HeartBeatReq.deviceId);
	m_pLog->LogDebug("[%s][%s][%d] channelType   = %s", __FILE__ , __FUNCTION__, __LINE__,cns1__HeartBeatReq.channelType);

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

//	sprintf(stReqBase.szReqSysDate,"20161031084245");
	sprintf(stReqBase.szOperationCode,"S1-018");
//	sprintf(stReqBase.szCityCode,"020");
//	sprintf(stReqBase.szDeviceId,"0501020004");
//	sprintf(stReqBase.szChannelType,"01");

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

	m_pLog->LogDebug("[%s][%s][%d] szResult  = %s", __FILE__ , __FUNCTION__, __LINE__,ns1__S1_USCORE018Response.S1_USCORE018Result->respCode);

	if(iRet == 0)
	{
		m_pLog->LogDebug("[%s][%s][%d] orderNo  = %s", __FILE__ , __FUNCTION__, __LINE__,ns1__S1_USCORE018Response.S1_USCORE018Result->orderNo);
		m_pLog->LogDebug("[%s][%s][%d] deviceId  = %s", __FILE__ , __FUNCTION__, __LINE__,ns1__S1_USCORE018Response.S1_USCORE018Result->deviceId);
		m_pLog->LogDebug("[%s][%s][%d] qrCode  = %s", __FILE__ , __FUNCTION__, __LINE__,ns1__S1_USCORE018Response.S1_USCORE018Result->qrCode);
		if(NULL != ns1__S1_USCORE018Response.S1_USCORE018Result->orderNo)
			strcpy(pstSnapQRCodePrePayURLQueryResp->szOrderNo, ns1__S1_USCORE018Response.S1_USCORE018Result->orderNo);
//		if(NULL != ns1__S1_USCORE018Response.S1_USCORE018Result->deviceId)
//			strcpy(pstSnapQRCodePrePayURLQueryResp->szDeviceId, ns1__S1_USCORE018Response.S1_USCORE018Result->deviceId);
		if(NULL != ns1__S1_USCORE018Response.S1_USCORE018Result->qrCode)
			strcpy(pstSnapQRCodePrePayURLQueryResp->szQrCode, ns1__S1_USCORE018Response.S1_USCORE018Result->qrCode);
	}

	return iRet;
}

int CQRCPay::S019SnapQRCodePayResultQuery(ST_SNAP_QRCODE_PAY_RESULT_REQ *pstSnapQRCodePayResultQueryReq, ST_SNAP_QRCODE_PAY_RESULT_RESP *pstSnapQRCodePayResultQueryResp)
{
	int iRet = 9999;
	ST_REQ_BASE stReqBase;
	memset(&stReqBase, 0, sizeof(stReqBase));
	PackHeadReq(&stReqBase);

//	sprintf(stReqBase.szReqSysDate,"20161031084245");
	sprintf(stReqBase.szOperationCode,"S1-019");
//	sprintf(stReqBase.szCityCode,"020");
//	sprintf(stReqBase.szDeviceId,"0501020004");
//	sprintf(stReqBase.szChannelType,"01");

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
		m_pLog->LogDebug("[%s][%s][%d] orderNo         = %s", __FILE__ , __FUNCTION__, __LINE__,ns1__S1_USCORE019Response.S1_USCORE019Result->orderNo);
		m_pLog->LogDebug("[%s][%s][%d] paymentDate     = %s", __FILE__ , __FUNCTION__, __LINE__,ns1__S1_USCORE019Response.S1_USCORE019Result->paymentDate);
		m_pLog->LogDebug("[%s][%s][%d] amount          = %s", __FILE__ , __FUNCTION__, __LINE__,ns1__S1_USCORE019Response.S1_USCORE019Result->amount);
		m_pLog->LogDebug("[%s][%s][%d] paymentAccount  = %s", __FILE__ , __FUNCTION__, __LINE__,ns1__S1_USCORE019Response.S1_USCORE019Result->paymentAccount);
		m_pLog->LogDebug("[%s][%s][%d] paymentResult   = %s", __FILE__ , __FUNCTION__, __LINE__,ns1__S1_USCORE019Response.S1_USCORE019Result->paymentResult);
		m_pLog->LogDebug("[%s][%s][%d] paymentDesc     = %s", __FILE__ , __FUNCTION__, __LINE__,ns1__S1_USCORE019Response.S1_USCORE019Result->paymentDesc);
		m_pLog->LogDebug("[%s][%s][%d] userName        = %s", __FILE__ , __FUNCTION__, __LINE__,ns1__S1_USCORE019Response.S1_USCORE019Result->userName);

		if(NULL != ns1__S1_USCORE019Response.S1_USCORE019Result->orderNo)
			strcpy(pstSnapQRCodePayResultQueryResp->szOrderNo, ns1__S1_USCORE019Response.S1_USCORE019Result->orderNo);
		if(NULL != ns1__S1_USCORE019Response.S1_USCORE019Result->paymentDate)
			strcpy(pstSnapQRCodePayResultQueryResp->szPaymentDate, ns1__S1_USCORE019Response.S1_USCORE019Result->paymentDate);
		if(NULL != ns1__S1_USCORE019Response.S1_USCORE019Result->amount)
			strcpy(pstSnapQRCodePayResultQueryResp->szAmount, ns1__S1_USCORE019Response.S1_USCORE019Result->amount);
		if(NULL != ns1__S1_USCORE019Response.S1_USCORE019Result->paymentAccount)
			strcpy(pstSnapQRCodePayResultQueryResp->szPaymentAccount, ns1__S1_USCORE019Response.S1_USCORE019Result->paymentAccount);
		if(NULL != ns1__S1_USCORE019Response.S1_USCORE019Result->paymentResult)
			strcpy(pstSnapQRCodePayResultQueryResp->szPaymentResult, ns1__S1_USCORE019Response.S1_USCORE019Result->paymentResult);
		if(NULL != ns1__S1_USCORE019Response.S1_USCORE019Result->paymentDesc)
			strcpy(pstSnapQRCodePayResultQueryResp->szPaymentDesc, ns1__S1_USCORE019Response.S1_USCORE019Result->paymentDesc);
		if(NULL != ns1__S1_USCORE019Response.S1_USCORE019Result->userName)
			strcpy(pstSnapQRCodePayResultQueryResp->szUserName, ns1__S1_USCORE019Response.S1_USCORE019Result->userName);
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

//	sprintf(pstReqBase->szOperationCode,"010250");
	sprintf(pstReqBase->szCityCode,"020");
	sprintf(pstReqBase->szDeviceId,"0101020001");
	sprintf(pstReqBase->szChannelType,"01");

	return 0;
}
