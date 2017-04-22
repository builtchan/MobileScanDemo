/*
 * VirObjCoreForComm.h
 *
 *  Created on: Jan 20, 2015
 *      Author: root
 */

#ifndef VIROBJCOREFORCOMM_H_
#define VIROBJCOREFORCOMM_H_

#include "VirObjectBase.h"
#include "ipcpublic.h"
#include "IpcManager.h"
#include "IpcMsgSortContainer.h"
#include "IpcMsgText.h"

class CVirObjCoreForComm: public CVirObjectBase
{
public:
	CVirObjCoreForComm();
	virtual ~CVirObjCoreForComm();

	bool RegisterDataRequest(EM_SLE_DEVICE_TYPE emSleUnitType, map<DWORD, DWORD> *pRegDataMap);

	bool RunningCtrlRequest(EM_RUN_MANAGEMENT_DEF emRunManagementType, list<ST_IPCMSG_ADDITIONAL_RECORD> *pRecordList);

	//	EM_IPCMSG_COMM_CORE_SYNCTIME_NOTIFY	        		= 0x3102,		//	时钟同步通知
	//	EM_IPCMSG_COMM_CORE_PARAM_DOWNLOAD	    			= 0x3103,		//	参数下载完成报告
	//	EM_IPCMSG_COMM_CORE_DEVICE_STATUS_REQUEST	 		= 0x3104,		//	查询设备状态请求
	//	EM_IPCMSG_COMM_CORE_RUN_BEGIN_END		 			= 0x3105,		//	运营开始结束完成报告
	//	EM_IPCMSG_COMM_CORE_CONTROL_CMD_NOTIFY	 			= 0x3106,		//	设备控制命令通知
	//	EM_IPCMSG_COMM_CORE_RUN_MODE_NOTIFY 				= 0x3107,		//	运营模式控制命令通知
	//	EM_IPCMSG_COMM_CORE_HOURS_24_SETUP_NOTIFY 			= 0x3108,		//	24小时运营控制命令通知
	//	EM_IPCMSG_COMM_CORE_DELAY_TIME_SETUP_NOTIFY 		= 0x3109,		//	延长运营时间命令通知
	//	EM_IPCMSG_COMM_CORE_QUERY_VERSION 					= 0x3110, 			//版本查询	请求报文

	//连接状态报告 				slecomm与SC物理连接成功，slecomm与SC物理连接状态
	//parm[in] int iConnectStatus 连接状态 0：正常 -1：断开
	void ConnectStatusNotify(int iConnectStatus);
	//连接状态报告解析
	//parm[out] int iConnectStatus 连接状态 0：正常 -1：断开
	void ConnectStatusNotifyParse(const CIpcMsgText * pcIpcRawData, int* piConnectStatus);

	//时钟同步通知				当slecomm发现和SC的始终差异或者SC强制进行时钟同步，slecomm通知主控进程执行时钟同步
	//parm[in] int iSyncTimeWay 0：slecomm自动时钟同步 1：slecomm收到SC强制时钟同步命令 2：维修界面发起的强制时钟同步 4：维修界面发起的修改本地时间
	//parm[in] bool bUseParam3 0：不需要使用参数3（iTimeDiff） 1：需要使用命令参数3（iTimeDiff）
	//parm[in] int iTimeDiff 时间差异
	void SyncTimeNotify(int iSyncTimeWay,bool bUseParam3,int iTimeDiff);//
	//时钟同步通知解析
	//parm[out] int iSyncTimeWay 0：slecomm自动时钟同步 1：slecomm收到SC强制时钟同步命令 2：维修界面发起的强制时钟同步 4：维修界面发起的修改本地时间
	//parm[out] bool bUseParam3 0：不需要使用参数3（iTimeDiff） 1：需要使用命令参数3（iTimeDiff）
	//parm[out] int iTimeDiff 时间差异
	void SyncTimeNotifyParse(const CIpcMsgText * pcIpcRawData, int* piSyncTimeWay,bool* pbUseParam3,int* piTimeDiff);//

	//参数下载完成报告						slecomm参数下载完成，通知主控进程
	//parm[in] iLoadResult 0参数下载成功  -1参数下载失败
	//parm[in] int iNeedReboot 1：无更新  2：需要重启  3：无需重启
	void DownloadParamNotify(int iLoadResult,int iNeedReboot);
	//参数下载完成报告解析
	//parm[out] iLoadResult 0参数下载成功  -1参数下载失败
	//parm[out] int iNeedReboot 1：无更新  2：需要重启  3：无需重启
	void DownloadParamNotifyParse(const CIpcMsgText * pcIpcRawData, int* piLoadResult,int* piNeedReboot);

	//逻辑连接时序结果报告				slecomm连接时序完成，通知主控进程连接时序结果通知
	//parm[in] bConnectResult 0连接时序成功 -1连接时序失败
//	void LogicConnectSequenceNotify(bool bConnectResult);
	//逻辑连接时序结果报告解析
	//parm[out] bConnectResult 0连接时序成功 -1连接时序失败
//	void LogicConnectSequenceNotifyParse(const CIpcMsgText * pcIpcRawData, bool* pbConnectResult);

