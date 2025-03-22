#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& arr, int n) {
    vector<int> sieve(n + 1);
    for(int i = 0; i < n; ++i) {
        if(arr[i] <= n) {
            sieve[arr[i]]++;
        }
    }

    int maxFrogs = 0;
    for(int i = n; i >= 1; i--) {
        maxFrogs = sieve[i];
        for(int j = 2 * i; j <= n; j += i) {
            sieve[j] += sieve[i];
            maxFrogs = max(maxFrogs, sieve[j]);
        }
    }

    return maxFrogs;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;
    cin >> tc;
    while(tc--) {
        int n; 
        cin >> n;
        vector<int> arr(n);
        for(auto &i : arr) cin >> i;

        cout << solve(arr, n) << endl;
    }
    return 0;
}