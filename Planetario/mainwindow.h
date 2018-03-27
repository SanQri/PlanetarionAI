#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets>
#include "mousetrackingwidget.h"

class Camera;
class Map;
class MouseTrackingWidget;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();
    QPixmap *camImage;
    QLabel *camLabel;
    Camera *camera;
    Map *map;
    MouseTrackingWidget *mouseTrackingWidget;
    void redraw();
    void mouseMovedTo(float x, float y);

private slots:
    void redrawScene();

};

#endif // MAINWINDOW_H
