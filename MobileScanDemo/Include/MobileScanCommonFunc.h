/*
 * MobileScanCommonFunc.h
 *
 *  Created on: Apr 18, 2017
 *      Author: chenjc
 */

#ifndef MOBILESCANCOMMONFUNC_H_
#define MOBILESCANCOMMONFUNC_H_

#include <pthread.h>
#include <list>
#include <semaphore.h>
#include <errno.h>
#include <sys/time.h>

#include "MobileScanPayCommonDef.h"
#include "CQRCPay.h"
#include "IMobileScanPaymentFunction.h"
#include "IWebPayEvenHandler.h"
#include "SlePublicFunc.h"
#include "CLogOper2.h"
//#include "PubXml.h"

using namespace std;

class CMobileScanPayCommonFunc : public IMobileScanPaymentFunction
{

public://继承自上层接口的虚函数

	//通讯连接函数
	bool Connect(const char * pszComPath);
	bool Connect(const char* pszComPath, int iBaud, int iDataBits, char cParity, int iStopBits);
	//断开连接函数
	void Disconnect();
	//获取通信质量
	int GetCommQuality();
	//设备初始化
	int Init(const void * pParam);
	//获取模块版本信息
	int GetVersion(EM_SLE_UNIT_TYPE emUnitType, list<ST_CSS_VERSION_INFO> * pstVersionInfoList);
	//模块复位
	int Reset(bool bResetFirmware, const void *pParam);
	//获取模块运行参数
	int GetParam(void *pParam);
	//设置模块运行参数
	int SetParam(const void *pParam);
	//查询模块日志
	int GetLogData(int iLogType, unsigned char *pszBuffer, int iBuffer);
	//清除模块日志
	int ClearLogData(int iLogType);
	//获取模块状态
	int GetDeviceStatus(void *pParam);
	//设置或退出维修模式
	int SetMaintainMode(bool set);
	//设置或退出测试模式
	int SetTestMode(bool set);
	//单体测试
	int StepTest(int iTestItem, const unsigned char *pszTestParam);
	//测试传感器, 获取传感器状态
	int TestSensorStatus(unsigned char *pszStatus, int *piSensorNum);
	//固件软件下载
	int UpdateFireWare(const char *szPortName, int iBaud, int iDataBits, char cParity,
			int iStopBits, const char *szFileName, int iBlockSize, IProgressReport *pcProgressReport);

	//注册事件句柄，返回给上层产生事件
	bool RegEventHandler(CIWebPayEvenHandler * pcCashEventHandler );
	//注册事件句柄，返回给上层产生事件
	CIWebPayEvenHandler * GetEventHandler();

	//交易开始
	bool paymentBegin(const void *pData);

	//确认交易
	bool confirmPayment(const void *pData);

	//取消交易
	bool cancelPayment(const void *pData);

public:
	void AddErrorCode(int iErrorCode,const char * pszErrorInfo);
	void AddErrorCode(int iErrorCode);

public:
	CMobileScanPayCommonFunc(CLogOper2 * pcLog);
	virtual ~CMobileScanPayCommonFunc();

private:
	static void * BizThread(void * arg);

	bool ExecFailedResultAnalyse(int iRet);

private:
	CLogOper2 * m_pCommonLog;			//日志对象
	CQRCPay * m_pQrCodePayAtomic;		//原子层对象
	CIWebPayEvenHandler * m_pHandler;	//回调指针

	bool m_bThread;						//线程标记
	bool m_bNetworkOK;					//网络连接正常
	int m_iConnectTimeOut;				//连接超时时间，毫秒
	int m_iWaitPayTimeOut;				//等待支付超时时间，毫秒

	bool m_bOrderSend;					//请求是否发出
	bool m_bCreateQRCodeOk;				//是否已经生成二维码
	bool m_bConfirmTrans;				//确认交易
	bool m_bFaultTrans;					//是否时故障交易
	bool m_bCancelTrans;				//取消交易
	int m_iTryTime;						//重复执行次数

	EM_RESP_CODE m_emRespFaultCode;		//响应返回的故障码
	int  m_iErrorCode;					//错误码

	ST_ORDER_COMMIT_RESP m_stOrderCommitRespData;	//订单提交响应数据
	ST_SNAP_QRCODE_PREPAY_URL_QUERY_RESP m_stQRCodeRespData; //预订单请求回复数据

	ST_SNAP_QRCODE_PAY_RESULT_REQ m_stPayResultReq;   //支付结果请求
	ST_SNAP_QRCODE_PAY_RESULT_RESP m_stPayResultData; //支付结果

	ST_ORDER_EXECUTE_RESULT_REQ m_stExecResultReq;		//支付结果确认
	ST_ORDER_EXECUTE_FAULT_REQ m_stTransFaultReq;		//交易失败

	pthread_t m_BizThreadId;			//线程ID
	pthread_mutex_t m_BizThreadMutex;	//线程锁

	EM_DEVICE_COMMON_STATE m_stCommonState;				//通用状态
	ST_MOBILESCAN_STATUS m_stMobileScanStatus;			//模块状态

};




#endif /* MOBILESCANCOMMONFUNC_H_ */
