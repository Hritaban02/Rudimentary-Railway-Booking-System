/* ****************************************
*	Name: Hritaban Ghosh
*	Roll Number: 19CS30053
**************************************** */

#include "SecondSitting.h"
#include <string>
#include <iostream>

//static constant 
//Stores the load factor of the Booking Class
const double SecondSitting::sloadFactor = 0.5;

//Constructor
SecondSitting::SecondSitting()
{
}

//Virtual Destructor
SecondSitting::~SecondSitting()
{
}

//Creates a Singleton Instance of the Class
const SecondSitting& SecondSitting::Instance()
{
	static const SecondSitting SecondSittingInstance = SecondSitting();
	return SecondSittingInstance;
}

//Returns the Load Factor
double SecondSitting::GetLoadFactor() const
{
	return SecondSitting::sloadFactor;
}

//Returns the name of the Booking Class
std::string SecondSitting::GetName() const
{
	return "Second Sitting";
}

//Returns whether the Booking Class is AC or not
bool SecondSitting::IsAC() const
{
	return false;
}

//Returns whether the Booking Class is Luxury or not
bool SecondSitting::IsLuxury() const
{
	return false;
}

//STATIC UNIT TEST FUNCTION
void SecondSitting::UnitTestSecondSitting()// Test application for SecondSitting
{
	std::cout << "STATIC UNIT TEST FUNCTION To unit test class SecondSitting" << std::endl << std::endl;
	
	//Check the static constants
	std::cout << "**********************************************************" << std::endl;
	std::cout << "Check the static constants:" << std::endl << std::endl;
	std::cout << "Checking the sloadFactor:" << sloadFactor << std::endl << std::endl;
	if(sloadFactor!=0.5)
	{
		std::cerr << "Error on Initialisation of sloadFactor" << std::endl;
	}
	
	//Check whether the class is singleton or not
	std::cout << "**********************************************************" << std::endl;
	std::cout << "Check whether the class is singleton or not:" << std::endl <<std::endl;
	std::cout << "Address of SecondSitting::Instance called the first time: " << &SecondSitting::Instance() << std::endl;
	std::cout << std::endl;
	std::cout << "Address of SecondSitting::Instance called the second time: " << &SecondSitting::Instance() << std::endl;
	std::cout << std::endl;
	if(&SecondSitting::Instance() !=  &SecondSitting::Instance())
	{
		std::cerr << "Error: SecondSitting is not a singleton class!!!" << std::endl;
	}
	else
	{
		std::cout << "SecondSitting is a singleton class" << std::endl;
	}
	
	//Check the IsSitting member Function
	std::cout << "**********************************************************" << std::endl;
	std::cout << "Check the IsSitting member Function:" << std::endl <<std::endl;
	std::cout << "SecondSitting::Instance().IsSitting() : " << SecondSitting::Instance().IsSitting() << std::endl <<std::endl;
	if(SecondSitting::Instance().IsSitting() != true)
	{
		std::cerr << "Error in isSitting member Function" << std::endl;
	}
	
	//Check the GetNumberOfTiers member Function
	std::cout << "**********************************************************" << std::endl;
	std::cout << "Check the GetNumberOfTiers member Function:" << std::endl <<std::endl;
	std::cout << "SecondSitting::Instance().GetNumberOfTiers() : " << SecondSitting::Instance().GetNumberOfTiers() << std::endl <<std::endl;
	if(SecondSitting::Instance().GetNumberOfTiers() != 0)
	{
		std::cerr << "Error in GetNumberOfTiers member Function" << std::endl;
	}
	
	//Check the GetLoadFactor member Function
	std::cout << "**********************************************************" << std::endl;
	std::cout << "Check the GetLoadFactor member Function:" << std::endl <<std::endl;
	std::cout << "SecondSitting::Instance().GetLoadFactor() : " << SecondSitting::Instance().GetLoadFactor() << std::endl <<std::endl;
	if(SecondSitting::Instance().GetLoadFactor() != sloadFactor)
	{
		std::cerr << "Error in GetLoadFactor member Function" << std::endl;
	}
	
	//Check the GetName member Function
	std::cout << "**********************************************************" << std::endl;
	std::cout << "Check the GetName member Function:" << std::endl <<std::endl;
	std::cout << "SecondSitting::Instance().GetName() : " << SecondSitting::Instance().GetName() << std::endl <<std::endl;
	if(SecondSitting::Instance().GetName() != "Second Sitting")
	{
		std::cerr << "Error in GetName member Function" << std::endl;
	}
	
	//Check the IsAC member Function
	std::cout << "**********************************************************" << std::endl;
	std::cout << "Check the IsAC member Function:" << std::endl <<std::endl;
	std::cout << "SecondSitting::Instance().IsAC() : " << SecondSitting::Instance().IsAC() << std::endl <<std::endl;
	if(SecondSitting::Instance().IsAC() != false)
	{
		std::cerr << "Error in IsAC member Function" << std::endl;
	}
	
	//Check the IsLuxury member Function
	std::cout << "**********************************************************" << std::endl;
	std::cout << "Check the IsLuxury member Function:" << std::endl <<std::endl;
	std::cout << "SecondSitting::Instance().IsLuxury() : " << SecondSitting::Instance().IsLuxury() << std::endl <<std::endl;
	if(SecondSitting::Instance().IsLuxury() != false)
	{
		std::cerr << "Error in IsLuxury member Function" << std::endl;
	}
	std::cout << "**********************************************************" << std::endl;
}

