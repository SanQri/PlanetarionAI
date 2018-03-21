#ifndef RENDERER_H
#define RENDERER_H

#include "qimage.h"

class Renderer
{
public:
    Renderer();
    virtual QImage renderImageOfSize(int w, int h) = 0;
};

#endif // RENDERER_H
