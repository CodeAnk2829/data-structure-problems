#include <bits/stdc++.h>
using namespace std;
int lcSubstring(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();

    // Initialize a 2D array named as dp with 0s
    // The main purpose is to fill the first row and first column with 0s
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));

    int longestSubstring = 0;
    // calculation
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            if(s1[i - 1] == s2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = 0;
            }
            longestSubstring = max(longestSubstring, dp[i][j]);
        }
    }

    return longestSubstring;
}