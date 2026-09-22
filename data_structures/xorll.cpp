#include <cstdint>
#include <iostream>

using std::cout;
using std::endl;

class XORLinkedList {
private:
  struct Node {
    int data;
    Node *both;
  } *start;

  Node *XOR(Node *a, Node *b) const {
    uintptr_t xorptr =
        reinterpret_cast<uintptr_t>(a) ^ reinterpret_cast<uintptr_t>(b);
    return reinterpret_cast<Node *>(xorptr);
  }

public:
  XORLinkedList() { start = nullptr; }

  void insert_start(int data) {
    Node *new_node = new Node{data, XOR(nullptr, start)};

    if (start != nullptr) {
      // so that 2nd node can go back and forth
      start->both = XOR(new_node, start->both);
    }
    start = new_node;
  };

  void display() {
    Node *prev, *curr, *next;
    prev = nullptr;
    curr = start;
    next = nullptr;

    while (curr != nullptr) {
      cout << curr->data;
      next = XOR(prev, curr->both);
      if (next != nullptr)
        cout << " -> ";
      prev = curr;
      curr = next;
    }
    cout << endl;
  }
};

int main() {
  XORLinkedList xorll;
  xorll.insert_start(5);
  xorll.insert_start(4);
  xorll.insert_start(3);
  xorll.insert_start(2);
  xorll.insert_start(1);
  
  xorll.display();
  return 0;
}