/* ****************************************
*	Name: Hritaban Ghosh
*	Roll Number: 19CS30053
**************************************** */

//Imports
#include "AC2Tier.h"
#include <string>
#include <iostream>

//static constant 
//Stores the load factor of the Booking Class
const double AC2Tier::sloadFactor = 2;

//Constructor
AC2Tier::AC2Tier()
{
}

//Virtual Destructor
AC2Tier::~AC2Tier()
{
}

//Creates a Singleton Instance of the Class
const AC2Tier& AC2Tier::Instance()
{
	static const AC2Tier AC2TierInstance = AC2Tier();
	return AC2TierInstance;
}

//Returns the Load Factor
double AC2Tier::GetLoadFactor() const
{
	return AC2Tier::sloadFactor;
}

//Returns the name of the Booking Class
std::string AC2Tier::GetName() const
{
	return "AC 2 Tier";
}

//Returns whether the Booking Class is AC or not
bool AC2Tier::IsAC() const
{
	return true;
}

//Returns whether the Booking Class is Luxury or not
bool AC2Tier::IsLuxury() const
{
	return false;
}

//STATIC UNIT TEST FUNCTION
void AC2Tier::UnitTestAC2Tier()// Test application for AC2Tier
{
	std::cout << "STATIC UNIT TEST FUNCTION To unit test class AC2Tier" << std::endl << std::endl;
	
	//Check the static constants
	std::cout << "**********************************************************" << std::endl;
	std::cout << "Check the static constants:" << std::endl << std::endl;
	std::cout << "Checking the sloadFactor:" << sloadFactor << std::endl << std::endl;
	if(sloadFactor!=2)
	{
		std::cerr << "Error on Initialisation of sloadFactor" << std::endl;
	}
	
	//Check whether the class is singleton or not
	std::cout << "**********************************************************" << std::endl;
	std::cout << "Check whether the class is singleton or not:" << std::endl <<std::endl;
	std::cout << "Address of AC2Tier::Instance called the first time: " << &AC2Tier::Instance() << std::endl;
	std::cout << std::endl;
	std::cout << "Address of AC2Tier::Instance called the second time: " << &AC2Tier::Instance() << std::endl;
	std::cout << std::endl;
	if(&AC2Tier::Instance() !=  &AC2Tier::Instance())
	{
		std::cerr << "Error: AC2Tier is not a singleton class!!!" << std::endl;
	}
	else
	{
		std::cout << "AC2Tier is a singleton class" << std::endl;
	}
	
	//Check the IsSitting member Function
	std::cout << "**********************************************************" << std::endl;
	std::cout << "Check the IsSitting member Function:" << std::endl <<std::endl;
	std::cout << "AC2Tier::Instance().IsSitting() : " << AC2Tier::Instance().IsSitting() << std::endl <<std::endl;
	if(AC2Tier::Instance().IsSitting() != false)
	{
		std::cerr << "Error in isSitting member Function" << std::endl;
	}
	
	//Check the GetNumberOfTiers member Function
	std::cout << "**********************************************************" << std::endl;
	std::cout << "Check the GetNumberOfTiers member Function:" << std::endl <<std::endl;
	std::cout << "AC2Tier::Instance().GetNumberOfTiers() : " << AC2Tier::Instance().GetNumberOfTiers() << std::endl <<std::endl;
	if(AC2Tier::Instance().GetNumberOfTiers() != 2)
	{
		std::cerr << "Error in GetNumberOfTiers member Function" << std::endl;
	}
	
	//Check the GetLoadFactor member Function
	std::cout << "**********************************************************" << std::endl;
	std::cout << "Check the GetLoadFactor member Function:" << std::endl <<std::endl;
	std::cout << "AC2Tier::Instance().GetLoadFactor() : " << AC2Tier::Instance().GetLoadFactor() << std::endl <<std::endl;
	if(AC2Tier::Instance().GetLoadFactor() != sloadFactor)
	{
		std::cerr << "Error in GetLoadFactor member Function" << std::endl;
	}
	
	//Check the GetName member Function
	std::cout << "**********************************************************" << std::endl;
	std::cout << "Check the GetName member Function:" << std::endl <<std::endl;
	std::cout << "AC2Tier::Instance().GetName() : " << AC2Tier::Instance().GetName() << std::endl <<std::endl;
	if(AC2Tier::Instance().GetName() != "AC 2 Tier")
	{
		std::cerr << "Error in GetName member Function" << std::endl;
	}
	
	//Check the IsAC member Function
	std::cout << "**********************************************************" << std::endl;
	std::cout << "Check the IsAC member Function:" << std::endl <<std::endl;
	std::cout << "AC2Tier::Instance().IsAC() : " << AC2Tier::Instance().IsAC() << std::endl <<std::endl;
	if(AC2Tier::Instance().IsAC() != true)
	{
		std::cerr << "Error in IsAC member Function" << std::endl;
	}
	
	//Check the IsLuxury member Function
	std::cout << "**********************************************************" << std::endl;
	std::cout << "Check the IsLuxury member Function:" << std::endl <<std::endl;
	std::cout << "AC2Tier::Instance().IsLuxury() : " << AC2Tier::Instance().IsLuxury() << std::endl <<std::endl;
	if(AC2Tier::Instance().IsLuxury() != false)
	{
		std::cerr << "Error in IsLuxury member Function" << std::endl;
	}
	std::cout << "**********************************************************" << std::endl;
}
