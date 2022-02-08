#include "Name.h"
#include "Bad_Name.h"

Name Name::createName(std::string firstName_val,std::string middleName_val,std::string lastName_val)
{
	if(firstName_val=="" && lastName_val=="")
	{
		throw Bad_Name();
	}
	return Name(firstName_val,middleName_val,lastName_val);;
}

Name::Name(std::string firstName_val,std::string middleName_val,std::string lastName_val):firstName(firstName_val),middleName(middleName_val),lastName(lastName_val)
{
}

Name::~Name()
{
}

std::string Name::GetFirstName() const
{
	return this->firstName;
}

std::string Name::GetMiddleName() const
{
	return this->middleName;
}

std::string Name::GetLastName() const
{
	return this->lastName;
}

std::ostream& operator<<(std::ostream& out, const Name& name)
{
	if(name.firstName!="" && name.lastName!="")
	{
		out << name.firstName << " " << name.middleName << " " << name.lastName;
	}
	else if(name.firstName=="")
	{
		out << name.middleName << " " << name.lastName;
	}
	else if(name.lastName=="")
	{
		out << name.firstName << " " << name.middleName;
	}
	return out;
}

//STATIC UNIT TEST FUNCTION
void Name::UnitTestName()
{
	std::cout << "STATIC UNIT TEST FUNCTION Test application for Name " << std::endl << std::endl;
	//To unit test class Name
	
	
	//To test the construction of objects
	Name s1 = createName("Alexis","Marcus","Xavier");
	if(s1.firstName !="Alexis" || s1.middleName!="Marcus" || s1.lastName!="Xavier")
	{
		std::cerr << "Error Construction Error of createName(\"Alexis\",\"\",\"Xavier\")" << std::endl; 
	}
	Name s2 = createName("Carlos","","");
	if(s2.firstName !="Carlos" || s2.middleName!="" || s2.lastName!="")
	{
		std::cerr << "Error Construction Error of createName(\"Carlos\",\"\",\"\"))" << std::endl; 
	}
	Name s3 = createName("","","Murphy");
	if(s3.firstName !="" || s3.middleName!="" || s3.lastName!="Murphy")
	{
		std::cerr << "Error Construction Error of createName(\"\",\"\",\"Murphy\"))" << std::endl; 
	}
	
	std::cout << "**********************************************************" << std::endl;
	try
	{
		Name S = createName("","Zaxon","");
	}
	catch (Bad_Name& B)
	{
		std::cout << "Exception caught successfully upon trying to create an invalid Name using createName(\"\",\"Zaxon\",\"\")" << std::endl << std::endl;
		std::cout << "Exception message: " << B.what() << std::endl << std::endl;
	}
	std::cout << "**********************************************************" << std::endl;
	try
	{
		Name S = createName("","","");
	}
	catch (Bad_Name& B)
	{
		std::cout << "Exception caught successfully upon trying to create an invalid Name using createName(\"\",\"\",\"\")" << std::endl << std::endl;
		std::cout << "Exception message: " << B.what() << std::endl << std::endl;
	}
	
	
	std::cout << "**********************************************************" << std::endl;
	std::cout << std::endl;
	std::cout << "Name s1 = createName(\"Alexis\",\"Marcus\",\"Xavier\")" << std::endl;
	std::cout << std::endl;
	std::cout << "Name s1 = createName(\"Carlos\",\"\",\"\")" << std::endl;
	std::cout << std::endl;
	
	
	//To test the GetFirstName() member Function
	std::cout << "**********************************************************" << std::endl;
	std::cout << "To test the GetFirstName() member Function:" << std::endl << std::endl;
	std::cout << "s1 Object First Name: " << s1.GetFirstName() << std::endl;
	if(s1.GetFirstName() != "Alexis")
	{
		std::cerr << "Error in GetFirstName() Member Function" << std::endl; 
	}
	
	//To test the GetMiddleName() member Function
	std::cout << "**********************************************************" << std::endl;
	std::cout << "To test the GetMiddleName() member Function:" << std::endl << std::endl;
	std::cout << "s1 Object Middle Name: " << s1.GetMiddleName() << std::endl;
	if(s1.GetMiddleName() != "Marcus")
	{
		std::cerr << "Error in GetMiddleName() Member Function" << std::endl; 
	}
	
	//To test the GetLastName() member Function
	std::cout << "**********************************************************" << std::endl;
	std::cout << "To test the GetLastName() member Function:" << std::endl << std::endl;
	std::cout << "s1 Object Last Name: " << s1.GetLastName() << std::endl;
	if(s1.GetLastName() != "Xavier")
	{
		std::cerr << "Error in GetLastName() Member Function" << std::endl; 
	}
	
	
	
	//To test the insertion operator
	std::cout << "**********************************************************" << std::endl;
	std::cout << "To test the insertion operator:" << std::endl << std::endl;
	std::cout << "s1 Object: " << s1 << std::endl;
	std::cout << "s2 Object: " << s2 << std::endl;
	std::cout << "**********************************************************" << std::endl;
}
