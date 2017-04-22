/*
 * ITPUCommonFunction.h
 *
 *  Created on: Sep 10, 2014
 *      Author: root
 */

#ifndef ITPUCOMMONFUNCTION_H_
#define ITPUCOMMONFUNCTION_H_


#include "IDeviceCommonFunction.h"
#include "CLogOper2.h"
#include "AfcPublic.h"
#include "SleParamAttriDefPublic.h"

#include <loki/Singleton.h>
#include <loki/Factory.h>
#include <loki/Sequence.h>
#include <list>
#include <set>

using namespace Loki;

using namespace std;

class IPollcardcallbackFunctionHandler
{
public:
	/* virtual void PollCardNotify(ST_TPU_POLLING_CARD_INFO * pstPollingCardInfo)=0;
	 * TPU模块polling卡后回调通知
	 * param[in]:无
	 * param[out]:
	 * 		pstPollingCardInfo：Polling结果
	 * author:wugang
	 * date:2015-01-30
	 * return: void
	 */
	virtual void PollCardNotify(ST_TPU_POLLING_CARD_INFO * pstPollingCardInfo)=0;
};

class ITPUCommonFunction : public IDeviceCommonFunction
{

public:

	/* virtual void SetPollCardCallbackFunction(IPollcardcallbackFunctionHandler *pstIPollcardcallbackFunctionHandler)=0;
	 * 设置回调对象
	 * param[in]:
	 * 		pstIPollcardcallbackFunctionHandler：回调对象指针
	 * param[out]:无
	 * author:wugang
	 * date:2015-01-30
	 * return: void
	*/
	virtual void SetPollCardCallbackFunction(IPollcardcallbackFunctionHandler *pstIPollcardcallbackFunctionHandler)=0;
	virtual IPollcardcallbackFunctionHandler * GetPollCardCallbackFunction()=0;

	/* virtual int SetTpuTime( char *pDateTime)=0;
	 * 设置TPU时钟
	 * param[in]:
	 * 		pDateTime：时间，字符串格式，如“20141122090923“
	 * param[out]: 无
	 * author:wugang
	 * date:2015-01-30
	 * return:
			COMMOM_FUNC_OK  执行成功
			COMMOM_FUNC_FAIL   执行失败
			COMMOM_FUNC_CMDERR   指令错误，没有被执行
			COMMOM_FUNC_UNSUPP   模块不支持此项功能
	*/
	virtual int SetTpuTime(const char *pDateTime)=0;

	/* virtual int GetTpuTime( char *pDateTime)=0;
	 * 获取TPU时钟
	 * param[in]: 无
	 * param[out]:
	 * 		pDateTime：时间，字符串格式，如“20141122090923“
	 * author:wugang
	 * date:2015-01-30
	 * return: 同SetTpuTime
	*/
	virtual int GetTpuTime( char *pDateTime)=0;

	/* virtual int SetTpuOperationDate( char *pDate)=0;
	 * 设置TPU运营日
	 * param[in]:
	 * 		pDate：时间，字符串格式，如“20151231“
	 * param[out]: 无
	 * author:wugang
	 * date:2015-01-30
	 * return: 同SetTpuTime
	*/
	virtual int SetTpuOperationDate(const char *pDate)=0;

	/* virtual int SetTpuOperatorInfo(unsigned char szOperaterID[4], unsigned char szBomShiftID[4])=0;
	 * 设置操作员ID和班次信息
	 * param[in]:
	 * 		szOperaterID：操作员ID
	 * 		szBomShiftID：班次ID，如果没有班次，填充0
	 * param[out]: 无
	 * author:wugang
	 * date:2015-01-30
	 * return: 同SetTpuTime
	*/
	virtual int SetTpuOperatorInfo(const unsigned char szOperaterID[4], const unsigned char szBomShiftID[4])=0;

	/* virtual int SetTpuTestMode(bool bDeviceTestMode)=0;
	 * 设置/取消测试模式
	 * param[in]:
	 * 		bDeviceTestMode：false:normal mode,true:test mode
	 * param[out]: 无
	 * author:wugang
	 * date:2015-01-30
	 * return: 同SetTpuTime
	*/
	virtual int SetTpuTestMode(bool bDeviceTestMode)=0;

	/* virtual int GetSamInfo(SAM_INFO_CSS szTpuInfo[10], int * piSamCount)=0;
	 * 获取SAM卡信息
	 * param[in]: 无
	 * param[out]:
	 * 		szTpuInfo： 存储SAM卡信息的数组，最多10个SAM卡
	 * 		piSamCount：SAM卡数量，也是szTpuInfo数组的有效个数
	 * author:wugang
	 * date:2015-01-30
	 * return: 同SetTpuTime
	*/
	virtual int GetSamInfo(SAM_INFO_CSS szTpuInfo[10], int * piSamCount)=0;//

