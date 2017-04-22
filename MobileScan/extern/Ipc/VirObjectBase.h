/*! \file   VirObjectBase.h
 *  \version 1.0
 *  \brief  虚拟对象工厂
 *  \author 张保兵
 *  \date   2013－10－11
 *  \par    修改记录:
 *  \par
 *  \par
*/
#ifndef VIROBJECTBASE_H_
#define VIROBJECTBASE_H_
#include "ipcpublic.h"
#include "IpcMsgText.h"

#define SYN_CALL_MAX_TIME    3*60*1000     //added by wangzp
#define SYN_CALL_COMMON_TIME 60*1000     //added by wangzp
/*! \class CVirObjectBase
* \version	1.0
* \brief  	虚拟对象工厂类
* \author	张保兵
* \date		2013－10－11
* \par		修改记录
* \par
*/

class CVirObjectBase
{
public:
	CVirObjectBase(EM_IPC_KEY key);/*!<构造函数*/
	virtual ~CVirObjectBase();/*!<析构函数*/
	bool SyncCall(CIpcMsgText *pCIpcMsgText, int iTimeOut, CIpcMsgText *pCIpcMsgTextResponse);
	bool AsyncCall( CIpcMsgText *pCIpcMsgText);
	bool Answer(CIpcMsgText *pCIpcMsgText);
	bool NoAnswerCall(CIpcMsgText *pCIpcMsgText);

	bool CustomSyncRequest(int iMsgID, list<ST_IPCMSG_ADDITIONAL_RECORD> *pParamRecordList, list<ST_IPCMSG_ADDITIONAL_RECORD> *pResponseDataList, int iTimeoutImMs);
	bool CustomSyncRequest(int iMsgID, const ST_IPCMSG_ADDITIONAL_RECORD *pParamData, ST_IPCMSG_ADDITIONAL_RECORD *pResponseData, int iTimeoutImMs);

	bool CustomAsyncNotify(int iMsgID, list<ST_IPCMSG_ADDITIONAL_RECORD> *pParamRecordList);
	bool CustomAsyncNotify(int iMsgID, const ST_IPCMSG_ADDITIONAL_RECORD *pParamData);

protected:
	EM_IPC_KEY m_emKey;


};

#endif /* VIROBJECTBASE_H_ */
