#include <iostream>
using namespace std;
void bubblesort(int arr[],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}
void removeduplicates(int arr[],int& n){
    for (int i=0;i<n-1;i++){
        if(arr[i]==arr[i+1]){
            for(int j=i+1;j<n;j++)
            {arr[j-1]=arr[j];}
            n--;
            i--;
        }
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
         cout<<"Sorted version of array: ";
         bubblesort(arr,n);
         for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
         }
         cout<<endl;
         removeduplicates(arr,n);
         cout<<"Array with only unique elements:";
         for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
         }
         return 0;
        }