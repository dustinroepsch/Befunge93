//
// Created by Dustin Ryan-Roepsch on 9/4/18.
//

#ifndef FUNGE93_FUNGECOORDINATE_H
#define FUNGE93_FUNGECOORDINATE_H


#include <cstdint>

class FungeCoordinate {
public:
    FungeCoordinate(int32_t x, int32_t y);

    FungeCoordinate() = delete;

    int32_t x();

    int32_t y();

    void x(int32_t x);

    void y(int32_t y);

private:
    int32_t _y;
    int32_t _x;

    int32_t wrap(int32_t x, int i);
};


#endif //FUNGE93_FUNGECOORDINATE_H
