#ifndef MAP_H
#define MAP_H

#include "cell.h"
#include "diamonsquaregenerator.h"

class Map
{
private:
    Cell *cells[SIZE_OF_MAP][SIZE_OF_MAP];
public:
    void generate();
    CellType getTypeOfCellAt(int x, int y);
    Map();
};

#endif // MAP_H
