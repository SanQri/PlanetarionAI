#ifndef POINTOBJECT_H
#define POINTOBJECT_H

#include "QPixmap.h"
#include "position.h"

class PointObject
{
private:
    Position *position;
public:
    Position *getPosition();
    void setPosition(Position *position);
    virtual QPixmap *getPixmap();
    PointObject();
};

#endif // POINTOBJECT_H
