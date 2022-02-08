#ifndef __LADIES_CONCESSION_H__
#define __LADIES_CONCESSION_H__

#include "Concessions.h"
#include "Passenger.h"

class Ladies_Concession : public Concessions
{

	Ladies_Concession();
public:
	~Ladies_Concession();
	static double GetConcessionFactor(const Passenger&);
	
public:
	//STATIC UNIT TEST FUNCTION
	static void UnitTestLadies_Concession();// Test application for Ladies_Concession

};

#endif // __LADIES_CONCESSION_H__
