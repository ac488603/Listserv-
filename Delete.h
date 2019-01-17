#ifndef DELETE_H
#define DELETE_H
#include "Icommand.h"
#include "organization.h"

class Delete : public ICommand
{
public:
	Delete(organization ** curr);
	~Delete();
	virtual void execute(std::string param);
private:
	organization ** current;
};

#endif
