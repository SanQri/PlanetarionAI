#ifndef FOODRESOURCE_H
#define FOODRESOURCE_H

#include "resource.h"

class FoodResource : public Resource
{
protected:
    double caloricity;
public:
    bool canBeUsed() override;
    double getCaloricity();
    FoodResource(double mass, double volume, double caloricity);
    FoodResource(double mass);
};

#endif // FOODRESOURCE_H
