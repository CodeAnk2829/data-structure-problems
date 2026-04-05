// problem link: https://codeforces.com/contest/414/problem/B

#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll mod = 1e9 + 7;

// state: dp[k][i] = number of good sequence of length k assuming i is the kth element choosen in that seq
// transition: dp[k][i] = summation of dp[k - 1][j] where 1 <= j <= n iff j % i == 0
// final subproblem: dp[k + 1][1]

ll helper(ll n, ll k, ll i, vector<vector<ll>>& dp) {
    // base case
    if (k == 1) return 1;

    // state already calculated
    if (dp[k][i] != -1) return dp[k][i];

    // calculate 
    ll ans = 0;
    for (ll j = i; j <= n; j += i) {
        if (j % i == 0) {
            ans += helper(n, k - 1, j, dp) % mod;
        }
    }

    return dp[k][i] = ans % mod;
}

ll solve(ll n, ll k) {
    vector<vector<ll>> dp(k + 2, vector<ll>(n + 1, -1));
    return helper(n, k + 1, 1, dp);
}

// iterative solution
ll findGoodSeq(ll n, ll k) {
    vector<vector<ll>> dp(k + 2, vector<ll>(n + 1, 0));
    for (int i = 0; i <= n; i++) {
        dp[1][i] = 1;
    }

    for (ll i = 2; i <= k + 1; ++i) {
        for (ll j = 1; j <= n; ++j) {
            for (ll d = j; d <= n; d += j) {
                if (d % j == 0) {
                    dp[i][j] += dp[i - 1][d] % mod;
                }
            }
        }
    }

    return dp[k + 1][1] % mod;
}

int main() {
    ll n, k;
    cin >> n >> k;

    cout << solve(n, k) << endl;
    return 0;
}