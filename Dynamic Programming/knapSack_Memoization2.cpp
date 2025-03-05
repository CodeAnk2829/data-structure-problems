// Method-2 Memoization approach for 0-1 knapSack problem
#include <bits/stdc++.h>
using namespace std;
int knapSack2Helper(vector<int>& wt, vector<int>& val, int n, int w, vector<vector<int>>& dp) {
    // Base case
    if(n == 0 || w == 0) {
        return dp[n][w] = 0;
    }
    // if the value has stored in dp array then return the ans
    if(dp[n][w] != -1) {
        return dp[n][w];
    }
    // store the val in dp array
    if(wt[n - 1] <= w) {
        dp[n][w] = max(val[n - 1] + knapSack2Helper(wt, val, n - 1, w - wt[n - 1], dp), knapSack2Helper(wt, val, n - 1, w, dp));
    } else {
        dp[n][w] = knapSack2Helper(wt, val, n - 1, w, dp);
    }

    return dp[n][w];
}

int knapSack2(vector<int>& wt, vector<int>& val, int n, int w) {
    vector<vector<int>> dp;
    for(int i = 0; i <= n; ++i) {
        vector<int> temp;
        for(int j = 0; j <= w; ++j) {
            temp.push_back(-1);
        }
        dp.push_back(temp);
    }
    return knapSack2Helper(wt, val, n, w, dp);
}
int main() {
    int n, w;
    cin >> n >> w;

    vector<int> wt(n);
    for(int i = 0; i < n; ++i) cin >> wt[i];
    vector<int> val(n);
    for(int i = 0; i < n; ++i) cin >> val[i];

    int ans = knapSack2(wt, val, n, w);
    cout << ans << endl;
    return 0;
}