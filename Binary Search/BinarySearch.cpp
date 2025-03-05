// Program to perform binary search on an array
#include <bits/stdc++.h>
using namespace std;
int binarySearch(vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(arr[mid] == target) return mid; // target found
        if(arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1; // target not found
}

int main() {
    int n;
    cin >> n;
    vector<int> v;
    for(int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    int target;
    cin >> target;

    sort(v.begin(), v.end());
    int isFoundAt = binarySearch(v, target);
    cout << isFoundAt << endl;
    return 0;
}