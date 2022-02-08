/* ****************************************
*	Name: Hritaban Ghosh
*	Roll Number: 19CS30053
**************************************** */

#include "Date.h"
#include "Bad_Date.h"
#include <iostream>
#include <time.h>
#include <cstring>
#include <stdexcept>

//List of Month Names
const std::vector<std::string> Date::monthNames = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
//List of Day Names
const std::vector<std::string> Date::dayNames = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
//Maximum Valid Year
const int Date::MAX_VALID_YR = 2099; 
//Minimum Valid Year
const int Date::MIN_VALID_YR = 1900; 

//This is a utility function which returns true if the year entered as input is a leap year else false
bool Date::isLeap(int year) 
{ 
	// Return true if year  
	// is a multiple pf 4 and 
	// not multiple of 100. 
	// OR year is multiple of 400. 
	return (((year % 4 == 0) &&  (year % 100 != 0)) || (year % 400 == 0)); 
} 

//This is a utility function which returns true if the date is valid or not
bool Date::validate(UINT d, UINT m, UINT y)
{
	
	// If year, month and day  
    // are not in given range 
    if (y > Date::MAX_VALID_YR || y < Date::MIN_VALID_YR) 
		return false; 
    if (m < 1 || m > 12) 
		return false; 
    if (d < 1 || d > 31) 
		return false; 
  
    // Handle February month  
    // with leap year 
    if (m == 2) 
    { 
        if (isLeap(y)) 
			return (d <= 29); 
        else
			return (d <= 28); 
    } 
  
    // Months of April, June,  
    // Sept and Nov must have  
    // number of days less than 
    // or equal to 30. 
    if (m == 4 || m == 6 || m == 9 || m == 11) 
        return (d <= 30); 
  
    return true;
}

Date Date::GetCurrentDate()
{
	// current date/time based on current system
   time_t now = time(0);

   tm *ltm = localtime(&now);
   
   unsigned int y = 1900 + ltm->tm_year;
   unsigned int m = 1 + ltm->tm_mon;
   unsigned int d = ltm->tm_mday;
   
   return Date(d,m,y);
}

Date Date::createDate(UINT d, UINT m, UINT y)
{
	if(!Date::validate(d,m,y))
	{
		throw Bad_Date();
	}
	
	return Date (d,m,y);
}

//Constructor- takes three arguments as input
Date::Date(UINT d, UINT m, UINT y) : date_(d), month_(static_cast<Month>(m)), year_(y)
{
}

//Destructor
Date::~Date()
{
}

//This function prints out the date in dd/MMM/yyy format
void Date::print() const
{ 
	std::cout << date_ << "/" << Date::monthNames[month_ - 1] << "/" << year_ << std::endl; 
}

//Returns true if the date is valid else returns false
bool Date::validDate() const
{ 
	/* Check validity */ 
	UINT d = this->date_;
	UINT m = static_cast<UINT>(this->month_);
	UINT y = this->year_;
	
	// If year, month and day  
    // are not in given range 
    if (y > Date::MAX_VALID_YR || y < Date::MIN_VALID_YR) 
		return false; 
    if (m < 1 || m > 12) 
		return false; 
    if (d < 1 || d > 31) 
		return false; 
  
    // Handle February month  
    // with leap year 
    if (m == 2) 
    { 
        if (isLeap(y)) 
			return (d <= 29); 
        else
			return (d <= 28); 
    } 
  
    // Months of April, June,  
    // Sept and Nov must have  
    // number of days less than 
    // or equal to 30. 
    if (m == 4 || m == 6 || m == 9 || m == 11) 
        return (d <= 30); 
  
    return true;
}

//Returns the name of the day in the week corresponding to the date
std::string Date::day() const
{ 
	/* Compute day from date using time.h */ 
	struct tm current_date;
	memset((void *) &current_date, 0, sizeof(tm));
	current_date.tm_year = this->year_ - 1900;
	current_date.tm_mon = static_cast<UINT>(this->month_) - 1;
	current_date.tm_mday = this->date_;
	time_t t = mktime(&current_date);
	if (t != (time_t) - 1 && t >= 0)
	{
		return Date::dayNames[static_cast<Date::Day>(localtime(&t)->tm_wday)];
	}
	else
	{
		throw std::out_of_range("Not a Valid Date");
	}
}

// Returns the difference of years 
unsigned int Date:: DiffOfYears(const Date& D) const
{
	return abs(static_cast<int>(D.year_)-(static_cast<int>(this->year_)));
}

//The insertion operator is overloaded as a friend function and it prints out the date to the console in a dd/MMM/yyy format
std::ostream& operator<<(std::ostream& out, const Date& date)
{
	out << date.date_ << "/" << Date::monthNames[date.month_ - 1] << "/" << date.year_;
	return out;
}

