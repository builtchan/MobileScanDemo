/*! \file 	PubNtpSyncClock.h	
* \version  1.0		
* \brief  	时钟同步管理文件		
* \author	liuyp						
* \date		2011-01-10		
* \par		修改记录			
*  
* \par
			
* \par:	
*/
#ifndef SYNCTIMEMANAGER_H_
#define SYNCTIMEMANAGER_H_

#ifdef __cplusplus                    
extern "C"                             
{
#endif



#define NTP_SYNC_CLOCK_PORT 123


/*! \class		CSyncClock
* \version		1.0			
* \brief  	    时钟管理类
* \author		liuyp
* \date			2011-01-10
* \par			修改记录
*  
* \par
				
* \par:	
*/
class CSyncClock
{
public:
	/*! \fn CSyncClock::CSyncClock()
	 * \brief 		构造函数
	 * \author 		liuyp
	 * \date 		2011-01-10
	*/
	CSyncClock();
	
	/*! \fn CSyncClock::~CSyncClock()
	 * \brief 		析构函数
	 * \author 		liuyp
	 * \date 		2011-01-10
	*/
	virtual ~CSyncClock();

public:

	/*! \fn int PubNtpGetTimeDiff(char *pszNtpServerIp, int iNtpPort, long *plTimeDiff)
	 * \brief 		通过NTP协议获取与NTP服务器的时间差
	 * \param[in] 	pszNtpServerIp   		NTP服务器IP地址
	 * \param[in] 	iNtpPort		 			NTP服务器端口号
	 * \param[out] 	plTimeDiff		  		时间差(单位:秒)
	 * \return 		int   0 成功, -1 失败
	 * \author 		liuyp
	 * \date 		2011-01-10
	*/
	int 	PubNtpGetTimeDiff(char *pszNtpServerIp, int iNtpPort, long *plTimeDiff);
	
	/*! \fn int PubNtpCheckAlarmFlag(int T2, int T3, int T4, long lTimeDiff, int *piAlarmFlag)
	 * \brief 		通过NTP协议获取与NTP服务器的时间差
	 * \param[in] 	T2   						当 时间差 > T2 时，时钟报警
	 * \param[in] 	T3   						当 时间差 > T3 时，时钟故障
	 * \param[in] 	T4   						当 时间差 < T4 时，不设置本地系统时间
	 * \param[in] 	lTimeDiff		 			时间差(单位:秒)
	 * \param[out] 	piAlarmFlag		  		警报标志。0: 不同步；1：同步，不报警; 2：同步，报警；3：不同步，故障报警。
	 * \return 		int   0 成功, -1 失败
	 * \author 		liuyp
	 * \date 		2011-01-10
	*/
	void 	PubNtpCheckAlarmFlag(int Ta, int Tb, int Tc, long lTimeDiff, int *piAlarmFlag);
	
	/*! \fn int PubNtpSycnTime(long lTimeDiff)
	 * \brief 		根据时间差设置本地系统时间
	 * \param[in] 	lTimeDiff		 			时间差(单位:秒)
	 * \return 		int  						0 成功, -1 失败
	 * \author 		liuyp
	 * \date 	    2011-01-10
	*/
	int 	PubNtpSycnTime(long lTimeDiff);
	/*! \fn int PubNtpCheckAlarmFlag(int Ta, int Tb, long lTimeDiff, int *piAlarmFlag)
	 * \brief 		通过NTP协议获取与NTP服务器的时间差
	 * \param[in] 	Ta  						当 时间差 > Ta 时，时钟故障
	 * \param[in] 	Tb  						当 时间差 < Tb 时，不设置本地系统时间
	 * \param[in] 	lTimeDiff		 			时间差(单位:秒)
	 * \param[out] 	piAlarmFlag		  		警报标志。0: 不同步；1：同步，不报警; 2：同步，报警；3：不同步，故障报警。
	 * \return 		int   0 成功, -1 失败
	 * \author 		yangshuang
	 * \date 			2011-04-29
	*/
	void PubNtpCheckAlarmFlag(int Ta, int Tb, long lTimeDiff, int *piAlarmFlag);
};

#ifdef __cplusplus 		 
}
#endif/*__cplusplus*/

#endif /*SYNCTIMEMANAGER_H_*/
