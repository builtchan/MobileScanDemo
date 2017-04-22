/*
 * VirObjCommForMaintence.h
 *
 *  Created on: Aug 12, 2015
 *      Author: root
 */

#ifndef VIROBJOPERUIFORMAINTENCE_H_
#define VIROBJOPERUIFORMAINTENCE_H_
#include "VirObjectBase.h"
#include "ipcpublic.h"
#include "IpcManager.h"
#include "IpcMsgSortContainer.h"
#include "IpcMsgText.h"
#include "DataDef.h"
class CVirObjTvmOperUIForMaintence:public CVirObjectBase
{
public:
	CVirObjTvmOperUIForMaintence();
	virtual ~CVirObjTvmOperUIForMaintence();
	/*
	 * 通知SleComm, 维修界面通过U盘导入TPU参数通知
	 */
//	void TpuParamImportNotifyByUDisk();
//	void OperLoginOrLogOutNotify(ST_LOGIN_REQUEST_INFO stLoginInfo, EM_OPERATOR_NOTIFY_TYPE emOperatorNotifyType);
//	void OperLoginOrLogOutNotifyParse(CIpcMsgText * pcIpcRawData, ST_LOGIN_REQUEST_INFO* pstLoginInfo, EM_OPERATOR_NOTIFY_TYPE* pemOperatorNotifyType);
//
//	void OperLoginOrLogOutNotify(ST_LOGIN_REQUEST_INFO stLoginInfo, EM_OPERATOR_NOTIFY_TYPE emOperatorNotifyType);
//	void OperLoginOrLogOutNotifyParse(CIpcMsgText * pcIpcRawData, ST_LOGIN_REQUEST_INFO* pstLoginInfo, EM_OPERATOR_NOTIFY_TYPE* pemOperatorNotifyType);

	void LoginNotify(int iRst, int iFunsNum, char *pFuncs, int iLen);
	void LoginNotifyParse(CIpcMsgText *pcIpcRawData, int *iRst, int *iFunsNum, char *pFuncs, int *iLen);

	void TpuLoopPollCardNotify(ST_TPU_POLLING_CARD_INFO* pstTpuPollCardInfo);
	void TpuLoopPollCardNotifyParse(CIpcMsgText * pcIpcRawData,ST_TPU_POLLING_CARD_INFO* pstTpuPollCardInfo);


	void DataQuerySystemStatusNotify(list<ST_OPER_UI_DATA_QUERY_SYSTEM_STATUS> List);
	void DataQuerySystemStatusNotifyParse(CIpcMsgText * pcIpcRawData,list<ST_OPER_UI_DATA_QUERY_SYSTEM_STATUS> *pList);


	void TpuInitResultNotify(ST_OPER_UI_TPU_STATUS* pstTpuStatus);
	void TpuInitResultNotifyParse(CIpcMsgText * pcIpcRawData,ST_OPER_UI_TPU_STATUS* pstTpuStatus);

	void TpuQueryVersionResultNotify(ST_OPER_UI_TPU_STATUS* pstTpuStatus);
	void TpuQueryVersionResultNotifyParse(CIpcMsgText * pcIpcRawData,ST_OPER_UI_TPU_STATUS* pstTpuStatus);

	void TpuParamCompareResultNotify(ST_OPER_UI_TPU_PARAM *pstTpuStatus);
	void TpuParamCompareResultNotifyParse(CIpcMsgText * pcIpcRawData,ST_OPER_UI_TPU_PARAM *pstTpuStatus);

	void TpuParamOnekeyUpdateResultNotify(ST_OPER_UI_TPU_PARAM_UPDATE *pstTpuStatus);
	void TpuParamOnekeyUpdateResultNotifyParse(CIpcMsgText * pcIpcRawData,ST_OPER_UI_TPU_PARAM_UPDATE *pstTpuStatus);

	void SystemGetDateNotify(unsigned char *pstInfo,int iLen);
	void SystemGetDateNotifyParse(CIpcMsgText * pcIpcRawData,unsigned char *pstInfo,int *iLen);

	void SystemGetIpNotify(ST_OPER_UI_IP_INFO *pstInfo);
	void SystemGetIpNotifyParse(CIpcMsgText * pcIpcRawData,ST_OPER_UI_IP_INFO *pstInfo);

	void SystemGetSCIpNotify(unsigned char *pstInfo,int iLen);
	void SystemGetSCIpNotifyParse(CIpcMsgText * pcIpcRawData,unsigned char *pstInfo,int *iLen);

	void SystemGetSCPortNotify(unsigned char *pstInfo,int iLen);
	void SystemGetSCPortNotifyParse(CIpcMsgText * pcIpcRawData,unsigned char *pstInfo,int *iLen);

	void SystemGetLineNoNotify(unsigned char *pstInfo,int iLen);
	void SystemGetLineNoNotifyParse(CIpcMsgText * pcIpcRawData,unsigned char *pstInfo,int *iLen);

	void SystemGetDeviceNoNotify(unsigned char *pstInfo,int iLen);
	void SystemGetDeviceNoNotifyParse(CIpcMsgText * pcIpcRawData,unsigned char *pstInfo,int *iLen);


	void RunServiceRunStartNotify(ST_OPER_UI_RUN_DATE_INFO *pstInfo);
	void RunServiceRunStartNotifyParse(CIpcMsgText * pcIpcRawData,ST_OPER_UI_RUN_DATE_INFO *pstInfo);


	void RunServiceRunEndNotify(ST_OPER_UI_RUN_DATE_INFO *pstInfo);
	void RunServiceRunEndNotifyParse(CIpcMsgText * pcIpcRawData,ST_OPER_UI_RUN_DATE_INFO *pstInfo);

	//add by mabin 20170321
	void MaintenceOninnerMsgResultNotify(ST_CSSCOINSTATUS* pstCssCoinStatusInfo);
	void CommonResultNotifyParse(CIpcMsgText * pcIpcRawData,ST_CSSCOINSTATUS* pstCssCoinStatusInfo);

	void MaintenceOninnerMsgResultCommonNotify(char *pstInfo,int Len);
	void MaintenceOninnerMsgResultCommonNotifyParse(CIpcMsgText * pcIpcRawData,char *pstInfo,int *Len);

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
};
#endif /* VIROBJCOMMFOROPER_H_ */
