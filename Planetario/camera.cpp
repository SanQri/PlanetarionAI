#include "camera.h"
#include "math.h"
#include "cell.h"

Camera::Camera(Map *map, float x, float y) {
    Camera(map, new Position(x, y));
}

Camera::Camera(Map *map, Position *position) {
    this->position = position;
    this->map = map;
    verticalWorldSize = 30;
}

QImage Camera::renderImageOfSize(int w, int h) {
    QImage image = QImage(w, h, QImage::Format_RGB32);
//    position = new Position(10, 20);
//    map = new Map();
//    verticalWorldSize = 30;
    float horizontalWorldSize = (verticalWorldSize * w) / h;
    int topCell = std::floor(position->y - verticalWorldSize / 2);
    int bottomCell = std::ceil(position->y + verticalWorldSize / 2);
    int leftCell = std::floor(position->x - horizontalWorldSize / 2);
    int rightCell = std::ceil(position->x + horizontalWorldSize / 2);

    int cellSize = h / verticalWorldSize;

    for (int x = leftCell; x <= rightCell; x++) {
        int screenX = w / 2 - (x - position->x) * cellSize;
        for (int y = topCell; y <= bottomCell; y++) {
            int screenY = h / 2 - (y - position->y) * cellSize;
            CellType type = map->getTypeOfCellAt(x, y);
            QColor color = colorForCellType(type);
            for(int pixelX = screenX; pixelX < screenX + cellSize; pixelX++) {
                for(int pixelY = screenY; pixelY < screenY + cellSize; pixelY++) {
                    if (pixelX >= 0 && pixelX < w &&
                        pixelY >= 0 && pixelY < h) {
                        image.setPixelColor(QPoint(pixelX, pixelY), color);
                    }
                }
            }
        }
    }

    return image;
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
