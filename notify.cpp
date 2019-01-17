#include "notify.h"
#include <sstream>
#include <iostream>



notify::notify(std::unordered_map<std::string, Listserv*>* l, std::unordered_map<std::string, std::list<ArchiveObject*>* >* a):lists(l),archive(a)
{
}


notify::~notify()
{
}

std::string trim(const std::string& str,
	const std::string& whitespace = " ")
{
	const auto strBegin = str.find_first_not_of(whitespace);
	if (strBegin == std::string::npos)
		return ""; // no content

	const auto strEnd = str.find_last_not_of(whitespace);
	const auto strRange = strEnd - strBegin + 1;

	return str.substr(strBegin, strRange);
}

void notify::execute(std::string param)
{
	std::stringstream ss(param);
	std::string listname;
	std::string message;
	std::string monthtemp;
	std::string daytemp;
	int month;
	int day;
	getline(ss, listname, ' ');  // get name of list
	getline(ss, monthtemp, ' ');
	getline(ss, daytemp, ' ');
	getline(ss, message); // get name of observer
	if ((!isInt(daytemp) && !isInt(monthtemp)) || monthtemp.empty() || daytemp.empty() ) return; //  check to see if paramters are in correct order
	month = std::stoi(monthtemp);
	day = std::stoi(daytemp);

	if (lists->count(listname)) //  check if key is in list 
	{
		auto list = (*lists)[listname];
		list->setMessage(message); //set message 
		list->notify();  // notify all subscribers 
		ArchiveObject*  newMessage = new ArchiveObject(message,day,month);  // new message added to archive
		newMessage->days = day;
		newMessage->month = month;
		newMessage->message = message;
		auto listarchive = (*archive)[listname]; //  get archive
		listarchive->push_back(newMessage);  //  save message in archive
		std::cout << listname << " notified." << std::endl; 
	}
}

bool notify::isInt(std::string s)
{
	//returns false when string contains somethig other than a digit
		return s.find_first_not_of("0123456789") == std::string::npos;
}
