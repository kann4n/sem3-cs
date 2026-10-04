#include <iostream>

const int MAX = 100;

class Stack {
	private:
		int arr[MAX];
		int top;
	public:
		Stack() {
			top = -1;
		}
		void put(int val) {
			arr[++top] = val;	
		}
		int pop() {
			if (top <= -1) {
				// do nothing
			} else {
				int tmp = arr[top--];
				return tmp;
			}
		}
		void display() {
			for (int i = top; i >= 0; i--) {
				std::cout << "| "<< arr[i] << " |\n";
				if (i == 0) {
					std::cout << "|_____|\n";
				}
			}
		}
};


int main() {
	Stack stack;
	for (int i = 0; i < 10; i++) {
		stack.put(i*i);
	}
	stack.display();
	stack.pop();
	stack.pop();
	std::cout << "\n";
	stack.display();
	return 0;
}
