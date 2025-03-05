#include <bits/stdc++.h>
using namespace std;

int knapSackHelper(vector<int>& wt, vector<int>& val, int w, int n, vector<vector<int>>& dp) {
    if(w == 0 || n == 0) {
        return dp[n][w] = 0;
    }

    if(dp[n][w] != -1) {
        return dp[n][w];
    }
    if(wt[n - 1] <= w) {
        dp[n][w] = max(val[n - 1] + knapSackHelper(wt, val, w - wt[n - 1], n - 1, dp), knapSackHelper(wt, val, w, n - 1, dp));
    } else {
        dp[n][w] = knapSackHelper(wt, val, w, n - 1, dp);
    }

    return dp[n][w];
}
int knapSack(vector<int>& wt, vector<int>& val, int w) {
    int n = wt.size();
    vector<vector<int>> dp(n + 1, vector<int>(w + 1, -1));
    return knapSackHelper(wt, val, w, n, dp);
}

int knapSack2(vector<int>& wt, vector<int>& val, int w) {
    int n = wt.size();
    vector<vector<int>> dp(n + 1, vector<int>(w + 1, 0));
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= w; ++j) {
            if(wt[i - 1] <= j) {
                dp[i][j] = max(dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    dp[n][w];
}


int main() {
    int n;
    vector<int> wt(n), val(n);
    cin >> n;
    for(int i = 0; i < n; ++i) cin >> wt[i];
    for(int i = 0; i < n; ++i) cin >> val[i];

    int w;
    cin >> w;

    int ans = knapSack2(wt, val, w);
    cout << ans << endl;
    return 0;
}