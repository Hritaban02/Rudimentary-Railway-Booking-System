/* ****************************************
*	Name: Hritaban Ghosh
*	Roll Number: 19CS30053
**************************************** */

#ifndef __AC3TIER_H__
#define __AC3TIER_H__

#include "ThreeTierBerth.h"
#include <string>

// Specialisation of the Abstract Base Class ThreeTierBerth
// This is a singleton concrete class as all virtual functions of the Base Class have been implemented
class AC3Tier : public ThreeTierBerth
{
	private:
		static const double sloadFactor; //Stores the load factor of the Booking Class
		
	public:
		static const AC3Tier& Instance();//Creates a Singleton Instance of the Class
		
	private:
		AC3Tier();//Constructor
		virtual ~AC3Tier();//Virtual Destructor
	
	public:
		virtual double GetLoadFactor() const; //Returns the Load Factor
		virtual std::string GetName() const; //Returns the name of the Booking Class
		virtual bool IsAC() const; //Returns whether the Booking Class is AC or not
		virtual bool IsLuxury() const; //Returns whether the Booking Class is Luxury or not
		
	public:
		//STATIC UNIT TEST FUNCTION
		static void UnitTestAC3Tier();// Test application for AC3Tier

};

#endif // __AC3TIER_H__
