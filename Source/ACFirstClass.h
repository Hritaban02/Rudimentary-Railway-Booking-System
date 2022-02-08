/* ****************************************
*	Name: Hritaban Ghosh
*	Roll Number: 19CS30053
**************************************** */

#ifndef __ACFIRSTCLASS_H__
#define __ACFIRSTCLASS_H__

#include "TwoTierBerth.h"
#include <string>

// Specialisation of the Abstract Base Class TwoTierBerth
// This is a singleton concrete class as all virtual functions of the Base Class have been implemented
class ACFirstClass : public TwoTierBerth
{
	private:
		static const double sloadFactor;//Stores the load factor of the Booking Class
	
	public:
		static const ACFirstClass& Instance();//Creates a Singleton Instance of the Class

	private:
		ACFirstClass();//Constructor
		virtual ~ACFirstClass();//Virtual Destructor
		
	public:
		virtual double GetLoadFactor() const; //Returns the Load Factor
		virtual std::string GetName() const; //Returns the name of the Booking Class
		virtual bool IsAC() const; //Returns whether the Booking Class is AC or not
		virtual bool IsLuxury() const; //Returns whether the Booking Class is Luxury or not
		
	public:
		//STATIC UNIT TEST FUNCTION
		static void UnitTestACFirstClass();// Test application for ACFirstClass
};

#endif // __ACFIRSTCLASS_H__
