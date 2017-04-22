/*! \file   IpcMsgSortContainer.h
 *  \version 1.0
 *  \brief  消息分拣器,用LIST存储消息文本
 *  \author 薛峰
 *  \date   2013－10－25
 *  \par    修改记录:
 *  \par
 *  \par
 */
#ifndef IPCMSGSORTCONTAINER__H_
#define IPCMSGSORTCONTAINER__H_

#include "IpcMsgText.h"
#include <list>
#include <pthread.h>
#include <semaphore.h>

using namespace std;

/*! \class CIpcMsgSortContainer
* \version	1.0
* \brief  	消息分拣器,用LIST存储消息文本
* \author	薛峰
* \date		2013－10－25
* \par		修改记录
* \par
*/
class CIpcMsgSortContainer
{
public:
	/*! \fn CIpcMsgSortContainer::CIpcMsgSortContainer()
	 * \brief 		构造函数
	 * \author 		薛峰
	 * \date 		2013－10－25
	*/
	CIpcMsgSortContainer();

	/*! \fn CIpcMsgSortContainer::~CIpcMsgSortContainer()
	 * \brief 		析构函数
	 * \author 		薛峰
	 * \date 		2013－10－25
	*/
	virtual ~CIpcMsgSortContainer();

	/*! \fn CIpcMsgSortContainer::PushMsg(CIpcMsgText * pMsgText)
	 * \brief 		将一条消息文本存入内部链表，尾部添加
	 * \param[in] 	pMsgText 消息文本
	 * \return 		无
	 * \author 		薛峰
	 * \date 		2013－10－25
	*/
	virtual void PushMsg(CIpcMsgText * pMsgText);

	/*! \fn CIpcMsgSortContainer::PopMsg(CIpcMsgText * pMsgText)
	 * \brief 		从内部链表取出一条消息文本，头部取出
	 * \param[out]  pMsgText 取出的消息
	 * \return 		成功：true 失败：false
	 * \author 		薛峰
	 * \date 		2013－10－25
	*/
	virtual bool PopMsg(CIpcMsgText * pMsgText);
public:
	sem_t m_semMsgNotifySignal;//消息通知信号

protected:
	/*!<消息报文对象的链表（消息报文）*/
	list<CIpcMsgText> m_List;

	/*!<互斥锁*/
	pthread_mutex_t m_Mutex;
};

#endif /* IPCMSGSORTCONTAINER__H_ */


