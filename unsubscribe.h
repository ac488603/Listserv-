#ifndef UNSUB_H
#define UNSUB_H
#include <unordered_Map>
#include "Listserv.h"
#include "Icommand.h"
#include "student.h"
#include "organization.h"
class unsubscribe : public ICommand
{
public:
	unsubscribe(std::unordered_map<std::string, Listserv*>* l, organization *r);
	~unsubscribe();
	virtual void execute(std::string);
private:
	void findObservers(organization*, Listserv*, std::string);
	void removechildren(organization *curent, Listserv* list);
	std::list<Student*> getLeafs(std::list<Component*> children);
	std::list<organization*> getComposites(std::list<Component*> children);
	std::unordered_map<std::string, Listserv*>* lists;
	organization* root;
};
#endif

