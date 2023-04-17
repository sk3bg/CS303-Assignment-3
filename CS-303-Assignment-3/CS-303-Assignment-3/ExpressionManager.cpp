#include "ExpressionManager.h"
#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool ExpressionManager::isOperand(char ch) {
    return (ch >= '0' && ch <= '9');
}

bool ExpressionManager::isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%');
}

int ExpressionManager::precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    else if (op == '*' || op == '/' || op == '%')
        return 2;
    else
        return 0;
}

string ExpressionManager::infixToPostfix(string exp) {
    stack<char> stack;
    string postfixExp = "";
    for (int i = 0; i < exp.length(); i++) {
        char ch = exp[i];
        if (isOperand(ch)) {
            postfixExp += ch;
        }
        else if (isOperator(ch)) {
            while (!stack.empty() && stack.top() != '(' && precedence(ch) <= precedence(stack.top())) {
                postfixExp += stack.top();
                stack.pop();
            }
            stack.push(ch);
        }
        else if (ch == '(') {
            stack.push(ch);
        }
        else if (ch == ')') {
            while (!stack.empty() && stack.top() != '(') {
                postfixExp += stack.top();
                stack.pop();
            }
            if (!stack.empty() && stack.top() == '(') {
                stack.pop();
            }
            else {
                return "Invalid Expression";
            }
        }
    }
    while (!stack.empty()) {
        if (stack.top() == '(' || stack.top() == ')') {
            return "Invalid Expression";
        }
        postfixExp += stack.top();
        stack.pop();
    }
    return postfixExp;
}

bool ExpressionManager::isBalanced(string exp) {
    stack<char> stack;
    for (int i = 0; i < exp.length(); i++) {
        char ch = exp[i];
        if (ch == '{' || ch == '[' || ch == '(') {
            stack.push(ch);
        }
        else if (ch == '}' || ch == ']' || ch == ')') {
            if (stack.empty()) {
                return false;
            }
            if ((ch == '}' && stack.top() == '{') || (ch == ']' && stack.top() == '[') || (ch == ')' && stack.top() == '(')) {
                stack.pop();
            }
            else {
                return false;
            }
        }
    }
    return stack.empty();
}