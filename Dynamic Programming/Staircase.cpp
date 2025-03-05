/*A child runs up a staircase with 'n' steps and can hop either 1 step, 
2 steps or 3 steps at a time. Implement a method to count and return 
all possible ways in which the child can run-up to the stairs.*/

// Time Comlexity = O(n)
// Space Complexity = O(1)
// Using Dynammc Programming

#include <iostream>
using namespace std;
int countWays(int n) {
    if(n <= 2) return n;
    if(n == 3) return 4;

    int dp1 = 1, dp2 = 2, dp3 = 4;
    int ans;
    for(int i = 4; i <= n; ++i) {
        ans = dp1 + dp2 + dp3;
        dp1 = dp2; 
        dp2 = dp3;
        dp3 = ans;
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    cout << countWays(n);
    return 0;
}