#include <iostream>
using namespace std;

class Queue {
    int *arr;
    int front, rear, capacity;

public:
    Queue(int size) {
        capacity = size;
        arr = new int[capacity];
        front = -1;
        rear = -1;
    }

    ~Queue() {
        delete[] arr;
    }

    bool isEmpty() {
        return (front == -1 || front > rear);
    }

    bool isFull() {
        return (rear == capacity - 1);
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue Overflow! Cannot insert " << x << endl;
            return;
        }
        if (front == -1) front = 0; // first element
        arr[++rear] = x;
        cout << x << " enqueued successfully.\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow! Nothing to delete.\n";
            return;
        }
        cout << arr[front] << " dequeued successfully.\n";
        front++;
    }

    void peek() {
        if (isEmpty()) {
            cout << "Queue is empty. Nothing at front.\n";
        } else {
            cout << "Front element = " << arr[front] << endl;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int size, choice, value;
    cout << "Enter the size of the queue: ";
    cin >> size;

    Queue q(size);

    while (true) {
        cout << "\n=== Queue Menu ===\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek (Front element)\n";
        cout << "4. Check if Empty\n";
        cout << "5. Check if Full\n";
        cout << "6. Display\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                q.enqueue(value);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.peek();
                break;
            case 4:
                cout << (q.isEmpty() ? "Queue is empty.\n" : "Queue is not empty.\n");
                break;
            case 5:
                cout << (q.isFull() ? "Queue is full.\n" : "Queue is not full.\n");
                break;
            case 6:
                q.display();
                break;
            case 7:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } ;

    return 0;
}
