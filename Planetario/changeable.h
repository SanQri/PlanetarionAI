#ifndef CHANGEABLE_H
#define CHANGEABLE_H

#include <QTimer>

class Changeable
{
public:
    virtual void updateWithTimer(QTimer *timer) = 0;
};

#endif // CHANGEABLE_H
