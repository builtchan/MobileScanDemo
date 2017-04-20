/*
 * CLogOper.h
 *
 *  Created on: 2012-7-17
 *      Author: miqiang
 */

#ifndef CLOGOPER_H_
#define CLOGOPER_H_

class CLogOper {
public:
	CLogOper();
	virtual ~CLogOper();
public:
	void GetLogFileName(const char* pszLogFileDir, const char* pszDeviceCode,
			int iFileNum, char* pszLogFileName);//获得日志的文件名
	bool SetConfigureFile(const char* pszConfigureFileName,
			const char* pszInstanceName, const char* pszLogFileName,
			int iMaxFileSize = 10485760, int iMaxBackupIndex = 10,
			const char* pszPriority = "DEBUG");//设置日志配置文件
	bool InitLogInstance(const char* pszConfigureFileName,
			const char* pszInstanceName);//初始化日志实例

	//日志记录:DEBUG等级
	void LogDebug(const char* pszStringLog, ...);
	void LogDebug(const char* pszLogCode, const char* pszLogSubCode,
			const char* pszStringLog, ...);
	void LogDebug(const int iLogCode, const int iLogSubCode,
			const char* pszStringLog, ...);

	//日志记录:INFO等级
	void LogInfo(const char* pszStringLog, ...);
	void LogInfo(const char* pszLogCode, const char* pszLogSubCode,
			const char* pszStringLog, ...);
	void LogInfo(const int iLogCode, const int iLogSubCode,
			const char* pszStringLog, ...);

	//日志记录:WARN等级
	void LogWarn(const char* pszStringLog, ...);
	void LogWarn(const char* pszLogCode, const char* pszLogSubCode,
			const char* pszStringLog, ...);
	void LogWarn(const int iLogCode, const int iLogSubCode,
			const char* pszStringLog, ...);

	//日志记录:ERROR等级
	void LogError(const char* pszStringLog, ...);
	void LogError(const char* pszLogCode, const char* pszLogSubCode,
			const char* pszStringLog, ...);
	void LogError(const int iLogCode, const int iLogSubCode,
			const char* pszStringLog, ...);

	//日志记录:FATAL等级
	void LogFatal(const char* pszStringLog, ...);
	void LogFatal(const char* pszLogCode, const char* pszLogSubCode,
			const char* pszStringLog, ...);
	void LogFatal(const int iLogCode, const int iLogSubCode,
			const char* pszStringLog, ...);
protected:
	void* m_hCategory; //生成实例的句柄
};

#endif /* CLOGOPER_H_ */
