// Min steps to 1
// Dynamic Programming Approach
// Time Complexity = O(n)

#include <bits/stdc++.h>
using namespace std;
int minSteps(int n) {
    if(n == 1) return 0;
    int* ans = new int[n + 1];
    ans[0] = ans[1] = 0;
    for(int i = 2; i <= n; ++i) {
        int x = ans[i - 1];
        int y = INT_MAX, z = INT_MAX;
        if(i % 2 == 0) {
            y = ans[i / 2];
        }
        if(i % 3 == 0) {
            z = ans[i / 3];
        }
        ans[i] = min(x, min(y, z))  + 1;
    }
    return ans[n];
}

int main() {
    int n;
    cin >> n;
    cout << minSteps(n);
    return 0;
}