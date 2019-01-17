#include "Subscribe.h"
#include <sstream>
#include <iostream>


Subscribe::Subscribe(std::unordered_map<std::string, Listserv*>* l, organization * r):lists(l), root(r)
{
}

Subscribe::~Subscribe()
{
}

void Subscribe::execute(std::string param)
{
	std::stringstream ss(param);
	std::string listname;  
	std::string observer; 
	getline(ss, listname, ' ');  // get name of list
	getline(ss, observer, ' '); // get name of observer 
	
	if (lists->count(listname)) // error check,  returns 1 if list exists
	{
		auto list = (*lists)[listname]; //  get desired listserv
		if (root->getName() == observer)  //  check if root is 
		{
			std::cout << root->getName() << " subscribed" <<std::endl;
			auto temp = dynamic_cast<Student*> (root); 
			if (temp)
			{
				list->addSubscriber(root); //  if student add student
			}
			else 
			{
				addchildren(root, list); //  if organization add all student 
			}

			return;
		}

		findObservers(root, list, observer);
	}
}

void Subscribe::findObservers(organization * root, Listserv* list, std::string obsr)
{
	auto children = root->getChild(); // get childrean

	for (auto it = children.begin(); it != children.end(); it++)
	{
		if ((*it)->getName() == obsr) //check to see if this is correct observer
		{
			std::cout << (*it)->getName() << " subscribed" << std::endl;
			auto temp = dynamic_cast<organization*> (*it);
			if (temp)
			{
				addchildren(temp, list); //  if organization
			}
			else
			{
				list->addSubscriber(*it); //  if student
			}


			return;
		}
	}

	auto composites = getComposites(children); 

	for (auto it = composites.begin(); it != composites.end(); it++)
	{
		findObservers(*it, list,obsr);  // recursive call
	}

}

std::list<organization*> Subscribe::getComposites(std::list<Component*> children)
{
	std::list<organization*> composites;
	for (auto it = children.begin(); it != children.end(); it++) {
		organization* temp = dynamic_cast<organization*>  (*it);
		if (temp) {
			composites.push_back(temp); // collect all composite objects
		}
	}
	return composites;
}

std::list<Student*> Subscribe::getLeafs(std::list<Component*> children)
{
	std::list<Student*> leafs;
	for (auto it = children.begin(); it != children.end(); it++) {
		auto temp = dynamic_cast<Student*>  (*it);
		if (temp) {
			leafs.push_back(temp); // collect all leaf objects
		}
	}
	return leafs;
}

void Subscribe::addchildren(organization * curent, Listserv * list) // for composite objects
{
	auto children = curent->getChild(); 
	auto leafs = getLeafs(children);  // filter for leaves
	auto composites = getComposites(children);  // filter for composites

	for (auto it = leafs.begin(); it != leafs.end(); it++)
	{
		list->addSubscriber(*it);  // add all leaves
	}
	
	for (auto it = composites.begin(); it != composites.end(); it++)
	{
		addchildren(*it, list); // recursive call
	}
}
