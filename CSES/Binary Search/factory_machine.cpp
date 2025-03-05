// https://cses.fi/problemset/task/1620
#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll countProducts(vector<ll>& arr, ll& time, ll& t)
{
    ll products = 0;
    for(auto i : arr) {
        products += (ll)(time / i);
        if(products > t) {
            return products;
        }
    }
    return products;
}

int main()
{
    ll n, t;
    cin >> n >> t;
    vector<ll> arr;

    for (ll i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        arr.push_back(x);
    }


    ll low = 1;
    ll high = 1e18;
    ll result = 1;

    while (low <= high)
    {
        ll mid = low + (high - low) / 2;
        ll numOfProducts = countProducts(arr, mid, t);
        if (numOfProducts >= t)
        {
            high = mid - 1;
            result = mid;
        }
        else
        {
            low = mid + 1;
        }
    }

    cout << result;

    return 0;
}