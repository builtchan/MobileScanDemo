/*! \file   CIpcMsgText.h
 *  \version 1.0
 *  \brief  IPC 消息文本类
 *  \author 薛峰
 *  \date   2013－10－15
 *  \par    修改记录:
 *  \par
 *  \par
 */
#ifndef CIPCMSGTEXT_H_
#define CIPCMSGTEXT_H_

#include "ipcpublic.h"
#include <list>
#include <map>
#include <set>

using namespace std;

#define MSG_PARAM_MIN_NUM      0/*!<参数最小序号*/
#define MSG_PARAM_MAX_NUM      5/*!<参数最大序号*/

#define MSG_PARAM_WORD_LOW     0/*!<参数字序低位*/
#define MSG_PARAM_WORD_HIGH    1/*!<参数字序高位*/

#define MSG_PARAM_BYTE_0 	   0/*!<参数字节序低位*/
#define MSG_PARAM_BYTE_1 	   1/*!<参数字节序1位*/
#define MSG_PARAM_BYTE_2 	   2/*!<参数字节序2位*/
#define MSG_PARAM_BYTE_3 	   3/*!<参数字节序高位*/


/*! \class CIpcMsgText
* \version	1.0
* \brief  	IPC 消息文本类
* \author	薛峰
* \date		2013－10－15
* \par		修改记录
* \par
*/
class CIpcMsgText
{
public:

	/*! \fn CIpcMsgText::CIpcMsgText(void)
	 * \brief 		默认构造函数
	 * \author 		薛峰
	 * \date 		2013－10－15
	*/
	CIpcMsgText();

	/*! \fn CIpcMsgText::CIpcMsgText(const unsigned char * pcText, int iTextLen)
	 * \brief 		构造函数 根据消息内容和消息长度
	 * \param[in] 	pcText 消息内容
	 * \param[in]	iTextLen 消息总长度（结构体长度+附加数据段长度）
	 * \author 		薛峰
	 * \date 		2013－10－15
	*/
	CIpcMsgText(const unsigned char * pcText, int iTextLen);

	/*! \fn CIpcMsgText::CIpcMsgText(unsigned short usMsgID, int iParam[6])
	 * \brief 		构造函数 根据消息ID 和消息参数
	 * \param[in] 	iMsgID 消息ID
	 * \param[in]	iParam[6] 消息参数
	 * \author 		薛峰
	 * \date 		2013－10－15
	*/
	CIpcMsgText(int iMsgID, int iParam[6]);

	/*! \fn CIpcMsgText::CIpcMsgText(const CIpcMsgText * pCIpcMsgTextObj)
	 * \brief 		构造函数 根据另一个对象
	 * \param[in] 	pCIpcMsgTextObj 已有的CIpcMsgText对象
	 * \author 		薛峰
	 * \date 		2013－10－15
	*/
	CIpcMsgText(const CIpcMsgText * pCIpcMsgTextObj);

	/*! \fn virtual CIpcMsgText::~CIpcMsgText(void)
	 * \brief 		析构函数
	 * \author 		薛峰
	 * \date 		2013－10－15
	*/
	virtual ~CIpcMsgText();

	/*! \fn void CIpcMsgText::AttachData(const void * pAdditionalData, int iDataLen)
	 * \brief 		追加数据
	 * \param[in] 	pAdditionalData 数据源
	 * \param[in]	iDataLen 数据长度
	 * \author 		薛峰
	 * \date 		2013－10－15
	*/


	bool AppendAttachDataRecord(const void * pAdditionalDataRecord, int iRecordLen);

	/*! \fn int CIpcMsgText::GetMsgID(void)
	 * \brief 		获取消息ID
	 * \return 		成功：消息ID 失败：-1
	 * \author 		薛峰
	 * \date 		2013－10－15
	*/
	int GetMsgID();

	/*! \fn int CIpcMsgText::GetParamValueInDword(int iParamIndex)
	 * \brief 		以4字节获取参数
	 * \param[in] 	iParamIndex 消息序号
	 * \return 		成功：参数值 失败：-1
	 * \author 		薛峰
	 * \date 		2013－10－15
	*/
	int GetParamValueInDword(int iParamIndex);

	/*! \fn const int * CIpcMsgText::GetParamArrayInDword(void)
	 * \brief 		获取4字节参数数组
	 * \return 		成功：数组首地址 失败：null
	 * \author 		薛峰
	 * \date 		2013－10－15
	*/
	const int * GetParamArrayInDword();

