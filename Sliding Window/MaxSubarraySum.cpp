// Program to find the maximum subarray sum of size k
#include <bits/stdc++.h>
using namespace std;
long maxSubarraySum(vector<long>& arr, int k) {
    int n = arr.size();
    long windowSum = 0;

    // find sum of first window containing k elements
    for(int i = 0; i < k; ++i) {
        windowSum += arr[i];
    }

    // find the maximum subarray sum by sliding the window 
    long maxSum = windowSum;
    for(int i = 1; i <= n - k; ++i) {
        windowSum = windowSum + arr[i + k - 1] - arr[i - 1];
        maxSum = max(maxSum, windowSum);
    }

    return maxSum;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<long> arr;
    for(int i = 0; i < n; ++i) {
        long x;
        cin >> x;
        arr.push_back(x);
    }

    cout << maxSubarraySum(arr, k);
    return 0;
}