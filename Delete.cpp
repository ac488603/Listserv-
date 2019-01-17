#include "Delete.h"
#include <iostream>

Delete::Delete(organization ** curr):current(curr)
{
}


Delete::~Delete()
{
}

 void Delete::execute(std::string param)
{
	 //prevents user from deleting  Fresnostate (main organization)
		 auto children = (*current)->getChild(); // get children 
		 for (auto it = children.begin(); it != children.end(); it++)
		 {
			 if((*it)->getName() == param) // iterate until desired object found
			 {
				 (*current)->removeComponent(*it); // remove object from list
				 (*it)->del(); // delete object 
				 return;
			 }
		 }
}