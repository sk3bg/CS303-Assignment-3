#pragma once
#include <string>

using namespace std;

class ExpressionManager {

private:
    bool isOperand(char ch);

    bool isOperator(char ch);

    int precedence(char op);

    

public:

    string infixToPostfix(string exp);
    bool isBalanced(string exp);
};

