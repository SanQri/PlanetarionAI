#include "Resources/resource.h"

Resource::Resource(double mass, double volume)
{
    this->mass = mass;
    this->volume = volume;
}

void Resource::add(Resource *resource) {
    if (getType() == resource->getType()) {
        this->mass += resource->getMass();
        this->volume += resource->getVolume();
    }
}

bool Resource::remove(double mass, double volume) {
    if (this->mass > mass && this->volume > volume) {
        this->mass -= mass;
        this->volume -= volume;
        return true;
    }
    return false;
}

double Resource::getMass() {
    return mass;
}

double Resource::getVolume() {
    return volume;
}
