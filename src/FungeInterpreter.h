//
// Created by Dustin Ryan-Roepsch on 9/4/18.
//

#ifndef FUNGE93_FUNGEINTERPRETER_H
#define FUNGE93_FUNGEINTERPRETER_H


#include "FungeCoordinate.h"
#include "FungeSpace.h"
#include "FungeStack.h"

#include <istream>

class FungeInterpreter {
public:
    typedef char befunge_instruction_t;

    FungeInterpreter() : pc(0, 0), direction(RIGHT), isExecuting(true) {}

    void LoadProgram(std::istream &program);

    void Tick();

    bool IsExecuting();

private:
    enum Direction {
        UP,
        DOWN,
        LEFT,
        RIGHT
    };

    Direction direction;
    FungeCoordinate pc;
    FungeSpace space;
    FungeStack stack;

    befunge_instruction_t NextInstruction();

    void Execute(befunge_instruction_t instruction);

    bool isExecuting;
};


#endif //FUNGE93_FUNGEINTERPRETER_H
