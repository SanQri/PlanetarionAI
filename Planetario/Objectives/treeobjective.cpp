#include "treeobjective.h"
#include "random"

TreeObjective::TreeObjective()
{
    int r = rand() % 3;
    if (r == 0) {
        pixmap = new QPixmap(":/ObjectiveSprites/treeObjective.png");
    } else if (r == 1) {
        pixmap = new QPixmap(":/ObjectiveSprites/treeObjective2.png");
    } else {
        pixmap = new QPixmap(":/ObjectiveSprites/treeObjective3.png");
    }
}

QPixmap *TreeObjective::getPixmap() {
    return pixmap;
}
