/* ****************************************
*	Name: Hritaban Ghosh
*	Roll Number: 19CS30053
**************************************** */

#include "ZeroTierSeat.h"

//Constructor
ZeroTierSeat::ZeroTierSeat()
{
}

//Virtual Destructor
ZeroTierSeat::~ZeroTierSeat()
{
}

//Returns 0 as the class represents Booking Classes having Seat with 0 Tiers 
int ZeroTierSeat::GetNumberOfTiers() const
{
	return 0;
}
