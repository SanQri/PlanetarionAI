#include "camera.h"
#include "math.h"
#include "cell.h"
#include "vector"
#include <QTimer>

Camera::Camera(Map *map, float x, float y) {
    Camera(map, new Position(x, y));
}

Camera::Camera(Map *map, Position *position) {
    this->position = position;
    this->anchorPosition = position;
    this->map = map;
    verticalWorldSize = 30;
    for(int i = 0; i < CellType::CountOfCellTypes; i++) {
        for(int j = 0; j < 257; j++) {
            tilesForScalesCalculated[i][j] = false;
        }
    }

    QTimer *timer = new QTimer();
    timer->setInterval(16);
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(moveToAnchor()));
    timer->start();
}

QPixmap *Camera::renderImageOfSize(int w, int h) {
    float horizontalWorldSize = (verticalWorldSize * w) / h;
    int topCell = std::floor(position->y - verticalWorldSize / 2) - 1;
    int bottomCell = std::ceil(position->y + verticalWorldSize / 2) + 1;
    int leftCell = std::floor(position->x - horizontalWorldSize / 2) - 1;
    int rightCell = std::ceil(position->x + horizontalWorldSize / 2) + 1;

    int cellSize = h / verticalWorldSize;

    QPixmap *pixmap = new QPixmap(w, h);
    pixmap->fill(Qt::transparent);
    QPainter *painter = new QPainter(pixmap);

    for (int x = leftCell; x <= rightCell; x++) {
        int screenX = w / 2 + (x - position->x) * cellSize;
        for (int y = topCell; y <= bottomCell; y++) {
            int screenY = h / 2 + (y - position->y) * cellSize;
            CellType type = map->getTypeOfCellAt(x, y);
            QPixmap tilePixmap = getTileOfTypeAndCellSize(type, cellSize);
            painter->drawPixmap(screenX, screenY, tilePixmap);
        }
    }
    std::vector<PointObject *> objectivesToRender = map->objectivesAtBounds(leftCell, topCell, rightCell, bottomCell);
    for (PointObject *objective: objectivesToRender) {
        QPixmap *objectivePixmap = objective->getPixmap();
        if (objectivePixmap != nullptr) {
            Position *objectivePosition = objective->getPosition();
            int screenX = w / 2 + (objectivePosition->x - position->x) * cellSize;
            int screenY = h / 2 + (objectivePosition->y - position->y) * cellSize;
            painter->drawPixmap(screenX, screenY, cellSize, cellSize, *objectivePixmap);
        }
    }

    painter->end();

    return pixmap;
}

QPixmap Camera::getTileOfTypeAndCellSize(CellType cellType, int cellSize) {
    if (!tilesForScalesCalculated[cellType][cellSize]) {
        QPixmap pixmap = pixmapForCellType(cellType);
        pixmap = pixmap.scaled(cellSize, cellSize);
        tilesForScales[cellType][cellSize] = pixmap;
        tilesForScalesCalculated[cellType][cellSize] = true;
    }
    return tilesForScales[cellType][cellSize];
}

QPixmap Camera::pixmapForCellType(CellType cellType) {
    switch (cellType) {
    case CellType::DarkGrass:
        return QPixmap("C:\\Users\\SanQri\\Documents\\PlanetarioAI\\Planetario\\MapTiles\\darkGrass.png");
    case CellType::Grass:
        return QPixmap("C:\\Users\\SanQri\\Documents\\PlanetarioAI\\Planetario\\MapTiles\\grass.png");
    case CellType::Sand:
        return QPixmap("C:\\Users\\SanQri\\Documents\\PlanetarioAI\\Planetario\\MapTiles\\sand.png");
    case CellType::Water:
        return QPixmap("C:\\Users\\SanQri\\Documents\\PlanetarioAI\\Planetario\\MapTiles\\water.png");
    case CellType::DeepWater:
        return QPixmap("C:\\Users\\SanQri\\Documents\\PlanetarioAI\\Planetario\\MapTiles\\deepWater.png");
    case CellType::Stones:
        return QPixmap("C:\\Users\\SanQri\\Documents\\PlanetarioAI\\Planetario\\MapTiles\\stone.png");
    case CellType::BeyondMap:
        return QPixmap("C:\\Users\\SanQri\\Documents\\PlanetarioAI\\Planetario\\MapTiles\\outOfMap.png");
    }
    return QPixmap("C:\\Users\\SanQri\\Documents\\PlanetarioAI\\Planetario\\MapTiles\\outOfMap.png");
}

QColor Camera::colorForCellType(CellType cellType) {
    switch (cellType) {
    case CellType::DarkGrass:
        return QColor(9, 135, 72);
    case CellType::Grass:
        return QColor(16, 163, 62);
    case CellType::Sand:
        return QColor(226, 221, 152);
    case CellType::Water:
        return QColor(76, 130, 224);
    case CellType::DeepWater:
        return QColor(31, 85, 186);
    case CellType::Stones:
        return QColor(154, 185, 234);
    case CellType::BeyondMap:
        return QColor(20, 20, 20);
    }
    return CellType::BeyondMap;
}

void Camera::setPosition(float x, float y) {
    position = new Position(x, y);
}

void Camera::setPosition(Position *p) {
    position = p;
}

Position *Camera::getPosition() {
    return position;
}
Position *Camera::getAnchorPosition() {
    return anchorPosition;
}

void Camera::setVerticalSize(float size) {
    if (size < 10) {
        size = 10;
    } else if (size > 100) {
        size = 100;
    }
    verticalWorldSize = size;
}

float Camera::getVerticalSize() {
    return verticalWorldSize;
}

void Camera::setAnchorPosition(Position *p) {
    anchorPosition = p;
}

void Camera::updateWithTimer(QTimer *timer) {
    Position *shift = new Position(anchorPosition->x - position->x, anchorPosition->y - position->y);
    position = new Position(position->x + shift->x * 0.2, position->y + shift->y * 0.2);
}
