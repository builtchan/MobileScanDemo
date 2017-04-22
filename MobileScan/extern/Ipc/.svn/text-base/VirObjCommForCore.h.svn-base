/*
 * VirObjCommForCore.h
 *
 *  Created on: Jan 20, 2015
 *      Author: root
 */

#ifndef VIROBJCOMMFORCORE_H_
#define VIROBJCOMMFORCORE_H_

#include "VirObjectBase.h"
#include "ipcpublic.h"
#include "IpcManager.h"
#include "IpcMsgSortContainer.h"
#include "IpcMsgText.h"

class CVirObjCommForCore : public CVirObjectBase
{
public:
	CVirObjCommForCore();
	virtual ~CVirObjCommForCore();

	//结算完成通知
	void BalanceFinishNotify(list<ST_IPCMSG_ADDITIONAL_RECORD> *pRecordList);
	void BalanceFinishNotifyParse(CIpcMsgText * pcIpcRawData, list<ST_IPCMSG_ADDITIONAL_RECORD> *pRecordList);


	//运营结束通知 						通知slecomm(Comm)运营结束
	void RunEndNotify();//EM_IPCMSG_CORE_INNER_COMMON_RUN_END

	//运营模式改变通知 				通知slecomm(Comm)运营模式改变
	void RunModeChangeNotify();

	//参数更新完成通知					通知slecomm(Comm)运营结束
	void ParamUpdateFinishNotify();//

	//切换运营日通知					切换运营日时发送
	void SwithRunDateNotify();//EM_IPCMSG_CORE_INNER_COMMON_SWITCH_BIZ_DATE

	//设备招援通知						招援按钮按下，设备招援请求
	//param[out] int* piRequestResult 执行结果
	//param[out] int* piRequestDetail 反馈确认类型
	void NeedHelpRequest(ST_TVM_HELP_INFO stHelpInfo);
	void NeedHelpRequestParse(CIpcMsgText * pcIpcRawData, ST_TVM_HELP_INFO * pstHelpInfo);

	//软件退出通知						需要slecomm关闭退出时，通知slecomm关闭退出
	void SoftwareExitNotify();

	//设备状态变化通知					初始化时，设备状态变化时，发送给SLECOMM更新全状态
	//param[in] char* szStatusRequest 状态数据
	//param[in] int iStatusLenth 状态数据长度
	void DeviceStatusNotify(list<ST_IPCMSG_ADDITIONAL_RECORD> *pRecordList);
	void DeviceStatusNotifyParse(CIpcMsgText * pcIpcRawData, list<ST_IPCMSG_ADDITIONAL_RECORD> *pRecordList);

	void VersionQueryAnswer(list<ST_CSS_VERSION_INFO>  *pVersionRecordList);
	void FlushCommandAnswer(bool bOK);
	void RegisterDataAnswer(bool bRet, map<DWORD, DWORD> * pRegisterDataMap);

	//操作员登录验证
	bool LoginRequest(ST_LOGIN_REQUEST_INFO stLoginInfo, EM_LOGIN_VERIFY_RESULT* pemLoginVerifyResult);
	void LoginRequestParse(CIpcMsgText* pcIpcRawData, ST_LOGIN_REQUEST_INFO* pstLoginInfo);
};
#endif /* VIROBJCOMMFORCORE_H_ */
