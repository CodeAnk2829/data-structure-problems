#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool isPossible(ll mid, ll n) {
    ll half = n / 2;
    double x = 9 * (mid - 1);
    double a = (n / x) + 1;
    double y = (double)(a / x);
    double temp = (log(y) / log(0.9));
    ll result = temp + 3;
    return result >= ((half) / mid);
}

int main() {
    ll n;
    cin >> n;
    ll low = 2, high = n;
    ll ans = low;
    while(low <= high) {
        ll mid = (high + low) / 2;
        if(isPossible(mid, n)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    cout << ans << endl;
    return 0;
}