//Imports
#include <iostream>
#include "Name.h"
#include "Date.h"
#include "Station.h"
#include "Railways.h"
#include "Booking.h"
#include "Name.h"
#include "Gender.h"
#include "Divyaang.h"
#include "Concessions.h"
#include "General_Concession.h"
#include "Ladies_Concession.h"
#include "SeniorCitizen_Concession.h"
#include "Divyaang_Concession.h"
#include "Bad_Date.h"
#include "Bad_Name.h"
#include "Bad_Aadhaar.h"
#include "Bad_Mobile.h"
#include "Bad_Station.h"

void ApplicationTest()
{
	std::cout << "******************APPLICATION TEST********************" << std::endl << std::endl << std::endl;
	
	std::cout << "########### VALID PASSENGER CREATION #############" << std::endl;
	Passenger P1 = Passenger::createPassenger("Mike","","Xavier",21,01,2001,Gender::Male::Type(),"987654321012","1234567890" );
	Passenger P2 = Passenger::createPassenger("Alexis","Carlos","Xavier",21,01,2000,Gender::Female::Type(),"987653321012");
	Passenger P3 = Passenger::createPassenger("Carlos","","Xavier",21,01,1945,Gender::Male::Type(),"987655321012","",Divyaang::TB_Patient::Type(),"123");
	Passenger P4 = Passenger::createPassenger("Petricia","","Xavier",18,9,1940,Gender::Female::Type(),"987656321012");
	Passenger P5 = Passenger::createPassenger("Michael","","Xavier",2,12,2015,Gender::Male::Type(),"987657321012");
	Passenger P6 = Passenger::createPassenger("Michelle","Rodriguez","Xavier",22,04,2016,Gender::Female::Type(),"987657321012","4356789011",Divyaang::Blind::Type(),"345");
	
	std::cout << "*****Adults*****" << std::endl;
	std::cout << "P1" << std::endl << P1 << std::endl;
	std::cout << "P2" << std::endl << P2 << std::endl;
	std::cout << "*****Senior Citizen*****" << std::endl;
	std::cout << "P3" << std::endl << P3 << std::endl;
	std::cout << "P4" << std::endl << P4 << std::endl;
	std::cout << "*****Children*****" << std::endl;
	std::cout << "P5" << std::endl << P5 << std::endl;
	std::cout << "P6" << std::endl << P6 << std::endl;
	std::cout << "##################################################" << std::endl<< std::endl << std::endl;
	
	
	std::cout << "########### INVALID PASSENGER CREATION (Exception Handling) #############" << std::endl<< std::endl << std::endl;
	std::cout << "*****Create a Passenger who last both first name and last name missing*****" << std::endl << std::endl;
	try
	{
		Passenger P7 = Passenger::createPassenger("","","",21,01,2001,Gender::Male::Type(),"987654321012","1234567890" );
	}
	catch(Bad_Name& B)
	{
		std::cout << "Exception caught successfully upon trying to create an invalid Passenger who last both first name and last name missing" << std::endl;
		std::cout << "Exception message: " << B.what() << std::endl << std::endl;
	}
	catch(Bad_Passenger& B)
	{
		std::cout << "Exception caught successfully upon trying to create an invalid Passenger who last both first name and last name missing" << std::endl;
		std::cout << "Exception message: " << B.what() << std::endl << std::endl;
	}
	
	std::cout << "*****Create a Passenger who has dateOfBirth in the future*****" << std::endl << std::endl;
	try
	{
		Passenger P8 = Passenger::createPassenger("Alexis","Carlos","Xavier",21,01,2050,Gender::Female::Type(),"987653321012");
	}
	catch(Bad_Date& B)
	{
		std::cout << "Exception caught successfully upon trying to create an invalid Passenger who has dateOfBirth in the future" << std::endl;
		std::cout << "Exception message: " << B.what() << std::endl << std::endl;
	}
	catch(Bad_Passenger& B)
	{
		std::cout << "Exception caught successfully upon trying to create an invalid Passenger who has dateOfBirth in the future" << std::endl;
		std::cout << "Exception message: " << B.what() << std::endl << std::endl;
	}
	
	std::cout << "*****Create a Passenger who has invalid aadhaar Number*****" << std::endl << std::endl;
	try
	{
		Passenger P9 = Passenger::createPassenger("Carlos","","Xavier",21,01,1945,Gender::Male::Type(),"987Ab1012","",Divyaang::TB_Patient::Type(),"123");
	}
	catch(Bad_Aadhaar& B)
	{
		std::cout << "Exception caught successfully upon trying to create an invalid Passenger who has invalid aadhaar Number" << std::endl;
		std::cout << "Exception message: " << B.what() << std::endl << std::endl;
	}
	catch(Bad_Passenger& B)
	{
		std::cout << "Exception caught successfully upon trying to create an invalid Passenger who has invalid aadhaar Number" << std::endl;
		std::cout << "Exception message: " << B.what() << std::endl << std::endl;
	}
	
	std::cout << "*****Create a Passenger who has invalid Mobile Number*****" << std::endl << std::endl;
	try
	{
		Passenger P10 = Passenger::createPassenger("Carlos","","Xavier",21,01,1945,Gender::Male::Type(),"987653321012","1234Avgh89",Divyaang::TB_Patient::Type(),"123");
	}
	catch(Bad_Aadhaar& B)
	{
		std::cout << "Exception caught successfully upon trying to create an invalid Passenger who has invalid Mobile Number" << std::endl;
		std::cout << "Exception message: " << B.what() << std::endl << std::endl;
	}
	catch(Bad_Passenger& B)
	{
		std::cout << "Exception caught successfully upon trying to create an invalid Passenger who has invalid Mobile Number" << std::endl;
		std::cout << "Exception message: " << B.what() << std::endl << std::endl;
		
	}
	std::cout << "#########################################################################" << std::endl<< std::endl << std::endl;
	
	
	std::cout << "########### VALID BOOKING CREATION (using Valid Passengers) #############" << std::endl;
	std::cout << "*****General*****" << std::endl;
	Booking* B1 = Booking::GeneralBooking::createBooking(Station::createStation("Delhi"),Station::createStation("Mumbai"),Date::createDate(9,12,2021),BookingClass::AC3Tier::Type(),BookingCategory::GeneralCategory::Type(),P1);
	Booking* B2 = Booking::GeneralBooking::createBooking(Station::createStation("Delhi"),Station::createStation("Mumbai"),Date::createDate(27,12,2021),BookingClass::ACFirstClass::Type(),BookingCategory::GeneralCategory::Type(),P2);
	std::cout << "B1" << std::endl << *B1 << std::endl;
	std::cout << "B2" << std::endl << *B2 << std::endl;
	std::cout << "*****Senior Citizen*****" << std::endl;
	Booking* B3 = Booking::SeniorCitizenBooking::createBooking(Station::createStation("Delhi"),Station::createStation("Mumbai"),Date::createDate(28,11,2021),BookingClass::AC3Tier::Type(),BookingCategory::SeniorCitizenCategory::Type(),P3);
	Booking* B4 = Booking::SeniorCitizenBooking::createBooking(Station::createStation("Delhi"),Station::createStation("Mumbai"),Date::createDate(9,10,2021),BookingClass::ACFirstClass::Type(),BookingCategory::SeniorCitizenCategory::Type(),P4);
	std::cout << "B3" << std::endl << *B3 << std::endl;
	std::cout << "B4" << std::endl << *B4 << std::endl;
	std::cout << "*****Divyaang*****" << std::endl;
	Booking* B5 = Booking::DivyaangBooking::createBooking(Station::createStation("Delhi"),Station::createStation("Mumbai"),Date::createDate(28,11,2021),BookingClass::AC3Tier::Type(),BookingCategory::DivyaangCategory::Type(),P6);
	Booking* B6 = Booking::DivyaangBooking::createBooking(Station::createStation("Delhi"),Station::createStation("Mumbai"),Date::createDate(9,10,2021),BookingClass::ACFirstClass::Type(),BookingCategory::DivyaangCategory::Type(),P3);
	std::cout << "B5" << std::endl << *B5 << std::endl;
	std::cout << "B6" << std::endl << *B6 << std::endl;
	std::cout << "*****Tatkal*****" << std::endl;
	Booking* B7 = Booking::TatkalBooking::createBooking(Station::createStation("Delhi"),Station::createStation("Mumbai"),Date::GetCurrentDate(),BookingClass::AC3Tier::Type(),BookingCategory::TatkalCategory::Type(),P4);
	Booking* B8 = Booking::TatkalBooking::createBooking(Station::createStation("Chennai"),Station::createStation("Bangalore"),Date::GetCurrentDate(),BookingClass::ACFirstClass::Type(),BookingCategory::TatkalCategory::Type(),P5);
	std::cout << "B7" << std::endl << *B7 << std::endl;
	std::cout << "B8" << std::endl << *B8 << std::endl;
	std::cout << "*****PremiumTatkal*****" << std::endl;
	Booking* B9 = Booking::PremiumTatkalBooking::createBooking(Station::createStation("Delhi"),Station::createStation("Mumbai"),Date::GetCurrentDate(),BookingClass::AC3Tier::Type(),BookingCategory::PremiumTatkalCategory::Type(),P4);
	Booking* B10 = Booking::PremiumTatkalBooking::createBooking(Station::createStation("Chennai"),Station::createStation("Bangalore"),Date::GetCurrentDate(),BookingClass::ACFirstClass::Type(),BookingCategory::PremiumTatkalCategory::Type(),P5);
	std::cout << "B9" << std::endl << *B9 << std::endl;
	std::cout << "B10" << std::endl << *B10 << std::endl;
	std::cout << "#########################################################################" << std::endl<< std::endl << std::endl;
	
	
	std::cout << "########### INVALID BOOKING CREATION (Exception Handling) #############" << std::endl<< std::endl << std::endl;
	std::cout << "*****Create a Booking with past date*****" << std::endl << std::endl;
	Booking* B11;
	try
	{
		B11 = Booking::GeneralBooking::createBooking(Station::createStation("Delhi"),Station::createStation("Mumbai"),Date::createDate(9,12,2019),BookingClass::AC3Tier::Type(),BookingCategory::GeneralCategory::Type(),P1);
	}
	catch(Bad_Date& B)
	{
		std::cout << "Exception caught successfully upon trying to create an invalid Booking with past date" << std::endl;
		std::cout << "Exception message: " << B.what() << std::endl << std::endl;
	}
	catch(Bad_Booking& B)
	{
		std::cout << "Exception caught successfully upon trying to create an invalid Booking with past date" << std::endl;
		std::cout << "Exception message: " << B.what() << std::endl << std::endl;
	}
	
	std::cout << "*****Create a Booking with fromStation same as toStation*****" << std::endl << std::endl;
	Booking* B12;
	try
	{
		B12 = Booking::GeneralBooking::createBooking(Station::createStation("Mumbai"),Station::createStation("Mumbai"),Date::createDate(9,12,2019),BookingClass::AC3Tier::Type(),BookingCategory::GeneralCategory::Type(),P1);
	}
	catch(Bad_Station& B)
	{
		std::cout << "Exception caught successfully upon trying to create an invalid Booking with fromStation same as toStation" << std::endl;
		std::cout << "Exception message: " << B.what() << std::endl << std::endl;
	}
	catch(Bad_Booking& B)
	{
		std::cout << "Exception caught successfully upon trying to create an invalid Booking with fromStation same as toStation" << std::endl;
		std::cout << "Exception message: " << B.what() << std::endl << std::endl;
	}
	
	std::cout << "*****Create a Booking with date for more than a year*****" << std::endl << std::endl;
	Booking* B13;
	try
	{
		B13 = Booking::GeneralBooking::createBooking(Station::createStation("Delhi"),Station::createStation("Mumbai"),Date::createDate(9,12,2050),BookingClass::AC3Tier::Type(),BookingCategory::GeneralCategory::Type(),P1);
	}
	catch(Bad_Date& B)
	{
		std::cout << "Exception caught successfully upon trying to create an invalid Booking with date for more than a year" << std::endl;
		std::cout << "Exception message: " << B.what() << std::endl << std::endl;
	}
	catch(Bad_Booking& B)
	{
		std::cout << "Exception caught successfully upon trying to create an invalid Booking with date for more than a year" << std::endl;
		std::cout << "Exception message: " << B.what() << std::endl << std::endl;
	}
	
	std::cout << "*****Create a Booking with Passenger Ineligible for the Booking Category*****" << std::endl << std::endl;
	Booking* B14;
	try
	{
		B14 = Booking::DivyaangBooking::createBooking(Station::createStation("Delhi"),Station::createStation("Mumbai"),Date::createDate(28,11,2021),BookingClass::AC3Tier::Type(),BookingCategory::DivyaangCategory::Type(),P1);
	}
	catch(Bad_Passenger& B)
	{
		std::cout << "Exception caught successfully upon trying to create an invalid Booking with Passenger Ineligible for the Booking Category" << std::endl;
		std::cout << "Exception message: " << B.what() << std::endl << std::endl;
	}
	catch(Bad_Booking& B)
	{
		std::cout << "Exception caught successfully upon trying to create an invalid Booking with Passenger Ineligible for the Booking Category" << std::endl;
		std::cout << "Exception message: " << B.what() << std::endl << std::endl;
	}
	std::cout << "#########################################################################" << std::endl<< std::endl << std::endl;
	
}
