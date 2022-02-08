#include "Divyaang.h"
#include "BookingClass.h"
#include <iostream>
#include <string>
#include <map>

template<>
std::string Divyaang::Blind::sName = "Blind";

template<>
std::string Divyaang::Orthopaedically_Handicapped::sName = "Orthopaedically Handicapped";

template<>
std::string Divyaang::Cancer_Patient::sName = "Cancer Patient";

template<>
std::string Divyaang::TB_Patient::sName = "TB Patient";

template<>
const std::map <std::string,double> Divyaang::Blind::ConcessionFactor = 
{
	{"AC First Class",0.50},
	{"Executive Chair Car",0.75},
	{"AC 2 Tier",0.50},
	{"First Class",0.75},
	{"AC 3 Tier",0.75},
	{"AC Chair Car",0.75},
	{"Sleeper",0.75},
	{"Second Sitting",0.75}
};

template<>
const std::map <std::string,double> Divyaang::Orthopaedically_Handicapped::ConcessionFactor = 
{
	{"AC First Class",0.50},
	{"Executive Chair Car",0.75},
	{"AC 2 Tier",0.50},
	{"First Class",0.75},
	{"AC 3 Tier",0.75},
	{"AC Chair Car",0.75},
	{"Sleeper",0.75},
	{"Second Sitting",0.75}
};

template<>
const std::map <std::string,double> Divyaang::Cancer_Patient::ConcessionFactor = 
{
	{"AC First Class",0.50},
	{"Executive Chair Car",0.75},
	{"AC 2 Tier",0.50},
	{"First Class",0.75},
	{"AC 3 Tier",1},
	{"AC Chair Car",1},
	{"Sleeper",1},
	{"Second Sitting",1}
};

template<>
const std::map <std::string,double> Divyaang::TB_Patient::ConcessionFactor = 
{
	{"AC First Class",0},
	{"Executive Chair Car",0},
	{"AC 2 Tier",0},
	{"First Class",0.75},
	{"AC 3 Tier",0},
	{"AC Chair Car",0},
	{"Sleeper",0.75},
	{"Second Sitting",0.75}
};

Divyaang::Divyaang()
{
}

Divyaang::~Divyaang()
{
}
