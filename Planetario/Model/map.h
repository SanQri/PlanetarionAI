#ifndef MAP_H
#define MAP_H

#include "cell.h"
#include "diamonsquaregenerator.h"
#include "Objectives/pointobject.h"

#include <vector>
#include <queue>

class Map
{
private:
    Cell *cells[SIZE_OF_MAP][SIZE_OF_MAP];
    std::vector<PointObject *> *objectivesAtMap[SIZE_OF_MAP][SIZE_OF_MAP];
    bool hasTreeAtPoint[SIZE_OF_MAP][SIZE_OF_MAP];
    std::vector<PointObject *>objectives;
    std::vector<PointObject *>dynamicObjectives;
    void putObjective(PointObject *obj);
    bool acceptableIndex(int i);
    Position *searchNearestTree(std::queue<Position> &searchQueue, bool (&visited)[SIZE_OF_MAP][SIZE_OF_MAP]);

public:
    void generate();
    CellType getTypeOfCellAt(int x, int y);
    std::vector<PointObject *>objectivesAtBounds(int x1, int y1, int x2, int y2);
    void addDynamicObject(PointObject *dynamicObjective);

    Position *getNearestTreeFromStartingPoint(Position startingPoint);

    Map();
};

#endif // MAP_H
