/*! \file   IAfcApp.h
 *  \version 1.0
 *  \brief  所有App类Base
 *  \author zhangbb
 *  \date   2014-02-27
 *  \par    修改记录:
 */
#ifndef IAFCAPP_H_
#define IAFCAPP_H_

#include "CLogOper2.h"
//#include <loki/Singleton.h>
//#include <loki/Factory.h>
//#include <loki/Sequence.h>
//using namespace Loki;//引用命名空间

/*! \class IAfcApp
* \version	1.0
* \brief  	所有App类的Base类
* \author	zhangbb
* \date		2014-02-27
* \par		修改记录
* \par
*/
class IAfcApp
{
public:

	/*! \fn 		Init()
	* \brief 		初始化(调用Start之前调用，只调用1次)
	* \param[in]  	no
	* \return 		true: 初始化成功；false：初始化失败
	* \author		zhangbb
	* \date			2014-02-27
	*/
	virtual bool Init()=0;

	/*! \fn 		Destroy()
	* \brief 		销毁
	* \param[in]  	no
	* \return 		true: 初始化成功；false：初始化失败
	* \author
	* \date			2014-02-27
	*/
	virtual bool Destroy()=0;

};
#endif /* IAFCAPP_H_ */
