#include "mainwindow.h"

#include <QtWidgets>
#include <QMouseEvent>
#include <QTimer>

#include "timemanager.h"
#include "diamonsquaregenerator.h"
#include "math.h"
#include "camera.h"
#include "position.h"

MainWindow::MainWindow() : QMainWindow()
{
    this->setGeometry(0, 0, 1920, 1080);

    camLabel = new QLabel(this);

    map = new Map();
    map->generate();
    camera = new Camera(map, new Position(10.41, 20.76));

    camImage = nullptr;

    TimeManager::shared()->add(this);
    TimeManager::shared()->add(camera);

    mouseTrackingWidget = new MouseTrackingWidget(this);
    mouseTrackingWidget->setGeometry(0, 0, width(), height());
    mouseTrackingWidget->window = this;
    mouseTrackingWidget->show();

    drawing = false;
}

void MainWindow::redrawScene() {
    if (drawing) {
        return;
    }
    drawing = true;
    if (camLabel != nullptr) {
        delete camImage;
        delete camLabel;
    }

    camImage = camera->renderImageOfSize(width(), height());

    camLabel = new QLabel(this);
    camLabel->setGeometry(0, 0, width(), height());
    camLabel->setPixmap(*camImage);
    camLabel->setWindowFlags(Qt::WindowStaysOnBottomHint);
    setCentralWidget(camLabel);
    drawing = false;
}

void MainWindow::mouseMovedTo(float x, float y) {
    float cameraSpeed = 0.02 * camera->getVerticalSize();
    float padding = 20;

    Position *cameraPosition = camera->getAnchorPosition();
    if (x < padding) {
        float newX = std::max(0.0f, cameraPosition->x - cameraSpeed);
        camera->setAnchorPosition(new Position(newX, cameraPosition->y));
    }
    if (x > width() - padding) {
        float newX = std::min((float)SIZE_OF_MAP, cameraPosition->x + cameraSpeed);
        camera->setAnchorPosition(new Position(newX, cameraPosition->y));
    }
    cameraPosition = camera->getAnchorPosition();
    if (y < padding) {
        float newY = std::max(0.0f, cameraPosition->y - cameraSpeed);
        camera->setAnchorPosition(new Position(cameraPosition->x, newY));
    }
    if (y > height() - padding) {
        float newY = std::min((float)SIZE_OF_MAP, cameraPosition->y + cameraSpeed);
        camera->setAnchorPosition(new Position(cameraPosition->x, newY));
    }
}

void MainWindow::wheelEvent(QWheelEvent *event) {
    camera->setVerticalSize(camera->getVerticalSize() * (event->delta() < 0 ? 1.1 : 0.91));
}

void MainWindow::updateWithTimer(QTimer *timer) {
    redrawScene();
}
