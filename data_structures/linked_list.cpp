#include <iostream>

using std::cout;
using std::endl;

class LinkedList {
private:
  struct Node {
    int data;
    Node *nxt;
  } *start;

public:
  LinkedList() { start = nullptr; }

  void display() {
    Node *current_node = start;
    while (current_node != nullptr) {
      cout << endl;
      cout << "=> " << current_node << endl;
      cout << "   data = " << current_node->data << endl;
      cout << "   nxt  => " << current_node->nxt << endl;

      current_node = current_node->nxt;
    }
  }

  void insert_start(int data) {
    Node *new_node = new Node;
    new_node->data = data;
    new_node->nxt = start;
    start = new_node;
  }

  void insert_end(int data) {
    Node *new_node = new Node;
    new_node->data = data;
    new_node->nxt = nullptr;
    
    if (start == nullptr) {
      start = new_node;
      return;
    }
    
    // gets the end of chain
    Node *current_node = start;
    while (current_node->nxt != nullptr) {
      current_node = current_node->nxt;
    }
    current_node->nxt = new_node;
  }
};

int main() {
  LinkedList list;
  list.insert_end(3);
  list.insert_end(2);
  list.insert_end(1);

  list.display();
  return 0;
}
