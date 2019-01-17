#ifndef ICOMMAND_H
#define ICOMMAND_H


#include <string>
class ICommand { // Listserv Commands
public:
	virtual void execute(std::string param){};
};

#endif