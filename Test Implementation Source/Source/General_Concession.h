#ifndef __GENERAL_CONCESSION_H__
#define __GENERAL_CONCESSION_H__

#include "Concessions.h"

class General_Concession : public Concessions
{

	General_Concession();
public:
	~General_Concession();
	static double GetConcessionFactor(); //Overload the base class function
	
public:
	//STATIC UNIT TEST FUNCTION
	static void UnitTestGeneral_Concession();// Test application for General_Concession

};

#endif // __GENERAL_CONCESSION_H__
