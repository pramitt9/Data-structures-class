#include <iostream>
#include <string.h>
using namespace std;
void concat(char s1[],char s2[]){
   int i=strlen(s1);
   int j=0;
    while(s2[j]!='\0'){
        s1[i++]=s2[j++];

    }
    s1[i]='\0';

}

int main(){
    char s1[50]="Hello";
    char s2[]=" World";
    concat(s1,s2);
    for(int i=0;s1[i]!='\0';i++){
        cout<<s1[i];
    }
    return 0;
}
