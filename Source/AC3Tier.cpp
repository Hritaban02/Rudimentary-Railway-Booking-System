/* ****************************************
*	Name: Hritaban Ghosh
*	Roll Number: 19CS30053
**************************************** */

#include "AC3Tier.h"
#include <string>
#include <iostream>

//static constant 
//Stores the load factor of the Booking Class
const double AC3Tier::sloadFactor = 1.75;

//Constructor
AC3Tier::AC3Tier()
{
}

//Virtual Destructor
AC3Tier::~AC3Tier()
{
}

//Creates a Singleton Instance of the Class
const AC3Tier& AC3Tier::Instance()
{
	static const AC3Tier AC3TierInstance = AC3Tier();
	return AC3TierInstance;
}

//Returns the Load Factor
double AC3Tier::GetLoadFactor() const
{
	return AC3Tier::sloadFactor;
}

//Returns the name of the Booking Class
std::string AC3Tier::GetName() const
{
	return "AC 3 Tier";
}

//Returns whether the Booking Class is AC or not
bool AC3Tier::IsAC() const
{
	return true;
}

//Returns whether the Booking Class is Luxury or not
bool AC3Tier::IsLuxury() const
{
	return false;
}

//STATIC UNIT TEST FUNCTION
void AC3Tier::UnitTestAC3Tier()// Test application for AC3Tier
{
	std::cout << "STATIC UNIT TEST FUNCTION To unit test class AC3Tier" << std::endl << std::endl;
	
	//Check the static constants
	std::cout << "**********************************************************" << std::endl;
	std::cout << "Check the static constants:" << std::endl << std::endl;
	std::cout << "Checking the sloadFactor:" << sloadFactor << std::endl << std::endl;
	if(sloadFactor!=1.75)
	{
		std::cerr << "Error on Initialisation of sloadFactor" << std::endl;
	}
	
	//Check whether the class is singleton or not
	std::cout << "**********************************************************" << std::endl;
	std::cout << "Check whether the class is singleton or not:" << std::endl <<std::endl;
	std::cout << "Address of AC3Tier::Instance called the first time: " << &AC3Tier::Instance() << std::endl;
	std::cout << std::endl;
	std::cout << "Address of AC3Tier::Instance called the second time: " << &AC3Tier::Instance() << std::endl;
	std::cout << std::endl;
	if(&AC3Tier::Instance() !=  &AC3Tier::Instance())
	{
		std::cerr << "Error: AC3Tier is not a singleton class!!!" << std::endl;
	}
	else
	{
		std::cout << "AC3Tier is a singleton class" << std::endl;
	}

	//Check the IsSitting member Function
	std::cout << "**********************************************************" << std::endl;
	std::cout << "Check the IsSitting member Function:" << std::endl <<std::endl;
	std::cout << "AC3Tier::Instance().IsSitting() : " << AC3Tier::Instance().IsSitting() << std::endl <<std::endl;
	if(AC3Tier::Instance().IsSitting() != false)
	{
		std::cerr << "Error in isSitting member Function" << std::endl;
	}
	
	//Check the GetNumberOfTiers member Function
	std::cout << "**********************************************************" << std::endl;
	std::cout << "Check the GetNumberOfTiers member Function:" << std::endl <<std::endl;
	std::cout << "AC3Tier::Instance().GetNumberOfTiers() : " << AC3Tier::Instance().GetNumberOfTiers() << std::endl <<std::endl;
	if(AC3Tier::Instance().GetNumberOfTiers() != 3)
	{
		std::cerr << "Error in GetNumberOfTiers member Function" << std::endl;
	}
	
	//Check the GetLoadFactor member Function
	std::cout << "**********************************************************" << std::endl;
	std::cout << "Check the GetLoadFactor member Function:" << std::endl <<std::endl;
	std::cout << "AC3Tier::Instance().GetLoadFactor() : " << AC3Tier::Instance().GetLoadFactor() << std::endl <<std::endl;
	if(AC3Tier::Instance().GetLoadFactor() != sloadFactor)
	{
		std::cerr << "Error in GetLoadFactor member Function" << std::endl;
	}
	
	//Check the GetName member Function
	std::cout << "**********************************************************" << std::endl;
	std::cout << "Check the GetName member Function:" << std::endl <<std::endl;
	std::cout << "AC3Tier::Instance().GetName() : " << AC3Tier::Instance().GetName() << std::endl <<std::endl;
	if(AC3Tier::Instance().GetName() != "AC 3 Tier")
	{
		std::cerr << "Error in GetName member Function" << std::endl;
	}
	
	//Check the IsAC member Function
	std::cout << "**********************************************************" << std::endl;
	std::cout << "Check the IsAC member Function:" << std::endl <<std::endl;
	std::cout << "AC3Tier::Instance().IsAC() : " << AC3Tier::Instance().IsAC() << std::endl <<std::endl;
	if(AC3Tier::Instance().IsAC() != true)
	{
		std::cerr << "Error in IsAC member Function" << std::endl;
	}
	
	//Check the IsLuxury member Function
	std::cout << "**********************************************************" << std::endl;
	std::cout << "Check the IsLuxury member Function:" << std::endl <<std::endl;
	std::cout << "AC3Tier::Instance().IsLuxury() : " << AC3Tier::Instance().IsLuxury() << std::endl <<std::endl;
	if(AC3Tier::Instance().IsLuxury() != false)
	{
		std::cerr << "Error in IsLuxury member Function" << std::endl;
	}
	std::cout << "**********************************************************" << std::endl;
}
