/* ****************************************
*	Name: Hritaban Ghosh
*	Roll Number: 19CS30053
**************************************** */

//Imports
#include "Passenger.h"
#include "Date.h"

//Constructor
Passenger::Passenger(std::string& name_val, int aadhaarNumber_val, Date& dateOfBirth_val, std::string& gender_val, int mobileNumber_val) : name{name_val}, aadhaarNumber{aadhaarNumber_val}, dateOfBirth{dateOfBirth_val}, gender{gender_val}, mobileNumber{mobileNumber_val}
{
}

//Copy Constructor for constructing a new object from a existing one
Passenger::Passenger(const Passenger& other) : name{other.name}, aadhaarNumber{other.aadhaarNumber}, dateOfBirth{other.dateOfBirth}, gender{other.gender}, mobileNumber{other.mobileNumber}
{
}


//Destructor
Passenger::~Passenger()
{
}
