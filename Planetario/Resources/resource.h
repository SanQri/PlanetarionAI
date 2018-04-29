#ifndef RESOURCE_H
#define RESOURCE_H

enum ResourceType {
    FishType,
    FruitType,
    WaterType,
    WoodType
};

class Resource
{
protected:
    double mass;
    double volume;
public:
    double getMass();
    double getVolume();

    virtual bool canBeUsed() = 0;
    virtual void add(Resource *resource);
    virtual bool remove(double mass, double volume);
    virtual ResourceType getType() = 0;

    Resource(double mass, double volume);
};

#endif // RESOURCE_H
