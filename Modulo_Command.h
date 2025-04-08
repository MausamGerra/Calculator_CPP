#ifndef MODULO_COMMAND_H
#define MODULO_COMMAND_H

#include "Expr_Command.h"
#include "Stack.h"

//
// Modulo
//
class Modulo_Command : public Expr_Command
{
public:
    bool execute(Stack<int> &stack) override
    {
        if (stack.is_empty())
            return false;
        int n2 = stack.top();
        stack.pop();
        if (n2 == 0)
        {
            std::cerr << "Error: Modulo by zero\n";
            return false;
        }
        if (stack.is_empty())
            return false;
        int n1 = stack.top();
        stack.pop();
        stack.push(n1 % n2);
        return true;
    }
};

#endif