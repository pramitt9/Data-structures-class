#include <iostream>
using namespace std;

class TriDiagonal {
    int n;   // size of matrix (n x n)
    int *A;  // 1D array to store nonzero elements

public:
    TriDiagonal(int n) {
        this->n = n;
        A = new int[3*n - 2];
    }

  
    void set(int i, int j, int x) {
        if (i - j == 0) 
            A[i-1] = x;
        else if (i - j == 1) 
            A[n + (i-2)] = x;
        else if (i - j == -1) 
            A[2*n - 1 + (i-1)] = x;
    }

    // Get value at (i,j)
    int get(int i, int j) {
        if (i - j == 0)  
            return A[i-1];
        else if (i - j == 1)
            return A[n + (i-2)];
        else if (i - j == -1)
            return A[2*n - 1 + (i-1)];
        else
            return 0;
    }


    void display() {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cout << get(i, j) << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    TriDiagonal t(5);

    t.set(1,1,1); t.set(2,2,2); t.set(3,3,3); t.set(4,4,4); t.set(5,5,5);

    t.set(1,2,6); t.set(2,3,7); t.set(3,4,8); t.set(4,5,9);

    t.set(2,1,11); t.set(3,2,12); t.set(4,3,13); t.set(5,4,14);

    cout << "Tri-diagonal matrix:" << endl;
    t.display();
}