//The equality operator is overloaded as a member function-Returns true if the dates are the same else false
bool Date::operator==(const Date& other) const
{
	if((*this).date_==other.date_ && (*this).month_==other.month_ && (*this).year_==other.year_)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//The inequality operator is overloaded as a member function-Returns true if the dates are different else false
bool Date::operator!=(const Date& other) const
{
	if((*this).date_!=other.date_ || (*this).month_!=other.month_ || (*this).year_!=other.year_)
	{
		return true;
	}
	else
	{
		return false;
	}
}


// Returns -1 if this date is before other date, 0 if they are same and +1 if this date is after other date
int Date::CompareDate(const Date& other) const{
	if(this->year_ > other.year_)
	{
		return 1;
	}
	else if(this->year_ == other.year_)
	{
		if(this->month_ > other.month_)
		{
			return 1;
		}
		else if(this->month_ == other.month_)
		{
			if(this->date_ > other.date_)
			{
				return 1;
			}
			else if(this->date_ == other.date_)
			{
				return 0;
			}
			else
			{
				return -1;
			}
		}
		else
		{
			return -1;
		}
	}
	else
	{
		return -1;
	}
}

// Returns true if the date is within one year from now else false
bool Date::isWithinOneYear(const Date& D) const
{
	if(static_cast<int>(this->year_)-static_cast<int>(D.year_) > 1 || static_cast<int>(this->year_)-static_cast<int>(D.year_) < 0)
	{
		return false;
	}
	else if(static_cast<int>(this->year_)-static_cast<int>(D.year_) == 1)
	{
		if(static_cast<int>(this->month_) > static_cast<int>(D.month_))
		{
			return false;
		}
		else if(static_cast<int>(this->month_) == static_cast<int>(D.month_))
		{
			if(static_cast<int>(this->date_) > static_cast<int>(D.date_))
			{
				return false;
			}
			else
			{
				return true;
			}
		}
		else
		{
			return true;
		}
	}
	else
	{
		if(static_cast<int>(this->month_) < static_cast<int>(D.month_))
		{
			return false;
		}
		else
		{
			if(static_cast<int>(this->date_) < static_cast<int>(D.date_))
			{
				return false;
			}
			else
			{
				return true;
			}
		}
		
	}
}

bool Date::isWithinOneDay(const Date& D) const
{
	if(static_cast<int>(this->year_)-static_cast<int>(D.year_) >= 1 || static_cast<int>(this->year_)-static_cast<int>(D.year_) < 0)
	{
		return false;
	}
	else
	{
		if(static_cast<int>(this->month_) > static_cast<int>(D.month_))
		{
			return false;
		}
		else if(this->month_ == D.month_)
		{
			if(static_cast<int>(this->date_) - static_cast<int>(D.date_) == 1 
			|| static_cast<int>(this->date_) - static_cast<int>(D.date_) == 0)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
}

//STATIC UNIT FUNCTION
void Date::UnitTestDate()// Test application for Date
{
	std::cout << "STATIC UNIT TEST FUNCTION To unit test class Date" << std::endl << std::endl;
	
	//Check the static constants
	std::cout << "**********************************************************" << std::endl;
	std::cout << "Check the static constants:" << std::endl << std::endl;
	std::cout << "Checking the list of month names:" << std::endl << std::endl;
	for(auto i{monthNames.begin()};i!=monthNames.end();i++)
	{
		std::cout << *i << "  " ;
	}
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "Checking the list of day names:" << std::endl << std::endl;
	for(auto i{dayNames.begin()};i!=dayNames.end();i++)
	{
		std::cout << *i << "  " ;
	}
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "Checking the maximum valid year: " << MAX_VALID_YR << std::endl << std::endl;
	if(MAX_VALID_YR!=2099)
	{
		std::cerr << "Error on Initialisation of MAX_VALID_YR" << std::endl;
	}
	std::cout << "Checking the minimum valid year: " << MIN_VALID_YR << std::endl << std::endl;
	if(MIN_VALID_YR!=1900)
	{
		std::cerr << "Error on Initialisation of MIN_VALID_YR" << std::endl;
	}
	
	//Check the construction of Date Objects
	Date D = createDate(2,3,2021);
	Date E = createDate(29,2,2020);
	if (D.date_ != 2)
	{
		std::cerr << "Error on Construction of Date(2,3,2021)" << std::endl;
	}
	if (D.month_ != 3)
	{
		std::cerr << "Error on Construction of Date(2,3,2021)" << std::endl;
	}
	if (D.year_ != 2021)
	{
		std::cerr << "Error on Construction of Date(2,3,2021)" << std::endl;
	}
	
	std::cout << "**********************************************************" << std::endl;
	try
	{
		Date F = createDate(31,4,2021);
	}
	catch (Bad_Date& B)
	{
		std::cout << "Exception caught successfully upon trying to create an invalid date" << std::endl << std::endl;
		std::cout << "Exception message: " << B.what() << std::endl << std::endl;
	}
	
	//Check the isLeap Utility Function
	std::cout << "**********************************************************" << std::endl;
	std::cout << "Check the isLeap Utility Function:" << std::endl << std::endl;
	std::cout << "2020 is a Leap Year or Not: " << isLeap(2020) << std::endl << std::endl;
	if(isLeap(2020)!=true)
	{
		std::cerr << "Error in Utility Function isLeap()" << std::endl;
	}
	std::cout << "2021 is a Leap Year or Not: " << isLeap(2021) << std::endl << std::endl;
	if(isLeap(2021)!=false)
	{
		std::cerr << "Error in Utility Function isLeap()" << std::endl;
	}
	
	//Check the validate Utility Function
	std::cout << "**********************************************************" << std::endl;
	std::cout << "Check the validate Utility Function:" << std::endl << std::endl;
	std::cout << "29 Feb 2020 is a valid date : " << validate(29,2,2020) << std::endl << std::endl;
	std::cout << "29 Feb 2021 is not a valid date : " << validate(29,2,2021) << std::endl << std::endl;
	std::cout << "31 Apr 2020 is not a valid date : " << validate(31,4,2021) << std::endl << std::endl;
	if(validate(29,2,2020)!=true)
	{
		std::cerr << "Error in Utility Function isLeap()" << std::endl;
	}
	if(validate(29,2,2021)!=false)
	{
		std::cerr << "Error in Utility Function isLeap()" << std::endl;
	}
	if(validate(31,4,2021)!=false)
	{
		std::cerr << "Error in Utility Function isLeap()" << std::endl;
	}
	
	//Check the print member function
	std::cout << "**********************************************************" << std::endl;
	std::cout << "Check the print member function:" << std::endl << std::endl;
	std::cout << "D.print() where D is Date(2,3,2021): ";
	D.print();
	
	//Check the validDate member function
	std::cout << "**********************************************************" << std::endl;
	std::cout << "Check the validDate member function:" << std::endl << std::endl;
	std::cout << "D.validDate() where D is Date(2,3,2021): " << D.validDate();
	if(D.validDate()!=true)
	{
		std::cerr << "Error in Function validDate()" << std::endl;
	}
	std::cout << std::endl;
	std::cout << "E.validDate() where E is DatE(29,2,2020): " << E.validDate();
	if(E.validDate()!=false)
	{
		std::cerr << "Error in Function validDate()" << std::endl;
	}
	std::cout << std::endl;
	
	//Check the day member function
	std::cout << "**********************************************************" << std::endl;
	std::cout << "Check the day member function:" << std::endl << std::endl;
	std::cout << "D.day() where D is Date(2,3,2021): " << D.day() << std::endl;
	if(D.day()!="Tuesday")
	{
		std::cerr << "Error in Function day()" << std::endl;
	}
	
	//Check the equality operator
	std::cout << "**********************************************************" << std::endl;
	std::cout << "Check the equality operator:" << std::endl << std::endl;
	std::cout << "D==D where D is Date(2,3,2021): " << (D==D) << std::endl;
	std::cout << "D==E where D is Date(2,3,2021) and E is E(29,2,2020): " << (D==E) << std::endl;
	
	//Check the inequality operator
	std::cout << "**********************************************************" << std::endl;
	std::cout << "Check the inequality operator:" << std::endl << std::endl;
	std::cout << "D!=D where D is Date(2,3,2021): " << (D!=D) << std::endl;
	std::cout << "D!=E where D is Date(2,3,2021) and E is E(29,2,2020): " << (D!=E) << std::endl;
	
	//Check the DiffOfYears Function
	std::cout << "**********************************************************" << std::endl;
	std::cout << "Check the DiffOfYears Function:" << std::endl << std::endl;
	std::cout << "Difference of years between dates D and E where D is Date(2,3,2021) and E is E(29,2,2020): " << D.DiffOfYears(E) << std::endl;
	std::cout << "Difference of years between date D where D is Date(2,3,2021) and (29,2,1900): " << D.DiffOfYears(createDate(30,01,1900)) << std::endl;
	if(D.DiffOfYears(E)!=1)
	{
		std::cerr << "Error in Function DiffOfYears()" << std::endl;
	}
	if(D.DiffOfYears(createDate(30,01,1900))!=121)
	{
		std::cerr << "Error in Function DiffOfYears()" << std::endl;
	}
	
	//Check the CompareDate Function
	std::cout << "**********************************************************" << std::endl;
	std::cout << "Check the CompareDate Function:" << std::endl << std::endl;
	std::cout << "Compare dates D where D is Date(2,3,2021) and D using D.CompareDate(D): " << D.CompareDate(D) << std::endl;
	std::cout << "Compare dates D and E where D is Date(2,3,2021) and E is E(29,2,2020) using E.CompareDate(D): " << E.CompareDate(D) << std::endl;
	std::cout << "Compare dates D and E where D is Date(2,3,2021) and E is E(29,2,2020) using D.CompareDate(E): " << D.CompareDate(E) << std::endl;
	std::cout << "Compare dates D where D is Date(2,3,2021) and (29,2,1900) using D.CompareDate(createDate(30,01,1900)): " << D.CompareDate(createDate(30,01,1900)) << std::endl;
	if(D.CompareDate(D)!=0)
	{
		std::cerr << "Error in Function CompareDate()" << std::endl;
	}
	if(E.CompareDate(D)!=-1)
	{
		std::cerr << "Error in Function CompareDate()" << std::endl;
	}
	if(D.CompareDate(E)!=1)
	{
		std::cerr << "Error in Function CompareDate()" << std::endl;
	}
	if(D.CompareDate(createDate(30,01,1900))!=1)
	{
		std::cerr << "Error in Function CompareDate()" << std::endl;
	}
	
	//Check the isWithinOneYear Function
	std::cout << "**********************************************************" << std::endl;
	std::cout << "Check the isWithinOneYear Function:" << std::endl << std::endl;
	std::cout << "Compare dates D where D is Date(2,3,2021) and D using D.isWithinOneYear(D): " << D.isWithinOneYear(D) << std::endl;
	std::cout << "Compare dates D and E where D is Date(2,3,2021) and E is E(29,2,2020) using E.isWithinOneYear(D): " << E.isWithinOneYear(D) << std::endl;
	std::cout << "Compare dates D and E where D is Date(2,3,2021) and E is E(29,2,2020) using D.isWithinOneYear(E): " << D.isWithinOneYear(E) << std::endl;
	std::cout << "Compare dates D where D is Date(2,3,2021) and (29,2,1900) using D.isWithinOneYear(createDate(30,01,1900)): " << D.isWithinOneYear(createDate(30,01,1900)) << std::endl;
	if(D.isWithinOneYear(D)!=true)
	{
		std::cerr << "Error in Function isWithinOneYear()" << std::endl;
	}
	if(E.isWithinOneYear(D)!=false)
	{
		std::cerr << "Error in Function isWithinOneYear()" << std::endl;
	}
	if(D.isWithinOneYear(E)!=false)
	{
		std::cerr << "Error in Function isWithinOneYear()" << std::endl;
	}
	if(D.isWithinOneYear(createDate(30,01,1900))!=false)
	{
		std::cerr << "Error in Function isWithinOneYear()" << std::endl;
	}
	
	//Check the isWithinOneDay Function
	std::cout << "**********************************************************" << std::endl;
	std::cout << "Check the isWithinOneDay Function:" << std::endl << std::endl;
	std::cout << "Compare dates D where D is Date(2,3,2021) and D using D.isWithinOneDay(D): " << D.isWithinOneDay(D) << std::endl;
	std::cout << "Compare dates D and E where D is Date(2,3,2021) and E is E(29,2,2020) using E.isWithinOneDay(D): " << E.isWithinOneDay(D) << std::endl;
	std::cout << "Compare dates D and E where D is Date(2,3,2021) and E is E(29,2,2020) using D.isWithinOneDay(E): " << D.isWithinOneDay(E) << std::endl;
	std::cout << "Compare dates D where D is Date(2,3,2021) and (29,2,1900) using D.isWithinOneDay(createDate(30,01,1900)): " << D.isWithinOneDay(createDate(30,01,1900)) << std::endl;
	if(D.isWithinOneDay(D)!=true)
	{
		std::cerr << "Error in Function isWithinOneDay()" << std::endl;
	}
	if(E.isWithinOneDay(D)!=false)
	{
		std::cerr << "Error in Function isWithinOneDay()" << std::endl;
	}
	if(D.isWithinOneDay(E)!=false)
	{
		std::cerr << "Error in Function isWithinOneDay()" << std::endl;
	}
	if(D.isWithinOneDay(createDate(30,01,1900))!=false)
	{
		std::cerr << "Error in Function isWithinOneDay()" << std::endl;
	}
	
	//Check the insertion operator
	std::cout << "**********************************************************" << std::endl;
	std::cout << "Check the insertion operator:" << std::endl << std::endl;
	std::cout << "std::cout << D where D is Date(2,3,2021): " << D << std::endl;
	std::cout << "**********************************************************" << std::endl;
}
