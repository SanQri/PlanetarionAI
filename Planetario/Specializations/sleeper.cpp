#include "sleeper.h"
#include "timemanager.h"

Sleeper::Sleeper(Person *worker) : Specialization(worker) {
    TimeStamp *t = TimeManager::shared()->getCurrentTime();
    creationStamp = new TimeStamp(t->day(), t->dayTime());
}

void Sleeper::work() {
    PersonStats *stats = worker->getPersonStats();
    double drowsiness = stats->getDrowsiness();
    stats->setDrowsiness(std::max(0.0, drowsiness - 5.0 / TICKS_PER_DAY));
    double starvation = stats->getStarvation();
    stats->setStarvation(std::max(0.0, starvation - 0.5 / TICKS_PER_DAY));
}

bool Sleeper::canBeIntercepted() {
    return TimeManager::shared()->getCurrentTime()->timeSince(creationStamp)->dayTimeTotal() > 0.333;
}

QPixmap *Sleeper::getSprite() {
    return new QPixmap(":/ObjectiveSprites/sleeper.png");
}

SpecializationType Sleeper::getType() {
    return SpecializationType::SleeperType;
}
