#ifndef OBSERVER_H
#define OBSERVER_H

class observable; 
class observer {
public:
	virtual void update(observable *obj) {};
	virtual ~observer() {}
protected:
	observer() {}
};

#endif