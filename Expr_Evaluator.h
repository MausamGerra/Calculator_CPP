#ifndef EXPR_EVALUATOR_H
#define EXPR_EVALUATOR_H

#include <vector>
#include "Expr_Node.h"
#include "Expr_Command.h"
#include "Number_Command.h"
#include "Operator_Commands.h"

// List of cmd objects from postfix token sequence
std::vector<Expr_Command *> build_postfix_commands(const std::vector<Expr_Node> &postfix_tokens);

// Executing List of cmd objects to produce result
bool evaluate_postfix_commands(const std::vector<Expr_Command *> &commands, int &result);

#endif