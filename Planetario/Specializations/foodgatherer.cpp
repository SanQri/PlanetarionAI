#include "foodgatherer.h"
#include "timemanager.h"

FoodGatherer::FoodGatherer(Person *worker) : Specialization(worker) {

}

void FoodGatherer::work() {
    worker->moveToNearestTree();
}

double FoodGatherer::getProductivityMultiplier() {
    double commonProductivity = worker->getCommonProductivityMultiplier();

    double brightness = TimeManager::shared()->getBrightness();
    double brightnessMultiplier = std::pow(brightness, 1.4);

    return commonProductivity * brightnessMultiplier;
}

QPixmap *FoodGatherer::getSprite() {
    return new QPixmap("C:\\Users\\SanQri\\Documents\\PlanetarioAI\\Planetario\\ObjectiveSprites\\gathererFood.png");
}
