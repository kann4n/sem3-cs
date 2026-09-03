#include "array.cpp"

int main() {
  int choice, quit = 0;
  int pos, ele, lb, ub;
  bool res;
  array<int> arr;
  while (!quit) {
    cout << "\033[2J Menu" << endl;
    cout << endl;
    cout << " 1.create array with user input" << endl;
    cout << " 2.create a default array" << endl;
    cout << " 3.insertion at beginning" << endl;
    cout << " 4.insertion at a specific position" << endl;
    cout << " 5.Insertion at end" << endl;
    cout << " 6.Deletion from beginning" << endl;
    cout << " 7.Deletion at specific position" << endl;
    cout << " 8.Deletion from end" << endl;
    cout << " 9.Display the array elements" << endl;
    cout << "10.Quit" << endl;
    cout << endl;
    cout << "Enter your choice ";
    cin >> choice;
    switch (choice) {
    case 1:
    case 2:
      // Set up bounds first, then read that many elements.
      cout << "lower bound" << endl;
      cin >> lb;
      cout << "upper bound" << endl;
      cin >> ub;
      res = arr.setLB(lb) | arr.setUB(ub);
      if (!res) {
        cout << "error creating array" << endl;
        break;
      }
      if (choice == 1)
        arr.create();
      else
        arr.create_default(arr.getUB() - arr.getLB());
      break;
    case 3:
      cout << "Enter the element" << endl;
      cin >> ele;
      arr.insertAtBeg(ele);
      break;
    case 4:
      cout << "enter the position( " << arr.getLB() << ", " << arr.getUB()
           << " )";
      cin >> pos;
      cout << "Enter the element" << endl;
      cin >> ele;
      arr.insertAtPos(pos, ele);
      break;
    case 5:
      cout << "Enter the element" << endl;
      cin >> ele;
      arr.insertAtEnd(ele);
      break;
    case 6:
      arr.deleteAtBeg();
      break;
    case 7:
      cout << "enter the position( " << arr.getLB() << ", " << arr.getUB()
           << " )";
      cin >> pos;
      arr.deleteAtPos(pos);
      cout << "element deleted" << endl;
      break;
    case 8:
      arr.deleteAtEnd();
      break;
    case 9:
      cout << arr; // invokes the overloaded operator <<
      break;
    case 10:
      quit = true;
      break;
    default:
      cout << "Invalid entry" << endl;
    }
  }
  return 0;
}
