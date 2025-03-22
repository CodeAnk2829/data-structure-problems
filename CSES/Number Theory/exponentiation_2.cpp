#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;

long long expo(long long a, long long b, long long m) {
    a %= m;
    long long result = 1;
    while(b > 0) {
        if(b & 1) {
            result = result * a % m;
        }
        a = a * a % m;
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
        long long a, b, c;
        cin >> a >> b >> c;

        cout << expo(a, expo(b, c, mod - 1), mod) << endl;
    }
    return 0;
}