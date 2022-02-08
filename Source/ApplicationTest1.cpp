/* ****************************************
*	Name: Hritaban Ghosh
*	Roll Number: 19CS30053
**************************************** */

#ifndef __APPLICATIONTEST1_H__
#define __APPLICATIONTEST1_H__

//Imports
#include "Booking.h"
#include "Station.h"
#include "Date.h"
#include "BookingClass.h"
#include "ACFirstClass.h"
#include "AC2Tier.h"
#include "FirstClass.h"
#include "AC3Tier.h"
#include "ACChairCar.h"
#include "Sleeper.h"
#include "SecondSitting.h"
#include <iostream>
#include <vector>

// Test application for booking
void BookingApplication1() 
{
	std:: cout << "Application Test 1:" << std::endl;
	
	// Bookings by different booking classes
	// <BookingClasses>::Instance() returns the constant object of the respective type
	
	Booking b1(Station("Mumbai"), Station("Delhi"), Date(15, 2, 2021), ACFirstClass::Instance());
	Booking b2(Station("Kolkata"), Station("Delhi"), Date(5, 3, 2021), AC2Tier::Instance());
	Booking b3(Station("Mumbai"), Station("Kolkata"), Date(17, 3, 2021), FirstClass::Instance());
	Booking b4(Station("Mumbai"), Station("Delhi"), Date(23, 3, 2021), AC3Tier::Instance());
	Booking b5(Station("Chennai"), Station("Delhi"), Date(25, 4, 2021), ACChairCar::Instance());
	Booking b6(Station("Chennai"), Station("Kolkata"), Date(7, 5, 2021), Sleeper::Instance());
	Booking b7(Station("Mumbai"), Station("Delhi"), Date(19, 5, 2021), SecondSitting::Instance());
	Booking b8(Station("Delhi"), Station("Mumbai"), Date(22, 5, 2021), SecondSitting::Instance());
	
	// Output the bookings done where sBookings is the collection of bookings done
	std::vector<Booking*>::iterator it;
	for (it = Booking::sBookings.begin(); it < Booking::sBookings.end(); ++it) 
	{
		std::cout << *(*it);
	}
	return;
}

#endif // __APPLICATIONTEST1_H__
