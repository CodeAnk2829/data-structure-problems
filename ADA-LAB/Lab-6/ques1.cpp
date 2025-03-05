#include <bits/stdc++.h>
using namespace std;
bool binarySearch(int a[], int lo, int hi, int k) {
    while(hi - lo > 1) {
        int mid = (hi + lo) / 2;
        if(k >= a[mid]) {
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }
    if(k == a[lo]) {
        return true;
    } else if(k == a[hi]) {
        return true;
    }
    return false;
}
bool solve(int a[], int b[], int n, int val) {
    sort(b, b + n);
    for(int i = 0; i < n; ++i) {
        int diff = val - a[i];
        if(binarySearch(b, 0, n - 1, diff)) {
            return true;
        } 
    }
    return false;
}
int main() {
    int n, val;
    cout << "Enter size: " << endl;
    cin >> n;
    cout << "Enter sum: " << endl;
    cin >> val;
    
    int a[n], b[n];

    cout << "Enter elements in first array: " << endl;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    cout << "Enter elements in the second array: " << endl;
    for(int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    if (solve(a, b, n, val)) {
        cout << "TRUE" << endl;
    } else {
        cout << "FALSE" << endl;
    }
    return 0;
}