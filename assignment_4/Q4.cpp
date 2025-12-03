#include <iostream>
#include <queue>
#include <string>
using namespace std;

void firstNonRepeating(string s) {
    queue<char> q;
    int freq[26] = {0};

    for (int i = 0; i < s.length(); i++) {
        char ch = s[i];
        freq[ch - 'a']++;
        q.push(ch);

       
        while (!q.empty() && freq[q.front() - 'a'] > 1) {
            q.pop();
        }
        if (q.empty())
            cout << -1 << " ";
        else
            cout << q.front() << " ";
    }
    cout << endl;
}

int main() {
    string str;
    cout << "Enter string: ";
    cin >> str;

    firstNonRepeating(str);

    return 0;
}