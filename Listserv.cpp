#include "Listserv.h"
#include "observer.h"

Listserv::Listserv(std::string n):observable(n){}


Listserv::~Listserv(){}

void Listserv::addSubscriber(observer *obj)
{
	subscribers.push_back(obj); // add new subscribers to list
}

void Listserv::removeSubscriber(observer *obj)
{
	subscribers.remove(obj); // remove subscribers from list
}

void Listserv::notify()
{
	for (auto it = subscribers.begin(); it != subscribers.end(); it++)
	{
		(*it)->update(this);  // update all subscribers
	}

}


std::string Listserv::getMessage() { return message; }
std::string Listserv::getOrganizationName(){ return  name; }
void Listserv::setMessage(std::string m) { this->message = m; }