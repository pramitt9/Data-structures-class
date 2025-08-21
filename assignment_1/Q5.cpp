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
    int rowsum=0;
    for (int j=0;j<c1;j++){
    rowsum+=a[i][j];}
    cout<< "Sum of all number in row"<<i<<"is: "<<rowsum;
}
for(int j=0;j<c1;j++){
    int colsum=0;
    for(int i=0;i<r1;i++){
        colsum+=a[i][j];
    }
    cout<<"Sum of all numbers in column"<<j<<"is: "<<colsum;
}


return 0;
}