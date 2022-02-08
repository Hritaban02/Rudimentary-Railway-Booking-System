/* ****************************************
*	Name: Hritaban Ghosh
*	Roll Number: 19CS30053
**************************************** */

#include "ACChairCar.h"
#include <string>
#include <iostream>

//static constant 
//Stores the load factor of the Booking Class
const double ACChairCar::sloadFactor = 1.25;

//Constructor
ACChairCar::ACChairCar()
{
}

//Virtual Destructor
ACChairCar::~ACChairCar()
{
}

//Creates a Singleton Instance of the Class
const ACChairCar& ACChairCar::Instance()
{
	static const ACChairCar ACChairCarInstance = ACChairCar();
	return ACChairCarInstance;
}

//Returns the Load Factor
double ACChairCar::GetLoadFactor() const
{
	return ACChairCar::sloadFactor;
}

//Returns the name of the Booking Class
std::string ACChairCar::GetName() const
{
	return "AC Chair Car";
}

//Returns whether the Booking Class is AC or not
bool ACChairCar::IsAC() const
{
	return true;
}

//Returns whether the Booking Class is Luxury or not
bool ACChairCar::IsLuxury() const
{
	return false;
}

//STATIC UNIT TEST FUNCTION
void ACChairCar::UnitTestACChairCar()// Test application for ACChairCar
{
	std::cout << "STATIC UNIT TEST FUNCTION To unit test class ACChairCar" << std::endl << std::endl;
	
	//Check the static constants
	std::cout << "**********************************************************" << std::endl;
	std::cout << "Check the static constants:" << std::endl << std::endl;
	std::cout << "Checking the sloadFactor:" << sloadFactor << std::endl << std::endl;
	if(sloadFactor!=1.25)
	{
		std::cerr << "Error on Initialisation of sloadFactor" << std::endl;
	}
	
	//Check whether the class is singleton or not
	std::cout << "**********************************************************" << std::endl;
	std::cout << "Check whether the class is singleton or not:" << std::endl <<std::endl;
	std::cout << "Address of ACChairCar::Instance called the first time: " << &ACChairCar::Instance() << std::endl;
	std::cout << std::endl;
	std::cout << "Address of ACChairCar::Instance called the second time: " << &ACChairCar::Instance() << std::endl;
	std::cout << std::endl;
	if(&ACChairCar::Instance() !=  &ACChairCar::Instance())
	{
		std::cerr << "Error: ACChairCar is not a singleton class!!!" << std::endl;
	}
	else
	{
		std::cout << "ACChairCar is a singleton class" << std::endl;
	}
	
	//Check the IsSitting member Function
	std::cout << "**********************************************************" << std::endl;
	std::cout << "Check the IsSitting member Function:" << std::endl <<std::endl;
	std::cout << "ACChairCar::Instance().IsSitting() : " << ACChairCar::Instance().IsSitting() << std::endl <<std::endl;
	if(ACChairCar::Instance().IsSitting() != true)
	{
		std::cerr << "Error in isSitting member Function" << std::endl;
	}
	
	//Check the GetNumberOfTiers member Function
	std::cout << "**********************************************************" << std::endl;
	std::cout << "Check the GetNumberOfTiers member Function:" << std::endl <<std::endl;
	std::cout << "ACChairCar::Instance().GetNumberOfTiers() : " << ACChairCar::Instance().GetNumberOfTiers() << std::endl <<std::endl;
	if(ACChairCar::Instance().GetNumberOfTiers() != 0)
	{
		std::cerr << "Error in GetNumberOfTiers member Function" << std::endl;
	}
	
	//Check the GetLoadFactor member Function
	std::cout << "**********************************************************" << std::endl;
	std::cout << "Check the GetLoadFactor member Function:" << std::endl <<std::endl;
	std::cout << "ACChairCar::Instance().GetLoadFactor() : " << ACChairCar::Instance().GetLoadFactor() << std::endl <<std::endl;
	if(ACChairCar::Instance().GetLoadFactor() != sloadFactor)
	{
		std::cerr << "Error in GetLoadFactor member Function" << std::endl;
	}
	
	//Check the GetName member Function
	std::cout << "**********************************************************" << std::endl;
	std::cout << "Check the GetName member Function:" << std::endl <<std::endl;
	std::cout << "ACChairCar::Instance().GetName() : " << ACChairCar::Instance().GetName() << std::endl <<std::endl;
	if(ACChairCar::Instance().GetName() != "AC Chair Car")
	{
		std::cerr << "Error in GetName member Function" << std::endl;
	}
	
	//Check the IsAC member Function
	std::cout << "**********************************************************" << std::endl;
	std::cout << "Check the IsAC member Function:" << std::endl <<std::endl;
	std::cout << "ACChairCar::Instance().IsAC() : " << ACChairCar::Instance().IsAC() << std::endl <<std::endl;
	if(ACChairCar::Instance().IsAC() != true)
	{
		std::cerr << "Error in IsAC member Function" << std::endl;
	}
	
	//Check the IsLuxury member Function
	std::cout << "**********************************************************" << std::endl;
	std::cout << "Check the IsLuxury member Function:" << std::endl <<std::endl;
	std::cout << "ACChairCar::Instance().IsLuxury() : " << ACChairCar::Instance().IsLuxury() << std::endl <<std::endl;
	if(ACChairCar::Instance().IsLuxury() != false)
	{
		std::cerr << "Error in IsLuxury member Function" << std::endl;
	}
	std::cout << "**********************************************************" << std::endl;
}

