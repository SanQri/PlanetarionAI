#include "mousetrackingwidget.h"

MouseTrackingWidget::MouseTrackingWidget(QWidget *parent, MouseTrackingWidgetListener *listener) : QWidget(parent)
{
    this->listener = listener;
    setMouseTracking(true);
}

void MouseTrackingWidget::mouseMoveEvent(QMouseEvent *event) {
    if (listener != nullptr) {
        listener->mouseMovedTo((double)event->localPos().x(), (double)event->localPos().y());
    }
}

void MouseTrackingWidget::mouseDoubleClickEvent(QMouseEvent *event) {

}

void MouseTrackingWidget::mousePressEvent(QMouseEvent *event) {

}

void MouseTrackingWidget::mouseReleaseEvent(QMouseEvent *event) {

}
