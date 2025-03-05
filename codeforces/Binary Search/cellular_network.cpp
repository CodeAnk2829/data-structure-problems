// https://codeforces.com/problemset/problem/702/C
#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool isPossible(vector<ll>& cities, vector<ll>& towers, int n, int m, int r) {
    int cityPos = 0;
    for(auto &tower : towers) {
        pair<ll, ll> towerRange = {tower - r, tower + r};
        while(cityPos < n && towerRange.first <= cities[cityPos] && towerRange.second >= cities[cityPos]) {
            cityPos++;
        }
    }
    return cityPos == n;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<ll> cities(n);
    for(auto &i : cities) cin >> i;
    vector<ll> towers(m);
    for(auto &i : towers) cin >> i;

    sort(cities.begin(), cities.end());
    sort(towers.begin(), towers.end());

    ll low = 0, high = 2e9;
    ll ans = high;

    while(low <= high) {
        ll mid = (low + high) / 2;
        if(isPossible(cities, towers, n, m, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    cout << ans;
    return 0;
}