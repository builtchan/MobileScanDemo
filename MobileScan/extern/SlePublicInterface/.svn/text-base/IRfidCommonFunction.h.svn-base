/*! \file   IRfidCommonFunction
 *  \version 1.0
 *  \brief  RFID功能接口
 *  \author 吴刚
 *  \date   2015－02－20
 *  \par    修改记录:
 *  \par
 *  \par
 */

#ifndef IRFIDCOMMONFUNCTION_H_
#define IRFIDCOMMONFUNCTION_H_

#include "AfcPublic.h"


class IRfidCommonFunction
{
public:
	/*! \fn 		ReadBoxRFID
	 * \brief 		读取钱票箱Rfid信息
	 * param[in] 	1. int iBoxType: 钱票箱类型，对于钱箱，属于EM_CASH_CONTAINER_TYPE，对于票箱，属于EM_TICKET_CONTAINER_TYPE
	 * param[in] 2.EM_BOX_NO 	emBoxNo: 钱票箱号
	 * param[in] 	3.BYTE szBlockMark，块标识
	 *           	bit0~bit127,分别代表块0~块127，1有效，0无效；
	 *          	根据RFID类型不同,每个“块/扇区“的长度可能为4，16不等。
	 * param[out]4.void* 	pReadData：读取钱箱RFID的数据
	 * param[out]5. int* 	piReadDatalen：读取RFID的数据长度。该长度=每块的长度*读取块的数量
	 * 返回值：Int
	 * 				COMMOM_FUNC_OK         1    执行成功
	 *            	COMMOM_FUNC_FAIL       0    执行失败
	 *           	COMMOM_FUNC_CMDERR   (-1)   指令错误，没有被执行
	 *           	COMMOM_FUNC_UNSUPP   (-2)   模块不支持此项功能
	 */
	virtual int ReadBoxRFID(int iBoxType, EM_BOX_NO emBoxNo, BYTE szBlockMark[16], void  *pReadData,  int * piReadDatalen) = 0;//只读箱子ID
	virtual int ReadBoxRFID(int iBoxType, EM_BOX_NO emBoxNo, BYTE szBlockMark[16], ST_CASHBOX_RFID_INFO * stCashBoxRfidInfo) = 0;
	virtual int ReadBoxRFID(int iBoxType, EM_BOX_NO emBoxNo, BYTE szBlockMark[16], ST_TICKETBOX_RFID_INFO * stTicketBoxRfidInfo) = 0;

	/*! \fn 		WriteBoxRFID
	 * \brief 		写入钱票箱Rfid信息
	 * param[in] 	iBoxType: 钱票箱类型，对于钱箱，属于EM_CASH_CONTAINER_TYPE，对于票箱，属于EM_TICKET_CONTAINER_TYPE
	 * param[in] 	emBoxNo: 钱票箱号
	 * param[in] 	szBlockMark，块标识
	 *           	bit0~bit127,分别代表块0~块127，1有效，0无效；
	 *           	根据RFID类型不同,每个“块/扇区“的长度可能为4，16不等。
	 * param[in] 	pReadData：欲写入的钱箱的RFID信息
	 * param[in] 	iWriteDatalen：钱箱RFID信息长度。该长度=每块的长度*写入块的数量
	 * 返回值：		同ReadBoxRFID
	 */
	virtual int WriteBoxRFID(int iBoxType, EM_BOX_NO emBoxNo, BYTE szBlockMark[16], const void *pWriteData, int iWriteDatalen) = 0;

	/*

	 */
	virtual int WriteBoxRFID(int iBoxType, EM_BOX_NO emBoxNo, BYTE szBlockMark[16], ST_CASHBOX_RFID_INFO stCashBoxRfidInfo) = 0;

	/*

	 */
	virtual int WriteBoxRFID(int iBoxType, EM_BOX_NO emBoxNo, BYTE szBlockMark[16], ST_TICKETBOX_RFID_INFO stTicketBoxRfidInfo) = 0;


	/*! \fn 		PollingBoxRFID
	 * \brief 		通过RFID检查钱票箱是否存在
	 * param[in] 	iBoxType: 钱票箱类型，对于钱箱，属于EM_CASH_CONTAINER_TYPE，对于票箱，属于EM_TICKET_CONTAINER_TYPE
	 * param[in] 	emBoxNo: 钱票箱号
	 * 返回值：		同ReadBoxRFID
	 */
	virtual int PollingBoxRFID(int iBoxType, EM_BOX_NO emBoxNo) = 0;




};

#endif /* IRFIDCOMMONFUNCTION_H_ */
