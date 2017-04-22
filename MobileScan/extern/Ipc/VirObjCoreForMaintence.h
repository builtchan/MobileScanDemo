/*
 * VirObjTvmMaintenceForCore.h
 *
 *  Created on: Dec 18, 2014
 *      Author: yangshuang
 */

#ifndef VIROBJTVMTVMCOREFORMAINTENCE_H_
#define VIROBJTVMTVMCOREFORMAINTENCE_H_

#include "VirObjectBase.h"

#include "ipcpublic.h"

#include "SleParamAttriDefPublic.h"
#include "IpcManager.h"
#include "IpcMsgSortContainer.h"
#include "IpcMsgText.h"
#include "MaintainTestPublicDef.h"
#include <string>

class CVirObjCoreForMaintence: public CVirObjectBase {
public:
	CVirObjCoreForMaintence();
	virtual ~CVirObjCoreForMaintence();
	//退出维修模式
	bool ExitMaintenceMode();
	//重新加载参数
	bool ReloadParamNotify(EM_PARAM_TYPE_DEF emParamType);
	//维修界面发送票箱更换开始
	void TicketboxChangeBeginTest(bool bBalanceFlag, bool bIsLastBox, ST_BALANCE_BOX_INFO stBalanceBoxInfo);
	void TicketboxChangeBeginTestParse(CIpcMsgText* pcIpcRawData, bool* pbBalanceFlag, bool* pbIsLastBox, ST_BALANCE_BOX_INFO* pstBalanceBoxInfo);
	//维修界面发送票箱更换完成
	void TicketboxChangeFinishTest(bool bPrintAllow, list<ST_TICKET_BOX_INPUT_INFO>* pRecordList);
	//维修界面发送票箱更换完成解析
	void TicketboxChangeFinishTestParse(CIpcMsgText * pcIpcRawData, bool * pbPrintAllow,
			list<ST_TICKET_BOX_INPUT_INFO> *pRecordList);
	//维修界面点击票箱解锁
	void TicketboxOperationTest(int iCount,
			EM_CONTAINER_OPERATION_TYPE emBoxOpType,
			const ST_TICKET_CONTAINER_LOCATION* pstTicketBoxPosition);
	//维修界面点击票箱解锁解析
	void TicketboxOperationTestParse(CIpcMsgText * pcIpcRawData,
			EM_CONTAINER_OPERATION_TYPE * pemBoxOpType,
			list<ST_TICKET_CONTAINER_LOCATION>* pstTicketBoxPositionList);

	//维修界面发送钱箱更换开始
	void CashboxChangeBeginTest(bool bBalanceFlag, bool bIsLastBox, ST_BALANCE_BOX_INFO stBalanceBoxInfo);
	void CashboxChangeBeginTestParse(CIpcMsgText* pcIpcRawData, bool* pbBalanceFlag, bool* pbIsLastBox, ST_BALANCE_BOX_INFO* pstBalanceBoxInfo);
	//维修界面发送钱箱更换完成
	void CashboxChangeFinishTest(bool bPrintAllow, list<ST_CASH_BOX_INPUT_INFO>* pRecordList);
	//维修界面发送钱箱更换完成解析
	void CashboxChangeFinishTestParse(CIpcMsgText * pcIpcRawData, bool * pbPrintAllow,
			list<ST_CASH_BOX_INPUT_INFO> *pRecordList);
	//维修界面点击钱箱解锁
	//param[in] iCount 箱子的个数
	//param[in] emBoxOpType 箱子操作类型 换上换下补充
	//param[in] pstBoxPosition 箱子位置信息
	void CashboxOperationTest(int iCount,
			EM_CONTAINER_OPERATION_TYPE emBoxOpType,
			const ST_CASH_CONTAINER_LOCATION* pstTicketBoxPosition);
	//维修界面点击钱箱解锁解析
	//param[out] stBoxPosition
	void CashboxOperationTestParse(CIpcMsgText * pcIpcRawData,
			EM_CONTAINER_OPERATION_TYPE * pemBoxOpType,
			list<ST_CASH_CONTAINER_LOCATION>* pstTicketBoxPositionList);

//	bool SyncCallToCore(const ST_TEXT_DATA * pstTextData,
//			ST_TEXT_DATA * pstData);
//	bool AsyncCallToCore(const ST_TEXT_DATA * pstTextData);

	bool LoginRequest(ST_LOGIN_REQUEST_INFO stLoginInfo, EM_LOGIN_VERIFY_RESULT* pemLoginVerifyResult);
	void LoginRequestParse(CIpcMsgText * pcIpcRawData,
			ST_LOGIN_REQUEST_INFO * pstLoginInfo);

	void LogoutRequest();
	/*+++++++++++++++++++++++++++++*/
	/*! \fn 	void CtrlCommandRequest(EM_SLE_RUN_CONTROL_CMD emSleRunCtrlCmd);
	 * \brief 				控制命令请求
	 * \param[in]  		emSleRunCtrlCmd		运行控制命令代码枚举值
	 * \return			执行结果
	 * \author 			hehj
	 * \date 			2015－4-1
	 */
	bool CtrlCommandRequest(EM_SLE_RUN_CONTROL_CMD emSleRunCtrlCmd);
	void CtrlCommandRequestParse(CIpcMsgText * pcIpcRawData,
			EM_SLE_RUN_CONTROL_CMD* pemSleRunCtrlCmd);

	bool RunningCtrlRequest(EM_RUN_MANAGEMENT_DEF emRunManageType);


	/*! \fn 		void ClockSynchronousRequest(int iClockSycWay,bool bNeedParam,int iDifferTime);
	 * \brief 	时钟同步请求
	 * \param[in]  		iClockSycWay		0：slecomm自动时钟同步。
	 1：slecomm收到SC强制时钟同步命令。
	 2：维修界面发起的强制时钟同步。
	 4：维修界面发起的修改本地时间。
	 * \param[in]  		bNeedParam		false：不需要使用参数iDifferTime。
	 true：需要使用命令参数iDifferTime。
	 * \param[in]  		iDifferTime		当bNeedParam=true,此参数作为时间差异
	 * \return			无
	 * \author 			hehj
	 * \date 			2015－4-1
	 * 修改作者：         wangzp
	 * 修改内容：         添加设置时间参数，供修改本地时间使用
	 */
	void ClockSynchronousRequest(int iClockSycWay, bool bNeedParam,
			int iDifferTime, string strNewTime);
	void ClockSynchronousRequestParse(CIpcMsgText * pcIpcRawData,
			int* piClockSycWay, bool* pbNeedParam, int* piDifferTime, string * pstrNewTime);
	/*! \fn 	void VersionInfoRequest(bool* pbExecResult,list<ST_IPCMSG_ADDITIONAL_RECORD> *pRecordList);
	 * \brief 	版本信息请求
	 * \param[out] pRecordList 附加信息为部件ID和版本信息结构体
	 * \return			执行结果
	 * \author 			hehj
	 * \date 			2015－4-1
	 */
	bool VersionInfoRequest(list<ST_CSS_VERSION_INFO> *pRecordList);
	/*! \fn 	void CashBoxFlushRequest(list<ST_CASH_CONTAINER_LOCATION> *pstCashContainerInfoList);
	 * \brief 	钱箱清空请求
	 * \param[in] pstCashContainerInfoList 所清空的箱子信息
	 * \return			成功失败
	 * \author 			hehj
	 * \date 			2015－4-1
	 */
	bool CashBoxFlushRequest(list<ST_CASH_CONTAINER_LOCATION> *pstCashContainerInfoList);
	void CashBoxFlushRequestParse(CIpcMsgText * pcIpcRawData,list<ST_CASH_CONTAINER_LOCATION> *pstCashContainerInfoList);
	/*! \fn 	void CashBoxSupplyOneByOneRequest(int iDoStart);
	 * \brief 	找零箱逐张补充请求（循环纸币单元）
	 * \param[in] iDoStart 1:补充开始 2:补充完成
	 * \return			无
	 * \author 			hehj
	 * \date 			2015－4-1
	 */
	void CashBoxSupplyOneByOneRequest(int iDoStart);
	void CashBoxSupplyOneByOneRequestParse(CIpcMsgText * pcIpcRawData,
			int* piDoStart);
	/*! \fn 	void TicketBoxFlushRequest(list<ST_TICKET_CONTAINER_LOCATION> *pstTicketContainerInfoList);
	 * \brief 	票箱清空请求
	 * \param[in] pstTicketContainerInfoList 所清空的箱子信息
	 * \return			成功/失败
	 * \author 			hehj
	 * \date 			2015－4-1
	 */
	bool TicketBoxFlushRequest(list<ST_TICKET_CONTAINER_LOCATION> *pstTicketContainerInfoList);
	void TicketBoxFlushRequestParse(CIpcMsgText * pcIpcRawData,list<ST_TICKET_CONTAINER_LOCATION> *pstTicketContainerInfoList);
	/*! \fn 	void RunBalanceRequest(list<ST_IPCMSG_ADDITIONAL_RECORD> *pRecordList);
	 * \brief 	结算请求
	 * \param[out] list<ST_IPCMSG_ADDITIONAL_RECORD> *pRecordList 结算数据结构体，项目化数据结构
	 * \param[in] list<ST_TICKET_CONTAINER_LOCATION> *pstTicketContainerInfoList    结算前需要清空的票箱位置集合
	 * \param[in] list<ST_CASH_CONTAINER_LOCATION> *pstCashContainerInfoList 结算前需要清空的钱箱位置集合
	 * \return			执行结果
	 * \author 			hehj
	 * \date 			2015－4-1
	 */
	bool RunBalanceRequest(list<ST_IPCMSG_ADDITIONAL_RECORD> *pRecordList, string strRemark);
	bool RunBalanceRequestParse(CIpcMsgText * pcIpcRawData, string & strRemark);
	bool RunSettlementRequest(list<ST_IPCMSG_ADDITIONAL_RECORD> *pRecordList);

