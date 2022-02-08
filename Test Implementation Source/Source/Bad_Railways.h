#ifndef __BAD_RAIWAYS_H__
#define __BAD_RAIWAYS_H__

#include <iostream>

class Bad_Railways : public std::exception
{
public:
	Bad_Railways();
	~Bad_Railways();
	virtual const char* what() const throw()
	{
		return "Railways has invalid master data. Please check the details again.";
	}

};

#endif // __BAD_RAIWAYS_H__
