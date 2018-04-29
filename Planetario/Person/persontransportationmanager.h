#ifndef PERSONTRANSPORTATIONMANAGER_H
#define PERSONTRANSPORTATIONMANAGER_H

#include "person.h"
#include "Resources/resource.h"
#include "Resources/foodresource.h"
#include "Resources/waterresource.h"
#include <set>

class Person;

// curently inconsistent

class PersonTransportationManager
{
private:
    Person *person;
    std::set<Resource *> resources;
    FoodResource *food;
    WaterResource *water;

public:
    double currentVolume;
    double currentMass;
    double massLimit();
    double volumeLimit();
    bool take(Resource *resource);
    void put(Resource *resource);
    bool hasFood();
    bool hasWater();

    void consumeFood();

    PersonTransportationManager(Person *person);
};

#endif // PERSONTRANSPORTATIONMANAGER_H
