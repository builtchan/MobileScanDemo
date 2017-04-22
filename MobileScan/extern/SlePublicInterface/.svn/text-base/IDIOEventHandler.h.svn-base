/*
 * IDIOEventHandler.h
 *
 *  Created on: Nov 27, 2014
 *      Author: root
 */

#ifndef IDIOEVENTHANDLER_H_
#define IDIOEVENTHANDLER_H_

#define ADDITIONAL_UNIT_ID_DOOR			0x8001
#define ADDITIONAL_UNIT_ID_CASHDOOR		0x8002
#define ADDITIONAL_UNIT_ID_WARING		0x8003
#define ADDITIONAL_UNIT_ID_POWER		0x8004
#define ADDITIONAL_UNIT_ID_PERSON		0x8005
#define ADDITIONAL_UNIT_ID_CARDSET		0x8006
#define ADDITIONAL_UNIT_ID_HELPBT		0x8007
#define ADDITIONAL_UNIT_ID_COINBOX1		0x8011
#define ADDITIONAL_UNIT_ID_COINBOX2		0x8012


class IDIOEventHandler
{
public:
	/*!\fn  IDIOEventHandler::DiStatusChange(unsigned short usDIStatus)
	 *\brief 		.
	 *\param[in]
	 *\return  		无
	 *\author: 		longjg
	 *\date 		2014-11-18
	 */
	//virtual void DiStatusChange(unsigned short usDIStatus) = 0;
	virtual void UnitRemoved(int iUnitID) = 0;
	virtual void UnitReady(int iUnitID) = 0;

	virtual void CoinboxRemoved(int iIndex) = 0;
	virtual void CoinboxReady(int iIndex) = 0;

	virtual void DoorOpened() = 0;
	virtual void DoorClosed() = 0;

	virtual void CashDoorOpened() = 0;
	virtual void CashDoorClosed() = 0;

	virtual void FireWarning() = 0;
	virtual void CancelWarning() = 0;

	virtual void PowerOk() = 0;
	virtual void PowerNg() = 0;

	virtual void PersonClose() = 0;
	virtual void PersonLeave() = 0;

	virtual void CardIn() = 0;
	virtual void CardOut() = 0;

	virtual void HelpPress() = 0;
	virtual void HelpRelease() = 0;

	virtual void BoxBaffleOpen(bool bIsOpened) = 0;
};

#endif /* IDIOEVENTHANDLER_H_ */
