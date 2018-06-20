#ifndef RENDERER_H
#define RENDERER_H

#include "qimage.h"
#include "Model/position.h"

class CameraProtocol : public QObject
{
    Q_OBJECT

public:
    CameraProtocol();
    virtual QPixmap *renderImageOfSize(int w, int h) = 0;

    virtual Position *getAnchorPosition() = 0;
    virtual void setAnchorPosition(Position *p) = 0;
    virtual float getVerticalSize() = 0;
    virtual void setVerticalSize(float size) = 0;
};

#endif // RENDERER_H
