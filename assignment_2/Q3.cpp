#include<iostream>
using namespace std;

int findmissing(int arr[],int n){
    int d;
    int firstdiff=arr[1]-arr[0];
    int lastdiff=arr[n-1]-arr[n-2];
    int avgdiff=(arr[n-1]-arr[0])/2;
    if(firstdiff==lastdiff)
    d=firstdiff;
    else if(firstdiff==avgdiff)
    d=firstdiff;
    else
    d=lastdiff;
    //sum with n+1 terms
    long long expectedsum=(2LL*arr[0]+n*d)*(n+1)/2;
    long long sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    return expectedsum-sum;

} 
int main(){
     int arr[] = {2, 4, 8, 10, 12, 14};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Missing number is: " << findmissing(arr, n) << endl;

    return 0;

}