#include "queue.cpp"
#include <iostream>

using std::cout;
using std::endl;

#define CAPACITY 100

int main() {
    Queue<int> q(CAPACITY);
    bool running = true;
    while (running) {
        cout << "\nMenu" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl << endl;

        cout << "input > ";
        int choice, n, value;

        if (!(std::cin >> choice)) {
            cout << "Invalid input - use only numbers" << endl;
            running = false;
            continue;
        }
        switch (choice) {
        case 1:
            cout << "\thow many elements > ";
            if (!(std::cin >> n)) {
                cout << "Invalid input - use only numbers" << endl;
                running = false;
                continue;
            }
            for (int i = 0; i < n; i++) {
                cout << "\tvalue > ";
                if (!(std::cin >> value)) {
                    cout << "Invalid input - use only numbers" << endl;
                    running = false;
                    continue;
                }
                q.enqueue(value);
            }
            break;
        case 2:
            cout << "\thow many elements to dequeue > ";
            if (!(std::cin >> n)) {
                cout << "Invalid input - use only numbers" << endl;
                continue;
            }
            for (int i = 0; i < n; i++) {
                q.dequeue();
            }
            break;
        case 3:
            cout << "\n\tQueue: ";
            q.display();
            break;
        case 4:
            cout << "\tExiting..." << endl << endl;
            running = false;
            break;
        default:
            cout << "\n\tInvalid choice" << endl;
            break;
        }
    }
    return 0;
}
