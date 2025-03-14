#include <bits/stdc++.h>
using namespace std;

/*
    state: f(i, x) --> min. no. of coins used from i to n - 1 to produce the sum x
    transition: f(i, x) --> min(f(i + 1, x), i <= x ? 1 + f(i, x - coins[i]) : INT_MAX)
*/

int helper(vector<int>& arr, vector<vector<int>>& dp, int n, int i, int x) {
    // base case
    if(x == 0) return 0;
    if(i >= n) return INT_MAX - 1;

    // if ans has already been calculated
    if(dp[i][x] != -1) return dp[i][x];

    int pick = INT_MAX;
    if(arr[i] <= x) {
        pick = 1 + helper(arr, dp, n, i, x - arr[i]);
    }
    int skip = helper(arr, dp, n, i + 1, x);

    return dp[i][x] = min(pick, skip);
}

int findMinimalCoinsUsed(vector<int>& coins, int n, int money) {
    vector<vector<int>> dp(n, vector<int>(money + 1, -1));
    return helper(coins, dp, n, 0, money);
}

// iterative solution works here because recursive solution gave TLE

int f(vector<int>& coins, int n, int money) {
    vector<vector<int>> dp(n + 1, vector<int>(money + 1, INT_MAX - 1));
    for(int i = 0; i <= n; ++i) {
        dp[i][0] = 0;
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= money; j++) {
            if(coins[i - 1] <= j) {
                dp[i][j] = min(1 + dp[i][j - coins[i - 1]], dp[i - 1][j]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][money];
}

int main() {
    int n, money;
    cin >> n >> money;
    vector<int> coins(n);
    for(auto &i : coins) cin >> i;

    int ans = f(coins, n, money);
    if(ans == INT_MAX - 1) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }

    return 0;
}