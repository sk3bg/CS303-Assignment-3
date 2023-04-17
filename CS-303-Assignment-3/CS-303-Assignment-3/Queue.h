#pragma once
#include <iostream>
using namespace std;

const int MAX_SIZE = 100;   // Maximum size of the queue

class Queue {
private:
    int arr[MAX_SIZE];  // Array to store elements of the queue
    int front;          // Index of front element
    int rear;           // Index of rear element
    int size;           // Current size of the queue

public:
    Queue();

    // Inserts a new element at the rear
    void enqueue(int element);

    // Removes the front element of the queue and returns it.
    int dequeue();

    // Returns the front element present in the queue without removing it.
    int peek();

    // Checks if the queue is empty
    bool isEmpty();

    // Returns the total number of elements present in the queue
    int getSize();
};