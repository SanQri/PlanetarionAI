#ifndef TIMEMANAGER_H
#define TIMEMANAGER_H

#include <QObject>

#include <set>

#include "changeable.h"

const int TICKS_PER_DAY = 96;
const double SECONDS_PER_TICK = 900.0;

class TimeManager : public QObject
{
    Q_OBJECT
private:
    std::set<Changeable *> changables;
    std::set<Changeable *> unsubs;
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
    int getDay();
    double getBrightness();
private slots:
    void update();
};

#endif // TIMEMANAGER_H
