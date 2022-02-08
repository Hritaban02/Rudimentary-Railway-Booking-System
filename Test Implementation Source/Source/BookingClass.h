/* ****************************************
*	Name: Hritaban Ghosh
*	Roll Number: 19CS30053
**************************************** */

#ifndef __BOOKING_CLASS_H__
#define __BOOKING_CLASS_H__

#include <string>
#include <iostream>

template<typename T>
class BookingClassTypes; // Generic Booking Class Type to generate specific Booking Classes

class BookingClass//Abstract Base Class
{
	
	// Tag types - to instantiate the template
	// Note that these names are placeholders only and are not exposed outside the class
	// Also they are put inside the class for not cluttering the global namespace
	struct ACFirstClassType {};
	struct ExecutiveChairCarType {};
	struct AC2TierType {};
	struct FirstClassType {};
	struct AC3TierType {};
	struct ACChairCarType {};
	struct SleeperType {};
	struct SecondSittingType {};
	
protected:
		BookingClass();//Constructor
		virtual ~BookingClass();//Virtual Destructor
	
	public:
		
		virtual double GetLoadFactor() const = 0;//Returns the Load Factor of the Booking Class
		virtual std::string GetName() const = 0;//Returns the Name of the Booking Class
		virtual bool IsSitting() const = 0;//Returns true if the Booking Class has Seat else false 
		virtual bool IsAC() const = 0;//Returns true if the Booking Class has AC else false 
		virtual int GetNumberOfTiers() const = 0;//Returns the Number Of Tiers of the Booking Class
		virtual bool IsLuxury() const = 0;//Returns true if the Booking Class is Luxury else false 
		virtual double GetReservationCharge() const = 0;//Returns the Reservation Charge of the Booking Class
		virtual double GetMinimumTatkalCharges() const =0;//Returns the Minimum Tatkal Charges of the Booking Class
		virtual double GetMaximumTatkalCharges() const =0;//Returns the Maximum Tatkal Charges of the Booking Class
		virtual double GetMinimumTatkalDistance() const =0;//Returns the Minimum Tatkal Distance of the Booking Class
		virtual double GetTatkalLoadFactor() const =0;//Returns the Tatkal Load Factor of the Booking Class
		
		
		// Enumerated types - the target sub-types
		typedef BookingClassTypes<ACFirstClassType> ACFirstClass;
		typedef BookingClassTypes<ExecutiveChairCarType> ExecutiveChairCar;
		typedef BookingClassTypes<AC2TierType> AC2Tier;
		typedef BookingClassTypes<FirstClassType> FirstClass;
		typedef BookingClassTypes<AC3TierType> AC3Tier;
		typedef BookingClassTypes<ACChairCarType> ACChairCar;
		typedef BookingClassTypes<SleeperType> Sleeper;
		typedef BookingClassTypes<SecondSittingType> SecondSitting;
};

//Specific Booking Class Types
template<typename T>
class BookingClassTypes : public BookingClass
{
	static const double sLoadFactor;//the Load Factor of the Booking Class
	static const std::string sName;//the Name of the Booking Class
	static const bool sIsSitting;//true if the Booking Class has Seat else false 
	static const bool sIsAC;//true if the Booking Class has AC else false 
	static const int sNumberOfTiers;//the Number Of Tiers of the Booking Class
	static const bool sIsLuxury;//true if the Booking Class is Luxury else false 
	static const double sReservationCharge;//the Reservation Charge of the Booking Class
	static const double sMinimumTatkalCharges;//the Minimum Tatkal Charges of the Booking Class
	static const double sMaximumTatkalCharges;//the Maximum Tatkal Charges of the Booking Class
	static const double sMinimumTatkalDistance;//the Minimum Tatkal Distance of the Booking Class
	static const double sTatkalLoadFactor;//the Tatkal Load Factor of the Booking Class
	
