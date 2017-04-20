/*! \file   IDeviceCommonFunction
 *  \version 1.0
 *  \brief  约束所有基于RS232通信的模块，必须实现的功能接口。
 *  \author 吴刚
 *  \date   2013－11－27
 *  \par    修改记录:
 *  \par
 *  \par
 */

#ifndef IDEVICECOMMONFUNCTION_H_
#define IDEVICECOMMONFUNCTION_H_

#include "AfcPublic.h"
#include "IProgressReport.h"
#include <list>

using namespace std;

/*! \class IDeviceCommonFunction
* \version	1.0
* \brief  	约束所有基于RS232通信的模块，必须实现的功能接口。
* \author	吴刚
* \date		2013－11－27
* \par		修改记录
* \par
*/
class IDeviceCommonFunction
{
public:
	/*! \fn IDeviceCommonFunction::Connect(const char* pszComPath)
	 * \brief 		建立通信连接(打开串口)。如果通信连接已经建立，返回true
	 * \param[in]  	pszComPath 串口标识
	 * \return		true: 通信连接成功；false：通信连接失败
	 * \author 		吴刚
	 * \date 		2013－11－27
	*/
	virtual bool Connect(const char* pszComPath) = 0;

	/*! \fn IDeviceCommonFunction::Connect(const char* pszComPath, int iBaud, int iDataBits, char cParity, int iStopBits)
	 * \brief 		建立通信连接(打开串口)。如果通信连接已经建立，返回true
	 * \param[in]  	pszComPath 串口标识
	 * \param[in]  	iBaud 波特率
	 * \param[in]  	iDataBits 数据位，7 or 8
	 * \param[in]  	cParity 校验位 'N' or 'O' or 'E'
	 * \param[in]  	iStopBits 停止位， 1 or 2
	 * \return		true: 通信连接成功；false：通信连接失败
	 * \author 		吴刚
	 * \date 		2013－11－27
	*/
	virtual bool Connect(const char* pszComPath, int iBaud, int iDataBits, char cParity, int iStopBits) = 0;

	/*! \fn IDeviceCommonFunction:: Disconnect()
	 * \brief 		关闭通信连接。如果通信连接没有建立，则不执行任何操作。
	 * \author 		吴刚
	 * \date 		2013－11－27
	*/
	virtual void Disconnect() = 0;

	/*! \fn IDeviceCommonFunction::GetDeviceCommonState()
	 * \brief 		获取硬件模块的通用状态
	 * \return		通用状态
	 * \	EM_DEVICE_COMMON_STATE_CONNECT_ERROR,	//打开COM口失败，不能提供服务
	 * \	EM_DEVICE_COMMON_STATE_COMM_FAILTURE,	//设备通信失败，不能提供服务
	 * \	EM_DEVICE_COMMON_STATE_UNINIT,		//设备没有初始化，或者初始化没有完成，不能提供服务
	 * \	EM_DEVICE_COMMON_STATE_DLING,		//模块正在下载软件，不能提供服务
	 * \	EM_DEVICE_COMMON_STATE_FAILTURE ,	//模块故障，不能提供服务
	 * \	EM_DEVICE_COMMON_STATE_MAINTAIN ,	//模块需要维护（如票箱不到位、满、空），不能提供服务
	 * \	EM_DEVICE_COMMON_STATE_REMOVE,		//模块不到位，不能提供服务
	 * \	EM_DEVICE_COMMON_STATE_DEGRAD,		//模块部分功能不能使用，但能提供能够降级服务
	 * \	EM_DEVICE_COMMON_STATE_WARNING,		//模块能提供全功能服务，但有预警信息
	 * \	EM_DEVICE_COMMON_STATE_OK,			//模块完好，能提供全功能服务
	 * \author 		吴刚
	 * \date 		2013－11－27
	*/
	//virtual EM_DEVICE_COMMON_STATE GetDeviceCommonState() = 0;


	/*! \fn IDeviceCommonFunction::GetCommQuality()
	 * \brief 		获取串口通信的质量值
	 * \return		通信质量值（0为最好， 值越大， 质量越差）
	 * \author 		吴刚
	 * \date 		2013－11－27
	*/
	virtual int GetCommQuality() = 0;

	/*! \fn IDeviceCommonFunction::Init(const void * pParam)
	 * \brief 		初始化模块。
	 * \param[in]  	pParam  不同类型的模块，定义不同。不需要参数时，可以为NULL。
	 * \return		COMMOM_FUNC_OK         1    //执行成功
	 * \            COMMOM_FUNC_FAIL       0    //执行失败
	 * \            COMMOM_FUNC_CMDERR   (-1)   //指令错误，没有被执行
	 * \            COMMOM_FUNC_UNSUPP   (-2)   //模块不支持此项功能
	 * \author 		吴刚
	 * \date 		2013－11－27
	*/
	virtual int Init(const void * pParam) = 0;

	/*! \fn IDeviceCommonFunction::GetVersion(char *pszVerBuf, int iBufSize)
	 * \brief 		获取模块版本信息。
	 * \param[in]  	emUnitType 模块类型，赋值到出参结构体中。
	 * \param[out]  pstVersionInfoList 版本信息list, 硬件适配层模块将本模块版本信息push到list，不能更改list原有信息。
	 * \return		同Init
	 * \author 		吴刚
	 * \date 		2013－11－27
	*/
	virtual int GetVersion(EM_SLE_UNIT_TYPE emUnitType, list<ST_CSS_VERSION_INFO> * pstVersionInfoList) = 0;

