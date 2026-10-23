// queue.cpp
#include "queue.h"

template <typename T> Queue<T>::Queue(int cap) {
    capacity = cap;
    arr = new T[capacity];
    head = 0;
    size = 0;
}

template <typename T> Queue<T>::~Queue() { delete[] arr; }

template <typename T> bool Queue<T>::isEmpty() { return size <= 0; }

template <typename T> bool Queue<T>::isFull() { return size >= capacity; }

template <typename T> T Queue<T>::front() {
    if (isEmpty()) {
        std::cout << "Queue is empty\n";
        return -1;
    }
    return arr[head];
}

template <typename T> void Queue<T>::enqueue(T val) {
    if (isFull()) {
        std::cout << "\x1b[31mQueue Overflow\x1b[0m\n";
        return;
    }
    int idx = (head + size) % capacity;
    arr[idx] = val;
    size++;
}

template <typename T> void Queue<T>::dequeue() {
    if (isEmpty()) {
        std::cout << "\x1b[31mQueue Underflow\x1b[0m\n";
        return;
    }
    head = (head + 1) % capacity;
    size--;
}

template <typename T> void Queue<T>::display() {
    for (int i = 0; i < size; i++) {
        int idx = (head + i) % capacity;
        std::cout << arr[idx] << " ";
    }
    std::cout << "\n";
}
