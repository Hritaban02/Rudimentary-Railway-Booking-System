#include "Concessions.h"

Concessions::Concessions()
{
}

Concessions::~Concessions()
{
}

double Concessions::GetConcessionFactor()
{
	return 0;
}

//STATIC UNIT TEST FUNCTION
void Concessions::UnitTestConcessions()
{
	std::cout << "STATIC UNIT TEST FUNCTION To unit test class Concessions" << std::endl << std::endl;
	
	//Check the GetConcessionFactor() Member Function
	std::cout << "**********************************************************" << std::endl;
	std::cout << "Check the GetConcessionFactor() Member Function using Concessions::GetConcessionFactor() : " << Concessions::GetConcessionFactor() << std::endl <<std::endl;
	std::cout << std::endl;
	if( Concessions::GetConcessionFactor() != 0)
	{
		std::cerr << "Error in GetConcessionFactor()  Member Function" << std::endl; 
	}
	std::cout << "**********************************************************" << std::endl;
}
