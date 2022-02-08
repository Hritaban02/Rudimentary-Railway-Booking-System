/* ****************************************
*	Name: Hritaban Ghosh
*	Roll Number: 19CS30053
**************************************** */

#ifndef __AC2TIER_H__
#define __AC2TIER_H__

#include "TwoTierBerth.h"
#include <string>

// Specialisation of the Abstract Base Class TwoTierBerth
// This is a singleton concrete class as all virtual functions of the Base Class have been implemented
class AC2Tier : public TwoTierBerth
{
	private:
		static const double sloadFactor; //Stores the load factor of the Booking Class
	
	public:
		static const AC2Tier& Instance(); //Creates a Singleton Instance of the Class

	private:
		AC2Tier(); //Constructor
		virtual ~AC2Tier(); //Virtual Destructor
	
	public:
		virtual double GetLoadFactor() const; //Returns the Load Factor
		virtual std::string GetName() const; //Returns the name of the Booking Class
		virtual bool IsAC() const; //Returns whether the Booking Class is AC or not
		virtual bool IsLuxury() const; //Returns whether the Booking Class is Luxury or not
		
	public:
		//STATIC UNIT TEST FUNCTION
		static void UnitTestAC2Tier();// Test application for AC2Tier
};

#endif // __AC2TIER_H__
