#ifndef PERSON_H
#define PERSON_H

#include "Specializations/specialization.h"
#include "Objectives/pointobject.h"

class Specialization;

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
    double getStamina();
    double getFtigue();
    double getStrength();
    double getAgility();
    double getIntelligence();

    void setStamina(double value);
    void setFatigue(double value);
    void setStrength(double value);
    void setAgility(double value);
    void setIntelligence(double value);

    void desideWhatToDo();
};

#endif // PERSON_H
