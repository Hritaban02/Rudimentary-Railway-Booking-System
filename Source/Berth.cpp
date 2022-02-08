/* ****************************************
*	Name: Hritaban Ghosh
*	Roll Number: 19CS30053
**************************************** */

#include "Berth.h"

//Constructor
Berth::Berth()
{
}

//Virtual Destructor
Berth::~Berth()
{
}

//Returns true as the class represents all BookingClasses with Berth
bool Berth::IsSitting() const
{
	return false;
}
