#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    vector<int> nums = {2, 3, 2, 4, 3, 2};
    unordered_map<int, int> freq;

    for (int x : nums) freq[x]++;

    for (auto &p : freq)
        cout << p.first << " → " << p.second << " times" << endl;
}