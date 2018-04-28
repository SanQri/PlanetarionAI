#ifndef EATER_H
#define EATER_H

#include "specialization.h"

class Eater : public Specialization
{
public:
    Eater(Person *worker);
    void work() override;
    QPixmap *getSprite() override;
    SpecializationType getType() override;
};

#endif // EATER_H