	BookingClassTypes() {}
	~BookingClassTypes() {}
	public:
		// Singleton object - placeholder for the respective type
		static BookingClassTypes<T>& Type() 
		{
			static BookingClassTypes<T> theObject;
			return theObject;
		}
		
		//Returns the Load Factor
		double GetLoadFactor() const
		{
			return BookingClassTypes<T>::sLoadFactor;
		}

		//Returns the name of the Booking Class
		std::string GetName() const
		{
			return BookingClassTypes<T>::sName;
		}

		//Returns whether the Booking Class is AC or not
		bool IsAC() const
		{
			return BookingClassTypes<T>::sIsAC;
		}

		//Returns whether the Booking Class is Luxury or not
		bool IsLuxury() const
		{
			return BookingClassTypes<T>::sIsLuxury;
		}

		//Returns true as the class is with Berth
		bool IsSitting() const
		{
			return BookingClassTypes<T>::sIsSitting;
		}

		//Returns 2 as the class is with 2 Tiers 
		int GetNumberOfTiers() const
		{
			return BookingClassTypes<T>::sNumberOfTiers;
		}

		//Returns the Reservation Charge of the Booking Class
		double GetReservationCharge() const
		{
			return BookingClassTypes<T>::sReservationCharge;
		}

		//Returns the Minimum Tatkal Charges of the Booking Class
		double GetMinimumTatkalCharges() const
		{
			return BookingClassTypes<T>::sMinimumTatkalCharges;
		}

		//Returns the Maximum Tatkal Charges of the Booking Class
		double GetMaximumTatkalCharges() const
		{
			return BookingClassTypes<T>::sMaximumTatkalCharges;
		}

		//Returns the Minimum Tatkal Distance of the Booking Class
		double GetMinimumTatkalDistance() const
		{
			return BookingClassTypes<T>::sMinimumTatkalDistance;
		}

