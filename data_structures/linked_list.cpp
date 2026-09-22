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
      cout << current_node->data;
      if (current_node->nxt != nullptr)
        cout << " -> ";

      current_node = current_node->nxt;
    }
    cout << endl;
  }

  void display_verbose() {
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
    for (int i = 0; i < pos - 1 && current_node != nullptr; i++) {
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

  void rev() {
    Node *prev, *curr, *tmp;
    prev = nullptr;
    curr = start;
    tmp = nullptr;

    while (curr != nullptr) {
      tmp = curr->nxt;
      curr->nxt = prev;
      prev = curr;
      curr = tmp;
    }
    start = prev;
  }
};

int main() {
  LinkedList list;

  list.insert_start(1);
  list.insert_end(2);
  list.insert_end(4);
  list.insert_pos(3, 2);

  list.display();
  list.rev();
  list.display();
  return 0;
}
