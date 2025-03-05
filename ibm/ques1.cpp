#include <bits/stdc++.h>
using namespace std;

long getMaxUnits(long n, vector<long>& boxes, vector<long>& u, long k) {
    map<long, long, greater<long>> m;
    for(int i = 0; i < n; ++i) {
        m[u[i]] += boxes[i];
    }
    
    long result = 0;
    for(auto &i : m) {
        result += (min(k, i.second) * i.first);
        k -= min(k, i.second);
        if(k == 0) break;
    }

    return result;
}

int main() {
    long n, k;
    cin >> n >> k;
    vector<long> a(n), b(n);
    for(auto &i : a) cin >> i;
    for(auto &i : b) cin >> i;

    long result = getMaxUnits(n, a, b, k);
    cout << result << endl;
    return 0;
}