#ifndef LISTSERV_H
#define LISTSERV_H
#include <list>
#include "observable.h"

class Listserv : public observable
{
public:
	Listserv(std::string n);
	~Listserv();

	virtual void addSubscriber(observer *obj);
	virtual void removeSubscriber(observer *obj);
	virtual void notify();
	virtual std::string getMessage();
	virtual std::string getOrganizationName();
	void setMessage(std::string m); 

private:
	std::list<observer*> subscribers;
};
#endif

