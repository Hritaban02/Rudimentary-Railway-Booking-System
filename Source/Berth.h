/* ****************************************
*	Name: Hritaban Ghosh
*	Roll Number: 19CS30053
**************************************** */

#ifndef __BERTH_H__
#define __BERTH_H__

#include "BookingClass.h"

// Specialisation of the Abstract Base Class BookingClass
// This is still an abstract class as not all virtual functions of the Base Class have been implemented
class Berth : public BookingClass
{
	public:
		Berth();//Constructor
		virtual ~Berth();//Virtual Destructor
		virtual bool IsSitting() const;//Returns true as the class represents all BookingClasses with Berth

};

#endif // __BERTH_H__