		//Returns the Tatkal Load Factor of the Booking Class
		double GetTatkalLoadFactor() const
		{
			return BookingClassTypes<T>::sTatkalLoadFactor;
		}
		
		
		static void UnitTestBookingClassTypes()
		{
			std::cout << "STATIC UNIT TEST FUNCTION To unit test class BookingClassTypes" << std::endl << std::endl;
	
		
			//Check whether the class is singleton or not
			std::cout << "**********************************************************" << std::endl;
			std::cout << "Check whether the class is singleton or not:" << std::endl <<std::endl;
			std::cout << "Address of BookingClassTypes<T> called the first time: " << &BookingClassTypes<T>::Type() << std::endl;
			std::cout << std::endl;
			std::cout << "Address of BookingClassTypes<T> called the second time: " << &BookingClassTypes<T>::Type() << std::endl;
			std::cout << std::endl;
			if(&BookingClassTypes<T>::Type() !=  &BookingClassTypes<T>::Type())
			{
				std::cerr << "Error: BookingClassTypes<T> is not a singleton class!!!" << std::endl;
			}
			else
			{
				std::cout << "BookingClassTypes<T> is a singleton class" << std::endl;
			}
		
			//Check the static data
			std::cout << "**********************************************************" << std::endl;
			std::cout << "Check the static data stored : " << std::endl <<std::endl;
			std::cout << std::endl;
			std::cout  << "sLoadFactor : " << BookingClassTypes<T>::sLoadFactor <<std::endl;
			std::cout  << "sName : " << BookingClassTypes<T>::sName <<std::endl;
			std::cout  << "sIsSitting : " << BookingClassTypes<T>::sIsSitting <<std::endl;
			std::cout  << "sIsAC : " << BookingClassTypes<T>::sIsAC <<std::endl;
			std::cout  << "sNumberOfTiers : " << BookingClassTypes<T>::sNumberOfTiers <<std::endl;
			std::cout  << "sIsLuxury : " << BookingClassTypes<T>::sIsLuxury <<std::endl;
			std::cout  << "sReservationCharge : " << BookingClassTypes<T>::sReservationCharge <<std::endl;
			std::cout  << "sMinimumTatkalCharges : " << BookingClassTypes<T>::sMinimumTatkalCharges <<std::endl;
			std::cout  << "sMaximumTatkalCharges : " << BookingClassTypes<T>::sMaximumTatkalCharges <<std::endl;
			std::cout  << "sMinimumTatkalDistance : " << BookingClassTypes<T>::sMinimumTatkalDistance <<std::endl;
			std::cout  << "sTatkalLoadFactor : " << BookingClassTypes<T>::sTatkalLoadFactor <<std::endl;
			std::cout << std::endl;
			
		
			
			//To test the GetLoadFactor() member Function
			if(BookingClassTypes<T>().GetLoadFactor()!=BookingClassTypes<T>::sLoadFactor)
			{
				std::cerr << "Error in GetLoadFactor() Member Function" << std::endl; 
			}
			
			//To test the GetName() member Function
			if(BookingClassTypes<T>().GetName()!=BookingClassTypes<T>::sName)
			{
				std::cerr << "Error in GetName() Member Function" << std::endl; 
			}
		
			
			
			//To test the IsSitting() member Function
			if(BookingClassTypes<T>().IsSitting()!=BookingClassTypes<T>::sIsSitting)
			{
				std::cerr << "Error in IsSitting() Member Function" << std::endl; 
			}
			
			
			//To test the IsAC() member Function
			if(BookingClassTypes<T>().IsAC()!=BookingClassTypes<T>::sIsAC)
			{
				std::cerr << "Error in IsAC() Member Function" << std::endl; 
			}
		
			
			//To test the GetNumberOfTiers() member Function
			if(BookingClassTypes<T>().GetNumberOfTiers()!=BookingClassTypes<T>::sNumberOfTiers)
			{
				std::cerr << "Error in GetNumberOfTiers() Member Function" << std::endl; 
			}
		
			
			
			//To test the IsLuxury() member Function
			if(BookingClassTypes<T>().IsLuxury()!=BookingClassTypes<T>::sIsLuxury)
			{
				std::cerr << "Error in IsLuxury() Member Function" << std::endl; 
			}
		
			
			
			//To test the GetReservationCharge() member Function
			if(BookingClassTypes<T>().GetReservationCharge()!=BookingClassTypes<T>::sReservationCharge)
			{
				std::cerr << "Error in GetReservationCharge() Member Function" << std::endl; 
			}
		

			//To test the GetMinimumTatkalCharges() member Function
			if(BookingClassTypes<T>().GetMinimumTatkalCharges()!=BookingClassTypes<T>::sMinimumTatkalCharges)
			{
				std::cerr << "Error in GetMinimumTatkalCharges() Member Function" << std::endl; 
			}
			
			//To test the GetMaximumTatkalCharges() member Function
			if(BookingClassTypes<T>().GetMaximumTatkalCharges()!=BookingClassTypes<T>::sMaximumTatkalCharges)
			{
				std::cerr << "Error in GetMaximumTatkalCharges() Member Function" << std::endl; 
			}
			
			//To test the GetMinimumTatkalDistance() member Function
			if(BookingClassTypes<T>().GetMinimumTatkalDistance()!=BookingClassTypes<T>::sMinimumTatkalDistance)
			{
				std::cerr << "Error in GetMinimumTatkalDistance() Member Function" << std::endl; 
			}
			
			//To test the GetTatkalLoadFactor() member Function
			if(BookingClassTypes<T>().GetTatkalLoadFactor()!=BookingClassTypes<T>::sTatkalLoadFactor)
			{
				std::cerr << "Error in GetTatkalLoadFactor() Member Function" << std::endl; 
			}
		
			std::cout << "**********************************************************" << std::endl;
		}

};

#endif // __BOOKING_CLASS_H__
