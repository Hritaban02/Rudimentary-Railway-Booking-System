#ifndef __SENIORCITIZEN_CONCESSION_H__
#define __SENIORCITIZEN_CONCESSION_H__

#include "Concessions.h"
#include "Passenger.h"

class SeniorCitizen_Concession : public Concessions
{

	SeniorCitizen_Concession();
public:
	~SeniorCitizen_Concession();
	static double GetConcessionFactor(const Passenger&);
	
public:
	//STATIC UNIT TEST FUNCTION
	static void UnitTestSeniorCitizen_Concession();// Test application for SeniorCitizen_Concession

};

#endif // __SENIORCITIZEN_CONCESSION_H__
