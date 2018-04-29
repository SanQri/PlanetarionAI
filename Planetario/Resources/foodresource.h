#ifndef FOODRESOURCE_H
#define FOODRESOURCE_H

#include "resource.h"

// will be extended by implementing caloricity/mass
// and volume/mass densities

class FoodResource : public Resource
{
protected:
    double caloricity;
public:
    bool canBeUsed() override;
    double getCaloricity();
    FoodResource(double mass, double volume, double caloricity);
    FoodResource(double mass);
    void add(Resource *resource) override;
    bool remove(double caloricity);
};

#endif // FOODRESOURCE_H
