#ifndef POINTOBJECT_H
#define POINTOBJECT_H

#include "QPixmap.h"

class PointObject
{
public:
    float x;
    float y;
    virtual QPixmap *getPixmap();
    PointObject();
};

#endif // POINTOBJECT_H
