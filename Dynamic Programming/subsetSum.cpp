// Print yes/no, whether a given target sum can be achieved by taking sum of subarray from the given array
#include <bits/stdc++.h>
using namespace std;
bool subsetSumToK(int n, int targetSum, vector<int> &sum) {
    bool dp[n + 1][targetSum + 1];
    for(int i = 0; i <= n; ++i) {
        for(int j = 0; j <= targetSum; ++j) {
            if(j == 0) {
                dp[i][j] = true;
            } else if(i == 0) {
                dp[i][j] = false;
            }
        }
    }

    // find the desired subset
    
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= targetSum; ++j) {

            // inclusion or exclusion case arises only when a number is less
            // than or equal to the target sum otherwise no need to choose
            // that number

            if(sum[i - 1] <= j) { 
                dp[i][j] = (dp[i - 1][j - sum[i - 1]] || dp[i - 1][j]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][targetSum];
}
