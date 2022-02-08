#ifndef __BAD_MOBILE_H__
#define __BAD_MOBILE_H__

#include "Bad_Passenger.h"

class Bad_Mobile : public Bad_Passenger
{
public:
	Bad_Mobile();
	~Bad_Mobile();
	virtual const char* what() const throw()
	{
		return "Mobile Number entered is not valid. Please check the details again.";
	}

};

#endif // __BAD_MOBILE_H__
