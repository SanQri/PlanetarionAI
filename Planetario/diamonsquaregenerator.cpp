#include "diamonsquaregenerator.h"
#include "math.h"
#include "time.h"
#include "random"


DiamonSquareGenerator::DiamonSquareGenerator() {

}

const int TEN_THOUTHAND = 10000;
const float GENERATION_DISTORTION = 0.1;

inline float randomFloat() {
    return (rand() % TEN_THOUTHAND) / 10000.0;
}

inline float randomShiftWithAmplitude(float amplitude) {
    return randomFloat() * amplitude - amplitude * 0.5;
}

inline void DiamonSquareGenerator::init() {
    for (int i = 0; i < SIZE_OF_MAP; i++) {
        for (int j = 0; j < SIZE_OF_MAP; j++) {
            height[i][j] = 0;
        }
    }
    srand(time(NULL));
    height[0][0] = 0.1 + randomShiftWithAmplitude(0.4);
    height[0][SIZE_OF_MAP - 1] = 0.3 + randomShiftWithAmplitude(0.4);
    height[SIZE_OF_MAP - 1][0] = -0.1 + randomShiftWithAmplitude(0.4);
    height[SIZE_OF_MAP - 1][SIZE_OF_MAP - 1] = 0.1 + randomShiftWithAmplitude(0.4);

}

void DiamonSquareGenerator::generate() {
    init();
    int step = SIZE_OF_MAP;

    while (step > 1) {
        int halfStep = step / 2;
        for (int y = halfStep; y <= SIZE_OF_MAP - halfStep; y += step) {
            for (int x = halfStep; x <= SIZE_OF_MAP - halfStep; x += step) {
                height[x][y] = square(x - halfStep, y - halfStep, x + halfStep, y + halfStep) +
                        (randomShiftWithAmplitude(GENERATION_DISTORTION) * std::pow(step, 1.4) * 0.007);
            }
        }

        bool evenStep = false;
        for (int y = 0; y < SIZE_OF_MAP; y += halfStep) {
            int initialStep = evenStep ? 0 : halfStep;
            int trashold = evenStep ? SIZE_OF_MAP : SIZE_OF_MAP - halfStep + 1;
            for (int x = initialStep;
                 x < trashold;
                 x += step) {

                height[x][y] = diamond(x, y, halfStep) +
                        (randomShiftWithAmplitude(GENERATION_DISTORTION) * std::pow(step, 1.4) * 0.01);
            }
            evenStep = !evenStep;
        }

        step /= 2;
    }

    blur(3);
}

void DiamonSquareGenerator::blur(int blurRadius) {
    float newH[SIZE_OF_MAP][SIZE_OF_MAP];

    for (int x = 0; x < SIZE_OF_MAP; x++) {
        for (int y = 0; y < SIZE_OF_MAP; y++) {

            float sum = 0;
            int c = 0;
            for (int i = -blurRadius; i <= blurRadius; i++) {
                if (acceptableIndex(x + i)) {
                    for (int j = -blurRadius; j <= blurRadius; j++) {
                        if (acceptableIndex(y + j)) {
                            sum += height[x + i][y + j];
                            c++;
                        }
                    }
                }
            }
            sum /= c;

            newH[x][y] = sum;
        }
    }
    for (int x = 0; x < SIZE_OF_MAP; x++) {
        for (int y = 0; y < SIZE_OF_MAP; y++) {
            height[x][y] = newH[x][y];
        }
    }
}

inline bool DiamonSquareGenerator::acceptableIndex(int i) {
    return i >= 0 && i < SIZE_OF_MAP;
}

float DiamonSquareGenerator::square(int top, int left, int bottom, int right) {
    float sum = 0;
    int countOfSources = 0;

    bool topIsAcceptable = acceptableIndex(top);
    bool rightIsAcceptable = acceptableIndex(right);
    bool bottomIsAcceptable = acceptableIndex(bottom);
    bool leftIsAcceptable = acceptableIndex(left);

    if (topIsAcceptable && rightIsAcceptable) {
        sum += height[right][top];
        countOfSources++;
    }
    if (topIsAcceptable && leftIsAcceptable) {
        sum += height[left][top];
        countOfSources++;
    }
    if (bottomIsAcceptable && rightIsAcceptable) {
        sum += height[right][bottom];
        countOfSources++;
    }
    if (bottomIsAcceptable && leftIsAcceptable) {
        sum += height[left][bottom];
        countOfSources++;
    }

    return sum / countOfSources;
}

inline float DiamonSquareGenerator::diamond(int centerX, int centerY, int shift) {
    float sum = 0;
    int countOfSources = 0;

    int top = centerY - shift;
    int bottom = centerY + shift;
    int left = centerX - shift;
    int right = centerX + shift;

    bool topIsAcceptable = acceptableIndex(top);
    bool rightIsAcceptable = acceptableIndex(right);
    bool bottomIsAcceptable = acceptableIndex(bottom);
    bool leftIsAcceptable = acceptableIndex(left);

    if (topIsAcceptable) {
        sum += height[centerX][top];
        countOfSources++;
    }
    if (leftIsAcceptable) {
        sum += height[left][centerY];
        countOfSources++;
    }
    if (bottomIsAcceptable) {
        sum += height[centerX][bottom];
        countOfSources++;
    }
    if (rightIsAcceptable) {
        sum += height[right][centerY];
        countOfSources++;
    }

    return sum / countOfSources;
}
