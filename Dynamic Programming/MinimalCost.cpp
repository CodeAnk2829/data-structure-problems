// https://www.codingninjas.com/studio/problems/minimal-cost_8180930?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0

#include <bits/stdc++.h>
using namespace std;

int f(int n, int k, vector<int> &heights, vector<int> &dp)
{
    // base case
    if (n == 0)
        return 0;

    // if ans already exists
    if (dp[n] != -1)
        return dp[n];

    int minCost = INT_MAX;
    for (int i = 1; i <= k; ++i)
    {
        if (n - i >= 0)
        {
            int cost = f(n - i, k, heights, dp) + abs(heights[n] - heights[n - i]);
            minCost = min(minCost, cost);
        }
    }
    return dp[n] = minCost;
}

int minimizeCost(int n, int k, vector<int> &height)
{
    vector<int> dp(n, -1);
    return f(n - 1, k, height, dp);
}