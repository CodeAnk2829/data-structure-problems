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
        int n;
        cin >> n;
        map<int, int> m;
        for(int i = 0; i < 2*n; ++i) {
            int x;
            cin >> x;
            m[x]++;
        }

        int mini = m[0] % 2;
        int maxi = min(m[0], m[1]);
        cout << mini << " " << maxi << endl;
    }
    return 0;
}