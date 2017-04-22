/*
 * VirObjTvmCoreForUI.h
 *
 *  Created on: Aug 29, 2014
 *      Author: root
 */

#ifndef VIROBJCOREFORAGMUI_H_
#define VIROBJCOREFORAGMUI_H_




#include "VirObjectBase.h"

class CVirObjCoreForAgmUI :public CVirObjectBase
{
public:
	CVirObjCoreForAgmUI();
	virtual ~CVirObjCoreForAgmUI();

	/*! \fn void VersionQueryRequest(int *piAddiLen, void *pAddiData);
	 * \brief 		版本查询
	 * \param[out] 	pVersionRecordList  版本记录LIST
	 * \return  	成功 true； 失败 false
	 * \author 		wugang
	 * \date 		2015－4－12
	 */
	bool VersionQueryRequest(list<ST_CSS_VERSION_INFO>  *pVersionRecordList);

	/*! \fn AllStatusRequest
	 * \brief 			系统全状态请求
	 * \param[in]		无
	 * \return			无
	 * \author 			wangzp
	 * \date 			2015－04-13
	 */
	bool AllStatusRequest();
};

#endif /* VIROBJCOREFORAGMUI_H_ */
