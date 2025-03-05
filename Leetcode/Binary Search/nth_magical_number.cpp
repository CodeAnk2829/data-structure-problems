// https: // leetcode.com/problems/nth-magical-number/
#include <bits/stdc++.h>
using namespace std;

#define ll long long
class Solution {
private:
    ll mod = 1e9 + 7;
    bool isPossible(int n, int a, int b, ll mid) {
        ll lcm = (ll)((a * b) / __gcd(a, b));
        ll pos = (mid / a) + (mid / b) - (mid / lcm);
        return pos >= n;
    }
public:
    int nthMagicalNumber(int n, int a, int b) {
        ll low = 1, high = 1e14;
        ll ans = high;
        while(low <= high) {
            ll mid = (high + low) / 2;
            if(isPossible(n, a, b, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return (int)(ans % mod);
    }
};