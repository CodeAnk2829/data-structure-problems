// Maximum money looted by the robber using Dynammic Progarmming
// Time Comlexity = O(n)
// Space Complexity = O(1)
#include <iostream>
using namespace std;
int maximizeMoney(int* a, int n) {
    int dp0 = a[0];
    if(n == 1) return dp0;

    int dp1 = max(a[0], a[1]);
    if(n == 2) return dp1;

    int ans;
    for(int i = 2; i < n; ++i) {
        int temp1 = a[i] + dp0;
        int temp2 = dp1;
        ans = max(temp1, temp2);
        dp0 = dp1;
        dp1 = ans;
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; ++i) cin >> a[i];
    cout << maximizeMoney(a, n);
    return 0;
}