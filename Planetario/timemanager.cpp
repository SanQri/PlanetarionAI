#include "timemanager.h"

#include <QTimer>

TimeManager::TimeManager() {
    timer = new QTimer();

    timer->setInterval(18);
    day = 0;
    dayTime = 0;
    QObject::connect( timer, SIGNAL(timeout()), this, SLOT(update()) );
    timer->start();
}

TimeManager *TimeManager::sharedInstance;

TimeManager *TimeManager::shared() {
    if (TimeManager::sharedInstance == nullptr) {
        TimeManager::sharedInstance = new TimeManager();
    }
    return TimeManager::sharedInstance;
}

void TimeManager::add(Changeable *changableObject) {
    changables.insert(changableObject);
}

void TimeManager::remove(Changeable *changableObject) {
    unsubs.insert(changableObject);
}

void TimeManager::update() {
    dayTime += (1.0 / TICKS_PER_DAY);
    
    // new day!
    if (dayTime > 0.99999) {
        day++;
        dayTime = 0;
    }
    for (Changeable *unsub : unsubs) {
        changables.erase(unsub);
    }
    unsubs.clear();
    
    for (Changeable *changable : changables) {
        changable->updateWithTimer(timer);
    }
}

double TimeManager::getDayTime() {
    return dayTime;
}

int TimeManager::getDay() {
    return day;
}

double TimeManager::getBrightness() {

    double morningShift = 0.25;
    double eveningShift = 0.75;

    if (dayTime < 0.25) {
        return twilightBrightnessWithShift(morningShift);
    } else if (dayTime < 0.75) {
        return 1;
    } else {
        return twilightBrightnessWithShift(eveningShift);
    }
}

double TimeManager::twilightBrightnessWithShift(double shift) {
    double smoothness = 0.007;
    double minimalBrightness = 0.16666;

    return (1 - minimalBrightness) * std::exp( (-std::pow((dayTime - shift), 2)) / smoothness) + minimalBrightness;
}