	/*! \fn 	void ErrorClearRequest(bool* pbExecResult, list<ST_IPCMSG_ADDITIONAL_RECORD> *pstStatusRecordList);
	 * \brief 	一键错误重置请求
	 * \param[out] pstStatusRecordList 全状态结构体
	 * \return			 执行结果
	 * \author 		hehj
	 * \date 			2015－4-1
	 */
	bool ErrorClearRequest(	list<ST_IPCMSG_ADDITIONAL_RECORD> *pstStatusRecordList);
	/*! \fn 	void IlegalOperationNotify(int iInvadeOperWay);
	 * \brief 	入侵通知
	 * \param[in] iInvadeOperWay 	入侵类型枚举值：
	 1：超时未登陆
	 2：密码连续输错达到规定次数
	 3：未授权打开现金门或者动用钱箱
	 4: 打开维修门短时间未登录
	 * \return			无
	 * \author 		hehj
	 * \date 			2015－4-1
	 */
	void InvadeOperationNotify(int iInvadeOperWay);
	void InvadeOperationNotifyParse(CIpcMsgText * pcIpcRawData,
			int* piInvadeOperWay);
	/*! \fn 	void TestModeSet(int iBizFunctionID, int iOperWay, bool* pbExecResult);
	 * \brief 	入侵通知
	 * \param[in] iBizFunctionID 	业务功能ID
	 * \param[in] iOperWay 			操作类型
	 1：进入测试模式
	 2：退出测试模式
	 * \return			执行结果
	 * \author 		hehj
	 * \date 			2015－4-1
	 */
	bool TestModeSet(int iBizFunctionID, int iOperWay);
	void TestModeSetParse(CIpcMsgText * pcIpcRawData, int* piBizFunctionID,
			int* piOperWay);
	/*+++++++++++++++++++++++++++++*/
//--------------------------------------------------------------------------------------------------------
	/*! \fn CVirObjCoreForMaintence::PlayTest(ST_TEST_REQUEST_MSG stTestRequestMsg, EM_PALY_DEVICE_TYPE emPlayDeviceType,
	 ST_TEST_FEEDBACK_MSG* pstTestFeedBackMsg, void* pRetStatusData)
	 * \brief 			1.维修播放测试
	 * \param[in]  		stTestRequestMsg		部件测试发起数据
	 * \param[in]		emPlayDeviceType		播放设备类型
	 * \param[out]		pstTestFeedBackMsg		部件测试反馈数据
	 * \param[out]		pRetStatusData			模块状态结构体
	 * \return			true/false				测试成功/失败
	 * \author 			longjg
	 * \date 			2015－3-24
	 */
	bool PlayTest(ST_TEST_REQUEST_MSG stTestRequestMsg,
			EM_PALY_DEVICE_TYPE emPlayDeviceType,
			ST_TEST_FEEDBACK_MSG* pstTestFeedBackMsg, void* pRetStatusData);
	void PlayTestParse(CIpcMsgText * pcIpcRawData,
			EM_PALY_DEVICE_TYPE *pemPlayDeviceType);

//--------------------------------------------------------------------------------------------------------
	/*! \fn CVirObjCoreForMaintence::ConnectTest(ST_TEST_REQUEST_MSG stTestRequestMsg, EM_CONNECT_TYPE emConnectType,
	 ST_TEST_FEEDBACK_MSG* pstTestFeedBackMsg, void* pRetStatusData)								)
	 * \brief 			2.维修连接测试
	 * \param[in]  		stTestRequestMsg		部件测试发起数据
	 * \param[in]  		emConnectType			连接类型
	 * \param[out]		pstTestFeedBackMsg		部件测试反馈数据
	 * \param[out]		pRetStatusData			模块状态结构体
	 * \return			true/false				测试成功/失败
	 * \author 			longjg
	 * \date 			2015－3-24
	 */
	bool ConnectTest(ST_TEST_REQUEST_MSG stTestRequestMsg,
			EM_CONNECT_TYPE emConnectType,
			ST_TEST_FEEDBACK_MSG* pstTestFeedBackMsg, void* pRetStatusData);
	void ConnectTestParse(CIpcMsgText * pcIpcRawData,
			EM_CONNECT_TYPE *pemConnectType);

//--------------------------------------------------------------------------------------------------------
	/*! \fn CVirObjCoreForMaintence::InitTest(ST_TEST_REQUEST_MSG stTestRequestMsg, ST_TEST_FEEDBACK_MSG* pstTestFeedBackMsg, void* pRetStatusData)
	 * \brief 			3.维修初始化测试
	 * \param[in]  		stTestRequestMsg		部件测试发起数据
	 * \param[out]		pstTestFeedBackMsg		部件测试反馈数据
	 * \param[out]		pRetStatusData			模块状态结构体
	 * \return			true/false				测试成功/失败
	 * \author 			longjg
	 * \date 			2015－3-24
	 */
	bool InitTest(ST_TEST_REQUEST_MSG stTestRequestMsg,
			ST_TEST_FEEDBACK_MSG* pstTestFeedBackMsg, void* pRetStatusData);
//--------------------------------------------------------------------------------------------------------
	/*! \fn CVirObjCoreForMaintence::ErrorResetTest(ST_TEST_REQUEST_MSG stTestRequestMsg, ST_TEST_FEEDBACK_MSG* pstTestFeedBackMsg, void* pRetStatusData)
	 * \brief 			4.维修错误重置测试
	 * \param[in]  		stTestRequestMsg		部件测试发起数据
	 * \param[out]		pstTestFeedBackMsg		部件测试反馈数据
	 * \param[out]		pRetStatusData			模块状态结构体
	 * \return			true/false				测试成功/失败
	 * \author 			longjg
	 * \date 			2015－3-24
	 */
	bool ErrorResetTest(ST_TEST_REQUEST_MSG stTestRequestMsg,
			ST_TEST_FEEDBACK_MSG* pstTestFeedBackMsg, void* pRetStatusData);
//--------------------------------------------------------------------------------------------------------
	/*! \fn CVirObjCoreForMaintence::StatusRequestTest(ST_TEST_REQUEST_MSG stTestRequestMsg, ST_TEST_FEEDBACK_MSG* pstTestFeedBackMsg, void* pRetStatusData)
	 * \brief 			5.维修状态请求测试
	 * \param[in]  		stTestRequestMsg		部件测试发起数据
	 * \param[out]		pstTestFeedBackMsg		部件测试反馈数据
	 * \param[out]		pRetStatusData			模块状态结构体
	 * \return			true/false				测试成功/失败
	 * \author 			longjg
	 * \date 			2015－3-24
	 */
	bool StatusRequestTest(ST_TEST_REQUEST_MSG stTestRequestMsg,
			ST_TEST_FEEDBACK_MSG* pstTestFeedBackMsg, void* pRetStatusData);
//--------------------------------------------------------------------------------------------------------
	/*! \fn CVirObjCoreForMaintence::GoThroughIndicateTest(EM_PASS_INDICATE_DEVICE_TYPE emIndicateType, EM_GO_THROUGH_WAY emGoThroughWay, ST_TEST_REQUEST_MSG stTestRequestMsg, ST_TEST_FEEDBACK_MSG* pstTestFeedBackMsg, void* pRetStatusData)
	 * \brief 			6.通行指示测试
	 * \param[in]		emIndicateType			通行指示部件类型
	 * \param[in]		emGoThroughWay			通行方式
	 * \param[in]  		stTestRequestMsg		部件测试发起数据
	 * \param[out]		pstTestFeedBackMsg		部件测试反馈数据
	 * \param[out]		pRetStatusData			模块状态结构体
	 * \return			true/false				测试成功/失败
	 * \author 			longjg
	 * \date 			2015－3-24
	 */
	bool GoThroughIndicateTest(EM_PASS_INDICATE_DEVICE_TYPE emIndicateType,
			EM_GO_THROUGH_WAY emGoThroughWay,
			ST_TEST_REQUEST_MSG stTestRequestMsg,
			ST_TEST_FEEDBACK_MSG* pstTestFeedBackMsg, void* pRetStatusData);
	void GoThroughIndicateTestParse(CIpcMsgText * pcIpcRawData,
			EM_PASS_INDICATE_DEVICE_TYPE *pemIndicateType,
			EM_GO_THROUGH_WAY *pemGoThroughWay);

