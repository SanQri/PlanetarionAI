#ifndef WOODGATHERER_H
#define WOODGATHERER_H

#include "specialization.h"

class WoodGatherer : public Specialization
{
public:
    WoodGatherer(Person *person);
    void work() override;
    QPixmap *getSprite() override;
};

#endif // WOODGATHERER_H
