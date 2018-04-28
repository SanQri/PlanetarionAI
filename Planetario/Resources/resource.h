#ifndef RESOURCE_H
#define RESOURCE_H


class Resource
{
protected:
    double mass;
    double volume;
public:
    double getMass();
    double getVolume();

    virtual bool canBeUsed() = 0;

    Resource(double mass, double volume);
};

#endif // RESOURCE_H
