#include "bonfire.h"

Bonfire::Bonfire()
{
    pixmap = new QPixmap("C:\\Users\\SanQri\\Documents\\PlanetarioAI\\Planetario\\ObjectiveSprites\\bonfire.png");
}

QPixmap *Bonfire::getPixmap() {
    return pixmap;
}
