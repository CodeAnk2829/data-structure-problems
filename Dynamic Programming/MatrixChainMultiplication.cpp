#include <bits/stdc++.h>
using namespace std;
int mcm(vector<int>& mat) {
    int n = mat.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    for(int i = 0; i < n; ++i) {
        dp[i][i] = 0;
    }

    for(int i = n - 1; i >= 1; --i) {
        for(int j = i + 1; j < n; ++j) {
            int maxi = INT_MIN;
            for(int k = i; k < j; ++k) {
                int steps = (mat[i - 1] * mat[k] * mat[j]) + dp[i][k] + dp[k + 1][j];
                if(steps > maxi) maxi = steps;
            }
            dp[i][j] = maxi;
        }
    }

    return dp[1][n - 1];
}
int main() {
    int n;
    cin >> n;
    vector<int> mat(n);
    for(int i = 0; i < n; ++i) cin >> mat[i];

    cout << mcm(mat);
    return 0;
}