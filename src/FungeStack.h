//
// Created by Dustin Ryan-Roepsch on 9/4/18.
//

#ifndef FUNGE93_FUNGESTACK_H
#define FUNGE93_FUNGESTACK_H

#include <stack>


class FungeStack {
public:
    typedef int32_t stack_cell_t;
    FungeStack() = default;

    void Push(stack_cell_t v);

    stack_cell_t Peek();

    stack_cell_t Pop();
private:
    std::stack<stack_cell_t> stack;
};


#endif //FUNGE93_FUNGESTACK_H
