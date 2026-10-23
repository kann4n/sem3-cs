// queue.cpp
#include "queue.h"

Queue::Queue(int cap) {
    capacity = cap;
    arr = new int[capacity];
    size = 0;
}

Queue::~Queue() { delete[] arr; }

bool Queue::isEmpty() { return size <= 0; }

bool Queue::isFull() { return size >= capacity; }

int Queue::front() {
    if (isEmpty()) {
        std::cout << "Queue is empty\n";
        return -1;
    }
    return arr[0];
}

void Queue::enqueue(int val) {
    if (isFull()) {
        std::cout << "Queue Overflow\n";
        return;
    }
    arr[size] = val;
    size++;
}

void Queue::dequeue() {
    if (isEmpty()) {
        std::cout << "Queue Underflow\n";
        return;
    }
    for (int i = 1; i < size; i++) {
        arr[i - 1] = arr[i];
    }
    size--;
}

void Queue::display() {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}
