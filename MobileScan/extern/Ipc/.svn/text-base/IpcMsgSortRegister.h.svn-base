/*! \file   IpcMsgSortRegister.h
 *  \version 1.0
 *  \brief  消息分拣注册器
 *  \author 薛峰
 *  \date   2013－10－24
 *  \par    修改记录:
 *  \par
 *  \par
 */
#ifndef IPCMSGSORTREGISTER_H_
#define IPCMSGSORTREGISTER_H_

#include "IpcMsgSortContainer.h"
#include "IpcManager.h"
#include "IpcMsgText.h"
#include <stdio.h>
#include <string.h>
#include <sys/mman.h>
#include <list>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <map>
using namespace std;

/*! \class CIpcMsgSortRegister
* \version	1.0
* \brief  	消息分拣注册器 实现了消息ID与类指针的映射关系，可以一对多
* \author	薛峰
* \date		2013－10－24
* \par		修改记录
* \par
*/
class CIpcMsgSortRegister
{
public:
	/*! \fn CIpcMsgSortRegister::~CIpcMsgSortRegister()
	 * \brief 		析构函数
	 * \author 		薛峰
	 * \date 		2013－10－24
	*/
	virtual ~CIpcMsgSortRegister();

	/*! \fn CIpcMsgSortRegister::CIpcMsgSortRegister* GetInstance()
	 * \brief 		获取消息分拣器句柄，采用单例模式
	 * \return 		消息分捡器句柄
	 * \author 		薛峰
	 * \date 		2013－10－24
	*/
	static CIpcMsgSortRegister* GetInstance();

	/*! \fn CIpcMsgSortRegister::RegistSortingMsg(int iMsgID, CIpcMsgSortContainer* pCMsgContainer)
	 * \brief 		消息注册，将映射关系添加到multimap结构中
	 * \param[in] 	iMsgID 消息ID
	 * \param[in]	iObjPtrAddr 对应类对象指针地址值
	 * \return 		0
	 * \author 		薛峰
	 * \date 		2013－10－24
	*/
	int RegistSortingMsg(int iMsgID, CIpcMsgSortContainer* pCMsgContainer);

	/*! \fn CIpcMsgSortRegister::UnRegistSortingMsg(int iMsgID, CIpcMsgSortContainer* pCMsgContainer)
	 * \brief 		取消消息注册，将映射关系从multimap结构中删除
	 * \param[in] 	iMsgID 消息ID
	 * \param[in]	iObjPtrAddr 对应类对象指针地址值
	 * \return 		成功：0 失败 -1
	 * \author 		薛峰
	 * \date 		2013－10－24
	*/
	int UnRegistSortingMsg(int iMsgID, CIpcMsgSortContainer* pCMsgContainer);

	/*! \fn CIpcMsgSortRegister::GetSortContainer(int iMsgID, list<CIpcMsgSortContainer> * pMatchList)
	 * \brief 		根据消息ID获取对应的对象指针链表
	 * \param[in] 	iMsgID 消息ID
	 * \param[out]  pMatchList 获取到的链表地址
	 * \return 		成功：true 失败：false
	 * \author 		薛峰
	 * \date 		2013－10－24
	*/
	bool GetSortContainer(int iMsgID, list<CIpcMsgSortContainer *> * pMatchList);
private:
	/*! \fn CIpcMsgSortRegister::CIpcMsgSortRegister
	 * \brief 		构造函数
	 * \author 		薛峰
	 * \date 		2013－10－24
	*/
	CIpcMsgSortRegister();
	/*!<类对象句柄*/
	static CIpcMsgSortRegister *instance;
	/*!<内部MultiMap存储结构*/
	multimap<int,CIpcMsgSortContainer*> m_ListContainer;

};

#endif /* IPCMSGSORTREGISTER_H_ */
