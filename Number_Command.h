#ifndef NUMBER_COMMAND_H
#define NUMBER_COMMAND_H

#include "Expr_Command.h"

//
// Push Numbers on the Stack
//
class Number_Command : public Expr_Command
{
public:
    Number_Command(int value) : value_(value) {}
    bool execute(Stack<int> &stack) override
    {
        stack.push(value_);
        return true;
    }

private:
    int value_;
};

#endif