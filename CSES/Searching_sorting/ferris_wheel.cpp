#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll minGondolas(ll n, ll w, vector<ll>& c) {
    sort(c.begin(), c.end());
    ll count = 0;
    ll right = c.size() - 1;
    ll left = 0;
    while(left <= right) {
        if((c[left] + c[right]) <= w) {
            left++, right--;
        } else {
            right--;
        }
        count++;
    }
    if(left == right) count++;
    return count;
}

int main() {
    ll n, w;
    cin >> n >> w;
    vector<ll> childrenWeight(n);
    for(auto& cw : childrenWeight) cin >> cw;

    cout << minGondolas(n, w, childrenWeight) << endl;
    return 0;
}