// The most optimized code for min steps to 1 --> dp solution
// TC - O(1)
// 1 <= n <= 10^9

#include <bits/stdc++.h>
using namespace std;

unordered_map<int, int> dp;

int minStepsTo1(int n) {
    // Base case
    if(n <= 1) return 0;

    // If n is not found in dp map
    if(dp.count(n) == 0) {
        // store the result
        dp[n] = 1 + min(n % 2 + minStepsTo1(n / 2), n % 3 + minStepsTo1(n / 3));
    }
    return dp[n];
}

int main() {
    int n;
    cin >> n;
    cout << minStepsTo1(n) << endl;
    return 0;
}