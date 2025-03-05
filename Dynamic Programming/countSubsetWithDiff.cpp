#include <bits/stdc++.h>
using namespace std;
int countSubsetSum(vector<int>& arr, int sum) {
    const int mod = 1e9 + 7;
    int n = arr.size();
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));
    dp[0][0] = 1;
    for(int i = 1; i <= n; ++i) {
        for(int j = 0; j <= sum; ++j) {
            if(arr[i - 1] <= j) {
                dp[i][j] = (dp[i - 1][j - arr[i - 1]] + dp[i - 1][j]) % mod;
            } else {
                dp[i][j] = dp[i - 1][j] % mod;
            }
        }
    }
    
    return dp[n][sum];
}

int countPartitions(int n, int d, vector<int>& arr) {
    int totalSum = 0;
    for(int i = 0; i < n; ++i) {
        totalSum += arr[i];
    }
    
    if((d + totalSum) & 1) {
        return 0;
    }
    
    int subset1Sum = (d + totalSum) / 2;
    int ans = countSubsetSum(arr, subset1Sum);
    return ans;
}

int main() {
    int n, d;
    cin >> n >> d;
    vector<int> arr(n);
    
    for(int i = 0; i < n; ++i) {
        cin >> arr[i];   
    }
    cout << countPartitions(n, d, arr);
    return 0;
}