#ifndef __CONCESSIONS_H__
#define __CONCESSIONS_H__

#include <string>
#include <iostream>

class Concessions
{

protected:
	Concessions();
public:
	~Concessions();
	static double GetConcessionFactor();

public:
	//STATIC UNIT TEST FUNCTION
	static void UnitTestConcessions();// Test application for Concessions

};

#endif // __CONCESSIONS_H__
