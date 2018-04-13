#include "mixedgatherer.h"

MixedGatherer::MixedGatherer(Person *worker) : Specialization(worker) {

}

void MixedGatherer::work() {

}

QPixmap *MixedGatherer::getSprite() {
    return new QPixmap("C:\\Users\\SanQri\\Documents\\PlanetarioAI\\Planetario\\ObjectiveSprites\\gathererMixed.png");
}

