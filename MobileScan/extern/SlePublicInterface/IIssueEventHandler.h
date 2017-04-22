/*
 * ITokenEventHandler.h
 *
 *  Created on: Nov 18, 2014
 *  处理Token库存的回调类
 *      Author: root
 */

#ifndef IISSUEEVENTHANDLER_H_
#define IISSUEEVENTHANDLER_H_
#include <list>
#include "AfcPublic.h"
using namespace std;
class IIssueEventHandler
{
public:
	/*!\fn  IIssueEventHandler::OutTicketCount(int iOutTicketCount)
	 *\brief 		库存变动通知.
	 *\param[in]	票箱出票数量
	 *\param[out]	票箱出票数量
	 *\return  		无
	 *\author: 		longjg
	 *\date 		2014-11-18
	 */
	virtual void OutTicketCount(int iTicketboxNo, int iOutTicketCount) = 0;
	/*
	 * void TicketFlushNotify(list<ST_TICKET_FLUSH_PARAM> * pTicketboxParamList, bool bFinished)
	 * \brif 票箱实时上报清空过程和结果(异步)
	 * \param[out] *pTicketboxParamList 清空上报数目
	 * author: hehj
	 *\date 2014-4-15
	 */
	virtual void TicketFlushNotify(list<ST_TICKET_FLUSH_PARAM> * pTicketboxParamList, EM_FLUSH_STATUS emFlushStatus) = 0;
};


#endif /* IISSUEEVENTHANDLER_H_ */
