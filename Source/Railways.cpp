/* ****************************************
*	Name: Hritaban Ghosh
*	Roll Number: 19CS30053
**************************************** */

#include "Railways.h"
#include "Station.h"
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

//Collection of Stations
const std::vector<Station> Railways::sStations {Station("Mumbai"), Station("Delhi"), Station("Bangalore"), Station("Kolkata"), Station("Chennai")};
//Distance Matrix to get distance between any two stations
const std::vector<std::vector <double>> Railways::sDistances { {0, 1447, 981, 2014, 1338}, {1447, 0, 2150, 1472, 2180}, {981, 2150, 0, 1871, 350}, {2014, 1472, 1871, 0, 1659}, {1338, 2180, 350, 1659, 0}};

//Constructor
Railways::Railways()
{
}

//Destructor
Railways::~Railways()
{
}

//Singleton instance of the class Railways called IndianRailways
const Railways& Railways::IndianRailways()
{
	static const Railways IndianRailways = Railways();
	return IndianRailways;
}

//Returns the distance between two stations provided as input
double Railways:: GetDistance(const Station& station1, const Station& station2) const
{
	size_t i = 0;
	size_t j = 0;
	
	std::string st1 = station1.GetName();
	for(auto &s: Railways::sStations)
	{
		if(s.GetName() == st1)
		{
			break;
		}
		i++;
	}
	
	std::string st2 = station2.GetName();
	for(auto &s: Railways::sStations)
	{
		if(s.GetName() == st2)
		{
			break;
		}
		j++;
	}
	
	return Railways::sDistances[i][j];
}

//The insertion operator is implemented as a friend function, it prints out the list of railway stations and the distance matrix
std::ostream& operator<<(std::ostream& out, const Railways& railways)
{
	out << "The list of stations reachable via the Indian Railways: " << std::endl;
	out << std::endl;
	for(auto it{Railways::sStations.begin()};it!=Railways::sStations.end();it++)
	{
		out << (*it).GetName() << "  ";
	}
	out << std::endl;
	out << std::endl;
	
	out << "Distance Matrix: D[i][j] gives the distance between stations i and j" << std::endl;
	out << std::endl;
	out << std::setw(15) <<  "Stations : ";
	for(auto it{Railways::sStations.begin()};it!=Railways::sStations.end();it++)
	{
		out << std::setw(15) << (*it).GetName();
	}
	out << std::endl;
	auto j{Railways::sStations.begin()};
	for(auto i{Railways::sDistances.begin()};i!=Railways::sDistances.end();i++,j++)
	{
		out << std::setw(15) <<  (*j).GetName();
		for(auto it{(*i).begin()};it!=(*i).end();it++)
		{
			out << std::setw(15) << *it;
		}
		out << std::endl;
	}
	return out;
}

//STATIC UNIT TEST FUNCTION
//To unit test class Railways
void Railways::UnitTestRailways()// Test application for Railways
{
	std::cout << "STATIC UNIT TEST FUNCTION To unit test class Railways" << std::endl << std::endl;
	
	//Check whether the class is singleton or not
	std::cout << "**********************************************************" << std::endl;
	std::cout << "Check whether the class is singleton or not:" << std::endl <<std::endl;
	std::cout << "Address of IndianRailways called the first time: " << &Railways::IndianRailways() << std::endl;
	std::cout << std::endl;
	std::cout << "Address of IndianRailways called the second time: " << &Railways::IndianRailways() << std::endl;
	std::cout << std::endl;
	if(&Railways::IndianRailways() !=  &Railways::IndianRailways())
	{
		std::cerr << "Error: Railways is not a singleton class!!!" << std::endl;
	}
	else
	{
		std::cout << "Railways is a singleton class" << std::endl;
	}
	
	//Check the list of Stations
	std::cout << "**********************************************************" << std::endl;
	std::cout << "Check the list of Stations:" << std::endl <<std::endl;
	std::cout << "The list of stations reachable via the Indian Railways: " << std::endl;
	std::cout << std::endl;
	for(auto it{Railways::sStations.begin()};it!=Railways::sStations.end();it++)
	{
		std::cout  << (*it).GetName() << "  ";
	}
	std::cout << std::endl;
	
	//Check the Distance Matrix
	std::cout << "**********************************************************" << std::endl;
	std::cout << "Check the Distance Matrix:" << std::endl <<std::endl;
	std::cout << "Distance Matrix: D[i][j] gives the distance between stations i and j" << std::endl;
	std::cout << std::endl;
	std::cout << std::setw(15) <<  "Stations : ";
	for(auto it{Railways::sStations.begin()};it!=Railways::sStations.end();it++)
	{
		std::cout  << std::setw(15) << (*it).GetName();
	}
	std::cout  << std::endl;
	auto j{Railways::sStations.begin()};
	for(auto i{Railways::sDistances.begin()};i!=Railways::sDistances.end();i++,j++)
	{
		std::cout  << std::setw(15) <<  (*j).GetName();
		for(auto it{(*i).begin()};it!=(*i).end();it++)
		{
			std::cout  << std::setw(15) << *it;
		}
		std::cout  << std::endl;
	}
	std::cout << std::endl;
	
	//To test the GetDistance() member Function
	std::cout << "**********************************************************" << std::endl;
	std::cout << "To test the GetDistance() member Function:" << std::endl << std::endl;
	std::cout << "Distance between Mumbai and Kolkata as obtained from Railways::IndianRailways().GetDistance(Station(\"Mumbai\"), Station(\"Kolkata\")) is " << Railways::IndianRailways().GetDistance(Station("Mumbai"), Station("Kolkata")) << std::endl;
	if(Railways::IndianRailways().GetDistance(Station("Mumbai"), Station("Kolkata")) != 2014)
	{
		std::cerr << "GetDistance() Member Function Error on Station(\"Mumbai\"),Station(\"Kolkata\")" << std::endl; 
	}
	
	
	//Check the insertion operator
	std::cout << "**********************************************************" << std::endl;
	std::cout << "Check the insertion operator:" << std::endl <<std::endl;
	std::cout << Railways::IndianRailways() << std::endl;
	std::cout << "**********************************************************" << std::endl;
}
