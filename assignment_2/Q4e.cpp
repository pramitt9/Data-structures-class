#include <iostream>
#include<string.h>
using namespace std;


int main() {
    string str="Hello World";
    string ans="";

    for(int i=0;i<str.size();i++){
        char ch=str[i];
        if(ch>='A' && ch<='Z')
            ans+=str[i] +32 ;
        
        else
        ans+=str[i];
    }
    
    cout<<ans;
    return 0;
}
