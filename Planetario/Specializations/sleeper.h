#ifndef SLEEPER_H
#define SLEEPER_H

#include "specialization.h"
#include "timestamp.h"

class Sleeper : public Specialization
{
private:
    TimeStamp *creationStamp;
public:
    Sleeper(Person *worker);
    void work() override;
    QPixmap *getSprite() override;
    bool canBeIntercepted() override;
    SpecializationType getType() override;
};

#endif // SLEEPER_H
