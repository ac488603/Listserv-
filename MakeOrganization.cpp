#include "MakeOrganization.h"
#include <iostream>

MakeOrganization::MakeOrganization(organization** curr):current(curr){}


MakeOrganization::~MakeOrganization(){}

void MakeOrganization::execute(std::string param) 
{
		(*current)->addComponent(new organization(param));  // add new component to current
}