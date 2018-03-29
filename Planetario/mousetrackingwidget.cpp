#include "mousetrackingwidget.h"

MouseTrackingWidget::MouseTrackingWidget(QWidget *parent) : QWidget(parent)
{
    window = nullptr;
    setMouseTracking(true);
}

void MouseTrackingWidget::mouseMoveEvent(QMouseEvent *event) {
    if (window != nullptr) {
        window->mouseMovedTo(event->localPos().x(), event->localPos().y());
    }
}

void MouseTrackingWidget::mouseDoubleClickEvent(QMouseEvent *event) {

}

void MouseTrackingWidget::mousePressEvent(QMouseEvent *event) {

}

void MouseTrackingWidget::mouseReleaseEvent(QMouseEvent *event) {

}
