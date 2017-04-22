/*! \file   IpcMsgChildContainer.h
 *  \version 1.0
 *  \brief  为业务提供消息源和入口消息
 *  \author wugang
 *  \date   2014-08-05
 *  \par    修改记录:
 */
#ifndef CIPCMSGCHILDCONTAINER_H_
#define CIPCMSGCHILDCONTAINER_H_

#include "IpcMsgSortContainer.h"


class CIpcMsgChildContainer: public CIpcMsgSortContainer
{
public:
	CIpcMsgChildContainer();
	~CIpcMsgChildContainer();

	void SetEntryMsgID(const int * szEntryMsgID, int iEntryMsgCount);
	void SetConcernedMsgID(const int * piConcernedMsgID, int iConcernedMsgIDCount);
	const int * GetEntryMsgID(int * piEntryMsgCount);
	const int * GetConcernedMsgID (int *piConcernedMsgIDCount);

protected:
	int * m_piEntryMsgID;
	int m_iEntryMsgCount;
	int * m_piConcernedMsgID;
	int m_iConcernedMsgIDCount;
};

#endif /* CIPCMSGCHILDCONTAINER_H_ */
