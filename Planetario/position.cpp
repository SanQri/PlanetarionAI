#include "position.h"

Position::Position(float x, float y) {
    this->x = x;
    this->y = y;
}

void Position::offsetSelfBy(float x, float y) {
    this->x += x;
    this->y += y;
}

Position *Position::offsetBy(float x, float y) {
    return new Position(this->x + x, this->y + y);
}
