#ifndef ADMIN_H
#define ADMIN_H


#include <unordered_map>
#include <string>
#include <list>
#include "Icommand.h"
#include "component.h"
#include "organization.h"
#include "Listserv.h"
#include "Archiveobject.h"

class Admin
{
public:
	Admin();
	~Admin();
	void processCommand();
	void Mapping(); 
	void constructOrg();
	void constructListserv();
private:
	std::unordered_map<std::string, ICommand*> commands; 
	std::unordered_map<std::string, Listserv*> lists; 
	std::unordered_map<std::string, std::list<ArchiveObject*>* > archive;
	organization* orgs;   // root
	organization* parent; 
	organization* current;
	bool *status; 
};

#endif 