/* ****************************************
*	Name: Hritaban Ghosh
*	Roll Number: 19CS30053
**************************************** */

#ifndef __PASSSENGER_H__
#define __PASSSENGER_H__

#include <string>
#include <iostream>
#include "Date.h"
#include "Name.h"
#include "Gender.h"
#include "Divyaang.h"



class Passenger
{
	friend std::ostream& operator<<(std::ostream&, const Passenger&);
	
	private:
		Name name;
		Date dateOfBirth;
		const Gender& gender;
		std::string aadhaarNumber;
		std::string mobileNumber="";
		const Divyaang* const disabilityType=0;
		const std::string disabilityID="";
		
		
	private:
		Passenger(Name&, Date&,  const Gender&, std::string&, std::string mobileNumber_val="", const Divyaang* const disabilityType_val=0, const std::string disabilityID_val="");
		
	public:
		static Passenger createPassenger(std::string, std::string, std::string,
			unsigned int, unsigned int, unsigned int,  const Gender&, std::string,
			std::string mobileNumber_val="",const Divyaang* const disabilityType_val=0, const std::string disabilityID_val="");
		Passenger(const Passenger&);
		virtual ~Passenger();
		
		static bool validateAadhaar(const std::string& aadhaarNumber);
		static bool validateMobile(const std::string& mobileNumber);
		
		const Name GetName() const;
		const Date GetDOB() const;
		const unsigned int GetAge() const;
		const Gender& GetGender() const;
		const std::string GetAadhaar() const;
		const std::string GetMobile() const;
		const Divyaang* const GetDisability() const;
		const std::string GetDisabilityID() const;
		
	public:
		//STATIC UNIT TEST FUNCTION
		static void UnitTestPassenger();// Test application for Passenger

};

#endif // __PASSSENGER_H__
