// problem link: https://codeforces.com/problemset/problem/1881/E

#include <bits/stdc++.h>
using namespace std;

int iterative_solution(vector<int>& arr) {
    int n = arr.size();
    int dp[n];
    // base case or trivial case
    dp[n - 1] = 0;

    /*  state: dp[i] = maximum number of elements we can pick from i to n - 1
            such that all the blocks are formed with element i to n - 1

        transition: dp[i] = max(dp[i + 1], 1 + arr[i] + dp[i + arr[i] + 1])
    */

    for(int i = n - 1; i >= 0; i--) {
        // start a block from this ith element by including arr[i] consecutive elements
        int pick = 0;
        if(i + arr[i] < n) {
            pick = 1 + arr[i];
            if(1 + i + arr[i] < n) {
                pick += dp[1 + i + arr[i]];
            }
        }

        // skip
        int skip = 0;
        if(i + 1 < n) {
            skip += dp[i + 1];
        }

        dp[i] = max(pick, skip);
    }

    return n - dp[0];
}

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

        // cout << n - minimumRemoval(arr) << endl;
        cout << iterative_solution(arr) << endl;
    }

    return 0;
}