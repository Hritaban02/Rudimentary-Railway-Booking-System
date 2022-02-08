/* ****************************************
*	Name: Hritaban Ghosh
*	Roll Number: 19CS30053
**************************************** */

//Imports
#include "Passenger.h"
#include "Bad_Passenger.h"
#include "Bad_Name.h"
#include "Bad_Date.h"
#include "Bad_Mobile.h"
#include "Bad_Aadhaar.h"
#include "Date.h"
#include "Name.h"
#include <cstring>
#include <ctime>

bool Passenger::validateAadhaar(const std::string& aadhaarNumber)
{
	if(aadhaarNumber.size()!=12)
	{
		return false;
	}
	for (size_t i=0; i<aadhaarNumber.size(); i++)
    {
        if (!isdigit(aadhaarNumber[i]))
		{
			return false;
		}
    }
	return true;
}

bool Passenger::validateMobile(const std::string& mobileNumber)
{
	if(mobileNumber.size()==0)
	{
		return true;
	}
	
	
	if(mobileNumber.size()!=10)
	{
		return false;
	}
	for (size_t i=0; i<mobileNumber.size(); i++)
    {
        if (!isdigit(mobileNumber[i]))
		{
			return false;
		}
    }
	return true;
}

Passenger Passenger::createPassenger(std::string firstName_val, std::string middleName_val, std::string lastName_val, 
unsigned int date_val, unsigned int month_val, unsigned int year_val, const Gender& gender_val, std::string aadhaarNumber_val,
std::string mobileNumber_val,const Divyaang* const disabilityType_val, const std::string disabilityID_val)
{
	Name name_val=Name::createName(firstName_val,middleName_val,lastName_val);
	Date dateOfBirth_val=Date::createDate(date_val,month_val,year_val);
	
	if(!validateAadhaar(aadhaarNumber_val) || !validateMobile(mobileNumber_val) || dateOfBirth_val.CompareDate(Date::GetCurrentDate())==1)
	{
		throw Bad_Passenger();
	}
	
	return Passenger(name_val, dateOfBirth_val, gender_val,aadhaarNumber_val, mobileNumber_val, disabilityType_val, disabilityID_val);
}

//Constructor
Passenger::Passenger(Name& name_val, Date& dateOfBirth_val, const Gender& gender_val, 
std::string& aadhaarNumber_val, std::string mobileNumber_val, const Divyaang* const disabilityType_val, 
const std::string disabilityID_val) 
: name{name_val}, dateOfBirth{dateOfBirth_val}, 
gender{gender_val}, aadhaarNumber{aadhaarNumber_val}, mobileNumber{mobileNumber_val}, disabilityType{disabilityType_val},
disabilityID{disabilityID_val}
{
}

//Copy Constructor for constructing a new object from a existing one
Passenger::Passenger(const Passenger& other) : name{other.name}, dateOfBirth{other.dateOfBirth}, 
gender{other.gender}, aadhaarNumber{other.aadhaarNumber}, mobileNumber{other.mobileNumber}
{
}


//Destructor
Passenger::~Passenger()
{
}

const Name Passenger::GetName() const
{
	return this->name;
}

const Date Passenger::GetDOB() const
{
	return this->dateOfBirth;
}

const unsigned int Passenger::GetAge() const
{
	Date currentDate = Date::GetCurrentDate();
   
   return (this->dateOfBirth).DiffOfYears(currentDate);
}

const Gender& Passenger::GetGender() const
{
	return this->gender;
}

const std::string Passenger::GetAadhaar() const
{
	return this->aadhaarNumber;
}

const std::string Passenger::GetMobile() const
{
	return this->mobileNumber;
}

const Divyaang* const Passenger::GetDisability() const
{
	return (this->disabilityType);
}

const std::string Passenger::GetDisabilityID() const
{
	return this->disabilityID;
}

std::ostream& operator<<(std::ostream& out , const Passenger& P)
{
	out << std::endl;
	out << "Name : " << P.GetName() << std::endl;
	out << "Date Of Birth : " << P.GetDOB() << std::endl;
	out << "Gender : " << P.GetGender().GetName() << std::endl;
	out << "Aadhar Number : " << P.GetAadhaar() << std::endl;
	if(P.GetMobile()!="")
	{
		out << "Mobile Number : " << P.GetMobile() << std::endl;
	}
	if(P.GetDisability() != 0)
	{
		out << "Disability Type : " << (*(P.GetDisability())).GetName()<< std::endl;
		out << "Disability ID : " << P.GetDisabilityID()<< std::endl;
	}
	
	return out;
}

