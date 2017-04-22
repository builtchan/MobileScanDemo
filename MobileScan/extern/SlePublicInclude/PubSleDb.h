/*! \file 	PubSleDb.h	
* \version  	1.0		
* \brief  	数据处理模块，通过对本模块的调用可完成各类数据的落地和读取	
* \author		牛更五						
* \date		2009-11-11	
* \par			修改记录				
*/
#ifndef __PUBSLEDB_H__
#define __PUBSLEDB_H__

#include "pthread.h"
#include "sqlite3.h"
#include <vector>
using std::vector;
#define CE_OK		0x00
#define FAILED	0x01
//
//#define AG_DATABASE_NAME	"/Afc/Data/SleDb.db"
#define CURRENT_DATE "strftime('%Y%m%d', 'now', 'localtime')"
#define CURRENT_TIME	"strftime('%H%M%S', 'now', 'localtime')"
#define SQLITE_TIMEOUT	5000 /*设定当数据库锁定时等待的时间,现在设定为5秒*/

//typedef enum
//{
////	ACC_SEQ			= 0x01,               /*ACC交易流水号*/
////	YKT_SEQ			= 0x02,               /*一卡通交易流水号*/
//	AFC_SEQ			= 0x03,               /*AFC数据流水号*/
//	TRN_SEQ			= 0x04,               /* 交易明细流水号*/
//	OPR_SEQ			= 0x05,               /* 操作流水号*/
//	TIC_BOX_SEQ	 	= 0x06,           	  /* 票箱更换流水号*/
//	BILL_BOX_SEQ	= 0x07,           	  /* 纸币钱箱更换流水号*/
//	COIN_BOX_SEQ	= 0x08,           	  /* 硬币钱箱更换流水号*/
//	UNDEF_SEQ 		= 0x09,
//	BUSI_PUB_SEQ 	= 3001,   			/*公共流水号，数据存储模块专用*/
//	ACC_UDSN     	= 3002,
//	YKT_UDSN    	= 3003,
//	ACC_UDSN_SV  	= 3021, 			//一票通储值票
//
//	//SAM1 对应的UDSN；在各设备中， SAM1分别对应： BOM 桌面一卡通充值SAM； AG 进站一卡通SAM
//	UDSN_SAM1       = 3026,
//
//	//SAM2 对应的UDSN；在各设备中， SAM2分别对应： BOM 桌面一卡通消费SAM； AG 出站一卡通SAM
//	UDSN_SAM2       = 3027,             //SAM2 对应的UDSN；
//
//	UDSN_SAM3       = 3028,             //SAM3 对应的UDSN；
//
//
//	RECORD_SN_YPT 	= 3012, 			/*一卡通RecordSN，用于 YKT 交易数据存储流水号，而非直接使用TPU返回的UDSN*/
//	RECORD_SN_YKT 	= 3013, 			/*一票通RecordSN，用于 YPT 交易数据存储，而非直接使用TPU返回的UDSN*/
//	BALANCE_SEQ 	= 3101,             /* 结算流水号*/
//
//}SEQ_TYPE;

 //
typedef struct _ST_READ_DOWNLOAD_TEMP_
{
	char szParamId[10];			//参数ID	10
	char szSaveFilePath[64];	//保存文件路径	64
	char szSaveFileName[100];	//保存文件名称	100
}ST_READ_DOWNLOAD_TEMP;

