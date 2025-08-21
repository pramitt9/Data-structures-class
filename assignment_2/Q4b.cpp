#include<iostream>
#include<cstring>
using namespace std;
void reversestring(char *s) {
    char *start = s;
    char *end = s + strlen(s) - 1;

    while (start < end) {
        swap(*start, *end);
        start++;
        end--;
    }
}
int main(){
    char s1[]=" Hello World";
    reversestring(s1);
    cout<<s1;
    return 0;

}