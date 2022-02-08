/* ****************************************
*	Name: Hritaban Ghosh
*	Roll Number: 19CS30053
**************************************** */

#ifndef __RAILWAYS_H__
#define __RAILWAYS_H__

//Imports
#include "Station.h"
#include <string>
#include <vector>

class Railways
{
	friend std::ostream& operator<<(std::ostream&, const Railways&);//The insertion operator is overloaded as a friend function, it prints out the list of railway stations and the distance matrix
	
	public:
		static const std::vector<Station> sStations;//Collection of Stations
	private:
		static const std::vector<std::vector <double>> sDistances;//Distance Matrix to get distance between any two stations

	public:
		static const Railways& IndianRailways();//Singleton instance of the class Railways called IndianRailways

	private:
		Railways();//Constructor
		~Railways();//Destructor

	public:
		double GetDistance(const Station&, const Station&) const;//Returns the distance between two stations provided as input

	public:
		//STATIC UNIT TEST FUNCTION
		static void UnitTestRailways();// Test application for Railways

};

#endif // __RAILWAYS_H__
