/*
 * VirObjBomUIToBomCore.h
 *
 *  Created on: Dec 12, 2016
 *      Author: root
 */

#ifndef VIROBJBOMUITOBOMCORE_H_
#define VIROBJBOMUITOBOMCORE_H_

#include "BomIpcMsgDef.h"
#include "VirObjectBase.h"
#include "IpcManager.h"
#include "IpcMsgSortContainer.h"
#include "IpcMsgText.h"

class CVirObjBomUIToBomCore :public CVirObjectBase
{
public:
	CVirObjBomUIToBomCore();
	virtual ~CVirObjBomUIToBomCore();

	bool BOMSynUIToCore(const ST_BOM_IPCMSG_INFO stIpcMsgInfo,ST_TEXT_DATA *pstData);//UI给core发同步消息

	void BOMAnswerToCore(const ST_BOM_IPCMSG_INFO stIpcMsgInfo);//同步应答

	void BOMAsynUIToCore(const ST_BOM_IPCMSG_INFO stIpcMsgInfo);//UI给core发异步消息

};



#endif /* VIROBJBOMUITOBOMCORE_H_ */