	//--------------------------------------------------------------------------------------------------------
	/*! \fn CVirObjCoreForMaintence::LampLightTest(EM_LAMPLIGHT_TYPE emLampLightType, EM_ALARM_LIGHT emAlarmLightColor,
	 EM_ALARM_LIGHT_TYPE emAlarmLightNo, ST_TEST_REQUEST_MSG stTestRequestMsg,
	 ST_TEST_FEEDBACK_MSG* pstTestFeedBackMsg, void* pRetStatusData)
	 * \brief 			7.灯光测试
	 * \param[in]		emLampLightType			灯光类型
	 * \param[in]		emAlarmLightColor		警报指示灯颜色
	 * \param[in]		emAlarmLightNo			警报灯序号
	 * \param[in]  		stTestRequestMsg		部件测试发起数据
	 * \param[out]		pstTestFeedBackMsg		部件测试反馈数据
	 * \param[out]		pRetStatusData			模块状态结构体
	 * \return			true/false				测试成功/失败
	 * \author 			longjg
	 * \date 			2015－3-24
	 */
	bool LampLightTest(EM_LAMPLIGHT_TYPE emLampLightType,
			EM_ALARM_LIGHT emAlarmLightColor,
			EM_ALARM_LIGHT_TYPE emAlarmLightNo,
			ST_TEST_REQUEST_MSG stTestRequestMsg,
			ST_TEST_FEEDBACK_MSG* pstTestFeedBackMsg, void* pRetStatusData);
	void LampLightTestParse(CIpcMsgText * pcIpcRawData,
			EM_LAMPLIGHT_TYPE *pemLampLightType,
			EM_ALARM_LIGHT *pemAlarmLightColor,
			EM_ALARM_LIGHT_TYPE *pemAlarmLightNo);
//--------------------------------------------------------------------------------------------------------
	/*! \fn CVirObjCoreForMaintence::PassageWayModeTest(EM_GATE_WORKMODE emGateWorkMode, ST_TEST_REQUEST_MSG stTestRequestMsg,
	 ST_TEST_FEEDBACK_MSG* pstTestFeedBackMsg, void* pRetStatusData)
	 * \brief 			8.通道模式测试
	 * \param[in]		emGateWorkMode			门工作模式
	 * \param[in]  		stTestRequestMsg		部件测试发起数据
	 * \param[out]		pstTestFeedBackMsg		部件测试反馈数据
	 * \param[out]		pRetStatusData			模块状态结构体
	 * \return			true/false				测试成功/失败
	 * \author 			longjg
	 * \date 			2015－3-24
	 */
	bool PassageWayModeTest(EM_GATE_WORKMODE emGateWorkMode,
			ST_TEST_REQUEST_MSG stTestRequestMsg,
			ST_TEST_FEEDBACK_MSG* pstTestFeedBackMsg, void* pRetStatusData);
	void PassageWayModeTestParse(CIpcMsgText * pcIpcRawData,
			EM_GATE_WORKMODE *pemGateWorkMode);
//--------------------------------------------------------------------------------------------------------
	/*! \fn CVirObjCoreForMaintence::GoThroughTest(EM_GO_THROUGH_FUNC_TYPE emGoThroughFuncType, ST_TEST_REQUEST_MSG stTestRequestMsg,
	 ST_TEST_FEEDBACK_MSG* pstTestFeedBackMsg, void* pRetStatusData)
	 * \brief 			9.通行测试
	 * \param[in]		emGoThroughFuncType		通行功能类型
	 * \param[in]  		stTestRequestMsg		部件测试发起数据
	 * \param[out]		pstTestFeedBackMsg		部件测试反馈数据
	 * \param[out]		pRetStatusData			模块状态结构体
	 * \return			true/false				测试成功/失败
	 * \author 			longjg
	 * \date 			2015－3-24
	 */
	bool GoThroughTest(EM_GO_THROUGH_FUNC_TYPE emGoThroughFuncType,
			ST_TEST_REQUEST_MSG stTestRequestMsg,
			ST_TEST_FEEDBACK_MSG* pstTestFeedBackMsg, void* pRetStatusData);
	void GoThroughTestParse(CIpcMsgText * pcIpcRawData,
			EM_GO_THROUGH_FUNC_TYPE *pemGoThroughFuncType);
//--------------------------------------------------------------------------------------------------------
	/*! \fn CVirObjCoreForMaintence::TicketRecycleTest(EM_TRU_FUNC_TYPE emTruFuncType, ST_TICKET_CONTAINER_LOCATION stContainerLocation,
	 ST_TEST_REQUEST_MSG stTestRequestMsg, ST_TEST_FEEDBACK_MSG* pstTestFeedBackMsg, void* pRetStatusData)
	 * \brief 			10.车票回收测试
	 * \param[in]		emTruFuncType			车票回收功能类型
	 * \param[in]		stContainerLocation		箱子类型+箱子编号
	 * \param[in]  		stTestRequestMsg		部件测试发起数据
	 * \param[out]		pstTestFeedBackMsg		部件测试反馈数据
	 * \param[out]		pRetStatusData			模块状态结构体
	 * \return			true/false				测试成功/失败
	 * \author 			longjg
	 * \date 			2015－3-24
	 */
	bool TicketRecycleTest(EM_TRU_FUNC_TYPE emTruFuncType,
			ST_TICKET_CONTAINER_LOCATION stContainerLocation,
			ST_TEST_REQUEST_MSG stTestRequestMsg,
			ST_TEST_FEEDBACK_MSG* pstTestFeedBackMsg, void* pRetStatusData);
	void TicketRecycleTestParse(CIpcMsgText * pcIpcRawData,
			EM_TRU_FUNC_TYPE *pemTruFuncType,
			ST_TICKET_CONTAINER_LOCATION *pstContainerLocation);
//--------------------------------------------------------------------------------------------------------
	/*! \fn CVirObjCoreForMaintence::CashBoxUnlockTest(EM_CONTAINER_OPERATION_TYPE emOperateType, ST_CASH_CONTAINER_LOCATION stContainerLocation,
	 ST_TEST_REQUEST_MSG stTestRequestMsg, ST_TEST_FEEDBACK_MSG* pstTestFeedBackMsg, void* pRetStatusData)
	 * \brief 			11.钱箱开锁测试
	 * \param[in]		emOperateType			钱箱操作类型
	 * \param[in]		stContainerLocation		现金类型+箱子类型+箱子编号
	 * \param[in]  		stTestRequestMsg		部件测试发起数据
	 * \param[out]		pstTestFeedBackMsg		部件测试反馈数据
	 * \param[out]		pRetStatusData			模块状态结构体
	 * \return			true/false				测试成功/失败
	 * \author 			longjg
	 * \date 			2015－3-24
	 */
	bool CashBoxUnlockTest(EM_CONTAINER_OPERATION_TYPE emOperateType,
			ST_CASH_CONTAINER_LOCATION stContainerLocation,
			ST_TEST_REQUEST_MSG stTestRequestMsg,
			ST_TEST_FEEDBACK_MSG* pstTestFeedBackMsg, void* pRetStatusData);
	void CashBoxUnlockTestParse(CIpcMsgText * pcIpcRawData,
			EM_CONTAINER_OPERATION_TYPE *pemOperateType,
			ST_CASH_CONTAINER_LOCATION *pstContainerLocation);
//--------------------------------------------------------------------------------------------------------
	/*! \fn CVirObjCoreForMaintence::TicketBoxUnlockTest(EM_CONTAINER_OPERATION_TYPE emOperateType, ST_TICKET_CONTAINER_LOCATION stContainerLocation,
	 ST_TEST_REQUEST_MSG stTestRequestMsg, ST_TEST_FEEDBACK_MSG* pstTestFeedBackMsg, void* pRetStatusData)
	 * \brief 			12.票箱开锁测试
	 * \param[in]		emOperateType			票箱操作类型
	 * \param[in]		stContainerLocation		箱子类型+箱子编号
	 * \param[in]  		stTestRequestMsg		部件测试发起数据
	 * \param[out]		pstTestFeedBackMsg		部件测试反馈数据
	 * \param[out]		pRetStatusData			模块状态结构体
	 * \return			true/false				测试成功/失败
	 * \author 			longjg
	 * \date 			2015－3-24
	 */
	bool TicketBoxUnlockTest(EM_CONTAINER_OPERATION_TYPE emOperateType,
			ST_TICKET_CONTAINER_LOCATION stContainerLocation,
			ST_TEST_REQUEST_MSG stTestRequestMsg,
			ST_TEST_FEEDBACK_MSG* pstTestFeedBackMsg, void* pRetStatusData);
	void TicketBoxUnlockTestParse(CIpcMsgText * pcIpcRawData,
			EM_CONTAINER_OPERATION_TYPE *pemOperateType,
			ST_TICKET_CONTAINER_LOCATION *pstContainerLocation);
//--------------------------------------------------------------------------------------------------------
	/*! \fn CVirObjCoreForMaintence::CashBoxRfidTest(EM_RFID_OPERATE_TYPE emRfidOperateType,
	 ST_CASH_CONTAINER_LOCATION stContainerLocation, ST_TEST_REQUEST_MSG stTestRequestMsg,
	 ST_TEST_FEEDBACK_MSG* pstTestFeedBackMsg, void* pRetStatusData, unsigned int* piBoxId)
	 * \brief 			13.钱箱RFID测试
	 * \param[in]		emRfidOperateType		Rfid操作类型
	 * \param[in]		stContainerLocation		现金类型+箱子类型+箱子编号
	 * \param[in]  		stTestRequestMsg		部件测试发起数据
	 * \param[out]		pstTestFeedBackMsg		部件测试反馈数据
	 * \param[out]		pRetStatusData			模块状态结构体
	 * \param[out]		piBoxId					箱子Id
	 * \return			true/false				测试成功/失败
	 * \author 			longjg
	 * \date 			2015－3-24
	 */
	bool CashBoxRfidTest(EM_RFID_OPERATE_TYPE emRfidOperateType,
			ST_CASH_CONTAINER_LOCATION stContainerLocation,
			ST_TEST_REQUEST_MSG stTestRequestMsg,
			ST_TEST_FEEDBACK_MSG* pstTestFeedBackMsg, void* pRetStatusData,
			BYTE *pszBoxId);
	void CashBoxRfidTestParse(CIpcMsgText * pcIpcRawData,
			EM_RFID_OPERATE_TYPE *pemRfidOperateType,
			ST_CASH_CONTAINER_LOCATION *pstContainerLocation);

