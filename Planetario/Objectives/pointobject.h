#ifndef POINTOBJECT_H
#define POINTOBJECT_H

#include "QPixmap.h"
#include "Model/position.h"
#include "Model/changeable.h"

class PointObject : public Changeable
{
protected:
    Position *position;
public:
    Position *getPosition();
    void setPosition(Position *position);
    virtual QPixmap *getPixmap();
    virtual void updateWithTimer(QTimer *timer) override;
    PointObject();
};

#endif // POINTOBJECT_H
