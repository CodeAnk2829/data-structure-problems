// Problem: Maximum no. of ways in which we can add the coins
// to find the required amount

#include <bits/stdc++.h>
using namespace std;

int coinChange(vector<int>& coin, int amount) {
    int n = coin.size();
    vector<vector<int>> dp(n + 1, vector<int>(amount + 1));
    dp[0][0] = 1;
    
    // calculation
    for(int i = 1; i <= n; ++i) {
        for(int j = 0; j <= amount; ++j) {
            if(coin[i - 1] <= j) {
                dp[i][j] = dp[i][j - coin[i - 1]] + dp[i - 1][j];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][amount];
}

int main() {
    int n;
    cin >> n;
    vector<int> coin;
    for(int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        coin.push_back(x);
    }
    int amount;
    cin >> amount;
    cout << coinChange(coin, amount);
    return 0;
}