	/*! \fn short CIpcMsgText::GetParamValueInWord(int iParamIndex, int iWordIndex)
	 * \brief 		以2字节获取参数
	 * \param[in] 	iParamIndex 参数号
	 * \param[in]	iWordIndex 字节序 0低字节
	 * \return 		成功：对应参数序号字节序值 失败：-1
	 * \author 		薛峰
	 * \date 		2013－10－15
	*/
	short GetParamValueInWord(int iParamIndex, int iWordIndex);

	/*! \fn const short * CIpcMsgText::GetParamArrayInWord(int iParamIndex)
	 * \brief 		以2字节获取参数数组
	 * \param[in] 	iParamIndex 参数序号
	 * \return 		成功：对应序号数组首地址 失败：null
	 * \author 		薛峰
	 * \date 		2013－10－15
	*/
	const short * GetParamArrayInWord(int iParamIndex);

	/*! \fn unsigned char CIpcMsgText::GetParamValueInByte(int iParamIndex, int iByteIndex)
	 * \brief 		以1字节获取参数
	 * \param[in] 	iParamIndex 参数序号
	 * \param[in]	iByteIndex 字节序号
	 * \return 		成功：对应参数序号字节序号值 失败：-1
	 * \author 		薛峰
	 * \date 		2013－10－15
	*/
	unsigned char GetParamValueInByte(int iParamIndex, int iByteIndex);

	/*! \fn const unsigned char * CIpcMsgText::GetParamArrayInByte(int iParamIndex)
	 * \brief 		以1字节获取参数数组
	 * \param[in] 	iParamIndex 参数序号
	 * \return 		成功：对应参数序号数组首地址 失败：null
	 * \author 		薛峰
	 * \date 		2013－10－15
	*/
	const unsigned char * GetParamArrayInByte(int iParamIndex);

	/*! \fn int CIpcMsgText::GetAdditionalDataLength(void)
	 * \brief 		获取附加数据长度
	 * \return 		成功：附加数据长度 失败：-1
	 * \author 		薛峰
	 * \date 		2013－10－15
	*/
	int GetAdditionalDataLength();

	/*! \fn const void * CIpcMsgText::GetAdditionalData()
	 * \brief 		获取附加数据
	 * \return 		成功：附加数据地址 失败：null
	 * \author 		薛峰
	 * \date 		2013－10－15
	*/
	bool GetAdditionalDataRecordList(list<ST_IPCMSG_ADDITIONAL_RECORD> * pstRecordList);

	/*! \fn CIpcMsgText::CIpcMsgText(const unsigned char * pcText, int iTextLen)
	 * \brief 		根据消息内容和消息长度设置消息文本内容
	 * \param[in] 	pcText 消息内容
	 * \param[in]	iTextLen 消息总长度（结构体长度+附加数据段长度）
	 * \author 		薛峰
	 * \date 		2013－10－15
	*/
	void SetText(const unsigned char * pcText, int iTextLen);

	/*! \fn CIpcMsgText::CIpcMsgText(const CIpcMsgText * pCIpcMsgTextObj)
	 * \brief 		根据另一个对象拷贝文本
	 * \param[in] 	pCIpcMsgTextObj 对象指针
	 * \author 		薛峰
	 * \date 		2013－10－15
	*/
	void paste(const CIpcMsgText * pCIpcMsgTextObj);

	/*! \fn CIpcMsgText::GetTextStream()
	 * \brief 		获取字符串流文本
	 * \return  	字符串首地址
	 * \author 		薛峰
	 * \date 		2013－10－15
	*/
	const unsigned char * GetTextStream();

	/*! \fn CIpcMsgText::GetTextStreamLength()
	 * \brief 		获取字符串流文本长度
	 * \return  	文本长度
	 * \author 		薛峰
	 * \date 		2013－10－15
	*/
	int GetTextStreamLength();

	//获取消息来源key
	EM_IPC_KEY GetIpcSourceKey();
	//设置消息来源key
	void SetIpcSourceKey(EM_IPC_KEY emKey);
public:
	ST_TEXT_DATA m_stTextData;

	EM_IPC_KEY m_emSrcIpcKey;

private:
	int m_iRecordCount;

};

#endif /*CIPCMSGTEXT_H_*/
