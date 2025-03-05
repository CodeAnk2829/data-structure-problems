// Minimum no. of coins to achieve the required amount
#include <bits/stdc++.h>
using namespace std;
long long int countHelper(int coins[], int n, int sum, long long int** ans) {
    if(sum == 0) {
        return ans[n][sum] = 1;
    } 
    if(sum < 0) {
        return 0;
    }
    if(ans[n][sum] != -1) {
        return ans[n][sum];
    }
    if(n == 1) {
        long long int temp = (sum % coins[n - 1] == 0) ? 1 : 0;
        ans[n][sum] = temp;
        return temp;
    }
    long long int option1 = countHelper(coins, n, sum - coins[n - 1], ans);
    long long int option2 = countHelper(coins, n - 1, sum, ans);
    long long int temp = option1 + option2;
    ans[n][sum] = temp;
    return temp;
}
long long int count(int coins[], int n, int sum) {
    long long int** dp = new long long int*[n + 1];
    for(int i = 0; i <= n; ++i) {
        dp[i] = new long long int[sum + 1];
        for(int j = 0; j <= sum; ++j) {
            dp[i][j] = -1;
        }
    }
    long long int ans = countHelper(coins, n, sum, dp);
    for(int i = 0; i <= n; ++i) {
        delete [] dp[i];
    } 
    delete [] dp;
    return ans;
}
int main() {
    int sum, n;
    cin >> sum >> n;
    int coin[n];
    for(int i = 0; i < n; ++i) {
        cin >> coin[i];
    }
    cout << count(coin, n, sum);
    return 0;
}