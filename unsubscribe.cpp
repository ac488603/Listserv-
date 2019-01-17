#include "unsubscribe.h"
#include <sstream>
#include <iostream>


unsubscribe::unsubscribe(std::unordered_map<std::string, Listserv*>* l, organization * r):lists(l),root(r)
{
}

unsubscribe::~unsubscribe()
{
}

void unsubscribe::execute(std::string param)
{
	std::stringstream ss(param);
	std::string listname;
	std::string observer;
	getline(ss, listname, ' ');  // get name of list
	getline(ss, observer, ' '); // get name of observer 

	if (lists->count(listname)) // error check,  returns 1 if list exists
	{
		auto list = (*lists)[listname]; //  get desired listserv
		if (root->getName() == observer)
		{
			std::cout << root->getName() << " unsubscribed" << std::endl;
			auto temp = dynamic_cast<Student*> (root);
			if (temp)
			{
				std::cout << "student removed" << std::endl;
				list->removeSubscriber(root);
			}
			else
			{
				removechildren(root, list);
			}

			return;
		}

		findObservers(root, list, observer);
	}
}

void unsubscribe::findObservers(organization *root, Listserv *list, std::string obsr)
{

	auto children = root->getChild();

	for (auto it = children.begin(); it != children.end(); it++)
	{
		if ((*it)->getName() == obsr)
		{
			std::cout << (*it)->getName() << " unsubscribed" << std::endl;
			auto temp = dynamic_cast<organization*> (*it);
			if (temp)
			{
				std::cout << "removing" << temp->getName() << "organization" << std::endl;
				removechildren(temp, list);
			}
			else
			{
				std::cout << "student removed" << std::endl;
				list->removeSubscriber(*it);
			}


			return;
		}
	}

	auto composites = getComposites(children);

	for (auto it = composites.begin(); it != composites.end(); it++)
	{
		findObservers(*it, list, obsr);  // recursive call
	}

}

void unsubscribe::removechildren(organization * curent, Listserv * list)
{
	auto children = curent->getChild();
	auto leafs = getLeafs(children);  // filter for leaves
	auto composites = getComposites(children);  // filter for composites

	for (auto it = leafs.begin(); it != leafs.end(); it++)
	{
		list->removeSubscriber(*it);  // add all leaves
	}

	for (auto it = composites.begin(); it != composites.end(); it++)
	{
		removechildren(*it, list); // recursive call
	}
}

std::list<Student*> unsubscribe::getLeafs(std::list<Component*> children)
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

std::list<organization*> unsubscribe::getComposites(std::list<Component*> children)
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
