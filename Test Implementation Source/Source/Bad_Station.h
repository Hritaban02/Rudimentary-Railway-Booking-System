#ifndef __BAD_STATION_H__
#define __BAD_STATION_H__

#include "Bad_Railways.h"

class Bad_Station : public Bad_Railways
{
public:
	Bad_Station();
	~Bad_Station();
	virtual const char* what() const throw()
	{
		return "Station is not in Master Data. Please check the details again.";
	}


};

#endif // __BAD_STATION_H__
