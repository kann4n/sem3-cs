// queue.h
#pragma once

#include <iostream>

template <typename T> class Queue {
  private:
    struct Node {
        T data;
        Node *next;
        // the next pointer of new Node is always nullptr
        Node(T val) : data(val), next(nullptr) {}
    };
    Node *head;
    Node *tail;

  public:
    Queue();
    ~Queue();
    bool isEmpty();
    T front();
    void enqueue(T val);
    bool dequeue();
    void display();
};
