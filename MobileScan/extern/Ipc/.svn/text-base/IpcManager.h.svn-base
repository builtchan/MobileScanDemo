/*! \file   IpcManager.h
 *  \version 1.0
 *  \brief  基于消息队列API的同步通信和异步通信,采用单例模式
 *  \author 吴刚
 *  \date   2013－10－15
 *  \par    修改记录:
 *  \par
 *  \par
 */

#ifndef IPCMANAGER_H_
#define IPCMANAGER_H_
#include "IpcMsgText.h"
#include <pthread.h>
#include <list>
#include <map>
#include <semaphore.h>


using namespace std;

class CIpcMsgQueue;

/*! \class CIpcMsgText
* \version	1.0
* \brief  	基于消息队列API的同步通信和异步通信,采用单例模式
* \author	吴刚
* \date		2013－10－30
* \par		修改记录
* \par
*/
class CIpcManager
{
public:
	/*! \fn CIpcManager::~CIpcManager()
	 * \brief 		析构函数
	 * \author 		吴刚
	 * \date 		2013－10－30
	*/
	virtual ~CIpcManager();

	/*! \fn static CIpcManager * CIpcManager::GetInstance()
	 * \brief 		获取实例
	 * \return  	CIpcManager对象指针
	 * \author 		吴刚
	 * \date 		2013－10－30
	*/
	static CIpcManager * GetInstance();

	/*! \fn CIpcManager::Init(EM_IPC_KEY emIpcKey)
	 * \brief 		创建监听线程;创建初始化消息通信API即CMsgQueue
	 * \param[in] 	emIpcKey 消息队列键值，系统定义枚举值
	 * \return  	成功：0
	 * \author 		吴刚
	 * \date 		2013－10－30
	*/
	int Init(EM_IPC_KEY emIpcKey);

	/*! \fn SyncCall(EM_IPC_KEY emIpcKey, CIpcMsgText *pCIpcMsgText, int iTimeOut, CIpcMsgText *pCIpcMsgTextResponse)
	 * \brief 		同步调用
	 * \param[in] 	emIpcKey 消息队列键值，系统定义枚举值
	 * \param[in]	pCIpcMsgText 消息文本
	 * \param[in]   iTimeOut 超时时间
	 * \param[in]   pCIpcMsgTextResponse 反馈消息
	 * \return		成功：true 失败：false
	 * \author 		吴刚
	 * \date 		2013－10－30
	*/
	bool SyncCall(EM_IPC_KEY emIpcKey, CIpcMsgText *pCIpcMsgText, int iTimeOut, CIpcMsgText *pCIpcMsgTextResponse);

	/*! \fn CIpcManager::AsyncCall(EM_IPC_KEY emIpcKey, CIpcMsgText *pCIpcMsgText)
	 * \brief 		异步调用
	 * \param[in] 	emIpcKey 消息队列键值，系统定义枚举值
	 * \param[in]	pCIpcMsgText 消息文本
	 * \author 		吴刚
	 * \date 		2013－10－30
	*/
	bool AsyncCall(EM_IPC_KEY emIpcKey, CIpcMsgText *pCIpcMsgText);

	/*! \fn CIpcManager::Answer(EM_IPC_KEY emIpcKey, CIpcMsgText *pCIpcMsgText)
	 * \brief 		异步有应答
	 * \param[in] 	emIpcKey 消息队列键值，系统定义枚举值
	 * \param[in]	pCIpcMsgText 消息文本
	 * \author 		吴刚
	 * \date 		2013－10－30
	*/
	bool Answer(EM_IPC_KEY emIpcKey, CIpcMsgText *pCIpcMsgText);

	/*! \fn CIpcManager::NoAnswerCall(EM_IPC_KEY emIpcKey, CIpcMsgText *pCIpcMsgText)
	 * \brief 		异步无应答
	 * \param[in] 	emIpcKey 消息队列键值，系统定义枚举值
	 * \param[in]	pCIpcMsgText 消息文本
	 * \author 		吴刚
	 * \date 		2013－10－30
	*/
	bool NoAnswerCall(EM_IPC_KEY emIpcKey, CIpcMsgText *pCIpcMsgText);
private:

	/*! \fn CIpcManager::CIpcManager()
	 * \brief 		构造函数
	 * \author 		吴刚
	 * \date 		2013－10－30
	*/
	CIpcManager();
	/*!<消息队列底层API*/
	CIpcMsgQueue * m_pIpcMsgQueue;
	/*!<句柄*/
	static CIpcManager * m_pCIpcManager;

	/*! \fn CIpcManager::Destroy()
	 * \brief 		关闭监听线程
	 * \return  	0
	 * \author 		吴刚
	 * \date 		2013－10－30
	*/
	int Destroy();

	/*! \fn CIpcManager::SendIpcMsgText(EM_IPC_KEY emIpcKey, CIpcMsgText *pCIpcMsgText)
	 * \brief 		发送消息
	 * \param[in] 	emIpcKey 消息队列键值，系统定义枚举值
	 * \param[in]	pCIpcMsgText 消息内容
	 * \return      成功：true 失败：false
	 * \author 		吴刚
	 * \date 		2013－10－30
	*/
	bool SendIpcMsgText(EM_IPC_KEY emIpcKey, CIpcMsgText *pCIpcMsgText);

	/*! \fn CIpcManager::MsgListenThread(void*pParam)
	 * \brief 		消息监听线程,用于监听异步反馈信息或者通知报文
	 * \param[in] 	pParam 对象指针
	 * \return		0
	 * \author 		吴刚
	 * \date 		2013－10－30
	*/
	static void* MsgListenThread(void*pParam);

	/*!<消息队列key*/
	EM_IPC_KEY m_emIpcKey;

	/*!<当前处理的同步消息ID*/
	int m_iCurrentSyncMsgID;

	/*!<同步等待状态,标识当前同步处理状态，1在正处理同步信息，0没有正在处理的同步信息。*/
	bool m_bSyncCallState;

	/*!<同步调用等待信号*/
	sem_t m_iSyncCallWaitSignal;
private:
	/*!<线程退出标志*/
	bool m_bEnqClose;

	/*!<线程号*/
	pthread_t m_idThread;

	/*!<同步反馈内容*/
	CIpcMsgText m_cSyncMsgText;

	/*!<内部map，键值-CIpcMsgQueue */
	map<int, CIpcMsgQueue> m_mapIpcMsgQueue;
};

#endif /* IPCMANAGER_H_ */
