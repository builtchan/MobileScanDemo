/*
 * VirObjBomCoreToBomUI.h
 *
 *  Created on: Dec 12, 2016
 *      Author: root
 */

#ifndef VIROBJBOMCORETOBOMUI_H_
#define VIROBJBOMCORETOBOMUI_H_

#include "BomIpcMsgDef.h"
#include "VirObjectBase.h"
#include "IpcManager.h"
#include "IpcMsgSortContainer.h"
#include "IpcMsgText.h"

class CVirObjBomCoreToBomUI :public CVirObjectBase
{
public:
	CVirObjBomCoreToBomUI();
	virtual ~CVirObjBomCoreToBomUI();

	bool BOMSynCoreToUI(const ST_BOM_IPCMSG_INFO stIpcMsgInfo,ST_TEXT_DATA *pstData);//core给UI发同步消息

	void BOMAnswerToUI(const ST_BOM_IPCMSG_INFO stIpcMsgInfo);//同步应答

	void BOMAsynCoreToUI(const ST_BOM_IPCMSG_INFO stIpcMsgInfo);//core给UI发异步消息

	void BOMDialogCoreToUI(const ST_BOM_IPCMSG_INFO stIpcMsgInfo);//core给UI发异步消息

};



#endif /* VIROBJBOMCORETOBOMUI_H_ */
