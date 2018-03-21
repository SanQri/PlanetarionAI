#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets>

class Camera;
class Map;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();
    QImage image;
    QLabel *label;
    QImage camImage;
    QLabel *camLabel;
    QWidget *view;
    QSlider *xPosition;
    QSlider *yPosition;
    QSlider *heightSlider;
    Camera *camera;
    Map *map;
    void redraw();

private slots:
    void redrawScene();

};

#endif // MAINWINDOW_H
