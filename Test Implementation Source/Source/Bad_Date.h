#ifndef __BAD_DATE_H__
#define __BAD_DATE_H__

#include <iostream>

class Bad_Date : public std::exception
{
public:
	Bad_Date();
	~Bad_Date();
	virtual const char* what() const throw()
	{
		return "Date entered is invalid or inconsistent with other data. Please check the details again.";
	}

};

#endif // __BAD_DATE_H__
