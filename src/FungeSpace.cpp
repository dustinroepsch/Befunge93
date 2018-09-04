//
// Created by Dustin Ryan-Roepsch on 9/4/18.
//

#include "FungeSpace.h"

FungeSpace::FungeSpace() {
    for (auto &row : space) {
        for (unsigned char &el : row) {
            el = ' ';
        }
    }
}

void FungeSpace::LoadProgram(std::istream &program) {
    std::string currentLine;
    int32_t row = 0;

    while (std::getline(program, currentLine)) {
        if (row >= SPACE_HEIGHT) {
            throw std::length_error("Program Height is too long");
        }
        if (currentLine.size() > SPACE_WIDTH) {
            throw std::length_error("Program width is too long");
        }

        currentLine.resize(SPACE_WIDTH, ' ');
        for (int i = 0; i < SPACE_WIDTH; i++) {
            space[row][i] = static_cast<space_cell_t>(currentLine[i]);
        }
        row++;
    }
}

FungeSpace::space_cell_t &FungeSpace::operator()(FungeCoordinate coordinate) {
    return space[coordinate.y()][coordinate.x()];
}
