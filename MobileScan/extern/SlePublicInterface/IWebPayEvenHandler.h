/*
 * IWebPayEvenHandler.h
 *
 *	Func:用于网络支付异步消息的回调类
 *
 *  Created on: Apr 17, 2017
 *      Author: chenjc
 */

#ifndef IWEBPAYEVENHANDLER_H_
#define IWEBPAYEVENHANDLER_H_


class CIWebPayEvenHandler
{

public:

	/*!\fn  void QRCodeDataNotify(const void * pData)
	 *\brief 	二维码数据接收通知，由部件层回调
	 *\param[in]
	 *\return
	 *\author: chenjc
	 *\date 2017-04-17
	 */
	virtual void QRCodeDataNotify(const void * pData) = 0;

	/*!\fn  void PaymentNotify(const void * pData)
	 *\brief 		支付通知，由部件层回调
	 *\param[in]
	 *\return
	 *\author: chenjc
	 *\date 2017-04-17
	 */
	virtual void PaymentNotify(const void * pData) = 0;

	/*!\fn  void FailtureNotify(const void * pData)
	 *\brief 		支付失败，由部件层回调
	 *\param[in]
	 *\return
	 *\author: chenjc
	 *\date 2017-04-17
	 */
	virtual void FailtureNotify(const void * pData) = 0;
};


#endif /* IWEBPAYEVENHANDLER_H_ */
