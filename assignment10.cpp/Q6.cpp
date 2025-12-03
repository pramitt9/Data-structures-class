#include <iostream>
#include <unordered_set>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node(int v) : val(v), left(NULL), right(NULL) {}
};

bool checkDuplicates(Node* root, unordered_set<int>& s) {
    if (!root) return false;
    if (s.count(root->val)) return true;
    s.insert(root->val);
    return checkDuplicates(root->left, s) || checkDuplicates(root->right, s);
}

int main() {
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(7);
    root->left->left = new Node(3);

    unordered_set<int> s;
    cout << (checkDuplicates(root, s) ? "Duplicates Found" : "No Duplicates");
}