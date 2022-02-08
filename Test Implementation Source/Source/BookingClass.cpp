/* ****************************************
*	Name: Hritaban Ghosh
*	Roll Number: 19CS30053
**************************************** */

#include "BookingClass.h"


//AC First Class

	template<>
	const double BookingClass::ACFirstClass::sLoadFactor = 6.50;//the Load Factor of the Booking Class
	template<>
	const std::string BookingClass::ACFirstClass::sName = "AC First Class";//the Name of the Booking Class
	template<>
	const bool BookingClass::ACFirstClass::sIsSitting = false;//true if the Booking Class has Seat else false 
	template<>
	const bool BookingClass::ACFirstClass::sIsAC = true;//true if the Booking Class has AC else false 
	template<>
	const int BookingClass::ACFirstClass::sNumberOfTiers = 2;//the Number Of Tiers of the Booking Class
	template<>
	const bool BookingClass::ACFirstClass::sIsLuxury = true;//true if the Booking Class is Luxury else false 
	template<>
	const double BookingClass::ACFirstClass::sReservationCharge = 60.0;//the Reservation Charge of the Booking Class
	template<>
	const double BookingClass::ACFirstClass::sMinimumTatkalCharges = 400.0;//the Minimum Tatkal Charges of the Booking Class
	template<>
	const double BookingClass::ACFirstClass::sMaximumTatkalCharges = 500.0;//the Maximum Tatkal Charges of the Booking Class
	template<>
	const double BookingClass::ACFirstClass::sMinimumTatkalDistance = 500;//the Minimum Tatkal Distance of the Booking Class
	template<>
	const double BookingClass::ACFirstClass::sTatkalLoadFactor = 0.3;//the Tatkal Load Factor of the Booking Class

//Executive Chair Car

	template<>
	const double BookingClass::ExecutiveChairCar::sLoadFactor = 5.00;//the Load Factor of the Booking Class
	template<>
	const std::string BookingClass::ExecutiveChairCar::sName = "Executive Chair Car";//the Name of the Booking Class
	template<>
	const bool BookingClass::ExecutiveChairCar::sIsSitting = true;//true if the Booking Class has Seat else false 
	template<>
	const bool BookingClass::ExecutiveChairCar::sIsAC = true;//true if the Booking Class has AC else false 
	template<>
	const int BookingClass::ExecutiveChairCar::sNumberOfTiers = 0;//the Number Of Tiers of the Booking Class
	template<>
	const bool BookingClass::ExecutiveChairCar::sIsLuxury = true;//true if the Booking Class is Luxury else false 
	template<>
	const double BookingClass::ExecutiveChairCar::sReservationCharge = 60.0;//the Reservation Charge of the Booking Class
	template<>
	const double BookingClass::ExecutiveChairCar::sMinimumTatkalCharges = 400.0;//the Minimum Tatkal Charges of the Booking Class
	template<>
	const double BookingClass::ExecutiveChairCar::sMaximumTatkalCharges = 500.0;//the Maximum Tatkal Charges of the Booking Class
	template<>
	const double BookingClass::ExecutiveChairCar::sMinimumTatkalDistance = 250;//the Minimum Tatkal Distance of the Booking Class
	template<>
	const double BookingClass::ExecutiveChairCar::sTatkalLoadFactor = 0.3;//the Tatkal Load Factor of the Booking Class
	
//AC 2 Tier

	template<>
	const double BookingClass::AC2Tier::sLoadFactor = 4.00;//the Load Factor of the Booking Class
	template<>
	const std::string BookingClass::AC2Tier::sName = "AC 2 Tier";//the Name of the Booking Class
	template<>
	const bool BookingClass::AC2Tier::sIsSitting = false;//true if the Booking Class has Seat else false 
	template<>
	const bool BookingClass::AC2Tier::sIsAC = true;//true if the Booking Class has AC else false 
	template<>
	const int BookingClass::AC2Tier::sNumberOfTiers = 2;//the Number Of Tiers of the Booking Class
	template<>
	const bool BookingClass::AC2Tier::sIsLuxury = false;//true if the Booking Class is Luxury else false 
	template<>
	const double BookingClass::AC2Tier::sReservationCharge = 50.0;//the Reservation Charge of the Booking Class
	template<>
	const double BookingClass::AC2Tier::sMinimumTatkalCharges = 400.0;//the Minimum Tatkal Charges of the Booking Class
	template<>
	const double BookingClass::AC2Tier::sMaximumTatkalCharges = 500.0;//the Maximum Tatkal Charges of the Booking Class
	template<>
	const double BookingClass::AC2Tier::sMinimumTatkalDistance = 500;//the Minimum Tatkal Distance of the Booking Class
	template<>
	const double BookingClass::AC2Tier::sTatkalLoadFactor = 0.3;//the Tatkal Load Factor of the Booking Class
	
