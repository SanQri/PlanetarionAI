#ifndef MAP_H
#define MAP_H

#include "cell.h"
#include "diamonsquaregenerator.h"
#include "vector"
#include "Objectives/pointobject.h"

class Map
{
private:
    Cell *cells[SIZE_OF_MAP][SIZE_OF_MAP];
    std::vector<PointObject *>objectives;
public:
    void generate();
    CellType getTypeOfCellAt(int x, int y);
    std::vector<PointObject *>objectivesAtBounds(int x1, int y1, int x2, int y2);
    Map();
};

#endif // MAP_H
