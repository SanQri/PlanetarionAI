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
private:
    bool drawing;

public:
    MainWindow();
    QPixmap *camImage;
    QPixmap *previousCamImage;
    QLabel *camLabel;
    Camera *camera;
    Map *map;
    MouseTrackingWidget *mouseTrackingWidget;
    void redraw();
    void mouseMovedTo(float x, float y);


    void wheelEvent(QWheelEvent *event) override;

private slots:
    void redrawScene();

};

#endif // MAINWINDOW_H
