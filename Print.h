#ifndef PRINT_H
#define PRINT_H
#include "Icommand.h"
#include "organization.h"
class Print : public ICommand
{
public:
	Print(organization** root);
	~Print();
	using ICommand::execute;
	virtual void execute(std::string Params);
private:
	organization** root; 
};
#endif
