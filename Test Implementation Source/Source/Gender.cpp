/* ****************************************
*	Name: Hritaban Ghosh
*	Roll Number: 19CS30053
**************************************** */


// Gender.cpp
#include "Gender.h"
#include <string>

// Names defined as static constants
template<>
const std::string Gender::Male::sName = "Male";
template<>
const std::string Gender::Female::sName = "Female";

// Salutations defined as static constants
template<>
const std::string Gender::Male::sSalutation = "Mr.";
template<>
const std::string Gender::Female::sSalutation = "Ms.";

Gender::Gender(const std::string& name) : name_(name)
{
}

Gender::~Gender()
{
}



