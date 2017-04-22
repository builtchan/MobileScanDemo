/*
 * ICashEventHandler.h
 *
 *  Created on: Aug 20, 2014
 *  实现回调函数
 *      Author: root
 */

#ifndef ICASHEVENTHANDLER_H_
#define ICASHEVENTHANDLER_H_

#include "AfcPublic.h"

#include <list>

using namespace std;

//异步消息回调类接口 业务层实现
class ICashEventHandler
{
public:

	/*!\fn  PaymentNotify(list<ST_CASH_INFO> stCashInfoList)
	 *\brief 投入通知. 由业务层实现类回调函数注入下层部件接口类。
	 *\param[in] pCashInfoList 支付信息列表(支持多张/枚)
	 *\return
	 *\author: longjg
	 *\date 2016-11-11
	 */
	virtual void PaymentNotify(list<ST_CASH_INFO> stCashInfoList) = 0;

	/*!\fn  void PaymentNotify(int iCashCount)
	 *\brief 不识别或不接收的纸币，模块自动退币通知 由业务层实现类回调函数注入下层部件接口类。
	 *\param[in] iCashCount 退出现金数量
	 *\param[out]
	 *\return
	 *\author: shaopf
	 *\date 2014-7-16
	 */
	virtual void RejectCashNotify(int iCashCount) = 0;

	/*!\fn  void FailtureNotify()
	 *\brief 故障通知. 业务层应强制取消当前进行的交易，实现类回调函数注入下层部件接口类。
	 *\param[in]
	 *\param[out]
	 *\return
	 *\author: shaopf
	 *\date 2014-7-16
	 */
	virtual void FailtureNotify() = 0;
	/*
	 * void FlushNotify()
	 * \brif 现金箱实时上报清空过程和结果(异步)
	 * \param[out] *pCashboxParamList 清空上报数目
	 * \param[out] *emFinished 清空/回收状态
	 * author: hehj
	 *\date 2014-4-3
	 */
	virtual void FlushNotify(list<ST_CASH_FLUSH_PARAM> * pCashboxParamList, EM_FLUSH_STATUS emFinished) = 0;
	/*
	 * void RecycleNotify()
	 * \brif 现金箱实时上报清空过程和结果(异步)
	 * \param[out] *pCashboxParamList 清空/回收上报数目
	 * \param[out] *emFinished 清空/回收状态
	 * author: hehj
	 *\date 2015-8-24
	 */
	virtual void RecycleNotify(list<ST_CASH_FLUSH_PARAM> * pCashboxParamList, EM_FLUSH_STATUS emFinished) = 0;

	/*
	 * void RecycleNotify()
	 * \brif 现金箱补币通知 (目的保存钱币的流转)
	 * \param[out] *pCashboxParamList 补币详细信息
	 * \param[out] *emFinished 补币状态
	 * author: shaopf
	 *\date 2015-11-06
	 */
	virtual void SupplyNotify(list<ST_CASH_FLUSH_PARAM> * pStockChangeList, EM_FLUSH_STATUS emStatus) = 0;

};

#endif /* ICASHEVENTHANDLER_H_ */
