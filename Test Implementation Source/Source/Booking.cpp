/* ****************************************
*	Name: Hritaban Ghosh
*	Roll Number: 19CS30053
**************************************** */

//Imports
#include "Booking.h"
#include "Railways.h"
#include "Station.h"
#include "Date.h"
#include "BookingClass.h"
#include "Passenger.h"
#include "Concessions.h"
#include "Ladies_Concession.h"
#include "SeniorCitizen_Concession.h"
#include "Divyaang_Concession.h"
#include <iostream>
#include <string>
#include <cmath>
#include <ctime>

//General Booking
template<>
int Booking::GeneralBooking::ComputeFare() const
{
	double fare = 0;
	double distance = Railways::IndianRailways().GetDistance(Station(this->fromStation), Station(this->toStation));
	
	std::string bookingClassName = (this->bookingClass).GetName();
	
	double baseFare = distance*(Booking::sBareFarePerKM);
	
	double loadedFare = baseFare*((this->bookingClass).GetLoadFactor());
	fare = loadedFare;
	
	double reservationCharge = (this->bookingClass).GetReservationCharge();
	fare += reservationCharge;
	
	return std::round(fare);
}

//Ladies Booking
template<>
int Booking::LadiesBooking::ComputeFare() const
{
	double fare = 0;
	double distance = Railways::IndianRailways().GetDistance(Station(this->fromStation), Station(this->toStation));
	
	std::string bookingClassName = (this->bookingClass).GetName();
	
	double baseFare = distance*(Booking::sBareFarePerKM);
	
	double loadedFare = baseFare*((this->bookingClass).GetLoadFactor());
	fare = loadedFare;
	
	double concessionFactor = Ladies_Concession::GetConcessionFactor(this->passenger);
	double concessionFare = fare*(1-concessionFactor);
	fare = concessionFare;
	
	double reservationCharge = (this->bookingClass).GetReservationCharge();
	fare += reservationCharge;
	
	return std::round(fare);
}

//Senior Citizen Booking
template<>
int Booking::SeniorCitizenBooking::ComputeFare() const
{
	double fare = 0;
	double distance = Railways::IndianRailways().GetDistance(Station(this->fromStation), Station(this->toStation));
	
	std::string bookingClassName = (this->bookingClass).GetName();
	
	double baseFare = distance*(Booking::sBareFarePerKM);
	
	double loadedFare = baseFare*((this->bookingClass).GetLoadFactor());
	fare = loadedFare;
	
	double concessionFactor = SeniorCitizen_Concession::GetConcessionFactor(this->passenger);
	double concessionFare = fare*(1-concessionFactor);
	fare = concessionFare;
	
	double reservationCharge = (this->bookingClass).GetReservationCharge();
	fare += reservationCharge;
	
	return std::round(fare);
}

//Divyaang Booking
template<>
int Booking::DivyaangBooking::ComputeFare() const
{
	double fare = 0;
	double distance = Railways::IndianRailways().GetDistance(Station(this->fromStation), Station(this->toStation));
	
	std::string bookingClassName = (this->bookingClass).GetName();
	
	double baseFare = distance*(Booking::sBareFarePerKM);
	
	double loadedFare = baseFare*((this->bookingClass).GetLoadFactor());
	fare = loadedFare;
	
	double concessionFactor = Divyaang_Concession::GetConcessionFactor(this->bookingClass,this->passenger);
	double concessionFare = fare*(1-concessionFactor);
	fare = concessionFare;
	
	double reservationCharge = (this->bookingClass).GetReservationCharge();
	fare += reservationCharge;
	
	return std::round(fare);
}

//Tatkal Booking
template<>
int Booking::TatkalBooking::ComputeFare() const
{
	double fare = 0;
	double distance = Railways::IndianRailways().GetDistance(Station(this->fromStation), Station(this->toStation));
	
	std::string bookingClassName = (this->bookingClass).GetName();
	
	double baseFare = distance*(Booking::sBareFarePerKM);
	
	double loadedFare = baseFare*((this->bookingClass).GetLoadFactor());
	fare = loadedFare;
	
	double tatkalCharge = (this->bookingClass).GetTatkalLoadFactor() * fare;
	
	if(distance < (this->bookingClass).GetMinimumTatkalDistance())
	{
		tatkalCharge=0;
	}
	else
	{
		if(tatkalCharge < (this->bookingClass).GetMinimumTatkalCharges())
		{
			tatkalCharge=(this->bookingClass).GetMinimumTatkalCharges();
		}
		else if(tatkalCharge > (this->bookingClass).GetMaximumTatkalCharges())
		{
			tatkalCharge=(this->bookingClass).GetMaximumTatkalCharges();
		}
	}
	
	double reservationCharge = (this->bookingClass).GetReservationCharge();
	fare = fare+tatkalCharge+reservationCharge;
	
	return std::round(fare);
}

//Premium Tatkal Booking
template<>
int Booking::PremiumTatkalBooking::ComputeFare() const
{
	double fare = 0;
	double distance = Railways::IndianRailways().GetDistance(Station(this->fromStation), Station(this->toStation));
	
	std::string bookingClassName = (this->bookingClass).GetName();
	
	double baseFare = distance*(Booking::sBareFarePerKM);
	
	double loadedFare = baseFare*((this->bookingClass).GetLoadFactor());
	fare = loadedFare;
	
	double tatkalCharge = (this->bookingClass).GetTatkalLoadFactor() * fare;
	
	if(distance < (this->bookingClass).GetMinimumTatkalDistance())
	{
		tatkalCharge=0;
	}
	else
	{
		if(tatkalCharge < (this->bookingClass).GetMinimumTatkalCharges())
		{
			tatkalCharge=(this->bookingClass).GetMinimumTatkalCharges();
		}
		else if(tatkalCharge > (this->bookingClass).GetMaximumTatkalCharges())
		{
			tatkalCharge=(this->bookingClass).GetMaximumTatkalCharges();
		}
	}
	
	double reservationCharge = (this->bookingClass).GetReservationCharge();
	fare = fare+2*tatkalCharge+reservationCharge;
	
	return std::round(fare);
}


//Stores pointers to Bookings made in the Railway Booking System
std::vector<Booking*> Booking::sBookings = {};

//Stores the Bare Fare per Kilometer
const double Booking::sBareFarePerKM = 0.5;

//Stores the current PNR Serial starting from 1
int Booking::sBookingPNRSerial = 1;