	/*! \fn CVirObjCoreForMaintence::CashBoxRfidRw(EM_RFID_OPERATE_TYPE emRfidOperateType, int iBlockNo, ST_CASH_CONTAINER_LOCATION stContainerLocation,
	 	ST_TEST_REQUEST_MSG stTestRequestMsg, ST_TEST_FEEDBACK_MSG* pstTestFeedBackMsg, void* pRetStatusData, void* pReadWriteRfidData, DWORD* puiReadWriteDataLenth);
	 * \brief 			13.钱箱RFID读写
	 * \param[in]		emRfidOperateType		Rfid操作类型
	 * \param[in]		iBlockNo				块号0~127块
	 * \param[in]		stContainerLocation		现金类型+箱子类型+箱子编号
	 * \param[in]  		stTestRequestMsg		部件测试发起数据
	 * \param[out]		pstTestFeedBackMsg		部件测试反馈数据
	 * \param[out]		pRetStatusData			模块状态结构体
	 * \param[in/out]	pReadWriteRfidData		写为入参, 读为出参
	 * \param[in/out]	puiReadWriteDataLenth	写为入参, 读为出参
	 * \return			true/false				测试成功/失败
	 * \author 			longjg
	 * \date 			2017－03-02
	 */
	bool CashBoxRfidRw(EM_RFID_OPERATE_TYPE emRfidOperateType, int iBlockNo, ST_CASH_CONTAINER_LOCATION stContainerLocation, ST_TEST_REQUEST_MSG stTestRequestMsg,
			ST_TEST_FEEDBACK_MSG* pstTestFeedBackMsg, void* pRetStatusData, void* pReadWriteRfidData, DWORD* puiReadWriteDataLenth);
	void CashBoxRfidRwParse(CIpcMsgText* pcIpcRawData, EM_RFID_OPERATE_TYPE* pemRfidOperateType, int* piBlockNo, ST_CASH_CONTAINER_LOCATION* pstContainerLocation,
			void* pReadWriteRfidData, DWORD* puiDataLenth);
//--------------------------------------------------------------------------------------------------------
	/*! \fn CVirObjCoreForMaintence::TicketBoxRfidTest(EM_RFID_OPERATE_TYPE emRfidOperateType, ST_TICKET_CONTAINER_LOCATION stContainerLocation,
	 ST_TEST_REQUEST_MSG stTestRequestMsg, ST_TEST_FEEDBACK_MSG* pstTestFeedBackMsg, void* pRetStatusData, unsigned int* piBoxId)
	 * \brief 			14.票箱RFID测试
	 * \param[in]		emRfidOperateType		Rfid操作类型
	 * \param[in]		stContainerLocation		箱子类型+箱子编号
	 * \param[in]  		stTestRequestMsg		部件测试发起数据
	 * \param[out]		pstTestFeedBackMsg		部件测试反馈数据
	 * \param[out]		pRetStatusData			模块状态结构体
	 * \param[out]		piBoxId					箱子Id
	 * \return			true/false				测试成功/失败
	 * \author 			longjg
	 * \date 			2015－3-24
	 */
	bool TicketBoxRfidTest(EM_RFID_OPERATE_TYPE emRfidOperateType,
			ST_TICKET_CONTAINER_LOCATION stContainerLocation,
			ST_TEST_REQUEST_MSG stTestRequestMsg,
			ST_TEST_FEEDBACK_MSG* pstTestFeedBackMsg, void* pRetStatusData,
			BYTE *pszBoxId);
	void TicketBoxRfidTestParse(CIpcMsgText * pcIpcRawData,
			EM_RFID_OPERATE_TYPE *pemRfidOperateType,
			ST_TICKET_CONTAINER_LOCATION *pstContainerLocation);


