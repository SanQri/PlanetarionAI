#include "fruit.h"

Fruit::Fruit(double weight, double volume, double caloricity) : FoodResource(weight, volume, caloricity) { }

Fruit::Fruit(double weight) : FoodResource(weight) { }