#ifdef __cplusplus 
extern "C"
{
/*！ \class CComApi
 *  \brief 定义了操作数据库的类
 *  \version	杨爽
 *  \date	2011-3-3
*/	
class PubSleDb
{
public:

	PubSleDb();/*!<构造函数*/
	
	~PubSleDb();/*!<析构函数*/
	
	/*! \fn int InitDbAndCheck(const char *pDbFilePath, bool bSynchronous, bool bFullfsync)
	 * \brief 	初始化数据库，并检查数据库是否损坏，如果损坏则执行数据库修复
	 * \param[in] pDbFilePath - 要打开数据库文件的路径
	 * 			bSynchronous - 是否同步
	 * 			bFullfsync - 	是否完全同步(一般为false表示先保存在内存中，随后再写入库)
	 * \author 	弥强
	 * \date 		2012-5-10
	*/
	int InitDbAndCheck(const char *pDbFilePath, bool bSynchronous, bool bFullfsync);
	
	/*! \fn int InitDb(const char *pDbFilePath, bool bSynchronous, bool bFullfsync)
	 * \brief 	初始化数据库
	 * \param[in] pDbFilePath - 要打开数据库文件的路径
	 * 			bSynchronous - 是否同步
	 * 			bFullfsync - 	是否完全同步(一般为false表示先保存在内存中，随后再写入库)
	 * \author 	牛更五
	 * \date 		2011-1-11
	*/
	int InitDb(const char *pDbFilePath, bool bSynchronous, bool bFullfsync);
	
	/*! \fn int CloseDb()
	 * \brief 	关闭线程和端口	
	 * \return 	SQLITE_OK：操作成功
	 * 			SQLITE_BUSY:数据库忙
	 * \author 	牛更五	
	 * \date 		2011-01-11
	 */		
	int CloseDb();
	
	/*! \fn const char * GetVersion()
	 * \brief 	获取数据库版本	
	 * \return 	版本号的字符串
	 * \author 	牛更五	
	 * \date 		2011-01-11
	 */		
	const char * GetVersion();
	
	/*! \fn int InsertUd(const char *pszSql, const char *pszUdData, int usUDLen, const char *pszErrMsg)
	 * \brief 	插入UD	
	 * \param[in] pszSql - 执行的SQL语句
	 * 			pszUdData - UD数据
	 * 			usUDLen - UD数据的长度
	 * 			pszErrMsg - 执行失败后返回的错误信息串
	 * \return 	SQLITE_OK-成功  其它失败 
	 * \author 	牛更五	
	 * \date 		2010-01-08
	 */		
	int InsertUd(const char *pszSql, const char *pszUdData, int usUDLen, char *pszErrMsg);
	
	/*! \fn ReadDownloadTemp()
	 * \brief 	读取DownloadTemp	
	 * \param[in] pszSql 
	 * \return 	int, 和SQLITE的返回值相同 
	 * \author 	牛更五	
	 * \date 		2010-01-08
	 */		
	int ReadDownloadTemp(const char *pszSql, char *pszErrMsg);
	
	
	/*! \fn ReadUd()
	 * \brief 	读取UD	
	 * \param[in] pszSql 
	 * \return 	int, 和SQLITE的返回值相同 
	 * \author 	牛更五	
	 * \date 		2010-01-08
	 */		
	int ReadUd(const char *pszSql, char *pszUdData, int *pusUDLen, char *pszErrMsg);

	/*! \fn int GetTable(const char *pszSql, char ***pppszResult, int *piRow, int *piColumn, char *pszErrMsg)
	 * \brief 	 插入UD	
	 * \param[in]  pszSql 
	 * \param[out] ppszResult - 查询的结果集
	 * 			 piRow - 查询的结果集的行数
	 *  			 piColumn - 查询的结果集的列数 
	 * 			 pszErrMsg - 执行失败后返回的错误信息串
	 * \return 	 SQLITE_OK-成功  其它失败 
	 * \author 	 牛更五	
	 * \date 		 2010-05-25
	 */			
	int GetTable(const char *pszSql, char ***pppszResult, int *piRow, int *piColumn, char *pszErrMsg);
	
	/*! \fn FreeErrMsg(char *pszErrMsg)
	 * \brief 	释放错误信息指针	
	 * \return 	SQLITE_OK-成功  其它失败 
	 * \author 	孙桂刚	
	 * \date 		2011-04-27
	 */	
	void FreeErrMsg(char *pszErrMsg);
	
	/*! \fn GetDeviceSeq(int iSeqType, unsigned long *piSeqValue)
 	* \brief 	使用事务的方式获取序号	
	 * \return 	int, 和SQLITE的返回值相同 
 	* \author 	孙桂刚	
 	* \date 		2011-03-08
	 */	
	int GetDeviceSeq(int iSeqType, unsigned long *piSeqValue);
	
	/*! \fn GetAccUdSeq(unsigned long *piSeqValue)
 	* \brief 	使用事务的方式获取序号	
	 * \return 	int, 和SQLITE的返回值相同 
 	* \author 	孙桂刚	
 	* \date 		2011-03-08
	 */	
	int GetAccUdSeq( unsigned long *piSeqValue);
	
	/*! \fn GetYktUdSeq(unsigned long *piSeqValue)
 	* \brief 	使用事务的方式获取序号	
	 * \return 	int, 和SQLITE的返回值相同 
 	* \author 	孙桂刚	
 	* \date 		2011-03-08
	 */	
	int GetYktUdSeq( unsigned long *piSeqValue);
	
	/*! \fn Execute(const char *pszSql, char *pszErrMsg)
	 * \brief 	执行SQL语句	
	 * \param[in] pszSql - 执行的SQL语句
	 * \param[out] pszErrMsg - 如何执行失败返回的错误信息
	 * \return 	SQLITE_OK - 成功
	 * 				其它失败 
	 * \author 	牛更五	
	 * \date 		2010-01-08
	 */			
	int Execute(const char *pszSql, char *pszErrMsg);

	/*! \fn Begin()
	 * \brief 	执行SQL语句	
	 * \return 	 SQLITE_OK-成功  其它失败 
	 * \author 	牛更五	
	 * \date 		2010-05-25
	 */			
	int Begin();
	
	/*! \fn Commit()
	 * \brief 	执行SQL语句	
	 * \return 	 SQLITE_OK-成功  其它失败 
	 * \author 	牛更五	
	 * \date 		2010-05-25
	 */	
	int Commit();

	/*! \fn Rollback()
	 * \brief 	执行SQL语句	
	 * \return 	 SQLITE_OK-成功  其它失败 
	 * \author 	牛更五	
	 * \date 		2010-05-25
	 */		
	int Rollback();
	
	/*! \fn GetDbStatus()
	 * \brief 	获取数据状态	
	 * \return 	布尔值
	 * \author 	牛更五	
	 * \date 		2010-05-25
	 */
	bool GetDbStatus();
	
	/*! \fn SetDbStatus()
	 * \brief 	设置数据库状态	
	 * \return 	布尔值
	 * \author 	牛更五	
	 * \date 		2010-05-25
	 */
	void SetDbStatus(bool bDbStatus);
	
	/*! \fn SqlitePrepare(const char *pszSql)
 	* \brief 	编译sql语句	
 	* \return 	int, 和SQLITE的返回值相同 
 	* \author 	孙桂刚	
 	* \date 		2011-03-08
 	*/	
	int SqlitePrepare(const char *pszSql);
	
	/*! \fn SqliteStep()
 	* \brief 	读取UD数据	
	* \return 	int, 和SQLITE的返回值相同 
	* \author 	孙桂刚	
 	* \date 		2011-03-08
 	*/	
	int SqliteStep();
	
	/*! \fn FreeTable(	const char **ppDbResult  )
 	* \brief 	释放结果集合	
 	* \return 	int, 和SQLITE的返回值相同 
 	* \author 	孙桂刚	
 	* \date 		2011-03-08
	 */	
	void FreeTable(  char **ppDbResult );
	
	/*! \fn GetUd( )
 	* \brief 	获取UD	
 	* \return int, 和SQLITE的返回值相同 
 	* \author 孙桂刚	
 	* \date 	2011-03-08
 	*/	
	const void * GetUd();
	
	/*! \fn GetUdLength( )
 	* \brief 	获取UD长度	
 	* \return int ud数据的长度
 	* \author 孙桂刚	
 	* \date 	2011-03-08
 	*/	
 	int GetUdLength();
	
	/*! \fn FreeStmt( )
 	* \brief 	释放游标集合
 	* \return 	int ud数据的长度
 	* \author 	孙桂刚	
 	* \date 		2011-03-08
 	*/	
 	void FreeStmt();

public:
	vector<ST_READ_DOWNLOAD_TEMP> m_iterDownloadTemp;
private:
	unsigned long m_ulMaxLong;/*!<最大流水号*/
	sqlite3 *m_pDb ;/*!<数据库指针*/
	sqlite3_stmt  *m_pstmt ; /*!<游标指针*/
	bool m_bDbStatus ;/*!<数据库状态*/
	pthread_mutex_t m_hMutex;/*!<变量标志互斥锁*/
	char *pszErrorMsg;/*!<数据库执行出错信息*/
};
}
#endif/*__cplusplus*/

#endif /*__PUBSLEDB_H__*/
