#include "treeobjective.h"
#include "random"

TreeObjective::TreeObjective()
{
    int r = rand() % 3;
    if (r == 0) {
        pixmap = new QPixmap("C:\\Users\\SanQri\\Documents\\PlanetarioAI\\Planetario\\ObjectiveSprites\\treeObjective.png");
    } else if (r == 1) {
        pixmap = new QPixmap("C:\\Users\\SanQri\\Documents\\PlanetarioAI\\Planetario\\ObjectiveSprites\\treeObjective2.png");
    } else {
        pixmap = new QPixmap("C:\\Users\\SanQri\\Documents\\PlanetarioAI\\Planetario\\ObjectiveSprites\\treeObjective3.png");
    }
}

QPixmap *TreeObjective::getPixmap() {
    return pixmap;
}
