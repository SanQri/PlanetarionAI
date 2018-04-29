#include "foodresource.h"

FoodResource::FoodResource(double mass, double volume, double caloricity) : Resource(mass, volume) {
    this->caloricity = caloricity;
}

FoodResource::FoodResource(double mass) : Resource(mass * 1, mass * 1.2) {
    this->caloricity = mass * 0.5;
}

bool FoodResource::canBeUsed() {
    return true;
}

double FoodResource::getCaloricity() {
    return caloricity;
}

void FoodResource::add(Resource *resource) {
    Resource::add(resource);
    if (getType() == resource->getType()) {
        caloricity += dynamic_cast<FoodResource *>(resource)->getCaloricity();
    }
}

bool FoodResource::remove(double caloricity) {
    if (this->caloricity > caloricity) {
        Resource::remove(caloricity * 2, caloricity * 2.4);
        this->caloricity -= caloricity;
        return true;
    }
    return false;
}
