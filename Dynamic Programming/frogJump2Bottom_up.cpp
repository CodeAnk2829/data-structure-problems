// https://leetcode.com/problems/frog-jump-ii/

// Bottom up approach

#include <bits/stdc++.h>
using namespace std;

int maxJump(vector<int> &stones)
{
    int n = stones.size();
    int prev = stones[1] - stones[0];
    int prevToPrev = 0;

    for (int i = 2; i < n; ++i)
    {
        int cost1 = max(stones[i] - stones[i - 1], stones[i] - stones[i - 2]);
        int cost2 = max(prev, prevToPrev);
        int curr = max(cost1, cost2);
        prevToPrev = prev;
        prev = curr;
    }

    return prev;
}