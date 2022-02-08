#include "General_Concession.h"
#include "Concessions.h"

General_Concession::General_Concession()
{
}

General_Concession::~General_Concession()
{
}

double General_Concession::GetConcessionFactor()
{
	return 0;
}

void General_Concession::UnitTestGeneral_Concession()
{
	std::cout << "STATIC UNIT TEST FUNCTION To unit test class General_Concession" << std::endl << std::endl;
	
	//Check the GetConcessionFactor() Member Function
	std::cout << "**********************************************************" << std::endl;
	std::cout << "Check the GetConcessionFactor() Member Function using General_Concession::GetConcessionFactor() : " << General_Concession::GetConcessionFactor() << std::endl <<std::endl;
	std::cout << std::endl;
	if( General_Concession::GetConcessionFactor() != 0)
	{
		std::cerr << "Error in GetConcessionFactor()  Member Function" << std::endl; 
	}
	std::cout << "**********************************************************" << std::endl;
}

