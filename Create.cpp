#include "Create.h"
#include <iostream>
#include "student.h"
Create::Create(organization ** curr):current(curr)
{
}


Create::~Create()
{
}

void Create::execute(std::string params)
{
	(*current)->addComponent(new Student(params)); // add student to current organization

}