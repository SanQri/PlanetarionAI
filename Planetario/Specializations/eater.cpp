#include "eater.h"

Eater::Eater(Person *worker) : Specialization(worker) {

}

void Eater::work() {
    worker->getTransportationManager()->consumeFood();
}

QPixmap *Eater::getSprite() {
    return new QPixmap(":/ObjectiveSprites/eater.png");
}

SpecializationType Eater::getType() {
    return SpecializationType::EaterType;
}
