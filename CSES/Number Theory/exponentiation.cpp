#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;

long long expo(long long a, long long b) {
    a %= mod;
    long long result = 1;
    while(b > 0) {
        if(b & 1) {
            result = result * a % mod;
        }
        a = a * a % mod;
        b >>= 1;
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;
    cin >> tc;
    while(tc--) {
        long long a, b;
        cin >> a >> b;

        cout << expo(a, b % (mod - 1)) << endl;
    }
    return 0;
}