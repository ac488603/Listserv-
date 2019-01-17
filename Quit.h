#ifndef QUIT_H
#define QUIT_H
#include "Icommand.h"
class Quit : public ICommand
{
public:
	Quit(bool *s);
	~Quit();
	virtual void execute(std::string);
private:
	bool * status;

};
#endif

