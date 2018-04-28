#ifndef SPECIALIZATION_H
#define SPECIALIZATION_H

#include <QPixmap>

#include "person.h"
class Person;

enum SpecializationType {
    WoodGatherer,
    MixedGatherer,
    FoodGatherer,
    Eater
};

class Specialization
{
protected:
    Person *worker;
    double getProductivityByExp(double exp);
public:
    Specialization(Person *worker);
    virtual void work() = 0;
    virtual QPixmap *getSprite() = 0;
    virtual void readyToWork();
    virtual SpecializationType getType();
};

#endif // SPECIALIZATION_H
