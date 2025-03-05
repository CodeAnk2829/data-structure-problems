#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll solve(vector<ll>& arr, ll i, ll j, vector<vector<ll>>& dp) {
    if(i >= j) {
        return 0;
    }

    if(dp[i][j] != -1e10) return dp[i][j];

    return dp[i][j] = max(arr[i] + solve(arr, i + 2, j, dp), arr[j] + solve(arr, i, j - 2, dp));
}

int main() {
    ll n;
    cin >> n; 

    vector<ll> arr(n);
    for(auto &i : arr) cin >> i;

    vector<vector<ll>> dp(n, vector<ll>(n, -1e10));
    cout << solve(arr, 0, n - 1, dp) << endl;
    return 0;
}