#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll maxNumOfHousesSold(ll n, ll m, ll k, vector<ll>& d, vector<ll>& a) {
    sort(a.begin(), a.end());
    sort(d.begin(), d.end());
    ll count = 0;

    ll i = 0, j = 0;
    while(i < n && j < m) {
        if((d[i] - k) <= a[j] && a[j] <= (d[i] + k)) {
            count++, i++, j++;
        } else if((d[i] - k) > a[j]) {
            j++;
        } else {
            i++;    
        }
    }
    return count;
}

int main() {
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> desiredSizesOfTheHouse(n);
    vector<ll> apartments(m);
    
    for (auto &d : desiredSizesOfTheHouse) cin >> d;
    for (auto &a : apartments) cin >> a;
    
    cout << maxNumOfHousesSold(n, m, k, desiredSizesOfTheHouse, apartments) << endl;

    return 0;
}