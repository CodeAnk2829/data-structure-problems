#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;


ll calculateRemainingEnergy(vector<pll>& a, vector<pll>& b, ll e) {
    int n = a.size();
    int m = b.size();

    int i = 0, j = 0;
    ll energyExhausted = 0;

    while(i < n && j < m) {
        pll trackA = a[i];
        pll trackB = b[j];

        ll left = max(trackA.first, trackB.first);
        ll right = min(trackA.second, trackB.second);
        pll intersection = {left, right};

        if(left < right) {
            energyExhausted += (right - left);
        }

        if(trackA == trackB) {
            i++, j++;
        } else if(trackA.second <= trackB.second) {
            i++;
        } else {
            j++;
        }
    }
    
    ll remainingEnergy = energyExhausted > e ? -1 : (e - energyExhausted);
    return remainingEnergy;
}

int main() {
    ll n, m, e;
    cin >> n >> m >> e;
    vector<pll> a(n), b(m);

    for(int i = 0; i < n; ++i) {
        ll x, y;
        cin >> x >> y;
        a[i] = {x, y};
    }

    for(int i = 0; i < m; ++i) {
        ll x, y;
        cin >> x >> y;
        b[i] = {x, y};
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    ll result = calculateRemainingEnergy(a, b, e);
    cout << result << endl;
    return 0;
}