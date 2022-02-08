#include "SeniorCitizen_Concession.h"
#include "Concessions.h"
#include "Gender.h"

SeniorCitizen_Concession::SeniorCitizen_Concession()
{
}

SeniorCitizen_Concession::~SeniorCitizen_Concession()
{
}

double SeniorCitizen_Concession::GetConcessionFactor(const Passenger& P)
{
	if(Gender::IsMale(P.GetGender()))
	{
		if(P.GetAge()>60)
		{
			return 0.40;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		if(P.GetAge()>58)
		{
			return 0.50;
		}
		else
		{
			return 0;
		}
	}
}

void SeniorCitizen_Concession::UnitTestSeniorCitizen_Concession()
{
	std::cout << "STATIC UNIT TEST FUNCTION To unit test class SeniorCitizen_Concession" << std::endl << std::endl;
	
	//Check the GetConcessionFactor() Member Function
	std::cout << "**********************************************************" << std::endl;
	Passenger P1 = Passenger::createPassenger("Alexis","","Xavier",21,01,2001,Gender::Female::Type(),"987654321012","");
	Passenger P2 = Passenger::createPassenger("Carlos","","Xavier",21,01,1945,Gender::Male::Type(),"987654321012","",Divyaang::Blind::Type(),"124" );
	Passenger P3 = Passenger::createPassenger("Petricia","","Xavier",21,01,1940,Gender::Female::Type(),"987654321012","",Divyaang::Blind::Type(),"125" );
	Passenger P4 = Passenger::createPassenger("Michael","","Xavier",21,01,2015,Gender::Male::Type(),"987654321012","" );
	std::cout << std::endl;
	std::cout << "P1 "<< std::endl;
	std::cout << P1 << std::endl;
	std::cout << std::endl;
	std::cout << "########################" << std::endl;
	std::cout << std::endl;
	std::cout << "P2 "<< std::endl;
	std::cout << P2 << std::endl;
	std::cout << std::endl;
	std::cout << "########################" << std::endl;
	std::cout << std::endl;
	std::cout << "P3 "<< std::endl;
	std::cout << P3 << std::endl;
	std::cout << std::endl;
	std::cout << "########################" << std::endl;
	std::cout << std::endl;
	std::cout << "P4 "<< std::endl;
	std::cout << P4 << std::endl;
	std::cout << std::endl;
	std::cout << "########################" << std::endl;
	std::cout << "Check the GetConcessionFactor() Member Function using SeniorCitizen_Concession::GetConcessionFactor(P1) : " << SeniorCitizen_Concession::GetConcessionFactor(P1) << std::endl <<std::endl;
	if( SeniorCitizen_Concession::GetConcessionFactor(P1) != 0)
	{
		std::cerr << "Error in GetConcessionFactor()  Member Function" << std::endl; 
	}
	std::cout << "Check the GetConcessionFactor() Member Function using SeniorCitizen_Concession::GetConcessionFactor(P2) : " << SeniorCitizen_Concession::GetConcessionFactor(P2) << std::endl <<std::endl;
	if( SeniorCitizen_Concession::GetConcessionFactor(P2) != 0.4)
	{
		std::cerr << "Error in GetConcessionFactor()  Member Function" << std::endl; 
	}
	std::cout << "Check the GetConcessionFactor() Member Function using SeniorCitizen_Concession::GetConcessionFactor(P3) : " << SeniorCitizen_Concession::GetConcessionFactor(P3) << std::endl <<std::endl;
	if( SeniorCitizen_Concession::GetConcessionFactor(P3) != 0.5)
	{
		std::cerr << "Error in GetConcessionFactor()  Member Function" << std::endl; 
	}
	std::cout << "Check the GetConcessionFactor() Member Function using SeniorCitizen_Concession::GetConcessionFactor(P4) : " << SeniorCitizen_Concession::GetConcessionFactor(P4) << std::endl <<std::endl;
	if( SeniorCitizen_Concession::GetConcessionFactor(P4) != 0)
	{
		std::cerr << "Error in GetConcessionFactor()  Member Function" << std::endl; 
	}
	std::cout << "**********************************************************" << std::endl;
}
