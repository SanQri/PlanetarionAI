#ifndef DIAMONSQUAREGENERATOR_H
#define DIAMONSQUAREGENERATOR_H

const int SIZE_OF_MAP = 257;

class DiamonSquareGenerator
{
private:
    inline float square(int top, int left, int bottom, int right);
    inline float diamond(int centerX, int centerY, int shift);
    bool acceptableIndex(int i);
    void blur(int blurRadius);
    void init();
public:
    float height[SIZE_OF_MAP][SIZE_OF_MAP];
    void generate();
    DiamonSquareGenerator();
};

#endif // DIAMONSQUAREGENERATOR_H
