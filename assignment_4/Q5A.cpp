#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class StackTwoQueues {
    queue<int> q1, q2;

public:
    void push(int x) {
        q1.push(x);
    }

    void pop() {
        if (q1.empty()) {
            cout << "Stack is Empty\n";
            return;
        }

        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }

        q1.pop();
        swap(q1, q2);
    }

    void top() {
        if (q1.empty()) {
            cout << "Stack is Empty\n";
            return;
        }

        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }

        cout << "Top element: " << q1.front() << endl;
        q2.push(q1.front());
        q1.pop();

        swap(q1, q2);
    }

    bool empty() {
        return q1.empty();
    }
};
int main() {
    StackTwoQueues s1;
    s1.push(10);
    s1.push(20);
    s1.top();
    s1.pop();
    s1.top();
    
}