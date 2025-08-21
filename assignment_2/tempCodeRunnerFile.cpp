#include<iostream>
using namespace std;

int BinarySearch(int arr[],int n,int key){
    int s=0;
    int e=n-1;
    int mid= s+(e-s)/2;
    while(s<=e){
    if(arr[mid]==key)
        return mid;
    
    if (arr[mid]>key)
        e=mid-1;
    
    if(arr[mid]<key)
        s=mid+1;
    
}
return -1;
}
int main(){
        int arr[100];
        int n;
        int key;
        cout<< "How many numbers do you want to  enter?"<<endl;
         cin>>n;
         cout<< "Enter the numbers: ";
         for(int i=0;i<n;i++)
         cin>>arr[i];
         cout<<endl;
         cout<<"Enter the number to be searched: ";
         cin>>key;
        int index= BinarySearch(arr,n,key);
         if(index=-1)
         cout<<"element not found";
         else
         cout<<"Element found at index(starts form 0) "<<index;

}
