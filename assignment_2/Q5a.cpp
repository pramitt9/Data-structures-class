#include <iostream>
using namespace std;



class Diagonal {
    int n;
    int *A;
public:
    Diagonal(int n) {
        this->n = n;
        A = new int[n];
    }
    void set(int i, int j, int x) {
        if (i == j) A[i-1] = x;
    }
    int get(int i, int j) {
        if (i == j) return A[i-1];
        return 0;
    }
};
int main(){
    Diagonal a(3);
    a.set(1,1,5);
    a.set(2,2,8);
    a.set(3,3,10);
    cout << a.get(2,2) << endl;
    cout << a.get(1,3) << endl;
    return 0;
}