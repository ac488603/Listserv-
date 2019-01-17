#ifndef BUILDLIST_H
#define BUILDLIST_H
#include "Icommand.h"
#include "Listserv.h"
#include <unordered_map>
#include "Archiveobject.h"

class Listserv;
class BuildList: public ICommand
{
public:
	BuildList(std::unordered_map<std::string, Listserv*>* l, std::unordered_map<std::string, std::list<ArchiveObject*>* >* archive);
	virtual void execute(std::string param); 
	~BuildList();
private:
	std::unordered_map<std::string, Listserv* > * lists;
	std::unordered_map<std::string, std::list<ArchiveObject*>* >* archive;

};

#endif