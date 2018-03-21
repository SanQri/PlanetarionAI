#include "mainwindow.h"

#include <QtWidgets>
#include "diamonsquaregenerator.h"
#include "math.h"
#include "camera.h"
#include "position.h"

QGraphicsScene* scene;
QGraphicsView* graphicView;

void MainWindow::redrawScene()
{
    scene->clear();
}

inline int getR(int x, int y) {
    return (x + y * SIZE_OF_MAP) * 3;
}
inline int getG(int x, int y) {
    return (x + y * SIZE_OF_MAP) * 3 + 1;
}
inline int getB(int x, int y) {
    return (x + y * SIZE_OF_MAP) * 3 + 2;
}

inline int inRange(int x) {
    if (x < 0)
        return 0;
    if (x > 255)
        return 255;
    return x;
}

MainWindow::MainWindow() : QMainWindow()
{
    this->setGeometry(100, 100, 858, 758);

    view = new QWidget(this);
    this->setCentralWidget(view);
    image = QImage(SIZE_OF_MAP, SIZE_OF_MAP, QImage::Format_RGB32);
    label = new QLabel(view);
    label->show();
    label->setGeometry(0, 0, SIZE_OF_MAP * 2, SIZE_OF_MAP * 2);

    QPushButton *but = new QPushButton(view);
    but->setGeometry(700,0,100,30);
    but->show();
    but->connect(but, &QPushButton::clicked, [this]() {
        map->generate();
        redraw();
    });

    map = new Map();
    map->generate();
    camera = new Camera(map, new Position(10.41, 20.76));

    xPosition = new QSlider(view);
    xPosition->setOrientation(Qt::Horizontal);
    xPosition->show();
    xPosition->setGeometry(32, SIZE_OF_MAP + 32, 200, 20);
    xPosition->setRange(0, SIZE_OF_MAP * 100);

    yPosition = new QSlider(view);
    yPosition->setOrientation(Qt::Horizontal);
    yPosition->show();
    yPosition->setGeometry(32, SIZE_OF_MAP + 72, 200, 20);
    yPosition->setRange(0, SIZE_OF_MAP * 100);

    xPosition->connect(xPosition, &QSlider::valueChanged, [this](int value) {
        camera->setPosition(value / 100.0, camera->getPosition()->y);
        redraw();
    });

    yPosition->connect(yPosition, &QSlider::valueChanged, [this](int value) {
        camera->setPosition(camera->getPosition()->x, value / 100.0);
        redraw();
    });


    heightSlider = new QSlider(view);
    heightSlider->setOrientation(Qt::Horizontal);
    heightSlider->show();
    heightSlider->setGeometry(32, SIZE_OF_MAP + 112, 200, 20);
    heightSlider->setRange(100, 1000);

    heightSlider->connect(heightSlider, &QSlider::valueChanged, [this](int value) {
        camera->setVerticalSize(value / 10.0);
        redraw();
    });
}

void MainWindow::redraw() {

    camImage = camera->renderImageOfSize(SIZE_OF_MAP * 3, SIZE_OF_MAP * 2);
    camLabel = new QLabel(view);
    camLabel->show();
    camLabel->setGeometry(SIZE_OF_MAP, 100, SIZE_OF_MAP * 3, SIZE_OF_MAP * 2);
    camLabel->setPixmap(QPixmap::fromImage(camImage));

    for(int x = 0; x < SIZE_OF_MAP; x++) {
        for(int y = 0; y < SIZE_OF_MAP; y++) {
            image.setPixelColor(x, y, camera->colorForCellType(map->getTypeOfCellAt(x, y)));
        }
    }

    label = new QLabel(view);
    label->show();
    label->setGeometry(0, 0, SIZE_OF_MAP, SIZE_OF_MAP);
    label->setPixmap(QPixmap::fromImage(image));
}
