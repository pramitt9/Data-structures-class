#include <iostream>
#include <string>
using namespace std;

class Stack {
    char *arr;
    int top;
    int capacity;
public:
    Stack(int size) {
        capacity = size;
        arr = new char[capacity];
        top = -1;
    }
    ~Stack() {
        delete[] arr;
    }
    bool isEmpty() {
        return (top == -1);
    }
    bool isFull() {
        return (top == capacity - 1);
    }
    void push(char x) {
        if (isFull()) {
            cout << "Stack Overflow" << endl;
        } else {
            arr[++top] = x;
        }
    }
    char pop() {
        if (isEmpty()) {
            cout << "Stack Underflow" << endl;
            return '\0';
        } else {
            return arr[top--];
        }
    }
    char peek() {
        if (isEmpty()) {
            return '\0';
        }
        return arr[top];
    }
};

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return -1;
}

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// check if operand (manual check)
bool isOperand(char c) {
    return ( (c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') );
}

// Infix → Postfix
string infixToPostfix(string infix) {
    Stack st(infix.size());
    string postfix = "";

    for (char c : infix) {
        if (isOperand(c)) {
            postfix += c;
        }
        else if (c == '(') {
            st.push(c);
        }
        else if (c == ')') {
            while (!st.isEmpty() && st.peek() != '(') {
                postfix += st.pop();
            }
            if (!st.isEmpty()) st.pop(); // pop '('
        }
        else if (isOperator(c)) {
            while (!st.isEmpty() && precedence(st.peek()) >= precedence(c)) {
                postfix += st.pop();
            }
            st.push(c);
        }
    }

    while (!st.isEmpty()) {
        postfix += st.pop();
    }

    return postfix;
}

int main() {
    string infix;
    cout << "Enter infix expression: ";
    cin >> infix;

    cout << "Postfix expression: " << infixToPostfix(infix) << endl;
    return 0;
}
