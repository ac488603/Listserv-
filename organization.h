#ifndef ORGAN_H
#define ORGAN_H
#include "component.h"
#include <list>

class organization : public Component
{
public:
	organization(std::string );
	~organization();

	//component methods
	std::list<Component*> getChild();
	void addComponent(Component *obj);
	void removeComponent(Component *obj);
	virtual void update(observable *obj);
	virtual void print(std::string spaces ="");
	virtual void del(); 


private:
	std::list<Component*> elements;

};

#endif
