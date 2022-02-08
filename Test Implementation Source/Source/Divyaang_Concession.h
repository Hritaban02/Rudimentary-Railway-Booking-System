#ifndef __DIVYAANG_CONCESSION_H__
#define __DIVYAANG_CONCESSION_H__

#include "Concessions.h"
#include "Passenger.h"
#include "BookingClass.h"

class Divyaang_Concession : public Concessions
{

	Divyaang_Concession();
public:
	~Divyaang_Concession();
	static double GetConcessionFactor(const BookingClass&, const Passenger&);
	
public:
	//STATIC UNIT TEST FUNCTION
	static void UnitTestDivyaang_Concession();// Test application for Divyaang_Concession

};

#endif // __DIVYAANG_CONCESSION_H__
