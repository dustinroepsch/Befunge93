//
// Created by Dustin Ryan-Roepsch on 9/4/18.
//

#include <iostream>
#include "FungeInterpreter.h"

void FungeInterpreter::LoadProgram(std::istream &program) {
    space.LoadProgram(program);
}

void FungeInterpreter::Tick() {
    befunge_instruction_t instruction = NextInstruction();
    Execute(instruction);
    Move();
}

FungeInterpreter::befunge_instruction_t FungeInterpreter::NextInstruction() {
    return space(pc);
}

void FungeInterpreter::Execute(FungeInterpreter::befunge_instruction_t instruction) {
    if (instruction == '"') {
        stringMode = !stringMode;
        return;
    }

    if (stringMode) {
        stack.Push(instruction);
        return;
    }

    if (std::isdigit(instruction)) {
        stack.Push(instruction - '0');
        return;
    }

    switch (instruction) {
        case '!': {
            FungeStack::stack_cell_t b = stack.Pop();
            stack.Push(!b);
            break;
        }
        case '#': {
            Move();
            break;
        }
        case '$': {
            stack.Pop();
            break;
        }
        case '%': {
            FungeStack::stack_cell_t b = stack.Pop();
            FungeStack::stack_cell_t a = stack.Pop();
            stack.Push(b == 0 ? 0 : a % b);
            break;
        }
        case '&': {
            FungeStack::stack_cell_t input;
            std::cin >> input;
            stack.Push(input);
            break;
        }
        case '*': {
            FungeStack::stack_cell_t b = stack.Pop();
            FungeStack::stack_cell_t a = stack.Pop();
            stack.Push(a * b);
            break;
        }
        case '+': {
            FungeStack::stack_cell_t b = stack.Pop();
            FungeStack::stack_cell_t a = stack.Pop();
            stack.Push(a + b);
            break;
        }
        case ',': {
            FungeStack::stack_cell_t b = stack.Pop();
            std::cout << static_cast<char>(b);
            std::cout.flush();
            break;
        }
        case '-': {
            FungeStack::stack_cell_t b = stack.Pop();
            FungeStack::stack_cell_t a = stack.Pop();
            stack.Push(a - b);
            break;
        }
        case '.': {
            FungeStack::stack_cell_t b = stack.Pop();
            std::cout << static_cast<int32_t>(b) << " ";
            std::cout.flush();
            break;
        }
        case '/': {
            FungeStack::stack_cell_t b = stack.Pop();
            FungeStack::stack_cell_t a = stack.Pop();
            stack.Push(b == 0 ? 0 : a / b);
            break;
        }
        case ':': {
            stack.Push(stack.Peek());
            break;
        }
        case '<': {
            direction = LEFT;
            break;
        }
        case '>': {
            direction = RIGHT;
            break;
        }
        case '?': {
            direction = static_cast<Direction>(rand() % 4);
            break;
        }
        case '@': {
            isExecuting = false;
            break;
        }
        case '\\': {
            FungeStack::stack_cell_t b = stack.Pop();
            FungeStack::stack_cell_t a = stack.Pop();
            stack.Push(b);
            stack.Push(a);
            break;
        }
        case '^': {
            direction = UP;
            break;
        }
        case '_': {
            direction = stack.Pop() ? LEFT : RIGHT;
            break;
        }
        case '`': {
            FungeStack::stack_cell_t b = stack.Pop();
            FungeStack::stack_cell_t a = stack.Pop();
            stack.Push(a > b);
            break;
        }
        case 'g': {
            FungeStack::stack_cell_t y = stack.Pop();
            FungeStack::stack_cell_t x = stack.Pop();
            FungeCoordinate coord(x, y);
            stack.Push(space(coord));
            break;
        }
        case 'p': {
            FungeStack::stack_cell_t y = stack.Pop();
            FungeStack::stack_cell_t x = stack.Pop();
            FungeCoordinate coord(x, y);
            space(coord) = static_cast<FungeSpace::space_cell_t>(stack.Pop());
            break;
        }
        case 'v': {
            direction = DOWN;
            break;
        }
        case '|': {
            direction = stack.Pop() ? UP : DOWN;
            break;
        }
        case '~': {
            char in;
            std::cin >> in;
            stack.Push(in);
            break;
        }
        default:

            break;
    }
}

bool FungeInterpreter::IsExecuting() {
    return isExecuting;
}

void FungeInterpreter::Move() {
    switch (direction) {
        case UP:
            pc.y(pc.y() - 1);
            break;
        case DOWN:
            pc.y(pc.y() + 1);
            break;
        case LEFT:
            pc.x(pc.x() - 1);
            break;
        case RIGHT:
            pc.x(pc.x() + 1);
            break;
    }
}
