#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> primeFactorization(ll n) {
    vector<ll> primeFactors;

    for(ll d = 2; d * d <= n; d++) {
        if(n % d == 0) {
            primeFactors.push_back(d);
            while(n % d == 0) n /= d;
        }
    }

    if(n > 1) {
        primeFactors.push_back(n);
    }

    return primeFactors;
}

int main() {
    ll n; 
    cin >> n;

    vector<ll> primeFactors = primeFactorization(n);
    for(auto &pf : primeFactors) {
        cout << pf << " ";
    }
    cout << endl;

    return 0;
}