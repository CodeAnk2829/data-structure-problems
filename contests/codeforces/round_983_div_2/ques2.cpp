#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

const int mod = 1e9 + 7;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        if(n == 1) {
            cout << 1 << endl;
            cout << 1 << endl;
            continue;
        }

        if(k == n || k == 1) {
            cout << -1 << endl;
            continue;
        }

        if(k & 1) {
            cout << 5 << endl;
            cout << 1 << " " << 2 << " " << k << " " << k + 1 << " " << k + 2 << endl;
        } else {
            cout << 3 << endl;
            cout << 1 << " " << k << " " << k + 1 << endl;
        }
    }
    return 0;
}