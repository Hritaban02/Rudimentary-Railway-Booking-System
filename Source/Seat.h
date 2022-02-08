/* ****************************************
*	Name: Hritaban Ghosh
*	Roll Number: 19CS30053
**************************************** */

#ifndef __SEAT_H__
#define __SEAT_H__

#include "BookingClass.h"

// Specialisation of the Abstract Base Class BookingClass
// This is still an abstract class as not all virtual functions of the Base Class have been implemented
class Seat : public BookingClass 
{
	public:
		Seat();//Constructor
		virtual ~Seat(); //Destructor
		virtual bool IsSitting() const;//Returns true as the class represents all BookingClasses with Seat
};

#endif // __SEAT_H__
