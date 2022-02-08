/* ****************************************
*	Name: Hritaban Ghosh
*	Roll Number: 19CS30053
**************************************** */

#include "ThreeTierBerth.h"

//Constructor
ThreeTierBerth::ThreeTierBerth()
{
}

//Virtual Destructor
ThreeTierBerth::~ThreeTierBerth()
{
}

//Returns 3 as the class represents Booking Classes having Berth with 3 Tiers 
int ThreeTierBerth::GetNumberOfTiers() const
{
	return 3;
}
