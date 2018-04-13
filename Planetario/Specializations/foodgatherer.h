#ifndef FOODGATHERER_H
#define FOODGATHERER_H

#include "specialization.h"

class FoodGatherer : public Specialization
{
private:
    double getProductivityFromBrightness(double brightness);
    double getProductivityMultiplier();
public:
    FoodGatherer(Person *worker);
    void work() override;
    QPixmap *getSprite() override;
};

#endif // FOODGATHERER_H
