#ifndef SPECIALIZATION_H
#define SPECIALIZATION_H

#include "person.h"

class Specialization
{
private:
    Person *worker;
public:
    Specialization(Person *worker);
    virtual ~Specialization() { }
    virtual void work() = 0;
};

#endif // SPECIALIZATION_H