	/*! \fn CVirObjCoreForMaintence::TicketBoxRfidRw(EM_RFID_OPERATE_TYPE emRfidOperateType, int iBlockNo, ST_TICKET_CONTAINER_LOCATION stContainerLocation,
	 	 ST_TEST_REQUEST_MSG stTestRequestMsg, ST_TEST_FEEDBACK_MSG* pstTestFeedBackMsg, void* pRetStatusData, void* pReadWriteRfidData, DWORD* puiReadWriteDataLenth);
	 * \brief 			14.票箱RFID读写
	 * \param[in]		emRfidOperateType		Rfid操作类型
	 * \param[in]		iBlockNo				块号0~127块
	 * \param[in]		stContainerLocation		箱子类型+箱子编号
	 * \param[in]  		stTestRequestMsg		部件测试发起数据
	 * \param[out]		pstTestFeedBackMsg		部件测试反馈数据
	 * \param[out]		pRetStatusData			模块状态结构体
	 * \param[in/out]	pReadWriteRfidData		写为入参, 读为出参
	 * \param[in/out]	puiReadWriteDataLenth	写为入参, 读为出参
	 * \return			true/false				测试成功/失败
	 * \author 			longjg
	 * \date 			2017－03-02
	 */
	bool TicketBoxRfidRw(EM_RFID_OPERATE_TYPE emRfidOperateType, int iBlockNo, ST_TICKET_CONTAINER_LOCATION stContainerLocation, ST_TEST_REQUEST_MSG stTestRequestMsg,
			ST_TEST_FEEDBACK_MSG* pstTestFeedBackMsg, void* pRetStatusData, void* pReadWriteRfidData, DWORD* puiReadWriteDataLenth);
	void TicketBoxRfidRwParse(CIpcMsgText* pcIpcRawData, EM_RFID_OPERATE_TYPE* pemRfidOperateType, int* piBlockNo, ST_TICKET_CONTAINER_LOCATION* pstContainerLocation,
			void* pReadWriteRfidData, DWORD* puiDataLenth);
//--------------------------------------------------------------------------------------------------------
	/*! \fn CVirObjCoreForMaintence::ViemingScreenTest(EM_DISPLAY_PARTS_TYPE emDisplayType, EM_ALARM_LIGHT emLightColor
	 ST_TEST_REQUEST_MSG stTestRequestMsg, ST_TEST_FEEDBACK_MSG* pstTestFeedBackMsg, void* pRetStatusData)
	 * \brief 			15.显示器测试
	 * \param[in]		emDisplayType			显示部件类型
	 * \param[in]		emLightColor			显示颜色
	 * \param[in]  		stTestRequestMsg		部件测试发起数据
	 * \param[out]		pstTestFeedBackMsg		部件测试反馈数据
	 * \param[out]		pRetStatusData			模块状态结构体
	 * \return			true/false				测试成功/失败
	 * \author 			longjg
	 * \date 			2015－3-24
	 */
	bool ViemingScreenTest(EM_DISPLAY_PARTS_TYPE emDisplayType,
			EM_ALARM_LIGHT emLightColor, ST_TEST_REQUEST_MSG stTestRequestMsg,
			ST_TEST_FEEDBACK_MSG* pstTestFeedBackMsg, void* pRetStatusData);
	void ViemingScreenTestParse(CIpcMsgText * pcIpcRawData,
			EM_DISPLAY_PARTS_TYPE *pemDisplayType,
			EM_ALARM_LIGHT *pemLightColor);
//---------------------------------------------------------------------------------------------------------
	/*! \fn CVirObjCoreForMaintence::CashPaymentTest(EM_CASH_PAYMENT_FUNC_TYPE emCashPaymentFuncType,
	 ST_TEST_REQUEST_MSG stTestRequestMsg, ST_TEST_FEEDBACK_MSG* pstTestFeedBackMsg, void* pRetStatusData,
	 unsigned int* piPressInCount)
	 * \brief 			16.现金支付测试
	 * \param[in]		emCashPaymentFuncType	现金支付功能类型
	 * \param[in]  		stTestRequestMsg		部件测试发起数据
	 * \param[out]		pstTestFeedBackMsg		部件测试反馈数据
	 * \param[out]		pRetStatusData			模块状态结构体
	 * \param[out]		piPressInCount			实际压箱数量
	 * \return			true/false				测试成功/失败
	 * \author 			longjg
	 * \date 			2015－3-24
	 */
	bool CashPaymentTest(EM_CASH_PAYMENT_FUNC_TYPE emCashPaymentFuncType,
			ST_TEST_REQUEST_MSG stTestRequestMsg,
			ST_TEST_FEEDBACK_MSG* pstTestFeedBackMsg, void* pRetStatusData,
			unsigned int* piPressInCount);
	void CashPaymentTestParse(CIpcMsgText * pcIpcRawData,
			EM_CASH_PAYMENT_FUNC_TYPE *pemCashPaymentFuncType);
//----------------------------------------------------------------------------------------------------------
	/*! \fn CVirObjCoreForMaintence::CashChangeTest(unsigned int iWantChangeCount, ST_CASH_CONTAINER_LOCATION stContainerLocation
	 ST_TEST_REQUEST_MSG stTestRequestMsg, ST_TEST_FEEDBACK_MSG* pstTestFeedBackMsg,
	 void* pRetStatusData, unsigned int* piRealChangeCount)
	 * \brief 			17.现金找零测试
	 * \param[in]		iWantChangeCount		想要测试的找零数量
	 * \param[in]		stContainerLocation		现金类型+箱子类型+箱子编号
	 * \param[in]  		stTestRequestMsg		部件测试发起数据
	 * \param[out]		pstTestFeedBackMsg		部件测试反馈数据
	 * \param[out]		pRetStatusData			模块状态结构体
	 * \param[out]		piRealChangeCount		实际找零数量
	 * \return			true/false				测试成功/失败
	 * \author 			longjg
	 * \date 			2015－3-24
	 */
	bool CashChangeTest(unsigned int iWantChangeCount,
			ST_CASH_CONTAINER_LOCATION stContainerLocation,
			ST_TEST_REQUEST_MSG stTestRequestMsg,
			ST_TEST_FEEDBACK_MSG* pstTestFeedBackMsg, void* pRetStatusData,
			unsigned int* piRealChangeCount);
	void CashChangeTestParse(CIpcMsgText * pcIpcRawData,
			unsigned int *piWantChangeCount,
			ST_CASH_CONTAINER_LOCATION *pstContainerLocation);
//----------------------------------------------------------------------------------------------------------
	/*! \fn CVirObjCoreForMaintence::PrinterTest(EM_PRINTER_CUT_PAPER_OPERAT_TYPE emCutPaperType, ST_TEST_REQUEST_MSG stTestRequestMsg,
	 ST_TEST_FEEDBACK_MSG* pstTestFeedBackMsg, void* pRetStatusData)
	 * \brief 			18.打印机测试
	 * \param[in]		emCutPaperType			打印机切纸操作类型
	 * \param[in]  		stTestRequestMsg		部件测试发起数据
	 * \param[out]		pstTestFeedBackMsg		部件测试反馈数据
	 * \param[out]		pRetStatusData			模块状态结构体
	 * \return			true/false				测试成功/失败
	 * \author 			longjg
	 * \date 			2015－3-24
	 */
	bool PrinterTest(EM_PRINTER_CUT_PAPER_OPERAT_TYPE emCutPaperType,
			ST_TEST_REQUEST_MSG stTestRequestMsg,
			ST_TEST_FEEDBACK_MSG* pstTestFeedBackMsg, void* pRetStatusData);
	void PrinterTestParse(CIpcMsgText * pcIpcRawData,
			EM_PRINTER_CUT_PAPER_OPERAT_TYPE *pemCutPaperType);

	//AG门单步打开关闭测试
	bool AgGcuDoorStepControlTest(EM_GCU_STEP_CONTROL_TYPE emGcuCtrType, ST_TEST_REQUEST_MSG stTestRequestMsg, ST_TEST_FEEDBACK_MSG* pstTestFeedBackMsg, void* pRetStatusData);
	void AgGcuDoorStepControlTestParse(CIpcMsgText* pcIpcSrcData, EM_GCU_STEP_CONTROL_TYPE* pemGcuCtrType);
//----------------------------------------------------------------------------------------------------------
	/*! \fn CVirObjCoreForMaintence::TicketIssueTest(EM_TIU_FUNC_TYPE emTiuFucType, ST_TICKET_CONTAINER_LOCATION stContainerLocation,
	 ST_TEST_REQUEST_MSG stTestRequestMsg, ST_TEST_FEEDBACK_MSG* pstTestFeedBackMsg, void* pRetStatusData)
	 * \brief 			19.车票发行测试
	 * \param[in]		emTiuFucType			车票发行功能类型
	 * \param[in]		stContainerLocation		箱子类型+箱子编号
	 * \param[in]  		stTestRequestMsg		部件测试发起数据
	 * \param[out]		pstTestFeedBackMsg		部件测试反馈数据
	 * \param[out]		pRetStatusData			模块状态结构体
	 * \return			true/false				测试成功/失败
	 * \author 			longjg
	 * \date 			2015－3-24
	 */
	bool TicketIssueTest(EM_TIU_FUNC_TYPE emTiuFucType,
			ST_TICKET_CONTAINER_LOCATION stContainerLocation,
			ST_TEST_REQUEST_MSG stTestRequestMsg,
			ST_TEST_FEEDBACK_MSG* pstTestFeedBackMsg, void* pRetStatusData);
	void TicketIssueTestParse(CIpcMsgText * pcIpcRawData,
			EM_TIU_FUNC_TYPE *pemTiuFucType,
			ST_TICKET_CONTAINER_LOCATION *pstContainerLocation);
//---------------------------------------------------------------------------------------------------------
	/*! \fn CVirObjCoreForMaintence::ElectromotorTest(unsigned int iElectromotorNo, EM_ELCETROMOTOR_ACTION_TYPE emActionType, unsigned int iTurnTime,
	 ST_TEST_REQUEST_MSG stTestRequestMsg, ST_TEST_FEEDBACK_MSG* pstTestFeedBackMsg, void* pRetStatusData)
	 * \brief 			20.电机测试
	 * \param[in]		iElectromotorNo			电动机编号
	 * \param[in]		emActionType			电动机动作类型
	 * \param[in]		iTurnTime				电动机转动时间
	 * \param[in]  		stTestRequestMsg		部件测试发起数据
	 * \param[out]		pstTestFeedBackMsg		部件测试反馈数据
	 * \param[out]		pRetStatusData			模块状态结构体
	 * \return			true/false				测试成功/失败
	 * \author 			longjg
	 * \date 			2015－3-24
	 */
	bool ElectromotorTest(unsigned int iElectromotorNo,
			EM_ELCETROMOTOR_ACTION_TYPE emActionType, unsigned int iTurnTime,
			ST_TEST_REQUEST_MSG stTestRequestMsg,
			ST_TEST_FEEDBACK_MSG* pstTestFeedBackMsg, void* pRetStatusData);
	void ElectromotorTestParse(CIpcMsgText * pcIpcRawData,
			unsigned int *piElectromotorNo,
			EM_ELCETROMOTOR_ACTION_TYPE *pemActionType,
			unsigned int *piTurnTime);
//---------------------------------------------------------------------------------------------------------
	/*! \fn CVirObjCoreForMaintence::ElectromagnetTest(EM_ELECTROMAGNET_TYPE emElectromagnetType, EM_ELECTROMAGNET_ACTION_TYPE emActionType, unsigned int iAttractTime,
	 ST_TEST_REQUEST_MSG stTestRequestMsg, ST_TEST_FEEDBACK_MSG* pstTestFeedBackMsg, void* pRetStatusData)
	 * \brief 			21.电磁铁测试
	 * \param[in]		emElectromagnetType		电磁铁类型
	 * \param[in]		emActionType			电磁铁动作类型
	 * \param[in]		iAttractTime			电磁铁吸合时间
	 * \param[in]  		stTestRequestMsg		部件测试发起数据
	 * \param[out]		pstTestFeedBackMsg		部件测试反馈数据
	 * \param[out]		pRetStatusData			模块状态结构体
	 * \return			true/false				测试成功/失败
	 * \author 			longjg
	 * \date 			2015－3-24
	 */
	bool ElectromagnetTest(EM_ELECTROMAGNET_TYPE emElectromagnetType,
			EM_ELECTROMAGNET_ACTION_TYPE emActionType,
			unsigned int iAttractTime, ST_TEST_REQUEST_MSG stTestRequestMsg,
			ST_TEST_FEEDBACK_MSG* pstTestFeedBackMsg, void* pRetStatusData);
	void ElectromagnetTestParse(CIpcMsgText * pcIpcRawData,
			 EM_ELECTROMAGNET_TYPE *pemElectromagnetType,
			EM_ELECTROMAGNET_ACTION_TYPE *pemActionType,
			unsigned int *piAttractTime);

