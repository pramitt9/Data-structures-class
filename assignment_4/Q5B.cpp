#include <iostream>
#include <queue>
#include <stack>
using namespace std;
class StackOneQueue {
    queue<int> q;

public:
    void push(int x) {
        int size = q.size();
        q.push(x);
        
        for (int i = 0; i < size; i++) {
            q.push(q.front());
            q.pop();
        }

    }

    void pop() {
        if (q.empty()) {
            cout << "Stack is Empty!\n";
            return;
        }
        q.pop();
    }

    void top() {
        if (q.empty()) {
            cout << "Stack is Empty!\n";
            return;
        }
        cout << "Top element: " << q.front() << endl;
    }

    bool empty() {
        return q.empty();
    }
};
int main() {



    StackOneQueue s2;
    s2.push(100);
    s2.push(200);
    s2.top();
    s2.pop();
    s2.top();

    return 0;
}