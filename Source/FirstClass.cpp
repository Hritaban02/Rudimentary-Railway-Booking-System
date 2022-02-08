/* ****************************************
*	Name: Hritaban Ghosh
*	Roll Number: 19CS30053
**************************************** */

#include "FirstClass.h"
#include <string>
#include <iostream>

//static constant 
//Stores the load factor of the Booking Class
const double FirstClass::sloadFactor = 2;

//Constructor
FirstClass::FirstClass()
{
}

//Virtual Destructor
FirstClass::~FirstClass()
{
}

//Creates a Singleton Instance of the Class
const FirstClass& FirstClass::Instance()
{
	static const FirstClass FirstClassInstance = FirstClass();
	return FirstClassInstance;
}

//Returns the Load Factor
double FirstClass::GetLoadFactor() const
{
	return FirstClass::sloadFactor;
}

//Returns the name of the Booking Class
std::string FirstClass::GetName() const
{
	return "First Class";
}

//Returns whether the Booking Class is AC or not
bool FirstClass::IsAC() const
{
	return false;
}

//Returns whether the Booking Class is Luxury or not
bool FirstClass::IsLuxury() const
{
	return false;
}

//STATIC UNIT TEST FUNCTION
void FirstClass::UnitTestFirstClass()// Test application for FirstClass
{
	std::cout << "STATIC UNIT TEST FUNCTION To unit test class FirstClass" << std::endl << std::endl;
	
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
	std::cout << "Address of FirstClass::Instance called the first time: " << &FirstClass::Instance() << std::endl;
	std::cout << std::endl;
	std::cout << "Address of FirstClass::Instance called the second time: " << &FirstClass::Instance() << std::endl;
	std::cout << std::endl;
	if(&FirstClass::Instance() !=  &FirstClass::Instance())
	{
		std::cerr << "Error: FirstClass is not a singleton class!!!" << std::endl;
	}
	else
	{
		std::cout << "FirstClass is a singleton class" << std::endl;
	}
	
	//Check the IsSitting member Function
	std::cout << "**********************************************************" << std::endl;
	std::cout << "Check the IsSitting member Function:" << std::endl <<std::endl;
	std::cout << "FirstClass::Instance().IsSitting() : " << FirstClass::Instance().IsSitting() << std::endl <<std::endl;
	if(FirstClass::Instance().IsSitting() != false)
	{
		std::cerr << "Error in isSitting member Function" << std::endl;
	}
	
	//Check the GetNumberOfTiers member Function
	std::cout << "**********************************************************" << std::endl;
	std::cout << "Check the GetNumberOfTiers member Function:" << std::endl <<std::endl;
	std::cout << "FirstClass::Instance().GetNumberOfTiers() : " << FirstClass::Instance().GetNumberOfTiers() << std::endl <<std::endl;
	if(FirstClass::Instance().GetNumberOfTiers() != 2)
	{
		std::cerr << "Error in GetNumberOfTiers member Function" << std::endl;
	}
	
	//Check the GetLoadFactor member Function
	std::cout << "**********************************************************" << std::endl;
	std::cout << "Check the GetLoadFactor member Function:" << std::endl <<std::endl;
	std::cout << "FirstClass::Instance().GetLoadFactor() : " << FirstClass::Instance().GetLoadFactor() << std::endl <<std::endl;
	if(FirstClass::Instance().GetLoadFactor() != sloadFactor)
	{
		std::cerr << "Error in GetLoadFactor member Function" << std::endl;
	}
	
	//Check the GetName member Function
	std::cout << "**********************************************************" << std::endl;
	std::cout << "Check the GetName member Function:" << std::endl <<std::endl;
	std::cout << "FirstClass::Instance().GetName() : " << FirstClass::Instance().GetName() << std::endl <<std::endl;
	if(FirstClass::Instance().GetName() != "First Class")
	{
		std::cerr << "Error in GetName member Function" << std::endl;
	}
	
	//Check the IsAC member Function
	std::cout << "**********************************************************" << std::endl;
	std::cout << "Check the IsAC member Function:" << std::endl <<std::endl;
	std::cout << "FirstClass::Instance().IsAC() : " << FirstClass::Instance().IsAC() << std::endl <<std::endl;
	if(FirstClass::Instance().IsAC() != false)
	{
		std::cerr << "Error in IsAC member Function" << std::endl;
	}
	
	//Check the IsLuxury member Function
	std::cout << "**********************************************************" << std::endl;
	std::cout << "Check the IsLuxury member Function:" << std::endl <<std::endl;
	std::cout << "FirstClass::Instance().IsLuxury() : " << FirstClass::Instance().IsLuxury() << std::endl <<std::endl;
	if(FirstClass::Instance().IsLuxury() != false)
	{
		std::cerr << "Error in IsLuxury member Function" << std::endl;
	}
	std::cout << "**********************************************************" << std::endl;
}

