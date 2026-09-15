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
    Node *new_node = new Node{data, start};
    start = new_node;
  }

  void insert_end(int data) {
    Node *new_node = new Node{data, nullptr};

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

  void insert_pos(int data, int pos) {
    if (pos < 0) {
      cout << "invaild position" << endl;
      return;
    }
    if (pos == 0) {
      insert_start(data);
      return;
    }
    // get to just before pos
    Node *current_node = start;
    for (int i = 1; i < pos - 1 && current_node != nullptr; i++) {
      current_node = current_node->nxt;
    }
    // append if pos > num of nodes
    if (current_node == nullptr) {
      insert_end(data);
      return;
    }
    Node *new_node = new Node{data, current_node->nxt};
    current_node->nxt = new_node;
  }
};

int main() {
  LinkedList list;

  list.insert_start(1);
  list.insert_end(3);
  list.insert_pos(2, 1);

  list.display();
  return 0;
}
