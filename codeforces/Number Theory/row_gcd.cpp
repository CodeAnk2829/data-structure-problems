#include <bits/stdc++.h>
using namespace std;

#define ll long long

// gcd(a, b) = gcd(a, b - a) = gcd(a, a - b)
// gcd(a, b, c) = gcd(a, b - a, c - a) = gcd(a, b - a, c - b) = ...

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<ll> a(n), b(m);
    for(auto &i : a) cin >> i;
    for(auto &i : b) cin >> i;

    // calculate gcd from 1 to n - 1
    ll intermediateResult = 0;
    for(int i = 1; i < n; ++i) {
        intermediateResult = __gcd(intermediateResult, abs(a[i] - a[0]));
    }

    for(auto &i : b) {
        cout << __gcd(a[0] + i, intermediateResult) << " ";
    }

    return 0;
}