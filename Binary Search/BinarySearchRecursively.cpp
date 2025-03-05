// Program to perform binary search on an array (Recursively)
#include <bits/stdc++.h>
using namespace std;

int bsHelper(vector<int>& arr, int low, int high, int target) {
    if(low > high) return -1;

    int mid = low + (high - low) / 2;
    if(arr[mid] == target) return mid;
    if(arr[mid] > target) {
        return bsHelper(arr, low, mid - 1, target);
    } 
    return bsHelper(arr, mid + 1, high, target);
}

int binarySearch(vector<int>& arr, int target) {
    return bsHelper(arr, 0, arr.size() - 1, target);
}

int main() {
    int n;
    cin >> n;
    vector<int> a;
    for(int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        a.push_back(x);
    }
    int key;
    cin >> key;
    sort(a.begin(), a.end());
    int isFoundAt = binarySearch(a, key);
    cout << isFoundAt << endl;
    return 0;
}
