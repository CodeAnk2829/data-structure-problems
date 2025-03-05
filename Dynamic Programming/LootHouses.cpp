// Brute Force Approach
#include <bits/stdc++.h>
using namespace std;
int maxLootHelper(int*a, int i, int n) {
    if(i > n) return 0;
    int temp1 = a[i] + maxLootHelper(a, i + 2, n);
    int temp2 = maxLootHelper(a, i + 1, n);
    int ans = max(temp1, temp2);
    return ans;
}

int maxLoot(int n, int* a) {
    return maxLootHelper(a, 0, n - 1);
}

int main() {
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    cout << maxLoot(n, a);
    return 0;
}