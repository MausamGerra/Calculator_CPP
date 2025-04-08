#include "Expr_Evaluator.h"

std::vector<Expr_Command *> build_postfix_commands(const std::vector<Expr_Node> &postfix_tokens)
{
    std::vector<Expr_Command *> commands;
    commands.reserve(postfix_tokens.size());
    for (const Expr_Node &node : postfix_tokens)
    {
        if (node.tag_ == Expr_Node::NUM)
        {
            // New Number command created for operand/number token
            commands.push_back(new Number_Command(node.num_));
        }
        else
        {
            // Operator command created for operator token
            switch (node.op_)
            {
            case '+':
                commands.push_back(new Add_Command());
                break;
            case '-':
                commands.push_back(new Subtract_Command());
                break;
            case '*':
                commands.push_back(new Multiply_Command());
                break;
            case '/':
                commands.push_back(new Divide_Command());
                break;
            case '%':
                commands.push_back(new Modulo_Command());
                break;
            default:
                std::cout << "Ignore : Unknown operators" << std::endl;
                break;
            }
        }
    }
    return commands;
}

bool evaluate_postfix_commands(const std::vector<Expr_Command *> &commands, int &result)
{
    Stack<int> stack;
    for (Expr_Command *cmd : commands)
    {
        if (!cmd->execute(stack))
        {
            // Execution fail : Error in calculation
            return false;
        }
    }
    if (stack.is_empty())
    {
        return false; // Invalid Expression
    }
    result = stack.top();
    stack.pop();
    if (!stack.is_empty())
    {
        std::cout << "Ignore : Too many operands" << std::endl;
    }
    return true;
}