//First Class

	template<>
	const double BookingClass::FirstClass::sLoadFactor = 3.00;//the Load Factor of the Booking Class
	template<>
	const std::string BookingClass::FirstClass::sName = "First Class";//the Name of the Booking Class
	template<>
	const bool BookingClass::FirstClass::sIsSitting = false;//true if the Booking Class has Seat else false 
	template<>
	const bool BookingClass::FirstClass::sIsAC = false;//true if the Booking Class has AC else false 
	template<>
	const int BookingClass::FirstClass::sNumberOfTiers = 2;//the Number Of Tiers of the Booking Class
	template<>
	const bool BookingClass::FirstClass::sIsLuxury = true;//true if the Booking Class is Luxury else false 
	template<>
	const double BookingClass::FirstClass::sReservationCharge = 50.0;//the Reservation Charge of the Booking Class
	template<>
	const double BookingClass::FirstClass::sMinimumTatkalCharges = 400.0;//the Minimum Tatkal Charges of the Booking Class
	template<>
	const double BookingClass::FirstClass::sMaximumTatkalCharges = 500.0;//the Maximum Tatkal Charges of the Booking Class
	template<>
	const double BookingClass::FirstClass::sMinimumTatkalDistance = 500;//the Minimum Tatkal Distance of the Booking Class
	template<>
	const double BookingClass::FirstClass::sTatkalLoadFactor = 0.3;//the Tatkal Load Factor of the Booking Class

//AC 3 Tier

	template<>
	const double BookingClass::AC3Tier::sLoadFactor = 2.50;//the Load Factor of the Booking Class
	template<>
	const std::string BookingClass::AC3Tier::sName = "AC 3 Tier";//the Name of the Booking Class
	template<>
	const bool BookingClass::AC3Tier::sIsSitting = false;//true if the Booking Class has Seat else false 
	template<>
	const bool BookingClass::AC3Tier::sIsAC = true;//true if the Booking Class has AC else false 
	template<>
	const int BookingClass::AC3Tier::sNumberOfTiers = 3;//the Number Of Tiers of the Booking Class
	template<>
	const bool BookingClass::AC3Tier::sIsLuxury = false;//true if the Booking Class is Luxury else false 
	template<>
	const double BookingClass::AC3Tier::sReservationCharge = 40.0;//the Reservation Charge of the Booking Class
	template<>
	const double BookingClass::AC3Tier::sMinimumTatkalCharges = 300.0;//the Minimum Tatkal Charges of the Booking Class
	template<>
	const double BookingClass::AC3Tier::sMaximumTatkalCharges = 400.0;//the Maximum Tatkal Charges of the Booking Class
	template<>
	const double BookingClass::AC3Tier::sMinimumTatkalDistance = 500;//the Minimum Tatkal Distance of the Booking Class
	template<>
	const double BookingClass::AC3Tier::sTatkalLoadFactor = 0.3;//the Tatkal Load Factor of the Booking Class

