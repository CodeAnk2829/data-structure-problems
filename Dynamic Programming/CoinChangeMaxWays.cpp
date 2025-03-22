// Problem: Maximum no. of ways in which we can add the coins
// to find the required amount

#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int coinChange(vector<int>& coin, int amount) {
    int n = coin.size();
    vector<vector<int>> dp(n + 1, vector<int>(amount + 1));
    dp[0][0] = 1;
    
    // calculation
    for(int i = 1; i <= n; ++i) {
        for(int j = 0; j <= amount; ++j) {
            if(coin[i - 1] <= j) {
                dp[i][j] = ((dp[i][j - coin[i - 1]] % mod) + (dp[i - 1][j] % mod));
            } else {
                dp[i][j] = dp[i - 1][j] % mod;
            }
        }
    }
    return dp[n][amount] % mod;
}

int main() {
    int n;
    cin >> n;
    int amount;
    cin >> amount;
    vector<int> coin;
    for(int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        coin.push_back(x);
    }
    cout << coinChange(coin, amount);
    return 0;
}