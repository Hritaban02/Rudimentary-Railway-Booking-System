#include "Divyaang_Concession.h"
#include "Divyaang.h"

Divyaang_Concession::Divyaang_Concession()
{
}

Divyaang_Concession::~Divyaang_Concession()
{
}

double Divyaang_Concession::GetConcessionFactor(const BookingClass& B, const Passenger& P)
{
	const Divyaang* D=P.GetDisability();
	
	if(D!=0)
	{
		return (*D).GetConcession(B);
	}
	else
	{
		return 0;
	}
}

void Divyaang_Concession::UnitTestDivyaang_Concession()
{
	std::cout << "STATIC UNIT TEST FUNCTION To unit test class Divyaang_Concession" << std::endl << std::endl;
	
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
	std::cout << "Check the GetConcessionFactor() Member Function using Divyaang_Concession::GetConcessionFactor(BookingClass::AC2Tier::Type(),P1) : " << Divyaang_Concession::GetConcessionFactor(BookingClass::AC2Tier::Type(),P1) << std::endl <<std::endl;
	if( Divyaang_Concession::GetConcessionFactor(BookingClass::AC2Tier::Type(),P1) != 0)
	{
		std::cerr << "Error in GetConcessionFactor()  Member Function" << std::endl; 
	}
	std::cout << "Check the GetConcessionFactor() Member Function using Divyaang_Concession::GetConcessionFactor(BookingClass::AC3Tier::Type(),P2) : " << Divyaang_Concession::GetConcessionFactor(BookingClass::AC3Tier::Type(),P2) << std::endl <<std::endl;
	if( Divyaang_Concession::GetConcessionFactor(BookingClass::AC3Tier::Type(),P2) != 0.75)
	{
		std::cerr << "Error in GetConcessionFactor()  Member Function" << std::endl; 
	}
	std::cout << "Check the GetConcessionFactor() Member Function using Divyaang_Concession::GetConcessionFactor(BookingClass::ACFirstClass::Type(),P3) : " << Divyaang_Concession::GetConcessionFactor(BookingClass::ACFirstClass::Type(),P3) << std::endl <<std::endl;
	if( Divyaang_Concession::GetConcessionFactor(BookingClass::ACFirstClass::Type(),P3) != 0.5)
	{
		std::cerr << "Error in GetConcessionFactor()  Member Function" << std::endl; 
	}
	std::cout << "Check the GetConcessionFactor() Member Function using Divyaang_Concession::GetConcessionFactor(BookingClass::Sleeper::Type(),P4) : " << Divyaang_Concession::GetConcessionFactor(BookingClass::Sleeper::Type(),P4) << std::endl <<std::endl;
	if( Divyaang_Concession::GetConcessionFactor(BookingClass::Sleeper::Type(),P4) != 0)
	{
		std::cerr << "Error in GetConcessionFactor()  Member Function" << std::endl; 
	}
	std::cout << "**********************************************************" << std::endl;
}
