/* ****************************************
*	Name: Hritaban Ghosh
*	Roll Number: 19CS30053
**************************************** */

#ifndef __THREETIERBERTH_H__
#define __THREETIERBERTH_H__

#include "Berth.h"

// Specialisation of the Abstract Base Class Berth
// This is still an abstract class as not all virtual functions of the Base Class have been implemented
class ThreeTierBerth : public Berth
{
	public:
		ThreeTierBerth();//Constructor
		virtual ~ThreeTierBerth();//Virtual Destructor
		virtual int GetNumberOfTiers() const;//Returns 3 as the class represents Booking Classes having Berth with 3 Tiers 

};

#endif // __THREETIERBERTH_H__
