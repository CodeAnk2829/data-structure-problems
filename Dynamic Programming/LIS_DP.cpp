// Time Comlexity = O(n^2)
#include <bits/stdc++.h>
using namespace std;
int LIS(int* a, int n) {
    if(n == 1) return 1;
    int* ans = new int[n];
    ans[0] = 1;
    for(int i = 1; i < n; ++i) {
        ans[i] = 1;
        for(int j = i - 1; j >= 0; --j) {
            if(a[j] < a[i]) {
                ans[i] = max(ans[i], ans[j] + 1);
            }
        }
    }

    int lis = ans[0];
    for(int i = 1; i < n; ++i) {
        lis = max(lis, ans[i]);
    }

    delete [] ans;
    return lis;
}
int main() {
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; ++i) cin >> a[i];
    int result = LIS(a, n);
    cout << result;
    return 0;
}