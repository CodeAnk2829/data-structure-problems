// problem link: https://codeforces.com/problemset/problem/1881/E

#include <bits/stdc++.h>
using namespace std;

int helper(vector<int>& arr, int i, int n, vector<int>& dp) {
    // base case
    if(i >= n - 1) {
        return 0;
    }

    if(dp[i] != -1) {
        return dp[i];
    }

    int startBlockFromHere = INT_MIN;
    if(i + arr[i] < n) {
        startBlockFromHere = 1 + arr[i] + helper(arr, i + arr[i] + 1, n, dp);
    }

    int skip = helper(arr, i + 1, n, dp);

    return dp[i] = max(startBlockFromHere, skip);
}

int minimumRemoval(vector<int>& arr) {
    vector<int> dp(arr.size(), -1);
    return helper(arr, 0, arr.size(), dp);
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for(auto &i : arr) cin >> i;

        cout << n - minimumRemoval(arr) << endl;
    }

    return 0;
}