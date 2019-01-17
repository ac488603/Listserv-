#ifndef SUB_H
#define SUB_H
#include "Icommand.h"
#include "Listserv.h"
#include "organization.h"
#include <unordered_map>
#include <list>
#include "student.h"

class Subscribe : public ICommand
{
public:
	Subscribe(std::unordered_map<std::string, Listserv*>* l, organization *r);
	~Subscribe();
	virtual void execute(std::string ); 
private:
	std::list<Student*> getLeafs(std::list<Component*> children);
	void addchildren(organization *curent,  Listserv* list);
	void findObservers(organization*,Listserv*, std::string);
	std::list<organization*> getComposites(std::list<Component*> children);
	std::unordered_map<std::string, Listserv*>* lists;
	organization* root;
};
#endif
