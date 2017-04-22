/*
 * IUpsEventHandler.h
 *
 *  Created on: Aug 7, 2014
 *      Author: wangyzh
 */

#ifndef IUPSEVENTHANDLER_H_
#define IUPSEVENTHANDLER_H_


//异步消息回调类接口 业务层实现
class IUpsEventHandler
{
public:

	/*!\fn  virtual void ExPowerOffNotify() = 0;
	 *\brief 市电断开通知。
	 *\return
	 *\author: wangyzh
	 *\date 2014-8-7
	 */
	virtual void ExPowerOffNotify(int iPowerLevel) = 0;

	/*!\fn  virtual void ExPowerOnNotify() = 0;
	 *\brief 市电断开通知。
	 *\return
	 *\author: wangyzh
	 *\date 2014-8-7
	 */
	virtual void ExPowerOnNotify(int iPowerLevel) = 0;
};
#endif /* IUPSEVENTHANDLER_H_ */
