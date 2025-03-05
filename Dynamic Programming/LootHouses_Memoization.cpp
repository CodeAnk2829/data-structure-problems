// Memoization Technique
// Time Comlexity = O(n)
#include <bits/stdc++.h>
using namespace std;

int maxLootHelper(int* a, int* ans, int n) {
    if(n < 0) return 0;
    if(ans[n] != -1) {
        return ans[n];
    }
    int temp1 = maxLootHelper(a, ans, n - 1);
    int temp2 = a[n] + maxLootHelper(a, ans, n - 2);
    ans[n] = max(temp1, temp2);
    return ans[n];

}

int maxLoot(int* a, int n) {
    int* ans = new int[n];
    for(int i = 0; i < n; ++i) {
        ans[i] = -1;
    }
    int result = maxLootHelper(a, ans, n - 1);
    delete [] ans;
    return result;
}

int main() {
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; ++i) cin >> a[i];
    cout << maxLoot(a, n);
    return 0;
}