#include <bits/stdc++.h>
using namespace std;

const int MAX_CHAR = 256;


void sortString(string &s) {
    int charCount[MAX_CHAR] = {0};

    for (int i = 0; i < s.length(); i++) {
        charCount[(unsigned char)s[i]]++;
    }

    for (int i = 0; i < MAX_CHAR; i++) {
        for (int j = 0; j < charCount[i]; j++) {
            cout << (char)i;
        }
    }
}

int main() {
    string s = "HelloWorld32450968!";    
    sortString(s);    
    return 0;
}