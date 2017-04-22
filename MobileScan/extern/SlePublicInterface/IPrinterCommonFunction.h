/*
 * IPrinterCommonFunction.h
 *
 *  Created on: 2014-10-14
 *      Author: root
 */

#ifndef IPRINTERCOMMONFUNCTION_H_
#define IPRINTERCOMMONFUNCTION_H_

#include "AfcPublic.h"
#include "IDeviceCommonFunction.h"


#include <loki/Singleton.h>
#include <loki/Factory.h>
#include <loki/Sequence.h>
#include <CLogOper2.h>

using namespace Loki;

////字符打印格式定义
//typedef struct _ST_FONT_FORMAT_
//{
//	bool bUnderLine;				//字符是否加下划线
//	bool bBold;						//字符是否加粗
//	BYTE ucHeightTimes;				//高度放大倍数
//	BYTE ucWidthTimes;				//宽度放大倍数
//
//}ST_FONT_FORMAT;

//字体格式定义
typedef struct _ST_FONT_FORMAT_
{
	int iFontType;
	bool bBold;
	bool bUnderLine;
	BYTE ucHeightTimes;				//高度放大倍数
	BYTE ucWidthTimes;				//宽度放大倍数

}ST_FONT_FORMAT;

////打印字符数据及格式
//typedef struct _ST_PRINT_DATA_
//{
//	BYTE szPrintContent[512];		//打印内容
//	ST_FONT_FORMAT stFormat;		//打印格式
//
//}ST_PRINT_DATA;



class IPrinterCommonFunction : public IDeviceCommonFunction
{

public:
	/*!\fn  bool PrintTextData(char *pData)
	 *\brief 		打印字符数据
	 *\param[in] 	pstPrintData	--数据与格式信息
	 *\param[in]
	 *\return	是否执行成功
	 *\author: shaopf
	 *\date 2014-10-14
	 */
	virtual bool PrintTextData(char *pData) = 0;

	/*!\fn  bool PrintBitmap(const char *pBitmapPath)
	 *\brief 		打印位图
	 *\param[in] 	pBitmapPath  -- 位图文件绝对路径
	 *\return	是否执行成功
	 *\author: shaopf
	 *\date 2014-10-14
	 */
	virtual bool PrintBitmap(const char *pBitmapPath) = 0;

	/*!\fn  bool SetPrintMode(ST_FONT_FORMAT *pstFontFormat)
	 *\brief 		设置打印格式
	 *\param[in] 	pstFontFormat  -- 字符格式
	 *\return	是否执行成功
	 *\author: shaopf
	 *\date 2014-10-14
	 */
	virtual bool SetPrintMode(ST_FONT_FORMAT *pstFontFormat) = 0;

	/*!\fn  	bool ClearPrintMode(ST_FONT_FORMAT *pstFontFormat)
	 *\brief
	 *\param[in]	pstFontFormat -- 清除打印格式-- 传入之前设置的打印格式数据，即SetPrintMode的入参
	 *\return	是否执行成功
	 *\author: shaopf
	 *\date 2014-10-14
	 */
	virtual bool ClearPrintMode(ST_FONT_FORMAT *pstFontFormat) = 0;

	/*!\fn  	FeedLine(int iLineNums)
	 *\brief	打印机走纸 iLineNums 行
	 *\param[in]	iLineNums -- 走纸行数
	 *\return
	 *\author: shaopf
	 *\date 2014-10-14
	 */
	virtual void FeedLine(int iLineNums) = 0;

	/*!\fn  	CutPaper
	 *\brief	打印完毕，需要切纸
	 *\param[in]
	 *\return
	 *\author: shaopf
	 *\date 2014-10-14
	 */
	virtual bool CutPaper() = 0;

};



class CLogOper2;

typedef Loki::SingletonHolder
<
	Loki::Factory<IPrinterCommonFunction, std::string, Seq<CLogOper2*> >,
	CreateUsingNew, Loki::LongevityLifetime::DieAsSmallObjectChild
> PrinterBaseFactory;

#define REGISTER_COMM_PRINTER_BIZ(className) \
namespace {                                                                            \
	IPrinterCommonFunction* CreatePrinterBase(CLogOper2 *m_SleLog ) { return new className(m_SleLog ); }                                              \
const bool PrinterBaseFactory__ = PrinterBaseFactory::Instance().Register( #className, CreatePrinterBase );  \
}

class IPrinterCommonFunction;
extern IPrinterCommonFunction *pPrinterUnitBase;



#endif /* IPRINTERCOMMONFUNCTION_H_ */
