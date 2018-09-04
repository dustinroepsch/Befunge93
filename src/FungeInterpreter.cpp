//
// Created by Dustin Ryan-Roepsch on 9/4/18.
//

#include "FungeInterpreter.h"

void FungeInterpreter::LoadProgram(std::istream &program) {
    space.LoadProgram(program);
}

void FungeInterpreter::Tick() {
    befunge_instruction_t instruction = NextInstruction();
}

FungeInterpreter::befunge_instruction_t FungeInterpreter::NextInstruction() {
    return space(pc);
}

void FungeInterpreter::Execute(FungeInterpreter::befunge_instruction_t instruction) {
    if (std::isdigit(instruction)) {
        stack.Push(instruction);
    }
}

bool FungeInterpreter::IsExecuting() {
    return isExecuting;
}
