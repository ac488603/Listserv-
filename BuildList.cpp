#include "BuildList.h"

#include <iostream>



BuildList::BuildList(std::unordered_map<std::string, Listserv*>* l, std::unordered_map<std::string, std::list<ArchiveObject*>* >* a)
{
   lists = l;
   archive = a;
}

void BuildList::execute(std::string param)
{
	lists->emplace(param, new Listserv(param)); //  create new Listserv
	archive->emplace(param, new std::list<ArchiveObject*>()); //  create archive for newly created list serve
	std::cout << param << " created" << std::endl;
}

BuildList::~BuildList()
{
}
