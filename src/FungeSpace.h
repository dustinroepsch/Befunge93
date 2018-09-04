//
// Created by Dustin Ryan-Roepsch on 9/4/18.
//

#ifndef FUNGE93_FUNGESPACE_H
#define FUNGE93_FUNGESPACE_H


#include <cstdint>
#include <istream>
#include "FungeCoordinate.h"

class FungeSpace {
public:
    typedef uint8_t space_cell_t;
    const static int32_t SPACE_WIDTH = 80;
    const static int32_t SPACE_HEIGHT = 25;

    FungeSpace();

    void LoadProgram(std::istream &program);

    space_cell_t &operator()(FungeCoordinate coordinate);

private:
    space_cell_t space[SPACE_HEIGHT][SPACE_WIDTH];
};


#endif //FUNGE93_FUNGESPACE_H
