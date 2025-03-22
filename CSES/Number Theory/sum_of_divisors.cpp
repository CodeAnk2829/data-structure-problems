// again do this question

#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll mod = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;

    ll i = 1; 
    ll sumOfDivisors = 0LL;

    while(i <= n) {
        ll firstSum = (i & 1) ? ((i % mod) * (((i - 1) / 2) % mod)) % mod : (((i / 2) % mod) * ((i - 1) % mod)) % mod;
        ll q = n / i;
        i = n / q + 1;
        ll secondSum = (i & 1) ? ((i % mod) * (((i - 1) / 2) % mod)) % mod : (((i / 2) % mod) * ((i - 1) % mod)) % mod;
        sumOfDivisors = (sumOfDivisors + ((q % mod) * ((secondSum - firstSum + mod) % mod))) % mod;
    }

    cout << sumOfDivisors << endl;
    return 0;
}