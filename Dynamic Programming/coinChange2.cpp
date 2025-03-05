#include <bits/stdc++.h>
using namespace std;

int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    vector<vector<long>> dp(n + 1, vector<long>(amount + 1));

    cout << endl;
    for(int i = 0; i <= n; ++i) {
        for(int j = 0; j <= amount; ++j) {
            if(i == 0) {
                dp[i][j] = INT_MAX - 1;
            }
            if(i == 1 && j % coins[0] == 0) {
                dp[i][j] = j / coins[0];
            } else if(i == 1) {
                dp[i][j] = INT_MAX - 1;
            }
        }
    }

    for(int i = 2; i <= n; ++i) {
        for(int j = 1; j <= amount; ++j) {
            if(coins[i - 1] <= j) {
                dp[i][j] = min(1 + dp[i][j - coins[i - 1]], dp[i - 1][j]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][amount] >= INT_MAX - 1 ? -1 : dp[n][amount];
}
int main() {
    int n;
    cin >> n;
    vector<int> coins(n);
    for(int i = 0; i < n; ++i) cin >> coins[i];

    int amount;
    cin >> amount;
    int minCoins = coinChange(coins, amount);
    cout << minCoins << endl;
    return 0;
}