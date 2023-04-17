// CS-303-Assignment-3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "ExpressionManager.h"
#include "Queue.h"
#include <iostream>

int main()
{
    cout << "Expression Manager Stack Implementation" << endl;
    /* ====================================================================
                Stack Expression Manager
    =======================================================================*/
    ExpressionManager* expressionManager = new ExpressionManager();
    string infixExp;
    cout << "Enter infix expression: ";
    getline(cin, infixExp);
    if (!expressionManager->isBalanced(infixExp)) {
        cout << "Invalid Expression" << endl;
    }
    else {
        string postfixExp = expressionManager->infixToPostfix(infixExp);
        cout << "Postfix expression: " << postfixExp << endl;
    }


    cout << "\nQueue Implementation" << endl;
    /*=======================================================================
                    Queue 
    =======================================================================*/
    Queue* q = new Queue();

    q->enqueue(1);           // Insert element 1 at rear
    q->enqueue(2);           // Insert element 2 at rear
    q->enqueue(3);           // Insert element 3 at rear
    cout << "Size of queue: " << q->getSize() << endl;      // Output: 3

    cout << "Front element: " << q->peek() << endl;         // Output: 1
    cout << "Removed element: " << q->dequeue() << endl;    // Output: 1

    cout << "Size of queue: " << q->getSize() << endl;      // Output: 2

    q->enqueue(4);           // Insert element 4 at rear
    cout << "Front element: " << q->peek() << endl;         // Output: 2

    cout << "Is queue empty? " << (q->isEmpty() ? "Yes" : "No") << endl; // Output: No

     return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
