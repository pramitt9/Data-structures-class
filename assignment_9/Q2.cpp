#include <bits/stdc++.h>
using namespace std;

template<typename T, typename Compare = std::less<T>>
class BinaryHeapPQ {
    vector<T> heap;
    Compare cmp;

    void siftUp(int i) {
        while (i > 0) {
            int p = (i - 1) / 2;
            if (!cmp(heap[p], heap[i])) break;
            swap(heap[p], heap[i]);
            i = p;
        }
    }

    void siftDown(int i) {
        int n = heap.size();
        while (true) {
            int l = 2*i + 1;
            int r = 2*i + 2;
            int best = i;
            if (l < n && cmp(heap[best], heap[l])) best = l;
            if (r < n && cmp(heap[best], heap[r])) best = r;
            if (best == i) break;
            swap(heap[i], heap[best]);
            i = best;
        }
    }

public:
    BinaryHeapPQ(Compare c = Compare()) : cmp(c) {}

    bool empty() const { return heap.empty(); }
    int size() const { return heap.size(); }

    void push(const T& val) {
        heap.push_back(val);
        siftUp(heap.size() - 1);
    }

    T top() const {
        if (heap.empty()) throw runtime_error("top() on empty heap");
        return heap.front();
    }

    void pop() {
        if (heap.empty()) throw runtime_error("pop() on empty heap");
        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty()) siftDown(0);
    }

    void buildFrom(const vector<T>& arr) {
        heap = arr;
        for (int i = heap.size()/2 - 1; i >= 0; --i) siftDown(i);
    }

    void removeAtIndex(int i) {
        if (i < 0 || i >= heap.size()) return;
        if (i == heap.size() - 1) {
            heap.pop_back();
            return;
        }
        heap[i] = heap.back();
        heap.pop_back();
        siftUp(i);
        siftDown(i);
    }

    void replaceTop(const T& val) {
        if (heap.empty()) {
            heap.push_back(val);
            return;
        }
        heap[0] = val;
        siftDown(0);
    }
};

int main() {
    BinaryHeapPQ<int, less<int>> pq;
    pq.push(5); pq.push(2); pq.push(9); pq.push(1);
    cout << "size: " << pq.size() << "\n";
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << "\n";

    BinaryHeapPQ<int, greater<int>> minpq;
    vector<int> data = {7,3,8,4,1};
    minpq.buildFrom(data);
    cout << "min top: " << minpq.top() << "\n";
}