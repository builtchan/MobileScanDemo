/*! \file ComApi.h
 *  \brief ComApi串口通信类定义
 
 *  包含对串口的打开、设置、写、读、清空、关闭、锁操作
 * \version 1.0
 * \author 杨爽
 * \date 2009-8-19
*/

#ifndef COMAPI_
#define COMAPI_

#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<errno.h>
#include<fcntl.h>
#include<sys/file.h>
#include<unistd.h>
#include<termios.h>
#include<stdlib.h>
#include<pthread.h>
#include<stdlib.h>
#include<sys/time.h>

//#define ZERO		 	 0
#define FUN_OK		 1
#define FUN_ERROR    -1
#define FUN_TIMEOUT	-2
#define FUN_COUNT_ERROR	-3
#define WRITE_LOCK	6
#define READ_LOCK	4
#define UNLOCK		5
#define LOCK_TIMEOUT	100
#define RW			0666//可读可写
#define CLEAR_READBUF	1
#define CLEAR_WRITEBUF	2
#define CLEAR_ALLBUF		3

/*！\typedef enum ClearType
 * \brief 定义了一个枚举量，用于选择清空串口的类型

 *可供选择的类型有：	ClearReadBuf,清空读缓冲区
					ClearWriteBuf,清空写缓冲区
					ClearAllBuf,清空全部缓冲区
*/
 enum ClearType
{
	ClearReadBuf,
	ClearWriteBuf,
	ClearAllBuf
};

/*！\typedef enum LockType
 * \brief 定义了一个枚举量，用于选择上锁解锁的类型

 *可供选择的类型有：	ReadLock,读入锁
					WriteLock,写入锁
					UnLock,解锁
*/
 enum LockType
{
	ReadLock=F_RDLCK,
	WriteLock=F_WRLCK,
	UnLock=F_UNLCK
};
#ifdef  __cplusplus   
extern "C" 
{  
/*！ \class CComApi
 *  \brief 定义了串口通信的协议
 
 	 成员变量：	int iOpenPort;打开的串口标志
 	 			char szComApiLog[128];
				CLogOper stCComApiLog;ComApi的日志
				pthread_mutex_t g_hComApiMutex;串口通讯互斥量
 	 			int ClearPort(enum ClearType iType);清空串口缓存数据
				int OpenPort(char*cDev);打开串口
				int SetPort(int iSpeed,int iBites,char cEvent,int iStop);设置串口
				int WritePort(char*TxBuf,int iCount,int iTimeout));写串口操作
				int ReadPort(char*RxBuf,int iCount,int iTimeout);读串口操作
				int ClosePort();关闭串口
				int LockSet(enum LockType iType);	设置写入锁，避免数据冲突	
 *  \version	杨爽
 *  \date	2009-8-19
*/
class CComApi
{

public: 
	CComApi();/*!<构造函数*/
	~CComApi();/*!<析构函数*/

	int OpenPort(char*cDev);/*!打开串口*/
	int ClosePort();/*!关闭串口*/

	int SetPort(int iSpeed,int iBites,char cEvent,int iStop);/*!设置串口*/

	int ClearPort(enum ClearType iType);/*!清空串口缓存*/


	int WritePort( char*TxBuf,int iCount,int iTimeout);/*!串口写操作*/

	/*  函数说明（last edit at 20130801 by NN）:
	 *    读取指定长度(iCount)的数据包至 RxBuf中， 直到指定的超时（iTimeout, ms）为止;
	 *
	 *  参数说明(经20130801 by LMG 验证，)：
	 *     int iTimeout 单位为毫秒(ms)；
	 **/
	int ReadPort(char* RxBuf,int iCount,int iTimeout);/*!串口读操作*/

	int ReadPort(char* RxBuf,int iCount,int iTimeout, bool bIsNeedLockMutexFlag);/*!串口读操作*/

	//RSR232动态库中，引用了该函数
	int InitClockTickTimeOut(timespec * pTimeOutClockTick,unsigned long ulTimeSpecOfms);

	//RSR232动态库中，引用了该函数
	bool CheckClockTickTimeOut(timespec * pTimeOutClockTick);


private:
	int iOpenCom;/*!打开的串口标志*/
	pthread_mutex_t g_hComApiMutex;/*!串口通讯互斥量*/
	bool bIsNeedLockMutexFlag; //add by limg at 20121126:
};
}
#endif 
#endif /*COMAPI_*/



