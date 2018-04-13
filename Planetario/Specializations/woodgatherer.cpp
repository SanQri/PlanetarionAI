#include "woodgatherer.h"

WoodGatherer::WoodGatherer(Person *person) : Specialization(worker) {

}

void WoodGatherer::work() {

}

QPixmap *WoodGatherer::getSprite() {
    return new QPixmap("C:\\Users\\SanQri\\Documents\\PlanetarioAI\\Planetario\\ObjectiveSprites\\gathererWood.png");
}
