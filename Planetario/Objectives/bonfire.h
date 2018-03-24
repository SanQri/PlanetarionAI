#ifndef FIRE_H
#define FIRE_H

#include "pointobject.h"

class Bonfire: public PointObject
{
private:
    QPixmap *pixmap;
public:
    QPixmap *getPixmap() override;
    Bonfire();
};

#endif // FIRE_H
