#ifndef MOUSETRACKINGLABEL_H
#define MOUSETRACKINGLABEL_H

#include "mainwindow.h"
#include <QtWidgets>

class MainWindow;

class MouseTrackingWidget : public QWidget
{
public:
    MainWindow *window;
    MouseTrackingWidget(QWidget *parent);
    void mouseMoveEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mouseDoubleClickEvent(QMouseEvent *event) override;
};

#endif // MOUSETRACKINGLABEL_H
