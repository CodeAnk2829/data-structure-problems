// problem link: https://codeforces.com/contest/1350/problem/B

#include <bits/stdc++.h>
using namespace std;

// state: dp[i] = max length of the beautiful arrangement with index i
// transition: dp[i] = max(dp[i], 1 + dp[j]) where 2*i <= j <= n
// final subproblem = dp[n]

int getMaxModels(int i, vector<int>& models, vector<int>& dp) {
    // base case
    if (i > models.size()) return 0;

    // state already calculated 
    if (dp[i] != -1) return dp[i];

    // calculation
    int count = 0;

    for (int j = 2 * i; j <= models.size(); j += i) {
        if (models[j - 1] > models[i - 1]) {
            count = max(count, 1 + getMaxModels(j, models, dp));
        }
    }

    return dp[i] = count;
}


int main() {
    int t;
    cin >> t;
    while(t--) {
        int n; 
        cin >> n;
        vector<int> models(n);
        for (auto &m : models) cin >> m;
        
        vector<int> dp(n + 1, -1);
        int maxLengthModel = 1;

        for (int i = 0; i < n; ++i) {
            maxLengthModel = max(maxLengthModel, 1 + getMaxModels(i + 1, models, dp));
        }
        cout << maxLengthModel << endl;
    }
    return 0;
}