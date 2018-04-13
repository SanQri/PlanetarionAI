#include "person.h"

#include <queue>

#include "timemanager.h"

#include "Specializations/foodgatherer.h"
#include "Specializations/mixedgatherer.h"
#include "Specializations/woodgatherer.h"


Person::Person(Map *map) {
    this->map = map;
    agility = 2;
    specialization = new FoodGatherer(this);
}

void Person::desideWhatToDo() {
    specialization->work();

    drowsiness += 1.0 / TICKS_PER_DAY;
    starvation += 1.0 / TICKS_PER_DAY;
    thurst += 1.0 / TICKS_PER_DAY;
    // If person has not eaten for a 4 days or has not drunk for a 2 days, it dies
    if (starvation > 4 || thurst > 2) {
        // die
    }
}

double Person::getCommonProductivityMultiplier() {
    return getDrowsinessProductivityMultiplier() * getStarvationProductivityMultiplier();
}

double Person::getStarvationProductivityMultiplier() {

    // Person reaches maximal productivity, when his starvation equals 0.6
    // that equals 14.5 hours of starvation after absolute satiety
    double maximalProductivityPoint = 0.6;
    double smoothness = 3.2;

    return std::exp(-std::pow(starvation - maximalProductivityPoint, 2) / smoothness);
}

double Person::getDrowsinessProductivityMultiplier() {

    // Person feels good during 0.6 day
    // after that appears desire to sleep
    double durationOfCompleteCheerfulness = 0.6;
    double smoothness = 2;

    if (drowsiness < durationOfCompleteCheerfulness) {
        return 1;
    }
    return std::exp(-std::pow(drowsiness - durationOfCompleteCheerfulness, 2) / smoothness);

}

void Person::moveToPoint(Position *p) {
    targetPosition = p;
}

void Person::updateWithTimer(QTimer *timer) {
    Position *velocity = new Position(targetPosition->x - position->x, targetPosition->y - position->y);
    double absoluteValueOfVelocity = std::sqrt(std::pow(velocity->x, 2) + std::pow(velocity->y, 2));
    if (absoluteValueOfVelocity < 0.5) {
        position = targetPosition;
    } else {
        Position *velocityNormalized = new Position(velocity->x / absoluteValueOfVelocity * agility * 0.2,
                                                    velocity->y / absoluteValueOfVelocity * agility * 0.2);
        position = new Position(position->x + velocityNormalized->x, position->y + velocityNormalized->y);
    }
    moveToNearestTree();
}

void Person::moveToNearestTree() {
    targetPosition = map->getNearestTreeFromStartingPoint(*position);
}

QPixmap *Person::getPixmap() {
    return specialization->getSprite();
}

// MARK: Getters and setters

double Person::getStamina() {
    return stamina;
}

double Person::getFtigue() {
    return fatigue;
}

double Person::getStrength() {
    return strength;
}

double Person::getAgility() {
    return agility;
}

double Person::getIntelligence() {
    return intelligence;
}

double Person::getAttentiveness() {
    return attentiveness;
}

double Person::getStarvation() {
    return starvation;
}

double Person::getDrowsiness() {
    return drowsiness;
}

double Person::getThurst() {
    return thurst;
}

double Person::getFoodGatheringExp() {
    return foodGatheringExp;
}

double Person::getWoodGatheringExp() {
    return woodGatheringExp;
}

double Person::getFishingExp() {
    return fishingExp;
}

double Person::getHuntingExp() {
    return huntingExp;
}

double Person::getBonfireExp() {
    return bonfireExp;
}

void Person::setStamina(double value) {
    stamina = value;
}

void Person::setFatigue(double value) {
    fatigue = value;
}

void Person::setStrength(double value) {
    strength = value;
}

void Person::setAgility(double value) {
    agility = value;
}

void Person::setIntelligence(double value) {
    intelligence = value;
}

void Person::setAttentiveness(double value) {
    attentiveness = value;
}

void Person::setStarvation(double value) {
    starvation = value;
}

void Person::setDrowsiness(double value) {
    drowsiness = value;
}

void Person::setThurst(double value) {
    thurst = value;
}

void Person::setFoodGatheringExp(double value) {
    foodGatheringExp = value;
}

void Person::setWoodGatheringExp(double value) {
    woodGatheringExp = value;
}

void Person::setFishingExp(double value) {
    fishingExp = value;
}

void Person::setHuntingExp(double value) {
    huntingExp = value;
}

void Person::setBonfireExp(double value) {
    bonfireExp = value;
}
