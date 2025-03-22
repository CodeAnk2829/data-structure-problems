#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll> factorization(ll n) {
    vector<ll> factors;
    for(ll d = 1; d * d <= n; ++d) {
        if(n % d == 0) {
            factors.push_back(d);
            if(n / d != d) {
                factors.push_back(n / d);
            }
        }
    }

    return factors;
}

int main() {
    ll n; 
    cin >> n;

    vector<ll> factors = factorization(n);
    for(auto &factor: factors) {
        cout << factor << " ";
    }
    cout << endl;

    return 0;
}