template <typename T>
BookingTypes<T>* BookingTypes<T>::createBooking(Station fromStation_val, Station toStation_val, Date dateOfBooking_val, const BookingClass& bookingClass_val, const BookingCategory& bookingCategory_val, const Passenger& passenger_val) 
{
	if(dateOfBooking_val.isWithinOneYear(Date::GetCurrentDate())!=true || fromStation_val==toStation_val || !bookingCategory_val.isEligiblefor(passenger_val))
	{
		throw Bad_Booking();
	}
	auto B = new BookingTypes<T>(fromStation_val, toStation_val,dateOfBooking_val,bookingClass_val, bookingCategory_val,passenger_val);
	return B;
}


//Constructor
Booking::Booking(Station fromStation_val, Station toStation_val, Date dateOfBooking_val, const BookingClass& bookingClass_val, const BookingCategory& bookingCategory_val, const Passenger& passenger_val)
 : fromStation{fromStation_val}, toStation{toStation_val}, dateOfBooking{dateOfBooking_val}, bookingClass{bookingClass_val}, bookingCategory{bookingCategory_val}, fare{0}, PNR{Booking::sBookingPNRSerial++}, passenger{passenger_val}, dateOfReservation{Date::GetCurrentDate()}
{
	sBookings.push_back(this);
}

//Virtual Destructor
Booking::~Booking()
{
	auto it = sBookings.begin();
	for(;it != sBookings.end(); it++)
	{
		if((*it) == this)
		{
			sBookings.erase(it);
			break;
		}
	}
}

//Binary Equality Operator
//Returns true if both have the same PNR number else false
bool Booking::operator==(const Booking& other) const
{
	return (*this).PNR == other.PNR;
}

//Binary Inequality Operator
//Returns true if both have different PNR number else false
bool Booking::operator!=(const Booking& other) const
{
	return (*this).PNR != other.PNR;
}


//The insertion operator is overloaded as a friend function and prints out necessary details of the Booking
std::ostream& operator<<(std::ostream& out, const Booking& booking)
{
	out << std::endl;
	out << "Passenger Details :" << std::endl;
	out << booking.passenger << std::endl;
	out << "Booking Details :" << std::endl;
	out << booking.bookingMessage << ":" << std::endl;
	out << "PNR Number : " << booking.PNR << std::endl;
	out << "From Station : " << booking.fromStation.GetName() << std::endl;
	out << "To Station : " << booking.toStation.GetName() << std::endl;
	out << "Travel Date : " << booking.dateOfBooking << std::endl;
	out << "Travel Class : " << booking.bookingClass.GetName() << std::endl;
	out << "Travel Category : " << booking.bookingCategory.GetName() << std::endl;
	out << "Reservation Date : " << booking.dateOfReservation << std::endl;
	if (booking.bookingClass.IsSitting())
	{
		out << "--> Mode : Sitting" << std::endl;
	}
	else
	{
		out << "--> Mode : Sleeping" << std::endl;
	}
	
	if (booking.bookingClass.IsAC())
	{
		out << "--> Comfort : AC" << std::endl;
	}
	else
	{
		out << "--> Comfort : Non-AC" << std::endl;
	}
	
	out << "--> Bunks : " << booking.bookingClass.GetNumberOfTiers() << std::endl;
	
	if (booking.bookingClass.IsLuxury())
	{
		out << "--> Luxury : Yes" << std::endl;
	}
	else
	{
		out << "--> Luxury : No" << std::endl;
	}
	
	out << "Fare : " << booking.fare << std::endl << std::endl;
	return out;
}

