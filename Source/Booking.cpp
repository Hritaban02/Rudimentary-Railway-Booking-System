/* ****************************************
*	Name: Hritaban Ghosh
*	Roll Number: 19CS30053
**************************************** */

//Imports
#include "Booking.h"
#include "ACFirstClass.h"
#include "FirstClass.h"
#include "Railways.h"
#include "Station.h"
#include "Date.h"
#include "BookingClass.h"
#include "Passenger.h"
#include <iostream>
#include <string>
#include <cmath>

//Stores pointers to Bookings made in the Railway Booking System
std::vector<Booking*> Booking::sBookings = {};

//Stores the Bare Fare per Kilometer
const double Booking::sBareFarePerKM = 0.5;

//Stores the AC Surcharge
const double Booking::sACSurcharge = 50;

//Stores the Luxury Tax Percent
const double Booking::sLuxuryTaxPercent = 0.25;

//Stores the current PNR Serial starting from 1
int Booking::sBookingPNRSerial = 1;

//Constructor
Booking::Booking(Station fromStation_val, Station toStation_val, Date date_val, const BookingClass& bookingClass_val, Passenger* passenger_val)
 : fromStation{fromStation_val}, toStation{toStation_val}, date{date_val}, bookingClass{bookingClass_val}, fare{0}, PNR{Booking::sBookingPNRSerial++}, passenger{passenger_val}
{
	(*this).fare = (*this).ComputeFare();
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
	delete passenger;
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

//Computes the fare and stores it in data member fare
int Booking:: ComputeFare()
{
	double fare = 0;
	double distance = Railways::IndianRailways().GetDistance(Station(this->fromStation), Station(this->toStation));
	
	std::string bookingClassName = (this->bookingClass).GetName();
	
	double baseFare = distance*(Booking::sBareFarePerKM);
	
	double loadedFare = baseFare*((this->bookingClass).GetLoadFactor());
	fare += loadedFare;
	
	if((this->bookingClass).IsAC())
	{
		fare += Booking::sACSurcharge;
	}
	
	if((this->bookingClass).IsLuxury())
	{
		double luxuryTax = fare*(Booking::sLuxuryTaxPercent);
		fare += luxuryTax;
	}
	
	return std::round(fare);
}

//The insertion operator is overloaded as a friend function and prints out necessary details of the Booking
std::ostream& operator<<(std::ostream& out, const Booking& booking)
{
	out << std::endl;
	out << booking.bookingMessage << ":" << std::endl;
	out << "PNR Number : " << booking.PNR << std::endl;
	out << "From Station : " << booking.fromStation.GetName() << std::endl;
	out << "To Station : " << booking.toStation.GetName() << std::endl;
	out << "Travel Date : " << booking.date;
	out << "Travel Class : " << booking.bookingClass.GetName() << std::endl;
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
void Booking::UnitTestBooking()//To unit test class Booking
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
	std::cout << "Checking the sACSurcharge:" << sACSurcharge << std::endl << std::endl;
	if(sACSurcharge!=50)
	{
		std::cerr << "Error on Initialisation of sACSurcharge" << std::endl;
	}
	std::cout << "Checking the sLuxuryTaxPercent:" << sLuxuryTaxPercent << std::endl << std::endl;
	if(sLuxuryTaxPercent!=0.25)
	{
		std::cerr << "Error on Initialisation of sLuxuryTaxPercent" << std::endl;
	}
	
	//Check the construction of a Booking Object
	std::cout << "**********************************************************" << std::endl;
	Booking B(Station("Mumbai"),Station("Kolkata"),Date(2,3,2021),ACFirstClass::Instance());
	Booking D(Station("Mumbai"),Station("Chennai"),Date(2,3,2021),FirstClass::Instance());
	
	std::cout << "Booking B(Station(\"Mumbai\"),Station(\"Kolkata\"),Date(2,3,2021),ACFirstClass::Instance()) has been constructed" << std::endl; 
	
	if(B.fromStation!=Station("Mumbai"))
	{
		std::cerr << "Error in Constructor of Booking Class" << std::endl;
	}
	else 
	{
		std::cout << "B.fromStation.GetName(): " << B.fromStation.GetName() << std::endl;
	}
	
	if(B.toStation!=Station("Kolkata"))
	{
		std::cerr << "Error in Constructor of Booking Class" << std::endl;
	}
	else 
	{
		std::cout << "B.toStation.GetName(): " << B.toStation.GetName() << std::endl;
	}
	
	if(B.date!=Date(2,3,2021))
	{
		std::cerr << "Error in Constructor of Booking Class" << std::endl;
	}
	else 
	{
		std::cout << "B.date: " << B.date;
	}
	
	if(&(B.bookingClass)!=&ACFirstClass::Instance())
	{
		std::cerr << "Error in Constructor of Booking Class" << std::endl;
	}
	else
	{
		std::cout << "B.bookingClass.GetName(): " << B.bookingClass.GetName() << std::endl;
	}
	
	if(B.fare != 3839)
	{
		std::cerr << "Error in Constructor of Booking Class" << std::endl;
	}
	else
	{
		std::cout << "B.fare: " << B.fare << std::endl;
	}
	
	//Checking the working of ComputeFare() Member Funciton
	if(B.ComputeFare() != 3839)
	{
		std::cerr << "Error in ComputeFare() Member Funciton of Booking Class" << std::endl;
	}
	else
	{
		std::cout << "B.ComputeFare(): " << B.ComputeFare() << std::endl;
	}
	std::cout << std::endl;
	
	//Check the equality operator
	std::cout << "**********************************************************" << std::endl;
	std::cout << "Check the equality operator:" << std::endl << std::endl;
	std::cout << "D==D where D is Booking D(....FirstClass::Instance()): " << (D==D) << std::endl;
	std::cout << "D==B where D is Booking D(....FirstClass::Instance()) and B is Booking B(....ACFirstClass::Instance()): " << (D==B) << std::endl;
	
	//Check the inequality operator
	std::cout << "**********************************************************" << std::endl;
	std::cout << "Check the inequality operator:" << std::endl << std::endl;
	std::cout << "D!=D where D is Booking D(....FirstClass::Instance()): " << (D!=D) << std::endl;
	std::cout << "D!=B where D is Booking D(....FirstClass::Instance()) and B is Booking B(....ACFirstClass::Instance()): " << (D!=B) << std::endl;
	
	//Check the insertion operator
	std::cout << "**********************************************************" << std::endl;
	std::cout << "Check the insertion operator:" << std::endl << std::endl;
	std::cout << "std::cout << D where D is Booking D(Station(\"Mumbai\"),Station(\"Chennai\"),Date(2,3,2021),FirstClass::Instance()): " << D << std::endl;
	std::cout << "**********************************************************" << std::endl;

	
}
