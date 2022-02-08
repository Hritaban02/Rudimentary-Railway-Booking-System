/* ****************************************
*	Name: Hritaban Ghosh
*	Roll Number: 19CS30053
**************************************** */

#ifndef __BOOKING_CLASS_H__
#define __BOOKING_CLASS_H__

#include <string>

class BookingClass//Abstract Base Class
{
	public:
		BookingClass();//Constructor
		virtual ~BookingClass();//Virtual Destructor
		virtual double GetLoadFactor() const = 0;//Returns the Load Factor of the Booking Class
		virtual std::string GetName() const = 0;//Returns the Name of the Booking Class
		virtual bool IsSitting() const = 0;//Returns true if the Booking Class has Seat else false 
		virtual bool IsAC() const = 0;//Returns true if the Booking Class has AC else false 
		virtual int GetNumberOfTiers() const = 0;//Returns the Number Of Tiers of the Booking Class
		virtual bool IsLuxury() const = 0;//Returns true if the Booking Class is Luxury else false 

};

#endif // __BOOKING_CLASS_H__