//STATIC UNIT TEST FUNCTION
template<>
void Booking::GeneralBooking::UnitTestBooking()//To unit test class Booking
{
	std::cout << "STATIC UNIT TEST FUNCTION To unit test class Booking" << std::endl << std::endl;
	
	//Check the static constants
	std::cout << "**********************************************************" << std::endl;
	std::cout << "Check the static constants:" << std::endl << std::endl;
	std::cout << "Checking the sBareFarePerKM:" << sBareFarePerKM << std::endl << std::endl;
	if(sBareFarePerKM!=0.5)
	{
		std::cerr << "Error on Initialisation of sBareFarePerKM" << std::endl;
	}
	
	//Check the construction of a Booking Object
	std::cout << "**********************************************************" << std::endl;
	Passenger P1 = Passenger::createPassenger("Mike","","Xavier",21,01,2001,Gender::Male::Type(),"987654321012","",Divyaang::Blind::Type(),"123" );
	Booking::GeneralBooking* B1 = Booking::GeneralBooking::createBooking(Station::createStation("Mumbai"),Station::createStation("Delhi"),Date::createDate(21,5,2021),BookingClass::ACFirstClass::Type(),BookingCategory::GeneralCategory::Type(),P1);
	std::cout << *B1 << std::endl;
	
	std::cout << "**********************************************************" << std::endl;
	Booking* B2=0;
	try
	{
		B2 = Booking::GeneralBooking::createBooking(Station::createStation("Mumbai"),Station::createStation("Delhi"),Date::createDate(21,3,2021),BookingClass::ACFirstClass::Type(),BookingCategory::GeneralCategory::Type(),P1);
	
	}
	catch(Bad_Booking& B)
	{
		std::cout << "Exception caught successfully upon trying to create an invalid Booking with past date." << std::endl << std::endl;
		std::cout << "Exception message: " << B.what() << std::endl << std::endl;
		if(B2!=0)
		{
			delete B2;
		}
	}
	
	std::cout << "**********************************************************" << std::endl;
	Booking* B3=0;
	try
	{
		B3 = Booking::GeneralBooking::createBooking(Station::createStation("Mumbai"),Station::createStation("Mumbai"),Date::createDate(21,5,2021),BookingClass::ACFirstClass::Type(),BookingCategory::GeneralCategory::Type(),P1);
	
	}
	catch(Bad_Booking& B)
	{
		std::cout << "Exception caught successfully upon trying to create an invalid Booking with having fromStation and toStation to be the same." << std::endl << std::endl;
		std::cout << "Exception message: " << B.what() << std::endl << std::endl;
		if(B3!=0)
		{
			delete B3;
		}
	}
	
	std::cout << "**********************************************************" << std::endl;
	
	std::cout << "Booking::GeneralBooking::createBooking(Station::createStation(\"Mumbai\"),Station::createStation(\"Delhi\"),\nDate::createDate(21,5,2021),BookingClass::ACFirstClass::Type(),BookingCategory::GeneralCategory::Type(),P1) booking instance has been constructed"  << std::endl;
	std::cout << std::endl;
	if(B1->fromStation!=Station::createStation("Mumbai"))
	{
		std::cerr << "Error in Constructor of Booking Class" << std::endl;
	}
	else 
	{
		std::cout << "B1->fromStation.GetName(): " << B1->fromStation.GetName() << std::endl;
	}
	
	if(B1->toStation!=Station::createStation("Delhi"))
	{
		std::cerr << "Error in Constructor of Booking Class" << std::endl;
	}
	else 
	{
		std::cout << "B1->toStation.GetName(): " << B1->toStation.GetName() << std::endl;
	}
	
	if(B1->dateOfBooking!=Date::createDate(21,5,2021))
	{
		std::cerr << "Error in Constructor of Booking Class" << std::endl;
	}
	else 
	{
		std::cout << "B1->dateOfBooking: " << B1->dateOfBooking << std::endl;
	}
	
	if(&(B1->bookingClass)!=&BookingClass::ACFirstClass::Type())
	{
		std::cerr << "Error in Constructor of Booking Class" << std::endl;
	}
	else
	{
		std::cout << "B1->bookingClass.GetName(): " << B1->bookingClass.GetName() << std::endl;
	}
	
	if(&(B1->bookingCategory)!=&BookingCategory::GeneralCategory::Type())
	{
		std::cerr << "Error in Constructor of Booking Class" << std::endl;
	}
	else
	{
		std::cout << "B1->bookingCategory.GetName(): " << B1->bookingCategory.GetName() << std::endl;
	}
	
	if(B1->fare != 4763)
	{
		std::cerr << "Error in Constructor of Booking Class" << std::endl;
	}
	else
	{
		std::cout << "B1->fare: " << B1->fare << std::endl;
	}
	
	if(B1->dateOfReservation!=Date::GetCurrentDate())
	{
		std::cerr << "Error in Constructor of Booking Class" << std::endl;
	}
	else 
	{
		std::cout << "B1->dateOfReservation: " << B1->dateOfReservation << std::endl;
	}
	
	
	//Checking the working of ComputeFare() Member Funciton
	if(B1->ComputeFare() != 4763)
	{
		std::cerr << "Error in ComputeFare() Member Funciton of Booking Class" << std::endl;
	}
	else
	{
		std::cout << "B1->ComputeFare(): " << B1->ComputeFare() << std::endl;
	}
	std::cout << std::endl;
	
	
	Booking::GeneralBooking* D = Booking::GeneralBooking::createBooking(Station::createStation("Mumbai"),Station::createStation("Chennai"),Date::createDate(22,5,2021),BookingClass::FirstClass::Type(),BookingCategory::GeneralCategory::Type(),P1);
	
	
	//Check the equality operator
	std::cout << "**********************************************************" << std::endl;
	std::cout << "Check the equality operator:" << std::endl << std::endl;
	std::cout << "D==D where D is Booking D(....FirstClass::Instance()): " << (*D==*D) << std::endl;
	std::cout << "D==B1 where D is Booking D(....FirstClass::Instance()) and B1 is Booking B1(....ACFirstClass::Instance()): " << (*D==*B1) << std::endl;
	
	//Check the inequality operator
	std::cout << "**********************************************************" << std::endl;
	std::cout << "Check the inequality operator:" << std::endl << std::endl;
	std::cout << "D!=D where D is Booking D(....FirstClass::Instance()): " << (*D!=*D) << std::endl;
	std::cout << "D!=B1 where D is Booking D(....FirstClass::Instance()) and B1 is Booking B1(....ACFirstClass::Instance()): " << (*D!=*B1) << std::endl;
	
	//Check the insertion operator
	std::cout << "**********************************************************" << std::endl;
	std::cout << "Check the insertion operator:" << std::endl << std::endl;
	std::cout << "std::cout << D where D is Booking::GeneralBooking::createBooking(Station::createStation(\"Mumbai\"),Station::createStation(\"Chennai\"),\nDate::createDate(22,5,2021),BookingClass::FirstClass::Type(),BookingCategory::LadiesCategory::Type(),P1): " << std::endl << *D << std::endl;
	std::cout << "**********************************************************" << std::endl;

	
}


