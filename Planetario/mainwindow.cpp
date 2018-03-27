#include "mainwindow.h"

#include <QtWidgets>
#include <QMouseEvent>
#include <QTimer>

#include "diamonsquaregenerator.h"
#include "math.h"
#include "camera.h"
#include "position.h"

MainWindow::MainWindow() : QMainWindow()
{
    this->setGeometry(20, 20, 1600, 900);

    camLabel = new QLabel(this);

    map = new Map();
    map->generate();
    camera = new Camera(map, new Position(10.41, 20.76));

    camImage = nullptr;

    redrawScene();

    QTimer *timer = new QTimer();
    timer->setInterval(30);
    connect(timer, SIGNAL(timeout()), this, SLOT(redrawScene()));
    timer->start();



    mouseTrackingWidget = new MouseTrackingWidget(camLabel);
    mouseTrackingWidget->setGeometry(0, 0, width(), height());
    mouseTrackingWidget->show();
}

void MainWindow::redrawScene() {
    if (camImage != nullptr) {
        delete camImage;
        delete camLabel;
//        delete mouseTrackingWidget;
    }
    camImage = camera->renderImageOfSize(width(), height());
    camLabel = new QLabel(this);
    setCentralWidget(camLabel);
    camLabel->setGeometry(0, 0, width(), height());
    camLabel->setPixmap(*camImage);
//    mouseTrackingWidget = new MouseTrackingWidget(camLabel);
//    mouseTrackingWidget->setGeometry(0, 0, width(), height());
//    mouseTrackingWidget->show();
}

void MainWindow::mouseMovedTo(float x, float y) {
    float cameraSpeed = 0.02;
    Position *cameraPosition = camera->getPosition();
    if (x < 10) {
        float newX = std::max(0.0f, cameraPosition->x - cameraSpeed);
        camera->setPosition(new Position(newX, cameraPosition->y));
    }
    if (y < 10) {
        float newY = std::max(0.0f, cameraPosition->y - cameraSpeed);
        camera->setPosition(new Position(cameraPosition->x, newY));
    }
    if (x > width() - 10) {
        float newX = std::min((float)SIZE_OF_MAP, cameraPosition->x + cameraSpeed);
        camera->setPosition(new Position(newX, cameraPosition->y));
    }
    if (y < height() - 10) {
        float newY = std::min((float)SIZE_OF_MAP, cameraPosition->y + cameraSpeed);
        camera->setPosition(new Position(cameraPosition->x, newY));
    }
}

