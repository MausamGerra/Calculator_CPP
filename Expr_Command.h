#ifndef EXPR_COMMAND_H
#define EXPR_COMMAND_H

#include "Stack.h"

// Base Command Class
class Expr_Command
{
public:
    virtual ~Expr_Command() = default;

    //
    // Execute the command on the given evaluation stack
    //
    virtual bool execute(Stack<int> &stack) = 0;
};

#endif