template<>
void Booking::LadiesBooking::UnitTestBooking()//To unit test class Booking
{
	std::cout << "STATIC UNIT TEST FUNCTION To unit test class Booking" << std::endl << std::endl;
	
	//Check the static constants
	std::cout << "**********************************************************" << std::endl;
	std::cout << "Check the static constants:" << std::endl << std::endl;
	std::cout << "Checking the sBareFarePerKM:" << sBareFarePerKM << std::endl << std::endl;
	if(sBareFarePerKM!=0.5)
	{
		std::cerr << "Error on Initialisation of sBareFarePerKM" << std::endl;
	}
	
	//Check the construction of a Booking Object
	std::cout << "**********************************************************" << std::endl;
	Passenger P1 = Passenger::createPassenger("Alexis","","Xavier",21,01,2001,Gender::Female::Type(),"987654321012","",Divyaang::Blind::Type(),"123" );
	Booking::LadiesBooking* B1 = Booking::LadiesBooking::createBooking(Station::createStation("Mumbai"),Station::createStation("Delhi"),Date::createDate(21,5,2021),BookingClass::ACFirstClass::Type(),BookingCategory::LadiesCategory::Type(),P1);
	std::cout << *B1 << std::endl;
	
	std::cout << "**********************************************************" << std::endl;
	Booking* B2=0;
	try
	{
		B2 = Booking::LadiesBooking::createBooking(Station::createStation("Mumbai"),Station::createStation("Delhi"),Date::createDate(21,3,2021),BookingClass::ACFirstClass::Type(),BookingCategory::LadiesCategory::Type(),P1);
	
	}
	catch(Bad_Booking& B)
	{
		std::cout << "Exception caught successfully upon trying to create an invalid Booking with past date." << std::endl << std::endl;
		std::cout << "Exception message: " << B.what() << std::endl << std::endl;
		if(B2!=0)
		{
			delete B2;
		}
	}
	
	std::cout << "**********************************************************" << std::endl;
	Booking* B3=0;
	try
	{
		B3 = Booking::LadiesBooking::createBooking(Station::createStation("Mumbai"),Station::createStation("Mumbai"),Date::createDate(21,5,2021),BookingClass::ACFirstClass::Type(),BookingCategory::LadiesCategory::Type(),P1);
	
	}
	catch(Bad_Booking& B)
	{
		std::cout << "Exception caught successfully upon trying to create an invalid Booking with having fromStation and toStation to be the same." << std::endl << std::endl;
		std::cout << "Exception message: " << B.what() << std::endl << std::endl;
		if(B3!=0)
		{
			delete B3;
		}
	}
	
	std::cout << "**********************************************************" << std::endl;
	
	std::cout << "Booking::LadiesBooking::createBooking(Station::createStation(\"Mumbai\"),Station::createStation(\"Delhi\"),\nDate::createDate(21,5,2021),BookingClass::ACFirstClass::Type(),BookingCategory::LadiesCategory::Type(),P1) booking instance has been constructed"  << std::endl;
	std::cout << std::endl;
	if(B1->fromStation!=Station::createStation("Mumbai"))
	{
		std::cerr << "Error in Constructor of Booking Class" << std::endl;
	}
	else 
	{
		std::cout << "B1->fromStation.GetName(): " << B1->fromStation.GetName() << std::endl;
	}
	
	if(B1->toStation!=Station::createStation("Delhi"))
	{
		std::cerr << "Error in Constructor of Booking Class" << std::endl;
	}
	else 
	{
		std::cout << "B1->toStation.GetName(): " << B1->toStation.GetName() << std::endl;
	}
	
	if(B1->dateOfBooking!=Date::createDate(21,5,2021))
	{
		std::cerr << "Error in Constructor of Booking Class" << std::endl;
	}
	else 
	{
		std::cout << "B1->dateOfBooking: " << B1->dateOfBooking << std::endl;
	}
	
	if(&(B1->bookingClass)!=&BookingClass::ACFirstClass::Type())
	{
		std::cerr << "Error in Constructor of Booking Class" << std::endl;
	}
	else
	{
		std::cout << "B1->bookingClass.GetName(): " << B1->bookingClass.GetName() << std::endl;
	}
	
	if(&(B1->bookingCategory)!=&BookingCategory::LadiesCategory::Type())
	{
		std::cerr << "Error in Constructor of Booking Class" << std::endl;
	}
	else
	{
		std::cout << "B1->bookingCategory.GetName(): " << B1->bookingCategory.GetName() << std::endl;
	}
	
	if(B1->fare != 4763)
	{
		std::cerr << "Error in Constructor of Booking Class" << std::endl;
	}
	else
	{
		std::cout << "B1->fare: " << B1->fare << std::endl;
	}
	
	if(B1->dateOfReservation!=Date::GetCurrentDate())
	{
		std::cerr << "Error in Constructor of Booking Class" << std::endl;
	}
	else 
	{
		std::cout << "B1->dateOfReservation: " << B1->dateOfReservation << std::endl;
	}
	
	
	//Checking the working of ComputeFare() Member Funciton
	if(B1->ComputeFare() != 4763)
	{
		std::cerr << "Error in ComputeFare() Member Funciton of Booking Class" << std::endl;
	}
	else
	{
		std::cout << "B1->ComputeFare(): " << B1->ComputeFare() << std::endl;
	}
	std::cout << std::endl;
	
	
	Booking::LadiesBooking* D = Booking::LadiesBooking::createBooking(Station::createStation("Mumbai"),Station::createStation("Chennai"),Date::createDate(22,5,2021),BookingClass::FirstClass::Type(),BookingCategory::LadiesCategory::Type(),P1);
	
	
	//Check the equality operator
	std::cout << "**********************************************************" << std::endl;
	std::cout << "Check the equality operator:" << std::endl << std::endl;
	std::cout << "D==D where D is Booking D(....FirstClass::Instance()): " << (*D==*D) << std::endl;
	std::cout << "D==B1 where D is Booking D(....FirstClass::Instance()) and B1 is Booking B1(....ACFirstClass::Instance()): " << (*D==*B1) << std::endl;
	
	//Check the inequality operator
	std::cout << "**********************************************************" << std::endl;
	std::cout << "Check the inequality operator:" << std::endl << std::endl;
	std::cout << "D!=D where D is Booking D(....FirstClass::Instance()): " << (*D!=*D) << std::endl;
	std::cout << "D!=B1 where D is Booking D(....FirstClass::Instance()) and B1 is Booking B1(....ACFirstClass::Instance()): " << (*D!=*B1) << std::endl;
	
	//Check the insertion operator
	std::cout << "**********************************************************" << std::endl;
	std::cout << "Check the insertion operator:" << std::endl << std::endl;
	std::cout << "std::cout << D where D is Booking::LadiesBooking::createBooking(Station::createStation(\"Mumbai\"),Station::createStation(\"Chennai\"),\nDate::createDate(22,5,2021),BookingClass::FirstClass::Type(),BookingCategory::LadiesCategory::Type(),P1): " << std::endl << *D << std::endl;
	std::cout << "**********************************************************" << std::endl;

	
}