	/* virtual int GetTpuLastErrCode(int *piTpuLastErrCode, int *piCssErrCode,  unsigned char* ucErrInfo)=0;
	 * 获取TPU最近操作的错误代码
	 * param[in]: 无
	 *
	 * param[out]:
	 * 		piTpuLastErrCode： 原厂错误代码
	 * 		piCssErrCode：产品化错误代码，EM_TICKET_TRANS_RESULT枚举值
	 * 		ucErrInfo: 原厂错误代码附加信息
	 * author:wugang
	 * date:2015-01-30
	 * return: 同SetTpuTime
	*/
	virtual int GetTpuLastErrCode(int *piTpuLastErrCode, int *piCssErrCode,  unsigned char* ucErrInfo)=0;

	/* virtual GetTpuAllVerInfo(bool bSoftwareVerInfo, bool bParamVerInfo, EM_SLE_PARAM_VERSION_TYPE emParamVersionType, DWORD uiSoftwareId, DWORD uiParamNum, DWORD* puiParamId, ST_TPU_PARAM_VERSION_INFO* pstParaminfo) = 0;
	* \brief        获取TPU所有版本信息(软件版本/参数版本)
	* \param[in]	bSoftwareVerInfo			软件版本信息
	* \param[in]	bParamVerInfo				参数版本信息
	* \param[in]	emParamVersionType			版本类型
	* \param[in]	uiSoftwareId				软件版本Id				(bSoftwareVerInfo = true时有效)
	* \param[in]	uiParamNum					参数数目					(bParamVerInfo = true时有效)
	* \param[in]	puiParamId					参数版本Id集合				(bParamVerInfo = true时有效)
	* \param[out]	pstParaminfo				获取到的具体版本信息
	* \return		true/false					成功/失败
	* \author		longjg
	* \date			2015-08-05
	*/
	virtual int GetTpuAllVerInfo(bool bSoftwareVerInfo, bool bParamVerInfo, EM_SLE_PARAM_VERSION_TYPE emParamVersionType, DWORD uiSoftwareId, DWORD uiParamNum, DWORD* puiParamId, ST_TPU_PARAM_VERSION_INFO* pstParaminfo) = 0;

	/* virtual	int GetTpuParamInfo(EM_SLE_PARAM_VERSION_TYPE emParamVersionType, unsigned short usParamTypeID, ST_TPU_PARAM_VERSION_INFO *pstParaminfo)=0;
	 * 获取TPU的单个参数信息
	 * param[in]:
	 * 		emParamVersionType：参数版本类型
	 * 		usParamTypeID：参数类型ID
	 * param[out]:
	 * 		pstParaminfo：存储参数信息的BUF
	 * author:wugang
	 * date:2015-01-30
	 * return: 同SetTpuTime
	*/
	virtual	int GetTpuParamInfo(EM_SLE_PARAM_VERSION_TYPE emParamVersionType, unsigned short usParamTypeID, ST_TPU_PARAM_VERSION_INFO *pstParaminfo)=0;

	/* virtual int SetTpuRunmode(ST_SYSTEM_RUN_MODE stModeCode)=0;
	 * 设置TPU运营模式
	 * param[in]:
	 * 		stModeCode：运营模式，必须完全赋值
	 * param[out]: 无
	 * author:wugang
	 * date:2015-01-30
	 * return: 同SetTpuTime
	*/
	virtual int SetTpuRunmode(ST_SYSTEM_RUN_MODE stModeCode)=0;

	/* virtual int ModeNotify(void * pModeNotifyData,unsigned int uiModeNotifyDataLen)=0;
	 * 模式通知
	 * param[in]:
	 * 		pModeNotifyData：运营模式的数据
	 * 		uiModeNotifyDataLen: 运营模式的数据长度
	 * param[out]: 无
	 * author:wugang
	 * date:2015-01-30
	 * return: 同SetTpuTime
	*/
	virtual int ModeNotify(const void * pModeNotifyData,unsigned int uiModeNotifyDataLen)=0;

