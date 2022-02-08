#ifndef __BAD_PASSENGER_H__
#define __BAD_PASSENGER_H__

#include <iostream>

class Bad_Passenger : public std::exception
{
public:
	Bad_Passenger();
	~Bad_Passenger();
	virtual const char* what() const throw()
	{
		return "Passenger has invalid or inconsistent details. Please check the details again.";
	}

};

#endif // __BAD_PASSENGER_H__
