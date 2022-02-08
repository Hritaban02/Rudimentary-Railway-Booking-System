/* ****************************************
*	Name: Hritaban Ghosh
*	Roll Number: 19CS30053
**************************************** */

#ifndef __BOOKING_H__
#define __BOOKING_H__

#include <string>
#include <vector>
#include <cstdlib>
#include "Date.h"
#include "Station.h"
#include "BookingClass.h"
#include "Passenger.h"

class Booking
{
	friend std::ostream& operator<<(std::ostream&, const Booking&);//The insertion operator is overloaded as a friend function and prints out necessary details of the Booking
	
	public:
		static std::vector<Booking*> sBookings;//Stores pointers to Bookings made in the Railway Booking System
	
	private:
		static const double sBareFarePerKM;//Stores the Bare Fare per Kilometer
		static const double sACSurcharge;//Stores the AC Surcharge
		static const double sLuxuryTaxPercent;//Stores the Luxury Tax Percent
		static int sBookingPNRSerial;//Stores the current PNR Serial starting from 1
	
	private:
		Station fromStation;//Stores the Station of Departure
		Station toStation;//Stores the Station of Arrival
		Date date;//Stores the Date of the Journey
		const BookingClass& bookingClass;//Stores the reference to the Booking Class
		int fare;//Stores the fare required to pay for the ticket
		int PNR;//Stores the unique PNR Number of the ticket
		bool bookingStatus = true;//Stores the Booking Status
		std::string bookingMessage = "BOOKING SUCCEEDED";//Stores the Booking Message to be displayed when Booking is done
		Passenger* passenger;//Stores Passenger Information
		
	public:
		Booking(Station, Station, Date, const BookingClass&, Passenger* passenger_val=NULL);//Constructor
		virtual ~Booking();//Virtual Destructor
		virtual int ComputeFare();//Computes the fare and returns it
		bool operator==(const Booking&) const;//The equality operator is overloaded as a member function-Returns true if both have the same PNR number else false
		bool operator!=(const Booking& other) const;//The inequality operator is overloaded as a member function-Returns true if both have different PNR number else false

	public:
		//STATIC UNIT TEST FUNCTION
		static void UnitTestBooking();//To unit test class Booking
};

#endif // __BOOKING_H__