//AC Chair Car

	template<>
	const double BookingClass::ACChairCar::sLoadFactor = 2.00;//the Load Factor of the Booking Class
	template<>
	const std::string BookingClass::ACChairCar::sName = "AC Chair Car";//the Name of the Booking Class
	template<>
	const bool BookingClass::ACChairCar::sIsSitting = true;//true if the Booking Class has Seat else false 
	template<>
	const bool BookingClass::ACChairCar::sIsAC = true;//true if the Booking Class has AC else false 
	template<>
	const int BookingClass::ACChairCar::sNumberOfTiers = 0;//the Number Of Tiers of the Booking Class
	template<>
	const bool BookingClass::ACChairCar::sIsLuxury = false;//true if the Booking Class is Luxury else false 
	template<>
	const double BookingClass::ACChairCar::sReservationCharge = 40.0;//the Reservation Charge of the Booking Class
	template<>
	const double BookingClass::ACChairCar::sMinimumTatkalCharges = 125.0;//the Minimum Tatkal Charges of the Booking Class
	template<>
	const double BookingClass::ACChairCar::sMaximumTatkalCharges = 225.0;//the Maximum Tatkal Charges of the Booking Class
	template<>
	const double BookingClass::ACChairCar::sMinimumTatkalDistance = 250;//the Minimum Tatkal Distance of the Booking Class
	template<>
	const double BookingClass::ACChairCar::sTatkalLoadFactor = 0.3;//the Tatkal Load Factor of the Booking Class

//Sleeper

	template<>
	const double BookingClass::Sleeper::sLoadFactor = 1.00;//the Load Factor of the Booking Class
	template<>
	const std::string BookingClass::Sleeper::sName = "Sleeper";//the Name of the Booking Class
	template<>
	const bool BookingClass::Sleeper::sIsSitting = false;//true if the Booking Class has Seat else false 
	template<>
	const bool BookingClass::Sleeper::sIsAC = false;//true if the Booking Class has AC else false 
	template<>
	const int BookingClass::Sleeper::sNumberOfTiers = 3;//the Number Of Tiers of the Booking Class
	template<>
	const bool BookingClass::Sleeper::sIsLuxury = false;//true if the Booking Class is Luxury else false 
	template<>
	const double BookingClass::Sleeper::sReservationCharge = 20.0;//the Reservation Charge of the Booking Class
	template<>
	const double BookingClass::Sleeper::sMinimumTatkalCharges = 100.0;//the Minimum Tatkal Charges of the Booking Class
	template<>
	const double BookingClass::Sleeper::sMaximumTatkalCharges = 200.0;//the Maximum Tatkal Charges of the Booking Class
	template<>
	const double BookingClass::Sleeper::sMinimumTatkalDistance = 500;//the Minimum Tatkal Distance of the Booking Class	
	template<>
	const double BookingClass::Sleeper::sTatkalLoadFactor = 0.3;//the Tatkal Load Factor of the Booking Class
	
//Second Sitting

	template<>
	const double BookingClass::SecondSitting::sLoadFactor = 0.60;//the Load Factor of the Booking Class
	template<>
	const std::string BookingClass::SecondSitting::sName = "Second Sitting";//the Name of the Booking Class
	template<>
	const bool BookingClass::SecondSitting::sIsSitting = true;//true if the Booking Class has Seat else false 
	template<>
	const bool BookingClass::SecondSitting::sIsAC = false;//true if the Booking Class has AC else false 
	template<>
	const int BookingClass::SecondSitting::sNumberOfTiers = 0;//the Number Of Tiers of the Booking Class
	template<>
	const bool BookingClass::SecondSitting::sIsLuxury = false;//true if the Booking Class is Luxury else false 
	template<>
	const double BookingClass::SecondSitting::sReservationCharge = 15.0;//the Reservation Charge of the Booking Class
	template<>
	const double BookingClass::SecondSitting::sMinimumTatkalCharges = 10.0;//the Minimum Tatkal Charges of the Booking Class
	template<>
	const double BookingClass::SecondSitting::sMaximumTatkalCharges = 15.0;//the Maximum Tatkal Charges of the Booking Class
	template<>
	const double BookingClass::SecondSitting::sMinimumTatkalDistance = 100;//the Minimum Tatkal Distance of the Booking Class
	template<>
	const double BookingClass::SecondSitting::sTatkalLoadFactor = 0.1;//the Tatkal Load Factor of the Booking Class
	
//Constructor
BookingClass::BookingClass()
{
}

//Virtual Destructor
BookingClass::~BookingClass()
{
}


