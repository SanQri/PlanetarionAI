#include "persontransportationmanager.h"
#include <typeinfo>

PersonTransportationManager::PersonTransportationManager(Person *person) {
    this->person = person;
}

double PersonTransportationManager::volumeLimit() {
    return 10;
}

double PersonTransportationManager::massLimit() {
    return 10;
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

        resources.insert(resource);

        FoodResource *asFood = dynamic_cast<FoodResource *>(resource);
        WaterResource *asWater = dynamic_cast<WaterResource *>(resource);

        if (asFood) {
            food.insert(asFood);
        } else if (asWater) {
            water.insert(asWater);
        }

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
        food.erase((FoodResource *)resource);
        water.erase((WaterResource *)resource);
    }
}

bool PersonTransportationManager::hasFood() {
    return !food.empty();
}

bool PersonTransportationManager::hasWater() {
    return !water.empty();
}

void PersonTransportationManager::consumeFood() {
    if (hasFood()) {
        FoodResource *pieceOfFood = *food.begin();
        put(pieceOfFood);
        person->consumeFoodResource(pieceOfFood);
    }
}
