/* ****************************************
*	Name: Hritaban Ghosh
*	Roll Number: 19CS30053
**************************************** */

#include "ACFirstClass.h"
#include <string> 
#include <iostream>

//static constant 
//Stores the load factor of the Booking Class
const double ACFirstClass::sloadFactor = 3;

//Constructor
ACFirstClass::ACFirstClass()
{
}

//Virtual Destructor
ACFirstClass::~ACFirstClass()
{
}

//Creates a Singleton Instance of the Class
const ACFirstClass& ACFirstClass::Instance()
{
	static const ACFirstClass ACFirstClassInstance = ACFirstClass();
	return ACFirstClassInstance;
}

//Returns the Load Factor
double ACFirstClass::GetLoadFactor() const
{
	return ACFirstClass::sloadFactor;
}

//Returns the name of the Booking Class
std::string ACFirstClass::GetName() const
{
	return "AC First Class";
}

//Returns whether the Booking Class is AC or not
bool ACFirstClass::IsAC() const
{
	return true;
}

//Returns whether the Booking Class is Luxury or not
bool ACFirstClass::IsLuxury() const
{
	return true;
}

//STATIC UNIT TEST FUNCTION
void ACFirstClass::UnitTestACFirstClass()// Test application for ACFirstClass
{
	std::cout << "STATIC UNIT TEST FUNCTION To unit test class ACFirstClass" << std::endl << std::endl;
	
	//Check the static constants
	std::cout << "**********************************************************" << std::endl;
	std::cout << "Check the static constants:" << std::endl << std::endl;
	std::cout << "Checking the sloadFactor:" << sloadFactor << std::endl << std::endl;
	if(sloadFactor!=3)
	{
		std::cerr << "Error on Initialisation of sloadFactor" << std::endl;
	}
	
	//Check whether the class is singleton or not
	std::cout << "**********************************************************" << std::endl;
	std::cout << "Check whether the class is singleton or not:" << std::endl <<std::endl;
	std::cout << "Address of ACFirstClass::Instance called the first time: " << &ACFirstClass::Instance() << std::endl;
	std::cout << std::endl;
	std::cout << "Address of ACFirstClass::Instance called the second time: " << &ACFirstClass::Instance() << std::endl;
	std::cout << std::endl;
	if(&ACFirstClass::Instance() !=  &ACFirstClass::Instance())
	{
		std::cerr << "Error: ACFirstClass is not a singleton class!!!" << std::endl;
	}
	else
	{
		std::cout << "ACFirstClass is a singleton class" << std::endl;
	}
	
	//Check the IsSitting member Function
	std::cout << "**********************************************************" << std::endl;
	std::cout << "Check the IsSitting member Function:" << std::endl <<std::endl;
	std::cout << "ACFirstClass::Instance().IsSitting() : " << ACFirstClass::Instance().IsSitting() << std::endl <<std::endl;
	if(ACFirstClass::Instance().IsSitting() != false)
	{
		std::cerr << "Error in isSitting member Function" << std::endl;
	}
	
	//Check the GetNumberOfTiers member Function
	std::cout << "**********************************************************" << std::endl;
	std::cout << "Check the GetNumberOfTiers member Function:" << std::endl <<std::endl;
	std::cout << "ACFirstClass::Instance().GetNumberOfTiers() : " << ACFirstClass::Instance().GetNumberOfTiers() << std::endl <<std::endl;
	if(ACFirstClass::Instance().GetNumberOfTiers() != 2)
	{
		std::cerr << "Error in GetNumberOfTiers member Function" << std::endl;
	}
	
	//Check the GetLoadFactor member Function
	std::cout << "**********************************************************" << std::endl;
	std::cout << "Check the GetLoadFactor member Function:" << std::endl <<std::endl;
	std::cout << "ACFirstClass::Instance().GetLoadFactor() : " << ACFirstClass::Instance().GetLoadFactor() << std::endl <<std::endl;
	if(ACFirstClass::Instance().GetLoadFactor() != sloadFactor)
	{
		std::cerr << "Error in GetLoadFactor member Function" << std::endl;
	}
	
	//Check the GetName member Function
	std::cout << "**********************************************************" << std::endl;
	std::cout << "Check the GetName member Function:" << std::endl <<std::endl;
	std::cout << "ACFirstClass::Instance().GetName() : " << ACFirstClass::Instance().GetName() << std::endl <<std::endl;
	if(ACFirstClass::Instance().GetName() != "AC First Class")
	{
		std::cerr << "Error in GetName member Function" << std::endl;
	}
	
	//Check the IsAC member Function
	std::cout << "**********************************************************" << std::endl;
	std::cout << "Check the IsAC member Function:" << std::endl <<std::endl;
	std::cout << "ACFirstClass::Instance().IsAC() : " << ACFirstClass::Instance().IsAC() << std::endl <<std::endl;
	if(ACFirstClass::Instance().IsAC() != true)
	{
		std::cerr << "Error in IsAC member Function" << std::endl;
	}
	
	//Check the IsLuxury member Function
	std::cout << "**********************************************************" << std::endl;
	std::cout << "Check the IsLuxury member Function:" << std::endl <<std::endl;
	std::cout << "ACFirstClass::Instance().IsLuxury() : " << ACFirstClass::Instance().IsLuxury() << std::endl <<std::endl;
	if(ACFirstClass::Instance().IsLuxury() != true)
	{
		std::cerr << "Error in IsLuxury member Function" << std::endl;
	}
	std::cout << "**********************************************************" << std::endl;
}

