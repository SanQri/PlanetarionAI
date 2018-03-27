#ifndef WOODCUTTER_H
#define WOODCUTTER_H

#include "specialization.h"

class Woodcutter : public Specialization
{
public:
    void work() override;
    Woodcutter();
};

#endif // WOODCUTTER_H
