#include <bits/stdc++.h>
using namespace std;

int minCount_helper(int n, int* ans) {
    if(n == 0) return 0;
    if(ans[n] != -1) {
        return ans[n];
    }
    int minValue = n;
    for(int i = 1; i * i <= n; ++i) {
        minValue = min(minValue, 1 + minCount_helper(n - (i * i), ans));
    }
    ans[n] = minValue;
    return ans[n];
}

int minCount(int n) {
    int* ans = new int[n + 1];
    for(int i = 0; i <= n; ++i) {
        ans[i] = -1;
    }
    return minCount_helper(n, ans);
}

int main() {
    int n;
    cin >> n;
    cout << minCount(n);
    return 0;
}