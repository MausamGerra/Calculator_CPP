#include "Expr_Node.h"
#include <cctype>
#include <iostream>

// Determine precedence of an operator
static int precedence(char op)
{
    switch (op)
    {
    case '*':
    case '/':
    case '%':
        return 2;
    case '+':
    case '-':
        return 1;
    default:
        return 0;
    }
}

// Tokenize an infix expression string into Expr_Node tokens
std::vector<Expr_Node> tokenize_expression(const std::string &infix_expr)
{
    std::vector<Expr_Node> tokens;
    bool lastWasOperator = true;
    for (size_t i = 0; i < infix_expr.length();)
    {
        char ch = infix_expr[i];
        if (isspace(ch))
        {
            ++i;
            continue;
        }
        if (isdigit(ch))
        {
            long number = 0;
            while (i < infix_expr.length() && isdigit(infix_expr[i]))
            {
                number = number * 10 + (infix_expr[i] - '0');
                ++i;
            }
            Expr_Node node;
            node.tag_ = Expr_Node::NUM;
            node.num_ = static_cast<int>(number);
            tokens.push_back(node);
            lastWasOperator = false;
        }
        else if (ch == '+' || ch == '-')
        {
            if (lastWasOperator)
            {
                bool isNegative = (ch == '-');
                ++i;
                while (i < infix_expr.length() && isspace(infix_expr[i]))
                {
                    ++i;
                }
                if (i < infix_expr.length() && isdigit(infix_expr[i]))
                {
                    long number = 0;
                    while (i < infix_expr.length() && isdigit(infix_expr[i]))
                    {
                        number = number * 10 + (infix_expr[i] - '0');
                        ++i;
                    }
                    if (isNegative)
                        number = -number;
                    Expr_Node node;
                    node.tag_ = Expr_Node::NUM;
                    node.num_ = static_cast<int>(number);
                    tokens.push_back(node);
                    lastWasOperator = false;
                }
                else if (i < infix_expr.length() && infix_expr[i] == '(')
                {
                    Expr_Node zero;
                    zero.tag_ = Expr_Node::NUM;
                    zero.num_ = 0;
                    tokens.push_back(zero);
                    Expr_Node op_node;
                    op_node.tag_ = Expr_Node::OPERATOR;
                    op_node.op_ = isNegative ? '-' : '+';
                    tokens.push_back(op_node);
                    lastWasOperator = true;
                }
                else
                {
                    Expr_Node zero;
                    zero.tag_ = Expr_Node::NUM;
                    zero.num_ = 0;
                    tokens.push_back(zero);
                    lastWasOperator = false;
                }
            }
            else
            {
                // It's a binary + or - operator
                Expr_Node op_node;
                op_node.tag_ = Expr_Node::OPERATOR;
                op_node.op_ = ch;
                tokens.push_back(op_node);
                lastWasOperator = true;
                ++i;
            }
        }
        else if (ch == '*' || ch == '/' || ch == '%')
        {
            // Other binary operators
            Expr_Node op_node;
            op_node.tag_ = Expr_Node::OPERATOR;
            op_node.op_ = ch;
            tokens.push_back(op_node);
            lastWasOperator = true;
            ++i;
        }
        else if (ch == '(')
        {
            Expr_Node op_node;
            op_node.tag_ = Expr_Node::OPERATOR;
            op_node.op_ = '(';
            tokens.push_back(op_node);
            lastWasOperator = true;
            ++i;
        }
        else if (ch == ')')
        {
            Expr_Node op_node;
            op_node.tag_ = Expr_Node::OPERATOR;
            op_node.op_ = ')';
            tokens.push_back(op_node);
            lastWasOperator = false;
            ++i;
        }
        else
        {
            // Unknown character (skip it or handle as error)
            std::cerr << "Warning: Skipping unknown character '" << ch << "'\n";
            ++i;
        }
    }
    return tokens;
}

// Convert infix token list to postfix (RPN) using a stack
std::vector<Expr_Node> infix_to_postfix(const std::vector<Expr_Node> &infix_tokens)
{
    std::vector<Expr_Node> postfix;
    std::vector<Expr_Node> op_stack;
    for (const Expr_Node &token : infix_tokens)
    {
        if (token.tag_ == Expr_Node::NUM)
        {
            // Number goes directly to output
            postfix.push_back(token);
        }
        else
        {
            char op = token.op_;
            if (op == '(')
            {
                op_stack.push_back(token);
            }
            else if (op == ')')
            {
                // Pop operators until matching '('
                bool foundLeft = false;
                while (!op_stack.empty())
                {
                    Expr_Node top = op_stack.back();
                    op_stack.pop_back();
                    if (top.tag_ == Expr_Node::OPERATOR && top.op_ == '(')
                    {
                        foundLeft = true;
                        break;
                    }
                    postfix.push_back(top);
                }
            }
            else
            {
                // An operator (+, -, *, /, %)
                while (!op_stack.empty())
                {
                    Expr_Node top = op_stack.back();
                    if (top.tag_ == Expr_Node::OPERATOR && top.op_ != '(' &&
                        precedence(top.op_) >= precedence(op))
                    {
                        op_stack.pop_back();
                        postfix.push_back(top);
                        continue;
                    }
                    break;
                }
                op_stack.push_back(token);
            }
        }
    }
    // Pop any remaining operators
    while (!op_stack.empty())
    {
        Expr_Node top = op_stack.back();
        op_stack.pop_back();
        if (top.tag_ == Expr_Node::OPERATOR && (top.op_ == '(' || top.op_ == ')'))
        {
            continue;
        }
        postfix.push_back(top);
    }
    return postfix;
}