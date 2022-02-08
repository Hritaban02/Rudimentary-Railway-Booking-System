#ifndef __NAME_H__
#define __NAME_H__

#include <string>
#include <iostream>

class Name
{
	friend std::ostream& operator<<(std::ostream&, const Name& );
	
private:
	std::string firstName="";
	std::string middleName="";
	std::string lastName="";
	
private:
	Name(std::string,std::string,std::string);
public:
	static Name createName(std::string,std::string,std::string);
	~Name();
	std::string GetFirstName() const;
	std::string GetMiddleName() const;
	std::string GetLastName() const;
	
public:
	//STATIC UNIT TEST FUNCTION
	static void UnitTestName();// Test application for Name

};

#endif // __NAME_H__
