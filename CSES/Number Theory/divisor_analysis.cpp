#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll mod = 1e9 + 7;

ll expo(ll a, ll b, ll m) {
    a %= m;
    ll result = 1;
    while(b) {
        if(b & 1) result = result * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // NOT SUBMITTED, PLEASE TRY AGAIN
    
    ll n;
    cin >> n;
    vector<pair<ll, ll>> primeFactors(n);
    for(ll i = 0; i < n; ++i) {
        ll base, exponent;
        cin >> base >> exponent;
        primeFactors[i] = {base, exponent};
    }

    ll numOfDivisors = 1;
    ll sumOfDivisors = 1;

    for (auto &pf : primeFactors) {
        numOfDivisors = ((numOfDivisors % mod) * ((pf.second + 1) % mod)) % mod;
        ll geometricSum = (((expo(pf.first, pf.second + 1, mod) - 1 + mod) % mod) * expo((pf.first - 1), mod - 2, mod)) % mod;
        sumOfDivisors = ((sumOfDivisors % mod) * geometricSum) % mod;
    }
    
    
    ll productOfDivisors = 1;
    bool dividedBy2 = false;

    // look for the even exponent either on primes
    for(auto pf : primeFactors) {
        if(pf.second % 2 == 0) {
            pf.second /= 2;
            dividedBy2 = true;
            break;
        }
    }
    
    ll outerExponent = 1;
    for (auto &pf : primeFactors) {
        if(!dividedBy2) {
            outerExponent = (outerExponent * ((pf.second + 1) / 2)) % (mod - 1);
        } else {
            outerExponent = (outerExponent * (pf.second + 1)) % (mod - 1);
        }
    }

    for(auto &pf : primeFactors) {
        productOfDivisors = (productOfDivisors * (expo(pf.first, (pf.second * outerExponent) % (mod - 1), mod))) % mod;
    }
    cout << numOfDivisors << " " << sumOfDivisors << " " << productOfDivisors << endl;

    return 0;
}