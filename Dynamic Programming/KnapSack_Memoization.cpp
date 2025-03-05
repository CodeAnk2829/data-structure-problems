#include <bits/stdc++.h>
using namespace std;
int knapSnack2Helper(int* val, int* wt, int n, int w, int** dp) {
    if(w == 0 || n <= 0) {
        return 0;
    }
    if(dp[n][w] != -1) {
        return dp[n][w];
    }
    int a = INT_MIN;
    if(wt[n - 1] <= w) {
        a = val[n - 1] + knapSnack2Helper(val, wt, n - 1, w - wt[n - 1], dp);
    }
    int b = knapSnack2Helper(val, wt, n - 1, w, dp);
    int ans = max(a, b);
    dp[n][w] = ans;
    return ans;
}
int knapSnack2(int* val, int* wt, int n, int w) {
    int** dp = new int*[n + 1];
    for(int i = 0; i <= n; ++i) {
        dp[i] = new int[w + 1];
        for(int j = 0; j <= w; ++j) {
            dp[i][j] = -1;
        }
    }
    int ans = knapSnack2Helper(val, wt, n, w, dp);
    for(int i = 0; i <= n; ++i) {
        delete [] dp[i];
    }
    delete [] dp;
    return ans;
}

int main() {
    int n, w;
    cin >> n >> w;
    int val[n];
    int wt[n];
    for(int i = 0; i < n; ++i) cin >> val[i];
    for(int i = 0; i < n; ++i) cin >> wt[i];
    cout << knapSnack2(val, wt, n, w);
    return 0;
}