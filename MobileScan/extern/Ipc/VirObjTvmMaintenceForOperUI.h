/*
 * VirObjMaintenceForComm.h
 *
 *  Created on: 6.3, 2016
 *      Author: xuefeng
 */

#ifndef VIROBJTVMMAINTENCEFOROPERUI_H_
#define VIROBJTVMMAINTENCEFOROPERUI_H_

#include "VirObjectBase.h"
#include "ipcpublic.h"
#include "IpcManager.h"
#include "IpcMsgSortContainer.h"
#include "IpcMsgText.h"

//test

class CVirObjTvmMaintenceForOperUI: public CVirObjectBase
{
public:
	CVirObjTvmMaintenceForOperUI();
	virtual ~CVirObjTvmMaintenceForOperUI();

	void LeaveMaintanceRequest();
	void LeaveMaintanceRequestParse();

	void LoginRequest(unsigned char *pstInfo,int iLen);
	void LoginRequestParse(CIpcMsgText * pcIpcRawData,unsigned char *pstId,int *iLen);

//系统设置
	void SystemGetDateRequestEnq();
	void SystemGetIpRequestEnq();
	void SystemGetSCIpRequestEnq();
	void SystemGetSCPortRequestEnq();
	void SystemGetLineNoRequestEnq();
	void SystemGetDeviceNoRequestEnq();


	void SystemSetDateRequest(unsigned char *pstInfo,int iLen);
	void SystemSetDateRequestParse(CIpcMsgText * pcIpcRawData,unsigned char *pstInfo,int *iLen);

	void SystemSetIpRequest(unsigned char *pstIpInfo,int iLen);
	void SystemSetIpRequestParse(CIpcMsgText * pcIpcRawData,unsigned char *pstIpInfo,int *iLen);

	void SystemSetSCIpRequest(unsigned char *pstIpInfo,int iLen);
	void SystemSetSCIpRequestParse(CIpcMsgText * pcIpcRawData,unsigned char *pstIpInfo,int *iLen);

	void SystemSetSCPortRequest(unsigned char *pstIpInfo,int iLen);
	void SystemSetSCPortRequestParse(CIpcMsgText * pcIpcRawData,unsigned char *pstIpInfo,int *iLen);

	void SystemSetLineNoRequest(unsigned char *pstIpInfo,int iLen);
	void SystemSetLineNoRequestParse(CIpcMsgText * pcIpcRawData,unsigned char *pstIpInfo,int *iLen);

	void SystemSetDeviceNoRequest(unsigned char *pstIpInfo,int iLen);
	void SystemSetDeviceNoRequestParse(CIpcMsgText * pcIpcRawData,unsigned char *pstIpInfo,int *iLen);
//系统功能
	void SystemFuncRestartRequest();
	void SystemFuncShutdownRequest();

//维修
	void RepairRechargeReaderInitRequest(unsigned char *pstIpInfo,int iLen);
	void RepairRechargeReaderInitRequestParse(CIpcMsgText * pcIpcRawData,unsigned char *pstIpInfo,int *iLen);


	void RepairRechargeReaderPollingRequest(unsigned char *pstIpInfo,int iLen);
	void RepairRechargeReaderPollingRequestParse(CIpcMsgText * pcIpcRawData,unsigned char *pstIpInfo,int *iLen);

	void RepairRechargeReaderQueryVersionRequest(unsigned char *pstIpInfo,int iLen);
	void RepairRechargeReaderQueryVersionRequestParse(CIpcMsgText * pcIpcRawData,unsigned char *pstIpInfo,int *iLen);

	void RepairRechargeReaderParamCompareRequest(unsigned char *pstIpInfo,int iLen);
	void RepairRechargeReaderParamCompareRequestParse(CIpcMsgText * pcIpcRawData,unsigned char *pstIpInfo,int *iLen);


	void RepairRechargeReaderParamUpdateRequest(unsigned char *pstIpInfo,int iLen);
	void RepairRechargeReaderParamUpdateRequestParse(CIpcMsgText * pcIpcRawData,unsigned char *pstIpInfo,int *iLen);

	void RepairRechargeReaderParamOnekeyUpdateRequest(unsigned char *pstIpInfo,int iLen);
	void RepairRechargeReaderParamOneKeyUpdateRequestParse(CIpcMsgText * pcIpcRawData,unsigned char *pstIpInfo,int *iLen);
//纸币测试 add by  mabin 20170320
	void MaintenceOninnerMsgRequest(int onload,int action);
//	void RepairBillAccepterInitRequest(unsigned char *pstIpInfo,int iLen);
//	void RepairBillAccepterResetRequest(unsigned char *pstIpInfo,int iLen);
//	void RepairBillAccepterStateRequest(unsigned char *pstIpInfo,int iLen);
//	void RepairBillAccepterQueryVersionRequest(unsigned char *pstIpInfo,int iLen);
//	void RepairBillAccepterAcceptRequest(unsigned char *pstIpInfo,int iLen);
//	void RepairBillAccepterForbidRequest(unsigned char *pstIpInfo,int iLen);
//	void RepairBillAccepterEncashRequest(unsigned char *pstIpInfo,int iLen);
//	void RepairBillAccepterRefundRequest(unsigned char *pstIpInfo,int iLen);
//add end 20170322

	//容器更换请求
	bool ContainerChangeRequest(map<DWORD, ST_CONTAINER_DETAIL_INFO>* pstContainerDetailInfoMap);
	//容器操作请求
	bool ContainerOperationRequest(EM_SLE_UNIT_TYPE emSleUnitType, ST_CONTAINER_LOCATION stContainerLocation, EM_CONTAINER_OPERATION_TYPE emOperType, int iOperTimeOut, EM_CONTAINER_OPERATION_RESULT* pemOperResult);
	//容器操作请求解析
	void ContainerOperationRequestParse(CIpcMsgText* pcIpcRawData, EM_SLE_UNIT_TYPE* pemSleUnitType, ST_CONTAINER_LOCATION* pstContainerLocation, EM_CONTAINER_OPERATION_TYPE* pemOperType, int* piOperTimeOut);
	//容器更换结束请求
	bool ContainerChangeEndRequest(map<DWORD, ST_CONTAINER_DETAIL_INFO> stContainerDetailInfoMap);
	//容器更换结束请求解析
	void ContainerChangeEndRequestParse(CIpcMsgText* pcIpcRawData, map<DWORD, ST_CONTAINER_DETAIL_INFO>* pstContainerDetailInfoMap);

//数据查询
	void DataQuerySystemStatusRequest(unsigned char *pstIpInfo,int iLen);
	void DataQuerySystemStatusRequestParse(CIpcMsgText * pcIpcRawData,unsigned char *pstIpInfo,int *iLen);

//服务控制
	void SystemControlServiceNormalModeRequest(int iMode);
	void SystemControlServiceNormalModeRequestParse(CIpcMsgText * pcIpcRawData,int *iMode);

	void SystemControlServiceOutServiceModeRequest(int iMode);
	void SystemControlServiceOutServiceModeRequestParse(CIpcMsgText * pcIpcRawData,int *iMode);


//运营服务
	void RunServiceRunStartRequest(int iMode);
	void RunServiceRunStartRequestParse(CIpcMsgText * pcIpcRawData,int *iMode);

	void RunServiceRunEndRequest(int iMode);
	void RunServiceRunEndRequestParse(CIpcMsgText * pcIpcRawData,int *iMode);

};

#endif /* VIROBJMAINTENCEFORCOMM_H_ */
