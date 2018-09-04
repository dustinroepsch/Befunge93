#include <iostream>
#include <fstream>
#include "src/FungeInterpreter.h"

int main() {
    FungeInterpreter interpreter;

    std::ifstream file("/Users/dustin/CLionProjects/Funge93/ExamplePrograms/pi.bf");
    interpreter.LoadProgram(file);
    file.close();

    while (interpreter.IsExecuting()) {
        interpreter.Tick();
    }
    return 0;
}