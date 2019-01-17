#ifndef NOTIFY_H
#define NOTIFY_H
#include "Icommand.h"
#include <unordered_map>
#include "Listserv.h"
#include "Archiveobject.h"
class notify :public ICommand
{
public:
	notify(std::unordered_map<std::string, Listserv*>* l, std::unordered_map<std::string, std::list<ArchiveObject*>* >* a);
	~notify();
	virtual void execute(std::string param); 
private:
	bool isInt(std::string);
	std::unordered_map<std::string, Listserv*>* lists;
	std::unordered_map<std::string, std::list<ArchiveObject*>* >* archive;
};

#endif
