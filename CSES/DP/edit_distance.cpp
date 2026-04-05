#include <bits/stdc++.h>
using namespace std;

// state: dp[i][j] = min number of operations to make a string from 0 to i to a string from 0 to j
// transition = if character matches then dp[i][j] = dp[i - 1][j - 1];
//              else dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]})

int editDistance(string &s, string& t) {
    int n = s.size();
    int m = t.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int row = 0; row <= n; row++) {
        dp[row][0] = row;
    }

    for (int col = 0; col <= m; col++) {
        dp[0][col] = col;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (s[i - 1] == t[j - 1]) {
                // replicate (i - 1, j - 1)
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                // 1 + min(delete, replace, insert)
                dp[i][j] = 1 + min({dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]});
            }
        }
    }

    return dp[n][m];
}

int main() {
    string s, t;
    cin >> s >> t;
    cout << editDistance(s, t) << endl;

    return 0;
}