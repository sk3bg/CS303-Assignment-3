#include "Queue.h"
#include <iostream>
using namespace std;


Queue::Queue() {
    front = rear = -1;  // Initialize front and rear indices to -1
    size = 0;           // Initialize current size to 0
}

// Inserts a new element at the rear
void Queue::enqueue(int element) {
    if (size == MAX_SIZE) {
        cout << "Queue is full. Cannot insert more elements." << endl;
        return;
    }

    if (front == -1) {
        front++;
    }

    rear++;
    arr[rear] = element;
    size++;
}

// Removes the front element of the queue and returns it.
int Queue::dequeue() {
    if (front == -1 || front > rear) {
        cout << "Queue is empty. Cannot dequeue elements." << endl;
        return -1;
    }

    int element = arr[front];
    front++;
    size--;

    return element;
}

// Returns the front element present in the queue without removing it.
int Queue::peek() {
    if (front == -1 || front > rear) {
        cout << "Queue is empty. Cannot peek elements." << endl;
        return -1;
    }

    return arr[front];
}

// Checks if the queue is empty
bool Queue::isEmpty() {
    return (front == -1 || front > rear);
}

// Returns the total number of elements present in the queue
int Queue::getSize() {
    return size;
}
