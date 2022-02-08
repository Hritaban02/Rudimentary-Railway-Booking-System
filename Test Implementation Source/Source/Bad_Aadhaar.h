#ifndef __BAD_AADHAAR_H__
#define __BAD_AADHAAR_H__

#include "Bad_Passenger.h"

class Bad_Aadhaar : public Bad_Passenger
{
public:
	Bad_Aadhaar();
	~Bad_Aadhaar();
	virtual const char* what() const throw()
	{
		return "Aadhaar Number entered is not valid. Please check the details again.";
	}

};

#endif // __BAD_AADHAAR_H__
