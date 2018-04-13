#include "foodresource.h"

FoodResource::FoodResource(double mass, double volume, double caloricity) : Resource(mass, volume) {
    this->caloricity = caloricity;
}

double FoodResource::getCaloricity() {
    return caloricity;
}
