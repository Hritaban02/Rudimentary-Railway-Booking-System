#ifndef __BOOKINGCATEGORY_H__
#define __BOOKINGCATEGORY_H__

#include <iostream>
#include <string>
#include "Passenger.h"
#include "Station.h"
#include "Gender.h"
#include "Divyaang.h"

// Forward declaration of templatized class
template<typename T>
class BookingCategoryTypes; // Generic Booking Category type to generate specific Booking Categories

class BookingCategory
{
	
	// Abstract Base Class

private:
	std::string name_;//Name of the Booking Category
	
	// Tag types - to instantiate the template
	// Note that these names are placeholders only and are not exposed outside the class
	// Also they are put inside the class for not cluttering the global namespace
	struct GeneralType {};
	struct LadiesType {};
	struct SeniorCitizenType{};
	struct DivyaangType{};
	struct TatkalType{};
	struct PremiumTatkalType{};

protected:
	BookingCategory(const std::string&);
	virtual ~BookingCategory();
	
public:
	const std::string& GetName() const;
	virtual bool isEligiblefor(const Passenger&) const=0;
	
	// Enumerated types - the target sub-types
	typedef BookingCategoryTypes<GeneralType> GeneralCategory;
	typedef BookingCategoryTypes<LadiesType> LadiesCategory;
	typedef BookingCategoryTypes<SeniorCitizenType> SeniorCitizenCategory;
	typedef BookingCategoryTypes<DivyaangType> DivyaangCategory;
	typedef BookingCategoryTypes<TatkalType> TatkalCategory;
	typedef BookingCategoryTypes<PremiumTatkalType> PremiumTatkalCategory;

};



// Specific Booking Category types
template<typename T>
class BookingCategoryTypes : public BookingCategory
{
	static const std::string sName; // Respective name of the Booking Category
	
	BookingCategoryTypes(const std::string& name = BookingCategoryTypes<T>::sName) : BookingCategory(name) { }
	~BookingCategoryTypes() { }
	
	public:
		// Singleton object - placeholder for the respective type
		static BookingCategoryTypes<T>& Type() 
		{
			static BookingCategoryTypes<T> theObject; 
			return theObject;
		}
		bool isEligiblefor(const Passenger&) const;
		static bool isEligible(const Passenger&);
		
		static void UnitTestBookingCategory();
};

#endif // __BOOKINGCATEGORY_H__
