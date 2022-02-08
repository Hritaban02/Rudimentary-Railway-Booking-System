/* ****************************************
*	Name: Hritaban Ghosh
*	Roll Number: 19CS30053
**************************************** */

#include "TwoTierBerth.h"

//Constructor
TwoTierBerth::TwoTierBerth()
{
}

//Virtual Destructor
TwoTierBerth::~TwoTierBerth()
{
}

//Returns 2 as the class represents Booking Classes having Berth with 2 Tiers 
int TwoTierBerth::GetNumberOfTiers() const
{
	return 2;
}
