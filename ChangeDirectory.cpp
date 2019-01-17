#include "ChangeDirectory.h"
#include <iostream>
#include <list>
ChangeDirectory::ChangeDirectory(organization **p,organization *r, organization **current):root(r), parent(p), curr(current)
{

}


ChangeDirectory::~ChangeDirectory()
{
}

void ChangeDirectory::execute(std::string param)
{
	if (param == "..") {
		*curr = *parent;

		if (root->getName() == (*parent)->getName()) return; // check if parent is root, 
		(*parent) = locateParent(root); //  find parent
		return;
	}

	auto children = (*curr)->getChild();  // get children
	auto composites = getComposites(children); // get composite objects amoung children


	for (auto it = composites.begin(); it != composites.end(); it++) //  iterate through composite objects
	{
		if ((*it)->getName() == param)  //check if object matches name 
		{
			*parent = (*curr); 
			(*curr) = *it;  
			break;
		}

	}

}


std::list<organization*> ChangeDirectory::getComposites(std::list<Component*> children)
{
	std::list<organization*> composites;
	for (auto it = children.begin(); it != children.end(); it++) {
		organization* temp = dynamic_cast<organization*>  (*it); // downcast 
		if (temp) { //  null if not a composite object
			composites.push_back(temp); // collect all composite objects
		}
	}
	return composites;
}

organization * ChangeDirectory::locateParent(organization* root)
{
	auto children = root->getChild();  // get all children from root
	auto composites = getComposites(children);  //  filter and get composite objects

	for(auto it = composites.begin();  it != composites.end(); it++)
	{
		if ((*it)->getName() == (*parent)->getName()) // if parent is a child of root then new parent is root
			return root;
		else
			locateParent(*it); // recursive call go further in tree 
	}
}
