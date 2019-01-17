#ifndef STUDENT_H
#define STUDENT_H
#include "component.h"
#include <unordered_map>


class Student : public Component
{
public:
	Student(std::string);
	~Student();
	virtual void update(observable *obj);
	virtual void print(std::string spaces = " "); 
	virtual void del();
	void showRecent(); 
 
private:
	std::unordered_map<std::string, std::string> subscribed; // contains subscribed ListServs
};
#endif