	/*iAntennaMark出站读卡器寻卡标志，系统枚举值
	出站端天线寻卡标志
    	0：停止寻卡
		1：双天线同时寻卡
		2：只有A天线寻卡
		3：只有B天线寻卡；
		4:只有C天线寻卡
		5:A、C天线寻卡
		6:B、C天线寻卡
		7:A、B、C天线寻卡
	iPreAntennaMark出站预读卡标志，1表示启用，0表示未启用
	出站端预读卡标志
		1：启用预读
		0：不启用预读。
	返回值说明：
		成功返回0，失败返回1。
	 * */
//	virtual int PollCard( int iAntennaMark, bool  bPreAntennaMark=0)=0;

	/* virtual int ParamDownload(char* szParamTypeID, const char* pMainVersion, const char*pSubVersion, const char* pFilePath, const char* pFileName) = 0
	 * 下载参数到TPU
	 * param[in]:
	 * 		szParamTypeID:参数类型ID
	 * 		pMainVersion:参数主版本
	 * 		pSubVersion:参数子版本
	 * 		pFilePath:参数文件的路径
	 * 		pFileName:参数文件名
	 * param[out]: 无
	 * author:wugang
	 * date:2015-01-30
	 * return: 同SetTpuTime
	*/
	virtual int ParamDownload(char* szParamTypeID, const char* pMainVersion, const char*pSubVersion, const char* pFilePath, const char* pFileName) = 0;

	/* virtual int AsyncPollCard( int iAntennaMark, bool bPreRead=0)=0;
	 * 异步寻卡，TPU启动异步寻卡，直到寻到卡，或者收到AbortTpu后方才停止。寻到卡后调用IPollcardcallbackFunctionHandler->PollCardNotify通知业务层
	 * param[in]:
	 * 		iAntennaMark：天线寻卡标记 1HEX, bit0: A天线, bit1: B天线, bit2: C天线
	 * 					 1：只有A天线寻卡;2：只有B天线寻卡；3：双天线同时寻卡;	4:只有C天线寻卡; 5:A、C天线寻卡; 6:B、C天线寻卡;  7:A、B、C天线寻卡
	 * 		bPreRead: 出站预读卡标志，true表示启用预读，false表示不预读
	 * param[out]: 无
	 * author:wugang
	 * date:2015-01-30
	 * return: 同SetTpuTime
	*/
	virtual int AsyncPollCard( int iAntennaMark, bool bPreRead)=0;

	/* virtual int AbortTpu()=0;
	 * 中止读卡器工作,应用预执行Polling之后，中止Polling
	 * param[in]: 无
	 * param[out]: 无
	 * author:wugang
	 * date:2015-01-30
	 * return: 同SetTpuTime
	*/
	virtual int AbortTpu()=0;

	/* virtual int ImmediatelyPollCard( int iAntennaMark, bool bPreRead, ST_TPU_POLLING_CARD_INFO * pstPollingCardInfo)=0;
	 * 即时寻卡，如果没有寻到卡，马上返回COMMOM_FUNC_FAIL
	 * param[in]:
	 * 		iAntennaMark：天线寻卡标记 1HEX, bit0: A天线, bit1: B天线, bit2: C天线
	 * 					 1：只有A天线寻卡;2：只有B天线寻卡；3：双天线同时寻卡;	4:只有C天线寻卡; 5:A、C天线寻卡; 6:B、C天线寻卡;  7:A、B、C天线寻卡
	 * 		bPreRead: 出站预读卡标志，true表示启用预读，false表示不预读
	 * param[out]:
	 * 		pstPollingCardInfo：Polling结果
	 * author:wugang
	 * date:2015-01-30
	 * return: 寻到卡，返回COMMOM_FUNC_OK；否则，返回COMMOM_FUNC_FAIL
	*/
	virtual int ImmediatelyPollCard( int iAntennaMark, bool bPreRead, ST_TPU_POLLING_CARD_INFO * pstPollingCardInfo)=0;

	/* virtual int StopTpu()=0;
	 * 停止TPU，调用StopTpu，TPU将不能工作，知道重新Init
	 * param[in]: 无
	 * param[out]: 无
	 * author:wugang
	 * date:2015-01-30
	 * return: 同SetTpuTime
	*/
	virtual int StopTpu()=0;

	/* virtual int ReadCardInfo(const ST_TPU_READ_CARD_PARAM * pstReadCardParam, ST_TPU_READ_CARD_INFO * pstOutCardInfo)=0;
	 * 读取车票信息
	 * param[in]:
	 * 		pstReadCardParam：读卡参数
	 * param[out]:
	 * 		pstOutCardInfo：卡信息，读卡成功后才有效
	 * author:wugang
	 * date:2015-01-30
	 * return: 同SetTpuTime
	*/
	virtual int ReadCardInfo(const ST_TPU_READ_CARD_PARAM * pstReadCardParam, ST_TPU_READ_CARD_INFO * pstOutCardInfo)=0;

