#include "array.h"
#include <iostream>
#include <ostream>

template <class T> array<T>::array() {
  lb = 0;
  ub = -1;
  for (int i = lb; i <= ub; i++)
    arr[i] = 0;
}

template <class T> int array<T>::setLB(int x) {
  if (x < 0 || x > ub) {
    cout << "Lower Bound must be > 0" << endl;
    return false;
  }
  lb = x;
  return true;
}

template <class T> int array<T>::setUB(int x) {
  if (x < lb || x >= CAP) {
    cout << "UPPER Bound must be < Maximum capacity" << endl;
    return false;
  }
  ub = x;
  return true;
}

template <class T> int array<T>::getLB() { return lb; }
template <class T> int array<T>::getUB() { return ub; }

template <class T> void array<T>::create_default(int n) {
  if (ub < 0)
    setUB(0);
  int counter = 0;
  for (int i = lb; i < n; i++) {
    if (i > ub)
      break;
    arr[i] = counter++;
  }
}

template <class T> void array<T>::create() {
  cout << "Press Enter after each input. avoid adding spaces";
  for (int i = lb; i <= ub; i++) {
    cout << "\n array[" << i << "]" << " = ";
    cin >> arr[i];
  }
}

template <class T> void array<T>::insertAtBeg(T val) {
  setUB(ub + 1);
  for (int i = ub; i > lb; i--) {
    arr[i] = arr[i - 1];
  }
  arr[lb] = val;
}

template <class T> void array<T>::insertAtEnd(T val) {
  setUB(ub + 1);
  arr[ub] = val;
}

template <class T> void array<T>::insertAtPos(T val, int pos) {
  if (pos < lb || pos > ub)
    return;
  setUB(ub + 1);
  for (int i = ub; i > pos; i--) {
    arr[i] = arr[i - 1];
  }
  arr[pos] = val;
}

template <class T> void array<T>::deleteAtBeg() {
  for (int i = lb; i < ub; i++) {
    arr[i] = arr[i + 1];
  }
  setUB(ub - 1);
}

template <class T> void array<T>::deleteAtEnd() {
  if (ub < 0)
    return;
  setUB(ub - 1);
}

template <class T> void array<T>::deleteAtPos(int pos) {
  if (pos < lb || pos > ub)
    return;
  for (int i = pos; i < ub; i++) {
    arr[i] = arr[i + 1];
  }
  setUB(ub - 1);
}

template <class U> ostream &operator<<(ostream &os, const array<U> &a) {
  int counter = 0;
  os << "[ ";
  for (int i = a.lb; i <= a.ub; i++) {
    os << a.arr[i];
    if (counter % 2 != 0)
      os << ", ";
    counter++;
  }
  os << " ]";
  return os;
}
