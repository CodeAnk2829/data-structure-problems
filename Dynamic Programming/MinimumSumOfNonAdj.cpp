// https://www.codingninjas.com/studio/problems/maximum-sum-of-non-adjacent-elements_843261?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0

// top-down approach

#include <bits/stdc++.h>
using namespace std;

int f(int n, vector<int> &nums, vector<int> &dp)
{
    // base case
    if (n <= 0)
        return 0;

    // if ans already exists
    if (dp[n - 1] != -1)
        return dp[n - 1];

    int option1 = f(n - 2, nums, dp) + nums[n - 1];
    int option2 = f(n - 1, nums, dp);

    return dp[n - 1] = max(option1, option2);
}
int maximumNonAdjacentSum(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, -1);
    return f(n, nums, dp);
}