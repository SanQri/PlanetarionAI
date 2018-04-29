#include "foodgatherer.h"
#include "timemanager.h"
#include "Resources/fruit.h"

FoodGatherer::FoodGatherer(Person *worker) : Specialization(worker) {

}

void FoodGatherer::work() {
    switch (worker->workState) {
    case WorkState::JustChanged:
        worker->moveToNearestTree();
        worker->workState = WorkState::Moving;
        break;
    case WorkState::Moving:
        if (worker->atAnchorPoint()) {
            worker->workState = WorkState::Working;
            work();
        }
        break;
    case WorkState::Working:
        PersonTransportationManager *bag = worker->getTransportationManager();
        double productivity = getProductivityMultiplier();
        Fruit *fruit = new Fruit(productivity * 100);
        bag->take(fruit);
        break;
    }
}

double FoodGatherer::getProductivityMultiplier() {
    double commonProductivity = worker->getCommonProductivityMultiplier();

    double brightness = TimeManager::shared()->getBrightness();
    double brightnessMultiplier = std::pow(brightness, 1.4);

    return commonProductivity * brightnessMultiplier;
}

QPixmap *FoodGatherer::getSprite() {
    return new QPixmap(":/ObjectiveSprites/gathererFood.png");
}

SpecializationType FoodGatherer::getType() {
    return SpecializationType::FoodGathererType;
}
