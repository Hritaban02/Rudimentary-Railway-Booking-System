#ifndef __DIVYAANG_H__
#define __DIVYAANG_H__

#include <iostream>
#include "BookingClass.h"
#include <string>
#include <map>

// Forward declaration of templatized class
template<typename T>
class DivyaangTypes; // Generic Divyaang type to generate specific disabilities

class Divyaang
{
	// Abstract Base Class
	
	// Tag types - to instantiate the template
	// Note that these names are placeholders only and are not exposed outside the class
	// Also they are put inside the class for not cluttering the global namespace
	struct BlindType {};
	struct OrthopaedicallyHandicappedType {};
	struct CancerPatientsType {};
	struct TBPatientsType {};
	
	protected:
		Divyaang();
		virtual ~Divyaang();
		
public:
		virtual std::string GetName() const=0;
		virtual const double GetConcession(const BookingClass&) const=0;
		// Enumerated types - the target sub-types
		typedef DivyaangTypes<BlindType> Blind;
		typedef DivyaangTypes<OrthopaedicallyHandicappedType> Orthopaedically_Handicapped;
		typedef DivyaangTypes<CancerPatientsType> Cancer_Patient;
		typedef DivyaangTypes<TBPatientsType> TB_Patient;

};


// Specific Divyaang types
template<typename T>
class DivyaangTypes : public Divyaang
{
	std::string name_;
	
	static std::string sName;
	static const std::map <std::string,double> ConcessionFactor;
	DivyaangTypes() : name_{DivyaangTypes<T>::sName} { }
	~DivyaangTypes() { }
	
	public:
		// Singleton object - placeholder for the respective type
		static DivyaangTypes<T>* Type() 
		{
			static DivyaangTypes<T> theObject;
			return &theObject;
		}
		std::string GetName() const
		{
			return name_;
		}
		const double GetConcession(const BookingClass& B) const 
		{
			return DivyaangTypes<T>::ConcessionFactor.at(B.GetName());
		}
		
		static void UnitTestDivyaang()
		{
			std::cout << "STATIC UNIT TEST FUNCTION To unit test class DivyaangTypes<T>" << std::endl << std::endl;
	
		
			//Check whether the class is singleton or not
			std::cout << "**********************************************************" << std::endl;
			std::cout << "Check whether the class is singleton or not:" << std::endl <<std::endl;
			std::cout << "Address of DivyaangTypes<T> called the first time: " << DivyaangTypes<T>::Type() << std::endl;
			std::cout << std::endl;
			std::cout << "Address of DivyaangTypes<T> called the second time: " << DivyaangTypes<T>::Type() << std::endl;
			std::cout << std::endl;
			if(DivyaangTypes<T>::Type() !=  DivyaangTypes<T>::Type())
			{
				std::cerr << "Error: DivyaangTypes<T> Class is not a singleton class!!!" << std::endl;
			}
			else
			{
				std::cout << "DivyaangTypes<T> Class is a singleton class" << std::endl;
			}
		
			//Check the static data
			std::cout << "**********************************************************" << std::endl;
			std::cout << "Check the static data stored : " << std::endl <<std::endl;
			std::cout << std::endl;
			std::cout << "Name Of the Disability: " << DivyaangTypes<T>::sName << std::endl;
			std::cout << std::endl;
			for(auto it=DivyaangTypes<T>::ConcessionFactor.begin();it!=(DivyaangTypes<T>::ConcessionFactor.end());it++)
			{
				std::cout << "Concession Factor for Booking Class " << it->first << " is " << it->second << std::endl;
			}
			std::cout << std::endl;
			
		
			
			//To test the GetName() member Function
			if(DivyaangTypes<T>().GetName()!=DivyaangTypes<T>::sName)
			{
				std::cerr << "Error in GetName() Member Function" << std::endl; 
			}
			
			//To test the GetConcession() member Function
			if(DivyaangTypes<T>().GetConcession(BookingClass::AC2Tier::Type())!=DivyaangTypes<T>::ConcessionFactor.at("AC 2 Tier"))
			{
				std::cerr << "Error in GetConcession() Member Function" << std::endl; 
			}
			if(DivyaangTypes<T>().GetConcession(BookingClass::AC3Tier::Type())!=DivyaangTypes<T>::ConcessionFactor.at("AC 3 Tier"))
			{
				std::cerr << "Error in GetConcession() Member Function" << std::endl; 
			}
			if(DivyaangTypes<T>().GetConcession(BookingClass::ACFirstClass::Type())!=DivyaangTypes<T>::ConcessionFactor.at("AC First Class"))
			{
				std::cerr << "Error in GetConcession() Member Function" << std::endl; 
			}
			if(DivyaangTypes<T>().GetConcession(BookingClass::FirstClass::Type())!=DivyaangTypes<T>::ConcessionFactor.at("First Class"))
			{
				std::cerr << "Error in GetConcession() Member Function" << std::endl; 
			}
			if(DivyaangTypes<T>().GetConcession(BookingClass::ExecutiveChairCar::Type())!=DivyaangTypes<T>::ConcessionFactor.at("Executive Chair Car"))
			{
				std::cerr << "Error in GetConcession() Member Function" << std::endl; 
			}
			if(DivyaangTypes<T>().GetConcession(BookingClass::ACChairCar::Type())!=DivyaangTypes<T>::ConcessionFactor.at("AC Chair Car"))
			{
				std::cerr << "Error in GetConcession() Member Function" << std::endl; 
			}
			if(DivyaangTypes<T>().GetConcession(BookingClass::Sleeper::Type())!=DivyaangTypes<T>::ConcessionFactor.at("Sleeper"))
			{
				std::cerr << "Error in GetConcession() Member Function" << std::endl; 
			}
			if(DivyaangTypes<T>().GetConcession(BookingClass::SecondSitting::Type())!=DivyaangTypes<T>::ConcessionFactor.at("Second Sitting"))
			{
				std::cerr << "Error in GetConcession() Member Function" << std::endl; 
			}
			
			std::cout << "**********************************************************" << std::endl;
		}
		

};

#endif // __DIVYAANG_H__
