/* ****************************************
*	Name: Hritaban Ghosh
*	Roll Number: 19CS30053
**************************************** */

#include "Sleeper.h"
#include <string>
#include <iostream>

//static constant 
//Stores the load factor of the Booking Class
const double Sleeper::sloadFactor = 1;

//Constructor
Sleeper::Sleeper()
{
}

//Virtual Destructor
Sleeper::~Sleeper()
{
}

//Creates a Singleton Instance of the Class
const Sleeper& Sleeper::Instance()
{
	static const Sleeper SleeperInstance = Sleeper();
	return SleeperInstance;
}

//Returns the Load Factor
double Sleeper::GetLoadFactor() const
{
	return Sleeper::sloadFactor;
}

//Returns the name of the Booking Class
std::string Sleeper::GetName() const
{
	return "Sleeper";
}

//Returns whether the Booking Class is AC or not
bool Sleeper::IsAC() const
{
	return false;
}

//Returns whether the Booking Class is Luxury or not
bool Sleeper::IsLuxury() const
{
	return false;
}

//STATIC UNIT TEST FUNCTION
void Sleeper::UnitTestSleeper()// Test application for Sleeper
{
	std::cout << "STATIC UNIT TEST FUNCTION To unit test class Sleeper" << std::endl << std::endl;
	
	//Check the static constants
	std::cout << "**********************************************************" << std::endl;
	std::cout << "Check the static constants:" << std::endl << std::endl;
	std::cout << "Checking the sloadFactor:" << sloadFactor << std::endl << std::endl;
	if(sloadFactor!=1)
	{
		std::cerr << "Error on Initialisation of sloadFactor" << std::endl;
	}
	
	//Check whether the class is singleton or not
	std::cout << "**********************************************************" << std::endl;
	std::cout << "Check whether the class is singleton or not:" << std::endl <<std::endl;
	std::cout << "Address of Sleeper::Instance called the first time: " << &Sleeper::Instance() << std::endl;
	std::cout << std::endl;
	std::cout << "Address of Sleeper::Instance called the second time: " << &Sleeper::Instance() << std::endl;
	std::cout << std::endl;
	if(&Sleeper::Instance() !=  &Sleeper::Instance())
	{
		std::cerr << "Error: Sleeper is not a singleton class!!!" << std::endl;
	}
	else
	{
		std::cout << "Sleeper is a singleton class" << std::endl;
	}
	
	//Check the IsSitting member Function
	std::cout << "**********************************************************" << std::endl;
	std::cout << "Check the IsSitting member Function:" << std::endl <<std::endl;
	std::cout << "Sleeper::Instance().IsSitting() : " << Sleeper::Instance().IsSitting() << std::endl <<std::endl;
	if(Sleeper::Instance().IsSitting() != false)
	{
		std::cerr << "Error in isSitting member Function" << std::endl;
	}
	
	//Check the GetNumberOfTiers member Function
	std::cout << "**********************************************************" << std::endl;
	std::cout << "Check the GetNumberOfTiers member Function:" << std::endl <<std::endl;
	std::cout << "Sleeper::Instance().GetNumberOfTiers() : " << Sleeper::Instance().GetNumberOfTiers() << std::endl <<std::endl;
	if(Sleeper::Instance().GetNumberOfTiers() != 3)
	{
		std::cerr << "Error in GetNumberOfTiers member Function" << std::endl;
	}
	
	//Check the GetLoadFactor member Function
	std::cout << "**********************************************************" << std::endl;
	std::cout << "Check the GetLoadFactor member Function:" << std::endl <<std::endl;
	std::cout << "Sleeper::Instance().GetLoadFactor() : " << Sleeper::Instance().GetLoadFactor() << std::endl <<std::endl;
	if(Sleeper::Instance().GetLoadFactor() != sloadFactor)
	{
		std::cerr << "Error in GetLoadFactor member Function" << std::endl;
	}
	
	//Check the GetName member Function
	std::cout << "**********************************************************" << std::endl;
	std::cout << "Check the GetName member Function:" << std::endl <<std::endl;
	std::cout << "Sleeper::Instance().GetName() : " << Sleeper::Instance().GetName() << std::endl <<std::endl;
	if(Sleeper::Instance().GetName() != "Sleeper")
	{
		std::cerr << "Error in GetName member Function" << std::endl;
	}
	
	//Check the IsAC member Function
	std::cout << "**********************************************************" << std::endl;
	std::cout << "Check the IsAC member Function:" << std::endl <<std::endl;
	std::cout << "Sleeper::Instance().IsAC() : " << Sleeper::Instance().IsAC() << std::endl <<std::endl;
	if(Sleeper::Instance().IsAC() != false)
	{
		std::cerr << "Error in IsAC member Function" << std::endl;
	}
	
	//Check the IsLuxury member Function
	std::cout << "**********************************************************" << std::endl;
	std::cout << "Check the IsLuxury member Function:" << std::endl <<std::endl;
	std::cout << "Sleeper::Instance().IsLuxury() : " << Sleeper::Instance().IsLuxury() << std::endl <<std::endl;
	if(Sleeper::Instance().IsLuxury() != false)
	{
		std::cerr << "Error in IsLuxury member Function" << std::endl;
	}
	std::cout << "**********************************************************" << std::endl;
}


