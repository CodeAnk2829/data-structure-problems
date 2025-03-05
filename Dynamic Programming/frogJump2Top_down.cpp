// top-down approach
#include <bits/stdc++.h>
using namespace std;

int f(vector<int> &stones, int n, vector<int> &dp)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return (stones[1] - stones[0]);

    // if answer already exists
    if (dp[n] != -1)
    {
        return dp[n];
    }

    int cost1 = max(stones[n] - stones[n - 1], stones[n] - stones[n - 2]);
    int cost2 = max(f(stones, n - 1, dp), f(stones, n - 2, dp));

    return dp[n] = max(cost1, cost2);
}


int maxJump(vector<int> &stones)
{
    int n = stones.size();
    vector<int> dp(n, -1);
    return f(stones, n - 1, dp);
}