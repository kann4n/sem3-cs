// queue.cpp
#include "queue.h"

template <typename T> Queue<T>::Queue(int cap) {
    capacity = cap;
    arr = new T[capacity];
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
    return arr[0];
}

template <typename T> void Queue<T>::enqueue(T val) {
    if (isFull()) {
        std::cout << "Queue Overflow\n";
        return;
    }
    arr[size] = val;
    size++;
}

template <typename T> void Queue<T>::dequeue() {
    if (isEmpty()) {
        std::cout << "Queue Underflow\n";
        return;
    }
    for (int i = 1; i < size; i++) {
        arr[i - 1] = arr[i];
    }
    size--;
}

template <typename T> void Queue<T>::display() {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}
