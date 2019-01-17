#ifndef COMPONENT_H
#define COMPONENT_H
#include "observer.h"
#include <string>

class Component : public observer{
public:
	 ~Component() {}
	 std::string getName() { return name; }
	 virtual void print(std::string spaces = " ") {}; 
	 virtual void del() {};
protected:
	Component(std::string n) { name = n; }
	std::string name; 
};

#endif
