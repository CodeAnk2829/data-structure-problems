#include <bits/stdc++.h>
using namespace std;

int findLargestGCD(vector<int>& arr, int n) {
    int m = 1e6 + 1;
    int maxi = *max_element(arr.begin(), arr.end());
    vector<int> sieve(m);
    
    // count frequency of each element inside arr
    for(auto element : arr) {
        sieve[element]++;
    }

    for(int i = maxi; i >= 1; i--) {
        int count = 0;
        for(int j = i; j < m; j += i) {
            count += sieve[j];
            if(count > 1) return i;
        }
    }

    return 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> arr(n);
    for(auto &i : arr) cin >> i;

    cout << findLargestGCD(arr, n);
    return 0;
}