	//34.版本查询
	bool QueryVersionTest(ST_TEST_REQUEST_MSG stTestRequestMsg, ST_TEST_FEEDBACK_MSG* pstTestFeedBackMsg, list<ST_CSS_VERSION_INFO>  *pVersionRecordList);
//--------------------------------------------------------------------------------------------------------
	/*! \fn CVirObjCoreForMaintence::LoopReadSensorTest(ST_TEST_REQUEST_MSG stTestRequestMsg)
	 * \brief 			22.连续读传感器测试(异步接收数据)
	 * \param[in]  		stTestRequestMsg		部件测试发起数据
	 * \return			无
	 * \author 			longjg
	 * \date 			2015－3-24
	 */
	void LoopReadSensorTest(ST_TEST_REQUEST_MSG stTestRequestMsg);
	void TpuLoopUpdateTest(ST_TEST_REQUEST_MSG stTestRequestMsg);
//--------------------------------------------------------------------------------------------------------
	/*! \fn CVirObjCoreForMaintence::TruLoopRecycleTest(unsigned int iWantRecycleCount, ST_TICKET_CONTAINER_LOCATION stContainerLocation)
	 * \brief 			23.车票回收模块连续回收票卡测试(异步接收数据)
	 * \param[in]  		iWantRecycleCount		想要测试回收的票卡数量(注意：0表示无限回收票卡)
	 * \param[in]		stContainerLocation		箱子类型+箱子编号
	 * \return			无
	 * \author 			longjg
	 * \date 			2015－3-24
	 */
	void TruLoopRecycleTest(unsigned int iWantRecycleCount,
			ST_TICKET_CONTAINER_LOCATION stContainerLocation);
	void TruLoopRecycleTestParse(CIpcMsgText * pcIpcRawData,
			unsigned int *piWantRecycleCount,
			ST_TICKET_CONTAINER_LOCATION *pstContainerLocation);
//--------------------------------------------------------------------------------------------------------
	/*! \fn CVirObjCoreForMaintence::TruLoopRefundTest(unsigned int iWantRefundCount)
	 * \brief 			24.车票回收模块连续退还票卡测试(异步接收数据)
	 * \param[in]  		iWantRefundCount		想要测试的退还票卡数量(注意：0表示无限退还票卡)
	 * \return			无
	 * \author 			longjg
	 * \date 			2015－3-24
	 */
	void TruLoopRefundTest(unsigned int iWantRefundCount);
	void TruLoopRefundTestParse(CIpcMsgText * pcIpcRawData,
			unsigned int *piWantRefundCount);
//---------------------------------------------------------------------------------------------------------
	/*! \fn CVirObjCoreForMaintence::TpuLoopRefundTest(EM_POLLING_CARD_OPERAT_TYPE emPollCardType)
	 * \brief 			25.TPU连续寻卡测试(异步接收数据)
	 * \param[in]  		emPollCardType			寻卡操作类型
	 * \param[in]		bPreRead				出站预读卡标志，true表示启用预读，false表示不预读
	 * \return			无
	 * \author 			longjg
	 * \date 			2015－3-24
	 */
	void TpuLoopPollCardTest(ST_TEST_REQUEST_MSG stTestRequestMsg,
			EM_POLLING_CARD_OPERAT_TYPE emPollCardType, bool bPreRead);
	void TpuLoopPollCardTestParse(CIpcMsgText * pcIpcRawData,
			EM_POLLING_CARD_OPERAT_TYPE *pemPollCardType, bool* pbPreRead);
//---------------------------------------------------------------------------------------------------------
	/*! \fn CVirObjCoreForMaintence::TiuLoopIssueTicketTest(unsigned int iWantIssueCount, ST_TICKET_CONTAINER_LOCATION stTicketboxLocation)
	 * \brief 			26.车票发行模块连续发行票卡测试(异步接收数据)
	 * \param[in]		iWantIssueCount				想要测试发行的票卡数量(注意：0表示无限发行票卡)
	 * \param[in]		stTicketboxLocation			箱子类型+箱子编号
	 * \return			无
	 * \author 			longjg
	 * \date 			2015－3-24
	 */
	void TiuLoopIssueTicketTest(unsigned int iWantIssueCount,
			ST_TICKET_CONTAINER_LOCATION stTicketboxLocation);
	void TiuLoopIssueTicketTestParse(CIpcMsgText * pcIpcSrcData,
			unsigned int *piWantIssueCount,
			ST_TICKET_CONTAINER_LOCATION * pstTicketboxLocation);
//--------------------------------------------------------------------------------------------------------
	/*! \fn CVirObjCoreForMaintence::TiuLoopRecycleTicketTest(unsigned int iWantRecycleCount, ST_TICKET_CONTAINER_LOCATION stTicketboxLocation)
	 * \brief 			27.车票发行模块连续互收票卡测试(异步接收数据)
	 * \param[in]		iWantRecycleCount		想要测试回收的票卡数量(注意：0表示无限回收票卡)
	 * \param[in]		stTicketboxLocation		子类型+箱子编号
	 * \return			无
	 * \author 			longjg
	 * \date 			2015－3-24
	 */
	void TiuLoopRecycleTicketTest(unsigned int iWantRecycleCount,
			ST_TICKET_CONTAINER_LOCATION stTicketboxLocation);
	void TiuLoopRecycleTicketTestParse(CIpcMsgText * pcIpcSrcData,
			unsigned int *iWantRecycleCount,
			ST_TICKET_CONTAINER_LOCATION* pstTicketboxLocation);

