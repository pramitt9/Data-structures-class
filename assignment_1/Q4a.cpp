#include <iostream>
using namespace std;
void reverse(int arr[],int n){
    for(int i=0,j=n-1;i<j;i++,j--){
        swap(arr[i],arr[j]);
    }
}
int main(){
        int arr[100];
        int n;
        cout<< "How many numbers do you want to  enter?"<<endl;
         cin>>n;
         cout<< "Enter the numbers: ";
         for(int i=0;i<n;i++){
         cin>>arr[i];}
         reverse(arr,n);
         cout<<"Reversed :";
         for (int i=0;i<n;i++){
            cout<<arr[i]<<" ";
         }
}