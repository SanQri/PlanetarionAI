#include "map.h"

#include <queue>

#include "diamonsquaregenerator.h"
#include "random"
#include "time.h"
#include "timemanager.h"
#include "Objectives/treeobjective.h"
#include "Objectives/bonfire.h"
#include "bounds.h"
#include "person.h"

Map::Map() {
    for (int i = 0; i < SIZE_OF_MAP; i++)
        for (int j = 0; j < SIZE_OF_MAP; j++) {
            cells[i][j] = new Cell(i, j);
            hasTreeAtPoint[i][j] = false;
//            objectivesAtMap[i][j] = std::vector<PointObject *>;
        }
}

void Map::generate() {
    DiamonSquareGenerator *generator = new DiamonSquareGenerator();
    srand(time(NULL));

    int w = 0;
    int s = 0;
    int g = 0;
    int rofl = 0;

    while (w < 1000 || s < 1000 || g < 1000) {

        w = 0;
        s = 0;
        g = 0;
        objectives.clear();
        generator->generate();
        for (int x = 0; x < SIZE_OF_MAP; x++) {
            for (int y = 0; y < SIZE_OF_MAP; y++) {
                float h = generator->height[x][y] + 0.2;
                int c = (int)(h * 650);
                if(c < 70) {
                    cells[x][y]->setType(CellType::DeepWater);
                    w++;
                } else if (c < 90) {
                    cells[x][y]->setType(CellType::Water);
                    w++;
                } else if (c < 150) {
                    cells[x][y]->setType(CellType::Sand);
                    s++;
                } else if (c < 200) {
                    cells[x][y]->setType(CellType::Grass);
                    g++;
                } else {
                    cells[x][y]->setType(CellType::DarkGrass);
                    g++;
                }
                if (c > 180) {
                    int r = rand() % 1000;
                    if (r < 200) {
                        TreeObjective *treeObjective = new TreeObjective();
                        hasTreeAtPoint[x][y] = true;
                        treeObjective->setPosition(new Position(x, y));
                        putObjective(treeObjective);
                    }
                }
                if (c > 90 && c < 150) {
                    int r = rand() % 1000;
                    if (r == 1) {
                        Bonfire *bonfire = new Bonfire();
                        bonfire->setPosition(new Position(x, y));
                        putObjective(bonfire);
                        TimeManager::shared()->add(bonfire);
                    }
                }
            }
        }
        rofl++;
    }



    for (int i = 0; i < 100; i++) {
        Person *person = new Person(this);
        int x = rand() % SIZE_OF_MAP;
        int y = rand() % SIZE_OF_MAP;
        person->setPosition(new Position(x, y));
        person->moveToNearestTree();
//        int x1 = rand() % SIZE_OF_MAP;
//        int y1 = rand() % SIZE_OF_MAP;
//        person->moveToPoint(new Position(x1, y1));
        TimeManager::shared()->add(person);
        dynamicObjectives.push_back(person);
    }
}

void Map::putObjective(PointObject *obj) {
    int x = std::round(obj->getPosition()->x);
    int y = std::round(obj->getPosition()->y);
//    objectivesAtMap[x][y]->push_back(obj);
    objectives.push_back(obj);
}

CellType Map::getTypeOfCellAt(int x, int y) {
    if (x >= 0 && x < SIZE_OF_MAP && y >= 0 && y < SIZE_OF_MAP) {
        return cells[x][y]->getType();
    }
    return CellType::BeyondMap;
}

// To be optimized
std::vector<PointObject *>Map:: objectivesAtBounds(int x1, int y1, int x2, int y2) {
    std::vector<PointObject *>result;

    // WutFace
    Bounds *bounds = new Bounds(y1 - 0.01, x2 + 1.01, y2 + 1.01, x1 - 0.01);
    for (PointObject *objective: objectives) {
        if (bounds->contains(objective->getPosition())) {
            result.push_back(objective);
        }
    }
    for (PointObject *objective: dynamicObjectives) {
        if (bounds->contains(objective->getPosition())) {
            result.push_back(objective);
        }
    }
    return result;
}

void Map::addDynamicObject(PointObject *dynamicObjective) {
    dynamicObjectives.push_back(dynamicObjective);
}

// MARK: BFS

inline bool Map::acceptableIndex(int i) {
    return i >= 0 && i < SIZE_OF_MAP;
}


Position *Map::getNearestTreeFromStartingPoint(Position startingPosition) {
    std::queue<Position> searchQueue;
    searchQueue.push(startingPosition);
    bool visited[SIZE_OF_MAP][SIZE_OF_MAP];
    for (int i = 0; i < SIZE_OF_MAP; i++) {
        for (int j = 0; j < SIZE_OF_MAP; j++) {
            visited[i][j] = false;
        }
    }
    int x = std::round(startingPosition.x);
    int y = std::round(startingPosition.y);
    visited[x][y] = true;

    return searchNearestTree(searchQueue, visited);
}
Position *Map::searchNearestTree(std::queue<Position> &searchQueue, bool (&visited)[SIZE_OF_MAP][SIZE_OF_MAP]) {
    Position currentPosition = searchQueue.front();
    searchQueue.pop();
    int x = std::round(currentPosition.x);
    int y = std::round(currentPosition.y);
    if (hasTreeAtPoint[x][y]) {
        Position *answer = new Position(currentPosition.x, currentPosition.y);
        delete visited;
        return answer;
    }
    bool topAccesible = acceptableIndex(y - 1);
    bool bottomAccesible = acceptableIndex(y + 1);
    bool leftAccesible = acceptableIndex(x - 1);
    bool rightAccesible = acceptableIndex(x + 1);
    if (topAccesible && !visited[x][y - 1]) {
        searchQueue.push(Position(currentPosition.x, currentPosition.y - 1));
        visited[x][y - 1] = true;
    }
    if (bottomAccesible && !visited[x][y + 1]) {
        searchQueue.push(Position(currentPosition.x, currentPosition.y + 1));
        visited[x][y + 1] = true;
    }
    if (leftAccesible && !visited[x - 1][y]) {
        searchQueue.push(Position(currentPosition.x - 1, currentPosition.y));
        visited[x - 1][y] = true;
    }
    if (rightAccesible && !visited[x + 1][y]) {
        searchQueue.push(Position(currentPosition.x + 1, currentPosition.y));
        visited[x + 1][y] = true;
    }
    if (!searchQueue.empty()) {
        return searchNearestTree(searchQueue, visited);
    }
    delete visited;
    return nullptr;
}
