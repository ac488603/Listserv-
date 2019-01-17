#include "Print.h"
#include "component.h"
Print::Print(organization **root):root(root){}


Print::~Print() {}

void Print::execute(std::string Params)
{
	if (*root) {
		(*root)->print();
	}
}