	//查询设备状态请求						slecomm与SC物理连接成功，slecomm与SC物理连接状态
	void StatusRequestNotify();

	//运营开始结束完成报告				slecomm连接时序完成，通知主控进程
	//parm[in] bool bStart 0运营开始 1运营结束
	//bool bResult 0成功 -1失败
	void RunNotify(bool bStart, bool bResult);
	//运营开始结束完成报告解析
	//parm[in] bool bStart 0运营开始 1运营结束
	//bool bResult 0成功 -1失败
	void RunNotifyParse(const CIpcMsgText * pcIpcRawData, bool* pbStart, bool* pbResult);

	//设备控制命令通知						slecomm接收到SC设备运行控制命令
	//parm[in] EM_CONTROL_CMD emCmdCode 运行控制命令代码
	void DeviceCtrlCmdNotify(EM_SLE_RUN_CONTROL_CMD emCmdCode);
	//设备控制命令通知	解析
	//parm[out] EM_CONTROL_CMD emCmdCode 运行控制命令代码
	void DeviceCtrlCmdNotifyParse(const CIpcMsgText * pcIpcRawData, EM_SLE_RUN_CONTROL_CMD* pemCmdCode);

	//运营模式控制命令通知 			slecomm接收到SC运营模式控制命令
	//parm[in] ST_COMMON_RUN_MODE cRunMode运营模式代码      0000	正常模式
	void RunModeCMDNotify(ST_COMMON_RUN_MODE stRunMode);
	//运营模式控制命令通知解析
	//parm[in] ST_COMMON_RUN_MODE cRunMode运营模式代码      0000	正常模式
	void RunModeCMDNotifyParse(const CIpcMsgText * pcIpcRawData,ST_COMMON_RUN_MODE* pstRunMode);

	//24小时运营控制命令通知		slecomm接收到SC 24小时运营控制命令
	//parm[in] bool b24HourRun 0:取消24小时运行 1:设置24小时运营
	void Is24HourRunNotify(bool b24HourRun);
	//24小时运营控制命令通知解析
	//parm[out] bool b24HourRun 0:取消24小时运行 1:设置24小时运营
	void Is24HourRunNotifyParse(const CIpcMsgText * pcIpcRawData,bool* pb24HourRun);

	//延长运营时间命令通知
	//parm[in] int iDelayRunTimeInMinute 当为0时，表示取消延长运营，恢复正常运营时间
	void IsDelayRunTimeNotify(int iDelayRunTimeInMinute);
	//延长运营时间命令通知解析
	//parm[out] int iDelayRunTimeInMinute 当为0时，表示取消延长运营，恢复正常运营时间
	void IsDelayRunTimeNotifyParse(const CIpcMsgText * pcIpcRawData,int* iDelayRunTimeInMinute);

	//售票限制命令通知
	//parm[in] int iIsAllowSaleTiket  0x00:解除所有售票限制,此时车站编码填0000; 0x01:允许售票; 0x02:拒绝售票
	//parm[in] int iStationId 车站ID
//	void LimitSaleTicketNotify(int iIsAllowSaleTiket, int iStationId);
	//售票限制命令通知解析
	//parm[out] int piIsAllowSaleTiket  0x00:解除所有售票限制,此时车站编码填0000; 0x01:允许售票; 0x02:拒绝售票
	//parm[out] int piStationId 车站ID
//	void LimitSaleTicketNotifyParse(const CIpcMsgText * pcIpcRawData,int* piIsAllowSaleTiket, int* piStationId);
	//同步请求的应答
	//param[in] int iLogResult 执行结果
	//param[in] int iLogDetail 结果详情
	void LogInQuestAnswer(bool bCheckOK, bool bPwdReset);
	//招援请求应答
	//param[in] int iLogResult 执行结果
	//param[in] int iLogDetail 结果详情
//	void NeedHelpAnswer(int iHelpResult,int iHelpDetail);

	/*! \fn void VersionQueryRequest(int *piAddiLen, void *pAddiData);
	 * \brief 		版本查询
	 * \param[out] 	pVersionRecordList  版本记录LIST
	 * \return  	成功 true； 失败 false
	 * \author 		wugang
	 * \date 		2015－4－12
	 */
	bool VersionQueryRequest(list<ST_CSS_VERSION_INFO>  *pVersionRecordList);

	/*! \fn bool ModeNotify(const void * pModeNotifyData,unsigned int uiModeNotifyDataLent);
	 * \brief 		其他车站的模式通知
	 * param[in]:
	 * 		pModeNotifyData：运营模式的数据
	 * 		uiModeNotifyDataLen: 运营模式的数据长度
	 * \return  	成功 true； 失败 false
	 * \author 		wugang
	 * \date 		2015－4－25
	 */
	void ModeNotify(const void * pModeNotifyData,unsigned int uiModeNotifyDataLent);
	void ModeNotifyParse(CIpcMsgText * pcIpcRawData,void * pModeNotifyData,unsigned int * puiModeNotifyDataLen);

	bool FlushCommand(bool bFlushCoin, bool bFlushBill, bool bFlushTicket);
};
#endif /* VIROBJTVMCOREFORCOMM_H_ */