template<>
void Booking::SeniorCitizenBooking::UnitTestBooking()//To unit test class Booking
{
	std::cout << "STATIC UNIT TEST FUNCTION To unit test class Booking" << std::endl << std::endl;
	
	//Check the static constants
	std::cout << "**********************************************************" << std::endl;
	std::cout << "Check the static constants:" << std::endl << std::endl;
	std::cout << "Checking the sBareFarePerKM:" << sBareFarePerKM << std::endl << std::endl;
	if(sBareFarePerKM!=0.5)
	{
		std::cerr << "Error on Initialisation of sBareFarePerKM" << std::endl;
	}
	
	//Check the construction of a Booking Object
	std::cout << "**********************************************************" << std::endl;
	Passenger P1 = Passenger::createPassenger("Alexis","","Xavier",21,01,1940,Gender::Female::Type(),"987654321012","",Divyaang::Blind::Type(),"123" );
	Booking::SeniorCitizenBooking* B1 = Booking::SeniorCitizenBooking::createBooking(Station::createStation("Mumbai"),Station::createStation("Delhi"),Date::createDate(21,5,2021),BookingClass::ACFirstClass::Type(),BookingCategory::SeniorCitizenCategory::Type(),P1);
	std::cout << *B1 << std::endl;
	
	std::cout << "**********************************************************" << std::endl;
	Booking* B2=0;
	try
	{
		B2 = Booking::SeniorCitizenBooking::createBooking(Station::createStation("Mumbai"),Station::createStation("Delhi"),Date::createDate(21,3,2021),BookingClass::ACFirstClass::Type(),BookingCategory::SeniorCitizenCategory::Type(),P1);
	
	}
	catch(Bad_Booking& B)
	{
		std::cout << "Exception caught successfully upon trying to create an invalid Booking  with past date." << std::endl << std::endl;
		std::cout << "Exception message: " << B.what() << std::endl << std::endl;
		if(B2!=0)
		{
			delete B2;
		}
	}
	
	std::cout << "**********************************************************" << std::endl;
	Booking* B3=0;
	try
	{
		B3 = Booking::SeniorCitizenBooking::createBooking(Station::createStation("Mumbai"),Station::createStation("Mumbai"),Date::createDate(21,5,2021),BookingClass::ACFirstClass::Type(),BookingCategory::SeniorCitizenCategory::Type(),P1);
	
	}
	catch(Bad_Booking& B)
	{
		std::cout << "Exception caught successfully upon trying to create an invalid Booking with having fromStation and toStation to be the same." << std::endl << std::endl;
		std::cout << "Exception message: " << B.what() << std::endl << std::endl;
		if(B3!=0)
		{
			delete B3;
		}
	}
	
	std::cout << "**********************************************************" << std::endl;
	
	std::cout << "Booking::SeniorCitizenBooking::createBooking(Station::createStation(\"Mumbai\"),Station::createStation(\"Delhi\"),\nDate::createDate(21,5,2021),BookingClass::ACFirstClass::Type(),BookingCategory::SeniorCitizenCategory::Type(),P1) booking instance has been constructed"  << std::endl;
	std::cout << std::endl;
	if(B1->fromStation!=Station::createStation("Mumbai"))
	{
		std::cerr << "Error in Constructor of Booking Class" << std::endl;
	}
	else 
	{
		std::cout << "B1->fromStation.GetName(): " << B1->fromStation.GetName() << std::endl;
	}
	
	if(B1->toStation!=Station::createStation("Delhi"))
	{
		std::cerr << "Error in Constructor of Booking Class" << std::endl;
	}
	else 
	{
		std::cout << "B1->toStation.GetName(): " << B1->toStation.GetName() << std::endl;
	}
	
	if(B1->dateOfBooking!=Date::createDate(21,5,2021))
	{
		std::cerr << "Error in Constructor of Booking Class" << std::endl;
	}
	else 
	{
		std::cout << "B1->dateOfBooking: " << B1->dateOfBooking << std::endl;
	}
	
	if(&(B1->bookingClass)!=&BookingClass::ACFirstClass::Type())
	{
		std::cerr << "Error in Constructor of Booking Class" << std::endl;
	}
	else
	{
		std::cout << "B1->bookingClass.GetName(): " << B1->bookingClass.GetName() << std::endl;
	}
	
	if(&(B1->bookingCategory)!=&BookingCategory::SeniorCitizenCategory::Type())
	{
		std::cerr << "Error in Constructor of Booking Class" << std::endl;
	}
	else
	{
		std::cout << "B1->bookingCategory.GetName(): " << B1->bookingCategory.GetName() << std::endl;
	}
	
	if(B1->fare !=2411)
	{
		std::cerr << "Error in Constructor of Booking Class" << std::endl;
	}
	else
	{
		std::cout << "B1->fare: " << B1->fare << std::endl;
	}
	
	if(B1->dateOfReservation!=Date::GetCurrentDate())
	{
		std::cerr << "Error in Constructor of Booking Class" << std::endl;
	}
	else 
	{
		std::cout << "B1->dateOfReservation: " << B1->dateOfReservation << std::endl;
	}
	
	
	//Checking the working of ComputeFare() Member Funciton
	if(B1->ComputeFare() != 2411)
	{
		std::cerr << "Error in ComputeFare() Member Funciton of Booking Class" << std::endl;
	}
	else
	{
		std::cout << "B1->ComputeFare(): " << B1->ComputeFare() << std::endl;
	}
	std::cout << std::endl;
	
	
	Booking::SeniorCitizenBooking* D = Booking::SeniorCitizenBooking::createBooking(Station::createStation("Mumbai"),Station::createStation("Chennai"),Date::createDate(22,5,2021),BookingClass::FirstClass::Type(),BookingCategory::SeniorCitizenCategory::Type(),P1);
	
	
	//Check the equality operator
	std::cout << "**********************************************************" << std::endl;
	std::cout << "Check the equality operator:" << std::endl << std::endl;
	std::cout << "D==D where D is Booking D(....FirstClass::Instance()): " << (*D==*D) << std::endl;
	std::cout << "D==B1 where D is Booking D(....FirstClass::Instance()) and B1 is Booking B1(....ACFirstClass::Instance()): " << (*D==*B1) << std::endl;
	
	//Check the inequality operator
	std::cout << "**********************************************************" << std::endl;
	std::cout << "Check the inequality operator:" << std::endl << std::endl;
	std::cout << "D!=D where D is Booking D(....FirstClass::Instance()): " << (*D!=*D) << std::endl;
	std::cout << "D!=B1 where D is Booking D(....FirstClass::Instance()) and B1 is Booking B1(....ACFirstClass::Instance()): " << (*D!=*B1) << std::endl;
	
	//Check the insertion operator
	std::cout << "**********************************************************" << std::endl;
	std::cout << "Check the insertion operator:" << std::endl << std::endl;
	std::cout << "std::cout << D where D is Booking::SeniorCitizenBooking::createBooking(Station::createStation(\"Mumbai\"),Station::createStation(\"Chennai\"),\nDate::createDate(22,5,2021),BookingClass::FirstClass::Type(),BookingCategory::SeniorCitizenCategory::Type(),P1): " << std::endl << *D << std::endl;
	std::cout << "**********************************************************" << std::endl;

	
}