	/*! \fn IDeviceCommonFunction::Reset(bool bResetFirmware, const void * pParam)
	 * \brief 		模块复位。
	 * \param[in]   bResetFirmware true: 复位硬件。
	 * \param[in]  	pParam 不同类型的模块，定义不同。不需要参数时，可以为NULL。
	 * \return		同Init
	 * \author 		吴刚
	 * \date 		2013－11－27
	*/
	virtual int Reset(bool bResetFirmware, const void * pParam) = 0;

	/*! \fn IDeviceCommonFunction::GetParam (void * pParam)
	 * \brief 		获取模块运行参数。
	 * \param[out]  pParam 不同类型的模块，定义不同。
	 * \return		同Init
	 * \author 		吴刚
	 * \date 		2013－11－27
	*/
	virtual int GetParam (void * pParam) = 0;

	/*! \fn IDeviceCommonFunction::SetParam (const void * pParam)
	 * \brief 		设置模块运行参数。
	 * \param[in]   pParam 不同类型的模块，定义不同。
	 * \return		同Init
	 * \author 		吴刚
	 * \date 		2013－11－27
	*/
	virtual int SetParam (const void * pParam) = 0;

	/*! \fn IDeviceCommonFunction::GetLogData(int iLogType, unsigned char * pszBuffer, int iBufSize)
	 * \brief 		查询模块日志。
	 * \param[in]   iLogType 要获取的日志类型。
	 * \param[out]  pszBuffer 保存日志Buffer。
	 * \param[in]   iBufSize pszBuffer的size。
	 * \return		同Init
	 * \author 		吴刚
	 * \date 		2013－11－27
	*/
	virtual int GetLogData(int iLogType, unsigned char * pszBuffer, int iBufSize) = 0;

	/*! \fn IDeviceCommonFunction::ClearLogData(int iLogType)
	 * \brief 		清除模块日志。
	 * \param[in]   iLogType 要清除的日志类型。
	 * \return		同Init
	 * \author 		吴刚
	 * \date 		2013－11－27
	*/
	virtual int ClearLogData(int iLogType) = 0;

	/*! \fn IDeviceCommonFunction::GetDeviceStatus (void * pParam)
	 * \brief 		获取模块状态。
	 * \param[out]  pParam 一般为状态结构体，不同类型的模块，定义不同。
	 * \return		同Init
	 * \author 		吴刚
	 * \date 		2013－11－27
	*/
	virtual int GetDeviceStatus (void * pParam) = 0;

	/*! \fn IDeviceCommonFunction::SetMaintainMode (bool set)
	 * \brief 		设置或退出维修模式。
	 * \param[in]  set true: 设置；false：退出
	 * \return		同Init
	 * \author 		吴刚
	 * \date 		2013－11－27
	*/
	virtual int SetMaintainMode (bool set) = 0;

	/*! \fn IDeviceCommonFunction::SetTestMode (bool set)
	 * \brief 		设置或退出测试模式。
	 * \param[in]  set true: 设置；false：退出
	 * \return		同Init
	 * \author 		吴刚
	 * \date 		2013－11－27
	*/
	virtual int SetTestMode (bool set) = 0;

	/*! \fn IDeviceCommonFunction::StepTest (int iTestItem, const unsigned char * pszTestParam)
	 * \brief 		单体测试。
	 * \param[in]   iTestItem 测试项目枚举值:  电机，电磁铁,蜂鸣器
	 * \param[in]   pszTestParam 对应iTestItem的测试参数, 电机序号，电磁铁序号。可以为NULL
	 * \return		同Init
	 * \author 		吴刚
	 * \date 		2013－11－27
	*/
	virtual int StepTest (int iTestItem, const unsigned char * pszTestParam) = 0;

	/*! \fn IDeviceCommonFunction::TestSensorStatus (unsigned char * pszStatus, int * piSensorNum)
	 * \brief 		测试传感器，获取传感器状态。
	 * \param[out]  pszStatus 每1个bit对应1个传感器状态，0表示闭合，1表示断开
	 * \param[out]  piSensorNum 传感器数量
	 * \return		同Init
	 * \author 		吴刚
	 * \date 		2013－11－27
	*/
	virtual int TestSensorStatus (unsigned char * pszStatus, int * piSensorNum) = 0;

	/*! \fn IDeviceCommonFunction::UpdateFireWare(const char * szPortName, int iBaud, int iDataBits, char cParity, int iStopBits, const char * szFileName, int iBlockSize, IProgressReport * pcProgressReport)
	 * \brief 		固件软件下载。
	 * \param[in]   szPortName：COM端口
	 * \param[in]   iBaud: 波特率
	 * \param[in]   iDataBits：数据位
	 * \param[in]   cParity：校验方式
	 * \param[in]   iStopBits：停止位
	 * \param[in]   szFileName：固件软件存放文件路径
	 * \param[in]   iBlockSize：每帧数据大小
	 * \param[in]   pcProgressReport: 下载进度报告接收对象, 可以为NULL
	 * \param[in]   pszTestParam 对应iTestItem的测试参数, 可以为NULL
	 * \return		同Init
	 * \author 		吴刚
	 * \date 		2013－11－27
	*/
	virtual int UpdateFireWare(const char * szPortName, int iBaud, int iDataBits, char cParity, int iStopBits, const char * szFileName, int iBlockSize, IProgressReport * pcProgressReport) = 0;
};

#endif /* IDEVICECOMMONFUNCTION_H_ */
