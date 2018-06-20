#ifndef CAMERA_H
#define CAMERA_H

#include "Model/position.h"
#include "mainwindow.h"
#include "renderer.h"
#include "Model/map.h"
#include "Model/changeable.h"

class Camera: public CameraProtocol, public Changeable
{
    Q_OBJECT

private:
    Position *position;
    Position *anchorPosition;
    float verticalWorldSize;
    Map *map;
public:
    QPixmap tilesForScales[CellType::CountOfCellTypes][257];
    bool tilesForScalesCalculated[CellType::CountOfCellTypes][257];
    QPixmap getTileOfTypeAndCellSize(CellType cellType, int cellSize);
    QColor colorForCellType(CellType cellType);
    QPixmap pixmapForCellType(CellType cellType);
    QPixmap *renderImageOfSize(int w, int h) override;
    Position *getPosition();
    Position *getAnchorPosition() override;
    void setPosition(float x, float y);
    void setPosition(Position *p);
    void setAnchorPosition(Position *p) override;
    void setVerticalSize(float size) override;
    void updateWithTimer(QTimer *timer) override;
    float getVerticalSize() override;
    Camera(Map *map, float x, float y);
    Camera(Map *map, Position *position);
};

#endif // CAMERA_H
