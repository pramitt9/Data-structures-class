#include <iostream>
using namespace std;
int main(){
    int a[50][50];
    int b[50][50];
    int r1,r2,c1,c2;
    cout<< "Enter the rows and columns of first matrix(rows then columns):";
    cin>>r1>>c1;
    cout<<"Enter the rows and columns of second matrix: ";
    cin>>r2>>c2;
    if(c1!=r2){
        cout<<"Not possible.Try again.(Columns of first need to be equal to rows of the second)";
        return 0;
    }
    int result[50][50];
    cout<<"enter the values for first matrix:";
    for (int i=0;i<r1;i++){
        for (int j=0;j<c1;i++){
            cin>>a[i][j];
        } 
    }
        cout<<"enter the values for second matrix:";
    for (int i=0;i<r2;i++){
        for (int j=0;j<c2;i++){
            cin>>b[i][j];
        } 
    }
    for (int i=0;i<r1;i++){
        for(int j=0;j<c2;j++){
            for(int k=0;k<c1;k++)
            result[i][j]=a[i][k]*b[k][j];
        }
    }
    cout<< "Resultant matrix will be:"<<endl;
    for(int i=0;i<r1;i++){
        for(int j=0;j<c2;j++)
       { cout<<result[i][j];}
       cout<<endl;
    }
    return 0;
}