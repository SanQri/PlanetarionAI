#include "cell.h"

Cell::Cell(int x, int y)
{
    this->x = x;
    this->y = y;
}

int Cell::getX() {
    return x;
}

int Cell::getY() {
    return y;
}

void Cell::setType(CellType type) {
    this->type = type;
}

CellType Cell::getType() {
    return type;
}
