#ifndef CREATE_H
#define CREATE_H
#include "Icommand.h"
#include "organization.h"
class Create : public ICommand
{
public:
	Create(organization ** curr);
	~Create();
    virtual void execute(std::string Params);
private:
	organization ** current; 
};
#endif
