/*
 * IProgressReport.h
 *
 *  Created on: Nov 28, 2013
 *      Author: root
 */

#ifndef IPROGRESSREPORT_H_
#define IPROGRESSREPORT_H_

class IProgressReport
{
public:
	/*! \fn IProgressReport::ReportProcess(int iMoudleID, int iType, int iProgress)
	 * \brief 		在软件升级、初始化等较长执行时间的功能执行时，报告执行进度
	 * \param[in]  	iMoudleID 模块标识
	 * \param[in]  	iType 功能类型  1：下载；2：初始化
	 * \param[in]  	iProgress 进度百分比，0~100
	 * \return		无
	 * \author 		吴刚
	 * \date 		2013－11－27
	*/
	virtual void ReportProcess(int iMoudleID, int iType, int iProgress) = 0;
};

#endif /* IPROGRESSREPORT_H_ */
