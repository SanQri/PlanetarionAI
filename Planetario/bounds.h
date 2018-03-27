#ifndef BOUNDS_H
#define BOUNDS_H

#include "position.h"

class Bounds
{
private:
    float top;
    float right;
    float bottom;
    float left;
public:
    Bounds(float top, float right, float bottom, float left);
    bool contains(Position *position);
};

#endif // BOUNDS_H
