#include "display.h"

display::display(organization * r):root(r)
{
}

display::~display()
{
}

void display::execute(std::string params)
{
	findUser(params, root);
}

void display::findUser(std::string param, organization * root)
{
	auto children = root->getChild();
	auto leafs = getLeafs(children);  // get students

	for (auto it = leafs.begin(); it != leafs.end(); it++)
	{
		if ((*it)->getName() == param)
		{
			(*it)->showRecent(); // show all recent updates from subscribed listservs
			return;
		}
	}

	auto composites = getComposites(children);

	for (auto it = composites.begin(); it != composites.end(); it++)
	{
		findUser(param, *it); 
	}
}

std::list<organization*> display::getComposites(std::list<Component*> children)
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

std::list<Student*> display::getLeafs(std::list<Component*> children)
{
	std::list<Student*> leafs;
	for (auto it = children.begin(); it != children.end(); it++) {
		auto temp = dynamic_cast<Student*>  (*it); //  null if object is not a student 
		if (temp) {
			leafs.push_back(temp); // collect all leaf objects
		}
	}
	return leafs;
}

