/*
 * VirObjCommForMaintence.h
 *
 *  Created on: Aug 12, 2015
 *      Author: root
 */

#ifndef VIROBJCOMMFOROPER_H_
#define VIROBJCOMMFOROPER_H_
#include "VirObjectBase.h"
#include "ipcpublic.h"
#include "IpcManager.h"
#include "IpcMsgSortContainer.h"
#include "IpcMsgText.h"
class CVirObjCommForMaintence:public CVirObjectBase
{
public:
	CVirObjCommForMaintence();
	virtual ~CVirObjCommForMaintence();
	/*
	 * 通知SleComm, 维修界面通过U盘导入TPU参数通知
	 */
	void TpuParamImportNotifyByUDisk();
	void OperLoginOrLogOutNotify(ST_LOGIN_REQUEST_INFO stLoginInfo, EM_OPERATOR_NOTIFY_TYPE emOperatorNotifyType);
	void OperLoginOrLogOutNotifyParse(CIpcMsgText * pcIpcRawData, ST_LOGIN_REQUEST_INFO* pstLoginInfo, EM_OPERATOR_NOTIFY_TYPE* pemOperatorNotifyType);
};
#endif /* VIROBJCOMMFOROPER_H_ */
