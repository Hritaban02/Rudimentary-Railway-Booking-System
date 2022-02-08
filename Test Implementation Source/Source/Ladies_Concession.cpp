#include "Ladies_Concession.h"
#include "Concessions.h"

Ladies_Concession::Ladies_Concession() 
{
}

Ladies_Concession::~Ladies_Concession()
{
}

double Ladies_Concession::GetConcessionFactor(const Passenger&)
{
	return 0;
}

void Ladies_Concession::UnitTestLadies_Concession()
{
	std::cout << "STATIC UNIT TEST FUNCTION To unit test class Ladies_Concession" << std::endl << std::endl;
	
	//Check the GetConcessionFactor() Member Function
	std::cout << "**********************************************************" << std::endl;
	Passenger P1 = Passenger::createPassenger("Alexis","","Xavier",21,01,2001,Gender::Female::Type(),"987654321012","");
	std::cout << std::endl;
	std::cout << "P1 "<< std::endl;
	std::cout << P1 << std::endl;
	std::cout << std::endl;
	std::cout << "Check the GetConcessionFactor() Member Function using Ladies_Concession::GetConcessionFactor(P1) : " << Ladies_Concession::GetConcessionFactor(P1) << std::endl <<std::endl;
	std::cout << std::endl;
	if( Ladies_Concession::GetConcessionFactor(P1) != 0)
	{
		std::cerr << "Error in GetConcessionFactor()  Member Function" << std::endl; 
	}
	std::cout << "**********************************************************" << std::endl;
}
