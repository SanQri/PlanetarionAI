#ifndef WOODGATHERER_H
#define WOODGATHERER_H

#include "specialization.h"

class WoodGatherer : public Specialization
{
private:
    double getProductivityMultiplier();
public:
    WoodGatherer(Person *person);
    void work() override;
    QPixmap *getSprite() override;
    SpecializationType getType() override;
};

#endif // WOODGATHERER_H