	void SetTestMode(bool bSet);
	void SetTestModeParse(CIpcMsgText * pcIpcSrcData, bool * pbSet);
//-------------------------------------------------------------------------------------------------------
	/*! \fn CVirObjCoreForMaintence::CashLoopPressInBoxTest(unsigned int iPressBoxCount, EM_CASH_TYPE emCashType)
	 * \brief 			28.现金模块连续投币压箱测试(异步接收数据)
	 * \param[in]		iPressBoxCount			每次压箱数量
	 * \param[in]		emCashType				现金类型
	 * \return			无
	 * \author 			longjg
	 * \date 			2015－3-24
	 */
	void CashLoopPressInBoxTest(unsigned int iPressBoxCount,
			EM_CASH_TYPE emCashType);
	void CashLoopPressInBoxTestParse(CIpcMsgText * pcIpcRawData,
			unsigned int *piPressBoxCount, EM_CASH_TYPE *pemCashType);
//-------------------------------------------------------------------------------------------------------
	/*! \fn CVirObjCoreForMaintence::CashLoopRefundTest(unsigned int iRefundCount, EM_CASH_TYPE emCashType)
	 * \brief 			29.现金模块连续投币退还测试(异步接收数据)
	 * \param[in]		iRefundCount			每次退还数量
	 * \param[in]		emCashType				现金类型
	 * \return			无
	 * \author 			longjg
	 * \date 			2015－3-24
	 */
	void CashLoopRefundTest(unsigned int iRefundCount, EM_CASH_TYPE emCashType);
	void CashLoopRefundTestParse(CIpcMsgText * pcIpcRawData,
			unsigned int *piRefundCount, EM_CASH_TYPE *pemCashType);
//-------------------------------------------------------------------------------------------------------
	/*! \fn CVirObjCoreForMaintence::CashLoopChangeTest(unsigned int iChangeCount, ST_CASH_CONTAINER_LOCATION stCashBoxLocation)
	 * \brief 			30.现金模块连续投币找零测试(异步接收数据)
	 * \param[in]		iChangeCount			每次找零数量
	 * \param[in]		stCashBoxLocation		现金类型+箱子类型+箱子编号
	 * \return			无
	 * \author 			longjg
	 * \date 			2015－3-24
	 */
	void CashLoopChangeTest(unsigned int iChangeCount,
			ST_CASH_CONTAINER_LOCATION stCashBoxLocation);
	void CashLoopChangeTestParse(CIpcMsgText * pcIpcRawData,
			unsigned int *piChangeCount,
			ST_CASH_CONTAINER_LOCATION *pstCashBoxLocation);
//-------------------------------------------------------------------------------------------------------
	/*! \fn CVirObjCoreForMaintence::GcuLoopGoThroughTest(EM_CON_GO_THROUGH_DIRECTION emGoThroughDirection)
	 * \brief 			31.门模块连续通行测试(异步接收数据)
	 * \param[in]		emGoThroughDirection	通行方向
	 * \return			无
	 * \author 			longjg
	 * \date 			2015－3-24
	 */
	void GcuLoopGoThroughTest(EM_CON_GO_THROUGH_DIRECTION emGoThroughDirection);
	void GcuLoopGoThroughTestParse(CIpcMsgText * pcIpcRawData,
			EM_CON_GO_THROUGH_DIRECTION *pemGoThroughDirection);
//-------------------------------------------------------------------------------------------------------
	/*! \fn CVirObjCoreForMaintence::LoopElectromotorTest(unsigned int iElectromotorNo, EM_ELCETROMOTOR_ACTION_TYPE emActionType,
	 unsigned int iTurnTime, unsigned int iStopTime, ST_TEST_REQUEST_MSG stTestRequestMsg)
	 * \brief 			32.连续电机测试(异步接收数据)
	 * \param[in]		iElectromotorNo			电机编号
	 * \param[in]  		emActionType			动作类型
	 * \param[in]		iTurnTime				转动时间
	 * \param[in]		iStopTime				停止时间
	 * \param[in]		stTestRequestMsg		部件测试发起数据
	 * \return			无
	 * \author 			longjg
	 * \date 			2015－3-24
	 */
	void LoopElectromotorTest(unsigned int iElectromotorNo,
			EM_ELCETROMOTOR_ACTION_TYPE emActionType, unsigned int iTurnTime,
			unsigned int iStopTime, ST_TEST_REQUEST_MSG stTestRequestMsg);
	void LoopElectromotorTestParse(CIpcMsgText * pcIpcRawData,
			unsigned int *piElectromotorNo,
			EM_ELCETROMOTOR_ACTION_TYPE *pemActionType,
			unsigned int *piTurnTime, unsigned int *piStopTime);
//-------------------------------------------------------------------------------------------------------
	/*! \fn CVirObjCoreForMaintence::LoopElectromagnetTest(EM_ELECTROMAGNET_TYPE emElectromagnetType, EM_ELECTROMAGNET_ACTION_TYPE emActionType,
	 unsigned int iAttractTime, unsigned int iReleaseTime, ST_TEST_REQUEST_MSG stTestRequestMsg)
	 * \brief 			33.连续电磁铁测试(异步接收数据)
	 * \param[in]		emElectromagnetType		电磁铁类型
	 * \param[in]		iAttractTime			吸合时间
	 * \param[in]		iReleaseTime			放开时间
	 * \param[in]		stTestRequestMsg		部件测试发起数据
	 * \return			无
	 * \author 			longjg
	 * \date 			2015－3-24
	 */
	void LoopElectromagnetTest(EM_ELECTROMAGNET_TYPE emElectromagnetType,
			unsigned int iAttractTime, unsigned int iReleaseTime,
			ST_TEST_REQUEST_MSG stTestRequestMsg);
	void LoopElectromagnetTestParse(CIpcMsgText * pcIpcRawData,
			EM_ELECTROMAGNET_TYPE* pemElectromagnetType, unsigned int *piAttractTime,
			unsigned int *piReleaseTime);


	/*! \fn TpuParamVersionRequest();
	 * \brief 			Tpu参数版本查询
	 * \param[in]
	 * \param[in]s
	 * \param[in]
	 * \param[in]
	 * \return			无
	 * \author 			shaopf
	 * \date 			2015-06-24
	 */
	bool TpuParamVersionRequest(ST_TEST_REQUEST_MSG stTestRequestMsg,ST_TEST_FEEDBACK_MSG* pstTestFeedBackMsg, void* pRetStatusData, \
			unsigned int *puiParamNum, ST_TPU_PARAM_VERSION_INFO *pstParaminfo);

	/*! \fn CVirObjCoreForMaintence::GetTpuParamVerInfo(ST_TEST_REQUEST_MSG stTestRequestMsg, EM_SLE_PARAM_VERSION_TYPE emParamVersionType, unsigned int iParamNum, unsigned int* puiParamTypeID,
			ST_TPU_PARAM_VERSION_INFO* pstParaminfo, ST_TEST_FEEDBACK_MSG* pstTestFeedBackMsg, void* pRetStatusData);
	 * \brief 			根据参数ID获取TPU内部参数版本信息(此函数可以用来获取某一个或多个)
	 * \param[in]		stTestRequestMsg		部件测试发起数据
	 * \param[in]		emParamVersionType		参数版本类型
	 * \param[in]		iParamNum				参数数目
	 * \param[in]		puiParamTypeID			参数ID集合
	 * \param[out]		pstParaminfo			反馈的TPU参数版本信息
	 * \param[out]		pstTestFeedBackMsg		部件测试反馈数据
	 * \param[out]		pRetStatusData			状态数据
	 * \return			true/false				成功/失败
	 * \author 			longjg
	 * \date 			2015－7-24
	 */
	bool GetTpuParamVerInfo(ST_TEST_REQUEST_MSG stTestRequestMsg, EM_SLE_PARAM_VERSION_TYPE emParamVersionType, unsigned int iParamNum, unsigned int* puiParamTypeID,
			ST_TPU_PARAM_VERSION_INFO* pstParaminfo, ST_TEST_FEEDBACK_MSG* pstTestFeedBackMsg, void* pRetStatusData);
	void GetTpuParamVerInfoParse(CIpcMsgText* pcIpcRawData, EM_SLE_PARAM_VERSION_TYPE* pemParamVersionType, unsigned int* piParamNum, unsigned int* puiParamTypeID);

	/*! \fn CVirObjCoreForMaintence::TpuParamDownload(ST_TEST_REQUEST_MSG stTestRequestMsg, ST_FUNC_INPUT_PARAM stInputParam, ST_TEST_FEEDBACK_MSG* pstTestFeedBackMsg, void* pRetStatusData);
	 * \brief 			TPU参数下载,根据实际情况入参(一些项目也可以通过此处进行软件升级,单项参数升级)
	 * \param[in]		stTestRequestMsg		部件测试发起数据
	 * \param[in]		stInputParam			入参集合(根据实际情况入参)
	 * \param[out]		pstTestFeedBackMsg		部件测试反馈数据
	 * \param[out]		pRetStatusData			状态数据
	 * \return			true/false				成功/失败
	 * \author 			longjg
	 * \date 			2015－7-24
	 */
	bool TpuParamDownload(ST_TEST_REQUEST_MSG stTestRequestMsg, ST_FUNC_INPUT_PARAM stInputParam, ST_TEST_FEEDBACK_MSG* pstTestFeedBackMsg, void* pRetStatusData);
	void TpuParamDownloadParse(CIpcMsgText* pcIpcRawData, ST_FUNC_INPUT_PARAM* pstInputParam);

	/*! \fn CVirObjCoreForMaintence::SoftwareUpdate(ST_TEST_REQUEST_MSG stTestRequestMsg, ST_SOFTWARE_UPDATE_INPUT_PARAM stSoftwareUpdateInputParam, ST_TEST_FEEDBACK_MSG* pstTestFeedBackMsg, void* pRetStatusData);
	 * \brief 			软件升级,根据项目不同需要针对性软件升级
	 * \param[in]		stTestRequestMsg			部件测试发起数据
	 * \param[in]		stSoftwareUpdateInputParam	维修测试软件升级入参结构信息
	 * \param[out]		pstTestFeedBackMsg			部件测试反馈数据
	 * \param[out]		pRetStatusData				状态数据
	 * \return			true/false					成功/失败
	 * \author 			longjg
	 * \date 			2015－7-24
	 */
	bool SoftwareUpdate(ST_TEST_REQUEST_MSG stTestRequestMsg, ST_SOFTWARE_UPDATE_INPUT_PARAM stSoftwareUpdateInputParam, ST_TEST_FEEDBACK_MSG* pstTestFeedBackMsg, void* pRetStatusData);
	void SoftwareUpdateParse(CIpcMsgText* pcIpcRawData, ST_SOFTWARE_UPDATE_INPUT_PARAM* pstSoftwareUpdateInputParam);

	/*! \fn CVirObjCoreForMaintence::TpuAutoUpdate(ST_TEST_REQUEST_MSG stTestRequestMsg, ST_TEST_FEEDBACK_MSG* pstTestFeedBackMsg, void* pRetStatusData);
	 * \brief 			Tpu自动一键升级(不分AG/TVM),直接调用项目化进行参数和软件自动对比升级
	 * \param[in]		stTestRequestMsg			部件测试发起数据
	 * \param[out]		pstTestFeedBackMsg			部件测试反馈数据
	 * \param[out]		pRetStatusData				状态数据
	 * \return			true/false					成功/失败
	 * \author 			longjg
	 * \date 			2015－7-24
	 */
	bool TpuAutoUpdate(ST_TEST_REQUEST_MSG stTestRequestMsg, ST_TEST_FEEDBACK_MSG* pstTestFeedBackMsg, void* pRetStatusData);
	//-------------------------------------------------------------------------------------------------------
	//循环测试结束
	void LoopTestEnd();

