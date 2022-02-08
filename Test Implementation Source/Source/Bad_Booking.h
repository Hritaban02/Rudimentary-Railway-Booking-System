#ifndef __BAD_BOOKING_H__
#define __BAD_BOOKING_H__

#include <iostream>

class Bad_Booking : public std::exception
{
public:
	Bad_Booking();
	~Bad_Booking();
	virtual const char* what() const throw()
	{
		return "Booking has invalid or inconsistent details. Please check the details again.";
	}

};

#endif // __BAD_BOOKING_H__
