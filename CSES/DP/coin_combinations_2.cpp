#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

/*
    state: f(i, sum) means the no. of ways to produce the sum from the coins from i to n - 1;
    transition: f(i, sum) = f(i, sum - coins[i]) --> pick the current coin + f(i + 1, sum) --> skip the current coin
*/

int calculateOrderedWays(vector<int> &coins, int n, int sum) {
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));
    dp[0][0] = 1;
    
    for(int i = 1; i <= n; ++i) {
        for(int j = 0; j <= sum; ++j) {
            dp[i][j] = dp[i - 1][j] % mod;
            if(coins[i - 1] <= j) {
                dp[i][j] += (dp[i][j - coins[i - 1]] % mod);
            }
        }
    }

    return dp[n][sum] % mod;
}

int main() {
    int n, sum;
    cin >> n >> sum;
    vector<int> coins(n);
    for(auto &i : coins) cin >> i;

    cout << calculateOrderedWays(coins, n, sum) << endl;

    return 0;
}