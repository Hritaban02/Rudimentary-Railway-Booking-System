/* ****************************************
*	Name: Hritaban Ghosh
*	Roll Number: 19CS30053
**************************************** */

#include "Seat.h"

//Constructor
Seat::Seat()
{
}

//Virtual Destructor
Seat::~Seat()
{
}

//Returns true as the class represents all BookingClasses with Seat
bool Seat::IsSitting() const
{
	return true;
}
