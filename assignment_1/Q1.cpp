#include <iostream>
using namespace std;
void Display(int arr[],int n){ 
     for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }cout<< endl;}
void insert(int arr[],int& n, int x, int pos){
        for (int i=n-1;i>=pos;i--){
            arr[i+1]=arr[i];
        }
        arr[pos]=x;
        n++;
    }
void deleteattpos(int arr[],int &n,int pos){
    for (int i=pos;i<n-1;i++){
        arr[i]=arr[i+1];
    }
    n--;
}
int linearsearch(int arr[],int n,int key){
    for(int i=0;i<=n-1;i++){
        if(arr[i]==key){
            return i;
        }
    }
    return -1;
}

int main(){
    int arr[100];
    int n;
    int op;
    while(true){

           cout << "\n---Menu---" << endl
             << "1. CREATE" << endl
             << "2. DISPLAY" << endl
             << "3. INSERT" << endl
             << "4. DELETE" << endl
             << "5. LINEAR SEARCH" << endl
             << "6. EXIT" << endl;
   cin>>op;
    switch(op){
    case 1:{
         cout<< "How many numbers do you want to  enter?"<<endl;
         cin>>n;
         cout<< "Enter the numbers: ";
         for(int i=0;i<n;i++){
         cin>>arr[i];}
    
    break;}
    case 2:{
        Display(arr,n);
        break;}
    case 3:{
         int pos;
         int x;
         cout<<"enter the position(starting from 1): ";
         cin>>pos;
         if(pos < 1 || pos > n+1){
    cout << "Invalid position!" << endl;
    break;
}
         cout<<"Enter the number to be inserted";
         cin>>x;
         insert(arr,n,x,pos-1);
         cout<<"After insertion: ";
         Display(arr,n);
         break;}
    case 4:{
    cout<<"Enter the number to be deleted:";
    int key;
    cin>>key;
    int pos=linearsearch(arr,n,key);
    if(pos==-1){
        cout<<"Element not present";
    }
    else{
        deleteattpos(arr,n,pos);
        cout<<"After deletion:";
        Display(arr,n);
    }
    break;}
    case 5:{
    cout<<"Enter the number to be searched: ";
    int key;
    cin>>key;
    int pos=linearsearch(arr,n,key);
    if(pos==-1)
    cout<<"element not found";
    else
    cout<<"Element found at: "<<pos+1;
    break;}
    
case 6:{
    cout << "Thank you :) - Exiting now." << endl;
    return 0;
    break;
}
    }
   
    }
    return 0;
}