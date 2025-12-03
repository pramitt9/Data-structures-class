#include <bits/stdc++.h>
using namespace std;

template<typename T, typename Compare>
void heapify(vector<T>& a, int n, int i, Compare compare) {
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if (l < n && compare(a[l], a[largest])) largest = l;
    if (r < n && compare(a[r], a[largest])) largest = r;
    if (largest != i) {
        swap(a[i], a[largest]);
        heapify(a, n, largest, compare);
    }
}

template<typename T, typename Compare>
void heapsort(vector<T>& a, Compare compare) {
    int n = a.size();
    for (int i = n/2 - 1; i >= 0; --i)
        heapify(a, n, i, compare);
    for (int end = n - 1; end > 0; --end) {
        swap(a[0], a[end]);
        heapify(a, end, 0, compare);
    }
}

int main() {
    vector<int> v = {4, 10, 3, 5, 1, 12, 7};

    vector<int> a = v;
    heapsort(a, greater<int>());
    cout << "Ascending: ";
    for (int x : a) cout << x << ' ';
    cout << '\n';

    vector<int> b = v;
    heapsort(b, less<int>());
    cout << "Descending: ";
    for (int x : b) cout << x << ' ';
    cout << '\n';

    return 0;
}