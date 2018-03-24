#ifndef PERSON_H
#define PERSON_H

#include "Specializations/specialization.h"
#include "Objectives/pointobject.h"

class Person: public PointObject
{
private:
    double stamina;
    double fatigue;
    double strength;
    double agility;
    double intelligence;
    Specialization *specialization;
    // cutting, firing, cooking, collecting, fishing, hunting, crafting, raiding(???)

public:
    Person();
    void desideWhatToDo();
    void work();
};

#endif // PERSON_H
