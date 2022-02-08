#include "BookingCategory.h"
#include "Gender.h"
#include "Divyaang.h"

// Names defined as static constants
template<>
const std::string BookingCategory::GeneralCategory::sName = "General";
template<>
const std::string BookingCategory::LadiesCategory::sName = "Ladies";
template<>
const std::string BookingCategory::SeniorCitizenCategory::sName = "Senior Citizen";
template<>
const std::string BookingCategory::DivyaangCategory::sName = "Divyaang";
template<>
const std::string BookingCategory::TatkalCategory::sName = "Tatkal";
template<>
const std::string BookingCategory::PremiumTatkalCategory::sName = "Premium Tatkal";

// Eligibility Policy
template<>
bool BookingCategory::GeneralCategory::isEligible(const Passenger& P)
{
	return true;
}
template<>
bool BookingCategory::LadiesCategory::isEligible(const Passenger& P)
{
	if(Gender::IsMale(P.GetGender()) && P.GetAge() > 12)
	{
		return false;
	}
	else
	{
		return true;
	}
}
template<>
bool BookingCategory::SeniorCitizenCategory::isEligible(const Passenger& P)
{
	if(Gender::IsMale(P.GetGender()))
	{
		if(P.GetAge()>60)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		if(P.GetAge()>58)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}
template<>
bool BookingCategory::DivyaangCategory::isEligible(const Passenger& P)
{
	if((P.GetDisability())!=0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
template<>
bool BookingCategory::TatkalCategory::isEligible(const Passenger& P)
{
	return true;
}
template<>
bool BookingCategory::PremiumTatkalCategory::isEligible(const Passenger& P)
{
	return true;
}

BookingCategory::BookingCategory(const std::string& name_val) : name_{name_val}
{
}

BookingCategory::~BookingCategory()
{
}

const std::string& BookingCategory::GetName() const
{
	return name_;
}

template<typename T>
bool BookingCategoryTypes<T>::isEligiblefor(const Passenger& P) const
{
	return BookingCategoryTypes<T>::isEligible(P);
}

template<>
void BookingCategory::GeneralCategory::UnitTestBookingCategory()
{
	std::cout << "STATIC UNIT TEST FUNCTION To unit test class BookingCategoryTypes::GeneralCategory" << std::endl << std::endl;


	//Check whether the class is singleton or not
	std::cout << "**********************************************************" << std::endl;
	std::cout << "Check whether the class is singleton or not:" << std::endl <<std::endl;
	std::cout << "Address of BookingCategoryTypes::GeneralCategory called the first time: " << &BookingCategoryTypes::GeneralCategory::Type() << std::endl;
	std::cout << std::endl;
	std::cout << "Address of BookingCategoryTypes::GeneralCategory called the second time: " << &BookingCategoryTypes::GeneralCategory::Type() << std::endl;
	std::cout << std::endl;
	if(&BookingCategoryTypes::GeneralCategory::Type() !=  &BookingCategoryTypes::GeneralCategory::Type())
	{
		std::cerr << "Error: BookingCategoryTypes::GeneralCategory is not a singleton class!!!" << std::endl;
	}
	else
	{
		std::cout << "BookingCategoryTypes::GeneralCategory is a singleton class" << std::endl;
	}

	//Check the static data
	std::cout << "**********************************************************" << std::endl;
	std::cout << "Check the static data stored : " << std::endl <<std::endl;
	std::cout << std::endl;
	std::cout  << "sName : " << BookingCategoryTypes::GeneralCategory::sName <<std::endl;
	
	//Check the isEligible member function
	std::cout << "**********************************************************" << std::endl;
	std::cout << "Check the isEligible member function:" << std::endl << std::endl;
	Passenger P1 = Passenger::createPassenger("Mike","","Xavier",21,01,2001,Gender::Male::Type(),"987654321012","",Divyaang::Blind::Type(),"123" );
	Passenger P2 = Passenger::createPassenger("Alexis","","Xavier",21,01,2001,Gender::Female::Type(),"987654321012","");
	Passenger P3 = Passenger::createPassenger("Carlos","","Xavier",21,01,1945,Gender::Male::Type(),"987654321012","",Divyaang::Blind::Type(),"124" );
	Passenger P4 = Passenger::createPassenger("Petricia","","Xavier",21,01,1940,Gender::Female::Type(),"987654321012","",Divyaang::Blind::Type(),"125" );
	Passenger P5 = Passenger::createPassenger("Michael","","Xavier",21,01,2015,Gender::Male::Type(),"987654321012","" );
	std::cout << "Passengers used to check the eligibility function: " << std::endl << std::endl;
	
	std::cout << "P1" << std::endl << P1 << std::endl;
	std::cout << "########################" << std::endl;
	std::cout << "P2" << std::endl << P2 << std::endl;
	std::cout << "########################" << std::endl;
	std::cout << "P3" << std::endl << P3 << std::endl;
	std::cout << "########################" << std::endl;
	std::cout << "P4" << std::endl << P4 << std::endl;
	std::cout << "########################" << std::endl;
	std::cout << "P5" << std::endl << P5 << std::endl;
	std::cout << "########################" << std::endl;
	std::cout << "BookingCategoryTypes::GeneralCategory::Type().isEligible(P1) where P1 is a Passenger: " << BookingCategoryTypes::GeneralCategory::Type().isEligible(P1)<< std::endl;
	if(BookingCategoryTypes::GeneralCategory::Type().isEligible(P1)!=true)
	{
		std::cerr << "Error in Function isEligible() on P1" << std::endl;
	}
	std::cout << std::endl;
	std::cout << "BookingCategoryTypes::GeneralCategory::Type().isEligible(P2) where P2 is a Passenger: " << BookingCategoryTypes::GeneralCategory::Type().isEligible(P2)<< std::endl;
	if(BookingCategoryTypes::GeneralCategory::Type().isEligible(P2)!=true)
	{
		std::cerr << "Error in Function isEligible() on P2" << std::endl;
	}
	std::cout << std::endl;
	std::cout << "BookingCategoryTypes::GeneralCategory::Type().isEligible(P3) where P3 is a Passenger: " << BookingCategoryTypes::GeneralCategory::Type().isEligible(P3)<< std::endl;
	if(BookingCategoryTypes::GeneralCategory::Type().isEligible(P3)!=true)
	{
		std::cerr << "Error in Function isEligible() on P3" << std::endl;
	}
	std::cout << std::endl;
	std::cout << "BookingCategoryTypes::GeneralCategory::Type().isEligible(P4) where P4 is a Passenger: " << BookingCategoryTypes::GeneralCategory::Type().isEligible(P4)<< std::endl;
	if(BookingCategoryTypes::GeneralCategory::Type().isEligible(P4)!=true)
	{
		std::cerr << "Error in Function isEligible() on P4" << std::endl;
	}
	std::cout << std::endl;
	std::cout << "BookingCategoryTypes::GeneralCategory::Type().isEligible(P5) where P5 is a Passenger: " << BookingCategoryTypes::GeneralCategory::Type().isEligible(P5)<< std::endl;
	if(BookingCategoryTypes::GeneralCategory::Type().isEligible(P5)!=true)
	{
		std::cerr << "Error in Function isEligible() on P5" << std::endl;
	}
	std::cout << std::endl;
	std::cout << std::endl;
	
}

template<>
void BookingCategory::LadiesCategory::UnitTestBookingCategory()
{
	std::cout << "STATIC UNIT TEST FUNCTION To unit test class BookingCategoryTypes::LadiesCategory" << std::endl << std::endl;


	//Check whether the class is singleton or not
	std::cout << "**********************************************************" << std::endl;
	std::cout << "Check whether the class is singleton or not:" << std::endl <<std::endl;
	std::cout << "Address of BookingCategoryTypes::LadiesCategory called the first time: " << &BookingCategoryTypes::LadiesCategory::Type() << std::endl;
	std::cout << std::endl;
	std::cout << "Address of BookingCategoryTypes::LadiesCategory called the second time: " << &BookingCategoryTypes::LadiesCategory::Type() << std::endl;
	std::cout << std::endl;
	if(&BookingCategoryTypes::LadiesCategory::Type() !=  &BookingCategoryTypes::LadiesCategory::Type())
	{
		std::cerr << "Error: BookingCategoryTypes::LadiesCategory is not a singleton class!!!" << std::endl;
	}
	else
	{
		std::cout << "BookingCategoryTypes::LadiesCategory is a singleton class" << std::endl;
	}

	//Check the static data
	std::cout << "**********************************************************" << std::endl;
	std::cout << "Check the static data stored : " << std::endl <<std::endl;
	std::cout << std::endl;
	std::cout  << "sName : " << BookingCategoryTypes::LadiesCategory::sName <<std::endl;
	
	//Check the isEligible member function
	std::cout << "**********************************************************" << std::endl;
	std::cout << "Check the isEligible member function:" << std::endl << std::endl;
	Passenger P1 = Passenger::createPassenger("Mike","","Xavier",21,01,2001,Gender::Male::Type(),"987654321012","",Divyaang::Blind::Type(),"123" );
	Passenger P2 = Passenger::createPassenger("Alexis","","Xavier",21,01,2001,Gender::Female::Type(),"987654321012","");
	Passenger P3 = Passenger::createPassenger("Carlos","","Xavier",21,01,1945,Gender::Male::Type(),"987654321012","",Divyaang::Blind::Type(),"124" );
	Passenger P4 = Passenger::createPassenger("Petricia","","Xavier",21,01,1940,Gender::Female::Type(),"987654321012","",Divyaang::Blind::Type(),"125" );
	Passenger P5 = Passenger::createPassenger("Michael","","Xavier",21,01,2015,Gender::Male::Type(),"987654321012","" );
	std::cout << "Passengers used to check the eligibility function: " << std::endl << std::endl;
	
	std::cout << "P1" << std::endl << P1 << std::endl;
	std::cout << "########################" << std::endl;
	std::cout << "P2" << std::endl << P2 << std::endl;
	std::cout << "########################" << std::endl;
	std::cout << "P3" << std::endl << P3 << std::endl;
	std::cout << "########################" << std::endl;
	std::cout << "P4" << std::endl << P4 << std::endl;
	std::cout << "########################" << std::endl;
	std::cout << "P5" << std::endl << P5 << std::endl;
	std::cout << "########################" << std::endl;
	std::cout << "BookingCategoryTypes::LadiesCategory::Type().isEligible(P1) where P1 is a Passenger: " << BookingCategoryTypes::LadiesCategory::Type().isEligible(P1)<< std::endl;
	if(BookingCategoryTypes::LadiesCategory::Type().isEligible(P1)!=false)
	{
		std::cerr << "Error in Function isEligible() on P1" << std::endl;
	}
	std::cout << std::endl;
	std::cout << "BookingCategoryTypes::LadiesCategory::Type().isEligible(P2) where P2 is a Passenger: " << BookingCategoryTypes::LadiesCategory::Type().isEligible(P2)<< std::endl;
	if(BookingCategoryTypes::LadiesCategory::Type().isEligible(P2)!=true)
	{
		std::cerr << "Error in Function isEligible() on P2" << std::endl;
	}
	std::cout << std::endl;
	std::cout << "BookingCategoryTypes::LadiesCategory::Type().isEligible(P3) where P3 is a Passenger: " << BookingCategoryTypes::LadiesCategory::Type().isEligible(P3)<< std::endl;
	if(BookingCategoryTypes::LadiesCategory::Type().isEligible(P3)!=false)
	{
		std::cerr << "Error in Function isEligible() on P3" << std::endl;
	}
	std::cout << std::endl;
	std::cout << "BookingCategoryTypes::LadiesCategory::Type().isEligible(P4) where P4 is a Passenger: " << BookingCategoryTypes::LadiesCategory::Type().isEligible(P4)<< std::endl;
	if(BookingCategoryTypes::LadiesCategory::Type().isEligible(P4)!=true)
	{
		std::cerr << "Error in Function isEligible() on P4" << std::endl;
	}
	std::cout << std::endl;
	std::cout << "BookingCategoryTypes::LadiesCategory::Type().isEligible(P5) where P5 is a Passenger: " << BookingCategoryTypes::LadiesCategory::Type().isEligible(P5)<< std::endl;
	if(BookingCategoryTypes::LadiesCategory::Type().isEligible(P5)!=true)
	{
		std::cerr << "Error in Function isEligible() on P5" << std::endl;
	}
	std::cout << std::endl;
	std::cout << std::endl;
	
}

template<>
void BookingCategory::SeniorCitizenCategory::UnitTestBookingCategory()
{
	std::cout << "STATIC UNIT TEST FUNCTION To unit test class BookingCategoryTypes::SeniorCitizenCategory" << std::endl << std::endl;


	//Check whether the class is singleton or not
	std::cout << "**********************************************************" << std::endl;
	std::cout << "Check whether the class is singleton or not:" << std::endl <<std::endl;
	std::cout << "Address of BookingCategoryTypes::SeniorCitizenCategory called the first time: " << &BookingCategoryTypes::SeniorCitizenCategory::Type() << std::endl;
	std::cout << std::endl;
	std::cout << "Address of BookingCategoryTypes::SeniorCitizenCategory called the second time: " << &BookingCategoryTypes::SeniorCitizenCategory::Type() << std::endl;
	std::cout << std::endl;
	if(&BookingCategoryTypes::SeniorCitizenCategory::Type() !=  &BookingCategoryTypes::SeniorCitizenCategory::Type())
	{
		std::cerr << "Error: BookingCategoryTypes::SeniorCitizenCategory is not a singleton class!!!" << std::endl;
	}
	else
	{
		std::cout << "BookingCategoryTypes::SeniorCitizenCategory is a singleton class" << std::endl;
	}

	//Check the static data
	std::cout << "**********************************************************" << std::endl;
	std::cout << "Check the static data stored : " << std::endl <<std::endl;
	std::cout << std::endl;
	std::cout  << "sName : " << BookingCategoryTypes::SeniorCitizenCategory::sName <<std::endl;
	
	//Check the isEligible member function
	std::cout << "**********************************************************" << std::endl;
	std::cout << "Check the isEligible member function:" << std::endl << std::endl;
	Passenger P1 = Passenger::createPassenger("Mike","","Xavier",21,01,2001,Gender::Male::Type(),"987654321012","",Divyaang::Blind::Type(),"123" );
	Passenger P2 = Passenger::createPassenger("Alexis","","Xavier",21,01,2001,Gender::Female::Type(),"987654321012","");
	Passenger P3 = Passenger::createPassenger("Carlos","","Xavier",21,01,1945,Gender::Male::Type(),"987654321012","",Divyaang::Blind::Type(),"124" );
	Passenger P4 = Passenger::createPassenger("Petricia","","Xavier",21,01,1940,Gender::Female::Type(),"987654321012","",Divyaang::Blind::Type(),"125" );
	Passenger P5 = Passenger::createPassenger("Michael","","Xavier",21,01,2015,Gender::Male::Type(),"987654321012","" );
	std::cout << "Passengers used to check the eligibility function: " << std::endl << std::endl;
	
	std::cout << "P1" << std::endl << P1 << std::endl;
	std::cout << "########################" << std::endl;
	std::cout << "P2" << std::endl << P2 << std::endl;
	std::cout << "########################" << std::endl;
	std::cout << "P3" << std::endl << P3 << std::endl;
	std::cout << "########################" << std::endl;
	std::cout << "P4" << std::endl << P4 << std::endl;
	std::cout << "########################" << std::endl;
	std::cout << "P5" << std::endl << P5 << std::endl;
	std::cout << "########################" << std::endl;
	std::cout << "BookingCategoryTypes::SeniorCitizenCategory::Type().isEligible(P1) where P1 is a Passenger: " << BookingCategoryTypes::SeniorCitizenCategory::Type().isEligible(P1)<< std::endl;
	if(BookingCategoryTypes::SeniorCitizenCategory::Type().isEligible(P1)!=false)
	{
		std::cerr << "Error in Function isEligible() on P1" << std::endl;
	}
	std::cout << std::endl;
	std::cout << "BookingCategoryTypes::SeniorCitizenCategory::Type().isEligible(P2) where P2 is a Passenger: " << BookingCategoryTypes::SeniorCitizenCategory::Type().isEligible(P2)<< std::endl;
	if(BookingCategoryTypes::SeniorCitizenCategory::Type().isEligible(P2)!=false)
	{
		std::cerr << "Error in Function isEligible() on P2" << std::endl;
	}
	std::cout << std::endl;
	std::cout << "BookingCategoryTypes::SeniorCitizenCategory::Type().isEligible(P3) where P3 is a Passenger: " << BookingCategoryTypes::SeniorCitizenCategory::Type().isEligible(P3)<< std::endl;
	if(BookingCategoryTypes::SeniorCitizenCategory::Type().isEligible(P3)!=true)
	{
		std::cerr << "Error in Function isEligible() on P3" << std::endl;
	}
	std::cout << std::endl;
	std::cout << "BookingCategoryTypes::SeniorCitizenCategory::Type().isEligible(P4) where P4 is a Passenger: " << BookingCategoryTypes::SeniorCitizenCategory::Type().isEligible(P4)<< std::endl;
	if(BookingCategoryTypes::SeniorCitizenCategory::Type().isEligible(P4)!=true)
	{
		std::cerr << "Error in Function isEligible() on P4" << std::endl;
	}
	std::cout << std::endl;
	std::cout << "BookingCategoryTypes::SeniorCitizenCategory::Type().isEligible(P5) where P5 is a Passenger: " << BookingCategoryTypes::SeniorCitizenCategory::Type().isEligible(P5)<< std::endl;
	if(BookingCategoryTypes::SeniorCitizenCategory::Type().isEligible(P5)!=false)
	{
		std::cerr << "Error in Function isEligible() on P5" << std::endl;
	}
	std::cout << std::endl;
	std::cout << std::endl;
	
}

template<>
void BookingCategory::DivyaangCategory::UnitTestBookingCategory()
{
	std::cout << "STATIC UNIT TEST FUNCTION To unit test class BookingCategoryTypes::DivyaangCategory" << std::endl << std::endl;


	//Check whether the class is singleton or not
	std::cout << "**********************************************************" << std::endl;
	std::cout << "Check whether the class is singleton or not:" << std::endl <<std::endl;
	std::cout << "Address of BookingCategoryTypes::DivyaangCategory called the first time: " << &BookingCategoryTypes::DivyaangCategory::Type() << std::endl;
	std::cout << std::endl;
	std::cout << "Address of BookingCategoryTypes::DivyaangCategory called the second time: " << &BookingCategoryTypes::DivyaangCategory::Type() << std::endl;
	std::cout << std::endl;
	if(&BookingCategoryTypes::DivyaangCategory::Type() !=  &BookingCategoryTypes::DivyaangCategory::Type())
	{
		std::cerr << "Error: BookingCategoryTypes::DivyaangCategory is not a singleton class!!!" << std::endl;
	}
	else
	{
		std::cout << "BookingCategoryTypes::DivyaangCategory is a singleton class" << std::endl;
	}

	//Check the static data
	std::cout << "**********************************************************" << std::endl;
	std::cout << "Check the static data stored : " << std::endl <<std::endl;
	std::cout << std::endl;
	std::cout  << "sName : " << BookingCategoryTypes::DivyaangCategory::sName <<std::endl;
	
	//Check the isEligible member function
	std::cout << "**********************************************************" << std::endl;
	std::cout << "Check the isEligible member function:" << std::endl << std::endl;
	Passenger P1 = Passenger::createPassenger("Mike","","Xavier",21,01,2001,Gender::Male::Type(),"987654321012","",Divyaang::Blind::Type(),"123" );
	Passenger P2 = Passenger::createPassenger("Alexis","","Xavier",21,01,2001,Gender::Female::Type(),"987654321012","");
	Passenger P3 = Passenger::createPassenger("Carlos","","Xavier",21,01,1945,Gender::Male::Type(),"987654321012","",Divyaang::Blind::Type(),"124" );
	Passenger P4 = Passenger::createPassenger("Petricia","","Xavier",21,01,1940,Gender::Female::Type(),"987654321012","",Divyaang::Blind::Type(),"125" );
	Passenger P5 = Passenger::createPassenger("Michael","","Xavier",21,01,2015,Gender::Male::Type(),"987654321012","" );
	std::cout << "Passengers used to check the eligibility function: " << std::endl << std::endl;
	
	std::cout << "P1" << std::endl << P1 << std::endl;
	std::cout << "########################" << std::endl;
	std::cout << "P2" << std::endl << P2 << std::endl;
	std::cout << "########################" << std::endl;
	std::cout << "P3" << std::endl << P3 << std::endl;
	std::cout << "########################" << std::endl;
	std::cout << "P4" << std::endl << P4 << std::endl;
	std::cout << "########################" << std::endl;
	std::cout << "P5" << std::endl << P5 << std::endl;
	std::cout << "########################" << std::endl;
	std::cout << "BookingCategoryTypes::DivyaangCategory::Type().isEligible(P1) where P1 is a Passenger: " << BookingCategoryTypes::DivyaangCategory::Type().isEligible(P1)<< std::endl;
	if(BookingCategoryTypes::DivyaangCategory::Type().isEligible(P1)!=true)
	{
		std::cerr << "Error in Function isEligible() on P1" << std::endl;
	}
	std::cout << std::endl;
	std::cout << "BookingCategoryTypes::DivyaangCategory::Type().isEligible(P2) where P2 is a Passenger: " << BookingCategoryTypes::DivyaangCategory::Type().isEligible(P2)<< std::endl;
	if(BookingCategoryTypes::DivyaangCategory::Type().isEligible(P2)!=false)
	{
		std::cerr << "Error in Function isEligible() on P2" << std::endl;
	}
	std::cout << std::endl;
	std::cout << "BookingCategoryTypes::DivyaangCategory::Type().isEligible(P3) where P3 is a Passenger: " << BookingCategoryTypes::DivyaangCategory::Type().isEligible(P3)<< std::endl;
	if(BookingCategoryTypes::DivyaangCategory::Type().isEligible(P3)!=true)
	{
		std::cerr << "Error in Function isEligible() on P3" << std::endl;
	}
	std::cout << std::endl;
	std::cout << "BookingCategoryTypes::DivyaangCategory::Type().isEligible(P4) where P4 is a Passenger: " << BookingCategoryTypes::DivyaangCategory::Type().isEligible(P4)<< std::endl;
	if(BookingCategoryTypes::DivyaangCategory::Type().isEligible(P4)!=true)
	{
		std::cerr << "Error in Function isEligible() on P4" << std::endl;
	}
	std::cout << std::endl;
	std::cout << "BookingCategoryTypes::DivyaangCategory::Type().isEligible(P5) where P5 is a Passenger: " << BookingCategoryTypes::DivyaangCategory::Type().isEligible(P5)<< std::endl;
	if(BookingCategoryTypes::DivyaangCategory::Type().isEligible(P5)!=false)
	{
		std::cerr << "Error in Function isEligible() on P5" << std::endl;
	}
	std::cout << std::endl;
	std::cout << std::endl;
	
}

template<>
void BookingCategory::TatkalCategory::UnitTestBookingCategory()
{
	std::cout << "STATIC UNIT TEST FUNCTION To unit test class BookingCategoryTypes::TatkalCategory" << std::endl << std::endl;


	//Check whether the class is singleton or not
	std::cout << "**********************************************************" << std::endl;
	std::cout << "Check whether the class is singleton or not:" << std::endl <<std::endl;
	std::cout << "Address of BookingCategoryTypes::TatkalCategory called the first time: " << &BookingCategoryTypes::TatkalCategory::Type() << std::endl;
	std::cout << std::endl;
	std::cout << "Address of BookingCategoryTypes::TatkalCategory called the second time: " << &BookingCategoryTypes::TatkalCategory::Type() << std::endl;
	std::cout << std::endl;
	if(&BookingCategoryTypes::TatkalCategory::Type() !=  &BookingCategoryTypes::TatkalCategory::Type())
	{
		std::cerr << "Error: BookingCategoryTypes::TatkalCategory is not a singleton class!!!" << std::endl;
	}
	else
	{
		std::cout << "BookingCategoryTypes::TatkalCategory is a singleton class" << std::endl;
	}

	//Check the static data
	std::cout << "**********************************************************" << std::endl;
	std::cout << "Check the static data stored : " << std::endl <<std::endl;
	std::cout << std::endl;
	std::cout  << "sName : " << BookingCategoryTypes::TatkalCategory::sName <<std::endl;
	
	//Check the isEligible member function
	std::cout << "**********************************************************" << std::endl;
	std::cout << "Check the isEligible member function:" << std::endl << std::endl;
	Passenger P1 = Passenger::createPassenger("Mike","","Xavier",21,01,2001,Gender::Male::Type(),"987654321012","",Divyaang::Blind::Type(),"123" );
	Passenger P2 = Passenger::createPassenger("Alexis","","Xavier",21,01,2001,Gender::Female::Type(),"987654321012","");
	Passenger P3 = Passenger::createPassenger("Carlos","","Xavier",21,01,1945,Gender::Male::Type(),"987654321012","",Divyaang::Blind::Type(),"124" );
	Passenger P4 = Passenger::createPassenger("Petricia","","Xavier",21,01,1940,Gender::Female::Type(),"987654321012","",Divyaang::Blind::Type(),"125" );
	Passenger P5 = Passenger::createPassenger("Michael","","Xavier",21,01,2015,Gender::Male::Type(),"987654321012","" );
	std::cout << "Passengers used to check the eligibility function: " << std::endl << std::endl;
	
	std::cout << "P1" << std::endl << P1 << std::endl;
	std::cout << "########################" << std::endl;
	std::cout << "P2" << std::endl << P2 << std::endl;
	std::cout << "########################" << std::endl;
	std::cout << "P3" << std::endl << P3 << std::endl;
	std::cout << "########################" << std::endl;
	std::cout << "P4" << std::endl << P4 << std::endl;
	std::cout << "########################" << std::endl;
	std::cout << "P5" << std::endl << P5 << std::endl;
	std::cout << "########################" << std::endl;
	std::cout << "BookingCategoryTypes::TatkalCategory::Type().isEligible(P1) where P1 is a Passenger: " << BookingCategoryTypes::TatkalCategory::Type().isEligible(P1)<< std::endl;
	if(BookingCategoryTypes::TatkalCategory::Type().isEligible(P1)!=true)
	{
		std::cerr << "Error in Function isEligible() on P1" << std::endl;
	}
	std::cout << std::endl;
	std::cout << "BookingCategoryTypes::TatkalCategory::Type().isEligible(P2) where P2 is a Passenger: " << BookingCategoryTypes::TatkalCategory::Type().isEligible(P2)<< std::endl;
	if(BookingCategoryTypes::TatkalCategory::Type().isEligible(P2)!=true)
	{
		std::cerr << "Error in Function isEligible() on P2" << std::endl;
	}
	std::cout << std::endl;
	std::cout << "BookingCategoryTypes::TatkalCategory::Type().isEligible(P3) where P3 is a Passenger: " << BookingCategoryTypes::TatkalCategory::Type().isEligible(P3)<< std::endl;
	if(BookingCategoryTypes::TatkalCategory::Type().isEligible(P3)!=true)
	{
		std::cerr << "Error in Function isEligible() on P3" << std::endl;
	}
	std::cout << std::endl;
	std::cout << "BookingCategoryTypes::TatkalCategory::Type().isEligible(P4) where P4 is a Passenger: " << BookingCategoryTypes::TatkalCategory::Type().isEligible(P4)<< std::endl;
	if(BookingCategoryTypes::TatkalCategory::Type().isEligible(P4)!=true)
	{
		std::cerr << "Error in Function isEligible() on P4" << std::endl;
	}
	std::cout << std::endl;
	std::cout << "BookingCategoryTypes::TatkalCategory::Type().isEligible(P5) where P5 is a Passenger: " << BookingCategoryTypes::TatkalCategory::Type().isEligible(P5)<< std::endl;
	if(BookingCategoryTypes::TatkalCategory::Type().isEligible(P5)!=true)
	{
		std::cerr << "Error in Function isEligible() on P5" << std::endl;
	}
	std::cout << std::endl;
	std::cout << std::endl;
	
}

template<>
void BookingCategory::PremiumTatkalCategory::UnitTestBookingCategory()
{
	std::cout << "STATIC UNIT TEST FUNCTION To unit test class BookingCategoryTypes::PremiumTatkalCategory" << std::endl << std::endl;


	//Check whether the class is singleton or not
	std::cout << "**********************************************************" << std::endl;
	std::cout << "Check whether the class is singleton or not:" << std::endl <<std::endl;
	std::cout << "Address of BookingCategoryTypes::PremiumTatkalCategory called the first time: " << &BookingCategoryTypes::PremiumTatkalCategory::Type() << std::endl;
	std::cout << std::endl;
	std::cout << "Address of BookingCategoryTypes::PremiumTatkalCategory called the second time: " << &BookingCategoryTypes::PremiumTatkalCategory::Type() << std::endl;
	std::cout << std::endl;
	if(&BookingCategoryTypes::PremiumTatkalCategory::Type() !=  &BookingCategoryTypes::PremiumTatkalCategory::Type())
	{
		std::cerr << "Error: BookingCategoryTypes::PremiumTatkalCategory is not a singleton class!!!" << std::endl;
	}
	else
	{
		std::cout << "BookingCategoryTypes::PremiumTatkalCategory is a singleton class" << std::endl;
	}

	//Check the static data
	std::cout << "**********************************************************" << std::endl;
	std::cout << "Check the static data stored : " << std::endl <<std::endl;
	std::cout << std::endl;
	std::cout  << "sName : " << BookingCategoryTypes::PremiumTatkalCategory::sName <<std::endl;
	
	//Check the isEligible member function
	std::cout << "**********************************************************" << std::endl;
	std::cout << "Check the isEligible member function:" << std::endl << std::endl;
	Passenger P1 = Passenger::createPassenger("Mike","","Xavier",21,01,2001,Gender::Male::Type(),"987654321012","",Divyaang::Blind::Type(),"123" );
	Passenger P2 = Passenger::createPassenger("Alexis","","Xavier",21,01,2001,Gender::Female::Type(),"987654321012","");
	Passenger P3 = Passenger::createPassenger("Carlos","","Xavier",21,01,1945,Gender::Male::Type(),"987654321012","",Divyaang::Blind::Type(),"124" );
	Passenger P4 = Passenger::createPassenger("Petricia","","Xavier",21,01,1940,Gender::Female::Type(),"987654321012","",Divyaang::Blind::Type(),"125" );
	Passenger P5 = Passenger::createPassenger("Michael","","Xavier",21,01,2015,Gender::Male::Type(),"987654321012","" );
	std::cout << "Passengers used to check the eligibility function: " << std::endl << std::endl;
	
	std::cout << "P1" << std::endl << P1 << std::endl;
	std::cout << "########################" << std::endl;
	std::cout << "P2" << std::endl << P2 << std::endl;
	std::cout << "########################" << std::endl;
	std::cout << "P3" << std::endl << P3 << std::endl;
	std::cout << "########################" << std::endl;
	std::cout << "P4" << std::endl << P4 << std::endl;
	std::cout << "########################" << std::endl;
	std::cout << "P5" << std::endl << P5 << std::endl;
	std::cout << "########################" << std::endl;
	std::cout << "BookingCategoryTypes::PremiumTatkalCategory::Type().isEligible(P1) where P1 is a Passenger: " << BookingCategoryTypes::PremiumTatkalCategory::Type().isEligible(P1)<< std::endl;
	if(BookingCategoryTypes::PremiumTatkalCategory::Type().isEligible(P1)!=true)
	{
		std::cerr << "Error in Function isEligible() on P1" << std::endl;
	}
	std::cout << std::endl;
	std::cout << "BookingCategoryTypes::PremiumTatkalCategory::Type().isEligible(P2) where P2 is a Passenger: " << BookingCategoryTypes::PremiumTatkalCategory::Type().isEligible(P2)<< std::endl;
	if(BookingCategoryTypes::PremiumTatkalCategory::Type().isEligible(P2)!=true)
	{
		std::cerr << "Error in Function isEligible() on P2" << std::endl;
	}
	std::cout << std::endl;
	std::cout << "BookingCategoryTypes::PremiumTatkalCategory::Type().isEligible(P3) where P3 is a Passenger: " << BookingCategoryTypes::PremiumTatkalCategory::Type().isEligible(P3)<< std::endl;
	if(BookingCategoryTypes::PremiumTatkalCategory::Type().isEligible(P3)!=true)
	{
		std::cerr << "Error in Function isEligible() on P3" << std::endl;
	}
	std::cout << std::endl;
	std::cout << "BookingCategoryTypes::PremiumTatkalCategory::Type().isEligible(P4) where P4 is a Passenger: " << BookingCategoryTypes::PremiumTatkalCategory::Type().isEligible(P4)<< std::endl;
	if(BookingCategoryTypes::PremiumTatkalCategory::Type().isEligible(P4)!=true)
	{
		std::cerr << "Error in Function isEligible() on P4" << std::endl;
	}
	std::cout << std::endl;
	std::cout << "BookingCategoryTypes::PremiumTatkalCategory::Type().isEligible(P5) where P5 is a Passenger: " << BookingCategoryTypes::PremiumTatkalCategory::Type().isEligible(P5)<< std::endl;
	if(BookingCategoryTypes::PremiumTatkalCategory::Type().isEligible(P5)!=true)
	{
		std::cerr << "Error in Function isEligible() on P5" << std::endl;
	}
	std::cout << std::endl;
	std::cout << std::endl;
	
}

