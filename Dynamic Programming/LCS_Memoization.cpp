#include <bits/stdc++.h>
using namespace std;
int LCShelper(char* s1, char* s2, int n, int m, int** dp) {
    if(n == 0 || m == 0) {
        return 0;
    }
    if(dp[n][m] > -1) {
        return dp[n][m];
    }
    int ans;
    if(s1[0] == s2[0]) {
        ans = 1 + LCShelper(s1 + 1, s2 + 1, n - 1, m - 1, dp);
    } else {
        int b = LCShelper(s1 + 1, s2, n - 1, m, dp);
        int c = LCShelper(s1, s2 + 1, n, m - 1, dp);
        ans = max(b, c);
    }
    dp[n][m] = ans;
    return ans;
}
int LCS(char* s1, char* s2) {
    int n = strlen(s1);
    int m = strlen(s2);
    int** dp = new int*[n + 1];
    for(int i = 0; i <= n; ++i) {
        dp[i] = new int[m + 1];
        for(int j = 0; j <= m + 1; ++j) {
            dp[i][j] = -1;
        }
    }
    int ans = LCShelper(s1, s2, n, m, dp);
    for(int i = 0; i <= n; ++i) {
        delete [] dp[i];
    }
    delete [] dp;
    return ans;
}
int main() {
    char s1[1001], s2[1001];
    cin.getline(s1, 1001);
    cin.getline(s2, 1001);
    cout << LCS(s1, s2);
    return 0;
}