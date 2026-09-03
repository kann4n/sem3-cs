#include <iostream>
#include <ostream>

#define CAP 256

using std::ostream;
using std::cout;
using std::cin;
using std::endl;

template <class T> class array {
private:
  int lb, ub;
  T arr[CAP];

public:
  array();

  int setLB(int x);
  int setUB(int x);

  int getLB();
  int getUB();

  // creates default array of like (0, 1, 2, 3...) from lb of size n or till ub
  void create_default(int n);
  // ask users input for creating array
  void create();

  void insertAtBeg(T val);
  void insertAtEnd(T val);
  void insertAtPos(T val, int pos);

  void deleteAtBeg();
  void deleteAtEnd();
  void deleteAtPos(int pos);

  template <class U> friend ostream &operator<<(ostream &os, const array<U> &m);
};
