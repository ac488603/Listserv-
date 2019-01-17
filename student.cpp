#include "student.h"
#include "observable.h"
#include <iostream>
Student::Student(std::string name): Component(name){ }

Student::~Student(){ std::cout << getName() << " deleted!" << std::endl; }

void Student::update(observable *obj) {
	std::string message = obj->getMessage(); //  get state from object
	std::string organization = obj->getOrganizationName(); // get name from organization  

	subscribed[organization] = message; // update organizations state
	//probably archieve here
}

void Student::print(std::string spaces)
{
	std::cout << spaces <<getName()  <<  std::endl;
}

void Student::del()
{
	delete this;
}

void Student::showRecent()
{
		for (const auto& s : subscribed)
		{
			std::cout << s.first << ": " << s.second << std::endl; //  iterate through map printing key and value
		}
}
