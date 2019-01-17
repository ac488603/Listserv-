#include "ShowMessage.h"

#include <unordered_map>
#include "Archiveobject.h"
#include <sstream>


ShowMessage::ShowMessage(std::unordered_map<std::string, std::list<ArchiveObject*>* >* a):archive(a)
{
}


ShowMessage::~ShowMessage()
{
}

void ShowMessage::execute(std::string param)
{
	
	std::string message;
	std::string month;
	std::string day;
	std::string listname;
	std::string key;
	std::stringstream ss(param);
	getline(ss, listname, ' ');  // get name of list
	getline(ss, month, ' ');
	getline(ss, day, ' ');
	getline(ss, message); // get name of observer 
	if (!(isInt(day) && isInt(month))) return; //  check to see if paramters are in correct order
	key = month + "/" + day;
	auto archivelist = (*archive)[listname]; //  get list  of archived messages

	for (auto it = archivelist->begin(); it != archivelist->end(); it++)
	{
		std::string temp = std::to_string((*it)->month) + "/"  + std::to_string((*it)->days); //  build key
		if (temp == key)
		{
			std::cout << (*it)->month << "/"<< (*it)->days << ": "<< (*it)->message << std::endl;
		}
	}
}

bool ShowMessage::isInt(std::string s)
{
	//returns false when string contains somethig other than a digit
	return s.find_first_not_of("0123456789") == std::string::npos;
}
