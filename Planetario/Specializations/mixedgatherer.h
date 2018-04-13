#ifndef MIXEDGATHERER_H
#define MIXEDGATHERER_H

#include "specialization.h"

class MixedGatherer : public Specialization
{
public:
    MixedGatherer(Person *worker);
    void work() override;
    QPixmap *getSprite() override;
};

#endif // MIXEDGATHERER_H
