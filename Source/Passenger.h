/* ****************************************
*	Name: Hritaban Ghosh
*	Roll Number: 19CS30053
**************************************** */

#ifndef __PASSSENGER_H__
#define __PASSSENGER_H__

#include <string>
#include "Date.h"


class Passenger
{
	private:
		std::string name;
		int aadhaarNumber;
		Date dateOfBirth;
		std::string gender;
		int mobileNumber;
		
	public:
		Passenger(std::string&, int, Date&, std::string&, int mobileNumber_val=-1);
		Passenger(const Passenger&);
		virtual ~Passenger();

};

#endif // __PASSSENGER_H__
