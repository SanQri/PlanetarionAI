#include "mixedgatherer.h"

MixedGatherer::MixedGatherer(Person *worker) : Specialization(worker) {

}

void MixedGatherer::work() {

}

QPixmap *MixedGatherer::getSprite() {
    return new QPixmap(":/ObjectiveSprites/gathererMixed.png");
}

SpecializationType MixedGatherer::getType() {
    return SpecializationType::MixedGathererType;
}
