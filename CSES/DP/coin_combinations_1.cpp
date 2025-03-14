#include <bits/stdc++.h>
using namespace std;

/*
    state: f(x) --> number of distinct ways to produce the money sum x from the given set of coins
    transition: f(x) --> summation of f(x - arr[i]) where 0 <= i <= n - 1
*/

const long long mod = 1e9 + 7;

long long helper(vector<long long>& arr, long long n, long long sum, vector<long long>& dp) {
    // base case
    if(sum == 0) return 1;

    // if ans already calculated
    if(dp[sum] != -1) return dp[sum];

    long long countDistinctWays = 0;
    for(long long i = 0; i < n; ++i) {
        if(arr[i] <= sum) {
            countDistinctWays += helper(arr, n, sum - arr[i], dp) % mod;
        }
    }

    return dp[sum] = countDistinctWays % mod;
}

long long calculateDistinctWays(long long n, long long money, vector<long long>& coins) {
    vector<long long> dp(money + 1, -1);
    return helper(coins, n, money, dp);
}

int iterativeSolution(vector<long long>& coins, long long money) {
    vector<long long> dp(money + 1, 0);
    dp[0] = 1;

    for(int i = 1; i <= money; ++i) {
        for(auto &j : coins) {
            if(j <= i) {
                dp[i] += dp[i - j] % mod;
            }
        }
    }

    return dp[money] % mod;
}

int main() {
    long long n, money;
    cin >> n >> money;
    vector<long long> coins(n);
    for(auto &i : coins) cin >> i;

    // cout << calculateDistinctWays(n, money, coins) << endl;
    cout << iterativeSolution(coins, money) << endl;
    return 0;
}