#include <cctype>
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

    int peek() {
        if (top < 0)
            return -99999;
        return stack[top];
    }
};

int prec(int c) {
    if (c == '^')
        return 3;
    if (c == '*' || c == '/')
        return 2;
    if (c == '-' || c == '+')
        return 1;
    return 0;
}

void infixToPostfix(char* eq, char* out) {
    int i = 0, j = 0;
    Stack s;
    while (eq[i] != '\0') {
        if (isdigit(eq[i]) || isalpha(eq[i]) || isspace(eq[i])) {
            out[j++] = eq[i];
            if (!isalnum(eq[i + 1])) {
                out[j++] = ' ';
            }
        } else if (eq[i] == '(') {
            s.push('(');
        } else if (eq[i] == ')') {
            while (s.peek() != '(' && s.peek() != -99999) {
                out[j++] = s.pop();
            }
            s.pop();
        } else {
            while (s.peek() != '(' && s.peek() != -99999 &&
                   (prec(s.peek()) > prec(eq[i]) ||
                    (prec(s.peek()) == prec(eq[i]) && eq[i] != '^'))) {
                out[j++] = s.pop();
                out[j++] = ' ';
            }
            s.push(eq[i]);
        }
        i++;
    }
    while (s.peek() != -99999) {
        out[j++] = s.pop();
    }
    if (j > 0 && out[j - 1] == ' ') {
        j--; // trim trailing space
    }
    out[j] = '\0';
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Usage: " << argv[0] << " <infix expression>\n";
        cout << "Example: " << argv[0] << " \"(1 + 2) + 3\"\n";
        return 1;
    }

    char eq[MAX] = "";
    char out[MAX] = "";
    for (int i = 1; i < argc; i++) {
        strcat(eq, argv[i]);
        strcat(eq, " ");
    }
    cout << eq << std::endl;
    infixToPostfix(eq, out);
    cout << "=> " << out << "\n";
    return 0;
}
