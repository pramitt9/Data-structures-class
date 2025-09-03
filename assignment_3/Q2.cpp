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
};
string ReverseString(string str){
    int n=str.length();
    Stack s(n);
    for(int i=0;i<n;i++){
        s.push(str[i]);
    }
    string reversed="";
    while(!s.isEmpty()){
        reversed+=s.pop();
    }
    return reversed;
}
int main(){
    string input;
    cout<<"Input String: ";
    getline(cin,input);
    string output=ReverseString(input);
    cout<<"Reversed string: "<<output<<endl;
    return 0;
}