#include<iostream>
#include<cstring>
using namespace std;

void deletevowels(char s1[]){
    int i=0;
    while(s1[i]!='\0'){
        if(s1[i]== 'a' || s1[i]== 'e' || s1[i]== 'i' || s1[i]== 'o' || s1[i]== 'u' ||
            s1[i]=='A' || s1[i]=='E' || s1[i]=='I' || s1[i]=='O' || s1[i]=='U'){
            int j = i;
            while (s1[j] != '\0') {
                s1[j] = s1[j+1];
                j++;
            }
        }
        else
        i++;
    }
}
int main(){
    char s1[]="Hello World";
    cout<<"Before deletion: "<<endl<<s1;
    deletevowels(s1);
    cout<<"String After Deletion: "<<endl<<s1;
}