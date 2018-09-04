//
// Created by Dustin Ryan-Roepsch on 9/4/18.
//

#include "FungeCoordinate.h"
#include "FungeSpace.h"

int32_t FungeCoordinate::x() {
    return _x;
}

int32_t FungeCoordinate::y() {
    return _y;
}

void FungeCoordinate::x(int32_t x) {
    _x = wrap(x, FungeSpace::SPACE_WIDTH);
}

void FungeCoordinate::y(int32_t y) {
    _y = wrap(y, FungeSpace::SPACE_HEIGHT);
}

int32_t FungeCoordinate::wrap(int32_t val, int32_t max) {
    while (val < 0) {
        val += max;
    }

    return val % max;
}

FungeCoordinate::FungeCoordinate(int32_t x, int32_t y) {
    this->x(x);
    this->y(y);
}

