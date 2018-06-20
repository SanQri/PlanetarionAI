#include "persontransportationmanager.h"
#include <typeinfo>

#include "Resources/fruit.h"

PersonTransportationManager::PersonTransportationManager(Person *person) {
    this->person = person;
    food = new Fruit(0);
    water = new WaterResource(0);
}

double PersonTransportationManager::volumeLimit() {
    return 10000;
}

double PersonTransportationManager::massLimit() {
    return 10000;
}

bool PersonTransportationManager::take(Resource *resource) {
    if (resources.find(resource) != resources.end()) {
        return false;
    }

    double newMass = currentMass + resource->getMass();
    double newVolume = currentVolume + resource->getVolume();
    if (newMass < massLimit() && newVolume < volumeLimit()) {
        currentMass = newMass;
        currentVolume = newVolume;

        food->add(resource);
        water->add(resource);

        return true;
    }
    return false;
}

void PersonTransportationManager::put(Resource *resource) {
    if (resources.find(resource) != resources.end()) {
        currentMass -= resource->getMass();
        currentVolume -= resource->getVolume();
        if (currentMass < 0)
            currentMass = 0;
        if (currentVolume < 0)
            currentVolume = 0;
        resources.erase(resource);
    }
}

bool PersonTransportationManager::hasFood() {
    return food->getMass() > 100;
}

bool PersonTransportationManager::hasWater() {
    return water->getMass() > 100;
}

void PersonTransportationManager::consumeFood() {
    if(food->getMass()) {
        double caloricity = std::min(food->getCaloricity(), 120.0);
        currentMass -= caloricity * 0.5;
        currentVolume -= caloricity * 0.6;
        if (food->remove(caloricity)) {
            person->consumeFoodResource(caloricity);
        }
    }
}
