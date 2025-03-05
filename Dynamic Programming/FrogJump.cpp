// https://leetcode.com/problems/frog-jump/

#include <bits/stdc++.h>
using namespace std;

int findMaxDiff(vector<int> &stones)
{
    int ans = 0;
    for (int i = 0; i < stones.size() - 1; ++i)
    {
        int diff = stones[i + 1] - stones[i];
        ans = max(ans, diff);
    }
    return ans;
}

bool binarySearch(vector<int> &stones, int key)
{
    int low = 0, high = stones.size() - 1;
    while (high - low > 1)
    {
        int mid = (high + low) / 2;
        if (stones[mid] <= key)
        {
            low = mid;
        }
        else
        {
            high = mid - 1;
        }
    }

    if (stones[low] == key)
        return true;
    if (stones[high] == key)
        return true;
    return false;
}

bool check(vector<int> &stones, int steps, int pos, int target, map<pair<int, int>, bool> &dp)
{
    // base case
    if (steps == 0)
        return false;
    if (pos == target)
        return true;

    if (dp.find({steps, pos}) != dp.end())
        return dp[{steps, pos}];
    // search for the desired position
    if (binarySearch(stones, pos) == false)
        return dp[{steps, pos}] = false;
    if (check(stones, steps - 1, pos + (steps - 1), target, dp))
        return dp[{steps, pos}] = true;
    if (check(stones, steps, pos + steps, target, dp))
        return dp[{steps, pos}] = true;
    if (check(stones, steps + 1, pos + steps + 1, target, dp))
        return dp[{steps, pos}] = true;

    return dp[{steps, pos}] = false;
}


bool canCross(vector<int> &stones)
{
    int n = stones.size();
    if (stones[1] - stones[0] != 1)
        return false;

    int maxStep = findMaxDiff(stones);

    map<pair<int, int>, bool> dp;
    return check(stones, 1, stones[1], stones[n - 1], dp);
}