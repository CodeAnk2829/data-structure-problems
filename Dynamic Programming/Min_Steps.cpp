// Find the minimum no. of steps to reach to 1 from a given integer
// Brute Force Approach
// Time Complexity = O(2^n) to O(3^n)
#include <bits/stdc++.h>
using namespace std;
int minSteps(int n) {
    if(n == 1) return 0;
    int a = minSteps(n - 1);
    int b = INT_MAX, c = INT_MAX;
    if(n % 2 == 0) {
        b = minSteps(n / 2);
    }
    if(n % 3 == 0) {
        c = minSteps(n / 3);
    }
    int ans = min(a, min(b, c)) + 1;
    return ans;
}

int main() {
    int n;
    cin >> n;
    cout << minSteps(n);
    return 0;
}