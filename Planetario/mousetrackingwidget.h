#ifndef MOUSETRACKINGLABEL_H
#define MOUSETRACKINGLABEL_H

#include <QtWidgets>

class MouseTrackingWidgetListener {
public:
    virtual void mouseMovedTo(double x, double y) = 0;
};

class MouseTrackingWidget : public QWidget
{
private:
    MouseTrackingWidgetListener *listener;
public:
    MouseTrackingWidget(QWidget *parent, MouseTrackingWidgetListener *listener);
    void mouseMoveEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mouseDoubleClickEvent(QMouseEvent *event) override;
};

#endif // MOUSETRACKINGLABEL_H
