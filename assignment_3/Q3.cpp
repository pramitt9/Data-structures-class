#include <iostream>
#include <string>
using namespace std;

class Stack
{
char *arr;
int top;
int capacity;
public:
    Stack(int size){
        capacity=size;
        arr=new char[capacity];
        top=-1;
    }
    ~Stack(){
    delete[] arr;}

    bool isEmpty(){
        return (top==-1);
    }

    bool isFull(){
        return(top==capacity-1);
    }
void push(char c){
    if(isFull()){
        cout<<"Stack Overflow";
    }
    else
    arr[++top]=c;
}

char pop(){
    if(isEmpty()){
        cout<<"Stack is Empty"<<endl;
    }
    else
    return arr[top--];
}
char peek() {
        if (!isEmpty()) {
            return arr[top];
        }
        return '\0';
    }
};
bool ismatching(char open,char close){
    return(open=='('&&close==')')||(open=='{'&&close=='}')||(open=='['&&close==']');
}
bool balanced(string str){
    Stack s(str.length());
    for(char c:str){
        if(c=='('||c=='{'||c=='[')
        s.push(c);
        else if(c==')'||c=='}'||c==']'){
            if(s.isEmpty()||!ismatching(s.peek(),c)){
                return false;
            }
        }
         s.pop();
    }
    return s.isEmpty();

}
int main(){
    string str;
    cout<<"Enter the string: ";
    getline(cin,str);
    Stack s(str.length());
    if(balanced)
    cout<<"Balanced paranthesis.";
    else
    cout<<"Unbalanced paranthesis.";

    return 0;
}