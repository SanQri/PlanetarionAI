#ifndef FRUIT_H
#define FRUIT_H

#include "foodresource.h"

class Fruit : public FoodResource
{
public:
    Fruit(double weight, double volume, double caloricity);
    Fruit(double weight);

    ResourceType getType() override;
};

#endif // FRUIT_H
