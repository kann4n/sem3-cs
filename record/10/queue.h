// queue.h
#pragma once

#include <iostream>

class Queue {
  private:
    int *arr;
    int capacity;
    int size;

  public:
    Queue(int cap);
    ~Queue();
    bool isEmpty();
    bool isFull();
    int front();
    void enqueue(int val);
    void dequeue();
    void display();
};
