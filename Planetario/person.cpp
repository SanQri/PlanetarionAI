#include "person.h"

#include <queue>

#include "timemanager.h"

#include "Specializations/foodgatherer.h"
#include "Specializations/mixedgatherer.h"
#include "Specializations/woodgatherer.h"
#include "Specializations/eater.h"

class Eater;
class FoodGatherer;
class MixedGatherer;
class WoodGatherer;

Person::Person(Map *map) {
    this->stats = new PersonStats();
    this->transportationManager = new PersonTransportationManager(this);
    this->map = map;
    isDead = false;
    stats->setAgility(2);
    this->specialization = new FoodGatherer(this);
    workState = WorkState::JustChanged;
}

PersonStats *Person::getPersonStats() {
    return stats;
}

PersonTransportationManager *Person::getTransportationManager() {
    return transportationManager;
}

double Person::getCommonProductivityMultiplier() {
    double drowsiness = getDrowsinessProductivityMultiplier();
    double starvation = getStarvationProductivityMultiplier();
    return drowsiness * starvation;
}

double Person::getStarvationProductivityMultiplier() {

    // Person reaches maximal productivity, when his starvation equals 0.6
    // that equals 14.5 hours of starvation after absolute satiety
    double maximalProductivityPoint = 0.6;
    double smoothness = 3.2;

    return std::exp(-std::pow(stats->getStarvation() - maximalProductivityPoint, 2) / smoothness);
}

double Person::getDrowsinessProductivityMultiplier() {

    // Person feels good during 0.6 day
    // after that appears desire to sleep
    double durationOfCompleteCheerfulness = 0.6;
    double smoothness = 2;

    if (stats->getDrowsiness() < durationOfCompleteCheerfulness) {
        return 1;
    }
    return std::exp(-std::pow(stats->getDrowsiness() - durationOfCompleteCheerfulness, 2) / smoothness);

}

void Person::moveToPoint(Position *p) {
    targetPosition = p;
}

void Person::updateWithTimer(QTimer *timer) {
    updatePosition();
    updateStats();
    desideWhatToDo();
}

void Person::desideWhatToDo() {
    Specialization *newSpecialization = nullptr;
    if (stats->getStarvation() > 0.3 && transportationManager->hasFood()) {
        newSpecialization = new Eater(this);
    } else {
        newSpecialization = new FoodGatherer(this);
    }

    if (specialization->getType() != newSpecialization->getType()) {
        delete specialization;
        specialization = newSpecialization;
        workState = WorkState::JustChanged;
    } else {
        delete newSpecialization;
    }

    specialization->work();
}

void Person::updatePosition() {
    if (targetPosition == nullptr) {
        return;
    }

    Position *velocity = new Position(targetPosition->x - position->x, targetPosition->y - position->y);
    double absoluteValueOfVelocity = std::sqrt(std::pow(velocity->x, 2) + std::pow(velocity->y, 2));
    if (absoluteValueOfVelocity < 0.5) {
        position = targetPosition;
    } else {
        double agility = stats->getAgility();
        Position *velocityNormalized = new Position(velocity->x / absoluteValueOfVelocity * SECONDS_PER_TICK * 0.2,
                                                    velocity->y / absoluteValueOfVelocity * SECONDS_PER_TICK * 0.2);

        double absoluteValue = std::sqrt(std::pow(velocityNormalized->x, 2) + std::pow(velocityNormalized->y, 2));
        if (absoluteValue > absoluteValueOfVelocity) {
            position = targetPosition;
        } else {
            position = new Position(position->x + velocityNormalized->x, position->y + velocityNormalized->y);
        }
    }
}

void Person::updateStats() {
    stats->setDrowsiness(stats->getDrowsiness() + 1.0 / TICKS_PER_DAY);
    stats->setStarvation(stats->getStarvation() + 1.0 / TICKS_PER_DAY);
//    stats->setThurst(stats->getThurst() + 1.0 / TICKS_PER_DAY);
    // If person has not eaten for 4 days or has not drunk for 2 days, it dies
    if (stats->getStarvation() > 4 || stats->getThurst() > 2) {
        TimeManager::shared()->remove(this);
        isDead = true;
    }
}

void Person::moveToNearestTree() {
    targetPosition = map->getNearestTreeFromStartingPoint(*position);
}

bool Person::atAnchorPoint() {
    return atPoint(targetPosition);
}

bool Person::atPoint(Position *target) {
    Position *vectorToAnchor = new Position(target->x - position->x, target->y - position->y);
    double distance = std::sqrt(std::pow(vectorToAnchor->x, 2) + std::pow(vectorToAnchor->y, 2));
    return distance < 0.5;
}

QPixmap *Person::getPixmap() {
    if (isDead) {
        return new QPixmap(":/ObjectiveSprites/rip.png");
    }
    return new QPixmap(":/ObjectiveSprites/rip.png");
    return specialization->getSprite();
}

void Person::consumeFoodResource(FoodResource *foodResource) {
    double newStarvation = stats->getStarvation() - foodResource->getCaloricity() / 2000.0;
    if (newStarvation < 0) {
        newStarvation = 0;
    }
    stats->setStarvation(newStarvation);
}
