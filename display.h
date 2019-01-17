#ifndef DISPLAY_H
#define DISPLAY_H
#include "Icommand.h"
#include "organization.h"
#include "student.h"
#include <list>

class display : public ICommand
{
public:
	display(organization * r);
	~display();
	virtual void execute(std::string params);
private:
	void findUser(std::string param,  organization* root);
	std::list<organization*> getComposites(std::list<Component*> children);
	std::list<Student*> getLeafs(std::list<Component*> children);
	organization * root;
};

#endif

