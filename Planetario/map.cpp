#include "map.h"
#include "diamonsquaregenerator.h"
#include "random"
#include "time.h"

Map::Map() {
    for (int i = 0; i < SIZE_OF_MAP; i++)
        for (int j = 0; j < SIZE_OF_MAP; j++)
            cells[i][j] = new Cell(i, j);
}

void Map::generate() {
    DiamonSquareGenerator *generator = new DiamonSquareGenerator();
    generator->generate();
    srand(time(NULL));
    for (int x = 0; x < SIZE_OF_MAP; x++) {
        for (int y = 0; y < SIZE_OF_MAP; y++) {
            float h = generator->height[x][y] + 0.2;
            int c = (int)(h * 650);
            if(c < 70) {
                cells[x][y]->setType(CellType::DeepWater);
            } else if (c < 90) {
                cells[x][y]->setType(CellType::Water);
            } else if (c < 150) {
                cells[x][y]->setType(CellType::Sand);
            } else if (c < 200) {
                cells[x][y]->setType(CellType::Grass);
            } else {
                cells[x][y]->setType(CellType::DarkGrass);
            }
            if (c > 80) {
                int r = rand() % 1000;
                if (r == 1) {
                    cells[x][y]->setType(CellType::Stones);
                }
            }
        }
    }
}

CellType Map::getTypeOfCellAt(int x, int y) {
    if (x >= 0 && x < SIZE_OF_MAP && y >= 0 && y < SIZE_OF_MAP) {
        return cells[x][y]->getType();
    }
    return CellType::BeyondMap;
}
