/* ****************************************
*	Name: Hritaban Ghosh
*	Roll Number: 19CS30053
**************************************** */

#ifndef __ZEROTIERSEAT_H__
#define __ZEROTIERSEAT_H__

#include "Seat.h"

// Specialisation of the Abstract Base Class Seat
// This is still an abstract class as not all virtual functions of the Base Class have been implemented
class ZeroTierSeat : public Seat
{
public:
	ZeroTierSeat();//Constructor
	virtual ~ZeroTierSeat();//Virtual Destructor
	virtual int GetNumberOfTiers() const;//Returns 0 as the class represents Booking Classes having Seat with 0 Tiers 

};

#endif // __ZEROTIERSEAT_H__
