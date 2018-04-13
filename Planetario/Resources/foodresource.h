#ifndef FOODRESOURCE_H
#define FOODRESOURCE_H

#include "resource.h"

class FoodResource : public Resource
{
protected:
    double caloricity;
public:
    double getCaloricity();
    FoodResource(double mass, double volume, double caloricity);
};

#endif // FOODRESOURCE_H
