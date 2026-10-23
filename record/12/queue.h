// queue.h
#pragma once

#include <iostream>

template <typename T> class Queue {
  private:
    T *arr;
    int head;
    int capacity;
    int size;

  public:
    Queue(int cap);
    ~Queue();
    bool isEmpty();
    bool isFull();
    T front();
    void enqueue(T val);
    void dequeue();
    void display();
};
