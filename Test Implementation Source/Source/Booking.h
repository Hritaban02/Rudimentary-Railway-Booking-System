/* ****************************************
*	Name: Hritaban Ghosh
*	Roll Number: 19CS30053
**************************************** */

#ifndef __BOOKING_H__
#define __BOOKING_H__

#include <string>
#include <vector>
#include "Date.h"
#include "Station.h"
#include "BookingClass.h"
#include "BookingCategory.h"
#include "Passenger.h"
#include "Bad_Booking.h"

// Forward declaration of templatized class
template<typename T>
class BookingTypes; // Generic Booking type to generate specific Bookings

class Booking
{
	// Abstract Base Class
	
	// Tag types - to instantiate the template
	// Note that these names are placeholders only and are not exposed outside the class
	// Also they are put inside the class for not cluttering the global namespace
	struct GeneralType {};
	struct LadiesType {};
	struct SeniorCitizenType{};
	struct DivyaangType{};
	struct TatkalType{};
	struct PremiumTatkalType{};
	
	
	friend std::ostream& operator<<(std::ostream&, const Booking&);//The insertion operator is overloaded as a friend function and prints out necessary details of the Booking
	
	public:
		static std::vector<Booking*> sBookings;//Stores pointers to Bookings made in the Railway Booking System
	
	protected:
		static const double sBareFarePerKM;//Stores the Bare Fare per Kilometer
		static int sBookingPNRSerial;//Stores the current PNR Serial starting from 1
	
	protected:
		Station fromStation;//Stores the Station of Departure
		Station toStation;//Stores the Station of Arrival
		Date dateOfBooking;//Stores the Date of the Journey
		const BookingClass& bookingClass;//Stores the reference to the Booking Class
		const BookingCategory& bookingCategory;//Stores the reference to the Booking Category
		int fare;//Stores the fare required to pay for the ticket
		int PNR;//Stores the unique PNR Number of the ticket
		bool bookingStatus = true;//Stores the Booking Status
		std::string bookingMessage = "BOOKING SUCCEEDED";//Stores the Booking Message to be displayed when Booking is done
		const Passenger& passenger;//Stores Passenger Information
		Date dateOfReservation;//Stores the Date of Booking
		
	protected:
		Booking(Station, Station, Date, const BookingClass&, const BookingCategory&, const Passenger&);//Constructor
		
	public:
		virtual ~Booking();//Virtual Destructor
		bool operator==(const Booking&) const;//The equality operator is overloaded as a member function-Returns true if both have the same PNR number else false
		bool operator!=(const Booking& other) const;//The inequality operator is overloaded as a member function-Returns true if both have different PNR number else false
		
		// Enumerated types - the target sub-types
		typedef BookingTypes<GeneralType> GeneralBooking;
		typedef BookingTypes<LadiesType> LadiesBooking;
		typedef BookingTypes<SeniorCitizenType> SeniorCitizenBooking;
		typedef BookingTypes<DivyaangType> DivyaangBooking;
		typedef BookingTypes<TatkalType> TatkalBooking;
		typedef BookingTypes<PremiumTatkalType> PremiumTatkalBooking;

};

// Specific Booking types
template<typename T>
class BookingTypes : public Booking
{
	
		BookingTypes<T>(Station fromStation_val, Station toStation_val, Date dateOfBooking_val, const BookingClass& bookingClass_val, const BookingCategory& bookingCategory_val, const Passenger& passenger_val) 
		: Booking(fromStation_val,toStation_val, dateOfBooking_val, bookingClass_val, bookingCategory_val, passenger_val) 
		{ 
			(*this).fare = (*this).ComputeFare();
		}
	public:
		~BookingTypes() { }
		
		static BookingTypes<T>* createBooking(Station fromStation_val, Station toStation_val, Date dateOfBooking_val, const BookingClass& bookingClass_val, const BookingCategory& bookingCategory_val, const Passenger& passenger_val);
		
		virtual int ComputeFare() const;
		
		
		//STATIC UNIT TEST FUNCTION
		static void UnitTestBooking();//To unit test class Booking
};


#endif // __BOOKING_H__
