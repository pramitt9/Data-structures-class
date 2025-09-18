#include <iostream>
#include <string>
using namespace std;

class Stack {
    int *arr;
    int top;
    int capacity;
public:
    Stack(int size) {
        capacity = size;
        arr = new int[capacity];
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
    void push(int x) {
        if (isFull()) {
            cout << "Stack Overflow" << endl;
        } else {
            arr[++top] = x;
        }
    }
    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow" << endl;
            return -1;
        } else {
            return arr[top--];
        }
    }
    int peek() {
        if (isEmpty()) {
            return -1;
        }
        return arr[top];
    }
};

int evaluatePostfix(string expr) {
    Stack st(expr.size());

    for (int i = 0; i < expr.size(); i++) {
        char c = expr[i];

        // Ignore spaces
        if (c == ' ') continue;

        if (c >= '0' && c <= '9') {
            st.push(c - '0');
        }
        else {
            int val2 = st.pop();
            int val1 = st.pop();
            int result = 0;

            switch (c) {
                case '+': result = val1 + val2; break;
                case '-': result = val1 - val2; break;
                case '*': result = val1 * val2; break;
                case '/': result = val1 / val2; break;
            }
            st.push(result);
        }
    }
    return st.pop();
}

int main() {
    string postfix;
    cout << "Enter postfix expression (single-digit operands, no spaces needed): ";
    cin >> postfix;

    int result = evaluatePostfix(postfix);
    cout << "Evaluated Result: " << result << endl;

    return 0;
}