	/* virtual int CheckTicketTrans(const ST_TPU_CONTEXT_DATA * pstTpuContextData, EM_TICKET_TRANS_RESULT * pemOutTransResult)=0;
	 * 检票交易，不立即返回UD数据
	 * param[in]:
	 * 		pstTpuContextData：TPU交易参数
	 * param[out]:
	 * 		pstTpuTransResult: 交易结果信息,返回值是COMMOM_FUNC_OK时有效
	 * author:wugang
	 * date:2015-01-30
	 * return: 同SetTpuTime
	 * 		注：车票无效的结果在出参反馈，此时的返回值是COMMOM_FUNC_OK；只有在调用读写器检票功能失败，没有得到返回结果时，返回COMMOM_FUNC_FAIL
	*/
	virtual int CheckTicketTrans(const ST_TPU_CONTEXT_DATA * pstTpuContextData, ST_TPU_TRANS_RESULT * pstTpuTransResult)=0;

	/* virtual int GetUdData(ST_TPU_TRANS_RESULT * pstTpuTransResult,   ST_TICKET_TRANS_DETAIL_INFO * pstTicketTransUdInfo)=0;
	 * 检票交易后获取UD数据
	 * param[in]: 无
	 * param[out]:
	 * 		pstTicketTransUdInfo：交易产生的UD数据信息
	 * author:wugang
	 * date:2015-01-30
	 * return: 同SetTpuTime
	*/
	virtual int GetUdData(ST_TICKET_TRANS_DETAIL_INFO * pstTicketTransUdInfo)=0;

	/* virtual int SaleTicketTrans(const ST_TPU_CONTEXT_DATA * pstTpuContextData, ST_TPU_SALE_INFO stSaleInfo, ST_TPU_TRANS_RESULT * pstTpuTransResult,   ST_TICKET_TRANS_DETAIL_INFO * pstTicketTransUdInfo)=0;
	 * 售票交易
	 * param[in]:
	 * 		pstTpuContextData：TPU交易参数
	 * 		stSaleInfo： 售票参数
	 * param[out]:
	 * 		pstTpuTransResult: 交易结果信息
	 * 		pstTicketTransUdInfo：交易产生的UD数据信息
	 * author:wugang
	 * date:2015-01-30
	 * return: 同SetTpuTime
	 * 		注：TPU写票失败的结果在出参反馈，此时的返回值是COMMOM_FUNC_OK；只有在调用读写器售票功能失败，没有得到返回结果时，返回COMMOM_FUNC_FAIL
	*/
	virtual int SaleTicketTrans(const ST_TPU_CONTEXT_DATA * pstTpuContextData, ST_TPU_SALE_INFO stSaleInfo, ST_TPU_TRANS_RESULT * pstTpuTransResult,   ST_TICKET_TRANS_DETAIL_INFO * pstTicketTransUdInfo)=0;

	/* virtual int Recharge(const ST_TPU_CONTEXT_DATA * pstTpuContextData, ST_TPU_TRANS_RESULT * pstTpuTransResult,   ST_TICKET_TRANS_DETAIL_INFO * pstTicketTransUdInfo)=0;
	 * 充值交易
	 * param[in]:
	 * 		pstTpuContextData：TPU交易参数
	 * param[out]:
	 * 		pstTpuTransResult: 交易结果信息
	 * 		pstTicketTransUdInfo：交易产生的UD数据信息
	 * author:wugang
	 * date:2015-01-30
	 * return: 同SetTpuTime
	 * 		注：TPU写票失败的结果在出参反馈，此时的返回值是COMMOM_FUNC_OK；只有在调用读写器充值功能失败，没有得到返回结果时，返回COMMOM_FUNC_FAIL
	*/
	virtual int Recharge(const ST_TPU_CONTEXT_DATA * pstTpuContextData, ST_TPU_TRANS_RESULT * pstTpuTransResult,   ST_TICKET_TRANS_DETAIL_INFO * pstTicketTransUdInfo)=0;

	/* virtual int CalculateImmediatelyTicketPrice(ST_TPU_CALCULATE_PRICE_PARAM stCalculateParam, int * piOutTicketPrice,int * piDiscountValue)=0;
	 * 计算即时票价
	 * param[in]:
	 * 		stCalculateParam: 计算票价用的参数
	 * param[out]:
	 * 		piOutTicketPrice: 即时票价，如果有折扣，指折扣后的票价
	 * 		piDiscountValue：折扣金额
	 * author:wugang
	 * date:2015-01-30
	 * return: 同SetTpuTime
	*/
	virtual int CalculateImmediatelyTicketPrice(ST_TPU_CALCULATE_PRICE_PARAM stCalculateParam, int * piOutTicketPrice,int * piDiscountValue)=0;

