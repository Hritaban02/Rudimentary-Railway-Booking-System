/* ****************************************
*	Name: Hritaban Ghosh
*	Roll Number: 19CS30053
**************************************** */


#ifndef __GENDER_H__
#define __GENDER_H__

#include <string>

// Forward declaration of templatized class
template<typename T>
class GenderTypes; // Generic Gender type to generate specific genders

// Generic gender type
class Gender
{
	// Abstract Base Class
	std::string name_; // Name of the Gender
	
	// Tag types - to instantiate the template
	// Note that these names are placeholders only and are not exposed outside the class
	// Also they are put inside the class for not cluttering the global namespace
	struct MaleType {};
	struct FemaleType {};
	
	protected:
		Gender(const std::string&);
		virtual ~Gender();
		
	public:
		const std::string& GetName() const { return name_; }
		virtual const std::string GetTitle() const = 0; // Salutation specific to gender
		static bool IsMale(const Gender&); // Checking and matching gender
		
		// Enumerated types - the target sub-types
		typedef GenderTypes<MaleType> Male;
		typedef GenderTypes<FemaleType> Female;
};




// Specific gender types
template<typename T>
class GenderTypes : public Gender 
{
	static const std::string sName; // Respective name of the gender
	static const std::string sSalutation; // Respective salutation for the gender
	GenderTypes(const std::string& name = GenderTypes<T>::sName) : Gender(name) { }
	~GenderTypes() { }
	
	public:
		// Singleton object - placeholder for the respective type
		static GenderTypes<T>& Type() 
		{
			static GenderTypes<T> theObject; 
			return theObject;
		}
		
		const std::string GetTitle() const // Dynamic dispatch
		{ 
			return GenderTypes<T>::sSalutation;
		} // Salutation parametrized by static
};



inline
bool Gender::IsMale(const Gender& g) 
{ 
	return &g == &Gender::Male::Type(); 
}

#endif // __GENDER_H__
