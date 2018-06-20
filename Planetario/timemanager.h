#ifndef TIMEMANAGER_H
#define TIMEMANAGER_H

#include <QObject>

#include <set>

#include "Model/changeable.h"
#include "timestamp.h"

const int TICKS_PER_DAY = 240;
const double SECONDS_PER_TICK = 360.0;

class TimeManager : public QObject
{
    Q_OBJECT
private:
    std::set<Changeable *> changables;
    std::set<Changeable *> unsubs;
    TimeStamp *currentDate;
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
    TimeStamp *getCurrentTime();
private slots:
    void update();
};

#endif // TIMEMANAGER_H
