/* ****************************************
*	Name: Hritaban Ghosh
*	Roll Number: 19CS30053
**************************************** */

#ifndef __SLEEPER_H__
#define __SLEEPER_H__

#include "ThreeTierBerth.h"
#include <string>

// Specialisation of the Abstract Base Class ThreeTierBerth
// This is a singleton concrete class as all virtual functions of the Base Class have been implemented
class Sleeper : public ThreeTierBerth
{
	private:
		static const double sloadFactor;//Stores the load factor of the Booking Class
	
	public:
		static const Sleeper& Instance();//Creates a Singleton Instance of the Class

	private:
		Sleeper();//Constructor
		virtual ~Sleeper();//Virtual Destructor
		
	public:
		virtual double GetLoadFactor() const; //Returns the Load Factor
		virtual std::string GetName() const; //Returns the name of the Booking Class
		virtual bool IsAC() const; //Returns whether the Booking Class is AC or not
		virtual bool IsLuxury() const; //Returns whether the Booking Class is Luxury or not
		
	public:
		//STATIC UNIT TEST FUNCTION
		static void UnitTestSleeper();// Test application for Sleeper

};

#endif // __SLEEPER_H__
