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
    Resource();
};

#endif // RESOURCE_H
