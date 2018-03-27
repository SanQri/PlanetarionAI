#include "bounds.h"

Bounds::Bounds(float top, float right, float bottom, float left) {
    this->top = top;
    this->right = right;
    this->bottom = bottom;
    this->left = left;
}

bool Bounds::contains(Position *position) {
    return position->x >= left && position->x <= right &&
           position->y >= top && position->y <= bottom;
}
