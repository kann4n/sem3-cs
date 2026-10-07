#include <cctype>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iostream>

using std::cout;

const int MAX = 100;

class Stack {
  private:
    int stack[MAX] = {0};
    int top = -1;

  public:
    void push(int val) {
        if (top < MAX - 1) {
            stack[++top] = val;
        } else {
            cout << "stack overflow";
            exit(EXIT_FAILURE);
        }
    }

    int pop() {
        if (top < 0) {
            cout << "stack underflow\n";
            exit(EXIT_FAILURE);
        }
        return stack[top--];
    }
};

int evalpostfix(char* eq) {
    int i = 0;
    int op1, op2, result;
    Stack stack;
    while (eq[i] != '\0') {
        // all opr and ops sparated by space
        // skip space
        if (isspace(eq[i])) {
            i++;
            continue;
        }
        if (isdigit(eq[i])) {
            int num = 0;
            while (isdigit(eq[i])) {
                num = num * 10 + (eq[i] - '0'); // covert ascii digit to digit
                i++;
            }
            stack.push(num);
        } else {
            op1 = stack.pop();
            op2 = stack.pop();
            char opr = eq[i];
            switch (opr) {
            case '+':
                result = op2 + op1;
                break;
            case '-':
                result = op2 - op1;
                break;
            case '*':
                result = op2 * op1;
                break;
            case '/':
                if (op1 == 0) {
                    cout << "zero division error\n";
                    exit(EXIT_FAILURE);
                }
                result = op2 / op1;
                break;
            case '^':
                result = pow(op2, op1);
                break;
            default:
                cout << "invaild or unsupported opr(" << eq[i] << ")\n";
                exit(EXIT_FAILURE);
            }
            stack.push(result);
            i++;
        }
    }
    return stack.pop();
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Usage: " << argv[0] << " <postfix expression>\n";
        cout << "Example: " << argv[0] << " \"1 2 3 + +\"\n";
        return 1;
    }

    char eq[MAX] = "";
    for (int i = 1; i < argc; i++) {
        strcat(eq, argv[i]);
        strcat(eq, " ");
    }
    cout << eq << std::endl;
    int r = evalpostfix(eq);
    cout << "=> " << r << "\n";
    return 0;
}
