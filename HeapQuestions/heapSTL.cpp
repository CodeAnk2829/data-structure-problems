#include <bits/stdc++.h>
using namespace std;
// Print elements of heap
template <typename T> void printQueue(T& pq) {
    while(!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
}
int main() {
    priority_queue<int> pq; // Create max-heap
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    // Insert elements in max-heap
    for(auto &elm : v) {
        pq.push(elm);
    }

    // Initialize max-heap at the time of declaration
    priority_queue<int> pq2(v.begin(), v.end()); 
    printQueue(pq2);
    printQueue(pq);

    priority_queue<int, vector<int>, greater<int>> q; // Create min-heap

    // Insert elements in min-heap
    for(int i = 0; i < n; ++i) {
        q.push(v[i]);
    }
    printQueue(q);

    int arr[n];
    for(int i = 0; i < n; ++i) {
        arr[i] = v[i];
    }

    // Initialize min-heap at the time of declaration
    priority_queue<int, vector<int>, greater<int>> p(v.begin(), v.end());
    priority_queue<int, vector<int>, greater<int>> a(arr, arr + n);
    
    printQueue(p);
    printQueue(a);
    return 0;
}