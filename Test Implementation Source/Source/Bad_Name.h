#ifndef __BAD_NAME_H__
#define __BAD_NAME_H__

#include "Bad_Passenger.h"

class Bad_Name : public Bad_Passenger
{
public:
	Bad_Name();
	~Bad_Name();
	virtual const char* what() const throw()
	{
		return "Name has inconsistent details. Please check the details again.";
	}

};

#endif // __BAD_NAME_H__
