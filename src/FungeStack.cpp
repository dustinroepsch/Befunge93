//
// Created by Dustin Ryan-Roepsch on 9/4/18.
//

#include "FungeStack.h"

void FungeStack::Push(FungeStack::stack_cell_t v) {
    stack.push(v);
}

FungeStack::stack_cell_t FungeStack::Peek() {
    return stack.empty() ? 0 : stack.top();
}

FungeStack::stack_cell_t FungeStack::Pop() {
    if (stack.empty()) {
        return 0;
    }

    stack_cell_t returnValue = stack.top();
    stack.pop();

    return returnValue;
}
