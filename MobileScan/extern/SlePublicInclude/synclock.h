/*
 * Copyright (c) 2011 中国软件与技术服务股份有限公司
 * All right reserved.
 * 
 * 文件名称：synclock.h
 * 摘    要：
 * 当前版本：0.1
 * 作    者：yangshuang
 * 修订记录：
 * 完成日期：2011-04-15
 *  
 */
#ifndef SYNCLOCK_H_
#define SYNCLOCK_H_

#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
using namespace std;

#define		POWER_ON_SYNC_TIME		0//开机时钟同步
#define		RUN_STRART_SYNC_TIME		1//运营开始时钟同步
#define		RUN_END_SYNC_TIME		2//运营结束时钟同步
#define		AUTO_SYNC_TIME			3//定时时钟同步
#define		FORCE_SYNC_TIME			4//强制时钟同步
#define		MANUAL_SYNC_TIME			5//手工时钟同步

//#include "CLogOper2.h"
#include "PubNtpSyncClock.h"
#include  <limits>

//#include "slepubbiz/slepubbiz/SleOperlog/PubOperLog.h"
//#include "slepubbiz/slepubbiz/PubSleErrorCode/SleErrorCode.h"
//
//#include "config/pubconfig/SleConfig/StanderParamAnalysis.h"
//#include "config/pubconfig/SleConfig/SpecParamAnalysis.h"
//#include "config/pubconfig/SleConfig/GlobeParamTable.h"

/*！ \class cClockManager
 *  \brief 定义了类
 	
 	 成员函数与变量：	cClockManager(CLogOper2 *SleLog  ,PubOperLog *Operlog,cStanderParamAnalysis*StaderPara,cSpecParamAnalysis*SpecPara,cErrorCode*ErrorCode);构造函数
						virtual ~cClockManager();析构函数
						bool OnSyncTime(int iSrcType, bool bUseTimeDiff, long iTimeDiff);时钟同步
						bool OnStartUpSync();开机时钟同步
						CLogOper2 *m_SleLog;日志指针
						PubSleDb *m_SleDb;数据库指针
						PubOperLog *m_Operlog;操作日志指针
						cStanderParamAnalysis*m_StaderPara;标准参数指针
						cSpecParamAnalysis*m_SpecPara;特殊参数指针
						cErrorCode*m_ErrorCode;特殊参数指针				
 *  \version	杨爽
 *  \date	2011-5-5
*/

class cClockManager
{
public:
	cClockManager();/*!构造函数*/
	virtual ~cClockManager();/*!析构函数*/
public:

	/*! \fn OnSyncTime()
	 * \brief  		时钟同步
	 * \param[in]		   char * pszSourceIP
	 *                     int iSourcePort
	 *                     int iSrcType 0：slecomm自动时钟同步。
	 * 									1：slecomm收到SC强制时钟同步命令。
	 * 									2：维修界面发起的强制时钟同步。
										4：维修界面发起的修改本地时间。
						bool bUseTimeDiff 0：不需要使用参数2。1：需要使用命令参数2。
						long iTimeDiff	当命令参数1为1时，此参数作为时间差异
						int iMinTime 最大同步时间
						int iMaxTime 最小同步时间
	 * \return 		bool型 false：未完成 true：完成
	 * \author
	 * \date
	 */
	bool OnSyncTime(char * pszSourceIP,int iSourcePort,int iSrcType,
			bool bUseTimeDiff, long iTimeDiff, unsigned int iMaxTime=0xFFFE , unsigned int iMinTime = 0);/*!时钟同步*/


	/*! \fn OnStartUpSync()
	 * \brief  		开机时钟同步
	 *  \param[in]	char * pszSourceIP
	 *              int iSourcePort
	 *              unsigned int iMaxTime 最大时间
	 *              unsigned int iMinTime 最小时间
	 * \return 		bool型 false：未完成 true：完成
	 * \author
	 * \date
	 */
	bool OnStartUpSync(char * pszSourceIP,int iSourcePort, unsigned int iMaxTime=0xFFFE, unsigned int iMinTime = 0);/*!开机时钟同步*/
};



#endif /*PARAUPDATE_H_*/
