/*
 * CQRCPay.h
 *
 *  Created on: 2017-4-11
 *      Author: root
 */

#ifndef CQRCPAY_H_
#define CQRCPAY_H_

#include "soapH.h"
#include "soapStub.h"
#include "soapSLEWebServiceSoapProxy.h"
//#include "soapSLEWebServiceSoap12Proxy.h"

#include "QRCPayDef.h"
#include "CLogOper2.h"

class CQRCPay {
public:
	CQRCPay(CLogOper2 *pLog);
	virtual ~CQRCPay();

	int S001OrderCommit(ST_ORDER_COMMIT_REQ *pstOrderCommitReq, ST_ORDER_COMMIT_RESP *pstOrderCommitResp);
	int S004OrderExecuteResult(ST_ORDER_EXECUTE_RESULT_REQ *pstOrderExecuteResultReq);
	int S005OrderExecuteFault(ST_ORDER_EXECUTE_FAULT_REQ *pstOrderExecuteFaultReq);
	int S009HeartBeat();
	int S018SnapQRCodePrePayURLQuery(char *szOrderNo, ST_SNAP_QRCODE_PREPAY_URL_QUERY_RESP *pstSnapQRCodePrePayURLQueryResp);
	int S019SnapQRCodePayResultQuery(ST_SNAP_QRCODE_PAY_RESULT_REQ *pstSnapQRCodePayResultQueryReq, ST_SNAP_QRCODE_PAY_RESULT_RESP *pstSnapQRCodePayResultQueryResp);

private:
	int PackHeadReq(ST_REQ_BASE *pstReqBase);
	SLEWebServiceSoapProxy *cSLEWebServiceSoapProxy;

	CLogOper2 * m_pLog;			//日志对象
};

#endif /* CQRCPAY_H_ */