	/*! \fn SystemSettingRequest
	 * \brief 			系统设置请求
	 * \param[in]		int iParamType
	 * \param[in]		int iParamKey    参数类型
	 * \param[in]		const char * pszParamValue    参数VALUE
	 * \param[out]		bool * bExeSuccess    执行结果
	 * \return			无
	 * \author 			wangzp
	 * \date 			2015－04-13
	 */
	bool SystemSettingRequest(int iParamType, int iParamKey, const char * pszParamValue, bool * bExeSuccess);

	/*! \fn SystemSettingRequestParse
	 * \brief 			系统设置请求解析
	 * \param[in]		CIpcMsgText * pcIpcMsgText    IPC文本
	 * \param[out]		int * piParamType    参数类型
	 * \param[out]		int * piParamKey     参数ID
	 * \param[out]		int * piParamValueLen    参数VALUE长度
	 * \param[out]		char * pszParamValue     参数VALUE
	 * \return			无
	 * \author 			wangzp
	 * \date 			2015－04-13
	 */
	void SystemSettingRequestParse(CIpcMsgText * pcIpcMsgText, int * piParamType, int * piParamKey, int * piParamValueLen, char * pszParamValue);

	/*! \fn AllStatusRequest
	 * \brief 			系统全状态请求
	 * \param[in]		无
	 * \return			无
	 * \author 			wangzp
	 * \date 			2015－04-13
	 */
	bool AllStatusRequest();

	/*! \fn RunModeCMDNotify
	 * \brief 			运营模式设置
	 * \param[in]		BYTE cRunMode    运营模式
	 * \param[out]		bool * pResult   执行结果
	 * \return			无
	 * \author 			wangzp
	 * \date 			2015－04-13
	 */
	//bool RunModeCMDNotify(BYTE cRunMode, bool * pResult);
	bool RunModeCMDNotify(ST_COMMON_RUN_MODE stRunMode, bool * pResult);

	/*! \fn RunModeCMDNotifyParse
	 * \brief 			运营模式设置解析
	 * \param[in]		const CIpcMsgText * pcIpcRawData
	 * \param[out]		BYTE* pcRunMode
	 * \return			无
	 * \author 			wangzp
	 * \date 			2015－04-13
	 */
	//	void RunModeCMDNotifyParse(const CIpcMsgText * pcIpcRawData,BYTE* pcRunMode);
	void RunModeCMDNotifyParse(const CIpcMsgText * pcIpcRawData,ST_COMMON_RUN_MODE* pstRunMode);

	bool VoucherPrint(DWORD uiUdsn, DWORD uiVoucherType);

	bool FlushCommand(bool bFlushCoin, bool bFlushBill, bool bFlushTicket);

	bool UnitInitBiz(EM_SLE_UNIT_TYPE emSleUnitType, int iTimeOut);
	void UnitInitBizParse(CIpcMsgText* pcIpcRawData, EM_SLE_UNIT_TYPE* pemSleUnitType);

	//用于各类箱子上升下降请求(非测试应用请求)

	/*! \fn CVirObjCoreForMaintence::ControlBoxUpDownBiz(EM_SLE_UNIT_TYPE emSleUnitType, ST_CASH_CONTAINER_LOCATION stBoxInfo, EM_CONTAINER_OPERATION_TYPE emControlBoxUpDown, int iTimeOut);
	 * \brief 			控制各类箱子上升下降
	 * \param[in]		emSleUnitType				部件类型
	 * \param[in]		stBoxInfo					具体的箱子信息	//注意：对于票箱, 入参信息, stBoxInfo.emCashType = 0, stBoxInfo.emCashboxType 需要转换成 EM_TICKET_CONTAINER_TYPE类型
	 * \param[in]		emControlBoxUpDown			上升下降类型
	 * \param[in]		iTimeOut					超时时间
	 * \return			true/false					成功/失败
	 * \author 			longjg
	 * \date 			2016-01-03
	 */
	bool ControlBoxUpDownBiz(EM_SLE_UNIT_TYPE emSleUnitType, ST_CASH_CONTAINER_LOCATION stBoxInfo, EM_CONTAINER_OPERATION_TYPE emControlBoxUpDown, int iTimeOut);
	void ControlBoxUpDownBizParse(CIpcMsgText* pcIpcRawData, EM_SLE_UNIT_TYPE* pemSleUnitType, ST_CASH_CONTAINER_LOCATION* pstBoxInfo, EM_CONTAINER_OPERATION_TYPE* pemControlBoxUpDown, int* piTimeOut);

	/*! \fn CVirObjCoreForMaintence::ContainerChangeRequest(map<DWORD, ST_CONTAINER_DETAIL_INFO>* pstContainerDetailInfoMap);
	 * \brief 			容器更换请求
	 * \param[out]  	pstContainerDetailInfoMap	容器更换详细记录信息
	 * \return 			请求结果						true/false 	成功/失败
	 * \author			longjg
	 * \date			2017-03-27
	*/
	bool ContainerChangeRequest(map<DWORD, ST_CONTAINER_DETAIL_INFO>* pstContainerDetailInfoMap);

	/*! \fn CVirObjCoreForMaintence::ContainerOperationRequest(EM_SLE_UNIT_TYPE emSleUnitType, ST_CONTAINER_LOCATION stContainerLocation, EM_CONTAINER_OPERATION_TYPE emOperType, int iOperTimeOut, EM_CONTAINER_OPERATION_RESULT* pemOperResult);
	 * \brief 			容器操作请求
	 * \param[in]  		emSleUnitType				部件类型
	 * \param[in]  		stContainerLocation			部件位置
	 * \param[in]		emOperType					操作类型
	 * \param[in]		iOperTimeOut				操作超时时间(单位:秒)
	 * \param[out]		pemOperResult				操作结果(超时/失败/成功)
	 * \return 			请求结果						true/false 	成功/失败
	 * \author			longjg
	 * \date			2017-03-27
	*/
	bool ContainerOperationRequest(EM_SLE_UNIT_TYPE emSleUnitType, ST_CONTAINER_LOCATION stContainerLocation, EM_CONTAINER_OPERATION_TYPE emOperType, int iOperTimeOut, EM_CONTAINER_OPERATION_RESULT* pemOperResult);
	void ContainerOperationRequestParse(CIpcMsgText* pcIpcRawData, EM_SLE_UNIT_TYPE* pemSleUnitType, ST_CONTAINER_LOCATION* pstContainerLocation, EM_CONTAINER_OPERATION_TYPE* pemOperType, int* piOperTimeOut);
	//容器更换结束请求
	bool ContainerChangeEndRequest(map<DWORD, ST_CONTAINER_DETAIL_INFO> stContainerDetailInfoMap);
	//容器更换结束请求解析
	void ContainerChangeEndRequestParse(CIpcMsgText* pcIpcRawData, map<DWORD, ST_CONTAINER_DETAIL_INFO>* pstContainerDetailInfoMap);
private:
	bool CommonTestSyncSend(int iTimeOut, ST_TEST_REQUEST_MSG stTestRequestMsg,
			ST_TEST_FEEDBACK_MSG* pstTestFeedBackMsg, void* pRetStatusData);
	bool CommonTestSyncSend(int *pszParam, int iTimeOut,
			ST_TEST_FEEDBACK_MSG* pstTestFeedBackMsg, void* pRetStatusData);
	bool CommonTestSyncSend(int *pszParam, int iTimeOut,
			ST_TEST_FEEDBACK_MSG* pstTestFeedBackMsg, void* pRetStatusData,
			unsigned int *piValue);
	bool CommonTestSyncSend(int *pszParam, int iTimeOut,
			ST_TEST_FEEDBACK_MSG* pstTestFeedBackMsg, void* pRetStatusData,
			BYTE *pszBoxId);
	bool CommonTestSyncSend(int *pszParam, int iTimeOut,
			ST_TEST_FEEDBACK_MSG* pstTestFeedBackMsg, void* pRetStatusData,
			unsigned int *piValue ,BYTE *pszData);

	void LoopTestAsyncSend(int *pszParam);

	/*! \fn CVirObjCoreForMaintence::UnitSoftUpdate(ST_TEST_REQUEST_MSG stTestRequestMsg, ST_TEST_FEEDBACK_MSG* pstTestFeedBackMsg, void* pRetStatusData)
	 * \brief 			部件软件升级
	 * \param[in]  		stTestRequestMsg		部件测试发起数据
	 * \param[out]		pstTestFeedBackMsg		部件测试反馈数据
	 * \param[out]		pRetStatusData			模块状态结构体
	 * \return			true/false				测试成功/失败
	 * \author 			wangzp
	 * \date 			2015－3-24
	 */
	bool UnitSoftUpdate(ST_TEST_REQUEST_MSG stTestRequestMsg,
			ST_TEST_FEEDBACK_MSG* pstTestFeedBackMsg, void* pRetStatusData);



private:
	CIpcManager *m_pCManager; //发送IPC消息 ，接收IPC消息管理器
};

#endif /* VIROBJTVMTVMCOREFORMAINTENCE_H_ */
