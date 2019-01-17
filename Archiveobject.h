#ifndef ARCHIVEOBJECT_H
#define ARCHIVEOBJECT_H
#include <string>
#include <iostream>
class ArchiveObject{
public:
	ArchiveObject(std::string mess, int d, int m) :month(m), days(d), message(mess) {}
	int month; 
	int days; 
	std::string message; 
	void info()
	{
		std::cout << month << "/" << days << ": " << message << std::endl;
	}


};

#endif