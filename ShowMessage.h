#ifndef SWMSG_H
#define SWMSG_H
#include "Icommand.h"
#include <unordered_map>
#include "Archiveobject.h"

class ShowMessage : public ICommand
{
public:
	ShowMessage(std::unordered_map<std::string, std::list<ArchiveObject*>* >* a);
	~ShowMessage();
	virtual void execute(std::string );
private:
	bool isInt(std::string);
	std::unordered_map<std::string, std::list<ArchiveObject*>* >* archive;
};
#endif