template<>
void Booking::DivyaangBooking::UnitTestBooking()//To unit test class Booking
{
	std::cout << "STATIC UNIT TEST FUNCTION To unit test class Booking" << std::endl << std::endl;
	
	//Check the static constants
	std::cout << "**********************************************************" << std::endl;
	std::cout << "Check the static constants:" << std::endl << std::endl;
	std::cout << "Checking the sBareFarePerKM:" << sBareFarePerKM << std::endl << std::endl;
	if(sBareFarePerKM!=0.5)
	{
		std::cerr << "Error on Initialisation of sBareFarePerKM" << std::endl;
	}
	
	//Check the construction of a Booking Object
	std::cout << "**********************************************************" << std::endl;
	Passenger P1 = Passenger::createPassenger("Alexis","","Xavier",21,01,1940,Gender::Female::Type(),"987654321012","",Divyaang::Blind::Type(),"123" );
	Booking::DivyaangBooking* B1 = Booking::DivyaangBooking::createBooking(Station::createStation("Mumbai"),Station::createStation("Delhi"),Date::createDate(21,5,2021),BookingClass::ACFirstClass::Type(),BookingCategory::DivyaangCategory::Type(),P1);
	std::cout << *B1 << std::endl;
	
	std::cout << "**********************************************************" << std::endl;
	Booking* B2=0;
	try
	{
		B2 = Booking::DivyaangBooking::createBooking(Station::createStation("Mumbai"),Station::createStation("Delhi"),Date::createDate(21,3,2021),BookingClass::ACFirstClass::Type(),BookingCategory::DivyaangCategory::Type(),P1);
	
	}
	catch(Bad_Booking& B)
	{
		std::cout << "Exception caught successfully upon trying to create an invalid Booking with past date." << std::endl << std::endl;
		std::cout << "Exception message: " << B.what() << std::endl << std::endl;
		if(B2!=0)
		{
			delete B2;
		}
	}
	
	std::cout << "**********************************************************" << std::endl;
	Booking* B3=0;
	try
	{
		B3 = Booking::DivyaangBooking::createBooking(Station::createStation("Mumbai"),Station::createStation("Mumbai"),Date::createDate(21,5,2021),BookingClass::ACFirstClass::Type(),BookingCategory::DivyaangCategory::Type(),P1);
	
	}
	catch(Bad_Booking& B)
	{
		std::cout << "Exception caught successfully upon trying to create an invalid Booking with having fromStation and toStation to be the same." << std::endl << std::endl;
		std::cout << "Exception message: " << B.what() << std::endl << std::endl;
		if(B3!=0)
		{
			delete B3;
		}
	}
	
	std::cout << "**********************************************************" << std::endl;
	
	std::cout << "Booking::DivyaangBooking::createBooking(Station::createStation(\"Mumbai\"),Station::createStation(\"Delhi\"),\nDate::createDate(21,5,2021),BookingClass::ACFirstClass::Type(),BookingCategory::DivyaangCategory::Type(),P1) booking instance has been constructed"  << std::endl;
	std::cout << std::endl;
	if(B1->fromStation!=Station::createStation("Mumbai"))
	{
		std::cerr << "Error in Constructor of Booking Class" << std::endl;
	}
	else 
	{
		std::cout << "B1->fromStation.GetName(): " << B1->fromStation.GetName() << std::endl;
	}
	
	if(B1->toStation!=Station::createStation("Delhi"))
	{
		std::cerr << "Error in Constructor of Booking Class" << std::endl;
	}
	else 
	{
		std::cout << "B1->toStation.GetName(): " << B1->toStation.GetName() << std::endl;
	}
	
	if(B1->dateOfBooking!=Date::createDate(21,5,2021))
	{
		std::cerr << "Error in Constructor of Booking Class" << std::endl;
	}
	else 
	{
		std::cout << "B1->dateOfBooking: " << B1->dateOfBooking << std::endl;
	}
	
	if(&(B1->bookingClass)!=&BookingClass::ACFirstClass::Type())
	{
		std::cerr << "Error in Constructor of Booking Class" << std::endl;
	}
	else
	{
		std::cout << "B1->bookingClass.GetName(): " << B1->bookingClass.GetName() << std::endl;
	}
	
	if(&(B1->bookingCategory)!=&BookingCategory::DivyaangCategory::Type())
	{
		std::cerr << "Error in Constructor of Booking Class" << std::endl;
	}
	else
	{
		std::cout << "B1->bookingCategory.GetName(): " << B1->bookingCategory.GetName() << std::endl;
	}
	
	if(B1->fare !=2411)
	{
		std::cerr << "Error in Constructor of Booking Class" << std::endl;
	}
	else
	{
		std::cout << "B1->fare: " << B1->fare << std::endl;
	}
	
	if(B1->dateOfReservation!=Date::GetCurrentDate())
	{
		std::cerr << "Error in Constructor of Booking Class" << std::endl;
	}
	else 
	{
		std::cout << "B1->dateOfReservation: " << B1->dateOfReservation << std::endl;
	}
	
	
	//Checking the working of ComputeFare() Member Funciton
	if(B1->ComputeFare() != 2411)
	{
		std::cerr << "Error in ComputeFare() Member Funciton of Booking Class" << std::endl;
	}
	else
	{
		std::cout << "B1->ComputeFare(): " << B1->ComputeFare() << std::endl;
	}
	std::cout << std::endl;
	
	
	Booking::DivyaangBooking* D = Booking::DivyaangBooking::createBooking(Station::createStation("Mumbai"),Station::createStation("Chennai"),Date::createDate(22,5,2021),BookingClass::FirstClass::Type(),BookingCategory::DivyaangCategory::Type(),P1);
	
	
	//Check the equality operator
	std::cout << "**********************************************************" << std::endl;
	std::cout << "Check the equality operator:" << std::endl << std::endl;
	std::cout << "D==D where D is Booking D(....FirstClass::Instance()): " << (*D==*D) << std::endl;
	std::cout << "D==B1 where D is Booking D(....FirstClass::Instance()) and B1 is Booking B1(....ACFirstClass::Instance()): " << (*D==*B1) << std::endl;
	
	//Check the inequality operator
	std::cout << "**********************************************************" << std::endl;
	std::cout << "Check the inequality operator:" << std::endl << std::endl;
	std::cout << "D!=D where D is Booking D(....FirstClass::Instance()): " << (*D!=*D) << std::endl;
	std::cout << "D!=B1 where D is Booking D(....FirstClass::Instance()) and B1 is Booking B1(....ACFirstClass::Instance()): " << (*D!=*B1) << std::endl;
	
	//Check the insertion operator
	std::cout << "**********************************************************" << std::endl;
	std::cout << "Check the insertion operator:" << std::endl << std::endl;
	std::cout << "std::cout << D where D is Booking::DivyaangBooking::createBooking(Station::createStation(\"Mumbai\"),Station::createStation(\"Chennai\"),\nDate::createDate(22,5,2021),BookingClass::FirstClass::Type(),BookingCategory::DivyaangCategory::Type(),P1): " << std::endl << *D << std::endl;
	std::cout << "**********************************************************" << std::endl;

	
}


