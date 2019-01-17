#include "organization.h"
#include <iostream>

organization::organization(std::string n): Component(n){ }

organization::~organization(){ std::cout << getName() << " deleted!" << std::endl; }

std::list<Component*> organization::getChild()
{
	return elements; // get children
}

void organization::addComponent(Component * obj)
{
	elements.push_back(obj);  // add object to list 
}

void organization::removeComponent(Component * obj)
{
	elements.remove(obj); //  remove component from list 
}

void organization::update(observable *obj)
{
	for (auto it = elements.begin(); it != elements.end(); it++)
	{
		(*it)->update(obj);  // update each component
	}
}

void organization::print(std::string spaces)
{
	std::cout << spaces << getName() <<std::endl; // print apporpriate number of spaces and name
	
	for (auto it = elements.begin(); it != elements.end(); it++)
	{
		std::cout << spaces; 
		(*it)->print(spaces + " ");  // spaces increase by one for child 
	}
}

void organization::del()
{
	while (elements.size())
	{
		auto it = elements.front();  // set pointer to first object 
		elements.pop_front(); // remove object from front of list 
		it->del(); // delete each object
	} 
	delete this; //delete itself when children are removed 
}

