#include "bonfire.h"
#include <QTimer>

Bonfire::Bonfire()
{
    timerTicks = 0;
    QString gifEnding = QString(".gif");
    QString commonPath = QString("C:\\Users\\SanQri\\Documents\\PlanetarioAI\\Planetario\\ObjectiveSprites\\BonfireFrames\\");
    for (int i = 0; i < COUNT_OF_BONFIRE_FRAMES; i++) {
        QString fileName = commonPath + QString::number(i) + gifEnding;
        pixmap[i] = new QPixmap(fileName);
    }
}

QPixmap *Bonfire::getPixmap() {
    int countOfFramesPerImage = 3;
    return pixmap[(timerTicks % (COUNT_OF_BONFIRE_FRAMES * countOfFramesPerImage)) / countOfFramesPerImage];
}

void Bonfire::updateWithTimer(QTimer *timer) {
    timerTicks++;
}
