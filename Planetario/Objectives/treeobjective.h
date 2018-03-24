#ifndef TREEOBJECTIVE_H
#define TREEOBJECTIVE_H

#include "pointobject.h"

class TreeObjective: public PointObject
{
private:
    QPixmap *pixmap;
public:
    QPixmap *getPixmap() override;
    TreeObjective();
};

#endif // TREEOBJECTIVE_H
