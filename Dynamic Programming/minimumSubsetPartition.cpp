// Minimum sum partition
#include <bits/stdc++.h>
using namespace std;
void subsetSum(int nums[], int n, int targetSum, vector<vector<bool>>& dp) {
    // check whether target sum can be obtained by any subset
    // of the given array or not
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= targetSum; ++j) {
            if(nums[i - 1] <= j) {
                dp[i][j] = dp[i - 1][j - nums[i - 1]] || dp[i - 1][j];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
}

int minDifference(int arr[], int n)  { 
    int totalSum = 0;
    // calculate total sum 
    for(int i = 0; i < n; ++i) {
        totalSum += arr[i];
    }

    vector<vector<bool>> dp(n + 1, vector<bool>(totalSum + 1));
    for(int i  = 0; i <= n; ++i) {
        for(int j = 0; j <= totalSum; ++j) {
            if(j == 0) {
                dp[i][j] = true;
            } else if(i == 0) {
                dp[i][j] = false;
            }
        }
    }

    // check whether total sum can be can be obtained by the process
    // of finding subset sum or not so that dp array can be fulfilled
    // with appropriate values and further it can be used
    subsetSum(arr, n, totalSum, dp);

    int subset1Max = 0;

    //find possible subset sum for Subset1 ranges 0 to totalSum / 2;
    for(int i = 1; i <= (totalSum / 2); ++i) {
        if(dp[n][i]) {
            subset1Max = i;
        }
    }

    // return the minimum subset sum partition
    return (totalSum - (2 * subset1Max));
} 

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; ++i) cin >> arr[i];
    cout << minDifference(arr, n) << endl;
    return 0;
}