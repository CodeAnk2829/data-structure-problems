// https://cses.fi/problemset/result/10159979/
#include <bits/stdc++.h>
using namespace std;
#define ll long long 

bool isPossible(ll n, ll mid) {
    ll count = 0;
    for(ll i = 1; i <= n; ++i) {
        count += min(n, (mid / i));
        if(count >= ((n * n) / 2) + 1) return true;
    }
    return false;
}

int main() {
    ll n;
    cin >> n;
    ll low = 1, high = n*n;
    ll ans = high;
    while(low <= high) {
        ll mid = (high + low) / 2;
        if(isPossible(n, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    cout << ans;
    return 0;
}