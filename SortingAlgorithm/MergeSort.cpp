// Time Complexity for merge sort is (n.log(n) base 2)

#include <bits/stdc++.h>
using namespace std;
const int N = 10e5 + 7;
int a[N];

// Function to merge sort and merge left and right subarrays (Time Complexity for merging the subarrays is n);
void merge(int l, int mid, int r) {
    int l_sz = mid - l + 1;
    int r_sz = r - mid;
    int L[l_sz + 1], R[r_sz + 1];
    for(int i = 0; i < l_sz; ++i) {
        L[i] = a[i + l];
    }
    for(int i = 0; i < r_sz; ++i) {
        R[i] = a[i + mid + 1];
    }
    L[l_sz] = R[r_sz] = INT_MAX;
    int l_i = 0;
    int r_i = 0;
    for(int i = l; i <= r; ++i) {
        a[i] = (L[l_i] <= R[r_i]) ? L[l_i++] :  R[r_i++]; 
    }
}

// Function to traverse the whole by dividing them into two equal halves (Time complexity of dividing by 2 is log(n) base 2).
void merge_sort(int l, int r) {
    if(l == r) return;
    int mid = (l + r) / 2;
    merge_sort(l, mid);
    merge_sort(mid + 1, r);
    merge(l, mid, r);
}
int main() {
    int n; 
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    merge_sort(0, n - 1);
    for(int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    return 0;
}