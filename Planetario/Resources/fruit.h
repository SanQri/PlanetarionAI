#ifndef FRUIT_H
#define FRUIT_H

#include "foodresource.h"

class Fruit : public FoodResource
{
public:
    Fruit(double weight, double volume, double caloricity);
};

#endif // FRUIT_H
