#include "pointobject.h"

PointObject::PointObject()
{

}

QPixmap *PointObject::getPixmap() {
    return nullptr;
}

void PointObject::setPosition(Position *position) {
    this->position = position;
}

Position *PointObject::getPosition() {
    return position;
}

void PointObject::updateWithTimer(QTimer *timer) {

}
