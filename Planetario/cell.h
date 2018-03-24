#ifndef CELL_H
#define CELL_H

enum CellType {

    Sand,
    Grass,
    DarkGrass,
    Stones,
    Water,
    DeepWater,
    BeyondMap,
    CountOfCellTypes

};

class Cell
{
private:
    int x;
    int y;
    CellType type;
public:
    void setType(CellType type);
    CellType getType();
    int getX();
    int getY();
    Cell(int x, int y);
};

#endif // CELL_H
