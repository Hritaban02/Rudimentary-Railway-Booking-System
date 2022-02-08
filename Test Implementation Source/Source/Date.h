/* ****************************************
*	Name: Hritaban Ghosh
*	Roll Number: 19CS30053
**************************************** */

#ifndef __DATE_H__
#define __DATE_H__

#include <vector>
#include <string>



class Date 
{
	typedef unsigned int UINT;//Shortened form of unsigned int
	friend std::ostream& operator<<(std::ostream&, const Date&);//The insertion operator is overloaded as a friend function and it prints out the date to the console in a dd/MMM/yyy format
	
	private:
		static const std::vector<std::string> monthNames;//List of Month Names
		static const std::vector<std::string> dayNames;//List of Day Names
		static const int MAX_VALID_YR;//Maximum Valid Year
		static const int MIN_VALID_YR;//Minimum Valid Year
		
	private:
		static bool validate(UINT d, UINT m, UINT y);//This is a utility function which returns true if the date is valid or not
	
		static bool isLeap(int);//This is a utility function which returns true if the year entered as input is a leap year else false

	private:
		enum Month { Jan = 1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec };//Enumerated list of Months indexed starting from 1
		enum Day {Sun,  Mon, Tue, Wed, Thr, Fri, Sat};//Enumerated list of days of the week indexed starting from 0
		
		UINT date_;//Stores the date in unsigned int form 
		Month month_;//Stores the month using enum Month
		UINT year_;//Stores the year in unsigned int form
		
	private:
		Date(UINT d, UINT m, UINT y);//Constructor- takes three arguments as input
		
	public:
		static Date createDate(UINT d, UINT m, UINT y);
		~Date();//Destructor
		void print() const;//This function prints out the date in dd/MMM/yyy format
		bool validDate() const;//Returns true if the date is valid else returns false
		std::string day() const;//Returns the name of the day in the week corresponding to the date
		bool operator==(const Date&) const;//The equality operator is overloaded as a member function-Returns true if the dates are the same else false
		bool operator!=(const Date&) const;//The inequality operator is overloaded as a member function-Returns true if the dates are different else false
		unsigned int DiffOfYears(const Date&) const; // Returns the difference of years 
		int CompareDate(const Date&) const;// Returns -1 if this date is before other date, 0 if they are same and +1 if this date is after other date
		bool isWithinOneYear(const Date&) const;// Returns true if the date is within one year from D else false
		bool isWithinOneDay(const Date&) const;// Returns true if the date is within one day from D else false
		
		static Date GetCurrentDate();
		
	public:
		//STATIC UNIT FUNCTION
		static void UnitTestDate() ;// Test application for Date
};

#endif // __DATE_H__
