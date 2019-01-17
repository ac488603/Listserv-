#ifndef OBSERVABLE_H
#define OBSERVABLE_H
#include <string>

class observer;  
class observable {
public: 
	observable(std::string n):name(n){}
	~observable() {}

	virtual void addSubscriber(observer *obj) = 0;
	virtual void removeSubscriber(observer *obj) = 0;
	virtual void notify() = 0; 

	virtual std::string getMessage() { return message; }
	virtual std::string getOrganizationName() { return name; }
protected:
	std::string name;
	std::string message;
};
#endif