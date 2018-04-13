#ifndef TIMEMANAGER_H
#define TIMEMANAGER_H

#include <QObject>

#include <set>

#include "changeable.h"

const int TICKS_PER_DAY = 720;
const double SECONDS_PER_TICK = 120.0;

class TimeManager : public QObject
{
    Q_OBJECT
private:
    std::set<Changeable *> changables;
    QTimer *timer;
    int day;
    double dayTime;
    static TimeManager *sharedInstance;
    double twilightBrightnessWithShift(double shift);

public:
    TimeManager();
    void add(Changeable *changableObject);
    void remove(Changeable *changableObject);
    static TimeManager *shared();
    double getDayTime();
    double getBrightness();
private slots:
    void update();
};

#endif // TIMEMANAGER_H
