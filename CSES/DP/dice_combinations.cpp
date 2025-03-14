#include <bits/stdc++.h>
using namespace std;

/*
    state: f(n): number of ways to produce n
    transition: f(n) = f(n - 1) + f(n - 2) + f(n - 3) + f(n - 4) + f(n - 5) + f(n - 6)
*/

const long long mod = 1e9 + 7;

long long solve(long long n, vector<long long>& dp) {
    // base case
    if(n == 0) return 1;

    // if ans already exists
    if(dp[n] != -1) {
        return dp[n];
    }

    long long count = 0;
    for(long long i = 1; i <= 6; ++i) {
        if(n >= i) {
            count += solve(n - i, dp) % mod;
        }
    }

    return dp[n] = count % mod;
}

long long iterativeSolution(long long n) {
    vector<long long> dp(n + 1, 0);

    for(int i = 1; i <= 6 && i <= n; ++i) {
        dp[i] = 1 << (i - 1);
    }

    long long count = 63;
    
    for(int i = 7; i <= n; ++i) {
        dp[i] = count % mod;
        count += (dp[i] - dp[i - 6]) % mod;
    }

    return dp[n];
}

int main() {
    long long n;
    cin >> n;
    // vector<long long> dp(n + 1, -1);
    // cout << solve(n, dp) << endl;

    cout << iterativeSolution(n) << endl;
    return 0;
}