#include <bits/stdc++.h>
using namespace std;

int countSubsetSum(vector<int>& nums, int targetSum) {
    
    const int mod = 1e9 + 7;
    int n = nums.size();

    // initialize the dp array according to the condition
    // condition--> if(n == 0) then, targetSum can never be achieved with 0 elements
    // if(targetSum == 0) then, empty subset can be possible or if an element is 0

    vector<vector<int>> dp(n + 1, vector<int>(targetSum + 1, 0));
    dp[0][0] = 1; // 0 means empty array and 0 sum
    
    // count the no. of desired subsets
    for(int i = 1; i <= n; ++i) {
        for(int j = 0; j <= targetSum; ++j) {
            if(nums[i - 1] <= j) {
                dp[i][j] = (dp[i - 1][j - nums[i - 1]] + dp[i - 1][j]) % mod;
            } else {
                dp[i][j] = dp[i - 1][j] % mod;
            }
        }
    }

    return dp[n][targetSum];
}

int main() {
    int n;
    cin >> n;

    // Take input
    vector<int> nums;
    for(int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        nums.push_back(x);
    }

    int targetSum;
    cin >> targetSum;

    // count the no. of subset which can become targetSum
    // after adding all of its element

    int perfectSum = countSubsetSum(nums, targetSum);
    cout << perfectSum << endl;
    return 0;
}