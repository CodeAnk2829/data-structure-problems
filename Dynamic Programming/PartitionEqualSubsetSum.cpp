#include <bits/stdc++.h>
using namespace std;
bool canPartition(vector<int>& nums) {
    int n = nums.size();
    int sum = 0;
    // calculate sum of all elements in the given array
    for(int i = 0; i < n; ++i) {
        sum += nums[i];
    }
    // if sum is odd then equal partition subset sum can not be possible
    // hence return false
    if(sum & 1) {
        return false;
    }
    // if sum is even then equal partition subset sum may be possible
    // hence we check whether half of the total sum can be possible to achieve
    // with one of the subset or not
    int targetSum = sum / 2;
    vector<vector<bool>> dp(n + 1, vector<bool>(targetSum + 1));
    for(int i = 0; i <= n; ++i) {
        for(int j = 0; j <= targetSum; ++j) {
            if(j == 0) {
                dp[i][j] = true;
            } else if(i == 0) {
                dp[i][j] = false;
            }
        }
    }
    // find whether there exist a subset which can give the target sum when all of its
    // elements get added or not
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= targetSum; ++j) {
            if(nums[i - 1] <= j) {
                dp[i][j] = dp[i - 1][j - nums[i - 1]] || dp[i - 1][j];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][targetSum];
}