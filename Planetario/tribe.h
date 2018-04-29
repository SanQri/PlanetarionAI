#ifndef TRIBE_H
#define TRIBE_H

#include "Objectives/bonfire.h"
#include "person.h"

class Tribe
{
public:
    std::vector<Person *> people;
    Tribe();
};

#endif // TRIBE_H
