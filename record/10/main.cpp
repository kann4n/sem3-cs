#include "queue.h"
#include <iostream>

#define CAPACITY 5

int main() {
    Queue q(CAPACITY);

    std::cout << "Created Queue with capacity: " << CAPACITY << "\n\n";
    
    std::cout << "Enqueueing 5 elements [1, 2, 3, 4, 5]" << "\n";
    for (int i = 0; i < 5; i++) {
        q.enqueue(i + 1);
    }
    std::cout << "\nDisplaying current Queue: ";
    q.display();
    std::cout << "Queue is now " << (q.isFull() ? "full\n" : "not full\n");

    std::cout << "Filling Queue to capacity" << "\n";
    for (int i = 5; i < CAPACITY; i++) {
        q.enqueue(i + 1);
    }

    std::cout << "\nDisplaying current Queue: ";
    q.display();
    std::cout << "Queue is now " << (q.isFull() ? "full\n" : "not full\n");

    std::cout << "\nChecking Queue overflows" << "\n";
    std::cout << "Enqueueing " << CAPACITY + 1 << "th element" << "\n";
    q.enqueue(CAPACITY + 1);

    std::cout << "Dequeueing " << CAPACITY - 2 << " elements" << "\n";
    for (int i = 0; i < CAPACITY - 2; i++) {
        q.dequeue();
    }

    std::cout << "\nDisplaying current Queue: ";
    q.display();
    std::cout << "Queue is now " << (q.isEmpty() ? "empty\n" : "not empty\n");

    std::cout << "Dequeueing remaining elements" << "\n";
    while (!q.isEmpty()) {
        q.dequeue();
    }
    std::cout << "Queue is now " << (q.isEmpty() ? "empty\n" : "not empty\n");

    std::cout << "Checking Queue underflows" << "\n";
    q.dequeue();

    return 0;
}