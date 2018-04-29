#include "foodresource.h"

FoodResource::FoodResource(double mass, double volume, double caloricity) : Resource(mass, volume) {
    this->caloricity = caloricity;
}

FoodResource::FoodResource(double mass) : Resource(mass * 1, mass * 1.2) {
    this->caloricity = mass * 0.5;
}

bool FoodResource::canBeUsed() {

}

double FoodResource::getCaloricity() {
    return caloricity;
}
