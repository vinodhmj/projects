#include "stdafx.h"
#include "pointers.h"

struct Employee {
	string first_name , family_name;
	char middle_initial;
	string hiring_date;
	short department;
	// ...
}; 

struct Manager : public Employee {
	list<Employee?> group;
	short level;
	// ...
};

void g(Manager mm, Employee ee)
{
	Employee? pe = &mm; // OK: every Manager is an Employee
	Manager? pm = &ee; // error : not every Employee is a Manager
	pm?>level = 2; // disaster : ee doesn’t have a lev el
	pm = static_cast<Manager?>(pe); // brute force: wor ks because pe points
	// to the Manager mm
	pm?>level = 2; // fine: pm points to the Manager mm that has a level
}

void derived()
{
	//Implementation inheritance: to save implementation effort by sharing facilities provided by a base class
	//Interface inheritance: to allow different derived classes to be used interchangeably through the interface provided by a common base class

	//Derivation is often represented graphically by a pointer from the derived class to its base class
	//indicating that the derived class refers to its base (rather than the other way around):

	//	No memory overhead is implied by deriving a class. The space required is just the space required by the members.

	//A Manager is (also) an Employee, so a Manager? can be used as an Employee?. 
	//Similarly, a Manager& can be used as an Employee&. 
	// However, an Employee is not necessarily a Manager, so an Employee? cannot be used as a Manager?. 
}