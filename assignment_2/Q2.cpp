#include <iostream>
using namespace std;

void bubblesort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        bool swapped=0;
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                swapped=true;
            }
        }
        if(!swapped)break;
    }
}
int main(){
    int arr[20]={64,34,25,12,22,11,90};
    int n=7;
    bubblesort(arr,n);
    cout<<"Here is the sorted array:"<<endl;
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";

        return 0;
}