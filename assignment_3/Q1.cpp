#include <iostream>
using namespace std;

class Stack
{
int *arr;
int top;
int capacity;
public:
    Stack(int size){
        capacity=size;
        arr=new int[capacity];
        top=-1;
        cout<<"Stack created with size"<<capacity<<endl;
    }
    ~Stack(){
    delete[] arr;
    cout<<"Stack memory freed";}
    bool isEmpty(){
        return (top==-1);
    }

    bool isFull(){
        return(top==capacity-1);
    }
void push(int x){
    if(isFull()){
        cout<<"Stack Overflow";
    }
    else
    arr[++top]=x;
    cout<<x<<" pushed into the stack";
}

void pop(){
    if(isEmpty()){
        cout<<"Stack is Empty"<<endl;
    }
    else
    cout<<"Popped Element: "<<arr[top--]<<endl;
}
void display(){
    if(isEmpty())
    cout<<"Stack is empty.";
    else{
        cout<<"Elements(top to bottom)";
        for(int i=top;i>-1;i--)
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void peek(){
    if(isEmpty()){
        cout<<"Stack is Empty"<<endl;}
    else
    cout<<"Top element is:"<<arr[top]<<endl;
}

};
int main(){
    int size;
    cout<<"Enter the size of the stack: ";
    cin>>size;
    Stack s(size);

    int choice, value;

     while (true) {
        cout << "\n===== Stack Menu =====" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Check if Empty" << endl;
        cout << "4. Check if Full" << endl;
        cout << "5. Display Stack" << endl;
        cout << "6. Peek (Top element)" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

         switch (choice) {
            case 1:
                cout << "Enter element to push: ";
                cin >> value;
                s.push(value);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                cout << (s.isEmpty() ? "Stack is Empty." : "Stack is NOT Empty.") << endl;
                break;
            case 4:
                cout << (s.isFull() ? "Stack is Full." : "Stack is NOT Full.") << endl;
                break;
            case 5:
                s.display();
                break;
            case 6:
                s.peek();
                break;
            case 7:
                cout << "Exiting program." << endl;
                return 0;
            default:
                cout << "Invalid choice." << endl;
        }
    
    
    
    }


}

