/* ****************************************
*	Name: Hritaban Ghosh
*	Roll Number: 19CS30053
**************************************** */

//Imports
#include "Station.h"
#include "Railways.h"
#include "Bad_Station.h"
#include <vector>
#include <algorithm>
#include <iostream>

//Constructor
Station::Station(std::string name_val): name_{name_val}
{
}

Station Station::createStation(std::string name_val)
{
	if(name_val=="")
	{
		throw Bad_Station();
	}
	
	return Station(name_val);
}

//Destructor
Station::~Station()
{
}

//Returns the name of the Station
std::string Station:: GetName() const
{
	return (*this).name_;
}

//Returns the distance between the current station and the station entered as input
double Station:: GetDistance(const Station& other) const
{
	return Railways::IndianRailways().GetDistance(*this, other);
}

//The insertion operator is overloaded as a friend function, it prints out the current station name
std::ostream& operator<<(std::ostream& out, const Station& station)
{
	
	out << station.GetName() << std::endl;
	
	return out;
}

//The equality operator is overloaded as a member function-Returns true if the Station names are the same else false
bool Station::operator==(const Station& other) const
{
	return (*this).GetName()==other.GetName();
}

//The inequality operator is overloaded as a member function-Returns true if the Station names are different else false
bool Station::operator!=(const Station& other) const

{
	return (*this).GetName()!=other.GetName();
}

//STATIC UNIT TEST FUNCTION
void Station::UnitTestStation()// Test application for Station
{
	std::cout << "STATIC UNIT TEST FUNCTION Test application for Station " << std::endl << std::endl;
	//To unit test class Station
	
	
	//To test the construction of objects
	Station s1 = createStation("Mumbai");
	if(s1.name_ != "Mumbai")
	{
		std::cerr << "Station Construction Error on Station(\"Mumbai\")" << std::endl; 
	}
	Station s2 = createStation("Kolkata");
	if(s2.name_ != "Kolkata")
	{
		std::cerr << "Station Construction Error on Station(\"Kolkata\")" << std::endl; 
	}
	
	std::cout << "**********************************************************" << std::endl;
	try
	{
		Station S = createStation("");
	}
	catch (Bad_Station& B)
	{
		std::cout << "Exception caught successfully upon trying to create an invalid station" << std::endl << std::endl;
		std::cout << "Exception message: " << B.what() << std::endl << std::endl;
	}
	
	//To test the GetName() member Function
	std::cout << "**********************************************************" << std::endl;
	std::cout << "To test the GetName() member Function:" << std::endl << std::endl;
	std::cout << "s1 Object name_: " << s1.GetName() << std::endl;
	if(s1.GetName() != "Mumbai")
	{
		std::cerr << "Station GetName() Member Function Error on Station(\"Mumbai\")" << std::endl; 
	}
	std::cout << "s2 Object name_: " << s2.GetName() << std::endl;
	if(s2.GetName() != "Kolkata")
	{
		std::cerr << "Station GetName() Member Function Error on Station(\"Kolkata\")" << std::endl; 
	}
	
	//To test the GetDistance() member Function
	std::cout << "**********************************************************" << std::endl;
	std::cout << "To test the GetDistance() member Function:" << std::endl << std::endl;
	std::cout << "Distance between Mumbai and Kolkata as obtained from s1.GetDistance(s2) is " << s1.GetDistance(s2) << std::endl;
	if(s1.GetDistance(s2) != 2014)
	{
		std::cerr << "Station GetDistance() Member Function Error on Station(\"Mumbai\")" << std::endl; 
	}
	std::cout << "Distance between Mumbai and Kolkata as obtained from s2.GetDistance(s1) is " << s2.GetDistance(s1) << std::endl;
	if(s2.GetDistance(s1) != 2014)
	{
		std::cerr << "Station GetDistance() Member Function Error on Station(\"Kolkata\")" << std::endl; 
	}
	
	//Check the equality operator
	std::cout << "**********************************************************" << std::endl;
	std::cout << "Check the equality operator:" << std::endl << std::endl;
	std::cout << "s1==s1 where s1 is Staion(\"Mumbai\"): " << (s1==s1) << std::endl;
	std::cout << "s1==s2 where s1 is Staion(\"Mumbai\") and s2 is Staion(\"Kolkata\"): " << (s1==s2) << std::endl;
	
	//Check the inequality operator
	std::cout << "**********************************************************" << std::endl;
	std::cout << "Check the inequality operator:" << std::endl << std::endl;
	std::cout << "s1!=s1 where s1 is Staion(\"Mumbai\"): " << (s1!=s1) << std::endl;
	std::cout << "s1!=s2 where s1 is Staion(\"Mumbai\") and s2 is Staion(\"Kolkata\"): " << (s1!=s2) << std::endl;
	
	//To test the insertion operator
	std::cout << "**********************************************************" << std::endl;
	std::cout << "To test the insertion operator:" << std::endl << std::endl;
	std::cout << "s1 Object: " << s1 << std::endl;
	std::cout << "s2 Object: " << s2 << std::endl;
	std::cout << "**********************************************************" << std::endl;
}
