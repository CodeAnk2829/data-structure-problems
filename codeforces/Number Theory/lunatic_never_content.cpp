#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& arr, int n) {
    int gcd = 0;
    for(int i = 0; i < (n + 1) / 2; i++) {
        gcd = __gcd(gcd, abs(arr[i] - arr[n - 1 - i]));
    }
    
    return gcd;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for(auto &i : arr) cin >> i;
    
        int ans = solve(arr, n);
        cout << ans << endl;
    }
    return 0;
}