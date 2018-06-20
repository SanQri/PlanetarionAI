#ifndef SPECIALIZATION_H
#define SPECIALIZATION_H

#include <QPixmap>

#include "Person/person.h"
class Person;

enum SpecializationType {
    WoodGathererType,
    MixedGathererType,
    FoodGathererType,
    SleeperType,
    EaterType
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
    virtual bool canBeIntercepted();
    virtual SpecializationType getType();
};

#endif // SPECIALIZATION_H
