#include "woodgatherer.h"
#include "timemanager.h"

WoodGatherer::WoodGatherer(Person *person) : Specialization(worker) {

}

void WoodGatherer::work() {
    switch (worker->workState) {
    case WorkState::JustChanged:
        worker->moveToNearestTree();
        break;
    case WorkState::Moving:
        // do nothing. just walk.
        break;
    case WorkState::Working:

        break;
    }
    worker->moveToNearestTree();
}

double WoodGatherer::getProductivityMultiplier() {
    double commonProductivity = worker->getCommonProductivityMultiplier();

    double brightness = TimeManager::shared()->getBrightness();
    double brightnessMultiplier = std::pow(brightness, 0.7);

    return commonProductivity * brightnessMultiplier;
}

QPixmap *WoodGatherer::getSprite() {
    return new QPixmap(":/ObjectiveSprites/gathererWood.png");
}

SpecializationType WoodGatherer::getType() {
    return SpecializationType::WoodGatherer;
}
