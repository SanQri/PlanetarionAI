#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets>
#include "mousetrackingwidget.h"
#include "Model/changeable.h"
#include "renderer.h"

class Camera;
class Map;

class MainWindow : public QMainWindow, public Changeable, public MouseTrackingWidgetListener
{
    Q_OBJECT
private:
    bool newImageIsReady;

    QPixmap *camImage;
    QPixmap *newCamImage;
    QPixmap *previousCamImage;
    QLabel *camLabel;
    CameraProtocol *camera;
    Map *map;
    MouseTrackingWidget *mouseTrackingWidget;

    void redraw();
    void redrawScene();

public:
    MainWindow();
    void updateWithTimer(QTimer *timer) override;
    void wheelEvent(QWheelEvent *event) override;
    void mouseMovedTo(double x, double y) override;

};

#endif // MAINWINDOW_H
