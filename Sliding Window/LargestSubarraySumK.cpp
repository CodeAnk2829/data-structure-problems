// Find the length of the largest subarray having sum equal to k
// Elements of the array are whole numbers
// Sliding window approach or Two pointer approach
// TC = O(N) --> best case and O(2N) --> worst case
// SC = O(1)
#include <bits/stdc++.h>
using namespace std;

int longestSubarrayWithSumK(vector<int> &arr, int k) {
    int n = arr.size();
    int sum = arr[0];
    int left = 0, right = 0;
    int maxLen = 0;

    while(right < n) {
        // Trim the array from the left side if the 
        // current sum is greater than k
        while(left <= right && sum > k) {
            sum -= arr[left];
            left++;
        }

        // update maxLen of the subarray if we found the required sum
        if(sum == k) {
            maxLen = max(maxLen, right - left + 1);
        }

        // calculate the sum going in right direction
        right++;
        if(right < n) {
            sum += arr[right];
        }
    }

    return maxLen;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr;
    for(int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        arr.push_back(x);
    }

    cout << longestSubarrayWithSumK(arr, k);

    return 0;
}