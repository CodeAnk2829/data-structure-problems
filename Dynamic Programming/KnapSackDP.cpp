// Top-Down approach for 0-1 knapSack problem
#include <bits/stdc++.h>
using namespace std;
int knapSack(vector<int>& wt, vector<int>& val, int n, int w) {
    int dp[n + 1][w + 1];

    // Initialize the dp array with 0 where n == 0 or w == 0
    for(int i = 0; i <= n; ++i) {
        for(int j = 0; j <= w; ++j) {
            if(i == 0 || j == 0) {
                dp[i][j] = 0;
            }
        }
    }

    // Calculation
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= w; ++j) {
            if(wt[i - 1] <= j) {
                dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][w];
}
int main() {
    int n, w;
    cin >> n >> w;
    vector<int> val(n);
    vector<int> wt(n);
    for(int i = 0; i < n; ++i) cin >> wt[i];
    for(int i = 0; i < n; ++i) cin >> val[i];
    cout << knapSack(wt, val, n, w);
    return 0;
}