template<>
void Booking::TatkalBooking::UnitTestBooking()//To unit test class Booking
{
	std::cout << "STATIC UNIT TEST FUNCTION To unit test class Booking" << std::endl << std::endl;
	
	//Check the static constants
	std::cout << "**********************************************************" << std::endl;
	std::cout << "Check the static constants:" << std::endl << std::endl;
	std::cout << "Checking the sBareFarePerKM:" << sBareFarePerKM << std::endl << std::endl;
	if(sBareFarePerKM!=0.5)
	{
		std::cerr << "Error on Initialisation of sBareFarePerKM" << std::endl;
	}
	
	//Check the construction of a Booking Object
	std::cout << "**********************************************************" << std::endl;
	Passenger P1 = Passenger::createPassenger("Alexis","","Xavier",21,01,1940,Gender::Female::Type(),"987654321012","",Divyaang::Blind::Type(),"123" );
	Booking::TatkalBooking* B1 = Booking::TatkalBooking::createBooking(Station::createStation("Mumbai"),Station::createStation("Delhi"),Date::GetCurrentDate(),BookingClass::AC3Tier::Type(),BookingCategory::TatkalCategory::Type(),P1);
	std::cout << *B1 << std::endl;
	
	std::cout << "**********************************************************" << std::endl;
	Booking* B2=0;
	try
	{
		B2 = Booking::TatkalBooking::createBooking(Station::createStation("Mumbai"),Station::createStation("Delhi"),Date::createDate(21,3,2021),BookingClass::ACFirstClass::Type(),BookingCategory::TatkalCategory::Type(),P1);
	
	}
	catch(Bad_Booking& B)
	{
		std::cout << "Exception caught successfully upon trying to create an invalid Booking with past date." << std::endl << std::endl;
		std::cout << "Exception message: " << B.what() << std::endl << std::endl;
		if(B2!=0)
		{
			delete B2;
		}
	}
	
	std::cout << "**********************************************************" << std::endl;
	Booking* B3=0;
	try
	{
		B3 = Booking::TatkalBooking::createBooking(Station::createStation("Mumbai"),Station::createStation("Mumbai"),Date::GetCurrentDate(),BookingClass::ACFirstClass::Type(),BookingCategory::TatkalCategory::Type(),P1);
	
	}
	catch(Bad_Booking& B)
	{
		std::cout << "Exception caught successfully upon trying to create an invalid Booking with having fromStation and toStation to be the same." << std::endl << std::endl;
		std::cout << "Exception message: " << B.what() << std::endl << std::endl;
		if(B3!=0)
		{
			delete B3;
		}
	}
	
	std::cout << "**********************************************************" << std::endl;
	
	std::cout << "Booking::TatkalBooking::createBooking(Station::createStation(\"Mumbai\"),Station::createStation(\"Delhi\"),\nDate::GetCurrentDate(),BookingClass::AC3Tier::Type(),BookingCategory::TatkalCategory::Type(),P1) booking instance has been constructed"  << std::endl;
	std::cout << std::endl;
	if(B1->fromStation!=Station::createStation("Mumbai"))
	{
		std::cerr << "Error in Constructor of Booking Class" << std::endl;
	}
	else 
	{
		std::cout << "B1->fromStation.GetName(): " << B1->fromStation.GetName() << std::endl;
	}
	
	if(B1->toStation!=Station::createStation("Delhi"))
	{
		std::cerr << "Error in Constructor of Booking Class" << std::endl;
	}
	else 
	{
		std::cout << "B1->toStation.GetName(): " << B1->toStation.GetName() << std::endl;
	}
	
	if(B1->dateOfBooking!=Date::createDate(21,5,2021))
	{
		std::cerr << "Error in Constructor of Booking Class" << std::endl;
	}
	else 
	{
		std::cout << "B1->dateOfBooking: " << B1->dateOfBooking << std::endl;
	}
	
	if(&(B1->bookingClass)!=&BookingClass::ACFirstClass::Type())
	{
		std::cerr << "Error in Constructor of Booking Class" << std::endl;
	}
	else
	{
		std::cout << "B1->bookingClass.GetName(): " << B1->bookingClass.GetName() << std::endl;
	}
	
	if(&(B1->bookingCategory)!=&BookingCategory::TatkalCategory::Type())
	{
		std::cerr << "Error in Constructor of Booking Class" << std::endl;
	}
	else
	{
		std::cout << "B1->bookingCategory.GetName(): " << B1->bookingCategory.GetName() << std::endl;
	}
	
	if(B1->fare !=2249)
	{
		std::cerr << "Error in Constructor of Booking Class" << std::endl;
	}
	else
	{
		std::cout << "B1->fare: " << B1->fare << std::endl;
	}
	
	if(B1->dateOfReservation!=Date::GetCurrentDate())
	{
		std::cerr << "Error in Constructor of Booking Class" << std::endl;
	}
	else 
	{
		std::cout << "B1->dateOfReservation: " << B1->dateOfReservation << std::endl;
	}
	
	
	//Checking the working of ComputeFare() Member Funciton
	if(B1->ComputeFare() != 2249)
	{
		std::cerr << "Error in ComputeFare() Member Funciton of Booking Class" << std::endl;
	}
	else
	{
		std::cout << "B1->ComputeFare(): " << B1->ComputeFare() << std::endl;
	}
	std::cout << std::endl;
	
	
	Booking::TatkalBooking* D = Booking::TatkalBooking::createBooking(Station::createStation("Mumbai"),Station::createStation("Chennai"),Date::GetCurrentDate(),BookingClass::FirstClass::Type(),BookingCategory::TatkalCategory::Type(),P1);
	
	
	//Check the equality operator
	std::cout << "**********************************************************" << std::endl;
	std::cout << "Check the equality operator:" << std::endl << std::endl;
	std::cout << "D==D where D is Booking D(....FirstClass::Instance()): " << (*D==*D) << std::endl;
	std::cout << "D==B1 where D is Booking D(....FirstClass::Instance()) and B1 is Booking B1(....ACFirstClass::Instance()): " << (*D==*B1) << std::endl;
	
	//Check the inequality operator
	std::cout << "**********************************************************" << std::endl;
	std::cout << "Check the inequality operator:" << std::endl << std::endl;
	std::cout << "D!=D where D is Booking D(....FirstClass::Instance()): " << (*D!=*D) << std::endl;
	std::cout << "D!=B1 where D is Booking D(....FirstClass::Instance()) and B1 is Booking B1(....ACFirstClass::Instance()): " << (*D!=*B1) << std::endl;
	
	//Check the insertion operator
	std::cout << "**********************************************************" << std::endl;
	std::cout << "Check the insertion operator:" << std::endl << std::endl;
	std::cout << "std::cout << D where D is Booking::TatkalBooking::createBooking(Station::createStation(\"Mumbai\"),Station::createStation(\"Chennai\"),\nDate::createDate(22,5,2021),BookingClass::FirstClass::Type(),BookingCategory::TatkalCategory::Type(),P1): " << std::endl << *D << std::endl;
	std::cout << "**********************************************************" << std::endl;

	
}



