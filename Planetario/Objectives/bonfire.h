#ifndef FIRE_H
#define FIRE_H

#include "pointobject.h"

const int COUNT_OF_BONFIRE_FRAMES = 11;

class Bonfire: public PointObject
{
private:
    QPixmap *pixmap[COUNT_OF_BONFIRE_FRAMES];
    int timerTicks;
public:
    QPixmap *getPixmap() override;
    void updateWithTimer(QTimer *timer) override;
    Bonfire();
};

#endif // FIRE_H
