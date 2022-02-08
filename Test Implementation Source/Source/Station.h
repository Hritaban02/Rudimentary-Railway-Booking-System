/* ****************************************
*	Name: Hritaban Ghosh
*	Roll Number: 19CS30053
**************************************** */

#ifndef __STATION_H__
#define __STATION_H__

#include <string>

class Station
{
	friend std::ostream& operator<<(std::ostream&, const Station&);//The insertion operator is overloaded as a friend function, it prints out the current station name
	
	private:
		std::string name_;//Name of the Station
		Station(std::string);//Constructor
		
public:
		static Station createStation(std::string);
		~Station();//Destructor
		std::string GetName() const;//Returns the name of the Station
		double GetDistance(const Station&) const;//Returns the distance between the current station and the station entered as input
		bool operator==(const Station&) const;//The equality operator is overloaded as a member function-Returns true if the Station names are the same else false
		bool operator!=(const Station&) const;//The inequality operator is overloaded as a member function-Returns true if the Station names are different else false

	public:
		//STATIC UNIT TEST FUNCTION
		static void UnitTestStation();// Test application for Station
};

#endif // __STATION_H__
