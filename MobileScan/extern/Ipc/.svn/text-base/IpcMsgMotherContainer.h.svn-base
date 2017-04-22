/*! \file   IpcMsgMotherContainer.h
 *  \version 1.0
 *  \brief  母消息容器
 *  \author wugang
 *  \date   2014-08-05
 *  \par    修改记录:
 */
#ifndef CIPCMSGMOTHERCONTAINER_H_
#define CIPCMSGMOTHERCONTAINER_H_

#include "CLogOper2.h"
#include "IpcMsgSortContainer.h"
#include "IpcMsgChildContainer.h"
#include "IpcMsgText.h"
#include <list>

typedef enum
{
	EM_MOTHER_CONTAINER_TYPE_SEIZE = 0x00,/*抢占类型*/
	EM_MOTHER_CONTAINER_TYPE_QUEUE	= 0x01,	/*排队类型*/
}EM_MOTHER_CONTAINER_TYPE;

using namespace std;

class CIpcMsgMotherContainer : public CIpcMsgSortContainer
{
public:
	CIpcMsgMotherContainer(EM_MOTHER_CONTAINER_TYPE emType, CLogOper2 * pLog);
	virtual ~CIpcMsgMotherContainer();

	void AddChild(CIpcMsgChildContainer * pcIpcMsgChildContainer);
	void PushMsg (CIpcMsgText * pMsgText);//重载PushMsg，所有消息将被送入这个active容器；否则，所有消息将被送入母容器；当收到某个Child的入口消息时，将该消息送入该子容器，并active该Child
	void Inactivate();  //结束活跃状态，由业务容器调用
	bool IsActive();	//返回是否活跃状态
	bool ChangeActiveChild(CIpcMsgText * pMsgText);	//先导业务应用，切换活动业务
	CIpcMsgText * GetActiveIpcMsgText();
protected:
	bool QueryConcernedMsgIDInChild(int iMsgID, CIpcMsgChildContainer * pChildContainer);
	bool QueryEntryMsgIDInChild(int iMsgID, CIpcMsgChildContainer * pChildContainer);
	CIpcMsgChildContainer * m_pcActiveChild;
	list< CIpcMsgChildContainer *> m_Childlist; //子消息容器对象的链表

	CIpcMsgText m_cActiveIpcMsgText;
	CLogOper2 * m_pLog;
	EM_MOTHER_CONTAINER_TYPE m_emContainerType;
	pthread_mutex_t m_pcActiveChildMutex;
};

#endif /* CIPCMSGMOTHERCONTAINER_H_ */
