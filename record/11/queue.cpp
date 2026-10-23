// queue.cpp
#include "queue.h"

template <typename T> Queue<T>::Queue() {
    head = nullptr;
    tail = nullptr;
}

template <typename T> Queue<T>::~Queue() {
    while (head != nullptr) {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}

template <typename T> bool Queue<T>::isEmpty() { return head == nullptr; }

template <typename T> T Queue<T>::front() { return head->data; }

template <typename T> void Queue<T>::enqueue(T val) {
    Node *newNode = new Node(val);
    if (tail == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

template <typename T> bool Queue<T>::dequeue() {
    if (head == nullptr) {
        std::cout << "\x1b[31mQueue underflow\x1b[0m" << std::endl;
        return false;
    }
    Node *temp = head;
    head = head->next;
    delete temp;
    if (head == nullptr) {
        tail = nullptr;
    }
    return true;
}

template <typename T> void Queue<T>::display() {
    Node *temp = head;
    while (temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}
