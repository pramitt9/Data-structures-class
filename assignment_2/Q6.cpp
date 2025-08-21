#include <iostream>
using namespace std;

struct Element {
    int row, col, val;
};

class SparseMatrix {
    int rows, cols, num;
    Element *ele;

public:
    SparseMatrix(int r=0, int c=0, int n=0) {
        rows = r; cols = c; num = n;
        if (n > 0)
            ele = new Element[n];
        else
            ele = nullptr;
    }

    void read() {
        cout << "Enter dimensions (rows cols): ";
        cin >> rows >> cols;
        cout << "Enter number of non-zero elements: ";
        cin >> num;
        ele = new Element[num];

        cout << "Enter row col value:\n";
        for (int i = 0; i < num; i++) {
            cin >> ele[i].row >> ele[i].col >> ele[i].val;
        }
    }

    void display() {
        cout << "Row Col Val\n";
        for (int i = 0; i < num; i++) {
            cout << ele[i].row << " " << ele[i].col << " " << ele[i].val << endl;
        }
    }

    SparseMatrix transpose() {
        SparseMatrix t(cols, rows, num);
        for (int i = 0; i < num; i++) {
            t.ele[i].row = ele[i].col;
            t.ele[i].col = ele[i].row;
            t.ele[i].val = ele[i].val;
        }
        return t;
    }

    SparseMatrix add(SparseMatrix &s2) {
        if (rows != s2.rows || cols != s2.cols) {
            cout << "Addition not possible!" << endl;
            return SparseMatrix();
        }

        SparseMatrix sum(rows, cols, num + s2.num);
        int i=0, j=0, k=0;

        while (i < num && j < s2.num) {
            if (ele[i].row < s2.ele[j].row ||
               (ele[i].row == s2.ele[j].row && ele[i].col < s2.ele[j].col)) {
                sum.ele[k++] = ele[i++];
            } else if (s2.ele[j].row < ele[i].row ||
                      (ele[i].row == s2.ele[j].row && s2.ele[j].col < ele[i].col)) {
                sum.ele[k++] = s2.ele[j++];
            } else { // same position
                sum.ele[k] = ele[i];
                sum.ele[k++].val = ele[i++].val + s2.ele[j++].val;
            }
        }

        while (i < num) sum.ele[k++] = ele[i++];
        while (j < s2.num) sum.ele[k++] = s2.ele[j++];

        sum.num = k;
        return sum;
    }

    SparseMatrix multiply(SparseMatrix &s2) {
        if (cols != s2.rows) {
            cout << "Multiplication not possible!" << endl;
            return SparseMatrix();
        }

        SparseMatrix result(rows, s2.cols, rows * s2.cols);
        int k = 0;

        for (int i = 0; i < num; i++) {
            for (int j = 0; j < s2.num; j++) {
                if (ele[i].col == s2.ele[j].row) {
                    int r = ele[i].row;
                    int c = s2.ele[j].col;
                    int v = ele[i].val * s2.ele[j].val;

                    bool found = false;
                    for (int x = 0; x < k; x++) {
                        if (result.ele[x].row == r && result.ele[x].col == c) {
                            result.ele[x].val += v;
                            found = true;
                            break;
                        }
                    }
                    if (!found) {
                        result.ele[k].row = r;
                        result.ele[k].col = c;
                        result.ele[k].val = v;
                        k++;
                    }
                }
            }
        }
        result.num = k;
        return result;
    }
};

int main() {
    SparseMatrix s1, s2;
    cout << "Matrix 1:\n";
    s1.read();
    cout << "Matrix 2:\n";
    s2.read();

    cout << "\nMatrix 1 (triplets):\n"; s1.display();
    cout << "\nMatrix 2 (triplets):\n"; s2.display();

    cout << "\nTranspose of Matrix 1:\n";
    SparseMatrix t = s1.transpose();
    t.display();

    cout << "\nAddition:\n";
    SparseMatrix sum = s1.add(s2);
    sum.display();

    cout << "\nMultiplication:\n";
    SparseMatrix prod = s1.multiply(s2);
    prod.display();

    return 0;
}
