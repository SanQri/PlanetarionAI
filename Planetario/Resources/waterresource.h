#ifndef WATERRESOURCE_H
#define WATERRESOURCE_H

#include "resource.h"

class WaterResource : public Resource
{
public:
    WaterResource(double mass);
    ResourceType getType() override;
    bool canBeUsed() override;
};

#endif // WATERRESOURCE_H
