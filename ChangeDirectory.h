#ifndef CHANGEDIR_H
#define CHANGEDIR_H
#include "Icommand.h"
#include <string>
#include "organization.h"

class ChangeDirectory : public ICommand 
{
public:
	ChangeDirectory(organization **p,organization *r, organization **curr);
	~ChangeDirectory(); 
	virtual void execute(std::string);

private:
	std::list<organization*> getComposites(std::list<Component*> children);
	organization* locateParent(organization* root);
	organization** parent; 
	organization* root; 
	organization** curr; 
};

#endif

