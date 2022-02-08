/* ****************************************
*	Name: Hritaban Ghosh
*	Roll Number: 19CS30053
**************************************** */

#ifndef __TWOTIERBERTH_H__
#define __TWOTIERBERTH_H__

#include "Berth.h"

// Specialisation of the Abstract Base Class Berth
// This is still an abstract class as not all virtual functions of the Base Class have been implemented
class TwoTierBerth : public Berth
{
	public:
		TwoTierBerth();//Constructor
		virtual ~TwoTierBerth();//Virtual Destructor
		virtual int GetNumberOfTiers() const;//Returns 2 as the class represents Booking Classes having Berth with 2 Tiers 

};

#endif // __TWOTIERBERTH_H__