template<>
void Booking::PremiumTatkalBooking::UnitTestBooking()//To unit test class Booking
{
	std::cout << "STATIC UNIT TEST FUNCTION To unit test class Booking" << std::endl << std::endl;
	
	//Check the static constants
	std::cout << "**********************************************************" << std::endl;
	std::cout << "Check the static constants:" << std::endl << std::endl;
	std::cout << "Checking the sBareFarePerKM:" << sBareFarePerKM << std::endl << std::endl;
	if(sBareFarePerKM!=0.5)
	{
		std::cerr << "Error on Initialisation of sBareFarePerKM" << std::endl;
	}
	
	//Check the construction of a Booking Object
	std::cout << "**********************************************************" << std::endl;
	Passenger P1 = Passenger::createPassenger("Alexis","","Xavier",21,01,1940,Gender::Female::Type(),"987654321012","",Divyaang::Blind::Type(),"123" );
	Booking::PremiumTatkalBooking* B1 = Booking::PremiumTatkalBooking::createBooking(Station::createStation("Mumbai"),Station::createStation("Delhi"),Date::GetCurrentDate(),BookingClass::AC3Tier::Type(),BookingCategory::PremiumTatkalCategory::Type(),P1);
	std::cout << *B1 << std::endl;
	
	std::cout << "**********************************************************" << std::endl;
	Booking* B2=0;
	try
	{
		B2 = Booking::PremiumTatkalBooking::createBooking(Station::createStation("Mumbai"),Station::createStation("Delhi"),Date::createDate(21,3,2021),BookingClass::ACFirstClass::Type(),BookingCategory::PremiumTatkalCategory::Type(),P1);
	
	}
	catch(Bad_Booking& B)
	{
		std::cout << "Exception caught successfully upon trying to create an invalid Booking with past date." << std::endl << std::endl;
		std::cout << "Exception message: " << B.what() << std::endl << std::endl;
		if(B2!=0)
		{
			delete B2;
		}
	}
	
	std::cout << "**********************************************************" << std::endl;
	Booking* B3=0;
	try
	{
		B3 = Booking::PremiumTatkalBooking::createBooking(Station::createStation("Mumbai"),Station::createStation("Mumbai"),Date::GetCurrentDate(),BookingClass::ACFirstClass::Type(),BookingCategory::PremiumTatkalCategory::Type(),P1);
	
	}
	catch(Bad_Booking& B)
	{
		std::cout << "Exception caught successfully upon trying to create an invalid Booking with having fromStation and toStation to be the same." << std::endl << std::endl;
		std::cout << "Exception message: " << B.what() << std::endl << std::endl;
		if(B3!=0)
		{
			delete B3;
		}
	}
	
	std::cout << "**********************************************************" << std::endl;
	
	std::cout << "Booking::PremiumTatkalBooking::createBooking(Station::createStation(\"Mumbai\"),Station::createStation(\"Delhi\"),\nDate::GetCurrentDate(),BookingClass::AC3Tier::Type(),BookingCategory::PremiumTatkalCategory::Type(),P1) booking instance has been constructed"  << std::endl;
	std::cout << std::endl;
	if(B1->fromStation!=Station::createStation("Mumbai"))
	{
		std::cerr << "Error in Constructor of Booking Class" << std::endl;
	}
	else 
	{
		std::cout << "B1->fromStation.GetName(): " << B1->fromStation.GetName() << std::endl;
	}
	
	if(B1->toStation!=Station::createStation("Delhi"))
	{
		std::cerr << "Error in Constructor of Booking Class" << std::endl;
	}
	else 
	{
		std::cout << "B1->toStation.GetName(): " << B1->toStation.GetName() << std::endl;
	}
	
	if(B1->dateOfBooking!=Date::createDate(21,5,2021))
	{
		std::cerr << "Error in Constructor of Booking Class" << std::endl;
	}
	else 
	{
		std::cout << "B1->dateOfBooking: " << B1->dateOfBooking << std::endl;
	}
	
	if(&(B1->bookingClass)!=&BookingClass::ACFirstClass::Type())
	{
		std::cerr << "Error in Constructor of Booking Class" << std::endl;
	}
	else
	{
		std::cout << "B1->bookingClass.GetName(): " << B1->bookingClass.GetName() << std::endl;
	}
	
	if(&(B1->bookingCategory)!=&BookingCategory::PremiumTatkalCategory::Type())
	{
		std::cerr << "Error in Constructor of Booking Class" << std::endl;
	}
	else
	{
		std::cout << "B1->bookingCategory.GetName(): " << B1->bookingCategory.GetName() << std::endl;
	}
	
	if(B1->fare !=2649)
	{
		std::cerr << "Error in Constructor of Booking Class" << std::endl;
	}
	else
	{
		std::cout << "B1->fare: " << B1->fare << std::endl;
	}
	
	if(B1->dateOfReservation!=Date::GetCurrentDate())
	{
		std::cerr << "Error in Constructor of Booking Class" << std::endl;
	}
	else 
	{
		std::cout << "B1->dateOfReservation: " << B1->dateOfReservation << std::endl;
	}
	
	
	//Checking the working of ComputeFare() Member Funciton
	if(B1->ComputeFare() != 2649)
	{
		std::cerr << "Error in ComputeFare() Member Funciton of Booking Class" << std::endl;
	}
	else
	{
		std::cout << "B1->ComputeFare(): " << B1->ComputeFare() << std::endl;
	}
	std::cout << std::endl;
	
	
	Booking::PremiumTatkalBooking* D = Booking::PremiumTatkalBooking::createBooking(Station::createStation("Mumbai"),Station::createStation("Chennai"),Date::GetCurrentDate(),BookingClass::FirstClass::Type(),BookingCategory::PremiumTatkalCategory::Type(),P1);
	
	
	//Check the equality operator
	std::cout << "**********************************************************" << std::endl;
	std::cout << "Check the equality operator:" << std::endl << std::endl;
	std::cout << "D==D where D is Booking D(....FirstClass::Instance()): " << (*D==*D) << std::endl;
	std::cout << "D==B1 where D is Booking D(....FirstClass::Instance()) and B1 is Booking B1(....ACFirstClass::Instance()): " << (*D==*B1) << std::endl;
	
	//Check the inequality operator
	std::cout << "**********************************************************" << std::endl;
	std::cout << "Check the inequality operator:" << std::endl << std::endl;
	std::cout << "D!=D where D is Booking D(....FirstClass::Instance()): " << (*D!=*D) << std::endl;
	std::cout << "D!=B1 where D is Booking D(....FirstClass::Instance()) and B1 is Booking B1(....ACFirstClass::Instance()): " << (*D!=*B1) << std::endl;
	
	//Check the insertion operator
	std::cout << "**********************************************************" << std::endl;
	std::cout << "Check the insertion operator:" << std::endl << std::endl;
	std::cout << "std::cout << D where D is Booking::PremiumTatkalBooking::createBooking(Station::createStation(\"Mumbai\"),Station::createStation(\"Chennai\"),\nDate::createDate(22,5,2021),BookingClass::FirstClass::Type(),BookingCategory::PremiumTatkalCategory::Type(),P1): " << std::endl << *D << std::endl;
	std::cout << "**********************************************************" << std::endl;

	
}




