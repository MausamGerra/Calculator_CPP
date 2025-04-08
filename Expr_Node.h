#ifndef EXPR_NODE_H
#define EXPR_NODE_H

#include <stdexcept>
#include <iostream>
#include <vector>
#include <string>

// Token structure for expressions
typedef struct Expr_Node
{
    enum
    {
        NUM,
        OPERATOR
    } tag_;
    union
    {
        char op_; // +-*/%
        int num_; // Positive/Negative Numbers
    } o;
#define num_ o.num_
#define op_ o.op_
} Expr_Node;

// Parse an infix expression string into a list of Expr_Node tokens
std::vector<Expr_Node> tokenize_expression(const std::string &infix_expr);

// Convert a list of infix tokens to postfix (RPN) order
std::vector<Expr_Node> infix_to_postfix(const std::vector<Expr_Node> &infix_tokens);

#endif