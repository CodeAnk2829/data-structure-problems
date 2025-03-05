// Program to perform binary search on an array (Recursively)
#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

// Function to find a key using Binary Search
void binary_search(int* v, int lo, int hi, int key) {
    if(lo > hi) {
        cout << "Not found";
        return;
    }
    int mid = (lo + hi)/2;
    if(v[mid] == key) {
        cout << "Key found at " << mid << endl;
        return;
    }
    if(v[mid] < key) {
        binary_search(v, mid + 1, hi, key);
    } else {
        binary_search(v, lo, mid, key);
    }
}
int main() {
    int n;
    cout << "Enter size: " << endl;
    cin >> n;

    int* a = new int[n];
    cout << "Enter elements: " << endl;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int key;
    cout << "Enter the key" << endl;
    cin >> key;

    // Sort the array
    sort(a, a + n);

    // Get starting timepoint
    auto start = high_resolution_clock::now();

    // Finding the key using recursive approach
    binary_search(a, 0, n - 1, key);
    

    // Get ending timepoint
    auto stop = high_resolution_clock::now();

    // use duration cast method
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Time taken by function: " << duration.count() << " microseconds" << endl;

    return 0;
}
