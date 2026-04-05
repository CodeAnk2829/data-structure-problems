#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> p(n), deg(n);
    for (int i = 1; i < n; i++) {
        cin >> p[i];
        p[i]--;
        deg[p[i]]++;
    }

    vector<int> leafs(n);
    for (int i = 0; i < n; i++) {
        if (deg[i] == 0) {
            leafs[p[i]]++;
        }
    }

    for (int i = 0; i < n; i++) {
        if (deg[i] > 0 && leafs[i] < 3) {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
    return 0;
}