#include <bits/stdc++.h>
using namespace std;

int minDiff(vector<int>& v) {
    sort(v.begin(), v.end());
    int ans = INT_MAX;
    for(int i = 1; i < v.size(); ++i) {
        int diff = v[i] - v[i - 1];
        ans = min(ans, diff);
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; ++i) cin >> v[i];
    cout << minDiff(v);
    return 0;
}