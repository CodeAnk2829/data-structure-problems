// Array is sorted but contains only distinct elements
// https://leetcode.com/problems/search-in-rotated-sorted-array/

#include <bits/stdc++.h>
using namespace std;

int searchInRotatedSortedArray(vector<int>& arr, int target) {
    int n = arr.size();
    int low = 0, high = n - 1;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(arr[mid] == target) return mid;
        // check which half is sorted

        if(arr[low] <= arr[mid]) { // left half is sorted
            if(arr[low] <= target && target <= arr[mid]) {
                // target lies in the left half
                high = mid - 1; // trim down the right half
            } else {
                // target lies in the right half
                low = mid + 1; // trim down the left half
            }
        } else { // right half is sorted
            if(arr[mid] <= target && target <= arr[high]) {
                // target lies in the right half
                low = mid + 1; // trim down the left half
            } else {
                // target lies in the left half
                high = mid - 1; // trim down the right half
            }
        }
    }
    return -1;
}

int main() {
    int n, target; 
    cin >> n >> target;
    vector<int> arr(n);

    // take elements in rotated sorted manner
    for(int i = 0; i < n; ++i) cin >> arr[i];
    
    int ans = searchInRotatedSortedArray(arr, target);
    cout << ans << endl;
    return 0;
}