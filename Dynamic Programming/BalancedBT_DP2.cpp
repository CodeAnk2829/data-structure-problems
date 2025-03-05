// Dynamic Programming Approach
// Time Comlexity = O(n)
// Space Complexity = O(1)
#include <iostream>
#include <cmath>
using namespace std;
long long int countBT(int h) {
    long long dp0 = 1, dp1 = 1, dp2;

    int mod = (int) (pow(10, 9)) + 7;
    for(int i = 2; i <= h; ++i) {
        int temp1 = (int) ((dp1 * dp1) % mod);
        int temp2 = (int) ((2 * dp1 * dp0) % mod);
        dp2 = (temp1 + temp2) % mod;
        dp0 = dp1;
        dp1 = dp2;
    }

    long long int result = dp2;
    return result;
}

int main() {
    int h;
    cin >> h;
    cout << countBT(h);
    return 0;
}