	/*! \fn 		GetStationList
	* \brief        获取车站列表
	* \param[in]    int iPrice    票价
	* \param[out]   list<DWORD> * pStationList    车站列表
	* \return 		同SetTpuTime
	* \author
	* \date			2014-08-06
	*/
	virtual int GetStationList(int iPrice, list<DWORD> * pStationList) = 0;

	/*! \fn 		GetPriceSet
	* \brief        获取本车站所有票价集合
	* \param[in]    无
	* \param[out]   set<DWORD> * pPriceSet    票价集合
	* \return 		同SetTpuTime
	* \author
	* \date			2015-04-17
	*/
	virtual int GetPriceSet(set<DWORD> * pPriceSet) = 0;

	/*! \fn 		SetGateApplicationType
	* \brief        设置TPU应用类型
	* \param[in]    emAppType: TPU应用类型
	* \param[out]   无
	* \return 		同SetTpuTime
	* \author
	* \date			2015-04-17
	*/
	virtual int SetGateApplicationType(EM_AG_APPLICATION_TYPE emAppType) = 0;

	/* virtual int SoftWareDownload(char* szParamTypeID, const char* pMainVersion, const char*pSubVersion, const char* pFilePath, const char* pFileName) = 0
	 * 软件下载参数到TPU
	 * param[in]:
	 * 		pMainVersion:参数主版本
	 * 		pSubVersion:参数子版本
	 * 		pFilePath:参数文件的路径
	 * 		pFileName:参数文件名
	 * param[out]: 无
	 * author:wangyzh
	 * date:2015-08-04
	 * return: 同SetTpuTime
	*/
	virtual int SoftWareDownload(const char* pMainVersion, const char*pSubVersion, const char* pFilePath, const char* pFileName) = 0;

	/* virtual SvtConsume(int iAntenna, int iConsumeMoney, EM_TICKET_TRANS_RESULT * pemTransResult, ST_TPU_TRANS_RESULT * pstTransResultSnapshot, ST_TICKET_TRANS_DETAIL_INFO * pstTransDetailInfo) = 0;
	 * 软件下载参数到TPU
	 * param[in]:
	 * 		iAntenna:天线
	 * 		pstContextData:扣费金额
	 * param[out]: 无
	 * 		pemTransResult:交易结果
	 * 		pstTransResultSnapshot:交易快照
	 * 		pstTransDetailInfo:交易ud数据
	 * author:wangyzh
	 * date:2015-08-04
	 * return: 同SetTpuTime
	*/
	virtual int SvtConsume(int iAntenna, const ST_TPU_CONTEXT_DATA *pstContextData, ST_TPU_TRANS_RESULT * pstTransResultSnapshot, ST_TICKET_TRANS_DETAIL_INFO * pstTransDetailInfo) = 0;

	/* virtual SetServiceIP(ONLINE_BUSINESS_INFO stOnlineBusinessInfo) = 0;
	 * 设置通讯IP地址
	 * param[in]:
	 * 		stOnlineBusinessInfo:IP地址等信息
	 * param[out]: 无
	 * author:lixm
	 * date:2016-09-05
	 * return: 同SetTpuTime
	*/
	virtual int SetServiceIP(ONLINE_BUSINESS_INFO stOnlineBusinessInfo) = 0;

	/* virtual GetServiceIP(ONLINE_BUSINESS_INFO *pstOnlineBusinessInfo) = 0;
	 * 设置通讯IP地址
	 * param[in]:无
	 * param[out]:
	 * 		pstOnlineBusinessInfo:IP地址等信息
	 * author:lixm
	 * date:2016-09-05
	 * return: 同SetTpuTime
	*/
	virtual int GetServiceIP(ONLINE_BUSINESS_INFO *pstOnlineBusinessInfo) = 0;


};
typedef Loki::SingletonHolder
<
	Loki::Factory<ITPUCommonFunction, std::string, Seq<CLogOper2*> >,
	CreateUsingNew, Loki::LongevityLifetime::DieAsSmallObjectChild
> ITPUFactory;

#define REGISTER_TPU_CLASS(className) \
namespace {                                                                            \
	ITPUCommonFunction* create(CLogOper2 *pSleLog) { return new className(pSleLog); }                                              \
const bool ITPUFactory__ = ITPUFactory::Instance().Register( #className, create );  \
}
#endif /* ITPUCOMMONFUNCTION_H_ */
