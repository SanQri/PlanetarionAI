#include "Resources/resource.h"

Resource::Resource(double mass, double volume)
{
    this->mass = mass;
    this->volume = volume;
}

double Resource::getMass() {
    return mass;
}

double Resource::getVolume() {
    return volume;
}
