#ifndef POSITION_H
#define POSITION_H


class Position
{
public:
    float x;
    float y;
    Position(float x, float y);
    void offsetSelfBy(float x, float y);
    Position *offsetBy(float x, float y);
};

#endif // POSITION_H
