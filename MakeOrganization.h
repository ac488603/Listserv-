#ifndef MKORG_H
#define MKORG_H
#include "Icommand.h"
#include "organization.h"
class MakeOrganization : public ICommand
{
public:
	MakeOrganization(organization** curr);
	~MakeOrganization(); 
    void execute(std::string param);
private:
	organization** current;
};
#endif