//STATIC UNIT TEST FUNCTION
void Passenger::UnitTestPassenger()
{
	std::cout << "STATIC UNIT TEST FUNCTION Test application for Passenger " << std::endl << std::endl;
	//To unit test class Passenger
	
	
	
	//To test the construction of objects
	Passenger P1 = Passenger::createPassenger("Mike","Charles","Xavier",21,01,2001,Gender::Male::Type(),"987654321012","1234567890",Divyaang::Blind::Type(),"123" );
	if(P1.name.GetFirstName() != "Mike")
	{
		std::cerr << "Error Passenger Construction : First Name not correct" << std::endl; 
	}
	if(P1.name.GetMiddleName() != "Charles")
	{
		std::cerr << "Error Passenger Construction : Middle Name not correct" << std::endl; 
	}
	if(P1.name.GetLastName() != "Xavier")
	{
		std::cerr << "Error Passenger Construction : Last Name not correct" << std::endl; 
	}
	if(P1.dateOfBirth != Date::createDate(21,01,2001))
	{
		std::cerr << "Error Passenger Construction : DOB is not correct" << std::endl; 
	}
	if(&P1.gender != &Gender::Male::Type())
	{
		std::cerr << "Error Passenger Construction : Gender is not correct" << std::endl; 
	}
	if(P1.aadhaarNumber != "987654321012")
	{
		std::cerr << "Error Passenger Construction : aadhaar Number is not correct" << std::endl; 
	}
	if(P1.mobileNumber != "1234567890")
	{
		std::cerr << "Error Passenger Construction : mobile Number is not correct" << std::endl; 
	}
	if(P1.disabilityType != Divyaang::Blind::Type())
	{
		std::cerr << "Error Passenger Construction : disability Type is not correct" << std::endl; 
	}
	if(P1.disabilityID != "123")
	{
		std::cerr << "Error Passenger Construction : disability ID is not correct" << std::endl; 
	}
	
	//Bad_Name
	std::cout << "**********************************************************" << std::endl;
	try
	{
		Passenger P1 = Passenger::createPassenger("","Charles","",21,01,2001,Gender::Male::Type(),"987654321012","1234567890",Divyaang::Blind::Type(),"123" );
	
	}
	catch (Bad_Name& B)
	{
		std::cout << "Exception caught successfully upon trying to create an invalid Passenger" << std::endl << std::endl;
		std::cout << "Exception message: " << B.what() << std::endl << std::endl;
	}
	catch (Bad_Date& B)
	{
		std::cout << "Exception caught successfully upon trying to create an invalid Passenger" << std::endl << std::endl;
		std::cout << "Exception message: " << B.what() << std::endl << std::endl;
	}
	catch (Bad_Aadhaar& B)
	{
		std::cout << "Exception caught successfully upon trying to create an invalid Passenger" << std::endl << std::endl;
		std::cout << "Exception message: " << B.what() << std::endl << std::endl;
	}
	catch (Bad_Mobile& B)
	{
		std::cout << "Exception caught successfully upon trying to create an invalid Passenger" << std::endl << std::endl;
		std::cout << "Exception message: " << B.what() << std::endl << std::endl;
	}
	catch (Bad_Passenger& B)
	{
		std::cout << "Exception caught successfully upon trying to create an invalid Passenger" << std::endl << std::endl;
		std::cout << "Exception message: " << B.what() << std::endl << std::endl;
	}
	
	//Bad_Date
	std::cout << "**********************************************************" << std::endl;
	try
	{
		Passenger P1 = Passenger::createPassenger("Mike","","Xavier",29,02,2001,Gender::Male::Type(),"987321012","",Divyaang::Blind::Type(),"123" );
	
	}
	catch (Bad_Name& B)
	{
		std::cout << "Exception caught successfully upon trying to create an invalid Passenger" << std::endl << std::endl;
		std::cout << "Exception message: " << B.what() << std::endl << std::endl;
	}
	catch (Bad_Date& B)
	{
		std::cout << "Exception caught successfully upon trying to create an invalid Passenger" << std::endl << std::endl;
		std::cout << "Exception message: " << B.what() << std::endl << std::endl;
	}
	catch (Bad_Aadhaar& B)
	{
		std::cout << "Exception caught successfully upon trying to create an invalid Passenger" << std::endl << std::endl;
		std::cout << "Exception message: " << B.what() << std::endl << std::endl;
	}
	catch (Bad_Mobile& B)
	{
		std::cout << "Exception caught successfully upon trying to create an invalid Passenger" << std::endl << std::endl;
		std::cout << "Exception message: " << B.what() << std::endl << std::endl;
	}
	catch (Bad_Passenger& B)
	{
		std::cout << "Exception caught successfully upon trying to create an invalid Passenger" << std::endl << std::endl;
		std::cout << "Exception message: " << B.what() << std::endl << std::endl;
	}
	
	//Bad_Aadhaar
	std::cout << "**********************************************************" << std::endl;
	try
	{
		Passenger P1 = Passenger::createPassenger("Mike","Charles","Xavier",21,01,2001,Gender::Male::Type(),"9876012","1234567890",Divyaang::Blind::Type(),"123" );
	
	}
	catch (Bad_Name& B)
	{
		std::cout << "Exception caught successfully upon trying to create an invalid Passenger" << std::endl << std::endl;
		std::cout << "Exception message: " << B.what() << std::endl << std::endl;
	}
	catch (Bad_Date& B)
	{
		std::cout << "Exception caught successfully upon trying to create an invalid Passenger" << std::endl << std::endl;
		std::cout << "Exception message: " << B.what() << std::endl << std::endl;
	}
	catch (Bad_Aadhaar& B)
	{
		std::cout << "Exception caught successfully upon trying to create an invalid Passenger" << std::endl << std::endl;
		std::cout << "Exception message: " << B.what() << std::endl << std::endl;
	}
	catch (Bad_Mobile& B)
	{
		std::cout << "Exception caught successfully upon trying to create an invalid Passenger" << std::endl << std::endl;
		std::cout << "Exception message: " << B.what() << std::endl << std::endl;
	}
	catch (Bad_Passenger& B)
	{
		std::cout << "Exception caught successfully upon trying to create an invalid Passenger" << std::endl << std::endl;
		std::cout << "Exception message: " << B.what() << std::endl << std::endl;
	}
	
	//Bad_Mobile
	std::cout << "**********************************************************" << std::endl;
	try
	{
		Passenger P1 = Passenger::createPassenger("Mike","Charles","Xavier",21,01,2001,Gender::Male::Type(),"987654321012","1234890");
	
	}
	catch (Bad_Name& B)
	{
		std::cout << "Exception caught successfully upon trying to create an invalid Passenger" << std::endl << std::endl;
		std::cout << "Exception message: " << B.what() << std::endl << std::endl;
	}
	catch (Bad_Date& B)
	{
		std::cout << "Exception caught successfully upon trying to create an invalid Passenger" << std::endl << std::endl;
		std::cout << "Exception message: " << B.what() << std::endl << std::endl;
	}
	catch (Bad_Aadhaar& B)
	{
		std::cout << "Exception caught successfully upon trying to create an invalid Passenger" << std::endl << std::endl;
		std::cout << "Exception message: " << B.what() << std::endl << std::endl;
	}
	catch (Bad_Mobile& B)
	{
		std::cout << "Exception caught successfully upon trying to create an invalid Passenger" << std::endl << std::endl;
		std::cout << "Exception message: " << B.what() << std::endl << std::endl;
	}
	catch (Bad_Passenger& B)
	{
		std::cout << "Exception caught successfully upon trying to create an invalid Passenger" << std::endl << std::endl;
		std::cout << "Exception message: " << B.what() << std::endl << std::endl;
	}
	
	
	//To test the validateAadhaar() static member Function
	std::cout << "**********************************************************" << std::endl;
	std::cout << "To test the validateAadhaar() static member Function:" << std::endl << std::endl;
	std::cout << "Passenger::validateAadhaar(\"123456789012\"): " << Passenger::validateAadhaar("123456789012") << std::endl;
	if(Passenger::validateAadhaar("123456789012")!=true)
	{
		std::cerr << "Error in validateAadhaar() static Member Function" << std::endl; 
	}
	std::cout << "Passenger::validateAadhaar(\"1239012\"): " << Passenger::validateAadhaar("1239012") << std::endl;
	if(Passenger::validateAadhaar("1239012")!=false)
	{
		std::cerr << "Error in validateAadhaar() static Member Function" << std::endl; 
	}
	
	
	//To test the validateMobile() static member Function
	std::cout << "**********************************************************" << std::endl;
	std::cout << "To test the validateMobile() static member Function:" << std::endl << std::endl;
	std::cout << "Passenger::validateMobile(\"1234567890\"): " << Passenger::validateMobile("1234567890") << std::endl;
	if(Passenger::validateMobile("1234567890")!=true)
	{
		std::cerr << "Error in validateMobile() static Member Function" << std::endl; 
	}
	std::cout << "Passenger::validateMobile(\"1290\"): " << Passenger::validateMobile("1290") << std::endl;
	if(Passenger::validateMobile("1290")!=false)
	{
		std::cerr << "Error in validateMobile() static Member Function" << std::endl; 
	}
	
	std::cout << std::endl;
	std::cout << "**********************************************************" << std::endl;
	std::cout << std::endl;
	std::cout << "Passenger P1 = Passenger::createPassenger(\"Mike\",\"Charles\",\"Xavier\",21,01,2001,Gender::Male::Type(),\"987654321012\",\"1234567890\",Divyaang::Blind::Type(),\"123\" )" << std::endl;
	std::cout << std::endl;
	
	
	//To test the GetName() member Function
	std::cout << "**********************************************************" << std::endl;
	std::cout << "To test the GetName() member Function:" << std::endl << std::endl;
	std::cout << "P1 Object name: " << P1.GetName() << std::endl;
	if(P1.GetName().GetFirstName() != "Mike" || P1.GetName().GetMiddleName() != "Charles" || P1.GetName().GetLastName() != "Xavier")
	{
		std::cerr << "Error in GetName() Member Function" << std::endl; 
	}
	
	//To test the GetDOB() member Function
	std::cout << "**********************************************************" << std::endl;
	std::cout << "To test the GetDOB() member Function:" << std::endl << std::endl;
	std::cout << "P1 Object DOB: " << P1.GetDOB() << std::endl;
	if(P1.GetDOB() != Date::createDate(21,01,2001))
	{
		std::cerr << "Error in GetDOB() Member Function" << std::endl; 
	}
	
	//To test the GetAge() member Function
	std::cout << "**********************************************************" << std::endl;
	std::cout << "To test the GetAge() member Function:" << std::endl << std::endl;
	std::cout << "P1 Object Age: " << P1.GetAge() << std::endl;
	if(P1.GetAge() != 20)
	{
		std::cerr << "Error in GetAge() Member Function" << std::endl; 
	}
	
	//To test the GetGender() member Function
	std::cout << "**********************************************************" << std::endl;
	std::cout << "To test the GetGender() member Function:" << std::endl << std::endl;
	std::cout << "P1 Object Gender: " << P1.GetGender().GetName() << std::endl;
	if(&P1.GetGender() != &Gender::Male::Type())
	{
		std::cerr << "Error in GetDOB() Member Function" << std::endl; 
	}
	
	//To test the GetAadhaar() member Function
	std::cout << "**********************************************************" << std::endl;
	std::cout << "To test the GetAadhaar() member Function:" << std::endl << std::endl;
	std::cout << "P1 Object Aadhaar: " << P1.GetAadhaar() << std::endl;
	if(P1.GetAadhaar() != "987654321012")
	{
		std::cerr << "Error in GetAadhaar() Member Function" << std::endl; 
	}
	
	//To test the GetMobile() member Function
	std::cout << "**********************************************************" << std::endl;
	std::cout << "To test the GetMobile() member Function:" << std::endl << std::endl;
	std::cout << "P1 Object Mobile: " << P1.GetMobile() << std::endl;
	if(P1.GetMobile() != "1234567890")
	{
		std::cerr << "Error in GetMobile() Member Function" << std::endl; 
	}
	
	//To test the GetDisability() member Function
	std::cout << "**********************************************************" << std::endl;
	std::cout << "To test the GetDisability() member Function:" << std::endl << std::endl;
	std::cout << "P1 Object Disability Type: " << P1.GetDisability()->GetName() << std::endl;
	if(P1.GetDisability() != Divyaang::Blind::Type())
	{
		std::cerr << "Error in GetDisabilityType() Member Function" << std::endl; 
	}
	
	//To test the GetDisabilityID() member Function
	std::cout << "**********************************************************" << std::endl;
	std::cout << "To test the GetDisabilityID() member Function:" << std::endl << std::endl;
	std::cout << "P1 Object Disability ID: " << P1.GetDisabilityID() << std::endl;
	if(P1.GetDisabilityID() != "123")
	{
		std::cerr << "Error in GetDisabilityID() Member Function" << std::endl; 
	}
	
	//To test the insertion operator
	std::cout << "**********************************************************" << std::endl;
	Passenger P2 = Passenger::createPassenger("Michael","","Xavier",21,01,2015,Gender::Male::Type(),"987654321012","" );
	std::cout << "To test the insertion operator:" << std::endl << std::endl;
	std::cout << "P1 Object: " << P1 << std::endl;
	std::cout << "P2 Object: " << P2 << std::endl;
	std::cout << "**********************************************************" << std::endl;
}
