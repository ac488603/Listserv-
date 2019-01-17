#ifndef SWORD_H
#define SWORD_H
#include <unordered_map>
#include <list>
#include "Archiveobject.h"
#include <string>
#include "Icommand.h"
class showordered :public ICommand
{
public:
	showordered(std::unordered_map<std::string, std::list<ArchiveObject*>* >* a);
	~showordered();
	virtual void execute(std::string param);
private:
	std::unordered_map<std::string, std::list<ArchiveObject*>* >* archive; // reference to archive
};
#endif
