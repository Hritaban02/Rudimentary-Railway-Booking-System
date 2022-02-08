/* ****************************************
*	Name: Hritaban Ghosh
*	Roll Number: 19CS30053
**************************************** */

#include "Date.h"
#include <iostream>
#include <time.h>
#include <cstring>
#include <stdexcept>

//List of Month Names
const std::vector<std::string> Date::monthNames = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
//List of Day Names
const std::vector<std::string> Date::dayNames = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
//Maximum Valid Year
const int Date::MAX_VALID_YR = 9999; 
//Minimum Valid Year
const int Date::MIN_VALID_YR = 1800; 

//This is a utility function which returns true if the year entered as input is a leap year else false
bool Date::isLeap(int year) 
{ 
	// Return true if year  
	// is a multiple pf 4 and 
	// not multiple of 100. 
	// OR year is multiple of 400. 
	return (((year % 4 == 0) &&  (year % 100 != 0)) || (year % 400 == 0)); 
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

//The insertion operator is overloaded as a friend function and it prints out the date to the console in a dd/MMM/yyy format
std::ostream& operator<<(std::ostream& out, const Date& date)
{
	out << date.date_ << "/" << Date::monthNames[date.month_ - 1] << "/" << date.year_ << std::endl;
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
	if(MAX_VALID_YR!=9999)
	{
		std::cerr << "Error on Initialisation of MAX_VALID_YR" << std::endl;
	}
	std::cout << "Checking the minimum valid year: " << MIN_VALID_YR << std::endl << std::endl;
	if(MIN_VALID_YR!=1800)
	{
		std::cerr << "Error on Initialisation of MIN_VALID_YR" << std::endl;
	}
	
	//Check the construction of Date Objects
	Date D(2,3,2021);
	Date E(29,2,2021);
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
	std::cout << "E.validDate() where E is Date(29,2,2021): " << E.validDate();
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
	std::cout << "D==E where D is Date(2,3,2021) and E is E(29,2,2021): " << (D==E) << std::endl;
	
	//Check the inequality operator
	std::cout << "**********************************************************" << std::endl;
	std::cout << "Check the inequality operator:" << std::endl << std::endl;
	std::cout << "D!=D where D is Date(2,3,2021): " << (D!=D) << std::endl;
	std::cout << "D!=E where D is Date(2,3,2021) and E is E(29,2,2021): " << (D!=E) << std::endl;
	
	//Check the insertion operator
	std::cout << "**********************************************************" << std::endl;
	std::cout << "Check the insertion operator:" << std::endl << std::endl;
	std::cout << "std::cout << D where D is Date(2,3,2021): " << D << std::endl;
	std::cout << "**********************************************************" << std::endl;
}
