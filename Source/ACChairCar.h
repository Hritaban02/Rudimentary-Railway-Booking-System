/* ****************************************
*	Name: Hritaban Ghosh
*	Roll Number: 19CS30053
**************************************** */

#ifndef __ACCHAIRCAR_H__
#define __ACCHAIRCAR_H__

#include "ZeroTierSeat.h"
#include <string>

// Specialisation of the Abstract Base Class ZeroTierSeat
// This is a singleton concrete class as all virtual functions of the Base Class have been implemented
class ACChairCar : public ZeroTierSeat
{
	private:
		static const double sloadFactor; //Stores the load factor of the Booking Class
	
	public:
		static const ACChairCar& Instance();//Creates a Singleton Instance of the Class

	private:
		ACChairCar();//Constructor
		virtual ~ACChairCar();//Virtual Destructor
	
	public:
		virtual double GetLoadFactor() const; //Returns the Load Factor
		virtual std::string GetName() const; //Returns the name of the Booking Class
		virtual bool IsAC() const; //Returns whether the Booking Class is AC or not
		virtual bool IsLuxury() const; //Returns whether the Booking Class is Luxury or not
		
	public:
		//STATIC UNIT TEST FUNCTION
		static void UnitTestACChairCar();// Test application for ACChairCar

};

#endif // __ACCHAIRCAR_H__
