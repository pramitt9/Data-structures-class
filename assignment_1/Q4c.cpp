#include<iostream>
using namespace std;
int main(){
   int a[50][50];
    int r1,c1;
    cout<< "Enter the rows and columns(rows then columns):";
    cin>>r1>>c1;
       int result[50][50];
    cout<<"enter the values for the matrix:";
    for (int i=0;i<r1;i++){
        for (int j=0;j<c1;j++){
            cin>>a[i][j];
        } 
    }
    for(int i=0;i<r1;i++){
        for(int j=0;j<c1;j++){
            result[j][i]=a[i][j];
        }
    }
    cout<<"The transpose of the matrix: "<<endl;
    for(int i=0;i<c1;i++){
        for(int j=0;j<r1;j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}