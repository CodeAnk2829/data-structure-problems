// Problem Rod Cutting

#include <bits/stdc++.h>
using namespace std;

int rodCutting(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1));

    // cut the rod in order to maximize the selling price 

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            if(i <= j) {
                dp[i][j] = max(prices[i - 1] + dp[i][j - 1], dp[i - 1][j]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][n];
}

int main() {
    int n;
    cin >> n;
    vector<int> prices;
    for(int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        prices.push_back(x);
    }
    
    // Maximum profit gained by selling the rod 
    cout << rodCutting(prices) << endl;
    return 0;
}